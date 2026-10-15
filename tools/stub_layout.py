"""Member-level model and MSVC (x86, /Zp8) layout of the stub classes in matches/ and equivalent/ sources.

Used by tools/gen_tree.py to merge layout-compatible variants of one class name inside a translation unit,
and by tools/reconcile_stubs.py. Deliberately conservative: anything it does not understand (templates,
bit-fields, virtual or multiple inheritance, overloaded virtuals, unknown by-value types) makes the class
`unsupported`, and an unsupported class is never merged.

    ctx = Context(items)                 # cxx_items items of one source (or of a merged TU)
    lay = ctx.layout("ParamIntConstRange")
    lay.size, lay.align, lay.poly, lay.fields, lay.slots, lay.base

Fields are absolute: (offset, size, name, type) with `type` the normalized type text ("int", "Owner *",
"char [16]"); `slots` is the full vftable as [(name, params, ret, cv)].
"""
import re

import cxx_items

PRIM = {
    ("char",): (1, 1), ("signed", "char"): (1, 1), ("unsigned", "char"): (1, 1), ("bool",): (1, 1),
    ("__int8",): (1, 1), ("unsigned", "__int8"): (1, 1),
    ("short",): (2, 2), ("short", "int"): (2, 2), ("signed", "short"): (2, 2), ("unsigned", "short"): (2, 2),
    ("unsigned", "short", "int"): (2, 2), ("wchar_t",): (2, 2), ("__wchar_t",): (2, 2), ("__int16",): (2, 2),
    ("unsigned", "__int16"): (2, 2),
    ("int",): (4, 4), ("signed",): (4, 4), ("signed", "int"): (4, 4), ("unsigned",): (4, 4),
    ("unsigned", "int"): (4, 4), ("long",): (4, 4), ("long", "int"): (4, 4), ("signed", "long"): (4, 4),
    ("unsigned", "long"): (4, 4), ("unsigned", "long", "int"): (4, 4), ("float",): (4, 4), ("__int32",): (4, 4),
    ("unsigned", "__int32"): (4, 4),
    ("double",): (8, 8), ("long", "double"): (8, 8), ("__int64",): (8, 8), ("unsigned", "__int64"): (8, 8),
    ("long", "long"): (8, 8), ("unsigned", "long", "long"): (8, 8), ("signed", "__int64"): (8, 8),
}
# spelling synonyms (same type): used to normalize type text
SYNONYM = {
    "signed": "int", "signed int": "int", "unsigned": "unsigned int", "long int": "long", "signed long": "long",
    "unsigned long int": "unsigned long", "short int": "short", "signed short": "short",
    "unsigned short int": "unsigned short", "signed char": "signed char", "__int32": "int",
    "unsigned __int32": "unsigned int", "__int16": "short", "unsigned __int16": "unsigned short",
    "long long": "__int64", "unsigned long long": "unsigned __int64", "signed __int64": "__int64",
    "__int8": "char", "unsigned __int8": "unsigned char",
}
PACK = 8
CV = {"const", "volatile"}
CALLCONV = {"__cdecl", "__stdcall", "__fastcall", "__thiscall", "_cdecl"}
ELAB = {"struct", "class", "union", "enum"}


class Unsupported(Exception):
    pass


def norm_type(words):
    """Normalized spelling of a type given as a token list: 'unsigned' -> 'unsigned int', no elaborated
    keywords, 'char const *' -> 'const char *'."""
    ws = [w for w in words if w not in ELAB]
    k = 0
    while k < len(ws) and ws[k] not in ("*", "&"):
        k += 1
    base, tail = ws[:k], ws[k:]
    cv = sorted({w for w in base if w in CV})
    b = " ".join(w for w in base if w not in CV)
    b = SYNONYM.get(b, b).replace(" :: ", "::")
    return " ".join(cv + ([b] if b else []) + tail)


# ---------------------------------------------------------------------------------------------
class Member:
    """One member of a class body."""
    __slots__ = ("kind", "name", "toks", "text", "access", "virtual", "static", "params", "ret", "cv",
                 "body", "pure", "decls", "pos")

    def __init__(self, kind, name, toks, text, access):
        self.kind, self.name, self.toks, self.text, self.access = kind, name, toks, text, access
        self.virtual = self.static = self.pure = False
        self.params = self.ret = self.cv = self.body = None
        self.decls = []      # fields: [(name, type tokens, array dims, fnptr)]
        self.pos = 0

    def __repr__(self):
        return "Member(%s %s)" % (self.kind, self.name)


