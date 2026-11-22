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
`HULK_INPUT="3000-3010:10,..."` holds pad 0's buttons (wButtons, hex) over frame ranges, `HULK_SNAPTEST=1` times a
snapshot and restore of the state at the end.

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

## Status

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
