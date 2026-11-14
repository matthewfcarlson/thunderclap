#!/usr/bin/env python3
"""Layout checker for the class headers in include/gen/ (the layout probe).

include/gen/ is source, edited by hand (since gen1, 2026-11-13). This tool generated it from the recovered RTTI
until then; it is now a checker only. It builds a model of the game's polymorphic classes from build/rtti.json
(tools/rtti.py) and the XBE (destructor slots), compiles the headers with cl 13.10 and checks what MSVC makes of
them against that model:

  tools/gen_headers.py --probe [HDR..]   # compile every header alone, then construct every RTTI class and check
                                         # its vftables, slot implementers, RTTI base descriptors and sizeof
  tools/gen_headers.py --probe --update-sizes   # after an intended 32-bit layout change: record the sizes

Checks (docs/headers.md "The layout probe"):
  - every header compiles on its own (/c /O2 /GR /GX-: the game was built without exceptions);
  - every RTTI class with a vftable has its vftables emitted, with the slot count RTTI gives;
  - every slot's function is the one RTTI says (the class that last overrode it, or _purecall);
  - every class's ??_R1 base class descriptors (mdisp/pdisp/vdisp) are the XBE's;
  - sizeof of every concrete class equals config/gen-sizes.json (the 32-bit sizes the headers had when they were
    last recorded: a header edit that changes a layout shows up here, and is recorded with --update-sizes when it
    is meant).

Inputs: build/rtti.json, build/functions.csv, isos/extracted/default.xbe, the MSVC 7.1 compiler under wibo.

Writes: nothing in the checkout. `--probe` reads include/gen/ and config/gen-sizes.json and compiles its probe TUs in a
fresh directory under build/tmp/ (removed afterwards; `--keep DIR` keeps it, DIR must be under build/ or outside the
checkout). Only `--update-sizes` writes a tracked file (config/gen-sizes.json). (tool2: an agent's `--probe` in the
shared checkout was refused by the auto-mode permission check as a destructive action: until gen1 this tool
regenerated include/gen/ and deleted the headers it did not write, which is what the agent had read about it.)
`tools/tree_tu.py verify` runs the probe itself when a file under include/gen/ changed (docs/headers.md).
"""
import argparse
import collections
import csv
import json
import os
import re
import subprocess
import sys
import tempfile

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
RTTI_PATH = os.path.join(ROOT, "build/rtti.json")
FUNCS_PATH = os.path.join(ROOT, "build/functions.csv")
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
OUT_DIR = os.path.join(ROOT, "include/gen")
SIZES_PATH = os.path.join(ROOT, "config/gen-sizes.json")
MSVC = os.path.join(ROOT, "build/compilers/msvc7.1/compilers/win32/msvc7.1")
WIBO = os.path.join(ROOT, "build/tools/wibo")

PURECALL = 0x344F51  # FUN_00344f51: calls the purecall handler then _amsg_exit(25)

# ---------------------------------------------------------------------------------------------
# Names

def split_top(s, sep):
    """Split s on sep at template depth 0."""
    out, depth, cur, i = [], 0, "", 0
    while i < len(s):
        ch = s[i]
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        if depth == 0 and s.startswith(sep, i):
            out.append(cur)
            cur = ""
            i += len(sep)
            continue
        cur += ch
        i += 1
    out.append(cur)
    return out


def split_template(comp):
    """'Method1<class A,void,int>' -> ('Method1', ['class A', 'void', 'int']); no args -> (comp, None)."""
    if "<" not in comp:
        return comp, None
    i = comp.index("<")
    return comp[:i], split_top(comp[i + 1:-1], ",")


def csv_name(name):
    """Demangled RTTI name -> the owner spelling ApplyRtti used in functions.csv."""
    return re.sub(r"\b(class|struct|union|enum) ", "", name).replace(" ", "_")


ELAB_RE = re.compile(r"\b(class|struct|union|enum) ")


