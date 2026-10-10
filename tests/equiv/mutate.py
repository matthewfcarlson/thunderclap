#!/usr/bin/env python3
"""Mutation suite for tools/equiv.py: wrong code must FAIL, equivalent rewrites must PASS.

  build/venv/bin/python tests/equiv/mutate.py [--n 120] [--jobs 2] [--only 0x...]

For a sample of matched functions, each source is mutated once per operator:

  must fail:  swap      swap the operands of a non-commutative binary operator (a - b -> b - a)
              const     change a numeric literal (n -> n + 1, f -> 2f + 0.5)
              dropcall  delete a call statement
              field     shift a field offset (insert a 4-byte member before a data member)
              flipcmp   flip a comparison (== <-> !=, < -> >=, ...)
  must pass:  commute   swap the operands of a commutative operator where it is the whole expression
              (a + b -> b + a): different code, same behaviour

Mutants that don't compile, or compile to the same bytes as the original, are excluded (not counted).
Symbols are bound with the ground-truth mapping of the unmutated match, so a mutant's names mean
what the original's names mean. Results: build/equiv/mutants.jsonl and a summary.
"""
import argparse
import json
import os
import random
import re
import sys
import time
from collections import Counter, defaultdict
from multiprocessing import Pool

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
OUT_DIR = os.path.join(ROOT, "build/equiv/mutants")

# Mutants that compile to different bytes but are semantically equivalent (checked by hand); a pass on
# them is correct. Key: (address, operator, removed line, added line).
EQUIVALENT_MUTANTS = {
    # the inlined bit-set clear runs twice over the same words: either loop alone gives the same memory
    ("0x000f86f0", "swap", "if (n > 0) {", "if (0 > n) {"),
    ("0x000f86f0", "const", "for (; k != 0; k--)", "for (; k != 1; k--)"),
    ("0x000f86f0", "flipcmp", "for (unsigned i = n; i != 0; i--)", "for (unsigned i = n; i == 0; i--)"),
    # dead store: mTarget is overwritten before anything can observe it
    ("0x001909b0", "const", "*p = 0;", "*p = 1;"),
    ("0x00199630", "const", "*p = 0;", "*p = 1;"),
    # dead store: the second c.vt assignment, after the only call that sees c
    ("0x00296c50", "const", "c.vt = (void*)0x42d330;", "c.vt = (void*)0x42d331;"),
    # the callee (FUN_0027af50) is an empty function: which `this` it gets is unobservable
    ("0x00172da0", "field", "Part part;", "int mut_pad_111; Part part;"),
    ("0x00202430", "field", "Helper helper;", "int mut_pad_52; Helper helper;"),
    ("0x00305320", "const", "((H10*)((char*)this + 0x10))->run10();", "((H10*)((char*)this + 0x11))->run10();"),
    # F2 (FUN_001ebd80) pops four arguments but never reads the fourth
    ("0x001ee090", "const", 'F2(c, "impact_big", 100.0f, 0);', 'F2(c, "impact_big", 100.0f, 1);'),
    # only the size of a stack-local object/buffer changes; callees see the same start address
    ("0x00262700", "field", "char pad[12];", "int mut_pad_59; char pad[12];"),
    ("0x001ebc80", "const", "char local[72];", "char local[73];"),
}


def _change(src, mut):
    import difflib
    d = [x for x in difflib.unified_diff(src.splitlines(), mut.splitlines(), lineterm="", n=0)
         if x[:1] in "+-" and x[:3] not in ("+++", "---")]
    rem = [x[1:].strip() for x in d if x.startswith("-")]
    add = [x[1:].strip() for x in d if x.startswith("+")]
    return (rem[0] if rem else "", add[0] if add else "")


TOKEN = re.compile(r"""
    (?P<ws>\s+|//[^\n]*|/\*.*?\*/)
  | (?P<str>"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*')
  | (?P<num>0[xX][0-9a-fA-F]+[uUlL]*|\d+\.\d*(?:[eE][-+]?\d+)?[fF]?|\.\d+(?:[eE][-+]?\d+)?[fF]?|\d+(?:[eE][-+]?\d+)[fF]?|\d+[uUlL]*)
  | (?P<id>[A-Za-z_]\w*)
  | (?P<op><<=|>>=|->\*|->|::|\+\+|--|<=|>=|==|!=|&&|\|\||<<|>>|\+=|-=|\*=|/=|%=|&=|\|=|\^=|[-+*/%<>=!&|^~?:;,.(){}\[\]#])
""", re.X | re.S)

