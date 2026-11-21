#!/usr/bin/env python3
"""The 64-bit equivalence regression gate (docs/equivalence.md "64-bit gate").

The 64-bit builds compile every tree TU; `equiv.py TU ADDR --x64` checks a block's x86-64 object against its 32-bit
clang object (tools/equiv64.py). x64eq's tree-wide sweep (docs/native-build.md) left ~1,200 blocks that differ in one of
the three classes that are real 64-bit bugs:

  layout    an access the 64-bit layout puts elsewhere (past an object's 64-bit end, a pointer kept in 4 bytes)
  ptrtrunc  a pointer truncated to 32 bits
  crash64   the 64-bit run faults where the 32-bit run returned (`crash64/ptr32`: through a pointer read from 32-bit data)

and (integ3, rev5) `compile_error`: the run's compile failed, so the block's 64-bit code was never checked.

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
unchanged code is never run twice. A result also carries the fingerprints of the type layouts its run built (equiv64
Types.fingerprints): a cached one whose types the current source lays out differently (a field's type changed, the
code didn't) is run again (x64t12).

Runs use x64eq's sweep settings (200 inputs, 60 s budget): through the queue (tools/jobq_equiv.py, libclang's Python
binding shipped with each job) when more than --local-max blocks need a run, here otherwise (at most 2 processes).

(integ3, x64syn) Every candidate TU is also run through the native builds' own front ends, -fsyntax-only, for macOS
arm64 (native_mac.FRONT) and linux-x64 (native_elf.flags): an error is a failing `native_syntax` row (TU, target,
first errors), a missing toolchain a failing `native_syntax_unavailable` row; an error a header-only change didn't
bring (the TU's text and errors are REF's) is `known`. Cached in build/tree-cache/x64gate/syntax/; X64_GATE_OFF=native
leaves the pass out (diagnosis only).

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
GATING = ("layout", "ptrtrunc", "crash64", "compile_error")    # (integ3, rev5) compile_error: the --x64 run's
# compile failed, the block's 64-bit code was never checked
# (rev1) non-failing classes listed apart for a human look: wild64 is mostly fuzzed indexes wrapping at 2^32 on i386,
# but an unsigned negative step (`p += (unsigned)-k`) is a real 64-bit bug of the same shape
TRIAGE = ("wild64",)
SETTINGS = {"inputs": 200, "time_budget": 60}
KEYVER = "x64key2"      # (integ2, D97) x64key2: the block's 32- and 64-bit symbols are part of its code key
LOCAL_MAX = 4
JOB_PER = 2         # blocks (= slots) per queue job (integ3: was 4; a 4-slot job waits for 4 free slots on one host)


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
    if st == "compile_error":
        return "compile_error", "compile_error"
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
                # (integ2, D97) the symbols too: the code hash leaves the function's own name out, and a member
                # function moved to another class (`owners::SomeClass_2aed60::f` -> `Registry_2aed60::f`, x64t18) can
                # keep its bytes while the checker types its `this` (and the parameters the name spells) by the new
                # declaration: the cached result was the old class's `layout` difference
                out[b["addr"]] = {"key": hashlib.sha1(("%s\0%s\0%s\0%s\0%s" % (KEYVER, h32, h64, s32, s64)).encode()
                                                      ).hexdigest()[:20], "s32": s32, "s64": s64}
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


def _job():
    """Inside a queue job (no git in its workspace): the submit's record (tree_tu.JOB_META), else None. The job's base
    commit is the only REF the gate can take there: its tree is the workspace with the shipped files put back to the
    commit's copies (tree_tu.JOB_REF), and the changed TUs are the shipped ones (tool2)."""
    import tree_tu
    m = tree_tu.job_meta()
    return m if m is not None and not tree_tu.have_git() else None


def rev(ref):
    m = _job()
    if m is not None:
        if ref not in m.get("refs", []):
            raise SystemExit("x64_gate: in a queue job only the base commit (%s) is known, not %s"
                             % (m.get("commit", "?")[:10], ref))
        return m["commit"]
    r = _git("rev-parse", "--verify", ref + "^{commit}")
    if r.returncode:
        raise SystemExit("x64_gate: no commit %s" % ref)
    return r.stdout.strip()


TREE_DIRS = ("src/game", "src/engine", "src/platform/xbox")


def snapshot(commit, d):
    """The tree of COMMIT (include/ and the tree TUs) extracted into D; returns D."""
    os.makedirs(d, exist_ok=True)
    m = _job()
    if m is not None:       # (the workspace, its shipped files back at the commit's copies)
        import tree_tu
        if commit != m["commit"]:
            raise SystemExit("x64_gate: in a queue job only the base commit is known")
        for top in ["include"] + list(TREE_DIRS):
            if not os.path.isdir(os.path.join(ROOT, top)):
                continue
            os.makedirs(os.path.dirname(os.path.join(d, top)), exist_ok=True)
            if subprocess.run(["cp", "-Rc", os.path.join(ROOT, top), os.path.join(d, top)], capture_output=True).returncode:
                shutil.rmtree(os.path.join(d, top), ignore_errors=True)
                shutil.copytree(os.path.join(ROOT, top), os.path.join(d, top))
        for rel in m.get("shipped", []):
            if not rel.startswith(("include/",) + tuple(t + "/" for t in TREE_DIRS)):
                continue
            dst, src = os.path.join(d, rel), os.path.join(ROOT, tree_tu.JOB_REF, rel)
            if os.path.exists(src):
                shutil.copyfile(src, dst)
            elif os.path.exists(dst):
                os.unlink(dst)          # (new in the shipped files)
        return d
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
    m = _job()
    if m is not None:
        files = [f for f in m.get("shipped", []) if f.startswith(("src/", "include/"))]
        if any(f.endswith((".h", ".hpp", ".inl")) for f in files):
            return sorted(os.path.relpath(p, ROOT) for p in tree_tu.tree_tus(ROOT))
        return sorted(f for f in files if f.endswith(".cpp") and f.startswith(tuple(d + "/" for d in TREE_DIRS)))
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


def changed_blocks(ref, head=None, tus=None, jobs=2, workdir=None, baseline_path=None, force=None):
    """The blocks the gate checks: [(addr, rel path, head key record, why changed)], the blocks REF had in those TUs
    that HEAD doesn't, the HEAD-side root, and the key errors."""
    ref_c = rev(ref)
    rels = candidate_tus(ref_c, rev(head) if head else None, tus)
    tmp = workdir or tempfile.mkdtemp(prefix="x64gate-", dir=os.path.join(ROOT, "build"))
    try:
        rroot = snapshot(ref_c, os.path.join(tmp, "ref"))
        hroot = snapshot(rev(head), os.path.join(tmp, "head")) if head else ROOT
        cpc = {} if "calleepost" in os.environ.get("X64_GATE_OFF", "") else callee_post_callers(rroot, hroot)
        rels = sorted(set(rels) | set(cpc.values()))
        rk, e1 = side_keys(rroot, rels, jobs)
        hk, e2 = side_keys(hroot, rels, jobs)
    except BaseException:
        if not workdir:
            shutil.rmtree(tmp, ignore_errors=True)
        raise
    out = []
    same = []
    for a, (rel, h) in sorted(hk.items()):
        r = rk.get(a)
        if r is None:
            why = "new"
        elif h["key"] is None:
            why = "unkeyed (%s)" % h.get("why")
        elif r[1]["key"] != h["key"]:
            why = "code changed" if r[1]["key"] else "keyed now"
        elif a in cpc:
            # (integ9, D165) a direct caller of a return-post block whose post, pins or proof lines changed: its x64 run
            # draws that callee's result (or no longer does), so it runs again with code and AST digest unchanged
            why = "callee post changed"
        elif force and a in force:
            # (integ4, --blocks; lead/rev5) a named block runs although its code and AST digest are REF's: a checker
            # change that fixes a baseline block (a model, not the source) can only leave the baseline this way. The
            # baseline still only shrinks on a fresh equivalent (judge: improved)
            why = "forced (--blocks)"
        else:
            same.append((a, rel, h, r[1]))
            continue
        out.append((a, rel, h, why))
    if "astbase" not in os.environ.get("X64_GATE_OFF", ""):
        # (integ2, D118) a baseline block whose code didn't change but whose run's AST digest did (a data annotation,
        # a view, a HULK_INTO or HULK_RANGE: what the checker generates for it, not its bytes) runs again, so a fix
        # that leaves the code alone can leave the baseline (--update-baseline), and a model change that makes a known
        # block worse is seen
        known = load_baseline(baseline_path or BASELINE).get("blocks", {})
        out += ast_changed(rroot, hroot, [x for x in same if x[0] in known], jobs)
    gone = sorted(set(rk) - set(hk))
    return {"blocks": out, "gone": gone, "tus": len(rels), "head_root": hroot, "tmp": tmp, "rels": rels,
            "ref_root": rroot,
            "errors": dict(list(e1.items()) + list(e2.items())), "keyed": len(hk)}


