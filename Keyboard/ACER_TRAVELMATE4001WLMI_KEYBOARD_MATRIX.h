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
#define ID_KEY_DEGREE  10
#define ID_KEY_F5  11
#define ID_KEY_TAB 12
#define ID_KEY_F1  13
#define ID_KEY_F2  14
#define ID_KEY_F6  15
#define ID_KEY_CAPSLOCK 16
#define ID_KEY_F10 17
#define ID_KEY_F9  18
#define ID_KEY_BACKSPACE 19
#define ID_KEY_3 20
#define ID_KEY_2 21
#define ID_KEY_UP  22
#define ID_KEY_BRK 23
#define ID_KEY_PRN 24
#define ID_KEY_INS 25
#define ID_KEY_DEL 26
#define ID_KEY_POS1 27
#define ID_KEY_PageUp 28
#define ID_KEY_PageDown 29
#define ID_KEY_RGT 30
#define ID_KEY_LFT 31
#define ID_KEY_DWN 32
#define ID_KEY_Ue  33
#define ID_KEY_P 34
#define ID_KEY_Ae  35
#define ID_KEY_Oe  36
#define ID_KEY_MINUS 37
#define ID_KEY_COLON 38
#define ID_KEY_DOLLAR  39
#define ID_KEY_SS  40
#define ID_KEY_7 41
#define ID_KEY_9 42
#define ID_KEY_5 43
#define ID_KEY_0 44
#define ID_KEY_APOS 45
#define ID_KEY_6 46
#define ID_KEY_8 47
#define ID_KEY_4 48
#define ID_KEY_EURO  49
#define ID_KEY_CTL 50
#define ID_KEY_CTR 51
#define ID_KEY_O 52
#define ID_KEY_ASTERISK  53
#define ID_KEY_T 54
#define ID_KEY_U 55
#define ID_KEY_R 56
#define ID_KEY_W 57
#define ID_KEY_RSH 58
#define ID_KEY_LSH 59
#define ID_KEY_I 60
#define ID_KEY_ENT 61
#define ID_KEY_H 62
#define ID_KEY_Z 63
#define ID_KEY_E 64
#define ID_KEY_S 65
#define ID_KEY_L 66
#define ID_KEY_K 67
#define ID_KEY_M 68
#define ID_KEY_SEMICOLON 69
#define ID_KEY_SHARP 70
#define ID_KEY_END 71
#define ID_KEY_RWN 72
#define ID_KEY_G 73
#define ID_KEY_V 74
#define ID_KEY_SPC 75
#define ID_KEY_C 76
#define ID_KEY_J 77
#define ID_KEY_N 78
#define ID_KEY_B 79
#define ID_KEY_F 80
#define ID_KEY_A 81
#define ID_KEY_D 82
#define ID_KEY_GREATER 83
#define ID_KEY_X 84
#define ID_KEY_LWN 85
#define ID_KEY_ALT 86
#define ID_KEY_AGR 87
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
#define HR_KEY_DEGREE       "°"
#define HR_KEY_F5       "F5"
#define HR_KEY_TAB      "Tab"
#define HR_KEY_F1       "F1"
#define HR_KEY_F2       "F2"
#define HR_KEY_F6       "F6"
#define HR_KEY_CAPSLOCK   "CapsLock"
#define HR_KEY_F10      "F10"
#define HR_KEY_F9       "F9"
#define HR_KEY_BACKSPACE  "BackSpace"
#define HR_KEY_3      "3"
#define HR_KEY_2      "2"
#define HR_KEY_UP       "Up"
#define HR_KEY_BRK      "Break"
#define HR_KEY_PRN      "Print"
#define HR_KEY_INS      "Insert"
#define HR_KEY_DEL      "Delete"
#define HR_KEY_POS1     "Pos1"
#define HR_KEY_PageUp     "PageUp"
#define HR_KEY_PageDown   "PageDown"
#define HR_KEY_RGT      "Right"
#define HR_KEY_LFT      "Left"
#define HR_KEY_DWN      "Down"
#define HR_KEY_Ue       "Ü"
#define HR_KEY_P      "P"
#define HR_KEY_Ae       "Ä"
#define HR_KEY_Oe       "Ö"
#define HR_KEY_MINUS    "_"
#define HR_KEY_COLON    ":"
#define HR_KEY_DOLLAR     "$"
#define HR_KEY_SS       "ß"
#define HR_KEY_7      "7"
#define HR_KEY_9      "9"
#define HR_KEY_5      "5"
#define HR_KEY_0      "0"
#define HR_KEY_APOS     "`"
#define HR_KEY_6      "6"
#define HR_KEY_8      "8"
#define HR_KEY_4      "4"
#define HR_KEY_EURO     "€"
#define HR_KEY_CTL      "Ctrl-L"
#define HR_KEY_CTR      "Ctrl-R"
#define HR_KEY_O      "O"
#define HR_KEY_ASTERISK   "*"
#define HR_KEY_T      "T"
#define HR_KEY_U      "U"
#define HR_KEY_R      "R"
#define HR_KEY_W      "W"
#define HR_KEY_RSH      "Shift-R"
#define HR_KEY_LSH      "Shift-L"
#define HR_KEY_I      "I"
#define HR_KEY_ENT      "Enter"
#define HR_KEY_H      "H"
#define HR_KEY_Z      "Z"
#define HR_KEY_E      "E"
#define HR_KEY_S      "S"
#define HR_KEY_L      "L"
#define HR_KEY_K      "K"
#define HR_KEY_M      "M"
#define HR_KEY_SEMICOLON  ";"
#define HR_KEY_SHARP    "'"
#define HR_KEY_END      "End"
#define HR_KEY_RWN      "Win-R"
#define HR_KEY_G      "G"
#define HR_KEY_V      "V"
#define HR_KEY_SPC      "Space"
#define HR_KEY_C      "C"
#define HR_KEY_J      "J"
#define HR_KEY_N      "N"
#define HR_KEY_B      "B"
#define HR_KEY_F      "F"
#define HR_KEY_A      "A"
#define HR_KEY_D      "D"
#define HR_KEY_GREATER    ">"
#define HR_KEY_X      "X"
#define HR_KEY_LWN      "Win-L"
#define HR_KEY_ALT      "Alt"
#define HR_KEY_AGR      "AltGr"
#define HR_KEY_Y      "Y"
#define HR_KEY_FN       "Fn"

