# Wine replay (rp1)

Goal: run a hybrid recording (`build/replays/*.json`, made by `tools/hybrid_test.py record` on the XBE with the
test hooks) through the **Wine image** and see the same game: the same checkpoint hashes frame by frame. The
hybrid build proved its recordings replay exactly on xemu ([record-replay.md](tasks/record-replay.md)); this page
lists what each of those guarantees means for the Wine build, what is built (rp1), and what native9 had to
provide. Status: native9 to native18 are done and the replays run (play3 matches the hybrid's checkpoints through ~990, see the
status sections below); the pins list is the contract the Wine build implements. Clean-room as the rest of the platform layer ([platform-boundary.md](platform-boundary.md)): the hook
semantics below are read from `hybrid/hooks.cpp` and `tools/patch_xbe.py`, the code is our own.

```sh
PY=build/venv/bin/python
$PY tools/wine_sdl.py test            # host: tests/native_input (includes the replay checks)
$PY tools/wine_sdl.py wine-test       # i686 under Wine: the same through the XDK-shaped stand-ins
$PY tools/replay_pack.py pack build/replays/play3.json build/rp1/play3.hrp   # compact binary (445 KB for play3)
$PY tools/replay_pack.py stream build/replays/play3.json --polls N           # reference pad-stream hash
$PY tools/replay_pack.py synth --check  # the committed synthetic recording is current
HULK_INPUT_SOURCE=replay:build/replays/play3.json HULK_AUDIO_CLOCK=frame HULK_CKPT=1 <Wine image>   # (works since native9-11)
```

Wine replays as queue jobs (any host, headless; docs/compute.md "Wine replays"):

```sh
id=$(build/venv/bin/python tools/wine_replay_job.py submit --name ME --timeout 200)   # image build/native/link, recording build/rp1/play3.hrp
build/venv/bin/python tools/wine_replay_job.py wait $id     # build/jobs/out/$id/wine-out/{ckpt.txt,trace.txt,result.json}
build/venv/bin/python tools/wine_replay_job.py compare $id1 $id2   # common checkpoint frames identical across hosts
```

## What a recording is

`{"version": 2, "key": "polls", "flags": [...], "seed", "tweaks", "inputs": [[poll, buttons, [8 analog], [4 thumbs]]],
"checkpoints": [[frame, hash]], ...}`. An input entry is written only when the pad state changes; it applies from
that poll on. The checkpoint list is the hybrid run's own record of the game state every 30 frames.

The recording is only meaningful together with the pins its flags name (play3: `fixed-dt ckpt pollkey vclock
sound-rng vpad vdate seq-rng record quant`) and its tweaks (`skip-intro no-fmv`): they remove every host input from
the game, and the hash is only reproducible when the Wine image has the same pins.

## Built: the input source (`HULK_INPUT_SOURCE=replay:<file>`)

`src/platform/sdl/replay/hulk_replay.{h,cpp}` (compiled into `hulk_sdl.lib` as part of `input/hulk_input.cpp`, so
`wine_sdl.py` needs no change), selected like the other sources in `hulk_input_init`.

Poll semantics, from `hybrid_xinput_get_state` (`hybrid/hooks.cpp`):

| hybrid | Wine replay source |
|---|---|
| the game sees **one virtual pad** in port 1 (`vpad_count` pads in ports 1..n for old interleaved recordings), inserted at its first `XGetDeviceChanges`, then no changes; every read succeeds | `connected` = ports 0..n-1, generation fixed, so `hulk_input_changes` reports the insertion once; reads of other ports fail and are not polls |
| a **poll** is one read by `ControllerXBox::vfunc_17` (call site 0x2685d9); the counter counts every pad together, increments *before* the lookup (the first read is poll 1) | `read()` increments one counter shared by all ports |
| the **pad-init reads** (`0x2692c0`, 20 per new pad object) are a different call site: idle state, not polls | `read_init` (`hulk_input_read_init`): idle state, no count |
| the state is the last entry with `key <= poll`; before the first entry the pad is idle; after the last the state holds for good | same (an advancing cursor, as the hybrid) |
| frame-keyed files (version 1 / the bare lists in `tests/replays/`): key = `g_hybrid.frame`; flag `autostart`: while the frame has not moved for more than 60 polls and the game is at PRESS START, release everything and tap START (`(stalled >> 3) & 1`) | `hulk_replay_set_frame` supplies the frame; `hulk_replay_set_press_start_ok(game_state == 3)`; the rule stays off until the first `set_frame` so an image that does not report frames never gets spurious presses |
| rumble completes at once, real pads are never touched | `rumble` is ignored (the XPP shim already completes the request) |

