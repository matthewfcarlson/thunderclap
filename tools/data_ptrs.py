#!/usr/bin/env python3
"""How the sources use the game's data items, for pointer-sized data (docs/native-mac.md section 10, docs/data.md).

  build/venv/bin/python tools/data_ptrs.py scan [FILE...] --out ACC.jsonl     # every access to a DAT_<addr> item
  build/venv/bin/python tools/data_ptrs.py evidence ACC.jsonl                 # -> config/data-ptrs.json
  build/venv/bin/python tools/data_ptrs.py lint ACC.jsonl [--json OUT]        # code that will break on 64-bit

On the 32-bit builds a data item that holds a pointer at run time is often declared (by data_gen or the source) as
an integer or a byte array, and read through a pun: `*(CSimDb**)&DAT_004dd700`, `((void**)&DAT_x)[i]`,
`*(T**)((char*)&DAT_x + 8)`. With 8-byte pointers that reads the word and the one after it. tools/data_gen.py has
to know which words of an item hold pointers to give them pointer types (8 bytes, 8-aligned on 64-bit, 4 on 32-bit
so the 32-bit objects stay identical); the XBE only shows the ones initialized to an address.

`scan` parses each source that names an address-named global (`DAT_<addr>`, `hulk_at_<addr>`) with libclang for the
32-bit MS target (the game's layout: byte offsets as the sources spell them), follows each reference through `&`,
casts, constant `+`/`-`, subscripts and member accesses to the access it ends in, and records one row per access:
item address, byte offset in the variable (null when indexed by a non-constant), access size, kind (pointer / int /
float / record / ...), the pointee type spelled, and whether the item's address itself escapes (passed, compared,
stored) with the byte offset added.

`evidence` aggregates the pointer accesses per data item into config/data-ptrs.json (offsets of the words that
hold pointers, a pointer table's range, the pointee class when the sources agree on one): data_gen's input, names and
offsets only (no game bytes).

`lint` lists the accesses that stay wrong on 64-bit once the items have their pointer types: a byte offset into a
pointer-holding item past its first pointer (the offset is a 32-bit layout), an integer access to a word that holds
a pointer (hashing, compares, arithmetic on a pointer kept as an int), and an indexed access with a 4-byte stride
over a pointer table.
"""
import argparse
import collections
import concurrent.futures
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ptr1  # noqa: E402

ci, CK, TK = ptr1.ci, ptr1.CK, ptr1.TK
ROOT = ptr1.ROOT
EVIDENCE = os.path.join(ROOT, "config/data-ptrs.json")
NAME = re.compile(r"^(?:DAT|hulk_at)_([0-9a-fA-F]{8})$")
MENTION = re.compile(rb"\b(?:DAT|hulk_at)_[0-9a-fA-F]{8}\b")
TARGET = "i686-pc-windows-msvc"
INT_KINDS = {TK.INT, TK.UINT, TK.LONG, TK.ULONG, TK.SHORT, TK.USHORT, TK.CHAR_S, TK.CHAR_U, TK.SCHAR, TK.UCHAR,
             TK.LONGLONG, TK.ULONGLONG, TK.BOOL, TK.ENUM}


def kind_of(t):
    c = t.get_canonical()
    k = c.kind
    if k in (TK.POINTER, TK.MEMBERPOINTER):
        return "pointer"
    if k in INT_KINDS:
        return "int"
    if k in (TK.FLOAT, TK.DOUBLE, TK.LONGDOUBLE):
        return "float"
    if k == TK.RECORD:
        return "record"
    if k in (TK.CONSTANTARRAY, TK.INCOMPLETEARRAY):
        return "array"
    if k == TK.FUNCTIONPROTO:
        return "function"
    return k.name.lower()


def size_of(t):
    try:
        s = t.get_canonical().get_size()
    except Exception:  # noqa: BLE001
        return None
    return s if s and s > 0 else None


def elem_of(t):
    c = t.get_canonical()
    if c.kind in (TK.CONSTANTARRAY, TK.INCOMPLETEARRAY):
        return c.element_type
    if c.kind == TK.POINTER:
        return c.get_pointee()
    return None