class ClassDef:
    """A parsed class/struct definition (from a cxx_items 'class' item)."""

    def __init__(self, item, text_of=None):
        self.item = item
        ts = item.toks
        vs = [t.v for t in ts]
        self.name = item.name
        self.scope = item.scope
        if item.kind != "class":
            raise Unsupported("not a plain class (%s)" % item.kind)
        i = 0
        while i < len(ts) and (vs[i] in ("typedef", "const", "volatile", "static", "extern") or ts[i].t == "str"):
            i += 1
        i = cxx_items._skip_declspec(ts, i)
        self.key = vs[i]
        if self.key not in ("class", "struct"):
            raise Unsupported("union")
        i = cxx_items._skip_declspec(ts, i + 1)
        j = vs.index("{")
        head = vs[i:j]
        if ":" in head:
            k = head.index(":")
            nm = head[:k]
            bases = self._bases(head[k + 1:])
        else:
            nm, bases = head, []
        if len(nm) != 1:
            raise Unsupported("qualified or templated class name %s" % " ".join(nm))
        self.bases = bases
        close = cxx_items._match(ts, j, "{", "}")
        if [t.v for t in ts[close + 1:]] not in ([";"], []):
            raise Unsupported("declarator after the class body")
        self.body_toks = ts[j + 1:close]
        self.src = item.text
        self.base_off = ts[0].s
        self.members = self._members()

    @staticmethod
    def _bases(vs):
        out, cur = [], []
        for v in vs + [","]:
            if v == ",":
                if cur:
                    acc = "private"
                    virt = False
                    names = []
                    for w in cur:
                        if w in ("public", "private", "protected"):
                            acc = w
                        elif w == "virtual":
                            virt = True
                        else:
                            names.append(w)
                    if virt:
                        raise Unsupported("virtual base")
                    if "<" in names:
                        raise Unsupported("template base")
                    out.append(("".join(names), acc))
                cur = []
            else:
                cur.append(v)
        return out

    def _members(self):
        ts = self.body_toks
        out = []
        access = "private" if self.key == "class" else "public"
        i, n = 0, len(ts)
        cur = []
        while i < n:
            t = ts[i]
            if not cur and t.v in ("public", "private", "protected") and i + 1 < n and ts[i + 1].v == ":":
                access = t.v
                i += 2
                continue
            if t.t == "pp":
                raise Unsupported("preprocessor line in class body")
            if t.v == ";":
                if cur:
                    out.append(self._member(cur, access, None))
                cur = []
                i += 1
                continue
            if t.v in ("(", "["):
                k = cxx_items._match(ts, i, t.v, ")" if t.v == "(" else "]")
                cur.extend(ts[i:k + 1])
                i = k + 1
                continue
            if t.v == "{":
                k = cxx_items._match(ts, i, "{", "}")
                vs = [x.v for x in cur]
                if vs and (vs[0] in ELAB or vs[0] == "typedef" or vs[0] == "enum"):
                    # nested type: runs to the ';'
                    cur.extend(ts[i:k + 1])
                    i = k + 1
                    while i < n and ts[i].v != ";":
                        cur.append(ts[i])
                        i += 1
                    out.append(self._member(cur + [ts[i]] if i < n else cur, access, None, nested=True))
                    cur = []
                    i += 1
                    continue
                if "=" in vs:
                    raise Unsupported("braced initializer in class body")
                out.append(self._member(cur, access, ts[i:k + 1]))
                cur = []
                i = k + 1
                if i < n and ts[i].v == ";":
                    i += 1
                continue
            cur.append(t)
            i += 1
        if cur:
            raise Unsupported("unterminated member")
        for k, m in enumerate(out):
            m.pos = k
        return out

    def text(self, toks):
        return self.src[toks[0].s - self.base_off:toks[-1].e - self.base_off]

    def _member(self, toks, access, body, nested=False):
        vs = [t.v for t in toks]
        full = toks + (body or [])
        text = self.text(full)
        if nested or (vs and vs[0] in ("typedef", "friend", "using", "enum")):
            name = None
            if vs[0] == "typedef":
                ids = [t.v for t in toks if t.t == "id" and t.v not in cxx_items.KEYWORDS]
                name = ids[-1] if ids else None
            elif vs[0] in ELAB or vs[0] == "enum":
                if len(vs) > 1 and toks[1].t == "id":
                    name = vs[1]
                if "{" in vs:
                    close = cxx_items._match(toks, vs.index("{"), "{", "}")
                    if [v for v in vs[close + 1:] if v != ";"]:
                        raise Unsupported("nested type with a declarator")
                    if name is None and vs[0] == "union" and vs[1] == "{":
                        return self._anon_union(toks, close, access, text)
                    if name is None and vs[0] != "enum":
                        raise Unsupported("anonymous struct/union member")
            m = Member("other", name, full, text, access)
            return m
        if vs and vs[0] == "template":
            raise Unsupported("member template")
        # function or field?
        fnptr = None
        paren = None
        k = 0
        while k < len(vs):
            v = vs[k]
            if v == "[":
                k = cxx_items._match(toks, k, "[", "]") + 1
                continue
            if v == "operator":
                paren = k + 1
                while paren < len(vs) and vs[paren] != "(":
                    paren += 1
                if paren < len(vs) and vs[paren - 1] == "operator" and paren + 1 < len(vs) and vs[paren + 1] == ")":
                    paren += 2          # operator()
                break
            if v == "(":
                inner = vs[k + 1:k + 4]
                if inner and (inner[0] in ("*", "&") or inner[0] in CALLCONV
                              or (len(inner) >= 3 and inner[1] == "::" and inner[2] == "*")):
                    fnptr = k
                else:
                    paren = k
                break
            k += 1
        if paren is not None and fnptr is None:
            return self._method(toks, vs, paren, access, body, text)
        if body is not None:
            raise Unsupported("body on a non-function member")
        m = Member("field", None, full, text, access)
        if "static" in vs:
            m.static = True
        if ":" in vs and "::" not in vs[vs.index(":") - 1:vs.index(":")]:
            raise Unsupported("bit-field")
        if "=" in vs:
            if not m.static:
                raise Unsupported("initialized field")
        m.decls = self._declarators(toks)
        m.name = m.decls[0][0]
        return m

    def _anon_union(self, toks, close, access, text):
        """`union { T a; U b; };`: a member whose fields share one offset."""
        m = Member("union", None, toks, text, access)
        inner = toks[2:close]
        cur = []
        subs = []
        for t in inner:
            if t.v in ("{", "}"):
                raise Unsupported("nested aggregate in an anonymous union")
            if t.v == ";":
                if cur:
                    subs.append(cur)
                cur = []
                continue
            cur.append(t)
        if cur:
            raise Unsupported("unterminated union member")
        for st in subs:
            f = self._member(st, access, None)
            if f.kind != "field" or f.static:
                raise Unsupported("non-field in an anonymous union")
            m.decls.append(f)
        m.name = m.decls[0].name if m.decls else None
        return m

    def _method(self, toks, vs, paren, access, body, text):
        close = cxx_items._match(toks, paren, "(", ")")
        name_toks = []
        k = paren - 1
        if "operator" in vs[:paren]:
            oi = vs.index("operator")
            name = "operator" + "".join(vs[oi + 1:paren])
            pre = vs[:oi]
        else:
            name = vs[k]
            pre = vs[:k]
            if k > 0 and vs[k - 1] == "~":
                name = "~"
                pre = vs[:k - 1]
        del name_toks
        m = Member("method", name, toks + (body or []), text, access)
        m.virtual = "virtual" in pre
        m.static = "static" in pre
        ret = [v for v in pre if v not in ("virtual", "static", "inline", "__inline", "__forceinline",
                                            "explicit", "__cdecl")]
        m.ret = norm_type(ret)
        m.params = norm_params(toks[paren + 1:close])
        tail = vs[close + 1:]
        if "=" in tail and tail[-1:] == ["0"]:
            m.pure = True
            tail = tail[:tail.index("=")]
        m.cv = " ".join(tail)
        if body is not None:
            m.body = " ".join(t.v for t in body)
        return m

    def _declarators(self, toks):
        """[(name, type tokens, dims, fnptr text)] of a field declaration (several declarators possible)."""
        vs = [t.v for t in toks]
        vs = [v for v in vs if v not in ("static", "mutable")]
        # split at top-level commas
        parts, cur, depth = [], [], 0
        for v in vs:
            if v in ("(", "[", "<"):
                depth += 1
            elif v in (")", "]", ">"):
                depth -= 1
            if v == "," and depth == 0:
                parts.append(cur)
                cur = []
                continue
            cur.append(v)
        parts.append(cur)
        first = parts[0]
        # base type: leading tokens up to the first declarator token
        out = []
        if "(" in first and ("[" not in first or first.index("(") < first.index("[")):
            # function pointer / member function pointer: T (C::*name)(args)
            p = first.index("(")
            q = first.index(")", p)
            inner = first[p + 1:q]
            ids = [v for v in inner if re.match(r"[A-Za-z_]\w*$", v) and v not in cxx_items.KEYWORDS]
            if not ids:
                raise Unsupported("unnamed function pointer")
            name = ids[-1]
            cls = None
            if "::" in inner:
                cls = "".join(inner[:inner.index("::")]).strip()
                cls = [v for v in inner[:inner.index("::")] if v not in CALLCONV and v != "*"]
                cls = "::".join(c for c in cls if c != "::") if cls else None
            if len(parts) > 1:
                raise Unsupported("several function pointer declarators")
            rest = first[q + 1:]
            dims = []
            ftype = " ".join(first[:p] + ["("] + [v for v in inner if v != name] + [")"] + rest)
            out.append((name, ["<fnptr>", cls], dims, ftype))
            return out
        # T *a, b[3], **c;
        k = 0
        base = []
        while k < len(first) and first[k] not in ("*", "&"):
            base.append(first[k])
            k += 1
        # the last identifier of base (before * or [) is the name when no '*' follows
        decl0 = first[k:]
        if not decl0:
            # name is the last token of base (before any '[')
            if "[" in base:
                b = base.index("[")
                decl0 = base[b - 1:]
                base = base[:b - 1]
            else:
                decl0 = base[-1:]
                base = base[:-1]
        decls = [decl0] + parts[1:]
        for d in decls:
            ptr = []
            j = 0
            while j < len(d) and d[j] in ("*", "&", "const", "volatile"):
                ptr.append(d[j])
                j += 1
            if j >= len(d) or not re.match(r"[A-Za-z_]\w*$", d[j]):
                raise Unsupported("declarator %r" % d)
            name = d[j]
            dims = []
            r = d[j + 1:]
            while r:
                if r[0] != "[":
                    raise Unsupported("declarator tail %r" % r)
                e = r.index("]")
                dims.append(eval_const(r[1:e]))
                r = r[e + 1:]
            out.append((name, base + ptr, dims, None))
        return out


