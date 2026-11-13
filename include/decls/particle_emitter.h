// pure3d::SpriteParticleEmitter's words (x64t9-spe): the record its constructor 0x002d63a0 (with the bases'
// 0x002d3de0 and its state's 0x002d4200) writes, and the offset macros every source viewing the emitter places its
// members with. The loader 0x002ac610 (and 0x002acd70) allocates it (0x1e0 bytes on the 32-bit builds), its copy
// 0x002d63f0 (vfunc_4 0x002d66b0 allocates the copy), the destructor 0x002d6590 and 0x002d4b50 (ParticleEmitter's).
// The pointer-typed words are the ones the code dereferences, releases or frees as pointers; natively they are 8 bytes,
// so the words after the first one move. HULK_SPE(k) is the native offset of the emitter's word at the 32-bit offset k,
// HULK_EST(k) the state's (the 0x114-byte member at 0xa8); on the 32-bit builds both are k.
#ifndef HULK_DECLS_PARTICLE_EMITTER_H
#define HULK_DECLS_PARTICLE_EMITTER_H
#include "compat/ptr.h"
#include "decls/loaders.h"

// The emitter's state (0x114 bytes at the emitter's 0xa8 on the 32-bit builds): constructor 0x002d4200, copy
// 0x002d4e80, destroyed by 0x002d5090 (and inline by 0x002d6590); 0x002d53d0 / 0x002d50c0 update it per particle
// frame. Natively 0x130 bytes.
struct HulkEmitterState {
    void* shader;           // 0x00 the shader (vfunc_8 0x002d5e00 sets it, AddRef / Release; 0x002d5090 releases)
    int f04;                // 0x04 (not written by the code seen)
    float local[16];        // 0x08 the frame's transform (0x002d53d0, 0x002d50c0)
    float orient[16];       // 0x48 the channels' orientation
    void* position;         // 0x88 the "TRA" channel (0x002ac610 FUN_00288960; 0x002d53d0 calls its slot 4)
    void* rotation;         // 0x8c the "ROT" channel (slot 6)
    int visible;            // 0x90 written as an int by the "VIS" channel (0x002d53d0), read as a byte (0x002d4600)
    void* visibility;       // 0x94 the "VIS" channel (0x002d53d0 calls FUN_0028ac90 on it when set)
    float* motion;          // 0x98 a 0x40-byte matrix (0x002ac610 / 0x002d4e80 allocate it, 0x002d5090 frees it)
    float scale;            // 0x9c (0x002d6100)
    float blend;            // 0xa0
    unsigned int count;     // 0xa4 the live particles in use (the emitter's 0x14c)
    float credit;           // 0xa8 particles owed (0x002d5f20)
    float rate;             // 0xac
    float fb0;              // 0xb0
    unsigned char fb4;      // 0xb4
    float fb8[21];          // 0xb8 .. 0x108 the per-particle ranges (0x002d5a70) and curve scales (0x002d53d0)
    unsigned int color;     // 0x10c
    unsigned char f110, f111;
};
#define HULK_EST(k) ((int)(sizeof(void*) == 4 ? (k) : (k) < 0x04 ? (k) : (k) < 0x88 ? (k) + 4 :               \
                           (k) < 0x8c ? (k) + 8 : (k) < 0x90 ? (k) + 0xc : (k) < 0x94 ? (k) + 0x10 :             \
                           (k) < 0x98 ? (k) + 0x14 : (k) < 0x9c ? (k) + 0x18 : (k) + 0x1c))
HULK_LOADER_SIZE32(HulkEmitterState, 0x114);
typedef char hulk_size64_est_[(sizeof(void*) != 8 || sizeof(HulkEmitterState) == HULK_EST(0x114)) ? 1 : -1];

// pure3d::SpriteParticleEmitter (0x1e0 bytes on the 32-bit builds, natively 0x240): content::LoadObject's vftable and
// count, pure3d::Entity's name, pure3d::DrawablePrimitive's words (a word, the bounds, a word), ParticleEmitter's
// (the transform, five ref-counted objects 0x002d4b50 releases, the blend-state count and the animation frame) and
// SpriteParticleEmitter's (the state, the over-life attributes and two resources, the list of live particles and the
// list of blend states).
struct HulkSpriteParticleEmitter {
    void* vftable;
    int refs;               // 0x04 content::LoadObject's reference count
    unsigned int name[2];   // 0x08 pure3d::Entity's name (0x0027b040)
    int f10;                // 0x10 (vfunc_8 0x002d5e00)
    float bounds[10];       // 0x14 box, centre and radius (vfunc_10 0x002d4650)
    int f3c;
    float transform[16];    // 0x40 (vfunc_22 0x002d3f80)
    void* f80;              // 0x80 (vfunc_23 0x002d4d40)
    FUN_002ac4a0* allocator;    // 0x84 the particle allocator (vfunc_25 0x002d5e70; 0x002d5cb0 returns particles to it)
    void* generator;        // 0x88 (vfunc_27 0x002d4db0; 0x002d5f20 calls its slots 5 and 6)
    void* updater;          // 0x8c (vfunc_29 0x002d4de0; 0x002d5fe0 calls its slots 4 and 5)
    void* renderer;         // 0x90 (vfunc_31 0x002d4e20; 0x002ac610 creates a SpriteParticleRenderer, 0x002d6760)
    unsigned int stateCount;    // 0x94 the blend states (0x002ac610 counts them)
    int frame;              // 0x98 (vfunc_19 0x002d4bd0)
    float frac;             // 0x9c
    float time;             // 0xa0 (vfunc_20 0x002d3ec0)
    unsigned char fa4, fa5, fa6;
    HulkEmitterState state; // 0xa8
    void* overLife;         // 0x1bc the OverLifeAttributes (0x002d5640; 0x002d1db0 reads its tables)
    void* f1c0;             // 0x1c0 ("SPEM" animation, 0x002ac610)
    void* f1c4;             // 0x1c4 ("SPAR" animation)
    HulkParticleList live;  // 0x1c8 the live particles (0x002ab880 sizes it; vfunc_14 0x002d5a70 adds to it)
    int f1d0;               // 0x1d0 (not written by the code seen)
    void** blendBegin;      // 0x1d4 the blend states (0x002ab8e0 sizes it; 0x002d4040 builds each)
    void** blendEnd;        // 0x1d8
    int f1dc;               // 0x1dc (not written by the code seen)
};
#define HULK_SPE(k) ((int)(sizeof(void*) == 4 ? (k) : (k) < 0x04 ? (k) : (k) < 0x80 ? (k) + 4 :               \
                           (k) < 0x84 ? (k) + 8 : (k) < 0x88 ? (k) + 0xc : (k) < 0x8c ? (k) + 0x10 :            \
                           (k) < 0x90 ? (k) + 0x14 : (k) < 0x94 ? (k) + 0x18 : (k) < 0xa8 ? (k) + 0x1c :         \
                           (k) < 0x1bc ? 0xc8 + HULK_EST((k) - 0xa8) : (k) + 0x3c + ((k) - 0x1bc)))
HULK_LOADER_SIZE32(HulkSpriteParticleEmitter, 0x1e0);
typedef char hulk_size64_spe_[(sizeof(void*) != 8 || sizeof(HulkSpriteParticleEmitter) == HULK_SPE(0x1e0)) ? 1 : -1];

#endif
