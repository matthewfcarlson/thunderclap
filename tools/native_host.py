#!/usr/bin/env python3
"""The native image's host side: host C runtime, library stand-ins, start-up table, interior data, named stubs.

Used by tools/native_link.py (docs/native-build.md "Start-up"); not run on its own.

  host_crt(...)        src/platform/sdl/crt/host_crt_table.h -> import libraries for msvcrt / ntdll / kernel32
                       (llvm-dlltool, our own .def files: every host function under `hulk_host_<name>`), the
                       glue objects (src/platform/sdl/crt/*.cpp), and the aliases of the tree's CRT references
                       (by XBE address, by name)
  library_table(...)   src/platform/sdl/xdk/library.h: the library code and data the tree reaches by address
                       (beyond the 167 imports of imports.h) and the stand-ins / our own definitions for them
  startup_asm(...)     build/native/link/startup.s: the game's C++ dynamic initializers in the XBE's order (the
                       pointers between the `.CRT$XCA` and `.CRT$XCZ` markers), each bound to the tree's
                       definition of that `.text$yc` function; library initializers are left out (null entries)
  interior_targets(...) undefined references to an address inside an emitted data item (`DAT_<start>` of a data
                       TU, or an item of vtables.s): the referencing objects are patched to name the item with the
                       offset added to the relocation's inline addend (retarget_object)
  stubs_asm(...)       the stub object: each code stub reports its own name (hulk_native_missing) instead of int3
"""
import bisect
import collections
import json
import os
import re
import struct
import subprocess

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
LLVM = "/opt/homebrew/opt/llvm/bin"
CRT_DIR = os.path.join(ROOT, "src/platform/sdl/crt")
CRT_TABLE = os.path.join(CRT_DIR, "host_crt_table.h")
LIB_TABLE = os.path.join(ROOT, "src/platform/sdl/xdk/library.h")
# The XBE's C++ initializer table: the CRT start-up reads the pointers strictly between these two markers
# (`__xc_a` / `__xc_z`, `.CRT$XCA` / `.CRT$XCZ`; config/data.json has both as one-word items referenced from the
# start-up's _initterm call). Null words are linker padding between the `.CRT$XCU` contributions.
XC_A, XC_Z = 0x0048ca90, 0x0048d4f4
# game code reaches library code in these spans (docs/platform-boundary.md "Where library code lives")
LIB_SPANS = [(0x208b9c, 0x212bb0), (0x3440e0, 0x356bf0), (0x35a7b0, 0x35be88), (0x364840, 0x3f2be0)]
MAIN_ADDR = 0x0008ee30          # the game's main (Ghidra label `main`; matches/0x0008ee30.cpp)


def is_library(a):
    return any(lo <= a < hi for lo, hi in LIB_SPANS)


# ---------------------------------------------------------------------------------------------
# Tables
I_RX = re.compile(r'^\s*I\((\w+), (\w+), (-?\d+), "([^"]*)"\)', re.M)
C_RX = re.compile(r'^\s*C\((0x[0-9a-fA-F]{8}|0), (\w+), "([^"]*)"\)', re.M)
D_RX = re.compile(r'^\s*D\((0x[0-9a-fA-F]{8}), (\S+?), (\d+)\)', re.M)
X_RX = re.compile(r'^\s*X\((0x[0-9a-fA-F]{8}), (\w+), "([^"]*)"\)', re.M)


def host_tables():
    t = open(CRT_TABLE).read() if os.path.exists(CRT_TABLE) else ""
    imports = [(dll, name, int(n), exp or name) for dll, name, n, exp in I_RX.findall(t)]
    crt = [(int(a, 16), target, names.split()) for a, target, names in C_RX.findall(t)]
    data = [(int(a, 16), sym, int(n)) for a, sym, n in D_RX.findall(t)]
    return imports, crt, data


def library_table():
    """(code rows [(addr, name)], data rows [(addr, symbol, bytes)]) of src/platform/sdl/xdk/library.h."""
    t = open(LIB_TABLE).read() if os.path.exists(LIB_TABLE) else ""
    return [(int(a, 16), n) for a, n, _ in X_RX.findall(t)], [(int(a, 16), s, int(n)) for a, s, n in D_RX.findall(t)]


