#!/usr/bin/env python3
"""Move matches/ and equivalent/ sources from their own `extern ... DAT_xxxxxxxx` declarations onto the shared data
declarations in include/decls/data/ (tools/data_gen.py), so the source tree has one declaration and one definition
per global (docs/data.md, "Wiring"). Re-runnable, logged, and every rewrite is verified before it is kept, like
tools/migrate_gen.py.

  build/venv/bin/python tools/migrate_data.py                         # plan + verify matches/ in a scratch dir
  build/venv/bin/python tools/migrate_data.py --apply                 # ... and rewrite what still verifies
  build/venv/bin/python tools/migrate_data.py --apply --equivalent    # also equivalent/ (equiv.py --inputs 3000)
  build/venv/bin/python tools/migrate_data.py --only matches/0x0004e980.cpp --show
  build/venv/bin/python tools/migrate_data.py --no-verify --show      # plan only, compile nothing

What a rewrite does, per source:

  * Every top-level declaration (or definition) of an address name `DAT_<addr>` whose address is a data item that
    tools/data_gen.py emits goes; the source includes `decls/data/<layer>/<dir>.h` (the item owner's header)
    instead. The symbol keeps its spelling: data items are named `DAT_<addr>` in the data TUs, which is what
    equiv.py binds by address. Declarations of other address names (vftables and RTTI, library data, FourCC
    constants, names pinned in include/decls/address.h) stay.
  * Where the source's type differs from the shared one (`extern char DAT_x;` for a 144-byte BSS item, a
    `float` the header declares `const float`, a source stub class), the source keeps its own access type with
    a cast at each use: `(*(T*)&DAT_x)`, `((T*)&DAT_x)` for `&DAT_x` and for arrays (`T DAT_x[]`).
  * An address inside an item (`DAT_y` = item x + k, docs/data.md "interior") becomes `(*(T*)((char*)&DAT_x + k))`.
  * A source that defines the global itself (`unsigned __int64 DAT_x;`) loses the definition: the data TU owns
    every item (docs/data.md, "Owners of a global").

Rules (`rule` in the log): data-decl (same type: the declaration just goes), data-cast, data-interior, data-def
(a definition), combined per source with `+`.

Refused (reported as skips): declarations inside a namespace, with an initializer, with several declarators or a
function-pointer declarator; a use that needs a cast but is `sizeof`, a member name (`p->DAT_x`), outside a
function body, or inside a preprocessor line; names on `// equiv-*` lines; a source that keeps another declaration
of a name the included headers declare; files whose address is listed in build/farm/bench/claude-equiv/
batch-{r9p,fx9p,fx9r,r10p,bigq}.txt (scheduled promotions); equivalent/ sources shadowed by a matches/ source.

A rewrite is kept only if it verifies: matches/ must MATCH under tools/compare.py, equivalent/ must be EQUIVALENT
under tools/equiv.py --inputs 3000 (when not, the unchanged source is run under the same checker and both lines
are logged). The source is re-read just before writing and skipped if it changed meanwhile (farm lanes and
promotions write matches/ and equivalent/ while this runs). Kept: the source, the text before its first rewrite
in build/data-orig/<path>, the path in build/data-migrated.txt, one JSON line in build/migrate-data.log.
"""
import argparse
import collections
import json
import os
import re
import shutil
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402
import data_gen  # noqa: E402
import subprocess  # noqa: E402
from concurrent.futures import as_completed  # noqa: E402
from migrate_gen import EQUIV_LINE, PY, compare_cli  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
LOG = os.path.join(ROOT, "build/migrate-data.log")
ORIG = os.path.join(ROOT, "build/data-orig")
CHANGED = os.path.join(ROOT, "build/data-migrated.txt")
SCRATCH = os.path.join(ROOT, "build/data-mig-scratch")
DECLS_DIR = os.path.join(ROOT, "include/decls/data")
EXCLUDE_LISTS = ["build/farm/bench/claude-equiv/batch-%s.txt" % b for b in ("r9p", "fx9p", "fx9r", "r10p", "bigq")]
ADDR = re.compile(r"DAT_([0-9a-fA-F]{8})")
TYPE_FIX = {"unsigned": "unsigned int", "signed": "int", "signed int": "int", "short int": "short",
            "unsigned short int": "unsigned short", "long int": "long", "unsigned long int": "unsigned long"}


