# Merge-once preparation (build5, 2026-11-10)

This page is the prep list for making the merged tree (`tools/gen_tree.py` / `tools/build_tree.py`,
[source-tree.md](source-tree.md)) the committed source instead of `matches/` + `equivalent/`. The design itself is
build4's ([merge-once.md](merge-once.md)). This page covers four things. Section 1 reviews the object splits that
become committed file names. Section 2 lists every tool that writes per-function sources, with what to do with each.
Section 3 gives the merge rate on HEAD and the scripted renames that are left. Section 4 summarises what the hybrid
build still needs; the full write-up is in [hybrid-build.md](hybrid-build.md), "After merge-once".

## 1. Splits review (`config/splits.json`)

`tools/infer_splits.py` reproduces the committed `config/splits.json` on HEAD: 1,807 objects, of which 1,781 are
game, 25 library and 1 game-init. Of the game objects, 1,097 are high confidence, 485 medium and 199 low; with
`init/` that makes 200 low. Of the low objects, 126 are under `unknown/`. The rest are 20 `global/`,
19 `hulkfight/`, 11 `audio/`, 10 `pure3d/`, 5 `physics/`, 4 `core/`, 3 `fight/`, 1 `choreo2/` and 1 `init/`.
By kind of evidence:

| kind (evidence line) | objects | what it means |
|---|---|---|
| unattached run (no call affinity to either neighbour) | ~85 | `FUN_` runs cut where no call edge crosses. Boundaries are a guess and names are `unk_<addr>` |
| COMDAT strays only | ~30 | out-of-line inline members emitted in the first object that used them. Correct for link order, but not a source file anyone wrote |
| template instantiations only (`template args: X`) | 15 | track/condition factory COMDATs, see "Registration TUs" below |

### Clear finding: the Lua VM and its libraries (proposed, not applied)

Two low-confidence objects are the embedded Lua VM ([native-build.md](native-build.md), "The Lua VM on records"):
`unknown/unk_212bb0.cpp` (368 functions) and `unknown/unk_338d90.cpp` (161 functions, after bink1/bink2 removed the
Bink spans). lua1 identified every function from the game's own code: allocation sizes, error strings and
accessors. The identification is the first comment line of each source (`// lua_typename: ...`,
`// luaK_patchlist: ...`). In link order the identified functions fall into contiguous runs, one per API prefix and
library. Each run is one object file, so the boundaries come from the binary (link order plus the identified names).
No Lua source was used. Proposed objects, all in layer `engine`, directory `lua/`:

