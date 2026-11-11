"""Stale-input guard for Wine build jobs (guard1; docs/compute.md "Wine builds", docs/wine-build.md).

A Wine build job ships local, untracked inputs that are generated from tracked sources: the data TUs
(build/data/src, tools/data_gen.py --gen-only), the audio/input platform library
(build/third_party/out/sdl-backends/win32/hulk_sdl.lib, tools/wine_sdl.py backends --target win32) and the pddi/bgfx
objects (build/third_party/out/pddi-win32/obj, tools/wine_gfx.py pddi --target win32). When one lags the sources the
job builds, the image breaks without a source change (2026-11-10: jobs 71106 and 71282). Each such input carries a
stamp: the content hash of the sources it was generated from (`<input>/.srchash`, or `<lib>.srchash` next to a
platform library as tools/platform_libs.py writes it), plus `<stamp>.files.json`, the per-file hashes, so a stale input
can be explained file by file. The producers write the stamps (data_gen, wine_sdl backends, wine_gfx pddi).

  * submit (tools/wine_build_job.py, check_submit): the job's view of the generating sources (its workspace, --live
    paths from this checkout) is hashed and compared with each input's stamp. A stale shared input is rebuilt here
    when its generating sources are clean in git and the job sees the checkout's copies; otherwise the submit is refused
    (--data-src / --sdl-src for a private build, or --allow-stale). A private input (--data-src / --sdl-src) is never
    rebuilt: stale with a stamp is refused like a shared one, unstamped is a warning.
  * host (tools/wine_build_run.py, host_check): the same comparison over the lineage's sources and the shipped
    inputs, before any stage; a stale input fails the job (exit 3) unless the spec says allow_stale.

Stdlib only and python 3.9 compatible (the build hosts import it from the job's tools/).

  build/venv/bin/python tools/input_guard.py status [--workspace DIR] [--live PATH...]   # what submit would decide
"""
import fcntl
import hashlib
import json
import os
import subprocess
import sys
import tempfile
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
TP = "build/third_party/out/"
PLAT = "src/platform/sdl"
SKIP_NAMES = ("__pycache__", ".git", ".DS_Store")
SKIP_SUFFIX = (".pyc", ".orig", ".rej")          # (what wine_build_job.walk leaves out: they never reach a host)


# ---------------------------------------------------------------------------------------------- views and hashes
class View:
    """The job's sources: files under ROOT (a workspace or a lineage), except LIVE path prefixes, which come from
    LIVE_ROOT (the checkout: wine_build_job submit --live)."""

    def __init__(self, root, live=(), live_root=ROOT):
        self.root = os.path.abspath(root)
        self.live = [x.strip("/") for x in live or ()]
        self.live_root = os.path.abspath(live_root)

    def is_live(self, rel):
        return any(rel == x or rel.startswith(x + "/") for x in self.live)

    def path(self, rel):
        return os.path.join(self.live_root if self.is_live(rel) else self.root, rel)

    def roots(self):
        return [self.root] + ([self.live_root] if self.live and self.live_root != self.root else [])

    def listdir(self, reldir, recursive):
        """Repo-relative paths of the files under reldir as the job sees them, sorted."""
        cand = set()
        for r in self.roots():
            base = os.path.join(r, reldir)
            if not os.path.isdir(base):
                continue
            if recursive:
                for dp, dns, fns in os.walk(base):
                    dns[:] = [d for d in dns if d not in SKIP_NAMES]
                    cand.update(os.path.relpath(os.path.join(dp, f), r) for f in fns)
            else:
                cand.update(os.path.join(reldir, f) for f in os.listdir(base) if os.path.isfile(os.path.join(base, f)))
        return sorted(rel for rel in cand if keep(rel) and os.path.isfile(self.path(rel)))


def keep(rel):
    return os.path.basename(rel) not in SKIP_NAMES and not rel.endswith(SKIP_SUFFIX)


