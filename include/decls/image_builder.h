// (x64t18, D90) pure3d::ImageBuilder (RTTI .?AVImageBuilder@pure3d@@, vftable 0x0042e184, 0x1c bytes on the 32-bit
// builds): the image handlers' sink that builds a pure3d::Image8 (paletted) or pure3d::Image32. The image factories
// (ImageHandler_3.cpp: 0x002aea70 modes 0 and 2, 0x002aecb0, 0x002aed60) construct it on the stack, inline, and store
// the game's vftable; the PNG / BMP / ... readers call it through that vftable (slot 0 begins an image, slot 1 takes
// a 32-bit row, slot 2 a paletted one, slot 10 finishes), and its methods (ImageBuilder.cpp, 0x002adf20 .. 0x002ae0d0)
// read it through this record. Natively the vftable is the game's by address (the link emits the game's vftables and
// binds their slots to the tree's definitions; a source-local polymorphic stand-in got clang's own vftable, whose
// slots past the first had no definition). gen/pure3d.h's pure3d::ImageBuilder declares the same words (f_04 .. f_18;
// natively the same layout). As decls/texture_builder.h's HulkTextureBuilder (D76).
// Only the TUs that use it include this header (D74). Declare no namespaces here other than the forward declaration.
#ifndef HULK_DECLS_IMAGE_BUILDER_H
#define HULK_DECLS_IMAGE_BUILDER_H

#include "compat/ptr.h"

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

namespace pure3d { class Image; }

extern "C" char DAT_0042e184[];   // pure3d::ImageBuilder's vftable

struct HulkImageBuilder {
    void* vftable;               // +0x00 the game's 0x0042e184
    ::pure3d::Image* image;      // +0x04 the image built (slot 0 makes an Image8 or an Image32)
    unsigned int* palette;       // +0x08 slot 0's palette (A8R8G8B8 words), for the paletted rows into an Image32
    unsigned char* row;          // +0x0c where the next row goes
    int rows;                    // +0x10 rows written
    int stride;                  // +0x14 bytes from a row to the next (negative: a bottom-up image)
    int depth;                   // +0x18 the bit depth asked for (0: the image's; <= 8 keeps a paletted image paletted)

    // The inline constructor the factories expand (the game has no out-of-line one): the vftable by address, then
    // the words in their order.
    void init(int bits) {
        vftable = (void*)DAT_0042e184;
        image = 0;
        palette = 0;
        row = 0;
        rows = 0;
        stride = 0;
        depth = bits;
    }
};
HULK_SIZE32(HulkImageBuilder, 0x1c);

#endif
