"""Split a C++ translation unit into top-level items (declarations, definitions, preprocessor lines).

Small and deliberately shallow: enough for the per-function sources in matches/ and equivalent/ (no
#include, no macros at top level apart from #define lines). Used by tools/gen_tree.py.

    items = parse(text)
    for it in items: it.kind, it.key, it.scope, it.text, it.norm, it.deps_names

Item kinds:
  pp        preprocessor line (`#define NAME` gets key ('macro', NAME))
  class     class/struct/union definition (also `template <...> class X {...}`)
  fwd       forward declaration `class X;`
  enum      enum definition
  typedef   typedef
  func      function declaration (no body)
  funcdef   function definition (with body)
  var       variable declaration or definition
  using     using-directive / using-declaration
  other     anything else (kept verbatim)
"""
import re

KEYWORDS = {
    "alignas", "asm", "auto", "bool", "break", "case", "catch", "char", "class", "const", "const_cast",
    "continue", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export",
    "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable",
    "namespace", "new", "operator", "private", "protected", "public", "register", "reinterpret_cast",
    "return", "short", "signed", "sizeof", "static", "static_cast", "struct", "switch", "template", "this",
    "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void",
    "volatile", "wchar_t", "while", "__int64", "__int32", "__int16", "__int8", "__cdecl", "__stdcall",
    "__fastcall", "__thiscall", "__declspec", "__forceinline", "__inline", "_cdecl", "__single_inheritance",
}
TYPE_WORDS = {"bool", "char", "double", "float", "int", "long", "short", "signed", "unsigned", "void",
              "wchar_t", "__int64", "__int32", "__int16", "__int8", "const", "volatile"}
CLASS_KEYS = {"class", "struct", "union"}

_TOKEN = re.compile(r"""
    (?P<ws>\s+)
  | (?P<lc>//[^\n]*)
  | (?P<bc>/\*.*?\*/)
  | (?P<str>L?"(?:\\.|[^"\\\n])*")
  | (?P<chr>L?'(?:\\.|[^'\\\n])*')
  | (?P<num>\.?\d(?:[\w.]|[eEpP][+-])*)
  | (?P<id>[A-Za-z_$][\w$]*)
  | (?P<punct>::|->\*|->|\+\+|--|<<=|>>=|<<|>>|<=|>=|==|!=|&&|\|\||\+=|-=|\*=|/=|%=|&=|\|=|\^=|\.\.\.|\.\*|[^\s])
""", re.S | re.X)


# include/compat/ptr.h: the pointer-sized integer typedefs are the 32-bit types they replace as far as the tree
# generator is concerned (variants, signatures and class layouts compare as before); the source text keeps its spelling
PTR_TYPES = {"hulk_intptr": "int", "hulk_uintptr": "unsigned int", "hulk_longptr": "long",
             "hulk_ulongptr": "unsigned long"}


class Tok:
    __slots__ = ("t", "v", "s", "e")

    def __init__(self, t, v, s, e):
        self.t, self.v, self.s, self.e = t, v, s, e

    def __repr__(self):
        return "Tok(%s,%r)" % (self.t, self.v)


def tokenize(text):
    """Tokens without whitespace/comments. Preprocessor lines become one 'pp' token each."""
    toks = []
    i, n = 0, len(text)
    while i < n:
        m = _TOKEN.match(text, i)
        if not m:
            raise ValueError("cannot tokenize at %d: %r" % (i, text[i:i + 20]))
        kind = m.lastgroup
        if kind in ("ws", "lc", "bc"):
            i = m.end()
            continue
        if text[i] == "#" and not text[text.rfind("\n", 0, i) + 1:i].strip():
            # preprocessor line (with backslash continuations)
            k = i
            while True:
                k = text.find("\n", k)
                if k < 0:
                    k = n
                    break
                if text[:k].rstrip("\r").endswith("\\"):
                    k += 1
                    continue
                break
            toks.append(Tok("pp", text[i:k].strip(), i, k))
            i = k
            continue
        v = m.group(kind)
        toks.append(Tok(kind, PTR_TYPES.get(v, v) if kind == "id" else v, m.start(), m.end()))
        i = m.end()
    return toks


