# Compute: the shared job queue

Heavy work does not run on the laptop. `tools/jobq.py` is a shared queue with a scheduler daemon that spreads jobs over
this laptop, mac2 and mac1 by free capacity (it reads each host's load and sizes the slots from it). Everything that
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
LIST lines are `0xADDR path/to/source.cpp`. Sources travel with their job, so uncommitted candidates work. `OUT.jsonl`
is appended as results arrive and addresses already in it are skipped (rerun to resume).

## What runs where

| `--needs` | hosts |
| --- | --- |
| `equiv`, `msvc`, `clang`, `any` | mac2, mac1 first; the laptop only when they are full (it has few slots) |
| `wine` | all three (headless Wine replays; `wine64` in argv0 is expanded to the host's Whisky Wine: the app's copy on the laptop, `~/wine-whisky` on the Macs) |
| `wine-gfx` | laptop only (a Wine run that draws through MoltenVK; see Wine replays) |
| `xemu` | mac2 only, one at a time, never the laptop |

Hosts and capabilities: `build/jobs/hosts.json` (untracked: it holds user and host names; created from
`build/agent-tools/hosts.json` on first use; fields `slots`, `caps`, `pref` (lower is preferred), `path`, `xemu_max`).

## Workspaces

A job runs in a fresh clone (APFS clonefile) of a per-host cached base tree, `git archive HEAD tools include tests config`
(keyed by the content hash of those trees, kept under `~/hulk-jobs/ws`, newest 4 kept), plus the job's overlay files.
`build/ isos/ matches/ equivalent/ src/ farm/ docs/` are symlinks to the host's own checkout (`~/hulk-permute` on the
Macs), so the jobs share its compilers, venv and caches. Consequences:

- Committed `tools/` and `include/` are what runs. For uncommitted files pass `--files` (or `--dirty`: every modified or
  untracked file under `tools include tests config`; `jobq_equiv.py` and `regress.py --jobq` do this by default).
- `matches/` and `equivalent/` on the Macs are whatever was last synced there, not your working tree.
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
link, and optionally a headless replay on the host. Builds default to mac2/mac1 (the one with more free slots); `--host local`
only on purpose; graphics and screenshot runs stay on the laptop (`wine-gfx`).

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
  removed) and wine_link's imports are untouched. `--state fresh|resume`, `--map full|reuse` force it. A different toolchain
  (clang, lld-link, wibo, cl.exe, python minor version, disc) drops all derived state. Jobs on one lineage run one at a time.
- **Local-only inputs** (`build/functions.csv rtti.json xbsymbols.txt port/platform_calls.json`, `build/data/src`, the prebuilt
  libraries under `build/third_party/out`: pddi-win32/obj, win32/lib, sdl-*, fs1, ffmpeg-win32) are rsynced by `submit` to
  `~/hulk-jobs/nb/inputs-STAMP` (STAMP = content hash; immutable; newest 4 kept). Rebuild the libraries locally and the next
  submit ships them. The extracted disc, compilers, wibo, the venv, LLVM and Wine are the host's own, as for every job.
- **Timing (play3 workspace, `--gfx`, 8 slots).** Cold on mac2, empty caches: build 56 min, probe 1 min, link 5 min. Same
  sources, warm caches, fresh state: build 17-19 min. One changed function source, state and map reused: 5 min in all
  (build 2 min of verification, probe 25 s, link 1.8 min) plus a 20 s replay to frame 1000. Laptop (2 slots, loaded): 12 min
  for the resumed link-only path, versus 5 min on mac2 and 8 min on mac1.
- **Reproducible.** Images from mac2, mac1 and the laptop are byte-identical except the PE link time stamp, and the play3
  checkpoints agree for every frame to 1020. Three things made them differ and are fixed: `wine_link` sorted objects by cache
  file name, which embeds the compiler's path (now by TU); a cold `build/equiv/crt2.json` raced between workers and the failed
  equivalence checks were cached for good (errors are retried and not cached; the job links the host's `build/equiv` and purges
  cached errors); and `PYTHONHASHSEED=0` for the build.
- **Big jobs.** A queued job of 4+ slots now reserves the hosts it could run on (`BIG_SLOTS` in `jobq.py`), else one-slot jobs
  starve it. This needs the daemon restarted; until then a build waits for an idle remote (or use `--slots 2`).
