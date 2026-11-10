#!/usr/bin/env python3
"""The 64-bit builds' float IR pass (flt1, docs/native-float64.md): what the Wine build's SSE code computes, on
x86-64 and arm64.

  build/venv/bin/python tools/native_float.py IN.ll OUT.ll      # apply the pass to one IR file (tests)

The native compiles (tools/native_mac.py, native_elf.py) apply it in native_mac.retarget() by default (HULK_NATIVE_FPFIX=0
turns it off; the cache key carries it). Four rewrites of the front end's IR, all target-independent (tests:
tests/native_host/native_float_test.py):

1. castfix: `fpext (sitofp/uitofp i to float) to double` becomes a direct conversion to double, as the Wine build's
   sse_castfix_ir (tools/clang_probe.py) does: MSVC 7.1's x87 code and the Wine build never round `(float)i` inside an
   expression.
2. Float -> integer conversions with the Wine build's results for every input. The Wine build's SSE code converts with
   `cvttsd2si`/`cvttss2si` (0x80000000 for NaN and out-of-range values) and LLVM's i686 lowerings of the unsigned and 64-bit
   cases; x86-64 agrees for the signed and narrow ones but not for `unsigned` and `unsigned __int64` out of range, and
   arm64's `fcvtzs`/`fcvtzu` saturate and give 0 for NaN and for negative values to unsigned types (measured:
   build/flt1/fp/conv). Every `fptosi`/`fptoui` becomes a call of a small IR helper (linkonce_odr, one per module) that
   computes the i686 SSE result:
     cvtt32(x)  = -2^31-1 < x < 2^31 ? trunc(x) : INT32_MIN              (signed i32; i8/i16: low bits of cvtt32)
     cvtt64(x)  = -2^63 <= x < 2^63 ? trunc(x) : INT64_MIN               (signed i64; x87 fistp qword)
     u32(x)     = b | (cvtt32(x - 2^31) & (b >> 31)), b = cvtt32(x)      (LLVM's i686 SSE2 lowering of fptoui i32)
     u64(x)     = x < 2^63 ? cvtt64(x) : cvtt64(x - 2^63) ^ INT64_MIN    (its x87 lowering of fptoui i64; NaN: 0)
     u8/u16(x)  = low bits of cvtt32(x)
   `float` sources are widened first (exact).
3. x87ext (x87ext_ir): a math-shim result consumed by the next arithmetic, fptrunc or fcmp is used as the 80-bit value
   the Wine build's x87-keep code computes with (src/platform/sdl/host/x87ext_native.cpp).
4. retfix64 (retfix64_ir): float results travel as doubles between game functions, as st(0) does on i686 (the Wine
   build's sse_retfix_ir), so `float` declarations of `hulk_freg` functions and vftable slots agree on 64-bit.
"""
import re
import sys

_FPCVT = re.compile(r"^(\s*)(%[\w.]+) = (fptosi|fptoui) (float|double) ([^ ,]+) to (i8|i16|i32|i64)(.*)$")

