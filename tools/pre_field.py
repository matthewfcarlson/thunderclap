#!/usr/bin/env python3
"""(integ7, item 8; rev5) Range contracts on words of the object a member function runs on: the 32-bit offsetof probe
and the writer census behind tools/equiv.py's `// pre: ge(*this+0xOFF.f32, 0)` items (docs/equivalence.md "Range
contracts on object words").

probe(src, addr, exprs)
    The block's definition (the member function whose body holds its HULK_PRE_* macros) is found in a libclang i386
    parse of the TU (tools/equiv64.py's front end, the 32-bit layout MSVC 7.1 and the original share); each macro
    subject (`shake[0].time`) is resolved as a field path of the definition's class: {expr: (byte offset, "f" | "i",
    bytes)} or {expr: "error ..."}. A field reached through a base adds that base's offset; constant indices only.

census(addr, offs, text)
    Every writer of the contract's words the reviewers must judge, and which of them the block's comment leaves
    uncited. The class is the definition's (its RTTI name by the last component), plus every RTTI class derived from
    it. Two halves:
      typed  every tree TU that names one of these classes (a text prefilter) is parsed (i386); a store to a member
             lvalue (`=`, a compound assignment, `++` / `--`, or the address taken: `&p->f`) whose object is of one of
             these classes (by its record's name, in any namespace: gen's classes and TU-local views alike) and whose
             32-bit offsets (every element for a variable index) overlap a contract word is a writer: its block's
             address must be cited in `// pre-writers:`.
      raw    the machine code of the classes' methods (every slot of their RTTI vftables, and every function that
             references one of those vftables: the constructors and destructors): each store whose memory operand is
             [reg + disp] (reg not esp / ebp) with [disp, disp + size) overlapping a contract word's offset must be
             cited (its instruction or its function in `// pre-writers:`) or dismissed with a reason
             (`// pre-writers-dismissed: 0xINSN (why) ...`).
    Residual, a reviewed claim (rev5): stores through views of other names outside these methods, pointer-strided
    stores (`p->time` walking the array), whole-object copies and memset, reference bindings.

callee_writers(addr, cited)
    The cited writer functions the block itself calls directly: an item whose writer is a callee is refused (the
    harness stubs the callee and keeps the word in range, where the claim is the callee's)."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
_PARSES = {}


class ProbeError(Exception):
    pass


def _parse(src):
    """A libclang i386 parse of SRC as tools/equiv64.py prepares it (cached per path and text)."""
    import tempfile
    import equiv64
    text = open(src, errors="replace").read()
    key = (os.path.abspath(src), hash(text))
    t = _PARSES.get(key)
    if t is not None:
        return t
    m = equiv64.ci()
    d = tempfile.mkdtemp(prefix="prefield-")
    w = equiv64.write_wrapper(src, d)
    args = [a for a in equiv64.front_flags("i686-pc-windows-msvc") if a != "-O0"] + \
        ["-w", "-DHULK_EQ64_PARSE", "-I" + d] + equiv64.tree_inc() + ["-I" + os.path.join(ROOT, "include")]
    tu = m.Index.create().parse(w, args=args)
    errs = [str(x) for x in tu.diagnostics if x.severity >= 3]
    if errs:
        raise ProbeError("libclang (i386): " + "; ".join(errs[:3]))
    # (positions are the wrapper's: libclang reports expansion locations, and the prepared text can add lines)
    t = _PARSES[key] = (tu, w, open(w, errors="replace").read())
    if len(_PARSES) > 8:
        _PARSES.pop(next(iter(_PARSES)))
    return t


def _block_lines(text, addr):
    """(first, last) 1-based lines of block ADDR in TEXT (its header to the line before the next block's header)."""
    lines = text.splitlines()
    hdr = "// 0x%08x " % addr
    s = next((i for i, l in enumerate(lines) if l.startswith(hdr)), None)
    if s is None:
        if not any(re.match(r"^// 0x[0-9a-f]{8} ", l) for l in lines):
            return 1, len(lines)        # (a one-function source, a regress case: the whole file is the block)
        raise ProbeError("no block 0x%08x in the TU" % addr)
    e = next((i for i in range(s + 1, len(lines)) if re.match(r"^// 0x[0-9a-f]{8} ", lines[i])), len(lines))
    return s + 1, e


def _same_file(c, src):
    f = c.location.file
    return f is not None and os.path.abspath(f.name) == os.path.abspath(src)


def definition(src, addr):
    """The member function definition of block ADDR that holds its HULK_PRE_* macros (the last definition in the block
    before the first macro, as equiv._pre_definition chooses), and its class's record cursor."""
    tu, w, text = _parse(src)
    l0, l1 = _block_lines(text, addr)
    lines = text.splitlines()
    mac = next((i + 1 for i in range(l0 - 1, l1) if re.search(r"\bHULK_PRE_[A-Z]+\s*\(", lines[i].split("//")[0])), None)
    m = __import__("equiv64").ci()
    best = None
    for c in tu.cursor.walk_preorder():
        if c.kind not in (m.CursorKind.CXX_METHOD, m.CursorKind.CONSTRUCTOR, m.CursorKind.DESTRUCTOR) or \
                not c.is_definition() or not _same_file(c, w):
            continue
        s, e = c.extent.start.line, c.extent.end.line
        if not (l0 <= s <= l1):
            continue
        if mac is not None and not (s <= mac <= e):
            continue
        best = c
    if best is None:
        raise ProbeError("block 0x%08x: no member function definition holding its HULK_PRE_* macros" % addr)
    rec = best.semantic_parent
    if rec is None or rec.kind not in (m.CursorKind.STRUCT_DECL, m.CursorKind.CLASS_DECL):
        raise ProbeError("block 0x%08x: the definition is not a member of a class" % addr)
    return best, rec.type.get_canonical().get_declaration()


def _field(rec, name, depth=0):
    """(byte offset, FIELD_DECL) of field NAME in record REC (its own fields first, then its bases), or None."""
    m = __import__("equiv64").ci()
    rec = rec.type.get_canonical().get_declaration()
    for c in rec.get_children():
        if c.kind == m.CursorKind.FIELD_DECL and c.spelling == name:
            o = c.get_field_offsetof()
            if o < 0 or o % 8:
                return None
            return o // 8, c
    if depth > 16:
        return None
    for c in rec.get_children():
        if c.kind == m.CursorKind.CXX_BASE_SPECIFIER:
            if c.is_virtual_base():
                continue
            b = c.type.get_canonical().get_declaration()
            r = _field(b, name, depth + 1)
            if r is not None:
                bo = c.get_base_offsetof(rec)
                if bo < 0 or bo % 8:
                    return None
                return bo // 8 + r[0], r[1]
    return None


def _scalar(t):
    """("f" | "i" | "u" | None, bytes) of a canonical type."""
    k = t.kind.name
    if k == "FLOAT":
        return "f", 4
    if k in ("INT", "LONG", "SHORT", "SCHAR", "CHAR_S", "LONGLONG"):
        return "i", t.get_size()
    if k in ("UINT", "ULONG", "USHORT", "UCHAR", "CHAR_U", "ULONGLONG", "BOOL"):
        return "u", t.get_size()
    return None, t.get_size()


def resolve(rec, expr):
    """(byte offset, kind, bytes) of the field path EXPR (`shake[0].time`) in record REC (32-bit layout)."""
    off = 0
    cur = rec
    t = None
    for part in expr.split("."):
        mp = re.match(r"^([A-Za-z_]\w*)(?:\[(\d+)\])?$", part)
        if not mp or cur is None:
            raise ProbeError("%s: not a field path" % expr)
        r = _field(cur, mp.group(1))
        if r is None:
            raise ProbeError("%s: no field %s" % (expr, mp.group(1)))
        off += r[0]
        t = r[1].type.get_canonical()
        if mp.group(2) is not None:
            if t.kind.name != "CONSTANTARRAY":
                raise ProbeError("%s: %s is not an array" % (expr, mp.group(1)))
            k = int(mp.group(2))
            if not 0 <= k < t.get_array_size():
                raise ProbeError("%s: index %d past the array's %d elements" % (expr, k, t.get_array_size()))
            et = t.get_array_element_type().get_canonical()
            off += k * et.get_size()
            t = et
        cur = t.get_declaration() if t.kind.name == "RECORD" else None
    kind, size = _scalar(t)
    return off, kind, size


def probe(src, addr, exprs):
    """{expr: (offset, kind, bytes)} (or {expr: "error: ..."}) of the macro subjects EXPRS of block ADDR."""
    out = {}
    try:
        _d, rec = definition(src, addr)
    except ProbeError as e:
        return {x: "error: %s" % e for x in exprs}
    for x in exprs:
        try:
            out[x] = resolve(rec, x)
        except ProbeError as e:
            out[x] = "error: %s" % e
    return out


# --------------------------------------------------------------------------------------------------------- census
def class_family(name):
    """(RTTI mangled names, unqualified names) of the RTTI class named NAME (last component) and every class derived
    from it."""
    import equiv
    p = equiv.Program.get()
    roots = [mg for mg, c in p.rtti.items() if c.get("name") == name or mg == ".?AV%s@@" % name]
    fam = set(roots)
    for mg, c in p.rtti.items():
        if any(b["name"] in roots for b in c.get("bases", [])):
            fam.add(mg)
    names = {name} | {p.rtti[mg].get("name") or re.sub(r"^\.\?A[UV]([^@]+)@.*$", r"\1", mg) for mg in fam}
    return sorted(fam), sorted(names)


def _lvalue_offsets(e, names, m, depth=0, this_rec=None):
    """(record name, {32-bit byte offsets}, bytes) of member lvalue E rooted in an object of a class in NAMES, or None.
    A variable index takes every element."""
    if depth > 24:
        return None
    k = e.kind
    if k in (m.CursorKind.UNEXPOSED_EXPR, m.CursorKind.PAREN_EXPR):
        ch = list(e.get_children())
        return _lvalue_offsets(ch[0], names, m, depth + 1, this_rec) if len(ch) == 1 else None
    if k == m.CursorKind.ARRAY_SUBSCRIPT_EXPR:
        ch = list(e.get_children())
        if len(ch) != 2:
            return None
        b = _lvalue_offsets(ch[0], names, m, depth + 1, this_rec)
        if b is None:
            return None
        a = ch[0]
        bt = a.type.get_canonical()
        while bt.kind.name != "CONSTANTARRAY" and a.kind in (m.CursorKind.UNEXPOSED_EXPR, m.CursorKind.PAREN_EXPR):
            kids = list(a.get_children())      # (through the array-to-pointer decay)
            if len(kids) != 1:
                break
            a = kids[0]
            bt = a.type.get_canonical()
        if bt.kind.name != "CONSTANTARRAY":
            return None
        es = bt.get_array_element_type().get_canonical().get_size()
        n = bt.get_array_size()
        idx = None
        try:
            toks = [t.spelling for t in ch[1].get_tokens()]
            if len(toks) == 1 and re.match(r"^\d+$", toks[0]):
                idx = int(toks[0])
        except Exception:   # noqa: BLE001
            pass
        ks = [idx] if idx is not None else range(n)
        return b[0], {o + j * es for o in b[1] for j in ks}, es
    if k != m.CursorKind.MEMBER_REF_EXPR:
        return None
    f = e.referenced
    if f is None or f.kind != m.CursorKind.FIELD_DECL:
        return None
    ch = list(e.get_children())
    size = f.type.get_canonical().get_size()
    if ch:
        base = ch[0]
        bt = base.type.get_canonical()
        if bt.kind.name == "POINTER":
            bt = bt.get_pointee().get_canonical()
            inner = None
        else:
            inner = _lvalue_offsets(base, names, m, depth + 1, this_rec)
    else:
        bt = None       # implicit this
        inner = None
    if inner is not None:
        rec = bt.get_declaration() if bt is not None else None
        r = _field(rec, f.spelling) if rec is not None else None
        if r is None:
            return None
        return inner[0], {o + r[0] for o in inner[1]}, size
    if bt is None:
        # implicit `this`: the enclosing member function's class
        rec = this_rec
    else:
        rec = bt.get_declaration()
    if rec is None or rec.spelling not in names:
        return None
    r = _field(rec, f.spelling)
    if r is None:
        return None
    return rec.spelling, {r[0]}, size


def typed_writers(names, offs, tus=None):
    """[(TU, line, block address or None, what)] of every typed store to a contract word (see the module doc)."""
    m = __import__("equiv64").ci()
    pat = re.compile(r"\b(%s)\b" % "|".join(map(re.escape, names)))
    if tus is None:
        tus = []
        for dp, _dn, fns in os.walk(os.path.join(ROOT, "src")):
            for fn in fns:
                if fn.endswith(".cpp"):
                    tus.append(os.path.join(dp, fn))
    out, errs = [], []
    words = set(offs)
    for tu_path in sorted(tus):
        try:
            text = open(tu_path, errors="replace").read()
        except OSError:
            continue
        if not pat.search(text):
            continue
        try:
            tu, w, text = _parse(tu_path)
        except Exception as e:     # noqa: BLE001
            errs.append("%s: %s" % (os.path.relpath(tu_path, ROOT), e))
            continue
        heads = [(i + 1, int(mm.group(1), 16)) for i, l in enumerate(text.splitlines())
                 for mm in [re.match(r"^// (0x[0-9a-f]{8}) ", l)] if mm]

        def block_of(line):
            a = None
            for hl, ha in heads:
                if hl <= line:
                    a = ha
            return a
        def walk(c, rec):
            yield c, rec
            for x in c.get_children():
                r_ = rec
                if x.kind in (m.CursorKind.CXX_METHOD, m.CursorKind.CONSTRUCTOR, m.CursorKind.DESTRUCTOR):
                    r_ = x.semantic_parent
                for y in walk(x, r_):
                    yield y
        for c, this_rec in walk(tu.cursor, None):
            if not _same_file(c, w):
                continue
            lhs, what = None, None
            if c.kind in (m.CursorKind.BINARY_OPERATOR, m.CursorKind.COMPOUND_ASSIGNMENT_OPERATOR):
                try:
                    op = c.binary_operator
                    is_as = bool(op.is_assignment)
                except Exception:   # noqa: BLE001
                    is_as = c.kind == m.CursorKind.COMPOUND_ASSIGNMENT_OPERATOR
                if is_as:
                    lhs, what = next(iter(c.get_children()), None), "store"
            elif c.kind == m.CursorKind.UNARY_OPERATOR:
                toks = [t.spelling for t in c.get_tokens()]
                if toks and (toks[0] in ("++", "--", "&") or toks[-1] in ("++", "--")):
                    lhs = next(iter(c.get_children()), None)
                    what = "address taken" if toks[0] == "&" else "increment"
            if lhs is None:
                continue
            r = _lvalue_offsets(lhs, set(names), m, 0, this_rec)
            if r is None:
                continue
            rn, os_, sz = r
            if any(o < w + 4 and w < o + sz for o in os_ for w in words):
                ln = c.location.line
                out.append((os.path.relpath(tu_path, ROOT), ln, block_of(ln), "%s %s (%s)" % (
                    what, " ".join(t.spelling for t in lhs.get_tokens())[:60], rn)))
    return out, errs


def class_methods(fam):
    """The functions of the classes' RTTI vftables plus the functions referencing those vftables."""
    import equiv
    p = equiv.Program.get()
    fns = set()
    for mg in fam:
        for v in p.rtti[mg]["vtables"]:
            fns.update(v.get("slots") or ())
            for site in equiv.pre_callers(v["address"]):
                cf = p.containing_func(site)
                if cf:
                    fns.add(cf[0])
    return sorted(f for f in fns if f in p.funcs)


def raw_writers(fam, offs):
    """[(function, instruction, text)] of the stores in the classes' methods to [reg + disp] overlapping a word."""
    import capstone
    from capstone import x86
    import equiv
    p = equiv.Program.get()
    out = []
    for f in class_methods(fam):
        code = p.read(f, p.funcs[f][0])
        for ci in p.md.disasm(code, f):
            for op in ci.operands:
                if op.type == x86.X86_OP_MEM and (op.access & capstone.CS_AC_WRITE) and \
                        op.mem.base not in (0, x86.X86_REG_ESP, x86.X86_REG_EBP):
                    d, n = op.mem.disp, op.size
                    if any(d < o + 4 and o < d + n for o in offs):
                        out.append((f, ci.address, "%s %s" % (ci.mnemonic, ci.op_str)))
    return out


def block_text(text, addr):
    """Block ADDR's lines of TEXT (a TU: its citations are the block's own, never another block's)."""
    l0, l1 = _block_lines(text, addr)
    return "\n".join(text.splitlines()[l0 - 1:l1])


def cited(text):
    """(cited addresses, {dismissed instruction: reason}) from TEXT's `// pre-writers:` / `// pre-writers-dismissed:`
    lines (a dismissal needs a parenthesized reason after its address)."""
    c, dis = set(), {}
    for l in text.splitlines():
        mm = re.match(r"^\s*//\s*pre-writers:\s*(.*)$", l)
        if mm:
            c |= {int(x, 16) for x in re.findall(r"0x[0-9a-fA-F]+", mm.group(1))}
        mm = re.match(r"^\s*//\s*pre-writers-dismissed:\s*(.*)$", l)
        if mm:
            for a, why in re.findall(r"(0x[0-9a-fA-F]+)\s*\(([^()]+)\)", mm.group(1)):
                dis[int(a, 16)] = why.strip()
    return c, dis


def census(src, addr, offs, text):
    """{"typed": [...], "raw": [...], "missing": [descriptions], "errors": [...], "family": [...]}: the writers of
    the contract words OFFS of block ADDR and which are uncited in TEXT (the block's comment)."""
    _d, rec = definition(src, addr)
    fam, names = class_family(rec.spelling)
    if not fam:
        raise ProbeError("class %s: no RTTI class of that name (the raw census needs its vftables)" % rec.spelling)
    names = sorted(set(names) | {rec.spelling})
    ty, errs = typed_writers(names, offs)
    raw = raw_writers(fam, offs)
    c, dis = cited(block_text(text, addr))
    missing = []
    for tu, ln, blk, what in ty:
        if blk is None or blk not in c:
            missing.append("typed %s:%d %s (block %s)" % (tu, ln, what, "0x%08x" % blk if blk is not None else "none"))
    for f, ia, what in raw:
        if ia not in c and f not in c and ia not in dis:
            missing.append("raw 0x%08x in 0x%08x: %s" % (ia, f, what))
    return {"typed": ty, "raw": raw, "missing": missing, "errors": errs, "family": fam}


def callee_writers(addr, writers):
    """The functions in WRITERS (addresses) the original block ADDR calls directly (E8 rel32 in its extent)."""
    import equiv
    p = equiv.Program.get()
    sz = p.funcs.get(addr, (0,))[0]
    code = p.read(addr, sz)
    calls = set()
    for ci in p.md.disasm(code, addr):
        if ci.mnemonic in ("call", "jmp") and ci.operands and ci.operands[0].type == 2:     # X86_OP_IMM
            calls.add(ci.operands[0].imm & 0xFFFFFFFF)
    return sorted(calls & set(writers) - {addr})


if __name__ == "__main__":
    import json
    src, a = sys.argv[1], int(sys.argv[2], 16)
    cmd = sys.argv[3] if len(sys.argv) > 3 else "census"
    if cmd == "probe":
        print(json.dumps(probe(src, a, sys.argv[4:])))
    else:
        offs = [int(x, 16) for x in sys.argv[4:]]
        text = open(src, errors="replace").read()
        r = census(src, a, offs, text)
        print(json.dumps({k: [list(x) if isinstance(x, tuple) else x for x in v] for k, v in r.items()}, indent=1))
