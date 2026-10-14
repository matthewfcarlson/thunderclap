#!/usr/bin/env python3
"""Collect the Lua call/global inventory of the game's scripts.

Sources scanned under a directory (default build/rcf):
  * standalone compiled chunks (.lua / .obj files starting with ESC Lua)
  * compiled chunks embedded back to back in .fig containers
  * plain-text Lua sources (.lua that are not bytecode), via a small lexer

For compiled code the callee of every CALL/TAILCALL is recovered by tracing
the function register backwards to its GETGLOBAL / GETTABLE / SELF producer.
Output is a JSON file (default build/lua/calls.json) with, per call target:
count, number of distinct scripts, per-group counts; plus the set of globals
the scripts assign (entry points / helpers they define).

The output contains game content (names only, but still): keep it under
build/lua/ (gitignored).

Usage: tools/lua_bindings.py [--root build/rcf] [--out build/lua/calls.json]
"""
import json
import os
import re
import sys
from collections import Counter, defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import luac_list as L  # noqa: E402

OPN = {i: n for i, (n, _) in enumerate(L.OPS)}
WRITES_A = {"MOVE", "LOADK", "LOADBOOL", "GETUPVAL", "GETGLOBAL", "GETTABLE",
            "NEWTABLE", "ADD", "SUB", "MUL", "DIV", "POW", "UNM", "NOT",
            "CONCAT", "CLOSURE"}


def group_of(rel):
    parts = rel.split("/")
    arch = parts[0]
    rest = parts[1:-1]
    if rest and rest[0] == arch:
        rest = rest[1:]
    return arch + "/" + (rest[0] if rest else "(root)")


def kname(f, i):
    if 0 <= i < len(f.k) and f.k[i][0] == "s":
        return f.k[i][1].decode("latin-1")
    return None


def resolve(f, pc, reg, depth=0):
    """Describe the value in `reg` just before instruction `pc`."""
    if depth > 6:
        return "?"
    for q in range(pc - 1, -1, -1):
        op, a, b, c, bx = L.decode(f.code[q])
        nm = OPN.get(op)
        if nm is None:
            continue
        if nm in WRITES_A and a == reg:
            if nm == "GETGLOBAL":
                return kname(f, bx) or "?"
            if nm == "GETUPVAL":
                un = f.upvalues[b].decode("latin-1") if b < len(f.upvalues) and f.upvalues[b] else "up%d" % b
                return "^" + un
            if nm == "GETTABLE":
                base = resolve(f, q, b, depth + 1)
                key = kname(f, c - L.MAXSTACK) if c >= L.MAXSTACK else None
                if key is None:
                    return base + "[]"
                return base + "." + key
            if nm == "MOVE":
                return resolve(f, q, b, depth + 1)
            return "<" + nm.lower() + ">"
        if nm == "SELF" and reg in (a, a + 1):
            base = resolve(f, q, b, depth + 1)
            if reg == a + 1:
                return base
            key = kname(f, c - L.MAXSTACK) if c >= L.MAXSTACK else None
            return base + ":" + (key or "?")
        if nm == "LOADNIL" and a <= reg <= b:
            return "nil"
        if nm == "CALL" and reg >= a:
            return "<call-result>"
        if nm in ("JMP", "EQ", "LT", "LE", "TEST", "FORLOOP", "FORPREP", "TFORLOOP", "TFORPREP"):
            pass  # linear scan only; good enough for call-target statistics
    return "<local>"


def bytecode_calls(fn):
    calls = Counter()
    setglobals = Counter()
    getglobals = Counter()
    for g in L.walk(fn):
        for pc, ins in enumerate(g.code):
            op, a, b, c, bx = L.decode(ins)
            nm = OPN.get(op)
            if nm in ("CALL", "TAILCALL"):
                calls[resolve(g, pc, a)] += 1
            elif nm == "SETGLOBAL":
                n = kname(g, bx)
                if n:
                    setglobals[n] += 1
            elif nm == "GETGLOBAL":
                n = kname(g, bx)
                if n:
                    getglobals[n] += 1
    return calls, setglobals, getglobals


