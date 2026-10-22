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
# (round 12) A/B switches, like equiv.py's EQUIV_OFF: REPLAY_OFF=x87arg,scratchkey,... turns the named changes off
REPLAY_OFF = set(os.environ.get("REPLAY_OFF", "").split(","))
# Captures made before b566e0d3 ("read ST(0) as xemu sends it", 2026-10-12 13:41:58 -0500) recorded the physical
# x87 register instead of ST(0): their callee float results are wrong (sessions s1, t1, t2)
ST0_FIX_TIME = 1791830518
PRE_ST0_FIX = {"s1", "t1", "t2"}
MAX_STEPS_REPLAY = 16000000     # (round 12, steps) the original's step budget when the default one runs out


def pre_st0_fix(path):
    """Was this session captured before the ST(0) fix? (by name, else by the capture's own files' times)"""
    d = path if os.path.isdir(path) else os.path.dirname(path)
    if os.path.basename(os.path.normpath(d)) in PRE_ST0_FIX:
        return True
    for f in ("session.json", "capture.json"):
        q = os.path.join(d, f)
        if os.path.exists(q):
            return os.path.getmtime(q) < ST0_FIX_TIME
    return False


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
        self.pre_st0_fix = pre_st0_fix(path)
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

    def calls_spread(self, func, limit):
        """Like calls(only_ok=True) but at most `limit` of them, spread evenly over the recording."""
        ns = [r[0] for r in self.db.execute("SELECT n FROM calls WHERE func = ? AND ok = 1 ORDER BY n", (func,))]
        if limit and len(ns) > limit:
            ns = [ns[(i * len(ns)) // limit] for i in range(limit)]
        return [pickle.loads(zlib.decompress(r[0])) for n in ns for r in
                self.db.execute("SELECT data FROM calls WHERE func = ? AND n = ?", (func, n))]

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

    def __init__(self, *a, trace=None, side="orig", syncer=None, skip_unknown=None, **kw):
        super().__init__(*a, **kw)
        self.trace = trace
        self.side = side
        self.syncer = syncer
        self.base_misses = 0            # recorded frame writes we couldn't place in our frame
        self.beyond_trace = False       # more calls than the recording has
        self.seg_stack_w = set()        # capture: stack bytes written in the current segment
        self.ended_by_tail = False
        self.st0_used = 0               # recorded x87 results this run took (pre-fix sessions: unreliable)
        # (round 12, unknown) None, or the recorded bytes to keep among those that may not be callee writes: the
        # others are left out (a set of (call, piece, byte))
        self.skip_unknown = skip_unknown
        self.unknown_placed = 0         # recorded bytes placed that lay below the stack pointer since the last call
        self.unk_live = {}              # (orig) such a byte's address -> (call, piece, byte), until the code writes it
        self.unk_read = set()           # (orig) such bytes the original's own code read
        self.prefix_hi = None           # the highest esp since the last call returned (or since entry)
        self.arg_access = {}            # (orig) incoming argument byte -> [(calls made so far, "r"/"w")]
        self.dropped = {"xlate": 0, "scratchkey": 0}

    def _setup(self):
        super()._setup()
        fpcw = self.trace["entry"].get("fpcw")
        if fpcw is not None:
            self.uc.reg_write(self.u.UC_X86_REG_FPCW, fpcw)
        fpsw = self.trace["entry"].get("fpsw")
        if fpsw is not None:
            # the sticky exception flags and condition codes the game had (code that returns after fnstsw ax
            # leaves them in eax); not TOP: the x87 stack is empty at a call
            self.uc.reg_write(self.u.UC_X86_REG_FPSW, fpsw & 0x477F)
        below = self.trace["entry"].get("below")
        if self.syncer is not None and below:
            # capture: Unicorn runs on the game's own stack contents (uninitialised locals included), so it
            # repeats the game exactly. Replay gives both sides STACK_FILL, as in level 3
            self.uc.mem_write(equiv.ENTRY_ESP - len(below), below)
        if self.syncer is None:
            if "unknown" not in REPLAY_OFF and self.side == "orig":
                # (the original's run decides which recorded bytes may not be callee writes)
                self.prefix_hi = equiv.ENTRY_ESP
                from unicorn import UC_HOOK_MEM_READ
                self.uc.hook_add(UC_HOOK_MEM_READ, self._on_frame_read, begin=STACK_LO, end=equiv.ENTRY_ESP - 1)
            if self.side == "orig" and "deadarg" not in REPLAY_OFF and self.inp["stack"]:
                from unicorn import UC_HOOK_MEM_READ
                self.uc.hook_add(UC_HOOK_MEM_READ, self._on_arg_read, begin=equiv.ENTRY_ESP + 4,
                                 end=self.stack_top() - 1)

    def _on_write(self, uc, access, addr, size, value, _):
        super()._on_write(uc, access, addr, size, value, _)
        if self.syncer is not None and STACK_LO <= addr < STACK_HI:
            self.seg_stack_w.update(range(addr, addr + size))
        if self.unk_live:
            for x in range(addr, addr + size):
                self.unk_live.pop(x, None)
        if self.syncer is None and self.side == "orig" and equiv.ENTRY_ESP + 4 <= addr < self.stack_top():
            for x in range(addr, addr + size):
                self.arg_access.setdefault(x, []).append((len(self.calls), "w"))

    def _on_frame_read(self, uc, access, addr, size, value, _):
        if self.unk_live:
            for x in range(addr, addr + size):
                w = self.unk_live.pop(x, None)
                if w is not None:
                    self.unk_read.add(w)

    def _on_arg_read(self, uc, access, addr, size, value, _):
        for x in range(addr, addr + size):
            self.arg_access.setdefault(x, []).append((len(self.calls), "r"))

    def arg_dead_after(self, k, lo, hi):
        """(orig) Does the original leave its incoming argument bytes lo..hi alone after call k returns (no read
        before a write of its own)?"""
        for x in range(lo, hi):
            ev = [e for n, e in self.arg_access.get(x, ()) if n > k]
            if ev and ev[0] == "r":
                return False
        return True

    def _on_code(self, uc, addr, size, _):
        if self.prefix_hi is not None and not TRAMP <= addr < TRAMP + PAGE:
            esp = uc.reg_read(self.u.UC_X86_REG_ESP)
            if esp > self.prefix_hi:
                self.prefix_hi = esp
        return super()._on_code(uc, addr, size, _)

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
            if self.side == "orig":
                place[k] = self._pieces(res, k, insn)
            for pi, pc in enumerate(place.get(k, ())):
                self._place_piece(pc, k, pi)
        if self.prefix_hi is not None:
            self.prefix_hi = 0                  # (the next instruction after the return sets it)
        self._apply_regs(insn, target, res, k)

    def _pieces(self, res, k, insn):
        """(orig) The recorded frame writes of call k as placement decisions, made once for both runs: a list of
        dicts {key, off, data, how, keep (bytes to place), unk (bytes that may not be callee writes)}."""
        entry = equiv.ENTRY_ESP
        uc = self.uc
        c = self.calls[k]
        frame = res.get("frame")
        esp_g = self.trace["entry"].get("esp_g")
        fbase = entry + frame[0] if frame else None
        g = frame[1] if frame else b""
        tgt = c["target"]
        # (round 12, scratchkey) a write the capture keyed to a register the callee doesn't take (eax after
        # `fnstsw ax` holding (&R & 0xffff0000) | fpsw, a loop's end pointer, `mov al, ..` over a pointer): the
        # callee can't have written through it. It goes behind the nearest pointer argument below it, else
        # nowhere (on both sides)
        allowed = None
        if "scratchkey" not in REPLAY_OFF:
            allowed = self.prog.reg_inputs(tgt) if c.get("known") and tgt in self.prog.funcs else None
            allowed = set(allowed) if allowed is not None else {"ecx", "edx"}
        items = [(key, off, data, False) for key, off, data in res.get("delta", ())] + \
                [(key, off, data, True) for key, off, data in res.get("fills", ())]
        out = []
        for key, off, data, is_fill in items:
            n = len(data)
            if key[0] == "reg" and allowed is not None and key[1] not in allowed:
                b0 = self.base_value(key, k)
                key = None
                if b0 is not None:
                    a0 = b0 + off
                    best = None
                    for j, (v, _) in enumerate(c["args"]):
                        if STACK_LO <= v <= a0 and a0 - v < BASE_REACH and (best is None or v > best[1]):
                            best = (j, v)
                    if best is not None:
                        key, off = ("arg", best[0]), a0 - best[1]
                if key is None:
                    self.dropped["scratchkey"] += 1
                    self.base_misses += 1
                    continue
            b = None if key[0] == "entry" and off < 0 else self.base_value(key, k)
            a = None if b is None else b + off
            if a is None or (a < entry + 4 and a + n > entry) or not (STACK_LO <= a and a + n <= STACK_HI):
                self.base_misses += 1
                continue
            data = bytearray(data)
            keep = [True] * n
            if fbase is not None and esp_g is not None and a < entry:
                gat = lambda x: g[x - fbase] if 0 <= x - fbase < len(g) else None
                if not is_fill and "widen" not in REPLAY_OFF:
                    # (round 12, widen) a delta that leaves part of a word alone assumed both sides had the
                    # game's bytes there; bytes the original never wrote itself get the game's too (a stale return
                    # address in a by-value struct's padding: 0x60.. in ours, 0x00.. in the original)
                    for lo, hi in ((a & ~3, a), (a + n, (a + n + 3) & ~3)):
                        if lo < hi and all(gat(x) is not None and x not in self.func_stack_written for x in range(lo, hi)):
                            ext = bytearray(gat(x) for x in range(lo, hi))
                            if lo < a:
                                data, keep, a, off = ext + data, [True] * (hi - lo) + keep, lo, off - (hi - lo)
                            else:
                                data, keep = data + ext, keep + [True] * (hi - lo)
                    n = len(data)
                if "xlate" not in REPLAY_OFF:
                    for w in range(a & ~3, a + n, 4):
                        if any(gat(x) is None for x in range(w, w + 4)):
                            continue
                        gw = struct.unpack("<I", bytes(gat(x) for x in range(w, w + 4)))[0]
                        if not esp_g - FRAME_BELOW <= gw < esp_g:
                            continue        # (only the function's own frame is Unicorn's: words above are recorded pages)
                        tu = (entry + (gw - esp_g)) & M32
                        ow = struct.unpack("<I", bytes(uc.mem_read(w, 4)))[0]
                        j0 = w - a
                        if tu == ow:
                            # (round 12, xlate) the game's stack address where Unicorn holds its own for the same
                            # word (a pushed &local: 0xd004.. against 0x7eff..): no callee wrote it
                            for x in range(max(0, j0), min(n, j0 + 4)):
                                keep[x] = False
                            self.dropped["xlate"] += 1
                        # (a stack address the callee stored stays the game's on both sides: equal, and reads
                        # through it see the recorded game pages; translated, it would differ by frame layout)
            unk = [False] * n
            if not is_fill and self.prefix_hi is not None:
                # (round 12, unknown) bytes that were below the stack pointer at some point since the last call
                # returned (or since entry): an interrupt frame or the gate trampoline may have left them, so
                # they may not be callee writes
                for i in range(n):
                    if a + i < self.prefix_hi:
                        unk[i] = True
            how = ("args", a - entry, b - entry) if a >= entry + 4 else None
            redirect = None
            if how is not None and fbase is not None and not is_fill and "widen" not in REPLAY_OFF and \
                    "redirwiden" not in REPLAY_OFF:
                # (cap1, redirwiden) the original's callee wrote into its incoming-argument slots (a pointer to a
                # dead parameter slot reused as a local); ours keeps a local of its own and the write is placed
                # behind it (_place_piece). As `widen` does for frame writes: the bytes of the word the delta
                # leaves alone get the game's, where the original's code never wrote them
                gat2 = lambda x: g[x - fbase] if 0 <= x - fbase < len(g) else None
                wd, wk, wa = bytearray(data), list(keep), a
                for lo, hi in ((a & ~3, a), (a + n, (a + n + 3) & ~3)):
                    if lo < hi and all(gat2(x) is not None and x not in self.func_stack_written for x in range(lo, hi)):
                        ext = bytearray(gat2(x) for x in range(lo, hi))
                        if lo < wa:
                            wd, wk, wa = ext + wd, [True] * (hi - lo) + wk, lo
                        else:
                            wd, wk = wd + ext, wk + [True] * (hi - lo)
                if len(wd) != len(data):
                    redirect = (wa - a, bytes(wd), wk, [False] * (a - wa) + list(unk) + [False] * (len(wd) - n - (a - wa)))
            if how is None:
                alt = None
                if key[0] == "reg":
                    # (a pointer the capture keyed by a register, `mov ecx, edi` left over, that the call also
                    # passes as a stack argument: ours may not have it in that register)
                    alt = next((("arg", j) for j, (v, _) in enumerate(c["args"]) if v == b), None)
                how = ("frame", alt)
            altkey = None
            if how is not None and key[0] == "reg" and "redirwiden" not in REPLAY_OFF:
                # (cap1) ours may not hold the pointer in that register (a callee `// equiv-conv` takes it in ecx, our
                # declaration passes it on the stack): the call's argument that has its value finds it
                altkey = next((("arg", j) for j, (v, _) in enumerate(c["args"]) if v == b), None)
            pieces = [dict(key=key, off=off, data=bytes(data), how=how, keep=keep, unk=unk, a=a, b=b, redirect=redirect,
                           altkey=altkey)]
            out.extend(pieces)
        return out

    def _place_piece(self, pc, k, pi):
        uc = self.uc
        entry = equiv.ENTRY_ESP
        key, off, data, how = pc["key"], pc["off"], bytearray(pc["data"]), pc["how"]
        n = len(data)
        keep = list(pc["keep"])
        if self.skip_unknown is not None:
            keep = [kp and (not u or (k, pi, i) in self.skip_unknown) for i, (kp, u) in enumerate(zip(keep, pc["unk"]))]
        if self.side == "orig":
            a = pc["a"]
        elif how[0] == "args":
            a = entry + how[1]
            b = self.base_value(key, k) if key[0] != "entry" else None
            if b is None and pc.get("altkey"):
                b = self.base_value(pc["altkey"], k)
            if b is not None and b != entry + how[2] and not (b + off < entry + 4 and b + off + n > entry):
                # the original passed a pointer into its incoming argument slots (a dead parameter
                # reused as a local) and ours a local of its own: the write goes behind ours
                a = b + off
                if pc.get("redirect") and not (self.skip_unknown is not None):
                    sh, data, keep, unk_ = pc["redirect"]
                    data, keep, a, n = bytearray(data), list(keep), a + sh, len(data)
                    pc = dict(pc, unk=unk_)
        else:
            if len(how) > 1 and how[1] is not None:
                key = how[1]
            b = self.base_value(key, k)
            a = None if b is None or key[0] == "entry" else b + off
            if a is not None:
                last = max((i for i in range(n) if keep[i]), default=-1) + 1
                room, what = self._frame_room(b)
                if 0 <= off < room < off + last:
                    # the game's callee wrote one run of bytes starting inside the object it was
                    # given and going past where ours has room (a smaller local; equiv.py's
                    # undersized-local check, with the real write)
                    self.calls[k].setdefault("overflow", []).append((key[1], off + last, room, what))
                    n = room - off
                    data, keep = data[:n], keep[:n]
                if a + n > entry:
                    # (round 12, deadarg) ours keeps the object in a dead parameter slot: the real callee writes
                    # there, as long as the write stays within our incoming arguments and the original's own
                    # slots there are dead after the call
                    orun = self.trace.get("_orun")
                    # (cap1, ownconv) when the function under test has its own `// equiv-conv`, the incoming-argument
                    # slots hold different words on the two sides (the original's register arguments are our stack
                    # words): the original's liveness there says nothing about ours
                    if "deadarg" in REPLAY_OFF or orun is None or a < entry + 4 or a + n > self.stack_top() or \
                            (not getattr(self, "own_conv", False) and not orun.arg_dead_after(k, a, a + n)):
                        a = None
        if a is None:
            self.base_misses += 1
            return
        i = 0
        while i < n:
            if not keep[i]:
                i += 1
                continue
            j = i
            while j < n and keep[j]:
                j += 1
            uc.mem_write(a + i, bytes(data[i:j]))
            self.stack_written.update(range(a + i, a + j))
            for x in range(i, j):
                if pc["unk"][x]:
                    self.unknown_placed += 1
                    if self.side == "orig":
                        self.unk_live[a + x] = (k, pi, x)
            i = j

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
                self.st0_used += 1
            elif TRAMP + 0xC00 <= eip < TRAMP + 0xC10 and "x87arg" not in REPLAY_OFF:
                # (round 12, x87arg) a callee with x87 register arguments (`fld x; call __CIasin`): the stub pops
                # them, then jumps through [FSLOT + 0x10] to the float-load trampoline: point that at the qword
                # variant with the real result too
                t = struct.unpack("<I", bytes(uc.mem_read(FSLOT + 0x10, 4)))[0]
                if TRAMP + 0x800 <= t < TRAMP + 0xC00:
                    uc.mem_write(FSLOT + 0x10, struct.pack("<I", t - 0x400))
                    uc.mem_write(FSLOT, struct.pack("<d", res["st0"]))
                    self.st0_used += 1


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
                 own_float=False, max_steps=2000000, skip_unknown=None):
    set_entry_esp(trace["entry"].get("esp_g"))
    trace.pop("_place", None)
    inp = make_input(trace["entry"])
    mach = TraceMemory(prog, trace["pages"], store)
    orun = TraceRun(prog, oview, mach, inp, ours_image=ours_image, sig=None, max_steps=max_steps,
                    own_float_ret=own_float, coverage=True, helpers=helpers, trace=trace, side="orig",
                    skip_unknown=skip_unknown)
    orun.pointee_sizes = psizes or {}
    orun.convs = convs or {}
    orun.slot_arity = {}
    orun.loop_limits = {}
    orun.varargs = set(varargs)
    trace["_orun"] = orun
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


def replay_level3(store, addr, max_calls=None, max_steps=2000000, time_budget=120, spread=False):
    """A level3_fn for equiv.verify: replay every recorded call of addr."""
    def fn(prog, oview, rview, ours, orefs, sig, ret_kind, psizes, convs, decls, void_eax, issues):
        res = {"captured": 0, "replayed": 0, "agreed": 0, "mismatched": 0, "incomplete": 0, "mismatches": [],
               "incomplete_reasons": [], "notes": [], "level2_ok": not issues}
        target_conv = (convs or {}).get(oview.entry)
        own_layout, esp_adjust = [], 0
        if target_conv:
            # (cap1, ownconv) the function under test has `// equiv-conv`: the recorded entry is the original's
            # layout; ours gets the same values where its declaration takes them (inverse of equiv._conv_input)
            own_layout = equiv.decl_layout(sig)[0] if "ownconv" not in REPLAY_OFF else None
            if not own_layout:
                res["unsupported"] = "the function itself has an equiv-conv annotation (register arguments)"
                res["status"] = "unsupported"
                return res
            esp_adjust = (equiv.decl_layout(sig)[1] or 0) - (prog.callee_pop(oview.entry) or 0)
        traces = store.calls_spread(addr, max_calls) if spread else store.calls(addr, only_ok=True, limit=max_calls)
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
        pre_fix = getattr(store, "pre_st0_fix", False) and "st0fix" not in REPLAY_OFF
        res["st0fix"] = True            # (round 12: results of this version drop pre-fix x87 results)
        if pre_fix:
            res["pre_st0_fix"] = 0

        def ours_input(inp):
            if not target_conv:
                return inp
            vals, si = [], 0
            for loc in target_conv:
                if loc == "stack":
                    vals.append(inp["stack"][si] if si < len(inp["stack"]) else 0)
                    si += 1
                else:
                    vals.append(inp["regs"][loc])
            regs = dict(inp["regs"])
            stack = []
            for li, loc in enumerate(own_layout):
                v = vals[li] if li < len(vals) else 0
                if loc == "stack":
                    stack.append(v)
                else:
                    regs[loc] = v
            return dict(inp, regs=regs, stack=stack + list(inp["stack"][si:]), own_args=list(stack), own_pop=None)

        def run_ours(tr, inp, skip_unknown, steps):
            inp = ours_input(inp)
            rmach = TraceMemory(prog, tr["pages"], store)
            rrun = TraceRun(prog, rview, rmach, inp, ours_image=(equiv.OURS, ours.image), sig=sig,
                            max_steps=steps * 2, own_float_ret=own_float, helpers=helpers, trace=tr, side="ours",
                            skip_unknown=skip_unknown)
            rrun.pointee_sizes = psizes or {}
            rrun.intrinsics = {a: n for a, n in ours.poison.items() if n in equiv.INTRINSIC_NAMES}
            rrun.local_code = (equiv.OURS, ours.end)
            rrun.self_alias = oview.entry
            rrun.own_conv = bool(target_conv)
            rrun.convs = convs or {}
            rrun.decls = decls or {}
            rrun.varargs = varargs
            rrun.caller_cleans = caller_cleans
            rrun.slot_arity = {}
            return rmach, rrun, rrun.run(rview.entry)

        for tr in traces:
            if time.process_time() - t0 > time_budget:
                res["time_budget_hit"] = True
                break
            steps = max_steps
            inp, mach, orun, o = run_original(prog, oview, tr, store, helpers, (equiv.OURS, ours.image), psizes,
                                              convs, varargs, own_float, steps)
            if o["status"] == "timeout" and tr["outcome"]["status"] == "ret" and "steps" not in REPLAY_OFF and \
                    steps < MAX_STEPS_REPLAY and time.process_time() - t0 < time_budget / 2:
                # (round 12, steps) the recording returned: give the original's replay a bigger budget
                steps = MAX_STEPS_REPLAY
                inp, mach, orun, o = run_original(prog, oview, tr, store, helpers, (equiv.OURS, ours.image), psizes,
                                                  convs, varargs, own_float, steps)
                res["long_steps"] = res.get("long_steps", 0) + 1
            why = selfcheck(o, orun, mach, tr)
            if not why and pre_fix and orun.st0_used:
                # (round 12, st0fix) captured before b566e0d3: the x87 results this call took are the physical
                # register, not ST(0) (s1's 0x00042680: cos(angle) recorded where the game returned the angle)
                why = "captured before the ST(0) fix (b566e0d3): %d x87 callee result(s) unreliable" % orun.st0_used
                res["pre_st0_fix"] += 1
            if why:
                res["incomplete"] += 1
                if len(res["incomplete_reasons"]) < 3:
                    res["incomplete_reasons"].append({"call": tr["n"], "why": why})
                tr.pop("_orun", None)
                continue
            if o["status"] == "ret":
                edges.update(orun.edges)
            rmach, rrun, r = run_ours(tr, inp, None, steps)
            # compare against the original's memory as recorded (both runs read the same pages)
            diffs = equiv.compare_runs(o, r, ret_kind, mach, TraceNamer(inp, sig, prog), prog, void_eax=void_eax,
                                       esp_adjust=esp_adjust, skip_saved=set(target_conv or ()))
            note = []
            if diffs and orun.unknown_placed > len(orun.unk_read) and "unknown" not in REPLAY_OFF:
                # (round 12, unknown) the difference may come from recorded bytes no callee wrote: they lay below
                # the stack pointer since the last call (an interrupt frame, the gate trampoline's words) and
                # the original's own code never read them. Both sides again without those: if the original still
                # reproduces the recording and ours then agrees, the call is inconclusive, not a mismatch
                keep_ = set(orun.unk_read)
                inp2, mach2, orun2, o2 = run_original(prog, oview, tr, store, helpers, (equiv.OURS, ours.image),
                                                      psizes, convs, varargs, own_float, steps, skip_unknown=keep_)
                if not selfcheck(o2, orun2, mach2, tr):
                    _, rrun2, r2 = run_ours(tr, inp2, keep_, steps)
                    if not equiv.compare_runs(o2, r2, ret_kind, mach2, TraceNamer(inp2, sig, prog), prog,
                                              void_eax=void_eax, esp_adjust=esp_adjust,
                                              skip_saved=set(target_conv or ())):
                        res["incomplete"] += 1
                        res["unknown_bytes"] = res.get("unknown_bytes", 0) + 1
                        if len(res["incomplete_reasons"]) < 3:
                            res["incomplete_reasons"].append({"call": tr["n"], "why": (
                                "differs only through recorded stack bytes that were below the stack pointer "
                                "since the last call and the original never read (%d; maybe not callee writes): %s" % (
                                    orun.unknown_placed - len(orun.unk_read), diffs[0]))})
                        tr.pop("_orun", None)
                        continue
            res["replayed"] += 1
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
            tr.pop("_orun", None)
        res["coverage"] = equiv.coverage_of(oview, edges)
        res["coverage"].pop("uncovered", None)
        if res["replayed"] == 0:
            res["status"] = "no_replay" if res["captured"] or res["incomplete"] else "not_reached"
        else:
            res["status"] = "mismatch" if res["mismatched"] else "agreed"
        return res
    return fn


def replay_level3_multi(stores, addr, max_calls=None, time_budget=120):
    """A level3_fn that replays addr over several sessions in one verify (ours is compiled once).
    stores: [(session name, TraceStore)]. Result = replay_level3's dict summed, plus res["per_session"]."""
    fns = [(n, replay_level3(st, addr, max_calls, time_budget=time_budget, spread=True)) for n, st in stores]

    def fn(**kw):
        t0 = time.time()
        tot = {"captured": 0, "replayed": 0, "agreed": 0, "mismatched": 0, "incomplete": 0, "mismatches": [],
               "incomplete_reasons": [], "notes": [], "per_session": {}, "level2_ok": not kw.get("issues")}
        for name, f in fns:
            r = f(**kw)
            if r.get("status") == "unsupported":
                r["per_session"] = {}
                return r
            for k in ("captured", "replayed", "agreed", "mismatched", "incomplete"):
                tot[k] += r[k]
            for m in r["mismatches"]:
                if len(tot["mismatches"]) < 5:
                    tot["mismatches"].append(dict(m, session=name))
            tot["incomplete_reasons"] += r["incomplete_reasons"][:1]
            tot["per_session"][name] = {k: r[k] for k in ("captured", "replayed", "agreed", "mismatched", "incomplete",
                                                          "status")}
            for k in ("st0fix", "pre_st0_fix", "unknown_bytes"):
                if k in r:
                    tot["per_session"][name][k] = r[k]
            tot["coverage"] = r.get("coverage")
        tot["t_replay"] = round(time.time() - t0, 2)
        tot["status"] = ("no_replay" if not tot["replayed"] else "mismatch" if tot["mismatched"] else "agreed") \
            if tot["captured"] or tot["incomplete"] else "not_reached"
        return tot
    return fn


def replay_multi(src, addr, stores, max_calls=None, time_budget=120):
    """Replay addr's recorded calls from every session in stores against SRC. Like replay()."""
    t0 = time.time()
    stores = [(n, st) for n, st in stores if st.db.execute("SELECT 1 FROM calls WHERE func = ? LIMIT 1", (addr,)).fetchone()]
    out = {"addr": "0x%08x" % addr, "src": src}
    if not stores:
        return dict(out, status="not_reached", per_session={})
    rep = equiv.verify(src, addr, max_level=3, level3_fn=replay_level3_multi(stores, addr, max_calls, time_budget))
    if "replay" not in rep:
        return dict(out, status=rep.get("status", "error"), error=rep.get("error"), per_session={})
    out.update(rep["replay"])
    out["time"] = round(time.time() - t0, 1)
    out["t_setup"] = round(out["time"] - out.get("t_replay", 0), 1)
    return out


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
        kind = "equivalent" if not a.only else "only"     # (only a full --equivalent run feeds equiv_confidence)
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
