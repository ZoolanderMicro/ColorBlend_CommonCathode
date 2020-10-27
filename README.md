# ColorBlend_CommonCathode
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