/*1/x*/
#define MATRLINE_1 \
/*1/1 */ 0,\
/*1/2 */ 0,\
/*1/3 */ 0,\
/*1/4 */ 0,\
/*1/5 */ 0,\
/*1/6 */ ID_KEY_F11,\
/*1/7 */ ID_KEY_F12,\
/*1/8 */ 0,\
/*1/9 */ 0,\
/*1/10*/ ID_KEY_F8,\
/*1/11*/ 0,\
/*1/12*/ ID_KEY_Q,\
/*1/13*/ 0,\
/*1/14*/ 0,\
/*1/15*/ 0,\
/*1/16*/ 0,\
/*1/17*/ ID_KEY_F4,\
/*1/18*/ 0,\
/*1/19*/ 0,\
/*1/20*/ 0,\
/*1/21*/ ID_KEY_F3,\
/*1/22*/ 0,\
/*1/23*/ ID_KEY_F7,\
/*1/24*/ ID_KEY_1

#define MATRLINE_2 \
/*2/1 */ 0,\
/*2/2 */ 0,\
/*2/3 */ 0,\
/*2/4 */ 0,\
/*2/5 */ 0,\
/*2/6 */ ID_KEY_ESC,\
/*2/7 */ ID_KEY_DEGREE,\
/*2/8 */ 0,\
/*2/9 */ 0,\
/*2/10*/ ID_KEY_F5,\
/*2/11*/ 0,\
/*2/12*/ ID_KEY_TAB,\
/*2/13*/ 0,\
/*2/14*/ 0,\
/*2/15*/ 0,\
/*2/16*/ 0,\
/*2/17*/ ID_KEY_F1,\
/*2/18*/ 0,\
/*2/19*/ 0,\
/*2/20*/ 0,\
/*2/21*/ ID_KEY_F2,\
/*2/22*/ 0,\
/*2/23*/ ID_KEY_F6,\
/*2/24*/ ID_KEY_CAPSLOCK

