/*
#################################################################################
#################################################################################
##### PS/2 Codes and Commands (This is for Scan Code Set 2)
#################################################################################
#################################################################################
*/
/*
	Where I found all these details:
	http://www.marjorie.de
	https://www.eecg.utoronto.ca/~pc/courses/241/DE1_SoC_cores/ps2/ps2.html
	https://de.wikipedia.org/wiki/PS/2-Schnittstelle
	http://www.winfaq.de/faq_html/Content/tip1500/onlinefaq.php?h=tip1576.htm
*/
/*
#################################################################################
##### Keyboard to Host Commands
#################################################################################
*/
#define Ps2ScanCodeDummy 0x00  //Not a real scan code, just a dummy that will never be used on the wire

#define Ps2K2H_Acknowedge 		  0xFA
#define Ps2K2H_SelftestPassed 	0xAA
#define Ps2K2H_EchoResponse 	  0xEE
#define Ps2K2H_Resendrequest 	  0xFE
#define Ps2K2H_ErrorA			      0x00			
#define Ps2K2H_ErrorB			      0xFF


/*
#################################################################################
##### Host to Keyboard Commands
#################################################################################
*/

/*
Set status LEDs - This command can be used to turn on and off the Num Lock, Caps Lock and Scroll Lock LEDs. 
After receiving this command, the keyboard will reply with an ACK (FA) and wait for another byte which 
determines the status of the LEDs. 
Bit 0 controls the Scroll Lock, bit 1 controls the Num Lock and Bit 2 controls the Caps lock. Bits 3 to 7 are ignored.
*/
#define Ps2H2K_SetStatusLEDs 		0xED

/*
Echo - The keyboard should reply with an Echo (EE) upon receiving this command
*/
#define Ps2H2K_Echo 				    0xEE
/*
Set scan code set - Upon receiving F0, the keyboard will reply with an ACK (FA) and wait for another byte. 
This byte can be in the range 01 to 03, and it determines the scan code set to be used. 
Sending 00 as the second byte will return the scan code set currently in use.
*/
#define Ps2H2K_ScanCodeSet 		  0xF0

/*
Set repeat rate - The keyboard will acknowledge the command with an ACK (FA) and wait for the second byte 
which determines the repeat rate. 
*/
#define Ps2H2K_SetRepeatRate 		0xF3

/*
Keyboard Enable - Clears the output buffer, enables the keyboard (i.e., key codes will be transmitted) 
and returns an ACK.
*/
#define Ps2H2K_KeyboardEnable 		0xF4

/*
Keyboard Disable - Resets the keyboard, disables the keyboard 
(key codes will not be transmitted) and returns an ACK.
*/
#define Ps2H2K_KeyboardEnable 		0xF5

/*
Resend - Upon receipt of the resend command the keyboard will retransmit the last byte sent.
*/
#define Ps2H2K_Resend 		0xFE

/*
Reset - Resets the keyboard.
*/
#define Ps2H2K_Reset 		0xFF

/*
Makecodes
*/
#define Ps2Mk_ESC 				0x76 
#define Ps2Mk_F1 				  0x05 
#define Ps2Mk_F2 				  0x06 
#define Ps2Mk_F3 				  0x04 
#define Ps2Mk_F4 				  0x0C 
#define Ps2Mk_F5 				  0x03 
#define Ps2Mk_F6 			  	0x0B 
#define Ps2Mk_F7 				  0x83 
#define Ps2Mk_F8 				  0x0A 
#define Ps2Mk_F9 				  0x01 
#define Ps2Mk_F10 				0x09 
#define Ps2Mk_F11 				0x78 
#define Ps2Mk_F12 				0x07 
#define Ps2Mk_PRINT				0xE0, 0x12, 0xE0, 0x7C 
#define Ps2Mk_SCROLL_LOCK 		0x7E 
#define Ps2Mk_BREAK 			0xE1, 0x14, 0x77, 0xE1, 0xF0, 0x14, 0xE0, 0x77 
#define Ps2Mk_CIRCUMFLEX				0x0E
#define Ps2Mk_1					0x16 
#define Ps2Mk_2					0x1E 
#define Ps2Mk_3					0x26 
#define Ps2Mk_4					0x25 
#define Ps2Mk_5					0x2E 
#define Ps2Mk_6					0x36 
#define Ps2Mk_7					0x3D 
#define Ps2Mk_8					0x3E 
#define Ps2Mk_9					0x46 
#define Ps2Mk_0					0x45

