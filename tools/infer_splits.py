#!/usr/bin/env python3
"""Infer object-file (translation unit) ranges in .text from link order -> config/splits.json, docs/splits.md.

  build/venv/bin/python tools/infer_splits.py            # write config/splits.json and docs/splits.md
  build/venv/bin/python tools/infer_splits.py --stats    # print the summary only

Method (docs/splits.md has the long version):

1. Library regions are fixed: the three XDK/CRT spans inside .text (tools/packet.py LIB_SPANS) and every
   executable section after .text (BINK*, D3D, XGRPH, DSOUND, XPP). They become `library` objects.
   `.text$yc/$yd` (dynamic initializers and atexit thunks, 0x35be88..0x364840) becomes `game-init` objects.
2. In game code, each RTTI-named function (`Class::vfunc_N`) is labelled with its owning class. Template
   instantiations (`fight::ParamBool<X>`, `Method1<...>`) are COMDATs placed by the linker; they get no
   label of their own.
3. A class's functions are clustered by address (a new cluster starts after a long gap). The largest
   cluster is the class's home; a small far-away cluster (<= 2 functions, < 300 bytes) is a COMDAT stray
   (inline virtual destructor or getter emitted in whatever object used it first) and is unlabelled too.
4. Every remaining cluster is a span [first, last]. Overlapping spans are unioned into one object core
   (classes that interleave in address order were compiled from one file).
5. Unnamed functions between two cores are cut between them by call-graph affinity (direct calls and
   address-taken references, propagated through the gap). Long runs that have no affinity to either side
   become their own objects, cut where no call edge crosses.
6. Each object is named after its dominant class (most bytes) with one directory per namespace.

Only addresses and names are written; no game bytes.
"""
import argparse
import bisect
import collections
import csv
import hashlib
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xbe import Xbe  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
FUNCS_CSV = os.path.join(ROOT, "build/functions.csv")
RTTI_JSON = os.path.join(ROOT, "build/rtti.json")
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
CACHE_DIR = os.path.join(ROOT, "build/tree-cache")
OUT_JSON = os.path.join(ROOT, "config/splits.json")
OUT_MD = os.path.join(ROOT, "docs/splits.md")

TEXT_START = 0x11000
GAME_TEXT_END = 0x364840          # end of .text (tools/packet.py)
INIT_START = 0x35BE88             # .text$yc/.text$yd: dynamic initializers + atexit thunks of game TUs
LIB_SPANS = [                     # docs/platform-boundary.md "Where library code lives"
    (0x208B9C, 0x212BB0, "xapilib", "XAPILIB and xboxkrnl jump stubs"),
    (0x3440E0, 0x356BF0, "libcmt_xapi", "LIBCMT plus more XAPILIB"),
    (0x35A7B0, 0x35BE88, "libcmt_eh", "LIBCMT EH runtime, itoa, 64-bit helpers"),
]
LIB_PREFIXES = ("XAPILIB::", "D3D8::", "xboxkrnl.exe::", "DSOUND::", "XGRAPHC::", "LIBCMT::")

# Clustering / cutting parameters (see docs/splits.md "Parameters").
CLUSTER_GAP_BYTES = 0x3000        # a class's next function this far away starts a new cluster ...
CLUSTER_GAP_CLASSES = 12          # ... or after this many distinct other classes in between
STRAY_MAX_FUNCS = 2               # a non-home cluster this small is a COMDAT stray
STRAY_MAX_BYTES = 300
MID_MIN_FUNCS = 8                 # an unattached run at least this long becomes its own object(s)
MID_MIN_SEG = 6                   # pieces of an unattached run are at least this long
PROPAGATE_ROUNDS = 4              # affinity propagation through gap-internal call edges
PROPAGATE_DECAY = 0.5


# ---------------------------------------------------------------------------------------------
# Inputs
def split_top(name):
    """Split a qualified name at '::' outside template brackets."""
    parts, cur, depth, i = [], "", 0, 0
    while i < len(name):
        c = name[i]
        if c == "<":
            depth += 1
        elif c == ">":
            depth -= 1
        if depth == 0 and name.startswith("::", i):
            parts.append(cur)
            cur = ""
            i += 2
            continue
        cur += c
        i += 1
    parts.append(cur)
    return parts


