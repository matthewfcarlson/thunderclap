#!/usr/bin/env python3
"""Probe xemu's x87 transcendentals (fsin, fcos, fptan, fpatan) over the GDB stub (cap1; docs/native-float.md).

  HULK_XEMU_INSTANCE=N tools/xemu_x87_probe.py --out build/cap1/x87-probe.json      # runs on mac2, one xemu, -snapshot

Boots the hybrid image paused (-S), runs to the first call of an early game function, then executes tiny code
written below the stack with the stub's single-step: `fninit; fld tbyte [a]; (fld tbyte [b]); OP`, and reads
ST(0) back as the full 80 bits. Inputs are exact 80-bit values (sign/exponent/64-bit mantissa), chosen by a
fixed seed, so tools/x87_ref.py (mpmath, laptop) can score the raw results against the correctly rounded
values. Control word 0x37f (64-bit precision, round to nearest). Nothing here is written to the disc or HDD.
"""
import argparse
import json
import os
import random
import struct
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hybrid_run  # noqa: E402
from xemu_gdb import Gdb  # noqa: E402

BREAK = 0x00011330          # an early, hot game function (the census sees it at poll ~509k in tr1; boot-time)
OPS = {"fsin": b"\xd9\xfe", "fcos": b"\xd9\xff", "fptan": b"\xd9\xf2", "fpatan": b"\xd9\xf3",
       "f2xm1": b"\xd9\xf0", "fyl2x": b"\xd9\xf1", "fsincos": b"\xd9\xfb"}


def ext(sign, e, m):
    return struct.pack("<QH", m, (sign << 15) | e)


def inputs(rng):
    """(op, [operands as 10 bytes]) cases."""
    xs = []
    for lo, hi in ((1e-6, 1e-3), (1e-3, 0.5), (0.5, 0.785), (0.785, 1.5707), (1.5707, 1.5709), (1.6, 3.2),
                   (3.2, 7.0), (7.0, 100.0), (100.0, 1e5), (1e5, 1e10)):
        for _ in range(4):
            v = rng.uniform(lo, hi)
            e = (struct.unpack("<Q", struct.pack("<d", v))[0] >> 52) - 1023 + 16383
            m = (1 << 63) | rng.getrandbits(63)         # a full 64-bit mantissa, not a double
            xs.append((rng.getrandbits(1) if lo > 1e-4 else 0, e, m))
    # a few exact large-argument cases
    xs.append((0, 16383 + 40, (1 << 63) | rng.getrandbits(63)))
    xs.append((0, 16383 + 62, (1 << 63) | rng.getrandbits(63)))
    out = []
    for op in ("fsin", "fcos", "fptan"):
        for s, e, m in xs:
            out.append((op, [ext(s, e, m)]))
    for _ in range(40):
        y = (rng.getrandbits(1), 16383 + rng.randint(-6, 4), (1 << 63) | rng.getrandbits(63))
        x = (rng.getrandbits(1), 16383 + rng.randint(-6, 4), (1 << 63) | rng.getrandbits(63))
        out.append(("fpatan", [ext(*y), ext(*x)]))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", required=True)
    ap.add_argument("--seed", type=int, default=87)
    ap.add_argument("--timeout", type=int, default=240)
    a = ap.parse_args()
    cases = inputs(random.Random(a.seed))
    x = hybrid_run.Xemu("x87probe", True, ["-S"], snapshot=True)       # always -snapshot; muted (dummy audio)
    res = []
    try:
        g = Gdb(timeout=60)
        g.set_break(BREAK)
        g._send("c")
        g.s.settimeout(a.timeout)
        g._recv_packet()
        g.s.settimeout(None)
        g.clear_break(BREAK)
        r = g.regs()
        base = (r["esp"] - 0x2000) & ~0xFFF
        code_at, data_at = base + 0x100, base + 0x400

        def setreg(n, v):
            assert g.cmd("P%x=%s" % (n, struct.pack("<I", v).hex())) == "OK"

        def st(i):
            # the 'g' packet: 8 gprs, eip, eflags, 6 segment registers, fs_base ... efer (9 x 4 bytes), then st0..st7 (10 bytes each,
            # ST(i) relative to the top of stack, as QEMU's stub sends them)
            raw = bytes.fromhex(g.cmd("g"))
            return raw[100 + 10 * i:110 + 10 * i]

        for op, vals in cases:
            code = b"\xdb\xe3"                                          # fninit
            code += b"\xb8" + struct.pack("<I", 0x37f) + b"\x50\xd9\x2c\x24\x58"   # push 0x37f; fldcw [esp]; pop eax
            for i, v in enumerate(vals):
                g.write(data_at + 16 * i, v + b"\0" * 6)
                code += b"\xdb\x2d" + struct.pack("<I", data_at + 16 * i)  # fld tbyte [addr]
            code += OPS[op] + b"\x90"
            g.write(code_at, code)
            setreg(8, code_at)
            n = 0
            # step until the op has executed (count its instructions: fninit, mov, push, fldcw, pop, flds, op)
            for _ in range(6 + len(vals) + 1):
                g.cmd("s")
                n += 1
            fctrl = struct.unpack_from("<I", bytes.fromhex(g.cmd("g")), 180)[0]
            assert fctrl == 0x37f, hex(fctrl)
            rec = {"op": op, "in": [v.hex() for v in vals], "st0": st(0).hex(), "st1": st(1).hex()}
            res.append(rec)
        json.dump({"cases": res, "seed": a.seed}, open(a.out, "w"), indent=0)
        print("wrote", a.out, len(res))
    finally:
        try:
            x.p.terminate()
        except Exception:
            pass


if __name__ == "__main__":
    main()
