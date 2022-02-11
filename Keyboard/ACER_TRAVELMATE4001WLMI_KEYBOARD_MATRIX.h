/*
 * 2022-02-10
 * 
 * Target System: Arduino Mega2560
 * Arduino IDE: 1.8.19
 * 
*/


#define MATRIX_PINS_COUNT 24
#define MATRIX_KEY_COUNT 89 //0 is the unknown key, the other 89 keys are known



/*
 each key gets its unique number here. There are 89 keys on the keyboard matrix.
 The strange order is the order as used in the matrix. other orders will work, too.
 But if the last button of this array can be used, at least the structures of this sketch are ok.
*/


#define ID_KEY_F11 				0 
#define ID_KEY_F12 				1 
#define ID_KEY_F8  				2 
#define ID_KEY_Q 				3 
#define ID_KEY_F4  				4 
#define ID_KEY_F3  				5 
#define ID_KEY_F7  				6 
#define ID_KEY_1 				7 
#define ID_KEY_ESC				8 
#define ID_KEY_TILDE  			9 
#define ID_KEY_F5  				10
#define ID_KEY_TAB 				11
#define ID_KEY_F1  				12
#define ID_KEY_F2  				13
#define ID_KEY_F6  				14
#define ID_KEY_CAPS_LOCK 		15
#define ID_KEY_F10 				16
#define ID_KEY_F9  				17
#define ID_KEY_BACKSPACE 		18
#define ID_KEY_3  				19
#define ID_KEY_2  				20
#define ID_KEY_ARROW_UP  		21
#define ID_KEY_PAUSE 			22
#define ID_KEY_PRINT  			23
#define ID_KEY_INSERT  			24
#define ID_KEY_DELETE  			25
#define ID_KEY_HOME 			26
#define ID_KEY_PAGE_UP 			27
#define ID_KEY_PAGE_DOWN  		28
#define ID_KEY_ARROW_RIGHT  	29
#define ID_KEY_ARROW_LEFT  		30
#define ID_KEY_ARROW_DOWN 		31
#define ID_KEY_UE  				32
#define ID_KEY_P  				33
#define ID_KEY_AE  				34
#define ID_KEY_OE   			35
#define ID_KEY_MINUS  			36
#define ID_KEY_DOT  			37
#define ID_KEY_DOLLAR   		38
#define ID_KEY_QUESTIONMARK  	39
#define ID_KEY_7  				40
#define ID_KEY_9 				41
#define ID_KEY_5  				42
#define ID_KEY_0  				43
#define ID_KEY_APOS  			44
#define ID_KEY_6  				45
#define ID_KEY_8  				46
#define ID_KEY_4  				47
#define ID_KEY_EURO   			48
#define ID_KEY_CTRL_L  			49
#define ID_KEY_CTRL_R  			50
#define ID_KEY_O  				51
#define ID_KEY_ASTERISK   		52
#define ID_KEY_T 				53
#define ID_KEY_U  				54
#define ID_KEY_R  				55
#define ID_KEY_W  				56
#define ID_KEY_SHIFT_R  		57
#define ID_KEY_SHIFT_L  		58
#define ID_KEY_I  				59
#define ID_KEY_ENTER  			60
#define ID_KEY_H  				61
#define ID_KEY_Z  				62
#define ID_KEY_E  				63
#define ID_KEY_S  				64
#define ID_KEY_L  				65
#define ID_KEY_K  				66
#define ID_KEY_M  				67
#define ID_KEY_COMMA  			68
#define ID_KEY_SHARP  			69
#define ID_KEY_END  			70
#define ID_KEY_WIN_R  			71
#define ID_KEY_G  				72
#define ID_KEY_V  				73
#define ID_KEY_SPACE  			74
#define ID_KEY_C  				75
#define ID_KEY_J  				76
#define ID_KEY_N  				77
#define ID_KEY_B  				78
#define ID_KEY_F  				79
#define ID_KEY_A  				80
#define ID_KEY_D  				81
#define ID_KEY_SMALLER  		82
#define ID_KEY_X  				83
#define ID_KEY_WIN_L  			84
#define ID_KEY_ALT_L  			85
#define ID_KEY_ALT_R  			86
#define ID_KEY_Y  				87
#define ID_KEY_FN   			88


const char PROGMEM HR_KEY_F11[] =      			"F11"                 ;
const char PROGMEM HR_KEY_F12[] =      			"F12"                 ;
const char PROGMEM HR_KEY_F8[] =       			"F8"                  ;
const char PROGMEM HR_KEY_Q[] =      				"Q"               ;
const char PROGMEM HR_KEY_F4[] =       			"F4"                  ;
const char PROGMEM HR_KEY_F3[] =       			"F3"                  ;
const char PROGMEM HR_KEY_F7[] =       			"F7"                  ;
const char PROGMEM HR_KEY_1[] =      				"1"               ;
const char PROGMEM HR_KEY_ESC[] =      			"ESC"                 ;
const char PROGMEM HR_KEY_TILDE[] =       			"^"               ;
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
const char PROGMEM HR_KEY_SMALLER[] =    			"<"               ;
const char PROGMEM HR_KEY_X[] =      				"X"               ;
const char PROGMEM HR_KEY_WIN_L[] =      			"Win-L"           ;
const char PROGMEM HR_KEY_ALT_L[] =      			"Alt"             ;
const char PROGMEM HR_KEY_ALT_R[] =      			"AltGr"           ;
const char PROGMEM HR_KEY_Y[] =     				"Y"               ;
const char PROGMEM HR_KEY_FN[] =       			"Fn"                  ;


