// The physics world (x64t4): the object DAT_00554c14 points at, which 0x002ef0b0 (and its constructor 0x002ef050)
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

#endif
