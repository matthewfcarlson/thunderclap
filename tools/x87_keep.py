#!/usr/bin/env python3
"""x87_keep.py [--snap DIR] [--map MAP] [--out FILE]: the functions the SSE Wine build (HULK_WINE_FLOAT=sse) keeps as x87 code.

The Wine build's sin, cos, tan, atan, atan2, exp, asin, acos, log, log10 and pow return the 80-bit x87 result in st(0),
as the original's inlined fsin/fpatan/... leave it, and x87 code computes on with it; SSE code would store it to a double
first (a second rounding: play3 diverged at frame 450 in CChaseCamera's 0x000a04c0, at 780 elsewhere). So these stay x87:
every function that calls one of them, and, to a fixpoint, every function that uses the floating-point result of a call
to an x87 function returning float or double (it returns st(0) unrounded: 0x000fce60's call of 0x00224ea0). Callees are
matched by address through an image's link map (MAP: any recent Wine image of the same sources), else by FUN_ name.
Indirect calls are not followed (no virtual function returns such a value today). Writes one IR function name per line.
"""
import argparse, json, os, re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
os.environ["HULK_WINE_FLOAT"] = "sse"
import clang_probe as cp  # noqa: E402
ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
ap.add_argument("--snap", default=cp.SNAP)
ap.add_argument("--map", default=os.path.join(ROOT, "build/native/link/hulk-strict.map"))
ap.add_argument("--out", default=cp.X87_KEEP)
ap.add_argument("--jobs", type=int, default=4)
a = ap.parse_args()
flags = [f for f in cp.CONFIGS["msvc"]["flags"] + cp.COMMON if f != "-c"] + ["-S", "-emit-llvm", "-w"]
clang = cp.tool("clang++")
tus = [t["path"] for t in json.load(open(os.path.join(a.snap, "manifest.json")))["tus"]]
MATH = set(cp._X87_FNS)
DEF = re.compile(r'^define [^@]*?(float|double|void|i\d+|ptr|\{[^}]*\}|%[\w.]+|x86_fp80)? ?@("[^"]+"|[\w.$?@]+)\(')
CALL = re.compile(r'(?:%[\w.]+ = )?(?:tail )?call [^@]*?(float|double|void|i\d+|ptr|%[\w."]+)? ?@("[^"]+"|[\w.$?@]+)\(')


def scan(rel):
    r = subprocess.run([clang] + flags + ["-I" + a.snap + "/include", "-I" + a.snap + "/repo-include",
                        os.path.join(a.snap, rel), "-o", "-"], capture_output=True, text=True, errors="replace")
    fns, cur = {}, None
    for l in r.stdout.split("\n"):
        m = DEF.match(l)
        if m:
            cur = m.group(2).strip('"')
            fns[cur] = {"ret": m.group(1) or "", "calls": set()}
        elif cur and l == "}":
            cur = None
        elif cur:
            for m in CALL.finditer(l):
                if (m.group(1) or "") in ("float", "double") or m.group(2).strip('"') in MATH:
                    fns[cur]["calls"].add((m.group(2).strip('"'), m.group(1) or ""))
    return fns


allf = {}
with ThreadPoolExecutor(a.jobs) as ex:
    for fns in ex.map(scan, tus):
        for k, v in fns.items():
            allf.setdefault(k, v)
addr = {}
if os.path.exists(a.map):
    for l in open(a.map, errors="replace"):
        m = re.match(r"\s*0001:[0-9a-f]+\s+(\S+)\s+([0-9a-f]{16})", l)
        if m:
            addr[m.group(1)] = m.group(2)


def key(n):
    for c in (n, "_" + n):
        if c in addr:
            return addr[c]
    m = re.search(r"FUN_([0-9a-f]{8})", n)
    return m.group(1) if m else n


keep = {n for n, v in allf.items() if any(c in MATH for c, _ in v["calls"])}
while True:
    ext = {key(n) for n in keep if allf[n]["ret"] in ("float", "double")}
    more = {n for n, v in allf.items() if n not in keep and any(rt in ("float", "double") and key(c) in ext for c, rt in v["calls"])}
    if not more:
        break
    keep |= more
os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
open(a.out, "w").write("\n".join(sorted(keep)) + "\n")
print("%d functions, %d kept as x87 -> %s" % (len(allf), len(keep), a.out))
