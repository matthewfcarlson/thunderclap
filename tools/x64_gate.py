#!/usr/bin/env python3
"""The 64-bit equivalence regression gate (docs/equivalence.md "64-bit gate").

The 64-bit builds compile every tree TU; `equiv.py TU ADDR --x64` checks a block's x86-64 object against its 32-bit
clang object (tools/equiv64.py). x64eq's tree-wide sweep (docs/native-build.md) left ~1,200 blocks that differ in one of
the three classes that are real 64-bit bugs:

  layout    an access the 64-bit layout puts elsewhere (past an object's 64-bit end, a pointer kept in 4 bytes)
  ptrtrunc  a pointer truncated to 32 bits
  crash64   the 64-bit run faults where the 32-bit run returned (`crash64/ptr32`: through a pointer read from 32-bit data)

Those blocks are the baseline, config/x64-baseline.json (addresses and class names only). The gate re-checks only the
blocks whose code changed and fails when one of them is newly in a gating class. Every other class (intwidth, int,
untyped, float, call, wild64, hang64, tool, inconclusive, unsupported) is reported, never fails: those are mostly the
fuzzer's or the checker's limits. `wild64` failures are listed apart (`triage`): an unsigned negative step
(`p += (unsigned)-k`) is a real bug of that shape.

  build/venv/bin/python tools/x64_gate.py check [--changed-since REF] [--tus FILE] [--local | --jobq] [--json]
  build/venv/bin/python tools/x64_gate.py check --changed-since REF --head COMMIT   # what the gate said about a commit
  build/venv/bin/python tools/x64_gate.py check ... --update-baseline   # ratchet: drop the blocks that improved
  build/venv/bin/python tools/x64_gate.py accept 0xADDR --why TEXT [--class C]  # admit a new difference, with a reason
  build/venv/bin/python tools/x64_gate.py keys TU.cpp...            # the blocks' code keys (debugging)
  build/venv/bin/python tools/tree_tu.py verify . --changed-since origin/main --x64   # verify, then this gate

Which blocks changed: per block a *code key*, sha256 over the code hash (tools/code_hash.py) of its function in the
32-bit clang object and in the x86-64 object equiv64 compiles (the same text, the same front end, a canonical `#line`).
The keys of the candidate TUs (those whose text changed since REF; every TU when a header changed) are computed on
both sides, REF from a `git archive` snapshot, and only blocks whose key differs (or that have none) are run. A header
edit that changes only the 64-bit layout changes the 64-bit key, so it is seen even where the MSVC object and the
`@`/`@w` hashes stay put. Keys are cached in build/tree-cache/x64gate/keys/ by the TU's text, its include closure and
the toolchain; results in build/tree-cache/x64gate/res/ by the code key, the checker's source and the settings, so
unchanged code is never run twice.

Runs use x64eq's sweep settings (200 inputs, 60 s budget): through the queue (tools/jobq_equiv.py, libclang's Python
binding shipped with each job) when more than --local-max blocks need a run, here otherwise (at most 2 processes).

The baseline only shrinks by itself: --update-baseline removes a block whose fresh result is equivalent or a
that no longer exists; another failure class (often the same bug seen first elsewhere) or an unsupported /
inconclusive / unfinished result keeps it. Adding one is
explicit: `accept ADDR --why TEXT` (the reason is recorded in the file).
"""
import argparse
import collections
import datetime
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
BASELINE = os.path.join(ROOT, "config/x64-baseline.json")
CACHE = os.path.join(ROOT, "build/tree-cache/x64gate")
GATING = ("layout", "ptrtrunc", "crash64")
# (rev1) non-failing classes listed apart for a human look: wild64 is mostly fuzzed indexes wrapping at 2^32 on i386,
# but an unsigned negative step (`p += (unsigned)-k`) is a real 64-bit bug of the same shape
TRIAGE = ("wild64",)
SETTINGS = {"inputs": 200, "time_budget": 60}
KEYVER = "x64key1"
LOCAL_MAX = 4


