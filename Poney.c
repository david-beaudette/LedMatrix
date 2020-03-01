
/*******************************************************************************
* image
* filename: F:/David/Documents/Projets/LedMatrix/Poney.xml
* name: Poney
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



static const uint24_t image_data_Poney[64] = {
    0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
    0x000000, 0x03a9f4, 0x03a9f4, 0x03a9f4, 0x03a9f4, 0x000000, 0x000000, 0x000000, 
    0x000000, 0x03a9f4, 0xff4081, 0xff4081, 0x03a9f4, 0x000000, 0x000000, 0x000000, 
    0x000000, 0x000000, 0x76ff03, 0xff4081, 0x03a9f4, 0x03a9f4, 0x000000, 0x000000, 
    0x000000, 0x000000, 0xff4081, 0xff4081, 0xff4081, 0x03a9f4, 0x000000, 0x000000, 
    0x000000, 0x000000, 0xff4081, 0x000000, 0xff4081, 0x000000, 0x000000, 0x000000, 
    0x000000, 0x000000, 0xff4081, 0x000000, 0xff4081, 0x000000, 0x000000, 0x000000, 
    0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000
};
const tImage Poney = { image_data_Poney, 8, 8,
    24 };

