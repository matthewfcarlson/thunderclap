#!/usr/bin/env python3
"""Generate the source tree build/tree/ from config/splits.json and the verified sources.

  build/venv/bin/python tools/gen_tree.py            # regenerate build/tree/{src,include}/ + manifest.json
  build/venv/bin/python tools/gen_tree.py --stats    # numbers only

build/ is gitignored: matches/ and equivalent/ stay the source of truth and the tree is regenerated from
them. tools/build_tree.py compiles and re-verifies it (and drives the fallback rounds through
build/tree/state.json).

Per object in config/splits.json (kind game / game-init) the generator writes one translation unit,
`build/tree/src/<layer>/<dir>/<File>.cpp` (layer = the object's `layer`: game, engine, platform/xbox; see
docs/shipping.md §1), with every function of the object in address order:

  * a verified function (matches/ wins over equivalent/) as its definition;
  * an unverified one as `// 0xADDR NAME (size B): not yet verified`.

Functions whose source needs other compiler flags (`// cl-flags:`) go into a sibling TU with the same
stem, `<File>.<flags>.cpp`, which starts with the same `// cl-flags:` line.

Declarations. Each source declares its own callees, globals and stub classes. They are split into items
(tools/cxx_items.py) and merged:

  * A function is **merged** when every declaration it uses is its TU's canonical variant (the variant of
    that symbol most functions in the TU use). Its declarations are emitted once, at the top of the TU or
    in a shared header, and only its definition stays in place.
  * Otherwise it is **wrapped**: its whole original source goes inside `namespace fn_<addr> { ... }`, which
    keeps its local declarations from clashing with the rest (MSVC accepts differing `extern "C"`
    declarations in different namespaces). Other reasons to wrap: macros, using-directives, helper
    definitions besides the function itself (they could be inlined into neighbours), a definition that
    another function in the TU also defines, or a compile error blamed on it by build_tree.py.
  * **Isolated** functions (compile errors even when wrapped) get their own TU, `<File>.iso_<addr>.cpp`.

Stub reconciliation inside a TU (docs/source-tree.md "Stub reconciliation"):

  * Spellings: declarations that differ only in spelling that doesn't change code (`unsigned` / `unsigned int`,
    `char const*`, default `__cdecl`, top-level const on parameters, `f(void)`; C vs C++ linkage for address
    names and a few CRT names; parameter names of inline definitions) count as one variant
    (canonical_variant); the TU emits the most-used spelling.
  * Classes: variants of one class name that can't coexist are merged into one definition with the union of
    the members the TU's functions use, when tools/stub_layout.py proves every user sees the same layout,
    vftable and special members (merge_name); the result is checked again against the TU's final
    declarations (validate_tu). Global-scope stubs of namespaced RTTI classes count as `rtti_stub` in
    conflicts.json.
  * Placement `operator new` with and without `throw()`: the object's less used form goes to a sibling TU
    `<File>.new_<form>.cpp` (each form changes the code of `new (p) T`, and both must be global).

build_tree.py checks the result: a match must still match, an equivalent/ function must compile to the same
bytes as its standalone source; otherwise it falls back (merged -> wrapped -> isolated).

Headers: a declaration that two or more TUs of one directory use identically, and that no TU of that
directory declares differently, goes to `build/tree/include/<layer>/<dir>.h`; one used identically by two or more
directories and declared the same way everywhere goes to `build/tree/include/common.h`. A declaration is
only hoisted together with the declarations it depends on.

Conflicts (one symbol declared differently by different sources) are listed in build/tree/conflicts.json.

Native spelling (docs/native-build.md fixes 1-2; the MSVC 7.1 code does not change, build_tree.py checks it):

  * every TU that names size_t includes `build/tree/include/tree_prelude.h` first: the tree's one `size_t`;
    sources' own `typedef unsigned int size_t;` become comments, `operator new/delete` parameters spell
    `size_t`, and the non-placement `operator new(size_t) throw()` spells `HULK_NEW_THROW` (throw() under MSVC, nothing off MS);
  * a wrapped source's `extern "C"` declaration that would clash in the TU (another type of the same C name,
    or an invented name such as `Lookup`) gets C++ linkage, `extern "C++"`, so it becomes fn_<addr>::name
    (CLinkage); merged declarations that overload one C name keep C linkage only on the first (emit_item).
    tools/native_link.py binds the resulting names by address for the native link;
  * a TU's own declarations and merged definitions live in its TU namespace `fn_f<7 hex>` (see TU_NS_GLOBAL),
    so stubs and helpers of different TUs don't collide in the native link; TU-local variable definitions
    become declarations (as_declaration), wrapped sources' declarations of the pinned globals become typed
    views of one C name (PINNED), the repeated placement operator new is HULK_NATIVE_INLINE (docs/native-build.md
    "After the next fixes 1-3").
"""
import argparse
import bisect
import collections
import csv
import hashlib
import json
import os
import re
import shutil
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402
import stub_layout  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SPLITS = os.path.join(ROOT, "config/splits.json")
FUNCS_CSV = os.path.join(ROOT, "build/functions.csv")
TREE = os.path.join(ROOT, "build/tree")
STATE = os.path.join(TREE, "state.json")
SOURCE_DIRS = ("matches", "equivalent")     # earlier wins
DEFAULT_FLAGS = ["/nologo", "/c", "/O2", "/GR", "/GX", "/Gy"]
ALLOWED_FLAGS = {"/Oy-", "/Oy", "/O1", "/O2", "/Ox", "/Os", "/Ot", "/Og", "/Oi", "/Ob0", "/Ob1", "/Ob2",
                 "/GX", "/GX-", "/GR", "/GR-", "/Gy"}

# Item kinds whose symbol may have only one variant in a scope.
SINGLE = {"class", "template class", "enum", "typedef", "var", "cfunc", "macro", "funcdef", "template func",
          "template funcdef"}
DECL_KINDS = {"class", "template class", "enum", "typedef", "var", "cfunc", "func", "fwd", "template fwd",
              "template func", "funcdef"}
HEADER = "// GENERATED by tools/gen_tree.py -- DO NOT EDIT. Regenerate: tools/gen_tree.py (tools/build_tree.py)."


# ---------------------------------------------------------------------------------------------
# Inputs
def load_functions():
    out = {}
    with open(FUNCS_CSV) as f:
        for r in csv.DictReader(f):
            out[int(r["address"], 16)] = (int(r["size"]), r["name"])
    return out


def load_splits():
    objs = json.load(open(SPLITS))["objects"]
    for o in objs:
        o["start_i"] = int(o["start"], 16)
        o["end_i"] = int(o["end"], 16)
    return sorted(objs, key=lambda o: o["start_i"])


def layer_of(obj):
    """The object's layer from config/splits.json (tools/infer_splits.py); `game` for splits written before layers."""
    return obj.get("layer") or "game"


def file_flags(text):
    """Same rule as compare.file_flags: a '// cl-flags:' comment in the first 5 lines."""
    for line in text.splitlines()[:5]:
        m = re.match(r"\s*//\s*cl-flags:\s*(.+)", line)
        if m:
            return [t for t in m.group(1).split() if t in ALLOWED_FLAGS]
    return []


def flags_tag(flags):
    """Extra flags beyond the defaults, in order; '' when the source compiles with the defaults."""
    extra = [f for f in flags if f not in DEFAULT_FLAGS]
    return "_".join(f.lstrip("/") for f in extra)


def load_sources():
    """addr -> (kind, relpath, text). matches/ wins over equivalent/."""
    out = {}
    for d in SOURCE_DIRS:
        p = os.path.join(ROOT, d)
        for fn in sorted(os.listdir(p)):
            m = re.fullmatch(r"0x([0-9a-fA-F]{8})\.cpp", fn)
            if not m:
                continue
            addr = int(m.group(1), 16)
            if addr in out:
                continue
            text = open(os.path.join(p, fn), encoding="latin1").read()
            out[addr] = (d, "%s/%s" % (d, fn), text)
    return out


def load_state():
    try:
        s = json.load(open(STATE))
    except (OSError, ValueError):
        s = {}
    return {"wrap": {int(k, 16): v for k, v in s.get("wrap", {}).items()},
            "isolate": {int(k, 16): v for k, v in s.get("isolate", {}).items()},
            "local_only": {tuple(k) for k in s.get("local_only", [])},
            "iso_plain": {int(k, 16): v for k, v in s.get("iso_plain", {}).items()}}


def save_state(state):
    os.makedirs(TREE, exist_ok=True)
    s = {"wrap": {"0x%08x" % k: v for k, v in sorted(state["wrap"].items())},
         "isolate": {"0x%08x" % k: v for k, v in sorted(state["isolate"].items())},
         "local_only": sorted(list(k) for k in state["local_only"]),
         "iso_plain": {"0x%08x" % k: v for k, v in sorted(state.get("iso_plain", {}).items())}}
    with open(STATE, "w") as f:
        json.dump(s, f, indent=1)


# ---------------------------------------------------------------------------------------------
# Model
class Block:
    """One verified function's source."""

    def __init__(self, addr, size, name, kind, path, text):
        self.addr, self.size, self.name, self.kind, self.path, self.text = addr, size, name, kind, path, text
        self.flags = file_flags(text)
        self.tag = flags_tag(self.flags)
        self.mode = "merged"
        self.reasons = []
        self.items = []
        self.defs = []
        self.decls = []          # (key, norm, item)
        self.macros = sorted(set(re.findall(r"^\s*#\s*define\s+(\w+)", text, re.M)))
        self.gen_includes = []   # include/gen/ headers the source includes (hoisted to the TU)
        try:
            self.items = cxx_items.parse(text)
        except ValueError as e:
            self.wrap("parse: %s" % e)
            return
        keep = []
        for it in self.items:
            m = GEN_INCLUDE.match(it.text) if it.kind == "pp" else None
            if m:
                self.gen_includes.append(m.group(1))
            else:
                keep.append(it)
        self.items = keep
        for it in self.items:
            if it.kind == "funcdef" and not it.is_inline and not it.key[0].startswith("template"):
                self.defs.append(it)
        if self.macros or any(it.kind in ("pp", "define", "undef") for it in self.items):
            self.wrap("macros")
        if any(it.kind == "using" for it in self.items):
            self.wrap("using-directive")
        if len(self.defs) > 1:
            self.wrap("helper definitions (%d out-of-line function bodies)" % len(self.defs))
        if not self.defs:
            self.wrap("no out-of-line definition (target defined in a class body)")
        if any(it.kind == "other" for it in self.items):
            self.wrap("unparsed top-level text")
        for it in self.items:
            if it.kind in DECL_KINDS and it not in self.defs:
                self.decls.append((key_of(it), it.norm, it))

    def wrap(self, why):
        if self.mode == "merged":
            self.mode = "wrapped"
        self.reasons.append(why)

    @property
    def ns(self):
        return "fn_%08x" % self.addr


def key_of(it):
    k = it.key
    if it.kind == "funcdef":
        return ("funcdef",) + tuple(k[1:])
    return tuple(k)


def key_str(k):
    return "%s %s" % (k[0], "::".join(str(x) for x in k[1:2])) + ("(%s)" % k[2] if len(k) > 2 else "")


