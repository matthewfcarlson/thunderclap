// Physics records (x64t4). The physics world (x64t9-pw): the object DAT_00554c14 points at, which 0x002ef0b0 allocates
// (sizeof(HulkPhysicsWorld): 0x1c4 bytes on the 32-bit builds) and its constructor 0x002ef050 builds from its parts:
// the body pool (0x002eee10, at 0), a flag (0x6c), the collision detector (0x00301290, at 0x70), the impulse-based
// collision solver (0x002f7ee0, at 0xb0), the contact buffer (0x00304300, at 0x1b0) and a last word (0x1c0). Each
// part is the words its constructor writes, pointers as pointers; a view that pads up to a part or to one of its words
// takes the offset from the record: HULK_WORLD_AT(member), e.g. `char pad[HULK_WORLD_AT(solver)]` or
// HULK_WORLD_AT(detector.tolerance); HULK_SOLVER_AT(member) inside the solver.
#ifndef HULK_DECLS_PHYSICS_WORLD_H
#define HULK_DECLS_PHYSICS_WORLD_H
#include "compat/ptr.h"

// The body pool's vectors (0x002eee10 allocates them, 0x002eefc0 frees them): begin, end, capacity and a fourth word
// that neither touches (16 bytes on the 32-bit builds).
struct HulkPoolVec {
    char* first;
    char* last;
    char* end;
    int tail;
};
// The body pool (0x002eee10; 0x6c bytes on the 32-bit builds): the vectors of ids (DAT_004d293c * 4 bytes), records
// (DAT_004d2944 * 0x44), indices (DAT_004d2940 * 4), edges (DAT_004d2948 * 20) and flags (DAT_004d293c * 4); a bit
// set (its count, then the words: allocated by 0x002eee10, freed by 0x002eefc0's `delete`); the slots and the links
// (allocated, then freed by `delete[]`) with their counts.
struct HulkBodyPool {
    HulkPoolVec ids;         // 0x00
    unsigned int* bits;      // 0x10
    int* slots;              // 0x14
    int slotCount[3];        // 0x18
    char* links;             // 0x24
    int linkCount;           // 0x28
    HulkPoolVec records;     // 0x2c
    HulkPoolVec indices;     // 0x3c
    HulkPoolVec edges;       // 0x4c
    HulkPoolVec flags;       // 0x5c
};
// The collision detector (physics::CollisionDetector, 0x00301290 on physics::SubCollisionDetector's 0x00313500; 0x40
// bytes on the 32-bit builds): the word at 8 is the contact vector (ContactManager's view in unk_3137f0.cpp: begin,
// end, capacity), the word at 0x10 the tolerance (the environment's float at 0x30, DAT_00554c10), 0x38 the flags (3).
struct HulkCollisionDetector {
    void* vftable;
    int m4;
    void* contacts;          // 0x08
    int mc;
    union { float tolerance; int toleranceBits; };   // 0x10
    char pad14[0x20];
    char b34, b35;
    int flags;               // 0x38
    int m3c;
};
// A contact (0x44 bytes on the 32-bit builds): 0x002f8d70 initializes one, the contact buffer's elements are these
// (0x00304300 allocates DAT_004d2f80 * 0x44 bytes on the 32-bit builds), 0x002f8020 reads them (Rec_2f8020: the
// object and the two holders are pointers).
struct HulkContact {
    int f0;
    void* object;            // 0x04
    void* first;             // 0x08
    void* second;            // 0x0c
    int f10, f14;
    float f18, f1c, f20;
    int f24;
    int flags;               // 0x28
    int f2c, f30, f34, f38, f3c, f40;
};
// The solver's state (0x88 bytes on the 32-bit builds, at 0xc of the solver): the current contact, then 0x002f8020's
// floats and its bodies and their records (pointers).
struct HulkSolverState {
    HulkContact current;
    char pad44[0x24];
    float f68, f6c, f70, k;  // the solver's 0x74 .. 0x80
    void* body1;             // the solver's 0x84
    void* body2;
    void* q1;
    void* q2;                // the solver's 0x90
};
// A symmetric 3x3 matrix (0x002fca90 / 0x002fcaa0: a vftable and six floats, 0x1c bytes on the 32-bit builds)
struct HulkSymMatrix {
    void* vftable;
    float m[6];
};
// physics::ImpulseBasedCollisionSolver (0x002f7ee0; 0x100 bytes on the 32-bit builds): the core and the contact list
// (0x002f8020; the destructor 0x002f7fc0 releases the core), the state, three matrices, the environment's two words
// (0x30 and 0x28), flags, the iteration count (3) and the world collision object's state (0x002efa90, a pointer).
struct HulkCollisionSolver {
    void* vftable;
    void* core;              // 0x04
    void* list;              // 0x08
    HulkSolverState state;   // 0x0c
    HulkSymMatrix s1, s2, s3;   // 0x94, 0xb0, 0xcc
    int me8, mec;
    char f0, f1, f2, f3;
    char cf4;
    int iterations;          // 0xf8
    void* zone;              // 0xfc
};
// The contact buffer (owners::Buffer_304300, 0x00304300; 0x10 bytes on the 32-bit builds): begin, end, capacity of
// the contacts and a word its constructor does not write (the pool's vectors' shape; 0x00300c90's object has the
// collision detector right after its buffer, at 0x10).
struct HulkContactBuffer {
    char* begin;
    char* end;
    char* capacity;
    int tail;
};
struct HulkPhysicsWorld {
    HulkBodyPool pool;                   // 0x000
    unsigned char flag;                  // 0x06c
    HulkCollisionDetector detector;      // 0x070
    HulkCollisionSolver solver;          // 0x0b0
    HulkContactBuffer buffer;            // 0x1b0
    int m1c0;                            // 0x1c0 (nothing in the constructor writes it)
};
#define HULK_WORLD_AT(m) ((int)(hulk_uintptr)&((HulkPhysicsWorld*)0)->m)   // a physics world word's offset
#define HULK_SOLVER_AT(m) ((int)(hulk_uintptr)&((HulkCollisionSolver*)0)->m)   // a solver word's offset
typedef char hulk_size32_pw_[(sizeof(void*) != 4 || (sizeof(HulkBodyPool) == 0x6c && sizeof(HulkCollisionDetector) == 0x40 &&
    sizeof(HulkContact) == 0x44 && sizeof(HulkSolverState) == 0x88 && sizeof(HulkSymMatrix) == 0x1c &&
    sizeof(HulkCollisionSolver) == 0x100 && sizeof(HulkContactBuffer) == 0x10 && sizeof(HulkPhysicsWorld) == 0x1c4 &&
    HULK_WORLD_AT(flag) == 0x6c && HULK_WORLD_AT(detector) == 0x70 && HULK_WORLD_AT(solver) == 0xb0 &&
    HULK_WORLD_AT(buffer) == 0x1b0 && HULK_WORLD_AT(solver.zone) == 0x1ac)) ? 1 : -1];