#define Ps2Mk_QUESTIONMARK		0x4E 
#define Ps2Mk_APOS				0x55 
#define Ps2Mk_BACKSPACE 		0x66 
#define Ps2Mk_TAB 				0x0D 
#define Ps2Mk_Q 				0x15 
#define Ps2Mk_W 				0x1D 
#define Ps2Mk_E 				0x24 
#define Ps2Mk_R 				0x2D 
#define Ps2Mk_T 				0x2C 
#define Ps2Mk_Z					0x35 
#define Ps2Mk_U 				0x3C 
#define Ps2Mk_I 				0x43 
#define Ps2Mk_O 				0x44 
#define Ps2Mk_P 				0x4D 
#define Ps2Mk_UE				0x54 
#define Ps2Mk_ASTERISK			0x5B 
#define Ps2Mk_SHARP				0x5D 
#define Ps2Mk_CAPS_LOCK 		0x58 
#define Ps2Mk_A 				0x1C 
#define Ps2Mk_S 				0x1B 
#define Ps2Mk_D 				0x23 
#define Ps2Mk_F 				0x2B 
#define Ps2Mk_G 				0x34 
#define Ps2Mk_H 				0x33 
#define Ps2Mk_J 				0x3B 
#define Ps2Mk_K 				0x42 
#define Ps2Mk_L 				0x4B 
#define Ps2Mk_OE				0x4C 
#define Ps2Mk_AE				0x52 
#define Ps2Mk_ENTER 			0x5A 
#define Ps2Mk_SHIFT_L 			0x12
#define Ps2Mk_LOWER_THAN 			0x61
 
#define Ps2Mk_Y					0x1A 
#define Ps2Mk_X 				0x22 
#define Ps2Mk_C 				0x21 
#define Ps2Mk_V 				0x2A 
#define Ps2Mk_B 				0x32 
#define Ps2Mk_N 				0x31 
#define Ps2Mk_M 				0x3A 
#define Ps2Mk_COMMA				0x41 
#define Ps2Mk_DOT				0x49 
#define Ps2Mk_MINUS				0x4A 
#define Ps2Mk_SHIFT_R			0x59 
#define Ps2Mk_CTRL_L 			0x14 
#define Ps2Mk_WIN_L 			    /*0xE0,*/ 0x1F 
#define Ps2Mk_ALT_L				0x11 
#define Ps2Mk_SPACE				0x29 
#define Ps2Mk_ALT_R 			    /*0xE0,*/ 0x11 
#define Ps2Mk_WIN_R 			    /*0xE0,*/ 0x27 
#define Ps2Mk_MENUS 			    /*0xE0,*/ 0x2F 
#define Ps2Mk_CTRL_R 			    /*0xE0,*/ 0x14
#define Ps2Mk_INSERT 			    /*0xE0,*/ 0x70 
#define Ps2Mk_HOME 				    /*0xE0,*/ 0x6C 
#define Ps2Mk_PAGE_UP 		    /*0xE0,*/ 0x7D 
#define Ps2Mk_DELETE 			    /*0xE0,*/ 0x71 
#define Ps2Mk_END 				    /*0xE0,*/ 0x69 
#define Ps2Mk_PAGE_DOWN 		  /*0xE0,*/ 0x7A 
#define Ps2Mk_ARROW_UP			  /*0xE0,*/ 0x75 
#define Ps2Mk_ARROW_LEFT 		  /*0xE0,*/ 0x6B 
#define Ps2Mk_ARROW_DOWN 		  /*0xE0,*/ 0x72 
#define Ps2Mk_ARROW_RIGHT 	  /*0xE0,*/ 0x74 

#define Ps2Mk_NUM_LOCK 			0x77 

