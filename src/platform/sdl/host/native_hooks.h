// The replay hooks of the native builds (docs/native-android.md section 14, A2 item 4): where the Wine build's link
// (tools/wine_link.py ENTRY_HOOKS, EXIT_HOOKS, SITE_REBIND and the --gfx clock wrapper) puts our functions between the
// game's, the native link (tools/native_bind.py, the same renaming of references in the game's objects that binds the
// native CRT table) does the same from this table. Data for the link only; never expanded by the compiler.
//
// H(kind, address, other, hook, status, "why"):
//   entry  every reference to the game's function at `address` (the tree's definition, or a name carrying the
//          address) outside its own object goes to `hook`, which calls the definition through `hulk_orig_<address>`
//          (a thunk the link writes). References inside the defining object are not hooked: the link reports them.
//   site   in the object defining the caller at `address`, the references to the function at `other` go to `hook`
//          (the Wine build's per-call-site rebinding). Applied only when every such reference of that object lies
//          inside the caller (relocations by function); otherwise reported and left alone.
//   data   as site, for the data item at `other` (a pointer the caller reads): `hook` is our pointer-sized variable.
// status: `ready` (the native link applies it), `layout` (the Wine hook reads the game's objects at their 32-bit
// offsets or x86 register images: it needs the class's 64-bit layout first, so the native link leaves it out and
// reports it) or `gfx` (the graphics build's, with the pddi backend: not in a headless image).
//
// The hooks live in src/platform/sdl/host/replay_native.cpp (and, for the virtual clock and the pad init read, the XDK
// shim's timing.cpp / input_xpp.cpp, compiled as host code). Host code calls a game function by address through the
// link's thunks: `hulk_orig_<address>` and, for the shim's existing spelling, `FUN_<address>`.
#ifndef HULK_PLATFORM_SDL_HOST_NATIVE_HOOKS_H
#define HULK_PLATFORM_SDL_HOST_NATIVE_HOOKS_H

#define HULK_NATIVE_HOOKS(H) \
    H(entry, 0x00086450, 0, hulk_nhook_clock_update, ready, \
      "GameClock::Update: the per-frame checkpoint at the update's entry (Wine: the --gfx clock wrapper's hulk_native_frame)") \
    H(site, 0x00086450, 0x00267f40, hulk_clock_tick, ready, \
      "GameClock::Update's time: fixed dt / the virtual clock with a replay or HULK_VCLOCK=1 (request D; xdk/timing.cpp)") \
    H(site, 0x00087e30, 0x00267f40, hulk_clock_now, ready, "the GameClock constructor's first timestamp (request D)") \
    H(site, 0x00086630, 0x00267f00, hulk_replay_seed, ready, "the new-game reseed: the recording's seed (request E)") \
    H(site, 0x002692c0, 0x003eb91f, hulk_xdk_XInputGetStateInit, ready, \
      "ControllerSystemXBox's pad constructor reads a new pad 20 times: not polls (request A; xdk/input_xpp.cpp)") \
    H(site, 0x001ef2a0, 0x000964d0, hulk_sound_rng, ready, "sound-rng: the sound manager caches the RNG it draws from") \
    H(site, 0x001efe20, 0x000964d0, hulk_sound_rng, ready, "sound-rng: 0x1efe8d") \
    H(site, 0x001f7320, 0x000964d0, hulk_sound_rng, ready, "sound-rng: the voices' draws") \
    H(site, 0x00260ae0, 0x0034774c, hulk_sound_rand, ready, "sound-rng: audio sequencing's rand()") \
    H(data, 0x002526b0, 0x004e5acc, hulk_seq_rng_ptr, ready, "seq-rng: SeqActionVarVolumeRand::vfunc_1 reads the RNG pointer") \
    H(data, 0x00253680, 0x004e5acc, hulk_seq_rng_ptr, ready, "seq-rng: SeqActionVarPitchRand::vfunc_1") \
    H(data, 0x00255250, 0x004e5acc, hulk_seq_rng_ptr, ready, "seq-rng: SeqCommandLogicOr::vfunc_0") \
    H(site, 0x002549a0, 0x000113e0, hulk_seq_randint, ready, "seq-rng: SeqEventSilence::vfunc_2 -> RandInt") \
    H(site, 0x00254c80, 0x000113e0, hulk_seq_randint, ready, "seq-rng: SeqEventLogicRepeat's state -> RandInt") \
    H(entry, 0x00269170, 0, hulk_nhook_pad_poll, layout, \
      "ControllerSystemXBox::vfunc_12: the poll's rate limit off with a recording open (request C; the pad's +0x12a0/+0x12a4)") \
    H(entry, 0x001b7310, 0, hulk_nhook_fmv_queue, layout, "no-fmv: CFMVManager::QueueMovie returns at once (`ret 0xc`)") \
    H(entry, 0x001b7d10, 0, hulk_nhook_fmv_render, layout, "no-fmv: the FMV render takes its finished path (+0xc, +8)") \
    H(entry, 0x00272fc0, 0, hulk_nhook_drive_post, layout, "syncio: core::DriveThread's post (the drive's +0x8c count)") \
    H(entry, 0x00272df0, 0, hulk_nhook_drive_pump, layout, "syncio: core::Drive::vfunc_3, the lockstep drive pump") \
    H(site, 0x001c1a40, 0x00344e74, hulk_cast_self, gfx, \
      "--gfx only: HulkShaderCallback's dynamic_cast of the pddi effects extension (xdk/library.cpp)")

#endif
