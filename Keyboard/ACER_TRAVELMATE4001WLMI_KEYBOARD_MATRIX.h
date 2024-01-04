/*
 * 2021-12-01
 * 
 * Target System: Arduino Mega2560
 * Arduino IDE: 1.8.14
 * 
*/


#define KBD_PINCOUNT 24
#define KBD_REAL_KEY_COUNT 89 //0 is the unknown key, the other 89 keys are known

#define STD_KEY 0
#define FN_COMPOSED_KEY 1

#define KBD_TESTTIME 50 //ms

//unique names and unique numbers for all electrical buttons. Numbers are used as index to iterate over all buttons
//They are in a useful order that allows to set ranges to iterate through

// Just a number that is not used
#define KBD_KEY_UNDEFINED 255

//Fn Key
#define KBD_KEY_FN   			0 //This is the only key that has no PS/2 scancodes

//Fn-dependent keys
#define KBD_KEY_F2  				1  //Fn + F2  =  ACPI Power
#define KBD_KEY_F3  				2  //Fn + F3  =  ACPI Wake
#define KBD_KEY_F4  				3  //Fn + F4  =  ACPI Sleep
#define KBD_KEY_F5  				4  //Fn + F5  =  Toggle between internal, external and both displays
#define KBD_KEY_F6  				5  //Fn + F6  =  Turn backlight off to save power
#define KBD_KEY_F7  				6  //Fn + F7  =  Toggle Touchpad
#define KBD_KEY_F8  				7  //Fn + F8  =  Mute Speakers
#define KBD_KEY_ARROW_RIGHT  		8  //Fn + right = Brightness up
#define KBD_KEY_ARROW_LEFT  		9  //Fn + left  = Brightness down
#define KBD_KEY_ARROW_DOWN 			10 //Fn + down  = Volume down  
#define KBD_KEY_ARROW_UP  			11 //Fn + up    = Volume up
#define KBD_KEY_F11 				12 //Fn + F11 =  turn on NumLock
#define KBD_KEY_F12 				13 //Fn + F12 =  turn on ScrollLock

	#define KBD_FN_DEPENDENT_START_INDEX KBD_KEY_F2
	#define KBD_FN_DEPENDENT_END_INDEX KBD_KEY_F12

//Note: The "overlayed numpad" can be activated via Fn+Numlock. But from there, Fn is no longer required to be active.
//Which PS2 code is send for these blue marked buttons does not depend on Fn but on the status of the Numlock LED.
//So, these are Numlock LED dependent keys. Numlock keys have their own code, not just a copy of the usual scan codes.
#define KBD_KEY_7  				14  // If NumLock LED is active, Code is NUMLOCK 7
#define KBD_KEY_9 				15  // If NumLock LED is active, Code is NUMLOCK 8
#define KBD_KEY_8  				16  // If NumLock LED is active, Code is NUMLOCK 9
#define KBD_KEY_0  				17  // If NumLock LED is active, Code is NUMLOCK *
#define KBD_KEY_U  				18  // If NumLock LED is active, Code is NUMLOCK 4
#define KBD_KEY_I  				19  // If NumLock LED is active, Code is NUMLOCK 5
#define KBD_KEY_O  				20  // If NumLock LED is active, Code is NUMLOCK 6
#define KBD_KEY_P  				21  // If NumLock LED is active, Code is NUMLOCK -
#define KBD_KEY_J  				22  // If NumLock LED is active, Code is NUMLOCK 1
#define KBD_KEY_K  				23  // If NumLock LED is active, Code is NUMLOCK 2
#define KBD_KEY_L  				24  // If NumLock LED is active, Code is NUMLOCK 3
#define KBD_KEY_OE   			25  // If NumLock LED is active, Code is NUMLOCK +
#define KBD_KEY_M  				26  // If NumLock LED is active, Code is NUMLOCK 0
#define KBD_KEY_DOT  			27  // If NumLock LED is active, Code is NUMLOCK ,
#define KBD_KEY_MINUS  			28  // If NumLock LED is active, Code is NUMLOCK /

	#define KBD_KBD_NUMLOCK_DEPENDENT_END_INDEX KBD_KEY_7
	#define NUMLOCK_DEPENDENT_END_INDEX  KBD_KEY_MINUS 			

//These buttons have no special sideffects for our code. They are simply buttons.
#define KBD_KEY_CAPS_LOCK 		29 // Turn on Capslock. Does not influence any PS2 code
#define KBD_KEY_CTRL_L  			30 
#define KBD_KEY_CTRL_R  			31 
#define KBD_KEY_ALT_L  			32 
#define KBD_KEY_ALT_R  			33 
#define KBD_KEY_SHIFT_L  		34 
#define KBD_KEY_SHIFT_R  		35 
#define KBD_KEY_WIN_L  			36 
#define KBD_KEY_WIN_R  			37 
#define KBD_KEY_F1  				38 
#define KBD_KEY_F9  				39 
#define KBD_KEY_F10 				40 
#define KBD_KEY_Q 				41 
#define KBD_KEY_1 				42 
#define KBD_KEY_ESC				43 
#define KBD_KEY_CIRCUMFLEX  		44 
#define KBD_KEY_TAB 				45 
#define KBD_KEY_BACKSPACE 		46 
#define KBD_KEY_3  				47 
#define KBD_KEY_2  				48 
#define KBD_KEY_INSERT  			49 
#define KBD_KEY_DELETE  			50 
#define KBD_KEY_HOME 			51 
#define KBD_KEY_PAGE_UP 			52 
#define KBD_KEY_PAGE_DOWN  		53 
#define KBD_KEY_UE  				54 
#define KBD_KEY_AE  				55 
#define KBD_KEY_QUESTIONMARK  	56 
#define KBD_KEY_5  				57 
#define KBD_KEY_APOS  			58 
#define KBD_KEY_6  				59 
#define KBD_KEY_4  				60 
#define KBD_KEY_ASTERISK   		61 
#define KBD_KEY_T 				62 
#define KBD_KEY_R  				63 
#define KBD_KEY_W  				64 
#define KBD_KEY_ENTER  			65 
#define KBD_KEY_H  				66 
#define KBD_KEY_Z  				67 
#define KBD_KEY_E  				68 
#define KBD_KEY_S  				69 
#define KBD_KEY_COMMA  			70 
#define KBD_KEY_SHARP  			71 
#define KBD_KEY_END  			72 
#define KBD_KEY_G  				73 
#define KBD_KEY_V  				74 
#define KBD_KEY_SPACE  			75 
#define KBD_KEY_C  				76 
#define KBD_KEY_N  				77 
#define KBD_KEY_B  				78 
#define KBD_KEY_F  				79 
#define KBD_KEY_A  				80 
#define KBD_KEY_D  				81 
#define KBD_KEY_LOWER_THAN  		82 
#define KBD_KEY_X  				83 
#define KBD_KEY_Y  				84 

	#define KBD_SIMPLEBUTTON_START_INDEX KBD_KEY_CAPS_LOCK
	#define KBD_SIMPLEBUTTON_END_INDEX KBD_KEY_Y

