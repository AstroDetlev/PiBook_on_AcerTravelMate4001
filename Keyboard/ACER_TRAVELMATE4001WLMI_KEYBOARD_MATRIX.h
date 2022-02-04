/*
 * 2021-12-01
 * 
 * Target System: Arduino Mega2560
 * Arduino IDE: 1.8.14
 * 
*/

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

#define HR_KEY_UNKNOWN      "[???]"
#define HR_KEY_F11      "F11"
#define HR_KEY_F12      "F12"
#define HR_KEY_F8       "F8"
#define HR_KEY_Q      "Q"
#define HR_KEY_F4       "F4"
#define HR_KEY_F3       "F3"
#define HR_KEY_F7       "F7"
#define HR_KEY_1      "1"
#define HR_KEY_ESC      "ESC"
#define HR_KEY_TILDE       "^"
#define HR_KEY_F5       "F5"
#define HR_KEY_TAB      "Tab"
#define HR_KEY_F1       "F1"
#define HR_KEY_F2       "F2"
#define HR_KEY_F6       "F6"
#define HR_KEY_CAPS_LOCK   "CAPS_LOCK"
#define HR_KEY_F10      "F10"
#define HR_KEY_F9       "F9"
#define HR_KEY_BACKSPACE  "BackSpace"
#define HR_KEY_3      "3"
#define HR_KEY_2      "2"
#define HR_KEY_ARROW_UP       "Up"
#define HR_KEY_BREAK      "Break"
#define HR_KEY_PRINT      "Print"
#define HR_KEY_INSERT      "Insert"
#define HR_KEY_DELETE      "Delete"
#define HR_KEY_HOME     "Pos1"
#define HR_KEY_PAGE_UP     "PAGE_UP"
#define HR_KEY_PAGE_DOWN   "PAGE_DOWN"
#define HR_KEY_ARROW_RIGHT      "Right"
#define HR_KEY_ARROW_LEFT      "Left"
#define HR_KEY_ARROW_DOWN      "Down"
#define HR_KEY_UE       "Ü"
#define HR_KEY_P      "P"
#define HR_KEY_AE       "Ä"
#define HR_KEY_OE       "Ö"
#define HR_KEY_MINUS    "_"
#define HR_KEY_DOT    "."
#define HR_KEY_DOLLAR     "$"
#define HR_KEY_QUESTIONMARK       "?"
#define HR_KEY_7      "7"
#define HR_KEY_9      "9"
#define HR_KEY_5      "5"
#define HR_KEY_0      "0"
#define HR_KEY_APOS     "'"
#define HR_KEY_6      "6"
#define HR_KEY_8      "8"
#define HR_KEY_4      "4"
#define HR_KEY_EURO     "€"
#define HR_KEY_CTRL_L      "Ctrl-L"
#define HR_KEY_CTRL_R      "Ctrl-R"
#define HR_KEY_O      "O"
#define HR_KEY_ASTERISK   "*"
#define HR_KEY_T      "T"
#define HR_KEY_U      "U"
#define HR_KEY_R      "R"
#define HR_KEY_W      "W"
#define HR_KEY_SHIFT_R      "Shift-R"
#define HR_KEY_SHIFT_L      "Shift-L"
#define HR_KEY_I      "I"
#define HR_KEY_ENTER      "Enter"
#define HR_KEY_H      "H"
#define HR_KEY_Z      "Z"
#define HR_KEY_E      "E"
#define HR_KEY_S      "S"
#define HR_KEY_L      "L"
#define HR_KEY_K      "K"
#define HR_KEY_M      "M"
#define HR_KEY_COMMA  ","
#define HR_KEY_SHARP    "#"
#define HR_KEY_END      "End"
#define HR_KEY_WIN_R      "Win-R"
#define HR_KEY_G      "G"
#define HR_KEY_V      "V"
#define HR_KEY_SPACE      "Space"
#define HR_KEY_C      "C"
#define HR_KEY_J      "J"
#define HR_KEY_N      "N"
#define HR_KEY_B      "B"
#define HR_KEY_F      "F"
#define HR_KEY_A      "A"
#define HR_KEY_D      "D"
#define HR_KEY_SMALLER    "<"
#define HR_KEY_X      "X"
#define HR_KEY_WIN_L      "Win-L"
#define HR_KEY_ALT_L      "Alt"
#define HR_KEY_ALT_R      "AltGr"
#define HR_KEY_Y      "Y"
#define HR_KEY_FN       "Fn"

