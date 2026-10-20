#!/usr/bin/env python3
"""Rename map: the game's real class for the stub classes in matches/ and equivalent/ (docs/consolidation-plan.md).

Read-only on the sources. Writes build/rn1/rename-map.json (one entry per stub class name and source) and
build/rn1/rename-map-summary.txt.

  build/venv/bin/python tools/rn_map.py                     # map + summary
  build/venv/bin/python tools/rn_map.py --show Obj_2d5ec0   # one stub's evidence
  build/venv/bin/python tools/rn_map.py --bindings build/native/bindings.json --out build/rn1

A stub is a class or struct a source defines itself that is not an include/gen/ class: placeholder-suffixed names
(`Obj_2d5ec0`), invented names (`Action`, `Node`) and global stubs of RTTI class names. Evidence, strongest first:

  self-vfunc   the source's own function is `S::m` and build/functions.csv names its address `X::vfunc_N` (a slot of
               RTTI class X's vftable): S is X.                                                           (high)
  self-vptr    the source's own function is a member of S and the original stores vftable pointers at [reg+0]:
               the most derived of the stored classes (one inheritance chain) is S (constructor, destructor or
               an inlined one of them).                                                                     (high)
  vftable      S's own `??_7S@...` vftable symbol is bound (tools/native_link.py, by relocation position) to the
               game's vftable of X.                                                                         (high)
  call         a member function `S::m` the source calls is bound to address A, and A's owner is X (one of the
               above for A's own source): S is X or derives from X. When X has no derived classes in RTTI that
               is X (medium), otherwise only the lower bound is recorded.
  base         S's base class B in the source, when S is X: B is X's base at offset 0 (RTTI).               (medium)

Conflicting evidence (two classes not on one inheritance chain) is reported, with confidence low. The binding map
(build/native/bindings.json) is from the last strict native link; its symbol names carry each source's tree
namespace (`fn_<addr>` for a wrapped source, `fn_f<hash>` for a TU), which is how a symbol is tied to its source.
"""
import argparse
import bisect
import collections
import csv
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SRC_DIRS = ("matches", "equivalent")
SUFFIXED = re.compile(r"^(\w+?)_([0-9a-f]{3,8})$")
MEMBER_CODES = set("ABEFIJMNQRUV")     # non-static member functions (after the scope's @@)
VIRTUAL_CODES = set("EFMNUV")


# ---------------------------------------------------------------------------------------------
# MSVC symbol: the qualified name only
def parse_symbol(sym):
    """(kind, name, qualifiers innermost first, code) for an MSVC-mangled name, or None.
    kind: 'ctor', 'dtor', 'sdtor', 'vftable', 'fn' (member or free function), 'data', 'special'."""
    if not sym.startswith("?"):
        return None
    if sym.startswith("??_7"):
        kind, rest, name = "vftable", sym[4:], None
    elif sym.startswith("??_G") or sym.startswith("??_E"):
        kind, rest, name = "sdtor", sym[4:], None
    elif sym.startswith("??0"):
        kind, rest, name = "ctor", sym[3:], None
    elif sym.startswith("??1"):
        kind, rest, name = "dtor", sym[3:], None
    elif sym.startswith("??"):
        return None
    else:
        if sym.startswith("?$"):
            return None
        i = sym.find("@", 1)
        if i < 0:
            return None
        kind, name, rest = "fn", sym[1:i], sym[i + 1:]
    quals = []
    names = [name] if name else []
    i = 0
    while True:
        if i >= len(rest):
            return None
        if rest[i] == "@":
            i += 1
            break
        if rest.startswith("?$", i):
            return None          # template names: not handled
        if rest[i].isdigit():
            k = int(rest[i])
            if k >= len(names):
                return None
            quals.append(names[k])
            i += 1
            continue
        j = rest.find("@", i)
        if j < 0:
            return None
        q = rest[i:j]
        quals.append(q)
        names.append(q)
        i = j + 1
    code = rest[i:i + 1]
    if kind == "fn":
        if code in ("2", "3", "4"):
            kind = "data"
        elif code not in MEMBER_CODES and code not in ("Y", "Z", "S", "T", "C", "D", "K", "L"):
            return None
    return kind, name, quals, code


