# Hybrid build: our code inside the original XBE, running in xemu

Task 06 (patcher, smoke test, a flag-guarded behaviour change) and the start of task 10 (determinism
hooks, bisect). The hybrid build is the original `default.xbe` with selected functions redirected to our
compiled code. It lets us play-test matched and equivalent functions for behaviour a byte diff can't see,
and it is the vehicle for QoL patches before a full relink.

## What you need (none of it is in git)

| What | Where | Notes |
|---|---|---|
| The extracted disc | `isos/extracted/` (`default.xbe` + the `.rcf` files, `img/`) | never modified |
| xemu | `/Applications/xemu.app` | tested with 0.8.136 |
| Your Xbox MCPX boot ROM, BIOS (flash) and HDD image | `build/xemu/Xbox-Emulator-Files/{mcpx,bios,hdd}/` | file names as in `tools/hybrid_run.py` (`mcpx_1.0.bin`, `Complex_4627.bin`, `xbox_hdd.qcow2`); change `FILES` there for others |
| Your xemu config | `~/Library/Application Support/xemu/xemu/xemu.toml` | read, never written; its EEPROM is copied once to `build/hybrid/eeprom.bin` |
| `xdvdfs` | `cargo install xdvdfs-cli` | packs the disc image |
| The MSVC 7.1 toolchain | `build/compilers/`, `build/tools/wibo` | as for `tools/compare.py` |

Everything the tools write goes to `build/hybrid/`.

## Steps

```sh
PY=build/venv/bin/python

# 1. Pack the disc once (6 s: data files are hard links to isos/extracted; default.xbe is padded to 16 MB)
$PY tools/hybrid_run.py iso

# 2. Baseline: the unmodified XBE, repacked by the pipeline, boots to the title screen
$PY tools/hybrid_run.py run isos/extracted/default.xbe --seconds 150 --interval 15 --tag baseline
#    (or the header-surgery check: an empty .hybrid section, intro movies skipped -> title in ~10 s)
$PY tools/patch_xbe.py --empty-section --tweak skip-intro --out build/hybrid/empty.xbe
$PY tools/hybrid_run.py run build/hybrid/empty.xbe --seconds 30

# 3. Patch functions: first N matches, all matches, plus equivalent/
$PY tools/patch_xbe.py --matches 200 --tweak skip-intro --out build/hybrid/m200.xbe
$PY tools/hybrid_run.py run build/hybrid/m200.xbe --seconds 40 --coverage   # + which patched functions ran

# 4. Test against the hooks-only build on the same input replay; bisect a failure
$PY tools/hybrid_test.py determinism --seconds 45            # the unmodified game, twice
$PY tools/hybrid_test.py compare --matches all --classes identical --seconds 40
$PY tools/bisect_hybrid.py --matches all --classes identical --seconds 40
```

`hybrid_run.py run` installs the XBE into the packed image (in place: it rewrites the 16 MB reserved for
`default.xbe`), starts xemu with a copy of your config (`build/hybrid/xemu.toml`), samples every
`--interval` seconds and quits xemu. Screenshots land in `build/hybrid/shots/<tag>/`, with a
`report.json`.

## How the patcher works (`tools/patch_xbe.py`)

1. **Compile** each source (`matches/0xADDR.cpp`, `equivalent/0xADDR.cpp`) with MSVC 7.1 exactly as
   `compare.py` does; objects are cached in `build/hybrid/obj/` by source hash, and the binding results in
   `build/hybrid/prepare-cache.json`. A full run over all 15,351 sources takes ~90 min on 8 cores the
   first time, seconds afterwards.
