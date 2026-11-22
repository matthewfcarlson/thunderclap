"""eaxscan.py [--out TSV]: callers in the XBE that read eax/ax/al after calling a function whose tree block returns void
(its // sym: has a void result), i.e. sources that drop a result the original leaves in eax (HULK_PORT_ABI class).

direct   call rel32 to a void block, then a read of eax before any write of it in the straight-line code after the call
         (a `ret` right after the call counts when the caller's own block is non-void: it passes eax on).
virtual  call [reg+disp]: reported with the void blocks that sit at slot disp/4 of any vftable (config/data.json)
         and the non-void ones, so a slot whose implementations are all void is the strong case.
"""
import collections, csv, glob, json, os, re, struct, sys
import capstone
from capstone import x86
R = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(R, "tools"))
from xbe import Xbe
import wasm_port

def ret_code(sym):
    if "@@" not in sym or sym.startswith("??"):
        return None
    t = sym[sym.index("@@") + 2:]
    if not t:
        return None
    if t[0] in "YSKC":
        i = 2
    elif t[0] in "AEIMQUBFJNRV":
        i = 3 if t[1] != "E" else 4
    else:
        return None
    return t[i:i + 1] or None

def is_void(sym):
    if "@@" not in sym or sym.startswith("??"):
        return False
    t = sym[sym.index("@@") + 2:]
    if not t:
        return False
    if t[0] in "YSKC":
        i = 2
    elif t[0] in "AEIMQUBFJNRV":
        i = 3 if t[1] != "E" else 4
    else:
        return False
    return len(t) > i and t[i] == "X"

def blocks():
    out = {}
    hdr = re.compile(r"^// (0x[0-9a-f]{8}) (\S+) \(\d+ B\): (\w+)")
    for p in glob.glob(os.path.join(R, "src/**/*.cpp"), recursive=True):
        lines = open(p, errors="replace").read().split("\n")
        for i, l in enumerate(lines):
            m = hdr.match(l)
            if not m:
                continue
            for j in range(i + 1, min(i + 4, len(lines))):
                if lines[j].startswith("// sym: "):
                    sym = lines[j].split()[2]
                    out[int(m.group(1), 16)] = (sym, os.path.relpath(p, R), m.group(2))
                    break
    return out

EAX = {x86.X86_REG_EAX, x86.X86_REG_AX, x86.X86_REG_AL, x86.X86_REG_AH}

def reads_after(md, code, va):
    """'read' / 'ret' / None for the straight-line code at va (code: bytes from va)."""
    for ins in md.disasm(code, va):
        m = ins.mnemonic
        if m in ("xor", "sub") and len(ins.operands) == 2 and ins.operands[0].type == x86.X86_OP_REG \
                and ins.operands[1].type == x86.X86_OP_REG and ins.operands[0].reg == ins.operands[1].reg:
            if ins.operands[0].reg in EAX:
                return None
            continue
        rd, wr = ins.regs_access()
        if m.startswith("ret"):
            return "ret"
        if set(rd) & EAX:
            return "read:" + m + " " + ins.op_str
        if m == "call" or m.startswith("j"):
            return None
        if set(wr) & {x86.X86_REG_EAX}:
            return None
        if set(wr) & {x86.X86_REG_AL, x86.X86_REG_AX}:
            return None
    return None

def main():
    out = sys.argv[sys.argv.index("--out") + 1] if "--out" in sys.argv else None
    B = blocks()
    void = {a for a, (s, _, _) in B.items() if is_void(s)}
    xbe = Xbe(os.path.join(R, "isos/extracted/default.xbe"))
    funcs = {}
    for r in csv.DictReader(open(os.path.join(R, "build/functions.csv"))):
        funcs[int(r["address"], 16)] = int(r["size"])
    slots = collections.defaultdict(set)
    d = json.load(open(os.path.join(R, "config/data.json")))
    items = d["items"] if isinstance(d["items"], list) else list(d["items"].values())
    for it in items:
        if it.get("kind") != "vtable":
            continue
        a = int(it["addr"], 16)
        o = xbe.offset(a)
        for k in range(it.get("slots", 0)):
            slots[k].add(struct.unpack_from("<I", xbe.data, o + 4 * k)[0])
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    rows = []
    for fa, size in sorted(funcs.items()):
        o = xbe.offset(fa)
        code = xbe.data[o:o + size]
        caller_void = fa in void
        for ins in md.disasm(code, fa):
            if ins.mnemonic != "call":
                continue
            op = ins.operands[0]
            nxt = ins.address + ins.size
            tail = xbe.data[xbe.offset(nxt):xbe.offset(nxt) + 64]
            r = reads_after(md, tail, nxt)
            if r is None or "or eax, 0xffffffff" in r or (r == "ret" and (caller_void or fa not in B or ret_code(B[fa][0]) in (None, "X", "M", "N", "O"))):
                continue
            if op.type == x86.X86_OP_IMM:
                t = op.imm
                if t in void:
                    rows.append(("direct", hex(t), B[t][2], B[t][1], hex(ins.address), hex(fa), r, ""))
            elif op.type == x86.X86_OP_MEM and op.mem.base != 0 and op.mem.index == 0 and op.mem.disp % 4 == 0 \
                    and op.mem.base != x86.X86_REG_ESP:
                k = op.mem.disp // 4
                impl = slots.get(k, set())
                v = sorted(x for x in impl if x in void)
                nv = [x for x in impl if x in B and x not in void]
                if v:
                    rows.append(("virtual", "slot%d" % k, "%d void/%d nonvoid" % (len(v), len(nv)),
                                 " ".join(hex(x) for x in v), hex(ins.address), hex(fa), r, ""))
    w = open(out, "w") if out else sys.stdout
    for r in rows:
        w.write("\t".join(r) + "\n")
    c = collections.Counter(r[0] for r in rows)
    print("void blocks %d; findings %s; direct callees %d" % (len(void), dict(c),
          len({r[1] for r in rows if r[0] == "direct"})), file=sys.stderr)

if __name__ == "__main__":
    main()

def leaves_eax(md, xbe, fa, size, B, void):
    """Why a void block's original leaves a meaningful eax at a ret: 'set:<insn>' (eax written by the last
    eax-writing instruction before the ret, not a call) or 'pass:<callee>' (a call to a non-void block), else None."""
    o = xbe.offset(fa)
    ins = list(md.disasm(xbe.data[o:o + size], fa))
    why = set()
    for i, x in enumerate(ins):
        if not x.mnemonic.startswith("ret"):
            continue
        for y in reversed(ins[max(0, i - 30):i]):
            if y.mnemonic in ("jmp",) or y.mnemonic.startswith("ret"):
                break
            if y.mnemonic == "call":
                op = y.operands[0]
                if op.type == x86.X86_OP_IMM and op.imm in B and op.imm not in void:
                    why.add("pass:" + hex(op.imm))
                break
            rd, wr = y.regs_access()
            if set(wr) & EAX:
                if y.mnemonic not in ("pop",):
                    why.add("set:" + y.mnemonic + " " + y.op_str)
                break
    return sorted(why)

def cands():
    B = blocks()
    void = {a for a, (s, _, _) in B.items() if is_void(s)}
    xbe = Xbe(os.path.join(R, "isos/extracted/default.xbe"))
    funcs = {int(r["address"], 16): int(r["size"]) for r in csv.DictReader(open(os.path.join(R, "build/functions.csv")))}
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    out = {}
    for a in sorted(void):
        if a in funcs:
            w = leaves_eax(md, xbe, a, funcs[a], B, void)
            if w:
                out[a] = w
    return out, B