/*1/x*/
#define MATRLINE_1 \
/*1/1 */ ID_KEY_UNKNOWN,\
/*1/2 */ ID_KEY_UNKNOWN,\
/*1/3 */ ID_KEY_UNKNOWN,\
/*1/4 */ ID_KEY_UNKNOWN,\
/*1/5 */ ID_KEY_UNKNOWN,\
/*1/6 */ ID_KEY_F11,\
/*1/7 */ ID_KEY_F12,\
/*1/8 */ ID_KEY_UNKNOWN,\
/*1/9 */ ID_KEY_UNKNOWN,\
/*1/10*/ ID_KEY_F8,\
/*1/11*/ ID_KEY_UNKNOWN,\
/*1/12*/ ID_KEY_Q,\
/*1/13*/ ID_KEY_UNKNOWN,\
/*1/14*/ ID_KEY_UNKNOWN,\
/*1/15*/ ID_KEY_UNKNOWN,\
/*1/16*/ ID_KEY_UNKNOWN,\
/*1/17*/ ID_KEY_F4,\
/*1/18*/ ID_KEY_UNKNOWN,\
/*1/19*/ ID_KEY_UNKNOWN,\
/*1/20*/ ID_KEY_UNKNOWN,\
/*1/21*/ ID_KEY_F3,\
/*1/22*/ ID_KEY_UNKNOWN,\
/*1/23*/ ID_KEY_F7,\
/*1/24*/ ID_KEY_1

#define MATRLINE_2 \
/*2/1 */ ID_KEY_UNKNOWN,\
/*2/2 */ ID_KEY_UNKNOWN,\
/*2/3 */ ID_KEY_UNKNOWN,\
/*2/4 */ ID_KEY_UNKNOWN,\
/*2/5 */ ID_KEY_UNKNOWN,\
/*2/6 */ ID_KEY_ESC,\
/*2/7 */ ID_KEY_TILDE,\
/*2/8 */ ID_KEY_UNKNOWN,\
/*2/9 */ ID_KEY_UNKNOWN,\
/*2/10*/ ID_KEY_F5,\
/*2/11*/ ID_KEY_UNKNOWN,\
/*2/12*/ ID_KEY_TAB,\
/*2/13*/ ID_KEY_UNKNOWN,\
/*2/14*/ ID_KEY_UNKNOWN,\
/*2/15*/ ID_KEY_UNKNOWN,\
/*2/16*/ ID_KEY_UNKNOWN,\
/*2/17*/ ID_KEY_F1,\
/*2/18*/ ID_KEY_UNKNOWN,\
/*2/19*/ ID_KEY_UNKNOWN,\
/*2/20*/ ID_KEY_UNKNOWN,\
/*2/21*/ ID_KEY_F2,\
/*2/22*/ ID_KEY_UNKNOWN,\
/*2/23*/ ID_KEY_F6,\
/*2/24*/ ID_KEY_CAPS_LOCK

#define MATRLINE_3 \
/*3/1 */ ID_KEY_UNKNOWN,\
/*3/2 */ ID_KEY_UNKNOWN,\
/*3/3 */ ID_KEY_UNKNOWN,\
/*3/4 */ ID_KEY_UNKNOWN,\
/*3/5 */ ID_KEY_UNKNOWN,\
/*3/6 */ ID_KEY_F10,\
/*3/7 */ ID_KEY_F9,\
/*3/8 */ ID_KEY_UNKNOWN,\
/*3/9 */ ID_KEY_UNKNOWN,\
/*3/10*/ ID_KEY_BACKSPACE,\
/*3/11*/ ID_KEY_UNKNOWN,\
/*3/12*/ ID_KEY_3,\
/*3/13*/ ID_KEY_UNKNOWN,\
/*3/14*/ ID_KEY_UNKNOWN,\
/*3/15*/ ID_KEY_UNKNOWN,\
/*3/16*/ ID_KEY_UNKNOWN,\
/*3/17*/ ID_KEY_2,\
/*3/18*/ ID_KEY_UNKNOWN,\
/*3/19*/ ID_KEY_UNKNOWN,\
/*3/20*/ ID_KEY_UNKNOWN,\
/*3/21*/ ID_KEY_ARROW_UP,\
/*3/22*/ ID_KEY_UNKNOWN,\
/*3/23*/ ID_KEY_BREAK,\
/*3/24*/ ID_KEY_PRINT

#define MATRLINE_4 \
/*4/1 */ ID_KEY_UNKNOWN,\
/*4/2 */ ID_KEY_UNKNOWN,\
/*4/3 */ ID_KEY_UNKNOWN,\
/*4/4 */ ID_KEY_UNKNOWN,\
/*4/5 */ ID_KEY_UNKNOWN,\
/*4/6 */ ID_KEY_INSERT,\
/*4/7 */ ID_KEY_DELETE,\
/*4/8 */ ID_KEY_UNKNOWN,\
/*4/9 */ ID_KEY_UNKNOWN,\
/*4/10*/ ID_KEY_HOME,\
/*4/11*/ ID_KEY_UNKNOWN,\
/*4/12*/ ID_KEY_PAGE_UP,\
/*4/13*/ ID_KEY_UNKNOWN,\
/*4/14*/ ID_KEY_UNKNOWN,\
/*4/15*/ ID_KEY_UNKNOWN,\
/*4/16*/ ID_KEY_UNKNOWN,\
/*4/17*/ ID_KEY_PAGE_DOWN,\
/*4/18*/ ID_KEY_UNKNOWN,\
/*4/19*/ ID_KEY_UNKNOWN,\
/*4/20*/ ID_KEY_UNKNOWN,\
/*4/21*/ ID_KEY_ARROW_RIGHT,\
/*4/22*/ ID_KEY_UNKNOWN,\
/*4/23*/ ID_KEY_ARROW_LEFT,\
/*4/24*/ ID_KEY_ARROW_DOWN