def split_quals(quals):
    """(scope path without the tree namespace, tree namespace or None). quals innermost first."""
    tns = None
    rest = []
    for q in quals:
        if re.fullmatch(r"fn_[0-9a-f]{8}", q):
            tns = q
        else:
            rest.append(q)
    return rest, tns


# ---------------------------------------------------------------------------------------------
class RTTI:
    def __init__(self):
        rt = json.load(open(os.path.join(ROOT, "build/rtti.json")))
        self.by_mangled = {c["mangled"]: c for c in rt["classes"]}
        self.names = {c["name"] for c in rt["classes"] if c.get("name")}
        self.bases = {}            # name -> [(base name, mdisp)] all bases (flattened)
        self.first_base = {}       # name -> direct base at offset 0 (the primary base)
        for c in rt["classes"]:
            n = c.get("name")
            if not n:
                continue
            bl = []
            for b in c["bases"]:                # flattened, pre-order; the class itself is not listed
                bn = self.by_mangled.get(b["name"], {}).get("name")
                if bn:
                    bl.append((bn, b["mdisp"]))
            self.bases[n] = bl
            if c["bases"]:
                b = c["bases"][0]
                bn = self.by_mangled.get(b["name"], {}).get("name")
                if bn and b["mdisp"] == 0:
                    self.first_base[n] = bn
        self.derived = collections.defaultdict(set)
        for n, bl in self.bases.items():
            for b, _ in bl:
                self.derived[b].add(n)
        self.short = collections.defaultdict(set)    # simple name -> qualified names
        for n in self.names:
            s = re.sub(r"<.*", "", n).split("::")[-1]
            self.short[s].add(n)

    def is_base(self, b, d):
        return b == d or any(x == b for x, _ in self.bases.get(d, ()))

    def chain_top(self, classes):
        """The most derived of `classes` if they lie on one inheritance chain, else None."""
        cs = set(classes)
        for c in cs:
            if all(self.is_base(o, c) for o in cs):
                return c
        return None


def csv_to_rtti_name(n):
    """functions.csv class part -> rtti.json name (they use the same spelling apart from template spacing)."""
    return n


def load_funcs():
    out = {}
    with open(os.path.join(ROOT, "build/functions.csv")) as f:
        for r in csv.DictReader(f):
            out[int(r["address"], 16)] = (int(r["size"]), r["name"])
    return out


def load_sources():
    out = {}
    for d in SRC_DIRS:
        for fn in sorted(os.listdir(os.path.join(ROOT, d))):
            m = re.fullmatch(r"0x([0-9a-fA-F]{8})\.cpp", fn)
            if not m:
                continue
            a = int(m.group(1), 16)
            if a in out:
                continue
            out[a] = "%s/%s" % (d, fn)
    return out


def gen_classes():
    """Qualified names of the classes include/gen/ declares (class definitions and forward declarations of
    template families), from the headers' `// .?AV...` comments and class heads."""
    names = set()
    gdir = os.path.join(ROOT, "include/gen")
    for fn in os.listdir(gdir):
        if not fn.endswith(".h"):
            continue
        for m in re.finditer(r"^// (\.\?A[VUT][^\s]+)", open(os.path.join(gdir, fn), encoding="latin1").read(), re.M):
            names.add(m.group(1))
    return names


