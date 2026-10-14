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
    for e in d["extended"]:
        old[e["address"]] = ("parent", e["old_size"], e["new_size"], e["address"])
    for e in d["removed"]:
        old[e["address"]] = ("removed fragment", e["size"], None, e["parent"])
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
            if role != "parent":
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
    d["sources"] = res
    json.dump(d, open(log, "w"), indent=1)


def main(argv):
    if "--sources" in argv:
        return check_sources(argv)
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