#define MATRLINE_5 \
/*5/1 */ ID_KEY_UNKNOWN,\
/*5/2 */ ID_KEY_UNKNOWN,\
/*5/3 */ ID_KEY_UNKNOWN,\
/*5/4 */ ID_KEY_UNKNOWN,\
/*5/5 */ ID_KEY_UNKNOWN,\
/*5/6 */ ID_KEY_UE,\
/*5/7 */ ID_KEY_P,\
/*5/8 */ ID_KEY_UNKNOWN,\
/*5/9 */ ID_KEY_UNKNOWN,\
/*5/10*/ ID_KEY_AE,\
/*5/11*/ ID_KEY_UNKNOWN,\
/*5/12*/ ID_KEY_OE,\
/*5/13*/ ID_KEY_UNKNOWN,\
/*5/14*/ ID_KEY_UNKNOWN,\
/*5/15*/ ID_KEY_UNKNOWN,\
/*5/16*/ ID_KEY_UNKNOWN,\
/*5/17*/ ID_KEY_MINUS,\
/*5/18*/ ID_KEY_UNKNOWN,\
/*5/19*/ ID_KEY_UNKNOWN,\
/*5/20*/ ID_KEY_UNKNOWN,\
/*5/21*/ ID_KEY_DOT,\
/*5/22*/ ID_KEY_UNKNOWN,\
/*5/23*/ ID_KEY_UNKNOWN,\
/*5/24*/ ID_KEY_UNKNOWN

#define MATRLINE_6 \
/*6/1 */ ID_KEY_UNKNOWN,\
/*6/2 */ ID_KEY_UNKNOWN,\
/*6/3 */ ID_KEY_UNKNOWN,\
/*6/4 */ ID_KEY_UNKNOWN,\
/*6/5 */ ID_KEY_UNKNOWN,\
/*6/6 */ ID_KEY_UNKNOWN,\
/*6/7 */ ID_KEY_UNKNOWN,\
/*6/8 */ ID_KEY_UNKNOWN,\
/*6/9 */ ID_KEY_DOLLAR,\
/*6/10*/ ID_KEY_UNKNOWN,\
/*6/11*/ ID_KEY_UNKNOWN,\
/*6/12*/ ID_KEY_UNKNOWN,\
/*6/13*/ ID_KEY_QUESTIONMARK,\
/*6/14*/ ID_KEY_UNKNOWN,\
/*6/15*/ ID_KEY_7,\
/*6/16*/ ID_KEY_9,\
/*6/17*/ ID_KEY_UNKNOWN,\
/*6/18*/ ID_KEY_5,\
/*6/19*/ ID_KEY_UNKNOWN,\
/*6/20*/ ID_KEY_UNKNOWN,\
/*6/21*/ ID_KEY_UNKNOWN,\
/*6/22*/ ID_KEY_UNKNOWN,\
/*6/23*/ ID_KEY_UNKNOWN,\
/*6/24*/ ID_KEY_UNKNOWN

#define MATRLINE_7 \
/*7/1 */ ID_KEY_UNKNOWN,\
/*7/2 */ ID_KEY_UNKNOWN,\
/*7/3 */ ID_KEY_UNKNOWN,\
/*7/4 */ ID_KEY_UNKNOWN,\
/*7/5 */ ID_KEY_UNKNOWN,\
/*7/6 */ ID_KEY_UNKNOWN,\
/*7/7 */ ID_KEY_UNKNOWN,\
/*7/8 */ ID_KEY_UNKNOWN,\
/*7/9 */ ID_KEY_UNKNOWN,\
/*7/10*/ ID_KEY_UNKNOWN,\
/*7/11*/ ID_KEY_UNKNOWN,\
/*7/12*/ ID_KEY_UNKNOWN,\
/*7/13*/ ID_KEY_0,\
/*7/14*/ ID_KEY_APOS,\
/*7/15*/ ID_KEY_6,\
/*7/16*/ ID_KEY_8,\
/*7/17*/ ID_KEY_UNKNOWN,\
/*7/18*/ ID_KEY_4,\
/*7/19*/ ID_KEY_UNKNOWN,\
/*7/20*/ ID_KEY_UNKNOWN,\
/*7/21*/ ID_KEY_UNKNOWN,\
/*7/22*/ ID_KEY_UNKNOWN,\
/*7/23*/ ID_KEY_UNKNOWN,\
/*7/24*/ ID_KEY_UNKNOWN

