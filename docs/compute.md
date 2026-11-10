# Compute: the shared job queue

Heavy work does not run on the laptop. `tools/jobq.py` is a shared queue with a scheduler daemon that spreads jobs over
mac2 and mac1 by free capacity (the laptop takes only `wine-gfx` jobs: its `caps` in `hosts.json` are `["wine-gfx"]`) (it reads each host's load and sizes the slots from it). Everything that
takes more than a minute or a few cores goes through it: `equiv.py` beyond a quick single check, `build_tree`, regress
suites, scans and sweeps. At most 2 local processes for interactive debugging.

## Submit, wait, look

```sh
J=build/venv/bin/python; Q=tools/jobq.py
id=$($J $Q submit --name MYNAME --needs equiv --limit 1800 --out build/tree.log -- python tools/build_tree.py --rounds 16)
$J $Q wait $id                 # exit 0 done, 1 failed or gave up, 2 timeout (--timeout S)
$J $Q result $id               # exit code, host, attempts, paths of the log and outputs under build/jobs/out/ID/
$J $Q status [--name MYNAME] [--all]    # per submitter counts, running jobs, host slots and load
$J $Q cancel $id | --name MYNAME
$J $Q submit-many cmds.txt --name MYNAME --needs equiv    # one shell command per line, or jsonl; one id per line
```

- Options: `--needs any|equiv|msvc|clang|wine|wine-gfx|xemu`, `--files PATH|SRC=DEST ...`, `--dirty`, `--out PATH ...` (paths relative
  to the workspace, fetched to `build/jobs/out/ID/PATH`), `--limit S` (wall clock per attempt, default 1800),
  `--slots N` (cores the job uses, default 1), `--attempts N` (default 3), `--prio N`, `--base PATHS`.
- The command is an argv after `--`; use `python` for `build/venv/bin/python`. Use `sh -c '...'` for pipes and redirects.
  Environment: `JOBQ_JOB`, `JOBQ_ATTEMPT`, `JOBQ_HOST`.
- The queue is `build/jobs/queue.sqlite`. `submit` starts the daemon (`jobq.py ensure`; log `build/jobs/daemon.log`,
  it exits after 15 idle minutes). Jobs survive a daemon restart.
- States: queued, running, done (exit 0), failed (the command exited non-zero: not retried), gaveup (infrastructure
  failed `--attempts` times: ssh drop, wall-clock limit), cancelled.

## Equivalence batches

```sh
$J tools/jobq_equiv.py LIST OUT.jsonl --name MYNAME [--per 2] -- --inputs 3000 --max-inputs 3000
$J tools/equiv_batch.py LIST OUT.jsonl --jobq --name MYNAME -- --inputs 3000     # same, from the old entry point
$J tools/promote_dispatch.py NAME LIST OUT.jsonl --hosts X --jobq ...            # same queue, same output format
$J tests/equiv/regress.py --jobq --name MYNAME                                   # all regress cases, sharded
```
**Promotion is gated on both modes** (round 23): `promote_dispatch.py` (and so `promote-remote.sh`) re-checks the MSVC passes
(3,000 inputs) with `--wine` at 600 inputs through the queue (`OUT.wine.jsonl`) and marks each record's `wine_gate`; the
installers (`promote-remote.sh`, `clone_equivalent.py`, `wine_fix.py`, the farm) promote only sources that pass both
(`tools/wine_gate.py`). `--no-wine-gate` (`NO_WINE_GATE=1` for `promote-remote.sh`, `HULK_NO_WINE_GATE=1` anywhere) skips
the `--wine` check where the Wine toolchain (LLVM clang) is unavailable. `tools/decl_lint.py --all --jobq --name ME --out
OUT.jsonl` runs round 23's declaration-arity lint over every source (level 2 only, ~0.3 s a source).

LIST lines are `0xADDR path/to/source.cpp`. Sources travel with their job, so uncommitted candidates work. `OUT.jsonl`
is appended as results arrive and addresses already in it are skipped (rerun to resume).

## What runs where

| `--needs` | hosts |
| --- | --- |
| `equiv`, `msvc`, `clang`, `any` | mac2, mac1 (not the laptop) |
| `wine` | mac2, mac1 (headless Wine replays; `wine64` in argv0 is expanded to the host's Whisky Wine: the app's copy on the laptop, `~/wine-whisky` on the Macs) |
| `wine-gfx` | laptop only (a Wine run that draws through MoltenVK; see Wine replays) |
| `xemu` | mac2 and the Mac Studio (`studio`), one at a time on each, never the laptop |

Hosts and capabilities: `build/jobs/hosts.json` (untracked: it holds user and host names; created from
`build/agent-tools/hosts.json` on first use; fields `slots`, `caps`, `pref` (lower is preferred), `path`, `xemu_max`,
`python` (the host's interpreter for the runner, default `python3`; a host without the Command Line Tools names its venv's),
`any` (default true; false: the host takes only jobs whose `--needs` is one of its caps, for a host that cannot run
MSVC, such as the Mac Studio without Rosetta)).
A host added to `hosts.json` joins the running daemon within 30 s (no restart); see "Adding a host" below.

## Workspaces

A job runs in a fresh clone (APFS clonefile) of a per-host cached base tree, `git archive HEAD tools include tests config src`
(keyed by the content hash of those trees, kept under `~/hulk-jobs/ws`, newest 4 kept), plus the job's overlay files.
`build/ isos/ matches/ equivalent/ farm/ docs/` are symlinks to the host's own checkout (`~/hulk-permute` on the
Macs), so the jobs share its compilers, venv and caches. Consequences:

