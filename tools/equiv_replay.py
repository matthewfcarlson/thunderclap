#!/usr/bin/env python3
"""Trace-driven equivalence: replay game states recorded from the real game (docs/equivalence.md, "Trace replay").

  tools/equiv_replay.py [--session build/traces/NAME] --equivalent           # every equivalent/ function captured
  tools/equiv_replay.py --only 0x00241390,0x0026ce10                         # equivalent/0xADDR.cpp
  tools/equiv_replay.py --src build/farm/equiv-demoted/0x0004dc60.cpp 0x0004dc60 [--json]
  tools/equiv_replay.py --matches 200                                        # false-failure check on matches

tools/trace_capture.py records, for the first N calls of each function, the real state at entry (registers,
the stack window, every memory page the function reads, per memory epoch), what each callee really did
(return registers, x87 result, the bytes it changed in the caller's frame; memory it changed elsewhere is in
the pages re-read after the call) and the real outcome. Replay runs the original bytes and our object on
each recorded state with equiv.py's level-3 machinery (same Unicorn setup, same comparison rules), feeding
both sides the recorded callee results in order instead of fuzzed stubs. The original's replay must
reproduce the recorded outcome; when it doesn't, the capture is incomplete and that call isn't counted.

Library: replay(src, addr, store, max_calls=None) -> report dict; TraceStore, TraceMemory, TraceRun are shared
with tools/trace_capture.py.
"""
import argparse
import hashlib
import json
import os
import pickle
import sqlite3
import struct
import sys
import time
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import equiv  # noqa: E402
from equiv import (CALLEE_SAVED, FSLOT, M32, PAGE, STACK_HI, STACK_LO, TRAMP, Run)  # noqa: E402

ROOT = equiv.ROOT
TRACES = os.path.join(ROOT, "build/traces")
STACK_WORDS = 64            # stack words recorded above the return address (arguments and some caller frame)
FRAME_BELOW = 0x10000       # guest addresses this far below the entry esp are the function's own frame
BASE_REACH = 0x1000         # a callee's write into the frame is located relative to a pointer this close below it


DEFAULT_ENTRY_ESP = equiv.ENTRY_ESP


def set_entry_esp(esp_g):
    """Give Unicorn's entry esp the game's low 12 bits, so `and esp, -8` (aligned frames) lays the frame out
    the same way. Returns the previous value (equiv.Run reads the module global; runs never overlap)."""
    old = equiv.ENTRY_ESP
    equiv.ENTRY_ESP = DEFAULT_ENTRY_ESP + (esp_g & 0xFFF) if esp_g is not None else DEFAULT_ENTRY_ESP
    return old


