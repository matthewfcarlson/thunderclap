#!/usr/bin/env python3
"""Which changed functions a checkpoint validation may cover (ckpt1, D162/D163 R2 and R4; docs/checkpoints.md "The
rule"). Read-only: it decides, it records nothing (the ledger kind `ckpt` re-runs these checks when a line is read).

  # R2 + R4 on the coverage (no-ICF) images of a control and a proof
  build/venv/bin/python tools/ckpt_validate.py blocks --control CTL_IMAGE_DIR --proof PROOF_IMAGE_DIR \
      --cover play3=PROOF_COVER.cov [--cover NAME=FILE ...] [--tree ROOT] [--json OUT]
  # R3: every manifest reference replayed by the pair, the checkpoint gate with the reference gate required
  build/venv/bin/python tools/ckpt_validate.py gate --pair play3=CONTROL_JOB,PROOF_JOB [--pair ...] [--json OUT]

CTL_IMAGE_DIR / PROOF_IMAGE_DIR hold hulk-strict.exe and hulk-strict.map of the control and the proof, both linked
without identical-code folding (HULK_WINE_NOICF=1: a folded function's hit cannot say which function ran). Each --cover
is the proof image's coverage of one manifest reference's replay (HULK_COVER with every block leader and
HULK_COVER_EPOCH, so its lines carry window bitmaps).

R2 (changed blocks ran): the proof's functions are matched to the control's by symbol; each is cut into basic blocks
(tools/cover.py basic_blocks) and every instruction normalised: addresses inside the image become the map symbol plus
offset, branch targets inside the function become the target block's index; the blocks are aligned in order
(difflib) and a proof block with no equal control block is changed. A new function is changed throughout. Every changed
block must be in one reference's hit list in at least MIN_WINDOWS windows inside that reference's compared frames
(tools/ckpt_refs.py windows_in); counts are never added across references.
R4 (what the probe can see), default deny: a function is eligible only if its tree block is `equivalent` (a matches
block's bytes are their own claim; 64-bit-only blocks are not in this image, so they are never found), its TU is in
ALLOW and not in DENY, no changed block makes an indirect call or jump (its target cannot be classified), and nothing
its direct-call closure reaches is in DENY or outside the game's objects (the platform layer: file and save I/O,
audio, movies, pddi).
R3 (gate): for every manifest reference, the pair's replays of that recording: tools/ckpt_gate.py CONTROL PROOF
--require-ref against the manifest's reference, verified (tools/ckpt_refs.py verify) on the machine that runs the gate;
the proof may lack no frame the control has. The (frame, tag) the control itself diverges at are listed per
reference (the known divergences: a proof that newly diverges at any other one fails). The report records the
machine (the queue host name, or "local") and the manifest's commit.
Exit 0 when every changed function is eligible and covered (blocks) or every reference's gate passes (gate), 1
otherwise.
"""
import argparse
import bisect
import collections
import difflib
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

MIN_WINDOWS = 2               # (D162 safeguard 1: at least two distinct 300-frame windows, within one reference)
# R4's allowlist (rev5): each entry names the TUs it admits (a path prefix, and optionally a pattern on the TU's file
# name) and the probe tags that observe their state; a TU no entry admits is denied. The first entry that matches is
# used and recorded in the validation, so the ledger's read-time re-check re-applies the same entry.
ALLOWLIST = [
    ("fight-actors", "src/game/hulkfight/", None, ("hulk", "actors")),
    ("fight-engine", "src/engine/fight/", None, ("hulk", "actors")),
    ("locomotion", "src/engine/choreo2/", None, ("hulk", "actors")),
    ("physics", "src/engine/physics/", None, ("hulk", "actors")),
    ("actors", "src/game/global/", r"^(CActor|CCharacter|CHand2Hand|AI|CPatrolPath|CCollision|CWorldCollision|CGrapple"
     r"|CWeaponCollision|CJoint|CStage)", ("hulk", "actors")),
    ("camera", "src/game/global/", r"Camera", ("camera",)),
    ("mission", "src/game/global/", r"^(CScenario|CTriggerVolume|CGameFlow|CEventManager)", ("mission", "flow")),
    ("clock", "src/game/global/", r"^CTimeManager", ("clock",)),
    ("particles", "src/engine/pure3d/", r"(Particle|Sprite|Emitter)", ("particle",)),
]
DENY_NAMES = re.compile(r"MemCard|SaveGame|Save_|Bink|FMV|Sound|Audio|Stream|Render|HUD|FE[A-Z]|Overlay", re.I)
MAP_ANY = re.compile(r"^\s*(000[1-9]):([0-9a-f]+)\s+(\S+)\s+([0-9a-f]{16})\s+(?:f\s+)?(?:i\s+)?(\S+)\s*$")
HEX = re.compile(r"0x([0-9a-f]+)")
INDIRECT = re.compile(r"^(call|jmp)l?\s+\*")
XBE_ADDR = re.compile(r"(?:^|[^0-9A-Za-z])(?:FUN|DAT|thunk_FUN|PTR|LAB|hulk_at|hulk_d|vtbl|rttiTD)_(00[0-9a-fA-F]{6})(?![0-9a-fA-F])")
STUB = re.compile(r"\$[0-9a-f]{8}$")
NAME_OP = re.compile(r"[_?@$A-Za-z][^\s,()]*")