def sha1_file(p):
    h = hashlib.sha1()
    with open(p, "rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    return h


def digest(files, base=""):
    """(hex digest, {rel: sha1}) of [(rel, abs path)]: per file its path relative to BASE, NUL, the sha1 of its bytes
    (the scheme of tools/platform_libs.source_hash, so a library's existing stamp keeps its meaning)."""
    h = hashlib.sha1()
    per = {}
    for rel, p in sorted(files, key=lambda x: os.path.relpath(x[0], base) if base else x[0]):
        d = sha1_file(p)
        per[rel] = d.hexdigest()
        h.update((os.path.relpath(rel, base) if base else rel).encode() + b"\0")
        h.update(d.digest())
    return h.hexdigest(), per


# ---------------------------------------------------------------------------------------------- the guarded inputs
class Guard:
    """One generated input. input: its directory relative to the inputs root (as in wine_build_run.INPUT_DIRS);
    stamp: the stamp file relative to that directory; base: the directory source paths are hashed relative to."""
    name = what = input = stamp = flag = None
    base = ""
    local = ()                  # inputs-root-relative files that are part of the hash (build/functions.csv)
    pathspecs = ()              # git pathspecs for the dirty check (filtered by owns())
    unstamped = "stale"         # what an input without a stamp is: stale, mtime (fresh/stale by mtime), note
    optional = False            # missing input: not checked

    def sources(self, view):
        raise NotImplementedError

    def owns(self, rel):
        return True

    def files(self, view, inp_root):
        out = [(rel, view.path(rel)) for rel in self.sources(view)]
        out += [(rel, os.path.join(inp_root, rel)) for rel in self.local if os.path.isfile(os.path.join(inp_root, rel))]
        return out

    def stamp_path(self, inp_dir):
        return os.path.join(inp_dir, self.stamp)

    def present(self, inp_dir):
        return os.path.isdir(inp_dir) and bool(os.listdir(inp_dir))

    def rebuild(self, log):
        raise NotImplementedError


class DataTUs(Guard):
    name, what, input, stamp, flag = "data", "data TUs (tools/data_gen.py --gen-only)", "build/data/src", ".srchash", "--data-src"
    # what data_gen's generate step reads (Model, pinned_vars, typed records, the pointer evidence)
    SOURCES = ["config/data.json", "config/splits.json", "config/data-ptrs.json", "config/data-not-pointers.json",
               "config/data-pointers.json", "include/decls/address.h", "include/decls/data/records.h",
               "tools/data_gen.py", "tools/data_inventory.py", "tools/xbe.py"]
    local = ("build/functions.csv",)
    pathspecs = tuple(SOURCES)

    def sources(self, view):
        return [r for r in self.SOURCES if os.path.isfile(view.path(r))]

    def rebuild(self, log):
        """A fresh generation in a private directory, swapped in (data_gen leaves TUs of objects that no longer exist)."""
        tmp = tempfile.mkdtemp(prefix="data-gen.", dir=os.path.join(ROOT, "build"))
        try:
            env = dict(os.environ, HULK_DATA_DIR=tmp)
            run([py(), "tools/data_gen.py", "--gen-only", "--no-decls"], env, log)
            dst = os.path.join(ROOT, self.input)
            old = dst + ".old-%d" % os.getpid()
            if os.path.exists(dst):
                os.rename(dst, old)
            os.rename(os.path.join(tmp, "src"), dst)
            if os.path.exists(old):
                rmtree(old)
        finally:
            rmtree(tmp)


class PlatformLib(Guard):
    """A tools/platform_libs.py library (stamp `<lib>.srchash` beside it, sources under src/platform/sdl)."""
    base = PLAT
    pathspecs = (PLAT,)

    def __init__(self, rel, dirs, files, cmd, only_if_built):
        self.rel, self.dirs, self.extra, self.cmd = rel, dirs, files, cmd
        lib = os.path.basename(rel)
        self.name = lib
        self.input = TP + os.path.dirname(rel)
        self.stamp = lib + ".srchash"
        self.what = "%s (tools/%s)" % (lib, " ".join(cmd))
        self.flag = "--sdl-src" if lib == "hulk_sdl.lib" else None
        # hulk_sdl.lib is required and was stamped by mtime where it is built (platform_libs.stamp_fresh); fs and
        # movies stay as they were: checked when they carry a stamp, a note otherwise
        self.unstamped = "mtime" if lib == "hulk_sdl.lib" else "note"
        self.optional = only_if_built or lib != "hulk_sdl.lib"

    def present(self, inp_dir):
        return os.path.isfile(os.path.join(inp_dir, os.path.basename(self.rel)))

    def mtime_target(self, inp_dir):
        return os.path.join(inp_dir, os.path.basename(self.rel))

    def sources(self, view):
        out = [r for r in view.listdir(PLAT, False)]
        for d in self.dirs:
            out += view.listdir(PLAT + "/" + d, True)
        out += [PLAT + "/" + f for f in self.extra if os.path.isfile(view.path(PLAT + "/" + f))]
        return sorted(set(out))

    def owns(self, rel):
        if not rel.startswith(PLAT + "/"):
            return False
        sub = rel[len(PLAT) + 1:]
        return "/" not in sub or any(sub.startswith(d + "/") for d in self.dirs) or sub in self.extra

    def rebuild(self, log):
        env = dict(os.environ)
        env.pop("HULK_TP_OUT", None)
        run([py(), os.path.join("tools", self.cmd[0])] + list(self.cmd[1:]), env, log)


class Pddi(Guard):
    name, what, input, stamp, flag = ("pddi", "pddi/bgfx objects (tools/wine_gfx.py pddi --target win32)",
                                      TP + "pddi-win32/obj", ".srchash", None)
    unstamped = "mtime"
    optional = True             # (a link without --gfx does not need them)
    pathspecs = (PLAT,)

    def sources(self, view):
        # the backend's units, headers and shaders (shaders/vp/combiners.txt included) and the top-level
        # src/platform/sdl files (platform_events.cpp is one of the units); not pddi/smoke (host tests)
        return sorted(set(view.listdir(PLAT, False) +
                          [r for r in view.listdir(PLAT + "/pddi", True) if not r.startswith(PLAT + "/pddi/smoke/")]))

    def owns(self, rel):
        if not rel.startswith(PLAT + "/"):
            return False
        sub = rel[len(PLAT) + 1:]
        return "/" not in sub or (sub.startswith("pddi/") and not sub.startswith("pddi/smoke/"))

    def mtime_target(self, inp_dir):
        objs = [os.path.join(inp_dir, f) for f in os.listdir(inp_dir) if f.endswith(".obj")]
        return min(objs, key=os.path.getmtime) if objs else None

    def rebuild(self, log):
        env = dict(os.environ)
        env.pop("HULK_TP_OUT", None)
        out = run([py(), "tools/wine_gfx.py", "shaders"], env, log, capture=True)
        try:
            res = json.loads(out[out.index("{"):])
        except ValueError:
            raise GuardError("tools/wine_gfx.py shaders printed no result:\n" + out[-2000:])
        bad = {k: v for k, v in res.items() if not v.startswith("ok")}
        if bad:
            raise GuardError("shaders failed: %s" % json.dumps(bad)[:2000])
        run([py(), "tools/wine_gfx.py", "pddi", "--target", "win32"], env, log)


def guards():
    out = [DataTUs()]
    here = os.path.dirname(os.path.abspath(__file__))
    added = here not in sys.path
    if added:
        sys.path.insert(0, here)
    try:
        import platform_libs as pl
        out += [PlatformLib(*x) for x in pl.LIBS]
    except ImportError:
        pass
    finally:
        if added:
            sys.path.remove(here)
    out.append(Pddi())
    return out


def guard(name):
    for g in guards():
        if g.name == name:
            return g
    raise KeyError(name)


class GuardError(Exception):
    pass


# ---------------------------------------------------------------------------------------------- stamps
def read_stamp(path):
    try:
        with open(path) as f:
            return f.read().strip() or None
    except OSError:
        return None


def read_files(path):
    """The per-file hashes recorded with a stamp, if they belong to it."""
    try:
        with open(path + ".files.json") as f:
            d = json.load(f)
    except (OSError, ValueError):
        return None
    return d.get("files") if d.get("hash") == read_stamp(path) else None


def write_stamp(path, dg, per):
    for p, text in ((path + ".files.json", json.dumps({"hash": dg, "files": per}, indent=0, sort_keys=True) + "\n"),
                    (path, dg + "\n")):
        tmp = p + ".%d.tmp" % os.getpid()
        with open(tmp, "w") as f:
            f.write(text)
        os.replace(tmp, p)


def stamp(g, inp_dir, view=None, inp_root=ROOT):
    """Stamp INP_DIR (an input of guard G) as built from VIEW's sources (default: this checkout). Producers call this."""
    dg, per = digest(g.files(view or View(ROOT), inp_root), g.base)
    write_stamp(g.stamp_path(inp_dir), dg, per)
    return dg


def source_stamp(name, root=ROOT):
    """For producers (data_gen, wine_sdl, wine_gfx): the stamp of guard NAME's sources in ROOT, taken before they build;
    put_stamp() writes it next to the output once the build succeeded. Best effort (None: no stamp)."""
    try:
        g = guard(name)
        dg, per = digest(g.files(View(root), root), g.base)
        return g, dg, per
    except (OSError, KeyError) as e:
        print("input_guard: no source stamp for %s (%s)" % (name, e), file=sys.stderr)
        return None


def put_stamp(tok, inp_dir):
    if tok:
        g, dg, per = tok
        write_stamp(g.stamp_path(inp_dir), dg, per)


def check(g, inp_dir, view, inp_root):
    """{"name", "input", "state": fresh|stale|unstamped|missing, "why", "changed": [...]} for one input."""
    r = {"name": g.name, "input": g.input, "dir": inp_dir}
    if not g.present(inp_dir):
        r.update(state="missing", why="not present")
        return r
    sp = g.stamp_path(inp_dir)
    st = read_stamp(sp)
    dg, per = digest(g.files(view, inp_root), g.base)
    r["hash"] = dg
    if st:
        r["stamp"] = st
        if st == dg:
            r.update(state="fresh", why="content hash")
            return r
        old = read_files(sp)
        if old is not None:
            r["changed"] = sorted(k for k in set(old) | set(per) if old.get(k) != per.get(k))
        r.update(state="stale", why="content hash")
        return r
    if g.unstamped == "mtime" and hasattr(g, "mtime_target"):
        t = g.mtime_target(inp_dir)
        if t:
            tm = os.path.getmtime(t)
            newer = sorted(rel for rel, p in g.files(view, inp_root) if os.path.getmtime(p) > tm)
            r.update(state="stale" if newer else "fresh", why="no stamp; mtime")
            if newer:
                r["changed"] = newer
            return r
    if g.unstamped == "note":
        r.update(state="unstamped", why="no stamp")
        return r
    r.update(state="stale", why="no stamp")
    return r


# ---------------------------------------------------------------------------------------------- git
def git(args, cwd=ROOT):
    return subprocess.run(["git"] + args, cwd=cwd, capture_output=True, text=True).stdout


def dirty(g, root=ROOT):
    """The guard's generating sources with uncommitted edits in ROOT (git status lines), untracked files included."""
    out = git(["status", "--porcelain=v1", "--untracked-files=all", "--"] + list(g.pathspecs), root)
    res = []
    for line in out.splitlines():
        rel = line[3:].split(" -> ")[-1].strip('"')
        if g.owns(rel) and keep(rel):
            res.append(line)
    return res


def newest_commit(g, root=ROOT):
    """The newest commit that touched the guard's generating sources (as this checkout has them)."""
    files = [rel for rel in g.sources(View(root))]
    return git(["log", "-1", "--format=%h %cs %s", "--"] + files, root).strip()[:120] if files else ""


# ---------------------------------------------------------------------------------------------- submit and host
def py():
    p = os.path.join(ROOT, "build/venv/bin/python")
    return p if os.path.exists(p) else sys.executable


def run(argv, env, log, capture=False):
    log("input_guard: " + " ".join(os.path.relpath(a, ROOT) if a.startswith(ROOT) else a for a in argv))
    r = subprocess.run(argv, cwd=ROOT, env=env, stdin=subprocess.DEVNULL, capture_output=True, text=True)
    if r.returncode:
        raise GuardError("%s failed (exit %d):\n%s" % (" ".join(argv[1:3]), r.returncode, (r.stdout + r.stderr)[-3000:]))
    return r.stdout


def rmtree(p):
    import shutil
    shutil.rmtree(p, ignore_errors=True)


def describe(g, r, root=ROOT):
    ch = r.get("changed")
    if ch and "mtime" in r["why"]:
        what = "it is older than %s%s (no stamp; by mtime)" % (", ".join(ch[:6]), " and %d more" % (len(ch) - 6) if len(ch) > 6 else "")
    elif ch:
        what = "its sources changed since it was built: %s%s" % (", ".join(ch[:6]), " and %d more" % (len(ch) - 6) if len(ch) > 6 else "")
    elif r["why"] == "no stamp":
        what = "it has no source stamp (built before the guard, or by a tool that does not stamp)"
    elif "mtime" in r["why"]:
        what = "it is older than its sources (no stamp; by mtime)"
    else:
        what = "it was built from other sources (content hash %s, the job's is %s)" % (r.get("stamp", "?")[:12], r["hash"][:12])
    nc = newest_commit(g, root)
    return "%s [%s] is stale: %s%s" % (os.path.relpath(r["dir"], root) if r["dir"].startswith(root) else r["dir"], g.what,
                                       what, "; newest commit touching its sources: " + nc if nc else "")


def check_submit(ws, live, local_dir, private, allow_stale=False, rebuild=True, log=None, root=ROOT):
    """Check every guarded input of a submit. ws: the job's workspace (root for the checkout itself); live: --live
    prefixes; local_dir(d): where input directory d comes from here; private: input dirs given as private builds.
    Rebuilds stale shared inputs whose generating sources are clean (and the job sees the checkout's copies), but only
    when nothing else is wrong (or allow_stale): a refused submit leaves the shared inputs alone.
    Returns (results, problems): problems are the messages of stale inputs not rebuilt (the caller refuses the
    submit unless allow_stale)."""
    log = log or (lambda m: print(m, file=sys.stderr))
    view, here = View(ws, live, root), View(root)
    results, problems, todo = [], [], []      # (a refused submit rebuilds nothing: todo runs only without problems)
    for g in guards():
        inp_dir = local_dir(g.input)
        r = check(g, inp_dir, view, root)
        r["private"] = g.input in private
        results.append(r)
        if r["state"] == "missing" and not g.optional:
            problems.append("%s [%s] is missing" % (g.input, g.what))
        if r["state"] == "unstamped":
            continue
        if r["state"] == "stale" and r["private"] and r["why"].startswith("no stamp"):
            r["state"] = "unstamped"
            log("input_guard: WARNING %s (your private build, %s) has no source stamp: it cannot be checked against the "
                "job's sources" % (inp_dir, g.flag))
            continue
        if r["state"] == "fresh" and r["why"].endswith("mtime") and not r["private"] and rebuild:
            stamp(g, inp_dir, view, root)          # (built here, before the stamps: record what it was built from)
            r["why"] += "; stamped now"
        if r["state"] != "stale":
            continue
        msg = describe(g, r, root)
        if r["private"]:
            problems.append(msg + ". It is your private build (%s): rebuild it from the job's sources%s." % (
                g.flag, ", or --allow-stale" if not allow_stale else ""))
            continue
        why_not = None
        if not rebuild:
            why_not = "rebuilding is off"
        elif ws != root and digest(g.files(view, root), g.base)[0] != digest(g.files(here, root), g.base)[0]:
            why_not = "the job's generating sources (workspace %s) differ from this checkout's" % ws
        else:
            d = dirty(g, root)
            if d:
                why_not = "its generating sources have uncommitted edits in this checkout (%s%s)" % (
                    "; ".join(x.strip() for x in d[:5]), " and %d more" % (len(d) - 5) if len(d) > 5 else "")
        if why_not:
            hint = ("pass a private build with %s DIR" % g.flag) if g.flag else "rebuild it (%s)" % g.what
            problems.append("%s. Not rebuilt: %s. %s%s, or submit with --allow-stale." % (
                msg, why_not, "Commit them, " if "uncommitted" in why_not else "", hint))
            continue
        todo.append((g, r, inp_dir, msg))
    if problems and not allow_stale:
        for g, r, _d, _m in todo:
            r["why"] += "; not rebuilt (the submit is refused)"
        return results, problems
    for g, r, inp_dir, msg in todo:
        log(msg + "; rebuilding it from this checkout (clean in git)")
        t0 = time.time()
        try:
            with lock(root):
                again = check(g, inp_dir, view, root)          # (another submit may have rebuilt it meanwhile)
                if again["state"] == "stale":
                    g.rebuild(log)
                    stamp(g, inp_dir, here, root)
        except GuardError as e:
            problems.append("%s; the rebuild failed: %s" % (msg, e))
            continue
        r2 = check(g, inp_dir, view, root)
        if r2["state"] != "fresh":
            problems.append("%s; still %s after the rebuild" % (msg, r2["state"]))
            continue
        r.update(state="fresh", why="rebuilt", rebuilt_s=round(time.time() - t0, 1), hash=r2["hash"])
        log("input_guard: rebuilt %s in %.0f s" % (g.input, time.time() - t0))
    return results, problems


class lock:
    def __init__(self, root):
        self.path = os.path.join(root, "build/.input_guard.lock")

    def __enter__(self):
        self.f = open(self.path, "w")
        fcntl.flock(self.f, fcntl.LOCK_EX)
        return self

    def __exit__(self, *a):
        fcntl.flock(self.f, fcntl.LOCK_UN)
        self.f.close()


def host_check(src_root, inp_root):
    """On a build host: every guarded input under INP_ROOT against the job's sources under SRC_ROOT. Returns
    [result]; state "stale" means the job would link an input that does not fit its sources. Inputs without a
    stamp are reported ("unstamped") but not judged: mtimes mean nothing on a host."""
    view = View(src_root)
    out = []
    for g in guards():
        inp_dir = os.path.join(inp_root, g.input)
        if not g.present(inp_dir):
            continue
        if not read_stamp(g.stamp_path(inp_dir)):
            out.append({"name": g.name, "input": g.input, "state": "unstamped", "why": "no stamp"})
            continue
        r = check(g, inp_dir, view, inp_root)
        r.pop("dir", None)
        if r["state"] == "stale":
            r["message"] = "%s [%s] is stale: %s" % (g.input, g.what, ("sources changed: " + ", ".join(r["changed"][:6]))
                                                     if r.get("changed") else "content hash %s, the job's %s" % (r["stamp"][:12], r["hash"][:12]))
        out.append(r)
    return out


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="c", required=True)
    s = sp.add_parser("status", help="each guarded input against this checkout (or a workspace): no rebuilds")
    s.add_argument("--workspace")
    s.add_argument("--live", nargs="*")
    s.add_argument("--json", action="store_true")
    a = ap.parse_args(argv)
    ws = os.path.abspath(a.workspace or ROOT)
    res, probs = check_submit(ws, a.live or [], lambda d: os.path.join(ROOT, d), set(), rebuild=False)
    if a.json:
        print(json.dumps({"results": res, "problems": probs}, indent=1))
    else:
        for r in res:
            print("%-14s %-10s %s%s" % (r["name"], r["state"], r["why"], (" (changed: %s)" % ", ".join(r["changed"][:4])) if r.get("changed") else ""))
        for p in probs:
            print("  " + p)
    return 1 if probs else 0


if __name__ == "__main__":
    sys.exit(main())