# ------------------------------------------------------------------------------------------------------ classes
def classify(rec):
    """(status class, gate class or None) of an equiv_batch.py record of an `equiv.py --x64` run. The status class is
    x64eq's (final.jsonl): `equivalent`, `fail:<class>`, `unsupported:<class>`, `inconclusive`, `compile_error`, ...;
    the gate class is `layout` / `ptrtrunc` / `crash64` (`crash64/ptr32` when the fault is through a pointer read from
    32-bit data), only for a failure in one of those classes."""
    if rec is None:
        return "unchecked", None
    st = rec.get("status") or "error"
    fd = rec.get("first_diff") or ""
    if st == "equivalent":
        return "equivalent", None
    if st == "fail":
        m = re.search(r"\[(\w+)\]", fd)
        c = m.group(1) if m else "?"
        if c in GATING:
            g = c + ("/ptr32" if c == "crash64" and "not an address" in fd else "")
            return "fail:" + c, g
        return "fail:" + c, None
    if st == "unsupported":
        if "no input completed on the 32-bit side" in fd:
            return "unsupported:no32", None
        m = re.search(r"\[(\w+)\]", fd)
        return "unsupported:" + (m.group(1) if m else "?"), None
    return st, None


def improved(status_class):
    """Does a fresh result take a block out of the baseline? Only a clean pass. A failure of another class is often the
    same bug seen first elsewhere (a crash64 through garbage that now returns garbage: `float`, `wild64`), and a check
    that couldn't run (unsupported, inconclusive, unfinished) says nothing: both keep the entry."""
    return status_class == "equivalent"


# ------------------------------------------------------------------------------------------------------ baseline
def load_baseline(path=BASELINE):
    if not os.path.exists(path):
        return {"blocks": {}, "why": {}}
    with open(path) as f:
        b = json.load(f)
    b.setdefault("blocks", {})
    b.setdefault("why", {})
    return b


def write_baseline(b, path=BASELINE):
    """One entry per line (reviewable diffs), sorted by address."""
    head = {k: v for k, v in b.items() if k not in ("blocks", "why")}
    blocks = b.get("blocks", {})
    counts = collections.Counter(blocks.values())
    head["counts"] = dict(sorted(counts.items()))
    head["total"] = len(blocks)
    lines = ["{"]
    for k, v in head.items():
        lines.append("  %s: %s," % (json.dumps(k), json.dumps(v)))
    lines.append('  "why": {')
    w = sorted(b.get("why", {}).items())
    for i, (a, t) in enumerate(w):
        lines.append("    %s: %s%s" % (json.dumps(a), json.dumps(t), "," if i + 1 < len(w) else ""))
    lines.append("  },")
    lines.append('  "blocks": {')
    items = sorted(blocks.items())
    for i, (a, c) in enumerate(items):
        lines.append("    %s: %s%s" % (json.dumps(a), json.dumps(c), "," if i + 1 < len(items) else ""))
    lines.append("  }")
    lines.append("}")
    tmp = path + ".tmp"
    with open(tmp, "w") as f:
        f.write("\n".join(lines) + "\n")
    os.replace(tmp, path)


# ------------------------------------------------------------------------------------------------------ code keys
def _sha_file(p):
    with open(p, "rb") as f:
        return hashlib.sha1(f.read()).hexdigest()


_BK = []


def base_key():
    """What every code key depends on besides the TU: the compiler, both targets' flags, the tools that build the
    compiled text and the hash."""
    if not _BK:
        import inspect
        import clang_probe as cp
        import equiv
        import equiv64
        import tree_tu
        clang = equiv64.clangxx()
        ver = subprocess.run([clang, "--version"], capture_output=True, text=True).stdout.splitlines()[0]
        ver = re.sub(r"^.*?clang version (\S+).*$", r"\1", ver)
        h = hashlib.sha1((KEYVER + "\0" + ver + "\0" + repr(equiv64.front_flags("x86_64-pc-windows-msvc"))).encode())
        for m in ("code_hash.py", "clang_probe.py", "gen_tree.py"):
            h.update(_sha_file(os.path.join(ROOT, "tools", m)).encode())
        for f in (equiv.compile_native, equiv64.compile32, equiv64.compile64, equiv64.norm_mangled, tree_tu.clang_symbol,
                  equiv64.loc_key, _tu_keys, _wrapper, pair64, canon64, _prefix):
            h.update(inspect.getsource(f).encode())
        _BK.append(h.hexdigest())
    return _BK[0]


