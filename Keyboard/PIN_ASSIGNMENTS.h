/*
 * 2023-12-12
 * PiBook_on_AcerTravelMate4001
 * Target System: Teensy ++2.0 and Arduino Mega 2560
 * Arduino IDE: 2.2.1
 * 
*/

//Available pinouts. Activate only one
//#define PINOUT_TEENSY_PP_2
#define PINOUT_ARDUINO_MEGA2560

#if defined(PINOUT_ARDUINO_MEGA2560) || defined(PINOUT_TEENSY_PP_2)
	//at least one is active

	#if defined(PINOUT_ARDUINO_MEGA2560) && defined(PINOUT_TEENSY_PP_2)	
		#error "More than one Arduino pinout active. Activate only one"
	#else
		#if defined(PINOUT_ARDUINO_MEGA2560)
			#pragma "Pinout for Arduino Mega 2560 is in use"
		#endif
		#if defined(PINOUT_TEENSY_PP_2)
			#pragma "Pinout for Teensy ++2.0 is in use"
		#endif
	#endif
#else
	#error "No Pinout active. Activate one"
#endif



#if defined(PINOUT_TEENSY_PP_2)
/******************************************************************************
* For Teensy ++2.0, using Arduino Naming
******************************************************************************/ 
//here, each pin gets a macro name
	//The lower side of PCB (seen from above, counted from left to right USB is on the left side)
	//PIN1 is GND
	#define T2_PCBPIN2_B7   27
	#define T2_PCBPIN3_D0   0
	#define T2_PCBPIN4_D1   1
	#define T2_PCBPIN5_D2   2
	#define T2_PCBPIN6_D3   3 
	#define T2_PCBPIN7_D4   4 
	#define T2_PCBPIN8_D5   5 
	#define T2_PCBPIN9_D6   6  //The blue LED on PCB is connected to D6.
	#define T2_PCBPIN10_D7  7
	#define T2_PCBPIN11_E0  8 
	#define T2_PCBPIN12_E1  9 
	#define T2_PCBPIN13_C0 10
	#define T2_PCBPIN14_C1 11
	#define T2_PCBPIN15_C2 12
	#define T2_PCBPIN16_C3 13
	#define T2_PCBPIN17_C4 14
	#define T2_PCBPIN18_C5 15
	#define T2_PCBPIN19_C6 16
	#define T2_PCBPIN20_C7 17

	//upper side of PCB (seen from above, counted from RIGHT to LEFT, USB is on the left side)
	#define T2_PCBPIN21_F7  45
	#define T2_PCBPIN22_F6  44
	#define T2_PCBPIN23_F5  43
	#define T2_PCBPIN24_F4  42
	#define T2_PCBPIN25_F3  41
	#define T2_PCBPIN26_F2  40
	#define T2_PCBPIN27_F1  39
	#define T2_PCBPIN28_F0  38
	//PIN29 is AREF
	//PIN30 is GND

	#define T2_PCBPIN31_INT6  18
	#define T2_PCBPIN32_INT7  19
	#define T2_PCBPIN33 20
	#define T2_PCBPIN34 21
	#define T2_PCBPIN35 22
	#define T2_PCBPIN36 23
	#define T2_PCBPIN37_PWM  24
	#define T2_PCBPIN38_PWM  25
	#define T2_PCBPIN39_PWM  26
	//PIN40 is +5V

	//PCB interior. There are two groups of pins. A pair of pins and a group of 2x4 pins
	#define T2_PCBPIN_E4_INT4  36
	#define T2_PCBPIN_E5_INT5  37

	#define T2_PCBPIN_PA0  28
	#define T2_PCBPIN_PA1  29
	#define T2_PCBPIN_PA2  30
	#define T2_PCBPIN_PA3  31
	#define T2_PCBPIN_PA4  32
	#define T2_PCBPIN_PA5  33
	#define T2_PCBPIN_PA6  34
	#define T2_PCBPIN_PA7  35
  
