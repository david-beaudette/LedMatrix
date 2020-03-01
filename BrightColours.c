
/*******************************************************************************
* image
* filename: F:/David/Documents/Projets/LedMatrix/BrightColours.xml
* name: BrightColours
*
* preset name: NeoMatrix RGBW
* data block size: 24 bit(s), uint24_t
* RLE compression enabled: no
* conversion type: Color, not_used not_used
* bits per pixel: 24
*
* preprocess:
*  main scan direction: top_to_bottom
*  line scan direction: forward
*  inverse: no
*******************************************************************************/

/*
 typedef struct {
     const uint24_t *data;
     uint16_t width;
     uint16_t height;
     uint8_t dataSize;
     } tImage;
*/
#include <stdint.h>



static const uint24_t image_data_BrightColours[64] = {
    0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 0xe91e63, 
    0xe91e63, 0xe91e63, 0xe91e63, 0x64dd17, 0x64dd17, 0x64dd17, 0xe91e63, 0xe91e63, 
    0xe91e63, 0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xe91e63, 
    0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0x76ff03, 0x76ff03, 0x76ff03, 0xffeb3b, 
    0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0x76ff03, 0x76ff03, 0x76ff03, 0xffeb3b, 
    0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0x76ff03, 0x76ff03, 0x76ff03, 0xffeb3b, 
    0xe91e63, 0xe91e63, 0x64dd17, 0x00bcd4, 0xffeb3b, 0xffeb3b, 0xffeb3b, 0xe91e63, 
    0xe91e63, 0xe91e63, 0xe91e63, 0x64dd17, 0x64dd17, 0x64dd17, 0xe91e63, 0xe91e63
};
const tImage BrightColours = { image_data_BrightColours, 8, 8,
    24 };