TYPE_KINDS = {"class", "template class", "enum", "typedef", "fwd", "template fwd"}
# shared headers a source may include: include/gen/ (classes, tools/gen_headers.py) and include/decls/ (pinned
# prototypes of address names) and include/decls/data/ (the data items, tools/data_gen.py); the generator hoists
# them to the TU and their declarations win in it
GEN_INCLUDE = re.compile(r'#\s*include\s*[<"]((?:gen|decls)/\w+\.h|decls/data/[\w/]+\.h)[>"]\s*$')
DATA_INCLUDE = re.compile(r'^[ \t]*#\s*include\s*[<"]decls/data/[\w/]+\.h[>"][ \t]*\r?\n?', re.M)


def tu_data_headers(blocks):
    """include/decls/data/ headers of a TU's merged and wrapped sources. They are hoisted to the TU whatever the
    source's mode: they hold only `extern "C"` declarations (and `struct DataLayout_<addr>;`), so a wrapped
    source sees them from its fn_<addr> namespace, and a declaration in one namespace can't hide them from
    another wrapped source (an include guard would)."""
    return {h for b in blocks if b.mode in ("merged", "wrapped") for h in b.gen_includes if h.startswith("decls/data/")}


INCLUDE_ROOT = os.path.join(ROOT, "include")
_GEN_CACHE = {}


def gen_header_items(h):
    """Declaration items of include/gen/<h> and the gen headers it includes (cached)."""
    if h in _GEN_CACHE:
        return _GEN_CACHE[h]
    _GEN_CACHE[h] = []          # include cycles (there are none) end here
    p = os.path.join(INCLUDE_ROOT, h)
    out = []
    try:
        items = cxx_items.parse(open(p, encoding="latin1").read())
    except (OSError, ValueError):
        items = []
    for it in items:
        m = re.match(r'#\s*include\s*"(\w+\.h)"', it.text) if it.kind == "pp" else None
        if m:
            out += gen_header_items(os.path.dirname(h) + "/" + m.group(1))
        elif it.kind in DECL_KINDS:
            out.append(it)
    _GEN_CACHE[h] = out
    return out


def decls_body(h):
    """The declarations of include/<h> (an include/decls/ header) without its include guard."""
    lines = open(os.path.join(INCLUDE_ROOT, h), encoding="latin1").read().splitlines()
    return "\n".join(l for l in lines if not re.match(r"\s*#\s*(ifndef|define|endif)\b", l))


def gen_variants(headers):
    """name -> {variants} declared by include/gen/ headers (and what they include)."""
    out = collections.defaultdict(set)
    seen = set()
    for h in headers:
        for it in gen_header_items(h):
            if id(it) in seen:
                continue
            seen.add(id(it))
            nk, var = item_variant(it)
            out[nk].add(var)
    return dict(out)


def item_variant(it, k=None, norm=None):
    """(name key, variant) of a declaration item. Names live in two spaces: types and values.

    C-linkage functions are keyed by their bare name: extern "C" ignores namespaces."""
    k = k or key_of(it)
    norm = norm if norm is not None else it.norm
    kind = k[0]
    # one name space: a function or variable named like a class hides the class
    if kind in TYPE_KINDS:
        return k[1], (kind, norm, None, None)
    if kind == "cfunc":
        return k[1], ("cfunc", norm, it.params, it.sig)
    if kind == "funcdef":
        nm = k[1].split("::")[-1] if it.c_linkage else k[1]
        return nm, ("cdef" if it.c_linkage else "def", norm, it.params, it.sig)
    if kind == "func":
        return k[1], ("func", norm, it.params, it.sig)
    return k[1], (kind, norm, None, None)


def block_variants(b):
    """[(name key, variant)] for a block's declarations and its own definitions."""
    out = [item_variant(it, k, norm) for k, norm, it in b.decls]
    for d in b.defs:
        nk, (kind, _, params, sig) = item_variant(d)
        out.append((nk, (kind, "definition", params, sig)))
    return out


def block_variants_of(decls):
    return [item_variant(it, k, norm) for k, norm, it in decls]


ADDR_NAME = re.compile(r"(?:^|_)(?:FUN|DAT|LAB|PTR|thunk_FUN)_[0-9a-fA-F]{6,8}$")
# CRT functions sources declare by hand, some with C++ linkage: one declaration per name, the C one when the
# TU's functions use it (the most-used spelling is the representative)
CRT_NAMES = {"__security_check_cookie", "atexit", "_atexit", "_purecall", "memset", "memcpy", "memcmp", "strlen",
             "strcmp", "strcpy", "_ftol", "_ftol2", "_CIfmod", "_CIsqrt", "sqrtf", "fabs", "_chkstk", "_alloca_probe"}


def block_cvariants(b):
    """[(name, variant, canonical variant, item or None)] of a block's declarations and own definitions."""
    c = b.__dict__.get("_cvars")
    if c is None:
        c = []
        for k, norm, it in b.orig_decls:
            nk, var = item_variant(it, k, norm)
            c.append((nk, var, canonical_variant(nk, var, it), it))
        for nk, var in block_variants(b)[len(b.orig_decls):]:
            c.append((nk, var, var, None))
        b._cvars = c
    return c


def _norm_sig_parts(it):
    """(return type, [parameter types], qualifiers) of a function item, spelled canonically."""
    sig, params = it.sig or "", it.params or ""
    i = sig.rfind("(" + params + ")")
    if i < 0:
        return None
    ret = sig[:i].split()
    quals = sig[i + len(params) + 2:].split()
    ret = [w for w in ret if w not in ("__cdecl", "_cdecl")]
    ps = []
    if params not in ("", "void"):
        for p in stub_layout.split_commas(params):
            ws = [w for w in p.split() if w not in ("__cdecl", "_cdecl")]
            t = stub_layout.norm_type(ws).replace("( void )", "( )")    # f(void) = f() in C++
            if "*" not in t and "&" not in t and "(" not in t:
                t = " ".join(w for w in t.split() if w not in ("const", "volatile"))     # by-value cv
            elif t.endswith(" const") or t.endswith(" volatile"):
                t = t.rsplit(" ", 1)[0]                     # T * const: top-level cv
            ps.append(t)
    return stub_layout.norm_type(ret), ps, " ".join(quals)


def canonical_variant(nk, var, it):
    """The variant with spelling differences that don't change code removed: `unsigned` = `unsigned int`,
    `char const*` = `const char*`, default `__cdecl`, top-level const on parameters; for functions and
    variables named by an address also C vs C++ linkage (equiv.py binds them by the address either way);
    inline definitions up to their parameter names."""
    kind = var[0]
    try:
        if kind in ("func", "cfunc") and it is not None and not it.scope:
            parts = _norm_sig_parts(it)
            if parts is None:
                return var
            ret, ps, quals = parts
            sig = "%s(%s)%s" % (ret, ",".join(ps), quals)
            if ADDR_NAME.search(nk) or nk in CRT_NAMES:
                return ("func", "|" + sig, ",".join(ps), sig)
            return (kind, ("C:" if kind == "cfunc" else "") + "|" + sig, ",".join(ps), sig)
        if kind == "var" and it is not None and not it.scope and ADDR_NAME.search(nk):
            vs = [t.v for t in it.toks if t.v not in ("extern", '"C"')]
            out = []
            for i, v in enumerate(vs):
                out.append(v)
                if v == "unsigned" and (i + 1 >= len(vs) or vs[i + 1] not in ("char", "short", "int", "long", "__int64")):
                    out.append("int")
            return ("var", " ".join(out), None, None)
        if kind == "def" and it is not None and it.is_inline and it.kind == "funcdef":
            return ("def", inline_canon(it), var[2], var[3])
    except (ValueError, IndexError):
        return var
    return var


def inline_canon(it):
    """Tokens of an inline function definition with parameter names replaced by position, no __cdecl."""
    vs = [t.v for t in it.toks]
    if "(" not in vs:
        return it.norm
    if "operator" in vs:
        oi = vs.index("operator")
        p = vs.index("(", oi + 2) if vs[oi + 1] == "(" else vs.index("(", oi)
    else:
        p = vs.index("(")
    close = cxx_items._match(it.toks, p, "(", ")")
    names = {}
    depth = 0
    cur = []
    for t in it.toks[p + 1:close] + [None]:
        if t is None or (t.v == "," and depth == 0):
            ids = [x for x in cur if x.t == "id" and x.v not in cxx_items.KEYWORDS]
            if len(cur) > 1 and ids and cur[-1] is ids[-1] and cur[-2].v not in ("::", "struct", "class", "enum", "union"):
                names[ids[-1].v] = "_p%d" % len(names)
            cur = []
            continue
        if t.v in ("(", "[", "<"):
            depth += 1
        elif t.v in (")", "]", ">"):
            depth -= 1
        cur.append(t)
    return " ".join(names.get(v, v) for v in vs if v not in ("__cdecl", "_cdecl"))


def block_ctx(b):
    c = getattr(b, "_ctx", None)
    if c is None:
        c = b._ctx = stub_layout.Context(b.items)
        c.items = b.items
    return c


def block_refs(b, q):
    """(identifiers b's code mentions outside class q's definition, members of q that b defines out of line)."""
    cache = b.__dict__.setdefault("_refs", {})
    r = cache.get(q)
    if r is None:
        refs, defined = set(), set()
        for it in b.items:
            if it.kind == "class" and it.key and it.key[1] == q:
                continue
            if it.kind in ("class", "enum") or it.kind == "typedef" and "{" in it.norm:
                # another class's own member declarations don't use q's members; its inline bodies may
                refs |= inline_body_ids(it)
                refs |= base_ids(it)
                continue
            refs |= it.ids
            if it.kind == "funcdef" and it.key[1].startswith(q + "::"):
                defined.add(it.key[1][len(q) + 2:].split("::")[-1])
        r = cache[q] = (refs, defined)
    return r


def inline_body_ids(it):
    """Identifiers inside the braces nested in a class definition (inline member bodies, nested types)."""
    out = set()
    depth = 0
    for t in it.toks:
        if t.v == "{":
            depth += 1
        elif t.v == "}":
            depth -= 1
        elif depth >= 2 and t.t == "id":
            out.add(t.v)
    return out


def base_ids(it):
    vs = [t.v for t in it.toks]
    if "{" not in vs:
        return set()
    head = vs[:vs.index("{")]
    if ":" not in head:
        return set()
    return {v for v in head[head.index(":") + 1:] if re.match(r"[A-Za-z_]\w*$", v)}


def uses_by_value(b, name):
    """Does b's code use class `name` where its size matters (a local, `new`, `sizeof`, an array)?"""
    toks = [t for it in b.items if it.kind == "funcdef" for t in it.toks]
    if any(t.v == "delete" for t in toks):
        return True
    for i, t in enumerate(toks):
        if t.v != name:
            continue
        p = toks[i - 1].v if i else ""
        n = toks[i + 1].v if i + 1 < len(toks) else ""
        if p in ("new", "sizeof") or (p == "(" and i >= 2 and toks[i - 2].v == "sizeof"):
            return True
        if n not in ("*", "&", "::", ")", ",", ">") and p not in ("::", "~", "class", "struct"):
            return True
    return False