def canon64(n):
    """An MS mangled name with the differences between the i386 and x86-64 spellings taken out (equiv64.norm_mangled,
    plus: every calling convention is the one x64 has, thiscall/stdcall/fastcall members and functions alike)."""
    import equiv64
    if n.startswith("??_C@"):
        return n
    n = equiv64.norm_mangled(n)
    n = re.sub(r"@@([ABEFIJMNQRUV])([ABCD])[AEGI]", r"@@\1\2E", n)
    n = re.sub(r"@@([CDKLST])[AEGI]", r"@@\1A", n)
    n = re.sub(r"@@([YZ])[AEGI]", r"@@\1A", n)
    return n


def _prefix(n):
    """A mangled name up to its qualified name's end and the next letter (`?f@C@ns@@Q`): the same on both targets."""
    i = n.find("@@")
    if not n.startswith("?") or i < 0 or i + 2 >= len(n):
        return None
    return n[:i + 3]


def pair64(s32, f64, by_canon, by_prefix64, by_prefix32):
    """The x86-64 object's name for the 32-bit clang name S32, or None: a C name undecorated; else the one name whose
    canon64 is S32's; else, for an MS name whose qualified name is unique in both objects, the 64-bit one with it
    (back-references make an overload's argument list differ between the targets: `HHH` / `_J0H`)."""
    if not s32.startswith("?"):
        m = re.match(r"^[_@](.+?)(?:@\d+)?$", s32)
        cn = m.group(1) if m else s32
        return cn if cn in f64 else None
    c = by_canon.get(canon64(s32), [])
    if len(c) == 1:
        return c[0]
    k = _prefix(s32)
    if k and len(by_prefix32.get(k, ())) == 1 and len(by_prefix64.get(k, ())) == 1:
        return by_prefix64[k][0]
    return None


def _wrapper(path, d, root):
    """equiv64.write_wrapper with `#line 1 "<path relative to the tree root>"`: __FILE__ strings must not hold the
    checkout's or a snapshot's location, or every key would differ between them."""
    import gen_tree
    with open(os.path.join(d, "tree_prelude.h"), "w") as f:
        f.write("\n".join(gen_tree.PRELUDE_LINES) + "\n")
    text = open(path, errors="replace").read()
    text = gen_tree.crt_guard_text(gen_tree.native_spelling(text))
    w = os.path.join(d, "eq64_src.cpp")
    with open(w, "w") as f:
        f.write('#include "tree_prelude.h"\n#line 1 "%s"\n%s' % (os.path.relpath(path, root).replace("\\", "/"), text))
    return w


def tu_keys(path):
    """{addr: {"key": hex or None, "why": reason when None, "s32", "s64"}} of every block of the tree TU PATH, cached
    by the TU's text and path, its include closure and base_key()."""
    import include_keys
    import tree_tu
    ap = os.path.abspath(path)
    root = tree_tu.find_root(ap)
    inc = os.path.join(root, "include")
    text = open(ap, "rb").read()
    d = include_keys.digest(ap, [inc], root=root, force=["compat/native.h"])
    if d is None:
        import build_tree
        d = "all " + build_tree.include_tree_digest(inc)
    rel = os.path.relpath(ap, root)
    k = hashlib.sha1((base_key() + "\0" + d + "\0" + rel + "\0").encode() + text).hexdigest()[:24]
    cp_ = os.path.join(CACHE, "keys", k + ".json")
    try:
        with open(cp_) as f:
            return json.load(f)
    except (OSError, ValueError):
        pass
    out = _tu_keys(ap, root)
    os.makedirs(os.path.dirname(cp_), exist_ok=True)
    with open(cp_ + ".%d.tmp" % os.getpid(), "w") as f:
        json.dump(out, f)
    os.replace(cp_ + ".%d.tmp" % os.getpid(), cp_)
    return out


