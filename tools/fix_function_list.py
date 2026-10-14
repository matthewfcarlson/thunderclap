#!/usr/bin/env python3
"""Fix bogus entries in build/functions.csv: caller-frame FRAGMENTS and TRUNCATED function sizes.

Ghidra ends a function early (after a cmp whose jcc it mis-attributed, at an early `ret`, before a block only
reached by a conditional jump) and then lists the rest of the body as a separate "function" that nobody calls.
Those fragments can never be matched, and the truncated parent can't either (its bytes stop mid-flow).

For every listed function this walks the real control-flow graph from its entry (fallthrough, conditional and
in-function unconditional jumps, jump tables; calls are not followed) and works out the real extent:

  * a jcc / jump-table / fall-through edge that leaves the recorded range is followed, unless it lands on the
    start of another listed function that something else calls or points at (call rel32, a data pointer such as a
    vtable slot, a pushed/loaded address) or that is jumped to from two or more different functions (a shared tail);
  * an unconditional jmp is followed only when it lands on no listed function start (a jmp to a function entry is
    a tail call);
  * decoding stops at ret / int3 / ud2 / undecodable bytes / an independent entry.

The furthest reached instruction end is the new end. Listed entries that start inside the new extent are folded
into the parent (removed). Anything that would fold an independently referenced function is reported as a
conflict and left alone. The scan repeats until stable (a fixed point), because extending a parent exposes the
references made by its tail.

  tools/fix_function_list.py [--in build/functions.csv] [--out PATH] [--log build/function-list-fixes.json]
                             [--dry-run]

Without --out the corrected list goes to build/functions.csv.new (never over the live file); move it into place
yourself. Read-only otherwise; the .xbe is read, never written.

  tools/fix_function_list.py --pass2 [--in build/functions.csv] [--out build/functions.csv.new] [--install TAG]
      # second pass, run on the already-fixed list: classify every gap between listed functions that holds more than
      # 0xCC padding (a: truncated parent, b: missing function, c: data / dead / table / padding; see GapScan) and add
      # the b functions. Appends a "pass2" section to the log (the pass-1 sections are kept). With --install TAG the
      # backup build/functions.csv.bak-TAG is written (if absent) and the new list moved over the live file in one
      # os.replace, but only if the live file still has the sha1 it had when this run started (or --live-sha SHA).
      # Full re-run from the pre-pass-2 state: --in build/functions.csv.bak-TAG --install TAG --live-sha <live sha1>.

  tools/fix_function_list.py --sources NEW.csv [--inputs 400]
      # for every address in the log (changed parent or removed fragment) that has matches/ADDR.cpp or
      # equivalent/ADDR.cpp: re-run tools/compare.py (matches) / tools/equiv.py (equivalent, local Unicorn,
      # --inputs random inputs) against NEW.csv's sizes, and add the verdicts to the log under "sources".
      # Sources are only read. equivalent/ verdicts here are a quick local screen; the usual 3000-input check
      # still has to be re-run on the checker box before a source is trusted at the new size.
"""
import bisect
import collections
import csv
import json
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from capstone import CS_ARCH_X86, CS_MODE_32, Cs  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
CSV_IN = os.path.join(ROOT, "build/functions.csv")
LOG = os.path.join(ROOT, "build/function-list-fixes.json")
MAX_SPAN = 0x6000          # a function never reaches further than this from its entry
TABLE_RE = re.compile(r"\[(?:\w+\s*\+\s*)?\w+\*4\s*\+\s*(0x[0-9a-f]+)\]")
JCC = {"jo", "jno", "jb", "jae", "je", "jne", "jbe", "ja", "js", "jns", "jp", "jnp", "jl", "jge", "jle", "jg",
       "jcxz", "jecxz", "loop", "loope", "loopne"}
STOP = {"int3", "ud2", "hlt", "ud1", "int"}


class Walker:
    def __init__(self, xbe):
        self.x = xbe
        self.md = Cs(CS_ARCH_X86, CS_MODE_32)
        self.memo = {}

    def ins(self, va):
        """(size, kind, target, table) for the instruction at va; kind in seq/ret/stop/jmp/jcc/call/jmpind/bad."""
        r = self.memo.get(va)
        if r is not None:
            return r
        o = self.x.offset(va)
        r = ("bad",)
        if o is not None:
            for i in self.md.disasm(self.x.data[o:o + 16], va, 1):
                m = i.mnemonic
                tgt = None
                tab = None
                if m == "jmp":
                    if i.op_str.startswith("0x"):
                        kind, tgt = "jmp", int(i.op_str, 16)
                    else:
                        t = TABLE_RE.search(i.op_str)
                        kind, tab = "jmpind", (int(t.group(1), 16) if t else None)
                elif m in JCC:
                    kind, tgt = "jcc", int(i.op_str, 16)
                elif m == "call":
                    kind = "call"
                elif m.startswith("ret"):
                    kind = "ret"
                elif m in STOP:
                    kind = "stop"
                else:
                    kind = "seq"
                r = (i.size, kind, tgt, tab)
        self.memo[va] = r
        return r


