// The 64-bit builds' stand-in for x87 code that computes on with an 80-bit math result (flt1, docs/native-float64.md).
//
// The Wine build's sin, cos, tan, atan, atan2, exp, asin, acos, log, log10 and pow leave the 80-bit x87 result in st(0),
// as the original's inlined fsin/fpatan/... do, and the functions that call them stay x87 code (the x87-keep list,
// docs/wine-float.md section 13): the first arithmetic instruction that consumes the result rounds once, at the game's
// 53-bit precision control. SSE/NEON code would round the result to a double first and then again after the operation
// (one double ULP apart in about a quarter of the products and quotients: build/flt1/fp/ext_consume.cpp).
// tools/native_float.py's x87ext pass (HULK_NATIVE_FPFIX=1) rewrites such a call into hulk_x87e_<fn> (the 80-bit result
// into a slot) and each consumer in the same expression into the operations below, which compute what the x87 does:
// softx87's fmul/fadd/fsub at PC 53 and a division done here, all integer-only, so x86-64 and arm64 give the same bits.
#include "crt/softx87.h"

#include <string.h>

typedef hulk_x87_ext Ext;
typedef unsigned long long u64;

extern "C" {

#define X1(fn) void hulk_x87e_##fn(double x, Ext* out) { *out = hulk_x87_##fn##_ext(x); }
#define X2(fn) void hulk_x87e_##fn(double a, double b, Ext* out) { *out = hulk_x87_##fn##_ext(a, b); }
X1(sin) X1(cos) X1(tan) X1(atan) X1(exp) X1(asin) X1(acos) X1(log) X1(log10)
X2(atan2) X2(pow)
#undef X1
#undef X2

double hulk_x87e_to_double(const Ext* e) { return hulk_x87_to_double(*e); }
float hulk_x87e_to_float(const Ext* e) { return hulk_x87_to_float(*e); }

static int is_finite_nonzero(Ext e) { return (e.se & 0x7fff) != 0x7fff && e.m != 0; }
static int dfinite_nonzero(double b) { return b == b && b != 0 && b - b == 0; }

double hulk_x87e_mul(const Ext* e, double b) { return hulk_x87_to_double(hulk_x87_fmul(*e, hulk_x87_from_double(b), 53)); }
double hulk_x87e_add(const Ext* e, double b) { return hulk_x87_to_double(hulk_x87_fadd(*e, hulk_x87_from_double(b), 53)); }
double hulk_x87e_sub(const Ext* e, double b) { return hulk_x87_to_double(hulk_x87_fsub(*e, hulk_x87_from_double(b), 53)); }
double hulk_x87e_rsub(double a, const Ext* e) { return hulk_x87_to_double(hulk_x87_fsub(hulk_x87_from_double(a), *e, 53)); }

// a / b at 53 bits, round to nearest even, then stored to a double (fdiv at PC 53; fstp m64). Zeros, infinities and NaNs
// on either side are exact doubles in an Ext, so the double division gives the x87's result for them.
static double div53(Ext a, Ext b) {
    if (!is_finite_nonzero(a) || !is_finite_nonzero(b))
        return hulk_x87_to_double(a) / hulk_x87_to_double(b);
    int ea = (a.se & 0x7fff) - 16383, eb = (b.se & 0x7fff) - 16383;
    u64 ma = a.m, mb = b.m;
    if (!(ma >> 63) || !(mb >> 63)) {   // unnormal or denormal extended operands: not produced from doubles/softx87
        return hulk_x87_to_double(a) / hulk_x87_to_double(b);
    }
    unsigned __int128 n = (unsigned __int128)ma << 64;
    unsigned __int128 q = n / mb;           // in (2^63, 2^65)
    int sticky = (n % mb) != 0;
    int e = ea - eb;                         // value = q * 2^(e - 64)
    // normalise q to 64 significant bits with sticky: q has 64 or 65 bits
    if (q >> 64) {
        sticky |= (int)(q & 1);
        q >>= 1;
        e += 1;
    }
    u64 m = (u64)q;                          // bit 63 set; value = m * 2^(e - 64) = 1.f * 2^(e - 1)
    // round to 53 bits (drop 11), nearest even
    u64 low = m & 0x7ff, half = 0x400;
    u64 hi = m >> 11;
    if (low > half || (low == half && (sticky || (hi & 1))))
        hi++;
    if (hi >> 53) { hi >>= 1; e += 1; }
    Ext r;
    r.m = hi << 11;
    int be = e - 1 + 16383;
    r.se = (unsigned short)(((a.se ^ b.se) & 0x8000) | (be & 0x7fff));
    if (be <= 0 || be >= 0x7fff)     // outside the extended range: never for game values; fall back
        return hulk_x87_to_double(a) / hulk_x87_to_double(b);
    return hulk_x87_to_double(r);    // fstp m64 (denormal double results round again, as on the FPU)
}
double hulk_x87e_div(const Ext* e, double b) { return div53(*e, hulk_x87_from_double(b)); }
double hulk_x87e_rdiv(double a, const Ext* e) { return div53(hulk_x87_from_double(a), *e); }

// fcmp of e against b with an LLVM predicate number (FCmpInst::Predicate: 1 oeq, 2 ogt, 3 oge, 4 olt, 5 ole, 6 one,
// 7 ord, 8 uno, 9 ueq, 10 ugt, 11 uge, 12 ult, 13 ule, 14 une; 0 false, 15 true); swapped: b PRED e.
int hulk_x87e_fcmp(const Ext* ep, double b, int pred, int swapped) {
    Ext e = *ep, f = hulk_x87_from_double(b);
    int rel;   // -1 less, 0 equal, 1 greater, 2 unordered (e against b)
    int ne = (e.se & 0x7fff) == 0x7fff && (e.m << 1) != 0, nf = b != b;
    if (ne || nf)
        rel = 2;
    else {
        int se = e.se >> 15, sf = f.se >> 15;
        int ze = (e.se & 0x7fff) == 0 && e.m == 0, zf = (f.se & 0x7fff) == 0 && f.m == 0;
        if (ze && zf)
            rel = 0;
        else if (se != sf)
            rel = se ? -1 : 1;
        else {
            unsigned short xe = e.se & 0x7fff, xf = f.se & 0x7fff;
            int mag = xe != xf ? (xe < xf ? -1 : 1) : (e.m != f.m ? (e.m < f.m ? -1 : 1) : 0);
            rel = se ? -mag : mag;
        }
    }
    if (swapped && rel != 2)
        rel = -rel;
    int lt = rel == -1, eq = rel == 0, gt = rel == 1, un = rel == 2;
    switch (pred) {
    case 0: return 0;
    case 1: return eq;
    case 2: return gt;
    case 3: return gt || eq;
    case 4: return lt;
    case 5: return lt || eq;
    case 6: return lt || gt;
    case 7: return !un;
    case 8: return un;
    case 9: return un || eq;
    case 10: return un || gt;
    case 11: return un || gt || eq;
    case 12: return un || lt;
    case 13: return un || lt || eq;
    case 14: return !eq;
    default: return 1;
    }
}

}  // extern "C"
