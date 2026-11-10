#!/usr/bin/env python3
"""Full native builds as jobs of the shared queue (tools/jobq.py): MSVC tree build, clang probe, native link, then
optionally a headless replay, on mac2/mac1 instead of this laptop (docs/compute.md "Wine builds").

  # submit (prints the job id). Sources: HEAD + this checkout's dirty files, or --workspace DIR (only the files that
  # differ from HEAD travel). The queue picks the host when the job starts (jq3); --host H pins it, --host local builds here.
  build/venv/bin/python tools/wine_build_job.py submit --name ME [--workspace DIR] [--gfx]
        [--replay play3 --frames 1000] [--fetch image] [--host mac2|mac1|local] [--lineage L]
        [--state auto|fresh|resume|seed:CONTROL] [--map auto|full|reuse] [--slots N] [--slots-low N] [--env K=V ...] [--stages build,probe,link]
  build/venv/bin/python tools/wine_build_job.py wait ID     # then: summary, build/jobs/out/ID/nb-out/
  build/venv/bin/python tools/wine_build_job.py compare ID|DIR ...   # image hashes and replay checkpoints must agree
  build/venv/bin/python tools/wine_build_job.py sync [--host H ...]  # put the local-only inputs on the hosts (submit does it)
  build/venv/bin/python tools/wine_build_job.py lineages [--host H]  # the hosts' lineage workspaces and their sizes

Placement (jq3): without --host the job is not pinned. submit asks the build hosts which have the lineage's state and the
inputs, ships the inputs to those lacking them, and the daemon takes the first build host with room; it runs `prep`
(the inputs again, for a host that missed them) before the job starts there. A lineage with state on a host makes that
host the only candidate for --affinity-wait seconds (default 900), then the preferred one; --state resume / --map reuse pin
to it. The replay stage runs on 1 slot: wine_build_run.py tells the queue (RUNDIR/.jq-slots) and drops the lineage lock.

Where things live (tools/wine_build_run.py is the host side):
  * the job's base tree is `git archive HEAD` of matches equivalent include src tools config (jobq caches it per host,
    keyed by the content hash of those trees); the overlay is what differs from HEAD (--workspace) or is dirty (checkout);
    files missing from the workspace are deleted on the host. The host copies the run's sources by content hash into its
    lineage workspace ~/hulk-jobs/nb/ws/LINEAGE, so build_tree --resume, the clang probe snapshot and wine_link
    --reuse-map keep working between jobs of one lineage (default lineage NAME-WORKSPACEDIR);
  * local-only inputs (build/functions.csv, rtti.json, xbsymbols.txt, port/platform_calls.json, the data TUs
    build/data/src, the prebuilt third-party libraries under build/third_party/out) are rsynced to
    ~/hulk-jobs/nb/inputs-STAMP on each host (STAMP = content hash; immutable; the 4 most recently used kept, and every
    stamp a queued or running job names or a running job holds a lease on: PRUNE_PY). The extracted disc, the
    compilers, wibo, the venv and Wine are the host's own, as for every other job (docs/compute.md);
  * outputs: nb-out/{summary.json, build/probe/link logs, link-report.json, unbound.txt, image.sha256, ckpt.txt,
    trace.txt, result.json}; the image and its DLLs only with --fetch image (nb-out/image/).
"""
import argparse
import hashlib
import json
import os
import re
import shlex
import subprocess
import sys
import tempfile
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import jobq  # noqa: E402
from wine_build_run import INPUT_DIRS, INPUT_FILES, SRC_DIRS, NB, TP as TP_OUT  # noqa: E402

SKIP = ("__pycache__", ".git")
HASHCACHE = os.path.join(jobq.JOBS, "nb-hashcache.json")
RECS = {"play3": "build/rp1/play3.hrp"}


# --opt (opt1, docs/wine-build.md "Replay speed"): which game TUs clang_probe compiles optimised. o0 is the reference
# build (every TU -O0); hot compiles the TUs tools/wine_opt_tus.txt names at -O1 (the replay's hottest, each gated
# against o0 on play3). An explicit --env HULK_WINE_OPT... wins.
OPT_ENV = {"o0": {}, "hot": {"HULK_WINE_OPT": "O1", "HULK_WINE_OPT_ONLY": "tools/wine_opt_tus.txt"}}