def load_functions():
    rows = []
    with open(FUNCS_CSV) as f:
        for r in csv.DictReader(f):
            rows.append((int(r["address"], 16), int(r["size"]), r["name"], r["is_thunk"] == "1"))
    rows.sort()
    return rows


def owner_class(name):
    """RTTI class owning a named method, or None (FUN_, thunks, library names)."""
    if "::" not in name or name.startswith(LIB_PREFIXES) or name.startswith("FID_"):
        return None
    parts = split_top(name)
    if len(parts) < 2:
        return None
    return "::".join(parts[:-1])


def is_template(cls):
    return "<" in cls


PRIMITIVE = re.compile(r"^(const_|unsigned_|signed_)*(void|bool|char|short|int|long|float|double|__int64)\b")


def template_label(cls):
    """Label for a template instantiation: its first class-like template argument.

    `Method2<CActorManager,void,...>` (a script binding) -> CActorManager,
    `fight::ParamBool<hulkfight::DialogueTrack>` -> hulkfight::DialogueTrack. The instantiation is a COMDAT
    placed in the first object that used it, which for these families is the argument's own file.
    """
    m = re.search(r"<\s*(?:class |struct |enum )?([A-Za-z_][\w:]*)", cls)
    if not m or PRIMITIVE.match(m.group(1)) or m.group(1) in ("math::Vector",):
        return None
    return m.group(1)


def load_vtables():
    """class name (functions.csv spelling) -> [vtable addresses]."""
    rtti = json.load(open(RTTI_JSON))
    out = {}
    for c in rtti["classes"]:
        if not c.get("name"):
            continue
        name = re.sub(r"\b(class|struct|enum|union) ", "", c["name"])
        out[name] = sorted(v["address"] for v in c.get("vtables", []))
    return out


def call_graph(funcs):
    """{caller: set(callee)} from direct calls/jumps and address-taken function addresses. Cached."""
    os.makedirs(CACHE_DIR, exist_ok=True)
    h = hashlib.sha1()
    for p in (FUNCS_CSV, XBE_PATH):
        st = os.stat(p)
        h.update(("%s:%d:%d" % (p, st.st_size, int(st.st_mtime))).encode())
    cache = os.path.join(CACHE_DIR, "callgraph-%s.json" % h.hexdigest()[:12])
    if os.path.exists(cache):
        raw = json.load(open(cache))
        return {int(k): set(v) for k, v in raw.items()}
    import capstone
    xbe = Xbe(XBE_PATH)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    starts = {a for a, _, _, _ in funcs}
    edges = {}
    for a, size, _, _ in funcs:
        if a >= GAME_TEXT_END:
            continue
        o = xbe.offset(a)
        if o is None:
            continue
        out = set()
        for ins in md.disasm(xbe.data[o:o + size], a):
            for op in ins.operands:
                v = None
                if op.type == capstone.x86.X86_OP_IMM:
                    v = op.imm & 0xFFFFFFFF
                elif op.type == capstone.x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
                    v = op.mem.disp & 0xFFFFFFFF
                if v is not None and v in starts and v != a:
                    out.add(v)
        edges[a] = out
    json.dump({str(k): sorted(v) for k, v in sorted(edges.items())}, open(cache, "w"))
    return edges


# ---------------------------------------------------------------------------------------------
# Naming
def class_path(cls, known=()):
    """'hulkfight::motion::HitDamageTrack' -> ('hulkfight/motion', 'HitDamageTrack').

    A nested class (`CDisplayEffect::Fader`) goes into its outermost enclosing class's file name: a
    qualifier that is itself a known class is not a namespace."""
    parts = split_top(cls)
    for i in range(1, len(parts)):
        if "::".join(parts[:i]) in known:
            parts = parts[:i]
            break
    ns = [p for p in parts[:-1]]
    base = re.sub(r"[^A-Za-z0-9_]+", "_", parts[-1]).strip("_") or "anon"
    return ("/".join(ns) if ns else "global"), base


def namespace_of(cls):
    parts = split_top(cls)
    return parts[0] if len(parts) > 1 else "global"


