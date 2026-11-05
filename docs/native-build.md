# Moved

This document is now [docs/wine-build.md](wine-build.md). The 32-bit clang image run under Wine is called the "Wine build" ("native" is reserved for the future 64-bit builds); this stub keeps old links working.

## x86-64 Linux (SteamOS): the native build on ELF (elf1, 2026-11-03)

The 64-bit native builds are documented in [native-mac.md](native-mac.md) (arm64 macOS) and
[native-android.md](native-android.md) section 13 (the ELF targets). x86-64 Linux shares `tools/native_elf.py` with
arm64 Android:

1. The front end for `x86_64-pc-windows-msvc` (MS C++ ABI, LLP64).
2. `native_mac.retarget()`.
3. The ELF steps: `m:e` datalayout, COMDATs kept as `any`, `win64cc` on game variadics, and `@` -> `#` in MS names.
4. The backend for `x86_64-unknown-linux-gnu` with `-fPIC`.
5. lld into a PIE.

The toolchain is the tree's LLVM (22.1.8) with lld. The sysroot is Debian 11's glibc 2.31 and GCC 10's libstdc++,
the base of Steam Runtime 3 "sniper". `tools/linux_sysroot.py` builds it from pinned, SHA-256-checked packages
(about 70 MB, under build/).

```sh
PY=build/venv/bin/python; export HULK_CLANG_PROBE_DIR=<dir with snap/>
$PY tools/linux_sysroot.py                                   # build/elf1/sysroot-x64 (HULK_LINUX_SYSROOT elsewhere)
$PY tools/native_elf.py compile --target linux-x64 --jobs 4  # build/native-linux-x64/ (HULK_NATIVE_ELF_DIR)
$PY tools/native_elf.py link --target linux-x64 --ld         # link/hulk-linux, link-report.json, unbound.txt
sh tests/linux/host_link.sh                                  # the host-layer tests, linked for glibc
```

