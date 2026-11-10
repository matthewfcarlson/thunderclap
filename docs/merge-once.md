# Merge once: the merged tree as the source of truth

Status: stage 1 (tools) done, stage 2 (design + private prototype) in this document, stage 3 (the flip) a proposal that
needs the user's explicit OK. Plan approved 2026-11-09 (build4). Background: [source-tree.md](source-tree.md) (how the
tree is generated and verified today), [consolidation-plan.md](consolidation-plan.md) (why functions are wrapped),
[wine-build.md](wine-build.md) "Build speed (build3)" (where a proof's time goes).

## Why

Every proof today regenerates the merged tree from 27k per-function files: `tools/build_tree.py` merges, compiles with
MSVC 7.1, blames compile errors, falls functions back (merged -> wrapped -> isolated) and repeats, 9-20 rounds, 19-55
minutes of a studio proof whenever a shared header changes (build3 measured 2,030-2,850 s for a fresh build with changed
sources). The merge is deterministic given the fallback state, and almost every function lands where it landed last time.
Doing it once and committing the result removes the rounds from every build, makes the tree the place work happens
(renames, 64-bit fixes, `#if defined(HULK_PTR64)` branches, record types land in one file instead of being re-merged), and
keeps the per-function proof by re-verifying only TUs whose text or headers changed.

## Stage 1: the checkers take a tree TU (done)

```sh
build/venv/bin/python tools/compare.py src/game/global/CAction.cpp 0x00012340       # the function inside the TU's object
build/venv/bin/python tools/verify_relocs.py src/game/global/CAction.cpp --addr 0x00012340 --json
build/venv/bin/python tools/equiv.py src/game/global/CAction.cpp 0x00012340 [--wine | --x64] --json
build/venv/bin/python tools/tree_tu.py blocks TU.cpp                      # its functions: address, kind, mode, lines, symbol
build/venv/bin/python tools/tree_tu.py check TU.cpp --relocs [--equiv N [--wine|--x64]]   # every function of one TU
build/venv/bin/python tools/tree_tu.py verify ROOT [--changed-since REF] --relocs --jobs N --out OUT.jsonl
build/venv/bin/python tools/tree_tu.py pin ROOT --records OUT.jsonl       # record each function's symbol in the TU
build/venv/bin/python tools/tree_tu.py materialize --root ROOT --out build/tree   # a committed tree as build_tree's output
```

(Paths above are the committed layout; today the same commands take `build/tree/src/...`.)

- **Which function.** A TU is recognised by its block lines (`// 0xADDR NAME (SIZE B): matches/0xADDR.cpp [wrapped:
  why]`, written by gen_tree). The function at an address is found the way `build_tree.py` finds it, so a tree that
  verified there verifies here: a pinned `// sym: <mangled name>` line after the block line, else the mangled-name
  prefixes of the block's out-of-line definitions (parsed from the TU itself with their namespaces), the `@fn_<addr>@`
  namespace of a wrapped block, any function of an isolated TU, and the best-scoring unclaimed function for a merged
  block whose prefixes find nothing. Two blocks on one symbol with different original bytes are resolved through their
  standalone sources while those exist (build_tree.unique_symbols); after the flip the pinned symbol is what tells them
  apart, which is why `pin` runs before the per-function files are retired.
- **Objects.** `build_tree.compile_tu` (MSVC 7.1 under wibo, compare.py's flags + the TU's `// cl-flags:` line, `/I` the
  tree's include/ and the repo's include/), cached by content in `build/tree-cache/obj/` (text, flags, every reachable
  header): the same objects a tree build makes. `--wine` compiles the TU with the Wine build's clang flags (equiv.compile_native
  with the tree's include/ first), `--x64` the 64-bit pair (equiv64, the tree's include/ on every compile).
- **Directives.** `// equiv-map:`, `equiv-conv:`, `equiv-dead:` are read from the function's own block only (a TU holds
  hundreds of functions). `HULK_GEN_TREE_NOTES=1` makes gen_tree keep a merged source's notes (its leading comment block:
  `// STATUS:`, provenance, and every `equiv-*` line) after the block line; wrapped and isolated blocks are verbatim anyway.
