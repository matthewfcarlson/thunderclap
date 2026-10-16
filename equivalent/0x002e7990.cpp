// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 57/60, incomplete)
// FUN_002e7990 @ 0x002e7990
#include "decls/data/engine/physics.h"

extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct Image {
    unsigned int width;              // 0x00
    unsigned int pitch;              // 0x04
    char pad08[3];
    unsigned char bitsPerPixel;      // 0x0b
};


// Stretches a row-major pixel run in place, replicating every pixel DAT_004d10d8[sel] times (from the end, so
// the source is never overwritten before it is read), then updates the image width and pitch.
void FUN_002e7990(Image *img, unsigned char *pixels, int sel, unsigned int flags)
{
    if (pixels == 0 || img == 0)
        return;

    int factor = DAT_004d10d8[sel];
    unsigned int w = img->width;
    unsigned int newW = w * factor;
    unsigned int bpp = img->bitsPerPixel;
    unsigned int i;

    if (bpp == 1 || bpp == 2 || bpp == 4) {
        unsigned int perByte = 8 / bpp;
        unsigned int maxShift = 8 - bpp;
        unsigned int valMask = (1 << bpp) - 1;
        unsigned char *src = pixels + (w - 1) / perByte;
        unsigned char *dst = pixels + (newW - 1) / perByte;
        int srcShift, dstShift, reset, limit, step;
        if (flags & 0x10000) {
            srcShift = ((w - 1) % perByte) * bpp;
            dstShift = ((newW - 1) % perByte) * bpp;
            reset = maxShift;
            limit = 0;
            step = -(int)bpp;
        } else {
            srcShift = maxShift - ((w - 1) % perByte) * bpp;
            dstShift = maxShift - ((newW - 1) % perByte) * bpp;
            reset = 0;
            limit = maxShift;
            step = bpp;
        }
        if (w != 0) {
            i = 0;
            do {
                unsigned char v = (unsigned char)((*src >> srcShift) & valMask);
                if (factor > 0) {
                    int n = factor;
                    do {
                        *dst = (unsigned char)((*dst & ~(valMask << dstShift)) | (v << dstShift));
                        if (dstShift == limit) {
                            dstShift = reset;
                            dst--;
                        } else {
                            dstShift += step;
                        }
                    } while (--n != 0);
                }
                if (srcShift == limit) {
                    srcShift = reset;
                    src--;
                } else {
                    srcShift += step;
                }
                i++;
            } while (i < img->width);
        }
    } else {
        unsigned int bytes = bpp >> 3;
        unsigned char *src = pixels + (w - 1) * bytes;
        unsigned char *dst = pixels + (newW - 1) * bytes;
        unsigned char tmp[8];
        if (w != 0) {
            i = 0;
            do {
                memcpy(tmp, src, bytes);
                if (factor > 0) {
                    int n = factor;
                    do {
                        memcpy(dst, tmp, bytes);
                        dst -= bytes;
                    } while (--n != 0);
                }
                src -= bytes;
                i++;
            } while (i < img->width);
        }
    }
    img->width = newW;
    img->pitch = (img->bitsPerPixel * newW + 7) >> 3;
}
