#include <Adafruit_NeoPixel.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRBW + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

const uint32_t image_data_Melon[] PROGMEM = {
    0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
    0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
    0x37662e, 0xff7062, 0xd4222b, 0x7b2824, 0xdc2738, 0xe53d40, 0xd87563, 0x308247, 
    0x378633, 0xffef75, 0xe23541, 0xe1404e, 0x844548, 0xff8c7c, 0xe9eb61, 0x2f874b, 
    0x4a8a47, 0xf8dc6a, 0xf9807c, 0xfd847d, 0xff837d, 0xf28d6b, 0xcace58, 0x528d6b, 
    0x000000, 0x3d8334, 0xe7ef55, 0xe0e460, 0xdee960, 0xc6d25d, 0x3f915b, 0x000000, 
    0x000000, 0x000000, 0x307844, 0x3d8451, 0x378549, 0x548d5f, 0x000000, 0x000000, 
    0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000
};

const uint32_t image_data_Couleurs[] PROGMEM = {
    0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 
    0xe91e63, 0xe91e63, 0xe91e63, 0x64dd17, 0x64dd17, 0x64dd17, 0xe91e63, 0xe91e63, 
    0xe91e63, 0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xe91e63, 
    0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0x76ff03, 0x76ff03, 0x76ff03, 0xffeb3b, 
    0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0x76ff03, 0x76ff03, 0x76ff03, 0xffeb3b, 
    0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0x76ff03, 0x76ff03, 0x76ff03, 0xffeb3b, 
    0xe91e63, 0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xe91e63, 
    0xe91e63, 0xe91e63, 0xe91e63, 0x64dd17, 0x64dd17, 0x64dd17, 0xe91e63, 0xe91e63
};

const uint32_t image_data_Arbre[] PROGMEM = {
    0x0097a7, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x0097a7, 
    0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 
    0x0097a7, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x0097a7, 
    0x0097a7, 0x0097a7, 0x004d40, 0x795548, 0x004d40, 0x004d40, 0x0097a7, 0x0097a7, 
    0x81c784, 0x81c784, 0x81c784, 0x795548, 0x81c784, 0x81c784, 0x81c784, 0x81c784, 
    0x81c784, 0x81c784, 0x81c784, 0x795548, 0x81c784, 0x81c784, 0x81c784, 0x81c784, 
    0x81c784, 0x81c784, 0x81c784, 0x795548, 0x81c784, 0x81c784, 0x81c784, 0x81c784, 
    0x81c784, 0x81c784, 0x81c784, 0x795548, 0x81c784, 0x81c784, 0x81c784, 0x81c784
};

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  // End of trinket special code

  strip.begin();
  strip.setBrightness(30);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(0, 0, 0, 127), 20); // Blue

  show_melon();
  delay(5000);
  
  show_couleurs();
  delay(5000);
  
  show_arbre();
  delay(5000);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint32_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void show_melon() {
  for(uint16_t i=0; i < strip.numPixels(); i++) {
    uint16_t idx = 3*i;
    strip.setPixelColor(i, pgm_read_dword(&(image_data_Melon[i])));
  }
  strip.show();
}

void show_couleurs() {
  for(uint16_t i=0; i < strip.numPixels(); i++) {
    uint16_t idx = 3*i;
    strip.setPixelColor(i, pgm_read_dword(&(image_data_Couleurs[i])));
  }
  strip.show();
}

void show_arbre() {
  for(uint16_t i=0; i < strip.numPixels(); i++) {
    uint16_t idx = 3*i;
    strip.setPixelColor(i, pgm_read_dword(&(image_data_Arbre[i])));
  }
  strip.show();
}

void rainbow(uint32_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint32_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint32_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint32_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