def _tu_keys(ap, root):
    import clang_probe as cp
    import code_hash
    import equiv64
    import tree_tu
    from compare import Coff
    rec = tree_tu.scan(ap)
    blocks = rec["blocks"]
    out = {}
    lines = open(ap, errors="replace").read().splitlines()
    os.makedirs(os.path.join(ROOT, "build"), exist_ok=True)
    old = cp._X87_LIST
    cp._X87_LIST = set()        # (as tree_tu.wine_object: the queue hosts have no x87-keep list)
    try:
        with tree_tu.active(ap), tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as d:
            w = _wrapper(ap, d, root)
            try:
                o32 = equiv64.compile32(w, d)
                o64, _ = equiv64.compile64(w, d)
            except equiv64.CompileError as e:
                why = "compile: " + str(e).strip().splitlines()[-1][:160] if str(e).strip() else "compile error"
                return {b["addr"]: {"key": None, "why": why} for b in blocks}
            c32, c64 = Coff(o32), Coff(o64)
            f32 = {s[0]: s for s in c32.function_symbols()}
            f64 = {s[0]: s for s in c64.function_symbols()}
            by_canon, p64, p32 = {}, {}, {}
            for f in f64:
                by_canon.setdefault(canon64(f), []).append(f)
                p64.setdefault(_prefix(f), []).append(f)
            for f in f32:
                p32.setdefault(_prefix(f), []).append(f)
            names = {}
            lib = []

            def by_decl(s32):
                """(as equiv64.Checker.pick) the 64-bit function declared where S32's declaration is: libclang
                parses of both targets, made once per TU and only when the names alone can't pair a block."""
                if not lib:
                    try:
                        lib.append((equiv64.TU(w, d, "i686-pc-windows-msvc", 32),
                                    equiv64.TU(w, d, "x86_64-pc-windows-msvc", 64)))
                    except Exception:   # noqa: BLE001 - no libclang, or it can't parse: no pair
                        lib.append(None)
                if not lib[0]:
                    return None
                t32, t64 = lib[0]
                c32 = t32.by_mangled.get(s32)
                if c32 is None:
                    return None
                k = equiv64.loc_key(c32)
                hit = [mn for mn, c in t64.by_mangled.items() if mn in f64 and c.kind == c32.kind
                       and equiv64.loc_key(c) == k]
                return hit[0] if len(hit) == 1 else None

            for b in blocks:
                s = b.get("sym")
                if not s:
                    names[b["addr"]] = (None, None, "no pinned symbol")
                    continue
                s32 = tree_tu.clang_symbol(f32, s)
                if not s32:
                    # a scalar deleting destructor (clang emits none; equiv64 synthesizes it around the complete one)
                    m = re.match(r"^\?\?_G(.+)@@([A-Z])AEPAXI@Z$", s)
                    if m and "??1%s@@%sAE@XZ" % m.groups() in f32:
                        s32 = "??1%s@@%sAE@XZ" % m.groups()
                    else:
                        names[b["addr"]] = (None, None, "not in the 32-bit clang object")
                        continue
                s64 = pair64(s32, f64, by_canon, p64, p32) or by_decl(s32)
                names[b["addr"]] = (s32, s64, None if s64 else "no 64-bit pair")
            ext32 = {n[0]: int(a, 16) for a, n in names.items() if n[0]}
            ext64 = {n[1]: int(a, 16) for a, n in names.items() if n[1]}
            for b in blocks:
                s32, s64, why = names[b["addr"]]
                if why:
                    out[b["addr"]] = {"key": None, "why": why, "s32": s32}
                    continue
                bl = lines[b["lines"][0] - 1:b["lines"][1]]
                e32 = {n: a for n, a in ext32.items() if n != s32}
                e64 = {n: a for n, a in ext64.items() if n != s64}
                h32 = code_hash.function_hash(c32, f32[s32], e32, bl)
                h64 = code_hash.function_hash(c64, f64[s64], e64, bl)
                out[b["addr"]] = {"key": hashlib.sha1(("%s\0%s\0%s" % (KEYVER, h32, h64)).encode()).hexdigest()[:20],
                                  "s32": s32, "s64": s64}
    finally:
        cp._X87_LIST = old
    return out


def _keys_one(path):
    try:
        return path, tu_keys(path), None
    except Exception as e:      # noqa: BLE001 - keep the sweep going
        return path, None, repr(e)[:300]


def keys_of(paths, jobs=2):
    """{path: tu_keys or None}, errors {path: text}."""
    import multiprocessing
    out, errs = {}, {}
    if jobs <= 1 or len(paths) <= 1:
        res = map(_keys_one, paths)
    else:
        pool = multiprocessing.get_context("fork").Pool(jobs)
        res = pool.imap_unordered(_keys_one, paths, chunksize=2)
    for p, k, e in res:
        out[p] = k
        if e:
            errs[p] = e
    return out, errs


# ------------------------------------------------------------------------------------------------------ the two sides
def _git(*args, **kw):
    return subprocess.run(["git"] + list(args), cwd=ROOT, capture_output=True, text=True, **kw)


