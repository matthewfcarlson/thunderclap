#!/usr/bin/env python3
"""Calls whose declaration pops a different number of argument bytes than the original's callee (crash2, 2026-11-02).

A thiscall/stdcall callee pops its own stack arguments (`ret N`). When our source declares a virtual (or other) callee
with a different number of stack words than the real one, MSVC's byte match / equiv.py on the MSVC object can still
pass (the caller's pushes are the same bytes either way, or the harness follows our declaration), but the clang
Wine build's caller adjusts esp by what our declaration says (`call [eax+0x1c]; sub esp, 12`), so esp drifts and the
-O0 frame's esp-relative locals are read from the wrong slots. Found the hard way: 0x0013d7b0 declared
AnimationPhaseMatchedTrack::vfunc_7 (a plain `ret`) with three arguments; the three pushes before that call in the
original are the next call's; `part` was reloaded from a neighbouring slot and a driver entry was appended to the
hulk's params object, overwriting the CCharacterGolem after it (play3 frame 18530, docs/journal.md crash2).

What it compares, per function (build/tree/report.json checks with a symbol, defined in one clang object):
  ours      the clang object (the Wine build's objs/*.obj): every call and the `sub esp, N` clang emits right after it
            (N = the bytes our declaration says the callee pops; 0 for cdecl).
  original  the XBE: a stack-depth model of the function (push/pop, esp arithmetic, an ebp frame, calls). A direct
            callee pops what its `ret N` says; an indirect call's pop is a variable in 0..(words pushed in its
            straight-line block before it). The depth at every `ret` must be 0 and two paths into one block must agree;
            the assignments that satisfy all of that give each indirect call its feasible pops.
  indirect  calls through `[reg+disp]` are paired by displacement and order (only where both sides have the same
            number of calls with that displacement); a pair is reported when our pop is not one of the feasible ones.
  direct    calls to a bound symbol (the Wine build's bindings.json) whose clang `sub esp` differs from the bound
            address's `ret N` (equiv.py reports these as abi_mismatch; listed here for completeness).

  build/venv/bin/python tools/vcall_scan.py --objs DIR --rsp objects.rsp --report report.json --bindings bindings.json
      [--out OUT.tsv]   DIR, objects.rsp, report.json, bindings.json: a Wine build lineage's build/native/link/{objs,
      objects.rsp}, build/tree/report.json and build/native/bindings.json (rsync them from the host that built it). [--addr 0x... ...] limits the scan.
Output: one line per finding: kind, address, source, call index, displacement/target, our pop, the original's
feasible pops, and the function's name. `unresolved` counts functions whose original model had no consistent
assignment (an `and esp` frame, a switch, code the model doesn't follow); those are skipped, not reported.
"""
import argparse
import collections
import csv
import itertools
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import capstone  # noqa: E402
from capstone import x86  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LLVM = next((d for d in (os.path.join(os.environ.get("HULK_LLVM", ""), "bin"), "/opt/homebrew/opt/llvm/bin",
                         os.path.expanduser("~/llvm/bin")) if os.path.exists(os.path.join(d, "llvm-objdump"))), "")


def load_funcs():
    funcs = {}
    for r in csv.DictReader(open(os.path.join(ROOT, "build/functions.csv"))):
        funcs[int(r["address"], 16)] = (int(r["size"]), r["name"])
    return funcs


