#!/usr/bin/env python3
"""Verify that a match's relocations point at the right things (codegen match -> full match).

compare.py masks relocated bytes, so a TU calling the wrong function or loading the wrong
global still "matches". For an exact match, offsets line up, so every relocation in our object
can be paired with the 4 original bytes at the same offset. That gives the original target, which
is then checked:

  string literal  ??_C@...     same bytes at the target
  float constant  __real@...   same bits at the target
  vftable         ??_7...@6B@  target is a vftable (and that class's, when the class is in RTTI)
  call / jmp      REL32        target is a function start
  data            DIR32        target is inside .rdata/.data/.bss
  consistency                  one symbol -> one target within the function; two symbols -> one target is a warning

  tools/verify_relocs.py matches/0x00018b40.cpp            # one file (address from the name)
  tools/verify_relocs.py --all [--jobs 8]                  # every match -> build/reloc-report.jsonl
"""
import argparse
import csv
import json
import os
import re
import struct
import sys
import tempfile
from collections import Counter
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(__file__))
from compare import Coff, CompileError, DEFAULT_FLAGS, compare, compile_obj, strip_padding  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
REL32, DIR32 = 0x14, 0x06

_state = {}


def state():
    if not _state:
        _state["xbe"] = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
        with open(os.path.join(ROOT, "build/functions.csv")) as f:
            _state["funcs"] = {int(r["address"], 16) for r in csv.DictReader(f)}
        rtti = json.load(open(os.path.join(ROOT, "build/rtti.json")))
        vft = {}
        for c in rtti["classes"]:
            for v in c["vtables"]:
                vft[v["address"]] = c["mangled"]
        _state["vftables"] = vft
    return _state


def classify(name):
    if name.startswith("??_C@"):
        return "string"
    if name.startswith("__real@"):
        return "float"
    if name.startswith("??_7"):
        return "vftable"
    return "symbol"


def literal_bytes(coff, sym):
    """Contents of a string-literal symbol in our object (its COMDAT .rdata section): its full extent, from the
    symbol to the end of the section, so a wide literal's terminator and any embedded NULs are included.
    (cl4: it used to stop at the first NUL byte, which cut every wide string after its first character and
    let L"()" pass for the original's L"()[]{}=;". RELOC_OFF=literal restores that.)"""
    _, value, secnum, _, _ = sym
    if secnum <= 0:
        return None
    _, raw, _ = coff.sections[secnum - 1]
    if "literal" not in os.environ.get("RELOC_OFF", ""):
        return raw[value:]
    end = raw.find(b"\0", value)
    return raw[value:end + 1] if end >= 0 else raw[value:]


# (cl3) Initializers. A global our source defines (not only declares) that binds to an original address: the
# relocation is masked (compare.py) or the code reads the original's address (equiv.py level 3), so its initial
# bytes are never compared, but the native build starts with ours (`const float rads = 0.0174533f;` bound to
# the original's pi/180 at 0x003f32b8). They must equal the original's data there (.bss reads as zeros).
_NOT_GLOBALS = ("??_C@", "__real@", "__xmm@", "??_7", "??_8", "??_R", "$SG", "__imp_", ".", "@", "__security_cookie")
SCN_CODE, SCN_IDATA, SCN_UDATA = 0x20, 0x40, 0x80


def defined_data(obj_bytes):
    """{name: (section name, bytes (None: .bss), size, masked offsets)} of the data symbols an object defines."""
    d = obj_bytes
    _, nsec, _, symoff, nsym, opthdr, _ = struct.unpack_from("<HHIIIHH", d, 0)
    strtab = symoff + nsym * 18
    secs = []
    for i in range(nsec):
        o = 20 + opthdr + i * 40
        name = d[o:o + 8].rstrip(b"\0").decode("latin1")
        _, _, size, raw, relptr, _, nrel, _, flags = struct.unpack_from("<IIIIIIHHI", d, o + 8)
        if name.startswith("/"):
            off = int(name[1:])
            name = d[strtab + off:d.index(b"\0", strtab + off)].decode("latin1")
        relocs = [struct.unpack_from("<I", d, relptr + j * 10)[0] for j in range(nrel)]
        secs.append((name, size, d[raw:raw + size] if raw else None, relocs, flags))
    syms, i = [], 0
    while i < nsym:
        o = symoff + i * 18
        if d[o:o + 4] == b"\0\0\0\0":
            off, = struct.unpack_from("<I", d, o + 4)
            name = d[strtab + off:d.index(b"\0", strtab + off)].decode("latin1")
        else:
            name = d[o:o + 8].rstrip(b"\0").decode("latin1")
        value, secnum, typ, cls, naux = struct.unpack_from("<IhHBB", d, o + 8)
        syms.append((name, value, secnum, typ, cls, naux))
        i += 1 + naux
    starts = {}
    for name, value, secnum, typ, cls, naux in syms:
        if secnum > 0:
            starts.setdefault(secnum, set()).add(value)
    out = {}
    for name, value, secnum, typ, cls, naux in syms:
        if secnum <= 0 or typ == 0x20 or cls not in (2, 3) or name.startswith(_NOT_GLOBALS):
            continue
        sname, ssize, raw, relocs, flags = secs[secnum - 1]
        if flags & SCN_CODE or not flags & (SCN_IDATA | SCN_UDATA) or name == sname or (cls == 3 and naux):
            continue          # code, .drectve/.debug, the section's own symbol
        later = [v for v in starts[secnum] if v > value]
        end = min(later) if later else ssize
        if end <= value:
            continue
        mask = {k - value for r in relocs for k in range(r, r + 4) if value <= k < end}
        out[name] = (sname, raw[value:end] if raw is not None else None, end - value, mask)
    return out


