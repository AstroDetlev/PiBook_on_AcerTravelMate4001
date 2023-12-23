/*
 * This file contains the macros and settings to feed the keyboard key detection part with the right details to deal
 * with the keyboard of an Acer Travelmate 4001 WLMI with german keyboard layout
 *
 * 2022-02-10 AstroDetlev
 * PiBook_on_AcerTravelMate4001
 * Target System: Teensy ++2.0 and ArduinoMega 2560
 * Arduino IDE: 2.2.1
 *
*/
//How many pins are ocupied by the matrix decoder
#define MATRIX_PINS_COUNT 24
//How many different electrical buttons do we have
#define MATRIX_KEY_COUNT 89

//unique names and unique numbers for all electrical buttons. Numbers are used as index to iterate over all buttons
//They are in a useful order that allows to set ranges to iterate through
//Fn Key
#define ID_KEY_FN   			0 

//Fn-activated keys
#define ID_KEY_F2  				1  //Fn + F2  =  ACPI Power
#define ID_KEY_F3  				2  //Fn + F3  =  ACPI Wake
#define ID_KEY_F4  				3  //Fn + F4  =  ACPI Sleep
#define ID_KEY_F5  				4  //Fn + F5  =  Toggle between internal, external and both displays
#define ID_KEY_F6  				5  //Fn + F6  =  Turn backlight off to save power
#define ID_KEY_F7  				6  //Fn + F7  =  Toggle Touchpad
#define ID_KEY_F8  				7  //Fn + F8  =  Mute Speakers
#define ID_KEY_ARROW_RIGHT  	8  //Fn + right = Brightness up
#define ID_KEY_ARROW_LEFT  		9  //Fn + left  = Brightness down
#define ID_KEY_ARROW_DOWN 		10 //Fn + down  = Volume down  
#define ID_KEY_ARROW_UP  		11 //Fn + up    = Volume up
#define ID_KEY_F11 				12 //Fn + F11 =  turn on NumLock
#define ID_KEY_F12 				13 //Fn + F12 =  turn on ScrollLock

	#define FN_INFLUENCED_START_INDEX 1
	#define FN_INFLUENCED_COUNT 13

//Note: The numpad can be activated via Numlock. But from there, Fn is no longer required to be pressed.
//Which PS2 code is send for these blue marked buttons does not depend on Fn but on the status of the Numlock LED.
//Numlock LED related keys. Numlock keys have their own code.
#define ID_KEY_7  				14  // If NumLock LED is active, Code is NUMLOCK 7
#define ID_KEY_9 				15  // If NumLock LED is active, Code is NUMLOCK 8
#define ID_KEY_8  				16  // If NumLock LED is active, Code is NUMLOCK 9
#define ID_KEY_0  				17  // If NumLock LED is active, Code is NUMLOCK *
#define ID_KEY_U  				18  // If NumLock LED is active, Code is NUMLOCK 4
#define ID_KEY_I  				19  // If NumLock LED is active, Code is NUMLOCK 5
#define ID_KEY_O  				20  // If NumLock LED is active, Code is NUMLOCK 6
#define ID_KEY_P  				21  // If NumLock LED is active, Code is NUMLOCK -
#define ID_KEY_J  				22  // If NumLock LED is active, Code is NUMLOCK 1
#define ID_KEY_K  				23  // If NumLock LED is active, Code is NUMLOCK 2
#define ID_KEY_L  				24  // If NumLock LED is active, Code is NUMLOCK 3
#define ID_KEY_OE   			25  // If NumLock LED is active, Code is NUMLOCK +
#define ID_KEY_M  				26  // If NumLock LED is active, Code is NUMLOCK 0
#define ID_KEY_DOT  			27  // If NumLock LED is active, Code is NUMLOCK ,
#define ID_KEY_MINUS  			28  // If NumLock LED is active, Code is NUMLOCK /

	#define NUMLOCK_INFLUENCED_START_INDEX 14
	#define NUMLOCK_INFLUENCED_COUNT 15
//These buttons have unusual long make- or breakcodes
#define ID_KEY_PRINT  			29 
#define ID_KEY_PAUSE 			30 
	#define LONG_SCANCODE_START_INDEX 29
	#define LONG_SCANCODE_COUNT 2

#define ID_KEY_DOLLAR   		31 // ID_KEY_SHIFT_L + ID_KEY_4
#define ID_KEY_EURO   			32 // ID_KEY_ALT_R + ID_KEY_E
	#define MACROBUTTON_START_INDEX 31
	#define MACROBUTTON_COUNT 2

#define ID_KEY_CAPS_LOCK 		33 // Turn on Capslock. Does not influence any PS2 code
#define ID_KEY_CTRL_L  			34 // Does not influence any PS2 code
#define ID_KEY_CTRL_R  			35 // Does not influence any PS2 code
#define ID_KEY_ALT_L  			36 // Does not influence any PS2 code
#define ID_KEY_ALT_R  			37 // Does not influence any PS2 code
#define ID_KEY_SHIFT_L  		38 // Does not influence any PS2 code
#define ID_KEY_SHIFT_R  		39 // Does not influence any PS2 code
#define ID_KEY_WIN_L  			40 // Does not influence any PS2 code
#define ID_KEY_WIN_R  			41 // Does not influence any PS2 code
#define ID_KEY_F1  				42 // Does not influence any PS2 code
#define ID_KEY_F9  				43 // Does not influence any PS2 code
#define ID_KEY_F10 				44 // Does not influence any PS2 code
#define ID_KEY_Q 				45 // Does not influence any PS2 code
#define ID_KEY_1 				46 // Does not influence any PS2 code
#define ID_KEY_ESC				47 // Does not influence any PS2 code
#define ID_KEY_CIRCUMFLEX  			48 // Does not influence any PS2 code
#define ID_KEY_TAB 				49 // Does not influence any PS2 code
#define ID_KEY_BACKSPACE 		50 // Does not influence any PS2 code
#define ID_KEY_3  				51 // Does not influence any PS2 code
#define ID_KEY_2  				52 // Does not influence any PS2 code
#define ID_KEY_INSERT  			53 // Does not influence any PS2 code
#define ID_KEY_DELETE  			54 // Does not influence any PS2 code
#define ID_KEY_HOME 			55 // Does not influence any PS2 code
#define ID_KEY_PAGE_UP 			56 // Does not influence any PS2 code
#define ID_KEY_PAGE_DOWN  		57 // Does not influence any PS2 code
#define ID_KEY_UE  				58 // Does not influence any PS2 code
#define ID_KEY_AE  				59 // Does not influence any PS2 code
#define ID_KEY_QUESTIONMARK  	60 // Does not influence any PS2 code
#define ID_KEY_5  				61 // Does not influence any PS2 code
#define ID_KEY_APOS  			62 // Does not influence any PS2 code
#define ID_KEY_6  				63 // Does not influence any PS2 code
#define ID_KEY_4  				64 // Does not influence any PS2 code
#define ID_KEY_ASTERISK   		65 // Does not influence any PS2 code
#define ID_KEY_T 				66 // Does not influence any PS2 code
#define ID_KEY_R  				67 // Does not influence any PS2 code
#define ID_KEY_W  				68 // Does not influence any PS2 code
#define ID_KEY_ENTER  			69 // Does not influence any PS2 code
#define ID_KEY_H  				70 // Does not influence any PS2 code
#define ID_KEY_Z  				71 // Does not influence any PS2 code
#define ID_KEY_E  				72 // Does not influence any PS2 code
#define ID_KEY_S  				73 // Does not influence any PS2 code
#define ID_KEY_COMMA  			74 // Does not influence any PS2 code
#define ID_KEY_SHARP  			75 // Does not influence any PS2 code
#define ID_KEY_END  			76 // Does not influence any PS2 code
#define ID_KEY_G  				77 // Does not influence any PS2 code
#define ID_KEY_V  				78 // Does not influence any PS2 code
#define ID_KEY_SPACE  			79 // Does not influence any PS2 code
#define ID_KEY_C  				80 // Does not influence any PS2 code
#define ID_KEY_N  				81 // Does not influence any PS2 code
#define ID_KEY_B  				82 // Does not influence any PS2 code
#define ID_KEY_F  				83 // Does not influence any PS2 code
#define ID_KEY_A  				84 // Does not influence any PS2 code
#define ID_KEY_D  				85 // Does not influence any PS2 code
#define ID_KEY_LOWER_THAN  		86 // Does not influence any PS2 code
#define ID_KEY_X  				87 // Does not influence any PS2 code
#define ID_KEY_Y  				88 // Does not influence any PS2 code

	#define SIMPLEBUTTON_START_INDEX 33
	#define SIMPLEBUTTON_COUNT 56


//for debug and development. similar to the names of the buttons, the string that is printed on the button
const char PROGMEM HR_KEY_F11[] =      			"F11"                 ;
const char PROGMEM HR_KEY_F12[] =      			"F12"                 ;
const char PROGMEM HR_KEY_F8[] =       			"F8"                  ;
const char PROGMEM HR_KEY_Q[] =      			"Q"               ;
const char PROGMEM HR_KEY_F4[] =       			"F4"                  ;
const char PROGMEM HR_KEY_F3[] =       			"F3"                  ;
const char PROGMEM HR_KEY_F7[] =       			"F7"                  ;
const char PROGMEM HR_KEY_1[] =      			"1"               ;
const char PROGMEM HR_KEY_ESC[] =      			"ESC"                 ;
const char PROGMEM HR_KEY_CIRCUMFLEX[] =       		"^"               ;
const char PROGMEM HR_KEY_F5[] =       			"F5"                  ;
const char PROGMEM HR_KEY_TAB[] =      			"Tab"                 ;
const char PROGMEM HR_KEY_F1[] =       			"F1"                  ;
const char PROGMEM HR_KEY_F2[] =       			"F2"                  ;
const char PROGMEM HR_KEY_F6[] =       			"F6"                  ;
const char PROGMEM HR_KEY_CAPS_LOCK[] =   		"CAPS_LOCK"       ;
const char PROGMEM HR_KEY_F10[] =      			"F10"                 ;
const char PROGMEM HR_KEY_F9[] =       			"F9"                  ;
const char PROGMEM HR_KEY_BACKSPACE[] =  			"BackSpace"       ;
const char PROGMEM HR_KEY_3[] =      				"3"               ;
const char PROGMEM HR_KEY_2[] =      				"2"               ;
const char PROGMEM HR_KEY_ARROW_UP[] =       		"Up"              ;
const char PROGMEM HR_KEY_BREAK[] =      			"Break"           ;
const char PROGMEM HR_KEY_PRINT[] =      			"Print"           ;
const char PROGMEM HR_KEY_INSERT[] =      			"Insert"          ;
const char PROGMEM HR_KEY_DELETE[] =      			"Delete"          ;
const char PROGMEM HR_KEY_HOME[] =     			"Pos1"                ;
const char PROGMEM HR_KEY_PAGE_UP[] =     			"PAGE_UP"         ;
const char PROGMEM HR_KEY_PAGE_DOWN[] =   			"PAGE_DOWN"       ;
const char PROGMEM HR_KEY_ARROW_RIGHT[] =      	"Right"               ;
const char PROGMEM HR_KEY_ARROW_LEFT[] =      		"Left"            ;
const char PROGMEM HR_KEY_ARROW_DOWN[] =      		"Down"            ;
const char PROGMEM HR_KEY_UE[] =       			"Ü"                   ;
const char PROGMEM HR_KEY_P[] =      				"P"               ;
const char PROGMEM HR_KEY_AE[] =       			"Ä"                   ;
const char PROGMEM HR_KEY_OE[] =       			"Ö"                   ;
const char PROGMEM HR_KEY_MINUS[] =    			"-"                   ;
const char PROGMEM HR_KEY_DOT[] =    				"."               ;
const char PROGMEM HR_KEY_DOLLAR[] =     			"$"               ;
const char PROGMEM HR_KEY_QUESTIONMARK[] =       	"?"               ;
const char PROGMEM HR_KEY_7[] =      				"7"               ;
const char PROGMEM HR_KEY_9[] =      				"9"               ;
const char PROGMEM HR_KEY_5[] =      				"5"               ;
const char PROGMEM HR_KEY_0[] =      				"0"               ;
const char PROGMEM HR_KEY_APOS[] =     			"'"                   ;
const char PROGMEM HR_KEY_6[] =      				"6"               ;
const char PROGMEM HR_KEY_8[] =      				"8"               ;
const char PROGMEM HR_KEY_4[] =      				"4"               ;
const char PROGMEM HR_KEY_EURO[] =     			"€"                   ;
const char PROGMEM HR_KEY_CTRL_L[] =      			"Ctrl-L"          ;
const char PROGMEM HR_KEY_CTRL_R[] =      			"Ctrl-R"          ;
const char PROGMEM HR_KEY_O[] =      				"O"               ;
const char PROGMEM HR_KEY_ASTERISK[] =   			"*"               ;
const char PROGMEM HR_KEY_T[] =      				"T"               ;
const char PROGMEM HR_KEY_U[] =      				"U"               ;
const char PROGMEM HR_KEY_R[] =      				"R"               ;
const char PROGMEM HR_KEY_W[] =      				"W"               ;
const char PROGMEM HR_KEY_SHIFT_R[] =      		"Shift-R"             ;
const char PROGMEM HR_KEY_SHIFT_L[] =      		"Shift-L"             ;
const char PROGMEM HR_KEY_I[] =      				"I"               ;
const char PROGMEM HR_KEY_ENTER[] =      			"Enter"           ;
const char PROGMEM HR_KEY_H[] =      				"H"               ;
const char PROGMEM HR_KEY_Z[] =      				"Z"               ;
const char PROGMEM HR_KEY_E[] =      				"E"               ;
const char PROGMEM HR_KEY_S[] =      				"S"               ;
const char PROGMEM HR_KEY_L[] =      				"L"               ;
const char PROGMEM HR_KEY_K[] =      				"K"               ;
const char PROGMEM HR_KEY_M[] =      				"M"               ;
const char PROGMEM HR_KEY_COMMA[] =  				","               ;
const char PROGMEM HR_KEY_SHARP[] =    			"#"                   ;
const char PROGMEM HR_KEY_END[] =      			"End"                 ;
const char PROGMEM HR_KEY_WIN_R[] =      			"Win-R"           ;
const char PROGMEM HR_KEY_G[] =      				"G"               ;
const char PROGMEM HR_KEY_V[] =      				"V"               ;
const char PROGMEM HR_KEY_SPACE[] =      			"Space"           ;
const char PROGMEM HR_KEY_C[] =     				"C"               ;
const char PROGMEM HR_KEY_J[] =      				"J"               ;
const char PROGMEM HR_KEY_N[] =      				"N"               ;
const char PROGMEM HR_KEY_B[] =      				"B"               ;
const char PROGMEM HR_KEY_F[] =      				"F"               ;
const char PROGMEM HR_KEY_A[] =      				"A"               ;
const char PROGMEM HR_KEY_D[] =      				"D"               ;
const char PROGMEM HR_KEY_LOWER_THAN[] =    			"<"               ;
const char PROGMEM HR_KEY_X[] =      				"X"               ;
const char PROGMEM HR_KEY_WIN_L[] =      			"Win-L"           ;
const char PROGMEM HR_KEY_ALT_L[] =      			"Alt"             ;
const char PROGMEM HR_KEY_ALT_R[] =      			"AltGr"           ;
const char PROGMEM HR_KEY_Y[] =     				"Y"               ;
const char PROGMEM HR_KEY_FN[] =       			"Fn"                  ;

