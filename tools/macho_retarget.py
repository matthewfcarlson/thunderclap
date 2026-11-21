#!/usr/bin/env python3
"""Retarget chosen relocations of a Mach-O 64-bit relocatable object (MH_OBJECT) to another symbol (render1, D187).

The native link's replay hooks (src/platform/sdl/host/native_hooks.h, tools/native_bind.py plan_hooks) rename a
callee's name in a game object with llvm-objcopy --redefine-sym, which moves every reference of the object. A per-call-
site hook (`site`: the references one caller function makes) and an entry hook reaching the calls and vftable slots
inside the defining object need finer: only the relocations of chosen functions. This rewrites those relocation
entries to name a new undefined external symbol (appended to the symbol table, with its name appended to the string
table) and leaves every other relocation alone. Nothing else of the object changes: sections, their relocations' order
and count, the other symbols' indices (the new symbol goes last, in the undefined range, which ends the table).

    retarget(path_in, path_out, [(from_name, to_name, owners)])

`owners`: the function names (Mach-O spelling, `_` included) whose relocations move; a name prefixed `!` inverts the
choice (every relocation except those inside that function: an entry hook's own object minus the definition itself).
A relocation's owner is the last non-temporary symbol at or before its offset in its section (data sections included:
a vftable's owner is its label); only __TEXT / __DATA / __DATA_CONST sections are touched (never unwind or debug
info) and never a relocation without an owner. ARM64_RELOC_ADDEND entries (no symbol) are never touched.

    python tools/macho_retarget.py IN OUT FROM TO [OWNER ...]   # prints the relocations moved
"""
import struct
import sys

MH_MAGIC_64 = 0xFEEDFACF
LC_SEGMENT_64 = 0x19
LC_SYMTAB = 0x2
LC_DYSYMTAB = 0xB
N_EXT, N_UNDF, N_SECT, N_STAB, N_TYPE = 0x01, 0x0, 0xE, 0xE0, 0x0E


def _cstr(buf, off):
    end = buf.index(b"\0", off)
    return buf[off:end].decode("latin-1")


def parse(data):
    magic, _cpu, _sub, ftype, ncmds, _size, _flags, _res = struct.unpack_from("<IiiIIIII", data, 0)
    if magic != MH_MAGIC_64 or ftype != 1:
        raise ValueError("not a 64-bit Mach-O relocatable object")
    off, sects, symtab, dysym = 32, [], None, None
    for _ in range(ncmds):
        cmd, size = struct.unpack_from("<II", data, off)
        if cmd == LC_SEGMENT_64:
            nsects = struct.unpack_from("<I", data, off + 64)[0]
            for i in range(nsects):
                s = off + 72 + 80 * i
                sectname = data[s:s + 16].rstrip(b"\0").decode()
                segname = data[s + 16:s + 32].rstrip(b"\0").decode()
                addr, size_, foff, _align, reloff, nreloc = struct.unpack_from("<QQIIII", data, s + 32)
                sects.append({"name": segname + "," + sectname, "addr": addr, "reloff": reloff, "nreloc": nreloc})
        elif cmd == LC_SYMTAB:
            symtab = off
        elif cmd == LC_DYSYMTAB:
            dysym = off
        off += size
    if symtab is None:
        raise ValueError("no LC_SYMTAB")
    symoff, nsyms, stroff, strsize = struct.unpack_from("<IIII", data, symtab + 8)
    syms = []
    for i in range(nsyms):
        strx, ntype, nsect, ndesc, nvalue = struct.unpack_from("<IBBHQ", data, symoff + 16 * i)
        syms.append({"name": _cstr(data, stroff + strx) if strx else "", "type": ntype, "sect": nsect,
                     "value": nvalue})
    return {"sects": sects, "symtab": symtab, "dysym": dysym, "symoff": symoff, "nsyms": nsyms, "stroff": stroff,
            "strsize": strsize, "syms": syms}


