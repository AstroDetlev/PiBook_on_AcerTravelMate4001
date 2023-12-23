
/*
  This is the Main file with the includes

*/
//The MAKE- SCAN- and BREAKCODES as arrays
#include "PS2_DETAILS.h"


//This file contains details for the specific keyboard matrix. It uses the macros from PS2_DETAILS.h
#include "ACER_TRAVELMATE4001WLMI_KEYBOARD_MATRIX.h"


//This is the file to describe which pins of teh development board are used
#include "PIN_ASSIGNMENTS.h"


//Library to emulate a PS/2 device
//#include <_Teensy.h>
#include <ps2dev.h>
PS2dev keyboard(PS2_CLOCK, PS2_DATA);  //clock, data

unsigned long timecount = 0;
#define TestDelayMs 50

#define STD_KEY 0
#define FN_COMPOSED_KEY 1

//A list of the keyboard pins. They might not be in an unbroken row of pin numbers. Instead of iteration over the pins, iterate over this array
const uint8_t KeyboardPin[KBD_PINCOUNT] = 
{
	KBD_MATR_PIN1,
	KBD_MATR_PIN2,
	KBD_MATR_PIN3,
	KBD_MATR_PIN4,
	KBD_MATR_PIN5,
	KBD_MATR_PIN6,
	KBD_MATR_PIN7,
	KBD_MATR_PIN8,
	KBD_MATR_PIN9,
	KBD_MATR_PIN10,
	KBD_MATR_PIN11,
	KBD_MATR_PIN12,
	KBD_MATR_PIN13,
	KBD_MATR_PIN14,
	KBD_MATR_PIN15,
	KBD_MATR_PIN16,
	KBD_MATR_PIN17,
	KBD_MATR_PIN18,
	KBD_MATR_PIN19,
	KBD_MATR_PIN20,
	KBD_MATR_PIN21,
	KBD_MATR_PIN22,
	KBD_MATR_PIN23,
	KBD_MATR_PIN24
};

//A list of the keyboard LED pins. They might not be in an unbroken row of pin numbers.
const uint8_t KeyboardLEDPin[KBD_LED_PINCOUNT] =
{
	KBD_LED_PIN1,
	KBD_LED_PIN2,
	KBD_LED_PIN3
};

//A list of the Display Control button pins. They might not be in an unbroken row of pin numbers.
const uint8_t DisplayButtonPin[DISP_CTRL_PINCOUNT] =
{
	DISP_CTRL_PIN1,
	DISP_CTRL_PIN2,
	DISP_CTRL_PIN3,
	DISP_CTRL_PIN4,
	DISP_CTRL_PIN5
};

//This is used by DetectPressedKeys
bool CurrentlyPressedKeys[MATRIX_KEY_COUNT];
//This is for comparing
bool PreviouslyPressedKeys[MATRIX_KEY_COUNT];
//This is used by DetectPressedKeys
bool CurrentlyPressedKeysWithFn[MATRIX_KEY_COUNT];
//This is for comparing
bool PreviouslyPressedKeysWithFn[MATRIX_KEY_COUNT];
bool FnIsActive, FnWasActive;
//for text output
char buf1[30], buf2[30], debugBuffer[30], Leds = 0;
char buffer[10];
unsigned long TimeBefore, TimeAfter;

#define DebugPrint2(TEXT)

#define DebugPrint(TEXT) \
Serial.print("dbg: ");\
Serial.println(TEXT);
 

// the setup routine runs once when you press reset
void setup() {
  ActivatePullUpsForTheKeyboardMatrix();
 // keyboard.keyboard_init();

  //Prepare the output pins for LED and Display buttons.
  PrepareKbdLeds();
  PrepareDspKeys();
  //Let all leds flash up. Nice during development.
  TestAllKbdLeds();
  TestAllDspKeys();
  //Caps lock is activated
  //SetKbdLedPinMode(KBD_CAPS_LOCK, OUTPUT);

  // initialize serial communication at 9600 bits per second:
  //This is the debug output.
  Serial.begin(9600);
  Serial.println("setup done");
}

