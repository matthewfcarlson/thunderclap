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
- `matches/0x000964d0.cpp` is a replay pin, not touched (dec1 has since renamed it, with the user's approval). It names `DAT_004dd6e4` for 0x004e5acc, the seq-rng pointer
  that the native replay hook table also wants named by address. It now fails verify_relocs (`name_address_mismatch`)
  and needs its owner's change.
- `equivalent/0x0013e070.cpp` and `0x002b3340.cpp` call the thunk 0x00263ea0 under `FUN_0008d690`, the function it
  jumps to. Their `equiv-map` line says so. No tree source defines 0x00263ea0, so renaming would lose a binding that
  behaves correctly.

Definition names have the same disease, and this sweep does not check them. 152 sources define a `FUN_<x>` that is
not their own address. (dec1 renamed 125 of them by address: "Definition names by address" below.) Some of those definitions are helper bodies of a callee; others are propagated names, such as
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


## Start-up stops 67 to 216 (unb4, 2026-11-05)

Continues unb3's start-up work on a2s2's image (the XDK tables bound, the replay layer linked). The macOS start-up
stopped in initializer 67. It now runs initializers 0-215 and stops in **216**, on a layout problem that naming
cannot fix.

### The stops

Each iteration is unb3's method: a private workspace (HEAD plus the batch), gen_tree with `PYTHONHASHSEED=0` and
unb3 batch B's proof state, a clang-probe snapshot compiled for arm64 macOS as a queue job, a link with the B map plus
the batch's own address names, and a run, normal and in a2s2's survey mode (`HULK_NATIVE_MISSING=continue`). Scripts:
`build/unb4/scripts/` (`gtt.sh`, `iter.sh`, `run.sh`).

| initializer | stop | class | fix |
|---|---|---|---|
| 67 (0x0035d2d0) | `init@16`: the vector-constructor iterator 0x00011520 under an invented stdcall C name; its callback `destroyItem` (0x000b06e0, the 8-byte object's constructor), `cleanup` (0x00363dc0), `items` (0x004ddb68) | invented names (gen_tree merge) | every name by address. The source now merges, so its declarations must agree with its TU-mates: 0x0035d340 (the same pattern for 0x004ddab0) takes the same `extern "C"` declarations of 0x00011520 / 0x000b06e0 and the same `Obj_b06e0` record; the definition is `FUN_0035d2d0`, not `target` (0x0035dc90's); the row type is no longer `Item`, which 0x0035ee50 defines differently |
| 67, at exit | 0x0035d340's handler `cleanup` = 0x00363d90 | invented C name | left: only runs at exit. Naming it needs the gen_tree fix below |
| 99 (0x0035d720) | `FUN_0027b020(0x400488u)`: the source pushed the address of the string `"{"` as an integer, so the 64-bit image passed 0x400488 to the hasher | **B: an address written as an integer literal** (the bytes are the same, so compare.py and verify_relocs.py could not see it) | `FUN_0027b020("{")` with decls/address.h's declaration; the two result words by address (0x004ddfb0 / 0x004ddfb4) |
| 216 (0x0035e6b0) | the allocator 0x0008d690: `Obj::Init` (0x0008d480), `first` (0x00266d90), `second` (0x00266e00) | invented member and free names (D2) | by address, with the declarations its twin 0x0008d6d0 and the TU-mate 0x0008d480 use: `Storage::FUN_0008d480`, `extern "C" int FUN_00266d90()`, `extern "C" void* FUN_00266e00(int, hulk_intptr)`. 0x0008d480 (an equivalent) declared `FUN_00266d90` `void`: now `int` (3,020 inputs equivalent, complete coverage; `--wine` 620 equivalent) |
| 216 | `FUN_0026da80` called through `g_initCS`, the kernel slot RtlInitializeCriticalSection (0x003f2d38) under an invented name: a zero data stub, so a call to 0 | invented name for library data | `DAT_003f2d38`, which a2s2's XDK table binds to the shim's slot. The same for the other slot users of the TU: `enterFn` / `leaveFn` (0x0026d8f0), `gInit_26d820` / `_26d840` / `_26d850`, all spelled as 0x0026dad0 spells the slots (`extern "C" void(__stdcall* DAT_003f2c8c)(void*)`) |
| 216 | `FUN_00267280` (the loader registry's set-up) calls `InitA` / `InitB` (0x00270510 / 0x002705f0) and stores `Vftable` (0x0042af2c) | invented names | by address; the vftable as `DAT_0042af2c`, the label the native link gives a vftable's slot 0 |
| **216** (stops here) | `FUN_00266f40` returns the registry table's object pointer as an `int` (0x0ded570 in one run), and 0x0008d480 calls through it | **layout**: the table at 0x00527c58 | not fixed, below |

The normal run now ends with `crash signal=11 ... ?FUN_0008d480@Obj_8d480@...+0x70 phase=init 216`; the survey run
ends the same way (a crash ends it).

**Why 216 is a layout stop.** 0x00527c58 is a 744-byte `.bss` item: a pointer, then 46 records of 16 bytes from +8.
config/data-ptrs.json's evidence (0x00267110) gives the record as `{Object* object; unsigned value; Entry* next;
List* list;}`, three pointers. 55 sources touch the item, and they disagree: 0x00267280 writes `{void* p; int a, b, c;}`
at a byte stride of 16, 0x00266e00 indexes `{Item* p; char pad[12];}` (24 bytes on 64-bit), 0x00266f40 reads the
pointer as `int`, 0x00267110 uses the three-pointer record. On 64-bit the record is 32 bytes, so the table needs
8 + 46 x 32 bytes, but data_gen emits the `.bss` item with its XBE size and only the first word typed as a pointer
(`struct DataLayout_00527c58 { void* p0; unsigned int w4[185]; }`): data_gen's record views
(`config/data-ptrs.json` `records`) are not applied to `.bss` items. The fix is one record type for the table in every
source that touches it, and record emission for `.bss` in data_gen; a data-step change with its own proof.

What that fix involves (not done here):
- **The record.** Read together, the accessors describe one record of four pointers: `{Object* object; Entry* head;
  Entry* next; Entry* list;}`. 0x002670b0 links an entry into the list of entry `b` (its `head`, +4), 0x00267110
  unlinks it (`list->head` is the same +4 word), and 0x00527f40 is a sentinel entry of the same type, the fallback
  list. 0x00527f50 is a static object (its vftable 0x0042af2c), and 0x00527f58 points to it.
- **The sources.** Nine index the records: 0x00266e00, 0x00266eb0, 0x00266f00, 0x00266f20, 0x00266f40, 0x002670b0,
  0x00267280 (matches) and 0x00267110 (an equivalent, 73 inputs, incomplete). The other 46 read only the first word
  (the registry pointer).
- **data_gen.** `record_item()` gives up on a record view whose base is not 0. This table's records start at +8, after
  the pointer, so the generator needs a prefix before the records (the `pointers` evidence types it) and the `.bss`
  path. The 32-bit layout stays the XBE's (the size assertion checks it).

### Pointer-width fixes on the way (initializers 255-280, 253, and the hashers)

Static reach (unb3's `reach.py`; disassembly with `llvm-objdump -d`) showed what follows 216, so the batch also takes
the initializers after it whose fixes are names or signatures:

- **The hashers' name pointer (255-280, 24 sources).** `FUN_002672f0` declared `(int, int, int)`, `(unsigned, ...)`
  or `(u32, ...)`, with the name read from its data item through an `int` view. The declaration is now decls/address.h's
  (`unsigned __int64 FUN_002672f0(const char* s, int a, int b)`), the argument `(*(const char**)&DAT_x)` (the
  inventory types these items `const char*`), and the 8-byte result goes to its two 4-byte items as two stores (an
  8-byte store across two data items is wrong on 64-bit, where the items are separate variables: `--x64` reported it as
  a write past the item). `build/unb4/scripts/fixhash.py`, `normhash.py`, `splitstore.py`.
- **typeid names (5 sources).** Five initializers hash `typeid(T).name()`: the call is type_info::name (0x003469f5,
  the native CRT table's `hulk_ncrt_type_info_name`) on the type descriptor (`DAT_004c8040` ..., which the native link
  emits as 64-bit type_info objects). They declared it as `int` on invented objects (`gSource`, `gThing`, ...): now
  `const char* TypeInfo_3469f5::FUN_003469f5()` on `DAT_<descriptor>`.
- **253 (0x0035ee50).** `Item::init` is 0x0027af00 (`Item_35ee50::FUN_0027af00`), `entries` 0x004e37b8, `cleanup`
  0x003640f0.
- **0x0035f230** reads 0x004ca298 as the name pointer. The data inventory types that item `int` (`scalar`), but its
  value (0x0042777c) is a string's address: the native data holds the 32-bit number. A data_inventory fix (with
  0x004ca29c, typed the same way) is needed before this initializer can run.

### A gen_tree bug, found and left for a decision

gen_tree compares the shapes of a TU's C-linkage declarations so that two different C declarations of one name
don't share the TU (the second gets C++ linkage). A declaration's parsed signature keeps its closing `;`, so it never
has the same shape as the C definition of the same name and type. When that definition is a merged block (the same
namespace as the TU's shared declarations), the declaration is emitted `extern "C++"`: clang rejects the definition
("declaration of 'FUN_00363d90' has a different language linkage") and MSVC reports C2732, so build_tree wraps the
definition. This is why unb3 kept the atexit handlers' invented names: naming one by address makes its caller's
declaration collide with the handler's C definition.

The fix (`build/unb4/gen_tree-unb4.py`: the shared declarations take a merged C definition's shape with the `;`) is a
no-op on a tree generated with HEAD's build_tree state (0 lines differ). A fresh build_tree converges differently:
proof 63227 (this batch plus the fix, on the control's host) had 389 merge-mode changes against the control. 311 were C2732 wraps that
were gone, mostly the init TU's atexit handlers. The other 78 were the cascade: 44 merged -> wrapped ("code differs
from its standalone build", "lost its match in the tree", new conflicts) and some isolations. The proof itself passed:
strict link rc 0, Wine unbound 1,319, the x87 keep list identical, and the checkpoints identical at all 2,009 common
frames. The fix is left out of this batch because these mode changes are not removals of invented-name conflicts.
Taking it is a decision for the user.

**Taken (dec1, 2026-11-07, user-approved).** The fix is in `tools/gen_tree.py`. A fresh build on the control's host,
with and without it on the same sources (HEAD 3234e788e plus dec1's B2 batch, mac2, fresh state, full map, `--gfx`,
play3 to 60000): control 65100, proof 65216. Both strict-link rc 0 with 1,314 Wine-unbound names (identical lists),
the x87 keep list is identical, and the checkpoints are identical at all 2,016 common frames (to 60450). Trees made
from the two proofs' own build_tree states differ in **365 merge modes**:
- 312 C2732 wraps are gone (311 wrapped -> merged, 1 isolated -> merged): the C definitions whose callers' shared
  declarations had been forced to `extern "C++"` (equivalent/ 0x0026..., 0x0021..., 0x002d..., 0x0022...; matches/
  0x0036... the init TU's atexit handlers).
- 53 are the cascade of the fresh convergence: 45 merged -> wrapped (24 "code differs from its standalone build",
  7 "lost its match in the tree", 6 conflicts on a stub type: `physics::CollisionVolume` x3, `CollisionOBB`, `Stream`,
  `Result`, and 6 with no reason recorded), 4 other wrapped -> merged, 2 merged -> isolated, 2 isolated -> merged.
- The 64-bit front end over the 78 TUs holding the 365 sources: 0 errors before and after.
The port onto build2's faster gen_tree (feb1354fc) generates a byte-identical tree to the proven version (same
sources and state). Lists: `build/dec1/realmodes-a.txt` (local).

### Addresses written as integers

0x0035d720's `push 0x400488` was an integer literal in the source: the same bytes as the original, but no
relocation, so the 64-bit build passes a 32-bit address. Neither compare.py (it masks relocations, and the XBE has none
to compare) nor verify_relocs.py (it checks the relocations the object has) can see a missing one. A scan of the
sources' code for hexadecimal literals in the data range (`build/unb4/scripts/addrlit.py`, less FourCC codes) finds 40
more, almost all `__RTDynamicCast` calls (0x00344e74) that pass the source and target type descriptors as integers
(`FUN_00344e74(a, 0, 0x491ca8, 0x492108, 0)`): 0x00050680, 0x0006d590, 0x001110e0, 0x001fb140, ... (list in
`build/unb4/addrlit-all.txt`). They need `&DAT_<descriptor>`. A checker could flag an operand of our object that equals
an address of a data item and carries no relocation; that would tighten verify_relocs, not relax it.

(adr1) That check now exists: `address_as_integer`, in `verify_relocs.check` (a byte match: the original's
instruction at the same offset) and in equiv.py's level 2 (an address the original function references that our
object has only as a plain immediate). `tools/addr_literal.py` decides from the original instruction what is an address
(the XBE has no relocation table; rules in docs/equivalence.md round 28); `RELOC_OFF=addrlit` / `EQUIV_OFF=addrlit` turn
it off. The sweep over HEAD 77b9475d2 (`verify_relocs.py --addrlits`, 12 queue shards) found 44 matches/ and 1
equivalent/ source. 41 matches/ were real and are fixed: the 34 RTTI casts, 0x001a1880, 0x000dd8b0 (a table of index
pairs, spelled as its sibling 0x000dd8d0), 0x0014e220 (the HealthTrack vftable stored by number), 0x001922e0 (pi/180
by address: now the float literal), 0x00278060 (XPP's gamepad type), and 0x00321b70 / 0x00321c30, which stored D3D
render-state cache words through `*(int*)0x39de28`. The other 4 (0x0028f280, 0x00297150, 0x002c1480 and
equivalent/0x00291dc0: the sizes 0x11000, 0x13000, 0x120100 passed to the loader registry, which are also function
starts) were constants, and function starts are no longer taken as immediates. A Wine proof of the batch on the
control's host had no merge-mode changes and identical checkpoints.

### Batch and proof

| | control | batch (unb4) |
|---|---|---|
| sources | HEAD f6f05de96 | 37: 36 matches/, 1 equivalent/ (0x0008d480) |
| gates | - | 36 / 36 MATCH + verify_relocs ok (with name_address_mismatch); 0x0008d480 3,020 inputs equivalent (complete coverage), `--wine` 620 equivalent |
| `--x64` (HEAD -> batch) | - | 15 -> 35 equivalent of 37; none newly failing (the 2 failing are HEAD's: 0x00267280 layout, 0x0026d8f0 ptrtrunc) |
| 64-bit front end | the 4 TUs: 0 errors | 0 errors |
| merge modes (the proofs' own build_tree states) | - | 24, all wrapped -> merged: 22 batch sources (their conflicts were invented names or hasher declarations that now agree), and 0x00363800 / 0x00363d10, not in the batch, whose conflicts with batch sources' invented names (`Entry`, `items`) are gone |
| Wine proof (`--gfx`, play3 to 60,000, limit 14,400; both on one host) | 63216 | 63234 |
| strict link rc / Wine unbound | 0 / 1,321 | 0 / **1,319**. Gone: `gInput` and `gResult`, two invented names that 0x0035f170 and 0x0035f1b0 shared in the init TU's namespace for different addresses (ambiguous) |
| x87 keep list | 268 | identical |
| play3 checkpoints | 2,012 to 60,330 | identical at all 2,008 common frames (batch to 60,210) |
| arm64 macOS unbound / ld64 | 32,005 / rc 0 | **31,958** / rc 0 |
| x86-64 Linux unbound / lld | 31,996 / rc 0 | **31,949** / rc 0 |
| arm64 Android unbound / lld | 31,997 / rc 0 | **31,950** / rc 0 |
| macOS start-up | stops in 67 (`init@16`) | runs 0-215, stops in **216** (the registry table, layout) |
| static reach (stubs reachable from initializers by direct calls) | 98 | 76 |

### What is left

(216's table: fixed by reg1, "Start-up past the allocator registry" below; the next stop is the dl allocator.)

| initializers | what | class |
|---|---|---|
| **216** | the loader registry table 0x00527c58 (55 sources, data_gen `.bss` records) | layout |
| 216, after it | 0x0026cfa0 / 0x0026cf20 (the dl allocator): `MemoryDlAllocator_nv_26cfa0::Do`, `lookup`, `run` | invented names |
| 2 | 0x00247610 `Tmp_247610::init` / `cleanup` | invented member names (unb3's list) |
| 284, 290, 313-317, 329, 332, 340-346, 354-375 (about 25) | a derived type's constructor calls its base constructor (om::Type 0x00243310 / 0x0025e6c0, audio::SeqEventType 0x002605e0, ...) of a stub class, with invented names for the name temporary (`Temp::Init` = 0x0023fc40, `~Temp` = 0x00240060) and the hasher (`lookup`, `GetId`, `MakeId`). Recipe: a class named by the constructor's address (`struct FUN_002605e0`, the "class named fun" rule of native_unbound.name_address, 89 sources use it) for the base and for the temporary (`FUN_00240060`, whose destructor is 0x00240060), the hasher by address. 0x00243310's own definition takes the two key pointers as `int` (B, definition side). The derived classes' own vftables (verify_relocs' `vftable_of_other_class`) are a further native gap | D6 + B |
| 308-312 | `MetaType::FUN_0025fa00` stores the name pointer in an `int` key and lays out the tree node with 32-bit offsets; 0x0025f170 (Register, an incomplete equivalent) reads the same node with pointers | layout |
| 331, 333, 335, 338, 383 | `FUN_002672f0` declared with a `hulk_intptr` third parameter: the reference's IR signature (an `i64` argument) is not the definition's (`i32`), so native_unbound's plan does not bind it | signature (decls/address.h's `int`) |
| 348 | `FUN_002673a0` | signature |
| 456, 457 | `Obj::FUN_00337d20` | invented class |

The native numbers come from each proof's own clang-probe snapshot and binding map (the lineage's
`build/clang-probe/snap` and `build/native/bindings.json`), compiled as queue jobs and linked locally
(`build/unb4/scripts/natproof.sh`). The Linux and Android figures are a2s2's key (`unbound (undefined less the native
CRT and XDK tables' rows)`); `tools/native_unbound.py classify` gives the same macOS totals. Every link has 0 CRT
binding problems. tests/native_host all pass: crt_bind, xdk_bind and shim (3 targets each), replay_native, va_tree
(macOS and x64), rtti, entry, native_unbound_test 4 / 4.

## Start-up past the allocator registry (reg1, 2026-11-05)

unb4 stopped in initializer 216 (0x0035e6b0) on the table at 0x00527c58. The macOS start-up now gets through the
allocator registry and the malloc allocator of 216 and stops in the same initializer on the next layout: the dl
allocator (`MemoryDlAllocator`).

### The table was two variables

0x00527c58 was carved as one 744-byte item because sources wrote `(char*)&DAT_00527c58 + 8` for the slots; the code
says otherwise. 0x00527c58 is the content loader registry pointer (46 sources read it; +4 is unused), and the
"records from +8" are the **memory allocator registry** at 0x00527c60 (the code addresses 0x00527c60 directly): 46
slots, and a 47th of the same record at 0x00527f40, the root of a tree of allocators, which the inventory had split
into four 4-byte items because 0x00267280 stores its words by address. Read together, the accessors give one record,
`MemoryHeapSlot {allocator; child; next; parent;}`: 0x002670b0 links an allocator in as the first child of a slot (of
the root for 45 or a slot without a parent), 0x00267110 unlinks it, 0x00266f50 / 0x00266f90 walk `{item, child,
next}` from the root to find the allocator that owns an address, 0x00267280 points every slot at the static malloc
allocator 0x00527f50 (vftable 0x0042af2c).

- **Inventory** (config/data.json): 0x00527c58 744 -> 8 bytes; 0x00527c60 a new 736-byte `.bss` item (owner
  unknown/unk_266950.cpp, shared by 3 objects, as data_inventory's link-order rule places it); 0x00527f40 4 -> 16
  bytes (0x00527f44 / 48 / 4c become its interior). These are the items data_inventory itself carves once the sources
  use `DAT_00527c60[i]` and the root's fields (its source-offset merge); the coverage counts are adjusted (bss items
  2,500, `refs` 10,425, `shared` 2,038).
- **One record type**: `include/decls/data/records.h` (hand-written) defines `MemoryHeapSlot` and declares
  `DAT_00527c60[46]` and `DAT_00527f40`; data_gen defines the items with that declaration (docs/data.md "Typed
  records"). On 64-bit the slot is 32 bytes, so the table is 1,472 bytes; the 32-bit size is the XBE's (asserted).
- **The sources** (all byte-matched, verify_relocs ok): 0x00266e00, 0x00266eb0, 0x00266f00, 0x00266f20, 0x00266f40,
  0x002670b0, 0x00267280, 0x00267070, 0x00267090 and the equivalent 0x00267110 (3,009 inputs equivalent, `--wine`
  73 equivalent; 7 / 8 edges as before). Pointer-width fixes on the way: the allocate calls return `void*` (they were
  `int`: the allocation truncated), 0x00266f00 / 0x00266f20 pass the freed pointer as `void*`, 0x00266f40 returns
  the allocator pointer (it returned `int`), 0x00267280 loops `46 * sizeof(MemoryHeapSlot)` (it stepped 16 bytes to
  0x2e0), 0x00266e00's invented `gCallback_266e00` is 0x00527f64 (as 0x00266eb0 names it).

### The malloc allocator (0x00527f50)

Slot 0's allocator is the static `core::MemoryAllocatorMalloc`; 216's first allocation (`FUN_00266e00(0, 0x20800)`)
calls its slot 3.

- 0x00267210 (slot 3, allocate) was a propagated `int __stdcall FUN_00267210(int)`: on 64-bit the vtable call passes
  `this` first, so it allocated `this` bytes, and returned the pointer as `int`. Now a member returning `void*`.
- 0x00267230 (slot 6, aligned allocate) returned `void` (the pointer only survived in eax on x86): returns it.
- 0x00270570 / 0x002705b0 (aligned malloc / free) kept the block in a 4-byte word below the aligned address: now a
  pointer-sized word (`sizeof(void*)`; the 32-bit code is the same).
- 0x00267220 / 0x00267250 (slots 4 and 7, free) called an invented `thunk`: now `thunk_FUN_003479bc` (0x00270560, the
  thunk to free; it has no tree definition, but the native CRT table binds the name by the address in it: reg2) and
  `FUN_002705b0`.
- 0x0026d8f0 (the thread list append; unb4's survey crash) links `{next, previous}` as pointers. Its callers'
  thread objects keep 8 bytes for the two links (`char reserved[8]`), a layout still to fix.

### Where it stops now

Normal run: `missing ?Do@MemoryDlAllocator_nv_26cfa0@...` from `FUN_0026cfa0+0x58` in 216: 0x0008d480 creates the
"Temporary Heap" (and 0x0008d3a0 fifteen more heaps) with the dl allocator, whose constructor 0x0026ce90 0x0026cfa0
calls under an invented name. Naming it is not enough: the native link binds a name by address only when the
reference's IR signature equals the definition's, and the definition (`MemoryDlAllocator(unsigned char, int base,
int count, int unused)`) takes the heap's base pointer and name as `int`. The class keeps `start` / `end` /
`current` as `int` and a 0x474-byte state block that dlmalloc (0x0026c040 and the family, about 22 sources,
`gen/core.h`'s `core::MemoryDlAllocator`) uses with 32-bit chunk constants (8-byte headers, 16-byte minimum chunks
with two pointers in them). That is the next layout job: the dl allocator family on 64-bit.

Survey run (`HULK_NATIVE_MISSING=continue`): the skipped constructor returns 0, and 0x002670b0 crashes installing it.

### Method

As unb4, with unb4's final proof as the base (build_tree state and report from its clang-probe snapshot, its binding
map), the data TUs from this change (`HULK_DATA_DIR`), and the tree report's symbols of the renamed definitions patched
for the iteration links (`build/reg1/scripts/`). Merge modes (that state): one change, 0x00267230 wrapped -> merged
(its conflict on the invented `MemoryAllocatorMalloc` is gone). 64-bit front end of the 5 TUs: 0 errors.
`--x64` HEAD -> batch, 17 sources: the same statuses (7 equivalent, 4 unsupported, 6 failing: 0x00266f40, 0x002670b0,
0x00267110, 0x00267280 on the indexed table's 64-bit stride, which the harness does not map; 0x00270570's header
word, 8 bytes by design; 0x0026d8f0's declared `unsigned int*`).

### Batch and proof

| | control | batch (reg1) |
|---|---|---|
| sources | HEAD 77b9475d2 | 17 (16 matches/, 1 equivalent/: 0x00267110) + records.h, the 2 regenerated data headers, config/data.json, tools/data_gen.py |
| gates | - | 16 / 16 MATCH + verify_relocs ok; 0x00267110 3,009 inputs equivalent, `--wine` 73 equivalent |
| data_gen (MSVC 7.1) | 18,832 / 18,832 items | 18,830 / 18,830 items verified (two items fewer: 0x00527c58's split adds one, the root's merge removes three), 1,078 TUs |
| merge modes (the proofs' own build_tree states) | - | 1: 0x00267230 wrapped -> merged |
| Wine proof (`--gfx`, play3 to 60,000, limit 14,400; both on mac2) | 63381 | 63414 |
| strict link rc / Wine unbound | 0 / 1,319 | 0 / **1,318** (gone: the invented `thunk` that 0x00267220 and 0x00267250 shared for two addresses) |
| x87 keep list | 268 | identical |
| play3 checkpoints | 2,013 to 60,360 | identical at all 2,005 common frames (batch to 60,120) |
| arm64 macOS / x86-64 Linux / arm64 Android unbound (proof 64998's own snapshot and map) | 31,958 / 31,949 / 31,950 (unb4) | 31,957 / 31,948 / 31,949, all rc 0 |
| macOS start-up | 216: the registry table | 216: the dl allocator's constructor (`FUN_0026cfa0+0x58`) |

Both proofs build their data TUs from a private `HULK_DATA_DIR` (`--data-src`): the control from HEAD's inventory
(identical to the shared build/data/src), the batch from this one.

## Definition names by address (dec1, 2026-11-05)

unb3's sweep checked the names a source *references*; this one checks the name a source *defines*. A propagated
source ("Same code shape as 0x00025410 (propagated; names are from that function)") kept the definition name of the
function it was copied from, so 91 sources defined `FUN_00025410` (an empty function), 9 `FUN_00086320`, and so on.
In the tree each such block was either wrapped ("same definition as 0x... in this TU") or bound under a name that
belongs to another address.

**Which sources.** A definition scan (`FUN_<x>(...) {` with x not the file's address) finds 163 sources. compare.py's
matching symbol says which definition is the function itself:
- 128 matches/ sources: the matched symbol is the foreign `FUN_<x>`. Renamed to `FUN_<own address>` (one
  occurrence each; comments untouched). 3 of them are skipped: 0x00267050, 0x002671a0 and 0x002671b0 sit in the
  allocator registry's range that reg1 is changing. **125 renamed.**
- 7 matches/ and 5 equivalent/ sources define their own `FUN_<own>` plus a helper body named for the callee it is
  (0x00234cc0, 0x00234960, ...): correct, left.
- 4 matches/ (0x001312d0, 0x0028b9c0, 0x0035d7d0, 0x0035ead0) define themselves under a non-FUN_ name (`target`,
  a constructor, `Init`, `RegF`), and the FUN_ hits are callee helpers: left.
- The other equivalent/ hits were base-class constructor calls in initializer lists (`: FUN_000e9240(arg)`), not
  definitions.

**Gates.** All 125: compare.py MATCH and verify_relocs ok. MSVC's code is unchanged (only the symbol). A tree made
with one build_tree state (63234's) for HEAD and for HEAD + this batch: 37 merge-mode changes, all wrapped ->
merged and all batch sources (the "same definition as ..." wraps are gone); the 64-bit front end over the 76 TUs
holding them: 0 errors, as HEAD.

**The replay pin 0x000964d0** (user-approved one-time edit): its `DAT_004dd6e4` became `(*(int*)&DAT_004e5acc)`, the
seq-rng pointer the code reads. Byte-identical, verify_relocs ok (was `name_address_mismatch`). Nothing else changed,
so it still returns the pointer as `int`: `--x64` now fails `ptrtrunc` (HEAD's version read a different item and
passed); a `hulk_intptr` return would fix it and needs the pin's owner.

**Wine proof** (B, C and D together, mac2, fresh state and full map, `--gfx`, play3 to 60000): control 63437
(77b9475d2) and proof 63958 both strict-link rc 0 with 1,319 Wine-unbound names (identical lists), the x87 keep list
is identical, and the checkpoints are identical at all 2,002 common frames (to 60030). Trees from the two proofs'
own build_tree states: the same 37 wrapped -> merged changes, nothing else.

## Start-up past 216: the dl allocator, the heap set and the fiber scheduler (reg2, 2026-11-05)

reg1 stopped in initializer 216 on the dl allocator's constructor. The macOS start-up now runs initializers 0-259 and
stops in **260** (0x0035efb0) on a data item that holds a string's address as an integer.

### The dl allocator, 64-bit clean in source

`core::MemoryDlAllocator` (0x0026b910-0x0026cfa0, 28 functions) is the game's dlmalloc-style heap: the object (0x4a4
bytes on 32-bit) has the arena (start, end, size, break at +0x0c..+0x18), a 0x474-byte heap state at +0x1c, and the
statistics. The family is now one code path for both widths:

- **One record type.** `include/decls/data/records.h` defines `DlHeapChunk` (the chunk header: two pointer-sized
  words, then the bin links) and `DlHeapState` (285 pointer-sized words: the fast-bin limit and flags, 10 fast bins,
  top, last remainder, 256 bin links, a 4-word bin map that uses 32 bits per word, and 12 parameters and counters).
  On 32-bit that is the XBE's layout (8-byte headers, 16-byte minimum chunks, 8-byte alignment, 0x474 bytes); on 64-bit
  it scales (16-byte headers and alignment, 32-byte minimum chunks, 2,280 bytes). The chunk constants are
  `DlHeapChunk::kWord`, `kHeader`, `kAlign`, `kAlignMask`, `kMinSize`, all from `sizeof(hulk_uintptr)`; the
  request rounding (`n + kWord + kAlignMask`, at least `kMinSize`), the maximum request (`-2 * kMinSize`), the bin step
  (two words), the fence words sysmalloc leaves at the old top (`kWord | 1`) follow from them. The bin indices
  (`size >> 3` below 0x200, the large-bin shifts) and the fast-bin index stay as they are: they are byte counts, not
  layout. The game sets no fast-bin size (the limit is 8, below the minimum chunk), so the fast bins stay empty.
- **The heap globals.** The methods point the heap functions at an allocator through 0x0052839c (the state), 0x005283a0
  (arena start), 0x005283a4 (size), 0x005283a8 (arena end) and 0x005283ac (the address of the break word). 0x005283a0
  and 0x005283a8 hold addresses: records.h types them `hulk_uintptr` (typed `.bss` items, as reg1's).
- **The object.** include/gen/core.h's `core::MemoryDlAllocator` gets the break as `hulk_intptr f_18`
  (evidence-rn.json `ptr_fields`) and the state as `hulk_uintptr f_1c[0x11d]` (gen_headers.py `CURATED_FIELDS`);
  on 32-bit the class is unchanged. The sources that keep their own view of the object use the same fields.
- **The constructors** 0x0026ce90 (memory the caller owns: 0x0026cfa0, 0x0026cf60) and 0x0026ca80 (an arena from
  another heap: 0x0026cf20) are members named by their address with the vftable stores spelled out
  (`DAT_0042b36c` / `DAT_0042b364`, the labels the native link gives the vftables), so the callers' references bind
  by address and the object gets the game's vftables; the callers allocate `sizeof(core::MemoryDlAllocator)` (0x4a4 on
  32-bit) and take the arena as `void*` and the name as `const char*`. The destructor body 0x0026cc00, slot 11
  (0x0026cbc0, was a propagated fastcall `target`), slot 1 (0x0026cc40, the release) and slot 10 are named and laid out
  on the header.

The alternative, a native-only hook that sends these heaps to the host's malloc, was not needed: the bin arithmetic is
width-independent once the header words are pointer-sized.

### The heap set, the threads, the content loader's fiber

With the allocator constructed, 216 stopped on three more `.bss` objects that the inventory had carved into 4-byte
items or kept at their 32-bit size (each now a typed record in records.h; config/data.json changed to match):

| item | record | was | users |
|---|---|---|---|
| 0x004dd780 (96 B) | `HeapSet`: the size, one allocator per heap id (19, the heap table 0x00400520's rows), the Temporary Heap's arena | `int` + a 92-byte table | 0x0008d480 (builds it), 0x0008d3a0, 0x0035d090, 0x0008ceb0, the five first-allocation entry points 0x0008d660 / d690 / d6d0 / d710 / d750 (invented `init`, `run`, `delay`, `DoThing`... now by address; 0x0008d710 / 0x0008d750 took the size and heap id in each other's widths) |
| 0x0052a130 (76 B) | `CoreThread`: the thread list links, the thread's own `CoreFiber`, the fiber list, the current fiber, id, priority, handle | 16 B + three interior items | 0x0026d990 (the main thread becomes a fiber thread), 0x0026da20, 0x0026da80, 0x0026dad0, 0x0026db70, 0x0026dbb0, 0x0026dbf0 (returned the current fiber as `int`), 0x0026dc00, 0x0026dc20, 0x0026dc50, 0x0026dd10, 0x0026dd70, 0x0026d7a0 |
| 0x00527c28 (36 B) | `CoreFiber`: the content loader's fiber | the tail of the 40,460-byte item 0x0051de40 | 0x00264d20 (the loader's yield: `GetId`, `Use`, `Conv` were 0x0026dbf0, 0x0026dc00, 0x00266da0), 0x002656b0, 0x00265bf0, 0x00265c40; 0x00527c4c (the game's fiber) and 0x00527c50 / 0x00527c54 (each side's heap) hold pointers: `hulk_uintptr` |

The fiber's argument is pointer-sized (the content loader passes its object). The main thread's handle is -2, the
current-thread pseudo handle: the host layer took it for an object (`hulk_host_SetThreadPriority` crashed reading it);
`as()` in src/platform/sdl/host/win32_posix.cpp now rejects the pseudo handles.

Merged definitions of C functions whose TU-mates declare them `extern "C"` meet gen_tree's linkage bug (unb4, "A
gen_tree bug"): with the invented names gone, 0x0026d990, 0x0026dc50 and the others now merge, and their declarations of
0x0026d8f0 / 0x0026d940 / 0x0026d990 / 0x0026db70 would get C++ linkage. Those calls use class-scope declarations
(`ThreadList_26d990::FUN_0026d8f0`), bound by the address in the name like any other.

### On the way: 229 and the hasher callers

- 0x0027afb0 (a name's hash key, 229's callee) took the name as `hulk_intptr` and passed it on as `int`: now
  `const char*` with decls/address.h's 0x002672f0. 0x00023d30 and 0x00106230 still pass it an `int` (not on the path).
- unb4's 331, 333, 335, 338, 383: 0x0035fe60, 0x0035ff30, 0x00360000, 0x003600f0, 0x003611d0 declared 0x002672f0 with a
  `hulk_intptr` third parameter (the IR signature the native link compares): now decls/address.h's.
- reg1's thunk 0x00270560 (`thunk_FUN_003479bc`) was not a gap: the native CRT table binds the name by the address in it
  (0x003479bc, free) on all three targets, and the Wine link binds it too.

### Where it stops now

`crash ... FUN_002672f0+0x34 phase=init 260 0x0035efb0`: 0x0035efb0 hashes the name `*(const char**)&DAT_004ca248`, an
item the inventory has as `scalar int` (source type `const char*`) that holds 0x00427834, a string's address, so the
native data has the number. The same class as unb4's 0x004ca298 / 0x004ca29c (the data inventory's pointer evidence,
dec1's change): 0x0049ed3c, 0x004a06a4, 0x004c5cf8, 0x004ca248, 0x004ca254, 0x004ca298, 0x004ca29c. Changing their
kind in data.json alone does not make them pointers (data_gen takes the pointer words from the inventory's evidence).

Next, seen statically:
- 284, 290, 313-375: the derived om types' constructors call their base constructors (0x00243310, 0x0025e6c0, ...)
  under invented names, and those definitions take the two key references as `int` (unb4's recipe: classes named by
  the constructor's address).
- 308-312: `om::MetaType` (0x0025fa00) takes its name as `int`, lays out its node with 32-bit offsets, and registers in
  a red-black tree whose root, sentinel and count (0x004e79b8-0x004e79cc) are six 4-byte items; 0x0025f170 (insert) reads
  the node through pointers.
- Static objects of classes with pointers that the inventory keeps as raw `.bss` byte arrays of their 32-bit size (the
  om type objects at 0x004e6394, 0x004e63c8, 0x004e63fc, ..., 52-108 bytes) overflow into their neighbours on 64-bit.
  A typed record for each is one way; a general one would be data_gen giving untyped `.bss` arrays headroom on the
  64-bit builds (twice the size: 32-bit unchanged). A data-step decision.

### Method, batch and proof

As reg1 (scripts in build/reg2/scripts/), with reg1's proof as the base (its build_tree state, report and binding map),
the data TUs from this change (`HULK_DATA_DIR`), and the iteration reports' symbols of the changed definitions taken
from the tree TUs compiled with MSVC (`treesym_patch.py`).

| | control | batch (reg2) |
|---|---|---|
| sources | HEAD d05b666ea | 54 (32 matches/, 22 equivalent/) + records.h, 5 regenerated data headers, include/gen/core.h, evidence-rn.json, gen_headers.py, config/data.json, src/platform/sdl/host/win32_posix.cpp |
| gates | - | 32 / 32 matches MATCH + verify_relocs ok (HEAD's verify_relocs with address_as_integer); 22 equivalents equivalent at 3,000 inputs (complete coverage except 0x0026be70 30/34, 0x0026c040 93/94, 0x0026c6a0 25/26, as before) and `--wine` equivalent |
| `--x64` (HEAD -> batch, HEAD's tools, 60 sources) | - | 39 equivalent -> equivalent, 8 fail -> fail, 2 unsupported; 5 better (0x0026b970 inconclusive, 0x0026cbb0, 0x0026cc40, 0x0026da20, 0x0026d7a0 fail -> equivalent); 6 equivalent -> fail by design: the 64-bit object is the 64-bit layout (0x0026c6a0 / 0x0026c840 request sizes from the 16-byte alignment, 0x0026cd90 / 0x0026ce10 / 0x0026ce90 pointer-sized arena words, 0x0026cfa0 `sizeof` 2,360) |
| merge modes (the proofs' own build_tree states) | - | 13, all wrapped -> merged: 12 batch sources (their conflicts were invented names or local records) and 0x0026d940 (not in the batch: its `Node` conflict is gone); 64-bit front end 0 errors |
| Wine proof (`--gfx`, play3 to 60,000, limit 14,400; both on mac2) | 64085 | 64041 |
| strict link rc / Wine unbound | 0 / 1,318 | 0 / **1,314** |
| x87 keep list | 268 | identical |
| play3 checkpoints | 2,006 to 60,150 | identical at all 2,006 common frames (batch to 60,420) |
| arm64 macOS / x86-64 Linux / arm64 Android unbound (proof 64998's own snapshot and map) | 31,957 / 31,948 / 31,949 (reg1) | **31,928 / 31,919 / 31,920**, all rc 0 |
| macOS start-up | 216: the dl allocator's constructor | runs 0-259, stops in **260** (0x0035efb0, `DAT_004ca248`) |

Both proofs build their data TUs from a private `HULK_DATA_DIR` (`--data-src`). The shared build/data/src was stale
(2026-10-26, before reg1's inventory change: a 4-byte `DAT_00527f40` that no longer matched config/data.json, so a
fresh-HEAD Wine link of it failed on `_DAT_00527f40`); it is now regenerated from HEAD 50dd6fb59.

## Start-up past 260: the om type constructors and the type trees (reg3, 2026-11-06)

reg2 stopped in initializer 260 on `DAT_004ca248`, a name pointer the inventory typed `int` (dec1's change, taken here
only as a private data tweak for the survey runs). Past it, the macOS start-up now runs **every initializer** (0-465;
the normal run prints `initializers done`), enters the game's main and stops in **0x0026f070**, the platform set-up
main calls first.

### The stops

Each iteration as reg2 (scripts `build/reg3/scripts/`), with reg2's proof as the base and the private data step
(`dgen.sh`: HEAD's inventory plus this change, plus dec1's five pointer words for the survey only).

| initializers | stop | class | fix |
|---|---|---|---|
| 284-317 | the om type constructors: a derived type calls its base constructor under an invented name (`EntityType_242010`, `Base`, `MetaEntityType_24d7d0`, `ListenerEffectGcBase`, ...), the hasher as `lookup` / `findThing` / `getid`; om::EntityType's constructor (0x00243310) and om::MetaEntityType's (0x0025e6c0) took the two type keys as `int` | invented names (D6) + B | the bases are classes named by their constructor's address (`class FUN_00243310`, `FUN_0025e6c0`, `FUN_002584d0` for om::Type), the hasher decls/address.h's; 0x00243310 / 0x0025e6c0 take the keys by address (`const unsigned __int64*`, the callers' references: the same IR), and the leaf types pass `&(const U64&)hash` |
| (all) | the native link never bound a constructor or destructor of a class named by address (`??0FUN_00243310@...`: "special member of a class named by address"), so unb4's recipe could not work | link | `native_unbound.plan_link` binds them like a `FUN_` name, under the same checks (the Wine binding map's address, the IR signature): a destructor of a class named by its constructor is bound by the Wine link elsewhere, and the map vetoes it. tests/native_host/native_unbound_test.py has the case. 142 such names were left unbound in the first iteration's link |
| 308-312 | `om::MetaType` (0x0025fa00) stored its name in an `int` key and laid its tree out with 32-bit offsets; the tree of meta types (0x004e79b8) was six 4-byte items; the five static meta types were raw `.bss` arrays (two inside one 108-byte item and one inside 0x004e635c) | layout | records.h: `OmTreeNode`, `OmTree` (root, sentinel, count) and `OmMetaType` (vftable, its node, a tree of its own, the name, flags); `DAT_004e79b8` is one 24-byte `OmTree`, the meta types `DAT_004e6360` / `6394` / `63c8` / `63fc` / `6430` are `OmMetaType` (0x004e635c 56 -> 4 bytes, 0x004e63fc 108 -> 52 + `DAT_004e6430` + the unreferenced word 0x004e6464). 0x0025fa00 / 0x0025fa80 / 0x0025fc30 / 0x0025f170 (insert) and the initializers, accessors and exit handlers by the records |
| 326-337 | the sequence event types (audio::SeqEventType, 0x002605e0): the same invented bases and name temporaries (`Temp::Init` = 0x0023fc40, `~Temp` = 0x00240060); 0x0023fc40's option was `hulk_intptr` (owner_classes reconciled it for one caller's pointer), so the 67 `int` callers could not bind; 0x00240170 called `Helper` (0x00240090); 0x0035ff90 read a constructor's result as `int` | D6 + B | the temporary is `class FUN_00240060` with `FUN_0023fc40`, the base `FUN_002605e0`; 0x0023fc40 takes `int` (include/gen/evidence-owners.json, owners.h regenerated); 0x00240170 calls `FUN_00240090` |
| 329 | the tree of sequence event types: 0x002605e0 put the node after om::Type's 0x44 bytes (0x50 on 64-bit), 0x002601d0 / 0x002603e0 / 0x0025fca0 / 0x00260680 / 0x00260950 used 0x48 / 0x58; the tree (0x004e7a18, 20 bytes) and its count (the first word of 0x004e7a2c) were separate items | layout | records.h: `OmString` and `SeqEventTypeHead` (vftable, om::Type's bytes, the node, the name); `DAT_004e7a18` is an `OmTree`, 0x004e7a2c's two om::Type objects are `DAT_004e7a30` / `DAT_004e7a78`. The users of the tree go by the record (`entry_of`), the three C functions of the TU that merged sources call are declared at class scope (gen_tree's linkage bug, reg2) |
| 340-375, 390 | the other sequence event types (13 constructors), 0x00256c20 (`EntityType_256c20`), 0x003604b0 (0x002673a0 returns an `int`), 0x00361510 (`AtExit`) | D6 + B | as above |
| 456, 457 | 0x00337d20 took its buffer as `int` | B | `void*`, the buffer pointers `char*` |
| main | `hulk_game_main` was a reporting stub on the native links | link | native_mac / native_elf: a thunk to the tree's definition at 0x0008ee30 (wine_host.MAIN_ADDR), as the Wine link aliases it |
| **main, 0x0026f070** | `InitPlatform` (invented) and `XAPILIB::XInitDevices` (an XDK call in an invented namespace, not the XDK table's name) | invented names | next |

Also: 0x00023d30 and 0x00106230 pass the name to 0x0027afb0 as `const char*` (reg2's leftovers; 0x00106230's callers
0x00175060, 0x00106440 and 0x001df400 still declare an `int` key).

**Survey run** (`HULK_NATIVE_MISSING=continue`): main goes on to `thunk_FUN_002709b0` / `thunk_FUN_00270f10` (Ghidra
thunk names carry no address), `Obj_265b70::Init`, and crashes in 0x0008fca0 on a skipped `thunk_FUN_002710d0` (a file
open). The exit handlers (`atexit`) are mostly invented names (`f`, `Run`, `Cleanup`, `wrapper`) and only run at exit.

### Static objects in .bss

The om type objects (about 60 initializers construct one: om::Type 72 bytes, the effect and sequence event types
104-280) are `.bss` byte arrays of their 32-bit size, several carved into one item (`(char*)&DAT_004e5cf8 + 112`). On
64-bit each has a pointer-sized vftable and tree links, so it is larger and the next object's constructor writes over
its tail. The start-up gets through all initializers without more room (no constructor reads a neighbour's tail before
main), but the objects are corrupt. Typed records were given here only where the start-up needed them (the meta types
and the sequence event tree).

The general fallback, measured (not implemented: a data-step policy change): `.bss` items of 8 bytes or more that code
takes the address of (`mov` / `push` / `lea` of the address: static objects and buffers) or that config/data-ptrs.json
has pointer evidence for, and that records.h does not type: **390 items, 502,838 bytes** of 604,404 `.bss` bytes; 379
of them are 4 KB or less (52,158 bytes). Defining those twice as large on the 64-bit builds costs about 0.5 MB and stops
the overflow; it does not fix objects packed into one item, whose 64-bit offsets are still the 32-bit ones. A private
run with every untyped `.bss` array of 8+ bytes doubled (`build/reg3/scripts/headroom.py`, a patch of data_gen's
definitions only, headers unchanged) ran every initializer in survey mode, as the run without it did.

### Method, batch and proof

As reg2, with reg2's proof as the base (its build_tree state, report and binding map) and the iteration reports'
symbols of the changed definitions from the tree TUs compiled with MSVC. Iterations x0-x4 (`build/reg3/`): x0 HEAD (260
passes with dec1's words, stops in 284), x1 the om constructors and meta types (stops in 329), x2-x3 the sequence event
tree and types, x4 everything without the private `.bss` headroom (all initializers, then main).

| | control | batch (reg3) |
|---|---|---|
| sources | HEAD a42c96d86 | 62 (54 matches/, 8 equivalent/) + records.h, 3 regenerated data headers, config/data.json, include/gen/evidence-owners.json + owners.h, tools/native_unbound.py (+ test), tools/native_mac.py, tools/native_elf.py |
| gates | - | 54 / 54 MATCH + verify_relocs ok (address_as_integer on); 8 equivalents equivalent at 3,000 inputs and `--wine` (0x0023fc40 2,999, 0x0024df00 2,918, 0x0025f170 822 (54/56 edges, as before incomplete), 0x002601d0 3,126 (now complete), 0x002603e0 2,947, 0x002605e0 2,995, 0x00261d10 3,015, 0x00251170 2,971) |
| `--x64` (HEAD -> batch, 124 sources: the batch and the gen classes' users) | - | 81 equivalent -> equivalent, 23 unsupported, 12 fail -> fail; 7 better (0x00242010, 0x0024d7d0 unsupported -> equivalent; 0x0024d8e0, 0x0024d9e0, 0x0024dae0, 0x0025fa00, 0x003604b0 fail -> equivalent); 1 equivalent -> fail by design: 0x00260950 releases the name at the record's 64-bit offset (0x70; HEAD's view 0x5c) |
| merge modes (one build_tree state, HEAD vs batch) | - | 4, all wrapped -> merged: 0x0025f170, 0x002601d0, 0x002603e0 (their `Node` conflicts are gone), 0x003604b0 (its `void*` 0x002673a0); 64-bit front end of the 33 TUs: 0 errors. The proofs' own build_tree states: the same wrap / isolate sets |
| Wine proof (`--gfx`, play3 to 60,000, limit 14,400; both on mac2) | 64239 | 64283 |
| strict link rc / Wine unbound | 0 / 1,314 | 0 / 1,314 (identical lists) |
| x87 keep list | 268 | identical |
| play3 checkpoints | 2,006 to 60,150 | `ckpt_gate.py`: ok at all 2,002 common frames (to 60,030; the known transients only), PRNG hashes identical |
| arm64 macOS / x86-64 Linux / arm64 Android unbound (proof 64998's own snapshot and map) | 31,928 / 31,919 / 31,920 (reg2) | **31,741 / 31,732 / 31,733**, all rc 0 |
| macOS start-up | 260 (`DAT_004ca248`) | 260 until dec1's pointer words land; with them (x4): every initializer, then main to 0x0026f070 |

The proof's inventory also carried dec1's six `kind: pointer` lines (they were in the working copy it was taken
from); the committed inventory is HEAD's plus this change only. data_gen output from the two differs in those six
items' declarations only (`unsigned int X[1]` / `int X`, the same bytes).

## The static om types as records, and main's platform set-up (reg4, 2026-11-06)

reg3 ran every initializer but left the static om type objects as raw 32-bit-sized `.bss` arrays (several packed into
one item), and main stopped in its platform set-up. Both are done here (the user's decision of 2026-11-06: typed
records per object, no general `.bss` headroom).

### om::Type as one record

om::Type (0x002584d0) is 0x48 bytes: the vftable, a word nobody reads, its node in the red-black tree of types by key
(0x004cd1a8: om::Type::vfunc_0 0x002588d0 inserts with 0x00258530, vfunc_1 0x002588f0 removes with 0x00258730,
0x00258950 finds with 0x00258870), 16 unreferenced bytes, the data kind's key (+0x28), the type's own key (+0x30, the
tree's key), an instance's size and alignment (+0x38 / +0x3c, which the om allocator's slot 0x002474c0 allocates), and
8 unreferenced bytes. The sources disagreed: the tree functions found the key at node+0x28 (`char pad[0x18]` after the
links) and the type at node-8, the constructor wrote ints after `int pad[9]`, the sequence event types put their node
after `char data[0x44]`, om::EntityType's own word after `char pad[0x64]`, and the stack temporaries were `char[0x40]`
to `char[0x48]`.

- records.h: `OmKey {lo, hi}`, `OmTypeBody` (node .. reserved words), `OmType {vftable; reserved04; body}` (72),
  `OmEntityType {type; reserved48[8]; flags}` and `SeqEventTypeHead {type; node; name}` rebased on it. The keys are
  word pairs: with an `__int64` member MSVC 7.1 pads the vftable pointer's slot to 8 (0x002584d0's body moved to
  +0x10). The 104- and 112-byte objects are `__declspec(align(8))` (their items keep the 4 bytes after the class).
- The classes that derive from om::Type spell `virtual ...; unsigned int reserved04; OmTypeBody body;`, so they have
  the record's layout on both builds (0x002584d0, 0x00243310, 0x002605e0, 0x0024df00, 0x0024e4c0, 0x00261120); the tree
  functions go by the record (`entry_of` / `KeyOf` from the node's offset), the temporaries are `sizeof(OmType)`.

### The static objects

88 objects (58 `OmType`, 8 `OmEntityType`, 22 `SeqEventTypeHead`) in what were 64 items (initializers 284-396 construct them, the exit handlers 0x00364150-0x00364760 destroy them):
`extern "C" OmType DAT_x[1];` (an array of one: sources pass `DAT_x` as a pointer). 25 items held several objects
(`(char*)&DAT_004e5cf8 + 112`): one item per object now, the three with an id word first (0x002673a0's result, 4
bytes of padding, then the sequence event type), 0x004e7808's second type takes 0x004e7888 (its size and alignment
words, read by 0x0025c0d0 / 0x0025c190) as its interior, and 0x004e7be0's tail (the stream buffers) is
`DAT_004e7c28`. 99 sources name the parts (objs.py), 21 getters that declared a part's name themselves
(`extern "C" int DAT_004e5d68;`) use the record, 0x00245720 the key field. The inventory: 30 more `.bss` items.

data_gen: a generated header that leaves items to records.h now includes records.h, so a source naming them needs
nothing else (docs/data.md "Typed records").

### Main

| stop | what | fix |
|---|---|---|
| 0x0026f070 | `InitPlatform` (invented, 0x002705f0), `XAPILIB::XInitDevices` (the thunk 0x003eba7c to the XDK row 0x003eac33) | `FUN_002705f0` by its definition, `thunk_FUN_003eac33` (the native XDK table binds the name by the row address in it); 0x0026f020 the same. The static core::Platform's vftable is still stored as the invented `platformObject` (a placement-constructed local `core::Platform` was tried: the TU wraps it, and its clang vftable is a stub in the Wine build, one more Wine-unbound name) |
| main's thunk calls | `thunk_FUN_002709b0` / `thunk_FUN_00270f10` reach `jmp` thunks (0x00269680 / 0x00269780); the native link never bound `thunk_FUN_x` | `native_unbound.plan_link`: `thunk_FUN_x` binds to x's definition when the Wine binding map has its relocations reach x or a `jmp` thunk to x (test case added) |
| 0x00273530, 0x00276650, 0x00275d20 | `Init` / `Register` (0x0026d820 / 0x002702a0, a propagated shape) | address names with the definitions' types |
| 0x002702a0 | `MemoryPool_2702a0::Create` (core::MemoryPool's constructor 0x00270170), 0x34 bytes allocated | a stand-in named by the constructor's address with the class's layout, `sizeof` |
| 0x00265b70, 0x002656b0 | `Obj_265b70::Init` (the content loader, 0x3c bytes), its two hash tables (36 bytes, 0x00231550 calls `init`) | the loader's and the tables' layouts, `sizeof`; 0x00231550 `FUN_002310a0`, its slots as pointers |
| 0x0008ee30 | CGame's constructor as `CGame_8ee30::Ctor` (0x00087e80), 0x54 bytes | `FUN_00087e80` with CGame's layout |
| 0x0008fca0 -> 0x002710d0 -> 0x00270f10 / 0x00270c80 -> 0x00277260 -> 0x00278a40 / 0x0026fcf0 | the file open of `args.txt`: the path passed as `int` (0x002710d0, 0x002697c0's two results kept in `int`s, 0x00278a40, 0x0026fcf0), core::File allocated as 0x168 bytes, invented names for the drives' constructors (0x00278500, 0x0026f570) | pointers by the definitions; `FUN_002764d0` with core::File's layout; the constructors by address; 0x00270b70's destination `char*` |
| 0x00272d00 | core::Drive's constructor calls `Hook` (0x002705f0) and `Sub_272d00::Init` (0x00277a40) | address names |

Where main stops now (the iteration links, with dec1's pointer words added privately): after the platform set-up,
the content loader and its fiber, the file system's drive registry, CGame's allocation and the open of `args.txt`
through the save drive, core::Drive's constructor (0x00272d00) stores its vftables as invented data names
(`vt0_272d00`, `vtD_272d00`, ...: unbound on the native links), and main's next virtual call on it jumps to a bogus
address; the drive thread it started misses `FUN_002731d0` (a wrapped declaration whose types differ from the
definition's). One normal run hit a corrupted malloc free list (`FUN_00270540`); with libgmalloc it did not
reproduce: the 32-bit allocation sizes that remain (the XboxDrive's 0x1e4, the XboxSaveDrive's 0x910, the om types'
instance sizes, which the leaf types pass as 32-bit constants to 0x002584d0) are the suspects.

### Method, batch and proof

As reg3 (scripts `build/reg4/scripts/`; `objs.py` builds the object table from the initializers, the inventory edits
and the source rewrites). Iterations x1-x8 with reg3's proof as the base and gen_tree with unb4's fix (dec1 is
landing it; the om/Type.cpp TU needs it to merge the record-based tree functions, and build_tree wraps them without
it). The x64 check: improved 0x002474c0 (fail -> equivalent), 0x002702a0 (fail -> unsupported); 0x00278a40 /
0x00277260 return `void` (their only callers ignore the result; a pointer returned as `int` was a 64-bit truncation).
Not equivalent on x64 after (HEAD: equivalent): 0x0008ee30 and 0x0026fcf0 (unsupported: the harness cannot run a
placement-constructed object's or an untyped slot's virtual call), 0x00258530 / 0x00258870 (inconclusive: the
node-to-type cast), 0x0025c0d0 (fail, layout: it now reads the type's size through the record).

| | control | batch (reg4) |
|---|---|---|
| sources | HEAD 3234e788e (the batch's HEAD cb545e026 changes only native tools) | 125 matches/, 40 equivalent/, records.h, 8 regenerated data headers, config/data.json, tools/data_gen.py, tools/native_unbound.py (+ test) |
| gates | - | 125 / 125 matches MATCH + verify_relocs ok (and every source that includes a changed header: 1,168 MATCH + ok); 40 equivalents equivalent and promotable at 3,000 inputs and `--wine` |
| data_gen (MSVC 7.1) | 18,826 items | 18,856 items verified, 1,078 TUs |
| merge modes (the proof's build_tree state) | - | 2 merged -> wrapped (0x00270f10, 0x00270d40: declarations spelled by the definitions); 64-bit front end of the 50 TUs: no new error |
| Wine proof (`--gfx`, play3 to 60,000, limit 14,400) | 64872 (studio, 3234e788e); 65111 (mac1, 60956479a) | 64998 (studio, with a placement-constructed core::Platform in 0x0026f070, since reverted); the committed batch against 65111 on mac1 is the confirmation run (seeded from 65111) |
| strict link rc / Wine unbound | 0 / 1,314 | 64998: 0 / 1,315 (the local core::Platform's stub destructor: reverted) |
| x87 keep list | 268 | identical |
| play3 checkpoints | 2,007 to 60,180 | 64998: `ckpt_gate.py` ok at all 2,007 common frames (the known transients only), PRNG hashes identical |
| arm64 macOS / x86-64 Linux / arm64 Android unbound (proof 64998's own snapshot and map) | 31,741 / 31,732 / 31,733 (reg3) | **30,514 / 30,505 / 30,506**, all rc 0 |
| macOS start-up | 260 (`DAT_004ca248`) | 260 until dec1's pointer words land; with them: every initializer, then main to core::Drive's vftables (above) |

## Instance sizes (reg5, 2026-11-07)

The om types' initializers and constructors passed their instances' 32-bit sizes to om::Type's constructor
(0x002584d0; om::EntityType 0x00243310, audio::SeqEventType 0x002605e0), and the om pool (0x002474c0) allocates
`body.size` bytes per instance; the file-system drives were allocated as `FUN_00266e00(heap, 0x1e4)` (core::XboxDrive)
and `0x910` (core::XboxSaveDrive), their worker thread as `0x94`. Every one of these classes holds pointers, so on 64-bit
the blocks were too small (reg4's corrupted malloc free list in 0x00270540 was one of them). The literal is now
`(int)sizeof(T)` and the alignment `(int)__alignof(T)` of a class with the instance's layout (the alignment literal 8
of Mix / Clip / Sequence is kept: their records are 4-aligned word pairs, as OmKey), and each site checks the XBE's
size with `HULK_SIZE32(T, n)` (records.h: a block-scope typedef that is a compile error on the 32-bit builds unless
`sizeof(T) == n`, nothing on 64-bit). MSVC 7.1's object is unchanged (the constant is the same).

- **Not include/gen classes.** 29 sites first took the generated class of the literal's size; a wrapped source that
  includes an include/gen/ header is isolated into a TU of its own, and 18 initializers became isolated TUs that each
  define a global `target()` (strict link: duplicate symbols). Records instead, the gen class's proven fields checked
  word by word (gen's audio::SeqEvent also declares none of its 6 virtual functions, so several gen SeqEvent* classes
  lack the vftable pointer).
- **records.h instance records** (106 new names, prefixed Audio / Om / Core): the SeqEvent instances on a shared
  `AudioSeqEvent {vftable; link}` / `AudioSeqEventContainer` head; the SeqAction / SeqCommand ones on
  `AudioSeqActionBase {vftable; link; event; state}`, the fade behaviours on `OmDynBehaviour`; Mix / Clip / Sequence on `OmEntity`; the mixer,
  sequence player, track, layer, buss and beat records; the Hal voice / buffer / stream player / RSD header /
  circular buffer records and `AudioOmHalStream`; om::MetaTypeAttribScalar, om::DynAttrT<om::String>, om::Property
  (`OmMetaProperty`); `CoreDrive` (0xbc: its library list at +0x14, the 0x44-byte label union at +0x70),
  `CoreXboxDrive`, `CoreXboxSaveDrive` (four 0x208-byte find slots), `CoreDriveThread` (a CoreThread at +0x18).
  Each field is commented with its 32-bit offset and the function that reads or writes it; a word is a pointer
  where some accessor dereferences it, stores an address in it or links objects through it. 0x0024df00 sizes its
  temporaries by its own placed class (`om::MetaTypeAttribScalar<int/float>`).
- **Left as literals:** HalListener (0x0035f960), Properties (0x00361110) and PointerUid (0x00361700), whose pool
  getters have no caller (no instance is ever allocated); the 0x4000-byte aligned stream buffer (0x003611d0, raw
  bytes). Other literal-size allocations outside the om types remained: `FUN_00266e00` in 0x00269640 (0x12a8),
  0x00277b70 (0x74), 0x0026e9e0 (0x1d8), 0x00334010 (0x1dc) (typed by reg6, below), and the `FUN_0008d690` /
  `operator new` literals of ptr1's 302 sources whose stub is shorter than the class.
- **Checks:** 77 matches/ MATCH + verify_relocs ok; 9 equivalents equivalent at 3,000 inputs and `--wine`. `--x64`
  (HEAD -> batch): 64 equivalent -> fail by design, each at the size / alignment argument (the 64-bit object passes
  the 64-bit size, e.g. SeqPlayer 184 -> 312, XboxSaveDrive 2,320 -> 2,472); the 4 pointer-free records (the two
  volume arrays, HalPositionalInfo, the RSD header) stay equivalent; 12 unsupported and 6 fail as at HEAD.

### gen_tree: a C++ declaration beside its definition

`compatible()` never paired a C++ declaration (`func`) with the TU's definition of the same function (`def`): the
declaration's canonical signature keeps its closing `;` (`char(T *,int);`), the definition's has none, so the two
compared as a conflict, not as a redeclaration, and the source that declared the function was wrapped or isolated
(the C-linkage pair had the same defect, fixed by dec1/unb4 in 416dc2082). The `{func, def}` comparison now drops
the `;` (`_sig_noqual`; `HULK_GEN_TREE_OFF=defsig` switches it off), tests/test_gen_tree_compat.py covers it. reg4's
workaround is gone: 0x00258530 / 0x00258730 and their callers 0x002588d0 / 0x002588f0 are C++ functions again
(the spelling before reg4), and om/Type.cpp merges all six tree functions. Fresh generate on HEAD + this batch: 27
blocks in 17 TUs change mode, all to merged (25 wrapped "conflict: FUN_x" -> merged, the two om::Type slots isolated
-> merged); without the fix the two slots would be isolated.

### Proof (instance sizes + the gen_tree fix)

| | control 65235 (HEAD 416dc2082, mac1) | proof 65292 (mac1, seeded from 65235) |
|---|---|---|
| sources | - | 79 matches/, 11 equivalent/, records.h, tools/gen_tree.py (+ test) |
| gates | - | 79 / 79 MATCH + verify_relocs ok; 11 / 11 equivalent at 3,000 inputs (0x00258530 / 0x00258730 at their usual 1,055 / 2,941) and `--wine` |
| merge modes (the builds' own states) | - | 36 changes: 25 wrapped -> merged (the `;` conflicts), 9 merged -> wrapped and 2 -> isolated (the cascade: "code differs from its standalone build", inlining in unk_2e6780.cpp) |
| strict link rc / Wine unbound | 0 / 1,314 | 0 / 1,314 (the same list) |
| x87 keep list | 268 | 268 (0x000a1b30's namespace changed: wrapped -> merged) |
| play3 checkpoints | 2,013 to 60,360 | `ckpt_gate.py` ok at 2,006 common frames (the known transients only), PRNG hashes identical |
| arm64 macOS / x86-64 Linux / arm64 Android unbound | 30,497 / 30,488 / 23,904 | 30,493 / 30,484 / 23,903, all rc 0 |

A first proof (65247) failed the strict link: with gen/audio.h included, 18 wrapped initializers were isolated and
five of them define a global `target()`. The records replaced the gen classes.

### The remaining 0x00266e00 allocations (reg6)

Four more sites passed a class's 32-bit size to the heap allocator; each now passes `sizeof` of a records.h record
with the class's layout (fields commented with their 32-bit offsets and the functions that use them) and checks the
XBE's size with `HULK_SIZE32`:

| site | class | 32-bit | 64-bit | record | where it runs |
|---|---|---|---|---|---|
| 0x00269640 | core::ControllerSystemXBox (four core::ControllerXBox pads inline, each with 20 input and 2 output points) | 0x12a8 | 0x1c78 | `CoreControllerSystemXBox`, `CoreControllerXBox`, `CoreControllerInputPointXBox`, `CoreControllerOutputPointXBox` | CGame start-up (0x00088530 -> 0x00088020 -> 0x0008e880), before the first .rcf mount |
| 0x00277b70 | core::CementLibrary (a drive's archive) | 0x74 | 0xa8 | `CoreCementLibrary` (+ the on-disk `CoreCementLibraryHeader`) | CGame start-up: the .rcf mounts (0x0008e880 for rcfs.txt, 0x00088020 for sound_*.rcf) through 0x00271560 |
| 0x0026e9e0 | core::ConsoleClient (the debug console's host link; its network calls are stubs in this build) | 0x1d8 | 0x1f0 | `CoreConsoleClient` (+ `CoreConsoleTxBuffer`) | debug only (0x0026ed80) |
| 0x00334010 | movie::PlayerBink | 0x1dc | 0x1f8 | `MoviePlayerBink` (+ `MoviePlayerBinkTrack`) | the movie screens (0x001b77e0) |

- ControllerXBox keeps the XInputSetState feedback inline (+0x458 status, +0x45c the header's event handle as
  `hulk_uintptr`, the motors at +0x49a / +0x49c, the `connected` byte at +0x49e): a nested struct would round to
  0x48 and move the byte. The sources still address it by 32-bit offsets, as the shim (input_xpp.cpp) does.
- 0x00334010 also takes the heap id as `int` and returns `void*`: it stored its `void*` parameter into the `int`
  DAT_004cdbb0 (`--x64`: a write past the end of the global) and returned the player as `int`.
- **Left as a literal:** 0x0008d480's 0x20800 bytes of heap 0 for the "Temporary Heap" are a raw arena, not an
  object: the dl allocator object itself is allocated by 0x0026cfa0 with `sizeof(core::MemoryDlAllocator)`
  (pointer-scaled) and carves its chunks out of the arena. On 64-bit the arena holds less (16-byte chunk headers,
  32-byte minimum chunks, larger objects); whether it needs to grow is a capacity question (the heap's peak, which
  DlHeapState's systemPeak records), not a layout one.
- Still literal, not object sizes: the core::File allocations `FUN_00275d50(0x168)` (0x00277b70, 0x00276df0,
  0x00276f00, 0x00277460) pass a size the pool allocator ignores (0x00275d50 takes no argument; the pool's item size
  is set where it is created). Follow-ups found on the way: core::ConsoleClient's pool is created with 0x110-byte
  items (0x0026e2a0) and 0x0026e140 clears 0x110 bytes, but its `CoreConsoleTxBuffer` (next pointer at +0x10c) is
  0x118 on 64-bit, and 0x0026e2a0 keeps the pool pointer in an `int`; 0x00275d50 returns the File pointer as
  `unsigned int`.

### Proof (reg6)

| | control 65297 (HEAD edaf49b8e, studio) | proof 68254 (studio) |
|---|---|---|
| sources | - | 2 matches/, 2 equivalent/, records.h (a tree input, so the proof built fresh, not seeded) |
| gates | - | 2 / 2 MATCH + verify_relocs ok; 2 / 2 equivalent at 3,000 inputs and `--wine`; `--x64`: the 3 that were equivalent fail only at the size (4,776 -> 7,288, 116 -> 168, 472 -> 496), 0x00334010 fails only at its size (476 -> 504; at HEAD: the layout write) |
| strict link rc / Wine unbound | 0 / 1,314 | 0 / 1,314 (the same list) |
| x87 keep list | 268 | 268 (identical) |
| play3 checkpoints | 2,011 to 60,300 | `ckpt_gate.py` ok at 2,006 common frames (the known transients only), PRNG hashes identical |
| arm64 macOS / x86-64 Linux / arm64 Android unbound | 30,469 / 30,460 / 23,893 | 30,468 / 30,459 / 23,892, all rc 0 |

## Start-up through the file system: drives, requests and the args.txt read (boot1, 2026-11-07)

reg4 left main at core::Drive's constructor (vftables stored under invented names) and saw a corrupted malloc free
list once; reg6's proof binary crashed on that corruption every time. The macOS start-up now gets through the
platform set-up, the drive registry, the save and D: drives with their worker thread, the content loader's fiber and
the open of `args.txt` through the drive thread's request queue: with the proof's own binding map the normal run opens,
sizes, reads and closes args.txt (CreateFileA, GetFileSize, SetFilePointer, ReadFile, CloseHandle on the drive
thread), parses it and enters CGame's start-up, where it stops creating the Lua state: 0x002150e0 calls the allocator
callback 0x001d0990, which the native link leaves unbound (the callback's declared type is not the allocator's). The
survey run (`HULK_NATIVE_MISSING=continue`) stops next in the Lua VM (0x00212ed0, `getData`: below).

### The stops

| run | where | cause | fix |
|---|---|---|---|
| reg6 proof | malloc (0x00270540): free list corrupt | core::MemoryPool was allocated as 0x002702a0's stand-in (two pointers, 11 words: 60 bytes on 64-bit) while 0x00270020's owners view wrote to +0x40; gen's core::MemoryPool kept its block (+0x18) as `unsigned int` | records.h `CoreMemoryPool` (with `CoreObjectBase`: on the 64-bit MS ABI a base class's members end at its rounded size, so gen's f_0c is at +0x18, not +0x14); gen f_18 pointer-sized (evidence-rn ptr_fields), owners `Pool_270020` on the record, 0x00270170 / 0x0026ff90 / 0x002702a0 / 0x002701d0 on it, 0x002700f0 onto gen's class; 0x002701d0's child pool by address names (`gTag`, `Alloc`, `Init`, `Setup` were invented) |
| 1 | FUN_0026fcf0: slot 21 of the new XboxDrive jumps to 0x4000000000 | core::Drive's constructor stored invented vftable names; 0x0026f570 / 0x00278500 let the compiler emit stub vftables | the constructors on records.h `CoreDrive` / `CoreXboxDrive` / `CoreXboxSaveDrive` with explicit `DAT_` vftable stores; the library list 0x00277a40 on `CoreDriveLibraryList`; the label `DAT_00445644`, not the literal 0x445644 |
| 1 | the drive thread misses FUN_002731d0 | a wrapped C++ declaration | the worker (0x002731d0, `extern "C"`), the thread object (0x002733c0) and its queue (0x00272fc0 push, 0x00273140 pop, 0x00272f70, 0x00272fa0 / 0x00272fb0, 0x00273120) on `CoreDriveThread`; semaphores pointer-sized (0x0026d860 / 0x0026d880 / 0x0026d890 / 0x0026d8a0: the shim returns host pointers), the XDK rows by address |
| 2 | `?FUN_0026f570@XboxDrive_nv_26fcf0` unbound | the callers' IR signature (the heap as `const char*`) differs from the definition's (`int`) | 0x0026fcf0 / 0x00278a40 pass `int` |
| 3 | 0x0026dd10: the content loader's fiber has no thread | 0x0026dbb0 *defined* `DAT_0052a180` / `DAT_0052a188` itself; the tree wraps the TU, so they became `fn_0026dbb0` C++ variables: a private, always empty thread list | the shared declarations (decls/data/platform/xbox/core.h) |
| 4 | 0x0008fca0: no file for args.txt | the drive registry was two inventory items (0x00528418 20 bytes, 0x0052842c 7,392) that each source indexed with its own 32-bit stride view (0x11c, 0x120 on 64-bit) | records.h `CoreDriveRegistryEntry DAT_00528418[26]`, the critical section its own item `DAT_0052a0f0` (config/data.json; config/data-ptrs.json's 0x0052842c record dropped); 14 sources on it (0x00271070 also wrote the flag 0x0052a11d as lock + 0x2d) |
| 5 | core::Drive's AddRef reads the wrong word | gen_tree **merges** two classes of one TU that have the same name (`Drive` in 0x0026f130 and 0x0026f790) into one with `char _m_pad_4[0x8]`: a 32-bit-offset union that drops the pointer members | layout classes get unique names (`Drive_26f130`, `DriveThread_272f70`, ...: 23 sources) |
| 6 | the File slots call invented or devirtualized names | `init`, `Sub_275db0::F0` (a member object's virtual call is direct), `Allocate`, `Set`, base constructors of invented classes | core::File on records.h `CoreFile` (gen's core::File agrees: its +0x12c word is the library view's pointer, evidence-rn fields); the File slots (0x00275db0-0x002762f0, 0x002765d0), the request constructors (0x00274e60 core::FileRequest, 0x00274f20 / 0x002751a0 / 0x00275110 / 0x00275230 / 0x002752e0 / 0x00275390 / 0x00275430 / 0x002754d0 / 0x00275570) on `CoreRequest` with buffer and result pointers as pointers, the completion requests (0x00274ca0 / 0x00274ba0, `CoreCompletionRequest`), the nine FileRequest deleting destructors (one template), the pool allocators 0x00273560 / 0x00276680 / 0x00275d50 return `void*` and take the callers' size, the pools' item sizes by `sizeof` (0x00273530 core::DriveFindFirstRequest, 0x00276650 core::InstanceDrive, 0x00275d20 `CoreFile`) |
| 7 | the drive thread's slot 3 call reaches `hulk_x_00273880` | core::Request's slot 3 returns the drive: widened to `hulk_intptr` (evidence-rn sigs), but `native_mac.TreeDefs` keyed the slot's definition by its demangled form, `int` on i686 and `__int64` on 64-bit | tools/native_mac.py: `loose()` fallback key when the exact form matches nothing (tests/native_host/treedefs_test.py); every slot ptr_slots widened had this gap |
| proof map | CGame start-up: 0x002150e0's allocator callback FUN_001d0990 unbound | the Lua state's allocator: 0x001d3c90 passes FUN_001d0990 (`int (State*)`) where 0x002150e0 calls an allocator | next (and the survey's 0x00212ed0 `getData`: the Lua VM's invented names, TObjects copied as two 32-bit words) |

Also on the way: the request processes on the drive thread (open 0x00273920, read 0x00273f00, get-size 0x00274260,
close 0x00273da0, FileRequest::vfunc_4 0x00273890, FileCompletionRequest 0x002736e0 / 0x00273700 / 0x00274d20),
the XboxDrive slots on `CoreXboxDrive` (0x0026f130-0x0026fcb0; the error converter 0x0026f3e0 is a member: its
callers pass the drive in ecx), the XboxSaveDrive forwards (0x002786a0 / 0x002786c0 / 0x002786e0), 0x00272fc0
returns the semaphore release's result on 64-bit (the 32-bit spelling with a result does not match in 11
variants, so `Result_272fc0` is `int` only under `HULK_PTR64`).

**Then (batch D, proof 68765 vs control 68764):** the Lua state's allocator 0x001d0990 (`Realloc`'s `Alloc` is
FUN_00266e00) and its type in 0x001d3c90, the protected call 0x002152f0's argument as a pointer in its callers
(0x002150e0 / 0x002151e0 / 0x00215de0), the luaopen callback 0x00214e80 declared with its parameter, and its
luaM_realloc 0x0021add0 declared as defined. The start-up now runs into luaopen's table creation. The Lua VM is the next
subsystem and needs one batch for all of it: a TObject is 8 bytes on 32-bit and 16 on 64-bit, 38 VM sources index the
stack by `n * 8`, luaM_realloc has about 35 different declarations, and sizes are written as `stacksize * 8`, so the
records (TObject, lua_State, CallInfo, Table / Node, Closure) have to replace every user at once.

### Rules this batch found

- **Unique names for layout classes.** gen_tree merges same-named classes of one TU by their 32-bit layout; a record
  view must not share its name with another source's class in the TU.
- **MS-ABI bases round up.** A record that flattens a class with a polymorphic base (core::Object: vftable + heap)
  must keep the base as a member struct (`CoreObjectBase`), or its 64-bit offsets differ from gen's class; checked
  with static_asserts of gen against the record on i686 / x86_64 / aarch64 (build/boot1/lay.cpp: MemoryPool, File;
  core::Drive's gen class is still 32-bit-padded, so the drive sources go by the record only).
- **The native link's IR rule.** A name binds by its address only when the reference's IR signature equals the
  definition's (`ptr` and `i64` alike; `i8` vs `i32` parameters, a read result vs `void` are mismatches).
- **Equivalence and caching.** A rewrite that keeps a member in a local across calls fails level 3 when the original
  re-reads it (the stubs may write the object): read through `this` as the original does.

### Not done (follow-ups)

**0x002786f0** (XboxSaveDrive's IMutable slot 2) byte-matches only as a compiler-generated adjustor thunk of an
invented class (a written `this - 0xc` compiles to `add ecx, -0xc`), which on 64-bit adjusts by the invented layout and
jumps to an unbound name. The source keeps that form under `#if !defined(HULK_PTR64)` (the MSVC and clang i686
objects are unchanged: compare MATCH, the i686 object's code, relocations and symbols identical) and on 64-bit defines
the thunk explicitly as `Thunk_2786f0::FUN_002786f0`: back from the IMutable sub-object by
`offsetof(CoreXboxSaveDrive, drive.vftableMutable)`, then the deleting destructor `FUN_00278a80`. The top-level `#if`
makes gen_tree wrap the TU ("macros"). The vftable slot binds through a third `TreeDefs` key in tools/native_mac.py:
a definition named by its own address (`FUN_<addr>`), when neither demangled form matches.


DriveCompletionRequest 0x00273780 /
0x002737a0; the cement read 0x00278010 (owners `Obj_278010`, pointers through `int`); FileRequest::vfunc_2
0x00273860 (compares a file pointer with an `int`); core::ConsoleClient's record (reg6) has the RefCount base
flattened (64-bit offsets differ from the MS ABI's); XboxSaveDrive's save state `DAT_0052c270` is a packed DataRec the
sources index by 32-bit offsets.

### Method, batch and proof

Iterations as reg4's, but every MSVC step on the queue (the laptop's Rosetta was wedged: x86_64 processes hung in
state U): one queue job per iteration runs gen_tree with the base proof's state, the iteration report and the arm64
compile (build/boot1/scripts/iterjob.sh); the link and the runs are local. build/boot1/scripts/native_mac_why.py dumps
the link's per-name binding reasons. Iterations it1-it9 with reg6's proof 68254 as the base.

| | control 68254 (HEAD caa806d0a, studio) | proof 68701 (studio, HEAD 3655ceb29 + the batch) |
|---|---|---|
| sources | - | 121 matches/, 35 equivalent/, records.h, gen core.h / owners.h + evidence-rn / evidence-owners, config/data.json + data-ptrs.json, engine/unknown.h, tools/native_mac.py + tests/native_host/treedefs_test.py |
| gates | - | 121 / 121 MATCH + verify_relocs ok (and the 16 other core::MemoryPool users, 22 gen core::File users); 35 / 35 equivalent at 3,000 inputs and `--wine` (0x0008fca0 50 inputs and 0x002731d0 as at HEAD: slow loops) |
| `--x64` (HEAD -> batch) | - | matches: 45 eq -> eq, 11 fail / unsupported -> eq, 25 eq -> unsupported (virtual calls through a record's `const void*` vftable field: the harness), 11 eq -> fail by design (pool item sizes, pointer-sized handles and slot 3, gen views of the drives vs the record); equivalents: 16 eq -> eq, 5 fail -> eq, 3 eq -> unsupported, 1 eq -> fail by design (0x002733c0's pointer-sized argument) |
| data_gen | 18,856 items | 18,856 items verified, 1,078 TUs |
| merge modes | - | 25 wrapped -> merged (the renamed classes), 0x002761c0 isolated -> merged, 0x00272fc0 merged -> wrapped (macros) |
| strict link rc / Wine unbound | 0 / 1,314 | 0 / 1,254 (68 fewer; 8 new: the stub-vftable members of 0x0026f540's invented classes, now merged into XboxDrive.cpp) |
| x87 keep list | 268 | identical |
| arm64 macOS / x86-64 Linux / arm64 Android unbound | 30,468 / 30,459 / 23,892 | **30,263 / 30,254 / 23,688**, all rc 0 |
| macOS start-up | stops at the malloc corruption (0x00270540) | args.txt read; stops in CGame's start-up at the Lua state's allocator (above) |
| play3 checkpoints | 2,006 to 60,150 | `ckpt_gate.py`: ok at 2,006 common frames (the known transients only), PRNG hashes identical |

A first proof (68566, without 0x002741d0's fix) stopped at the Wine start-up: 0x002741d0 defined its own `CoreFile`,
the name clash isolated it, and its member object's devirtualized call `FileIface::f0` was unbound.

## The Lua VM on records (lua1 / lua2, 2026-11-08)

boot1 left the macOS start-up in CGame's start-up creating the Lua state. The game embeds a Lua VM (0x00212bb0-
0x00221ae0 core, 0x00338d90-0x0033eb6f lauxlib and the libraries): a Lua 5.1 work version (lua_newstate with an
allocator callback, the incremental collector's white/black bits and barriers, a ZIO that carries the state, upvalue
descriptors as byte pairs) that keeps Lua 5.0's lua_State, the pseudo-indices (registry -10000, globals -10001) and
the Node layout, with a `float` lua_Number. The version was identified from the game's code (allocation sizes,
constructors, accessors, the error strings), not from any Lua source. A TObject is 8 bytes on 32-bit and 16 on
64-bit, and the sources viewed every VM object through per-source pad structs with 32-bit offsets, indexed the stack
by `n * 8`, copied TObjects as two 32-bit words, held pointers in ints and called invented names (`getData`, `Alloc`,
`target`): every VM source moved onto one set of records in one batch.

### The records

`include/decls/data/lua.h` (new): `LuaVMTObject` / `LuaVMValue`, `LuaVMGCObject`, `LuaVMString` (+ `LUAVM_GETSTR`),
`LuaVMUdata`, `LuaVMProto` / `LuaVMLocVar`, `LuaVMUpVal`, `LuaVMCClosure` / `LuaVMLClosure` / `LuaVMClosure`
(`LUAVM_SIZECCLOSURE` / `LUAVM_SIZELCLOSURE`), `LuaVMNode` / `LuaVMTable`, `LuaVMCallInfo`, `LuaVMLongjmp`,
`LuaVMBuffer`, `LuaVMZio`, `LuaVMState` (0x58), `LuaVMStringTable`, `LuaVMGlobal` (0xb0), `LuaVMLG`, `LuaVMDebug`;
the compiler's `LuaVMSemInfo`, `LuaVMToken`, `LuaVMLexState`, `LuaVMExpDesc`, `LuaVMUpvalDesc`, `LuaVMFuncState`,
`LuaVMBlockCnt`, `LuaVMConsControl`, `LuaVMLHSAssign`; the loader's `LuaVMSParser`, `LuaVMLoadState`,
`LuaVMDumpState`; ldo's `LuaVMCallS` / `LuaVMCCallS`; the libraries' `LuaVMLBuffer`, `LuaVMReg`, `LuaVMCapture`,
`LuaVMMatchState`, `LuaVMLoadRefs`, `LuaVMFile`, `LuaVMLoadF`, `LuaVMLoadS`. Every field carries its 32-bit offset and
a function that uses it; `LuaVMLayout32` checks the XBE's offsets and sizes on the 32-bit builds (`LUAVM_CHECK32`).
`LUAVM_NILOBJECT` is `DAT_00426824` (now an 8-byte struct item), `LUAVM_SETOBJ` copies tt then value. The data:
`DAT_00426948` (luaT_typenames, `const char*[11]`) and `DAT_00426bf0` (luaX_tokens, `void*[31]`) are pointer tables
with their strings split out (config/data.json, the forced pointer words in config/data-pointers.json, the nil object's
record in config/data-ptrs.json).

Rules the batch kept: strides and sizes by `sizeof` (slot counts stay counts: `L->top + 20` for LUA_MINSTACK); the
on-disk chunk format's sizes (lundump / ldump header checks) stay 32-bit literals; every callee `FUN_<addr>` with the
definition's record-typed signature (`extern "C"`, every lua_CFunction `int __cdecl (LuaVMState*)`); casts at the use
where a record field's signedness changed MSVC's code.

### Batch

- 241 matches/ and 296 equivalent/ sources: the core (lapi, ldebug, ldo, lgc, lmem, lfunc, lobject, lstate,
  lstring, ltable, ltm, lvm, llex, lparser, lcode, lundump, ldump, lzio), lauxlib and the libraries (base, string,
  table, math, the loaders), and the game's callers (ScriptHandler 0x001d0990 / 0x001d1080 / 0x001d10e0 /
  0x001d2020 / 0x001d29b0 / 0x001d36f0 / 0x001d3960 / 0x001d3c90 ..., 0x001d17f0, 0x001d0a40 ...).
- 0x0033b7d0 (math.floor) now calls floor: HEAD called `__ceil_default`, the original calls `__floor_default`
  (0x0034557c). The proof's play3 checkpoints are unchanged, and `___ceil_default` left the Wine unbound list.
- gen_tree merges the Lua TU: two declarations of one `FUN_` name with different C++ types (an `unsigned int` vs
  `int` parameter) become two `extern "C++"` overloads and the call is ambiguous (0x0021c490 / 0x0021c5f0 /
  0x0021c9b0 declared luaM_growaux 0x0021ae40's element size `unsigned int`; unk_212bb0.cpp failed the 64-bit front
  end). The IR check (`build/lua1/scripts/sigcheck.py`) cannot see this: declare the definition's exact types.
- 0x001d2020 pushes a name 0x001d0c60 does not take (cdecl: the caller pops it): the 64-bit build declares and calls
  the one-argument form under `HULK_PTR64`.

### Gates

| | |
|---|---|
| matches | 241 / 241 compare.py MATCH + verify_relocs ok (queue, with the batch's headers) |
| equivalents, 3,000 inputs | 296 / 296 equivalent; 199 at 3,000+; the rest at their own ceilings (slow or stale-coverage inputs), each at or above the original source's STATUS count, or (0x0021d4b0 at `--inputs 3200`, 0x00217830, 0x0021b720) within 2 inputs of the original run on the same host; except 0x002134a0 (lua_pushcclosure: 79 inputs, 6/6 branches; the original 150 on the same host: the record-typed inputs end its random phase earlier; time budget does not change it) |
| equivalents, `--wine` | 287 / 296; the 9 others fail identically on the untouched originals: 0x00216340, 0x00219a60, 0x0021aa00, 0x0021b230, 0x0021b720, 0x0021fb50, 0x0033d400, 0x001d36f0 (fail), 0x002142d0 (inconclusive). Since wine1 (below, "The nine `--wine` exceptions"): 296 / 296 |
| `--x64` (informational) | 227 equivalent, 42 fail (by design: the realloc sizes, stack strides, 16-byte TObjects past 32-bit allocations, pointer-sized fields read by 32-bit views), 23 unsupported (no input completes on the 32-bit side), 4 inconclusive |
| sigcheck (64-bit IR, declarations vs definitions) | 0 in the Lua set; left: 0x001d29b0 -> 0x001d17f0 (gen owners.h holds the lua_State in an `int`), 0x00278ef0 -> 0x00278180 (not Lua), 0x0033ed20 -> 0x0033eb90 (the aligned allocator, below) |

### Proof

| | control 68765 (boot1's proof, studio) | proof 69769 (studio, HEAD c459a542a + the batch) |
|---|---|---|
| data_gen | 18,856 items | 18,861 items, 1,078 TUs (dg-n2) |
| strict link rc / Wine unbound | 0 / 1,254 | 0 / 1,253 (`___ceil_default` gone) |
| x87 keep list | 268 | 268, the same functions (0x00222180's namespace and 0x0033b880's `extern "C"` name changed) |
| play3 checkpoints | 2,002 to 60,030 | `ckpt_gate.py` GATE ok at 2,002 common frames (the known transients only), PRNG hashes identical; 2,016 to 60,450 |
| arm64 macOS / x86-64 Linux / arm64 Android unbound | 30,248 / 23,676 / 30,240 | **29,654 / 23,556 / 29,646**, all rc 0 |
| macOS start-up | luaM_realloc | lua_newstate, the allocator and luaopen run; stops in luaL_openlib (0x003390d0) at lua_setfield (0x00213790): the luaL_reg tables' names are 32-bit XBE addresses (`strlen(0x434f60)`) |

### Follow-ups

- The luaL_reg tables: done (below).
- getF 0x00339770 / luaL_loadfile 0x00339800 read the Xbox FILE's `_flag` directly (`LuaVMFile`): the native build
  needs a feof / ferror shim in src/platform/sdl.
- 0x001d22a0 packs its arguments into 4-byte slots; gen owners.h classes hold the lua_State in an `int` at +0x08
  (0x001d29b0's cast, 0x001d17f0's `void*` context).
- The aligned allocator 0x0033eb70 / 0x0033eb90 / 0x0033ec00 / 0x0033ec30 / 0x0033ed10 / 0x0033ed20 (about 32
  callers, not Lua): a function-pointer hook in a 4-byte header slot at user-8 and pointer tables (`DAT_004d9858` /
  `DAT_004d985c`) as `unsigned int`; needs a header-layout decision.
- Game bug kept: generic_reader and luaB_load call luaL_unref 0x00339710 with (ref, LUA_REGISTRYINDEX) swapped.

### The library tables, the heap's free and ScriptHandler's Lua callers (lua2, 2026-11-08)

- **luaL_reg tables as pointer data.** luaL_openlib (0x003390d0) reads name / function pairs; the inventory had
  dropped every name word whose bytes read as text (`60 4f 43 00`), so the data TUs emitted 32-bit addresses
  (`strlen(0x434f60)` on 64-bit). config/data-pointers.json forces the name words of the six tables (math
  0x00434970, string 0x00434af8, base 0x00434d90, debug 0x00434710, table 0x004348a0, ScriptHandler 0x00422458);
  config/data.json ends the math, string and debug tables at their terminators (the strings after them, e.g.
  "randomseed", "gsub", "traceback", are their own items now) and makes 0x004348a0 and 0x00422458 one 72- and
  16-byte item each (they were a 4-byte "string", a pointer table and zeros). The data step types them
  `const void* const[2n]`, the 64-bit LuaVMReg layout.
- **Library-owned strings.** Eight of the math names (0x00434a4c-0x00434a7c, "exp" .. "ceil", "mod") were owned by
  library/xgrph.obj (an XGraphics string shares "exp"); once the table pointed at them they were unbound library data
  in the Wine build and play3 diverged at frame 24,450 (proof 69780; the sound RNG count moved first). They belong to
  unk_338d90 now (`data` / `data-shared`). 0x00434b9c "char" and 0x00434bbc "sub" (string library) stay library-owned
  and unbound as at HEAD.
- **The heap's free took the block as an int.** 0x00267090 passed the pointer as `hulk_intptr` to the heap tree's
  lookup 0x00266f50 and as `int` to the owner's slot 4 (core::IMemoryAllocator's free): a truncated free of the first
  block the Lua allocator released (macOS: "pointer being freed was not allocated"). Both take `void*` now (the tree
  node is `Node_266f50`, the name `Node` collided in merged TUs).
- **ScriptHandler's Lua callers.** 33 matches (0x001d0620-0x001d47c0) called the Lua API under invented names (`A`,
  `F2133d0`, `Reg`, `Post`, ...), with the state as `const char*` and lua_pushnumber's float as an int bit pattern:
  all on `FUN_<addr>` with the definitions' types (`1.0f`), the luaL_reg tables as `LuaVMReg`, the closures built by
  placement new on the callees' real constructors. 0x001d3c90 (`target` -> `FUN_001d3c90`) calls 0x001d1740 as
  `void` on 64-bit (MS mangling carries the return type; the 32-bit source returns what 0x001d1740 left in eax).

| | control 69769 (HEAD 741fd13b2) | proof 69791 (studio) |
|---|---|---|
| gates | - | 41 / 41 matches MATCH + verify_relocs ok (queue, the batch's headers); 0x0033ea90 equivalent at 3,000 inputs and `--wine` |
| data_gen | 18,861 items | 18,874 items, all verified (dg-n4) |
| strict link rc / Wine unbound | 0 / 1,253 | 0 / 1,252 (the invented `_Check` gone) |
| x87 keep list | 268 | identical |
| play3 checkpoints | 2,016 to 60,450 | `ckpt_gate.py` GATE ok at 2,012 common frames (the known transients only), PRNG hashes identical |
| bisect of 69780's divergence | - | 69784 (heap + 0x001d3c90 only): ok; 69783 (data with the ownership fix): ok |
| arm64 macOS / x86-64 Linux / arm64 Android unbound | 29,654 / 23,556 / 29,646 | **29,556 / 23,559 / 29,548**, all rc 0 (Linux +3: the ScriptHandler callers now name real members the Linux link does not bind yet, e.g. `SortedList::FUN_001d1180`) |
| macOS start-up | luaL_openlib's names | the Lua state, every luaopen and ScriptHandler's registrations run; stops in ScriptHandler's constructor (0x001d4830) at SortedList::FUN_001d1180: ScriptHandler is a 32-bit view (`HandlerTable data[0x1000]` for 0x400 entry pointers, `WatchList data[0x4404]`), allocated by 0x001d4c90 with its 32-bit size |

Next: ScriptHandler (0x001d4830's view, SortedList 0x001d1180, WatchList 0x001d27d0, the closures' 0x24-byte
literal sizes in 0x001d4580-0x001d47c0) as records; then the rest of reg6's CGame literal-size list
(build/reg6/lit-startup.txt). Found on the way: the closure constructors 0x001d40d0 / 0x001d4320 and 0x001d4210 /
0x001d3250 take object and function pointers as `int` / `const char*` and keep them in `hulk_intptr` members; gen
owners.h holds the lua_State as an `int` at +0x08 in ten ScriptHandler-area classes; 0x001d3410 names the
ScriptHandler vftable 0x00422684 by an invented data name.

### The nine `--wine` exceptions (wine1, 2026-11-09)

The nine Lua sources that failed `equiv.py --wine` after the records batch (and before it): two kinds of cause, three
source fixes and five checker rules (docs/equivalence.md round 29, `EQUIV_OFF=rowrite,fescape,intrub,natobj,fillrel`).
None of them is a difference a real input reaches; the three source changes put clang's order of two stores where
the original has it.

| function | cause | kind | fix |
|---|---|---|---|
| 0x00216340 luaO_chunkid | a fuzzed `out` at the literal `"[string \""` it copies (`out` overlaps the literal pool) or `out == source` (an overlapping strcat) | checker | rowrite, intrub |
| 0x00219a60 numuse | `nums[luaO_log2(k - 1) + 1]++` with the stubbed log2's fuzzed result: an index beyond the whole stack, landing where each frame layout puts it | checker | fescape |
| 0x0021aa00 DumpConstants | `D->writer(L, &bits, 4, ud)`: a function pointer, so the 8 bytes behind `bits` were compared, another local in each frame (the original's loop counter) | checker | natobj (clang's DWARF bounds the object) |
| 0x0021b230 read_numeral | `b->buffer[b->n++] = c` and `*z->p++`: clang stores n + 1 / p + 1 before the character store / load, MSVC after; a buffer overlapping its own LuaVMBuffer / Zio header (undefined behaviour) tells them apart | source | the statements in the original's order |
| 0x0021b720 read_string | `*z->p++` in NEXT, as above (its SAVE already had the original's order) | source | the same |
| 0x0021fb50 LoadLocals | the original keeps the locals still to read in the frame word behind `f.w` (`dec` per loop); the source's frame struct set `f.count = n` once | source | `f.count--` per local |
| 0x0033d400 str_format | a directed input planted the original's frame address (its luaL_Buffer's end - 1) in the stub-filled `b.p`; clang's buffer is 4 bytes lower | checker | fillrel (the same offset into ours's object) |
| 0x001d36f0 ScriptHandler::DoLuaBuffer | `buffer[length] = 0` with fuzzed buffer/length lands in the original's `.rdata` initializer of `script[]`, which the original then copies | checker | rowrite (source unchanged; sh1's area) |
| 0x002142d0 symbexec | none: `--wine` at 600 inputs is equivalent (2,095 inputs, 89/120); inconclusive only at a low input count | - | - |

| | control 69791 (lua2's proof, studio, HEAD 8310fb004) | proof 69964 (studio, HEAD + the three sources, seed:69791) |
|---|---|---|
| gates | - | `--wine` 600: 9 / 9 equivalent (with the round-29 checker); MSVC mode: 0x0021b230 1,806 inputs 40/40, 0x0021b720 5,851 (`--inputs 8000 --time-budget 1500`) 46/48, 0x0021fb50 106 (its STATUS count) 17/18; regress 466 / 467 (0x001fe380_tiny_counts at 70% coverage, the same with HEAD's equiv.py) |
| strict link rc / Wine unbound | 0 / 1,252 | 0 / 1,252 |
| play3 checkpoints | 2,012 to 60,330 | `ckpt_gate.py` GATE ok at 2,012 common frames (the known transients only), PRNG hashes identical; 2,014 to 60,390 |

Not done: the other lexer sources (save_and_next 0x0021b1c0, llex) spell `*z->p++` the clang-ambiguous way too; fuzzing
did not reach an aliasing input there. natobj finds the function by its DWARF name; a C++ member's definition DIE
carries its name through DW_AT_specification, which the parser does not follow (such a call is compared as before).