# ---------------------------------------------------------------------------------------------
# Inference
class Inferrer:
    def __init__(self):
        self.funcs = load_functions()
        self.addr_index = {f[0]: i for i, f in enumerate(self.funcs)}
        self.vtables = load_vtables()
        self.known_classes = set(self.vtables)
        for _, _, name, _ in self.funcs:
            c = owner_class(name)
            if c:
                self.known_classes.add(c)
        self.edges = call_graph(self.funcs)
        self.undirected = collections.defaultdict(set)
        for a, outs in self.edges.items():
            for b in outs:
                self.undirected[a].add(b)
                self.undirected[b].add(a)
        self.objects = []
        self.stats = collections.Counter()
        self.strays = []          # (addr, name, class, home object start) for the report

    # -- regions -------------------------------------------------------------------------------
    def library_objects(self):
        xbe = Xbe(XBE_PATH)
        objs = []
        for start, end, tag, what in LIB_SPANS:
            objs.append(dict(start=start, end=end, file="library/%s.obj" % tag, kind="library",
                             confidence="high", evidence=["docs/platform-boundary.md: " + what]))
        for s in xbe.sections:
            if s.executable and s.va >= GAME_TEXT_END and s.vsize:
                tag = re.sub(r"[^A-Za-z0-9_]+", "_", s.name).strip("_").lower()
                objs.append(dict(start=s.va, end=s.va + s.vsize, file="library/%s.obj" % tag, kind="library",
                                 confidence="high", evidence=["XBE section %s (XDK/Bink library)" % s.name]))
        return objs

    def game_regions(self):
        """Contiguous game-code address ranges (between library spans), excluding .text$yc."""
        out, cur = [], TEXT_START
        for start, end, _, _ in LIB_SPANS:
            out.append((cur, min(start, INIT_START)))
            cur = end
        if cur < INIT_START:
            out.append((cur, INIT_START))
        return [(a, b) for a, b in out if b > a]

    # -- one game region -------------------------------------------------------------------------
    def infer_region(self, lo, hi):
        fs = [f for f in self.funcs if lo <= f[0] < hi]
        n = len(fs)
        if not n:
            return []
        labels = [None] * n
        tmpl = [None] * n
        for i, (a, size, name, thunk) in enumerate(fs):
            c = owner_class(name)
            if c is None:
                continue
            if is_template(c):
                tmpl[i] = c
                labels[i] = template_label(c)
            else:
                labels[i] = c
        # clusters per class
        occ = collections.defaultdict(list)
        for i, c in enumerate(labels):
            if c:
                occ[c].append(i)
        clusters = []                  # (class, [indices])
        for c, idx in occ.items():
            cur = [idx[0]]
            for j in idx[1:]:
                prev = cur[-1]
                gap_bytes = fs[j][0] - (fs[prev][0] + fs[prev][1])
                others = {labels[k] for k in range(prev + 1, j) if labels[k] and labels[k] != c}
                if gap_bytes > CLUSTER_GAP_BYTES or len(others) > CLUSTER_GAP_CLASSES:
                    clusters.append((c, cur))
                    cur = [j]
                else:
                    cur.append(j)
            clusters.append((c, cur))
        by_class = collections.defaultdict(list)
        for c, idx in clusters:
            by_class[c].append(idx)
        spans = []
        stray_of = {}
        for c, cl in by_class.items():
            home = max(cl, key=lambda ix: (sum(fs[k][1] for k in ix), len(ix), -ix[0]))
            for ix in cl:
                nbytes = sum(fs[k][1] for k in ix)
                if ix is not home and len(ix) <= STRAY_MAX_FUNCS and nbytes < STRAY_MAX_BYTES:
                    for k in ix:
                        stray_of[k] = (c, fs[home[0]][0])
                    continue
                spans.append((ix[0], ix[-1], c))
        for k in stray_of:
            labels[k] = None
        self.stats["stray_functions"] += len(stray_of)
        self.stats["template_functions"] += sum(1 for t in tmpl if t)
        # union overlapping spans into cores
        spans.sort()
        cores = []
        for s, e, c in spans:
            if cores and s <= cores[-1][1]:
                cores[-1][1] = max(cores[-1][1], e)
                cores[-1][2].add(c)
            else:
                cores.append([s, e, {c}])
        # assign every function index to an object
        owner = [None] * n          # object id
        objects = []                # dict(lo, hi, classes, how)
        for s, e, cs in cores:
            oid = len(objects)
            objects.append(dict(lo=s, hi=e, classes=cs, how="core", cuts=[]))
            for k in range(s, e + 1):
                owner[k] = oid
        # gaps: before first core, between cores, after last core
        self.region_index = {f[0]: k for k, f in enumerate(fs)}
        gap_list = []
        prev_end, prev_obj = -1, None
        for i, o in enumerate(objects):
            gap_list.append((prev_end + 1, o["lo"], prev_obj, i))
            prev_end, prev_obj = o["hi"], i
        gap_list.append((prev_end + 1, n, prev_obj, None))
        new_objects = []
        for g0, g1, left, right in gap_list:
            if g1 <= g0:
                continue
            assign = self.cut_gap(fs, g0, g1, left, right, owner, stray_of)
            for k, tgt in assign.items():
                if isinstance(tgt, int):
                    owner[k] = tgt
            # middle pieces
            mids = sorted({tgt for tgt in assign.values() if isinstance(tgt, tuple)})
            for m in mids:
                ks = sorted(k for k, t in assign.items() if t == m)
                oid = len(objects) + len(new_objects)
                new_objects.append(dict(lo=ks[0], hi=ks[-1], classes=set(), how="unattached", cuts=[]))
                for k in ks:
                    owner[k] = oid
        objects += new_objects
        # rebuild contiguous objects in address order
        out = []
        cur = None
        for k in range(n):
            oid = owner[k]
            if cur is None or cur["oid"] != oid:
                cur = dict(oid=oid, idx=[])
                out.append(cur)
            cur["idx"].append(k)
        # an object id appearing in two places would be a bug in cut_gap
        seen = collections.Counter(o["oid"] for o in out)
        assert all(v == 1 for v in seen.values()), "non-contiguous object"
        res = []
        for piece in out:
            o = objects[piece["oid"]]
            idx = piece["idx"]
            res.append(self.describe(fs, idx, o, labels, tmpl, stray_of, hi))
        return res

    def affinity(self, fs, g0, g1, owner, side_obj, stray_of):
        """Affinity of each gap function to object side_obj, propagated through gap-internal edges."""
        if side_obj is None:
            return [0.0] * (g1 - g0)
        addrs = self.region_index
        aff = []
        for k in range(g0, g1):
            if k in stray_of:
                aff.append(0.0)
                continue
            a = fs[k][0]
            aff.append(float(sum(1 for b in self.undirected.get(a, ()) if b in addrs and owner[addrs[b]] == side_obj)))
        base = list(aff)
        gap_pos = {fs[k][0]: k - g0 for k in range(g0, g1)}
        for _ in range(PROPAGATE_ROUNDS):
            nxt = list(base)
            for i, k in enumerate(range(g0, g1)):
                if k in stray_of:
                    continue
                s = 0.0
                for b in self.undirected.get(fs[k][0], ()):
                    j = gap_pos.get(b)
                    if j is not None and j != i:
                        s += aff[j]
                nxt[i] += PROPAGATE_DECAY * s
            aff = nxt
        return aff

    def cut_gap(self, fs, g0, g1, left, right, owner, stray_of):
        """Assign gap indices [g0, g1) to left/right object ids, or to ('mid', n) middle pieces."""
        aL = self.affinity(fs, g0, g1, owner, left, stray_of)
        aR = self.affinity(fs, g0, g1, owner, right, stray_of)
        m = g1 - g0
        # attached extents: left keeps a prefix, right a suffix
        lastL = max([i for i in range(m) if aL[i] > aR[i]] or [-1])
        firstR = min([i for i in range(m) if aR[i] > aL[i]] or [m])
        if left is None:
            lastL = -1
        if right is None:
            firstR = m
        assign = {}
        if lastL < firstR:
            # clean: [0, lastL] left, [firstR, m) right, ambiguous middle in between
            amb0, amb1 = lastL + 1, firstR
        else:
            # interleaved affinities: best single cut
            best, bp = None, 0
            prefL = [0.0]
            for i in range(m):
                prefL.append(prefL[-1] + aL[i] - aR[i])
            for p in range(m + 1):
                if best is None or prefL[p] > best:
                    best, bp = prefL[p], p
            amb0 = amb1 = bp
            self.stats["interleaved_gaps"] += 1
        for i in range(amb0):
            assign[g0 + i] = left
        for i in range(amb1, m):
            assign[g0 + i] = right
        amb = list(range(amb0, amb1))
        if not amb:
            return assign
        if len(amb) < MID_MIN_FUNCS and (left is not None or right is not None):
            # short ambiguous run: static helpers precede their users, so it starts the next file
            tgt = right if right is not None else left
            for i in amb:
                assign[g0 + i] = tgt
            return assign
        # long unattached run: own objects, cut where no call edge crosses
        pieces = self.split_unattached(fs, [g0 + i for i in amb])
        for p in pieces:
            key = ("mid", p[0])
            for k in p:
                assign[k] = key
        return assign

    def split_unattached(self, fs, ks):
        pos = {fs[k][0]: i for i, k in enumerate(ks)}
        # crossing[i] = number of edges between ks[:i] and ks[i:]
        span_end = list(range(len(ks)))
        for i, k in enumerate(ks):
            for b in self.undirected.get(fs[k][0], ()):
                j = pos.get(b)
                if j is not None:
                    lo, hi = min(i, j), max(i, j)
                    span_end[lo] = max(span_end[lo], hi)
        cuts = []
        reach = -1
        for i in range(len(ks)):
            reach = max(reach, span_end[i])
            if reach == i and i + 1 < len(ks):
                cuts.append(i + 1)
        segs, start = [], 0
        for c in cuts + [len(ks)]:
            segs.append(ks[start:c])
            start = c
        merged = []
        for s in segs:
            if merged and (len(merged[-1]) < MID_MIN_SEG or len(s) < MID_MIN_SEG):
                merged[-1] = merged[-1] + s
            else:
                merged.append(s)
        if len(merged) > 1 and len(merged[-1]) < MID_MIN_SEG:
            merged[-2] += merged.pop()
        return merged

    def describe(self, fs, idx, o, labels, tmpl, stray_of, region_hi):
        start = fs[idx[0]][0]
        nxt = idx[-1] + 1
        end = fs[nxt][0] if nxt < len(fs) else region_hi
        cls_bytes = collections.Counter()
        cls_funcs = collections.Counter()
        for k in idx:
            if labels[k]:
                cls_bytes[labels[k]] += fs[k][1]
                cls_funcs[labels[k]] += 1
        tmpl_args = collections.Counter()
        for k in idx:
            if tmpl[k]:
                for arg in re.findall(r"[<,]\s*([A-Za-z_][\w:]*)", tmpl[k]):
                    if arg in self.vtables or "::" in arg:
                        tmpl_args[arg] += 1
        strays = [dict(addr="0x%08x" % fs[k][0], name=fs[k][2], home="0x%08x" % stray_of[k][1])
                  for k in idx if k in stray_of]
        named = sum(cls_funcs.values())
        evidence = []
        if cls_bytes:
            dom = max(cls_bytes, key=lambda c: (cls_bytes[c], c))
            d, base = class_path(dom, self.known_classes)
            evidence.append("classes: " + ", ".join("%s (%d fn)" % (c, cls_funcs[c])
                                                     for c, _ in cls_bytes.most_common(6))
                            + (" +%d more" % (len(cls_bytes) - 6) if len(cls_bytes) > 6 else ""))
        else:
            dom = None
            d, base = self.unnamed_dir(fs, idx), "unk_%06x" % start
            if tmpl_args:
                arg = tmpl_args.most_common(1)[0][0]
                evidence.append("only template instantiations/unnamed functions; template args: %s" % arg)
        vt = sorted(v for c in cls_bytes for v in self.vtables.get(c, []))
        if vt:
            evidence.append("vtables 0x%x..0x%x (%d)" % (vt[0], vt[-1], len(vt)))
        if strays:
            evidence.append("%d COMDAT stray(s) from other classes' homes" % len(strays))
        # confidence
        if o["how"] == "core" and named >= 3:
            conf = "high"
        elif o["how"] == "core":
            conf = "medium"
        else:
            conf = "low"
            evidence.append("unattached run: no call affinity to neighbouring objects")
        return dict(start=start, end=end, file="%s/%s.cpp" % (d, base), kind="game", confidence=conf,
                    dominant=dom, functions=len(idx), named=named, bytes=end - start,
                    evidence=evidence, comdat=strays, vtables=vt)

    def unnamed_dir(self, fs, idx):
        """Directory for an object without named functions: majority namespace of its call partners."""
        votes = collections.Counter()
        for k in idx:
            for b in self.undirected.get(fs[k][0], ()):
                j = self.addr_index.get(b)
                if j is None:
                    continue
                c = owner_class(self.funcs[j][2])
                if c and not is_template(c):
                    votes[namespace_of(c)] += 1
        if votes:
            ns, v = votes.most_common(1)[0]
            if v >= 3 and v >= 0.6 * sum(votes.values()):
                return ns
        return "unknown"

    # -- init region -----------------------------------------------------------------------------
    def init_objects(self):
        fs = [f for f in self.funcs if INIT_START <= f[0] < GAME_TEXT_END]
        # One file per contiguous run; the initializers belong to the TUs whose globals they construct,
        # which this pass does not try to recover (see docs/splits.md weak spots).
        return [dict(start=INIT_START, end=GAME_TEXT_END, file="init/dynamic_initializers.cpp", kind="game-init",
                     confidence="low", dominant=None, functions=len(fs), named=0, bytes=GAME_TEXT_END - INIT_START,
                     evidence=[".text$yc/.text$yd: dynamic initializers and atexit thunks of game TUs "
                               "(docs/platform-boundary.md); per-TU ownership not recovered"],
                     comdat=[], vtables=[])]

    # -- all ------------------------------------------------------------------------------------
    def run(self):
        objs = []
        for lo, hi in self.game_regions():
            objs += self.infer_region(lo, hi)
        objs += self.init_objects()
        objs += self.library_objects()
        objs.sort(key=lambda o: o["start"])
        # unique file names
        seen = collections.Counter()
        for o in objs:
            seen[o["file"]] += 1
        dup = collections.Counter()
        for o in objs:
            f = o["file"]
            if seen[f] > 1:
                dup[f] += 1
                if dup[f] > 1:
                    stem, ext = os.path.splitext(f)
                    o["file"] = "%s_%d%s" % (stem, dup[f], ext)
                    o["evidence"].append("same dominant class as an earlier object (class split across files)")
        self.vtable_order_check(objs)
        self.objects = objs
        return objs

    def vtable_order_check(self, objs):
        """Evidence only: .rdata vtables should follow .text object order (both are in link order)."""
        game = [o for o in objs if o["kind"] == "game" and o.get("vtables")]
        ok = bad = 0
        for a, b in zip(game, game[1:]):
            if max(a["vtables"]) < min(b["vtables"]):
                ok += 1
            elif min(a["vtables"]) > max(b["vtables"]):
                bad += 1
                b["evidence"].append("vtables precede the previous object's in .rdata (order inverted)")
            else:
                bad += 1
                b["evidence"].append("vtable range overlaps the previous object's (may be one file)")
        self.stats["vtable_pairs_ordered"] = ok
        self.stats["vtable_pairs_unordered"] = bad