const char PROGMEM HR_Fn_KEY_F11[] 		=      			"NumPad";
const char PROGMEM HR_Fn_KEY_F12[] 		=      			"Scroll";
const char PROGMEM HR_Fn_KEY_F8[] 		=      			"Speaker";
const char PROGMEM HR_Fn_KEY_Q[] 		  = "";
const char PROGMEM HR_Fn_KEY_F4[] 		=      			"Sleep";
const char PROGMEM HR_Fn_KEY_F3[] 		=      			"Wake up";
const char PROGMEM HR_Fn_KEY_F7[] 		=      			"Touchpad";
const char PROGMEM HR_Fn_KEY_1[] 		  = "";
const char PROGMEM HR_Fn_KEY_ESC[] 		= "";
const char PROGMEM HR_Fn_KEY_TILDE[] =       		"";
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
const char PROGMEM HR_Fn_KEY_SMALLER[] =    		"";
const char PROGMEM HR_Fn_KEY_X[] =      			"";
const char PROGMEM HR_Fn_KEY_WIN_L[] =      		"";
const char PROGMEM HR_Fn_KEY_ALT_L[] =      		"";
const char PROGMEM HR_Fn_KEY_ALT_R[] =      		"";
const char PROGMEM HR_Fn_KEY_Y[] =     				"";
const char PROGMEM HR_Fn_KEY_FN[] =       			"";

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
  0, /*KEY_TILDE*/
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
  0, /*KEY_SMALLER*/
  0, /*KEY_X*/
  0, /*KEY_WIN_L*/
  0, /*KEY_ALT_L*/
  0, /*KEY_ALT_R*/
  0, /*KEY_Y*/
  0, /*KEY_FN*/
};

  /*This is the array that in a way holds the labels of the Keys. If you got the cell content from the Matrix, this is the transformation to a human readable string, just to see
    the keyboard decoder is doing the right things and the wiring is ok.  
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
	,HR_KEY_TILDE
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
	,HR_KEY_SMALLER
	,HR_KEY_X
	,HR_KEY_WIN_L
	,HR_KEY_ALT_L
	,HR_KEY_ALT_R
	,HR_KEY_Y
	,HR_KEY_FN
};

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
	,HR_Fn_KEY_TILDE
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
	,HR_Fn_KEY_SMALLER
	,HR_Fn_KEY_X
	,HR_Fn_KEY_WIN_L
	,HR_Fn_KEY_ALT_L
	,HR_Fn_KEY_ALT_R
	,HR_Fn_KEY_Y
	,HR_Fn_KEY_FN
};

const uint8_t PIN1_KEY_F11  		= 2;
const uint8_t PIN1_KEY_F12  		= 2;
const uint8_t PIN1_KEY_F8  			= 2;
const uint8_t PIN1_KEY_Q  			= 2;
const uint8_t PIN1_KEY_F4  			= 2;
const uint8_t PIN1_KEY_F3  			= 2;
const uint8_t PIN1_KEY_F7  			= 2;
const uint8_t PIN1_KEY_1  			= 2;

const uint8_t PIN1_KEY_ESC  		= 1;
const uint8_t PIN1_KEY_TILDE  		= 1;
const uint8_t PIN1_KEY_F5  			= 1;
const uint8_t PIN1_KEY_TAB  		= 1;
const uint8_t PIN1_KEY_F1  			= 1;
const uint8_t PIN1_KEY_F2  			= 1;
const uint8_t PIN1_KEY_F6  			= 1;
const uint8_t PIN1_KEY_CAPS_LOCK  	= 1;

const uint8_t PIN1_KEY_F10  		= 4;
const uint8_t PIN1_KEY_F9  			= 4;
const uint8_t PIN1_KEY_BACKSPACE  	= 4;
const uint8_t PIN1_KEY_3  			= 4;
const uint8_t PIN1_KEY_2  			= 4;
const uint8_t PIN1_KEY_ARROW_UP  	= 4;
const uint8_t PIN1_KEY_PAUSE 		= 4;
const uint8_t PIN1_KEY_PRINT  		= 4;

const uint8_t PIN1_KEY_INSERT  		= 3;
const uint8_t PIN1_KEY_DELETE  		= 3;
const uint8_t PIN1_KEY_HOME  		= 3;
const uint8_t PIN1_KEY_PAGE_UP  	= 3;
const uint8_t PIN1_KEY_PAGE_DOWN  	= 3;
const uint8_t PIN1_KEY_ARROW_RIGHT  = 3;
const uint8_t PIN1_KEY_ARROW_LEFT  	= 3;
const uint8_t PIN1_KEY_ARROW_DOWN  	= 3;

const uint8_t PIN1_KEY_UE  			= 6;
const uint8_t PIN1_KEY_P  			= 6;
const uint8_t PIN1_KEY_AE  			= 6;
const uint8_t PIN1_KEY_OE  			= 6;
const uint8_t PIN1_KEY_MINUS  		= 6;
const uint8_t PIN1_KEY_DOT  		= 6;

const uint8_t PIN1_KEY_DOLLAR  		= 5;
const uint8_t PIN1_KEY_QUESTIONMARK = 5;
const uint8_t PIN1_KEY_7  			= 5;
const uint8_t PIN1_KEY_9  			= 5;
const uint8_t PIN1_KEY_5  			= 5;

const uint8_t PIN1_KEY_0  			= 8;
const uint8_t PIN1_KEY_APOS  		= 8;
const uint8_t PIN1_KEY_6  			= 8;
const uint8_t PIN1_KEY_8  			= 8;
const uint8_t PIN1_KEY_4  			= 8;

const uint8_t PIN1_KEY_EURO  		= 7;

const uint8_t PIN1_KEY_CTRL_L  		= 10;
const uint8_t PIN1_KEY_CTRL_R  		= 10;

const uint8_t PIN1_KEY_O  			= 9;
const uint8_t PIN1_KEY_ASTERISK  	= 9;
const uint8_t PIN1_KEY_T  			= 9;
const uint8_t PIN1_KEY_U  			= 9;
const uint8_t PIN1_KEY_R  			= 9;
const uint8_t PIN1_KEY_W  			= 9;

const uint8_t PIN1_KEY_SHIFT_R  	= 12;
const uint8_t PIN1_KEY_SHIFT_L  	= 12;

const uint8_t PIN1_KEY_I  			= 11;
const uint8_t PIN1_KEY_ENTER  		= 11;
const uint8_t PIN1_KEY_H  			= 11;
const uint8_t PIN1_KEY_Z  			= 11;
const uint8_t PIN1_KEY_E  			= 11;
const uint8_t PIN1_KEY_S  			= 11;

const uint8_t PIN1_KEY_L  			= 14;
const uint8_t PIN1_KEY_K  			= 14;
const uint8_t PIN1_KEY_M  			= 14;
const uint8_t PIN1_KEY_COMMA  		= 14;

const uint8_t PIN1_KEY_SHARP  		= 13;
const uint8_t PIN1_KEY_END  		= 13;
const uint8_t PIN1_KEY_WIN_R  		= 13;

const uint8_t PIN1_KEY_G  			= 16;
const uint8_t PIN1_KEY_V  			= 16;
const uint8_t PIN1_KEY_SPACE  		= 16;
const uint8_t PIN1_KEY_C  			= 16;

const uint8_t PIN1_KEY_J  			= 15;
const uint8_t PIN1_KEY_N  			= 15;
const uint8_t PIN1_KEY_B  			= 15;

const uint8_t PIN1_KEY_F  			= 18;
const uint8_t PIN1_KEY_A  			= 18;

const uint8_t PIN1_KEY_D  			= 17;
const uint8_t PIN1_KEY_SMALLER  	= 17;
const uint8_t PIN1_KEY_X  			= 17;

const uint8_t PIN1_KEY_WIN_L  		= 20;

const uint8_t PIN1_KEY_ALT_L  		= 19;
const uint8_t PIN1_KEY_ALT_R  		= 19;

const uint8_t PIN1_KEY_Y  			= 22;

const uint8_t PIN1_KEY_FN  			= 21;


const uint8_t PIN2_KEY_F11  		= 5;  
const uint8_t PIN2_KEY_F12  		= 8; 
const uint8_t PIN2_KEY_F8  			= 9; 
const uint8_t PIN2_KEY_Q  			= 11; 
const uint8_t PIN2_KEY_F4  			= 18; 
const uint8_t PIN2_KEY_F3  			= 22; 
const uint8_t PIN2_KEY_F7  			= 24; 
const uint8_t PIN2_KEY_1  			= 23;
 
const uint8_t PIN2_KEY_ESC  		= 5;  
const uint8_t PIN2_KEY_TILDE  		= 8;  
const uint8_t PIN2_KEY_F5  			= 9; 
const uint8_t PIN2_KEY_TAB  		= 11;
const uint8_t PIN2_KEY_F1  			= 18;
const uint8_t PIN2_KEY_F2  			= 22;
const uint8_t PIN2_KEY_F6  			= 24;
const uint8_t PIN2_KEY_CAPS_LOCK  	= 23;

const uint8_t PIN2_KEY_F10  		= 5 ;
const uint8_t PIN2_KEY_F9  			= 8 ;
const uint8_t PIN2_KEY_BACKSPACE  	= 9;
const uint8_t PIN2_KEY_3  			= 11;
const uint8_t PIN2_KEY_2  			= 18;
const uint8_t PIN2_KEY_ARROW_UP  	= 22;
const uint8_t PIN2_KEY_PAUSE 		= 24;
const uint8_t PIN2_KEY_PRINT  		= 23;

const uint8_t PIN2_KEY_INSERT  		= 5 ;
const uint8_t PIN2_KEY_DELETE  		= 8 ;
const uint8_t PIN2_KEY_HOME  		= 9;
const uint8_t PIN2_KEY_PAGE_UP  	= 11;
const uint8_t PIN2_KEY_PAGE_DOWN  	= 18;
const uint8_t PIN2_KEY_ARROW_RIGHT  = 22;
const uint8_t PIN2_KEY_ARROW_LEFT  	= 24;
const uint8_t PIN2_KEY_ARROW_DOWN  	= 23;

const uint8_t PIN2_KEY_UE  			= 5 ;
const uint8_t PIN2_KEY_P  			= 8 ;
const uint8_t PIN2_KEY_AE  			= 9	;
const uint8_t PIN2_KEY_OE  			= 11;
const uint8_t PIN2_KEY_MINUS  		= 18;
const uint8_t PIN2_KEY_DOT  		= 22;

const uint8_t PIN2_KEY_DOLLAR  		= 10;
const uint8_t PIN2_KEY_QUESTIONMARK = 14;
const uint8_t PIN2_KEY_7  			= 16;
const uint8_t PIN2_KEY_9  			= 15;
const uint8_t PIN2_KEY_5  			= 17;

const uint8_t PIN2_KEY_0  			= 14;
const uint8_t PIN2_KEY_APOS  		= 13;
const uint8_t PIN2_KEY_6  			= 16;
const uint8_t PIN2_KEY_8  			= 15;
const uint8_t PIN2_KEY_4  			= 17;

const uint8_t PIN2_KEY_EURO  		= 18;
const uint8_t PIN2_KEY_CTRL_L  		= 22;
const uint8_t PIN2_KEY_CTRL_R  		= 24;

const uint8_t PIN2_KEY_O  			= 14;
const uint8_t PIN2_KEY_ASTERISK  	= 13;
const uint8_t PIN2_KEY_T  			= 16;
const uint8_t PIN2_KEY_U  			= 15;
const uint8_t PIN2_KEY_R  			= 17;
const uint8_t PIN2_KEY_W  			= 21;

const uint8_t PIN2_KEY_SHIFT_R  	= 18;
const uint8_t PIN2_KEY_SHIFT_L  	= 22;

const uint8_t PIN2_KEY_I  			= 14;
const uint8_t PIN2_KEY_ENTER  		= 13;
const uint8_t PIN2_KEY_H  			= 16;
const uint8_t PIN2_KEY_Z  			= 15;
const uint8_t PIN2_KEY_E  			= 17;
const uint8_t PIN2_KEY_S  			= 21;

const uint8_t PIN2_KEY_L  			= 18;
const uint8_t PIN2_KEY_K  			= 22;
const uint8_t PIN2_KEY_M  			= 24;
const uint8_t PIN2_KEY_COMMA  		= 23;

const uint8_t PIN2_KEY_SHARP  		= 18;
const uint8_t PIN2_KEY_END  		= 22;
const uint8_t PIN2_KEY_WIN_R  		= 24;

const uint8_t PIN2_KEY_G  			= 18;
const uint8_t PIN2_KEY_V  			= 22;
const uint8_t PIN2_KEY_SPACE  		= 24;
const uint8_t PIN2_KEY_C  			= 23;

const uint8_t PIN2_KEY_J  			= 18;
const uint8_t PIN2_KEY_N  			= 22;
const uint8_t PIN2_KEY_B  			= 23;

const uint8_t PIN2_KEY_F  			= 17;
const uint8_t PIN2_KEY_A  			= 21;

const uint8_t PIN2_KEY_D  			= 22;
const uint8_t PIN2_KEY_SMALLER  	= 24;
const uint8_t PIN2_KEY_X  			= 23;

const uint8_t PIN2_KEY_WIN_L  		= 24;

const uint8_t PIN2_KEY_ALT_L  		= 24;
const uint8_t PIN2_KEY_ALT_R  		= 23;

const uint8_t PIN2_KEY_Y  			= 21;
const uint8_t PIN2_KEY_FN  			= 24;


const uint8_t PS2_MAKEBYTE_COUNT_KEY_F11  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F12  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F8  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_Q  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F4  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F3  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F7  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_1  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_ESC  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_TILDE  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F5  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_TAB  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F1  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F2  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F6  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_CAPS_LOCK  	= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F10  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F9  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_BACKSPACE  	= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_3  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_2  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_ARROW_UP  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_PAUSE 			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_PRINT  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_INSERT  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_DELETE  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_HOME  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_PAGE_UP  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_PAGE_DOWN  	= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_ARROW_RIGHT  	= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_ARROW_LEFT  	= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_ARROW_DOWN  	= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_UE  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_P  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_AE  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_OE  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_MINUS  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_DOT  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_DOLLAR  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_QUESTIONMARK  	= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_7  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_9  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_5  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_0  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_APOS  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_6  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_8  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_4  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_EURO  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_CTRL_L  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_CTRL_R  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_O  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_ASTERISK  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_T  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_U  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_R  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_W  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_SHIFT_R  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_SHIFT_L  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_I  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_ENTER  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_H  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_Z  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_E  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_S  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_L  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_K  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_M  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_COMMA  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_SHARP  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_END  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_WIN_R  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_G  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_V  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_SPACE  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_C  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_J  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_N  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_B  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_F  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_A  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_D  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_SMALLER  		= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_X  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_WIN_L 			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_ALT_L 			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_ALT_R 			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_Y  			= 1;
const uint8_t PS2_MAKEBYTE_COUNT_KEY_FN  			= 1;


struct detect_pins
{
  uint8_t PinA;
  uint8_t PinB;
};



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
  {PIN1_KEY_TILDE      		,PIN2_KEY_TILDE    }, 
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
  {PIN1_KEY_SMALLER    		,PIN2_KEY_SMALLER  }, 
  {PIN1_KEY_X          		,PIN2_KEY_X        }, 
  {PIN1_KEY_WIN_L      		,PIN2_KEY_WIN_L    }, 
  {PIN1_KEY_ALT_L      		,PIN2_KEY_ALT_L    }, 
  {PIN1_KEY_ALT_R      		,PIN2_KEY_ALT_R    }, 
  {PIN1_KEY_Y          		,PIN2_KEY_Y        },
  {PIN1_KEY_FN         		,PIN2_KEY_FN		}  
};		

/* 
	############# PS2 Stuff (unfinished) ##############
	https://de.wikipedia.org/wiki/PS/2-Schnittstelle
	http://www.winfaq.de/faq_html/Content/tip1500/onlinefaq.php?h=tip1576.htm
*/