def import_symbol(name, stack):
    """The COFF symbol the import library defines for host function `name` (cdecl or stdcall with N bytes)."""
    return "_hulk_host_%s%s" % (name, "@%d" % stack if stack >= 0 else "")


def plain_name(sym):
    """The source-level identifier of a C or MS-mangled symbol: `_x` -> x, `_x@8` / `@x@8` -> x, `?x@...` -> x."""
    if sym.startswith("?"):
        m = re.match(r"\?([\w$]+)@", sym)
        return m.group(1) if m else None
    m = re.fullmatch(r"[_@](\w+?)(?:@\d+)?", sym)
    return m.group(1) if m else None


def build_import_libs(outdir, imports):
    """One import library per DLL from our own .def files; returns the .lib paths."""
    os.makedirs(outdir, exist_ok=True)
    by_dll = collections.defaultdict(list)
    for dll, name, stack, exp in imports:
        by_dll[dll].append("hulk_host_%s%s == %s" % (name, "@%d" % stack if stack >= 0 else "", exp))
    libs = []
    for dll, lines in sorted(by_dll.items()):
        d = os.path.join(outdir, dll + ".def")
        with open(d, "w") as f:
            f.write("LIBRARY %s.dll\nEXPORTS\n%s\n" % (dll, "\n".join(lines)))
        lib = os.path.join(outdir, dll + ".lib")
        r = subprocess.run([os.path.join(LLVM, "llvm-dlltool"), "-m", "i386", "-d", d, "-l", lib],
                           capture_output=True, text=True)
        if r.returncode != 0:
            raise RuntimeError("llvm-dlltool %s: %s" % (dll, r.stderr[-1000:]))
        libs.append(lib)
    return libs


def compile_dir(cp, src_dir, out_dir, st, defines=()):
    """Compile every .cpp of a platform directory (clang, i686-pc-windows-msvc, -Werror); [objects]."""
    os.makedirs(out_dir, exist_ok=True)
    clang = cp.tool("clang++")
    objs = []
    for fn in sorted(os.listdir(src_dir)):
        if not fn.endswith(".cpp"):
            continue
        obj = os.path.join(out_dir, fn[:-4] + ".obj")
        r = subprocess.run([clang, "--target=i686-pc-windows-msvc", "-fms-extensions", "-std=c++14", "-O1",
                            "-mno-sse", "-mfpmath=387", "-fno-builtin", "-Werror"] + ["-D" + d for d in defines] +
                           ["-c", os.path.join(src_dir, fn),
                            "-o", obj], capture_output=True, text=True)
        if r.returncode != 0:
            st["files failing to compile"] += 1
            print(r.stderr[-3000:])
            continue
        objs.append(obj)
        st["files"] += 1
    return objs


def defined_by_key(cp, objs, prefix):
    """{plain name without `prefix`: symbol} of the functions/data objs define whose plain name starts with prefix."""
    out = {}
    for dset, _u in cp.nm(objs).values():
        for s in dset:
            k = plain_name(s) if not s.startswith("?") else None
            if k is None and s.startswith("?"):
                m = re.match(r"\?([\w$]+)@@", s)          # a global C++ name (`??_7type_info@@6B@` is not one)
                k = m.group(1) if m else None
            if k and k.startswith(prefix):
                out[k] = s
    return out


