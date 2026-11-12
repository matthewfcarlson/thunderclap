// Physics records (x64t4). The physics world: the object DAT_00554c14 points at, which 0x002ef0b0 (and its constructor 0x002ef050)
// allocates and builds from four parts: the body pool (0x002eee10, at 0), a flag (0x6c), the collision detector
// (0x00301290, at 0x70), the impulse-based collision solver (0x002f7ee0, at 0xb0) and the contact buffer (0x00304300,
// at 0x1b0); 0x1c4 bytes in all. Each part is built and read through its own TU's view, so the parts' 64-bit sizes
// are those views' and nothing gives one record for the whole. On 64-bit every part's base and the allocation are
// the 32-bit offset doubled, room for any part whose words all turn into pointers (pool 0x6c -> 0xd8, detector
// 0x40 -> 0x80, solver 0x100 -> 0x200, buffer 0x14 -> 0x28); the 32-bit offsets are unchanged. A field inside a part
// keeps its offset from the part's base: HULK_PW_AT(part, k) for the world's 32-bit offset k inside PART.
#ifndef HULK_DECLS_PHYSICS_WORLD_H
#define HULK_DECLS_PHYSICS_WORLD_H
#include "compat/ptr.h"

#define HULK_PW(k) ((k) * (int)(sizeof(void*) / 4))
#define HULK_PW_FLAG HULK_PW(0x6c)       // unsigned char
#define HULK_PW_DETECTOR HULK_PW(0x70)   // physics::CollisionDetector
#define HULK_PW_SOLVER HULK_PW(0xb0)     // physics::ImpulseBasedCollisionSolver
#define HULK_PW_BUFFER HULK_PW(0x1b0)    // the contact buffer (owners::Buffer_304300 and its words)
#define HULK_PW_SIZE HULK_PW(0x1c4)
#define HULK_PW_AT(part, k) (HULK_PW(part) + (k) - (part))

// physics::CollisionVolume's words as its constructor 0x003060a0 writes them (0x38 bytes on the 32-bit builds): the
// owner (the CollisionObject that 0x003065b0 attaches, a pointer) and the children range are pointer-sized; the last
// word is a float that CollisionWall's constructor 0x0030e700 overwrites with another constant. Shared by the
// constructor's, 0x003065b0's and CollisionWall's views (each had its own 32-bit pad or `int`).
// (x64t6) The word at 4 is pure3d::NonCopyable's (gen: `hulk_intptr f_04`), pointer-sized natively, so every view
// (gen's physics::CollisionVolume, the subclasses' and the helpers' own) puts the id (m8) at 0x10 and the owner at
// 0x18: natively the words sit at HULK_CV(k) for the 32-bit offset k (0x48 bytes in all). A polymorphic view (an
// implicit vftable) pads up to word k with `char pad[HULK_CV(k) - sizeof(void*)]`.
#define HULK_CV(k) ((int)(sizeof(void*) == 4 ? (k) : (k) >= 0x18 ? (k) + 0x10 : (k) >= 0x14 ? (k) + 0xc : \
                                                     (k) >= 0x8 ? (k) + 8 : (k) * 2))
#define HULK_COLLISION_VOLUME_WORDS \
    hulk_intptr m4; /* pure3d::NonCopyable's word */ \
    int m8, mc; /* the id (0x00306600 sets it on the children too), a word */ \
    void* owner; /* 0x10: the CollisionObject (0x003065b0) */ \
    void* children; /* 0x14: the children range (begin, end) */ \
    char c18, c19; /* c19: the bounds are current (0x00306910 sets it) */ \
    int m1c, m20, m24, m28, m2c, m30; \
    union { float f34; int i34; };