#define Ps2Mk_NUMPAD_DIVIDE 	  /*0xE0,*/ 0x4A 
#define Ps2Mk_NUMPAD_MULTI		0x7C 
#define Ps2Mk_NUMPAD_MINUS		0x7B 
#define Ps2Mk_NUMPAD_7			0x6C 
#define Ps2Mk_NUMPAD_8			0x75 
#define Ps2Mk_NUMPAD_9			0x7D 
#define Ps2Mk_NUMPAD_PLUS 		0x79 
#define Ps2Mk_NUMPAD_4			0x6B 
#define Ps2Mk_NUMPAD_5			0x73 
#define Ps2Mk_NUMPAD_6			0x74 
#define Ps2Mk_NUMPAD_1			0x69 
#define Ps2Mk_NUMPAD_2			0x72 
#define Ps2Mk_NUMPAD_3			0x7A 
#define Ps2Mk_NUMPAD_0			0x70 
#define Ps2Mk_NUMPAD_DECIMAL 		0x71 
#define Ps2Mk_NUMPAD_ENTER 		  /*0xE0,*/ 0x5A 

//ACPI Scancodes
#define Ps2Mk_AcpiPower /*0xE0,*/ 0x5E 
#define Ps2Mk_AcpiSleep /*0xE0,*/ 0x5F 
#define Ps2Mk_AcpiWake  /*0xE0,*/ 0x63  