def render_type(t):
    """Demangled type text -> C++ ('class a::B *' -> ' ::a::B *'), template brackets spaced."""
    out, i = [], 0
    while i < len(t):
        m = ELAB_RE.match(t, i)
        if m and (i == 0 or not (t[i - 1].isalnum() or t[i - 1] == "_")):
            out.append("::")
            i = m.end()
            continue
        ch = t[i]
        if ch == "<":
            out.append("< ")
        elif ch == ">":
            out.append(" >")
        elif ch == ",":
            out.append(", ")
        else:
            out.append(ch)
        i += 1
    s = "".join(out)
    s = re.sub(r"\s+", " ", s).strip()
    return s


def elaborated_types(t):
    """All (keyword, qualified name) pairs named with class/struct/union/enum in type text."""
    res = []
    for m in ELAB_RE.finditer(t):
        i = m.end()
        depth, j = 0, i
        while j < len(t):
            ch = t[j]
            if ch == "<":
                depth += 1
            elif ch == ">":
                if depth == 0:
                    break
                depth -= 1
            elif depth == 0 and (ch in ", *&" or ch == ")"):
                break
            j += 1
        res.append((m.group(1), t[i:j]))
    return res


def is_nontype(arg):
    return re.fullmatch(r"-?\d+", arg) is not None


# ---------------------------------------------------------------------------------------------
# Slot bodies

class Code:
    def __init__(self):
        self.ok = os.path.exists(XBE_PATH)
        self.funcs = {}
        with open(FUNCS_PATH) as f:
            for r in csv.DictReader(f):
                self.funcs[int(r["address"], 16)] = (int(r["size"]), r["name"])
        if self.ok:
            sys.path.insert(0, os.path.dirname(__file__))
            from xbe import Xbe
            import capstone
            self.xbe = Xbe(XBE_PATH)
            self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
            self.md.syntax = capstone.CS_OPT_SYNTAX_INTEL
        self._cache = {}

    def insns(self, va, depth=0):
        if not self.ok:
            return []
        if va in self._cache:
            return self._cache[va]
        size = self.funcs.get(va, (256, None))[0]
        o = self.xbe.offset(va)
        if o is None:
            return []
        out = []
        for ins in self.md.disasm(self.xbe.data[o:o + min(size, 512)], va):
            out.append(ins)
            if ins.mnemonic in ("ret", "jmp") and va not in self.funcs:
                break
        # Adjustor thunk: sub/add ecx, imm; jmp target -> analyse the target.
        if depth == 0 and len(out) >= 2 and out[0].mnemonic in ("sub", "add") and out[0].op_str.startswith("ecx,") \
                and out[1].mnemonic == "jmp" and out[1].op_str.startswith("0x"):
            out = self.insns(int(out[1].op_str, 16), 1)
        self._cache[va] = out
        return out

    def is_scalar_dtor(self, va):
        """Scalar deleting destructor shape: tests the flags argument against 1 and returns with ret 4."""
        ins = self.insns(va)
        if not ins:
            return False
        ret4 = any(i.mnemonic == "ret" and i.op_str == "4" for i in ins)
        test1 = any(i.mnemonic == "test" and re.search(r"(byte ptr \[esp \+ (?:0x)?[0-9a-f]+\]|\b[a-d]l|\bbl), 1$", i.op_str)
                    for i in ins)
        calls = any(i.mnemonic == "call" for i in ins)
        return ret4 and test1 and calls



# ---------------------------------------------------------------------------------------------
# Model

class Cls:
    def __init__(self, rec):
        self.rec = rec
        self.mangled = rec["mangled"]
        self.name = rec["name"]
        self.keyword = {"V": "class", "U": "struct", "T": "union"}[self.mangled[3]]
        self.parts = split_top(self.name, "::")
        self.short, self.targs = split_template(self.parts[-1])
        self.vtables = {}
        self.vtaddr = {}
        for v in rec["vtables"]:
            if v["slots"] and v["offset"] not in self.vtables:
                self.vtables[v["offset"]] = v["slots"]
                self.vtaddr[v["offset"]] = v["address"]
        self.has_layout = rec["attributes"] is not None
        self.bases = []      # direct: (Cls, mdisp, virtual)
        self.all_bases = []  # flattened RTTI list: (Cls, mdisp, pdisp, vdisp, attributes)
        self.unit = None

    @property
    def scope_mangled(self):
        return self.mangled[4:]