def literal(u, n):
    """Integer value of a constant operand (a literal, a negated or parenthesized one), else None."""
    n = ptr1.strip(n)
    if n.kind == CK.INTEGER_LITERAL:
        toks = list(n.cur.get_tokens())
        if toks:
            s = re.sub(r"[uUlL]+$", "", toks[0].spelling)
            try:
                return int(s, 0)
            except ValueError:
                return None
    if n.kind == CK.UNARY_OPERATOR and n.kids:
        toks = list(n.cur.get_tokens())
        if toks and toks[0].spelling == "-":
            v = literal(u, n.kids[0])
            return -v if v is not None else None
    if n.kind in ptr1.CASTS and n.kids:
        return literal(u, n.kids[-1])
    return None


def first_tok(n):
    return next(iter(n.cur.get_tokens()), None)


def record_layout(t):
    """[[offset, name, type spelling, kind, element size, count]] of a record's fields (arrays: their element), the
    record's own layout in the 32-bit target."""
    out = []
    c = t.get_canonical()
    for f in c.get_fields():
        try:
            off = c.get_offset(f.spelling) // 8
        except Exception:  # noqa: BLE001
            return None
        ft = f.type.get_canonical()
        n = 1
        if ft.kind == TK.CONSTANTARRAY:
            n = ft.element_count
            ft = ft.element_type.get_canonical()
        if f.is_bitfield():
            return None
        k = kind_of(ft)
        row = [off, f.spelling, ft.spelling if k in ("int", "float") else f.type.spelling, k, size_of(ft), n]
        if row[3] == "record":
            sub = record_layout(ft)
            if sub is None:
                return None
            row.append(sub)
        elif row[3] == "pointer" and ft.get_pointee().get_canonical().kind == TK.FUNCTIONPROTO:
            row[3] = "code"
        out.append(row)
    return out