void loop()
{
    uint8_t index = MATRIX_KEY_COUNT ;
    uint8_t keytype;

 

    //backup the old detected data
    /*while ( index-- ) *( PreviouslyPressedKeys + index ) = *( CurrentlyPressedKeys + index );
    index = MATRIX_KEY_COUNT ;
    while ( index-- ) *( PreviouslyPressedKeysWithFn + index ) = *( CurrentlyPressedKeysWithFn + index );

    
    */
    for (index = 0; index < MATRIX_KEY_COUNT; index++)
    {
      PreviouslyPressedKeys[index] = CurrentlyPressedKeys[index];
      PreviouslyPressedKeysWithFn[index] = CurrentlyPressedKeysWithFn[index];
    }
    //get new data
    TimeBefore = micros();
    DetectPressedKeys();
    TimeAfter = micros();

  for (index = 0; index < MATRIX_KEY_COUNT; index++)
  {
    if (PreviouslyPressedKeys[index] != CurrentlyPressedKeys[index])
    {
      DebugOutputStandardKey(index);
      DebugPs2OutputStandardKey(index);
      keytype = STD_KEY;
      //Ps2Output(keytype, index); 
    }

    if (PreviouslyPressedKeysWithFn[index] != CurrentlyPressedKeysWithFn[index])
    {
      char tmp;
      DebugOutputWithFnKey(index);
      DebugPs2OutputWithFnKey(index);

      keytype = FN_COMPOSED_KEY;
      //Ps2Output(keytype, index);

      if (index == ID_KEY_CAPS_LOCK) 
      {
        //caps lock is pressed
        if ((PreviouslyPressedKeys[index] == 0) && (CurrentlyPressedKeys[index] == 1))
        {
          DebugPrint("set LED");
          Leds = Leds ||  BITVAL_CAPS_LOCK_LED;
          SetKeyboardLEDs(Leds);
        }
        if ((PreviouslyPressedKeys[index] == 1) && (CurrentlyPressedKeys[index] == 0))
        {

          DebugPrint("unset LED");
       
          Leds &= ~(1 << BITVAL_CAPS_LOCK_LED);
          SetKeyboardLEDs(Leds);
        }


      PreviouslyPressedKeysWithFn[index] = CurrentlyPressedKeysWithFn[index];
         
      }  
            
      if (index == ID_KEY_F12)   //scroll lock
      {

      }   
      if (index == ID_KEY_F11)   //numlock
      {

      }


    }
         
  }

  //DebugOutputDotEverySecond();
}
// the loop routine runs over and over again forever:



void Ps2Output (uint8_t TYPE, uint8_t index)
{

  switch (TYPE)
  {
    case STD_KEY:
      Serial.println("PS2 Std Key");

      //change detected
      if (CurrentlyPressedKeys[index])
      {
        Serial.print(F("pressed: "));
      }
      else
      {
        Serial.print(F("released: "));
      }

      Serial.print(F("Key#"));
      Serial.print(itoa(index, buf1, 10));
      Serial.print(F(",PinA="));
      Serial.print(itoa(MatrixPins[index].Pin1, buf1, 10));
      Serial.print(F(",PinB="));
      Serial.print(itoa(MatrixPins[index].Pin2, buf2, 10));

      strcpy_P(buffer, (char*)pgm_read_word(&(HumanReadableDecoder[index])));
      Serial.print(F(",HRLabel='"));
      Serial.print(buffer);
      Serial.print(F("' ScanDuration(µs)"));
      Serial.println(itoa(TimeAfter - TimeBefore, buf1, 10)); 

    break;
    case FN_COMPOSED_KEY:
      Serial.println("PS2 Fn Key");
    break;

  }
}


