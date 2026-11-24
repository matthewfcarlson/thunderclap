# The wasm32 port build (wasm1, D188)

A WebAssembly build of the whole tree, linked **by address**, in parallel with the 64-bit native builds. wasm32 has
4-byte pointers like the Xbox, so the game's own 32-bit layouts hold as they are: fields at 32-bit offsets, pointers
kept in ints and records sized by 32-bit pads mean on wasm32 what they meant on the console. The design follows the
owner's sibling project (fusion-frenzy-decomp `docs/port.md`); tools/wasm_ir.py is adapted from its port tool.

```sh
PY=build/venv/bin/python
$PY tools/wasm_port.py compile [--jobs 2] [--only TU ...]   # tree TUs -> build/wasm/obj/*.o (IR cached by content)
$PY tools/wasm_port.py link                                 # glue + host + emcc + Asyncify -> build/wasm/hulk.wasm
$PY tools/wasm_port.py report                               # the host's work list (unbound entries, named stubs)
$PY tools/wasm_port.py aot [--jobs 2]                       # wasm2c + clang -O2 -> build/wasm/hulk-aot (~1.5 min)
node src/platform/wasm/run/node.mjs build/wasm/hulk.wasm isos/extracted/default.xbe
build/wasm/hulk-aot isos/extracted/default.xbe
```

Needs Homebrew LLVM (`HULK_LLVM_BIN`, default `/opt/homebrew/opt/llvm/bin`), Emscripten (`emcc`; its Binaryen
`wasm-opt`, or `HULK_WASM_OPT_BIN`) and, for `aot`, wabt's `wasm2c` (`brew install wabt`; `HULK_WASM2C`).