class Model:
    def __init__(self, xbe, rows):
        self.x = xbe
        self.w = Walker(xbe)
        self.rows = rows
        self.size = {int(r["address"], 16): int(r["size"]) for r in rows}
        self.starts = sorted(self.size)
        self.text = [s for s in xbe.sections if s.executable]
        self.scan_refs()

    def in_code(self, va):
        return any(s.va <= va < s.va + s.vsize for s in self.text)

    def owner(self, va):
        k = bisect.bisect_right(self.starts, va) - 1
        if k < 0:
            return None
        a = self.starts[k]
        return a if va < a + self.size[a] else None

    def scan_refs(self):
        """call targets, data pointers, immediates, and unconditional/conditional jump sources, per target."""
        fs = set(self.starts)
        self.callt, self.imm = collections.defaultdict(set), collections.defaultdict(set)
        self.jsrc = collections.defaultdict(set)        # target -> {source function}
        self.dat = collections.defaultdict(int)
        md = Cs(CS_ARCH_X86, CS_MODE_32)
        for a in self.starts:
            o = self.x.offset(a)
            if o is None:
                continue
            for i in md.disasm(self.x.data[o:o + self.size[a]], a):
                m = i.mnemonic
                if m == "call" and i.op_str.startswith("0x"):
                    self.callt[int(i.op_str, 16)].add(a)
                elif (m == "jmp" or m in JCC) and i.op_str.startswith("0x"):
                    t = int(i.op_str, 16)
                    if not (a <= t < a + self.size[a]):
                        self.jsrc[t].add(a)
                elif m in ("push", "mov", "lea", "cmp") or m.startswith("f"):
                    for t in re.findall(r"0x[0-9a-f]{5,6}\b", i.op_str):
                        v = int(t, 16)
                        if v in fs:
                            self.imm[v].add(a)
        for s in self.x.sections:
            if s.executable:
                continue
            o = self.x.offset(s.va)
            if o is None:
                continue
            for k in range(0, min(s.rsize, s.vsize) - 3, 4):
                v = struct.unpack_from("<I", self.x.data, o + k)[0]
                if v in fs:
                    self.dat[v] += 1

    def independent(self, t):
        """A listed function start that something other than a jump into it refers to."""
        return bool(self.callt.get(t) or self.dat.get(t) or self.imm.get(t))

    def shared(self, t, parent):
        """Jumped to from two or more functions that are not the parent: a shared tail block, not a fragment."""
        return len({f for f in self.jsrc.get(t, ()) if self.independent(f)} | ({parent} if self.jsrc.get(t) else set())) >= 2

    def walk(self, a, n):
        """Real extent of the function at a. Returns (end, absorbed_starts, edges, notes, override)."""
        starts = self.starts
        fs = set(starts)
        end = a + n
        seen = {}
        work = [(a, False)]
        deferred = []   # forward unconditional jmps, followed only once the extent proves they stay inside
        edges = []      # evidence: (kind, from, to) edges that leave the recorded range
        notes = []
        override = {}   # absorbed entry -> why its own references don't count (mid-instruction / fall-through)
        hi_limit = a + MAX_SPAN
        inside = lambda t: a <= t < a + n
        while work or deferred:
            if not work:
                again = [d for d in deferred if d[1] < end]
                deferred = [d for d in deferred if d[1] >= end]
                if not again:
                    break
                for va, tgt in again:
                    if not inside(tgt):
                        edges.append(("jmp", va, tgt))
                    work.append((tgt, False))
                continue
            va, fall = work.pop()
            while True:
                if va in seen or va < a or va >= hi_limit:
                    break
                if va != a and va in fs and self.independent(va):
                    if fall and va % 16 and va >= a + n:
                        override[va] = "fall-through from 0x%08x (executed into it, start not 16-aligned)" % last
                    else:
                        if va >= a + n:
                            notes.append("stops at independent entry 0x%08x" % va)
                        break
                r = self.w.ins(va)
                if r[0] == "bad":
                    notes.append("undecodable at 0x%08x" % va)
                    break
                size, kind, tgt, tab = r
                seen[va] = size
                nxt = va + size
                if va < a + n < nxt:
                    edges.append(("overrun", va, a + n))     # the recorded size cuts this instruction in half
                if kind != "stop" or va < a + n:
                    end = max(end, nxt)
                if kind in ("ret", "stop"):
                    break
                if kind == "jmp":
                    if a <= tgt < hi_limit and tgt not in fs:
                        o = self.owner(tgt)
                        if o is not None and o != a and not inside(tgt):
                            notes.append("jmp 0x%08x into middle of 0x%08x (0x%08x), not followed" % (va, o, tgt))
                        elif tgt < end:
                            if not inside(tgt):
                                edges.append(("jmp", va, tgt))
                            work.append((tgt, False))
                        else:
                            deferred.append((va, tgt))
                    break
                if kind == "jmpind":
                    for k in range(512 if tab else 0):
                        v = self.x.u32(tab + 4 * k)
                        if v is None or not (a <= v < hi_limit) or not self.in_code(v):
                            break
                        if v in fs and v != a and (self.independent(v) or self.shared(v, a)):
                            break
                        if not inside(v):
                            edges.append(("jt", va, v))
                        work.append((v, False))
                    break
                if kind == "jcc" and a <= tgt < hi_limit:
                    if tgt in fs and tgt != a and (self.independent(tgt) or self.shared(tgt, a)):
                        if not inside(tgt):
                            notes.append("jcc 0x%08x -> 0x%08x independent/shared entry, not followed" % (va, tgt))
                    else:
                        if not inside(tgt):
                            edges.append(("jcc", va, tgt))
                        work.append((tgt, False))
                last = va
                va = nxt
                fall = True
                if va >= a + n and va not in seen:
                    if va in fs:
                        if not self.independent(va) or va % 16:
                            edges.append(("fall", last, va))
                    elif va == a + n:
                        # falling off the recorded end into bytes that are not a listed function
                        o = self.x.offset(va)
                        if o is None or self.x.data[o] == 0xCC:
                            break
                        edges.append(("fall", last, va))
        self.last_seen = seen
        absorbed = set()
        order = sorted(seen)
        for s in starts[bisect.bisect_right(starts, a):]:
            if s >= end:
                break
            absorbed.add(s)
            k = bisect.bisect_right(order, s) - 1
            if k >= 0 and order[k] != s and order[k] + seen[order[k]] > s:
                override[s] = "starts mid-instruction (inside the instruction at 0x%08x)" % order[k]
        return end, sorted(absorbed), edges, notes, override