def initializer_diffs(obj_bytes, mapping, read, sizes=None):
    """[{symbol, target, offset, ours, original}] for each defined data symbol in MAPPING ({name: original address})
    whose initial bytes differ from the original's (READ(addr, n) -> bytes; None or short reads are zeros).
    SIZES ({name: size}, round 25 nf5): clang's COFF has no symbol sizes, so a static array is taken to run to the end of
    its section, over whatever private constants follow it; the MSVC object's size for the same name is the extent."""
    out = []
    for name, (sname, raw, size, mask) in sorted(defined_data(obj_bytes).items()):
        a = mapping.get(name)
        if a is None:
            continue
        if sizes and name in sizes and sizes[name] < size:
            size = sizes[name]
            mask = {k for k in mask if k < size}
        ours = raw if raw is not None else bytes(size)
        orig = read(a, size) or b""
        orig = orig + bytes(size - len(orig))
        bad = [k for k in range(size) if k not in mask and ours[k] != orig[k]]
        if bad:
            k = bad[0] & ~3
            rec = {"kind": "initializer_differs", "symbol": name, "target": "0x%08x" % a, "size": size,
                   "offset": bad[0], "ours": ours[k:k + 16].hex(), "original": orig[k:k + 16].hex(),
                   "section": sname}
            if size == 4 and not mask:
                rec["ours_f"], rec["original_f"] = repr(struct.unpack("<f", ours)[0]), repr(struct.unpack("<f", orig)[0])
            out.append(rec)
    return out


def xbe_read(xbe):
    def read(a, n):
        o = xbe.offset(a)
        if o is None:
            return bytes(n) if xbe.section_of(a) is not None else None
        s = xbe.section_of(a)
        k = min(n, s.raw + s.rsize - o)
        return xbe.data[o:o + k] + bytes(n - k)
    return read


# (cl5) Declarations of thiscall callees. Byte-identical code can't show that a source declares a callee as a free
# __stdcall/__cdecl function when the original's callee takes `this` in ecx: the caller's ecx happened to hold the
# right value (matches/0x00042930 called the member 0x00042890 through `void __stdcall helper(int, float)`; ecx still
# held the caller's `this`, but natively ecx is the first argument). The callee's own body is the evidence: it reads
# ecx before writing it (equiv.Program.reg_inputs), or it sits in a vtable. A callee bound to an `// equiv-conv` line
# takes its registers as declared and is left out. RELOC_OFF=thisdecl switches the check off.
def free_decl_conv(name):
    """'cdecl' / 'stdcall' / 'fastcall' / 'thiscall' / 'static' of a callee symbol as our source declares it; None
    when it can't be told (a C name without decoration is cdecl)."""
    if name.startswith("?"):
        import equiv
        sig = equiv.parse_signature(name)
        if not sig:
            return None
        if sig.get("this"):
            return "thiscall" if sig.get("cc") == "thiscall" else sig.get("cc")
        return sig.get("cc") if sig.get("cc") in ("cdecl", "stdcall", "fastcall") else None
    if re.match(r"_\w+@\d+$", name):
        return "stdcall"
    if re.match(r"@\w+@\d+$", name):
        return "fastcall"
    return "cdecl" if re.match(r"_\w+$", name) else None