//Keyboard matrix Line 1 - Make Codes Byte Count
const uint8_t PS2_SC_MAKE_BYTECOUNT_ESC 	/*PROGMEM*/ =		{1};          
const uint8_t PS2_SC_MAKE_BYTECOUNT_F1 		/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F2 		/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F3 		/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F4 		/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F5 		/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F6 		/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F7 		/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F8 		/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F9 		/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F10 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F11 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F12 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_PRINT 	/*PROGMEM*/ =		{4};
const uint8_t PS2_SC_MAKE_BYTECOUNT_PAUSE 	/*PROGMEM*/ =		{8};
const uint8_t PS2_SC_MAKE_BYTECOUNT_INSERT 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_MAKE_BYTECOUNT_DELETE 	/*PROGMEM*/ =		{2};

//Keyboard matrix Line 2 - Make Codes Byte Count
const uint8_t PS2_SC_MAKE_BYTECOUNT_TILDE 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_1 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_2 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_3 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_4 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_5 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_6 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_7 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_8 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_9 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_0 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_QUESTIONMARK 	/*PROGMEM*/ =		{1};  	
const uint8_t PS2_SC_MAKE_BYTECOUNT_APOS 	/*PROGMEM*/ =		{1};    	
const uint8_t PS2_SC_MAKE_BYTECOUNT_BACKSPACE 	/*PROGMEM*/ =		{1};    	
const uint8_t PS2_SC_MAKE_BYTECOUNT_HOME 	/*PROGMEM*/ =		{2};