# ---------------------------------------------------------------------------------------------
# Storage: one sqlite file per capture session; pages are content-addressed and shared between calls.
class TraceStore:
    def __init__(self, path, create=False):
        if os.path.isdir(path):
            path = os.path.join(path, "trace.sqlite")
        if not create and not os.path.exists(path):
            raise FileNotFoundError(path)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        self.path = path
        self.db = sqlite3.connect(path, timeout=60, check_same_thread=False)   # (nested captures run in threads, one at a time)
        self.db.execute("PRAGMA journal_mode=WAL")
        self.db.executescript("""
            CREATE TABLE IF NOT EXISTS pages (sha TEXT PRIMARY KEY, data BLOB);
            CREATE TABLE IF NOT EXISTS calls (func INTEGER, n INTEGER, ok INTEGER, data BLOB, PRIMARY KEY (func, n));
            CREATE TABLE IF NOT EXISTS funcs (func INTEGER PRIMARY KEY, hits INTEGER, captured INTEGER,
                                              failed INTEGER, info TEXT);
            CREATE TABLE IF NOT EXISTS meta (k TEXT PRIMARY KEY, v TEXT);
        """)
        self._page_cache = {}

    def put_page(self, data):
        sha = hashlib.sha1(data).hexdigest()[:20]
        if sha not in self._page_cache:
            self.db.execute("INSERT OR IGNORE INTO pages VALUES (?, ?)", (sha, zlib.compress(data, 3)))
            self._page_cache[sha] = data
        return sha

    def get_page(self, sha):
        b = self._page_cache.get(sha)
        if b is None:
            row = self.db.execute("SELECT data FROM pages WHERE sha = ?", (sha,)).fetchone()
            b = zlib.decompress(row[0]) if row else None
            if len(self._page_cache) > 20000:
                self._page_cache.clear()
            self._page_cache[sha] = b
        return b

    def put_call(self, func, n, rec):
        self.db.execute("INSERT OR REPLACE INTO calls VALUES (?, ?, ?, ?)",
                        (func, n, 1 if rec.get("selfcheck") == "ok" else 0, zlib.compress(pickle.dumps(rec), 3)))

    def calls(self, func, only_ok=False, limit=None):
        q = "SELECT data FROM calls WHERE func = ?" + (" AND ok = 1" if only_ok else "") + " ORDER BY n"
        if limit:
            q += " LIMIT %d" % int(limit)
        return [pickle.loads(zlib.decompress(r[0])) for r in self.db.execute(q, (func,))]

    def funcs(self):
        """{func: {captured, ok}} for every function with at least one recorded call."""
        out = {}
        for f, n, ok in self.db.execute("SELECT func, COUNT(*), SUM(ok) FROM calls GROUP BY func"):
            out[f] = {"captured": n, "ok": ok or 0}
        return out

    def func_stats(self):
        return {f: {"hits": h, "captured": c, "failed": fl, "info": json.loads(i or "{}")}
                for f, h, c, fl, i in self.db.execute("SELECT * FROM funcs")}

    def set_func(self, func, hits, captured, failed, info):
        self.db.execute("INSERT OR REPLACE INTO funcs VALUES (?, ?, ?, ?, ?)",
                        (func, hits, captured, failed, json.dumps(info)))

    def meta(self, k, v=None):
        if v is not None:
            self.db.execute("INSERT OR REPLACE INTO meta VALUES (?, ?)", (k, json.dumps(v)))
            return v
        row = self.db.execute("SELECT v FROM meta WHERE k = ?", (k,)).fetchone()
        return json.loads(row[0]) if row else None

    def commit(self):
        self.db.commit()


def latest_session():
    if not os.path.isdir(TRACES):
        return None
    ss = [os.path.join(TRACES, d) for d in os.listdir(TRACES)
          if os.path.exists(os.path.join(TRACES, d, "trace.sqlite"))]
    return max(ss, key=lambda p: os.path.getmtime(os.path.join(p, "trace.sqlite"))) if ss else None


# ---------------------------------------------------------------------------------------------
# Memory: the recorded guest pages, per memory epoch (epoch k = after the k-th callee returned).
_STATIC = None


def static_page(prog, page):
    """Pages served from the original XBE instead of the guest: code that is never written (.text, BINK*),
    the header, and the null region. (.rdata comes from the guest: the kernel thunk table is patched at load.)"""
    global _STATIC
    if _STATIC is None:
        _STATIC = []
        for s in prog.xbe.sections:
            if not (s.flags & 1) and s.name != ".rdata":
                _STATIC.append((s.va & ~0xFFF, (s.va + s.vsize + 0xFFF) & ~0xFFF, s.name))
    if page < equiv.NULL_HI or page == equiv.IMAGE_LO:
        return True
    for lo, hi, name in _STATIC:
        if lo <= page < hi:
            # a page shared with a writable section's head/tail is not static
            return all(not (s.flags & 1) and s.name != ".rdata" for s in prog.xbe.sections
                       if s.va < page + PAGE and s.va + s.vsize > page)
    return False


