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
| `no-fmv` | `CFMVManager::QueueMovie` (`0x1b7310`) returns at once (`ret 0Ch`) | no Bink movies at all; needed by frame-keyed replays, because the game loop doesn't tick while a movie plays |

These are the first deliberate behaviour changes (task 06 deliverable 3).

## Test hooks (`hybrid/hooks.cpp`, `--hooks`)

Our own C++ (MSVC 7.1), linked at the start of `.hybrid`. It redirects three original calls and one
instruction, in the original and in our copy of any patched function that contains them:

| Site | Original | Hook |
|---|---|---|
| `0x8646e` in `GameClock::Update` | `call GetMicroseconds64` | `hybrid_clock_tick`: frame counter, checkpoint every N frames, virtual clock advancing exactly `dt_us` (33,333 µs) per frame |
| `0x87e40` in the `GameClock` ctor | `call GetMicroseconds64` | `hybrid_clock_now`: the same virtual clock |
| `0x2685d9` in `core::ControllerXBox::vfunc_17` | `call XInputGetState` | `hybrid_xinput_get_state`: replays pad state from `g_hybrid.replay` (keyed by frame), or records changes into `g_hybrid.record` |
| `0x8668e` in `0x86630` (new game) | `call GetMicroseconds` (the RNG seed) | `mov eax, seed` |

- **RNG.** Gameplay randomness is a Marsaglia multiply-with-carry generator (multipliers 36969/18000,
  float in [0,1) via the mantissa trick). Its state is `0x4e5ad0`, pointed to by `0x4e5acc`, constructed
  with seed 0 (→ `0xfc7d2ba2`) by a static initializer. Utility `util_GetRandomFloat` is `0x964e0`. The
  only time-based seed is `Seed(GetMicroseconds())` when a new game starts (`0x8669b`). CRT `rand` is used
  only by Lua's `math.random` (`0x33bb40`) and audio sequencing. Function-static generators seed with 0.
- **Input.** The pad is read once per main-loop frame by `ControllerXBox::vfunc_17`, so replays are keyed
  by the frame counter. xemu needs a pad in port 1: the config copy binds the keyboard as a
  `usb-xbox-gamepad`. Loading screens run their own loop that polls the pad but doesn't tick the game
  clock; when the frame counter stalls for 60 polls the hook releases all buttons and taps START (the
  loading screen waits for START, and a button held from the menu blocks it).
- **Checkpoints.** FNV-1a over the frame number, the RNG state, `g_BootSequenceStep`, `GameClock+0x10..0x40`
  (accumulated real and scaled time, dt, time scale; the clock's address is captured from `ecx` on the first
  tick), and up to 8 host-chosen regions. With `--wide` (in `hybrid_test.py determinism`), every 4 KB page of
  `.data`/`.bss` is hashed too, except the pages in `tests/replays/wide-mask.json`. The ring of 4,096
  checkpoints is read over QMP `memsave`.
- **Replays** are JSON: `[[frame, buttons, [8 analog buttons], [4 thumb axes]], ...]`, each entry applying
  from its frame on. `tests/replays/newgame-normal.json`: START at frame 150 (title), A at 300 (New Game),
  A at 450 (Normal). XInput buttons: up 1, down 2, left 4, right 8, START 0x10, BACK 0x20; analog index
  0 = A, 1 = B, 2 = X, 3 = Y, 4 = black, 5 = white, 6/7 = triggers.

## Driving xemu (`tools/hybrid_run.py`, `tools/xemu_gdb.py`)

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
- Determinism: two runs of the unmodified game with the hooks give identical checkpoints over the front
  end (frames 0–450, every run so far), and once over frames 0–3,300 into the opening cutscene. After the
  new-game load the frame count depends on load time, so `compare` checks frames ≤ 450 by default.

## Open

- **Adapter thunks for `equiv-conv`** functions (31 in `equivalent/`): an entry thunk moving register
  arguments to where our compile expects them, and call thunks for callees.
- **The new-game load.** After it, the main loop sometimes runs thousands of `GameClock::Update`s per
  second, so replays keyed on frames lose sync. The loading screen's START check (or the loop that
  ticks the clock there) needs a deterministic hook before gameplay scenarios can be compared.
- `--wide` page masks were taken at frame 420 only; a check of the masked hash over a longer run was cut
  short by the monitor issue.
- Player position/health/camera, entity counts and mission flags in the checkpoint (need their addresses).
- `tools/hybrid_test.py` scenario suite and JSON report beyond `determinism`/`compare`; snapshot capture and
  `equiv.py --inputs-from` (task 10 deliverables 2, 4).