class Unit:
    """A plain class, or a template family (its instantiations)."""

    def __init__(self, uid, members, template):
        self.uid = uid
        self.members = members        # [Cls]
        self.template = template
        self.parts = split_top(uid, "::")
        self.short = self.parts[-1]
        self.ns = []            # namespace path
        self.outer = None       # enclosing Unit (nested class)
        self.header = None      # the header the class lives in (its outermost class's top-level namespace)
        self.nested = []


class Model:
    """The game's polymorphic classes as RTTI and the XBE give them: bases, vftables, the class that implements
    each slot, destructor slots."""

    def __init__(self):
        rt = json.load(open(RTTI_PATH))
        self.classes = [Cls(r) for r in rt["classes"]]
        self.by_mangled = {c.mangled: c for c in self.classes}
        self.by_name = {c.name: c for c in self.classes}
        self.code = Code()
        self.report = collections.defaultdict(list)
        for c in self.classes:
            bl = c.rec["bases"]
            c.all_bases = [(self.by_mangled[b["name"]], b["mdisp"], b["pdisp"], b["vdisp"], b["attributes"]) for b in bl]
            i = 0
            while i < len(bl):
                b = bl[i]
                c.bases.append((self.by_mangled[b["name"]], b["mdisp"], b["pdisp"] != -1))
                i += b["contained"] + 1
        self.repair_vtables()
        self.build_units()
        self.classify_scopes()
        self.analyse_slots()

    def repair_vtables(self):
        """rtti.py ends a vftable at the next COL or non-code pointer, so a vftable followed by a
        code-looking pointer is over-counted. A derived class's vftable is never shorter than its
        base's, so a base longer than every derived class gets truncated."""
        derived_len = collections.defaultdict(list)
        for c in self.classes:
            for off, slots in c.vtables.items():
                for b, m, _ in c.bases:
                    if (off - m) in b.vtables:
                        derived_len[(b.mangled, off - m)].append(len(slots))
                        break
        for (bm, off), lens in derived_len.items():
            b = self.by_mangled[bm]
            if max(lens) < len(b.vtables[off]):
                self.report["vtable_repaired"].append("%s vftable +0x%x: %d slots -> %d (every derived class has <= %d)"
                                                      % (b.name, off, len(b.vtables[off]), max(lens), max(lens)))
                b.vtables[off] = b.vtables[off][:max(lens)]

    # -- units and scopes -------------------------------------------------------------------
    def build_units(self):
        groups = collections.OrderedDict()
        for c in self.classes:
            uid = "::".join(c.parts[:-1] + [c.short])
            groups.setdefault((uid, c.targs is not None), []).append(c)
        self.units = collections.OrderedDict()
        for (uid, is_t), members in groups.items():
            if (uid, not is_t) in groups and is_t:
                self.report["unexpressible"].append("%s is both a template and a plain class" % uid)
            u = Unit(uid, members, is_t)
            if is_t:
                n = len(members[0].targs)
                if any(len(m.targs) != n for m in members):
                    self.report["unexpressible"].append("%s: instantiations with different arity" % uid)
            for m in members:
                m.unit = u
            self.units[uid if not is_t else uid + "<>"] = u
        self.unit_by_uid = {}
        for u in self.units.values():
            self.unit_by_uid.setdefault(u.uid, u)

    def classify_scopes(self):
        """Decide namespace vs enclosing class for every qualifier; assign headers."""
        plain = {u.uid: u for u in self.units.values() if not u.template}
        for u in self.units.values():
            self._place(u.parts, u, plain)
        for u in self.units.values():
            o = u
            while o.outer is not None:
                o = o.outer
            u.ns = o.ns

    def _place(self, parts, u, plain):
        ns, outer = [], None
        for j in range(len(parts) - 1):
            prefix = "::".join(parts[:j + 1])
            if prefix in plain:
                outer = plain[prefix]
                ns = None
            elif outer is not None:
                self.report["unexpressible"].append(
                    "%s: qualifier %s nests inside class %s but has no RTTI" % ("::".join(parts), prefix, outer.uid))
                u.skip = True
            else:
                ns.append(parts[j])
        if outer is not None:
            u.outer = outer
            outer.nested.append(u)
            u.ns = outer.ns
            u.header = outer.header if outer.header else None
        else:
            u.ns = ns
        top = parts[0] if (len(parts) > 1 and parts[0] not in plain) else "global"
        u.header = top
        # nested classes go with their outermost class
        o = u
        while o.outer is not None:
            o = o.outer
        u.header = o.parts[0] if (len(o.parts) > 1) else "global"


    def vt_base(self, c, off):
        """(base Cls, mdisp) whose vtable becomes c's vtable at off, or None (new family)."""
        for b, m, virt in c.bases:
            if (off - m) in b.vtables and not virt:
                return b, m
        return None

    def resolve(self, c, off, i):
        """Slot key (unit uid, slot index) of the class that introduced slot i of c's vtable at off."""
        memo = self._resolve_memo
        k = (c.mangled, off, i)
        if k in memo:
            return memo[k]
        vb = self.vt_base(c, off)
        if vb and i < len(vb[0].vtables[off - vb[1]]):
            r = self.resolve(vb[0], off - vb[1], i)
        else:
            r = (c.unit.uid, i)
        memo[k] = r
        return r

    def analyse_slots(self):
        self._resolve_memo = {}
        self.slot_impls = collections.defaultdict(list)   # key -> [addresses]
        self.slot_pos = {}                                # key -> introducing (Cls, off)
        for c in self.classes:
            c.decl = collections.OrderedDict()   # key -> pure?
            c.new = []                           # keys introduced, in slot order
            c.vt_info = {}                       # off -> [(key, implementer Cls or 'pure')]
            for off in sorted(c.vtables):
                slots = c.vtables[off]
                vb = self.vt_base(c, off)
                bslots = vb[0].vtables[off - vb[1]] if vb else []
                if vb is None and off != 0:
                    self.report["unexpressible"].append(
                        "%s: vftable at +0x%x matches no base vftable" % (c.name, off))
                if vb and len(slots) < len(bslots):
                    self.report["anomaly"].append("%s: vftable +0x%x has %d slots, base %s has %d"
                                                  % (c.name, off, len(slots), vb[0].name, len(bslots)))
                info = []
                for i, a in enumerate(slots):
                    key = self.resolve(c, off, i)
                    self.slot_impls[key].append(a)
                    if i < len(bslots):
                        if a != bslots[i]:
                            c.decl[key] = (a == PURECALL)
                            info.append((key, "pure" if a == PURECALL else c))
                        else:
                            info.append((key, None))  # inherited: filled from base below
                    else:
                        if off != 0:
                            self.report["unexpressible"].append(
                                "%s: secondary vftable +0x%x longer than its base's" % (c.name, off))
                            continue
                        c.new.append(key)
                        c.decl[key] = (a == PURECALL)
                        info.append((key, "pure" if a == PURECALL else c))
                        self.slot_pos.setdefault(key, (c, i))
                c.vt_info[off] = info
        # destructor detection per slot key
        self.dtor = {}
        for key, impls in self.slot_impls.items():
            real = [a for a in set(impls) if a != PURECALL]
            if not real:
                continue
            n = sum(self.code.is_scalar_dtor(a) for a in real)
            if n and n * 2 > len(real):
                self.dtor[key] = True
        # at most one destructor per primary chain
        for c in self.classes:
            ks = [k for k, _ in c.vt_info.get(0, []) if k in self.dtor]
            if len(ks) > 1:
                self.report["anomaly"].append("%s: several destructor-like slots %s; keeping slot %d"
                                              % (c.name, ks, ks[0][1]))
                for k in ks[1:]:
                    self.dtor.pop(k, None)
        # A destructor is implicitly redeclared by every class, so declare it everywhere it appears
        # (pure where the class's own vftable has _purecall in that slot).
        for c in self.classes:
            for off, info in c.vt_info.items():
                for i, (key, impl) in enumerate(info):
                    if key in self.dtor and impl is None:
                        pure = c.vtables[off][i] == PURECALL
                        c.decl[key] = pure
                        info[i] = (key, "pure" if pure else c)

    def cpp_name(self, c):
        """Fully qualified C++ spelling of an RTTI class."""
        if c.targs is None:
            return "::" + c.name
        q = split_top(c.name, "::")
        return "::" + "::".join(q[:-1] + [c.short]) + "< " + ", ".join(render_type(a) for a in c.targs) + " >"

    def full_vt_info(self, c, off):
        """[(key, implementer)] with inherited slots resolved to the base's implementer."""
        out = []
        vb = self.vt_base(c, off)
        binfo = self.full_vt_info(vb[0], off - vb[1]) if vb else []
        for i, (key, impl) in enumerate(c.vt_info.get(off, [])):
            if impl is None and i < len(binfo):
                impl = binfo[i][1]
            out.append((key, impl))
        return out

    def is_abstract(self, c):
        return any(impl == "pure" for off in c.vtables for _, impl in self.full_vt_info(c, off))

    def index(self):
        """class name -> what the probe checks: its header, C++ spelling, mangled name, abstract?, vftables (slot
        counts), slot implementers and RTTI base descriptors."""
        index = {}
        for u in self.units.values():
            if getattr(u, "skip", False):
                continue
            for c in u.members:
                index[c.name] = {
                    "header": u.header + ".h", "unit": u.uid, "template": u.template,
                    "cpp": self.cpp_name(c), "mangled": c.mangled, "abstract": self.is_abstract(c),
                    "layout": c.has_layout,
                    "vtables": {str(off): len(s) for off, s in c.vtables.items()},
                    "slots": {str(off): [[k[0], k[1], (impl if isinstance(impl, str) else impl.name if impl else None)]
                                         for k, impl in self.full_vt_info(c, off)] for off in c.vtables},
                    "bases": [[b.name, m, p, v, a] for b, m, p, v, a in c.all_bases],
                }
        return index


