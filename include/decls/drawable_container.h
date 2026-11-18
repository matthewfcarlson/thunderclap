// (x64t19) pure3d::DrawableHierarchy (vftable 0x0042d82c, its constructor 0x002a3480) and pure3d::DrawableContainer
// (vftable 0x0042d90c, 0x50 bytes on the 32-bit builds; its constructor 0x002a4e10, the copy 0x002a4e40, the destructor
// 0x002a4ff0): a drawable with a bounding box and sphere, and the container's groups (a drawable and its children, each
// group 0x10 bytes on the 32-bit builds, pointers natively). pure3d::SpriteObject (vftable 0x0042e914, 0x58 bytes) is
// the container of one group whose drawable is a pure3d::Sprite. DrawableContainer.cpp's and SpriteLoader.cpp's views
// of them are these records (natively Entity's words are 0x14 bytes, the group's drawable and vector pointers 8 each:
// the 32-bit pads and the `>> 4` / `* 16` group arithmetic put the groups elsewhere). gen/pure3d.h's
// DrawableHierarchy / DrawableContainer declare the same words (f_10 .. f_4c; natively the same layout).
// Only the TUs that use it include this header (D74). Declare no namespaces here other than the forward declarations.
#ifndef HULK_DECLS_DRAWABLE_CONTAINER_H
#define HULK_DECLS_DRAWABLE_CONTAINER_H

#include "compat/ptr.h"

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

// A group: its drawable (reference counted: slot 0 AddRef, slot 1 Release) and its children, a vector of drawables.
struct HulkDrawableGroup {
    void* drawable;              // +0x00
    void** begin;                // +0x04 the children
    void** end;                  // +0x08
    void** capacity;             // +0x0c (0x002a4cb0 zeroes the other three; nothing here reads it)
};
HULK_SIZE32(HulkDrawableGroup, 0x10);

// pure3d::DrawableHierarchy's words (0x002a3480 zeroes +0x10 .. +0x38)
struct HulkDrawableHierarchy {
    void* vftable;               // +0x00
    int refs;                    // +0x04 content::LoadObject's reference count
    unsigned int name[2];        // +0x08 pure3d::Entity's name (natively at +0x0c)
    void* f10;                   // +0x10 a reference-counted object (vfunc_13 0x002a35a0 sets it; gen's f_10)
    float box[6];                // +0x14 the bounding box: min, max (vfunc_12 0x002a4570 merges the groups' boxes)
    float sphere[4];             // +0x2c the bounding sphere: centre, radius
};
HULK_SIZE32(HulkDrawableHierarchy, 0x3c);

// pure3d::DrawableContainer
struct HulkDrawableContainer : HulkDrawableHierarchy {
    int f3c;                     // +0x3c (no function of the container reads or writes it)
    unsigned int half;           // +0x40 0.5f (0x3f000000; the copy copies it)
    void* owner;                 // +0x44 the container itself (0x002a4e10)
    HulkDrawableGroup* groups;   // +0x48 the groups (0x002a4cb0 allocates them)
    HulkDrawableGroup* groupsEnd; // +0x4c
};
HULK_SIZE32(HulkDrawableContainer, 0x50);

// pure3d::SpriteObject: the container and two words past it (every allocation is 0x58 bytes)
struct HulkSpriteObject : HulkDrawableContainer {
    int f50, f54;
};
HULK_SIZE32(HulkSpriteObject, 0x58);

#endif
