/*
 * 2022-02-10
 * 
 * Target System: Arduino Mega2560
 * Arduino IDE: 1.8.19
 * 
*/

//Define the Pins
//HIGHEST_MATRIX_PIN + 1,2,3 is occupied by the Keyboard LEDs
const unsigned char DISP_KEY1_PIN        = HIGHEST_MATRIX_PIN + 4; //Give better names later
const unsigned char DISP_KEY2_PIN        = HIGHEST_MATRIX_PIN + 5;
const unsigned char DISP_KEY3_PIN        = HIGHEST_MATRIX_PIN + 6;
const unsigned char DISP_KEY4_PIN        = HIGHEST_MATRIX_PIN + 7;
const unsigned char DISP_KEY5_PIN        = HIGHEST_MATRIX_PIN + 8;

const unsigned char DISP_KEY1 = 0x01;
const unsigned char DISP_KEY2 = 0x02;
const unsigned char DISP_KEY3 = 0x04;
const unsigned char DISP_KEY4 = 0x08;
const unsigned char DISP_KEY5 = 0x10;