def strip_ops(ops):
    """an instruction's operands without llvm-objdump's comment (`# imm = 0x...` repeats a raw address) and its
    `<symbol>` annotation (the address beside it is normalised instead)"""
    return ops.split("#")[0].split(" <")[0].strip()


def load_map_all(path):
    """[(va, symbol, object, section)] of every public in the map, sorted"""
    out = []
    for l in open(path, errors="replace"):
        m = MAP_ANY.match(l)
        if m:
            out.append((int(m.group(4), 16), m.group(3), m.group(5), int(m.group(1))))
    out.sort()
    return out


class Image:
    def __init__(self, d):
        import cover
        from clang_probe import LLVM
        self.dir = d
        self.syms = load_map_all(os.path.join(d, "hulk-strict.map"))
        self.addrs = [s[0] for s in self.syms]
        self.at = collections.defaultdict(list)
        for va, s_, _o, _sec in self.syms:
            self.at[va].append(s_)
        self._canon = {}
        self.by_name = {}
        for va, s_, _o, _sec in self.syms:
            self.by_name.setdefault(s_, va)
        text = [(va, s, o) for va, s, o, sec in self.syms if sec == 1]
        self.by_sym = {}
        for va, s, o in text:
            self.by_sym.setdefault(s, va)
        self.obj_of = {va: o for va, s, o in text}
        self.ranges = cover.function_ranges(text)
        self.lo, self.hi = (self.syms[0][0], self.syms[-1][0] + 0x100000) if self.syms else (0, 0)
        exe = os.path.join(d, "hulk-strict.exe")
        lo, hi = self.ranges[0][0], self.ranges[-1][1]
        p = subprocess.run([os.path.join(LLVM, "llvm-objdump"), "-d", "--no-show-raw-insn", "--start-address=0x%x" % lo,
                            "--stop-address=0x%x" % hi, exe], capture_output=True, text=True, errors="replace")
        self.insns = []
        for l in p.stdout.splitlines():
            m = cover.INSN.match(l)
            if m:
                # (the operands without llvm-objdump's comments: `# imm = 0x...` repeats a raw address)
                self.insns.append((int(m.group(1), 16), m.group(2), strip_ops(m.group(3) or "")))
        self.iaddr = [x[0] for x in self.insns]
        self.blocks = cover.basic_blocks(exe, self.ranges, LLVM)

    def canon(self, va):
        """one name for everything at va, the same in two links whatever aliases each made: the XBE address any alias
        carries (FUN_/DAT_/hulk_d_<addr>...), else the smallest name that is not a hashed stub (`name$1234abcd`)"""
        c = self._canon.get(va)
        if c is None:
            names = self.at.get(va, ["?%x" % va])
            xbe = sorted({m.group(1) for n in names for m in [XBE_ADDR.search(n)] if m})
            plain = sorted(n for n in names if not STUB.search(n)) or sorted(names)
            c = self._canon[va] = ("@%s" % xbe[0]) if xbe else plain[0]
        return c

    def sym_at(self, a):
        i = bisect.bisect_right(self.addrs, a) - 1
        if i < 0:
            return "?%x" % a
        va = self.syms[i][0]
        return self.canon(va) if a == va else "%s+%x" % (self.canon(va), a - va)

    def body(self, start):
        """[(va, mnemonic, operands)] of the function at start, up to its range end"""
        end = next((e for s, e in self.ranges if s == start), start)
        i, j = bisect.bisect_left(self.iaddr, start), bisect.bisect_left(self.iaddr, end)
        return self.insns[i:j]


