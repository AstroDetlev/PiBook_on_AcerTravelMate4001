/*
   2021-12-01

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

#define LOWEST_MATRIX_PIN 22
#define HIGHEST_MATRIX_PIN LOWEST_MATRIX_PIN + MATRIX_PINS_COUNT - 1/* LOWEST_PIN itself is 1 pin, so there are 23 in addition*/
#define CAPS_LOCK_LED HIGHEST_MATRIX_PIN + 1
#define NUM_LOCK_LED HIGHEST_MATRIX_PIN + 2
#define SCROLL_LOCK_LED HIGHEST_MATRIX_PIN + 3
#define DISP_KEY1 HIGHEST_MATRIX_PIN + 4
#define DISP_KEY2 HIGHEST_MATRIX_PIN + 5
#define DISP_KEY3 HIGHEST_MATRIX_PIN + 6
#define DISP_KEY4 HIGHEST_MATRIX_PIN + 7
#define DISP_KEY5 HIGHEST_MATRIX_PIN + 8


#define DELAY_MS 0

const unsigned char DISPLAY_KEY_1 = 0x01;  
const unsigned char DISPLAY_KEY_2 = 0x02;  
const unsigned char DISPLAY_KEY_3 = 0x04;  
const unsigned char DISPLAY_KEY_4 = 0x08;  
const unsigned char DISPLAY_KEY_5 = 0x10;  

//This is used by DetectPressedKeys
bool CurrentlyPressedKeys[MATRIX_KEY_COUNT];
//This is for comparing
bool PreviouslyPressedKeys[MATRIX_KEY_COUNT];
char buf1[4], buf2[4];
char buffer[10];
unsigned long TimeBefore, TimeAfter;

// the setup routine runs once when you press reset
void setup() {

  // initialize serial communication at 9600 bits per second:
  //This is the debug output.
  Serial.begin(9600);
  //Let all leds flash up. Nice during development.
  ToggleAllKbdLedsAndDspKeys();
  ActivatePullUpsForTheMatrix();
}

// the loop routine runs over and over again forever:
void loop()
{
  int i = MATRIX_KEY_COUNT ;
    
  //backup the old detected data
  while ( i-- ) *( PreviouslyPressedKeys + i ) = *( CurrentlyPressedKeys + i );
  //get new data

  TimeBefore = micros();
  DetectPressedKeys();
  TimeAfter = micros();
  
  //delay(50);
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
      strcpy_P(buffer, (char*)pgm_read_word(&(HumanReadableDecoder[i])));
            
      Serial.print(F("Key#"));
      Serial.print(itoa(i, buf1, 10));
      Serial.print(F(",PinA="));
      Serial.print(itoa(MatrixPins[i].PinA, buf1, 10));
      Serial.print(F(",PinB="));
      Serial.print(itoa(MatrixPins[i].PinB, buf2, 10));
      Serial.print(F(",HRLabel='"));
      Serial.print(buffer);
      Serial.print(F("' ScanDuration(µs)"));
      Serial.print(itoa(TimeAfter-TimeBefore, buf1, 10));
      Serial.println(F("'"));
    }
  }
}

/*
  Determines the currently pressed keys. The result is the array of bool CurrentlyPressedKeys
*/
void DetectPressedKeys()
{
  int i, OutPin, InPin;
  //over all keys
  for (i = 0; i < MATRIX_KEY_COUNT; i++)
  {
    //set the offset to get the Ardino pin counting based on the matrix pin counting
    //Pin 1 of the matrix is wired to LOWEST_MATRIX_PIN
    OutPin = MatrixPins[i].PinA + LOWEST_MATRIX_PIN -1;
    InPin = MatrixPins[i].PinB + LOWEST_MATRIX_PIN -1;

    //set the output pin as OUTPUT
    //pinMode(OutPin, OUTPUT);
    
    //set output pin LOW.
    //digitalWrite(OutPin, LOW);
    SetOutPin(OutPin, LOW);
  
    //Set the input pullup before reading
    pinMode(InPin, INPUT_PULLUP);

    //Without a small delay, keys may be accidently reported as pressed, even without any user action.
    //delayMicroseconds(5);
    
    //get and store the result (a bool) at the right place in the summary.
    //But invert it as a pressed key gives the LOW from the OutPin.
    CurrentlyPressedKeys[i] = !digitalRead(InPin);

    //remove the output voltage 
    pinMode(OutPin, INPUT);
    pinMode(OutPin, INPUT_PULLUP);
  }
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
*/
void SetKeyboardLEDs (char LEDs)
{

    char numlock, capslock, scrolllock;

Serial.println(itoa(LEDs, buf1, 16));

    numlock =     LEDs & PS2_H2K_LED_NUM_LOCK;
    capslock =    LEDs & PS2_H2K_LED_CAPS_LOCK;
    scrolllock =  LEDs & PS2_H2K_LED_SCROLL_LOCK;

Serial.print(itoa(numlock, buf1, 16));
Serial.print(itoa(capslock, buf1, 16));
Serial.print(itoa(scrolllock, buf1, 16));
    
    pinMode(CAPS_LOCK_LED, OUTPUT);
    pinMode(NUM_LOCK_LED, OUTPUT);
    pinMode(SCROLL_LOCK_LED, OUTPUT);
    
    //set the output pin.

    if (numlock)
    { digitalWrite(NUM_LOCK_LED, HIGH);} else { digitalWrite(NUM_LOCK_LED, LOW);}  //middle on pcb
    if (capslock)
    { digitalWrite(PS2_H2K_LED_CAPS_LOCK, HIGH);} else { digitalWrite(PS2_H2K_LED_CAPS_LOCK, LOW);}  //left on pcb
    if (scrolllock)
    { digitalWrite(SCROLL_LOCK_LED, HIGH);} else { digitalWrite(SCROLL_LOCK_LED, LOW);}  //right on pcb

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

    //prepare an array of the output pins. They are not guaranteed to be in a seamless row.
    outpin[0] = DISP_KEY1;
    outpin[1] = DISP_KEY2;
    outpin[2] = DISP_KEY3;
    outpin[3] = DISP_KEY4;
    outpin[4] = DISP_KEY5;
  
    //over all possible keys
    for (i = 0; i < 5; i++)
    {
      //shift the filter bit each time
      key[i] =  KeyValues & (0x01 << i);
      //preset
      outval[i] = LOW;
      if (key[i]) {outval[i] = HIGH;}         
      //set if req'd
      SetOutPin(outpin[i], outval[i]);

      Serial.println(itoa(KeyValues, buf1, 16));
      Serial.print(itoa(key[i], buf1, 16));
      Serial.print(itoa(outval[i], buf1, 16));
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
void ToggleAllKbdLedsAndDspKeys()
{
    const unsigned long myDelay = 500; //milliseconds
    const unsigned char pinCount = 8;
    unsigned char outpin[pinCount], i;

    //The LEDs
    outpin[0] = CAPS_LOCK_LED;
    outpin[1] = NUM_LOCK_LED;
    outpin[2] = SCROLL_LOCK_LED;

    //The Keys
    outpin[3] = DISP_KEY1;
    outpin[4] = DISP_KEY2;
    outpin[5] = DISP_KEY3;
    outpin[6] = DISP_KEY4;
    outpin[7] = DISP_KEY5;
    
    for (i = 0; i < pinCount; i++)
    {
      SetOutPin(outpin[i], HIGH);
      delay(myDelay);
      SetOutPin(outpin[i], LOW);
      
    }
}
