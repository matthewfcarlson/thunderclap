#!/usr/bin/env python3
"""RETIRED (gen1, 2026-11-13): include/gen/ is hand-maintained source, so this tool, which fed the header
generator's inputs (include/gen/evidence*.json) or rewrote matches/ onto the generated headers, refuses to run.
Edit the headers and the blocks in src/ by hand (docs/headers.md). Kept for reference; its module-level
helpers still import.

Field names for include/gen/ classes from the fight parameter registrations (clean1).

The fight system describes each Track/Condition/Action parameter once, in a registration function:

    storage = FUN_0008d690(24);
    ((ParamBase *)storage)->FUN_00234960("arc");          // fight::ParamValueFloat, named "arc"
    p = new (storage) fight::ParamFloatConstRange<CClimbableCondition>;
    p->callback = FUN_000480a0;                            // the setter

The setter is a member of the registered class that stores its argument in one field (`this->f_10 = a *
0.0174...`; `ret 4`). So the string literal names the field the setter stores: CClimbableCondition +0x10 is "arc".
This tool pairs each literal with the next setter the source passes (tools' sources: matches/ and equivalent/),
disassembles the setter from the XBE for its single store through `ecx`, finds the include/gen/ unit that declares a
field at that offset (the class or one of its non-virtual bases, tools/gen_headers.py's model), and writes
include/gen/evidence-names.json "fields": {unit: {offset: {name, evidence}}}. tools/gen_headers.py names the fields
from it; tools/rename_fields.py rewrites the sources' references.

Refused: setters with no or several stores, calls, classes outside RTTI, offsets no unit declares, two names for one
field, one name for two fields of a unit, and a name some other member of the unit's hierarchy (bases or derived
classes) already has, or a C++ keyword.

  tools/param_fields.py [--out include/gen/evidence-names.json] [--report]
"""
import argparse
import collections
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import addr_names  # noqa: E402

# fight::ParamValue* constructors that take the parameter's name (include/gen/fight.h, docs/consolidation-plan.md s.10)
NAME_CTORS = {"FUN_00234860", "FUN_00234960", "FUN_00234a90", "FUN_00234ba0", "FUN_00235170", "FUN_002348e0",
              "FUN_002349e0", "FUN_00234cc0", "FUN_00234e50", "FUN_00235220", "FUN_00234af0", "FUN_00234c00"}
KEYWORDS = set("""alignas alignof and and_eq asm auto bitand bitor bool break case catch char class compl const
constexpr const_cast continue decltype default delete do double dynamic_cast else enum explicit export extern false
float for friend goto if inline int long mutable namespace new noexcept not not_eq nullptr operator or or_eq private
protected public register reinterpret_cast return short signed sizeof static static_assert static_cast struct switch
template this thread_local throw true try typedef typeid typename union unsigned using virtual void volatile wchar_t
while xor xor_eq""".split())
# the field type a setter's single store says: x87 stores are floats, integer stores by width
STORE_TYPES = {(4, "fstp"): "float", (4, "fst"): "float", (4, "mov"): "int", (2, "mov"): "short", (1, "mov"): "char"}
FLOAT_CTOR = "FUN_00234960"   # fight::ParamValueFloat's constructor (docs/consolidation-plan.md section 10)
TPARAMS = {"T", "T0", "T1", "C", "X"}
COMMENT = re.compile(r'//[^\n]*|/\*.*?\*/', re.S)


def registrations(paths):
    """[(source, ctor, name, setter, class or None)]"""
    out = []
    for f in paths:
        t = COMMENT.sub("", open(f, errors="replace").read())
        lits = [(m.start(), m.group(1), m.group(2)) for m in re.finditer(r'(FUN_0023[45][0-9a-f]{3})\("([^"]+)"', t)
                if m.group(1) in NAME_CTORS]
        if not lits:
            continue
        ts = [k for k in collections.OrderedDict.fromkeys(re.findall(r'<\s*(?:class\s+)?([A-Za-z_][\w:]*)\s*>', t))
              if k not in TPARAMS]
        whole = ts[0] if len(ts) == 1 else None
        for i, (pos, ct, name) in enumerate(lits):
            seg = t[pos:lits[i + 1][0] if i + 1 < len(lits) else len(t)]
            # (clean2) the setter named by the suffix convention (`SetArc_000480a0`) too; said as FUN_<addr> here
            fns = ["FUN_%08x" % addr_names.ident_address(x) for x in
                   re.findall(r'(?:=|\(|,)\s*&?\s*(?:\([^()]*\)\s*)*&?(FUN_[0-9a-f]{8}|[A-Za-z]\w*_00[0-9a-f]{6})\b(?!\s*\()',
                              seg) if addr_names.ident_address(x) is not None]
            tm = [k for k in re.findall(r'<\s*(?:class\s+)?([A-Za-z_][\w:]*)\s*>', seg) if k not in TPARAMS]
            if fns:
                out.append((os.path.relpath(f, ROOT), ct, name, fns[0], tm[0] if tm else whole))
    return out


