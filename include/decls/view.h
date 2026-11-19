// (recs1) pure3d::View (RTTI .?AVView@pure3d@@, vftable 0x0042d0bc, 0x140 bytes on the 32-bit builds) as a record.
// Its constructor 0x00294880 writes every word below; 0x00293ef0 (the view's begin-render) reads them all: the
// viewport (four floats, 0..1, the constructor's 0,0,1,1; 0x00293e40 sets it, 0x00293e60 reads it), the camera
// (0x00294980 sets it, taking a reference), the ambient colour (0x00293e90), the clear state (0x00293ef0 passes the
// colour, depth, stencil and mask on: the mask 3 by default, 2 for the message overlay), the fog values (colour,
// start, end, used when `fogEnabled`), the lights (32 reference-counted slots: 0x00293ea0 adds one, 0x00294080 /
// 0x002949e0 walk and clear them) and two matrices (0x00293ef0 multiplies the camera's by each).
// Natively the vftable and the pointers are 8 bytes, so every word from `left` on moves: the views in the TUs that
// read a View derive from this record or name its words (find1 F4 / F7 / F9). Allocations are sizeof(HulkView).
// gen/pure3d.h's pure3d::View declares the same words. Only the TUs that use the View include this header (D74).
// Declare no namespaces here.
#ifndef HULK_DECLS_VIEW_H
#define HULK_DECLS_VIEW_H

#include "compat/ptr.h"

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

// The words after the vftable, as one list: HulkView declares them after its vftable word, and a TU's polymorphic view
// of a View (one that calls the View's slots, `virtual void AddRef(); HULK_VIEW_WORDS`) after its own vptr, so both
// lay the words out alike on every build.
#define HULK_VIEW_WORDS \
    int refs;                   /* +0x04 pure3d::NonCopyable's reference count */ \
    float left;                 /* +0x08 the viewport, 0..1 (0x00293e40 / 0x00293e60 pass the words as ints) */ \
    float top;                  /* +0x0c */ \
    float right;                /* +0x10 */ \
    float bottom;               /* +0x14 */ \
    void* camera;               /* +0x18 a pure3d::Camera, referenced (0x00294980) */ \
    unsigned int ambient;       /* +0x1c the ambient colour (0xff101010) */ \
    unsigned int clearColour;   /* +0x20 (0xff000000) */ \
    float clearDepth;           /* +0x24 (1.0) */ \
    int clearStencil;           /* +0x28 */ \
    int clearMask;              /* +0x2c (3) */ \
    unsigned int fogColour;     /* +0x30 (0xffffffff) */ \
    unsigned int fogStart;      /* +0x34 */ \
    unsigned int fogEnd;        /* +0x38 */ \
    void* lights[32];           /* +0x3c reference-counted lights; a light's slot 5 binds it to a light index */ \
    unsigned char fogEnabled;   /* +0xbc */ \
    float matrix0[16];          /* +0xc0 */ \
    float matrix1[16];          /* +0x100 */

struct HulkView {
    void* vftable;              // +0x00 pure3d::View's (0x0042d0bc)
    HULK_VIEW_WORDS
};
HULK_SIZE32(HulkView, 0x140);

#endif
