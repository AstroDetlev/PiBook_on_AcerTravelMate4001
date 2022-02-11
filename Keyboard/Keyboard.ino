/*
   2022-02-10

   Target System: Arduino Mega2560

   This sketch is made to interface a keyboard matrix of an Acer TravelMate 4001 WLMI.
   The keyboard matrix offers 24 pins and does not contain additional electronic.

   This keyboard is NOT organised 8 by 11. It is much worse. In fact, All pins have to be observed, if any of them is connected to another.
   There is no set of pins that are "rows" and others that are "columns". They are both.

   How it works:
   1. All 24 pins are connected to the Arduino.
   2. All Pins are input, with Pullup High
   3. One of the Pins is set to OUTPUT Low
   4. Check the Inputs. Is there any LOW?
   5. If yes, decode which key was pressed and send this String over the serial (currently)
   6. The OUTPUT Pin is set to Input Pullup again
   7. The next Pin is set to OUTPUT Low.
   8. Repeat 4 - 7 with all pins
   9. Reapeat 2 - 8

   The key detection raw value are just 2 numbers: The pin that is set to LOW and the pin that is detected as LOW.
   These two number are used as index for the matrix array.

   A valid key press leads to an array cell unequal 0. This number is the index for the two decoder arrays, which contain human- and machine-readable outputs

   There might be smarter ways to deal with 89 keys than to use an array with > 500 cells, but this is how it works for me.
   There is no if-else or select-case nightmare, and the data is structured in a way that is easy to adapt for other keyboards.

   To speed up detection, only one half (triangle) of the matrix is used and filled with data. As a result, only half of the possible connections is checked.
   Example: the connection between 4 and 17 is checked (Leads to 29, "Page Down"), but not between 17 and 4, because [17][4] stays filled with 0 in the matrix.
   The wanted side effect: With increasing pin numbers (counter in the loop), the checks to be done decrease.
   There are two loops running to set the inputs/outputs. The outer loop goes over all pins, while the inner loop starts at the current value +1 of the outer loop.
   Example: If the outer Loop is at index 17, the inner loop goes from 18 to max, not from 1 to max. In fact , it goes to max-1, as this last opton is not used
   for this special keyboard matrix.





  Currently there's a delay in the loop, to reduce the output speed and make things easier to read at the screen.

  For a real keyboard detection, think of interrupts!

  There are 24 Pins in use. To make wiring easy, the 2-row extension on the Mega2560 is used.

  Pin 22 on A.Mega2560 is PA0
  ...
  Pin 29 on A.Mega2560 is PA7

  Pin 30 on A.Mega2560 is PC7 (NOT PC0!!!!)
  ...
  Pin 37 on A.Mega2560 is PC0 (NOT PC7!!!!)

  Pin 38 on A.Mega2560 is PD7

  Pin 39 on A.Mega2560 is PG2
  Pin 40 on A.Mega2560 is PG1
  Pin 41 on A.Mega2560 is PG0

  Pin 42 on A.Mega2560 is PL7
  ...
  Pin 49 on A.Mega2560 is PL0

  Pin 50 on A.Mega2560 is PB3(MISO)
  Pin 51 on A.Mega2560 is PB2(MOSI)
  Pin 52 on A.Mega2560 is PB1(SCK)
  Pin 53 on A.Mega2560 is PB0(SS)

  Pin1 of the Matrix is connected with Pin 22 of the Arduino
  Pin2 of the Matrix is connected with Pin 23 of the Arduino
  ...
  Pin24 of the Matrix is connected with Pin 45 of the Arduino


  Usefull details for PS/2
  https://www.marjorie.de/ps2/ps2_protocol.htm

*/


#include "ACER_TRAVELMATE4001WLMI_KEYBOARD_MATRIX.h"

const unsigned char LOWEST_MATRIX_PIN   = 22;
const unsigned char HIGHEST_MATRIX_PIN  = LOWEST_MATRIX_PIN + MATRIX_PINS_COUNT - 1;/* LOWEST_PIN itself is 1 pin, so there are 23 in addition*/

const unsigned char CAPS_LOCK_LED_PIN    = HIGHEST_MATRIX_PIN + 1;
const unsigned char NUM_LOCK_LED_PIN     = HIGHEST_MATRIX_PIN + 2;
const unsigned char SCROLL_LOCK_LED_PIN  = HIGHEST_MATRIX_PIN + 3;

const unsigned char DISP_KEY1_PIN        = HIGHEST_MATRIX_PIN + 4; //Give better names later
const unsigned char DISP_KEY2_PIN        = HIGHEST_MATRIX_PIN + 5;
const unsigned char DISP_KEY3_PIN        = HIGHEST_MATRIX_PIN + 6;
const unsigned char DISP_KEY4_PIN        = HIGHEST_MATRIX_PIN + 7;
const unsigned char DISP_KEY5_PIN        = HIGHEST_MATRIX_PIN + 8;

