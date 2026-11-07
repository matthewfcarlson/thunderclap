#!/usr/bin/env python3
"""tools/gen_tree.py output identity: the tree a changed generator writes must equal, byte for byte, the tree the
reference generator (a git revision's tools/) writes, for several fallback states.

  build/venv/bin/python tests/gen_tree_identity.py --ref REV --state fresh --state mid:STATE.json --state STATE.json
  build/venv/bin/python tests/gen_tree_identity.py --ref REV --new-tools DIR ...   # a private copy of tools/ instead

Both generators run on the same sources (this checkout's matches/ equivalent/ include/ config/ src/, or
--src-root), each in its own scratch root (--work, default build/gen-identity/) whose build/tree they write. Each
side generates every state in turn in ONE process, as tools/build_tree.py does across its rounds, so a cache that
goes stale between generate() calls shows up as a difference in a later state (a state may be given twice, e.g.
`fresh` first and last: the second tree replaces a bigger one, so files of the earlier tree must go). A state is `fresh` (no fallbacks),
a build_tree state.json (e.g. a Wine build's nb-out/tree-state.json), or `mid:FILE` (FILE thinned out: every other
wrap / isolate / iso_plain entry, plus a few header-declaration fallbacks: a state between rounds). After each
state the whole build/tree (sources, headers, manifest.json, conflicts.json) is hashed; the test passes when every
state's file set and every file's bytes agree. `--ref-cache FILE` keeps the reference hashes for reuse (keyed by
the ref revision, the states and a digest of the sources) while the new side is being worked on.
"""
import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SRC_LINKS = ("matches", "equivalent", "include", "config", "src")
BUILD_LINKS = ("functions.csv", "rtti.json")

DRIVER = r'''
import copy, hashlib, json, os, sys, time
sys.path.insert(0, os.path.join(os.getcwd(), "tools"))
import gen_tree
states = json.load(open(sys.argv[1]))
out = {}
for name, raw in states:
    st = {"wrap": {int(k, 16): v for k, v in raw.get("wrap", {}).items()},
          "isolate": {int(k, 16): v for k, v in raw.get("isolate", {}).items()},
          "local_only": {tuple(k) for k in raw.get("local_only", [])},
          "iso_plain": {int(k, 16): v for k, v in raw.get("iso_plain", {}).items()}}
    t = time.time()
    gen_tree.generate(st)
    dt = time.time() - t
    files = {}
    for dp, dns, fns in os.walk(gen_tree.TREE):
        for fn in fns:
            p = os.path.join(dp, fn)
            rel = os.path.relpath(p, gen_tree.TREE)
            if rel == "state.json":
                continue
            with open(p, "rb") as f:
                files[rel] = hashlib.sha1(f.read()).hexdigest()
    out[name] = {"files": files, "seconds": round(dt, 1)}
    print("%s: %d files, generate %.1f s" % (name, len(files), dt), file=sys.stderr, flush=True)
json.dump(out, open(sys.argv[2], "w"))
'''


def load_state(spec):
    if spec == "fresh":
        return "fresh", {}
    mid = spec.startswith("mid:")
    path = spec[4:] if mid else spec
    s = json.load(open(path))
    name = ("mid:" if mid else "") + os.path.basename(os.path.dirname(os.path.dirname(path)) or path) + \
        "/" + os.path.basename(path)
    if not mid:
        return name, s
    out = {}
    for k in ("wrap", "isolate", "iso_plain"):
        keys = sorted(s.get(k, {}))
        out[k] = {x: s[k][x] for x in keys[::2]}
    out["local_only"] = s.get("local_only", [])[::2]
    return name, out