def _ret_post_digests(root):
    """(integ9, D165) {address: digest} of ROOT's return-post blocks (equiv.ret_post_blocks' regexes): the block's sym,
    post and pre lines and its kind, and its lines in ROOT's proof ledger and revocations."""
    import equiv
    blocks = {}
    for dp, _dn, fns in os.walk(os.path.join(root, "src")):
        for f in fns:
            if not f.endswith(".cpp"):
                continue
            try:
                with open(os.path.join(dp, f), errors="replace") as f_:
                    t_ = f_.read()
            except OSError:
                continue
            if "// post:" not in t_:
                continue
            for blk in re.split(r"\n(?=// 0x[0-9a-f]{8} )", t_):
                m_ = re.match(r"// (0x[0-9a-f]{8}) .*?\(\d+ B\): (matches|equivalent)", blk)
                if not m_:
                    continue
                pl_ = [x.strip() for x in re.findall(r"^\s*//\s*post:\s*(.+?)\s*$", blk, re.M)]
                if not any(equiv._POST_RET_ITEM.search(x) for x in pl_):
                    continue
                dl_ = [x.strip() for x in re.findall(r"^\s*//\s*pre:\s*(.+?)\s*$", blk, re.M)]
                sm_ = re.findall(r"^// sym: .*$", blk, re.M)
                blocks[m_.group(1)] = [os.path.relpath(os.path.join(dp, f), root), m_.group(2), pl_, dl_, sm_]
    out = {}
    for a, v in blocks.items():
        h = hashlib.sha1(json.dumps(v).encode())
        for p_ in ("proof-ledger.jsonl", "proof-revoked.jsonl"):
            try:
                with open(os.path.join(root, "config", p_)) as f_:
                    for l in f_:
                        if '"%s"' % a in l:
                            h.update(l.strip().encode())
            except OSError:
                pass
        out[int(a, 16)] = h.hexdigest()
    return out


def callee_post_callers(rroot, hroot):
    """(integ9, D165) {caller address: HEAD tree TU (relative)} of the functions that call (E8 rel32 in the XBE) a
    return-post block whose digest (_ret_post_digests) differs between REF and HEAD, a block added or dropped too."""
    import bisect
    import equiv
    rd, hd = _ret_post_digests(rroot), _ret_post_digests(hroot)
    changed = sorted(a for a in set(rd) | set(hd) if rd.get(a) != hd.get(a))
    if not changed:
        return {}
    prog = equiv.Program.get()
    starts = sorted(prog.funcs)
    callers = set()
    for t in changed:
        for site in equiv.pre_callers(t):
            try:
                if prog.read(site, 1) != b"\xe8":
                    continue
            except Exception:   # noqa: BLE001
                continue
            i = bisect.bisect_right(starts, site) - 1
            if i >= 0 and site < starts[i] + prog.funcs[starts[i]][0] and starts[i] != t:
                callers.add(starts[i])
    out = {}
    if callers:
        want = {"// 0x%08x " % a: a for a in callers}
        for dp, _dn, fns in os.walk(os.path.join(hroot, "src")):
            for f in fns:
                if not f.endswith(".cpp"):
                    continue
                try:
                    with open(os.path.join(dp, f), errors="replace") as f_:
                        t_ = f_.read()
                except OSError:
                    continue
                for h_, a in want.items():
                    if ("\n" + h_) in t_ or t_.startswith(h_):
                        out[a] = os.path.relpath(os.path.join(dp, f), hroot)
    return out


def _ast_key_inputs():
    """(integ2, D118; rev5) What every run's AST digest depends on besides the TU and its includes: equiv64.py (the
    digest's code) and the inputs D103's gdata_inputs reads (config/data.json, the function list)."""
    if not _AK:
        import equiv
        h = hashlib.sha1(b"astkey1\0")
        for f in (os.path.join(ROOT, "tools", "equiv64.py"), os.path.join(ROOT, "config", "data.json"), equiv.FUNCS_CSV):
            h.update((_sha_file(f) if os.path.exists(f) else "none").encode() + b"\0")
        # (integ9, D165) the calleepost part reads the return-post blocks and their proof lines
        h.update(equiv.ret_post_state().encode() + b"\0")
        _AK.append(h.hexdigest())
    return _AK[0]


_AK = []


def tu_ast_digests(path, syms):
    """(integ2, D118) {32-bit symbol: AST digest or None} of SYMS in the tree TU PATH, cached by the TU's text and path,
    its include closure and _ast_key_inputs() (as tu_keys is): the REF side is parsed once per commit."""
    import equiv64
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
    k = hashlib.sha1((_ast_key_inputs() + "\0" + d + "\0" + rel + "\0" + "\0".join(sorted(syms)) + "\0").encode() +
                     text).hexdigest()[:24]
    cp_ = os.path.join(CACHE, "ast", k + ".json")
    try:
        with open(cp_) as f:
            return json.load(f)
    except (OSError, ValueError):
        pass
    out = equiv64.ast_digests(ap, sorted(syms))    # (a parse that fails raises: nothing cached)
    os.makedirs(os.path.dirname(cp_), exist_ok=True)
    with open(cp_ + ".%d.tmp" % os.getpid(), "w") as f:
        json.dump(out, f)
    os.replace(cp_ + ".%d.tmp" % os.getpid(), cp_)
    return out


def _ast_one(job):
    p, syms = job
    try:
        return p, (tu_ast_digests(p, syms) if os.path.exists(p) else {})
    except Exception:   # noqa: BLE001 - no digest: the block counts as changed
        return p, {}


def ast_changed(rroot, hroot, items, jobs=2):
    """(integ2, D118) [(addr, rel, head key record, "ast changed")] of ITEMS [(addr, rel, head rec, ref rec)] whose
    run's AST digest (equiv64.ast_digests) differs between the REF and HEAD roots. One cached parse of each TU per
    side, over the --jobs pool; a block whose digest can't be computed on either side counts as changed."""
    import multiprocessing
    by = {}
    for a, rel, h, r in items:
        by.setdefault(rel, []).append((a, h, r))
    work = []
    for rel, its in sorted(by.items()):
        work.append((os.path.join(rroot, rel), [x[2].get("s32") for x in its if x[2].get("s32")]))
        work.append((os.path.join(hroot, rel), [x[1].get("s32") for x in its if x[1].get("s32")]))
    if jobs <= 1 or len(work) <= 1:
        res = map(_ast_one, work)
    else:
        pool = multiprocessing.get_context("fork").Pool(jobs)
        res = pool.imap_unordered(_ast_one, work, chunksize=1)
    dig = dict(res)
    out = []
    for rel, its in sorted(by.items()):
        dr_, dh_ = dig.get(os.path.join(rroot, rel), {}), dig.get(os.path.join(hroot, rel), {})
        for a, h, r in its:
            dh, dr = dh_.get(h.get("s32")), dr_.get(r.get("s32"))
            if dh is None or dr is None or dh != dr:
                out.append((a, rel, h, "ast changed"))
    return out


# ------------------------------------------------------------------------------------------------------ runs
_CK = []


