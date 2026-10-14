#!/usr/bin/env python3
"""Verification build of the generated source tree (build/tree/, see tools/gen_tree.py).

  build/venv/bin/python tools/build_tree.py              # generate, compile, fall back, re-verify, report
  build/venv/bin/python tools/build_tree.py --jobs 4     # compiler processes (default 4; the box is shared)
  build/venv/bin/python tools/build_tree.py --rounds 8   # max fallback rounds
  build/venv/bin/python tools/build_tree.py --only src/global/CAction.cpp   # one TU, current state

Steps:
  1. Generate the tree from an empty fallback state (build/tree/state.json).
  2. Compile every TU with MSVC 7.1 under wibo, with tools/compare.py's flags (the defaults plus the TU's
     `// cl-flags:` line, which gen_tree.py writes for TUs of functions that need other flags) and
     `/I build/tree/include`. Objects are cached by content in build/tree-cache/obj/.
  3. Blame each compile error on what produced the line: a merged function's definition -> wrap that
     function; a TU-local shared declaration -> wrap the functions that use it; a header declaration ->
     keep that symbol out of headers; a wrapped function -> isolate it in its own TU. Regenerate and
     recompile until nothing new is blamed.
  4. Re-verify. matches/: the function's bytes in the merged object, compared with the XBE by
     compare.py's diff (relocations masked). equivalent/: compile check (the function's symbol exists).
     A match that stops matching is recompiled standalone to tell regressions from functions that do
     not match on their own either.
  5. Write build/tree/report.json and print a summary.
"""
import argparse
import collections
import hashlib
import json
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import compare  # noqa: E402
import gen_tree  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = gen_tree.ROOT
TREE = gen_tree.TREE
CACHE = os.path.join(ROOT, "build/tree-cache")
OBJ_CACHE = os.path.join(CACHE, "obj")
INCLUDE_DIR = os.path.join(TREE, "include")
ERR_RE = re.compile(r"^(.+?)\((\d+)\) : (?:fatal )?error (C\d+): (.*)$")


# ---------------------------------------------------------------------------------------------
# Compiling
def compile_tu(path, extra_inc=True):
    """Compile build/tree/<path> (cached by content). Returns (obj path or None, [error lines], log)."""
    src = os.path.join(TREE, path)
    text = open(src, "rb").read()
    incs = b""
    if extra_inc and os.path.isdir(INCLUDE_DIR):
        for name in sorted(_headers_used(text.decode("latin1"))):
            hp = os.path.join(INCLUDE_DIR, name)
            if os.path.exists(hp):
                incs += open(hp, "rb").read()
                # common.h comes in through the directory headers
                if name != "common.h" and os.path.exists(os.path.join(INCLUDE_DIR, "common.h")):
                    incs += open(os.path.join(INCLUDE_DIR, "common.h"), "rb").read()
    flags = compare.DEFAULT_FLAGS + compare.file_flags(src)
    h = hashlib.sha1(text + incs + repr(flags).encode()).hexdigest()[:20]
    os.makedirs(OBJ_CACHE, exist_ok=True)
    obj = os.path.join(OBJ_CACHE, h + ".obj")
    log = os.path.join(OBJ_CACHE, h + ".log")
    if os.path.exists(obj):
        return obj, [], ""
    if os.path.exists(log):
        out = open(log).read()
        return None, parse_errors(out), out
    src_dir, name = os.path.split(src)
    inc = os.path.relpath(INCLUDE_DIR, src_dir)
    env = dict(os.environ, INCLUDE=os.path.join(compare.MSVC, "Include") + ";" + os.path.join(ROOT, "include"))
    tmp = obj + ".%d.tmp" % os.getpid()
    cmd = [compare.WIBO, os.path.join(compare.MSVC, "Bin/cl.exe")] + flags + ["/I" + inc, "/Fo" + tmp, name]
    try:
        r = subprocess.run(cmd, env=env, capture_output=True, text=True, cwd=src_dir, timeout=600,
                           errors="replace")
        out = r.stdout + r.stderr
        ok = r.returncode == 0 and os.path.exists(tmp)
    except subprocess.TimeoutExpired:
        out, ok = "%s(1) : error C9999: compiler timed out" % name, False
    if ok:
        os.replace(tmp, obj)
        return obj, [], out
    if os.path.exists(tmp):
        os.unlink(tmp)
    with open(log, "w") as f:
        f.write(out)
    errs = parse_errors(out)
    if not errs:
        errs = [(name, 1, "C0000", out.strip().splitlines()[-1] if out.strip() else "unknown failure")]
    return None, errs, out


