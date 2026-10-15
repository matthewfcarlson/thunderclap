# The source tree (first scaffold)

The per-function sources in `matches/` and `equivalent/` stay the source of truth. Three tools turn them
into a source tree with one translation unit per recovered object file, and check that every function
survives the merge. Plan: [shipping.md §1](shipping.md#1-the-source-tree-roadmap-steps-2-and-4). Splits:
[splits.md](splits.md). Numbers below are from 2026-10-15, after the placeholder rename
([below](#placeholder-names-toolsrename_placeholderspy)) and the stub reconciliation
([below](#stub-reconciliation-2026-10-15)).

```sh
build/venv/bin/python tools/infer_splits.py      # config/splits.json + docs/splits.md      (~7 s)
build/venv/bin/python tools/gen_tree.py          # build/tree/{src,include}/ from the splits (~8 s)
build/venv/bin/python tools/build_tree.py --rounds 16  # generate, compile, fall back, re-verify (~25 min warm, ~45 min cold)
build/venv/bin/python tools/build_tree.py --equiv 300   # also run equiv.py on 300 equivalent/ functions
build/venv/bin/python tools/build_tree.py --only src/global/CAction.cpp  # one TU, current tree
build/venv/bin/python tools/reconcile_stubs.py [--apply]   # clone names in matches/ + equivalent/ (re-verify what it changes)
```

`build_tree.py` regenerates the tree itself (from an empty fallback state), so it is the one command to
run. Everything under `build/` is regenerated; nothing in it is edited by hand.

| Output | What |
|---|---|
| `config/splits.json` | object ranges in `.text` (committed) |
| `build/tree/src/<dir>/<File>.cpp` | one TU per game object; `<File>.O1.cpp` for functions with other `cl-flags`; `<File>.iso_<addr>.cpp` for isolated functions |
| `build/tree/include/<dir>.h`, `common.h` | hoisted shared declarations |
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

**`include/gen/` migration: measured, not started.** `gen_headers.py --swap-test 200` (rewrite a vfunc match to
use include/gen/ instead of its stub, recompile): 119 of 200 still match, 2 differ, 3 don't compile, 76 can't
be rewritten (59 destructor slots, 8 multiple/virtual bases, the rest fields or parameters the header lacks).
96% of the rewritable ones match, so the migration is viable; but a migrated source `#include`s a header, and
the generator wraps every source with preprocessor lines. The generator needs an include/gen/ mode first
(treat `#include "gen/…"` as a TU-level include, make the tree's include path see `include/gen/`), then the
swap can run per function with `build_tree.py` re-verifying. That is the next step below.

## Why functions still don't merge

Of 8,828 functions that are not merged, the reasons (a function can have more than one):

| reason | functions |
|---|---|
| the same definition as another function in the TU: clone-propagated sources whose target is a template instantiation (`Method2<CActorManager,void,const_char_*,math::Vector>::vfunc_0` defined as `CCollisionAction::vfunc_2`, ~3,000; `ParamIntConstRange::vfunc_6`/`vfunc_2` ~1,000 for `fight::ParamIntConstRange<X>`) | 4,113 |
| a declaration conflicts with the TU's chosen variant | 3,740 |
| compile errors blamed by the build (a merged class that one user's code can't use, e.g. an inline body naming a member the merged layout spells differently) | 492 |
| the merged class would differ for this function (validate_tu) | 194 |
| helper definitions besides the function itself (MSVC 7.1 `/O2` inlines any function defined anywhere in the TU) | 192 |
| code changed in the tree (36 + 3 caught by the regression rounds) | 38 |
| macros, using-directives, target defined inside a class | 82 |

## Conflicts

`build/tree/conflicts.json` lists 2,500 names declared incompatibly across the verified sources (raw
variants; most are now resolved inside the TUs). Names that still blocked a merge somewhere, and the
functions wrapped because of them:

| class | names blocking (before → after) | wraps (before → after) |
|---|---|---|
| RTTI classes (template families, `Closure*`/`Method*`, `FEThingsBase`, …) | 402 → 381 | 3,510 → 1,826 |
| global-scope stubs of namespaced RTTI classes (`rtti_stub`; counted as "invented" before) | — → 293 | — → 1,103 |
| invented names (functions like `Alloc`, `cleanup`) | 539 → 138 | 3,152 → 431 |
| address names | 438 → 292 | 1,868 → 1,179 |

Top remaining:

| symbol | wraps | what |
|---|---|---|
| `TrackFactoryTemplate` | 434 | one non-template stub for 245 instantiations of `fight::TrackFactoryTemplate<T>`, written as `struct { void* m_vptr; … }` in some sources and as a polymorphic class in others: the code differs (explicit vs virtual), not mergeable |
| `DAT_004dd700` | 170 | `extern World*` in 101 sources, a source-private stub type in the rest (`Context*`, `Game*`, `Global_10aa90*`, `unsigned`): a real type question |
| `Node`, `FaceTargetAction`, `Action`, `Object` | 115, 96, 81, 67 | global stubs of RTTI classes whose variants really differ (different bases or field types at one offset) |
| `Method0/1`, `Closure0/1/2` | 70–108 each | template families written as non-template stubs |
| `ParamIntConstRange` | 101 (was 703) | template family; the rest is `vfunc_6`/`vfunc_2` clones |
| `FUN_0027b020`, `FUN_001d04d0`, `FUN_002672f0` | 51, 45, 28 | return or parameter types really differ (`unsigned __int64` vs `__int64`, `char` vs `unsigned char`, `const char*` vs `unsigned int`), or `throw()` on the declaration (changes caller EH code, so not treated as a spelling) |
| `Alloc` | 54 | C vs C++ linkage of an invented name (not an address name, so not unified) and `Object*(int)` vs `void*(unsigned)` |

## Next steps (ranked)

1. **include/gen/ mode in the generator, then the swap.** Let a source use `include/gen/` (an `#include
   "gen/<ns>.h"` hoisted to the TU, `include/` on the tree's include path), then run
   `gen_headers.swap_transform` per function through `tools/reconcile_stubs.py`-style logged rewrites, rebuild,
   keep what still matches (swap-test: 60% of vfunc matches today, 96% of those it can rewrite). This is
   roadmap step 2.
2. **Template clones onto include/gen/ templates** (~4,100 "same definition" + the `TrackFactoryTemplate`,
   `Method*`, `Closure*`, `Param*ConstRange` conflicts, ~5,000 functions). include/gen/fight.h already declares
   the families (`template <class T0> class TrackFactoryTemplate`, 245 instantiations). A clone of
   `fight::TrackFactoryTemplate<CDriftTrack>::vfunc_5` becomes
   `template<> void* fight::TrackFactoryTemplate<CDriftTrack>::vfunc_5() { … }`: its own mangled name, no stub,
   no duplicate. Needs step 1 and a `clone-template` rule in `reconcile_stubs.py`.
3. **Pin the address-name types** (1,179 wraps): `DAT_004dd700` (`World*` in 101 sources; the other 30-odd
   types are private stubs of the same object and should become `World` fields), `DAT_0052c2a8`,
   `DAT_004dd6ec`, `FUN_0027b020` (`unsigned __int64(const char*)`, a string hash), `FUN_001d04d0`. Best as
   prototypes in include/gen/ (or an `include/decls/`) that sources include, re-verified per source.
4. **Global stubs of namespaced RTTI classes** (1,103 wraps): put them in their namespace and on include/gen/
   (same as step 1).
5. **Moving the tree into a committed `src/`** needs: the merged fraction well above today's 64% (steps 1-4), so
   the tree reads as source rather than namespaces of stubs; a decision on COMDAT strays; `matches/`/
   `equivalent/` retired or generated from the tree; the build flags per TU recorded (today `// cl-flags:`);
   and `build_tree.py` in CI. The regression check (matches + equivalent bytes vs standalone) is the CI gate.
6. Later: `.rdata`/`.data` splits, csplit + objdiff per object ([task 05](tasks/05-split-recovery.md)), and an
   `equiv.py` mode for tree objects (namespace-aware prototype lookup for wrapped functions; binding
   same-object neighbours to their original addresses).

**Rule for new sources** (in addition to the placeholder rule above): a clone keeps its donor's code but takes
the target's own name: `FUN_<own address>` for free functions, the target's class from functions.csv for
methods (`CJumpAction::vfunc_8`, not the donor's `CJointAction::vfunc_8`); for a template target, leave it to
`reconcile_stubs.py` (template rule pending). Write one spelling of a prototype you copy (`unsigned int`, no
`throw()` unless the original's callers need it); give address-named globals the type most sources already use
(`extern World* DAT_004dd700;`).
