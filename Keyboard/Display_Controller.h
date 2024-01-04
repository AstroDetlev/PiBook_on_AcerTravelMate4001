/*
 * 2022-02-10
 * 
 * Target System: Arduino Mega2560
 * Arduino IDE: 1.8.19
 * 
*/

//The display control PCB used 5 buttons.
	#define DISP_CTRL_PINCOUNT 5
	
  //The values that represent the Display Buttons. Used to call the function
	#define BITVAL_DISP_CTRL_PIN1 0x01
	#define BITVAL_DISP_CTRL_PIN2 0x02
	#define BITVAL_DISP_CTRL_PIN3 0x04
	#define BITVAL_DISP_CTRL_PIN4 0x08
	#define BITVAL_DISP_CTRL_PIN5 0x10


  #define BITVAL_DISP_CTRL_PIN1 0x01
	#define BITVAL_DISP_CTRL_PIN2 0x02
	#define BITVAL_DISP_CTRL_PIN3 0x04
	#define BITVAL_DISP_CTRL_PIN4 0x08
	#define BITVAL_DISP_CTRL_PIN5 0x10


	//alias names
	#define DISP_CTRL_POWER 	DISP_CTRL_PIN1
	#define DISP_CTRL_DOWN	 	DISP_CTRL_PIN2
	#define DISP_CTRL_UP	   	DISP_CTRL_PIN3
	#define DISP_CTRL_MENU	 	DISP_CTRL_PIN4
	#define DISP_CTRL_AUTO	 	DISP_CTRL_PIN5

  #define BITVAL_DISP_CTRL_POWER 		BITVAL_DISP_CTRL_PIN1
  #define BITVAL_DISP_CTRL_DOWN	 	BITVAL_DISP_CTRL_PIN2
  #define BITVAL_DISP_CTRL_UP	 		BITVAL_DISP_CTRL_PIN3
  #define BITVAL_DISP_CTRL_MENU	 	BITVAL_DISP_CTRL_PIN4
  #define BITVAL_DISP_CTRL_AUTO	 	BITVAL_DISP_CTRL_PIN5


  //A list of the Display Control button pins. They might not be in an unbroken row of pin numbers.
const uint8_t DisplayButtonPin[DISP_CTRL_PINCOUNT] = {
  DISP_CTRL_PIN1,
  DISP_CTRL_PIN2,
  DISP_CTRL_PIN3,
  DISP_CTRL_PIN4,
  DISP_CTRL_PIN5
};

