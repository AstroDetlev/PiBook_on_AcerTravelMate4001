/*
   2021-12-01

   Target System: Arduino Mega2560

   This sketch is made to interface a keyboard matrix of an Acer TravelMate 4001 WLMI.
   The keyboard matrix offers 24 pins and does not contain additional electronic.

   This keyboard is NOT organised 8 by 11. It is much worse. In fact, All pins have to be observed, if any of them is connected to another.
   There is no set of pins that are "rows" and others that are "columns". They are both.

   How it works:
   1. All 24 pins are connected to the Arduino.
   2. All Pins are input, with Pullup High
   3. One of the Pins is set to OUTPUT Low
   4. Check the Inputs. Is there any LOW?
   5. If yes, decode which key was pressed and send this String over the serial
   6. The OUTPUT Pin is set to Input Pullup again
   7. The next Pin is set to OUTPUT Low.
   8. Repeat 4 - 7 with all pins
   9. Reapeat 2 - 8

   The key detection raw value are just 2 numbers: The pin that is set to LOW and the pin that is detected as LOW.
   These two number are used as index for the matrix array.

   A valid key press leads to an array cell unequal 0. This number is the index for the two decoder arrays, which contain human- and machine-readable outputs

   There might be smarter ways to deal with 89 keys than to use an array with > 500 cells, but this is how it works for me.
   There is no if-else or select-case nightmare, and the data is structured in a way that is easy to adapt for other keyboards.

   To speed up detection, only one half (triangle) of the matrix is used and filled with data. As a result, only half of the possible connections is checked.
   Example: the connection between 4 and 17 is checked (Leads to 29, "Page Down"), but not between 17 and 4, because [17][4] stays filled with 0 in the matrix.
   The wanted side effect: With increasing pin numbers (counter in the loop), the checks to be done decrease.
   There are two loops running to set the inputs/outputs. The outer loop goes over all pins, while the inner loop starts at the current value +1 of the outer loop.
   Example: If the outer Loop is at index 17, the inner loop goes from 18 to max, not from 1 to max. In fact , it goes to max-1, as this last opton is not used
   for this special keyboard matrix.





  Currently there's a delay in the loop, to reduce the output speed and make things easier to read at the screen.

  For a real keyboard detection, think of interrupts!

  There are 24 Pins in use. To make wiring easy, the 2-row extension on the Mega2560 is used.

  Pin 22 on A.Mega2560 is PA0
  ...
  Pin 29 on A.Mega2560 is PA7

  Pin 30 on A.Mega2560 is PC7 (NOT PC0!!!!)
  ...
  Pin 37 on A.Mega2560 is PC0 (NOT PC7!!!!)

  Pin 38 on A.Mega2560 is PD7

  Pin 39 on A.Mega2560 is PG2
  Pin 40 on A.Mega2560 is PG1
  Pin 41 on A.Mega2560 is PG0

  Pin 42 on A.Mega2560 is PL7
  ...
  Pin 49 on A.Mega2560 is PL0

  Pin 50 on A.Mega2560 is PB3(MISO)
  Pin 51 on A.Mega2560 is PB2(MOSI)
  Pin 52 on A.Mega2560 is PB1(SCK)
  Pin 53 on A.Mega2560 is PB0(SS)

  Pin1 of the Matrix is connected with Pin 22 of the Arduino
  Pin2 of the Matrix is connected with Pin 23 of the Arduino
  ...
  Pin24 of the Matrix is connected with Pin 45 of the Arduino


  Usefull details for PS/2
  https://www.marjorie.de/ps2/ps2_protocol.htm

*/


#include "ACER_TRAVELMATE4001WLMI_KEYBOARD_MATRIX.h"

#define LOWEST_PIN 22
#define HIGHEST_PIN LOWEST_PIN + 23  /* LOWEST_PIN itself is 1 pin, so there are 23 in addition*/
#define DELAY_MS 0

bool CurrentlyPressedKeys[90];
bool PreviouslyPressedKeys[90];


// the setup routine runs once when you press reset

void setup() {

  // initialize serial communication at 9600 bits per second:
  //This is the debug output.
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop()
{
  int i;
  //backup the old data
  i = 90;
  while ( i-- ) *( PreviouslyPressedKeys + i ) = *( CurrentlyPressedKeys + i );
  //get new data
  DetectPressedKeys();
  //delay(50);
  for (i = 0; i < 90; i++)
  {
    if (PreviouslyPressedKeys[i] != CurrentlyPressedKeys[i])
    {
      //change detected
      if (CurrentlyPressedKeys[i])
      {
        Serial.print("pressed: ");
      }
      else
      {
        Serial.print("released: ");
      }
      Serial.println(HumanReadableDecoder[i]);
    }
  }
}


//This determines the currently pressed keys. The result is the array of bool CurrentlyPressedKeys
void DetectPressedKeys()
{

  char outer_loop, inner_loop, matrix_axis_2, matrix_axis_1, key_number, key_detect;
  int dly = 1; //the delay


  //over the pins of the mega2560 extension. This makes wiring easy
  for (outer_loop = LOWEST_PIN; outer_loop <= (HIGHEST_PIN); outer_loop++)
  {

    //set one pin as output
    pinMode(outer_loop, OUTPUT);
    //set this pin LOW. All others are pulled up High
    digitalWrite(outer_loop, LOW);
    // wait to stabelize
    //delayMicroseconds(5);
    //over all these pins, but only less than half of the matrix (triangle). That's why the start is shifting with each turn.
    for (inner_loop = outer_loop + 1; inner_loop <= (HIGHEST_PIN) ; inner_loop++)
    {
      //set the other pins as input if it is not the current LOW pin
      if (outer_loop != inner_loop)
      {
        //remove the offset
        matrix_axis_1 = inner_loop - LOWEST_PIN + 1;
        matrix_axis_2 = outer_loop - LOWEST_PIN + 1;
        key_number = int((Matrix[matrix_axis_2 - 1][matrix_axis_1 - 1])); //shift by 1. The first entry is at [0][0]!
        //get the value if it can be assigned to a valid key. Otherwise skip.
        if (key_number != ID_KEY_UNKNOWN)
        {
          pinMode(inner_loop, INPUT_PULLUP);
          //store the result (a bool) at the right place in the summary. 
          //But invert it as a pressed key gives the LOW from the outer_loop, not a HIGH
          CurrentlyPressedKeys[key_number] = !digitalRead(inner_loop);
        }
      }
    }
    //close the door
    pinMode(outer_loop, INPUT);
  }
  //a printout of a "." to signalize a full turn. Two "." in series means no key press detected.
  //Serial.print("\n.");
}