//Multimedia Scancodes 
#define Ps2Mk_MmNextTrack 		  /*0xE0,*/ 0x19
#define Ps2Mk_MmPreviousTrack 	/*0xE0,*/ 0x10
#define Ps2Mk_MmStop 			      /*0xE0,*/ 0x24
#define Ps2Mk_MmPlayPause 		  /*0xE0,*/ 0x22
#define Ps2Mk_MmMute 			      /*0xE0,*/ 0x20
#define Ps2Mk_MmVolumeUp 		    /*0xE0,*/ 0x30
#define Ps2Mk_MmVolumeDown 		  /*0xE0,*/ 0x2e
#define Ps2Mk_MmMediaSelect 	  /*0xE0,*/ 0x6d
#define Ps2Mk_MmEmail 			    /*0xE0,*/ 0x6c
#define Ps2Mk_MmCalculator 		  /*0xE0,*/ 0x21
#define Ps2Mk_MmMyComputer 		  /*0xE0,*/ 0x6b
#define Ps2Mk_MmWwwSearch 		  /*0xE0,*/ 0x65
#define Ps2Mk_MmWwwHome 		    /*0xE0,*/ 0x32
#define Ps2Mk_MmWwwBack 		    /*0xE0,*/ 0x6a
#define Ps2Mk_MmWwwForward 		  /*0xE0,*/ 0x69
#define Ps2Mk_MmWwwStop 		    /*0xE0,*/ 0x68
#define Ps2Mk_MmWwwRefresh 		  /*0xE0,*/ 0x67
#define Ps2Mk_MmWwwFavorites 	  /*0xE0,*/ 0x66


  /*
  Makecode byte counts
  */
  #define Ps2MkBc_ESC 			1 
  #define Ps2MkBc_F1 				1 
  #define Ps2MkBc_F2 				1 
  #define Ps2MkBc_F3 				1 
  #define Ps2MkBc_F4 				1 
  #define Ps2MkBc_F5 				1 
  #define Ps2MkBc_F6 				1 
  #define Ps2MkBc_F7 				1 
  #define Ps2MkBc_F8 				1 
  #define Ps2MkBc_F9 				1 
  #define Ps2MkBc_F10 			1 
  #define Ps2MkBc_F11 			1 
  #define Ps2MkBc_F12 			1 
  #define Ps2MkBc_PRINT				4 
  #define Ps2MkBc_SCROLL_LOCK 	1 
  #define Ps2MkBc_BREAK 				8 
  #define Ps2MkBc_CIRCUMFLEX			1 
  #define Ps2MkBc_1				1 
  #define Ps2MkBc_2				1 
  #define Ps2MkBc_3				1 
  #define Ps2MkBc_4				1 
  #define Ps2MkBc_5				1 
  #define Ps2MkBc_6				1 
  #define Ps2MkBc_7				1 
  #define Ps2MkBc_8				1 
  #define Ps2MkBc_9				1 
  #define Ps2MkBc_0				1 
  #define Ps2MkBc_QUESTIONMARK	1 
  #define Ps2MkBc_APOS			1 
  #define Ps2MkBc_BACKSPACE 		1 
  #define Ps2MkBc_TAB 			1 
  #define Ps2MkBc_Q 				1 
  #define Ps2MkBc_W 				1 
  #define Ps2MkBc_E 				1 
  #define Ps2MkBc_R 				1 
  #define Ps2MkBc_T 				1 
  #define Ps2MkBc_Z				1 
  #define Ps2MkBc_U 				1 
  #define Ps2MkBc_I 				1 
  #define Ps2MkBc_O 				1 
  #define Ps2MkBc_P 				1 
  #define Ps2MkBc_UE				1 
  #define Ps2MkBc_ASTERISK		1 
  #define Ps2MkBc_SHARP			1 
  #define Ps2MkBc_CAPS_LOCK 		1 
  #define Ps2MkBc_A 				1 
  #define Ps2MkBc_S 				1 
  #define Ps2MkBc_D 				1 
  #define Ps2MkBc_F 				1 
  #define Ps2MkBc_G 				1 
  #define Ps2MkBc_H 				1 
  #define Ps2MkBc_J 				1 
  #define Ps2MkBc_K 				1 
  #define Ps2MkBc_L 				1 
  #define Ps2MkBc_OE				1 
  #define Ps2MkBc_AE				1 
  #define Ps2MkBc_ENTER 			1 
  #define Ps2MkBc_SHIFT_L 		1
  #define Ps2MkBc_LOWER_THAN 		1
  #define Ps2MkBc_Y				1 
  #define Ps2MkBc_X 				1 
  #define Ps2MkBc_C 				1 
  #define Ps2MkBc_V 				1 
  #define Ps2MkBc_B 				1 
  #define Ps2MkBc_N 				1 
  #define Ps2MkBc_M 				1 
  #define Ps2MkBc_COMMA			1 
  #define Ps2MkBc_DOT				1 
  #define Ps2MkBc_MINUS			1 
  #define Ps2MkBc_SHIFT_R			1 
  #define Ps2MkBc_CTRL_L 			1 
  #define Ps2MkBc_WIN_L 				2 
  #define Ps2MkBc_ALT_L			1 
  #define Ps2MkBc_SPACE			1 
  #define Ps2MkBc_ALT_R 				2 
  #define Ps2MkBc_WIN_R 				2 
  #define Ps2MkBc_MENUS 				2 
  #define Ps2MkBc_CTRL_R 				2 
  #define Ps2MkBc_INSERT 				2 
  #define Ps2MkBc_HOME 				2 
  #define Ps2MkBc_PAGE_UP 			2 
  #define Ps2MkBc_DELETE 				2 
  #define Ps2MkBc_END 				2
  #define Ps2MkBc_PAGE_DOWN 			2
  #define Ps2MkBc_ARROW_UP			2 
  #define Ps2MkBc_ARROW_LEFT 			2 
  #define Ps2MkBc_ARROW_DOWN 			2 
  #define Ps2MkBc_ARROW_RIGHT 		2 
  #define Ps2MkBc_NUM_LOCK 		1 
  #define Ps2MkBc_NUMPAD_DIVIDE 		2 
  #define Ps2MkBc_NUMPAD_MULTI	1 
  #define Ps2MkBc_NUMPAD_MINUS	1 
  #define Ps2MkBc_NUMPAD_7		1 
  #define Ps2MkBc_NUMPAD_8		1 
  #define Ps2MkBc_NUMPAD_9		1 
  #define Ps2MkBc_NUMPAD_PLUS 	1 
  #define Ps2MkBc_NUMPAD_4		1 
  #define Ps2MkBc_NUMPAD_5		1 
  #define Ps2MkBc_NUMPAD_6		1 
  #define Ps2MkBc_NUMPAD_1		1 
  #define Ps2MkBc_NUMPAD_2		1 
  #define Ps2MkBc_NUMPAD_3		1 
  #define Ps2MkBc_NUMPAD_0		1 
  #define Ps2MkBc_NUMPAD_DECIMAL 	1 
  #define Ps2MkBc_NUMPAD_ENTER 		2 

  //ACPI Scancodes
  #define Ps2MkBc_AcpiPower 2 
  #define Ps2MkBc_AcpiSleep 2
  #define Ps2MkBc_AcpiWake  2  

  //Multimedia Scancodes
  #define Ps2MkBc_MmNextTrack 		2
  #define Ps2MkBc_MmPreviousTrack 	2
  #define Ps2MkBc_MmStop 				2
  #define Ps2MkBc_MmPlayPause 		2
  #define Ps2MkBc_MmMute 				2
  #define Ps2MkBc_MmVolumeUp 			2
  #define Ps2MkBc_MmVolumeDown 		2
  #define Ps2MkBc_MmMediaSelect 		2
  #define Ps2MkBc_MmEmail 			2
  #define Ps2MkBc_MmCalculator 		2
  #define Ps2MkBc_MmMyComputer 		2
  #define Ps2MkBc_MmWwwSearch 		2
  #define Ps2MkBc_MmWwwHome 			2
  #define Ps2MkBc_MmWwwBack 			2
  #define Ps2MkBc_MmWwwForward 		2
  #define Ps2MkBc_MmWwwStop 			2
  #define Ps2MkBc_MmWwwRefresh 		2
  #define Ps2MkBc_MmWwwFavorites 		2