class VtableIndex:
    def __init__(self, rtti):
        d = json.load(open(os.path.join(ROOT, "config/data.json")))
        self.by_addr = {}
        self.refs_of = collections.defaultdict(set)      # function addr -> vtable addrs
        for it in d["items"]:
            if it["kind"] != "vtable" or not it.get("cls"):
                continue
            a = int(it["addr"], 16)
            self.by_addr[a] = it["cls"]
            for x in it.get("interior", []):
                self.by_addr[int(x, 16)] = it["cls"]
            for x in it.get("xrefs", []):
                self.refs_of[int(x, 16)].add(a)
        self.rtti = rtti
        self._xbe = None
        self._md = None

    def vptr_stores(self, addr, size):
        """[(disp, class)] of `mov dword [reg+disp], imm` with imm a vftable address and reg holding `this`
        (ecx on entry, followed through register moves in code order; branches are ignored), in code order.
        Stores through other registers (a `new X` built inline by a factory) don't count."""
        if not self.refs_of.get(addr):
            return []
        if self._xbe is None:
            import capstone
            from xbe import Xbe
            self._xbe = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
            self._md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
            self._md.detail = True
        o = self._xbe.offset(addr)
        if o is None:
            return []
        code = self._xbe.data[o:o + size]
        out = []
        import capstone.x86 as X
        this = {X.X86_REG_ECX}
        for ins in self._md.disasm(code, addr):
            ops = ins.operands
            if ins.mnemonic == "mov" and len(ops) == 2:
                dst, src = ops
                if dst.type == X.X86_OP_MEM and src.type == X.X86_OP_IMM and dst.size == 4:
                    imm = src.imm & 0xffffffff
                    if imm in self.by_addr and dst.mem.index == 0 and dst.mem.base in this:
                        out.append((dst.mem.disp, self.by_addr[imm]))
                    continue
                if dst.type == X.X86_OP_REG and src.type == X.X86_OP_REG:
                    if src.reg in this:
                        this.add(dst.reg)
                    else:
                        this.discard(dst.reg)
                    continue
            try:
                _, written = ins.regs_access()
            except Exception:  # noqa: BLE001
                written = []
            for r in written:
                this.discard(r)
            if ins.mnemonic == "call":
                this -= {X.X86_REG_EAX, X.X86_REG_ECX, X.X86_REG_EDX}
        return out