def rev(ref):
    r = _git("rev-parse", "--verify", ref + "^{commit}")
    if r.returncode:
        raise SystemExit("x64_gate: no commit %s" % ref)
    return r.stdout.strip()


TREE_DIRS = ("src/game", "src/engine", "src/platform/xbox")


def snapshot(commit, d):
    """The tree of COMMIT (include/ and the tree TUs) extracted into D; returns D."""
    os.makedirs(d, exist_ok=True)
    p1 = subprocess.Popen(["git", "archive", "--format=tar", commit, "include"] + list(TREE_DIRS), cwd=ROOT,
                          stdout=subprocess.PIPE)
    p2 = subprocess.run(["tar", "-x", "-C", d], stdin=p1.stdout, capture_output=True)
    p1.wait()
    if p1.returncode or p2.returncode:
        raise SystemExit("x64_gate: git archive %s failed" % commit)
    return d


def candidate_tus(ref, head=None, tus=None):
    """Tree TU paths (relative to the root) to key on both sides: TUS when given, else the TUs whose text changed
    between REF and HEAD (the working tree when HEAD is None), every TU when a header under src/ or include/ did."""
    import tree_tu
    if tus is not None:
        return sorted(tus)
    r = _git("diff", "--name-only", ref, *([head] if head else []), "--", "src", "include")
    files = r.stdout.split()
    if not head:        # (the working tree: untracked TUs too)
        files += _git("ls-files", "--others", "--exclude-standard", "--", *TREE_DIRS).stdout.split()
    if any(f.endswith((".h", ".hpp", ".inl")) for f in files):
        if head:
            return sorted(f for f in _git("ls-tree", "-r", "--name-only", head, "--", *TREE_DIRS).stdout.split()
                          if f.endswith(".cpp"))
        return sorted(os.path.relpath(p, ROOT) for p in tree_tu.tree_tus(ROOT))
    return sorted({f for f in files if f.endswith(".cpp") and f.startswith(tuple(d + "/" for d in TREE_DIRS))})


def side_keys(root, rels, jobs):
    """{addr: (rel, key record)} of the tree TUs RELS under ROOT (a TU that isn't there, or isn't a tree TU, adds
    nothing), plus key errors."""
    import tree_tu
    paths = [os.path.join(root, r) for r in rels]
    paths = [p for p in paths if os.path.exists(p) and tree_tu.is_tree_tu(p)]
    ks, errs = keys_of(paths, jobs)
    out = {}
    for p, k in ks.items():
        for a, rec in (k or {}).items():
            out[a] = (os.path.relpath(p, root), rec)
    return out, errs


def changed_blocks(ref, head=None, tus=None, jobs=2, workdir=None):
    """The blocks the gate checks: [(addr, rel path, head key record, why changed)], the blocks REF had in those TUs
    that HEAD doesn't, the HEAD-side root, and the key errors."""
    ref_c = rev(ref)
    rels = candidate_tus(ref_c, rev(head) if head else None, tus)
    tmp = workdir or tempfile.mkdtemp(prefix="x64gate-", dir=os.path.join(ROOT, "build"))
    try:
        rroot = snapshot(ref_c, os.path.join(tmp, "ref"))
        hroot = snapshot(rev(head), os.path.join(tmp, "head")) if head else ROOT
        rk, e1 = side_keys(rroot, rels, jobs)
        hk, e2 = side_keys(hroot, rels, jobs)
    except BaseException:
        if not workdir:
            shutil.rmtree(tmp, ignore_errors=True)
        raise
    out = []
    for a, (rel, h) in sorted(hk.items()):
        r = rk.get(a)
        if r is None:
            why = "new"
        elif h["key"] is None:
            why = "unkeyed (%s)" % h.get("why")
        elif r[1]["key"] != h["key"]:
            why = "code changed" if r[1]["key"] else "keyed now"
        else:
            continue
        out.append((a, rel, h, why))
    gone = sorted(set(rk) - set(hk))
    return {"blocks": out, "gone": gone, "tus": len(rels), "head_root": hroot, "tmp": tmp,
            "errors": dict(list(e1.items()) + list(e2.items())), "keyed": len(hk)}


# ------------------------------------------------------------------------------------------------------ runs
def checker_key():
    h = hashlib.sha1(b"x64res1\0" + json.dumps(SETTINGS, sort_keys=True).encode())
    for m in ("equiv64.py", "equiv.py", "equiv_batch.py"):
        h.update(_sha_file(os.path.join(ROOT, "tools", m)).encode())
    return h.hexdigest()