def _headers_used(text):
    return re.findall(r'^#include "([^"]+)"', text, re.M)


def parse_errors(out):
    errs = []
    for line in out.splitlines():
        m = ERR_RE.match(line.strip())
        if m:
            errs.append((m.group(1).replace("\\", "/"), int(m.group(2)), m.group(3), m.group(4)))
    return errs


def compile_all(paths, jobs):
    with ThreadPoolExecutor(jobs) as ex:
        res = list(ex.map(compile_tu, paths))
    return dict(zip(paths, res))


# ---------------------------------------------------------------------------------------------
# Blame
def blame(manifest, results, state):
    """Turn compile errors into fallback decisions. Returns number of new decisions."""
    new = 0
    header_spans = manifest["headers"]
    for rec in manifest["tus"]:
        obj, errs, _ = results[rec["path"]]
        if obj is not None or not errs:
            continue
        tu_name = os.path.basename(rec["path"])
        acted = False
        for fname, line, code, msg in errs:
            why = "compile error %s: %s" % (code, msg[:120])
            if fname.endswith(".h"):
                hname = next((h for h in header_spans if fname.endswith(h)), None)
                if hname is None:
                    continue
                for s, e, key, norm in header_spans[hname]:
                    if s <= line <= e:
                        k = tuple(key)
                        if k not in state["local_only"]:
                            state["local_only"].add(k)
                            new += 1
                        acted = True
                continue
            if os.path.basename(fname) != tu_name:
                continue
            for s, e, key, norm, users in rec["locals"]:
                if s <= line <= e:
                    for a in users:
                        if a not in state["wrap"]:
                            state["wrap"][a] = "compile error in a shared declaration (%s)" % code
                            new += 1
                    acted = True
            for b in rec["blocks"]:
                s, e = b["lines"]
                if s <= line <= e:
                    a = int(b["addr"], 16)
                    if b["mode"] == "merged" and a not in state["wrap"]:
                        state["wrap"][a] = why
                        new += 1
                    elif b["mode"] == "wrapped" and a not in state["isolate"]:
                        state["isolate"][a] = why
                        new += 1
                    acted = True
        if not acted:
            # nothing attributable: wrap every merged function of this TU
            for b in rec["blocks"]:
                a = int(b["addr"], 16)
                if b["mode"] == "merged" and a not in state["wrap"]:
                    state["wrap"][a] = "unattributed compile error in TU"
                    new += 1
    return new


