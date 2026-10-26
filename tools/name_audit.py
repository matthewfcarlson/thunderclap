#!/usr/bin/env python3
"""Name audit of a Wine link: which references reach their definition by exact symbol name, and which only through
an alias, a rebinding or a stub (x64-6, name unification; docs/native-mac.md "Link inventory").

  build/venv/bin/python tools/name_audit.py --link DIR [--snap SNAP] [--out OUT.json] [--tsv OUT.tsv]

DIR holds what one Wine build leaves (a wine_build_job lineage's build/native/ plus build/clang-probe/):
`bindings.json`, `aliases.rsp` (build/native/link/), `slot_aliases.json`, `unbound.txt` and the clang probe's `undefined.txt`
(every symbol some clang object references and none defines, with its reference count). SNAP (the clang probe's
snapshot, `snap/`) maps the TU namespaces (`fn_f<7 hex>`) to their tree files and sources.

Every undefined symbol is put in one category. A reference is *exact* when the object that makes it names the
definition's own symbol; those never appear here (the link resolves them without help). Everything in
undefined.txt is resolved some other way:

  library      the target is the host C runtime, the XDK shim or the library stand-ins (`_hulk_host_*`,
               `_hulk_xdk_*`, `_hulk_lib_*`, `_hulk_crt_*`, the probe's CRT / platform / library groups): a separate
               category, resolved by our host tables by design.
  game         everything else: aliased (`/alternatename`), rebound per object or calling function (`sym$...`), a
               stub-vftable slot, or stubbed (unbound). Sub-categories by the shape of the two names after the
               generator's namespaces (`fn_<8 hex>::`) are taken off, so that they say what a *source* rename fixes:

    data: invented name for a DAT_ item             caller `extern int gCount;`, item `DAT_004e5acc`
    data: DAT_ name with C++ linkage / namespace    caller `extern float DAT_003f32dc;` outside decls/data
    data: vftable / RTTI item by another name       caller `g_vftable_2c22d0`, item `_hulk_d_0042ec20`
    function: generator namespace only              same source-level symbol (the TU or wrapped namespace differs)
    function: same name, other declaration          same qualified name, another signature / linkage
    function: same member, other class              `Pad::FUN_00035b70` vs `State_35b70::FUN_00035b70`
    function: FUN_ caller of a named definition     caller `FUN_000a0fe0`, definition `CChaseCamera::update`
    function: invented name for a FUN_ definition   caller `helper`, definition `FUN_00042890`
    function: other name                            both named, differently (`Destroy` vs `FUN_0027afd0`)
    thunk / forwarder shape (_hulk_j_)              the definition is a jump shape wine_link emits
    stub vftable slot                               a stub's virtual member, bound to the game vftable's slot
    rebound per TU / calling function               an ambiguous name (one invented name, two addresses)
    link-generated definition or retarget           wine_link emits it (`??_G` deleting destructors) or points
                                                    the reference elsewhere (vftables, interior data offsets)
    unbound (stubbed)                               no definition reachable (wine_link's unbound.txt)

The counts are symbols and references (an object counts once per symbol). The tsv lists every game symbol:
category, references, symbol, target, the referencing namespace's sources (when SNAP is given).
"""
import argparse
import collections
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

LIB_PREFIX = ("_hulk_host_", "_hulk_xdk_", "_hulk_lib_", "_hulk_crt_")
LIB_GROUPS = ("CRT / C++ runtime", "platform import", "data: library", "library code by address")
NS_RX = re.compile(r"\bfn_[0-9a-f]{8}::")
NS_M_RX = re.compile(r"@fn_[0-9a-f]{8}(?=@)")


def undname(names):
    exe = None
    for d in (os.environ.get("HULK_LLVM", "") + "/bin", "/opt/homebrew/opt/llvm/bin", os.path.expanduser("~/llvm/bin")):
        if os.path.exists(os.path.join(d, "llvm-undname")):
            exe = os.path.join(d, "llvm-undname")
            break
    names = [n for n in names if n.startswith("?")]
    if not exe or not names:
        return {}
    p = subprocess.run([exe], input="\n".join(names) + "\n", capture_output=True, text=True, errors="replace")
    out, it, want = {}, iter(p.stdout.splitlines()), set(names)
    for line in it:
        if line in want and line not in out:
            out[line] = next(it, line)
    return out