class Fail(Exception):
    pass


def equiv_cli(path, addr, inputs, timeout):
    """tools/equiv.py's verdict ('equivalent', 'fail', ..., 'timeout') and its first output line."""
    try:
        r = subprocess.run([PY, os.path.join(ROOT, "tools/equiv.py"), path, "0x%08x" % addr, "--inputs", str(inputs)],
                           capture_output=True, text=True, cwd=ROOT, errors="replace", timeout=timeout)
    except subprocess.TimeoutExpired:
        return "timeout", "TIMEOUT equiv.py ran over %d s" % timeout
    out = (r.stdout or "") + (r.stderr or "")
    first = out.strip().splitlines()[0] if out.strip() else "(no output)"
    m = re.match(r"\s*(\w+)", first)
    return (m.group(1).lower() if m else "error"), first


# ---------------------------------------------------------------------------------------------
# the shared declarations
class Decl:
    __slots__ = ("name", "base", "dims", "header", "addr")

    def __init__(self, name, base, dims, header):
        self.name, self.base, self.dims, self.header = name, base, dims, header
        self.addr = int(name[4:], 16)


def split_decl(toks, name):
    """(base type tokens, [array dims]) of a one-declarator variable declaration `[extern ["C"]] [static] T NAME
    [N]...;`, or raises Fail."""
    vs = [t.v for t in toks]
    if vs.count(name) != 1:
        raise Fail("%s: not a single declarator" % name)
    i = vs.index(name)
    head = [v for v in vs[:i] if v not in ("extern", '"C"', "static")]
    tail = vs[i + 1:]
    if tail and tail[-1] == ";":
        tail = tail[:-1]
    if "(" in head or ")" in head or "," in head or not head:
        raise Fail("%s: declarator is not `T %s[...]`" % (name, name))
    if "=" in tail:
        raise Fail("%s: initializer" % name)
    dims = []
    k = 0
    while k < len(tail):
        if tail[k] == "[" and k + 1 < len(tail) and tail[k + 1] == "]":
            dims.append("")
            k += 2
        elif tail[k] == "[" and k + 2 < len(tail) and tail[k + 2] == "]" and re.fullmatch(r"\w+", tail[k + 1]):
            dims.append(tail[k + 1])
            k += 3
        else:
            raise Fail("%s: declarator is not `T %s[...]`" % (name, name))
    return head, dims


def declarators(toks):
    """(head tokens, [(stars, name, dims, first tok index, last tok index)]) of a variable declaration with one or
    more declarators (`extern int A, *B, C[4];`), or raises Fail. head excludes the pointer stars of the first
    declarator."""
    vs = [t.v for t in toks]
    if vs and vs[-1] == ";":
        vs = vs[:-1]
    segs, cur, depth = [], [], 0
    for k, v in enumerate(vs):
        if v in ("(", "[", "<", "{"):
            depth += 1
        elif v in (")", "]", ">", "}"):
            depth -= 1
        if v == "," and depth == 0:
            segs.append(cur)
            cur = []
            continue
        cur.append(k)
    segs.append(cur)

    def tail(idx):
        """(stars, name, dims) of a declarator `* * NAME [N] [M]` given its token indexes."""
        k = 0
        stars = []
        while k < len(idx) and vs[idx[k]] in ("*", "const"):
            stars.append(vs[idx[k]])
            k += 1
        if k >= len(idx) or toks[idx[k]].t != "id":
            raise Fail("declarator is not `T NAME[...]`")
        name = vs[idx[k]]
        dims = []
        k += 1
        while k < len(idx):
            if vs[idx[k]] == "[" and k + 1 < len(idx) and vs[idx[k + 1]] == "]":
                dims.append("")
                k += 2
            elif vs[idx[k]] == "[" and k + 2 < len(idx) and vs[idx[k + 2]] == "]" and re.fullmatch(r"\w+", vs[idx[k + 1]]):
                dims.append(vs[idx[k + 1]])
                k += 3
            elif vs[idx[k]] == "=":
                raise Fail("%s: initializer" % name)
            else:
                raise Fail("%s: declarator is not `T %s[...]`" % (name, name))
        return stars, name, dims

    first = segs[0]
    # the first declarator's name: the last identifier of the first segment that only array bounds follow
    j = len(first) - 1
    while j >= 0 and vs[first[j]] in ("]",) or (j >= 0 and re.fullmatch(r"\w*", vs[first[j]]) and j >= 1 and vs[first[j - 1]] == "["):
        j -= 1
        while j >= 0 and vs[first[j]] != "[":
            j -= 1
        j -= 1
    if j < 0 or toks[first[j]].t != "id":
        raise Fail("declarator is not `T NAME[...]`")
    s0 = j
    while s0 > 0 and vs[first[s0 - 1]] in ("*", "const") and not all(vs[first[x]] in ("extern", '"C"', "static", "const")
                                                                        for x in range(s0 - 1)):
        s0 -= 1
    head = [vs[first[x]] for x in range(s0) if vs[first[x]] not in ("extern", '"C"', "static")]
    if not head or any(v in ("(", ")") for v in head):
        raise Fail("declarator is not `T NAME[...]`")
    out = []
    for n, idx in enumerate(segs):
        part = idx[s0:] if n == 0 else idx
        st, name, dims = tail(part)
        out.append((st, name, dims, part[0], part[-1]))
    return head, out