def norm_params(toks):
    s = cxx_items._strip_param_names(toks) if toks else ""
    if s in ("void", ""):
        return ""
    parts = []
    for p in split_commas(s):
        parts.append(norm_type(p.split()))
    return ",".join(parts)


def split_commas(s):
    out, cur, depth = [], "", 0
    for ch in s:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
            continue
        cur += ch
    out.append(cur)
    return out


def eval_const(vs):
    """Value of an integer constant expression of literals (array bounds: `0x108 - 0xe0`)."""
    if not vs:
        raise Unsupported("array of unknown bound")
    s = " ".join(vs)
    s2 = re.sub(r"\b(0[xX][0-9a-fA-F]+|\d+)[uUlL]*\b", lambda m: str(int(m.group(1), 0)), s)
    if not re.fullmatch(r"[\d\s+\-*/()%<>]*", s2):
        raise Unsupported("array bound %s" % s)
    try:
        v = eval(s2.replace("/", "//"), {"__builtins__": {}})
    except Exception:
        raise Unsupported("array bound %s" % s)
    if not isinstance(v, int) or v < 0:
        raise Unsupported("array bound %s" % s)
    return v


# ---------------------------------------------------------------------------------------------
class Field:
    __slots__ = ("off", "size", "align", "name", "type", "decl", "union_ok", "by_value_class", "own")

    def __init__(self, off, size, align, name, type_, decl, union_ok, by_value_class, own=True):
        self.off, self.size, self.align, self.name, self.type = off, size, align, name, type_
        self.decl, self.union_ok, self.by_value_class, self.own = decl, union_ok, by_value_class, own

    def sig(self):
        return (self.off, self.size, self.type)

    def __repr__(self):
        return "Field(+0x%x %s %s)" % (self.off, self.type, self.name)