def equiv_closure():
    """(integ1, rev5) The top-level names of equiv.py that the 64-bit check can reach: every `equiv.X` equiv64.py (and
    equiv.py's --x64 entry, main) names, and, transitively, every top-level name those definitions use. Names equiv.py
    imports from other modules are covered by those modules' files in the key (compare.py, ...)."""
    import ast
    src = open(os.path.join(ROOT, "tools", "equiv.py")).read()
    tree = ast.parse(src)
    defs = {}
    for node in tree.body:
        if isinstance(node, (ast.FunctionDef, ast.ClassDef)):
            defs[node.name] = ast.get_source_segment(src, node)
        elif isinstance(node, (ast.Assign, ast.AnnAssign)):
            for t in (node.targets if isinstance(node, ast.Assign) else [node.target]):
                for n_ in ast.walk(t):
                    if isinstance(n_, ast.Name):
                        defs[n_.id] = (defs.get(n_.id, "") + "\n" + ast.get_source_segment(src, node))
    roots = set(re.findall(r"\bequiv\.(\w+)", open(os.path.join(ROOT, "tools", "equiv64.py")).read())) | {"main"}
    seen, todo = set(), [r for r in roots if r in defs]
    while todo:
        n_ = todo.pop()
        if n_ in seen:
            continue
        seen.add(n_)
        for x in ast.walk(ast.parse(defs[n_].lstrip()) if defs[n_].lstrip() else ast.parse("")):
            if isinstance(x, ast.Name) and x.id in defs and x.id not in seen:
                todo.append(x.id)
    return seen, {n_: defs[n_] for n_ in seen}, roots


def checker_key():
    """What a cached --x64 result depends on besides the code: equiv64.py and equiv_batch.py whole, the files the check
    compiles with (compare.py, clang_probe.py), the EQ64_OFF switches, and of equiv.py the transitive closure of the
    names equiv64 uses (equiv_closure; integ1, D47 and rev5: the whole file's hash invalidated every result at each
    32-bit checker edit, a hand-kept list missed _x87_value and compile_obj)."""
    if not _CK:
        h = hashlib.sha1(b"x64res3\0" + json.dumps(SETTINGS, sort_keys=True).encode())
        h.update(os.environ.get("EQ64_OFF", "").encode() + b"\0")
        for k_ in ("EQUIV_WORK_PER_SEC", "EQUIV_WALL_CAP", "EQ64_WORK_PER_SEC", "EQ64_RUN_SECONDS"):
            h.update((k_ + "=" + os.environ.get(k_, "")).encode() + b"\0")   # (integ3, rev5 2) budget knobs
        for m in ("equiv64.py", "equiv_batch.py", "compare.py", "clang_probe.py"):
            h.update(_sha_file(os.path.join(ROOT, "tools", m)).encode())
        import equiv
        h.update(b"xbsyms " + equiv.xbsyms_digest().encode() + b"\0")     # (integ2, D101)
        _, srcs, _ = equiv_closure()
        for n_ in sorted(srcs):
            h.update(n_.encode() + b"\0" + srcs[n_].encode())
        _CK.append(h.hexdigest())
    return _CK[0]


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


def types_current(path, recs):
    """(x64t12) Which cached results still hold for PATH's current text: a result carries the fingerprints of the
    layouts its run built (equiv64 Types.fingerprints); a field whose type changed without changing the block's code
    (gen's `f_24` an `int` -> `char**`: the same code key, another heap the checker builds) makes it stale. RECS:
    {addr: cached record}; returns the addresses whose types still agree. One libclang parse of the TU for all of
    them; a record without fingerprints (no checker was built: compile error) depends on the code alone."""
    import equiv64
    # (integ2, D93/F3) the fingerprints of runs that read pointer fields through views are taken with those views,
    # one parse per distinct set of them
    groups = {}
    for a, r in recs.items():
        if r.get("types"):
            groups.setdefault(json.dumps(r.get("field_casts") or []), []).append(a)
    # (integ2; rev5) a record whose run built no layouts (types {}) still had a checker: its AST digest is checked
    # below. One with neither (no checker was built: compile error, an early unsupported) is reused on its code only
    # if it gives no credit; an `equivalent` without a digest runs again
    ok = set(a for a, r in recs.items() if "types" in r and not r["types"])
    # (integ3, rev5) nor a compile_error: it fails the gate now, and one stored before the no-checker rule (store_result)
    # came from another text with the same code (sweep-allocsize's `(unsigned int)sizeof` fix changes no byte)
    ok |= set(a for a, r in recs.items() if "types" not in r and r.get("status") not in ("equivalent", "compile_error"))
    for fc, addrs in groups.items():
        keys = {}
        for a in addrs:
            for k, v in recs[a]["types"].items():
                keys[k] = v.get("k64", k)
        try:
            now = equiv64.type_fingerprints(path, keys, json.loads(fc))
        except Exception:   # noqa: BLE001 - can't parse: run them all
            continue
        for a in addrs:
            if all(now.get(k, {}).get("fp") == v.get("fp") for k, v in recs[a]["types"].items()):
                ok.add(a)
    # (integ2, D97; rev5's review) what the parse gives the run besides bytes and layouts (its declaration, HULK_INTO,
    # the casts that type its objects): a result without that digest, or with another one, runs again
    typed = [a for a in ok if "types" in recs[a]]
    if typed:
        syms = {recs[a].get("symbol32") for a in typed if recs[a].get("symbol32")}
        try:
            dig = equiv64.ast_digests(path, sorted(syms)) if syms else {}
        except Exception:   # noqa: BLE001
            dig = {}
        for a in typed:
            r = recs[a]
            if not r.get("ast") or not r.get("symbol32") or dig.get(r["symbol32"]) != r["ast"]:
                ok.discard(a)
    return ok


def store_result(key, rec):
    if not key or rec.get("status") in (None, "error"):
        return
    if "types" not in rec and "ast" not in rec:
        # (integ2; rev5) no checker was built (a compile error, an early unsupported): the result depends on the TU's
        # text, not only on the block's code, so it is not kept under the code key (another text with the same bytes
        # would inherit it: x64t22's compile_error rows from a working copy, reused for a commit)
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
    if os.environ.get("JOBQ_JOB"):      # (inside a queue job: never submit from a host)
        mode = "local"
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
            # (integ3, recs1) 2 blocks (2 slots) per job: 4-slot gate jobs starved behind 1-slot work in the queue
            return jobq_equiv.run_items(name, items, out, equiv_args(), per=JOB_PER, dirty=not commit, quiet=quiet)
        finally:
            jobq.collect_files, jobq.head_commit, jobq.make_job = orig_cf, orig_hc, orig_mj
    finally:
        if not workdir:
            shutil.rmtree(d, ignore_errors=True)


# ------------------------------------------------------------------------------------------------------ native front ends
# (integ3, x64syn) `equiv.py --x64` compiles x86_64-pc-windows-msvc objects with equiv64's flags (`-w`, no W64, no
# COMMON), so a TU the real native builds refuse could pass the block gate. Every changed TU is also run through the
# native builds' own front ends, -fsyntax-only: macOS arm64 (tools/native_mac.py FRONT, which android-arm64 shares)
# and linux-x64 (tools/native_elf.py flags(), the x86-64 front end). The flags are those modules' own; only the IR
# output (-S -emit-llvm) is swapped for -fsyntax-only. A TU is compiled as the native compile reads it from the
# snapshot (materialize copies it verbatim): -I the tree's include/ (the snapshot's include/ and repo-include/).
SYNTAX_TARGETS = ("macos-arm64", "linux-x64")
SYNTAX_VER = "x64syn4"     # x64syn2: error keys carry the line (rev5 R1); x64syn3: linux-x64 emits IR, RTTI sites;
# x64syn4: the complete object locators' descriptors too (rtti_cols)
SYNTAX_ERRLINES = 4
# (integ3, 9a) the linux-x64 run goes on to LLVM IR (still the front end only: no object), with line tables, so codegen
# errors are seen too and the RTTI type descriptors the code references are read from it (rtti_sites)
RTTI_TARGET = "linux-x64"
SYNTAX_MODE = {"macos-arm64": ["-fsyntax-only"], "linux-x64": ["-S", "-emit-llvm", "-gline-tables-only"]}


def native_front(target):
    """(clang++ argv prefix, front-end flags) of TARGET's native compile, in SYNTAX_MODE[TARGET] (-fsyntax-only, or IR
    for the RTTI scan)."""
    import clang_probe as cp
    if target == "macos-arm64":
        import native_mac
        cxx, front = [cp.tool("clang++")], list(native_mac.FRONT)
    elif target == "linux-x64":
        import native_elf
        cxx, front = list(native_elf.Toolchain(target).cxx), list(native_elf.flags(target)[0])
    else:
        raise ValueError(target)
    front = [f for f in front if f not in ("-S", "-emit-llvm", "-c")] + cp.common_native() + SYNTAX_MODE[target]
    return cxx, front


_SYN_TC = {}


