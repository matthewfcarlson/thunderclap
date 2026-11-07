#!/usr/bin/env python3
"""native_float_test.py: tools/native_float.py's passes against the Wine build's float results (docs/native-float64.md).

arm64 macOS host (x86-64 cases run under Rosetta). Three checks:
  conv   float -> integer conversions (fpcvt): the i686 SSE object (the Wine build's code, run in Unicorn at control word
         0x027F) against x86-64 and arm64 objects of the same C, before and after the pass; edge values + random ones.
  ops    src/platform/sdl/host/x87ext_native.cpp's operations against the x87 (x86-64, long double, control word 0x027F).
  x87e   kernels through the x87ext pass: x86-64 against hand-written x87 references, and arm64 == x86-64.
Exit 0 when every check passes. Work files: build/native-float-test/.
"""
import math
import os
import random
import re
import struct
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "../.."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import clang_probe as cp  # noqa: E402
import native_float  # noqa: E402

T = os.path.join(ROOT, "tests/native_host/float")
W = os.path.join(ROOT, "build/native-float-test")
CC = os.path.join(cp.LLVM, "clang")
CXX = os.path.join(cp.LLVM, "clang++")
SDK = subprocess.run(["xcrun", "--show-sdk-path"], capture_output=True, text=True).stdout.strip()
SX = os.path.join(ROOT, "src/platform/sdl")
FP = ["-ffp-eval-method=double", "-ffp-contract=off"]


def run(cmd, **kw):
    r = subprocess.run(cmd, capture_output=True, text=True, **kw)
    if r.returncode:
        raise SystemExit("failed: %s\n%s" % (" ".join(cmd), r.stderr[-2000:]))
    return r.stdout


def mac(t):
    return ["-isysroot", SDK, "--target=%s-apple-macos13" % t]


def passed(ll_in, ll_out, fn):
    t, st = fn(open(ll_in).read())
    open(ll_out, "w").write(t)
    return st


def lld_link():
    for p in (os.path.join(cp.LLVM, "lld-link"), "/opt/homebrew/bin/lld-link", os.path.expanduser("~/llvm/bin/lld-link")):
        if os.path.exists(p):
            return p
    raise SystemExit("lld-link not found")


def i686_results(vals_h, n):
    """conv.c as the Wine build compiles it (i686, SSE2, -O0), run in Unicorn: the output lines of conv_main.c."""
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
    from unicorn.x86_const import UC_X86_REG_CR0, UC_X86_REG_CR4, UC_X86_REG_ESP
    obj, fu, exe = (os.path.join(W, x) for x in ("conv_i686.obj", "fltused.obj", "conv_i686.exe"))
    run([CC, "--target=i686-pc-windows-msvc", "-msse2", "-mfpmath=sse", "-O0", "-fno-stack-protector"] + FP
        + ["-c", os.path.join(T, "conv.c"), "-o", obj])
    open(os.path.join(W, "fltused.c"), "w").write("int _fltused = 0;\n")
    run([CC, "--target=i686-pc-windows-msvc", "-c", os.path.join(W, "fltused.c"), "-o", fu])
    run([lld_link(), "/entry:conv", "/subsystem:native", "/driver", "/nodefaultlib", "/base:0x400000", "/fixed",
         "/filealign:0x1000", "/align:0x1000", "/out:" + exe, obj, fu])
    img = open(exe, "rb").read()
    pe = struct.unpack_from("<I", img, 0x3c)[0]
    entry = 0x400000 + struct.unpack_from("<I", img, pe + 40)[0]
    vals = vals_h
    mu = Uc(UC_ARCH_X86, UC_MODE_32)
    mu.mem_map(0x400000, 0x100000)
    mu.mem_write(0x400000, img)
    mu.mem_map(0x100000, 0x300000)
    IN, OUT, STUB = 0x180000, 0x200000, 0x3F0000
    mu.mem_write(IN, b"".join(struct.pack("<d", v) for v in vals))
    code = (bytes([0xD9, 0x2D]) + struct.pack("<I", STUB + 0x40) + bytes([0x68]) + struct.pack("<I", n) + bytes([0x68])
            + struct.pack("<I", OUT) + bytes([0x68]) + struct.pack("<I", IN) + bytes([0xE8])
            + struct.pack("<i", entry - (STUB + 26)) + bytes([0xF4]))
    mu.mem_write(STUB, code)
    mu.mem_write(STUB + 0x40, struct.pack("<H", 0x027F))
    mu.reg_write(UC_X86_REG_CR0, (mu.reg_read(UC_X86_REG_CR0) & ~4) | 2)
    mu.reg_write(UC_X86_REG_CR4, mu.reg_read(UC_X86_REG_CR4) | 0x600)
    mu.reg_write(UC_X86_REG_ESP, 0x170000)
    mu.emu_start(STUB, STUB + len(code) - 1)
    fmt = "<iIhHbB2sqQiIiI"
    sz = struct.calcsize(fmt)
    out = []
    for k in range(n):
        i, u, s, us, c, uc, _, ll, ull, ill, ull32, fi, cmp = struct.unpack_from(fmt, mu.mem_read(OUT + k * sz, sz))
        out.append("i=%08x u=%08x s=%04x us=%04x c=%02x uc=%02x ll=%016x ull=%016x ill=%08x ull32=%08x fi=%08x cmp=%02x" % (
            i & 0xffffffff, u, s & 0xffff, us, c & 0xff, uc, ll & (2 ** 64 - 1), ull, ill & 0xffffffff, ull32,
            fi & 0xffffffff, cmp))
    return out


