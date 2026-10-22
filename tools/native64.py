#!/usr/bin/env python3
"""64-bit probe of the source tree: how far it is from a 64-bit native image (docs/wine-build.md "64-bit").

  build/venv/bin/python tools/native64.py                 # compile (msvc64, arm64, gnu64, gnu32w), classify, link probe
  build/venv/bin/python tools/native64.py --no-link       # compile and classify only
  build/venv/bin/python tools/native64.py --configs msvc64 --jobs 6
  # on another tree (as tools/clang_probe.py): HULK_CLANG_PROBE_DIR=<dir with snap/> HULK_CLANG_PROBE_CACHE=<cache>

Runs on tools/clang_probe.py's snapshot (`snap/`, made by `clang_probe.py --snapshot` from a complete
tools/build_tree.py run) and its per-TU cache; nothing in the repo or in build/tree/ changes. Targets:

  msvc64   x86_64-pc-windows-msvc (MS ABI, LLP64: `long` stays 32-bit): objects, linked below (Wine runs x64 PEs)
  arm64    arm64-apple-darwin (Itanium ABI, LP64: `long` is 64-bit), syntax only
  gnu64    x86_64-unknown-linux-gnu (Itanium, LP64), syntax only (the 2026-10-17 configuration)
  gnu32w   i686 with the same truncation warnings: sites that warn here too are `__int64` narrowed on purpose on
           every target, not pointer-width ones, and are subtracted from msvc64's / arm64's `64bit-shorten`

Classes reported (build/native64/report.json, summary on stdout):

  errors           per clang_probe category, per configuration (what stops a TU compiling)
  pointer-int      `(int)p`, `(T*)i`: a pointer through a 32-bit integer (wrong on every 64-bit target)
  shorten          implicit 64 -> 32-bit narrowing (`int n = p - q;`, `int i = sizeof(x);`) not seen on i686
  explicit pads    `char pad[N]` in sources and `_pad_` gaps in include/gen/: offsets fixed for 4-byte pointers
  layout           include/gen/ and include/decls/data/ records whose field offsets move on 64-bit (tools/layout64.py)
  link             the msvc64 objects linked with no bridge (lld-link /machine:x64): undefined symbols by
                   clang_probe's groups, duplicate definitions; what each 32-bit bridge of wine_link.py
                   leaves for source to do (docs/wine-build.md "64-bit", per-bridge table)
"""
import argparse
import collections
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import clang_probe as cp  # noqa: E402

ROOT = cp.ROOT
OUT = os.environ.get("HULK_NATIVE64_DIR") or os.path.join(ROOT, "build/native64")
CONFIGS = ["msvc64", "arm64", "gnu64", "gnu32w"]
SIXTY4 = ("64bit-pointer-int-cast", "64bit-shorten")


def compile_configs(cfgs, jobs):
    clang = cp.tool("clang++")
    if not os.path.exists(os.path.join(cp.SNAP, "manifest.json")):
        sys.exit("no snapshot: run tools/clang_probe.py --snapshot first (or set HULK_CLANG_PROBE_DIR)")
    digest = cp.include_digest(cp.SNAP)
    tus = cp.tu_list()
    results = {}
    for cfg in cfgs:
        paths = tus + (cp.data_tus() if cp.CONFIGS[cfg]["obj"] else [])
        results[cfg] = cp.compile_all(cfg, paths, jobs, clang, digest)
        ok = sum(1 for p in tus if results[cfg][p]["rc"] == 0)
        print("%s: %d / %d TUs compile" % (cfg, ok, len(tus)), flush=True)
    return tus, results


def sites(res, tus, cat):
    """{(file, line)} of one category's diagnostics."""
    out = set()
    for p in tus:
        for f, line, sev, msg, opt in res[p]["diags"]:
            if cp.classify(sev, msg) == cat:
                out.add((f, line))
    return out