//Keyboard matrix Line 3 - Make Codes Byte Count
const uint8_t PS2_SC_MAKE_BYTECOUNT_TAB 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_Q 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_W 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_E 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_R 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_T 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_Z 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_U 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_I 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_O 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_P 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_UE 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_ASTERISK 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_ENTER 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_PAGE_UP 	/*PROGMEM*/ =		{2};

//Keyboard matrix Line 4 - Make Codes Byte Count
const uint8_t PS2_SC_MAKE_BYTECOUNT_CAPS_LOCK 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_A 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_S 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_D 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_F 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_G 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_H 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_J 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_K 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_L 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_OE 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_AE 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_SHARP 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_PAGE_DOWN 	/*PROGMEM*/ =		{2};

//Keyboard matrix Line 5 - Make Codes Byte Count
const uint8_t PS2_SC_MAKE_BYTECOUNT_SHIFT_L 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_SMALLER 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_Y 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_X 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_C 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_V 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_B 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_N 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_M 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_COMMA 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_DOT 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_MINUS 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_SHIFT_R 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_END 	/*PROGMEM*/ =		{2};

//Keyboard matrix Line 6 - Make Codes Byte Count
const uint8_t PS2_SC_MAKE_BYTECOUNT_CTRL_L 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_FN 	/*PROGMEM*/ =		{0};  //No external communication
const uint8_t PS2_SC_MAKE_BYTECOUNT_WIN_L 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_MAKE_BYTECOUNT_ALT_L 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_SPACE 	/*PROGMEM*/ =		{1};
const uint8_t PS2_SC_MAKE_BYTECOUNT_ALT_R 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_MAKE_BYTECOUNT_WIN_R 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_MAKE_BYTECOUNT_CTRL_R 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_MAKE_BYTECOUNT_EURO 	/*PROGMEM*/ =		{0}; /* extra € key currently unused*/
const uint8_t PS2_SC_MAKE_BYTECOUNT_ARROW_UP 	/*PROGMEM*/ =		{2};	
const uint8_t PS2_SC_MAKE_BYTECOUNT_DOLLAR 	/*PROGMEM*/ =		{0}; /* extra $ key currently unused*/

//Keyboard matrix Line 7 - Make Codes Byte Count
const uint8_t PS2_SC_MAKE_BYTECOUNT_ARROW_LEFT 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_MAKE_BYTECOUNT_ARROW_DOWN 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_MAKE_BYTECOUNT_ARROW_RIGHT 	/*PROGMEM*/ =		{2};

//This is Scan Code Set 2
//PS2 Communication Host to Keyboard
const uint8_t PS2_H2K_RESET 						= 0xFF;
const uint8_t PS2_H2K_SET_ALL_KEY_TYPEMATIC 		= 0xF7;
const uint8_t PS2_H2K_SET_DEFAULT 					= 0xF6;
const uint8_t PS2_H2K_DISABLE 						= 0xF5;
const uint8_t PS2_H2K_ENABLE 						= 0xF4;
const uint8_t PS2_H2K_SET_RATE_DELAY				= 0xF3;
const uint8_t PS2_H2K_READ_KEYBOARD_ID				= 0xF2;
const uint8_t PS2_H2K_SET_SCANCODE 					= 0xF0;
const uint8_t PS2_H2K_SCAN_CODE_REQUEST				= 0x00;
const uint8_t PS2_H2K_SCAN_CODE_SET_1				= 0x01;
const uint8_t PS2_H2K_SCAN_CODE_SET_2				= 0x02;
const uint8_t PS2_H2K_SCAN_CODE_SET_3				= 0x03;
const uint8_t PS2_H2K_ECHO							= 0xEE;
const uint8_t PS2_H2K_SET_RESET_LEDS				= 0xED;
const uint8_t PS2_H2K_LED_CAPS_LOCK					= 0x04;
const uint8_t PS2_H2K_LED_NUM_LOCK					= 0x02;
const uint8_t PS2_H2K_LED_SCROLL_LOCK				= 0x01;

//PS2 Communication Keyboard to Host
const uint8_t PS2_K2H_SELFTEST_OK					= 0xAA;
const uint8_t PS2_K2H_ACKNOWLEDGE 					= 0xFA;
const uint8_t PS2_K2H_RESEND 						= 0xFE;
const uint8_t PS2_K2H_KEYBOARD_ID[]					= {0xAB, 0x83};
			
//Keyboard matrix Line 1 - Make Codes

const uint8_t PS2_SC_MAKE_ESC[] 	/*PROGMEM*/ =		{0x76};          
const uint8_t PS2_SC_MAKE_F1[] 		/*PROGMEM*/ =		{0x05};
const uint8_t PS2_SC_MAKE_F2[] 		/*PROGMEM*/ =		{0x06};
const uint8_t PS2_SC_MAKE_F3[] 		/*PROGMEM*/ =		{0x04};
const uint8_t PS2_SC_MAKE_F4[] 		/*PROGMEM*/ =		{0x0C};
const uint8_t PS2_SC_MAKE_F5[] 		/*PROGMEM*/ =		{0x03};
const uint8_t PS2_SC_MAKE_F6[] 		/*PROGMEM*/ =		{0x0B};
const uint8_t PS2_SC_MAKE_F7[] 		/*PROGMEM*/ =		{0x83};
const uint8_t PS2_SC_MAKE_F8[] 		/*PROGMEM*/ =		{0x0A};
const uint8_t PS2_SC_MAKE_F9[] 		/*PROGMEM*/ =		{0x01};
const uint8_t PS2_SC_MAKE_F10[] 	/*PROGMEM*/ =		{0x09};
const uint8_t PS2_SC_MAKE_F11[] 	/*PROGMEM*/ =		{0x78};
const uint8_t PS2_SC_MAKE_F12[] 	/*PROGMEM*/ =		{0x07};
const uint8_t PS2_SC_MAKE_PRINT[] 	/*PROGMEM*/ =		{0xE0,0x12,  0xE0,0x7C};
const uint8_t PS2_SC_MAKE_PAUSE[] 	/*PROGMEM*/ =		{0xE1,0x14,0x77,  0xE1,0xF0,0x14,  0xF0,0x77};
const uint8_t PS2_SC_MAKE_INSERT[] 	/*PROGMEM*/ =		{0xE0,0x70};
const uint8_t PS2_SC_MAKE_DELETE[] 	/*PROGMEM*/ =		{0xE0,0x71};

