# Native build: how far the tree is from clang

Roadmap step 6.1 ([roadmap.md](roadmap.md#6-native-build), [shipping.md §1](shipping.md#1-the-source-tree-roadmap-steps-2-and-4)):
the first native build is 32-bit x86 under clang. This page measures how far the merged source tree
([source-tree.md](source-tree.md)) is from that, sorts what's in the way into categories, and turns them into a
prioritized fix list. Measured 2026-10-17.

```sh
build/venv/bin/python tools/clang_probe.py              # snapshot (if missing), compile msvc/gnu/gnu64, classify, link probe
build/venv/bin/python tools/clang_probe.py --snapshot   # refresh the snapshot after a complete tools/build_tree.py run
build/venv/bin/python tools/clang_probe.py --only src/game/global/CAction.cpp   # one TU's diagnostics, every configuration
build/venv/bin/python tools/native_link.py              # binding map (fix 5a), link inventory, lld-link attempt
build/venv/bin/python tools/native_link.py --reuse-map  # inventory + link with build/native/bindings.json as it is
build/venv/bin/python tools/native_shim.py              # platform-shim / CRT inventory of the link (build/native/shim-inventory.json)
build/venv/bin/python tools/native_shim.py --skeleton   # write src/platform/sdl/xdk/ files that don't exist yet (pre-shim inventory)
build/venv/bin/python tools/native_fix.py               # fix 4 source edits: plan; --apply --verify rewrites verified sources
build/venv/bin/python tools/native_conv_check.py        # calling conventions of library imports and register-convention callers
build/venv/bin/python tools/native_conv_check.py --returns --pops --tree-report build/tree/report.json   # checks 6-9 (below)
build/venv/bin/python tools/native_fix.py --rule reg-call --apply --verify     # the hand-read call fixes in tools/native_calls.py
HULK_TREE_REPORT=... HULK_TREE_MANIFEST=... HULK_BINDINGS=... build/venv/bin/python tools/native_fix.py --rule base-ctor --apply --verify   # candidate rules: return-param, base-ctor, this-cand
build/venv/bin/python tools/native_run.py --hello       # Wine runs a trivial i686 PE? (our own prefix: build/native/wineprefix)
build/venv/bin/python tools/native_run.py               # run the image under Wine: build/native/run/ (trace, summary)
build/venv/bin/python tools/native_link.py --reuse-map --gfx   # with the pddi/bgfx graphics backend (docs/graphics-backend.md 8)
build/venv/bin/python tools/native64.py --bindings build/native/bindings.json   # 64-bit probe: msvc64/arm64 compile, x64 link (64-bit section)
build/venv/bin/python tools/layout64.py [--check]   # 32- vs 64-bit record layouts; file-format static_asserts (config/layout64.json)
# beside another agent's runs: HULK_CLANG_PROBE_DIR=build/native5/clang-probe HULK_CLANG_PROBE_CACHE=build/clang-probe/cache
#   HULK_NATIVE_DIR=build/native5 ... clang_probe.py --snapshot --configs msvc; native_link.py --tree build/native5/clang-probe/snap
```

**64-bit (x64-1, 2026-10-20):** the tree compiles for x86-64 (2,803 / 2,810 TUs) and arm64 (2,787); the gap is silent layout and the link: 4,881 pointer/int casts, 272 64-to-32 truncations, 874 include/gen/ classes whose fields move relative to each other, 56,688 undefined symbols in a bridge-free x64 link. See [64-bit](#64-bit-the-probe-the-gap-by-class-and-what-replaces-each-bridge-x64-1-2026-10-20).

**Status 2026-10-20 (native12): the first level loads.** On HEAD with x64-1's consolidation the replay again matches
all 15 checkpoints (frames 0-420) after five native bug classes the new tree exposed were fixed; stops 31-33 are fixed
(the fight tracks, a Lua thread, Lua upvalues) and the run now stops in the first gameplay update (stop 34, open).
See [native12](#native12-past-the-first-level-load-2026-10-20).

**Status 2026-10-20 (native11): a recorded game replays natively.** play3 (the hybrid's 56,566-frame recording) runs
through the native image with the replay pins: **frames 0-420 match the recording at all 15 checkpoints** (title,
menus, new game, into the first level's load), with the sound/sequencer RNG isolation, no-fmv and the I/O-sync hook
in. The level load then stops in the fight parameter reader (stop 31, open). The normal run plays the five boot
movies and reaches the title ("Press START", 8,000+ frames presented). See
[native11](#native11-the-replay-matches-to-frame-420-2026-10-20).

**Status 2026-10-19 (native10): the front end's scripts run.** Past native9's heap stop, the native image loads the
front end (the DollyScript `frontend\fe_real.txt`: fonts, macros, screens, labels, buttons, locators), sorts its
screens and runs the front-end Lua; it plays the boot movies and stops while uploading their frames (a null bgfx block). See
[native10](#native10-past-the-loader-into-the-front-end-2026-10-19).

**Status 2026-10-19 (native9): the game's own frame loop runs.** The native image gets through start-up and loading
into `Main::update`, which presents frames through the pddi/bgfx device (256+ frames of the copyright screen, drawn
by the game) and runs the Lua scripts; it stops later in the loader fiber (a game heap runs out). See
[native9](#native9-from-the-rcf-mount-toward-the-first-frame-2026-10-19).

**Status 2026-10-19 (G1): the graphics boundary is crossed.** With `native_link.py --gfx` the device the engine
creates is the pddi/bgfx backend's ([graphics-backend.md section 8](graphics-backend.md#8-g1-the-backend-in-the-native-image-2026-10-19)):
no D3D import is called, bgfx draws through Vulkan (MoltenVK) under Wine, and start-up goes on through
`pure3d::InitPlatform`, physics init and the platform start-up to the RCF mount, where it stops on native-only
source bugs: see [Graphics boundary crossed](#graphics-boundary-crossed-g1-2026-10-19).

**Status 2026-10-18 night: the game object is built and the D3D device is up.** The image runs all **457 game
C++ dynamic initializers**, gets into `main`, constructs the game object (the Lua VM opened with its libraries,
the script `Registry`), registers every script binding, and in `T_8ee30::Init` creates
the Direct3D device through the shim (`Direct3D_CreateDevice`, the vertical-blank callback, textures, a vertex
buffer, viewport, transforms and render states: 55 distinct imports called). It stops in pure3d's d3d backend,
which writes D3D's own render-state cache at its XBE address (`*(int*)0x39de28 = v` in `matches/0x00321b70.cpp`,
inside the D3D library section): the graphics boundary (the pddi/bgfx backend replaces that layer). See [Start-up,
part 3](#start-up-part-3-2026-10-18-night): three more classes of verified-source bugs found and their checks,
the Lua VM's register-convention calls, 308 sources rewritten (all re-verified; 3 matches became equivalent/
sources), and the split of the caller-convention mismatches.
The evening: [Start-up, continued](#start-up-continued-2026-10-18-evening) (into `main`, stopped in the Lua VM).
The morning: [Start-up](#start-up-2026-10-18) (308 of 466 initializers). The evening before: all 2,558 TUs
compiled under clang and the strict link succeeded with 3,253 symbols stubbed; see [Deleting destructors, the last TU and the platform
shim](#deleting-destructors-the-last-tu-and-the-platform-shim-2026-10-18).
[After fix 4 and the binding fixes](#after-fix-4-and-the-binding-fixes-2026-10-18) is the same morning, [After the
next fixes 1-3](#after-the-next-fixes-1-3-2026-10-17) the night before (first strict link), [After fixes 0-2 and
5a](#after-fixes-0-2-and-5a) the evening before, and the sections from "What was measured" on are the
2026-10-17 morning's baseline.

Cold, the first run takes 10-15 minutes (4 compiler processes); a warm run takes 30 s. Everything goes to `build/clang-probe/`:
`report.json` (counts, categories with example sites, scans, link probe), `undefined.txt` (every undefined symbol with
its group and demangled name), `cache/` (per-TU results and objects) and `snap/` (the tree being probed).

## 64-bit: the probe, the gap by class and what replaces each bridge (x64-1, 2026-10-20)

The port's targets are x86-64 (SteamOS/Linux, Windows) and arm64 macOS from one tree. A 64-bit image can't use
the 32-bit link's bridges: they take code or layout from the XBE (x86 bytes, 32-bit addresses), so every one of
them needs our own source instead. This section measures the distance on the tree of HEAD 441f5270b (the
consolidation batches b1-b3, b5 and the first part of b7 of [consolidation-plan.md](consolidation-plan.md) applied on top of it since: merged 74.85% -> 77.46%, header fields +815).

```sh
build/venv/bin/python tools/native64.py --bindings build/native/bindings.json   # compile msvc64/arm64/gnu64/gnu32w,
                                                  # classify, link the msvc64 objects with lld-link /machine:x64
build/venv/bin/python tools/layout64.py           # include/gen/ record layouts on i686 vs x86-64 vs arm64
build/venv/bin/python tools/layout64.py --check   # static_asserts for the file-format records (config/layout64.json)
```

`native64.py` runs on clang_probe's snapshot (`clang_probe.py --snapshot` after a complete tree build) with four
configurations added to `tools/clang_probe.py`: `msvc64` (`x86_64-pc-windows-msvc`, MS ABI, LLP64: objects for the
link; Wine runs x64 PEs), `arm64` (`arm64-apple-darwin`, Itanium, LP64, syntax only), `gnu64` (as 2026-10-17) and
`gnu32w` (i686 with the same truncation warnings, to subtract `__int64` narrowing every target has). The 64-bit
configurations add `-Wshorten-64-to-32 -Wvoid-pointer-to-int-cast -Wint-to-void-pointer-cast`.

**1. Compile** (2,810 tree TUs):

| config | TUs compiling | failing TUs by cause |
|---|---|---|
| `msvc64` | **2,803 (99.75%)** | 3 `array is too large` (pads computed as `N - sizeof(...)` that go negative with 8-byte pointers, `FEThingsBase_2.cpp`), 2 `extern "C"` CRT redeclarations (`strlen`/`memset`/`_alloca` with `unsigned int` sizes), 2 placement `operator new(unsigned int, ...)` |
| `arm64`, `gnu64` | 2,787 (99.2%) | the same 7, plus Itanium-only causes `gnu32w` (i686 Itanium) shares: 7 `other-error` (overloads `FUN_001d04d0` with `long`), 3 `register`, 3 `goto` over initialization, 3 exception specifications |

64-bit *compiles*; nothing about it is an error the compiler reports, which is the problem: the gap is silent.

**2. Pointer width, by class** (sites / sources, net of i686):

| class | `msvc64` | `arm64` | where |
|---|---|---|---|
| pointer <-> integer casts (`(int)p`, `(T*)i`) | **4,881 / 3,136** | 4,864 / 3,121 | matches merged 2,929, wrapped 785, isolated 123; equivalent wrapped 741, merged 271, isolated 30; one source has 521 (`equivalent/0x00107c90.cpp`). By direction (occurrences): pointer kept in an integer 3,119, integer used as a pointer 2,990 |
| implicit 64 -> 32-bit truncation (`int n = p - q;`, `int i = strlen(s);`) | **272 / 195** | 294 / 204 (`long` is 8 bytes) | 0 of them on i686 |
| explicit `char pad[N]` in sources (tree TUs) | 25,683 in 3,949 sources | same | offsets written for 4-byte pointers |
| include/gen/ `_pad_` gaps / pointer `f_XX` fields at 32-bit offsets | 889 / 589 | same | |
| `*(T*)&x` punning / hand-written vftable calls / stub virtual declarations | 2,946 / 734 / 84,904 (in 880 / 372 / 4,175 sources) | same | slot numbers and vptr offsets are MS-ABI x86 |

**3. Layout** (`layout64.py`, clang's record layouts of the 1,550 non-template include/gen/ classes): every one
moves on x86-64 and arm64 (all are polymorphic: the 8-byte vftable pointer shifts every field by 4); in **874**
the fields also move relative to each other (pointer fields, alignment), and **906** have `_pad_` gaps, which keep
their byte count while the fields around them grow: those headers are wrong on 64-bit although clang reports
nothing. The data TUs (`build/data/src`): 55 `#pragma pack(1)` `DataLayout_` structs, all with pointer members,
and 754 `void*` items/arrays, laid out at the XBE's 4-byte distances.

**File formats.** A search of the sources for whole-struct reads and in-place pointer fix-ups found none: the
P3D chunk reader reads field by field (`FUN_002647e0(dst, count, size, flag)`, ~1,330 sites with literal sizes
1/2/4), the RCF header is a byte array read by offset, fight/DHD data goes through `BufferDataReader`/`BinReader`,
the replay and save files are parsed by byte readers in `src/platform/sdl`. Two records are read raw and are now
pinned by `config/layout64.json` + `layout64.py --check` (static_asserts of size and offsets, compiled for
i686, x86-64 and arm64; all pass): `Entry_2779b0` (RCF directory entry, 20 bytes, all `unsigned`) and
`RawHeader` (`matches/0x002ddf10.cpp`, 28 bytes). The Lua 5.0 undump header checks `sizeof(int/size_t/
Instruction/lua_Number) == 4` with literal 4s (`equivalent/0x00220310.cpp`), so the compiled scripts stay
loadable; Lua's in-memory structs (`TString`, `Proto`, `TObject`) are stub structs with pads like the rest.
The XDK shims' ABI structs (find data 0x344 bytes, `DSBUFFERDESC` 24 bytes) are 32-bit shapes in
`src/platform/sdl/xdk/` and go with the 32-bit-only shim layer.

**4. The 64-bit link without bridges** (`lld-link /machine:x64`, 3,881 objects: tree TUs + data TUs):
**56,688 undefined symbols** (62,828 references), the same order as the 32-bit tree before its binding map
(57,533 in the 2026-10-19 probe):

| group | symbols | references |
|---|---|---|
| verified function referenced under another symbol (32-bit: bound by relocation position) | 26,000 | 26,829 |
| invented / stub names (32-bit: bound by relocation position, stub-vftable aliases, dispatch stubs) | 25,920 | 27,037 |
| vftables / RTTI by address (hand-written vptr stores) | 3,062 | 3,243 |
| platform imports (XDK / kernel / D3D / DSound / Bink) | 465 | 468 |
| CRT / C++ runtime | 404 | 4,389 |
| data: emitted item under a C++ name / outside the inventory / library | 286 / 192 / 55 | |
| not yet verified / TU fails under clang / library code by address | 229 / 65 / 10 | |

Reusing the 32-bit link's binding map as a *name table* (no bytes: symbol -> address -> definition name,
matched by demangled name with conventions and `__ptr64` dropped) would resolve **37,271** of them; 612 more
are bound but their definition's 64-bit name differs; 18,805 have no 32-bit binding under that name (the
stub-vftable members, dispatch stubs and ambiguous names the 32-bit link handles by aliases and stubs).

**5. What replaces each bridge on 64-bit** (none implemented for 64-bit; counts from the base tree's strict link):

| 32-bit bridge (count) | 64-bit replacement: the source it needs | batch / step |
|---|---|---|
| binding map: callers' names bound by relocation position (`/alternatename`, per-function rebinding) | every caller declares its callee under the definition's name: include/gen/ classes (b4-b13), prototype pins in include/decls/ for free functions and data, `FUN_` names replaced by the callee's real name. Interim, if wanted: the map as a name table (37,271 of 56,688, above), which carries no game bytes | consolidation b2-b13, pin-decl families |
| `jump_shapes` (205 thunks replaced, 120/122 bare `jmp` slots, 48 `jmp [reg+d]`) | the real base order of multiple-inheritance classes in include/gen/, so clang emits its own adjustor thunks; the thunk sources become those classes' overrides | b13 |
| RTTI TD redirection (2,731) | real class names and namespaces in the sources, so clang's own TDs are the game's classes (`dynamic_cast` across sources needs it; the 64-bit link has no undefined TDs, it would silently fail casts) | b9, b10, b11 |
| stub vftables pointed at the game's; 1,324 stubbed stub-vftable members; 1,218 dispatch stubs | constructors/destructors on include/gen/ classes so the compiler's vftable is the real one; hand-written vptr stores (`*(void**)this = g_vftable_x`, 3,062 undefined vftable/RTTI names on x64) become constructor calls | b10 first, then b9, b11 |
| stand-in bodies `local_code` (940) | sources declare callees they define today (`~Sprite() {}`) | `stub-body`-style rule over the 940 |
| `hulk_at_` / `DAT_` by address, data copied at XBE distances (54 sources; 1,670 data-by-address names on x64) | named data in include/decls/data/ everywhere, typed data structs instead of `DataLayout_` byte layouts (55 packed structs with pointers, 754 `void*` items), item boundaries from the types (data.md open problems 2, 5) | data steps |
| `ctor-virt` stand-ins (12) | the real class declaration | b9 |
| `SITE_REBIND` (15 sites), `ENTRY_HOOKS` (3), `EXIT_HOOKS` (1): replay pins, no-fmv, sync I/O | platform interfaces the sources call: a replay-aware clock/input/seed interface, a sound RNG object, a movie policy, a synchronous drive mode, ControllerSystemXBox +0x12a0/+0x12a4 as named members (b7) | platform layer + b7 |
| empty stubs for the 0x002777c0 class (14) | the class's real declaration | b13 |
| x87 (`-mno-sse -mfpmath=387`), `volatile` rounding pins (2,288) | SSE/NEON math: the replay checkpoints have to be re-recorded or made tolerant on 64-bit (roadmap step 6) | - |

**6. Order of work for 64-bit**: the consolidation batches in their plan order (each one shrinks the binding map
the 64-bit link can't use), then the pointer-int casts (4,881; item 9: now 1,163) as the fields they read get types
(b7 header fields turn `ptr-int` fits into typed fields), the 272 truncations per source, the 7 failing TUs, typed data,
and only then a 64-bit link attempt with real bindings. The gate to watch is `native64.py`'s undefined symbols
(56,688) and `layout64.py`'s relative-move count (874).

**8. After the batches** (b1-b3, b5, b7 part 1 applied; `native64.py` on that tree, 2,818 TUs):

| measure | HEAD 441f5270b | after the batches |
|---|---|---|
| `msvc64` / `arm64` TUs compiling | 2,803 / 2,787 of 2,810 | 2,811 / 2,795 of 2,818 (the same 7 / 23 fail) |
| pointer <-> integer casts (`msvc64`, sites / sources) | 4,881 / 3,136 | 4,935 / 3,186 |
| 64 -> 32-bit truncations | 272 / 195 | 272 / 195 |
| stub virtual declarations | 84,904 in 4,175 sources | 83,336 in 3,674 |
| explicit `char pad[N]` (sources) | 25,683 in 3,949 | 25,476 in 3,456 |
| include/gen/ `_pad_` gaps / pointer fields | 889 / 589 | 820 / 695 |
| x64 link undefined symbols (resolvable by the 32-bit map's names) | 56,688 (37,271) | 56,564 (37,305) |

The class work moves stubs onto the real classes (stub virtuals -1,568, header pads -69, pointer-typed header
fields +106) but adds casts: gen-ref and gen-swap keep a source's view of a field as a cast where its type differs
from the header's (`(*(int*)&p->f_1c)`), so the pointer/int count grows by 54 until header fields carry the
pointer types and the sources drop the casts.

**7. build_tree.py's symbol uniqueness** (rn1's finding a): the lookup by mangled-name prefix checked 1,137
functions of the base tree (302 groups) under another function's symbol (every `Method2<CActorManager,...>`
deleting destructor under the first instantiation's). `verify()` now re-checks such functions under their own
symbol: 832 resolved (all still match), 3 had no own symbol in their TU (they had matched another class's
deleting destructor) and fall back to isolated, where they match; 0 verdict differences. The strict 32-bit link
with that report: 1,600 -> 1,392 symbols stubbed, 1,218 -> 1,073 dispatch stubs (the native replay has not been
re-run since).

**9. Pointer-width types (ptr1, 2026-10-20).** The sources that keep a pointer in an `int` now say so, with types that are
the same `int` on the 32-bit builds and pointer-sized on 64-bit (`include/compat/ptr.h`; MSVC 7.1 has no `<stdint.h>`):

| type | 32-bit (MSVC 7.1, clang i686) | 64-bit (`intptr_t` width) | replaces |
|---|---|---|---|
| `hulk_intptr` / `hulk_uintptr` | `int` / `unsigned int` | `long long` (LLP64) or `long` (LP64) | `int` / `unsigned` that held a pointer, a difference or a size |
| `hulk_longptr` / `hulk_ulongptr` | `long` / `unsigned long` | the same | `long` (its own pair: `long` and `int` mangle differently) |

Signedness is kept as the source had it. A source that uses one has `#include "compat/ptr.h"` after its leading
comments; `gen_tree.py` drops that line from the source, includes the header once in the TU (and in generated headers
that spell the types), and `cxx_items.py` reads the four names as the 32-bit types they are, so declaration variants,
signatures and `stub_layout` sizes compare as before (the TU emits the pointer-sized spelling of a declaration the
variants share). Not touched, by design: on-disk fields (`layout64.py --check` still passes), `hulk_at_`/`DAT_`
constants, arrays of integers (their element size is the layout), locals that address a local array by byte offset
(the register-emulation equivalents), virtual methods, functions and fields declared in `include/` headers, and the
names a 64-bit compile of the merged tree found ambiguous once some declarations of them are pointer-sized
(`thunk`, `FUN_0008d690`, `FUN_00219430`, `FUN_00245850`, `FUN_0008d6d0`).

`tools/ptr1.py` does the rewriting (libclang: `build/venv/bin/pip install clang`, Homebrew LLVM's `libclang.dylib`):

```sh
build/venv/bin/python tools/ptr1.py scan matches equivalent --out r.json    # sites per source with the reason a site is unresolved
build/venv/bin/python tools/ptr1.py fix @files --write --out f.json          # casts, locals, punned slots; f.json["..."]["demands"]
build/venv/bin/python tools/ptr1.py collect @all --out collect.json          # keys declared in headers / virtual / overloaded
build/venv/bin/python tools/ptr1.py sigs --demands d.json --blocked collect.json --skip @n12 @all --write
build/venv/bin/python tools/ptr1.py proof @changed                           # MSVC 7.1 objects before/after (git HEAD)
```

`fix` rewrites the type of a pointer -> integer cast, of the local that receives it or feeds an integer -> pointer
cast, and the pointee type of a `*(uint*)(p + 8)` slot, and iterates on clang's own diagnostics (a file whose rewrite
adds a clang error on either target is left alone). What it cannot reach it reports as a demand (a parameter, return
type or field of this function / class carries a pointer); `sigs` applies the demands to every declaration of the same
function (i686 mangled name) in every source at once, since the tree generator merges declarations by text.
`proof` compiles HEAD's and the working copy's source with the verification flags and requires identical sections,
relocations (by symbol name), symbol tables (the compiler's `$L<n>` jump-table labels are named by position) and
data. Re-run `scan` after new sources land (`native64.py --sites OUT` lists the tree's sites as JSON lines).

| `native64.py` (msvc64) | before (HEAD 64a092293) | after |
|---|---|---|
| pointer <-> integer casts, sites / sources | 4,936 / 3,187 | **1,163 / 1,106** (pointer -> integer 3,163 -> 18; integer -> pointer 3,016 -> 1,205) |
| 64 -> 32-bit truncations | 274 / 196 | 666 / 302 |
| both classes | 5,210 | **1,829** |
| `arm64`: casts / truncations | 4,919 / 296 | 1,160 / 686 |

The truncation class grows because an explicit `(unsigned)p` that is now `(hulk_uintptr)p` meets a callee, return or
field that stays 32-bit: the cast no longer hides the narrowing. What is left, by source-level reason (`ptr1.py scan`,
1,902 sites in 1,297 sources): 975 parameters of virtual stub methods and of functions declared in `include/` headers
(they need the real class hierarchy: b9-b13), 198 stores into a local array used as a stack image (the register-emulation
equivalents, e.g. `equivalent/0x00107c90.cpp`), 336 `int*`/`unsigned*` locals and slots written or read as pointers
(`*p = (hulk_intptr)&vftable`: the hand-written vptr stores b10 replaces with constructors), 159 arguments of
callees whose signature is virtual, header-declared or overloaded, 53 fields of `include/gen/` classes, 53 subscripts
of such arrays, and a tail of constants and globals. 3,472 sources changed. Proof: every changed source compiles with
MSVC 7.1 to an identical object; `verify_relocs.py` ok on the 2,316 changed `matches/`; `build_tree.py` (mac2):
22,341 / 22,341 matches, 0 verdict differences, equivalents all `same`, merged 21,242 = 21,242 (8 functions swapped
modes among neighbours that share `GetLastError`-style declarations); the strict i686 native link of that tree:
lld-link rc 0, no messages.

## native16: the physics precision chase to 840, float returns, native-mode equivalence (2026-10-21)

Inputs: HEAD 4ecbc09d (native15) plus the same untracked other-session sources as native15's workspace; during the
round HEAD moved to 08e440d0 (fx24's round-17 fixes, cl6's `equiv.py --native`). Changed sources:
`build/native16/sources.txt`; files: `build/native16/files.txt`; equivalents for the 20,000-input promotion:
`build/native16/equivalents.txt`.

**Replay (play3)**: checkpoints 0-420 and 480-840 match (28; native15: 0-420, 480-780). 450 is still -1 ULP in the
camera's y. 870 differs only in the RNG (14 draws behind, camera exact): the first RNG caller missing natively is
an AI agent at frame 857 (CRangedAgent::vfunc_9 0x00107300, FUN_00107140, FUN_00037860, FUN_000fee10); the prop
physics already differs at 840 (another prop's velocity, 1-4 ULP). The image plays play3 to frame 103,500 without
a crash or hang (native15's stop near 4,600 is gone: the game no longer reaches that diverged state; the original
makes the same unchecked call, see below).

**What 810 was.** The checkpoint brute force (`$S/n16/bf.c`: the recorded hash from the native camera and clock
with the hybrid RNG stepped k draws past frame 780) showed the camera right at 810 and the RNG 10 draws behind. An
rng-log hybrid replay of play3 (`rl3`, mac2) against native probes of every RNG accessor (`rngcmp.py`) named the
missing draws: two awake CSPHulkPropInstance props (`FUN_001d8fc0` draws for a non-sleeping articulated body) fall
asleep at 800 and 814 natively and the prop manager 0x001e6390 deactivates them; in the hybrid the collision
solver's impulse (PhysicsObject::vfunc_19, 0x002f5db0) wakes them again. Guest-side loggers written over GDB into
the hybrid (`rl4`: function entries, instruction sites and memory chains logged per frame into the unused
`record[]` ring) against native `HULK_TRACE_SPAN` dumps then walked the props' physics back to its first
difference, fixed it, and repeated; each fix moved the first differing frame later (441 -> 444 -> 450 -> 678 ->
742 -> 769 -> 840):

| frame | where (first difference) | cause | fix |
|---|---|---|---|
| 441 | a triangle contact normal's z (FUN_002fa6b0 -> normalize 0x0022d180) | MSVC 7.1 computes (x*x + y*y) + z*z, root and reciprocal in registers; the source said z*z + y*y + x*x and `(float)sqrt` | listing order, `hulk_freg` (matches/, MATCH) |
| 444-678 | capsule depth 0x00314380, restitution `vfunc_4` 0x002f8730, `FUN_002f7ca0`, triangle/capsule tests 0x00358630 / 0x003577c0, inertia 0x002fcd60, impulse lever 0x002f5a20, quaternion 0x0022b370, PhysicsObject::vfunc_7 0x002f5870 | locals and returns the original keeps in st0 | `hulk_freg` locals / returns |
| 677 / 739 | box-triangle contact depth (0x002faa30 -> 0x0035a2a0 -> clip 0x00359a80, SAT 0x00359510) | clip interpolation and plane distances in registers | `hulk_freg` (MSVC objects identical) |
| 739 | contact velocity from SimState::vfunc_8 0x002ef530 | the workspace lacked 18 of fx24's committed round-17 fixes (`cycle.sh` copies only this round's sources) | workspace synced with HEAD |
| 769 | box centre (Mat::Transform 0x0022c2b0) | MSVC 7.1 reassociates x = v1*m4 + v2*m8 + v0*m0 + m12 | listing order (MATCH) |
| 768 | body-body capsule contact 0x00315620 | cross product and 1/(s*s) kept in registers | `hulk_freg` (MSVC object identical) |

The classes and how many sources each touched:

| class | sites | fix |
|---|---|---|
| float locals MSVC keeps in x87 registers (53 bits), rounded natively | the scanner's "image rounds more" functions | `hulk_freg` locals by hand from the listing, `localfreg.py` (78 replay-path candidates; 10 reverted where the original spills) and `autofix.py` (greedy float/`hulk_freg` toggles until `equiv.py --native` agrees: 15 sources) |
| float returns the original leaves unrounded in st0 | 299 functions whose listing returns a computed st0 (`retscan.py`) | `hulk_freg` return type (`retfreg.py`, 277 sources; 3 overrides of header virtuals reverted, 19 header-declared members left) + the binding rule below |
| sums MSVC 7.1 reassociates | 0x0022d180, 0x0022c2b0 | the listing's order. Random inputs rarely see these (at 53 bits two orders round to the same float almost always), so `--native` passes them: they need a listing-vs-source order check (next round) |
| `--native` sweep | 2,779 x87 functions: 2,374 equivalent natively, 403 fail (57 ULP-sized, 35 NaN-payload sign, 12 unrounded returns of header virtuals, 296 other: uninitialised frame words, stack-depth reports, harness gaps) | autofix (87 of 393 tried) + by hand; the rest listed for the next round (`$S/n16/af2*.txt`) |

**The binding rule.** A definition whose return is `hulk_freg` is mangled `N` (double) natively where its MSVC 7.1
symbol (the tree's `defs`) says `M`; `tools/native_link.py` now binds that address to the clang definition that
differs only in the return-type code (`@@Y?`, `@@[ABEFIJMNQRUV][A-D]?`, `@@[CDKLST]?` then M/N; never a parameter,
whose size differs). On x87 a float and a double come back the same way (st0), so a caller declared `float f()`
reads the unrounded value as the original's callers do. 186 definitions bound this way; the strict link stays at 0
errors (1,366 unresolved names, as before). x87-only: listed in "Bridges to remove".

**Flags.** **Adopted** (tools/clang_probe.py: `-ffp-eval-method=double -ffp-contract=off` added to the x87 flags). Evidence:
an image built with them (workspace wsn16f, all TUs compile) gives the same checkpoint hashes as the image without
them at all 67 checkpoints both runs reached (0-6,000: 28 matching, the diverged ones with identical hashes); strict
lld-link 0 errors with and without `--gfx` (1,366 unresolved names, as before). native15's blocker, the 159
functions whose unrounded return the flags would round, is down to 8: 151 now return `hulk_freg` and are bound by
the rule above; the 8 left are members declared in shared headers or overrides of header virtuals (0x000dd8b0,
0x000dd8d0, 0x000dd920, 0x000e85b0, 0x00143840, 0x00181270, 0x00268ea0, 0x002f60f0). `equiv.py --native` uses
clang_probe's flags, so native-mode checks now compile the same way.

**Crash near 4,600.** Not reproduced: the image plays all of play3 (to 103,500) without a crash or hang. native15's
stop was `Obj_2250e0::set` with a null driver reached from AnimationPhaseMatchedAction 0x0013d7b0 on the diverged
path; the original makes the same unchecked call, so it is a state the original never reaches. No guard added
(it would change a byte-matched source for a path the replay no longer takes).

**I/O capture (stop 41).** rl4 loggers on DriveThread's post (0x272fc0), request step (0x273210) and retirement
(0x27336c) on play3 to frame 1,000 in the hybrid: 1,089 posts, every request retired in the frame it was posted
(post-to-retire latency 0 frames). So the hybrid's model is "complete before the next frame" (native15's
`HULK_SYNCIO=3`/`4`); the 914/915 race natively comes from the request still pending >300 ms, not from xemu taking
frames.

**Screenshots.** `HULK_GFX_SHOT_GAME=<game frames>` (src/platform/sdl/pddi/sdl_platform.cpp; rebuild the pddi
objects with `tools/native_gfx.py pddi --target win32`) saves `game-<frame>.tga` at the first present after that
GameClock frame; mac2's `~/hulk-tr1/shots-native16.py UNTIL F1,...` stops the hybrid over GDB at the same frames and
saves the scan-out buffer. Side-by-sides stay in scratch (game imagery is never committed).

**Tools (scratch `$S/n16`).** `rl3.py` / `rl4.py` (hybrid loggers; `--mem ADDR:NB:CHAIN:K` with an
instruction-boundary check; `esp` chains are 0xc above the real esp, the logger pushes three registers),
`cmpmem.py`, `cmpq.py`, `cmpphy.py`, `seqcmp.py`, `rngcmp.py`, `bf.c` + `ckbf.sh`, `retscan.py`, `retfreg.py`,
`localfreg.py`, `autofix.py` + `autofix-batch.sh`, `msvcsame.py` (MSVC objects identical before and after: the proof
that a float -> `hulk_freg` spelling changes nothing for MSVC; compare under the same file name), `natdis.sh`.
Probe aids in startup.cpp: `HULK_TRACE_SPAN=[fn/]slot+off[@+off]:words` (slot 0 = ecx, 1.. = stack arguments),
the watch's readability check; replay_hooks.cpp: `HULK_CKPT_EVERY=a-b`.

**Checker gaps found.** (1) `--native` cannot see reassociated sums (above). (2) Native-mode reports that are
artefacts: "x87 stack depth at return 7, expected 0" (0x0002a960, 0x00316410, 0x00317700, 0x00039c60,
0x000418f0), 0x002fa6b0's tail `jmp` to 0x0022d180 read as a call with 0 argument words, NaN sign after `x * -1.0f`
(clang emits a sign flip, the x87 `fmul` keeps the NaN's sign: 35 functions, harmless for real values).

**Next.** (1) The prop that differs at 840 (another CSPHulkPropInstance; same method: `rl4 --mem
0x2f58e0:7:ecx+10@+40:16` from 800, then contacts/impulses with `cmpq.py`) and the AI agent draws at 857. (2) A
listing-order check for sums in byte-matched sources (compare the operand order of each fadd chain with the clang
object's). (3) The remaining 306 `--native` failures (autofix on `$S/n16/af2*.txt`, 87 done). (4) 450: the chase camera (0x000a75d0's object, 192 words compared per frame against the hybrid)
is equal at frame 442 and differs at 443 by 1-2 ULP in a direction vector (+0x50 / +0x64 / +0x70) and +0x80; the writer during
442 is next (the heap address moves between probe runs: watch it through a pointer, not an absolute address).

## native15: float precision through 780, the I/O timing of stop 41, check 7 (2026-10-20)

Inputs: native14's workspace (HEAD e6b732c9 + the same untracked sources), x87's study ([native-float.md](native-float.md)),
cl5's round 17 of equiv.py (exact floats at 53-bit precision, committed as c807a962). Changed sources:
`build/native15/sources.txt`; equivalents for the 20,000-input promotion: `build/native15/equivalents.txt`.

**Replay (play3)**: checkpoints 0-420 and 480-780 match (native14: 0-420, 480, 510, 570, 630); 450 differs by
-1 ULP in the camera's y; from 810 the RNG and the camera differ (not a precision-sized difference). The trace
census agrees with the hybrid's first calls to frame 914; next difference: the 953 group (0x00013f20 / 0x00014210 /
0x00043350 ..., a throw / hit action) starts at 1007-1477 natively. The image now stops at frame ~4,600 in
`Obj_2250e0::set` (null+0x20, under AnimationPhaseMatchedAction 0x0013d7b0) on the diverged path.

| # | what | cause | fix (class) |
|---|---|---|---|
| float | camera y 7 / -14 / -4 / -1 ULP at 540 / 600 / 660 / 690 (and the 720-780 differences) | x87 precision: clang -O0 rounds named `float` locals where MSVC kept them in 53-bit registers. Located with x87's mixed build (TUs at o1dyn, the rest -O0; `$S/n15/bis.sh`, ddmin over the 172 TUs): 600/660/690/720 need `physics/unk_2fa6b0.cpp` alone; 540/690 need `unknown/unk_22baf0.cpp` (vector/matrix library) and `CChaseCamera.cpp` together | **`hulk_freg`** (include/compat/ptr.h): `float` for MSVC 7.1, `double` elsewhere, for locals the original keeps in registers; byte-matched sources keep matching. Rewritten: 0x002fa6b0 (cross product), 0x002fb190 (triangle test), 0x0022d110 / 0x0022d1c0 (normalize), 0x0022cc90 / 0x0022ccf0 / 0x0022cd50 (axis matrices, with the original's spilled copy), 0x0022cdb0 (matrix inverse), 0x0022de70 (ray/plane), 0x0022dfe0 (plane), 0x00292bd0 (camera), 0x000a0fe0 (chase camera FOV: the radius from the reloaded x, y, z), 0x000418f0 (Hulk: products the original spills), 0x00228da0 / 0x00226b40 (locomotion drivers); and 43 byte-matched sources whose listing has no float round trip at all (`$S/n15/fregify.py`: every `float` local and `(float)` cast -> `hulk_freg`, MATCH + relocs ok each) |
| float | MSVC reassociates sums | MSVC 7.1 compiles `z*z + y*y + x*x` and `x*x + y*y + z*z` to the same code ((x*x + y*y) + z*z in 0x0022d110); clang keeps the source's order | write the listing's order (0x0022d110, 0x0022d1c0, 0x000a0fe0) |
| float | x87 intrinsics | the original runs fsin / fcos / fptan / fpatan / the f2xm1-fscale exp inline; the image called msvcrt | `hulk_crt_sin`, `_cos`, `_tan`, `_atan`, `_atan2`, `_exp` (src/platform/sdl/crt/crt_glue.cpp, host_crt_table.h): the same x87 instructions (on x86 hardware the original's results; under Rosetta 2 / QEMU fpatan is the host's atan2). No checkpoint changed through 870 when added alone |
| float | `-ffp-eval-method=double -ffp-contract=off` | x87's proposed flags | **not adopted** (yet): the header conflict is fixed (FUN_0004af40 `(int, float, float)` in 7 equivalents, FUN_00247890 `(int, int)` / `(void*, int)` in 0x001f32b0 / 0x001f6580 retyped to float; all TUs compile with the flags) and a flags image replays identically to the -O0 image through 750, but differs from 780 on, and the scanner shows why: 159 functions that return an unrounded st0 in the original (and at -O0) round their return under the flags (`build/native15/flags-ret-lost.txt`; unrounded returns 208 -> 44, "image rounds more" 353 -> 519 functions). Switch on after those returns are spelled; note that a `double` return type changes the symbol callers bind to (tried: unresolved stubs), so it needs a binding rule first |
| 41 | 0x00203a80 first call 914 (hybrid) vs 915 | native I/O completion follows host thread timing: the same image gave 914 in some runs and 915 in others (io post counts differ run to run; checkpoint hashes identical through frame 1,900+ in all runs) | not a source bug; guest-time models added (off by default, below); none makes 914 deterministic (see native-replay.md) |
| check 7 | 26 callee-pops mismatches | | 0x00248670 (no-argument Run callees + `equiv-conv: FUN_0025d740 ecx`; the -O1 frame-0 crash), the save streams 0x002786a0 / 0x002786c0 (9 / 10-word tail calls declared as such: both byte-match the original, relocs ok), 0x002ad7f0 (the PNG free callback, `__cdecl (png, pointer)`: MATCH). Left: 14, all deleting-destructor / adjustor tail thunks (`declared popping 0, callee ret 4`), which jump_shapes re-emits |
| fsescape | the 15 untriaged frame-store candidates | | all 21 pass round 17's equiv.py (which compares bytes a callee reads through a pointer into the caller's frame) except 0x0007bf80 (CAmbientsManager): its "no table entry" path compares uninitialized frame words in the original too (first runs at 2,110) |
| audio | 0x00256d40 | the pool release takes two words; the source passed one and relied on the stack word the previous call left | x87's patch (EQUIVALENT 1,527, time budget) |

**Locator pitfall**: clang_probe's object cache is keyed by the compiler path, so a mixed build must use a new path
per step (x87's bisect.sh symlinks x87cc-bisN; native15's bis.sh `$S/n15/cc/x87cc-bis-TAG`); with one path every
step after the first reuses the first step's objects (native15's first locator results were void for that reason).

**Tools (scratch, `$S/n15`)**: `bis.sh TAG LIST` (mixed image + replay), `ddmin.py NAME FRAMES LIST` (minimal TU
set keeping checkpoints), `fregify.py`, `natcheck.py` (native14's: equiv.py on the clang object with exact floats;
reliable for leaf functions, the clang-specific failure list: 0x0022d110, 0x0022dfe0, 0x0022cdb0, 0x0022de70,
0x002fb190 pass natively), `sym.py MAP ADDR...`. Probe aids: `HULK_SYNCIO_LOG=1` (one `io post` line per request:
frame, request class, queue count).

**Bridges**: none new. The drive-post exit hook (native11) now passes the drive's count before the post and the
posted request (`EXIT_HOOKS` `pre`), for the guest-time I/O models.

**Proof**: MSVC tree build 2,818 TUs, 22,342 matches still matching, 0 lost, 0 failed (one more `wrap`,
0x0021e300, "code differs from its standalone build", a Lua parser function no change touches); every changed
matches/ source MATCH + verify_relocs ok; changed equivalents EQUIVALENT under round 17 (`equivalents.txt`;
0x001f9810's coverage 52/94 at 3,000 needs the 20,000 run, as before); strict lld-link 0 errors plain and --gfx
(1,366 unresolved names, as native14).

**Checker gaps**: (1) equiv.py models `exp`/`sin`/... by Python's math library while the original runs x87 inline
sequences (f2xm1/fscale, fsin): 0x0009fb20 fails exactly on the last bit of exp (its native rewrite is parked in
build/native15/pending/). (2) natcheck (the clang object under equiv.py) misaligns on functions with calls
(wild jumps, argument words): only leaf functions are checked natively. (3) MSVC 7.1 reassociates float sums, so
an exact equiv pass doesn't show that a source's order is the one clang should compute.

## native14: the head tracker, prop events, cows (2026-10-20)

Inputs: native13's workspace, equal to HEAD 4ffd8334 plus the 21 untracked sources of other sessions plus the
0x0030ed60 demotion (now HEAD b5ec02a0), plus this round's rewrites (`build/native14/sources.txt`, 11 files;
`removed.txt`: matches/0x0033dad0 demoted). Method as native13: first-call frames of the trace session's census
(tr1-A) against native probes, then the stop's call chain from the hybrid's captured stacks and callee results.

| # | stop | cause | class and fix |
|---|---|---|---|
| 37 | Hulk's head tracker never updates (first difference 0x00039c60, hybrid frame 445) | the hybrid's captured stack of CHeadTrackerAction::vfunc_7 0x000202f0 shows the chain 0x0002ab40 -> 0x00042930 -> 0x00042890 (runs Hulk's +0xdc sequence with selector 0) -> SpawnAction::vfunc_5(0) -> 0x00231f20 -> CAction::vfunc_5 -> vfunc_7. matches/0x00042930 called 0x00042890 (thiscall) through `void __stdcall helper(int, float)`: MSVC 7.1 had `this` in ecx by chance, natively ecx was the first argument. Check 8 never saw it: `helper` is a name the link binds per calling function (`helper$00042890`), and check 8 read only `bindings` | **check 8 over the split names**: native_conv_check.py `split_bindings` (bindings.json `ambiguous_by_function` / `ambiguous_by_tu`) now feeds checks 7, 8 and 12. Check 8: 4 findings, `this-cand` rewrites (0x00042930, 0x00042960, the deleting destructors 0x00336f10, 0x00337330; MATCH, relocs ok). Check 12: luaB_getfenv 0x0033dad0 calls getfunc 0x0033d9e0 (L in esi) as `init()` (reg-call, demoted to equivalent/, EQUIVALENT). After it: 570 and 630 match, census first frames agree to 473 |
| 38 | a state prop's final-state event (ERS increase, event 20) never happens (hybrid 473/474) | the StateProp change notification 0x0027dca0 passes its listeners {state id, type -1, 0}: the original stores -1 and 0 into the two words after the id (`mov [esp+0x1c], -1` ...); the source passed only the id, so CSPListener::vfunc_0 0x001db230 switched on stack garbage: no prop state change (breakage, explosions' "Broken", ERS) was ever handled natively | **frame-structure fields a callee reads**: equiv.py doesn't compare the caller's frame bytes a callee reads through a pointer argument (checker gap). Patch (EQUIVALENT 3003). Scan: `framestores` (non-zero immediates the original stores into its frame that our MSVC compile never stores; 292 equivalents) narrowed to stores inside an escaped frame region the function never reads back: 21 candidates, the 6 read by hand are false positives (switch-filled arrays, flags); the rest are listed in build/native14/RESUME.md for triage |
| 39 | Hulk's y one ULP off at frame 445 (an exit probe of 0x000350c0 against the hybrid capture of its caller 0x00039c60); the chase camera's y 1-14 ULP off from frame 450 on (the checkpoint brute force over the logged regions: everything else equal to frame 690) | **x87 precision**: MSVC 7.1 keeps float temporaries in x87 registers (53-bit mantissa: the game's control word is 0x023f, Wine's default is the same and Rosetta honours it, measured) across statements; clang -O0 rounds every float local to 24 bits when it stores it. matches/0x000350c0 keeps `v*0.5 + y` in st0 for the second addition | patch: `double r` (MATCH: MSVC emits the same bytes). The camera's ULPs remain: other sites; 533 functions use `fst dword` (keep a value after storing it) and 3,260 have x87 code, so this is a compile-mode class, now with the x87 agent. clang -O1 (LLVM keeps float SSA values unrounded on x87) crashes right after frame 0 (a separate workspace) |
| 40 | ambient cows created and deleted every frame from 774 (the cow update 0x000835a0 never runs; hybrid census: once at 775) | the prop factory 0x000796e0 pushes (0, d, c, b, &m, a), builds the name 0x0027b0e0 (`ret 4`) and calls the entity manager's add 0x001dd330 (`ret 0x1c`) with the name and those six words; declared name(text, a, &m, b, c, d, 0) and add(name): natively clang re-reserves its outgoing call frame after a callee-pops call by the bytes the declaration pops (`sub esp, 0x1c`), so the add read six garbage words: the cow's world record was at (0, 4, ...) and 0x0007ee10 deleted it | **check 7 (native_conv_check, listed since native12: 26 symbols)**: these are real natively whenever the definition pops another number than the caller declares (not "harmless by luck": clang's re-reservation moves the next arguments). Fixed: 0x000796e0, 0x001b3320 (explosion effect spawn, `get()->doIt(pos, kind, 0, 0)`), 0x001c5740 (MATCH) and 0x0012f750 (EQUIVALENT). Not fixed: 0x00248670 (tail jumps to 0x0025d740/0x0025d780 with its own stack word; the rewrite fails equiv.py), the save streams 0x002786a0 / 0x002786c0 (0x0027a370 / 0x0027a460 pop 32 / 36), 0x002ad7f0, and the destructor / adjustor callers (most are tail thunks jump_shapes re-emits) |

**Next divergence (open, stop 41)**: census first frames agree to 914 except 0x00203a80 (the region-name builder:
hybrid 914, native 915), called by 0x00207410 when a streamed resource's state (0x00266710) reaches 3: an I/O
completion one frame later natively (play3 was recorded without the hybrid's syncio; see native11 pin H). From
953 on the census parts further (0x00013f20 953 vs 1007, ...). Not separated yet from the x87 class.

**Replay status**: frames 0-420, 480, 510, 570, 630 match (native13: 0-420, 480, 510); 450, 540, 600, 660, 690
differ only in the camera's y by 1-14 ULP (x87 class); from 720 on more. The image plays all of play3 (to frame
76,500 with the recording's end at 56,566) without a crash. The trace census agrees with the hybrid's first-call
frames for every probed function to frame 914 (native13: 441).

**Probe aids** (src/platform/sdl/xdk/startup.cpp, tools/native_link.py; diagnostics, not bridges):
`HULK_TRACE_FROM=<frame>` (nothing logged before it), `HULK_TRACE_WATCH=<ptr>:<off>` or `='<addr>'` (logs a
change of 3 words between two probe calls: who wrote it), `HULK_TRACE_EXIT=addr,...` (`fexit` lines: eax, edx,
st0 when the x87 stack holds one; `HULK_TRACE_XDEREF=<0-4, r>`: 16 words at the entry's ecx / stack arguments or
the returned eax after the call). Scratch tools (not committed): camulp.py (which camera ULPs explain a checkpoint),
capcallees.py / capmem.py (a capture's callee results / memory), framestores.py + fsescape.py, natcheck.py /
natreplay.py (equiv.py with the clang object: fuzzing misses x87 differences, and replays of clang objects
misalign on clang's helper calls: not usable yet).

**Checker gaps (cl4)**: (1) equiv.py doesn't compare frame bytes a callee reads through a pointer argument (stop
38). (2) the float tolerance (FTOL) lets ULP differences through; a replay needs bit-exact floats: with exact
comparison an MSVC object of the chase camera 0x000a75d0 still agrees with all 50 recorded calls, so exact
replay is feasible. (3) compare.py / verify_relocs accept a free `__stdcall` declaration of a thiscall callee
(MSVC's ecx is `this` by chance); check 8 is the only guard, now including split names.

**MSVC 7.1 proof and links**: see build/native14/msvc-proof.txt.

## native13: into the first level's gameplay (2026-10-20)

Inputs: native12's workspace (HEAD 8c871013 + native12) for the search, then a workspace rebuilt from HEAD 26a05b20
(ptr1's pointer-width typedefs) plus this round's rewrites (`build/native13/sources.txt`, 6 files) for the final
replay. Same procedure as native12. New probe aids: the probes' `fcall` lines carry `f=N` (GameClock::Update calls,
the frame the checkpoints and the hybrid's trace sessions number), `HULK_CKPT_REGIONS=1` logs the hashed regions of
every logged checkpoint. The hybrid side came from trace session tr1 (mac2 `~/hulk-tr1/build/traces`): its `census`
gives every equivalent/ function's first frame, so probing a few dozen of them natively finds the first frame where
the two runs part without a new xemu run.

| # | stop | cause | class and fix |
|---|---|---|---|
| 34 | first gameplay update 0x000677d0: no main actor | init.lua's SpawnHulk calls `am_CreateActor("hulk", "spawn_hulk", ...)` and on success `am_SetMainActor`. Natively 0x0002c050 found no locator: CTriggerVolumeManager was empty because the locator file's parse (0x00337a30) stopped at the first object: the type schema loader 0x00337700 had registered "HexWorld" and **"HudMap]"**. The tokenizer's one-character token list (ctor 0x003388d0) is the wide string L"()[]{}=;" at 0x00434634 (read as a double-NUL list of 1-char strings by 0x00338640); the source spelled **L"()"**, so `[`/`]` were not tokens | **literal shorter than the original's item**: verify_relocs compares a literal only up to its first NUL (checker gap, below). Scan of the XBE's string items that continue past their first NUL inside the item (`multistr.py`): no other game literal; sources with wide or embedded-NUL literals checked by hand: 0x003388d0 only. Fix: L"()[]{}=;" (MATCH, relocs ok) |
| 35 | Hulk's collision setup: `ret` to 0 in Node::run's callee | CollisionCylinder::vfunc_13 0x002f2fc0 pushes 3 words, calls the callback's slot 4 (SimState::vfunc_4 0x002ef300, `ret 4`) and the transform 0x0022c3b0 (`ret 8`) takes the two left; the source declared slot 4 with all three and passed the two again: natively 8 bytes too many came off the stack | **check 7 through a vftable slot, spelled with the words twice** (equiv.py can't see it: both calls get the same stack words). Scan (`dup_ind.py`: our MSVC compile of each equivalent at native11's 123 chain sites pushes more words than the original): 0x002f2fc0 and 0x0024da50 / 0x0024db50 (native11's patches for these two had never applied); the other "more" sites are register saves or `X()->M()` chains (read by hand). Fixed: the three, `X(a)->M(b)` form, EQUIVALENT |
| 36 | first level, frame 439: Owner::Traverse 0x0030ed60 reads null+0xc | the original keeps the node in **edx across a call** to 0x0030ecb0, which never writes edx (whole-program register allocation); the byte-matched source reads it back as the high half of a 64-bit return | **callee-preserved scratch register**: scan of every binding declared 64-bit whose original callee never writes edx (`edx64.py`): 0x0030ecb0 (0x0030ed60) and the UTF-8 validator 0x002719a0 (0x00271b70 read the text pointer back the same way). 0x00271b70 fixed (`p = text`, EQUIVALENT). 0x0030ed60 can't stay a match (MSVC 7.1 can't keep a value in edx over a call) and **equiv.py can't prove the rewrite**: its `reg_writes` recursion guard assumes a self-recursive callee (0x0030ecb0 calls itself) clobbers eax/ecx/edx, so the original's edx is fuzzed after the call. With the guard set to "no writes" (a scratch copy of equiv.py) the rewrite is EQUIVALENT. Pending: `build/native13/pending/0x0030ed60.cpp` (a demotion once cl3 fixes the guard); the replays below use it as a workspace-only test |
| 37 (open) | gameplay from frame 441: Hulk's head tracker never updates | first frame where the runs part (census vs `f=` probes, 60 functions): 0x00039c60 (target search) runs at frame 445 in the hybrid, at 6628 natively. Its caller CHeadTrackerAction::vfunc_7 0x000202f0 is never called natively: the action is created and started at 439 (vfunc_6) and its node sits in the list Hulk's 0x000366d0 runs with selector 1 (CAction::vfunc_5(1) -> vfunc_8), not in the +0xb4 list 0x0003b7d0 runs with selector 0 (-> vfunc_7), which is empty natively | not found yet: which code puts the head-tracker's spawn node in Hulk's +0xdc list instead of +0xb4 (the fight scenario's node placement, 0x00231ad0 / 0x002322f0 / 0x002324b0 and their callers). The checkpoints from 540 on differ (camera); 450 differs and 480/510 match only because a cinematic holds the camera, the clock is frame-counted and the RNG isn't drawn |

**check 6's 11** (triage): one real, fixed: 0x000fb240 returns the script 0x000faf80 returns (its caller 0x000f5fa0
keeps it; EQUIVALENT; it only needed its own declaration of 0x000faf80 retyped, not 0x000faf80's stuck patch).
0x00104c60 is not: the caller 0x001050d0 loads its own f6c onto the x87 stack before the call and stores it after
(the source models that). The other 9 (0x00090130, 0x001035f0 x2, 0x0022b980, 0x0024c090, 0x0025dbd0, 0x002629a0,
0x00284860, 0x002a5fd0) are tail-returned by wrappers whose own callers are virtual or ignore them (e.g. 0x00029390
is am_SetPatrolParams' handler, its closure returns void): incidental eax.

**Replay status** (workspace from HEAD 26a05b20 + `build/native13/sources.txt` + the pending 0x0030ed60 as a
workspace-only test; `build_tree.py --resume`: 2,818 TUs, 22,343 / 22,343 matches, 0 regressions; strict `lld-link`
0 errors `--gfx`): play3 matches at **frames 0-420 (15 of 15), 480 and 510**; the first level loads, Hulk spawns at
the recorded frame (439, as the hybrid), and the native image then plays **all of play3's inputs to frame 58,500**
(the recording ends at 56,566) in 500 s with `HULK_AUDIO_CLOCK=frame`, with no crash or hang; the checkpoints from 540
on differ (stop 37). 450 differs and 480/510 match only because a cinematic holds the camera while the clock is
frame-counted and the RNG isn't drawn. Without the pending 0x0030ed60 the run stops at stop 36 (frame 439).

**Checker gaps (cl3)**: (1) verify_relocs `literal_bytes` stops at the first NUL, so a wide or multi-string literal
that is a prefix of the original's item passes (stop 34); compare the COMDAT literal's full size. (2) equiv.py
`reg_writes` recursion guard: a self-recursive callee is assumed to clobber eax/ecx/edx (stop 36); the least fixed
point (start from no writes) is sound for self-recursion. (3) equiv.py can't see a virtual declared with more stack
words than its callee pops when the next call takes the same words (stop 35); comparing the total words pushed for
an indirect call plus the following direct call with the original's would.

**Bridges**: none new (the probe/checkpoint options are diagnostics).

**Process (farm)**: `farm/src/farm.ts --upgrade` now skips native_calls.DEMOTE, equivalent/ sources with an
`equiv-conv` register note, and sources naming a function whose own source has one (9 + 487 + 292 of the current
equivalents); `--dry-run` prints the filtered queue and exits.

## native12: past the first level load (2026-10-20)

Inputs: HEAD 8c871013 (`git archive`) plus the 21 untracked sources of other sessions native11's workspace also had
(the replay needs equivalent/0x0029e6c0.cpp: without it the image stops in a missing `Light` constructor) plus this
round's verified rewrites (`build/native12/sources.txt`, 17 files; `removed.txt`: 6 matches/ demoted to equivalent/).
`build_tree.py --resume --jobs 3 --regression-rounds 4`, probe, `native_link.py --gfx`, play3 replay as native11.

**1. Regression check (x64-1's b1-b7 and the uniqueness check).** HEAD's image did not start; each stop was a class:

| # | stop | cause | fix |
|---|---|---|---|
| R1 | start-up, `luaopen_base` reads L from the stack | **a lane re-matched a source native8 had demoted** (matches/0x0033eb30, chatgpt-upgrade 96abba03: `FUN_0033ea90()` with L in esi); likewise 0x00334c00 (`fallback()`) | `reg-call` (native_calls.py): demoted to equivalent/ again |
| R2 | registration: missing `Caster::_m_vf0` | **ambiguous stub vftable**: 0x0012d110 and 0x0012d2e0 declare `Caster` in one TU, each storing another game vftable; with the uniqueness check both are bound (before, one silently took the other's: ThreatBall's factory registered with ThreatDodge's caster) | `unique-class` (4 sources; the rule now renames the constructor too: `Derived_06c740::Derived_06c740`) |
| R3 | before frame 30: particle loader 0x002abfb0 | **dynamic_cast to a renamed class**: b3 renamed `pure3d::AnimationLoader` to `AnimationLoader_2abfb0` (also 0x002abd90, 0x00297680): the RTTI descriptor lookup by decorated name found no game TD, the cast returned null | native_link.py: the TD match also tries the name without an `_<6 hex>` suffix (exact, then leaf) |
| - | (found with them) | check 6/7 findings new on HEAD: 0x0002bf80 declared void (a lane match), the BinkCallback stand-in body 0x00335150 | `void-return`, `stub-body` |

With these, **15 of 15 checkpoints match again (frames 0-420)**. x64-1's renames themselves bound nothing to a wrong
address (verify_relocs and the replay agree); the regressions were RTTI identity (R3) and binding ambiguity the
uniqueness check made visible (R2), plus lane matches of native-fixed functions (R1).

**2. The stops past frame 420:**

| # | stop | cause | class and fix |
|---|---|---|---|
| 31 | fight BinReader reads a hash as a string length | not the file layer (the stream's bytes are misc.rcf's): record "effect" (hash 8b025b6b 1cd0cba1) in the scenario registry created a **NISAnimationTrack**, whose 121 parameters were read over the effect track's 20-word record. vtables.s slot 1 of the effect caster's vftable 0x0041c8b8 named `TrackFactoryCasterTemplate<NISAnimationTrack>::vfunc_1`: 0x001aac50 had been verified under 0x001aa740's symbol (two same-code-shape sources in one TU) | **fixed by build_tree's uniqueness check (5b0eab47)**; no source change |
| 32 | luaE_newthread 0x00215010: stack_init on garbage | **register-convention callee reached under another name**: matches/0x00215010 calls `Init()` (bound by position to 0x00214dd0, `edi esi`); check 5 only looks for callers naming FUN_x | `reg-call`: 5 callers (0x00215010, 0x00216f60, 0x0033db20, 0x001e5720, 0x00334c00) demoted to equivalent/; new **check 12** (native_conv_check.py) finds callers bound to a register-convention definition without its note: 0 left |
| - | `attempt to call field 'sub'` (Lua, from frame 0) | **game strings the linker pooled with library data**: `"sub"` (0x00434bbc) is owned by xgrph.obj in the inventory, so no data TU defines it; natively a 16-byte zero stub, so string.sub was registered under "" | native_host.data_block: 37 such strings the game names, from the XBE (bridge) |
| 33 | getobjname 0x002146f0 on a stripped proto (arithmetic on a nil upvalue) | **check 6, real**: luaF_findupval 0x00219610 declared void; OP_CLOSURE stored its eax, natively `&L->openupval` | void -> `Node*` (MATCH). Same check's other real ones: floor's wrapper 0x00047970 (st0; the propagated name said `_isnan`), uninitialized_copy 0x0030bf40, Lua start_capture 0x0033c6e0, 0x002b2c30 |
| 34 (open) | first gameplay update: 0x000677d0 reads the main actor (CSimDb+0x20 -> +0x124) = null | the setter 0x00025e50 (via `am_SetMainActor`, 0x00025fc0) is never called: the binding is registered (vftable, member pointer, argument types correct), the Lua dispatcher runs 5,000+ times, no Lua error is raised, but no script calls it. In the hybrid 0x00025e50 runs (trace session tr1: 4 calls) | - |

**3. Counts.** Rewrites 17 files (`build/native12/sources.txt`: 10 matches/, 7 equivalent/, all MATCH / EQUIVALENT
at 3000 inputs; equivalents listed in `build/native12/equivalents.txt` for the 20000-input re-check). Conv checks on
the final tree: check 5: 2 (native11 2), check 7: 26 (2 of them the untracked 0x002777e0/f0), check 6: 11 left (native11 20)
(eax kept by callers that return it; 0x000fb240 needs 0x000faf80's result, which its stuck `shared-static` patch
blocks), check 12: 0. Binding: unbound symbols 1,368 (native11 1,577). Strict `lld-link` 0 errors `--gfx`.

**4. MSVC 7.1 proof** (`build/native12/msvc-proof.txt`): base = HEAD + the untracked sources, mine = + this round,
both `build_tree.py --resume` from one state: TUs 2,817 / 2,817, matches 22,316 / 22,310 (the 6 demotions), verdicts
identical for 27,468 of 27,474 (the 6 demoted: match -> equivalent `same`), 0 equivalents differing from their
standalone code. Strict `lld-link` 0 errors plain (7.53 MB) and `--gfx` (10.51 MB).

**5. Tools.** `native_link.py`: RTTI TD names without the address suffix; pooled strings into the data block
(native_host.py). `native_fix.py`: `_ITEMS` cache shared by data-literal and code-literal fixed (the plan crashed),
`unique-class` renames constructors, native12 patches. `native_calls.py`: native12 reg-call groups. `native_conv_check.py`:
check 12. xdk trace options: `HULK_TRACE_WIDE`, `HULK_TRACE_STR`, `HULK_TRACE_PATH` (pointer chains, `@addr`),
`HULK_TRACE_IO` (file_io.cpp).

**6. Process note.** Lanes that upgrade equivalents into matches re-created two sources native8 had demoted
(0x0033eb30, 0x00334c00): a match can't pass a register argument. A lane should skip `native_calls.DEMOTE` and any
source whose callee carries an `equiv-conv` register note.

## native11: the replay matches to frame 420 (2026-10-20)

Inputs: native10's workspace plus this round's verified rewrites (`build/native11/sources.txt`, 35 sources, 16 of them
equivalent/), rebuilt with `build_tree.py --resume --jobs 3 --regression-rounds 4`, probed, linked (`native_link.py
--gfx`), run under Wine with `HULK_INPUT_SOURCE=replay:build/rp1/play3.hrp HULK_CKPT=1 HULK_AUDIO_CLOCK=frame` and a
fresh save directory. Every source edit went through `native_fix.py --apply --verify` (compare.py MATCH / equiv.py
--inputs 3000 EQUIVALENT; the equivalents re-verified under equiv.py round 15).

**1. Frame 0.** The hybrid's frame-0 hash 732dab43 decomposes (brute force over the checkpoint's inputs): the
gameplay RNG in its seed-0 state (7df2f1ba 418a5dfb, the same natively), boot step 6, the camera singleton present
with position (0,0,0), the GameClock's elapsed time 0. Natively the camera's position and the clock's elapsed/step
words were `ff000000`: fields the constructors leave, read from **recycled host memory** (the host malloc behind
the game's heaps returns old blocks; on the Xbox the heaps' arenas are fresh, zeroed pages). Class fix: the game's
`malloc` (0x3479aa and the tree's `malloc`) is `hulk_crt_malloc` (crt_glue.cpp: zero-filled), the shim's HeapAlloc
always zeroes. Frame 0 then matches, and with the pins below every checkpoint to frame 420.

**2. Replay pins** (build/rp1/for-native9.md; docs/native-replay.md):

| request | native11 |
|---|---|
| F no-fmv | `ENTRY_HOOKS` may now return at once (4th field: the `ret` bytes): CFMVManager::QueueMovie 0x1b7310 (`ret 0xc`) and the FMV render 0x1b7d10 (`ret 8`: the hook takes the "status 0, finished" path itself: 0x333ef0, then the manager's stop 0x1b7970) |
| G sound-rng / seq-rng | `SITE_REBIND` (9 sites): 0x964d0 from 0x1ef2a0 / 0x1efe20 / 0x1f7320 -> `hulk_sound_rng` (a private MWC, 0x2F6B6F2A 0x1F123BB5), rand() from 0x260ae0 -> `hulk_sound_rand` (LCG 0x5EED), the RNG pointer 0x4e5acc in 0x2526b0 / 0x253680 / 0x255250 -> `hulk_seq_rng_ptr` (data rebinding), RandInt 0x113e0 from 0x2549a0 / 0x254c80 -> `hulk_seq_randint`. Each caller makes only the hybrid's patched calls (read off the original). Two of the hybrid's seq sites (0x254ed0, 0x2548e0) are in functions without a source (not in functions.csv): reached, they are missing calls |
| H syncio | `EXIT_HOOKS` (new: a wrapper calls the thiscall definition with the caller's stack words, then `hook(this)`): 0x272fc0 (the drive's post) -> `hulk_hook_drive_post` (main thread: wait for drive+0x8c = 0, 2,000 x 1 ms). **Off unless `HULK_SYNCIO=1`**: play3 was recorded without the hybrid's syncio, and an .hrp can't carry it (rp1's bit 13 is seq-rng, the hybrid's HF_SYNCIO is 8192 too). With it on, the audio stream drive keeps a request in flight and the main thread times out 35 times in 30 frames. The forwarder 0x272b60 (`mov ecx, [ecx+0xb8]; jmp 0x272fc0`) that jump_shapes re-emits now jumps to the wrapper (native_link.py points re-emitted forwarders at entry/exit/probe wrappers) |

**3. The stops** (replay path; each fixed as a class where one could be named):

| # | stop | cause | class and fix |
|---|---|---|---|
| 28 | front end: Other_2dfc90 / Matrix::Mult 0x22ca90 on garbage (G5 saw the same after the movies) | **check 7 through a vftable slot**: 0x28faa0 and Scenegraph::vfunc_8 0x296160 push the next call's arguments, call the context's slot 18 (`ret 4`), and the next call takes the words left on the stack; declared as slot18(0, x, y) | patches 0x28faa0, 0x296160 (EQUIVALENT; in 0x296160 the arguments of the root node's call are written so MSVC pushes them before the slot-18 call: equiv.py only verifies that form). Same class, found by check 7's list and a scan of the original (indirect call, then a direct call taking more words than were pushed since: $S/n11/chain.py): the listener-effect types' Create 0x24d840/0x24da50/0x24db50 (stop 30), 0x0e2a60, 0x0e5f70, 0x0becd0, 0x0ef030, 0x0991b0, 0x0e39c0 (the text service's slot 44 and siblings take nothing), the fight reader's error report 0x232cc0 |
| 29 | front-end particles: 0x2d53d0, a null rotation reader | **FourCC constants spelled as data addresses**: 'ROT' 0x544f52, 'LIT' 0x54494c, 'INT', 'CLR', ... fall in the XBE's data range; sources name them `((char*)&DAT_0052cbb0 + 97692)`, `((int)DAT_00544457)` or (propagated getters) `return &DAT_004dd780;` that the link rebinds to the original's immediate. MSVC emits the same immediate; natively they are image addresses, so the channel lookups failed | rule `fourcc` (native_fix.py): a FourCC (three capitals, top byte 0, not a data item's start or a vptr) that the original has as an immediate becomes the literal: 16 sources (12 MATCH, 4 EQUIVALENT: 5 channel type ids, the particle attributes, 'TEX', 'DVD', 'CAM', 'RAD', 'BQG') |
| 30 | first level load: 0x25fb00 | check 7 through slot 3 (row 28) | patches |
| - | (found while reading stop 31) | **check 6**: void definitions whose callers use the result: fight BinReader::vfunc_6 0x23ba20 (an enum read's bool), Node::run 0x232f60 (a dynamic_cast), the tree step 0x241930 (the node it finds), forwarders 0x99d60, 0xad580, 0xad7b0 | patches (MATCH / EQUIVALENT) |
| 31 (open) | first level load, frame ~421: the fight parameter reader (BinReader 0x23be00) reads a 2 GB string length and the heap runs out (0x8d320) | the parameters of the track type 0x1a71e0 are read in the original's order (checked against the hashes of its registration: timeBegin ... blendOutDuration, then `filename`), every reader function matches its original, but the length word of `filename` is a hash: the record's bytes differ from what the reads expect. Not found: a native file/stream layer difference (fs1/RCF) is the next suspect | - |

**4. Replay status**: play3 matches at **every checkpoint from frame 0 to 420 (15 of 15)**: the title, menus and
the new game's setup, with the gameplay RNG, the camera and the clock identical; the run stops in the level load
(stop 31), before the next checkpoint. Every divergence found was a native bug (frame 0: host memory; stops 28-31:
source declarations / constants) or a missing pin (G, F). The I/O-sync pin is built but off for play3.

**5. The normal run** (G5's stop-27 fix pulled): the five boot movies play through and the game loop runs to the
title screen: "Press START" drawn, 8,000+ frames presented, no stop in 330 s. The movie layer's background is black
(build/g5/for-native10.md: nothing presents while movies play; the title's attract loop is one of them). A
synthetic recording tapping START (poll- or frame-keyed) did not leave the title: the attract loop's input path is
not read yet, so the main menu and its draw log are not reached (step 4 open; build/native11/for-g5.md).

**6. Counts**: rewrites **35 sources** (`build/native11/sources.txt`: 19 matches/, 16 equivalent/): fourcc 16, check 7
through a vftable slot 12 (0x28faa0, 0x296160 and the ten of row 28), check 6 6, jump-table case index 1 (0x2787c0, equiv.py round 15).
Conv checks on the final tree and map: check 7 **25 symbols** (native10 32), check 6 **20** (native10 25). Binding:
SITE_REBIND 15 sites (6 + 9), ENTRY_HOOKS 3 (1 + 2 skipping), EXIT_HOOKS 1. Strict `lld-link`: **0 errors** `--gfx`
(10.52 MB) and plain (see the MSVC proof); 1,577 symbols still stubbed.

**7. MSVC 7.1 proof** (`build/native11/msvc-proof.txt`): base = native10's final inputs (this round's 35 files at
HEAD), mine = + build/native11/sources.txt, both `build_tree.py --resume --jobs 3 --regression-rounds 4` from the same
state: TUs 2,810 / 2,810, matches 22,197 / 22,197 in both, **0 equivalents differing** from their standalone code,
per-function verdicts identical for all 27,474 functions, no mode changes; the 16 equivalents EQUIVALENT under
equiv.py round 15. Strict `lld-link` 0 errors plain (7.54 MB) and `--gfx` (10.52 MB).

**8. Tools.** `native_link.py`: `EXIT_HOOKS`, skipping entry hooks, re-emitted forwarders pointed at wrappers,
SITE_REBIND of data names. `native_fix.py`: rule `fourcc`, native11 patches. xdk: replay_hooks.cpp (sound/seq RNG,
syncio, no-fmv hooks, checkpoint log with the I/O and sound-RNG counters, the first divergence's regions),
memory.cpp (HeapAlloc zeroed); crt: `hulk_crt_malloc`.

## native10: past the loader, into the front end (2026-10-19)

Inputs: native9's workspace (HEAD 32bafa21's tree + native9's 244 sources) plus this round's verified rewrites
(`build/native10/sources.txt`, 55 sources, 25 of them equivalent/), rebuilt with `build_tree.py
--resume --jobs 3 --regression-rounds 4`, probed, linked (`native_link.py --gfx`, the binding map rebuilt), run under
Wine. Every source edit went through `native_fix.py --apply --verify` (compare.py MATCH / equiv.py --inputs 3000
EQUIVALENT); every tree build: all TUs compiled, every match matching, 0 equivalents differing from standalone.

**1. The stops** (each fixed as a class where a class could be named):

| # | stop | cause | class and fix |
|---|---|---|---|
| 17 | operator new -> out-of-memory handler 0x8d320: heap 11 (Stream Heap), size 0x021e62f0 | the size was `this`: `CompositeDrawable`'s inline constructor called the allocator 0x263ea0 for its base `DrawableBase()` 0x2a3480. The source's `// equiv-map: ??0DrawableBase@pure3d@@QAE@XZ = 0x002a3480` names the standalone symbol; in the merged tree object the name carries the TU namespace and equiv.py's translation (`_tree_names`) skips `??` names (constructors, destructors, operators), so the binding fell back to instruction pairing | **link**: `tree_explicit` (native_link.py): every equiv-map line matched to the object's symbol with the same demangled name without `fn_<addr>::` (llvm-undname); `build/native/tree-explicit.json` (3; 1 changed). Reported for equiv.py (cl2's) |
| 18 | particle loader 0x2d5640 -> `Animation::GetGroup` 0x288a10 reads a null group list | AnimationLoader 0x289500 compared chunk ids with `&DAT_00121401`: a constant spelled as the address of a `char` data name in .text (natively a stub of the image's data) | **source**: rule `addr-const` (8 sources: chunk ids, a push-buffer method, a function by its address) + `code-table` patches (6 sources: switch case-index tables in .text read as `DAT_<addr>[i]`, the switches written on the value) |
| 19 | Lua parser (`sound\map.lua`) | exprstat 0x21f300's `int values[5]` is the LHS link plus the 5-word expdesc: one word short, primaryexp's `f = NO_JUMP` overwrote `ls->fs` (reached only now: before `code-table`, simpleexp parsed every expression as a table constructor) | **source**: patch (EQUIVALENT) |
| 20 | AnimationLoader's qsort comparator 0x289270: a null group | `DefaultChannelHandler::vfunc_5` 0x28aea0 (the channel's pool sizes, a jump table) had no case 0x12110e and 0x121111 in the wrong group: the pool came out 63 headers short and its data overwrote the group array allocated after it. **The source was EQUIVALENT before and after**: equiv.py's coverage counts the jump table's 12 targets, not its 21 indices | **source**: patch, read off the original table. A static scan of all equivalent/ jump tables (scratch `jt.py`: 122 flagged, mostly index-vs-value noise) is not triaged; reported for equiv.py |
| 21 | front end: DollyScript token list walked into garbage | `CTokenHashed::vfunc_2` 0xfa9c0 (Clone) was `void`; the other tokens' Clones return the copy | **check 11** (native_conv_check `check_virtual_returns`: a `void` override in a vftable slot its family mostly returns a value from, by RTTI; 35) + rule `ret-cand` (27 MATCH/EQUIVALENT) + patch 0xfa9c0 (MATCH) |
| 22 | `FontSet::FUN_000f8970` got a code address as the font name | `v44(t)->FUN_000f8970()`: the getter v44 leaves `t` on the stack, the setter (`ret 4`) takes it (check 7, declared fewer words than the callee pops) | **source**: rule `arg-unshift` (the reverse of arg-shift: X's last words move to M: 0xf5b20 x2, 0x1c7550). equiv.py cannot tell which of two chained calls a stack word belongs to (a second pass of the rule "verified" a wrong move: reverted, the rule now checks M's declared words) |
| 23 | `FEContainer::vfunc_50` 0xee9b0: a container without children | the parser's token-list append `Lst::Put` is inline in 0xfaf80 and out of line in 0xfa870, with **one** function-local static `last` (0x4e09f8, guard 0x4e09fc); each source had its own `static ... last`, so the macro expander's Put never saw the parser's last token and every `$MACRO_INSERT` was lost (the screens' AddSceneGraph/AddLocators lines) | **source**: patches naming the shared item (MATCH, EQUIVALENT). A scan of the original for guard words shared by several functions finds no other instance |
| 24 | (not a stop) | 64-bit results through 32-bit definitions: `FUN_0027b020` (the 64-bit name hash, 173 callers), `GetMicroseconds64` 0x267f40 and 3 more declared `int` | **check 10** extended to 64-bit callers; patches (5 MATCH). 0xfaeb0 left (its `return 0` path only sets eax) |
| 25 | the front end's screen sort: comparator 0xe1e90 -> 0xf6370 -> `Run` 0x2848b0 | `int r = api->B(c, d, 0, &local); api->C(r);`: B pops 8, C (`ret 0xc`) takes (r, 0, &local) (check 7 through a variable) | **source**: patches 0xf6370 (MATCH), 0xf63c0 (the same shape) |
| 26 | Lua `luaD_poscall` 0x215970 filled nils past the stack (script `UpdateMoveList`) | `lua_call` 0x2139a0 rewrites two stack words and tail-jumps to `luaD_call` with its third (nresults) passed through; declared with two | **source**: patch (pass-through class) |
| 27 (open) | the boot movies: `bgfx::copy` from `bgfxTexture::upload` writes through a null block (bgfx's allocator returned 0) after three Bink movies opened | not read yet: the movie frames' texture uploads (pddi/mv1 side) |

**2. How far the game gets**: start-up, loading, the copyright screen (256+ frames), the front end's DollyScript (`frontend\fe_real.txt`: fonts, 44 macros defined and expanded, every screen with its labels, buttons, scene graphs and locators), the screen sort, the front end's Lua (`UpdateMoveList`), the pad device check (`XGetDeviceChanges`) and **the boot movies**: Bink opens three (640x480; 120, 390, 367 frames) and decodes about 665 frames before stop 27 (~29 s into the run).

**3. Replay groundwork** (build/rp1/for-native9.md; docs/native-replay.md):

| request | done |
|---|---|
| A pad-init reads are not polls | `native_link.py` `SITE_REBIND` (per-call-site binding: the calls one function makes to one callee go to another definition): 0x2692c0's XInputGetState -> `hulk_xdk_XInputGetStateInit` (xdk/input_xpp.cpp, `hulk_input_read_init`) |
| B frame hook | xdk/replay_hooks.cpp `hulk_native_frame(clock)`: `hulk_ckpt_update` with the image's 0x4e5ad0 / 0x49fb40 / 0x4e231c and the GameClock; the `--gfx` clock wrapper calls it before the draw-log tick; the first 64 checkpoints also go to the trace |
| C poll rate limit | `ENTRY_HOOKS` (a wrapper in front of a function, every address/vftable caller goes through it): 0x269170 -> `hulk_hook_pad_poll`: with a recording open the interval at +0x12a0 reads 0 |
| D virtual clock / vdate | xdk/timing.cpp: `HULK_VCLOCK=1` or a recording's vclock/fixed-dt/vdate flags: QPC is the hybrid's virtual clock (1 s, +4 ms per main-thread read before the first update, 300 s at the first, +33,333 us per update); SITE_REBIND 0x86450 / 0x87e30 -> `hulk_clock_tick` / `hulk_clock_now`; GetLocalTime = 2006-01-02 12:00 + virtual seconds |
| E new-game seed | SITE_REBIND 0x86630's GetMicroseconds -> `hulk_replay_seed` |
| F tweaks | skip-intro: `hulk_replay_startup` (after the initializers, before main) opens the recording and sets g_BootSequenceStep 6. no-fmv: not done |
| G, H, I, J | not done (sound/seq RNG isolation, I/O sync); I and J are run options (`HULK_AUDIO_CLOCK=frame`, `HULK_SAVE_DIR`), passed through by native_run.py's environment |

Replay run: `HULK_INPUT_SOURCE=replay:<play3.hrp> HULK_CKPT=1 HULK_AUDIO_CLOCK=frame` opens the recording (17,915 entries, 1,886 checkpoints, flags 0x3ecd, tweaks skip-intro + no-fmv, seed 0x1234) and hashes frame 0: **53891aea, the recording has 732dab43 (diverged at frame 0)**. The regions at that checkpoint (logged to the trace): RNG 7df2f1ba 418a5dfb, boot step 6, the camera singleton already set (0x04d69aa8: its position is hashed), the GameClock's +0x10 block 0,0,0,0, ff000000 ff000000 (the elapsed field before the first Update: the constructor leaves it, so it is heap content) ..., rate 0x10000. Candidates for rp1: the camera existing at frame 0 natively, and the uninitialized clock word. With skip-intro the run then takes another path and stops in `Other_2dfc90::g` (not read). A first version of request C zeroed the interval and ControllerXBox::vfunc_20 divided by it: the hook now moves the last-poll time instead.

**4. Counts**: rewrites **55 sources** (`build/native10/sources.txt`: 30 matches/, 25 equivalent/): by rule (one source has two): ret-cand (check 11) 27, addr-const 8, code-table 6, arg-unshift 2 (3 calls), check 10 (64-bit) 5, patches 8 (stops 19, 20, 21, 23 x2, 25 x2, 26). Conv checks on the final tree and map: check 6 **20 definitions / 25 sites** (unchanged), check 7 **33 symbols / 31 addresses** (native9 40/37), check 10 **59** (incl. the new 64-bit case; the 46-odd caller-side ones as before), check 11 (new) **7** left (35 found, 27 verified rewrites, 1 patch). Binding map: 3 equiv-map lines rebound in the tree namespace (tree_explicit), 6 call sites rebound (SITE_REBIND), 1 entry hook. Strict `lld-link`: **0 errors** plain (7.54 MB) and `--gfx` (10.41 MB); 1,579 symbols still stubbed (native9 1,596), 1,217 dispatch stubs.

**5. MSVC 7.1 proof** (`build/native10/msvc-proof.txt`): base = native9's final inputs (the 55 files at HEAD), mine = + build/native10/sources.txt, both `build_tree.py --resume --jobs 3 --regression-rounds 4` from the same state: TUs 2,810 / 2,810, matches 22,197 / 22,197 in both, **0 equivalents differing** from their standalone code, per-function verdicts identical for all 27,474 functions; 2 functions changed mode (wrapped <-> merged).

**6. Tools.** `native_link.py`: `tree_explicit`, `SITE_REBIND` / `site_rebind`, `ENTRY_HOOKS`, the clock wrapper's
`hulk_native_frame` call, a no-op `_hulk_platform_pump` without `--gfx`, HulkShaderCallback's dynamic_cast of the
pddi effects extension rebound to `hulk_cast_self` (build/g4/for-native10.md 8). `native_fix.py`: rules
`addr-const`, `arg-unshift`; native10 patches (`code-table`, `shared-static`, check 10/11 fixes); ret-cand also
takes check 11's findings. `native_conv_check.py`: check 10 (64-bit), check 11 (`check_virtual_returns`).
xdk: replay_hooks.cpp (new), input_xpp.cpp (`XInputGetStateInit`), timing.cpp (virtual clock), threads.cpp (the
main thread's Sleep and long waits pump the window's events, sdlwin's item 4), startup.cpp (`HULK_TRACE_DEREF`,
`HULK_TRACE_LIST` for the probe wrappers; `hulk_replay_startup`), library.cpp (`hulk_cast_self`).

## native9: from the RCF mount toward the first frame (2026-10-19)

Inputs: HEAD 32bafa21's tree (the gen_tree fix: the tree builds again; treefix's ws9) plus this round's verified
rewrites (`build/native9/sources.txt`), rebuilt with `build_tree.py --resume --jobs 3 --regression-rounds 4`, probed
(`clang_probe.py --snapshot --configs msvc`), linked (`native_link.py --gfx`, the binding map rebuilt), run under Wine
(`native_run.py`). Every source edit went through `native_fix.py --apply --verify` (compare.py MATCH / equiv.py
--inputs 3000 EQUIVALENT); every tree build in this round: all TUs compiled, every match matching, 0 equivalents
differing from standalone.

**1. The stops, run by run** (each fixed as a class, then the run repeated):

| # | stop | cause | class and fix |
|---|---|---|---|
| 0 | RCF mount: `FileCompletionRequest::vfunc_7` 0x273700 calls slot 3 of IRefCount's base vftable on a freed CementLibrary | the adjustor thunk 0x2777c0 (`sub ecx, 4; jmp 0x277790`, the IFileCompletionCallback AddRef) was matches/0x002777c0.cpp's clang thunk, which jumped to that source's own `CementLibrary::vfunc_0() {}` | **link**: `jump_shapes` re-emits every adjustor thunk and pure forwarder from the XBE's bytes (207 replaced definitions, 120 bare `jmp` slots without one); **source**: rule `stub-body` (10 sources) |
| 1 | `SwitchToFiber` -> eip 0x0026dc20 | `CreateFiber(d, (void*)0x26dc20, p)`: a function by its XBE address | **source**: rule `code-literal` generalized (35 sources: `((int)(void (__cdecl*)())&FUN_x)`) |
| 2 | hang (new watchdog: `HULK_HANG`) in `File::vfunc_21`'s wait | (a) `LoadStream`'s constructor calls its only virtual `FUN_00263f50`: MSVC 7.1 calls it directly in a constructor, clang through the game vftable's slot 0 (0x00038290); (b) `equivalent/0x00277d00` was `void`, 0x00278010 tail-jumps to it and `FileReadRequest::vfunc_1` tests the read status | **source**: rule `ctor-virt` (12 sources); patch (check 6 now follows `jmp` after a call and tail jumps) |
| 3 | P3D load: a loader's `reader` garbage | `dynamic_cast` in wrapped TUs: clang's type descriptors carry the TU namespace (`.?AVObjectLoader@content@fn_f638de75@@`) | **link**: clang TDs pointed at the game's TD of the same decorated name, or of the one game class with that leaf name (2,731) |
| 4 | PNG sprite: the heap overwritten | png_read_data matches/0x002dd690 (`mov [esp+4], ecx; jmp eax`) passed 1 of the callback's 3 arguments | **source**: patch (the 133 indirect tail calls scanned: no other cdecl one) |
| 5 | missing base destructor of `pure3d::DrawablePrimitive` | stand-in bodies: `pure3d::Sprite::~Sprite() {}` matched as the deleting destructor 0x2be420, whose call goes to 0x2bd430 | **link**: `local_code` (calls to code the object defines itself, by position): 1,187 stand-ins renamed `$standin`, their callers pointed at the address's definition |
| 6 | hang: the U: drive never opens | XboxSaveDrive::vfunc_7 is `bool` (`xor eax, eax; sete al`), `DriveOpenRequest::vfunc_1` calls it as `int` and returns eax | **check 10** (bound caller symbols declaring a 32-bit result for a bool/char/short definition) + rule `ret-widen` (11 of 57 verified as int; the rest set only al in the original: caller side, left) |
| 7 | sound init: a vptr 0 | singleton getters propagated from another function's shape (`return &DAT_004dd780;`, the original returns 0x4e7620) | **link**: per-function rebinding for data names, and into data items with an offset (31) |
| 8 | the same, next getter | two copies of one object: an initializer constructs `((Helper_360170*)0x4e6a68)` (the XBE window's copy), the getter returns the image's | **source**: rule `data-literal` (54 sources: `((int)(hulk_at_<item> + off))`, bound by address) |
| 9 | `TextureFontLoader` | a TD of a source class without the game's namespace (`TextureLoader` vs `pure3d::TextureLoader`) | (row 3, the leaf-name match) |
| 10 | 0x266220: `this` read from the wrong slot | `U64 FUN_00231530(Node*)`: the getter takes nothing, the node is OnEntry's second argument (check 7) | **source**: patch |
| 11 | missing `Caster::_m_vf0` (the fight factories' cast helpers) | one class name in many sources of a TU, each storing another game vftable; the tree merges the declarations, clang's one constructor stores one stub vftable | **source**: rule `unique-class` (117 sources); **link**: an ambiguous stub vftable resolved by the source that declares the class; checks whose source doesn't name their symbol (build_tree's loose lookup took a same-named function: 0x0023d710 compared as 0x0023d420's `Func`) bind nothing |
| 12 | missing `EnergyDoorSetParams` 0x000244c0 (a script binding target) | no source at that address (build/functions.csv names it `D3D8::D3D_SetPushBufferSize`) | **new match** matches/0x000244c0.cpp (MATCH) |
| 13 | missing `PrimGroupBase()` | a wrapped TU's symbol no relocation bound (the source's `equiv-map` names the standalone symbol) | **link**: bound like the same name in other TUs when they agree (20) |
| 14 | `SeqEventChannelSends::vfunc_0` -> 0x25c7c0 -> 0x25abd0: null `this` | `equivalent/0x0025c7c0` declared an `ecx` parameter that is only the `push ecx` making room for a local: its callers' two stack words were read one slot off | **source**: patch (EQUIVALENT) |
| 15 | Lua `cm_SetGravity`: eip 0 | 0x001b46d0 takes three floats and tail-jumps with them to 0x002ece90 (`ret 0xc`); declared with two (check 7) | **source**: patch (MATCH) |
| 16 | `math.randomseed`: missing 0x0034773f; a data TU's `_vtbl_00400888` stubbed as code | srand had no host row; data TUs name vftables `vtbl_<addr>` / TDs `rttiTD_<addr>` | **CRT rows** srand, fwrite, realloc; **link**: `vtbl_`/`rttiTD_` names bound by address |
| 17 (open) | loading geometry in the loader fiber: `operator new` -> the game allocator's out-of-memory handler `FUN_0008d320` (`jmp $`) | a game heap is exhausted: not read yet | - |


**2. How far the game gets** (the final link, `--gfx`, Wine 7.7, Vulkan on MoltenVK): all 457 initializers, `main`,
the game object, the D3D/pddi device (ours), physics, the RCF mount, the drives (incl. U:), sound init on sa1's mixer
(`audio mixer up: ... device open (dummy)`), the script registry and every binding, the loader fiber reading P3D
files (copyright, sprites, PNGs, fonts, audio sequences, geometry), and **the game's own frame loop**:
`T_8ee30::Init` -> `Thing_87940::Target` -> `Target_87630::run` -> `Main::update` 0x000873a0, presenting through the
pddi device's BeginFrame/EndFrame and the display's swap: **256+ frames presented, 8 draws each** (the copyright
screen, drawn by the game from `art\copyright-en.p3d`: a screenshot at frame 200 shows the full legal text), Lua
scripts running from the main loop (`scripts/physics.lua`). The native draw log works (`HULK_GFX_DRAWLOG=1:10:200`:
160 records). The run stops in the loader fiber after ~60 s (stop 17). The hybrid reference log has no copyright-screen
frames, so `drawlog_diff.py` finds nothing to align yet (as expected: the hybrid replay starts later).

**3. Counts** (the final tree): rewrites **244 sources** (`build/native9/sources.txt`: 234 matches/, 10 equivalent/,
one of them the new match 0x000244c0): unique-class 117, code-literal 35, data-literal 54, ctor-virt 12, ret-widen 11,
stub-body 10, patches 5. Conv checks (`native_conv_check.py --returns --pops`, `classify_definition_convs`): check 5
**1**, check 6 **20 definitions / 25 sites** (the jmp-following refinement finds 4 more than native8's 16), check 7
**40 symbols / 37 addresses** (native8 34/33: two fixed here, 8 newly visible through the better binding), check 8
changing **2**, check 9 **1**, check 10 (new) **52** definitions (the 46 the original sets only `al` for are caller
side). Binding map: stand-ins 940, ambiguous names rebound per function 98 (+31 into data items), RTTI TDs 2,731,
checks skipped for sharing a symbol their source doesn't name 1,884. Strict `lld-link`: **0 errors** plain (7.52 MB)
and `--gfx` (10.34 MB, with sa1's/fs1's/mv1's SDL3 backends); 1,596 symbols still stubbed, 1,217 dispatch stubs.

**4. MSVC 7.1 proof** (`build/native9/msvc-proof.txt`): base = treefix's inputs + HEAD's tools, mine = + the 244
sources, both `build_tree.py --resume --jobs 3 --regression-rounds 4` from the same state: TUs 2,810 / 2,810 in both,
matches 22,196 / 22,196 (base) and 22,197 / 22,197 (mine: + 0x000244c0), **0 equivalents differing** from their
standalone code, per-function verdicts identical for every function in both (27,473); 35 functions changed mode
(wrapped <-> merged: renamed classes no longer conflict, or newly do).

**5. Left**: stop 17; check 7's 37 addresses (the main loop will meet them: each a per-site reading); check 10's caller
side; the 2 untracked thunk sources; the `Derived` pair (matches/0x0006c740, 0x0006c790: the rename doesn't compile).
build_tree's loose symbol lookup (bcc61ada) attributes a same-named function of the TU to a check (0x0023d710 as
0x0023d420's `Func`, 1,884 checks share a symbol their source doesn't name): those checks' verdicts are the other
function's; reported, not mine to change.

**6. Tools.** `native_link.py`: `jump_shapes`, `local_code` stand-ins, RTTI TD redirection, data names and
interior addresses in the per-function rebinding, `hulk_at_` names, ambiguous-vftable resolution, the
loose-lookup filter, `HULK_TRACE_FUNCS` probe wrappers (`fcall` lines in the trace: ecx, edx, return address, four
stack words; `HULK_TRACE_MAX`), `slot_aliases.json` (check 10), `--gfx` wraps GameClock::Update 0x00086450 to call
`hulk_pddi_clock_tick` first (G3: draw-log frames numbered like the hybrid's), the SDL3 audio/input backends when
`tools/native_sdl.py` has built them (sa1: xdk/ compiled with `HULK_NATIVE_SDL=1`, hulk_sdl.lib and SDL3.lib
linked; `HULK_NATIVE_SDL=0` turns them off). `startup.cpp`: `HULK_HANG=n` (a watchdog sampling the main and the
game's threads after n s: registers, frames, stack scan), `HULK_FRAME_LOCALS=1` (8 words below each frame
pointer), `HULK_CRASH_PEEK` on hangs too. `native_run.py`: SDL3.dll next to the image, `SDL_AUDIO_DRIVER=dummy`.
`native_fix.py`: rules `code-literal` (generalized), `ctor-virt`, `ret-widen`, `data-literal`, `stub-body`,
`unique-class`, native9 patches. `native_conv_check.py`: check 6 through tail jumps and unconditional `jmp`s,
check 10 (return widths). Host CRT rows: srand 0x0034773f, fwrite 0x003463c7, realloc 0x00347d7a, wcslen (fs1's
library); library.h: 0x003d5e68 is 48 bytes (sa1), 0x00355bc2 is the drive's find-next (`DriveFindNextFile`).
fs1's and mv1's libraries are linked when built (hulk_fs.lib, hulk_movies.lib), their DLLs copied by native_run.py;
`tools/native_sdl.py wine-test` compiles the stand-ins with `HULK_NATIVE_NO_FS` (the find-first forwarder to fs1's
file_io.cpp is the image's).

### Bridges to remove

Build-time bridges that take game code or layout from the user's XBE, or that patch over a source's declarations,
instead of compiling our own source as written. Accepted as tech debt (2026-10-19) on the condition that they go:

| bridge | count | why it exists | what removes it |
|---|---|---|---|
| `jump_shapes` (native_link.py): adjustor thunks and pure forwarders re-emitted from the XBE's bytes | 207 definitions replaced, 120 bare `jmp` slots, 48 `jmp [reg+d]` forwarders | byte-matched thunk sources name the wrong virtual (matches/0x002777c0 & co.); the multiple-inheritance layout the thunks adjust for is only in the XBE | correct class declarations in include/gen with the real base order, so the compiler emits its own thunks (any architecture); then the thunk sources become those classes' overrides |
| RTTI TD redirection (native_link.py): clang's `??_R0` pointed at the game's TDs | 2,731 | wrapped sources' classes carry the TU namespace or no namespace | the real class names and namespaces in the sources (include/gen), so clang's own RTTI matches |
| stand-in bodies (`local_code`): sources' own bodies for callees renamed away | 940 | "same code shape" and other byte-matched sources define a callee's body (`~Sprite() {}`) where the original calls another function | declare, don't define: each such source rewritten to declare the callee (the `stub-body` rule did this for 10 thunk sources) |
| stub vftables pointed at the game's (`vt_` objects, fix 6a), ambiguous ones resolved by declaring source | all stub classes | stub classes stand for the game's classes | the real classes (include/gen) |
| `hulk_at_` / `DAT_` by address, data in the XBE window | 54 sources + the window mapping | sources name data by XBE address | named data (include/decls/data) everywhere |
| `ctor-virt` stand-in virtuals `hulk_slot_<name>` | 12 sources | stub classes made polymorphic by the wrong member | the real class declaration (the member is not virtual) |
| (native10) `SITE_REBIND` call sites named by XBE address (native_link.py) | 6 sites (0x2692c0, 0x86450, 0x87e30, 0x86630, 0x1c1a40) | the replay pins and one dynamic_cast act on single call sites of verified code | the platform calls as such in the sources (a replay-aware clock/input/seed interface), the pddi extension with real RTTI |
| (native10) `ENTRY_HOOKS`: a wrapper at 0x269170 writing ControllerSystemXBox +0x12a4 from +0x12a0 | 1 (2 field offsets) | the replay pin C needs the poll's rate limit off | a named member of the real class (include/gen) and a platform poll policy |
| (native11) `SITE_REBIND` for the sound/sequencer RNG (native_link.py) | 9 sites (0x1ef2a0, 0x1efe20, 0x1f7320, 0x260ae0, 0x2526b0, 0x253680, 0x255250 (data 0x4e5acc), 0x2549a0, 0x254c80) | replay pins G (sound-rng, seq-rng) act on single call sites of verified code | a sound RNG of its own in the sources (the audio code's generator as a named object) |
| (native11) `ENTRY_HOOKS` that return at once (no-fmv) | 2 (0x1b7310 `ret 0xc`, 0x1b7d10 `ret 8`) | the hybrid's no-fmv patches bytes of two functions | a movie-policy interface the FMV manager asks |
| (native11) `EXIT_HOOKS` | 1 (0x272fc0, `ret 0xc`; native15: passes the count before the post and the request) | replay pin H (syncio) and native15's guest-time I/O models after the drive's post | a drive interface with a synchronous mode |
| (native12) pooled game strings copied from the XBE (native_host.data_block `want`) | 37 strings (`"sub"` 0x00434bbc, ...) | the inventory gives a literal the linker shared with a library object to that object, so no data TU defines it | data_gen emits game-referenced strings whatever object the inventory names |
| (native12) RTTI TD match without the `_<address>` suffix (native_link.py) | the renamed classes' descriptors (0x002abfb0, 0x002abd90, 0x00297680 casts) | consolidation renames make the class name differ from the game's | the real class names (include/gen) in the casting sources |
| the empty stubs for a virtual the original doesn't own (the 0x002777c0 class) | 14 sources with an adjustor thunk and an empty out-of-line body: 10 fixed (`stub-body`), 2 are other sessions' untracked files (matches/0x002777e0, 0x002777f0), 2 are constructor/destructor bodies the vftable emission needs (0x00268010, 0x0026e350) | — | (the 2 untracked ones: the same rewrite once they are committed) |
| (native16) return-type binding (native_link.py): a caller's `float f()` reference bound to the definition returning `hulk_freg` (`double`, mangling `N` for `M`) | 186 definitions | MSVC 7.1 leaves those returns unrounded in st0 and the callers' declarations (headers, other TUs) still say `float`; on x87 both come back in st0 | callers declared with `hulk_freg` returns (the headers' members first), then the rule goes; x86-64 needs it gone (a `float` return is a single in xmm0, a `double` a double) |
| (native17) `ENTRY_HOOKS` drive pump: 0x272df0 `core::Drive::vfunc_3` gives the drive threads their turn (lockstep I/O, `HULK_SYNCIO=5`, default with a recording open; xdk/replay_hooks.cpp, threads.cpp, library.cpp) | 1 | native drive threads race the main thread (stop 41: 914 vs 915); the hybrid retires every post in the frame it is made | a drive interface with a deterministic completion policy |
| (sky1) `DATA_REBIND` (native_link.py): data symbols no relocation names, bound to their XBE address | 1 (`pure3d::scenegraph::one` -> 0x004c9f38, the identity Matrix) | unbound data linked as zero stubs (build/native/unbound.txt "no relocation names it"; 23 more to audit) | named data (include/decls/data) defining the object |

## Graphics boundary crossed (G1, 2026-10-19)

The native7 tree (frozen 18:18 sources + native7's 308 rewrites, its snapshot and binding map), linked with
`native_link.py --reuse-map --gfx`, run with `native_run.py` (Wine 7.7). Strict link: 0 errors with and without
`--gfx`. The run, after the backend replaced the d3d layer:

| stop | where | cause (read off the original) | probed fix (scratch tree only) |
|---|---|---|---|
| 1 | physics init `FUN_002f4df0` -> `O_2f7ee0` ctor -> `FUN_002efa90` -> `CollisionVolume::vfunc_10` -> `Node::run` -> `CollisionWall::vfunc_13` (`equivalent/0x0030e870.cpp`) returns to 0x1d2 | `SimState::vfunc_4` (0x2ef300, `lea eax,[ecx+0x10]; ret 4`) takes one argument; the original pushes three and leaves two on the stack as the arguments of the next call, `FUN_0022c3b0(output, bounds)`; the source declares `vfunc_4(unsigned, void*, void*)`, so natively esp is off by 8 | `virtual void* vfunc_4(unsigned int);` and `owner->result->vfunc_4(value)`: **equiv.py --inputs 3000 EQUIVALENT** |
| 2 | drive thread `FUN_0026db70` -> `DriveOpenRequest::vfunc_0` (0x2756e0): `missing ?acquire@Lock_2756e0@core@fn_f0fe475a@@UAEXXZ` | clang calls a member object's virtual function directly (`drive->lock.acquire()`); native_link's `source_slots` didn't match a symbol with a namespace between class and `fn_` | **fixed in tools/native_link.py** (10 more virtual-dispatch stubs) |
| 3 | `FUN_0008e880` -> stream `configure()` -> `core::InstanceDrive::vfunc_24` (`matches/0x00276d60.cpp`) | a pure forwarder (`mov ecx,[ecx+0xc]; jmp 0x272920`) that passes its two stack arguments on; the source calls `g()` with none. `native_fix.py --rule pass-through` plans it but its rewrite didn't compile (`compile_error`, in native-fix.log); 13 such sources are still planned | the snapshot's definitions of every pure forwarder (`mov ecx,[ecx+d]; jmp X`, `...; mov eax,[ecx]; jmp [eax+s]`: 70 functions) as naked asm doing exactly that (probe tool `probe_forwarders.py`); a source-level fix is native-build work (MSVC 7.1 `__declspec(naked)` + `__asm` would byte-match) |
| 4 | `File::vfunc_18` (`equivalent/0x00276160.cpp`) and `InstanceDrive::vfunc_19` (`equivalent/0x00276c10.cpp`) | the three words pushed before `call FUN_0026dbb0` (no arguments, plain `ret`) are the constructor `FUN_00274ca0`/`FUN_00274d80`'s (4 arguments, `ret 0x10`): the sources declare `FUN_0026dbb0` `__stdcall` with three (check 7 lists both) | `extern void* __cdecl FUN_0026dbb0();`, `FUN_00274ca0(void*, core::File*, unsigned, unsigned)` / `FUN_00274d80(void*, core::InstanceDrive*, unsigned, unsigned)` called as `(FUN_0026dbb0(), this, a, b)`: **both EQUIVALENT** |
| 5 (open) | RCF mount: `thunk_FUN_00271560` -> `FUN_00277b70` -> `CementLibrary` ctor (`equivalent/0x00277a70.cpp`) -> `File::vfunc_18` -> ... -> `FileCompletionRequest::vfunc_0` (0x274d20) releases its `CementLibrary` (the `IFileCompletionCallback` subobject at +4) and `CementLibrary::vfunc_1` (0x2777b0) gets `this` pointing into vtables.s | not read to the end: the ctor's explicit base constructor calls on a 4-base class, the adjustor thunks matched by byte shape (0x2777c0/0x2777d0 `sub ecx,4; jmp X`: identical bytes for any of the class's thunks once the jump is masked; the verification build names 0x2777d0 after `a`'s thunk), and the stub vftables of that class are the suspects | - |

Stops 1, 3 and 4 are the classes native8 works on (check 7's callee-pops list has 0x26dbb0, 0x274ca0 and 0x272920;
0x2ef300 is a virtual callee, which check 7 can't see by symbol): "the pushes belong to the next call", and pure
forwarders. The verified rewrites for 1 and 4 are in the G1 report for `native_fix.py`'s verified path (G1 did not
change `matches/` or `equivalent/`). Tools for crash hunting added to `src/platform/sdl/xdk/startup.cpp`'s crash
report: a scan of the stack top for return addresses into the image (the frame chain is useless after a stack
imbalance: `scan esp+... ` lines, symbolized by native_run.py; `HULK_CRASH_BELOW=n` starts n words lower),
`HULK_CRASH_DUMP=1` (0x40 bytes at each register) and `HULK_CRASH_PEEK=addr,...` (heap layouts repeat between runs).

## native8: the native-only bug classes, batch by batch (2026-10-19)

Checks 5-9 of [Start-up, part 3](#start-up-part-3-2026-10-18-night) worked through as batches, each fix through
`native_fix.py --apply --verify` (compare.py MATCH / equiv.py --inputs 3000 EQUIVALENT, file unchanged meanwhile),
counts re-measured after every batch on a full tree build + clang probe + link. **423 verified rewrites, 409
sources and 3 `include/gen` headers** (`build/native8/sources.txt`); 3 matches became equivalent/ sources.

**Inputs.** HEAD's own MSVC tree build currently fails 590 of 2,808 TUs (since 4dfc66ea: gen_tree hoists the
`TypeTag<...>` specializations of fx17's new /GS match `matches/0x000c0aa0` & co. into the shared
`build/tree/include/game/global.h`, which the `.GS` TUs see without `decls/data/game/unknown.h`: `DAT_0048e100`
undeclared). So the measurements and the proof use the last buildable state (native7's final tree: the 18:18
frozen copies + native7's 308 sources) with this round's sources on top. The generator needs the fix, not the sources.

**1. Counts per batch** (`native_conv_check.py --returns --pops` + `classify_definition_convs`; checks 5 and 9 with
this round's check refinements, see 3.):

| after | check 5 | check 6 defs / sites | check 7 symbols / addrs | check 8 changing (defs) | check 9 |
|---|---|---|---|---|---|
| start (native7 final) | 4 (1 after refinement) | 72 / 386 | 221 / 158 | 309 (197) | 10 (8 after refinement) |
| batch 1 (check 8: this-cand, arg-shift, hand groups) | 1 | 72 / 386 | 159 / 120 | 79 (60) | 2 |
| batch 1b (base-ctor, this-cand/this-wrap, C-linkage callers, hand groups) | 1 | 72 / 386 | 159 / 119 | 40 (32) | 1 |
| batch 2 (check 6: ret-cand, hand groups; G1's 3 probe fixes) | 1 | 34 / 70 | 120 / 92 | 9 (9) | 1 |
| batch 3 (check 7: closures, include/gen pass-through, getters, demotes) | 1 | 24 / 42 | 71 / 52 | 2 (2) | 1 |
| batch 4 (check 7/6 leftovers by hand) | **1** | **16 / 21** | **34 / 33** | **2 (2)** | **1** |

Strict `lld-link` links after every batch (1,726 undefined symbols, 1,276 dispatch stubs).

**2. What the bugs were** (all byte- or equiv-verified, all invisible to the MSVC match):

- *Thiscall callees called as free functions* (check 8, 230 rewrites by `this-cand`): member functions whose
  first call passes the incoming `this` on (`FUN_00019420()` in the "same code shape" sources), base constructors
  called by name, and **this-wrap**: free `__stdcall` wrappers whose original never touches ecx and passes it on
  (`bool FUN_001fc9d0(int x) { return FUN_001fc7f0(x); }`, the `Table::FUN_001fc7f0` and `Registry_e7260`
  families): the wrapper itself becomes a member, its callers the next level. Hand-read ones where ecx was a field
  (`m0`, the notifier at +0x1d94, the channel at +0x8c, the allocator word).
- *Arguments that belong to the next call* (checks 7 and 8, `arg-shift` 39 + ~40 by hand): a getter that takes
  nothing (`mov eax, [ecx+0x34]; ret`; the singleton getter 0x001c3d90) declared with the words MSVC pushed early
  for the call after it: `Make(1, 0.5f, 0, 0)->Act()` is `Make()->Act(1, 0.5f, 0, 0)`; natively the getter
  popped words it never got. Two of them (0x00117da0, 0x0011c9a0) also overran their local: the init 0x001ca2e0
  writes 0x5c bytes at the packet's start, the source had a 12-byte "prefix" plus an 80-byte text.
- *Pass-through wrappers* (check 7): `mov ecx, [ecx+d]; jmp callee` forwarding the callers' words. MSVC 7.1 keeps
  the tail `jmp` when the wrapper declares and passes them (byte-identical, also through a vftable slot). 13 of them
  are `include/gen` virtuals: `core::IDrive`/`InstanceDrive::vfunc_24..32`, `pure3d::ShadowSkin::vfunc_24`,
  `pddiExtGammaControl`/`d3dExtGammaControl::vfunc_1,2`, `pddiExtVertexProgram`/`d3dExtVertexProgram::vfunc_1`,
  `FEThingsBase`/`FEThings::vfunc_40`: the headers changed and **every source that includes a gen header and names
  those classes (68) re-verified** with them. The 11 script-binding `Closure2<...>::vfunc_2` overwrite their first
  word and pass two on to `Method2::vfunc_2` (`ret 0xc`); the deleting-destructor thunks pass the flags word.
- *Void definitions whose callers use the result* (check 6, `ret-cand` 28 + by hand): tail calls of float helpers
  (`atan2`-style 0x00224ea0, the angle wrap 0x0004af40: 151 of the 386 sites), `int Run() { ... return r; }`
  loops, luaH_setnum (`return the slot`), luaM_growaux (`return the block` past the stores), `_vsnprintf`'s count.
- *Register-convention leftovers*: Lua's DumpFunction declared its `equiv-conv` callees `__stdcall`; the heading
  getter 0x000354c0 and 0x00225b30 took stack words from the next call; 0x002d0950 is a thiscall member with three
  words (its note had made it a five-argument `__cdecl` function; the edx word only fed the upper bytes of a bool).
- *Demoted* (MSVC 7.1 can't keep the original's register): 0x00087990 (jumps with ecx = the tested field),
  0x001bc710 (call; jmp forwarding a word), 0x00334c00 (the movie owner's member takes `this` in esi).

**3. Tools.** `native_fix.py`: candidate rules `ret-cand` and `arg-shift`; `this-cand` extended (constructors with
`HULK_THIS_CAND_CTORS=1`, one-register `__fastcall` definitions, members after an `ecx ...` note, this-wrap,
C-linkage caller symbols mapped through `extern "C"` declarations); `HULK_FIX_SKIP` (sources no rule may touch:
`build/native8/protected.txt`). `native_calls.py`: the native8 hand groups (each with its call-site reading).
`native_conv_check.py`: check 5 accepts a `__fastcall` caller of a `__fastcall` definition with an `ecx [edx]`
note and structures passed by value; check 9 sees a note's member declaration further down; check 7 leaves out
definitions with a register note; check 6 treats `or eax, -1` as a write and counts a caller that only returns the
callee's eax when its own result is used; check 8's call shape knows fastcall members and `__int64` parameters, and
a C-linkage caller of a definition that reads no ecx/edx is no longer "changing".

**4. Left** (the after-batch-4 row):

- check 5 (1): `equivalent/0x0033d400` (str_format) still fails equiv.py unedited (native7 5.).
- check 9 (1) / check 8 (2): `equivalent/0x000e07c0` -> 0x0008ef00 (a thiscall reading nothing from the stack;
  equiv.py models the original's tail `jmp` as passing arguments and refuses the member call); 0x002ad7f0
  (`Obj::Target` sets the word where a `__cdecl` member's `this` sits and jumps to the cdecl 0x00266f00: a vftable
  slot of `__cdecl` shape, no direct caller).
- check 7 (34 symbols): mostly single sites of the same "next call's words" shape inside larger equivalents
  (0x001dd330 / 0x0027b0e0 request builders, 0x0027a370 / 0x0027a460 save writers, the `B`/`C` pair 0x002843a0 /
  0x002848b0), and the `ThisNote` callers of 0x0025d740/0x0025d780 (equiv.py needs the forwarded word).
- check 6 (16 / 21): callers (mostly equivalent/) that use an incidental eax of the callee (a loop index, the
  last pointer): per-site, the value has to be named in the callee or computed in the caller.
- Not this round: CementLibrary 0x00277a70 hands `this` as `IFileCompletionCallback*` (+4, correct in the source);
  FileCompletionRequest 0x00274d20 then calls back through the game's vftable at 0x0042bf98, whose adjustor thunks
  are the native link's (vftable / thunk binding), not a source bug.

**5. MSVC 7.1 proof** (`build/native8/msvc-proof.txt`, local): base = the frozen inputs above + HEAD's generator,
mine = + this round's 409 sources and 3 headers, both `build_tree.py --resume --jobs 3 --regression-rounds 4`:
TUs 2,726 / 2,730 all compiled; matches 22,124 / 22,122 all matching; equivalent/ 5,348 / 5,350 compiled, **0
differing** from their standalone code in either. Per function the verdicts are identical (27,468 / 27,472) except
the 3 demotes (match -> compiled, by design) and `0x000d8030` (its match is newer than the frozen inputs: the
overlay brings it in). 19 functions changed mode (13 wrapped -> merged: fewer conflicting declarations).

## Start-up, part 3 (2026-10-18 night)

From the Lua VM to the D3D device. Inputs: frozen copies of the live tree at 18:18 (HEAD d3c0fb15 plus the
untracked equivalent/ files then present; fx17's /GS installs after that are not in these measurements) with this
round's rewritten sources on top, `clang_probe.py --snapshot --configs msvc`, `native_link.py`, Wine 7.7
(`native_run.py`). Every source edit went through `native_fix.py --apply --verify` (compare.py MATCH /
equiv.py --inputs 3000 EQUIVALENT, file unchanged meanwhile; log `build/native-fix.log`, list
`build/native7/sources.txt`): **308 sources**, 3 of them matches/ that became equivalent/ sources.

**1. The trace, run by run:**

| run | stopped at | cause | fixed where |
|---|---|---|---|
| 21 | luaL_openlib 0x003390d0 -> lua_type 0x00212f00 -> index2adr 0x00212bb0 | index2adr is a `__fastcall` match (idx ecx, L edx); its 14 callers declared it `__cdecl` with an `ecx edx` / `edx ecx` note: natively they pushed both words (new check 9) | **source**: declared `__fastcall` (14 sources, rule `reg-call`) |
| 22 | luaL_openlib -> lua_setfield -> luaV_settable 0x00217980 writes through garbage | luaH_get 0x00219e90 and luaH_set 0x00219ef0 were `void` (their callers use the slot they return; check 6) | **source** (by hand) |
| 23 | luaopen_table 0x0033b560 -> luaL_openlib | `matches/0x0033b560.cpp` passed the string literal `"$IC"` for the `luaL_reg` table at 0x004348a0: compare.py matched the literal by the bytes at that address (the table's first pointer reads `$IC\0`); natively it is a 4-byte string. The same for the game's own table `"h$B"` in `matches/0x001d3c90.cpp` | **source**: `(const char*)DAT_004348a0` / `DAT_00422458` |
| 24 | the game object is built; `T_8ee30::Init` -> 0x00088020 -> 0x0008e880 -> `Registry::Add` 0x001d3b70 | the script Registry's singleton getter 0x001d4c90 was `void` (119 call sites use eax) | **source** |
| 25 | script bindings registered, D3D device created ... `d3dContext::v66` 0x00321b70 | see below | (run 26 = the final tree: same point) |
| 26 | **`T_8ee30::Init` -> 0x0008e880 -> 0x0008dec0 -> 0x00292560 -> `d3dDevice::vfunc_8` 0x0031b860 -> `pddiBaseContext::vfunc_99` -> `vfunc_102` -> `pddiStencilState::vfunc_0` -> `d3dContext::v66`** | pure3d's d3d backend (game code) writes D3D's own render-state cache at its XBE address: `*(int*)0x39de28 = v;` (`matches/0x00321b70.cpp`), inside the D3D library section, which the image doesn't map (its XBE window is 0x003f0000-0x0058a000) | open: the graphics boundary (the pddi/bgfx backend replaces pure3d's d3d layer; a stand-in for D3D's state words would be the D3D shim's) |

Between runs 24 and 25 the Lua binding objects: their base constructor `Function::Function(name, nargs)` 0x001d0480
(and the fight actions' 0x00232660, conditions' 0x00234590, ...) was called through free `__stdcall`
declarations (`Base(const char* s) { FUN_001d0480(s, 1); }`, `RegisterMethod(a1, 2)`, `BaseInit(...)`) with `this`
in ecx by chance: rule `base-ctor`, 135 sources (they still byte-match: the base class `Ctor_<addr>`, empty or
with a virtual function when the vftable pointer comes first, and its mem-initializer give MSVC 7.1 the
original's bytes).

**2. Verified-source bugs: classes and checks this round** (`tools/native_conv_check.py`; findings at the start of the
round / after it, on the same tree build):

| class | check | start | fixed | left |
|---|---|---|---|---|
| register-convention callers (no note, or a list without a register the definition reads) | 5 | 154 (64 + 90) | 150: the Lua VM (all), lundump's `error(S, ...)`, the text-encoding dispatchers' tail calls (36), phantom registers removed from definitions (0x00035ab0 is a `bool` thiscall member, 0x002e7560 returns `ax`, 0x0024b920's `ebx` was a register save) | 4: 2 benign (0x000e0850 / 0x000e0e50 note a `Vec3` by value per parameter, the definition per word), 1 benign (0x00271b70 now declares 0x002719a0 `__fastcall`; check 5 doesn't read conventions), `equivalent/0x0033d400` (below) |
| callers' notes for definitions without one, against the definition's real convention (`__fastcall` / thiscall matches called `__cdecl` with a register note; a `__cdecl` definition with a register note in a caller) | **9 (new)** | 30 | 20 (`__fastcall` declarations, member calls `((ThisNote_x*)p)->f()`, phantom register arguments dropped) | 10: five thiscall getters called with stack words that belong to later calls (0x00014d40, 0x00115e20, 0x001259c0, 0x0013d7b0, 0x00248670: per-site rewrite), a tail call equiv.py can't verify (0x000e07c0 -> 0x0008ef00: a thiscall without arguments, the original's `jmp` passes its frame on), 4 benign (member declarations, a callee reading no argument) |
| a definition with an equiv-conv note declared `__fastcall` (natively its second argument travels in edx) | (by hand) | 4 + 1 caller | 5 | 0 |
| `void` definition whose original callers use eax | 6 | 105 definitions (966 sites) | 34 rewritten (33 fewer): rule `void-return` now sees `extern "C"` callees and calls through function-pointer members (9), new rule `return-param` (22: `return out;` in vector ops, singleton getters), by hand (luaH_get, luaH_set, the Registry getter) | 72 (386 sites) |
| caller symbol in another convention than its definition | 8 | see the split below | 152 call symbols: rule `base-ctor` (135 sources), new rule `this-cand` (8), `this-note` (6) | 309 behaviour-changing |
| data tables passed as string literals | (scan) | 2 | 2 | 0 found (a scan of short literals with `$@^` etc.; no general check yet) |
| declared callee-pops bytes differ from `ret N` | 7 | 223 symbols / 160 addresses | 2 | 221 / 158 |

**3. Check 8, split** (`native_conv_check.classify_definition_convs`: each *called* caller symbol bound to a
definition of another convention, as the machine call; the registers the definition really reads come from
equiv.py's `reg_inputs` on the original, read-only): `identical` = the same registers set, no stack word read
that isn't pushed, the same cleanup (a `__cdecl`/`__stdcall` caller of a 0-argument stdcall, a thiscall caller of a
one-dword `__fastcall` such as `Normalize(float*, void*)` whose second register is never read, ...); `changing` =
natively the definition reads a register the caller doesn't set, stack words it doesn't push, or the stack is
cleaned up twice or not at all.

| pair (caller, definition) | identical | changing (start -> now) | unknown |
|---|---|---|---|
| thiscall, fastcall | 3,294 | 25 -> 25 | |
| thiscall, cdecl | 1,107 | 5 -> 5 | 26 |
| thiscall, stdcall | 375 | 4 -> 4 | 9 |
| stdcall, thiscall | 2 | 239 -> 120 | |
| cdecl, thiscall | 8 | 113 -> 94 | |
| fastcall, thiscall | 172 | 4 -> 4 | |
| cdecl, fastcall | 7 | 48 -> 34 | |
| stdcall, cdecl | 4 | 23 -> 23 | 16 |
| fastcall, cdecl | 28 | | 1 |
| **all** | **4,997** | **461 -> 309** (222 -> 197 definitions) | **52** |

The doc's earlier "1,497" were all *bound* cdecl/stdcall symbols of thiscall definitions; 362 of them are called
(352 changing at the start, 214 now), the rest are only referenced by address.

**4. Tools.** `tools/native_fix.py`: rules `reg-call` (hand-read edit groups in the new `tools/native_calls.py`,
each with the call site's reading; `DEMOTE`: a match whose call needs esi/edi/ebx becomes an equivalent/ source,
written only if equiv.py finds it equivalent and promotable, the match removed), `this-note`, and three
candidate rules verified candidate by candidate (`return-param`, `base-ctor`, `this-cand`; they need
`HULK_TREE_REPORT`, `HULK_TREE_MANIFEST`, `HULK_BINDINGS` of the tree build and link); `void-return` fixed for
`extern "C"` declarations (blanked string `"C"`) and function-pointer members. `tools/native_conv_check.py`:
check 9 (with `--returns`), `classify_definition_convs`; a note without locations no longer swallows the next
line (`CONV_NOTE`), and `target`/`run` notes count as the definition's own (check 5 had missed their callers).

**5. `equivalent/0x0033d400.cpp` (str_format) fails equiv.py unedited:** one directed `+patch` input (input 5) of
2,000 (1,252 more inconclusive, the cap hit): the original calls `luaL_prepbuffer` 0x00339470 where ours calls
`isdigit`, then the runs diverge. Two real differences in the source for the native build: its `buff[120]` is
512 bytes in the original (Lua 5.0's `MAX_ITEM`; `%99.99f` can overflow 120 natively), and its frame puts
`b.p` 4 bytes off the original's (`esp+0x3c` vs `esp+0x38`). With `buff[512]` and without the `unused` word the
frame matches the original's (size 0x43c+, `b.p` at 0x38) and the same single input still fails, so it isn't
the layout: left for an equiv.py look at that input (not written; its check-5 order finding stays).

**6. MSVC 7.1 verification build** (`build/native7/msvc-proof.txt`): the frozen 18:18 copies; HEAD = HEAD's
`gen_tree.py`/`build_tree.py` (`runbase.py`) with the frozen sources, this = the same generator (this round
changed none) with the 308 rewritten sources (and the 3 demoted matches removed), both `build_tree.py --resume
--jobs 3 --regression-rounds 4` from the same fallback state, local:

| | HEAD | this |
|---|---|---|
| TUs compiled | 2,723 / 2,723 | 2,726 / 2,726 |
| matches byte-matching | 22,127 / 22,127 | 22,124 / 22,124 (3 demoted) |
| equivalent/ compiled, same code as standalone | 5,345 (5,293 same, 51 no_symbol, 1 standalone_compile_error) | 5,348 (5,296 same, same split otherwise) |
| equivalent/ differing | 0 | 0 |
| merged / wrapped / isolated | 20,473 / 6,136 / 863 | 20,473 / 6,135 / 864 |
| fallbacks wrapped / isolated | 432 / 401 | 433 / 402 |

Per function the verdicts are identical (27,469 / 27,472) except the 3 demoted functions (`0x002151e0`,
`0x00339270`, `0x0033eb30`: match -> compiled equivalent, by design). Nine functions changed mode (wrapped <->
merged/isolated: `0x00027930`, `0x000e39c0`, `0x000fb110`, `0x0021e300`, `0x0021ee70`, `0x0024b920`,
`0x002bfb20`, `0x002bfb70`, `0x002bfd30`): a rewritten declaration now conflicts, or no longer does, with
another source's in the same TU; each still matches or compiles to its standalone code. Two sources
(`equivalent/0x000c4220`, `0x000e39c0`) got fx17's /GS version installed over this round's rewrite while it ran;
the rewrite was applied again on top (verified) and the proof's second build includes both.

**Compiling and link** (the final tree): `msvc` **2,724 / 2,724**; data TUs 1,078 / 1,078. Binding map: 56,897
referenced symbols, 56,663 bound, 234 ambiguous. Strict `lld-link`: **links (0 errors)**, 7.49 MB; undefined after
binding 1,722 symbols / 2,924 references (1,690 / 2,892 before: the 32 more are virtual members of clang's stub
vftables for the new polymorphic `CtorV_` bases); virtual-dispatch stubs 1,262.

**Start-up trace summary** (run 26): xbe-window mapped; 466 initializers, 457 run, 9 library ones skipped; `main`:
`XGetLaunchInfo`, `XInitDevices`, the thread/fiber system, the drive (`GetDiskFreeSpaceExA`, `XGetDiskSectorSizeA`,
`CreateFileA`, `GetFileSize`, `SetFilePointer`, `ReadFile`, `CloseHandle`), the game object (Lua VM with its
libraries, the script registry, every binding), then `T_8ee30::Init` and the display: `Direct3D_Object`,
`D3D_GetDeviceCaps`, `XGetVideoFlags`, `D3D_SetPushBufferSize`, `Direct3D_CreateDevice`, `D3DDevice_GetGammaRamp`,
`GetRenderTarget2`, `D3DSurface_GetDesc`, `CreateTexture2`, `D3DResource_Release`, `SetVerticalBlankCallback`,
`SetTexture`, `SetPalette`, texture and render states, `SetPixelShader`, `GetCreationParameters`,
`D3D_CheckDeviceFormat`, `CreateVertexBuffer2`, `Get/SetViewport`, `SetTransform`, `SetRenderState_CullMode`,
`ZEnable`, `FillMode`, `FogColor`, `StencilEnable` (55 distinct imports), and the stop above.

**Next** (in order):

1. The D3D seam: pure3d's d3d context writes D3D's state cache at XBE addresses in the D3D section
   (`0x39de28`; the "absolute-address-cast" scan lists 75 such casts in 54 sources): with the graphics agent
   (the pddi/bgfx backend replaces that layer; a D3D-shim state block at those addresses would let the d3d path
   run meanwhile).
2. Check 8's 309 behaviour-changing calls (197 definitions): the free `__stdcall` callers of thiscall lookups
   (`Table::FUN_001fc7f0` 13, `Registry_e7260` 7, `Table_1def30` 7, ...) whose ecx was a global or another call's
   result: per-site readings, as `reg-call`.
3. Check 6's 72 definitions, check 7's 158 addresses, check 9's 10.

## Start-up, continued (2026-10-18 evening)

From init 308 to the Lua VM inside `main`. Inputs: the tree `tools/build_tree.py` builds from the live sources plus
this round's 263 rewrites (frozen copies, see the MSVC proof below), `clang_probe.py --snapshot --configs msvc`, the
binding map rebuilt from that tree.

**1. Data layout** (`native_host.data_block`, `native_link.py`: `build/native/link/data.s`). The data TUs
(`tools/data_gen.py`, unchanged; still byte-verified under MSVC 7.1) are compiled by clang as before, but their
objects no longer go into the link: each item is copied out of its object (its bytes and its DIR32 relocations, so
exactly the verified data TU's contents) and placed in one assembly block per XBE section (`.rdata`, `.data`, the
`.bss` tail) at the XBE's distance from its neighbours (gaps up to 64 KB zero-filled; vftables, RTTI and library
data are elsewhere in the image), each block starting at its first item's address modulo 16. A structure the
inventory split into several items (the `om` type tree's header at 0x004e79b8: root, then the nil node at +4) is
contiguous again, and so is any structure whose owner object was guessed wrong. 18,832 items from 1,078 objects,
3 blocks, 0 items whose bytes differ from the XBE outside relocations (checked at link time). Run 9's crash is gone.

**2. The trace, run by run** (Wine 7.7, `native_run.py`; each source fix through `native_fix.py --apply --verify`):

| run | stopped at | cause | fixed where |
|---|---|---|---|
| 10 | init 329 (0x0035fd90, `audio::SeqEventChannelSendVolumesType`) | `matches/0x0024ed10.cpp` passes five arguments to a `Data(...)` constructor; the callee 0x0023fc40 pops two (`ret 8`, a string init), the base constructor 0x002605e0 after it reads the other three: natively the stack is 12 bytes off | **source** (patch), and the same shape in 12 more audio type constructors (rule `split-temp`) |
| 11 | init 349 (0x003604d0) | `equivalent/0x00251b40.cpp`: the same family, written with an equiv-conv note claiming five stack words | **source** (patch) |
| 12 | `main` → 0x00270f10 → ... → `XboxDrive::vfunc_21` | `equivalent/0x00277260.cpp` tail-calls 0x0026fcf0 with three arguments; the original's `jmp` hands on all four of its own | **source** (patch) |
| 13 | `main` → 0x00265b70 → 0x0026dbf0 | `matches/0x0026dbb0.cpp` defines `LockFn EnterPtr = 0;` where the original calls through the kernel thunk slot 0x003f2c8c: natively the source's own null pointer | **link**: source-defined globals pointed at the game's item (below) |
| 14 | `main` → 0x0008fca0 → file open | `matches/0x00275db0.cpp` `sub.F0()` on a member object: MSVC 7.1 calls through the vftable, clang devirtualizes to the stub class's `F0`, which nothing defines | **link**: virtual-dispatch stubs (below) |
| 15 | same | an ambiguous name rebound per calling function lost its alias (`native_link`: a stub was emitted for a symbol an alias covers) | **link** (our bug) |
| 16 | same, `A_272b60::run` | `return p->f();` whose original `jmp`s to f (`ret 0xc`) passing its callers' three arguments on | **source** (rule `pass-through`, 48 sources) |
| 17 | same, `Drive::vfunc_3` | `lock.acquire()` devirtualized; the stub class lives in a wrapped block's namespace | **link** (the slot reader now finds wrapped blocks' classes) |
| 18 | `main` → 0x0008fca0 → `FileCloseRequest` | `matches/0x00275110.cpp` declares the thiscall constructor 0x00274e60 as `void __stdcall FUN_00274e60(void*)`; ecx held `this` in the original | **source** (patch, and rule `this-call`: 19 sources) |
| 19 | `main` → `T_8ee30` constructor → Lua `luaH_new` (0x00219cc0) | calls two register-convention functions (`esi edi stack`, `ebx esi stack`) with only their stack word and no equiv-conv note | **source** (patch) |
| 20 | **`main` → `T_8ee30` constructor → 0x001d3c90 → `matches/0x0033eb30.cpp` → 0x0033ea90** | 0x0033eb30 calls the register-convention function 0x0033ea90 (`esi`) as a plain call: MSVC happened to have the argument in esi, clang doesn't (check 5, callers without a note); a match, so the fix is a rewrite to an equivalent/ source | open: where this round stops | |

**3. Verified-source bugs: the classes and the checks** (`tools/native_conv_check.py`; all invisible to the byte
match and, where equiv.py maps arguments to the original's registers or stack words, to equiv.py):

| class | check | found | fixed this round | left |
|---|---|---|---|---|
| register-convention parameter order (callers list the callee's parameters in another order than its own note) | 5 | 166 callers in 98 files | 76 callers (rule `register-order`: 53 sources) | 90: 85 callers don't pass a register the definition reads (the value the original has there needs per-site reading), 1 varargs declaration, 1 whose unedited source no longer passes equiv.py, 3 other |
| register-convention callee called with no equiv-conv note at all | 5 (new) | 66 | 1 (`0x00219cc0`) | 64, mostly the Lua VM (0x00214000-0x00222000) and `0x00035ab0` |
| `void` definition whose original callers use eax | 6 (new, `--returns`) | 222 definitions (3,336 call sites) | 118 sources (rule `void-return`: the body ends in a call, now returned) | 105 definitions not of that shape |
| x87-argument CRT helpers (`_ftol`, `_CIacos`, `_CIasin`) called by a plain name without their argument | 6 | 5 sources | 5 (0x00011000/0x00011010 now byte-match through MSVC's `acos`/`asin` intrinsics; 0x0033b700, 0x001d06a0, 0x000e8070 name the call whose x87 result they convert) | 0 |
| declared callee-pops bytes differ from the callee's `ret N` (arguments left on the stack for the next call; tail calls passing arguments on) | 7 (new, `--pops`) | 298 symbols, 197 addresses | 13 audio constructors, 48 pass-through wrappers, 1 tail call | 223 symbols / 160 addresses (13 pass-through wrappers are include/gen members: a header change) |
| caller symbol in another convention than its definition | 8 (new) | 1,516 cdecl/stdcall callers of a thiscall definition (and benign pairs: a one-argument fastcall called as a thiscall member, ...) | 20 (rule `this-call`, patch) | 1,497; the byte match decides each rewrite (ecx must really be `this`) |
| a function passed by its XBE address (`atexit((void (*)())0x364490)`) | rule `code-literal` | 12 | 12 | 0 (the 54 data-address literals of the morning's finding 1 are still mapped by the data window) |

Also found in our own tables: XBE 0x00348010 is `ldexp` (its callers push a double and an int), not `_CIexp`
(`host_crt_table.h`).

**4. Link-time repairs** (`tools/native_link.py`; no source or MSVC input changes):

- *Source-defined globals* (`local_data_bindings`): a byte-matching function whose relocation names data its own
  object defines (`EnterPtr`, `gFlag_24400`, `g_obj_265c40`, ...) where the original's word is an XBE data address:
  every reference is pointed at the game's item (a `data.s` label, a library slot, or an offset into an item).
  56 symbols. (Constants the sources define, `gNegOne`, `kRadiansToDegrees`, become the game's items too.)
- *Virtual-dispatch stubs*: a virtual member of a stub class that clang calls directly (devirtualized: a member
  object or a local of class type) and nothing defines gets a stub that loads `this`'s vftable and jumps to the
  member's slot, as the original's call did (slot from clang's emitted stub vftable or, for a class without bases,
  the declaration order in its TU); 1,230 stubs. A slot pointing back at the stub reports itself.
- The per-function rebinding of ambiguous names no longer stubs a symbol an alias covers.

**5. The platform shim's first real stand-ins** (`src/platform/sdl/`, Windows / Wine host functions until the SDL3
backends): threads, semaphores, waits, sleeps and fibers forward to the host's kernel32 functions of the same
public shape (fiber stacks at least 256 KB for clang's frames); the kernel critical-section slots map each game
section to a host `CRITICAL_SECTION` of its own (an address-keyed table, created on first use, so the game's
28-byte Xbox layout is never interpreted); files: `CreateFileA`/`ReadFile`/`WriteFile`/`SetFilePointer`/
`GetFileSize`/`SetEndOfFile`/`CloseHandle` on host files with the Xbox paths mapped (`D:\` -> `isos/extracted`,
`T:\` -> `build/native/tdata` via `HULK_TDATA_DIR`, created on demand for writes; `U:`/`Z:` -> the save dir),
`GetDiskFreeSpaceExA` (a fixed 1 GB free), `XGetDiskSectorSizeA` (2048 for the disc, 512 otherwise),
`GetLastError` (the host's), `XGetLanguage` (English). The start-up trace's phase buffer is static (a smashed stack
no longer garbles the crash line).

**Start-up trace summary** (`build/native/run/summary.txt` of the last run): xbe-window mapped; 466 initializers, 457 game ones run, 9 library ones skipped; first calls during init 216 as in the morning (`QueryPerformanceFrequency`, `GlobalMemoryStatus`, the kernel critical sections, `GetCurrentThreadId`, `ConvertThreadToFiber`, `SetThreadPriority`), then in `main`: `XGetLaunchInfo` (0x0008ed60), `XInitDevices`, `CreateSemaphoreA`, `CreateThread`, `ResumeThread`, `CreateFiber` (the radcore thread and fiber system), `ReleaseSemaphore`, `WaitForSingleObject`, `Sleep`, `GetDiskFreeSpaceExA`, `XGetDiskSectorSizeA` (the drive), `CreateFileA`, `GetFileSize`, `SetFilePointer`, `ReadFile`, `CloseHandle` (0x0008fca0 reads a game file from `D:\`), then the game object's constructor: the Lua VM creates its first table and stops in run 20 above. No graphics call yet.)

**6. MSVC 7.1 verification build: unchanged** (`build/native6/msvc-proof.txt`). Frozen copies of the live `matches/` (22,127 after the three new matches and fx16's commit), `equivalent/`, `build/functions.csv`, `config/`, `include/` and `tools/`; "HEAD" = HEAD's `gen_tree.py`/`build_tree.py` (imported first, `runbase.py`) with HEAD's version of the 263 sources, "this" = this round's tools (including `gen_tree.py`'s `/GS` and `/GS-` in `ALLOWED_FLAGS`, which round 13's compare.py accepts; no source uses them yet) with the rewritten sources; both `build_tree.py --resume --jobs 3 --regression-rounds 4` from the same fallback state, local:

| | HEAD | this |
|---|---|---|
| TUs compiled | 2,723 / 2,723 | 2,723 / 2,723 |
| matches byte-matching | 22,127 / 22,127 | 22,127 / 22,127 |
| equivalent/ compiled, same code as standalone | 5,345 (5,293 same, 51 no_symbol, 1 standalone_compile_error) | 5,345 (same split) |
| equivalent/ differing | 0 | 0 |
| merged / wrapped / isolated | 20,477 / 6,132 / 863 | 20,473 / 6,136 / 863 |
| fallbacks wrapped / isolated / without TU namespace | 431 / 401 / 1 | 432 / 401 / 1 |

Per function the verdicts are identical (27,472 / 27,472). Eight functions changed mode (six merged -> wrapped, two wrapped -> merged: `0x000e0e50`, `0x00249750`, `0x0025ab30`, `0x002e9c60`, `0x00342d90`, `0x00342e50` / `0x0025aaf0`, `0x0025c430`): rewritten declarations (a callee's return type, a parameter order) now conflict, or no longer conflict, with another source's declaration in the same TU; each still matches or compiles to its standalone code.

**Compiling and link**: `msvc` **2,723 / 2,723**; data TUs 1,078 / 1,078. Binding map: 56,881 referenced symbols, 56,647 bound, 234 ambiguous. Strict `lld-link`: **links (0 errors)**, 7.5 MB; undefined after binding 1,690 symbols / 2,892 references (1,691 / 2,893 in the morning: the groups are unchanged, the stubs for virtual members now dispatch).

**Next** (in order):

1. The Lua VM's register-convention calls (checks 5: ~50 call sites in 0x00214000-0x00222000, each needing the
   value the original has in the register: read from the original's code at the call site), then re-run.
2. Checks 6-8's remaining findings by the same verified-rewrite route, starting with what the trace reaches;
   the pass-through wrappers that are include/gen members need their header's prototype to change.
3. Graphics: the D3D device and the pddi layer are next after the game object's construction; real rendering is
   out of scope until the SDL_gpu backend.

## After fix 4 and the binding fixes (2026-10-18)

**What changed:**

- **Fix 4a, MSVC 7.1's dialect by switch** (`tools/clang_probe.py` `DIALECT`, part of the native flags):
  `-Xclang -fno-wchar` (clang-cl `/Zc:wchar_t-`: MSVC 7.1's default; sources `typedef unsigned short wchar_t;`
  and pass `L"..."` as `unsigned short*`), `-fno-operator-names` (a stub's `virtual void or();`),
  `-Wno-c++11-narrowing` (`case 0xce85a963:` on an `int` switch converts as under MSVC),
  `-Wno-address-of-temporary` (`&FUN_002672f0("Clip", 0, 0)`: the temporary lives to the end of the full
  expression, as under MSVC). 7 TUs.
- **Fix 4b, one CRT declaration** (`include/compat/crt.h`, included by `compat/native.h`; `gen_tree.py`
  `crt_guard_text` / `emit_item`): the header declares the 82 C runtime functions the tree calls with MSVC 7.1's
  x86 types and defines `HULK_COMPAT_CRT`. gen_tree puts every source declaration of one of those names (C linkage
  anywhere, or C++ linkage outside the source's own namespaces) inside `#if !defined(HULK_COMPAT_CRT)` ...
  `#endif`. MSVC 7.1 sees the same tokens (only line numbers move; no source uses `__LINE__`), clang sees only
  the canonical declaration: `extern "C" float sin(float)`, `__security_check_cookie(unsigned long)` (also
  declared `__fastcall` and `__cdecl` in one TU), `void _atexit(...)`, `sprintf` and a C++-linkage
  `__security_check_cookie` in a wrapped source (an ambiguous overload under clang) are gone. gen_tree reads the
  names from the header (`crt_names()`), so adding a declaration there guards it tree-wide. 901 guarded
  declarations in the tree.
- **Fix 4c, per-source edits through a verified rewrite** (`tools/native_fix.py --apply --verify`: the rewritten
  text must pass compare.py MATCH / equiv.py --inputs 3000 EQUIVALENT, and the file must not have changed
  meanwhile; log `build/native-fix.log`, list `build/native/fix4-sources.txt`, originals in
  `build/native/fix4-orig/`). 102 sources (46 matches, 56 equivalent), all re-verified:
  - `template-spec` (39 sources): `template <> ` before a member definition of an implicitly instantiated class
    template specialization (`int om::MetaTypeAttrib<float>::vfunc_2(...)`, the clone families
    `fight::*FactoryCasterTemplate<X>::vfunc_0`, `Store<Room>::vfunc_1`);
  - `dependent-base` (50): `typename Method0<T, R>::Fn` in the `Closure0/2` stubs (two-phase lookup; in
    `CActorManager.cpp` the unqualified `Fn` found another TU-level `Fn`). `equivalent/0x001b84f0.cpp`
    (`Closure4`) was refused: the rewrite doesn't compile under MSVC 7.1 there, so it was left alone;
  - `return-struct` (5): `extern "C" struct Pair {...} __cdecl Hash(...);` -> the struct, then the function;
  - `patch` (8, each with its reason in the tool): two for-scope loops (`equivalent/0x000c0e40.cpp`,
    `0x00322cd0.cpp`), a `char*` return of string literals (`matches/0x001ff730.cpp`), an extern variable of an
    unnamed union (`equivalent/0x000d4b60.cpp`), a comparison with an overloaded function name
    (`equivalent/0x0033a880.cpp`), a block-scope `extern` inside an `extern "C"` function
    (`matches/0x00238190.cpp`), an implicit-int member (`matches/0x000f6ef0.cpp`), `extern "C" struct X f()`
    (`matches/0x0035c720.cpp`).
- **Fix 5b-lite, stub vftables by equiv.py's mapping** (`native_link._equiv_job`, cache key `v2`): the
  equivalent/ bindings now keep the vftables an object defines itself (`??_7CAction@fn_00019380@@6B@` ->
  `0x003f3390`, equiv.py's `vftable` binding), so fix 3a finds the game vftable of stubs that only equivalent/
  code constructs. Stub-vftable slots bound: 2,182 -> **4,227**.
- **Thunks** (`native_link.jmp_target`): a verified call whose target is a `jmp rel32` thunk (the source calls
  `thunk_FUN_0008d690` or names the thunk's target) binds to the thunk's final target when that is defined:
  2,014 references.
- **clang's spelling of a definition** (`native_link.link_inventory`): MSVC 7.1 mangles `Matrix*` by the class key
  it saw first (`PAUMatrix`), clang by the definition's (`PAVMatrix`); when the MSVC symbol of a verified
  definition is missing from the clang objects, the one clang definition with that address in its name stands in.
- `tools/native_shim.py`: the shim / CRT inventory below (`build/native/shim-inventory.json`).

**MSVC 7.1 verification build: unchanged.** Frozen copies of `matches/` and `equivalent/` (after the 102
rewrites; 2026-10-18 01:00, before fx14's three new matches arrived) and of `build/functions.csv` (fx14's
corrections already in), HEAD's `gen_tree.py` + `build_tree.py` (imported first, `runbase.py`) vs this
generator, both `build_tree.py --resume --jobs 3 --regression-rounds 4` from the same fallback state, local:

| | HEAD generator | this one |
|---|---|---|
| TUs compiled | 2,557 / 2,557 | 2,557 / 2,557 |
| matches byte-matching | 21,837 / 21,837 | 21,837 / 21,837 |
| equivalent/ compiled, same code as standalone | 5,630 (5,578 same, 51 no_symbol, 1 standalone_compile_error) | 5,630 (same split) |
| equivalent/ differing | 0 | 0 |
| merged / wrapped / isolated | 20,514 / 6,257 / 696 | 20,514 / 6,257 / 696 |
| fallbacks wrapped / isolated / isolated without TU namespace | 497 / 234 / 1 | 497 / 234 / 1 |

Per function the verdicts and modes are identical (27,467 / 27,467). (`build/native/native3/msvc-proof.txt`.)

**Compiling** (`clang_probe.py --snapshot` on the tree of the run above):

| config | 2026-10-17 night | now |
|---|---|---|
| `msvc` | 2,516 / 2,557 (98.4%) | **2,556 / 2,557 (99.96%)** |
| `gnu` | 2,487 (97.3%) | **2,539 (99.3%)** |
| `gnu64` | 2,476 (96.8%) | **2,532 (99.0%)** |

The one `msvc` failure is `src/engine/pure3d/pddiBaseContext.cpp`: `q->pddiRenderState::pddiRenderState();` in
`matches/0x0031ee00.cpp` (an explicit constructor call through the injected class name, which clang rejects even
standalone; placement new is the portable spelling, but it doesn't match yet: left for a source fix). Its 21
definitions are the "TU fails" group below.

**Link** (`native_link.py`; binding map rebuilt: 56,983 referenced symbols, 56,748 bound to one address, 235
ambiguous, 37,440 aliases):

| | 2026-10-17 night | now |
|---|---|---|
| strict `lld-link` (no `/force`) | links, 6.6 MB | **links (0 errors), 7.6 MB** |
| undefined symbols / references before aliases | 46,680 / 52,106 | 57,510 / 63,464 (40 more TUs, names per TU) |
| undefined symbols / references after (stubbed) | 9,613 / 12,972 | **5,429 / 9,049** |

Undefined after, by group (symbols / references):

| group | 2026-10-17 night | now |
|---|---|---|
| stub name: virtual member of a stub class (only in a clang-emitted stub vftable) | 4,012 / 4,566 | **2,994** / 3,620 |
| stub name: bound to an address with no verified definition | 1,803 / 1,856 | **724** / 747 |
| function verified, but its TU fails under clang | 1,703 / 1,708 | **21** / 21 |
| function verified and compiled, referenced under another symbol | 685 / 689 | **24** / 24 |
| platform imports | 340 / 341 | 451 / 454 |
| CRT / C++ runtime | 332 / 2,834 | 425 / 3,198 |
| function not yet verified | 244 / 266 | **21** / 21 |
| library data | 189 / 206 | 288 / 306 |
| data outside the inventory / interior | 127 / 127 | 206 / 206 |
| stub name: ambiguous (two addresses) | 74 / 271 | 114 / 287 |
| stub name: named by no relocation | 64 / 64 | 108 / 108 |
| vftable / RTTI by address | 27 / 31 | 29 / 33 |
| data under a C++ name | 10 / 10 | 13 / 13 |
| library code by address | | 11 / 11 |

(Platform, CRT and data groups grew because 40 more TUs compile and names are per TU: a CRT or platform function
declared in five TUs' namespaces is five symbols bound to one stub. By function they barely moved; see the
inventory below.) Stub vftables: 6,939 virtual members found, 4,227 bound to the game vftable's slot, 1,838 slots
whose game function has no definition in the clang objects, 1,143 slots of stub vftables whose game address is
still unknown, 85 that disagree between two vftables. The 74 -> 114 ambiguous symbols (one invented name, two
callees in one TU) still need a source rename; not done.

## Deleting destructors, the last TU and the platform shim (2026-10-18)

**What changed:**

- **Fix 6b, scalar deleting destructors** (`native_link.deleting_destructors` -> `build/native/link/deleting.s`).
  1,872 of the 2,084 `_hulk_x_` vftable/RTTI targets were verified `??_GX@@UAEPAXI@Z` functions missing from the
  clang objects: MSVC 7.1 emits `??_G` as a COMDAT wherever the source defines a virtual destructor, clang (MS ABI)
  only next to the class's vftable, i.e. in a TU that constructs the class. They are synthesized at link time, one
  per symbol, as `this->X::~X(); if (flags & 1) ::operator delete(this); return this;` (thiscall, `ret 4`),
  calling the clang-compiled `??1X` from the same source. Why this and not binding the slot to the original's
  code: it is the function both compilers generate from the source (clang emits exactly this where it emits the
  vftable), it touches neither the sources nor the MSVC build, and each one is only synthesized after checking
  that MSVC's own definition in the verification build calls exactly `??1X` and the global `??3@YAXPAX@Z` (all
  1,872 do: no class-specific `operator delete`, no inlined destructor) and that clang defines `??1X`. No `??_E`
  is needed (nothing undefined names one). 1,171 symbols synthesized for 1,872 addresses: 701 addresses share their
  symbol with another (239 symbols, each within one TU: stub templates such as `Method2<CActorManager, bool, const
  char*, bool>` that collapse original instantiations), so they bind to one definition, as the tree's own `??1` of
  those classes already does.
- **The last failing TU** (`src/engine/pure3d/pddiBaseContext.cpp`): `matches/0x0031ee00.cpp`'s
  `q->pddiRenderState::pddiRenderState();` is an explicit constructor call, which clang accepts as a Microsoft
  extension, but not through `q` of the dependent type `T*` (it can't resolve the injected class name there).
  `((pddiRenderState*)q)->pddiRenderState::pddiRenderState();` compiles under both and MATCHes (native_fix.py
  `patch`, `--apply --verify`; the source edit of this round). Placement new would be portable but MSVC 7.1 adds a
  null check to it even with a class `operator new` without `throw()` (tried: no match).
- **Fix 7, first part: the platform shim skeleton** (`src/platform/sdl/xdk/`, native builds only). The first
  native image keeps the tree's own Xbox layer (`platform/xbox`: pddi on D3D8, the radcore drive/controller code,
  the radsound HAL, the Bink player) and links this directory in place of the XDK, XAPI and Bink. Directory choice:
  [shipping.md](shipping.md#1-the-source-tree-roadmap-steps-2-and-4) puts the native backends in `src/platform/sdl/`;
  the XDK stand-ins are the first of them (`xdk/`), and drop out once `src/platform/sdl` implements the seams
  directly. Files: `imports.h` (the 167 imports grouped by subsystem, an `X(xbe address, name, subsystem)` table
  and one machine-level prototype each), one stand-in file per subsystem (`graphics_d3d8.cpp` 73,
  `graphics_xgraphics.cpp` 6, `audio_dsound.cpp` 18, `audio_soundtracks.cpp` 3, `movies_bink.cpp` 10,
  `input_xpp.cpp` 7, `file_io.cpp` 10, `saves.cpp` 12, `threads.cpp` 13, `timing.cpp` 3, `memory.cpp` 5,
  `system.cpp` 6, `debug.cpp` 1), `xdk_shim.h` and `trace.cpp` (call counting and a log sink a backend can point
  at `SDL_Log`; freestanding, no CRT). Each stand-in `hulk_xdk_<name>` counts its calls and returns 0 (null
  handle, FALSE, S_OK; out-parameters untouched). `tools/native_shim.py --skeleton` wrote the generated files from
  the pre-shim inventory and won't overwrite them: they are maintained by hand from here. A prototype keeps what the
  callers' machine code depends on, from the symbols the tree calls the function by: calling convention, stack bytes
  the callee pops, return register (`float` in st0); 4 are `__fastcall` (`D3DDevice_SetRenderState_Simple`...).
  `native_link.platform_shim` compiles the directory (clang, `-Werror`) and binds every symbol bound to an import's
  address (or named after it) to its stand-in, with prefixed names so the host's `kernel32` names stay free.
  Platform imports in the link: 451 symbols -> **0**.
- Found on the way: `matches/0x00321c90.cpp` declares `D3DDevice_SetRenderState_FillMode` `__cdecl` while the two
  other callers (and the XDK) use `__stdcall`; the byte match can't see that, but natively the cdecl caller pops
  the argument the callee already popped. Noted in `imports.h`; a source fix (and a check for convention
  mismatches between a caller's symbol and the definition it is aliased to) is open.

**MSVC 7.1 verification build: unchanged.** `tools/gen_tree.py` and `tools/build_tree.py` are HEAD's (this round
changes neither), so the generator comparison is the source edit: frozen copies of the live `matches/` (21,948),
`equivalent/` (5,670), `build/functions.csv`, `config/` and `include/`, both `build_tree.py --resume --jobs 3
--regression-rounds 4` from the same fallback state, local; "HEAD" = HEAD's `gen_tree.py`/`build_tree.py` imported
first (`runbase.py`) with HEAD's `matches/0x0031ee00.cpp`, "this" = the tools as committed with the rewritten one:

| | HEAD | this |
|---|---|---|
| TUs compiled | 2,558 / 2,558 | 2,558 / 2,558 |
| matches byte-matching | 21,840 / 21,840 | 21,840 / 21,840 |
| equivalent/ compiled, same code as standalone | 5,631 (5,579 same, 51 no_symbol, 1 standalone_compile_error) | 5,631 (same split) |
| equivalent/ differing | 0 | 0 |
| merged / wrapped / isolated | 20,515 / 6,259 / 697 | 20,515 / 6,259 / 697 |
| fallbacks wrapped / isolated / isolated without TU namespace | 497 / 235 / 1 | 497 / 235 / 1 |

Per function the verdicts and modes are identical (27,471 / 27,471; `0x0031ee00` matches in both).
(`build/native/native4/msvc-proof.txt`.) The live inputs have grown since the morning (fx14, round 12): one more
TU, 3 more matches.

**Compiling** (`clang_probe.py --snapshot` on the tree of the run above): `msvc` **2,558 / 2,558**, `gnu` 2,541,
`gnu64` 2,534.

**Link** (`native_link.py`, binding map rebuilt: 56,991 referenced symbols, 56,756 bound to one address, 235
ambiguous, 37,450 aliases):

| | morning | now |
|---|---|---|
| strict `lld-link` (no `/force`) | links (0 errors), 7.6 MB | **links (0 errors), 7.6 MB** |
| undefined symbols / references after (stubbed) | 5,429 / 9,049 | **3,253 / 6,878** |
| game-vftable pointers to a `_hulk_x_` stub | 4,211 | **2,146** |
| stub-vftable slots bound to the game slot | 4,227 | **5,897** (of 6,956) |

Undefined after, by group (symbols / references):

| group | morning | now |
|---|---|---|
| stub name: virtual member of a stub class | 2,994 / 3,620 | **1,346** / 1,972 |
| stub name: bound to an address with no verified definition | 724 / 747 | 679 / 702 |
| CRT / C++ runtime | 425 / 3,198 | 426 / 3,207 |
| library data | 288 / 306 | 289 / 307 |
| data outside the inventory / interior | 206 / 206 | 207 / 207 |
| stub name: ambiguous (two addresses) | 114 / 287 | 114 / 287 |
| stub name: named by no relocation | 108 / 108 | 108 / 108 |
| vftable / RTTI by address | 29 / 33 | 29 / 33 |
| function verified and compiled, referenced under another symbol | 24 / 24 | 17 / 17 |
| function not yet verified | 21 / 21 | 15 / 15 |
| data under a C++ name | 13 / 13 | 13 / 13 |
| library code by address | 11 / 11 | 10 / 10 |
| platform imports | 451 / 454 | **0** (the shim) |
| function verified, but its TU fails under clang | 21 / 21 | **0** |

Stub vftables: of 6,956 virtual members, 5,897 bound, 1,143 in stub vftables whose game address is unknown, 164
whose two vftables disagree, 106 whose game slot has no verified definition.

## Start-up milestone: what is left (2026-10-18)

Sizes for an image that gets through `main`'s start-up (the groups above, by distinct address where it matters):

| what | size | how it gets done |
|---|---|---|
| ~~scalar deleting destructors clang doesn't emit~~ | *done the same evening (fix 6b)*: 1,872 synthesized; `_hulk_x_` pointers 4,211 -> 2,146 | |
| stub vftables whose game address is unknown | 1,143 slots (+164 disagreeing, 106 with no verified definition at the game slot) | fix 5b: find the vftable each stub stands for (equiv.py mapping of more constructors, or move stubs onto include/gen) |
| CRT / C++ runtime | 89 functions (425 symbols): `memcpy`/`memset`/`sqrt`/`sprintf`..., `__CxxFrameHandler3`, `type_info`'s vftable, `terminate`, `_purecall`, `__fltused` | the host's MSVC CRT on `i686-pc-windows-msvc` (same names); `__security_check_cookie` and the `/GS` cookie data (`DAT_004d9968`, 147 symbols) map onto the host's |
| platform imports | 167 functions (451 symbols, 454 references), table below | *skeleton done the same evening*: `src/platform/sdl/xdk/` stand-ins (0 symbols left); real backends on SDL3 next |
| library data | 42 addresses (288 symbols): the `/GS` cookie, 2 kernel import slots, D3D state words, CRT globals | shim data + host CRT |
| stub names at unverified addresses | 724 symbols -> **180 addresses: 161 in library code** (CRT/XAPI/D3D, i.e. more shim and CRT), 5 game functions (2,111 B), 3 not a function start; evening: 679 symbols -> 140 addresses, 139 in library code | the library ones join the shim list (`imports.h` lines + stand-ins); the game ones to verify |
| unverified game functions | 21 symbols; with the vftable targets, **72 game functions (2,446 B; median 5 B)** | roadmap step 3 (most are 5-byte stubs and thunks) |
| data outside the inventory / interior | 206 symbols | data.md: interior labels and items the inventory lacks |
| ~~the last failing TU~~, ambiguous names, unnamed references | ~~21~~ + 114 + 108 symbols | source fixes (the TU: done the same evening) |

**Platform-shim inventory** (`tools/native_shim.py` -> `build/native/shim-inventory.json`: one row per library
function by address, the names the tree calls it by, symbols, references; subsystems from
`tools/platform_map.py`, as in [platform-boundary.md](platform-boundary.md#full-call-inventory)). What the
image imports, and what each needs on SDL3:

| subsystem | functions (symbols) | imports | on SDL3 |
|---|---|---|---|
| graphics: D3D8 (Xbox) | 72 (282) | `D3DDevice_*` (Create*/Draw*/Set*/Get* state, shaders, palettes, `BlockUntilVerticalBlank`, `CopyRects`, `Swap`), `D3DResource_*`, `D3DSurface/Texture/VolumeTexture_Lock*`, the `D3D__DirtyFlags` state words (data) | the pddi seam: pddi on SDL_gpu (Metal / Vulkan / D3D12); push-buffer and NV2A register writes in platform/xbox are replaced, not emulated; vertex/pixel shader microcode needs a translator or per-shader rewrites |
| graphics: XGraphics | 6 (11) | `XGSwizzleRect/Box`, `XGIsSwizzledFormat`, `XGAssembleShader`, `XGBuffer_*` | CPU (un)swizzle in the texture loader; shader assembly at build time |
| audio: DirectSound (Xbox) | 18 (19) | `DirectSoundCreate`, `DirectSoundDoWork`, `IDirectSound_*` (buffers, I3DL2 listener, effects image), `IDirectSoundBuffer_*` (play/stop, position, frequency, headroom, mix-bin volumes) | the radsound HAL seam on `SDL_AudioStream`s with our mixer; I3DL2 reverb and the DSP effects image need a software reverb |
| audio: soundtracks | 3 | `XFindFirstSoundtrack`, `XFindNextSoundtrack`, `XOpenSoundtrackSong` | stub (no user soundtracks) |
| movies: Bink | 10 | `BinkOpen`... (unnamed `FUN_00364da0`...) | an FFmpeg/libbink-free decoder or pre-converted movies; the movie seam |
| input: XPP | 7 (12) | `XInitDevices`, `XGetDevices`, `XGetDeviceChanges`, `XInputOpen/Close/GetState/SetState` | `SDL_Gamepad` (state, rumble), hot-plug events |
| file I/O | 10 (33) | `CreateFileA`, `ReadFile`, `WriteFile`, `SetFilePointer`, `GetFileSize`, `SetEndOfFile`, `CloseHandle`, `GetDiskFreeSpaceExA`, `XGetDiskSectorSizeA`, `XapiOpenDirectory` | `SDL_IOStream` over the extracted game data (`D:\` -> data dir, `T:`/`U:` -> pref path) |
| saves/storage | 12 (19) | `XCreateSaveGame`, `XFind*SaveGame`, `XDeleteSaveGame`, `XCalculateSignature*`, `XMountMUA`, `XUnmountMU`, `XFormatUtilityDrive`, `XMUNameFromDriveLetter` | directories under `SDL_GetPrefPath`; signatures as a plain hash; no memory units |
| threads/sync | 13 (16) | `CreateThread`, `ExitThread`, `ResumeThread`, `SetThreadPriority`, `GetCurrentThreadId`, `Sleep`, `WaitForSingleObject`, `CreateSemaphoreA`, `ReleaseSemaphore`, fibers (`ConvertThreadToFiber`, `CreateFiber`, `SwitchToFiber`, `DeleteFiber`) | `SDL_Thread`, `SDL_Semaphore`, `SDL_Delay`; fibers: host fibers on Windows, a ucontext/asm switch elsewhere |
| timing | 3 (10) | `QueryPerformanceCounter/Frequency`, `GetLocalTime` | `SDL_GetPerformanceCounter/Frequency`, `SDL_GetDateTime` |
| memory | 5 (6) | `HeapCreate`, `HeapAlloc`, `HeapFree`, `HeapSize`, `GlobalMemoryStatus` | malloc-backed heaps; a fixed 64 MB report |
| process/system | 6 (24) | `XGetLanguage`, `XGetVideoFlags`, `XGetAudioFlags`, `XGetLaunchInfo`, `XLaunchNewImageA`, `GetLastError` | settings / `SDL_GetPreferredLocales`; relaunch = return to menu |
| debug | 1 (2) | `OutputDebugStringA` | `SDL_Log` |
| unsorted | 1 | `D3DVolumeTexture_LockBox` (a D3D function outside platform_map's list) | graphics |

167 platform functions in all (the full table is the JSON). No kernel function is called directly, only through
these XAPI wrappers; two kernel import slots are read as data. (The 161 library addresses behind stub names
above come on top of this list once they are named.)

**Next** (in order):

1. ~~The scalar deleting destructors~~ (done the same evening, fix 6b).
2. ~~The host CRT, the library data and code behind stub names, an entry point and a start-up trace~~ (done the
   next morning: [Start-up](#start-up-2026-10-18)).
3. The unverified game functions, the 1,143 stub vftables with unknown game address, the 114 ambiguous names
   (source renames), the 207 data symbols outside the inventory, and a convention check between each aliased
   caller symbol and its definition (`D3DDevice_SetRenderState_FillMode` above).

Caveats: the MSVC comparison ran on frozen inputs; the live tree has fx14's three new matches and one replaced
equivalent since. `native_fix.py`'s `patch` list is exact text: a source changed later no longer matches and is
reported, not edited. The CRT guard relies on line numbers not mattering to MSVC 7.1 codegen (no `__LINE__`, no
debug info), which the identical verdicts confirm for this tree.

## Start-up (2026-10-18)

The milestone: an image that starts and writes a start-up trace. Done; it gets through 308 of the 466 C++ dynamic
initializers (the `.text$yc` functions the XBE's CRT start-up runs before `main`). Inputs: a snapshot of the tree
`tools/build_tree.py` built at 08:36 (2,723 TUs, all compile under clang `msvc`), the binding map rebuilt from it.

**1. Host C runtime and library data.** Decision: the C runtime every Windows has, **msvcrt.dll** (plus ntdll's
64-bit arithmetic helpers `_allmul`/`_aulldiv`/... and a few kernel32 functions for the start-up code), through import
libraries that `tools/native_host.py` builds at link time with `llvm-dlltool` from our own `.def` files. Why: the
first target is i686 Windows / Wine, where msvcrt.dll is always present and exports almost everything the tree
calls with MSVC's names and ABI (`_ftol`, `_CIpow`, `_CIacos`, `__CxxFrameHandler3`, `_CxxThrowException`,
`__RTDynamicCast`, `_setjmp3`, `type_info::operator==`, the stdio and math functions); nothing has to be installed
(no MSVC CRT, xwin/msvc-wine sysroot or MinGW is on this Mac, and none is needed); no Microsoft code is linked into
the image. Our own code (`src/platform/sdl/crt/crt_glue.cpp`) covers what msvcrt doesn't export or what must know
about the game: the `/GS` cookie word and `__security_check_cookie` (fastcall, or a thiscall member in one source),
`__fltused`, `atexit` (the initializers' destructors), the sized `operator delete` clang calls (forwarded to the
game's own), the stdio functions that take the XBE's `_iob` entries (a 96-byte proxy for stdin/stdout/stderr), and
`fopen` with the game's paths mapped (`D:\` -> `HULK_DATA_DIR`, the extracted game files; `T:`/`U:`/`Z:` ->
`HULK_SAVE_DIR`). Every host function is imported as `hulk_host_<name>` (`.def`: `hulk_host_strncpy == strncpy`), so
a host export can never satisfy one of the tree's own symbols ahead of its alias (the tree's `_free` is the game's
operator delete thunk at 0x0008d340). `src/platform/sdl/crt/host_crt_table.h` lists the 132 imports, 105 CRT rows
(by XBE address: which standard function each LIBCMT address is, decided from the game's call sites, e.g.
`0x003465c6` is `strtok` (called `(line, " \t\n\r")` then `(0, ...)`), not the `_nh_malloc` platform_map.py
guessed; `0x003441f0`/`0x003442bc` are `_CIacos`/`_CIasin`, the helpers of the game's clamped acos/asin; by name:
`memcpy`, `sqrt`, clang's own `_alldiv`...) and 3 data rows. Library data in `src/platform/sdl/xdk/library.h`: the
three kernel import slots the game calls through (`RtlInitialize/Enter/LeaveCriticalSection`: our functions), D3D's
state block at 0x0039db00 (1,136 bytes: `D3D__RenderState`, `D3D__TextureState`, `D3D__DirtyFlags`...), two DSOUND
words, XPP's two device-type descriptors. A reference into one of these (or into any data-TU item: a global at +0x4c
of `DAT_004e7a2c`) is retargeted in the referencing object: the relocation names the item and the offset goes into
the inline addend (`native_host.retarget_object`; 55 objects).

**2. Library code behind stub names.** `library.h` stands in for the 9 library functions with game call sites
(XAPI save/soundtrack helpers, two Bink internals, D3D `CreateIndexBuffer2`, `SetRenderState_FogColor` /
`StencilFail`, the D3D object maker), shaped from the callers (stdcall, argument bytes, result use); counted and
returning 0 like imports.h's. The other library addresses still behind stub names (about 10, plus `malloc`/`ceil`
added to the CRT rows) have no call site in the original's game code: equiv.py's alignment bound an equivalent/
source's helper call to them, so they are left as stubs that report themselves if reached. When the library-cleanup
agent drops the 47 library-span sources from the tree, their addresses resolve the same way (the host/library rows
take precedence over any tree definition at a library address already).

**3. The entry point** (`src/platform/sdl/xdk/startup.cpp`, `build/native/link/startup.s`). The XBE's entry is
XAPI's; after its own set-up it runs the C initializers, then the C++ initializers between the `.CRT$XCA` and
`.CRT$XCZ` markers (XBE 0x0048ca90..0x0048d4f4: 457 game `.text$yc` functions and 9 library ones), then `main`
(0x0008ee30, matched). `hulk_native_entry` does the same with the tree's definitions, in the XBE's order, skipping
the library initializers (D3D, DSOUND, XGRAPHICS, XPP, LIBCMT: the shim stands in for those libraries). Four game
initializers are isolated sources that *are* MSVC's `$E1` dynamic initializer of a global; for those the table
calls clang's `__GLOBAL__sub_I_<file>` (made global in a copy of the object); clang's own `.CRT$XCU` table (6
entries, the same four plus duplicates) is counted, not run. The trace (`HULK_TRACE_FILE`) gets every initializer,
every stand-in's first call with its caller (`hulk_xdk_first_call_sink`; library stand-ins log as `lib:`/`kernel:`),
and how the run ended: `main` returning, a call to a symbol the image lacks (the stub object now calls
`hulk_native_missing` with the stub's name), or a crash (unhandled-exception filter: code, address, registers,
frame-pointer chain). `tools/native_run.py` symbolizes it with the link map (`/map`) and the binding map's
definitions (XBE addresses).

*The XBE data window.* Verified sources pass XBE data addresses as integer literals: strings
(`FUN_0027b020((const char*)0x3f3fd8)`) and the RTTI descriptors of every dynamic cast (`(void*)0x491ca8`; clang_probe
counts 75 casts and 802 `__RTDynamicCast` sites by address). MSVC emits the same immediate whether the source names
the item or casts its address, so the byte match can't see it. Until those sources name their data, the image maps
a copy of the XBE's data sections (0x003f0000-0x0058a000), read from the player's own `default.xbe` at run time, at
their original addresses: the image is linked at `/base:0x10000000`, and since Wine's (and Windows') start-up puts
heaps in that range, the image starts itself a second time, suspended, reserves the range in the child first, then
lets it run (`HULK_NATIVE_CHILD`; `HULK_NO_WINDOW` skips it). Reads of constants then work; a write there would miss
the tree's own copy.

**4. First start under Wine** (Whisky's Wine 7.7, our own prefix `build/native/wineprefix`; a trivial i686 PE from the
same toolchain runs: `native_run.py --hello`). The image, from first run to now:

| run | stopped at | cause | fixed where |
|---|---|---|---|
| 1 | clang initializer 6 | clang's own `.CRT$XCU` duplicates of the game's initializers | startup: not run |
| 2 | init 18 (0x0035c900) | `(const char*)0x3f3fd8`: an XBE string address in a verified source | the data window |
| 3 | init 38 | an ambiguous stub name (`Obj::Init`, two sources in one TU, two callees) | link: relocations rebound per calling function (`native_host.rebind_object`, 94 symbols) |
| 4 | init 216 (0x0035e6b0, the memory manager) | `equivalent/0x0008d480.cpp`: `int bounds[4]` for GlobalMemoryStatus's 32-byte MEMORYSTATUS (the original reserves 0x20): the stand-in overwrote the saved registers | **source fix** (native_fix `patch`, verified) |
| 5 | init 216 | `matches/0x00267210.cpp` calls `FUN_0008ed50` where its original calls 0x00270540 (a clone's donor name; the byte match masks the relocation) and the name is *defined*, so no alias applied | link: rebound per calling function for names that mean another address (18) |
| 6 | init 216 | `IMemoryAllocator::unknownAllocator`: a stub class's clang vftable | link: every reference to a stub vftable the verification bound to a game vftable now names the game's (vtables.s), 4,156 vftables |
| 7 | init 216 | `matches/0x0008d690.cpp` (the game's `operator new`): `second(first(x))` byte-matches `push size; call first; push eax; call second` but is `second(first(), size)`, and it returned nothing | **source fix** (MATCH either way) |
| 8 | init 216 | `equivalent/0x0026c040.cpp` (dlmalloc's malloc) declares the register-convention callee 0x0026be70 `(size, arena)`, its own source `(arena, size)`: equiv.py maps both to the original's registers, natively both are cdecl | **source fix** (EQUIVALENT); and a new check, below |
| 9 | **init 308 (0x0035fa20)** | `om::MetaType` registers into a red-black tree whose header (root + nil node, XBE 0x004e79b8..) the data inventory split into 4-byte items; the data TU's `DAT_004cd384` landed between `DAT_004e79b8` and `DAT_004e79bc`, so `&root + 4` is not the nil node | open: data layout (next steps) |

**Start-up trace summary** (`build/native5/run/summary.txt`): xbe-window mapped (1,061,700 bytes); 466
initializers, 457 game ones bound, 9 library ones skipped; initializers 0..307 run; first calls, all during init 216
(the radcore memory manager and the thread system): `QueryPerformanceFrequency` (the 733 MHz constant, kept by the
stand-in), `GlobalMemoryStatus`, `kernel:RtlInitializeCriticalSection`, `GetCurrentThreadId`,
`ConvertThreadToFiber`, `kernel:RtlEnterCriticalSection`, `kernel:RtlLeaveCriticalSection`, `SetThreadPriority`;
then the crash in init 308 (`strcmp(NULL, ...)` in `om` type registration). Real stand-ins this round: memory
(XAPI heaps on the host heap, a 64 MB `MEMORYSTATUS` with 56 MB free), timing (the host counter scaled to the
Xbox's 733,333,333 Hz), `GetLocalTime`; everything else still counts and returns 0.

**Verified-source bugs found** (the native build is the first that executes them as written; all invisible to the
byte match and to equiv.py's register-mapped stubs):

1. *XBE data addresses as integer literals* (54 sources, 75 casts; 802 dynamic casts by descriptor address): worked
   around by the data window; the fix is a source rewrite naming the item (a relocation, which compare.py masks).
2. *A caller's buffer smaller than what the callee writes*: `equivalent/0x0008d480.cpp` (fixed).
3. *Arguments left on the stack by MSVC and read by the next call*: `matches/0x0008d690.cpp` (fixed; `0x0008d6d0`,
   operator new[]'s twin, has the same pattern in its equivalent/ source and returns `void`).
4. *Register-convention parameter order*: `tools/native_conv_check.py` check 5 (equiv-conv notes) finds **166 caller
   declarations in 98 files** listing a register-convention callee's parameters in another order (79), with
   another count (82) or in other registers (5) than the callee's own source, all open (counted after fixing `equivalent/0x0026c040.cpp`).
5. *Return values carried in eax by `void` declarations*: `matches/0x0008d690.cpp` returned operator new's pointer
   that way (fixed); `equivalent/0x00011000.cpp`/`0x00011010.cpp` (`float` wrappers that call `_CIacos`/`_CIasin`
   without loading the argument on the x87 stack) and `equivalent/0x0033b700.cpp` are the same class for x87.

Also found in the tools: `clang_probe.nm` dropped the symbols of a batch's single object (llvm-nm prints no header for
one file): fixed; it hid one TU's undefined symbols.

**5. `tools/native_conv_check.py`** (fx15's sweep_conv.py as a tool; native_link runs checks 1-3 and 5 and writes
`conv_check` into report.json, report only): 476 declarations of the 176 stand-ins (imports.h + library.h) in the
sources, 0 disagreeing; 483 symbols bound to them, 0 disagreeing; 176 checked against the XBE's `ret N`, 0
disagreeing; register orders: 323 functions with their own note, 166 disagreeing callers (above). `--tails` (slow:
compiles) is check 4.

**6. MSVC 7.1 verification build: unchanged.** `gen_tree.py`/`build_tree.py` are HEAD's (this round changes
neither); the three source edits are the difference. Frozen copies of the live `matches/`, `equivalent/`,
`build/functions.csv`, `config/`, `include/` and `tools/` in two directories, one with HEAD's three sources, one with
the rewritten ones, both `build_tree.py --resume --jobs 3 --regression-rounds 4` from the same fallback state, local
(`build/native5/msvc-proof.txt`):

| | HEAD sources | edited |
|---|---|---|
| TUs compiled | 2,723 / 2,723 | 2,723 / 2,723 |
| matches byte-matching | 22,118 / 22,118 | 22,118 / 22,118 |
| equivalent/ compiled, same code as standalone | 5,353 (5,301 same, 51 no_symbol, 1 standalone_compile_error) | 5,353 (same split) |
| equivalent/ differing | 0 | 0 |
| merged / wrapped / isolated | 20,476 / 6,132 / 863 | 20,476 / 6,132 / 863 |
| fallbacks wrapped / isolated / without TU namespace | 431 / 401 / 1 | 431 / 401 / 1 |

Per function the verdicts and modes are identical (27,471 / 27,471; `0x0008d690` matches in both, under its new
symbol `?FUN_0008d690@...@YAPAXH@Z`).

**Compiling and link** (`clang_probe.py --snapshot --configs msvc`; `native_link.py --tree <snapshot>`; the snapshot
carries the three edits): `msvc` **2,723 / 2,723**. Binding map: 56,866 referenced symbols, 56,631 bound, 235
ambiguous. Strict `lld-link`: **links (0 errors)**, a 6.7 MB image with an entry point. Undefined after binding:

| group | evening | now |
|---|---|---|
| stub name: virtual member of a stub class | 1,346 / 1,972 | 1,346 / 1,972 (the clang stub vftables that keep them are no longer referenced where the game vftable is known) |
| stub name: bound to an address with no verified definition | 679 / 702 | **7** / 7 |
| CRT / C++ runtime | 426 / 3,207 | **1** / 454 (`operator new` where a TU names both of the game's allocators) |
| library data | 289 / 307 | **39** / 40 |
| data outside the inventory / interior | 207 / 207 | **16** / 16 |
| stub name: ambiguous | 114 / 287 | 104 / 222 |
| stub name: named by no relocation | 108 / 108 | 108 / 108 |
| vftable / RTTI by address | 29 / 33 | 29 / 33 |
| verified, referenced under another symbol | 17 / 17 | 17 / 17 |
| not yet verified | 15 / 15 | 15 / 15 |
| library code by address | 10 / 10 | 9 / 9 |
| **total** | **3,253 / 6,878** | **1,691 / 2,893** |

**Next** (in order):

1. **Data layout**: emit the data items of one original object (or of each contiguous run) as one block that keeps
   the XBE's distances, e.g. a `data.s` like vtables.s generated from config/data.json, the XBE and the data TUs'
   relocations, instead of one C variable per item. Without it every structure the inventory split (run 9) breaks.
2. The register-order findings (166) and the other verified-source classes above: native_fix rewrites, each
   verified (and the MSVC proof again); then equiv.py could check declared parameter order against each callee's own
   note so new sources can't reintroduce it.
3. Re-run the start-up and continue: the rest of the initializers, then `main` (0x0008ee30): the thread system
   (fibers: `ConvertThreadToFiber` is the first real one), files (`CreateFileA` & co on the host C runtime with the
   path map), then graphics, where the stand-ins end.
4. The literal XBE addresses (finding 1) as source rewrites, so the data window can go; the 1,142 stub vftables with
   unknown game address; the 104 ambiguous names.

Caveats: the run used a snapshot of the tree with the three source edits applied to its TU text (what the next tree
build produces); the library-cleanup agent's deletion of the library-span sources was not in that tree yet. The
data window and the start-up child process are Windows/Wine mechanisms of this first image only.

## After the next fixes 1-3 (2026-10-17)

**What changed** (generator, tools, and 169 `matches/` sources renamed by a verified rewrite):

- **Fix 1, duplicate definitions: the TU namespace** (`gen_tree.py`, [source-tree.md](source-tree.md#how-a-tu-is-built)).
  A TU's own declarations, its tree headers' TU-local items and its merged definitions live in `namespace
  fn_f<7 hex>` (one per TU, a hash of its path; `fn_<8 hex>` on purpose, so `equiv.py`'s and `clang_probe.py`'s
  existing look-through for wrapped namespaces applies, and it is never a function address). Global stay: names
  that this TU's `include/gen/` headers declare (in the shared tree headers such items sit inside `#ifdef
  TREE_LOCAL_<name>`, defined by each TU for the include/gen names its own gen headers don't declare, so a stub
  `CSweepTrack` is TU-local where no real `CSweepTrack` exists), `include/decls/` names, global `operator
  new/delete`, the CRT, anonymous namespaces, and wrapped blocks (already unique). `using namespace fn_f...;`
  lets a global definition (a member of an include/gen class) see the stubs, and a stub that a global declaration
  names by `struct X` before X is declared is declared in the namespace first (else it would declare a second,
  global X). Isolated TUs get the same namespace when the source has no include/gen header, `::name` or
  `type_info` (207 sources; state `iso_plain` falls one back if MSVC disagrees: used once). `build_tree.block_names` adds the
  namespace to the mangled-name prefixes and `standalone_symbol` finds the standalone build's symbol without it
  (back-references shift, so the name is compared without digits).
  **Data defined in sources** goes to the data TUs: a merged source's `float gNegOne = -1.0f;` (120 such
  definitions, 65 of them `gNegOne`) and a wrapped source's C-linkage `void* g_anim_vtable;` (9) become `extern`
  declarations; `native_link.py` binds them by address like any other reference. const and static ones stay.
  The repeated placement `operator new` definitions are `HULK_NATIVE_INLINE` (`inline` under clang, empty under
  MSVC 7.1, `tree_prelude.h`).
- **Fix 3, clones defining their donor's name** (`reconcile_stubs.py --rule clone-c --rule clone-stub --apply
  --verify`): `clone-c` renames a C-linkage definition under another name to its own address name (`extern "C"
  int* FUN_0008ceb0()` in `matches/0x0024ea10.cpp` -> `FUN_0024ea10`: 144 sources, `FUN_0008ceb0` 116 times),
  `clone-stub` renames a reused donor stub to the source's placeholder (`CSweepTrack` -> `CSweepTrack_23c870`: 25
  sources). `--verify` writes a rewrite only after compare.py MATCH (equiv.py --inputs 3000 for equivalent/;
  none were needed) and only if the file didn't change meanwhile: 169 sources, all MATCH, list in
  `build/native/fix3-sources.txt`, log in `build/reconcile-stubs.log`. The clang `duplicate-definition`
  compile errors (68 sites, 22 TUs) went with them: 19 more TUs compile.
- **Fix 2 of the list above, the pinned globals** ([data.md](data.md#what-is-left)): a wrapped or isolated
  source's declaration of `DAT_004dd700` / `DAT_0052c2a8` / `DAT_004dd6ec` becomes a typed view of the TU's one
  C declaration, `#define DAT_004dd700 (*(World* *)&::DAT_004dd700)` inside its namespace (`#undef` after; 1,930
  views, `World` being the source's own stub). Why not the alternatives: an exemption in `CLinkage.clashes`
  alone would put `extern "C" fn_A::World* DAT_004dd700` and `extern "C" fn_B::World* DAT_004dd700` in one TU,
  which clang rejects (the 79 TUs of fix 2); one shared opaque class would need every source's member accesses
  rewritten; a per-TU alias (`/alternatename` in a `#pragma comment`) would hard-code mangled names. The view is
  the same lvalue (a load of `[_DAT_004dd700]`), so MSVC's code is the same, and every reference is the data
  TU's `_DAT_004dd700`. The TU's global declaration is the merged one (forced to C linkage) or, if it has none,
  `extern "C" void* DAT_004dd700;`. Pinned by-address references 354 -> **0**.
- **Fix 3a, stub-class vftables** (`native_link.py`): clang emits a stub class's vftable when it compiles the
  stub's constructor, and its slots name stub virtual members nobody defines. The verification build says which
  game vftable the stub stands for (a match stores `??_7Stub@...@6B@` where the original stores the real
  vftable's address: the binding map now records those defined vftable symbols too), so slot N of the stub is
  aliased to the tree's definition of the function in slot N of the real vftable (read from the XBE).
- **Fix 6a, vftables and RTTI by address** (`native_link.py`, `build/native/link/vtables.s`): the 25,513
  `vtable`/`rtti_*` items of `config/data.json` as data: the XBE's bytes, every dword holding an image address as a
  relocation (to the tree's definition of a function, to another of these items, or to a `_hulk_x_<addr>`
  stub), a label `_hulk_d_<addr>` per item and interior address. By-address names (`g_vftable_<addr>`,
  `DAT_<vtable>`, stub vftable names bound by relocation, `??_7X@@6B@` that no TU emits) bind to the labels.
- **Ambiguous symbols** (one invented name, two callees): with the TU namespace most became one symbol per TU
  (329 -> 236 in the map). For the rest, the binding map now keeps the callee per TU, and where each TU has one,
  the link renames the symbol in that TU's object (`llvm-objcopy --redefine-syms`, copies in
  `build/native/link/objs/`) and aliases the new name: 23 symbols in all their objects, 18 in some.
- `build_tree.py`: the regression rounds default to 4 (one fallback can expose the next), and a merged function
  that regresses takes along the blocks wrapped only for having the same definition (they would merge in its
  place next round with the same problem: one round per clone). The TU namespace made the verifier stricter: a
  merged block's name prefix used to match a wrapped block's identical function in the same object
  (`?GetExtent@ThreatBallTrack@` also matches `...@fn_0015ba40@@`), which hid a wrongly merged clone of
  `ThreatBallTrack::GetExtent` (`0x0015b920`; the merged `Track` stub has another layout). Wrapped, its three
  twins would have merged in its place one round after another: hence the twin rule.
- `native_link.py --reuse-map` (the inventory and link from an existing `bindings.json`); the equivalent/ binding
  cache key ignores the COFF time stamp.

**MSVC 7.1 verification build: unchanged.** Same inputs (frozen copies of `matches/` and `equivalent/` after the
169 renames), HEAD generator (`gen_tree.py` + `build_tree.py` of HEAD) vs this one, both `build_tree.py --resume
--regression-rounds 4` from the same fallback state, local (the mac1 runs were abandoned: see the caveat below):

| | HEAD generator | this one |
|---|---|---|
| TUs compiled | 2,557 / 2,557 | 2,557 / 2,557 |
| matches byte-matching | 21,817 / 21,817 | 21,817 / 21,817 |
| equivalent/ compiled, same code as standalone | 5,607 (5,557 same, 49 no_symbol, 1 standalone_compile_error) | 5,607 (same split) |
| equivalent/ differing | 0 | 0 |
| merged / wrapped / isolated | 20,496 / 6,232 / 696 | 20,494 / 6,234 / 696 |
| fallbacks wrapped / isolated / isolated without TU namespace | 489 / 234 / - | 497 / 234 / 1 |

Per function the verdicts are identical (27,424 / 27,424). Two functions are wrapped instead of merged: `0x0015b920`
(a `ThreatBallTrack::GetExtent` clone whose merge was wrong all along, see the verifier note above: HEAD's verifier
counted it as a match on the wrapped twin's bytes; its three twins were wrapped already) and `0x00269550` (an
adjustor thunk `C_269550::f` whose merged code changed in the TU: the regression round falls it back, as with the
`size_t` typedef of fix 1). (The 169 renames alone already let HEAD's generator merge 83
more functions than before them: 20,413 -> 20,496.)

A local run on the live inputs (20 matches promoted meanwhile) agrees: 21,837 / 21,837 match, 5,607 compiled, 0
differing, merged / wrapped / isolated 20,504 / 6,244 / 696.

**Compiling** (`clang_probe.py --snapshot` on the final tree):

| config | after fixes 0-2, 5a | now |
|---|---|---|
| `msvc` | 2,496 / 2,556 (97.7%) | **2,516 / 2,557 (98.4%)** |
| `gnu` | 2,467 | **2,487 (97.3%)** |
| `gnu64` | 2,456 | **2,476 (96.8%)** |

**Link** (`native_link.py` on the final tree; binding map rebuilt: 54,410 referenced symbols, 54,174 bound to one
address, 236 ambiguous, 37,306 aliases):

| | after fixes 0-2, 5a | now |
|---|---|---|
| strict `lld-link` (no `/force`) | 1,211 duplicate-symbol errors (161 symbols) | **links (0 errors), 6.6 MB image** |
| undefined symbols / references before aliases | 40,675 / 51,177 | 46,680 / 52,106 (more names: one per TU now) |
| undefined symbols / references after (stubbed) | 13,803 / 21,977 | **9,613 / 12,972** |

Undefined after, by group (symbols / references):

| group | after fixes 0-2, 5a | now |
|---|---|---|
| stub name: virtual member of a stub class (only in a clang-emitted stub vftable) | 5,960 / 6,662 | **4,012** / 4,566 |
| stub name: bound to an address with no verified definition | 2,227 / 2,393 | **1,803** / 1,856 |
| function verified, but its TU fails under clang | 1,656 / 1,696 | 1,703 / 1,708 |
| function verified and compiled, referenced under another symbol | 501 / 549 | 685 / 689 |
| platform imports | 216 / 220 | 340 / 341 |
| CRT / C++ runtime | 279 / 3,927 | 332 / 2,834 |
| function not yet verified | 176 / 265 | 244 / 266 |
| library data | 146 / 206 | 189 / 206 |
| data outside the inventory / interior | 35 / 35 | 127 / 127 |
| stub name: ambiguous (two addresses) | 215 / 3,123 | **74** / 271 |
| stub name: named by no relocation | 50 / 51 | 64 / 64 |
| vftable / RTTI by address | 2,332 / 2,840 | **27** / 31 |
| data under a C++ name | 10 / 10 | 10 / 10 |

(Some groups grew because names are per TU now: a CRT or platform function declared in five TUs' namespaces
is five symbols, all bound to one stub. The 6,170 vftable slots and RTTI pointers whose function or structure
has no definition point at `_hulk_x_<addr>` stubs, not counted above.) Of the stub vftables' 6,085 virtual
members, 2,182 are bound to the game vftable's slot; 4,222 slot references come from stub vftables whose game
address no verified match reveals (the stub's vftable is stored only in equivalent/ or unverified code, or nowhere),
329 slots of the game vftable have no verified definition, 51 disagree between two vftables.

**Next** (sizes from the table; items 1 and 2 and the cheap part of 4 done 2026-10-18, see [After fix 4 and the
binding fixes](#after-fix-4-and-the-binding-fixes-2026-10-18)):

1. **The 41 TUs still failing under clang** (fix 4: 17 `template <>` clone specializations, `typename` in the
   Closure stubs, `case` narrowing, for-scope, ...) and a canonical CRT header in `include/compat/`: 1,703
   undefined symbols are definitions in them.
2. **Stub vftables whose game address is unknown** (4,222 slot references): take the address from equiv.py's
   level-2 mapping of defined `??_7` symbols too (`_equiv_job` maps only undefined ones), or, better, put the
   stubs on include/gen classes (fix 5b), whose vftables are the game's.
3. **Fix 7, CRT and platform** (332 + 340 + 189 symbols) and **fix 8** (244 unverified functions, 1,803 stub-name
   references to unverified addresses, 6,170 `_hulk_x_` vftable/RTTI targets): then the image can start.
4. The 74 ambiguous symbols left (a TU with two callees under one name: needs a source rename) and the 685
   "referenced under another symbol" (bound to an address whose definition clang doesn't emit under that name).

Caveats: the TU namespace needs `#include` order to stay as gen_tree writes it (the `TREE_TU_BEGIN` /
`TREE_LOCAL_<name>` macros are defined before the tree headers). `equiv._tree_names` and the RTTI look-ups in
equiv.py see the TU namespace as a wrapped one (by design). The mac1 runs of this round were discarded: the
"HEAD generator" run imported the working tree's `gen_tree.py` (compare.py puts `tools/` first on `sys.path`, so
`build_tree.py` from another directory picks up `tools/gen_tree.py`); the local base run imports HEAD's
`gen_tree` before `build_tree` (`runbase.py` in the work directory), as the previous round's `runbuild.py` did.

## After fixes 0-2 and 5a

**What changed** (nothing in `matches/` or `equivalent/`):

- **Fix 0:** the first native target is `i686-pc-windows-msvc`, clang-cl + lld-link ([shipping.md §1](shipping.md#1-the-source-tree-roadmap-steps-2-and-4)).
- **Fix 1:** `include/compat/native.h` (force-included by native builds only: `size_t`, `type_info`); the native
  flags in `tools/clang_probe.py` (`NATIVE`, `X87`): `-include compat/native.h -fno-strict-aliasing -fwrapv
  -fno-delete-null-pointer-checks`, `-mno-sse -mfpmath=387` on 32-bit (clang refuses `-mfpmath=387` while SSE is
  on), `-fcheck-new` off MS. `gen_headers.py`: `enum ScriptHandler::script_state { };` instead of the opaque
  `enum script_state;` (MSVC 7.1 rejects `enum X : int;`; an empty enum is `int`-sized like the opaque one). `gen_tree.py`:
  `build/tree/include/tree_prelude.h` declares the tree's one `size_t` (`__SIZE_TYPE__` under clang, `unsigned int`
  under MSVC) and `HULK_NEW_THROW` (`throw()` under MSVC, empty off MS); sources' `typedef unsigned int size_t;`
  become comments, `operator new/delete(unsigned int ...)` spell `size_t`, `operator new(size_t) throw()` spells
  `HULK_NEW_THROW`. Only TUs that name `size_t` include the prelude: one extra typedef in MSVC 7.1's symbol table
  swapped two commutative operands in a 5 KB function (`0x000ba040`, `add`/`lea` operand order), which the
  regression check caught.
- **Fix 2, done differently from the plan:** no forwarders. A wrapped source's `extern "C"` declaration that would
  clash gets C++ linkage instead (`extern "C++" __declspec(nothrow) ...`; `gen_tree.CLinkage`), so it becomes
  `fn_<addr>::name`. A call or load is the same instruction whatever the callee's linkage; only the relocation's
  symbol changes, and fix 5a binds it by address. `__declspec(nothrow)` keeps /GX's "C functions don't throw"
  (otherwise functions with unwinding get EH state stores around the call). Rules: never for compiler intrinsics,
  CRT names and `_names` (MSVC expands `sqrt`, `sin`, `memcpy`, `_ReadWriteBarrier` inline only for the C
  declaration: the first try made 263 functions regress, all intrinsics); always for invented names (`Lookup`,
  `Find`: one address per symbol); for address names when the TU already has that C name with another type, with
  non-builtin types (a stub class of another namespace), or as a global C++ name. 3,708 declarations change.
  Merged declarations that overload one C name (`FUN_0021add0` declared four ways in one TU, which clang and
  even MSVC's C2733 reject) keep C linkage only on the first (`emit_item`); this also lets 9 functions merge
  that MSVC used to wrap.
- **Fix 5a:** `tools/native_link.py` (below).

**MSVC 7.1 verification build: unchanged.** Same inputs (frozen copies of `matches/` and `equivalent/`), HEAD
generator vs this one, both `build_tree.py --resume` from the same fallback state, on mac1 (`~/hulk-native`, same
MSVC 7.1 + wibo binaries):

| | HEAD generator | fixes 1-2 |
|---|---|---|
| TUs compiled | 2,523 / 2,523 | 2,522 / 2,522 |
| matches byte-matching | 21,817 / 21,817 | 21,817 / 21,817 |
| equivalent/ compiled, same code as standalone | 5,607 (5,557 same, 49 no_symbol, 1 standalone_compile_error) | 5,607 (same split) |
| equivalent/ differing | 0 | 0 |
| merged / wrapped / isolated | 20,327 / 6,435 / 662 | 20,337 / 6,426 / 661 |
| fallbacks wrapped / isolated by the build | 594 / 195 | 584 / 194 |

Per function the verdicts are identical (27,424 / 27,424). The only fallback differences are 9 C2733 wraps and one
regression fallback (`0x001a9b10`) that the new generator no longer needs. A local run on the live inputs agrees
(21,817 / 21,817, 5,607 compiled, 0 differing).

**Compiling** (`clang_probe.py` on the tree of a complete fresh `build_tree.py` run at 16:50, 2,556 TUs; the
morning's tree had 2,498, so the TU sets differ a little):

| config | morning | now |
|---|---|---|
| `msvc` (`i686-pc-windows-msvc`, objects) | 2,378 / 2,498 (95.2%) | **2,496 / 2,556 (97.7%)** |
| `gnu` (`i686-unknown-linux-gnu`) | 1,676 (67.1%) | **2,467 (96.5%)** |
| `gnu64` (`x86_64-unknown-linux-gnu`) | 797 (31.9%) | **2,456 (96.1%)** |

The 60 TUs still failing under `msvc`, by category (TUs; only this category): duplicate-definition 22 (18, fix 3),
msvc-template-spec-syntax 17 (15), other-error 8 (5), extern-c-redeclared 6 (5: CRT names such as `sprintf`,
`sin`, `__security_check_cookie` declared two ways, which keep C linkage on purpose), dependent-base-lookup 4,
address-of-temporary 4, for-scope / case-narrowing / type-in-return-type 2 each, calling convention 1. Removing
the declaration clashes also exposed errors clang had suppressed behind them (an ambiguous call between a merged C
overload and a C++ one in `unk_212bb0.cpp`, stubs used before declaration in `unk_0240b0.cpp`): fix 4 material.

**Binding map** (`tools/native_link.py`, from the verification build's objects): for matches the original bytes at
each relocation's offset (21,817 functions), for equivalent/ the address `equiv.py` level 2 binds (5,607
functions; run on mac1, cached in `build/native/cache/`). 47,385 referenced symbols: 47,056 bound to one
address, **329 ambiguous** (one symbol, two addresses: an invented name or a stub member reused by two sources),
33,501 bound to a verified definition, 33,418 aliases (`build/native/alternatename.rsp`). How: name in the symbol
26,587, position (matches) 19,646, alignment 420, explicit `equiv-map` 56, other 347.

**Undefined symbols of the clang `msvc` objects** (2,496 code TUs + 1,078 data TUs), before and after the aliases
(26,872 aliases whose target the clang objects define; 26,708 from relocations, 164 from an address in the name):

| group | before: symbols / refs | after: symbols / refs |
|---|---|---|
| function verified and compiled, referenced under another symbol | 18,381 / 20,079 | **501** / 549 |
| function under an invented/stub name | 17,032 / 21,470 | **8,452** / 12,229 |
| &nbsp;&nbsp; of which: virtual member of a stub class (only in a clang-emitted stub vftable) | | 5,960 / 6,662 |
| &nbsp;&nbsp; bound to an address with no verified definition (unverified, data, vftable) | | 2,227 / 2,393 |
| &nbsp;&nbsp; ambiguous (two addresses) | | 215 / 3,123 |
| &nbsp;&nbsp; named by no relocation | | 50 / 51 |
| vftable / RTTI by address | 2,339 / 2,847 | 2,332 / 2,840 |
| function verified, but its TU fails under clang | 1,704 / 1,744 | 1,656 / 1,696 |
| data under a C++ name | 349 / 365 | 10 / 10 |
| CRT / C++ runtime | 283 / 3,932 | 279 / 3,927 |
| platform imports | 228 / 232 | 216 / 220 |
| function not yet verified | 177 / 266 | 176 / 265 |
| library data | 146 / 206 | 146 / 206 |
| data outside the inventory, library code by address | 36 / 36 | 35 / 35 |
| **total** | **40,675 / 51,177** | **13,803 / 21,977** |

(The morning's probe counted 30,130 undefined symbols: fewer TUs compiled, and wrapped declarations that are now
`fn_<addr>::` names were shared C names then. The "before" column is today's tree.)

**Link** (`build/native/link/`): `lld-link /machine:x86 /subsystem:console /nodefaultlib /safeseh:no` over the 3,574
objects, the aliases, and `stubs.obj` (an `int3` or 16 zero bytes for each of the 13,803 symbols still undefined):

- strict: **1,211 duplicate symbols**, nothing else. They are definitions with the same name in several TUs:
  `TrackFactoryTemplate::scalar_dtor` 350, `ThreatBallTrack::GetExtent` 81, `pure3d::NonCopyable::f2` 72,
  `gNegOne` 60, `CSweepTrack::vfunc_5` 56, `target` 47, `FUN_00025410` 45, `Action::~Action` 36. Mostly merged
  functions whose definition is a member of an invented stub class (`Action::~Action` is 43 different
  destructors in 43 TUs), constants that sources define rather than declare (`float gNegOne = -1.0f;` in 60 TUs),
  and clone sources that define their donor's name (fix 3). The verification build never links, so MSVC never
  saw these.
- `/force:multiple`: **links, a 5.6 MB PE32 image**. It doesn't run (stubs, no CRT, no platform layer, and with
  duplicates the linker picks one definition for every reference to that name), but it's a complete link inventory.

## What was measured

- **Input:** a copy of the tree from the last complete build (2026-10-16 18:44, `build/tree/`: 2,498 TUs, 26,395
  verified functions, 19,952 merged / 5,805 wrapped / 638 isolated), `include/` as committed (HEAD `7b9f6642`), and the
  1,078 data TUs (`build/data/src/`). It's a copy because `migrate_data.py` and `build_tree.py` were rewriting the
  live tree during the run. Nothing in `build/tree/` or `include/` was changed.
- **Compiler:** Homebrew clang 22.1.8. No system headers are needed: the tree includes nothing from the CRT.
- **Configurations** (all compile every TU; `-ferror-limit=0`; the warnings in `COMMON` in the tool):

| config | flags | answers |
|---|---|---|
| `msvc` | `--target=i686-pc-windows-msvc -fms-extensions -fms-compatibility -fms-compatibility-version=13.10 -std=c++14 -c` | what a clang build that keeps MSVC's ABI (mangling, vftable layout, `__thiscall`) needs. Its objects feed the link probe |
| `gnu` | `--target=i686-unknown-linux-gnu -fms-extensions -std=gnu++17 -fsyntax-only` | the MSVC-only constructs that `-fms-compatibility` was hiding (two-phase lookup, predeclared `size_t`, ...) |
| `gnu64` | the same for `x86_64-unknown-linux-gnu` | what else breaks with 8-byte pointers |
| `*-poc` | the three above on a patched copy (`build/clang-probe/poc/`) | the effect of the cheap fixes (fix 1 below) |

## Headline numbers

| config | TUs compiling | engine | game | platform/xbox |
|---|---|---|---|---|
| `msvc` | **2,378 / 2,498 (95.2%)** | 471 / 495 | 1,889 / 1,965 | 18 / 38 |
| `gnu` | 1,676 (67.1%) | 461 | 1,197 | 18 |
| `gnu64` | 797 (31.9%) | 332 | 450 | 15 |
| `msvc-poc` | 2,382 | 471 | 1,893 | 18 |
| `gnu-poc` | **2,316 (92.7%)** | 462 | 1,836 | 18 |
| `gnu64-poc` | **2,307 (92.4%)** | 458 | 1,832 | 17 |

- With MSVC's dialect and ABI, clang already compiles 95% of the tree. The 120 failing TUs come down to a few
  causes, and **one cause is 66% of them**: wrapped sources that redeclare an `extern "C"` name with a different type.
- One line in `include/gen/global.h` (`enum script_state;` has no underlying type) breaks 692 TUs on every non-MSVC
  target. Together with a 15-line compatibility header and spelling `operator new`'s parameter as `size_t`, the
  Linux targets go from 67% / 32% to 93% / 92%.
- **No inline assembly, SEH or `__declspec(naked)` anywhere in the tree.** x87 code survives only as `volatile`
  rounding pins (2,288 in 531 sources).
- **Linking is the real distance, not compiling.** The 2,378 compiling TUs plus the data TUs leave **30,130
  undefined symbols** (39,855 references). 79% of them (23,721) are calls under a name, class or signature other than
  the one the callee's definition has, or under a stub name that only the relocation resolves. The verification build never sees this, because `compare.py`
  masks relocations and `equiv.py` binds callees by address. Only 299 symbols are CRT or platform imports.

## Categories

Cells are *sites / failing TUs / sources* (a site is a distinct file:line; a header line counts once however many
TUs include it). "Producer" is what wrote the line: a source verbatim in a `fn_<addr>` namespace (wrapped), a
merged definition, the TU's merged declarations, a hoisted tree header, or `include/gen`.

**Errors**

| category | `msvc` | `gnu` | `gnu64` | `gnu-poc` | producer | what it is |
|---|---|---|---|---|---|---|
| `extern-c-redeclared` | 579 / 79 / 420 | 578 / 78 / 419 | 582 / 79 / 422 | 578 / 78 / 419 | wrapped sources (356 matches, 222 equivalent) | the same `extern "C"` function or global declared with another type in another `fn_` namespace (MSVC 7.1 accepts it, clang doesn't). 369 are `FUN_` names (`FUN_00344e74` = `__RTDynamicCast` 53, `FUN_0027b020` 45, `FUN_002672f0` 22), 191 invented names for one address (`Find`, `Lookup`, `Check`, `fetch`), 22 `DAT_` |
| `calling-convention-redeclared` | 4 / 4 / 4 | same | – | same | wrapped | the same, differing only in calling convention |
| `duplicate-definition` | 68 / 22 / 68 | same | same | same | wrapped matches | clones that still define their donor's name: 61 `pure3d::d3d*Shader::vfunc_N` clones each define `extern "C" FUN_0008ceb0` (namespaced targets, which `reconcile_stubs.py` skips) |
| `enum-forward-declaration` | (warning) | 1 / **692** / 0 | 1 / 692 / 0 | fixed | `include/gen/global.h:4181` | `enum script_state;` (an MS extension: no underlying type) |
| `placement-new-undeclared` | – | 70 / 4 / 4 | **4,313 / 1,179 / 1,259** | fixed (9 left on 64-bit) | everywhere | 1,311 sources declare `operator new(unsigned int, ...)`; on 64-bit, `size_t` isn't `unsigned int`. 156 sources also `typedef unsigned int size_t;` (hoisted into `common.h`) |
| `size_t-not-predeclared` | – | 4 / 4 / 4 | 4 / 4 / 4 | fixed | wrapped equivalent | MSVC predeclares `size_t` |
| `exception-spec-mismatch` | (warning) | 64 / 64 / 40 | 7 / 7 / 6 | 64 / 64 / 40 | merged declarations, wrapped | `void* operator new(size_t) throw();` against the implicit declaration |
| `typeid-needs-typeinfo` | 18 / 4 / 4 | same | same | other-error | isolated matches | `typeid` with the source's own `class type_info` (MS ABI's global `type_info`; Itanium wants `std::type_info`) |
| `msvc-template-spec-syntax` | 38 / 16 / 38 | same | same | same | wrapped matches | `int fight::ConditionFactoryCasterTemplate<X>::vfunc_0(void*)` without `template <>` (clone sources) |
| `dependent-base-lookup` | 9 / 4 / 9 | 69 / 24 / 49 | 47 / 22 / 43 | 69 / 24 / 49 | wrapped equivalent | `Closure0` stubs use `Fn` from their dependent base `Method0<T,R>` (two-phase lookup) |
| `case-narrowing` | 38 / 2 / 7 | same | same | same | wrapped equivalent | `switch (int) { case 0xce85a963: }` (C++11 narrowing) |
| `goto-over-initialization` | (warning) | 8 / 5 / 5 | same | same | asm-shaped sources | `goto` past an initialized local |
| `msvc-for-scope` | 2 / 2 / 2 | same | same | same | 2 equivalent sources | a `for` variable used after its loop (`/Zc:forScope-`) |
| `address-of-temporary`, `type-defined-in-return-type`, `register-keyword` | 6 / 3 / 5, 5 / 2 / 4, – | +2 / 2 / 2 `register` | same | same | sources | `&T()`, `struct W {...} *f();`, `register` (gone in C++17) |
| `other-error` | 8 / 7 / 7 | 9 / 8 / 8 | 18 / 11 / 12 | 28 / 13 / 13 | sources | `short wchar_t`, a call with mismatched argument types, an unnamed typedef, a `DAT_` used but never definable (`fn_000d4b60`) |

**Warnings that matter** (they don't stop compilation)

| category | sites / sources (`msvc` unless noted) | why it matters |
|---|---|---|
| `64bit-pointer-int-cast` (`gnu64`) | **4,779 / 2,981** (in 1,103 TUs) | pointers through `int` and back: the bulk of the 64-bit gap (an error without `-fms-extensions`) |
| `ub-null-this-or-reference-check` | 19 / 16 | `if (this)`, `&p->field != 0`: clang folds them to true. `-fno-delete-null-pointer-checks` |
| `ub-array-bounds` | 5 / 5 | `pad[77]` in `char pad[77]`: a field read through the stub's pad |
| `ub-missing-return`, `ub-uninitialized`, `ub-unsequenced`, `ub-vptr-memaccess`, `ub-pure-virtual-in-ctor`, `calling-convention-cast` | 2, 1, 2, 3, 1, 1 | each a real behaviour difference under clang's optimizer; per-source review |
| MS extensions tolerated by `-fms-extensions` | explicit constructor calls 126 / 86, exception specs 121 / 39, dependent-base lookup 41 / 40 (`msvc` only), `goto` 8 / 5 | build with `-fms-extensions` (all clang targets accept it), or fix per source |

**Source scans** (constructs no diagnostic reports; `report.json` → `scans`)

| scan | occurrences / TUs / sources | for |
|---|---|---|
| hand-written vptr stores (`*(void**)this = &g_vftable_x`, `vptr = ...`) | 2,115 / 891 / 1,845 | link (vftable by address), any non-MSVC ABI |
| vftables named as symbols (`g_vftable_*`) | 2,005 / 585 / 985 | same |
| virtual calls through a hand-written vftable (`vptr[5]`) | 753 / 292 / 390 | same: slot numbers are the MS ABI's |
| virtual members of TU-local stub classes | 82,632 / 1,983 / 3,893 | Itanium puts two slots per virtual destructor, so stubs that call by slot only work under the MS ABI |
| `__RTDynamicCast` called by address with RTTI descriptor addresses | 792 / 163 / 379 | needs the descriptors by symbol (or `dynamic_cast`) |
| integers in the XBE's ranges cast to pointers / function pointers from integers | 75 / 27 / 54, 19 / 4 / 13 | absolute addresses (NV2A methods written as pointers, `(void*)0x26dc20` fiber starts, D3D state words) |
| `*(T*)&x` type punning | 2,854 / 350 / 835 | strict aliasing: `-fno-strict-aliasing` (2,443 of them cast a `DAT_` global: the `data-cast` rewrites of [data.md](data.md#the-rewrite)) |
| explicit `char pad[N]` layouts | 24,747 / 1,355 / 3,572 | 64-bit; include/gen adds 889 `_pad_` gaps and 589 pointer-typed `f_XX` fields at 32-bit offsets |
| `__int64` / explicit calling conventions / `__declspec` | 2,715 / 1,000, 2,689 / 1,640, 521 / 297 sources | fine on 32-bit (clang accepts all three with `-fms-extensions`); conventions are ignored on 64-bit |
| `/GS` cookie calls written out | 714 / 317 sources | drop at the shim (`__security_check_cookie` → no-op) |
| inline asm, SEH | 0, 0 | |

## Link probe

`llvm-nm` over the 2,378 compiling `msvc` objects plus the 1,078 data TU objects (all of which compile under clang):
every referenced symbol that no object defines, grouped. ("in `fn_`" = the reference comes from inside a wrapped
source's namespace, so even a correct C++ declaration gets the namespace in its mangled name.)

| group | symbols | references | in `fn_` | addresses |
|---|---|---|---|---|
| function under an invented/stub name, no address in the symbol (`Base_135f40::Fin`, `Obj_150480::f1`, `helper`) | **13,221** | 17,427 | 4,114 | (known only from the relocation) |
| function verified and compiled, but referenced under another symbol | **10,500** | 11,873 | 5,242 | 4,253 |
| function verified, but its TU fails under clang | 2,689 | 2,779 | 1,215 | 1,513 |
| vftable / RTTI by address (`g_vftable_*`, `DAT_` of a `??_7`/`??_R0` item) | 1,954 | 2,426 | 502 | 576 |
| function not yet verified (incl. vfuncs of include/gen classes nobody defined) | 1,068 | 1,266 | 601 | 280 |
| data: emitted item referenced under a C++ name | 288 | 315 | 237 | 84 |
| CRT / C++ runtime (`type_info` vftable 1,060 refs, `operator new`/`delete`, `terminate`, `__RTDynamicCast`) | 168 | 3,477 | 63 | 9 |
| platform imports (D3D, DSound, XAPI, kernel, XPP, Bink; by name or by library address) | 131 | 134 | 62 | 15 |
| data: library (CRT/XDK) data | 81 | 128 | 41 | 39 |
| data: not an emitted item (interior / outside the inventory) | 27 | 27 | 24 | 21 |
| library code by address, unnamed | 3 | 3 | 0 | 3 |

Of the 10,500 "referenced under another symbol": 5,242 are declared inside a `fn_` namespace, 3,898 as a member of
the caller's own stub class (`Object::FUN_000b4c10`), 1,199 as free functions whose signature or linkage differs
from the definition's (`?FUN_00011070@@YAHM@Z` against a definition returning `void`), and 161 with C linkage against a C++
definition. The platform shim surface agrees with [platform-boundary.md](platform-boundary.md): 131 import symbols
plus 81 library data symbols (D3D state words, CRT globals), to be implemented in `platform/sdl`.

## Prioritized fix list

The order is set by what unblocks a linkable 32-bit image soonest. Sizes are estimates.

**0. Choose the first native target: `i686-pc-windows-msvc` (clang-cl + lld-link).** *Done 2026-10-17.* The verified code is
MS-ABI code: 82k virtual declarations in stub classes, 753 hand-written vftable calls and 2,115 vptr stores rely on
MSVC's vftable layout (one slot per virtual destructor, no offset-to-top), on `__thiscall`, and on MS mangling (which
fixes 5 and 6 below use to alias by name). Compiling for Itanium (Linux, macOS) works after fix 1, but it silently
changes the slot numbers of every stub with a virtual destructor. So the first link should be Windows x86, run
natively or under Wine. Linux and macOS come after fix 5b, once calls go through the real include/gen classes. This
narrows the "Linux or Windows" choice in roadmap step 6.1 rather than reversing it.

**1. Compatibility header + three generator one-liners** (half a day; proven in `build/clang-probe/poc/`). *Done
2026-10-17; see [After fixes 0-2 and 5a](#after-fixes-0-2-and-5a).*
- `include/compat/native.h` (force-included by the native build only): `typedef __SIZE_TYPE__ size_t;` off MSVC,
  `type_info` / `std::type_info`, later the CRT bits the shim provides.
- `gen_headers.py`: emit `enum script_state : int;` (or an empty definition) for enums named only in declarations
  (692 TUs on every non-MSVC target).
- `gen_tree.py`: global `operator new`/`delete` declarations and `typedef unsigned int size_t;` stop coming from
  sources. Emit one canonical set (`size_t`, the `throw()` form each TU's codegen needs) from a gen_tree prelude, so
  `common.h` loses its 32-bit `size_t`. MSVC output doesn't change (`size_t` is `unsigned int` there), so
  `build_tree.py` should show 0 changes. This also covers the 64 `exception-spec-mismatch` TUs on gnu (not in the
  PoC).
- Flags for every native build: `-fms-extensions -fno-strict-aliasing -fwrapv -fno-delete-null-pointer-checks`, and
  on 32-bit `-mfpmath=387` for the first replays: x87 is what the `volatile` pins and the replay checkpoints assume.

Measured: gnu 1,676 → 2,316 TUs, gnu64 797 → 2,307, msvc 2,378 → 2,382.

**2. `extern "C"` redeclarations in wrapped namespaces** (*done 2026-10-17 by C++ linkage instead of forwarders*) (gen_tree, about 150 lines plus a tree build; 79 TUs, 60 of
them fail on nothing else). For a wrapped source whose declaration of a C-linkage function or global differs from the
TU's canonical one, gen_tree emits a namespace-local forwarder instead of the declaration:
`static inline R name(A a) { return ((R (__cdecl*)(A))&::name)(a); }`, or for data `static T& DAT_x = *(T*)&::DAT_x;`.
MSVC should turn a call through a cast function address into the same direct `call`; the regression rounds of
`build_tree.py` would catch any change. Do it under a `--native` switch first if a tree-wide MSVC re-verification can't be
afforded. Invented names for one address (`Find`/`Lookup`/`Check` = `__RTDynamicCast`, 191 sites) collapse into
`FUN_<addr>` once fix 5a gives every relocation its address.

**3. Clones defining their donor's name** (68 sources, 22 TUs). Extend `reconcile_stubs.py`'s `clone-free` rule to
namespaced vfunc targets (`pure3d::d3dLightMapShader::vfunc_16` defining `FUN_0008ceb0`), or route them through
`migrate_gen.py` gen-swap. Check with `compare.py`.

**4. Per-source edits** (about 130 sources, a day for one agent plus re-verification): `template <>` on 38 clone
specializations (mechanical; extend migrate_gen's `clone-template`), `typename Method0<T,R>::Fn` in the Closure stubs
(49 sources on gnu, mechanical), `case (int)0x...` (7), for-scope (2), `goto` past initialization (5), `register` (2),
`&T()` (5), types defined in return types (4), `type_info` (4), the ~13 others. Each changed source is re-checked with
`compare.py` or `equiv.py`. Most of them are wrapped or isolated today, so the edits also help the MSVC tree merge.

**5. Callee binding: the link gap** (23,721 of 30,130 undefined symbols).
- **5a. A binding map from the verification build** (a new tool, about 500 lines, 2-3 days). *Done 2026-10-17:
  `tools/native_link.py`.* `build_tree.py`
  already compiles every TU with MSVC and checks it against the XBE. Record each relocation's symbol and the XBE
  address it must resolve to (`verify_relocs.py` does this for matches; for equivalent/ use the address `equiv.py`
  binds), map each address to the symbol of its definition in the tree (`build_tree.mangle_prefixes`), and emit a
  linker alias file (`/alternatename:<referenced>=<defined>` for lld-link). Every stub name, wrapped-namespace name
  and signature variant is the same machine-level call that the byte match or behaviour check proved, so on 32-bit
  MS ABI the alias is exact. This turns 10,500 + 13,221 + 1,954 (vftables, below) symbols into resolved references
  without touching a source. It's the fastest way to a linked image, but it only holds for the MS ABI and 4-byte
  pointers.
- **5b. Canonical prototypes** (the long-term fix, and the same work as header reconciliation). Declare every
  verified function once, from its definition, in `include/decls/` (generalising `decls/address.h`), and rewrite
  callers onto it with a `migrate_*` family like `pin-decl`. Needed for Itanium and 64-bit, where an `int`
  parameter declared for a pointer really differs. The link probe's "referenced under another symbol" and "stub name"
  counts are the progress measure.

**6. vftables and RTTI by address** (1,954 symbols, 576 addresses; 1,845 sources store vptrs by hand).
- 6a (MS ABI, about 1 day): `config/data.json` names every vftable and RTTI item by its MSVC symbol (`??_7X@@6B@`,
  `??_R0...`), and clang emits identical structures from include/gen (the `gen_headers.py --probe` TU constructs every
  class). So alias `g_vftable_<addr>` / `DAT_<vftable addr>` to the clang symbol. The 792 `__RTDynamicCast` calls by
  descriptor address then resolve against the host CRT's own `__RTDynamicCast` with clang's descriptors.
- 6b: constructors and non-trivial destructors in include/gen, so sources stop storing vptrs (next steps 1-2 of
  [source-tree.md](source-tree.md#next-steps-ranked)). Required for Itanium.

**7. Platform shim and CRT** (roadmap step 6.1 proper): 131 platform symbols and 81 library-data symbols behind the
four seams, plus the CRT. On `i686-pc-windows-msvc` the CRT is the host's (`operator new`, `type_info`, `terminate`
and `__RTDynamicCast` exist with the same names). The 75 absolute-address casts (NV2A methods written as pointers,
D3D state words at `0x39de20`, fiber starts by address) are all in platform/xbox and seam code, which the SDL layer
replaces anyway.

**8. Unverified functions** (1,068 symbols: 280 by address, the rest include/gen vfuncs nobody defined). The holes of
roadmap step 3; the link probe lists exactly the ones a linked image needs (`undefined.txt`, group "not yet verified").

**9. 64-bit (sized, not first; measured again 2026-10-20 in [64-bit](#64-bit-the-probe-the-gap-by-class-and-what-replaces-each-bridge-x64-1-2026-10-20)):** 4,779 pointer↔int casts in 2,981 sources, 24,747 explicit pads in 3,572 sources,
889 pads and 589 pointer fields in include/gen, mixed `DataLayout_` data structs ([data.md](data.md#what-the-native-clang-build-needs-from-data)),
loaders of 32-bit file formats. After fix 1, 64-bit *compiles* as well as 32-bit (2,307 TUs). The gap is silent layout,
which only real types close (5b, 6b, typed globals).

### Next fixes (after 2026-10-17), toward a link without `/force` and stubs

*Items 1-3 done the same night; see [After the next fixes 1-3](#after-the-next-fixes-1-3-2026-10-17) for what was
done and what is next.*

1. **Duplicate definitions (1,211 symbols, strict link's only error).** Merged functions defined as members of
   invented stub classes collide across TUs. Cheapest: gen_tree emits each TU's invented stub classes inside a
   per-TU namespace (`namespace tu_<object> { ... }`; the names are placeholders, `rename_placeholders.py`), so
   `Action::~Action` becomes 43 distinct symbols; the verification build is unaffected for the same reason as fix
   2 (only relocation names change; mangled-name lookup in `build_tree.mangle_prefixes` needs the namespace).
   Data defined in sources (`float gNegOne = -1.0f;`) goes to `static` or to the data TUs. Then fix 3 (clones).
2. **Stub-class vftables (5,960 symbols).** clang emits a vftable for every stub class whose constructor or
   destructor it compiles, and its slots name stub virtual members nobody defines. Either alias them through
   include/gen (slot N of the class whose vftable address the stub stores) or stop clang emitting them
   (`__declspec(novtable)` on stubs that never construct a real object). Overlaps fix 6.
3. **Fix 6a (vftables / RTTI by address, 2,332 symbols)**, and the **329 ambiguous symbols** (one invented name, two
   callees): per-object renaming (`llvm-objcopy --redefine-sym` on the objects of one of the users) or a
   gen_tree rule that makes such a C++ declaration namespace-local too.
4. **Fixes 3 and 4** (the 60 TUs still failing; 1,656 undefined symbols are definitions in them), and a canonical
   CRT header in `include/compat/` so `sprintf`/`sin`/`__security_check_cookie` are declared once.
5. **Fix 7 (CRT and platform: 279 + 216 + 146 symbols)** and fix 8 (176 unverified functions plus the 2,227
   stub-name references whose address has no verified definition). Then the image can start.

Caveats of fix 5a: equivalent/ bindings are `equiv.py`'s level-2 mapping (50 of 5,607 functions have level-2
issues; their mappings are still used). An `equiv-map:` line naming a C symbol that gen_tree now spells
`fn_<addr>::name` isn't renamed by `equiv._tree_names` (only C++ names are), which matters only for
`build_tree.py --equiv` runs on the tree.

## How this feeds header reconciliation and typed globals

The native gaps and the MSVC tree's merge failures are the same disagreements seen from two sides:

- **Wrapped blocks** (5,805 functions; `gen_tree --stats`: 4,035 refused class merges, 365 blocks wrapped by the
  merged-layout check, 466 include/gen sources isolated) are where a source's declarations disagree with its TU's.
  For clang, every such disagreement on a *callee* is also a link mismatch: 12,101 of the 30,130 undefined symbols come from inside
  `fn_` namespaces. Fixes 2 and 5b remove wrap reasons and link mismatches together. A source whose declarations
  become the canonical ones merges in the MSVC tree and links natively.
- **Refused class merges** are stub classes of one object that disagree. On the native side the same stubs are the
  13,221 stub-member symbols (members declared by callers and defined nowhere under that name) and the 82k
  slot-order-dependent virtual declarations. Moving them onto include/gen classes (migrate_gen gen-swap for
  non-owner stubs, next step 4 of source-tree.md) is what makes the code ABI-portable.
- **Typed globals and tables:** 288 data symbols are referenced under C++ names (237 from `fn_` namespaces: the
  pinned `DAT_004dd700` & co. while `decls/address.h` declares them with C++ linkage; the `extern "C"` change in the
  working tree fixes those). The 2,854 `*(T*)&x` casts are mostly `data-cast` rewrites. Typed declarations in
  `include/decls/data/` (stub classes per BSS object) remove them and the strict-aliasing exposure; until then
  `-fno-strict-aliasing`.
- **Suggested gate:** run `tools/clang_probe.py` after each `build_tree.py` run (`--snapshot`). The numbers to watch:
  `msvc` TUs compiling (target 100%), undefined "referenced under another symbol" + "stub name" (target 0 after 5b),
  and `gnu-poc` TUs compiling (Itanium readiness).

## Caveats

- `-O0` objects. Optimization changes nothing in the undefined-symbol set except inline functions that are never
  emitted, so the probe slightly *over*-counts references from inline helpers.
- The 120 failing `msvc` TUs contribute no references, and their definitions count as missing ("its TU fails").
- Groups come from symbol names: `FUN_`/`DAT_` addresses, `build/functions.csv` names, `build/port/platform_calls.json`
  and a CRT list. A stub name that happens to equal a functions.csv name is classified by that name.
- The snapshot predates the working-tree `extern "C"` change to `include/decls/address.h` (deliberately reverted to
  HEAD in the snapshot, so that it matches the tree it was built with).