class TraceMemory:
    """equiv.Machine's interface over recorded pages. Capture mode (fetch given): pages are read from the
    paused guest when first touched in an epoch and recorded. Replay mode: recorded pages; a page touched
    in an epoch it wasn't recorded in is served from the nearest earlier recording (else the next one), and a
    page never recorded reads as zeros; both are noted (`inexact`, `unrecorded`)."""

    stable = False

    def __init__(self, prog, index=None, store=None, fetch=None):
        self.prog = prog
        self.index = dict(index or {})          # (page, epoch) -> page sha
        self.store = store
        self.fetch = fetch
        self.captured = {}                      # capture mode: (page, epoch) -> bytes
        self.unrecorded, self.inexact, self.bad = set(), set(), set()
        self._cache = {}
        self._by_page = {}
        for (p, e) in self.index:
            self._by_page.setdefault(p, []).append(e)

    def page(self, page, epoch):
        key = (page, epoch)
        b = self._cache.get(key)
        if b is not None:
            return b
        if static_page(self.prog, page):
            b = self.prog.image_page(page) if page >= equiv.NULL_HI else bytes(PAGE)
        elif self.fetch is not None:
            b = self.fetch(page)
            if b is None:
                self.bad.add(page)
                b = bytes(PAGE)
            self.captured[key] = b
        elif key in self.index:
            b = self.store.get_page(self.index[key])
        else:
            eps = sorted(self._by_page.get(page, ()))
            if eps:
                before = [e for e in eps if e <= epoch]
                e = before[-1] if before else eps[0]
                b = self.store.get_page(self.index[(page, e)])
                self.inexact.add(page)
            else:
                b = bytes(PAGE)
                self.unrecorded.add(page)
        self._cache[key] = b
        return b

    def byte(self, addr, epoch):
        p = addr & ~0xFFF
        return self.page(p, epoch)[addr - p]


# ---------------------------------------------------------------------------------------------
# Execution: equiv.Run with recorded callee results instead of fuzzed ones.
def _known(insn):
    return insn.target is not None or (insn.mem is not None and insn.mem[1] is None and insn.mem[2] is None)