//These buttons have unusual long make- or breakcodes
#define KBD_KEY_PRINT  			85 
#define KBD_KEY_BREAK 			86 
	#define KBD_LONG_SCANCODE_START_INDEX KBD_KEY_PRINT
	#define KBD_LONG_SCANCODE_END_INDEX KBD_KEY_BREAK

//These buttons are a shortcut for a two button combination
#define KBD_KEY_DOLLAR   		87 // KBD_KEY_SHIFT_L + KBD_KEY_4
#define KBD_KEY_EURO   			88 // KBD_KEY_ALT_R + KBD_KEY_E
	#define KBD_MACROBUTTON_START_INDEX KBD_KEY_DOLLAR
	#define KBD_MACROBUTTON_END_INDEX KBD_KEY_EURO

//#######Important!##########
//This is the end of the button scan range. There are only 89 buttons in real life, so we scan for these 89 only.
//This number is available via KBD_REAL_KEY_COUNT
//The following buttons are virtual and exist only as PS/2 scan codes details. 
//These "virtual buttons" become active if special circumstances occur: Button "Fn" is active or NumLock LED is active.

//Fn-dependend keys if Fn is active
#define KBD_FN_VIRTKEY_F2  				89  //Fn + F2  =  ACPI Power
#define KBD_FN_VIRTKEY_F3  				90  //Fn + F3  =  ACPI Wake
#define KBD_FN_VIRTKEY_F4  				91  //Fn + F4  =  ACPI Sleep
#define KBD_FN_VIRTKEY_F5  				92  //Fn + F5  =  Toggle between internal, external and both displays
#define KBD_FN_VIRTKEY_F6  				93  //Fn + F6  =  Turn backlight off to save power
#define KBD_FN_VIRTKEY_F7  				94  //Fn + F7  =  Toggle Touchpad
#define KBD_FN_VIRTKEY_F8  				95  //Fn + F8  =  Mute Speakers
#define KBD_FN_VIRTKEY_ARROW_RIGHT  		96  //Fn + right = Brightness up
#define KBD_FN_VIRTKEY_ARROW_LEFT  		97  //Fn + left  = Brightness down
#define KBD_FN_VIRTKEY_ARROW_DOWN 		98  //Fn + down  = Volume down  
#define KBD_FN_VIRTKEY_ARROW_UP  		99  //Fn + up    = Volume up
#define KBD_FN_VIRTKEY_F11 				100 //Fn + F11 =  turn on NumLock
#define KBD_FN_VIRTKEY_F12 				101 //Fn + F12 =  turn on ScrollLock

#define KBD_FN_ACTIVATED_OFFSET  KBD_FN_VIRTKEY_F2 - KBD_FN_DEPENDENT_START_INDEX	// 89 - 1


//Num-Lock dependend Keys if Numlock is active
#define KBD_NUMLOCK_VIRTKEY_7  					102  // If NumLock LED is active, Code is NUMLOCK 7
#define KBD_NUMLOCK_VIRTKEY_9 					103  // If NumLock LED is active, Code is NUMLOCK 8
#define KBD_NUMLOCK_VIRTKEY_8  					104  // If NumLock LED is active, Code is NUMLOCK 9
#define KBD_NUMLOCK_VIRTKEY_0  					105  // If NumLock LED is active, Code is NUMLOCK *
#define KBD_NUMLOCK_VIRTKEY_U  					106  // If NumLock LED is active, Code is NUMLOCK 4
#define KBD_NUMLOCK_VIRTKEY_I  					107  // If NumLock LED is active, Code is NUMLOCK 5
#define KBD_NUMLOCK_VIRTKEY_O  					108  // If NumLock LED is active, Code is NUMLOCK 6
#define KBD_NUMLOCK_VIRTKEY_P  					109  // If NumLock LED is active, Code is NUMLOCK -
#define KBD_NUMLOCK_VIRTKEY_J  					110  // If NumLock LED is active, Code is NUMLOCK 1
#define KBD_NUMLOCK_VIRTKEY_K  					111  // If NumLock LED is active, Code is NUMLOCK 2
#define KBD_NUMLOCK_VIRTKEY_L  					112  // If NumLock LED is active, Code is NUMLOCK 3
#define KBD_NUMLOCK_VIRTKEY_OE   				113  // If NumLock LED is active, Code is NUMLOCK +
#define KBD_NUMLOCK_VIRTKEY_M  					114  // If NumLock LED is active, Code is NUMLOCK 0
#define KBD_NUMLOCK_VIRTKEY_DOT  				115  // If NumLock LED is active, Code is NUMLOCK ,
#define KBD_NUMLOCK_VIRTKEY_MINUS  				116  // If NumLock LED is active, Code is NUMLOCK /

#define KBD_NUMLOCK_ACTIVATED_OFFSET  KBD_NUMLOCK_VIRTKEY_7 - KBD_KBD_NUMLOCK_DEPENDENT_END_INDEX	//102 - 14

#define KBD_VIRT_KEY_COUNT 28 //117 - 89


#ifdef KBD_DEBUG
//These are the human readable "names" of the keys. Useful for debug, useless for the working keyboard

const char PROGMEM HR_KEY_F11[] =      			"F11"                 ;
const char PROGMEM HR_KEY_F12[] =      			"F12"                 ;
const char PROGMEM HR_KEY_F8[] =       			"F8"                  ;
const char PROGMEM HR_KEY_Q[] =      				"Q"               ;
const char PROGMEM HR_KEY_F4[] =       			"F4"                  ;
const char PROGMEM HR_KEY_F3[] =       			"F3"                  ;
const char PROGMEM HR_KEY_F7[] =       			"F7"                  ;
const char PROGMEM HR_KEY_1[] =      				"1"               ;
const char PROGMEM HR_KEY_ESC[] =      			"ESC"                 ;
const char PROGMEM HR_KEY_CIRCUMFLEX[] =       			"^"               ;
const char PROGMEM HR_KEY_F5[] =       			"F5"                  ;
const char PROGMEM HR_KEY_TAB[] =      			"Tab"                 ;
const char PROGMEM HR_KEY_F1[] =       			"F1"                  ;
const char PROGMEM HR_KEY_F2[] =       			"F2"                  ;
const char PROGMEM HR_KEY_F6[] =       			"F6"                  ;
const char PROGMEM HR_KEY_CAPS_LOCK[] =   			"CAPS_LOCK"       ;
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


  /*This is the array that in a way holds the labels of the Keys. If you got the cell content from the Matrix, this is the transformation to a human readable string, just to see
    the keyboard decoder is doing the right things and the wiring is ok.  
  */
