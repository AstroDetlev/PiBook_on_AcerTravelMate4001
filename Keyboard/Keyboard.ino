
/*
  PiBook_on_AcerTravelMate4001 
  
  AstroDetlev 2023

  This is the Main file for a Laptop Keyboard Matrix used as PS/2 Keyboard for a homemade Pibook
  It deals with the pressed buttons, interacts with the PS/2 Interface and also emulates some buttons
  that are required to adjust the display settings on a video board that feeds the Laptop display.
  The video board development is not part of this project. I buyed one that matches to the 1280x800 display.
  It has 5 buttons that will be replaced by some special keyboard shortcuts.

  This code does NOT deal with USB and also not with any video signal. 
  This is a keyboard controller with some extra pins that can be set to high or low.
  These pins replace buttons on a display controller board.

  Currently there a 2 Atmel uC boards used as targets:
  - Arduino Mega 2560
  - Teensy ++2.0

  Set matching macro in  "PIN_ASSIGNMENT.h" to switch between them.
  Info: Arduino UNO or Nano do not provide enough I/O-Pins, at least not for the hardware I am dealing with.
  Using two Nanos might work, but I gave up this idea.

  I started with Mega2560 and later decided to shrink the footprint. As I am a fan of "use what you already have" and 
  that "Teensy ++2.0" came into my hands, I decided to use it.
  
  NOTE: This code uses the Ps2Dev Library, which is made for AVR chips.
  Not sure if it will work for other plattforms, like STM32 ("blue pill" etc). 
*/

/*
KBD_DEBUG will activate the serial debug output, and as a result, mess up the timing
*/
//#define KBD_DEBUG
//The serial port Baudrate for the debug output
#define KBD_DEBUG_BAUDRATE 230400  //9600





//The MAKE- and BREAKCODES as macros (arrays)
#include "PS2_DETAILS.h"

//This file contains details for the specific keyboard matrix. It uses the macros of PS2_DETAILS.h
#include "ACER_TRAVELMATE4001WLMI_KEYBOARD_MATRIX.h"

//This is the file to describe which pins of the development board are used.
#include "PIN_ASSIGNMENTS.h"

//Settings for the buttons of the Display controller. It uses the macros of PIN_ASSIGNMENTS.h
#include "Display_controller.h"
/*
Library to emulate a PS/2 device. Written for keyboards with US layout.
Provided enums ScanCodes/SpecialScanCodes do not match to non-US keyboards. 
Doesn't matter, we will provide the right numbers
*/
#include <ps2dev.h>
PS2dev keyboard(PS2_CLOCK, PS2_DATA);  //clock + data pins



#ifdef KBD_DEBUG
//This is code for the debug outputs
unsigned long DbgTimeCount = 0, DbgTimeStart, DbgTimeEnd;
//Some char buffers for text output
char DbgBuf1[30], DbgBuf2[4], DbgBuf3[4];
//For identifying the first run of the loop
uint8_t DbgLoopStart = 0;
#endif

unsigned long KeyboardRepeatIntervall = 500;  //ms
//Remember the last pressed key, for implementing key repeat
uint8_t LastPressedKey;
//Remember when this key was last pressed
unsigned long LastPressedKeyTimestamp;
//The repeat interval

//This is used by DetectPressedKeys
bool CurrentlyPressedKeys[KBD_REAL_KEY_COUNT];
//This is for comparing
bool PreviouslyPressedKeys[KBD_REAL_KEY_COUNT];

/*
  the setup routine runs once when you press reset
*/
void setup() {
#ifdef KBD_DEBUG
  //initialize serial communication at certain bits per second:
  //This is the debug output.
  Serial.begin(KBD_DEBUG_BAUDRATE);
  Serial.println("entering setup()...");
#endif
  //Prepare the output pins for LED and Display buttons.
  PrepareKbdLeds();
  PrepareDspKeys();

#ifdef KBD_DEBUG
  //Let all leds flash up. Nice during development.
  TestAllKbdLeds();
  TestAllDspKeys();
#endif
  keyboard.keyboard_init();  //ps2dev

#ifdef KBD_DEBUG
  Serial.println("leaving setup()...");
#endif
}