// There are many buttons with a second meaning, combined with "Fn"
const char PROGMEM HR_Fn_KEY_F11[] 		=      			"NumPad";
const char PROGMEM HR_Fn_KEY_F12[] 		=      			"Scroll";
const char PROGMEM HR_Fn_KEY_F8[] 		=      			"Speaker";
const char PROGMEM HR_Fn_KEY_Q[] 		  = "";
const char PROGMEM HR_Fn_KEY_F4[] 		=      			"Sleep";
const char PROGMEM HR_Fn_KEY_F3[] 		=      			"Wake up";
const char PROGMEM HR_Fn_KEY_F7[] 		=      			"Touchpad";
const char PROGMEM HR_Fn_KEY_1[] 		  = "";
const char PROGMEM HR_Fn_KEY_ESC[] 		= "";
const char PROGMEM HR_Fn_KEY_CIRCUMFLEX[] =       		"";
const char PROGMEM HR_Fn_KEY_F5[] =       			"Display";
const char PROGMEM HR_Fn_KEY_TAB[] =      			"";
const char PROGMEM HR_Fn_KEY_F1[] =       			"";
const char PROGMEM HR_Fn_KEY_F2[] =       			"Power Up";
const char PROGMEM HR_Fn_KEY_F6[] =       			"Backlight";
const char PROGMEM HR_Fn_KEY_CAPS_LOCK[] =   		"";
const char PROGMEM HR_Fn_KEY_F10[] =      			"";
const char PROGMEM HR_Fn_KEY_F9[] =       			"";
const char PROGMEM HR_Fn_KEY_BACKSPACE[] =  		"";
const char PROGMEM HR_Fn_KEY_3[] =      			"";
const char PROGMEM HR_Fn_KEY_2[] =      			"";
const char PROGMEM HR_Fn_KEY_ARROW_UP[] =       	"Sound+";
const char PROGMEM HR_Fn_KEY_BREAK[] =      		"";
const char PROGMEM HR_Fn_KEY_PRINT[] =      		"";
const char PROGMEM HR_Fn_KEY_INSERT[] =      		"";
const char PROGMEM HR_Fn_KEY_DELETE[] =      		"";
const char PROGMEM HR_Fn_KEY_HOME[] =     			"";
const char PROGMEM HR_Fn_KEY_PAGE_UP[] =     		"";
const char PROGMEM HR_Fn_KEY_PAGE_DOWN[] =   		"";
const char PROGMEM HR_Fn_KEY_ARROW_RIGHT[] =      	"Display-";
const char PROGMEM HR_Fn_KEY_ARROW_LEFT[] =      	"Display+";
const char PROGMEM HR_Fn_KEY_ARROW_DOWN[] =      	"Sound-";
const char PROGMEM HR_Fn_KEY_UE[] =       			"";
const char PROGMEM HR_Fn_KEY_P[] =      			"-";
const char PROGMEM HR_Fn_KEY_AE[] =       			"";
const char PROGMEM HR_Fn_KEY_OE[] =       			"+";
const char PROGMEM HR_Fn_KEY_MINUS[] =    			"/";
const char PROGMEM HR_Fn_KEY_DOT[] =    			",";
const char PROGMEM HR_Fn_KEY_DOLLAR[] =     		"";
const char PROGMEM HR_Fn_KEY_QUESTIONMARK[] =       "";
const char PROGMEM HR_Fn_KEY_7[] =      			"7";
const char PROGMEM HR_Fn_KEY_9[] =      			"9";
const char PROGMEM HR_Fn_KEY_5[] =      			"";
const char PROGMEM HR_Fn_KEY_0[] =      			"*";
const char PROGMEM HR_Fn_KEY_APOS[] =     			"";
const char PROGMEM HR_Fn_KEY_6[] =      			"";
const char PROGMEM HR_Fn_KEY_8[] =      			"8";
const char PROGMEM HR_Fn_KEY_4[] =      			"";
const char PROGMEM HR_Fn_KEY_EURO[] =     			"";
const char PROGMEM HR_Fn_KEY_CTRL_L[] =      		"";
const char PROGMEM HR_Fn_KEY_CTRL_R[] =      		"";
const char PROGMEM HR_Fn_KEY_O[] =      			"6";
const char PROGMEM HR_Fn_KEY_ASTERISK[] =   		"";
const char PROGMEM HR_Fn_KEY_T[] =      			"";
const char PROGMEM HR_Fn_KEY_U[] =      			"4";
const char PROGMEM HR_Fn_KEY_R[] =      			"";
const char PROGMEM HR_Fn_KEY_W[] =      			"";
const char PROGMEM HR_Fn_KEY_SHIFT_R[] =      		"";
const char PROGMEM HR_Fn_KEY_SHIFT_L[] =      		"";
const char PROGMEM HR_Fn_KEY_I[] =      			"5";
const char PROGMEM HR_Fn_KEY_ENTER[] =      		"";
const char PROGMEM HR_Fn_KEY_H[] =      			"";
const char PROGMEM HR_Fn_KEY_Z[] =      			"";
const char PROGMEM HR_Fn_KEY_E[] =      			"";
const char PROGMEM HR_Fn_KEY_S[] =      			"";
const char PROGMEM HR_Fn_KEY_L[] =      			"3";
const char PROGMEM HR_Fn_KEY_K[] =      			"2";
const char PROGMEM HR_Fn_KEY_M[] =      			"0";
const char PROGMEM HR_Fn_KEY_COMMA[] =  			"";
const char PROGMEM HR_Fn_KEY_SHARP[] =    			"";
const char PROGMEM HR_Fn_KEY_END[] =      			"";
const char PROGMEM HR_Fn_KEY_WIN_R[] =      		"";
const char PROGMEM HR_Fn_KEY_G[] =      			"";
const char PROGMEM HR_Fn_KEY_V[] =      			"";
const char PROGMEM HR_Fn_KEY_SPACE[] =      		"";
const char PROGMEM HR_Fn_KEY_C[] =     				"";
const char PROGMEM HR_Fn_KEY_J[] =      			"1";
const char PROGMEM HR_Fn_KEY_N[] =      			"";
const char PROGMEM HR_Fn_KEY_B[] =      			"";
const char PROGMEM HR_Fn_KEY_F[] =      			"";
const char PROGMEM HR_Fn_KEY_A[] =      			"";
const char PROGMEM HR_Fn_KEY_D[] =      			"";
const char PROGMEM HR_Fn_KEY_LOWER_THAN[] =    		"";
const char PROGMEM HR_Fn_KEY_X[] =      			"";
const char PROGMEM HR_Fn_KEY_WIN_L[] =      		"";
const char PROGMEM HR_Fn_KEY_ALT_L[] =      		"";
const char PROGMEM HR_Fn_KEY_ALT_R[] =      		"";
const char PROGMEM HR_Fn_KEY_Y[] =     				"";
const char PROGMEM HR_Fn_KEY_FN[] =       			"";

// A list as long as the list ob buttons. Contains a "1" if the meaning of the button can be influenced by "Fn"
const bool FnAffectedKeys[MATRIX_KEY_COUNT] =
{
  1, /*KEY_F11*/
  1, /*KEY_F12*/
  1, /*KEY_F8*/
  0, /*KEY_Q*/
  1, /*KEY_F4*/
  1, /*KEY_F3*/
  1, /*KEY_F7*/
  0, /*KEY_1*/
  0, /*KEY_ESC*/
  0, /*KEY_CIRCUMFLEX*/
  1, /*KEY_F5*/
  0, /*KEY_TAB*/
  0, /*KEY_F1*/
  1, /*KEY_F2*/
  1, /*KEY_F6*/
  0, /*KEY_CAPS_LOCK*/
  0, /*KEY_F10*/
  0, /*KEY_F9*/
  0, /*KEY_BACKSPACE*/
  0, /*KEY_3*/
  0, /*KEY_2*/
  1, /*KEY_ARROW_UP*/
  0, /*KEY_BREAK*/
  0, /*KEY_PRINT*/
  0, /*KEY_INSERT*/
  0, /*KEY_DELETE*/
  0, /*KEY_HOME*/
  0, /*KEY_PAGE_UP*/
  0, /*KEY_PAGE_DOWN*/
  1, /*KEY_ARROW_RIGHT*/
  1, /*KEY_ARROW_LEFT*/
  1, /*KEY_ARROW_DOWN*/
  0, /*KEY_UE*/
  1, /*KEY_P*/
  0, /*KEY_AE*/
  1, /*KEY_OE*/
  1, /*KEY_MINUS*/
  1, /*KEY_DOT*/
  0, /*KEY_DOLLAR*/
  0, /*KEY_QUESTIONMARK*/
  1, /*KEY_7*/
  1, /*KEY_9*/
  0, /*KEY_5*/
  1, /*KEY_0*/
  0, /*KEY_APOS*/
  0, /*KEY_6*/
  1, /*KEY_8*/
  0, /*KEY_4*/
  0, /*KEY_EURO*/
  0, /*KEY_CTRL_L*/
  0, /*KEY_CTRL_R*/
  1, /*KEY_O*/
  0, /*KEY_ASTERISK*/
  0, /*KEY_T*/
  1, /*KEY_U*/
  0, /*KEY_R*/
  0, /*KEY_W*/
  0, /*KEY_SHIFT_R*/
  0, /*KEY_SHIFT_L*/
  1, /*KEY_I*/
  0, /*KEY_ENTER*/
  0, /*KEY_H*/
  0, /*KEY_Z*/
  0, /*KEY_E*/
  0, /*KEY_S*/
  1, /*KEY_L*/
  1, /*KEY_K*/
  1, /*KEY_M*/
  0, /*KEY_COMMA*/
  0, /*KEY_SHARP*/
  0, /*KEY_END*/
  0, /*KEY_WIN_R*/
  0, /*KEY_G*/
  0, /*KEY_V*/
  0, /*KEY_SPACE*/
  0, /*KEY_C*/
  1, /*KEY_J*/
  0, /*KEY_N*/
  0, /*KEY_B*/
  0, /*KEY_F*/
  0, /*KEY_A*/
  0, /*KEY_D*/
  0, /*KEY_LOWER_THAN*/
  0, /*KEY_X*/
  0, /*KEY_WIN_L*/
  0, /*KEY_ALT_L*/
  0, /*KEY_ALT_R*/
  0, /*KEY_Y*/
  0, /*KEY_FN*/ //of course Fn is also just a button. And it does not influence itself
};

  /*This is the array that in a way, holds the labels of the Keys. If you got the cell content from the Matrix, this is the transformation to a human readable string,
    just to validate the keyboard decoder is doing the right things and the wiring is ok.
  */
const char* const HumanReadableDecoder[MATRIX_KEY_COUNT] PROGMEM =
{
	HR_KEY_F11
	,HR_KEY_F12
	,HR_KEY_F8
	,HR_KEY_Q
	,HR_KEY_F4
	,HR_KEY_F3
	,HR_KEY_F7
	,HR_KEY_1
	,HR_KEY_ESC
	,HR_KEY_CIRCUMFLEX
	,HR_KEY_F5
	,HR_KEY_TAB
	,HR_KEY_F1
	,HR_KEY_F2
	,HR_KEY_F6
	,HR_KEY_CAPS_LOCK
	,HR_KEY_F10
	,HR_KEY_F9
	,HR_KEY_BACKSPACE
	,HR_KEY_3
	,HR_KEY_2
	,HR_KEY_ARROW_UP
	,HR_KEY_BREAK
	,HR_KEY_PRINT
	,HR_KEY_INSERT
	,HR_KEY_DELETE
	,HR_KEY_HOME
	,HR_KEY_PAGE_UP
	,HR_KEY_PAGE_DOWN
	,HR_KEY_ARROW_RIGHT
	,HR_KEY_ARROW_LEFT
	,HR_KEY_ARROW_DOWN
	,HR_KEY_UE
	,HR_KEY_P
	,HR_KEY_AE
	,HR_KEY_OE
	,HR_KEY_MINUS
	,HR_KEY_DOT
	,HR_KEY_DOLLAR
	,HR_KEY_QUESTIONMARK
	,HR_KEY_7
	,HR_KEY_9
	,HR_KEY_5
	,HR_KEY_0
	,HR_KEY_APOS
	,HR_KEY_6
	,HR_KEY_8
	,HR_KEY_4
	,HR_KEY_EURO
	,HR_KEY_CTRL_L
	,HR_KEY_CTRL_R
	,HR_KEY_O
	,HR_KEY_ASTERISK
	,HR_KEY_T
	,HR_KEY_U
	,HR_KEY_R
	,HR_KEY_W
	,HR_KEY_SHIFT_R
	,HR_KEY_SHIFT_L
	,HR_KEY_I
	,HR_KEY_ENTER
	,HR_KEY_H
	,HR_KEY_Z
	,HR_KEY_E
	,HR_KEY_S
	,HR_KEY_L
	,HR_KEY_K
	,HR_KEY_M
	,HR_KEY_COMMA
	,HR_KEY_SHARP
	,HR_KEY_END
	,HR_KEY_WIN_R
	,HR_KEY_G
	,HR_KEY_V
	,HR_KEY_SPACE
	,HR_KEY_C
	,HR_KEY_J
	,HR_KEY_N
	,HR_KEY_B
	,HR_KEY_F
	,HR_KEY_A
	,HR_KEY_D
	,HR_KEY_LOWER_THAN
	,HR_KEY_X
	,HR_KEY_WIN_L
	,HR_KEY_ALT_L
	,HR_KEY_ALT_R
	,HR_KEY_Y
	,HR_KEY_FN
};

