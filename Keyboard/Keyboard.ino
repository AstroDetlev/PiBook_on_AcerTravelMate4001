
/*
  PiBook_on_AcerTravelMate4001 
  
  AstroDetlev 2020

  This is the Main file for a Laptop Keyboard Matrix used as PS/2 Keyboard for a homemade Pibook
  It deals with the pressed buttons, interacts with the PS/2 Interface and also emulates some buttons
  that are required to adjust the display settings on a video board that feeds the Laptop display.
  The video board development is not part of this project. I buyed one that matches to the 1280x800 display.
  It has 5 buttons that will be replaced by some special keyboard shortcuts.

  This code does NOT deal with USB and also not with any video signal. 
  This is a keyboard controller with some extra wires that can be set to high or low.  

  Currently there a 2 boards used as targets:
  - Arduino Mega 2560
  - Teensy ++2.0

  Set matching macro in  "PIN_ASSIGNMENT.h" to switch between them.
  Info: Arduino UNO or Nano do not provide enough I/O-Pins, at least not for the hardware I am dealing with.
  Using two Nanos might work, but I gave up this idea.

  I started with Mega2560 and later decided to shrink the footprint. As I am a fan of "use what you already have" and 
  that "Teensy ++2.0" came into my hands, I decided to use it.
  
  NOTE: This code uses the Ps2Dev Library, which is made for AVR chips.
  Not sure if it will work for other plattforms, like STM32 ("blue pill"). 
*/

/*
KBD_DEBUG will activate the serial debug output, and as a result, mess up the timing
*/
#define KBD_DEBUG 

#define SCANCODE_1BYTE   0x01
#define SCANCODE_2BYTE   0x02

#define SCANID_MK_STD   0x01
#define SCANID_MK_SPCL  0x02
#define SCANID_MK_PRINT 0x04
#define SCANID_MK_BREAK 0x08

#define SCANID_BK_STD   0x81
#define SCANID_BK_SPCL  0x82
#define SCANID_BK_PRINT 0x84
#define SCANID_DUMMY 0x00

//The MAKE- and BREAKCODES as macros (arrays)
#include "PS2_DETAILS.h"

//This file contains details for the specific keyboard matrix. It uses the macros from PS2_DETAILS.h
#include "ACER_TRAVELMATE4001WLMI_KEYBOARD_MATRIX.h"

//This is the file to describe which pins of the development board are used.
#include "PIN_ASSIGNMENTS.h"

//Library to emulate a PS/2 device. Written for keyboards with US layout. 
//Provided enums ScanCodes/SpecialScanCodes do not match outside US. Doesn't matter, we have these numbers
#include <ps2dev.h>
PS2dev keyboard(PS2_CLOCK, PS2_DATA);  //clock + data pins


#define TestDelayMs 50

#ifdef KBD_DEBUG
  unsigned long DbgTimeCount = 0;
  unsigned long DbgTimeStart, DbgTimeEnd;
  char DbgBuf1[30];
#endif

#define STD_KEY 0
#define FN_COMPOSED_KEY 1

//A list of the keyboard pins. They might not be in an unbroken row of pin numbers. Instead of an iteration over the pins, iterate over this array
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

//This is used by ProcessPressedKeys
bool CurrentlyPressedKeys[KBD_REAL_KEY_COUNT];
//This is for comparing to see what has changed
bool PreviouslyPressedKeys[KBD_REAL_KEY_COUNT];


// the setup routine runs once when you press reset
void setup() {
  ActivateKeyboardPullUps();

  //Prepare the output pins for LED and Display buttons.
  PrepareKbdLeds();
  PrepareDspKeys();



#ifdef KBD_DEBUG

  //Let all leds flash up. Nice during development.
  TestAllKbdLeds();
  //TestAllDspKeys();

  //initialize serial communication at 9600 bits per second:
  //This is the debug output.
  Serial.begin(9600);
#endif  

  keyboard.keyboard_init();  //ps2dev

#ifdef KBD_DEBUG
  Serial.println("setup done");
#endif  

}

void loop()
{
    unsigned char leds; //ps2dev

    uint8_t index;

#ifdef KBD_DEBUG    
  //Start of measurement    
  DbgTimeStart = micros();
#endif

    //backup the old detected data
    for (index = 0; index < KBD_REAL_KEY_COUNT; index++)
    {
      PreviouslyPressedKeys[index] = CurrentlyPressedKeys[index];
    }
    //get new data
    ProcessPressedKeys();

#ifdef KBD_DEBUG
  //End of measurement    
  DbgTimeEnd = micros();

 // Serial.print(F("' ScanDuration(µs)"));
 // Serial.println(itoa(DbgTimeEnd - DbgTimeStart, DbgBuf1, 10)); 
#endif

  
//ps2dev
  if(keyboard.keyboard_handle(&leds)) 
  { 
#ifdef KBD_DEBUG
    Serial.print('LEDS');
    Serial.print(leds, HEX);
#endif    
   // digitalWrite(LED_BUILTIN, leds);
  }
}