def host_crt(cp, outdir):
    """The host CRT pieces of the link: {"libs", "objects", "defined", "by_addr", "by_name", "stats"}.

    by_addr: XBE address -> the symbol that stands for it (host import or our glue); by_name: tree plain name ->
    symbol. Data rows (D) go to by_addr too (our own definitions of library data)."""
    st = collections.Counter()
    imports, crt, data = host_tables()
    out = {"libs": [], "objects": [], "defined": set(), "by_addr": {}, "by_name": {}, "stats": st}
    if not imports:
        return out
    out["libs"] = build_import_libs(os.path.join(outdir, "host"), imports)
    st["host imports"] = len(imports)
    out["objects"] = compile_dir(cp, CRT_DIR, os.path.join(outdir, "crt"), st)
    syms = cp.nm(out["objects"])
    for dset, _u in syms.values():
        out["defined"] |= dset
    glue = defined_by_key(cp, out["objects"], "hulk_crt_")
    imp_sym = {name: import_symbol(name, stack) for dll, name, stack, exp in imports}
    for a, target, names in crt:
        s = glue.get(target) if target.startswith("hulk_crt_") else imp_sym.get(target)
        if s is None:
            st["table rows without a definition"] += 1
            print("native_host: no definition for %s" % target)
            continue
        if a:
            out["by_addr"][a] = s
        for n in names:
            out["by_name"][n] = s
        st["crt rows"] += 1
    for a, sym, size in data:
        s = glue.get(sym) or sym          # (not in the glue: defined by startup.s, e.g. type_info's vftable)
        out["defined"].add(s)
        out["by_addr"][a] = s
        st["data rows"] += 1
    return out


def library_shim(cp, shim_objs):
    """library.h's rows -> {"by_addr": addr -> stand-in symbol, "stats"} (the stand-ins are in the shim's objects)."""
    st = collections.Counter()
    code, data = library_table()
    defs = defined_by_key(cp, shim_objs, "hulk_lib_")
    allsyms = set()
    for dset, _u in cp.nm(shim_objs).values():
        allsyms |= dset
    by_addr = {}
    for a, name in code:
        s = defs.get("hulk_lib_" + name)
        if s is None:
            st["code rows without a stand-in"] += 1
            continue
        by_addr[a] = s
        st["code rows"] += 1
    for a, sym, size in data:
        s = defs.get(sym) or (sym if sym in allsyms else None)
        if s is None:
            st["data rows without a definition"] += 1
            continue
        by_addr[a] = s
        st["data rows"] += 1
    return {"by_addr": by_addr, "stats": dict(st)}


# ---------------------------------------------------------------------------------------------
def startup_asm(x, by_addr_def):
    """build/native/link/startup.s: the initializer table (tree definitions in the XBE's order; 0 for library
    initializers and for game ones without a definition) and the XBE address of each entry. Returns (asm, stats)."""
    st = collections.Counter()
    rows = []
    for a in range(XC_A + 4, XC_Z, 4):
        v = x.u32(a)
        if not v:
            continue
        if is_library(v):
            rows.append((v, None))
            st["library initializers (left out)"] += 1
            continue
        d = by_addr_def.get(v)
        rows.append((v, d))
        st["game initializers bound" if d else "game initializers without a definition"] += 1
    out = ["\t.section\t.rdata,\"dr\"", "\t.p2align\t2",
           "\t.globl\t_hulk_game_initializer_count", "_hulk_game_initializer_count:", "\t.long\t%d" % len(rows),
           "\t.globl\t_hulk_game_initializer_addrs", "_hulk_game_initializer_addrs:"]
    out += ["\t.long\t0x%08x" % v for v, _ in rows]
    out += ["\t.data", "\t.p2align\t2", "\t.globl\t_hulk_game_initializers", "_hulk_game_initializers:"]
    out += ['\t.long\t"%s"' % d if d else "\t.long\t0" for _, d in rows]
    # markers around clang's own `.CRT$XCU` entries (dynamic initializers clang emits for a TU; MSVC 7.1 put the
    # game's into .text$yc and the table above): lld-link sorts `.CRT$X*` by suffix, so they lie between these two
    out += ['\t.section\t.CRT$XCA,"dr"', "\t.p2align\t2", "\t.globl\t_hulk_clang_xc_a", "_hulk_clang_xc_a:", "\t.long\t0",
            '\t.section\t.CRT$XCZ,"dr"', "\t.p2align\t2", "\t.globl\t_hulk_clang_xc_z", "_hulk_clang_xc_z:", "\t.long\t0"]
    # type_info's vftable (msvcrt.dll doesn't export it): slot 0, the scalar deleting destructor, deletes nothing
    out += ["\t.text", "\t.p2align\t4", "_hulk_type_info_sdd:", "\tmovl\t%ecx, %eax", "\tretl\t$4",
            '\t.section\t.rdata,"dr"', "\t.p2align\t2", "\t.long\t0", '\t.globl\t"??_7type_info@@6B@"',
            '"??_7type_info@@6B@":', "\t.long\t_hulk_type_info_sdd"]
    return "\n".join(out) + "\n", dict(st)