const char* const HumanReadableDecoder[KBD_REAL_KEY_COUNT] PROGMEM =
{
HR_KEY_FN   		
,HR_KEY_F2  		
,HR_KEY_F3  		
,HR_KEY_F4  		
,HR_KEY_F5  		
,HR_KEY_F6  		
,HR_KEY_F7  		
,HR_KEY_F8  		
,HR_KEY_ARROW_RIGHT 
,HR_KEY_ARROW_LEFT  
,HR_KEY_ARROW_DOWN 	
,HR_KEY_ARROW_UP  	
,HR_KEY_F11 		
,HR_KEY_F12 		
,HR_KEY_7  			
,HR_KEY_9 			
,HR_KEY_8  			
,HR_KEY_0  			
,HR_KEY_U  			
,HR_KEY_I  			
,HR_KEY_O  			
,HR_KEY_P  			
,HR_KEY_J  			
,HR_KEY_K  			
,HR_KEY_L  			
,HR_KEY_OE   		
,HR_KEY_M  			
,HR_KEY_DOT  		
,HR_KEY_MINUS  		
,HR_KEY_CAPS_LOCK 	
,HR_KEY_CTRL_L  	
,HR_KEY_CTRL_R  	
,HR_KEY_ALT_L  		
,HR_KEY_ALT_R  		
,HR_KEY_SHIFT_L  	
,HR_KEY_SHIFT_R  	
,HR_KEY_WIN_L  		
,HR_KEY_WIN_R  		
,HR_KEY_F1  		
,HR_KEY_F9  		
,HR_KEY_F10 		
,HR_KEY_Q 			
,HR_KEY_1 			
,HR_KEY_ESC			
,HR_KEY_CIRCUMFLEX  
,HR_KEY_TAB 		
,HR_KEY_BACKSPACE 	
,HR_KEY_3  			
,HR_KEY_2  			
,HR_KEY_INSERT  	
,HR_KEY_DELETE  	
,HR_KEY_HOME 		
,HR_KEY_PAGE_UP 	
,HR_KEY_PAGE_DOWN  	
,HR_KEY_UE  		
,HR_KEY_AE  		
,HR_KEY_QUESTIONMARK
,HR_KEY_5  			
,HR_KEY_APOS  		
,HR_KEY_6  			
,HR_KEY_4  			
,HR_KEY_ASTERISK   	
,HR_KEY_T 			
,HR_KEY_R  			
,HR_KEY_W  			
,HR_KEY_ENTER  		
,HR_KEY_H  			
,HR_KEY_Z  			
,HR_KEY_E  			
,HR_KEY_S  			
,HR_KEY_COMMA  		
,HR_KEY_SHARP  		
,HR_KEY_END  		
,HR_KEY_G  			
,HR_KEY_V  			
,HR_KEY_SPACE  		
,HR_KEY_C  			
,HR_KEY_N  			
,HR_KEY_B  			
,HR_KEY_F  			
,HR_KEY_A  			
,HR_KEY_D  			
,HR_KEY_LOWER_THAN  
,HR_KEY_X  			
,HR_KEY_Y  			
,HR_KEY_PRINT  		
,HR_KEY_BREAK 		
,HR_KEY_DOLLAR   	
,HR_KEY_EURO
};

#endif //KBD_DEBUG

/*
Each key of the keyboard matrix can be identified by a pair of pins (Pin1, Pin2). Set a certain signal on Pin1, 
press the button and you will read the signal at Pin2 as long as the button is pressed.
No other Pin is influenced and no other button will cause this effect.

The numbering is not based on any numbers used by Arduino. It is just 1...n
*/

#define KBD_PIN1_KEY_F11  		 2
#define KBD_PIN1_KEY_F12  		 2
#define KBD_PIN1_KEY_F8  			 2
#define KBD_PIN1_KEY_Q  			 2
#define KBD_PIN1_KEY_F4  			 2
#define KBD_PIN1_KEY_F3  			 2
#define KBD_PIN1_KEY_F7  			 2
#define KBD_PIN1_KEY_1  			 2

#define KBD_PIN1_KEY_ESC  		 1
#define KBD_PIN1_KEY_CIRCUMFLEX  		 1
#define KBD_PIN1_KEY_F5  			 1
#define KBD_PIN1_KEY_TAB  		 1
#define KBD_PIN1_KEY_F1  			 1
#define KBD_PIN1_KEY_F2  			 1
#define KBD_PIN1_KEY_F6  			 1
#define KBD_PIN1_KEY_CAPS_LOCK  	 1

#define KBD_PIN1_KEY_F10  		 4
#define KBD_PIN1_KEY_F9  			 4
#define KBD_PIN1_KEY_BACKSPACE  	 4
#define KBD_PIN1_KEY_3  			 4
#define KBD_PIN1_KEY_2  			 4
#define KBD_PIN1_KEY_ARROW_UP  	 4
#define KBD_PIN1_KEY_BREAK 		 4
#define KBD_PIN1_KEY_PRINT  		 4

#define KBD_PIN1_KEY_INSERT  		 3
#define KBD_PIN1_KEY_DELETE  		 3
#define KBD_PIN1_KEY_HOME  		 3
#define KBD_PIN1_KEY_PAGE_UP  	 3
#define KBD_PIN1_KEY_PAGE_DOWN  	 3
#define KBD_PIN1_KEY_ARROW_RIGHT   3
#define KBD_PIN1_KEY_ARROW_LEFT  	 3
#define KBD_PIN1_KEY_ARROW_DOWN  	 3

#define KBD_PIN1_KEY_UE  			 6
#define KBD_PIN1_KEY_P  			 6
#define KBD_PIN1_KEY_AE  			 6
#define KBD_PIN1_KEY_OE  			 6
#define KBD_PIN1_KEY_MINUS  		 6
#define KBD_PIN1_KEY_DOT  		 6

#define KBD_PIN1_KEY_DOLLAR  		 5
#define KBD_PIN1_KEY_QUESTIONMARK  5
#define KBD_PIN1_KEY_7  			 5
#define KBD_PIN1_KEY_9  			 5
#define KBD_PIN1_KEY_5  			 5