def compatible(a, b):
    """Can two variants of one name coexist in one scope?"""
    if a == b:
        return True
    ka, kb = a[0], b[0]
    pair = {ka, kb}
    if pair <= {"fwd"} or pair == {"fwd", "class"} or pair <= {"template fwd", "template class"} and ka != kb:
        return True
    if pair <= {"template fwd"}:
        return True
    if pair <= {"func", "def"}:
        # C++ overloads (different parameters) or redeclarations (same signature); two definitions only
        # as overloads
        if a[2] != b[2]:
            return True
        return ka != kb and a[3] == b[3]
    if pair == {"cfunc", "cdef"}:
        return a[3] == b[3]
    return False


def accept_variants(vs, forced=()):
    """Greedy: most-used variants first, each kept if compatible with all kept so far. `forced` variants
    (the declarations of an include/gen/ header the TU includes) are kept first."""
    order = sorted(vs, key=lambda v: (-len(vs[v]), min(vs[v]), v))
    kept = list(forced)
    for v in order:
        if all(compatible(v, k) for k in kept):
            kept.append(v)
    return set(kept)


def name_str(nk):
    return nk


class TU:
    def __init__(self, obj, path, tag):
        self.obj, self.path, self.tag = obj, path, tag
        self.blocks = []
        self.placeholders = []      # (addr, size, name)
        self.local = []             # [(key, norm, item)] emitted in this TU
        self.flags = None
        self.gen = []               # include/gen/ headers the TU includes (gen/<ns>.h)
        self.gen_vars = {}          # name -> variants those headers declare

    @property
    def dir(self):
        return os.path.dirname(self.path)