**Status (snapshot of clean1's proof build 42504):**
- Tree TUs: 2,655 / 2,658 compile. The 3 failures are the same as on macOS.
- Data TUs: 1,078 / 1,078.
- Unbound: 46,369. That is macOS's 46,370 without Darwin's `bzero`; `floor` moves to the host-libm rows.
- lld links with every unbound name stubbed (rc 0). The image is a 41 MB PIE for `/lib64/ld-linux-x86-64.so.2`.
- **Link only:** there is no Linux machine yet, so neither the image nor the host tests have run on Linux.

On the first run, check:
- the start-up trace's `low-4gb reserved` line (about 4,095 MB; the reservation is on by default on Linux);
- the game-`va_list` glue on glibc (it ran as x86-64 macOS under Rosetta: the same System V convention);
- `tests/native_host/*`.

## Varargs on the 64-bit builds (va1, 2026-11-03)

**The problem** (A0, [native-android.md](native-android.md) section 12). 18 game functions built their `va_list` the
32-bit x86 way, from the address of their last named parameter (`(char*)&fmt + 4`, `&fmt + 1`, `&c`), 10 of them
with the variadic part declared as fixed parameters, and three consumers walked lists in 4-byte slots. On a 64-bit
target the parameter is a spilled register copy, so the list was garbage (`"%d-%d", 11, 22` printed `22558-22558`).
Callers also had to agree with the definition: 142 caller sources declared these functions with fixed parameters,
which on arm64 macOS (variadic arguments on the stack) and with `win64cc` on ELF (a different register order from the
host's System V convention) passes the arguments where the callee does not look.

**The conditional.** `include/compat/ptr.h`'s pointer-size test (the one that makes `hulk_intptr` 64-bit) now also
defines `HULK_PTR64`. A source that must say something else on a 64-bit build includes `compat/ptr.h` and tests
`#if defined(HULK_PTR64)` *inside the function body*. A top-level `#if` would make gen_tree wrap the source ("macros"),
so the signatures carry no conditional: they are what they are on both builds.

**Definitions: variadic on both builds.** MSVC 7.1's `__cdecl` code is the same for `f(a, b, ...)` and `f(a, b, c)`,
so every producer is now spelled with `...` on both builds; the body keeps the 32-bit spelling under `#else` and uses
`__builtin_va_start` on 64-bit (the MS front ends' `va_list` is a `char*` over 8-byte slots on every 64-bit target).
All 15 matches/ definitions still MATCH with verify_relocs ok; the 7 equivalents stay promotable.

| pattern | functions | 64-bit spelling |
|---|---|---|
| `...` with `(char*)&fmt + 4` / `&fmt + 1` | 0x000964a0, 0x000dfcc0, 0x0023fde0 `Fn`, 0x00245b00 `Err`, 0x00246f50, 0x00238bb0, 0x0021f800, 0x00232cc0 | `va_start(ap, fmt)`, pass `ap` |
| fake fixed parameters, list after the last one (`&c + 1`) | 0x00267760, 0x00213470, 0x000fc000, 0x000fc020 | `, ...` appended; `va_start(ap, c)` |
| fake fixed parameters, list *at* the last one (`&c`) | 0x00216320, 0x00214a90, 0x0023fef0 `Target`, 0x00338e20 `target` | `c` dropped for `...`; 32-bit `(char*)&b + 4` (same bytes); `va_start(ap, b)` |
| a pointer read through a 4-byte parameter slot (not varargs) | 0x0025fba0, 0x0025fad0 | the parameter is `hulk_uintptr` / `hulk_intptr`, so `&p` holds the whole pointer |
| consumers walking 4-byte slots | 0x002160c0 (Lua's pushvfstring), 0x000fbc00, 0x000fbe00 (wide formatters) | `__builtin_va_arg(ap, T)` per conversion |
| `va_list` passed as `int` | 0x00213440 (lua_pushvfstring wrapper) | `hulk_intptr` parameters |

Named parameters that carry a pointer (formats, the Lua state, buffers) became `hulk_uintptr` / `hulk_intptr` where the
32-bit type was an integer (the consolidation's "pointer beats integer" rule: the same type on 32-bit).

**Callers: one shape per address.** Every caller's declaration (by relocation: `verify_relocs.py --json`'s map for
matches/, the binding map for equivalent/) keeps the definition's named parameters and ends in `...` on both builds:
138 sources (57 matches/, 81 equivalent/), names kept (`F2`, `Match`, `Check`, `fmt`, `c`, ...). The callers keep
their own parameter types; what must agree across a call on the 64-bit targets is the variadic shape (the number of
named parameters, then `...`), which this makes one per address. `build/va1/scripts/rewrite.py` did the rewrite;
`census.py` lists the candidates from a Wine build's binding map.

**Tests.** `tests/native_host/va_tree_test.sh` compiles the real sources of the producers and consumers one TU each
through the tree's front end and the target's retarget, with `tests/native_host/va_tree_game.cpp` as their callers and
callees (a small vsnprintf over the game's list, a Lua stack, the wide formatters, recording stubs): 17 cases, ints,
doubles, chars, narrow and wide strings, up to 12 arguments (past the registers).

| mode | target | result |
|---|---|---|
| `mac` | arm64 macOS, `native_mac.py retarget` (Darwin variadics) | 17/17 |
| `x64` | x86-64 macOS under Rosetta, System V host + `native_elf.add_win64cc` (SteamOS's convention) | 17/17 |
| `android` | arm64 Android 15 emulator, `native_elf.py retarget --target android-arm64`, NDK r30 | 17/17 |

With HEAD's 0x000964a0 linked in instead, the `mac` binary dies with SIGBUS.

**Gates.** Batch gates: 72 matches/ sources MATCH + verify_relocs ok; 88 equivalent/ sources promotable at 3,000 inputs and
at 600 with `--wine`; `--x64` (equiv64 batch) on the 88 against their HEAD versions: 63 -> 64 equivalent (0x0025fad0
newly passes), no new failure. gen_tree (`--fresh`, `PYTHONHASHSEED=0`) against HEAD: 6 mode changes, all
canonical-variant ties in three TUs (0x00089f80 / 0x0008b560 swap, 0x0033c2b0 and 0x0033cb70 to wrapped, 0x0033c7e0
to merged, 0x0025c6d0 to wrapped).

| | control 42913 (HEAD 362e4aa7a, mac2) | batch 42914 (mac2) |
|---|---|---|
| strict link rc / Wine unbound | 0 / 1,324 | 0 / 1,324 (the same set) |
| build_tree fallbacks | 20 compile-error wraps, 213 isolated | 0 compile-error wraps (the overload ambiguities between fixed and variadic declarations are gone), 214 isolated (0x000b86b0: code differs from its standalone build, isolated plain) |
| image (PE time stamp zeroed) | - | differs (the merges above) |
| x87 keep list | - | identical |
| play3 checkpoints | 2,004 to 60,090 | identical at all 2,004 common frames (batch to 60,150) |
| native arm64 macOS unbound (front-end failures) | 46,370 (3) | 46,350 (3) |
| native x86-64 Linux / arm64 Android unbound | 46,369 / 46,369 (3) | 46,349 / 46,349 (3) |

All native links rc 0 (ld64, lld). The batch has one more tree TU (0x000b86b0's isolation): 2,656 / 2,659.

**Left.**
- Four callers keep a fixed-parameter declaration: 0x00062180 (`owners.h` types its parameter `float`, so `...` would
  push a double: its owner class needs the real type, `const char*`), and 0x000c9bd0, 0x001fa3a0, 0x00233c50, whose
  equivalence checks are not promotable at HEAD either (30 `--wine` inputs; a `--wine` fault; unsupported, every
  input a frame overrun).
- Pointer-size problems next to the varargs: callers that pass a pointer through an `int` parameter of their own
  declaration (`Format(int, int, const char*, ...)`, `Setup(void*, int, int, ...)`, `Grow(int, int, ...)`), the Lua
  stub structs whose 32-bit pads put `Obj_213470::p` where the 64-bit `lua_State` keeps `base`, and 0x00213470 /
  0x00216320 returning a `const char*` as `int`.
- The game's `snprintf` (0x000964a0 bound under the C name `snprintf` in 0x00203740) binds to the C library's on the
  native link; harmless (same contract).

## 64-bit pointer and layout fixes (ptr1, 2026-11-04)

The `--x64` check ([equivalence.md](equivalence.md) "64-bit check") runs a source's x86-64 object against its own
32-bit clang object. eq64's pilot, clean2's registration batch and va1's leftovers left a work list of 107 sources.
Most of their failures are shapes that recur across the tree, so ptr1 fixes the shapes tree-wide, most common first.
Every fix spells the same code on the 32-bit builds: MSVC 7.1's object is identical to HEAD's (`tools/ptr1.py proof`)
or the source still byte-matches, and equivalents stay promotable.

**Checker fixes first** (tools/equiv64.py, listed in equivalence.md "ptr1's checker changes"; regress `X64_CASES` 8 -> 18
cases, all ok; the full suite 423/424, the one failure 0x000ffef0_compare_chain fails on mac2 at HEAD too). 15 of the list's `int` failures were the checker pairing string literals by a rule meant
for `__ptr64` qualifiers; the game's allocators under C++ linkage, template classes' vftables and `void*` results the
source casts were not typed, so many real layout bugs showed as `untyped` or not at all.

**Batch 1: allocation sizes.** `operator new(0x10)` / `FUN_0008d690(24)` with the 32-bit size of the class the
memory becomes (placement-new'd or cast right after): every class with a vfptr or a pointer field is larger on 64-bit
(the TrackFactoryTemplate and ConditionFactory families, the fight parameter registrations' `ParamFloatConstRange` /
`ParamEnumConstList` / `ParamValueName` stubs, ...). The literal becomes `sizeof(T)`, kept only where MSVC's object
stays identical (the literal *is* the 32-bit `sizeof`): `build/ptr1/scripts/sizeof_rw.py` proposed 1,540 sources, the
object identity kept 1,238 (619 matches/, 619 equivalent/); the other 302 allocate more than their stub class
declares (the stub is short of the real class) and keep their literal.

| | control 44161 (06bcabc77, mac1) | batch 44162 (mac2) |
|---|---|---|
| gates | - | 619/619 MATCH + verify_relocs ok; 619/619 promotable at 3,000; 619/619 equivalent at 600 `--wine` |
| `--x64` over the 1,238 (same checker) | 99 equivalent | 1,182 equivalent, none newly failing |
| gen_tree merge modes | - | 0 changes |
| strict link rc / Wine unbound | 0 / 1,324 | 0 / 1,324 (the same set) |
| x87 keep list | 268 | identical |
| image | - | differs: 0x002b5770 no longer needs a compile-error wrap (one fewer: 737) |
| play3 checkpoints | 2,004 to 60,090 | identical at all 2,004 common frames |
| native unbound (macOS / Linux / Android) | 46,350 / 46,349 / 46,349 (va1) | 46,350 / 46,349 / 46,349, 3 front-end failures each (the same 3), all links rc 0 |

The first native compile of the batch lost 10 TUs: in a merged TU that declares the allocator twice
(`FUN_0008d690(int)` and `FUN_0008d690(hulk_uintptr)`), a 64-bit `size_t` argument converts to both. The argument is
now `(int)sizeof(T)`, the type the replaced literal had, so every TU resolves the call as before (the objects are
still identical: 1,238 / 1,238; 0x002b5770 is wrapped again as at HEAD, its call now resolving as the literal did). Native numbers without a Wine build: `build/ptr1/scripts/mksnap.sh` makes a clang-probe
snapshot from a workspace's gen_tree output with a proof build's `state.json` (on the batch's own sources it
reproduced that build's snapshot exactly), and the queue compiles it for the three targets (`native_jobs.sh`).

**Batch 2: hand-stored vptrs, pointer arrays, member-function pointers, the list's remaining shapes.**

| shape | sources | fix |
|---|---|---|
| `volatile int* p = (volatile int*)this; *p = vt; q = (T*)p[8];` (the 80 propagated `fight::Action` destructors, "Same code shape as 0x0010bd90") | 80 matches/ | the stub's pad starts with `hulk_intptr vtable;`, `p` is `volatile hulk_intptr*`, `q = *(T* volatile*)&m_20` |
| a non-virtual stub whose leading `char pad[N]` receives a hand-stored vptr (`*(hulk_intptr*)this = vt`) | 9 matches/ | `hulk_intptr vtable; char pad[N - 4];` (only stubs without a vfptr of their own and without byte-offset accesses into the pad: the other 101 candidates keep their spelling) |
| a non-virtual stub whose first `int` field receives the vptr, its fields reached by byte offsets (ConditionFactory `vfunc_5`s) | 9 matches/ | the field is `hulk_intptr`, the byte offsets name their fields (`p->c = 0`) |
| `(T **)FUN_0008d6d0(count * 4)` | 21 (19 + 0x002d3980 / 0x002d3b80) | `count * sizeof(T *)` |
| constructors called as members on raw memory (`((T *)mem)->FUN_...()`), pure3d's pool allocator (`pool->FUN_002888c0(0x1c, 7)`), `Method1` then `Closure1` placement-new on one block, a registration naming its classes by typedefs after the allocation | 28 equivalent/ | `(int)sizeof(T)` of the final class |
| member-function pointers in `int` fields (`*(bool (T::**)(int))&this->f_10`; 8 fight `Param*` templates, ~860 sources) | include/gen/fight.h | `f_10` / `ParamEnumConstList::f_18` are `hulk_intptr` (evidence-rn.json `ptr_fields`) |
| `core::MemoryDlAllocator` arena bounds `f_0c` / `f_10` compared with addresses | core.h, 0x0026cb20, 0x0026cb40 | `hulk_intptr` fields, compared as `(hulk_uintptr)this->f_0c` |
| `core::ICementLibrary` slot 7 takes a pointer as `int` | core.h | `vfunc_7(hulk_intptr, ...)` (evidence-rn.json `sigs`) |
| `owners::Obj_62180::FUN_00062180(float)` passed to `"%s"` (va1's leftover) | owners.h, 0x00062180 | `const char*`; FUN_00267760 declared variadic |
| Lua: `lua_State` stubs with `char pad[0x10]` before `l_G` (0x00213470, 0x00213440); `lua_pushfstring` / `luaO_pushfstring` returning `int` (0x00213470, 0x00216320) | 3 matches/ | the head as pointers (`next`, `tt`/`marked`, `top`, `base`), `const char*` returns (tests/native_host's harness follows) |
| byte offsets of the 32-bit layout: `(char*)this + 0x1a8` (0x000983d0), `(char*)this + 4` as a tree's end sentinel (0x00230ba0, nodes typed) | 2 matches/ | the stub's fields; `sizeof(void*)` |
| the `__fastcall` trick calling a thiscall slot with a dummy `edx` (0x00268020) | 1 equivalent/ | `this->vfunc_4(result)` |
| a callee declared `unsigned int` for the pointer it is given (0x0013a5f0), a pointer list copied as `unsigned int` (0x002347b0), png `pCAL` params `nparams * 4` (0x002e9880) | 3 | the pointer type, `hulk_uintptr`, `sizeof(char *)` |

Left out of the batch: six sources whose change is object-identical but whose equivalence runs are thin or fail at HEAD
the same way (0x0027def0, 0x002a6a20 under 50 inputs; 0x0028cd80, 0x00297680, 0x00297ba0, 0x0029a630 fail `--wine`),
and the 101 pad-vptr candidates whose class has a vfptr of its own or reaches the pad by byte offsets.

| | control 61835 (HEAD 93b84c383) | batch 61836 |
|---|---|---|
| sources | - | 153 (108 matches/, 45 equivalent/) + include/gen (core.h, fight.h, owners.h and their evidence) + tests/native_host's varargs harness |
| gates | - | 108/108 MATCH + verify_relocs ok; 45/45 promotable at 3,000; 45/45 equivalent at 600 `--wine`; `va_tree_test.sh` mac and x64 0 failures |
| `--x64` over the 153 | 15 equivalent | 141 equivalent, none newly failing |
| `--x64` over the 2,960 other sources naming a retyped header class | 2,609 | 2,777, none newly failing |
| gen_tree merge modes | - | 0 changes |
| strict link rc / Wine unbound | 0 / 1,324 | 0 / 1,324 (the same set); x87 keep list identical |
| image | - | differs: 0x002ea3c0 (libpng, a TU-mate of 0x002e9880) is isolated, its tree code differing from its standalone build |
| play3 checkpoints | 2,011 to 60,300 | identical at all 2,011 common frames (batch to 60,630) |
| native unbound (macOS / Linux / Android) | 46,350 / 46,349 / 46,349 | 46,350 / 46,349 / 46,349 from the batch build's snapshot, the same 3 front-end failures, links rc 0 |

**Totals.** `--x64` over the 1,391 sources ptr1 changed: 115 -> 1,326 equivalent; over every source checked (4,406:
those plus the header classes' users and the work list), 2,729 -> 4,108, none newly failing. eq64's work list of 107:
7 -> 54 equivalent.

**What is left of the list** (53): 18 `tool` and 8 `stubsize` sources whose 32-bit run never completes (calls through
member pointers kept in `int` fields, null-object writes, stub classes smaller than what the function writes); `untyped`
pads and `void*` the checker cannot type (0x0004ee60, 0x0005b230, 0x000e9160, 0x00251720, 0x002dbd90, 0x002ee260,
0x0032b6c0, 0x00362860); bool setters whose `int` return keeps a pointer's upper bits by accident of the register
(0x00035e70, 0x0010c8d0, 0x0012e710, 0x0012ee50: the callers read `al`; the checker compares the whole register);
byte offsets into include/gen/ classes' pads that need the real fields (0x00292ba0, 0x002a78c0 `pure3d::Camera`,
0x00217c80, 0x00219c30); checker artefacts of fuzzed indices and unrelated objects (0x000e8cf0, 0x001df4c0,
0x0033c6e0, 0x002fa7c0, 0x000a89c0's uninitialised local, the `intwidth` pair 0x0026d320 / 0x0026f7b0); a by-value
record with a destructor on Win64 (0x001f8670); 0x00277500 (crash64 at one seed after its slot is typed), 0x002e9880
(png `pCAL`: the `sizeof(char*)` fix is in, an aliasing artefact remains). va1's caller declarations that pass the Lua
state through `int` (`Format`, `Setup`, `Grow`, owners `Obj_1d19f0::field`) need the script classes' 64-bit layout.

## Unbound names of the 64-bit links (unb1, 2026-11-04)

A2 item 1 ([native-android.md](native-android.md) section 13). Before this work the native links had 46,350 unbound
names on arm64 macOS and 46,349 on x86-64 Linux and arm64 Android. The Wine build's strict link had 1,324. Five
name-unification batches had barely moved the native number.

**Why the two numbers differ.** They are not comparable. Before binding, the Wine build's strict link has about the
same undefined names as the native links: 47,639 symbols with 53,291 references (its `report.json`,
`undefined_before`). Its 1,324 is what is left *after* `tools/wine_link.py` binds 49,137 aliases. 39,129 of those
aliases come from the binding map, where each relocation is bound to the address it was proven to reach. Another
6,208 are stub-vftable slot aliases, and 1,488 are stand-in bodies. The native links bound nothing by name, by
design ([native-mac.md](native-mac.md) section 9).

Most names are undefined because of the tree, not because of how they are spelled:
- gen_tree puts every TU's own declarations in a TU namespace (`fn_f<7 hex>`), and wraps sources in `fn_<addr>`
  ([source-tree.md](source-tree.md)).
- So a call from one TU to a function another TU defines names a symbol nobody defines:
  `fn_00031310::FUN_0002b380` for the definition `fn_ff0a839e::FUN_0002b380`. Only include/gen/ and include/decls/
  names are global.
- A caller that spells its callee perfectly still does not meet the definition by name. That is why renaming alone
  moved the number so little.

**Classification** (`tools/native_unbound.py classify`; the same snapshot as ptr1's batch 2 build, HEAD d02bb4336).
The "Wine build" column says how the Wine link binds the same names: its binding map, looked up by demangled form.

| class | macOS | Linux | Android | how the Wine build binds them | fix |
|---|---|---|---|---|---|
| **A. the name carries an address, the tree defines it, the IR signatures agree, and the Wine map binds the name there** | 11,420 (11,809 refs) | 11,428 | 11,427 | equiv.py by name: 9,471; relocation position: 1,949 | **bound now** (below) |
| B. the name carries an address, but the caller's declaration passes differently on 64-bit | 9,961 (10,088 refs) | 9,953 | 9,954 | by name / position (on 32-bit the two shapes are the same stack and `eax`) | the sources' declarations (below) |
| C. the name carries an address, other reasons: the Wine map has no binding (474) or says another address (113); no tree definition (303); interior data address (250); a class named by address (126); no unique 64-bit definition (99); outside .text (36); bound in some objects only (19); ambiguous in the map (12) | 1,432 | 1,432 | 1,432 | by position, or stubbed | per case |
| D1. invented: virtual members of stub classes, referenced only by clang's stub vftables | 7,570 | 7,570 | 7,570 | stub-vftable slot aliases 6,224; stubbed 1,170 | include/gen/ classes (consolidation) |
| D2. invented: non-virtual members of stub classes | 6,908 | 6,908 | 6,908 | relocation position 6,374 | names that carry the address (clean2's convention) |
| D3. invented: free functions (`thunk_FUN_` included: the thunk is not at the address in its name) | 3,357 | 3,357 | 3,357 | relocation position 2,981 | the same |
| D4. invented: vftable variables (`CondVtable`, `g_vftable_1916c0`) | 2,121 | 2,121 | 2,121 | relocation position | `DAT_<addr>` / the class's own vftable |
| D5. invented: variables | 1,902 | 1,902 | 1,902 | relocation position | `DAT_<addr>` (include/decls/data) |
| D6. invented: constructors / destructors of stub classes | 1,308 | 1,308 | 1,308 | relocation position | include/gen/ classes |
| D7. invented C names (311) and RTTI descriptors (60) | 371 | 370 | 370 | relocation position, ambiguous renames | names in the sources |
| total | 46,350 | 46,349 | 46,349 | | |

Class B, by kind (macOS; the ELF targets differ by a few names):

| kind | names |
|---|---|
| argument count (`FUN_00019420()` called on a destructor that takes `this`; a member declared as a free function) | 3,504 |
| pointer / `int` argument | 2,721 |
| pointer / `int` result | 833 |
| `float` result for a `hulk_freg` (double) definition | 676 |
| `float` / `int` argument | 468 |
| pointer / `__int64` and `int` / `__int64` arguments | 526 |
| integers of other widths (`bool` / `char` / `short` / `int` / `__int64` results and arguments) | 1,011 |
| the rest (a void definition read for a result 102, `float` / pointer 48, code / data 15, sret and by-value aggregates, variadic / fixed) | 222 |

The B and D classes are the sources' work, not the link's. Two measurements:
- Even the rejected name table would not do it. Use the Wine map to bind the D names, with the same IR check:
  4,876 would bind. 7,452 have no binding in the map, 5,997 are bound to an address with no 64-bit definition, and
  the rest pass differently on 64-bit (`classify --whatif`).
- A definition-side fix would bind 2,585 B names in one go. These are 733 definitions that take or return an `int`
  where every caller passes a pointer (`build/unb1/scripts/defside.py`): 487 members, 148 free C++ functions, 87 C
  names and 11 `owners::` members. The fix is `hulk_intptr` / `hulk_uintptr` or the pointer type. Those spell the
  same on the 32-bit builds, so the MSVC and Wine objects stay identical.

**The fix: binding by the address in the name** (tools/native_unbound.py, called by both native links).

1. **Which names.** A name binds if it carries an address: `FUN_<addr>`, the suffix convention (`SetArc_000480a0`),
   or `DAT_<addr>` / `PTR_` / `hulk_at_` (tools/addr_names.py).
   - Every checker reads these names the same way (equiv.py name_address, wine_link name_address).
   - The tree's definition at that address is the tree build's report matched to the 64-bit symbols, as
     native_mac.TreeDefs does. If the types differ (a `hulk_freg` result, `hulk_intptr` parameters), the one
     function with that qualified name is used.
   - A data name binds to the data TU's item. A vftable or RTTI record binds to its link-table label.
2. **The ABI check.** Both native compiles now write `<obj>.sig.json` beside every object:
   - It holds the IR signature of every function the TU defines or declares, after the MS front end's lowering
     (`this`, sret / byval with their sizes, a constructor's returned `this`, `signext` / `zeroext` / `inreg`,
     `win64cc`), and the size of every global.
   - A reference binds only where its signature in that object equals the definition's.
   - `ptr` and `i64` count as equal: one 64-bit integer register or stack slot on all three ABIs.
   - A caller that ignores a result the definition returns is accepted.
   - Data binds when the referenced global is no larger than the item.
   - Signatures are compared per object, so a C name declared two ways in two TUs binds only where it agrees.
3. **The verification.** The sources' `FUN_` names are claims that no checker verifies. verify_relocs checks only
   the suffix convention.
   - 113 of them are wrong. Sources propagated from a function of the same code shape keep that function's callee
     names: matches/0x00024170.cpp calls `ThisCall_00067a20::FUN_00019420()`, and the call goes to 0x00067a20.
   - So the link takes the Wine build's binding map of the same tree (`--bindings`) and binds only names that the
     map binds to the address the name says.
   - Without a map, nothing binds by address.
   - The map is a check here and never a source of bindings: a name it binds elsewhere stays unbound.
   - All 11,420 bound names agree with the map (`classify`'s cross-check).
4. **Applying it.** The link renames, per object, the references to the definition's symbol (`llvm-objcopy
   --redefine-sym` on copies). This uses the step native_bind.py uses for the CRT table (its `extra` renames), on
   Mach-O and ELF alike. `--no-addr` turns it off.

`thunk_FUN_<x>` names carry no address. Ghidra names the thunk *to* x; the thunk sits elsewhere: 0x00263ea0 for
`thunk_FUN_0008d690`.

| | before (ptr1 batch 2's objects) | after |
|---|---|---|
| native compile | - | objects byte-identical to ptr1's (3,736 / 3,736 per target), plus a `.sig.json` sidecar |
| arm64 macOS unbound / ld64 | 46,350 / rc 0 | **34,930** / rc 0, 0 CRT binding problems |
| x86-64 Linux unbound / lld | 46,349 / rc 0 | **34,921** / rc 0, 0 problems |
| arm64 Android unbound / lld | 46,349 / rc 0 | **34,922** / rc 0, 0 problems |
| references renamed | - | 12,686 in 1,333 objects (macOS) |
| tests/native_host | - | crt_bind (3 targets), shim (3), replay_native, va_tree (mac, x64), rtti, entry: all ok; native_unbound_test 4/4 |
| macOS start-up | stops in init 1 at `FUN_0027b020` | init 1 runs; init 2 (0x0035c700) stops at `owners::String_23fc40::FUN_0023fb20`, a class B name: the definition takes `unsigned int` for the caller's `const char*` |

No Wine build input changed. The Wine build does not import the native tools, and no source, header or gen_tree
changed.

```sh
PY=build/venv/bin/python; export HULK_CLANG_PROBE_DIR=<dir with snap/>
$PY tools/native_mac.py link --ld --bindings <Wine build's bindings.json of the same tree>
$PY tools/native_elf.py link --target linux-x64 --ld --bindings B.json
$PY tools/native_unbound.py classify --dir build/native-mac [--fmt elf] [--unbound U.txt] --bindings B.json \
    --wine-unbound <Wine unbound.txt> [--whatif] [--json OUT]     # the table above
$PY tests/native_host/native_unbound_test.py
```

The Wine build's binding map lives in the lineage workspace on the build host: `~/hulk-jobs/nb/ws/<lineage>/build/native/bindings.json`.

**Left, largest first.**
1. **Stub vftables (D1, 7,570).** Clang emits vftables for stub classes, and their slots reference stub members. The
   Wine link points those vftables at the game's and aliases their slots by the binding map. Native code that
   installs a stub vftable would call stubs. The consolidation (include/gen/ classes with their real vftables) is
   the fix.
2. **Invented callee names (D2, D3, D6: 11,573).** Callers name the callee by an invented stub name. The fix is
   renaming to the clean2 convention (`Fin_00165d30`), which the link now binds. name_unify.py has the machinery. At
   most about 4,900 of them have a matching IR signature today.
3. **Declarations that pass differently (B, 9,961).**
   - The definition-side batch: 733 definitions, 2,585 names.
   - Callers' declarations: the argument-count class, and 676 `float` callers of `hulk_freg` functions.
   - These are real 64-bit bugs, not naming problems.
4. **Data and vftable variables (D4, D5: 4,023).** `DAT_<addr>` names and include/decls/data.
5. **Class C (1,432).** Of these, 113 `FUN_` names in sources are wrong. A `name_address_mismatch` sweep of
   verify_relocs over `FUN_` names (clean2's open item) would find them in matches/.

## Definition-side retyping: the B names a definition can bind (unb2, 2026-11-04)

unb1's top source batch. A class B name stays unbound when the caller passes a pointer (`ptr`) where the definition
takes or returns an `int` (`i32`). On 32-bit the two are the same stack slot or `eax`; on 64-bit they are not, so the
IR check refuses the binding. When every caller passes a pointer, the definition is what is wrong: the original held a
pointer in an `int`. Retyping the definition's parameter or result to `hulk_intptr` / `hulk_uintptr` (or
`hulk_longptr` / `hulk_ulongptr` for `long`) binds those callers. These typedefs are the same type as before on the
32-bit builds ([ptr.h](../include/compat/ptr.h)), so the MSVC and Wine objects do not change.

**The plan** (`build/unb2/scripts/plan.py`, on unb1's objects and the Wine map of the same tree):
- For each definition, every reference the address binding resolves to it, bound or not.
- The fix sets the callers ask for (argument positions plus the result), and which set binds the most names.
- The net gain: names the fix binds minus names that bind today and would stop (a caller that does pass an `int`
  there). unb1's 2,585 counted gains only.
- 735 definitions have a candidate. 672 gain names: 2,321 net.

**The rewrite** (`build/unb2/scripts/rw.py`, libclang on the x86-64 MSVC target):
- Finds the definition by its 64-bit mangled name (TU namespaces stripped, back references compared demangled).
- Maps IR positions to source parameters (`this` and sret skipped).
- Rewrites every declaration of that function in its source: the stub class's member declaration, forward
  declarations, the definition. The int keywords or the typedef name of the parameter / result become the
  pointer-sized typedef.
- 628 rewritten. Left out:
  - 18 declared in include/gen/ headers (owners.h 10, global.h 4, pure3d.h, physics.h, Render.h): 34 names. One
    was done by hand (batch 2 below).
  - 24 sources that libclang cannot parse for x86-64 (`operator new(unsigned int)`, `memset` declarations). The
    13 that parse leniently bind 16 names only.
  - 1 replay pin (`0x00086450`) and 1 not found.

Every rewritten source was MSVC-identical to HEAD: `tools/ptr1.py proof`, 628 / 628.

**What the 64-bit front end found.** gen_tree hoists every declaration variant of a function into the TUs that use it,
as C++ overloads. On 32-bit `int` and `hulk_intptr` are one type, so a retyped parameter changes nothing there. On
64-bit, an argument of the new type can make another call ambiguous between `f(int)` and `f(unsigned int)`, or fail
to bind an `int*` parameter (`&param`):
- The first native compile had 9 front-end failures (3 at HEAD).
- `build/unb2/scripts/fe.py` runs the native front end (`-fsyntax-only`, every error) over the batch's TUs and maps
  each error to its source.
- It named 8 sources: 0x002e6b20, 0x00339dc0, 0x001d1e50, 0x001af650, 0x002722b0, 0x000ceb80, 0x002eb140,
  0x00339e60. They were taken out.

Also taken out:
- Three `--x64` regressions: 0x00213b20, 0x000e2800, 0x0008ca70.
  - 0x00213b20: the checker pairs a local static by a mangled name that carries the function's signature.
  - 0x000e2800: a `-1` result, `intwidth`.
  - 0x0008ca70: a 9-input run.
- Three equivalents whose `--wine` run fails the same way at HEAD: 0x000aa450, 0x000bc900, 0x00264050.

**Batch 1: 614 definitions** (474 matches/, 140 equivalent/; 125 results, 513 with parameters; planned net 2,208).

**Batch 2: the start-up stop.** unb1 left the macOS start-up stopped in init 2 at
`owners::String_23fc40::FUN_0023fb20`. Its definition `owners::Obj_23fb20::FUN_0023fb20` is declared in owners.h,
so batch 1 left it out:
- The function stores the string pointer in the stub's first field.
- On the copy path, it passes that field's address to `FUN_0023fa40`, which writes a new buffer pointer through it.
- The fix: `Obj_23fb20` holds `const char *value` (include/gen/evidence-owners.json, owners.h regenerated: 12 ->
  16 bytes on 64-bit), and the definition takes `(const char *, hulk_uintptr, hulk_uintptr, int)`.
- `FUN_0023fa40` takes `char **out`, written through as a pointer. It used to read the stored pointer back as `int`
  (`*out - 2`).
- Both still byte-match, with verify_relocs ok. The 32-bit name of 0x0023fb20 changes (`QAEXPBDIIH`); the Wine map
  binds it by address.
- `--x64`: 0x0023fa40 goes from `layout` fail to equivalent, and 0x0023fb20 stays equivalent. The variant that keeps
  `hulk_uintptr` for the pointer failed `intwidth` / `call`: the callee's stub wrote 4 bytes through an `int*`.

| | control 62465 (HEAD 04cce9abf, mac2) | batch 62466 (batch 1 + 2, mac2) |
|---|---|---|
| sources | - | 616 (476 matches/, 140 equivalent/) + owners.h, evidence-owners.json |
| gates | - | 476/476 MATCH + verify_relocs ok; 140/140 promotable at 3,000; 140/140 equivalent at 600 `--wine` |
| `--x64` (same checker, before / after) | 523 equivalent of 616 | 525, none newly failing (newly equivalent: 0x001fa7d0, 0x0023fa40) |
| gen_tree merge modes (27,474 blocks) | - | 0 changes |
| strict link rc / Wine unbound | 0 / 1,324 | 0 / 1,324 (the same set); x87 keep list identical (268); image differs |
| play3 checkpoints | 2,016 to 60,450 | identical at all 2,004 common frames (batch to 60,090) |
| native front-end failures (each target) | 3 | 3 (the same) |
| arm64 macOS unbound / ld64 | 34,930 / rc 0 | **32,870** / rc 0 |
| x86-64 Linux unbound / lld | 34,921 / rc 0 | **32,861** / rc 0 |
| arm64 Android unbound / lld | 34,922 / rc 0 | **32,862** / rc 0 |
| tests/native_host | - | crt_bind (3 targets), shim (3), replay_native, va_tree (mac, x64), rtti, entry: all ok; native_unbound_test 4/4 |
| macOS start-up | init 2 (0x0035c700) stops at `FUN_0023fb20` | init 2 and 3 run; init 4 (0x0035c740) stops at `Hash` |

The native numbers come from the same tree as the Wine build, bound with that build's own binding map (`--bindings`).
Batch 1 alone (its own tree, the control's map): 32,871 / 32,862 / 32,863.

The proof builds are lineages built fresh (`--state fresh --map full`) and then linked and replayed with `--gfx`
(`--state resume --map reuse`). The batch's checkpoints are identical to the control's, so they agree with the Xbox
exactly as far as HEAD does (to 43,170).

**Notes for the next batch.**
- A Wine build without `--gfx` cannot replay. wine_link wraps GameClock::Update with `hulk_native_frame`, the
  checkpoint hook, only for the pddi backend. Without it the image crashes in `main` after 54 imports.
- gen_tree's output depends on the hash seed (`struct` / `class` spellings of stub forward declarations, declaration
  order). The Wine builds run it with `PYTHONHASHSEED=0`. A native snapshot made from a workspace tree must use the
  same seed, or the two A/B trees differ in hundreds of lines, and in mangled names (`V` / `U`), that no source
  changed.
- The next start-up stop: `matches/0x0035c740.cpp` calls `FUN_0027b020` under an invented name, `Hash` (class D3).
  The callee's name with the declaration most of its callers use (`extern "C" __int64 __cdecl FUN_0027b020(const
  char*)`) binds it.

**What is left of class B.**
- Definitions: the 18 header-declared ones, the 24 sources libclang cannot parse for x86-64, and the 14 taken out
  above. The 63 definitions whose net gain is zero or negative are mixed: some callers pass a pointer, others an
  `int`. The callers are wrong there, not the definition (0x00266a30, a chunk reader's `unsigned int` result: 33
  callers bind today, 27 want a pointer).
- **`float` callers of `hulk_freg` results (676 names, 81 definitions) are not done.** The fix is to declare the
  callee's result as `hulk_freg` in the callers: 758 declarations in 453 sources.
  - On MSVC the object stays identical (`hulk_freg` is `float` there).
  - On the Wine build it changes code: each caller would take a `double` from `st(0)` instead of rounding it to
    `float` first. The original MSVC callers do keep the full register value, so this would be closer to the
    original. But it changes float results wherever a caller computes with the value before storing it, so the play3
    checkpoints can move.
  - Unifying the declarations also changes which sources merge.
  - It needs its own batch, proof and float review.
- **Argument-count mismatches (about 3,500 names):** a destructor or member called through a free-function
  declaration that does not pass `this`, or extra and missing arguments. None has a one-line fix at the definition.
  They need the callers' declarations: the member through its include/gen/ or owners class, as name unification
  batch 4 did.

## Start-up stops and the name/address sweep (unb3, 2026-11-05)

Two steps toward native links that bind by name without the Wine build's map:
- **The macOS start-up.** It stopped in initializer 4 of the game's 466 static initializers, which `entry_posix`
  runs in a loop.
- **The names.** The sources' `FUN_` / `DAT_` names were claims that no checker verified. unb1 found 113 wrong
  ones among the native links' names.

### Placeholder names are checked

`tools/verify_relocs.py` already checked the suffix convention (`SetArc_000480a0`, clean2). It now checks Ghidra's
placeholders the same way (`placeholder_address()`):
- **Which names:** a relocation whose symbol's leaf is `FUN_<addr>` / `LAB_<addr>` (a function; `thunk_FUN_x` is not
  at x), or `DAT_` / `PTR_` / `hulk_at_<addr>` (a data item).
- **The rule:** the relocation must reach that address. For data, the addend is taken off first, so
  `(char*)&DAT_x + 4` reads x.
- **Failure:** a hard issue, `name_address_mismatch`. `RELOC_OFF=placename` turns the check off.
- **Regress:** `RELOC_CASES` gains `0x00024170_fun_name` / `..._wrong` and `0x00068cc0_dat_name` / `..._wrong`.
  All 11 reloc cases pass.

Equivalents have no relocation map. Their names bind by rule 3 of equiv.py's binding order. Only a `// equiv-map:`
line can bind a placeholder name to another address, and the sweep reads those from the level-2 mapping.

**The sweep** covered every source, as queue jobs on `git archive HEAD` (`build/unb3/scripts/sweep_job.py`, 40
shards): 22,340 matches through `verify_relocs.check`, and 5,140 equivalents through equiv.py level 2.

| | names | sources |
|---|---|---|
| wrong placeholder names found | 1,214: 1,039 data, 171 `FUN_` in matches/; 4 `FUN_` in equivalent/ (all four through `equiv-map` lines) | 771: 767 matches, 4 equivalents |
| other hard verify_relocs issues found | none | - |
| fixed | 1,211 | 768: 766 matches (one of them, 0x0035fa80, in batch A), 2 equivalents |
| left | 3 | 3, listed below |

Almost all of them come from propagation. A source made from a function of the same code shape kept that function's
names (`// Same code shape as 0x000482e0 (propagated; names are from that function)`):
- 80 fight-track registrations read `DAT_004dc3f8` / `DAT_004dc3fc` for their own pair of globals.
- About 100 getters return `DAT_004dd780` / `DAT_004dd6e4` for their own item.
- Destructors call `FUN_00019420` for their own base destructor.

**How each one was fixed** (`build/unb3/scripts/fixmm.py`):
- The leaf is renamed to the address the relocation reaches. This is done only when every reference of that leaf
  in the source goes to the one address.
- A data name gets the `include/decls/data/` header that declares it (573 sources).
- If the new item's declared type does not fit the code (an array or a pointer where the old name was an `int`),
  the use becomes a view of the old type: `(*(int*)&DAT_x)`, 141 sources (`castfix.py`).
- 21 items are not in the data inventory's headers. They are declared in the source with the old type
  (`declfix.py`).
- MSVC's object stays identical. Only relocations change, and compare.py masks them.

Some fixes needed more than a rename:
- **0x000fc020.** The wide variant of `FUN_000fc000` called `FUN_000fbc00`, the narrow formatter. The call goes to
  0x000fbe00, the wide formatter.
  - The source now declares 0x000fbe00 with its own types.
  - `tests/native_host/va_tree_game.cpp` had encoded the wrong pairing. It now passes a wide format and expects
    0x000fbe00. va_tree: 0 failures on macOS and on x64.
- **Four getters of pointer items.** 0x0027f250 and 0x00240780 read their item through `*(hulk_intptr*)&`.
  0x001eb200 and 0x00328510 also return `hulk_intptr`.
  - 0x00328510's definition was named `FUN_00085cd0`. It is now `FUN_00328510`.
  - With the `int` view these failed `--x64` (`ptrtrunc`).
- **0x00336f10.** It calls 0x003352b0 as `SetVtable_003352b0`, a suffix name. The name `FUN_003352b0` collides with
  a member of that name in another source, and gen_tree then isolated it.
- **Two equivalents** dropped their `equiv-map` lines with the rename (0x0003f090: 0x002325f0; 0x00093600: 0x000c2c10).
  - 3,000 inputs: 873 / 3,045 inputs, equivalent.
  - `--wine` 600: 650 / 718 inputs, equivalent.

**Left (3 names in 3 sources).**
- `matches/0x000964d0.cpp` is a replay pin, not touched. It names `DAT_004dd6e4` for 0x004e5acc, the seq-rng pointer
  that the native replay hook table also wants named by address. It now fails verify_relocs (`name_address_mismatch`)
  and needs its owner's change.
- `equivalent/0x0013e070.cpp` and `0x002b3340.cpp` call the thunk 0x00263ea0 under `FUN_0008d690`, the function it
  jumps to. Their `equiv-map` line says so. No tree source defines 0x00263ea0, so renaming would lose a binding that
  behaves correctly.

Definition names have the same disease, and this sweep does not check them. 152 sources define a `FUN_<x>` that is
not their own address. Some of those definitions are helper bodies of a callee; others are propagated names, such as
0x00328510's.

### The start-up stops

**Method.** Each iteration builds a private workspace (HEAD plus the batch), then:
1. gen_tree with `PYTHONHASHSEED=0`;
2. a clang-probe snapshot, compiled for arm64 macOS as a queue job;
3. a local link, with a map that adds the batch's own verified address names to a base Wine map;
4. a run with `HULK_TRACE_FILE`.

The scripts are in `build/unb3/scripts/`: `iter.sh`, `gtfe.sh`, `augmap.py`, `reach.py`, `initnames.py`.

Two traps:
- **The 64-bit front end.** An early iteration seemed to reach initializer 316. In fact the merged TU
  `src/game/init/dynamic_initializers.cpp` failed the 64-bit front end, so all its initializers were skipped (the
  trace's `skip` lines).
  - The cause: an `extern "C" unsigned __int64 FUN_0027b020(const char*)` at global scope, where `decls/address.h`
    declares the same function with C++ linkage.
  - Every iteration tree now goes through `fe.py`: the 64-bit front end, `-fsyntax-only`, every error mapped to its
    source. Its failures must equal HEAD's.
- **The build_tree state.** The tree that counts is the proof build's, generated with that build's own build_tree
  state (`nb-out/tree-state.json`), not a stale `state.json`.
  - With the old state, batch A's image left initializer 7 unbound. 0x0035c7a0 was wrapped there for a C2732 that no
    longer happens; the batch's map is of the real tree.
  - `mksnap2.sh` makes the native snapshot from the proof's own state, and the numbers below come from it.

`reach.py` reads the image's disassembly and the link's `stubs.s` / `startup.s`. For each initializer in run order, it
lists the missing-name stubs that direct calls (`bl` / `b`) reach, with the path:
- unb2's image: 246 stubs;
- batch A: 106;
- batch B: 101.

Calls through vftables are not followed, so the run decides.

`initnames.py` lists each initializer's references whose names carry no address, with the targets from verify_relocs
(matches) or level 2 (equivalents).

| initializers | stop (64-bit name) | class | fix | batch |
|---|---|---|---|---|
| 4 (0x0035c740) and 52 more | `Hash`, `GetHash`, `Lookup`, `parse`, `MACRO_LOOKUP`, ... for the hashers 0x0027b020 / 0x002672f0 | invented C / C++ names (D3) | `FUN_0027b020` / `FUN_002672f0`. Merged sources use `decls/address.h`'s declaration. A by-value result that is 16 bytes on 64-bit (`{char*, char*}`, `{void*, unsigned}`) becomes `unsigned __int64`: on 64-bit it comes back through memory | A, B |
| about 60 | `Registry::init`, `Manager::Register`, ... (0x002584d0, a constructor called as a member); other members | invented member names (D2) | the leaf becomes `FUN_<addr>` and the stub class stays. The shared `Registry` stub takes one signature, with casts | A |
| 25, 149, 189, 211 and 11 more | `Sound::Sound`, `T::T`, `G::Reg`, `Obj::Init(const char*, float)` for 0x0023fc40 | stub constructors / members for `owners::String_23fc40::FUN_0023fc40` (D6 / D2) | the form 0x0035c700 uses, `((owners::String_23fc40 *)&X)->FUN_0023fc40(s, (hulk_intptr)0)`. Dynamic initializers (`Sound gSound(...)`) get a class derived from `owners::String_23fc40` whose inline constructor makes the call | A (25, 189: B) |
| 290, 313-316, 342, 358, 375 | `Obj::Obj()`, `Thing::Thing()` called directly | stub constructors (D6) | the member `FUN_<addr>()`; inline constructors for dynamic initializers | A |
| 71 | `FUN_0027b020` returning `{void*, unsigned}` | B: result passed through memory | `unsigned __int64` | B |
| 213 | `Obj::FUN_002fb160(int, int, int)` | B: the definition takes `unsigned short` | the caller's declaration | B |
| 247 | `Reg(void*)` | an invented name for `atexit` | `atexit` (the CRT table binds it) | B |
| **67** (B stops here) | `init@16` (0x00011520, the vector-constructor iterator) | invented stdcall C name | not done: naming it merges 0x0035d2d0, and then its `target()` and its stub `Item` clash with TU-mates (0x0035dc90, 0x0035ee50) | - |

Atexit handlers mostly keep their invented names (`cleanup`, `Done`, ...). They only run at exit.
- Naming a handler by address makes gen_tree's emitter give the merged caller's declaration C++ linkage, beside the
  handler's C definition. The TU then fails the 64-bit front end, or the handler's block wraps.
- 0x00364200 and 0x003640a0 lost their wrapping conflicts as a side effect, so their callers' declarations did not
  have to change. Their definitions now have C++ linkage instead, to match.

**What is left after 67** (batch B's image, static reach):

| initializers | what | class |
|---|---|---|
| 67 | as above | gen_tree merge |
| 216 | the allocator 0x0008d690, then `FUN_0026da80`, then `FUN_0026d990`, then `XAPILIB::ConvertThreadToFiber` / `SetThreadPriority` | XDK imports have no native binding ([native-android.md](native-android.md) 14.3, item 2). The allocator's own `Init` / `first` / `second` can be named by address, but that changes 0x0008d480's and 0x0008d6d0's modes (`void` / `int` variants of `FUN_00266d90`) |
| 253 | 0x0035ee50 `Item::init` (0x0027af00) | the member rename changes `Item`, and gen_tree merges that class with a TU-mate's |
| 255-280 (14) | `FUN_002672f0` declared `(int, int, int)` / `(unsigned, ...)`, with the name passed as an `int` from a getter (0x003469f5) | B: pointer / `int` argument and its source |
| 284, 290, 316, 358 | a base-class constructor in a constructor's initializer list (0x00242010, 0x002455e0, 0x0024dae0, 0x00253120), defined as a stub class in another TU's namespace | D6: include/gen/ classes with constructors (`om::MetaEntityType`, `audio::SeqEventType`, ...) |
| 308-312 | `MetaType::FUN_0025fa00(const char*, int)`. The definition stores the name pointer in an `int` key (`Pair_25fa00`) | layout |

### Batches and proofs

| | control | batch A (start-up) | batch B (start-up 2 + the sweep) |
|---|---|---|---|
| sources | HEAD 2446ba9bb | 183 matches/ (181 committed in a276e8d7e; 0x0035e340 / 0x0035e640 changed again in B) | 773: 771 matches/, 2 equivalent/ |
| gates | - | 183 / 183 MATCH + verify_relocs ok (the new check included) | 771 / 771 MATCH + verify_relocs ok; 2 / 2 promotable (3,000) and equivalent `--wine` (600); regress reloc cases 11 / 11 |
| `--x64` (same checker, HEAD -> batch) | - | 129 -> 130 equivalent of 183, none newly failing | 734 -> 736 of 773, none newly failing |
| 64-bit front end (failing TUs) | 3 | 3 (the same) | 3 (the same) |
| merge modes (proof trees, against the batch before) | - | 10 changes. 8 wrapped -> merged (0x0035ca70, 0x0035d720, 0x0035d890, 0x0035dfc0, 0x0035ea90, 0x0035f640, 0x0035fc50, 0x00360670: their invented names conflicted, and both sides are now named by address); 0x00364200 merged -> wrapped; 0x0035c7a0 wrapped -> merged, not in the batch (its C2732 compile-error wrap is gone) | 5 changes. 0x0035d3a0 / 0x0035ed90 wrapped -> merged; 0x003640a0 merged -> wrapped; 0x000b86b0 / 0x002ea3c0, not in the batch, isolated -> wrapped (build_tree no longer finds their tree code different from the standalone build) |
| Wine proof (`--gfx`, play3 to 60,000, limit 14,400) | 62531 on mac1; 63151 (= batch A) on mac2 for B | 62646 (mac1) vs 62531 | 63161 (mac2) vs 63151 |
| strict link rc / Wine unbound | 0 / 1,324 | 0 / **1,321**. Gone: two ambiguous invented names (`Cleanup`, `Obj::Init`). Two TU-local `~Sound` stubs became one, and `registry` is now spelled `class` | 0 / 1,321 (the same set as A) |
| x87 keep list | 268 | identical | identical |
| play3 checkpoints | 2,014 to 60,390 | identical at all 2,014 common frames (batch to 60,870) | identical to A at all 2,011 common frames (to 60,900) |
| arm64 macOS unbound / ld64 | 32,870 / rc 0 | **32,671** / rc 0 | **32,631** / rc 0 |
| x86-64 Linux unbound / lld | 32,861 / rc 0 | **32,662** / rc 0 | **32,622** / rc 0 |
| arm64 Android unbound / lld | 32,862 / rc 0 | **32,663** / rc 0 | **32,623** / rc 0 |
| macOS start-up | stops in initializer 4 (`Hash`) | runs 4-24, stops in 25 (`G::Reg`) | runs 25-66, stops in **67** (`init@16`) |

The proof checkpoints are identical to the control's. The batches therefore match the Xbox exactly as far as HEAD
does (to 43,170).

The native numbers come from each proof build's own clang-probe snapshot, copied from the lineage workspace's
`build/clang-probe/snap`, and each is bound with that build's own Wine map (`--bindings`).
- A snapshot regenerated locally with the same state has the same tree, but an older `report.json`.
- With it, two merged initializers (7, 30) have no definition, and the start-up skips them.
- Commit a276e8d7e's message gives batch A's numbers from that older snapshot: one name more on each target. All native links have 0 CRT
binding problems. tests/native_host all pass: crt_bind and shim (3 targets each), replay_native, va_tree (macOS and
x64), rtti, entry, native_unbound_test 4 / 4.