def run_once(model, rows_by_addr):
    changes, conflicts = [], []
    removed = set()
    new_size = {}
    for a in model.starts:
        if a in removed:
            continue
        n = model.size[a]
        if model.x.offset(a) is None:
            continue
        end, absorbed, edges, notes, override = model.walk(a, n)
        if end <= a + n and not absorbed:
            continue
        # no edge leaving the recorded range: nothing to extend
        if not edges:
            continue
        bad = [s for s in absorbed if (model.independent(s) or model.shared(s, a)) and s not in override]
        if bad:
            conflicts.append({"address": "0x%08x" % a, "size": n, "would_end": "0x%08x" % end,
                              "absorbs_independent": ["0x%08x" % s for s in bad],
                              "edges": ["%s 0x%08x->0x%08x" % e for e in edges]})
            continue
        new_size[a] = end - a
        for s in absorbed:
            removed.add(s)
        changes.append({"address": "0x%08x" % a, "old_size": n, "new_size": end - a,
                        "absorbed": [{"address": "0x%08x" % s, "size": model.size[s], "why": override.get(s, "no references of its own")}
                                 for s in absorbed],
                        "evidence": ["%s 0x%08x->0x%08x" % e for e in edges] + notes})
    return changes, conflicts, removed, new_size


SRC_RUN = r'''
import json, sys
sys.path.insert(0, "tools")
mode, csvp, src, addr, n = sys.argv[1:6]
if mode == "match":
    import compare, csv
    funcs = {int(r["address"], 16): (int(r["size"]), r["name"]) for r in csv.DictReader(open(csvp))}
    compare.load_functions = lambda: funcs
    if int(addr, 16) not in funcs:
        print(json.dumps({"status": "not-listed"})); sys.exit(0)
    r = compare.compare(open(src).read(), int(addr, 16))
    print(json.dumps({k: v for k, v in r.items() if k != "rows"}, default=str))
else:
    import equiv
    equiv.FUNCS_CSV = csvp
    sys.argv = ["equiv.py", src, addr, "--inputs", n, "--json"]
    equiv.main(sys.argv[1:])
'''


def check_sources(argv):
    import subprocess
    new_csv = os.path.abspath(argv[argv.index("--sources") + 1])
    n = argv[argv.index("--inputs") + 1] if "--inputs" in argv else "400"
    log = argv[argv.index("--log") + 1] if "--log" in argv else LOG
    d = json.load(open(log))
    new_size = {int(r["address"], 16): int(r["size"]) for r in csv.DictReader(open(new_csv))}
    old = {}
    p2 = "--pass2" in argv            # only the pass-2 section (extended parents and newly added functions)
    if not p2:
        for e in d["extended"]:
            old[e["address"]] = ("parent", e["old_size"], e["new_size"], e["address"])
        for e in d["removed"]:
            old[e["address"]] = ("removed fragment", e["size"], None, e["parent"])
    for e in (d.get("pass2", {}).get("a_extended", []) if p2 else []):
        old[e["parent"]] = ("parent", e["old_size"], e["new_size"], e["parent"])
    for e in (d.get("pass2", {}).get("b_added", []) if p2 else []):
        old[e["address"]] = ("new function", None, e["size"], e["address"])
    res = []
    for addr in sorted(old):
        for kind, mode in (("matches", "match"), ("equivalent", "equiv")):
            src = "%s/%s.cpp" % (kind, addr)
            if not os.path.exists(os.path.join(ROOT, src)):
                continue
            role, osz, nsz, parent = old[addr]
            row = {"address": addr, "dir": kind, "role": role, "old_size": osz, "new_size": nsz, "parent": parent}
            r = subprocess.run([sys.executable, "-I", "-c", SRC_RUN, mode, new_csv, src, addr, n],
                               capture_output=True, text=True, cwd=ROOT)
            try:
                out = json.loads(r.stdout.strip().splitlines()[-1])
            except (ValueError, IndexError):
                out = {"status": "error", "detail": (r.stderr or r.stdout)[-300:]}
            if role == "removed fragment":
                row["verdict"] = "demote: the source covers a fragment that is no longer a function"
            elif mode == "match":
                row["verdict"] = "still matches at new size" if out.get("status") == "match" else \
                    "demote: %s at new size (matched %s of %s bytes)" % (out.get("status"), out.get("matched"), out.get("total"))
            else:
                l3 = out.get("level3") or {}
                cov = l3.get("coverage") or {}
                ok = out.get("status") == "equivalent"
                row["verdict"] = ("passes locally at new size (%s inputs, coverage %s/%s%s); recheck on checker box"
                                  % (l3.get("inputs_run"), cov.get("edges_covered"), cov.get("edges_total"),
                                     "" if cov.get("complete") else ", incomplete")) if ok else \
                    "re-verify/demote: %s at new size" % out.get("status")
                row["equiv"] = {"status": out.get("status"), "inputs_run": l3.get("inputs_run"),
                                "failed": l3.get("inputs_failed"), "coverage": "%s/%s" % (cov.get("edges_covered"), cov.get("edges_total")),
                                "mismatches": (l3.get("mismatches") or [])[:2]}
            row["result"] = {k: out[k] for k in ("status", "score", "exact", "matched", "total") if k in out}
            res.append(row)
            print(addr, kind, role, row["verdict"])
    if p2:
        d["pass2"]["sources"] = res
        d["pass2"]["sources_note"] = ("matches/ and equivalent/ checked for every extended parent and every new function: "
                                      "%d source files touch a changed address" % len(res))
    else:
        d["sources"] = res
    json.dump(d, open(log, "w"), indent=1)
    print("%d sources checked" % len(res))