/*
  the loop routine runs over and over again forever:
*/
void loop() {
  unsigned char leds;  //ps2dev
  uint8_t index = KBD_REAL_KEY_COUNT;

#ifdef KBD_DEBUG
  if (DbgLoopStart == 0) {
    Serial.println("entering loop() for the first time...");
  }
#endif


  //backup the old detected data
  //while (index--) *(PreviouslyPressedKeys + index) = *(CurrentlyPressedKeys + index);
  for (index = 0; index < KBD_REAL_KEY_COUNT; index++) {
    PreviouslyPressedKeys[index] = CurrentlyPressedKeys[index];
  }
#ifdef KBD_DEBUG
  DbgTimeStart = micros();
#endif
  //get new data
  DetectPressedKeys();
  //delay(5);
#ifdef KBD_DEBUG
  DbgTimeEnd = micros();
#endif

  for (index = 0; index < KBD_REAL_KEY_COUNT; index++) {
    if (PreviouslyPressedKeys[index] != CurrentlyPressedKeys[index]) {





#ifdef KBD_DEBUG
      //change detected
      if (CurrentlyPressedKeys[index]) {

        Serial.print(F("\r\npressed: "));
      } else {
        Serial.print(F("\r\nreleased: "));
      }

      strcpy_P(DbgBuf1, (char*)pgm_read_word(&(HumanReadableDecoder[index])));

      //Serial.print(F("Key#"));
      //Serial.print(itoa(index, DbgBuf2, 10));
      //Serial.print(F(",Pin1="));
      //Serial.print(itoa(MatrixPins[index].Pin1, DbgBuf2, 10));
      //Serial.print(F(",Pin2="));
      //Serial.print(itoa(MatrixPins[index].Pin2, DbgBuf3, 10));
      //Serial.print(F(",HRLabel='"));

      Serial.print("'");
      Serial.print(DbgBuf1);
      Serial.print("'");
      //  Serial.print(F("' ScanDuration(µs)"));
      //  Serial.print(itoa(DbgTimeEnd - DbgTimeStart, DbgBuf2, 10));
      Serial.println("");
#endif

      if (CurrentlyPressedKeys[index]) {

        //remember the last pressed key, for repeating
        LastPressedKey = index;
        LastPressedKeyTimestamp = millis();
#ifdef KBD_DEBUG
        Serial.print("last pressed key noted for repeat:");
        Serial.print(LastPressedKey);

#endif
      }
    }
  }
#ifdef KBD_DEBUG
  if (DbgLoopStart == 0) {
    Serial.println("passed loop() for the first time. loop() will continue without further messages...");
    DbgLoopStart = 1;
  }
#endif

  //Ps2dev
  //Handle PS2 communication and react to keyboard led change
  //This should be done at least once each 10ms

  if(keyboard.keyboard_handle(&leds)) {
#ifdef KBD_DEBUG
        Serial.print("\r\nKeyboard LEDs change:");
        Serial.print(leds, HEX);
#endif
    SetKeyboardLEDs(leds);
  }
}