def local_dir(d):
    """Where an input directory comes from on this machine: `--data-src DIR` (HULK_NB_DATA_SRC) replaces the shared
    build/data/src with a private set of data TUs (a data_gen change under test), shipped under the same name."""
    if d == "build/data/src" and os.environ.get("HULK_NB_DATA_SRC"):
        return os.path.abspath(os.environ["HULK_NB_DATA_SRC"])
    # (opt1) `--sdl-src DIR`: a private build of the audio/input backends (tools/wine_sdl.py backends --target win32
    # with HULK_TP_OUT=<private out>; DIR is its sdl-backends/win32), shipped as the shared one's name
    if d == TP_OUT + "sdl-backends/win32" and os.environ.get("HULK_NB_SDL_SRC"):
        return os.path.abspath(os.environ["HULK_NB_SDL_SRC"])
    return os.path.join(ROOT, d)


def walk(root, dirs):
    for d in dirs:
        base = local_dir(d) if root == ROOT else os.path.join(root, d)
        for dp, dns, fns in os.walk(base):
            dns[:] = sorted(x for x in dns if x not in SKIP)
            for fn in sorted(fns):
                if fn != ".DS_Store" and not fn.endswith((".pyc", ".orig", ".rej")):
                    p = os.path.join(dp, fn)
                    if os.path.exists(p):
                        yield os.path.join(d, os.path.relpath(p, base)), p


# ---------------------------------------------------------------------------------------------- sources
def head_blobs():
    out = subprocess.run(["git", "ls-tree", "-r", "HEAD", "--"] + SRC_DIRS, cwd=ROOT, capture_output=True, text=True, check=True).stdout
    return {l.split("\t", 1)[1]: l.split()[2] for l in out.splitlines()}


def overlay(ws, live=()):
    """(files {dest: abs path}, deletions): what differs between the workspace's SRC_DIRS and HEAD's. LIVE: path
    prefixes (e.g. tools src/platform) taken from this checkout instead of the workspace (a private workspace's copy of
    the build tools is often older than HEAD's, which matters when they changed how they find LLVM, say)."""
    head = head_blobs()
    live = [x.strip("/") for x in live]

    def is_live(rel):
        return any(rel == x or rel.startswith(x + "/") for x in live)
    paths = [(rel, p) for rel, p in walk(ws, SRC_DIRS) if not is_live(rel)]
    if live:
        paths += [(rel, p) for rel, p in walk(ROOT, SRC_DIRS) if is_live(rel)]
    r = subprocess.run(["git", "hash-object", "--stdin-paths"], cwd=ROOT, input="\n".join(p for _, p in paths) + "\n",
                       capture_output=True, text=True, check=True)
    shas = r.stdout.split()
    if len(shas) != len(paths):
        sys.exit("git hash-object returned %d hashes for %d files" % (len(shas), len(paths)))
    files, seen = {}, set()
    for (rel, p), sha in zip(paths, shas):
        seen.add(rel)
        if head.get(rel) != sha:
            files[rel] = p
    dirs_present = {d for d in SRC_DIRS if os.path.isdir(os.path.join(ws, d))}
    dele = sorted(rel for rel in head if rel.split("/")[0] in dirs_present and rel not in seen)
    return files, dele


# ---------------------------------------------------------------------------------------------- inputs
def hashes(root, relpaths):
    """sha1 per file, cached by (mtime, size)."""
    try:
        cache = json.load(open(HASHCACHE))
    except (OSError, ValueError):
        cache = {}
    out, dirty = {}, False
    for rel, p in relpaths:
        st = os.stat(p)
        key = [st.st_mtime_ns, st.st_size]
        c = cache.get(p)
        if c and c[:2] == key:
            out[rel] = c[2]
            continue
        h = hashlib.sha1(open(p, "rb").read()).hexdigest()
        cache[p] = key + [h]
        out[rel] = h
        dirty = True
    if dirty:
        tmp = HASHCACHE + ".%d" % os.getpid()
        json.dump(cache, open(tmp, "w"))
        os.replace(tmp, HASHCACHE)
    return out


