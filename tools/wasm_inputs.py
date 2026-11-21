#!/usr/bin/env python3
"""The wasm port's inputs at one commit (docs/wasm-port.md "Inputs"): the clang_probe snapshot of the materialized tree and
the Wine build's binding map of the same tree, in one directory that HULK_WASM_SNAP / HULK_WASM_BINDINGS point at.

  # as a queue job on HEAD (the queue's workspace is `git archive HEAD`; MSVC verification of every TU, ~11 min on 8 slots)
  build/venv/bin/python tools/wasm_inputs.py submit --name ME [--slots 8]          # prints the job id
  build/venv/bin/python tools/wasm_inputs.py fetch ID [--dest DIR]                  # unpack; prints the exports
  # or here, from a `git archive REV` workspace (slow on 2 local jobs)
  build/venv/bin/python tools/wasm_inputs.py local --rev REV [--dest DIR] [--jobs 2]
  # the step both run inside a workspace whose tools/ this is
  build/venv/bin/python tools/wasm_inputs.py job --commit SHA [--jobs N]

The default DEST is build/wasm-inputs/<commit, 12 digits>/ with snap/ (manifest.json, report.json, src/, include/,
repo-include/), bindings.json and meta.json. Then

  export HULK_WASM_SNAP=DEST/snap HULK_WASM_BINDINGS=DEST/bindings.json
  build/venv/bin/python tools/wasm_port.py compile && ... link && ... aot

The steps are the Wine build's (tools/wine_build_run.py): `tree_tu.py materialize`, `wine_link.py --no-inventory
--no-link` (the binding map alone, from the verification objects), then clang_probe's snapshot layout of the
materialized tree (no clang compile: wasm_port.py compiles the snapshot itself). The job writes only under the
workspace's wasm-in/ (a queue job's build/ is the host checkout's); the content-keyed caches (build/tree-cache,
build/equiv) are the usual shared ones. Everything it makes is game-derived build state: it stays under build/.
"""
import argparse
import json
import os
import shutil
import subprocess
import sys
import tarfile
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PY = sys.executable
# the local-only inputs the checks and the binding map read (a queue host has its own in its checkout's build/)
INPUT_FILES = ["build/functions.csv", "build/rtti.json"]
WORK = "wasm-in"                 # (in the workspace, not under its build/)
TARBALL = "wasm-in.tgz"


def run(argv, cwd, env=None, log=None):
    t = time.time()
    print("+ %s" % " ".join(argv), flush=True)
    r = subprocess.run(argv, cwd=cwd, env=env, stdin=subprocess.DEVNULL)
    print("  rc %d, %.0f s" % (r.returncode, time.time() - t), flush=True)
    return r.returncode


def cmd_job(a):
    """Inside a workspace (cwd = ROOT): materialize, map, snapshot -> WORK/out and TARBALL. Everything is written under
    WORK (a queue job's build/ is the host checkout's, shared with other jobs); only the content-keyed caches
    (build/tree-cache, build/equiv) are the usual shared ones."""
    os.chdir(ROOT)
    work = os.path.join(ROOT, WORK)
    shutil.rmtree(work, ignore_errors=True)
    tree, nat, out = (os.path.join(work, d) for d in ("tree", "native", "out"))
    env = dict(os.environ, PYTHONHASHSEED="0")
    meta = {"commit": a.commit, "steps": {}}
    rc = run([PY, "tools/tree_tu.py", "materialize", "--out", tree, "--jobs", str(a.jobs)], ROOT, env)
    meta["steps"]["materialize"] = rc
    if not os.path.exists(os.path.join(tree, "manifest.json")):
        sys.exit("materialize wrote no manifest (rc %d)" % rc)
    env_map = dict(env, HULK_WINE_DIR=nat, HULK_WINE_CACHE=os.path.join(nat, "cache"), HULK_TREE_DIR=tree,
                   HULK_WINE_REFRESH_LIBS="0")
    rc = run([PY, "tools/wine_link.py", "--jobs", str(a.jobs), "--no-inventory", "--no-link"], ROOT, env_map)
    meta["steps"]["map"] = rc
    if rc or not os.path.exists(os.path.join(nat, "bindings.json")):
        sys.exit("wine_link made no binding map (rc %d)" % rc)
    # clang_probe.snapshot()'s layout (without the data TUs: the wasm build compiles none)
    snap = os.path.join(out, "snap")
    os.makedirs(snap)
    for sub in ("src", "include"):
        shutil.copytree(os.path.join(tree, sub), os.path.join(snap, sub))
    for fn in ("manifest.json", "report.json", "state.json"):
        shutil.copy2(os.path.join(tree, fn), os.path.join(snap, fn))
    shutil.copytree(os.path.join(ROOT, "include"), os.path.join(snap, "repo-include"))
    shutil.copyfile(os.path.join(nat, "bindings.json"), os.path.join(out, "bindings.json"))
    gen = json.load(open(os.path.join(tree, "report.json")))
    meta["tree"] = {k: gen["generator"].get(k) for k in ("tu_files", "verified_functions", "modes")}
    meta["materialize_counts"] = (gen.get("summary") or {}).get("counts")
    with open(os.path.join(out, "meta.json"), "w") as f:
        json.dump(meta, f, indent=1)
    with tarfile.open(os.path.join(ROOT, TARBALL), "w:gz") as t:
        t.add(out, arcname="wasm-inputs")
    print("wrote %s (%s)" % (TARBALL, json.dumps(meta["steps"])))