class Layout:
    def __init__(self):
        self.size = 0
        self.align = 1
        self.poly = False
        self.base = None            # base class name (as written)
        self.base_size = 0
        self.base_slots = 0
        self.fields = []            # [Field], absolute, base fields included (own=False)
        self.slots = []             # [(name, params, ret, cv)]
        self.own_slots = []
        self.dtor = None            # None, "virtual", "plain"
        self.ctors = []
        self.pod = True
        self.cls = None


class Context:
    """Definitions of one source (or of a merged TU), keyed by qualified name, and their layouts."""

    def __init__(self, items, replace=None):
        self.classes = {}
        self.typedefs = {}
        self.enums = set()
        self.fwd = {}
        for it in items:
            k = it.key[0] if it.key else None
            q = it.key[1] if it.key else None
            if it.kind == "class" and k == "class":
                self.classes.setdefault(q, it)
            elif it.kind == "enum":
                self.enums.add(q)
            elif it.kind == "typedef":
                self.typedefs.setdefault(q, it)
            elif k == "fwd":
                self.fwd[q] = it
        if replace:
            self.classes.update(replace)
        self.cache = {}
        self.parsed = {}

    def resolve(self, name, scope):
        """Qualified key of `name` looked up from namespace `scope` (innermost first), or None."""
        name = name.lstrip(":")
        if name.startswith("::"):
            name = name[2:]
        for i in range(len(scope), -1, -1):
            q = "::".join(tuple(scope[:i]) + (name,))
            if q in self.classes or q in self.typedefs or q in self.enums or q in self.fwd:
                return q
        return None

    def classdef(self, q):
        if q not in self.parsed:
            it = self.classes.get(q)
            if it is None:
                self.parsed[q] = Unsupported("no definition of %s" % q)
            else:
                try:
                    self.parsed[q] = ClassDef(it)
                except Unsupported as e:
                    self.parsed[q] = e
                except (ValueError, IndexError) as e:
                    self.parsed[q] = Unsupported("parse: %s" % e)
        c = self.parsed[q]
        if isinstance(c, Unsupported):
            raise c
        return c

    def layout(self, q, stack=()):
        r = self.cache.get(q)
        if r is None:
            if q in stack:
                raise Unsupported("recursive layout %s" % q)
            try:
                r = self._layout(q, stack + (q,))
            except Unsupported as e:
                r = e
            self.cache[q] = r
        if isinstance(r, Unsupported):
            raise r
        return r

    def type_info(self, words, scope, stack, self_q=None):
        """(size, align, kind) of a type given as tokens (no declarator). kind: 'prim', 'ptr', 'enum',
        'memptr', 'class:<q>'."""
        ws = [w for w in words if w not in CV and w not in ELAB]
        if not ws:
            raise Unsupported("empty type")
        if ws[-1] in ("*", "&"):
            return 4, 4, "ptr" if ws[-1] == "*" else "ref"
        if ws[0] == "<fnptr>":
            if ws[1] is None:
                return 4, 4, "ptr"
            return self.memptr_size(ws[1], scope, self_q) + ("memptr",)
        t = tuple(ws)
        if t in PRIM:
            return PRIM[t] + ("prim",)
        if all(w == "::" or re.match(r"\w+$", w) for w in ws):
            q = self.resolve("".join(ws), scope)
            if q in self.enums:
                return 4, 4, "enum"
            if q in self.typedefs:
                return self.typedef_info(self.typedefs[q], stack)
            if q in self.classes:
                lay = self.layout(q, stack)
                return lay.size, lay.align, "class:" + q
        raise Unsupported("unknown type %s" % " ".join(ws))

    def typedef_info(self, td, stack):
        vs = [t.v for t in td.toks]
        if "{" in vs:
            raise Unsupported("typedef with a body")
        if "(" in vs:
            for i in range(len(vs) - 2):
                if vs[i + 1] == "::" and vs[i + 2] == "*":
                    return self.memptr_size(vs[i], td.scope, None) + ("memptr",)
            return 4, 4, "ptr"      # function pointer typedef
        body = vs[1:-1]   # drop 'typedef' and ';'
        if "[" in body:
            raise Unsupported("array typedef")
        if not body or body[-1] != td.name:
            raise Unsupported("typedef shape")
        return self.type_info(body[:-1], td.scope, stack)

    def memptr_size(self, cls, scope, self_q):
        q = self.resolve(cls, scope)
        if q is not None and q == self_q:
            c = self.classdef(q)
            return (4, 4) if len(c.bases) <= 1 else (8, 4)
        if q in self.classes:
            b = self.classdef(q)
            while True:
                if len(b.bases) > 1:
                    return 8, 4
                if not b.bases:
                    return 4, 4
                bq = self.resolve(b.bases[0][0], b.scope)
                if bq not in self.classes:
                    raise Unsupported("member pointer of class with unknown base")
                b = self.classdef(bq)
        fw = self.fwd.get(q) if q else None
        if fw is not None and re.search(r"single_inheritance|HULK_SINGLE_INHERITANCE", fw.text):
            return 4, 4
        raise Unsupported("member pointer of incomplete class %s" % cls)

    def _layout(self, q, stack):
        c = self.classdef(q)
        name = c.name
        L = Layout()
        L.cls = c
        own_virtual = [m for m in c.members if m.kind == "method" and m.virtual]
        if len(c.bases) > 1:
            raise Unsupported("multiple bases")
        cur = 0
        if c.bases:
            bq = self.resolve(c.bases[0][0], c.scope)
            if bq not in self.classes:
                raise Unsupported("base %s not defined" % c.bases[0][0])
            B = self.layout(bq, stack)
            L.base = bq
            L.pod = False
            if not B.poly and own_virtual:
                raise Unsupported("vfptr added below a non-polymorphic base")
            if not B.fields and not B.poly and B.base is None:
                raise Unsupported("empty base")
            L.poly = B.poly
            L.slots = list(B.slots)
            L.base_slots = len(B.slots)
            L.align = B.align
            cur = B.size
            L.base_size = B.size
            L.dtor = B.dtor if B.dtor == "virtual" else None
            L.fields = [Field(f.off, f.size, f.align, f.name, f.type, f.decl, f.union_ok, f.by_value_class, False)
                        for f in B.fields]
        names = {}
        for m in own_virtual:
            names.setdefault(m.name, []).append(m)
        for nm, ms in names.items():
            if len(ms) > 1:
                raise Unsupported("overloaded virtual %s" % nm)
        own = []
        for m in own_virtual:
            hit = None
            for i, s in enumerate(L.slots):
                if s[0] == m.name and (m.name == "~" or s[1] == m.params):
                    hit = i
                    break
            if hit is not None:
                L.slots[hit] = (m.name, m.params, m.ret, m.cv)
            else:
                if any(s[0] == m.name for s in L.slots):
                    raise Unsupported("virtual %s hides a base virtual" % m.name)
                L.slots.append((m.name, m.params, m.ret, m.cv))
                own.append(m.name)
        L.own_slots = own
        if own_virtual:
            L.pod = False
            if not L.poly:
                L.poly = True
                cur = 4
                L.align = max(L.align, 4)
        for m in c.members:
            if m.kind == "method":
                if m.name == "~":
                    L.dtor = "virtual" if (m.virtual or L.dtor == "virtual") else "plain"
                    L.pod = False
                elif m.name == name:
                    L.ctors.append(m.params)
                    L.pod = False
                elif m.name == "operator=":
                    L.pod = False
                continue
            if m.kind == "union":
                if m.access != "public":
                    L.pod = False
                ual, usz, subs = 1, 0, []
                for sub in m.decls:
                    for fname, tw, dims, ftext in sub.decls:
                        sz, al, kind = self.type_info(tw, c.scope, stack, self_q=q)
                        n = 1
                        for d in dims:
                            n *= d
                        ttext = re.sub(r"\s+", " ", ftext) if ftext else norm_type(tw)
                        if dims:
                            ttext += " " + "".join("[%d]" % d for d in dims)
                        al = min(al, PACK)
                        decl = sub.text.rstrip().rstrip(";") if len(sub.decls) == 1 else (
                            " ".join(tw) + " " + fname + "".join("[%d]" % d for d in dims))
                        subs.append((sz * n, al, fname, ttext, decl, kind))
                        ual, usz = max(ual, al), max(usz, sz * n)
                usz = (usz + ual - 1) // ual * ual
                cur = (cur + ual - 1) // ual * ual
                for sz, al, fname, ttext, decl, kind in subs:
                    L.fields.append(Field(cur, sz, al, fname, ttext, decl, kind in ("prim", "ptr", "enum", "memptr"),
                                          kind.startswith("class:")))
                cur += usz
                L.align = max(L.align, ual)
                continue
            if m.kind != "field" or m.static:
                continue
            if m.access != "public":
                L.pod = False
            single = len(m.decls) == 1
            for fname, tw, dims, ftext in m.decls:
                sz, al, kind = self.type_info(tw, c.scope, stack, self_q=q)
                if kind.startswith("class:"):
                    try:
                        if not self.layout(kind[6:], stack).pod:
                            L.pod = False
                    except Unsupported:
                        L.pod = False
                if kind == "ref":
                    L.pod = False
                ttext = re.sub(r"\s+", " ", ftext) if ftext else norm_type(tw)
                n = 1
                for d in dims:
                    n *= d
                if dims:
                    ttext += " " + "".join("[%d]" % d for d in dims)
                al = min(al, PACK)
                cur = (cur + al - 1) // al * al
                decl = m.text.rstrip().rstrip(";") if single else (
                    " ".join(tw) + " " + fname + "".join("[%d]" % d for d in dims))
                L.fields.append(Field(cur, sz * n, al, fname, ttext, decl, kind in ("prim", "ptr", "enum", "memptr"),
                                      kind.startswith("class:")))
                cur += sz * n
                L.align = max(L.align, al)
        if cur == 0 and not L.poly:
            L.size = 1
        else:
            L.size = (cur + L.align - 1) // L.align * L.align
        return L