#define MATRLINE_3 \
/*3/1 */ 0,\
/*3/2 */ 0,\
/*3/3 */ 0,\
/*3/4 */ 0,\
/*3/5 */ 0,\
/*3/6 */ ID_KEY_F10,\
/*3/7 */ ID_KEY_F9,\
/*3/8 */ 0,\
/*3/9 */ 0,\
/*3/10*/ ID_KEY_BACKSPACE,\
/*3/11*/ 0,\
/*3/12*/ ID_KEY_3,\
/*3/13*/ 0,\
/*3/14*/ 0,\
/*3/15*/ 0,\
/*3/16*/ 0,\
/*3/17*/ ID_KEY_2,\
/*3/18*/ 0,\
/*3/19*/ 0,\
/*3/20*/ 0,\
/*3/21*/ ID_KEY_UP,\
/*3/22*/ 0,\
/*3/23*/ ID_KEY_BRK,\
/*3/24*/ ID_KEY_PRN

#define MATRLINE_4 \
/*4/1 */ 0,\
/*4/2 */ 0,\
/*4/3 */ 0,\
/*4/4 */ 0,\
/*4/5 */ 0,\
/*4/6 */ ID_KEY_INS,\
/*4/7 */ ID_KEY_DEL,\
/*4/8 */ 0,\
/*4/9 */ 0,\
/*4/10*/ ID_KEY_POS1,\
/*4/11*/ 0,\
/*4/12*/ ID_KEY_PageUp,\
/*4/13*/ 0,\
/*4/14*/ 0,\
/*4/15*/ 0,\
/*4/16*/ 0,\
/*4/17*/ ID_KEY_PageDown,\
/*4/18*/ 0,\
/*4/19*/ 0,\
/*4/20*/ 0,\
/*4/21*/ ID_KEY_RGT,\
/*4/22*/ 0,\
/*4/23*/ ID_KEY_LFT,\
/*4/24*/ ID_KEY_DWN

#define MATRLINE_5 \
/*5/1 */ 0,\
/*5/2 */ 0,\
/*5/3 */ 0,\
/*5/4 */ 0,\
/*5/5 */ 0,\
/*5/6 */ ID_KEY_Ue,\
/*5/7 */ ID_KEY_P,\
/*5/8 */ 0,\
/*5/9 */ 0,\
/*5/10*/ ID_KEY_Ae,\
/*5/11*/ 0,\
/*5/12*/ ID_KEY_Oe,\
/*5/13*/ 0,\
/*5/14*/ 0,\
/*5/15*/ 0,\
/*5/16*/ 0,\
/*5/17*/ ID_KEY_MINUS,\
/*5/18*/ 0,\
/*5/19*/ 0,\
/*5/20*/ 0,\
/*5/21*/ ID_KEY_COLON,\
/*5/22*/ 0,\
/*5/23*/ 0,\
/*5/24*/ 0

#define MATRLINE_6 \
/*6/1 */ 0,\
/*6/2 */ 0,\
/*6/3 */ 0,\
/*6/4 */ 0,\
/*6/5 */ 0,\
/*6/6 */ 0,\
/*6/7 */ 0,\
/*6/8 */ 0,\
/*6/9 */ ID_KEY_DOLLAR,\
/*6/10*/ 0,\
/*6/11*/ 0,\
/*6/12*/ 0,\
/*6/13*/ ID_KEY_SS,\
/*6/14*/ 0,\
/*6/15*/ ID_KEY_7,\
/*6/16*/ ID_KEY_9,\
/*6/17*/ 0,\
/*6/18*/ ID_KEY_5,\
/*6/19*/ 0,\
/*6/20*/ 0,\
/*6/21*/ 0,\
/*6/22*/ 0,\
/*6/23*/ 0,\
/*6/24*/ 0