class Original:
    def __init__(self):
        self.xbe = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
        self.funcs = load_funcs()
        self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self.md.detail = True
        self._pop = {}

    def insns(self, va, size):
        o = self.xbe.offset(va)
        return list(self.md.disasm(self.xbe.data[o:o + size], va))

    def callee_pop(self, t, depth=0):
        """`ret N` of a function (None: unknown, several different N, or no ret)."""
        if t in self._pop:
            return self._pop[t]
        self._pop[t] = None
        res = None
        if t in self.funcs:
            ins = self.insns(t, self.funcs[t][0])
            rets = {(i.operands[0].imm if i.operands else 0) for i in ins if i.mnemonic == "ret"}
            if len(rets) == 1:
                res = rets.pop()
            elif not rets and ins and ins[0].mnemonic == "jmp" and ins[0].operands[0].type == x86.X86_OP_IMM \
                    and depth < 4:
                res = self.callee_pop(ins[0].operands[0].imm, depth + 1)
        self._pop[t] = res
        return res

    def model(self, va):
        """Indirect calls of the function at VA: [(addr, disp, feasible pops or None)], or None when unresolved."""
        size = self.funcs[va][0]
        ins = self.insns(va, size)
        if not ins:
            return None
        by = {i.address: k for k, i in enumerate(ins)}
        lo, hi = va, va + size
        vars_ = []                      # [(insn addr, domain)]
        var_at = {}

        def var_for(k):
            if ins[k].address in var_at:
                return var_at[ins[k].address]
            # words pushed in this straight line, earlier calls and cleanups included (their words may be this
            # call's: `push 0; call [rand]; push ecx; fstp [esp]; call [ebp+0x18]`; `push 1; call [v16]; push eax;
            # push edi; call f; add esp, 8; push eax; push x; call [v3]` with v3 taking the 1 too)
            n, j = 0, k - 1
            while j >= 0 and ins[j].mnemonic not in ("ret", "jmp") and not ins[j].mnemonic.startswith("j"):
                m = ins[j].mnemonic
                if m == "push":
                    n += 1
                j -= 1
            v = len(vars_)
            vars_.append((ins[k].address, list(range(0, 4 * n + 1, 4))))
            var_at[ins[k].address] = v
            return v

        def add(e, c=0, v=None, coef=1):
            const, terms = e
            terms = dict(terms)
            if v is not None:
                terms[v] = terms.get(v, 0) + coef
                if not terms[v]:
                    del terms[v]
            return (const + c, tuple(sorted(terms.items())))

        constraints = []                # expressions that must be 0
        seen = {}                       # insn index -> (depth expr, ebp expr) at block entry
        work = [(0, (0, ()), None)]
        steps = 0
        indirect = []
        while work:
            k, d, ebp = work.pop()
            while True:
                steps += 1
                if steps > 200000:
                    return None
                if k in seen:
                    if d is not None and seen[k][0] is not None and seen[k][0] != d:
                        constraints.append(_sub(d, seen[k][0]))
                    break
                seen[k] = (d, ebp)
                i = ins[k]
                m, ops = i.mnemonic, i.operands
                nxt = k + 1
                if m == "ret":
                    if d is not None:
                        constraints.append(d)
                    break
                if m == "int3" or m == "hlt":
                    break
                if m == "jmp":
                    if ops[0].type == x86.X86_OP_IMM and lo <= ops[0].imm < hi and ops[0].imm in by:
                        k = by[ops[0].imm]
                        continue
                    break                   # a tail call or a switch: no constraint
                if m.startswith("j") or m.startswith("loop"):
                    if ops[0].type == x86.X86_OP_IMM and ops[0].imm in by:
                        work.append((by[ops[0].imm], d, ebp))
                    k = nxt
                    if k >= len(ins):
                        break
                    continue
                if d is not None:
                    if m == "push":
                        d = add(d, 4)
                    elif m == "pop":
                        if ops[0].type == x86.X86_OP_REG and i.reg_name(ops[0].reg) == "ebp":
                            ebp = None
                        d = add(d, -4)
                    elif m == "pushal" or m == "pushad":
                        d = add(d, 32)
                    elif m == "popal" or m == "popad":
                        d = add(d, -32)
                    elif m == "pushfd" or m == "pushf":
                        d = add(d, 4)
                    elif m == "popfd" or m == "popf":
                        d = add(d, -4)
                    elif m in ("sub", "add") and ops[0].type == x86.X86_OP_REG and i.reg_name(ops[0].reg) == "esp":
                        if ops[1].type == x86.X86_OP_IMM:
                            d = add(d, ops[1].imm if m == "sub" else -ops[1].imm)
                        else:
                            d = None
                    elif m == "mov" and ops[0].type == x86.X86_OP_REG and i.reg_name(ops[0].reg) == "ebp" and \
                            ops[1].type == x86.X86_OP_REG and i.reg_name(ops[1].reg) == "esp":
                        ebp = d
                    elif m == "mov" and ops[0].type == x86.X86_OP_REG and i.reg_name(ops[0].reg) == "esp":
                        d = ebp if (ops[1].type == x86.X86_OP_REG and i.reg_name(ops[1].reg) == "ebp") else None
                    elif m == "leave":
                        d = add(ebp, -4) if ebp is not None else None
                        ebp = None
                    elif m == "lea" and ops[0].type == x86.X86_OP_REG and i.reg_name(ops[0].reg) == "esp":
                        mem = ops[1].mem
                        base = i.reg_name(mem.base) if mem.base else None
                        if base == "ebp" and ebp is not None and not mem.index:
                            d = add(ebp, -mem.disp)
                        elif base == "esp" and not mem.index:
                            d = add(d, -mem.disp)
                        else:
                            d = None
                    elif ops and ops[0].type == x86.X86_OP_REG and i.reg_name(ops[0].reg) == "esp" and \
                            m not in ("cmp", "test", "push"):
                        d = None            # and esp, -8 and the like: depth unknown until restored from ebp
                    elif ops and ops[0].type == x86.X86_OP_REG and i.reg_name(ops[0].reg) == "ebp" and \
                            m not in ("cmp", "test", "push"):
                        ebp = None
                    elif m == "call":
                        op = ops[0]
                        if op.type == x86.X86_OP_IMM:
                            p = self.callee_pop(op.imm)
                            if p is None:
                                d = add(d, 0, var_for(k), -1)
                            else:
                                d = add(d, -p)
                        else:
                            v = var_for(k)
                            d = add(d, 0, v, -1)
                            if op.type == x86.X86_OP_MEM and op.mem.base and not op.mem.index:
                                indirect.append((i.address, op.mem.disp, v))
                elif m == "mov" and ops and ops[0].type == x86.X86_OP_REG and i.reg_name(ops[0].reg) == "esp" and \
                        ops[1].type == x86.X86_OP_REG and i.reg_name(ops[1].reg) == "ebp":
                    d = ebp
                elif m == "lea" and ops and ops[0].type == x86.X86_OP_REG and i.reg_name(ops[0].reg) == "esp":
                    mem = ops[1].mem
                    if mem.base and i.reg_name(mem.base) == "ebp" and ebp is not None and not mem.index:
                        d = add(ebp, -mem.disp)
                elif m == "leave" and ebp is not None:
                    d = add(ebp, -4)
                    ebp = None
                elif m == "call" and ops[0].type == x86.X86_OP_MEM and ops[0].mem.base and not ops[0].mem.index:
                    indirect.append((i.address, ops[0].mem.disp, None))
                k = nxt
                if k >= len(ins):
                    break
        # solve: the variables that appear in constraints, by brute force over their domains
        used = sorted({v for c in constraints for v, _ in c[1]})
        doms = [vars_[v][1] for v in used]
        n = 1
        for dm in doms:
            n *= len(dm)
        if n > 50000:
            return None
        feas = {v: set() for v in used}
        ok_any = False
        cons = [c for c in constraints]
        for vals in itertools.product(*doms) if used else [()]:
            asg = dict(zip(used, vals))
            if all(c[0] + sum(coef * asg[v] for v, coef in c[1]) == 0 for c in cons):
                ok_any = True
                for v in used:
                    feas[v].add(asg[v])
        if not ok_any:
            return None
        out = []
        for a, disp, v in indirect:
            if v is None:
                out.append((a, disp, None))
            elif v in feas:
                out.append((a, disp, sorted(feas[v])))
            else:
                dm = vars_[v][1]
                out.append((a, disp, dm if len(dm) == 1 else None))     # unconstrained: unknown unless forced
        return out