#define KBD_PIN1_KEY_0  			 8
#define KBD_PIN1_KEY_APOS  		 8
#define KBD_PIN1_KEY_6  			 8
#define KBD_PIN1_KEY_8  			 8
#define KBD_PIN1_KEY_4  			 8

#define KBD_PIN1_KEY_EURO  		 7

#define KBD_PIN1_KEY_CTRL_L  		 10
#define KBD_PIN1_KEY_CTRL_R  		 10

#define KBD_PIN1_KEY_O  			 9
#define KBD_PIN1_KEY_ASTERISK  	 9
#define KBD_PIN1_KEY_T  			 9
#define KBD_PIN1_KEY_U  			 9
#define KBD_PIN1_KEY_R  			 9
#define KBD_PIN1_KEY_W  			 9

#define KBD_PIN1_KEY_SHIFT_R  	 12
#define KBD_PIN1_KEY_SHIFT_L  	 12

#define KBD_PIN1_KEY_I  			 11
#define KBD_PIN1_KEY_ENTER  		 11
#define KBD_PIN1_KEY_H  			 11
#define KBD_PIN1_KEY_Z  			 11
#define KBD_PIN1_KEY_E  			 11
#define KBD_PIN1_KEY_S  			 11

#define KBD_PIN1_KEY_L  			 14
#define KBD_PIN1_KEY_K  			 14
#define KBD_PIN1_KEY_M  			 14
#define KBD_PIN1_KEY_COMMA  		 14

#define KBD_PIN1_KEY_SHARP  		 13
#define KBD_PIN1_KEY_END  		 13
#define KBD_PIN1_KEY_WIN_R  		 13

#define KBD_PIN1_KEY_G  			 16
#define KBD_PIN1_KEY_V  			 16
#define KBD_PIN1_KEY_SPACE  		 16
#define KBD_PIN1_KEY_C  			 16

#define KBD_PIN1_KEY_J  			 15
#define KBD_PIN1_KEY_N  			 15
#define KBD_PIN1_KEY_B  			 15

#define KBD_PIN1_KEY_F  			 18
#define KBD_PIN1_KEY_A  			 18

#define KBD_PIN1_KEY_D  			 17
#define KBD_PIN1_KEY_LOWER_THAN  	 17
#define KBD_PIN1_KEY_X  			 17

#define KBD_PIN1_KEY_WIN_L  		 20

#define KBD_PIN1_KEY_ALT_L  		 19
#define KBD_PIN1_KEY_ALT_R  		 19

#define KBD_PIN1_KEY_Y  			 22

#define KBD_PIN1_KEY_FN  			 21

#define KBD_PIN2_KEY_F11  		 5  
#define KBD_PIN2_KEY_F12  		 8 
#define KBD_PIN2_KEY_F8  			 9 
#define KBD_PIN2_KEY_Q  			 11 
#define KBD_PIN2_KEY_F4  			 18 
#define KBD_PIN2_KEY_F3  			 22 
#define KBD_PIN2_KEY_F7  			 24 
#define KBD_PIN2_KEY_1  			 23
 
#define KBD_PIN2_KEY_ESC  		 5  
#define KBD_PIN2_KEY_CIRCUMFLEX  		 8  
#define KBD_PIN2_KEY_F5  			 9 
#define KBD_PIN2_KEY_TAB  		 11
#define KBD_PIN2_KEY_F1  			 18
#define KBD_PIN2_KEY_F2  			 22
#define KBD_PIN2_KEY_F6  			 24
#define KBD_PIN2_KEY_CAPS_LOCK  	 23

#define KBD_PIN2_KEY_F10  		 5 
#define KBD_PIN2_KEY_F9  			 8 
#define KBD_PIN2_KEY_BACKSPACE  	 9
#define KBD_PIN2_KEY_3  			 11
#define KBD_PIN2_KEY_2  			 18
#define KBD_PIN2_KEY_ARROW_UP  	 22
#define KBD_PIN2_KEY_BREAK 		 24
#define KBD_PIN2_KEY_PRINT  		 23

#define KBD_PIN2_KEY_INSERT  		 5 
#define KBD_PIN2_KEY_DELETE  		 8 
#define KBD_PIN2_KEY_HOME  		 9
#define KBD_PIN2_KEY_PAGE_UP  	 11
#define KBD_PIN2_KEY_PAGE_DOWN  	 18
#define KBD_PIN2_KEY_ARROW_RIGHT   22
#define KBD_PIN2_KEY_ARROW_LEFT  	 24
#define KBD_PIN2_KEY_ARROW_DOWN  	 23

#define KBD_PIN2_KEY_UE  			 5 
#define KBD_PIN2_KEY_P  			 8 
#define KBD_PIN2_KEY_AE  			 9	
#define KBD_PIN2_KEY_OE  			 11
#define KBD_PIN2_KEY_MINUS  		 18
#define KBD_PIN2_KEY_DOT  		 22

#define KBD_PIN2_KEY_DOLLAR  		 10
#define KBD_PIN2_KEY_QUESTIONMARK  14
#define KBD_PIN2_KEY_7  			 16
#define KBD_PIN2_KEY_9  			 15
#define KBD_PIN2_KEY_5  			 17

#define KBD_PIN2_KEY_0  			 14
#define KBD_PIN2_KEY_APOS  		 13
#define KBD_PIN2_KEY_6  			 16
#define KBD_PIN2_KEY_8  			 15
#define KBD_PIN2_KEY_4  			 17

#define KBD_PIN2_KEY_EURO  		 18
#define KBD_PIN2_KEY_CTRL_R  		 22
#define KBD_PIN2_KEY_CTRL_L  		 24

#define KBD_PIN2_KEY_O  			 14
#define KBD_PIN2_KEY_ASTERISK  	 13
#define KBD_PIN2_KEY_T  			 16
#define KBD_PIN2_KEY_U  			 15
#define KBD_PIN2_KEY_R  			 17
#define KBD_PIN2_KEY_W  			 21

#define KBD_PIN2_KEY_SHIFT_R  	 18
#define KBD_PIN2_KEY_SHIFT_L  	 22

#define KBD_PIN2_KEY_I  			 14
#define KBD_PIN2_KEY_ENTER  		 13
#define KBD_PIN2_KEY_H  			 16
#define KBD_PIN2_KEY_Z  			 15
#define KBD_PIN2_KEY_E  			 17
#define KBD_PIN2_KEY_S  			 21

#define KBD_PIN2_KEY_L  			 18
#define KBD_PIN2_KEY_K  			 22
#define KBD_PIN2_KEY_M  			 24
#define KBD_PIN2_KEY_COMMA  		 23