def native_results(t, fix, vals_name):
    ll = os.path.join(W, "conv_%s.ll" % t)
    run([CC] + mac(t) + ["-O0"] + FP + ["-S", "-emit-llvm", os.path.join(T, "conv.c"), "-o", ll])
    if fix:
        passed(ll, ll, native_float.fpfix_ir)
    o = ll[:-3] + ".o"
    run([CC] + mac(t) + ["-O0", "-c", "-Wno-override-module", ll, "-o", o])
    exe = os.path.join(W, "conv_%s_%d" % (t, fix))
    run([CC] + mac(t) + ['-DVALS="%s"' % vals_name, "-I" + W, "-I" + T, os.path.join(T, "conv_main.c"), o, "-o", exe])
    return [" ".join(l.split()[1:]) for l in run([exe]).splitlines()]


def check_conv():
    edge = open(os.path.join(T, "vals_edge.h")).read().split("{", 1)[1].split("}")[0]
    vals = []
    for t in edge.replace("\n", " ").split(","):
        t = t.strip()
        if t:
            vals.append(eval(t.replace("0.0/0.0", 'float("nan")').replace("1.0/0.0", 'float("inf")')) if "/" in t else float(t))
    rnd = random.Random(5)
    for _ in range(3000):
        x = rnd.uniform(1, 2) * rnd.choice([1, -1]) * 2.0 ** rnd.randint(-3, 70)
        if rnd.random() < 0.3:
            x = float(int(x)) + rnd.choice([0, 0.5, -0.5, 0.999999])
        vals.append(x)
    with open(os.path.join(W, "vals_all.h"), "w") as f:
        f.write("static const double V[] = {%s};\n" % ",".join(
            "0.0/0.0" if v != v else ("1.0/0.0" if v == float("inf") else ("-1.0/0.0" if v == -float("inf") else repr(v)))
            for v in vals))
    ref = i686_results(vals, len(vals))
    ok = True
    for t in ("x86_64", "arm64"):
        for fix in (0, 1):
            got = native_results(t, fix, "vals_all.h")
            bad = sum(1 for a, b in zip(ref, got) if a != b)
            print("conv %-6s %-8s %4d of %d values differ from the i686 SSE object" % (t, "fpfix" if fix else "plain", bad, len(ref)))
            if fix and bad:
                ok = False
    return ok


