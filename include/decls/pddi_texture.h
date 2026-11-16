// (x64t17) The pddi texture's records: what a texture's lock returns (HulkPixelLock). Only the TUs that use them include this header (D74). Declare no namespaces here.
#ifndef HULK_DECLS_PDDI_TEXTURE_H
#define HULK_DECLS_PDDI_TEXTURE_H

#include "compat/ptr.h"

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

// What a pddi texture's lock (slot 13, d3dTexture 0x00326900; FUN_0031c570 fills it) returns: the level's size, the
// pixel layout and where to write. The SDL backend's bgfxTexture::LockInfo (src/platform/sdl/pddi/bgfx_pddi.h) is
// the same layout natively (bits at +0x50 on both). The channel order of the arrays is red, green, blue, alpha.
struct HulkPixelLock {
    int width;                   // +0x00 pixels a row
    int height;                  // +0x04
    int bitsPerPixel;            // +0x08 16, 32, 8 (paletted) or 4
    int depth;                   // +0x0c
    int type;                    // +0x10
    unsigned char direct;        // +0x14 the pixels are A8R8G8B8 as they come (a row is copied)
    char pad15[3];
    unsigned int left[4];        // +0x18 a channel's shift left (TextureBuilder's vfunc_1 / vfunc_2)
    unsigned int right[4];       // +0x28 its shift right
    unsigned int mask[4];        // +0x38
    int stride;                  // +0x48 bytes a row (the builder walks it, negated for a bottom-up image)
    int slicePitch;              // +0x4c
    unsigned char* bits;         // +0x50 the level's first row
    // 0x54 bytes on the 32-bit builds (d3dTexture keeps one at +0x70, its next word at +0xc4; 0x003265f0's view)
};

HULK_SIZE32(HulkPixelLock, 0x54);


#endif