def _res_path(key):
    return os.path.join(CACHE, "res", hashlib.sha1((checker_key() + "\0" + key).encode()).hexdigest()[:24] + ".json")


def cached_result(key):
    if not key:
        return None
    try:
        with open(_res_path(key)) as f:
            return json.load(f)
    except (OSError, ValueError):
        return None


def store_result(key, rec):
    if not key or rec.get("status") in (None, "error"):
        return
    p = _res_path(key)
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p + ".%d.tmp" % os.getpid(), "w") as f:
        json.dump(rec, f)
    os.replace(p + ".%d.tmp" % os.getpid(), p)


def equiv_args():
    return ["--x64", "--inputs", str(SETTINGS["inputs"]), "--time-budget", str(SETTINGS["time_budget"])]


def run_blocks(items, mode="auto", jobs=2, name="x64gate", commit=None, workdir=None, quiet=False, prio=0):
    """items: [(addr, abs source path)] -> {addr: equiv_batch record}. MODE local / jobq / auto (the queue for more
    than LOCAL_MAX). COMMIT: the queue hosts check out COMMIT and get only the sources and the tools that differ from
    it (a historical side), else HEAD plus the uncommitted files (jobq_equiv's default)."""
    if not items:
        return {}
    d = workdir or tempfile.mkdtemp(prefix="x64run-", dir=os.path.join(ROOT, "build"))
    out = os.path.join(d, "runs.jsonl")
    if mode == "auto":
        mode = "local" if len(items) <= LOCAL_MAX else "jobq"
    try:
        if mode == "local":
            lst = os.path.join(d, "list.txt")
            with open(lst, "w") as f:
                for a, p in items:
                    f.write("%s %s\n" % (a, p))
            subprocess.run([sys.executable, os.path.join(ROOT, "tools/equiv_batch.py"), lst, out, "--no-jobq",
                            "--jobs", str(max(1, min(jobs, 2))), "--"] + equiv_args(), cwd=ROOT,
                           stdout=subprocess.DEVNULL if quiet else None)
            res = {}
            if os.path.exists(out):
                for l in open(out):
                    if l.strip():
                        r = json.loads(l)
                        res[r["addr"]] = r
            return res
        import equiv64
        import jobq
        import jobq_equiv
        orig_cf, orig_hc, orig_mj = jobq.collect_files, jobq.head_commit, jobq.make_job
        if prio:
            def mj(*a_, **kw):
                a_ = list(a_)
                if len(a_) > 8:     # (jobq_equiv passes prio as the 9th positional argument)
                    a_[8] = prio
                else:
                    kw["prio"] = prio
                return orig_mj(*a_, **kw)
            jobq.make_job = mj
        jf = equiv64.job_files()
        if commit:
            ship = [f for f in _git("diff", "--name-only", commit, "--", "tools").stdout.split()
                    if f.endswith(".py") and os.path.exists(os.path.join(ROOT, f))]
            jobq.head_commit = lambda: commit
            jobq.collect_files = lambda specs, dirty=False, **kw: {**orig_cf(list(specs or []) + ship, False, **kw), **jf}
        else:
            jobq.collect_files = lambda specs, dirty=False, **kw: {**orig_cf(specs, dirty, **kw), **jf}
        try:
            return jobq_equiv.run_items(name, items, out, equiv_args(), per=4, dirty=not commit, quiet=quiet)
        finally:
            jobq.collect_files, jobq.head_commit, jobq.make_job = orig_cf, orig_hc, orig_mj
    finally:
        if not workdir:
            shutil.rmtree(d, ignore_errors=True)


# ------------------------------------------------------------------------------------------------------ the gate
def judge(blocks, results, baseline):
    """Per checked block: its status class, gate class and verdict: new (a failure), known (in the baseline),
    improved (in the baseline, now equivalent: removable), known-unclear (in the baseline, now another class), unchecked (no result: a failure too), ok, other (reported)."""
    known = baseline.get("blocks", {})
    out = []
    for a, rel, h, why in blocks:
        r = results.get(a)
        sc, g = classify(r)
        if r is None:
            v = "unchecked"
        elif g:
            v = "known" if a in known else "new"
        elif a in known:
            v = "improved" if improved(sc) else "known-unclear"
        elif sc.startswith("fail:") and sc[5:] in TRIAGE:
            v = "triage"
        else:
            v = "ok" if sc == "equivalent" else "other"
        out.append({"addr": a, "tu": rel, "changed": why, "class": sc, "gate": g, "verdict": v,
                    "baseline": known.get(a), "cached": bool(r and r.get("_cached")),
                    "diff": ((r or {}).get("first_diff") or "")[:240]})
    return out