/*
  Determines the currently pressed keys. The result is the array of bool CurrentlyPressedKeys
*/
void DetectPressedKeys() {
  uint8_t ScanIndex, ScanByteCount, VirtKeyIndex, OutPin, InPin, Ps2CodeFragment, Ps2CodeDetail;
  bool Result, FnDependend, NumLockDependend, SendMakeCode, SendBreakCode;
  unsigned long Now;

  //over all keys
  for (ScanIndex = 0; ScanIndex < KBD_REAL_KEY_COUNT; ScanIndex++) {
    //init
    FnDependend = 0;
    NumLockDependend = 0;
    VirtKeyIndex = 0;
    SendMakeCode = 0;
    SendBreakCode = 0;
    Ps2CodeDetail = SCANID_MK_DUMMY;


    //The two pins with the specific button in between.
    OutPin = MatrixPins[ScanIndex].Pin1;
    InPin = MatrixPins[ScanIndex].Pin2;

    //set output pin LOW.
    SetKbdPin(OutPin, LOW);

    //Set the input pullup before reading
    SetKbdPinMode(InPin, INPUT_PULLUP);

    //Without a small delay, keys may be accidently reported as pressed, even without any user action.
    // delayMicroseconds(5);

    //get the result (a bool), but invert it as a pressed key reads as a LOW from the OutPin.
    Result = !GetKbdPin(InPin);
    CurrentlyPressedKeys[ScanIndex] = Result;

    if ((Result == LOW) && (LastPressedKey == ScanIndex) && (ScanIndex != KBD_KEY_FN)) {

      if ((LastPressedKey == ScanIndex) && (ScanIndex != KBD_KEY_FN)) {
        if (Result == 1) {
          //That key is already pressed
          Now = millis();
          if ((Now - LastPressedKeyTimestamp) > KeyboardRepeatIntervall) {
            //release the key to trigger it again
            CurrentlyPressedKeys[ScanIndex] = LOW;
#ifdef KBD_DEBUG
            Serial.print("\r\nreleased the key to enable to trigger it again:");
            Serial.print(ScanIndex);
#endif
            LastPressedKey = KBD_KEY_UNDEFINED; 
          } else {
            //That key is released meanwhile
            LastPressedKey = KBD_KEY_UNDEFINED;  
#ifdef KBD_DEBUG
            Serial.print("\r\nremoved repeat 'marking' from key:");
            Serial.print(ScanIndex);
#endif
          }
        }
      }
    }

    if (PreviouslyPressedKeys[ScanIndex] != Result) {
      //There is a change in the status of this button!
      if (Result) {
        //Key is pressed, send MakeCode
        SendMakeCode = 1;


      } else {
        //key is release, send BreakCode
        SendBreakCode = 1;
      }

      //preset, might be overwritten if there are special keys to deal with
      VirtKeyIndex = ScanIndex;

      //deal with current Fn button status. Fn itself does not trigger any PS/2 scan code
      if (CurrentlyPressedKeys[KBD_KEY_FN]) {

        if ((ScanIndex >= KBD_FN_DEPENDENT_START_INDEX) && (ScanIndex <= KBD_FN_DEPENDENT_END_INDEX)) {
          FnDependend = 1;
          VirtKeyIndex = ScanIndex + KBD_FN_ACTIVATED_OFFSET;
        }
      }

      //deal with Num Lock status
      if (KeyboardLEDPin[KBD_CAPS_LOCK]) {
        if ((ScanIndex >= KBD_KBD_NUMLOCK_DEPENDENT_END_INDEX) && (ScanIndex <= NUMLOCK_DEPENDENT_END_INDEX)) {
          NumLockDependend = 1;
          VirtKeyIndex = ScanIndex + KBD_NUMLOCK_ACTIVATED_OFFSET;
        }
      }

      if (VirtKeyIndex != KBD_KEY_FN)  //keep calm if it is the Fn key
      {
        //Scan is done. Now put the pieces together to get the correct scancode
        if (SendMakeCode == 1) {
          //We need the MakeCode

          switch (Ps2CodeCombo[VirtKeyIndex].ByteCountMakeCode) {
            case SCANCODE_1BYTE:
              Ps2CodeDetail = SCANID_MK_STD;
              break;
            case SCANCODE_2BYTE:
              Ps2CodeDetail = SCANID_MK_SPCL;
              break;
            default:
              if (VirtKeyIndex == KBD_KEY_PRINT) {
                Ps2CodeDetail = SCANID_MK_PRINT;
              } else {
                if (VirtKeyIndex == KBD_KEY_BREAK) {
                  Ps2CodeDetail = SCANID_MK_BREAK;
                } else {
                  //no known other scan codes
                  Ps2CodeDetail = SCANID_MK_DUMMY;
                }
              }
          }
          Ps2CodeFragment = Ps2CodeCombo[VirtKeyIndex].MakeCode;
        }

        if (SendBreakCode == 1) {

          //We need the BreakCode
          switch (Ps2CodeCombo[VirtKeyIndex].ByteCountMakeCode)  //yes, makecode
          {
            case SCANCODE_1BYTE:
              Ps2CodeDetail = SCANID_BK_STD;
              break;
            case SCANCODE_2BYTE:
              Ps2CodeDetail = SCANID_BK_SPCL;
              break;
            default:
              if (VirtKeyIndex == KBD_KEY_PRINT) {
                Ps2CodeDetail = SCANID_BK_PRINT;
              } else {
                Ps2CodeDetail = SCANID_BK_DUMMY;
                //There is no break for break
                //and no known other weired scan codes
              }
          }
          Ps2CodeFragment = Ps2CodeCombo[VirtKeyIndex].MakeCode;
        }
        if ((SendMakeCode == 1) || (SendBreakCode == 1)) {


#ifdef KBD_DEBUG

          Serial.print("\r\n\r\nScanIndex: ");
          Serial.print(ScanIndex);
          Serial.print(" OutPin: ");
          Serial.print(" OutPin: ");
          Serial.print(OutPin);
          Serial.print(" InPin: ");
          Serial.print(InPin);
          Serial.print(" Result: ");
          Serial.print(Result);
          Serial.print(" CurrentlyPressedKeys[i]: ");
          Serial.print(CurrentlyPressedKeys[ScanIndex]);
          Serial.print(" PreviouslyPressedKeys[i]: ");
          Serial.print(PreviouslyPressedKeys[ScanIndex]);


#endif

          if ((Ps2CodeDetail == SCANID_MK_DUMMY) || (Ps2CodeDetail == SCANID_BK_DUMMY)) {
            //The button is for internal use
            TriggerDisplayButton(Ps2CodeDetail, VirtKeyIndex);
          } else {
            //The button needs to cause some PS/2 activity
            SendScanCodeOverPs2(Ps2CodeFragment, Ps2CodeDetail, VirtKeyIndex);  //
          }
        }
      }
    }  //if (PreviouslyPressedKeys[index] != CurrentlyPressedKeys[index])
    //remove the output voltage
    SetKbdPinMode(OutPin, INPUT);
    SetKbdPinMode(OutPin, INPUT_PULLUP);
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
void SetKeyboardLEDs(uint8_t LedValues) {
  uint8_t i;
  /*
     The lower 3 bits of the input will trigger the LEDs
  */
  //over all LEDs
  for (i = 0; i < KBD_LED_PINCOUNT; i++) {
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
void SetDisplayControlKeys(uint8_t KeyValues) {
  uint8_t i;

  //over all control keys
  for (i = 0; i < DISP_CTRL_PINCOUNT; i++) {
    //shift the filter bit each time

    SetDispCtrlPin(i, KeyValues & (0x01 << i));
  }
}
/*
  Set a single Keyboard pin as output and give it the defined value.
  To simplify bug hunting, this shall be the only way to set any Keyboard value.
  PinNumber is 1 ... KBD_PINCOUNT.
*/
void SetKbdPin(uint8_t PinNumber, bool OutVal) {
  //new
  SetKbdPinMode(PinNumber, OUTPUT);
  digitalWrite(KeyboardPin[PinNumber - 1], OutVal);
}
/*
  Get a single Keyboard pin value
  To simplify bug hunting, this shall be the only way to get any Keyboard value.
  PinNumber is 1 ... KBD_PINCOUNT.
*/
bool GetKbdPin(uint8_t PinNumber) {
  return digitalRead(KeyboardPin[PinNumber - 1]);
}


/*
  Set the mode of a single Keyboard pin
  To simplify bug hunting, this shall be the only way to set any Keyboard pinmode.
 PinNumber is 1 ... KBD_PINCOUNT.
*/
void SetKbdPinMode(uint8_t PinNumber, uint8_t PinMode) {
  //change mode
  pinMode(KeyboardPin[PinNumber - 1], PinMode);
}
void SetKbdLedPin(uint8_t PinNumber, bool OutVal) {
  SetKbdLedPinMode(PinNumber, OUTPUT);
  digitalWrite(KeyboardLEDPin[PinNumber], OutVal);
}

void SetKbdLedPinMode(uint8_t PinNumber, uint8_t PinMode) {
  pinMode(KeyboardLEDPin[PinNumber], PinMode);
}

void SetDispCtrlPin(uint8_t PinNumber, bool OutVal) {
  SetDispCtrlPinMode(PinNumber, OUTPUT);
  digitalWrite(DisplayButtonPin[PinNumber], OutVal);
}

void SetDispCtrlPinMode(uint8_t PinNumber, uint8_t PinMode) {
  pinMode(DisplayButtonPin[PinNumber], PinMode);
}

void PrepareKbdLeds() {
  uint8_t i;

  for (i = 0; i < KBD_LED_PINCOUNT; i++) {
    SetKbdLedPinMode(i, OUTPUT);
  }
}

void PrepareDspKeys() {
  uint8_t i;

  for (i = 0; i < DISP_CTRL_PINCOUNT; i++) {
    SetDispCtrlPinMode(i, OUTPUT);
  }
}
/*
 #define BITVAL_DISP_CTRL_POWER 		BITVAL_DISP_CTRL_PIN1
  #define BITVAL_DISP_CTRL_DOWN	 	BITVAL_DISP_CTRL_PIN2
  #define BITVAL_DISP_CTRL_UP	 		BITVAL_DISP_CTRL_PIN3
  #define BITVAL_DISP_CTRL_MENU	 	BITVAL_DISP_CTRL_PIN4
  #define BITVAL_DISP_CTRL_AUTO	 	BITVAL_DISP_CTRL_PIN5
  
*/
void TriggerDisplayButton(uint8_t Ps2CodeDetail, uint8_t VirtKeyIndex) {
  uint8_t DisplayButtons = 0x00;

  switch (VirtKeyIndex) {
    case KBD_FN_VIRTKEY_F6:
      switch (Ps2CodeDetail) {
        case (SCANID_MK_DUMMY):
          //Serial.println("### € ein");
          //bitwise OR
          DisplayButtons |= BITVAL_DISP_CTRL_POWER;
          break;
        case (SCANID_BK_DUMMY):
          //Serial.println("### € aus");
          //biswise AND with inversed pattern
          DisplayButtons &= ~BITVAL_DISP_CTRL_POWER;
          break;
      }
      break;
  }
  SetDisplayControlKeys(DisplayButtons);
}
/*
  Iterate over the keyboard LEDs and the keys to adjust the display adapter board.
  Set each pin to High, wait some time, then set back to low
  Usefull for hardware debugging. The LEDs and Keys are known via their defines.
*/
void TestAllKbdLeds() {
  uint8_t i;
  const unsigned long myDelay = KBD_TESTTIME;  //milliseconds
  const unsigned char pattern[KBD_LED_PINCOUNT] = {
    //The LEDs
    BITVAL_CAPS_LOCK_LED,
    BITVAL_NUM_LOCK_LED,
    BITVAL_SCROLL_LOCK_LED
  };

  delay(myDelay);
  SetKeyboardLEDs(0x07);  //all active

  delay(myDelay);
  SetKeyboardLEDs(0x00);  //all off

  delay(myDelay);
  for (i = 0; i < KBD_LED_PINCOUNT; i++) {
    SetKeyboardLEDs(pattern[i]);
    delay(myDelay);
    SetKeyboardLEDs(0x00);
    delay(myDelay);
  }
}

#ifdef KBD_DEBUG
/*
This Subroutine is only useful for early developing tests. It sets each of the Display control
button pins to High, one after the other. Once these pins are connected to the control board,
calling this subroutine might disturb the whole thing.
*/
void TestAllDspKeys() {
  uint8_t i;
  const unsigned long myDelay = KBD_TESTTIME;  //milliseconds
  const unsigned char pinCount = 5, keyCount = 5;


  const unsigned char pattern[pinCount] = {
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
  SetDisplayControlKeys(0x00);  //all off

  delay(myDelay);
  for (i = 0; i < keyCount; i++) {
    SetDisplayControlKeys(pattern[i]);
    delay(myDelay);
    SetDisplayControlKeys(0x00);
  }
}
#endif
/*
  This is our connection to the Ps2dev library.
  It gets the scancode fragment and some more details and uses this to prepare the right call
  to send the scancode.
*/
void SendScanCodeOverPs2(uint8_t ScanCodeFragment, uint8_t ScanCodeId, uint8_t VirtKey) {
#ifdef KBD_DEBUG

  Serial.print("\r\nPS2: code 0x");
  Serial.print(ScanCodeFragment, HEX);
  Serial.print(", Detail 0x");
  Serial.print(ScanCodeId, HEX);
  Serial.print(", Key(dez) ");

  Serial.print(VirtKey);

#endif

  //Most scancodes are 1byte, some are 2 byte and a few are longer.
  //We always provide 1 byte, even for 2 byte scancodes. The ps2dev library knows how to fill this gap.
  //For the longer scancodes, there are special subroutines to call. No scancode required.
  switch (ScanCodeId) {
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
      //Note: there is no Break for Break available. This is the only key that has no BreakCode
      break;
    case SCANID_MK_DUMMY:
      //do nothing
      break;
    case SCANID_BK_DUMMY:
      //do nothing
      break;
  }
}