# ---------------------------------------------------------------------------------------------
# Verification
class Verifier:
    def __init__(self):
        self.xbe = Xbe(compare.XBE_PATH)
        self.funcs = gen_tree.load_functions()
        self.coffs = {}

    def target(self, addr):
        size, _ = self.funcs[addr]
        o = self.xbe.offset(addr)
        return self.xbe.data[o:o + size]

    def coff(self, obj):
        c = self.coffs.get(obj)
        if c is None:
            c = self.coffs[obj] = compare.Coff(obj)
        return c

    def candidates(self, coff, block, claimed):
        """Function symbols in the object that can be this block's function."""
        syms = coff.function_symbols()
        if block["mode"] == "isolated":
            return syms, "all"
        tag = "@fn_%s@" % block["addr"][2:]
        if block["mode"] == "wrapped":
            c = [s for s in syms if tag in s[0]]
            plain = block.get("cnames", [])
            c += [s for s in syms if s[0] in plain or re.sub(r"@\d+$", "", s[0]) in plain]
            return c, "namespace"
        pre = block.get("prefixes", [])
        cn = set(block.get("cnames", []))
        c = [s for s in syms if any(s[0].startswith(p) for p in pre) or s[0] in cn
             or re.sub(r"@\d+$", "", s[0]) in cn]
        if c:
            return c, "name"
        return [s for s in syms if s[0] not in claimed and "@fn_" not in s[0]], "loose"

    def check(self, obj, block, claimed):
        r = self._check(obj, block, claimed)
        if r["status"] != "match" and block["mode"] == "merged" and r.get("how") == "name":
            # the function can be one the compiler generated from the definition (a thunk, a deleting
            # destructor): try every unclaimed symbol of the TU
            r2 = self._check(obj, dict(block, prefixes=[], cnames=[]), claimed)
            if r2["status"] == "match":
                return r2
        return r

    def _check(self, obj, block, claimed):
        addr = int(block["addr"], 16)
        coff = self.coff(obj)
        cands, how = self.candidates(coff, block, claimed)
        if not cands:
            return {"status": "no_function", "how": how}
        target = self.target(addr)
        best = None
        for sym in cands:
            name, ours, mask = coff.function(sym)
            d = compare.diff(target, compare.strip_padding(ours), mask)
            key = (d["exact"], d["matched"] / d["total"], -abs(d["target_bytes"] - d["our_bytes"]))
            if best is None or key > best[0]:
                best = (key, name, d)
            if d["exact"]:
                break
        (_, score, _), name, d = best
        return {"status": "match" if d["exact"] else "diff", "symbol": name, "how": how,
                "score": round(d["matched"] / d["total"], 3), "rows": d["rows"] if not d["exact"] else None}


MANGLE_OPS = {"operatornew": "??2", "operatordelete": "??3", "operator=": "??4", "operator==": "??8",
              "operator!=": "??9", "operator[]": "??A", "operator()": "??R", "operatornew[]": "??_U",
              "operatordelete[]": "??_V"}


def mangle_prefixes(qname, scope, c_linkage):
    """Mangled-name prefixes a definition of qname can have (MSVC), or [] if unsure."""
    parts = list(scope) + qname.split("::")
    if c_linkage and len(parts) == 1:
        return []          # C names are matched exactly (block "cnames")
    if any(not re.fullmatch(r"~?[A-Za-z_]\w*", p) and not p.startswith("operator") for p in parts):
        return []
    last, quals = parts[-1], parts[:-1]
    q = "".join("%s@" % p for p in reversed(quals))
    if last.startswith("~"):
        # the destructor, or the scalar/vector deleting destructors generated from it
        return ["??%s%s@@" % (op, q.rstrip("@")) for op in ("1", "_G", "_E")] if quals else []
    if quals and last == quals[-1]:
        return ["??0%s@" % q.rstrip("@") + "@"]
    if last in MANGLE_OPS:
        return [MANGLE_OPS[last] + q + "@"]
    if last.startswith("operator"):
        return []
    return ["?%s@%s@" % (last, q.rstrip("@")) if q else "?%s@@" % last]


def block_names(gen):
    """addr -> mangled-name prefixes / C names of the block's definitions (from the parsed sources)."""
    out = {}
    for tu in gen.tus:
        for b in tu.blocks:
            pre, cn = [], []
            for d in b.defs:
                qn = d.key[1].split("::")
                scope = list(d.scope)
                q = "::".join(qn[len(scope):]) if qn[:len(scope)] == scope else d.key[1]
                if "::" not in q:
                    # C linkage can come from an earlier extern "C" declaration: cdecl/stdcall, fastcall
                    # names (the @N suffix is dropped before comparing)
                    cn += ["_" + q, "@" + q]
                pre += mangle_prefixes(q, scope, d.c_linkage)
            out[b.addr] = (pre, cn)
    return out