//Keyboard matrix Line 2 - Make Codes
const uint8_t PS2_SC_MAKE_TILDE[] 	/*PROGMEM*/ =		{0xE0};
const uint8_t PS2_SC_MAKE_1[] 	/*PROGMEM*/ =		{0x16};
const uint8_t PS2_SC_MAKE_2[] 	/*PROGMEM*/ =		{0x1E};
const uint8_t PS2_SC_MAKE_3[] 	/*PROGMEM*/ =		{0x26};
const uint8_t PS2_SC_MAKE_4[] 	/*PROGMEM*/ =		{0x25};
const uint8_t PS2_SC_MAKE_5[] 	/*PROGMEM*/ =		{0x2E};
const uint8_t PS2_SC_MAKE_6[] 	/*PROGMEM*/ =		{0x36};
const uint8_t PS2_SC_MAKE_7[] 	/*PROGMEM*/ =		{0x3D};
const uint8_t PS2_SC_MAKE_8[] 	/*PROGMEM*/ =		{0x3E};
const uint8_t PS2_SC_MAKE_9[] 	/*PROGMEM*/ =		{0x46};
const uint8_t PS2_SC_MAKE_0[] 	/*PROGMEM*/ =		{0x45};
const uint8_t PS2_SC_MAKE_QUESTIONMARK[] 	/*PROGMEM*/ =		{0x4E};  	
const uint8_t PS2_SC_MAKE_APOS[] 	/*PROGMEM*/ =		{0x55};    	
const uint8_t PS2_SC_MAKE_BACKSPACE[] 	/*PROGMEM*/ =		{0x66};    	
const uint8_t PS2_SC_MAKE_HOME[] 	/*PROGMEM*/ =		{0xE0,0x6C};

//Keyboard matrix Line 3 - Make Codes
const uint8_t PS2_SC_MAKE_TAB[] 	/*PROGMEM*/ =		{0x0D};
const uint8_t PS2_SC_MAKE_Q[] 	/*PROGMEM*/ =		{0x15};
const uint8_t PS2_SC_MAKE_W[] 	/*PROGMEM*/ =		{0x1D};
const uint8_t PS2_SC_MAKE_E[] 	/*PROGMEM*/ =		{0x24};
const uint8_t PS2_SC_MAKE_R[] 	/*PROGMEM*/ =		{0x2D};
const uint8_t PS2_SC_MAKE_T[] 	/*PROGMEM*/ =		{0x2C};
const uint8_t PS2_SC_MAKE_Z[] 	/*PROGMEM*/ =		{0x35};
const uint8_t PS2_SC_MAKE_U[] 	/*PROGMEM*/ =		{0x3C};
const uint8_t PS2_SC_MAKE_I[] 	/*PROGMEM*/ =		{0x43};
const uint8_t PS2_SC_MAKE_O[] 	/*PROGMEM*/ =		{0x44};
const uint8_t PS2_SC_MAKE_P[] 	/*PROGMEM*/ =		{0x4D};
const uint8_t PS2_SC_MAKE_UE[] 	/*PROGMEM*/ =		{0x54};
const uint8_t PS2_SC_MAKE_ASTERISK[] 	/*PROGMEM*/ =		{0x5B};
const uint8_t PS2_SC_MAKE_ENTER[] 	/*PROGMEM*/ =		{0x5A};
const uint8_t PS2_SC_MAKE_PAGE_UP[] 	/*PROGMEM*/ =		{0xE0,0x7D};

//Keyboard matrix Line 4 - Make Codes
const uint8_t PS2_SC_MAKE_CAPS_LOCK[] 	/*PROGMEM*/ =		{0x58};
const uint8_t PS2_SC_MAKE_A[] 	/*PROGMEM*/ =		{0x1C};
const uint8_t PS2_SC_MAKE_S[] 	/*PROGMEM*/ =		{0x1B};
const uint8_t PS2_SC_MAKE_D[] 	/*PROGMEM*/ =		{0x23};
const uint8_t PS2_SC_MAKE_F[] 	/*PROGMEM*/ =		{0x2B};
const uint8_t PS2_SC_MAKE_G[] 	/*PROGMEM*/ =		{0x34};
const uint8_t PS2_SC_MAKE_H[] 	/*PROGMEM*/ =		{0x33};
const uint8_t PS2_SC_MAKE_J[] 	/*PROGMEM*/ =		{0x3B};
const uint8_t PS2_SC_MAKE_K[] 	/*PROGMEM*/ =		{0x42};
const uint8_t PS2_SC_MAKE_L[] 	/*PROGMEM*/ =		{0x4B};
const uint8_t PS2_SC_MAKE_OE[] 	/*PROGMEM*/ =		{0x4C};
const uint8_t PS2_SC_MAKE_AE[] 	/*PROGMEM*/ =		{0x52};
const uint8_t PS2_SC_MAKE_SHARP[] 	/*PROGMEM*/ =		{0x5D};
const uint8_t PS2_SC_MAKE_PAGE_DOWN[] 	/*PROGMEM*/ =		{0xE0,0x7A};

//Keyboard matrix Line 5 - Make Codes
const uint8_t PS2_SC_MAKE_SHIFT_L[] 	/*PROGMEM*/ =		{0x12};
const uint8_t PS2_SC_MAKE_SMALLER[] 	/*PROGMEM*/ =		{0x61};
const uint8_t PS2_SC_MAKE_Y[] 	/*PROGMEM*/ =		{0x1A};
const uint8_t PS2_SC_MAKE_X[] 	/*PROGMEM*/ =		{0x22};
const uint8_t PS2_SC_MAKE_C[] 	/*PROGMEM*/ =		{0x21};
const uint8_t PS2_SC_MAKE_V[] 	/*PROGMEM*/ =		{0x2A};
const uint8_t PS2_SC_MAKE_B[] 	/*PROGMEM*/ =		{0x32};
const uint8_t PS2_SC_MAKE_N[] 	/*PROGMEM*/ =		{0x31};
const uint8_t PS2_SC_MAKE_M[] 	/*PROGMEM*/ =		{0x3A};
const uint8_t PS2_SC_MAKE_COMMA[] 	/*PROGMEM*/ =		{0x41};
const uint8_t PS2_SC_MAKE_DOT[] 	/*PROGMEM*/ =		{0x49};
const uint8_t PS2_SC_MAKE_MINUS[] 	/*PROGMEM*/ =		{0x4A};
const uint8_t PS2_SC_MAKE_SHIFT_R[] 	/*PROGMEM*/ =		{0x59};
const uint8_t PS2_SC_MAKE_END[] 	/*PROGMEM*/ =		{0xE0,0x69};