# ---------------------------------------------------------------------------------------------
# Generation
class Generator:
    def __init__(self, state=None):
        self.funcs = load_functions()
        self.splits = load_splits()
        self.sources = load_sources()
        self.state = state if state is not None else load_state()
        self.tus = []
        self.merge_classes = True
        self.refusals = collections.Counter()
        self.stats = collections.Counter()
        self.notes = collections.defaultdict(list)

    def assign(self):
        starts = [o["start_i"] for o in self.splits]
        per_obj = collections.defaultdict(list)
        for addr in sorted(self.funcs):
            i = bisect.bisect_right(starts, addr) - 1
            if i < 0 or addr >= self.splits[i]["end_i"]:
                self.stats["functions outside splits"] += 1
                continue
            per_obj[i].append(addr)
        for addr in self.sources:
            if addr not in self.funcs:
                self.notes["sources without a functions.csv entry"].append("0x%08x" % addr)
        return per_obj

    def build(self):
        per_obj = self.assign()
        for i, o in enumerate(self.splits):
            addrs = per_obj.get(i, [])
            if o["kind"] == "library":
                v = [a for a in addrs if a in self.sources]
                self.stats["verified functions in library objects (not in the tree)"] += len(v)
                continue
            base = os.path.join("src", layer_of(o), o["file"])
            stem = base[:-4]
            tus = {"": TU(o, base, "")}
            blocks = []
            for addr in addrs:
                size, name = self.funcs[addr]
                src = self.sources.get(addr)
                if src is None:
                    tus[""].placeholders.append((addr, size, name))
                    continue
                kind, path, text = src
                blocks.append(Block(addr, size, name, kind, path, text))
            # placement `operator new` with and without throw() can't share a TU (a throw() new gets a null
            # check, so neither can stand in for the other) and must be global: the less used one of an
            # object goes to a sibling TU
            votes = collections.Counter((b.tag, placement_new(b)) for b in blocks if b.addr not in self.state["isolate"])
            for b in blocks:
                pn = placement_new(b)
                if pn and votes[(b.tag, pn)] < votes[(b.tag, "plain" if pn == "throw" else "throw")] or (
                        pn == "throw" and votes[(b.tag, pn)] == votes[(b.tag, "plain")]):
                    b.tag = (b.tag + "_" if b.tag else "") + "new_" + pn
                    self.stats["functions in a placement-new sibling TU"] += 1
            for b in blocks:
                addr = b.addr
                if addr in self.state["isolate"]:
                    b.mode = "isolated"
                    b.reasons.append(self.state["isolate"][addr])
                    t = TU(o, "%s.iso_%08x.cpp" % (stem, addr), "iso")
                    t.blocks.append(b)
                    t.flags = b.flags
                    tus["iso_%08x" % addr] = t
                    continue
                if addr in self.state["wrap"]:
                    b.wrap(self.state["wrap"][addr])
                tu = tus.get(b.tag)
                if tu is None:
                    tu = tus[b.tag] = TU(o, "%s.%s.cpp" % (stem, b.tag), b.tag)
                    tu.flags = b.flags
                tu.blocks.append(b)
            for t in tus.values():
                if t.blocks or t.placeholders:
                    self.tus.append(t)
        for t in self.tus:
            if any(b.gen_includes and b.mode == "merged" for b in t.blocks):
                self.merge_tu_gen(t)
            else:
                self.merge_tu(t)
        # a source on include/gen/ that can't merge gets its own TU: its definition (`void ns::X::f()`,
        # `template <> ...`) can't go inside a fn_<addr> namespace
        for t in list(self.tus):
            if t.tag == "iso":
                continue
            # a wrapped source that only includes include/decls/ stays wrapped: write_tu puts the header's
            # declarations inline in its fn_<addr> namespace
            for b in [b for b in t.blocks if b.mode == "wrapped"
                      and any(h.startswith("gen/") for h in b.gen_includes)]:
                t.blocks.remove(b)
                b.mode = "isolated"
                b.reasons.append("on include/gen/ and not mergeable")
                it = TU(t.obj, "%s.iso_%08x.cpp" % (t.path[:-4].split(".")[0], b.addr), "iso")
                it.blocks.append(b)
                it.flags = b.flags
                self.tus.append(it)
                self.stats["include/gen/ sources isolated (not mergeable)"] += 1
        self.hoist()

    # -- per TU --------------------------------------------------------------------------------
    def merge_tu(self, tu):
        """Decide which blocks of a TU can share one set of declarations; collect those declarations.

        For each name, the variants the TU's functions use are taken most-used first while they can coexist.
        Variants of a class that can't coexist are merged into one definition when every user's code compiles
        the same against it (tools/stub_layout.py); a merge is checked again against the whole TU (layouts
        of every class each function declares, in the TU's final declarations) and a function that would see
        a different layout is wrapped instead."""
        for b in tu.blocks:
            if not hasattr(b, "orig_decls"):
                b.orig_decls = list(b.decls)
        tu.gen = sorted({h for b in tu.blocks if b.mode == "merged" for h in b.gen_includes} | tu_data_headers(tu.blocks))
        tu.gen_vars = gen_variants(tu.gen) if tu.gen else {}
        for _ in range(12):
            for b in tu.blocks:
                b.decls = list(b.orig_decls)
            absorbed = self.choose_variants(tu)
            for b in tu.blocks:
                if b.mode != "merged":
                    continue
                subst = absorbed
                if subst:
                    nd = []
                    for (k, norm, it), (nk, var) in zip(b.orig_decls, block_variants_of(b.orig_decls)):
                        m = subst.get(nk, {}).get(var)
                        nd.append((key_of(m), m.norm, m) if m is not None else (k, norm, it))
                    b.decls = nd
            if not absorbed or not self.validate_tu(tu, absorbed):
                break
        seen = set()
        tu.variants = collections.defaultdict(set)       # name -> variants used by merged blocks (incl. defs)
        tu.local = []
        tu.merged_names = sorted(absorbed) if absorbed else []
        for nk, vs in tu.gen_vars.items():
            tu.variants[nk] |= vs           # keeps conflicting stubs out of the headers this TU includes
        for b in tu.blocks:
            if b.mode != "merged":
                continue
            for nk, var in block_variants(b):
                tu.variants[nk].add(var)
            for k, norm, it in b.decls:
                if (k, norm) not in seen:
                    seen.add((k, norm))
                    tu.local.append((k, norm, it, b.addr))

    def merge_tu_gen(self, tu):
        """A TU with sources on include/gen/ (or include/decls/): the headers' declarations win in the TU, so
        functions whose own stubs of those names differ are wrapped. Merge both ways, with the headers and
        without them (the sources on them then go to their own TUs), and keep the one with more merged
        functions."""
        start = {b.addr: (b.mode, list(b.reasons)) for b in tu.blocks}

        def reset():
            for b in tu.blocks:
                b.mode, b.reasons = start[b.addr][0], list(start[b.addr][1])
                if hasattr(b, "orig_decls"):
                    b.decls = list(b.orig_decls)

        def score():
            # merged functions, minus half a point per source that would go to its own TU (see build())
            iso = sum(1 for x in tu.blocks if x.mode == "wrapped" and any(h.startswith("gen/") for h in x.gen_includes))
            return sum(1 for x in tu.blocks if x.mode == "merged") - 0.5 * iso

        self.merge_tu(tu)
        with_gen = score()
        reset()
        for b in tu.blocks:
            if b.gen_includes and b.mode == "merged":
                b.wrap("on include/gen/, and its TU merges more functions without the headers")
        self.merge_tu(tu)
        without = score()
        if without > with_gen:
            self.stats["TUs that merge more without include/gen/"] += 1
            return
        reset()
        self.merge_tu(tu)
        self.stats["TUs on include/gen/"] += 1

    def choose_variants(self, tu):
        """Wrap the TU's blocks whose declarations can't share the TU's scope. Returns the substitutions
        {name: {variant: item}} the remaining blocks rely on: merged class definitions, and one
        representative for declarations that differ only in spelling (canonical_variant)."""
        while True:
            cand = [b for b in tu.blocks if b.mode == "merged"]
            users = collections.defaultdict(lambda: collections.defaultdict(set))   # name -> variant -> addrs
            raw = collections.defaultdict(lambda: collections.defaultdict(lambda: collections.defaultdict(set)))
            items = {}
            for b in cand:
                for nk, var, cvar, it in block_cvariants(b):
                    users[nk][cvar].add(b.addr)
                    raw[nk][cvar][var].add(b.addr)
                    if it is not None:
                        items.setdefault((nk, var), it)
            accepted = {nk: accept_variants(vs, tu.gen_vars.get(nk, ())) for nk, vs in users.items()}
            absorbed = {}
            for nk, vs in users.items():
                # spellings of one declaration: everyone uses the most-used spelling's item
                for cvar, rv in raw[nk].items():
                    if len(rv) > 1:
                        best = max(rv, key=lambda v: (len(rv[v]), -min(rv[v])))
                        rep = items.get((nk, best))
                        if rep is not None:
                            for v in rv:
                                if v != best:
                                    absorbed.setdefault(nk, {})[v] = rep
                if len(accepted[nk]) == len(vs) or not self.merge_classes or nk in tu.gen_vars:
                    continue
                m = self.merge_name(tu, nk, vs, cand)
                if m:
                    absorbed.setdefault(nk, {}).update(m)
            defined = {}
            new_bad = 0
            for b in cand:
                bad = sorted({name_str(nk) for nk, var, cvar, it in block_cvariants(b)
                              if cvar not in accepted[nk] and var not in absorbed.get(nk, {})})
                if bad:
                    b.wrap("conflict: " + "; ".join(bad[:4]) + (" (+%d)" % (len(bad) - 4) if len(bad) > 4 else ""))
                    new_bad += 1
                    continue
                dk = key_of(b.defs[0])
                if dk in defined:
                    b.wrap("same definition as 0x%08x in this TU" % defined[dk])
                    new_bad += 1
                    continue
                defined[dk] = b.addr
            if not new_bad:
                return absorbed

    def merge_name(self, tu, nk, vs, cand):
        """{variant: merged item} for the class variants of name nk that one merged definition can serve
        (the most-used variants first), or None."""
        cls_vars = [v for v in vs if v[0] == "class"]
        if len(cls_vars) < 2 or any(v[0] not in ("class", "fwd") for v in vs):
            return None
        by_addr = {b.addr: b for b in cand}
        infos = []
        for var in sorted(cls_vars, key=lambda v: (-len(vs[v]), min(vs[v]))):
            bs = [by_addr[a] for a in sorted(vs[var])]
            try:
                infos.append((var, self.variant_of(bs, nk, var)))
            except stub_layout.Unsupported:
                continue
        if len(infos) < 2:
            return None
        chosen, merged = [], None
        for var, info in infos:
            trial = chosen + [(var, info)]
            if len(trial) < 2:
                chosen = trial
                continue
            r = self.try_merge([i for _, i in trial])
            if r is not None:
                chosen, merged = trial, r
        if merged is None:
            return None
        item = merged
        return {var: item for var, _ in chosen}

    def variant_of(self, blocks, nk, var):
        it = next(it for k, norm, it in blocks[0].orig_decls if it.kind == "class" and item_variant(it, k, norm) == (nk, var))
        refs, defined = set(), set()
        for b in blocks:
            r, d = block_refs(b, it.key[1])
            refs |= r
            defined |= d
        bv = any(uses_by_value(b, it.name) for b in blocks)
        return stub_layout.Variant(it, block_ctx(blocks[0]), refs, defined, len(blocks), bv)

    def try_merge(self, infos):
        try:
            text, fwd = stub_layout.merge_variants(infos)
        except (stub_layout.Unsupported, ValueError, KeyError, IndexError) as e:
            self.stats["class merges refused"] += 1
            self.refusals[re.sub(r"\b\w+_[0-9a-f]{5,6}\b|\d+|\+0x[0-9a-f]+", "N", str(e))[:70]] += 1
            return None
        v0 = infos[0]
        try:
            it = cxx_items.parse(text)[0]
        except ValueError:
            return None
        it.scope = v0.item.scope
        it.key = ("class", v0.item.key[1])
        it.lead = ""
        it.merged_fwd = fwd
        it.merged_from = len(infos)
        for v in infos:
            # the variant's own declarations first; the others' for what only they declare (a base)
            items = list(v.ctx.items) + [x for w in infos if w is not v for x in w.ctx.items]
            try:
                ctx = stub_layout.Context(items, replace={it.key[1]: it})
                M = ctx.layout(it.key[1])
            except stub_layout.Unsupported as e:
                self.refusals["merged layout: " + re.sub(r"\b\w+_[0-9a-f]{5,6}\b|\d+", "N", str(e))[:60]] += 1
                return None
            why = stub_layout.check_variant(M, fwd, v)
            if why is not None:
                self.refusals["check: " + re.sub(r"\b\w+_[0-9a-f]{5,6}\b|\d+|\+0x[0-9a-f]+", "N", why)[:70]] += 1
                return None
        self.stats["class merges"] += 1
        return it

    def validate_tu(self, tu, absorbed):
        """Wrap merged blocks that would see a different layout of one of their classes in the TU's final
        declarations. Returns True if anything was wrapped (the TU's choices must be redone)."""
        items = []
        seen = set()
        for b in tu.blocks:
            if b.mode == "merged":
                for k, norm, it in b.decls:
                    if (k, norm) not in seen:
                        seen.add((k, norm))
                        items.append(it)
        tctx = stub_layout.Context(items)
        changed = False
        for b in tu.blocks:
            if b.mode != "merged":
                continue
            bad = None
            for k, norm, it in b.orig_decls:
                if it.kind != "class" or it.key[0] != "class":
                    continue
                q = it.key[1]
                own = block_ctx(b)
                try:
                    L = own.layout(q)
                except stub_layout.Unsupported:
                    L = None
                if L is None:
                    continue
                try:
                    M = tctx.layout(q)
                except stub_layout.Unsupported as e:
                    bad = "%s: %s" % (it.name, e)
                    break
                refs, defined = block_refs(b, q)
                v = stub_layout.Variant.__new__(stub_layout.Variant)
                v.item, v.ctx, v.refs, v.defined, v.layout, v.cls = it, own, refs, defined, L, L.cls
                v.by_value = uses_by_value(b, it.name)
                fwd = getattr(tctx.classes.get(q), "merged_fwd", {}) or {}
                why = stub_layout.check_variant(M, fwd, v, size_matters=uses_by_value(b, it.name))
                if why:
                    bad = "%s: %s" % (it.name, why)
                    break
            if bad:
                b.wrap("merged class would differ: " + bad)
                self.stats["blocks wrapped by the merged-layout check"] += 1
                changed = True
        return changed

    # -- across TUs -----------------------------------------------------------------------------
    def hoist(self):
        """Move declarations shared by several TUs into per-directory headers and common.h.

        A declaration goes to <dir>.h if at least two TUs of the directory use it and it is compatible with
        every variant of its name that any TU of the directory uses (merged functions only: wrapped ones
        live in their own namespace). Likewise for common.h across all directories. A declaration moves
        only together with the declarations it depends on."""
        deps = collections.defaultdict(set)
        for tu in self.tus:
            for b in tu.blocks:
                if b.mode != "merged":
                    continue
                prior = []
                for k, norm, it in b.decls:
                    for pk, pnorm, pit in prior:
                        if pit.name and pit.name in it.ids:
                            deps[(k, norm)].add((pk, pnorm))
                    prior.append((k, norm, it))
        self.deps = deps
        dir_vars = collections.defaultdict(lambda: collections.defaultdict(set))   # dir -> name -> variants
        all_vars = collections.defaultdict(set)
        dir_users = collections.defaultdict(lambda: collections.defaultdict(set))  # dir -> (k,norm) -> tus
        all_users = collections.defaultdict(set)                                   # (k,norm) -> dirs
        for tu in self.tus:
            for nk, vs in getattr(tu, "variants", {}).items():
                dir_vars[tu.dir][nk] |= vs
                all_vars[nk] |= vs
            for k, norm, it, _ in tu.local:
                dir_users[tu.dir][(k, norm)].add(tu.path)
                all_users[(k, norm)].add(tu.dir)
        # level per (directory, declaration): 0 stays in the TU, 1 goes to <dir>.h, 2 to common.h
        level, dir_ok = {}, {}
        for tu in self.tus:
            for k, norm, it, _ in tu.local:
                kn = (k, norm)
                if (tu.dir, kn) in level:
                    continue
                lv = 0
                nk, var = item_variant(it, k, norm)
                dir_ok[(tu.dir, kn)] = False
                if self.hoistable(nk, k, it):
                    if len(dir_users[tu.dir][kn]) >= 2 and all(compatible(var, v) for v in dir_vars[tu.dir][nk]):
                        lv = 1
                        dir_ok[(tu.dir, kn)] = True
                    if len(all_users[kn]) >= 2 and all(compatible(var, v) for v in all_vars[nk]):
                        lv = 2
                level[(tu.dir, kn)] = lv
        # common.h only if every directory agrees; a declaration moves only with its dependencies
        changed = True
        while changed:
            changed = False
            common_ok = collections.defaultdict(lambda: True)
            for (d, kn), lv in level.items():
                if lv < 2:
                    common_ok[kn] = False
            for (d, kn), lv in list(level.items()):
                if lv == 2 and not common_ok[kn]:
                    level[(d, kn)] = lv = 1 if dir_ok[(d, kn)] else 0
                    changed = True
                for dkn in deps.get(kn, ()):
                    dl = level.get((d, dkn), 0)
                    if dl < lv:
                        level[(d, kn)] = lv = dl
                        changed = True
        self.level = level
        self.headers = collections.defaultdict(list)      # header path -> [(key, norm, item, addr)]
        placed = set()
        for tu in self.tus:
            tu.header = tu.dir.replace("src/", "", 1) + ".h"
            keep = []
            for k, norm, it, addr in tu.local:
                lv = level[(tu.dir, (k, norm))]
                if lv == 0:
                    keep.append((k, norm, it, addr))
                    continue
                h = "common.h" if lv == 2 else tu.header
                if (h, k, norm) not in placed:
                    placed.add((h, k, norm))
                    self.headers[h].append((k, norm, it, addr))
            tu.local = keep

    def hoistable(self, nk, k, it):
        if tuple(nk) in self.state["local_only"]:
            return False
        if k[0] in ("macro", "funcdef", "template funcdef"):
            return False
        if k[0] == "var" and not it.text.lstrip().startswith("extern"):
            return False      # a definition, not a declaration
        return True

    # -- ordering ------------------------------------------------------------------------------
    def order(self, entries):
        """Topological order of [(key, norm, item, addr)] by self.deps; ties by first use."""
        idx = {(k, n): i for i, (k, n, _, _) in enumerate(entries)}
        indeg = collections.Counter()
        out = collections.defaultdict(list)
        for kn, i in idx.items():
            for d in self.deps.get(kn, ()):
                if d in idx and d != kn:
                    out[d].append(kn)
                    indeg[kn] += 1
        import heapq
        prio = {kn: (entries[i][3], i) for kn, i in idx.items()}
        heap = [(prio[kn], kn) for kn in idx if indeg[kn] == 0]
        heapq.heapify(heap)
        res, done = [], set()
        while len(res) < len(idx):
            if not heap:
                # cycle: release the earliest remaining item
                rest = min((prio[kn], kn) for kn in idx if kn not in done)
                heap.append(rest)
                indeg[rest[1]] = 0
            _, kn = heapq.heappop(heap)
            if kn in done:
                continue
            done.add(kn)
            res.append(entries[idx[kn]])
            for nx in out[kn]:
                indeg[nx] -= 1
                if indeg[nx] == 0 and nx not in done:
                    heapq.heappush(heap, (prio[nx], nx))
        return res

    # -- emit ----------------------------------------------------------------------------------
    def write(self):
        for sub in ("src", "include"):
            p = os.path.join(TREE, sub)
            if os.path.isdir(p):
                shutil.rmtree(p)
        manifest = {"tus": [], "headers": {}}
        write_file(os.path.join(TREE, "include", PRELUDE), PRELUDE_LINES)
        self.c_seen = {}        # header -> {C function name: shape} declared by it and what it includes
        self.prelude_use = {}   # header -> it (or common.h) names size_t / HULK_NEW_THROW
        self.header_globals = {}    # header -> top-level names it (and common.h) emits outside the TU namespace
        self.header_declared = {}   # header -> top-level names it (and common.h) declares
        self.header_gen_tops = {}   # header -> include/gen names whose items it emits under #ifdef TREE_LOCAL_<name>
        self.tu_ns_taken = set()
        for h, entries in sorted(self.headers.items()):
            lines = [HEADER]
            guard = "TREE_" + re.sub(r"\W", "_", h).upper()
            lines += ["#ifndef " + guard, "#define " + guard]
            # the TU namespace (see TU_NS_GLOBAL): a TU defines these before including its headers
            lines += ["#ifndef " + TU_BEGIN, "#define " + TU_BEGIN, "#define " + TU_END, "#endif"]
            if h != "common.h":
                lines.append('#include "common.h"')
            spans = []
            seen = self.c_seen[h] = dict(self.c_seen.get("common.h", {}))
            glob = self.header_globals[h] = set(self.header_globals.get("common.h", set()))
            declared = self.header_declared[h] = set(self.header_declared.get("common.h", set()))
            gnames = self.header_gen_tops[h] = set(self.header_gen_tops.get("common.h", set()))
            ns = NsLines(lines, {"tu": (TU_BEGIN, TU_END)})

            def local_if(nm, body):
                # an include/gen name: TU-local in the TUs whose include/gen headers don't declare it
                gnames.add(nm)
                ns.at(None)
                lines.extend(["#ifdef %s%s" % (TU_LOCAL, nm), TU_BEGIN, "#endif"] + body +
                             ["#ifdef %s%s" % (TU_LOCAL, nm), TU_END, "#endif"])
            for k, norm, it, addr in self.order(entries):
                cls = ns_class(it)
                top = item_top(it)
                if cls is None:
                    glob.add(top)
                if cls != "tu":
                    # TU-local stubs a global item names by `struct X` before their declaration
                    for ck, nm in elaborated_refs(it):
                        ncls = name_class(nm)
                        if nm in declared or ncls is None:
                            continue
                        fwd = "%s %s;   // (declared here for the next declaration)" % (ck, nm)
                        if ncls == "tu":
                            ns.at("tu")
                            lines.append(fwd)
                        else:
                            local_if(nm, [fwd])
                        declared.add(nm)
                        self.stats["stub classes forward-declared for a global declaration"] += 1
                declared.add(top)
                if cls == "gen":
                    s = len(lines) + 4
                    local_if(top, emit_item(it, seen))
                    spans.append([s, len(lines) - 3, list(map(str, k)), norm])
                    continue
                ns.at(cls)
                s = len(lines) + 1
                lines += emit_item(it, seen)
                spans.append([s, len(lines), list(map(str, k)), norm])
            ns.close()
            lines.append("#endif")
            self.prelude_use[h] = bool(PRELUDE_USE.search(native_spelling("\n".join(lines)))) or \
                self.prelude_use.get("common.h", False)
            write_file(os.path.join(TREE, "include", h), lines)
            manifest["headers"][h] = spans
        for tu in self.tus:
            manifest["tus"].append(self.write_tu(tu))
        with open(os.path.join(TREE, "manifest.json"), "w") as f:
            json.dump(manifest, f, indent=0)
        return manifest

    def write_tu(self, tu):
        o = tu.obj
        lines = []
        if tu.flags:
            lines.append("// cl-flags: " + " ".join(tu.flags))
        lines.append(HEADER)
        lines.append("// object %s..%s (kind %s, layer %s, confidence %s)%s" % (o["start"], o["end"], o["kind"], layer_of(o),
                                                                             o["confidence"],
                                                                   ", dominant class " + o["dominant"] if o.get("dominant") else ""))
        prelude_at = len(lines)
        lines.append('#include "%s"' % PRELUDE)
        rec = {"path": tu.path, "object": o["file"], "layer": layer_of(o), "start": o["start"], "tag": tu.tag,
               "flags": tu.flags or [], "blocks": [], "locals": [], "placeholders": len(tu.placeholders)}
        merged = [b for b in tu.blocks if b.mode == "merged"]
        gen = sorted({h for b in merged for h in b.gen_includes} | tu_data_headers(tu.blocks))
        for h in gen:
            lines.append('#include "%s"' % h)
        rec["gen"] = gen
        tu_ns = ns = None
        if merged:
            # the TU namespace (TU_NS_GLOBAL): TU-local declarations and merged definitions go inside it
            tu_ns = tu_namespace(tu.path, self.tu_ns_taken)
            rec["tu_ns"] = tu_ns
            lines += ["#define %s namespace %s {" % (TU_BEGIN, tu_ns), "#define %s }" % TU_END]
            hdr = tu.header if os.path.exists(os.path.join(TREE, "include", tu.header)) else "common.h"
            # include/gen names: TU-local where this TU's include/gen headers don't declare them (a stub of the
            # same name would hide the real class or namespace)
            gen_decl = header_tops(gen)
            for nm in sorted(self.header_gen_tops.get(hdr, set()) - gen_decl):
                lines.append("#define %s%s" % (TU_LOCAL, nm))
            lines.append("namespace %s {} using namespace %s;" % (tu_ns, tu_ns))
            hp = os.path.join(TREE, "include", tu.header)
            if os.path.exists(hp):
                lines.append('#include "%s"' % tu.header)
                hg = self.header_globals.get(tu.header, set())
            else:
                lines.append('#include "common.h"') if os.path.exists(os.path.join(TREE, "include", "common.h")) else None
                hg = self.header_globals.get("common.h", set())
            rec["header"] = tu.header
            glob = TU_NS_GLOBAL | gen_decl | hg | include_tops()[1]
            ns = NsLines(lines, {True: ("namespace %s {" % tu_ns, "} // namespace %s" % tu_ns)})
        if tu.local:
            lines.append("")
            lines.append("// ---- declarations shared by the functions below")
            # C names the TU's headers declared, and the C definitions of its functions (a definition can't change)
            seen = dict(self.c_seen.get(tu.header, self.c_seen.get("common.h", {}))) if merged else {}
            seen.update({it.name: _c_shape(it)[0] for b in tu.blocks if b.mode in ("merged", "wrapped")
                         for it in b.items if it.kind == "funcdef" and it.c_linkage and it.name and not it.is_inline})
            declared = set(self.header_declared.get(tu.header if merged and os.path.exists(
                os.path.join(TREE, "include", tu.header)) else "common.h", set())) if merged else set()
            for k, norm, it, addr in self.order(tu.local):
                if ns is not None:
                    local = not (always_global(it) or item_top(it) in glob)
                    if not local:
                        for ck, nm in elaborated_refs(it):
                            if nm not in declared and nm not in glob and not keeps_c_linkage(nm):
                                ns.at(True)
                                lines.append("%s %s;   // (declared here for the next declaration)" % (ck, nm))
                                declared.add(nm)
                                self.stats["stub classes forward-declared for a global declaration"] += 1
                    ns.at(True if local else None)
                    declared.add(item_top(it))
                s = len(lines) + 1
                d = as_declaration(it)
                if d is not None:
                    self.stats["variable definitions of merged sources emitted as declarations"] += 1
                lines += emit_item(d or it, seen)
                rec["locals"].append([s, len(lines), list(map(str, k)), norm,
                                      sorted(b.addr for b in merged if any(kk == k and nn == norm for kk, nn, _ in b.decls))])
        emitted_ops = {(it.name, it.params) for _, _, it, _ in tu.local if it.name and it.name.startswith("operator")}
        clink = CLinkage(self, tu, gen, merged)
        pin_declared = set()
        events = [(b.addr, 1, b) for b in tu.blocks] + [(a, 0, (a, s, n)) for a, s, n in tu.placeholders]
        events.sort(key=lambda e: (e[0], e[1]))
        lines.append("")
        for addr, isblock, x in events:
            if not isblock:
                a, s, n = x
                lines.append("// 0x%08x %s (%d B): not yet verified" % (a, n, s))
                continue
            b = x
            b.tu_ns = None
            if ns is not None:
                if b.mode == "merged" and not (always_global(b.defs[0]) or item_top(b.defs[0]) in glob):
                    b.tu_ns = tu_ns
                ns.at(True if b.tu_ns is not None else None)
            s = len(lines) + 1
            lines.append("")
            lines.append("// 0x%08x %s (%d B): %s%s" % (b.addr, b.name, b.size, b.path,
                                                       "" if b.mode == "merged" else " [%s: %s]" % (b.mode, "; ".join(b.reasons))))
            if b.mode == "merged":
                d = b.defs[0]
                lead = d.lead.strip("\n")
                lead_lines = [l for l in lead.splitlines() if l.strip().startswith("//") and "cl-flags" not in l]
                lines += lead_lines
                lines += emit_item(d)
            elif b.mode == "wrapped":
                # global operator new/delete must stay global: `new (p) T` never looks in a namespace
                text = b.text
                for it in sorted(global_operators(b), key=lambda it: -it.toks[0].s):
                    sig = (it.name, it.params)
                    if sig not in emitted_ops:
                        emitted_ops.add(sig)
                        lines += emit_item(native_inline(it))
                    text = text[:it.toks[0].s] + text[it.toks[-1].e:]
                # an include/decls/ header goes in inline: its declarations belong to the fn_<addr> namespace
                # with the source's own stubs (`struct World;` + the source's `struct World {...}`)
                text = re.sub(r'^[ \t]*#\s*include\s*[<"](decls/\w+\.h)[>"][ \t]*$', lambda m: decls_body(m.group(1)),
                              text, flags=re.M)
                text = DATA_INCLUDE.sub("", text)        # hoisted to the TU (tu_data_headers)
                text, pinned = pin_views(text)
                text, n_cdefs = c_var_declarations(text)
                if n_cdefs:
                    self.stats["C-linkage variable definitions in wrapped sources emitted as declarations"] += n_cdefs
                for nm in pinned:
                    if nm not in clink.global_names and nm not in pin_declared:
                        # the one global C declaration the source's typed views read (see pin_views)
                        lines.append('extern "C" { extern void* %s; }   // (pinned global: one C name for every view)' % nm)
                        pin_declared.add(nm)
                if pinned:
                    self.stats["pinned global declarations in wrapped sources made views of the C name"] += len(pinned)
                text, local_c = clink.rewrite(b, text)
                if local_c:
                    self.stats["C-linkage declarations made namespace-local in wrapped sources"] += len(local_c)
                    b.c_local = local_c
                lines.append("namespace %s {" % b.ns)
                lines += [l for l in text.rstrip("\n").splitlines()]
                lines.append("} // namespace %s" % b.ns)
                for m in b.macros + sorted(pinned):
                    lines.append("#undef " + m)
            else:
                text, b.tu_ns = self.iso_text(tu, b)
                lines += text
                if b.tu_ns:
                    rec["tu_ns"] = b.tu_ns
            lines.append("")
            rec["blocks"].append({"addr": "0x%08x" % b.addr, "name": b.name, "src": b.path, "kind": b.kind,
                                  "mode": b.mode, "reasons": b.reasons, "lines": [s, len(lines)],
                                  "ns": b.ns if b.mode == "wrapped" else None})
            if b.tu_ns:
                rec["blocks"][-1]["tu_ns"] = b.tu_ns
            if getattr(b, "c_local", None):
                rec["blocks"][-1]["c_local"] = b.c_local
        if ns is not None:
            ns.close()
        if not PRELUDE_USE.search(native_spelling("\n".join(lines))) and not (
                merged and self.prelude_use.get(tu.header, self.prelude_use.get("common.h"))):
            # only TUs that name size_t or HULK_NEW_THROW include the prelude: one more typedef in MSVC 7.1's
            # symbol table is enough to swap two commutative operands in a large function (seen once)
            lines[prelude_at] = "// (%s: not needed)" % PRELUDE
        write_file(os.path.join(TREE, tu.path), lines)
        return rec

    def iso_text(self, tu, b):
        """(lines, TU namespace or None) of an isolated source. The source goes into a TU namespace like a
        merged TU's declarations (its stubs and helpers would otherwise collide with other isolated TUs' in the
        native link): the include/decls/data/ headers go first, global operator new/delete stay global where
        they are (the namespace closes around them; `using namespace` makes the source's typedefs visible to
        them), an include/decls/ header goes in inline. Not for sources on include/gen/ (their definitions are
        members of the real classes), with other preprocessor includes, using-directives, `::name`
        qualifiers or type_info, or that build_tree.py found failing or changed that way (state `iso_plain`)."""
        text = b.text
        ops = sorted(global_operators(b), key=lambda it: -it.toks[0].s)
        plain_text = text
        for it in ops:
            if is_native_inline(it):
                plain_text = plain_text[:it.toks[0].s] + NATIVE_INLINE + " " + plain_text[it.toks[0].s:]
        plain = (plain_text.rstrip("\n").splitlines(), None)
        if (b.addr in self.state.get("iso_plain", {}) or not b.items or any(h.startswith("gen/") for h in b.gen_includes)
                or any(it.kind == "using" for it in b.items) or re.search(r"(?<![\w>)\]])::\s*[A-Za-z_]", text)
                or re.search(r"\b(type_info|typeid)\b", text)):
            return plain
        incs = re.findall(r'^[ \t]*#\s*include\b.*$', text, re.M)
        if any(not (DATA_INCLUDE.match(l + "\n") or re.match(r'\s*#\s*include\s*[<"]decls/\w+\.h[>"]', l))
               for l in incs):
            return plain
        ns = tu_namespace(tu.path, self.tu_ns_taken)
        # global operators in place: close the namespace around them
        for it in ops:
            text = "%s\n} // namespace %s\n%s%s\nnamespace %s {\n%s" % (
                text[:it.toks[0].s], ns, NATIVE_INLINE + " " if is_native_inline(it) else "",
                text[it.toks[0].s:it.toks[-1].e], ns, text[it.toks[-1].e:])
        pre = [l.strip() for l in DATA_INCLUDE.findall(text)]
        text = DATA_INCLUDE.sub("", text)
        text = re.sub(r'^[ \t]*#\s*include\s*[<"](decls/\w+\.h)[>"][ \t]*$', lambda m: decls_body(m.group(1)),
                      text, flags=re.M)
        text, pinned = pin_views(text)          # (see PINNED)
        pre += ['extern "C" { extern void* %s; }   // (pinned global: one C name for every view)' % n for n in sorted(pinned)]
        self.stats["isolated sources in a TU namespace"] += 1
        return pre + ["namespace %s {} using namespace %s;" % (ns, ns), "namespace %s {" % ns] + \
            text.rstrip("\n").splitlines() + ["} // namespace %s" % ns] + ["#undef " + n for n in sorted(pinned)], ns

    # -- conflicts ------------------------------------------------------------------------------
    def conflicts(self):
        """Symbols declared incompatibly by different verified sources (across the whole tree).

        Each entry: the name, its class (`address`: the name carries an address, FUN_/DAT_/thunk_...;
        `rtti`: an RTTI class or method; `invented`: a placeholder name such as Obj or Base reused with
        different meanings), the differing declarations with their sources, and how many functions were
        wrapped because of it."""
        rtti = rtti_names()
        simple = lambda n: re.sub(r"<.*", "", n).split("::")[-1]
        rtti_simple = {simple(n) for n in rtti if "<" in n}      # template families (fight::ParamBool<X>)
        # global-scope stubs of namespaced RTTI classes (`ParamValue` for fight::ParamValue)
        rtti_short = {simple(n) for n in rtti if "::" in re.sub(r"<.*", "", n)}
        variants = collections.defaultdict(lambda: collections.defaultdict(list))
        for tu in self.tus:
            for b in tu.blocks:
                for nk, var in block_variants_of(getattr(b, "orig_decls", b.decls)):
                    variants[nk][var].append((b.path, tu.path))
        blocked = collections.Counter()
        for tu in self.tus:
            for b in tu.blocks:
                for r in b.reasons:
                    if r.startswith("conflict: "):
                        for nm in re.sub(r" \(\+\d+\)$", "", r[len("conflict: "):]).split("; "):
                            blocked[nm] += 1
        out = []
        for nk, vs in variants.items():
            if len(vs) < 2:
                continue
            kept = accept_variants({v: set(range(len(x))) for v, x in vs.items()})
            if len(kept) == len(vs):
                continue                       # all variants can coexist (overloads, fwd + definition)
            cls = ("address" if re.search(r"(?:^|_)(?:FUN|DAT|LAB|PTR|thunk_FUN)_[0-9a-fA-F]{6,8}\b|_[0-9a-f]{8}\b", nk)
                   else "rtti" if nk in rtti or nk.rsplit("::", 1)[0] in rtti or simple(nk) in rtti_simple
                   else "rtti_stub" if "::" not in nk and nk in rtti_short
                   else "invented")
            tus = len({t for x in vs.values() for _, t in x})
            out.append({"symbol": nk, "class": cls, "variants": len(vs), "sources": sum(len(v) for v in vs.values()),
                        "tus": tus, "wrapped_because": blocked.get(nk, 0),
                        "declarations": [{"kind": v[0], "text": v[1][:400], "count": len(x),
                                          "sources": sorted({p for p, _ in x})[:8]}
                                         for v, x in sorted(vs.items(), key=lambda kv: (-len(kv[1]), kv[0][1]))[:6]]})
        out.sort(key=lambda c: (-c["wrapped_because"], -c["sources"], c["symbol"]))
        return out