def syntax_toolchain(target):
    """{"cxx", "front", "version"} of TARGET, or {"unavailable": why}: no clang++, or one that can't parse an empty
    TU for the target's front-end triple. Asked once per process."""
    if target not in _SYN_TC:
        try:
            cxx, front = native_front(target)
            if not cxx or not cxx[0] or not os.path.exists(cxx[0]):
                raise RuntimeError("no clang++ for %s (%s)" % (target, cxx and cxx[0]))
            tgt = [f for f in front if f.startswith("--target=")]
            p = subprocess.run(cxx + tgt + ["-x", "c++", "-fsyntax-only", "-"], input="int x;\n", capture_output=True,
                               text=True, timeout=120)
            if p.returncode:
                raise RuntimeError("%s %s: %s" % (cxx[0], " ".join(tgt), (p.stderr.strip().splitlines() or ["?"])[-1]))
            v = subprocess.run(cxx[:1] + ["--version"], capture_output=True, text=True).stdout.splitlines()
            _SYN_TC[target] = {"cxx": cxx, "front": front, "version": (v[0] if v else "?").strip()}
        except Exception as e:      # noqa: BLE001 - a missing or broken toolchain is a row, not a crash
            _SYN_TC[target] = {"unavailable": str(e)[:300]}
    return _SYN_TC[target]


def _errors(stderr, root):
    """The error lines of a clang run (paths relative to ROOT), and [file, line, message] keys for comparing two
    runs (known_errors)."""
    import clang_probe as cp
    lines, keys = [], []
    for l in stderr.splitlines():
        m = cp.DIAG_RE.match(l)
        if not m or m.group(4) not in ("error", "fatal error"):
            continue
        f = m.group(1)
        if os.path.isabs(f) and not os.path.relpath(f, root).startswith(".."):
            f = os.path.relpath(f, root)
        lines.append("%s:%s: %s" % (f, m.group(2), m.group(5)))
        keys.append([f, int(m.group(2)), m.group(5)])
    return lines, keys


def native_syntax(path, target):
    """{"rc", "errors": [first error lines], "keys", "n_errors"} of TARGET's native front end over the tree TU PATH,
    or {"unavailable": why}; for RTTI_TARGET also "rtti": [[file, line, descriptor name]] (rtti_sites) when it
    compiled. Cached by the TU's text and path, its include closure, the target's flags and the
    compiler's version line (a failure is cached too: it gives no credit)."""
    import include_keys
    import tree_tu
    tc = syntax_toolchain(target)
    if "unavailable" in tc:
        return {"unavailable": tc["unavailable"]}
    ap = os.path.abspath(path)
    root = tree_tu.find_root(ap)
    inc = os.path.join(root, "include")
    with open(ap, "rb") as f:
        text = f.read()
    d = include_keys.digest(ap, [inc], root=root, force=["compat/native.h"])
    if d is None:
        import build_tree
        d = "all " + build_tree.include_tree_digest(inc)
    rel = os.path.relpath(ap, root)
    k = hashlib.sha1(("\0".join([SYNTAX_VER, target, tc["version"], repr(tc["front"]), d, rel]) + "\0").encode()
                     + text).hexdigest()[:24]
    cp_ = os.path.join(CACHE, "syntax", k + ".json")
    try:
        with open(cp_) as f:
            r = json.load(f)
        r["_cached"] = True
        return r
    except (OSError, ValueError):
        pass
    # (the native compile's -I snap/include -I snap/repo-include: the first is materialize's copy of the tree's own
    # headers under include/, the second all of include/, so the one include/ resolves every name to the same file)
    cmd = tc["cxx"] + tc["front"] + ["-I" + inc, ap]
    ll = None
    if "-emit-llvm" in tc["front"]:
        os.makedirs(os.path.join(CACHE, "tmp"), exist_ok=True)
        fd, ll = tempfile.mkstemp(suffix=".ll", dir=os.path.join(CACHE, "tmp"))
        os.close(fd)
        cmd += ["-o", ll]
    try:
        try:
            p = subprocess.run(cmd, capture_output=True, text=True, errors="replace", timeout=600, cwd=root)
            rc, err = p.returncode, p.stderr
        except subprocess.TimeoutExpired:
            return {"rc": -1, "errors": ["timeout"], "keys": [["", 0, "timeout"]], "n_errors": 1}     # (not cached)
        sites = cols = None
        if ll and rc == 0:
            with open(ll, errors="replace") as f:
                ir = f.read()
            sites, cols = rtti_sites(ir, root), rtti_cols(ir)
    finally:
        if ll and os.path.exists(ll):
            os.unlink(ll)
    lines, keys = _errors(err, root)
    if rc and not lines:        # (a driver error, a crash: the tail of the output)
        lines = (err.strip().splitlines() or ["exit %d" % rc])[-SYNTAX_ERRLINES:]
        keys = [["", 0, l] for l in lines]
    r = {"rc": rc, "errors": lines[:SYNTAX_ERRLINES], "keys": keys, "n_errors": len(lines)}
    if sites is not None:
        r["rtti"], r["rtti_col"] = sites, cols
    os.makedirs(os.path.dirname(cp_), exist_ok=True)
    with open(cp_ + ".%d.tmp" % os.getpid(), "w") as f:
        json.dump(r, f)
    os.replace(cp_ + ".%d.tmp" % os.getpid(), cp_)
    return r


def changed_files(rroot, hroot, keys):
    """The files of KEYS (paths relative to the roots) whose text differs between RROOT and HROOT, or exists on one
    side only."""
    out = set()
    for f in {k[0] for k in keys if k[0]}:
        a, b = os.path.join(rroot, f), os.path.join(hroot, f)
        if os.path.isabs(f) or not (os.path.exists(a) and os.path.exists(b)) or _sha_file(a) != _sha_file(b):
            out.add(f)
    return out


def known_errors(head, ref, changed):
    """(rev5 R1) Are HEAD's error keys [file, line, message] all REF's, as multisets (no key's count grows)? An error
    in a file the change didn't touch is matched with its line; one in a CHANGED file (lines move) by file and
    message, with counts."""
    def ms(keys):
        return collections.Counter((f, l if f not in changed else None, m) for f, l, m in keys)
    h, r = ms(head), ms(ref)
    return all(r[k] >= n for k, n in h.items())


def syntax_rows(hroot, rels, rroot=None, jobs=2, targets=SYNTAX_TARGETS):
    """One row per (tree TU of RELS under HROOT, target): verdict `ok`, `native_syntax` (fails the gate), `known`
    (fails, but the TU's text is REF's and REF failed with every one of these errors: a header changed and every TU
    is a candidate, the error isn't the change's) or `native_syntax_unavailable` (one row per target, no TU: the
    toolchain is missing; fails the gate). A TU whose text changed (or is new) fails on any error."""
    import concurrent.futures
    import tree_tu
    paths = [r for r in rels if os.path.exists(os.path.join(hroot, r)) and tree_tu.is_tree_tu(os.path.join(hroot, r))]
    rows, live = [], []
    for t in targets:
        tc = syntax_toolchain(t)
        if "unavailable" in tc:
            rows.append({"tu": None, "target": t, "verdict": "native_syntax_unavailable",
                         "errors": [tc["unavailable"]]})
        else:
            live.append(t)
    work = [(r, t) for r in paths for t in live]
    with concurrent.futures.ThreadPoolExecutor(max(1, jobs)) as ex:
        res = dict(zip(work, ex.map(lambda w: native_syntax(os.path.join(hroot, w[0]), w[1]), work)))
    same = set()
    if rroot:
        for r in {w[0] for w in work if res[w]["rc"]}:
            rp = os.path.join(rroot, r)
            if os.path.exists(rp) and _sha_file(rp) == _sha_file(os.path.join(hroot, r)):
                same.add(r)
    for (r, t) in work:
        h = res[(r, t)]
        v = "ok"
        if h["rc"]:
            v = "native_syntax"
            if r in same:
                ref = native_syntax(os.path.join(rroot, r), t)
                if ref.get("rc") and known_errors(h["keys"], ref.get("keys", []),
                                                  changed_files(rroot, hroot, h["keys"])):
                    v = "known"
        rows.append({"tu": r, "target": t, "verdict": v, "errors": h["errors"], "n_errors": h["n_errors"],
                     "cached": bool(h.get("_cached"))})
        if "rtti" in h:
            rows[-1]["rtti"], rows[-1]["rtti_col"] = h["rtti"], h.get("rtti_col", [])
    return rows


