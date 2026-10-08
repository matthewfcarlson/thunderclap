#!/usr/bin/env python3
"""Recover MSVC RTTI (classes, hierarchy, vtables) from an XBE.

Usage: tools/rtti.py isos/extracted/default.xbe build/rtti.json

MSVC 7.1 x86 layouts (all pointers absolute):
  TypeDescriptor        { type_info_vftable*, spare, char name[] }
  CompleteObjectLocator { sig=0, offset, cdOffset, TypeDescriptor*, ClassHierarchyDescriptor* }
  ClassHierarchyDesc    { sig=0, attributes, numBaseClasses, BaseClassDescriptor** }
  BaseClassDescriptor   { TypeDescriptor*, numContainedBases, mdisp, pdisp, vdisp, attributes }
  vftable[-1] = CompleteObjectLocator*
"""
import json
import re
import sys
from collections import Counter, defaultdict

from msvc_demangle import DemangleError, demangle_type_name
from xbe import Xbe


def aligned_words(xbe, section):
    """Yield (va, value) for every aligned u32 stored in a section's raw data."""
    import struct
    end = section.raw + section.rsize
    for o in range(section.raw, end - 3, 4):
        yield section.va + (o - section.raw), struct.unpack_from("<I", xbe.data, o)[0]


def main(xbe_path, out_path):
    xbe = Xbe(xbe_path)
    data_secs = [s for s in xbe.sections if s.name in (".rdata", ".data")]

    # 1. Type descriptors: find mangled names, TD starts 8 bytes before.
    tds = {}
    for s in data_secs:
        blob = xbe.data[s.raw:s.raw + s.rsize]
        for m in re.finditer(rb"\.\?A[VU][\x21-\x7e]+?@@\x00", blob):
            name_va = s.va + m.start()
            tds[name_va - 8] = m.group()[:-1].decode("latin1")
    # The type_info vftable pointer is shared by every real TD.
    ti_vft, _ = Counter(xbe.u32(td) for td in tds).most_common(1)[0]
    tds = {td: n for td, n in tds.items() if xbe.u32(td) == ti_vft}

    # Index aligned words in data sections by value (for reverse lookups).
    refs = defaultdict(list)
    for s in data_secs:
        for va, v in aligned_words(xbe, s):
            refs[v].append(va)

    def valid_chd(chd):
        sig, attrs, nbases, bca = (xbe.u32(chd + 4 * i) for i in range(4))
        if sig != 0 or nbases is None or not 0 < nbases < 256 or xbe.offset(bca) is None:
            return False
        return xbe.u32(xbe.u32(bca) or 0) in tds

    # 2. Complete object locators: { 0, off, cdoff, td, chd } referencing a known TD.
    cols = {}
    for td in tds:
        for p in refs.get(td, []):
            col = p - 12
            sig, off, cdoff, _, chd = (xbe.u32(col + 4 * i) for i in range(5))
            if sig == 0 and off is not None and off < 0x10000 and valid_chd(chd):
                cols[col] = (td, off, cdoff, chd)

    # 3. vftables: slot after each pointer to a COL.
    vft_of_col = {}
    col_slots = set()
    for col in cols:
        for p in refs.get(col, []):
            vft_of_col.setdefault(col, []).append(p + 4)
            col_slots.add(p)

    def vtable_slots(vft):
        slots = []
        va = vft
        while va not in col_slots:
            v = xbe.u32(va)
            if v is None or not xbe.is_code(v):
                break
            slots.append(v)
            va += 4
        return slots

    # 4. Hierarchy per type descriptor (from any COL that names it).
    def hierarchy(chd):
        _, attrs, nbases, bca = (xbe.u32(chd + 4 * i) for i in range(4))
        bases = []
        for i in range(nbases):
            bcd = xbe.u32(bca + 4 * i)
            btd, ncont, mdisp, pdisp, vdisp, battrs = (xbe.u32(bcd + 4 * j) for j in range(6))
            pdisp = pdisp - (1 << 32) if pdisp >= 1 << 31 else pdisp
            bases.append({"td": btd, "contained": ncont, "mdisp": mdisp,
                          "pdisp": pdisp, "vdisp": vdisp, "attributes": battrs})
        return attrs, bases

    classes = {}
    demangle_failures = []
    for td, mangled in tds.items():
        try:
            name = demangle_type_name(mangled)
        except DemangleError as e:
            name = None
            demangle_failures.append((mangled, str(e)))
        classes[td] = {"td": td, "mangled": mangled, "name": name,
                       "attributes": None, "bases": [], "vtables": []}

    for col, (td, off, cdoff, chd) in cols.items():
        c = classes[td]
        if c["attributes"] is None:
            attrs, bases = hierarchy(chd)
            c["attributes"] = attrs
            # Entry 0 is the class itself.
            c["bases"] = [dict(b, name=classes[b["td"]]["mangled"]) for b in bases[1:] if b["td"] in classes]
        for vft in vft_of_col.get(col, []):
            c["vtables"].append({"address": vft, "col": col, "offset": off,
                                 "slots": vtable_slots(vft)})

    out = sorted(classes.values(), key=lambda c: c["td"])
    with open(out_path, "w") as f:
        json.dump({"type_info_vftable": ti_vft, "classes": out}, f, indent=1)

    nvft = sum(len(c["vtables"]) for c in out)
    nslots = sum(len(v["slots"]) for c in out for v in c["vtables"])
    uniq = len({s for c in out for v in c["vtables"] for s in v["slots"]})
    print("type descriptors: %d (type_info vftable %#x)" % (len(tds), ti_vft))
    print("complete object locators: %d" % len(cols))
    print("classes with vtables: %d, vtables: %d, slots: %d (%d unique functions)"
          % (sum(1 for c in out if c["vtables"]), nvft, nslots, uniq))
    print("demangle failures: %d" % len(demangle_failures))
    for m, e in demangle_failures[:10]:
        print("  %s: %s" % (m, e))


if __name__ == "__main__":
    main(*sys.argv[1:3])
