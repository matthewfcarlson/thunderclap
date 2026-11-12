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
struct HulkCollisionVolume {
    void* vftable;
    int m4, m8, mc;
    void* owner;     // 0x10
    void* children;  // 0x14
    char c18, c19;
    int m1c, m20, m24, m28, m2c, m30;
    union { float f34; int i34; };
};
// physics::CollisionWall (0x0030e700): the base and eleven words (0x60 bytes on the 32-bit builds)
// (x64t5) CollisionVolume's subclasses that have no record yet (AABB, cylinder, OBB, sphere) are allocated as twice the
// XBE's size on 64-bit (interim, docs/tech-debt.md; the 32-bit size unchanged): HULK_X2_VOLUME(n)
#define HULK_X2_VOLUME(n) ((n) * (int)(sizeof(void*) / 4))

struct HulkCollisionWall : HulkCollisionVolume {
    float x, y, z, w;
    float x2, y2, z2;
    int a, b, c;
};


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

#endif