# ---------------------------------------------------------------------------------------------
# Constructors the headers declare out of line (the probe defines them, so the class's vftable lands in its object)

NS_OPEN = re.compile(r"\bnamespace (\w+) \{")
CLASS_OPEN = re.compile(r"^(?:template\s*<.*>\s*)?(?:class|struct|union)\s+([\w:]+)\b[^;]*$")


def declared_ctors(text):
    """{qualified class name: [parameter list text]} for the constructors declared (not defined) in the plain
    classes of a header: `    X(P...);` inside `class X ... {` ... `};`. Templates are skipped."""
    out = collections.defaultdict(list)
    ns, cls, tmpl = [], None, False
    cond = []   # (gx2) `#if defined(X)` regions: the probe defines no X, so `#if defined` is off, `#if !defined` on
    for line in text.split("\n"):
        pp = re.match(r"\s*#\s*(if|ifdef|ifndef|else|endif)\b(.*)", line)
        if pp:
            d, rest = pp.group(1), pp.group(2)
            if d in ("if", "ifdef", "ifndef"):
                neg = d == "ifndef" or bool(re.match(r"\s*!\s*defined", rest))
                cond.append(neg if (d != "if" or "defined" in rest) else True)
            elif d == "else" and cond:
                cond[-1] = not cond[-1]
            elif d == "endif" and cond:
                cond.pop()
            continue
        if not all(cond):
            continue
        s = line.split("//")[0]
        if cls is None:
            if s.startswith("namespace "):
                ns.extend(NS_OPEN.findall(s))
                continue
            if s.startswith("}") and line.split("//")[-1].strip().startswith("namespace"):
                del ns[len(ns) - s.count("}"):]
                continue
            if s.startswith("template"):
                tmpl = True
                if not CLASS_OPEN.match(s):
                    continue
            m = CLASS_OPEN.match(s)
            if m and s.rstrip().endswith("{"):
                cls = (ns + split_top(m.group(1), "::"), tmpl)
            elif not s.startswith("template"):
                tmpl = False
            continue
        if s.startswith("};"):
            cls, tmpl = None, False
            continue
        if cls[1]:
            continue
        short = split_template(cls[0][-1])[0]
        m = re.match(r"^\s+(?:explicit\s+)?%s\s*\((.*)\)\s*;" % re.escape(short), s)
        if m:
            params = [re.sub(r"\s*=.*$", "", p).strip() for p in split_top(m.group(1), ",") if p.strip()]
            out["::".join(cls[0])].append(params)
    return dict(out)