class TraceRun(Run):
    """One run (original or ours) on one recorded call. `trace` is the call record; in capture mode `syncer`
    drives the real game alongside (tools/trace_capture.py) and fills the record's results as calls happen."""

    def __init__(self, *a, trace=None, side="orig", syncer=None, **kw):
        super().__init__(*a, **kw)
        self.trace = trace
        self.side = side
        self.syncer = syncer
        self.base_misses = 0            # recorded frame writes we couldn't place in our frame
        self.beyond_trace = False       # more calls than the recording has
        self.seg_stack_w = set()        # capture: stack bytes written in the current segment
        self.ended_by_tail = False

    def _setup(self):
        super()._setup()
        fpcw = self.trace["entry"].get("fpcw")
        if fpcw is not None:
            self.uc.reg_write(self.u.UC_X86_REG_FPCW, fpcw)
        below = self.trace["entry"].get("below")
        if self.syncer is not None and below:
            # capture: Unicorn runs on the game's own stack contents (uninitialised locals included), so it
            # repeats the game exactly. Replay gives both sides STACK_FILL, as in level 3
            self.uc.mem_write(equiv.ENTRY_ESP - len(below), below)

    def _on_write(self, uc, access, addr, size, value, _):
        super()._on_write(uc, access, addr, size, value, _)
        if self.syncer is not None and STACK_LO <= addr < STACK_HI:
            self.seg_stack_w.update(range(addr, addr + size))

    def stack_top(self):
        return equiv.ENTRY_ESP + 4 + 4 * len(self.inp["stack"])

    def _stub(self, insn, target, tail):
        k = len(self.calls)
        esp = self.reg("esp")
        top = self.stack_top()
        snap = bytes(self.uc.mem_read(esp, top - esp)) if esp < top else b""
        # (the fuzzing stub first: it reads what the call passes at the current memory epoch; in capture mode
        # the game only then runs the callee)
        super()._stub(insn, target, tail)
        if self.syncer is not None:
            res = self.syncer.sync(self, insn, target, tail, k, esp)
        else:
            rs = self.trace["results"]
            res = rs[k] if k < len(rs) else None
        if tail:
            self.ended_by_tail = True
        if res is None:
            self.beyond_trace = True
            return
        if res.get("noreturn"):
            return
        if self.syncer is not None:
            self.syncer.finish(self, res, snap, esp, k, tail)
        self._apply(insn, target, res, snap, esp, k, tail)

    def base_value(self, key, k):
        if key[0] == "entry":
            return equiv.ENTRY_ESP
        c = self.calls[k]
        if key[0] == "arg":
            v = c["args"][key[1]][0] if key[1] < len(c["args"]) else None
        else:
            v = c["regs"].get(key[1])
        if v is None or not (STACK_LO <= v < STACK_HI):
            return None
        return v

    def resolve(self, enc, k):
        if enc is None:
            return None
        if enc[0] == "raw":
            return enc[1]
        b = self.base_value(enc[1], k)
        if b is None or (self.syncer is None and enc[1][0] == "entry" and enc[2] < 0):
            self.base_misses += 1
            return None
        return (b + enc[2]) & M32

    def _apply(self, insn, target, res, snap, esp, k, tail):
        uc = self.uc
        if not tail:
            if snap and self.reg("esp") <= esp:     # (not after a >252-byte pop, which moved the return address)
                uc.mem_write(esp, snap)         # undo the fuzzing stub's out-parameter fills
            frame = res.get("frame")
            if self.syncer is not None and frame:
                off, data = frame               # capture: the game's frame after the call, byte for byte
                uc.mem_write(equiv.ENTRY_ESP + off, data)
                uc.mem_write(equiv.ENTRY_ESP, struct.pack("<I", equiv.SENTINEL))    # (not the game's return address)
                return self._apply_regs(insn, target, res, k)
            # Replay, both sides alike: what the callee wrote into the frame, placed relative to the pointer it
            # got (our frame is laid out differently): the bytes it changed, and the bytes its static write
            # extent covers through each pointer. A write no argument of this call points at (through a pointer
            # stored earlier) can't be placed in our frame, so neither side gets it.
            # The original's run places each write first and decides for both: a write into the incoming
            # arguments (identical layout on both sides) goes to the same slot in ours; one into the frame goes
            # relative to its pointer, and must stay in our frame; one the original can't place is skipped.
            place = self.trace.setdefault("_place", {})
            entry = equiv.ENTRY_ESP
            for i, (key, off, data) in enumerate(list(res.get("delta", ())) + list(res.get("fills", ()))):
                n = len(data)
                if self.side == "orig":
                    b = None if key[0] == "entry" and off < 0 else self.base_value(key, k)
                    a = None if b is None else b + off
                    if a is None or (a < entry + 4 and a + n > entry) or not (STACK_LO <= a and a + n <= STACK_HI):
                        place[(k, i)] = a = None
                    else:
                        place[(k, i)] = ("args", a - entry) if a >= entry + 4 else ("frame",)
                else:
                    how = place.get((k, i))
                    if how is None:
                        a = None
                    elif how[0] == "args":
                        a = entry + how[1]
                    else:
                        b = self.base_value(key, k)
                        a = None if b is None or key[0] == "entry" else b + off
                        if a is not None and a + n > entry:
                            a = None
                if a is None:
                    self.base_misses += 1
                    continue
                uc.mem_write(a, data)
                self.stack_written.update(range(a, a + n))
        self._apply_regs(insn, target, res, k)

    def _apply_regs(self, insn, target, res, k):
        uc = self.uc
        clobbers = self.prog.reg_writes(target) if _known(insn) else None
        if clobbers is None:
            clobbers = {"eax", "ecx", "edx"}
        for r in ("eax", "edx", "ecx"):
            if r in clobbers and r in res:
                v = self.resolve(res[r], k)
                if v is not None:
                    uc.reg_write(equiv._uc_regs()[r], v)
        if res.get("st0") is not None:
            eip = self.reg("eip")
            if TRAMP + 0x800 <= eip < TRAMP + 0xC00:
                # the stub returns through `fld dword [FSLOT]`: use the qword variant with the real result
                uc.reg_write(self.u.UC_X86_REG_EIP, eip - 0x400)
                uc.mem_write(FSLOT, struct.pack("<d", res["st0"]))