| object | range | first .. last identified function | boundary evidence |
|---|---|---|---|
| `lua/lapi.cpp` | 0x00212bb0..0x00213f20 | index2adr .. lua_setupvalue | `lua_*` API; 0x00213a50 (no name) sits between lua_pcall and lua_cpcall |
| `lua/ldebug.cpp` | 0x00213f20..0x00214dd0 | currentline, lua_sethook .. luaG_ordererror | `luaG_*` and the hook API |
| `lua/lstate.cpp` | 0x00214dd0..0x00215240 | stack_init .. lua_close | `luaE_*`, lua_newstate |
| `lua/ldo.cpp` | 0x00215240..0x00215f50 | seterrorobj .. luaD_protectedparser | `luaD_*`, lua_resume/yield |
| `lua/lobject.cpp` | 0x00215f50..0x002164b0 | (0x00215f50) luaO_log2 .. luaO_chunkid | 0x00215f50 is a 31-byte leaf called only by the parser's constructor. It opens the next file (the "helpers come first" rule) |
| `lua/lgc.cpp` | 0x002164b0..0x00217520 | reallymarkobject .. luaC_fullgc | `luaC_*` |
| `lua/ltm.cpp` | 0x00217520..0x00217600 | luaT_init .. luaT_gettmbyobj | `luaT_*` |
| `lua/lvm.cpp` | 0x00217600..0x002192c0 | luaV_tonumber .. luaV_execute | `luaV_*` |
| `lua/lstring.cpp` | 0x002192c0..0x00219520 | luaS_freeall .. luaS_newudata | `luaS_*` |
| `lua/lfunc.cpp` | 0x00219520..0x00219870 | luaF_newCclosure .. luaF_getlocalname | `luaF_*` |
| `lua/ltable.cpp` | 0x00219870..0x0021a550 | hashnum .. luaH_setstr | `luaH_*` |
| `lua/lzio.cpp` | 0x0021a550..0x0021a790 | luaZ_fill .. luaZ_openspace | `luaZ_*` |
| `lua/ldump.cpp` | 0x0021a790..0x0021add0 | DumpString .. luaU_dump | the Dump* writers |
| `lua/lmem.cpp` | 0x0021add0..0x0021aeb0 | luaM_realloc, luaM_growaux | `luaM_*` |
| `lua/llex.cpp` | 0x0021aeb0..0x0021c190 | luaX_init .. llex | `luaX_*` |
| `lua/lparser.cpp` | 0x0021c190..0x0021f800 | next .. luaY_parser | the parser's statements and expressions |
| `lua/lundump.cpp` | 0x0021f800..0x002204e0 | the "lundump error" helper .. luaU_undump | the Load* readers |
| `lua/lcode.cpp` | 0x002204e0..0x00221b30 | fixjump .. luaK_patchlist | `luaK_*`. The core ends at luaK_patchlist, as native-build.md records (0x00221ae0) |
| `choreo2/unk_221b30.cpp` (not Lua) | 0x00221b30..0x002222f0 | copy helpers; 0x002222d0 stores `choreo2::PartitionDriver`'s vftable 0x00427260 | the callers are choreo2 (0x00223fa0) and game code. The callees are the 0x0022b… math objects. Today this run is wrongly inside the Lua TU |
| `lua/lauxlib.cpp` | 0x00338d90..0x0033a080 | 0x00338d90 (no name; called by luaL_error and luaB_error), luaL_error .. luaL_optint, including lua_dostring | `luaL_*`. 0x00339c30 (no name) is called by every `luaL_check*` |
| `lua/ldblib.cpp` | 0x0033a080..0x0033acd0 | 0x0033a080 / 0x0033a340 / 0x0033a430 (no names and no direct callers: reached through the luaL_reg table), db_getupvalue .. luaopen_debug | lua_getstack / lua_getlocal / lua_setlocal callers |
| `lua/ltablib.cpp` | 0x0033acd0..0x0033b610 | 0x0033acd0, foreach, luaB_getn .. luaB_sort, luaopen_table | |
| `lua/lmathlib.cpp` | 0x0033b610..0x0033bd00 | the math functions .. luaopen_math, including `os.exit` 0x0033bc80 | the game added `os.exit` to this file, before luaopen_math |
| `lua/lstrlib.cpp` | 0x0033bd00..0x0033d6e0 | string.len .. luaopen_string 0x0033d6c0 | luaopen_string is called by ScriptHandler 0x001d3c90 |
| `lua/lbaselib.cpp` | 0x0033d6e0..0x0033eb70 | luaB_print .. luaB_cocreate/cowrap/yield, luaopen_base 0x0033eb30 | the coroutine functions live in the base library, as in this work version |

**Why this is not applied yet: the ripple.** The data headers are generated per directory
(`include/decls/data/<layer>/<dir>.h`, `tools/data_gen.py` `write_decls`). config/data.json gives 159 items to
`unknown/unk_212bb0.cpp` and 193 to `unknown/unk_338d90.cpp`. Moving the objects to `lua/` therefore moves those
declarations from `engine/unknown.h` to a new `engine/lua.h`. Each of the 537 Lua sources (241 matches, 296
equivalents) that includes `decls/data/engine/unknown.h` would need the new include. That means re-running
`compare.py` on 241 sources and `equiv.py --inputs 3000` on 296, all of which become one TU-level `#include` line
at the flip. Two more files list the old TU name: `tools/wine_opt_tus.txt`, the `-O1` hot list (`unk_212bb0.cpp`
would become the hot Lua files, probably lvm/ltable/ldo/lgc/lapi), and `tools/reach.py`'s library-internals
pattern. **Recommendation: apply this table at the flip.** The steps are: add it as a fixed-span table in
`tools/infer_splits.py`, like `LIB_SPANS`, so a re-run keeps it; re-own the data items (`tools/data_inventory.py`
reads the splits); regenerate the data headers; and give the Lua TUs one `#include "decls/data/engine/lua.h"`. One
Wine proof covers it. If the user wants it before the flip, the cost is the 537-source re-verification above.

