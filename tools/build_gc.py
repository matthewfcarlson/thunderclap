#!/usr/bin/env python3
"""Trim finished lanes' folders out of build/.

  build_gc.py                      # dry run: what stays (and why) and what goes
  build_gc.py --yes                # archive and delete
  build_gc.py --keep wmenu1,foo    # also keep these (live lanes)

An entry of build/ (folder or file) stays when any of these holds:
  - it is infrastructure (INFRA below: toolchains, caches, the queue, inputs, deliverables);
  - a live file names it as build/<name>: CLAUDE.md, tools/, tests/, config/, src/, .gitignore,
    build/lead/rules.md or the lead's Claude memory folder (docs/ and the journal are history and don't count);
  - something inside changed in the last --days days (default 3);
  - a running process names it on its command line;
  - it is in --keep.
Everything else is a finished lane's scratch. Its notes (*.md, *.txt, *.log, scripts and small
json/py/sh/c/cpp files under 1 MB, no game data) go into build/attic/<name>.tar.gz, then the entry
is deleted. build/attic/index.txt records each entry's size and date. Nothing outside build/ is touched.
"""
import argparse, os, re, shutil, subprocess, sys, tarfile, time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BUILD = os.path.join(ROOT, "build")
ATTIC = os.path.join(BUILD, "attic")
MEMORY = os.path.join(os.path.expanduser("~/.claude/projects"), ROOT.replace(os.sep, "-"), "memory")

INFRA = {
    "attic", "deliver", "lead", "app", "android", "compilers", "venv", "ghidra", "jobs", "tree-cache", "tree",
    "third_party", "data", "rcf", "replays", "xemu", "wasm", "wasm-app", "wasm-inputs", "clang-probe",
    "native", "hybrid", "tools", "external", "shaders", "farm", "texpack", "lua", "p3d", "ckpt", "traces",
    "agent-tools", "rn1", "elf1", "soft-intrinsics", "xtu", "equiv", "port",
}
NOTE_EXT = (".md", ".txt", ".log", ".sh", ".py", ".json", ".jsonl", ".c", ".cpp", ".h", ".patch", ".diff")
NOTE_MAX = 1 << 20
REF = re.compile(r"build/([A-Za-z0-9_.+-]+)")


def live_refs():
    names = set()
    out = subprocess.run(["git", "grep", "-ohE", r"build/[A-Za-z0-9_.+-]+", "--",
                          "CLAUDE.md", "tools", "tests", "config", "src", ".gitignore"],
                         cwd=ROOT, capture_output=True, text=True).stdout
    names.update(REF.findall(out))
    extra = [os.path.join(BUILD, "lead", "rules.md")]
    if os.path.isdir(MEMORY):
        extra += [os.path.join(MEMORY, f) for f in os.listdir(MEMORY)]
    for p in extra:
        try:
            names.update(REF.findall(open(p, errors="replace").read()))
        except OSError:
            pass
    return {n.rstrip(".") for n in names}


def newest_mtime(path, cutoff):
    """Files only: a folder's own date moves whenever anything is deleted from it."""
    if not os.path.isdir(path) or os.path.islink(path):
        try:
            return os.lstat(path).st_mtime > cutoff
        except OSError:
            return False
    if True:
        for dp, dns, fns in os.walk(path):
            for n in fns:
                if n == ".DS_Store":
                    continue
                try:
                    if os.lstat(os.path.join(dp, n)).st_mtime > cutoff:
                        return True
                except OSError:
                    pass
    return False


def size_of(path):
    if os.path.islink(path) or not os.path.isdir(path):
        return os.lstat(path).st_size
    total = 0
    for dp, _, fns in os.walk(path):
        for n in fns:
            try:
                total += os.lstat(os.path.join(dp, n)).st_size
            except OSError:
                pass
    return total


def archive(name, path):
    dst = os.path.join(ATTIC, name + ".tar.gz")
    n = 0
    with tarfile.open(dst, "w:gz") as tf:
        files = [path] if not os.path.isdir(path) else [
            os.path.join(dp, f) for dp, _, fns in os.walk(path) for f in fns]
        for f in files:
            if os.path.islink(f) or not f.endswith(NOTE_EXT):
                continue
            if os.path.getsize(f) > NOTE_MAX:
                continue
            tf.add(f, arcname=os.path.relpath(f, BUILD))
            n += 1
    if n == 0:
        os.remove(dst)
    return n


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--yes", action="store_true")
    ap.add_argument("--days", type=float, default=3)
    ap.add_argument("--keep", default="")
    a = ap.parse_args()

    keep = set(filter(None, a.keep.split(",")))
    refs = live_refs()
    procs = subprocess.run(["ps", "-axo", "command"], capture_output=True, text=True).stdout
    cutoff = time.time() - a.days * 86400
    stay, go = [], []
    for name in sorted(os.listdir(BUILD)):
        path = os.path.join(BUILD, name)
        if name in INFRA or name.startswith("ghidra.bak"):
            why = "infrastructure"
        elif name in keep:
            why = "--keep"
        elif name in refs:
            why = "named by a live file"
        elif name == ".DS_Store":
            continue
        elif re.search(r"build/" + re.escape(name) + r"(?![A-Za-z0-9_.+-])", procs):
            why = "used by a running process"
        elif newest_mtime(path, cutoff):
            why = f"changed in the last {a.days:g} days"
        else:
            go.append((name, path, size_of(path)))
            continue
        stay.append((name, why))

    for name, why in stay:
        print(f"keep    {name:32} {why}")
    total = sum(s for _, _, s in go)
    for name, _, s in go:
        print(f"{'delete' if a.yes else 'would  '}  {name:32} {s / 2**20:9.1f} MB")
    print(f"# {len(stay)} kept, {len(go)} to go, {total / 2**30:.2f} GB")
    if not a.yes:
        print("# dry run; --yes archives their notes to build/attic/ and deletes them")
        return
    os.makedirs(ATTIC, exist_ok=True)
    with open(os.path.join(ATTIC, "index.txt"), "a") as idx:
        for name, path, s in go:
            n = archive(name, path)
            if os.path.isdir(path) and not os.path.islink(path):
                shutil.rmtree(path)
            else:
                os.remove(path)
            idx.write(f"{time.strftime('%Y-%m-%d')} {name} {s} bytes, {n} note files\n")
    print(f"# done; free: {shutil.disk_usage(BUILD).free / 2**30:.0f} GB")


if __name__ == "__main__":
    sys.exit(main())