def canon(head):
    """Spelling-independent type text: `unsigned` = `unsigned int`, `char const` = `const char`."""
    words = list(head)
    const = "const" in words
    words = [w for w in words if w != "const"]
    # pointer levels keep their own const (`char * const`): only a leading const is moved
    s = " ".join(words)
    m = re.match(r"([\w ]+?)\s*((?:\*\s*)*)$", s)
    if m:
        base = TYPE_FIX.get(m.group(1).strip(), m.group(1).strip())
        s = base + (" " + m.group(2).replace(" ", "") if m.group(2) else "")
    return ("const " if const else "") + s


def spell(head):
    """Source text of a type from its tokens (`const char *` -> `const char*`)."""
    s = " ".join(head)
    s = re.sub(r"\s*\*", "*", s)
    s = re.sub(r"\s*::\s*", "::", s)
    s = re.sub(r"\s*<\s*", "<", s)
    s = re.sub(r"\s*>", ">", s)
    return s


def load_decls():
    """name -> Decl for every declaration in include/decls/data/; header -> set of names it declares."""
    out, by_header = {}, collections.defaultdict(set)
    for dp, dns, fns in os.walk(DECLS_DIR):
        for fn in fns:
            if not fn.endswith(".h"):
                continue
            path = os.path.join(dp, fn)
            rel = os.path.relpath(path, os.path.join(ROOT, "include")).replace(os.sep, "/")
            for it in cxx_items.parse(open(path, encoding="latin1").read()):
                if it.kind in ("var",) and it.name:
                    head, dims = split_decl(it.toks, it.name)
                    out[it.name] = Decl(it.name, head, dims, rel)
                if it.name:
                    by_header[rel].add(it.name)
    return out, by_header


def excluded_addrs():
    out = set()
    for p in EXCLUDE_LISTS:
        try:
            for line in open(os.path.join(ROOT, p)):
                m = re.search(r"0x([0-9a-fA-F]{8})", line)
                if m:
                    out.add(int(m.group(1), 16))
        except OSError:
            pass
    return out


# ---------------------------------------------------------------------------------------------
PRE_OPERAND = {"(", "[", ",", "=", "return", "{", ";", "+", "-", "*", "/", "%", "!", "~", "&&", "||", "?", ":", "<",
               ">", "<=", ">=", "==", "!=", "+=", "-=", "*=", "/=", "|=", "&=", "^=", "<<", ">>", "|", "^", "&",
               "case", "throw", "delete", "<<=", ">>="}


def is_unary_amp(toks, j):
    """toks[j] is `&`: is it the address-of operator (not a binary and)?"""
    if j == 0:
        return True
    p = toks[j - 1]
    if p.t in ("id", "num", "str", "chr") and p.v not in cxx_items.KEYWORDS:
        return False
    if p.v in (")", "]"):
        return False
    return True