//Now, map required pins to that named pins 
	//The 24 pins for accessing the keyboard matrix, mapped to the Teensy++2.0)
	#define KBD_MATR_PIN1 T2_PCBPIN2_B7
	#define KBD_MATR_PIN2 T2_PCBPIN3_D0
	#define KBD_MATR_PIN3 T2_PCBPIN4_D1
	#define KBD_MATR_PIN4 T2_PCBPIN5_D2
	#define KBD_MATR_PIN5 T2_PCBPIN6_D3
	#define KBD_MATR_PIN6 T2_PCBPIN7_D4
	#define KBD_MATR_PIN7 T2_PCBPIN8_D5
	//avoid T2_PCBPIN9_D6 because of the blue LED
	#define KBD_MATR_PIN8 T2_PCBPIN10_D7

	#define KBD_MATR_PIN9  T2_PCBPIN11_E0
	#define KBD_MATR_PIN10 T2_PCBPIN12_E1
	#define KBD_MATR_PIN11 T2_PCBPIN13_C0
	#define KBD_MATR_PIN12 T2_PCBPIN14_C1
	#define KBD_MATR_PIN13 T2_PCBPIN15_C2
	#define KBD_MATR_PIN14 T2_PCBPIN16_C3
	#define KBD_MATR_PIN15 T2_PCBPIN17_C4
	#define KBD_MATR_PIN16 T2_PCBPIN18_C5

	#define KBD_MATR_PIN17 T2_PCBPIN19_C6
	#define KBD_MATR_PIN18 T2_PCBPIN20_C7
	#define KBD_MATR_PIN19 T2_PCBPIN21_F7
	#define KBD_MATR_PIN20 T2_PCBPIN22_F6
	#define KBD_MATR_PIN21 T2_PCBPIN23_F5
	#define KBD_MATR_PIN22 T2_PCBPIN24_F4
	#define KBD_MATR_PIN23 T2_PCBPIN25_F3
	#define KBD_MATR_PIN24 T2_PCBPIN26_F2

	//The 3 pins for accessing the LEDs related to the keyboard
	#define KBD_LED_PIN1 T2_PCBPIN27_F1
	#define KBD_LED_PIN2 T2_PCBPIN28_F0
	#define KBD_LED_PIN3 T2_PCBPIN31_INT6

	//The 5 pins for accessing the substitution of the keys for the display controller board  
	#define DISP_CTRL_PIN1 T2_PCBPIN32_INT7 
	#define DISP_CTRL_PIN2 T2_PCBPIN33
	#define DISP_CTRL_PIN3 T2_PCBPIN34
	#define DISP_CTRL_PIN4 T2_PCBPIN35
	#define DISP_CTRL_PIN5 T2_PCBPIN36


	//The 2 pins for the PS/2 Interface
	#define PS2_CLOCK T2_PCBPIN37_PWM
	#define PS2_DATA T2_PCBPIN38_PWM  

#endif
/******************************************************************************
* End of Teensy ++2.0 specific definitions
******************************************************************************/ 

/******************************************************************************
* For Arduino Mega 2560, using Arduino Naming 
******************************************************************************/ 
#if defined(PINOUT_ARDUINO_MEGA2560)

	// extension pins 
	#define KBD_MATR_PIN1   22
	#define KBD_MATR_PIN2   23
	#define KBD_MATR_PIN3   24
	#define KBD_MATR_PIN4   25
	#define KBD_MATR_PIN5   26
	#define KBD_MATR_PIN6   27
	#define KBD_MATR_PIN7   28
	#define KBD_MATR_PIN8   29

	#define KBD_MATR_PIN9   30
	#define KBD_MATR_PIN10  31
	#define KBD_MATR_PIN11  32
	#define KBD_MATR_PIN12  33
	#define KBD_MATR_PIN13  34
	#define KBD_MATR_PIN14  35
	#define KBD_MATR_PIN15  36
	#define KBD_MATR_PIN16  37

	#define KBD_MATR_PIN17  38
	#define KBD_MATR_PIN18  39
	#define KBD_MATR_PIN19  40
	#define KBD_MATR_PIN20  41
	#define KBD_MATR_PIN21  42
	#define KBD_MATR_PIN22  43
	#define KBD_MATR_PIN23  44
	#define KBD_MATR_PIN24  45
	
	//The 3 pins for accessing the LEDs related to the keyboard
	#define KBD_LED_PIN1  46
	#define KBD_LED_PIN2  47
	#define KBD_LED_PIN3  48
	
	//The 5 pins for accessing the substitution of the keys for the display controller board
	#define DISP_CTRL_PIN1  49
	#define DISP_CTRL_PIN2  50
	#define DISP_CTRL_PIN3  51
	#define DISP_CTRL_PIN4  52
	#define DISP_CTRL_PIN5  53	
	
	//The 2 pins for the PS/2 Interface
	#define PS2_CLOCK 3
	#define PS2_DATA  2
#endif
/******************************************************************************
* End of Arduino Mega 2560 specific definitions
******************************************************************************/ 

/******************************************************************************
* General Settings
******************************************************************************/ 


	//We need as much keyboard pins as the keyboard matrix needs
	#define KBD_PINCOUNT MATRIX_PINS_COUNT

	//A keyboard uses 3 LEDs
	#define KBD_LED_PINCOUNT 3
	//The values that represent the LED. Used to call the function
	#define BITVAL_CAPS_LOCK_LED 	0x01
	#define BITVAL_NUM_LOCK_LED		0x02
	#define BITVAL_SCROLL_LOCK_LED	0x04

	//alias names
	#define KBD_CAPS_LOCK 		KBD_LED_PIN1
	#define KBD_NUM_LOCK 	  	KBD_LED_PIN2
	#define KBD_SCROLL_LOCK 	KBD_LED_PIN3

	//The display control PCB used 5 buttons.
	#define DISP_CTRL_PINCOUNT 5
	//The values that represent the Display Buttons. Used to call the function
	#define BITVAL_DISP_CTRL_PIN1 0x01
	#define BITVAL_DISP_CTRL_PIN2 0x02
	#define BITVAL_DISP_CTRL_PIN3 0x04
	#define BITVAL_DISP_CTRL_PIN4 0x08
	#define BITVAL_DISP_CTRL_PIN5 0x10

	//alias names
	#define DISP_CTRL_POWER 	DISP_CTRL_PIN1
	#define DISP_CTRL_DOWN	 	DISP_CTRL_PIN2
	#define DISP_CTRL_UP	 	DISP_CTRL_PIN3
	#define DISP_CTRL_MENU	 	DISP_CTRL_PIN4
	#define DISP_CTRL_AUTO	 	DISP_CTRL_PIN5

/******************************************************************************
* End of General Settings
******************************************************************************/ 