#define KBD_PIN2_KEY_SHARP  		 18
#define KBD_PIN2_KEY_END  		 22
#define KBD_PIN2_KEY_WIN_R  		 24

#define KBD_PIN2_KEY_G  			 18
#define KBD_PIN2_KEY_V  			 22
#define KBD_PIN2_KEY_SPACE  		 24
#define KBD_PIN2_KEY_C  			 23

#define KBD_PIN2_KEY_J  			 18
#define KBD_PIN2_KEY_N  			 22
#define KBD_PIN2_KEY_B  			 23

#define KBD_PIN2_KEY_F  			 17
#define KBD_PIN2_KEY_A  			 21

#define KBD_PIN2_KEY_D  			 22
#define KBD_PIN2_KEY_LOWER_THAN  	 24
#define KBD_PIN2_KEY_X  			 23

#define KBD_PIN2_KEY_WIN_L  		 24

#define KBD_PIN2_KEY_ALT_L  		 24
#define KBD_PIN2_KEY_ALT_R  		 23

#define KBD_PIN2_KEY_Y  			 21
#define KBD_PIN2_KEY_FN  			 24



struct detect_pins
{
  uint8_t Pin1;
  uint8_t Pin2;
};

const detect_pins MatrixPins[KBD_REAL_KEY_COUNT] =
{
	{KBD_PIN1_KEY_FN               ,KBD_PIN2_KEY_FN                 },
	{KBD_PIN1_KEY_F2               ,KBD_PIN2_KEY_F2                 },
	{KBD_PIN1_KEY_F3               ,KBD_PIN2_KEY_F3                 },
	{KBD_PIN1_KEY_F4               ,KBD_PIN2_KEY_F4                 },
	{KBD_PIN1_KEY_F5               ,KBD_PIN2_KEY_F5                 },
	{KBD_PIN1_KEY_F6               ,KBD_PIN2_KEY_F6                 },
	{KBD_PIN1_KEY_F7               ,KBD_PIN2_KEY_F7                 },
	{KBD_PIN1_KEY_F8               ,KBD_PIN2_KEY_F8                 },
	{KBD_PIN1_KEY_ARROW_RIGHT      ,KBD_PIN2_KEY_ARROW_RIGHT        },
	{KBD_PIN1_KEY_ARROW_LEFT       ,KBD_PIN2_KEY_ARROW_LEFT         },
	{KBD_PIN1_KEY_ARROW_DOWN       ,KBD_PIN2_KEY_ARROW_DOWN         },
	{KBD_PIN1_KEY_ARROW_UP         ,KBD_PIN2_KEY_ARROW_UP           },
	{KBD_PIN1_KEY_F11              ,KBD_PIN2_KEY_F11                },
	{KBD_PIN1_KEY_F12              ,KBD_PIN2_KEY_F12                },
	{KBD_PIN1_KEY_7                ,KBD_PIN2_KEY_7                  },
	{KBD_PIN1_KEY_9                ,KBD_PIN2_KEY_9                  },
	{KBD_PIN1_KEY_8                ,KBD_PIN2_KEY_8                  },
	{KBD_PIN1_KEY_0                ,KBD_PIN2_KEY_0                  },
	{KBD_PIN1_KEY_U                ,KBD_PIN2_KEY_U                  },
	{KBD_PIN1_KEY_I                ,KBD_PIN2_KEY_I                  },
	{KBD_PIN1_KEY_O                ,KBD_PIN2_KEY_O                  },
	{KBD_PIN1_KEY_P                ,KBD_PIN2_KEY_P                  },
	{KBD_PIN1_KEY_J                ,KBD_PIN2_KEY_J                  },
	{KBD_PIN1_KEY_K                ,KBD_PIN2_KEY_K                  },
	{KBD_PIN1_KEY_L                ,KBD_PIN2_KEY_L                  },
	{KBD_PIN1_KEY_OE               ,KBD_PIN2_KEY_OE                 },
	{KBD_PIN1_KEY_M                ,KBD_PIN2_KEY_M                  },
	{KBD_PIN1_KEY_DOT              ,KBD_PIN2_KEY_DOT                },
	{KBD_PIN1_KEY_MINUS            ,KBD_PIN2_KEY_MINUS              },
	{KBD_PIN1_KEY_CAPS_LOCK        ,KBD_PIN2_KEY_CAPS_LOCK          },
	{KBD_PIN1_KEY_CTRL_L           ,KBD_PIN2_KEY_CTRL_L             },
	{KBD_PIN1_KEY_CTRL_R           ,KBD_PIN2_KEY_CTRL_R             },
	{KBD_PIN1_KEY_ALT_L            ,KBD_PIN2_KEY_ALT_L              },
	{KBD_PIN1_KEY_ALT_R            ,KBD_PIN2_KEY_ALT_R              },
	{KBD_PIN1_KEY_SHIFT_L          ,KBD_PIN2_KEY_SHIFT_L            },
	{KBD_PIN1_KEY_SHIFT_R          ,KBD_PIN2_KEY_SHIFT_R            },
	{KBD_PIN1_KEY_WIN_L            ,KBD_PIN2_KEY_WIN_L              },
	{KBD_PIN1_KEY_WIN_R            ,KBD_PIN2_KEY_WIN_R              },
	{KBD_PIN1_KEY_F1               ,KBD_PIN2_KEY_F1                 },
	{KBD_PIN1_KEY_F9               ,KBD_PIN2_KEY_F9                 },
	{KBD_PIN1_KEY_F10              ,KBD_PIN2_KEY_F10                },
	{KBD_PIN1_KEY_Q                ,KBD_PIN2_KEY_Q                  },
	{KBD_PIN1_KEY_1                ,KBD_PIN2_KEY_1                  },
	{KBD_PIN1_KEY_ESC              ,KBD_PIN2_KEY_ESC                },
	{KBD_PIN1_KEY_CIRCUMFLEX       ,KBD_PIN2_KEY_CIRCUMFLEX         },
	{KBD_PIN1_KEY_TAB              ,KBD_PIN2_KEY_TAB                },
	{KBD_PIN1_KEY_BACKSPACE        ,KBD_PIN2_KEY_BACKSPACE          },
	{KBD_PIN1_KEY_3                ,KBD_PIN2_KEY_3                  },
	{KBD_PIN1_KEY_2                ,KBD_PIN2_KEY_2                  },
	{KBD_PIN1_KEY_INSERT           ,KBD_PIN2_KEY_INSERT             },
	{KBD_PIN1_KEY_DELETE           ,KBD_PIN2_KEY_DELETE             },
	{KBD_PIN1_KEY_HOME             ,KBD_PIN2_KEY_HOME               },
	{KBD_PIN1_KEY_PAGE_UP          ,KBD_PIN2_KEY_PAGE_UP            },
	{KBD_PIN1_KEY_PAGE_DOWN        ,KBD_PIN2_KEY_PAGE_DOWN          },
	{KBD_PIN1_KEY_UE               ,KBD_PIN2_KEY_UE                 },
	{KBD_PIN1_KEY_AE               ,KBD_PIN2_KEY_AE                 },
	{KBD_PIN1_KEY_QUESTIONMARK     ,KBD_PIN2_KEY_QUESTIONMARK       },
	{KBD_PIN1_KEY_5                ,KBD_PIN2_KEY_5                  },
	{KBD_PIN1_KEY_APOS             ,KBD_PIN2_KEY_APOS               },
	{KBD_PIN1_KEY_6                ,KBD_PIN2_KEY_6                  },
	{KBD_PIN1_KEY_4                ,KBD_PIN2_KEY_4                  },
	{KBD_PIN1_KEY_ASTERISK         ,KBD_PIN2_KEY_ASTERISK           },
	{KBD_PIN1_KEY_T                ,KBD_PIN2_KEY_T                  },
	{KBD_PIN1_KEY_R                ,KBD_PIN2_KEY_R                  },
	{KBD_PIN1_KEY_W                ,KBD_PIN2_KEY_W                  },
	{KBD_PIN1_KEY_ENTER            ,KBD_PIN2_KEY_ENTER              },
	{KBD_PIN1_KEY_H                ,KBD_PIN2_KEY_H                  },
	{KBD_PIN1_KEY_Z                ,KBD_PIN2_KEY_Z                  },
	{KBD_PIN1_KEY_E                ,KBD_PIN2_KEY_E                  },
	{KBD_PIN1_KEY_S                ,KBD_PIN2_KEY_S                  },
	{KBD_PIN1_KEY_COMMA            ,KBD_PIN2_KEY_COMMA              },
	{KBD_PIN1_KEY_SHARP            ,KBD_PIN2_KEY_SHARP              },
	{KBD_PIN1_KEY_END              ,KBD_PIN2_KEY_END                },
	{KBD_PIN1_KEY_G                ,KBD_PIN2_KEY_G                  },
	{KBD_PIN1_KEY_V                ,KBD_PIN2_KEY_V                  },
	{KBD_PIN1_KEY_SPACE            ,KBD_PIN2_KEY_SPACE              },
	{KBD_PIN1_KEY_C                ,KBD_PIN2_KEY_C                  },
	{KBD_PIN1_KEY_N                ,KBD_PIN2_KEY_N                  },
	{KBD_PIN1_KEY_B                ,KBD_PIN2_KEY_B                  },
	{KBD_PIN1_KEY_F                ,KBD_PIN2_KEY_F                  },
	{KBD_PIN1_KEY_A                ,KBD_PIN2_KEY_A                  },
	{KBD_PIN1_KEY_D                ,KBD_PIN2_KEY_D                  },
	{KBD_PIN1_KEY_LOWER_THAN       ,KBD_PIN2_KEY_LOWER_THAN         },
	{KBD_PIN1_KEY_X                ,KBD_PIN2_KEY_X                  },
	{KBD_PIN1_KEY_Y                ,KBD_PIN2_KEY_Y                  },
	{KBD_PIN1_KEY_PRINT            ,KBD_PIN2_KEY_PRINT              },
	{KBD_PIN1_KEY_BREAK            ,KBD_PIN2_KEY_BREAK              },
	{KBD_PIN1_KEY_DOLLAR           ,KBD_PIN2_KEY_DOLLAR             },
	{KBD_PIN1_KEY_EURO             ,KBD_PIN2_KEY_EURO               }
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

//First we need some dummies to fill the gaps
//Key "Fn" does not use any PS2 codes. Bytecount is 0
#define Ps2Mk_FN Ps2ScanCodeDummy
#define Ps2Bk_FN Ps2ScanCodeDummy
#define Ps2MkBc_FN Ps2ScanCodeDummy
#define Ps2BkBc_FN Ps2ScanCodeDummy

//Separate "$" creates a sequence of codes. TBD later
#define Ps2Mk_DOLLAR Ps2ScanCodeDummy
#define Ps2Bk_DOLLAR Ps2ScanCodeDummy
#define Ps2MkBc_DOLLAR Ps2ScanCodeDummy
#define Ps2BkBc_DOLLAR Ps2ScanCodeDummy

//Separate "€" creates a sequence of codes. TBD later
#define Ps2Mk_EURO Ps2ScanCodeDummy
#define Ps2Bk_EURO Ps2ScanCodeDummy
#define Ps2MkBc_EURO Ps2ScanCodeDummy
#define Ps2BkBc_EURO Ps2ScanCodeDummy

//Some virtual keys cause interactions with hardware or not active yet.
#define Ps2Mk_Dummy Ps2ScanCodeDummy
#define Ps2Bk_Dummy Ps2ScanCodeDummy
#define Ps2MkBc_Dummy Ps2ScanCodeDummy
#define Ps2BkBc_Dummy Ps2ScanCodeDummy


//PS2 scan code details mapping to PS2 macros
//The right part is taken from PS2_Details.h
#define KBD_PS2SCANCODESEXT(VIRTNAME, PS2NAME) \
const uint8_t PROGMEM Ps2Make_##VIRTNAME =    Ps2Mk_##PS2NAME;\
const uint8_t PROGMEM Ps2MakeBc_##VIRTNAME =  Ps2MkBc_##PS2NAME;

//In many cases, the identifying part of the name is the same
//Let's safe some typo errors before they occur and use a macro
#define KBD_PS2SCANCODES(NAME) \
KBD_PS2SCANCODESEXT(NAME,NAME)

//real buttons
KBD_PS2SCANCODES(FN)
KBD_PS2SCANCODES(F2)
KBD_PS2SCANCODES(F3)
KBD_PS2SCANCODES(F4)
KBD_PS2SCANCODES(F5)
KBD_PS2SCANCODES(F6)
KBD_PS2SCANCODES(F7)
KBD_PS2SCANCODES(F8)
KBD_PS2SCANCODES(ARROW_RIGHT)
KBD_PS2SCANCODES(ARROW_LEFT)
KBD_PS2SCANCODES(ARROW_DOWN)
KBD_PS2SCANCODES(ARROW_UP)
KBD_PS2SCANCODES(F11)
KBD_PS2SCANCODES(F12)
KBD_PS2SCANCODES(7)
KBD_PS2SCANCODES(9)
KBD_PS2SCANCODES(8)
KBD_PS2SCANCODES(0)
KBD_PS2SCANCODES(U)
KBD_PS2SCANCODES(I)
KBD_PS2SCANCODES(O)
KBD_PS2SCANCODES(P)
KBD_PS2SCANCODES(J)
KBD_PS2SCANCODES(K)
KBD_PS2SCANCODES(L)
KBD_PS2SCANCODES(OE)
KBD_PS2SCANCODES(M)
KBD_PS2SCANCODES(DOT)
KBD_PS2SCANCODES(MINUS)
KBD_PS2SCANCODES(CAPS_LOCK)
KBD_PS2SCANCODES(CTRL_L)
KBD_PS2SCANCODES(CTRL_R)
KBD_PS2SCANCODES(ALT_L)
KBD_PS2SCANCODES(ALT_R)
KBD_PS2SCANCODES(SHIFT_L)
KBD_PS2SCANCODES(SHIFT_R)
KBD_PS2SCANCODES(WIN_L)
KBD_PS2SCANCODES(WIN_R)
KBD_PS2SCANCODES(F1)
KBD_PS2SCANCODES(F9)
KBD_PS2SCANCODES(F10)
KBD_PS2SCANCODES(Q)
KBD_PS2SCANCODES(1)
KBD_PS2SCANCODES(ESC)
KBD_PS2SCANCODES(CIRCUMFLEX)
KBD_PS2SCANCODES(TAB)
KBD_PS2SCANCODES(BACKSPACE)
KBD_PS2SCANCODES(3)
KBD_PS2SCANCODES(2)
KBD_PS2SCANCODES(INSERT)
KBD_PS2SCANCODES(DELETE)
KBD_PS2SCANCODES(HOME)
KBD_PS2SCANCODES(PAGE_UP)
KBD_PS2SCANCODES(PAGE_DOWN)
KBD_PS2SCANCODES(UE)
KBD_PS2SCANCODES(AE)
KBD_PS2SCANCODES(QUESTIONMARK)
KBD_PS2SCANCODES(5)
KBD_PS2SCANCODES(APOS)
KBD_PS2SCANCODES(6)
KBD_PS2SCANCODES(4)
KBD_PS2SCANCODES(ASTERISK)
KBD_PS2SCANCODES(T)
KBD_PS2SCANCODES(R)
KBD_PS2SCANCODES(W)
KBD_PS2SCANCODES(ENTER)
KBD_PS2SCANCODES(H)
KBD_PS2SCANCODES(Z)
KBD_PS2SCANCODES(E)
KBD_PS2SCANCODES(S)
KBD_PS2SCANCODES(COMMA)
KBD_PS2SCANCODES(SHARP)
KBD_PS2SCANCODES(END)
KBD_PS2SCANCODES(G)
KBD_PS2SCANCODES(V)
KBD_PS2SCANCODES(SPACE)
KBD_PS2SCANCODES(C)
KBD_PS2SCANCODES(N)
KBD_PS2SCANCODES(B)
KBD_PS2SCANCODES(F)
KBD_PS2SCANCODES(A)
KBD_PS2SCANCODES(D)
KBD_PS2SCANCODES(LOWER_THAN)
KBD_PS2SCANCODES(X)
KBD_PS2SCANCODES(Y)
KBD_PS2SCANCODESEXT(PRINT, Dummy)
KBD_PS2SCANCODESEXT(BREAK, Dummy)
KBD_PS2SCANCODESEXT(DOLLAR, Dummy)
KBD_PS2SCANCODESEXT(EURO, Dummy)

//virtual buttons

KBD_PS2SCANCODESEXT(FN_F2, AcpiPower )        			//Fn + F2  =  ACPI Power
KBD_PS2SCANCODESEXT(FN_F3, AcpiWake )         			//Fn + F3  =  ACPI Wake
KBD_PS2SCANCODESEXT(FN_F4, AcpiSleep )        			//Fn + F4  =  ACPI Sleep
KBD_PS2SCANCODESEXT(FN_F5, Dummy )              			//Fn + F5  =  Toggle between internal, external and both displays
KBD_PS2SCANCODESEXT(FN_F6, Dummy )              			//Fn + F6  =  Turn backlight off to save power
KBD_PS2SCANCODESEXT(FN_F7, Dummy )              			//Fn + F7  =  Toggle Touchpad
KBD_PS2SCANCODESEXT(FN_F8, MmMute )              		//Fn + F8  =  Mute Speakers
KBD_PS2SCANCODESEXT(FN_ARROW_RIGHT, Dummy )     			//Fn + right = Brightness up
KBD_PS2SCANCODESEXT(FN_ARROW_LEFT, Dummy )      			//Fn + left  = Brightness down
KBD_PS2SCANCODESEXT(FN_ARROW_DOWN, MmVolumeDown )      	//Fn + down  = Volume down  
KBD_PS2SCANCODESEXT(FN_ARROW_UP, MmVolumeUp )        	//Fn + up    = Volume up
KBD_PS2SCANCODESEXT(FN_F11, NUM_LOCK )             		//Fn + F11 =  turn on NumLock
KBD_PS2SCANCODESEXT(FN_F12, SCROLL_LOCK )             	//Fn + F12 =  turn on ScrollLock

KBD_PS2SCANCODESEXT(NUMLOCK_KEY_7, NUMPAD_7 )           		// If NumLock LED is active, Code is NUMLOCK "7"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_9, NUMPAD_9 )           		// If NumLock LED is active, Code is NUMLOCK "8"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_8, NUMPAD_8 )           		// If NumLock LED is active, Code is NUMLOCK "9"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_0, NUMPAD_MULTI )           	// If NumLock LED is active, Code is NUMLOCK "*"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_U, NUMPAD_4 )           		// If NumLock LED is active, Code is NUMLOCK "4"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_I, NUMPAD_5 )           		// If NumLock LED is active, Code is NUMLOCK "5"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_O, NUMPAD_6 )           		// If NumLock LED is active, Code is NUMLOCK "6"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_P, NUMPAD_MINUS )           	// If NumLock LED is active, Code is NUMLOCK "-""
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_J, NUMPAD_1 )           		// If NumLock LED is active, Code is NUMLOCK "1"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_K, NUMPAD_2 )           		// If NumLock LED is active, Code is NUMLOCK "2"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_L, NUMPAD_3 )           		// If NumLock LED is active, Code is NUMLOCK "3"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_OE, NUMPAD_PLUS )          	// If NumLock LED is active, Code is NUMLOCK "+"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_M, NUMPAD_0 )           		// If NumLock LED is active, Code is NUMLOCK "0"
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_DOT, NUMPAD_DECIMAL )         	// If NumLock LED is active, Code is NUMLOCK ","
KBD_PS2SCANCODESEXT(NUMLOCK_KEY_MINUS, NUMPAD_DIVIDE )       // If NumLock LED is active, Code is NUMLOCK "/"