def inputs_stamp():
    # fix1: the platform libraries carry the content hash of the sources they were built from (tools/platform_libs.py),
    # so the host can tell whether they fit the job's src/platform/sdl; stamp the ones this checkout built
    try:
        import platform_libs
        if platform_libs.can_build(ROOT):
            platform_libs.stamp_fresh(os.path.join(ROOT, TP_OUT))
    except (ImportError, OSError) as e:
        print("platform library stamps: %s" % e, file=sys.stderr)
    rels = [(f, os.path.join(ROOT, f)) for f in INPUT_FILES if os.path.exists(os.path.join(ROOT, f))]
    rels += list(walk(ROOT, INPUT_DIRS))
    h = hashes(ROOT, rels)
    return hashlib.sha1(json.dumps(sorted(h.items())).encode()).hexdigest()[:16]


def host_cfg(name):
    for h in jobq.load_hosts():
        if h["name"] == name:
            return h
    sys.exit("unknown host " + name)


def ssh_parts(cfg):
    """(ssh options list, user@host) of the first route that answers."""
    for r in cfg["routes"]:
        p = subprocess.run(jobq.SSH + r + ["true"], capture_output=True)
        if p.returncode == 0:
            return r[:-1], r[-1]
    sys.exit("cannot reach " + cfg["name"])


def sync_host(name, stamp, quiet=False):
    """Make ~/hulk-jobs/nb/inputs-STAMP complete on the host (a clone of the newest earlier one, then rsync)."""
    cfg = host_cfg(name)
    if cfg.get("local"):
        return
    opts, dest = ssh_parts(cfg)
    ssh = jobq.SSH + opts
    lock = open(os.path.join(jobq.JOBS, "nb-sync-%s.lock" % name), "w")
    import fcntl
    fcntl.flock(lock, fcntl.LOCK_EX)
    r = subprocess.run(ssh + [dest, "test -f ~/hulk-jobs/nb/inputs-%s/.complete" % stamp], capture_output=True)
    if r.returncode == 0:
        return
    t0 = time.time()
    tmp = "~/hulk-jobs/nb/inputs-%s.tmp" % stamp
    script = ("set -e; mkdir -p ~/hulk-jobs/nb; cd ~/hulk-jobs/nb; rm -rf inputs-%s.tmp; "
              "prev=$(ls -dt inputs-*/ 2>/dev/null | head -1); "
              "if [ -n \"$prev\" ]; then cp -Rcp \"$prev\" inputs-%s.tmp 2>/dev/null || cp -Rp \"$prev\" inputs-%s.tmp; "
              "rm -f inputs-%s.tmp/.complete; else mkdir inputs-%s.tmp; fi") % ((stamp,) * 5)
    subprocess.run(ssh + [dest, "sh -c " + shlex.quote(script)], check=True)
    e = " ".join(shlex.quote(x) for x in ssh)
    for f in INPUT_FILES:
        if os.path.exists(os.path.join(ROOT, f)):
            d = os.path.dirname(f)
            subprocess.run(ssh + [dest, "mkdir -p %s/%s" % (tmp, d)], check=True)
            subprocess.run(["rsync", "-a", "-e", e, os.path.join(ROOT, f), "%s:%s/%s" % (dest, tmp, f)], check=True,
                           capture_output=quiet)
    for d in INPUT_DIRS:
        if os.path.isdir(local_dir(d)):
            subprocess.run(ssh + [dest, "mkdir -p %s/%s" % (tmp, d)], check=True)
            subprocess.run(["rsync", "-a", "--delete", "-e", e, local_dir(d) + "/", "%s:%s/%s/" % (dest, tmp, d)],
                           check=True, capture_output=quiet)
    fin = ("cd ~/hulk-jobs/nb && touch inputs-%s.tmp/.complete && rm -rf inputs-%s && mv inputs-%s.tmp inputs-%s") % ((stamp,) * 4)
    subprocess.run(ssh + [dest, "sh -c " + shlex.quote(fin)], check=True)
    prune_host(ssh, dest, cfg, {stamp} | live_stamps())
    print("synced inputs %s to %s in %.0f s" % (stamp, name, time.time() - t0), file=sys.stderr if quiet else sys.stdout)