# ------------------------------------------------------------------------------------------------------ RTTI names
# (integ3, 9a; find2) A dynamic_cast or typeid compiles to a reference to a ??_R0 type descriptor. Natively the runtime
# (src/platform/sdl/host/rtti_msabi.cpp) compares descriptors by name with the game's own RTTI: the decorated name,
# then the name without the tree's fn_<8 hex> wrapping namespaces. A descriptor that is not the name of one of the
# game's descriptors (a local stand-in `?AVX@fn_ADDR@@`, a Class_<addr> rename, another namespace) makes the cast fail
# natively; the Wine link hides it (tools/wine_link.py native9/native12 redirect clang's ??_R0 onto the game's by leaf
# name or with the address suffix dropped). Every descriptor a function body of a candidate TU references (the
# linux-x64 IR) must be exact; the known ones are config/rtti-baseline.json, which only shrinks.
RTTI_BASELINE = os.path.join(ROOT, "config/rtti-baseline.json")
_R0_REF = re.compile(r'@"?\?\?_R0\.?(\?A[UVTW][^"\s,()]*?)@8"?(?=[\s,)])')
_DBG = re.compile(r"!dbg !(\d+)\s*$")
_MD = re.compile(r"^!(\d+) = (?:distinct )?(.*)$", re.M)


def rtti_sites(ir, root):
    """[[file relative to ROOT, line, descriptor name (`?AVX@ns@@`)]] of every ??_R0 reference in a function body of
    the LLVM IR text IR (a dynamic_cast's source and target, a typeid(T)); the place comes from the instruction's
    debug location (line tables), its scope's file."""
    md = {int(m.group(1)): m.group(2) for m in _MD.finditer(ir)}

    def field(t, k):
        m = re.search(r"\b%s: (!\d+|\d+|\"(?:[^\"\\]|\\.)*\")" % k, t or "")
        return m.group(1) if m else None

    def filename(scope):
        seen = 0
        while scope and seen < 50:
            t = md.get(int(scope[1:]), "")
            f = field(t, "file")
            if f and f.startswith("!"):
                ft = md.get(int(f[1:]), "")
                fn, dn = (field(ft, "filename") or '""')[1:-1], (field(ft, "directory") or '""')[1:-1]
                p = fn if os.path.isabs(fn) else os.path.join(dn, fn)
                p = os.path.normpath(p if os.path.isabs(p) else os.path.join(root, p))
                r = os.path.relpath(p, root)
                return r if not r.startswith("..") else p
            scope = field(t, "scope")
            seen += 1
        return ""

    out = []
    infn = False
    for l in ir.splitlines():
        if l.startswith("define "):
            infn = True
            continue
        if infn and l.startswith("}"):
            infn = False
            continue
        if not infn or "??_R0" not in l:
            continue
        m = _DBG.search(l)
        line, f = 0, ""
        if m:
            loc = md.get(int(m.group(1)), "")
            line = int(field(loc, "line") or 0)
            f = filename(field(loc, "scope"))
        for n in _R0_REF.findall(l):
            out.append([f, line, n])
    return out


_GLOBAL_DEF = re.compile(r'^@"(\?\?_R[1-4][^"]*)" = (.*)$', re.M)
_RTTI_REF = re.compile(r'@"(\?\?_R[0-4][^"]*)"')


def rtti_cols(ir):
    """(rev5 R2) [[owner, descriptor]] per complete object locator (??_R4, COMDAT or not) the IR text IR defines:
    the descriptors reached from it through its class hierarchy (??_R3 -> ??_R2 -> ??_R1 -> ??_R0), its own class's
    first; OWNER is that class's descriptor (the class whose vftable it is). Natively a dynamic_cast or typeid on an
    object reads its vftable's locator, so a non-game name there fails as one at the cast does (rtti_msabi.cpp)."""
    refs = {m.group(1): _RTTI_REF.findall(m.group(2)) for m in _GLOBAL_DEF.finditer(ir)}
    out = []
    for n, rs in sorted(refs.items()):
        if not n.startswith("??_R4"):
            continue
        tds, seen, todo = [], set(), list(rs)
        while todo:
            x = todo.pop(0)
            if x in seen:
                continue
            seen.add(x)
            if x.startswith("??_R0"):
                m = re.match(r"^\?\?_R0\.?(\?A[UVTW].*)@8$", x)
                if m and m.group(1) not in tds:
                    tds.append(m.group(1))
            else:
                todo += refs.get(x, [])
        for td in tds:
            out.append([tds[0], td])
    return out


def unwrap_rtti(n):
    """A descriptor name without the tree's fn_<8 hex> wrapping namespaces, as the native runtime compares it:
    src/platform/sdl/host/rtti_msabi.cpp `unwrapped()` (lines 77-91) drops `fn_` + 8 lowercase hex + `@` only where
    the character before it (in the original name) is `@` (rev5 R1: `?AVX_fn_0123abcd@@` keeps it)."""
    return re.sub(r"(?<=@)fn_[0-9a-f]{8}@", "", n)


_GAME_RTTI = {}


def game_rtti(path=None):
    """{descriptor name `?AVX@ns@@`} of the game's RTTI type descriptors (config/data.json's rtti_td items: every
    descriptor of the XBE, the same RTTI tools/rtti.py recovers for include/gen), and {leaf: names} for hints."""
    path = path or os.path.join(ROOT, "config/data.json")
    if path not in _GAME_RTTI:
        names, leaf = set(), collections.defaultdict(set)
        with open(path) as f:
            items = json.load(f).get("items", [])
        for it in items:
            if it.get("kind") != "rtti_td":
                continue
            m = re.fullmatch(r"\?\?_R0\.(\?A[UVTW].*)@8", it.get("name", ""))
            if m:
                names.add(m.group(1))
                lm = re.match(r"\?A[UVTW]([^@]+)@", m.group(1))
                if lm:
                    leaf[lm.group(1)].add(m.group(1))
        _GAME_RTTI[path] = (names, dict(leaf))
    return _GAME_RTTI[path]


def rtti_hint(n, leaf):
    """The game descriptors a non-exact name probably means: the same leaf, or the leaf without `_<address>`."""
    lm = re.match(r"\?A[UVTW]([^@]+)@", unwrap_rtti(n))
    if not lm:
        return []
    lf = lm.group(1)
    return sorted(leaf.get(lf) or leaf.get(re.sub(r"_[0-9a-f]{5,6}$", "", lf)) or ())


def rtti_groups(root, rel, sites, game, cols=()):
    """{"addr|td": count} of the non-exact sites of the tree TU REL (under ROOT): addr is the block whose lines hold
    the site, `-` for a line of the TU outside every block, or the header's path for a site in a header; for a
    complete object locator's descriptor (COLS, rtti_cols) `col:<owner>`, the class whose vftable it is."""
    import tree_tu
    blocks = tree_tu.scan(os.path.join(root, rel))["blocks"]
    out = collections.Counter()
    for f, line, n in sites:
        if unwrap_rtti(n) in game:
            continue
        if f == rel:
            a = next((b["addr"] for b in blocks if b["lines"][0] <= line <= b["lines"][1]), "-")
        else:
            a = f or "-"
        out["%s|%s" % (a, n)] += 1
    for owner, n in cols:
        if unwrap_rtti(n) not in game:
            out["col:%s|%s" % (owner, n)] += 1
    return dict(out)


SEED_STAMP = {"by": "rtti-seed", "accepted": "seed"}


def parse_rtti_baseline(text, where="config/rtti-baseline.json"):
    """The file's shape -> the gate's: {"sites": {"TU|addr|descriptor": {"count", "by", "accepted"[, "why"]}}, ...}.
    The file (rev5/lead, r3) is {"comment", "seed_why", "total", "tus": {TU: {"addr|descriptor": entry}}}, an entry a
    bare count (seed-stamped: rtti-seed's) or {count, accepted, by, why} (rtti-accept's). The first, flat shape
    (`"sites"`, never committed) is refused."""
    b = json.loads(text)
    if "tus" not in b or "sites" in b:
        raise SystemExit("x64_gate: %s is not in the per-TU shape ({\"tus\": {TU: {...}}}); re-seed it" % where)
    sites = {}
    for tu, ents in b["tus"].items():
        for k, e in ents.items():
            sites["%s|%s" % (tu, k)] = dict(SEED_STAMP, count=e) if isinstance(e, int) else dict(e)
    out = {k: v for k, v in b.items() if k != "tus"}
    out["sites"] = sites
    return out