def sixty4_classes(results, tus, man):
    """Pointer-width warnings per configuration, net of the ones i686 has too."""
    base = sites(results["gnu32w"], tus, "64bit-shorten") if "gnu32w" in results else set()
    out = {}
    for cfg, res in results.items():
        if cfg == "gnu32w":
            continue
        row = {}
        for cat in SIXTY4:
            s = sites(res, tus, cat)
            if cat == "64bit-shorten":
                s -= base
            srcs = collections.Counter()
            prods = collections.Counter()
            for f, line in s:
                prod, src = man.producer(f, line)
                prods[prod] += 1
                if src and src.startswith(("matches/", "equivalent/")):
                    srcs[src] += 1
            row[cat] = {"sites": len(s), "sources": len(srcs), "producers": dict(prods.most_common()),
                        "top_sources": srcs.most_common(8)}
            if cat == "64bit-pointer-int-cast":
                # direction: a pointer kept in an integer (`(int)p`: the field or variable wants a pointer type)
                # or an integer used as a pointer (`(T*)i`: where the integer came from wants one)
                d = collections.Counter()
                for p in tus:
                    for f, line, sev, msg, opt in res[p]["diags"]:
                        if cp.classify(sev, msg) == cat:
                            d["pointer -> integer" if "cast to smaller integer type" in msg else
                              "integer -> pointer"] += 1
                row[cat]["direction (occurrences)"] = dict(d)
        out[cfg] = row
    if "gnu32w" in results:
        out["gnu32w"] = {"64bit-shorten (i686 too: __int64 narrowed on purpose)": len(base)}
    return out


# ---------------------------------------------------------------------------------------------
# The 64-bit link probe: msvc64 objects, no bridges
def site_list(results, tus, man, path):
    """JSON lines of every pointer-width site (class, tree file:line, the source it comes from) of msvc64, net of
    i686's `__int64` narrowing: the work list for tools/ptr1.py (which works on the sources themselves)."""
    base = sites(results["gnu32w"], tus, "64bit-shorten") if "gnu32w" in results else set()
    with open(path, "w") as out:
        for cat in SIXTY4:
            s = sites(results["msvc64"], tus, cat)
            if cat == "64bit-shorten":
                s -= base
            for f, line in sorted(s):
                prod, src = man.producer(f, line)
                out.write(json.dumps({"class": cat, "tree_file": f, "line": line, "producer": prod,
                                      "source": src}) + "\n")


def link64(results, tus, man, do_link=True, bindings=None):
    res = results["msvc64"]
    objs = sorted(r["obj"] for r in res.values() if r.get("obj"))
    syms = cp.nm(objs)
    defined = collections.Counter()
    for d, u in syms.values():
        for s in d:
            defined[s] += 1
    refs = collections.Counter()
    for d, u in syms.values():
        for s in u:
            refs[s] += 1
    undef = {s for s in refs if s not in defined and not s.startswith(("@feat", "__imp_"))}
    ok_tus = {p for p in tus if res[p]["rc"] == 0}
    dem = cp.undname(sorted(undef))
    gr = cp.Grouper(man, ok_tus)
    groups = collections.defaultdict(lambda: {"symbols": 0, "references": 0, "examples": []})
    for s in sorted(undef):
        g, _ = gr.group(s, dem.get(s, s))
        G = groups[g]
        G["symbols"] += 1
        G["references"] += refs[s]
        if len(G["examples"]) < 5:
            G["examples"].append(dem.get(s, s))
    rep = {"objects": len(objs), "code_tus": len(ok_tus), "undefined_symbols": len(undef),
           "undefined_references": sum(refs[s] for s in undef),
           "groups": dict(sorted(groups.items(), key=lambda kv: -kv[1]["symbols"])),
           # the shapes the 32-bit bridges act on, counted in the 64-bit objects
           "bridge_shapes": bridge_shapes(undef, dem, defined)}
    if bindings and os.path.exists(bindings):
        rep["binding_transfer"] = binding_transfer(undef, dem, defined, bindings)
    if do_link:
        rep["lld_link"] = lld_link64(objs)
    return rep