def gate(ref="HEAD", head=None, tus=None, mode="auto", jobs=2, name="x64gate", quiet=False, workdir=None,
         baseline_path=BASELINE, prio=0):
    """Run the gate: {"rows": judge's rows, "summary", "gone", "errors", "failed": bool}."""
    base = load_baseline(baseline_path)
    ch = changed_blocks(ref, head, tus, jobs, workdir)
    try:
        results, todo = {}, []
        for a, rel, h, why in ch["blocks"]:
            c = cached_result(h.get("key"))
            if c is not None:
                c["_cached"] = True
                results[a] = c
            else:
                todo.append((a, os.path.join(ch["head_root"], rel)))
        if todo and not quiet:
            print("x64_gate: %d changed blocks, %d cached, %d to run (%s)" % (len(ch["blocks"]), len(ch["blocks"]) - len(todo),
                                                                          len(todo), mode), file=sys.stderr, flush=True)
        fresh = run_blocks(todo, mode, jobs, name, rev(head) if head else None, quiet=quiet, prio=prio)
        keyof = {a: h.get("key") for a, rel, h, why in ch["blocks"]}
        for a, r in fresh.items():
            r = {k: v for k, v in r.items() if k not in ("src", "host")}
            store_result(keyof.get(a), r)
            results[a] = r
    finally:
        if not workdir:
            shutil.rmtree(ch["tmp"], ignore_errors=True)
    rows = judge(ch["blocks"], results, base)
    vs = collections.Counter(r["verdict"] for r in rows)
    cs = collections.Counter(r["class"] for r in rows)
    gone_known = [a for a in ch["gone"] if a in base["blocks"]]
    summary = {"ref": ref, "head": head or "working tree", "tus": ch["tus"], "blocks_keyed": ch["keyed"],
               "changed": len(rows), "ran": len(fresh), "cached": sum(r["cached"] for r in rows),
               "verdicts": dict(sorted(vs.items())), "classes": dict(sorted(cs.items())), "gone": len(ch["gone"]),
               "gone_in_baseline": len(gone_known), "key_errors": len(ch["errors"])}
    failed = bool(vs.get("new") or vs.get("unchecked") or ch["errors"])
    return {"rows": rows, "summary": summary, "gone": ch["gone"], "errors": ch["errors"], "failed": failed}


def update_baseline(res, base, why_gone="gone"):
    """The ratchet: drop the blocks that improved or no longer exist. Returns the removed addresses."""
    removed = []
    for r in res["rows"]:
        if r["verdict"] == "improved":
            removed.append(r["addr"])
    removed += [a for a in res["gone"] if a in base["blocks"]]
    for a in removed:
        base["blocks"].pop(a, None)
        base["why"].pop(a, None)
    return removed


def render(res):
    lines = []
    for r in sorted(res["rows"], key=lambda r: ({"new": 0, "unchecked": 1, "triage": 2, "improved": 3, "known": 4}.get(
                    r["verdict"], 5),
                                                 r["addr"])):
        if r["verdict"] in ("ok",):
            continue
        lines.append("%-13s %s %-22s %-14s %s%s" % (r["verdict"].upper() if r["verdict"] in ("new", "unchecked") else
                                                   r["verdict"], r["addr"], r["class"], r["changed"][:14], r["tu"],
                                                   ("  [baseline %s]" % r["baseline"]) if r["baseline"] else ""))
        if r["verdict"] in ("new", "triage"):
            lines.append("    " + r["diff"][:200])
    for p, e in sorted(res["errors"].items()):
        lines.append("KEY ERROR %s: %s" % (p, e))
    lines.append(json.dumps(res["summary"]))
    lines.append("x64 gate: %s" % ("FAIL" if res["failed"] else "ok"))
    return "\n".join(lines)