#if 0
  /*
  Breakcodes
  */ 
  #define Ps2Bk_ESC 			/*0xF0,*/ 0x76 
  #define Ps2Bk_F1 			/*0xF0,*/ 0x05 
  #define Ps2Bk_F2 			/*0xF0,*/ 0x06 
  #define Ps2Bk_F3 			/*0xF0,*/ 0x04 
  #define Ps2Bk_F4 			/*0xF0,*/ 0x0C 
  #define Ps2Bk_F5 			/*0xF0,*/ 0x03 
  #define Ps2Bk_F6 			/*0xF0,*/ 0x0B 
  #define Ps2Bk_F7 			/*0xF0,*/ 0x83 
  #define Ps2Bk_F8 			/*0xF0,*/ 0x0A 
  #define Ps2Bk_F9 			/*0xF0,*/ 0x01 
  #define Ps2Bk_F10 			/*0xF0,*/ 0x09 
  #define Ps2Bk_F11 			/*0xF0,*/ 0x78 
  #define Ps2Bk_F12 			/*0xF0,*/ 0x07 
  #define Ps2Bk_PRINT			0xE0, 0xF0, 0x7C, 0xE0, 0xF0, 0x12 
  #define Ps2Bk_SCROLL_LOCK 	0xF0, 0x7E 
  #define Ps2Bk_BREAK 	 Ps2ScanCodeDummy //There is no breakcode for break 
  #define Ps2Bk_CIRCUMFLEX			0xF0, 0x0E 
  #define Ps2Bk_1				0xF0, 0x16 
  #define Ps2Bk_2				0xF0, 0x1E 
  #define Ps2Bk_3				0xF0, 0x26 
  #define Ps2Bk_4				0xF0, 0x25 
  #define Ps2Bk_5				0xF0, 0x2E 
  #define Ps2Bk_6				0xF0, 0x36 
  #define Ps2Bk_7				0xF0, 0x3D 
  #define Ps2Bk_8				0xF0, 0x3E 
  #define Ps2Bk_9				0xF0, 0x46 
  #define Ps2Bk_0				0xF0, 0x45 
  #define Ps2Bk_QUESTIONMARK	0xF0, 0x4E 
  #define Ps2Bk_APOS			0xF0, 0x55 
  #define Ps2Bk_BACKSPACE 	0xF0, 0x66 
  #define Ps2Bk_TAB 			0xF0, 0x0D 
  #define Ps2Bk_Q 			0xF0, 0x15 
  #define Ps2Bk_W 			0xF0, 0x1D 
  #define Ps2Bk_E 			0xF0, 0x24 
  #define Ps2Bk_R 			0xF0, 0x2D 
  #define Ps2Bk_T 			0xF0, 0x2C 
  #define Ps2Bk_Z				0xF0, 0x35 
  #define Ps2Bk_U 			0xF0, 0x3C 
  #define Ps2Bk_I 			0xF0, 0x43 
  #define Ps2Bk_O 			0xF0, 0x44 
  #define Ps2Bk_P 			0xF0, 0x4D 
  #define Ps2Bk_UE			0xF0, 0x54 
  #define Ps2Bk_ASTERISK		0xF0, 0x5B 
  #define Ps2Bk_SHARP			0xF0, 0x5D 
  #define Ps2Bk_CAPS_LOCK 	0xF0, 0x58 
  #define Ps2Bk_A 			0xF0, 0x1C 
  #define Ps2Bk_S 			0xF0, 0x1B 
  #define Ps2Bk_D 			0xF0, 0x23 
  #define Ps2Bk_F 			0xF0, 0x2B 
  #define Ps2Bk_G 			0xF0, 0x34 
  #define Ps2Bk_H 			0xF0, 0x33 
  #define Ps2Bk_J 			0xF0, 0x3B 
  #define Ps2Bk_K 			0xF0, 0x42 
  #define Ps2Bk_L 			0xF0, 0x4B 
  #define Ps2Bk_OE			0xF0, 0x4C 
  #define Ps2Bk_AE			0xF0, 0x52 
  #define Ps2Bk_ENTER 		0xF0, 0x5A 
  #define Ps2Bk_SHIFT_L 		0xF0, 0x12
  #define Ps2Bk_LOWER_THAN 		0xF0, 0x61
  #define Ps2Bk_Y				0xF0, 0x1A 
  #define Ps2Bk_X 			0xF0, 0x22 
  #define Ps2Bk_C 			0xF0, 0x21 
  #define Ps2Bk_V 			0xF0, 0x2A 
  #define Ps2Bk_B 			0xF0, 0x32 
  #define Ps2Bk_N 			0xF0, 0x31 
  #define Ps2Bk_M 			0xF0, 0x3A 
  #define Ps2Bk_COMMA			0xF0, 0x41 
  #define Ps2Bk_DOT			0xF0, 0x49 
  #define Ps2Bk_MINUS			0xF0, 0x4A 
  #define Ps2Bk_SHIFT_R		0xF0, 0x59 
  #define Ps2Bk_CTRL_L 		0xF0, 0x14 
  #define Ps2Bk_WIN_L 		0xE0, 0xF0, 0x1F 
  #define Ps2Bk_ALT_L			0xF0, 0x11 
  #define Ps2Bk_SPACE			0xF0, 0x29 
  #define Ps2Bk_ALT_R 		0xE0, 0xF0, 0x11 
  #define Ps2Bk_WIN_R 		0xE0, 0xF0, 0x27 
  #define Ps2Bk_MENUS 		0xE0, 0xF0, 0x2F 
  #define Ps2Bk_CTRL_R 		0xE0, 0xF0, 0x14 
  #define Ps2Bk_INSERT 		0xE0, 0xF0, 0x70 
  #define Ps2Bk_HOME 			0xE0, 0xF0, 0x6C 
  #define Ps2Bk_PAGE_UP 		0xE0, 0xF0, 0x7D 
  #define Ps2Bk_DELETE 		0xE0, 0xF0, 0x71 
  #define Ps2Bk_END 			0xE0, 0xF0, 0x69 
  #define Ps2Bk_PAGE_DOWN 	0xE0, 0xF0, 0x7A 
  #define Ps2Bk_ARROW_UP		0xE0, 0xF0, 0x75 
  #define Ps2Bk_ARROW_LEFT 	0xE0, 0xF0, 0x6B 
  #define Ps2Bk_ARROW_DOWN 	0xE0, 0xF0, 0x72 
  #define Ps2Bk_ARROW_RIGHT 	0xE0, 0xF0, 0x74 
  #define Ps2Bk_NUM_LOCK 		0xF0, 0x77 
  #define Ps2Bk_NUMPAD_DIVIDE 0xE0, 0xF0, 0x4A 
  #define Ps2Bk_NUMPAD_MULTI	0xF0, 0x7C 
  #define Ps2Bk_NUMPAD_MINUS	0xF0, 0x7B 
  #define Ps2Bk_NUMPAD_7		0xF0, 0x6C 
  #define Ps2Bk_NUMPAD_8		0xF0, 0x75 
  #define Ps2Bk_NUMPAD_9		0xF0, 0x7D 
  #define Ps2Bk_NUMPAD_PLUS 	0xF0, 0x79 
  #define Ps2Bk_NUMPAD_4		0xF0, 0x6B 
  #define Ps2Bk_NUMPAD_5		0xF0, 0x73 
  #define Ps2Bk_NUMPAD_6		0xF0, 0x74 
  #define Ps2Bk_NUMPAD_1		0xF0, 0x69 
  #define Ps2Bk_NUMPAD_2		0xF0, 0x72 
  #define Ps2Bk_NUMPAD_3		0xF0, 0x7A 
  #define Ps2Bk_NUMPAD_0		0xF0, 0x70 
  #define Ps2Bk_NUMPAD_DECIMAL 	0xF0, 0x71 
  #define Ps2Bk_NUMPAD_ENTER 	0xE0, 0xF0, 0x5A


  //ACPI Scancodes

  #define Ps2Bk_AcpiPower 0xe0, 0xde
  #define Ps2Bk_AcpiSleep 0xe0, 0xdf
  #define Ps2Bk_AcpiWake  0xe0, 0xe3

  //Multimedia Scancodes
  #define Ps2Bk_MmNextTrack 		0xe0, 0x99
  #define Ps2Bk_MmPreviousTrack 	0xe0, 0x90
  #define Ps2Bk_MmStop 			0xe0, 0xa4
  #define Ps2Bk_MmPlayPause 		0xe0, 0xa2
  #define Ps2Bk_MmMute 			0xe0, 0xa0
  #define Ps2Bk_MmVolumeUp 		0xe0, 0xb0
  #define Ps2Bk_MmVolumeDown 		0xe0, 0xae
  #define Ps2Bk_MmMediaSelect 	0xe0, 0xed
  #define Ps2Bk_MmEmail 			0xe0, 0xec
  #define Ps2Bk_MmCalculator 		0xe0, 0xa1
  #define Ps2Bk_MmMyComputer 		0xe0, 0xeb
  #define Ps2Bk_MmWwwSearch 		0xe0, 0xe5
  #define Ps2Bk_MmWwwHome 		0xe0, 0xb2
  #define Ps2Bk_MmWwwBack 		0xe0, 0xea
  #define Ps2Bk_MmWwwForward 		0xe0, 0xe9
  #define Ps2Bk_MmWwwStop 		0xe0, 0xe8
  #define Ps2Bk_MmWwwRefresh 		0xe0, 0xe7
  #define Ps2Bk_MmWwwFavorites 	0xe0, 0xe6


  /*
  Breakcode byte counts
  */

  #define Ps2BkBc_ESC 			2 
  #define Ps2BkBc_F1 				2 
  #define Ps2BkBc_F2 				2 
  #define Ps2BkBc_F3 				2 
  #define Ps2BkBc_F4 				2 
  #define Ps2BkBc_F5 				2 
  #define Ps2BkBc_F6 				2 
  #define Ps2BkBc_F7 				2 
  #define Ps2BkBc_F8 				2 
  #define Ps2BkBc_F9 				2 
  #define Ps2BkBc_F10 			2 
  #define Ps2BkBc_F11 			2 
  #define Ps2BkBc_F12 			2 
  #define Ps2BkBc_PRINT				6 
  #define Ps2BkBc_SCROLL_LOCK 	2 
  #define Ps2BkBc_BREAK 				0 
  #define Ps2BkBc_CIRCUMFLEX			2 
  #define Ps2BkBc_1				2 
  #define Ps2BkBc_2				2 
  #define Ps2BkBc_3				2 
  #define Ps2BkBc_4				2 
  #define Ps2BkBc_5				2 
  #define Ps2BkBc_6				2 
  #define Ps2BkBc_7				2 
  #define Ps2BkBc_8				2 
  #define Ps2BkBc_9				2 
  #define Ps2BkBc_0				2 
  #define Ps2BkBc_QUESTIONMARK	2 
  #define Ps2BkBc_APOS			2 
  #define Ps2BkBc_BACKSPACE 		2 
  #define Ps2BkBc_TAB 			2 
  #define Ps2BkBc_Q 				2 
  #define Ps2BkBc_W 				2 
  #define Ps2BkBc_E 				2 
  #define Ps2BkBc_R 				2 
  #define Ps2BkBc_T 				2 
  #define Ps2BkBc_Z				2 
  #define Ps2BkBc_U 				2 
  #define Ps2BkBc_I 				2 
  #define Ps2BkBc_O 				2 
  #define Ps2BkBc_P 				2 
  #define Ps2BkBc_UE				2 
  #define Ps2BkBc_ASTERISK		2 
  #define Ps2BkBc_SHARP			2 
  #define Ps2BkBc_CAPS_LOCK 		2 
  #define Ps2BkBc_A 				2 
  #define Ps2BkBc_S 				2 
  #define Ps2BkBc_D 				2 
  #define Ps2BkBc_F 				2 
  #define Ps2BkBc_G 				2 
  #define Ps2BkBc_H 				2 
  #define Ps2BkBc_J 				2 
  #define Ps2BkBc_K 				2 
  #define Ps2BkBc_L 				2 
  #define Ps2BkBc_OE				2 
  #define Ps2BkBc_AE				2 
  #define Ps2BkBc_ENTER 			2 
  #define Ps2BkBc_SHIFT_L 		2
  #define Ps2BkBc_LOWER_THAN 		2
  #define Ps2BkBc_Y				2 
  #define Ps2BkBc_X 				2 
  #define Ps2BkBc_C 				2 
  #define Ps2BkBc_V 				2 
  #define Ps2BkBc_B 				2 
  #define Ps2BkBc_N 				2 
  #define Ps2BkBc_M 				2 
  #define Ps2BkBc_COMMA			2 
  #define Ps2BkBc_DOT				2 
  #define Ps2BkBc_MINUS			2 
  #define Ps2BkBc_SHIFT_R			2 
  #define Ps2BkBc_CTRL_L 			2 
  #define Ps2BkBc_WIN_L 				3 
  #define Ps2BkBc_ALT_L			2 
  #define Ps2BkBc_SPACE			2 
  #define Ps2BkBc_ALT_R 				3 
  #define Ps2BkBc_WIN_R 				3 
  #define Ps2BkBc_MENUS 				3 
  #define Ps2BkBc_CTRL_R 				3 
  #define Ps2BkBc_INSERT 				3 
  #define Ps2BkBc_HOME 				3 
  #define Ps2BkBc_PAGE_UP 			3 
  #define Ps2BkBc_DELETE 				3 
  #define Ps2BkBc_END 				3 
  #define Ps2BkBc_PAGE_DOWN 			3 
  #define Ps2BkBc_ARROW_UP			3 
  #define Ps2BkBc_ARROW_LEFT 			3 
  #define Ps2BkBc_ARROW_DOWN 			3 
  #define Ps2BkBc_ARROW_RIGHT 		3 
  #define Ps2BkBc_NUM_LOCK 		2 
  #define Ps2BkBc_NUMPAD_DIVIDE 		3 
  #define Ps2BkBc_NUMPAD_MULTI	2 
  #define Ps2BkBc_NUMPAD_MINUS	2 
  #define Ps2BkBc_NUMPAD_7		2 
  #define Ps2BkBc_NUMPAD_8		2 
  #define Ps2BkBc_NUMPAD_9		2 
  #define Ps2BkBc_NUMPAD_PLUS 	2 
  #define Ps2BkBc_NUMPAD_4		2 
  #define Ps2BkBc_NUMPAD_5		2 
  #define Ps2BkBc_NUMPAD_6		2 
  #define Ps2BkBc_NUMPAD_1		2 
  #define Ps2BkBc_NUMPAD_2		2 
  #define Ps2BkBc_NUMPAD_3		2 
  #define Ps2BkBc_NUMPAD_0		2 
  #define Ps2BkBc_NUMPAD_DECIMAL 	2 
  #define Ps2BkBc_NUMPAD_ENTER 		3

  //ACPI Scancodes
  #define Ps2BkBc_AcpiPower 2 
  #define Ps2BkBc_AcpiSleep 2
  #define Ps2BkBc_AcpiWake  2  

  //Multimedia Scancodes
  #define Ps2BkBc_MmNextTrack 		2
  #define Ps2BkBc_MmPreviousTrack 	2
  #define Ps2BkBc_MmStop 				2
  #define Ps2BkBc_MmPlayPause 		2
  #define Ps2BkBc_MmMute 				2
  #define Ps2BkBc_MmVolumeUp 			2
  #define Ps2BkBc_MmVolumeDown 		2
  #define Ps2BkBc_MmMediaSelect 		2
  #define Ps2BkBc_MmEmail 			2
  #define Ps2BkBc_MmCalculator 		2
  #define Ps2BkBc_MmMyComputer 		2
  #define Ps2BkBc_MmWwwSearch 		2
  #define Ps2BkBc_MmWwwHome 			2
  #define Ps2BkBc_MmWwwBack 			2
  #define Ps2BkBc_MmWwwForward 		2
  #define Ps2BkBc_MmWwwStop 			2
  #define Ps2BkBc_MmWwwRefresh 		2
  #define Ps2BkBc_MmWwwFavorites 		2
#endif  