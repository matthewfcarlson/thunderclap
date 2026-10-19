// Native replay: feeds a hybrid-build recording (tools/hybrid_test.py JSON v1/v2, or the packed .hrp that
// tools/replay_pack.py writes) to the native controller backend, and checks game-state checkpoints against the
// recording's. Design and what the native image must provide: docs/native-replay.md.
//
// Poll semantics are the hybrid build's (hybrid/hooks.cpp hybrid_xinput_get_state): every read of a virtual pad
// by ControllerXBox::vfunc_17 is one poll; the counter counts all pads, starts at 1 for the first read, and the
// pad state is the last recorded entry whose key (poll number, or frame for frame-keyed files) is <= it.
#ifndef HULK_PLATFORM_SDL_REPLAY_H
#define HULK_PLATFORM_SDL_REPLAY_H

#include "../input/hulk_input.h"

#ifdef __cplusplus
extern "C" {
#endif

// Loads a recording: a .hrp (magic "HRP1") or JSON (a recording object, or the bare entry list of
// tests/replays/*.json). 1 on success; on failure 0 and hulk_replay_error() says why. Replaces any earlier one.
int hulk_replay_open(const char* path);
int hulk_replay_open_memory(const void* data, unsigned long size);
void hulk_replay_close(void);
const char* hulk_replay_error(void);

// The input source for it (select with hulk_input_set_source, or HULK_INPUT_SOURCE=replay:<file>).
const HulkInputSource* hulk_replay_source(void);

typedef struct HulkReplayInfo {
    int frame_keyed;                // 0: entries keyed by poll number, 1: by frame
    int autostart;                  // legacy files: START is pulsed while the game loop is stalled
    unsigned vpad_count;            // virtual pads in ports 0..n-1 (1 when the file says 0)
    unsigned seed;                  // the new-game reseed the hybrid build pins (0x86630), 0 if not in the file
    unsigned tweaks;                // bit 0 skip-intro, bit 1 no-fmv
    unsigned flags;                 // the recording's hybrid flags (HF_*, tools/patch_xbe.py HF)
    unsigned ckpt_interval;
    unsigned entries, checkpoints;
    unsigned polls;                 // polls served so far
    unsigned pos;                   // index of the current entry
} HulkReplayInfo;
int hulk_replay_info(HulkReplayInfo* out);          // 0 when no recording is open

// The game loop's frame counter (GameClock::Update calls so far): frame-keyed files, the auto-START rule and
// checkpoint lookups use it. hulk_ckpt_update (below) maintains it when the checkpoint hook is in use.
// The auto-START rule (recordings whose flags include "autostart", and the legacy lists: START is tapped while
// the frame counter has not moved for more than 60 polls) stays off until this has been called once, so an image
// that does not report frames never gets spurious START presses.
void hulk_replay_set_frame(unsigned frame);
void hulk_replay_set_press_start_ok(int ok);        // the auto-START rule only fires while this is set (default 1)

// The recording's checkpoint for a frame: 1 and *hash when there is one.
int hulk_replay_expected_hash(unsigned frame, unsigned* hash);

// ---------------------------------------------------------------------------------------------
// Checkpoint hashing (hybrid/hooks.cpp checkpoint(), the recordings' flags without "wide"): FNV-1a over the frame
// counter (4 bytes, little endian), then
//   8 bytes   the gameplay RNG state            (0x4e5ad0 in the original image)
//   4 bytes   g_BootSequenceStep                (0x49fb40)
//   12 bytes  the camera's position             (*(0x4e231c) + 0x4c: the singleton pointer is dereferenced first)
//   48 bytes  the GameClock                     (object + 0x10)
// A null pointer skips its region (the singleton before it exists).
typedef struct HulkCkptState {
    const void* rng;                // 8 bytes
    const void* boot_step;          // 4 bytes
    const void* const* camera_ptr;  // address of the camera singleton pointer
    const void* clock;              // GameClock object
    // 1: the state is read at GameClock::Update's entry. The hybrid build hashes in the middle of Update (at its call
    // of GetMicroseconds64, 0x8646e), after Update has zeroed the clock's step and scaled step (+0x28, +0x30, 8 bytes
    // each); the previous frame's values are still there at entry, so they are hashed as zeros.
    int clock_at_entry;
} HulkCkptState;
unsigned hulk_ckpt_hash(unsigned frame, const HulkCkptState* s);
unsigned hulk_fnv1a(unsigned h, const void* data, unsigned long n);

// Per-frame hook (call once per GameClock::Update, where the hybrid build calls checkpoint()). Enabled by the
// environment: HULK_CKPT=<interval> (1 or "on" = every 30 frames, the hybrid default). Each checkpoint frame is
// hashed and, with a recording open, compared with the recording's; mismatches are logged (first 8) and counted.
// Returns 1 when this frame was a checkpoint and matched (or had nothing to match), 0 on a mismatch, -1 when idle.
int hulk_ckpt_update(const HulkCkptState* s);
typedef struct HulkCkptStats {
    unsigned frame;                 // frames seen
    unsigned checked, matched, mismatched, unmatched;   // unmatched: no expected hash for that frame
    unsigned first_bad_frame;       // 0xffffffff when none
    unsigned last_hash;
} HulkCkptStats;
void hulk_ckpt_stats(HulkCkptStats* out);
void hulk_ckpt_reset(unsigned interval);     // tests: start counting frames from 0 with this interval (0 = off)

#ifdef __cplusplus
}
#endif

#endif