class Model:
    def __init__(self):
        self.dm = data_gen.Model()
        self.decls, self.by_header = load_decls()
        self.pins = data_gen.pinned_vars()

    def target(self, name):
        """(Decl of the item, offset) for an address name of an emitted, declared data item, else None."""
        a = int(name[4:], 16)
        it = self.dm.item_at(a)
        if it is None or not self.dm.emitted(it) or it["cname"] in self.pins or name in self.pins:
            return None
        d = self.decls.get(it["cname"])
        if d is None:
            return None
        return d, a - it["addr"]


def transform(model, rel, text):
    """(rules, new text, headers, per-name notes) or raises Fail."""
    try:
        items = cxx_items.parse(text)
        toks = cxx_items.tokenize(text)
    except ValueError:
        raise Fail("does not parse")
    equiv = "\n".join(m.group(1) for m in EQUIV_LINE.finditer(text))
    targets = []
    for it in items:
        if it.kind != "var" or not any(t.t == "id" and ADDR.fullmatch(t.v) and model.target(t.v) for t in it.toks):
            continue
        head, decs = declarators(it.toks)
        for st, nm, dims, a0, a1 in decs:
            t = model.target(nm) if ADDR.fullmatch(nm) else None
            if t is not None:
                targets.append((it, t, nm, head + st, dims, decs))
    if not targets:
        raise Fail("nothing to migrate")
    names = {}
    for it, (d, off), nm, head, dims, decs in targets:
        if nm in names:
            o = names[nm]
            if (canon(o["head"]), o["dims"]) != (canon(head), dims):
                raise Fail("%s declared twice, differently" % nm)
            o["items"].append(it)
            continue
        if it.scope:
            raise Fail("%s declared inside a namespace" % nm)
        if re.search(r"\b%s\b" % nm, equiv):
            raise Fail("%s named on an equiv-* line" % nm)
        vs = [t.v for t in it.toks]
        is_def = vs[0] != "extern" or "static" in vs
        same = off == 0 and canon(head) == canon(d.base) and len(dims) == len(d.dims) and \
            all(a == b or (k == 0 and a == "") for k, (a, b) in enumerate(zip(dims, d.dims)))
        rule = "data-interior" if off else "data-def" if is_def else "data-decl" if same else "data-cast"
        if is_def and not same:
            rule = "data-def+cast"
        names[nm] = dict(item=it, items=[it], decl=d, off=off, head=head, dims=dims, same=same, rule=rule)
    # preprocessor lines can't be rewritten token by token
    for t in toks:
        if t.t == "pp":
            for nm in names:
                if re.search(r"\b%s\b" % nm, t.v):
                    raise Fail("%s used in a preprocessor line" % nm)
    headers = sorted({n["decl"].header for n in names.values()})
    provided = set()
    for h in headers:
        provided |= model.by_header[h]
    touched = {id(x) for n in names.values() for x in n["items"]}
    for it in items:
        if it.kind == "pp":
            continue
        own = set()
        if id(it) in touched:
            own = {nm for nm in names}
        if it.kind in ("var", "func", "class", "fwd", "typedef", "enum", "funcdef"):
            declared = {it.name} if it.name else set()
            if it.kind == "var" and id(it) in touched:
                declared = {d[1] for d in declarators(it.toks)[1]}
            bad = (declared - own) & provided
            if bad:
                raise Fail("keeps a declaration of %s, which %s declares" % (
                    sorted(bad)[0], headers[0] if len(headers) == 1 else "an included header"))
    # spans of code: function definitions and class bodies (inline members); a use in a global's initializer
    # must not change (a cast there can make the initializer dynamic)
    bodies = [(it.toks[0].s, it.toks[-1].e) for it in items if it.kind in ("funcdef", "class")]
    decl_spans = [(x.toks[0].s, x.toks[-1].e) for x in {id(x): x for n in names.values() for x in n["items"]}.values()]
    edits = []
    for j, t in enumerate(toks):
        if t.t != "id" or t.v not in names:
            continue
        if any(s <= t.s < e for s, e in decl_spans):
            continue
        n = names[t.v]
        prev = toks[j - 1] if j else None
        if prev is not None and prev.v in (".", "->"):
            raise Fail("%s used as a member name" % t.v)
        start = t.s
        if prev is not None and prev.v == "::":
            if j >= 2 and toks[j - 2].t == "id" and toks[j - 2].v not in cxx_items.KEYWORDS:
                raise Fail("%s used qualified" % t.v)
            start = prev.s
            pj = j - 1
        else:
            pj = j
        if n["same"]:
            if start != t.s:
                edits.append((start, t.e, t.v))
            continue
        if not any(s <= t.s < e for s, e in bodies):
            raise Fail("%s needs a cast outside code (a global's initializer)" % t.v)
        if prev is not None and (prev.v == "sizeof" or (prev.v == "(" and j >= 2 and toks[j - 2].v == "sizeof")):
            raise Fail("sizeof %s" % t.v)
        d, off = n["decl"], n["off"]
        T = spell(n["head"])
        base = "&%s" % d.name if not off else "((char*)&%s + %d)" % (d.name, off)
        nxt = toks[j + 1].v if j + 1 < len(toks) else ""
        # `&DAT_x` takes the name's address; in `&DAT_x[i]`, `&DAT_x.f` the postfix operator binds first
        amp = pj >= 1 and toks[pj - 1].v == "&" and is_unary_amp(toks, pj - 1) and \
            nxt not in ("[", ".", "->", "(", "++", "--")
        dims = n["dims"]
        if not dims:
            rep = "((%s*)%s)" % (T, base) if amp else "(*(%s*)%s)" % (T, base)
        elif len(dims) == 1 and not amp:
            rep = "((%s*)%s)" % (T, base)
        else:
            D = "".join("[%s]" % x for x in dims)
            rep = "((%s(*)%s)%s)" % (T, D, base) if amp else "(*(%s(*)%s)%s)" % (T, D, base)
        if amp:
            start = toks[pj - 1].s
        edits.append((start, t.e, rep))
    # declarations go (the whole line when the declaration is alone on it); a declaration that also declares
    # names that stay keeps those declarators
    for it in {id(x): x for n in names.values() for x in n["items"]}.values():
        head, decs = declarators(it.toks)
        keep = [d for d in decs if d[1] not in names]
        s0, e0 = it.toks[0].s, it.toks[-1].e
        if keep:
            t0 = it.toks
            first_decl = decs[0][3]
            rest = ", ".join(text[t0[d[3]].s:t0[d[4]].e] for d in keep)
            if keep[0] is decs[0]:
                new_decl = text[s0:t0[decs[0][4]].e] + "".join(", " + text[t0[d[3]].s:t0[d[4]].e] for d in keep[1:]) + ";"
            else:
                # the first declarator goes: the head stays, with its pointer stars dropped from the text
                new_decl = text[s0:t0[first_decl].s].rstrip() + " " + rest + ";"
                if decs[0][0]:
                    raise Fail("first declarator has its own pointer stars")
            edits.append((s0, e0, new_decl))
            continue
        ls = text.rfind("\n", 0, s0) + 1
        le = text.find("\n", e0)
        le = len(text) if le < 0 else le + 1
        if text[ls:s0].strip() == "" and text[e0:le].strip() == "":
            s0, e0 = ls, le
        edits.append((s0, e0, ""))
    edits.sort(key=lambda e: (e[0], e[1]))
    out, cur = [], 0
    for s0, e0, nt in edits:
        if s0 < cur:
            raise Fail("overlapping edits")
        out.append(text[cur:s0])
        out.append(nt)
        cur = e0
    out.append(text[cur:])
    new = "".join(out)
    new = insert_includes(new, headers)
    rules = "+".join(sorted({n["rule"] for n in names.values()}))
    notes = {nm: (n["rule"] + ("@+%d" % n["off"] if n["off"] else "")) for nm, n in sorted(names.items())}
    return rules, new, headers, notes