void DebugOutputDotEverySecond ()
{
    //Print letter every second
  if ((millis() - timecount) > 2000) {
    Serial.print(".");
    timecount = millis();
  }
}
void DebugOutputWithFnKey (uint8_t index)
{
    //change detected
    if (CurrentlyPressedKeysWithFn[index])
    {
      Serial.print(F("(Fn)pressed: "));
    }
    else
    {
      Serial.print(F("(Fn)released: "));
    }

    Serial.print(F("Key#"));
    Serial.print(itoa(index, buf1, 10));
    Serial.print(F(",PinA="));
    Serial.print(itoa(MatrixPins[index].Pin1, buf1, 10));
    Serial.print(F(",PinB="));
    Serial.print(itoa(MatrixPins[index].Pin2, buf2, 10));

    strcpy_P(buffer, (char*)pgm_read_word(&(HumanReadableDecoderWithFn[index])));
    Serial.print(F(",(Fn)Label='"));
    Serial.print(buffer);
    Serial.print(F("' ScanDuration(µs)"));
    Serial.println(itoa(TimeAfter - TimeBefore, buf1, 10));    
}
void DebugOutputStandardKey (uint8_t index)
{
  //change detected
  if (CurrentlyPressedKeys[index])
  {
    Serial.print(F("pressed: "));
  }
  else
  {
    Serial.print(F("released: "));
  }

  Serial.print(F("Key#"));
  Serial.print(itoa(index, buf1, 10));
  Serial.print(F(",PinA="));
  Serial.print(itoa(MatrixPins[index].Pin1, buf1, 10));
  Serial.print(F(",PinB="));
  Serial.print(itoa(MatrixPins[index].Pin2, buf2, 10));

  strcpy_P(buffer, (char*)pgm_read_word(&(HumanReadableDecoder[index])));
  Serial.print(F(",HRLabel='"));
  Serial.print(buffer);
  Serial.print(F("' ScanDuration(µs)"));
  Serial.println(itoa(TimeAfter - TimeBefore, buf1, 10));    



}


void DebugPs2OutputWithFnKey (uint8_t index)
{
    Serial.print(F("PS2 Details (Fn)"));
    if (CurrentlyPressedKeysWithFn[index])
    {
      Serial.print(F("Makecode byte count:"));
      Serial.print(itoa(Ps2CodeCombo[index].ByteCountMakeFn, buf1, 10));

      Serial.print(F("Makecode:"));
      Serial.println(itoa(Ps2CodeCombo[index].MakecodeFn, buf1, 16));
     
    }
    else
    {
      Serial.print(F("Breakcode byte count:"));
    Serial.print(itoa(Ps2CodeCombo[index].ByteCountBreakFn, buf1, 10));
      
      Serial.print(F("Breakcode:"));
      Serial.println(itoa(Ps2CodeCombo[index].BreakcodeFn, buf1, 16));

    }
    
}
void DebugPs2OutputStandardKey (uint8_t index)
{
  int i;
  //change detected
  if (CurrentlyPressedKeys[index])
  {
    Serial.print(F("pressed: "));
  }
  else
  {
    Serial.print(F("released: "));
  }

  Serial.print(F("PS2 Details"));
    if (CurrentlyPressedKeys[index])
    {
      Serial.print(F("Makecode byte count:"));
      Serial.print(itoa(Ps2CodeCombo[index].ByteCountMake, buf1, 10));

      Serial.print(F("Makecode:"));
      for (i= 0; i<Ps2CodeCombo[index].ByteCountMake;i++)
      {
        Serial.print(" 0x");
        Serial.print(itoa(Ps2CodeCombo[index].Makecode[i], buf1, 10));
      }
      Serial.println("");
    }
    else
    {
      Serial.print(F("Breakcode byte count:"));
    Serial.print(itoa(Ps2CodeCombo[index].ByteCountBreak, buf1, 16));
      
      Serial.print(F("Breakcode:"));
       for (i= 0; i<Ps2CodeCombo[index].ByteCountBreak;i++)
      {
        Serial.print(" 0x");
        Serial.print(itoa(Ps2CodeCombo[index].Breakcode[i], buf1, 16));
      }
      Serial.println("");

    } 



}