def normalise(insns, leaders, image):
    """{leader: [normalised instruction text]}: addresses in the image -> symbol+offset, branch targets in the function
    -> 'B<k>' (the target block's index)"""
    lead = sorted(leaders)
    idx = {x: k for k, x in enumerate(lead)}
    out = collections.OrderedDict((x, []) for x in lead)
    cur = None
    for va, mn, ops in insns:
        if va in idx:
            cur = va
        if cur is None:
            continue

        def rep(m):
            a = int(m.group(1), 16)
            if a in idx:
                return "B%d" % idx[a]
            if image.lo <= a < image.hi:
                return image.sym_at(a)
            return m.group(0)
        ops = NAME_OP.sub(lambda m: image.canon(image.by_name[m.group(0)]) if m.group(0) in image.by_name else m.group(0),
                          HEX.sub(rep, ops))
        out[cur].append("%s %s" % (mn, ops))
    return out




def cfg_shape(blocks):
    """(block count, edges by block index) of a function normalised by normalise(): a block's successors are the blocks
    its branch names ('B<k>') and, unless it ends in an unconditional jump or a return, the next block"""
    keys = list(blocks)
    edges = []
    for i, k in enumerate(keys):
        ins = blocks[k]
        last = ins[-1] if ins else ""
        mn = last.split(" ", 1)[0]
        for m in re.finditer(r"\bB(\d+)\b", last):
            edges.append((i, int(m.group(1))))
        if not (mn.startswith("ret") or mn == "jmp" or mn == "jmpl") and i + 1 < len(keys):
            edges.append((i, i + 1))
    return len(keys), sorted(set(edges))


def changed_blocks(ctl_blocks, prf_blocks):
    """[proof leader] of the changed proof blocks. When the control-flow graph's shape (block count, edges by index)
    differs, every block is changed (rev5: an ordered alignment can pair a modified block with an unrelated equal
    one); with the same shape, the blocks that differ at their own index."""
    if cfg_shape(ctl_blocks) != cfg_shape(prf_blocks):
        return list(prf_blocks)
    a = ["\n".join(v) for v in ctl_blocks.values()]
    b = ["\n".join(v) for v in prf_blocks.values()]
    keys = list(prf_blocks)
    return [keys[j] for j in range(len(b)) if a[j] != b[j]]


def changed_blocks_aligned(ctl_blocks, prf_blocks):
    """(the former ordered alignment, kept only for comparison in tests)"""
    a = ["\n".join(v) for v in ctl_blocks.values()]
    b = ["\n".join(v) for v in prf_blocks.values()]
    keys = list(prf_blocks)
    same = set()
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
        if tag == "equal":
            same.update(range(j1, j2))
    return [keys[j] for j in range(len(b)) if j not in same]


def r2_ok(best):
    """R2 per function: {reference: the fewest windows any changed block ran in within that reference} -> one reference
    must reach MIN_WINDOWS on its own (counts are never added across references)"""
    return any(w >= MIN_WINDOWS for w in best.values())


def load_cover(path):
    """(epoch length, {va: bitmap hex}) of a coverage hit file with window bitmaps"""
    n, hits = 0, {}
    for l in open(path):
        if l.startswith("cover"):
            m = re.search(r"epoch (\d+)", l)
            n = int(m.group(1)) if m else 0
            continue
        w = l.split()
        if len(w) > 3:
            hits[int(w[0], 16)] = w[3]
    return n, hits


def tree_index(root):
    """{symbol: (tu, kind, addr)} of the tree's pinned blocks"""
    import tree_tu
    import glob
    out = {}
    for area in ("src/game", "src/engine", "src/platform/xbox"):
        for p in glob.glob(os.path.join(root, area, "**", "*.cpp"), recursive=True):
            rel = os.path.relpath(p, root)
            for b in tree_tu.scan(p)["blocks"]:
                if b["sym"]:
                    out[b["sym"]] = (rel, b["kind"], b["addr"])
    return out


