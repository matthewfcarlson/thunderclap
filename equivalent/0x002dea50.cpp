// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 20/20)
// pure3d::ImageConverter::vfunc_8 @ 0x002dea50
#include "gen/pure3d.h"

struct PixelFormat_2dea50 {
    char pad0[8];
    int bits;                   // 0x08
    char pad0c[0x18 - 0x0c];
    int rShift;                 // 0x18
    int gShift;                 // 0x1c
    int bShift;                 // 0x20
    char pad24[4];
    int rDst;                   // 0x28
    int gDst;                   // 0x2c
    int bDst;                   // 0x30
    char pad34[4];
    unsigned int rMask;         // 0x38
    unsigned int gMask;         // 0x3c
    unsigned int bMask;         // 0x40
    char pad44[4];
    int pitch;                  // 0x48
    char pad4c[4];
    unsigned char *pixels;      // 0x50
};

struct Image_2dea50 {
    char pad0[0x10];
    int width;                  // 0x10
    int height;                 // 0x14
    char pad18[0x24 - 0x18];
    unsigned int *dst;          // 0x24
};

void pure3d::ImageConverter::vfunc_8(int __p0, int __p1) { PixelFormat_2dea50 * fmt = (PixelFormat_2dea50 *)__p0; Image_2dea50 * img = (Image_2dea50 *)__p1;

    int sA = fmt->rShift + (4 - fmt->rDst) * 2;
    int sB = fmt->gShift + (4 - fmt->gDst) * 2;
    int sC = fmt->bShift + (4 - fmt->bDst) * 2;
    int width = img->width;
    int height = img->height;

    if (fmt->bits == 16) {
        const unsigned char *src = fmt->pixels;
        unsigned int *dst = img->dst;
        int rowBytes = (fmt->pitch / 2) * 2;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                unsigned int v = ((const unsigned short *)src)[x];
                unsigned int r = fmt->rMask & v;
                unsigned int b = fmt->bMask & v;
                unsigned int g = fmt->gMask & v;
                unsigned int out = ((b >> fmt->bShift) << fmt->bDst)
                                 | ((g >> fmt->gShift) << fmt->gDst)
                                 | ((r >> fmt->rShift) << fmt->rDst)
                                 | (b >> sC) | (g >> sB) | (r >> sA) | 0xff000000;
                *dst++ = out;
            }
            src += rowBytes;
        }
    } else if (fmt->bits == 32) {
        const unsigned char *src = fmt->pixels;
        unsigned int *dst = img->dst;
        int rowBytes = (fmt->pitch / 4) * 4;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                unsigned int v = ((const unsigned int *)src)[x];
                unsigned int r = fmt->rMask & v;
                unsigned int b = fmt->bMask & v;
                unsigned int g = fmt->gMask & v;
                unsigned int out = ((b >> fmt->bShift) << fmt->bDst)
                                 | ((g >> fmt->gShift) << fmt->gDst)
                                 | ((r >> fmt->rShift) << fmt->rDst)
                                 | (b >> sC) | (g >> sB) | (r >> sA) | 0xff000000;
                *dst++ = out;
            }
            src += rowBytes;
        }
    }
}