void SendScanCodeOverPs2(uint8_t ScanCodeFragment, uint8_t ScanCodeId, uint8_t VirtKey )
{
  #ifdef KBD_DEBUG
      Serial.print("PS2: code 0x");
     // Serial.print(itoa(ScanCodeFragment, DbgBuf1, 16));
      Serial.print(ScanCodeFragment,HEX);
      Serial.print(", Detail 0x");
      Serial.print(ScanCodeId, HEX);
      Serial.print(", Key(dez) ");

      Serial.println(VirtKey);

  #endif
  switch(ScanCodeId)
  {
    case SCANID_MK_STD:
      keyboard.keyboard_press(ScanCodeFragment);
    break;
    case SCANID_MK_SPCL:
      keyboard.keyboard_press_special(ScanCodeFragment);
    break;
    case SCANID_BK_STD:
      keyboard.keyboard_release(ScanCodeFragment);
    break;
    case SCANID_BK_SPCL:
      keyboard.keyboard_release_special(ScanCodeFragment);
    break;

    case SCANID_MK_PRINT:
      keyboard.keyboard_press_printscreen();
    break;
    case SCANID_BK_PRINT:
      keyboard.keyboard_release_printscreen();
    break;
    case SCANID_MK_BREAK:
      keyboard.keyboard_pausebreak();
    break;
    case SCANID_DUMMY:
      //do nothing
    break;
  }
}

/*
  ProcessPressedKeys

  - Determines the currently pressed keys 
  - Triggers SendScanCodeOverPs2 . 
  
  - Uses MatrixPins to select the right pins to deal with for each button.
  - Uses SetKbdPin and 
  A sideeffect is a change in array of bool CurrentlyPressedKeys
*/
void ProcessPressedKeys()
{
  uint8_t ScanIndex, ScanByteCount, VirtKeyIndex, OutPin, InPin, Ps2CodeFragment, Ps2CodeDetail;
  bool Result, FnDependend, NumLockDependend, SendMakeCode, SendBreakCode;



  //A loop over all keys. Note that the loop will start at 0 and not reach KBD_REAL_KEY_COUNT
  for (ScanIndex = 0; ScanIndex < KBD_REAL_KEY_COUNT; ScanIndex++)
  {
    //init
    FnDependend = 0;
    NumLockDependend =0;
    VirtKeyIndex = 0;
    SendMakeCode = 0;
    SendBreakCode = 0;
    Ps2CodeDetail = SCANID_DUMMY;

    //The two pins with the specific button in between.
    OutPin = MatrixPins[ScanIndex].Pin1; 
    InPin = MatrixPins[ScanIndex].Pin2; 

    //set output pin LOW.
    SetKbdPin(OutPin, LOW);
    //Set the input pullup before reading
    //SetKbdPinMode(InPin, INPUT_PULLUP);

    //Without a small delay, keys may be accidently reported as pressed, even without any user action.
    delayMicroseconds(10);

    //get the result (a bool), but invert it as a pressed key reads as a LOW from the OutPin.
    Result = !GetKbdPin(InPin);
    //CurrentlyPressedKeys[ScanIndex] = Result;


    if (PreviouslyPressedKeys[ScanIndex] != Result)
    {
        //There is a change in the status of this button!
        if (Result)
        {
          //Key is pressed, send MakeCode
          SendMakeCode = 1;
         
        }
        else
        {
          //key is release, send BreakCode
          SendBreakCode = 1;
          
        }

        //preset, might be overwritten if there are special keys to deal with
        VirtKeyIndex = ScanIndex; 

        //deal with current Fn button status. Fn itself does not trigger any PS/2 scan code
        if (CurrentlyPressedKeys[KBD_KEY_FN])
        {
          
          if ((ScanIndex >= KBD_FN_DEPENDENT_START_INDEX) && (ScanIndex <= KBD_FN_DEPENDENT_END_INDEX))
          {
            FnDependend = 1;
            VirtKeyIndex = ScanIndex + KBD_FN_ACTIVATED_OFFSET;
          }
        }

        //deal with Num Lock status
        if (KeyboardLEDPin[KBD_CAPS_LOCK])
        {
          if ((ScanIndex >= KBD_KBD_NUMLOCK_DEPENDENT_END_INDEX) && (ScanIndex <= NUMLOCK_DEPENDENT_END_INDEX))
          {
              NumLockDependend = 1;
              VirtKeyIndex = ScanIndex + KBD_NUMLOCK_ACTIVATED_OFFSET; 
          }
        }

      if (VirtKeyIndex != KBD_KEY_FN) //keep calm if it is the Fn key
      {


        //Scan is done. Now put the pieces together to get the correct scancode
        if (SendMakeCode == 1)
        {
            //We need the MakeCode         

              switch (Ps2CodeCombo[VirtKeyIndex].ByteCountMakeCode)
              {
                case SCANCODE_1BYTE:
                  Ps2CodeDetail =  SCANID_MK_STD;
                break;
                case SCANCODE_2BYTE:
                  Ps2CodeDetail =  SCANID_MK_SPCL;
                break;
                default:
                  if (VirtKeyIndex == KBD_KEY_PRINT)
                  {
                    Ps2CodeDetail = SCANID_MK_PRINT;
                  }
                  else
                  {
                    if (VirtKeyIndex == KBD_KEY_BREAK)
                    {
                        Ps2CodeDetail = SCANID_MK_BREAK;
                    }
                    else
                    {
                      //no known other scan codes
                      Ps2CodeDetail = SCANID_DUMMY;
                    }
                  }                
              }
              Ps2CodeFragment = Ps2CodeCombo[VirtKeyIndex].MakeCode;
              SendScanCodeOverPs2(Ps2CodeFragment, Ps2CodeDetail, VirtKeyIndex);
#ifdef KBD_DEBUG
    Serial.print("ScanIndex: " );
    Serial.print(ScanIndex );
    Serial.print(" OutPin: " );
    Serial.print(OutPin );
   Serial.print(" InPin: " );
    Serial.print(InPin );
   Serial.print(" Result: " );
    Serial.println(Result );   
#endif              
                        
       }
      
        if (SendBreakCode == 1)
        {

            //We need the BreakCode
            switch (Ps2CodeCombo[VirtKeyIndex].ByteCountMakeCode) //yes, makecode
            {
              case SCANCODE_1BYTE:
                Ps2CodeDetail =  SCANID_BK_STD;
              break;
              case SCANCODE_2BYTE:
                Ps2CodeDetail =  SCANID_BK_SPCL;
              break;
              default:
                if (VirtKeyIndex == KBD_KEY_PRINT)
                {
                  Ps2CodeDetail = SCANID_BK_PRINT;
                }
                else
                {
                  Ps2CodeDetail = SCANID_DUMMY;
                  //There is no break for break
                  //and no known other weired scan codes
                }                
            }
            Ps2CodeFragment = Ps2CodeCombo[VirtKeyIndex].MakeCode;

            SendScanCodeOverPs2(Ps2CodeFragment, Ps2CodeDetail, VirtKeyIndex);
            
#ifdef KBD_DEBUG
    Serial.print("ScanIndex: " );
    Serial.print(ScanIndex );
    Serial.print(" OutPin: " );
    Serial.print(OutPin );
    Serial.print(" InPin: " );
    Serial.print(InPin );
     Serial.print(" Result: " );
    Serial.println(Result );  
#endif
        }
      }
      //if neither SendMakeCode nor SendBreakCode are set, there is nothing to do beside from storing the result of the scan.
      CurrentlyPressedKeys[ScanIndex] = Result;
    
        //To discharge any capacitance. Pullup will pull to HIGH, so HIGH is the default value
        //SetKbdPin(OutPin, HIGH);
        //SetKbdPin(InPin, HIGH);
 //delayMicroseconds(10);
        //remove the output voltage for the scanned key
        SetKbdPinMode(OutPin, INPUT);
       // SetKbdPinMode(InPin, INPUT);
  delayMicroseconds(10);       
        //SetKbdPinMode(OutPin, INPUT_PULLUP);

    }//if (PreviouslyPressedKeys[index] != CurrentlyPressedKeys[index])
#ifdef KBD_DEBUG
Serial.print(ScanIndex );
#endif
  }//for

    /*processing is done for all keys. */
}