Files: JSON (the recording, or a bare entry list) and `.hrp` (tools/replay_pack.py: 36-byte header, 24-byte entries,
8-byte checkpoints; format in the tool's docstring). A file that cannot be read or parsed makes the source "none"
(logged), never live pads: a replay must not silently turn into a played game.

**Tests** (`tests/native_input/input_test.cpp`, host 73 / i686 under Wine 75 checks, sa1's 29/31 still pass): the
synthetic recording (`synth_replay.json`, `.hrp`, `.inc`, generated by `tools/replay_pack.py synth`) against a
hand-written table for 40 polls, init reads not counted, a read of an unplugged port not counted, two pads sharing
the counter, the frame-keyed list and the auto-START rule (off without frames; first tap at stalled poll 61, three
taps in 100; off when the game is not at PRESS START), JSON and `.hrp` giving the same stream as the independent Python
reference, bad files, `HULK_INPUT_SOURCE` with a missing and a present file. Against the local recordings (never
committed; `HULK_TEST_REPLAY=<file> HULK_TEST_REPLAY_POLLS=N`): the C++ stream hash equals
`replay_pack.py stream` for play3 (1,231,393 polls, `bf40be73`, JSON and `.hrp`), final2 (14,134 polls, `853a6305`),
snaprec (15,489, `fcd8b3dd`), play2-salvaged (63,012, `1e21ba60`).

## What else a Wine replay needs

Everything below is a host input the hybrid build pinned. Where the Wine image already has one choke point (the
shim), the pin is small; where the hybrid patched original code, native9 needs the same patch in the tree's build.

| # | hybrid pin | how the hybrid does it | native plan | who |
|---|---|---|---|---|
| 1 | **frame counter** | `GameClock::Update` 0x86450: the call of `GetMicroseconds64` at 0x8646e becomes `hybrid_clock_tick`; `frame` counts Update calls, 0 before the first | the link already wraps 0x86450 (`_hulk_clock_update` -> `hulk_pddi_clock_tick`, G3). Call `hulk_ckpt_update` from the same wrapper (below) | native9 |
| 2 | **fixed dt, virtual clock** (`fixed-dt`, `vclock`) | Update returns `VCLOCK_BASE_US (300 s) + n * 33333 us`; after the first Update every QPC read of game code (8 sites) returns the virtual clock, which stands still between updates; before it, each main-thread read advances it 4 ms; Bink and DirectSound keep the real counter | `xdk/timing.cpp` `hulk_xdk_QueryPerformanceCounter` (and `GetTickCount`-style readers) is the single choke point: a `HULK_VCLOCK=1` mode with the same rules (main thread = the thread of the first read; other threads read the virtual value, only main-thread reads count towards `extra_us`). The tree's `core::GetMicroseconds64` 0x267f40 then returns the virtual value without further change. Audio/Bink are SDL-side and keep real time | native9 (timing.cpp) |
| 3 | **poll rate limit removed** (`vclock`) | `VCLOCK_PATCHES`: the `jb` at 0x26918b (`ControllerSystemXBox::vfunc_12`: `if (now - last < interval) return`) becomes two `nop`s, because the virtual clock stands still between updates and the PRESS START loop would never poll | **required** for poll parity: matches/0x00269170 must poll on every call in replay mode (a verified-source variant or a `HULK_REPLAY` switch in the tree's build). Without it the poll counter runs at the real rate limit and the input stream drifts from the first frames | native9 |
| 4 | **vpad** | device calls redirected: `XGetDeviceChanges`, `XInputOpen/Close/SetState`, the pad-init `XInputGetState` | the XPP shim already is the device layer. Needed: tell the init read from a poll (item A in for-native9.md) | native9 (xdk/input_xpp.cpp) |
| 5 | **new-game reseed** | 0x86630 calls `Seed(GetMicroseconds())` at 0x8668e; the build patches it to a constant (`seed` in the file, 0x1234 for every recording) | per-call-site binding to a function returning `hulk_replay_info().seed` (the link's per-function rebinding already exists); without a replay, the real clock | native9 |
| 6 | **sound-rng** | the 4 sound-code calls of the RNG accessor 0x964d0 (0x1ef2ca, 0x1efe8d, 0x1f7362, 0x1f74b7) return a private MWC state (init `0x2F6B6F2A, 0x1F123BB5`); the CRT `rand()` call at 0x260ae2 (audio sequencing) is a private LCG (seed `0x5EED`, `*214013 + 2531011`, `>> 16 & 0x7fff`) | same, per call site, in the Wine link: the sites are ordinary calls in the tree. Needed because sound draws would otherwise shift the gameplay RNG | native9 |
| 7 | **seq-rng** | the audio sequencer's inline MWC steps (`mov ecx, [0x4e5acc]` at 0x2526cc, 0x25369c, 0x254ed0, 0x25527f) read the sound generator's pointer instead; the `RandInt` (0x113e0) calls at 0x2548f8, 0x2549c9, 0x254ca8 draw from it (`hybrid_seq_randint`, same step and modulo) | the data reads: per-function rebinding of `DAT_004e5acc` to a pointer variable that points at the sound generator (the link's `hulk_at_` mechanism rebinds data by name per function); the three calls: rebound to a copy of RandInt on the private state. These draws happen when a voice ends, so even with `HULK_AUDIO_CLOCK=frame` they must be isolated: the native mixer ends a voice on a frame boundary that need not equal xemu's | native9 |
| 8 | **vdate** | `GetLocalTime` at 0x267ad7 returns 2006-01-02 12:00 plus the virtual clock (saves' slot stamps, audio event ids) | `xdk/timing.cpp` `hulk_xdk_GetLocalTime` in `HULK_VCLOCK` mode: the same formula (`hooks.cpp hybrid_get_local_time`: day = 2 + days % 28, dow = (1 + days) % 7) | native9 |
| 9 | **tweaks** | `skip-intro`: `g_BootSequenceStep` (0x49fb40) = 6 at load; `no-fmv`: `CFMVManager::QueueMovie` 0x1b7310 returns at once, FMV render 0x1b7d38 reports "finished" | `HulkReplayInfo.tweaks` says which. skip-intro: write the variable before the first frame (it is also in the checkpoint hash); no-fmv: mv1's movie layer finishes at once in replay mode (`HULK_NATIVE_MOVIES=none`-like) | native9 / mv1 |
| 10 | **iosync / syncio** | the game streams through `core::DriveThread` (0x272fc0 posts a request, the handler runs on the drive's own thread); which frame a result lands in followed the host and parted replays at frame 51570 of play3 (build/snapdiv/RESUME.md). Fix: after each post the main thread sleeps until the drive's request count (`drive + 0x8c`) is 0, so every request completes in the frame that made it | the native fs layer (fs1) completes a read inside the DriveThread's own thread, so the same race exists. Same wait after 0x272fc0 (a link wrapper on that function, polling the drive's `+0x8c` with a 2 s limit, as `syncio_stub`), plus `hybrid_pump_services`' wait before the pump at 0x8763a | native9 / fs1 |
| 11 | **audio clock** | n/a (xemu audio is real time; seq-rng isolates the draws) | `HULK_AUDIO_CLOCK=frame` (sa1): voices advance 1/60 s per `DirectSoundDoWork`, so voice-end events (dialogue finishing, which scripts wait on) land on the same update every run. Not necessarily the update xemu's hardware produced: recordings made with real-time audio have script-visible timing from the DSP; see "limits" | sa1 / native9 |
| 12 | **checkpoint hash** | `checkpoint()` every 30 frames at Update | `hulk_ckpt_hash` / `hulk_ckpt_update` (built, below) | rp1 + native9 symbols |

### Checkpoint hashing (built)

The recordings' hash (no `wide` flag) is FNV-1a (32 bit) over: the frame counter (u32 LE), then

| bytes | what | original address |
|---|---|---|
| 8 | the gameplay RNG state (two MWC words) | 0x4e5ad0 |
| 4 | `g_BootSequenceStep` | 0x49fb40 |
| 12 | the camera position: the singleton pointer at 0x4e231c is dereferenced, +0x4c (skipped while null) | 0x4e231c |
| 48 | the GameClock at +0x10 (total, scaled total, elapsed, step, scaled step, rate) | the object `GameClock::Update` runs on |

taken before the frame counter increments, when `frame % 30 == 0`. `hulk_ckpt_hash(frame, &state)` computes it from
native pointers; `hulk_ckpt_update(&state)` is the per-frame call (enabled by `HULK_CKPT=<interval>`, `1` = every 30):
it hashes, compares with the recording's checkpoint for that frame, logs the first 8 divergences, keeps
`HulkCkptStats` (first bad frame), and sets the replay's frame counter. **Timing difference:** the hybrid hashes in
the middle of `Update`, after it has zeroed the clock's step and scaled step; a wrapper at the function's entry sees
the previous frame's values there, so it sets `clock_at_entry = 1` and they are hashed as zeros. Layout: all four
regions are plain data in the game's own structs (compiled with the original layout, checked by the equivalence
work), so the native hash is byte-comparable as long as the simulation is.

The unit test cross-checks the hash against an independent Python implementation (`replay_pack.py hash`, the
synthetic recording's checkpoints: two agree, one is deliberately wrong and is reported as the first divergence).
**Not reproduced from real data:** no committed or local dump holds the camera and clock objects (the saved dumps in
`build/replays/dumps/` are `.data`/`.bss` only; the camera singleton and the clock are heap objects), so a known
hybrid value (play3's frame-0 hash 1932372803) could not be recomputed. The first Wine run against play3 is the
real test: frame 0 must match (the hash then depends on seed, skip-intro, the clock's initial fields), and the
output of `HULK_CKPT` names the first frame that does not.

### Status (native11, 2026-10-20)

play3 replays natively with every pin except syncio: **frames 0-420 match the recording at all 15 checkpoints**
(docs/wine-build.md "native11"). Frame 0 needed fresh (zeroed) heap memory: the hybrid's camera position and clock
fields that the constructors leave are 0 on the Xbox. Pins in the Wine image: 1-5, 8 (native10), 6 and 7
(`SITE_REBIND` to xdk/replay_hooks.cpp's `hulk_sound_rng`, `hulk_sound_rand`, `hulk_seq_rng_ptr`, `hulk_seq_randint`;
two seq-rng sites, 0x254ed0 and 0x2548e0, are in functions with no source), 9 (skip-intro and no-fmv: entry hooks on
0x1b7310 and 0x1b7d10), 10 (an exit hook on 0x272fc0, **off unless `HULK_SYNCIO=1`**: play3 was recorded without
syncio; note the .hrp's bit 13 (seq-rng) is the hybrid's HF_SYNCIO bit, so an .hrp can't say syncio), 12. The log
line `ckpt frame N hash ... (io posts, waits, timeouts, sound rng)` counts the pins' activity; the first divergence's
regions (RNG, boot step, camera position, clock block) are logged to the trace.

### Status (native12, 2026-10-20)

Still 15 of 15 checkpoints (frames 0-420) on HEAD 8c871013 (x64-1's consolidation b1-b7, build_tree's uniqueness check,
the lanes' new matches) once five native classes were fixed (docs/wine-build.md "native12"). The first level's
load now completes: the fight tracks parse (stop 31 was a mis-verified factory, fixed by the uniqueness check), the
level's Lua runs without a runtime error, and the run stops in the first gameplay update (stop 34: the main actor is
never set, `am_SetMainActor` is registered but no script calls it; open). The replay needs the untracked
equivalent/0x0029e6c0.cpp (another session's file): without it the image stops in a missing `Light` constructor.

### Status (native13, 2026-10-20)

On HEAD 26a05b20 plus native13's six rewrites (and the pending 0x0030ed60, see docs/wine-build.md "native13"):
frames 0-420, 480 and 510 match; the first level loads and Hulk spawns at frame 439 as in the hybrid; the image
then plays all of play3's inputs (to frame 58,500) without a crash, but the checkpoints from 540 on differ: Hulk's
head-tracker action never updates natively (its node lands in the list run with selector 1), first visible as the
target search 0x00039c60 at frame 445 in the hybrid and 6628 natively (stop 37, open). Finding where two runs part
without xemu: the trace session's census (first frame of every traced function) against native probes, whose
`fcall` lines now carry `f=<frame>`; `HULK_CKPT_REGIONS=1` logs the hashed regions at every logged checkpoint
(brute-forcing which region a recorded hash differs in, e.g. the RNG by N draws).

### Status (native14, 2026-10-20)

Four native bugs on play3's path fixed (docs/wine-build.md "native14"): Hulk's head tracker (a thiscall reached
through a free `__stdcall` declaration bound per calling function), the state props' change events (a listener
event structure the source didn't fill), Hulk's position getter's x87 precision, and the ambient cows (check 7: a
callee-pops mismatch that clang's call-frame re-reservation turns into garbage arguments). Checkpoints 0-420,
480, 510, 570 and 630 match; 450-690's other checkpoints differ only in the camera's y by 1-14 ULP (the x87
precision class: MSVC keeps float temporaries in 53-bit registers, clang -O0 rounds float locals). The census of
first calls agrees with the hybrid's to frame 914, where a streamed resource completes one frame later natively
(I/O timing: play3 has no syncio). New probe aids: `HULK_TRACE_FROM`, `HULK_TRACE_WATCH`, `HULK_TRACE_EXIT` /
`HULK_TRACE_XDEREF`; `HULK_CKPT_REGIONS=1` plus a brute force over small ULP changes of the camera tells a
precision difference from a logic one.

### Status (native16, 2026-10-21)

Checkpoints 0-420 and 480-840 match (28); 450 is still -1 ULP in the camera's y (the frame is black, mid-fade, in
both); 870 differs only in the RNG (14 draws behind, camera exact): an AI agent's draws (CRangedAgent::vfunc_9
0x00107300 and FUN_00107140 / FUN_00037860 / FUN_000fee10) are missing natively at 857, after a prop's physics
first differs at 840. The image plays play3 to frame 103,500 with no crash or hang. Side-by-side screenshots of
the diverged checkpoints (native | hybrid, scratch only): same scene and camera up to 1,050 with small pose
differences, Hulk doing something else by 1,500, a different tutorial page by 6,000.

**Method that found 810 and the rest** ([wine-build.md](wine-build.md) "native16"): the checkpoint brute force
(camera exact? RNG how many draws behind?), then an rng-log hybrid (`rl3`) against native RNG-accessor probes to
name the missing draws' caller, then hybrid loggers written over GDB (`rl4 --fn/--site/--mem`, per-frame records in
the unused `record[]` ring) against native `HULK_TRACE_SPAN` dumps of the same objects, frame by frame, to the first
differing word, and `HULK_TRACE_WATCH` (now also absolute addresses) to the native writer.

**I/O (stop 41).** The instrumented hybrid capture: loggers at DriveThread's post (0x272fc0), request step
(0x273210) and retirement (0x27336c) on play3 to frame 1,000 saw 1,089 posts, every request retired within the
frame it was posted. The hybrid therefore behaves as "every request completes before the next frame"; natively the
914/915 race is a request that stays pending (more than 300 ms) while the main thread waits, i.e. a dependency on
main-thread work, not xemu latency.

### Status (native17, 2026-10-21)

Checkpoints as native16 (0-420, 480-840), and now **deterministic**: `HULK_SYNCIO=5` ("lockstep", the default when a
recording is open) runs the drive threads (start routine 0x26db70, worker 0x2731d0) one request at a time and only
on the main thread's turn: after a post made while the main thread holds no critical section, at
`GameClock::Update`'s entry, at the drive pump 0x272df0 (`core::Drive::vfunc_3`, a new `ENTRY_HOOKS` entry), and when
the main thread sleeps, switches fibers or waits; the drive's error wait (a failed open) is a turn too
(src/platform/sdl/xdk/replay_hooks.cpp, threads.cpp, library.cpp). Three runs give 0x00203a80's first call at frame
917 every time (it was 914 or 915 by run; the hybrid: 914) and two runs with `HULK_CKPT_ALL=1` are identical at all
326 checkpoints to 9,750. The 3 frames to the hybrid's 914: natively the sound code requests .rsd files that no RCF
holds (`sound\rsd\3\346494a868380c06.rsd` from frame 2, `1\1903a420eb3c5dce` and `e\e828675c1d7e5e29` every frame from
~440), each through the drive's error path and retried every frame; the hybrid posts none of them. The ranged
enemy (CRangedAgent) that the hybrid spawns at 857 spawns natively at 891 although the spawner, camera, visibility
and distance (68.72) agree. 0x000a75d0 (`CChaseCamera::vfunc_35`) rewritten with its square root unrounded (cl7's
`x87_order.py`); its two reassociated sums cannot be spelled without MSVC reordering an unrelated sum.

### Status (native18, 2026-10-21)

**Checkpoints 0-420 and 480-990 match** (33; native17: 0-420, 480-840). The image still crashes near frame 3,900
on the diverged path (native15's `Obj_2250e0::set` with a null AnimationDriver). What changed
([wine-build.md](wine-build.md) "native18"):

- **The ranged enemy at 857** (native17's goal): equivalent/0x001f9810 compared the spawn distance with the
  literals 70 / 20. The original reads two globals that Lua sets (`tvm_SetSpawnDistanceOnCamera` /
  `OffCamera`, 0x004c83ec / 0x004c83e8), and play3's script lowers them, so the hybrid spawned at distance 68.72.
  A sweep for the same class (a writable global that the original reads, that other code writes, and that the
  equivalent source never names) found 7 more: two AI distance-squared thresholds (0x0007a420, 0x00081b20), an overlay
  quad height (0x000d50f0) and four sound volume scales (0x001f3af0, 0x001f4140, 0x001f5640, 0x001f56b0). The checker
  can't see this class: it seeds data with the load-time values only.
- **The missing .rsd files and stop 41's 3 frames:** the host CRT table mapped 0x00348380 to `_strupr`, but it is
  `_strlwr`. The sound key constructor (0x00253a90) folds a name before hashing it into the 64-bit id that names
  `sound\rsd\<c>\<id>.rsd`, so every stream and clip id was wrong. No .rsd open fails now, and 0x00203a80 first
  runs at frame 914, as in the hybrid (native17: 917). With the sounds found, the newly reached sound code had two
  native-only bugs: 0x00258f40 (an eax-convention function written as a thiscall member, its caller pushing the
  argument) and matches/0x0025d070 (an argument passed to the wrong one of two nested calls).
- **1020** (open): RNG callers are identical from 990 to 1033. The chase camera is equal through 1019 and differs
  at 1020 because Hulk's walk velocity (CCharacter +0x74, written by FUN_000418f0) differs at 1019. Behind it:
  Hulk's ground-contact plane list is sorted by depth (0x00038e80). From frame 1009 the depth of Hulk's capsule
  contact, reported through AICollisionSolverAgent::vfunc_5 (0x001b2560, contact +0x24), has its low bits rounded
  off natively (hybrid 0xbcb40858, native 0xbcb40800): a float rounding of a ~1,000-magnitude coordinate term in
  the narrowphase, the same x87 precision class as native16's chase. At 1019 the two lists sort differently.
- **450** is unchanged with 0x000a75d0's unrounded sqrt (hash 90d3d9ad, as native17).

Probe aids: `HULK_TRACE_WATCH` takes pointer chains (`=<address>@+<offset>@+<offset>`), and `fcall` lines show six
stack words. The hybrid logger `~/hulk-tr1/rl4-native18.py` (mac2) takes an absolute start address in `--mem`
chains (`0x4e231c@+4c`).

### Status (native15, 2026-10-20)

Checkpoints 0-420 and 480-780 match (24 of 27); 450 differs by -1 ULP in the camera's y; from 810 the gameplay
RNG and the camera part (docs/wine-build.md "native15": the x87 precision fixes located with x87's mixed build).
The census of first calls agrees with the hybrid's to frame 914; the next difference is the action at 953.

**I/O timing (stop 41).** Every request of the game goes through one `core::DriveThread` (vftable 0x42b8f8):
FileOpenRequest (most posts), FileReadRequest, FileCloseRequest, DriveFindNextRequest, and the audio stream's
persistent read. Without a wait the frame a result lands in follows the host's threads: the same image gave
0x00203a80's first call at frame 914 in some runs and 915 in others (the hybrid: 914), with identical checkpoint
hashes through frame 1,900 and more. Guest-time models (`HULK_SYNCIO`, off by default; `HULK_SYNCIO_LOG=1` logs
each post's frame, request class and queue count): 1 = the hybrid's syncio (whole queue; stalls 2 s at a time on
the audio stream's persistent read); 3 = every request completes before the next frame (wait at
GameClock::Update's entry for each request posted before it); 4 = every request completes at once (wait after the
post). A request counts as done when it is no longer queued and the drive runs nothing else; one still pending
after 300 ms is treated as a stream (its class is logged and not waited on again). Result: 3 and 4 still give 914
or 915 depending on the run, because a FileOpenRequest stays pending for more than 300 ms while the main thread
waits (its completion depends on work the main thread does later), so the model drops it and the race returns;
the tr1 trace sessions don't pair posts with completions, and gdb breakpoints in xemu stop the VM and change the
very timing to be measured. What would settle what xemu does: an instrumented hybrid build (hooks.cpp recording
each post and each request's retirement with the frame and poll count, as the checkpoint ring does) on play3.
Until then 914/915 is a host-timing difference that no checkpoint sees. Proposal: measure xemu's post-to-retire
latency per request class that way, then complete each class natively after that many frames (the drive
thread's work run at fixed points of the main loop), and re-record with syncio for any recording that has to pin
it (not verified here).

### Limits and expectations

- **What has to be exactly equal.** The hash covers the gameplay RNG, the camera and the clock, so it is a
  sensitive end-to-end check: any simulation difference (input timing, a draw count, physics, an unverified
  function) shows at the next checkpoint. Expect native to part from a recording somewhere, and use
  `first_bad_frame` plus `tools/snapdiv`-style dumps to find why; the hybrid work found three causes this way (pad
  interleaving, sequencer draws, I/O timing) and the same classes apply here.
- **Audio-driven events** (a line of dialogue ending, a script waiting on a sound) depend on when the voice ends.
  xemu's hardware ends it in its own time; the native frame clock ends it at an exact update. If the xemu run's end
  fell in another update than ours the scripts diverge from the recording through no fault of the simulation. If that
  happens, the fix is on the recording side (a recording made with the native frame clock), not the replay.
- **Saves and the disk.** Recordings start from an empty HDD overlay; the Wine build must start from an empty
  save directory (`HULK_SAVE_DIR` pointing at a fresh one) and run with `vdate` so slot stamps match.
- **Old recordings** (play1, play2) were made before the pins and do not replay even on xemu; use v2 files (play3,
  final*, snaprec) for native work.

### Milestones

1. **Input only** (this task): `HULK_INPUT_SOURCE=replay:<file>`, no pins: the menus react to the recorded presses.
   Frame-0 and early checkpoints will not match yet.
2. **Pins 1-5, 8, 9** (clock, poll limit, reseed, date, tweaks) and `HULK_CKPT=1`: frame 0 and the first checkpoints
   of play3 should match (before any sound draws: the first 330 frames of the new-game load).
3. **Pins 6, 7, 10, 11**: the full play3 (56,566 frames, 1,886 checkpoints). First-bad-frame reports drive the rest.
4. Then the Wine run can play a recording for the other agents' tools: draw-log comparison with the hybrid
   (`drawlog_diff.py`), trace capture on the native side, and regression runs of the Wine image.