def qual_name(dem):
    """`public: void __thiscall fn_0001b510::Pad::FUN_00035b70(float)` -> `fn_0001b510::Pad::FUN_00035b70`."""
    depth, cut = 0, len(dem)
    for i, ch in enumerate(dem):
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        elif ch == "(" and depth == 0:
            cut = i
            break
    head = dem[:cut].rstrip()
    depth, start = 0, 0
    for i, ch in enumerate(head):
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        elif ch == " " and depth == 0:
            start = i + 1
    return head[start:]


def ident(q):
    depth, last = 0, 0
    for i in range(len(q)):
        ch = q[i]
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        elif depth == 0 and q.startswith("::", i):
            last = i + 2
    return q[last:]


def strip_ns(s):
    return NS_RX.sub("", s)


def plain(sym, dem):
    """Source-level form of a symbol: demangled, generator namespaces removed; C names as they are."""
    if sym.startswith("?"):
        return strip_ns(dem.get(sym, sym))
    s = sym[1:] if sym.startswith("_") else sym
    return re.sub(r"@\d+$", "", s)


def is_addr_name(i, kind="FUN"):
    return re.fullmatch(r"%s_[0-9a-f]{8}" % kind, i) is not None


def load(link):
    rd = lambda n: os.path.join(link, n)  # noqa: E731
    bindings = json.load(open(rd("bindings.json")))
    aliases, rebound = {}, collections.defaultdict(set)
    for line in open(rd("aliases.rsp")):
        line = line.strip().strip('"')
        if not line.startswith("/alternatename:"):
            continue
        a, b = line[len("/alternatename:"):].split("=", 1)
        if "$" in a:
            rebound[a.split("$", 1)[0]].add(b)
        else:
            aliases[a] = b
    undef = []
    for line in open(rd("undefined.txt"), errors="replace"):
        p = line.rstrip("\n").split("\t")
        if len(p) >= 3:
            undef.append((p[0], int(p[1]), p[2]))
    slots = json.load(open(rd("slot_aliases.json"))) if os.path.exists(rd("slot_aliases.json")) else {}
    stubbed = None
    if os.path.exists(rd("unbound.txt")):     # (wine_link's: what the strict link still stubs)
        stubbed = {l.split("\t")[2] for l in open(rd("unbound.txt"), errors="replace") if l.count("\t") >= 3}
    return bindings, aliases, rebound, undef, slots, stubbed


def tu_map(snap):
    """namespace -> [source paths], from the snapshot's TU files (`// 0xADDR name (size): path [mode]` lines)."""
    ns_src = collections.defaultdict(list)
    src_tu = {}
    for dp, dns, fns in os.walk(os.path.join(snap, "src")):
        for fn in fns:
            if not fn.endswith(".cpp"):
                continue
            p = os.path.join(dp, fn)
            tu = os.path.relpath(p, snap)
            tns = None
            for line in open(p, errors="replace"):
                m = re.match(r"namespace (fn_f[0-9a-f]{7}) \{\} using namespace", line)
                if m and not tns:
                    tns = m.group(1)
                m = re.match(r"// 0x([0-9a-f]{8}) .*\): ((?:matches|equivalent)/0x[0-9a-f]{8}\.cpp)( \[(\w+))?", line)
                if m:
                    mode = m.group(4) or "merged"
                    src_tu[m.group(2)] = (tu, mode)
                    if mode in ("wrapped", "isolated"):
                        ns_src["fn_" + m.group(1)].append(m.group(2))
                    elif tns:
                        ns_src[tns].append(m.group(2))
    return ns_src, src_tu