#define MATRLINE_8 \
/*8/1 */ ID_KEY_UNKNOWN,\
/*8/2 */ ID_KEY_UNKNOWN,\
/*8/3 */ ID_KEY_UNKNOWN,\
/*8/4 */ ID_KEY_UNKNOWN,\
/*8/5 */ ID_KEY_UNKNOWN,\
/*8/6 */ ID_KEY_UNKNOWN,\
/*8/7 */ ID_KEY_UNKNOWN,\
/*8/8 */ ID_KEY_UNKNOWN,\
/*8/9 */ ID_KEY_UNKNOWN,\
/*8/10*/ ID_KEY_UNKNOWN,\
/*8/11*/ ID_KEY_UNKNOWN,\
/*8/12*/ ID_KEY_UNKNOWN,\
/*8/13*/ ID_KEY_UNKNOWN,\
/*8/14*/ ID_KEY_UNKNOWN,\
/*8/15*/ ID_KEY_UNKNOWN,\
/*8/16*/ ID_KEY_UNKNOWN,\
/*8/17*/ ID_KEY_EURO,\
/*8/18*/ ID_KEY_UNKNOWN,\
/*8/19*/ ID_KEY_UNKNOWN,\
/*8/20*/ ID_KEY_UNKNOWN,\
/*8/21*/ ID_KEY_UNKNOWN,\
/*8/22*/ ID_KEY_UNKNOWN,\
/*8/23*/ ID_KEY_UNKNOWN,\
/*8/24*/ ID_KEY_UNKNOWN


#define MATRLINE_9 \
/*9/1 */ ID_KEY_UNKNOWN,\
/*9/2 */ ID_KEY_UNKNOWN,\
/*9/3 */ ID_KEY_UNKNOWN,\
/*9/4 */ ID_KEY_UNKNOWN,\
/*9/5 */ ID_KEY_UNKNOWN,\
/*9/6 */ ID_KEY_UNKNOWN,\
/*9/7 */ ID_KEY_UNKNOWN,\
/*9/8 */ ID_KEY_UNKNOWN,\
/*9/9 */ ID_KEY_UNKNOWN,\
/*9/10*/ ID_KEY_UNKNOWN,\
/*9/11*/ ID_KEY_UNKNOWN,\
/*9/12*/ ID_KEY_UNKNOWN,\
/*9/13*/ ID_KEY_UNKNOWN,\
/*9/14*/ ID_KEY_UNKNOWN,\
/*9/15*/ ID_KEY_UNKNOWN,\
/*9/16*/ ID_KEY_UNKNOWN,\
/*9/17*/ ID_KEY_UNKNOWN,\
/*9/18*/ ID_KEY_UNKNOWN,\
/*9/19*/ ID_KEY_UNKNOWN,\
/*9/20*/ ID_KEY_UNKNOWN,\
/*9/21*/ ID_KEY_CTRL_L,\
/*9/22*/ ID_KEY_UNKNOWN,\
/*9/23*/ ID_KEY_CTRL_R,\
/*9/24*/ ID_KEY_UNKNOWN

#define MATRLINE_10 \
/*10/1 */ ID_KEY_UNKNOWN,\
/*10/2 */ ID_KEY_UNKNOWN,\
/*10/3 */ ID_KEY_UNKNOWN,\
/*10/4 */ ID_KEY_UNKNOWN,\
/*10/5 */ ID_KEY_UNKNOWN,\
/*10/6 */ ID_KEY_UNKNOWN,\
/*10/7 */ ID_KEY_UNKNOWN,\
/*10/8 */ ID_KEY_UNKNOWN,\
/*10/9 */ ID_KEY_UNKNOWN,\
/*10/10*/ ID_KEY_UNKNOWN,\
/*10/11*/ ID_KEY_UNKNOWN,\
/*10/12*/ ID_KEY_UNKNOWN,\
/*10/13*/ ID_KEY_O,\
/*10/14*/ ID_KEY_ASTERISK,\
/*10/15*/ ID_KEY_T,\
/*10/16*/ ID_KEY_U,\
/*10/17*/ ID_KEY_UNKNOWN,\
/*10/18*/ ID_KEY_R,\
/*10/19*/ ID_KEY_UNKNOWN,\
/*10/20*/ ID_KEY_UNKNOWN,\
/*10/21*/ ID_KEY_UNKNOWN,\
/*10/22*/ ID_KEY_W,\
/*10/23*/ ID_KEY_UNKNOWN,\
/*10/24*/ ID_KEY_UNKNOWN


