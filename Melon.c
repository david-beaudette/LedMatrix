
/*******************************************************************************
* image
* filename: F:/David/Documents/Projets/LedMatrix/Melon.xml
* name: Melon
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



static const uint24_t image_data_Melon[64] = {
    0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
    0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
    0x37662e, 0xff7062, 0xd4222b, 0x7b2824, 0xdc2738, 0xe53d40, 0xd87563, 0x308247, 
    0x378633, 0xffef75, 0xe23541, 0xe1404e, 0x844548, 0xff8c7c, 0xe9eb61, 0x2f874b, 
    0x4a8a47, 0xf8dc6a, 0xf9807c, 0xfd847d, 0xff837d, 0xf28d6b, 0xcace58, 0x528d6b, 
    0x000000, 0x3d8334, 0xe7ef55, 0xe0e460, 0xdee960, 0xc6d25d, 0x3f915b, 0x000000, 
    0x000000, 0x000000, 0x307844, 0x3d8451, 0x378549, 0x548d5f, 0x000000, 0x000000, 
    0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000
};
const tImage Melon = { image_data_Melon, 8, 8,
    24 };

