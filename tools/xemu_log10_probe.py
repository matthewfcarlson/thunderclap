#!/usr/bin/env python3
"""Probe what the original's log10 computes in xemu, input -> output (flt2; docs/native-float64.md "log10").

  # an xemu queue job (mac2 or studio), run from the host's ~/hulk-tr1, always -snapshot:
  build/venv/bin/python tools/xemu_log10_probe.py --args ARGS.txt --out OUT.jsonl

The game has no log10 function call: both sites inline MSVC's intrinsic, FUN_00258f90+0x388 (the 3D sound's dB
conversion: `fld dword; fldlg2; fxch st(1); fyl2x; fmul dword [0x3fef48]; fstp dword`) and FUN_0033b900 (`fldlg2;
fxch st(1); fyl2x; fstp dword`). So the black box is the emulated CPU's FLDLG2/FYL2X followed by the game's own fmul
and float store, and this probe runs exactly that sequence on chosen arguments; no library code is read or run.

Boots the hybrid image paused (-S, -snapshot, muted), runs to the first call of an early game function (as
tools/xemu_x87_probe.py does), then writes a loop under the stack: `cli; fninit; fldcw CW;` and per argument
`fld qword; fldlg2; fxch; fyl2x; fnstsw; fstp tbyte (a copy); fstp dword (a copy); fmul dword [0x3fef48]; fstp dword`,
continues to a breakpoint after it and reads the results back. Interrupts stay off while it runs, so nothing else
writes the area. Every chunk runs at control word 0x027f (the game's: 53-bit precision, nearest) and 0x037f (64-bit).

ARGS.txt: one double per line as 16 hex digits (the bit pattern); edge cases and random arguments are added
(--extra). OUT.jsonl: per argument and control word {"x": hex64, "cw": int, "e80": hex20 (sign/exponent then the
mantissa, big-endian), "f": hex32 (the result stored as a float), "db": hex32 (times the game's 20.0f, stored as a
float), "sw": int (status word after fyl2x)}. Nothing is written to the disc or the HDD.
"""
import argparse
import json
import os
import random
import struct
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.getcwd(), "tools"))
import hybrid_run  # noqa: E402
from xemu_gdb import Gdb  # noqa: E402

BREAK = 0x0008ee30          # the game's main (tools/wine_host.py MAIN_ADDR): the XBE is loaded and the CRT initialized
K20 = 0x003fef48            # the game's 20.0f, the operand of FUN_00258f90's fmul
CHUNK = 64
REC = 32


def extra_args(seed):
    """Edge cases and random arguments (doubles), as 64-bit patterns."""
    d = lambda v: struct.unpack("<Q", struct.pack("<d", v))[0]
    f = lambda b: d(struct.unpack("<f", struct.pack("<I", b))[0])
    out = [0, 1 << 63, 0x7FF0000000000000, 0xFFF0000000000000, 0x7FF8000000000000, d(-1.0), d(-0.5), 1, 0x000FFFFFFFFFFFFF,
           0x0010000000000000, d(1.0), d(2.0), d(10.0), d(100.0), d(0.1), d(0.01), d(1e-3), d(3.4028234663852886e38)]
    for k in range(-149, 128):
        out.append(d(2.0 ** k))
    for k in range(-45, 39):
        out.append(d(float("1e%d" % k)))
    one = 0x3F800000
    for k in range(1, 2049):                     # floats just below and above 1.0
        out += [f(one - k), f(one + k)]
    for k in range(1, 257):
        out += [d(1.0) - k, d(1.0) + k]          # doubles next to 1.0
    rng = random.Random(seed)
    for _ in range(40000):                       # random floats in (0, 1]: the dB conversion's domain
        out.append(f(rng.randint(1, one)))
    for _ in range(10000):                       # random positive floats anywhere
        out.append(f(rng.randint(1, 0x7F7FFFFF)))
    for _ in range(10000):                       # random doubles in [2^-30, 2^30]
        out.append((rng.randint(1023 - 30, 1023 + 29) << 52) | rng.getrandbits(52))
    for k in range(1, 4097):                     # small integers (FUN_0033b900's argument is a computed double)
        out.append(d(float(k)))
    return out