# ------------------------------------------------------------------------------------------------------ cli
def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("check", help="gate the blocks changed since REF")
    p.add_argument("--changed-since", default="HEAD", metavar="REF", help="(default HEAD: the uncommitted changes)")
    p.add_argument("--head", metavar="COMMIT", help="gate COMMIT instead of the working tree (validation)")
    p.add_argument("--tus", metavar="FILE", help="key only these TUs (paths relative to the root, one per line)")
    g = p.add_mutually_exclusive_group()
    g.add_argument("--local", action="store_const", dest="mode", const="local")
    g.add_argument("--jobq", action="store_const", dest="mode", const="jobq")
    p.add_argument("--jobs", type=int, default=2, help="local processes (keys, local runs; at most 2 runs)")
    p.add_argument("--name", default=os.environ.get("USER", "x64gate"), help="the queue jobs' owner name")
    p.add_argument("--prio", type=int, default=0, help="the queue jobs' priority (-1: behind everyone's)")
    p.add_argument("--update-baseline", action="store_true", help="drop improved and removed blocks from the baseline")
    p.add_argument("--baseline", default=BASELINE)
    p.add_argument("--out", metavar="OUT.jsonl", help="one record per checked block")
    p.add_argument("--json", action="store_true")
    p = sub.add_parser("accept", help="add a block to the baseline, with the reason")
    p.add_argument("addr")
    p.add_argument("--why", required=True)
    p.add_argument("--class", dest="cls", help="its gate class (default: the last gate result for its current code)")
    p.add_argument("--tu", help="its TU (default: found by address)")
    p.add_argument("--baseline", default=BASELINE)
    p = sub.add_parser("keys", help="the code keys of TUs")
    p.add_argument("tus", nargs="+")
    p = sub.add_parser("baseline", help="the baseline's counts")
    p.add_argument("--baseline", default=BASELINE)
    a = ap.parse_args(argv)

    if a.cmd == "keys":
        for t in a.tus:
            for addr, k in sorted(tu_keys(t).items()):
                print(addr, k.get("key") or "-", k.get("s64") or k.get("why"))
        return 0
    if a.cmd == "baseline":
        b = load_baseline(a.baseline)
        print(json.dumps({"total": len(b["blocks"]), "counts": dict(collections.Counter(b["blocks"].values())),
                          "accepted": len(b["why"])}, indent=1))
        return 0
    if a.cmd == "accept":
        addr = "0x%08x" % int(a.addr, 16)
        b = load_baseline(a.baseline)
        cls = a.cls
        if cls is None:
            import tree_tu
            tu = a.tu or next((os.path.relpath(p, ROOT) for p in tree_tu.tree_tus(ROOT)
                               if ("// %s " % addr) in open(p, errors="replace").read()), None)
            k = tu_keys(os.path.join(ROOT, tu)).get(addr) if tu else None
            r = cached_result((k or {}).get("key"))
            cls = classify(r)[1] if r else None
            if not cls:
                raise SystemExit("x64_gate accept: no gating result for %s's current code (run the gate first, or "
                                 "--class)" % addr)
        if cls.split("/")[0] not in GATING:
            raise SystemExit("x64_gate accept: %s is not a gate class (%s)" % (cls, ", ".join(GATING)))
        b["blocks"][addr] = cls
        b["why"][addr] = "%s (%s)" % (a.why, datetime.date.today().isoformat())
        write_baseline(b, a.baseline)
        print("accepted %s %s" % (addr, cls))
        return 0
    tus = [l.strip() for l in open(a.tus) if l.strip()] if a.tus else None
    res = gate(a.changed_since, a.head, tus, a.mode or "auto", a.jobs, a.name, quiet=a.json, baseline_path=a.baseline,
               prio=a.prio)
    if a.out:
        with open(a.out, "w") as f:
            for r in res["rows"]:
                f.write(json.dumps(r) + "\n")
    if a.update_baseline:
        b = load_baseline(a.baseline)
        removed = update_baseline(res, b)
        if removed:
            write_baseline(b, a.baseline)
        res["summary"]["baseline_removed"] = removed
    print(json.dumps({"summary": res["summary"], "failed": res["failed"],
                      "new": [r for r in res["rows"] if r["verdict"] in ("new", "unchecked")],
                      "triage": [r for r in res["rows"] if r["verdict"] == "triage"]}, indent=1)
          if a.json else render(res))
    return 1 if res["failed"] else 0


if __name__ == "__main__":
    sys.exit(main())