def allow_entry(tu):
    """the ALLOWLIST entry admitting TU (name, tags), or None (denied)"""
    if tu is None or DENY_NAMES.search(os.path.basename(tu)):
        return None
    for name, prefix, pat, tags in ALLOWLIST:
        if tu.startswith(prefix) and (pat is None or re.search(pat, os.path.basename(tu))):
            return name, tags
    return None


def denied_tu(tu):
    return allow_entry(tu) is None


def classify(fn_va, image, tree, changed, cache):
    """None when the function may be validated by checkpoints, else the reason (R4, default deny)"""
    import cover
    sym = next((s for s, va in image.by_sym.items() if va == fn_va and s in tree), None)
    if sym is None:
        return "not a tree block in this image"
    tu, kind, _addr = tree[sym]
    if kind != "equivalent":
        return "a %s block (its bytes are their own claim)" % kind
    if denied_tu(tu):
        return "TU %s is in no allowlist entry (no probe tag observes it)" % tu
    body = image.body(fn_va)
    for va, mn, ops in body:
        if INDIRECT.match("%s %s" % (mn, ops)):
            blk = max([x for x in changed if x <= va] or [None], key=lambda x: x or 0)
            if blk is not None and blk in changed:
                return "a changed block makes an indirect %s at 0x%x" % (mn, va)
    # the direct-call closure
    seen, todo = {fn_va}, [fn_va]
    while todo:
        f = todo.pop()
        for va, mn, ops in image.body(f):
            if not mn.startswith("call"):
                continue
            m = HEX.match(ops)
            if not m:
                continue
            t = int(m.group(1), 16)
            if t in seen:
                continue
            seen.add(t)
            o = image.obj_of.get(t)
            if o is None or not cover.GAME_OBJ.match(o):
                return "reaches platform code %s (0x%x)" % (image.sym_at(t), t)
            ts = next((s for s, v in image.by_sym.items() if v == t and s in tree), None)
            if ts is not None and denied_tu(tree[ts][0]):
                return "reaches %s in %s" % (ts, tree[ts][0])
            todo.append(t)
    return None


def trace_of(job):
    for sub in ("nb-out", "wine-out"):
        p = os.path.join(ROOT, "build/jobs/out", str(job), sub, "trace.txt")
        if os.path.exists(p):
            return p
    return job if os.path.isfile(job) else None