def thiscall_decl_issue(name, target, prog=None, convs=()):
    """None, or a record when SYMBOL (our declaration of the function at TARGET) is a non-member __cdecl/__stdcall
    function but the original's function reads ecx (`this`) on entry or is a virtual function."""
    if "thisdecl" in os.environ.get("RELOC_OFF", ""):
        return None
    if prog is None:
        import equiv
        prog = equiv.Program.get()
    if target in convs or name.startswith("__"):        # (__aullshr, __allmul ...: CRT helpers take registers)
        return None
    conv = free_decl_conv(name)
    if conv not in ("cdecl", "stdcall") or not prog.is_code(target):
        return None
    why = []
    regs = prog.reg_inputs(target)
    if regs and "ecx" in regs:
        why.append("the original reads ecx before writing it")
    if target in prog.virtual_funcs:
        why.append("the original is a virtual function")
    if not why:
        return None
    return {"kind": "free_decl_of_thiscall", "symbol": name, "target": "0x%08x" % target, "declared": conv,
            "why": " and ".join(why)}



def check(src, addr):
    st = state()
    xbe = st["xbe"]
    r = compare(src, addr)
    if r["status"] not in ("match", "thiscall_decl"):       # (cl5: thiscall_decl is reported as an issue below)
        return {"addr": "0x%08x" % addr, "status": "not_matching", "detail": r["status"]}
    with tempfile.TemporaryDirectory() as tmp:
        try:
            objp = compile_obj(src, DEFAULT_FLAGS, tmp)
            coff = Coff(objp)
        except CompileError as e:
            return {"addr": "0x%08x" % addr, "status": "compile_error", "detail": str(e)[:200]}
    sym = next(s for s in coff.function_symbols() if s[0] == r["symbol"])
    issues, mapping = [], {}
    calls, thisdecls = {}, []
    for off, target_sym, typ, addend_bytes in coff.function_relocs(sym):
        if target_sym is None:
            issues.append(("unknown_symbol", off))
            continue
        name = target_sym[0]
        orig, = struct.unpack("<I", xbe.data[xbe.offset(addr + off):xbe.offset(addr + off) + 4])
        addend, = struct.unpack("<i", addend_bytes)
        if typ == REL32:
            target = (addr + off + 4 + struct.unpack("<i", struct.pack("<I", orig))[0] - addend) & 0xFFFFFFFF
        elif typ == DIR32:
            target = (orig - addend) & 0xFFFFFFFF
        else:
            issues.append(("reloc_type_%#x" % typ, name))
            continue
        kind = classify(name)
        if typ == REL32 and kind == "symbol":
            calls[name] = target
        if mapping.get(name, target) != target:
            issues.append(("inconsistent", name))
        mapping[name] = target
        if kind == "string":
            ours = literal_bytes(coff, target_sym)
            o = xbe.offset(target)
            if ours is None or o is None or xbe.data[o:o + len(ours)] != ours:
                issues.append(("string_mismatch", name))
        elif kind == "float":
            hexbits = name[len("__real@"):]
            want = bytes.fromhex(hexbits)[::-1]
            o = xbe.offset(target)
            if o is None or xbe.data[o:o + len(want)] != want:
                issues.append(("float_mismatch", name))
        elif kind == "vftable":
            owner = st["vftables"].get(target)
            if owner is None:
                issues.append(("not_a_vftable", name))
            else:
                ours_cls = name[len("??_7"):].split("@6B")[0]
                if ".?AV" + ours_cls + "@" != owner and ".?AU" + ours_cls + "@" != owner \
                        and ours_cls + "@" not in owner:
                    issues.append(("vftable_of_other_class", name))  # names may be invented: warning
        elif typ == REL32:
            if target not in st["funcs"]:
                # Usually a function Ghidra didn't split out; not proof of a wrong match.
                issues.append(("call_target_not_known_function", name))
        else:
            sec = xbe.section_of(target)
            if sec is None:
                issues.append(("data_outside_image", name))
            elif sec.name == ".text" and target in st["funcs"]:
                issues.append(("function_address_as_data", name))  # e.g. int global holding &func: type wrong, bytes fine
            elif sec.name == ".text" and not (addr <= target < addr + 0x10000):
                issues.append(("data_in_code", name))
            # Other sections (.rdata/.data, XDK D3D/XGRPH/DSOUND data, BINKDATA) hold real globals.
    # (cl5) a callee declared as a free __cdecl/__stdcall function that takes `this` in ecx
    for name, target in sorted(calls.items()):
        rec = thiscall_decl_issue(name, target)
        if rec:
            issues.append(("free_decl_of_thiscall", name))
            thisdecls.append(rec)
    # (cl3) a global the source defines: its initial bytes must be the original's
    inits = initializer_diffs(coff.data, mapping, xbe_read(xbe))
    for rec in inits:
        issues.append(("initializer_mismatch", rec["symbol"]))
    targets = Counter(mapping.values())
    for name, t in mapping.items():
        if targets[t] > 1 and classify(name) == "symbol":
            issues.append(("aliased_target", name))
    SOFT = ("vftable_of_other_class", "aliased_target", "call_target_not_known_function", "function_address_as_data")
    hard = [i for i in issues if i[0] not in SOFT]
    return {"addr": "0x%08x" % addr, "status": "ok" if not hard else "bad", "relocs": len(mapping),
            "issues": issues, "map": {k: "0x%08x" % v for k, v in mapping.items()},
            **({"initializers": inits} if inits else {}), **({"thiscall_decls": thisdecls} if thisdecls else {})}


