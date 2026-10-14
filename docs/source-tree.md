# The source tree (first scaffold)

The per-function sources in `matches/` and `equivalent/` stay the source of truth. Three tools turn them
into a source tree with one translation unit per recovered object file, and check that every function
survives the merge. Plan: [shipping.md §1](shipping.md#1-the-source-tree-roadmap-steps-2-and-4). Splits:
[splits.md](splits.md). Numbers below are from 2026-10-14, after the placeholder rename
([below](#placeholder-names-toolsrename_placeholderspy)).

```sh
build/venv/bin/python tools/infer_splits.py      # config/splits.json + docs/splits.md      (~7 s)
build/venv/bin/python tools/gen_tree.py          # build/tree/{src,include}/ from the splits (~8 s)
build/venv/bin/python tools/build_tree.py --rounds 16  # generate, compile, fall back, re-verify (~6 min warm, ~15 min cold)
build/venv/bin/python tools/build_tree.py --equiv 300   # also run equiv.py on 300 equivalent/ functions
build/venv/bin/python tools/build_tree.py --only src/global/CAction.cpp  # one TU, current tree
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
function is isolated. It regenerates and recompiles until nothing new is blamed (4 rounds today); a TU that
still fails after the last round has all its functions isolated.

## Current numbers

| | |
|---|---|
| objects in `config/splits.json` | 1,803: 1,779 game, 1 game-init, 23 library |
| TU files | 2,004 (1,780 objects + 10 flag variants + 214 isolated functions); 10 hold only placeholders |
| TUs compiling | **2,003 / 2,004** |
| verified functions in the tree | 23,742 (19,235 matches, 4,507 equivalent) |
| emitted merged / wrapped / isolated | **12,810 / 10,718 / 214** (before the rename: 7,462 / 15,550 / 232 of 23,244) |
| TUs where every function is merged | 514 (325 of them with more than one function; before: 425 / 233) |
| hoisted declarations | 646 in 19 headers (before: 732 in 18; per-source names hoist less) |
| **matches still matching after the merge** | **19,235 / 19,235** (10,606 merged, 8,573 wrapped, 56 isolated) |
| equivalent/ functions compiling | 4,506 / 4,507 |

Run `build_tree.py` with `--rounds 16`. With the default 8, a run whose round 7 still has failures isolates every
function of those TUs (round `rounds - 1` is the last resort): one run on 2026-10-14 isolated 1,102 functions of
12 TUs that compile a round later. The fallbacks converge in 7 rounds today.

The one failing TU is `src/global/CPatrolPathManager.iso_00106e90.cpp`: `equivalent/0x00106e90.cpp` does
not compile on its own either (`FUN_0008d6d0` used without a declaration). It needs fixing in
`equivalent/`.

How the target function is found in a merged object: by its mangled-name prefix built from the
definition (`?vfunc_5@CSweepTrack@@`, `??1X@@` / `??_GX@@` for destructors and the deleting destructors
the compiler generates from them; 12,798), by the `@fn_<addr>@` namespace tag for wrapped functions
(10,718), any function of an isolated TU (213), and for 12 merged sources whose matched function is a
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

## Why functions still don't merge

Of 10,932 functions that are not merged, the generator's reasons (first reason per function):

| reason | functions |
|---|---|
| a declaration conflicts with the TU's chosen variant | 6,408 |
| the same definition as another function in the TU (clone-propagated sources define the same RTTI method, e.g. several `ParamIntConstRange::vfunc_2()`) | 3,927 |
| compile errors blamed by the build (mostly a second placement `operator new` with/without `throw()`; that changes codegen, a `throw()` new gets a null check) | 168 |
| helper definitions besides the function itself (they could be inlined into neighbours: MSVC 7.1 `/O2` inlines any function defined anywhere in the TU) | 150 |
| macros, using-directives, target defined inside a class | 65 |

## Conflicts

`build/tree/conflicts.json` lists **2,225 names declared incompatibly** across the verified sources (3,302
before the rename): 851 that gen_tree classifies as invented, 714 address names (`FUN_`/`DAT_`/`thunk_`), 660
RTTI class names. 1,382 of them actually blocked a merge inside some TU (1,735 before).

| class | names that blocked a merge | functions wrapped because of them |
|---|---|---|
| RTTI classes (`ParamIntConstRange`, `TrackFactoryTemplate`, `ParamEnumConstList`, `Closure*`, `Method*`, `FEThingsBase`, `pure3d::pddiBaseContext`, …) | 400 | 3,505 |
| "invented" to gen_tree's classifier, which only knows full RTTI names. Nearly all are global-scope stubs of namespaced RTTI classes (`fight::ParamValue`, `fight::Node`/`scenegraph::Node`, `core::Object`, `CActorManager`, `hulkfight::ai::FaceTargetAction`, `fight::Action`, `Render::World`, …: 2,635 wraps); the rest are functions (`operator new` with/without `throw()`, `Alloc`, `atexit`, `__security_check_cookie`) | 545 | 3,142 |
| address names | 437 | 1,855 |

(A function counts once per conflicting name it uses, so the column sums to more than 6,408.)

Top conflicts by functions blocked:

| symbol | variants | sources | wrapped | e.g. |
|---|---|---|---|---|
| `ParamIntConstRange` | 4 | 1,418 | 703 | two stub layouts, one with a member-function pointer at +0x10 |
| `TrackFactoryTemplate` | 72 | 1,034 | 524 | `struct { void* m_vptr; … }` vs `class { virtual void vf0(); … }` |
| `ParamEnumConstList` | 10 | 677 | 504 | |
| `ParamValue` (`fight::ParamValue`) | 18 | 1,084 | 263 | `virtual void v0()…` vs `virtual void a()…` (same slots, different names) |
| `Node` (`fight::Node`, `pure3d::scenegraph::Node`) | 321 | 421 | 232 | |
| `DAT_004dd700` | 277 | 382 | 174 | `extern World*` vs `extern Globals*` |
| `Object` (`core::Object`, `Render::Object`) | 312 | 385 | 153 | |
| `operator new` | 33 | 1,770 | 124 | placement new with and without `throw()` |
| `CActorManager`, `FaceTargetAction`, `Action` | 24–149 | | 85–112 each | global stubs of RTTI classes |
| `FUN_0008d690` (allocator) | 60 | 996 | 90 | C++ vs `extern "C"` linkage, `unsigned` vs `unsigned int` |
| `FUN_0027b020` | 85 | 222 | 81 | |
| `FUN_001d04d0` | 21 | 191 | 76 | `char(const char*)` vs `char(const void*) throw()` |

**`include/gen/` is not used yet.** No stub agreed with it closely enough to swap blindly: the stubs name
virtual slots and fields freely (`v0`, `a`, `f0`, `pad`), while `include/gen/` has `vfunc_N(int, …)`
signatures and only proven fields. Swapping is the job of `gen_headers.py --swap-test`'s rewrite
(`swap_transform`), applied per function and re-verified, which is next-step 2 below.

## Next steps (ranked)

1. **Done: invented placeholder names renamed per source** (`tools/rename_placeholders.py`, above). Re-run it
   when farm lanes add sources, and re-verify what it changes.
2. **Move the RTTI stubs onto `include/gen/`**, including the global-scope stubs of namespaced classes
   (`ParamValue`, `Node`, `Object`, `CActorManager`, `FaceTargetAction`, `Action`, `World`, …: 2,635 wraps),
   starting with the fight parameter/factory families:
   `ParamIntConstRange`, `TrackFactoryTemplate`, `ParamEnumConstList`, `ParamValue`, `Closure*`/`Method*`
   cover 2,300+ wrapped functions. Use `gen_headers.swap_transform` per function, recompile, keep what
   still matches. This is roadmap step 2 and it also fixes the next item for those classes.
3. **Give clone-propagated sources their own names.** 3,927 functions are wrapped only because a clone
   reuses its donor's definition name in the same TU (after the rename, nearly all RTTI methods). `tools/clone_matches.py` /
   `clone_equivalent.py` could emit the target's own name (`CMoveAddYTrack::vfunc_5`, from functions.csv).
4. **Pin the address-name types**: one declaration per `FUN_`/`DAT_` (437 blocking names). A
   `include/decls/` of agreed prototypes for the most used ones (`FUN_0008d690`, the allocator,
   `thunk_FUN_00267090`, the delete helper, `DAT_004dd700`, `DAT_004d9968`, `FUN_001d04d0`) would remove most
   of the 1,855 wraps; `DAT_004dd700` being `World*` in some files and `Globals*` in others is a real type
   question.
5. **Fix `equivalent/0x00106e90.cpp`** (doesn't compile standalone).
6. **Moving the tree into a committed `src/`** needs: the merged fraction well above today's 54% (steps
   2–4), so the tree reads as source rather than namespaces of stubs; a decision on COMDAT strays
   (keep them where the linker put them, as now, or in their class's home); `matches/`/`equivalent/` either
   retired or generated from the tree; the build flags per TU recorded (today `// cl-flags:` lines); and
   `build_tree.py` wired into CI so a match that stops matching after a source edit is caught. Splits
   themselves are good enough to start: a wrong cut costs nothing in codegen.
7. Later: `.rdata`/`.data` splits, csplit + objdiff per object ([task 05](tasks/05-split-recovery.md)),
   and an `equiv.py` mode for tree objects: namespace-aware prototype lookup (wrapped functions) and
   binding same-object neighbours to their original addresses.