def rtti_names():
    p = os.path.join(ROOT, "build/rtti.json")
    try:
        return {re.sub(r"\b(class|struct|enum|union) ", "", c["name"]) for c in json.load(open(p))["classes"] if c.get("name")}
    except (OSError, ValueError):
        return set()


# ---------------------------------------------------------------------------------------------
# C-linkage declarations in wrapped sources (docs/native-build.md fix 2)
# C names that keep C linkage whatever: compiler intrinsics and the C runtime (MSVC expands `sqrt`, `sin`,
# `memcpy`, `_ReadWriteBarrier` ... inline only for the C declaration), and reserved `_names`
C_RUNTIME = CRT_NAMES | set("""memmove strncpy strcat strncmp stricmp strnicmp strchr strrchr strstr strtok sprintf
_snprintf vsprintf sscanf printf atoi atof atol strtol strtoul strtod toupper tolower isspace isdigit isalpha malloc
free calloc realloc sqrt sin sinf cos cosf tan tanf atan atanf atan2 atan2f asin asinf acos acosf exp expf log logf
log10 pow powf fabsf floor floorf ceil ceilf fmod fmodf ldexp frexp modf abs labs rand srand qsort bsearch time
clock wcslen wcscpy itoa""".split())


def keeps_c_linkage(name):
    return name.startswith("_") or name in C_RUNTIME