HELPERS = {
    "cvtt32": """define linkonce_odr hidden i32 @hulk.fp.cvtt32(double %x) {
  %lo = fcmp ogt double %x, 0xC1E0000000200000
  %hi = fcmp olt double %x, 0x41E0000000000000
  %ok = and i1 %lo, %hi
  %c = select i1 %ok, double %x, double 0.0
  %t = fptosi double %c to i32
  %r = select i1 %ok, i32 %t, i32 -2147483648
  ret i32 %r
}""",
    "cvtt64": """define linkonce_odr hidden i64 @hulk.fp.cvtt64(double %x) {
  %lo = fcmp oge double %x, 0xC3E0000000000000
  %hi = fcmp olt double %x, 0x43E0000000000000
  %ok = and i1 %lo, %hi
  %c = select i1 %ok, double %x, double 0.0
  %t = fptosi double %c to i64
  %r = select i1 %ok, i64 %t, i64 -9223372036854775808
  ret i64 %r
}""",
    "u32": """define linkonce_odr hidden i32 @hulk.fp.u32(double %x) {
  %b = call i32 @hulk.fp.cvtt32(double %x)
  %y = fsub double %x, 0x41E0000000000000
  %a = call i32 @hulk.fp.cvtt32(double %y)
  %s = ashr i32 %b, 31
  %m = and i32 %a, %s
  %r = or i32 %b, %m
  ret i32 %r
}""",
    "u64": """define linkonce_odr hidden i64 @hulk.fp.u64(double %x) {
  %lt = fcmp olt double %x, 0x43E0000000000000
  %p = call i64 @hulk.fp.cvtt64(double %x)
  %y = fsub double %x, 0x43E0000000000000
  %q0 = call i64 @hulk.fp.cvtt64(double %y)
  %q = xor i64 %q0, -9223372036854775808
  %r = select i1 %lt, i64 %p, i64 %q
  ret i64 %r
}""",
}
NEEDS = {"u32": ("cvtt32",), "u64": ("cvtt64",)}


def castfix_ir(ll):
    import clang_probe as cp
    return cp.sse_castfix_ir(ll)


def fpcvt_ir(ll):
    """fptosi/fptoui -> the i686 SSE results (module docstring). Returns (text, sites)."""
    out, used, n, k = [], set(), 0, 0
    for line in ll.split("\n"):
        m = _FPCVT.match(line)
        if not m:
            out.append(line)
            continue
        ind, r, op, sty, v, ity, rest = m.groups()
        k += 1
        x = v
        if sty == "float":
            x = "%%hulk.fpx%d" % k
            out.append("%s%s = fpext float %s to double" % (ind, x, v))
        if op == "fptosi" or ity in ("i8", "i16"):
            h, wide = ("cvtt64", "i64") if ity == "i64" and op == "fptosi" else ("cvtt32", "i32")
        else:
            h, wide = ("u32", "i32") if ity == "i32" else ("u64", "i64")
        used.add(h)
        used.update(NEEDS.get(h, ()))
        if wide == ity:
            out.append("%s%s = call %s @hulk.fp.%s(double %s)%s" % (ind, r, ity, h, x, rest))
        else:
            t = "%%hulk.fpw%d" % k
            out.append("%s%s = call %s @hulk.fp.%s(double %s)" % (ind, t, wide, h, x))
            out.append("%s%s = trunc %s %s to %s%s" % (ind, r, wide, t, ity, rest))
        n += 1
    if used:
        out.append("")
        for h in ("cvtt32", "cvtt64", "u32", "u64"):
            if h in used and ("@hulk.fp.%s(" % h) not in "\n".join(l for l in out if l.startswith("define")):
                out.append(HELPERS[h])
    return "\n".join(out), n


# ---------------------------------------------------------------------------------------------- x87ext
_SHIMS = ("sin", "cos", "tan", "atan", "atan2", "exp", "asin", "acos", "log", "log10", "pow")
_SHIM_CALL = re.compile(r"^(\s*)(%[\w.]+) = (?:tail |notail )?call (?:[\w]+ )*double @(" + "|".join(_SHIMS)
                        + r")\(([^()]*)\)(.*)$")
_ARITH = re.compile(r"^(\s*)(%[\w.]+) = (fmul|fadd|fsub|fdiv) double ([^ ,]+), ([^ ,]+)(.*)$")
_TRUNC = re.compile(r"^(\s*)(%[\w.]+) = fptrunc double ([^ ,]+) to float(.*)$")
_FCMP = re.compile(r"^(\s*)(%[\w.]+) = fcmp (\w+) double ([^ ,]+), ([^ ,]+)(.*)$")
_PRED = {"false": 0, "oeq": 1, "ogt": 2, "oge": 3, "olt": 4, "ole": 5, "one": 6, "ord": 7, "uno": 8, "ueq": 9,
         "ugt": 10, "uge": 11, "ult": 12, "ule": 13, "une": 14, "true": 15}
