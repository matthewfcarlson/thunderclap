// (x64t17, D76) pure3d::TextureBuilder (RTTI .?AVTextureBuilder@pure3d@@, vftable 0x0042e154, 0x34 bytes on the
// 32-bit builds): the image handlers' sink that builds or refills a pure3d::Texture. The image factories
// (ImageHandler_3.cpp: 0x002aea70, 0x002aedd0, 0x002aeec0, 0x002aef60, 0x002af010) construct it on the stack, inline,
// and store the game's vftable; the PNG / BMP / ... readers call it through that vftable (slot 0 begins an image,
// slots 1 / 2 / 3 take a 32-bit / paletted / raw row, slot 10 finishes), and its methods (TextureBuilder.cpp,
// 0x002ae0e0 .. 0x002ae890) read it through this record. Natively the vftable is the game's by address (the link emits
// the game's vftables and binds their slots to the tree's definitions; a source-local polymorphic stand-in got clang's
// own, shorter vftable). gen/pure3d.h's pure3d::TextureBuilder declares the same fields (f_04 .. f_30).
// Only the TUs that use it include this header (D74). Declare no namespaces here other than the forward declaration.
#ifndef HULK_DECLS_TEXTURE_BUILDER_H
#define HULK_DECLS_TEXTURE_BUILDER_H

#include "compat/ptr.h"
#include "decls/pddi_texture.h"   // HulkPixelLock

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

namespace pure3d { class Texture; }

extern "C" char DAT_0042e154[];   // pure3d::TextureBuilder's vftable

struct HulkTextureBuilder {
    void* vftable;               // +0x00 the game's 0x0042e154
    ::pure3d::Texture* texture;  // +0x04 the texture built (0: slot 0 creates one) or refilled
    unsigned int* palette;       // +0x08 slot 0's palette (A8R8G8B8 words), for the paletted rows
    HulkPixelLock* lock;         // +0x0c the locked level
    int stride;                  // +0x10 bytes from a row to the next (negative: top-down rows into a bottom-up lock)
    unsigned char* row;          // +0x14 where the next row goes
    int rows;                    // +0x18 rows written
    int level;                   // +0x1c the mip level locked
    // the texture's creation parameters (pure3d::Texture's 0x002c1c70: bits, alpha depth, mips, pddi format, usage)
    int alphaDepth;              // +0x20
    int mips;                    // +0x24
    int format;                  // +0x28 (slot 9 sets it)
    int usage;                   // +0x2c
    int bits;                    // +0x30 the bit depth asked for (16 or 32; 0: the image's)

    // The inline constructor the factories expand (the game has no out-of-line one): the vftable by address, then
    // the fields in their order.
    void init(::pure3d::Texture* tex, int lvl, int alpha, int mipCount, int fmt, int use, int depth) {
        vftable = (void*)DAT_0042e154;
        texture = tex;
        palette = 0;
        lock = 0;
        stride = 0;
        row = 0;
        rows = 0;
        level = lvl;
        alphaDepth = alpha;
        mips = mipCount;
        format = fmt;
        usage = use;
        bits = depth;
    }
};
HULK_SIZE32(HulkTextureBuilder, 0x34);

#endif