_STRIP = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S)
_NOT_DEF = re.compile(r"^\s*(?:extern|typedef|using|template|friend|class|struct|union|enum|namespace|#)\b|^\s*#")


def may_define_data(text):
    """Cheap, conservative text test: could this source define a global (a namespace-scope variable, a static data
    member, a function-local static)? False only when it certainly doesn't."""
    t = _STRIP.sub(lambda m: " " if m.group(0)[0] in "/" else '""', text)
    if re.search(r"\bstatic\b(?![^;{]*\()", t):
        return True               # a static variable (not a static member function declaration)
    depth, transparent, stmt = 0, [], ""
    for line in t.splitlines():
        if line.lstrip().startswith("#"):
            continue
        for c in line + "\n":
            if c == "{":
                head = stmt.strip()
                tr = depth == len(transparent) and re.match(r'(?:namespace\b[^=]*|extern\s*""\s*)$', head)
                if tr:
                    transparent.append(depth)
                elif depth == len(transparent) and "=" in head:
                    return True       # an aggregate initializer at namespace scope
                depth += 1
                stmt = "" if (tr or depth > len(transparent)) else stmt
                continue
            if c == "}":
                depth -= 1
                if transparent and transparent[-1] == depth:
                    transparent.pop()
                    stmt = ""
                elif depth == len(transparent):
                    stmt = "}"         # a class body closed: `} g;` defines g
                continue
            if depth != len(transparent):
                continue
            if c == ";":
                s = stmt.strip()
                if s.startswith("}") and s.strip("} \n"):
                    return True
                if s.startswith("extern") and "=" in s:
                    return True       # `extern "C" const float k = 1.0f;` defines k
                if s and s != "}" and not _NOT_DEF.match(s) and ("=" in s or "(" not in s or "(*" in s.replace(" ", "")):
                    return True
                stmt = ""
                continue
            stmt += c
    return False


def init_job(path):
    """(cl3) The initializer check for one matches/ or equivalent/ source: [records] (empty: none)."""
    addr = int(os.path.basename(path)[2:10], 16)
    if not may_define_data(open(path, errors="replace").read()):
        return path, "skip", []
    try:
        if "/matches/" in path:
            r = check(path, addr)
            if r.get("status") == "not_matching":
                import equiv
                r2 = equiv.verify(path, addr, max_level=2)
                return path, "equiv", [i for i in (r2.get("level2") or {}).get("issues", [])
                                       if i["kind"] == "initializer_differs"]
            return path, "relocs", r.get("initializers", [])
        import equiv
        r = equiv.verify(path, addr, max_level=2)
        return path, "equiv", [i for i in (r.get("level2") or {}).get("issues", []) if i["kind"] == "initializer_differs"]
    except Exception as e:  # noqa: BLE001
        return path, "error", [{"error": repr(e)[:200]}]


# (cl4) Literals. literal_bytes() above compares a literal's full extent. The sweep (--literals) re-checks the
# sources that have a literal with a NUL before its end (a wide string, or an escape \\0 / \\x0 in a narrow one):
# for a matches/ source with check() (its reloc map), for an equivalents/ source (no reloc map) that the literal's
# full bytes occur somewhere in the image.
_NUL_LITERAL = re.compile(r'L"|\\(?:0|x0)')


