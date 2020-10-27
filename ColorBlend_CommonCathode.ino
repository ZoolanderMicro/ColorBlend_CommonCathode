#include <avr/io.h>
#include <util/delay.h>
/**
   Scetch ColorBlend_CommonCathode is a color fade/blend routine for a tri-color
   common cathode led connected to Arduino Uno digital pins 9, 10, and 11 as PWM
   outputs. Colors transition from blue through teal, green, yellow, orange, red,
   violet, purple, and back to blue. With common cathode tri-colored leds,
   analogWrite() value of 0 results in a full 'off' state, and analogWrite()   
   value of 255 results in a full 'on' state. This scetch works with common
   anode tri-colored leds, only the color blend runs in the opposite order.
   Written in Arduino C language.
   @author Mike Tonge
   @date 12/03/2019
*/
// Constants
const uint8_t DELAY_TIME = 100; // Delay time (miliseconds)
const uint8_t redLED = 9; // Red on digital pin 9
const uint8_t grnLED = 10; // Green on digital pin 10
const uint8_t bluLED = 11; // Blue on digital pin 11
const uint8_t OFF = 0; // Value used to turn led off
// Variables
uint8_t redVal = 0; // Red value
uint8_t grnVal = 0; // Green value
uint8_t bluVal = 0; // Blue value

void setup() {
  pinMode(redLED, OUTPUT); // Set pin 9 as output
  pinMode(grnLED, OUTPUT); // Set pin 10 as output
  pinMode(bluLED, OUTPUT); // Set pin 11 as output
}

void loop() {
  for (int count = 0; count <= 765; count++) {
    switch (count) {
      // Red is off, Green gets brighter, Blue gets dimmer
      case 0 ... 255:
        redVal = OFF;
        grnVal = count;
        bluVal = 255 - count;
        break;
      // Red gets brighter, Green gets dimmer, Blue is off
      case 256 ... 510:
        redVal = count - 255;
        grnVal = 510 - count;
        bluVal = OFF;
        break;
      // Red gets dimmer, Green is off, Blue gets brighter
      case 511 ... 765:
        redVal = 765 - count;
        grnVal = OFF;
        bluVal = count - 510;
        break;
      default:
        break;
    } // End switch
    analogWrite(redLED, redVal);
    analogWrite(grnLED, grnVal);
    analogWrite(bluLED, bluVal);
    delay(DELAY_TIME);
  }
}