def standalone(src, addr, verifier):
    """Compile a verified source on its own (cached) and compare: is it a match by itself?"""
    text = open(os.path.join(ROOT, src), "rb").read()
    flags = compare.DEFAULT_FLAGS + compare.file_flags(os.path.join(ROOT, src))
    h = hashlib.sha1(text + repr(flags).encode()).hexdigest()[:20]
    obj = os.path.join(OBJ_CACHE, "sa-" + h + ".obj")
    if not os.path.exists(obj):
        import tempfile
        with tempfile.TemporaryDirectory() as tmp:
            try:
                o = compare.compile_obj(os.path.join(ROOT, src), compare.DEFAULT_FLAGS, tmp)
            except compare.CompileError as e:
                return {"status": "compile_error", "error": str(e)[:200]}
            os.replace(o, obj)
    blk = {"addr": "0x%08x" % addr, "mode": "isolated"}
    return verifier.check(obj, blk, set())


def diff_reason(tree_rows, sa_rows):
    """Short description of how the merged function differs."""
    if not tree_rows:
        return "?"
    bad = [r for r in tree_rows if r[0] != "  "]
    calls_t = [r for r in bad if r[2].startswith("call") or r[3].startswith("call")]
    if any(r[0] == "--" and r[2].startswith("call") for r in bad):
        return "a call became inline code (callee now defined in the same TU)"
    if calls_t:
        return "call sequence differs"
    return "codegen differs (%d of %d instructions)" % (len(bad), len(tree_rows))


# ---------------------------------------------------------------------------------------------
def run(jobs=4, rounds=8, fresh=True):
    state = {"wrap": {}, "isolate": {}, "local_only": set()} if fresh else gen_tree.load_state()
    history = []
    for rnd in range(1, rounds + 1):
        gen = gen_tree.generate(state)
        gen_tree.save_state(state)
        manifest = gen.manifest
        paths = [t["path"] for t in manifest["tus"]]
        results = compile_all(paths, jobs)
        failed = [p for p in paths if results[p][0] is None]
        new = blame(manifest, results, state)
        history.append({"round": rnd, "tus": len(paths), "failed": len(failed), "new_fallbacks": new})
        print("round %d: %d TUs, %d failed, %d new fallbacks" % (rnd, len(paths), len(failed), new), flush=True)
        if not failed:
            break
        if not new or rnd == rounds - 1:
            # last resort: every function of a still-failing TU gets its own TU
            for rec in manifest["tus"]:
                if results[rec["path"]][0] is None:
                    for b in rec["blocks"]:
                        a = int(b["addr"], 16)
                        if a not in state["isolate"]:
                            state["isolate"][a] = "TU still failing after %d rounds" % rnd
                            new += 1
            if not new:
                break
    gen_tree.save_state(state)
    return gen, manifest, results, history, state


def verify(gen, manifest, results, jobs=4):
    v = Verifier()
    names = block_names(gen)
    out = []
    for rec in manifest["tus"]:
        obj = results[rec["path"]][0]
        claimed = set()
        for b in rec["blocks"]:
            a = int(b["addr"], 16)
            pre, cn = names.get(a, ([], []))
            b["prefixes"], b["cnames"] = pre, cn
            r = {"addr": b["addr"], "name": b["name"], "src": b["src"], "kind": b["kind"], "mode": b["mode"],
                 "tu": rec["path"]}
            if obj is None:
                r["status"] = "tu_failed"
            elif b["kind"] == "equivalent":
                c = v.check(obj, b, claimed)
                r["status"] = "compiled" if c["status"] != "no_function" else "no_function"
                r["symbol"] = c.get("symbol")
                r["how"] = c.get("how")
                if c.get("symbol"):
                    claimed.add(c["symbol"])
            else:
                c = v.check(obj, b, claimed)
                r.update({k: c[k] for k in ("status", "symbol", "how", "score") if k in c})
                if c.get("symbol"):
                    claimed.add(c["symbol"])
                if c["status"] != "match":
                    sa = standalone(b["src"], a, v)
                    r["standalone"] = sa["status"]
                    if sa["status"] == "match" and c["status"] == "diff":
                        r["why"] = diff_reason(c.get("rows"), sa.get("rows"))
            out.append(r)
    return out


