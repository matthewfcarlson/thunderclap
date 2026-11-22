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
  compile`, `wasm_port.py link`, `aot --app`), `wasm_app.py bundle` (build/app/Hulk.app: not signed or notarised;
  nothing built from the game is published or committed). Started from Finder the app reads the extracted disc from
  ~/Library/Application Support/HulkUD/disc and keeps saves in .../HulkUD/save; `hulk-app default.xbe` (with
  `HULK_DATA_DIR`) as the other runners. Input: SDL3 gamepads and the keyboard as pad 0, merged when a gamepad is
  there (docs/native-play.md's map; `HULK_KEY_SCRIPT` holds keys for unattended runs).
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
- **The item.** "Frame Rate: 30 FPS / 60 FPS", the fourth item of camera_options in the front end's options and in the
  pause menu (Options > Camera Options). The menus are game data (misc.rcf: frontend\fe_real.txt, fe_run.txt, the
  strings in frontend\lang\str_*.txt); src/platform/wasm/gfx/fe_options.c serves misc.rcf through an overlay that
  appends patched copies of those three files from the player's own disc (located by anchors at run time, the
  directory entries pointing at the copies) and holds only the inserted item and its three English strings. Three
  entry hooks (`wasm_port.GFX_APP_HOOKS`, app builds only) connect it: 0x000df9e0 (the int-callback lookup:
  "PortFrameRateChanged" is a host handler, a vftable slot made by `ff_host_method`), 0x000f8e70 (NamedValueInt's
  Create: "PortFrameRate" starts at the saved value; one object per front-end slot, kept in step) and 0x000b5ad0 (the
  camera selectors' sync on front-end set-up and pause: ours shows the setting; a selector shows its first choice
  until code sets it). `HULK_FE_OPTIONS=0` serves the disc's archive unpatched; `HULK_FE_OPTIONS_LOG=1` logs the item.
- **The setting** is saved in `HULK_SAVE_DIR/port_settings.txt` (`frame_rate=60`), not in the game's save. At 60,
  gfx.c's frame end moves the virtual clock one field a present in gameplay too, and sdl_platform.cpp's pacing
  (`hulk_wasm_fps60`, `HULK_PDDI_WASM` only) presents at 60. `HULK_FPS_CAP=60` still forces 60 without the menu.
  Replays ignore the file and never write it (the recording's clock decides).
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
- **The option.** "Frame Rate: 30 FPS / 60 FPS / 120 FPS / Display" (fps1's item; `frame_rate=30|60|120|display` in
  port_settings.txt; 30 = no recording, today's path). "Display" presents at the display's refresh (vsync).
  `HULK_DISPLAY_FPS=30|60|120|display` overrides it in the runner without touching the menus. The setting is host
  state (not in a snapshot); the menu's own objects (the item's NamedValueInt and selector) show it, the only game
  words that depend on it.
- **Audio**: waud1's model advances by the virtual clock, which follows the fixed simulation step: unchanged.

## Status

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