def load_rtti_baseline(path=None):
    """{"sites": {"TU|addr|descriptor": {"count", "accepted", "by"[, "why"]}}, "total"} of config/rtti-baseline.json
    (parse_rtti_baseline): the non-exact RTTI references known when the check began. Only shrinks: `check
    --update-baseline` lowers an entry to what a fresh scan finds; an entry is added (or its count raised) only by
    `x64_gate.py rtti-accept`."""
    path = path or RTTI_BASELINE
    try:
        with open(path) as f:
            text = f.read()
    except OSError:
        return {"sites": {}, "total": 0, "missing": True}
    return parse_rtti_baseline(text, path)


def rtti_counts(b):
    """(sites, entries) of a baseline in the gate's shape."""
    return sum(e.get("count", 1) for e in b.get("sites", {}).values()), len(b.get("sites", {}))


def write_rtti_baseline(b, path=None):
    """The gate's shape -> the file's (parse_rtti_baseline), one TU per block, keys sorted, one entry per line (a fix
    diffs as a few lines in one place). A seed-stamped entry is written as its bare count."""
    path = path or RTTI_BASELINE
    b.pop("missing", None)
    tus = {}
    for k, e in b.get("sites", {}).items():
        tu, rest = k.split("|", 1)
        tus.setdefault(tu, {})[rest] = e["count"] if e.get("by") == "rtti-seed" else \
            {x: e[x] for x in ("count", "accepted", "by", "why") if x in e}
    b["total"] = rtti_counts(b)[0]
    lines = ["{"]
    for k in ("comment", "seed_why", "total"):
        if k in b:
            lines.append(" %s: %s," % (json.dumps(k), json.dumps(b[k])))
    lines.append(' "tus": {')
    tl = sorted(tus)
    for i, tu in enumerate(tl):
        lines.append("  %s: {" % json.dumps(tu))
        el = sorted(tus[tu])
        for j, k in enumerate(el):
            lines.append("   %s: %s%s" % (json.dumps(k), json.dumps(tus[tu][k]), "," if j + 1 < len(el) else ""))
        lines.append("  }%s" % ("," if i + 1 < len(tl) else ""))
    lines.append(" }")
    lines.append("}")
    with open(path + ".tmp", "w") as f:
        f.write("\n".join(lines) + "\n")
    os.replace(path + ".tmp", path)


def rtti_baseline_at(ref):
    """The rtti baseline of commit REF ({} with "missing" when it had none). In a queue job the base commit's copy is
    JOB_REF's (when shipped) or the workspace's."""
    m = _job()
    if m is not None:
        import tree_tu
        rel = os.path.relpath(RTTI_BASELINE, ROOT)
        p = os.path.join(ROOT, tree_tu.JOB_REF, rel) if rel in m.get("shipped", []) else RTTI_BASELINE
        if rel in m.get("shipped", []) and not os.path.exists(p):
            return {"sites": {}, "missing": True}
        return load_rtti_baseline(p)
    # (fail closed, as tree_tu.file_at_ref: REF is a verified commit (rev), an absent file is "missing", any other git
    # failure stops the gate rather than reading as "REF had no list")
    rel = os.path.relpath(RTTI_BASELINE, ROOT)
    r = _git("ls-tree", "--name-only", ref, "--", ":(top)" + rel)
    if r.returncode:
        raise SystemExit("x64_gate: git ls-tree %s: %s" % (ref, r.stderr.strip()[:200]))
    if not r.stdout.strip():
        return {"sites": {}, "missing": True}
    r = _git("show", "%s:%s" % (ref, rel))
    if r.returncode:
        raise SystemExit("x64_gate: git show %s:%s: %s" % (ref, rel, r.stderr.strip()[:200]))
    return parse_rtti_baseline(r.stdout, "%s:%s" % (ref, rel))


def rtti_baseline_growth(before, now):
    """["key"] of entries NOW holds that BEFORE didn't, or with a higher count, unless the entry's own stamp says
    `by: rtti-accept` and the stamp is new (BEFORE had another), or `by: rtti-seed` when BEFORE had no list at all;
    ["(deleted)"] when BEFORE had the list and NOW doesn't."""
    if not before.get("missing") and now.get("missing"):
        return ["(deleted)"]
    out = []
    for k, e in now.get("sites", {}).items():
        o = before.get("sites", {}).get(k) or {}
        if o and o.get("count", 1) >= e.get("count", 1):
            continue
        if e.get("by") == "rtti-accept" and e.get("accepted") and \
                (not o or (o.get("by"), o.get("accepted")) != (e.get("by"), e.get("accepted"))):
            continue
        if e.get("by") == "rtti-seed" and e.get("accepted") and before.get("missing"):
            continue
        out.append(k)
    return out


def rtti_rows(native, base, root, game_leaf=None):
    """The RTTI rows of the RTTI_TARGET rows of syntax_rows: `rtti_inexact` (a non-exact descriptor the baseline
    doesn't hold that often: fails), `rtti_known` (in the baseline), `rtti_fixed` (the baseline holds more than the
    TU has now: --update-baseline lowers it); a complete object locator's descriptor (addr `col:<owner>`) has the
    same three as `rtti_col_*`. A TU that didn't compile has no scan (its native_syntax row fails)."""
    names, leaf = game_rtti() if game_leaf is None else game_leaf
    sites = base.get("sites", {})
    rows = []
    for r in native:
        if r.get("target") != RTTI_TARGET or "rtti" not in r or not r.get("tu"):
            continue
        tu = r["tu"]
        now = rtti_groups(root, tu, r["rtti"], names, r.get("rtti_col", []))
        old = {k.split("|", 1)[1]: e.get("count", 1) for k, e in sites.items() if k.split("|", 1)[0] == tu}
        for g_ in sorted(set(now) | set(old)):
            n, b = now.get(g_, 0), old.get(g_, 0)
            addr, td = g_.split("|", 1)
            v = "rtti_inexact" if n > b else "rtti_fixed" if n < b else "rtti_known"
            if addr.startswith("col:"):
                v = v.replace("rtti_", "rtti_col_")
            rows.append({"tu": tu, "addr": addr, "td": td, "count": n, "baseline": b, "verdict": v,
                         "game": rtti_hint(td, leaf)})
    return rows