### Uncertain (left as they are, listed for the flip)

- **Registration TUs split into many objects.** The fight track/condition factories are COMDAT template
  instantiations. Each lands in the first object that registers it, and the inference labels each run by its
  template argument. As a result, 0x0004e000..0x00057000 holds 67 objects (36 with `_2`/`_3` suffixes, 540
  functions). 0x0006a000..0x00070000 holds 79 objects (32 suffixed, 603 functions) and 0x00150000..0x00159000
  holds 44 (27 suffixed, 417 functions). The 15 template-only `unknown/unk_*` objects (`unk_050500`
  `CAxisArcCondition`, `unk_06d590` `CClimbingTrack`, `unk_157800` `CollisionThrownObjectCondition`, ...) never sit
  next to their argument's own object. The pattern fits one registration file per family (conditions, tracks,
  motion conditions) that instantiates every factory, cut into one object per class by the inference. Merging them
  needs evidence this pass doesn't have: the registration function that names all of them, and `.rdata` string pools.
  This is the biggest naming question for the flip.
- **The big unattached runs.** `unknown/unk_0240b0.cpp` (291 functions), `unknown/unk_011000.cpp` (138),
  `unknown/unk_15a820.cpp` (138), `unknown/unk_14c470.cpp` (181, with 21 strays), `unknown/unk_17f2b0.cpp` (181),
  `unknown/unk_10c0d0.cpp` (119), `unknown/unk_11b800.cpp` (102), `unknown/unk_22baf0.cpp` (71, engine, in the
  `-O1` hot list), `unknown/unk_357740.cpp` (21, after LIBCMT: the math/collision library) and
  `unknown/unk_3137f0.cpp` (23). No class, no strings checked. Each needs a look at its callers and `.rdata` before
  it gets a real name.
- **`init/dynamic_initializers.cpp`**: each initializer belongs to the TU whose global it constructs. Recovering
  that needs the `.data` writes of each one (docs/splits.md, weak spots).
- **Affinity over-attachment**: `global/CCharacter.cpp` has 116 functions, 1 of them named. This is often right,
  but nothing bounds it.

## 2. Tools that write per-function sources

Audit of every writer of `matches/` / `equivalent/`. "Last run" comes from commit messages and is approximate. After
the flip, three things still need a tree-aware writer: formatting, the farm's `--rewrite` (readability) mode, and
any continuing 64-bit or naming batches (ptr1, ptr_fields, name_unify, rename_ids). Everything else is a finished
migration or a matching-era tool.

