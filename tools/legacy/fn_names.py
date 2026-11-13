#!/usr/bin/env python3
"""RETIRED (gen1, 2026-11-13): include/gen/ is hand-maintained source, so this tool, which fed the header
generator's inputs (include/gen/evidence*.json) or rewrote matches/ onto the generated headers, refuses to run.
Edit the headers and the blocks in src/ by hand (docs/headers.md). Kept for reference; its module-level
helpers still import.

Function names from evidence (clean2): writes include/gen/evidence-fnames.json, which tools/name_unify.py rename
applies (the definition and every `FUN_<addr>` reference take the name).

Every name follows the suffix convention (tools/addr_names.py, docs/consolidation-plan.md section 13): a meaningful
name plus `_<8 hex digits>` of the function's address, `SetArc_000480a0`, so that every tool that reads an address
from a name still does.

  tools/fn_names.py params [--out include/gen/evidence-fnames.json] [--report]

`params`: the fight parameter callbacks. A registration passes a string literal to a `fight::ParamValue*`
constructor and then the parameter's callback (tools/param_fields.py registrations: `p->callback = FUN_000480a0`
after `FUN_00234960("arc")`). Each callback registered under exactly one parameter name is named after it:

  - `Get<Name>` when its body is `lea eax,[ecx+X]; ret` (it hands the parameter the field's address);
  - `Set<Name>` otherwise (it takes the value: one store through ecx, a conversion first, or a copy of a string).

Refused: callbacks registered under two names, names that are not identifiers, and callbacks whose body is neither
(no store, no call, no field address).
"""
import argparse
import collections
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.join(ROOT, "tools", "legacy"))
import addr_names  # noqa: E402
import param_fields  # noqa: E402

OUT = os.path.join(ROOT, "include/gen/evidence-fnames.json")


def callback_kind(xbe, md, addr):
    """('get', offset) for `lea eax,[ecx+X]; ret`, ('set', None) for a body that stores through ecx or calls,
    None otherwise."""
    o = xbe.offset(addr)
    if o is None:
        return None
    ins = list(md.disasm(xbe.data[o:o + 64], addr))
    if len(ins) >= 2 and ins[0].mnemonic == "lea" and ins[1].mnemonic == "ret":
        m = re.fullmatch(r"eax, \[ecx \+ (0x[0-9a-f]+|\d+)\]", ins[0].op_str)
        if m:
            return "get", int(m.group(1), 0)
    st = param_fields.setter_stores(xbe, md, addr)
    if st:
        return "set", None
    return None


def cmd_params(a):
    import capstone
    from xbe import Xbe
    xbe = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    regs = param_fields.registrations(sorted(glob.glob(os.path.join(ROOT, "matches/*.cpp")) +
                                             glob.glob(os.path.join(ROOT, "equivalent/*.cpp"))))
    by = collections.defaultdict(list)
    for src, ct, name, setter, cls in regs:
        by[int(setter[4:], 16)].append((src, ct, name, cls))
    out, refused = {}, collections.Counter()
    for addr in sorted(by):
        names = sorted({r[2] for r in by[addr]})
        if len(names) != 1:
            refused["registered under several names"] += 1
            continue
        pname = names[0]
        if not re.fullmatch(r"[A-Za-z][A-Za-z0-9_]*", pname):
            refused["not an identifier"] += 1
            continue
        k = callback_kind(xbe, md, addr)
        if k is None:
            refused["body neither stores, calls nor returns a field address"] += 1
            continue
        verb = "Get" if k[0] == "get" else "Set"
        new = "%s%s%s_%08x" % (verb, pname[0].upper(), pname[1:], addr)
        assert addr_names.suffix_address(new) == addr
        regs_s = "; ".join("%s registers it for \"%s\" of %s (%s)" % (os.path.basename(s)[:-4], n, c or "?", ct)
                           for s, ct, n, c in sorted(set(by[addr])))
        body = ("returns this+0x%x (the field's address)" % k[1]) if k[0] == "get" else "takes the value"
        out["0x%08x" % addr] = {"name": new, "kind": "fight parameter callback",
                                "evidence": "%s; the callback %s" % (regs_s, body)}
    doc = {"_doc": "Function names from evidence (tools/fn_names.py; applied by tools/name_unify.py rename). "
                   "Each name keeps the function's address as a suffix (tools/addr_names.py).",
           "functions": out}
    if a.report:
        print(json.dumps(dict(refused)))
    old = {}
    if os.path.exists(a.out):
        old = json.load(open(a.out)).get("functions", {})
    merged = dict(old)
    merged.update(out)
    doc["functions"] = dict(sorted(merged.items()))
    with open(a.out, "w") as f:
        json.dump(doc, f, indent=1, sort_keys=False)
        f.write("\n")
    print("%d callbacks named (%d registrations); refused %s" % (len(out), len(regs), dict(refused)))
    return 0


def main(argv=None):
    sys.exit("tools/legacy/fn_names.py is retired (gen1, 2026-11-13): include/gen/ is hand-maintained source "
             "(docs/headers.md)")
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("params")
    p.add_argument("--out", default=OUT)
    p.add_argument("--report", action="store_true")
    a = ap.parse_args(argv)
    return cmd_params(a)


if __name__ == "__main__":
    sys.exit(main())