# ---------------------------------------------------------------------------------------------
# Merging layout-compatible variants of one class name
class Variant:
    """One definition of a class name as one or more sources write it.

    item: the cxx_items class item; ctx: Context of a source that uses it (its base and member types are
    resolved there); refs: identifiers the users' code mentions outside this definition; defined: member
    names the users define out of line; users: number of functions using it."""

    def __init__(self, item, ctx, refs, defined=(), users=1, by_value=True):
        self.item, self.ctx, self.refs, self.defined, self.users = item, ctx, set(refs), set(defined), users
        self.by_value = by_value
        self.q = item.key[1]
        self.layout = ctx.layout(self.q)
        self.cls = self.layout.cls


SPECIAL_KINDS = ("ctor", "dtor", "assign")


def _special(m, cname):
    if m.kind != "method":
        return None
    if m.name == "~":
        return "dtor"
    if m.name == cname:
        return "ctor"
    if m.name == "operator=":
        return "assign"
    return None


def _param_list(params):
    if not params:
        return "", ""
    ps = split_commas(params)
    decl, call = [], []
    for i, p in enumerate(ps):
        if "(" in p or "..." in p:
            raise Unsupported("forwarder with a function-pointer or variadic parameter")
        decl.append("%s _m_a%d" % (p, i))
        call.append("_m_a%d" % i)
    return ", ".join(decl), ", ".join(call)