def check_ops():
    exe = os.path.join(W, "x87e_ops")
    run([CXX] + mac("x86_64") + ["-O1", "-std=c++14", "-I" + os.path.join(SX, "crt"), "-I" + SX,
                                 os.path.join(T, "x87e_ops.cpp"), os.path.join(SX, "host/x87ext_native.cpp"),
                                 os.path.join(SX, "crt/softx87.cpp"), "-o", exe])
    out = run([exe, "300000"]).strip()
    print("ops  " + out)
    return all(int(x) == 0 for x in re.findall(r"(?:mul|add|sub|rsub|div|rdiv|to_float|fcmp) (\d+)", out))


def check_x87e():
    hashes, ok = {}, True
    for t in ("x86_64", "arm64"):
        ll = os.path.join(W, "kern_%s.ll" % t)
        run([CC] + mac(t) + ["-O0", "-fno-builtin"] + FP + ["-S", "-emit-llvm", os.path.join(T, "x87e_kern.c"), "-o", ll])
        st = passed(ll, ll, native_float.x87ext_ir)
        o = ll[:-3] + ".o"
        run([CC] + mac(t) + ["-O0", "-c", "-Wno-override-module", ll, "-o", o])
        exe = os.path.join(W, "kern_%s" % t)
        run([CXX] + mac(t) + ["-O1", "-std=c++14", "-ffp-contract=off", "-I" + os.path.join(SX, "crt"), "-I" + SX,
                              os.path.join(T, "x87e_drv.cpp"), o, os.path.join(SX, "host/x87ext_native.cpp"),
                              os.path.join(SX, "crt/softx87.cpp"), "-o", exe])
        out = run([exe])
        hashes[t] = re.search(r"hash (\w+)", out).group(1)
        m = re.search(r"mismatches of \d+: (.*)$", out, re.M)
        if m:
            print("x87e %s %s; %s" % (t, st, m.group(1)))
            ok &= all(int(x) == 0 for x in re.findall(r"k\d (\d+)", m.group(1)))
    print("x87e hash x86_64 %s arm64 %s" % (hashes["x86_64"], hashes["arm64"]))
    return ok and hashes["x86_64"] == hashes["arm64"]


LG2_M = 0x9A209A84FBCFF799          # FLDLG2: log10(2) = LG2_M * 2^-65 (round to nearest)


def _e80_round(sign, num, den_log2):
    """num / 2^den_log2 (num > 0 an integer) rounded to 64 bits, nearest even, as the 80-bit hex"""
    top = num.bit_length() - 1
    sh = top - 63
    if sh > 0:
        q, r = num >> sh, num & ((1 << sh) - 1)
        half = 1 << (sh - 1)
        if r > half or (r == half and q & 1):
            q += 1
        if q >> 64:
            q >>= 1
            top += 1
    else:
        q = num << -sh
    return "%04x%016x" % ((sign << 15) | (16383 + top - den_log2), q)


def log10_expect(b):
    """softx87's documented log10 (docs/native-float64.md "log10"): FLDLG2 * log2(x) rounded once at 64 bits; the x87's
    special cases. Exact for powers of two (integers), decimal arithmetic at 120 digits otherwise."""
    from decimal import Decimal, getcontext
    getcontext().prec = 120
    x = struct.unpack("<d", struct.pack("<Q", b))[0]
    if x != x:
        return "7fffc000000000000000" if not b >> 63 else "ffffc000000000000000"
    if x == 0:
        return "ffff8000000000000000"
    if x < 0:
        return "ffffc000000000000000"
    if x == float("inf"):
        return "7fff8000000000000000"
    if x == 1.0:
        return "00000000000000000000"
    m, e = math.frexp(x)
    if m == 0.5:                                         # 2^(e-1): (e-1) * LG2_M * 2^-65 exactly
        k = e - 1
        return _e80_round(1 if k < 0 else 0, abs(k) * LG2_M, 65)
    v = Decimal(LG2_M) / Decimal(2) ** 65 * Decimal(x).ln() / Decimal(2).ln()
    sign = 1 if v < 0 else 0
    a = abs(v)
    top = math.floor(math.log2(float(a)))
    while Decimal(2) ** top > a:
        top -= 1
    while Decimal(2) ** (top + 1) <= a:
        top += 1
    q = a * Decimal(2) ** (63 - top)
    n = int(q)
    fr = q - n
    if fr > Decimal("0.5") or (fr == Decimal("0.5") and n & 1):
        n += 1
    if n >> 64:
        n >>= 1
        top += 1
    return "%04x%016x" % ((sign << 15) | (16383 + top), n)