//Same idea as HumanReadableDecoder, but for the buttons influenced by Fn
const char* const HumanReadableDecoderWithFn[MATRIX_KEY_COUNT] PROGMEM =
{
	 HR_Fn_KEY_F11
	,HR_Fn_KEY_F12
	,HR_Fn_KEY_F8
	,HR_Fn_KEY_Q
	,HR_Fn_KEY_F4
	,HR_Fn_KEY_F3
	,HR_Fn_KEY_F7
	,HR_Fn_KEY_1
	,HR_Fn_KEY_ESC
	,HR_Fn_KEY_CIRCUMFLEX
	,HR_Fn_KEY_F5
	,HR_Fn_KEY_TAB
	,HR_Fn_KEY_F1
	,HR_Fn_KEY_F2
	,HR_Fn_KEY_F6
	,HR_Fn_KEY_CAPS_LOCK
	,HR_Fn_KEY_F10
	,HR_Fn_KEY_F9
	,HR_Fn_KEY_BACKSPACE
	,HR_Fn_KEY_3
	,HR_Fn_KEY_2
	,HR_Fn_KEY_ARROW_UP
	,HR_Fn_KEY_BREAK
	,HR_Fn_KEY_PRINT
	,HR_Fn_KEY_INSERT
	,HR_Fn_KEY_DELETE
	,HR_Fn_KEY_HOME
	,HR_Fn_KEY_PAGE_UP
	,HR_Fn_KEY_PAGE_DOWN
	,HR_Fn_KEY_ARROW_RIGHT
	,HR_Fn_KEY_ARROW_LEFT
	,HR_Fn_KEY_ARROW_DOWN
	,HR_Fn_KEY_UE
	,HR_Fn_KEY_P
	,HR_Fn_KEY_AE
	,HR_Fn_KEY_OE
	,HR_Fn_KEY_MINUS
	,HR_Fn_KEY_DOT
	,HR_Fn_KEY_DOLLAR
	,HR_Fn_KEY_QUESTIONMARK
	,HR_Fn_KEY_7
	,HR_Fn_KEY_9
	,HR_Fn_KEY_5
	,HR_Fn_KEY_0
	,HR_Fn_KEY_APOS
	,HR_Fn_KEY_6
	,HR_Fn_KEY_8
	,HR_Fn_KEY_4
	,HR_Fn_KEY_EURO
	,HR_Fn_KEY_CTRL_L
	,HR_Fn_KEY_CTRL_R
	,HR_Fn_KEY_O
	,HR_Fn_KEY_ASTERISK
	,HR_Fn_KEY_T
	,HR_Fn_KEY_U
	,HR_Fn_KEY_R
	,HR_Fn_KEY_W
	,HR_Fn_KEY_SHIFT_R
	,HR_Fn_KEY_SHIFT_L
	,HR_Fn_KEY_I
	,HR_Fn_KEY_ENTER
	,HR_Fn_KEY_H
	,HR_Fn_KEY_Z
	,HR_Fn_KEY_E
	,HR_Fn_KEY_S
	,HR_Fn_KEY_L
	,HR_Fn_KEY_K
	,HR_Fn_KEY_M
	,HR_Fn_KEY_COMMA
	,HR_Fn_KEY_SHARP
	,HR_Fn_KEY_END
	,HR_Fn_KEY_WIN_R
	,HR_Fn_KEY_G
	,HR_Fn_KEY_V
	,HR_Fn_KEY_SPACE
	,HR_Fn_KEY_C
	,HR_Fn_KEY_J
	,HR_Fn_KEY_N
	,HR_Fn_KEY_B
	,HR_Fn_KEY_F
	,HR_Fn_KEY_A
	,HR_Fn_KEY_D
	,HR_Fn_KEY_LOWER_THAN
	,HR_Fn_KEY_X
	,HR_Fn_KEY_WIN_L
	,HR_Fn_KEY_ALT_L
	,HR_Fn_KEY_ALT_R
	,HR_Fn_KEY_Y
	,HR_Fn_KEY_FN
};

//Each pressed button can be identified by electrical current that flows from one pin of the matrix pins to another pin of the matrix.
// At the end, a pair (PIN1, PIN2) describes how to identify tis button.
#define PIN1_KEY_F11  		   2
#define PIN1_KEY_F12  		   2
#define PIN1_KEY_F8  			   2
#define PIN1_KEY_Q  			   2
#define PIN1_KEY_F4  			   2
#define PIN1_KEY_F3  			   2
#define PIN1_KEY_F7  			   2
#define PIN1_KEY_1  			   2
#define PIN1_KEY_ESC  		   1
#define PIN1_KEY_CIRCUMFLEX  	   1
#define PIN1_KEY_F5  			   1
#define PIN1_KEY_TAB  		   1
#define PIN1_KEY_F1  			   1
#define PIN1_KEY_F2  			   1
#define PIN1_KEY_F6  			   1
#define PIN1_KEY_CAPS_LOCK   1
#define PIN1_KEY_F10  		     4
#define PIN1_KEY_F9  			     4
#define PIN1_KEY_BACKSPACE  	 4
#define PIN1_KEY_3  			     4
#define PIN1_KEY_2  			     4
#define PIN1_KEY_ARROW_UP  	   4
#define PIN1_KEY_PAUSE 		     4
#define PIN1_KEY_PRINT  		   4
#define PIN1_KEY_INSERT  		   3
#define PIN1_KEY_DELETE  		   3
#define PIN1_KEY_HOME  		     3
#define PIN1_KEY_PAGE_UP  	   3
#define PIN1_KEY_PAGE_DOWN  	 3
#define PIN1_KEY_ARROW_RIGHT   3
#define PIN1_KEY_ARROW_LEFT  	 3
#define PIN1_KEY_ARROW_DOWN  	 3
#define PIN1_KEY_UE  			     6
#define PIN1_KEY_P  			     6
#define PIN1_KEY_AE  			     6
#define PIN1_KEY_OE  			     6
#define PIN1_KEY_MINUS  		   6
#define PIN1_KEY_DOT  		     6
#define PIN1_KEY_DOLLAR  		   5
#define PIN1_KEY_QUESTIONMARK  5
#define PIN1_KEY_7  			     5
#define PIN1_KEY_9  			     5
#define PIN1_KEY_5  			     5
#define PIN1_KEY_0  			     8
#define PIN1_KEY_APOS  		     8
#define PIN1_KEY_6  			     8
#define PIN1_KEY_8  			     8
#define PIN1_KEY_4  			     8
#define PIN1_KEY_EURO  		     7
#define PIN1_KEY_CTRL_L  		   10
#define PIN1_KEY_CTRL_R  		   10
#define PIN1_KEY_O  			     9
#define PIN1_KEY_ASTERISK  	   9
#define PIN1_KEY_T  			     9
#define PIN1_KEY_U  			     9
#define PIN1_KEY_R  			     9
#define PIN1_KEY_W  			     9
#define PIN1_KEY_SHIFT_R  	   12
#define PIN1_KEY_SHIFT_L  	   12
#define PIN1_KEY_I  			     11
#define PIN1_KEY_ENTER  		   11
#define PIN1_KEY_H  			     11
#define PIN1_KEY_Z  			     11
#define PIN1_KEY_E  			     11
#define PIN1_KEY_S  			     11
#define PIN1_KEY_L  			     14
#define PIN1_KEY_K  			     14
#define PIN1_KEY_M  			     14
#define PIN1_KEY_COMMA  		   14
#define PIN1_KEY_SHARP  		   13
#define PIN1_KEY_END  		     13
#define PIN1_KEY_WIN_R  		   13
#define PIN1_KEY_G  			     16
#define PIN1_KEY_V  			     16
#define PIN1_KEY_SPACE  		   16
#define PIN1_KEY_C  			     16
#define PIN1_KEY_J  			     15
#define PIN1_KEY_N  			     15
#define PIN1_KEY_B  			     15
#define PIN1_KEY_F  			     18
#define PIN1_KEY_A  			     18
#define PIN1_KEY_D  			     17
#define PIN1_KEY_LOWER_THAN  	   17
#define PIN1_KEY_X  			     17
#define PIN1_KEY_WIN_L  		   20
#define PIN1_KEY_ALT_L  		   19
#define PIN1_KEY_ALT_R  		   19
#define PIN1_KEY_Y  			     22
#define PIN1_KEY_FN  			     21
#define PIN2_KEY_F11  		 5
#define PIN2_KEY_F12  		 8
#define PIN2_KEY_F8  			 9
#define PIN2_KEY_Q  			 11
#define PIN2_KEY_F4  			 18
#define PIN2_KEY_F3  			 22
#define PIN2_KEY_F7  			 24
#define PIN2_KEY_1  			 23
#define PIN2_KEY_ESC        5
#define PIN2_KEY_CIRCUMFLEX  	  8
#define PIN2_KEY_F5  			  9
#define PIN2_KEY_TAB  		  11
#define PIN2_KEY_F1  			  18
#define PIN2_KEY_F2  			  22
#define PIN2_KEY_F6  			  24
#define PIN2_KEY_CAPS_LOCK  23
#define PIN2_KEY_F10        5
#define PIN2_KEY_F9  			  8
#define PIN2_KEY_BACKSPACE  9
#define PIN2_KEY_3  			  11
#define PIN2_KEY_2  			  18
#define PIN2_KEY_ARROW_UP  	22
#define PIN2_KEY_PAUSE 		  24
#define PIN2_KEY_PRINT  		23
#define PIN2_KEY_INSERT  		5
#define PIN2_KEY_DELETE  		8
#define PIN2_KEY_HOME  		  9
#define PIN2_KEY_PAGE_UP  	11
#define PIN2_KEY_PAGE_DOWN  18
#define PIN2_KEY_ARROW_RIGHT   22
#define PIN2_KEY_ARROW_LEFT  	 24
#define PIN2_KEY_ARROW_DOWN  	 23
#define PIN2_KEY_UE  			  5
#define PIN2_KEY_P  			  8
#define PIN2_KEY_AE  			  9
#define PIN2_KEY_OE  			  11
#define PIN2_KEY_MINUS      18
#define PIN2_KEY_DOT  		  22
#define PIN2_KEY_DOLLAR  		    10
#define PIN2_KEY_QUESTIONMARK   14
#define PIN2_KEY_7  			      16
#define PIN2_KEY_9  			      15
#define PIN2_KEY_5  			      17
#define PIN2_KEY_0  			 14
#define PIN2_KEY_APOS  		 13
#define PIN2_KEY_6  			 16
#define PIN2_KEY_8  			 15
#define PIN2_KEY_4  			 17
#define PIN2_KEY_EURO  		  18
#define PIN2_KEY_CTRL_L  	  22
#define PIN2_KEY_CTRL_R  		24
#define PIN2_KEY_O  			  14
#define PIN2_KEY_ASTERISK  	13
#define PIN2_KEY_T  			  16
#define PIN2_KEY_U  			  15
#define PIN2_KEY_R  			  17
#define PIN2_KEY_W  			  21
#define PIN2_KEY_SHIFT_R  	18
#define PIN2_KEY_SHIFT_L  	22
#define PIN2_KEY_I  			  14
#define PIN2_KEY_ENTER  		13
#define PIN2_KEY_H  			  16
#define PIN2_KEY_Z  			  15
#define PIN2_KEY_E  			  17
#define PIN2_KEY_S  			  21
#define PIN2_KEY_L  			  18
#define PIN2_KEY_K  			  22
#define PIN2_KEY_M  			  24
#define PIN2_KEY_COMMA  		23
#define PIN2_KEY_SHARP  		18
#define PIN2_KEY_END  		  22
#define PIN2_KEY_WIN_R  		24
#define PIN2_KEY_G  			  18
#define PIN2_KEY_V  			  22
#define PIN2_KEY_SPACE  		24
#define PIN2_KEY_C  			  23
#define PIN2_KEY_J  			  18
#define PIN2_KEY_N  			  22
#define PIN2_KEY_B  			  23
#define PIN2_KEY_F  			  17
#define PIN2_KEY_A  			  21
#define PIN2_KEY_D  			  22
#define PIN2_KEY_LOWER_THAN  	24
#define PIN2_KEY_X  			  23
#define PIN2_KEY_WIN_L  		24
#define PIN2_KEY_ALT_L  		24
#define PIN2_KEY_ALT_R  		23
#define PIN2_KEY_Y  			  21
#define PIN2_KEY_FN  			  24

struct detect_pins
{
  uint8_t Pin1;
  uint8_t Pin2;
};