def _sub(a, b):
    terms = dict(a[1])
    for v, c in b[1]:
        terms[v] = terms.get(v, 0) - c
    return (a[0] - b[0], tuple(sorted((v, c) for v, c in terms.items() if c)))


def _assignable(us, og):
    """A perfect matching of our calls (pops) onto the original's (feasible pop sets): augmenting paths."""
    match = {}

    def try_(i, seen):
        for j, (_, _, f) in enumerate(og):
            if us[i][2] in f and j not in seen:
                seen.add(j)
                if j not in match or try_(match[j], seen):
                    match[j] = i
                    return True
        return False
    return all(try_(i, set()) for i in range(len(us)))


CALL_RE = re.compile(r"^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2} )+\s*\t(\w+)\s*\t?(.*)$")


def ours_calls(obj, syms):
    """{symbol: [(kind, disp or target symbol, declared pop or None)]} from llvm-objdump of OBJ. clang -O0 stores the
    arguments into an outgoing area reserved in the prologue (`sub esp, F`); a callee that pops is followed by
    `sub esp, N` (re-reserving), or, in tail position, by `add esp, F - N` and the epilogue (as equiv.py's
    clang_pop_after reads it). Code that pushes (or `sub esp, N` right before the call) passes what it pushed since
    the previous call: the callee pops all of it unless an `add esp, X` releases some right after."""
    out = {}
    insn_re = re.compile(r"^\s*[0-9a-f]+:\s+(\w+)\s*(.*)$")

    def imm(ar):
        try:
            return int(ar.split(",")[1].strip(), 0)
        except (ValueError, IndexError):
            return None
    for k in range(0, len(syms), 40):
        chunk = syms[k:k + 40]
        p = subprocess.run([os.path.join(LLVM, "llvm-objdump"), "-d", "-r", "--no-show-raw-insn", "--x86-asm-syntax=intel",
                            "--disassemble-symbols=" + ",".join(chunk), obj], capture_output=True, text=True,
                           errors="replace")
        cur, frame, body, delta, dyn, skip = None, 0, False, 0, False, None
        lines = p.stdout.splitlines()
        for j, l in enumerate(lines):
            m = re.match(r"^[0-9a-f]+ <(.+)>:$", l)
            if m:
                cur, frame, body, delta, dyn = out.setdefault(m.group(1), []), 0, False, 0, False
                continue
            if cur is None:
                continue
            m = insn_re.match(l)
            if not m or m.group(1).startswith("IMAGE_REL"):
                continue
            mn, ar = m.group(1), m.group(2).strip()
            if j == skip:
                continue                    # the re-reserve right after a call: not words for the next call
            if not body:
                if mn == "push" and ar in ("ebp", "esi", "edi", "ebx"):
                    continue
                if mn == "push" and ar in ("eax", "ecx", "edx"):
                    frame += 4              # clang reserves 4 bytes with a scratch-register push
                    continue
                if (mn == "mov" and ar.replace(" ", "") == "ebp,esp") or (mn == "and" and ar.startswith("esp,")):
                    continue
                if mn == "sub" and ar.startswith("esp,") and imm(ar) is not None:
                    frame += imm(ar)
                    continue
                body = True
            if mn != "call":
                if mn == "push" or (mn == "sub" and ar.startswith("esp,")):
                    dyn = True
                if mn == "push":
                    delta += 4
                elif mn == "pop":
                    delta -= 4
                elif mn in ("sub", "add") and ar.startswith("esp,") and imm(ar) is not None:
                    delta += imm(ar) if mn == "sub" else -imm(ar)
                elif mn.startswith("j") or mn == "ret":
                    delta = 0
                continue
            rel, nxt, nxt_line = None, [], []
            for jj, l2 in enumerate(lines[j + 1:j + 16], j + 1):
                r = re.match(r"^\s*[0-9a-f]+:\s+IMAGE_REL_I386_\w+\s+(\S+)", l2)
                if r:
                    if rel is None and not nxt:
                        rel = r.group(1)     # the call's own relocation (the line right after it)
                    continue
                m2 = insn_re.match(l2)
                if m2:
                    nxt.append((m2.group(1), m2.group(2).strip()))
                    nxt_line.append(jj)
            pop, via_delta = 0, False
            # the first instruction after the call that touches esp or ends the straight line (clang stores a float
            # result or the returned value first: `call; fstp [esp+x]; add esp, X; pop esi; ret`)
            q = 0
            while q < len(nxt) and q < 10 and not (
                    nxt[q][0] in ("push", "pop", "ret", "leave", "call") or nxt[q][0].startswith("j")
                    or nxt[q][1].startswith("esp")):
                q += 1
            nxt = nxt[q:]
            n0, a0 = nxt[0] if nxt else ("", "")
            epi = len(nxt) > 1 and nxt[1][0] in ("pop", "ret", "leave")
            if n0 == "sub" and a0.startswith("esp,") and q:
                pop = None                  # a later call's reservation (`call f; mov ecx, eax; sub esp, 8`)
            elif n0 == "sub" and a0.startswith("esp,") and delta == 0:
                pop = imm(a0)
                skip = nxt_line[0]
            elif n0 == "add" and a0.startswith("esp,") and imm(a0) is not None:
                x = imm(a0)
                if epi:
                    pop = (frame - x if 0 < x < frame else 0) if delta == 0 else None
                else:
                    pop = delta - x if delta >= x else None
                    via_delta = True
            elif delta > 0:
                pop = delta
                via_delta = True
            elif delta < 0:
                pop = None
            elif n0 in ("pop", "ret") and frame:
                pop = frame
            elif (n0 in ("lea", "mov") and a0.startswith("esp")) or n0 == "leave":
                pop = None
            delta = 0
            mm = re.match(r"dword ptr \[(e\w\w)(?: ([+-]) (0x[0-9a-f]+|\d+))?\]$", ar)
            if mm:
                disp = int(mm.group(3), 0) * (-1 if mm.group(2) == "-" else 1) if mm.group(3) else 0
                cur.append(("indirect", disp, pop))
            elif rel:
                # a direct call's words counted from pushes/`sub esp` are unreliable (a by-value argument copied
                # into a reserved block by a constructor call first): only clang -O0's re-reserve/epilogue counts
                # (and a 0 from "nothing after the call" means nothing in code that passes words dynamically)
                cur.append(("direct", rel, None if via_delta or (dyn and not (q == 0 and n0 == "sub")) else pop))
    return out