CC_RX = re.compile(r"\b__(?:cdecl|thiscall|stdcall|fastcall|ptr64)\b")


def norm(d):
    """A demangled name without what differs between i686 and x86-64 (conventions, __ptr64)."""
    return re.sub(r"\s+", " ", CC_RX.sub("", d)).replace(" ,", ",").replace(" )", ")").strip()


def binding_transfer(undef, dem, defined, path):
    """How many of the 64-bit link's undefined symbols the 32-bit link's binding map would resolve, matched by
    demangled name (tools/wine_link.py's map is names -> address -> definition name; no game bytes travel with
    it). An estimate of what reusing the map as a name table would do on 64-bit: an interim, not a bridge to keep."""
    b = json.load(open(path))
    defs = b["definitions"]
    want32 = set()
    for s, v in b["bindings"].items():
        d = defs.get(v["addr"])
        if d:
            want32 |= {s, d}
    dem32 = cp.undname(sorted(want32))
    by_norm = {}
    for s, v in b["bindings"].items():
        d = defs.get(v["addr"])
        if d:
            by_norm[norm(dem32.get(s, s))] = norm(dem32.get(d, d))
    dem_def = cp.undname(sorted(s for s in defined if s.startswith("?")))
    def_norm = {norm(dem_def.get(s, s)) for s in defined}
    c = collections.Counter()
    for s in undef:
        n = norm(dem.get(s, s))
        t = by_norm.get(n) or by_norm.get(n.lstrip("_"))
        if t is None:
            c["no 32-bit binding under this name"] += 1
        elif t in def_norm or t.lstrip("_") in def_norm:
            c["bound: the definition exists in the 64-bit objects"] += 1
        else:
            c["bound, but the definition's 64-bit name differs"] += 1
    return dict(c.most_common())


def bridge_shapes(undef, dem, defined):
    """Undefined symbols of the kinds the 32-bit link's bridges resolve (docs/wine-build.md "Bridges to remove"):
    what is left for source to provide on 64-bit."""
    c = collections.Counter()
    for s in undef:
        d = dem.get(s, s)
        if s.startswith("??_R0") or "RTTI Type Descriptor" in d:
            c["RTTI type descriptors (32-bit: redirected to the game's TDs)"] += 1
        elif s.startswith("??_7") or "vftable" in d:
            c["vftables (32-bit: stub vftables pointed at the game's)"] += 1
        elif re.search(r"(?:^|[^0-9A-Za-z])hulk_at_|(?:^|[^0-9A-Za-z_])_?DAT_00[0-9a-f]{6}", s):
            c["data by XBE address (hulk_at_ / DAT_ outside the data TUs)"] += 1
        elif re.search(r"FUN_00[0-9a-f]{6}", s):
            c["functions by address (FUN_)"] += 1
        elif s.startswith("?") and re.search(r"@fn_00[0-9a-f]{6}@", s):
            c["declared in a wrapped namespace fn_<addr> (32-bit: bound by relocation position)"] += 1
        elif s.startswith("?"):
            c["C++ names (stub members, other signatures; 32-bit: bound by relocation position)"] += 1
        else:
            c["C names"] += 1
    return dict(c.most_common())


def lld_link64(objs):
    lld = cp.tool("lld-link")
    if not lld:
        return {"status": "lld-link not found"}
    os.makedirs(OUT, exist_ok=True)
    rsp = os.path.join(OUT, "objects.rsp")
    with open(rsp, "w") as f:
        f.write("\n".join('"%s"' % o for o in objs) + "\n")
    cmd = [lld, "/nologo", "/machine:x64", "/subsystem:console", "/entry:hulk_native_entry", "/nodefaultlib",
           "/errorlimit:0", "/out:" + os.path.join(OUT, "hulk64.exe"), "@" + rsp]
    r = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    with open(os.path.join(OUT, "lld-link.log"), "w") as f:
        f.write(r.stdout + r.stderr)
    kinds = collections.Counter()
    for line in (r.stdout + r.stderr).splitlines():
        m = re.match(r"lld-link: (error|warning): (.*)", line)
        if m:
            k = re.sub(r":.*", "", m.group(2))
            k = re.sub(r"'[^']*'|\S+\.obj|0x[0-9a-f]+", "X", k)[:80]
            kinds["%s: %s" % (m.group(1), k)] += 1
    return {"rc": r.returncode, "messages": dict(kinds.most_common(20))}