def literal_job(path):
    """(path, how, [records]) for one matches/ or equivalent/ source."""
    addr = int(os.path.basename(path)[2:10], 16)
    if not _NUL_LITERAL.search(open(path, errors="replace").read()):
        return path, "skip", []
    try:
        if "/matches/" in path:
            r = check(path, addr)
            if r.get("status") != "not_matching":
                return path, "relocs", [{"kind": "string_mismatch", "symbol": n, "target": r["map"].get(n)}
                                        for k, n in r.get("issues", []) if k == "string_mismatch"]
        xbe = state()["xbe"]
        with tempfile.TemporaryDirectory() as tmp:
            coff = Coff(compile_obj(path, DEFAULT_FLAGS, tmp))
        out = []
        for sym in coff.symbols:
            if sym[0].startswith("??_C@") and sym[2] > 0:
                lit = literal_bytes(coff, sym)
                if lit and xbe.data.find(lit) < 0:
                    out.append({"kind": "string_not_in_image", "symbol": sym[0], "bytes": lit.hex()})
        return path, "image", out
    except Exception as e:  # noqa: BLE001
        return path, "error", [{"error": repr(e)[:200]}]


def _job(path):
    try:
        return check(path, int(os.path.basename(path)[:-4], 16))
    except Exception as e:  # keep the sweep going
        return {"addr": os.path.basename(path)[:-4], "status": "error", "detail": repr(e)[:200]}


def main():
    p = argparse.ArgumentParser()
    p.add_argument("file", nargs="?")
    p.add_argument("--only", help="file with addresses to (re)check")
    p.add_argument("--addr", help="target address for FILE (default: from the file name)")
    p.add_argument("--json", action="store_true", help="one-line JSON (for the farm)")
    p.add_argument("--all", action="store_true")
    p.add_argument("--jobs", type=int, default=8)
    p.add_argument("--out", default=os.path.join(ROOT, "build/reloc-report.jsonl"))
    p.add_argument("--initializers", metavar="OUT", help="(cl3) check the initializers of every matches/ and "
                   "equivalent/ source that may define a global; violations to OUT (JSON)")
    p.add_argument("--literals", metavar="OUT", help="(cl4) check the string literals (full extent, wide strings, "
                   "embedded NULs) of every matches/ and equivalent/ source that has one; violations to OUT (JSON)")
    a = p.parse_args()
    if a.literals:
        files = sorted(os.path.join(ROOT, d, f) for d in ("matches", "equivalent")
                       for f in os.listdir(os.path.join(ROOT, d)) if f.endswith(".cpp"))
        out, counts = {}, Counter()
        with Pool(a.jobs) as pool:
            for path, how, recs in pool.imap_unordered(literal_job, files, chunksize=8):
                counts[how] += 1
                if recs:
                    out[os.path.relpath(path, ROOT)] = recs
                    counts["violating"] += 1
        json.dump({"counts": dict(counts), "violations": dict(sorted(out.items()))}, open(a.literals, "w"), indent=1)
        print("results:", dict(counts))
        return
    if a.initializers:
        files = sorted(os.path.join(ROOT, d, f) for d in ("matches", "equivalent")
                       for f in os.listdir(os.path.join(ROOT, d)) if f.endswith(".cpp"))
        out, counts = {}, Counter()
        with Pool(a.jobs) as pool:
            for i, (path, how, recs) in enumerate(pool.imap_unordered(init_job, files, chunksize=8)):
                counts[how] += 1
                if recs:
                    out[os.path.relpath(path, ROOT)] = recs
                    counts["violating"] += 1
                if (i + 1) % 2000 == 0:
                    print("  %d/%d %s" % (i + 1, len(files), dict(counts)), flush=True)
        json.dump({"counts": dict(counts), "violations": dict(sorted(out.items()))}, open(a.initializers, "w"), indent=1)
        print("results:", dict(counts))
        return
    if a.file:
        r = check(a.file, int(a.addr, 16)) if a.addr else _job(a.file)
        print(json.dumps(r) if a.json else json.dumps(r, indent=1))
        return
    files = sorted(os.path.join(ROOT, "matches", f) for f in os.listdir(os.path.join(ROOT, "matches")))
    if a.only:
        want = {l.strip() for l in open(a.only) if l.strip()}
        files = [f for f in files if os.path.basename(f)[:-4] in want]
    counts, issue_counts = Counter(), Counter()
    with open(a.out, "w") as out, Pool(a.jobs) as pool:
        for i, r in enumerate(pool.imap_unordered(_job, files, chunksize=16)):
            out.write(json.dumps(r) + "\n")
            counts[r["status"]] += 1
            for kind, _ in r.get("issues", []):
                issue_counts[kind] += 1
            if (i + 1) % 1000 == 0:
                print("  %d/%d %s" % (i + 1, len(files), dict(counts)), flush=True)
    print("results:", dict(counts))
    print("issues:", dict(issue_counts.most_common()))


if __name__ == "__main__":
    main()