#define DELAY_MS 0

const unsigned char CAPS_LOCK_LED =   0x01;
const unsigned char NUM_LOCK_LED  =   0x02;
const unsigned char SCROLL_LOCK_LED = 0x04;

const unsigned char DISP_KEY1 = 0x01;
const unsigned char DISP_KEY2 = 0x02;
const unsigned char DISP_KEY3 = 0x04;
const unsigned char DISP_KEY4 = 0x08;
const unsigned char DISP_KEY5 = 0x10;




//This is used by DetectPressedKeys
bool CurrentlyPressedKeys[MATRIX_KEY_COUNT + 1];
//This is for comparing
bool PreviouslyPressedKeys[MATRIX_KEY_COUNT + 1];

//This is used by DetectPressedKeys
bool CurrentlyPressedKeysWithFn[MATRIX_KEY_COUNT + 1];
//This is for comparing
bool PreviouslyPressedKeysWithFn[MATRIX_KEY_COUNT + 1];

bool FnIsActive, FnWasActive;
char buf1[6], buf2[6];
char buffer[10];
unsigned long TimeBefore, TimeAfter;

// the setup routine runs once when you press reset
void setup() {
  TestAllKbdLedsAndDspKeys();
  //Let all leds flash up. Nice during development.
  ActivatePullUpsForTheMatrix();

  // initialize serial communication at 9600 bits per second:
  //This is the debug output.
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop()
{
  int i = MATRIX_KEY_COUNT ;

  //backup the old detected data
  while ( i-- ) *( PreviouslyPressedKeys + i ) = *( CurrentlyPressedKeys + i );
  i = MATRIX_KEY_COUNT ;
  while ( i-- ) *( PreviouslyPressedKeysWithFn + i ) = *( CurrentlyPressedKeysWithFn + i );
  //get new data

  TimeBefore = micros();
  DetectPressedKeys();
  TimeAfter = micros();


  for (i = 0; i < MATRIX_KEY_COUNT; i++)
  {

    if (PreviouslyPressedKeys[i] != CurrentlyPressedKeys[i])
    {
      //change detected
      if (CurrentlyPressedKeys[i])
      {
        Serial.print(F("pressed: "));
      }
      else
      {
        Serial.print(F("released: "));
      }

      Serial.print(F("Key#"));
      Serial.print(itoa(i, buf1, 10));
      Serial.print(F(",PinA="));
      Serial.print(itoa(MatrixPins[i].PinA, buf1, 10));
      Serial.print(F(",PinB="));
      Serial.print(itoa(MatrixPins[i].PinB, buf2, 10));

      strcpy_P(buffer, (char*)pgm_read_word(&(HumanReadableDecoder[i])));
      Serial.print(F(",HRLabel='"));
      Serial.print(buffer);

      Serial.print(F("' ScanDuration(µs)"));
      Serial.print(itoa(TimeAfter - TimeBefore, buf1, 10));
      Serial.println(F("'"));
    }

    if (PreviouslyPressedKeysWithFn[i] != CurrentlyPressedKeysWithFn[i])
    {
      //change detected
      if (CurrentlyPressedKeysWithFn[i])
      {
        Serial.print(F("(Fn)pressed: "));
      }
      else
      {
        Serial.print(F("(Fn)released: "));
      }

      Serial.print(F("Key#"));
      Serial.print(itoa(i, buf1, 10));
      Serial.print(F(",PinA="));
      Serial.print(itoa(MatrixPins[i].PinA, buf1, 10));
      Serial.print(F(",PinB="));
      Serial.print(itoa(MatrixPins[i].PinB, buf2, 10));

      strcpy_P(buffer, (char*)pgm_read_word(&(HumanReadableDecoderWithFn[i])));
      Serial.print(F(",(Fn)Label='"));
      Serial.print(buffer);

      Serial.print(F("' ScanDuration(µs)"));
      Serial.print(itoa(TimeAfter - TimeBefore, buf1, 10));
      Serial.println(F("'"));
    }
  }
}

/*
  Determines the currently pressed keys. The result is the array of bool CurrentlyPressedKeys and CurrentlyPressedKeysWithFn
*/
void DetectPressedKeys()
{
  int i, n,  OutPin, InPin;
  bool readout;
  //Read the Fn Key. The result is stored in CurrentlyPressedKeys[ID_KEY_FN]
  ReadFnKey();
  FnIsActive = CurrentlyPressedKeys[ID_KEY_FN];
  FnWasActive = PreviouslyPressedKeys[ID_KEY_FN];
  //over all keys
  for (i = 0; i < MATRIX_KEY_COUNT; i++)
  {
    //set the offset to get the Ardino pin counting based on the matrix pin counting
    //Pin 1 of the matrix is wired to LOWEST_MATRIX_PIN
    OutPin = MatrixPins[i].PinA + LOWEST_MATRIX_PIN - 1;
    InPin = MatrixPins[i].PinB + LOWEST_MATRIX_PIN - 1;

    //set output pin LOW.
    //digitalWrite(OutPin, LOW);
    SetOutPin(OutPin, LOW);

    //Set the input pullup before reading
    pinMode(InPin, INPUT_PULLUP);

    //Without a small delay, keys may be accidently reported as pressed, even without any user action.
    //delayMicroseconds(5);

    //get the result (a bool) at the right place in the summary.
    //But invert it as a pressed key gives the LOW from the OutPin.
    readout = !digitalRead(InPin);
    //CurrentlyPressedKeys[i] = !digitalRead(InPin);

    //get and store the result (a bool) at the right place in the summary.
    //But invert it as a pressed key gives the LOW from the OutPin.
    //CurrentlyPressedKeys[i] = !digitalRead(InPin);

    if (FnIsActive)
    {
      //Serial.println(F("Fn detected!"));

      //Fn-key was detected, so we are possibly dealing with a virtual key composed with Fn
      if (FnAffectedKeys[i]) //check if the detected key has a second meaning if Fn is active
      {
        //yes, there is a second meaning.
        //put the result at that special pile
        CurrentlyPressedKeysWithFn[i] = readout;
      }

    }
    else
    {
      //not influenced by Fn. Put it on the normal pile, if it not an unfinished Fn-action.
      if (!CurrentlyPressedKeysWithFn[i])
      {
        CurrentlyPressedKeys[i] = readout;
      }
    }

    //remove the output voltage
    pinMode(OutPin, INPUT);
    pinMode(OutPin, INPUT_PULLUP);

  }
  /*Detection is done now. Now some additional logic.
    If there is no Fn key anymore, all Fn-related virtual keys have to disappear, too.
    Without this purge, we may miss some of their break codes
  */

  if (FnIsActive)
  {
    for (n = 0; n <= MATRIX_KEY_COUNT; n++)
    {

      CurrentlyPressedKeysWithFn[i] = LOW;

    }
  }
}


/*
   have a look at the Fn key
*/


void ReadFnKey()
{
  uint8_t OutPin, InPin;
  bool readout;
  OutPin = MatrixPins[ID_KEY_FN].PinA + LOWEST_MATRIX_PIN - 1;  //21 + 22 - 1 = 42
  InPin = MatrixPins[ID_KEY_FN].PinB + LOWEST_MATRIX_PIN - 1;  //24 + 22 - 1 = 45
  //set output pin LOW.
  SetOutPin(OutPin, LOW);

  //Set the input pullup before reading
  pinMode(InPin, INPUT_PULLUP);
  //delayMicroseconds(10);

  //invert the reading as we pull down to activate
  CurrentlyPressedKeys[ID_KEY_FN] = !digitalRead(InPin);

  //remove the output voltage
  pinMode(OutPin, INPUT);
  pinMode(OutPin, INPUT_PULLUP);
}

/*
  Activate the internal Pullup Resistors for all Pins wired to the Keyboard Matrix
*/
void ActivatePullUpsForTheMatrix()
{
  int i;
  for (i = LOWEST_MATRIX_PIN; i <= (HIGHEST_MATRIX_PIN); i++)
  {
    pinMode(i, INPUT);
    pinMode(i, INPUT_PULLUP);
  }
}
/*
   Set the 3 Keyboard LEDs (Caps Lock, Num Lock, Scroll Lock)
   Paranmeter: char
   Allows to set/unset all 3 LEDS.
   Use the PS2 constants PS2_H2K_LED_NUM_LOCK, PS2_H2K_LED_CAPS_LOCK, PS2_H2K_LED_SCROLL_LOCK to combine the input.
   An active bit means: Set the LED. The other 5 bits will be ignored.
   Call again with blanked bit to clear the LED
*/
void SetKeyboardLEDs (char LedValues)
{

  /*
     The lower 3 bits of the input will trigger the LEDs
  */
  const unsigned char count = 3;
  unsigned char led[count], i;
  unsigned char outpin[count], pattern[count];
  bool outval[count];

  //Serial.print("LedValues: ");
  //Serial.print(itoa(LedValues, buf1, 10));

  //prepare an array of the output pins. They are not guaranteed to be in a seamless row.
  outpin[0] = CAPS_LOCK_LED_PIN;
  outpin[1] = NUM_LOCK_LED_PIN;
  outpin[2] = SCROLL_LOCK_LED_PIN;

  //prepare an array of the expected bit patterns. They are connected to the pins via the array index
  pattern[0] = CAPS_LOCK_LED;
  pattern[1] = NUM_LOCK_LED;
  pattern[2] = SCROLL_LOCK_LED;

  //over all LEDs
  for (i = 0; i < count; i++)
  {
    //shift the filter bit each time
    led[i] =  LedValues & (0x01 << i);
    //Serial.print(" led[i]: ");
    //Serial.print(itoa(led[i], buf1, 10));
    //preset
    outval[i] = LOW;
    if (led[i]  )
    {
      outval[i] = HIGH;
    }
    //set if req'd
    SetOutPin(outpin[i], outval[i]);

    //Serial.print(" outval[i]: ");
    //Serial.println(itoa(outval[i], buf1, 10));
  }
}

/*
  Set the 5 Keys for the Display controller board.
  Paranmeter: char
  Allows to set/unset all 5 Keys.
  Use the constants DISPLAY_KEY_1...DISPLAY_KEY_5 to combine the input.
  An active bit means: Set the Key. The other 3 bits will be ignored.
*/
void SetDisplayControlKeys (char KeyValues)
{
  unsigned char key[5], i;
  unsigned char outpin[5];
  bool outval[5];

  //Serial.print("KeyValues: ");
  //Serial.print(itoa(KeyValues, buf1, 10));

  //prepare an array of the output pins. They are not guaranteed to be in a seamless row.
  outpin[0] = DISP_KEY1_PIN;
  outpin[1] = DISP_KEY2_PIN;
  outpin[2] = DISP_KEY3_PIN;
  outpin[3] = DISP_KEY4_PIN;
  outpin[4] = DISP_KEY5_PIN;

  //over all control keys
  for (i = 0; i < 5; i++)
  {
    //shift the filter bit each time
    key[i] =  KeyValues & (0x01 << i);
    //Serial.print(" key[i]: ");
    //Serial.print(itoa(key[i], buf1, 10));
    //preset
    outval[i] = LOW;
    if (key[i])
    {
      outval[i] = HIGH;
    }
    //set if req'd
    SetOutPin(outpin[i], outval[i]);

    //Serial.print(" outval[i]: ");
    //Serial.println(itoa(outval[i], buf1, 10));
  }
}

/*
  Set a single pin as output and give it the defined value
  To simplify bug hinting, this shall be the only way to set any output value.
*/
void SetOutPin (char PinNumber, bool OutVal)
{
  pinMode(PinNumber, OUTPUT);
  digitalWrite(PinNumber, OutVal);
}

/*
  Iterate over the keyboard LEDs and the keys to adjust the display adapter board.
  Set each pin to High, wait some time, then set back to low
  Usefull for hardware debugging. The LEDs and Keys are known via their defines.
*/
void TestAllKbdLedsAndDspKeys()
{
  unsigned char i;
  const unsigned long myDelay = 50; //milliseconds
  const unsigned char pinCount = 8, ledCount = 3, keyCount = 5;
  const unsigned char outpin[pinCount] =
  {
    //The LEDs
    CAPS_LOCK_LED_PIN,    NUM_LOCK_LED_PIN,    SCROLL_LOCK_LED_PIN,
    //The Control Keys
    DISP_KEY1_PIN, DISP_KEY2_PIN, DISP_KEY3_PIN, DISP_KEY4_PIN, DISP_KEY5_PIN
  };

  const unsigned char pattern[pinCount] =
  {
    //The LEDs
    CAPS_LOCK_LED,    NUM_LOCK_LED,    SCROLL_LOCK_LED,
    //The Control Keys
    DISP_KEY1, DISP_KEY2, DISP_KEY3, DISP_KEY4, DISP_KEY5
  };
  /*
    //First Test: Set the outputs directly.
    for (i = 0; i < pinCount; i++)
    {
      SetOutPin(outpin[i], HIGH);
      delay(myDelay);
      SetOutPin(outpin[i], LOW);
    }
    //Second Test: Set them by using their functions, involving much more code.
  */
  delay(myDelay);
  SetKeyboardLEDs(0x0F);  //all active
  SetDisplayControlKeys(0x00);
  delay(myDelay);
  SetKeyboardLEDs(0x00); //all off
  SetDisplayControlKeys(0x00); //all off
  /*
    delay(myDelay);
    for (i = 0; i < ledCount; i++)
    {
      SetKeyboardLEDs(pattern[i]);
      delay(myDelay);
      SetKeyboardLEDs(0x00);
    }

    delay(myDelay);
    for (i = 0; i < keyCount; i++)
    {

      SetDisplayControlKeys(pattern[i + ledCount] );
      delay(myDelay);
      SetDisplayControlKeys(0x00);
    }
  */
}