//Used for Ps2CodeCombo
struct KbdPs2ScanCodeDetails
{
  uint8_t ByteCountMakeCode;
  uint8_t MakeCode;
};

//An easy way to deal with all that similar names
#define PS2AllDetails(NAME) \
 Ps2MakeBc_##NAME,\
 Ps2Make_##NAME
   
//The full feateared list of PS code details, same order as for finding the buttons, but extended by virtual keys
const KbdPs2ScanCodeDetails  Ps2CodeCombo[KBD_REAL_KEY_COUNT + KBD_VIRT_KEY_COUNT] =
{
//real life keys
	{PS2AllDetails(FN)},  //no scancodes, just dummies
	{PS2AllDetails(F2)},
	{PS2AllDetails(F3)},
	{PS2AllDetails(F4)},
	{PS2AllDetails(F5)},
	{PS2AllDetails(F6)},
	{PS2AllDetails(F7)},
	{PS2AllDetails(F8)},
	{PS2AllDetails(ARROW_RIGHT)},
	{PS2AllDetails(ARROW_LEFT)},
	{PS2AllDetails(ARROW_DOWN)},
	{PS2AllDetails(ARROW_UP)},
	{PS2AllDetails(F11)},
	{PS2AllDetails(F12)},
	{PS2AllDetails(7)},
	{PS2AllDetails(9)},
	{PS2AllDetails(8)},
	{PS2AllDetails(0)},
	{PS2AllDetails(U)},
	{PS2AllDetails(I)},
	{PS2AllDetails(O)},
	{PS2AllDetails(P)},
	{PS2AllDetails(J)},
	{PS2AllDetails(K)},
	{PS2AllDetails(L)},
	{PS2AllDetails(OE)},
	{PS2AllDetails(M)},
	{PS2AllDetails(DOT)},
	{PS2AllDetails(MINUS)},
	{PS2AllDetails(CAPS_LOCK)},
	{PS2AllDetails(CTRL_L)},
	{PS2AllDetails(CTRL_R)},
	{PS2AllDetails(ALT_L)},
	{PS2AllDetails(ALT_R)},
	{PS2AllDetails(SHIFT_L)},
	{PS2AllDetails(SHIFT_R)},
	{PS2AllDetails(WIN_L)},
	{PS2AllDetails(WIN_R)},
	{PS2AllDetails(F1)},
	{PS2AllDetails(F9)},
	{PS2AllDetails(F10)},
	{PS2AllDetails(Q)},
	{PS2AllDetails(1)},
	{PS2AllDetails(ESC)},
	{PS2AllDetails(CIRCUMFLEX)},
	{PS2AllDetails(TAB)},
	{PS2AllDetails(BACKSPACE)},
	{PS2AllDetails(3)},
	{PS2AllDetails(2)},
	{PS2AllDetails(INSERT)},
	{PS2AllDetails(DELETE)},
	{PS2AllDetails(HOME)},
	{PS2AllDetails(PAGE_UP)},
	{PS2AllDetails(PAGE_DOWN)},
	{PS2AllDetails(UE)},
	{PS2AllDetails(AE)},
	{PS2AllDetails(QUESTIONMARK)},
	{PS2AllDetails(5)},
	{PS2AllDetails(APOS)},
	{PS2AllDetails(6)},
	{PS2AllDetails(4)},
	{PS2AllDetails(ASTERISK)},
	{PS2AllDetails(T)},
	{PS2AllDetails(R)},
	{PS2AllDetails(W)},
	{PS2AllDetails(ENTER)},
	{PS2AllDetails(H)},
	{PS2AllDetails(Z)},
	{PS2AllDetails(E)},
	{PS2AllDetails(S)},
	{PS2AllDetails(COMMA)},
	{PS2AllDetails(SHARP)},
	{PS2AllDetails(END)},
	{PS2AllDetails(G)},
	{PS2AllDetails(V)},
	{PS2AllDetails(SPACE)},
	{PS2AllDetails(C)},
	{PS2AllDetails(N)},
	{PS2AllDetails(B)},
	{PS2AllDetails(F)},
	{PS2AllDetails(A)},
	{PS2AllDetails(D)},
	{PS2AllDetails(LOWER_THAN)},
	{PS2AllDetails(X)},
	{PS2AllDetails(Y)},
	{PS2AllDetails(PRINT)},	   //long scan code, not stored here
	{PS2AllDetails(BREAK)},	  //long scan code, not staored here
	{PS2AllDetails(DOLLAR)},  //real key that will need to trigger a series of scan codes
	{PS2AllDetails(EURO)},    //real key that will need to trigger a series of scan codes
//end of real life keys

//virtual keys
	{PS2AllDetails(FN_F2)},
	{PS2AllDetails(FN_F3)},
	{PS2AllDetails(FN_F4)},
	{PS2AllDetails(FN_F5)},
	{PS2AllDetails(FN_F6)},
	{PS2AllDetails(FN_F7)},
	{PS2AllDetails(FN_F8)},
	{PS2AllDetails(FN_ARROW_RIGHT)},
	{PS2AllDetails(FN_ARROW_LEFT)},
	{PS2AllDetails(FN_ARROW_DOWN)},
	{PS2AllDetails(FN_ARROW_UP)},
	{PS2AllDetails(FN_F11)},
	{PS2AllDetails(FN_F12)},
	{PS2AllDetails(NUMLOCK_KEY_7)},
	{PS2AllDetails(NUMLOCK_KEY_9)},
	{PS2AllDetails(NUMLOCK_KEY_8)},
	{PS2AllDetails(NUMLOCK_KEY_0)},
	{PS2AllDetails(NUMLOCK_KEY_U)},
	{PS2AllDetails(NUMLOCK_KEY_I)},
	{PS2AllDetails(NUMLOCK_KEY_O)},
	{PS2AllDetails(NUMLOCK_KEY_P)},
	{PS2AllDetails(NUMLOCK_KEY_J)},
	{PS2AllDetails(NUMLOCK_KEY_K)},
	{PS2AllDetails(NUMLOCK_KEY_L)},
	{PS2AllDetails(NUMLOCK_KEY_OE)},
	{PS2AllDetails(NUMLOCK_KEY_M)},
	{PS2AllDetails(NUMLOCK_KEY_DOT)},
	{PS2AllDetails(NUMLOCK_KEY_MINUS)}
//end of virtual keys
};

/*end of file*/