def merge_variants(variants):
    """Text of one class definition that every variant's users can compile against with unchanged code,
    or raise Unsupported. Members nobody mentions are dropped (padding takes their place); differently
    named fields at the same offset share an anonymous union; differently named virtuals at the same slot
    become one virtual plus inline forwarders."""
    v0 = variants[0]
    cname = v0.cls.name
    keys = {v.cls.key for v in variants}
    key = max(keys, key=lambda k: sum(v.users for v in variants if v.cls.key == k))
    for v in variants:
        if v.cls.scope != v0.cls.scope:
            raise Unsupported("variants in different namespaces")
    # ---- base and polymorphism
    based = [v for v in variants if v.layout.base]
    bases = {v.cls.bases[0][0] for v in based}
    base = None
    if bases:
        # one base name; a variant may name another base of the same layout if its code never mentions it
        base = max(bases, key=lambda n: (sum(v.users for v in based if v.cls.bases[0][0] == n), n))
        for v in based:
            if v.cls.bases[0][0] != base and v.cls.bases[0][0] in v.refs:
                raise Unsupported("different bases: %s" % ", ".join(sorted(bases)))
    start = 0
    nB = 0
    if based:
        bsz = {v.layout.base_size for v in based}
        bsl = {v.layout.base_slots for v in based}
        if len(bsz) > 1 or len(bsl) > 1:
            raise Unsupported("base layouts differ between variants")
        start, nB = bsz.pop(), bsl.pop()
    poly = any(v.layout.poly for v in variants)
    if poly and not base:
        start = 4
    base_slots = based[0].layout.slots[:nB] if based else []
    # ---- fields
    fields = {}
    for v in variants:
        for f in v.layout.fields:
            if not f.own:
                continue
            if f.name not in v.refs and not f.by_value_class:
                continue
            if f.off < start:
                raise Unsupported("field %s at +0x%x overlaps the base or vfptr" % (f.name, f.off))
            old = fields.get(f.name)
            if old is not None:
                if old.sig() != f.sig():
                    raise Unsupported("field %s differs: %s vs %s" % (f.name, old, f))
                continue
            fields[f.name] = f
    order = sorted(fields.values(), key=lambda f: (f.off, -f.size, f.name))
    groups = []
    for f in order:
        if groups and f.off < groups[-1][0].off + groups[-1][0].size:
            g = groups[-1]
            if (f.off, f.size) != (g[0].off, g[0].size):
                raise Unsupported("fields %s and %s overlap partially" % (g[0].name, f.name))
            g.append(f)
        else:
            groups.append([f])
    # ---- virtual slots and methods
    mem_names = set(fields)
    slots = {}          # absolute slot -> [(name, params, ret, cv, member, variant)]
    overrides = {}      # name -> member text (overrides of base slots)
    nonvirt = {}        # (name, params, cv) -> member
    special = {}        # kind -> {(params, cv, body)}
    others = {}         # name -> text
    statics = {}
    base_fwd = {}       # name -> (base slot name, slot, member)
    for v in variants:
        L = v.layout
        own = {m.name: m for m in v.cls.members if m.kind == "method" and m.virtual}
        for i, s in enumerate(L.slots):
            m = own.get(s[0])
            if m is None:
                continue        # inherited from the base: the base's business
            if i < nB and not L.base:
                # a variant without the base: its first slots are the base's, under other names
                if not (m.name in v.refs or m.name in v.defined):
                    continue
                b = base_slots[i]
                if (b[1], b[2], b[3]) != (s[1], s[2], s[3]):
                    raise Unsupported("slot %d: %s vs the base's %s" % (i, m.name, b[0]))
                if m.name == b[0]:
                    continue
                if m.name in v.defined or m.body is not None:
                    raise Unsupported("%s defines the base's slot %d under another name" % (m.name, i))
                base_fwd.setdefault(m.name, (b[0], s, m))
                if base_fwd[m.name][0] != b[0]:
                    raise Unsupported("forwarder %s to two slots" % m.name)
                continue
            if i < nB:
                if m.name in v.refs or m.name in v.defined or m.name == "~":
                    t = (m.params, m.ret, m.cv, m.body)
                    if overrides.setdefault(m.name, (t, m))[0] != t:
                        raise Unsupported("override %s differs" % m.name)
                continue
            slots.setdefault(i, []).append((s[0], s[1], s[2], s[3], m, v))
        sp = {}
        for m in v.cls.members:
            k = _special(m, cname)
            if k and not m.virtual:
                sp.setdefault(k, set()).add((m.params, m.cv, m.body))
            elif m.kind == "method" and not m.virtual:
                if m.name in v.refs or m.name in v.defined:
                    nk = (m.name, m.params, m.cv)
                    old = nonvirt.get(nk)
                    if old is not None and (old.ret, old.body, old.static) != (m.ret, m.body, m.static):
                        raise Unsupported("method %s differs" % m.name)
                    nonvirt[nk] = m
            elif m.kind == "other":
                if m.name is None or m.name in v.refs:
                    k2 = m.name or m.text
                    if others.setdefault(k2, m.text) != m.text:
                        raise Unsupported("nested declaration %s differs" % m.name)
            elif m.kind == "field" and m.static:
                if m.name in v.refs:
                    if statics.setdefault(m.name, m.text) != m.text:
                        raise Unsupported("static member %s differs" % m.name)
        for k in SPECIAL_KINDS:
            special.setdefault(k, []).append(sp.get(k, set()))
    # special members: the same set in every variant (a destructor or constructor changes what users'
    # code does with the object), except that variants which all declare constructors may differ in which
    # A variant without them may take them on if its users never create, copy or destroy an object
    # (Variant.by_value: a local, `new`, `sizeof`, `delete`).
    for k in ("dtor", "assign"):
        sets = {frozenset(x) for x in special[k] if x}
        if len(sets) > 1:
            raise Unsupported("variants disagree on %s" % k)
        if sets and any(not x and v.by_value for x, v in zip(special[k], variants)):
            raise Unsupported("variants disagree on %s" % k)
    ctor_sets = special["ctor"]
    if any(ctor_sets) and any(not x and v.by_value for x, v in zip(ctor_sets, variants)):
        raise Unsupported("some variants declare constructors, some don't")
    dts = {v.layout.dtor for v in variants if v.layout.dtor}
    if len(dts) > 1 or dts and any(v.layout.dtor is None and (v.by_value or v.layout.poly) for v in variants):
        raise Unsupported("variants disagree on the destructor")
    ctor_members = {}
    for v in variants:
        for m in v.cls.members:
            if _special(m, cname) == "ctor":
                k2 = (m.params, m.cv)
                if ctor_members.setdefault(k2, m).body != m.body:
                    raise Unsupported("constructor bodies differ")
    # virtual slots
    vlines = []
    fwd_lines = []
    fwd_map = {}
    nslots = max([nB] + [len(v.layout.slots) for v in variants])
    used_names = set(mem_names) | {n for n, _, _ in nonvirt} | set(overrides)
    for i in range(nB, nslots):
        cands = slots.get(i, [])
        ref = [c for c in cands if c[0] in c[5].refs or c[0] in c[5].defined or c[0] == "~"]
        if not ref:
            vlines.append("    virtual void _m_vf%d();" % i)
            continue
        by_name = {}
        for c in ref:
            sig = (c[1], c[2], c[3])
            old = by_name.get(c[0])
            if old is not None and (old[1], old[2], old[3]) != sig:
                raise Unsupported("virtual %s has different signatures" % c[0])
            if old is not None and old[4].body != c[4].body:
                raise Unsupported("virtual %s has different inline bodies" % c[0])
            by_name.setdefault(c[0], c)
        defined = [n for n in by_name if any(n in c[5].defined for c in ref if c[0] == n)]
        if len(defined) > 1:
            raise Unsupported("slot %d is defined under several names" % i)
        if "~" in by_name and len(by_name) > 1:
            raise Unsupported("destructor slot %d has other names" % i)
        prim = defined[0] if defined else max(by_name, key=lambda n: (sum(c[5].users for c in ref if c[0] == n), n))
        p = by_name[prim]
        if prim in used_names:
            raise Unsupported("name %s used twice" % prim)
        used_names.add(prim)
        vlines.append("    " + (("virtual ~%s();" % cname) if prim == "~" and p[4].body is None else
                                 _member_decl(p[4], virtual=True)))
        for n, c in by_name.items():
            if n == prim:
                continue
            if (c[1], c[2], c[3]) != (p[1], p[2], p[3]):
                raise Unsupported("slot %d: %s and %s have different signatures" % (i, n, prim))
            if any(n in x[5].defined for x in ref if x[0] == n):
                raise Unsupported("forwarder %s is defined out of line" % n)
            if n in used_names:
                raise Unsupported("name %s used twice" % n)
            used_names.add(n)
            fwd_map[n] = prim
            decl, call = _param_list(c[1])
            ret = c[2] or "void"
            body = ("%s(%s);" if ret == "void" else "return %s(%s);") % (prim, call)
            fwd_lines.append("    %s %s(%s)%s { %s }" % (ret, n, decl, (" " + c[3]) if c[3] else "", body))
    for n, (bn, sl, m) in base_fwd.items():
        if n in used_names:
            raise Unsupported("name %s used twice" % n)
        used_names.add(n)
        fwd_map[n] = bn
        decl, call = _param_list(sl[1])
        ret = sl[2] or "void"
        body = ("%s(%s);" if ret == "void" else "return %s(%s);") % (bn, call)
        fwd_lines.append("    %s %s(%s)%s { %s }" % (ret, n, decl, (" " + sl[3]) if sl[3] else "", body))
    lines = []
    head = "%s %s" % (key, cname)
    if base:
        head += " : public %s" % base
    lines.append(head + " {")
    lines.append("  public:")
    for k2, t in others.items():
        lines.append("    " + t.strip().rstrip(";") + ";")
    for n, (t, m) in overrides.items():
        lines.append("    " + (("virtual ~%s();" % cname) if n == "~" and m.body is None else _member_decl(m, virtual=True)))
    lines += vlines
    for (params, cv), m in ctor_members.items():
        lines.append("    " + _member_decl(m))
    for k in ("dtor", "assign"):
        for v in variants[:1]:
            for m in v.cls.members:
                if _special(m, cname) == k and not m.virtual:
                    lines.append("    " + _member_decl(m))
    cur = start
    for g in groups:
        off = g[0].off
        if off > cur:
            lines.append("    char _m_pad_%x[0x%x];" % (cur, off - cur))
        if len(g) == 1:
            lines.append("    " + g[0].decl + ";")
        else:
            if not all(f.union_ok for f in g):
                raise Unsupported("fields %s share an offset but can't share a union" % ", ".join(f.name for f in g))
            lines.append("    union { " + " ".join(f.decl + ";" for f in g) + " };")
        cur = off + g[0].size
    tail = max(v.layout.size for v in variants)
    if poly or groups:
        # pad to the largest variant (rounded the same way MSVC rounds the merged class)
        if tail > cur:
            lines.append("    char _m_pad_%x[0x%x];" % (cur, tail - cur))
    for (n, params, cv), m in nonvirt.items():
        if n in mem_names:
            raise Unsupported("method %s is also a field" % n)
        lines.append("    " + _member_decl(m))
    lines += fwd_lines
    for n, t in statics.items():
        lines.append("    " + t.strip().rstrip(";") + ";")
    lines.append("};")
    return "\n".join(lines), fwd_map


