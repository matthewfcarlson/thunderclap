// softx87: see softx87.h and docs/soft-x87.md. Integer-only: no float, double or long double arithmetic anywhere
// (the doubles of the public wrappers are only ever moved as bit patterns), so the results do not depend on the host's
// FPU, its precision control, libm or compiler flags. Written from the instruction semantics in Intel's manuals and
// from published analyses of the hardware's argument reduction; no code from any libm or emulator.
#include "softx87.h"

namespace {

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef hulk_x87_ext Ext;

// ---------------------------------------------------------------------------------------------------------------
// F: a 128-bit software float. Value = (-1)^s * ((hi:lo) / 2^128) * 2^e with hi's top bit set (mantissa in [0.5, 1)),
// or zero (hi = lo = 0). Operations truncate, so each carries an error of a few units of 2^-128 relative.
struct F {
    int s;
    int e;
    u64 hi, lo;
};

inline bool fzero(const F& a) { return a.hi == 0 && a.lo == 0; }
inline F fmake(int s, int e, u64 hi, u64 lo) {
    F r;
    r.s = s;
    r.e = e;
    r.hi = hi;
    r.lo = lo;
    return r;
}
inline F fzeroval(int s) { return fmake(s, 0, 0, 0); }

inline int clz64(u64 v) { return __builtin_clzll(v); }

// shift (hi:lo) left by n in 0..127
inline void shl128(u64& hi, u64& lo, int n) {
    if (n == 0) return;
    if (n >= 64) {
        hi = lo << (n - 64);
        lo = 0;
    } else {
        hi = (hi << n) | (lo >> (64 - n));
        lo <<= n;
    }
}
// shift right by n in 0..127; returns true if a nonzero bit was shifted out
inline bool shr128(u64& hi, u64& lo, int n) {
    if (n == 0) return false;
    bool lost;
    if (n >= 128) {
        lost = (hi | lo) != 0;
        hi = lo = 0;
    } else if (n >= 64) {
        lost = lo != 0 || (n > 64 && (hi & ((1ULL << (n - 64)) - 1)) != 0);
        lo = hi >> (n - 64);
        hi = 0;
    } else {
        lost = (lo & ((1ULL << n) - 1)) != 0;
        lo = (lo >> n) | (hi << (64 - n));
        hi >>= n;
    }
    return lost;
}

inline void fnorm(F& a) {
    if (a.hi == 0 && a.lo == 0) {
        a.e = 0;
        return;
    }
    if (a.hi == 0) {
        a.hi = a.lo;
        a.lo = 0;
        a.e -= 64;
    }
    int z = clz64(a.hi);
    if (z) {
        a.hi = (a.hi << z) | (a.lo >> (64 - z));
        a.lo <<= z;
        a.e -= z;
    }
}

void mul64(u64 a, u64 b, u64& hi, u64& lo) {
    u64 a0 = (u32)a, a1 = a >> 32, b0 = (u32)b, b1 = b >> 32;
    u64 p00 = a0 * b0, p01 = a0 * b1, p10 = a1 * b0, p11 = a1 * b1;
    u64 mid = (p00 >> 32) + (u32)p01 + (u32)p10;
    lo = (mid << 32) | (u32)p00;
    hi = p11 + (p01 >> 32) + (p10 >> 32) + (mid >> 32);
}

F fmul(const F& a, const F& b) {
    int s = a.s ^ b.s;
    if (fzero(a) || fzero(b)) return fzeroval(s);
    u64 h1, h0, x1, x0, y1, y0, z1, z0;
    mul64(a.hi, b.hi, h1, h0);
    mul64(a.hi, b.lo, x1, x0);
    mul64(a.lo, b.hi, y1, y0);
    mul64(a.lo, b.lo, z1, z0);
    (void)z0;
    u64 s1 = z1 + x0;
    u64 c1 = s1 < z1;
    s1 += y0;
    c1 += s1 < y0;
    u64 s2 = h0 + x1;
    u64 c2 = s2 < h0;
    s2 += y1;
    c2 += s2 < y1;
    s2 += c1;
    c2 += s2 < c1;
    F r = fmake(s, a.e + b.e, h1 + c2, s2);
    fnorm(r);
    return r;
}

// a / b
F fdiv(const F& a, const F& b) {
    int s = a.s ^ b.s;
    if (fzero(a)) return fzeroval(s);
    int e = a.e - b.e;
    u64 rh = a.hi, rl = a.lo;
    // A >= B: halve A so that A < B
    if (rh > b.hi || (rh == b.hi && rl >= b.lo)) {
        shr128(rh, rl, 1);
        e += 1;
    }
    u64 qh = 0, ql = 0;
    for (int i = 0; i < 128; i++) {
        u64 carry = rh >> 63;
        rh = (rh << 1) | (rl >> 63);
        rl <<= 1;
        qh = (qh << 1) | (ql >> 63);
        ql <<= 1;
        if (carry || rh > b.hi || (rh == b.hi && rl >= b.lo)) {
            u64 nl = rl - b.lo;
            u64 borrow = rl < b.lo;
            rh = rh - b.hi - borrow;
            rl = nl;
            ql |= 1;
        }
    }
    F r = fmake(s, e, qh, ql);
    fnorm(r);
    return r;
}

// a / d for a small positive integer d (< 65536)
F fdivu(const F& a, u32 d) {
    if (fzero(a)) return a;
    u32 rem = 0;
    u64 w[2] = {a.hi, a.lo};
    for (int k = 0; k < 2; k++) {
        u64 q = 0;
        for (int sh = 48; sh >= 0; sh -= 16) {
            u32 cur = (rem << 16) | (u32)((w[k] >> sh) & 0xffff);
            u32 qd = cur / d;
            rem = cur - qd * d;
            q = (q << 16) | qd;
        }
        w[k] = q;
    }
    F r = fmake(a.s, a.e, w[0], w[1]);
    fnorm(r);
    return r;
}

// |a| vs |b|: -1, 0, 1
int fcmpmag(const F& a, const F& b) {
    bool za = fzero(a), zb = fzero(b);
    if (za || zb) return za == zb ? 0 : (za ? -1 : 1);
    if (a.e != b.e) return a.e < b.e ? -1 : 1;
    if (a.hi != b.hi) return a.hi < b.hi ? -1 : 1;
    if (a.lo != b.lo) return a.lo < b.lo ? -1 : 1;
    return 0;
}

F fadd(const F& a0, const F& b0) {
    if (fzero(a0)) return b0;
    if (fzero(b0)) return a0;
    const F* pa = &a0;
    const F* pb = &b0;
    if (fcmpmag(a0, b0) < 0) {
        pa = &b0;
        pb = &a0;
    }
    const F& a = *pa;
    const F& b = *pb;
    int d = a.e - b.e;
    u64 bh = b.hi, bl = b.lo;
    bool lost = shr128(bh, bl, d > 128 ? 128 : d);
    if (lost) bl |= 1;     // sticky
    F r;
    r.s = a.s;
    r.e = a.e;
    if (a.s == b.s) {
        u64 lo = a.lo + bl;
        u64 c = lo < a.lo;
        u64 hi = a.hi + bh;
        u64 c2 = hi < a.hi;
        hi += c;
        c2 |= hi < c;
        r.hi = hi;
        r.lo = lo;
        if (c2) {
            shr128(r.hi, r.lo, 1);
            r.hi |= 1ULL << 63;
            r.e += 1;
        }
    } else {
        u64 lo = a.lo - bl;
        u64 br = a.lo < bl;
        r.hi = a.hi - bh - br;
        r.lo = lo;
    }
    fnorm(r);
    return r;
}

inline F fneg(F a) {
    a.s ^= 1;
    return a;
}
inline F fsub(const F& a, const F& b) { return fadd(a, fneg(b)); }
inline F fabsv(F a) {
    a.s = 0;
    return a;
}
inline F fscl(F a, int k) {      // times 2^k
    if (!fzero(a)) a.e += k;
    return a;
}

F ffromu64(u64 v, int s = 0) {
    if (v == 0) return fzeroval(s);
    int z = clz64(v);
    return fmake(s, 64 - z, v << z, 0);
}
F ffromint(int v) { return v < 0 ? ffromu64((u64)(-(long long)v), 1) : ffromu64((u64)v, 0); }

// 32-bit integer square root of a 64-bit value
u32 isqrt64(u64 v) {
    u64 res = 0;
    u64 bit = 1ULL << 62;
    while (bit > v) bit >>= 2;
    while (bit) {
        if (v >= res + bit) {
            v -= res + bit;
            res = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }
    return (u32)res;
}

F fsqrt_(const F& a) {
    if (fzero(a)) return a;
    // a = m * 2^e, m in [0.5,1); make the exponent even: m' in [0.25, 1)
    F m = fmake(0, 0, a.hi, a.lo);
    int e = a.e;
    if (e & 1) {
        m.e = -1;       // m/2
        e += 1;
    }
    // m' is in [0.25,1); sqrt in [0.5,1). initial value: 32 bits from the top 64 bits of m'
    u64 top = m.hi;
    if (m.e == 0) top = m.hi >> 0;     // m in [0.5,1): m*2^64 = hi
    else top = m.hi >> 1;              // m/2 * 2^64
    u32 r0 = isqrt64(top);              // sqrt(m' * 2^64) = sqrt(m') * 2^32
    // sqrt(m') * 2^32 -> F: r0 / 2^32
    F y = ffromu64(r0);
    y.e -= 32;
    for (int i = 0; i < 3; i++) {
        F q = fdiv(m, y);
        y = fscl(fadd(y, q), -1);
    }
    y.e += e / 2;
    return y;
}

// ---------------------------------------------------------------------------------------------------------------
// constants (build/soft-intrinsics/gen_consts.py)
const F K_PI = {0, 2, 0xc90fdaa22168c234ULL, 0xc4c6628b80dc1cd1ULL};
const F K_LN2 = {0, 0, 0xb17217f7d1cf79abULL, 0xc9e3b39803f2f6afULL};
const F K_INV_LN2 = {0, 1, 0xb8aa3b295c17f0bbULL, 0xbe87fed0691d3e88ULL};
const F K_LG2 = {0, -1, 0x9a209a84fbcff798ULL, 0x8f8959ac0b7c9178ULL};
const F K_SQRT_HALF = {0, 0, 0xb504f333f9de6484ULL, 0x597d89b3754abe9fULL};
const F K_INV_H = {0, 0, 0xa2f9836e4e44152aULL, 0x00062bc40da276beULL};
const F K_HALF = {0, 0, 0x8000000000000000ULL, 0x0000000000000000ULL};
const F K_ONE = {0, 1, 0x8000000000000000ULL, 0x0000000000000000ULL};

// the FPU's 66-bit approximation of pi: P66 / 2^64 with P66 = 0x3243f6a8885a308d3; H = pi66/2 = P66 / 2^65
const u64 P66_HI = 3ULL;
const u64 P66_LO = 0x243f6a8885a308d3ULL;

// ---------------------------------------------------------------------------------------------------------------
// Ext <-> F, packing
const Ext QNAN_INDEF = {0xC000000000000000ULL, 0xFFFF};

inline int ext_sign(const Ext& x) { return x.se >> 15; }
inline int ext_exp(const Ext& x) { return x.se & 0x7fff; }
inline bool ext_isnan(const Ext& x) { return ext_exp(x) == 0x7fff && (x.m << 1) != 0; }
inline bool ext_isinf(const Ext& x) { return ext_exp(x) == 0x7fff && (x.m << 1) == 0; }
inline bool ext_iszero(const Ext& x) { return x.m == 0 && ext_exp(x) != 0x7fff; }
inline Ext ext_make(int s, u64 m, int bexp) {
    Ext r;
    r.m = m;
    r.se = (u16)((s << 15) | bexp);
    return r;
}
inline Ext ext_inf(int s) { return ext_make(s, 1ULL << 63, 0x7fff); }
inline Ext ext_zero(int s) { return ext_make(s, 0, 0); }
inline Ext ext_one() { return ext_make(0, 1ULL << 63, 16383); }
inline Ext ext_quiet(Ext x) {
    x.m |= 1ULL << 62;
    return x;
}
// two NaNs: the one with the larger significand wins (the manual's rule)
Ext ext_nan2(Ext a, Ext b) {
    bool na = ext_isnan(a), nb = ext_isnan(b);
    if (na && nb) return ext_quiet(a.m >= b.m ? a : b);
    return ext_quiet(na ? a : b);
}

// finite Ext -> F
F toF(const Ext& x) {
    int s = ext_sign(x);
    if (x.m == 0) return fzeroval(s);
    int ex = ext_exp(x);
    if (ex == 0) ex = 1;
    int z = clz64(x.m);
    return fmake(s, ex - 16383 - z + 1, x.m << z, 0);
}

// pack a 64-bit-mantissa value (m normalised, true exponent E) to Ext: overflow to inf, gradual underflow
Ext pack(int s, u64 m, int E) {
    int be = E + 16383;
    if (be >= 0x7fff) return ext_inf(s);
    if (be <= 0) {
        int sh = 1 - be;     // denormal: exponent field 0 means 2^-16382
        if (sh >= 65) return ext_zero(s);
        u64 q, rem, half;
        if (sh == 64) {
            q = 0;
            rem = m;
            half = 1ULL << 63;
        } else {
            q = m >> sh;
            rem = m & ((1ULL << sh) - 1);
            half = 1ULL << (sh - 1);
        }
        if (rem > half || (rem == half && (q & 1))) q++;
        return ext_make(s, q, (q >> 63) ? 1 : 0);
    }
    return ext_make(s, m, be);
}

// round F to `bits` significant bits (nearest even) and pack
Ext toExtBits(const F& a, int bits) {
    int s = a.s;
    if (fzero(a)) return ext_zero(s);
    u64 m = a.hi;
    int E = a.e - 1;
    bool up;
    if (bits >= 64) {
        up = a.lo > (1ULL << 63) || (a.lo == (1ULL << 63) && (m & 1));
        if (up) {
            m++;
            if (m == 0) {
                m = 1ULL << 63;
                E++;
            }
        }
        return pack(s, m, E);
    }
    int low = 64 - bits;
    u64 lowmask = (1ULL << low) - 1;
    u64 rem = m & lowmask;
    u64 half = 1ULL << (low - 1);
    m &= ~lowmask;
    if (rem > half || (rem == half && (a.lo != 0 || (m & (1ULL << low)) != 0))) up = true;
    else up = false;
    if (up) {
        m += 1ULL << low;
        if (m == 0) {
            m = 1ULL << 63;
            E++;
        }
    }
    return pack(s, m, E);
}
inline Ext toExt(const F& a) { return toExtBits(a, 64); }

// ---------------------------------------------------------------------------------------------------------------
// double / float images
u64 dbits(double d) {
    u64 b;
    __builtin_memcpy(&b, &d, 8);
    return b;
}
double bitsd(u64 b) {
    double d;
    __builtin_memcpy(&d, &b, 8);
    return d;
}
u32 fbits(float f) {
    u32 b;
    __builtin_memcpy(&b, &f, 4);
    return b;
}
float bitsf(u32 b) {
    float f;
    __builtin_memcpy(&f, &b, 4);
    return f;
}

Ext from_ieee(int s, u64 frac, int ex, int fbitsn, int exmax, int bias) {
    if (ex == exmax) {
        if (frac == 0) return ext_inf(s);
        return ext_make(s, (3ULL << 62) | (frac << (63 - fbitsn)), 0x7fff);
    }
    if (ex == 0) {
        if (frac == 0) return ext_zero(s);
        int z = clz64(frac);
        int E = (63 - (bias - 1 + fbitsn)) - z;     // value = frac * 2^(1 - bias - fbitsn)
        return ext_make(s, frac << z, E + 16383);
    }
    return ext_make(s, (1ULL << 63) | (frac << (63 - fbitsn)), ex - bias + 16383);
}

// Ext -> IEEE image (without the sign): mantissa bits mbits (52 / 23), minimum normal exponent emin, exponent bias
u64 to_ieee(const Ext& x, int mbits, int emin, int emax, int bias) {
    int be = ext_exp(x);
    u64 expmax = (u64)(emax + bias + 1);
    if (be == 0x7fff) {
        if ((x.m << 1) == 0) return expmax << mbits;
        return (expmax << mbits) | (1ULL << (mbits - 1)) | ((x.m >> (63 - mbits)) & ((1ULL << mbits) - 1));
    }
    if (x.m == 0 || be == 0) return 0;
    int E = be - 16383;
    int d = E < emin ? emin - E : 0;
    int sh = (63 - mbits) + d;
    u64 q;
    if (sh > 64) return 0;
    u64 rem, half;
    if (sh == 64) {
        q = 0;
        rem = x.m;
        half = 1ULL << 63;
    } else {
        q = x.m >> sh;
        rem = x.m & ((1ULL << sh) - 1);
        half = 1ULL << (sh - 1);
    }
    if (rem > half || (rem == half && (q & 1))) q++;
    u64 bits;
    if (d) bits = q;      // subnormal: frac = q (2^mbits carries into the exponent field)
    else bits = ((u64)(E + bias) << mbits) + (q - (1ULL << mbits));
    if (E > emax) bits = expmax << mbits;
    if (bits >= (expmax << mbits)) bits = expmax << mbits;
    return bits;
}

// PC rounding of a normal Ext to `bits` bits
Ext round_pc_(const Ext& x, int bits) {
    if (bits >= 64 || ext_exp(x) == 0x7fff || x.m == 0) return x;
    F f = toF(x);
    return toExtBits(f, bits);
}

// ---------------------------------------------------------------------------------------------------------------
// series
// sin(r) and cos(r) for |r| <= ~0.8 (signed r)
F sinSeries(const F& r) {
    if (fzero(r)) return r;
    F r2 = fabsv(fmul(r, r));
    F term = r, sum = r;
    for (u32 k = 1; k < 60; k++) {
        term = fmul(term, r2);
        term = fdivu(term, (2 * k) * (2 * k + 1));
        term.s ^= 1;
        sum = fadd(sum, term);
        if (fzero(term) || term.e < sum.e - 136) break;
    }
    return sum;
}
F cosSeries(const F& r) {
    F r2 = fabsv(fmul(r, r));
    F term = K_ONE, sum = K_ONE;
    for (u32 k = 1; k < 60; k++) {
        term = fmul(term, r2);
        term = fdivu(term, (2 * k - 1) * (2 * k));
        term.s ^= 1;
        sum = fadd(sum, term);
        if (fzero(term) || term.e < sum.e - 136) break;
    }
    return sum;
}

// atan(w) for small w (|w| < 0.11)
F atanSeries(const F& w) {
    if (fzero(w)) return w;
    F w2 = fabsv(fmul(w, w));
    F pw = w, sum = w;
    for (u32 k = 1; k < 80; k++) {
        pw = fmul(pw, w2);
        pw.s ^= 1;
        F term = fdivu(pw, 2 * k + 1);
        sum = fadd(sum, term);
        if (fzero(term) || term.e < sum.e - 136) break;
    }
    return sum;
}

// atan(k/8) for k = 1..8 (build/soft-intrinsics/gen_consts.py)
const F K_ATAN8[9] = {
    {0, 0, 0, 0},
    {0, -3, 0xfeadd4d5617b6e32ULL, 0xc897989f3e888ef7ULL},
    {0, -2, 0xfadbafc96406eb15ULL, 0x6dc79ef5f7a217e5ULL},
    {0, -1, 0xb7b0ca0f26f78473ULL, 0x8aa32122dcfe4483ULL},
    {0, -1, 0xed63382b0dda7b45ULL, 0x6fe445ecbc3a8d03ULL},
    {0, 0, 0x8f005d5ef7f59f9bULL, 0x5c835e1665c43747ULL},
    {0, 0, 0xa4bc7d1934f70924ULL, 0x19a87f2a457dac9eULL},
    {0, 0, 0xb8053e2bc2319e73ULL, 0xcb2da55210a4443dULL},
    {0, 0, 0xc90fdaa22168c234ULL, 0xc4c6628b80dc1cd1ULL},
};

// integer part of a non-negative F (below 2^64)
u64 ffloor(const F& t) {
    if (t.e <= 0) return 0;
    return t.e >= 64 ? t.hi : (t.hi >> (64 - t.e));
}

// atan(z) for 0 <= z <= 1: atan(z) = atan(c) + atan((z - c) / (1 + c z)) with c = k/8 the nearest eighth
F atanUnit(const F& z) {
    if (fzero(z)) return z;
    u64 k = ffloor(fadd(fscl(z, 3), K_HALF));
    if (k == 0) return atanSeries(z);
    F c = fscl(ffromu64(k), -3);
    F w = fdiv(fsub(z, c), fadd(K_ONE, fmul(c, z)));
    return fadd(K_ATAN8[k], atanSeries(w));
}

// Sum t^(2j+1)/(2j+1): atanh(t)
F atanhSeries(const F& t) {
    if (fzero(t)) return t;
    F t2 = fabsv(fmul(t, t));
    F pw = t, sum = t;
    for (u32 k = 1; k < 80; k++) {
        pw = fmul(pw, t2);
        F term = fdivu(pw, 2 * k + 1);
        sum = fadd(sum, term);
        if (fzero(term) || term.e < sum.e - 136) break;
    }
    return sum;
}

// atan2(y, x) of finite nonzero y, x (F, signed): the angle in (-pi, pi]
F atan2F(const F& y, const F& x) {
    F ay = fabsv(y), ax = fabsv(x);
    F a;
    if (fcmpmag(ay, ax) <= 0) a = atanUnit(fdiv(ay, ax));
    else a = fsub(fscl(K_PI, -1), atanUnit(fdiv(ax, ay)));
    if (x.s) a = fsub(K_PI, a);
    a.s = y.s;
    return a;
}

// log2 of a positive F
F log2F(const F& x) {
    int k = x.e;
    F m = fmake(0, 0, x.hi, x.lo);           // [0.5, 1)
    if (fcmpmag(m, K_SQRT_HALF) < 0) {
        m.e = 1;                              // [1, sqrt 2)
        k -= 1;
    }
    F t = fdiv(fsub(m, K_ONE), fadd(m, K_ONE));
    F ln = fscl(atanhSeries(t), 1);
    return fadd(ffromint(k), fmul(ln, K_INV_LN2));
}

// log2(1 + x) for a finite F with x > -1
F log2p1F(const F& x) {
    if (fzero(x)) return x;
    if (x.e <= -1) {      // |x| < 0.5: t = x / (2 + x)
        F t = fdiv(x, fadd(fscl(K_ONE, 1), x));
        return fmul(fscl(atanhSeries(t), 1), K_INV_LN2);
    }
    return log2F(fadd(K_ONE, x));
}

// e^y - 1 with relative accuracy for small y
F expm1F(const F& y) {
    if (fzero(y)) return y;
    int h = y.e + 4;
    if (h < 0) h = 0;
    if (h > 60) h = 60;
    F ys = fscl(y, -h);
    F term = ys, sum = ys;
    for (u32 k = 2; k < 80; k++) {
        term = fdivu(fmul(term, ys), k);
        sum = fadd(sum, term);
        if (fzero(term) || term.e < sum.e - 136) break;
    }
    for (int i = 0; i < h; i++) sum = fadd(fscl(sum, 1), fmul(sum, sum));
    return sum;
}

// ---------------------------------------------------------------------------------------------------------------
// 192-bit helpers for the exact argument reduction
void sub192(u64* a, const u64* b) {
    u64 br = 0;
    for (int i = 0; i < 3; i++) {
        u64 t = a[i] - b[i];
        u64 b1 = a[i] < b[i];
        u64 r = t - br;
        b1 |= t < br;
        a[i] = r;
        br = b1;
    }
}
void add192(u64* a, const u64* b) {
    u64 c = 0;
    for (int i = 0; i < 3; i++) {
        u64 t = a[i] + b[i];
        u64 c1 = t < a[i];
        u64 r = t + c;
        c1 |= r < t;
        a[i] = r;
        c = c1;
    }
}
void neg192(u64* a) {
    for (int i = 0; i < 3; i++) a[i] = ~a[i];
    u64 one[3] = {1, 0, 0};
    add192(a, one);
}
int cmp192(const u64* a, const u64* b) {
    for (int i = 2; i >= 0; i--)
        if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;
    return 0;
}

// Reduce ax (positive, finite, pi/4 <= ax < 2^63, from an Ext) by H = pi66/2: ax = n*H + r with |r| <= H/2, exactly.
// Returns n mod 4 in `quad`, r signed in `r`.
void reduceArg(const F& ax, unsigned& quad, F& r) {
    F t = fadd(fmul(ax, K_INV_H), K_HALF);
    u64 n = ffloor(t);
    int sh = (ax.e - 1) + 2;                 // x * 2^65 = M << sh (M = the 64-bit mantissa), 1 <= sh <= 64
    u64 X[3] = {0, 0, 0};
    u64 M = ax.hi;
    if (sh < 64) {
        X[0] = M << sh;
        X[1] = M >> (64 - sh);
    } else {
        X[1] = M;
    }
    u64 a1, a0, b1, b0;
    mul64(n, P66_LO, a1, a0);
    mul64(n, 3, b1, b0);
    u64 N[3];
    N[0] = a0;
    N[1] = a1 + b0;
    N[2] = b1 + (N[1] < a1);
    sub192(X, N);                            // X = x*2^65 - n*P66
    const u64 P[3] = {P66_LO, P66_HI, 0};
    u64 mag[3];
    int neg;
    for (;;) {
        neg = (int)(X[2] >> 63);
        mag[0] = X[0];
        mag[1] = X[1];
        mag[2] = X[2];
        if (neg) neg192(mag);
        u64 twice[3] = {mag[0] << 1, (mag[1] << 1) | (mag[0] >> 63), (mag[2] << 1) | (mag[1] >> 63)};
        if (cmp192(twice, P) > 0) {
            if (!neg) {
                n++;
                sub192(X, P);
            } else {
                n--;
                add192(X, P);
            }
            continue;
        }
        break;
    }
    quad = (unsigned)(n & 3);
    u64 h = mag[1], l = mag[0];
    if (h == 0 && l == 0) {
        r = fzeroval(0);
        return;
    }
    int L = h ? (64 - clz64(h)) + 64 : 64 - clz64(l);
    shl128(h, l, 128 - L);
    r = fmake(neg, L - 65, h, l);
}

enum { OP_SIN = 0, OP_COS = 1, OP_TAN = 2, OP_SINCOS = 3 };

int trigImpl(const Ext& x, int op, Ext* o1, Ext* o2) {
    if (ext_isnan(x)) {
        *o1 = ext_quiet(x);
        if (o2) *o2 = *o1;
        return 0;
    }
    if (ext_isinf(x)) {
        *o1 = QNAN_INDEF;
        if (o2) *o2 = QNAN_INDEF;
        return 0;
    }
    if (ext_exp(x) >= 16383 + 63) {
        *o1 = x;
        if (o2) *o2 = x;
        return 1;
    }
    if (x.m == 0) {
        switch (op) {
        case OP_SIN: case OP_TAN: *o1 = x; break;
        case OP_COS: *o1 = ext_one(); break;
        default: *o1 = x; *o2 = ext_one(); break;
        }
        return 0;
    }
    F xf = toF(x);
    int xs = xf.s;
    F ax = fabsv(xf);
    unsigned quad = 0;
    F r = ax;
    if (fcmpmag(ax, fscl(K_PI, -2)) >= 0) reduceArg(ax, quad, r);
    bool odd = (quad & 1) != 0;
    F sn = fzeroval(0), cs = fzeroval(0);
    bool needS = op >= OP_TAN || (op == OP_SIN) != odd;
    bool needC = op >= OP_TAN || (op == OP_COS) != odd;
    if (op == OP_SIN) { needS = !odd; needC = odd; }
    else if (op == OP_COS) { needS = odd; needC = !odd; }
    if (needS) sn = sinSeries(r);
    if (needC) cs = cosSeries(r);
    F res, res2 = fzeroval(0);
    if (op == OP_SIN || op == OP_SINCOS) {
        res = odd ? cs : sn;
        if (quad & 2) res = fneg(res);
        if (xs) res = fneg(res);
    }
    if (op == OP_COS || op == OP_SINCOS) {
        F c = odd ? sn : cs;
        if (quad == 1 || quad == 2) c = fneg(c);
        if (op == OP_COS) res = c;
        else res2 = c;
    }
    if (op == OP_TAN) {
        if (!odd) {
            res = fdiv(sn, cs);
        } else if (fzero(sn)) {
            *o1 = ext_inf(xs);
            return 0;
        } else {
            res = fneg(fdiv(cs, sn));
        }
        if (xs) res = fneg(res);
    }
    *o1 = toExt(res);
    if (op == OP_SINCOS) *o2 = toExt(res2);
    return 0;
}

// integer part of |x| as a clamped count (for fscale)
long long trunc_clamped(const Ext& x) {
    int E = ext_exp(x) - 16383;
    if (x.m == 0 || E < 0) return 0;
    if (E >= 20) return ext_sign(x) ? -(1LL << 20) : (1LL << 20);
    long long k = (long long)(x.m >> (63 - E));
    return ext_sign(x) ? -k : k;
}

Ext pi_ext(int s, int num) {      // s * num * pi / 4 for num = 1, 2, 3, 4
    F p = fscl(K_PI, -2);
    if (num == 2) p = fscl(p, 1);
    else if (num == 3) p = fsub(K_PI, p);
    else if (num == 4) p = K_PI;
    p.s = s;
    return toExt(p);
}

bool ext_isone(const Ext& x) { return x.m == (1ULL << 63) && x.se == 16383; }

// 128 / 64 -> 64 division by shift and subtract: (nh:nl) / d with nh < d
void divmod128(u64 nh, u64 nl, u64 d, u64& q, u64& r) {
    u64 rem = nh;
    u64 quo = 0;
    for (int i = 0; i < 64; i++) {
        u64 carry = rem >> 63;
        rem = (rem << 1) | (nl >> 63);
        nl <<= 1;
        quo <<= 1;
        if (carry || rem >= d) {
            rem -= d;
            quo |= 1;
        }
    }
    q = quo;
    r = rem;
}

int premImpl(Ext* rem, const Ext& b, u64* q, bool nearest) {
    const Ext a = *rem;
    *q = 0;
    if (ext_isnan(a) || ext_isnan(b)) {
        *rem = ext_nan2(a, b);
        return 0;
    }
    if (ext_isinf(a) || ext_iszero(b)) {
        *rem = QNAN_INDEF;
        return 0;
    }
    if (ext_isinf(b) || ext_iszero(a)) return 0;
    F fa = toF(a), fb = toF(b);
    int sa = fa.s;
    u64 Ma = fa.hi, Mb = fb.hi;
    int Ea = fa.e - 1, Eb = fb.e - 1;
    int D = Ea - Eb;
    if (D < 0) {
        if (!nearest || D < -1 || Ma <= Mb) return 0;      // |a| <= |b|/2: quotient rounds to 0
        // D == -1 and |a| > |b|/2: Q = 1, remainder |b| - |a| with the opposite sign
        u64 lo2 = Mb << 1;
        u64 hi2 = Mb >> 63;
        u64 diff_lo = lo2 - Ma;
        u64 diff_hi = hi2 - (lo2 < Ma);
        *q = 1;
        if (diff_lo == 0 && diff_hi == 0) {
            *rem = ext_zero(sa ^ 1);
            return 0;
        }
        // value (diff_hi:diff_lo) * 2^(Ea-63)
        F v = fmake(sa ^ 1, 0, 0, 0);
        u64 h = diff_hi, l = diff_lo;
        int L = h ? 128 - clz64(h) : 64 - clz64(l);
        shl128(h, l, 128 - L);
        v.hi = h;
        v.lo = l;
        v.e = L + (Ea - 63);
        *rem = toExt(v);
        return 0;
    }
    int N = D >= 64 ? 63 : D;
    bool partial = D >= 64;
    u64 Q, R;
    if (N == 0) {
        Q = Ma >= Mb ? 1 : 0;
        R = Q ? Ma - Mb : Ma;
    } else {
        divmod128(Ma >> (64 - N), Ma << N, Mb, Q, R);
    }
    int flip = 0;
    if (nearest && !partial) {
        u64 other = Mb - R;
        if (R > other || (R == other && (Q & 1))) {
            Q++;
            R = other;
            flip = 1;
        }
    }
    *q = Q;
    if (R == 0) {
        *rem = ext_zero(sa);
        return partial ? 1 : 0;
    }
    int lz = clz64(R);
    *rem = pack(sa ^ flip, R << lz, Eb + (D - N) - lz);
    return partial ? 1 : 0;
}

Ext arith(const Ext& a, const Ext& b, int op, int bits) {     // 0 add, 1 sub, 2 mul
    if (ext_isnan(a) || ext_isnan(b)) return ext_nan2(a, b);
    int sb = ext_sign(b) ^ (op == 1);
    if (op == 2) {
        int s = ext_sign(a) ^ ext_sign(b);
        if (ext_isinf(a) || ext_isinf(b)) return (ext_iszero(a) || ext_iszero(b)) ? QNAN_INDEF : ext_inf(s);
        if (ext_iszero(a) || ext_iszero(b)) return ext_zero(s);
        return toExtBits(fmul(toF(a), toF(b)), bits);
    }
    if (ext_isinf(a) || ext_isinf(b)) {
        if (ext_isinf(a) && ext_isinf(b)) return ext_sign(a) == sb ? a : QNAN_INDEF;
        return ext_isinf(a) ? a : ext_inf(sb);
    }
    F fa = toF(a), fb = toF(b);
    fb.s = sb;
    if (fzero(fa) && fzero(fb)) return ext_zero(fa.s & fb.s);
    F r = fadd(fa, fb);
    if (fzero(r)) return ext_zero(0);
    return toExtBits(r, bits);
}

}  // namespace

// ---------------------------------------------------------------------------------------------------------------
// public API
extern "C" {

hulk_x87_ext hulk_x87_from_double(double d) {
    u64 b = dbits(d);
    return from_ieee((int)(b >> 63), b & ((1ULL << 52) - 1), (int)((b >> 52) & 0x7ff), 52, 0x7ff, 1023);
}
hulk_x87_ext hulk_x87_from_float(float f) {
    u32 b = fbits(f);
    return from_ieee((int)(b >> 31), b & ((1u << 23) - 1), (int)((b >> 23) & 0xff), 23, 0xff, 127);
}
double hulk_x87_to_double(hulk_x87_ext x) {
    return bitsd(((u64)ext_sign(x) << 63) | to_ieee(x, 52, -1022, 1023, 1023));
}
float hulk_x87_to_float(hulk_x87_ext x) {
    return bitsf((u32)(((u32)ext_sign(x) << 31) | (u32)to_ieee(x, 23, -126, 127, 127)));
}
hulk_x87_ext hulk_x87_round_pc(hulk_x87_ext x, int pc_bits) { return round_pc_(x, pc_bits); }

int hulk_x87_fsin(hulk_x87_ext x, hulk_x87_ext* out) { return trigImpl(x, OP_SIN, out, 0); }
int hulk_x87_fcos(hulk_x87_ext x, hulk_x87_ext* out) { return trigImpl(x, OP_COS, out, 0); }
int hulk_x87_fsincos(hulk_x87_ext x, hulk_x87_ext* s, hulk_x87_ext* c) { return trigImpl(x, OP_SINCOS, s, c); }
int hulk_x87_fptan(hulk_x87_ext x, hulk_x87_ext* out) { return trigImpl(x, OP_TAN, out, 0); }

hulk_x87_ext hulk_x87_fpatan(hulk_x87_ext y, hulk_x87_ext x) {
    if (ext_isnan(y) || ext_isnan(x)) return ext_nan2(y, x);
    int ys = ext_sign(y), xs = ext_sign(x);
    if (ext_iszero(y)) return xs ? pi_ext(ys, 4) : ext_zero(ys);
    if (ext_iszero(x)) return pi_ext(ys, 2);
    if (ext_isinf(y)) {
        if (ext_isinf(x)) return xs ? pi_ext(ys, 3) : pi_ext(ys, 1);
        return pi_ext(ys, 2);
    }
    if (ext_isinf(x)) return xs ? pi_ext(ys, 4) : ext_zero(ys);
    return toExt(atan2F(toF(y), toF(x)));
}

hulk_x87_ext hulk_x87_f2xm1(hulk_x87_ext x) {
    if (ext_isnan(x)) return ext_quiet(x);
    if (ext_iszero(x)) return x;
    if (ext_isinf(x)) return ext_sign(x) ? ext_make(1, 1ULL << 63, 16383) : x;
    if (ext_exp(x) >= 16383 + 7) return ext_sign(x) ? ext_make(1, 1ULL << 63, 16383) : ext_inf(0);
    return toExt(expm1F(fmul(toF(x), K_LN2)));
}

hulk_x87_ext hulk_x87_fyl2x(hulk_x87_ext x, hulk_x87_ext y) {
    if (ext_isnan(x) || ext_isnan(y)) return ext_nan2(x, y);
    int ys = ext_sign(y);
    if (ext_iszero(x)) return ext_iszero(y) ? QNAN_INDEF : ext_inf(ys ^ 1);
    if (ext_sign(x)) return QNAN_INDEF;
    bool below1 = ext_exp(x) < 16383;
    if (ext_isinf(x)) return ext_iszero(y) ? QNAN_INDEF : ext_inf(ys);
    if (ext_isone(x)) return ext_isinf(y) ? QNAN_INDEF : ext_zero(ys);
    if (ext_iszero(y)) return ext_zero(ys ^ (below1 ? 1 : 0));
    if (ext_isinf(y)) return ext_inf(ys ^ (below1 ? 1 : 0));
    return toExt(fmul(log2F(toF(x)), toF(y)));
}

hulk_x87_ext hulk_x87_fyl2xp1(hulk_x87_ext x, hulk_x87_ext y) {
    if (ext_isnan(x) || ext_isnan(y)) return ext_nan2(x, y);
    int ys = ext_sign(y), xs = ext_sign(x);
    if (ext_isinf(x)) {
        if (xs) return QNAN_INDEF;
        return ext_iszero(y) ? QNAN_INDEF : ext_inf(ys);
    }
    if (ext_iszero(x)) return ext_isinf(y) ? QNAN_INDEF : ext_zero(xs ^ ys);
    F xf = toF(x);
    if (xs && fcmpmag(xf, K_ONE) >= 0) {
        if (fcmpmag(xf, K_ONE) == 0) return ext_iszero(y) ? QNAN_INDEF : ext_inf(ys ^ 1);
        return QNAN_INDEF;
    }
    if (ext_iszero(y)) return ext_zero(ys ^ xs);
    if (ext_isinf(y)) return ext_inf(ys ^ xs);
    return toExt(fmul(log2p1F(xf), toF(y)));
}

hulk_x87_ext hulk_x87_fscale(hulk_x87_ext a, hulk_x87_ext b) {
    if (ext_isnan(a) || ext_isnan(b)) return ext_nan2(a, b);
    if (ext_isinf(b)) {
        if (!ext_sign(b)) return ext_iszero(a) ? QNAN_INDEF : (ext_isinf(a) ? a : ext_inf(ext_sign(a)));
        return ext_isinf(a) ? QNAN_INDEF : ext_zero(ext_sign(a));
    }
    if (ext_isinf(a) || ext_iszero(a)) return a;
    long long k = trunc_clamped(b);
    F f = toF(a);
    f.e += (int)k;
    return toExt(f);
}

hulk_x87_ext hulk_x87_frndint(hulk_x87_ext x) {
    if (ext_isnan(x)) return ext_quiet(x);
    int be = ext_exp(x);
    if (be == 0x7fff || x.m == 0 || be == 0) return x;
    int E = be - 16383;
    int s = ext_sign(x);
    if (E >= 63) return x;
    if (E < -1) return ext_zero(s);
    int shift = 63 - E;
    u64 q, rem, half;
    if (shift == 64) {
        q = 0;
        rem = x.m;
        half = 1ULL << 63;
    } else {
        q = x.m >> shift;
        rem = x.m & ((1ULL << shift) - 1);
        half = 1ULL << (shift - 1);
    }
    if (rem > half || (rem == half && (q & 1))) q++;
    if (q == 0) return ext_zero(s);
    int z = clz64(q);
    return pack(s, q << z, 63 - z);
}

int hulk_x87_fprem(hulk_x87_ext* rem, hulk_x87_ext st1, unsigned long long* q) { return premImpl(rem, st1, q, false); }
int hulk_x87_fprem1(hulk_x87_ext* rem, hulk_x87_ext st1, unsigned long long* q) { return premImpl(rem, st1, q, true); }

hulk_x87_ext hulk_x87_fsqrt(hulk_x87_ext x, int pc_bits) {
    if (ext_isnan(x)) return ext_quiet(x);
    if (ext_iszero(x)) return x;
    if (ext_sign(x)) return QNAN_INDEF;
    if (ext_isinf(x)) return x;
    return toExtBits(fsqrt_(toF(x)), pc_bits);
}
hulk_x87_ext hulk_x87_fmul(hulk_x87_ext a, hulk_x87_ext b, int pc) { return arith(a, b, 2, pc); }
hulk_x87_ext hulk_x87_fadd(hulk_x87_ext a, hulk_x87_ext b, int pc) { return arith(a, b, 0, pc); }
hulk_x87_ext hulk_x87_fsub(hulk_x87_ext a, hulk_x87_ext b, int pc) { return arith(a, b, 1, pc); }

// ---- double wrappers ----------------------------------------------------------------------------------------------
// *_ext: the 80-bit result as the instruction leaves it in st(0) (what the original's code goes on to compute with);
// the plain ones store it to a double.
hulk_x87_ext hulk_x87_sin_ext(double x) {
    Ext r;
    hulk_x87_fsin(hulk_x87_from_double(x), &r);
    return r;
}
hulk_x87_ext hulk_x87_cos_ext(double x) {
    Ext r;
    hulk_x87_fcos(hulk_x87_from_double(x), &r);
    return r;
}
hulk_x87_ext hulk_x87_tan_ext(double x) {
    Ext r;
    hulk_x87_fptan(hulk_x87_from_double(x), &r);
    return r;
}
hulk_x87_ext hulk_x87_atan_ext(double x) { return hulk_x87_fpatan(hulk_x87_from_double(x), ext_one()); }
hulk_x87_ext hulk_x87_atan2_ext(double y, double x) { return hulk_x87_fpatan(hulk_x87_from_double(y), hulk_x87_from_double(x)); }
hulk_x87_ext hulk_x87_exp_ext(double x) {
    Ext a = hulk_x87_from_double(x);
    Ext l2e = toExt(K_INV_LN2);
    Ext t = hulk_x87_fmul(a, l2e, 53);
    Ext i = hulk_x87_frndint(t);
    Ext f = hulk_x87_fsub(t, i, 53);
    Ext p = hulk_x87_f2xm1(f);
    Ext p1 = hulk_x87_fadd(p, ext_one(), 53);
    return hulk_x87_fscale(p1, i);
}
hulk_x87_ext hulk_x87_log_ext(double x) { return hulk_x87_fyl2x(hulk_x87_from_double(x), toExt(K_LN2)); }
hulk_x87_ext hulk_x87_log10_ext(double x) { return hulk_x87_fyl2x(hulk_x87_from_double(x), toExt(K_LG2)); }

hulk_x87_ext hulk_x87_pow_ext(double x, double y) {
    Ext ex = hulk_x87_from_double(x), ey = hulk_x87_from_double(y);
    if (ext_iszero(ey)) return ext_one();
    if (ext_isnan(ex) || ext_isnan(ey)) return ext_nan2(ex, ey);
    if (ext_isone(ex)) return ext_one();
    // is y an integer, odd?
    bool yint = false, yodd = false;
    if (!ext_isinf(ey)) {
        Ext ri = hulk_x87_frndint(ey);
        yint = ri.m == ey.m && ri.se == ey.se;
        if (yint) {
            int E = ext_exp(ey) - 16383;
            if (E < 63) yodd = ((ey.m >> (63 - E)) & 1) != 0;
        }
    }
    int xs = ext_sign(ex);
    int ys = ext_sign(ey);
    int rs = (xs && yodd) ? 1 : 0;
    if (ext_iszero(ex)) return ys ? ext_inf(rs) : ext_zero(rs);
    if (ext_isinf(ex)) return ys ? ext_zero(rs) : ext_inf(rs);
    Ext ax = ex;
    ax.se &= 0x7fff;
    if (ext_isinf(ey)) {
        if (ext_isone(ax)) return ext_one();
        bool gt1 = ext_exp(ax) >= 16383;
        bool big = gt1 != (ys != 0);
        return big ? ext_inf(0) : ext_zero(0);
    }
    if (xs && !yint) return QNAN_INDEF;
    Ext L = hulk_x87_fyl2x(ax, ey);
    if (ext_isinf(L)) return ext_sign(L) ? ext_zero(rs) : ext_inf(rs);
    Ext i = hulk_x87_frndint(L);
    Ext f = hulk_x87_fsub(L, i, 64);
    Ext p = hulk_x87_f2xm1(f);
    Ext p1 = hulk_x87_fadd(p, ext_one(), 64);
    Ext r = hulk_x87_fscale(p1, i);
    r.se = (u16)((r.se & 0x7fff) | (rs << 15));
    return r;
}

hulk_x87_ext hulk_x87_asin_ext(double x) {
    Ext e = hulk_x87_from_double(x);
    if (ext_isnan(e)) return ext_quiet(e);
    if (ext_iszero(e)) return e;
    F xf = toF(e);
    int c = fcmpmag(xf, K_ONE);
    if (c > 0 || ext_isinf(e)) return QNAN_INDEF;
    if (c == 0) return pi_ext(xf.s, 2);
    F ax = fabsv(xf);
    F root = fsqrt_(fmul(fsub(K_ONE, ax), fadd(K_ONE, ax)));
    return toExt(atan2F(xf, root));
}
hulk_x87_ext hulk_x87_acos_ext(double x) {
    Ext e = hulk_x87_from_double(x);
    if (ext_isnan(e)) return ext_quiet(e);
    if (ext_iszero(e)) return pi_ext(0, 2);
    F xf = toF(e);
    int c = fcmpmag(xf, K_ONE);
    if (c > 0 || ext_isinf(e)) return QNAN_INDEF;
    if (c == 0) return xf.s ? pi_ext(0, 4) : ext_zero(0);
    F ax = fabsv(xf);
    F root = fsqrt_(fmul(fsub(K_ONE, ax), fadd(K_ONE, ax)));
    return toExt(atan2F(root, xf));
}

double hulk_x87_sin(double x) { return hulk_x87_to_double(hulk_x87_sin_ext(x)); }
double hulk_x87_cos(double x) { return hulk_x87_to_double(hulk_x87_cos_ext(x)); }
double hulk_x87_tan(double x) { return hulk_x87_to_double(hulk_x87_tan_ext(x)); }
double hulk_x87_atan(double x) { return hulk_x87_to_double(hulk_x87_atan_ext(x)); }
double hulk_x87_atan2(double y, double x) { return hulk_x87_to_double(hulk_x87_atan2_ext(y, x)); }
double hulk_x87_exp(double x) { return hulk_x87_to_double(hulk_x87_exp_ext(x)); }
double hulk_x87_log(double x) { return hulk_x87_to_double(hulk_x87_log_ext(x)); }
double hulk_x87_log10(double x) { return hulk_x87_to_double(hulk_x87_log10_ext(x)); }
double hulk_x87_pow(double x, double y) { return hulk_x87_to_double(hulk_x87_pow_ext(x, y)); }
double hulk_x87_asin(double x) { return hulk_x87_to_double(hulk_x87_asin_ext(x)); }
double hulk_x87_acos(double x) { return hulk_x87_to_double(hulk_x87_acos_ext(x)); }

double hulk_x87_fmod(double x, double y) {
    Ext r = hulk_x87_from_double(x), b = hulk_x87_from_double(y);
    u64 q;
    for (int i = 0; i < 100; i++)
        if (!hulk_x87_fprem(&r, b, &q)) break;
    return hulk_x87_to_double(r);
}

double hulk_x87_sqrt(double x) { return hulk_x87_to_double(hulk_x87_fsqrt(hulk_x87_from_double(x), 53)); }

}  // extern "C"
