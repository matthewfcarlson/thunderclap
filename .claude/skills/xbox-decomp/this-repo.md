# In this repo (Thunderclap: The Incredible Hulk: Ultimate Destruction)

Concrete paths, tools and conventions behind the general rules in SKILL.md. CLAUDE.md is authoritative for layout,
commands and hard rules; this file adds the operational lessons. Run everything from the repo root with
`build/venv/bin/python` (written `$J` below).

## Status and terms

- Every game function is verified: `matches/0xADDR.cpp` (byte-matched) or `equivalent/0xADDR.cpp` (proven; first
  line `// STATUS: equivalent (tools/equiv.py level 3: N inputs, branch coverage a/b)`). README's table and
  `docs/progress-map.svg` come from `tools/progress.py --readme`; `docs/tech-debt.md` from `tools/tech_debt.py`.
- Work now is the port: the **Wine build** (32-bit clang image under Wine; `tools/wine_*.py`, `docs/wine-*.md`,
  `HULK_WINE_*`, `equiv.py --wine`; old `native_*`/`--native`/`HULK_NATIVE_*` names are aliases), then **native**
  64-bit builds (x86-64 Windows/SteamOS, arm64 macOS; `docs/consolidation-plan.md`). Still native-named on purpose:
  `build/native/`, C++ `HULK_NATIVE_*` macros, `tests/native_*`.
- Docs to read by area: `docs/equivalence.md` (checker, rounds, replay, x87 order check), `docs/compute.md` (queue),
  `docs/wine-build.md`, `docs/wine-float.md`, `docs/wine-replay.md`, `docs/hybrid-build.md`, `docs/graphics-backend.md`,
  `docs/platform-boundary.md` (library/platform rules), `docs/journal.md` (findings log; append, the coordinator
  usually owns it).

## Verification commands and bars

```sh
$J tools/compare.py SRC.cpp 0xADDR                         # MATCH or aligned diff (--full for whole-function view)
$J tools/verify_relocs.py SRC.cpp --addr 0xADDR --json     # status "ok" required (includes float bits, initializers)
$J tools/equiv.py SRC.cpp 0xADDR --json --inputs 3000      # "promotable": true required
$J tools/equiv.py SRC.cpp 0xADDR --wine --json             # the clang object the Wine build runs
$J tools/x87_order.py SRC.cpp 0xADDR                       # float operation grouping vs the original
$J tools/lint_floats.py                                    # float literals near but not equal to original constants
$J tests/equiv/regress.py --jobq --name ME                 # after ANY change to tools/equiv.py (also replay_regress.py)
```

- Promotion of a new equivalent: 3,000 inputs, `promotable` (no level-2 conflicts, >= 75% coverage, >= 50 completed).
  Replacing an existing `equivalent/` file or a fix batch: 20,000 inputs (`promote-remote.sh` with `REPLACE=1
  INPUTS=20000`, or `jobq_equiv.py ... -- --inputs 20000 --max-inputs 20000`). Slow functions need
  `--time-budget`/`--steps` and a matching queue `--limit`.
- The `STATUS` line records the run that proved it; update it when a source is re-proven.
- Checker rules are switchable with `EQUIV_OFF=rule,...` (replay: `REPLAY_OFF`); dev copies live as untracked
  `tools/equiv_<round>.py` modules until promoted. Never edit `tools/equiv.py` outside a checker-round task.
- Formatting: `tools/format_matches.py`, `tools/format_equivalents.py` (keeps the format only if the object is
  unchanged). Generated farm rewrites go through the same formatter.
- Writable-global sweep, `fconst`, `initbytes`, `argcall` and the round-21 rules exist because sources passed while
  being wrong; read the round notes in `docs/equivalence.md` before calling something a checker bug.

## x87 in this tree

- `hulk_freg` (`include/compat/ptr.h`): `float` under MSVC, `double` under clang. Use it for locals and returns the
  original keeps in x87 registers; header-declared float virtuals may need it too (generator issue).
- Recipes that recur in Wine-build fix batches (nf2/nf3 notes): `hulk_freg` toggling, dropping elided `(float)` casts,
  hoisting argument calls ahead of the receiver, `(int)(__int64)f` for `__ftol2`, inline loops for memcmp/strlen the
  original inlined (dword-then-byte, not byte loops: they time out), `__forceinline` helpers, `-fcheck-new`.

## Compute

- Queue: `tools/jobq.py submit|wait|result|status|cancel|submit-many` (see `docs/compute.md`). Batches:
  `tools/jobq_equiv.py LIST OUT.jsonl --name ME -- --inputs 3000` (LIST lines `0xADDR path.cpp`; reruns resume).
  `equiv_batch.py` and `promote_dispatch.py` submit through it by default.
- Hosts: the laptop plus the remote checker Macs named in the untracked `build/jobs/hosts.json` (template
  `build/agent-tools/hosts.json`). Remote checkouts' `matches/`/`equivalent/` are stale: ship sources with the job.
- `--needs xemu` runs only on the designated emulator host, one at a time; `wine` on all hosts headless; `wine-gfx`
  laptop only (pictures).
