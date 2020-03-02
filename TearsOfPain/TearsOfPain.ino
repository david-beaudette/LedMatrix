/* 
  Tears of Pain Game
  
  by David Beaudette
   
  Video game using a rotary encoder as control and an 8x8 RGB led matrix as the display.

  Just escape the falling tears.
  
*/

#include <Timer.h>

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#include <SimpleRotary.h>

//#define DEBUG_OUT;

// NeoPixel library construction
// Parameter 1 = number of pixels in ledmatrix
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel ledmatrix = Adafruit_NeoPixel(64, 4, NEO_GRBW + NEO_KHZ800);

const uint32_t cursor_colors[] PROGMEM = {
    0x009900, 0xbb99ff, 0xff0066, 0xff0000 };
    
// Declare timer object and global counter
Timer t;

// Declare game variables
const uint8_t num_tears = 8;
const unsigned long frame_period_ms = 150;
const uint8_t tears_num_speed = 5;
const uint8_t collision_num_period = 5;

int8_t cursor_pos;
uint8_t tears_pos[num_tears];
uint8_t tears_period_count[num_tears];
uint8_t tears_collision_period_count[num_tears];

byte controller_rotation;

// Speed between 0 and (tears_num_speed - 1)
uint8_t tears_speed[num_tears];

SimpleRotary rotary(5, 6, 7);

void setup() {
  // Setup serial for debugging
  Serial.begin(115200);
  
  // Setup the led matrix
  ledmatrix.begin();
  ledmatrix.setBrightness(30);
  ledmatrix.show(); // Initialise all pixels to 'off'

  // Setup the game timed thread
  int8_t game_frame_event = t.every(frame_period_ms, GameFrame);

  // Initialise the game variables
  cursor_pos = 0;
  for(uint8_t i = 0; i < num_tears; ++i) {
    tears_pos[i] = i;
    //tears_speed[i] = (i % (tears_num_speed));
     tears_speed[i] = 1;
    tears_period_count[i] = 0;
    tears_collision_period_count[i] = 0;
  }
  controller_rotation = 0;
}

void loop() {
  // Update rotary encoder state
  byte rotation = rotary.rotate();  
  
  // Update timed threads
  t.update();
  if(rotation == 1) {
    // Clockwise
    controller_rotation = 1;
  }
  else if(rotation == 2) {
    // Counter clockwise
    controller_rotation = 2;
  }
}

void GameFrame() {
  
  // Update cursor position
  if(tears_collision_period_count[cursor_pos] == 0) {
    if(controller_rotation == 1) {
      // Clockwise    
      cursor_pos = (++cursor_pos % 8);
    }
    else if(controller_rotation == 2) {
      // Counter clockwise
      cursor_pos = --cursor_pos;
      if(cursor_pos < 0) cursor_pos = 7;
    }
    controller_rotation = 0;
  }
  
  // Update tears of pain
  for(uint8_t i = 0; i < num_tears; ++i) {

    uint8_t line_num = i % 8;
    // Tear period between tears_num_speed and 1 cycles 
    uint8_t tear_period = tears_num_speed - tears_speed[i];

    tears_period_count[i] = ++tears_period_count[i];
    if(tears_period_count[i] == tear_period) {
      tears_pos[i] = (++tears_pos[i] % 8);
      tears_period_count[i] = 0;
    }

    // Detect collision
    if(tears_pos[i] == 7) {
      if((cursor_pos == line_num) && (tears_collision_period_count[i] == 0)) {
#ifdef DEBUG_OUT
Serial.println("Collision!");
#endif
        tears_collision_period_count[i] = collision_num_period;
        tears_pos[i] = 0;
      }
    }
    if(tears_collision_period_count[i] > 0) {
      --tears_collision_period_count[i];  
    }       
  }
  // Draw frame
  ledmatrix.clear();
  ledmatrix.setPixelColor(cursor_pos + 7 * 8, 
                          pgm_read_dword(&(
                            cursor_colors[tears_collision_period_count[cursor_pos]])));
  for(uint8_t i = 0; i < num_tears; ++i) {
    ledmatrix.setPixelColor((i % 8) + tears_pos[i] * 8, 0x000099);
  }
  ledmatrix.show();
  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c) {
  for(uint16_t i = 0; i < ledmatrix.numPixels(); ++i) {
    ledmatrix.setPixelColor(i, c);
    ledmatrix.show();
    delay(25);
    
  }
  // Erase
  ledmatrix.clear();
  ledmatrix.show();
  
}