- Committed `tools/` and `include/` are what runs. For uncommitted files pass `--files` (or `--dirty`: every modified or
  untracked file under `tools include tests config src`; `jobq_equiv.py` and `regress.py --jobq` do this by default).
- `matches/` and `equivalent/` on the Macs are whatever was last synced there, not your working tree.
- `src/` ships in the base tree (bink2, 2026-11-09). Before that it was a symlink to the host's checkout, which is a
  one-time `git archive` snapshot from the host's onboarding: mac2 and mac1 (onboarded before `jobq_host_setup.sh`
  existed) had no `src/` at all and studio's was three days stale, so a native compile job (`native_elf.py` /
  `native_mac.py`) failed its retarget stage on mac2 / mac1 for every TU with a float-returning call
  (`tools/native_float.py` reads `src/platform/sdl/crt/native_crt_table.h`: `FileNotFoundError`, 226 TUs) and
  silently used an old table on studio. The tools' only `src/` dependence is that table (`HULK_NATIVE_CRT_TABLE`
  overrides it in native_elf.py, native_mac.py and native_float.py alike); everything else a job needs from `src/`
  (the clang probe's platform sources) comes from the base tree, the same bytes on every host.
  Verified on one clang-probe snapshot (control 70622's): the linux-x64 compile on studio / mac2 / mac1 (jobs 70646 /
  70648 / 70650) and the android-arm64 compile on studio / mac2 (70647 / 70649) give the same report (2,649 of 2,652
  TUs, the 3 known front-end failures, identical diagnostic counts) and, linked locally against the same binding map,
  the same unbound totals (Linux 29,275 on all three hosts, Android 29,276 on both); before the fix mac2 / mac1 failed
  226 TUs more at the retarget stage.
- Do not write outside the workspace or into shared `build/` paths another job also writes; put outputs under a path in
  `--out` instead. The workspace and any leftover process group are removed when the job ends or times out.

## Safety rules

- xemu jobs must carry `-snapshot` as an argument; `drive-backup`, `blockdev-backup`, `blockdev-create`, `drive-mirror` and
  `Application Support/xemu` are refused at submit, at dispatch and on the host. xemu never runs on the laptop.
- Other agents' processes are not yours: `cancel` only your own jobs.

## Defaults

The queue is the default (2026-10-21): `equiv_batch.py` and `promote_dispatch.py` (so `promote-remote.sh` too) submit
through it unless given `--no-jobq`. Inside a queue job (`JOBQ_JOB` set) `equiv_batch.py` runs locally, and
`promote_dispatch.py --no-jobq` (its own ssh dispatcher) passes `--no-jobq` to the remote `equiv_batch.py`.

## Wine replays

`tools/wine_replay_job.py` runs the Wine image's replay as a job on any host:

```sh
J=build/venv/bin/python
id=$($J tools/wine_replay_job.py submit --name ME [--img build/native/link] [--rec build/rp1/play3.hrp] [--timeout 200] [--host mac2] [--env K=V])
$J tools/wine_replay_job.py wait $id                      # then: ckpt.txt (frame hash), trace.txt, result.json in build/jobs/out/ID/wine-out/
$J tools/wine_replay_job.py compare ID1 ID2 ...           # common checkpoint frames must be identical (exit 1 otherwise)
```

- The job ships the image and its DLLs (`hulk-strict.exe`, SDL3, hulkmovie, avutil/avcodec/avformat) and the `.hrp`
  recording as overlay files (content-hashed by jobq); the game data is never shipped: it is the host's own
  `~/hulk-permute/isos/extracted` (`HULK_DATA_DIR`), put there once with
  `rsync -a --exclude default.xbe isos/extracted/ HOST:hulk-permute/isos/extracted/` (2.3 GB; the `default.xbe` is already there).
- Wine on the Macs: a copy of Whisky's `Libraries/Wine` + `WhiskyWineVersion.plist` in `~/wine-whisky` (873 MB, needs
  Rosetta); `rsync -a "$HOME/Library/Application Support/com.isaacmarovitz.Whisky/Libraries/Wine" HOST:wine-whisky/` (read-only
  use of the app's folder). `WINE=...` overrides. No per-host setting is needed. Each host makes one Wine prefix
  (`~/hulk-jobs/wine-template`, first job only, about a minute) and every job runs in a private clone of it.
- Both remote Macs run Python 3.12 and keep LLVM 22.1.8 in `~/llvm` (the clang jobs, `--needs clang`) beside `~/wine-whisky` (jobs
  that run the Wine build, `--needs wine`).
- **Headless works over ssh**: the job sets `HULK_GFX_RENDERER=noop` (bgfx's null renderer), no window session is needed,
  and checkpoint hashes do not depend on it. A graphics run (`--gfx`, Vulkan on MoltenVK) also started and ran over ssh on
  mac2 (which has a console login) but nobody has looked at its pixels there; `HULK_GFX_SHOT` crashed (frame - 210) in
  that image on mac2, so use `wine-gfx` (laptop only) when a picture matters.
- `HULK_SYNCIO=5` (lockstep, the default with a recording) makes runs deterministic: play3 gave identical checkpoint
  hashes on the laptop, mac2 and mac1 (2026-10-21, 120 s runs: 7,440, 8,460 and 2,040 frames; mac1 was loaded at the time).
- The queue daemon re-reads `hosts.json` every 30 s: `caps`, `xemu_max` and `slots` edits apply without a restart.


## Wine builds

`tools/wine_build_job.py` runs a whole Wine build as one queue job: MSVC tree build (`build_tree`), clang probe, Wine
link, and optionally a headless replay on the host. The queue picks the host when the job starts (any remote with the caps
and room; see "Placement" below); `--host H` pins it, `--host local` only on purpose; graphics and screenshot runs stay on
the laptop (`wine-gfx`).

```sh
J=build/venv/bin/python; N=tools/wine_build_job.py
id=$($J $N submit --name ME [--workspace DIR] [--live tools src/platform] --gfx [--replay play3 --frames 1000] [--fetch image])
$J $N wait $id          # summary (decision, wall times, link, replay); files in build/jobs/out/ID/nb-out/
$J $N compare ID1 ID2   # image hashes (PE time stamp zeroed) and replay checkpoints must agree
$J $N sync | lineages   # inputs on the hosts (submit does it) | lineage workspaces and sizes
```

- **Sources.** The job's base tree is `git archive HEAD` of `matches equivalent include src tools config` (cached per host by
  content hash). The overlay is what differs from HEAD: the checkout's dirty files, or with `--workspace DIR` the files of that
  private workspace that differ (files it lacks are deleted). `--live PATH...` takes paths (`tools`, `src/platform`) from the
  checkout instead: a private workspace's copy of the build tools can be older than HEAD's.
- **Lineages.** The host copies the run's sources by content hash into `~/hulk-jobs/nb/ws/LINEAGE` (default `NAME-DIRNAME`) and
  builds there, so build_tree's state, the clang snapshot and the binding map survive between jobs; object caches are per host
  and content-keyed. `--state auto` resumes build_tree only if nothing changed under `include/ config/` or in build_tree's
  imports since the last good build; `--map auto` reuses the binding map only if function sources were modified (none added or
  removed), wine_link's imports are untouched, and (fix1) the tree build left the map key unchanged: `wine_link.py --map-key`
  after the build stage, compared with `build/native/mapkey.json` saved with the map. The key covers what the map binds by
  name: per function its kind, status, symbol, TU and source, the external names its relocations reference (matches: also
  where), `// equiv-map:` lines, and per TU the object's undefined externals. A source that changes a mangled name (a return
  or parameter type, `extern "C"`, a calling convention) is mapped again; a body edit that keeps the names reuses the map
  (`summary.json` `decision.why.map` says which parts changed; a few seconds with warm caches). An equivalent's callees are
  keyed by name only: an edit that sends an unchanged name to another address needs `--map full`. A map made by an older
  wine_link has no key and is made again once. `--state fresh|resume`, `--map full|reuse` force it. A different toolchain
  (clang, lld-link, wibo, cl.exe, python minor version, disc) drops all derived state. Jobs on one lineage run one at a time.