#define MATRLINE_7 \
/*7/1 */ 0,\
/*7/2 */ 0,\
/*7/3 */ 0,\
/*7/4 */ 0,\
/*7/5 */ 0,\
/*7/6 */ 0,\
/*7/7 */ 0,\
/*7/8 */ 0,\
/*7/9 */ 0,\
/*7/10*/ 0,\
/*7/11*/ 0,\
/*7/12*/ 0,\
/*7/13*/ ID_KEY_0,\
/*7/14*/ ID_KEY_APOS,\
/*7/15*/ ID_KEY_6,\
/*7/16*/ ID_KEY_8,\
/*7/17*/ 0,\
/*7/18*/ ID_KEY_4,\
/*7/19*/ 0,\
/*7/20*/ 0,\
/*7/21*/ 0,\
/*7/22*/ 0,\
/*7/23*/ 0,\
/*7/24*/ 0

#define MATRLINE_8 \
/*8/1 */ 0,\
/*8/2 */ 0,\
/*8/3 */ 0,\
/*8/4 */ 0,\
/*8/5 */ 0,\
/*8/6 */ 0,\
/*8/7 */ 0,\
/*8/8 */ 0,\
/*8/9 */ 0,\
/*8/10*/ 0,\
/*8/11*/ 0,\
/*8/12*/ 0,\
/*8/13*/ 0,\
/*8/14*/ 0,\
/*8/15*/ 0,\
/*8/16*/ 0,\
/*8/17*/ ID_KEY_EURO,\
/*8/18*/ 0,\
/*8/19*/ 0,\
/*8/20*/ 0,\
/*8/21*/ 0,\
/*8/22*/ 0,\
/*8/23*/ 0,\
/*8/24*/ 0


#define MATRLINE_9 \
/*9/1 */ 0,\
/*9/2 */ 0,\
/*9/3 */ 0,\
/*9/4 */ 0,\
/*9/5 */ 0,\
/*9/6 */ 0,\
/*9/7 */ 0,\
/*9/8 */ 0,\
/*9/9 */ 0,\
/*9/10*/ 0,\
/*9/11*/ 0,\
/*9/12*/ 0,\
/*9/13*/ 0,\
/*9/14*/ 0,\
/*9/15*/ 0,\
/*9/16*/ 0,\
/*9/17*/ 0,\
/*9/18*/ 0,\
/*9/19*/ 0,\
/*9/20*/ 0,\
/*9/21*/ ID_KEY_CTL,\
/*9/22*/ 0,\
/*9/23*/ ID_KEY_CTR,\
/*9/24*/ 0

#define MATRLINE_10 \
/*10/1 */ 0,\
/*10/2 */ 0,\
/*10/3 */ 0,\
/*10/4 */ 0,\
/*10/5 */ 0,\
/*10/6 */ 0,\
/*10/7 */ 0,\
/*10/8 */ 0,\
/*10/9 */ 0,\
/*10/10*/ 0,\
/*10/11*/ 0,\
/*10/12*/ 0,\
/*10/13*/ ID_KEY_O,\
/*10/14*/ ID_KEY_ASTERISK,\
/*10/15*/ ID_KEY_T,\
/*10/16*/ ID_KEY_U,\
/*10/17*/ 0,\
/*10/18*/ ID_KEY_R,\
/*10/19*/ 0,\
/*10/20*/ 0,\
/*10/21*/ 0,\
/*10/22*/ ID_KEY_W,\
/*10/23*/ 0,\
/*10/24*/ 0


#define MATRLINE_11 \
/*11/1 */ 0,\
/*11/2 */ 0,\
/*11/3 */ 0,\
/*11/4 */ 0,\
/*11/5 */ 0,\
/*11/6 */ 0,\
/*11/7 */ 0,\
/*11/8 */ 0,\
/*11/9 */ 0,\
/*11/10*/ 0,\
/*11/11*/ 0,\
/*11/12*/ 0,\
/*11/13*/ 0,\
/*11/14*/ 0,\
/*11/15*/ 0,\
/*11/16*/ 0,\
/*11/17*/ ID_KEY_RSH,\
/*11/18*/ 0,\
/*11/19*/ 0,\
/*11/20*/ 0,\
/*11/21*/ ID_KEY_LSH,\
/*11/22*/ 0,\
/*11/23*/ 0,\
/*11/24*/ 0


