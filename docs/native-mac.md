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

**Entry point.** `src/platform/sdl/host/entry_posix.cpp` is the native builds' `main` (macOS, Linux), in place of
`startup.cpp`: the start-up trace (`HULK_TRACE_FILE`, the same line formats), the game's dynamic initializers in the
XBE's order from the table the native link will write (`hulk_game_initializers[]`, as startup.s), the replay start-up
hook and the atexit list (weak no-op defaults until the image has them), the game's main; a crash report on an
alternate signal stack (registers, frame-pointer chain, dladdr symbols), `hulk_native_missing` for the link's stubs,
and `HULK_HANG=N` (every thread's pc and frames from Mach thread states on macOS). The FPU is set to round to
nearest with denormals kept (the game's x87 word 0x027f has no other effect off x87). Not mapped, on purpose: the XBE
window (arm64 macOS has no address space below 4 GB for it). Open for the link: the tree objects' own C++ initializers
go to `__mod_init_func` on Mach-O, which dyld runs before `main`; the Wine build only counts clang's `.CRT$XCU`
entries, so the native link has to drop them (the XBE's table constructs those globals).
`tests/native_host/entry_test.sh` runs a stand-in game through the four endings (return, missing symbol, crash,
hang): passes on arm64, and as x86-64 under Rosetta.

**C runtime.** `src/platform/sdl/crt/native_crt_table.h` says what each row of the Wine build's `HULK_HOST_CRT`
(every library function the game reaches by XBE address or by name) and the rest of `compat/crt.h` become on the
native builds: 67 rows go to the host's libc as they are, 31 to glue, 28 math rows to soft-intrinsics' x87 routines
(`softx87.h`: the 13 functions it provides and their float variants; host libm with `-DHULK_NO_SOFT_X87`), 5 wait for
the ABI decision (RTTI: `__RTDynamicCast`, `__RTtypeid`, `type_info`; the MS exception tables) and 11 are x86 compiler
helpers (`_allmul`, `_chkstk`, ...) that 64-bit code never calls. The glue (`src/platform/sdl/host/crt_posix.cpp`):
`_snprintf` / `_vsnprintf` (no NUL when full, -1 on truncation), `rand` / `srand` (the C runtime's LCG, seed 1 per
thread: replays hash its sequences), per-thread `strtok`, 16-bit `wcslen`, `strtol` / `strtoul` / `labs` at the game's
32-bit `long`, `_strlwr`, `_isnan`, `_ftol`, `_errno`, the zero-filling malloc, the stdio proxy for the game's `_iob`
and the `D:\` / `T:\` / `U:\` / `Z:\` path mapping, atexit, the /GS cookie, `_purecall` / `terminate` /
`_CxxThrowException` reports, and `_setjmp3` / `longjmp` in assembly (AArch64, x86-64) for the game's 64-byte jmp_buf
(the callee-saved state lives in a per-thread table keyed by the buffer address). `tools/native_mac.py crt` checks
the table against the Wine one (every address row and tree name covered) and resolves every target on the host (libc
by linking a reference to each, glue and math in the glue's object); `tests/native_host/crt_test.cpp` tests the glue
(arm64 at -O1/-O2 and ASan+UBSan, x86-64 under Rosetta, with and without softx87). Known differences left: `qsort` is
the host's (the order of equal elements can differ from the Xbox CRT's), and on x86-64 System V the game's `char*`
va_list (Windows-style IR) does not match the host's `va_list` for the v*printf glue (arm64 macOS: both are `char*`).

## 6. What the native Itanium ABI would cost (x64-3, 2026-10-24)

The alternative to section 1: compile the tree for `arm64-apple-macosx` directly (Itanium C++ ABI, LP64). Measured over
the merged tree of HEAD 122f16970 (Wine build job 18670's snapshot), same dialect flags as section 1, only the triple
differs. Scripts and data: `build/x64-3/itanium/abi_measure.py` (`dump`: per TU and target, `-fsyntax-only -Xclang
-fdump-record-layouts-complete` and `-emit-llvm -Xclang -fdump-vtable-layouts`; `analyze`: the comparison; ran as two
queue jobs, 18752/18753, 90 s each), `report.json` / `report.txt` beside it.

**Record layouts.** 121,197 distinct records (every complete class and struct of every TU); 2,620 / 2,627 TUs compile on
Itanium (6 fail), 2,625 on the MS triple (1: the held-back `_alloca` source). **3,492 records differ (2.9%), 2,933 of
them in size**; 1,826 of the 3,492 are source stubs (in a wrapped TU's `fn_` namespace), the rest header and merged
classes. Causes (a record can have several):

| cause | records | what it is |
|---|---|---|
| tail-padding reuse | 1,598 | Itanium places a derived class's first member in a non-POD base's tail padding (`CCharacter`: `pure3d::Entity` is 24 bytes with 4 of padding, `_pad_10` moves from 24 to 20 and every field after it with it) |
| member-pointer size | 1,106 (+124 through typedefs) | MS member function pointers are 8 bytes for single inheritance, Itanium's always 16 (`Closure`/`Method` families) |
| contains / derives from a differing type | 604 | knock-on |
| empty-base placement | 336 | MS gives an empty second base its own byte, Itanium overlaps it at offset 0 |
| `long` width | 22 | 4 -> 8 bytes |
| alignment / unclassified | 19 / 24 | |
| bitfields, virtual bases, `wchar_t` fields | 0 | the tree compiles with `-fno-wchar` and typedefs `wchar_t` as `unsigned short` |

How many sources touch them is only roughly measurable (record names to sources by name): sources naming an affected type
by its short name, an upper bound: tail padding 8,101 (2,723 of them with literal offsets `f_XX` / `(char*)p + 0x..`),
member pointers 4,746 (2,230), empty bases 798 (81), `long` 549 (71); any cause 10,281 (3,589).

**Vtables.** 11,565 polymorphic classes dumped on both targets: **1,208 (10.4%) have method slots shifted by one** (the
Itanium complete + deleting destructor pair against MS's single deleting destructor, `CAction::vfunc_3` 3 -> 4), 195 differ
only in the destructor entries, 10,162 are the same. Every Itanium vtable also starts with offset-to-top + RTTI (two
words) where MS has the complete object locator (one). Calls by raw slot index or vptr offset are rare in the sources
(35 sites in 26 sources), but the sources declare their stub classes' virtuals by position (82,814 `virtual`
declarations in 9,890 sources, 165 with a virtual destructor; include/gen has 1,511 virtual destructors): every stub
that stands for a destructor slot with an ordinary virtual, or leaves it out, calls the wrong slot under Itanium without
any diagnostic. 864 sources store vptrs by hand (`*(void**)this = ...`): those are MS vftable layouts.

**`long` and `wchar_t`.** 384 `long` / `unsigned long` sites in 127 sources, 44 record fields; the two pinned on-disk
records (`config/layout64.json`) have none. `wchar_t`: 35 sites (the type and `L""` / `L''` literals) in 7 sources: the
type stays 16-bit through the sources' typedef, the literals would become 32-bit.

**Names and tooling.** The native link's name table (the Wine build's 56,523 bindings, 37,416 of them usable on 64-bit:
section 4) works by demangled MS names; under Itanium it needs an MS-to-Itanium translation of every reference (by
demangled form; `long` and calling conventions spell differently). The 2,731 RTTI descriptor redirections and div1's
class-name fixes assume MS descriptor names; the stub-vftable slot aliases (fix 3a) assume MS slot numbering. 40 tools
parse MS-mangled names (130k lines), but the MSVC verification tools among them (compare, verify_relocs, equiv,
build_tree) keep working whatever the native ABI is: only the native link's (native_mac.py, the wine_link logic it
reuses) would have to be redone.

**Exceptions and RTTI.** try/catch: 1 source (1 try, 1 catch, 2 throw). `dynamic_cast` / `typeid`: 216 + 18 in 135
sources. `__RTDynamicCast` called by name or address with RTTI descriptor arguments: 1,200 sites in 561 sources. Itanium
would give libc++abi's `dynamic_cast`, `typeid` and exceptions for free for the 135; the 561 that call the MS runtime
function with MS descriptors need rewriting to `dynamic_cast` (or an emulation) under either ABI choice on macOS:
under the MS ABI we write `__RTDynamicCast` ourselves (section 4, the 5 `abi` rows).

**Estimate.**

| work for Itanium | size | kind |
|---|---|---|
| name table MS -> Itanium, link logic (slot aliases, RTTI, ambiguous renames) | 37k references, 1 tool | mechanical |
| `long` -> `int` or `hulk_long32` typedef in sources and headers | 384 sites, 127 sources | mechanical, MSVC-neutral (typedef), but every source re-proved |
| vtable slots: every stub whose virtuals stand for a destructor slot, every hand-written vptr store | 1,208 hierarchies, up to 9,890 sources, 864 vptr stores | per-source proof; silent when wrong (risky) |
| tail padding, empty bases, member pointers: field offsets that move only on Itanium | 3,492 records, a few thousand sources with literal offsets | needs real types first (the consolidation); then per-source proof |
| `__RTDynamicCast` callers -> `dynamic_cast` | 561 sources | per-source proof (needs real class names) |
| exceptions / RTTI runtime | 0 (libc++abi) | free |

Under the MS ABI on macOS the same tree needs: the retarget (done), our `__RTDynamicCast` / `typeid` reading the
retargeted RTTI (the 5 `abi` rows), and no exceptions runtime (the game throws in one source). Layouts and vtables are
then the same as on x86-64 Windows, so one layout family is verified for all three native targets.

**Recommendation: keep the MS ABI on macOS now** (section 1), and keep a migration open: the consolidation work that
64-bit needs anyway (real class types instead of pads and literal offsets, real destructors in include/gen, named data)
is exactly what makes the Itanium differences harmless, because a source that names its fields and declares its
destructors gets the right layout and slots from either compiler. Re-run `abi_measure.py` after the consolidation
batches; the numbers to watch are the 3,492 differing records and the 1,208 shifted vtables, and the per-source counts
with literal offsets. Switching while sources still address fields by MS offsets and slots by position would add a
second, silent layout family on top of the 64-bit one.

## 7. The MS C++ ABI runtime on macOS (x64-5, 2026-10-25)

`src/platform/sdl/host/rtti_msabi.cpp` is the run-time support the MS ABI objects need on arm64 macOS: the five
`abi` rows of `crt/native_crt_table.h` (`__RTDynamicCast` 0x00344e74, `__RTtypeid` 0x003449e4, `type_info::operator==`
0x00344913, `type_info::name` 0x003469f5, `__CxxFrameHandler3`), plus what clang itself emits for the MS ABI:
`__RTCastToVoid` (`dynamic_cast<void*>`), type_info's other members (`!=`, `before`, `raw_name`, the destructor) and
type_info's vftable `??_7type_info@@6B@`, which every type descriptor points at (1,179 references in the tree;
x64-3's unbound list had it as the largest "vftable" entry). Host code (Itanium C++, system headers), C linkage, the
MS-mangled names as assembler aliases. Written from the documented record layouts and the semantics of the
operations; no Microsoft code.

- **Records.** The 64-bit MS layouts (complete object locator signature 1, base class descriptors with their PMD
  and attributes, class hierarchy descriptors, base class arrays), with the retarget's one change: each 32-bit
  "image-relative" field is an offset from the start of the record that holds it (an array's entries from the
  array). `native_mac.py retarget()` also drops clang's `nuw` from those subtractions (the difference can be
  negative; with `nuw` the constant is poison).
- **dynamic_cast.** Finds the complete object (offset, and the vtordisp when the locator has one), then the
  source subobject among the bases (type and offset), then a target that contains it (down cast; the source must be
  a public base of the target, checked in the target's own hierarchy when it is not the complete object), else the
  one visible, unambiguous target base of the complete object (cross cast). A failed reference cast and typeid of a
  null pointer report through `hulk_native_missing` (exit 3): the native builds have no exceptions.
- **Type identity.** Descriptors compare by address, then by decorated name: one class can have clang's
  `??_R0` descriptor and the game's (below). A name that differs only by the tree's wrapping namespaces
  (`fn_<8 hex>`, tools/gen_tree.py: `.?AVCAction@fn_0001d1e0@@`) is the same class, which is what the Wine build's
  "RTTI TD redirection" bridge does at link time. Stubs renamed with a placeholder suffix (`CTrack_23d3d0`) are not
  matched: those wait for the consolidation (real class names), as in the Wine build.
- **type_info::name.** The undecorated name the MS runtime gives (`class fight::Track`, `struct ns::Tpl<int,3>`,
  `int`, `char const * __ptr64`), made once per descriptor and kept (a side table, not the descriptor's `spare`
  word, which the descriptors of other images may keep read-only). equivalent/0x0028fbc0 strips "class " and the scopes from it.
- **Exceptions.** One source has try/catch: matches/0x0035be90, whose original is an unwind funclet of
  `FUN_003a8296` in the XGraphics library section (its only reference is that function's EH table), so it is never
  reached on the native builds. `_CxxThrowException` (crt_posix.cpp) and `__CxxFrameHandler3` report and exit.
- **The game's type descriptors.** Sources pass the game's descriptors by address (`__RTDynamicCast(p, 0,
  &DAT_00491ca8, &DAT_004a3940, 0)`: 1,200 sites in 561 sources; `type_info::operator==` against `DAT_0048e100` ...).
  `native_mac.py link` writes them as 64-bit type_info objects (`link/rtti.s`: type_info's vftable, a null word, the
  decorated name from config/data.json's item name, no game bytes) under `DAT_<addr>`: 4,244 descriptors.

Test: `sh tests/native_host/rtti_test.sh [OUT] [host flags]` compiles `tests/native_host/rtti_game.cpp` the way the
tree is compiled (MS ABI front end, retarget, Mach-O) and links it with the runtime and `rtti_test.cpp`: single,
multiple and virtual inheritance (down, cross, to void), private bases refused, typeid of the complete object,
`name()` / `raw_name()` of classes, templates, enums and built-in types, descriptors of the game's shape (and wrapped
names) against clang's, and the two failures (bad_cast, bad_typeid) exit 3 with their report. Passes on arm64 at
-O1 and under ASan+UBSan. Not covered: a non-zero vtordisp (only during construction or destruction of a class
with virtual bases).

## 8. Pointer-sized virtual slots (x64-5 batch 1, 2026-10-25)

ptr1 (wine-build.md item 9) left the pointers that travel through `int` parameters and returns of virtual methods:
every override of a slot shares the signature, so no single source can widen it. `tools/ptr_slots.py` widens the slot
as a whole: from ptr1's per-source demands (`ptr1.py fix` without `--write`) it finds the include/gen/ slot
(gen_headers' slot keys), writes the widened signature to include/gen/evidence-rn.json "sigs" (`hulk_intptr` /
`hulk_uintptr` at the positions some override uses as a pointer, the return when some override returns one), and
rewrites the out-of-line definition of every override in every source on include/gen/. `check` parses sources for
the 64-bit MS target and reports new errors and `-Woverloaded-virtual` hits (an in-class override of a source's own
that would stop overriding on 64-bit, silently). MSVC 7.1 and clang i686 see `int` / `unsigned int`: objects and
mangled names unchanged.

```sh
build/venv/bin/python tools/ptr1.py fix @files --out FIX.json                  # demands (no --write)
build/venv/bin/python tools/ptr_slots.py plan FIX.json --out PLAN.json
build/venv/bin/python tools/ptr_slots.py apply PLAN.json --write --list CHANGED.txt && build/venv/bin/python tools/gen_headers.py
build/venv/bin/python tools/ptr_slots.py check @SOURCES --out CHECK.json       # before and after; compare errors
```

Batch 1: 113 demanded slots, 109 widened (4 refused: the header's slot returns `void` / `void*`), 1,686 sources
(1,566 matches/, 120 equivalent/), 11 headers; `gen_headers.CURATED_SIGS` `CAction::vfunc_5` widened too (curated
signatures win over evidence-rn.json). Per-source `ptr1.py scan` (msvc64), HEAD -> batch: pointer <-> integer casts
1,263 -> 268, 64 -> 32-bit truncations 499 -> 653 (casts that become visible narrowings further down, mostly
arguments of the sources' own stub members: batch 2, ptr1's `sigs` phase finds 173 sources), all sites 1,762 -> 921 in
1,343 -> 551 sources. The merged tree's native compile: pointer <-> integer casts 301, truncations 637 sites.

## 9. Link preparation without a name table (x64-5, 2026-10-25)

The names-only link table (the Wine build's binding map as an ld64 alias list) was rejected: names are unified in
the sources instead (x64-6). `native_mac.py link` therefore binds nothing by alias by default (`--name-table` keeps
x64-3's inventory for comparison) and reports what is unbound, by kind; that report is the metric. What it adds:

- **Initializers.** `retarget()` takes the TUs' dynamic initializers out of `llvm.global_ctors` (Mach-O's
  `__mod_init_func`, which dyld would run before `main` in link order) and gives each TU's own initializer the global
  name `hulk_tu_init$<tu path>`; the compile report lists them per TU. `link` writes `link/startup.s`:
  `hulk_game_initializers[]` in the XBE's order (`__xc_a`..`__xc_z`), each entry bound to the tree's own definition
  at that address (the tree build's report: our definitions by address, no callers' names), the TU's
  `hulk_tu_init$` for a game initializer whose source is the dynamic initializer itself (`_$E<n>`), 0 for library
  initializers; entry_posix.cpp runs them. Batch 1's tree: 453 bound to function sources, 4 to TU initializers, 9
  library ones left out, 2 TU initializers the XBE table never calls (`link/tu-inits-not-run.txt`).
- **Type descriptors.** `link/rtti.s` (section 7), 4,244, under `DAT_<addr>` and `rttiTD_<addr>`.
- **The native CRT table** classifies references by a row's tree names or by the XBE address in the name (300 + 74
  references); they are counted, not aliased: the host side or the sources have to use the names.
- **ld64.** With every unbound symbol stubbed (code as `brk`, data as 16-aligned zero blocks) and the MS ABI runtime
  linked, ld64 now links batch 1's 3,701 objects into an arm64 executable (26 MB; x64-3's attempt stopped at the
  first data fixup). Left: 274 "pointer not aligned" warnings, the packed `DataLayout_` data items (data_gen, next).
  Unbound (no name table): 56,625 symbols, 59,874 references: FUN_ by address 26,470, C++ names 25,286, data by
  XBE address 2,255, vftables 1,785, C names 403, RTTI descriptors 52.

## 10. Data items with real pointer types (x64-5, 2026-10-25)

The data TUs (`tools/data_gen.py`, [data.md](data.md)) now give every word that holds a pointer a pointer type, so it
is 4 bytes on the 32-bit builds and 8 bytes, 8-aligned, on 64-bit:

- **Which words.** The XBE's initialized pointers (as before) and the words the sources use as pointers at run time:
  zero in the XBE or in BSS, so only the code shows them. `tools/data_ptrs.py scan` parses every source that names an
  address-named global (libclang, the 32-bit MS target: the sources' byte offsets are the game's layout), follows
  each reference through `&`, casts, constant offsets, subscripts and member accesses to the access it ends in
  (15,442 accesses), and `evidence` writes the pointer accesses per item to `config/data-ptrs.json` (names and
  offsets only): 292 items, 406 pointer words, 28 pointer tables.
- **Types.** By what the word points at: `const char*` (410 items), `hulk_code_ptr` (code, 34),
  `hulk_vftable_ptr` (11), `const void*` (other data, 66), `void*` (set at run time, 62; 133 items in all gained
  run-time pointers). An item whose name was an array stays an array (`void* DAT_x[1]`) and a scalar stays a scalar,
  so a source's `(hulk_intptr)DAT_x` or `DAT_x == 0` means what it meant or stops compiling, never changes silently.
- **Layouts.** The mixed items (pointers among other words, 101 now, 55 before) are structs with pointer members and
  `unsigned int` words, packed on the 32-bit builds (`HULK_DATA_PACKED`, the XBE's layout) and naturally aligned
  on 64-bit. The packed structs that put 274 pointers at 4-byte offsets (the ld64 warnings of section 9) are gone:
  ld64 links with no warnings.
- **Proof.** data_gen's own check: 18,832 / 18,832 items byte- and relocation-identical under MSVC 7.1, 1,078 /
  1,078 TUs. The 2,635 sources that include `include/decls/data/` compile to identical MSVC objects with the new
  headers, except 5 that passed a pointer item to an `int` (now compile errors, fixed with `(hulk_intptr)` casts:
  objects identical). arm64: 1,078 / 1,078 data TUs, no 64-bit diagnostics.
- **On-disk records** are not affected: `layout64.py --check` passes, and of the 19 pointer items the file, save and
  memory-card code touches, none is itself read or written: they hold pointers to the buffers that are.
- **Lint.** `tools/data_ptrs.py lint ACC.jsonl` lists the code that is still wrong on 64-bit once the items have
  pointer types, in 68 sources over 59 items: 142 pointer accesses at a 32-bit byte offset into a pointer-holding
  item (`((Entry*)&DAT_004d4d08)[1].fn`, `*(T**)((char*)&DAT_x + 8)`), 30 addresses with such an offset, 29 integer
  reads of a pointer word (`*(unsigned*)&DAT_0048e060` passed as an int), 8 indexed 4-byte integer accesses over
  pointer items. Each needs the item's real record type in the source (or the source's record as the item's type).

```sh
build/venv/bin/python tools/data_ptrs.py scan --out ACC.jsonl              # every source (~4 min, 2 processes)
build/venv/bin/python tools/data_ptrs.py evidence ACC.jsonl               # -> config/data-ptrs.json
HULK_DATA_DIR=/private/dir build/venv/bin/python tools/data_gen.py         # a private set of data TUs
build/venv/bin/python tools/wine_build_job.py submit ... --data-src /private/dir/src   # a Wine build with them
build/venv/bin/python tools/data_ptrs.py lint ACC.jsonl --json LINT.json
```