# ---------------------------------------------------------------------------------------------
# Probe: compile each header with cl 13.10 and check layouts against RTTI

def run_cl(src_dir, src, flags, obj, include=None):
    env = dict(os.environ, INCLUDE=os.path.join(MSVC, "Include") + ";" + (include or os.path.join(ROOT, "include")))
    cmd = [WIBO, os.path.join(MSVC, "Bin/cl.exe"), "/nologo"] + flags + ["/Fo" + obj, src]
    r = subprocess.run(cmd, env=env, capture_output=True, text=True, cwd=src_dir)
    return r.returncode == 0 and os.path.exists(obj), (r.stdout + r.stderr)


def mangled_num(s, i):
    """Decode an MSVC-mangled number at s[i:] -> (value, new index)."""
    neg = s[i] == "?"
    if neg:
        i += 1
    if s[i].isdigit():
        return (-(int(s[i]) + 1) if neg else int(s[i]) + 1), i + 1
    v = 0
    while s[i] != "@":
        v = v * 16 + ord(s[i]) - ord("A")
        i += 1
    return (-v if neg else v), i + 1



def load_sizes(path=SIZES_PATH):
    return json.load(open(path))["sizes"] if os.path.exists(path) else {}


TMP_DIR = os.path.join(ROOT, "build/tmp")


