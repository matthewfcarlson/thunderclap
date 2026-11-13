# Merge once: the merged tree as the source of truth

Status: stages 1 and 2 done (build4). Stage 3: the user approved (a)-(c) on 2026-11-10 and build6 carried them out (see
[The flip](#the-flip-build6-2026-11-10)): freeze point F = e68debc9d, the tree committed under src/ and include/, the
Wine build's default source. (d), removing matches/ and equivalent/, was approved on 2026-11-13 (user decision D1) and
done by del1 the same day ([Step (d)](#step-d-matches-and-equivalent-removed-del1-2026-11-13)). Plan approved 2026-11-09 (build4). Background: [source-tree.md](source-tree.md) (how the
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
check fall back to the prefix lookup and report `pin_missing`, and `pin` rewrites the line). A function that is one of
MSVC's numbered local labels (an unwind funclet or catch block, `$L68215`: one counter over the whole compile, so any
header edit reaching the TU renumbers it) is pinned by a key that doesn't move, `// sym: $L#<k>@<owner>`: the k-th (from
0, in code order) `$L` label of the function OWNER (mangled), whose `__ehhandler$<owner>` follows the label in its
section (else the nearest function before it). The key resolves to exactly one symbol of the object, which is then
checked like any pinned symbol (bytes, relocations); a key that resolves to nothing is `pin_missing`. The tree's three
such blocks (src/game/init/dynamic_initializers.cpp 0x0035c3e0, 0x0035c4c0; dynamic_initializers.Oy-.cpp 0x0035be90)
carry it since 2026-11-10. The notes (STATUS, provenance, equiv directives) live in the block.

**What "verified" means after the flip** (unchanged in strength):

- matches: `compare.py TU ADDR` MATCH + `verify_relocs.py` ok, on the TU's object (`tree_tu.py verify --relocs`).
- equivalent: the function's code in the TU's object is the code that was proven (bytes, relocation positions and
  kinds, address targets: build_tree.same_code), or `equiv.py TU ADDR` passes again (3,000 inputs, plus the `--wine`
  gate at 600, as for a promotion). Implemented 2026-11-11 (hash1) as a per-block code hash on the pin line,
  `// sym: NAME @<msvc12hex> @w<clang12hex>`: a TU edit that leaves a function's code unchanged needs no new equiv
  run, and one that changes it is `code_changed` until re-proven ([Code hashes](#code-hashes)).

### Code hashes

Every `equivalent` block records the hashes of the code that was proven (tools/code_hash.py has the definition):

```cpp
// 0x001c49c0 FUN_001c49c0 (60 B): equivalent
// sym: ?FUN_001c49c0@Reader_1c49c0@fn_f4431f34@@QAEPAV12@XZ @62436bd00f45 @w519b552cd43b
```

- `@<hex>`: the function in the TU's MSVC 7.1 object (tree_tu's compile). sha256 (48 bits kept) over the function's
  bytes (trailing padding stripped, as same_code) and per relocation its offset, type and target, plus every region of
  the object the proof runs or reads in place (functions defined in the object that are not other blocks: inline
  members, `$L` unwind funclets, `__ehhandler$`; EH tables, `$SG` strings, static data, `.bss` sizes), plus the block's
  equiv directives (map/conv/name lines, the `+0xNN taken` claims of equiv-dead). Targets are keyed as the proof binds
  them: another block of the TU by its address; `__real@`/`__xmm@`/`??_C@` constants by name (their names spell the
  content); an address in the symbol's own leaf (`FUN_`/`LAB_`/`DAT_`/`PTR_`/`hulk_at_`/`vtbl_`/`rttiTD_<hex>`, or the
  `Name_00xxxxxx` suffix of a call into .text) or an `equiv-map` line's address; a region of the object as its node
  number; compiler-local names (`$L<n>`, `$T<n>`, `$SG<n>`, `__ehfuncinfo$`) never by name; anything else (vftables,
  RTTI, operators, CRT names, `??0`/`??1` of stub classes) by its name. Section-relative relocations (jump tables,
  clang's unnamed constants) are resolved to (region, offset) with the addend taken out of the bytes. So renames that
  keep every target's address, `$L`/`$T` renumbering, and edits to other functions of the TU leave it unchanged; a
  changed byte, relocation position or kind, a call to another address, a changed inline callee or EH table changes
  it; a rename the rules can't see through (a name with no address) counts as a change. Strictly stronger than
  build_tree.same_code.
- `@w<hex>`: the same over the clang object `equiv.py TU ADDR --wine` checks (equiv.compile_native: i686 MS ABI, -O0,
  the SSE build's IR passes), compiled with an empty x87-keep list (the queue hosts have none; a Wine build lineage's
  list must not leak in). Needed: the `--wine` proof is of the clang object, and a header edit can change it without
  touching the MSVC code (`#if defined(__clang__)` / `_MSC_VER` branches, compat/native.h, hulk_freg). The function is
  found by its MSVC name, or the one name that differs in M <-> N (equiv's mnret rule: a float return clang makes
  double); where clang has none (an MSVC `$L` funclet) the hash is of the whole clang object. Homebrew's and ~/llvm's
  clang 22.1.8 give the same hashes (checked on mac2). The 64-bit (`--x64`) check has no hash: it is not a promotion
  gate.

`tree_tu.py check` / `verify` / `materialize` recompute both (the clang one compiles the TU with clang once, cached in
`build/tree-cache/whash/` by the TU, the headers clang can reach, the toolchain and the hash code; `--no-wine-code`
skips it where there is no clang) and report per equivalent block `code` / `wine_code`: `ok`; `changed` (the record's
`code_changed` lists msvc/wine); `unhashed` (none recorded); `no_object` (clang can't compile the TU). In verify's
counts, and so in the exit codes of `check`, `verify` and `materialize` (the Wine build's build stage), `changed` and
`unhashed` are failures like `pinned symbol missing`; `no_object` is reported, not a failure.
`verify --changed-since REF` also fails a block that had a hash at REF and has none now (a hash is replaced by
`hash --proven`, never dropped). `pin` keeps a block's hashes when it rewrites the symbol.

Recording a hash needs a proof of the code as it is now:

```sh
$J tools/equiv.py TU.cpp 0xADDR --json --inputs 3000 > msvc.json     # its report carries tree_code: the hash it checked
$J tools/equiv.py TU.cpp 0xADDR --wine --json --inputs 600 > wine.json
$J tools/tree_tu.py hash TU.cpp --proven msvc.json wine.json          # (a jsonl of such reports works too)
```

`hash --proven` writes a block's new `@hash` only from an MSVC run whose `tree_code.msvc` is the code's hash now,
asked for >= 3,000 inputs and promotable, and a new `@w` hash only from a `--wine` run whose `tree_code.wine` matches,
asked for >= 600 inputs, passing tools/wine_gate.py and compiled without an x87-keep list; a block whose MSVC code
changed needs both, one whose clang code alone changed needs the `--wine` run. equiv.py records `tree_code` only for a
plain run of the tree TU (no extra flags, `--map`, seeds, replay level 3, EQUIV_OFF rules or another symbol). Nothing
else writes a hash. `hash . --compute OUT [--tus LIST] [--commit SHA]` only reports the hashes of the code as it stands
(a queue job's workspace is `git archive HEAD`): a way to show an edit leaves code unchanged. The equiv.py runs above
must be of the tree TU at its path; `jobq_equiv.py` ships a copy under `jobsrc/`, so its reports carry no `tree_code`
(run `tools/equiv.py TU 0xADDR --json` in a plain queue job instead).

Populated 2026-11-11 (hash1) from the code at 6a71f9a03, which the flip's proofs and every proof since cover: 4,916
of the 5,099 equivalent blocks in 1,144 TUs, computed in 24 queue jobs (mac2, mac1); the 13 TUs (183 blocks) that had
uncommitted edits by other agents at the time went on a pending list (`unhashed` reported, not failing) and were filled
in later by a one-off `hash --init` from such records: dynamic_initializers.cpp (dg1, 9063a0525) and the last 12 (hash2,
2026-11-12; 122 of their 127 blocks re-proved at 3,000 + --wine 600, the other five's code unchanged since 6a71f9a03).
The list and `--init` were then removed: every equivalent block has its hashes, and `unhashed` is a failure everywhere.

**Header edits that change MSVC code (hash3, 2026-11-13).** A hash is a pure function of the TU's preprocessed text:
the same files give the same object on every host, layout (checkout, build/tree, a job workspace) and path, so
`verify` and the Wine build's `materialize` (one function, `verify()`) agree on the same files. But MSVC 7.1's output
for a few functions depends on the *number* of symbols declared before them in the TU, not on what they are: three
`extern int` lines anywhere before 0x001a9b10 swap two independent spill reloads at a join (`mov ebp, [esp+1c]` /
`mov esi, [esp+30]`); names, name lengths, macros, comments, paths, the environment and declarations after the function
change nothing. So any header that adds or removes a declaration (records.h, gen/*.h, decls/*.h) can flip such a block
between two codegen variants, and its `@hash` reports `changed` until re-proved (an MSVC run; its clang code doesn't
move, so `@w` stands). Six blocks do this (a sweep inserting N dummy declarations at the top of every TU: N = 1, 2, 3,
5, 8, 13, 21 over all 2,675 TUs, N = 1..32 over the 1,157 with equivalent blocks): 0x001a9b10, 0x000b86b0, 0x000ba040,
0x00027930, 0x002e9c60, 0x002ea3c0 (spill reloads, stack slots, registers or a commutative operand order swapped); no
`matches` block moved. `verify` prints `inputs` (content digests of the TUs and of every header the compiles can
reach); `tree_tu.py inputs ROOT [--tus FILE]` gives the same locally, so a queue job's pass can be tied to the files
it checked: a job is `git archive HEAD` plus its overlay, and a verify job without `--files`/`--dirty` checks HEAD.

### Checks beyond the blocks (tool2, 2026-11-13)

`check` and `verify` run three more checks (user decisions D9, D10, D12 of 2026-11-13); each fails the run like a
block does:

- **The header probe (D9).** When a header under include/gen/ changed, `verify` runs `gen_headers.py --probe`
  (in process, ~7-11 s; [headers.md](headers.md) "The probe in verify") and fails when it fails (summary `gen_probe`).
  Changed means: since `--changed-since REF` (working tree and untracked files), else uncommitted (vs HEAD); in a
  queue job, shipped. `check TU` runs it when such a header is one the TU can `#include`. `--gen-probe` forces it.
- **Unshipped local edits (D10).** A queue job is `git archive COMMIT` plus its overlay files (docs/compute.md
  "Workspaces"), so a verify job passes whatever the checkout holds unless the edits travel with it (hash3).
  `tools/jobq.py` refuses a job running `tree_tu.py verify|check` or `x64_gate.py check` (also inside `sh -c`) when a
  TU it lists, a file those TUs can `#include` (`reach` below), or a config file the check reads (config/data.json;
  config/x64-baseline.json for `--x64`; config/gen-sizes.json when the probe will run) is modified or untracked in the
  checkout and not shipped, unless that command has `--head-only` (check the commit, plus what is shipped, on purpose).
  The refusal names the files and what to pass. The job gets `.jobq/local-inputs.json` (the local `inputs` digests,
  the shipped paths, the commit) and prints `inputs_vs_local`: its own digests against the checkout's at submit, per
  digest `same` true/false. `inputs` now has three digests: `tus`, `headers` (every header under include/) and
  `reach` (only the files the TUs can `#include`: tools/include_keys.closure; what the guard compares).
- **Data overreach (D12).** tools/data_overreach.py's scan over the MSVC object `check_tu` already compiled: a hit of a
  reported class (`over`, `pad`, `addr`, `before`, `indexed`) is a record's `overreach` list and a failure
  (`overreach <kind>` in verify's counts, so `materialize` fails on it too); the informational classes (`end`,
  `negidx`) are `overreach_info` / `info: overreach <kind>`, never failing. config/data.json and data_overreach.py are
  part of the verify cache's key. Baseline on HEAD 1c5f08c59 (whole tree, job 78937): 0 reported, 16
  informational (13 `end`, 3 `negidx`), as scan1's last run (78132).

Inside a queue job (no git in its workspace) `verify --changed-since REF` and the x64 gate take only the job's base
commit as REF (submit checks that REF names it): the changed TUs are the shipped ones, the gate's REF side is the
workspace with the shipped files put back to the commit's copies (`.jobq/ref/`), and its equivalence runs stay in the
job. Before tool2 `--changed-since` in a job found no TUs (git failed silently) and passed.

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

**include/gen after gen1 (2026-11-13).** The same flip for the class headers: include/gen/ is hand-maintained source
(user decision 2026-11-13). The generator's output was checked against the committed headers first (nothing in its
inputs was missing; every difference was a later hand edit), the "GENERATED ... DO NOT EDIT" banners became a note
that the files are source, the generator's inputs (`include/gen/evidence*.json`) were deleted, and
`tools/gen_headers.py` kept only the layout probe (`--probe`, with `config/gen-sizes.json` as the size ratchet). The
tools that wrote the evidence or rewrote matches/ onto the generated headers refuse to run. Nothing in the build or
proof pipeline regenerates include/gen/. See [headers.md](headers.md).

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

**Before F (prerequisites, no approval needed; all done by build6, see [The flip](#the-flip-build6-2026-11-10)):** equiv64's tree mode (the 23 x64 differences of the sample: neighbours
bound to their addresses and namespaced names, as equiv.py has them); same-object neighbours reached through a vftable
the TU defines (the one `--wine` difference); `src/link-order.txt` written by the flip's gen_tree run (the TU order is the
link order); wine_link's equiv cache key with the checker's hash; and the 12 corrected template-instantiation symbols
(finding 3) either accepted (they gate ok) or pinned to build_tree's choice for a byte-identical first image.

**Risks.** (1) The x64 checker was not tree-identical (177/200 on the sample; 198/200 after build6's tree mode, the two
left are tool limits). (2) Equivalent functions whose code changes in a TU edit need a new
equiv run in tree mode; the code-hash rule keeps that to changed functions, but equiv's tree mode has had only a
200-function sample (100% identical for MSVC, 99.5% for `--wine`). (3) The tree is 30 MB of text in ~2,650 files with
long TUs (the largest are tens of thousands of lines); merges of concurrent edits to one TU are ordinary git merges
but bigger than today's one-function files. (4) Anything that silently relies on build_tree's choices (the symbol
picks, the manifest fields, the TU order, PYTHONHASHSEED) shows up only as a changed image: every switch gets an
image-identity or gate check, as here.

**What the user approves:** (a) the freeze point and the announcement to agents; (b) committing ~30 MB of generated-then-
owned TUs and headers under src/ and include/; (c) changing the Wine build default to the tree source; (d) the later
removal of matches/ and equivalent/ (a separate OK after the grace period).

## The flip (build6, 2026-11-10)

The user approved (a) the freeze point, (b) committing the tree and (c) the tree as the Wine build's default source
("Yes A-c seems sane"). (d), deleting or moving matches/ and equivalent/, needs a separate OK and was not done. The
decisions folded in from merge-prep: the Lua/choreo2 split at the flip, sensible names for the registration TUs,
hybrid function patching and the farm retired, the x64 tools retargeted later, no dataset export.

### Pre-freeze fixes (each its own commit)

| fix | commit | what |
|---|---|---|
| wine_link equiv cache key | 0a78ca376 | key v3 = object, symbol, source path + sha1(equiv.py, tree_tu.py) + the source's `equiv-*` lines |
| gen_tree PYTHONHASHSEED | f9460984f | two set-order ties: the struct/class keyword of a merged stub class (stub_layout.merge_variants) and a wrapped source's pinned-global declarations. Seven runs (seeds 0, 2, 3, 7, 11, two random) on control 70736's state give one tree; before, three different ones |
| template-sibling pick | c59cc5632 | build_tree.prefer_relocs (moved from tree_tu): of several byte-exact candidates, the one whose relocations hit the original's targets. **Kept** (the 12 corrected symbols, image 60d78357 in build4): each address is bound to its own instantiation's code; build4's proofs with them gated ok on both hosts; and now a build_tree control and a tree proof pick the same symbols, so their images compare byte for byte |
| link-order.txt | e72df1f82 | `tree_tu.py layout` lays a generated tree out as the committed tree and writes `src/link-order.txt` from the manifest's TU order |
| `--wine` 0x002b1c40 | 4038b3486 | not a vftable neighbour: the TU's function arrives with its MSVC name (`...UAEMXZ`, float return), clang's is `...UAENXZ` (hulk_freg = double), and pick_symbol's byte-similarity fallback picked the neighbour vfunc_15. pick_symbol / natmap take the one M <-> N variant (`EQUIV_OFF=mnret`) |
| equiv64 tree mode | 5f7763157 | the TU's other functions are stubs; allocator names without tree namespaces; param_casts on the definition; pin views type their globals; integers decoded as our addresses only inside what the function reaches; input streams independent of source position (stub returns by callee name, heap contents by creation order apart from globals, globals in name-hashed 64 KB slots). `EQ64_OFF=treeext,treens,pinview,treereach,rngloc,gseq` |

Regress after the equiv/equiv64 changes: 465/465 three times (queue batches 71120-71197, 71201-71278, 71293-71370).

**Identity with the standalone tools** (build4's 400-function sample; tree generated from f607f8708 with control 70736's
state and the fixed generator; queue jobs 71108-71119, x64 71285-71292):

| checker | merged | wrapped | isolated | identical |
|---|---|---|---|---|
| `compare.py` (200 matches) | 100/100 | 70/70 | 30/30 | **200/200** |
| `verify_relocs.py` (200 matches) | 100/100 | 70/70 | 30/30 | **200/200** |
| `equiv.py` (200 equivalents) | 100/100 | 70/70 | 30/30 | **200/200** |
| `equiv.py --wine` | 100/100 | 70/70 | 30/30 | **200/200** (was 199) |
| `equiv.py --x64` | 99/100 | 69/70 | 30/30 | **198/200** (was 177) |

The two x64 differences are tool limits, not opposite verdicts: 0x0027de50 inconclusive standalone (6 of 9 inputs
completed in the time budget) vs equivalent in the TU (30 of 35); 0x00207080 a CRT `_sprintf` that neither side has a
signature for (unsupported vs fail class tool).

**Start-up failures at HEAD were stale local inputs** (asked by mp3: a plain 1febf1140 build, studio 71106, crashed at
init 332 in the audio type-tree insert): the laptop's build/data/src was from 11-06, older than three data.json commits,
so the OmType .bss items were unbound; with fresh data TUs the build reached main and then stopped (71282) because the
prebuilt hulk_sdl.lib predates 23ae2f213's `hulk_session_*`. With both rebuilt from a clean archive, HEAD e72df1f82
(71374) gates ok against build4's control 70736 (2,003 frames, PRNG 0 differ). No commit broke the build; see
[compute.md](compute.md) "Local inputs must be current".

### F and the split

F = **e68debc9d**: config/splits.json gets the Lua split (unk_212bb0 and unk_338d90 become 24 `lua/` objects and
`choreo2/unk_221b30`; `tools/infer_splits.py` FIXED_OBJECTS) and the registration names (110 objects of the three
registration runs and the 15 template-only `unk_` objects become `<Class>_params`, `_factory`, `_params_factory` or `_reg`
in their class's directory; REGISTRATION_RANGES). Only these changes: infer_splits' drift of the unk_357740 / unk_35a640
boundary on HEAD is left out (it predates build6). config/data.json: the Lua objects' 352 items re-owned by where their
code references fall, the renamed objects' 3,265 items follow the rename. The data headers are regenerated; items whose
object left `unknown/` stay declared in `<layer>/unknown.h` too (data_gen SPLIT_AT_FLIP), so the per-function sources
compile unchanged (18 sources that name a moved item: identical compare results). The agent briefs carry a freeze notice.

### The tree from F

Control 71377 (studio; F through build_tree, `--state fresh --map full --opt o0`, the F data TUs and a clean hulk_sdl.lib
built from an archive; play3 to 60000) gates ok against build4's control 70736 (2,020 frames, PRNG 0 differ): F's split
and renames change no behaviour. Its final fallback state gave the tree: `PYTHONHASHSEED=0 HULK_GEN_TREE_NOTES=1
tools/gen_tree.py` in an archive of F, `tools/tree_tu.py layout` into a second archive (which writes `src/link-order.txt`),
then one queue job (71419, studio, 306 s): `tree_tu.py verify . --relocs --vs-standalone`, `pin`, verify again.

**2,675 TUs** (2,021 under src/game, 616 under src/engine, 38 under src/platform/xbox; 2,674 with functions), **25 tree
headers** (include/common.h, include/tree_prelude.h, 11 under include/game, 11 under include/engine, 3 under
include/platform/xbox) and src/link-order.txt: 2,702 files, 26.5 MB of text. **27,438 functions: 22,661 merged, 4,082
wrapped, 695 isolated** (build4's prototype: 22,504 / 4,238 / 696). Verification: 22,339 / 22,339 matches byte-match in their
TU's object with relocations ok, 5,099 / 5,099 equivalent functions compile to their proven standalone code (`same`),
0 errors; after `pin` every function is found by its pinned `// sym:` (27,438 `pinned`, 0 `pin_missing`), with the same
counts. 118 symbols came from the relocation pick (`name+relocs`), as in build4.

**No game data in the tree** (build/build6/scripts/datascan.py over all 2,702 files): no data_gen output or marker, no
`#include` of build/, no numeric initializer of 64 or more elements, and the 13 string literals of 200+ characters are
all verbatim in committed matches/ / equivalent/ sources. The tree's text is a function of committed inputs (the sources,
config/splits.json, the function table's names): gen_tree turns variable definitions into `extern` declarations, the data
TUs stay local (`tools/data_gen.py` from the player's XBE into build/data/src) and include/decls/data stays as it is.

### Proofs

Each proof is the committed-tree candidate (notes and pins) built with `HULK_TREE_SOURCE=1` (`tree_tu.py materialize`,
no fallback rounds). Its control is F built through build_tree on the same host. Both use one source snapshot: git-archive
workspaces of F, F's data TUs (`--data-src`) and a hulk_sdl.lib built from a clean archive (`--sdl-src`). Settings:
`--gfx --replay play3 --frames 60000 --opt o0 --map full`, gated with `tools/ckpt_gate.py CONTROL PROOF`.

| host | control (build_tree) | proof (tree) | image | gate | proof time |
|---|---|---|---|---|---|
| studio | 71377: 3,255 s (build 2,825), GATE ok vs 70736 | 71420 (`--state seed:71377`) | f4d5cedca2c8 = control's, **byte-identical** | **GATE ok**, 2,005 common frames, PRNG 0 differ | 1,101 s (materialize 675 s, MSVC objects cold for the noted TUs) |
| mac2 | 71378: 5,620 s (build 5,129), GATE ok vs 70737 | 71421 (`--state fresh`, submitted while the control ran; state is unused on the tree path) | f4d5cedca2c8 = control's = studio's, **byte-identical** | **GATE ok**, 2,021 common frames, PRNG 0 differ | 3,650 s (materialize 3,228 s cold) |

The images are byte-identical, and not just gate-equal, because build_tree now picks the same relocation-correct
symbols as tree_tu (c59cc5632) and because comments (notes, pins, the header line) don't change objects.

### What was committed and what was not

- **79e737139** (b): the tree, 2,703 files (the TUs, the 27 tree headers, src/link-order.txt), built with a private
  index from the proven workspace and nothing else.
- (c): `tools/wine_build_run.py` defaults to the tree source when the lineage has `src/link-order.txt`
  (`HULK_TREE_SOURCE=0` restores build_tree). Docs: this page, compute.md, wine-build.md and the freeze notice in
  docs/agents/.
- **Excluded**: no generated data TUs or data headers were added (include/decls/data is F's; the data TUs under
  build/data/src stay local and generated from the player's XBE). No game bytes, shader bytes, Lua script content or
  disassembly are in the tree (scan above). CLAUDE.md is not edited; the proposed text is in build6's report.
- Not done in this flip, by decision: removing matches/ and equivalent/ ((d), below), the tool retargets (progress.py,
  packet.py, the x64 tools, conv_check's key), and a pre-commit check refusing new files in matches/ / equivalent/.
  The briefs announce the freeze.

### What (d) involves (the plan; done 2026-11-13, see [Step (d)](#step-d-matches-and-equivalent-removed-del1-2026-11-13))

(d) removes matches/ and equivalent/ after a grace period, with the user's separate OK. What it involves:

1. Every block already carries its pinned symbol, so the shared-symbol tie-break no longer needs the standalone sources.
   The block lines can name the kind only (`: matches` / `: equivalent`; tree_tu's BLOCK pattern accepts both) and the
   `--vs-standalone` check retires; equivalent code is then guarded by the code hashes ([Code hashes](#code-hashes),
   implemented) or a new equiv run.
2. Retarget what reads per-function paths. That means one address -> TU helper over `tree_tu.scan` for packet.py,
   progress.py (count blocks by kind), tech_debt.py, reach.py, data_inventory.py (source names and offsets), wine_link's
   conv_check key (TUs under src/ instead of matches/ + equivalent/), equiv_batch / jobq_equiv / promote_dispatch, and the
   regress and test inputs that read sources. Most of the ~80 tools that name matches/ are finished campaigns and go to
   tools/legacy/.
3. Retarget the x64 tools (ptr1, ptr_fields, name_unify, rename_ids) and a tree formatter to TU blocks. The 64-bit work
   needs these even before (d).
4. Retire the per-function generators: build_tree.py and gen_tree.py stay only as the regeneration path from history,
   and hybrid's function patching and the farm are removed (both already decided).
5. One commit deletes matches/ (22,339 files) and equivalent/ (5,099). `git show e68debc9d:matches/0x....cpp` restores
   any one, and reverting that commit restores all of them.
6. Rewrite CLAUDE.md, docs/agents and the README status (progress.py) for "edit the block in its TU".

## Step (d): matches/ and equivalent/ removed (del1, 2026-11-13)

User decision D1 (2026-11-13): delete the frozen per-function sources and move the ten tools gen1 retired into
tools/legacy/. Two commits: the readers first (tools, tests, docs), then the deletion of matches/ (22,339 files) and
equivalent/ (5,099 files). Neither directory changed after F, so `git show e68debc9d:matches/0x....cpp` restores any one
(as does the last commit that has them, named below); reverting the deletion commit restores all.

**Readers, and what became of each.** Every tool, test, config and doc that named matches/, equivalent/,
`HULK_TREE_SOURCE=0` or build_tree's generation path was looked at.

| reader | was | now |
|---|---|---|
| tools/wine_link.py, binding map of the equivalent functions (`_equiv_job`) | `equiv.py` level 2 on `equivalent/0xADDR.cpp` with the tree object | the same check on the function's unit text: the TU's shared part and its block, block line neutralised (`tools/tree_index.py` source_text) written to a temporary file, so equiv.py stays in its standalone mode (its tree mode reads names differently on purpose, equiv.name_address). Cache key v4: the unit text instead of the file's directive lines |
| wine_link `tree_explicit` (native10's equiv-map lines) | the source file's lines | the unit text's lines |
| wine_link build_map's same-symbol check (native9) | the source file names every word of the shared symbol | the block's text (the skip set is the same: 1,249 of the 1,698 checks in shared-symbol groups, both ways) |
| wine_link map key | source texts | block texts; MAPKEY_VERSION 2 (one full map after the change) |
| wine_link conv_check key | every file under matches/ equivalent/ | every tree TU |
| tools/wine_conv_check.py (report only) | per-function files | a root is a block kind of the tree: notes and definitions from each block, declarations from its TU (gen_tree hoisted them), check 4 compiles the TU at the address; a directory path still reads per-function files |
| tools/equiv.py `_definition_conv` (convdef) | equivalent/ or matches/0xADDR.cpp | the callee's block. Over all 27,438 functions the answer is the same but for 5 blocks edited after F (0x0005d130, 0x00234210, 0x0028f980, 0x002ac4a0, 0x0031b7d0), where the block is the code that compiles |
| tools/wine_build_run.py, wine_build_job.py | SRC_DIRS with matches equivalent; `HULK_TREE_SOURCE=0` / no link-order.txt ran build_tree's rounds; `seed_decision()` | SRC_DIRS = include src tools config; the build stage refuses the old path; `seed_decision()` removed (a tree-source proof seeds through `tree_seed_decision()`); decide() counts added/removed tree TUs where it counted function sources |
| tools/jobq_run.py LINKS, jobq.py | jobs got symlinks to the host checkout's matches/ equivalent/ | not linked: a job sees no per-function sources even where a host's checkout still has them |
| tools/jobq_host_setup.sh, jobq_host_setup_linux.sh | archived matches equivalent; smoke test compared matches/<first>.cpp | archive without them; smoke test compares the first `matches` block of a tree TU |
| tools/similar.py (packet.py --similar) | matches/*.cpp | the `matches` blocks (index build/farm/simindex2.pkl) |
| tools/layout64.py, config/layout64.json | `"source": "matches/..."`, the file included | `"block": "0x..."`: the record's definition cut from its TU (the whole TU need not compile for every target); --check ok on i686, x64, arm64 as before |
| tools/tech_debt.py, docs/tech-debt.md | scanned matches/ equivalent/ | scans the blocks; the same 5 functions and flags |
| tools/data_ptrs.py scan | default matches equivalent | default the tree TUs (config/data-ptrs.json's `sources` stay the per-function evidence it was made from) |
| tools/verify_relocs.py whole-set sweeps (--all, --initializers, --literals, --addrlits, --names) | listed matches/ equivalent/ | exit with a message without them (`--src-root` an export of a commit that has them); the tree: `tree_tu.py verify . --relocs` |
| tools/tree_tu.py `--vs-standalone`, `_shared`, cached_check | used standalone sources where they exist | unchanged: they test for the files, which no longer exist (every block is pinned, so `_shared` has nothing to resolve) |
| ten gen1-retired tools (migrate_gen, rn_members, rn_sigs, rn_ptrfields, rn_fields, ptr_slots, param_fields, rename_fields, fn_names, owner_classes) | tools/ | `git mv` to tools/legacy/; paths fixed so they import and print their refusal; references in tools/ and docs/ follow |
| tests/jobq/test_native_build.py, test_map_key.py | matches/ names in fakes; seed_decision tests | tree TU names; a fake tree TU for the map key; the seed tests went with seed_decision |
| tests/test_verify_relocs.py, tests/equiv/test_equiv.py, selftest.py, mutate.py | matches/0xADDR.cpp | the tree TU (tree mode), or the unit text as a source of its own (mutate: only mutants inside the block) |
| tests/android/count_variadics.py | matches/ equivalent/ | one unit text per block |
| tests/native_host/replay_native_test.py, va_tree_test.sh | compiled per-function files as fixtures | the same files from F (`git show e68debc9d:...`) |
| tests/gen_tree_identity.py | this checkout's matches/ | refuses without `--src-root` of an export that has them |
| build_tree.py, gen_tree.py | the generator | stay: tree_tu, wine_link, x64_gate, data_inventory, clang_probe and others use their compile, key and check code; the generation path needs an export of a commit with the sources |
| per-function campaign tools that only read or rewrite matches/ equivalent/ (agent_round, clone_matches, clone_equivalent, decl_lint --all, fix_literals, fix_relocs, fix_function_list, format_matches, format_equivalents, lint_floats, lua_inventory, migrate_data, narrow_scan, patch_xbe, permute --install, reach, reconcile_stubs, rename_placeholders, rn_map, seam_inventory, wine_calls, wine_fix, equiv_replay / equiv_replay_fn / equiv_confidence / trace_capture (the trace replay of equivalent/ sources), capture_mac1.sh, the workbench) | read matches/ equivalent/ | retired by this note, not moved: they find no sources (most stop at a missing directory); several are imported by live tools (migrate_data by data_gen and data_inventory, reconcile_stubs by stub_layout, format_matches by permute), so moving them is a separate clean-up. The trace replay would read blocks through tools/tree_index.py if it is wanted again |
| docs | | README, roadmap, compute, wine-build, equivalence, data, headers and this page say the directories are gone; the rest are logs of their time |

Comments in tools and TUs that cite a function as `matches/0x....cpp` (the block lines themselves say
`: matches/0xADDR.cpp`) are left: they name the function and its history. tree_tu's BLOCK pattern accepts the kind
alone, so a block line can drop the path when it is next edited.

**The binding map, checked function by function.** Before the deletion, every equivalent function's level-2 map was
computed both ways on the committed tree (the per-function source, and the unit text as above) through the queue
(mac1, jobs 79038, 79041, 79046-79051): **5,099 / 5,099 the same** map, status, unresolved names and native10 lines.
A first attempt in equiv.py's tree mode differed in 39 of 508 (it drops `how: name` bindings of the TU's neighbours,
by design), which is why the map uses the standalone mode on the unit text.


**Proof.** Control 79153 (studio; ec01c3faa with matches/ and equivalent/, built by that commit's own wine_build_run,
private data TUs) and proof 79235 (studio, `--state seed:79153`; the same commit with the readers above and without
the two directories): the **image is byte-identical** (hulk-strict.exe 1264ae52), `ckpt_gate.py 79153 79235`: **GATE
ok**, 2,003 common frames to 60060, PRNG 0 differ. Link stats equal (1,249 shared-symbol checks not bound; 4,783 / 316
equiv level 2 ok / fail; 37 unbound). Only the report-only conv_check moved: 404 import declarations counted per TU
instead of 475 per function (hoisted declarations counted once), and check 5 lists one more caller
(0x000e07c0 from 0x000e0850 in src/game/global/FEAnimation.cpp: its by-value struct exception now reads the block's
unit text). A first control (79058) was invalid: `submit` ships the checkout's own tools/wine_build_run.py, which
already lacked matches/ in SRC_DIRS, so HEAD's wine_link found no per-function sources and the image hung at frame 0.
A control of a commit before (d) must be submitted with that commit's wine_build_job.py / wine_build_run.py.

**Other checks.** `tests/equiv/regress.py --jobq`: 478 / 478 (jobs 79154-79233, after the `_definition_conv` change).
Unit tests (`unittest discover` over tests/, tests/equiv, tests/jobq): pass, apart from test_jobq's RoundTrip cases,
which drive the live queue and fail the same way on HEAD without this change. `tools/progress.py --readme`: no change.
`tools/layout64.py --check`: all ok. Whole-tree verify after the deletion: below.
