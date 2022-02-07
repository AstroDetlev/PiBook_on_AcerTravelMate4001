/*
 * 2021-12-01
 * 
 * Target System: Arduino Mega2560
 * Arduino IDE: 1.8.14
 * 
*/


#define MATRIX_PINS_COUNT 24
#define MATRIX_KEY_COUNT 89 //0 is the unknown key, the other 89 keys are known



/*
 each key gets its unique number here. There are 89 keys on the keyboard matrix.
 The strange order is the order as used in the matrix. other orders will work, too.
 But if the last button of this array can be used, at least the structures of this sketch are ok.
*/

#define ID_KEY_UNKNOWN 0
#define ID_KEY_F11 1
#define ID_KEY_F12 2
#define ID_KEY_F8  3
#define ID_KEY_Q 4
#define ID_KEY_F4  5
#define ID_KEY_F3  6
#define ID_KEY_F7  7
#define ID_KEY_1 8
#define ID_KEY_ESC 9
#define ID_KEY_TILDE  10
#define ID_KEY_F5  11
#define ID_KEY_TAB 12
#define ID_KEY_F1  13
#define ID_KEY_F2  14
#define ID_KEY_F6  15
#define ID_KEY_CAPS_LOCK 16
#define ID_KEY_F10 17
#define ID_KEY_F9  18
#define ID_KEY_BACKSPACE 19
#define ID_KEY_3 20
#define ID_KEY_2 21
#define ID_KEY_ARROW_UP  22
#define ID_KEY_BREAK 23
#define ID_KEY_PRINT 24
#define ID_KEY_INSERT 25
#define ID_KEY_DELETE 26
#define ID_KEY_HOME 27
#define ID_KEY_PAGE_UP 28
#define ID_KEY_PAGE_DOWN 29
#define ID_KEY_ARROW_RIGHT 30
#define ID_KEY_ARROW_LEFT 31
#define ID_KEY_ARROW_DOWN 32
#define ID_KEY_UE  33
#define ID_KEY_P 34
#define ID_KEY_AE  35
#define ID_KEY_OE  36
#define ID_KEY_MINUS 37
#define ID_KEY_DOT 38
#define ID_KEY_DOLLAR  39
#define ID_KEY_QUESTIONMARK  40
#define ID_KEY_7 41
#define ID_KEY_9 42
#define ID_KEY_5 43
#define ID_KEY_0 44
#define ID_KEY_APOS 45
#define ID_KEY_6 46
#define ID_KEY_8 47
#define ID_KEY_4 48
#define ID_KEY_EURO  49
#define ID_KEY_CTRL_L 50
#define ID_KEY_CTRL_R 51
#define ID_KEY_O 52
#define ID_KEY_ASTERISK  53
#define ID_KEY_T 54
#define ID_KEY_U 55
#define ID_KEY_R 56
#define ID_KEY_W 57
#define ID_KEY_SHIFT_R 58
#define ID_KEY_SHIFT_L 59
#define ID_KEY_I 60
#define ID_KEY_ENTER 61
#define ID_KEY_H 62
#define ID_KEY_Z 63
#define ID_KEY_E 64
#define ID_KEY_S 65
#define ID_KEY_L 66
#define ID_KEY_K 67
#define ID_KEY_M 68
#define ID_KEY_COMMA 69
#define ID_KEY_SHARP 70
#define ID_KEY_END 71
#define ID_KEY_WIN_R 72
#define ID_KEY_G 73
#define ID_KEY_V 74
#define ID_KEY_SPACE 75
#define ID_KEY_C 76
#define ID_KEY_J 77
#define ID_KEY_N 78
#define ID_KEY_B 79
#define ID_KEY_F 80
#define ID_KEY_A 81
#define ID_KEY_D 82
#define ID_KEY_SMALLER 83
#define ID_KEY_X 84
#define ID_KEY_WIN_L 85
#define ID_KEY_ALT_L 86
#define ID_KEY_ALT_R 87
#define ID_KEY_Y 88
#define ID_KEY_FN  89