def follow(u, ref):
    """From a DeclRefExpr of an address-named variable to the access it ends in. Returns a dict."""
    vt = ref.cur.type
    arr = vt.get_canonical().kind in (TK.CONSTANTARRAY, TK.INCOMPLETEARRAY)
    # state: ("lval", off, type) or ("addr", off, pointee type)
    st = ["lval", 0, vt]
    raw = [False]           # some offset came from a non-pointer stride (a 32-bit byte layout)
    recd = {}               # the access goes through a cast to a record pointer: the record and where
    n = ref
    p = n.parent
    escape = None
    while p is not None:
        k = p.kind
        if k == CK.PAREN_EXPR:
            n, p = p, p.parent
            continue
        if k == CK.UNEXPOSED_EXPR:
            # implicit conversions: array decay, lvalue-to-rvalue, derived-to-base, ...
            if st[0] == "lval" and st[2].get_canonical().kind in (TK.CONSTANTARRAY, TK.INCOMPLETEARRAY) and \
                    p.cur.type.get_canonical().kind == TK.POINTER:
                st = ["addr", st[1], elem_of(st[2])]
            n, p = p, p.parent
            continue
        if k == CK.UNARY_OPERATOR:
            t = first_tok(p)
            op = t.spelling if t is not None and t.extent.start.offset == p.s else None
            if op == "&" and st[0] == "lval":
                st = ["addr", st[1], st[2]]
            elif op == "*" and st[0] == "addr":
                st = ["lval", st[1], st[2]]
            else:
                break
            n, p = p, p.parent
            continue
        if k in ptr1.CASTS:
            pt = p.cur.type.get_canonical()
            if st[0] == "addr" and pt.kind == TK.POINTER:
                st = ["addr", st[1], p.cur.type.get_pointee() if p.cur.type.kind == TK.POINTER else pt.get_pointee()]
                if st[2].get_canonical().kind == TK.RECORD and not recd:
                    recd.update(base=st[1], type=st[2].get_canonical().spelling, size=size_of(st[2]),
                               fields=record_layout(st[2]))
                n, p = p, p.parent
                continue
            if st[0] == "lval" and st[2].get_canonical().kind in (TK.CONSTANTARRAY, TK.INCOMPLETEARRAY) and \
                    pt.kind == TK.POINTER:
                st = ["addr", st[1], pt.get_pointee()]
                n, p = p, p.parent
                continue
            break
        if k == CK.BINARY_OPERATOR and st[0] == "addr" and len(p.kids) == 2 and p.kids[0] is n:
            op, _ = ptr1.binop(u, p)
            if op in ("+", "-"):
                v = literal(u, p.kids[1])
                es = size_of(st[2]) or 1
                if v and kind_of(st[2]) != "pointer":
                    raw[0] = True
                if st[1] is not None and v is not None:
                    st = ["addr", st[1] + (v if op == "+" else -v) * es, st[2]]
                else:
                    st = ["addr", None, st[2]]
                n, p = p, p.parent
                continue
            break
        if k == CK.ARRAY_SUBSCRIPT_EXPR and st[0] == "addr" and p.kids and p.kids[0] is n:
            v = literal(u, p.kids[1]) if len(p.kids) > 1 else None
            es = size_of(st[2]) or 1
            if recd and "index" not in recd and st[2].get_canonical().kind == TK.RECORD:
                recd["index"] = v
            if v and kind_of(st[2]) != "pointer":
                raw[0] = True
            st = ["lval", st[1] + v * es if (v is not None and st[1] is not None) else None, st[2]]
            if v is None:
                st.append("indexed")
            n, p = p, p.parent
            continue
        if k == CK.MEMBER_REF_EXPR and p.cur.referenced is not None and p.cur.referenced.kind == CK.FIELD_DECL:
            f = p.cur.referenced
            rec = f.semantic_parent.type
            try:
                fo = rec.get_offset(f.spelling) // 8
            except Exception:  # noqa: BLE001
                fo = -1
            if fo < 0:
                break
            if st[0] == "addr" or (st[0] == "lval" and st[2].get_canonical().kind == TK.RECORD):
                if fo:
                    raw[0] = True
                if recd and "field" not in recd:
                    recd.update(field=f.spelling, field_off=fo)
                st = ["lval", st[1] + fo if st[1] is not None else None, f.type] + st[3:]
                n, p = p, p.parent
                continue
            break
        break
    row = {"line": ref.cur.location.line, "var": ref.cur.spelling, "decl": vt.spelling, "raw_off": raw[0]}
    if recd:
        row["rec"] = recd
    if st[0] == "lval":
        row.update(off=st[1], size=size_of(st[2]), kind=kind_of(st[2]), type=st[2].spelling,
                   indexed=len(st) > 3)
        # how: a store (left of =), else a read
        if p is not None and p.kind in (CK.BINARY_OPERATOR, CK.COMPOUND_ASSIGNMENT_OPERATOR) and p.kids and \
                p.kids[0] is n:
            op, _ = ptr1.binop(u, p)
            row["how"] = "store" if op and op.endswith("=") and op not in ("==", "!=", "<=", ">=") else "read"
        else:
            row["how"] = "read"
        if row["kind"] == "int" and p is not None and p.kind in ptr1.CASTS and \
                p.cur.type.get_canonical().kind == TK.POINTER:
            row["int_as_pointer"] = p.cur.type.spelling
    else:
        row.update(off=st[1], kind="address", type=st[2].spelling if st[2] is not None else None,
                   size=size_of(st[2]) if st[2] is not None else None)
        row["how"] = p.kind.name.lower() if p is not None else "?"
    return row


def scan_file(path):
    path = os.path.abspath(path)
    src = open(path, "rb").read()
    if not MENTION.search(src):
        return os.path.relpath(path, ROOT), [], None
    try:
        u = ptr1.Unit(path, src, TARGET)
    except Exception as e:  # noqa: BLE001
        return os.path.relpath(path, ROOT), [], repr(e)
    rows = []
    for n in u.nodes:
        if n.kind != CK.DECL_REF_EXPR:
            continue
        r = n.cur.referenced
        if r is None or r.kind != CK.VAR_DECL:
            continue
        m = NAME.match(r.spelling)
        if not m:
            continue
        try:
            row = follow(u, n)
        except Exception as e:  # noqa: BLE001
            row = {"line": n.cur.location.line, "var": r.spelling, "error": repr(e)[:200]}
        row["addr"] = int(m.group(1), 16)
        rows.append(row)
    return os.path.relpath(path, ROOT), rows, None if not u.errors else "%d clang errors" % u.errors