# ---- text lexer ----------------------------------------------------------
KEYWORDS = {"and", "break", "do", "else", "elseif", "end", "false", "for",
            "function", "if", "in", "local", "nil", "not", "or", "repeat",
            "return", "then", "true", "until", "while"}
TOK = re.compile(r"""
    (?P<ws>\s+)
  | (?P<lcom>--\[(?P<leq>=*)\[)
  | (?P<com>--[^\n]*)
  | (?P<lstr>\[(?P<seq>=*)\[)
  | (?P<str>"(?:\\.|[^"\\\n])*"|'(?:\\.|[^'\\\n])*')
  | (?P<num>\d+\.?\d*(?:[eE][+-]?\d+)?|\.\d+)
  | (?P<name>[A-Za-z_][A-Za-z0-9_]*)
  | (?P<op>\.\.\.|\.\.|==|~=|<=|>=|.)
""", re.X | re.S)


def lex(src):
    pos = 0
    n = len(src)
    out = []
    while pos < n:
        m = TOK.match(src, pos)
        if not m:
            pos += 1
            continue
        pos = m.end()
        k = m.lastgroup
        if k == "lcom":
            close = "]" + m.group("leq") + "]"
            e = src.find(close, pos)
            pos = n if e < 0 else e + len(close)
        elif k == "lstr":
            close = "]" + m.group("seq") + "]"
            e = src.find(close, pos)
            pos = n if e < 0 else e + len(close)
            out.append(("str", ""))
        elif k in ("ws", "com", "leq", "seq"):
            continue
        elif k == "str":
            out.append(("str", m.group()[1:-1]))
        elif k in ("name", "num", "op"):
            out.append((k, m.group()))
    return out


def text_calls(src):
    toks = lex(src)
    calls = Counter()
    defined = Counter()
    locals_ = set()
    i = 0
    n = len(toks)
    # first pass: locals / params / function definitions
    for i, (k, v) in enumerate(toks):
        if k == "name" and v == "local":
            j = i + 1
            if j < n and toks[j] == ("name", "function"):
                j += 1
            while j < n and toks[j][0] == "name":
                locals_.add(toks[j][1])
                j += 1
                if j < n and toks[j] == ("op", ","):
                    j += 1
                else:
                    break
        elif k == "name" and v == "function":
            j = i + 1
            chain = []
            while j < n and toks[j][0] == "name":
                chain.append(toks[j][1])
                j += 1
                if j < n and toks[j][1] in (".", ":"):
                    j += 1
                else:
                    break
            if chain and j < n and toks[j] == ("op", "("):
                if len(chain) == 1:
                    defined[chain[0]] += 1
                j += 1
                while j < n and toks[j] != ("op", ")"):
                    if toks[j][0] == "name":
                        locals_.add(toks[j][1])
                    j += 1
        elif k == "name" and v == "for":
            j = i + 1
            while j < n and toks[j][0] == "name" and toks[j][1] != "in":
                locals_.add(toks[j][1])
                j += 1
                if j < n and toks[j] == ("op", ","):
                    j += 1
                else:
                    break
    # global assignments at statement level: Name = ...
    for i, (k, v) in enumerate(toks):
        if (k == "name" and v not in KEYWORDS and i + 1 < n and toks[i + 1] == ("op", "=")
                and (i == 0 or toks[i - 1][1] not in (".", ":")) and v not in locals_):
            if i + 2 < n and toks[i + 2] != ("op", "="):
                defined[v] += 1
    i = 0
    while i < n:
        k, v = toks[i]
        if k == "name" and v not in KEYWORDS and (i == 0 or toks[i - 1][1] not in (".", ":", "function")):
            chain = v
            j = i + 1
            while j + 1 < n and toks[j][1] in (".", ":") and toks[j + 1][0] == "name":
                chain += toks[j][1] + toks[j + 1][1]
                j += 2
            if j < n and (toks[j] == ("op", "(") or toks[j][0] == "str" or toks[j] == ("op", "{")):
                root = re.split(r"[.:]", chain)[0]
                if root not in locals_:
                    calls[chain] += 1
            i = j
        else:
            i += 1
    return calls, defined