_LABEL = re.compile(r"^[\w.$\"-]+:")
X87E_DECLS = """declare void @hulk_x87e_%s(%s, ptr)"""


def x87ext_ir(ll):
    """The x87-keep semantics on 64-bit (src/platform/sdl/host/x87ext_native.cpp): a math-shim call's result is the
    80-bit value in a slot (hulk_x87e_<fn>), and the arithmetic, fptrunc or fcmp that consumes it directly, before the
    next call or block boundary (where the x87 code at -O0 spills it as a double), computes from the 80-bit value at
    53 bits; every other use sees the double (fstp m64), as before. Returns (text, {"shim calls": n, "consumers": n})."""
    out, n_calls, n_uses, used = [], 0, 0, set()
    fn_start, k, ext = None, 0, {}
    for line in ll.split("\n"):
        if line.startswith("define "):
            fn_start, ext = len(out), {}
            out.append(line)
            continue
        if fn_start is None:
            out.append(line)
            continue
        if line == "}":
            fn_start, ext = None, {}
            out.append(line)
            continue
        if _LABEL.match(line):
            ext = {}
            out.append(line)
            continue
        m = _SHIM_CALL.match(line)
        if m:
            ind, r, fn, args, rest = m.groups()
            k += 1
            slot = "%%hulk.x87e%d" % k
            out.insert(fn_start + 1, "  %s = alloca [16 x i8], align 8" % slot)
            out.append("%scall void @hulk_x87e_%s(%s, ptr %s)" % (ind, fn, args, slot))
            out.append("%s%s = call double @hulk_x87e_to_double(ptr %s)" % (ind, r, slot))
            used.add(fn)
            ext = {r: slot}          # (the previous ones were spilled by this call)
            n_calls += 1
            continue
        if ext:
            m = _ARITH.match(line)
            if m and (m.group(4) in ext or m.group(5) in ext):
                ind, r, op, a, b, rest = m.groups()
                name = {"fmul": "mul", "fadd": "add", "fsub": "sub", "fdiv": "div"}[op]
                if a in ext:
                    line = "%s%s = call double @hulk_x87e_%s(ptr %s, double %s)%s" % (ind, r, name, ext[a], b, rest)
                elif op in ("fmul", "fadd"):
                    line = "%s%s = call double @hulk_x87e_%s(ptr %s, double %s)%s" % (ind, r, name, ext[b], a, rest)
                else:
                    line = "%s%s = call double @hulk_x87e_r%s(double %s, ptr %s)%s" % (ind, r, name, a, ext[b], rest)
                n_uses += 1
                out.append(line)
                continue
            m = _TRUNC.match(line)
            if m and m.group(3) in ext:
                ind, r, a, rest = m.groups()
                out.append("%s%s = call float @hulk_x87e_to_float(ptr %s)%s" % (ind, r, ext[a], rest))
                n_uses += 1
                continue
            m = _FCMP.match(line)
            if m and (m.group(4) in ext or m.group(5) in ext) and m.group(3) in _PRED:
                ind, r, pred, a, b, rest = m.groups()
                sw = a not in ext
                e_, o_ = (ext[b], a) if sw else (ext[a], b)
                t = "%%hulk.x87c%d" % n_uses
                out.append("%s%s = call i32 @hulk_x87e_fcmp(ptr %s, double %s, i32 %d, i32 %d)" % (
                    ind, t, e_, o_, _PRED[pred], 1 if sw else 0))
                out.append("%s%s = icmp ne i32 %s, 0%s" % (ind, r, t, rest))
                n_uses += 1
                continue
            if re.search(r"\b(call|invoke)\b", line):
                ext = {}
        out.append(line)
    if n_calls:
        out.append("")
        for fn in sorted(used):
            out.append(X87E_DECLS % (fn, "double, double" if fn in ("atan2", "pow") else "double"))
        out += ["declare double @hulk_x87e_to_double(ptr)", "declare float @hulk_x87e_to_float(ptr)",
                "declare double @hulk_x87e_mul(ptr, double)", "declare double @hulk_x87e_add(ptr, double)",
                "declare double @hulk_x87e_sub(ptr, double)", "declare double @hulk_x87e_div(ptr, double)",
                "declare double @hulk_x87e_rsub(double, ptr)", "declare double @hulk_x87e_rdiv(double, ptr)",
                "declare i32 @hulk_x87e_fcmp(ptr, double, i32, i32)"]
    return "\n".join(out), {"shim calls": n_calls, "consumers": n_uses}