def cmd_scan(a):
    files = []
    for f in a.files or ["matches", "equivalent"]:
        if f.startswith("@"):
            files += [x.strip() for x in open(f[1:]) if x.strip()]
        elif os.path.isdir(f):
            files += sorted(os.path.join(f, x) for x in os.listdir(f) if re.fullmatch(r"0x[0-9a-f]{8}\.cpp", x))
        else:
            files.append(f)
    n = errs = 0
    with open(a.out, "w") as fo, concurrent.futures.ProcessPoolExecutor(a.jobs) as ex:
        for rel, rows, err in ex.map(scan_file, files, chunksize=16):
            errs += err is not None
            if err is not None:
                print("  %s: %s" % (rel, err), file=sys.stderr)
            for r in rows:
                r["src"] = rel
                fo.write(json.dumps(r) + "\n")
                n += 1
    print("%d sources, %d accesses, %d with parse errors" % (len(files), n, errs))


# ---------------------------------------------------------------------------------------------- aggregation
def model():
    import data_gen
    return data_gen.Model()


def rows_of(path):
    for l in open(path):
        r = json.loads(l)
        if "error" not in r:
            yield r


def per_item(m, rows):
    """{item addr: {"ptr": {off: Counter(pointee types)}, "table": [(start, srcs)], "int": {off: [rows]}, ...}}"""
    out = collections.defaultdict(lambda: {"ptr": collections.defaultdict(collections.Counter),
                                           "ptr_src": collections.defaultdict(set), "table": collections.defaultdict(set),
                                           "int": collections.defaultdict(list), "other": [], "addr_esc": []})
    for r in rows:
        it = m.item_at(r["addr"])
        if it is None or not m.emitted(it):
            continue
        base = r["addr"] - it["addr"]
        e = out[it["addr"]]
        off = None if r.get("off") is None else base + r["off"]
        if r["kind"] == "pointer" and r.get("size") == 4:
            if off is not None and not r.get("indexed"):
                e["ptr"][off][r["type"]] += 1
                e["ptr_src"][off].add(r["src"])
                if r.get("raw_off") or base:
                    e.setdefault("ptr_raw", collections.defaultdict(set))[off].add((r["src"], r["line"]))
            else:
                e["table"][base].add(r["src"])
        elif r["kind"] == "int" and r.get("size") == 4 and off is not None:
            e["int"][off].append(r)
        elif r["kind"] == "address":
            e["addr_esc"].append(r)
        else:
            e["other"].append(r)
    return out


POINTEE = re.compile(r"^(?:const\s+)?(?:struct\s+|class\s+)?([A-Za-z_][\w:]*)\s*\*$")


def shape(fields):
    """A record layout without names and pointer/integer kinds: what two sources must agree on."""
    return [(f[0], f[4], f[5], shape(f[6]) if len(f) > 6 else (f[3] == "float")) for f in fields]


def leaves(fields, base=0):
    """[(offset, size, kind)] of a layout's scalar leaves, arrays expanded."""
    out = []
    for f in fields:
        for j in range(f[5]):
            o = base + f[0] + j * f[4]
            if len(f) > 6:
                out += leaves(f[6], o)
            else:
                out.append((o, f[4], f[3]))
    return out


def set_leaf(fields, off, kind, base=0):
    """Mark the scalar leaf at offset off as kind (a field array with one pointer element becomes all pointers:
    an array has one element type)."""
    for f in fields:
        for j in range(f[5]):
            o = base + f[0] + j * f[4]
            if len(f) > 6:
                if o <= off < o + f[4]:
                    set_leaf(f[6], off, kind, o)
                    return
            elif o == off:
                f[3] = kind
                return


def merge_fields(layouts):
    """One field list from several sources' layouts of the same shape: names and types from the first, a leaf is a
    pointer (code) when any source uses it as one."""
    out = json.loads(json.dumps(layouts[0]))
    for other in layouts[1:]:
        for f, g in zip(out, other):
            if len(f) > 6:
                f[6] = merge_fields([f[6], g[6]])
            elif g[3] in ("pointer", "code") and f[3] not in ("pointer", "code"):
                f[2], f[3] = g[2], g[3]
            elif g[3] == "code" and f[3] == "pointer":
                f[2], f[3] = g[2], g[3]
    return out