- **Incremental.** `tree_tu.py verify` caches each TU's check records in `build/tree-cache/tuverify/` by the object's
  key, the TU's block records and the checker code (tree_tu, build_tree, compare, verify_relocs, xbe, disasm, the XBE,
  functions.csv): a TU whose text and headers did not change is not compiled or checked again. `--changed-since REF`
  narrows the walk to the TUs git says changed (all of them when a header changed).
- `--vs-standalone` (while matches/ and equivalent/ exist): build_tree's check that an equivalent function's code in
  the TU is the code its own source compiles to (`same` carries the source's proof over).

Identity with the standalone tools: see [Results](#results) (sample of 200 matches + 200 equivalents across merged,
wrapped and isolated emission).

## Stage 2: the committed tree (design)

### Layout

```
src/game/<dir>/<File>.cpp            one TU per recovered object (config/splits.json), functions in address order
src/game/<dir>/<File>.O1.cpp         a sibling per other `// cl-flags:` set (the first line repeats the flags)
src/game/<dir>/<File>.new_<form>.cpp the placement-new siblings
src/game/<dir>/<File>.iso_<addr>.cpp an isolated function (its own TU, until its conflict is fixed)
src/engine/...                       the same for Radical's libraries (Lua, choreo2, fight, radsound, radcore, Pure3D, sim, pddi)
src/platform/xbox/...                the Xbox seam implementations (pddi D3D8, radcore Xbox, radsound HAL, Bink player)
src/platform/sdl/...                 unchanged (the native platform layer)
include/tree_prelude.h               the tree's size_t / HULK_NEW_THROW (included first where needed)
include/common.h                     declarations shared by several directories (hoisted by gen_tree)
include/{game,engine,platform/xbox}/<dir>.h   declarations shared within a directory
include/gen/, include/decls/, include/compat/ unchanged (RTTI classes, pinned names and data declarations, compat)
```

No path collides with what is committed today (include/ has only compat/ decls/ gen/; src/ only platform/sdl/). The tree
root is the checkout (`tools/tree_tu.py` finds it by include/tree_prelude.h), so `/I include` reaches both the tree headers
and include/gen etc., exactly as `build/tree/include` + `include` do now.

### A function in the tree

```cpp
// 0x00011000 FUN_00011000 (10 B): equivalent
// sym: ?FUN_00011000@fn_ff0a839e@@YAMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// equiv-map: ...
float __cdecl FUN_00011000(float value) { ... }
```

The block line keeps today's form; after the flip it names the kind instead of a file (`matches/0x....cpp` becomes
`matches`/`equivalent`, with git history as the pointer to the old file). `// sym:` is the function's symbol in its
TU's MSVC object (written by `tree_tu.py pin` from a full verification; a TU edit that renames the function makes the
check fall back to the prefix lookup and report `pin_missing`, and `pin` rewrites the line). The notes (STATUS,
provenance, equiv directives) live in the block.

**What "verified" means after the flip** (unchanged in strength):

- matches: `compare.py TU ADDR` MATCH + `verify_relocs.py` ok, on the TU's object (`tree_tu.py verify --relocs`).
- equivalent: the function's code in the TU's object is the code that was proven (bytes, relocation positions and
  kinds, address targets: build_tree.same_code), or `equiv.py TU ADDR` passes again (3,000 inputs, plus the `--wine`
  gate at 600, as for a promotion). Proposed: a per-function code hash next to the symbol (`// sym: NAME @code12hex`)
  so a TU edit that leaves a function's code unchanged needs no new equiv run (the same rule build_tree uses against the
  standalone build today), and one that changes it is re-proven before it lands.

### Wrapped and isolated functions