def default_dest(commit):
    return os.path.join(ROOT, "build/wasm-inputs", commit[:12])


def exports(dest):
    print("export HULK_WASM_SNAP=%s HULK_WASM_BINDINGS=%s" % (os.path.join(dest, "snap"), os.path.join(dest, "bindings.json")))


def unpack(tgz, dest):
    tmp = dest + ".tmp"
    shutil.rmtree(tmp, ignore_errors=True)
    os.makedirs(tmp)
    with tarfile.open(tgz) as t:
        t.extractall(tmp, filter="data")
    if os.path.exists(dest):
        shutil.rmtree(dest)
    os.replace(os.path.join(tmp, "wasm-inputs"), dest)
    shutil.rmtree(tmp)


def cmd_submit(a):
    head = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
    files = ["tools/wasm_inputs.py"]
    cmd = [PY, os.path.join(ROOT, "tools/jobq.py"), "submit", "--name", a.name, "--needs", "wine", "--slots", str(a.slots),
           "--limit", str(a.limit), "--files"] + files + ["--out", TARBALL, "--",
           "build/venv/bin/python", "tools/wasm_inputs.py", "job", "--commit", head, "--jobs", str(a.slots)]
    print("job at HEAD %s" % head[:12], file=sys.stderr)
    return subprocess.call(cmd, cwd=ROOT)


def cmd_fetch(a):
    tgz = os.path.join(ROOT, "build/jobs/out", a.id, TARBALL)
    if not os.path.exists(tgz):
        sys.exit("no %s (job not done? tools/jobq.py result %s)" % (tgz, a.id))
    with tarfile.open(tgz) as t:
        meta = json.load(t.extractfile("wasm-inputs/meta.json"))
    dest = os.path.abspath(a.dest or default_dest(meta["commit"]))
    unpack(tgz, dest)
    print(json.dumps(meta))
    exports(dest)


def cmd_local(a):
    rev = subprocess.check_output(["git", "rev-parse", a.rev], cwd=ROOT, text=True).strip()
    dest = os.path.abspath(a.dest or default_dest(rev))
    ws = dest + ".ws"
    shutil.rmtree(ws, ignore_errors=True)
    os.makedirs(os.path.join(ws, "build"))
    for d in ("tree-cache",):
        os.makedirs(os.path.join(ROOT, "build", d), exist_ok=True)
        os.symlink(os.path.join(ROOT, "build", d), os.path.join(ws, "build", d))
    arch = subprocess.Popen(["git", "archive", rev, "include", "src", "tools", "config", "tests"], cwd=ROOT,
                            stdout=subprocess.PIPE)
    subprocess.check_call(["tar", "xf", "-"], cwd=ws, stdin=arch.stdout)
    arch.wait()
    for f in INPUT_FILES:
        os.makedirs(os.path.dirname(os.path.join(ws, f)), exist_ok=True)
        shutil.copyfile(os.path.join(ROOT, f), os.path.join(ws, f))
    # the shared local toolchain (as wine_build_run's lineage links it)
    for n in ("venv", "compilers", "tools", "equiv"):
        if os.path.exists(os.path.join(ROOT, "build", n)):
            os.symlink(os.path.join(ROOT, "build", n), os.path.join(ws, "build", n))
    os.symlink(os.path.join(ROOT, "isos"), os.path.join(ws, "isos"))
    rc = run([os.path.join(ws, "build/venv/bin/python"), "tools/wasm_inputs.py", "job", "--commit", rev,
              "--jobs", str(a.jobs)], ws)
    if rc:
        sys.exit("job failed (workspace kept: %s)" % ws)
    unpack(os.path.join(ws, TARBALL), dest)
    shutil.rmtree(ws)
    exports(dest)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    p = sp.add_parser("job")
    p.add_argument("--commit", required=True)
    p.add_argument("--jobs", type=int, default=4)
    p = sp.add_parser("submit")
    p.add_argument("--name", required=True)
    p.add_argument("--slots", type=int, default=8)
    p.add_argument("--limit", type=int, default=5400)
    p = sp.add_parser("fetch")
    p.add_argument("id")
    p.add_argument("--dest")
    p = sp.add_parser("local")
    p.add_argument("--rev", default="HEAD")
    p.add_argument("--dest")
    p.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args()
    return {"job": cmd_job, "submit": cmd_submit, "fetch": cmd_fetch, "local": cmd_local}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