- **Local-only inputs** (`build/functions.csv rtti.json xbsymbols.txt port/platform_calls.json`, `build/data/src`, the prebuilt
  libraries under `build/third_party/out`: pddi-win32/obj, win32/lib, sdl-*, fs1, ffmpeg-win32) are rsynced by `submit` to
  `~/hulk-jobs/nb/inputs-STAMP` (STAMP = content hash; immutable; newest 4 kept). Rebuild the libraries locally and the next
  submit ships them. (fix1) `hulk_fs.lib`, `hulk_sdl.lib` and `hulk_movies.lib` carry `<lib>.srchash`, the content hash of
  the `src/platform/sdl` sources they were built from (`tools/platform_libs.py`; `submit` stamps the ones that are fresh by
  mtime in the checkout). The host's wine_link compares that with the job's sources instead of mtimes (a lineage's copies
  are always newer), so `HULK_WINE_REFRESH_LIBS=0` is no longer needed; a library that really is stale (or unstamped) is
  linked as shipped with a warning (the host has no SDL3 sources to rebuild it), listed in `summary.json` `platform_libs`. The extracted disc, compilers, wibo, the venv, LLVM and Wine are the host's own, as for every job.
- **Timing (play3 workspace, `--gfx`, 8 slots).** Cold on mac2, empty caches: build 56 min, probe 1 min, link 5 min. Same
  sources, warm caches, fresh state: build 17-19 min. One changed function source, state and map reused: 5 min in all
  (build 2 min of verification, probe 25 s, link 1.8 min) plus a 20 s replay to frame 1000. Laptop (2 slots, loaded): 12 min
  for the resumed link-only path, versus 5 min on mac2 and 8 min on mac1.