/*
  Determines the currently pressed keys. The result is the array of bool CurrentlyPressedKeys and CurrentlyPressedKeysWithFn
*/
void DetectPressedKeys()
{
  uint8_t index, n,  OutPin, InPin;
  bool readout;

  //Read the Fn Key. The result is stored in CurrentlyPressedKeys[ID_KEY_FN]
  ReadFnKey();
  
  FnIsActive = CurrentlyPressedKeys[ID_KEY_FN];
  FnWasActive = PreviouslyPressedKeys[ID_KEY_FN];
     
  //A loop over all keys. Note that the loop will start at 0 and not reach MATRIX_KEY_COUNT
  for (index = 0; index < MATRIX_KEY_COUNT; index++)
  {
    OutPin = MatrixPins[index].Pin1; 
    InPin = MatrixPins[index].Pin2; 

    //set output pin LOW.
    //digitalWrite(OutPin, LOW);
    SetKbdPin(OutPin, LOW);

    //Set the input pullup before reading
    SetKbdPinMode(InPin, INPUT_PULLUP);

    //Without a small delay, keys may be accidently reported as pressed, even without any user action.
    //delayMicroseconds(50);

    //get the result (a bool)
    //But invert it as a pressed key gives a LOW from the OutPin.
    readout = !GetKbdPin(InPin);
   
    if (FnIsActive)
    {

      //Fn-key was detected, so we are possibly dealing with a virtual key composed with Fn
      if (FnAffectedKeys[index]) //check if the detected key has a second meaning if Fn is active
      {
        //yes, there is a second meaning.
        //put the result at that special pile
        CurrentlyPressedKeysWithFn[index] = readout;
      }
      //else: do nothing
    }
    else
    {
      //not influenced by Fn. Put it on the normal pile.
      CurrentlyPressedKeys[index] = readout;
    }
    //remove the output voltage
    SetKbdPinMode(OutPin, INPUT);
    SetKbdPinMode(OutPin, INPUT_PULLUP);
  }
  /*Detection is done now. */
}

/*
   have a look at the Fn key
*/
void ReadFnKey()
{
  
  uint8_t OutPin, InPin, index;
  bool result;
 
  OutPin = MatrixPins[ID_KEY_FN].Pin1;
  InPin = MatrixPins[ID_KEY_FN].Pin2; 
  //set output pin LOW.
  SetKbdPin(OutPin, LOW);

  //Set the input pullup before reading
  SetKbdPinMode(InPin, INPUT_PULLUP);
  //delayMicroseconds(1000);

  //invert the reading as we pull down to activate

  result = !GetKbdPin(InPin);

  if (result != CurrentlyPressedKeys[ID_KEY_FN])
  {
    Serial.println(F("Fn released!"));
    //update the matrix
    CurrentlyPressedKeys[ID_KEY_FN] = result;
   }

  //remove the output voltage
  SetKbdPinMode(OutPin, INPUT);
  SetKbdPinMode(OutPin, INPUT_PULLUP);
}

