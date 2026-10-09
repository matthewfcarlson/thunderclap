#!/usr/bin/env python3
"""Brute-force near-misses: randomly rewrite a close attempt, recompile, keep what scores better.

The LLM gets the logic right but often loses on register allocation, instruction order or branch
layout, which depend on surface details of the source (statement order, operand order, signedness,
if/else orientation, declaration order). This searches those details with the CPU instead of tokens.

Mutations need not preserve meaning: a candidate only counts when the code is byte-identical
(compare.py) and every relocation points at the right target (verify_relocs.py), so identical bytes
mean identical behaviour.

  tools/permute.py SRC 0xADDR [--minutes 10] [--jobs 6] [--install]
  tools/permute.py --queue near.txt [--minutes 5] [--install]   # lines: "0xADDR path/to/best.cpp"
"""
import argparse
import json
import os
import random
import re
import shutil
import subprocess
import sys
import tempfile
import time
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(__file__))
from compare import compare  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
OUT = os.path.join(ROOT, "build/farm/permute")
FLAG_SETS = ["", "/Oy-", "/Oy- /O1", "/O1", "/Os", "/Oy- /Os"]
STMT = re.compile(r"^(\s+)([^\s{}#/][^{}]*;)\s*$")  # one simple statement / declaration on a line
OPERAND = r"[\w.\[\]]+(?:->[\w\[\]]+)*"


# ---- mutations: each takes the source text and returns new text (or None if not applicable) ----

def _lines_with(text, pred):
    lines = text.split("\n")
    return lines, [i for i, l in enumerate(lines) if pred(l)]


def m_swap_lines(text):
    """Swap two nearby statements in the same block (same indentation, no braces between)."""
    lines, idx = _lines_with(text, lambda l: STMT.match(l) and not l.strip().startswith("return"))
    if len(idx) < 2:
        return None
    i = random.choice(idx)
    ind = STMT.match(lines[i]).group(1)
    cands = []
    for d in (1, 2, 3, -1, -2, -3):
        j = i + d
        if 0 <= j < len(lines) and j in idx and STMT.match(lines[j]).group(1) == ind:
            between = lines[min(i, j) + 1:max(i, j)]
            if all(STMT.match(b) and STMT.match(b).group(1) == ind for b in between):
                cands.append(j)
    if not cands:
        return None
    j = random.choice(cands)
    lines[i], lines[j] = lines[j], lines[i]
    return "\n".join(lines)


def m_commute(text):
    """a OP b -> b OP a for commutative operators (incl. && / ||, which changes evaluation order)."""
    pat = re.compile(r"(?<![\w.>\]])(%s)\s*(\+|\*|(?<![&|])&(?![&=])|(?<!\|)\|(?![|=])|\^|==|!=|&&|\|\|)\s*(%s)(?![\w(\[])" % (OPERAND, OPERAND))
    ms = [m for m in pat.finditer(text) if not text[:m.start()].rstrip().endswith(("struct", "class"))]
    if not ms:
        return None
    m = random.choice(ms)
    return text[:m.start()] + "%s %s %s" % (m.group(3), m.group(2), m.group(1)) + text[m.end():]


def m_flip_compare(text):
    pat = re.compile(r"(%s)\s*(<=|>=|<(?![<=])|>(?![>=]))\s*(%s)(?![\w(\[])" % (OPERAND, OPERAND))
    ms = [m for m in pat.finditer(text) if "template" not in text[max(0, m.start() - 20):m.start()]]
    if not ms:
        return None
    m = random.choice(ms)
    flip = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}[m.group(2)]
    return text[:m.start()] + "%s %s %s" % (m.group(3), flip, m.group(1)) + text[m.end():]


TYPE_SWAPS = [
    (r"\bunsigned int\b", "int"), (r"(?<!unsigned )\bint\b", "unsigned int"), (r"\bunsigned\b(?! (int|char|short|long))", "int"),
    (r"(?<!unsigned )\bchar\b", "unsigned char"), (r"\bunsigned char\b", "char"), (r"\bbool\b", "char"), (r"\bbool\b", "int"),
    (r"(?<!unsigned )\bshort\b", "unsigned short"), (r"\bunsigned short\b", "short"), (r"\blong\b", "int"),
]


def m_retype(text):
    pat, rep = random.choice(TYPE_SWAPS)
    ms = list(re.finditer(pat, text))
    if not ms:
        return None
    m = random.choice(ms)
    return text[:m.start()] + rep + text[m.end():]


