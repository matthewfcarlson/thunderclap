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
`wasm-opt`, or `HULK_WASM_OPT`) and, for `aot`, wabt's `wasm2c` (`brew install wabt`; `HULK_WASM2C`).

**Inputs.** A clang_probe snapshot of the tree (`HULK_WASM_SNAP`, default `build/wasm/cp/snap`: the output of
`tools/tree_tu.py materialize` copied by `tools/clang_probe.py --snapshot`; manifest.json and report.json give each
TU's blocks and their pinned symbols) and the Wine build's binding map of the same tree (`HULK_WASM_BINDINGS`,
default `build/wasm/maps/bindings.json`: which XBE address each name the tree references means). Nothing in the tree
changes for the build; the outputs stay in `build/wasm/` (a module built from the game is derived content: never
committed).

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
