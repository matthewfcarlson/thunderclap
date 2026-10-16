# The source tree (first scaffold)

The per-function sources in `matches/` and `equivalent/` stay the source of truth. Three tools turn them
into a source tree with one translation unit per recovered object file, and check that every function
survives the merge. Plan: [shipping.md §1](shipping.md#1-the-source-tree-roadmap-steps-2-and-4). Splits:
[splits.md](splits.md). Numbers below are from 2026-10-15, after the placeholder rename
([below](#placeholder-names-toolsrename_placeholderspy)), the stub reconciliation
([below](#stub-reconciliation-2026-10-15)) and the [platform layer split](#platform-layers-2026-10-15); the
[include/gen/ migration](#includegen-migration-2026-10-16) (2026-10-16) has its own numbers.

```sh
build/venv/bin/python tools/infer_splits.py      # config/splits.json + docs/splits.md      (~7 s)
build/venv/bin/python tools/gen_tree.py          # build/tree/{src,include}/ from the splits (~8 s)
build/venv/bin/python tools/build_tree.py --rounds 16  # generate, compile, fall back, re-verify (~25 min warm, ~45 min cold)
build/venv/bin/python tools/build_tree.py --equiv 300   # also run equiv.py on 300 equivalent/ functions
build/venv/bin/python tools/build_tree.py --only src/game/global/CAction.cpp  # one TU, current tree
build/venv/bin/python tools/seam_inventory.py    # docs/seams.md: what game/engine call in platform/xbox (~30 s)
build/venv/bin/python tools/reconcile_stubs.py [--apply]   # clone names in matches/ + equivalent/ (re-verify what it changes)
build/venv/bin/python tools/migrate_gen.py [--family gen|pin|ns] [--equivalent] [--apply]   # sources onto include/gen/, include/decls/
build/venv/bin/python tools/data_inventory.py && build/venv/bin/python tools/data_gen.py   # data inventory + data TUs (docs/data.md)
```

`build_tree.py` regenerates the tree itself (from an empty fallback state), so it is the one command to
run. Everything under `build/` is regenerated; nothing in it is edited by hand.

| Output | What |
|---|---|
| `config/splits.json` | object ranges in `.text` (committed) |
| `build/tree/src/<layer>/<dir>/<File>.cpp` | one TU per game object, under its layer (`game`, `engine`, `platform/xbox`; [below](#platform-layers-2026-10-15)); `<File>.O1.cpp` for functions with other `cl-flags`; `<File>.iso_<addr>.cpp` for isolated functions |
| `build/tree/include/<layer>/<dir>.h`, `common.h` | hoisted shared declarations |
| `build/tree/manifest.json` | every TU: its functions, how each was emitted, line ranges |
| `build/tree/state.json` | fallback decisions from the last build (wrap / isolate / keep out of headers) |
| `build/tree/conflicts.json` | every symbol declared incompatibly by different sources |
| `build/tree/report.json` | per-function verification results and the summary |
| `build/tree-cache/` | compiled objects (by content hash) and the call graph |

## How a TU is built

Each game object gets one TU with all its functions in address order. A verified function is its
definition; an unverified one is `// 0xADDR NAME (size B): not yet verified`. Each verified source is split
into top-level items (`tools/cxx_items.py`: classes, forward declarations, typedefs, functions, variables,
`#define`s) and emitted in one of three ways:

- **merged**: the function's declarations are the TU's chosen variant of every name it declares. They are
  emitted once (at the top of the TU or in a header) and only the definition stays in place. For each
  name, the variants used by the TU's functions are taken most-used first, keeping each one that can
  coexist with those already kept (C++ overloads can; two different `class Obj` definitions can't; a
  function named like a class hides it, so types and values share one name space).
- **wrapped**: the original source verbatim inside `namespace fn_<addr> { ... }`. MSVC 7.1 accepts
  differing declarations, even of `extern "C"` names, in different namespaces. Global `operator new` /
  `delete` are pulled out in front of the namespace, because `new (p) T` never looks inside one.
- **isolated**: the original source verbatim in its own TU `<File>.iso_<addr>.cpp`. Used when a wrapped
  function still fails to compile (it can see the TU's global declarations: an elaborated `struct Manager*`
  finds `::Manager` before declaring its own).

Functions with a `// cl-flags:` line that differs from the defaults go to a sibling TU per flag set
(`CFoo.O1.cpp`, whose first line repeats the `// cl-flags:` comment so `compare.compile_obj` picks it up).
10 such TUs exist; the 119 verified functions inside the XDK/CRT library objects are not in the tree.

Headers: a declaration that at least two TUs of a directory use, and that is compatible with every variant
of its name used by merged functions in that directory, goes to `include/<dir>.h`. One that is used by two
or more directories and compatible everywhere goes to `common.h` (included by every directory header). A
declaration moves only together with the declarations it mentions.

`build_tree.py` then compiles every TU (4 `cl` processes at most, `compare.py`'s flags plus
`/I build/tree/include`) and blames each compile error on the line's owner: a merged definition is
wrapped, a TU-level declaration wraps its users, a header declaration is kept out of headers, a wrapped
function is isolated. It regenerates and recompiles until nothing new is blamed (10 rounds today); a TU that
still fails after the last round has all its functions isolated.

It then checks every function's code: a match must still match (else it is recompiled on its own to tell a
regression from a function that doesn't match standalone), and an equivalent/ function must compile to the
same bytes as its own source compiled standalone (relocation positions and kinds; targets where they carry an
address). A function that fails either check falls back (merged -> wrapped -> isolated) and the tree is rebuilt
(`--regression-rounds`, default 2). This is what makes the class merges below safe for equivalent/ sources.

## Current numbers

(Before the include/gen/ migration. Latest: 19,611 / 5,202 / 640 merged / wrapped / isolated, 77.0% merged, 2,499 TUs,
[below](#includegen-migration-2026-10-16).)

| | before (2026-10-14, 19:00) | after (2026-10-15) |
|---|---|---|
| verified functions in the tree | 23,913 | 24,527 (farm lanes added sources meanwhile) |
| TU files | 2,004 | 1,998 (1,779 objects, 10 flag variants, 67 placement-new siblings, 142 isolated) |
| TUs compiling | 2,004 / 2,004 | **1,998 / 1,998** |
| emitted merged / wrapped / isolated | 12,946 / 10,753 / 214 (54.1% merged) | **15,699 / 8,686 / 142 (64.0% merged)** |
| matches merged / wrapped / isolated | 10,745 / 8,609 / 56 | 12,919 / 7,044 / 61 |
| equivalent/ merged / wrapped / isolated | 2,201 / 2,144 / 158 | 2,780 / 1,642 / 81 |
| TUs where every function is merged | ~514 (325 with more than one function) | 657 (439) |
| hoisted declarations | 643 in 19 headers | 673 in 20 headers |
| **matches still matching after the merge** | **19,410 / 19,410** | **20,024 / 20,024** |
| equivalent/ code identical to its standalone build | (not checked) | 4,459 / 4,503; 44 wrapped ones can't be told (symbol not found standalone); 0 differ |

Run `build_tree.py` with `--rounds 16`. With the default 8, a run whose round 7 still has failures isolates every
function of those TUs (round `rounds - 1` is the last resort). The fallbacks converge in 10 rounds today (the
class merges cause more first-round compile errors, 116 TUs: mostly a merged class that one user's inline code
can't use), followed by two regression rounds (36, then 3 functions fall back). A full run takes 30-45 minutes,
most of it the standalone compiles of equivalent/ sources on a cold cache.

How the target function is found in a merged object: by its mangled-name prefix built from the
definition (`?vfunc_5@CSweepTrack@@`, `??1X@@` / `??_GX@@` for destructors and the deleting destructors
the compiler generates from them; 15,681), by the `@fn_<addr>@` namespace tag for wrapped functions
(8,686), any function of an isolated TU (142), and for 18 merged sources whose matched function is a
compiler-generated or inline-emitted one, any unclaimed function of the TU. A match that stops matching is
recompiled on its own to tell a regression from a function that doesn't match standalone.

**Equivalent functions.** A compile check by default. `equiv.verify(src, addr, symbol=..., obj_path=...)`
already runs on the merged object (`--equiv N`). On the first 300: 281 `equivalent`, 17 `fail`, 2 crash
inside equiv.py (`OverflowError`, the same crash standalone). All 17 failures are wrapped functions whose
bytes are identical to their standalone build, and they pass standalone; the failures are level-3 "local
passed as argument differs" at calls. Most likely equiv.py takes callee prototypes from the source by
mangled name, and the `fn_<addr>` namespace changes those names; it needs a namespace-aware lookup before
it can re-verify wrapped functions. Another difference from a standalone run: functions defined in the same
object run as our code, like inlined helpers, instead of being bound to the original's addresses.

## Platform layers (2026-10-15)

The tree is split by layer, as decided in [shipping.md §1](shipping.md#1-the-source-tree-roadmap-steps-2-and-4):
every object in `config/splits.json` has a `layer` (with `layer_evidence`, and `borderline` where the call was
close), and `gen_tree.py` writes `build/tree/src/<layer>/<dir>/<File>.cpp` and `build/tree/include/<layer>/<dir>.h`
(`common.h` stays shared). The verification build still compiles all three layers with MSVC 7.1.

| layer | objects | functions | bytes | TUs | verified merged / wrapped / isolated |
|---|---|---|---|---|---|
| `game` | 1,318 (incl. the `.text$yc` initializers) | 19,615 | 2,049 KB | 1,494 | 10,418 / 6,727 / 119 |
| `engine` | 433 | 7,342 | 1,123 KB | 470 | 4,831 / 1,704 / 17 |
| `platform/xbox` | 32 | 824 | 113 KB | 33 | 471 / 290 / 1 |
| `library` | 23 | — | 689 KB | not in the tree | |

How (`tools/infer_splits.py` step 7, details in [splits.md](splits.md#layers)):

- **game vs engine is link order.** The game's objects come first (up to XAPILIB at `0x208b9c`), Radical's
  libraries after it: Lua 5.1 core (`unk_212bb0`, identified by its error strings), choreo2, fight, radsound/`om`,
  radcore, Pure3D, sim (`physics`), pddi, radmovie, the Lua libraries (`unk_338d90`, `"Lua 5.1 (work)"`) and the
  math library after LIBCMT. By namespace the split is clean: no namespace has more than a few hundred COMDAT
  bytes on the other side. So `fight` and `physics` are `engine`, not `game` as the first sketch had it.
- **platform/xbox inside the four seam ranges.** Objects are cut at the seam range edges and where functions
  switch from Xbox classes / XDK calls to portable classes (5 cuts: the radsound HAL out of `unk_23fa40` and
  `unk_258b40`, `d3dDevice` out of `pddiBaseContext`, the Maya-ASCII parser after `BinkCallback`), then an object
  is `platform/xbox` when Xbox classes (`pure3d::d3d*`, `core::*XBox`/`Xbox*`, `movie::PlayerBink`/
  `RenderStrategyBink`/`BinkCallback`) or XDK-calling functions dominate it. The rest of the seam ranges
  (pddi base classes, radcore drives/files/requests/memory, radsound mixing) is portable `engine` code.
- **Borderline (9)**: two game-region objects whose dominant class is from an engine namespace
  (`pure3d/NonCopyable`, `om/Stream`), the `.text$yc` initializers (engine TUs' initializers too), and six engine
  objects that call the platform directly but are mostly portable (`core/TimerList` and the radcore time
  helpers in `unk_267280`: QPC; `core/Platform`: `XInitDevices`; `MemorySpaceAsyncRequest_Copy`:
  `GlobalMemoryStatus`; `unk_2719a0`: `OutputDebugStringA`; the Pure3D timer in `unk_291dc0`). Those 12 functions
  plus the 6 game leaks of platform-boundary.md are the layer leaks: shim functions before `game` + `engine`
  can build without the XDK.

**Seam interface**: [seams.md](seams.md) (`tools/seam_inventory.py`). Portable code reaches platform/xbox through
53 virtual slots (453 typed call sites; mostly `pddiRenderContext` 24 slots / 302 sites, `pddiDisplay`,
`pddiDevice`, `core::IControllerSystem`), 74 direct entry points (radcore thread/critical-section functions,
controller and Bink helpers, the radsound HAL's plain functions, `d3dCreateDevice`) and 18 leak functions.
No virtual slot exists only on an Xbox class. Of the 824 platform/xbox functions 597 are matched, 165
equivalent, 62 not yet.

**Tree after the layer split** (`build_tree.py --rounds 16`, log `build/layers-build.log`): **1,997 / 1,997 TUs
compile; 20,024 / 20,024 matches still match; 4,554 / 4,554 equivalent/ functions compile, 4,508 with code
identical to their standalone build, 46 wrapped ones can't be told, 0 differ.** Merged / wrapped / isolated
15,720 / 8,721 / 137 (64.0% merged; before: 15,699 / 8,686 / 142, with a few dozen fewer sources). Splits were
regenerated against the current `build/functions.csv` too (1,806 objects, was 1,803), which accounts for part of
the TU count change. 26 headers (was 20): the directory headers now exist per layer.

## Placeholder names (`tools/rename_placeholders.py`)

Invented stub names (`Obj`, `C`, `X`, `Owner`, `Base`, `g_vftable`, …) meant different things in different
sources and blocked about 11k merges. The tool gives them a per-source suffix:

```sh
build/venv/bin/python tools/rename_placeholders.py --dry-run     # what would change (and what is skipped, why)
build/venv/bin/python tools/rename_placeholders.py               # rewrite matches/ and equivalent/
```

- **Scheme:** `Obj` in `matches/0x00123450.cpp` becomes `Obj_123450`: the source's address in lower-case hex
  without leading zeros. Not the 8-digit form: `equiv.pick_symbol` takes the one object function whose name
  contains the 8-digit address, and gen_tree classifies `_xxxxxxxx` names as address names.
- **What is renamed:** file-level type names (class/struct/union/enum/typedef, also inside a namespace) and
  file-level variable names, when two or more sources define the name differently (iterated to a fixed point:
  a struct that mentions a renamed name changes text too), or when it is defined identically in several
  sources and the source's own function definition uses it in its name or parameters (clone-propagated
  sources). A name defined identically everywhere and used only in bodies keeps its name, so it can still be
  hoisted into a header.
- **Never renamed:** RTTI class and namespace names in any namespace (a global `struct FaceTargetAction` stands
  for `hulkfight::ai::FaceTargetAction`; fixing those is next-step 2), `include/gen/` classes, the class parts of
  `build/functions.csv` names (for variables, every identifier of them and the XDK symbols), address names
  (`FUN_`/`DAT_`/`g_xxxxxxxx`, …), `_`-prefixed and library names. Per source also: names on its `// equiv-*`
  lines (also inside mangled names: `PBUKey@@`), names used in preprocessor lines, everything in a file with
  function-like macros (`t##R` pastes names together), and names that are also member names (`p->X`, `Foo::X`).
- **Token-aware:** identifiers only (tools/cxx_items.py tokenizer); comments, strings and preprocessor lines
  stay byte-for-byte, so the `// STATUS:` and `// equiv-*` lines don't change.
- **Re-running** plans nothing on an unchanged corpus. New farm sources get the same treatment against the
  corpus; a source that copies a suffixed stub from another one keeps the name while the definition is
  identical, and gets its own suffix once it differs.

First run (2026-10-14): 13,951 sources rewritten (10,266 matches/, 3,685 equivalent/; list in
`build/rename-changed.txt`), 30,093 renames of 1,407 distinct names. All 10,266 matches still byte-match
(`compare.py`); every changed equivalent/ file was run with `equiv.py --inputs 300` and none regressed (the 19
that don't pass fail, crash or stay inconclusive the same way on the original source).

**Rule for new sources** (batch agents, farm prompts): give a stub type or global without a real name the
function's suffix from the start (`Obj_1b77e0`, `g_vftable_1b77e0`). Real names stay: RTTI classes in their
namespace (`fight::ParamValue`, not a global `ParamValue`), `FUN_`/`DAT_` names. Copying a stub from another
source is fine while it stays identical; once it changes, rename it to your own suffix.

## Stub reconciliation (2026-10-15)

Goal: let functions whose sources declare the same names differently share one set of declarations. Most of
the sources were fine: the same stub written in different but compatible ways, or spellings of one prototype.
So most of the work is in the generator; sources were changed only where a name was plainly wrong.

**Generator (`tools/gen_tree.py`, `tools/stub_layout.py`).**

- **Spellings are one variant** (`canonical_variant`): `unsigned` = `unsigned int`, `char const*` = `const char*`,
  `__cdecl`, top-level `const` on by-value parameters, `f(void)` = `f()`; for address names (`FUN_`/`DAT_`/
  `thunk_FUN_`) and a short list of CRT names (`atexit`, `__security_check_cookie`, …) also C vs C++ linkage,
  which changes only the symbol a call relocates against (masked by `compare.py`; `equiv.py` binds address names
  by their address); parameter names of inline definitions. The TU emits the most-used spelling.
  `FUN_0008d690` (90 wraps) and most of `ParamValue` are gone.
- **Layout-compatible class stubs are merged** (`merge_name`, `stub_layout.merge_variants`): two variants of a
  class that can't coexist become one definition with the union of the members the TU's functions use, when
  `stub_layout` (MSVC x86 /Zp8 layout model) shows that for each user every field it touches has the same
  offset, size and type, every virtual it calls has the same slot and signature, size matters only where the
  user needs it (`new`, `sizeof`, locals, arrays, `delete`), and constructors/destructors agree. Fields and
  slots a user doesn't touch may differ in name (`v0` vs `a`), so `virtual void v0()` and `virtual void a()`
  stubs merge. Anything the model doesn't understand (templates, bit-fields, virtual or multiple inheritance,
  overloaded virtuals, unknown by-value types) is never merged. The merged class is checked again against
  the TU's final declarations (`validate_tu`); 194 functions are wrapped by that check. 5,148 merges, 2,214
  refused (top reasons: an explicit `void* m_vptr` field against a polymorphic variant, different bases,
  a field one user reads with another type).
- **Placement `operator new` with and without `throw()`** can't share a TU (a `throw()` new makes
  `new (p) T` test for null) and must be global, so the object's less used form goes to a sibling TU
  `<File>.new_<form>.cpp` (234 functions, 67 TUs). The `operator new` conflict (124 wraps) is gone.
- **Global-scope stubs of namespaced RTTI classes** (`ParamValue` for `fight::ParamValue`) are now classified
  `rtti_stub` in conflicts.json instead of "invented".
- `build_tree.py` checks equivalent/ code against the standalone build and falls back functions whose code
  changed ([above](#how-a-tu-is-built)).

The tree is a generated artifact, so none of this changes what a source means: a merged class is a union of
stubs that each user's code compiles to the same bytes against, and the build proves it per function.

**Sources (`tools/reconcile_stubs.py`).** Clone-propagated sources ("Same code shape as 0x…, names are from
that function") define their donor's name, so two clones of one donor in one object define the same function.
Where the target's own name is spellable, the tool renames it, token-level (comments, strings, preprocessor
lines untouched), logged to `build/reconcile-stubs.log`, list in `build/stubs-changed.txt`, originals kept in
`build/stubs-orig/`:

- `clone-free`: `void FUN_00025410() {}` in `matches/0x0002c110.cpp` becomes `FUN_0002c110` (690 sources);
- `clone-class`: the source's stub class `A` becomes the target's class `B` when functions.csv names the
  function `B::m` with the same member name and a plain global `B` (444 sources, e.g. `CJointAction` ->
  `CJumpAction` in `matches/0x00013d40.cpp`).

It skips template targets (`Method1<CActorManager,bool,math::Vector>::vfunc_0`: 5,788 sources, no source
spelling for them yet), namespaced targets, names on `// equiv-*` or preprocessor lines, files with
function-like macros, and sources that already use the new name. Re-running it plans nothing. Run 2026-10-15:
1,134 sources changed, all in `matches/`; **all 1,134 still byte-match** (`compare.py`). No equivalent/ source
qualified, so no `equiv.py` runs were needed. Effect: about +400 merged functions.

**`include/gen/` migration:** done 2026-10-16, see the [next section](#includegen-migration-2026-10-16). (Before
it: `gen_headers.py --swap-test 200` had 119 of 200 vfunc matches surviving the rewrite; the generator wrapped
every source with an `#include`.)

## include/gen/ migration (2026-10-16)

Roadmap step 2: sources stop declaring private stubs of RTTI classes and define the real members on the
generated headers ([headers.md](headers.md)). Next steps 1-4 of the previous plan, in order.

**Generator (`tools/gen_tree.py`, `tools/build_tree.py`, `tools/cxx_items.py`).**

- A source may `#include "gen/<ns>.h"` or `"decls/<x>.h"`. The include is not a wrap reason any more: it is hoisted
  to the TU (emitted first, before the directory header), and the header's declarations (with what it includes)
  become *forced* variants in the TU: kept first, so a function whose own stub of a header class differs is
  wrapped, and conflicting stubs are kept out of the tree headers a gen TU includes. `build_tree.py` adds
  `/I include` (it was only on `INCLUDE`), and the object cache key covers `include/gen/` and `include/decls/`.
- Per TU the generator merges both ways, with the headers and without them (the sources on them then get their own
  TU), and keeps the better one (merged functions, half a point off per source sent to its own TU): 1,351 TUs are
  on include/gen/, 27 merge more without it.
- A source on include/gen/ that can't merge is isolated (`void ns::X::f()` and `template <> ...` can't go inside a
  `fn_<addr>` namespace): 465 functions. A wrapped source that only includes `decls/` gets the header's
  declarations inline in its namespace instead.
- `cxx_items` parses template-id declarators (`template <> bool fight::ParamBool<CFoo>::vfunc_6(int, int)`, key
  `fight::ParamBool<CFoo>::vfunc_6`; it used to key it `<CFoo>::vfunc_6`), and `build_tree.mangle_prefixes` finds
  explicit specializations by `?vfunc_6@?$ParamBool@` / `??_G?$Closure1@` / `??1?$...`.

**Sources (`tools/migrate_gen.py`).** Token-level, logged (`build/migrate-gen.log`), list in
`build/gen-migrated.txt`, originals in `build/gen-orig/`, every rewrite verified before it is kept (matches/:
`compare.py` MATCH; equivalent/: `equiv.py --inputs 3000` EQUIVALENT, the unchanged source run under the same
checker when it isn't). Rules and counts (9,159 sources: 8,308 matches/, 851 equivalent/):

| family / rule | what | matches/ | equivalent/ | rejected by verification |
|---|---|---|---|---|
| gen / `gen-swap` | stub of the target's class -> the header's class (`gen_headers.swap_transform`: `f_XX` fields, slot names, parameter casts) | 2,720 | 104 | 210 compile errors, 15 DIFF, 4 FAIL (equivalent/) |
| gen / `clone-template` | template target as an explicit specialization, `template <> bool fight::ParamFloatConstRange<CFoo>::vfunc_6(int a, int b)` (step 2) | 3,403 | 6 | 32 compile errors, 14 DIFF |
| gen / `gen-dtor` | plain scalar deleting destructor (base dtor, `delete` if `flags & 1`) -> `X::~X() {}`; MSVC generates the matched `??_G` from it | 1,873 | 0 | 13 DIFF |
| pin / `pin-decl` | own declarations of pinned address names -> `#include "decls/address.h"`; the private class of `DAT_004dd700` & co. renamed to the pinned type (`Global_10aa90` -> `World`) (step 3) | 160 | 745 | 95 compile errors (argument types: `FUN_002672f0(int, ...)`), 1 DIFF, 15 FAIL (4 of them fail unchanged too) |
| ns / `rtti-ns`, `clone-ns` | the global stub of the target's own namespaced RTTI class moves into its namespace; a clone's donor class becomes the target's (step 4) | 152 | 22 | 2 compile errors |

Not rewritten (skip reasons from the tool): 1,718 destructor slots with more than the plain body (vptr stores,
inlined base destructors, member releases), 926 sources using a field the header doesn't have, 356 with several
candidate definitions, 353 stubs with several bases, 160 slots whose header return type is `void`, plus small
classes. `include/gen/` itself did not change.

Step 4 is narrower than planned: moving a global stub into its namespace makes it collide with the include/gen/
class in a TU that includes the header (measured over all 879 candidates: -48 merged), so the ns family only touches
sources whose TU is not on include/gen/ (+83 merged).

**Tree** (`build_tree.py --rounds 16`, log `build/gen-build.log`): **2,499 / 2,499 TUs compile; 20,889 / 20,889
matches still match; 4,564 / 4,564 equivalent/ functions compile, 4,517 with code identical to their standalone
build, 47 wrapped ones can't be told (symbol not found standalone), 0 differ.** Fallback rounds converge in 8 plus
two regression rounds (72, then 2 functions: mostly a `~X() {}` now defined in the TU getting inlined into a
neighbour's call).

| | baseline (2026-10-15 build) | after (2026-10-16 build) |
|---|---|---|
| verified functions in the tree | 24,578 | 25,453 (farm lanes added sources meanwhile) |
| TU files | 1,997 | 2,499 (more isolated TUs and placement-new siblings) |
| merged / wrapped / isolated | 15,720 / 8,721 / 137 (64.0%) | **19,611 / 5,202 / 640 (77.0%)** |
| matches merged / wrapped / isolated | 12,919 / 7,044 / 61 (2026-10-15) | 17,226 / 3,153 / 510 |
| equivalent/ merged / wrapped / isolated | 2,780 / 1,642 / 81 (2026-10-15) | 2,385 / 2,049 / 130 |

Per step (generator only, `gen_tree` with the last build's fallback state, earlier steps' rewrites applied and
later ones reverted from `build/gen-orig/`; the build's own fallbacks shift the final numbers a little):

| after step | sources rewritten | merged / wrapped / isolated | merged % | TUs |
|---|---|---|---|---|
| 0 (generator change only) | 0 | 16,184 / 9,132 / 137 | 63.6% | 1,997 |
| 1 `gen-swap` + `gen-dtor` of plain classes | 3,016 | 16,374 / 8,707 / 372 | 64.3% | 2,232 |
| 2 `clone-template` + template `gen-dtor` | 8,106 | 19,627 / 5,387 / 439 | 77.1% | 2,299 |
| 3 `pin-decl` | 8,985 | 19,646 / 5,371 / 436 | 77.2% | 2,296 |
| 4 `rtti-ns` / `clone-ns` | 9,159 | 19,729 / 5,286 / 438 | 77.5% | 2,298 |

Step 1 alone gains little because a plain class's sources share TUs with the template clones and destructor
clones of the same stubs; step 2 is where the "same definition" wraps (4,111) go (674 left). equivalent/ merged
goes down (2,790 -> 2,385): 4,060 equivalent/ sources sit in TUs on include/gen/ and keep private stubs of the
header's classes (`Closure0`, `fight::ParamFloatConstRange`, `Node`, ...), mostly constructors and registration
functions the headers can't express (no constructors in include/gen/). Step 3 barely moves the count: pinning
`DAT_004dd700` turns 180 private type names into `World`, and the World stubs only merge where their layouts agree
(`World` now blocks 191 functions, `DAT_004dd700` none).

## Why functions still don't merge

After the include/gen/ migration (2026-10-16 build), of 5,842 functions that are not merged, the reasons (a
function can have more than one):

| reason | functions |
|---|---|
| a declaration conflicts with the TU's chosen variant (in a TU on include/gen/ that includes the header's class: a private stub of it) | 4,042 |
| the same definition as another function in the TU: mostly destructor-slot clones with more than the plain body, which `gen-dtor` doesn't take (`CSweepTrack`/`CTrack` 390, `TrackFactoryTemplate` 468, ...) | 674 |
| compile errors blamed by the build (incl. shared declarations) | 623 |
| on include/gen/ and not mergeable (its own TU) | 465 |
| helper definitions besides the function itself | 214 |
| the merged class would differ (validate_tu) | 77 |
| on include/gen/, but its TU merges more without the headers | 76 |
| code changed in the tree (regression rounds: an inlined `~X() {}`, a call sequence) | 73 |
| macros, using-directives, target defined inside a class | 88 |

## Conflicts

`build/tree/conflicts.json`: 2,434 names declared incompatibly (raw variants across all sources). Functions wrapped
because of them, by class (2026-10-15 -> 2026-10-16): RTTI classes 1,826 -> 2,949 (now mostly private stubs of a
class that include/gen/ declares in the same TU), global stubs of namespaced RTTI classes 1,103 -> 1,003, invented
names 431 -> 915, address names 1,179 -> 837.

Top remaining:

| symbol | wraps | what |
|---|---|---|
| `World` | 191 | the pinned type of `DAT_004dd700`: 280 sources' private stubs of the world object, merged only where layouts agree |
| `Node`, `FaceTargetAction`, `Action`, `Object` | 119, 95, 77, 61 | global stubs of RTTI classes whose variants really differ, mostly in equivalent/ and in functions that are not the class's own vfuncs |
| `CTrack`, `CSweepTrack`, `pure3d::NonCopyable` | 119, 102, 107 | destructor-slot clones with an inlined base destructor (vptr store + one call): no `~X() {}` form compiles to them on today's headers |
| `Closure0/1/2`, `Method0/1`, `fight::Param*`, `content::LoadInventory::DynamicCaster`, `FEThingsBase` | 47-82 each | constructors and registration functions (`new (mem) fight::ParamFloatConstRange<CFoo>("timeBegin", &CFoo::f)`) that need constructors the headers don't have |
| `Alloc`, `Obj`, `Find`, `zeroCondition` | 92, 69, 57, 55 | invented names whose variants really differ (linkage, signatures) |

## Next steps (ranked)

1. **Destructor slots beyond the plain body** (1,718 sources; the `CTrack`/`CSweepTrack`, `TrackFactoryTemplate`
   and `NonCopyable` clones are most of the remaining "same definition" and RTTI conflicts). Each pattern needs
   its `~X() { ... }` body: member releases go into the body, the vptr store and inlined base destructor need the
   base's destructor inline in include/gen/ (a header change, probe-checked) or an explicit body. Pattern-match
   them in `migrate_gen.dtor_transform` like the plain one, verify per source.
2. **Fields and constructors in include/gen/** (additively, through `gen_headers.py`): mine equivalent/ sources too
   (926 sources wait on a field the header lacks), and give the template families their constructors so the
   `fight::Param*` / `Method*` / `Closure*` registration functions and constructors can drop their stubs (the
   biggest group of equivalent/ conflicts in gen TUs). Re-run `gen_headers.py --probe` after each change.
3. **`World` and the other pinned types**: turn the merged World stubs into one `include/decls/` (or gen) class with
   the fields the sources agree on, then rewrite sources onto it the way `gen-swap` does for RTTI classes.
   Add casts at call sites for the 95 `pin-decl` compile errors (`FUN_002672f0(int, ...)`).
4. **Non-owner stubs onto include/gen/**: `swap_transform` only replaces the stub of the function's own class.
   Stubs of other RTTI classes used through pointers and virtual calls (`Node`, `Object`, ...) can map the same
   way (slot names by vtable index, `f_XX` fields); that also retires the global stubs step 4 left alone.
5. **Moving the tree into a committed `src/`**: the merged fraction is 77% now; still needed: a decision on COMDAT
   strays; `matches/`/`equivalent/` retired or generated from the tree; the build flags per TU recorded (today
   `// cl-flags:`); `build_tree.py` in CI (the regression check: matches + equivalent bytes vs standalone). Isolated
   TUs (640, 510 of them matches) should get folded back as their conflicts go.
6. Data: the `.rdata`/`.data`/`.bss` inventory, per-object data TUs and the plan to move sources from `extern DAT_x`
   to named declarations are in [data.md](data.md) (`tools/build_tree.py --data` builds and checks them next to the tree).
   Later: csplit + objdiff per object ([task 05](tasks/05-split-recovery.md)), and an
   `equiv.py` mode for tree objects (namespace-aware prototype lookup for wrapped functions; binding
   same-object neighbours to their original addresses).

**Rule for new sources (include/gen/):** if the function is a vfunc of an RTTI class, write it on the header:
`#include "gen/<ns>.h"` after the `// STATUS` comment block and define the real member (`void fight::WaitAction::vfunc_4()`,
`template <> bool fight::ParamBool<CFoo>::vfunc_6(int a, int b)`, `CFoo::~CFoo() {}` for a plain scalar deleting
destructor), using the header's slot names and `f_XX` fields and casting where your types differ
(`(*(T*)&this->f_10)`); no stub of that class. Helper types you still need get the placeholder suffix
(`Thing_1b77e0`). For `DAT_004dd700`, `DAT_0052c2a8`, `DAT_004dd6ec`, `FUN_0027b020`, `FUN_002672f0`, `FUN_001d04d0`
`#include "decls/address.h"` instead of declaring them, and name the object's type `World` / `Gfx` /
`Singleton_4dd6ec` in your stub. Don't add other `#include`s or a `using namespace`. If the header lacks a
field or the slot's signature disagrees, keep the stub (tools/migrate_gen.py can move it later).

**Rule for new sources** (in addition to the placeholder rule above): a clone keeps its donor's code but takes
the target's own name: `FUN_<own address>` for free functions, the target's class from functions.csv for
methods (`CJumpAction::vfunc_8`, not the donor's `CJointAction::vfunc_8`); for a template target, leave it to
`reconcile_stubs.py` (template rule pending). Write one spelling of a prototype you copy (`unsigned int`, no
`throw()` unless the original's callers need it); give address-named globals the type most sources already use
(`extern World* DAT_004dd700;`).