# ---------------------------------------------------------------------------------------------------------------
# Pass 2: unlisted executable bytes (gaps between listed functions that are not just 0xCC padding).
#
# Every gap is cut into units by walking the control flow from the first non-padding byte (calls are recorded,
# not followed; jump tables and index tables found through `jmp [r*4+T]` / `movzx r, byte [r+T]` are data).
# A unit is then classified by who refers to it:
#   a  the parent function's own control flow reaches it (jcc/jmp from the parent into a unit that starts at the
#      parent's end with no padding, or fall-through)           -> extend the parent
#   b  something outside the unit refers to its entry: call rel32 / jmp rel32 (tail call) from a listed function or
#      from a unit that is itself b, a dword pointer in a data section (vtable, EH/unwind tables, callback tables),
#      a pushed/loaded code address                              -> add a function
#   c  nothing refers to it (dead or unreferenced), or it does not decode as code, or it is a jump/index table.
# Units referred to only from other unreferenced units stay c until a real referrer exists (fixed point).
GAP_BYTE_TABLE_MAX = 256
TABLE_B_RE = re.compile(r"\[(?:\w+\s*\+\s*)?(\w+)\s*\+\s*(0x[0-9a-f]+)\]|\[(0x[0-9a-f]+)\]")


class GapScan:
    def __init__(self, xbe, rows):
        self.x = xbe
        self.rows = rows
        self.size = {int(r["address"], 16): int(r["size"]) for r in rows}
        self.starts = sorted(self.size)
        self.secs = [s for s in xbe.sections if s.executable]
        self.md = Cs(CS_ARCH_X86, CS_MODE_32)
        self.md.detail = True
        self.memo = {}
        self.find_gaps()

    def sec(self, va):
        for s in self.secs:
            if s.va <= va < s.va + s.vsize:
                return s
        return None

    def byte(self, va):
        o = self.x.offset(va)
        return None if o is None else self.x.data[o]

    def find_gaps(self):
        self.gaps = []           # (start, end, section) of gaps holding anything other than 0xCC
        self.gap_starts = []
        for s in self.secs:
            lo, hi = s.va, s.va + min(s.vsize, s.rsize)
            prev = lo
            for a in [a for a in self.starts if lo <= a < hi]:
                if a > prev:
                    self.add_gap(prev, a, s)
                prev = max(prev, a + self.size[a])
            if prev < hi:
                self.add_gap(prev, hi, s)
        self.gap_starts = [g[0] for g in self.gaps]

    def add_gap(self, a, b, s):
        o = self.x.offset(a)
        if o is not None and any(c != 0xCC for c in self.x.data[o:o + b - a]):
            self.gaps.append((a, b, s))

    def gap_of(self, va):
        k = bisect.bisect_right(self.gap_starts, va) - 1
        if k >= 0 and va < self.gaps[k][1]:
            return self.gaps[k]
        return None

    def dec(self, va):
        """Capstone instruction at va (detail on), cached; None when undecodable."""
        if va in self.memo:
            return self.memo[va]
        o = self.x.offset(va)
        r = None
        if o is not None:
            for i in self.md.disasm(self.x.data[o:o + 16], va, 1):
                r = i
        self.memo[va] = r
        return r

    # --- references -------------------------------------------------------------------------------------------
    def ref_kinds(self, i):
        """[(kind, target)] for one instruction. call/jmp/jcc are rel32 branches; imm is an immediate that looks like
        a code address; mem is a memory operand whose displacement lands in .text (tables); jt is `jmp/call [..*4+T]`."""
        out = []
        m = i.mnemonic
        for op in i.operands:
            if op.type == 2:                      # X86_OP_IMM
                v = op.imm & 0xFFFFFFFF
                if m == "call":
                    out.append(("call", v))
                elif m == "jmp":
                    out.append(("jmp", v))
                elif m in JCC:
                    out.append(("jcc", v))
                elif self.sec(v) is not None and v >= 0x11000 and m in ("push", "mov", "lea", "cmp", "add", "sub", "or", "and"):
                    out.append(("imm", v))
            elif op.type == 3:                    # X86_OP_MEM
                d = op.mem.disp & 0xFFFFFFFF
                if self.sec(d) is not None and d >= 0x11000:
                    if m in ("jmp", "call") and op.mem.scale == 4 and op.mem.index != 0:
                        out.append(("jt", d))
                    elif op.mem.index != 0 and op.mem.scale == 1 and m.startswith("mov"):
                        out.append(("bt", d))
                    else:
                        out.append(("mem", d))
        return out

    def collect(self, model):
        """refs[target] = [(kind, src_insn_va, src_function)] for targets inside gaps, from the instructions each listed
        function actually executes (CFG, not a linear sweep: inline tables would give garbage)."""
        refs = collections.defaultdict(list)
        for a in self.starts:
            if self.x.offset(a) is None:
                continue
            model.walk(a, self.size[a])
            for va in model.last_seen:
                i = self.dec(va)
                if i is None:
                    continue
                for k, t in self.ref_kinds(i):
                    if a <= t < a + self.size[a] and k in ("jmp", "jcc"):
                        continue
                    g = self.gap_of(t)
                    if g is not None:
                        refs[t].append((k, va, a))
        self.memo.clear()
        # dword pointers in data sections
        for s in self.x.sections:
            if s.executable:
                continue
            o = self.x.offset(s.va)
            if o is None:
                continue
            for k in range(0, min(s.rsize, s.vsize) - 3, 4):
                v = struct.unpack_from("<I", self.x.data, o + k)[0]
                if 0x11000 <= v < 0x3f2be0 and self.gap_of(v) is not None:
                    refs[v].append(("ptr", s.va + k, s.name))
        return refs

    # --- gap segmentation -------------------------------------------------------------------------------------
    def walk_unit(self, entry, hi):
        """CFG from entry inside [entry, hi). Returns dict(end, ok, term, calls, jt, bt, ext, bad)."""
        seen = {}
        work = [entry]
        end = entry
        calls, jts, bts, ext, imms = [], [], [], [], []
        bad = None
        term = set()
        while work:
            va = work.pop()
            while True:
                if va in seen:
                    break
                if va < entry or va >= hi:
                    break
                i = self.dec(va)
                if i is None:
                    bad = va
                    break
                seen[va] = i.size
                nxt = va + i.size
                if nxt > hi:
                    bad = va
                    break
                end = max(end, nxt)
                m = i.mnemonic
                refs = self.ref_kinds(i)
                for k, t in refs:
                    if k == "call":
                        calls.append((va, t))
                    elif k == "jt":
                        jts.append((va, t))
                    elif k == "bt":
                        bts.append((va, t))
                    elif k == "imm":
                        imms.append((va, t))
                if m.startswith("ret") or m in STOP:
                    term.add("ret" if m.startswith("ret") else "stop")
                    break
                if m == "jmp":
                    tg = [t for k, t in refs if k == "jmp"]
                    if tg:
                        t = tg[0]
                        if entry <= t < hi:
                            work.append(t)
                        else:
                            ext.append((va, t))
                            term.add("tail")
                    else:
                        term.add("jmpind")
                        for v, T in [(va, t) for k, t in refs if k == "jt"]:
                            for n in range(512):
                                q = self.x.u32(T + 4 * n)
                                if q is None or not (entry <= q < hi) or self.byte(q) == 0xCC:
                                    break
                                work.append(q)
                    break
                if m in JCC:
                    tg = [t for k, t in refs if k == "jcc"]
                    if tg:
                        if entry <= tg[0] < hi:
                            work.append(tg[0])
                        else:
                            ext.append((va, tg[0]))
                va = nxt
        return dict(end=end, ok=bad is None, term=sorted(term), calls=calls, jt=jts, bt=bts, ext=ext, imms=imms, bad=bad, n=len(seen))

    def table_len(self, T, lo, hi):
        """Entries of a dword code-pointer table at T whose values stay inside [lo, hi) on non-padding bytes."""
        n = 0
        while T + 4 * n + 4 <= hi:
            q = self.x.u32(T + 4 * n)
            if q is None or not (lo <= q < hi) or self.byte(q) == 0xCC:
                break
            n += 1
        return n

    def is_nop(self, i):
        m, ops = i.mnemonic, i.op_str
        if m == "nop":
            return True
        if m in ("mov", "xchg") and len(i.operands) == 2 and i.operands[0].type == 1 and i.operands[1].type == 1 \
                and i.operands[0].reg == i.operands[1].reg:
            return True
        if m == "lea" and re.fullmatch(r"(e\w\w), (?:dword ptr )?\[\1(?: \+ 0)?\]", ops):
            return True
        return False

    def skip_pad(self, pos, ge, stop):
        """Alignment NOPs (mov edi,edi / nop / lea esi,[esi]) that lead up to an aligned address (or `stop`)."""
        p = pos
        while p < ge and p not in stop:
            i = self.dec(p)
            if i is None or not self.is_nop(i):
                break
            p += i.size
        if p > pos and (p in stop or p % 4 == 0 and (p >= ge or self.byte(p) != 0xCC)):
            return p
        return pos

    def segment(self, refs):
        """Cut every gap into units: (kind, start, end, info) with kind code / jtab / btab / junk / pad."""
        units = []
        for (gs, ge, s) in self.gaps:
            pos = gs
            tabs = {}          # table start -> (kind, bytes) found while walking this gap
            stop = {t for t in refs if gs <= t < ge and {k for k, _, _ in refs[t]} & {"jt", "bt", "mem"}}
            while pos < ge:
                b = self.byte(pos)
                if b == 0xCC:
                    pos += 1
                    continue
                q = self.skip_pad(pos, ge, stop | set(tabs))
                if q != pos:
                    units.append(("pad", pos, q, None))
                    pos = q
                    continue
                if pos in tabs and tabs[pos][1]:
                    k, n = tabs[pos]
                    units.append((k, pos, pos + n, None))
                    pos += n
                    continue
                refk = {k for k, _, _ in refs.get(pos, ())}
                if refk and refk <= {"mem", "bt"}:
                    e = pos
                    while e < ge and self.byte(e) != 0xCC and e - pos < GAP_BYTE_TABLE_MAX:
                        e += 1
                    units.append(("btab", pos, e, None))
                    pos = e
                    continue
                if "jt" in refk:
                    n = self.table_len(pos, s.va, s.va + s.vsize)
                    if n:
                        units.append(("jtab", pos, pos + 4 * n, None))
                        pos += 4 * n
                        continue
                info = self.walk_unit(pos, ge)
                for _, T in info["jt"]:
                    g2 = self.gap_of(T)
                    if g2 is not None and g2[0] == gs:
                        tabs[T] = ("jtab", 4 * self.table_len(T, s.va, s.va + s.vsize))
                for _, T in info["bt"]:
                    g2 = self.gap_of(T)
                    if g2 is not None and g2[0] == gs and T not in tabs:
                        tabs[T] = ("btab", 0)
                if not info["ok"] or info["n"] == 0 or not info["term"]:
                    e = pos + 1
                    while e < ge and not (self.byte(e) == 0xCC and e % 4 == 0):
                        e += 1
                    units.append(("junk", pos, e, info))
                    pos = e
                    continue
                units.append(("code", pos, info["end"], info))
                pos = info["end"]
                if pos in tabs and tabs[pos][0] == "btab" and tabs[pos][1] == 0:
                    e = pos
                    while e < ge and self.byte(e) != 0xCC and e - pos < GAP_BYTE_TABLE_MAX:
                        e += 1
                    tabs[pos] = ("btab", e - pos)
        return units

    # --- classification ---------------------------------------------------------------------------------------
    def classify(self, units, refs):
        """Returns records for every code/junk/table unit: dict(cls a/b/c, ...). See the pass-2 comment above."""
        code = {u[1]: u for u in units if u[0] == "code"}
        ustarts = sorted(code)
        ends = {a + n: a for a, n in self.size.items()}
        # references from unit code to other units
        urefs = collections.defaultdict(list)
        for a, (_, _, e, info) in code.items():
            for va, t in info["calls"]:
                if t in code and t != a:
                    urefs[t].append(("call", va, a))
            for va, t in info["ext"]:
                if t in code and t != a:
                    urefs[t].append(("jmp", va, a))
            for va, t in info["imms"]:
                if t in code and t != a:
                    urefs[t].append(("imm", va, a))
        # code reached by jumping into the middle of a unit from listed code
        def unit_containing(t):
            k = bisect.bisect_right(ustarts, t) - 1
            if k >= 0:
                u = code[ustarts[k]]
                if t < u[2]:
                    return u
            return None
        live, why = set(), {}
        ext_refs = collections.defaultdict(list)       # unit start -> hard refs from listed code / data
        mids = collections.defaultdict(list)
        for t, lst in refs.items():
            u = unit_containing(t)
            if u is None:
                continue
            for k, va, src in lst:
                if k in ("mem", "bt", "jt"):
                    continue
                (ext_refs if t == u[1] else mids)[u[1]].append((k, va, src, t))
        cls = {}
        for a in ustarts:
            r = ext_refs.get(a, []) + mids.get(a, [])
            if r:
                live.add(a)
        # fixpoint: references from live units make units live
        changed = True
        while changed:
            changed = False
            for t, lst in urefs.items():
                if t in live:
                    continue
                if any(src in live for _, _, src in lst):
                    live.add(t)
                    changed = True
        out = []
        for a in ustarts:
            _, _, e, info = code[a]
            hard = ext_refs.get(a, [])
            mid = mids.get(a, [])
            fromu = [x for x in urefs.get(a, []) if x[2] in live]
            deadu = [x for x in urefs.get(a, []) if x[2] not in live]
            parent = ends.get(a)
            rec = dict(address=a, end=e, size=e - a, parent=parent, aligned16=(a % 16 == 0),
                       padded=(a > 0 and self.byte(a - 1) == 0xCC), term=info["term"], n_insn=info["n"],
                       calls=len(info["calls"]), refs=[], mid_refs=[])
            for k, va, src, t in hard:
                rec["refs"].append([k, "0x%08x" % va, ("0x%08x" % src) if isinstance(src, int) else src])
            for k, va, src in fromu:
                rec["refs"].append([k + "(from unit)", "0x%08x" % va, "0x%08x" % src])
            for k, va, src, t in mid:
                rec["mid_refs"].append([k, "0x%08x" % va, ("0x%08x" % src) if isinstance(src, int) else src, "0x%08x" % t])
            kinds = {k for k, *_ in hard} | {k for k, _, _ in fromu}
            jonly = kinds <= {"jmp", "jcc", "jtent"} and bool(kinds)
            srcs = {x[2] for x in hard if isinstance(x[2], int)}
            if parent is not None and (hard or mid) and all(isinstance(x[2], int) and x[2] == parent for x in hard + mid) \
                    and all(x[0] in ("jmp", "jcc", "jtent") for x in hard + mid) and a % 16:
                rec["cls"] = "a"
                rec["why"] = "parent 0x%08x jumps into code that starts at its end (no padding, not 16-aligned)" % parent
            elif hard or fromu:
                rec["cls"] = "b"
                rec["why"] = "referenced: " + ", ".join(sorted(kinds))
            elif mid:
                rec["cls"] = "c"
                rec["why"] = "only jumped into mid-body from listed code (%s); not an entry" % ", ".join(sorted({x[0] for x in mid}))
            else:
                rec["cls"] = "c"
                rec["why"] = "no references" if not deadu else "referenced only from unreferenced code"
            out.append(rec)
        return out