def defined_text_symbols(obj):
    p = subprocess.run([os.path.join(LLVM, "llvm-nm"), "--defined-only", obj], capture_output=True, text=True,
                       errors="replace")
    return [l.split(" ", 2)[2] for l in p.stdout.splitlines() if re.match(r"^[0-9a-f]+ [tT] ", l)]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--objs", required=True)
    ap.add_argument("--report", required=True)
    ap.add_argument("--bindings")
    ap.add_argument("--out")
    ap.add_argument("--rsp", help="the link's objects.rsp: only the objects it lists (objs/ keeps older builds' objects)")
    ap.add_argument("--addr", nargs="*")
    a = ap.parse_args()
    checks = [c for c in json.load(open(a.report))["checks"] if c.get("symbol")]
    if a.addr:
        want = {int(x, 16) for x in a.addr}
        checks = [c for c in checks if int(c["addr"], 16) in want]
    where = collections.defaultdict(set)
    listed = None
    if a.rsp:
        listed = {os.path.basename(l.strip().strip('"')) for l in open(a.rsp) if l.strip()}
    for fn in sorted(os.listdir(a.objs)):
        if fn.endswith(".obj") and (listed is None or fn in listed):
            for s in defined_text_symbols(os.path.join(a.objs, fn)):
                where[s].add(os.path.join(a.objs, fn))
    by_obj = collections.defaultdict(list)
    for c in checks:
        objs = where.get(c["symbol"], set())
        if len(objs) == 1:
            by_obj[next(iter(objs))].append(c)
    bind = {}
    if a.bindings:
        for s, b in json.load(open(a.bindings))["bindings"].items():
            if b.get("addr"):
                bind[s] = int(b["addr"], 16)
    orig = Original()
    rows, stats = [], collections.Counter()
    for obj, cs in sorted(by_obj.items()):
        calls = ours_calls(obj, sorted({c["symbol"] for c in cs}))
        for c in cs:
            va = int(c["addr"], 16)
            ours = calls.get(c["symbol"])
            if ours is None or va not in orig.funcs:
                stats["no-code"] += 1
                continue
            stats["functions"] += 1
            # direct calls: our declaration vs the bound callee's ret N
            for k, (kind, t, pop) in enumerate(ours):
                if kind == "direct" and t in bind and pop is not None:
                    real = orig.callee_pop(bind[t])
                    if real is not None and real != pop and orig.xbe.offset(bind[t]) is not None:
                        rows.append(("direct", c["addr"], c["src"], k, "%s=0x%08x" % (t, bind[t]), pop, str(real),
                                     c.get("name", "")))
            ind_ours = [(k, t, pop) for k, (kind, t, pop) in enumerate(ours) if kind == "indirect"]
            if not ind_ours:
                continue
            try:
                mod = orig.model(va)
            except Exception:
                mod = None
            if mod is None:
                stats["unresolved"] += 1
                continue
            go, gu = collections.defaultdict(list), collections.defaultdict(list)
            for x in mod:
                go[x[1]].append(x)
            for x in ind_ours:
                gu[x[1]].append(x)
            for disp in gu:
                if len(go.get(disp, [])) != len(gu[disp]):
                    stats["unpaired"] += 1
                    continue
                us, og = gu[disp], go[disp]
                stats["pairs"] += len(us)
                if any(f is None for _, _, f in og) or any(p_ is None for _, _, p_ in us):
                    stats["pair-unknown"] += 1
                    continue
                # pair by order first; when that fails, any assignment of our calls to the original's calls with
                # the same displacement that fits every pop (MSVC and clang lay blocks out differently)
                if all(p_ in f for (_, _, p_), (_, _, f) in zip(us, og)) or _assignable(us, og):
                    continue
                for (k, _, pop), (oa, _, feas) in zip(us, og):
                    if pop not in feas:
                        rows.append(("indirect", c["addr"], c["src"], k, "[+0x%x] at 0x%08x" % (disp, oa), pop,
                                     "/".join(map(str, feas)), c.get("name", "")))
    out = open(a.out, "w") if a.out else sys.stdout
    for r in rows:
        out.write("\t".join(map(str, r)) + "\n")
    print(dict(stats), "findings", len(rows), file=sys.stderr)


if __name__ == "__main__":
    main()