// physics::CollisionVolume's words as its constructor 0x003060a0 writes them (0x38 bytes on the 32-bit builds): the
// owner (the CollisionObject that 0x003065b0 attaches, a pointer) and the children range are pointer-sized; the last
// word is a float that CollisionWall's constructor 0x0030e700 overwrites with another constant. Shared by the
// constructor's, 0x003065b0's and CollisionWall's views (each had its own 32-bit pad or `int`).
// (x64t6, x64t7) The word at 4 is pure3d::NonCopyable's reference count (an int), and natively the count is followed
// directly by the id (gen's NonCopyable packs to 12 bytes: compat/ptr.h HULK_REFCOUNT_PACK); the owner and the children
// are pointers, so natively the words sit at HULK_CV(k) for the 32-bit offset k (0x48 bytes in all), in gen's
// physics::CollisionVolume too. A polymorphic view (an implicit vftable) pads up to word k with
// `char pad[HULK_CV(k) - sizeof(void*)]`.
#define HULK_CV(k) ((int)(sizeof(void*) == 4 ? (k) : (k) >= 0x18 ? (k) + 0x10 : (k) >= 0x14 ? (k) + 0xc : \
                                                     (k) >= 0x10 ? (k) + 8 : (k) >= 4 ? (k) + 4 : (k)))
#define HULK_COLLISION_VOLUME_WORDS \
    int m4; /* pure3d::NonCopyable's reference count */ \
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
// owner, the shape, the link array, the state's group array and its byte array are pointers; Entity's words (the
// reference count, then the 8-byte name) follow the vftable directly and end at 0x14 (x64t8: content::LoadObject packs
// natively as pure3d::NonCopyable does, so gen's pure3d::Entity is 0x14 bytes), so every view declares: its vftable, Entity's words as HULK_ENTITY_WORDS (or a base class
// named FUN_0027b070), its name (8 bytes), then HULK_COLLISION_OBJECT_WORDS. The anonymous structs are the link array
// (0x00304930 grows it, 0x00304da0 copies it: count, capacity, elements of 20 bytes, two flags) and the state
// (0x00305210 copies it, 0x00304e80 frees it: a count, groups of 16 bytes, a byte array with its own count, capacity
// and flags), laid out natively as the helpers' own views of them.
#define HULK_ENTITY_WORDS \
    int entity[3]; /* pure3d::Entity's three words after the vftable (LoadObject's count, the name) */
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
#define HULK_CO_AT(m) ((int)(hulk_uintptr)&((HulkCollisionObject*)0)->m)   // a CollisionObject word's offset

// (x64t6, x64t7) physics::SimState as its constructor 0x002ef7f0 writes it (0x88 bytes on the 32-bit builds): the
// word at 4 is pure3d::NonCopyable's reference count (an int, followed natively by the state's words: gen's
// NonCopyable packs to 12 bytes), the simulated object (0x70) and the CollisionObject (0x74) are pointers; natively
// the words sit at HULK_SS(k) for the 32-bit offset k (0x98 bytes in all), which is gen's physics::SimState too.
#define HULK_SS(k) ((int)(sizeof(void*) == 4 ? (k) : (k) < 4 ? (k) : (k) < 0x70 ? (k) + 4 : (k) < 0x74 ? (k) + 8 : \
                                                     (k) < 0x78 ? (k) + 0xc : (k) + 0x10))
struct HulkSimState {
    void* vftable;
    int m4;            // pure3d::NonCopyable's reference count
    int m8, mc;
    float current[16]; // 0x10
    float delta[3];    // 0x50
    int m5c, m60, m64;
    union { float f68; int mode; };
    int m6c;
    void* m70;         // 0x70 the simulated object
    void* m74;         // 0x74 the CollisionObject
    unsigned char changed;
    int m7c;
    float radius;      // 0x80
    unsigned char locked;
};
typedef char hulk_size32_ss_[(sizeof(void*) != 4 || sizeof(HulkSimState) == 0x88) ? 1 : -1];
typedef char hulk_size64_ss_[(sizeof(void*) != 8 || sizeof(HulkSimState) == HULK_SS(0x88)) ? 1 : -1];

#endif
