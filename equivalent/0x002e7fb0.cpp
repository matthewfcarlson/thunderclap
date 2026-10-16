// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 49/50, incomplete)
// FUN_002e7fb0 @ 0x002e7fb0
  // png_pass_start
  // png_pass_inc
  // png_pass_ystart
  // png_pass_yinc
#include "decls/data/engine/physics.h"
#include "decls/data/engine/pure3d.h"

struct png_struct_2e7fb0 {
    char pad0[0x64];
    unsigned int flags;                 // 0x64
    unsigned int transformations;       // 0x68
    char pad6c[4];
    unsigned int avail_in;              // 0x70
    char pad74[0xc0 - 0x74];
    unsigned int width;                 // 0xc0
    unsigned int height;                // 0xc4
    unsigned int num_rows;              // 0xc8
    char padcc[4];
    unsigned int rowbytes;              // 0xd0
    unsigned int irowbytes;             // 0xd4
    unsigned int iwidth;                // 0xd8
    char paddc[4];
    unsigned char *row_buf;             // 0xe0
    unsigned char *big_row_buf;         // 0xe4
    char pade8[0x112 - 0xe8];
    unsigned short num_trans;           // 0x112
    char pad114[0x11b - 0x114];
    unsigned char interlaced;           // 0x11b
    unsigned char pass;                 // 0x11c
    char pad11d;
    unsigned char color_type;           // 0x11e
    unsigned char bit_depth;            // 0x11f
    char pad120;
    unsigned char pixel_depth;          // 0x121
};

void __cdecl FUN_002dc3e0(png_struct_2e7fb0 *png_ptr);
unsigned char *__cdecl FUN_002e6c00(png_struct_2e7fb0 *png_ptr, unsigned int size);
void __cdecl FUN_002e6b60(png_struct_2e7fb0 *png_ptr, unsigned char *ptr, int value, unsigned int size);

// libpng png_read_start_row
void __cdecl FUN_002e7fb0(png_struct_2e7fb0 *png_ptr)
{
    int max_pixel_depth;
    unsigned int row_bytes;

    png_ptr->avail_in = 0;
    FUN_002dc3e0(png_ptr);

    if (png_ptr->interlaced) {
        if (!(png_ptr->transformations & 2))
            png_ptr->num_rows = (png_ptr->height - ((const unsigned int*)&DAT_004d10f4)[0] + ((const unsigned int*)&DAT_004d1110)[0] - 1) / ((const unsigned int*)&DAT_004d1110)[0];
        else
            png_ptr->num_rows = png_ptr->height;
        png_ptr->iwidth = (png_ptr->width - ((const unsigned int*)&DAT_004d10bc)[png_ptr->pass] + ((const unsigned int*)&DAT_004d10d8)[png_ptr->pass] - 1)
                          / ((const unsigned int*)&DAT_004d10d8)[png_ptr->pass];
        row_bytes = (png_ptr->pixel_depth * png_ptr->iwidth + 7) >> 3;
    } else {
        png_ptr->num_rows = png_ptr->height;
        png_ptr->iwidth = png_ptr->width;
        row_bytes = png_ptr->rowbytes;
    }
    png_ptr->irowbytes = row_bytes + 1;

    max_pixel_depth = png_ptr->pixel_depth;
    unsigned int transformations = png_ptr->transformations;

    if ((transformations & 4) && png_ptr->bit_depth < 8)
        max_pixel_depth = 8;

    unsigned int expand = transformations & 0x1000;
    if (expand) {
        if (png_ptr->color_type == 3) {
            max_pixel_depth = (png_ptr->num_trans != 0) ? 32 : 24;
        } else if (png_ptr->color_type == 0) {
            if (max_pixel_depth < 8)
                max_pixel_depth = 8;
            if (png_ptr->num_trans != 0)
                max_pixel_depth *= 2;
        } else if (png_ptr->color_type == 2) {
            if (png_ptr->num_trans != 0)
                max_pixel_depth = (max_pixel_depth * 4) / 3;
        }
    }

    unsigned int filler = transformations & 0x8000;
    if (filler) {
        if (png_ptr->color_type == 3)
            max_pixel_depth = 32;
        else if (png_ptr->color_type == 0)
            max_pixel_depth = (max_pixel_depth > 8) ? 32 : 16;
        else if (png_ptr->color_type == 2)
            max_pixel_depth = (max_pixel_depth > 32) ? 64 : 32;
    }

    if (transformations & 0x4000) {
        if ((png_ptr->num_trans != 0 && expand) || filler || png_ptr->color_type == 4)
            max_pixel_depth = (max_pixel_depth > 16) ? 64 : 32;
        else
            max_pixel_depth = (max_pixel_depth > 8) ? 48 : 24;
    }

    unsigned int w = (png_ptr->width + 7) & ~7u;
    unsigned int bytes = (w * max_pixel_depth + 7) >> 3;
    bytes = bytes + (((max_pixel_depth + 7) >> 3) + 1);

    png_ptr->big_row_buf = FUN_002e6c00(png_ptr, bytes);
    png_ptr->row_buf = FUN_002e6c00(png_ptr, png_ptr->rowbytes + 1);
    FUN_002e6b60(png_ptr, png_ptr->row_buf, 0, png_ptr->rowbytes + 1);
    png_ptr->flags |= 0x40;
}
