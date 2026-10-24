# Native build: arm64 macOS (x64-3, 2026-10-24)

The first native (64-bit) build of the tree: arm64 macOS, linked by ld64 against SDL3 and the platform layer, no
Wine. Roadmap step 6.2/6.3 ([roadmap.md](roadmap.md#6-wine-build-then-native-builds-in-progress)); the 32-bit clang
image under Wine is the [Wine build](wine-build.md), whose 64-bit probe (x64-1) this builds on.

```sh
PY=build/venv/bin/python
$PY tools/native_mac.py compile [--jobs N]        # every tree TU + data TU -> Mach-O arm64 objects (build/native-mac/)
$PY tools/native_mac.py report                    # failing TUs, 64-bit diagnostics
$PY tools/native_mac.py sites                     # 64-bit diagnostics per verified source (sites64-src.jsonl)
$PY tools/native_mac.py link --bindings B.json [--ld]   # link inventory: the 32-bit binding map as a name table
$PY tools/ptr_fields.py scan --out F.jsonl && $PY tools/ptr_fields.py summary F.jsonl   # pointers punned through int fields
# on another tree: HULK_CLANG_PROBE_DIR=<dir with snap/> (clang_probe.py --snapshot of a complete build_tree run),
# HULK_NATIVE_MAC_DIR=<out>; HULK_NATIVE_MAC_SHARD=k/n compiles every n-th TU from k (queue jobs)
```

## 1. The ABI: MS C++ ABI on arm64 macOS

The tree is MSVC code: MS name mangling, MS vftables (one scalar deleting destructor slot; the sources call slots
by number), `long` is 4 bytes and `wchar_t` 2 bytes in its records, and the Wine build's binding map, RTTI handling
and stub-vftable aliases are all in MS terms. clang only allows the MS C++ ABI on Windows triples, so
`native_mac.py` compiles each TU in two steps:

1. front end for `aarch64-pc-windows-msvc` (LLP64, MS ABI) to LLVM IR, with the Wine build's dialect flags
   (`compat/native.h`, `-fno-strict-aliasing -fwrapv`, no wchar keyword, ...), `-fcheck-new`, `-ffp-eval-method=double
   -ffp-contract=off` and clang_probe's `W64` warnings;
2. the IR retargeted to `arm64-apple-macosx13.0` (`retarget()`) and compiled to a Mach-O object. The AArch64 code is
   the same; what changes is the object format and the platform's calling details (both sides of every call are
   compiled the same way, so they agree; `va_list` is a `char*` on both platforms).

The retarget: triple and datalayout (`m:w` -> `m:o`); COMDATs dropped (the members are `linkonce_odr`/`weak`, which
ld64 coalesces); each MS vftable (a private `{COL, slots}` with the vftable symbol an alias at +8) becomes a named
`linkonce_odr` global `<vftable>$rtti` with a `linkonce_odr` alias, so one class's vftable is one address across
TUs; RTTI's 32-bit image-relative offsets (`x - __ImageBase`, which Mach-O cannot relocate against an undefined
symbol) become offsets from the descriptor holding them, which the host side's `__RTDynamicCast` has to read that
way; `dllimport`/`dllexport` and Windows linker options dropped. Prototype programs (virtual calls across TUs,
deleting destructors, `dynamic_cast` reaching `__RTDynamicCast`) link with ld64 and run.

Why not Itanium (`arm64-apple-macos` directly): every vftable with a virtual destructor gains a second slot
(complete + deleting destructor), shifting the slots the sources call by number; `long` becomes 8 bytes (LP64) and
`wchar_t` 4; the mangled names, and with them the 32-bit link's whole binding map, change form. x86-64 Windows will
use the same front end without the retarget, so the two 64-bit targets share names and layouts.

arm64 macOS refuses executables with a `__PAGEZERO` below 4 GB (the process is killed at exec), so every pointer
is above 4 GB: a pointer kept in a 32-bit integer is always fatal at run time, never latent.

## 2. Compile (milestone 1)