/*
  Activate the internal Pullup Resistors for all Pins wired to the Keyboard Matrix
*/
void ActivateKeyboardPullUps()
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
void SetKeyboardLEDs (uint8_t LedValues)
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
  Paranmeter: uint8_t
  Allows to set/unset all 5 Keys.
  Use the constants DISPLAY_KEY_1...DISPLAY_KEY_5 to combine the input.
  An active bit means: Set the Key. The other 3 bits will be ignored.
*/
void SetDisplayControlKeys (uint8_t KeyValues)
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
  Set a single Keyboard pin as output and give it the defined value.
  To simplify bug hunting, this shall be the only way to set any Keyboard value.
  PinNumber is 1 ... KBD_PINCOUNT.
*/
void SetKbdPin (uint8_t PinNumber, bool OutVal)
{
  SetKbdPinMode(PinNumber, OUTPUT);
  digitalWrite(KeyboardPin[PinNumber-1], OutVal);
}

/*
  Get a single Keyboard pin value
  To simplify bug hunting, this shall be the only way to get any Keyboard value.
  PinNumber is 1 ... KBD_PINCOUNT.
*/
bool GetKbdPin (uint8_t PinNumber)
{
  return digitalRead(KeyboardPin[PinNumber-1]);
}


/*
  Set the mode of a single Keyboard pin
  To simplify bug hunting, this shall be the only way to set any Keyboard pinmode.
 PinNumber is 1 ... KBD_PINCOUNT.
*/
void SetKbdPinMode (uint8_t PinNumber, uint8_t PinMode)
{
  //change mode
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



