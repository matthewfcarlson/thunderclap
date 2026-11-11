# In this repo (Thunderclap: The Incredible Hulk: Ultimate Destruction)

Concrete paths, tools, bars and history behind the general rules in SKILL.md, matching.md, codegen-pitfalls.md and
tooling-design.md. **CLAUDE.md is authoritative** for layout, commands, builds and proofs, compute and hard rules; read
it first. This file adds the operational lessons and says where the generic advice no longer fits this repo. Run
everything from the repo root with `build/venv/bin/python` (written `$J` below). Updated 2026-11-11 for the merge-once flip.

## Where the project is

- Every game function (about 27,400; 2.7 MB of game code, dead COMDAT bodies and XDK/CRT/Bink spans left out) has
  verified source: about 81% of functions byte-matched, 67% of bytes proven equivalent (README's table, from
  `tools/progress.py --readme`). Engine: Radical's Pure3D/radcore (RTTI namespaces `pure3d`, `choreo2`, `fight`,
  `physics`, `audio`, ...), Lua 5.1 game scripts, RCF archives. A leaked source of another game on this engine exists:
  never look at it (CLAUDE.md, `docs/prior-art.md`).
- **Phase: the port.** Matching at scale is over. Current work is the 64-bit native builds (x86-64 SteamOS, arm64
  macOS, arm64 Android handhelds; Windows is not a target), with the Wine build (32-bit clang image under Wine) as the
  development and verification build. The remaster's multiplayer is designed but **paused** (`docs/multiplayer.md`).