def check_keep(keep):
    """--keep must not put probe files into the tracked tree: under build/ or outside the checkout only."""
    k = os.path.abspath(keep)
    inside = os.path.commonpath([k, ROOT]) == ROOT
    if inside and os.path.commonpath([k, os.path.join(ROOT, "build")]) != os.path.join(ROOT, "build"):
        raise SystemExit("--keep %s: the probe writes nothing into the checkout; use a directory under build/" % keep)
    return k


def probe(headers=None, keep=None, sizes="load", include=None):
    """Compile each header alone, then one layout TU per header that constructs every RTTI class placed there
    (abstract ones through a derived probe class) and check the object. sizes: {class: sizeof} to compare with
    (default "load": config/gen-sizes.json; None: record only). INCLUDE: the include/ directory whose gen/ is probed
    (default the checkout's). The work files go to a fresh directory under build/tmp/ (KEEP: that directory instead,
    kept). Returns (counts, problems, work dir if kept, {class: sizeof seen})."""
    sys.path.insert(0, os.path.dirname(__file__))
    from compare import Coff
    inc = os.path.abspath(include or os.path.dirname(OUT_DIR))
    gen_dir = os.path.join(inc, "gen")
    index = Model().index()
    sizes = load_sizes() if sizes == "load" else sizes
    ctors = {}
    for f in os.listdir(gen_dir):
        if f.endswith(".h"):
            for k, v in declared_ctors(open(os.path.join(gen_dir, f)).read()).items():
                ctors.setdefault(k, v)
    allh = sorted(f[:-2] for f in os.listdir(gen_dir) if f.endswith(".h") and f not in ("all.h", "_prelude.h"))
    headers = headers or allh
    if keep:
        work = check_keep(keep)
        tmp = None
    else:
        os.makedirs(TMP_DIR, exist_ok=True)
        tmp = tempfile.TemporaryDirectory(prefix="genprobe-", dir=TMP_DIR)
        work = tmp.name
    os.makedirs(work, exist_ok=True)
    total = collections.Counter()
    problems = []
    seen = {}
    for h in headers:
        # 1) the header alone, with the project flags
        src = "hdr_%s.cpp" % h
        with open(os.path.join(work, src), "w") as f:
            f.write('#include <gen/%s.h>\n' % h)
        ok, out = run_cl(work, src, ["/c", "/O2", "/GR", "/GX-"], os.path.join(work, "hdr_%s.obj" % h), inc)
        total["headers"] += 1
        total["headers_ok"] += ok
        if not ok:
            problems.append("%s.h: does not compile:\n%s" % (h, "\n".join(out.splitlines()[:15])))
            continue
        # 2) layout probe: construct every class so its vftables and RTTI land in the object (all.h: a class that
        # moved to another header is still found)
        classes = [(n, e) for n, e in sorted(index.items()) if e["header"] == h + ".h" and e["layout"]]
        if not classes:
            continue
        lines = ['#include <gen/all.h>', "void* operator new(unsigned int);"]
        for k, (n, e) in enumerate(classes):
            # constructors the header declares out of line: defined here, so the class's vftable lands in this object
            for params in ([] if e["template"] else ctors.get(e["cpp"][2:], ())):
                lines.append("%s::%s(%s) {}" % (e["cpp"], re.sub(r"^.*::", "", e["cpp"]), ", ".join(params)))
            if not e["abstract"]:
                lines.append("unsigned probe_sz_%d() { return sizeof(%s); }" % (k, e["cpp"]))
            lines.append("void* probe_%d() { return new %s; }" % (k, e["cpp"]) if not e["abstract"] else
                         "struct Probe_%d : %s { Probe_%d(); }; Probe_%d::Probe_%d() {}" % (k, e["cpp"], k, k, k))
        src = "lay_%s.cpp" % h
        with open(os.path.join(work, src), "w") as f:
            f.write("\n".join(lines) + "\n")
        obj = os.path.join(work, "lay_%s.obj" % h)
        ok, out = run_cl(work, src, ["/c", "/Od", "/GR", "/GX-"], obj, inc)
        if not ok:
            problems.append("%s.h: layout probe does not compile:\n%s" % (h, "\n".join(out.splitlines()[:15])))
            continue
        res = check_layout(Coff(obj), classes, index, sizes, seen)
        for k, v in res[0].items():
            total[k] += v
        problems += res[1]
    if tmp:
        tmp.cleanup()
    return total, problems, (work if keep else None), seen


