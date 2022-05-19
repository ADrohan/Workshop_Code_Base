/*************************************************************
To use the Pixel Board you must include the Adafruit NeoPixel library
This library is not installed by default. 

To install: 
Go to sketch  > Include Library > Manage Libraries
Search for Adafruit NeoPixel. You may see similar options available
Look for the Adafruit library for controlling single wire based LED pixels and strips
Click install
**************************************************************/

// include the library
#include <Adafruit_NeoPixel.h>

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. It doesn't have to be a pwm pin.

#define PIN 4 // here the pixels are attached to pin 4. 
#define NUMPIXELS 1  // with one pixel attached

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel
}

void loop() {

    // the pixel colour takes RGB values, from 0,0,0 up to 255,255,255
    // Below we're using a pink color: 100, 0, 125
    // the first 0 stand for the first led connected.
    pixels.setPixelColor(0, 100, 0, 125);

    pixels.show();   // Send the updated pixel colors to the hardware.
}
