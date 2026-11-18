// (x64t19, D94) pure3d::Sprite (RTTI .?AVSprite@pure3d@@, vftable 0x0042e8d8, 0xa8 bytes on the 32-bit builds): a 2D
// image drawn as a grid of textured quads. The sprite chunk (SpriteLoader.cpp 0x002bed90) and the image factory's mode 2
// (ImageHandler_3.cpp 0x002aea70) allocate it and construct it with 0x002beb20 (from one image: 0x002be720 cuts the
// image into tiles of at most the display's texture size, 0x002bd570 lays the tiles out, 0x002bd790 copies one into a
// texture with a border, 0x002bdaf0 places its quad) or 0x002be440 (from textures already cut). Every SpriteLoader.cpp
// view of the sprite is this record (natively Entity's words are 0x14 bytes and the pointers 8: the 32-bit pads
// each view had put the counts and pointers elsewhere). gen/pure3d.h's pure3d::Sprite declares the same words (f_10 ..
// f_a0; natively the same layout); its size there (0xa4) is the last field's end, the allocations are 0xa8.
// Only the TUs that use it include this header (D74). Declare no namespaces here other than the forward declarations.
#ifndef HULK_DECLS_SPRITE_H
#define HULK_DECLS_SPRITE_H

#include "compat/ptr.h"

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

namespace pure3d { class Texture; class Shader; }

extern "C" char DAT_0042e8d8[];   // pure3d::Sprite's vftable

// One corner of a tile's quad (0x18 bytes): the position, the colour (0x002bdd00 sets every corner's to the
// sprite's; the draw 0x002bdd40 copies it as a word) and the texture coordinates.
struct HulkSpriteVertex {
    float x, y, z;               // +0x00
    union {
        int color;               // +0x0c
        float colorWord;         // (the draw copies the word through a float)
    };
    float u, v;                  // +0x10
};

// A tile's quad: four corners (0x60 bytes); the sprite has `count` of them.
struct HulkSpriteQuad {
    HulkSpriteVertex v[4];
};
HULK_SIZE32(HulkSpriteQuad, 0x60);

struct HulkSprite {
    void* vftable;                   // +0x00 the game's 0x0042e8d8 (pure3d::DrawablePrimitive's 0x0042d978 while its
                                     //       constructor 0x002a5060 runs)
    int refs;                        // +0x04 content::LoadObject's reference count
    unsigned int name[2];            // +0x08 pure3d::Entity's name (a 64-bit hash; natively at +0x0c)
    hulk_intptr blended;             // +0x10 DrawablePrimitive's word: slot 8 sets it for a blending shader
                                     //       (x64t20, D105: pointer-sized natively, decls/drawable_container.h)
    int primitive[11];               // +0x14 DrawablePrimitive's other words
    int count;                       // +0x40 tiles
    HulkSpriteQuad* quads;           // +0x44 count quads
    ::pure3d::Texture** textures;    // +0x48 count textures, one a tile
    ::pure3d::Shader* shader;        // +0x4c
    int color;                       // +0x50 the quads' colour (0x002bdd00)
    int height;                      // +0x54 the image's height in pixels (0x002beb20: the image's f_14)
    int width;                       // +0x58 its width (f_10)
    int border;                      // +0x5c pixels copied around each tile (0: one tile, or tiles that fill it)
    int scale;                       // +0x60 pixels a unit (the constructors' a4 / a7)
    int scaleArg;                    // +0x64 (a5 / a8)
    int maxTile;                     // +0x68 the display's largest texture less the borders (0x002bd570)
    int minTile;                     // +0x6c the smallest tile (DAT_004d0898) less the borders
    float invScaleX;                 // +0x70 1 / scale
    float invScaleY;                 // +0x74
    int minX, minY, minZ;            // +0x78 the bounding box (slot 11 hands it out); zeroed as words
    float maxX, maxY;                // +0x84 the size in units
    int maxZ;                        // +0x8c
    float centerX, centerY;          // +0x90 the bounding sphere (slot 12 hands it out)
    int centerZ;                     // +0x98
    float radius;                    // +0x9c
    unsigned char noBorder;          // +0xa0 one tile, no border (DAT_004d0894 for 0x002beb20)
    char _pad_a1[3];
    int unused_a4;                   // +0xa4 (no function of the sprite reads or writes it)
};
HULK_SIZE32(HulkSprite, 0xa8);

#endif