# ---------------------------------------------------------------------------------------------- retfix64
_RET_DEF = re.compile(r'^((?:define|declare) [^@]*?)\bfloat (@(?:"[^"]+"|[\w.$?@-]+)\()')
_RET_CALL = re.compile(r'^(\s*)(%[\w.]+) = ((?:tail |notail |musttail )?(?:call|invoke)(?: (?!float )[^ (%@]+)*) float '
                       r'(@(?:"[^"]+"|[\w.$?@-]+)|%[\w.]+)(\(.*)$')
_RET = re.compile(r'^(\s*)ret float (.*)$')
_EXT = re.compile(r'^(\s*)(%[\w.]+) = fpext float (%[\w.]+) to double(.*)$')
_HOST_FLOAT = None


def host_float_names():
    """Names whose definition is host code (the native CRT table's tree names: sinf, sqrtf, ...): their float results
    stay float. Every other float-returning function is game code (or a stub returning 0)."""
    global _HOST_FLOAT
    if _HOST_FLOAT is None:
        import os
        # the same table native_mac / native_elf read: HULK_NATIVE_CRT_TABLE names another copy (a queue job's)
        path = os.environ.get("HULK_NATIVE_CRT_TABLE") or os.path.join(
            os.path.dirname(os.path.abspath(__file__)), "..", "src/platform/sdl/crt/native_crt_table.h")
        t = open(path, errors="replace").read()
        _HOST_FLOAT = set()
        for m in re.finditer(r'N\(\d+, \w+, \w+, "([^"]*)"\)', t):
            for n in m.group(1).split():
                _HOST_FLOAT |= {n, "_" + n}
    return _HOST_FLOAT


def _host(callee):
    c = callee[1:].strip('"')
    leaf = c[1:].split("@", 1)[0] if c.startswith("?") and "@@" in c and c.count("@") <= 4 else c
    return callee.startswith("@") and (c.startswith(("llvm.", "hulk_")) or c in host_float_names()
                                       or (leaf != c and c.endswith("@Z") and "@@Y" in c and leaf in host_float_names()))