#define MATRLINE_12 \
/*12/1 */ 0,\
/*12/2 */ 0,\
/*12/3 */ 0,\
/*12/4 */ 0,\
/*12/5 */ 0,\
/*12/6 */ 0,\
/*12/7 */ 0,\
/*12/8 */ 0,\
/*12/9 */ 0,\
/*12/10*/ 0,\
/*12/11*/ 0,\
/*12/12*/ 0,\
/*12/13*/ ID_KEY_I,\
/*12/14*/ ID_KEY_ENT,\
/*12/15*/ ID_KEY_H,\
/*12/16*/ ID_KEY_Z,\
/*12/17*/ 0,\
/*12/18*/ ID_KEY_E,\
/*12/19*/ 0,\
/*12/20*/ 0,\
/*12/21*/ 0,\
/*12/22*/ ID_KEY_S,\
/*12/23*/ 0,\
/*12/24*/ 0

#define MATRLINE_13 \
/*13/1 */ 0,\
/*13/2 */ 0,\
/*13/3 */ 0,\
/*13/4 */ 0,\
/*13/5 */ 0,\
/*13/6 */ 0,\
/*13/7 */ 0,\
/*13/8 */ 0,\
/*13/9 */ 0,\
/*13/10*/ 0,\
/*13/11*/ 0,\
/*13/12*/ 0,\
/*13/13*/ 0,\
/*13/14*/ 0,\
/*13/15*/ 0,\
/*13/16*/ 0,\
/*13/17*/ ID_KEY_L,\
/*13/18*/ 0,\
/*13/19*/ 0,\
/*13/20*/ 0,\
/*13/21*/ ID_KEY_K,\
/*13/22*/ 0,\
/*13/23*/ ID_KEY_M,\
/*13/24*/ ID_KEY_SEMICOLON

#define MATRLINE_14 \
/*14/1 */ 0,\
/*14/2 */ 0,\
/*14/3 */ 0,\
/*14/4 */ 0,\
/*14/5 */ 0,\
/*14/6 */ 0,\
/*14/7 */ 0,\
/*14/8 */ 0,\
/*14/9 */ 0,\
/*14/10*/ 0,\
/*14/11*/ 0,\
/*14/12*/ 0,\
/*14/13*/ 0,\
/*14/14*/ 0,\
/*14/15*/ 0,\
/*14/16*/ 0,\
/*14/17*/ ID_KEY_SHARP,\
/*14/18*/ 0,\
/*14/19*/ 0,\
/*14/20*/ 0,\
/*14/21*/ ID_KEY_END,\
/*14/22*/ 0,\
/*14/23*/ ID_KEY_RWN,\
/*14/24*/ 0


#define MATRLINE_15 \
/*15/1 */ 0,\
/*15/2 */ 0,\
/*15/3 */ 0,\
/*15/4 */ 0,\
/*15/5 */ 0,\
/*15/6 */ 0,\
/*15/7 */ 0,\
/*15/8 */ 0,\
/*15/9 */ 0,\
/*15/10*/ 0,\
/*15/11*/ 0,\
/*15/12*/ 0,\
/*15/13*/ 0,\
/*15/14*/ 0,\
/*15/15*/ 0,\
/*15/16*/ 0,\
/*15/17*/ ID_KEY_G,\
/*15/18*/ 0,\
/*15/19*/ 0,\
/*15/20*/ 0,\
/*15/21*/ ID_KEY_V,\
/*15/22*/ 0,\
/*15/23*/ ID_KEY_SPC,\
/*15/24*/ ID_KEY_C

