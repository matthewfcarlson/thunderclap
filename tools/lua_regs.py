#!/usr/bin/env python3
"""Recover the C++ -> Lua binding table from default.xbe.

The game does not use the stock lua_register: script bindings are objects
(Method<n>/Closure<n> templates) registered with Registry::Add = FUN_001d3b70(name, obj)
which does lua_pushlightuserdata/lua_pushcclosure(FUN_001d22a0 thunk, 1 upvalue)/
lua_settable(GLOBALS).  This tool finds every registration site in .text and
reports name -> bound C++ function address.  It handles:

  G  inline Method/Closure constructors: Base ctor FUN_001d0480(name, nargs),
     function pointer stored at [obj+0x1c], then FUN_001d3b70
  X  out-of-line registration: any call (Entry ctor, Registry::Register* helper
     with a name and function pointer) whose pending pushes include an
     identifier string and a .text address, inside a function that registers
     bindings or calls a registration helper

It also scans the data sections for luaL_reg-style {name, cfunction} arrays
(standard library tables: table.*, string.*, math.*, ...).

usage: build/venv/bin/python tools/lua_regs.py [--out build/lua/regs.json]
"""
import csv
import json
import os
import re
import struct
import sys
from collections import defaultdict

import capstone

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
from xbe import Xbe  # noqa: E402