def record_views(m, rows):
    """{item addr: [{"base", "stride", "fields", "types", "sources"}]}: the record types sources cast the item to,
    merged per (base, stride) when their shapes agree; a shape conflict is reported as {"conflict": ...}."""
    uses = collections.defaultdict(lambda: collections.defaultdict(dict))   # addr -> (base, stride) -> type -> (fields, src)
    for r in rows:
        rc = r.get("rec")
        if not rc or rc.get("fields") is None or rc.get("base") is None or not rc.get("size"):
            continue
        it = m.item_at(r["addr"])
        if it is None or not m.emitted(it):
            continue
        base = r["addr"] - it["addr"] + rc["base"]
        uses[it["addr"]][(base, rc["size"])].setdefault(rc["type"], (rc["fields"], r["src"]))
    out = {}
    for addr, views in uses.items():
        vs = []
        for (base, stride), types in sorted(views.items()):
            ts = sorted(types.items(), key=lambda kv: kv[1][1])
            shapes = {json.dumps(shape(f)) for _, (f, _) in ts}
            if len(shapes) > 1:
                # different field breakdowns: take the one with the most pointer leaves when every other layout's
                # pointer leaves are 4-byte leaves of it (the others only split the plain bytes differently)
                cand = sorted(ts, key=lambda kv: (-len([x for x in leaves(kv[1][0]) if x[2] in ("pointer", "code")]),
                                                  -len(leaves(kv[1][0])), kv[1][1]))
                best = cand[0][1][0]
                bl = {(o, sz): k for o, sz, k in leaves(best)}
                if all((o, sz) in bl for _, (f, _) in cand[1:] for o, sz, k in leaves(f) if k in ("pointer", "code")):
                    fields = json.loads(json.dumps(best))
                    for _, (f, _) in cand[1:]:
                        for o, sz, k in leaves(f):
                            if k in ("pointer", "code") and bl[(o, sz)] not in ("pointer", "code"):
                                set_leaf(fields, o, k)
                    vs.append({"base": "0x%x" % base, "stride": stride, "fields": fields, "types": sorted(t for t, _ in ts),
                               "sources": sorted({sr for _, (_, sr) in ts}), "merged": "leaves"})
                    continue
                vs.append({"base": "0x%x" % base, "stride": stride, "conflict": sorted("%s (%s)" % (t, sr) for t, (_, sr) in ts)})
                continue
            vs.append({"base": "0x%x" % base, "stride": stride, "fields": merge_fields([f for _, (f, _) in ts]),
                       "types": sorted(t for t, _ in ts), "sources": sorted({sr for _, (_, sr) in ts})})
        out[addr] = vs
    return out


def cmd_evidence(a):
    m = model()
    rows = list(rows_of(a.acc))
    agg = per_item(m, rows)
    views = record_views(m, rows)
    items = {}
    for addr in sorted(set(agg) | set(views)):
        e = agg[addr]
        it = m.item_at(addr)
        ptrs = sorted(o for o in e["ptr"] if 0 <= o and o + 4 <= it["size"] and o % 4 == 0 and (it["addr"] + o) % 4 == 0)
        table = sorted(o for o in e["table"] if 0 <= o < it["size"])
        rv = [v for v in views.get(addr, ()) if "conflict" in v or json.dumps(v["fields"]).count('"pointer"') +
              json.dumps(v["fields"]).count('"code"')]
        if not ptrs and not table and not rv:
            continue
        row = {"name": it["cname"], "size": it["size"]}
        if rv:
            row["records"] = rv
        if ptrs:
            row["pointers"] = ["0x%x" % o for o in ptrs]
            types = {}
            for o in ptrs:
                ts = {POINTEE.match(t).group(1) if POINTEE.match(t) else None for t in e["ptr"][o]}
                if len(ts) == 1 and None not in ts:
                    types["0x%x" % o] = ts.pop()
            if types:
                row["pointee"] = types
        if table:
            row["table_from"] = ["0x%x" % o for o in table]
        row["sources"] = sorted({s for o in ptrs for s in e["ptr_src"][o]} | {s for o in table for s in e["table"][o]} |
                                {s for v in rv for s in v.get("sources", ())})[:6]
        items["0x%08x" % it["addr"]] = row
    doc = {"_comment": "Words of the game's data items that hold pointers at run time, from the sources' accesses "
                       "(tools/data_ptrs.py evidence): byte offsets in the item (`pointers`), pointer tables indexed "
                       "from an offset to the item's end (`table_from`), the pointee class the sources agree on. "
                       "tools/data_gen.py gives these words pointer types. Names and offsets only.",
           "items": items}
    out = a.out or EVIDENCE
    json.dump(doc, open(out, "w"), indent=1, sort_keys=True)
    print("%d items with pointer evidence (%d words, %d tables, %d record views, %d conflicting) -> %s" % (
        len(items), sum(len(r.get("pointers", [])) for r in items.values()),
        sum(len(r.get("table_from", [])) for r in items.values()),
        sum(1 for r in items.values() for v in r.get("records", ()) if "fields" in v),
        sum(1 for r in items.values() for v in r.get("records", ()) if "conflict" in v), os.path.relpath(out, ROOT)))


