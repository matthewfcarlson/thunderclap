#!/usr/bin/env python3
"""Platform-shim and CRT inventory of the native link (docs/native-build.md "Start-up milestone").

  build/venv/bin/python tools/native_shim.py          # after tools/native_link.py: build/native/shim-inventory.json

What the linked image still needs from outside the tree, from tools/native_link.py's build/native/unbound.txt
(symbols still undefined after binding) and bindings.json (the XBE address each one stands for), sorted by
tools/platform_map.py's subsystems (build/port/platform_calls.json: library targets by address, library data by
name / address, kernel imports). One row per library function (by address): the names the tree calls it by,
symbols, references, and the library region it lives in (D3D, DSOUND, XAPI, XPP, BINK, XGRPH, LIBC, kernel).

Groups covered: platform imports, CRT / C++ runtime, library data. The other groups (unverified functions,
stub names at unverified addresses, ...) are sized by native_link.py's report.json.
"""
import collections
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
NATIVE = os.path.join(ROOT, "build/native")
GROUPS = {"platform import": "platform", "CRT / C++ runtime": "crt", "data: library": "library data"}
ADDR_RX = re.compile(r"(?:FUN|DAT|thunk_FUN|PTR|LAB)_(00[0-9a-fA-F]{6})(?![0-9a-fA-F])")
SIMPLE = re.compile(r"(?:^|::)(~?[A-Za-z_]\w*)(?:<.*>)?\s*\(")


def simple_name(sym, dem):
    if dem and "(" not in dem:
        return dem
    m = SIMPLE.search(dem or "")
    if m:
        return m.group(1)
    s = sym.lstrip("_?").split("@")[0]
    return s


def main():
    pc = json.load(open(os.path.join(ROOT, "build/port/platform_calls.json")))
    by_addr = {}
    for k, v in pc["targets"].items():
        by_addr[int(v["address"], 16)] = (k.split("!")[-1], v["region"], v["subsystem"])
    by_name = {k.split("!")[-1]: v for k, v in pc["targets"].items()}
    data_sub = {}
    for k, v in pc["data_refs"].items():
        data_sub[k.split("!")[-1]] = v["subsystem"]
        m = ADDR_RX.search(k)
        if m:
            data_sub[int(m.group(1), 16)] = v["subsystem"]
    kernel = {int(a, 16): n.split(":")[-1] for a, n in pc["kernel_imports"].items()}
    spans = [(int(s["start"], 16), int(s["end"], 16), s["label"]) for s in pc["lib_spans_in_text"]]
    bind = json.load(open(os.path.join(NATIVE, "bindings.json")))["bindings"]
    rows = collections.defaultdict(lambda: {"names": set(), "symbols": 0, "references": 0})
    for line in open(os.path.join(NATIVE, "unbound.txt"), encoding="utf-8", errors="replace"):
        g, n, sym, dem = (line.rstrip("\n").split("\t") + [""])[:4]
        grp = next((v for k, v in GROUPS.items() if g.startswith(k)), None)
        if grp is None:
            continue
        b = bind.get(sym)
        a = int(b["addr"], 16) if b else None
        if a is None:
            m = ADDR_RX.search(sym)
            a = int(m.group(1), 16) if m else None
        name = simple_name(sym, dem)
        if grp == "library data":
            sub = data_sub.get(a) or data_sub.get(name) or data_sub.get(sym.lstrip("_"))
            if sub is None and a in kernel:
                sub, name = "kernel import slot", kernel[a]
            sub = sub or "library data (unsorted)"
            region = next((lab for lo, hi, lab in spans if a is not None and lo <= a < hi), "data")
            key = (grp, sub, region, a if a is not None else name)
        else:
            t = by_addr.get(a) if a is not None else None
            if t is None and name in by_name:
                v = by_name[name]
                t = (name, v["region"], v["subsystem"])
                a = int(v["address"], 16)
            if t is None and a in kernel:
                t = (kernel[a], "kernel", "kernel")
            if t is None:
                region = next((lab for lo, hi, lab in spans if a is not None and lo <= a < hi), "?")
                t = (name, region, "CRT / C++ runtime" if grp == "crt" else "unsorted")
            key = (grp, t[2], t[1], a if a is not None else name)
            name = t[0] if not t[0].startswith("FUN_") else name
        r = rows[key]
        r["names"].add(name)
        r["symbols"] += 1
        r["references"] += int(n)
    out = []
    for (grp, sub, region, a), r in sorted(rows.items(), key=lambda kv: (kv[0][0], kv[0][1], kv[0][2], str(kv[0][3]))):
        out.append({"group": grp, "subsystem": sub, "region": region,
                    "addr": "0x%08x" % a if isinstance(a, int) else None, "names": sorted(r["names"]),
                    "symbols": r["symbols"], "references": r["references"]})
    summ = collections.defaultdict(lambda: [0, 0, 0])
    for o in out:
        s = summ[(o["group"], o["subsystem"])]
        s[0] += 1
        s[1] += o["symbols"]
        s[2] += o["references"]
    with open(os.path.join(NATIVE, "shim-inventory.json"), "w") as f:
        json.dump({"summary": [{"group": g, "subsystem": s, "functions": v[0], "symbols": v[1], "references": v[2]}
                               for (g, s), v in sorted(summ.items())], "rows": out}, f, indent=1)
    print("%-14s %-24s %9s %8s %6s" % ("group", "subsystem", "functions", "symbols", "refs"))
    for (g, s), v in sorted(summ.items()):
        print("%-14s %-24s %9d %8d %6d" % (g, s, v[0], v[1], v[2]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