# --- pass 2 driver ------------------------------------------------------------------------------------------------
LIB_SPAN_NAMES = [(0x208B9C, 0x212BB0, "XAPILIB"), (0x3440E0, 0x356BF0, "LIBCMT+XAPILIB"), (0x35A7B0, 0x35BE88, "LIBCMT EH runtime")]
GAME_TEXT_END = 0x364840


def region_of(va, secs):
    for lo, hi, n in LIB_SPAN_NAMES:
        if lo <= va < hi:
            return "library:" + n
    if va >= GAME_TEXT_END:
        for s in secs:
            if s.va <= va < s.va + s.vsize:
                return "library:" + s.name
    return "game"


def sha1_file(path):
    import hashlib
    with open(path, "rb") as f:
        return hashlib.sha1(f.read()).hexdigest()


def make_b_row(x, md, refs, uses, scan, r):
    """(csv row, log record) for a class-b unit."""
    a, n = r["address"], r["size"]
    o = x.offset(a)
    raw = x.data[o:o + n]
    ins = list(md.disasm(raw, a))
    ptrs = [q for q in refs.get(a, []) if q[0] == "ptr"]
    imms = [q for q in refs.get(a, []) if q[0] == "imm"]
    name, note = "FUN_%08x" % a, "function"

    def unwind_pattern(q):
        v = x.u32(q[1] - 4)
        sv = v - (1 << 32) if v is not None and v >= 1 << 31 else v
        return sv is not None and -1 <= sv < 64
    if len(raw) == 10 and raw[0] == 0xB8 and raw[5] == 0xE9 and (imms or ptrs):
        name, note = "__ehhandler_%08x" % a, "EH frame-handler thunk (mov eax, offset funcinfo; jmp __CxxFrameHandler)"
    elif ptrs and not r["aligned16"] and not r["padded"] and all(unwind_pattern(q) for q in ptrs):
        name, note = "__unwindfunclet_%08x" % a, "EH unwind funclet (referenced as the action of an unwind-map entry)"
    elif n == 5 and ins and ins[0].mnemonic == "jmp" and ins[0].op_str.startswith("0x"):
        name, note = "thunk_FUN_%08x" % int(ins[0].op_str, 16), "jmp thunk"
    elif a in uses:
        name, note = "%s::vfunc_%d" % uses[a][0], "vtable slot (RTTI)"
    reg = region_of(a, scan.secs)
    kind = "eh" if note.startswith("EH") else ("library" if reg != "game" else "game")
    rec = {"address": "0x%08x" % a, "size": n, "name": name, "kind": kind, "region": reg, "note": note,
           "aligned16": r["aligned16"], "padded_before": r["padded"], "ends": r["term"], "insns": r["n_insn"],
           "why": r["why"], "refs": r["refs"][:6], "n_refs": len(r["refs"]),
           "parent_end": ("0x%08x" % r["parent"]) if r["parent"] else None}
    row = {"address": "0x%08x" % a, "size": str(n), "name": name, "calls": str(r["calls"]),
           "xrefs": str(len(r["refs"])), "is_thunk": "1" if note == "jmp thunk" else "0", "chunks": "1"}
    return row, rec