def add_local_only(states, tree_manifest):
    """Header-declaration fallbacks (blame()'s local_only keys) taken from a generated manifest's header spans."""
    try:
        man = json.load(open(tree_manifest))
    except (OSError, ValueError):
        return
    keys = [span[2] for h in sorted(man.get("headers", {})) for span in man["headers"][h]]
    pick = keys[::max(1, len(keys) // 40)][:40]
    for name, s in states:
        if name.startswith("mid:"):
            s["local_only"] = sorted({tuple(k) for k in s.get("local_only", [])} | {tuple(k) for k in pick})


def make_root(root, tools_src, src_root, ref=None):
    if os.path.isdir(root):
        shutil.rmtree(root)
    os.makedirs(os.path.join(root, "build"))
    for d in SRC_LINKS:
        os.symlink(os.path.join(src_root, d), os.path.join(root, d))
    for f in BUILD_LINKS:
        os.symlink(os.path.join(ROOT, "build", f), os.path.join(root, "build", f))
    if ref:
        p = subprocess.run("git archive %s tools | tar -x -C %s" % (ref, root), shell=True, cwd=ROOT)
        if p.returncode:
            sys.exit("git archive %s failed" % ref)
    else:
        os.symlink(tools_src, os.path.join(root, "tools"))


def run_side(root, states, label):
    sf, of = os.path.join(root, "states.json"), os.path.join(root, "hashes.json")
    json.dump(states, open(sf, "w"))
    with open(os.path.join(root, "driver.py"), "w") as f:
        f.write(DRIVER)
    print("[%s] generating %d states in %s" % (label, len(states), root), flush=True)
    env = dict(os.environ, PYTHONHASHSEED="0")
    p = subprocess.run([sys.executable, "driver.py", sf, of], cwd=root, env=env)
    if p.returncode:
        sys.exit("[%s] generator failed (exit %d)" % (label, p.returncode))
    return json.load(open(of))


def sources_digest(src_root):
    h = hashlib.sha1()
    for d in SRC_LINKS:
        for dp, dns, fns in sorted(os.walk(os.path.join(src_root, d), followlinks=True)):
            dns.sort()
            for fn in sorted(fns):
                p = os.path.join(dp, fn)
                st = os.stat(p)
                h.update(("%s %d %d\n" % (os.path.relpath(p, src_root), st.st_size, st.st_mtime_ns)).encode())
    return h.hexdigest()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--ref", required=True, help="git revision of the reference tools/")
    ap.add_argument("--new-tools", default=os.path.join(ROOT, "tools"), help="the changed tools/ (default: this checkout's)")
    ap.add_argument("--src-root", default=ROOT, help="where matches/ equivalent/ include/ config/ src/ come from")
    ap.add_argument("--state", action="append", default=[], help="fresh | STATE.json | mid:STATE.json (repeatable)")
    ap.add_argument("--work", default=os.path.join(ROOT, "build/gen-identity"))
    ap.add_argument("--ref-cache", help="JSON file: reuse / store the reference side's hashes")
    a = ap.parse_args()
    specs = a.state or ["fresh"]
    states, seen = [], {}
    for spec in specs:
        name, st = load_state(spec)
        seen[name] = seen.get(name, 0) + 1
        states.append((name if seen[name] == 1 else "%s#%d" % (name, seen[name]), st))
    src_root = os.path.abspath(a.src_root)
    ref_rev = subprocess.run(["git", "rev-parse", a.ref], cwd=ROOT, capture_output=True, text=True).stdout.strip()
    if not ref_rev:
        sys.exit("unknown revision %s" % a.ref)
    a.work = os.path.abspath(a.work)
    ref_root, new_root = os.path.join(a.work, "ref"), os.path.join(a.work, "new")
    # the header-declaration fallbacks of the mid states come from a fresh tree of the reference generator
    if any(n.startswith("mid:") for n, _ in states):
        man = os.path.join(a.work, "local-only-manifest.json")
        if not os.path.exists(man):
            make_root(ref_root, None, src_root, ref=ref_rev)
            run_side(ref_root, [("fresh", {})], "ref, for local_only keys")
            shutil.copyfile(os.path.join(ref_root, "build/tree/manifest.json"), man)
        add_local_only(states, man)
    key = hashlib.sha1(json.dumps([ref_rev, states, sources_digest(src_root)], sort_keys=True).encode()).hexdigest()
    ref = None
    if a.ref_cache and os.path.exists(a.ref_cache):
        c = json.load(open(a.ref_cache))
        if c.get("key") == key:
            ref = c["hashes"]
            print("[ref] from %s" % a.ref_cache)
    if ref is None:
        make_root(ref_root, None, src_root, ref=ref_rev)
        ref = run_side(ref_root, states, "ref " + ref_rev[:9])
        if a.ref_cache:
            json.dump({"key": key, "hashes": ref}, open(a.ref_cache, "w"))
    make_root(new_root, os.path.abspath(a.new_tools), src_root)
    new = run_side(new_root, states, "new")
    bad = 0
    for name, _ in states:
        r, n = ref[name]["files"], new[name]["files"]
        only_r, only_n = sorted(set(r) - set(n)), sorted(set(n) - set(r))
        diff = sorted(p for p in set(r) & set(n) if r[p] != n[p])
        ok = not (only_r or only_n or diff)
        bad += not ok
        print("%-40s %s  %d files  generate %.1f s -> %.1f s%s" % (
            name, "identical" if ok else "DIFFERS", len(r), ref[name]["seconds"], new[name]["seconds"],
            "" if ok else "  (%d differ, %d only in ref, %d only in new: %s)" % (
                len(diff), len(only_r), len(only_n), (diff + only_r + only_n)[:5])))
    print("IDENTITY %s" % ("ok" if not bad else "FAILED (%d of %d states)" % (bad, len(states))))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