| tool | what it does | last commit / last run | recommendation |
|---|---|---|---|
| `tools/equiv_gen/reg_helper.py` | Registry::Register* helper sources | d7694febb 10-13 / a9f0adc8f 10-13 | **retire**. It produces nothing new. sh2 hand-converted its 123 helpers to member-function pointers (11-09). Its `emit()` still types every closure function pointer `void (*)()` with a 32-bit `char pad[0x1c]` layout, the form "Member-function pointers in the script closures" rules out. Because it is retired, its output is not fixed (the brief asked for the fix only if kept) |
| `tools/equiv_gen/closure.py`, `call_table.py`, `inlined_regs.py`, `props_reader.py`, `param_table.py`, `param_table_spec.py`, `read_xbe.py`, `templates/` | equivalence generators for script bindings, factory tables, property readers and fight parameter tables. They write to scratch dirs and were promoted by hand | 10-12 / 10-13 | **retire** (every function is verified; their outputs were hand-edited since) |
| `tools/migrate_gen.py` (+ `rn_transform.py`, `rn_members.py`, `rn_sigs.py`) | header migrations (gen-swap, gen-nv, gen-base, rn renames) so gen_tree merges | d78cbbd35 10-24 | **retire at the flip**. On a merged tree the rename is an edit of the TU. Until then it is how section 3's batches are applied |
| `tools/migrate_data.py` | per-source `extern DAT_` onto include/decls/data | 9d6e883c5 10-16/17 | retire (one-shot, done) |
| `tools/reconcile_stubs.py`, `rename_placeholders.py` | stub renames / placeholder suffixes | 10-15 / 10-14 (last 10-22) | retire (one-shot) |
| `tools/owner_classes.py`, `ptr_slots.py` | owners.h / pointer-sized slots, rewriting sources | 11-03 / 10-25 | retire (one batch each, done) |
| `tools/wine_fix.py` | clang/Wine source fixes behind a `--verify` gate | 79336d1ea 10-23 | retire (the edits are in the sources) |
| `tools/fix_vptr.py`, `fix_relocs.py`, `fix_literals.py`, `batch_run.py`, `permute.py`, `clone_matches.py`, `clone_equivalent.py`, `equiv_next.py` | matching-era rescue, cloning and older verifiers | 10-09 .. 10-23 | retire (matching is finished, every function verified) |
| `tools/ptr1.py`, `ptr_fields.py` | libclang pointer-width rewrites (64-bit) | 11-04 / 11-06 | **retarget** if the 64-bit cleanup continues: run over the TUs and patch the span of one function, found by its address marker |
| `tools/name_unify.py`, `rename_ids.py`, `rename_fields.py` | token renames: definitions' symbols, locals and parameters, include/gen field names | 11-03 | **retarget** if the naming batches continue, as a TU-wide token rename. Otherwise retire |
| `tools/format_matches.py`, `format_equivalents.py` | clang-format with a still-MATCH / same-object guard | 10-08 / 10-19 | **retarget** as one tree formatter (format a TU, then check each function). It must keep the per-function `// STATUS:` and `// name @ addr` lines |
| `farm/src/farm.ts` | the model farm: writes accepted results as `matches/` / `equivalent/` files; `--upgrade` deletes the equivalent copy; `--rewrite` rewrites proven sources (tech-debt readability) | 10-2x .. 11-0x | **user's call**. Matching mode: retire. `--rewrite`: retarget, to splice a body into the TU at its marker; `isDone` and upgrade need the tree's status |
| `tools/fn_names.py`, `param_fields.py`, `rn_ptrfields.py`, `promote_dispatch.py`, `agent_round.py`, lints | write JSON, headers or reports only | | keep as they are |