//Keyboard matrix Line 6 - Make Codes
const uint8_t PS2_SC_MAKE_CTRL_L[] 	/*PROGMEM*/ =		{0x14};
const uint8_t PS2_SC_MAKE_WIN_L[] 	/*PROGMEM*/ =		{0xE0,0x1F};
const uint8_t PS2_SC_MAKE_ALT_L[] 	/*PROGMEM*/ =		{0x11};
const uint8_t PS2_SC_MAKE_SPACE[] 	/*PROGMEM*/ =		{0x29};
const uint8_t PS2_SC_MAKE_ALT_R[] 	/*PROGMEM*/ =		{0xE0,0x11};
const uint8_t PS2_SC_MAKE_WIN_R[] 	/*PROGMEM*/ =		{0xE0,0x2F};
const uint8_t PS2_SC_MAKE_CTRL_R[] 	/*PROGMEM*/ =		{0xE0,0x14};
/* extra € key unused*/				
const uint8_t PS2_SC_MAKE_ARROW_UP[] 	/*PROGMEM*/ =		{0xE0,0x75};	
/* extra $ key unused*/

//Keyboard matrix Line 7 - Make Codes
const uint8_t PS2_SC_MAKE_ARROW_LEFT[] 	/*PROGMEM*/ =		{0xE0,0x6B};
const uint8_t PS2_SC_MAKE_ARROW_DOWN[] 	/*PROGMEM*/ =		{0xE0,0x72};
const uint8_t PS2_SC_MAKE_ARROW_RIGHT[] 	/*PROGMEM*/ =		{0xE0,0x74};


//Multimedia Scan Codes - Make Codes
const uint8_t PS2_SC_MAKE_NEXT_TRACK[] 	/*PROGMEM*/ =		{0xE0, 0x4D};
const uint8_t PS2_SC_MAKE_PREVIOUS_TRACK[] 	/*PROGMEM*/ =		{0xE0, 0x15};
const uint8_t PS2_SC_MAKE_STOP[] 	/*PROGMEM*/ =		{0xE0, 0x3B};
const uint8_t PS2_SC_MAKE_PLAY_PAUSE[] 	/*PROGMEM*/ =		{0xE0, 0x34};
const uint8_t PS2_SC_MAKE_MUTE[] 	/*PROGMEM*/ =		{0xE0, 0x23};
const uint8_t PS2_SC_MAKE_VOLUME_UP[] 	/*PROGMEM*/ =		{0xE0, 0x32};
const uint8_t PS2_SC_MAKE_VOLUME_DOWN[] 	/*PROGMEM*/ =		{0xE0, 0x21};
const uint8_t PS2_SC_MAKE_MEDIA_SELECT[] 	/*PROGMEM*/ =		{0xE0, 0x50};
const uint8_t PS2_SC_MAKE_E_MAIL[] 	/*PROGMEM*/ =		{0xE0, 0x48};
const uint8_t PS2_SC_MAKE_CALCULATOR[] 	/*PROGMEM*/ =		{0xE0, 0x2B};
const uint8_t PS2_SC_MAKE_MY_COMPUTER[] 	/*PROGMEM*/ =		{0xE0, 0x40};
const uint8_t PS2_SC_MAKE_WWW_SEARCH[] 	/*PROGMEM*/ =		{0xE0, 0x10};
const uint8_t PS2_SC_MAKE_WWW_HOME[] 	/*PROGMEM*/ =		{0xE0, 0x3A};
const uint8_t PS2_SC_MAKE_WWW_BACK[] 	/*PROGMEM*/ =		{0xE0, 0x38};
const uint8_t PS2_SC_MAKE_WWW_FORWARD[] 	/*PROGMEM*/ =		{0xE0, 0x30};
const uint8_t PS2_SC_MAKE_WWW_STOP[] 	/*PROGMEM*/ =		{0xE0, 0x28};
const uint8_t PS2_SC_MAKE_WWW_REFRESH[] 	/*PROGMEM*/ =		{0xE0, 0x20};
const uint8_t PS2_SC_MAKE_WWW_FAVORITES[] 	/*PROGMEM*/ =		{0xE0, 0x18};

//ACPI Scan Codes - Make Codes
const uint8_t PS2_SC_MAKE_POWER[] 	/*PROGMEM*/ =		{0xE0,0x37};
const uint8_t PS2_SC_MAKE_SLEEP[] 	/*PROGMEM*/ =		{0xE0,0x3F};
const uint8_t PS2_SC_MAKE_WAKE[] 	/*PROGMEM*/ =		{0xE0,0x5E};


//BREAK Codes 
//Keyboard matrix Line 1 - Break Codes
const uint8_t PS2_SC_BREAK_ESC[] 				= {	0xF0, 0x76 };          
const uint8_t PS2_SC_BREAK_F1[] 	/*PROGMEM*/ =		{0xF0, 0x05};
const uint8_t PS2_SC_BREAK_F2[] 	/*PROGMEM*/ =		{0xF0, 0x06};
const uint8_t PS2_SC_BREAK_F3[] 	/*PROGMEM*/ =		{0xF0, 0x04};
const uint8_t PS2_SC_BREAK_F4[] 	/*PROGMEM*/ =		{0xF0, 0x0C};
const uint8_t PS2_SC_BREAK_F5[] 	/*PROGMEM*/ =		{0xF0, 0x03};
const uint8_t PS2_SC_BREAK_F6[] 	/*PROGMEM*/ =		{0xF0, 0x0B};
const uint8_t PS2_SC_BREAK_F7[] 	/*PROGMEM*/ =		{0xF0, 0x83};
const uint8_t PS2_SC_BREAK_F8[] 	/*PROGMEM*/ =		{0xF0, 0x0A};
const uint8_t PS2_SC_BREAK_F9[] 	/*PROGMEM*/ =		{0xF0, 0x01};
const uint8_t PS2_SC_BREAK_F10[] 	/*PROGMEM*/ =		{0xF0, 0x09};
const uint8_t PS2_SC_BREAK_F11[] 	/*PROGMEM*/ =		{0xF0, 0x78};
const uint8_t PS2_SC_BREAK_F12[] 	/*PROGMEM*/ =		{0xF0, 0x07};
const uint8_t PS2_SC_BREAK_PRINT[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x12,  0xE0,0xF0,0x7C};
//const uint8_t PS2_SC_BREAK_PAUSE     				/*There is NO Break Code for Pause*/
const uint8_t PS2_SC_BREAK_INSERT[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x70};
const uint8_t PS2_SC_BREAK_DELETE[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x71};