- **Object cache keys (build1, 2026-11-06).** build_tree's MSVC objects (`tree-cache/obj/`, also read by wine_link and
  data_inventory) and the clang probe's per-TU results are keyed by the TU's text, flags and the headers it can reach
  (`tools/include_keys.py`: the transitive `#include` closure, every candidate a name could resolve to in every includer's
  directory and search directory, `compat/native.h` for clang; a computed `#include` falls back to every header). Before,
  every TU that mentioned `gen/` or `decls/` was keyed on all of `include/` (and `include/compat/` on nothing: fixed in
  eed85215e). On the current tree a one-header edit now recompiles the TUs that see it: `decls/data/game/global.h` 608 of
  2,659 (was 2,517), `gen/hulkfight.h` 283, the mean header 425, median 126; `compat/ptr.h` still reaches 2,599.
  `[time]` lines in `build.log` give each round's generate / compile (cache misses) / verify times. Per round on mac1:
  generate ~120-160 s (single-threaded), verify ~80 s warm (mostly single-threaded; 2,240 s on a cold standalone cache),
  compile ~850 s when `common.h` changed (a new fallback moves hoisted declarations; 1,937 TUs include it), seconds
  otherwise. A fresh warm build stage is ~95% single-threaded time while it holds 8 slots.
- **Seeding a proof from its control (build1, opt-in).** `--state seed:CONTROL` starts the proof's build_tree from the
  control job's final fallback state (`nb-out/tree-state.json`) instead of empty, so it skips the ~18 rounds that rediscover
  the same fallbacks. Measured on mac1 (batch: f9e1c9f1a's 125 renamed sources; control 64299 fresh, proof fresh 64300,
  proof seeded 64969, `--gfx`, play3 to 60000): the seeded proof's `tree-state.json` equals the fresh proof's, the image
  hash is the same (2f60fc01), and the checkpoints agree at all 2,006 common frames (`ckpt_gate.py`: GATE ok, prng 0 of
  2,006 differ). Build stage 3,113 s seeded vs 4,171 s fresh (total 3,866 vs 4,932 s). The saving is smaller than the
  round count suggests: a fresh proof after its control walks the control's states, so its compiles are cache hits (305 cl
  runs) and its time is generate (18 x ~150 s) and verify (15 x ~80 s), both single-threaded; the seed drops 73 fallbacks
  in the batch's 76 objects, which changes `common.h` and recompiles ~1,940 TUs twice (3,896 cl runs). The host (`seed_decision()`) takes the seed only when the control's sources
  (`nb-out/sources.json.gz`, written by every build since build1) differ from the proof's in function sources
  (`matches|equivalent/0xADDR.cpp`, added, modified or removed) and files the tree build does not read (src/, other tools),
  on the same toolchain; anything under `include/` or `config/`, a tool in build_tree's imports or another file in
  `matches/ equivalent/` means a fresh build (`decision.why.state` says which). build_tree (`--seed`, `seed_state()`) then
  drops every fallback in the objects (config/splits.json) of the changed functions, and all header-declaration
  fallbacks, so those are found again as in a fresh build; everything else is verified exactly as in any build (every
  match re-compared, every equivalent against its standalone object, regressions fall back). Rule: seed only from a
  control that ran on the same host (`--host`, as the gate needs anyway) and with the same tools; a control built before
  this change has no `sources.json.gz` and cannot seed (`submit` says so).