def main():
    root = "build/rcf"
    out = "build/lua/calls.json"
    a = sys.argv[1:]
    while a:
        if a[0] == "--root":
            root = a[1]
        elif a[0] == "--out":
            out = a[1]
        a = a[2:]
    tgt = defaultdict(lambda: {"count": 0, "scripts": set(), "groups": Counter(), "kinds": Counter()})
    sets = defaultdict(lambda: {"count": 0, "scripts": set(), "groups": Counter()})
    gets = Counter()
    nscripts = Counter()
    errors = []

    def add(name, cnt, script, grp, kind):
        t = tgt[name]
        t["count"] += cnt
        t["scripts"].add(script)
        t["groups"][grp] += cnt
        t["kinds"][kind] += cnt

    def add_set(name, cnt, script, grp):
        t = sets[name]
        t["count"] += cnt
        t["scripts"].add(script)
        t["groups"][grp] += cnt

    for dp, _, fns in os.walk(root):
        for fn in sorted(fns):
            p = os.path.join(dp, fn)
            rel = os.path.relpath(p, root)
            grp = group_of(rel)
            ext = fn.rsplit(".", 1)[-1]
            if ext not in ("lua", "obj", "fig"):
                continue
            data = open(p, "rb").read()
            try:
                if data[:4] == b"\x1bLua":
                    _, f = L.load_chunk(data)
                    c, s, g = bytecode_calls(f)
                    nscripts[(grp, "bytecode")] += 1
                    for k, v in c.items():
                        add(k, v, rel, grp, "bytecode")
                    for k, v in s.items():
                        add_set(k, v, rel, grp)
                    gets.update(g)
                elif ext == "fig":
                    cnt = 0
                    for off, _, f in L.iter_embedded(data):
                        c, s, g = bytecode_calls(f)
                        cnt += 1
                        for k, v in c.items():
                            add(k, v, rel, grp, "fig-embedded")
                        for k, v in s.items():
                            add_set(k, v, rel, grp)
                        gets.update(g)
                    if cnt:
                        nscripts[(grp, "fig-embedded")] += 1
                elif ext == "lua":
                    src = data.decode("latin-1")
                    c, d = text_calls(src)
                    nscripts[(grp, "text")] += 1
                    for k, v in c.items():
                        add(k, v, rel, grp, "text")
                    for k, v in d.items():
                        add_set(k, v, rel, grp)
            except L.LuaError as e:
                errors.append((rel, str(e)))
    res = {
        "calls": {k: {"count": v["count"], "scripts": len(v["scripts"]),
                      "groups": dict(v["groups"]), "kinds": dict(v["kinds"])}
                  for k, v in sorted(tgt.items(), key=lambda kv: -kv[1]["count"])},
        "defined_globals": {k: {"count": v["count"], "scripts": len(v["scripts"]),
                                "groups": dict(v["groups"])}
                            for k, v in sorted(sets.items(), key=lambda kv: -kv[1]["count"])},
        "globals_read": dict(gets.most_common()),
        "script_counts": {"%s|%s" % k: v for k, v in sorted(nscripts.items())},
        "errors": errors,
    }
    os.makedirs(os.path.dirname(out), exist_ok=True)
    json.dump(res, open(out, "w"), indent=1)
    print("call targets:", len(res["calls"]), " defined globals:", len(res["defined_globals"]),
          " errors:", len(errors))
    for k, v in list(res["calls"].items())[:30]:
        print("%7d %4d  %s" % (v["count"], v["scripts"], k))


if __name__ == "__main__":
    main()