def code_at(base, n, cw_at, in_at, out_at):
    c = b"\xfa\xdb\xe3"                                          # cli; fninit
    c += b"\xd9\x2d" + struct.pack("<I", cw_at)                 # fldcw [cw]
    c += b"\xbe" + struct.pack("<I", in_at)                     # mov esi, in
    c += b"\xbf" + struct.pack("<I", out_at)                    # mov edi, out
    c += b"\xb9" + struct.pack("<I", n)                         # mov ecx, n
    loop = len(c)
    c += (b"\xdd\x06"              # fld qword [esi]
          b"\xd9\xec"              # fldlg2
          b"\xd9\xc9"              # fxch st(1)
          b"\xd9\xf1"              # fyl2x
          b"\xdf\xe0"              # fnstsw ax
          b"\x66\x89\x47\x12"      # mov [edi+18], ax
          b"\xd9\xc0"              # fld st(0)
          b"\xdb\x3f"              # fstp tbyte [edi]
          b"\xd9\xc0"              # fld st(0)
          b"\xd9\x5f\x0a"          # fstp dword [edi+10]
          b"\xd8\x0d" + struct.pack("<I", K20) +                # fmul dword [0x3fef48]
          b"\xd9\x5f\x0e"          # fstp dword [edi+14]
          b"\x83\xc6\x08"          # add esi, 8
          b"\x83\xc7\x20"          # add edi, 32
          b"\x49")                 # dec ecx
    c += b"\x75" + struct.pack("<b", loop - (len(c) + 2))       # jnz loop
    end = base + len(c)
    c += b"\xeb\xfe"                                            # jmp $ (the breakpoint)
    return c, end


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--args", help="one double per line, 16 hex digits")
    ap.add_argument("--out", required=True)
    ap.add_argument("--seed", type=int, default=1010)
    ap.add_argument("--no-extra", action="store_true")
    ap.add_argument("--timeout", type=int, default=900)
    a = ap.parse_args()
    xs = []
    if a.args:
        xs = [int(l.split()[0], 16) for l in open(a.args) if l.strip() and not l.startswith("#")]
    if not a.no_extra:
        xs += extra_args(a.seed)
    seen, uniq = set(), []
    for v in xs:
        if v not in seen:
            seen.add(v)
            uniq.append(v)
    xs = uniq
    print("arguments", len(xs), flush=True)
    x = hybrid_run.Xemu("l10probe", True, ["-S"], snapshot=True)       # always -snapshot; muted (dummy audio)
    t0 = time.time()
    try:
        g = Gdb(timeout=60)
        g.set_break(BREAK)
        g._send("c")
        g.s.settimeout(a.timeout)
        try:
            g._recv_packet()
        except OSError:
            g.interrupt()
            g.s.settimeout(30)
            print("no stop at %#x in %ds: interrupted at" % (BREAK, a.timeout), g._recv_packet(), g.regs(), flush=True)
            raise
        g.s.settimeout(None)
        g.clear_break(BREAK)
        r = g.regs()
        base = (r["esp"] - 0x2000) & ~0xFFF
        cw_at, in_at, out_at = base + 0x100, base + 0x200, base + 0x200 + 8 * CHUNK
        assert out_at + REC * CHUNK <= r["esp"] - 0x400, (hex(base), hex(r["esp"]))
        k20 = g.read(K20, 4)
        print("esp %#x base %#x; [0x3fef48] = %s (%r)" % (r["esp"], base, k20.hex(), struct.unpack("<f", k20)[0]),
              flush=True)
        code, end = code_at(base, CHUNK, cw_at, in_at, out_at)
        g.write(base, code)
        g.set_break(end)
        n_out = 0
        with open(a.out, "w") as fo:
            fo.write(json.dumps({"meta": {"k20": k20.hex(), "esp": r["esp"], "n": len(xs), "seed": a.seed}}) + "\n")
            for i in range(0, len(xs), CHUNK):
                part = xs[i:i + CHUNK]
                n = len(part)
                g.write(in_at, b"".join(struct.pack("<Q", v) for v in part))
                for cw in (0x027F, 0x037F):
                    g.write(cw_at, struct.pack("<H", cw))
                    code, _e = code_at(base, n, cw_at, in_at, out_at)
                    g.write(base, code)
                    assert g.cmd("P8=%s" % struct.pack("<I", base).hex()) == "OK"
                    g.cont()
                    eip = g.regs()["eip"]
                    assert eip == end, (hex(eip), hex(end))
                    raw = g.read(out_at, REC * n)
                    for j, v in enumerate(part):
                        rec = raw[REC * j:REC * (j + 1)]
                        m, se = struct.unpack_from("<QH", rec, 0)
                        fo.write(json.dumps({"x": "%016x" % v, "cw": cw, "e80": "%04x%016x" % (se, m),
                                             "f": rec[10:14][::-1].hex(), "db": rec[14:18][::-1].hex(),
                                             "sw": struct.unpack_from("<H", rec, 18)[0]}) + "\n")
                        n_out += 1
                if (i // CHUNK) % 100 == 0:
                    print("  %d/%d %.0fs" % (i + n, len(xs), time.time() - t0), flush=True)
        print("wrote", a.out, n_out, "records in %.0fs" % (time.time() - t0))
    finally:
        try:
            print("xemu log tail:", open(os.path.join(x.outdir, "xemu.log"), errors="replace").read()[-1500:])
        except OSError:
            pass
        try:
            x.p.terminate()
        except Exception:
            pass


if __name__ == "__main__":
    main()