//Keyboard matrix Line 2 - Break Codes
const uint8_t PS2_SC_BREAK_TILDE[] 	/*PROGMEM*/ =		{0xF0,0xE0};
const uint8_t PS2_SC_BREAK_1[] 	/*PROGMEM*/ =		{0xF0,0x16};
const uint8_t PS2_SC_BREAK_2[] 	/*PROGMEM*/ =		{0xF0,0x1E};
const uint8_t PS2_SC_BREAK_3[] 	/*PROGMEM*/ =		{0xF0,0x26};
const uint8_t PS2_SC_BREAK_4[] 	/*PROGMEM*/ =		{0xF0,0x25};
const uint8_t PS2_SC_BREAK_5[] 	/*PROGMEM*/ =		{0xF0,0x2E};
const uint8_t PS2_SC_BREAK_6[] 	/*PROGMEM*/ =		{0xF0,0x36};
const uint8_t PS2_SC_BREAK_7[] 	/*PROGMEM*/ =		{0xF0,0x3D};
const uint8_t PS2_SC_BREAK_8[] 	/*PROGMEM*/ =		{0xF0,0x3E};
const uint8_t PS2_SC_BREAK_9[] 	/*PROGMEM*/ =		{0xF0,0x46};
const uint8_t PS2_SC_BREAK_0[] 	/*PROGMEM*/ =		{0xF0,0x45};
const uint8_t PS2_SC_BREAK_QUESTIONMARK[] 	/*PROGMEM*/ =		{0xF0,0x4E};   	
const uint8_t PS2_SC_BREAK_APOS[] 	/*PROGMEM*/ =		{0xF0,0x55};   	
const uint8_t PS2_SC_BREAK_BACKSPACE[] 	/*PROGMEM*/ =		{0xF0,0x66};   	
const uint8_t PS2_SC_BREAK_HOME[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x6C};

//Keyboard matrix Line 3 - Break Codes
const uint8_t PS2_SC_BREAK_TAB[] 	/*PROGMEM*/ =		{0xF0,0x0D};
const uint8_t PS2_SC_BREAK_Q[] 	/*PROGMEM*/ =		{0xF0,0x15};
const uint8_t PS2_SC_BREAK_W[] 	/*PROGMEM*/ =		{0xF0,0x1D};
const uint8_t PS2_SC_BREAK_E[] 	/*PROGMEM*/ =		{0xF0,0x24};
const uint8_t PS2_SC_BREAK_R[] 	/*PROGMEM*/ =		{0xF0,0x2D};
const uint8_t PS2_SC_BREAK_T[] 	/*PROGMEM*/ =		{0xF0,0x2C};
const uint8_t PS2_SC_BREAK_Z[] 	/*PROGMEM*/ =		{0xF0,0x35};
const uint8_t PS2_SC_BREAK_U[] 	/*PROGMEM*/ =		{0xF0,0x3C};
const uint8_t PS2_SC_BREAK_I[] 	/*PROGMEM*/ =		{0xF0,0x43};
const uint8_t PS2_SC_BREAK_O[] 	/*PROGMEM*/ =		{0xF0,0x44};
const uint8_t PS2_SC_BREAK_P[] 	/*PROGMEM*/ =		{0xF0,0x4D};
const uint8_t PS2_SC_BREAK_UE[] 	/*PROGMEM*/ =		{0xF0,0x54};
const uint8_t PS2_SC_BREAK_ASTERISK[] 	/*PROGMEM*/ =		{0xF0,0x5B};
const uint8_t PS2_SC_BREAK_ENTER[] 	/*PROGMEM*/ =		{0xF0,0x5A};
const uint8_t PS2_SC_BREAK_PAGE_UP[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x7D};

//Keyboard matrix Line 4 - Break Codes
const uint8_t PS2_SC_BREAK_CAPS_LOCK[] 	/*PROGMEM*/ =		{0xF0,0x58};
const uint8_t PS2_SC_BREAK_A[] 	/*PROGMEM*/ =		{0xF0,0x1C};
const uint8_t PS2_SC_BREAK_S[] 	/*PROGMEM*/ =		{0xF0,0x1B};
const uint8_t PS2_SC_BREAK_D[] 	/*PROGMEM*/ =		{0xF0,0x23};
const uint8_t PS2_SC_BREAK_F[] 	/*PROGMEM*/ =		{0xF0,0x2B};
const uint8_t PS2_SC_BREAK_G[] 	/*PROGMEM*/ =		{0xF0,0x34};
const uint8_t PS2_SC_BREAK_H[] 	/*PROGMEM*/ =		{0xF0,0x33};
const uint8_t PS2_SC_BREAK_J[] 	/*PROGMEM*/ =		{0xF0,0x38};
const uint8_t PS2_SC_BREAK_K[] 	/*PROGMEM*/ =		{0xF0,0x42};
const uint8_t PS2_SC_BREAK_L[] 	/*PROGMEM*/ =		{0xF0,0x4B};
const uint8_t PS2_SC_BREAK_OE[] 	/*PROGMEM*/ =		{0xF0,0x46};
const uint8_t PS2_SC_BREAK_AE[] 	/*PROGMEM*/ =		{0xF0,0x52};
const uint8_t PS2_SC_BREAK_SHARP[] 	/*PROGMEM*/ =		{0xF0,0x5D};
const uint8_t PS2_SC_BREAK_PAGE_DOWN[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x7A};

//Keyboard matrix Line 5 - Break Codes
const uint8_t PS2_SC_BREAK_SHIFT_L[] 	/*PROGMEM*/ =		{0xF0,0x12};
const uint8_t PS2_SC_BREAK_SMALLER[] 	/*PROGMEM*/ =		{0xF0,0x61};
const uint8_t PS2_SC_BREAK_Y[] 	/*PROGMEM*/ =		{0xF0,0x1A};
const uint8_t PS2_SC_BREAK_X[] 	/*PROGMEM*/ =		{0xF0,0x22};
const uint8_t PS2_SC_BREAK_C[] 	/*PROGMEM*/ =		{0xF0,0x21};
const uint8_t PS2_SC_BREAK_V[] 	/*PROGMEM*/ =		{0xF0,0x2A};
const uint8_t PS2_SC_BREAK_B[] 	/*PROGMEM*/ =		{0xF0,0x32};
const uint8_t PS2_SC_BREAK_N[] 	/*PROGMEM*/ =		{0xF0,0x31};
const uint8_t PS2_SC_BREAK_M[] 	/*PROGMEM*/ =		{0xF0,0x3A};
const uint8_t PS2_SC_BREAK_COMMA[] 	/*PROGMEM*/ =		{0xF0,0x41};
const uint8_t PS2_SC_BREAK_DOT[] 	/*PROGMEM*/ =		{0xF0,0x49};
const uint8_t PS2_SC_BREAK_MINUS[] 	/*PROGMEM*/ =		{0xF0,0x4A};
const uint8_t PS2_SC_BREAK_SHIFT_R[] 	/*PROGMEM*/ =		{0xF0,0x59};
const uint8_t PS2_SC_BREAK_END[] 	/*PROGMEM*/ =		{0xE0,0x69};

//Keyboard matrix Line 6 - Break Codes
const uint8_t PS2_SC_BREAK_CTRL_L[] 	/*PROGMEM*/ =		{0xF0,0x14};
const uint8_t PS2_SC_BREAK_WIN_L[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x1F};
const uint8_t PS2_SC_BREAK_ALT_L[] 	/*PROGMEM*/ =		{0xF0,0x11};
const uint8_t PS2_SC_BREAK_SPACE[] 	/*PROGMEM*/ =		{0xF0,0x29};
const uint8_t PS2_SC_BREAK_ALT_R[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x11};
const uint8_t PS2_SC_BREAK_WIN_R[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x2F};
const uint8_t PS2_SC_BREAK_CTRL_R[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x14};
/* extra € key unused*/				
const uint8_t PS2_SC_BREAK_ARROW_UP[] 	/*PROGMEM*/ =		{0xE0,0x75};	
/* extra $ key unused*/