- Plan: `docs/roadmap.md`; findings log: `docs/journal.md` (the coordinator usually owns it); history behind the generic
  advice is in the journal (e.g. 2026-10-08 aligned diff, 10-11 "research once, apply many" and the vptr-sink recipes,
  10-12 the permuter's 0/70 on residue).

## The merged tree (since the flip, F = e68debc9d, 2026-11-10)

SKILL.md's "one self-contained TU per function, separate directories for matched and equivalent" describes how this
repo got here, not how it works now (`docs/merge-once.md`):

- `src/game/`, `src/engine/`, `src/platform/xbox/` hold one TU per recovered object (`config/splits.json`), in link
  order (`src/link-order.txt`). Siblings carry other flags or forms: `<File>.GS.cpp`, `.O1.cpp`, `.Oy-.cpp` (first
  line `// cl-flags: ...`), `.new_<form>.cpp` (placement new), `.iso_<addr>.cpp` (one isolated function). Wrapped
  blocks keep their original source verbatim in `namespace fn_<addr> { }`.
- A function is a block: `// 0xADDR NAME (SIZE B): matches/0xADDR.cpp` (or `equivalent/...`, plus `[wrapped: why]`;
  the path names the frozen file, the kind is what counts) then `// sym: <mangled>` (its pinned symbol in the TU's MSVC
  object), its notes (`// STATUS:`, provenance) and its `// equiv-map:` / `equiv-conv:` / `equiv-dead:`
  directives, which are read from that block only. MSVC's numbered `$L` labels (funclets, catch blocks) renumber on any
  header edit, so they are pinned as `$L#k@owner` (the k-th `$L` label of the owning function).
- **Edit the block in its TU.** `matches/` and `equivalent/` are frozen at F: never add or edit files there; removing
  them awaits the user's OK. Tree headers: `include/common.h`, `include/tree_prelude.h`, `include/{game,engine,platform/xbox}/`;
  `include/gen/`, `include/decls/`, `include/compat/` as before.
- Find a function's TU: `grep -rl "^// 0x00013940 " src/game src/engine src/platform/xbox` (the block line). `tools/packet.py show 0xADDR` still gives
  the asm, Ghidra hint and referenced data.
- The tree holds no game data: variable definitions became `extern` declarations; the data TUs are generated locally
  (`tools/data_gen.py` -> `build/data/src`) from the player's XBE.

```sh
$J tools/tree_tu.py blocks TU.cpp                    # its functions: address, kind, mode, symbol
$J tools/tree_tu.py check TU.cpp --relocs [--equiv N [--wine|--x64]]   # every function of one TU
$J tools/tree_tu.py verify . --changed-since origin/main --relocs [--jobs N] [--out OUT.jsonl]  # incremental, cached
$J tools/tree_tu.py pin . [--records OUT.jsonl]      # rewrite `// sym:` after an edit that changes a symbol (pin_missing)
$J tools/tree_tu.py materialize --out build/tree     # the committed tree as a local Wine-build input
```

Objects and check records are cached by content (`build/tree-cache/obj/`, `build/tree-cache/tuverify/`): an unchanged
TU is not recompiled or rechecked. A header edit reaches every TU that can include it; `verify --changed-since` then
walks them all, so run it through the queue.

## Verification bars

```sh
$J tools/compare.py TU.cpp 0xADDR                        # MATCH or aligned diff (--full for the whole function)
$J tools/verify_relocs.py TU.cpp --addr 0xADDR --json    # status "ok" (includes float bits, initializers)
$J tools/equiv.py TU.cpp 0xADDR --json --inputs 3000     # "promotable": true
$J tools/equiv.py TU.cpp 0xADDR --wine --json            # the clang object the Wine build runs
$J tools/equiv.py TU.cpp 0xADDR --x64 --json             # the 64-bit object vs the 32-bit clang object
$J tools/x87_order.py TU.cpp 0xADDR                      # float operation grouping vs the original
$J tests/equiv/regress.py --jobq --name ME               # after ANY change to tools/equiv.py
```

- An edited `matches` block: still MATCH, relocations ok. An edited `equivalent` block: a fresh promotable run at 3,000
  inputs (no level-2 conflicts, >= 75% branch coverage, >= 50 completed), plus `--wine` (promotions gate it at 600
  inputs, `tools/wine_gate.py`), plus `--x64` where the 64-bit build compiles the TU. A 64-bit fix changes the source,
  never the 32-bit proof: re-check both sides. Update the block's `// STATUS:` line with the run that proved it.
- Slow functions need `--time-budget`/`--steps` and a matching queue `--limit`. Never shard one proof by seed range.
- Checker rules are switchable (`EQUIV_OFF=rule,...`, `EQ64_OFF=...`, replay `REPLAY_OFF`); dev copies live as untracked
  `tools/equiv_<round>.py`. Never edit `tools/equiv*.py` or `tests/equiv/` outside a checker-round task. Writable-global
  sweep, `fconst`, `initbytes`, `argcall` and later rules exist because wrong sources passed: read the round notes in
  `docs/equivalence.md` before calling something a checker bug.

## Matching and x87 here

- `cl` 13.10.3077, base flags `/O2 /GR /GX` (`/Gy` in the tools); `/GS` objects are the `.GS.cpp` siblings (with a plain
  `char buf[N]`). The CRT/XAPI region around 0x34xxxx-0x35xxxx is `/O1 /Oy-` (library code: not decompiled); a few game
  objects are `/O1` or `/Oy-`. `_ftol` is `FUN_0034483c`; the XBE's own CRT routines are identified by behaviour in
  `tools/equiv.py`.
- Best MSVC 7.1 reading: `farm/src/prompt.ts` (symptom table; Pure3D idioms such as `p3d::find<T>(name)`,
  `new(allocator) T(...)`, `DynamicCaster<T>`) and `docs/agents/match-brief.md` (vptr and register-allocation studies).
  The briefs predate the flip: their file paths and install steps are historical.
- `hulk_freg` (`include/compat/ptr.h`): `float` under MSVC, `double` under clang, for locals and returns the original
  keeps in x87 registers. Recurring Wine-build fixes: `hulk_freg` toggling, dropping elided `(float)` casts, hoisting
  argument calls ahead of the receiver, `(int)(__int64)f` for `__ftol2`, dword-then-byte inline loops for the
  memcmp/strlen the original inlined (byte loops time out), `__forceinline` helpers, `-fcheck-new`.
- 64-bit spellings: `#if defined(HULK_PTR64)` branches, `hulk_intptr`/`hulk_uintptr`, typed records in
  `include/decls/data/` (records.h, lua.h, script.h), all source text inside the blocks.

## Builds and proofs

CLAUDE.md "Builds and proofs" is the rule; the details are in `docs/compute.md` "Wine builds", `docs/wine-build.md`,
`docs/wine-replay.md`.

- **Wine build**: `tools/wine_build_job.py submit --name ME [--workspace DIR] [--live tools src/platform] --gfx
  [--replay play3 --frames N]`, then `wait`, `compare ID1 ID2`. It materializes the committed tree (no build_tree
  rounds; `--env HULK_TREE_SOURCE=0` or a pre-flip commit falls back to them). Use it rather than private local builds:
  a private snapshot goes stale.
- **Proving a change to shared code** (headers, records, renames, anything beyond one checked block): a control (HEAD
  without the change) and a proof (with it), same host, same local inputs, `--gfx --replay play3 --frames 60000`; the
  proof takes `--state seed:CONTROL` (pins it to the control's host; tree-mode controls save an empty
  `tree-state.json`, so a control from before 2026-11-11 must be rebuilt). Gate: `tools/ckpt_gate.py CONTROL PROOF`
  must print GATE ok (the proof ok wherever the control is; `--known` lists known transient frames). Commit messages
  name the control, the proof and the gate result.
- **Stale inputs**: `build/data/src`, `hulk_sdl.lib`, `hulk_movies.lib` and the pddi-win32 objects are generated locally
  and stamped with their sources' hash. `$J tools/input_guard.py status [--workspace DIR] [--live ...]` shows what submit
  would decide (rebuild if clean, refuse if dirty); the host ends a stale job with exit 3. Private copies via
  `--data-src` / `--sdl-src`; a control and its proof take the same ones. `--allow-stale` is not a fix.
- **Native 64-bit**: `$J tools/native_mac.py compile|link` (arm64 macOS), `$J tools/native_elf.py compile|link --target
  linux-x64|android-arm64`; snapshot via `HULK_CLANG_PROBE_DIR`. The link refuses a compile report with a failed tree or
  data TU (`--allow-compile-failures` is for diagnosis only). Unbound names (~22k per target): `$J tools/native_unbound.py
  classify --dir build/native-mac`; fix them in source by root cause (renames at the definition or in shared headers,
  real types at callers), never by a link-time redirect of local vftables to the game's (`docs/native-unbound-plan.md`).
  Batches log under their own heading in `docs/native-build.md`; `tools/equiv64.py batch LIST OUT` checks a batch at 64 bits.
- Per-function rewrite tools (`fix_relocs`, `fix_literals`, `fix_vptr`, `format_matches`/`format_equivalents`,
  `clone_matches`/`clone_equivalent`, `ptr1`, `ptr_fields`, `name_unify`, `rename_ids`, `tech_debt`) were written for
  `matches/`/`equivalent/` and are not all retargeted to TU blocks: read a tool before running it, and never let one
  write into the frozen directories.

## Compute

CLAUDE.md "Compute" and `docs/compute.md` are the rules. Lessons:

- `tools/jobq.py submit|wait|result|status|cancel|submit-many`; equivalence batches `tools/jobq_equiv.py LIST OUT.jsonl
  --name ME -- --inputs 3000` (LIST lines `0xADDR path`, which may be a TU; reruns resume). Jobs run on a `git archive`
  of committed `tools include tests config src` plus your overlay: `--dirty` or `--files` ships uncommitted TUs and
  headers. The hosts' `matches/`/`equivalent/` are stale symlinks to their own checkouts.
- Remote hosts (mac2, mac1, studio) take the work; the laptop takes only `wine-gfx`. `xemu` runs on mac2 and studio,
  one at a time each. Host config is the untracked `build/jobs/hosts.json`.
- Inside `sh -c '...'` job strings write `build/venv/bin/python`, not `python` (exit 127).
- The daemon (`build/jobs/daemon.log`) exits after 15 idle minutes and restarts on submit; host slots reload every
  30 s. A restart kills running jobs: check `status --all` first and resubmit any that gave up.
- Private queues for testing queue changes: `JOBQ_DIR=build/<agent>/jobs` with its own daemon (stop it after).

## Emulator (xemu)

- Only on the designated hosts, never on the laptop; one instance at a time (`HULK_XEMU_INSTANCE=N` picks ports);
  always `-snapshot`, or a per-recording qcow2 overlay over the read-only base HDD. The queue refuses backup/mirror
  commands and the xemu settings folder.
- xemu now only records: `hybrid/` is the hook-only XBE (determinism hooks, no game code patched in). Record with
  `tools/hybrid_test.py record`; capture and replay traces with `tools/trace_gate.py`, `tools/trace_capture.py`,
  `tools/equiv_replay.py` (absolute `--src-dir`), `tools/equiv_confidence.py`. Captures (`build/traces/*/trace.sqlite`)
  hold game memory: never commit. Recordings: `build/replays/*.json` (play3 is the reference run; `tools/replay_pack.py`).

## Retired (kept for reference; don't restart without the user)

| Retired | Replaced by |
| --- | --- |
| Per-function sources as the source of truth (`matches/`, `equivalent/`) | blocks in tree TUs (frozen at F) |
| `tools/build_tree.py` / `gen_tree.py` rounds as the build's source | `tree_tu.py materialize` (`HULK_TREE_SOURCE=0` for history) |
| Model farm (`farm/`, `tools/batch_run.py`, fine-tuned `ulk-*` and ChatGPT lanes) | done; `farm/src/prompt.ts` stays as reading |
| Hybrid function patching (`patch_xbe.py` source selection, `hybrid_test.py compare`, bisect) | Wine-build replays gated by `ckpt_gate.py` |
| CPU permuter (`tools/permute.py`) | nothing: the matching campaign is over |
| Per-function briefs (`docs/agents/`, most of `docs/tasks/`) | CLAUDE.md, `docs/merge-once.md`, the current docs |

## Agents and commits

- Agent directory `build/<agent>/` with `RESUME.md`, `claimed.txt`, `files.txt`, `notes.md` (SKILL.md section 7); claims
  are now TUs and headers, not addresses. Use a private workspace and lineage per agent for builds, and delete your own
  large scratch under `build/<agent>/` at hand-back.
- Don't touch unless it is your task: `tools/equiv*.py`, `tests/equiv/*`, `docs/journal.md`, `docs/game-functions.csv`,
  `tools/export_dataset.py`, `tools/train_sft_unsloth.py`, `farm/tiers-*`, anything in another agent's
  `files.txt`/`claimed.txt`; never `matches/`/`equivalent/`. Untracked files of other sessions stay untouched and
  uncommitted.
- Commit explicit paths only: `F=(a b); git commit -m MSG -- "${F[@]}"` (zsh: `F=(${(f)"$(cat build/AGENT/files.txt)"})`);
  check the staged diff holds only your hunks (`git diff --cached --stat`). Partial hunks of a shared file: build a
  filtered patch, `git apply --cached --check`, then `git apply --cached`. Push as CLAUDE.md says.
- Usage gate: `build/agent-tools/usage-gate.sh [T5H [WEEKLY]]` (exit 1 = blocked; defaults 90 / 95). The agent cap and
  pacing are the user's call and change; follow the coordinator's current notes.
- Scratch cleanup: `build/agent-tools/clean-scratch.sh` (dry run) then `--yes`, only with the user's OK.

## Incidents and traps

- Disk: about 90 private build trees (1-5 GB each) filled the laptop to 0 bytes; shell calls and the daemon died.
- Queue: 42 jobs exited 127 from a bare `python` in `sh -c`; slow functions "gave up" on default limits; seed-range
  shards came back inconclusive; a daemon restart killed another agent's 7-hour proof.
- Stale local inputs broke images with no source change (data TUs from days earlier left .bss items unbound and crashed
  at init 332; an old `hulk_sdl.lib` lacked new symbols). Hence the stamps and the guard.
- Emulator: a `drive-backup` on a `-snapshot` drive unlinked the only local base HDD.
- Screenshots: compare with a one-frame offset and the half-pixel fix (`HULK_GFX_HALFPIXEL`) before calling a
  rendering difference real.
- A header regex pass must handle template specializations; check every affected TU (`tree_tu.py verify --changed-since`)
  before landing a header change (x64-2 once broke 355 matches).
- `gen_headers` needs the XBE present, or every destructor slot comes out as `vfunc_N(unsigned char)`.
- Per-host LLVM differs: resolve through `clang_probe.LLVM`/`tool()`, never hard-code a path.
- Sources that hard-code a script-written global (spawn distances, AI thresholds) pass fuzzing and fail replay.
