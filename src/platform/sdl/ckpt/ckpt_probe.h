// The semantic checkpoint probe (ckpt1, D155/D158; docs/checkpoints.md "The semantic state hash").
//
// One source, compiled three ways: with MSVC 7.1 into the hook-only XBE (hybrid/hooks.cpp includes ckpt_probe.cpp),
// with clang i686 into the Wine build (src/platform/sdl/xdk/replay_hooks.cpp includes it) and with the native front
// ends into the 64-bit builds. Each build hands the probe the addresses of the game's globals it reads
// (HulkProbeInputs); the probe walks the objects from there and writes, per subsystem tag, an exact hash (every value's
// bits) and a quantised one (floats rounded to 10 fraction bits, for telling float drift from logic). Pointers are never
// hashed: only null / non-null, or what they point to.
//
// Plain C-compatible C++ that MSVC 7.1 compiles: no <stdint.h>, no static_assert.
#ifndef HULK_PLATFORM_SDL_CKPT_PROBE_H
#define HULK_PLATFORM_SDL_CKPT_PROBE_H

#define HULK_PROBE_VERSION 3

// tags (the order is the record order; ids are stable: a new tag takes a new id, never a reused one)
enum {
    HULK_PT_LEGACY = 0,     // the narrow hash of hulk_replay.h (written by the caller, not the probe)
    HULK_PT_FLOW = 1,       // boot step, world present, mission state
    HULK_PT_CLOCK = 2,      // the GameClock block (as the legacy hash reads it)
    HULK_PT_RNG = 3,        // the gameplay MWC (0x4e5ad0)
    HULK_PT_HULK = 4,       // the main actor
    HULK_PT_CAMERA = 5,     // the logic view's position
    HULK_PT_ACTORS = 6,     // every actor of the actor manager (full tier)
    HULK_PT_MISSION = 7,    // the scenario manager's mission state, checkpoint and clocks (full tier)
    HULK_PT_SOUND = 8,      // the sound code's own generators (sound-rng): an observable, not game state (v2)
    HULK_PT_PARTICLE = 9,   // pure3d's particle generators (v3: the original itself is not deterministic here after
                            // about frame 12,920 of play3, so they are kept apart from the gameplay RNG)
    HULK_PT_COUNT = 10
};
#define HULK_PROBE_CHEAP_MASK ((1u << HULK_PT_FLOW) | (1u << HULK_PT_CLOCK) | (1u << HULK_PT_RNG) | \
                               (1u << HULK_PT_HULK) | (1u << HULK_PT_CAMERA) | (1u << HULK_PT_SOUND) | \
                               (1u << HULK_PT_PARTICLE))
#define HULK_PROBE_FULL_MASK ((1u << HULK_PT_ACTORS) | (1u << HULK_PT_MISSION))
#define HULK_PROBE_FULL_EVERY 30

typedef struct HulkProbeInputs {
    const void* rng;              // the gameplay MWC state, 8 bytes (0x4e5ad0)
    const void* boot_step;        // g_BootSequenceStep (0x49fb40)
    const void* const* view_ptr;  // the logic view singleton pointer (0x4e231c); its position at +0x4c
    const void* clock;            // the GameClock (GameClock::Update's this)
    int clock_at_entry;           // 1: read at Update's entry (step and scaled step hashed as zeros, as the legacy hash)
    const unsigned char* prng;    // the 40 particle RNG bytes (hulk_replay.h HULK_PRNG_BYTES), or 0
    const void* snd_rng;          // the sound code's own MWC (16 bytes) and rand state (4), or 0 (sound-rng off)
    const void* snd_rand;
    const void* const* world_ptr; // the world pointer (0x4dd700): +0x20 actor manager, +0x2c scenario manager
    // (D161 B) the game's own read-only getters, so these reads follow the game code's layout on every build; 0: the
    // probe reads the 32-bit offsets itself. Each was checked side-effect free from its listing (reads only).
    const void* (*actor_of)(const void* table, unsigned handle);   // 0x00059c10 (through 0x00059ba0): handle -> actor
    int (*position_of)(const void* node, unsigned out[3]);        // 0x00059a50: the scene node's position (writes out)
} HulkProbeInputs;

typedef struct HulkProbeRecord {
    unsigned frame;
    unsigned mask;                // tags present in this record
    unsigned unavailable;         // tags this build cannot read yet (native: fields gen does not spell)
    unsigned exact[HULK_PT_COUNT];
    unsigned quant[HULK_PT_COUNT];
} HulkProbeRecord;

// A field dump (HULK_CKREF_DUMP): called once per hashed value with its tag, name and bits; 0 for none.
typedef void (*HulkProbeDump)(void* ctx, int tag, const char* name, unsigned index, unsigned bits, int is_float);

#ifdef __cplusplus
extern "C" {
#endif
// Hash the tags of MASK (HULK_PROBE_CHEAP_MASK, | HULK_PROBE_FULL_MASK every HULK_PROBE_FULL_EVERY frames).
void hulk_probe_frame(unsigned frame, const HulkProbeInputs* in, unsigned mask, HulkProbeRecord* out,
                      HulkProbeDump dump, void* ctx);
#ifdef __cplusplus
}
#endif

#endif