REG_ADD = 0x1D3B70   # Registry::Add(name, binding)
LUA_SETTABLE = 0x213790  # lua_settable-like (index, key) used by the inline Add
BASE_CTOR = 0x1D0480  # Method base ctor (name, nargs)
GAME_TEXT_END = 0x364840
IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def main():
    out = os.path.join(ROOT, "build/lua/regs.json")
    if "--out" in sys.argv:
        out = sys.argv[sys.argv.index("--out") + 1]
    xbe = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
    funcs = {}
    with open(os.path.join(ROOT, "build/functions.csv")) as f:
        for r in csv.DictReader(f):
            funcs[int(r["address"], 16)] = int(r["size"])
    addrs = sorted(funcs)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = False

    def is_text(v):
        return 0x11000 <= v < GAME_TEXT_END

    def identstr(v):
        if v < 0x11000 or xbe.section_of(v) is None or is_text(v):
            return None
        s = xbe.cstr(v, 80)
        return s if s and IDENT.match(s) else None

    # pass 1: disassemble, find callers of REG_ADD and of its small wrappers
    prog = {}
    callers = defaultdict(set)
    for a in addrs:
        if a >= GAME_TEXT_END:
            continue
        o = xbe.offset(a)
        if o is None:
            continue
        ins = []
        for i in md.disasm(xbe.data[o:o + funcs[a]], a):
            ins.append((i.address, i.mnemonic, i.op_str))
            if i.mnemonic == "call":
                m = re.match(r"0x([0-9a-f]+)$", i.op_str)
                if m:
                    callers[int(m.group(1), 16)].add(a)
        prog[a] = ins
    direct = callers[REG_ADD]
    # helpers: functions that call Registry::Add with a name/function that came in as
    # parameters (no identifier string pushed anywhere in the body)
    def pushes_ident(a):
        for _, mn, ops in prog[a]:
            if mn == "push":
                m = re.match(r"(0x[0-9a-f]+)$", ops)
                if m and identstr(int(m.group(1), 16)):
                    return True
        return False
    helpers = {a for a in direct if not pushes_ident(a)}
    helper_callers = set()
    for h in helpers:
        helper_callers |= callers[h]
    # constructors that open-code Registry::Add (lua_pushcclosure + lua_settable inline)
    inline_add = callers[BASE_CTOR] & callers[LUA_SETTABLE]
    targets = (direct | helper_callers | inline_add) - helpers
    print("funcs calling Registry::Add: %d (helpers: %d, their callers: %d)"
          % (len(direct), len(helpers), len(helper_callers)))

    results = {}   # name -> record

    def record(name, fn, site, shape, callee=None):
        r = results.get(name)
        if r is None:
            results[name] = {"name": name, "fn": fn, "site": site, "shape": shape, "dups": []}
        elif (r["fn"], r["site"]) != (fn, site):
            r["dups"].append({"fn": fn, "site": site, "shape": shape})

    for a in sorted(targets):
        calls = [(i, t) for i, (_, mn, t) in enumerate(prog[a]) if mn == "call"]
        nxt = {}
        for k, (i, t) in enumerate(calls):
            nxt[i] = calls[k + 1][1] if k + 1 < len(calls) else None
        pend = []
        gname = None
        gfn = None
        for idx, (addr, mn, ops) in enumerate(prog[a]):
            if mn == "push":
                m = re.match(r"(0x[0-9a-f]+|\d+)$", ops)
                pend.append(int(m.group(1), 0) if m else None)
                continue
            m = re.match(r"dword ptr \[(\w+) \+ 0x1c\], (0x[0-9a-f]+)$", ops)
            if mn == "mov" and m and is_text(int(m.group(2), 16)):
                gfn = int(m.group(2), 16)
            if mn == "call":
                tm = re.match(r"0x([0-9a-f]+)$", ops)
                tgt = int(tm.group(1), 16) if tm else None
                if tgt == BASE_CTOR:
                    # pushes (right to left): nargs, name
                    # last push = first arg
                    cand = [identstr(v) for v in reversed(pend[-3:]) if v is not None]
                    cand = [c for c in cand if c]
                    gname = cand[0] if cand else None
                    gfn = None
                elif tgt in (REG_ADD, LUA_SETTABLE):
                    if gname and gfn:
                        record(gname, gfn, addr, "G")
                    gname = gfn = None
                else:
                    names = [(identstr(v), v) for v in pend if v is not None]
                    names = [n for n, _ in names if n]
                    fns = [v for v in pend if v is not None and is_text(v)]
                    if (names and fns and tgt not in (BASE_CTOR,)
                            and (tgt in helpers or nxt.get(idx) == "0x%x" % REG_ADD)):
                        record(names[-1], fns[-1] if len(fns) == 1 else fns[0], addr, "X", tgt)
                pend = []
            elif mn in ("ret", "jmp") or mn.startswith("j"):
                if mn == "ret":
                    pend = []

    # luaL_reg-style arrays: consecutive {char* name, fn} pairs in data sections
    lib_entries = []
    for sec in xbe.sections:
        if sec.executable:
            continue
        va0 = sec.va
        o0 = xbe.offset(va0)
        if o0 is None:
            continue
        data = xbe.data[o0:o0 + min(sec.vsize, sec.rsize)]
        n = len(data) // 4
        words = struct.unpack("<%dI" % n, data[:n * 4])
        i = 0
        while i + 1 < n:
            run = []
            j = i
            while j + 1 < n:
                nm = identstr(words[j]) if words[j] else None
                if nm and is_text(words[j + 1]):
                    run.append((nm, words[j + 1], va0 + 4 * j))
                    j += 2
                else:
                    break
            if len(run) >= 3:
                lib_entries.append({"va": run[0][2], "entries": [(a, b) for a, b, _ in run],
                                    "end_null": j + 1 < n and words[j] == 0 and words[j + 1] == 0})
                i = j
            else:
                i += 1
    json.dump({"bindings": results, "libs": lib_entries,
               "registrars": sorted(hex(a) for a in targets),
               "helpers": sorted(hex(a) for a in helpers)},
              open(out, "w"), indent=1)
    print("bindings: %d  (G %d, X %d)  lib arrays: %d" % (
        len(results), sum(1 for r in results.values() if r["shape"] == "G"),
        sum(1 for r in results.values() if r["shape"] == "X"), len(lib_entries)))


if __name__ == "__main__":
    main()
