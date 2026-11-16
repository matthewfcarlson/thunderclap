// (x64t17) The pddi texture's records: what a texture's lock returns (HulkPixelLock) and the Xbox build's texture,
// pure3d::d3dTexture (HulkD3dTexture). Only the TUs that use them include this header (D74). Declare no namespaces here.
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

// pure3d::d3dTexture (RTTI .?AVd3dTexture@pure3d@@, vftable 0x004333ac, 0xf8 bytes on the 32-bit builds: d3dDevice's
// slot 9 0x0031b8a0 and the shaders' render targets allocate 248), on pure3d::pddiObject's three words. Its functions
// are d3dTexture.cpp's (0x00326110 .. 0x00326c40); every view there is this record. The D3D handles are pointers.
struct HulkD3dTexture {
    void* vftable;               // +0x00 0x004333ac
    int refs;                    // +0x04 (pddiObject; 0x0031bac0: 0)
    int error;                   // +0x08 (pddiObject; 0x0031bac0: 1) the last error (0xc8 .. 0xca: Create's checks)
    void* context;               // +0x0c the d3dContext (Create asks it for the largest texture size, slot 84)
    void* resource;              // +0x10 a D3D resource it wraps (0x00326110's; the created ones keep 0)
    void* texture;               // +0x14 the D3D texture (D3DDevice_CreateTexture2)
    void* volume;                // +0x18 the D3D volume texture (0x003265f0)
    struct {                     // +0x1c D3DLOCKED_RECT
        int pitch;
        unsigned char* bits;
    } lockedRect;
    struct {                     // +0x24 D3DLOCKED_BOX
        int rowPitch;
        int slicePitch;
        unsigned char* bits;
    } lockedBox;
    unsigned int surfaceDesc[7]; // +0x30 D3DSURFACE_DESC: format, type, usage, size, multisample, width, height
    unsigned int volumeDesc[7];  // +0x4c D3DVOLUME_DESC: format, type, usage, size, width, height, depth
    void* palette;               // +0x68 the D3D palette (the paletted formats)
    int d3dFormat;               // +0x6c (0x003265f0)
    HulkPixelLock lock;          // +0x70 what slot 13 returns (FUN_0031c570 / FUN_0031c600 fill it)
    unsigned int fc4;            // +0xc4 (TextureBuilder's slot 5 reads it, as the word after the lock)
    int format;                  // +0xc8 the pddi format
    int usage;                   // +0xcc (the constructors: 1)
    int type;                    // +0xd0 slot 4 (the lock's type)
    int width;                   // +0xd4 slot 5
    int height;                  // +0xd8 slot 6
    int bitsPerPixel;            // +0xdc slot 7
    int alphaBits;               // +0xe0 slot 8 (the alpha mask's bit count)
    int mips;                    // +0xe4 slot 9
    int bytes;                   // +0xe8 the memory the levels take
    unsigned char compressed;    // +0xec DXT
    unsigned char palettized;    // +0xed
    unsigned char linear;        // +0xee
    unsigned char fef;           // +0xef (the constructors: 1)
    unsigned int priority;       // +0xf0 slots 18 / 19 (the constructors: 0xf)
    unsigned char* buffer;       // +0xf4 slot 13's staging copy (the formats the Xbox swizzles: slot 14 swizzles it in)
};
HULK_SIZE32(HulkD3dTexture, 0xf8);

#endif
