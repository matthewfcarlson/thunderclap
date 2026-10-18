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
```

**Status 2026-10-17 (night): the strict link succeeds.** `lld-link` without `/force` links the 3,594 clang objects
(2,516 code TUs + 1,078 data TUs), the aliases, the game's vftables/RTTI and a stub object for the 9,613 symbols still
undefined into a 6.6 MB PE32 image: no duplicate definitions left (were 1,211). See [After the next fixes
1-3](#after-the-next-fixes-1-3-2026-10-17); [After fixes 0-2 and 5a](#after-fixes-0-2-and-5a) is the evening before
(fixes 0, 1, 2, 5a; link only with `/force:multiple`), and the sections from "What was measured" on are the
morning's baseline.

Cold, the first run takes 10-15 minutes (4 compiler processes); a warm run takes 30 s. Everything goes to `build/clang-probe/`:
`report.json` (counts, categories with example sites, scans, link probe), `undefined.txt` (every undefined symbol with
its group and demangled name), `cache/` (per-TU results and objects) and `snap/` (the tree being probed).

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

**Next** (sizes from the table):

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

**9. 64-bit (sized, not first):** 4,779 pointer↔int casts in 2,981 sources, 24,747 explicit pads in 3,572 sources,
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