def classify(link, snap=None):
    bindings, aliases, rebound, undef, slots, stubbed = load(link)
    dem = undname({s for _, _, s in undef} | set(aliases.values()) | {t for v in rebound.values() for t in v})
    ns_src = tu_map(snap)[0] if snap else {}
    rows = []
    for grp, n, s in undef:
        tgt = aliases.get(s)
        tgts = {tgt} if tgt else set(rebound.get(s, ()))
        if any(t.startswith(LIB_PREFIX) for t in tgts) or (not tgts and grp.startswith(LIB_GROUPS)) or \
                (grp.startswith(LIB_GROUPS) and not any(t.startswith("?") for t in tgts)):
            rows.append(("library", grp.split(" (")[0], n, s, ",".join(sorted(tgts))))
            continue
        cat = game_category(s, tgt, tgts, slots, dem)
        if cat == "unbound (stubbed)" and stubbed is not None and s not in stubbed:
            cat = "link-generated definition or retarget (deleting destructor, vftable, interior)"
        rows.append(("game", cat, n, s, ",".join(sorted(tgts))))
    out = []
    for kind, cat, n, s, t in rows:
        srcs = []
        if ns_src:
            for m in NS_M_RX.finditer(s):
                srcs += ns_src.get(m.group(0)[1:], [])
        out.append((kind, cat, n, s, t, srcs))
    return out


def game_category(s, tgt, tgts, slots, dem):
    if s in slots:
        return "stub vftable slot"
    if not tgts:
        return "unbound (stubbed)"
    if not tgt:
        return "rebound per TU / calling function"
    if tgt.startswith("_hulk_j_"):
        return "thunk / forwarder shape (_hulk_j_)"
    if tgt.startswith("_hulk_d_"):
        return "data: vftable / RTTI item by another name"
    if tgt.startswith("_hulk_"):
        return "platform hook (_hulk_*)"
    is_data = bool(re.match(r"\?[^?].*@@[23]", s)) or tgt.startswith("_DAT_")
    pc, pt = plain(s, dem), plain(tgt, dem)
    qc, qt = qual_name(pc) if s.startswith("?") else pc, qual_name(pt) if tgt.startswith("?") else pt
    ic, it = ident(qc), ident(qt)
    if s.startswith(("??_7", "??_R")) or "vftable" in ic.lower():
        return "vftable / RTTI by another name"
    if tgt.startswith("_DAT_") or (is_data and is_addr_name(it, "DAT")):
        return "data: DAT_ name with C++ linkage / namespace" if ic == it else "data: invented name for a DAT_ item"
    if is_data:
        return "data: other"
    if pc == pt:
        return "function: generator namespace only"
    if qc == qt:
        return "function: same name, other declaration"
    if ic == it:
        return "function: same member, other class"
    if is_addr_name(ic) and not is_addr_name(it):
        return "function: FUN_ caller of a named definition"
    if is_addr_name(it):
        return "function: invented name for a FUN_ definition"
    return "function: other name"


def summarize(rows):
    t = collections.defaultdict(lambda: [0, 0])
    for kind, cat, n, s, tg, srcs in rows:
        for k in ((kind, "*"), (kind, cat)):
            t[k][0] += 1
            t[k][1] += n
    res = {}
    for (kind, cat), (ns, nr) in sorted(t.items(), key=lambda kv: (kv[0][0], -kv[1][0])):
        res.setdefault(kind, {})[cat] = {"symbols": ns, "references": nr}
    return res


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--link", required=True, help="dir with bindings.json, aliases.rsp, undefined.txt, slot_aliases.json")
    ap.add_argument("--snap", help="the clang probe snapshot (snap/) for namespace -> sources")
    ap.add_argument("--out", help="summary json")
    ap.add_argument("--tsv", help="every game symbol: category, refs, symbol, target, sources")
    a = ap.parse_args(argv)
    rows = classify(a.link, a.snap)
    summ = summarize(rows)
    if a.out:
        json.dump(summ, open(a.out, "w"), indent=1)
    if a.tsv:
        with open(a.tsv, "w") as f:
            for kind, cat, n, s, tg, srcs in sorted(rows, key=lambda r: (r[0], r[1], -r[2], r[3])):
                f.write("%s\t%s\t%d\t%s\t%s\t%s\n" % (kind, cat, n, s, tg, " ".join(sorted(set(srcs)))))
    for kind, cats in summ.items():
        print("%-8s %6d symbols %6d references" % (kind, cats["*"]["symbols"], cats["*"]["references"]))
        for cat, v in cats.items():
            if cat != "*":
                print("   %6d %6d  %s" % (v["symbols"], v["references"], cat))
    return 0


if __name__ == "__main__":
    sys.exit(main())