def cmd_gate(a):
    import ckpt_ref
    import ckpt_refs
    m = ckpt_refs.load(a.manifest)
    refs = {e["name"]: e for e in ckpt_refs.verify(m)}
    pairs = {}
    for p in a.pair:
        name, _, jobs = p.partition("=")
        c, _, q = jobs.partition(",")
        pairs[name] = (c, q)
    if set(pairs) != set(refs):
        print("gate: FAILED (pairs for %s, the manifest lists %s: every reference must be replayed)" % (
            sorted(pairs), sorted(refs)))
        return 1
    commit = subprocess.run(["git", "-C", ROOT, "log", "-1", "--format=%H", "--", "config/ckpt-refs.json"],
                            capture_output=True, text=True).stdout.strip() or None
    out = {"host": os.environ.get("JOBQ_HOST") or "local", "manifest_commit": commit, "references": {}}
    ok = True
    for name, (c, q) in sorted(pairs.items()):
        e = refs[name]
        ct, pt = trace_of(c), trace_of(q)
        if not ct or not pt:
            print("gate %s: FAILED (no trace for %s)" % (name, c if not ct else q))
            ok = False
            continue
        r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/ckpt_gate.py"), ct, pt, "--require-ref", "--ref",
                            os.path.join(ROOT, e["ref"])], capture_output=True, text=True)
        gate_line = ([l for l in r.stdout.splitlines() if l.startswith("GATE")] or ["GATE ?"])[-1]
        _m, _v, ref, _u = ckpt_ref.read(os.path.join(ROOT, e["ref"]))
        _m, _v, ctl, cun = ckpt_ref.read(ct + ".ckref")
        known = sorted((fr, ckpt_ref.name(t)) for fr in ref if fr in ctl for t, (h, _q) in ref[fr].items()
                       if t in ctl[fr] and ctl[fr][t][0] != h and ckpt_ref.name(t) not in ckpt_ref.OBSERVABLE)
        rok = r.returncode == 0
        ok &= rok
        out["references"][name] = {"control": c, "proof": q, "gate": gate_line, "ok": rok,
                                    "control_diverged": len(known), "control_diverged_first": known[:50]}
        print("gate %s: %s; the control diverges from the original at %d (frame, tag)%s" % (
            name, gate_line, len(known), " (first %d %s)" % known[0] if known else ""))
    out["ok"] = ok
    if a.json:
        json.dump(out, open(a.json, "w"), indent=1)
    print("ckpt_validate gate:", "ok" if ok else "FAILED")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    g = sp.add_parser("gate")
    g.add_argument("--pair", action="append", default=[], help="NAME=CONTROL_JOB,PROOF_JOB (job ids or traces)")
    g.add_argument("--manifest")
    g.add_argument("--json")
    b = sp.add_parser("blocks")
    b.add_argument("--control", required=True)
    b.add_argument("--proof", required=True)
    b.add_argument("--cover", action="append", default=[], help="NAME=FILE: the proof's coverage of reference NAME")
    b.add_argument("--tree", default=ROOT)
    b.add_argument("--manifest")
    b.add_argument("--json")
    a = ap.parse_args()
    if a.cmd == "gate":
        return cmd_gate(a)
    import ckpt_refs
    refs = {e["name"]: e for e in ckpt_refs.verify(ckpt_refs.load(a.manifest))}
    covers = {}
    for c in a.cover:
        name, _, path = c.partition("=")
        if name not in refs:
            sys.exit("--cover %s: not a manifest reference" % name)
        covers[name] = load_cover(path)
    if set(covers) != set(refs):
        sys.exit("coverage is needed for every manifest reference: have %s, manifest %s" % (sorted(covers), sorted(refs)))
    ctl, prf = Image(a.control), Image(a.proof)
    tree = tree_index(a.tree)
    report, ok = [], True
    for sym, pva in sorted(prf.by_sym.items(), key=lambda kv: kv[1]):
        if sym not in tree or pva not in prf.blocks:
            continue
        pb = normalise(prf.body(pva), [x for x, _n in prf.blocks[pva]], prf)
        cva = ctl.by_sym.get(sym)
        cb = normalise(ctl.body(cva), [x for x, _n in ctl.blocks[cva]], ctl) if cva in ctl.blocks else {}
        ch = changed_blocks(cb, pb)
        if not ch:
            continue
        r = {"sym": sym, "addr": tree[sym][2], "tu": tree[sym][0], "changed_blocks": ["0x%x" % x for x in ch],
             "new": cva is None}
        r["r4"] = classify(pva, prf, tree, set(ch), {})
        ae = allow_entry(tree[sym][0])
        r["allow"] = {"entry": ae[0], "tags": list(ae[1])} if ae else None
        best = {}
        for name, (n, hits) in covers.items():
            counts = [ckpt_refs.windows_in(hits[x], n, refs[name]) if x in hits else 0 for x in ch]
            best[name] = min(counts)
        r["r2_windows"] = best
        r["r2"] = r2_ok(best)
        r["eligible"] = r["r4"] is None and r["r2"]
        ok &= r["eligible"]
        report.append(r)
    for r in report:
        print("%s %-60s %s%s" % (r["addr"], r["sym"][:60], "eligible" if r["eligible"] else "NOT eligible",
                                  "" if r["eligible"] else " (%s)" % (r["r4"] or "R2: windows %s, need %d in one reference"
                                                                      % (r["r2_windows"], MIN_WINDOWS))))
    print("ckpt_validate: %d changed function(s), %d eligible -> %s" % (
        len(report), sum(r["eligible"] for r in report), "ok" if ok and report else "NOT ok"))
    if a.json:
        json.dump({"ok": ok and bool(report), "min_windows": MIN_WINDOWS, "functions": report,
                   "control": os.path.abspath(a.control), "proof": os.path.abspath(a.proof)}, open(a.json, "w"), indent=1)
    return 0 if ok and report else 1


if __name__ == "__main__":
    sys.exit(main())