#define MATRLINE_16 \
/*16/1 */ 0,\
/*16/2 */ 0,\
/*16/3 */ 0,\
/*16/4 */ 0,\
/*16/5 */ 0,\
/*16/6 */ 0,\
/*16/7 */ 0,\
/*16/8 */ 0,\
/*16/9 */ 0,\
/*16/10*/ 0,\
/*16/11*/ 0,\
/*16/12*/ 0,\
/*16/13*/ 0,\
/*16/14*/ 0,\
/*16/15*/ 0,\
/*16/16*/ 0,\
/*16/17*/ ID_KEY_J,\
/*16/18*/ 0,\
/*16/19*/ 0,\
/*16/20*/ 0,\
/*16/21*/ ID_KEY_N,\
/*16/22*/ 0,\
/*16/23*/ 0,\
/*16/24*/ ID_KEY_B

#define MATRLINE_17 \
/*17/1 */ 0,\
/*17/2 */ 0,\
/*17/3 */ 0,\
/*17/4 */ 0,\
/*17/5 */ 0,\
/*17/6 */ 0,\
/*17/7 */ 0,\
/*17/8 */ 0,\
/*17/9 */ 0,\
/*17/10*/ 0,\
/*17/11*/ 0,\
/*17/12*/ 0,\
/*17/13*/ 0,\
/*17/14*/ 0,\
/*17/15*/ 0,\
/*17/16*/ 0,\
/*17/17*/ 0,\
/*17/18*/ ID_KEY_F,\
/*17/19*/ 0,\
/*17/20*/ 0,\
/*17/21*/ 0,\
/*17/22*/ ID_KEY_A,\
/*17/23*/ 0,\
/*17/24*/ 0

#define MATRLINE_18 \
/*18/1 */ 0,\
/*18/2 */ 0,\
/*18/3 */ 0,\
/*18/4 */ 0,\
/*18/5 */ 0,\
/*18/6 */ 0,\
/*18/7 */ 0,\
/*18/8 */ 0,\
/*18/9 */ 0,\
/*18/10*/ 0,\
/*18/11*/ 0,\
/*18/12*/ 0,\
/*18/13*/ 0,\
/*18/14*/ 0,\
/*18/15*/ 0,\
/*18/16*/ 0,\
/*18/17*/ 0,\
/*18/18*/ 0,\
/*18/19*/ 0,\
/*18/20*/ 0,\
/*18/21*/ ID_KEY_D,\
/*18/22*/ 0,\
/*18/23*/ ID_KEY_GREATER,\
/*18/24*/ ID_KEY_X

#define MATRLINE_19 \
/*19/1 */ 0,\
/*19/2 */ 0,\
/*19/3 */ 0,\
/*19/4 */ 0,\
/*19/5 */ 0,\
/*19/6 */ 0,\
/*19/7 */ 0,\
/*19/8 */ 0,\
/*19/9 */ 0,\
/*19/10*/ 0,\
/*19/11*/ 0,\
/*19/12*/ 0,\
/*19/13*/ 0,\
/*19/14*/ 0,\
/*19/15*/ 0,\
/*19/16*/ 0,\
/*19/17*/ 0,\
/*19/18*/ 0,\
/*19/19*/ 0,\
/*19/20*/ 0,\
/*19/21*/ 0,\
/*19/22*/ 0,\
/*19/23*/ ID_KEY_LWN,\
/*19/24*/ 0

#define MATRLINE_20 \
/*20/1 */ 0,\
/*20/2 */ 0,\
/*20/3 */ 0,\
/*20/4 */ 0,\
/*20/5 */ 0,\
/*20/6 */ 0,\
/*20/7 */ 0,\
/*20/8 */ 0,\
/*20/9 */ 0,\
/*20/10*/ 0,\
/*20/11*/ 0,\
/*20/12*/ 0,\
/*20/13*/ 0,\
/*20/14*/ 0,\
/*20/15*/ 0,\
/*20/16*/ 0,\
/*20/17*/ 0,\
/*20/18*/ 0,\
/*20/19*/ 0,\
/*20/20*/ 0,\
/*20/21*/ 0,\
/*20/22*/ 0,\
/*20/23*/ ID_KEY_ALT,\
/*20/24*/ ID_KEY_AGR