# ------------------------------------------------------------------------------------------------------ the gate
def judge(blocks, results, baseline):
    """Per checked block: its status class, gate class and verdict: new (a failure), known (in the baseline),
    improved (in the baseline, now equivalent: removable), known-unclear (in the baseline, now another class), unchecked (no result: a failure too), ok, other (reported)."""
    known = baseline.get("blocks", {})
    out = []
    for a, rel, h, why in blocks:
        r = results.get(a)
        if r is not None and r.get("eq64_off"):
            r = None        # (integ1, rev5) a run with EQ64_OFF switches vouches for nothing
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
         baseline_path=BASELINE, prio=0, rtti_path=None, force=None):
    """Run the gate: {"rows": judge's rows, "summary", "gone", "errors", "failed": bool}."""
    base = load_baseline(baseline_path)
    ch = changed_blocks(ref, head, tus, jobs, workdir, baseline_path, force=force)
    if force:
        missing_ = sorted(set(force) - {x[0] for x in ch["blocks"]})
        if missing_:
            raise SystemExit("x64_gate: --blocks %s: not in the keyed TUs (pass their TUs with --tus)" % ", ".join(missing_))
    try:
        results, todo, hits = {}, [], {}
        for a, rel, h, why in ch["blocks"]:
            c = cached_result(h.get("key"))
            if c is not None:
                hits.setdefault(rel, {})[a] = c
            else:
                todo.append((a, os.path.join(ch["head_root"], rel)))
        stale = 0
        for rel, recs in sorted(hits.items()):
            p = os.path.join(ch["head_root"], rel)
            good = types_current(p, recs)
            for a, c in recs.items():
                if a in good:
                    c["_cached"] = True
                    results[a] = c
                else:
                    stale += 1
                    todo.append((a, p))
        if stale and not quiet:
            print("x64_gate: %d cached results re-run: a type they used changed" % stale, file=sys.stderr, flush=True)
        if todo and not quiet:
            print("x64_gate: %d changed blocks, %d cached, %d to run (%s)" % (len(ch["blocks"]), len(ch["blocks"]) - len(todo),
                                                                          len(todo), mode), file=sys.stderr, flush=True)
        fresh = run_blocks(todo, mode, jobs, name, rev(head) if head else None, quiet=quiet, prio=prio)
        lost = [it for it in todo if it[0] not in fresh]
        if lost and "noretry" not in os.environ.get("X64_GATE_OFF", ""):
            # (integ1, D47) a block the batch gave no result for (a job that died, a lost record: gx3's 6 ??_G came out
            # equivalent on a re-run) is run once more before it counts as `unchecked`
            if not quiet:
                print("x64_gate: %d blocks without a result, run again" % len(lost), file=sys.stderr, flush=True)
            again = run_blocks(lost, mode, jobs, name + "-retry", rev(head) if head else None, quiet=quiet, prio=prio)
            fresh.update(again)
        keyof = {a: h.get("key") for a, rel, h, why in ch["blocks"]}
        for a, r in fresh.items():
            r = {k: v for k, v in r.items() if k not in ("src", "host")}
            store_result(keyof.get(a), r)
            results[a] = r
        # (integ3, x64syn) the changed TUs through the native builds' front ends (native_syntax); X64_GATE_OFF=native
        # leaves it out (diagnosis only: the summary says so)
        native = None
        if "native" not in os.environ.get("X64_GATE_OFF", ""):
            native = syntax_rows(ch["head_root"], ch.get("rels", []), ch.get("ref_root"), jobs)
        # (integ3, 9a) the RTTI descriptors of the changed TUs (the linux-x64 IR) against the game's names and
        # config/rtti-baseline.json, and the baseline against REF's (it grows only by rtti-accept)
        rtti = None
        if native is not None and "rtti" not in os.environ.get("X64_GATE_OFF", ""):
            rbase = rtti_baseline_at(rev(head)) if head else load_rtti_baseline(rtti_path)
            rtti = {"rows": rtti_rows(native, rbase, ch["head_root"]),
                    "grew": rtti_baseline_growth(rtti_baseline_at(rev(ref)), rbase),
                    "total": rtti_counts(rbase)[0], "entries": rtti_counts(rbase)[1],
                    "missing": bool(rbase.get("missing"))}
            for r in native:
                r.pop("rtti", None)
                r.pop("rtti_col", None)
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
    if force:
        summary["forced"] = sorted(force)      # (integ4, --blocks; rev5) how a baseline drop was reached
        if not quiet:
            print("x64_gate: forced: %d blocks (%s)" % (len(force), " ".join(sorted(force))))
    if "refanc" in os.environ.get("X64_GATE_OFF", ""):
        summary["refanc"] = "off (X64_GATE_OFF=refanc: development only, not citable)"
    if native is None:
        summary["native_syntax"] = "off (X64_GATE_OFF=native)"
        native = []
    else:
        nv = collections.Counter(r["verdict"] for r in native)
        summary["native_syntax"] = {"tus": len({r["tu"] for r in native if r["tu"]}), "targets": list(SYNTAX_TARGETS),
                                    "verdicts": dict(sorted(nv.items())),
                                    "cached": sum(bool(r.get("cached")) for r in native),
                                    "unavailable": sorted(r["target"] for r in native
                                                          if r["verdict"] == "native_syntax_unavailable")}
    if rtti is None:
        summary["rtti"] = "off (X64_GATE_OFF=%s)" % ("native" if not native else "rtti")
        rtti = {"rows": [], "grew": []}
    else:
        rv = collections.Counter(r["verdict"] for r in rtti["rows"])
        summary["rtti"] = {"verdicts": dict(sorted(rv.items())), "baseline_grew": rtti["grew"][:50],
                           "sites_inexact": sum(r["count"] for r in rtti["rows"])}
        summary["rtti_baseline"] = rtti["total"] if not rtti["missing"] else "missing"
        summary["rtti_baseline_entries"] = rtti["entries"] if not rtti["missing"] else "missing"
    failed = bool(vs.get("new") or vs.get("unchecked") or ch["errors"] or
                  any(r["verdict"] in ("native_syntax", "native_syntax_unavailable") for r in native) or
                  any(r["verdict"] in ("rtti_inexact", "rtti_col_inexact") for r in rtti["rows"]) or rtti["grew"])
    return {"rows": rows, "summary": summary, "gone": ch["gone"], "errors": ch["errors"], "failed": failed,
            "native": native, "rtti": rtti["rows"], "rtti_grew": rtti["grew"]}


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


def update_rtti_baseline(res, b):
    """(integ3, 9a) The RTTI ratchet: lower each entry the fresh scan found fewer sites for (rtti_fixed), drop it at
    0. Returns the changed keys."""
    out = []
    for r in res.get("rtti", []):
        if r["verdict"] not in ("rtti_fixed", "rtti_col_fixed"):
            continue
        k = "%s|%s|%s" % (r["tu"], r["addr"], r["td"])
        if k not in b["sites"]:
            continue
        if r["count"]:
            b["sites"][k]["count"] = r["count"]
        else:
            del b["sites"][k]
        out.append(k)
    return out