#define MATRLINE_11 \
/*11/1 */ ID_KEY_UNKNOWN,\
/*11/2 */ ID_KEY_UNKNOWN,\
/*11/3 */ ID_KEY_UNKNOWN,\
/*11/4 */ ID_KEY_UNKNOWN,\
/*11/5 */ ID_KEY_UNKNOWN,\
/*11/6 */ ID_KEY_UNKNOWN,\
/*11/7 */ ID_KEY_UNKNOWN,\
/*11/8 */ ID_KEY_UNKNOWN,\
/*11/9 */ ID_KEY_UNKNOWN,\
/*11/10*/ ID_KEY_UNKNOWN,\
/*11/11*/ ID_KEY_UNKNOWN,\
/*11/12*/ ID_KEY_UNKNOWN,\
/*11/13*/ ID_KEY_UNKNOWN,\
/*11/14*/ ID_KEY_UNKNOWN,\
/*11/15*/ ID_KEY_UNKNOWN,\
/*11/16*/ ID_KEY_UNKNOWN,\
/*11/17*/ ID_KEY_SHIFT_R,\
/*11/18*/ ID_KEY_UNKNOWN,\
/*11/19*/ ID_KEY_UNKNOWN,\
/*11/20*/ ID_KEY_UNKNOWN,\
/*11/21*/ ID_KEY_SHIFT_L,\
/*11/22*/ ID_KEY_UNKNOWN,\
/*11/23*/ ID_KEY_UNKNOWN,\
/*11/24*/ ID_KEY_UNKNOWN


#define MATRLINE_12 \
/*12/1 */ ID_KEY_UNKNOWN,\
/*12/2 */ ID_KEY_UNKNOWN,\
/*12/3 */ ID_KEY_UNKNOWN,\
/*12/4 */ ID_KEY_UNKNOWN,\
/*12/5 */ ID_KEY_UNKNOWN,\
/*12/6 */ ID_KEY_UNKNOWN,\
/*12/7 */ ID_KEY_UNKNOWN,\
/*12/8 */ ID_KEY_UNKNOWN,\
/*12/9 */ ID_KEY_UNKNOWN,\
/*12/10*/ ID_KEY_UNKNOWN,\
/*12/11*/ ID_KEY_UNKNOWN,\
/*12/12*/ ID_KEY_UNKNOWN,\
/*12/13*/ ID_KEY_I,\
/*12/14*/ ID_KEY_ENTER,\
/*12/15*/ ID_KEY_H,\
/*12/16*/ ID_KEY_Z,\
/*12/17*/ ID_KEY_UNKNOWN,\
/*12/18*/ ID_KEY_E,\
/*12/19*/ ID_KEY_UNKNOWN,\
/*12/20*/ ID_KEY_UNKNOWN,\
/*12/21*/ ID_KEY_UNKNOWN,\
/*12/22*/ ID_KEY_S,\
/*12/23*/ ID_KEY_UNKNOWN,\
/*12/24*/ ID_KEY_UNKNOWN

#define MATRLINE_13 \
/*13/1 */ ID_KEY_UNKNOWN,\
/*13/2 */ ID_KEY_UNKNOWN,\
/*13/3 */ ID_KEY_UNKNOWN,\
/*13/4 */ ID_KEY_UNKNOWN,\
/*13/5 */ ID_KEY_UNKNOWN,\
/*13/6 */ ID_KEY_UNKNOWN,\
/*13/7 */ ID_KEY_UNKNOWN,\
/*13/8 */ ID_KEY_UNKNOWN,\
/*13/9 */ ID_KEY_UNKNOWN,\
/*13/10*/ ID_KEY_UNKNOWN,\
/*13/11*/ ID_KEY_UNKNOWN,\
/*13/12*/ ID_KEY_UNKNOWN,\
/*13/13*/ ID_KEY_UNKNOWN,\
/*13/14*/ ID_KEY_UNKNOWN,\
/*13/15*/ ID_KEY_UNKNOWN,\
/*13/16*/ ID_KEY_UNKNOWN,\
/*13/17*/ ID_KEY_L,\
/*13/18*/ ID_KEY_UNKNOWN,\
/*13/19*/ ID_KEY_UNKNOWN,\
/*13/20*/ ID_KEY_UNKNOWN,\
/*13/21*/ ID_KEY_K,\
/*13/22*/ ID_KEY_UNKNOWN,\
/*13/23*/ ID_KEY_M,\
/*13/24*/ ID_KEY_COMMA