#define MATRLINE_21 \
/*21/1 */ 0,\
/*21/2 */ 0,\
/*21/3 */ 0,\
/*21/4 */ 0,\
/*21/5 */ 0,\
/*21/6 */ 0,\
/*21/7 */ 0,\
/*21/8 */ 0,\
/*21/9 */ 0,\
/*21/10*/ 0,\
/*21/11*/ 0,\
/*21/12*/ 0,\
/*21/13*/ 0,\
/*21/14*/ 0,\
/*21/15*/ 0,\
/*21/16*/ 0,\
/*21/17*/ 0,\
/*21/18*/ 0,\
/*21/19*/ 0,\
/*21/20*/ 0,\
/*21/21*/ 0,\
/*21/22*/ ID_KEY_Y,\
/*21/23*/ 0,\
/*21/24*/ 0

#define MATRLINE_22 \
/*22/1 */ 0,\
/*22/2 */ 0,\
/*22/3 */ 0,\
/*22/4 */ 0,\
/*22/5 */ 0,\
/*22/6 */ 0,\
/*22/7 */ 0,\
/*22/8 */ 0,\
/*22/9 */ 0,\
/*22/10*/ 0,\
/*22/11*/ 0,\
/*22/12*/ 0,\
/*22/13*/ 0,\
/*22/14*/ 0,\
/*22/15*/ 0,\
/*22/16*/ 0,\
/*22/17*/ 0,\
/*22/18*/ 0,\
/*22/19*/ 0,\
/*22/20*/ 0,\
/*22/21*/ 0,\
/*22/22*/ 0,\
/*22/23*/ ID_KEY_FN,\
/*22/24*/ 0

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
	,HR_KEY_DEGREE
	,HR_KEY_F5
	,HR_KEY_TAB
	,HR_KEY_F1
	,HR_KEY_F2
	,HR_KEY_F6
	,HR_KEY_CAPSLOCK
	,HR_KEY_F10
	,HR_KEY_F9
	,HR_KEY_BACKSPACE
	,HR_KEY_3
	,HR_KEY_2
	,HR_KEY_UP
	,HR_KEY_BRK
	,HR_KEY_PRN
	,HR_KEY_INS
	,HR_KEY_DEL
	,HR_KEY_POS1
	,HR_KEY_PageUp
	,HR_KEY_PageDown
	,HR_KEY_RGT
	,HR_KEY_LFT
	,HR_KEY_DWN
	,HR_KEY_Ue
	,HR_KEY_P
	,HR_KEY_Ae
	,HR_KEY_Oe
	,HR_KEY_MINUS
	,HR_KEY_COLON
	,HR_KEY_DOLLAR
	,HR_KEY_SS
	,HR_KEY_7
	,HR_KEY_9
	,HR_KEY_5
	,HR_KEY_0
	,HR_KEY_APOS
	,HR_KEY_6
	,HR_KEY_8
	,HR_KEY_4
	,HR_KEY_EURO
	,HR_KEY_CTL
	,HR_KEY_CTR
	,HR_KEY_O
	,HR_KEY_ASTERISK
	,HR_KEY_T
	,HR_KEY_U
	,HR_KEY_R
	,HR_KEY_W
	,HR_KEY_RSH
	,HR_KEY_LSH
	,HR_KEY_I
	,HR_KEY_ENT
	,HR_KEY_H
	,HR_KEY_Z
	,HR_KEY_E
	,HR_KEY_S
	,HR_KEY_L
	,HR_KEY_K
	,HR_KEY_M
	,HR_KEY_SEMICOLON
	,HR_KEY_SHARP
	,HR_KEY_END
	,HR_KEY_RWN
	,HR_KEY_G
	,HR_KEY_V
	,HR_KEY_SPC
	,HR_KEY_C
	,HR_KEY_J
	,HR_KEY_N
	,HR_KEY_B
	,HR_KEY_F
	,HR_KEY_A
	,HR_KEY_D
	,HR_KEY_GREATER
	,HR_KEY_X
	,HR_KEY_LWN
	,HR_KEY_ALT
	,HR_KEY_AGR
	,HR_KEY_Y
	,HR_KEY_FN
};
  