KEYWORDS = {"return", "if", "while", "for", "else", "do", "switch", "case", "delete", "new", "goto", "break",
            "continue", "sizeof", "default", "throw", "typedef", "static_cast", "reinterpret_cast", "const_cast"}
TYPEWORDS = {"int", "unsigned", "char", "short", "long", "float", "double", "bool", "void", "const", "signed",
             "struct", "class", "static", "volatile", "virtual", "inline", "extern"}


def tokenize(src):
    out = []
    for m in TOKEN.finditer(src):
        kind = m.lastgroup
        if kind == "ws":
            continue
        out.append((kind, m.group(), m.start(), m.end()))
    return out


def regions(toks):
    """Mark each token as in a function body ('code') or not, by brace structure."""
    depth_kind = []
    marks = []
    for k, (kind, text, s, e) in enumerate(toks):
        in_code = any(d == "code" for d in depth_kind)
        if text == "{":
            # a function body starts after ')' or ') const' at a non-code level
            j = k - 1
            while j >= 0 and toks[j][1] == "const":
                j -= 1
            is_body = (not in_code) and j >= 0 and toks[j][1] == ")"
            depth_kind.append("code" if in_code or is_body else "decl")
        elif text == "}":
            if depth_kind:
                depth_kind.pop()
        marks.append(in_code)
    return marks


def _atom_bounds(toks, k, direction):
    """Extent of a simple operand next to operator token k: ident/num with ->/. chains and [..] subscripts."""
    if direction < 0:
        j = k - 1
        if j < 0:
            return None
        end = j
        while True:
            if toks[j][1] == "]":
                depth = 0
                while j >= 0:
                    if toks[j][1] == "]":
                        depth += 1
                    elif toks[j][1] == "[":
                        depth -= 1
                        if depth == 0:
                            break
                    j -= 1
                j -= 1
                if j < 0:
                    return None
            if toks[j][0] not in ("id", "num") or toks[j][1] in KEYWORDS or toks[j][1] in TYPEWORDS:
                return None
            if j - 1 >= 0 and toks[j - 1][1] in ("->", ".", "::"):
                j -= 2
                if j < 0:
                    return None
                continue
            break
        if j - 1 >= 0 and toks[j - 1][1] in ("*", "&", "-", "!", "~", "++", "--", ")"):
            # possibly a unary prefix or a cast: let it be, unless it is clearly binary context
            if toks[j - 1][1] == ")" or (j - 2 >= 0 and toks[j - 2][0] not in ("id", "num") and toks[j - 2][1] not in (")", "]")):
                return None
        return (j, end)
    j = k + 1
    if j >= len(toks) or toks[j][0] not in ("id", "num") or toks[j][1] in KEYWORDS or toks[j][1] in TYPEWORDS:
        return None
    start = j
    while True:
        if j + 1 < len(toks) and toks[j + 1][1] in ("->", ".", "::") and j + 2 < len(toks) and toks[j + 2][0] == "id":
            j += 2
            continue
        if j + 1 < len(toks) and toks[j + 1][1] == "[":
            depth = 0
            j += 1
            while j < len(toks):
                if toks[j][1] == "[":
                    depth += 1
                elif toks[j][1] == "]":
                    depth -= 1
                    if depth == 0:
                        break
                j += 1
            continue
        break
    if j + 1 < len(toks) and toks[j + 1][1] == "(":
        return None          # a call: keep it simple
    return (start, j)


def _closes_condition(toks, k):
    """Is toks[k] the ')' of an if/while/for condition?"""
    if toks[k][1] != ")":
        return False
    depth = 0
    for j in range(k, -1, -1):
        if toks[j][1] == ")":
            depth += 1
        elif toks[j][1] == "(":
            depth -= 1
            if depth == 0:
                return j > 0 and toks[j - 1][1] in ("if", "while", "for")
    return False


def _is_binary(toks, k):
    return k > 0 and (toks[k - 1][0] in ("id", "num") or toks[k - 1][1] in (")", "]")) \
        and toks[k - 1][1] not in KEYWORDS


def _splice(src, toks, a, b, text):
    return src[:toks[a][2]] + text + src[toks[b][3]:]


def _text(src, toks, a, b):
    return src[toks[a][2]:toks[b][3]]