KEEP_INPUTS = 4
LEASE_MAX_S = 26 * 3600
# Run on a host (python3 -c PRUNE_PY NB KEEP LEASE_MAX STAMP...): remove inputs-* beyond the KEEP most recently used
# (directory mtime: sync makes it, wine_build_run touches it when a job starts), but never one named by a STAMP argument
# (the queued and running jobs' stamps, from the queue) or one holding a lease younger than LEASE_MAX seconds
# (inputs-S/.lease-JOB, written by wine_build_run while the job runs). Prints what it removed.
PRUNE_PY = r"""
import os, shutil, sys, time
nb, keep, lease_max, protected = sys.argv[1], int(sys.argv[2]), float(sys.argv[3]), set(sys.argv[4:])
now = time.time()
ds = []
for n in os.listdir(nb):
    p = os.path.join(nb, n)
    if n.startswith("inputs-") and not n.endswith(".tmp") and os.path.isdir(p):
        ds.append((os.path.getmtime(p), n))
ds.sort(reverse=True)
for _, n in ds[keep:]:
    p = os.path.join(nb, n)
    if n[len("inputs-"):] in protected:
        continue
    try:
        if any(f.startswith(".lease-") and now - os.path.getmtime(os.path.join(p, f)) < lease_max for f in os.listdir(p)):
            continue
    except OSError:
        continue
    shutil.rmtree(p, ignore_errors=True)
    print("pruned " + n)
"""


def live_stamps():
    """The inputs stamps of the queue's queued and running Wine builds (their `prep` command names it)."""
    out = set()
    try:
        c = jobq.conn()
        for r in c.execute("SELECT prep FROM jobs WHERE state IN ('queued', 'running') AND prep IS NOT NULL"):
            argv = json.loads(r["prep"])
            if "--stamp" in argv:
                out.add(argv[argv.index("--stamp") + 1])
    except Exception as e:  # noqa: BLE001  (no queue state: protect nothing more than the caller's stamp)
        print("live_stamps: %s" % e, file=sys.stderr)
    return out


def prune_host(ssh, dest, cfg, protected):
    py = cfg.get("python", "python3")
    cmd = "%s -c %s ~/hulk-jobs/nb %d %d %s" % (py, shlex.quote(PRUNE_PY), KEEP_INPUTS, LEASE_MAX_S,
                                               " ".join(shlex.quote(x) for x in sorted(protected)))
    r = subprocess.run(ssh + [dest, cmd], capture_output=True, text=True)
    if r.returncode != 0:
        print("prune on %s failed: %s" % (dest, r.stderr.strip()[-200:]), file=sys.stderr)


def cmd_sync(a):
    stamp = inputs_stamp()
    for h in a.host or [h["name"] for h in jobq.load_hosts() if not h.get("local")]:
        sync_host(h, stamp)
    print(stamp)
    return 0


def cmd_prep(a):
    """Run by the queue daemon when it dispatches a build to a host (jobq `prep`): make the job's inputs STAMP complete
    there. The inputs are rebuilt from this checkout, so they must still hash to STAMP (exit 2 otherwise: another host
    that has them can still take the job)."""
    if a.data_src:
        os.environ["HULK_NB_DATA_SRC"] = a.data_src
    if a.sdl_src:
        os.environ["HULK_NB_SDL_SRC"] = a.sdl_src
    cfg = host_cfg(a.host)
    if cfg.get("local"):
        return 0
    opts, dest = ssh_parts(cfg)
    if subprocess.run(jobq.SSH + opts + [dest, "test -f ~/hulk-jobs/nb/inputs-%s/.complete" % a.stamp], capture_output=True).returncode == 0:
        return 0
    now = inputs_stamp()
    if now != a.stamp:
        print("inputs %s are not on %s and this checkout's are now %s" % (a.stamp, a.host, now), file=sys.stderr)
        return 2
    sync_host(a.host, a.stamp, quiet=True)
    return 0