2. **Bind** every symbol the object references to an original address with `tools/equiv.py`'s binding
   (`resolve_symbols`: `// equiv-map:` lines, then strings, floats and vftables by content, then names, then
   pairing with the original's instructions). The patcher imports equiv.py and does not change it.
   Compiler-generated EH symbols (`__ehhandler$…`, `__unwindfunclet$…`, `$SG…`) always link to our own
   copy, because their names embed `FUN_xxxxxxxx` and would otherwise bind to the function itself.
3. **Classify**:
   - `identical`: our function linked at the original address is byte-for-byte the original. It can't
     change behaviour, so these go first.
   - `local`: a match whose object calls helpers defined in the object (an inline function MSVC emitted
     out of line); the helpers are linked into the section too.
   - `equivalent`: from `equivalent/`.
   - rejected: shorter than the 5-byte `jmp`; an `// equiv-conv:` annotation (the function or a callee
     takes arguments in registers MSVC can't declare, so it needs an adapter thunk, not done yet); any
     reachable unresolved symbol; a private copy of a writable global.
4. **Link** every accepted object into one new section, `.hybrid`, page-aligned after `$$XSIMAGE`
   (VA `0x58a000`), with `equiv.Ours.link` (the same linker the verifier uses; the patcher points
   `equiv.OURS` at each object's final address). Unreachable functions in an object are linked too.
5. **Redirect**: `jmp ours` (E9 rel32) over the first 5 bytes of each original function. The rest of the
   original body stays, so anything that still points into it (EH funclets, vtables, function pointers)
   keeps working.
6. **Header**: insert one 56-byte section header after the table and shift the rest of the header
   (names, page refcounts, library versions, debug strings, logo) up by 56 bytes, fixing every pointer into
   it; append the section name and its two page-refcount words; grow the header size (`0xda4` → `0xde8`,
   still below the first section at `0x1000`) and the image size; recompute every section's SHA-1 digest
   (`SHA1(u32 raw size ‖ raw bytes)`, checked against the original). xemu does not check the RSA header
   signature with this BIOS.

The manifest next to each XBE (`*.json`) lists every patched function with its new address, and the
address of `g_hybrid`.

### Behaviour changes behind flags (`--tweak`)

| Tweak | Patch | Effect |
|---|---|---|
| `skip-intro` | `g_BootSequenceStep` (`0x49fb40`) starts at 6 instead of 1 | no dolby/marvel/radical/sierra/attract movies: title in ~10 s instead of ~135 s |
| `no-fmv` | `CFMVManager::QueueMovie` (`0x1b7310`) returns at once (`ret 0Ch`); the FMV render (`0x1b7d10`) reads a playing movie's status as 0, "finished" (`call [eax+30h]` at `0x1b7d38` → `xor eax, eax`) | no Bink movies at all. The opening movie, started another way (`0x1b83c0` → `0x1b7f40`), ends at its first render. Movies run the loop unpaced in `GS_FMV`: nothing is presented, so `GameClock::Update` ran as fast as the host could for as long as the movie played in real time (5,000–12,000 updates of 33 ms each) |

These are the first deliberate behaviour changes (task 06 deliverable 3).

## Test hooks (`hybrid/hooks.cpp`, `--hooks`)

Our own C++ (MSVC 7.1), linked at the start of `.hybrid`. It redirects these original calls (in the original
and in our copy of any patched function that contains them), and patches two instructions:

| Site | Original | Hook |
|---|---|---|
| `0x8646e` in `GameClock::Update` | `call GetMicroseconds64` | `hybrid_clock_tick`: frame counter, checkpoint every N frames, virtual clock advancing exactly `dt_us` (33,333 µs) per frame |
| `0x87e40` in the `GameClock` ctor | `call GetMicroseconds64` | `hybrid_clock_now`: the same virtual clock |
| `0x2685d9` in `core::ControllerXBox::vfunc_17` | `call XInputGetState` | `hybrid_xinput_get_state`: replays pad state from `g_hybrid.replay` (keyed by frame, or by pad poll with `pollkey`), and/or records changes into the ring `g_hybrid.record` |
| `0x876e5` in `CGame::Tick` | `call GameClock::Update` | `hybrid_game_tick`: notes `CGame` (`esi`) so the hooks can read the game state (`*(*(CGame+4))`) |
| `0x8763a` in `CGame::Tick` | `call PumpPlatformServices` | `hybrid_pump_services`: with `iosync`, first waits until no `core::DriveThread` has requests pending |
| `0x273465` in the `DriveThread` ctor | `call` thread start | `hybrid_drive_thread_start`: notes each DriveThread (its `+0x8c` counts pending requests) |
| 8 sites: `0x267f07`/`0x267f47`/`0x267f87` (`core::GetMicroseconds`/`GetMicroseconds64`/`GetMilliseconds`), `0x267aa7`, `0x26802c` (`core::TimerList`), `0x292507` (Pure3D timer), `0x3214d7`/`0x3214eb` (`d3dContext`) | `call QueryPerformanceCounter` (`rdtsc`) | `hybrid_qpc`: with `vclock`, the virtual clock |
| `0x1ef2ca`, `0x1efe8d`, `0x1f7362`, `0x1f74b7` (sound) | `call 0x964d0` (the game's RNG) | `hybrid_sound_rng`: with `sound-rng`, the sound code's own generator |
| `0x260ae2` (audio sequencing) | `call _rand` | `hybrid_sound_rand`: with `sound-rng`, its own `rand()` state |
| `0x8668e` in `0x86630` (new game) | `call GetMicroseconds` (the RNG seed) | `mov eax, seed` |
| `0x26918b` in `ControllerSystemXBox::vfunc_12` (with `vclock`) | `jb` (skip the pad poll if less than the poll interval has passed) | `nop nop`: the pad is read on every call, which is once per frame |
| `0x269210`, `0x269241`, `0x269389`, `0x26867a`, `0x268531`/`0x26878b`/`0x2695e7` (with `vpad`) | `XGetDeviceChanges`, `XInputOpen`, the pad-init `XInputGetState`, `XInputSetState`, `XInputClose` | `hybrid_get_device_changes` etc.: one virtual pad in port 1 (docs/tasks/record-replay.md) |
| `0x267ad7` in core `0x267ad0` (with `vdate`) | `call GetLocalTime` | `hybrid_get_local_time`: the date follows the virtual clock |
| `0x2526cc`, `0x25369c`, `0x254ed0`, `0x25527f`; `0x2548f8`, `0x2549c9`, `0x254ca8` (with `seq-rng`) | `mov ecx, [0x4e5acc]` (the game's RNG); `call RandInt` | the sound code's generator (`g_hybrid.seq_rng_ptr`, `hybrid_seq_randint`) |

Flags (`g_hybrid.flags`, `tools/patch_xbe.py` `HF`); with every flag off the hooks call the original:

| Flag | Effect |
|---|---|
| `fixed-dt`, `ckpt`, `replay`, `record`, `autostart`, `wide`, `pollkey` | as before: fixed frame time, checkpoints, input replay/record, START tapped while the loop is stalled in `GS_PRESSSTART`, `.data`/`.bss` page hashes, replay keyed by pad polls |
| `vclock` | every game timer read is virtual (below) |
| `sound-rng` | the sound code draws from its own random generators |
| `iosync` | each frame first waits for the drive threads (opt-in; no requests were ever pending at that point in the tutorial, so it is not in the default set) |
| `vpad` | the game sees one virtual pad in port 1, whatever xemu has bound; recording merges every real pad into it (recording version 2) |
| `vdate` | `GetLocalTime` returns 2006-01-02 12:00 plus the virtual clock (save timestamps, audio event ids) |
| `seq-rng` | the audio sequencer's random actions (volume/pitch variation, random branches, silence and repeat lengths) draw from the sound generator, not the game's (build-time patch) |
| `rng-log` | diagnostic: the game's RNG accessors and the functions that step it inline log (caller, frame) to `g_hybrid.rnglog` |

- **RNG.** Gameplay randomness is a Marsaglia multiply-with-carry generator (multipliers 36969/18000,
  float in [0,1) via the mantissa trick). Its state is `0x4e5ad0`, pointed to by `0x4e5acc`, constructed
  with seed 0 (→ `0xfc7d2ba2`) by a static initializer. Utility `util_GetRandomFloat` is `0x964e0`. The
  only time-based seed is `Seed(GetMicroseconds())` when a new game starts (`0x8669b`). CRT `rand` is
  per-thread and used only by Lua's `math.random` (`0x33bb40`) and audio sequencing (`0x260ae0`). The sound
  code also draws from the game's generator (above). Function-static generators seed with 0.
- **Input.** The pad is read once per main-loop frame by `ControllerXBox::vfunc_17`, so replays are keyed
  by the frame counter. xemu needs a pad in port 1: the config copy binds the keyboard as a
  `usb-xbox-gamepad`. The loading screen after a new game (`GS_PRESSSTART`, `0x86790`) runs its own loop
  that polls the pad but doesn't tick the game clock; when the frame counter stalls for 60 polls in that
  state, the hook releases all buttons and taps START (a button held from the menu blocks it).
- **Checkpoints.** FNV-1a over the frame number, the RNG state, `g_BootSequenceStep`, the first 0x58 bytes of
  the camera's position (3 floats at `*0x4e231c + 0x4c`, singleton `0x1c3d90`; what `rm_GetCameraPosition`
  returns, and it follows the player; a region with a dereference takes an offset in its size's high 16 bits), `GameClock+0x10..0x40` (accumulated real and scaled time, dt, time
  scale; the clock's address is captured from `ecx` on the first tick), and up to 8 host-chosen regions. With
  `--wide`, every 4 KB page of `.data`/`.bss` is hashed too, except the pages and byte ranges in
  `tests/replays/wide-mask.json`. The ring of 4,096 checkpoints is read over QMP `memsave`.
- **Replays** are JSON: `[[frame, buttons, [8 analog buttons], [4 thumb axes]], ...]`, each entry applying
  from its frame on. `tests/replays/newgame-normal.json`: START at frame 150 (title), A at 300 (New Game),
  A at 450 (Normal). XInput buttons: up 1, down 2, left 4, right 8, START 0x10, BACK 0x20; analog index
  0 = A, 1 = B, 2 = X, 3 = Y, 4 = black, 5 = white, 6/7 = triggers. The `capture-*.json` scripts are keyed
  by pad polls. Recordings (below) are `{"key": "polls", "flags", "inputs": [...], "checkpoints", ...}`.
- **Memory dumps at an exact frame.** `g_hybrid.halt_frame` makes the game loop wait at the start of that
  frame until the host clears it (over the GDB stub); `halted` says it is waiting. Two runs dumped at the
  same frames and diffed word by word is how the leaks below were found.

## Determinism after the new-game load

`tools/hybrid_test.py determinism`, `compare`, `bisect_hybrid.py`, `record` and `replay` (and
`trace_capture.py`) build with `vclock` and `sound-rng` on. What varied, and what pins it:

1. **The opening movie (the "runaway").** After Normal is picked, the game enters `GS_FMV` with the opening
   Bink movie, which `no-fmv`'s `QueueMovie` patch didn't catch, while the level loads. The FMV render
   presents nothing, so `SwapBuffers`' vblank pacing never ran and the loop spun as fast as the host allowed
   until the movie ended in real time: 5,000–12,000 `GameClock::Update`s of a fixed 33 ms, so every later
   frame number, and the game time the opening ran for, depended on the host. `no-fmv` now also ends that
   movie at its first render; `GS_FMV` lasts one frame.
2. **Other timers.** `GameClock` was virtual, but everything else that reads the time
   (`core::GetMilliseconds` for the pad poll's rate limit, `TimerList`, sound and script timers, loading
   screens, per-frame time budgets, the Pure3D timer) read `rdtsc`. With `vclock` they all read the virtual
   clock, which only moves at a game-loop update: loops outside the game loop (the loading screen) run a
   host-dependent number of times, so any time that advanced per read there would not replay. Before the
   first update (boot, the copyright screen's 3 s wait), every main-thread read advances it 4 ms, and the
   game loop then starts at a fixed 300 s. The pad poll's rate limit is patched out, because frozen time
   would otherwise keep the `GS_PRESSSTART` loop from ever reading START.
3. **Sound draws from the gameplay RNG.** Dumps of `.data`/`.bss` from two runs halted at the same frames
   first differed in the sound voice manager's per-category counters (`0x4e3768..0x4e37b0`, `0x1f5c20`),
   then in the RNG. Whether a sound gets a voice depends on how many voices are still playing, which the
   emulated audio hardware decides in real time, and voice selection draws from the game's MWC generator
   (`0x964d0` from `0x1ef2a0`, `0x1efe20`, `0x1f7320`), so each run's gameplay RNG sequence shifted at a
   different moment. `sound-rng` gives the sound code its own MWC state and its own `rand()`.
4. **The audio sequencer draws from the gameplay RNG too** (2026-10-17; docs/tasks/record-replay.md). The
   `audio::Seq*` actions (volume/pitch variation, random branches, silence and repeat lengths) read `[0x4e5acc]` or
   call `RandInt` directly, and `sound-rng` didn't catch them. A recording made at ~5 fps parted from its
   full-speed replays at frame 600 by one RNG step. `seq-rng` moves them to the sound generator. Since then, a
   throttled and a full-speed replay of the same recording agree to the end, and so does a ~3 fps recording with
   its full-speed replays. It is in recording version 2; the older flag sets (`determinism`, `compare`) don't
   have it yet.

Results (capture-gameplay.json, frame-keyed, through the junkyard tutorial; checkpoints = RNG, camera position,
`GameClock`, boot step every 30 frames):

| Pinned | Identical through (frames; the load ends at ~455) |
|---|---|
| `GameClock` only (before) | 450 |
| + `no-fmv` ends the opening movie | 7,767 (one run pair) |
| + `vclock` | 8,927; 19,890; < 9,000 (three pairs) |
| + `sound-rng` | 8,760 (one pair of 15-minute runs, ~18,500 frames each) |
| `record` (a script as stand-in player) → `replay` | 15,182 of 15,182 recorded (8.4 min) |

So most runs now stay identical for 4–10 minutes of gameplay, but a leak remains: one run pair with every
flag on still parted at frame 8,760. It is not found yet; the next step is the same halted-dump diff
(`halt_frame`) around that point, with the sound manager's globals masked.

`--wide` is a diagnostic, not part of the pass/fail checkpoints of recordings: `.data`/`.bss` holds heap and
thread-stack pointers, and the memory layout differs between runs of different builds (and sometimes of the
same build), so the page hashes differ even when the game doesn't. Words that differed between two runs of the
same build, masked in `wide-mask.json` (none feeds gameplay as far as the checkpoints show): the
`/GS` cookie (`0x4d9968`, from `rdtsc` at CRT start), the vblank counter (`0x55549c`), Bink's timer
(`0x5660e0..`), the sound voice manager's counters and float clock (`0x4e3714..0x4e37b0`), the sound stream
allocator's pointers (`0x4e5f9c`, `0x4e61ec`), and XAPI/DirectSound state at the end of `.bss`.

## Recording a session (play once, replay forever)

```sh
build/venv/bin/python tools/hybrid_test.py record my-session --out build/replays/my-session.json
```

builds the unmodified game with only the hooks (`fixed-dt`, `vclock`, `sound-rng`, constant seed, `skip-intro`,
`no-fmv`, checkpoints, `record`, and the version-2 pins `vpad`, `vdate`, `seq-rng`: docs/tasks/record-replay.md),
starts xemu, and saves every pad change, keyed by pad poll, plus the checkpoints (default
`tests/replays/NAME.json`; use `--out build/...` to keep it out of git). Play from the title with **any pad**: the
keyboard, or a gamepad xemu binds to any port. The game sees one virtual pad, so it doesn't matter which. Press
START at the loading screen yourself, and press Ctrl-C in the terminal when done (closing the xemu window also
works but loses the last 2 s). Game time is frames × 33 ms, so if xemu renders slower than 30 fps the game runs in
slow motion. The recording still replays exactly at any speed. Movies are skipped.

By default the recording build also quantizes the analog inputs the game is given (`quant`; `--no-quant` records
raw values):
- sticks snap to 1/32 of their travel, with a centre dead zone;
- pressure buttons and triggers snap to 1/8 steps;
- each has hysteresis: a value moves to a new step only once the raw reading is a full step away.

Analog noise would otherwise log a pad change on nearly every poll. The game sees the snapped values, so the
recording still replays exactly. A 32,768-entry ring was tried instead and slowed the game to a crawl (the extra
1.2 MB in the patched image starves the game of memory), so the ring stays at 8,192, and long recordings are
streamed in. The host reads only the new ring entries and checkpoints every 2 s.

```sh
build/venv/bin/python tools/hybrid_test.py replay build/replays/my-session.json [--until-frame N]
build/venv/bin/python tools/trace_gate.py --session s3 --script build/replays/my-session.json
build/venv/bin/python tools/hybrid_test.py salvage OLD.json NEW.json   # a version-1 recording made with two pads
```

With `--snap-every MIN` (default 5) the recording runs on its own overlay of the base HDD
(`NAME.disk.qcow2`) and saves a VM snapshot into it every few minutes (or on `s` + Enter). `replay --from-snapshot
K` / `--from-frame F` and `trace_gate.py --from-snapshot/--from-frame [--shard K/N]` start from one, and
`trace_gate.py --merge` joins parallel shards (docs/tasks/record-replay.md, "VM snapshots").

`replay` runs the same build with the recording as input and compares its checkpoints with the recorded ones.
Recordings longer than the 8,192-entry ring are fed in over the GDB stub while the game runs (`ReplayFeeder`).
`trace_capture.py` does the same while the guest is stopped at a breakpoint (`feed_ring`, tested with an
8,647-change recording that wraps the ring at poll ~275). `determinism --replay` still replays only the first 8,192
pad changes.

## Driving xemu (`tools/hybrid_run.py`, `tools/xemu_gdb.py`)

**Several at once.** `HULK_XEMU_INSTANCE=N` (N > 0) gives a run its own disc image (an APFS clone of
`hulk-hybrid.iso`, made on first use: instant, and only the patched blocks take space), config, EEPROM copy,
QMP socket and GDB port (1234 + N); instance 0 keeps the plain names. Parallel trace captures split the targets
with `--shard K/N` (disjoint by address; the known-bad pinned functions stay in every shard), e.g.

```sh
HULK_XEMU_INSTANCE=0 tools/trace_capture.py --session p0 --shard 0/2 --script R.json &
HULK_XEMU_INSTANCE=1 tools/trace_capture.py --session p1 --shard 1/2 --script R.json &
```

Two 6-minute shards side by side on an M3 captured 160 + 215 functions with no interference.

**No headless mode.** xemu always adds its own `-display xemu` UI, and its NV2A emulation needs a GL context:
with `HULK_XEMU_DISPLAY=none` (passed as `-display none`) the game never gets past boot step 6, so captures
keep a window. `egl-headless` isn't available on macOS.

- xemu accepts `-config_path` and `-dvd_path`, and passes QEMU options through: `-qmp unix:…` for the
  monitor, `-gdb tcp::1234` for the GDB stub, `-S` to start paused, `-snapshot` so the HDD image is never
  written.
- **Screenshots.** xemu has no QMP `screendump`. The harness reads the scan-out address from the NV2A
  register `NV_PCRTC_START` (`0xfd600800`, through HMP `xp`) and saves 640×480 X8R8G8B8 from guest RAM
  with `pmemsave`, written as PNG with zlib. xemu writes rendered frames back to RAM, so this is the
  displayed image.
- **Guest state** comes from HMP `x` (virtual addresses) and `memsave`: the boot step, EIP and `g_hybrid`
  every sample.
- **Coverage** (`--coverage`): one-shot GDB breakpoints on every patched function's new address; the VM
  stops once per function reached. Continuing from a breakpoint needs `z0`/step/`Z0`; QEMU doesn't step
  over it itself.
- **Known xemu issues on macOS**: about 1 launch in 10 crashes xemu itself (SIGSEGV, within 15 s); the
  harness retries. Occasionally the monitor stops answering for good while the guest keeps running
  (seen 4 times, after the new-game load); a 30 s socket timeout ends the run and the data read up
  to then is kept.

## Results (2026-10-10)

- The baseline (unmodified XBE through the pipeline) boots to the "Press START" title in ~135 s; with
  `skip-intro`, in ~10 s. An empty `.hybrid` section boots the same way, which checks the header surgery.
- 12 matched leaf functions, then 199 matches: boot to the title; 3 and 6 of them actually ran
  (`--coverage`).
- Classification of all 15,351 sources: 14,418 byte-identical matches, 6 matches with local helpers,
  156 equivalent. Rejected: 939 shorter than 5 bytes, 31 with `equiv-conv`, 1 unresolved, and 4 whose
  functions.csv extent doesn't end in ret/jmp.
- **The full build: 14,614 functions** (all identical and local matches, and every equivalent except
  `hybrid/exclude.txt`) boots, goes title → menu → difficulty → new-game load → the opening in-engine
  cutscene, and its checkpoints match the hooks-only baseline over frames 0–450.
- Bisects (`tools/bisect_hybrid.py`, 8–23 xemu runs each) found these culprits:
  | Function | Class | Cause | Fix |
  |---|---|---|---|
  | `0x87e30` GameClock ctor | identical | our copy bypassed the fixed-dt hook | hooks are applied inside our copies too |
  | `0x27afb0` | identical | functions.csv says 14 bytes, the function is 18; the match is noreturn-truncated and runs off its end | extent check |
  | `0x88020` CGame::Init | equivalent | `__security_check_cookie` declared `__cdecl`; the original is `__fastcall`, so ecx held garbage and the /GS check hung the boot | cdecl shim in hooks.cpp |
  | `0x241390` | equivalent | a local object of 32 bytes; its ctor writes 64 | excluded |
  | `0x26ce10` MemoryDlAllocator::vfunc_6 | equivalent | declared void; the original returns the allocation in eax | excluded |
  | `0x324e00` d3dContext ctor | equivalent | 4-byte local passed to QueryPerformanceFrequency (writes 8) | excluded |
  | `0x259610` | equivalent | stalls in DSOUND at frame 3 (verified on only 3 inputs) | excluded, not analysed |
  | `0x329f70` | equivalent | stalls at frame 156, entering the menu | excluded, not analysed |
- Determinism (2026-10-10): two runs of the unmodified game with the hooks gave identical checkpoints over
  the front end (frames 0–450). After the new-game load the frame count depended on how long the opening
  movie played; fixed 2026-10-12/13, see "Determinism after the new-game load" and the results there.
  `compare` still checks frames ≤ 450 by default (`--max-frame 0` for all).

## Open

- **Adapter thunks for `equiv-conv`** functions (31 in `equivalent/`): an entry thunk moving register
  arguments to where our compile expects them, and call thunks for callees.
- **Pinning, still open:** the memory layout (heap base, thread stacks) differs between runs, so `--wide`
  can't be a pass/fail check; audio itself (which voices play, the sound manager's state) still follows the
  emulated hardware's real time, it just no longer feeds the gameplay RNG; `iosync` is in place but unproven
  (no drive request was ever pending at the frame boundary in the tutorial); `determinism --replay` doesn't feed
  recordings past 8,192 pad changes.
- Player health, entity counts and mission flags in the checkpoint (the camera position stands in for the
  player's).
- `tools/hybrid_test.py` scenario suite and JSON report beyond `determinism`/`compare`; snapshot capture and
  `equiv.py --inputs-from` (task 10 deliverables 2, 4).