def retfix64_ir(ll):
    """A float result travels as a double between game functions (the x87's st(0); the Wine build's sse_retfix_ir).
    On i686 a function declared `float` and one declared `hulk_freg` (double) both return in st(0), and the Wine build
    reads every float-declared call as the double in st(0); on x86-64 and arm64 a float and a double result are
    different bits of xmm0 / d0, so a caller that declares `float` for a `hulk_freg` definition (676 names, unb1), or
    calls through a vftable slot declared `float` that a `hulk_freg` override fills (570 of the 702 hulk_freg
    definitions are virtual), reads garbage. So in game code every float-returning function returns the double of
    its float (`fpext` before `ret`), and every call of one (direct, through a pointer, or invoke) is a double call,
    rounded where the caller wanted a float and used whole where it widened it, exactly as the Wine build does.
    Host functions (the CRT table's names, llvm intrinsics, hulk_*) keep their float results.
    Returns (text, {"float definitions": n, "float calls": n})."""
    out, calls, n_def, n_call, k = [], {}, 0, 0, 0
    pend = {}          # invoke's normal destination label -> [fptrunc lines]
    musttail = set()
    lines = ll.split("\n")
    in_float_def = False
    inv, fstart = {}, 0
    for i, line in enumerate(lines):
        if line == "}" and inv:
            for j in range(fstart, len(out)):
                l_ = out[j]
                for r_, rt_ in inv.items():
                    if r_ in l_ and not re.match(r"^\s*(%s = |%s = )" % (re.escape(r_), re.escape(rt_)), l_) \
                            and not re.search(r"= fptrunc double %s to float" % re.escape(r_), l_) \
                            and not re.search(r"select i1 true, double %s," % re.escape(r_), l_):
                        out[j] = re.sub(re.escape(r_) + r"(?![\w.])", rt_, l_)
            inv = {}
        m = _RET_DEF.match(line)
        if m and not _host(m.group(2)[:-1]):
            line = m.group(1) + "double " + line[m.end(1) + len("float "):]
            if line.startswith("define"):
                n_def += 1
                in_float_def = True
                calls, musttail, inv, fstart = {}, set(), {}, len(out) + 1
            out.append(line)
            continue
        if line.startswith("define "):
            in_float_def = False
            calls, musttail, inv, fstart = {}, set(), {}, len(out) + 1
        lab = re.match(r'^([\w.$"-]+):', line)
        if lab and lab.group(1) in pend:
            out.append(line)
            out.extend(pend.pop(lab.group(1)))
            continue
        m = _RET_CALL.match(line)
        if m and not _host(m.group(4)):
            ind, r, kw, callee, rest = m.groups()
            k += 1
            n_call += 1
            if "invoke" in kw.split():
                # the invoke keeps its (numbered) name, now a double; the float is made in the normal destination
                # and the function's other uses of the name are renamed to it at the end of the function
                rt = "%hulk.rt" + r[1:].replace(".", "_").replace('"', "")
                out.append("%s%s = %s double %s%s" % (ind, r, kw, callee, rest))
                nm = re.search(r"to label %([\w.$-]+)", lines[i] + (lines[i + 1] if i + 1 < len(lines) else ""))
                if nm:
                    pend.setdefault(nm.group(1), []).append("  %s = fptrunc double %s to float" % (rt, r))
                    calls[r] = r
                    inv[r] = rt
                continue
            rd = "%hulk.rd" + r[1:].replace(".", "_").replace('"', "")
            out.append("%s%s = %s double %s%s" % (ind, rd, kw, callee, rest))
            calls[r] = rd
            if "musttail" in kw:
                musttail.add(r)
            else:
                out.append("%s%s = fptrunc double %s to float" % (ind, r, rd))
            continue
        m = _EXT.match(line)
        if m and m.group(3) in calls:
            line = "%s%s = select i1 true, double %s, double %s%s" % (m.group(1), m.group(2), calls[m.group(3)],
                                                                        calls[m.group(3)], m.group(4))
        m = _RET.match(line)
        if m and in_float_def:
            v = m.group(2).strip()
            if v in musttail:
                line = "%sret double %s" % (m.group(1), calls[v])
            else:
                k += 1
                t = "%%hulk.rx%d" % k
                out.append("%s%s = fpext float %s to double" % (m.group(1), t, v))
                line = "%sret double %s" % (m.group(1), t)
        out.append(line)
    return "\n".join(out), {"float definitions": n_def, "float calls": n_call}


def fpfix_ir(ll):
    """All three rewrites. Returns (text, {"castfix": n, "fpcvt": n, "shim calls": n, "consumers": n})."""
    ll, a = castfix_ir(ll)
    ll, b = fpcvt_ir(ll)
    ll, c = x87ext_ir(ll)
    ll, d = retfix64_ir(ll)
    return ll, dict(dict({"castfix": a, "fpcvt": b}, **c), **d)


if __name__ == "__main__":
    sys.path.insert(0, __import__("os").path.dirname(__import__("os").path.abspath(__file__)))
    t, st = fpfix_ir(open(sys.argv[1]).read())
    open(sys.argv[2], "w").write(t)
    print(st, file=sys.stderr)