def load_evidence(path=EVIDENCE):
    try:
        return json.load(open(path)).get("items", {})
    except (OSError, ValueError):
        return {}


def cmd_lint(a):
    """Accesses that are wrong on 64-bit, given which words hold pointers (data_gen's emitted layout:
    build/data/pointers.json, else the evidence plus the XBE's initialized pointers)."""
    import data_gen
    m = model()
    layout = data_gen.pointer_layout(m)          # {item addr: set(offsets of pointer words)}
    recs = data_gen.record_items(m)               # {item addr: stride}: emitted as the sources' record type
    rows = []
    for r in rows_of(a.acc):
        it = m.item_at(r["addr"])
        rc = r.get("rec")
        # an access through the record type the item is emitted as indexes it correctly on every target
        if it is not None and it["addr"] in recs and rc and rc.get("size") == recs[it["addr"]] and \
                r["addr"] - it["addr"] + (rc.get("base") or 0) == 0:
            continue
        # a pointer-sized integer (hulk_intptr / hulk_uintptr) read or written at a pointer word is what it holds
        if r.get("kind") == "int" and "hulk_" in (r.get("type") or "") and "ptr" in (r.get("type") or ""):
            continue
        rows.append(r)
    agg = per_item(m, rows)
    hits = collections.defaultdict(list)
    for addr, e in agg.items():
        pw = layout.get(addr)
        if not pw:
            continue
        it = m.item_at(addr)
        first = min(pw)
        for o, rs in e["int"].items():
            if o in pw:
                for r in rs:
                    hits["int access to a pointer word"].append((r["src"], r["line"], it["cname"], o, r["type"]))
        for o, srcs in e.get("ptr_raw", {}).items():
            if o > first:
                for src, line in sorted(srcs):
                    hits["byte offset into a pointer-holding item"].append((src, line, it["cname"], o,
                                                                           "+".join(e["ptr"][o])))
        for r in e["addr_esc"]:
            if r.get("off") not in (None, 0) and (r["addr"] - addr + (r["off"] or 0)) > first:
                hits["address with a byte offset into a pointer-holding item"].append(
                    (r["src"], r["line"], it["cname"], r["addr"] - addr + r["off"], r.get("type")))
        for r in e["other"]:
            if r.get("kind") == "int" and r.get("indexed") and r.get("size") == 4:
                hits["indexed 4-byte integer access over a pointer item"].append(
                    (r["src"], r["line"], it["cname"], r.get("off"), r["type"]))
    rep = {k: {"count": len(v), "sources": len({x[0] for x in v}), "rows": sorted(v, key=str)} for k, v in hits.items()}
    for k, v in sorted(rep.items()):
        print("%-60s %5d accesses in %4d sources" % (k, v["count"], v["sources"]))
    if a.json:
        json.dump(rep, open(a.json, "w"), indent=1)
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("scan")
    s.add_argument("files", nargs="*")
    s.add_argument("--out", required=True)
    s.add_argument("--jobs", type=int, default=2)
    e = sub.add_parser("evidence")
    e.add_argument("acc")
    e.add_argument("--out")
    li = sub.add_parser("lint")
    li.add_argument("acc")
    li.add_argument("--json")
    a = ap.parse_args()
    return {"scan": cmd_scan, "evidence": cmd_evidence, "lint": cmd_lint}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