Tree of HEAD 4f50d9dbc (Wine control build 16277's snapshot): **2,620 / 2,627 tree TUs and 1,078 / 1,078 data TUs
compile to Mach-O arm64 objects.** The 7 failures were pointer-size declarations; with the 9 source fixes below the
tree of Wine build 16555 compiles **2,627 / 2,627** (and 1,078 / 1,078 data TUs). Every fix leaves the MSVC 7.1 object
identical (`tools/ptr1.py proof`), and Wine build 16555 (HEAD + the fixes) equals control 16277: same tree state,
22,340 / 22,340 matches, identical image and play3 checkpoints to frame 1020.

| TU | cause | source fixed |
|---|---|---|
| `FEThingsBase_2.cpp` | pads `char padA[0x54 - sizeof(base)]` negative with 8-byte pointers | equivalent/0x000eff20 |
| `GameStateCondition.cpp`, `AcquireTargetTrack_2.new_plain.cpp` | the allocators `FUN_0008d6d0` / `FUN_0008d690` declared with `size_t` and `unsigned int` in one TU: two overloads on 64-bit, calls ambiguous | equivalent/0x0012ece0, 0x001285a0 |
| `unk_338d90.cpp` | `FUN_00213360` (lua_pushnumber's int) declared with `hulk_intptr` by three sources (a pointer difference passed to it) | matches/0x0033acd0, equivalent/0x0033a080, 0x0033cb70 |
| `SemaphoreWaitTrack_3.iso_00112060.cpp`, `unk_1899a0.iso_00189ba0.cpp` | placement `operator new(unsigned int, void*)` | equivalent/0x00112060, 0x00189ba0 |
| `unk_240c20.cpp` | `extern "C" _alloca(unsigned int)` | equivalent/0x002411b0 (held back: its `--wine` check fails on HEAD as well, identically) |

## 3. Pointer-size inventory

| class | count | where / what removes it |
|---|---|---|
| pointer <-> integer casts (`(T*)i`, `(int)p`), `W64` | 1,240 sites in 1,177 sources (1,255 int -> pointer) | ptr1's remaining reasons: 1,016 parameters of stub virtuals / header functions (class hierarchy, b9-b13), 198 register-emulation arrays, 171 derefs, 160 indexed pointer vars, 159 args of virtual/overloaded callees, 48 fields |
| implicit 64 -> 32-bit truncations, `W64` | 672 sites in 311 sources | mostly `hulk_intptr` values meeting 32-bit callees/fields (the cast made visible) |
| pointers punned through 4-byte integer fields (`*(T**)&p->f_20`): no diagnostic | 277 sites, 139 fields; 132 in include/gen/ (pointer-only uses) | the field's type in tools/gen_headers.py (`hulk_intptr`/pointer): list in build/x64-3/ |
| byte offsets `(char*)p + 0x24` | 3,456 sites in 1,631 sources | typed fields |
| stub `char pad[N]` at 32-bit offsets / include/gen `_pad_` | 25,476 in 3,456 sources / 820 (x64-1) | consolidation (rn batches) |
| literal allocation sizes (`FUN_0008d690(0x18)`, `operator new(0x54)`) | 498 `operator new(N)` in 496 sources; `FUN_0008d690(<literal>)` 3,194 | `sizeof(the class)` where the source declares it (done for 0x000eff20) |
| pointer variables bound (name table) to 4-byte data items | 621 (+65 not 8-aligned) of 937 | data_gen: an item that holds a pointer at run time is pointer-sized and aligned on 64-bit |
| packed `DataLayout_` data with pointers at 4-byte offsets | 274 unaligned pointers in 26 items (ld64 warnings) | typed data structs (data.md) |
| on-disk records | 2 raw records (RCF entry, texture header), asserted by `layout64.py --check`; P3D reads field by field | none open |

## 4. Link inventory (milestone 2, started)

`native_mac.py link` uses the Wine build's binding map (`build/native/bindings.json` of the same tree) as a
**name table** (names -> XBE address -> the tree's definition name, translated to 64-bit names by demangled form;
no game bytes) and emits an ld64 `-alias_list`. On the 3,698 objects: 56,063 undefined symbols (60,507
references); **37,416 bound** by the name table; unbound: 8,296 bound to library code or data with no tree definition
(CRT/XDK by address: the host CRT table and the platform shim), 7,752 C++ names with no 32-bit binding (stub
members, dispatch stubs: the 32-bit link's slot aliases and stubs), 1,540 whose definition has no 64-bit symbol of
that form, 924 `FUN_` names, 87 C names, 42 data by address, 5 vftables. ld64 with every unbound symbol stubbed
reaches the final layout (8.9 MB image) and stops at the first data fixup of a pointer variable bound to a 4-byte,
4-aligned data item (the 621 above).

The name table is a link-time bridge of the kind listed in [wine-build.md "Bridges to remove"](wine-build.md#bridges-to-remove)
(callers' names bound by relocation position); on 64-bit it only names definitions, it carries no code or data.

## 5. The platform layer on 64-bit (x64-3, 2026-10-24)

**XDK shim interface.** `src/platform/sdl/xdk/xdk_shim.h` has `hulk_uptr`: `unsigned int` on the 32-bit builds (the
same word as `hulk_u32`, so the Wine build's objects are byte-identical: all 17 shim files, in the three ways
wine_link compiles them, checked with the COFF time stamp masked) and `__UINTPTR_TYPE__` on the native builds. Every
stand-in of imports.h (167; 135 of them carry a pointer-sized argument or result) and library.h (9), and the fs1 directory calls, take `hulk_uptr` for each argument that
carries a pointer, handle or address and return it for HANDLE / object results; integers (sizes, counts, flags,
HRESULT/BOOL/DWORD results) stay `hulk_u32`. The kind of each argument comes from the public Win32 / XAPI / D3D8 /
DirectSound shapes and the stand-ins' own use. Alongside: `HULK_INVALID_UPTR` (INVALID_HANDLE_VALUE at handle width:
the shims returned `0xffffffff`, which a 64-bit caller would not take for -1), `HULK_OFS(o32, o64)` for fields of
records the game hands over (DSBUFFERDESC's format and mix-bin pointers at 16/24, DSMIXBINS' pairs at 8,
OVERLAPPED's offset words at 16/20 with pointer-sized Internal/InternalHigh), pointer-sized object out-parameters
(`IDirectSoundBuffer**`), and our file/save handles narrowed explicitly (`fh()`: they are small tagged indices). With
`-Wshorten-64-to-32` and the pointer/int cast warnings, the aarch64 compile of the directory is clean except two
files that stay 32-bit by design: `startup.cpp` (the Windows entry point, crash report from x86 CONTEXT records) and
`replay_hooks.cpp` (the replay pins: game objects at 32-bit offsets and the entry hooks' x86 register images, both
Wine-build bridges).

Left for the game side: records the game builds itself keep its sources' layout (the Bink I/O block's callbacks in
32-bit words, the XINPUT_FEEDBACK header with its event handle), noted at the sites.

**Win32 host functions on POSIX.** `src/platform/sdl/host/win32_posix.{h,cpp}` implements the kernel32 subset of
`crt/host_crt.h` that the shims call, for macOS and Linux: threads (pthreads; `CREATE_SUSPENDED` held on a gate until
ResumeThread; exit codes; SuspendThread / GetThreadContext refused), semaphores, events (auto and manual reset, which
host_crt.h lacked), `WaitForSingleObject` on all three with timeouts, critical sections (a recursive mutex behind a
pointer in the caller's storage), fibers (an own context switch in assembly for AArch64 and x86-64 System V, mmap'd
stacks with a guard page), files (the five dispositions, read/write with OVERLAPPED offsets, SetFilePointer with the
64-bit high word, size, truncate, attributes, directories, free space), last error, QueryPerformanceCounter
(nanoseconds), GetLocalTime and VirtualAlloc. Not linked into an image yet. `tests/native_host/host_test.cpp`
exercises all of it (command line in the file): passes on arm64 macOS at -O1/-O2 and under ASan+UBSan, and as x86-64
under Rosetta.