# ---------------------------------------------------------------------------------------------
# Interior data: a reference to an address inside an item another object defines
def data_items():
    items = [it for it in json.load(open(os.path.join(ROOT, "config/data.json")))["items"]]
    items.sort(key=lambda it: int(it["addr"], 16))
    return items, [int(it["addr"], 16) for it in items]


def container(a, items, starts, defined_at):
    """(symbol, offset) of the defined item that contains address a (defined_at: item start -> symbol), or None."""
    i = bisect.bisect_right(starts, a) - 1
    if i < 0:
        return None
    s = starts[i]
    if s < a < s + max(items[i]["size"], 1) + items[i].get("pad", 0) and s in defined_at:
        return defined_at[s], a - s
    return None


REL_PATCHABLE = {0x06: "DIR32", 0x07: "DIR32NB", 0x14: "REL32"}


def retarget_object(obj, mapping, out):
    """Copy of a COFF object where each undefined symbol in mapping {name: (new name, offset)} is renamed to the new
    name and `offset` is added to the inline addend of every DIR32 / REL32 relocation that names it (COFF keeps the
    addend in the instruction or data bytes). Returns (patched relocation count, skipped relocation count)."""
    d = bytearray(open(obj, "rb").read())
    _, nsec, _, symoff, nsym, opthdr, _ = struct.unpack_from("<HHIIIHH", d, 0)
    strtab = symoff + nsym * 18
    strsize, = struct.unpack_from("<I", d, strtab)
    extra = bytearray()
    idx_off = {}
    i = 0
    while i < nsym:
        o = symoff + i * 18
        if d[o:o + 4] == b"\0\0\0\0":
            so, = struct.unpack_from("<I", d, o + 4)
            s = strtab + so
            name = bytes(d[s:d.index(b"\0", s)]).decode()
        else:
            name = bytes(d[o:o + 8]).rstrip(b"\0").decode()
        value, secnum, typ, cls, naux = struct.unpack_from("<IhHBB", d, o + 8)
        if name in mapping and secnum == 0:
            new, off = mapping[name]
            nb = new.encode()
            if len(nb) <= 8:
                d[o:o + 8] = nb.ljust(8, b"\0")
            else:
                struct.pack_into("<II", d, o, 0, strsize + len(extra))
                extra += nb + b"\0"
            idx_off[i] = off
        i += 1 + naux
    patched = skipped = 0
    for k in range(nsec):
        o = 20 + opthdr + k * 40
        _, _, size, raw, relptr, _, nrel, _, _ = struct.unpack_from("<IIIIIIHHI", d, o + 8)
        for j in range(nrel):
            va, si, typ = struct.unpack_from("<IIH", d, relptr + j * 10)
            if si not in idx_off:
                continue
            if typ not in REL_PATCHABLE or not raw:
                skipped += 1
                continue
            v, = struct.unpack_from("<I", d, raw + va)
            struct.pack_into("<I", d, raw + va, (v + idx_off[si]) & 0xFFFFFFFF)
            patched += 1
    d += extra
    struct.pack_into("<I", d, strtab, strsize + len(extra))
    with open(out, "wb") as f:
        f.write(d)
    return patched, skipped