BUILTIN_WORDS = cxx_items.TYPE_WORDS | {"extern", "static", "inline", "__inline", "__forceinline", "__cdecl", "_cdecl",
                                        "__stdcall", "__fastcall", "__thiscall", "__declspec", "noreturn", "throw"}


def _c_shape(it):
    """(kind, normalized type) of a C-linkage declaration or definition, and whether it uses only builtin types."""
    if it.kind in ("func", "funcdef") and it.sig is not None:
        parts = _norm_sig_parts(it)
        shape = ("f",) + ((parts[0], tuple(parts[1]), parts[2]) if parts else (it.sig,))
        words = re.findall(r"[A-Za-z_]\w*", it.sig or "")
    else:
        vs = [t.v for t in it.toks if t.v not in ("extern", '"C"', ";")]
        shape = ("v", " ".join(vs))
        words = [t.v for t in it.toks if t.t == "id" and t.v != it.name]
    return shape, all(w in BUILTIN_WORDS for w in words)


class CLinkage:
    """Makes a wrapped source's `extern "C"` declarations namespace-local where they would clash in the TU.

    MSVC 7.1 accepts one C-linkage name declared with different types in different namespaces (each wrapped
    source in its namespace fn_<addr> declares its callees with its own stub types); clang does not (79 TUs).
    For a declaration (never a definition) in a wrapped source, the C linkage is replaced by C++ linkage
    (`extern "C++"`), so the name becomes fn_<addr>::name, unique to that source:

      * never compiler intrinsics, C runtime names or reserved `_names` (keeps_c_linkage: MSVC expands `sqrt` or
        `_ReadWriteBarrier` inline only for the C declaration);
      * invented names (no address in the name): always, so that a name like `Lookup` means
        one address per symbol, which the native link binds by address (tools/native_link.py);
      * address names (FUN_/DAT_...): when the TU already has a declaration of that C name (in an
        included header, a shared declaration, an earlier wrapped source, any C definition) of another type,
        or one whose types are not all builtin (a stub class of another namespace is another type), or a
        global variable / C++ function of that name.

    The code does not change: a call or a load is the same instruction whatever the callee's linkage; only the
    relocation's symbol name differs (compare.py masks relocations; build_tree.same_code compares them by the
    address in the name). Functions get `__declspec(nothrow)`, because /GX (= /EHsc) assumes C functions never
    throw and C++ ones may, which would add EH state stores around calls in functions with unwinding.
    build_tree.py's regression rounds would catch any change anyway."""

    def __init__(self, gen, tu, headers, merged):
        self.seen = {}          # C name -> (shape, builtin_only) of the first declaration in the TU
        self.defs = {}          # C name -> (shape, builtin_only) of a C definition anywhere in the TU
        self.globals_cpp = set()    # names of global-scope C++ variables / functions declared before
        items = []
        for h in headers:
            items += gen_header_items(h)
        if merged:
            for h in ("common.h", tu.header):
                items += [it for _, _, it, _ in gen.headers.get(h, ())]
            items += [it for _, _, it, _ in tu.local]
        for it in items:
            self.note(it)
        for b in tu.blocks:
            if b.mode in ("merged", "wrapped"):
                for it in b.items:
                    if it.kind == "funcdef" and it.c_linkage and it.name and not it.is_inline:
                        self.defs.setdefault(it.name, _c_shape(it))
                    elif b.mode == "merged" and it in b.defs:
                        self.note(it)      # a global C++ definition of that name
        # names the TU declares at global scope (headers, shared declarations, merged definitions)
        self.global_names = set(self.seen) | set(self.globals_cpp)

    def note(self, it):
        if it.kind not in ("func", "var", "funcdef") or not it.name:
            return
        if it.c_linkage or it.kind == "var" and it.name in PINNED:
            self.seen.setdefault(it.name, _c_shape(it))
        elif not it.scope and "::" not in (it.key[1] if it.key else ""):
            self.globals_cpp.add(it.name)

    def clashes(self, it):
        n = it.name
        if keeps_c_linkage(n):
            return False
        if not ADDR_NAME.search(n):
            return True
        shape, builtin = _c_shape(it)
        if n in self.globals_cpp:
            return True
        for prev in (self.defs.get(n), self.seen.get(n)):
            if prev is not None and (prev[0] != shape or not (builtin and prev[1])):
                return True
        return False

    def rewrite(self, b, text):
        """(text, [names made namespace-local]) for a wrapped block's final source text."""
        try:
            items = cxx_items.parse(text)
        except ValueError:
            return text, []
        own = {it.name for it in items if it.kind == "funcdef" and it.name}
        edits, names = [], []
        for it in items:
            if not (it.c_linkage and it.kind in ("func", "var") and it.name):
                continue       # (C++ names here are inside fn_<addr>: they clash with nothing)
            vs = [t.v for t in it.toks]
            if it.name in own or it.kind == "var" and "extern" not in vs:
                self.note(it)      # its own definition, or a variable definition
                continue
            if not self.clashes(it) and not (it.kind == "var" and "," in vs):    # (several declarators: always)
                self.note(it)
                continue
            names.append(it.name)
            if len(vs) > 1 and vs[0] == "extern" and vs[1] == '"C"':
                t = it.toks[1]
                if it.kind == "func":
                    # `extern "C" R f(...);` -> `extern "C++" __declspec(nothrow) R f(...);`
                    edits.append((t.s, t.e, '"C++" __declspec(nothrow)'))
                else:
                    # `extern "C" T x;` -> `extern "C++" { extern T x; }`
                    edits.append((t.s, t.e, '"C++" { extern'))
                    edits.append((it.toks[-1].e, it.toks[-1].e, " }"))
            else:
                ns = "__declspec(nothrow) " if it.kind == "func" else ""
                # inside an `extern "C" { ... }` block
                edits.append((it.toks[0].s, it.toks[0].s, 'extern "C++" { ' + ns))
                edits.append((it.toks[-1].e, it.toks[-1].e, " }"))
        for s, e, rep in sorted(edits, reverse=True):
            text = text[:s] + rep + text[e:]
        return text, names


