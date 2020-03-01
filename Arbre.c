
/*******************************************************************************
* image
* filename: F:/David/Documents/Projets/LedMatrix/Arbre.xml
* name: Arbre
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



static const uint24_t image_data_Arbre[64] = {
    0x0097a7, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x0097a7, 
    0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 
    0x0097a7, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x004d40, 0x0097a7, 
    0x0097a7, 0x0097a7, 0x004d40, 0x795548, 0x004d40, 0x004d40, 0x0097a7, 0x0097a7, 
    0x81c784, 0x81c784, 0x81c784, 0x795548, 0x81c784, 0x81c784, 0x81c784, 0x81c784, 
    0x81c784, 0x81c784, 0x81c784, 0x795548, 0x81c784, 0x81c784, 0x81c784, 0x81c784, 
    0x81c784, 0x81c784, 0x81c784, 0x795548, 0x81c784, 0x81c784, 0x81c784, 0x81c784, 
    0x81c784, 0x81c784, 0x81c784, 0x795548, 0x81c784, 0x81c784, 0x81c784, 0x81c784
};
const tImage Arbre = { image_data_Arbre, 8, 8,
    24 };