They stay as they are in the committed tree (wrapped: the original source verbatim in `namespace fn_<addr> { }`;
isolated: its own `.iso_<addr>.cpp`). Clean-up is one function at a time and needs no generator: edit the block (drop its
private stubs for the TU's or include/gen's declarations, move it out of its namespace), then `tree_tu.py check TU --relocs`
(matches) / the code-hash or `equiv.py TU ADDR` (equivalent). A tool can automate the common case later (`tree_tu.py
merge 0xADDR`: try the block merged, keep it only if the TU still compiles and every function's code is unchanged). The
same holds for the things build5 prepares (renames that turn wrapped functions into merged ones): before the flip they are
edits to per-function files and the generated tree picks them up; after it, the same rename is applied to the TU.

### 64-bit branches, records, include/gen and include/decls

Nothing changes in kind: `#if defined(HULK_PTR64)` branches, `hulk_intptr` and friends, and the typed records of
include/decls/data/ (records.h, lua.h, script.h) are source text, so they are in the blocks verbatim (sources with
top-level preprocessor lines are wrapped today, so their text is untouched); include/gen/ and include/decls/ stay where
they are and are reached the same way. The difference is where the next edit goes: into the TU, checked by
`tree_tu.py check` (MSVC, 32-bit) and `equiv.py TU ADDR --x64` (the 64-bit pair).

### Generated data stays out of git

The tree has no data contents: gen_tree already turns a merged source's variable definitions into `extern`
declarations (the data TUs own the data), the data TUs (`build/data/src/...`, `tools/data_gen.py` from the player's
XBE) stay a local generated step that the builds read from build/, and include/decls/data/ (names, types, sizes) is
what is committed today. The tree's text is a function of committed inputs only (the sources, config/splits.json, the
function names and sizes that docs/game-functions.csv carries): no XBE bytes, disassembly or Lua content enters it.
Checked on the prototype: [Results](#results).

### What points at the tree

| consumer | today | after the flip |
|---|---|---|
| proofs (Wine build) | build_tree rounds -> build/tree -> probe, map, link, replay | `tree_tu.py materialize` (one verification pass, cached; `HULK_TREE_SOURCE=1` in wine_build_run.py) -> the same stages; later the stages read src/ directly |
| native 64-bit builds (native_mac.py, ELF) | the tree snapshot | the same TUs |
| MSVC verification | every build, all TUs, many rounds | CI / a queue job per change: `tree_tu.py verify . --changed-since origin/main --relocs`, equiv for changed equivalent code |
| wine_link (map) | report.json checks with `src` = matches/... (reads equiv-map lines and words of the source) | `src` = the TU path: `equiv.verify(TU, addr, symbol, obj)` already reads the block's directives; the two places that `open(c["src"])` read the block (tree_tu.block_lines) |
| conv_check cache key | every file under matches/ and equivalent/ | every TU under src/{game,engine,platform/xbox} |
| progress.py / README table | counts files in matches/ and equivalent/ | counts blocks by kind (`tree_tu.scan`) |
| hybrid/ | patches our functions into the XBE; the hook-only recording path | **decided (user, 2026-11-10):** function patching is retired (hybrid_test compare, bisect_hybrid.py, patch_xbe's source selection, hybrid/exclude.txt); recording on the hook-only XBE stays and needs no decompiled code ([merge-prep.md](merge-prep.md)) |
| farm / datasets (export_dataset.py, prompts) | one source per function | **decided:** the farm is retired (matching mode and `--rewrite`); no retargeting and no final per-function dataset export (git history keeps the sources) |
| x64 tweak tools (ptr1, ptr_fields, name_unify, rename_ids) | rewrite per-function sources | **decided:** the 64-bit work continues after the flip, so these are retargeted to edit blocks in TUs (token-level edits of a block, then `tree_tu.py check` / `equiv.py TU ADDR --x64`) |
| agent briefs (docs/agents/) | write `matches/0xADDR.cpp`, run compare/equiv on it | edit the block in its TU, run the same tools with `TU ADDR`; a new standalone experiment can still be a scratch file, merged in as a wrapped block |
| regress cases (tests/equiv/cases) | standalone test sources | unchanged: they are checker test inputs, not game sources |
| addr -> file lookups (packet.py, workbench, many tools) | `matches/0x%08x.cpp` | an index `tree_tu.scan` builds (address -> TU, lines); a compatibility helper returns the TU path for an address |

About 80 tools name matches/ or equivalent/ paths; most are batch tools of finished campaigns (renames, migrations,
promotions) that are not needed after the flip, and the rest go through one address -> TU helper.

### Proof builds

"clang compiles the committed tree; MSVC re-verifies only changed TUs": the Wine build's build stage becomes
`tree_tu.py materialize` (copy the tree into build/tree, check every function from the caches, compile with MSVC only the
TUs whose object key is new), then map, probe, link and replay as before. No fallback rounds exist, so a changed shared
header recompiles the TUs that include it once instead of once per round. Prototype numbers: [Results](#results).

## Results

Prototype (build4, 2026-11-10; private workspace build/build4/, nothing committed): HEAD 0c41c92ee, the tree generated
from control 70736's final fallback state with `PYTHONHASHSEED=0 HULK_GEN_TREE_NOTES=1 gen_tree.py`, laid out as above
(2,645 TUs, 25 tree headers, 30 MB; 27,438 functions: 22,504 merged / 4,238 wrapped / 696 isolated) plus
`src/link-order.txt` (gen_tree's TU order).

**Every function verifies with the stage-1 tools** (`tree_tu.py verify --relocs --vs-standalone`, studio queue jobs
70877 + the proofs' materialize): 22,339 / 22,339 matches byte-match in their TU's object with relocations ok;
5,099 / 5,099 equivalent functions compile to the code of their proven standalone source (`same`); 0 ambiguous symbols.
After `pin`, the same with every function found by its pinned symbol. What it took (found on the way, all in
tree_tu.py now): names parsed per block (one wrapped source the shallow parser can't follow cost a whole TU its names;
gen_tree's `namespace fn_... {` lines between blocks are skipped), wrapped blocks keep their C names (`_FUN_x` ignores
namespaces), a block reason may hold brackets (`Cell [100] cells`: 9 functions were silently folded into the previous
block), and of several byte-identical candidates the one whose relocations hit the original's targets (118 functions,
below).

**Identity with the standalone tools** (sample: 100 merged / 70 wrapped / 30 isolated of each kind, random seed 4,
queue jobs 70880-70887, 70892-70895, 71020-71023):

| checker | merged | wrapped | isolated | identical | differences and causes |
|---|---|---|---|---|---|
| `compare.py` (200 matches) | 100/100 | 70/70 | 30/30 | **200/200** (status, exactness, score) | none |
| `verify_relocs.py` (200 matches) | 100/100 | 70/70 | 30/30 | **200/200** (status and issue kinds) | one fixed on the way: the vftable owner check read a tree namespace as part of the class (`CAction@fn_00018c20`), a soft warning |
| `equiv.py` (200 equivalents, 64 inputs) | 100/100 | 70/70 | 30/30 | **200/200** | the first run had 18 differences; fixed in tree mode only (below) |
| `equiv.py --wine` | 99/100 | 70/70 | 30/30 | **199/200** | 0x002b1c40: the TU defines the class, so clang emits its vftable in the TU's object and the virtual call runs our neighbour in place instead of calling the original (same-object neighbour through a vtable; open) |
| `equiv.py --x64` | 91/100 | 62/70 | 24/30 | **177/200** | 18 pass standalone and not in the tree, 4 the other way round, 1 unsupported; equiv64 has its own pairing (allocation sizes of a namespaced allocator call, 0x001318f0; same-object neighbours) and did not get the tree-mode fixes below; open |

equiv.py's tree mode (none of it changes a per-function check: regress 465/465): the function's directives are read
from its own block, its own declarations from the TU's shared part plus its block (`decl_c_signature`: two blocks
declaring one name differently made the signature unknown), the TU's other verified functions are separate functions
bound to their original addresses and never run as part of ours (`TREE_EXTERNAL`), an `equiv-map` name is matched to
the function's own `fn_<addr>` (or the TU's) namespace when several blocks declare it, and a name's tree namespaces are
not part of it (`fn_001bb0b0::thunk_FUN_000fc1b0` is the thunk).

**Wine proofs straight from the tree** (`HULK_TREE_SOURCE=1`: `tree_tu.py materialize` instead of build_tree's rounds;
`--state fresh --map full --opt o0`, play3 to 60000, gated against the control on the same host with
`tools/ckpt_gate.py`):

| job | host | tree | symbols | image | gate | build | total |
|---|---|---|---|---|---|---|---|
| 70736 | studio | control: build_tree (17 rounds) | build_tree | 5deed8e8 | — | 634 s (warm caches) | 1,004 s |
| 71017 | studio | tree text identical to the control's | build_tree's (`HULK_TREE_TU_OFF=pins,relocpick`) | **5deed8e8, byte-identical** | GATE ok, 2,002 frames, 0 PRNG diffs | 14 s | 222 s |
| 71007 / 71018 | studio | + notes (STATUS, provenance, equiv directives), header line | build_tree's | **5deed8e8, byte-identical** | GATE ok, 2,020 frames, 0 PRNG diffs | 745 s cold (one MSVC pass over 2,644 TUs) / 16 s warm | 994 s cold / 269 s warm |
| 71019 | studio | notes | tree_tu's (12 template-instantiation functions corrected) | 60d78357 | GATE ok, 2,010 frames, 0 PRNG diffs | 17 s | 269 s |
| 71103 | studio | notes + `// sym:` pins (the committed candidate) | pinned | 60d78357 (= 71019) | GATE ok, 2,018 frames, 0 PRNG diffs | 27 s | 260 s |
| 70737 | mac2 | control: build_tree | build_tree | 5deed8e8 (= studio's) | — | 1,044 s (2nd attempt; the 1st, cold, hit the 4 h limit) | 1,535 s |
| 71104 / 71105 | mac2 | notes + pins | pinned | 60d78357 (= studio's proof) | GATE ok vs 70737, 2,007 frames, 0 PRNG diffs | 3,102 s cold (shared with the control's build) / 5 s warm | 3,477 s cold / **228 s warm** |

Proof build time: **3.7-4.5 minutes** warm on studio and mac2 (build 14-27 s, map 32-52 s, probe 21-26 s, link 27-33 s, replay
121-149 s) against 17 minutes for the warm build_tree control; a first build of a changed tree is one MSVC pass (745 s
cold for all 2,644 TUs; a change compiles only the TUs whose text or headers changed) and no fallback rounds.

**Comments don't change the image**: the tree with notes, header line and pins gives the same image as the bare
generated tree (71017 vs 71018).

**Findings on the way**

1. *gen_tree's output depends on PYTHONHASHSEED*: ties between spellings of a stub (`struct Obj` / `class Obj`) are broken
   in set order, which changes 31 functions' symbols (`PAU` vs `PAV`) and the binding map. Builds set `PYTHONHASHSEED=0`;
   a local `gen_tree.py` run without it does not reproduce a build's tree. The committed tree removes this (it is
   generated once).
2. *The manifest's `tu_ns` is load-bearing*: wine_link's `source_slots` finds a stub class's TU by its namespace; without
   it the image starts but stops after the first file read (rc 3). `materialize` writes it.
3. *build_tree picks the first byte-identical candidate*: 118 matched functions are instantiations of one template member
   (`?vfunc_2@?$Method7@...`) that differ only in a relocated callee; build_tree's Verifier takes the first exact one,
   which for 12 of them is another instantiation (verify_relocs: `name_address_mismatch`), so the Wine link binds the
   address to a sibling's code. tree_tu takes the candidate whose relocations hit the original's targets; the image
   changes and still gates ok (71019, 71103). Worth applying to build_tree too.
4. *wine_link's equiv cache key has no checker version* (`native-cache/equiv`: object bytes, symbol, source path): a
   changed equiv.py reuses results the old one computed. build4 polluted 29 entries on studio with a development version
   (a tree-only name rule that was not yet gated to tree mode) and deleted exactly those (pattern-checked); the key
   should include equiv.py's hash.

## Stage 3: the flip (proposal; needs the user's explicit OK)

Nothing in this section has been done. What the user approves, in order:

1. **Freeze point.** A commit F at which the per-function sources are final: in-flight agents (build5's renames, mp2,
   any equiv -> match upgrades) land or park their work first; from F on, no agent writes matches/ or
   equivalent/ (a pre-commit check refuses new files there).
2. **Generate and verify the tree from F** (one queue job, studio): `build_tree.py --rounds 16` from F's sources (the
   final fallback state), `HULK_GEN_TREE_NOTES=1 gen_tree.py` with that state, `tree_tu.py verify --relocs
   --vs-standalone` (every match matches with relocations ok, every equivalent function's code is its proven source's),
   `tree_tu.py pin`, verify again. Gate: 0 differences; a Wine proof from the tree (`HULK_TREE_SOURCE=1`) gates ok against
   F's control on studio and mac2 (GATE ok, PRNG hashes identical).
3. **Splits and names at the flip** (decided, [merge-prep.md](merge-prep.md)): the Lua / choreo2 split (the 24 lua/ objects and
   choreo2/unk_221b30) is applied in config/splits.json at F and the tree generated from it, not before; the fragmented
   registration TUs (the `_N`-suffixed runs at 0x4e000, 0x6a000 and 0x150000, and the template-only `unk_` objects) get
   sensible names at the flip, with a clean-up pass later in the tree.
4. **Commit the tree** (one commit, explicit paths): `src/game`, `src/engine`, `src/platform/xbox`, `include/common.h`,
   `include/tree_prelude.h`, `include/{game,engine,platform/xbox}/` — about 2,650 TUs and 25 headers, ~30 MB of text.
   Plus the tool switches: wine_build_job defaults to `HULK_TREE_SOURCE=1`; progress.py counts blocks; wine_link and
   conv_check read blocks; the address -> TU helper; the x64 tools retargeted to blocks; hybrid patching tools removed; briefs say "edit the block in its TU".
5. **Freeze, then remove, the old trees.** matches/ and equivalent/ stay read-only for a grace period (two weeks, or
   until the first proofs and a native build from the committed tree pass), then a commit removes them (they stay in git
   history; `git show F:matches/0x....cpp` is the way back to any one). build_tree.py, gen_tree.py and the per-function
   campaign tools stay in the tree for that period as the regeneration path, then move to `tools/legacy/` or go.

**In-flight agents.** Announce F in docs/agents/ before step 1 (the farm is retired, so no farm prompts change); an agent's uncommitted per-function
edit after F is re-applied to its block by hand (or by a small tool: replace the block's code with the source's,
wrapped, and verify). The retargeted x64 tools (ptr1, ptr_fields, name_unify, rename_ids) must be ready at F so the 64-bit work goes on in the tree.

**Rollback.** Before step 5: revert the commit of step 4 (the per-function sources never changed, so the old flow works
at once). After step 5: revert the removal commit too; the tree commits stay in history and can be dropped. Any edits
made in the tree meanwhile would have to be carried back by hand, which is the reason for the grace period.

**Before F (prerequisites, no approval needed):** equiv64's tree mode (the 23 x64 differences of the sample: neighbours
bound to their addresses and namespaced names, as equiv.py has them); same-object neighbours reached through a vftable
the TU defines (the one `--wine` difference); `src/link-order.txt` written by the flip's gen_tree run (the TU order is the
link order); wine_link's equiv cache key with the checker's hash; and the 12 corrected template-instantiation symbols
(finding 3) either accepted (they gate ok) or pinned to build_tree's choice for a byte-identical first image.

**Risks.** (1) The x64 checker is not yet tree-identical (177/200 on the sample): until it is, 64-bit work in the tree
has a weaker check than on per-function files. (2) Equivalent functions whose code changes in a TU edit need a new
equiv run in tree mode; the code-hash rule keeps that to changed functions, but equiv's tree mode has had only a
200-function sample (100% identical for MSVC, 99.5% for `--wine`). (3) The tree is 30 MB of text in ~2,650 files with
long TUs (the largest are tens of thousands of lines); merges of concurrent edits to one TU are ordinary git merges
but bigger than today's one-function files. (4) Anything that silently relies on build_tree's choices (the symbol
picks, the manifest fields, the TU order, PYTHONHASHSEED) shows up only as a changed image: every switch gets an
image-identity or gate check, as here.

**What the user approves:** (a) the freeze point and the announcement to agents; (b) committing ~30 MB of generated-then-
owned TUs and headers under src/ and include/; (c) changing the Wine build default to the tree source; (d) the later
removal of matches/ and equivalent/ (a separate OK after the grace period).