def rtti_scan(root, rels, jobs=2):
    """{"TU|addr|descriptor": count} of the non-exact RTTI sites of the tree TUs RELS under ROOT, and the TUs that
    didn't compile for RTTI_TARGET (their sites are unknown)."""
    rows = syntax_rows(root, rels, None, jobs, targets=(RTTI_TARGET,))
    names, _ = game_rtti()
    out, bad = {}, []
    for r in rows:
        if r["verdict"] == "native_syntax_unavailable":
            raise SystemExit("x64_gate: %s toolchain unavailable: %s" % (RTTI_TARGET, r["errors"][0]))
        if "rtti" not in r:
            bad.append(r["tu"])
            continue
        for g_, n in rtti_groups(root, r["tu"], r["rtti"], names, r.get("rtti_col", [])).items():
            out["%s|%s" % (r["tu"], g_)] = n
    return out, bad


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
    for r in sorted(res.get("native", []), key=lambda r: (r["verdict"] != "native_syntax_unavailable",
                                                          r["verdict"] != "native_syntax", r["tu"] or "", r["target"])):
        if r["verdict"] == "ok":
            continue
        if r["verdict"] == "native_syntax_unavailable":
            lines.append("NATIVE_SYNTAX_UNAVAILABLE %s: %s" % (r["target"], r["errors"][0] if r["errors"] else ""))
            continue
        lines.append("%-13s %-11s %s (%d errors)" % ("NATIVE_SYNTAX" if r["verdict"] == "native_syntax" else
                                                     "native-known", r["target"], r["tu"], r.get("n_errors", 0)))
        for e in r["errors"][:SYNTAX_ERRLINES if r["verdict"] == "native_syntax" else 1]:
            lines.append("    " + e[:200])
    for r in sorted(res.get("rtti", []), key=lambda r: (not r["verdict"].endswith("_inexact"), r["tu"], r["addr"])):
        if r["verdict"] in ("rtti_known", "rtti_col_known"):
            continue
        lines.append("%-13s %s %s %s (%d sites, baseline %d)%s" % (
            r["verdict"].upper() if r["verdict"].endswith("_inexact") else r["verdict"], r["tu"], r["addr"], r["td"],
            r["count"], r["baseline"], ("  game: " + ", ".join(r["game"][:3])) if r["game"] else ""))
    for k in res.get("rtti_grew", []):
        lines.append("RTTI_BASELINE_GREW %s (not by rtti-accept)" % k)
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
    p.add_argument("--blocks", metavar="ADDR,...", help="(integ4) also run these blocks of the keyed TUs though their code "
                   "and AST digest are REF's (a checker change); with --update-baseline a fresh equivalent leaves the "
                   "baseline")
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
    p.add_argument("--head-only", action="store_true", help="as a queue job: gate the commit (plus what is shipped) on "
                   "purpose, though the checkout has unshipped edits the TUs read (tree_tu.submit_guard)")
    p = sub.add_parser("accept", help="add a block to the baseline, with the reason")
    p.add_argument("addr")
    p.add_argument("--why", required=True)
    p.add_argument("--class", dest="cls", help="its gate class (default: the last gate result for its current code)")
    p.add_argument("--tu", help="its TU (default: found by address)")
    p.add_argument("--baseline", default=BASELINE)
    p = sub.add_parser("rtti-accept", help="(integ3, 9a) list a TU's non-exact RTTI descriptor in "
                       "config/rtti-baseline.json, with a reason")
    p.add_argument("tu")
    p.add_argument("addr", help="the block holding the site, `-` (outside every block) or the header's path")
    p.add_argument("td", help="the descriptor name as compiled (`?AVX@fn_0012abcd@@`)")
    p.add_argument("--why", required=True)
    p.add_argument("--rtti-baseline", default=None)
    p = sub.add_parser("rtti-seed", help="(integ3, 9a) seed config/rtti-baseline.json with every non-exact RTTI "
                       "site of the tree (once, when the check begins)")
    p.add_argument("--why", required=True)
    p.add_argument("--tus", metavar="FILE", help="only these TUs (default: every tree TU)")
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--rtti-baseline", default=None)
    p = sub.add_parser("keys", help="the code keys of TUs")
    p.add_argument("tus", nargs="+")
    p = sub.add_parser("baseline", help="the baseline's counts")
    p.add_argument("--baseline", default=BASELINE)
    a = ap.parse_args(argv)

    if a.cmd in ("rtti-accept", "rtti-seed"):
        if not (a.why or "").strip():
            raise SystemExit("x64_gate %s: --why must give a reason" % a.cmd)
        now = datetime.datetime.now().isoformat(timespec="seconds")
        if a.cmd == "rtti-seed":
            import tree_tu
            if os.path.exists(a.rtti_baseline or RTTI_BASELINE):
                raise SystemExit("x64_gate rtti-seed: the baseline exists (it only shrinks; add with rtti-accept)")
            rels = ([l.strip() for l in open(a.tus) if l.strip()] if a.tus else
                    sorted(os.path.relpath(p_, ROOT) for p_ in tree_tu.tree_tus(ROOT)))
            found, bad = rtti_scan(ROOT, rels, a.jobs)
            if bad:
                raise SystemExit("x64_gate rtti-seed: %d TUs don't compile for %s (fix or seed later): %s"
                                 % (len(bad), RTTI_TARGET, ", ".join(bad[:10])))
            b = {"comment": "integ3 9a: RTTI type descriptors referenced by the tree's code whose names are not the "
                            "game's (native dynamic_cast/typeid fail on them). Only shrinks (x64_gate.py check "
                            "--update-baseline lowers; rtti-accept adds, with a reason).",
                 "seed_why": a.why.strip(),
                 "sites": {k: dict(SEED_STAMP, count=n) for k, n in found.items()}}
            write_rtti_baseline(b, a.rtti_baseline)
            print("rtti-seed: %d entries, %d sites, %d TUs" % (len(b["sites"]), b["total"],
                                                                len({k.split("|")[0] for k in b["sites"]})))
            return 0
        tu = os.path.relpath(a.tu if os.path.isabs(a.tu) else os.path.join(ROOT, a.tu), ROOT)
        found, bad = rtti_scan(ROOT, [tu], 1)
        if bad:
            raise SystemExit("x64_gate rtti-accept: %s doesn't compile for %s" % (tu, RTTI_TARGET))
        k = "%s|%s|%s" % (tu, a.addr if a.addr == "-" or not re.match(r"^0x[0-9a-f]+$", a.addr, re.I)
                          else "0x%08x" % int(a.addr, 16), a.td)
        if k not in found:
            raise SystemExit("x64_gate rtti-accept: no non-exact site %s now (sites: %s)"
                             % (k, ", ".join(sorted(found)) or "none"))
        b = load_rtti_baseline(a.rtti_baseline)
        if b.get("missing"):
            b = {"comment": "integ3 9a: see x64_gate.py rtti-seed", "sites": {}}
        if b["sites"].get(k, {}).get("count", 0) >= found[k]:
            raise SystemExit("x64_gate rtti-accept: %s is in the baseline already (%d)" % (k, found[k]))
        b["sites"][k] = {"count": found[k], "accepted": now, "by": "rtti-accept", "why": a.why.strip()}
        write_rtti_baseline(b, a.rtti_baseline)
        print("accepted %s x%d" % (k, found[k]))
        return 0
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
            if r and r.get("eq64_off"):
                raise SystemExit("x64_gate accept: the cached result for %s was run with EQ64_OFF=%s: re-run without "
                                 "switches" % (addr, ",".join(r["eq64_off"])))
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
    if a.head and _job() is None and "refanc" not in os.environ.get("X64_GATE_OFF", ""):
        # (integ4, item 5) --head COMMIT is gated against REF: REF must be an ancestor of COMMIT. A side commit made on an
        # older base checked against the shared checkout's newer HEAD read the newer commit's ratchets (the RTTI and x64
        # baselines lowered by other lanes) as growth (fix126's 3493a871c against 9727ae393): pass --changed-since BASE
        r_ = _git("merge-base", "--is-ancestor", rev(a.changed_since), rev(a.head))
        if r_.returncode:
            mb_ = _git("merge-base", rev(a.changed_since), rev(a.head)).stdout.strip()
            raise SystemExit("x64_gate: --changed-since %s is not an ancestor of --head %s: gate the commit against its own "
                             "base: --changed-since %s (git merge-base %s %s)" % (a.changed_since, a.head, mb_[:12] or "?",
                                                                                 a.changed_since, a.head))
    force = {"0x%08x" % int(x, 16) for x in a.blocks.split(",") if x.strip()} if a.blocks else None
    if force and not tus:
        raise SystemExit("x64_gate: --blocks needs --tus (the TUs that hold them)")
    res = gate(a.changed_since, a.head, tus, a.mode or "auto", a.jobs, a.name, quiet=a.json, baseline_path=a.baseline,
               prio=a.prio, force=force)
    import tree_tu
    if tree_tu.job_meta() is not None:      # (D10: what the job checked against the checkout's files at submit)
        cand = candidate_tus(rev(a.changed_since), rev(a.head) if a.head else None, tus)
        paths = [os.path.join(ROOT, r) for r in cand if os.path.exists(os.path.join(ROOT, r))]
        res["summary"]["inputs_vs_local"] = tree_tu.inputs_vs_local(
            "check", (argv if argv is not None else sys.argv[1:])[1:], tree_tu.inputs_digest(paths) if paths else {}, tool="x64_gate")
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
        if not a.head:
            rb = load_rtti_baseline()
            ch_ = update_rtti_baseline(res, rb)
            if ch_:
                write_rtti_baseline(rb)
            res["summary"]["rtti_baseline_lowered"] = ch_
        else:
            # (integ3) --head: the rows are against COMMIT's baseline, so COMMIT's copy is lowered; it is written over
            # the working tree's only when that copy is COMMIT's own (a dirty or other copy is refused, not merged)
            hd_ = rev(a.head)
            rb = rtti_baseline_at(hd_)
            if not rb.get("missing"):
                ch_ = update_rtti_baseline(res, rb)
                if ch_:
                    rel_ = os.path.relpath(RTTI_BASELINE, ROOT)
                    r_ = _git("show", "%s:%s" % (hd_, rel_))
                    try:
                        with open(RTTI_BASELINE) as f_:
                            cur_ = f_.read()
                    except OSError:
                        cur_ = None
                    if r_.returncode or cur_ != r_.stdout:
                        raise SystemExit("x64_gate: --update-baseline --head: %s differs from %s's copy; not written "
                                         "(restore it to %s's or run without --head)" % (rel_, hd_[:10], hd_[:10]))
                    write_rtti_baseline(rb)
                res["summary"]["rtti_baseline_lowered"] = ch_
    print(json.dumps({"summary": res["summary"], "failed": res["failed"],
                      "new": [r for r in res["rows"] if r["verdict"] in ("new", "unchecked")],
                      "triage": [r for r in res["rows"] if r["verdict"] == "triage"],
                      "native_syntax": [r for r in res.get("native", []) if r["verdict"] != "ok"],
                      "rtti": [r for r in res.get("rtti", []) if r["verdict"] not in ("rtti_known", "rtti_col_known")],
                      "rtti_grew": res.get("rtti_grew", [])}, indent=1)
          if a.json else render(res))
    return 1 if res["failed"] else 0


if __name__ == "__main__":
    sys.exit(main())