#define MATRLINE_14 \
/*14/1 */ ID_KEY_UNKNOWN,\
/*14/2 */ ID_KEY_UNKNOWN,\
/*14/3 */ ID_KEY_UNKNOWN,\
/*14/4 */ ID_KEY_UNKNOWN,\
/*14/5 */ ID_KEY_UNKNOWN,\
/*14/6 */ ID_KEY_UNKNOWN,\
/*14/7 */ ID_KEY_UNKNOWN,\
/*14/8 */ ID_KEY_UNKNOWN,\
/*14/9 */ ID_KEY_UNKNOWN,\
/*14/10*/ ID_KEY_UNKNOWN,\
/*14/11*/ ID_KEY_UNKNOWN,\
/*14/12*/ ID_KEY_UNKNOWN,\
/*14/13*/ ID_KEY_UNKNOWN,\
/*14/14*/ ID_KEY_UNKNOWN,\
/*14/15*/ ID_KEY_UNKNOWN,\
/*14/16*/ ID_KEY_UNKNOWN,\
/*14/17*/ ID_KEY_SHARP,\
/*14/18*/ ID_KEY_UNKNOWN,\
/*14/19*/ ID_KEY_UNKNOWN,\
/*14/20*/ ID_KEY_UNKNOWN,\
/*14/21*/ ID_KEY_END,\
/*14/22*/ ID_KEY_UNKNOWN,\
/*14/23*/ ID_KEY_WIN_R,\
/*14/24*/ ID_KEY_UNKNOWN


#define MATRLINE_15 \
/*15/1 */ ID_KEY_UNKNOWN,\
/*15/2 */ ID_KEY_UNKNOWN,\
/*15/3 */ ID_KEY_UNKNOWN,\
/*15/4 */ ID_KEY_UNKNOWN,\
/*15/5 */ ID_KEY_UNKNOWN,\
/*15/6 */ ID_KEY_UNKNOWN,\
/*15/7 */ ID_KEY_UNKNOWN,\
/*15/8 */ ID_KEY_UNKNOWN,\
/*15/9 */ ID_KEY_UNKNOWN,\
/*15/10*/ ID_KEY_UNKNOWN,\
/*15/11*/ ID_KEY_UNKNOWN,\
/*15/12*/ ID_KEY_UNKNOWN,\
/*15/13*/ ID_KEY_UNKNOWN,\
/*15/14*/ ID_KEY_UNKNOWN,\
/*15/15*/ ID_KEY_UNKNOWN,\
/*15/16*/ ID_KEY_UNKNOWN,\
/*15/17*/ ID_KEY_G,\
/*15/18*/ ID_KEY_UNKNOWN,\
/*15/19*/ ID_KEY_UNKNOWN,\
/*15/20*/ ID_KEY_UNKNOWN,\
/*15/21*/ ID_KEY_V,\
/*15/22*/ ID_KEY_UNKNOWN,\
/*15/23*/ ID_KEY_SPACE,\
/*15/24*/ ID_KEY_C

#define MATRLINE_16 \
/*16/1 */ ID_KEY_UNKNOWN,\
/*16/2 */ ID_KEY_UNKNOWN,\
/*16/3 */ ID_KEY_UNKNOWN,\
/*16/4 */ ID_KEY_UNKNOWN,\
/*16/5 */ ID_KEY_UNKNOWN,\
/*16/6 */ ID_KEY_UNKNOWN,\
/*16/7 */ ID_KEY_UNKNOWN,\
/*16/8 */ ID_KEY_UNKNOWN,\
/*16/9 */ ID_KEY_UNKNOWN,\
/*16/10*/ ID_KEY_UNKNOWN,\
/*16/11*/ ID_KEY_UNKNOWN,\
/*16/12*/ ID_KEY_UNKNOWN,\
/*16/13*/ ID_KEY_UNKNOWN,\
/*16/14*/ ID_KEY_UNKNOWN,\
/*16/15*/ ID_KEY_UNKNOWN,\
/*16/16*/ ID_KEY_UNKNOWN,\
/*16/17*/ ID_KEY_J,\
/*16/18*/ ID_KEY_UNKNOWN,\
/*16/19*/ ID_KEY_UNKNOWN,\
/*16/20*/ ID_KEY_UNKNOWN,\
/*16/21*/ ID_KEY_N,\
/*16/22*/ ID_KEY_UNKNOWN,\
/*16/23*/ ID_KEY_UNKNOWN,\
/*16/24*/ ID_KEY_B

#define MATRLINE_17 \
/*17/1 */ ID_KEY_UNKNOWN,\
/*17/2 */ ID_KEY_UNKNOWN,\
/*17/3 */ ID_KEY_UNKNOWN,\
/*17/4 */ ID_KEY_UNKNOWN,\
/*17/5 */ ID_KEY_UNKNOWN,\
/*17/6 */ ID_KEY_UNKNOWN,\
/*17/7 */ ID_KEY_UNKNOWN,\
/*17/8 */ ID_KEY_UNKNOWN,\
/*17/9 */ ID_KEY_UNKNOWN,\
/*17/10*/ ID_KEY_UNKNOWN,\
/*17/11*/ ID_KEY_UNKNOWN,\
/*17/12*/ ID_KEY_UNKNOWN,\
/*17/13*/ ID_KEY_UNKNOWN,\
/*17/14*/ ID_KEY_UNKNOWN,\
/*17/15*/ ID_KEY_UNKNOWN,\
/*17/16*/ ID_KEY_UNKNOWN,\
/*17/17*/ ID_KEY_UNKNOWN,\
/*17/18*/ ID_KEY_F,\
/*17/19*/ ID_KEY_UNKNOWN,\
/*17/20*/ ID_KEY_UNKNOWN,\
/*17/21*/ ID_KEY_UNKNOWN,\
/*17/22*/ ID_KEY_A,\
/*17/23*/ ID_KEY_UNKNOWN,\
/*17/24*/ ID_KEY_UNKNOWN

