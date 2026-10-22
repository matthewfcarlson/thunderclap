#!/usr/bin/env python3
"""Full native builds as jobs of the shared queue (tools/jobq.py): MSVC tree build, clang probe, native link, then
optionally a headless replay, on mac2/mac1 instead of this laptop (docs/compute.md "Native builds").

  # submit (prints the job id). Sources: HEAD + this checkout's dirty files, or --workspace DIR (only the files that
  # differ from HEAD travel). Default host: whichever of mac2/mac1 has more free capacity; --host local builds here.
  build/venv/bin/python tools/native_build_job.py submit --name ME [--workspace DIR] [--gfx]
        [--replay play3 --frames 1000] [--fetch image] [--host mac2|mac1|local] [--lineage L]
        [--state auto|fresh|resume] [--map auto|full|reuse] [--slots N] [--env K=V ...] [--stages build,probe,link]
  build/venv/bin/python tools/native_build_job.py wait ID     # then: summary, build/jobs/out/ID/nb-out/
  build/venv/bin/python tools/native_build_job.py compare ID|DIR ...   # image hashes and replay checkpoints must agree
  build/venv/bin/python tools/native_build_job.py sync [--host H ...]  # put the local-only inputs on the hosts (submit does it)
  build/venv/bin/python tools/native_build_job.py lineages [--host H]  # the hosts' lineage workspaces and their sizes

Where things live (tools/native_build_run.py is the host side):
  * the job's base tree is `git archive HEAD` of matches equivalent include src tools config (jobq caches it per host,
    keyed by the content hash of those trees); the overlay is what differs from HEAD (--workspace) or is dirty (checkout);
    files missing from the workspace are deleted on the host. The host copies the run's sources by content hash into its
    lineage workspace ~/hulk-jobs/nb/ws/LINEAGE, so build_tree --resume, the clang probe snapshot and native_link
    --reuse-map keep working between jobs of one lineage (default lineage NAME-WORKSPACEDIR);
  * local-only inputs (build/functions.csv, rtti.json, xbsymbols.txt, port/platform_calls.json, the data TUs
    build/data/src, the prebuilt third-party libraries under build/third_party/out) are rsynced to
    ~/hulk-jobs/nb/inputs-STAMP on each host (STAMP = content hash; immutable, newest 4 kept). The extracted disc, the
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
from native_build_run import INPUT_DIRS, INPUT_FILES, SRC_DIRS, NB  # noqa: E402

SKIP = ("__pycache__", ".git")
HASHCACHE = os.path.join(jobq.JOBS, "nb-hashcache.json")
RECS = {"play3": "build/rp1/play3.hrp"}


def walk(root, dirs):
    for d in dirs:
        for dp, dns, fns in os.walk(os.path.join(root, d)):
            dns[:] = sorted(x for x in dns if x not in SKIP)
            for fn in sorted(fns):
                if fn != ".DS_Store" and not fn.endswith((".pyc", ".orig", ".rej")):
                    p = os.path.join(dp, fn)
                    if os.path.exists(p):
                        yield os.path.relpath(p, root), p


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
        if os.path.isdir(os.path.join(ROOT, d)):
            subprocess.run(ssh + [dest, "mkdir -p %s/%s" % (tmp, d)], check=True)
            subprocess.run(["rsync", "-a", "--delete", "-e", e, os.path.join(ROOT, d) + "/", "%s:%s/%s/" % (dest, tmp, d)],
                           check=True, capture_output=quiet)
    fin = ("cd ~/hulk-jobs/nb && touch inputs-%s.tmp/.complete && rm -rf inputs-%s && mv inputs-%s.tmp inputs-%s && "
           "ls -dt inputs-*/ | tail -n +5 | xargs rm -rf") % ((stamp,) * 4)
    subprocess.run(ssh + [dest, "sh -c " + shlex.quote(fin)], check=True)
    print("synced inputs %s to %s in %.0f s" % (stamp, name, time.time() - t0))


def cmd_sync(a):
    stamp = inputs_stamp()
    for h in a.host or [h["name"] for h in jobq.load_hosts() if not h.get("local")]:
        sync_host(h, stamp)
    print(stamp)
    return 0


# ---------------------------------------------------------------------------------------------- submit
def pick_host(a):
    if a.host:
        return a.host
    try:
        st = {h["name"]: h for h in json.load(open(jobq.HOSTS_STATE))["hosts"]}
    except (OSError, ValueError):
        st = {}
    best = None
    for h in jobq.load_hosts():
        if h.get("local") or not {"msvc", "clang"} <= set(h.get("caps", [])) or (a.replay and "wine" not in h.get("caps", [])):
            continue
        s = st.get(h["name"], {})
        free = s.get("cap", 8) - s.get("used", 0)
        k = (-free, h.get("pref", 0), h["name"] != "mac2")
        if best is None or k < best[0]:
            best = (k, h["name"])
    if not best:
        sys.exit("no remote host can run native builds; use --host local")
    return best[1]


def cmd_submit(a):
    host = pick_host(a)
    cfg = host_cfg(host)
    ws = os.path.abspath(a.workspace or ROOT)
    for d in ("tools", "matches", "include"):
        if not os.path.isdir(os.path.join(ws, d)):
            sys.exit("%s is not a workspace (no %s/)" % (ws, d))
    stages = a.stages.split(",") if a.stages else ["build", "probe", "link"] + (["replay"] if a.replay else [])
    files, dele = overlay(ws, a.live or [])
    lineage = re.sub(r"[^A-Za-z0-9_.-]", "_", a.lineage or "%s-%s" % (a.name, os.path.basename(ws) if a.workspace else "head"))
    stamp = inputs_stamp()
    if not cfg.get("local"):
        sync_host(host, stamp, quiet=True)
    try:
        cap = {h["name"]: h for h in json.load(open(jobq.HOSTS_STATE))["hosts"]}.get(host, {}).get("cap", 8)
    except (OSError, ValueError):
        cap = 8
    slots = a.slots or (min(cap, 8) if not cfg.get("local") else 2)
    slots = max(1, min(slots, cap) if cfg.get("local") else slots)
    spec = {"lineage": lineage, "stages": stages, "gfx": bool(a.gfx), "state": a.state, "map": a.map, "jobs": slots,
            "inputs_stamp": stamp, "deletions": dele, "env": dict(e.split("=", 1) for e in a.env or []),
            "fetch": a.fetch or []}
    ov = {"nbrun/native_build_run.py": os.path.join(ROOT, "tools/native_build_run.py"),
          "nbrun/native_replay_job.py": os.path.join(ROOT, "tools/native_replay_job.py")}
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
    job = jobq.make_job(a.name, ["python", "nbrun/native_build_run.py"], "msvc" if not a.replay else "wine", store, ["nb-out"],
                        a.limit, slots, a.attempts, a.prio, jobq.head_commit(), SRC_DIRS, host)
    jid = jobq.submit_jobs([job])[0]
    print(jid)
    print("host %s, lineage %s, %d overlay files, %d deletions, %d slots, inputs %s" % (host, lineage, len(files), len(dele), slots, stamp),
          file=sys.stderr)
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
                                                "replay", "error", "exit") if k in d}, indent=1))
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
    s.add_argument("--host", help="mac2, mac1 or local (default: the remote with more free capacity)")
    s.add_argument("--live", nargs="*", metavar="PATH", help="paths (tools, src/platform...) taken from this checkout, not the workspace")
    s.add_argument("--lineage")
    s.add_argument("--gfx", action="store_true", help="link with the pddi/bgfx backend (native_link.py --gfx)")
    s.add_argument("--stages", help="comma list of build,probe,link,replay (default: all requested)")
    s.add_argument("--state", choices=["auto", "fresh", "resume"], default="auto", help="build_tree --resume policy")
    s.add_argument("--map", choices=["auto", "full", "reuse"], default="auto", help="native_link --reuse-map policy")
    s.add_argument("--replay", help="play3 or a .hrp path: headless replay of the built image on the host")
    s.add_argument("--frames", type=int, help="stop the replay once a checkpoint at this frame is written")
    s.add_argument("--replay-timeout", type=int, default=300)
    s.add_argument("--replay-env", action="append", help="K=V for the replay only")
    s.add_argument("--env", action="append", help="K=V for the build and link (e.g. HULK_NATIVE_SANITIZE=float-cast)")
    s.add_argument("--fetch", nargs="*", choices=["image"], help="also bring the image and DLLs back")
    s.add_argument("--slots", type=int, help="cores (default 8 on a remote, capped by its free capacity)")
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
    a = ap.parse_args()
    return {"submit": cmd_submit, "wait": cmd_wait, "compare": cmd_compare, "sync": cmd_sync,
            "lineages": cmd_lineages}[a.c](a) or 0


if __name__ == "__main__":
    sys.exit(main())