# ---------------------------------------------------------------------------------------------
def stubs_asm(undefined, data_like, vthunks=None):
    """The stub object for the symbols still undefined: data stubs are 16 zero bytes; a code stub calls
    hulk_native_missing with its own name (startup.cpp: logs the caller and ends the run). A virtual member of a
    stub class with a known slot (vthunks {symbol: slot}) dispatches through `this`'s vftable instead (thiscall:
    `this` in ecx), unless that slot is the stub itself (a clang stub vftable: then it reports itself)."""
    code, data, names = ["\t.text"], [], []
    for k, s in enumerate(sorted(undefined)):
        q = '"%s"' % s.replace('"', '\\"')
        if data_like.match(s):
            data += ["\t.globl\t%s" % q, "%s:" % q, "\t.zero\t16"]
        elif vthunks and s in vthunks:
            code += ["\t.globl\t%s" % q, "%s:" % q, "\tmovl\t(%ecx), %eax", "\tmovl\t%d(%%eax), %%eax" % (4 * vthunks[s]),
                     "\tcmpl\t$%s, %%eax" % q, "\tje\tLself%d" % k, "\tjmpl\t*%eax", "Lself%d:" % k,
                     "\tpushl\t$Lname%d" % k, "\tcalll\t_hulk_native_missing", "\tint3"]
            names += ["Lname%d:" % k, '\t.asciz\t"%s"' % s.replace("\\", "\\\\").replace('"', '\\"')]
        else:
            code += ["\t.globl\t%s" % q, "%s:" % q, "\tpushl\t$Lname%d" % k, "\tcalll\t_hulk_native_missing", "\tint3"]
            names += ["Lname%d:" % k, '\t.asciz\t"%s"' % s.replace("\\", "\\\\").replace('"', '\\"')]
    return "\n".join(code + ["\t.section\t.rdata,\"dr\""] + names + ["\t.data"] + data) + "\n"


def rebind_object(obj, plans, out):
    """Copy of a COFF object where relocations naming symbol S are rebound per containing function:
    plans {S: {function symbol: new symbol}}. New undefined external symbols are appended to the symbol table (the
    string table moves behind them). Returns the set of old names some relocation still uses."""
    d = bytes(open(obj, "rb").read())
    _, nsec, _, symoff, nsym, opthdr, _ = struct.unpack_from("<HHIIIHH", d, 0)
    strtab = symoff + nsym * 18
    strsize, = struct.unpack_from("<I", d, strtab)
    strings = bytearray(d[strtab:strtab + strsize])
    names, funcs = {}, collections.defaultdict(list)
    i = 0
    while i < nsym:
        o = symoff + i * 18
        if d[o:o + 4] == b"\0\0\0\0":
            so, = struct.unpack_from("<I", d, o + 4)
            name = d[strtab + so:d.index(b"\0", strtab + so)].decode()
        else:
            name = d[o:o + 8].rstrip(b"\0").decode()
        value, secnum, typ, cls, naux = struct.unpack_from("<IhHBB", d, o + 8)
        names[i] = name
        if secnum > 0 and typ == 0x20:
            funcs[secnum].append((value, name))
        i += 1 + naux
    for k in funcs:
        funcs[k].sort()
    new_idx, new_syms = {}, bytearray()
    body = bytearray(d[:strtab])
    left = set()
    for k in range(nsec):
        o = 20 + opthdr + k * 40
        _, _, size, raw, relptr, _, nrel, _, _ = struct.unpack_from("<IIIIIIHHI", d, o + 8)
        fl = funcs.get(k + 1, [])
        starts = [v for v, _ in fl]
        for j in range(nrel):
            va, si, typ = struct.unpack_from("<IIH", d, relptr + j * 10)
            s = names.get(si)
            if s not in plans:
                continue
            q = bisect.bisect_right(starts, va) - 1
            fn = fl[q][1] if q >= 0 else None
            new = plans[s].get(fn)
            if not new:
                left.add(s)
                continue
            if new not in new_idx:
                new_idx[new] = nsym + len(new_idx)
                nb = new.encode()
                rec = bytearray(18)
                if len(nb) <= 8:
                    rec[0:8] = nb.ljust(8, b"\0")
                else:
                    struct.pack_into("<II", rec, 0, 0, len(strings))
                    strings += nb + b"\0"
                struct.pack_into("<IhHBB", rec, 8, 0, 0, 0x20, 2, 0)
                new_syms += rec
            struct.pack_into("<I", body, relptr + j * 10 + 4, new_idx[new])
    struct.pack_into("<I", body, 12, nsym + len(new_idx))
    struct.pack_into("<I", strings, 0, len(strings))
    with open(out, "wb") as f:
        f.write(bytes(body) + bytes(new_syms) + bytes(strings))
    return left


