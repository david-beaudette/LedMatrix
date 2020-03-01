
/*******************************************************************************
* image
* filename: F:/David/Documents/Projets/LedMatrix/Squares.xml
* name: Squares
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



static const uint24_t image_data_Squares[64] = {
    0xe65100, 0xe65100, 0xc6ff00, 0xe65100, 0xe65100, 0x5d4037, 0xe65100, 0xe65100, 
    0xe65100, 0xe65100, 0xc6ff00, 0xe65100, 0xe65100, 0x5d4037, 0xe65100, 0xe65100, 
    0x4fc3f7, 0x4fc3f7, 0x1b5e20, 0x4fc3f7, 0x4fc3f7, 0x1b5e20, 0x4fc3f7, 0x4fc3f7, 
    0xe65100, 0xe65100, 0xc6ff00, 0xe65100, 0xe65100, 0x5d4037, 0xe65100, 0xe65100, 
    0xe65100, 0xe65100, 0xc6ff00, 0xe65100, 0xe65100, 0x5d4037, 0xe65100, 0xe65100, 
    0xff8a80, 0xff8a80, 0x1b5e20, 0xff8a80, 0xff8a80, 0x1b5e20, 0xff8a80, 0xff8a80, 
    0xe65100, 0xe65100, 0xc6ff00, 0xe65100, 0xe65100, 0x5d4037, 0xe65100, 0xe65100, 
    0xe65100, 0xe65100, 0xc6ff00, 0xe65100, 0xe65100, 0x5d4037, 0xe65100, 0xe65100
};
const tImage Squares = { image_data_Squares, 8, 8,
    24 };