# ---------------------------------------------------------------------------------------------- submit
def build_hosts(replay):
    """Remote hosts that can run a Wine build (the laptop only with --host local)."""
    return [h["name"] for h in jobq.load_hosts() if not h.get("local") and {"msvc", "clang"} <= set(h.get("caps", []))
            and (not replay or "wine" in h.get("caps", []))]


def survey(hosts, lineage, stamp):
    """{host: {"lineage": mtime of the lineage's last good tree build or None, "inputs": bool}} for the hosts that answer
    (one ssh each, in parallel)."""
    import threading
    out = {}
    py = ("import os,sys\nb=os.path.expanduser('~/hulk-jobs/nb')\np=os.path.join(b,'ws',sys.argv[1],'.nb/built.json')\n"
          "print(os.path.getmtime(p) if os.path.exists(p) else '-', os.path.exists(os.path.join(b,'inputs-'+sys.argv[2],'.complete')))")

    def one(h):
        cfg = host_cfg(h)
        for r in cfg["routes"]:
            try:
                p = subprocess.run(jobq.SSH + r + ["%s -c %s %s %s" % (cfg.get("python", "python3"), shlex.quote(py), shlex.quote(lineage), stamp)],
                                   capture_output=True, text=True, timeout=90)
            except subprocess.TimeoutExpired:
                continue
            if p.returncode == 0 and len(p.stdout.split()) == 2:
                m, i = p.stdout.split()
                out[h] = {"lineage": None if m == "-" else float(m), "inputs": i == "True"}
                return
    ts = [threading.Thread(target=one, args=(h,)) for h in hosts]
    for t in ts:
        t.start()
    for t in ts:
        t.join()
    return out


def placement(a, lineage, stamp):
    """(pin, affinity, hosts to sync now, note). --host pins. Otherwise the daemon picks the host at dispatch: a
    lineage with derived state on a host gives that host an affinity (only it may take the job for --affinity-wait
    seconds), or a pin when the state is required (--state resume / --map reuse, or --stages without build)."""
    if a.host:
        return a.host, None, [a.host], "pinned (--host)"
    hosts = build_hosts(a.replay)
    if not hosts:
        sys.exit("no remote host can run Wine builds; use --host local")
    sv = survey(hosts, lineage, stamp)
    have = sorted((v["lineage"], h) for h, v in sv.items() if v["lineage"])
    sync = [h for h in hosts if not sv.get(h, {}).get("inputs")]
    later = bool(getattr(a, "stages", None)) and "build" not in a.stages.split(",")     # probe/link/replay of an earlier build
    if have and (a.state == "resume" or a.map == "reuse" or later):
        return have[-1][1], None, [have[-1][1]], "pinned: %s needs lineage %s, which is on %s" % (
            "--stages without build" if later else "--state resume/--map reuse", lineage, have[-1][1])
    if have and a.state != "fresh" and a.affinity_wait != 0:
        return None, have[-1][1], sync, "dispatch-time host; lineage state on %s (affinity %ds)" % (have[-1][1], a.affinity_wait)
    return None, None, sync, "dispatch-time host" + ("; lineage %s is new" % lineage if not have else "")


def state_arg(v):
    if v in ("auto", "fresh", "resume") or re.fullmatch(r"seed:\d+", v):
        return v
    raise argparse.ArgumentTypeError("auto, fresh, resume or seed:JOB")


def seed_files(job):
    """--state seed:JOB: the control's final build_tree state and source list (nb-out/tree-state.json,
    sources.json.gz) and what wine_build_run.seed_decision checks (toolchain)."""
    d = out_dir(job)
    summ = jobq_json(os.path.join(d, "summary.json"))
    if not summ or summ.get("stages", {}).get("build") != 0:
        sys.exit("seed: job %s has no successful build stage (%s)" % (job, d))
    files = {"nbrun/seed-state.json": os.path.join(d, "tree-state.json"), "nbrun/seed-sources.json.gz": os.path.join(d, "sources.json.gz")}
    for p in files.values():
        if not os.path.exists(p):
            sys.exit("seed: %s is missing (a control built before seeding support cannot seed: rebuild it)" % p)
    return files, {"job": str(job), "host": summ.get("host"), "toolchain": summ.get("toolchain")}