def setter_stores(xbe, md, addr, n=64):
    """this-relative stores ([ecx+disp]) up to the first ret; ('call',..) ends the scan."""
    o = xbe.offset(addr)
    out = []
    ins = list(md.disasm(xbe.data[o:o + n], addr))
    # an accessor that returns the member's address (`lea eax, [ecx + X]; ret`: names, lists, scripts)
    if len(ins) >= 2 and ins[0].mnemonic == "lea" and ins[1].mnemonic == "ret":
        m = re.match(r'eax, \[ecx \+ (0x[0-9a-f]+|\d+)\]$', ins[0].op_str)
        if m:
            return [(int(m.group(1), 0), None, "lea")]
    for i in ins:
        if i.mnemonic.startswith("ret"):
            break
        m = re.match(r'(byte|word|dword|qword) ptr \[ecx(?: \+ (0x[0-9a-f]+|\d+))?\]', i.op_str)
        if m and i.mnemonic in ("mov", "fstp", "fst"):
            out.append((int(m.group(2), 0) if m.group(2) else 0, {"byte": 1, "word": 2, "dword": 4, "qword": 8}[m.group(1)],
                        i.mnemonic))
        if i.mnemonic in ("call", "jmp"):
            out.append(("call", 0, i.mnemonic))
            break
    return out


def hierarchy_names(g, c):
    """Member names (fields and functions) declared anywhere in c's bases or derived classes, except by c's unit."""
    up, todo = set(), [c]
    while todo:
        k = todo.pop()
        for b, _, _ in k.bases:
            if b not in up:
                up.add(b)
                todo.append(b)
    down = {k for k in g.classes if c in {b for b, *_ in k.all_bases}}
    names = set()
    for k in up | down:
        if k.unit is c.unit:
            continue
        for off in k.unit.fields:
            names.add(g.field_name(k.unit, off))
        for key in k.decl:
            names.add(g.name_of(key))
    return names