def mutants(src, rng):
    """{operator: [mutated source, ...]} (several candidates per operator; caller picks)."""
    toks = tokenize(src)
    code = regions(toks)
    out = defaultdict(list)
    for k, (kind, text, s, e) in enumerate(toks):
        if not code[k]:
            continue
        if kind == "op" and _is_binary(toks, k):
            L, R = _atom_bounds(toks, k, -1), _atom_bounds(toks, k, 1)
            if L and R:
                lt, rt = _text(src, toks, *L), _text(src, toks, *R)
                swapped = src[:toks[L[0]][2]] + rt + src[toks[L[1]][3]:toks[R[0]][2]] + lt + src[toks[R[1]][3]:]
                if text in ("-", "/", "%", "<<", ">>", "<", ">", "<=", ">=") and lt != rt:
                    out["swap"].append(swapped)
                if text in ("+", "*", "&", "|", "^", "==", "!=") and lt != rt:
                    before = toks[L[0] - 1][1] if L[0] > 0 else ""
                    after = toks[R[1] + 1][1] if R[1] + 1 < len(toks) else ""
                    if before in ("(", "=", "return", ",") and after in (")", ";", ","):
                        out["commute"].append(swapped)
                flip = {"==": "!=", "!=": "==", "<": ">=", ">": "<=", "<=": ">", ">=": "<"}.get(text)
                if flip:
                    out["flipcmp"].append(src[:s] + flip + src[e:])
        if kind == "num":
            t = text.rstrip("uUlL")
            suffix = text[len(t):]
            try:
                if t.lower().startswith("0x"):
                    new = hex(int(t, 16) + 1) + suffix
                elif re.search(r"[.eE]", t) or t.endswith(("f", "F")):
                    f = float(t.rstrip("fF"))
                    new = repr(f * 2 + 0.5) + ("f" if t.endswith(("f", "F")) else "")
                else:
                    new = str(int(t) + 1) + suffix
            except ValueError:
                continue
            # inside array sizes in code is fine; skip case labels' duplicates by compile failure
            out["const"].append(src[:s] + new + src[e:])
    # drop a call statement
    k = 0
    while k < len(toks):
        if code[k] and (k == 0 or toks[k - 1][1] in (";", "{", "}", "else") or _closes_condition(toks, k - 1)) \
                and toks[k][0] == "id" \
                and toks[k][1] not in KEYWORDS and toks[k][1] not in TYPEWORDS:
            j, depth, has_call, assign = k, 0, False, False
            while j < len(toks) and not (toks[j][1] == ";" and depth == 0):
                t = toks[j][1]
                if t in ("(", "["):
                    depth += 1
                    if t == "(" and toks[j - 1][0] == "id":
                        has_call = True
                elif t in (")", "]"):
                    depth -= 1
                elif t in ("{", "}"):
                    break
                elif depth == 0 and t in ("=", "+=", "-=", "*=", "/=", "|=", "&=", "^=", "<<=", ">>=", "++", "--"):
                    assign = True
                j += 1
            if j < len(toks) and toks[j][1] == ";" and has_call and not assign and toks[j - 1][1] == ")":
                out["dropcall"].append(src[:toks[k][2]] + ";" + src[toks[j][3]:])
            k = j + 1
            continue
        k += 1
    # shift a field: insert an int before a data member declaration (outside function bodies)
    for k, (kind, text, s, e) in enumerate(toks):
        if code[k] or text != ";":
            continue
        # walk back to the start of this declaration
        j = k - 1
        while j >= 0 and toks[j][1] not in (";", "{", "}", ":"):
            j -= 1
        decl = toks[j + 1:k]
        if len(decl) < 2 or any(t[1] in ("(", ")", "typedef", "static", "virtual", "friend", "using", "enum")
                                for t in decl):
            continue
        if decl[0][1] in ("class", "struct", "union") and len(decl) <= 3:
            continue
        # must be inside a class/struct body: the enclosing '{' belongs to a class/struct
        depth, m = 0, j
        enclosing = None
        while m >= 0:
            if toks[m][1] == "}":
                depth += 1
            elif toks[m][1] == "{":
                if depth == 0:
                    enclosing = m
                    break
                depth -= 1
            m -= 1
        if enclosing is None:
            continue
        head = [t[1] for t in toks[max(0, enclosing - 6):enclosing]]
        if not any(h in ("class", "struct", "union") for h in head):
            continue
        ins = toks[j + 1][2]
        out["field"].append(src[:ins] + "int mut_pad_%d; " % k + src[ins:])
    return out