**Inputs.** A clang_probe snapshot of the tree (`HULK_WASM_SNAP`, default `build/wasm/cp/snap`: the output of
`tools/tree_tu.py materialize` copied by `tools/clang_probe.py --snapshot`; manifest.json and report.json give each
TU's blocks and their pinned symbols) and the Wine build's binding map of the same tree (`HULK_WASM_BINDINGS`,
default `build/wasm/maps/bindings.json`: which XBE address each name the tree references means). Nothing in the tree
changes for the build; the outputs stay in `build/wasm/` (a module built from the game is derived content: never
committed). `tools/wasm_inputs.py` makes both at one commit: `submit --name ME` runs a queue job on HEAD (materialize,
the map from `wine_link.py --no-inventory --no-link`, the snapshot; about 11 minutes on mac2) and `fetch ID` unpacks
it into `build/wasm-inputs/<commit>/` and prints the two exports; `local --rev REV` does the same from a `git archive`
workspace here (slow on 2 local jobs). Recompile every TU after a change of inputs.

## How a TU is built

1. **Front end for the MS ABI**: clang for `i686-pc-windows-msvc` with the Wine build's `msvc` flags
   (`compat/native.h`, `-fms-compatibility-version=13.10`, no wchar keyword, `-ffp-eval-method=double
   -ffp-contract=off`, `-fcheck-new`, `-fno-exceptions`, RTTI on) to LLVM IR. The whole tree's front end takes about a
   minute on two processes.
2. **Which definition is which block**: the block's pinned symbol (report.json), else the map's definition name, else
   the same name with a float result spelled double (`hulk_freg`: `M` -> `N`), else the block's tree name matched
   against the undecorated definitions. Blocks that share one pinned symbol (identical code: template instances)
   get a forwarder. A scalar deleting destructor clang didn't emit (it emits one only with its vftable) is written in
   IR. A static-initializer block (`_$E1`) is the TU's own initializer (`_GLOBAL__sub_I_`), as in the native start-up
   table. 27,485 of 27,488 blocks are found; the three left are label stubs in dynamic_initializers.cpp.
3. **Bind and retarget** (`bind_tu()`):
   - each block's function becomes `ff_<addr>`, with a generic entry `ffg_<addr>(ecx, edx, stack, ret)` that takes the
     arguments where x86 had them; other definitions keep their linkage (linkonce ones become internal), and COMDAT
     data (vftables of stand-in classes, selectany data) becomes the TU's own copy;
   - names bound to an XBE address become that address (`inttoptr`): the host loads the XBE's sections into linear
     memory at their original addresses, so vftables, RTTI descriptors and every table are the original's bytes;
   - a direct call goes to `ff_<addr>` when its declared type is the definition's (as wasm types: `ptr` and `i32`
     are one), otherwise through a **packer** that lays the arguments out as x86 would and calls the callee's generic
     entry, so a declaration that disagrees with its definition (an `int` result for `void`, a float result read as
     double, fewer arguments) keeps its x86 meaning instead of trapping. Library functions (CRT, XAPI, D3D,
     DirectSound, XInput, Bink: code in the XBE the tree doesn't define) are always called through their generic
     entry, which the host defines;
   - a function used as a value is its original address (a local one with none gets a synthetic address,
     `0xF0000000 + (TU index << 14) + n`); every indirect call goes through `ff_dispatch(addr, ...)`, a hash table lookup
     over the generic entries;
   - `inalloca` (MS i686's by-value objects with a copy constructor or destructor) becomes an ordinary pointer to the
     caller's argument block: both sides are compiled here.
4. **Link** (`emcc`): `glue.c` holds the dispatch table, the `jmp` thunks resolved from the XBE's bytes, and a trapping
   stub per generic entry nothing defines; names nothing defines get trapping stubs of their declared type.
   Emscripten's static data starts at 1 GB (`GLOBAL_BASE`), so the image (0x10000..0x589860), the game stack
   (0xE00000..0xF00000), the sim block (0xF00000) and the game arena (16 MB..1 GB) are free for the game. A block that
   is a this-adjustor thunk (`sub ecx, n; jmp target`, a pin `@@W4AE...`: its source is a stand-in that makes cl emit
   the thunk) gets its entry from the XBE's bytes instead: `this` moves by n and the call goes on to the target.

## The host (`src/platform/wasm/host/`)

Game state lives in linear memory only (D191): the XBE image, the arena and the sim block (`sim.h`). A snapshot is
those bytes, and the same inputs hash the same run to run.

- `boot.c`: loads the XBE's sections at their addresses, points the kernel import table at `0xE0000000 + ordinal`
  (`ff_dispatch_miss` routes those to `ff_kernel`), runs the C++ initializer table (`.CRT$XCA..XCZ`, 0x48ca90..0x48d4f4,
  game initializers only) and calls main (0x8ee30).
- `arena.c`: the game arena (first fit in address order, so addresses don't depend on host allocations).
- `main.c`: the entry and the failure paths (`ff_unbound`: the next host function to write).

- `crt.c` (C library by address; the printf family reads x86 stack slots), `xapi.c` (files on host paths with
  case-insensitive lookup, D: = `HULK_DATA_DIR`, T:/U:/Z: under `HULK_SAVE_DIR`; heaps on the arena; the virtual
  clock), `sched.c` (threads and fibers), `kernel.c` (kernel imports by ordinal), `rtti.c` (`__RTDynamicCast`,
  typeid, type_info), `input.c` (XInput from the sim block), `d3d_null.c` (Direct3D and XGraphics, drawing nothing),
  `dsound_null.c` (DirectSound, silent, buffers playing on the clock), `bink_null.c` (BinkOpen fails), `frame.c`
  (the end of a frame), `missing.c` (game functions the tree has no block for yet).

A host function is `FFG(addr) { ... }` (`hulk_host.h`: `ARG(i)` is the i-th stack slot, `RET`/`RETF` the result).
`HULK_TRACE=1` prints every host function the game calls, `=2` also every call through `ff_dispatch`;
`HULK_FRAMES=N` ends the run after N frames, `HULK_REPORT=N` prints the frame rate every N, `HULK_THREADS=1` lists the
threads at the end, `HULK_STACK_AT=N` stops with a stack at frame N, `HULK_FILE_TRACE=1` lists file opens,
`HULK_INPUT="3000-3010:10,400-405:0/1,..."` holds pad 0's buttons over frame ranges (wButtons, hex; after a `/` the
analog buttons held down, a hex mask: 1 A, 2 B, 4 X, 8 Y, 10 black, 20 white, 40/80 the triggers), `HULK_GS=1`
prints the game-flow state's changes (GS_FRONTEND, GS_GAME, ...), `HULK_SNAPTEST=1` times a snapshot and restore of
the state at the end, `HULK_ROLLTEST=A:B` copies the state at the end of frame A, puts it back at the end of frame B
and checks that the run reaches B again with the same game hash, the same module-globals hash and (with a renderer)
the same front-end hash (exit 0 "identical", else 3; the lines give the snapshot's size and the restore's cost;
`HULK_ROLLTEST_DUMP=PREFIX` writes the game state at B before (PREFIX.1) and after (PREFIX.2)). With it set, every
frame's end suspends and resumes the running fiber (`ff_frame_checkpoint`), so the driver has every fiber suspended
there: the app's gameplay with a renderer never waits, and would give no fiber switch to snapshot at.

The snapshot (sched.c `state_copy`) is the image's data, the main stack and the sim block, the arena up to its top,
and two data sections of the module (wroll1, D227): `hulk_game_state`, the tree's own mutable globals
(`wasm_port.py` GAME_STATE_SECTION: function-local statics and their guards and the stand-in globals that have no
XBE address, ~73; not RTTI type descriptors, whose spare word caches a name the C library allocates), and, with a
renderer, `hulk_pddi_state` (the front end's, below). Both are hashed apart from the game hash (`ff_module_hash`,
`ff_gfx_hash`): their words include pointers into module data (vftables), which move with the build, and the game
hash stays comparable between builds. A restore that left `hulk_game_state` re-simulated a different game across
PRESSSTART -> GAME (CSPManager 0x001e4760's local static registered its atexit entry a second time). Host code
that keeps game-facing state in its own statics (what the game reads back, or game objects it holds: fe_options.c's
frame-rate setting, its NamedValueInt objects and its handler) declares them in `hulk_game_state` too
(`__attribute__((section("hulk_game_state")))`); host-only state (caches, host times, file handles) stays out.

Without a replay (a free run: no `HULK_INPUT_SOURCE`) the game keeps running: it sits in the front end
(GS_FRONTEND) without input, and `HULK_INPUT="300-305:10,400-405:0/1,1000-1005:0/1"` (START, then A) takes it through
GS_PREGAME and GS_PRESSSTART into GS_GAME (frame ~650-1,600) and on past 60,000 frames. Two host rules make that
work, both off in a replay (whose lockstep I/O and virtual clock do the same jobs): the main thread's drive pump
(0x00272df0) is a time slice (`ff_poll`), so a loader spinning on a request lets the drive thread run; and BinkWait,
when a movie frame isn't due yet, moves the clock on to it (the game spins on BinkWait, and the clock moves only a
microsecond a QueryPerformanceCounter read: the intro movie took ~30,000 polls a frame).

## The standalone module

`hulk.wasm` is a standalone module (`-sSTANDALONE_WASM`, no Emscripten JS). Its imports are WASI's stdio, arguments,
environment, clock and exit (what the C library calls) and nine `hulk` functions for host files by path
(`host/hulk_io.h`). Two runners define them: `run/node.mjs` (node's WASI) and `run/native.c`, linked with wasm2c's C
of the module and wabt's runtime into `hulk-aot` (`wasm_port.py aot`: wasm2c splits the module in 32 C files, clang
-O2, objects cached by content). Both hand the module only the `HULK_*` variables, sorted, and the same argv, so the
C library's heap holds the same bytes under both: host pointers can reach the game's stacks as dead bytes, which the
state hash covers. The same build gives the same state hash under node and compiled (20,000 frames with START
presses). Host work whose bytes depend on the host (the frame-rate report, the end-of-run lines) runs on a host stack
outside the state (`ff_on_host_stack`), so reporting doesn't change the hash.

## Replays (play3 against the reference checkpoints)

```sh
build/venv/bin/python tools/native_replay.py run --exe build/wasm/hulk-aot --out build/ME/run --frames 60000 \
    -- $PWD/isos/extracted/default.xbe          # then tools/native_replay.py check RUN.ckref --frames N
```

`src/platform/wasm/host/replay.cpp` is the wasm host's replay driver: it compiles the SDL layer's recording reader
(`src/platform/sdl/replay/hulk_replay.cpp`, behind a few-line SDL shim, `host/shim/SDL3/SDL.h`) and the semantic probe
(`src/platform/sdl/ckpt/ckpt_probe.cpp`, at the original's 32-bit offsets: wasm32 needs no native layout) and writes
the trace lines and the `.ckref` records through the host file imports. The hooks are the native link's table,
`src/platform/sdl/host/native_hooks.h`, placed by `wasm_port.py` (`wasm_hooks()`) by renaming at bind time, never by
editing a replay-pin function's source: an `entry` row renames the definition to `ffo_<addr>` (generic entry
`ffgo_<addr>`) and makes `ff_<addr>` a packer that calls the host's `ffh_<hook>` (a generic entry's shape, so a
caller's declaration needn't match); the defining TU's own direct calls stay on the definition, as natively. A `site`
row sends that block's calls of the callee to the hook through a packer; a `data` row makes the item the host's
variable. `HULK_WASM_DEBUG_HOOKS="entry:0xADDR:0:name,site:0xCALLER:0xCALLEE:name"` with `HULK_WASM_HOST_EXTRA=FILE.c`
adds debugging hooks (`ffh_name`) to a local build. `HULK_TRACE=2 HULK_WATCH=ADDR[:FROM-TO]` prints the indirect
calls around each change of a word (in update frames FROM..TO).

What the replay needs from the host, as the Wine build has it: the recording's virtual clock (vclock/vdate: QPC,
GetLocalTime, GameClock::Update's time); the pad from the recording, with the pad-init reads not counted as polls;
lockstep I/O (`host/io_lockstep.c`, the Wine build's `HULK_SYNCIO=5`: the drive thread steps only on the main
thread's turns); DirectSound buffers advancing exactly as the Wine mixer's voices do under `HULK_AUDIO_CLOCK=frame`
(800 frames of 48 kHz a `DirectSoundDoWork`); and a Bink that opens (header from the game's own I/O callbacks, time on
the virtual clock, no picture): with BinkOpen failing, the new game's movie was never opened and the clock reset a
frame early (play3 frame 440).

Link-time fixes on the way: clang's implicit `??1X` of a stand-in class goes to the original's deleting destructor
with flags 0 (found from RTTI: the vftable whose locator names X, the slot that tests `flags & 1`); clang's sized
frees (`??3@YAXPAXI@Z`) go to the game's unsized ones; clang's RTTI type descriptors are bound to the game's by the
Wine link's rules (wrapper namespaces dropped, an `_<hex>` suffix dropped, a unique leaf name), so a cast to a
stand-in name (`FrameControllerLoader_297680`) finds the game's class.

**A void whose callers read eax**: x86 leaves eax from a void function's last call, and some callers read it: the
tree's `ParamBranch<T>::vfunc_6` (147 blocks in 43 fight/hulkfight TUs) is read by its callers as `fn`'s result
(0x235290); without it the new game's fight data stops parsing at frame ~420. The port builds return such results in
source (HULK_PORT_ABI, include/compat/ptr.h): `hulk_eaxptr vfunc_6(void* p) { return fn(p); }` (844e08e50), and five
more voids play3 needs (wasm4): 0x00292a50 pure3d::Camera::vfunc_18 (slot 16's char), 0x001d6be0
CSPHulkPropInstance::vfunc_15 (an int), 0x00048650 CAxisCondition::vfunc_8 (vfunc_9's bool; gen's
`CControllerCondition_ret8`), 0x00048440 CControllerCondition::vfunc_7 (a `jmp` to slot 8: its argument and bool) and
0x00023e60 (0x00088fb0's unsigned). Each is a typedef that is void on the 32-bit builds, so their code is unchanged.
The binding map is the Wine build's, whose name says void, so `wasm_port.py` binds such a block by its name with the
void (`X`) spelled `H`, `I`, `PAX`, `_N`, `D` or `E`. They were found by bisecting over every void block with a
debugging build that hands a void's callers the last packed call's eax (wasm3's EAX_PASS stopgap, which did that for
every void and is gone): first divergence 439 without them, 446 with them.

## Threads and fibers

Every thread runs on a fiber; one runs at a time and switches only where the game waits
for an object that isn't signaled, sleeps, exits, switches fibers itself, or polls the clock (a time slice every 32
`QueryPerformanceCounter` calls, as preemption would: the content loader's fiber is run by the main loop while the
drive thread serves its reads). The next thread is the first runnable one after the current in handle order; when
none is runnable the virtual clock jumps to the earliest deadline. A suspended fiber's state is its C stack and its
Asyncify buffer, both in the arena (the main thread's stack is at 0xE00000), so it is game state like the rest.

The switching is Binaryen's Asyncify driven from C (`sched.c`), not Emscripten's fibers: `wasm_port.py link` runs
`wasm-opt --asyncify` on the linked module with the driver loop `ff_sched_loop` on the removelist and no import
allowed to unwind; the `asyncify.*` imports (start/stop unwind/rewind) are the pass's own functions. `fiber_swap`
saves the stack pointer and unwinds into the driver, which rewinds the next fiber (its saved stack pointer first).
Instrumented, the module grows from 10.8 to 15.3 MB (Emscripten's Asyncify build was 29.9 MB).

**setjmp/longjmp** (Lua's protected calls; libpng's and the physics' error exits) use the same machinery: `_setjmp3`
unwinds its fiber and keeps a copy of the Asyncify data and the stack pointer (a continuation, in the arena, keyed by
the jmp_buf's address, 32 kept), then rewinds and returns 0; `longjmp` unwinds, puts the continuation's data back and
rewinds into that `_setjmp3`, which returns the value. Memory keeps what it holds at the longjmp; wasm locals come back
as they were at the setjmp, as registers do on x86. A setjmp costs one unwind and rewind of its fiber (start-up and the
first 20,000 frames: 1,012 setjmps, ~740 bytes of Asyncify data each). `HULK_SJTEST=1` runs a longjmp through 20
frames before the game starts.

## Variadic functions

The game's variadic functions walk their arguments x86-style, from the address of the last named parameter
(`(char*)&fmt + 4`; the native builds take the `HULK_PTR64` branch instead). On wasm that address is the function's
local copy, so `fix_va_frames()` rebases such addresses onto the variadic area (`llvm.va_start`), and every variadic
call in game code passes its variadic arguments as x86 words (a double as two, a struct by value as its words), so
the area has the x86 layout. The host's printf family reads a `va_list` as x86 slots too.

## Bindings beyond the name table

- `ambiguous_by_function` (one name meaning another callee in some callers: two sources merged into one TU): in
  those callers the name becomes `name$addr`, bound to that address.
- `local_data` (data a TU defines that is the original's: a static object other game code reads at its address) is
  bound to its XBE address.
- RTTI names: a clang type descriptor of a class the tree wraps in `namespace fn_<hex>` keeps the wrapper in its
  name; `rtti.c` compares names without it (as the native host does).

## The macOS app (wapp1, D190: design)

The app is the wasm2c build with real hosts for graphics, input and audio on the native side of the module, and the
headless build kept as it is. Everything the game owns stays in linear memory at its 32-bit layout; what the native
side holds (GPU objects, the window, the audio device) is derived from linear memory and can be made again.

- **Graphics: the pddi front end inside the module, the sink outside.** The Wine and native `--gfx` links replace
  pure3d's d3d layer with the pddi front end (src/platform/sdl/pddi/, 23 classes the game calls through MS vftable
  slots) at the one entry point d3dCreateDevice 0x0031ba60. The module does the same: `tools/wasm_gfx.py` compiles
  the front-end units through wasm_port's i686 -> wasm32 path (MS ABI, the game's 32-bit offsets: `PDDI_SPE`'s 32-bit
  side under `HULK_PDDI_WASM`; their `GameBase::FUN_<addr>` calls bound by address; their vftable slots get dispatch
  entries like any local function used as a value) with the native builds' bridge sink (`HULK_PDDI_NATIVE`'s
  BridgeSink): every draw-sink call (bgfx_bridge.h) is a `hulk` import `gfx_*`. The runner implements them with the
  bridge's host half and bgfx_sink.cpp (Metal) unchanged, converting each packet's wasm32 pointers to host pointers
  (draw_sink.h's structs are fixed-width; the module sends its own `offsetof` table at start-up and the runner refuses
  a layout that differs). bgfx's transient vertices are staged in the module and copied over at the draw.
  The window, the event pump and the swap chain are the runner's (SDL3 with video, platform_events.cpp).
- **One module, two device paths.** An `entry` hook on 0x0031ba60 (wasm_port, `HULK_WASM_GFX=1` builds only) asks the
  runner: with a renderer (`HULK_GFX_RENDERER`, Metal by default in the app) the pddi front end makes the device; with
  `null` the game's own d3d layer runs on d3d_null.c exactly as in the headless build, so the app run headless gives
  the headless build's play3 records. The gfx-only site hook 0x001c1a40 (`hulk_cast_self`, native_hooks.h) takes the
  same switch. The headless module (`HULK_WASM_GFX` unset) is unchanged and needs no new imports.
- **Game state.** The front end's objects and its C allocations (texture levels, prim buffers' copies; `wasm_gfx.py`
  C_RENAME) are in the arena, so a snapshot carries them with the game objects that point at them and they never
  point into the module's own malloc heap (whose layout follows host history). Its mutable statics (73, less the frame
  pacer's host times) are in the data section `hulk_pddi_state`, which the snapshot carries.
- **Rollback with graphics** (wroll1, D225). The front end names every sink object by an id gfx.c gives out (a vid:
  textures, vertex and index buffers, targets and their frame buffers, queries; 1..3 are the sink's own frame copy and
  front buffer), never the runner's ids, so game state never holds a value that follows the runner's history. gfx.c's
  table of vids (`vt`, in `hulk_pddi_state`) keeps what each stands for: a texture's description and pointers to its
  levels' CPU copies, a prim buffer's packed copy, a target's size; every change takes a stamp from a counter in the
  same section. A mirror outside the state (`hs`) holds the kind and stamp the runner last got for each vid. After a
  restore (`ff_gfx_restored`) the vids whose stamps differ (made, changed or dropped since the snapshot) are dropped
  in the runner and made again from the restored copies (a prim buffer's vertices converted again by
  `hulk_pddi_convert_packed`, bgfx_draw.cpp under HULK_PDDI_WASM); the rest stay. Stamps rise along a run and a
  restore returns to an earlier point of it, so equal stamps mean equal contents. The runner (app.cpp) maps each vid
  to its sink's ids and translates the ids in packets, passes, copies and fx draws; the sink cannot destroy a query,
  so the queries a restore orphans are kept for the next ones. Cost: 0.05-0.4 ms a restore (9-561 objects), next to
  2-3 ms for the ~35 MB of state. The front end's statics outside the section are the pacer's host times. Open:
  occlusion results arrive when the GPU has them (none was read in 8,000 frames of free play); a snapshot taken
  between frames' draws would mix two frames' draws in one present (rolltest snapshots at frame ends).
- **Input.** The runner polls SDL once a presented frame (the SDL layer's gamepad source, src/platform/sdl/input/, and
  a keyboard map) and the module copies the pads into the sim block (`pads`, `pads_in`), where XInput reads them: a
  frame's input is game state, so it snapshots and could be recorded. A replay keeps the recording's pads.
- **Audio (D222: one deterministic model).** dsound_null.c is the only model of the voices the game reads (status,
  positions, a one-shot's end, a stream buffer's consumption): its state is in the arena and the sim block, so a
  snapshot carries it, and it is a function of the game's calls and the virtual clock alone. The voices' output frames
  (48 kHz) pass on `SIM->ds_clock`, fixed at DirectSoundCreate: in replays 800 a DirectSoundDoWork (the Wine build's
  frame clock, which the recordings were checked with; the game calls DoWork about three times a frame, so this runs
  ~1.5x fast), in every other run the virtual clock's 48 kHz (`SIM->ds_frames`: at every DirectSound call the voices
  move on to `SIM->clock`, as the console's APU plays in real time); `HULK_DS_CLOCK=work|time` overrides. In the app's
  free play the runner's mixer (src/platform/sdl/audio/: Xbox ADPCM, mix bins, the I3DL2 reverb) only listens: weak
  hooks `ff_audio_obs` (each call, once done) and `ff_audio_tick` (each advance, before it) drive a mirror of the voices
  with the same cursor arithmetic (`HULK_CLOCK_MANUAL`), `aud_tick` renders exactly the frames the model played, and
  they go to the playback device through a queue: its fill steers the device stream's rate within +-0.5%, and past
  300 ms (a jump of the virtual clock: start-up movies, loads) frames are dropped until the queue is down to ~67 ms.
  Nothing flows back. After a restore (`ff_audio_restored`) the mirror is made again from the model.
  `HULK_AUDIO_CHECK=1` compares the mirror with the model before every advance; `HULK_AUDIO_LOG=1` logs game vs real
  seconds, the queue, the rate and drops; `HULK_AUDIO=1` turns the mixer on without a renderer (`null`).
- **Pacing.** The presents are paced at the game's rate (sdl_platform.cpp's `HULK_FPS_CAP`: the SwapBuffers vblank
  flag 0x005554a0, 60 Hz in press-start and movies, 30 in gameplay), off in replays and headless runs. In free play a
  present moves the virtual clock by the fields the original waited for (two with the flag clear), so game time keeps
  to real time.
- **Build.** `tools/wasm_app.py sdl` (SDL3 with video, build/third_party/out/sdl-video), `wasm_app.py build`
  (`HULK_WASM_GFX=1` in its own `HULK_WASM_DIR`, default build/wasm-app: `wasm_port.py compile`, `wasm_gfx.py
  compile`, `wasm_port.py link`, `aot --app`), `wasm_app.py bundle` (`--out build/<lane>/Hulk.app`; build/Hulk.app is the user's; not signed or notarised;
  nothing built from the game is published or committed). Saves go to ~/Library/Application Support/HulkUD/save;
  where the game is: "First launch" below. Input: SDL3 gamepads and the keyboard as pad 0, merged when a gamepad is
  there (docs/native-play.md's map; `HULK_KEY_SCRIPT` holds keys for unattended runs). On macOS SDL's gamepad
  subsystem lives on its own thread (wpad1, run/app/input.cpp): HIDAPI's init creates every HID device and blocks
  forever in IOServiceOpen while gamecontrollerd is deadlocked (seen with Chrome's gamepad polling), and SDL holds its
  joystick lock meanwhile, which the main thread's event pump, SDL_Quit and GameController's connect notifications
  (SDL's MFi observers run on the main thread) all take. The pad thread first makes the same IOHIDManager call
  outside SDL (the probe), so a stall holds nothing of SDL's; the main thread reads the pad thread's snapshot, never
  calls an SDL joystick function (`SDL_HINT_AUTO_UPDATE_JOYSTICKS=0`), keeps the keyboard as pad 0, and after 3 s
  logs, titles the window "controllers unavailable" and shows a banner at the top of the window (wpol1: the runner's
  overlay image, drawn by Core Text in input.cpp; movie.c hands it the overlay slot when no skip ring is up; never
  module memory, never a modal dialog) naming the fix (quit apps that use gamepads, such as Chrome, or restart
  gamecontrollerd); the banner goes when the init completes or the player presses Delete (`Backspace` in
  `HULK_KEY_SCRIPT`); a pad attaches when the probe returns. Quitting skips
  `SDL_Quit` only while the thread is inside SDL. `HULK_PAD_INIT_DELAY=S` (tests) sleeps S seconds in the probe.
  Android keeps the main-thread path.
- **First launch** (wui1; run/app/start.cpp). The game is the player's own extracted disc (default.xbe and the .rcf
  archives). In order: the command line (`hulk-app <disc>/default.xbe` or `HULK_XBE`, with `HULK_DATA_DIR`, default
  the XBE's folder; `HULK_DATA_DIR` alone means its default.xbe); the remembered choice (`<app dir>/game.txt`, one
  line: the disc folder); `<app dir>/disc` (a disc copied there by hand); else a chooser: an alert ("Hulk needs your
  own copy of the game: choose the extracted disc folder or its default.xbe"; Choose Folder... / Choose
  default.xbe... / Quit) and the system's open panel (SDL3's file dialog, NSOpenPanel; `wasm_app.py sdl` builds SDL
  with `SDL_DIALOG=ON`). The choice is checked against the player's own files at run time: an XBE header whose
  certificate carries the game's title ID (0x56550039), and every archive the disc's rcfs.txt lists; a bad choice
  says why (no default.xbe, another game, missing archives) and asks again. A good one is remembered, so later
  launches start directly. To choose again: hold Option while the app starts, or `open Hulk.app --args
  --choose-game` (`hulk-app --choose-game`). Since wpkg1 the disc may also be an Xbox disc image (.iso) or a disc
  pack (.hulkdisc), and a game bundled in the app comes first: "Disc sources" below.
  `<app dir>` is `HULK_APP_DIR`, default ~/Library/Application Support/HulkUD (tests use their own). Runs that must not
  prompt never show the chooser: anything given on the command line, and with no game found `HULK_NO_UI=1` or a scripted
  run (`HULK_INPUT`, `HULK_KEY_SCRIPT`, `HULK_INPUT_SOURCE`, `HULK_CKPT`) exits 2 with the reason.
- **Saves** (whang1): only an interactive launch (none of the variables below) saves in the player's folder,
  `<app dir>/save`, also when the game is given on the command line (before, such a launch skipped it and saved in
  `build/wasm/save` under the working directory: nowhere writable under `open`, and the game then waits at a mission's
  summary for a save that never succeeds). A scripted, automated or test run (`HULK_INPUT`, `HULK_KEY_SCRIPT`,
  `HULK_INPUT_SOURCE` (replays, `native_replay.py`), `HULK_CKPT`, `HULK_ROLLTEST`, `HULK_NO_UI`) never defaults to it:
  it saves in `HULK_SAVE_DIR`, else the host's run-local `build/wasm/save` under its working directory, and a
  `HULK_SAVE_DIR` inside ~/Library/Application Support/HulkUD exits 2 unless the test set `HULK_APP_DIR` (its own
  app folder). An explicit `HULK_SAVE_DIR` wins for interactive launches too. The app prints where it saves
  (`hulk-app: saves in ...`), and the host warns once when the save folder can't be made.
- **Saves** (whang1): only an interactive launch (none of the variables below) saves in the player's folder,
  `<app dir>/save`, also when the game is given on the command line (before, such a launch skipped it and saved in
  `build/wasm/save` under the working directory: nowhere writable under `open`, and the game then waits at a mission's
  summary for a save that never succeeds). A scripted, automated or test run (`HULK_INPUT`, `HULK_KEY_SCRIPT`,
  `HULK_INPUT_SOURCE` (replays, `native_replay.py`), `HULK_CKPT`, `HULK_ROLLTEST`, `HULK_NO_UI`) never defaults to it:
  it saves in `HULK_SAVE_DIR`, else the host's run-local `build/wasm/save` under its working directory, and a
  `HULK_SAVE_DIR` inside ~/Library/Application Support/HulkUD exits 2 unless the test set `HULK_APP_DIR` (its own
  app folder). An explicit `HULK_SAVE_DIR` wins for interactive launches too. The app prints where it saves
  (`hulk-app: saves in ...`), and the host warns once when the save folder can't be made.
- **Building from a clean state** (wapp2): inputs at the commit being built (`tools/wasm_inputs.py submit`, then
  `fetch ID`), then `HULK_WASM_SNAP=.../snap HULK_WASM_BINDINGS=.../bindings.json tools/wasm_app.py build --jobs 2`
  (every TU on a first build: about 8 minutes on 2 local jobs) and `wasm_app.py bundle`. The build directory records
  the inputs its tree objects come from (app-inputs.json: the snapshot, the binding map, wasm_port.py / wasm_ir.py
  and the build knobs); a build whose inputs changed, or whose objects were copied in from another directory, compiles
  every TU again instead of linking stale objects. A failed `wasm_port.py link` exits nonzero and leaves no hulk.wasm.
  Host files (src/platform/wasm) come from the checkout the tools run in: build from a `git archive` workspace when
  the checkout carries other lanes' uncommitted host edits.
- **Callbacks across the module boundary.** A function the front end hands the module's C host code as a value (the
  resize handler of `hulk_platform_set_resize_handler`) is its synthetic dispatch address, not a wasm table index:
  call it with `ff_call`, never through a C function pointer (wapp2: the first window resize trapped with "Invalid
  call_indirect").

### Build the app on the queue (wbuild1)

Build and test on a queue host instead of this laptop: `tools/wasm_build_job.py` (docs/compute.md "Wasm builds and
tests" has the details: sources, inputs, the host's toolchain and cache, timings).

```sh
J=build/venv/bin/python; W=tools/wasm_build_job.py
id=$($J $W submit --name ME --target app --bundle --workspace build/ME/ws --test play3:2000)   # or --target aot
$J $W wait $id && $J $W fetch $id --dest build/ME/app     # hulk-app, Hulk.app, tests/play3-2000/cand/...
id=$($J $W test --name ME --exe CANDIDATE_JOB --control CONTROL_JOB --test play3:60000 --test rolltest:900:2500)
```

- The default build is HEAD's; ship host edits with `--workspace DIR` (a private workspace: its files that differ from
  HEAD), `--files` or `--dirty`. Tree edits need `--inputs make` (the job makes the wasm inputs from its own sources;
  otherwise it takes fetched `wasm_inputs.py` inputs of HEAD's tree).
- The host's build directory is per lineage (NAME-TARGET) and keeps wasm_port's front-end IR and app-inputs.json, so
  the second build of the same inputs relinks only (the hooked TUs for the app).
- `--test play3:N` replays play3 (the app with `HULK_GFX_RENDERER=null`) and checks against build/ckpt/play3.ckref;
  `rolltest:A:B` and `input:N[:EVERY]` are free runs with the START/A script (`--test-env HULK_INPUT=...`,
  `HULK_SETTINGS=...`). `--control` runs the same tests on a second executable on the same host and compares (play3:
  records against the control's, and the reference gate with the control's divergences allowed; input: game hashes
  frame by frame, which only agree between builds whose module data is laid out alike, e.g. two app builds).
- Metal: `--test-env HULK_GFX_RENDERER=metal --test-env HULK_GFX_HIDDEN=1` runs the app with Metal and a hidden
  window on mac2 and studio (over ssh); free play is paced, so such a run takes real time (30 frames/s).

### The build's id (wver1)

Every app and APK carries the short commit it was built from (7 hex digits; `+dirty` for a local build whose host files
or tools, src/platform/wasm, src/platform/sdl and tools/, have uncommitted changes; `+N` for a queue build with N
overlay files and deletions): `hulk-app: build 1a2b3c4` on stdout at start (logcat tag `hulk` on Android), the window
title "The Incredible Hulk: Ultimate Destruction (1a2b3c4)", the bundle's Info.plist (CFBundleShortVersionString
"0.1 (1a2b3c4)", CFBundleVersion "1a2b3c4": Finder's Get Info) and the APK's versionName ("0.2 (1a2b3c4)": Settings >
Apps, and the setup screen's last line). `tools/wasm_app.py build` takes HULK_BUILD_ID (wasm_build_run.py sets it from
the job's commit and overlay) or git, and writes it to `<dir>/aot/app-gen/hulk_build_id.h` (run/app/start.cpp) and
`<dir>/build-id.txt`; `bundle` and `wasm_android.py apk` read it back from the executable's `HULK_BUILD_ID=` tag, and
`wasm_android.py build` takes the module's (the hulk-app beside the hulk.wasm). Only the runner's objects depend on the
header: a new id recompiles them (about 20 files), never a game TU (app-inputs.json does not hold it). The id is
host-only: it never reaches module memory, so records and game hashes don't change with it.

### The frame-rate option (fps1, D224)

The user's decision D224: 60 fps is a menu toggle in the game's own options, 30 (the original) by default.
**Superseded in part by D228a (fps2, "Display rates by interpolation" below):** the simulation no longer takes one
field a present at 60; the item now sets the display rate only. The menu injection described here stands (wopt1
moves the item into Video Options).

- **Why only pacing changes.** The game is variable-step: every update takes the measured dt (GameClock, clamped at
  66,666 us), the physics update passes dt without a fixed sub-step, animation is time-based. 30 fps in gameplay comes
  only from d3dDisplay::SwapBuffers 0x31b190 waiting two vblanks while the flag 0x005554a0 is clear. The constants
  docs/subsystems.md §3 listed as per-frame are not: 1/30 in 0x18170 is a height ratio (the helicopter's tilt), in
  0xfee10 a per-golem phase step in a constructor, in 0x2b1df0 animation frames to seconds at the clip rate (30 per
  second of data); 1/60 in 0x38660 is degrees / 60 (sectors), and the controller / drive error callbacks step 1/60
  inside the disconnect pause loop. No tree source changes.
- **The item** (since wopt1: Options > Video Options > Frame Rate; "Settings and the remastered edition" below).
  fps1 put it in camera_options and named it "PortFrameRate"; it is now the `frame_rate` row of the settings table
  (30 / 60 / 120 / Display; fps2 owns what the values do, `hulk_wasm_frame_rate_apply`).
- **The setting** is `frame_rate` in `HULK_SAVE_DIR/port_settings.txt`, not in the game's save; port_settings.c calls
  `hulk_wasm_frame_rate_apply` (gfx.c) with it at load and at every change. Replays ignore the file and never write it.
- **Checks.** play3 to 60,000 on the app (`HULK_GFX_RENDERER=null`, the overlay and hooks active): the same checkpoint
  records as the app before the change (byte prefix). A scripted run (`HULK_INPUT` now takes the left stick: `FROM-TO:
  BUTTONS/ANALOG/LX/LY`; the deterministic audio model; the lane's local script build/fps1/scripts/timing.py) played
  at 30 and at 60 by the saved setting, the Hulk compared at equal game time: walking 10 s, walking sideways, attacks and jumps stay within 0.2 units over 47 s
  of game time (the camera within 0.6); jump apex and landing times are the same frame; the apex is 0.5 units higher at 60
  (smaller integration steps: +9% on a tap jump, +3% on a held one). Left-trigger moves differ by up to 9 units, less
  than the same plan at 30 shifted by one frame (37): input-timing sensitivity, not the rate. Presents hold 60.0 fps in
  gameplay with the setting (HULK_FPS_LOG). The virtual clocks drift 0.36 ms per second apart (more polls at 60).
- **Rollback and co-op.** The rate is part of a session's definition: peers must run the same one (each frame's dt
  depends on it), so a co-op session takes the host's at session start and the item must not change it mid-session
  (lock or hide it then). The value lives in the host (`fe_options.c`) and in the NamedValueInt objects in game memory;
  a snapshot restores the objects, not the host's copy, which is why it is per-session.

### Settings and the remastered edition (wopt1, D232 / D233)

The user's decisions: the port's additions are the "remastered edition", the wasm app is always that edition for now,
every remastered addition is a setting whose off state is the original's behaviour, and the settings live in two new
screens of the game's own Options, "Video Options" and "Gameplay Options" (D232). The remastered edition defaults to
most enhancements on; turning the edition off restores every faithful value (D233).

- **The table** (src/platform/wasm/gfx/port_settings.c, port_settings.h): one row per setting: its key in the settings
  file, its label, its screen, its kind (choice, on/off, or a slider shown as an ordered choice), its choices (values
  and their labels), its faithful value, its remastered default, whether it is remastered-only, and the function that
  applies it (called with the effective value at load and at every change). Values are ints, never choice indices.
  `hulk_setting(key)` is the effective value; `hulk_remastered()` the edition switch; `hulk_remastered_build()` says the
  build is the remastered edition (the app: 1). Adding a setting is one row plus its apply function: the menu item,
  its strings, its named int, its callback and the file entry follow from the row.
- **The edition switch** is the row `remastered` (Gameplay Options > Remastered Edition: On / Off). Off: every
  remastered-only setting takes its faithful value, its item shows that value and turns back to it when changed; the
  player's own values stay in the file and come back when the switch is turned on.
- **Defaults** (D233, when the file has no value): the edition on; Frame Rate 60 FPS (every display has it; 120 and
  Display are one selection away); Render Resolution Window (the window's own pixels); Aspect Ratio Window, HUD
  Frame Screen Edges, Draw Distance Far, Fog Reduced (wvid1, below), Texture Pack the first installed pack (wpack1).
  Faithful: Frame Rate 30, Render Resolution Original (640x480), Aspect Ratio 4:3, HUD Frame Centred, Draw Distance
  Original, Fog On, Texture Pack Off.
- **The file** is `HULK_SAVE_DIR/port_settings.txt` (`key=value` lines; fps1's `frame_rate=60` file reads as it is),
  next to the game's saves, written at every change. Runs that test or replay never read or write it and start from
  the faithful values: a recording, a `HULK_INPUT` run and `HULK_ROLLTEST` (`HULK_SETTINGS_FILE=1` makes a `HULK_INPUT`
  run use the file, to test it). `HULK_SETTINGS="key=value,..."` pins values in any run (never saved): a test that
  needs a setting states it.
- **The menus** (src/platform/wasm/gfx/fe_options.c). The misc.rcf overlay (fps1: patched copies of the player's own
  frontend\fe_real.txt, fe_run.txt and str_*.txt appended to the archive, located by anchors at run time; the
  repository holds only what is inserted and our own English strings) now adds, in both the front end (fe_real) and
  the pause menu (fe_run): one `AddNamedValueInt "Port_<screen>_<k>" 0 "Port_<screen>_<k>_Changed"` per item place
  (after CameraInvertY's; wmenu1: places, not settings, see "Scrolling" below), two `AddTextButton` entries at the end of the "options" screen (front end: FEmain_left_item5/6
  with menu_item_5/6; pause menu: FEpause_text4/5 with the bars and slide_down4/5) going to the screens
  "port_video_options" and "port_gameplay_options", and those screens (inserted before "camera_options", built like
  camera_options: a title and one `AddTextSelector` per place, FEsubMenu_text<k> / FEpause_text<k>, parsed showing
  the setting of row k: `TextSelection` of the choices' string ids TBS_PORT_<KEY>_<n>, `NamedValue
  "Port_<screen>_<k>"`, name "port_<screen>_<k>"). fps1's three entry hooks serve every place: 0x000df9e0 (the
  int-callback lookup) returns a host handler per place (a two-word object: a vftable whose call slot is
  `ff_host_method(on_change)`, and the place), 0x000f8e70 (NamedValueInt's Create) starts each named int at the
  choice index of the setting its place shows and remembers the latest parse's object, 0x000b5ad0 (the selectors'
  sync at front-end set-up and pause) shows each place's setting (the selector's choice written and the selector
  refreshed). The pause menu's items crashed the headless app (HULK_GFX_RENDERER=null) when one changed, or on pausing
  with the remastered defaults, since wopt1: 0x00329da0's isolated TU defined the D3D stage words DAT_0039db50 /
  DAT_0039db58 as `int[32]` and wrote `[stage * 32]`, so stages 1..3 overran them into the next globals of the module's
  `hulk_game_state` section, there the handlers' vftable (wmenu1: the arrays now hold four stages). The named
  ints and handlers are in `hulk_game_state`; the settings are host state. `HULK_FE_OPTIONS_LOG=1` logs the items and
  changes, `HULK_FE_OPTIONS_DUMP=DIR` writes the patched text files to a local directory (game text: never commit).
  Only one screen kind of item exists (a text selector over a named int); a real slider (AddHSlider) binds a
  NamedValueFloat, whose create and callback lookup would need two more hooks.

### Render resolution (wopt1, D232)

Video Options > Render Resolution: Original (640x480), 2x, 3x, 4x, Window, 720p, 1080p, 1440p, 4K (values 1..4: a
multiple of the frame; 0: the largest rectangle of the frame's aspect in the window, in pixels, followed on resize;
720 / 1080 / 1440 / 2160: that height at the frame's 4:3, 960x720 ...; at most 8192 a side).

- **Output only, in the runner.** The game and the pddi front end keep the frame they asked for (640x480): every
  size they read is that one, so nothing of the game's state can follow the setting. app.cpp (`rrSize`, `rrRemake`)
  makes the scene target, the sink's frame-buffer copy and front buffer, and every copy target of the frame's size at
  the render size; a pass into one of them has its viewport scaled (clip space and the game's 2D projections need
  nothing else); an occlusion query's pixel count is scaled back to the frame's; the present samples 1:1 when the
  render size is the frame's rectangle in the window. The effects' smaller render targets keep their sizes (their
  passes are in their own pixels). A change is applied between frames (after the sink's frame): the targets are made
  again and the module's ids for the sink's own targets (vids 1..3) re-pointed. No bgfx_sink.cpp or pddi change (D194:
  the Wine image's objects are untouched). The module sends the value through the import `gfx_render_res`.
- **Checks.** The same 9,000-frame `HULK_INPUT` run (start-up, menus, the first mission's start) at Original and at
  3x (1920x1440 window): byte-identical checkpoint records (`HULK_CKREF=1`). The game hash cannot show it with Metal
  (two runs at the same setting differ: the front end's pointers into the module's malloc heap, waud1). Screenshots
  at 1920x1440 show the frame, HUD and text at full resolution.
- **Aspect.** At an aspect other than 4:3 (the next section) the render size keeps the game's 480 lines per multiple
  and takes the aspect's width (Original at 16:9: 853x480; 720p: 1280x720), and Window fills the window's rectangle of
  that aspect: the module's present rectangle (bgfx_display.cpp presentRect) and the runner's use the same formula.

### Aspect ratio, HUD frame, draw distance and fog (wvid1, D234 / D235)

Video Options has four more rows (port_settings.c): Aspect Ratio, HUD Frame, Draw Distance and Fog. Faithful values:
4:3, Centred, Original, On; remastered defaults: Window, Screen Edges, Far, Reduced.

- **Aspect Ratio: 4:3 (Original) / 16:9 / 16:10 / 21:9 / Window** (`aspect=43|169|1610|219|0`; 21:9 is 64:27; Window
  is the window's own shape, clamped to 4:3 .. 64:27). The game's own widescreen, as an Xbox in a 16:9 video mode
  plays it: the frame stays 640x480 (the 480p widescreen modes of the mode table 0x4d3508 are anamorphic 640x480 too)
  and the display reports the aspect (`bgfxDisplay::vfunc_16`, d3dDisplay::GetAspectRatio 0x31b500's slot, under
  `HULK_PDDI_WASM`: gfx.c `hulk_wasm_display_aspect`). The cameras widen horizontally through ComputeRealFOV 0x9f790
  (Hor+: the vertical FOV is the 4:3 one), the HUD's text, message box and icons lay out on the wider frame
  (COverlayManager's half-width 0x4de600), and movies scale by the display aspect (0x334620). The runner draws the
  scene target at the aspect (the import `gfx_display_aspect`; "Render resolution") and presents it unstretched.
  - **It changes the simulation** (D234 accepts this). The logic view's frustum follows the camera's FOV (docs/remaster.md
    3.2: ambient despawn after 150 frames off screen, om::Stream's slots, the `killBuild` rubble spawn's
    `cm_IsPointInCameraView`). Measured on fps2's 8,000-frame `HULK_INPUT` run (front end, the load, 2,000 frames of
    the first mission): the game hash differs from frame 10 (the front end's and the HUD's layout words); the
    checkpoint records stay identical through the front end, the load and the first ~1,000 gameplay frames, then the
    gameplay RNG and `legacy` diverge at record 4,342 (about game frame 7,000: something off screen at 4:3 is on screen
    at 16:9, or the reverse), particles at 4,728, the Hulk and the camera at 4,773 (drift), actors at 4,800; flow,
    clock, mission and sound never. So, like the frame rate, it is a **per-session setting**: replays, `HULK_INPUT`
    runs and `HULK_ROLLTEST` start at 4:3 (port_settings.c), netplay peers must share it and the item locks during
    netplay (when netplay exists), and its determinism holds within a setting (rolltests below).
  - Window follows resizes and fullscreen as they happen (the cameras re-run ComputeRealFOV when the aspect changes).
- **HUD Frame: Centred (Original) / Screen Edges** (`hud_frame=0|1`). The HUD's corner brackets are four fixed models
  drawn for a 4:3 frame, so at 16:9 they sit in the middle (as on the Xbox). Screen Edges moves them out to the
  picture's edges with the Wine build's `HULK_HUD=edge` shift (docs/wine-widescreen-60fps.md; bgfx_context.cpp
  `vfunc_109`, the fixed-function vertex shader's `u_vc[55]`). Nothing at 4:3; `HULK_HUD=edge|centre` overrides it.
  Render-only, but the shift is a word of the front end's context (in the arena): like aspect, per session.
- **Draw Distance: Original / Far / Very Far** (`draw_distance=270|400|700`): World::Render 0x1c88f0 fades a resident
  room out from 0x4c53bc (270) over 0x4c53c4 (25) units of horizontal distance and skips it beyond their sum
  (docs/remaster.md 3.1). An entry hook (`wasm_port.GFX_APP_HOOKS`, src/platform/wasm/gfx/draw_distance.c) sets the
  two floats to the setting's start and a band scaled with it (25 x start / 270) while World::Render runs and puts
  270 / 25 back when it returns; nothing else reads them. The near-volume radius 0x4c53c0 (150) stays. The camera's
  near/far/FOV, the projection and culling are untouched (the game's far plane, 3,000, is beyond every choice).
  - **Rooms the game has not loaded never appear.** The streaming budget decides what is resident: in the first
    mission 14-16 rooms, the farthest 340-390 units from the camera (`HULK_DRAWDIST_LOG=N` logs it every N frames).
    Far (400) draws every resident room there; Very Far (700) only helps where more is resident. Drawing the rest of
    a location is the far-field layer, a later remaster stage (docs/remaster.md 3.3).
  - **The simulation is unchanged; the game hash is not** (D235). The same `HULK_INPUT` run with the hook at 270 and
    at 1,000 (`HULK_DRAWDIST_FORCE=N`, a test knob: the menus hold the same values in both runs) gives identical
    checkpoint records on all ten tags over 8,000 frames, and the same game hash to frame 7,010; at 7,020, when rooms
    beyond 295 units first come into view, 367 words differ, all render bookkeeping: the tails of pure3d's per-frame
    render lists past the faithful run's high-water mark, the pddi front end's vids and serials of prim buffers it
    uploads at their first draw, and from those uploads the arena allocator's bounds. (World::Render's own list of
    rooms drawn, +0x54c of its manager, is written only by 0x1c6800, 0x1c88f0 and the constructor 0x1c9030 and read by
    nothing; a room's fade f58 is only ever written 0.) Any approach that has the game draw more rooms moves these
    words, so draw distance is a per-session setting too: replays and tests pin Original, netplay peers must share
    it and it locks during netplay. Netplay's desync detection hashes the game with the session's settings fixed,
    which every peer shares.
- **Fog: On (Original) / Reduced / Off** (`fog=0|1|2`): the runner's draw packets only (app.cpp `fogOverride`: Reduced
  moves the start and end planes out 2.5x, Off clears the fog flag); the game's fog state, set by the location
  scripts (`rm_SetFogPlanes`, e.g. 30..900 or 30..1,200), is untouched, and nothing in module memory changes.
  Measured with Fog Off and HUD Frame Screen Edges at 4:3 against the faithful values (7,300 frames, one build): the
  checkpoint records identical, and the game state differs only in the five words of the two items' menu objects
  (their named ints' choice indices), as the frame-rate item's do.

### Texture and model packs (wpack1)

Gameplay Options > Texture Pack: Off / each pack folder under `<app dir>/mods` (remastered default: the first one; the
row was in Video Options until wquit1 moved it: Video Options had ten rows for the front end's nine places, and the
tenth, Anti-Aliasing, was not shown; a screen of its own is not possible, see "No more screens" below). The
runner replaces textures at upload and prim buffers at their draws (run/app/texpack.cpp, meshpack.cpp); the module
never sees a replacement, so checkpoint records and HULK_ROLLTEST are unchanged with a pack on. Keys, the pack layout,
`HULK_PACK_DUMP` and the Dolphin converter: [texture-packs.md](texture-packs.md) "Override packs in the app".

- **Pack status** (wquit1): in the front end's Gameplay Options (not the pause menu's: its heap, below), two
  read-only lines after the items say what is active: "Pack contents: N textures, M
  models" and "Replaced now: N textures, M models" (the textures and prim buffers shown replaced at that moment), or
  "N packs installed, none in use", or "No packs installed. Put packs in:" and the folder. The text is the runner's
  (texpack.cpp `texpack_status`, the import `gfx_texpack_status`), set into the labels with the game's own setter
  (0x000f8500, a text that is no string id is shown as it is) when the screen opens (the entry's first OnSelect is the
  front-end function "Port_PackStatus", fe_options.c's 0x000df970 hook) and when the pack changes. The string table
  holds only a fixed placeholder, so a run that never opens the screen has the same game memory with any packs.
- **No more screens, little heap.** The front end's parser holds at most 66 screens of fe_real.txt: the disc has 63,
  and Video Options and Gameplay Options take two. A 67th (tried: a packs screen, a dummy screen) crashes the parse at
  frame ~92 (an indirect call through null in the DollyScript reader). The menus' text is also parsed again in play
  (play3 at frame 26,654), and the game heap there has almost no margin: one more screen (a quit confirm in fe_real.txt,
  or a "Quit to Desktop" with its screen in fe_run.txt) ran a later level load out of memory, and play3 hung at
  ~26,500 in the out-of-memory spin 0x0008d320 (`sample` on the hung app shows 0x00266e00 -> 0x0008d320). Add items to
  existing screens and test any menu change with play3 past frame 27,000. A screen has nine places
  (FEsubMenu_text1..9 / FEpause_text1..9, the only locators); a screen with more rows scrolls (below).
- **Scrolling** (wmenu1, D238). A screen's rows are the table's settings on it, in the table's order (add a row
  where it should appear); its nine places show a window of them. Down on the last place with rows below moves the
  window one row (the cursor stays; the places are relabelled), up on the first place likewise; at the ends the
  cursor goes round to the other end and the window with it. Two entry hooks, the screens' key handlers 0x000e5710
  (FEScreenBase) and 0x000e6050 (FEMenuBase), do it before the game's handling (key 4 down, 0 up; the focus at
  +0x48): a place is relabelled with the selector's own pieces, its label and choice text entries re-pointed at the
  setting's string ids by 0x000f8500 (no allocation for an id), missing choices appended with its vfunc_19 (a
  TextSelector holds 128 in itself), the count at +0x1d58, then measured (slot 3) and refreshed (slot 0); the place's
  named int and handler stand for whichever setting it shows. So scrolling adds no screen, no item and no named int
  (Video Options: 12 rows, 9 selectors, 9 named ints). The window (`g_top`) is game-facing state (`hulk_game_state`).
  Checks: HULK_INPUT runs through Video Options front end and pause (every row reached and changed, the file
  written), play3 to 60,000 records identical to the control.

### Playthroughs (wplay4, D244)

`tools/playthrough.py record --name play4` plays on from play3's end (or the last session's) in the app and records
the pad; sessions chain into one recording (`build/playthrough/play4/play4.hrp`, `native_replay.py run --rec play4`,
`wasm_build_job.py --test play4:N`). A session runs under replay rules from a disk snapshot of the state (sched.c
`ff_snap_write` / `ff_snap_read`, replay.cpp "Playthroughs"). docs/playthrough.md.

### Quitting the app (wquit1)

- **The menu.** The front end's Story Mode column (the main menu after Press START) ends with "Quit Game"
  (FEmain_center_item4, after Load Game; Up from New Game reaches it). It quits at once: the game looks front-end
  functions up by name when the text is parsed (0x000df970, from FEDoFunction's constructor 0x000e19d0), and a fourth
  entry hook (tools/wasm_port.py GFX_APP_HOOKS) answers "Port_Quit" / "Port_PackStatus" with host handler objects.
  There is no confirm screen and no pause-menu item: either cost a screen the heap cannot hold (above). Both editions.
- **One way out.** The menu item, the window's close button and Cmd+Q (SDL_EVENT_WINDOW_CLOSE_REQUESTED /
  SDL_EVENT_QUIT in the runner's event pump) all become a quit request (gfx.c `hulk_app_request_quit`,
  `hulk_platform_quit_requested`), which sdl_platform.cpp's pump turns into ExitProcess(0) as the window's close
  always did. While the game holds a file open for writing (a save in progress: xapi.c's CreateFileA with
  GENERIC_WRITE) the request waits, up to 10 s. The settings file is written and closed at every change. The runner's
  proc_exit then closes the movies, the audio device and the mixer and calls SDL_Quit (start.cpp `hulk_app_quit`);
  the exit code is 0. Replays and `HULK_INPUT` runs never select it; the request is host state only.

### Renderer options and the runner's passes (wr2, D236)

R2's cheap wins (docs/remaster.md section 6) on today's bgfx path, each a Video Options row (port_settings.c;
faithful value off, remastered-only) and each a pass of the runner, so they carry over to R1's own RHI:
- **The pass interface** (run/app/rm_pass.h, remaster.md 5.3 in its R2 form). A pass registers itself
  (`HULK_RM_REGISTER_PASS`, no central list) and sees the runner's settings (`gfx_quality(what, value)`, one import for
  every row), each game draw packet as the runner hands it on (`packet`, both prepare_pipeline and submit), the frame's
  first pass into the scene target (`sceneBegin`) and the end of the game's frame before the present (`postScene`:
  views 251..253 into the scene target, the post-processing point). Every sink call of the runner, direct or replayed
  by interp.cpp at 60/120 fps, goes through rm::setPass / rm::present / rm::packet, so a pass works at every display
  rate. wvid1's fog override is now a pass (FogPass).
- **Mipmaps: Original / Full** (`mipmaps`, remastered 1). The game gives 55% of the textures of the scripted run only
  their top level (DXT1 64x64 and 128x128 world textures) and some a partial chain; a texture with fewer levels than
  the full chain is drawn from a replacement with the full chain: the game's own levels byte for byte, then box-filtered
  levels encoded in the original's format (BC1 keeps its 1-bit alpha use, BC2 its explicit alpha). Made like a pack's
  replacement (texpack.cpp: worker threads, swapped in between frames; the original stays for occlusion-query draws and
  for the setting turned off). It applies to textures uploaded while the runner tracks them (from the first time the
  setting is on: the remastered default at start). A texture rewritten more than twice with new contents (a dynamic
  one) keeps the game's levels. Cost: 25 ms of encoding for the whole scripted run (1,056 chains), 4 MB on the GPU.
- **Anisotropic Filtering: Off / 16x** (`aniso`, remastered 16). Every stage the game samples linearly gets
  anisotropic minification. bgfx's Metal renderer has one level (BGFX_RESET_MAXANISOTROPY: 16), so there is no 4x/8x.
- **Anti-Aliasing: Off / MSAA 2x / 4x / 8x / TAA** (`msaa`; remastered TAA, value 1, since wperf1: run/app/taa.cpp and
  docs/performance.md; MSAA 4x was the default before and costs ~4 ms of the frame on the half-float scene). The scene target (colour and depth-stencil) is
  multisampled; bgfx resolves it at the end of each view (StoreAndMultisampleResolve), so the frame copies (blits read
  the resolved texture), the effects' render targets (single-sampled, unchanged), the front buffer and the present
  work as before. Changing it makes the scene target again between frames (app.cpp's render-size path). An occlusion
  query counts samples under MSAA: the runner divides by the samples before the render-size scaling.
- The sink's part is app-only (bgfx_sink.cpp under HULK_SINK_OVERLAY: `hulk_gfx_sink_quality`,
  `hulk_gfx_sink_scene_handles`), so the Wine and native images are unchanged (D194: the 15 pddi units byte-identical).
- **Checks.** Checkpoint records byte-identical for the 8,000-frame scripted run (HULK_INPUT) with every option off and
  on, and to the control app. The game hash differs between settings only through the options menu's own words (each
  setting's value is a menu NamedValueInt) and the occlusion counts a flare reads (render-only, remaster.md 3.1).
  HULK_ROLLTEST identical with Metal and every option on. play3 with `null`: records identical to the control app.
- **Shadows** (item 3 of D236): the game makes no shadow render target. The scripted run's render targets are the
  effects' 320x240 and two 160x120 (the blur chain) and one 640x480 copy; the character shadows are stencil draws
  (about 5 a frame in gameplay: remaster.md 2.5's ShadowSkin / ShadowMeshBuffer volumes), which are already drawn at
  the render resolution and are antialiased by MSAA (the stencil is multisampled with the depth). Nothing to raise
  runner-side; soft or mapped shadows are R3 (shadow maps replacing those draws).
- **Cost** (laptop, Metal, the scripted run's last 1,800 gameplay frames, GPU time a frame from bgfx's timer):

  | render size | all off | Mipmaps + 16x + MSAA 4x | MSAA 4x only | MSAA 8x only |
  |---|---|---|---|---|
  | 1x (640x480) | 0.79 ms | 0.99 ms | | |
  | 3x (1920x1440) | 2.13 ms | 3.23 ms | 2.91 ms | 7.79 ms |

  The render thread's time is unchanged (0.16 ms; 0.24 ms at 1x with all on). MSAA 8x stores and resolves 8 samples
  at every one of the game's views, so it is not the default.
- **Far Field: Off / On (Experimental)** (`far_field`, off by default; prototype, docs/far-field.md): the rooms of
  the location the game does not draw, beyond the draw distance, drawn by the runner straight from rooms.rcf /
  districts.rcf (run/app/farfield.cpp; never registered with the game). Visible with Fog Reduced or Off.
- `HULK_RM_LOG=1`: the GPU and render-thread time a frame and the draw count every 300 frames, and each render target
  the game makes (and the far field's matching and draws).

### Window interiors (wlook0)

docs/look.md section 5. Video Options > Windows: Original / Interiors (`windows`; faithful 0, remastered 1;
rm::kWindows): run/app/windows.cpp draws each layeredReflect building draw again as a decal over itself
(shaders/vs_rm_window.sc, fs_rm_window.sc) showing a procedural room behind every pane: the facade's alpha is 0 on the
glass, stage 1/2's mapped layer is the game's night window lights (lamps follow it), its texgen'd layer the sphere map
(over the room by Fresnel). Output only: play3's records identical with it on and off.
wlook1 (section 5.7): a room per window chosen by its centre in world space (office, home, storage; shops and lobbies on
the first storey above the street), its own light colour, on or off, blinds, curtains, silhouettes; as bright as the
game's night layer.

### Profile (wprof1)

Where the app's time goes (2026-11-22; a laptop, hidden Metal window, the scripted run plus first-mission movement;
`sample` of the main thread and `HULK_GFX_STATS`). The app is far from any limit: the faithful build's gameplay
update takes 1-2 ms unpaced (the presents are paced at 30), the remastered defaults' (1920x1080, 60 fps by
interpolation, Far, the pack) about 3 ms for an update and its two presents. Paced at 60 the process uses ~15% of one
core and the main thread is asleep ~89% of the time.

- **Draws**: 90-360 an update in gameplay (30-62k primitives, 12 passes, 7 effect quads), 20-30 in the front end.
  Consecutive draws that could merge (same program, state, textures, constants and source): 3-6 an update. Draws
  differing only in their vertex constants (instancing candidates): 20-130. On Metal a draw costs ~1-2 us of encoding:
  batching or instancing would save at most ~0.2 ms a present.
- **Uploads**: prim buffers are made once, at their first draw after a change (bgfxPrimBuffer::prepare; static bgfx
  buffers, dynamic once rewritten): 0-0.8 vertex buffer uploads an update in gameplay (~8 KB), none for static world
  geometry or skinned meshes (skinning runs in the vertex program). Transient vertices (prim streams: text, HUD,
  particles): ~5,000 an update (~400 KB at 80 bytes a SinkVertex). Textures: none in steady gameplay; a playing movie
  uploads its frame (0.8-1.2 MB) each frame.
- **Main thread, remastered, unpaced** (share of samples): game update and scene traversal in the module 43% (the x87
  helpers 7.7%, ff_dispatch's indirect calls 4.6%, World::Render's subtree 12%), bgfx's Metal encoding 25%, waiting
  for the GPU 10%, interp.cpp's own work 9% (copies of constants and transient vertices, matching), bgfx Metal's
  transient buffer (a new MTLBuffer and a blit of the frame's transient vertices every bgfx frame) 4.6%, the mixer
  3%, the pddi front end's own code 3%, the sink imports 2%. GPU 1.5-1.8 ms a frame at 1920x1080 (0.5-0.8 at 640x480).
- **Pacing waits** (interp.cpp waitUntil: usleep to 1 ms before the deadline, then yields): the timers wake 1-2 ms late
  under load; the yield loop costs 0.2-0.7 ms of CPU an update at 60 and up to 7-9 ms at 120 on a loaded machine.
  A mach_wait_until variant cut the yielding to 0.1-0.5 ms but woke later (median 1.7 vs 1.0 ms at 60, load ~35):
  not landed; measure on an idle machine and with the bundle's user-interactive QoS before changing it.
- `HULK_GFX_STATS=N` (run/app/gfxstats.cpp; app runner only, nothing when unset) logs every N updates: wall time an
  update and the time in the sink imports by kind, bgfx's CPU / GPU / wait times, draws (transient, indexed, queries,
  bgfx's count), primitives, mergeable / constants-only neighbours and distinct buffer-draw groups, state changes,
  passes, uniform bytes, transient vertices, buffer and texture uploads (and repeats of a vid within the window), bgfx's
  buffer counts and texture / target memory, and the pacing waits (late p50 / p99 / max, yielding). Draws and uploads
  are counted at the sink imports (an update's own draws), not at interp's re-submits; turning it on hashes every
  draw's constants (~1 us a draw).
### Tutorial skip (wskip1)

Gameplay Options > Tutorial Skip: Off / On (`tutorial_skip=0|1`; remastered-only, remastered default On, faithful Off).
In the two tutorial missions, c00m01 (the moves) and c00m02 (being the Hulk), a spinning, glowing star with a light
beam waits about 4 units behind the Hulk where play starts (towards the camera: pull the stick back). Walking into it
ends the mission as a completed one. To turn it off: Options > Gameplay Options > Tutorial Skip: Off (or Remastered
Edition: Off), or `tutorial_skip=0` in `HULK_SAVE_DIR/port_settings.txt`.

- **The game's own success path** (src/platform/wasm/gfx/tutorial_skip.c). The skip runs one line of our own Lua
  through the game's `sh_DoString` (0x001d3f00), calling the bindings the mission's own ending calls: for c00m01 the
  mission's progress "complete", `gfm_SetAcquireMission("c00m02")` and `sm_SetMissionState(MISSION_SUCCESS)` (the
  Mission Success screen: Save, Continue); for c00m02 `gfm_SetNextMission("c01m10")`, its XP award and
  `MISSION_IMMEDIATELOAD` (no summary, as in the game). The fades and the c00m01 cut-scene that close the missions
  are skipped. The save, the next mission and the XP are the game's. Setting only the mission's progress or its script
  state is not enough: the missions poll those conditions only in their last stage, and jumping c00m02's script state
  during its intro made its streaming allocate a temp heap with no room left (the game's out-of-memory loop
  FUN_0008d320).
- **When the star appears.** An entry hook on UpdateSimulation 0x00088c30 (`wasm_port.GFX_APP_HOOKS`) checks after
  each update: the game-flow manager's chapter 0, mission 1 or 2; the main actor (world +0x20, +0x124). The star is
  placed when the Hulk is in play (a controller slot, +0x20a8 >= 0, and the logic view within 14 units: the chase
  camera; an intro's cameras are far while the script already moves him) and has stood still for 45 updates. It fires
  when he comes within 1.8 units of it horizontally while in play, once per mission run (a new main actor starts
  again). Its place, the counts and whether it fired are in `hulk_game_state`, computed only from game state, so the
  same input gives the same game and HULK_ROLLTEST holds across the skip.
- **Drawing** is the game's pddi context after World::Render (draw_distance.c's hook calls
  `hulk_wasm_tutorial_skip_draw`): two of the device's "simple" shaders (kept, in the arena), prim-stream triangles in
  world space (an extruded five-pointed star shaded by a fixed light; an additive glow disc facing the camera and a
  beam, drawn without depth writes so the Hulk behind them still draws). Our own geometry; no game assets. It moves
  the front end's render bookkeeping like any draw, only while the star is up.
- **Per session.** It changes the game (the mission ends), so replays, `HULK_INPUT` runs and HULK_ROLLTEST pin it off
  (pin it on with `HULK_SETTINGS=remastered=1,tutorial_skip=1`), and netplay peers must share it. Off, nothing runs:
  the checkpoint records are the original's. `HULK_TSKIP_LOG=1` logs the placement and the skip, `=2` every 30 updates.

### Traversal moves (wtrav1, D242)

docs/traversal.md §11. Gameplay Options > Traversal Moves (`remaster_moves`; remastered-only, per session: it
changes the simulation, so replays, `HULK_INPUT` runs and HULK_ROLLTEST pin it off and netplay peers must share it).
On, `src/platform/wasm/gfx/traversal.c` adds the charging sprint and higher leaps as six moves in the game's own store
(slots 0x2c4-0x2c9, bought with smash points, saved in the original's purchase bits) and a landing bounce, through
entry hooks (sprint 0x163ed0 / 0x15e250 / 0x15c540, input 0xfd0f0, damage 0x13f20, jump 0x13b90, store list 0xc21b0,
and tutorial_skip.c's UpdateSimulation hook). Off, every hook passes through and nothing is set up: play3's records are
byte-identical to the app without it. Test knobs: `HULK_SETTINGS=remastered=1,remaster_moves=1`,
`HULK_TRAV_FORCE=C,J` (levels as if bought), `HULK_TRAV_TEST_XP=N` (smash points), `HULK_TRAV_LOG=1..3`.

### Developer options (wdev1)

Developer mode: `developer=1` in `<save dir>/port_settings.txt` (a key with no menu item; the app keeps it when it
rewrites the file) or `HULK_DEV=1` in the environment (never saved; ignored in replays). It is read at launch: the
menus' item places are parsed once, so it takes a restart. In developer mode Gameplay Options lists three more rows
after Traversal Moves (port_settings.c keys `dev_*`; outside developer mode they are hidden, their strings are not
added and they take their faithful value, Off):
- **Force Charge Sprint: Off / I / II / III** and **Force Mega Leap: Off / I / II / III** (`dev_charge`, `dev_leap`):
  the traversal level the hooks use, as if bought (`HULK_TRAV_FORCE`'s path); they need Traversal Moves On. The store
  still shows the real purchases.
- **Force Original Moves: Off / All Bought** (`dev_moves`): every shipped store move (slots 0x266-0x2c3 with a name)
  counts as unlocked and bought: the fight script's `unlockable` condition (0x12f110, answered by an entry hook; air
  dash levels, combos), the C++ purchase reads through 0x92940 (the health upgrades 0x401a0 and the health bar
  0xd2c30) and the missile deflection (0x19e910 reads move 0x2b9's bytes itself: set for the call and put back).
Nothing is written: no purchase bit, locked byte or smash point changes. The save's capture 0x8b560 reads every
purchase bit through 0x92940, so the hook answers the real bit while it runs (traversal.c `g_saving`). Checked: a
play3 replay with Force Original Moves on from frame 8,600 (`HULK_DEV_TEST_FROM`, a test knob) writes its 8,793 save
byte-identical to the save of a replay without it (63 forced moves, 0 bits differ); the same replay with the guard
removed wrote 63 forced bits (32 bytes differ). Lua (`um_*`, through 0x92de0 inside the defining TU, which no entry
hook sees) and the store's screens see the real state. The rows are kept in port_settings.txt like any setting, so
they stay set across launches while developer mode stays on; they change the simulation, so they are per session
(replays, `HULK_INPUT` and HULK_ROLLTEST start from Off; netplay peers must share them). No smash-points row: the
store spends the real `xp` stat, which the save keeps, so a boost cannot be made temporary without a sidecar.

### Lighting and dynamic lights (wlight1)

docs/lighting.md. Two Video Options rows (port_settings.c; faithful off, remastered on), one runner pass
(run/app/lighting.cpp) with its own bgfx shaders (run/app/shaders, compiled by tools/rm_shaders.py into the app's
include dir by `wasm_app.py build`, and for Android by `wasm_android.py`, spirv + essl; the binaries live in
build/third_party/out/rm-shaders/<profile>; the queue's wasm hosts have no shaderc, so wasm_build_job.py ships this
machine's out/rm-shaders/metal and an overlay that edits run/app/shaders needs `--shaders-ok` after a local
`tools/rm_shaders.py`):
- **Lighting: Per-Vertex (Original) / Per-Pixel** (`lighting`). Lit fixed-function draws (vertex program 0 with
  LIGHTING, 6 two-sided: Hulk and the characters in play3) and the skin programs get a per-pixel program: the faithful
  transform, then the same light model in the fragment shader, then the faithful combiner (`fs_vp_stage.sh` included,
  one `fs_pxcmb_<hash>` per combiner key). The faithful shaders and the Wine image are untouched.
- **Dynamic Lights: Off (Original) / Health Orbs** (`dyn_lights`). Each health orb (found by its pair of draws: sprite +
  14-vertex mesh, additive, same texture) is a green point light (radius 8) on the opaque draws of the world's pass
  near it, the baked world included (added to the vertex colour before the texture). Lights are kept in world space
  (the frame's view from the static world draws' modelview) and applied from the next presented frame's view; only
  draws whose prim buffer's bounding sphere meets a light take the per-pixel program.
- Never changed: occlusion-query draws, 2D/orthographic views, blended draws (as receivers), refraction/proximity.
- **Checks**: checkpoint records byte-identical for the 8,000-frame scripted run (HULK_INPUT) with both off and on;
  play3 on Metal to 19,010 (the tutorial's and the city's orbs) off and on: records identical; play3 with `null` to
  60,000: records identical to the control app; HULK_ROLLTEST identical with Metal (6500:7600, 60 fps, 3x). The game
  hash differs between settings only through the options menu's own words, as for wr2's rows.
- **Cost** (laptop, Metal, play3's city 4,000-31,000 frames with `HULK_LIGHT_AB=30`: the passes off and on in turns of
  30 frames in the same run, so both see the same scenes and load): GPU 1.33 -> 1.44 ms a frame at 1x, 3.58 -> 3.96 ms
  at 3x (1920x1440) with MSAA 4x + 16x + Mipmaps; render thread +0.02..0.07 ms. 30-90 draws a frame take a per-pixel
  program (the lit characters and props, and the world draws near an orb). Android: the shaders build for spirv and
  essl (not yet run on a device).
- `HULK_LIGHT_LOG=1` (per-pixel draws and lights a frame), `HULK_LIGHT_AB=N` (the cost above), and for finding draws
  `HULK_LIGHT_DUMP=a:b:file` (every draw of presented frames a..b, small prim buffers with content keys) and
  `HULK_LIGHT_HIDE=ordinal,...` (hides a texture's draws).

### HDR, ambient occlusion and shadows (wr3a)

docs/hdr-shadows.md. Three Video Options rows (port_settings.c `hdr` Off/On, `ao` Off/On, `shadows` Original/Low/High;
faithful off, remastered On/On/High), runner passes run/app/hdr.cpp, ao.cpp, shadows.cpp that draw between the game's
passes: while one is on, rm renumbers the game's passes in submission order with the runner's views among them
(`rm::newView`, `viewsBefore`, `viewsHere`, `splitPass`; copies and effect quads now go through rm too).
- **HDR**: the scene target and frame copies in RGBA16F (sink overlay); tone mapped (a knee at 0.8, plus a glow of the
  light above 1) in views just before the game's first effect copy or quad, so the game's colour pass, bloom, overlay
  and HUD run unchanged on top.
- **Ambient occlusion**: the scene's depth made readable; a half-size screen-space obscurance from it and the world
  pass's projection, blurred and multiplied into the scene once the world's opaque draws are done (before translucent
  draws, particles, the stencil-shadow quad and the HUD).
- **Shadows**: a D16 atlas from the sun (the game's key light in world space), drawn before the scene from the world
  pass's opaque draws with caster programs (rooms and the rest in two rows); received by the lighting pass's per-pixel
  programs (every opaque world-pass draw takes one while Shadows are on); the baked world takes only the objects'
  shadows; the game's stencil-shadow quad is hidden.
- Output only: checkpoint records identical with every setting; the pddi units compile byte-identical (D194).

### Reflections (wssr1)

docs/reflections.md. A Video Options row (port_settings.c `reflections` Off/Low/High; faithful off, remastered High),
run/app/ssr.cpp: screen-space reflections. The world pass's opaque draws (and its additive glows, as depth) are drawn
again into a G-buffer of the runner's (depth, normal, reflectance per draw: wet ground at night, `layeredReflect`
buildings, `environment` objects); at the frame's first effect (before HDR's tone map) each reflective pixel's
mirrored ray is marched across that depth (Low half size, High full size) and the hit's scene colour blended over the
surface by Fresnel; where no ray hits, the game's own REFL / sphere-map surface stays. Other passes read the result
through run/app/ssr.h (docs/reflections.md "SSR interface"). Output only: play3's records identical.

### Night Lights and Atmosphere (wlook2)

docs/night.md. Two Video Options rows (port_settings.c `night_lights` Off/On, `atmosphere` Original/Enhanced; faithful
off, remastered On/Enhanced). run/app/nightlights.cpp turns the night city's own additive glows (street lamps, signs,
vehicle lights, markers; the sprites' centres from their transient vertices, `rm::transientVertices`) into world-space
lights, kept steady across frames by distance matching, and hands the per-pixel lighting a tiled light list (a 64 x 64
float texture: lights, then 16 indices per screen tile); pools under the lamps, spill on walls and characters.
run/app/atmosphere.cpp re-grades the game's sky dome in its own draw (fs_rm_sky.sc: zenith, horizon glow, clouds lit
from below by the city, stars, a moon at the key light) and, after ambient occlusion, adds exponential height fog,
aerial perspective and the lamps' in-scattering from the scene's depth (fs_rm_atmos.sc). The Fog row scales the added
fog. Output only: play3's records identical.

### Colour grade (wlook1)

docs/look.md section 7. Video Options > Colour Grade: Original / Natural / Cinematic (`grade`; faithful Original,
remastered Cinematic; rm::kGrade): run/app/grade.cpp, shaders/fs_rm_grade.sh. A parametric grade (contrast, split
toning, saturation with vibrance, a toe, a vignette) of the scene before the game's effects and the HUD, by the
location's time of day (the rooms' fog); inside HDR's tone map (no pass of its own; with HDR off nothing is graded). Output only:
play3's records identical.

### Grass (wgrass1)

docs/grass.md. A Video Options row (port_settings.c `grass` Original/Blades Low/Blades High; faithful Original,
remastered High), run/app/grass.cpp: blades on the game's grass ground. Textures are classified as uploaded and the
rooms' prim buffers kept (a worker thread makes 64x64 thumbnails and each lawn's clumps: level triangles, the draw's
own combiner evaluated on the CPU so only grass grows, the ground's colour per clump); each frame the clumps near the
camera are drawn instanced right after their ground draw (vs_rm_grass / fs_rm_grass: density by distance through a
per-clump rank, wind from the display clock, characters bending them aside, the sun's shadows, the night lights, the
fog). Reflections give grass no reflection (shaders/rm_grass.sh, shared). Output only: play3's records identical.

### Movies (wmov1; hold to skip: D231)

The game's Bink movies (the start-up logos, the attract loop, the cut-scenes) play with picture and sound in the app.

- **One model of what the game reads.** host/bink_null.c stays the only Bink the game sees: the handle's words
  (width, height, frames, frame number), BinkWait on the virtual clock (a frame not yet due moves the clock to it),
  BinkNextFrame, BinkClose. Weak hooks (gfx/movie.c, app builds only) observe the calls and hand them to the runner
  (`hulk` imports `mov_*`); nothing the runner does flows back. A movie's identity (the archive name's hash, the
  virtual clock at the open, the sound tracks) is in the handle's reserved words and the live handles in
  `hulk_game_state`, so a snapshot carries them.
- **The copy answer.** With a picture the app answers BinkCopyToBufferRect 0 ("copied"): PlayerBink (0x333de0) then
  hands the frame to its render loop (CRadMovieRenderLoop::vfunc_3), which clears, draws the tiles and presents.
  Answering 1 (the null model, kept for replays, headless runs and the app with `null` / `noop`) is a failed tile to
  the game: no present, and a whole movie ran inside one frame (black). **The answer changes the game's path**
  (presents, frame count): app free play (0) and replays / headless (1) are different game runs through a movie, so
  every peer of a netplay or rollback session must run the free-play mode. The answer never depends on the decoder:
  without FFmpeg the app still answers 0 and shows black frames with the same timing.
- **The decoder** is the SDL layer's (src/platform/sdl/movies/movie.c: FFmpeg's bink demuxer and decoders, no RAD
  code), compiled into the runner (run/app/movie.c) with FFmpeg's headers (Homebrew's, or `HULK_FFMPEG_PREFIX`, at
  build time) and FFmpeg's own libraries loaded at run time (`dlopen` of libavutil / libavcodec / libavformat of the
  headers' major versions from `HULK_FFMPEG_DIR`, the build's prefix, /opt/homebrew/lib, /usr/local/lib). Nothing of
  FFmpeg is linked into, bundled with or committed for the app. Without the libraries (or with other major versions)
  every movie plays black with one log line. The movie's bytes come straight from the disc's archive (the name the
  game opened, hashed as the game's file system does: docs/formats/rcf.md), never through the game's I/O callbacks,
  so decoding moves no game state. The picture of the frame the handle's frame number names is converted into the
  game's own lock (B, G, R, A, bottom-up) at BinkCopyToBufferRect; a frame behind the decoder (a restore) reopens the
  movie and decodes up to it.
- **Real time.** BinkWait's clock jump would play a movie as fast as the host draws it; the runner sleeps until the
  frame is due on the movie's own wall clock (anchored at its start, a pause or a restore; `mov_wait`). That decides
  only when BinkWait returns, never what it returns: the game's values follow the virtual clock and the input alone.
- **Sound.** Each selected track is a streaming voice on the app's mixer (hulk_audio_stream_*, the game's mix bins
  and volume), started and stopped with the movie's pause state and topped up just before every slice the mixer
  renders (`hulk_app_movie_tick` from aud_tick), so it advances with the same 48 kHz of game time as the DirectSound
  model (D222) and stays in step with the picture. After a restore its decoder seeks to the movie's time.
- **Hold to skip (D231).** Holding B (the keyboard's F) for a second skips any movie, also the ones the console
  doesn't let you skip; a short press does what the game does with it. The hold is timed on the virtual clock from
  pad 0 of the frame's input (the sim block's pads: recorded, replayed and re-simulated with the frame), kept in
  `hulk_game_state`; B held since before the movie opened counts only after a release. The skip goes through the
  game's own end of a movie: the handle's frame number becomes the last one and the movie's clock that frame's due
  time, so PlayerBink's end test (frame number == frames - 1) closes the movie as if it had played out. The runner
  draws a ring in the window's bottom-right corner (a tenth of the window's smaller side; our own drawing) that fills
  while B is held, over the presented frame (the bgfx sink's overlay, `HULK_SINK_OVERLAY`: the app's runner only),
  so it doesn't depend on the render resolution. Replays never skip (the movie hooks are off there; no-fmv stops
  their movies).
- **The clear order** (bgfx_context.cpp slot 4, under `HULK_PDDI_WASM`): the render loop clears before it begins the
  frame; the front end opened a view for that clear after the last frame's draws, and bgfx ran it after the new
  frame's view 0, wiping the tiles. The clear now moves to view 0. The Wine and native builds keep the old order (the
  same bug there: a follow-up that needs a Wine pair, D194).
- **Snapshots.** After a restore (`ff_movie_restored`) the runner closes the movies the restored state doesn't hold
  and reopens or re-seeks the rest (the picture lazily at the next copy, the sound to the movie's time).
  `HULK_MOVIES=0` turns the movie hooks off (the null model); `HULK_MOVIE_LOG=1` logs opens, pauses, closes and
  restores. The runner's `hulk_app_movie_playing()` says a movie plays (its frames are not to be interpolated: fps2).
### Display rates by interpolation (fps2, D228a)

The user's decision D228a: the game is deterministic whatever the frame rate. fps1's 60 fps changed the simulation
step (one field a present: a jump peaked 0.5 units higher); this replaces it. The simulation always steps at the
original's rate (two 60 Hz fields an update in gameplay, one in the front end and movies, as SwapBuffers 0x31b190
waits), so a run's game state depends only on its frame-indexed input; the display presents at 60, 120 or the
display's refresh by drawing the last simulated frame again with its transforms interpolated from the frame before.

- **Where: the runner, at the draw sink.** Rendering never feeds back into the module: the sink calls that answer
  the module (preparePipeline's program, resources made, query results) stay immediate; only what draws is
  recorded. With interpolation on, app.cpp's sink imports append each update's passes, frame copies, draws (the packet
  with copies of its vertex constants and, for prim streams, its transient vertices), full-screen passes and present
  to a stream (`run/app/interp.cpp`) instead of submitting them; the frame's end (`gfx_frame`) closes it. No tree
  source changes and no game-state change: the recorder reads linear memory only.
- **What is interpolated.** The bgfx sink draws only from a packet's vertex constants, fragment uniforms, stages,
  state and buffers (`modelview`/`projection` are informational), so the constants are what move. Fixed-function
  draws (vs_vp_ff layout): c0-c3 the modelview (camera folded in), c4-c7 the projection, c14-c29 the lights (camera
  space, lerped when the same lights are on), c32-c47 the stage texture matrices (lerped unless a component steps by
  more than 0.5: a scroll wrapping), and the normal matrix c52-c54 recomputed from the interpolated modelview. Vertex
  programs (c96-c191: skin, skin_onebone, refract, skin_refract): every constant lerped (the projection columns, the
  camera-space bone rows, refract's clip and world matrices, light directions, material). Matrices are lerped element
  by element, not decomposed: the constants are composites (bone x modelview, world x view x projection) that a
  decomposition cannot take apart, and over one 30 Hz step the shrink of a lerped rotation is 1 - cos(theta/2)
  (0.14% at 6 degrees a frame, 1.5% at 20). Fragment uniforms, textures and buffers are frame N's.
- **What the runner's passes see.** A replayed draw carries frame N's combiner key (interned), modelview, projection,
  view and lights (copies in the stream, each shared with the last equal one; not interpolated), so the rm passes'
  `late`/`draw` hooks classify draws as at 30 fps. Before wwin2 they were null at 60/120: window interiors (the
  combiner key) and the far field (the modelview) were missing, and the shadows' and atmosphere's key light and the
  sky dome's combiner test fell back.
- **Matching draws between N-1 and N.** A draw's key: pass, prim buffer serial (bufferOwner; 0 for a prim stream),
  vertex program, shader kind, combiner hash, the four stage texture ordinals, primitive kind, prim stream or buffer;
  a draw is the k-th of its key in its frame. (Not the shader serial: it is a change serial, new at every set-up of
  the shader, so text and HUD draws never matched.) Keys with the same count in both frames pair in order; otherwise
  each draw of N takes the unused draw of N-1 nearest in camera-space translation. A pair whose camera-space
  translation moved more than 40 units plus 0.3 of its distance (a camera turn moves far things by distance x angle:
  play3's world sits 100-3,000 units away and moves 1-40 units an update), whose axes turned more than 30 degrees or
  whose scale stepped by half is drawn from N unchanged (a teleport, a respawn reusing a slot); when more than half
  of the matched draws with a known transform jump, the frame is a camera cut and nothing interpolates. An unmatched fixed-function draw
  (spawned, a particle stream whose size changed) whose modelview and projection equal a matched draw's takes that
  draw's interpolated transform (world-space particles move with the camera); any other unmatched draw is frame N's.
  Stamped with `HULK_INTERP_LOG=1` (matched, snapped, substituted, unmatched per frame).
- **Presents.** A running present clock steps by the display period d (1/60, 1/120 or the display's refresh); the
  presents falling in an update's period P (1/30 s in gameplay, 1/60 in the front end's 60 Hz screens) draw its
  stream at alpha = (t - start + d) / P, clamped to 1. At a whole ratio m = P / d the clock realigns with every
  update and present k (0..m-1) is at alpha (k+1)/m: the last present of each update is frame N exactly, as the
  30 fps path shows it. A display rate that does not divide (75 Hz) gets 2 or 3 presents an update at their true
  times. The displayed state trails the simulation by P - d (17 ms at 60, 25 ms at 120); input is still sampled once
  an update, at the same point. Movies: while wmov1's `hulk_app_movie_playing()` (run/app/movie.c) says 1, nothing
  is recorded or drawn twice: each movie frame is presented as it comes; the skip ring
  (`hulk_app_movie_overlay`) is drawn once per present, after the re-submitted stream. The HUD's quads do
  not move. The front
  buffer (the effects' overlay reads the previous frame as presented) is kept only by the last present, so the
  overlay reads simulated frames as at 30. Resources the module destroys while a stream may still be drawn are
  destroyed once that stream is retired. After a restore (rollback) the next frame is drawn without interpolation.
- **Pacing** moves from the front end's platformFramePace (sdl_platform.cpp, `HULK_PDDI_WASM` only) to the runner
  (`plat_pace(fields)`): the frame period is the original's (the flag 0x005554a0), the presents of a frame at
  deadline + k x period / m. Pacing stays off in replays, with `noop`, and with `HULK_FPS_CAP=0`.
- **The option.** "Frame Rate: 30 FPS / 60 FPS / 120 FPS / Display" (Video Options, wopt1; `frame_rate=30|60|120|0` in
  port_settings.txt, 0 the display; 30 = no recording, today's path). "Display" presents at the display's refresh (vsync).
  `HULK_DISPLAY_FPS=30|60|120|display` overrides it in the runner without touching the menus. The setting is host
  state (not in a snapshot); the menu's own objects (the item's NamedValueInt and selector) show it, the only game
  words that depend on it.
- **Audio**: waud1's model advances by the virtual clock, which follows the fixed simulation step: unchanged.

### Disc sources: folder, .iso, disc pack (wpkg1, D237)

The runners read the game from one of three sources through one host file layer, run/disc.c (disc.h): the extracted
folder as before, an Xbox disc image (.iso) read in place, or a disc pack, one compressed seekable file. An image's
files are named as if it were the folder (`<image>/default.xbe`, `<image>/art.rcf`): `HULK_DATA_DIR` / `HULK_XBE` /
argv take the image's path, and every reader goes through the layer: the module's `hulk` file imports (run/native.c:
open, read, size, kind, list), the app's movies (movie.c reads the RCF archives directly), the far field (farfield.cpp),
the start-up check (start.cpp) and file texture packs (texpack.cpp). An image is mounted the first time a path runs
through it and stays mounted; names are case-insensitive; images are read-only. `HULK_DISC_LOG=1` logs mounts,
`HULK_DISC_TRACE=1` every read of an image's file (name, offset, size).

- **.iso** (XDVDFS, written from the format's public description): the volume descriptor is sector 32 of the game
  partition, which starts at 0 in a trimmed (xiso) image and at 0x18300000 in a full Redump image; both are detected.
  Directory tables are binary trees walked once at mount. A read is one pread at the file's sector.
- **Disc pack** (`tools/disc_pack.py`, `.hulkdisc`): every file in 256 KiB chunks, each a zstd frame (level 19, with
  its checksum), stored as it is when zstd saves less than 3% (the Bink movies, most of sound.rcf), or not stored when
  all zero; a zstd index at the end; `.hulk/pack.json` holds every file's size and sha256. A read that covers whole
  chunks decompresses into the caller's buffer, partial reads go through a 16-chunk cache; stored chunks are plain
  preads. zstd's decompressor (facebook/zstd v1.5.7, BSD; `disc_pack.py fetch-zstd` unpacks the pinned tarball into
  build/third_party/src/zstd, which the build tools do on first use) is compiled into the runners from run/zstd_dec.c.
  `disc_pack.py build SRC OUT` (SRC: the folder or an .iso), `verify PACK [--source SRC]` (every file's bytes against
  the manifest's sha256 and, with a source, byte for byte), `measure SRC` (levels x chunk sizes on a sample), `ls`,
  `cat`. Chunk size and level (measured on every 16th chunk): 64 / 256 / 1024 KiB at level 19 give 84.6 / 84.0 / 84.3%,
  levels 3 / 9 / 15 / 19 at 256 KiB 84.9 / 84.6 / 84.1 / 84.0%; one-thread decompression 450-790 MB/s at every
  setting, so 256 KiB / 19 (the smallest file) costs nothing at load. By file: rooms.rcf 44%, art.rcf 61%,
  sound_en.rcf 74%, sound.rcf 88%, the movie archives 99-100%.
- **AV1 movies** (optional; `tools/disc_av1.py encode SRC DIR`, then `disc_pack.py build SRC OUT --av1 DIR`): each
  Bink movie (.rmv in the movie archives) is re-encoded as Matroska: AV1 (SVT-AV1, preset 6, CRF 30, 8-bit 4:2:0, the
  same size, frame count and rate: every frame passed through, each encode's decoded frame count checked against the
  Bink header) and every Bink sound track as Opus (32 kbit/s mono) in the Bink file's track order. SSIM against the Bink
  decode 0.98 on a sample. The game's own model never sees it: the trace (`HULK_DISC_TRACE`) shows the game reads only
  each movie archive's header and directory and the first KiB of a movie it opens (bink_null.c takes 44 bytes); the
  pack keeps every movie's first 64 KiB (header and frame index) and stores the rest as zeros (no bytes), and the
  archives' headers, directories and name tables as they are. The runner (movie.c) decodes
  `.hulk/av1/<archive>/<entry hash>.mkv` instead when the pack has one, with the frame count, the rate and the sound
  tracks' ids taken from the kept Bink header. Needs an FFmpeg with libdav1d and Opus: Homebrew's has both, and so
  does the Android build (`wine_ffmpeg.py build --target android-arm64`, wapk1: dav1d 1.5.1, BSD 2-clause, from its
  pinned VideoLAN tarball, built static by meson with the NDK and linked into libavcodec.so; FFmpeg's own Opus decoder,
  which needs libswresample.so; the Matroska demuxer; still LGPL 2.1+, dav1d's notice in
  build/third_party/out/LICENSES-DAV1D.txt; needs `build/venv/bin/pip install meson pkgconf`).
- **Texture packs in the disc pack** (wapk1): `disc_pack.py build SRC OUT --texpack F.hulkpack` also stores a one-file
  texture pack's files under `.hulk/texpacks/<name>/`, so one file holds the game and its HD textures (Android's
  picker grants only the file picked, not its neighbours). A SRC that is a pack keeps its AV1 movies and texture packs,
  so `disc_pack.py build hulk-av1.hulkdisc hulk-hd.hulkdisc --texpack hfr-baked.hulkpack` adds the pack to an AV1 pack
  (1.325 GB, 157 s); `verify PACK --source ISO --texpack F` checks the disc files, every member's sha256 and the
  texture pack byte for byte against its file. disc.c lists a folder under `.hulk/` when asked for it (the root's
  listing still hides `.hulk`), and texpack.cpp lists `<HULK_DATA_DIR>/.hulk/texpacks/<name>` as a one-file pack
  `<name>` whenever the game comes from a pack (the chooser's choice, the bundle's game.hulkdisc, Android's `fd:N`).
- **Sizes** (the USA/Asia disc): folder 2.447 GB; trimmed .iso 2.447 GB (a full Redump image is 7.8 GB); disc pack
  2.060 GB (84.2%, 145 s to build on 2 threads); disc pack with AV1 movies 1.045 GB (42.7%; the 28 movies 1,226 MB of
  Bink -> 205 MB, about 10 min to encode). The texture pack below: 605 MB of PNGs -> 280 MB as one baked file.
- **Checks**: tests/wasm_disc/run.sh FOLDER IMAGE (disc.c against the folder: every file whole and at random offsets
  and lengths; tests/wasm_disc/make_test_iso.py writes a synthetic disc as a trimmed and a full-layout image, sparse);
  play3 (`HULK_GFX_RENDERER=null`, one hulk-app, queue build 111577) writes checkpoint records byte-identical to the
  folder's from the pack (to frame 60,240), the .iso (20,100) and the AV1 pack (20,550), and the folder's are
  identical to HEAD's own build (the reference gate reports the same known divergences, 5875 camera ..., for all);
  `HULK_ROLLTEST=900:2500` from the pack is identical. Android (emulator, `install --game`): the pack's records equal
  the folder's to frame ~24,700. AV1 decode, a Metal free run from the AV1 pack: the start-up movies open with the
  Bink header's frame count, rate and 6 tracks, every frame decoded and copied. Load time: 20 s for 20,000 frames from
  each source (level loads included); the whole 2.45 GB pack reads through disc.c in ~5 s. A stored (raw) chunk has
  no checksum at run time (zstd frames do): `verify` is the full check.
- **Where the app finds a game** (start.cpp): the command line; a game bundled in the app
  (`Contents/Resources/game.hulkdisc` or `game.iso`); the remembered choice (game.txt: a folder or an image);
  `<app dir>/disc`, `disc.hulkdisc` or `disc.iso`; else the chooser, whose "Choose File..." takes default.xbe, an .iso
  or a .hulkdisc. Android: SetupActivity's "Choose a disc image or pack" (`ACTION_OPEN_DOCUMENT`, a persisted read
  permission) hands GameActivity the content URI; it opens the file and passes its descriptor as `HULK_DATA_DIR=fd:N`,
  which disc.c reads with pread (no copy). `<files>/game.hulkdisc` (or the external files dir's) is found first.
- **Personal bundles** (never published: they hold the game; the employer check rule): `wasm_app.py bundle
  --with-game PACK|ISO [--with-texpack FILE.hulkpack]` copies them (APFS clones) into Hulk.app's Contents/Resources;
  the app plays the bundled game with no setup and lists the bundled texture pack. Android: `wasm_android.py install
  [--apk A] --game PACK [--texpack F]` streams them into the app's internal files dir (`adb exec-in run-as ... cat`;
  a debug build), not into the APK (copied again at every install, and an APK stays under 4 GB).

## The Android app (wand1)

The macOS app's module and runner on arm64 Android handhelds (Android 12+, API 31, arm64-v8a): the same hulk.wasm, run
through wasm2c and compiled by the NDK, with SDL3's Android layer and bgfx on Vulkan (OpenGL ES 3 as the fallback).
Gamepad only (the user, 11-22: handhelds with built-in controls, which SDL sees as a gamepad; no touch controls).

- **Build** (`tools/wasm_android.py`; the NDK, SDK and AVD under build/android, `. build/android/env.sh`):
  `wasm_android.py bgfx` (bx/bimg/bgfx for android-arm64 with the Vulkan and GLES renderers,
  build/third_party/out/android-arm64), `wasm_android.py build --wasm-dir <a wasm_app.py build dir>` (wasm2c of its
  hulk.wasm into build/wand1/android/aot, the C at the macOS app's flags `-O2 -fno-strict-aliasing`, the runner with
  native.c's `main` as `SDL_main`, run/android/log.c, SDL3 from `tools/native_android_sdl.py --config app`; one
  `libmain.so`), `wasm_android.py apk [--ffmpeg]` (tools/android_apk.py's javac / d8 / aapt2 / zipalign / apksigner with
  src/platform/wasm/android's manifest and activities; debug key; never published). Objects are cached by content: a
  host-only change relinks in about 30 s. The wasm module comes from `tools/wasm_app.py build` (HULK_WASM_GFX=1).
- **Activities.** `SetupActivity` (launcher) finds the game: a `HULK_DATA_DIR` extra; `<files>/disc`; the external
  files dir's `disc` (Android/data/org.thunderclap.hulkud/files/disc) when readable; else a chooser driven by the
  gamepad (D-pad to move, A to choose, B to go back): "Choose the disc folder" opens the system folder picker (Storage
  Access Framework, `ACTION_OPEN_DOCUMENT_TREE`). The folder is checked as start.cpp checks a disc (an XBE whose
  certificate carries the title ID, every archive rcfs.txt lists), then copied into `<files>/disc` (the game opens files
  by path; a SAF folder gives only content URIs): about 2.3 GB, with a free-space check and a progress line. Later
  launches start the game directly. `GameActivity` is SDL3's `SDLActivity`; it sets HULK_DATA_DIR, HULK_SAVE_DIR /
  TDATA / UDATA (`<files>/save` ...), HULK_APP_DIR (`<files>`: `mods/` for texture and model packs; port_settings.txt is in the save dir),
  HULK_GFX_RENDERER (`vulkan`; `gles`; `null` for the headless build's run), HULK_FFMPEG_DIR, HULK_LOG_FILE
  (`<files>/log.txt`; stdout and stderr also go to logcat, tag `hulk`) and SDL_ORIENTATIONS (landscape), then any
  `HULK_*` / `SDL_*` string extra of the intent (SetupActivity passes them on), so scripted runs use `am start --es`.
- **Movies.** run/app/movie.c is built against the Android FFmpeg headers (`tools/wine_ffmpeg.py build --target
  android-arm64`: the Bink decoders and demuxer, plus dav1d / Opus / Matroska for an AV1 pack's movies; LGPL 2.1+)
  and loads `libavutil.so` / `libavcodec.so` /
  `libavformat.so` at run time from HULK_FFMPEG_DIR: `<files>/ffmpeg` when the player put them there, else the APK's
  lib dir (`apk --ffmpeg` bundles them for local tests). Without them the movies play black and can be skipped as on
  macOS. Whether a distributed APK may carry FFmpeg is the user's decision (LGPL dynamic linking).
- **Window.** The window is fullscreen from the start (platform_events.cpp under `__ANDROID__`) and no resize event
  follows, so app.cpp takes its pixel size at creation as a resize and holds it until the sink is up (the display drops
  a resize before that): the frame is then placed by the aspect setting instead of stretched. bgfx takes SDL's
  `ANativeWindow` (`SDL_PROP_WINDOW_ANDROID_WINDOW_POINTER`). Checked on the emulator: the front end and gameplay with
  Vulkan and with OpenGL ES 3.0 (`HULK_GFX_RENDERER=gles`), the movies with `apk --ffmpeg`, the chooser and SAF copy.
- **Determinism across platforms.** play3 with `HULK_GFX_RENDERER=null` in the APK on the arm64 emulator writes
  checkpoint records byte-identical to the macOS app's from the same hulk.wasm (two modules: 60,243 and 60,244 frames in
  common, 0 differ; the
  macOS file is a byte prefix of the Android one). With Vulkan rendering the records are the same too (the renderer
  does not reach game state). The emulator reaches ~260 frames/s headless (not representative of a device).
- **Replays on the emulator**: `sh tests/android/wasm_apk_replay.sh OUT FRAMES [renderer]`: the
  disc in `<files>/disc` and the recording in `<files>/play3.hrp` (`adb push` to /data/local/tmp, then `adb shell
  run-as org.thunderclap.hulkud cp ...`: files adb writes into the external dir belong to the shell, and1's finding).
- **A real device** (USB debugging on): `adb install -r build/wand1/android/hulk.apk`, launch "Hulk UD", choose the
  extracted disc folder with the gamepad (copy the disc to the device's storage first, e.g. Download/HulkDisc), or for a
  debug build `adb push <disc>/. /data/local/tmp/hulk-data/` then `adb shell run-as org.thunderclap.hulkud sh -c 'mkdir
  -p files/disc && cp -r /data/local/tmp/hulk-data/. files/disc/'` and `adb shell rm -rf /data/local/tmp/hulk-data`.
  Logs: `adb logcat -s hulk SDL`, or `adb exec-out run-as org.thunderclap.hulkud cat files/log.txt`.
- **One APK plus one file** (wapk1): `wasm_android.py apk --ffmpeg` (16 MB) and a disc pack carrying the AV1 movies
  and the HD texture pack (`disc_pack.py build ... --texpack`, 1.325 GB). On the device: copy the .hulkdisc anywhere
  the system picker reaches (e.g. Download), install the APK, launch "Hulk UD", choose "Choose a disc image or pack"
  and pick the file; it is read in place (a persisted read permission; no copy) and later launches start directly.
  Checked on the emulator (picker driven with `input tap`): the game from the picked file (`HULK_DATA_DIR=fd:N`),
  Video Options' pack "hfr-baked" listed and drawn (Vulkan), the AV1 start-up movies decoded (every frame), and play3
  with `null` (`HULK_TEST_DISC=picked sh tests/android/wasm_apk_replay.sh ...`) to 78,840 frames: the macOS app's
  records from the same pack (60,030 frames) are a byte prefix of Android's. The emulator's Vulkan device is llvmpipe
  (CPU; it has BC), so Vulkan runs there take ~17 frames/s.
- **BC textures** (the game's DXT and a baked pack's BC1/BC3): bgfx's Vulkan and GLES renderers take a format the
  device lacks through `getViableTextureFormat`: decoded to BGRA8 on the CPU at upload (4x the memory of BC3, 8x of
  BC1), no change in the sink. Mali and PowerVR Vulkan drivers report no `textureCompressionBC`, recent Adreno ones do
  (public capability reports; no hardware here): on Mali handhelds every texture takes that path. A transcode to
  ASTC / ETC2 is the open user decision.
- **Open**: the gamepad path is untested (the emulator has no gamepad device; SDL maps a handheld's built-in controls
  through SDLControllerManager); lifecycle (pause / resume, the surface lost on home); performance on hardware.

## Status

- 2026-11-22 (wr2, D236 item 4): **Far Field (experimental)**: a prototype of remaster.md 3.3 (4) as a runner pass
  (docs/far-field.md): the game's room buffers are matched to the disc's rooms by vertex position, and the rooms it
  does not draw beyond the draw distance are drawn from the disc. Off by default; records unchanged with it on.

- 2026-11-22 (wand1): **the Android app** ("The Android app" above): the same module on arm64 Android 12+ through
  wasm2c and the NDK, bgfx Vulkan / GLES, a gamepad-driven disc chooser; play3 records byte-identical to the macOS app's.
- 2026-11-22 (wr2, D236): **Mipmaps, Anisotropic Filtering, Anti-Aliasing** (Video Options) and the runner's pass
  interface ("Renderer options and the runner's passes" above); the texture packs' disk cache. Remastered defaults:
  Full, 16x, MSAA 4x. Checkpoint records unchanged with every option on; play3 with `null` identical to the control.

- 2026-11-22 (wvid1, D234/D235): **Aspect Ratio, HUD Frame, Draw Distance, Fog** (Video Options; "Aspect ratio, HUD
  frame, draw distance and fog" above). 16:9 is the game's own widescreen and changes the simulation from ~1,000
  gameplay frames in; draw distance keeps every checkpoint tag but moves render bookkeeping in the game hash; both
  are per-session settings that replays and tests pin to the original. `HULK_ROLLTEST` with Metal identical at
  16:9 + Screen Edges + Very Far + Reduced fog + 60 fps (6500:7600 in gameplay, 1200:2500 across the load) and at
  21:9 + Far (6900:7500). play3 to 60,000 with `null`: records byte-identical (prefix) to the 08a213c72 user app.

- 2026-11-22 (wopt1, D232/D233): **Video Options and Gameplay Options; the remastered edition; render resolution.**
  Options (front end and pause menu) has two new screens built from one settings table (port_settings.c): Frame Rate
  and Render Resolution in Video Options, Remastered Edition in Gameplay Options ("Settings and the remastered
  edition", "Render resolution" above). Render resolution is output only (1x vs 3x: byte-identical checkpoint
  records); rolltests identical at 3x (4300:6300) and across a menu change of the resolution (3250:3400); play3 with
  `null` unchanged by the menus (with and without the overlay: identical records). The front end's text is visible
  again on the port builds (dd2d265b0).

- 2026-11-22 (fps2, D228a): **the game state is the same at any display rate.** The simulation always steps at the
  original's rate; 60, 120 and the display's refresh draw interpolated frames between updates in the runner ("Display
  rates by interpolation"). The same `HULK_INPUT` run (8,000 frames through the front end, the load and 4,200 frames
  of walking, jumps and attacks) with Metal at 30, 60 and 120 gives the same game hash at all 800 checkpoints (every
  10 frames). Paced: presents 60.0 / 120 / 75.0 fps (a 75 Hz display) with 30.0 updates a second in gameplay. Draws
  matched between updates: 99.1-99.5%, 0.2-0.3% drawn unchanged after a jump, 0.5% unmatched; two camera cuts in 4,800
  updates (the game's start and one cut-scene cut). Input to the first present that shows it: about 2 ms at every rate;
  to the update's own frame: 2 ms at 30, 16.7 at 60, 24 at 120, 23.7 at 75 Hz. Cost: matching 0.04-0.07 ms an update,
  re-submitting a stream 0.4-0.65 ms of CPU a present; the GPU 0.34 ms a frame at 30 and 60, 0.44 at 120
  (640x480).
  `HULK_ROLLTEST` with Metal at 60 identical (900:2500, 3700:4200 across the load, 4300:6300). play3 to 60,000 with
  `null`: records byte-identical (prefix) to HEAD's headless build. fps1's one-field step at 60 is gone.

- 2026-11-22 (wmov1, D231): **movies with picture and sound, hold B to skip.** The start-up movies, the attract loop
  and the cut-scenes play in the app in real time ("Movies" above): FFmpeg's Bink decoder loaded at run time,
  the sound on the app's mixer, B held for a second skips any movie with a ring in the corner. Free runs with the same
  `HULK_INPUT` through a skip end in the same game hash with and without a CPU hog; rolltests across a movie
  (100:160) and across a skip (110:200) are identical; play3's records to 60,000 are unchanged (app with `null` and
  with Metal, against the build without the change).

- 2026-11-22 (fps1, D224): **the frame-rate option.** "Frame Rate: 30 FPS / 60 FPS" in the options and pause menus
  (camera options), saved in port_settings.txt, 30 by default ("The frame-rate option" above). play3's records
  unchanged; gameplay at 60 keeps the speeds and timings of 30.

- 2026-11-22 (wroll1, D225/D227): **rollback and determinism with graphics.** In the app with Metal, `HULK_ROLLTEST`
  round trips re-simulate identically in the front end (900:2500), in gameplay (1500:1800, 1500:2500) and across the
  PRESSSTART -> GAME load (1200:2500, also with `null`); the frames after a restore are pixel-identical to a run
  without it (screenshots at 1201..2490). A restore costs 2-3 ms (state) plus 0.05-0.4 ms (GPU objects). Free runs
  with the same `HULK_INPUT` paced at 30 fps (95 s) and unpaced under a CPU hog (5.8 s) end in the same game state.
  A rolltest across a frame-rate menu toggle (4000:5200, toggle at 4800) restores the setting and the pacing with
  it. play3's records are byte-identical to HEAD's (headless, the app with `null` and with Metal).

- 2026-11-22 (waud1, D222): **one deterministic audio model.** Free play's voices run on the virtual clock (48 kHz of
  game time) in dsound_null.c, and the app's mixer renders what the model played instead of answering the game's
  reads. Free runs of the app with the same `HULK_INPUT` paced at 30 fps (96 s) and unpaced under a CPU hog (9 s) give
  the same game state (the previous build's differed in 1.38M words); with Metal the game hash can still differ in
  the pddi front end's objects' pointers into the module's own malloc heap (above 1 GB: host history, e.g. a log
  line, moves them; every differing word was one). `HULK_ROLLTEST` round trips (headless 1500:1800 and
  900:2500 across a load; the app with `null` and the mixer on, 1500:2000) re-simulate identically. In gameplay the
  game clock keeps to real time (35.01 s / 35.01 s, rate within 1.0005, no starved device). play3's records are
  byte-identical (replays keep the DoWork clock; with `HULK_DS_CLOCK=time` play3's sound tag diverges from frame 586).
  Open: rollback with the Metal renderer traps after a restore (the front end's statics: not audio's); the
  mirror's resync is byte-granular (an ADPCM voice can sit a frame from the model after a restore: output only).

- 2026-11-22 (wapp1, D190, milestones 2-4): **gameplay renders, input, audio, the bundle.** A free run driven by the
  real keyboard path (`HULK_KEY_SCRIPT`: Return / Space through press start and the difficulty menu, then W) reaches
  GS_GAME at frame ~1,000 and moves the Hulk; presents hold 30.0 fps in gameplay (worst 34 ms) and up to 60 in press
  start; the mixer's capture (`HULK_AUDIO_CAPTURE`) has sound throughout (RMS 1,200-4,500 over 10 s windows, front end
  and gameplay). play3 replayed with Metal (`HULK_GFX_SHOT_GAME`) shows gameplay with its HUD and effects. **play3 to
  60,000: the headless build, the app with `null` and the app drawing with Metal all write the same records** (the
  dsound hooks are null outside the app's free play). Open: a human play session, rollback with graphics (GPU objects
  after a restore), the front end's statics outside the snapshot, Bink movies (null: black), FPS beyond 30.

- 2026-11-22 (wapp1, D190, milestone 1): **the app draws.** `HULK_WASM_GFX=1` with its own `HULK_WASM_DIR`:
  `wasm_port.py compile --only src/platform/xbox/pure3d/d3dDevice.cpp src/game/Render/Canvas/HulkShaderCallback.cpp`
  (the two TUs the gfx hooks change), `wasm_gfx.py compile` (the 14 front-end units, llvm-linked into one IR module
  and bound once, so a vftable naming another unit's method gets a dispatch entry), `wasm_port.py link`, `aot --app`
  (`HULK_APP_SDL`: an SDL3 install with video; the cmake line is build_host's with `-DSDL_VIDEO=ON -DSDL_OPENGL=OFF
  -DSDL_OPENGLES=OFF -DSDL_VULKAN=OFF`). The front end needs bx's scalar SIMD and mingw-w64's math without x87 asm
  (`-U__SSE2__ -U__SSE__ -D__CRT__NO_INLINE`). `hulk-app` opens a Metal window and renders the legal screen, the front
  end's menus and Press START at 640x480 (scene target + frame-buffer copy); the present of each frame ends the frame as
  d3d_null's Swap does (`hulk_wasm_gfx_frame_end`, sdl_platform.cpp under `HULK_PDDI_WASM`). **play3 to 60,000: the
  app with `HULK_GFX_RENDERER=null` and with the front end on bgfx's noop renderer both write records byte-identical to
  the headless build of the same tree** (the front end changes nothing the game reads). The SDL-layer switch
  (`HULK_PDDI_LAYOUT64` = native and not wasm) leaves the Wine image's pddi objects byte-identical (D194: all 16 i686
  objects compared, COFF time stamps aside). Open: input, audio, the vblank flag's frame rate (presents are paced at
  30 in the front end), the .app bundle (milestones 2-4 below).

- 2026-11-22 (wasmq, D217): **qsort orders equal elements as the Xbox CRT does.** crt.c's 0x00345f90 is
  src/platform/sdl/crt/hulk_qsort.h, written clean-room from the XBE qsort run as a black box (docs/qsort.md;
  tests/test_qsort_xbe.py compares comparator call sequences and permutations). wasi-libc's qsort had left
  ItemQueue's (0x001cbfe0) equal-priority events in another order from frame 2733, and actors diverged at 3810. play3 to 60,000
  frames (41 s): camera 5875-5925 (the reference's known transient window), then the first lasting divergence at
  camera 10196 / rng 10198 (hulk 10396, actors 10410).

- 2026-11-22 (wasm14, speed; D218): **-O1 is the default** (`HULK_WASM_OPT=O0` for the old build). The profile of the
  compiled -O1 build on play3 (macOS `sample`) had the arena allocator's first-fit scan from the arena base at about
  30%, and softx87's transcendentals (trigImpl, atan2F and the fmul/fadd/fdiv under them) at about a third. Two host
  changes, each giving byte-identical play3 checkpoint records: (1) `arena.c` keeps a bound per size class (2^k):
  no free block of that size or more lies below it (`SIM->arena_lb`, game state like the rest of the allocator's). A
  search starts at its size class's bound and is still first fit in address order, so the addresses are the same. (2) `x87.cpp` puts a 4,096-entry direct-mapped table in front of each double-argument
  transcendental (sin, cos, tan, atan, atan2, exp, log, log10, pow, asin, acos): the same argument bits give the
  same result, and the tables are the host's, not game state. play3 to 60,000 frames, compiled: 70 s -> 43 s (a
  single lowest-free hint) -> 27 s (tables) -> 26 s (bounds per size class); about 5,700 update frames/s from frame
  24,000 on, about 1,100 over the first 12,000, where softx87's sin/cos/atan2 series (table misses) and the
  indirect-call dispatch lead the profile. Snapshot /
  restore of the 26.5 MB state: 0.68 / 0.62 ms. The four TUs of `tools/wine_opt_exclude.txt` are optimised on wasm too
  (`HULK_WASM_OPT_EXCLUDE=FILE` keeps a list at -O0): with them at -O1, play3's records stay byte-identical.
- 2026-11-22 (wasm15, speed): softx87's `fdiv`/`fdivu` divide in 32-bit digits (Knuth's algorithm D) instead of
  bit by bit, with the same quotients: play3's first 12,000 frames 21.1 -> 18.1 s on studio, records byte-identical
  (Wine pair 111481/111483, GATE ok).
  The arena's first fit starts at a bound per exact size up to 1 KB (`SIM->arena_lbn`, beside the per-class
  bounds): the same addresses, 17.8 -> 17.3 s.
  fdivu in three divisions (48/48/32-bit digits, the same quotients): 17.3 -> 16.7 s (Wine pair 111487/111488).

- 2026-11-22 (wasm14, -O1 vs -O0): **locals start as zeros** (`-ftrivial-auto-var-init=zero` in the front end;
  `HULK_WASM_ZEROINIT=0` turns it off). This is a deliberate difference from the Xbox, where an uninitialised local
  holds whatever the stack held. Game code copies uninitialised locals into heap records (4,096 0x40-byte records at
  frame 1). At -O0 that garbage comes from the shadow stack and moves with every frame's size: making only LoadStream's
  0x265210 -O1 (16 bytes less frame) shifted it by 16 bytes. At -O1 the locals are wasm locals and read 0. With zeros,
  the -O0 and -O1 game hashes at frame 1 differ in 96 bytes instead of 262 KB, and the -O1 hash is unchanged. play3 on
  -O0 keeps every tag's first divergence (actors 3810, camera 5875, rng 9484, ...). The 96 bytes were a source bug:
  the sprite constructor 0x2be440 passed 0x2bdaf0 a five-word rect, and 0x2bdaf0 reads six words (u from +0x14, the
  original's spill of the column width). With six words, -O0 and -O1 give the same game hash at frame 1, and some
  sprite u values that were 2.0 or 8.0 are now below 1. Bisect tools: build/wasm14/scripts (a TU prefix search over
  mixed links, and a per-function search that marks a TU's -O1 functions `optnone`).
  **-O1 now plays play3 exactly as -O0**: the same checkpoint records over the whole run (byte for byte to frame
  60,000; first divergence from the reference actors 3810 in both). Before that, -O1 left play3 at frame 672 (rng):
  Render::Object::vfunc_6 0x1c4e00 copies its sixteen int parameters with `memcpy(this + 0x30, &a0, 0x40)`, x86's
  argument block. On wasm each parameter's copy is its own local; -O0 happened to lay them out in a row, -O1 did not.
  wasm_port's `fix_param_block` now gives every function that lets a parameter copy's address escape one block of
  x86-laid-out slots for its stack parameters (156 functions, most with by-value vectors). play3 to 60,000 frames:
  -O0 86 s (1,273 update frames/s at the end), -O1 70 s (1,771).

- 2026-11-21 (wasm3, play3): `-O0` is the default build again (`HULK_WASM_OPT=O1` for the optimised one: its game hash
  differs from frame 1). play3 on the compiled build runs all 60,000 frames (about 2,000 update frames/s, 31 s) and
  matches the reference on every tag but sound* (an observable) to frame 445; the first divergence is the gameplay
  RNG at frame 446 (the reference draws 6 numbers in frame 445, the wasm build 4: CAmbientsManager's spawn search
  0x7a420 finds no active cell). flow matches to 8,586, clock to 3,870, mission to 3,780.

- 2026-11-21 (wasm2, optimised game code): the game's TUs were compiled as clang -O0 emits them (`optnone` on every
  function). The front end now runs as the Wine build's opt1 (`-O1 -Xclang -disable-llvm-passes -fno-strict-return
  -fno-finite-loops -fno-builtin`; the IR keeps -O0's shape for bind_tu) and the back end's -O1 optimises; the four TUs
  of `tools/wine_opt_exclude.txt` stay -O0 (`HULK_WASM_OPT_EXCLUDE`; `HULK_WASM_OPT=O0` builds everything as before).
  After START: node 1,500 -> 4,900 frames/s, compiled 3,500 -> 6,300 (idle screen: compiled 10,000 either way).
  Snapshot / restore unchanged (0.69 / 0.66 ms compiled). `-fno-builtin` leaves `memmove` a call to the game's CRT
  (0x345130, now a host function).
  **The -O0 and -O1 builds are not the same game yet**: the *game hash* (the state without the stacks, the Asyncify
  buffers, the fiber contexts and the continuations, whose bytes depend on code generation; `HULK_GAMEDUMP=PATH`
  writes those bytes) differs from the first frame (vertex-like floats 0x3f7f80xx at -O0 vs 0x4a7e00xx at -O1, and
  12,288 MemoryHeapSlot-like records at -O0 that are zeros at -O1). A prefix search over the TUs (a mixed link per
  step) found `src/engine/content/LoadStream.cpp` first, but with only it at -O0 the hash is still -O1's, so several
  TUs take part; the semantic checkpoints (play3's ckref) are the gate that decides, not this byte hash. The same
  build gives the same game hash under node and compiled (to 20,000 frames with START presses); the full state hash
  also depends on the environment's bytes (the C library's heap: host pointers reach dead stack bytes).

- 2026-11-21 (wasm2, the standalone module): the C-driven scheduler, setjmp/longjmp and the wasm2c build. Update
  frames/s (no rendering), idle screen / after START: node (V8) 6,800 / 1,500; compiled (wasm2c, clang -O2, arm64)
  10,000 / 2,200, and 3,500 after START once the indirect-call dispatch became a hash table (it was a binary search
  over 28,000 entries, 35% of the compiled run's samples). Snapshot / restore of the 27 MB state (memcpy): node 0.74 /
  0.70 ms, compiled 0.70 / 0.66 ms. Same state hash under node and compiled, run to run, and with or without
  reporting. The game's code is still compiled as clang -O0 emits it (`optnone` on every function): the next lever.

- 2026-11-21 (milestones 2 and 3): the game boots under node to its main loop (CGame's tick 0x87940 -> 0x86cb0 ->
  the render manager 0x1b93a0 -> Swap) and presents frames on the null renderer: 20,000 frames run without a stop.
  Two runs give the same state hash at frame 10,000 (the image's data, the game stack, the sim block and the arena:
  26.9 MB). Under node (V8's JIT, Asyncify build): about 5,000-6,000 frames/s in the steady state (3,100 frames/s
  over the first 10,000 frames, start-up included); a full snapshot of the state (memcpy) 1.2 ms, a restore 1.0 ms.
  Which screen the game shows is not checked yet (no renderer). What it took after the first frames: the
  anti-piracy sector size, this-adjustor thunks (17 blocks), `inalloca` blocks as `byval` (laid out where x86 has
  them, so a caller that declares the arguments one by one meets them), the TU's `// equiv-map:` hints for names the
  map lacks, a time slice for threads that poll the clock, a 1 GB arena and resources freed at their last Release.
- 2026-11-21 (wasm2, devirtualized calls): clang calls a virtual method directly when it knows the object's type (a
  member object, `drive->b.v0()`); cl 7.1 calls through the vftable, and the object's real class is one the source's
  stand-in doesn't show. `devirt()` finds such callees (a virtual method's MS mangling, not defined in the TU, not
  bound by the map, an `// equiv-map:` hint or its name), appends a probe per method to the TU (`p->m(args)`,
  compiled as the virtual call it is, cached in `build/wasm/devirt/`) and sends the calls there: 31 methods in 24
  TUs. With START pressed (`HULK_INPUT`) the game now leaves the idle screen and runs on (20,000 frames, no stop;
  about 1,400 frames/s under node after the press, 6,900 before it). Still open there: it opens
  `D:\\sound\\scripts\\(null).obj` (a name that comes out null).
- 2026-11-21 (milestone 2, first part): under node the game runs its 457 static initializers, main, the platform
  and content start-up (threads, the loader fiber, the RCF mounts) and presents frames; it stops in the World's
  set-up (0x00088670 -> ... 0x00272fc0, a memory fault). Found on the way: XGetDiskSectorSizeA("D:\\") must be 2048
  or the game shows TBS_STOP_PIRATING forever; the Xbox gamma ramp is 768 bytes; the vblank callback 0x31acc0 has no
  tree block (a stand-in in missing.c).

- 2026-11-21 (milestone 1): all 2,520 tree TUs compile to wasm32 objects and link (`hulk.wasm` 11.5 MB, 37,167
  generic entries, 63 thunks). Calls: 15,193 packed (declaration differs from the definition), 12,424 indirect, 3,064
  library. The host's work list: **252 unbound generic entries** (CRT/XAPI in .text 123, D3D 77, DirectSound 18, Bink
  12, XGraphics 10, XInput 9, game 3) and 506 named stubs (mostly implicit destructors of stand-in classes the map
  has no address for). Under node the XBE loads and the first static initializer runs into `atexit`, the first host
  function to write.
