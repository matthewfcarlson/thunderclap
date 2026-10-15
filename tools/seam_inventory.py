#!/usr/bin/env python3
"""Seam interface inventory: what the portable layers (game, engine) call in platform/xbox -> docs/seams.md.

  build/venv/bin/python tools/seam_inventory.py           # write docs/seams.md (+ build/port/seams.json)
  build/venv/bin/python tools/seam_inventory.py --stats   # print the summary only

Inputs: config/splits.json (each object's `layer`, tools/infer_splits.py), build/functions.csv, build/rtti.json,
default.xbe (direct calls), build/port/platform_calls.json (XDK/kernel/Bink calls, tools/platform_map.py), and the
verified sources in matches/ and equivalent/ (virtual calls, typed by their stub classes).

Three kinds of crossing from game/engine into platform/xbox:

1. **Virtual dispatch.** The platform classes (`pure3d::d3d*`, `core::*XBox`, `movie::PlayerBink`, ...) implement
   portable interfaces (`pddiRenderContext`, `pddiShader`, `core::IController`, ...). Portable code calls them
   through a pointer to the interface, so the call has no address. They are found in the verified sources: a call
   `p->m(...)` where `p` is declared as a pointer to a class whose name is a portable ancestor (or the class itself)
   of a platform class, and `m` is a virtual of the source's stub of that class. The slot is the position of `m`
   among the stub's virtuals (after its base's slots). The implementation is the platform class's vtable entry at
   that slot (build/rtti.json); the call crosses the seam when that function is in a platform/xbox object.
   Only verified callers are seen, and calls written as raw vtable arithmetic are not typed.
2. **Direct calls** (`call`/`jmp` to a platform/xbox function) and address references (callbacks, function
   pointers) from game/engine functions, from the instructions.
3. **Layer leaks**: game/engine functions that call the XDK / kernel / Bink directly (platform_calls.json), and
   portable sources that name a platform class.

Only addresses, names and counts are written; no game bytes.
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
from infer_splits import PLATFORM_CLASS_RE, SEAMS, load_platform_calls, owner_class  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SPLITS = os.path.join(ROOT, "config/splits.json")
FUNCS_CSV = os.path.join(ROOT, "build/functions.csv")
RTTI_JSON = os.path.join(ROOT, "build/rtti.json")
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
OUT_MD = os.path.join(ROOT, "docs/seams.md")
OUT_JSON = os.path.join(ROOT, "build/port/seams.json")
PORTABLE = ("game", "engine")
PURECALL = 0x344F51               # _purecall: an abstract slot


def clean(name):
    return re.sub(r"\b(class|struct|enum|union) ", "", name)


def depth(v):
    """Nesting depth of a symbolic value (bounds the load chains the dispatch typing follows)."""
    d = 0
    while isinstance(v, tuple) and len(v) > 1 and isinstance(v[1], tuple):
        v = v[1]
        d += 1
    return d


def demangle_td(m):
    """'.?AVpddiObject@pure3d@@' -> 'pure3d::pddiObject' (plain class names only)."""
    m = re.match(r"\.\?A[UVT](.*)@@$", m)
    if not m or "?" in m.group(1):
        return None
    return "::".join(reversed(m.group(1).split("@")))


# ---------------------------------------------------------------------------------------------
class Inventory:
    def __init__(self):
        self.funcs = {}
        for r in csv.DictReader(open(FUNCS_CSV)):
            self.funcs[int(r["address"], 16)] = (int(r["size"]), r["name"])
        self.addrs = sorted(self.funcs)
        objs = json.load(open(SPLITS))["objects"]
        for o in objs:
            o["s"], o["e"] = int(o["start"], 16), int(o["end"], 16)
        self.objs = sorted(objs, key=lambda o: o["s"])
        self.starts = [o["s"] for o in self.objs]
        self.verified = {}
        for d in ("matches", "equivalent"):
            for fn in os.listdir(os.path.join(ROOT, d)):
                m = re.fullmatch(r"0x([0-9a-fA-F]{8})\.cpp", fn)
                if m:
                    self.verified.setdefault(int(m.group(1), 16), d)
        self.platform_calls = load_platform_calls()
        self.load_rtti()

    def obj(self, a):
        i = bisect.bisect_right(self.starts, a) - 1
        if i >= 0 and a < self.objs[i]["e"]:
            return self.objs[i]
        return None

    def layer(self, a):
        o = self.obj(a)
        return o.get("layer", "game") if o else None

    def seam(self, a):
        for name, _, rs in SEAMS:
            if any(s <= a < e for s, e in rs):
                return name
        return "outside the seam ranges"

    def status(self, a):
        return {"matches": "matched", "equivalent": "equivalent"}.get(self.verified.get(a), "not yet")

    def name(self, a):
        return self.funcs.get(a, (0, "FUN_%08x" % a))[1]

    # -- RTTI ------------------------------------------------------------------------------------
    def load_rtti(self):
        rtti = json.load(open(RTTI_JSON))
        self.classes = {}
        for c in rtti["classes"]:
            if not c.get("name"):
                continue
            n = clean(c["name"])
            vt = [v for v in c.get("vtables", []) if v["offset"] == 0]
            self.classes[n] = {"bases": [(demangle_td(b["name"]), b["mdisp"]) for b in c.get("bases", [])],
                               "vt": vt[0]["slots"] if vt else None, "vt_addr": vt[0]["address"] if vt else None}
        # platform classes and, for each, its portable ancestors that share the primary vtable
        self.platform = {n for n in self.classes if PLATFORM_CLASS_RE.match(n)}
        self.impls = collections.defaultdict(set)      # interface (or platform) class -> platform classes
        for p in self.platform:
            self.impls[p].add(p)
            for b, mdisp in self.classes[p]["bases"]:
                if b and mdisp == 0:
                    self.impls[b].add(p)
        self.desc = collections.defaultdict(set)       # class -> classes deriving from it (primary base chain)
        for n, c in self.classes.items():
            for b, mdisp in c["bases"]:
                if b and mdisp == 0:
                    self.desc[b].add(n)
        simple = collections.defaultdict(set)
        for n in self.classes:
            simple[n.split("::")[-1]].add(n)
        self.by_simple = {s: next(iter(ns)) for s, ns in simple.items() if len(ns) == 1}

    # -- 1. virtual dispatch from the sources ------------------------------------------------------
    def stub_classes(self, toks):
        """{simple name: (base simple name or None, [virtual member names in order])} for class definitions."""
        out = {}
        i, n = 0, len(toks)
        while i < n:
            t = toks[i]
            if t.v in ("class", "struct") and i + 1 < n and toks[i + 1].t == "id":
                j = i + 1
                while j + 2 < n and toks[j + 1].v == "::" and toks[j + 2].t == "id":
                    j += 2                      # class pure3d::X
                name = toks[j].v
                k = j + 1
                base = None
                if k < n and toks[k].v == ":":
                    k += 1
                    while k < n and toks[k].v in ("public", "private", "protected", "virtual"):
                        k += 1
                    while k < n and toks[k].v not in ("{", ",", ";"):
                        if toks[k].t == "id":
                            base = toks[k].v    # last component of a qualified base
                        k += 1
                    while k < n and toks[k].v not in ("{", ";"):
                        k += 1
                if k < n and toks[k].v == "{":
                    end = self.match(toks, k)
                    out[name] = (base, self.virtuals(toks, k + 1, end))
                    i = k + 1
                    continue
            i += 1
        return out

    @staticmethod
    def match(toks, k):
        depth = 0
        for j in range(k, len(toks)):
            if toks[j].v == "{":
                depth += 1
            elif toks[j].v == "}":
                depth -= 1
                if depth == 0:
                    return j
        return len(toks)

    def virtuals(self, toks, a, b):
        """Names of the virtual member functions declared directly in toks[a:b], in order."""
        names, j, start = [], a, a
        while j < b:
            v = toks[j].v
            if v == "{":
                e = self.match(toks, j)
                if j > start and self.is_decl_start(toks, start, j):
                    names.append(self.member_name(toks, start, j))
                j = start = e + 1
                continue
            if v == ";":
                if self.is_decl_start(toks, start, j):
                    names.append(self.member_name(toks, start, j))
                j = start = j + 1
                continue
            if v == ":" and j == start + 1 and toks[start].v in ("public", "private", "protected"):
                j = start = j + 1
                continue
            j += 1
        return names

    @staticmethod
    def is_decl_start(toks, a, b):
        return any(toks[k].v == "virtual" for k in range(a, b)) and any(toks[k].v == "(" for k in range(a, b))

    @staticmethod
    def member_name(toks, a, b):
        for k in range(a, b):
            if toks[k].v == "(":
                if k > a and toks[k - 1].t == "id":
                    nm = toks[k - 1].v
                    if k > a + 1 and toks[k - 2].v == "~":
                        return "~" + nm
                    if toks[k - 1].v == "operator" or (k > a + 1 and toks[k - 2].v == "operator"):
                        return "operator"
                    return nm
                return "?"
        return "?"

    def slot_map(self, stubs, name, seen=()):
        """[member name] -> slot index for stub `name` (base slots first: the stub base, else the RTTI base)."""
        base, virts = stubs[name]
        off = 0
        if base and base in stubs and base not in seen:
            off = len(self.slot_map(stubs, base, seen + (name,)))
        elif base and base in self.by_simple:
            vt = self.classes[self.by_simple[base]]["vt"]
            off = len(vt) if vt else 0
        return ["?"] * off + virts

    def virtual_calls(self):
        """[(caller addr, interface class, slot, member)] from game/engine sources; also platform-typed sources."""
        calls, typed_platform = [], collections.defaultdict(set)
        iface_simple = {n.split("::")[-1]: n for n in self.impls if n.split("::")[-1] in self.by_simple}
        self.typed_sources = 0
        for addr, kind in sorted(self.verified.items()):
            if self.layer(addr) not in PORTABLE:
                continue
            text = open(os.path.join(ROOT, kind, "0x%08x.cpp" % addr), encoding="latin1").read()
            if not any(s in text for s in iface_simple):
                continue
            try:
                toks = cxx_items.tokenize(text)
            except ValueError:
                continue
            stubs = self.stub_classes(toks)
            typed = collections.defaultdict(set)        # identifier -> interface classes
            for k in range(len(toks) - 2):
                c = toks[k].v
                if c in iface_simple and toks[k + 1].v == "*" and toks[k + 2].t == "id":
                    typed[toks[k + 2].v].add(c)
            if not typed:
                continue
            self.typed_sources += 1
            for c in {c for cs in typed.values() for c in cs}:
                if iface_simple[c] in self.platform:
                    typed_platform[iface_simple[c]].add(addr)
            for k in range(len(toks) - 3):
                if toks[k + 1].v != "->" or toks[k + 3].v != "(" or toks[k + 2].t != "id":
                    continue
                recv, member = toks[k].v, toks[k + 2].v
                if recv == ")":
                    # ((C*)x)->m(  /  ((C*)this)->m(
                    if k >= 5 and toks[k - 5].v == "(" and toks[k - 4].v in iface_simple and toks[k - 3].v == "*" \
                            and toks[k - 2].v == ")":
                        cs = {toks[k - 4].v}
                    else:
                        continue
                else:
                    cs = typed.get(recv)
                if not cs:
                    continue
                for c in cs:
                    if c not in stubs:
                        continue
                    slots = self.slot_map(stubs, c)
                    if member in slots:
                        calls.append((addr, iface_simple[c], slots.index(member), member))
        self.typed_platform = typed_platform
        return calls

    def platform_impl(self, f):
        """A platform/xbox function that belongs to an Xbox class (or to none): not a portable class's inline
        method that the linker happened to place in a platform object (COMDAT)."""
        if self.layer(f) != "platform/xbox":
            return False
        c = owner_class(self.name(f))
        return c is None or "<" in c or bool(PLATFORM_CLASS_RE.match(c))

    def targets(self, iface, slot):
        """(platform implementations, mixed) of a virtual call on static type `iface` at `slot`: the slot's
        function in every leaf class deriving from `iface`. A crossing when every leaf's implementation is a
        platform one; `mixed` when only some are (e.g. core::IRefCount reference counting)."""
        cands = self.desc.get(iface, set()) | {iface}
        leaves = [c for c in cands if c in self.classes and not self.desc.get(c)]
        impl = []
        for c in leaves:
            vt = self.classes[c]["vt"]
            if vt and slot < len(vt) and vt[slot] != PURECALL:
                impl.append((c, vt[slot]))
        plat = {(c, f) for c, f in impl if self.platform_impl(f)}
        if not plat:
            return set(), False
        if len(plat) == len(impl):
            return plat, False
        return set(), True

    def declaring(self, cls, slot):
        """The portable class that introduces virtual `slot` of platform class `cls` (its most basic portable
        ancestor whose vtable has the slot), or None when only the Xbox class has it."""
        best = None
        for b, mdisp in self.classes.get(cls, {}).get("bases", []):
            if not b or mdisp != 0 or PLATFORM_CLASS_RE.match(b) or b not in self.classes:
                continue
            vt = self.classes[b]["vt"]
            if vt and slot < len(vt) and (best is None or len(vt) < best[0]):
                best = (len(vt), b)
        return best[1] if best else None

    def dispatch_table(self, machine_calls):
        """Group typed virtual calls by (declaring interface, slot); keep those whose every implementation is
        Xbox code. `mixed` counts the calls whose implementations are partly portable (shared bases)."""
        rows = {}
        self.mixed = collections.Counter()
        for caller, site, static, slot in machine_calls:
            t, mixed = self.targets(static, slot)
            if mixed:
                self.mixed[static] += 1
            if not t:
                continue
            leaf = min(t)[0]
            decl = self.declaring(leaf, slot)
            key = (decl or leaf, slot)
            r = rows.setdefault(key, {"iface": decl or leaf, "slot": slot, "platform_only": decl is None,
                                      "static": collections.Counter(), "targets": set(), "sites": set(),
                                      "callers": set()})
            r["targets"] |= t
            r["static"][static] += 1
            r["sites"].add(site)
            r["callers"].add(caller)
        return rows

    # -- 2. machine-level pass: direct calls, references, and typed virtual dispatch -----------------------
    def scan(self):
        """Disassemble every game/engine/platform function once: direct calls/references from portable code
        into platform/xbox, and the events dispatch_machine types (stores, virtual calls, returns, out-params).

        A linear, per-function symbolic pass (no control-flow merging): registers and stack slots hold the
        last value written; constants (`xor r, r`, `mov r, imm`) don't replace a pointer (a null on an error
        path is compatible with any type); esp is tracked through push/pop/sub/add and callee `ret N`."""
        import capstone
        from capstone import x86 as X
        xbe = Xbe(XBE_PATH)
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        md.detail = True
        plat = {a for a in self.funcs if self.layer(a) == "platform/xbox"}
        self.vtable_class = {c["vt_addr"]: n for n, c in self.classes.items() if c["vt_addr"] is not None}
        GP = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp"}
        SUB = {"al": "eax", "ah": "eax", "ax": "eax", "bl": "ebx", "bh": "ebx", "bx": "ebx", "cl": "ecx",
               "ch": "ecx", "cx": "ecx", "dl": "edx", "dh": "edx", "dx": "edx", "si": "esi", "di": "edi",
               "bp": "ebp"}
        insns = {}
        retpop = {}
        for a in self.addrs:
            size = self.funcs[a][0]
            o = xbe.offset(a)
            if o is None or size <= 0:
                continue
            lst = list(md.disasm(xbe.data[o:o + size], a))
            for ins in lst:
                if ins.mnemonic == "ret":
                    retpop[a] = ins.operands[0].imm if ins.operands else 0
                    break
            if self.layer(a) not in (None, "library"):
                insns[a] = lst
        calls, refs = [], []
        self.ev = {}
        for f, lst in insns.items():
            portable = self.layer(f) in PORTABLE
            st = {"regs": {"ecx": ("this", f)}, "esp": 0, "stack": {}, "pushes": [], "mem": {}}
            ev = {"stores": [], "dispatch": [], "rets": [], "vtstores": [], "outstores": [], "outcalls": []}

            def reg(name):
                return st["regs"].get(name) if name in GP else (("spv", f, st["esp"]) if name == "esp" and
                                                                  st["esp"] is not None else None)

            def memloc(op, ins):
                """(base value, disp) of a memory operand; base ('abs',) for an absolute address."""
                m = op.mem
                if m.index != 0 or m.segment != 0:
                    return None
                if m.base == 0:
                    return (("abs",), m.disp & 0xFFFFFFFF)
                b = reg(ins.reg_name(m.base))
                if b is None or depth(b) > 5:
                    return None
                return (b, m.disp)

            def load(loc):
                base, disp = loc
                if base[0] == "spv":
                    off = base[2] + disp
                    if off in st["stack"]:
                        return st["stack"][off]
                    return ("arg", f, off) if off > 0 else ("ls", f, off)
                return st["mem"].get(loc) or ("d", base, disp)

            def value(op, ins):
                if op.type == X.X86_OP_REG:
                    return reg(ins.reg_name(op.reg))
                if op.type == X.X86_OP_IMM:
                    return ("imm", op.imm & 0xFFFFFFFF)
                if op.type == X.X86_OP_MEM:
                    loc = memloc(op, ins)
                    return load(loc) if loc else None
                return None

            def store(loc, v):
                base, disp = loc
                if base[0] == "spv":
                    st["stack"][base[2] + disp] = v
                    if v is not None and v[0] != "imm":
                        ev["stores"].append(((("S", f), base[2] + disp), v))
                    return
                if v is None:
                    st["mem"].pop(loc, None)
                    return
                if v[0] == "imm":
                    if disp == 0 and v[1] in self.vtable_class:
                        ev["vtstores"].append((base, self.vtable_class[v[1]]))
                    return
                st["mem"][loc] = v
                if base[0] == "arg" and disp == 0:
                    ev["outstores"].append((base[2], v))
                    return
                ev["stores"].append((loc, v))

            def setreg(name, v, const_ok=False):
                name = SUB.get(name, name)
                if name == "esp":
                    st["esp"] = v[2] if v and v[0] == "spv" else None
                    return
                if name not in GP:
                    return
                if v is None:
                    st["regs"].pop(name, None)
                elif v[0] == "imm" and not const_ok:
                    if name not in st["regs"]:
                        st["regs"][name] = v
                else:
                    st["regs"][name] = v

            def after_call(target_spec, ins, popped):
                args = list(reversed(st["pushes"]))
                ev["outcalls"].append((target_spec, args, st["regs"].get("ecx")))
                if st["esp"] is not None:
                    st["esp"] += popped
                st["pushes"] = []
                for r in ("eax", "ecx", "edx"):
                    st["regs"].pop(r, None)

            for ins in lst:
                mn, ops = ins.mnemonic, ins.operands
                if portable:
                    for op in ops:
                        v = None
                        if op.type == X.X86_OP_IMM:
                            v = op.imm & 0xFFFFFFFF
                        elif op.type == X.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
                            v = op.mem.disp & 0xFFFFFFFF
                        if v in plat:
                            (calls if mn in ("call", "jmp") and op.type == X.X86_OP_IMM else refs).append((f, v))
                if mn == "push" and ops:
                    v = value(ops[0], ins)
                    if st["esp"] is not None:
                        st["esp"] -= 4
                        st["stack"][st["esp"]] = v
                    st["pushes"].append(v)
                    continue
                if mn == "pop" and ops:
                    v = st["stack"].get(st["esp"]) if st["esp"] is not None else None
                    if st["esp"] is not None:
                        st["esp"] += 4
                    if st["pushes"]:
                        st["pushes"].pop()
                    if ops[0].type == X.X86_OP_REG:
                        setreg(ins.reg_name(ops[0].reg), v, True)
                    continue
                if mn in ("sub", "add") and len(ops) == 2 and ops[0].type == X.X86_OP_REG and \
                        ins.reg_name(ops[0].reg) == "esp":
                    if ops[1].type == X.X86_OP_IMM and st["esp"] is not None:
                        n = ops[1].imm
                        st["esp"] += -n if mn == "sub" else n
                        if mn == "add":
                            st["pushes"] = st["pushes"][:max(0, len(st["pushes"]) - n // 4)]
                    else:
                        st["esp"] = None
                    continue
                if mn == "call":
                    op = ops[0]
                    if op.type == X.X86_OP_IMM:
                        t = op.imm & 0xFFFFFFFF
                        after_call(("f", t), ins, retpop.get(t, 0))
                        st["regs"]["eax"] = ("rc", t, ins.address)
                    elif op.type == X.X86_OP_MEM:
                        loc = memloc(op, ins)
                        ret, spec = None, None
                        if loc and loc[0][0] == "d" and loc[0][2] == 0 and loc[1] % 4 == 0 and loc[1] >= 0:
                            obj, slot = loc[0][1], loc[1] // 4
                            ev["dispatch"].append((ins.address, obj, slot))
                            ret, spec = ("rv", obj, slot, ins.address), ("v", obj, slot)
                        after_call(spec, ins, 4 * len(st["pushes"]))
                        if ret:
                            st["regs"]["eax"] = ret
                    else:
                        after_call(None, ins, 4 * len(st["pushes"]))
                    continue
                if mn == "ret":
                    if "eax" in st["regs"]:
                        ev["rets"].append(st["regs"]["eax"])
                    continue
                if mn == "jmp" and ops:
                    if ops[0].type == X.X86_OP_IMM:
                        t = ops[0].imm & 0xFFFFFFFF
                        if t in self.funcs and t != f:
                            ev["rets"].append(("rc", t, ins.address))       # tail call
                    else:
                        st["regs"].clear()
                    continue
                if mn in ("mov", "lea") and len(ops) == 2:
                    dst, src = ops
                    if mn == "lea":
                        loc = memloc(src, ins)
                        v = None
                        if loc and loc[0][0] == "spv":
                            v = ("spv", f, loc[0][2] + loc[1])
                        elif loc and loc[0] == ("abs",):
                            v = ("imm", loc[1])
                        setreg(ins.reg_name(dst.reg), v, True)
                        continue
                    if dst.type == X.X86_OP_MEM:
                        loc = memloc(dst, ins)
                        if loc:
                            store(loc, value(src, ins))
                        continue
                    if dst.type == X.X86_OP_REG:
                        setreg(ins.reg_name(dst.reg), value(src, ins))
                        continue
                if mn == "xor" and len(ops) == 2 and ops[0].type == X.X86_OP_REG and ops[1].type == X.X86_OP_REG \
                        and ops[0].reg == ops[1].reg:
                    setreg(ins.reg_name(ops[0].reg), ("imm", 0))
                    continue
                try:
                    _, written = ins.regs_access()
                except capstone.CsError:
                    written = []
                for w in written:
                    r = SUB.get(ins.reg_name(w), ins.reg_name(w))
                    if r == "esp":
                        if mn not in ("push", "pop", "call", "ret"):
                            st["esp"] = None
                    elif r in GP:
                        st["regs"].pop(r, None)
            self.ev[f] = ev
        return calls, refs

    def dispatch_machine(self):
        """Type the receivers of `call [vtbl+slot*4]` in portable code by propagation and return
        [(caller, site, static class, slot)] for receivers whose class has a platform implementation.

        Types: `this` is the function's RTTI owner (or the most derived vtable its constructor stores); a call
        returns what its target returns (the type of eax at its `ret`s and tail calls, or the class whose
        vtable is stored into the fresh object); an out-parameter (`*arg = x`) passes x's type to the global
        or stack slot the caller pointed it at; a global, class field (`[T+disp]`) or stack slot gets the type
        of every value stored there. Iterated to a fixed point. A lower bound: receivers reached through
        untyped code (FUN_ methods' `this`, containers, casts) stay untyped."""
        owner = {}
        for a, (size, name) in self.funcs.items():
            c = owner_class(name)
            if c and c in self.classes:
                owner[a] = c
        obj_type, ctor_this = {}, {}
        for f, ev in self.ev.items():
            for base, cls in ev["vtstores"]:
                if base == ("this", f):
                    ctor_this[f] = cls          # last store wins: the most derived constructor
                else:
                    obj_type[base] = cls
        returns, field, outp, thistype, argtype = {}, {}, {}, {}, {}
        # functions that return their own `this` (constructors, chaining setters): an object without RTTI gets
        # the anonymous type ('anon', constructor) so its fields can still carry types
        returns_this = {f for f, ev in self.ev.items() if ("this", f) in ev["rets"]}

        def resolve(spec, depth_=0):
            if spec is None:
                return None
            if spec[0] == "f":
                return spec[1]
            t = type_of(spec[1], depth_ + 1)
            vt = self.classes.get(t, {}).get("vt") if t else None
            return vt[spec[2]] if vt and spec[2] < len(vt) else None

        def type_of(v, depth_=0):
            if v is None or depth_ > 8:
                return None
            k = v[0]
            if v in obj_type:
                return obj_type[v]
            if k == "this":
                f = v[1]
                return ctor_this.get(f) or owner.get(f) or thistype.get(f) or (("anon", f) if f in returns_this else None)
            if k == "arg":
                return argtype.get((v[1], v[2]))
            if k == "rc":
                return returns.get(v[1])
            if k == "rv":
                t = resolve(("v", v[1], v[2]), depth_)
                return returns.get(t) if t else None
            if k == "ls":
                return field.get((("S", v[1]), v[2]))
            if k == "d":
                base, disp = v[1], v[2]
                if base == ("abs",):
                    return field.get(("G", disp))
                t = type_of(base, depth_ + 1)
                return field.get((t, disp)) if t else None
            return None

        def put(loc, t):
            if t and loc not in field:
                field[loc] = t
                return True
            return False

        for _ in range(16):
            changed = False
            for f, ev in self.ev.items():
                ts = {type_of(r) for r in ev["rets"]} - {None}
                if f in ctor_this:
                    ts = {ctor_this[f]}
                if len(ts) == 1:
                    t = ts.pop()
                    if returns.get(f) != t:
                        returns[f] = t
                        changed = True
                for off, v in ev["outstores"]:
                    t = type_of(v)
                    if t and (f, off) not in outp:
                        outp[(f, off)] = t
                        changed = True
                for (base, disp), v in ev["stores"]:
                    t = type_of(v)
                    if not t:
                        continue
                    if base == ("abs",):
                        changed |= put(("G", disp), t)
                    elif base[0] == "S":
                        changed |= put((base, disp), t)
                    else:
                        tb = type_of(base)
                        if tb:
                            changed |= put((tb, disp), t)
                for spec, args, ecx in ev["outcalls"]:
                    tgt = resolve(spec)
                    if tgt is None:
                        continue
                    if tgt not in thistype and tgt not in owner and tgt not in ctor_this:
                        t = type_of(ecx)
                        if t:
                            thistype[tgt] = t
                            changed = True
                    for i, av in enumerate(args):
                        if (tgt, 4 + 4 * i) not in argtype:
                            t = type_of(av)
                            if t:
                                argtype[(tgt, 4 + 4 * i)] = t
                                changed = True
                        t = outp.get((tgt, 4 + 4 * i))
                        if not t or av is None:
                            continue
                        if av[0] == "imm":
                            changed |= put(("G", av[1]), t)
                        elif av[0] == "spv":
                            changed |= put(((("S", av[1])), av[2]), t)
            if not changed:
                break
        self.field_types, self.returns = field, returns
        out = []
        for f, ev in self.ev.items():
            if self.layer(f) not in PORTABLE:
                continue
            for site, obj, slot in ev["dispatch"]:
                t = type_of(obj)
                vt = self.classes.get(t, {}).get("vt") if isinstance(t, str) else None
                if vt and slot < len(vt):       # a slot past the static type's vtable: typed too generally
                    out.append((f, site, t, slot))
        return out

    # -- 3. leaks ----------------------------------------------------------------------------------
    def leaks(self):
        out = []
        for a, apis in sorted(self.platform_calls.items()):
            layer = self.layer(a)
            if layer in PORTABLE:
                o = self.obj(a)
                out.append({"addr": a, "layer": layer, "object": o["file"], "apis": apis})
        return out


# ---------------------------------------------------------------------------------------------
def build():
    inv = Inventory()
    inv.virtual_calls()                 # portable sources that name a platform class
    dcalls, drefs = inv.scan()
    mcalls = inv.dispatch_machine()
    rows = inv.dispatch_table(mcalls)
    leaks = inv.leaks()
    return inv, mcalls, rows, dcalls, drefs, leaks


def fmt_status(counter):
    return ", ".join("%d %s" % (n, s) for s, n in sorted(counter.items(), key=lambda kv: (-kv[1], kv[0])))


def short(name):
    return name.replace("pure3d::", "").replace("core::", "core::")


def write_md(inv, mcalls, rows, dcalls, drefs, leaks):
    L = []
    caller_layer = lambda a: "init" if (inv.obj(a) or {}).get("kind") == "game-init" else inv.layer(a)
    plat_objs = [o for o in inv.objs if o.get("layer") == "platform/xbox"]
    plat_funcs = [a for a in inv.addrs if inv.layer(a) == "platform/xbox"]
    st_all = collections.Counter(inv.status(a) for a in plat_funcs)
    new = lambda: {"objs": [], "funcs": [], "vrows": [], "dcalls": collections.Counter(), "drefs": collections.Counter()}
    seams = collections.OrderedDict((n, new()) for n, _, _ in SEAMS)
    for o in plat_objs:
        seams.setdefault(inv.seam((o["s"] + o["e"]) // 2), new())["objs"].append(o)
    for a in plat_funcs:
        seams.setdefault(inv.seam(a), new())["funcs"].append(a)
    for r in rows.values():
        seams.setdefault(inv.seam(min(a for _, a in r["targets"])), new())["vrows"].append(r)
    is_init = lambda a: (inv.obj(a) or {}).get("kind") == "game-init"
    init_xs = [(c, t) for c, t in dcalls + drefs if is_init(c)]
    dcalls = [(c, t) for c, t in dcalls if not is_init(c)]
    drefs = [(c, t) for c, t in drefs if not is_init(c)]
    callers_of = collections.defaultdict(set)
    for c, t in dcalls:
        callers_of[t].add(c)
    refs_of = collections.defaultdict(list)
    for c, t in drefs:
        refs_of[t].append(c)
    for c, t in dcalls:
        seams.setdefault(inv.seam(t), new())["dcalls"][t] += 1
    for c, t in drefs:
        seams.setdefault(inv.seam(t), new())["drefs"][t] += 1
    n_vsites = sum(len(r["sites"]) for r in rows.values())
    n_disp = sum(len(ev["dispatch"]) for f, ev in inv.ev.items() if inv.layer(f) in PORTABLE)

    L.append("# Seam interfaces\n")
    L.append("Generated by `tools/seam_inventory.py` (rerun it after `tools/infer_splits.py`). Every way the portable "
             "layers, `src/game` and `src/engine`, reach into `src/platform/xbox`: the interface `include/seams/` will "
             "declare and `src/platform/sdl` has to implement. Layers: [splits.md](splits.md#layers) and "
             "[shipping.md §1](shipping.md#1-the-source-tree-roadmap-steps-2-and-4); seams: the four address ranges "
             "of [platform-boundary.md](platform-boundary.md#the-seams). Status: `matched` (matches/), `equivalent` "
             "(equivalent/), `not yet`.\n")
    L.append("## Summary\n")
    L.append("| seam | platform/xbox objects | functions: matched / equivalent / not yet | virtual methods called "
             "from portable code (call sites) | direct entry points (call sites) | functions whose address portable "
             "code takes |")
    L.append("|---|---|---|---|---|---|")
    for n, s in seams.items():
        st = collections.Counter(inv.status(a) for a in s["funcs"])
        L.append("| %s | %d | %d: %d / %d / %d | %d (%d) | %d (%d) | %d |" % (
            n, len(s["objs"]), len(s["funcs"]), st["matched"], st["equivalent"], st["not yet"],
            len(s["vrows"]), sum(len(r["sites"]) for r in s["vrows"]), len(s["dcalls"]), sum(s["dcalls"].values()),
            len(s["drefs"])))
    L.append("")
    L.append("platform/xbox in total: %d objects, %d functions (%s). Of %d virtual call instructions in game/engine "
             "code, %d have a receiver whose class the analysis could type, and %d of those always land in Xbox "
             "code (the rows below); %d more go through a shared base with both portable and Xbox implementations "
             "(%s), which is not a seam.\n" % (
                 len(plat_objs), len(plat_funcs), fmt_status(st_all), n_disp, len(mcalls), n_vsites,
                 sum(inv.mixed.values()), ", ".join("`%s` %d" % kv for kv in inv.mixed.most_common(4))))
    if init_xs:
        objs_ = collections.Counter(inv.obj(t)["file"] for _, t in init_xs)
        L.append("Not counted above: %d references from the `.text$yc` dynamic initializers (the `game-init` "
                 "pseudo-object, whose owning TUs are not recovered) to %d platform/xbox functions in %s. They "
                 "register the d3d shaders' factories, so they belong to those platform objects, not to portable "
                 "code.\n" % (len(init_xs), len({t for _, t in init_xs}), ", ".join(
                     "`%s`" % f for f, _ in objs_.most_common(4)) + (" and %d more" % (len(objs_) - 4)
                                                                    if len(objs_) > 4 else "")))

    for n, s in seams.items():
        if not (s["objs"] or s["vrows"] or s["dcalls"] or s["drefs"]):
            continue
        L.append("## %s\n" % n)
        if s["objs"]:
            L.append("Objects (`src/platform/xbox/…`): " + ", ".join(
                "`%s` (%d fn)" % (o["file"], o["functions"]) for o in s["objs"]) + ".\n")
        if s["vrows"]:
            by_iface = collections.defaultdict(list)
            for r in s["vrows"]:
                by_iface[r["iface"]].append(r)
            L.append("### Virtual methods\n")
            L.append("Per interface (the portable class that introduces the slot; an Xbox class name means only "
                     "the Xbox class has that slot), the slots portable code calls, the Xbox implementations, "
                     "typed call sites and calling functions, and the layers they are in.\n")
            L.append("| interface | slots called | call sites | callers | implementations: matched / equivalent / "
                     "not yet |")
            L.append("|---|---|---|---|---|")
            for iface, rs in sorted(by_iface.items(), key=lambda kv: -sum(len(r["sites"]) for r in kv[1])):
                impl = {a for r in rs for _, a in r["targets"]}
                st = collections.Counter(inv.status(a) for a in impl)
                L.append("| `%s`%s | %d | %d | %d | %d: %d / %d / %d |" % (
                    iface, " (Xbox only)" if rs[0]["platform_only"] else "", len(rs),
                    sum(len(r["sites"]) for r in rs), len({c for r in rs for c in r["callers"]}), len(impl),
                    st["matched"], st["equivalent"], st["not yet"]))
            L.append("")
            L.append("| interface | slot | implementation(s) | status | sites | callers | from | receiver typed as |")
            L.append("|---|---|---|---|---|---|---|---|")
            for r in sorted(s["vrows"], key=lambda r: (r["iface"], r["slot"])):
                ts = sorted(r["targets"], key=lambda t: t[1])
                impl = ", ".join("`%s`" % short(inv.name(a)) for _, a in ts[:2]) + (
                    " +%d" % (len(ts) - 2) if len(ts) > 2 else "")
                stc = collections.Counter(inv.status(a) for _, a in ts)
                ls = collections.Counter(caller_layer(c) for c in r["callers"])
                L.append("| `%s` | %d | %s | %s | %d | %d | %s | %s |" % (
                    short(r["iface"]), r["slot"], impl, fmt_status(stc), len(r["sites"]), len(r["callers"]),
                    fmt_status(ls), ", ".join("`%s`" % short(c) for c, _ in r["static"].most_common(2))))
            L.append("")
        if s["dcalls"]:
            L.append("### Direct entry points\n")
            L.append("| function | object | status | call sites | callers | from |")
            L.append("|---|---|---|---|---|---|")
            for t, k in sorted(s["dcalls"].items(), key=lambda kv: (-kv[1], kv[0])):
                ls = collections.Counter(caller_layer(c) for c in callers_of[t])
                L.append("| `%s` 0x%x | `%s` | %s | %d | %d | %s |" % (
                    short(inv.name(t)), t, inv.obj(t)["file"], inv.status(t), k, len(callers_of[t]), fmt_status(ls)))
            L.append("")
        if s["drefs"]:
            L.append("### Functions whose address portable code takes (callbacks, registration tables)\n")
            L.append("| function | object | status | references | from |")
            L.append("|---|---|---|---|---|")
            for t, k in sorted(s["drefs"].items(), key=lambda kv: (-kv[1], kv[0])):
                ls = collections.Counter(caller_layer(c) for c in refs_of[t])
                L.append("| `%s` 0x%x | `%s` | %s | %d | %s |" % (short(inv.name(t)), t, inv.obj(t)["file"],
                                                                inv.status(t), k, fmt_status(ls)))
            L.append("")

    L.append("## Layer leaks\n")
    L.append("Portable code that reaches the platform outside these interfaces. Each needs a shim function or a move "
             "into `platform/xbox` before `game` + `engine` build without the XDK.\n")
    L.append("### Direct XDK / kernel / Bink calls from game and engine\n")
    L.append("| function | layer | object | status | calls |")
    L.append("|---|---|---|---|---|")
    for lk in leaks:
        L.append("| `%s` 0x%x | %s | `%s` | %s | %s |" % (inv.name(lk["addr"]), lk["addr"], caller_layer(lk["addr"]),
                                                       lk["object"], inv.status(lk["addr"]), ", ".join(lk["apis"][:5])))
    L.append("")
    plat_only = [r for r in rows.values() if r["platform_only"]]
    L.append("### Virtual slots only the Xbox class has\n")
    if plat_only:
        L.append("Portable code calls these through the concrete Xbox type; no portable base declares the slot, so "
                 "the seam interface has to gain it.\n")
        L.append("| class | slot | implementation | sites | callers |")
        L.append("|---|---|---|---|---|")
        for r in sorted(plat_only, key=lambda r: (r["iface"], r["slot"])):
            ts = sorted(r["targets"], key=lambda t: t[1])
            L.append("| `%s` | %d | `%s` | %d | %s |" % (short(r["iface"]), r["slot"], short(inv.name(ts[0][1])),
                                                         len(r["sites"]), ", ".join(
                                                             "`%s`" % inv.obj(c)["file"] for c in sorted(r["callers"])[:3])))
    else:
        L.append("None.")
    L.append("")
    game_direct = sorted({(c, t) for c, t in dcalls + drefs if caller_layer(c) == "game"})
    L.append("### Game code calling platform/xbox directly\n")
    L.append("Not wrong in itself (the engine's Xbox layer has free functions too), but each is a call the SDL "
             "backend must provide under the same name.\n")
    if game_direct:
        L.append("| caller | object | target | target object |")
        L.append("|---|---|---|---|")
        for c, t in game_direct:
            L.append("| `%s` 0x%x | `%s` | `%s` 0x%x | `%s` |" % (inv.name(c), c, inv.obj(c)["file"], short(inv.name(t)),
                                                              t, inv.obj(t)["file"]))
    else:
        L.append("None.")
    L.append("")
    L.append("### Portable sources that name an Xbox class\n")
    if inv.typed_platform:
        L.append("A game/engine source in matches/ or equivalent/ declares a stub of an Xbox class (usually because "
                 "it was written against the concrete type the object has at run time). These sources need the "
                 "interface type once include/seams/ exists.\n")
        L.append("| Xbox class | portable sources |")
        L.append("|---|---|")
        for p, srcs in sorted(inv.typed_platform.items()):
            L.append("| `%s` | %d (%s) |" % (p, len(srcs), ", ".join("0x%x" % a for a in sorted(srcs)[:6]) +
                                             (" …" if len(srcs) > 6 else "")))
    else:
        L.append("None.")
    L.append("")
    L.append("""## Method and limits

- **Layers and seam ranges**: `config/splits.json` (`tools/infer_splits.py`), `tools/platform_map.py` `SEAMS`.
- **Direct calls and references**: `call`/`jmp` immediates and other immediate or absolute-memory operands that
  equal a platform/xbox function's start, in every game/engine function (`default.xbe`). `init` callers are the
  `.text$yc` dynamic initializers, whose owning TU is not recovered (the shader ones belong to the d3d objects).
- **Virtual calls** (`call [vtable+4*slot]`) are typed by a linear symbolic pass over every function: `this`
  of RTTI-named methods, constructors' vtable stores, what calls return (eax at `ret`, tail calls), out-parameters,
  parameters and `this` passed by callers, and the types of values stored in globals, fields and stack slots,
  iterated to a fixed point. The root is `d3dCreateDevice` (0x31ba60) returning a `d3dDevice`, which then hands
  out the display and the context that Pure3D keeps in globals (`0x52c2a0` device, `0x52c2a4` display,
  `0x52c2a8` context). No control-flow merging and no containers, so the counts are a **lower bound**; a call
  whose receiver stays untyped is not listed.
- A typed call is a seam crossing when the slot's function is Xbox code in **every** leaf class deriving from
  the receiver's type (build/rtti.json). Inline methods of portable classes that the linker placed in an Xbox
  object (COMDATs such as `pddiObject` reference counting) don't count as Xbox code.
- **Interface** = the most basic portable ancestor whose vtable already has the slot; that is the declaration
  `include/seams/` needs. Slot numbers are vtable indices (×4 = byte offset).
- **Leaks**: `build/port/platform_calls.json` (`tools/platform_map.py`) callers in game/engine objects; portable
  CRT calls are not leaks. Source stubs naming an Xbox class: verified game/engine sources only.
""")
    with open(OUT_MD, "w") as f:
        f.write("\n".join(L))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--stats", action="store_true")
    a = ap.parse_args(argv)
    inv, mcalls, rows, dcalls, drefs, leaks = build()
    print("virtual calls typed: %d; %d (interface, slot) rows land in platform/xbox (%d sites); mixed %d" % (
        len(mcalls), len(rows), sum(len(r["sites"]) for r in rows.values()), sum(inv.mixed.values())))
    print("direct calls: %d sites to %d functions; references: %d to %d" % (
        len(dcalls), len({t for _, t in dcalls}), len(drefs), len({t for _, t in drefs})))
    print("leak functions: %d" % len(leaks))
    if a.stats:
        return 0
    write_md(inv, mcalls, rows, dcalls, drefs, leaks)
    os.makedirs(os.path.dirname(OUT_JSON), exist_ok=True)
    with open(OUT_JSON, "w") as f:
        json.dump({"virtual": [{"interface": r["iface"], "slot": r["slot"], "platform_only": r["platform_only"],
                                "targets": sorted([p, "0x%x" % t] for p, t in r["targets"]),
                                "sites": sorted("0x%x" % x for x in r["sites"]),
                                "callers": sorted("0x%x" % c for c in r["callers"])} for r in rows.values()],
                   "direct_calls": [["0x%x" % c, "0x%x" % t] for c, t in dcalls],
                   "references": [["0x%x" % c, "0x%x" % t] for c, t in drefs],
                   "leaks": [dict(lk, addr="0x%x" % lk["addr"]) for lk in leaks]}, f, indent=0)
    print("wrote", os.path.relpath(OUT_MD, ROOT), "and", os.path.relpath(OUT_JSON, ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