**Readers that list sources by directory** (about 120 tools: `grep -lE 'matches|equivalent' tools/*.py`) need one
tree-aware listing (address → TU, status) instead of `os.listdir`. Among them: compare.py, verify_relocs.py,
equiv.py (build4's stage 1), equiv64.py, equiv_batch.py, jobq_equiv.py, packet.py, progress.py, progress_map.py,
tech_debt.py, reach.py, wine_link.py, wine_build_run.py, native_mac.py, native64.py, data_inventory.py,
gen_headers.py, trace_capture.py / trace_gate.py (section 4), and `export_dataset.py` (user-owned, section 5 of the
report). Neither promotion script (`promote-remote.sh`, `equiv_batch.py`) writes into `equivalent/` itself: the copy
is done by hand or by farm.ts.

## 3. Merge rate on HEAD (`tools/rn_plan.py`)

`rn_map.py` was re-run on the working tree, against the last local strict-link binding map
(`build/native/bindings.json`, 10-17). `rn_plan.py` then ran with build3's tree state (job 70735, 11-09) as the
fallback:

| | rn1 snapshot (10-19) | HEAD (11-10) |
|---|---|---|
| merged / wrapped / isolated | 20,567 / 6,045 / 862 (74.9%) | **22,504 / 4,238 / 696 (82.0%)** |
| conflict-wrapped | 4,847 | 3,269: header-stub 1,875, function/data 977, layout 848, split 29 |

The top conflicting names now are `World` 166 (pinned type, header-stub), `pure3d::NonCopyable` 105,
`FUN_0027b020` 97, `Closure2` 96, `Node` 94, `Obj` 89, `Object` 86, `Closure1` 75 and `Function` 63. The scripted
batches left on HEAD (`rn_plan.py --batches`):

| batch | rule | candidates |
|---|---|---|
| b1 | unclash, matches/ | 70 items in 54 sources |
| b2 | gen-ref, matches/ | 70 items in 64 sources |
| b3 | unclash + gen-ref, equivalent/ | 115 items in 88 sources |
| b4 | relabel, both | 106 + 113 items, no merge effect (readability) |
| b8 | gen-base | 32 + 20 sources |

The earlier rounds (rn1, x64-1, x64-4) applied the bulk. What is left is small: most wrapped functions stay wrapped
for reasons a rename doesn't fix (header fields, signatures, the stub closures). Refined on HEAD with
`rn_plan.py --refine` (generator in the loop, no `--bindings`: the local binding map is from 10-17; the Wine proof's
unbound count is the link check instead):

| batch | refined | merge effect | done |
|---|---|---|---|
| b1 unclash, matches/ | 54 -> 53 sources | modelled +32 merged | **16 applied**. `migrate_gen.py --family rn` kept 51 (compare.py MATCH; 2 compile errors), with verify_relocs 51/51 ok and `equiv.py --wine` 51/51 equivalent (the originals 51/51 too). The first proof (70872 vs control 70869) gave GATE ok but **+10 Wine unbound**: 9 hand-written vftable variables (`vftableD`, `rawVtable`, `missionVftable`, `vftable_sym`, `vtableA`) and one ambiguous `vt_name`, in the 8 TUs where the renamed stubs now merge, so one invented name stood for two addresses. That is refine's `--bindings` rule, which could not run without a current binding map. The 35 sources of those 8 TUs (hulkfight/unk_0185f0, global/unk_01cf40, unk_01eff0, unk_020a40, unknown/unk_10c0d0, hulkfight/GameStateCondition, unknown/unk_17b330, fight/FightNodeTimeCondition) were put back; 16 sources remain. Proof 70888 (studio, seeded from control 70869, play3 to 60,000): GATE ok (2,006 common frames, PRNG hashes identical), Wine unbound 1,251 -> 1,251 (one stub virtual renamed: `DrawableNode::Dummy` -> `LeafNode_295fd0::Dummy`), x87 keep list 266, identical |
| b2 gen-ref, matches/ | 64 -> 10 -> 5 sources | +1 merged | not applied (one function for a batch) |
| b3 unclash + gen-ref, equivalent/ | 88 -> 28 -> 15 sources | about +6 merged on top of b1 | not applied (15 sources at 3,000 inputs for six functions) |

With the 16, the measured numbers (rn_plan on the same fallback state, control 70869) are **merged 22,504 -> 22,514, wrapped 4,238 -> 4,228, isolated 696 -> 696**.
The remaining scripted renames are not worth doing before the flip. On a merged tree the remaining work is
header fields (b7), signatures (b6) and the closure stubs. Each of those is an edit of the TU, with no per-source
churn.

## 4. Hybrid xemu

Recording needs only the hook-only XBE (`patch_xbe.build([])`: hooks.cpp, tweaks, pins). It needs no compiled
sources, only an address list of trace targets that comes from the `matches/` / `equivalent/` directories. Function
patching (`compare`, `bisect_hybrid.py`) is superseded by Wine proofs. Details and the retirement proposal:
[hybrid-build.md](hybrid-build.md), "After merge-once".