#define MATRLINE_18 \
/*18/1 */ ID_KEY_UNKNOWN,\
/*18/2 */ ID_KEY_UNKNOWN,\
/*18/3 */ ID_KEY_UNKNOWN,\
/*18/4 */ ID_KEY_UNKNOWN,\
/*18/5 */ ID_KEY_UNKNOWN,\
/*18/6 */ ID_KEY_UNKNOWN,\
/*18/7 */ ID_KEY_UNKNOWN,\
/*18/8 */ ID_KEY_UNKNOWN,\
/*18/9 */ ID_KEY_UNKNOWN,\
/*18/10*/ ID_KEY_UNKNOWN,\
/*18/11*/ ID_KEY_UNKNOWN,\
/*18/12*/ ID_KEY_UNKNOWN,\
/*18/13*/ ID_KEY_UNKNOWN,\
/*18/14*/ ID_KEY_UNKNOWN,\
/*18/15*/ ID_KEY_UNKNOWN,\
/*18/16*/ ID_KEY_UNKNOWN,\
/*18/17*/ ID_KEY_UNKNOWN,\
/*18/18*/ ID_KEY_UNKNOWN,\
/*18/19*/ ID_KEY_UNKNOWN,\
/*18/20*/ ID_KEY_UNKNOWN,\
/*18/21*/ ID_KEY_D,\
/*18/22*/ ID_KEY_UNKNOWN,\
/*18/23*/ ID_KEY_SMALLER,\
/*18/24*/ ID_KEY_X

#define MATRLINE_19 \
/*19/1 */ ID_KEY_UNKNOWN,\
/*19/2 */ ID_KEY_UNKNOWN,\
/*19/3 */ ID_KEY_UNKNOWN,\
/*19/4 */ ID_KEY_UNKNOWN,\
/*19/5 */ ID_KEY_UNKNOWN,\
/*19/6 */ ID_KEY_UNKNOWN,\
/*19/7 */ ID_KEY_UNKNOWN,\
/*19/8 */ ID_KEY_UNKNOWN,\
/*19/9 */ ID_KEY_UNKNOWN,\
/*19/10*/ ID_KEY_UNKNOWN,\
/*19/11*/ ID_KEY_UNKNOWN,\
/*19/12*/ ID_KEY_UNKNOWN,\
/*19/13*/ ID_KEY_UNKNOWN,\
/*19/14*/ ID_KEY_UNKNOWN,\
/*19/15*/ ID_KEY_UNKNOWN,\
/*19/16*/ ID_KEY_UNKNOWN,\
/*19/17*/ ID_KEY_UNKNOWN,\
/*19/18*/ ID_KEY_UNKNOWN,\
/*19/19*/ ID_KEY_UNKNOWN,\
/*19/20*/ ID_KEY_UNKNOWN,\
/*19/21*/ ID_KEY_UNKNOWN,\
/*19/22*/ ID_KEY_UNKNOWN,\
/*19/23*/ ID_KEY_WIN_L,\
/*19/24*/ ID_KEY_UNKNOWN

#define MATRLINE_20 \
/*20/1 */ ID_KEY_UNKNOWN,\
/*20/2 */ ID_KEY_UNKNOWN,\
/*20/3 */ ID_KEY_UNKNOWN,\
/*20/4 */ ID_KEY_UNKNOWN,\
/*20/5 */ ID_KEY_UNKNOWN,\
/*20/6 */ ID_KEY_UNKNOWN,\
/*20/7 */ ID_KEY_UNKNOWN,\
/*20/8 */ ID_KEY_UNKNOWN,\
/*20/9 */ ID_KEY_UNKNOWN,\
/*20/10*/ ID_KEY_UNKNOWN,\
/*20/11*/ ID_KEY_UNKNOWN,\
/*20/12*/ ID_KEY_UNKNOWN,\
/*20/13*/ ID_KEY_UNKNOWN,\
/*20/14*/ ID_KEY_UNKNOWN,\
/*20/15*/ ID_KEY_UNKNOWN,\
/*20/16*/ ID_KEY_UNKNOWN,\
/*20/17*/ ID_KEY_UNKNOWN,\
/*20/18*/ ID_KEY_UNKNOWN,\
/*20/19*/ ID_KEY_UNKNOWN,\
/*20/20*/ ID_KEY_UNKNOWN,\
/*20/21*/ ID_KEY_UNKNOWN,\
/*20/22*/ ID_KEY_UNKNOWN,\
/*20/23*/ ID_KEY_ALT_L,\
/*20/24*/ ID_KEY_ALT_R