def jobq_json(p):
    try:
        with open(p) as f:
            return json.load(f)
    except (OSError, ValueError):
        return None


def cmd_submit(a):
    seed = None
    if a.state.startswith("seed:"):
        seed = seed_files(a.state[5:])
        if not a.host or a.host != seed[1]["host"]:
            print("note: control %s ran on %s; pin the proof there (--host %s) so the gate compares like with like" % (
                seed[1]["job"], seed[1]["host"], seed[1]["host"]), file=sys.stderr)
    if a.data_src:
        os.environ["HULK_NB_DATA_SRC"] = a.data_src
    if a.sdl_src:
        os.environ["HULK_NB_SDL_SRC"] = a.sdl_src
    ws = os.path.abspath(a.workspace or ROOT)
    for d in ("tools", "matches", "include"):
        if not os.path.isdir(os.path.join(ws, d)):
            sys.exit("%s is not a workspace (no %s/)" % (ws, d))
    stages = a.stages.split(",") if a.stages else ["build", "probe", "link"] + (["replay"] if a.replay else [])
    files, dele = overlay(ws, a.live or [])
    lineage = re.sub(r"[^A-Za-z0-9_.-]", "_", a.lineage or "%s-%s" % (a.name, os.path.basename(ws) if a.workspace else "head"))
    stamp = inputs_stamp()
    host, affinity, to_sync, note = placement(a, lineage, stamp)
    feats = jobq.daemon_features()
    if affinity and feats is not None and "affinity" not in feats:
        # a daemon from before jq3 ignores affinities: pin as submit used to (until it is restarted)
        host, affinity, to_sync, note = affinity, None, [affinity], "pinned to %s (the running daemon predates affinities)" % affinity
    local = bool(host and host_cfg(host).get("local"))
    # inputs: put them on every candidate now (in parallel; a host that fails here gets them at dispatch, jobq `prep`)
    import threading
    errs = {}

    def sync1(h):
        try:
            sync_host(h, stamp, quiet=True)
        except (SystemExit, subprocess.CalledProcessError) as e:
            errs[h] = str(e)
    ts = [threading.Thread(target=sync1, args=(h,)) for h in to_sync if not host_cfg(h).get("local")]
    for t in ts:
        t.start()
    for t in ts:
        t.join()
    for h, e in errs.items():
        print("sync to %s failed (%s): the queue retries it when the job goes there" % (h, e[-120:]), file=sys.stderr)
    if local:
        try:
            cap = {h["name"]: h for h in json.load(open(jobq.HOSTS_STATE))["hosts"]}.get(host, {}).get("cap", 2)
        except (OSError, ValueError):
            cap = 2
        slots = max(1, min(a.slots or 2, cap))
    else:
        slots = a.slots or 8
    spec = {"lineage": lineage, "stages": stages, "gfx": bool(a.gfx), "state": "seed" if seed else a.state, "map": a.map, "jobs": slots,
            "inputs_stamp": stamp, "deletions": dele, "env": dict(OPT_ENV[a.opt], **dict(e.split("=", 1) for e in a.env or [])),
            "fetch": a.fetch or [], "slots_low": a.slots_low}
    ov = {"nbrun/wine_build_run.py": os.path.join(ROOT, "tools/wine_build_run.py"),
          "nbrun/wine_replay_job.py": os.path.join(ROOT, "tools/wine_replay_job.py")}
    if seed:
        ov.update(seed[0])
        spec["seed"] = seed[1]
    if a.replay:
        rec = os.path.join(ROOT, RECS.get(a.replay, a.replay))
        if not os.path.exists(rec):
            sys.exit("no recording " + rec)
        ov["nbrun/rec.hrp"] = rec
        spec["replay"] = {"frames": a.frames, "timeout": a.replay_timeout, "env": dict(e.split("=", 1) for e in a.replay_env or [])}
    with tempfile.NamedTemporaryFile("w", suffix=".json", delete=False) as tf:
        json.dump(spec, tf)
    ov["nbrun/spec.json"] = tf.name
    ov.update(files)
    store = {dest: [jobq.store_file(p), os.stat(p).st_mode & 0o777] for dest, p in ov.items()}
    os.unlink(tf.name)
    prep = None if local else (["python", "tools/wine_build_job.py", "prep", "--host", "{host}", "--stamp", stamp] +
                               (["--data-src", os.path.abspath(a.data_src)] if a.data_src else []) +
                               (["--sdl-src", os.path.abspath(a.sdl_src)] if a.sdl_src else []))
    job = jobq.make_job(a.name, ["python", "nbrun/wine_build_run.py"], "msvc" if not a.replay else "wine", store, ["nb-out"],
                        a.limit, slots, a.attempts, a.prio, jobq.head_commit(), SRC_DIRS, host, prep=prep,
                        affinity=affinity, affinity_wait=max(0, a.affinity_wait))
    jid = jobq.submit_jobs([job])[0]
    print(jid)
    print("%s, lineage %s, %d overlay files, %d deletions, %d slots, inputs %s" % (
        "host " + host if host else note, lineage, len(files), len(dele), slots, stamp), file=sys.stderr)
    return 0