def make_input(entry):
    stack = list(entry["stack"])
    nown = entry.get("own_args") or 0
    return {"seed": 0, "regs": dict(entry["regs"]), "stack": stack, "own_args": stack[:nown],
            "own_pop": entry.get("own_pop"), "arity_by_call": {}, "ret_override": {}, "wext_by_call": {},
            "extra_by_call": {}, "dictionary": (), "stub_mode": "normal"}


class TraceNamer(equiv.Namer):
    """Name addresses relative to the real `this` and pointer arguments (equiv.Namer only knows the fuzz heap)."""

    def __init__(self, inp, sig, prog):
        super().__init__(inp, sig, prog)
        self.bases = []
        if sig and sig.get("this"):
            self.bases.append(("this", inp["regs"]["ecx"]))
        for i, w in enumerate(inp["own_args"]):
            if 0x10000 <= w and not (equiv.IMAGE_LO <= w < equiv.IMAGE_HI):
                self.bases.append(("arg%d" % i, w))


def run_original(prog, oview, trace, store, helpers, ours_image=None, psizes=None, convs=None, varargs=(),
                 own_float=False, max_steps=2000000):
    set_entry_esp(trace["entry"].get("esp_g"))
    trace.pop("_place", None)
    inp = make_input(trace["entry"])
    mach = TraceMemory(prog, trace["pages"], store)
    orun = TraceRun(prog, oview, mach, inp, ours_image=ours_image, sig=None, max_steps=max_steps,
                    own_float_ret=own_float, coverage=True, helpers=helpers, trace=trace, side="orig")
    orun.pointee_sizes = psizes or {}
    orun.convs = convs or {}
    orun.slot_arity = {}
    orun.loop_limits = {}
    orun.varargs = set(varargs)
    return inp, mach, orun, orun.run(oview.entry)


def selfcheck(o, orun, mach, trace):
    """Does the original's replay reproduce what the capture recorded? None if so, else why not."""
    out = trace["outcome"]
    if o["status"] != out["status"]:
        return "status %s, recorded %s" % (o["status"], out["status"])
    if [c["target"] for c in o["calls"]] != out["targets"]:
        return "call targets differ from the recording"
    if mach.unrecorded or mach.inexact:
        return "read %d unrecorded and %d other-epoch pages" % (len(mach.unrecorded), len(mach.inexact))
    if o["status"] == "ret" and not o.get("noreturn"):
        if (o["eax"], o["edx"]) != (out["eax"], out["edx"]):
            return "returned eax=%#x edx=%#x, recorded %#x %#x" % (o["eax"], o["edx"], out["eax"], out["edx"])
        last = {a: v for a, v in o["segments"][-1].items() if not (equiv.OURS <= a < equiv.OURS + equiv.OURS_SIZE)}
        if last != out["writes"]:
            bad = sorted(set(last.items()) ^ set(out["writes"].items()))[:1]
            return "final memory writes differ from the recording (first at %#x)" % bad[0][0]
    return None