def check_log10():
    """softx87's log10 (the original's inlined fldlg2/fyl2x): its documented rounding on powers of two, random and special
    arguments, the same bits on x86-64 and arm64, and, when the local probe data is there (HULK_LOG10_PROBE: the jsonl
    files of tools/xemu_log10_probe.py, default build/flt2/probe/), the game-visible floats against xemu's."""
    rnd = random.Random(1010)
    xs = [0, 1 << 63, 0x7FF0000000000000, 0xFFF0000000000000, 0x7FF8000000000000, 0xBFF0000000000000, 0x3FF0000000000000, 1,
          0x000FFFFFFFFFFFFF]
    xs += [struct.unpack("<Q", struct.pack("<d", math.ldexp(1.0, k)))[0] for k in range(-1074, 1024)]
    xs += [struct.unpack("<Q", struct.pack("<d", struct.unpack("<f", struct.pack("<I", rnd.randint(1, 0x3F800000)))[0]))[0]
           for _ in range(3000)]
    xs += [(rnd.randint(1, 2046) << 52) | rnd.getrandbits(52) for _ in range(1500)]
    xs += [0x3FF0000000000000 + k for k in range(-64, 65) if k]
    probe = {}
    pdir = os.environ.get("HULK_LOG10_PROBE") or os.path.join(ROOT, "build/flt2/probe")
    if os.path.isdir(pdir):
        import glob
        import json
        for fn in sorted(glob.glob(os.path.join(pdir, "*.jsonl"))):
            for line in open(fn):
                r = json.loads(line)
                if r.get("cw") == 0x27F:
                    probe[int(r["x"], 16)] = (r["e80"], r["f"], r["db"])
    allx = xs + [x for x in probe if x not in set(xs)]
    inp = "".join("%016x\n" % x for x in allx)
    outs = {}
    for t in ("x86_64", "arm64"):
        exe = os.path.join(W, "log10_%s" % t)
        run([CXX] + mac(t) + ["-O1", "-std=c++14", "-I" + os.path.join(SX, "crt"), os.path.join(T, "log10_drv.cpp"),
                              os.path.join(SX, "crt/softx87.cpp"), "-o", exe])
        outs[t] = run([exe], input=inp)
    ok = outs["x86_64"] == outs["arm64"]
    got = {int(l.split()[0], 16): l.split()[1:] for l in outs["arm64"].splitlines()}
    bad = [x for x in xs if got[x][0] != log10_expect(x)]
    print("log10 %d arguments: %d differ from the documented rounding; x86_64 %s arm64" % (
        len(xs), len(bad), "==" if ok else "!="))
    for x in bad[:5]:
        print("   %016x got %s want %s" % (x, got[x][0], log10_expect(x)))
    ok &= not bad
    if probe:
        e80 = sum(1 for x, p in probe.items() if got[x][0] == p[0])
        vis = sum(1 for x, p in probe.items() if got[x][1:] == [p[1], p[2]])
        print("log10 xemu probe (%s): game-visible floats %d of %d identical, 80-bit results %d of %d" % (
            pdir, vis, len(probe), e80, len(probe)))
        ok &= vis == len(probe)
    else:
        print("log10 xemu probe: no local data (%s), skipped" % pdir)
    return ok


def main():
    os.makedirs(W, exist_ok=True)
    res = {"conv": check_conv(), "ops": check_ops(), "x87e": check_x87e(), "log10": check_log10()}
    print("native_float_test: " + ", ".join("%s %s" % (k, "ok" if v else "FAIL") for k, v in res.items()))
    sys.exit(0 if all(res.values()) else 1)


if __name__ == "__main__":
    main()