//Keyboard matrix Line 7 - Break Codes
const uint8_t PS2_SC_BREAK_ARROW_LEFT[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x6B};
const uint8_t PS2_SC_BREAK_ARROW_DOWN[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x72};
const uint8_t PS2_SC_BREAK_ARROW_RIGHT[] 	/*PROGMEM*/ =		{0xE0,0xF0,0x74};
	

//Keyboard matrix Line 1 - Break Codes Byte Count
const uint8_t PS2_SC_BREAK_BYTECOUNT_ESC[] 				= {2};          
const uint8_t PS2_SC_BREAK_BYTECOUNT_F1[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F2[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F3[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F4[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F5[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F6[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F7[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F8[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F9[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F10[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F11[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F12[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_PRINT[] 	/*PROGMEM*/ =		{6};
const uint8_t PS2_SC_BREAK_BYTECOUNT_PAUSE     	/*PROGMEM*/ =		{0};			/*There is NO Break Code for Pause*/
const uint8_t PS2_SC_BREAK_BYTECOUNT_INSERT[] 	/*PROGMEM*/ =		{3};
const uint8_t PS2_SC_BREAK_BYTECOUNT_DELETE[] 	/*PROGMEM*/ =		{3};

//Keyboard matrix Line 2 - Break Codes Byte Count
const uint8_t PS2_SC_BREAK_BYTECOUNT_TILDE[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_1[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_2[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_3[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_4[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_5[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_6[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_7[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_8[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_9[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_0[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_QUESTIONMARK[] 	/*PROGMEM*/ =		{2};   	
const uint8_t PS2_SC_BREAK_BYTECOUNT_APOS[] 	/*PROGMEM*/ =		{2};   	
const uint8_t PS2_SC_BREAK_BYTECOUNT_BACKSPACE[] 	/*PROGMEM*/ =		{2};   	
const uint8_t PS2_SC_BREAK_BYTECOUNT_HOME[] 	/*PROGMEM*/ =		{3};

//Keyboard matrix Line 3 - Break Codes Byte Count
const uint8_t PS2_SC_BREAK_BYTECOUNT_TAB[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_Q[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_W[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_E[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_R[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_T[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_Z[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_U[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_I[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_O[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_P[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_UE[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_ASTERISK[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_ENTER[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_PAGE_UP[] 	/*PROGMEM*/ =		{3};

//Keyboard matrix Line 4 - Break Codes Byte Count
const uint8_t PS2_SC_BREAK_BYTECOUNT_CAPS_LOCK[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_A[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_S[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_D[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_F[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_G[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_H[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_J[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_K[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_L[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_OE[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_AE[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_SHARP[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_PAGE_DOWN[] 	/*PROGMEM*/ =		{3};

//Keyboard matrix Line 5 - Break Codes Byte Count
const uint8_t PS2_SC_BREAK_BYTECOUNT_SHIFT_L[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_SMALLER[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_Y[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_X[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_C[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_V[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_B[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_N[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_M[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_COMMA[] 	/*PROGMEM*/ =	{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_DOT[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_MINUS[] 	/*PROGMEM*/ =	{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_SHIFT_R[] 	/*PROGMEM*/ =	{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_END[] 	/*PROGMEM*/ =		{2};

//Keyboard matrix Line 6 - Break Codes Byte Count
const uint8_t PS2_SC_BREAK_BYTECOUNT_CTRL_L[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_FN[] 	/*PROGMEM*/ =		{0};  //No external communication
const uint8_t PS2_SC_BREAK_BYTECOUNT_WIN_L[] 	/*PROGMEM*/ =		{3};
const uint8_t PS2_SC_BREAK_BYTECOUNT_ALT_L[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_SPACE[] 	/*PROGMEM*/ =		{2};
const uint8_t PS2_SC_BREAK_BYTECOUNT_ALT_R[] 	/*PROGMEM*/ =		{3};
const uint8_t PS2_SC_BREAK_BYTECOUNT_WIN_R[] 	/*PROGMEM*/ =		{3};
const uint8_t PS2_SC_BREAK_BYTECOUNT_CTRL_R[] 	/*PROGMEM*/ =		{3};
const uint8_t PS2_SC_BREAK_BYTECOUNT_EURO[] 	/*PROGMEM*/ =		{0};	/* extra € key currently unused*/
const uint8_t PS2_SC_BREAK_BYTECOUNT_ARROW_UP[] 	/*PROGMEM*/ =		{2};	
const uint8_t PS2_SC_BREAK_BYTECOUNT_DOLLAR[] 	/*PROGMEM*/ =		{0};	/* extra $ key currently unused*/

//Keyboard matrix Line 7 - Break Codes Byte Count
const uint8_t PS2_SC_BREAK_BYTECOUNT_ARROW_LEFT[] 	/*PROGMEM*/ =		{3};
const uint8_t PS2_SC_BREAK_BYTECOUNT_ARROW_DOWN[] 	/*PROGMEM*/ =		{3};
const uint8_t PS2_SC_BREAK_BYTECOUNT_ARROW_RIGHT[] 	/*PROGMEM*/ =		{3};
	

//Multimedia Scan Codes - Break Codes
const uint8_t PS2_SC_BREAK_NEXT_TRACK[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x4D};
const uint8_t PS2_SC_BREAK_PREVIOUS_TRACK[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x15};
const uint8_t PS2_SC_BREAK_STOP[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x3B};
const uint8_t PS2_SC_BREAK_PLAY_PAUSE[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x34};
const uint8_t PS2_SC_BREAK_MUTE[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x23};
const uint8_t PS2_SC_BREAK_VOLUME_UP[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x32};
const uint8_t PS2_SC_BREAK_VOLUME_DOWN[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x21};
const uint8_t PS2_SC_BREAK_MEDIA_SELECT[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x50};
const uint8_t PS2_SC_BREAK_E_MAIL[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x48};
const uint8_t PS2_SC_BREAK_CALCULATOR[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x2B};
const uint8_t PS2_SC_BREAK_MY_COMPUTER[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x40};
const uint8_t PS2_SC_BREAK_WWW_SEARCH[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x10};
const uint8_t PS2_SC_BREAK_WWW_HOME[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x3A};
const uint8_t PS2_SC_BREAK_WWW_BACK[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x38};
const uint8_t PS2_SC_BREAK_WWW_FORWARD[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x30};
const uint8_t PS2_SC_BREAK_WWW_STOP[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x28};
const uint8_t PS2_SC_BREAK_WWW_REFRESH[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x20};
const uint8_t PS2_SC_BREAK_WWW_FAVORITES[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x18};

//ACPI Scan Codes - Break Codes
const uint8_t PS2_SC_BREAK_POWER[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x37};
const uint8_t PS2_SC_BREAK_SLEEP[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x3F};
const uint8_t PS2_SC_BREAK_WAKE[] 	/*PROGMEM*/ =		{0xE0, 0xF0, 0x5E};