#define HR_KEY_F11      			"F11"
#define HR_KEY_F12      			"F12"
#define HR_KEY_F8       			"F8"
#define HR_KEY_Q      				"Q"
#define HR_KEY_F4       			"F4"
#define HR_KEY_F3       			"F3"
#define HR_KEY_F7       			"F7"
#define HR_KEY_1      				"1"
#define HR_KEY_ESC      			"ESC"
#define HR_KEY_TILDE       			"^"
#define HR_KEY_F5       			"F5"
#define HR_KEY_TAB      			"Tab"
#define HR_KEY_F1       			"F1"
#define HR_KEY_F2       			"F2"
#define HR_KEY_F6       			"F6"
#define HR_KEY_CAPS_LOCK   			"CAPS_LOCK"
#define HR_KEY_F10      			"F10"
#define HR_KEY_F9       			"F9"
#define HR_KEY_BACKSPACE  			"BackSpace"
#define HR_KEY_3      				"3"
#define HR_KEY_2      				"2"
#define HR_KEY_ARROW_UP       		"Up"
#define HR_KEY_BREAK      			"Break"
#define HR_KEY_PRINT      			"Print"
#define HR_KEY_INSERT      			"Insert"
#define HR_KEY_DELETE      			"Delete"
#define HR_KEY_HOME     			"Pos1"
#define HR_KEY_PAGE_UP     			"PAGE_UP"
#define HR_KEY_PAGE_DOWN   			"PAGE_DOWN"
#define HR_KEY_ARROW_RIGHT      	"Right"
#define HR_KEY_ARROW_LEFT      		"Left"
#define HR_KEY_ARROW_DOWN      		"Down"
#define HR_KEY_UE       			"Ü"
#define HR_KEY_P      				"P"
#define HR_KEY_AE       			"Ä"
#define HR_KEY_OE       			"Ö"
#define HR_KEY_MINUS    			"-"
#define HR_KEY_DOT    				"."
#define HR_KEY_DOLLAR     			"$"
#define HR_KEY_QUESTIONMARK       	"?"
#define HR_KEY_7      				"7"
#define HR_KEY_9      				"9"
#define HR_KEY_5      				"5"
#define HR_KEY_0      				"0"
#define HR_KEY_APOS     			"'"
#define HR_KEY_6      				"6"
#define HR_KEY_8      				"8"
#define HR_KEY_4      				"4"
#define HR_KEY_EURO     			"€"
#define HR_KEY_CTRL_L      			"Ctrl-L"
#define HR_KEY_CTRL_R      			"Ctrl-R"
#define HR_KEY_O      				"O"
#define HR_KEY_ASTERISK   			"*"
#define HR_KEY_T      				"T"
#define HR_KEY_U      				"U"
#define HR_KEY_R      				"R"
#define HR_KEY_W      				"W"
#define HR_KEY_SHIFT_R      		"Shift-R"
#define HR_KEY_SHIFT_L      		"Shift-L"
#define HR_KEY_I      				"I"
#define HR_KEY_ENTER      			"Enter"
#define HR_KEY_H      				"H"
#define HR_KEY_Z      				"Z"
#define HR_KEY_E      				"E"
#define HR_KEY_S      				"S"
#define HR_KEY_L      				"L"
#define HR_KEY_K      				"K"
#define HR_KEY_M      				"M"
#define HR_KEY_COMMA  				","
#define HR_KEY_SHARP    			"#"
#define HR_KEY_END      			"End"
#define HR_KEY_WIN_R      			"Win-R"
#define HR_KEY_G      				"G"
#define HR_KEY_V      				"V"
#define HR_KEY_SPACE      			"Space"
#define HR_KEY_C      				"C"
#define HR_KEY_J      				"J"
#define HR_KEY_N      				"N"
#define HR_KEY_B      				"B"
#define HR_KEY_F      				"F"
#define HR_KEY_A      				"A"
#define HR_KEY_D      				"D"
#define HR_KEY_SMALLER    			"<"
#define HR_KEY_X      				"X"
#define HR_KEY_WIN_L      			"Win-L"
#define HR_KEY_ALT_L      			"Alt"
#define HR_KEY_ALT_R      			"AltGr"
#define HR_KEY_Y      				"Y"
#define HR_KEY_FN       			"Fn"


  /*This is the array that in a way holds the labels of the Keys. If you got the cell content from the Matrix, this is the transformation to a human readable string, just to see
    the keyboard decoder is doing the right things and the wiring is ok.  
  */