# ---------------------------------------------------------------------------------------------
class Mapper:
    def __init__(self, bindings_path):
        self.funcs = load_funcs()
        self.sources = load_sources()
        self.rtti = RTTI()
        self.vt = VtableIndex(self.rtti)
        self.gen_mangled = gen_classes()
        self.gen_names = {self.rtti.by_mangled[m]["name"] for m in self.gen_mangled if m in self.rtti.by_mangled}
        b = json.load(open(bindings_path))
        self.bindings = b["bindings"]
        self.definitions = {int(k, 16): v for k, v in b["definitions"].items()}
        self.splits = json.load(open(os.path.join(ROOT, "config/splits.json")))["objects"]
        self._starts = [int(o["start"], 16) for o in self.splits]

    def object_of(self, addr):
        i = bisect.bisect_right(self._starts, addr) - 1
        if i < 0:
            return None
        o = self.splits[i]
        return o["file"] if addr < int(o["end"], 16) else None

    # -- owners of addresses ------------------------------------------------------------------
    def owner(self, addr):
        """(class, how) for the code at addr, or (None, None)."""
        if addr in self._owner:
            return self._owner[addr]
        r = (None, None)
        size, name = self.funcs.get(addr, (0, ""))
        m = re.match(r"(.*)::vfunc_(\d+)(?:_adj\d+)?$", name)
        if m and csv_to_rtti_name(m.group(1)) in self.rtti.names and not m.group(0).count("_adj"):
            r = (m.group(1), "self-vfunc")
        elif size:
            st = [c for d, c in self.vt.vptr_stores(addr, size) if d == 0]
            if st:
                top = self.rtti.chain_top(st)
                if top is not None:
                    r = (top, "self-vptr")
                else:
                    r = ("?" + "|".join(sorted(set(st))), "self-vptr-conflict")
        self._owner[addr] = r
        return r

    # -- the per-source namespace from the binding map ------------------------------------------
    def tree_ns(self, addr):
        s = self.definitions.get(addr)
        if not s:
            return None
        p = parse_symbol(s)
        if not p:
            return None
        return split_quals(p[2])[1]

    def run(self):
        self._owner = {}
        # symbols by (class path, tree ns)
        by_cls = collections.defaultdict(list)
        for sym, info in self.bindings.items():
            p = parse_symbol(sym)
            if not p:
                continue
            kind, name, quals, code = p
            if kind == "fn" and code not in MEMBER_CODES:
                continue
            if kind == "data":
                continue
            rest, tns = split_quals(quals)
            if not rest:
                continue
            cls = "::".join(reversed(rest))
            a = int(info["addr"], 16)
            by_cls[(cls, tns)].append((kind, name, a, code in VIRTUAL_CODES, info.get("def")))
        self.by_cls = by_cls
        # stubs per source, with their static evidence and their calls
        entries = {}
        self.def_entry = collections.defaultdict(list)     # address -> entries whose source defines it as a member
        for addr, rel in sorted(self.sources.items()):
            text = open(os.path.join(ROOT, rel), encoding="latin1").read()
            try:
                items = cxx_items.parse(text)
            except ValueError:
                continue
            classes = [it for it in items if it.kind == "class" and it.name]
            if not classes:
                continue
            tns = self.tree_ns(addr)
            defs = [it for it in items if it.kind == "funcdef" and not it.is_inline]
            own_defs = {}
            for d in defs:
                q = d.key[1]
                if "::" in q:
                    c, m = q.rsplit("::", 1)
                    own_defs.setdefault(c, []).append(m)
            for it in classes:
                qn = it.key[1]          # already qualified by its namespaces
                own = qn in own_defs or it.key[1] in own_defs
                e = entries.setdefault((qn, rel), {
                    "stub": qn, "source": rel, "addr": "0x%08x" % addr, "kind": self.stub_kind(qn, addr),
                    "own": own, "poly": any(t.v == "virtual" for t in it.toks),
                    "bases": self.class_bases(it), "static": [], "calls": []})
                if own:
                    self.def_entry[addr].append(e)
                    o, how = self.owner(addr)
                    if o and not o.startswith("?"):
                        e["static"].append({"how": how, "cls": o, "rel": "=", "at": "0x%08x" % addr, "strong": True})
                    elif o:
                        e["static"].append({"how": how, "cls": o, "rel": "?", "at": "0x%08x" % addr})
                for kind, name, a, virt, dsym in by_cls.get((qn, tns), ()):
                    if kind == "vftable":
                        c = self.vt.by_addr.get(a)
                        if c:
                            e["static"].append({"how": "vftable", "cls": c, "rel": "=", "at": "0x%08x" % a,
                                                "strong": True})
                        continue
                    if a != addr:
                        e["calls"].append((a, name or kind))
        self.entries = entries
        by_src = collections.defaultdict(dict)
        for (qn, rel), e in entries.items():
            by_src[rel][qn] = e
        # fixpoint: owners of addresses from the stubs that define them; callers below, definers above
        derived_owner = {}
        # evidence only grows (owners of addresses and propagated items are never withdrawn), so this ends
        for e in entries.values():
            e["prop"] = {}
        for rnd in range(20):
            for e in entries.values():
                ev = list(e["static"])
                for a, member in e["calls"]:
                    o, how = self.owner(a)
                    if (not o or o.startswith("?")) and a in derived_owner:
                        o, how = derived_owner[a]
                    if o and not o.startswith("?"):
                        ev.append({"how": "call", "via": how, "cls": o, "rel": "<=", "at": "0x%08x" % a,
                                   "member": member, "strong": how in ("self-vfunc", "self-vptr", "def-high")})
                e["evidence"] = ev + list(e["prop"].values())
            if rnd:
                # a stub known to be X calls member A: A's defining stub is X or one of X's bases
                for e in entries.values():
                    if e.get("real") and e["confidence"] == "high" and e.get("eq"):
                        for a, member in e["calls"]:
                            for d in self.def_entry.get(a, ()):
                                k = ("called-as", e["real"], e["addr"])
                                if d is not e and k not in d["prop"]:
                                    d["prop"][k] = {"how": "called-as", "cls": e["real"], "rel": ">=",
                                                    "at": e["addr"], "member": member, "strong": False}
                # a stub's base in the source, when the stub is X: X's primary base
                for rel, es in by_src.items():
                    for qn, e in es.items():
                        if e.get("real") and e["confidence"] in ("high", "medium") and e.get("eq") and e["bases"]:
                            rb = self.rtti.first_base.get(e["real"])
                            b0 = e["bases"][0]
                            k = ("base", rb, qn)
                            if rb and b0 in es and k not in es[b0]["prop"]:
                                es[b0]["prop"][k] = {"how": "base", "cls": rb, "rel": "=", "at": e["addr"], "of": qn,
                                                     "strong": e["confidence"] == "high"}
                for e in entries.values():
                    e["evidence"] = [x for x in e["evidence"] if x["how"] not in ("called-as", "base")] + \
                        list(e["prop"].values())
            changed = 0
            for e in entries.values():
                before = (e.get("real"), e.get("confidence"))
                self.decide(e)
                changed += before != (e.get("real"), e.get("confidence"))
            added = 0
            for a, es in self.def_entry.items():
                if a in derived_owner:
                    continue
                rs = {(e["real"], e["confidence"]) for e in es if e.get("real") and e.get("eq")
                      and e["confidence"] in ("high", "medium")}
                if len({r for r, _ in rs}) == 1:
                    derived_owner[a] = (next(iter(rs))[0], "def-" + ("high" if any(c == "high" for _, c in rs) else "medium"))
                    added += 1
            self.rounds = rnd + 1
            print("round %d: %d changed, %d owners added" % (rnd + 1, changed, added), file=sys.stderr)
            if not changed and not added and rnd:
                break
        for e in entries.values():
            e.pop("static", None)
            e.pop("prop", None)
            e["calls"] = len(e["calls"])
        return entries
    def is_gen_class(self, qn):
        return False      # sources define stubs only; a global stub of an RTTI name is kind rtti-named

    def stub_kind(self, qn, addr):
        simple = qn.split("::")[-1]
        m = SUFFIXED.match(simple)
        if m:
            return "suffixed"
        if qn in self.rtti.names:
            return "rtti-named"
        if simple in self.rtti.short:
            return "rtti-short"
        return "invented"

    @staticmethod
    def class_bases(it):
        vs = [t.v for t in it.toks]
        if "{" not in vs:
            return []
        head = vs[:vs.index("{")]
        if ":" not in head:
            return []
        tail = head[head.index(":") + 1:]
        out, cur = [], []
        for v in tail + [","]:
            if v == ",":
                nm = [x for x in cur if x not in ("public", "private", "protected", "virtual")]
                if nm:
                    out.append("".join(nm))
                cur = []
            else:
                cur.append(v)
        return out

    def decide(self, e):
        """Confidence: high = only direct evidence on the class itself ('=' from its own vfunc slot, its vptr
        stores or its vftable symbol) and nothing against it; medium = one step from such evidence (the base of a
        high stub, or every call bound to a leaf class's members, or two callers that agree, or the class its
        object is named after among those that fit); low = a bound or conflicting evidence."""
        ev = e["evidence"]
        eq = collections.Counter(x["cls"] for x in ev if x["rel"] == "=")
        eq_strong = {x["cls"] for x in ev if x["rel"] == "=" and x.get("strong") and x["how"] != "base"}
        eq_base = {x["cls"] for x in ev if x["rel"] == "=" and x.get("strong") and x["how"] == "base"}
        le = collections.Counter(x["cls"] for x in ev if x["rel"] == "<=")
        le_strong = {x["cls"] for x in ev if x["rel"] == "<=" and x.get("strong")}
        ge = collections.Counter(x["cls"] for x in ev if x["rel"] == ">=")
        real, conf, note, is_eq = None, None, None, False
        obj = self.object_of(int(e["addr"], 16)) or ""
        stem = os.path.splitext(os.path.basename(obj))[0]
        if eq:
            top = self.rtti.chain_top(eq)
            is_eq = True
            if top is not None and len(eq) == 1:
                real = top
                conf = "high" if top in eq_strong else "medium" if top in eq_base else "low"
            elif top is not None:
                real, conf, note = top, ("medium" if top in eq_strong else "low"), \
                    "several '=' classes on one chain (%s): the most derived" % ", ".join(sorted(eq))
            else:
                real, conf, note = max(eq, key=eq.get), "low", "conflicting '=' classes: %s" % ", ".join(sorted(eq))
            bad = [c for c in le if not self.rtti.is_base(c, real)] + [c for c in ge if not self.rtti.is_base(real, c)]
            if bad and conf != "low":
                conf, note = "low", "other evidence names %s, not on %s's chain" % (", ".join(sorted(set(bad))), real)
        elif le or ge:
            # S <= each of le (S is it or derived), S >= each of ge (S is it or one of its bases)
            cands = None
            for c in le:
                cs = {c} | self.all_derived(c)
                cands = cs if cands is None else cands & cs
            for c in ge:
                cs = {c} | {b for b, _ in self.rtti.bases.get(c, ())}
                cands = cs if cands is None else cands & cs
            if not cands:
                conf, note = "none", "no class fits every call: %s" % ", ".join(sorted(set(le) | set(ge)))
            elif len(cands) == 1:
                real, is_eq = next(iter(cands)), True
                strong = (real in le_strong) or len(ge) >= 2 or (stem and re.sub(r"<.*", "", real).split("::")[-1] == stem)
                conf = "medium" if strong else "low"
                note = "the only class that fits every call" + ("" if strong else " (weak: one caller, or owners inferred)")
            else:
                short = {c for c in cands if re.sub(r"<.*", "", c).split("::")[-1] == stem}
                if len(short) == 1:
                    real, conf, is_eq = next(iter(short)), "medium", True
                    note = "one of %d classes that fit the calls; the one its object (%s) is named after" % (len(cands), obj)
                else:
                    top = self.rtti.chain_top(set(le)) if le else None
                    real, conf = (top or max(ge, key=ge.get)), "low"
                    note = "bound only: %d classes fit the calls" % len(cands)
        e["real"] = real
        e["confidence"] = conf or "none"
        e["eq"] = is_eq
        if note:
            e["note"] = note
        else:
            e.pop("note", None)
        e["real_on_gen"] = bool(real) and self.on_gen(real)

    def all_derived(self, c):
        return self.rtti.derived.get(c, set())

    def on_gen(self, name):
        return name in self.gen_names


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--bindings", default=os.path.join(ROOT, "build/native/bindings.json"))
    ap.add_argument("--out", default=os.path.join(ROOT, "build/rn1"))
    ap.add_argument("--show", nargs="*")
    a = ap.parse_args(argv)
    M = Mapper(a.bindings)
    entries = M.run()
    if a.show:
        for e in entries.values():
            if e["stub"] in a.show or e["source"] in a.show:
                print(json.dumps(e, indent=1))
        return 0
    os.makedirs(a.out, exist_ok=True)
    rows = sorted(entries.values(), key=lambda e: (e["source"], e["stub"]))
    # the sources a rename touches: its own, plus every other source that spells the same suffixed name (a copied
    # stub keeps its name while it stays identical; tools/rename_placeholders.py)
    want = {e["stub"].split("::")[-1] for e in rows if e["real"] and e["kind"] == "suffixed"}
    spelled = collections.defaultdict(set)
    for addr, rel in M.sources.items():
        text = open(os.path.join(ROOT, rel), encoding="latin1").read()
        for nm in set(re.findall(r"\b\w+_[0-9a-f]{3,8}\b", text)) & want:
            spelled[nm].add(rel)
    for e in rows:
        t = {e["source"]}
        if e["kind"] == "suffixed" and e["real"]:
            t |= spelled.get(e["stub"].split("::")[-1], set())
        e["touches"] = sorted(t)
    tsv = ["stub\tsource\treal\tconfidence\ton_include_gen\tevidence\tnote\ttouches"]
    for e in rows:
        if not e["real"]:
            continue
        ev = ", ".join(sorted({"%s %s %s" % (x["how"], x["rel"], x["cls"]) for x in e["evidence"]}))
        tsv.append("\t".join([e["stub"], e["source"], e["real"], e["confidence"], "yes" if e["real_on_gen"] else "no",
                              ev, e.get("note", ""), " ".join(e["touches"])]))
    open(os.path.join(a.out, "rename-map.tsv"), "w").write("\n".join(tsv) + "\n")
    with open(os.path.join(a.out, "rename-map.json"), "w") as f:
        json.dump({"comment": "tools/rn_map.py: real class per stub class (docs/consolidation-plan.md)",
                   "bindings": os.path.relpath(a.bindings, ROOT), "entries": rows}, f, indent=0)
    c = collections.Counter((e["kind"], e["confidence"]) for e in rows)
    lines = ["stub classes (name, source): %d" % len(rows)]
    for k in ("suffixed", "invented", "rtti-short", "rtti-named"):
        lines.append("  %-11s " % k + "  ".join("%s %d" % (cf, c[(k, cf)]) for cf in ("high", "medium", "low", "none")))
    hows = collections.Counter(x["how"] for e in rows if e["real"] for x in e["evidence"] if x["cls"] == e["real"])
    lines.append("evidence items for the chosen class: " + ", ".join("%s %d" % kv for kv in hows.most_common()))
    lines.append("propagation rounds: %d" % M.rounds)
    lines.append("chosen class on include/gen/: %d" % sum(1 for e in rows if e["real_on_gen"]))
    open(os.path.join(a.out, "rename-map-summary.txt"), "w").write("\n".join(lines) + "\n")
    print("\n".join(lines))
    return 0


if __name__ == "__main__":
    sys.exit(main())