def out_dir(x):
    if os.path.isdir(x):
        return x
    return os.path.join(jobq.OUT, str(x), "nb-out")


def cmd_wait(a):
    r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/jobq.py"), "wait", a.id])
    s = os.path.join(out_dir(a.id), "summary.json")
    if os.path.exists(s):
        d = json.load(open(s))
        print(json.dumps({k: d.get(k) for k in ("host", "lineage", "sync", "sources_hash", "decision", "wall", "stages", "link",
                                                "platform_libs", "replay", "error", "exit") if k in d}, indent=1))
        print("image: " + " ".join("%s=%s" % (k, v[:12]) for k, v in sorted((d.get("image") or {}).items())))
    else:
        print("no summary.json (see build/jobs/out/%s/log)" % a.id)
    return r.returncode


def load_ckpt(d):
    p = os.path.join(d, "ckpt.txt")
    return dict((int(l.split()[0]), l.split()[1]) for l in open(p)) if os.path.exists(p) else {}


def cmd_compare(a):
    bad = 0
    runs = [(x, out_dir(x)) for x in a.items]
    imgs = []
    for x, d in runs:
        p = os.path.join(d, "image.sha256")
        imgs.append(open(p).read() if os.path.exists(p) else None)
        print("%s: image hashes %s" % (x, "present" if imgs[-1] else "missing"))
    if all(imgs):
        same = len(set(imgs)) == 1
        print("images %s" % ("IDENTICAL" if same else "DIFFER"))
        if not same:
            bad = 1
            for n in set(l.split()[1] for i in imgs for l in i.splitlines()):
                vals = [dict((l.split()[1], l.split()[0]) for l in i.splitlines()).get(n, "-")[:12] for i in imgs]
                if len(set(vals)) > 1:
                    print("  %s: %s" % (n, " ".join(vals)))
    cks = [load_ckpt(d) for _, d in runs]
    if all(cks):
        common = sorted(set.intersection(*[set(c) for c in cks]))
        diff = [f for f in common if len({c[f] for c in cks}) > 1]
        print("checkpoints: %s; common frames %d (0..%d), differing %d%s" % (
            ", ".join("%d (last %d)" % (len(c), max(c)) for c in cks), len(common), common[-1] if common else -1, len(diff),
            " first at %d" % diff[0] if diff else ""))
        bad |= bool(diff) or not common
    return 1 if bad else 0