struct HulkCollisionVolume {
    void* vftable;
    HULK_COLLISION_VOLUME_WORDS
};
// physics::CollisionWall (0x0030e700): the base and eleven words (0x60 bytes on the 32-bit builds)
struct HulkCollisionWall : HulkCollisionVolume {
    float x, y, z, w;
    float x2, y2, z2;
    int a, b, c;
};
// (x64t6) The other subclasses CollisionVolume's clone 0x00306c60 allocates, by the words their constructors and
// methods write past the base (none of them a pointer): the AABB (0x00312900, 0x44 bytes on the 32-bit builds), the
// cylinder (0x00306b40: two 0x2c / 0x28-byte blocks that 0x00306e70 initializes, 0x8c), the OBB (0x00306ba0: a word
// and two 0x40-byte matrices that 0x0030eaa0 initializes, 0xbc) and the sphere (0x00306c00, 0x48). Natively each is
// 0x10 bytes longer than on the 32-bit builds (the base's), rounded to 8.
struct HulkCollisionAABB : HulkCollisionVolume {
    float e[3];
};
struct HulkCollisionCylinder : HulkCollisionVolume {
    char first[0x2c];
    char second[0x28];
};
struct HulkCollisionOBB : HulkCollisionVolume {
    int m38;
    char block3c[0x40];
    char block7c[0x40];
};
struct HulkCollisionSphere : HulkCollisionVolume {
    float m38[4];
};
typedef char hulk_size32_cv_[(sizeof(void*) != 4 || (sizeof(HulkCollisionVolume) == 0x38 && sizeof(HulkCollisionWall) == 0x60 &&
    sizeof(HulkCollisionAABB) == 0x44 && sizeof(HulkCollisionCylinder) == 0x8c && sizeof(HulkCollisionOBB) == 0xbc &&
    sizeof(HulkCollisionSphere) == 0x48)) ? 1 : -1];


// physics::CollisionObject (x64t5; 0x00304ed0 / 0x00304f50 construct it, 0x00305400 clones it, 0x00304ff0 destroys
// it): pure3d::Entity's words, a name (8 bytes), then the words below, 0x80 bytes on the 32-bit builds. Natively the
// owner, the shape, the link array, the state's group array and its byte array are pointers and Entity's words end at 0x18
// (Entity's own size), so every view declares: its vftable, Entity's words as HULK_ENTITY_WORDS (or a base class
// named FUN_0027b070), its name (8 bytes), then HULK_COLLISION_OBJECT_WORDS. The anonymous structs are the link array
// (0x00304930 grows it, 0x00304da0 copies it: count, capacity, elements of 20 bytes, two flags) and the state
// (0x00305210 copies it, 0x00304e80 frees it: a count, groups of 16 bytes, a byte array with its own count, capacity
// and flags), laid out natively as the helpers' own views of them.
#define HULK_ENTITY_WORDS \
    union { \
        char entity[0xc]; /* pure3d::Entity's three words after the vftable */ \
        void* entity_align_; /* natively padded to pointer alignment, as Entity's own size is */ \
    };
#define HULK_COLLISION_OBJECT_WORDS \
    void* f18; /* the owner (the SimState that 0x002efa90 attaches it to) */ \
    int f1c; /* flags */ \
    void* f20; /* the shape (a CollisionVolume) */ \
    int f24; \
    struct { int f28, f2c; void* f30; char b34, b35; }; /* the links */ \
    struct { int f38; void* f3c; struct { int f40, f44; unsigned char* f48; char b4c, b4d; }; }; /* the state */ \
    char b50, b51; \
    int f54, f58, f5c, f60, f64; \
    char b68, b69, b6a, b6b; \
    int f6c; \
    char b70, b71, b72; \
    int f74, f78, f7c;
struct HulkCollisionObject {
    void* vftable;
    HULK_ENTITY_WORDS
    char name[8];
    HULK_COLLISION_OBJECT_WORDS
};
// (x64t6) the owner's offset (0x18 on the 32-bit builds, 0x20 natively), for the views that read only the owner
// through a pad (the volumes' vfunc_13: `char pad[HULK_CO_OWNER]; Owner* owner;`)
#define HULK_CO_OWNER ((int)(hulk_uintptr)&((HulkCollisionObject*)0)->f18)

#endif