def pass2(argv):
    arg = lambda k, d=None: argv[argv.index(k) + 1] if k in argv else d
    src = arg("--in", CSV_IN)
    out = arg("--out", os.path.join(ROOT, "build/functions.csv.new"))
    log = arg("--log", LOG)
    start_sha = sha1_file(src)
    rows = list(csv.DictReader(open(src)))
    fields = list(rows[0].keys())
    x = Xbe(XBE_PATH)
    rtti = json.load(open(os.path.join(ROOT, "build/rtti.json")))
    uses = {}
    for c in rtti["classes"]:
        if c["name"]:
            for v in c["vtables"]:
                for i, f in enumerate(v["slots"]):
                    uses.setdefault(f, []).append((c["name"], i))
    cur = [dict(r) for r in rows]
    a_applied, rounds, added, conflicts = [], 0, [], []
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    while True:
        rounds += 1
        model = Model(x, cur)
        scan = GapScan(x, cur)
        refs = scan.collect(model)
        units = scan.segment(refs)
        recs = scan.classify(units, refs)
        listed = {int(r["address"], 16): r for r in cur}
        ext = [r for r in recs if r["cls"] == "a"]
        print("pass2 round %d: %d gaps, %d units (%s); a=%d b=%d c=%d" % (
            rounds, len(scan.gaps), len(units), dict(collections.Counter(u[0] for u in units)),
            len(ext), sum(r["cls"] == "b" for r in recs), sum(r["cls"] == "c" for r in recs)))
        for r in ext:
            p = r["parent"]
            old_size = None
            for row in cur:
                if int(row["address"], 16) == p:
                    old_size = int(row["size"])
                    row["size"] = str(r["end"] - p)
            a_applied.append({"parent": "0x%08x" % p, "old_size": old_size, "new_size": r["end"] - p,
                              "unit": "0x%08x" % r["address"], "new_end": "0x%08x" % r["end"],
                              "evidence": r["why"], "refs": r["refs"] + r["mid_refs"], "round": rounds})
        newrows = []
        if not ext:
            for r in recs:
                if r["cls"] == "b":
                    row, rec = make_b_row(x, md, refs, uses, scan, r)
                    rec["round"] = rounds
                    newrows.append(row)
                    added.append(rec)
        if not ext and not newrows or rounds >= 5:
            break
        cur = sorted(cur + newrows, key=lambda r: int(r["address"], 16))
    # --- conflicts: a unit with its own entry that executes into a listed function (SEH __finally tails) -------------
    for k, a, b, info in units:
        if k == "junk" and b in listed and info and info["n"]:
            rr = refs.get(a, [])
            if rr:
                conflicts.append({"address": "0x%08x" % a, "size": b - a, "falls_into": "0x%08x" % b,
                                  "why": "has its own entry (%s) and runs into listed 0x%08x (%s), which is called/pointed at on its own: "
                                         "one body with two entries; not applied" % (
                                             ", ".join(sorted({q[0] for q in rr})), b, listed[b]["name"]),
                                  "refs": [[q[0], "0x%08x" % q[1], q[2] if isinstance(q[2], str) else "0x%08x" % q[2]] for q in rr]})
    final = cur
    prev_end = -1
    for r in final:
        a = int(r["address"], 16)
        assert a >= prev_end, "overlap at 0x%x" % a
        prev_end = a + int(r["size"])
    # --- class c record -------------------------------------------------------------------------------------------
    csum = collections.Counter()
    cbytes = collections.Counter()
    clist = []
    for r in recs:
        if r["cls"] == "c":
            key = "code, " + r["why"].split(" (")[0]
            csum[key] += 1
            cbytes[key] += r["size"]
            clist.append(["0x%08x" % r["address"], r["size"], "code", r["why"].split(" (")[0]])
    for k, a, b, info in units:
        if k in ("jtab", "btab", "junk", "pad"):
            key = {"jtab": "jump table (dword code pointers)", "btab": "index / data table in .text",
                   "junk": "does not decode as a terminated body (data / library blob / SEH tail)",
                   "pad": "alignment NOPs"}[k]
            csum[key] += 1
            cbytes[key] += b - a
            clist.append(["0x%08x" % a, b - a, k, key])
    bk = collections.Counter(x_["kind"] for x_ in added)
    bb = collections.Counter()
    for x_ in added:
        bb[x_["kind"]] += x_["size"]
    summary = {"gaps_with_non_padding": len(scan.gaps), "units": dict(collections.Counter(u[0] for u in units)),
               "a_extended": len(a_applied), "b_added": len(added), "b_by_kind": dict(bk), "b_bytes_by_kind": dict(bb),
               "c_units": len(clist), "c_by_reason": dict(csum), "c_bytes_by_reason": dict(cbytes),
               "conflicts": len(conflicts), "entries_before": len(rows), "entries_after": len(final)}
    section = {"input": os.path.relpath(src, ROOT), "input_sha1": start_sha, "summary": summary, "a_extended": a_applied,
               "b_added": sorted(added, key=lambda e: e["address"]), "conflicts": conflicts, "c_units": clist}
    print(json.dumps(summary, indent=1))
    d = json.load(open(log)) if os.path.exists(log) else {}
    d["pass2"] = section
    if "--dry-run" in argv:
        return
    json.dump(d, open(log, "w"), indent=1)
    tmp = out + ".tmp"
    with open(tmp, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fields)
        w.writeheader()
        w.writerows(final)
    os.replace(tmp, out)
    print("wrote", out)
    tag = arg("--install")
    if tag:
        import shutil
        live = CSV_IN
        want = arg("--live-sha", start_sha)       # the sha1 the live file must still have (default: the input's)
        if sha1_file(live) != want:
            sys.exit("refusing to install: %s has sha1 %s, expected %s" % (live, sha1_file(live), want))
        bak = live + ".bak-" + tag
        if not os.path.exists(bak):
            shutil.copy2(live, bak)
        os.replace(out, live)
        print("installed over %s (backup %s)" % (live, bak))