def replay_level3(store, addr, max_calls=None, max_steps=2000000, time_budget=120):
    """A level3_fn for equiv.verify: replay every recorded call of addr."""
    def fn(prog, oview, rview, ours, orefs, sig, ret_kind, psizes, convs, decls, void_eax, issues):
        res = {"captured": 0, "replayed": 0, "agreed": 0, "mismatched": 0, "incomplete": 0, "mismatches": [],
               "incomplete_reasons": [], "notes": [], "level2_ok": not issues}
        if (convs or {}).get(oview.entry):
            res["unsupported"] = "the function itself has an equiv-conv annotation (register arguments)"
            res["status"] = "unsupported"
            return res
        traces = store.calls(addr, only_ok=True, limit=max_calls)
        res["captured"] = len(traces)
        res["capture_failed"] = (store.db.execute("SELECT COUNT(*) FROM calls WHERE func = ? AND ok = 0",
                                                  (addr,)).fetchone()[0])
        own_float = ret_kind in ("f32", "f64")
        varargs = {a for a, d in (decls or {}).items() if d and d.get("varargs")}
        helpers = dict(equiv.HELPERS)
        helpers.update({a: n for n, a in equiv.crt_table(prog).items()})
        caller_cleans = equiv.caller_cleaned(prog, oview)
        edges = set()
        t0 = time.process_time()
        for tr in traces:
            if time.process_time() - t0 > time_budget:
                res["time_budget_hit"] = True
                break
            inp, mach, orun, o = run_original(prog, oview, tr, store, helpers, (equiv.OURS, ours.image), psizes,
                                              convs, varargs, own_float, max_steps)
            why = selfcheck(o, orun, mach, tr)
            if why:
                res["incomplete"] += 1
                if len(res["incomplete_reasons"]) < 3:
                    res["incomplete_reasons"].append({"call": tr["n"], "why": why})
                continue
            if o["status"] == "ret":
                edges.update(orun.edges)
            rmach = TraceMemory(prog, tr["pages"], store)
            rrun = TraceRun(prog, rview, rmach, inp, ours_image=(equiv.OURS, ours.image), sig=sig,
                            max_steps=max_steps * 2, own_float_ret=own_float, helpers=helpers, trace=tr, side="ours")
            rrun.pointee_sizes = psizes or {}
            rrun.intrinsics = {a: n for a, n in ours.poison.items() if n in equiv.INTRINSIC_NAMES}
            rrun.local_code = (equiv.OURS, ours.end)
            rrun.self_alias = oview.entry
            rrun.convs = convs or {}
            rrun.decls = decls or {}
            rrun.varargs = varargs
            rrun.caller_cleans = caller_cleans
            rrun.slot_arity = {}
            r = rrun.run(rview.entry)
            # compare against the original's memory as recorded (both runs read the same pages)
            diffs = equiv.compare_runs(o, r, ret_kind, mach, TraceNamer(inp, sig, prog), prog, void_eax=void_eax)
            res["replayed"] += 1
            note = []
            if rmach.unrecorded:
                note.append("ours read %d page(s) the original never touched (%s)" % (
                    len(rmach.unrecorded), ", ".join("%#x" % p for p in sorted(rmach.unrecorded)[:3])))
            if rrun.base_misses:
                note.append("%d recorded frame write(s) had no matching pointer in ours" % rrun.base_misses)
            if diffs:
                res["mismatched"] += 1
                if len(res["mismatches"]) < 5:
                    res["mismatches"].append({"call": tr["n"], "diffs": diffs[:4], "notes": note,
                                              "context": tr.get("context")})
            else:
                res["agreed"] += 1
                if note and len(res["notes"]) < 3:
                    res["notes"].append({"call": tr["n"], "notes": note})
        res["coverage"] = equiv.coverage_of(oview, edges)
        res["coverage"].pop("uncovered", None)
        if res["replayed"] == 0:
            res["status"] = "no_replay" if res["captured"] or res["incomplete"] else "not_reached"
        else:
            res["status"] = "mismatch" if res["mismatched"] else "agreed"
        return res
    return fn


def replay(src, addr, store, max_calls=None, flags=(), time_budget=120):
    """Replay every recorded call of addr against SRC. Returns {addr, src, status, ...}."""
    t0 = time.time()
    if not store.calls(addr, only_ok=False, limit=1):
        return {"addr": "0x%08x" % addr, "src": src, "status": "not_reached"}
    rep = equiv.verify(src, addr, flags=flags, max_level=3, level3_fn=replay_level3(store, addr, max_calls,
                                                                                    time_budget=time_budget))
    out = {"addr": "0x%08x" % addr, "src": src, "time": round(time.time() - t0, 1)}
    if "replay" not in rep:
        out.update(status=rep.get("status", "error"), error=rep.get("error"))
        return out
    out.update(rep["replay"])
    out["byte_identical"] = rep.get("byte_identical")
    return out