def retarget_relocs(obj, mapping, out, own=False):
    """Copy of a COFF object where every DIR32 / REL32 relocation naming a symbol in mapping {name: (new name,
    offset)} names a new undefined symbol instead, with the offset added to the inline addend; relocations inside
    the section that defines the old symbol (a vftable's own COMDAT) are left alone unless `own` (native9: a stand-in
    body's callers in the same .text). Returns the count rebound."""
    d = bytes(open(obj, "rb").read())
    _, nsec, _, symoff, nsym, opthdr, _ = struct.unpack_from("<HHIIIHH", d, 0)
    strtab = symoff + nsym * 18
    strsize, = struct.unpack_from("<I", d, strtab)
    strings = bytearray(d[strtab:strtab + strsize])
    names, own_sec = {}, {}
    i = 0
    while i < nsym:
        o = symoff + i * 18
        if d[o:o + 4] == b"\0\0\0\0":
            so, = struct.unpack_from("<I", d, o + 4)
            name = d[strtab + so:d.index(b"\0", strtab + so)].decode()
        else:
            name = d[o:o + 8].rstrip(b"\0").decode()
        value, secnum, typ, cls, naux = struct.unpack_from("<IhHBB", d, o + 8)
        names[i] = name
        if name in mapping and secnum > 0:
            own_sec[name] = secnum
        i += 1 + naux
    body = bytearray(d[:strtab])
    new_idx, new_syms, n = {}, bytearray(), 0
    for k in range(nsec):
        o = 20 + opthdr + k * 40
        _, _, size, raw, relptr, _, nrel, _, _ = struct.unpack_from("<IIIIIIHHI", d, o + 8)
        for j in range(nrel):
            va, si, typ = struct.unpack_from("<IIH", d, relptr + j * 10)
            s = names.get(si)
            if s not in mapping or (own_sec.get(s) == k + 1 and not own) or typ not in REL_PATCHABLE or not raw:
                continue
            new, off = mapping[s]
            if new not in new_idx:
                new_idx[new] = nsym + len(new_idx)
                nb = new.encode()
                rec = bytearray(18)
                if len(nb) <= 8:
                    rec[0:8] = nb.ljust(8, b"\0")
                else:
                    struct.pack_into("<II", rec, 0, 0, len(strings))
                    strings += nb + b"\0"
                struct.pack_into("<IhHBB", rec, 8, 0, 0, 0, 2, 0)
                new_syms += rec
            struct.pack_into("<I", body, relptr + j * 10 + 4, new_idx[new])
            v, = struct.unpack_from("<I", body, raw + va)
            struct.pack_into("<I", body, raw + va, (v + off) & 0xFFFFFFFF)
            n += 1
    struct.pack_into("<I", body, 12, nsym + len(new_idx))
    struct.pack_into("<I", strings, 0, len(strings))
    with open(out, "wb") as f:
        f.write(bytes(body) + bytes(new_syms) + bytes(strings))
    return n


def globalize_object(obj, names, out):
    """Copy of a COFF object with the static symbols in names made external (storage class 3 -> 2). Returns the
    count changed."""
    d = bytearray(open(obj, "rb").read())
    _, nsec, _, symoff, nsym, opthdr, _ = struct.unpack_from("<HHIIIHH", d, 0)
    strtab = symoff + nsym * 18
    n, i = 0, 0
    while i < nsym:
        o = symoff + i * 18
        if d[o:o + 4] == b"\0\0\0\0":
            so, = struct.unpack_from("<I", d, o + 4)
            name = bytes(d[strtab + so:d.index(b"\0", strtab + so)]).decode()
        else:
            name = bytes(d[o:o + 8]).rstrip(b"\0").decode()
        if name in names and d[o + 16] == 3 and struct.unpack_from("<h", d, o + 12)[0] > 0:
            d[o + 16] = 2
            n += 1
        i += 1 + d[o + 17]
    with open(out, "wb") as f:
        f.write(d)
    return n