class Item:
    def __init__(self, kind, toks, scope, linkage, text, lead=""):
        self.kind = kind
        self.toks = toks
        self.scope = tuple(scope)        # enclosing namespaces, e.g. ('pure3d',)
        self.linkage = linkage           # 'C' inside extern "C" { }, else None
        self.text = text                 # verbatim source of the item
        self.lead = lead                 # comments/blank lines just before the item
        self.key = None
        self.name = None                 # declared simple name (last component)
        self.is_inline = False
        self.c_linkage = False           # extern "C" (block or prefix)
        self.norm = None                 # normalized text used to compare variants
        self.ids = set()                 # identifier tokens used by the item
        self.sig = None                  # functions: return type + (parameter types) + qualifiers
        self.params = None

    def __repr__(self):
        return "Item(%s %s)" % (self.kind, self.key)


def _match(toks, i, open_, close):
    depth = 0
    for j in range(i, len(toks)):
        v = toks[j].v
        if v == open_:
            depth += 1
        elif v == close:
            depth -= 1
            if depth == 0:
                return j
    raise ValueError("unbalanced %s" % open_)


def _skip_template_header(toks, i):
    """Skip `template < ... >` (angle brackets balanced) starting at i; returns index after it."""
    while i < len(toks) and toks[i].v == "template":
        if i + 1 < len(toks) and toks[i + 1].v == "<":
            depth = 0
            j = i + 1
            while j < len(toks):
                if toks[j].v == "<":
                    depth += 1
                elif toks[j].v == ">":
                    depth -= 1
                    if depth == 0:
                        break
                elif toks[j].v == ">>":
                    depth -= 2
                    if depth <= 0:
                        break
                j += 1
            i = j + 1
        else:
            i += 1
    return i


def _skip_declspec(toks, i):
    while i < len(toks) and toks[i].v in ("__declspec", "HULK_SINGLE_INHERITANCE"):
        if toks[i].v == "__declspec" and i + 1 < len(toks) and toks[i + 1].v == "(":
            i = _match(toks, i + 1, "(", ")") + 1
        else:
            i += 1
    return i


def _is_type_head(toks):
    """True if the tokens before '{' start a class/struct/union/enum head (a type definition)."""
    i = _skip_template_header(toks, 0)
    while i < len(toks) and toks[i].v in ("typedef", "const", "volatile", "static", "extern") or (
            i < len(toks) and toks[i].t == "str"):
        i += 1
    i = _skip_declspec(toks, i)
    return i < len(toks) and toks[i].v in CLASS_KEYS | {"enum"}