# ---------------------------------------------------------------------------------------------
# The TU namespace (docs/native-build.md "Next fixes" 1): a TU's own declarations and merged definitions
# live in `namespace fn_f<7 hex>` (one per TU), so the invented stub classes, helper functions and
# variables of different TUs get different symbols (`Action::~Action` was 43 different destructors under
# one name, which the native link reports as duplicates). The name has the shape of a wrapped block's
# `fn_<addr>` namespace on purpose: tools/equiv.py and tools/clang_probe.py already look through
# `fn_<8 hex>::` (fn_f... is never a function address, which all start 00). The MSVC 7.1 code does not
# change: only symbol names do (compare.py masks relocations; build_tree.same_code compares relocation
# targets by the address in the name), and build_tree.py's regression rounds would catch anything else.
#
# What stays global (outside the namespace), decided by an item's top-level name (its first namespace or
# its name; `pure3d::X::f` -> pure3d, `Action::~Action` -> Action):
#   * names declared by include/gen/ and include/decls/ (the real classes, pinned prototypes and data):
#     for a TU-local item, those of the headers this TU includes; for an item of a tree header (shared by
#     many TUs), those of all of include/; and then, in the TU, every top-level name its tree headers
#     emit globally, so that one name is never both global and TU-local in a TU;
#   * global operator new/delete (`new (p) T` only looks at global scope), the C runtime and `_names`
#     (keeps_c_linkage), anonymous namespaces, type_info / std / size_t;
#   * wrapped blocks (already unique by their fn_<addr> namespace) and isolated TUs (verbatim sources).
# A global definition (a member of an include/gen class) still sees the TU's stubs: every TU says
# `using namespace fn_f...;` before its declarations.
TU_NS_GLOBAL = {"type_info", "std", "size_t", "ptrdiff_t", "wchar_t", "va_list", "<anon>", "__type_info_node"}
TU_BEGIN, TU_END, TU_LOCAL = "TREE_TU_BEGIN", "TREE_TU_END", "TREE_LOCAL_"
_INCLUDE_TOPS = []


def tu_namespace(path, taken):
    """`fn_f<7 hex>` for a TU path, unique among `taken` (which it joins)."""
    salt = 0
    while True:
        h = hashlib.sha1(("%s#%d" % (path, salt)).encode()).hexdigest()[:7]
        ns = "fn_f" + h
        if ns not in taken:
            taken.add(ns)
            return ns
        salt += 1


def item_top(it):
    """The top-level name an item declares or defines in (see above)."""
    if it.scope:
        return it.scope[0]
    q = it.key[1] if it.key and len(it.key) > 1 else (it.name or "")
    q = str(q).lstrip(":")
    first = split_qualified_name(q)[0] if q else ""
    return re.sub(r"<.*", "", first).strip() or "<anon>"


def split_qualified_name(q):
    """'a::B<x::y>::f' -> ['a', 'B<x::y>', 'f']."""
    out, cur, depth, i = [], "", 0, 0
    while i < len(q):
        c = q[i]
        if c == "<":
            depth += 1
        elif c == ">":
            depth -= 1
        if depth == 0 and q.startswith("::", i):
            out.append(cur)
            cur = ""
            i += 2
            continue
        cur += c
        i += 1
    out.append(cur)
    return [p for p in out if p] or [""]


def always_global(it):
    """Items that never go into the TU namespace, whatever their name."""
    if it.kind in ("pp", "define", "undef", "using", "macro", "other"):
        return True
    n = it.name or ""
    if re.match(r"operator\s*(new|delete)", n) and not it.scope and "::" not in str(it.key[1] if it.key else ""):
        return True
    if it.c_linkage and n and keeps_c_linkage(n):
        return True
    if it.scope and it.scope[0] == "<anon>":
        return True
    return False


def header_tops(headers):
    """Top-level names the include/ headers declare (include/gen/, include/decls/, include/decls/data/)."""
    out = set()
    for h in headers:
        for it in gen_header_items(h):
            out.add(item_top(it))
    return out


def include_tops():
    """(top-level names declared by include/gen/, by include/decls/ (and include/decls/data/)), cached."""
    if not _INCLUDE_TOPS:
        hs = {"gen": [], "decls": []}
        for dp, dns, fns in os.walk(INCLUDE_ROOT):
            dns.sort()
            rel = os.path.relpath(dp, INCLUDE_ROOT)
            top = rel.split(os.sep)[0]
            if top in hs:
                hs[top] += [os.path.join(rel, fn).replace(os.sep, "/") for fn in sorted(fns) if fn.endswith(".h")]
        _INCLUDE_TOPS.append((header_tops(hs["gen"]), header_tops(hs["decls"]) | TU_NS_GLOBAL))
    return _INCLUDE_TOPS[0]


def name_class(nm):
    """ns_class for a bare top-level name."""
    gen_tops, decls_tops = include_tops()
    if nm in decls_tops or keeps_c_linkage(nm):
        return None
    if nm in gen_tops:
        return "gen" if re.fullmatch(r"[A-Za-z_]\w*", nm) else None
    return "tu"


def ns_class(it):
    """Where an item of a tree header goes: 'tu' (the TU namespace), 'gen' (an include/gen name: the TU
    namespace in the TUs whose include/gen headers don't declare it, `#ifdef TREE_LOCAL_<name>`), or None
    (global: always_global, or an include/decls/ name)."""
    if always_global(it):
        return None
    return name_class(item_top(it))


def elaborated_refs(it):
    """[(class key, name)] of the unqualified `struct X` / `class X` / `union X` an item mentions (not its own
    name). Where X is not declared yet, such a mention declares X in the item's namespace, so a global item
    naming a TU-local stub that way would declare a second, global X; the generator declares it first."""
    out, toks = [], it.toks
    own = it.name if it.kind in ("class", "template class", "fwd") else None
    for i in range(len(toks) - 1):
        if toks[i].v in ("struct", "class", "union") and toks[i + 1].t == "id":
            nm = toks[i + 1].v
            nxt = toks[i + 2].v if i + 2 < len(toks) else ""
            if nm == own or nxt in ("::", "{", ":") or nm in cxx_items.KEYWORDS:
                continue
            if i and toks[i - 1].v in ("<", ",", "template", "typename", "enum", "friend"):
                continue        # template parameters, `enum class`, friend declarations
            out.append((toks[i].v, nm))
    return out


def as_declaration(it):
    """A TU-local variable definition of a merged source (`float gNegOne = -1.0f;`, `int g_4dd834;`) as a
    declaration (`extern float gNegOne;`), or None to keep it. The data TUs (tools/data_gen.py) own the
    game's data; tools/native_link.py binds the declaration by the address the verification build proves
    for it. A definition gave every TU its own copy (the native link's duplicates), and a mutable global
    defined in two TUs would be two variables. The MSVC 7.1 code is the same: a load or store of a
    non-const global is the same instruction whether the TU defines it or not (no inter-procedural
    assumptions under /O2 without /GL). Kept as definitions: const objects (internal linkage, and MSVC
    folds their values), `static` ones, and anything unusual (a class type, braces, several declarators
    with initializers)."""
    if it.kind != "var" or not it.name or it.text.lstrip().startswith("extern") or it.scope[:1] == ("<anon>",):
        return None
    vs = [t.v for t in it.toks]
    if any(v in ("static", "const", "__declspec", "typedef", "{", "(", "operator", "template") for v in vs):
        return None
    if vs[-1:] != [";"]:
        return None
    # drop each top-level initializer (`= ...` up to the next top-level `,` or the `;`)
    base = it.toks[0].s
    text, depth, skip, prev = "", 0, False, None
    for t in it.toks:
        if t.v in ("(", "[", "<"):
            depth += 1
        elif t.v in (")", "]", ">"):
            depth -= 1
        if depth == 0 and t.v == "=":
            skip = True
        elif depth == 0 and t.v in (",", ";"):
            skip = False
        if skip:
            prev = None
            continue
        if prev is not None:
            text += it.text[prev.e - base:t.s - base]
        text += it.text[t.s - base:t.e - base]
        prev = t
    import copy
    d = copy.copy(it)
    d.text = "extern " + text
    return d


class NsLines:
    """Appends to `lines`, with begin/end lines around runs of entries of one namespace class (None: global)."""

    def __init__(self, lines, marks):
        self.lines, self.marks, self.cur = lines, marks, None      # marks: class -> (begin, end)

    def at(self, cls):
        if cls != self.cur:
            if self.cur is not None:
                self.lines.append(self.marks[self.cur][1])
            if cls is not None:
                self.lines.append(self.marks[cls][0])
            self.cur = cls

    def close(self):
        self.at(None)


# ---------------------------------------------------------------------------------------------
# The pinned globals (docs/native-build.md "Next fixes" 2, docs/data.md "What is left"): DAT_004dd700 & co. are
# declared by include/decls/address.h as pointers to `struct World` etc., and every source defines its own
# `World` stub. In a wrapped source that stub is fn_<addr>::World, so the declaration had to become
# fn_<addr>::DAT_004dd700 (CLinkage: one C name can't have two types in one TU under clang) and the native
# link could only bind it by address. Instead, a wrapped source's declaration of a pinned name becomes a typed
# view of the TU's one C declaration: `#define DAT_004dd700 (*(World* *)&::DAT_004dd700)` inside its namespace
# (#undef after it), where World is the source's own stub. The access is the same lvalue (a load of
# [_DAT_004dd700]), so the MSVC 7.1 code does not change; every reference is to `_DAT_004dd700`, the data TU's
# definition. The TU's global declaration is the merged one (forced to C linkage, emit_item) or, if the TU has
# none, `extern "C" void* DAT_004dd700;`.
PINNED = ("DAT_004dd700", "DAT_0052c2a8", "DAT_004dd6ec")