def main():
    sys.exit("tools/param_fields.py is retired (gen1, 2026-11-13): include/gen/ is hand-maintained source "
             "(docs/headers.md)")
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default=os.path.join(ROOT, "include/gen/evidence-names.json"))
    ap.add_argument("--report", action="store_true", help="print the refusals")
    a = ap.parse_args()
    import capstone
    import gen_headers as G
    from compare import XBE_PATH
    from xbe import Xbe
    xbe = Xbe(XBE_PATH)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    ev = json.load(open(G.EVIDENCE_PATH)) if os.path.exists(G.EVIDENCE_PATH) else {}
    g = G.Gen(ev)
    g._field_names = {}      # plan against placeholder names
    g.analyse_slots()
    g.load_sigs_fields()
    g.fix_collisions()
    g.compute_sizes()

    def declaring(c, off):
        stack = [(c, 0)]
        while stack:
            k, d = stack.pop()
            o = off - d
            if o in k.unit.fields and o >= g.own_start(k):
                return k, o
            for b, m, virt in k.bases:
                if not virt and m <= o:
                    stack.append((b, d + m))
        return None, None

    srcs = sorted(glob.glob(os.path.join(ROOT, "matches/*.cpp")) + glob.glob(os.path.join(ROOT, "equivalent/*.cpp")))
    regs = registrations(srcs)
    refused = collections.Counter()
    notes = []
    cand = collections.defaultdict(lambda: collections.defaultdict(list))   # uid -> off -> [(name, evidence)]
    adds = collections.defaultdict(lambda: collections.defaultdict(list))   # uid -> off -> [(name, type, evidence)]
    owner = {}
    for src, ct, name, setter, cls in regs:
        st = setter_stores(xbe, md, int(setter[4:], 16))
        if len(st) != 1 or st[0][0] == "call":
            refused["setter has %s stores" % ("no" if not st else "several/call")] += 1
            continue
        off, size, mn = st[0]
        c = None
        for nm in ([cls, re.sub(r'_[0-9a-f]{5,8}$', '', cls)] if cls else []):
            c = c or g.by_csv.get(nm) or g.by_name.get(nm)
        if c is None:
            refused["class not in RTTI or not found"] += 1
            notes.append("%s %r: class %s" % (src, name, cls))
            continue
        k, o = declaring(c, off)
        if k is None:
            # a field the header doesn't declare yet: added (named) when the offset lies in the class's own part,
            # inside its size, clear of every declared field, and the store says the type
            free = not c.unit.template
            typ = STORE_TYPES.get((size, mn))
            if ct == FLOAT_CTOR and size == 4:
                typ = "float"       # a float parameter copied with an integer move
            if free and typ and g.own_start(c) <= off and off + size <= g.size(c) and not any(
                    fo < off + size and off < fo + G.type_size(ft) for fo, ft in c.unit.fields.items()):
                ev_text = 'fight parameter "%s" of %s, registered by %s (%s); its setter %s stores this+0x%x (%s)' % (
                    name, c.name, os.path.basename(src)[:-4], ct, setter, off, mn)
                adds[c.unit.uid][off].append((name, typ, ev_text))
                owner[c.unit.uid] = c
                continue
            refused["no include/gen/ field at the offset"] += 1
            notes.append("%s %r: %s +0x%x not declared" % (src, name, c.name, off))
            continue
        if size is not None and size != G.type_size(k.unit.fields[o]):
            refused["store size differs from the field's type"] += 1
            notes.append("%s %r: store %d bytes, field %s" % (src, name, size, k.unit.fields[o]))
            continue
        ev_text = 'fight parameter "%s" of %s, registered by %s (%s); its setter %s stores this+0x%x' % (
            name, c.name, os.path.basename(src)[:-4], ct, setter, off)
        cand[k.unit.uid][o].append((name, ev_text))
        owner[k.unit.uid] = k
    out = {}
    for uid, offs in sorted(cand.items()):
        k = owner[uid]
        taken = hierarchy_names(g, k)
        names = {o: {n for n, _ in v} for o, v in offs.items()}
        count = collections.Counter(next(iter(s)) for s in names.values() if len(s) == 1)
        for o, v in sorted(offs.items()):
            s = names[o]
            if len(s) != 1:
                refused["two names for one field"] += 1
                notes.append("%s +0x%x: %s" % (uid, o, sorted(s)))
                continue
            n = next(iter(s))
            if not re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', n) or n in KEYWORDS or n.startswith("f_") or n.startswith("vfunc_"):
                refused["not a usable identifier"] += 1
                notes.append("%s +0x%x: %r" % (uid, o, n))
                continue
            if count[n] > 1:
                refused["one name for two fields"] += 1
                notes.append("%s +0x%x: %r used twice" % (uid, o, n))
                continue
            if n in taken:
                refused["name taken in the hierarchy"] += 1
                notes.append("%s +0x%x: %r taken" % (uid, o, n))
                continue
            out.setdefault(uid, {})["0x%02x" % o] = {"name": n, "evidence": sorted({e for _, e in v})}
    added = {}
    for uid, offs in sorted(adds.items()):
        k = owner[uid]
        taken = hierarchy_names(g, k) | {e["name"] for e in out.get(uid, {}).values()}
        for o, v in sorted(offs.items()):
            s = {(n, ty) for n, ty, _ in v}
            n, ty = sorted(s)[0]
            if len(s) != 1 or not re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', n) or n in KEYWORDS or n in taken \
                    or n.startswith("f_") or n.startswith("vfunc_"):
                refused["added field refused (name/type)"] += 1
                notes.append("%s +0x%x: add %s" % (uid, o, sorted(s)))
                continue
            taken.add(n)
            added.setdefault(uid, {})["0x%02x" % o] = {"name": n, "type": ty, "evidence": sorted({e for *_, e in v})}
    doc = {"_comment": "Generated by tools/param_fields.py: names for include/gen/ fields, each with its evidence. "
                       "tools/gen_headers.py emits these names instead of f_<offset>; tools/rename_fields.py "
                       "rewrites the sources' references.",
           "fields": out, "added": added}
    with open(a.out, "w") as f:
        json.dump(doc, f, indent=1, sort_keys=True)
        f.write("\n")
    print("%d registrations; %d fields named in %d classes; %d fields added; refused %s" % (
        len(regs), sum(len(v) for v in out.values()), len(out), sum(len(v) for v in added.values()), dict(refused)))
    if a.report:
        for n in notes:
            print("  " + n)
    return 0


if __name__ == "__main__":
    sys.exit(main())
