#!/usr/bin/env python3
"""(adr1) Addresses written as integers: an operand of our object that holds a game address with no relocation.

`FUN_0027b020(0x400488u)` or `__RTDynamicCast(p, 0, 0x491ca8, 0x492108, 0)` compiles to the original's bytes on
32-bit, so compare.py (relocations masked) and the relocation checks (they check the relocations the object has)
pass, but the 64-bit image passes a bogus pointer. This module decides which original operands are addresses and
finds our unrelocated operands that carry one.

The XBE has no relocation table, so "the original has a relocation here" is decided from the original instruction
the way the data inventory (tools/data_inventory.py, config/data.json) decides what code references:

  absolute memory operand ([disp], [index*s + disp])   an address when disp is in a section of the image
  memory operand with a base register ([reg + disp])  an address when disp is in .rdata/.data (struct offsets are
                                                      small; a data-range displacement is a global indexed by reg)
  immediate                                           an address when the instruction is not arithmetic or a
                                                      comparison (FourCC codes, hashes and masks are compared or
                                                      combined) and the value is a spot code references: the start
                                                      of a data item (a vtable's ??_7 point, not its COL slot; never
                                                      the RTTI descriptors only data points at: ??_R1/R2/R3/R4), a
                                                      referenced interior point of an item (not of a type descriptor:
                                                      that is its name string) or an aligned word in an
                                                      XDK section (their data sits next to their code); not a
                                                      function start (round constants coincide with them)

The caller pairs this with the original: verify_relocs (matches/: the bytes are the original's, so the operand at the
same offset is the original's) and equiv.py level 2 (equivalent/: a value the original function references as an
address, that our object only has as a plain immediate). RELOC_OFF=addrlit / EQUIV_OFF=addrlit switch it off.
"""
import json
import os

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
DATA_JSON = os.path.join(ROOT, "config/data.json")

# instructions whose immediate is a value, not an address (data_inventory.address_like_imm)
ARITH = frozenset(("cmp", "and", "or", "xor", "add", "sub", "imul", "test", "sbb", "adc", "shl", "shr", "sar",
                   "rol", "ror"))
# RTTI structures code never points at (only other RTTI data does)
DATA_ONLY_KINDS = frozenset(("rtti_bcd", "rtti_chd", "rtti_bca", "rtti_col"))

_st = {}


def _state():
    if not _st:
        import csv
        import sys
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        from xbe import Xbe
        _st["xbe"] = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
        funcs = {}
        with open(os.path.join(ROOT, "build/functions.csv")) as f:
            for r in csv.DictReader(f):
                funcs[int(r["address"], 16)] = int(r["size"])
        _st["funcs"] = funcs
        targets = set()
        if os.path.exists(DATA_JSON):
            for it in json.load(open(DATA_JSON))["items"]:
                k = it["kind"]
                if k in DATA_ONLY_KINDS:
                    continue
                a = int(it["addr"], 16)
                if k == "vtable":
                    targets.add(a + 4)          # the ??_7 point; the item starts at the COL slot
                    continue
                targets.add(a)
                if k == "rtti_td":
                    continue                    # its interior is the name string: never a code target
                for x in it.get("interior", ()):
                    targets.add(int(x, 16))
        _st["targets"] = targets
        _st["data"] = [s for s in _st["xbe"].sections if s.name in (".rdata", ".data")]
        # the XDK's sections (D3D, XGRPH, DSOUND, XPP) keep their own data next to their code
        # (XDEVICE_TYPE_GAMEPAD is &XDEVICE_TYPE_GAMEPAD_TABLE, in XPP)
        _st["xdk"] = [s for s in _st["xbe"].sections if s.name in ("D3D", "XGRPH", "DSOUND", "XPP")]
    return _st


def in_game_data(v):
    return any(s.contains(v) for s in _state()["data"])


def is_address_operand(v, mnemonic, kind, own=None):
    """Is operand value V of an original instruction MNEMONIC an address? KIND: 'mem_abs' (no base register),
    'mem_base' (a base register) or 'imm'. OWN: (start, end) of the function itself (its own body is not data)."""
    st = _state()
    v &= 0xFFFFFFFF
    if own and own[0] <= v < own[1]:
        return False
    sec = st["xbe"].section_of(v)
    if sec is None:
        return False
    if kind == "mem_abs":
        return True
    if kind == "mem_base":
        return in_game_data(v)
    if mnemonic in ARITH:
        return False
    # (a function start as an immediate is not taken: round constants such as 0x11000, 0x13000 and 0x120100, sizes
    # passed to the loader registry, are function starts too, and every hit of that rule over the tree was one)
    if v % 4 == 0 and any(s.contains(v) for s in st["xdk"]):
        return True
    return v in st["targets"]


def _operands(md, code, base=0):
    """[(insn offset, mnemonic, field offset in insn, field size, value, kind)] for the 4-byte imm/disp fields."""
    from capstone import x86
    out = []
    for i in md.disasm(code, base):
        for op in i.operands:
            if op.type == x86.X86_OP_IMM and i.imm_size == 4:
                if i.group(x86.X86_GRP_JUMP) or i.group(x86.X86_GRP_CALL):
                    continue
                out.append((i.address - base, i.mnemonic, i.imm_offset, 4, op.imm & 0xFFFFFFFF, "imm"))
            elif op.type == x86.X86_OP_MEM and i.disp_size == 4:
                kind = "mem_abs" if op.mem.base == 0 else "mem_base"
                out.append((i.address - base, i.mnemonic, i.disp_offset, 4, op.mem.disp & 0xFFFFFFFF, kind))
    return out


def _md():
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    return md


def unrelocated_addresses(code, mask, addr):
    """Our function bytes CODE (with relocated byte offsets MASK) matched at ADDR: the operands with no relocation
    whose value is an address by the original's instruction at the same offset. [{offset, value, mnemonic, kind}]"""
    st = _state()
    own = (addr, addr + st["funcs"].get(addr, len(code)))
    out = []
    for ioff, mn, foff, n, v, kind in _operands(_md(), code):
        o = ioff + foff
        if any(b in mask for b in range(o, o + n)):
            continue
        if is_address_operand(v, mn, kind, own):
            out.append({"offset": "0x%x" % o, "value": "0x%08x" % v, "mnemonic": mn, "kind": kind})
    return out


def original_addresses(addr):
    """The values the original function at ADDR references as addresses (by its own instructions)."""
    st = _state()
    xbe = st["xbe"]
    size = st["funcs"].get(addr)
    o = xbe.offset(addr)
    if size is None or o is None:
        return set()
    own = (addr, addr + size)
    return {v for _, mn, _, _, v, kind in _operands(_md(), xbe.data[o:o + size], addr)
            if is_address_operand(v, mn, kind, own)}
