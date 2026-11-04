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
| `xemu` | mac2 only, one at a time, never the laptop |

Hosts and capabilities: `build/jobs/hosts.json` (untracked: it holds user and host names; created from
`build/agent-tools/hosts.json` on first use; fields `slots`, `caps`, `pref` (lower is preferred), `path`, `xemu_max`,
`python` (the host's interpreter for the runner, default `python3`; a host without the Command Line Tools names its venv's)).
A host added to `hosts.json` joins the running daemon within 30 s (no restart); see "Adding a host" below.

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
    `--affinity-wait 0` drops it; `--state fresh` has none. `--state resume` or `--map reuse` need that state: they **pin** to
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