- **Faster generate and verify, fewer slots (build2, 2026-11-07).** gen_tree's generate step caches what is the same
  for every TU of a header list (include/gen variants, top-level names, C-linkage notes), parses each function source
  once per build_tree process and keeps tree files whose bytes did not change; its output is byte-identical
  (`tests/gen_tree_identity.py --ref REV --state fresh --state mid:STATE --state STATE ...`: both generators on the
  same sources, every state in one process as build_tree runs them; run it after any gen_tree change). build_tree's
  verification checks TUs in forked processes (`HULK_BUILD_TREE_VERIFY_PROCS=0`: one). After the first compile with
  few cache misses build_tree writes `--slots-low` (default 2; `wine_build_job.py submit --slots-low 0` keeps all) to
  `$JOBQ_RUN_DIR/.jq-slots`, so the daemon lowers the reservation from 8 to 2 for the rest of the build (it can only
  lower it: a later compile round with many misses runs on the host's idle cores by load average, as do the standalone
  builds and the map/probe/link stages). Measured on studio, play3 to 60000, `--gfx`, both fresh (control 65115+65234
  at b4ff21f77, proof 65218 at feb1354fc, same sources): images identical, `tree-state.json` identical, GATE ok (2,004
  common frames, 0 differ). Per stage, control / proof: generate 18 rounds 2,473 / 438 s (112-141 s / 14-39 s a
  round); verify 15 rounds 3,263 / 262 s (warm rounds 57-84 / 13-24 s; the control's first verify built the
  standalone objects cold, 2,414 s); compile 1,543 / 33 s (the control's caches were partly cold, the proof's warm);
  build 7,318 / 743 s; map 187 / 125, probe 52 / 25, link 122 / 121, replay 198 / 192; total about 7,900 / 1,216 s.
  A warm control would have been about 3,400 s of build. The proof held 8 slots for its first 60 s, then 2, then 1
  for the replay: about 2,600 slot-seconds where 8 slots for the whole job would be 8,400.