#define MATRLINE_21 \
/*21/1 */ ID_KEY_UNKNOWN,\
/*21/2 */ ID_KEY_UNKNOWN,\
/*21/3 */ ID_KEY_UNKNOWN,\
/*21/4 */ ID_KEY_UNKNOWN,\
/*21/5 */ ID_KEY_UNKNOWN,\
/*21/6 */ ID_KEY_UNKNOWN,\
/*21/7 */ ID_KEY_UNKNOWN,\
/*21/8 */ ID_KEY_UNKNOWN,\
/*21/9 */ ID_KEY_UNKNOWN,\
/*21/10*/ ID_KEY_UNKNOWN,\
/*21/11*/ ID_KEY_UNKNOWN,\
/*21/12*/ ID_KEY_UNKNOWN,\
/*21/13*/ ID_KEY_UNKNOWN,\
/*21/14*/ ID_KEY_UNKNOWN,\
/*21/15*/ ID_KEY_UNKNOWN,\
/*21/16*/ ID_KEY_UNKNOWN,\
/*21/17*/ ID_KEY_UNKNOWN,\
/*21/18*/ ID_KEY_UNKNOWN,\
/*21/19*/ ID_KEY_UNKNOWN,\
/*21/20*/ ID_KEY_UNKNOWN,\
/*21/21*/ ID_KEY_UNKNOWN,\
/*21/22*/ ID_KEY_Y,\
/*21/23*/ ID_KEY_UNKNOWN,\
/*21/24*/ ID_KEY_UNKNOWN

#define MATRLINE_22 \
/*22/1 */ ID_KEY_UNKNOWN,\
/*22/2 */ ID_KEY_UNKNOWN,\
/*22/3 */ ID_KEY_UNKNOWN,\
/*22/4 */ ID_KEY_UNKNOWN,\
/*22/5 */ ID_KEY_UNKNOWN,\
/*22/6 */ ID_KEY_UNKNOWN,\
/*22/7 */ ID_KEY_UNKNOWN,\
/*22/8 */ ID_KEY_UNKNOWN,\
/*22/9 */ ID_KEY_UNKNOWN,\
/*22/10*/ ID_KEY_UNKNOWN,\
/*22/11*/ ID_KEY_UNKNOWN,\
/*22/12*/ ID_KEY_UNKNOWN,\
/*22/13*/ ID_KEY_UNKNOWN,\
/*22/14*/ ID_KEY_UNKNOWN,\
/*22/15*/ ID_KEY_UNKNOWN,\
/*22/16*/ ID_KEY_UNKNOWN,\
/*22/17*/ ID_KEY_UNKNOWN,\
/*22/18*/ ID_KEY_UNKNOWN,\
/*22/19*/ ID_KEY_UNKNOWN,\
/*22/20*/ ID_KEY_UNKNOWN,\
/*22/21*/ ID_KEY_UNKNOWN,\
/*22/22*/ ID_KEY_UNKNOWN,\
/*22/23*/ ID_KEY_FN,\
/*22/24*/ ID_KEY_UNKNOWN

/*
  * This is a 2 dim array that represents the keyboard matrix.
 */
//const static char Matrix[22][24] PROGMEM  =
const char Matrix[22][24]  =
{
  { MATRLINE_1 }, { MATRLINE_2 }, { MATRLINE_3 }, { MATRLINE_4 },
  { MATRLINE_5 }, { MATRLINE_6 }, { MATRLINE_7 }, { MATRLINE_8 },
  { MATRLINE_9 }, { MATRLINE_10 },{ MATRLINE_11 },{ MATRLINE_12 },
  { MATRLINE_13 },{ MATRLINE_14 },{ MATRLINE_15 },{ MATRLINE_16 },
  { MATRLINE_17 },{ MATRLINE_18 },{ MATRLINE_19 },{ MATRLINE_20 },
  { MATRLINE_21 },{ MATRLINE_22 }
};

  /*This is the array that in a way holds the labels of the Keys. If you got the cell content from the Matrix, this is the transformation to a human readable string, just to see
    the keyboard decoder is doing the right things and the wiring is ok.  
  */
//const static char HumanReadableDecoder[90][10] PROGMEM =
const char HumanReadableDecoder[90][10] =
{
	HR_KEY_UNKNOWN
	,HR_KEY_F11
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
#define PS2_SC_BREAK_F11      				0xF0, 0x78
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