def summarize(manifest, results, checks, history, gen, state):
    tus = manifest["tus"]
    ok = [t for t in tus if results[t["path"]][0] is not None]
    bad = [t for t in tus if results[t["path"]][0] is None]
    causes = collections.Counter()
    examples = {}
    for t in bad:
        for fname, line, code, msg in results[t["path"]][1][:1]:
            k = "%s %s" % (code, re.sub(r"'[^']*'", "'X'", msg)[:80])
            causes[k] += 1
            examples.setdefault(k, "%s(%d)" % (t["path"], line))
    st = collections.Counter((c["kind"], c["status"]) for c in checks)
    m = [c for c in checks if c["kind"] == "matches"]
    m_by_mode = collections.Counter((c["mode"], c["status"]) for c in m)
    lost = [c for c in m if c["status"] != "match"]
    lost_why = collections.Counter(
        ("regression: " + c.get("why", c["status"])) if c.get("standalone") == "match" else
        ("not a match standalone either (%s)" % c.get("standalone")) for c in lost)
    return {
        "rounds": history,
        "tu_files": len(tus),
        "tu_compiled": len(ok),
        "tu_failed": len(bad),
        "tu_failure_causes": [{"cause": k, "tus": v, "example": examples[k]} for k, v in causes.most_common()],
        "functions": {"%s/%s" % k: v for k, v in sorted(st.items())},
        "matches_by_mode": {"%s/%s" % k: v for k, v in sorted(m_by_mode.items())},
        "matches_total": len(m),
        "matches_still_matching": sum(1 for c in m if c["status"] == "match"),
        "matches_lost": len(lost),
        "matches_lost_why": dict(lost_why.most_common()),
        "symbol_lookup": dict(collections.Counter(c.get("how") for c in checks if c.get("how"))),
        "fallbacks": {"wrapped_by_build": len(state["wrap"]), "isolated_by_build": len(state["isolate"]),
                      "header_symbols_kept_local": len(state["local_only"])},
        "generator": gen_tree.summary(gen),
    }


def run_equiv(checks, results, limit):
    """equiv.verify on the tree's objects (obj_path + symbol): behaviour check of equivalent/ functions.

    Caveat: functions defined in the same object run as our own code (equiv.py treats them like inlined
    helpers) instead of being bound to the original's addresses."""
    import equiv
    todo = [c for c in checks if c["kind"] == "equivalent" and c["status"] == "compiled" and c.get("symbol")]
    if limit:
        todo = todo[:limit]
    by_tu = {}
    for c in todo:
        by_tu.setdefault(c["tu"], []).append(c)
    st = collections.Counter()
    for tu, cs in by_tu.items():
        obj = results[tu][0]
        for c in cs:
            try:
                rep = equiv.verify(os.path.join(ROOT, c["src"]), int(c["addr"], 16), symbol=c["symbol"], obj_path=obj)
                c["equiv"] = rep["status"]
            except Exception as e:  # noqa: BLE001 - a crash in one function must not stop the report
                c["equiv"] = "error: %s" % type(e).__name__
            st[c["equiv"]] += 1
    return dict(st)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--rounds", type=int, default=8)
    ap.add_argument("--resume", action="store_true", help="start from build/tree/state.json instead of empty")
    ap.add_argument("--only", help="compile one TU of the current tree and print its errors")
    ap.add_argument("--equiv", type=int, metavar="N", help="also run tools/equiv.py (64 inputs) on the merged "
                    "object for the first N equivalent/ functions (0 = all; slow: 1-5 s each)")
    a = ap.parse_args(argv)
    if a.only:
        obj, errs, out = compile_tu(a.only)
        print(out if obj is None else "OK " + obj)
        return 0 if obj else 1
    gen, manifest, results, history, state = run(a.jobs, a.rounds, fresh=not a.resume)
    checks = verify(gen, manifest, results, a.jobs)
    rep = summarize(manifest, results, checks, history, gen, state)
    if a.equiv is not None:
        rep["equiv_on_merged_objects"] = run_equiv(checks, results, a.equiv)
    with open(os.path.join(TREE, "report.json"), "w") as f:
        json.dump(dict(rep, checks=checks), f, indent=1)
    rep.pop("generator")
    print(json.dumps(rep, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