def parse(text):
    toks = tokenize(text)
    items = []
    scope = []          # list of ('ns', name) / ('extern', 'C')
    cur = []            # tokens of the item being collected
    last_end = 0
    i = 0
    n = len(toks)

    def ns_scope():
        return [v for k, v in scope if k == "ns"]

    def linkage():
        return "C" if any(k == "extern" and v == "C" for k, v in scope) else None

    def emit(kind, ts):
        nonlocal last_end
        start, end = ts[0].s, ts[-1].e
        lead = text[last_end:start]
        it = Item(kind, ts, ns_scope(), linkage(), text[start:end], lead)
        classify(it)
        items.append(it)
        last_end = end

    while i < n:
        t = toks[i]
        if t.t == "pp" and not cur:
            emit("pp", [t])
            i += 1
            continue
        if t.v == ";" and not cur:
            i += 1
            last_end = t.e
            continue
        if t.v == "}" and not cur:
            if not scope:
                raise ValueError("unbalanced } at %d" % t.s)
            scope.pop()
            last_end = t.e
            i += 1
            continue
        if t.v == ";":
            cur.append(t)
            emit("decl", cur)
            cur = []
            i += 1
            continue
        if t.v == "{":
            vs = [x.v for x in cur]
            if vs and vs[0] == "namespace" and len(vs) <= 2:
                scope.append(("ns", vs[1] if len(vs) == 2 else "<anon>"))
                cur = []
                last_end = t.e
                i += 1
                continue
            if vs == ["extern", '"C"'] or vs == ["extern", '"C++"']:
                scope.append(("extern", "C" if vs[1] == '"C"' else "C++"))
                cur = []
                last_end = t.e
                i += 1
                continue
            j = _match(toks, i, "{", "}")
            if _is_type_head(cur) or any(x.v == "=" for x in cur):
                # type definition or braced initializer: runs to the ';'
                cur.extend(toks[i:j + 1])
                i = j + 1
                while i < n and toks[i].v != ";":
                    if toks[i].v in ("{", "(", "["):
                        close = {"{": "}", "(": ")", "[": "]"}[toks[i].v]
                        k = _match(toks, i, toks[i].v, close)
                        cur.extend(toks[i:k + 1])
                        i = k + 1
                        continue
                    cur.append(toks[i])
                    i += 1
                if i < n:
                    cur.append(toks[i])
                    i += 1
                emit("decl", cur)
                cur = []
                continue
            # function body (or constructor with mem-initializers)
            cur.extend(toks[i:j + 1])
            emit("funcdef", cur)
            cur = []
            i = j + 1
            continue
        if t.v in ("(", "["):
            close = ")" if t.v == "(" else "]"
            k = _match(toks, i, t.v, close)
            cur.extend(toks[i:k + 1])
            i = k + 1
            continue
        cur.append(t)
        i += 1
    if cur:
        emit("other", cur)
    if scope:
        raise ValueError("unclosed scope %r" % scope)
    return items


# ---------------------------------------------------------------------------------------------
def _qualified_before(ts, k):
    """Qualified name ending just before index k (exclusive): ['Foo', '::', 'bar'] -> 'Foo::bar'."""
    j = k - 1
    parts = []
    while j >= 0:
        v = ts[j].v
        if ts[j].t == "id" and v not in KEYWORDS - {"operator"} or v == "~":
            if parts and parts[-1] not in ("::", "~") and v != "~" and not parts[-1].startswith("<"):
                break           # two names in a row: the first one is the return type
            parts.append(v)
            j -= 1
            continue
        if v == "::":
            parts.append(v)
            j -= 1
            continue
        if v == ">":
            # template-id like Foo<int>::bar; take the bracket contents verbatim
            depth = 0
            jj = j
            while jj >= 0:
                if ts[jj].v == ">":
                    depth += 1
                elif ts[jj].v == "<":
                    depth -= 1
                    if depth == 0:
                        break
                jj -= 1
            if jj > 0 and ts[jj - 1].t == "id" and parts and parts[-1] == "::":
                parts.append("".join(x.v for x in ts[jj:j + 1]))
                j = jj - 1
                continue
        break
    return "".join(reversed(parts)).replace("~", "~"), j


def _strip_param_names(ts):
    """Normalized text of a parameter list (tokens between the parens), parameter names dropped."""
    out, cur, depth = [], [], 0
    for t in ts:
        if t.v in ("(", "[", "<"):
            depth += 1
        elif t.v in (")", "]", ">"):
            depth -= 1
        if t.v == "," and depth == 0:
            out.append(cur)
            cur = []
            continue
        cur.append(t)
    if cur:
        out.append(cur)
    res = []
    for p in out:
        vs = [t.v for t in p]
        if "=" in vs:
            vs = vs[:vs.index("=")]
        if len(vs) > 1 and p[len(vs) - 1].t == "id" and vs[-1] not in KEYWORDS and vs[-2] not in (
                "::", "struct", "class", "enum", "union"):
            vs = vs[:-1]
        res.append(" ".join(vs))
    return ",".join(res)