def c_var_declarations(text):
    """(text, count): a wrapped source's C-linkage variable definitions (`extern "C" { void* g_anim_vtable; }`) as
    declarations (as_declaration). C names ignore the fn_<addr> namespace, so two clones defining one are a
    redefinition under clang and a duplicate in the native link; the data (or vftable) is the game's, which
    tools/native_link.py binds by address. The MSVC 7.1 code is the same (a load, store or address of a global)."""
    if "extern" not in text:
        return text, 0
    try:
        items = cxx_items.parse(text)
    except ValueError:
        return text, 0
    edits = []
    for it in items:
        if it.kind == "var" and it.c_linkage and not it.scope:
            d = as_declaration(it)
            if d is not None:
                edits.append((it.toks[0].s, it.toks[-1].e, d.text))
    for s_, e_, rep in sorted(edits, reverse=True):
        text = text[:s_] + rep + text[e_:]
    return text, len(edits)


def pin_views(text):
    """(text, {names}) with a wrapped source's declarations of the pinned names replaced by typed views."""
    if not any(n in text for n in PINNED):
        return text, set()
    try:
        items = cxx_items.parse(text)
    except ValueError:
        return text, set()
    edits, names = [], set()
    for it in items:
        if it.kind == "fwd" and len(it.toks) >= 5 and it.toks[-2].v in PINNED and \
                re.fullmatch(r'extern\s+(?:"C"\s+)?(?:class|struct|union)\s+\w+\s*\*\s*\w+\s*;', it.text):
            it.name = it.toks[-2].v          # `extern class X* DAT_x;` (parsed as a class declaration)
        elif it.kind != "var" or it.name not in PINNED:
            continue
        vs = [t.v for t in it.toks]
        if not (vs[0] == "extern" or it.linkage == "C") or any(v in vs for v in ("=", "[", "(", ",")) \
                or vs[-1] != ";" or vs[-2] != it.name:
            return text, set()             # a definition or an unusual declarator: leave the source as it is
        ty = [t for t in it.toks[:-2] if t.v not in ("extern", '"C"')]
        if not ty:
            return text, set()
        tytext = text[ty[0].s:ty[-1].e]
        line = "" if it.name in names else "#define %s (*(%s *)&::%s)" % (it.name, tytext, it.name)
        edits.append((it.toks[0].s, it.toks[-1].e, "\n" + line + "\n"))
        names.add(it.name)
    for s_, e_, rep in sorted(edits, reverse=True):
        text = text[:s_] + rep + text[e_:]
    return text, names


def placement_new(b):
    """'throw' / 'plain' for a block that declares the placement `operator new(unsigned int, void*)` with or
    without an exception specification, else None."""
    for it in b.items:
        if it.kind in ("func", "funcdef") and not it.scope and it.name == "operatornew" and it.params:
            ps = [p.strip() for p in stub_layout.split_commas(it.params)]
            if len(ps) == 2 and ps[1].replace(" ", "") == "void*":
                return "throw" if "throw" in (it.sig or "") else "plain"
    return None


def global_operators(b):
    """Top-level `operator new` / `operator delete` declarations and definitions of a block."""
    return [it for it in b.items if it.kind in ("func", "funcdef") and not it.scope and it.name
            and re.match(r"operator(new|delete)", it.name) and "::" not in it.key[1]]


NATIVE_INLINE = "HULK_NATIVE_INLINE"


def is_native_inline(it):
    """Only operator new definitions (they name size_t, so their TU includes tree_prelude.h anyway: a TU that
    didn't must not start including it)."""
    return it.kind == "funcdef" and not it.is_inline and (it.name or "").startswith("operatornew")


def native_inline(it):
    """A global operator new/delete definition, `inline` off MSVC 7.1 (tree_prelude.h's HULK_NATIVE_INLINE):
    several TUs define the same placement new, which the native link would report as duplicates; under
    MSVC 7.1 the macro is empty (/O2 = /Ob1: `inline` would let callers inline it)."""
    if not is_native_inline(it):
        return it
    import copy
    d = copy.copy(it)
    d.text = NATIVE_INLINE + " " + it.text
    return d


def emit_item(it, c_seen=None):
    """Source lines for an item, re-wrapped in its namespaces and extern "C" block.

    c_seen ({C function name: shape} of the file so far): the merge treats C and C++ linkage of an address name
    as one spelling, so a TU can declare two overloads of FUN_x with C linkage, which MSVC 7.1 accepts and clang
    does not; the second and later ones are emitted with C++ linkage (see CLinkage: same code)."""
    opens, closes = [], []
    for ns in it.scope:
        opens.append("namespace %s {" % ("" if ns == "<anon>" else ns))
        closes.insert(0, "}")
    text = it.text
    linkage = it.linkage
    if it.kind == "var" and it.name in PINNED and not it.c_linkage and not it.scope:
        if text.lstrip().startswith("extern"):
            text = 'extern "C" { %s }' % text.strip()      # one C name in every TU (see PINNED)
    if c_seen is not None and it.kind == "func" and it.c_linkage and it.name and not keeps_c_linkage(it.name):
        shape = _c_shape(it)[0]
        if c_seen.setdefault(it.name, shape) != shape:
            if linkage == "C":
                linkage = None
                text = 'extern "C++" __declspec(nothrow) ' + text
            else:
                text = re.sub(r'^(\s*extern\s*)"C"', r'\1"C++" __declspec(nothrow)', text, count=1)
    if linkage == "C":
        opens.append('extern "C" {')
        closes.insert(0, "}")
    body = text.splitlines()
    if opens:
        return [" ".join(opens)] + body + [" ".join(closes)]
    return body


def write_file(path, lines):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="latin1") as f:
        f.write(native_spelling("\n".join(lines) + "\n"))


# ---------------------------------------------------------------------------------------------
# One size_t and one spelling of the global operator new (docs/native-build.md fix 1). Sources declare
# `typedef unsigned int size_t;` and `operator new(unsigned int, ...)` themselves; that is size_t under MSVC
# and on every 32-bit target, but not on 64-bit ones, and `void* operator new(size_t) throw();` contradicts
# the implicit declaration on non-MS targets. Every TU that names size_t includes tree_prelude.h first, which
# declares size_t once; the tree spells size_t in operator new/delete parameters and HULK_NEW_THROW for the non-placement
# operator new's `throw()`. Under MSVC 7.1 the types and the expansion are the same tokens' meaning as before
# (size_t is unsigned int; HULK_NEW_THROW is throw()), so the verification build's code does not change.
# The rewrite never changes the number of lines (the manifest's line spans stay right).
PRELUDE = "tree_prelude.h"
PRELUDE_LINES = [
    HEADER,
    "// Included first by every TU of the tree (docs/native-build.md fix 1).",
    "#ifndef TREE_PRELUDE_H",
    "#define TREE_PRELUDE_H",
    "#if defined(__SIZE_TYPE__)",
    "typedef __SIZE_TYPE__ size_t;          /* clang, any target */",
    "#else",
    "typedef unsigned int size_t;           /* MSVC 7.1 (predeclares the same type) */",
    "#endif",
    "/* the exception specification of the global `operator new(size_t)` a TU declares: MSVC null-checks the",
    "   result of a throw() new (codegen depends on it); non-MS targets declare it implicitly without one, so",
    "   the native build drops it there and compiles with -fcheck-new instead */",
    "#if defined(_MSC_VER)",
    "#define HULK_NEW_THROW throw()",
    "#else",
    "#define HULK_NEW_THROW",
    "#endif",
    "/* global operator new/delete definitions that several TUs repeat (the placement new): `inline` for the",
    "   native build, so its link keeps one; nothing under MSVC 7.1 (/Ob1 would inline them into callers) */",
    "#if defined(_MSC_VER) && !defined(__clang__)",
    "#define HULK_NATIVE_INLINE",
    "#else",
    "#define HULK_NATIVE_INLINE inline",
    "#endif",
    "#endif",
]
PRELUDE_USE = re.compile(r"\b(?:size_t|HULK_NEW_THROW|HULK_NATIVE_INLINE)\b")
SIZE_T_TYPEDEF = re.compile(r"\btypedef[ \t]+unsigned(?:[ \t]+int)?[ \t]+size_t[ \t]*;")
NEW_UNSIGNED = re.compile(r"\b(operator[ \t]*(?:new|delete)(?:[ \t]*\[[ \t]*\])?[ \t]*\([^()\n]*?)"
                          r"\bunsigned(?:[ \t]+int)?\b(?![ \t]*(?:long|short|char|__int64|int)\b)")
NEW_THROW = re.compile(r"\b(operator[ \t]*new(?:[ \t]*\[[ \t]*\])?[ \t]*\([ \t]*size_t(?:[ \t]+\w+)?[ \t]*\))"
                       r"[ \t]*throw[ \t]*\([ \t]*\)")


def native_spelling(text):
    """The tree's spelling of size_t and the global operator new (see PRELUDE). Line count unchanged."""
    text = SIZE_T_TYPEDEF.sub("/* size_t: tree_prelude.h */", text)
    while True:
        t = NEW_UNSIGNED.sub(r"\1size_t", text)
        if t == text:
            break
        text = t
    return NEW_THROW.sub(r"\1 HULK_NEW_THROW", text)


def generate(state=None, write=True):
    g = Generator(state)
    g.build()
    if write:
        g.manifest = g.write()
        conf = g.conflicts()
        with open(os.path.join(TREE, "conflicts.json"), "w") as f:
            json.dump(conf, f, indent=1)
        g.conflict_list = conf
    return g


def summary(g):
    modes = collections.Counter(b.mode for t in g.tus for b in t.blocks)
    kinds = collections.Counter((b.kind, b.mode) for t in g.tus for b in t.blocks)
    reasons = collections.Counter(re.sub(r"0x[0-9a-f]+|\d+", "N", r.split(":")[0]) for t in g.tus for b in t.blocks
                                  for r in b.reasons)
    files = len(g.tus)
    return {
        "tu_files": files,
        "objects": len({t.obj["file"] for t in g.tus}),
        "placeholder_only_files": sum(1 for t in g.tus if not t.blocks),
        "verified_functions": sum(modes.values()),
        "modes": dict(modes),
        "by_kind": {"%s/%s" % k: v for k, v in sorted(kinds.items())},
        "wrap_reasons": dict(reasons.most_common()),
        "placeholders": sum(len(t.placeholders) for t in g.tus),
        "headers": {h: len(v) for h, v in sorted(g.headers.items())} if hasattr(g, "headers") else {},
        "local_declarations": sum(len(t.local) for t in g.tus),
        "layers": {layer: {"tu_files": sum(1 for t in g.tus if layer_of(t.obj) == layer),
                           "functions": sum(len(t.blocks) + len(t.placeholders) for t in g.tus if layer_of(t.obj) == layer),
                           "verified": dict(collections.Counter(b.mode for t in g.tus if layer_of(t.obj) == layer
                                                                for b in t.blocks))}
                   for layer in sorted({layer_of(t.obj) for t in g.tus})},
        "stats": dict(g.stats),
    }


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--stats", action="store_true", help="print numbers, write nothing")
    ap.add_argument("--fresh", action="store_true", help="ignore build/tree/state.json (no fallbacks)")
    a = ap.parse_args(argv)
    state = {"wrap": {}, "isolate": {}, "local_only": set(), "iso_plain": {}} if a.fresh else None
    g = generate(state, write=not a.stats)
    s = summary(g)
    hs = s.pop("headers")
    print(json.dumps(s, indent=1))
    print("headers: %d, %d declarations" % (len(hs), sum(hs.values())))
    if not a.stats:
        print("conflicting symbols: %d" % len(g.conflict_list))
    return 0


if __name__ == "__main__":
    sys.exit(main())
