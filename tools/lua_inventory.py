#!/usr/bin/env python3
"""Cross-reference script call targets (tools/lua_bindings.py -> build/lua/calls.json)
with the C++ binding table recovered from the XBE (tools/lua_regs.py -> build/lua/regs.json)
and with decompilation status (matches/, equivalent/, farm proof directories).

Writes build/lua/inventory.json and (with --csv) docs/lua-bindings.csv, and prints a summary.
No script content is emitted: names, counts, group names, addresses, status.

usage: tools/lua_inventory.py [--csv docs/lua-bindings.csv]
"""
import bisect
import csv
import json
import os
import sys
from collections import Counter, defaultdict

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
B = lambda *p: os.path.join(ROOT, *p)

# Globals created directly by ScriptHandler::CreateState (0x001d3c90), not through Registry::Add:
# name -> (C function, note)
ENGINE_EXTRA = {
    "debug": 0x001D2000,   # lua_pushcclosure + settable "debug" in CreateState
    "cdebug": 0x001D2020,  # same, "cdebug"
    "Vector": 0x001D07B0,  # Vector userdata type setup (metatable, x/y/z); helpers 0x1d05a0-0x1d0870
}

STDLIBS = {"table", "string", "math", "coroutine", "debug", "io", "os"}


def status_of(addr):
    n = "0x%08x.cpp" % addr
    if os.path.exists(B("matches", n)):
        return "matches"
    if os.path.exists(B("equivalent", n)):
        return "equivalent"
    if os.path.exists(B("build/farm/bench/claude-equiv/pass", n)):
        return "proved-unpromoted"
    return "unverified"


def lib_name(entries):
    names = {e[0] for e in entries}
    for key, lib in (("getinfo", "debug"), ("getn", "table"), ("sin", "math"),
                     ("reverse", "string"), ("setmetatable", "base"),
                     ("resume", "coroutine"), ("timems", "base")):
        if key in names:
            return lib
    return None


def main():
    csv_out = None
    if "--csv" in sys.argv:
        csv_out = sys.argv[sys.argv.index("--csv") + 1]
    calls = json.load(open(B("build/lua/calls.json")))
    regs = json.load(open(B("build/lua/regs.json")))
    funcs = sorted(int(r["address"], 16) for r in csv.DictReader(open(B("build/functions.csv"))))

    def owner_fn(a):
        return funcs[bisect.bisect_right(funcs, a) - 1]

    bind = dict(regs["bindings"])
    for nm, fn in ENGINE_EXTRA.items():
        bind[nm] = {"fn": fn, "site": 0x001D3C90, "shape": "S"}
    libs = defaultdict(dict)
    for l in regs["libs"]:
        ln = lib_name(l["entries"])
        if ln:
            for nm, fn in l["entries"]:
                libs[ln][nm] = fn
    defined = calls["defined_globals"]
    used = calls["calls"]

    rows = []
    for name, v in bind.items():
        u = used.get(name)
        reg_site = owner_fn(v["site"])
        rows.append({
            "name": name, "fn": v["fn"], "registrar": reg_site, "shape": v["shape"],
            "calls": u["count"] if u else 0, "scripts": u["scripts"] if u else 0,
            "groups": sorted(u["groups"], key=lambda g: -u["groups"][g]) if u else [],
            "fn_status": status_of(v["fn"]), "registrar_status": status_of(reg_site),
        })
    rows.sort(key=lambda r: (-r["calls"], r["name"]))

    used_bound = [r for r in rows if r["calls"]]
    bound_unused = [r for r in rows if not r["calls"]]
    base_lib = libs.get("base", {})
    used_unbound = []
    stdlib_used = []
    script_tables = []
    method_calls = []
    script_defined = []
    for name, v in used.items():
        if name in bind:
            continue
        root = name.replace(":", ".").split(".")[0]
        leaf = name.replace(":", ".").split(".")[-1]
        if ":" in name:
            method_calls.append((name, v))
        elif "." in name and root in STDLIBS and libs.get(root, {}).get(leaf) \
                and name.count(".") == 1:
            stdlib_used.append((name, v, libs[root][leaf]))
        elif "." in name:
            script_tables.append((name, v))
        elif name in base_lib:
            stdlib_used.append((name, v, base_lib[name]))
        elif name in defined:
            script_defined.append((name, v))
        else:
            used_unbound.append((name, v))

    res = {
        "used_bound": used_bound, "bound_unused": bound_unused,
        "used_unbound": [(n, v["count"], v["scripts"]) for n, v in used_unbound],
        "script_defined": [(n, v["count"]) for n, v in script_defined],
        "stdlib_used": [(n, v["count"], fn) for n, v, fn in stdlib_used],
        "script_tables": [(n, v["count"]) for n, v in script_tables],
        "method_calls": [(n, v["count"]) for n, v in method_calls],
        "libs": {k: v for k, v in libs.items()},
    }
    json.dump(res, open(B("build/lua/inventory.json"), "w"), indent=1)

    if csv_out:
        with open(B(csv_out), "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["name", "bound_fn", "registrar", "calls", "scripts", "fn_status", "registrar_status", "top_groups"])
            for r in rows:
                w.writerow([r["name"], "0x%08x" % r["fn"], "0x%08x" % r["registrar"], r["calls"], r["scripts"],
                            r["fn_status"], r["registrar_status"], ";".join(r["groups"][:3])])

    st = Counter(r["fn_status"] for r in rows)
    print("bound names: %d; used&bound %d; bound-unused %d; used-unbound (unresolved) %d" % (
        len(rows), len(used_bound), len(bound_unused), len(used_unbound)))
    print("script-defined callees %d; script-table/method callees %d / %d; stdlib callees %d" % (
        len(script_defined), len(script_tables), len(method_calls), len(stdlib_used)))
    print("fn status (all bound):", dict(st))
    print("fn status (used&bound):", dict(Counter(r["fn_status"] for r in used_bound)))
    print("registrar status:", dict(Counter(r["registrar_status"] for r in rows)))
    print("-- unresolved top:")
    for n, v in sorted(used_unbound, key=lambda x: -x[1]["count"])[:40]:
        print("  %5d %s" % (v["count"], n))
    print("-- top 20 bindings:")
    for r in used_bound[:20]:
        print("  %6d 0x%08x %-12s %s" % (r["calls"], r["fn"], r["fn_status"], r["name"]))


if __name__ == "__main__":
    main()