//An array of pairs of pins. The order here is the same as for the array of buttons.
const detect_pins MatrixPins[MATRIX_KEY_COUNT] =
{
  {PIN1_KEY_F11       		,PIN2_KEY_F11      },
  {PIN1_KEY_F12        		,PIN2_KEY_F12      },
  {PIN1_KEY_F8        		,PIN2_KEY_F8       },
  {PIN1_KEY_Q          		,PIN2_KEY_Q        },
  {PIN1_KEY_F4         		,PIN2_KEY_F4       },
  {PIN1_KEY_F3         		,PIN2_KEY_F3       },
  {PIN1_KEY_F7         		,PIN2_KEY_F7       },
  {PIN1_KEY_1          		,PIN2_KEY_1        },
  {PIN1_KEY_ESC        		,PIN2_KEY_ESC      },
  {PIN1_KEY_CIRCUMFLEX      		,PIN2_KEY_CIRCUMFLEX    },
  {PIN1_KEY_F5         		,PIN2_KEY_F5       },
  {PIN1_KEY_TAB        		,PIN2_KEY_TAB      },
  {PIN1_KEY_F1         		,PIN2_KEY_F1       },
  {PIN1_KEY_F2         		,PIN2_KEY_F2       },
  {PIN1_KEY_F6         		,PIN2_KEY_F6       },
  {PIN1_KEY_CAPS_LOCK   	,PIN2_KEY_CAPS_LOCK  },
  {PIN1_KEY_F10        		,PIN2_KEY_F10      },
  {PIN1_KEY_F9         		,PIN2_KEY_F9       },
  {PIN1_KEY_BACKSPACE   	,PIN2_KEY_BACKSPACE  },
  {PIN1_KEY_3          		,PIN2_KEY_3        },
  {PIN1_KEY_2          		,PIN2_KEY_2        },
  {PIN1_KEY_ARROW_UP    	,PIN2_KEY_ARROW_UP  },
  {PIN1_KEY_PAUSE     		,PIN2_KEY_PAUSE   },
  {PIN1_KEY_PRINT      		,PIN2_KEY_PRINT    },
  {PIN1_KEY_INSERT     		,PIN2_KEY_INSERT   },
  {PIN1_KEY_DELETE     		,PIN2_KEY_DELETE   },
  {PIN1_KEY_HOME       		,PIN2_KEY_HOME     },
  {PIN1_KEY_PAGE_UP    		,PIN2_KEY_PAGE_UP  },
  {PIN1_KEY_PAGE_DOWN   	,PIN2_KEY_PAGE_DOWN  },
  {PIN1_KEY_ARROW_RIGHT 	,PIN2_KEY_ARROW_RIGHT  },
  {PIN1_KEY_ARROW_LEFT  	,PIN2_KEY_ARROW_LEFT  },
  {PIN1_KEY_ARROW_DOWN  	,PIN2_KEY_ARROW_DOWN  },
  {PIN1_KEY_UE         		,PIN2_KEY_UE       },
  {PIN1_KEY_P          		,PIN2_KEY_P        },
  {PIN1_KEY_AE         		,PIN2_KEY_AE       },
  {PIN1_KEY_OE         		,PIN2_KEY_OE       },
  {PIN1_KEY_MINUS      		,PIN2_KEY_MINUS    },
  {PIN1_KEY_DOT        		,PIN2_KEY_DOT      },
  {PIN1_KEY_DOLLAR     		,PIN2_KEY_DOLLAR   },
  {PIN1_KEY_QUESTIONMARK    ,PIN2_KEY_QUESTIONMARK  },
  {PIN1_KEY_7          		,PIN2_KEY_7        },
  {PIN1_KEY_9          		,PIN2_KEY_9        },
  {PIN1_KEY_5          		,PIN2_KEY_5        },
  {PIN1_KEY_0          		,PIN2_KEY_0        },
  {PIN1_KEY_APOS       		,PIN2_KEY_APOS     },
  {PIN1_KEY_6          		,PIN2_KEY_6        },
  {PIN1_KEY_8          		,PIN2_KEY_8        },
  {PIN1_KEY_4          		,PIN2_KEY_4        },
  {PIN1_KEY_EURO       		,PIN2_KEY_EURO     },
  {PIN1_KEY_CTRL_L     		,PIN2_KEY_CTRL_L   },
  {PIN1_KEY_CTRL_R     		,PIN2_KEY_CTRL_R   },
  {PIN1_KEY_O          		,PIN2_KEY_O        },
  {PIN1_KEY_ASTERISK   		,PIN2_KEY_ASTERISK },
  {PIN1_KEY_T          		,PIN2_KEY_T        },
  {PIN1_KEY_U          		,PIN2_KEY_U        },
  {PIN1_KEY_R          		,PIN2_KEY_R        },
  {PIN1_KEY_W          		,PIN2_KEY_W        },
  {PIN1_KEY_SHIFT_R    		,PIN2_KEY_SHIFT_R  },
  {PIN1_KEY_SHIFT_L    		,PIN2_KEY_SHIFT_L  },
  {PIN1_KEY_I          		,PIN2_KEY_I        },
  {PIN1_KEY_ENTER      		,PIN2_KEY_ENTER    },
  {PIN1_KEY_H          		,PIN2_KEY_H        },
  {PIN1_KEY_Z          		,PIN2_KEY_Z        },
  {PIN1_KEY_E          		,PIN2_KEY_E        },
  {PIN1_KEY_S          		,PIN2_KEY_S        },
  {PIN1_KEY_L          		,PIN2_KEY_L        },
  {PIN1_KEY_K          		,PIN2_KEY_K        },
  {PIN1_KEY_M          		,PIN2_KEY_M        },
  {PIN1_KEY_COMMA      		,PIN2_KEY_COMMA    },
  {PIN1_KEY_SHARP      		,PIN2_KEY_SHARP    },
  {PIN1_KEY_END        		,PIN2_KEY_END      },
  {PIN1_KEY_WIN_R      		,PIN2_KEY_WIN_R    },
  {PIN1_KEY_G          		,PIN2_KEY_G        },
  {PIN1_KEY_V          		,PIN2_KEY_V        },
  {PIN1_KEY_SPACE      		,PIN2_KEY_SPACE    },
  {PIN1_KEY_C          		,PIN2_KEY_C        },
  {PIN1_KEY_J          		,PIN2_KEY_J        },
  {PIN1_KEY_N          		,PIN2_KEY_N        },
  {PIN1_KEY_B          		,PIN2_KEY_B        },
  {PIN1_KEY_F          		,PIN2_KEY_F        },
  {PIN1_KEY_A          		,PIN2_KEY_A        },
  {PIN1_KEY_D          		,PIN2_KEY_D        },
  {PIN1_KEY_LOWER_THAN    		,PIN2_KEY_LOWER_THAN  },
  {PIN1_KEY_X          		,PIN2_KEY_X        },
  {PIN1_KEY_WIN_L      		,PIN2_KEY_WIN_L    },
  {PIN1_KEY_ALT_L      		,PIN2_KEY_ALT_L    },
  {PIN1_KEY_ALT_R      		,PIN2_KEY_ALT_R    },
  {PIN1_KEY_Y          		,PIN2_KEY_Y        },
  {PIN1_KEY_FN         		,PIN2_KEY_FN		}
};

