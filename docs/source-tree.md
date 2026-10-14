# The source tree (first scaffold)

The per-function sources in `matches/` and `equivalent/` stay the source of truth. Three tools turn them
into a source tree with one translation unit per recovered object file, and check that every function
survives the merge. Plan: [shipping.md §1](shipping.md#1-the-source-tree-roadmap-steps-2-and-4). Splits:
[splits.md](splits.md). Numbers below are from 2026-10-14.

```sh
build/venv/bin/python tools/infer_splits.py      # config/splits.json + docs/splits.md      (~7 s)
build/venv/bin/python tools/gen_tree.py          # build/tree/{src,include}/ from the splits (~8 s)
build/venv/bin/python tools/build_tree.py        # generate, compile, fall back, re-verify   (~6 min warm, ~12 min cold)
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
| TU files | 2,022 (1,780 objects + 10 flag variants + 232 isolated functions); 13 hold only placeholders |
| TUs compiling | **2,021 / 2,022** |
| verified functions in the tree | 23,244 (18,794 matches, 4,450 equivalent); 4,326 placeholders |
| emitted merged / wrapped / isolated | 7,462 / 15,550 / 232 |
| TUs where every function is merged | 425 (233 of them with more than one function) |
| hoisted declarations | 732 in 18 headers (`common.h` 222, `global.h` 95, `hulkfight/motion.h` 62, `pure3d.h` 54, …); 18,789 stay at TU level |
| **matches still matching after the merge** | **18,794 / 18,794** (6,124 merged, 12,603 wrapped, 67 isolated) |
| equivalent/ functions compiling | 4,449 / 4,450 |

The one failing TU is `src/global/CPatrolPathManager.iso_00106e90.cpp`: `equivalent/0x00106e90.cpp` does
not compile on its own either (`FUN_0008d6d0` used without a declaration). It needs fixing in
`equivalent/`.

How the target function is found in a merged object: by its mangled-name prefix built from the
definition (`?vfunc_5@CSweepTrack@@`, `??1X@@` / `??_GX@@` for destructors and the deleting destructors
the compiler generates from them; 7,453), by the `@fn_<addr>@` namespace tag for wrapped functions
(15,550), any function of an isolated TU (231), and for 9 merged sources whose matched function is a
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

## Why so few functions merge

Of 15,782 functions that could not be merged, the generator's reasons:

| reason | functions |
|---|---|
| a declaration conflicts with the TU's chosen variant | 10,852 |
| the same definition as another function in the TU (clone-propagated sources reuse their donor's names, e.g. three functions in `hulkfight/unk_0185f0.cpp` all define `Set(Obj**, Obj*)`) | 4,386 |
| compile errors blamed by the build (mostly a second placement `operator new` with/without `throw()`; that changes codegen, a `throw()` new gets a null check) | 346 |
| helper definitions besides the function itself (they could be inlined into neighbours: MSVC 7.1 `/O2` inlines any function defined anywhere in the TU) | 149 |
| macros, using-directives, target defined inside a class | 75 |

## Conflicts

`build/tree/conflicts.json` lists **3,302 names declared incompatibly** across the verified sources:
1,954 invented placeholder names, 700 address names (`FUN_`/`DAT_`/`thunk_`), 648 RTTI class names. 1,735
of them actually blocked a merge inside some TU.

| class | names that blocked a merge | functions wrapped because of them |
|---|---|---|
| invented (`Obj`, `C`, `X`, `Owner`, `Item`, `Entry`, `Base`, `Node`, …) | 918 | 11,191 |
| RTTI classes (`ParamIntConstRange`, `TrackFactoryTemplate`, `ParamEnumConstList`, `Closure*`, `Method*`, `FEThingsBase`, `pure3d::pddiBaseContext`, …) | 391 | 3,348 |
| address names | 426 | 1,579 |

(A function counts once per conflicting name it uses, so the column sums to more than 10,852.)

Top conflicts by functions blocked:

| symbol | variants | sources | wrapped | e.g. |
|---|---|---|---|---|
| `Obj` | 2,449 | 3,259 | 2,402 | `struct Obj { void f(); };` vs `class Obj : public Base { … };` |
| `ParamIntConstRange` | 4 | 1,418 | 704 | two stub layouts, one with a member-function pointer at +0x10 |
| `TrackFactoryTemplate` | 42 | 1,034 | 524 | `struct { void* m_vptr; … }` vs `class { virtual void vf0(); … }` |
| `ParamEnumConstList` | 10 | 677 | 504 | |
| `C`, `X`, `Owner`, `Item`, `Entry`, `Target`, `Base`, `Node` | 290–600 each | | 210–420 each | invented helper types |
| `ParamValue` | 18 | 1,084 | 263 | `virtual void v0()…` vs `virtual void a()…` (same slots, different names) |
| `DAT_004dd700` | 40 | 375 | 136 | `extern World*` vs `extern Globals*` |
| `FUN_0008d690` (allocator) | 31 | 993 | 84 | C++ vs `extern "C"` linkage, `unsigned` vs `unsigned int` |
| `FUN_001d04d0` | 20 | 179 | 70 | `char(const char*)` vs `char(const void*) throw()` |
| `DAT_004d9968` | 6 | 295 | 46 | C++ vs `extern "C"` linkage |
| `FUN_00344e74` | 49 | 215 | 36 | five different parameter lists |
| `thunk_FUN_00267090` (delete helper) | 65 | 2,341 | 24 | one overload per pointer type; coexist as overloads, so rarely blocking |

**`include/gen/` is not used yet.** No stub agreed with it closely enough to swap blindly: the stubs name
virtual slots and fields freely (`v0`, `a`, `f0`, `pad`), while `include/gen/` has `vfunc_N(int, …)`
signatures and only proven fields. Swapping is the job of `gen_headers.py --swap-test`'s rewrite
(`swap_transform`), applied per function and re-verified, which is next-step 2 below.

## Next steps (ranked)

1. **Rename invented placeholder types per function** (`Obj` → `Obj_0x00012400` or a real name) in
   `matches/` and `equivalent/`. Mangled names change, code doesn't, so it is safe and mechanical
   (re-verify with `compare.py`). The invented names account for 918 blocking names and about 11k wrapped
   functions; `Obj` alone blocks 2,402.
2. **Move the RTTI stubs onto `include/gen/`**, starting with the fight parameter/factory families:
   `ParamIntConstRange`, `TrackFactoryTemplate`, `ParamEnumConstList`, `ParamValue`, `Closure*`/`Method*`
   cover 2,300+ wrapped functions. Use `gen_headers.swap_transform` per function, recompile, keep what
   still matches. This is roadmap step 2 and it also fixes the next item for those classes.
3. **Give clone-propagated sources their own names.** 4,386 functions are wrapped only because a clone
   reuses its donor's definition name in the same TU. `tools/clone_matches.py` /
   `clone_equivalent.py` could emit the target's own name (`CMoveAddYTrack::vfunc_5`, from functions.csv).
4. **Pin the address-name types**: one declaration per `FUN_`/`DAT_` (426 blocking names). A
   `include/decls/` of agreed prototypes for the most used ones (`FUN_0008d690`, the allocator,
   `thunk_FUN_00267090`, the delete helper, `DAT_004dd700`, `DAT_004d9968`, `FUN_001d04d0`) would remove most
   of the 1,579 wraps; `DAT_004dd700` being `World*` in some files and `Globals*` in others is a real type
   question.
5. **Fix `equivalent/0x00106e90.cpp`** (doesn't compile standalone).
6. **Moving the tree into a committed `src/`** needs: the merged fraction well above today's third (steps
   1–4), so the tree reads as source rather than namespaces of stubs; a decision on COMDAT strays
   (keep them where the linker put them, as now, or in their class's home); `matches/`/`equivalent/` either
   retired or generated from the tree; the build flags per TU recorded (today `// cl-flags:` lines); and
   `build_tree.py` wired into CI so a match that stops matching after a source edit is caught. Splits
   themselves are good enough to start: a wrong cut costs nothing in codegen.
7. Later: `.rdata`/`.data` splits, csplit + objdiff per object ([task 05](tasks/05-split-recovery.md)),
   and an `equiv.py` mode for tree objects: namespace-aware prototype lookup (wrapped functions) and
   binding same-object neighbours to their original addresses.