def owners_by_section(m):
    """{section index (1-based): [(address, name)]} of the non-stab, non-temporary symbols defined in sections."""
    out = {}
    for s in m["syms"]:
        if s["type"] & N_STAB or (s["type"] & N_TYPE) != N_SECT:
            continue
        n = s["name"]
        if n.startswith(("ltmp", "L", "l_")):
            continue
        out.setdefault(s["sect"], []).append((s["value"], n))
    for v in out.values():
        v.sort()
    return out


def retarget(src, dst, plans):
    """Apply [(from, to, owners)] (Mach-O spellings) to `src`, writing `dst`. Returns [(section, offset, owner, from,
    to)] for every relocation moved; raises ValueError when a `from` name is not in the symbol table."""
    data = bytearray(open(src, "rb").read())
    m = parse(data)
    index = {s["name"]: i for i, s in enumerate(m["syms"]) if s["name"]}
    owners = owners_by_section(m)
    new_names, moved = [], []
    for frm, to, sel in plans:
        if frm not in index:
            raise ValueError("%s: no symbol %s" % (src, frm))
        fi = index[frm]
        if to in index:
            ti = index[to]
        else:
            ti = m["nsyms"] + len(new_names)
            new_names.append(to)
            index[to] = ti
        inv = {n[1:] for n in sel if n.startswith("!")}
        want = {n for n in sel if not n.startswith("!")}
        for si, sec in enumerate(m["sects"], 1):
            if not sec["name"].startswith(("__TEXT,", "__DATA,", "__DATA_CONST,")):
                continue    # (unwind, debug info: they describe the function, they do not call it)
            table = owners.get(si, [])
            for k in range(sec["nreloc"]):
                p = sec["reloff"] + 8 * k
                raddr, word = struct.unpack_from("<iI", data, p)
                if raddr < 0:      # (scattered: not on arm64)
                    continue
                symnum, ext, rtype = word & 0xFFFFFF, (word >> 27) & 1, word >> 28
                if not ext or symnum != fi or rtype == 10:    # (ARM64_RELOC_ADDEND carries an addend, no symbol)
                    continue
                at = sec["addr"] + raddr
                own = None
                for a, n in table:
                    if a <= at:
                        own = n
                    else:
                        break
                hit = own is not None and ((own in want) if want else (own not in inv))
                if not hit:
                    continue
                struct.pack_into("<I", data, p + 4, (word & ~0xFFFFFF) | ti)
                moved.append((sec["name"], raddr, own, frm, to))
    if new_names:
        # a new symbol table (old entries + the new undefined ones) and string table at the end of the file
        strtab = bytes(data[m["stroff"]:m["stroff"] + m["strsize"]])
        extra = b""
        nl = b""
        for n in new_names:
            nl += struct.pack("<IBBHQ", len(strtab) + len(extra), N_UNDF | N_EXT, 0, 0, 0)
            extra += n.encode("latin-1") + b"\0"
        old = bytes(data[m["symoff"]:m["symoff"] + 16 * m["nsyms"]])
        while len(data) % 8:
            data.append(0)
        symoff = len(data)
        data += old + nl
        stroff = len(data)
        newstr = strtab + extra
        while len(newstr) % 8:
            newstr += b"\0"
        data += newstr
        struct.pack_into("<IIII", data, m["symtab"] + 8, symoff, m["nsyms"] + len(new_names), stroff, len(newstr))
        if m["dysym"] is not None:
            iundef, nundef = struct.unpack_from("<II", data, m["dysym"] + 24)
            if iundef + nundef != m["nsyms"]:
                raise ValueError("%s: undefined symbols do not end the table" % src)
            struct.pack_into("<I", data, m["dysym"] + 28, nundef + len(new_names))
    open(dst, "wb").write(bytes(data))
    return moved


if __name__ == "__main__":
    if len(sys.argv) < 5:
        sys.exit(__doc__)
    for r in retarget(sys.argv[1], sys.argv[2], [(sys.argv[3], sys.argv[4], sys.argv[5:])]):
        print("%s +0x%x in %s: %s -> %s" % r)
