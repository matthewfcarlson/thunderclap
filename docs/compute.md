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

- Options: `--needs any|equiv|msvc|clang|wine|xemu`, `--files PATH|SRC=DEST ...`, `--dirty`, `--out PATH ...` (paths relative
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
| `wine` | laptop only (Whisky's Wine; `wine64` in argv0 is expanded to it) |
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