- **Replay speed (opt1, 2026-11-09; [wine-build.md](wine-build.md#replay-speed-and-optimised-objects-opt1-2026-11-09)).**
  A headless play3 replay to 60000 went from 168 s to 94-106 s on mac2 (357 -> 566-636 fps) with checkpoints identical:
  sqrt as `sqrtsd`, no audio mixing in headless replays (`HULK_AUDIO_NOMIX=1`, wine_replay_job's default), a memo of the
  x87 math, and `--opt hot` (the default: the 32 hottest game TUs at -O1, `tools/wine_opt_tus.txt`). `--opt o0` is the
  reference build (every TU -O0); `--opt all` compiles every game TU at -O1 but `tools/wine_opt_exclude.txt`'s (95 s on
  mac2). A divergence that only an optimised build shows: rebuild with `--opt o0`. The replay is 6-20% of a proof; the tree build is the rest when the lineage cannot resume. `HULK_PROF=1`
  (`--replay-env`) profiles a replay (`nb-out/trace.txt.prof`, `tools/opt_prof.py` with `--fetch image`'s map);
  `--sdl-src DIR` ships a private hulk_sdl.lib build.
- **Build speed: recorded inputs, the verify cache, cache-sync (build3, 2026-11-09; [wine-build.md](wine-build.md#build-speed-build3-2026-11-09)).**
  `--state auto` and `--state seed:CONTROL` decide from what the last build *recorded* loading (`build/tree/inputs.json`,
  copied to `nb-out/tree-inputs.json`: the tools/ modules the build and its verify workers imported, 9 files, and the
  config/ files it reads, `config/splits.json`) instead of build_tree's static import closure (21 files: equiv.py, jobq.py,
  clang_probe.py, data_gen.py, verify_relocs.py and others are imported lazily by features a Wine build never runs); under
  include/ only headers count. Of the 14 fresh builds in jobs 69769-70644, 9 were forced by such inputs (70239: equiv.py
  and verify_relocs.py, 2,269 s instead of about 60 s resumed). A lineage or control built before the record exists falls
  back to the closure; `decision.why.state` says which (`recorded inputs` / `static import closure`). build_tree caches
  each TU's check records in `tree-cache/verify/` (key: the object's content key, the manifest record, the standalone keys
  of its sources, the XBE, functions.csv and the verifier's code; `HULK_BUILD_TREE_VERIFY_CACHE=0` switches it off; the
  records are identical, tests/test_verify_cache.py); the `[time] verify` line counts the hits. `wine_build_job.py
  cache-sync SRC DST` copies the content-addressed entries one host has and another lacks (tree-cache/obj, tree-cache/verify,
  native-cache/equiv; each written under a temporary name and renamed into place; the compilers and disc are checked to be
  the same binaries) so a host that has not built the current sources skips its cold compile rounds. `wine_link.py` prints
  `[time]` phase marks into `map.log`/`link.log`.
- **SSE float (default since perf1, 2026-10-26; [wine-float.md](wine-float.md) section 13).** The game's TUs are built with
  SSE2 scalar float; `--env HULK_WINE_FLOAT=x87` builds the x87 image (checkpoint-identical, about 6x slower under Rosetta).
  An SSE build adds a `map` stage before the probe when the binding map is not reused (`wine_link.py --no-inventory --no-link`,
  about 100 s on mac2) and the probe computes the x87-keep list (an IR scan per TU, cached; about 40 s more on a cold cache);
  the link reuses the map. HEAD on mac2 (6 slots, fresh lineage): build 42 min, map 104 s, probe 64 s, link 2.6 min. play3
  headless to frame 8500: 23 s (x87: 123 s); gameplay 2.2 ms/frame (x87: 13.8), the level load at 420-480 2.5 s (x87: 9.3).
  The summary has `float`, `x87_keep` (the list's length) and `nb-out/x87_keep.txt`.
- **Reproducible.** Images from mac2, mac1 and the laptop are byte-identical except the PE link time stamp, and the play3
  checkpoints agree for every frame to 1020. Three things made them differ and are fixed: `wine_link` sorted objects by cache
  file name, which embeds the compiler's path (now by TU); a cold `build/equiv/crt2.json` raced between workers and the failed
  equivalence checks were cached for good (errors are retried and not cached; the job links the host's `build/equiv` and purges
  cached errors); and `PYTHONHASHSEED=0` for the build.
- **Big jobs.** A queued job of 4+ slots now reserves the hosts it could run on (`BIG_SLOTS` in `jobq.py`), else one-slot jobs
  starve it. This needs the daemon restarted; until then a build waits for an idle remote (or use `--slots 2`).
- **Placement (jq3, 2026-11-04).** `submit` no longer picks a host. Without `--host` the job is unpinned and the daemon
  starts it on whichever build host (remote, `msvc` + `clang`, plus `wine` for a replay) has room. What used to be decided at
  submit is now host-independent or done at dispatch:
  - *inputs*: `submit` asks every build host (one ssh each, in parallel) whether it has the inputs `STAMP` and the lineage's
    state, and syncs the inputs to the ones lacking them. The job also carries a `prep` command (`wine_build_job.py prep
    --host H --stamp S`) that the daemon runs on the laptop before the job starts on H: a host that was down at submit gets
    the inputs then. If this checkout's inputs changed meanwhile (the stamp differs), prep fails and the attempt is retried
    on another host.
  - *lineage state*: the lineage workspace is per host. If a host has the lineage's last good tree build (`.nb/built.json`;
    the newest one if several do), the job gets an **affinity** for it: only that host may take it for `--affinity-wait`
    seconds (default 900), after that any host may (a fresh build there), the affinity host still first when it has room.
    `--affinity-wait 0` drops it; `--state fresh` has none. `--state resume`, `--map reuse` or `--stages` without `build` need that state: they **pin** to
    the host that has it (a lineage nowhere means a fresh build anywhere, as `decide()` already did).
  - *slots*: 8 on a remote unless `--slots` (no longer sized from the submit-time free capacity of one host).
  - `--host H` still pins (and syncs H only).
- **Slots during the replay (jq3).** The replay is one Wine process. Before it starts, `wine_build_run.py` writes `1` to
  `$JOBQ_RUN_DIR/.jq-slots` and releases the lineage lock (the replay runs on its own copy of the image, so the next job of
  the lineage can start). The daemon's 30 s probe (`jobq_run.py probe slots`) reports the file and the job then holds 1
  slot (`status` shows `1 of 8 slots`; DB column `slots_now`); the other 7 go back to the host at once. Slots are only ever
  lowered; any job can do this by writing a smaller number to `$JOBQ_RUN_DIR/.jq-slots`. One job, one id, one result:
  `wait`, `compare` and `nb-out/` are unchanged. (With SSE float the play3 replay to 60000 is about 150 s of a 60+ min build,
  so the gain is small today; it was most of the job with x87.)
- **Generic queue fields (jq3).** `jobq.make_job(..., prep=ARGV, affinity=HOST, affinity_wait=S)`, and `jobq.py submit
  --affinity HOST --affinity-wait S`. `prep` runs on the laptop in the checkout before each attempt with `{host}` replaced;
  a non-zero exit is an infrastructure failure (requeued, `--attempts` applies).

## Adding a host

`tools/jobq_host_setup.sh` brings up a macOS Apple-silicon host for the queue. Run it on the laptop from the repo root; it
works over ssh, checks before it changes anything and can be rerun at any time (`--check` only reports):

```sh
tools/jobq_host_setup.sh --check USER@NEWHOST                 # what is there, what is missing
tools/jobq_host_setup.sh --name NAME [--slots N] USER@NEWHOST  # install what is missing
tools/jobq_host_setup.sh --name NAME --register USER@NEWHOST   # once all is ok: add it to build/jobs/hosts.json
```

What it puts on the host (the same pieces the existing hosts have):

| piece | where | how |
| --- | --- | --- |
| Rosetta 2 | system | checked (`arch -x86_64 /usr/bin/true`); wibo and Wine are x86-64. Installing it needs sudo: the user |
| Python 3.12 venv | `~/hulk-permute/build/venv` | an existing 3.12 (uv's, Homebrew's or python.org's), else uv + `uv python install 3.12` (downloads); `pip install capstone==5.0.9 unicorn==2.1.4 clang==21.1.7` |
| LLVM 22.1.8 | `~/llvm` | copied from a reference queue host (`--ref`, default the first clang host in `hosts.json`; llvm.org's release build, the same bytes on every host), streamed through the laptop |
| MSVC 7.1 + wibo | `~/hulk-permute/build/compilers`, `build/tools/wibo` | rsync from the laptop's `build/` (checked by sha1) |
| Wine | `~/wine-whisky` | rsync of the laptop's Whisky `Libraries/Wine` and `WhiskyWineVersion.plist` (read-only use of the app's folder) |
| sources | `~/hulk-permute/{matches,equivalent,include,src,tools,config,tests}` | `git archive HEAD` (what jobs symlink from the host's checkout) |
| queue runner | `~/hulk-jobs/jobq_run.py` | copied (the daemon reinstalls it on every connect) |
| hosts.json entry | laptop `build/jobs/hosts.json` | `--register`: caps `equiv msvc clang wine` (never `xemu`: it stays on the one xemu host), `slots` = cores unless `--slots`, `path ["~/llvm/bin"]`, `python` = the venv's when the host has no Command Line Tools |

The Wine build's inputs (`~/hulk-jobs/nb/inputs-*`), the Wine prefix template and the base trees arrive through the queue
on first use, as on the other hosts. A running daemon picks the new `hosts.json` entry up within 30 s; jobs start going there
at once (Wine builds are unpinned, so it gets builds as soon as it has room). `tools/jobq.py status` shows it.

What the user does (the script stops or prints the command):

1. On the new Mac: System Settings > General > Sharing > **Remote Login** on; keep it awake on power (Energy settings: prevent
   automatic sleeping; build stages also run under `caffeinate`).
2. On the laptop: `ssh-copy-id USER@NEWHOST` (the queue uses `BatchMode=yes`: key login only). Add a fallback route (LAN
   address) to the entry's `routes` by hand if wanted.
3. Rosetta: `ssh USER@NEWHOST 'sudo softwareupdate --install-rosetta --agree-to-license'`.
4. If the script cannot download Python (permission or network): `ssh USER@NEWHOST 'curl -LsSf https://astral.sh/uv/install.sh | sh &&
   ~/.local/bin/uv python install 3.12'`, then rerun the script. If no reference host has `~/llvm`: `ssh USER@NEWHOST 'mkdir -p
   ~/llvm && curl -L https://github.com/llvm/llvm-project/releases/download/llvmorg-22.1.8/LLVM-22.1.8-macOS-ARM64.tar.xz | tar
   -xJ -C ~/llvm --strip-components 1'`. If the laptop has no Whisky: install Whisky and let it fetch its Wine.
5. **Game data**, the player's own copy, never shipped by the script or the queue:
   `rsync -a isos/extracted/ USER@NEWHOST:hulk-permute/isos/extracted/` (2.3 GB, with `default.xbe`) and
   `rsync -a build/functions.csv build/rtti.json USER@NEWHOST:hulk-permute/build/` (equivalence jobs read them from the
   host's checkout). Then rerun the script: its smoke test byte-matches one function there.
6. `--register`, then `tools/jobq.py status` (the host appears with its slots). A first `tools/wine_build_job.py submit
   --host NAME ...` with a short replay checks the Wine side (the first job on a host makes the Wine prefix, about a minute).

### An xemu host

xemu jobs run in the host's `~/hulk-tr1`: a plain copy (not a git checkout) of the xemu side, with `build/xemu/Xbox-Emulator-Files`
(the user's BIOS, MCPX and base HDD image, read-only), `build/hybrid` (hybrid ISOs, eeprom) and `build/replays` (recordings and
their snapshot disks). Job scripts `cd ~/hulk-tr1` and check `snapshot=True` in its `tools/hybrid_run.py`. A second xemu host
(the Mac Studio, `studio`, 2026-11-06) was brought up from mac2's:

1. `/Applications/xemu.app` copied from mac2 (the same release: VM snapshots only load in the version that saved them).
   xemu is a universal app, so an xemu host needs no Rosetta.
2. `~/hulk-tr1` streamed from mac2 (`tar` over ssh through the laptop, without `build/traces`, `*.out` and sockets); its
   symlinks (`isos`, `build/{venv,tools,compilers,equiv,functions.csv,rtti.json}`) re-pointed at the host's own
   `~/hulk-permute`.
3. A snapshot disk records its base image by absolute path; where the home directory differs, `rebase.py OVERLAY BASE` in
   `~/hulk-tr1` rewrites that header field of the host's copy (only the copy; mac2's files are untouched). Check the base
   image's sha1 against mac2's.
4. `hosts.json`: at first `"caps": ["xemu"], "xemu_max": 1, "any": false` (no MSVC or Wine without Rosetta). Check with a short
   replay pinned to the host: `hybrid_test.py replay build/replays/play3.json --from-snapshot 0 --until-frame 6500` (job 64292
   on studio: identical).

The host needs a console login (xemu opens a window) and must not sleep.

Rosetta on the Mac Studio: macOS 27.2.1 (build 26B125) had no entry in Apple's Rosetta catalog
(`index-rosettaupdateauto-1.sucatalog`, one `RosettaUpdateAuto.pkg` per OS build), so `softwareupdate --install-rosetta`
said "Rosetta 2 update is not available". The neighbouring build's package (26B123; Apple-signed, no OS-build check, three
files under `/Library/Apple`) installed with `sudo installer -pkg RosettaUpdateAuto.pkg -target /` and works: the setup
check passes (MSVC MATCH through wibo, Wine 7.7), and 80 `--x64` verdicts are identical to mac1's (job 64304 vs 64296).
The Studio now has every capability (22 slots). Without Rosetta, note: `equiv --wine` gives false fails (its MSVC-side
compile fails silently) and `--x64` returns "unsupported" for sources whose name it can only learn from the MSVC object.
