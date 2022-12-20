// Exploding gift timer

#include <Timer.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include <SimpleRotary.h>

#define PIN 4
const long days2ms = 86400000;
const long hour2ms = 3600000;
const long min2ms  = 60000;
const long sec2ms  = 1000;
const double ms2days = 1.0/days2ms;
const double ms2hour = 1.0/hour2ms;
const double ms2min  = 1.0/min2ms;
const double ms2sec  = 1.0/sec2ms;

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS    + NEO_MATRIX_PROGRESSIVE,
  NEO_GRBW           + NEO_KHZ800);
  
int cursor_pos = 0;

// Declare timer object and global counter
Timer t;
const unsigned long frame_period_ms = 80;

SimpleRotary rotary(5, 6, 7);

const uint32_t image_data_up[] PROGMEM = {
  0xffeb3b, 0xffeb3b, 0xffeb3b, 0x00bcd4, 0x00bcd4, 0xffeb3b, 0xffeb3b, 0xffeb3b, 
  0xffeb3b, 0xffeb3b, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0xffeb3b, 0xffeb3b, 
  0xffeb3b, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0xffeb3b, 
  0x00bcd4, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0x00bcd4, 0x00bcd4, 
  0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 
  0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 
  0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 
  0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xffeb3b
};

char message[100];  // max length you’ll need +1

const long t2tgt_ini_ms = 289800 * 1000;

void setup() {
  Serial.begin(115200);
  
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(1);
  matrix.setTextColor(matrix.Color(0x08, 0x55, 0xFF));
    
  // Setup the display thread
  t.every(150, display_frame_event);
}

void loop() {
  // Update rotary encoder state
  byte rotation = rotary.rotate();  
  
  // Update timed threads
  if(rotation == 1) {
    // Clockwise
    if(cursor_pos > -82) cursor_pos = cursor_pos - 2;
  }
  else if(rotation == 2) {
    // Counter clockwise
    if(cursor_pos < 1) cursor_pos = cursor_pos + 2;
  }
  t.update();
}

void display_frame_event() {
  long t_cur_ms = millis();
  long t2tgt_cur_ms = t2tgt_ini_ms - millis();

  long t2tgt_cur_days = t2tgt_cur_ms * ms2days; 
  t2tgt_cur_ms = t2tgt_cur_ms - t2tgt_cur_days * days2ms;
  long t2tgt_cur_hour = t2tgt_cur_ms * ms2hour; 
  t2tgt_cur_ms = t2tgt_cur_ms - t2tgt_cur_hour * hour2ms;
  long t2tgt_cur_min = t2tgt_cur_ms * ms2min; 
  t2tgt_cur_ms = t2tgt_cur_ms - t2tgt_cur_min * min2ms;
  long t2tgt_cur_sec = t2tgt_cur_ms * ms2sec; 

  sprintf(message, "%djours %02d:%02d:%02d", 
          (int)t2tgt_cur_days, 
          (int)t2tgt_cur_hour, 
          (int)t2tgt_cur_min, 
          (int)t2tgt_cur_sec);
  
  //Serial.print(message);
  matrix.fillScreen(0);
  matrix.setCursor(cursor_pos, 0);
  matrix.print(message);
  matrix.show();
}