def m_truthiness(text):
    """if (x) <-> if (x != 0), if (!x) <-> if (x == 0)."""
    opts = [
        (r"\((!)(%s)\)" % OPERAND, lambda m: "(%s == 0)" % m.group(2)),
        (r"\((%s) == 0\)" % OPERAND, lambda m: "(!%s)" % m.group(1)),
        (r"\((%s) != 0\)" % OPERAND, lambda m: "(%s)" % m.group(1)),
        (r"(?<=if )\((%s)\)" % OPERAND, lambda m: "(%s != 0)" % m.group(1)),
    ]
    pat, fn = random.choice(opts)
    ms = list(re.finditer(pat, text))
    if not ms:
        return None
    m = random.choice(ms)
    return text[:m.start()] + fn(m) + text[m.end():]


def m_incdec(text):
    opts = [(r"(\w+)\+\+", r"++\1"), (r"\+\+(\w+)", r"\1++"), (r"(\w+)--", r"--\1"), (r"--(\w+)", r"\1--"),
            (r"(%s) \+= ([^;]+);" % OPERAND, r"\1 = \1 + \2;"), (r"(%s) = \1 \+ ([^;]+);" % OPERAND, r"\1 += \2;"),
            (r"(\w+)\+\+;", r"\1 += 1;"), (r"(\w+) \+= 1;", r"\1++;")]
    pat, rep = random.choice(opts)
    ms = list(re.finditer(pat, text))
    if not ms:
        return None
    m = random.choice(ms)
    return text[:m.start()] + m.expand(rep) + text[m.end():]


def _match(text, i, o, c):
    d = 0
    for j in range(i, len(text)):
        if text[j] == o:
            d += 1
        elif text[j] == c:
            d -= 1
            if d == 0:
                return j
    return -1


def m_flip_if(text):
    """if (c) {A} else {B} -> if (!(c)) {B} else {A}: changes which branch falls through."""
    ms = [m.start() for m in re.finditer(r"\bif\s*\(", text)]
    random.shuffle(ms)
    for s in ms:
        p0 = text.index("(", s)
        p1 = _match(text, p0, "(", ")")
        if p1 < 0:
            continue
        rest = text[p1 + 1:]
        b0 = p1 + 1 + (len(rest) - len(rest.lstrip()))
        if b0 >= len(text) or text[b0] != "{":
            continue
        b1 = _match(text, b0, "{", "}")
        m = re.match(r"\s*else\s*\{", text[b1 + 1:])
        if b1 < 0 or not m:
            continue
        e0 = b1 + m.end()
        e1 = _match(text, e0, "{", "}")
        if e1 < 0:
            continue
        cond = text[p0 + 1:p1]
        neg = cond[1:].strip() if cond.startswith("!") and "&&" not in cond and "||" not in cond else "!(%s)" % cond
        return text[:s] + "if (%s) %s else %s" % (neg, text[e0:e1 + 1], text[b0:b1 + 1]) + text[e1 + 1:]
    return None


def m_split_init(text):
    """T x = e;  ->  T x; x = e;   (and the reverse) — moves where a local comes alive."""
    if random.random() < 0.5:
        ms = list(re.finditer(r"^(\s+)((?:unsigned |const )?[\w:]+\s*\**\s*)(\w+) = ([^;{}]+);$", text, re.M))
        if not ms:
            return None
        m = random.choice(ms)
        return text[:m.start()] + "%s%s%s;\n%s%s = %s;" % (m.group(1), m.group(2), m.group(3), m.group(1), m.group(3), m.group(4)) + text[m.end():]
    ms = list(re.finditer(r"^(\s+)((?:unsigned |const )?[\w:]+\s*\**\s*)(\w+);\n\1\3 = ([^;{}]+);$", text, re.M))
    if not ms:
        return None
    m = random.choice(ms)
    return text[:m.start()] + "%s%s%s = %s;" % (m.group(1), m.group(2), m.group(3), m.group(4)) + text[m.end():]


MUTATIONS = [(m_swap_lines, 5), (m_commute, 3), (m_flip_compare, 2), (m_retype, 3), (m_truthiness, 2),
             (m_incdec, 1), (m_flip_if, 2), (m_split_init, 2)]
_W = [w for _, w in MUTATIONS]


def mutate(text):
    for _ in range(random.choice((1, 1, 1, 2, 2, 3))):
        for _ in range(10):
            fn = random.choices([f for f, _ in MUTATIONS], _W)[0]
            new = fn(text)
            if new and new != text:
                text = new
                break
    return text


def set_flags(text, flags):
    body = re.sub(r"\A\s*//\s*cl-flags:[^\n]*\n", "", text)
    return ("// cl-flags: %s\n" % flags if flags else "") + body


# ---- evaluation ----

_ctx = {}


def _init(addr, symbol):
    _ctx.update(addr=addr, symbol=symbol, tmp=tempfile.mkdtemp(prefix="perm"))
    random.seed(os.getpid() ^ int(time.time() * 1e6))