# ---------------------------------------------------------------------------------------------
# Data layout: the data TUs' items at the XBE's distances
DATA_SYM_RX = re.compile(r"^(?:_|\?)DAT_(00[0-9a-f]{6})(?:$|@@)")
GAP_LIMIT = 0x10000         # a larger gap between two items starts a new block


def data_block(x, objs, want=()):
    """build/native/link/data.s: every item the data TUs (tools/data_gen.py, compiled by clang) define, placed at
    the XBE's distances from its neighbours, instead of the data TU objects themselves.

    Why: the inventory splits one structure into several items where the code addresses its fields separately (the
    `om` type tree's header at 0x004e79b8: root, then the nil node at +4, each a 4-byte item); as separate C variables
    the native link places them wherever the compiler and linker like (clang put `DAT_004cd384` between the two),
    so `&root + 4` is not the nil node. Here each item is copied from its object (bytes and DIR32 relocations, i.e.
    exactly the verified data TU's contents: no MSVC input changes) and laid out in address order, one block per
    run of items in one XBE section (gaps up to 64 KB zero-filled: vftables, RTTI and library data live elsewhere in
    the image), each block starting at the item's address modulo 16. Labels keep each item's symbol.

    native12: `want` (the link's undefined symbols): a string item the game's code names (`_DAT_<addr>`) that the
    inventory gives to a library object, because the linker pooled the game's literal with a library's ("sub",
    0x00434bbc, also XGraphics' at 0x003ba1b8), has no data TU: natively it was a 16-byte zero stub, so Lua's string
    library registered str_sub under "" and play3's level scripts called a nil `string.sub`. Each such string is
    placed here with the XBE's bytes (a bridge: docs/native-build.md "Bridges to remove").

    objs: the data TU objects (after any relocation patches). Returns {"asm", "defined", "objects_used", "stats"}."""
    import compare
    st = collections.Counter()
    sizes = {int(it["addr"], 16): it["size"] for it in json.load(open(os.path.join(ROOT, "config/data.json")))["items"]}
    rdata = next(s for s in x.sections if s.name == ".rdata")
    data = next(s for s in x.sections if s.name == ".data")

    def region(a):
        if rdata.va <= a < rdata.va + rdata.vsize:
            return ".rdata"
        if data.va <= a < data.va + data.rsize:
            return ".data"
        if data.va + data.rsize <= a < data.va + data.vsize:
            return ".bss"
        return None
    items = {}                  # addr -> (symbol, bytes, {offset: (target, addend)})
    defined, used, mismatch = set(), [], []
    for o in objs:
        c = compare.Coff(o)
        d = c.data
        _, nsec, _, symoff, nsym, opthdr, _ = struct.unpack_from("<HHIIIHH", d, 0)
        secsize = [struct.unpack_from("<I", d, 20 + opthdr + k * 40 + 16)[0] for k in range(nsec)]
        by_sec = collections.defaultdict(list)          # secnum -> [(value, addr, symbol)]
        others = []
        for name, value, secnum, typ, cls in c.symbols:
            if secnum <= 0 or cls != 2:
                continue
            m = DATA_SYM_RX.match(name)
            if not m:
                others.append(name)
                continue
            by_sec[secnum].append((value, int(m.group(1), 16), name))
        if others:
            st["data objects defining other symbols (kept as objects)"] += 1
            continue
        used.append(o)
        for secnum, syms in by_sec.items():
            _, raw, relocs = c.sections[secnum - 1]
            for value, a, name in syms:
                n = sizes.get(a)
                if n is None:
                    st["items not in config/data.json (skipped)"] += 1
                    continue
                if value + n > secsize[secnum - 1]:
                    st["items larger than their section (skipped)"] += 1
                    continue
                b = bytes(raw[value:value + n]) if raw else bytes(n)
                rel = {}
                for va, si, typ in relocs:
                    if value <= va < value + n:
                        t = c.by_index.get(si)
                        add, = struct.unpack_from("<i", raw, va)
                        if typ != 0x06 or t is None:
                            st["relocations other than DIR32 (item skipped)"] += 1
                            rel = None
                            break
                        if t[4] != 2:   # a section symbol of this object: the item at that offset
                            tgt = next(((nm, t[1] + add - v) for v, aa, nm in by_sec.get(t[2], [])
                                        if v <= t[1] + add < v + sizes.get(aa, 0)), None)
                            if tgt is None:
                                rel = None
                                st["relocations to an unknown local (item skipped)"] += 1
                                break
                            rel[va - value] = tgt
                        else:
                            rel[va - value] = (t[0], add)
                if rel is None:
                    continue
                if a in items:
                    st["items defined twice (second dropped)"] += 1
                    continue
                if region(a) is None:
                    st["items outside .rdata/.data (skipped)"] += 1
                    continue
                items[a] = (name, b, rel)
                defined.add(name)
                # (sanity: the bytes outside relocations equal the XBE's; .bss has none)
                xo = x.offset(a)
                if xo is not None:
                    orig = x.data[xo:xo + n]
                    if any(orig[k] != b[k] for k in range(n) if not any(r <= k < r + 4 for r in rel)):
                        mismatch.append(name)
    if want:
        for it in json.load(open(os.path.join(ROOT, "config/data.json")))["items"]:
            a = int(it["addr"], 16)
            name = "_DAT_%08x" % a
            if it.get("kind") != "string" or name not in want or a in items or region(a) not in (".rdata", ".data"):
                continue
            if not str(it.get("object", "")).startswith("library/"):
                continue
            xo = x.offset(a)
            b = bytes(x.data[xo:xo + it["size"]]) if xo is not None else b""
            if len(b) != it["size"] or b[-1:] != b"\0":
                st["pooled library strings not NUL-terminated (skipped)"] += 1
                continue
            items[a] = (name, b, {})
            defined.add(name)
            st["game-referenced strings pooled with library data, from the XBE (native12)"] += 1
    st["items"] = len(items)
    st["data objects replaced by the block"] = len(used)
    st["items whose bytes differ from the XBE outside relocations"] = len(mismatch)
    out, prev, prev_reg, blocks = [], None, None, 0
    sec_dir = {".rdata": '\t.section\t.rdata,"dr"', ".data": "\t.data", ".bss": "\t.bss"}
    for a in sorted(items):
        name, b, rel = items[a]
        reg = region(a)
        if prev is None or reg != prev_reg or a - prev > GAP_LIMIT or a < prev:
            if prev is not None and a < prev:
                st["overlapping items (new block)"] += 1
            blocks += 1
            out += [sec_dir[reg], "\t.p2align\t4"]
            if a & 15:
                out.append("\t.zero\t%d" % (a & 15))
        elif a > prev:
            out.append("\t.zero\t%d" % (a - prev))
        q = '"%s"' % name
        out += ["\t.globl\t%s" % q, "%s:" % q]
        if reg == ".bss":
            out.append("\t.zero\t%d" % len(b))
        else:
            pos = 0
            while pos < len(b):
                if pos in rel:
                    t, add = rel[pos]
                    out.append('\t.long\t"%s"%s' % (t, "%+d" % add if add else ""))
                    pos += 4
                    continue
                k = pos
                while k < len(b) and k - pos < 32 and not any(r <= k < r + 4 for r in rel):
                    k += 1
                out.append("\t.byte\t" + ",".join(str(v) for v in b[pos:k]))
                pos = k
        prev, prev_reg = a + len(b), reg
    st["blocks"] = blocks
    return {"asm": "\n".join(out) + "\n", "defined": defined, "objects_used": used, "stats": dict(st),
            "mismatch": mismatch[:20]}