# ---------------------------------------------------------------------------------------------
# Output
def to_json(objs):
    out = []
    for o in objs:
        r = {"start": "0x%08x" % o["start"], "end": "0x%08x" % o["end"], "file": o["file"], "kind": o["kind"],
             "confidence": o["confidence"], "evidence": o["evidence"]}
        for k in ("dominant", "functions", "named"):
            if k in o and o[k] is not None:
                r[k] = o[k]
        if o.get("comdat"):
            r["comdat"] = o["comdat"]
        out.append(r)
    return {"comment": "Generated by tools/infer_splits.py: inferred object ranges in .text (link order). "
                       "end is exclusive. See docs/splits.md.",
            "objects": out}


def write_md(inf, objs):
    game = [o for o in objs if o["kind"] == "game"]
    lib = [o for o in objs if o["kind"] == "library"]
    conf = collections.Counter(o["confidence"] for o in game)
    dirs = collections.Counter(o["file"].split("/")[0] for o in game)
    st = inf.stats
    L = []
    L.append("# Object-file splits (`config/splits.json`)\n")
    L.append("Generated by `tools/infer_splits.py` (rerun it to refresh this page and the JSON). The XBE has no")
    L.append("PDB and no `.cpp` names, so object boundaries in `.text` are inferred from link order. A wrong cut")
    L.append("is cheap: codegen doesn't depend on the file a function sits in.\n")
    L.append("## Numbers\n")
    L.append("| | |\n|---|---|")
    L.append("| objects | %d (%d game, %d game-init, %d library) |" % (
        len(objs), len(game), sum(1 for o in objs if o["kind"] == "game-init"), len(lib)))
    L.append("| game objects by confidence | high %d, medium %d, low %d |" % (conf["high"], conf["medium"], conf["low"]))
    L.append("| game objects with a dominant class (RTTI or template argument) | %d |" % sum(1 for o in game if o.get("dominant")))
    L.append("| COMDAT strays (named functions far from their class's home) | %d |" % st["stray_functions"])
    L.append("| template-instantiation functions (COMDAT, labelled by template argument) | %d |" % st["template_functions"])
    L.append("| gaps with interleaved affinity (best single cut) | %d |" % st["interleaved_gaps"])
    L.append("| adjacent objects with vtables in the same order in .rdata | %d of %d |" % (
        st["vtable_pairs_ordered"], st["vtable_pairs_ordered"] + st["vtable_pairs_unordered"]))
    fn_counts = sorted(o["functions"] for o in game)
    if fn_counts:
        L.append("| functions per game object | median %d, max %d |" % (fn_counts[len(fn_counts) // 2], fn_counts[-1]))
    L.append("")
    L.append("Objects per directory: " + ", ".join("`%s/` %d" % (d, c) for d, c in dirs.most_common()) + ".\n")
    L.append("## Method\n")
    L.append("""1. **Library regions** are fixed, not inferred: the three XDK/CRT spans inside `.text`
   ([platform-boundary.md](platform-boundary.md#where-library-code-lives)) and every executable section after
   `.text` (`BINK*`, `D3D`, `XGRPH`, `DSOUND`, `XPP`). They are `kind: library` and never get sources.
   `.text$yc`/`.text$yd` (dynamic initializers and `atexit` thunks, `0x35be88`..`0x364840`) is one
   `kind: game-init` object.
2. **Labels.** Each RTTI-named game function (`Class::vfunc_N`) is labelled with its class. Unnamed
   (`FUN_`) functions have no label. Template instantiations (`fight::ParamBool<X>::vfunc_0`,
   `Method2<CActorManager,...>::vfunc_2`) are COMDATs that the linker places in the first object that
   used them. For these families that is the file of their first class-like template argument (track
   factories and parameters are registered by the track's file, script bindings by the bound class's
   file), so they are labelled with that argument. This is what finds non-virtual classes such as
   `CActorManager`, whose own methods are all `FUN_`.
3. **COMDATs.** A class's own functions are clustered by address (a new cluster starts
   after more than %#x bytes or more than %d other classes). The biggest cluster is the class's home; a
   non-home cluster of at most %d functions and under %d bytes is a **stray**: typically an inline virtual
   destructor or getter emitted out of line by another file. Strays stay in the object they physically
   sit in (so objects stay contiguous ranges, as csplit needs) and are listed under `comdat` with their
   home address. The tree generator puts them in that physical object too.
4. **Cores.** Each remaining cluster is a span [first, last]; overlapping spans are unioned. Classes that
   interleave in address order (a file defining several classes, nested helper classes) end up in one core.
5. **Gaps.** Unnamed functions between two cores are split by call-graph affinity: direct calls, jumps
   and address-taken function addresses to each neighbouring core, propagated %d rounds through edges
   inside the gap (decay %.1f). The left core keeps the prefix that prefers it, the right core the suffix.
   A short ambiguous run (< %d functions) goes to the right-hand object, because static helpers are
   defined before their users and so open the next file. A longer run with no affinity to either side
   becomes its own object(s) (`unk_<addr>.cpp`, `confidence: low`), cut where no call edge crosses and
   kept to at least %d functions per piece. Its directory is the majority namespace of its call partners,
   or `unknown/`.
6. **Names.** An object is named after its dominant class (most bytes), one directory per namespace
   (`hulkfight/motion/HitDamageTrack.cpp`, `global/CChaseCamera.cpp`). A class whose code is split over
   several objects gets `_2`, `_3`, ... on the later ones.
7. **Evidence checked and rejected.** Inter-function padding is uniformly `CC` and %s of game functions
   start 16-byte aligned, so padding carries no boundary signal (the linker aligns every `/Gy` COMDAT).
   `.rdata` vtable order is used only as a consistency check (table above): vtables are COMDATs too.
""" % (CLUSTER_GAP_BYTES, CLUSTER_GAP_CLASSES, STRAY_MAX_FUNCS, STRAY_MAX_BYTES, PROPAGATE_ROUNDS,
       PROPAGATE_DECAY, MID_MIN_FUNCS, MID_MIN_SEG, "99.9%"))
    L.append("Confidence: `high` = a core with at least 3 named functions, `medium` = a core with fewer,")
    L.append("`low` = an unattached run of unnamed functions (or the init region).\n")
    L.append("## Largest objects\n")
    L.append("| object | range | functions | named | dominant class |\n|---|---|---|---|---|")
    for o in sorted(game, key=lambda o: -o["bytes"])[:20]:
        L.append("| `%s` | `0x%06x`..`0x%06x` (%d KB) | %d | %d | %s |" % (
            o["file"], o["start"], o["end"], o["bytes"] // 1024, o["functions"], o["named"], o.get("dominant") or "-"))
    L.append("")
    L.append("## Uncertain regions\n")
    low = [o for o in game if o["confidence"] == "low"]
    L.append("%d low-confidence objects (%d functions, %d KB). The biggest:\n" % (
        len(low), sum(o["functions"] for o in low), sum(o["bytes"] for o in low) // 1024))
    L.append("| object | range | functions | directory from |\n|---|---|---|---|")
    for o in sorted(low, key=lambda o: -o["bytes"])[:15]:
        L.append("| `%s` | `0x%06x`..`0x%06x` | %d | %s |" % (
            o["file"], o["start"], o["end"], o["functions"],
            "call partners" if not o["file"].startswith("unknown/") else "none (no majority)"))
    L.append("")
    L.append("""## Known weak spots

- **Several classes per file.** Only classes whose runs interleave are merged. A file that defines class A
  and then class B in sequence (e.g. a manager and its iterator) comes out as two objects. Merging those
  would need evidence this pass doesn't use (shared string/float pools in `.rdata`, `__FILE__` asserts).
- **Gap cuts are a guess when affinity is weak.** Helpers with no calls into either neighbour (pure math,
  small leaf functions) are placed by the "helpers open the next file" rule.
- **Strays and template instantiations** sit in the object that first referenced them, which is right for
  link order but not where a human would put the source. Moving them to their class's home is a
  source-layout choice for later.
- **Unattached runs** (`unk_*.cpp`) are cut only where no call edge crosses; a file of independent free
  functions can come out as one big object or several small ones.
- **`.text$yc` initializers** are one pseudo-object. Each initializer belongs to the TU whose global it
  constructs; recovering that needs the `.data` globals each one writes.
- **Affinity can over-attach.** A core keeps every gap function that prefers it, through chains of calls,
  so a class with one virtual and many non-virtual methods can swallow a long `FUN_` run
  (`global/CCharacter.cpp`: 116 functions, 1 named). That is often right (non-virtual methods are
  `FUN_`), but nothing bounds it.
- **`unknown/unk_212bb0.cpp`** (368 functions right after the XAPILIB span) has no named function and no
  majority of game callers; it may be more library code. Check it before decompiling it.
- `.rdata`/`.data` splits are not inferred yet.
""")
    os.makedirs(os.path.dirname(OUT_MD), exist_ok=True)
    with open(OUT_MD, "w") as f:
        f.write("\n".join(L))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--stats", action="store_true", help="print the summary, write nothing")
    a = ap.parse_args(argv)
    inf = Inferrer()
    objs = inf.run()
    game = [o for o in objs if o["kind"] == "game"]
    print("objects: %d (game %d), confidence %s" % (
        len(objs), len(game), dict(collections.Counter(o["confidence"] for o in game))))
    print("stats:", dict(inf.stats))
    if a.stats:
        return 0
    os.makedirs(os.path.dirname(OUT_JSON), exist_ok=True)
    with open(OUT_JSON, "w") as f:
        json.dump(to_json(objs), f, indent=1)
        f.write("\n")
    write_md(inf, objs)
    print("wrote", os.path.relpath(OUT_JSON, ROOT), "and", os.path.relpath(OUT_MD, ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