const char HumanReadableDecoder[89][10] =
{
//	HR_KEY_UNKNOWN
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

const uint8_t PIN1_KEY_F11 PROGMEM = 1;
const uint8_t PIN1_KEY_F12 PROGMEM = 1;
const uint8_t PIN1_KEY_F8 PROGMEM = 1;
const uint8_t PIN1_KEY_Q PROGMEM = 1;
const uint8_t PIN1_KEY_F4 PROGMEM = 1;
const uint8_t PIN1_KEY_F3 PROGMEM = 1;
const uint8_t PIN1_KEY_F7 PROGMEM = 1;
const uint8_t PIN1_KEY_1 PROGMEM = 1;
const uint8_t PIN1_KEY_ESC PROGMEM = 2;
const uint8_t PIN1_KEY_TILDE PROGMEM = 2;
const uint8_t PIN1_KEY_F5 PROGMEM = 2;
const uint8_t PIN1_KEY_TAB PROGMEM = 2;
const uint8_t PIN1_KEY_F1 PROGMEM = 2;
const uint8_t PIN1_KEY_F2 PROGMEM = 2;
const uint8_t PIN1_KEY_F6 PROGMEM = 2;
const uint8_t PIN1_KEY_CAPS_LOCK PROGMEM = 2;
const uint8_t PIN1_KEY_F10 PROGMEM = 3;
const uint8_t PIN1_KEY_F9 PROGMEM = 3;
const uint8_t PIN1_KEY_BACKSPACE PROGMEM = 3;
const uint8_t PIN1_KEY_3 PROGMEM = 3;
const uint8_t PIN1_KEY_2 PROGMEM = 3;
const uint8_t PIN1_KEY_ARROW_UP PROGMEM = 3;
const uint8_t PIN1_KEY_BREAK PROGMEM = 3;
const uint8_t PIN1_KEY_PRINT PROGMEM = 3;
const uint8_t PIN1_KEY_INSERT PROGMEM = 4;
const uint8_t PIN1_KEY_DELETE PROGMEM = 4;
const uint8_t PIN1_KEY_HOME PROGMEM = 4;
const uint8_t PIN1_KEY_PAGE_UP PROGMEM = 4;
const uint8_t PIN1_KEY_PAGE_DOWN PROGMEM = 4;
const uint8_t PIN1_KEY_ARROW_RIGHT PROGMEM = 4;
const uint8_t PIN1_KEY_ARROW_LEFT PROGMEM = 4;
const uint8_t PIN1_KEY_ARROW_DOWN PROGMEM = 4;
const uint8_t PIN1_KEY_UE PROGMEM = 5;
const uint8_t PIN1_KEY_P PROGMEM = 5;
const uint8_t PIN1_KEY_AE PROGMEM = 5;
const uint8_t PIN1_KEY_OE PROGMEM = 5;
const uint8_t PIN1_KEY_MINUS PROGMEM = 5;
const uint8_t PIN1_KEY_DOT PROGMEM = 5;
const uint8_t PIN1_KEY_DOLLAR PROGMEM = 6;
const uint8_t PIN1_KEY_QUESTIONMARK PROGMEM = 6;
const uint8_t PIN1_KEY_7 PROGMEM = 6;
const uint8_t PIN1_KEY_9 PROGMEM = 6;
const uint8_t PIN1_KEY_5 PROGMEM = 6;
const uint8_t PIN1_KEY_0 PROGMEM = 7;
const uint8_t PIN1_KEY_APOS PROGMEM = 7;
const uint8_t PIN1_KEY_6 PROGMEM = 7;
const uint8_t PIN1_KEY_8 PROGMEM = 7;
const uint8_t PIN1_KEY_4 PROGMEM = 7;
const uint8_t PIN1_KEY_EURO PROGMEM = 8;
const uint8_t PIN1_KEY_CTRL_L PROGMEM = 9;
const uint8_t PIN1_KEY_CTRL_R PROGMEM = 9;
const uint8_t PIN1_KEY_O PROGMEM = 10;
const uint8_t PIN1_KEY_ASTERISK PROGMEM = 10;
const uint8_t PIN1_KEY_T PROGMEM = 10;
const uint8_t PIN1_KEY_U PROGMEM = 10;
const uint8_t PIN1_KEY_R PROGMEM = 10;
const uint8_t PIN1_KEY_W PROGMEM = 10;
const uint8_t PIN1_KEY_SHIFT_R PROGMEM = 11;
const uint8_t PIN1_KEY_SHIFT_L PROGMEM = 11;
const uint8_t PIN1_KEY_I PROGMEM = 12;
const uint8_t PIN1_KEY_ENTER PROGMEM = 12;
const uint8_t PIN1_KEY_H PROGMEM = 12;
const uint8_t PIN1_KEY_Z PROGMEM = 12;
const uint8_t PIN1_KEY_E PROGMEM = 12;
const uint8_t PIN1_KEY_S PROGMEM = 12;
const uint8_t PIN1_KEY_L PROGMEM = 13;
const uint8_t PIN1_KEY_K PROGMEM = 13;
const uint8_t PIN1_KEY_M PROGMEM = 13;
const uint8_t PIN1_KEY_COMMA PROGMEM = 13;
const uint8_t PIN1_KEY_SHARP PROGMEM = 14;
const uint8_t PIN1_KEY_END PROGMEM = 14;
const uint8_t PIN1_KEY_WIN_R PROGMEM = 14;
const uint8_t PIN1_KEY_G PROGMEM = 15;
const uint8_t PIN1_KEY_V PROGMEM = 15;
const uint8_t PIN1_KEY_SPACE PROGMEM = 15;
const uint8_t PIN1_KEY_C PROGMEM = 15;
const uint8_t PIN1_KEY_J PROGMEM = 16;
const uint8_t PIN1_KEY_N PROGMEM = 16;
const uint8_t PIN1_KEY_B PROGMEM = 16;
const uint8_t PIN1_KEY_F PROGMEM = 17;
const uint8_t PIN1_KEY_A PROGMEM = 17;
const uint8_t PIN1_KEY_D PROGMEM = 18;
const uint8_t PIN1_KEY_SMALLER PROGMEM = 18;
const uint8_t PIN1_KEY_X PROGMEM = 18;
const uint8_t PIN1_KEY_WIN_L PROGMEM = 19;
const uint8_t PIN1_KEY_ALT_L PROGMEM = 20;
const uint8_t PIN1_KEY_ALT_R PROGMEM = 20;
const uint8_t PIN1_KEY_Y PROGMEM = 21;
const uint8_t PIN1_KEY_FN PROGMEM = 22;


const uint8_t PIN2_KEY_F11 PROGMEM = 6;  
const uint8_t PIN2_KEY_F12 PROGMEM = 7; 
const uint8_t PIN2_KEY_F8 PROGMEM = 10; 
const uint8_t PIN2_KEY_Q PROGMEM = 12; 
const uint8_t PIN2_KEY_F4 PROGMEM = 17; 
const uint8_t PIN2_KEY_F3 PROGMEM = 21; 
const uint8_t PIN2_KEY_F7 PROGMEM = 23; 
const uint8_t PIN2_KEY_1 PROGMEM = 24; 
const uint8_t PIN2_KEY_ESC PROGMEM = 6;  
const uint8_t PIN2_KEY_TILDE PROGMEM = 7;  
const uint8_t PIN2_KEY_F5 PROGMEM = 10; 
const uint8_t PIN2_KEY_TAB PROGMEM = 12;
const uint8_t PIN2_KEY_F1 PROGMEM = 17;
const uint8_t PIN2_KEY_F2 PROGMEM = 21;
const uint8_t PIN2_KEY_F6 PROGMEM = 23;
const uint8_t PIN2_KEY_CAPS_LOCK PROGMEM = 24;
const uint8_t PIN2_KEY_F10 PROGMEM = 6 ;
const uint8_t PIN2_KEY_F9 PROGMEM = 7 ;
const uint8_t PIN2_KEY_BACKSPACE PROGMEM = 10;
const uint8_t PIN2_KEY_3 PROGMEM = 12;
const uint8_t PIN2_KEY_2 PROGMEM = 17;
const uint8_t PIN2_KEY_ARROW_UP PROGMEM = 21;
const uint8_t PIN2_KEY_BREAK PROGMEM = 23;
const uint8_t PIN2_KEY_PRINT PROGMEM = 24;
const uint8_t PIN2_KEY_INSERT PROGMEM = 6 ;
const uint8_t PIN2_KEY_DELETE PROGMEM = 7 ;
const uint8_t PIN2_KEY_HOME PROGMEM = 10;
const uint8_t PIN2_KEY_PAGE_UP PROGMEM = 12;
const uint8_t PIN2_KEY_PAGE_DOWN PROGMEM = 17;
const uint8_t PIN2_KEY_ARROW_RIGHT PROGMEM = 21;
const uint8_t PIN2_KEY_ARROW_LEFT PROGMEM = 23;
const uint8_t PIN2_KEY_ARROW_DOWN PROGMEM = 24;
const uint8_t PIN2_KEY_UE PROGMEM = 6 ;
const uint8_t PIN2_KEY_P PROGMEM = 7 ;
const uint8_t PIN2_KEY_AE PROGMEM = 10;
const uint8_t PIN2_KEY_OE PROGMEM = 12;
const uint8_t PIN2_KEY_MINUS PROGMEM = 17;
const uint8_t PIN2_KEY_DOT PROGMEM = 21;
const uint8_t PIN2_KEY_DOLLAR PROGMEM = 9 ;
const uint8_t PIN2_KEY_QUESTIONMARK PROGMEM = 13;
const uint8_t PIN2_KEY_7 PROGMEM = 15;
const uint8_t PIN2_KEY_9 PROGMEM = 16;
const uint8_t PIN2_KEY_5 PROGMEM = 18;
const uint8_t PIN2_KEY_0 PROGMEM = 13;
const uint8_t PIN2_KEY_APOS PROGMEM = 14;
const uint8_t PIN2_KEY_6 PROGMEM = 15;
const uint8_t PIN2_KEY_8 PROGMEM = 16;
const uint8_t PIN2_KEY_4 PROGMEM = 18;
const uint8_t PIN2_KEY_EURO PROGMEM = 17;
const uint8_t PIN2_KEY_CTRL_L PROGMEM = 21;
const uint8_t PIN2_KEY_CTRL_R PROGMEM = 23;
const uint8_t PIN2_KEY_O PROGMEM = 13;
const uint8_t PIN2_KEY_ASTERISK PROGMEM = 14;
const uint8_t PIN2_KEY_T PROGMEM = 15;
const uint8_t PIN2_KEY_U PROGMEM = 16;
const uint8_t PIN2_KEY_R PROGMEM = 18;
const uint8_t PIN2_KEY_W PROGMEM = 22;
const uint8_t PIN2_KEY_SHIFT_R PROGMEM = 17;
const uint8_t PIN2_KEY_SHIFT_L PROGMEM = 21;
const uint8_t PIN2_KEY_I PROGMEM = 13;
const uint8_t PIN2_KEY_ENTER PROGMEM = 14;
const uint8_t PIN2_KEY_H PROGMEM = 15;
const uint8_t PIN2_KEY_Z PROGMEM = 16;
const uint8_t PIN2_KEY_E PROGMEM = 18;
const uint8_t PIN2_KEY_S PROGMEM = 22;
const uint8_t PIN2_KEY_L PROGMEM = 17;
const uint8_t PIN2_KEY_K PROGMEM = 21;
const uint8_t PIN2_KEY_M PROGMEM = 23;
const uint8_t PIN2_KEY_COMMA PROGMEM = 24;
const uint8_t PIN2_KEY_SHARP PROGMEM = 17;
const uint8_t PIN2_KEY_END PROGMEM = 21;
const uint8_t PIN2_KEY_WIN_R PROGMEM = 23;
const uint8_t PIN2_KEY_G PROGMEM = 17;
const uint8_t PIN2_KEY_V PROGMEM = 21;
const uint8_t PIN2_KEY_SPACE PROGMEM = 23;
const uint8_t PIN2_KEY_C PROGMEM = 24;
const uint8_t PIN2_KEY_J PROGMEM = 17;
const uint8_t PIN2_KEY_N PROGMEM = 21;
const uint8_t PIN2_KEY_B PROGMEM = 24;
const uint8_t PIN2_KEY_F PROGMEM = 18;
const uint8_t PIN2_KEY_A PROGMEM = 22;
const uint8_t PIN2_KEY_D PROGMEM = 21;
const uint8_t PIN2_KEY_SMALLER PROGMEM = 23;
const uint8_t PIN2_KEY_X PROGMEM = 24;
const uint8_t PIN2_KEY_WIN_L PROGMEM = 23;
const uint8_t PIN2_KEY_ALT_L PROGMEM = 23;
const uint8_t PIN2_KEY_ALT_R PROGMEM = 24;
const uint8_t PIN2_KEY_Y PROGMEM = 22;
const uint8_t PIN2_KEY_FN PROGMEM = 23;

struct detect_pins
{
  uint8_t PinA;
  uint8_t PinB;
};


detect_pins MatrixPins[90] =
{
  {PIN1_KEY_F11        ,PIN2_KEY_F11      }, 
  {PIN1_KEY_F12        ,PIN2_KEY_F12      }, 
  {PIN1_KEY_F8         ,PIN2_KEY_F8       }, 
  {PIN1_KEY_Q          ,PIN2_KEY_Q        }, 
  {PIN1_KEY_F4         ,PIN2_KEY_F4       }, 
  {PIN1_KEY_F3         ,PIN2_KEY_F3       }, 
  {PIN1_KEY_F7         ,PIN2_KEY_F7       }, 
  {PIN1_KEY_1          ,PIN2_KEY_1        }, 
  {PIN1_KEY_ESC        ,PIN2_KEY_ESC      }, 
  {PIN1_KEY_TILDE      ,PIN2_KEY_TILDE    }, 
  {PIN1_KEY_F5         ,PIN2_KEY_F5       }, 
  {PIN1_KEY_TAB        ,PIN2_KEY_TAB      }, 
  {PIN1_KEY_F1         ,PIN2_KEY_F1       }, 
  {PIN1_KEY_F2         ,PIN2_KEY_F2       }, 
  {PIN1_KEY_F6         ,PIN2_KEY_F6       }, 
  {PIN1_KEY_CAPS_LOCK    ,PIN2_KEY_CAPS_LOCK  }, 
  {PIN1_KEY_F10        ,PIN2_KEY_F10      }, 
  {PIN1_KEY_F9         ,PIN2_KEY_F9       }, 
  {PIN1_KEY_BACKSPACE    ,PIN2_KEY_BACKSPACE  }, 
  {PIN1_KEY_3          ,PIN2_KEY_3        }, 
  {PIN1_KEY_2          ,PIN2_KEY_2        }, 
  {PIN1_KEY_ARROW_UP    ,PIN2_KEY_ARROW_UP  }, 
  {PIN1_KEY_BREAK      ,PIN2_KEY_BREAK    }, 
  {PIN1_KEY_PRINT      ,PIN2_KEY_PRINT    }, 
  {PIN1_KEY_INSERT     ,PIN2_KEY_INSERT   }, 
  {PIN1_KEY_DELETE     ,PIN2_KEY_DELETE   }, 
  {PIN1_KEY_HOME       ,PIN2_KEY_HOME     }, 
  {PIN1_KEY_PAGE_UP    ,PIN2_KEY_PAGE_UP  }, 
  {PIN1_KEY_PAGE_DOWN    ,PIN2_KEY_PAGE_DOWN  }, 
  {PIN1_KEY_ARROW_RIGHT    ,PIN2_KEY_ARROW_RIGHT  }, 
  {PIN1_KEY_ARROW_LEFT    ,PIN2_KEY_ARROW_LEFT  }, 
  {PIN1_KEY_ARROW_DOWN    ,PIN2_KEY_ARROW_DOWN  }, 
  {PIN1_KEY_UE         ,PIN2_KEY_UE       }, 
  {PIN1_KEY_P          ,PIN2_KEY_P        }, 
  {PIN1_KEY_AE         ,PIN2_KEY_AE       }, 
  {PIN1_KEY_OE         ,PIN2_KEY_OE       }, 
  {PIN1_KEY_MINUS      ,PIN2_KEY_MINUS    }, 
  {PIN1_KEY_DOT        ,PIN2_KEY_DOT      }, 
  {PIN1_KEY_DOLLAR     ,PIN2_KEY_DOLLAR   }, 
  {PIN1_KEY_QUESTIONMARK    ,PIN2_KEY_QUESTIONMARK  }, 
  {PIN1_KEY_7          ,PIN2_KEY_7        }, 
  {PIN1_KEY_9          ,PIN2_KEY_9        }, 
  {PIN1_KEY_5          ,PIN2_KEY_5        }, 
  {PIN1_KEY_0          ,PIN2_KEY_0        }, 
  {PIN1_KEY_APOS       ,PIN2_KEY_APOS     }, 
  {PIN1_KEY_6          ,PIN2_KEY_6        }, 
  {PIN1_KEY_8          ,PIN2_KEY_8        }, 
  {PIN1_KEY_4          ,PIN2_KEY_4        }, 
  {PIN1_KEY_EURO       ,PIN2_KEY_EURO     }, 
  {PIN1_KEY_CTRL_L     ,PIN2_KEY_CTRL_L   }, 
  {PIN1_KEY_CTRL_R     ,PIN2_KEY_CTRL_R   }, 
  {PIN1_KEY_O          ,PIN2_KEY_O        }, 
  {PIN1_KEY_ASTERISK    ,PIN2_KEY_ASTERISK  }, 
  {PIN1_KEY_T          ,PIN2_KEY_T        }, 
  {PIN1_KEY_U          ,PIN2_KEY_U        }, 
  {PIN1_KEY_R          ,PIN2_KEY_R        }, 
  {PIN1_KEY_W          ,PIN2_KEY_W        }, 
  {PIN1_KEY_SHIFT_R    ,PIN2_KEY_SHIFT_R  }, 
  {PIN1_KEY_SHIFT_L    ,PIN2_KEY_SHIFT_L  }, 
  {PIN1_KEY_I          ,PIN2_KEY_I        }, 
  {PIN1_KEY_ENTER      ,PIN2_KEY_ENTER    }, 
  {PIN1_KEY_H          ,PIN2_KEY_H        }, 
  {PIN1_KEY_Z          ,PIN2_KEY_Z        }, 
  {PIN1_KEY_E          ,PIN2_KEY_E        }, 
  {PIN1_KEY_S          ,PIN2_KEY_S        }, 
  {PIN1_KEY_L          ,PIN2_KEY_L        }, 
  {PIN1_KEY_K          ,PIN2_KEY_K        }, 
  {PIN1_KEY_M          ,PIN2_KEY_M        }, 
  {PIN1_KEY_COMMA      ,PIN2_KEY_COMMA    }, 
  {PIN1_KEY_SHARP      ,PIN2_KEY_SHARP    }, 
  {PIN1_KEY_END        ,PIN2_KEY_END      }, 
  {PIN1_KEY_WIN_R      ,PIN2_KEY_WIN_R    }, 
  {PIN1_KEY_G          ,PIN2_KEY_G        }, 
  {PIN1_KEY_V          ,PIN2_KEY_V        }, 
  {PIN1_KEY_SPACE      ,PIN2_KEY_SPACE    }, 
  {PIN1_KEY_C          ,PIN2_KEY_C        }, 
  {PIN1_KEY_J          ,PIN2_KEY_J        }, 
  {PIN1_KEY_N          ,PIN2_KEY_N        }, 
  {PIN1_KEY_B          ,PIN2_KEY_B        }, 
  {PIN1_KEY_F          ,PIN2_KEY_F        }, 
  {PIN1_KEY_A          ,PIN2_KEY_A        }, 
  {PIN1_KEY_D          ,PIN2_KEY_D        }, 
  {PIN1_KEY_SMALLER    ,PIN2_KEY_SMALLER  }, 
  {PIN1_KEY_X          ,PIN2_KEY_X        }, 
  {PIN1_KEY_WIN_L      ,PIN2_KEY_WIN_L    }, 
  {PIN1_KEY_ALT_L      ,PIN2_KEY_ALT_L    }, 
  {PIN1_KEY_ALT_R      ,PIN1_KEY_ALT_R    }, 
  {PIN1_KEY_Y          ,PIN1_KEY_Y        },
  {PIN1_KEY_FN         ,PIN1_KEY_FN     }  
};

/* 
	############# PS2 Stuff (unfinished) ##############
	https://de.wikipedia.org/wiki/PS/2-Schnittstelle
	http://www.winfaq.de/faq_html/Content/tip1500/onlinefaq.php?h=tip1576.htm
*/


//This is Scan Code Set 2
//PS2 Communication Host to Keyboard
#define PS2_H2K_RESET 							0xFF
#define PS2_H2K_SET_ALL_KEY_TYPEMATIC 			0xF7
#define PS2_H2K_SET_DEFAULT 					0xF6
#define PS2_H2K_DISABLE 						0xF5
#define PS2_H2K_ENABLE 							0xF4
#define PS2_H2K_SET_RATE_DELAY					0xF3
#define PS2_H2K_READ_KEYBOARD_ID				0xF2
#define PS2_H2K_SET_SCANCODE 					0xF0
#define PS2_H2K_SCAN_CODE_REQUEST				0x00
#define PS2_H2K_SCAN_CODE_SET_1					0x01
#define PS2_H2K_SCAN_CODE_SET_2					0x02
#define PS2_H2K_SCAN_CODE_SET_3					0x03
#define PS2_H2K_ECHO							0xEE
#define PS2_H2K_SET_RESET_LEDS					0xED
#define PS2_H2K_LED_CAPS_LOCK					0x04
#define PS2_H2K_LED_NUM_LOCK					0x02
#define PS2_H2K_LED_SCROLL_LOCK					0x01

//PS2 Communication Keyboard to Host
#define PS2_K2H_SELFTEST_OK						0xAA
#define PS2_K2H_ACKNOWLEDGE 					0xFA
#define PS2_K2H_RESEND 							0xFE
#define PS2_K2H_KEYBOARD_ID						0xAB, 0x83
			
//Keyboard matrix Line 1 - Make Codes
#define PS2_SC_MAKE_ESC 						0x76          
#define PS2_SC_MAKE_F1       					0x05
#define PS2_SC_MAKE_F2       					0x06
#define PS2_SC_MAKE_F3       					0x04
#define PS2_SC_MAKE_F4       					0x0C
#define PS2_SC_MAKE_F5       					0x03
#define PS2_SC_MAKE_F6       					0x0B
#define PS2_SC_MAKE_F7       					0x83
#define PS2_SC_MAKE_F8       					0x0A
#define PS2_SC_MAKE_F9       					0x01
#define PS2_SC_MAKE_F10      					0x09
#define PS2_SC_MAKE_F11      					0x78
#define PS2_SC_MAKE_F12      					0x07
#define PS2_SC_MAKE_PRINT     				0xE0,0x12,  0xE0,0x7C
#define PS2_SC_MAKE_PAUSE     				0xE1,0x14,0x77,  0xE1,0xF0,0x14,  0xF0,0x77
#define PS2_SC_MAKE_INSERT    				0xE0,0x70
#define PS2_SC_MAKE_DELETE    				0xE0,0x71

//Keyboard matrix Line 2 - Make Codes
#define PS2_SC_MAKE_TILDE    					0xE0
#define PS2_SC_MAKE_1							0x16
#define PS2_SC_MAKE_2    						0x1E
#define PS2_SC_MAKE_3    						0x26
#define PS2_SC_MAKE_4    						0x25
#define PS2_SC_MAKE_5    						0x2E
#define PS2_SC_MAKE_6    						0x36
#define PS2_SC_MAKE_7    						0x3D
#define PS2_SC_MAKE_8    						0x3E
#define PS2_SC_MAKE_9    						0x46
#define PS2_SC_MAKE_0    						0x45
#define PS2_SC_MAKE_QUESTIONMARK 				0x4E    	
#define PS2_SC_MAKE_APOS 						0x55    	
#define PS2_SC_MAKE_BACKSPACE 				0x66    	
#define PS2_SC_MAKE_HOME      				0xE0,0x6C

//Keyboard matrix Line 3 - Make Codes
#define PS2_SC_MAKE_TAB    					0x0D
#define PS2_SC_MAKE_Q      					0x15
#define PS2_SC_MAKE_W      					0x1D
#define PS2_SC_MAKE_E      					0x24
#define PS2_SC_MAKE_R      					0x2D
#define PS2_SC_MAKE_T      					0x2C
#define PS2_SC_MAKE_Z      					0x35
#define PS2_SC_MAKE_U      					0x3C
#define PS2_SC_MAKE_I      					0x43
#define PS2_SC_MAKE_O      					0x44
#define PS2_SC_MAKE_P      					0x4D
#define PS2_SC_MAKE_UE     					0x54
#define PS2_SC_MAKE_ASTERISK     				0x5B
#define PS2_SC_MAKE_ENTER     				0x5A
#define PS2_SC_MAKE_PAGE_UP     				0xE0,0x7D

//Keyboard matrix Line 4 - Make Codes
#define PS2_SC_MAKE_CAPS_LOCK 					0x58
#define PS2_SC_MAKE_A         				0x1C
#define PS2_SC_MAKE_S         				0x1B
#define PS2_SC_MAKE_D         				0x23
#define PS2_SC_MAKE_F         				0x2B
#define PS2_SC_MAKE_G         				0x34
#define PS2_SC_MAKE_H         				0x33
#define PS2_SC_MAKE_J         				0x3B
#define PS2_SC_MAKE_K         				0x42
#define PS2_SC_MAKE_L         				0x4B
#define PS2_SC_MAKE_OE        				0x4C
#define PS2_SC_MAKE_AE        				0x52
#define PS2_SC_MAKE_SHARP     				0x5D
#define PS2_SC_MAKE_PAGE_DOWN     				0xE0,0x7A

//Keyboard matrix Line 5 - Make Codes
#define PS2_SC_MAKE_SHIFT_L    				0x12
#define PS2_SC_MAKE_SMALLER   				0x61
#define PS2_SC_MAKE_Y         				0x1A
#define PS2_SC_MAKE_X         				0x22
#define PS2_SC_MAKE_C         				0x21
#define PS2_SC_MAKE_V         				0x2A
#define PS2_SC_MAKE_B         				0x32
#define PS2_SC_MAKE_N         				0x31
#define PS2_SC_MAKE_M         				0x3A
#define PS2_SC_MAKE_COMMA     				0x41
#define PS2_SC_MAKE_DOT       				0x49
#define PS2_SC_MAKE_MINUS     				0x4A
#define PS2_SC_MAKE_SHIFT_R    				0x59
#define PS2_SC_MAKE_END       				0xE0,0x69

//Keyboard matrix Line 6 - Make Codes
#define PS2_SC_MAKE_CTRL_L    				0x14
#define PS2_SC_MAKE_WIN_L     				0xE0,0x1F
#define PS2_SC_MAKE_ALT_L     				0x11
#define PS2_SC_MAKE_SPACE     				0x29
#define PS2_SC_MAKE_ALT_R     				0xE0,0x11
#define PS2_SC_MAKE_WIN_R     				0xE0,0x2F
#define PS2_SC_MAKE_CTRL_R    				0xE0,0x14
/* extra € key unused*/				
#define PS2_SC_MAKE_ARROW_UP   				0xE0,0x75	
/* extra $ key unused*/

//Keyboard matrix Line 7 - Make Codes
#define PS2_SC_MAKE_ARROW_LEFT    				0xE0,0x6B
#define PS2_SC_MAKE_ARROW_DOWN    				0xE0,0x72
#define PS2_SC_MAKE_ARROW_RIGHT    				0xE0,0x74
	

//Multimedia Scan Codes - Make Codes
#define PS2_SC_MAKE_NEXT_TRACK 				0xE0, 0x4D
#define PS2_SC_MAKE_PREVIOUS_TRACK 			0xE0, 0x15
#define PS2_SC_MAKE_STOP 					0xE0, 0x3B
#define PS2_SC_MAKE_PLAY_PAUSE 				0xE0, 0x34
#define PS2_SC_MAKE_MUTE 					0xE0, 0x23
#define PS2_SC_MAKE_VOLUME_UP 				0xE0, 0x32
#define PS2_SC_MAKE_VOLUME_DOWN 			0xE0, 0x21
#define PS2_SC_MAKE_MEDIA_SELECT 			0xE0, 0x50
#define PS2_SC_MAKE_E_MAIL 					0xE0, 0x48
#define PS2_SC_MAKE_CALCULATOR 				0xE0, 0x2B
#define PS2_SC_MAKE_MY_COMPUTER 			0xE0, 0x40
#define PS2_SC_MAKE_WWW_SEARCH 				0xE0, 0x10
#define PS2_SC_MAKE_WWW_HOME 				0xE0, 0x3A
#define PS2_SC_MAKE_WWW_BACK 				0xE0, 0x38
#define PS2_SC_MAKE_WWW_FORWARD 			0xE0, 0x30
#define PS2_SC_MAKE_WWW_STOP 				0xE0, 0x28
#define PS2_SC_MAKE_WWW_REFRESH 			0xE0, 0x20
#define PS2_SC_MAKE_WWW_FAVORITES 			0xE0, 0x18

//ACPI Scan Codes - Make Codes
#define PS2_SC_MAKE_POWER 					0xE0,0x37
#define PS2_SC_MAKE_SLEEP 					0xE0,0x3F
#define PS2_SC_MAKE_WAKE 					0xE0,0x5E


//BREAK Codes 
//Keyboard matrix Line 1 - Break Codes
#define PS2_SC_BREAK_ESC 						0xF0, 0x76          
#define PS2_SC_BREAK_F1       				0xF0, 0x05
#define PS2_SC_BREAK_F2       				0xF0, 0x06
#define PS2_SC_BREAK_F3       				0xF0, 0x04
#define PS2_SC_BREAK_F4       				0xF0, 0x0C
#define PS2_SC_BREAK_F5       				0xF0, 0x03
#define PS2_SC_BREAK_F6       				0xF0, 0x0B
#define PS2_SC_BREAK_F7       				0xF0, 0x83
#define PS2_SC_BREAK_F8       				0xF0, 0x0A
#define PS2_SC_BREAK_F9       				0xF0, 0x01
#define PS2_SC_BREAK_F10      				0xF0, 0x09
#define PS2_SC_BREAK_F11      				0xF078
#define PS2_SC_BREAK_F12      				0xF0, 0x07
#define PS2_SC_BREAK_PRINT     				0xE0,0xF0,0x12,  0xE0,0xF0,0x7C
#define PS2_SC_BREAK_PAUSE     				/*There is NO Break Code for Pause*/
#define PS2_SC_BREAK_INSERT    				0xE0,0xF0,0x70
#define PS2_SC_BREAK_DELETE    				0xE0,0xF0,0x71

//Keyboard matrix Line 2 - Break Codes
#define PS2_SC_BREAK_TILDE    					0xF0,0xE0
#define PS2_SC_BREAK_1							0xF0,0x16
#define PS2_SC_BREAK_2    						0xF0,0x1E
#define PS2_SC_BREAK_3    						0xF0,0x26
#define PS2_SC_BREAK_4    						0xF0,0x25
#define PS2_SC_BREAK_5    						0xF0,0x2E
#define PS2_SC_BREAK_6    						0xF0,0x36
#define PS2_SC_BREAK_7    						0xF0,0x3D
#define PS2_SC_BREAK_8    						0xF0,0x3E
#define PS2_SC_BREAK_9    						0xF0,0x46
#define PS2_SC_BREAK_0    						0xF0,0x45
#define PS2_SC_BREAK_QUESTIONMARK 				0xF0,0x4E    	
#define PS2_SC_BREAK_APOS 						0xF0,0x55    	
#define PS2_SC_BREAK_BACKSPACE 					0xF0,0x66    	
#define PS2_SC_BREAK_HOME      					0xE0,0xF0,0x6C

//Keyboard matrix Line 3 - Break Codes
#define PS2_SC_BREAK_TAB    					0xF0,0x0D
#define PS2_SC_BREAK_Q      					0xF0,0x15
#define PS2_SC_BREAK_W      					0xF0,0x1D
#define PS2_SC_BREAK_E      					0xF0,0x24
#define PS2_SC_BREAK_R      					0xF0,0x2D
#define PS2_SC_BREAK_T      					0xF0,0x2C
#define PS2_SC_BREAK_Z      					0xF0,0x35
#define PS2_SC_BREAK_U      					0xF0,0x3C
#define PS2_SC_BREAK_I      					0xF0,0x43
#define PS2_SC_BREAK_O      					0xF0,0x44
#define PS2_SC_BREAK_P      					0xF0,0x4D
#define PS2_SC_BREAK_UE     					0xF0,0x54
#define PS2_SC_BREAK_ASTERISK     				0xF0,0x5B
#define PS2_SC_BREAK_ENTER     					0xF0,0x5A
#define PS2_SC_BREAK_PAGE_UP     				0xE0,0xF0,0x7D

//Keyboard matrix Line 4 - Break Codes
#define PS2_SC_BREAK_CAPS_LOCK 				0xF0,0x58
#define PS2_SC_BREAK_A         				0xF0,0x1C
#define PS2_SC_BREAK_S         				0xF0,0x1B
#define PS2_SC_BREAK_D         				0xF0,0x23
#define PS2_SC_BREAK_F         				0xF0,0x2B
#define PS2_SC_BREAK_G         				0xF0,0x34
#define PS2_SC_BREAK_H         				0xF0,0x33
#define PS2_SC_BREAK_J         				0xF0,0x38
#define PS2_SC_BREAK_K         				0xF0,0x42
#define PS2_SC_BREAK_L         				0xF0,0x4B
#define PS2_SC_BREAK_OE        				0xF0,0x46
#define PS2_SC_BREAK_AE        				0xF0,0x52
#define PS2_SC_BREAK_SHARP     				0xF0,0x5D
#define PS2_SC_BREAK_PAGE_DOWN     			0xE0,0xF0,0x7A

//Keyboard matrix Line 5 - Break Codes
#define PS2_SC_BREAK_SHIFT_L    				0xF0,0x12
#define PS2_SC_BREAK_SMALLER   				0xF0,0x61
#define PS2_SC_BREAK_Y         				0xF0,0x1A
#define PS2_SC_BREAK_X         				0xF0,0x22
#define PS2_SC_BREAK_C         				0xF0,0x21
#define PS2_SC_BREAK_V         				0xF0,0x2A
#define PS2_SC_BREAK_B         				0xF0,0x32
#define PS2_SC_BREAK_N         				0xF0,0x31
#define PS2_SC_BREAK_M         				0xF0,0x3A
#define PS2_SC_BREAK_COMMA     				0xF0,0x41
#define PS2_SC_BREAK_DOT       				0xF0,0x49
#define PS2_SC_BREAK_MINUS     				0xF0,0x4A
#define PS2_SC_BREAK_SHIFT_R    				0xF0,0x59
#define PS2_SC_BREAK_END       				0xE0,0x69

//Keyboard matrix Line 6 - Break Codes
#define PS2_SC_BREAK_CTRL_L    				0xF0,0x14
#define PS2_SC_BREAK_WIN_L     				0xE0,0xF0,0x1F
#define PS2_SC_BREAK_ALT_L     				0xF0,0x11
#define PS2_SC_BREAK_SPACE     				0xF0,0x29
#define PS2_SC_BREAK_ALT_R     				0xE0,0xF0,0x11
#define PS2_SC_BREAK_WIN_R     				0xE0,0xF0,0x2F
#define PS2_SC_BREAK_CTRL_R    				0xE0,0xF0,0x14
/* extra € key unused*/				
#define PS2_SC_BREAK_ARROW_UP   				0xE0,0x75	
/* extra $ key unused*/

//Keyboard matrix Line 7 - Break Codes
#define PS2_SC_BREAK_ARROW_LEFT    				0xE0,0xF0,0x6B
#define PS2_SC_BREAK_ARROW_DOWN    				0xE0,0xF0,0x72
#define PS2_SC_BREAK_ARROW_RIGHT    				0xE0,0xF0,0x74
	

//Multimedia Scan Codes - Break Codes
#define PS2_SC_BREAK_NEXT_TRACK 				0xE0, 0xF0, 0x4D
#define PS2_SC_BREAK_PREVIOUS_TRACK 			0xE0, 0xF0, 0x15
#define PS2_SC_BREAK_STOP 					0xE0, 0xF0, 0x3B
#define PS2_SC_BREAK_PLAY_PAUSE 				0xE0, 0xF0, 0x34
#define PS2_SC_BREAK_MUTE 					0xE0, 0xF0, 0x23
#define PS2_SC_BREAK_VOLUME_UP 				0xE0, 0xF0, 0x32
#define PS2_SC_BREAK_VOLUME_DOWN 				0xE0, 0xF0, 0x21
#define PS2_SC_BREAK_MEDIA_SELECT 			0xE0, 0xF0, 0x50
#define PS2_SC_BREAK_E_MAIL 					0xE0, 0xF0, 0x48
#define PS2_SC_BREAK_CALCULATOR 				0xE0, 0xF0, 0x2B
#define PS2_SC_BREAK_MY_COMPUTER 				0xE0, 0xF0, 0x40
#define PS2_SC_BREAK_WWW_SEARCH 				0xE0, 0xF0, 0x10
#define PS2_SC_BREAK_WWW_HOME 				0xE0, 0xF0, 0x3A
#define PS2_SC_BREAK_WWW_BACK 				0xE0, 0xF0, 0x38
#define PS2_SC_BREAK_WWW_FORWARD 				0xE0, 0xF0, 0x30
#define PS2_SC_BREAK_WWW_STOP 				0xE0, 0xF0, 0x28
#define PS2_SC_BREAK_WWW_REFRESH 				0xE0, 0xF0, 0x20
#define PS2_SC_BREAK_WWW_FAVORITES 			0xE0, 0xF0, 0x18

//ACPI Scan Codes - Break Codes
#define PS2_SC_BREAK_POWER 					0xE0, 0xF0, 0x37
#define PS2_SC_BREAK_SLEEP 					0xE0, 0xF0, 0x3F
#define PS2_SC_BREAK_WAKE 					0xE0, 0xF0, 0x5E