- Wine builds: `tools/wine_build_job.py submit --name ME [--workspace DIR] [--live tools src/platform] --gfx
  [--replay play3 --frames 1000]`, `wait`, `compare`. Use it rather than private local builds: a private workspace
  snapshot goes stale (sky2's predated a sound fix and crashed at frame ~300). Replays:
  `tools/wine_replay_job.py submit|wait|compare`; same checkpoint hashes on every host with `HULK_SYNCIO=5`.
- Inside `sh -c '...'` job strings write `build/venv/bin/python`, not `python` (exit 127 on the laptop).
- Daemon: `build/jobs/daemon.pid`, log `build/jobs/daemon.log`; exits after 15 idle minutes, restarts on submit.
  Host slots and caps reload every 30 s. A restart kills running jobs: check `status --all` first.
- Private queues for testing queue changes: `JOBQ_DIR=build/<agent>/jobs` with its own daemon (stop it after).

## Emulator (xemu)

- Only on the designated emulator host, never on the laptop; one instance at a time (`HULK_XEMU_INSTANCE=N` picks
  ports); always `-snapshot`, or a per-recording qcow2 overlay over the read-only base HDD (user-approved design).
  The queue refuses backup/mirror commands and the xemu settings folder.
- Recording and capture: `tools/hybrid_test.py record`, `tools/trace_gate.py`, `tools/trace_capture.py`; replay with
  `tools/equiv_replay.py`/`equiv_replay_fn.py` (absolute `--src-dir` paths), summarise with `tools/equiv_confidence.py`.
  Captures (`build/traces/*/trace.sqlite`) hold game memory: never commit.
- Recordings: `build/replays/*.json` (play3 is the reference run), packed with `tools/replay_pack.py`.

## Agents and commits

- Agent directory: `build/<agent>/` with `RESUME.md`, `claimed.txt`, `files.txt`, `notes.md`, `pending/`. Equivalence
  fix batches also use `build/farm/bench/claude-equiv/{work,pass,match}/` and append to its `log.jsonl` (append only).
  Briefs: `docs/agents/equiv-brief.md`, `docs/agents/match-brief.md`, `build/farm/bench/claude-equiv/brief.md`
  (recipes by batch), `farm/src/prompt.ts` (MSVC symptom table; keep it byte-stable, providers cache it).
- Files agents must not touch unless that is their task: `tools/equiv*.py`, `tests/equiv/*`, `docs/journal.md`,
  `docs/game-functions.csv`, `tools/export_dataset.py`, `tools/train_sft_unsloth.py`, `farm/tiers-*`, and anything in
  another agent's `files.txt`/`claimed.txt`.
- Untracked files that belong to other sessions stay untouched and uncommitted (e.g. some `matches/` and
  `equivalent/` files, `tools/equiv_r*.py`, `farm/tiers-*.json`). Check `git status` against agents' `files.txt`.
- Commit (coordinator): `F=(${(f)"$(cat build/AGENT/files.txt)"}); git add -- "${F[@]}"; git diff --cached --stat`,
  then commit with the session's attribution lines and push with
  `git push -q || (git pull -q --no-rebase --no-edit origin main && git push -q)`. Partial hunks of shared files:
  build a filtered patch, `git apply --cached --check` then `git apply --cached`.
- Usage gate: `build/agent-tools/usage-gate.sh [T5H [WEEKLY]]` (reads the status line's `~/.claude/usage-limits.json`;
  exit 1 = blocked). Current cap is usage-based: new agents only while the 5-hour window is under ~60% and the weekly
  window is on pace; ~4 strongest-model agents at most; hard stop at 90% (5-hour) / 95% (weekly).
- Scratch cleanup: `build/agent-tools/clean-scratch.sh` (dry run) then `--yes`; `KEEP="name ..."`, `MIN_MB`,
  `AGE_MIN`. It keeps folders changed recently, used by a running process, or named in a `RESUME.md` from the last two
  days. Run it only with the user's OK; the permission system blocks bulk deletes, so the user may run it with `!`.
- The ChatGPT/model-farm lanes are paused while structural work (64-bit consolidation, Wine-build fixes) runs: lane
  rewrites collide with them. Don't restart a lane without the user.

## Known traps (from agents' notes)

- A full disk or a reboot wipes or corrupts scratch workspaces; x64-2 recovered its batch from the remote build
  lineage (`~/hulk-jobs/nb/ws/<lineage>` on the build host) and queue outputs (`build/jobs/out/ID/`).
- `rn_sigs`-style regex passes over headers must handle template specializations; hash every affected object old vs
  new before applying a header change (x64-2 caught 355 matches that stopped compiling).
- `gen_headers` needs the XBE present or every destructor slot comes out as `vfunc_N(unsigned char)`.
- Per-host LLVM differs (Homebrew on the laptop, `~/llvm` remotely): resolve through `clang_probe.LLVM`/`tool()`,
  never hard-code a path.
- Checkpoint hashes: the hybrid hashes mid-`Update`; the Wine build hashes at entry with `clock_at_entry`. Compare
  screenshots with a one-frame offset (native N-1 vs hybrid N) and remember the half-pixel offset fix
  (`HULK_GFX_HALFPIXEL`).
- Sources that hard-code a script-written global (spawn distances, AI thresholds) pass fuzzing and fail replay.