# ---------------------------------------------------------------------------------------------
def pad_scan(man, tus):
    s = cp.scans(man, tus)
    return {"explicit-padding (sources, tree TUs)": {k: s["explicit-padding"][k] for k in ("occurrences", "tus", "sources")},
            "include/gen": s["include-gen-layout"],
            "type-pun-cast": {k: s["type-pun-cast"][k] for k in ("occurrences", "sources")},
            "manual-virtual-call": {k: s["manual-virtual-call"][k] for k in ("occurrences", "sources")},
            "stub-virtual": {k: s["stub-virtual"][k] for k in ("occurrences", "sources")}}


def summary(rep):
    for cfg, r in rep["configs"].items():
        print("\n== %s: %d / %d TUs compile" % (cfg, r["tus_compiling"], r["tus"]))
        for k, v in list(r["categories"].items())[:25]:
            if k in cp.NOISE or k.startswith("ms-ext"):
                continue
            print("  %-34s %6d sites %5d TUs %5d sources  fail %d" % (k, v["sites"], v["tus"], v["sources"],
                                                                    r["failing_tus_by_category"].get(k, 0)))
    print("\n== pointer width (net of i686):")
    for cfg, row in rep["sixty4"].items():
        print("  %-8s %s" % (cfg, {k: (v["sites"], v["sources"]) if isinstance(v, dict) else v for k, v in row.items()}))
    print("\n== layout scans: %s" % json.dumps(rep["pads"]))
    lk = rep.get("link")
    if lk:
        print("\n== x64 link (no bridges): %d objects, %d undefined symbols (%d references)" % (
            lk["objects"], lk["undefined_symbols"], lk["undefined_references"]))
        for k, v in lk["groups"].items():
            print("  %-90s %6d %7d" % (k[:90], v["symbols"], v["references"]))
        print("  bridge shapes: %s" % json.dumps(lk["bridge_shapes"]))
        if lk.get("lld_link"):
            print("  lld-link: %s" % json.dumps(lk["lld_link"])[:1500])
        if lk.get("binding_transfer"):
            print("  32-bit binding map as a name table: %s" % json.dumps(lk["binding_transfer"]))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--configs", default=",".join(CONFIGS))
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--no-link", action="store_true")
    ap.add_argument("--sites", metavar="OUT", help="also write the pointer-width sites (msvc64) as JSON lines: "
                    "class, tree file:line, source")
    ap.add_argument("--bindings", help="the 32-bit strict link's build/native/bindings.json of the same tree: "
                    "estimate how much of the 64-bit link it would resolve as a name table")
    a = ap.parse_args(argv)
    cfgs = a.configs.split(",")
    tus, results = compile_configs(cfgs, a.jobs)
    man = cp.Manifest()
    rep = {"configs": {k: {kk: vv for kk, vv in v.items() if kk != "failing"}
                       for k, v in cp.analyse(results, man, tus).items()},
           "sixty4": sixty4_classes(results, tus, man),
           "pads": pad_scan(man, tus)}
    if "msvc64" in results and not a.no_link:
        rep["link"] = link64(results, tus, man, bindings=a.bindings)
    if a.sites and "msvc64" in results:
        site_list(results, tus, man, a.sites)
    os.makedirs(OUT, exist_ok=True)
    with open(os.path.join(OUT, "report.json"), "w") as f:
        json.dump(rep, f, indent=1, default=cp.jsonable)
    summary(rep)


if __name__ == "__main__":
    main()