def score(text, addr=None, symbol=None):
    addr = addr or _ctx["addr"]
    tmp = _ctx.get("tmp") or tempfile.mkdtemp(prefix="perm")
    src = os.path.join(tmp, "p.cpp")
    with open(src, "w") as f:
        f.write(text)
    try:
        r = compare(src, addr, symbol or _ctx.get("symbol"))
    except Exception:
        return (-1, 0), None
    if r.get("status") not in ("match", "diff"):
        return (-1, 0), None
    if r["status"] == "match":
        return (10 ** 6, 0), r
    # Matched instructions first, then closeness of size.
    return (r["matched"] / max(r["total"], 1), -abs(r["target_bytes"] - r["our_bytes"])), r


def _job(text):
    cand = mutate(text)
    s, _ = score(cand)
    return s, cand


def verify(text, addr):
    from verify_relocs import check
    with tempfile.TemporaryDirectory() as tmp:
        src = os.path.join(tmp, "v.cpp")
        with open(src, "w") as f:
            f.write(text)
        return check(src, addr)


def permute(src, addr, minutes=10.0, jobs=6, install=False, log=print):
    a = "0x%08x" % addr
    base = open(src).read()
    s0, r0 = score(base, addr)
    if r0 is None:
        log("%s: base does not compile/compare" % a)
        return "error"
    symbol = r0["symbol"]
    best, best_s = base, s0
    # Compiler option variants first: cheap and sometimes the whole story.
    for fl in FLAG_SETS:
        cand = set_flags(base, fl)
        s, _ = score(cand, addr, symbol)
        if s > best_s:
            best, best_s = cand, s
    log("%s: start %.3f (after flags %.3f)" % (a, s0[0], min(best_s[0], 1)))
    os.makedirs(os.path.join(OUT, a), exist_ok=True)
    cur, cur_s, tried, last_gain = best, best_s, 0, time.time()
    deadline = time.time() + minutes * 60
    result = "miss"
    with Pool(jobs, initializer=_init, initargs=(addr, symbol)) as pool:
        def gen():
            while time.time() < deadline:
                yield cur
        for s, cand in pool.imap_unordered(_job, gen()):
            tried += 1
            if s[0] >= 10 ** 6:
                v = verify(cand, addr)
                if v.get("status") == "ok":
                    best, best_s, result = cand, s, "match"
                    break
                log("%s: byte match but relocs %s; continuing" % (a, v.get("status")))
                continue
            if s > best_s:
                best, best_s, last_gain = cand, s, time.time()
                log("%s: %.3f after %d tries" % (a, s[0], tried))
            if s > cur_s or (s == cur_s and random.random() < 0.3):
                cur, cur_s = cand, s  # walk plateaus
            elif random.random() < 0.02:
                cur, cur_s = best, best_s  # restart from the best
            if time.time() - last_gain > max(120, minutes * 30):
                break  # stalled
        pool.terminate()
    with open(os.path.join(OUT, a, "best.cpp"), "w") as f:
        f.write(best)
    if result == "match" and install:
        dest = os.path.join(ROOT, "matches", a + ".cpp")
        with open(dest, "w") as f:
            f.write(best)
        subprocess.run([sys.executable, os.path.join(ROOT, "tools/format_matches.py"), dest, "--jobs", "1"],
                       capture_output=True)
    log("%s: %s, best %.3f, %d tries" % (a, result.upper(), min(best_s[0], 1.0), tried))
    with open(os.path.join(OUT, "log.jsonl"), "a") as f:
        f.write(json.dumps({"addr": a, "src": src, "result": result, "start": s0[0],
                            "best": min(best_s[0], 1.0), "tries": tried, "t": time.time()}) + "\n")
    return result


def main():
    p = argparse.ArgumentParser()
    p.add_argument("src", nargs="?")
    p.add_argument("addr", nargs="?")
    p.add_argument("--queue", help="file of lines '0xADDR path/to/attempt.cpp'")
    p.add_argument("--minutes", type=float, default=10)
    p.add_argument("--jobs", type=int, default=max(1, (os.cpu_count() or 4) - 2))
    p.add_argument("--install", action="store_true", help="copy verified matches into matches/")
    a = p.parse_args()
    if a.queue:
        for line in open(a.queue):
            parts = line.split()
            if len(parts) < 2 or os.path.exists(os.path.join(ROOT, "matches", "0x%08x.cpp" % int(parts[0], 16))):
                continue
            permute(parts[1], int(parts[0], 16), a.minutes, a.jobs, a.install,
                    log=lambda m: print(time.strftime("%H:%M:%S"), m, flush=True))
    else:
        permute(a.src, int(a.addr, 16), a.minutes, a.jobs, a.install)


if __name__ == "__main__":
    main()