def _member_decl(m, virtual=False):
    """Declaration text of a method member: its own text (body included), `virtual` added if needed."""
    t = m.text.strip()
    if not t.endswith("}") and not t.endswith(";"):
        t += ";"
    if virtual and not re.match(r"virtual\b", t):
        t = "virtual " + t
    return t


def check_variant(M, fwd, v, size_matters=False, pod_matters=False):
    """None if v's users see the same things through the merged class (layout M, forwarders fwd), else
    the first difference."""
    L = v.layout
    if L.poly and not M.poly:
        return "merged class lost the vfptr"
    if M.poly and not L.poly:
        for f in L.fields:
            if f.off < 4 and (f.name in v.refs or f.by_value_class):
                return "field %s sits where the merged class has its vfptr" % f.name
    if L.base and L.base != M.base and L.base.split("::")[-1] in v.refs:
        return "base differs"
    mf = {f.name: f for f in M.fields}
    for f in L.fields:
        if f.name in v.refs or f.by_value_class:
            g = mf.get(f.name)
            if g is None:
                return "field %s missing" % f.name
            if g.sig() != f.sig():
                return "field %s: %s vs %s" % (f.name, g, f)
    ms = {s[0]: (i, s) for i, s in enumerate(M.slots)}
    for i, s in enumerate(L.slots):
        if s[0] in v.refs or s[0] in v.defined or s[0] == "~":
            hit = ms.get(fwd.get(s[0], s[0]))
            if hit is None:
                return "virtual %s missing" % s[0]
            if hit[0] != i:
                return "virtual %s at slot %d, merged %d" % (s[0], i, hit[0])
            if (hit[1][1], hit[1][2], hit[1][3]) != (s[1], s[2], s[3]):
                return "virtual %s signature differs" % s[0]
    if L.dtor != M.dtor and (L.dtor is not None or getattr(v, "by_value", True) or M.dtor == "virtual"
                             and not L.poly):
        return "destructor differs"
    if pod_matters and L.pod != M.pod:
        return "POD-ness differs"
    if size_matters and L.size != M.size:
        return "size %d vs %d" % (M.size, L.size)
    return None