def _job(args):
    session, src, addr, max_calls = args
    try:
        return replay(src, addr, TraceStore(session), max_calls)
    except Exception as e:      # one broken source must not stop the batch
        import traceback
        return {"addr": "0x%08x" % addr, "src": src, "status": "error", "error": repr(e)[:200],
                "trace": traceback.format_exc()[-600:]}


def sources(kind):
    d = os.path.join(ROOT, kind)
    out = []
    for f in sorted(os.listdir(d)):
        if f.startswith("0x") and f.endswith(".cpp"):
            out.append((os.path.join(kind, f), int(f[:-4], 16)))
    return out


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--session", help="capture session directory (default: the newest under build/traces)")
    ap.add_argument("--equivalent", action="store_true", help="every equivalent/ source with a capture")
    ap.add_argument("--matches", help="N or all: matches/ sources with a capture (false-failure check)")
    ap.add_argument("--only", help="comma-separated addresses (equivalent/ sources, else matches/)")
    ap.add_argument("--src", nargs=2, metavar=("SRC", "ADDR"), action="append", default=[],
                    help="replay one source file against one address (repeatable)")
    ap.add_argument("--max-calls", type=int, help="replay at most this many recorded calls per function")
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--out", help="write all results here (default: SESSION/replay-<kind>.json)")
    a = ap.parse_args(argv)
    session = a.session or latest_session()
    if not session:
        raise SystemExit("no capture session under build/traces (run tools/trace_capture.py)")
    store = TraceStore(session)
    have = store.funcs()
    jobs = [(s, int(ad, 16)) for s, ad in a.src]
    kind = "src"
    if a.equivalent or a.only:
        kind = "equivalent"
        eq = dict((ad, s) for s, ad in sources("equivalent"))
        if a.only:
            want = [int(x, 16) for x in a.only.split(",")]
            ma = dict((ad, s) for s, ad in sources("matches"))
            jobs += [(eq.get(w) or ma.get(w), w) for w in want if eq.get(w) or ma.get(w)]
        else:
            jobs += [(s, ad) for ad, s in sorted(eq.items()) if ad in have]
    if a.matches:
        kind = "matches"
        ms = [(s, ad) for s, ad in sources("matches") if ad in have]
        jobs += ms if a.matches == "all" else ms[:int(a.matches)]
    if not jobs:
        raise SystemExit("nothing to replay (%d functions captured in %s)" % (len(have), session))
    print("replaying %d functions from %s" % (len(jobs), os.path.relpath(session, ROOT)), file=sys.stderr)
    results = []
    work = [(session, s, ad, a.max_calls) for s, ad in jobs]
    if a.jobs > 1 and len(work) > 1:
        import multiprocessing as mp
        with mp.get_context("fork").Pool(min(a.jobs, 3)) as pool:
            for r in pool.imap_unordered(_job, work):
                results.append(r)
                _progress(r, a.json)
    else:
        for w in work:
            r = _job(w)
            results.append(r)
            _progress(r, a.json)
    results.sort(key=lambda r: r["addr"])
    from collections import Counter
    summary = dict(Counter(r.get("status", "?") for r in results))
    out = a.out or os.path.join(session, "replay-%s.json" % kind)
    json.dump({"session": os.path.relpath(session, ROOT), "summary": summary, "results": results},
              open(out, "w"), indent=1)
    print("summary: %s -> %s" % (summary, os.path.relpath(out, ROOT)), file=sys.stderr)
    return 1 if summary.get("mismatch") else 0


def _progress(r, as_json):
    if as_json:
        print(json.dumps(r))
        return
    s = "%s %-11s calls=%s replayed=%s agreed=%s mismatched=%s incomplete=%s" % (
        r["addr"], r.get("status", "?"), r.get("captured"), r.get("replayed"), r.get("agreed"), r.get("mismatched"),
        r.get("incomplete"))
    if r.get("mismatches"):
        s += "\n    first mismatch (call %s): %s" % (r["mismatches"][0]["call"], "; ".join(r["mismatches"][0]["diffs"][:2]))
    if r.get("error"):
        s += "\n    error: %s" % r["error"]
    print(s, flush=True)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