def job(args):
    addr, ops_seed = args
    import equiv
    src_path = os.path.join(ROOT, "matches", "0x%08x.cpp" % addr)
    src = open(src_path).read()
    results = []
    truth = equiv.verify(src_path, addr, max_level=2)
    if truth["status"] in ("compile_error", "no_function"):
        return [{"addr": "0x%08x" % addr, "op": "-", "outcome": "skip_truth_failed"}]
    mapping = {n: int(v["addr"], 16) for n, v in truth["level2"]["mapping"].items() if v["addr"]}
    rng = random.Random(ops_seed)
    cands = mutants(src, rng)
    os.makedirs(OUT_DIR, exist_ok=True)
    for op in ("swap", "const", "dropcall", "field", "flipcmp", "commute"):
        pool = list(dict.fromkeys(cands.get(op, [])))
        rng.shuffle(pool)
        tried = 0
        for mut in pool:
            if tried >= 3:           # a few attempts to find one that compiles and changes the code
                break
            tried += 1
            path = os.path.join(OUT_DIR, "0x%08x_%s_%d.cpp" % (addr, op, tried))
            with open(path, "w") as f:
                f.write(mut)
            t = time.time()
            try:
                r = equiv.verify(path, addr, symbol=truth["symbol"], mapping=mapping, use_names=False)
            except Exception as e:
                r = {"status": "crash", "error": repr(e)[:300]}
            rec = {"addr": "0x%08x" % addr, "op": op, "file": os.path.relpath(path, ROOT), "status": r["status"],
                   "level": r.get("level"), "wall": round(time.time() - t, 2),
                   "byte_identical": r.get("byte_identical"),
                   "coverage": (r.get("level3") or {}).get("coverage", {}).get("complete"),
                   "why": ((r.get("level3") or {}).get("mismatches") or [{}])[0].get("diffs")
                   or [i["kind"] for i in (r.get("level2") or {}).get("issues", [])][:3] or r.get("error", "")[:200]}
            if r["status"] in ("compile_error", "no_function"):
                rec["outcome"] = "excluded_no_compile"
                results.append(rec)
                continue
            if r.get("byte_identical"):
                rec["outcome"] = "excluded_same_bytes"
                results.append(rec)
                continue
            expect_pass = op == "commute"
            if ("0x%08x" % addr, op) + _change(src, mut) in EQUIVALENT_MUTANTS:
                rec["outcome"] = "equivalent_mutant" if r["status"] == "equivalent" else "FALSE_FAIL"
                results.append(rec)
                break
            if r["status"] == "equivalent":
                rec["outcome"] = "ok_pass" if expect_pass else "FALSE_PASS"
            elif r["status"] == "fail":
                rec["outcome"] = "FALSE_FAIL" if expect_pass else "caught"
                rec["caught_at"] = "level2" if r.get("level", 0) < 2 else "level3"
            else:
                rec["outcome"] = "unsupported"
            results.append(rec)
            break
    return results


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--n", type=int, default=120)
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--only")
    p.add_argument("--out", default=os.path.join(ROOT, "build/equiv/mutants.jsonl"))
    a = p.parse_args()
    if not os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe")):
        print("skip: no isos/extracted/default.xbe")
        return 0
    import selftest
    if a.only:
        addrs = [int(x, 16) for x in a.only.split(",")]
    else:
        base = set(selftest.sample(300))
        addrs = [x for x in selftest.sample(a.n * 3, seed=23) if x not in base]
        import equiv
        prog = equiv.Program.get()
        addrs = [x for x in addrs if prog.funcs[x][0] >= 24]
        random.Random(5).shuffle(addrs)
        addrs = sorted(addrs[:a.n])
    counts = Counter()
    by_op = defaultdict(Counter)
    t0 = time.time()
    with open(a.out, "w") as f, Pool(a.jobs) as pool:
        for i, recs in enumerate(pool.imap_unordered(job, [(x, x) for x in addrs])):
            for r in recs:
                f.write(json.dumps(r, default=str) + "\n")
                counts[r["outcome"]] += 1
                by_op[r["op"]][r["outcome"]] += 1
            f.flush()
            if (i + 1) % 10 == 0:
                print("  %d/%d %s" % (i + 1, len(addrs), dict(counts)), flush=True)
    print("results:", dict(counts), "in %.0fs" % (time.time() - t0))
    for op, c in sorted(by_op.items()):
        print("  %-9s %s" % (op, dict(c)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