def classify(it):
    ts = it.toks
    vs = [t.v for t in ts]
    it.ids = {t.v for t in ts if t.t == "id"}
    if it.kind == "pp":
        m = re.match(r"#\s*define\s+(\w+)", it.text)
        if m:
            it.kind = "define"
            it.key = ("macro", m.group(1))
            it.name = m.group(1)
        else:
            m = re.match(r"#\s*undef\s+(\w+)", it.text)
            it.kind = "undef" if m else "pp"
            it.key = ("pp", it.text)
        it.norm = it.text
        return
    it.c_linkage = it.linkage == "C" or (len(vs) > 1 and vs[0] == "extern" and vs[1] == '"C"')
    body_start = vs.index("{") if "{" in vs else len(vs)
    head = ts[:body_start]
    hv = vs[:body_start]
    it.is_inline = any(v in ("inline", "__inline", "__forceinline") for v in hv)
    is_template = bool(hv) and hv[0] == "template"
    if hv and hv[0] in ("using",):
        it.kind = "using"
        it.key = ("using", " ".join(vs))
        it.norm = " ".join(vs)
        return
    if it.kind == "decl" and _is_type_head(head if body_start < len(vs) else ts):
        i = _skip_template_header(ts, 0)
        typedef = False
        while i < len(ts) and (ts[i].v in ("typedef", "const", "volatile", "static", "extern") or ts[i].t == "str"):
            typedef = typedef or ts[i].v == "typedef"
            i += 1
        i = _skip_declspec(ts, i)
        ckey = ts[i].v
        i = _skip_declspec(ts, i + 1)
        name = None
        j = i
        while j < len(ts) and ts[j].v not in ("{", ":", ";"):
            j += 1
        if j > i:
            name = "".join(t.v for t in ts[i:j])
        if typedef:
            # typedef struct X {...} Y;  -> key on Y
            tail = [t for t in ts[_match(ts, body_start, "{", "}") + 1:] if t.t == "id"] if body_start < len(ts) else []
            if tail:
                name = tail[-1].v
            it.kind = "typedef"
        elif body_start < len(vs):
            it.kind = "enum" if ckey == "enum" else "class"
            # `struct X {...} x;` also declares a variable; keep it as part of the class item
        else:
            it.kind = "fwd"
        it.name = (name or "<anon>").split("::")[-1]
        it.key = (it.kind if it.kind != "fwd" else "fwd", "::".join(it.scope + ((name or "<anon@%d>" % ts[0].s),)))
        if it.kind == "fwd":
            it.norm = "%s %s;" % (ckey, name)
        else:
            it.norm = " ".join(vs)
        if is_template:
            it.key = ("template " + it.key[0], it.key[1])
        return
    if hv and hv[0] == "typedef":
        it.kind = "typedef"
        name = None
        for k, t in enumerate(ts):
            if t.v == "(" and k + 1 < len(ts) and any(x.v == "*" for x in ts[k + 1:k + 4]):
                close = _match(ts, k, "(", ")")
                ids = [x.v for x in ts[k:close] if x.t == "id" and x.v not in KEYWORDS]
                if ids:
                    name = ids[-1]
                break
        if name is None:
            ids = [t.v for t in ts if t.t == "id" and t.v not in KEYWORDS]
            # drop array bounds: name is the last identifier before '[' or ';'
            k = vs.index("[") if "[" in vs else len(vs)
            ids = [t.v for t in ts[:k] if t.t == "id" and t.v not in KEYWORDS]
            name = ids[-1] if ids else "<anon>"
        it.name = name
        it.key = ("typedef", "::".join(it.scope + (name,)))
        it.norm = " ".join(vs)
        return
    # function or variable: find the first top-level '(' that starts a parameter list
    paren = None
    depth = 0
    k = 0
    while k < len(head):
        v = head[k].v
        if v == "<" and k > 0 and head[k - 1].t == "id" and depth == 0 and k + 1 < len(head):
            # skip template args in a declarator (Foo<int>::bar)
            pass
        if v == "operator":
            # operator name: operator() / operator new / operator== ...
            m = k + 1
            if m < len(head) and head[m].v == "(":
                m += 2  # 'operator' '(' ')'
            while m < len(head) and head[m].v != "(":
                m += 1
            paren = m if m < len(head) else None
            break
        if v == "(":
            if k > 0 and head[k - 1].v == "__declspec":
                k = _match(head, k, "(", ")") + 1
                continue
            paren = k
            break
        k += 1
    is_var = paren is None
    if paren is not None:
        # `int (*fp)(int);`: the first paren group is a declarator, not a parameter list
        prev = head[paren - 1].v if paren > 0 else ""
        inner = head[paren + 1:paren + 3]
        if (prev in TYPE_WORDS or prev in ("*", "&") or head[paren - 1].t == "id" and prev in KEYWORDS
                and prev != "operator") and inner and inner[0].v in ("*", "&", "__cdecl", "__stdcall", "__fastcall"):
            is_var = True
        elif any(x.v == "=" for x in head[:paren]):
            is_var = True
    if is_var:
        it.kind = "var"
        k = vs.index("=") if "=" in vs else len(vs)
        stop = min([k] + [q for q, v in enumerate(vs) if v in ("[", ";")] + ([vs.index(",")] if "," in vs else []))
        if paren is not None:
            close = _match(ts, paren, "(", ")")
            ids = [t.v for t in ts[paren:close] if t.t == "id" and t.v not in KEYWORDS]
            name = ids[-1] if ids else "<anon>"
        else:
            ids = [t.v for t in ts[:stop] if t.t == "id" and t.v not in KEYWORDS]
            name = ids[-1] if ids else "<anon>"
            q, _ = _qualified_before(ts, stop)
            if q and q.endswith(name):
                name = q
        it.name = name.split("::")[-1]
        it.key = ("var", "::".join(it.scope + (name,)))
        it.norm = " ".join(vs)
        return
    qname, _ = _qualified_before(head, paren)
    if head[paren - 1].v == ")" and "operator" in hv:
        qname = None
    if "operator" in hv:
        oi = hv.index("operator")
        q, _ = _qualified_before(head, oi)
        qname = (q + "::" if q and not q.endswith("::") else (q or "")) + "operator" + "".join(hv[oi + 1:paren])
        qname = qname.replace("::::", "::")
    if not qname:
        qname = "<anon@%d>" % ts[0].s
    it.name = qname.split("::")[-1]
    close = _match(head, paren, "(", ")")
    params = _strip_param_names(head[paren + 1:close])
    prefix = [v for v in hv[:paren] if v not in ("extern", '"C"')]
    # drop the declarator name itself from the prefix to get the return type
    # return type and modifiers without the declarator name; __cdecl is the default for free functions
    rtype = [v for v in prefix if v not in ("__cdecl", "inline", "__inline", "__forceinline", "static")]
    nq = len([x for x in re.split(r"(::)", qname) if x])
    if "<" in qname and "operator" not in hv:
        # template-id in the declarator (an explicit specialization `template <> R X<T>::f(...)`): the
        # return type is what precedes the qualified name
        _, qj = _qualified_before(head, paren)
        rtype = [v for v in hv[:qj + 1] if v not in ("extern", '"C"', "__cdecl", "inline", "__inline",
                                                    "__forceinline", "static")]
    elif "operator" not in hv:
        rtype = rtype[:len(rtype) - nq] if nq <= len(rtype) else rtype
    sig = " ".join(rtype) + "(" + params + ")" + " ".join(hv[close + 1:])
    it.sig = sig
    it.params = params
    if it.kind == "funcdef":
        it.key = ("funcdef", "::".join(it.scope + (qname,)), params)
        it.norm = " ".join(vs)
    else:
        it.kind = "func"
        it.key = ("cfunc" if it.c_linkage else "func", "::".join(it.scope + (qname,)) if not it.c_linkage else qname)
        it.norm = ("C:" if it.c_linkage else "") + "::".join(it.scope) + "|" + sig
    if is_template and it.kind == "func":
        it.key = ("template func",) + it.key[1:]