def insert_includes(text, headers):
    """`#include "decls/data/..."` lines after the leading comment block and any gen/ or decls/ includes."""
    nl = "\r\n" if "\r\n" in text else "\n"
    lines = text.split(nl)
    have = {m.group(1) for m in re.finditer(r'#\s*include\s*"([^"]+)"', text)}
    add = ['#include "%s"' % h for h in headers if h not in have]
    if not add:
        return text
    i = 0
    while i < len(lines) and (lines[i].strip().startswith("//") or not lines[i].strip()
                              or re.match(r'\s*#\s*include\s*"(gen|decls)/', lines[i])):
        i += 1
    while i > 0 and not lines[i - 1].strip():
        i -= 1
    # a blank line between the includes and the code when the source had none there
    tail = lines[i:]
    if tail and tail[0].strip() and not any(re.match(r'\s*#\s*include', l) for l in lines[:i][-1:]):
        add = add + [""]
    return nl.join(lines[:i] + add + tail)


# ---------------------------------------------------------------------------------------------
def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--apply", action="store_true", help="rewrite the sources that still verify")
    ap.add_argument("--only", nargs="*", help="limit to these source paths")
    ap.add_argument("--equivalent", action="store_true", help="also equivalent/ sources (checked with equiv.py)")
    ap.add_argument("--equivalent-only", action="store_true", help="only equivalent/ sources")
    ap.add_argument("--equiv-inputs", type=int, default=3000)
    ap.add_argument("--equiv-timeout", type=int, default=1800, help="seconds per equiv.py run (a timeout rejects)")
    ap.add_argument("--limit", type=int)
    ap.add_argument("--jobs", type=int, default=4, help="compiler/checker processes (default 4; shared box)")
    ap.add_argument("--show", action="store_true", help="print the rewritten text")
    ap.add_argument("--no-verify", action="store_true", help="plan only: rewrite into the scratch dir, compile nothing")
    a = ap.parse_args(argv)
    model = Model()
    excl = excluded_addrs()
    dirs = ("equivalent",) if a.equivalent_only else ("matches", "equivalent") if a.equivalent else ("matches",)
    in_matches = {int(f[2:10], 16) for f in os.listdir(os.path.join(ROOT, "matches")) if f.endswith(".cpp")}
    todo, skipped = [], collections.Counter()
    for d in dirs:
        for fn in sorted(os.listdir(os.path.join(ROOT, d))):
            if not re.fullmatch(r"0x[0-9a-fA-F]{8}\.cpp", fn):
                continue
            rel = "%s/%s" % (d, fn)
            if a.only and rel not in a.only:
                continue
            addr = int(fn[2:10], 16)
            if d == "equivalent" and addr in in_matches:
                skipped["equivalent/ shadowed by matches/"] += 1
                continue
            text = open(os.path.join(ROOT, rel), encoding="latin1", newline="").read()
            if "DAT_" not in text:
                continue
            if addr in excl:
                skipped["scheduled promotion/replacement (batch list)"] += 1
                continue
            todo.append((rel, addr, text))
    os.makedirs(SCRATCH, exist_ok=True)
    work = tempfile.mkdtemp(prefix="mig-", dir=SCRATCH)

    def plan_one(item):
        rel, addr, text = item
        try:
            rules, new, hdrs, notes = transform(model, rel, text)
        except Fail as e:
            return rel, addr, None, str(e)
        except Exception as e:  # noqa: BLE001 - one odd source must not stop the run
            return rel, addr, None, "rewrite crash: %s %s" % (type(e).__name__, str(e)[:60])
        sub = os.path.join(work, os.path.dirname(rel))
        os.makedirs(sub, exist_ok=True)
        p = os.path.join(sub, os.path.basename(rel))
        with open(p, "w", encoding="latin1", newline="") as f:
            f.write(new)
        return rel, addr, (rules, new, hdrs, notes, p), None

    planned = [plan_one(t) for t in (todo[:a.limit] if a.limit else todo)]
    for rel, addr, ok, why in planned:
        if why:
            skipped[re.sub(r"DAT_[0-9a-f]{8}|\b\d+\b", "N", why)[:90]] += 1
    cands = [(rel, addr, ok) for rel, addr, ok, why in planned if ok]
    by_rule = collections.Counter((rel.split("/")[0], ok[0]) for rel, addr, ok in cands)
    print("candidates: %d rewritten in %s (%d sources looked at)" % (len(cands), os.path.relpath(work, ROOT), len(todo)))
    for k, v in sorted(by_rule.items()):
        print("  %-11s %-40s %d" % (k[0], k[1], v))

    def verify_one(c):
        rel, addr, (rules, new, hdrs, notes, p) = c
        if rel.startswith("matches/"):
            line = compare_cli(p, addr)
            return c, line.startswith("MATCH"), line, None
        v_new, l_new = equiv_cli(p, addr, a.equiv_inputs, a.equiv_timeout)
        if v_new == "timeout":
            return c, False, l_new, None
        if v_new != "equivalent":
            v_old, l_old = equiv_cli(os.path.join(ROOT, rel), addr, a.equiv_inputs, a.equiv_timeout)
            return c, False, l_new, "original: " + l_old
        return c, True, l_new, None

    if a.no_verify:
        print("skipped:")
        for why, n in skipped.most_common(30):
            print("  %6d  %s" % (n, why))
        for rel, addr, (rules, new, hdrs, notes, p) in cands[:10] if a.show else []:
            print("==== %s (%s) %s\n%s" % (rel, rules, notes, new))
        return 0
    results = []
    orig_text = {r: t for r, _, t in todo}
    log_f = open(LOG, "a") if a.apply else None
    ch_f = open(CHANGED, "a") if a.apply else None
    n_written = 0
    st = collections.Counter()

    def keep(c, line):
        nonlocal n_written
        rel, addr, (rules, new, hdrs, notes, p) = c
        src = os.path.join(ROOT, rel)
        cur = open(src, encoding="latin1", newline="").read() if os.path.exists(src) else None
        if cur != orig_text[rel]:
            print("changed meanwhile, skipped:", rel, flush=True)
            st["changed meanwhile"] += 1
            return
        if addr in excluded_addrs():
            print("now on a batch list, skipped:", rel, flush=True)
            st["now on a batch list"] += 1
            return
        k = os.path.join(ORIG, rel)
        if not os.path.exists(k):
            os.makedirs(os.path.dirname(k), exist_ok=True)
            shutil.copyfile(src, k)
        with open(src, "w", encoding="latin1", newline="") as f:
            f.write(new)
        log_f.write(json.dumps({"file": rel, "rule": rules, "headers": hdrs, "names": notes, "verified": line}) + "\n")
        log_f.flush()
        ch_f.write(rel + "\n")
        ch_f.flush()
        n_written += 1

    with ThreadPoolExecutor(a.jobs) as ex:
        # kept as they finish (a slow equiv.py run must not hold back the others' writes)
        # smaller sources first: equiv.py time grows with the function, and a run that is stopped keeps the most
        for fut in as_completed([ex.submit(verify_one, c) for c in sorted(cands, key=lambda c: len(orig_text[c[0]]))]):
            c, ok, line, extra = fut.result()
            results.append((c, ok, line, extra))
            with open(os.path.join(work, "results.jsonl"), "a") as rf:
                rf.write(json.dumps({"file": c[0], "rule": c[2][0], "ok": ok, "line": line, "original": extra}) + "\n")
            st[(c[0].split("/")[0], c[2][0], "kept" if ok else "rejected: " + re.sub(r"\s.*", "", line)[:20])] += 1
            if ok and a.apply:
                keep(c, line)
            if len(results) % 50 == 0:
                print("  verified %d / %d" % (len(results), len(cands)), flush=True)
    for k, v in sorted(st.items(), key=str):
        print("  %-60s %d" % (k, v))
    print("skipped:")
    for why, n in skipped.most_common(30):
        print("  %6d  %s" % (n, why))
    with open(os.path.join(work, "results.json"), "w") as f:
        json.dump([{"file": c[0], "rule": c[2][0], "names": c[2][3], "ok": ok, "line": line, "original": extra}
                   for c, ok, line, extra in results], f, indent=1)
    if a.show:
        for (rel, addr, (rules, new, hdrs, notes, p)), ok, line, _ in results[:20]:
            print("==== %s (%s) %s %s\n%s" % (rel, rules, notes, line, new))
    if a.apply:
        print("rewrote %d sources (log: %s, list: %s, originals: %s)" % (
            n_written, os.path.relpath(LOG, ROOT), os.path.relpath(CHANGED, ROOT), os.path.relpath(ORIG, ROOT)))
    print("results:", os.path.relpath(os.path.join(work, "results.json"), ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