def check_layout(coff, classes, index, sizes, seen):
    syms = {s[0]: s for s in coff.symbols}
    vt_names = [n for n in syms if n.startswith("??_7")]
    cnt = collections.Counter()
    probs = []
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for k, (n, e) in enumerate(classes):
        scope = e["mangled"][4:]
        cnt["classes"] += 1
        bad = []
        # vftables: ??_7<scope>6B@ (primary) / ??_7<scope>6B<base scope>@ (secondary)
        for off, nslots in e["vtables"].items():
            off = int(off)
            # single inheritance: ??_7X6B@; multiple: ??_7X6B<base at that offset>@
            # (the qualifier may use name back-references, so compare its first identifier)
            pre = "??_7%s6B" % scope
            quals = {index[b]["mangled"][4:].split("@")[0] for b, m, p, v, a in e["bases"] if m == off}
            vname = pre + "@" if off == 0 and pre + "@" in syms else None
            if vname is None:
                vname = next((n for n in vt_names if n.startswith(pre) and n[len(pre):].split("@")[0] in quals), None)
            s = syms.get(vname) if vname else None
            if s is None:
                if not (len(e["vtables"]) == 1 and off == 0):
                    pass
                bad.append("vftable +0x%x not emitted (%s)" % (off, vname))
                continue
            _, raw, relocs = coff.sections[s[2] - 1]
            got = (len(raw) - s[1]) // 4
            if got != nslots:
                bad.append("vftable +0x%x: %d slots, RTTI says %d" % (off, got, nslots))
            else:
                cnt["vftables_ok"] += 1
            # implementers
            exp = e["slots"][str(off)]
            rel = {va: coff.by_index[si][0] for va, si, _ in relocs}
            for i, (kuid, kslot, impl) in enumerate(exp[:got]):
                tgt = rel.get(s[1] + 4 * i, "")
                if impl == "pure":
                    okk = tgt == "__purecall"
                elif impl is None:
                    okk = True
                else:
                    iscope = index[impl]["mangled"][4:]
                    okk = iscope in tgt or bool(re.search(r"@\d", tgt))
                cnt["slots"] += 1
                if okk:
                    cnt["slots_ok"] += 1
                else:
                    bad.append("slot +0x%x[%d] -> %s, expected implementer %s" % (off, i, tgt, impl))
        # base class array ??_R2<scope>8 -> ??_R1 entries
        r2 = syms.get("??_R2%s8" % scope)
        if r2 is not None:
            _, raw, relocs = coff.sections[r2[2] - 1]
            got = []
            for va, si, _ in sorted(relocs):
                nm = coff.by_index[si][0]
                if nm.startswith("??_R1"):
                    i = 5
                    vals = []
                    for _ in range(4):
                        v, i = mangled_num(nm, i)
                        vals.append(v)
                    got.append((nm[i:-1], vals[0], vals[1], vals[2]))
            want = [(".?AV".join([""]) + index[b]["mangled"][4:], m, p, v) for b, m, p, v, a in e["bases"]]
            want = [(index[b]["mangled"][4:], m, p, v) for b, m, p, v, a in e["bases"]]
            if got[1:] != want:
                bad.append("base descriptors differ: got %s want %s" % (got[1:], want))
            else:
                cnt["bases_ok"] += 1
        else:
            bad.append("no RTTI base array emitted")
        # sizeof: `new X` pushes the size before calling operator new
        if not e["abstract"]:
            # (`unsigned probe_sz_K() { return sizeof(X); }`: `mov eax, N`; with an out-of-line constructor `new X`
            # sets up an EH frame first, so its first push is not the size)
            fs = syms.get("?probe_sz_%d@@YAIXZ" % k)
            if fs is not None:
                _, raw, _ = coff.sections[fs[2] - 1]
                mov = next((i for i in md.disasm(raw[fs[1]:fs[1] + 16], 0) if i.mnemonic == "mov" and i.op_str.startswith("eax, ")), None)
                got = int(mov.op_str[5:], 0) if mov else None
                seen[n] = got
                if sizes is None:
                    cnt["sizes_recorded"] += 1
                elif n not in sizes:
                    bad.append("sizeof %s, no recorded size (config/gen-sizes.json: --probe --update-sizes)" % got)
                elif got != sizes[n]:
                    bad.append("sizeof %s, recorded %s (an intended change: --probe --update-sizes)" % (got, sizes[n]))
                else:
                    cnt["sizes_ok"] += 1
        if bad:
            probs.append("%s: %s" % (n, "; ".join(bad)))
        else:
            cnt["classes_ok"] += 1
    return cnt, probs


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--probe", nargs="*", metavar="HEADER", help="compile and layout-check headers (default: all)")
    ap.add_argument("--update-sizes", action="store_true",
                    help="with --probe (all headers): record the sizes the probe saw in config/gen-sizes.json")
    ap.add_argument("--keep", help="probe work directory to keep")
    a = ap.parse_args(argv)
    if a.probe is None:
        ap.error("include/gen/ is hand-maintained source (gen1, 2026-11-13); this tool only checks it: --probe")
    if a.update_sizes and a.probe:
        ap.error("--update-sizes records every class: run it with --probe and no header list")
    total, problems, work, seen = probe(a.probe or None, a.keep, sizes=None if a.update_sizes else "load")
    if a.update_sizes:
        with open(SIZES_PATH, "w") as f:
            json.dump({"_comment": "sizeof of every concrete RTTI class in include/gen/ as MSVC 7.1 lays it out "
                                   "(32-bit), recorded by tools/gen_headers.py --probe --update-sizes; the probe "
                                   "checks the headers against it (docs/headers.md)",
                       "sizes": dict(sorted(seen.items()))}, f, indent=0, sort_keys=False)
            f.write("\n")
        print("recorded %d sizes in %s" % (len(seen), os.path.relpath(SIZES_PATH, ROOT)))
    for p in problems:
        print(p)
    print(dict(total))
    if work:
        print("work dir:", work)
    return 0 if not problems and total["headers"] == total["headers_ok"] else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