def cmd_lineages(a):
    for h in a.host or [x["name"] for x in jobq.load_hosts() if not x.get("local")]:
        cfg = host_cfg(h)
        cmd = "cd ~/hulk-jobs/nb 2>/dev/null && du -sk ws/* inputs-*/ cache 2>/dev/null"
        if cfg.get("local"):
            r = subprocess.run(["sh", "-c", cmd.replace("~", os.path.expanduser("~"))], capture_output=True, text=True)
        else:
            opts, dest = ssh_parts(cfg)
            r = subprocess.run(jobq.SSH + opts + [dest, cmd], capture_output=True, text=True)
        print("== " + h)
        for l in r.stdout.splitlines():
            k, p = l.split("\t")
            print("%8.1f MB  %s" % (int(k) / 1024, p))
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="c", required=True)
    s = sp.add_parser("submit")
    s.add_argument("--name", required=True)
    s.add_argument("--workspace", help="a private workspace (default: this checkout); only files differing from HEAD travel")
    s.add_argument("--host", help="pin to this host (a hosts.json name, or local); default: the queue picks a host when the job starts")
    s.add_argument("--affinity-wait", type=int, default=900,
                   help="seconds only the host with this lineage's state may take the job (0: any host at once)")
    s.add_argument("--live", nargs="*", metavar="PATH", help="paths (tools, src/platform...) taken from this checkout, not the workspace")
    s.add_argument("--lineage")
    s.add_argument("--gfx", action="store_true", help="link with the pddi/bgfx backend (wine_link.py --gfx)")
    s.add_argument("--stages", help="comma list of build,probe,link,replay (default: all requested)")
    s.add_argument("--data-src", help="a private build/data/src (data TUs of a data_gen change under test)")
    s.add_argument("--opt", choices=sorted(OPT_ENV), default="o0",
                   help="optimised game objects: o0 (the reference, default) or hot (tools/wine_opt_tus.txt at -O1)")
    s.add_argument("--sdl-src", help="a private build/third_party/out/sdl-backends/win32 (hulk_sdl.lib of an audio/input "
                   "change under test: HULK_TP_OUT=OUT tools/wine_sdl.py backends --target win32)")
    s.add_argument("--state", default="auto", type=state_arg, metavar="auto|fresh|resume|seed:JOB",
                   help="build_tree --resume policy; seed:JOB starts from control JOB's final state (docs/compute.md)")
    s.add_argument("--map", choices=["auto", "full", "reuse"], default="auto", help="wine_link --reuse-map policy")
    s.add_argument("--replay", help="play3 or a .hrp path: headless replay of the built image on the host")
    s.add_argument("--frames", type=int, help="stop the replay once a checkpoint at this frame is written")
    s.add_argument("--replay-timeout", type=int, default=300)
    s.add_argument("--replay-env", action="append", help="K=V for the replay only")
    s.add_argument("--env", action="append", help="K=V for the build and link (e.g. HULK_WINE_SANITIZE=float-cast)")
    s.add_argument("--fetch", nargs="*", choices=["image"], help="also bring the image and DLLs back")
    s.add_argument("--slots", type=int, help="cores for the build stages (default 8 on a remote, 2 local); the replay gives all but one back")
    s.add_argument("--slots-low", type=int, default=2, metavar="N",
                   help="the reservation once build_tree's compile runs warm (generate/verify are single-threaded; 0: keep --slots)")
    s.add_argument("--limit", type=int, default=7200, help="wall-clock seconds per attempt")
    s.add_argument("--attempts", type=int, default=2)
    s.add_argument("--prio", type=int, default=0)
    s = sp.add_parser("wait")
    s.add_argument("id")
    s = sp.add_parser("compare")
    s.add_argument("items", nargs="+")
    s = sp.add_parser("sync")
    s.add_argument("--host", action="append")
    s = sp.add_parser("lineages")
    s.add_argument("--host", action="append")
    s = sp.add_parser("prep", help="(queue daemon) make the inputs STAMP complete on HOST")
    s.add_argument("--host", required=True)
    s.add_argument("--stamp", required=True)
    s.add_argument("--data-src")
    s.add_argument("--sdl-src")
    a = ap.parse_args()
    return {"submit": cmd_submit, "wait": cmd_wait, "compare": cmd_compare, "sync": cmd_sync,
            "lineages": cmd_lineages, "prep": cmd_prep}[a.c](a) or 0


if __name__ == "__main__":
    sys.exit(main())