/*
  Activate the internal Pullup Resistors for all Pins wired to the Keyboard Matrix
*/
void ActivatePullUpsForTheKeyboardMatrix()
{
  uint8_t i;
  for (i = 1; i <= KBD_PINCOUNT; i++)
  {
    SetKbdPinMode(i, INPUT);
    SetKbdPinMode(i, INPUT_PULLUP);
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
  
  uint8_t i;
  /*
     The lower 3 bits of the input will trigger the LEDs
  */
  //over all LEDs
  for (i = 0; i < KBD_LED_PINCOUNT; i++)
  {
    //shift the filter bit each time
    SetKbdLedPin(i, (LedValues & (0x01 << i)));

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
 uint8_t i;

  //over all control keys
  for (i = 0; i < DISP_CTRL_PINCOUNT; i++)
  {
    //shift the filter bit each time

    SetDispCtrlPin(i, KeyValues & (0x01 << i) );
  }
}

/*
  Set a single pin as output and give it the defined value
  To simplify bug hunting, this shall be the only way to set any output value.
*/
void SetKbdPin (uint8_t PinNumber, bool OutVal)
{
  SetKbdPinMode(PinNumber, OUTPUT);
  digitalWrite(KeyboardPin[PinNumber-1], OutVal);
}
bool GetKbdPin (uint8_t PinNumber)
{
  return digitalRead(KeyboardPin[PinNumber-1]);
}

void SetKbdPinMode (uint8_t PinNumber, uint8_t PinMode)
{
  pinMode(KeyboardPin[PinNumber-1], PinMode);
}



void SetKbdLedPin (uint8_t PinNumber, bool OutVal)
{
  SetKbdLedPinMode(PinNumber, OUTPUT);
  digitalWrite(KeyboardLEDPin[PinNumber], OutVal);
}

void SetKbdLedPinMode (uint8_t PinNumber, uint8_t PinMode)
{
  pinMode(KeyboardLEDPin[PinNumber], PinMode);
}

void SetDispCtrlPin (uint8_t PinNumber, bool OutVal)
{
  SetDispCtrlPinMode(PinNumber, OUTPUT);
  digitalWrite(DisplayButtonPin[PinNumber], OutVal);
}

void SetDispCtrlPinMode (uint8_t PinNumber, uint8_t PinMode)
{
  pinMode(DisplayButtonPin[PinNumber], PinMode);
}

void PrepareKbdLeds()
{
  uint8_t i;

  for (i = 0; i < KBD_LED_PINCOUNT; i++)
  {
    SetKbdLedPinMode(i, OUTPUT);
  }
}


void PrepareDspKeys()
{
  uint8_t i;

  for (i = 0; i < DISP_CTRL_PINCOUNT; i++)
  {
    SetDispCtrlPinMode(i, OUTPUT);
  }
}



/*
  Iterate over the keyboard LEDs and the keys to adjust the display adapter board.
  Set each pin to High, wait some time, then set back to low
  Usefull for hardware debugging. The LEDs and Keys are known via their defines.
*/
void TestAllKbdLeds()
{
  uint8_t i;
  const unsigned long myDelay = TestDelayMs; //milliseconds
 

  const unsigned char pattern[KBD_LED_PINCOUNT] =
  {
    //The LEDs
    BITVAL_CAPS_LOCK_LED,    
    BITVAL_NUM_LOCK_LED,    
    BITVAL_SCROLL_LOCK_LED
  };

  delay(myDelay);
  SetKeyboardLEDs(0x07);  //all active

  delay(myDelay);
  SetKeyboardLEDs(0x00); //all off

  delay(myDelay);
  for (i = 0; i < KBD_LED_PINCOUNT; i++)
  {
    SetKeyboardLEDs(pattern[i]);
    delay(myDelay);
    SetKeyboardLEDs(0x00);
    delay(myDelay);
  }
}


void TestAllDspKeys()
{
  uint8_t i;
  const unsigned long myDelay = TestDelayMs; //milliseconds
  const unsigned char pinCount = 5, keyCount = 5;


  const unsigned char pattern[pinCount] =
  {
    //The Control Keys
    BITVAL_DISP_CTRL_PIN1, 
    BITVAL_DISP_CTRL_PIN2, 
    BITVAL_DISP_CTRL_PIN3, 
    BITVAL_DISP_CTRL_PIN4, 
    BITVAL_DISP_CTRL_PIN5
  };

  delay(myDelay);
  SetDisplayControlKeys(0xFF);
  delay(myDelay);
  SetDisplayControlKeys(0x00); //all off

  delay(myDelay);
  for (i = 0; i < keyCount; i++)
  {
    SetDisplayControlKeys(pattern[i ] );
    delay(myDelay);
    SetDisplayControlKeys(0x00);
  }
}