def main(argv):
    if "--sources" in argv:
        return check_sources(argv)
    if "--pass2" in argv:
        return pass2(argv)
    arg = lambda k, d=None: argv[argv.index(k) + 1] if k in argv else d
    src = arg("--in", CSV_IN)
    out = arg("--out", os.path.join(ROOT, "build/functions.csv.new"))
    log = arg("--log", LOG)
    rows = list(csv.DictReader(open(src)))
    fields = list(rows[0].keys())
    x = Xbe(XBE_PATH)
    orig = {int(r["address"], 16): dict(r) for r in rows}
    cur = [dict(r) for r in rows]
    all_changes, all_conflicts = [], []
    for rnd in range(1, 6):
        model = Model(x, cur)
        final_model = model
        changes, conflicts, removed, new_size = run_once(model, None)
        print("round %d: %d extended, %d fragments folded, %d conflicts" %
              (rnd, len(changes), len(removed), len(conflicts)))
        if not changes:
            all_conflicts = conflicts
            break
        for c in changes:
            c["round"] = rnd
        all_changes += changes
        all_conflicts = conflicts
        nxt = []
        for r in cur:
            a = int(r["address"], 16)
            if a in removed:
                continue
            if a in new_size:
                r["size"] = str(new_size[a])
            nxt.append(r)
        cur = nxt
    # fold the per-round changes into a final per-address picture
    final = {int(r["address"], 16): int(r["size"]) for r in cur}
    ext = {}
    for c in all_changes:
        a = int(c["address"], 16)
        e = ext.setdefault(a, {"address": c["address"], "old_size": orig[a]["size"], "evidence": [],
                               "absorbed": []})
        e["evidence"] += c["evidence"]
        e["absorbed"] += c["absorbed"]
        e["new_size"] = final.get(a, c["new_size"])
    removed_all = {}
    for a, e in ext.items():
        e["old_size"] = int(e["old_size"])
    for a, e in list(ext.items()):
        for ab in e["absorbed"]:
            removed_all[int(ab["address"], 16)] = {"address": ab["address"], "size": ab["size"], "parent": e["address"],
                                                    "evidence": e["evidence"]}
        if a not in final:
            del ext[a]          # itself folded into a larger parent in a later round
    for fa in list(removed_all):
        if fa in final:
            del removed_all[fa]
    for a in orig:
        if a not in final and a not in removed_all:
            # folded in a later round into a function that absorbed its parent
            removed_all[a] = {"address": "0x%08x" % a, "size": int(orig[a]["size"]), "parent": None, "evidence": []}
    for a, f in removed_all.items():
        if f["parent"] is None or int(f["parent"], 16) not in final:
            k = bisect.bisect_right(sorted(final), a) - 1
            f["parent"] = "0x%08x" % sorted(final)[k]
    for a, e in ext.items():       # sanity: how the corrected body ends
        end, _, _, _, _ = final_model.walk(a, e["new_size"])
        seen = final_model.last_seen
        tail = max((v for v in seen if v + seen[v] == a + e["new_size"]), default=None)
        o = x.offset(a + e["new_size"])
        e["ends_with"] = None if tail is None else {
            "last_insn": "0x%08x" % tail, "kind": final_model.w.ins(tail)[1],
            "next_byte": None if o is None else "%02x" % x.data[o],
            "next_is_listed_start": (a + e["new_size"]) in final}
        e["still_walks_past_end"] = end > a + e["new_size"]
    result = {"input": os.path.relpath(src, ROOT), "extended": sorted(ext.values(), key=lambda e: e["address"]),
              "removed": sorted(removed_all.values(), key=lambda e: e["address"]),
              "conflicts": all_conflicts}
    if "--dry-run" not in argv:
        os.makedirs(os.path.dirname(log), exist_ok=True)
        json.dump(result, open(log, "w"), indent=1)
        tmp = out + ".tmp"
        with open(tmp, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=fields)
            w.writeheader()
            w.writerows(cur)
        os.replace(tmp, out)
    print("extended %d, removed %d, conflicts %d; %d -> %d entries" %
          (len(ext), len(removed_all), len(all_conflicts), len(rows), len(cur)))


if __name__ == "__main__":
    main(sys.argv[1:])