/*
Now the dealing with the PS/2 protocol
What happens in the code:
1. Arduino identifies a pressed or released button
2. The matching make- or break-code shall be identified.
3. Send/receive data telegrams via PS/2 interface
Part 1 can be done with the code above.
Part 3 can be done with PS2dev lib.
For Part 2, use the following code
*/
//Make codes
const uint8_t PROGMEM Ps2Make_F11[] =      		{Ps2Mk_F11};
const uint8_t PROGMEM Ps2Make_F12[] =      		{Ps2Mk_F12};
const uint8_t PROGMEM Ps2Make_F8[] =       		{Ps2Mk_F8};
const uint8_t PROGMEM Ps2Make_Q[] =      		{Ps2Mk_Q};
const uint8_t PROGMEM Ps2Make_F4[] =       		{Ps2Mk_F4};
const uint8_t PROGMEM Ps2Make_F3[] =       		{Ps2Mk_F3};
const uint8_t PROGMEM Ps2Make_F7[] =       		{Ps2Mk_F7};
const uint8_t PROGMEM Ps2Make_1[] =      		{Ps2Mk_1};
const uint8_t PROGMEM Ps2Make_ESC[] =      		{Ps2Mk_ESC};
const uint8_t PROGMEM Ps2Make_CIRCUMFLEX[] =       	{Ps2Mk_CIRCUMFLEX};
const uint8_t PROGMEM Ps2Make_F5[] =       		{Ps2Mk_F5};
const uint8_t PROGMEM Ps2Make_TAB[] =      		{Ps2Mk_TAB};
const uint8_t PROGMEM Ps2Make_F1[] =       		{Ps2Mk_F1};
const uint8_t PROGMEM Ps2Make_F2[] =       		{Ps2Mk_F2};
const uint8_t PROGMEM Ps2Make_F6[] =       		{Ps2Mk_F6};
const uint8_t PROGMEM Ps2Make_CAPS_LOCK[] =   	{Ps2Mk_CAPS_LOCK};
const uint8_t PROGMEM Ps2Make_F10[] =      		{Ps2Mk_F10};
const uint8_t PROGMEM Ps2Make_F9[] =       		{Ps2Mk_F9};
const uint8_t PROGMEM Ps2Make_BACKSPACE[] =  	{Ps2Mk_BACKSPACE};
const uint8_t PROGMEM Ps2Make_3[] =      		{Ps2Mk_3};
const uint8_t PROGMEM Ps2Make_2[] =      		{Ps2Mk_2};
const uint8_t PROGMEM Ps2Make_ARROW_UP[] =      {Ps2Mk_ARROW_UP};
const uint8_t PROGMEM Ps2Make_BREAK[] =      	{Ps2Mk_BREAK};
const uint8_t PROGMEM Ps2Make_PRINT[] =      	{Ps2Mk_PRINT};
const uint8_t PROGMEM Ps2Make_INSERT[] =      	{Ps2Mk_INSERT};
const uint8_t PROGMEM Ps2Make_DELETE[] =      	{Ps2Mk_DELETE};
const uint8_t PROGMEM Ps2Make_HOME[] =     		{Ps2Mk_HOME};
const uint8_t PROGMEM Ps2Make_PAGE_UP[] =     	{Ps2Mk_PAGE_UP};
const uint8_t PROGMEM Ps2Make_PAGE_DOWN[] =   	{Ps2Mk_PAGE_DOWN};
const uint8_t PROGMEM Ps2Make_ARROW_RIGHT[] =   {Ps2Mk_ARROW_RIGHT};
const uint8_t PROGMEM Ps2Make_ARROW_LEFT[] =    {Ps2Mk_ARROW_LEFT};
const uint8_t PROGMEM Ps2Make_ARROW_DOWN[] =    {Ps2Mk_ARROW_DOWN};
const uint8_t PROGMEM Ps2Make_UE[] =       		{Ps2Mk_UE};
const uint8_t PROGMEM Ps2Make_P[] =      		{Ps2Mk_P};
const uint8_t PROGMEM Ps2Make_AE[] =       		{Ps2Mk_AE};
const uint8_t PROGMEM Ps2Make_OE[] =       		{Ps2Mk_OE};
const uint8_t PROGMEM Ps2Make_MINUS[] =    		{Ps2Mk_MINUS};
const uint8_t PROGMEM Ps2Make_DOT[] =    		{Ps2Mk_DOT};
const uint8_t PROGMEM Ps2Make_DOLLAR[] =     	{ScanCodeDummy};;
const uint8_t PROGMEM Ps2Make_QUESTIONMARK[] =  {Ps2Mk_QUESTIONMARK};
const uint8_t PROGMEM Ps2Make_7[] =      		{Ps2Mk_7};
const uint8_t PROGMEM Ps2Make_9[] =      		{Ps2Mk_9};
const uint8_t PROGMEM Ps2Make_5[] =      		{Ps2Mk_5};
const uint8_t PROGMEM Ps2Make_0[] =      		{Ps2Mk_0};
const uint8_t PROGMEM Ps2Make_APOS[] =     		{Ps2Mk_APOS};
const uint8_t PROGMEM Ps2Make_6[] =      		{Ps2Mk_6};
const uint8_t PROGMEM Ps2Make_8[] =      		{Ps2Mk_8};
const uint8_t PROGMEM Ps2Make_4[] =      		{Ps2Mk_4};
const uint8_t PROGMEM Ps2Make_EURO[] =     		{ScanCodeDummy};;
const uint8_t PROGMEM Ps2Make_CTRL_L[] =      	{Ps2Mk_CTRL_L};
const uint8_t PROGMEM Ps2Make_CTRL_R[] =      	{Ps2Mk_CTRL_R};
const uint8_t PROGMEM Ps2Make_O[] =      		{Ps2Mk_O};
const uint8_t PROGMEM Ps2Make_ASTERISK[] =   	{Ps2Mk_ASTERISK};
const uint8_t PROGMEM Ps2Make_T[] =      		{Ps2Mk_T};
const uint8_t PROGMEM Ps2Make_U[] =      		{Ps2Mk_U};
const uint8_t PROGMEM Ps2Make_R[] =      		{Ps2Mk_R};
const uint8_t PROGMEM Ps2Make_W[] =      		{Ps2Mk_W};
const uint8_t PROGMEM Ps2Make_SHIFT_R[] =      	{Ps2Mk_SHIFT_R};
const uint8_t PROGMEM Ps2Make_SHIFT_L[] =      	{Ps2Mk_SHIFT_L};
const uint8_t PROGMEM Ps2Make_I[] =      		{Ps2Mk_I};
const uint8_t PROGMEM Ps2Make_ENTER[] =      	{Ps2Mk_ENTER};
const uint8_t PROGMEM Ps2Make_H[] =      		{Ps2Mk_H};
const uint8_t PROGMEM Ps2Make_Z[] =      		{Ps2Mk_Z};
const uint8_t PROGMEM Ps2Make_E[] =      		{Ps2Mk_E};
const uint8_t PROGMEM Ps2Make_S[] =      		{Ps2Mk_S};
const uint8_t PROGMEM Ps2Make_L[] =      		{Ps2Mk_L};
const uint8_t PROGMEM Ps2Make_K[] =      		{Ps2Mk_K};
const uint8_t PROGMEM Ps2Make_M[] =      		{Ps2Mk_M};
const uint8_t PROGMEM Ps2Make_COMMA[] =  		{Ps2Mk_COMMA};
const uint8_t PROGMEM Ps2Make_SHARP[] =    		{Ps2Mk_SHARP};
const uint8_t PROGMEM Ps2Make_END[] =      		{Ps2Mk_END};
const uint8_t PROGMEM Ps2Make_WIN_R[] =      	{Ps2Mk_WIN_R};
const uint8_t PROGMEM Ps2Make_G[] =      		{Ps2Mk_G};
const uint8_t PROGMEM Ps2Make_V[] =      		{Ps2Mk_V};
const uint8_t PROGMEM Ps2Make_SPACE[] =      	{Ps2Mk_SPACE};
const uint8_t PROGMEM Ps2Make_C[] =     		{Ps2Mk_C};
const uint8_t PROGMEM Ps2Make_J[] =      		{Ps2Mk_J};
const uint8_t PROGMEM Ps2Make_N[] =      		{Ps2Mk_N};
const uint8_t PROGMEM Ps2Make_B[] =      		{Ps2Mk_B};
const uint8_t PROGMEM Ps2Make_F[] =      		{Ps2Mk_F};
const uint8_t PROGMEM Ps2Make_A[] =      		{Ps2Mk_A};
const uint8_t PROGMEM Ps2Make_D[] =      		{Ps2Mk_D};
const uint8_t PROGMEM Ps2Make_LOWER_THAN[] =    	{Ps2Mk_LOWER_THAN};
const uint8_t PROGMEM Ps2Make_X[] =      		{Ps2Mk_X};
const uint8_t PROGMEM Ps2Make_WIN_L[] =      	{Ps2Mk_WIN_L};
const uint8_t PROGMEM Ps2Make_ALT_L[] =      	{Ps2Mk_ALT_L};
const uint8_t PROGMEM Ps2Make_ALT_R[] =      	{Ps2Mk_ALT_R};
const uint8_t PROGMEM Ps2Make_Y[] =     		{Ps2Mk_Y};
const uint8_t PROGMEM Ps2Make_FN[] =       		{ScanCodeDummy}; //
//Make code Byte counts
const uint8_t PROGMEM Ps2MakeBc_F11 =      		Ps2MkBc_F11;
const uint8_t PROGMEM Ps2MakeBc_F12 =      		Ps2MkBc_F12;
const uint8_t PROGMEM Ps2MakeBc_F8 =       		Ps2MkBc_F8;
const uint8_t PROGMEM Ps2MakeBc_Q =      		Ps2MkBc_Q;
const uint8_t PROGMEM Ps2MakeBc_F4 =       		Ps2MkBc_F4;
const uint8_t PROGMEM Ps2MakeBc_F3 =       		Ps2MkBc_F3;
const uint8_t PROGMEM Ps2MakeBc_F7 =       		Ps2MkBc_F7;
const uint8_t PROGMEM Ps2MakeBc_1 =      		Ps2MkBc_1;
const uint8_t PROGMEM Ps2MakeBc_ESC =      		Ps2MkBc_ESC;
const uint8_t PROGMEM Ps2MakeBc_CIRCUMFLEX =       	Ps2MkBc_CIRCUMFLEX;
const uint8_t PROGMEM Ps2MakeBc_F5 =       		Ps2MkBc_F5;
const uint8_t PROGMEM Ps2MakeBc_TAB =      		Ps2MkBc_TAB;
const uint8_t PROGMEM Ps2MakeBc_F1 =       		Ps2MkBc_F1;
const uint8_t PROGMEM Ps2MakeBc_F2 =       		Ps2MkBc_F2;
const uint8_t PROGMEM Ps2MakeBc_F6 =       		Ps2MkBc_F6;
const uint8_t PROGMEM Ps2MakeBc_CAPS_LOCK =   	Ps2MkBc_CAPS_LOCK;
const uint8_t PROGMEM Ps2MakeBc_F10 =      		Ps2MkBc_F10;
const uint8_t PROGMEM Ps2MakeBc_F9 =       		Ps2MkBc_F9;
const uint8_t PROGMEM Ps2MakeBc_BACKSPACE =  	Ps2MkBc_BACKSPACE;
const uint8_t PROGMEM Ps2MakeBc_3 =      		Ps2MkBc_3;
const uint8_t PROGMEM Ps2MakeBc_2 =      		Ps2MkBc_2;
const uint8_t PROGMEM Ps2MakeBc_ARROW_UP =      Ps2MkBc_ARROW_UP;
const uint8_t PROGMEM Ps2MakeBc_BREAK =      	Ps2MkBc_BREAK;
const uint8_t PROGMEM Ps2MakeBc_PRINT =      	Ps2MkBc_PRINT;
const uint8_t PROGMEM Ps2MakeBc_INSERT =      	Ps2MkBc_INSERT;
const uint8_t PROGMEM Ps2MakeBc_DELETE =      	Ps2MkBc_DELETE;
const uint8_t PROGMEM Ps2MakeBc_HOME =     		Ps2MkBc_HOME;
const uint8_t PROGMEM Ps2MakeBc_PAGE_UP =     	Ps2MkBc_PAGE_UP;
const uint8_t PROGMEM Ps2MakeBc_PAGE_DOWN =   	Ps2MkBc_PAGE_DOWN;
const uint8_t PROGMEM Ps2MakeBc_ARROW_RIGHT =   Ps2MkBc_ARROW_RIGHT;
const uint8_t PROGMEM Ps2MakeBc_ARROW_LEFT =    Ps2MkBc_ARROW_LEFT;
const uint8_t PROGMEM Ps2MakeBc_ARROW_DOWN =    Ps2MkBc_ARROW_DOWN;
const uint8_t PROGMEM Ps2MakeBc_UE =       		Ps2MkBc_UE;
const uint8_t PROGMEM Ps2MakeBc_P =      		Ps2MkBc_P;
const uint8_t PROGMEM Ps2MakeBc_AE =       		Ps2MkBc_AE;
const uint8_t PROGMEM Ps2MakeBc_OE =       		Ps2MkBc_OE;
const uint8_t PROGMEM Ps2MakeBc_MINUS =    		Ps2MkBc_MINUS;
const uint8_t PROGMEM Ps2MakeBc_DOT =    		Ps2MkBc_DOT;
const uint8_t PROGMEM Ps2MakeBc_DOLLAR =     	ScanCodeDummy;
const uint8_t PROGMEM Ps2MakeBc_QUESTIONMARK =  Ps2MkBc_QUESTIONMARK;
const uint8_t PROGMEM Ps2MakeBc_7 =      		Ps2MkBc_7;
const uint8_t PROGMEM Ps2MakeBc_9 =      		Ps2MkBc_9;
const uint8_t PROGMEM Ps2MakeBc_5 =      		Ps2MkBc_5;
const uint8_t PROGMEM Ps2MakeBc_0 =      		Ps2MkBc_0;
const uint8_t PROGMEM Ps2MakeBc_APOS =     		Ps2MkBc_APOS;
const uint8_t PROGMEM Ps2MakeBc_6 =      		Ps2MkBc_6;
const uint8_t PROGMEM Ps2MakeBc_8 =      		Ps2MkBc_8;
const uint8_t PROGMEM Ps2MakeBc_4 =      		Ps2MkBc_4;
const uint8_t PROGMEM Ps2MakeBc_EURO =     		ScanCodeDummy;
const uint8_t PROGMEM Ps2MakeBc_CTRL_L =      	Ps2MkBc_CTRL_L;
const uint8_t PROGMEM Ps2MakeBc_CTRL_R =      	Ps2MkBc_CTRL_R;
const uint8_t PROGMEM Ps2MakeBc_O =      		Ps2MkBc_O;
const uint8_t PROGMEM Ps2MakeBc_ASTERISK =   	Ps2MkBc_ASTERISK;
const uint8_t PROGMEM Ps2MakeBc_T =      		Ps2MkBc_T;
const uint8_t PROGMEM Ps2MakeBc_U =      		Ps2MkBc_U;
const uint8_t PROGMEM Ps2MakeBc_R =      		Ps2MkBc_R;
const uint8_t PROGMEM Ps2MakeBc_W =      		Ps2MkBc_W;
const uint8_t PROGMEM Ps2MakeBc_SHIFT_R =      	Ps2MkBc_SHIFT_R;
const uint8_t PROGMEM Ps2MakeBc_SHIFT_L =      	Ps2MkBc_SHIFT_L;
const uint8_t PROGMEM Ps2MakeBc_I =      		Ps2MkBc_I;
const uint8_t PROGMEM Ps2MakeBc_ENTER =      	Ps2MkBc_ENTER;
const uint8_t PROGMEM Ps2MakeBc_H =      		Ps2MkBc_H;
const uint8_t PROGMEM Ps2MakeBc_Z =      		Ps2MkBc_Z;
const uint8_t PROGMEM Ps2MakeBc_E =      		Ps2MkBc_E;
const uint8_t PROGMEM Ps2MakeBc_S =      		Ps2MkBc_S;
const uint8_t PROGMEM Ps2MakeBc_L =      		Ps2MkBc_L;
const uint8_t PROGMEM Ps2MakeBc_K =      		Ps2MkBc_K;
const uint8_t PROGMEM Ps2MakeBc_M =      		Ps2MkBc_M;
const uint8_t PROGMEM Ps2MakeBc_COMMA =  		Ps2MkBc_COMMA;
const uint8_t PROGMEM Ps2MakeBc_SHARP =    		Ps2MkBc_SHARP;
const uint8_t PROGMEM Ps2MakeBc_END =      		Ps2MkBc_END;
const uint8_t PROGMEM Ps2MakeBc_WIN_R =      	Ps2MkBc_WIN_R;
const uint8_t PROGMEM Ps2MakeBc_G =      		Ps2MkBc_G;
const uint8_t PROGMEM Ps2MakeBc_V =      		Ps2MkBc_V;
const uint8_t PROGMEM Ps2MakeBc_SPACE =      	Ps2MkBc_SPACE;
const uint8_t PROGMEM Ps2MakeBc_C =     		Ps2MkBc_C;
const uint8_t PROGMEM Ps2MakeBc_J =      		Ps2MkBc_J;
const uint8_t PROGMEM Ps2MakeBc_N =      		Ps2MkBc_N;
const uint8_t PROGMEM Ps2MakeBc_B =      		Ps2MkBc_B;
const uint8_t PROGMEM Ps2MakeBc_F =      		Ps2MkBc_F;
const uint8_t PROGMEM Ps2MakeBc_A =      		Ps2MkBc_A;
const uint8_t PROGMEM Ps2MakeBc_D =      		Ps2MkBc_D;
const uint8_t PROGMEM Ps2MakeBc_LOWER_THAN =    	Ps2MkBc_LOWER_THAN;
const uint8_t PROGMEM Ps2MakeBc_X =      		Ps2MkBc_X;
const uint8_t PROGMEM Ps2MakeBc_WIN_L =      	Ps2MkBc_WIN_L;
const uint8_t PROGMEM Ps2MakeBc_ALT_L =      	Ps2MkBc_ALT_L;
const uint8_t PROGMEM Ps2MakeBc_ALT_R =      	Ps2MkBc_ALT_R;
const uint8_t PROGMEM Ps2MakeBc_Y =     		Ps2MkBc_Y;
const uint8_t PROGMEM Ps2MakeBc_FN =       		ScanCodeDummy; //
// There are many buttons with a second meaning, combined with "Fn"
//Make codes for Fn
const uint8_t PROGMEM Ps2Make_Fn_F11[] 		= {Ps2Mk_NUM_LOCK};
const uint8_t PROGMEM Ps2Make_Fn_F12[] 		= {Ps2Mk_SCROLL_LOCK};
const uint8_t PROGMEM Ps2Make_Fn_F8[] 		= 		     			{ScanCodeDummy}; //"Speaker"};
const uint8_t PROGMEM Ps2Make_Fn_Q[] 		= 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_F4[] 		= {Ps2Mk_AcpiSleep};
const uint8_t PROGMEM Ps2Make_Fn_F3[] 		= {Ps2Mk_AcpiWake};
const uint8_t PROGMEM Ps2Make_Fn_F7[] 		= 		     			{ScanCodeDummy}; //"Touchpad"};
const uint8_t PROGMEM Ps2Make_Fn_1[] 		= 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_ESC[] 		= 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_CIRCUMFLEX[] 	=       				{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_F5[] 		=       				{ScanCodeDummy}; //"Display"};
const uint8_t PROGMEM Ps2Make_Fn_TAB[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_F1[] 		=       				{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_F2[] 		= {Ps2Mk_AcpiPower};
const uint8_t PROGMEM Ps2Make_Fn_F6[] 		= 		      			{ScanCodeDummy}; //"Backlight"};
const uint8_t PROGMEM Ps2Make_Fn_CAPS_LOCK[] =   					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_F10[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_F9[] 		=       				{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_BACKSPACE[] =  					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_3[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_2[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_ARROW_UP[] = {Ps2Mk_MmVolumeUp};
const uint8_t PROGMEM Ps2Make_Fn_BREAK[] 	= 			     		{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_PRINT[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_INSERT[] 	=    			  		{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_DELETE[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_HOME[] 	=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_PAGE_UP[] 	=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_PAGE_DOWN[] =   					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_ARROW_RIGHT[] =      				{ScanCodeDummy}; //"Display-"};
const uint8_t PROGMEM Ps2Make_Fn_ARROW_LEFT[] =      				{ScanCodeDummy}; //"Display+"};
const uint8_t PROGMEM Ps2Make_Fn_ARROW_DOWN[] = {Ps2Mk_MmVolumeDown};
const uint8_t PROGMEM Ps2Make_Fn_UE[] 		=   	    			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_P[] 		= {Ps2Mk_NUMPAD_MINUS};
const uint8_t PROGMEM Ps2Make_Fn_AE[] 		= 		      			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_OE[] 		= {Ps2Mk_NUMPAD_PLUS};
const uint8_t PROGMEM Ps2Make_Fn_MINUS[] 	= {Ps2Mk_NUMPAD_DIVIDE};
const uint8_t PROGMEM Ps2Make_Fn_DOT[] 		= {Ps2Mk_NUMPAD_COMMA};
const uint8_t PROGMEM Ps2Make_Fn_DOLLAR[] 	= 			    		{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_QUESTIONMARK[] =       			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_7[] 		= {Ps2Mk_NUMPAD_7};
const uint8_t PROGMEM Ps2Make_Fn_9[] 		= {Ps2Mk_NUMPAD_9};
const uint8_t PROGMEM Ps2Make_Fn_5[] 		= 		     			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_0[] 		= {Ps2Mk_NUMPAD_MULTI};
const uint8_t PROGMEM Ps2Make_Fn_APOS[] 	= 		    			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_6[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_8[] 		= {Ps2Mk_NUMPAD_8};
const uint8_t PROGMEM Ps2Make_Fn_4[] 		= 		     			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_EURO[] 	=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_CTRL_L[]	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_CTRL_R[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_O[] 		= {Ps2Mk_NUMPAD_6};
const uint8_t PROGMEM Ps2Make_Fn_ASTERISK[] = 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_T[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_U[] 		= {Ps2Mk_NUMPAD_4};
const uint8_t PROGMEM Ps2Make_Fn_R[] 		= 		     			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_W[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_SHIFT_R[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_SHIFT_L[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_I[] 		= {Ps2Mk_NUMPAD_5};
const uint8_t PROGMEM Ps2Make_Fn_ENTER[] 	= 			     		{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_H[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_Z[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_E[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_S[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_L[] 		= {Ps2Mk_NUMPAD_3};
const uint8_t PROGMEM Ps2Make_Fn_K[] 		= {Ps2Mk_NUMPAD_2};
const uint8_t PROGMEM Ps2Make_Fn_M[] 		= {Ps2Mk_NUMPAD_0};
const uint8_t PROGMEM Ps2Make_Fn_COMMA[] 	= 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_SHARP[] 	=    					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_END[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_WIN_R[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_G[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_V[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_SPACE[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_C[] 		=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_J[] 		= {Ps2Mk_NUMPAD_1};
const uint8_t PROGMEM Ps2Make_Fn_N[] 		= 		     			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_B[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_F[] 		=  		    			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_A[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_D[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_LOWER_THAN[]	=    					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_X[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_WIN_L[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_ALT_L[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_ALT_R[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_Y[] 		=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Make_Fn_FN[] 		=       				{ScanCodeDummy}; //
//Make codes byte count for Fn
const uint8_t PROGMEM Ps2MakeBc_Fn_F11 		= Ps2MkBc_NUM_LOCK;
const uint8_t PROGMEM Ps2MakeBc_Fn_F12 		= Ps2MkBc_SCROLL_LOCK;
const uint8_t PROGMEM Ps2MakeBc_Fn_F8 		= 		     			ScanCodeDummy; //"Speaker";
const uint8_t PROGMEM Ps2MakeBc_Fn_Q 		= 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_F4 		= Ps2MkBc_AcpiSleep;
const uint8_t PROGMEM Ps2MakeBc_Fn_F3 		= Ps2MkBc_AcpiWake;
const uint8_t PROGMEM Ps2MakeBc_Fn_F7 		= 		     			ScanCodeDummy; //"Touchpad";
const uint8_t PROGMEM Ps2MakeBc_Fn_1 		= 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_ESC 		= 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_CIRCUMFLEX 	=       				ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_F5 		=       				ScanCodeDummy; //"Display";
const uint8_t PROGMEM Ps2MakeBc_Fn_TAB 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_F1 		=       				ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_F2 		= Ps2MkBc_AcpiPower;
const uint8_t PROGMEM Ps2MakeBc_Fn_F6 		= 		      			ScanCodeDummy; //"Backlight";
const uint8_t PROGMEM Ps2MakeBc_Fn_CAPS_LOCK =   					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_F10 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_F9 		=       				ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_BACKSPACE =  					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_3 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_2 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_ARROW_UP = Ps2MkBc_MmVolumeUp;
const uint8_t PROGMEM Ps2MakeBc_Fn_BREAK 	= 			     		ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_PRINT 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_INSERT 	=    			  		ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_DELETE 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_HOME 	=     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_PAGE_UP 	=     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_PAGE_DOWN =   					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_ARROW_RIGHT =      				ScanCodeDummy; //"Display-";
const uint8_t PROGMEM Ps2MakeBc_Fn_ARROW_LEFT =      				ScanCodeDummy; //"Display+";
const uint8_t PROGMEM Ps2MakeBc_Fn_ARROW_DOWN = Ps2MkBc_MmVolumeDown;
const uint8_t PROGMEM Ps2MakeBc_Fn_UE 		=   	    			ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_P 		= Ps2MkBc_NUMPAD_MINUS;
const uint8_t PROGMEM Ps2MakeBc_Fn_AE 		= 		      			ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_OE 		= Ps2MkBc_NUMPAD_PLUS;
const uint8_t PROGMEM Ps2MakeBc_Fn_MINUS 	= Ps2MkBc_NUMPAD_DIVIDE;
const uint8_t PROGMEM Ps2MakeBc_Fn_DOT 		= Ps2MkBc_NUMPAD_COMMA;
const uint8_t PROGMEM Ps2MakeBc_Fn_DOLLAR 	= 			    		ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_QUESTIONMARK =       			ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_7 		= Ps2MkBc_NUMPAD_7;
const uint8_t PROGMEM Ps2MakeBc_Fn_9 		= Ps2MkBc_NUMPAD_9;
const uint8_t PROGMEM Ps2MakeBc_Fn_5 		= 		     			ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_0 		= Ps2MkBc_NUMPAD_MULTI;
const uint8_t PROGMEM Ps2MakeBc_Fn_APOS 	= 		    			ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_6 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_8 		= Ps2MkBc_NUMPAD_8;
const uint8_t PROGMEM Ps2MakeBc_Fn_4 		= 		     			ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_EURO 	=     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_CTRL_L	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_CTRL_R 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_O 		= Ps2MkBc_NUMPAD_6;
const uint8_t PROGMEM Ps2MakeBc_Fn_ASTERISK = 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_T 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_U 		= Ps2MkBc_NUMPAD_4;
const uint8_t PROGMEM Ps2MakeBc_Fn_R 		= 		     			ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_W 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_SHIFT_R 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_SHIFT_L 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_I 		= Ps2MkBc_NUMPAD_5;
const uint8_t PROGMEM Ps2MakeBc_Fn_ENTER 	= 			     		ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_H 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_Z 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_E 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_S 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_L 		= Ps2MkBc_NUMPAD_3;
const uint8_t PROGMEM Ps2MakeBc_Fn_K 		= Ps2MkBc_NUMPAD_2;
const uint8_t PROGMEM Ps2MakeBc_Fn_M 		= Ps2MkBc_NUMPAD_0;
const uint8_t PROGMEM Ps2MakeBc_Fn_COMMA 	= 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_SHARP 	=    					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_END 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_WIN_R 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_G 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_V 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_SPACE 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_C 		=     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_J 		= Ps2MkBc_NUMPAD_1;
const uint8_t PROGMEM Ps2MakeBc_Fn_N 		= 		     			ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_B 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_F 		=  		    			ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_A 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_D 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_LOWER_THAN	=    					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_X 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_WIN_L 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_ALT_L 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_ALT_R 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_Y 		=     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2MakeBc_Fn_FN 		=       				ScanCodeDummy; //
//Break codes
const uint8_t PROGMEM Ps2Break_F11[] =      		{Ps2Bk_F11};
const uint8_t PROGMEM Ps2Break_F12[] =      		{Ps2Bk_F12};
const uint8_t PROGMEM Ps2Break_F8[] =       		{Ps2Bk_F8};
const uint8_t PROGMEM Ps2Break_Q[] =      		{Ps2Bk_Q};
const uint8_t PROGMEM Ps2Break_F4[] =       		{Ps2Bk_F4};
const uint8_t PROGMEM Ps2Break_F3[] =       		{Ps2Bk_F3};
const uint8_t PROGMEM Ps2Break_F7[] =       		{Ps2Bk_F7};
const uint8_t PROGMEM Ps2Break_1[] =      		{Ps2Bk_1};
const uint8_t PROGMEM Ps2Break_ESC[] =      		{Ps2Bk_ESC};
const uint8_t PROGMEM Ps2Break_CIRCUMFLEX[] =       	{Ps2Bk_CIRCUMFLEX};
const uint8_t PROGMEM Ps2Break_F5[] =       		{Ps2Bk_F5};
const uint8_t PROGMEM Ps2Break_TAB[] =      		{Ps2Bk_TAB};
const uint8_t PROGMEM Ps2Break_F1[] =       		{Ps2Bk_F1};
const uint8_t PROGMEM Ps2Break_F2[] =       		{Ps2Bk_F2};
const uint8_t PROGMEM Ps2Break_F6[] =       		{Ps2Bk_F6};
const uint8_t PROGMEM Ps2Break_CAPS_LOCK[] =   	{Ps2Bk_CAPS_LOCK};
const uint8_t PROGMEM Ps2Break_F10[] =      		{Ps2Bk_F10};
const uint8_t PROGMEM Ps2Break_F9[] =       		{Ps2Bk_F9};
const uint8_t PROGMEM Ps2Break_BACKSPACE[] =  	{Ps2Bk_BACKSPACE};
const uint8_t PROGMEM Ps2Break_3[] =      		{Ps2Bk_3};
const uint8_t PROGMEM Ps2Break_2[] =      		{Ps2Bk_2};
const uint8_t PROGMEM Ps2Break_ARROW_UP[] =      {Ps2Bk_ARROW_UP};
const uint8_t PROGMEM Ps2Break_BREAK[] =      	{Ps2Bk_BREAK};
const uint8_t PROGMEM Ps2Break_PRINT[] =      	{Ps2Bk_PRINT};
const uint8_t PROGMEM Ps2Break_INSERT[] =      	{Ps2Bk_INSERT};
const uint8_t PROGMEM Ps2Break_DELETE[] =      	{Ps2Bk_DELETE};
const uint8_t PROGMEM Ps2Break_HOME[] =     		{Ps2Bk_HOME};
const uint8_t PROGMEM Ps2Break_PAGE_UP[] =     	{Ps2Bk_PAGE_UP};
const uint8_t PROGMEM Ps2Break_PAGE_DOWN[] =   	{Ps2Bk_PAGE_DOWN};
const uint8_t PROGMEM Ps2Break_ARROW_RIGHT[] =   {Ps2Bk_ARROW_RIGHT};
const uint8_t PROGMEM Ps2Break_ARROW_LEFT[] =    {Ps2Bk_ARROW_LEFT};
const uint8_t PROGMEM Ps2Break_ARROW_DOWN[] =    {Ps2Bk_ARROW_DOWN};
const uint8_t PROGMEM Ps2Break_UE[] =       		{Ps2Bk_UE};
const uint8_t PROGMEM Ps2Break_P[] =      		{Ps2Bk_P};
const uint8_t PROGMEM Ps2Break_AE[] =       		{Ps2Bk_AE};
const uint8_t PROGMEM Ps2Break_OE[] =       		{Ps2Bk_OE};
const uint8_t PROGMEM Ps2Break_MINUS[] =    		{Ps2Bk_MINUS};
const uint8_t PROGMEM Ps2Break_DOT[] =    		{Ps2Bk_DOT};
const uint8_t PROGMEM Ps2Break_DOLLAR[] =     	{ScanCodeDummy};;
const uint8_t PROGMEM Ps2Break_QUESTIONMARK[] =  {Ps2Bk_QUESTIONMARK};
const uint8_t PROGMEM Ps2Break_7[] =      		{Ps2Bk_7};
const uint8_t PROGMEM Ps2Break_9[] =      		{Ps2Bk_9};
const uint8_t PROGMEM Ps2Break_5[] =      		{Ps2Bk_5};
const uint8_t PROGMEM Ps2Break_0[] =      		{Ps2Bk_0};
const uint8_t PROGMEM Ps2Break_APOS[] =     		{Ps2Bk_APOS};
const uint8_t PROGMEM Ps2Break_6[] =      		{Ps2Bk_6};
const uint8_t PROGMEM Ps2Break_8[] =      		{Ps2Bk_8};
const uint8_t PROGMEM Ps2Break_4[] =      		{Ps2Bk_4};
const uint8_t PROGMEM Ps2Break_EURO[] =     		{ScanCodeDummy};;
const uint8_t PROGMEM Ps2Break_CTRL_L[] =      	{Ps2Bk_CTRL_L};
const uint8_t PROGMEM Ps2Break_CTRL_R[] =      	{Ps2Bk_CTRL_R};
const uint8_t PROGMEM Ps2Break_O[] =      		{Ps2Bk_O};
const uint8_t PROGMEM Ps2Break_ASTERISK[] =   	{Ps2Bk_ASTERISK};
const uint8_t PROGMEM Ps2Break_T[] =      		{Ps2Bk_T};
const uint8_t PROGMEM Ps2Break_U[] =      		{Ps2Bk_U};
const uint8_t PROGMEM Ps2Break_R[] =      		{Ps2Bk_R};
const uint8_t PROGMEM Ps2Break_W[] =      		{Ps2Bk_W};
const uint8_t PROGMEM Ps2Break_SHIFT_R[] =      	{Ps2Bk_SHIFT_R};
const uint8_t PROGMEM Ps2Break_SHIFT_L[] =      	{Ps2Bk_SHIFT_L};
const uint8_t PROGMEM Ps2Break_I[] =      		{Ps2Bk_I};
const uint8_t PROGMEM Ps2Break_ENTER[] =      	{Ps2Bk_ENTER};
const uint8_t PROGMEM Ps2Break_H[] =      		{Ps2Bk_H};
const uint8_t PROGMEM Ps2Break_Z[] =      		{Ps2Bk_Z};
const uint8_t PROGMEM Ps2Break_E[] =      		{Ps2Bk_E};
const uint8_t PROGMEM Ps2Break_S[] =      		{Ps2Bk_S};
const uint8_t PROGMEM Ps2Break_L[] =      		{Ps2Bk_L};
const uint8_t PROGMEM Ps2Break_K[] =      		{Ps2Bk_K};
const uint8_t PROGMEM Ps2Break_M[] =      		{Ps2Bk_M};
const uint8_t PROGMEM Ps2Break_COMMA[] =  		{Ps2Bk_COMMA};
const uint8_t PROGMEM Ps2Break_SHARP[] =    		{Ps2Bk_SHARP};
const uint8_t PROGMEM Ps2Break_END[] =      		{Ps2Bk_END};
const uint8_t PROGMEM Ps2Break_WIN_R[] =      	{Ps2Bk_WIN_R};
const uint8_t PROGMEM Ps2Break_G[] =      		{Ps2Bk_G};
const uint8_t PROGMEM Ps2Break_V[] =      		{Ps2Bk_V};
const uint8_t PROGMEM Ps2Break_SPACE[] =      	{Ps2Bk_SPACE};
const uint8_t PROGMEM Ps2Break_C[] =     		{Ps2Bk_C};
const uint8_t PROGMEM Ps2Break_J[] =      		{Ps2Bk_J};
const uint8_t PROGMEM Ps2Break_N[] =      		{Ps2Bk_N};
const uint8_t PROGMEM Ps2Break_B[] =      		{Ps2Bk_B};
const uint8_t PROGMEM Ps2Break_F[] =      		{Ps2Bk_F};
const uint8_t PROGMEM Ps2Break_A[] =      		{Ps2Bk_A};
const uint8_t PROGMEM Ps2Break_D[] =      		{Ps2Bk_D};
const uint8_t PROGMEM Ps2Break_LOWER_THAN[] =    	{Ps2Bk_LOWER_THAN};
const uint8_t PROGMEM Ps2Break_X[] =      		{Ps2Bk_X};
const uint8_t PROGMEM Ps2Break_WIN_L[] =      	{Ps2Bk_WIN_L};
const uint8_t PROGMEM Ps2Break_ALT_L[] =      	{Ps2Bk_ALT_L};
const uint8_t PROGMEM Ps2Break_ALT_R[] =      	{Ps2Bk_ALT_R};
const uint8_t PROGMEM Ps2Break_Y[] =     		{Ps2Bk_Y};
const char PROGMEM Ps2Break_FN[] =       		{ScanCodeDummy}; //
//Break codes byte count
//Make code Byte counts
const uint8_t PROGMEM Ps2BreakBc_F11 =      		Ps2BkBc_F11;
const uint8_t PROGMEM Ps2BreakBc_F12 =      		Ps2BkBc_F12;
const uint8_t PROGMEM Ps2BreakBc_F8 =       		Ps2BkBc_F8;
const uint8_t PROGMEM Ps2BreakBc_Q =      		Ps2BkBc_Q;
const uint8_t PROGMEM Ps2BreakBc_F4 =       		Ps2BkBc_F4;
const uint8_t PROGMEM Ps2BreakBc_F3 =       		Ps2BkBc_F3;
const uint8_t PROGMEM Ps2BreakBc_F7 =       		Ps2BkBc_F7;
const uint8_t PROGMEM Ps2BreakBc_1 =      		Ps2BkBc_1;
const uint8_t PROGMEM Ps2BreakBc_ESC =      		Ps2BkBc_ESC;
const uint8_t PROGMEM Ps2BreakBc_CIRCUMFLEX =       	Ps2BkBc_CIRCUMFLEX;
const uint8_t PROGMEM Ps2BreakBc_F5 =       		Ps2BkBc_F5;
const uint8_t PROGMEM Ps2BreakBc_TAB =      		Ps2BkBc_TAB;
const uint8_t PROGMEM Ps2BreakBc_F1 =       		Ps2BkBc_F1;
const uint8_t PROGMEM Ps2BreakBc_F2 =       		Ps2BkBc_F2;
const uint8_t PROGMEM Ps2BreakBc_F6 =       		Ps2BkBc_F6;
const uint8_t PROGMEM Ps2BreakBc_CAPS_LOCK =   	Ps2BkBc_CAPS_LOCK;
const uint8_t PROGMEM Ps2BreakBc_F10 =      		Ps2BkBc_F10;
const uint8_t PROGMEM Ps2BreakBc_F9 =       		Ps2BkBc_F9;
const uint8_t PROGMEM Ps2BreakBc_BACKSPACE =  	Ps2BkBc_BACKSPACE;
const uint8_t PROGMEM Ps2BreakBc_3 =      		Ps2BkBc_3;
const uint8_t PROGMEM Ps2BreakBc_2 =      		Ps2BkBc_2;
const uint8_t PROGMEM Ps2BreakBc_ARROW_UP =      Ps2BkBc_ARROW_UP;
const uint8_t PROGMEM Ps2BreakBc_BREAK =      	Ps2BkBc_BREAK;
const uint8_t PROGMEM Ps2BreakBc_PRINT =      	Ps2BkBc_PRINT;
const uint8_t PROGMEM Ps2BreakBc_INSERT =      	Ps2BkBc_INSERT;
const uint8_t PROGMEM Ps2BreakBc_DELETE =      	Ps2BkBc_DELETE;
const uint8_t PROGMEM Ps2BreakBc_HOME =     		Ps2BkBc_HOME;
const uint8_t PROGMEM Ps2BreakBc_PAGE_UP =     	Ps2BkBc_PAGE_UP;
const uint8_t PROGMEM Ps2BreakBc_PAGE_DOWN =   	Ps2BkBc_PAGE_DOWN;
const uint8_t PROGMEM Ps2BreakBc_ARROW_RIGHT =   Ps2BkBc_ARROW_RIGHT;
const uint8_t PROGMEM Ps2BreakBc_ARROW_LEFT =    Ps2BkBc_ARROW_LEFT;
const uint8_t PROGMEM Ps2BreakBc_ARROW_DOWN =    Ps2BkBc_ARROW_DOWN;
const uint8_t PROGMEM Ps2BreakBc_UE =       		Ps2BkBc_UE;
const uint8_t PROGMEM Ps2BreakBc_P =      		Ps2BkBc_P;
const uint8_t PROGMEM Ps2BreakBc_AE =       		Ps2BkBc_AE;
const uint8_t PROGMEM Ps2BreakBc_OE =       		Ps2BkBc_OE;
const uint8_t PROGMEM Ps2BreakBc_MINUS =    		Ps2BkBc_MINUS;
const uint8_t PROGMEM Ps2BreakBc_DOT =    		Ps2BkBc_DOT;
const uint8_t PROGMEM Ps2BreakBc_DOLLAR =     							ScanCodeDummy;
const uint8_t PROGMEM Ps2BreakBc_QUESTIONMARK =  Ps2BkBc_QUESTIONMARK;
const uint8_t PROGMEM Ps2BreakBc_7 =      		Ps2BkBc_7;
const uint8_t PROGMEM Ps2BreakBc_9 =      		Ps2BkBc_9;
const uint8_t PROGMEM Ps2BreakBc_5 =      		Ps2BkBc_5;
const uint8_t PROGMEM Ps2BreakBc_0 =      		Ps2BkBc_0;
const uint8_t PROGMEM Ps2BreakBc_APOS =     		Ps2BkBc_APOS;
const uint8_t PROGMEM Ps2BreakBc_6 =      		Ps2BkBc_6;
const uint8_t PROGMEM Ps2BreakBc_8 =      		Ps2BkBc_8;
const uint8_t PROGMEM Ps2BreakBc_4 =      		Ps2BkBc_4;
const uint8_t PROGMEM Ps2BreakBc_EURO =     							ScanCodeDummy;
const uint8_t PROGMEM Ps2BreakBc_CTRL_L =      	Ps2BkBc_CTRL_L;
const uint8_t PROGMEM Ps2BreakBc_CTRL_R =      	Ps2BkBc_CTRL_R;
const uint8_t PROGMEM Ps2BreakBc_O =      		Ps2BkBc_O;
const uint8_t PROGMEM Ps2BreakBc_ASTERISK =   	Ps2BkBc_ASTERISK;
const uint8_t PROGMEM Ps2BreakBc_T =      		Ps2BkBc_T;
const uint8_t PROGMEM Ps2BreakBc_U =      		Ps2BkBc_U;
const uint8_t PROGMEM Ps2BreakBc_R =      		Ps2BkBc_R;
const uint8_t PROGMEM Ps2BreakBc_W =      		Ps2BkBc_W;
const uint8_t PROGMEM Ps2BreakBc_SHIFT_R =      	Ps2BkBc_SHIFT_R;
const uint8_t PROGMEM Ps2BreakBc_SHIFT_L =      	Ps2BkBc_SHIFT_L;
const uint8_t PROGMEM Ps2BreakBc_I =      		Ps2BkBc_I;
const uint8_t PROGMEM Ps2BreakBc_ENTER =      	Ps2BkBc_ENTER;
const uint8_t PROGMEM Ps2BreakBc_H =      		Ps2BkBc_H;
const uint8_t PROGMEM Ps2BreakBc_Z =      		Ps2BkBc_Z;
const uint8_t PROGMEM Ps2BreakBc_E =      		Ps2BkBc_E;
const uint8_t PROGMEM Ps2BreakBc_S =      		Ps2BkBc_S;
const uint8_t PROGMEM Ps2BreakBc_L =      		Ps2BkBc_L;
const uint8_t PROGMEM Ps2BreakBc_K =      		Ps2BkBc_K;
const uint8_t PROGMEM Ps2BreakBc_M =      		Ps2BkBc_M;
const uint8_t PROGMEM Ps2BreakBc_COMMA =  		Ps2BkBc_COMMA;
const uint8_t PROGMEM Ps2BreakBc_SHARP =    		Ps2BkBc_SHARP;
const uint8_t PROGMEM Ps2BreakBc_END =      		Ps2BkBc_END;
const uint8_t PROGMEM Ps2BreakBc_WIN_R =      	Ps2BkBc_WIN_R;
const uint8_t PROGMEM Ps2BreakBc_G =      		Ps2BkBc_G;
const uint8_t PROGMEM Ps2BreakBc_V =      		Ps2BkBc_V;
const uint8_t PROGMEM Ps2BreakBc_SPACE =      	Ps2BkBc_SPACE;
const uint8_t PROGMEM Ps2BreakBc_C =     		Ps2BkBc_C;
const uint8_t PROGMEM Ps2BreakBc_J =      		Ps2BkBc_J;
const uint8_t PROGMEM Ps2BreakBc_N =      		Ps2BkBc_N;
const uint8_t PROGMEM Ps2BreakBc_B =      		Ps2BkBc_B;
const uint8_t PROGMEM Ps2BreakBc_F =      		Ps2BkBc_F;
const uint8_t PROGMEM Ps2BreakBc_A =      		Ps2BkBc_A;
const uint8_t PROGMEM Ps2BreakBc_D =      		Ps2BkBc_D;
const uint8_t PROGMEM Ps2BreakBc_LOWER_THAN =    	Ps2BkBc_LOWER_THAN;
const uint8_t PROGMEM Ps2BreakBc_X =      		Ps2BkBc_X;
const uint8_t PROGMEM Ps2BreakBc_WIN_L =      	Ps2BkBc_WIN_L;
const uint8_t PROGMEM Ps2BreakBc_ALT_L =      	Ps2BkBc_ALT_L;
const uint8_t PROGMEM Ps2BreakBc_ALT_R =      	Ps2BkBc_ALT_R;
const uint8_t PROGMEM Ps2BreakBc_Y =     		Ps2BkBc_Y;
const uint8_t PROGMEM Ps2BreakBc_FN =       							ScanCodeDummy; //
// There are many buttons with a second meaning, combined with "Fn"
//Break codes for Fn
const uint8_t PROGMEM Ps2Break_Fn_F11[] 		= {Ps2Bk_NUM_LOCK};
const uint8_t PROGMEM Ps2Break_Fn_F12[] 		= {Ps2Bk_SCROLL_LOCK};
const uint8_t PROGMEM Ps2Break_Fn_F8[] 		= 		     			{ScanCodeDummy}; //"Speaker"};
const uint8_t PROGMEM Ps2Break_Fn_Q[] 		= 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_F4[] 		= {Ps2Bk_AcpiSleep};
const uint8_t PROGMEM Ps2Break_Fn_F3[] 		= {Ps2Bk_AcpiWake};
const uint8_t PROGMEM Ps2Break_Fn_F7[] 		= 		     			{ScanCodeDummy}; //"Touchpad"};
const uint8_t PROGMEM Ps2Break_Fn_1[] 		= 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_ESC[] 		= 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_CIRCUMFLEX[] 	=       				{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_F5[] 		=       				{ScanCodeDummy}; //"Display"};
const uint8_t PROGMEM Ps2Break_Fn_TAB[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_F1[] 		=       				{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_F2[] 		= {Ps2Bk_AcpiPower};
const uint8_t PROGMEM Ps2Break_Fn_F6[] 		= 		      			{ScanCodeDummy}; //"Backlight"};
const uint8_t PROGMEM Ps2Break_Fn_CAPS_LOCK[] =   					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_F10[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_F9[] 		=       				{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_BACKSPACE[] =  					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_3[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_2[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_ARROW_UP[] = {Ps2Bk_MmVolumeUp};
const uint8_t PROGMEM Ps2Break_Fn_BREAK[] 	= 			     		{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_PRINT[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_INSERT[] 	=    			  		{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_DELETE[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_HOME[] 	=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_PAGE_UP[] 	=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_PAGE_DOWN[] =   					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_ARROW_RIGHT[] =      				{ScanCodeDummy}; //"Display-"};
const uint8_t PROGMEM Ps2Break_Fn_ARROW_LEFT[] =      				{ScanCodeDummy}; //"Display+"};
const uint8_t PROGMEM Ps2Break_Fn_ARROW_DOWN[] = {Ps2Bk_MmVolumeDown};
const uint8_t PROGMEM Ps2Break_Fn_UE[] 		=   	    			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_P[] 		= {Ps2Bk_NUMPAD_MINUS};
const uint8_t PROGMEM Ps2Break_Fn_AE[] 		= 		      			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_OE[] 		= {Ps2Bk_NUMPAD_PLUS};
const uint8_t PROGMEM Ps2Break_Fn_MINUS[] 	= {Ps2Bk_NUMPAD_DIVIDE};
const uint8_t PROGMEM Ps2Break_Fn_DOT[] 		= {Ps2Bk_NUMPAD_COMMA};
const uint8_t PROGMEM Ps2Break_Fn_DOLLAR[] 	= 			    		{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_QUESTIONMARK[] =       			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_7[] 		= {Ps2Bk_NUMPAD_7};
const uint8_t PROGMEM Ps2Break_Fn_9[] 		= {Ps2Bk_NUMPAD_9};
const uint8_t PROGMEM Ps2Break_Fn_5[] 		= 		     			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_0[] 		= {Ps2Bk_NUMPAD_MULTI};
const uint8_t PROGMEM Ps2Break_Fn_APOS[] 	= 		    			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_6[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_8[] 		= {Ps2Bk_NUMPAD_8};
const uint8_t PROGMEM Ps2Break_Fn_4[] 		= 		     			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_EURO[] 	=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_CTRL_L[]	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_CTRL_R[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_O[] 		= {Ps2Bk_NUMPAD_6};
const uint8_t PROGMEM Ps2Break_Fn_ASTERISK[] = 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_T[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_U[] 		= {Ps2Bk_NUMPAD_4};
const uint8_t PROGMEM Ps2Break_Fn_R[] 		= 		     			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_W[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_SHIFT_R[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_SHIFT_L[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_I[] 		= {Ps2Bk_NUMPAD_5};
const uint8_t PROGMEM Ps2Break_Fn_ENTER[] 	= 			     		{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_H[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_Z[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_E[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_S[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_L[] 		= {Ps2Bk_NUMPAD_3};
const uint8_t PROGMEM Ps2Break_Fn_K[] 		= {Ps2Bk_NUMPAD_2};
const uint8_t PROGMEM Ps2Break_Fn_M[] 		= {Ps2Bk_NUMPAD_0};
const uint8_t PROGMEM Ps2Break_Fn_COMMA[] 	= 						{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_SHARP[] 	=    					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_END[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_WIN_R[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_G[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_V[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_SPACE[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_C[] 		=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_J[] 		= {Ps2Bk_NUMPAD_1};
const uint8_t PROGMEM Ps2Break_Fn_N[] 		= 		     			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_B[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_F[] 		=  		    			{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_A[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_D[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_LOWER_THAN[]	=    					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_X[] 		=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_WIN_L[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_ALT_L[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_ALT_R[] 	=      					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_Y[] 		=     					{ScanCodeDummy}; //
const uint8_t PROGMEM Ps2Break_Fn_FN[] 		=       				{ScanCodeDummy}; //
//Break codes byte count for Fn
const uint8_t PROGMEM Ps2BreakBc_Fn_F11 		= Ps2BkBc_NUM_LOCK;
const uint8_t PROGMEM Ps2BreakBc_Fn_F12 		= Ps2BkBc_SCROLL_LOCK;
const uint8_t PROGMEM Ps2BreakBc_Fn_F8 		= 		     			ScanCodeDummy; //"Speaker";
const uint8_t PROGMEM Ps2BreakBc_Fn_Q 		= 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_F4 		= Ps2BkBc_AcpiSleep;
const uint8_t PROGMEM Ps2BreakBc_Fn_F3 		= Ps2BkBc_AcpiWake;
const uint8_t PROGMEM Ps2BreakBc_Fn_F7 		= 		     			ScanCodeDummy; //"Touchpad";
const uint8_t PROGMEM Ps2BreakBc_Fn_1 		= 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_ESC 		= 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_CIRCUMFLEX 	=       				ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_F5 		=       				ScanCodeDummy; //"Display";
const uint8_t PROGMEM Ps2BreakBc_Fn_TAB 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_F1 		=       				ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_F2 		= Ps2BkBc_AcpiPower;
const uint8_t PROGMEM Ps2BreakBc_Fn_F6 		= 		      			ScanCodeDummy; //"Backlight";
const uint8_t PROGMEM Ps2BreakBc_Fn_CAPS_LOCK =   					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_F10 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_F9 		=       				ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_BACKSPACE =  					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_3 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_2 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_ARROW_UP = Ps2BkBc_MmVolumeUp;
const uint8_t PROGMEM Ps2BreakBc_Fn_BREAK 	= 			     		ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_PRINT 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_INSERT 	=    			  		ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_DELETE 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_HOME 	=     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_PAGE_UP =     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_PAGE_DOWN =   					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_ARROW_RIGHT =      				ScanCodeDummy; //"Display-";
const uint8_t PROGMEM Ps2BreakBc_Fn_ARROW_LEFT =      				ScanCodeDummy; //"Display+";
const uint8_t PROGMEM Ps2BreakBc_Fn_ARROW_DOWN = Ps2BkBc_MmVolumeDown;
const uint8_t PROGMEM Ps2BreakBc_Fn_UE 		=   	    			ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_P 		= Ps2BkBc_NUMPAD_MINUS;
const uint8_t PROGMEM Ps2BreakBc_Fn_AE 		= 		      			ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_OE 		= Ps2BkBc_NUMPAD_PLUS;
const uint8_t PROGMEM Ps2BreakBc_Fn_MINUS 	= Ps2BkBc_NUMPAD_DIVIDE;
const uint8_t PROGMEM Ps2BreakBc_Fn_DOT 	= Ps2BkBc_NUMPAD_COMMA;
const uint8_t PROGMEM Ps2BreakBc_Fn_DOLLAR 	= 			    		ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_QUESTIONMARK =       			ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_7 		= Ps2BkBc_NUMPAD_7;
const uint8_t PROGMEM Ps2BreakBc_Fn_9 		= Ps2BkBc_NUMPAD_9;
const uint8_t PROGMEM Ps2BreakBc_Fn_5 		= 		     			ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_0 		= Ps2BkBc_NUMPAD_MULTI;
const uint8_t PROGMEM Ps2BreakBc_Fn_APOS 	= 		    			ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_6 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_8 		= Ps2BkBc_NUMPAD_8;
const uint8_t PROGMEM Ps2BreakBc_Fn_4 		= 		     			ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_EURO 	=     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_CTRL_L	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_CTRL_R 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_O 		= Ps2BkBc_NUMPAD_6;
const uint8_t PROGMEM Ps2BreakBc_Fn_ASTERISK = 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_T 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_U 		= Ps2BkBc_NUMPAD_4;
const uint8_t PROGMEM Ps2BreakBc_Fn_R 		= 		     			ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_W 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_SHIFT_R 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_SHIFT_L 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_I 		= Ps2BkBc_NUMPAD_5;
const uint8_t PROGMEM Ps2BreakBc_Fn_ENTER 	= 			     		ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_H 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_Z 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_E 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_S 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_L 		= Ps2BkBc_NUMPAD_3;
const uint8_t PROGMEM Ps2BreakBc_Fn_K 		= Ps2BkBc_NUMPAD_2;
const uint8_t PROGMEM Ps2BreakBc_Fn_M 		= Ps2BkBc_NUMPAD_0;
const uint8_t PROGMEM Ps2BreakBc_Fn_COMMA 	= 						ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_SHARP 	=    					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_END 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_WIN_R 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_G 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_V 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_SPACE 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_C 		=     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_J 		= Ps2BkBc_NUMPAD_1;
const uint8_t PROGMEM Ps2BreakBc_Fn_N 		= 		     			ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_B 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_F 		=  		    			ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_A 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_D 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_LOWER_THAN	=    					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_X 		=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_WIN_L 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_ALT_L 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_ALT_R 	=      					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_Y 		=     					ScanCodeDummy; //
const uint8_t PROGMEM Ps2BreakBc_Fn_FN 		=       				ScanCodeDummy; //

struct Ps2_CodeDetails
{
  uint8_t ByteCountMake;
  uint8_t ByteCountBreak;
  uint8_t Makecode[9];
  uint8_t Breakcode[8];
  uint8_t ByteCountMakeFn;
  uint8_t ByteCountBreakFn;
  uint8_t MakecodeFn[8];
  uint8_t BreakcodeFn[8];
};

//An easy way to deal with all that similar names
#define PS2AllDetails(BUTTONNAME) \
 Ps2MakeBc_##BUTTONNAME,\
Ps2BreakBc_##BUTTONNAME,\
   Ps2Make_##BUTTONNAME,\
  Ps2Break_##BUTTONNAME,\
\
 Ps2MakeBc_Fn_##BUTTONNAME,\
Ps2BreakBc_Fn_##BUTTONNAME,\
   Ps2Make_Fn_##BUTTONNAME,\
  Ps2Break_Fn_##BUTTONNAME
  
//The full feateared list of PS code details, same order as for finding the buttons.
const Ps2_CodeDetails  Ps2CodeCombo[MATRIX_KEY_COUNT] =
{
	 {PS2AllDetails(F11)}
	,{PS2AllDetails(F12)}
	,{PS2AllDetails(F8)}
	,{PS2AllDetails(Q)}
	,{PS2AllDetails(F4)}
	,{PS2AllDetails(F3)}
	,{PS2AllDetails(F7)}
	,{PS2AllDetails(1)}
	,{PS2AllDetails(ESC)}
	,{PS2AllDetails(CIRCUMFLEX)}
	,{PS2AllDetails(F5)}
	,{PS2AllDetails(TAB)}
	,{PS2AllDetails(F1)}
	,{PS2AllDetails(F2)}
	,{PS2AllDetails(F6)}
	,{PS2AllDetails(CAPS_LOCK)}
	,{PS2AllDetails(F10)}
	,{PS2AllDetails(F9)}
	,{PS2AllDetails(BACKSPACE)}
	,{PS2AllDetails(3)}
	,{PS2AllDetails(2)}
	,{PS2AllDetails(ARROW_UP)}
	,{PS2AllDetails(BREAK)}
	,{PS2AllDetails(PRINT)}
	,{PS2AllDetails(INSERT)}
	,{PS2AllDetails(DELETE)}
	,{PS2AllDetails(HOME)}
	,{PS2AllDetails(PAGE_UP)}
	,{PS2AllDetails(PAGE_DOWN)}
	,{PS2AllDetails(ARROW_RIGHT)}
	,{PS2AllDetails(ARROW_LEFT)}
	,{PS2AllDetails(ARROW_DOWN)}
	,{PS2AllDetails(UE)}
	,{PS2AllDetails(P)}
	,{PS2AllDetails(AE)}
	,{PS2AllDetails(OE)}
	,{PS2AllDetails(MINUS)}
	,{PS2AllDetails(DOT)}
	,{PS2AllDetails(DOLLAR)}
	,{PS2AllDetails(QUESTIONMARK)}
	,{PS2AllDetails(7)}
	,{PS2AllDetails(9)}
	,{PS2AllDetails(5)}
	,{PS2AllDetails(0)}
	,{PS2AllDetails(APOS)}
	,{PS2AllDetails(6)}
	,{PS2AllDetails(8)}
	,{PS2AllDetails(4)}
	,{PS2AllDetails(EURO)}
	,{PS2AllDetails(CTRL_L)}
	,{PS2AllDetails(CTRL_R)}
	,{PS2AllDetails(O)}
	,{PS2AllDetails(ASTERISK)}
	,{PS2AllDetails(T)}
	,{PS2AllDetails(U)}
	,{PS2AllDetails(R)}
	,{PS2AllDetails(W)}
	,{PS2AllDetails(SHIFT_R)}
	,{PS2AllDetails(SHIFT_L)}
	,{PS2AllDetails(I)}
	,{PS2AllDetails(ENTER)}
	,{PS2AllDetails(H)}
	,{PS2AllDetails(Z)}
	,{PS2AllDetails(E)}
	,{PS2AllDetails(S)}
	,{PS2AllDetails(L)}
	,{PS2AllDetails(K)}
	,{PS2AllDetails(M)}
	,{PS2AllDetails(COMMA)}
	,{PS2AllDetails(SHARP)}
	,{PS2AllDetails(END)}
	,{PS2AllDetails(WIN_R)}
	,{PS2AllDetails(G)}
	,{PS2AllDetails(V)}
	,{PS2AllDetails(SPACE)}
	,{PS2AllDetails(C)}
	,{PS2AllDetails(J)}
	,{PS2AllDetails(N)}
	,{PS2AllDetails(B)}
	,{PS2AllDetails(F)}
	,{PS2AllDetails(A)}
	,{PS2AllDetails(D)}
	,{PS2AllDetails(LOWER_THAN)}
	,{PS2AllDetails(X)}
	,{PS2AllDetails(WIN_L)}
	,{PS2AllDetails(ALT_L)}
	,{PS2AllDetails(ALT_R)}
	,{PS2AllDetails(Y)}
	,{PS2AllDetails(FN)}

};

/*end of file*/