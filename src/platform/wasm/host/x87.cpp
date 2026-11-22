// The x87 math the game's code computes with (wasm6; docs/native-float64.md): softx87's transcendental
// instructions and the 80-bit consumers of their results (tools/native_float.py x87ext, applied by
// tools/wasm_port.py fpfix), as on the 64-bit builds. Integer arithmetic only.
//
// (wasm14) The soft transcendentals were about a third of a play3 run, and the game asks for the same angles again
// and again: each double-argument entry point keeps its last results in a small direct-mapped table (a pure
// function of the argument bits, so the results are the same; the tables are the host's, not game state).
#define HULK_X87_MEMO_FNS(X1, X2) X1(sin) X1(cos) X1(tan) X1(atan) X2(atan2) X1(exp) X1(log) X1(log10) X2(pow) \
    X1(asin) X1(acos)
#define hulk_x87_sin_ext hulk_x87_sin_ext_raw
#define hulk_x87_cos_ext hulk_x87_cos_ext_raw
#define hulk_x87_tan_ext hulk_x87_tan_ext_raw
#define hulk_x87_atan_ext hulk_x87_atan_ext_raw
#define hulk_x87_atan2_ext hulk_x87_atan2_ext_raw
#define hulk_x87_exp_ext hulk_x87_exp_ext_raw
#define hulk_x87_log_ext hulk_x87_log_ext_raw
#define hulk_x87_log10_ext hulk_x87_log10_ext_raw
#define hulk_x87_pow_ext hulk_x87_pow_ext_raw
#define hulk_x87_asin_ext hulk_x87_asin_ext_raw
#define hulk_x87_acos_ext hulk_x87_acos_ext_raw
#include "../../sdl/crt/softx87.cpp"
#undef hulk_x87_sin_ext
#undef hulk_x87_cos_ext
#undef hulk_x87_tan_ext
#undef hulk_x87_atan_ext
#undef hulk_x87_atan2_ext
#undef hulk_x87_exp_ext
#undef hulk_x87_log_ext
#undef hulk_x87_log10_ext
#undef hulk_x87_pow_ext
#undef hulk_x87_asin_ext
#undef hulk_x87_acos_ext

#include <stdint.h>
#include <string.h>

namespace {
enum { MEMO_BITS = 12 };
struct Memo1 { uint64_t k; int used; hulk_x87_ext v; };
struct Memo2 { uint64_t a, b; int used; hulk_x87_ext v; };
inline uint64_t memo_bits(double d) { uint64_t u; memcpy(&u, &d, 8); return u; }
inline uint32_t slot(uint64_t k) { return (uint32_t)((k * 0x9E3779B97F4A7C15ull) >> (64 - MEMO_BITS)); }
}  // namespace

extern "C" {
#define MEMO1(fn) \
    hulk_x87_ext hulk_x87_##fn##_ext(double x) { \
        static Memo1 t[1u << MEMO_BITS]; \
        uint64_t k = memo_bits(x); \
        Memo1& m = t[slot(k)]; \
        if (!m.used || m.k != k) { m.v = hulk_x87_##fn##_ext_raw(x); m.k = k; m.used = 1; } \
        return m.v; \
    }
#define MEMO2(fn) \
    hulk_x87_ext hulk_x87_##fn##_ext(double a, double b) { \
        static Memo2 t[1u << MEMO_BITS]; \
        uint64_t ka = memo_bits(a), kb = memo_bits(b); \
        Memo2& m = t[slot(ka ^ (kb * 0xD6E8FEB86659FD93ull))]; \
        if (!m.used || m.a != ka || m.b != kb) { m.v = hulk_x87_##fn##_ext_raw(a, b); m.a = ka; m.b = kb; m.used = 1; } \
        return m.v; \
    }
HULK_X87_MEMO_FNS(MEMO1, MEMO2)
#undef MEMO1
#undef MEMO2
}

#include "../../sdl/host/x87ext_native.cpp"

// A call of a math function that x87ext left alone (no consumer pattern) still gets the instruction's result,
// not the C library's.
extern "C" {
double sin(double x) { return hulk_x87_to_double(hulk_x87_sin_ext(x)); }
double cos(double x) { return hulk_x87_to_double(hulk_x87_cos_ext(x)); }
double tan(double x) { return hulk_x87_to_double(hulk_x87_tan_ext(x)); }
double atan(double x) { return hulk_x87_to_double(hulk_x87_atan_ext(x)); }
double atan2(double y, double x) { return hulk_x87_to_double(hulk_x87_atan2_ext(y, x)); }
double exp(double x) { return hulk_x87_to_double(hulk_x87_exp_ext(x)); }
double log(double x) { return hulk_x87_to_double(hulk_x87_log_ext(x)); }
double log10(double x) { return hulk_x87_to_double(hulk_x87_log10_ext(x)); }
double pow(double x, double y) { return hulk_x87_to_double(hulk_x87_pow_ext(x, y)); }
double asin(double x) { return hulk_x87_to_double(hulk_x87_asin_ext(x)); }
double acos(double x) { return hulk_x87_to_double(hulk_x87_acos_ext(x)); }
}
