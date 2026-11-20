#!/usr/bin/env python3
"""Fast-forward the shared checkout's local main to origin/main without touching anyone's uncommitted edits.

  build/venv/bin/python tools/sync_main.py            # fetch, then fast-forward if safe
  build/venv/bin/python tools/sync_main.py --check    # report only (exit 1 when main lags origin)

Lanes push with `git push origin <sha>:refs/heads/main` from a side ref, so the shared checkout's local main falls
behind origin, and queue jobs (based on the local HEAD) then run old tools and TUs (11-19: equiv.py without the D153
guard). `git merge --ff-only` refuses whenever the working copy holds other lanes' edits to files upstream touched.

For every path that changed between HEAD and origin/main this tool:
  - leaves the file alone when its working copy already equals origin's (a lane committed it from the shared copy);
  - writes origin's version when the working copy equals HEAD's (no local edit);
  - merges three-way (git merge-file: HEAD as base) when the working copy holds local edits, keeping them unstaged;
    a merge conflict aborts the whole sync before anything is written.
Then it moves refs/heads/main with a compare-and-swap and points the index entries of those paths at origin's blobs.
A backup of every file it rewrites goes to build/lead/discarded/sync-<time>/.
"""
import argparse
import os
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def git(*args, inp=None, check=True):
    p = subprocess.run(["git", *args], cwd=ROOT, input=inp, capture_output=True)
    if check and p.returncode != 0:
        raise SystemExit("git %s: %s" % (" ".join(args), p.stderr.decode(errors="replace").strip()))
    return p


def out(*args):
    return git(*args).stdout.decode().strip()


def blob(rev, path):
    p = git("rev-parse", "-q", "--verify", "%s:%s" % (rev, path), check=False)
    return p.stdout.decode().strip() if p.returncode == 0 else None


def work_hash(path):
    full = os.path.join(ROOT, path)
    if not os.path.isfile(full):
        return None
    return out("hash-object", "--", path)


def plan(old, new):
    """[(path, action, data)]: action in keep / write / merge / delete; raises SystemExit on a conflict."""
    steps = []
    for line in out("diff", "--name-status", "--no-renames", old, new).splitlines():
        st, path = line.split("\t", 1)
        w, o, h = work_hash(path), blob(new, path), blob(old, path)
        if w == o:
            steps.append((path, "keep", None))
        elif w == h:
            steps.append((path, "delete" if o is None else "write", None))
        elif o is None:
            raise SystemExit("%s: deleted upstream but has local edits; resolve by hand" % path)
        else:
            base = git("show", "%s:%s" % (old, path)).stdout if h else b""
            theirs = git("show", "%s:%s" % (new, path)).stdout
            mine = open(os.path.join(ROOT, path), "rb").read()
            tmp = os.path.join(ROOT, "build", "lead", ".sync-%d" % os.getpid())
            os.makedirs(tmp, exist_ok=True)
            fs = []
            for n, data in (("mine", mine), ("base", base), ("theirs", theirs)):
                fp = os.path.join(tmp, n)
                open(fp, "wb").write(data)
                fs.append(fp)
            m = subprocess.run(["git", "merge-file", "-p"] + fs, capture_output=True)
            for fp in fs:
                os.unlink(fp)
            os.rmdir(tmp)
            if m.returncode != 0:
                raise SystemExit("%s: local edits conflict with upstream; nothing was changed" % path)
            steps.append((path, "merge", m.stdout))
    return steps


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true", help="report only")
    ap.add_argument("--no-fetch", action="store_true")
    a = ap.parse_args()
    if not a.no_fetch:
        git("fetch", "-q", "origin")
    if out("symbolic-ref", "--short", "HEAD") != "main":
        raise SystemExit("the checkout is not on main")
    old, new = out("rev-parse", "HEAD"), out("rev-parse", "origin/main")
    if old == new:
        print("main is at origin/main (%s)" % new[:9])
        return 0
    if git("merge-base", "--is-ancestor", old, new, check=False).returncode != 0:
        raise SystemExit("local main %s is not an ancestor of origin/main %s: not a fast-forward" % (old[:9], new[:9]))
    behind = out("rev-list", "--count", "%s..%s" % (old, new))
    steps = plan(old, new)
    if a.check:
        print("main is %s commits behind origin/main; %d paths (%d with local edits to merge)"
              % (behind, len(steps), sum(1 for s in steps if s[1] == "merge")))
        return 1
    bk = os.path.join(ROOT, "build", "lead", "discarded", "sync-%s" % time.strftime("%Y%m%d-%H%M%S"))
    for path, action, data in steps:
        full = os.path.join(ROOT, path)
        if action in ("write", "merge", "delete") and os.path.isfile(full):
            os.makedirs(os.path.dirname(os.path.join(bk, path)), exist_ok=True)
            open(os.path.join(bk, path), "wb").write(open(full, "rb").read())
        if action == "write":
            os.makedirs(os.path.dirname(full), exist_ok=True)
            open(full, "wb").write(git("show", "%s:%s" % (new, path)).stdout)
        elif action == "merge":
            open(full, "wb").write(data)
        elif action == "delete" and os.path.isfile(full):
            os.unlink(full)
    git("update-ref", "refs/heads/main", new, old)          # compare-and-swap: fails if someone moved main meanwhile
    for path, action, _ in steps:
        o = blob(new, path)
        if o is None:
            git("update-index", "--force-remove", "--", path)
        else:
            mode = out("ls-tree", new, "--", path).split()[0]
            git("update-index", "--add", "--cacheinfo", "%s,%s,%s" % (mode, o, path))
    merged = [p for p, act, _ in steps if act == "merge"]
    print("main %s -> %s (%s commits, %d paths; local edits kept in %s)"
          % (old[:9], new[:9], behind, len(steps), ", ".join(merged) or "none"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
