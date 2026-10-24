// Our own pieces of the native image's C runtime (host_crt.h): what msvcrt.dll doesn't export or what has to know
// about the game (its /GS cookie, its stdio objects, its paths). Native builds only: tools/native_link.py compiles
// this directory and binds the tree's references to these functions and data by XBE address or name
// (host_crt_table.h).
#include "host_crt.h"

extern "C" {

// ---------------------------------------------------------------------------------------------------------------
// /GS: the game's lifted code reads the cookie (XBE 0x004d9968) itself and passes `cookie ^ ebp` back to
// __security_check_cookie (ecx: fastcall, or a thiscall member in one source). Any constant works as long as both
// sides read this one word; a mismatch means the frame's copy was overwritten.
hulk_u32 hulk_crt_security_cookie = 0xbb40e64eu;
int _fltused = 0x9875;  // the symbol clang (MS ABI) references from every TU that uses floating point

void hulk_native_missing(const char* name);
void __fastcall hulk_crt_security_check_cookie(hulk_u32 cookie) {
    if (cookie != hulk_crt_security_cookie)
        hulk_native_missing("__security_check_cookie: stack cookie overwritten");
}

// ---------------------------------------------------------------------------------------------------------------
// atexit: the game's dynamic initializers register their destructors here; they run in reverse when main returns
// (startup.cpp). On the Xbox they never ran (main doesn't return).
typedef void(HULK_HOST_CDECL* hulk_exit_fn)(void);
static hulk_exit_fn hulk_crt_exit_fns_[2048];
static hulk_u32 hulk_crt_exit_n_;

int HULK_HOST_CDECL hulk_crt_atexit(hulk_exit_fn fn) {
    if (hulk_crt_exit_n_ >= sizeof(hulk_crt_exit_fns_) / sizeof(hulk_crt_exit_fns_[0]))
        return -1;
    hulk_crt_exit_fns_[hulk_crt_exit_n_++] = fn;
    return 0;
}

void HULK_HOST_CDECL hulk_crt_run_atexit(void) {
    while (hulk_crt_exit_n_)
        hulk_crt_exit_fns_[--hulk_crt_exit_n_]();
}

// ---------------------------------------------------------------------------------------------------------------
// stdio: the game names the Xbox CRT's stdin / stdout / stderr by address (the `_iob` array at XBE 0x004d99f0,
// 32 bytes per FILE). Those three words are this proxy; the FILE* functions below map it to the host's streams and
// pass every other stream (from fopen) through.
unsigned char hulk_crt_iob_proxy[96];

static hulk_host_file* hulk_stream(void* f) {
    unsigned char* p = (unsigned char*)f;
    if (p >= hulk_crt_iob_proxy && p < hulk_crt_iob_proxy + sizeof(hulk_crt_iob_proxy))
        return (hulk_host_file*)((unsigned char*)hulk_host___iob_func() + (p - hulk_crt_iob_proxy));
    return (hulk_host_file*)f;
}

static int hulk_starts(const char* s, const char* prefix) {
    while (*prefix) {
        char a = *s++, b = *prefix++;
        if (a >= 'A' && a <= 'Z')
            a += 'a' - 'A';
        if (a != b)
            return 0;
    }
    return 1;
}

// `D:\x\y` (the game disc: the extracted game files, HULK_DATA_DIR), `T:\` (title storage: HULK_TDATA_DIR, else
// HULK_SAVE_DIR) and `U:\` / `Z:\` (user / cache storage: HULK_SAVE_DIR) -> host paths; anything else is left alone (0).
char* hulk_crt_host_path(const char* p, char* buf, hulk_u32 size) {
    const char* root = 0;
    const char* rest = 0;
    if (hulk_starts(p, "d:\\") || hulk_starts(p, "d:/")) {
        root = hulk_host_getenv("HULK_DATA_DIR");
        rest = p + 3;
    } else if (hulk_starts(p, "t:\\") && (root = hulk_host_getenv("HULK_TDATA_DIR")) != 0 && *root) {
        rest = p + 3;      // title storage: a writable directory of its own (HULK_TDATA_DIR)
    } else if (hulk_starts(p, "t:\\") || hulk_starts(p, "u:\\") || hulk_starts(p, "z:\\")) {
        root = hulk_host_getenv("HULK_SAVE_DIR");
        rest = p + 3;
    } else if (p[0] == '\\' && !hulk_starts(p, "\\\\")) {
        root = hulk_host_getenv("HULK_DATA_DIR");
        rest = p + 1;
    }
    if (!root || !*root)
        return 0;
    int n = hulk_host__snprintf(buf, size, "%s\\%s", root, rest);
    if (n < 0 || (hulk_u32)n >= size)
        return 0;
    for (char* c = buf; *c; c++)
        if (*c == '/')
            *c = '\\';
    return buf;
}

// The game's malloc (0x003479aa and the tree's `malloc`): zero-filled. On the Xbox the game's allocations come from
// pages the kernel hands out zeroed (the heaps' arenas are allocated once at start-up, so they are fresh memory);
// the host's malloc returns recycled memory, and code that reads a field its constructor leaves (GameClock's
// elapsed time, the camera's position before its first update: both hashed by the replay checkpoints) saw the
// host's old bytes. docs/native-build.md native11.
void* HULK_HOST_CDECL hulk_crt_malloc(hulk_u32 size) {
    return hulk_host_calloc(1, size ? size : 1);
}

void* HULK_HOST_CDECL hulk_crt_fopen(const char* path, const char* mode) {
    char buf[520];
    const char* host = hulk_crt_host_path(path, buf, sizeof(buf));
    return hulk_host_fopen(host ? host : path, mode);
}

int HULK_HOST_CDECL hulk_crt_fclose(void* f) {
    hulk_host_file* h = hulk_stream(f);
    return h == (hulk_host_file*)f ? hulk_host_fclose(h) : 0;
}

hulk_u32 HULK_HOST_CDECL hulk_crt_fread(void* p, hulk_u32 size, hulk_u32 n, void* f) {
    return hulk_host_fread(p, size, n, hulk_stream(f));
}

hulk_u32 HULK_HOST_CDECL hulk_crt_fwrite(const void* p, hulk_u32 size, hulk_u32 n, void* f) {
    return hulk_host_fwrite(p, size, n, hulk_stream(f));
}

int HULK_HOST_CDECL hulk_crt_getc(void* f) { return hulk_host_getc(hulk_stream(f)); }
int HULK_HOST_CDECL hulk_crt_ungetc(int c, void* f) { return hulk_host_ungetc(c, hulk_stream(f)); }
char* HULK_HOST_CDECL hulk_crt_fgets(char* s, int n, void* f) { return hulk_host_fgets(s, n, hulk_stream(f)); }

int HULK_HOST_CDECL hulk_crt_fprintf(void* f, const char* fmt, ...) {
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    int r = hulk_host_vfprintf(hulk_stream(f), fmt, (char*)ap);
    __builtin_va_end(ap);
    return r;
}

// ---------------------------------------------------------------------------------------------------------------
// native15: the transcendental intrinsics as the original computes them (docs/native-float.md, "soft intrinsics").
// MSVC 7.1 (/Oi) inlined sin, cos, tan, atan and atan2 as the x87 instructions fsin, fcos, fptan, fpatan; the game's
// sources call the library functions, which msvcrt.dll implements with its own algorithms (1 ULP apart in a few
// percent of arguments). These run the instruction the original runs, at the game's precision control (53 bits).
// On x87 hardware that is the original's result; under an x87 emulator it is the emulator's (QEMU and Rosetta 2
// both compute fpatan with the host's atan2). A 64-bit build needs software versions instead.
#if defined(HULK_SOFT_X87)
// soft-intrinsics (docs/soft-x87.md): the same functions computed by softx87.cpp, integer arithmetic only, what real x87
// hardware returns. Selected with -DHULK_SOFT_X87=1 (tools/wine_host.py adds it when HULK_SOFT_X87=1 is in the
// environment, and then also binds the rest of the math table below to these).
#include "softx87.h"
#if defined(HULK_SOFT_X87_STATS)
// -DHULK_SOFT_X87_STATS=1 (HULK_SOFT_X87_STATS=1 in the Wine build's environment): the argument ranges the game really uses.
// One line appended to the file named by the environment variable HULK_SOFTX87_STATS (default softx87-stats.txt) at the 1st,
// 2nd, 4th ... call of each function and whenever an argument reaches a new exponent extreme: call count, smallest and
// largest argument as double bit patterns, and the number of non-finite / huge (|x| >= 2^63) arguments.
struct hulk_sx_stat {
    unsigned n, bad, diff;          // diff: calls whose double result differs from the x87 instruction the control build runs
    unsigned lo[2], hi[2];          // biased exponents of |arg|, per argument
    unsigned long long mn[2], mx[2];       // smallest / largest argument as ordered bit patterns (negative below positive)
    int neg[2];
};
static hulk_sx_stat hulk_sx_stats[16];
static unsigned long long hulk_sx_bits(double d) {
    unsigned long long b;
    hulk_host_memcpy(&b, &d, 8);
    return b;
}
static unsigned long long hulk_sx_order(unsigned long long b) { return (b >> 63) ? ~b : (b | (1ULL << 63)); }
static void hulk_sx_note(int k, const char* name, double a, double b, int nargs, double soft = 0.0, double ref = 0.0, int cmp = 0) {
    hulk_sx_stat& t = hulk_sx_stats[k];
    bool log = false;
    double args[2] = {a, b};
    if (t.n == 0)
        for (int i = 0; i < 2; i++) {
            t.lo[i] = 0xfff;
            t.hi[i] = 0;
            t.mn[i] = ~0ULL;
            t.mx[i] = 0;
        }
    t.n++;
    if (cmp && hulk_sx_bits(soft) != hulk_sx_bits(ref)) t.diff++;
    if ((t.n & (t.n - 1)) == 0) log = true;
    for (int i = 0; i < nargs; i++) {
        unsigned long long bits = hulk_sx_bits(args[i]);
        unsigned ex = (unsigned)((bits >> 52) & 0x7ff);
        if (ex == 0x7ff || ex >= 1023 + 63) t.bad++;
        if (ex < t.lo[i]) { t.lo[i] = ex; log = true; }
        if (ex > t.hi[i]) { t.hi[i] = ex; log = true; }
        unsigned long long o = hulk_sx_order(bits);
        if (o < t.mn[i]) t.mn[i] = o;
        if (o > t.mx[i]) t.mx[i] = o;
    }
    if (!log) return;
    const char* path = hulk_host_getenv("HULK_SOFTX87_STATS");
    hulk_host_file* f = hulk_host_fopen(path ? path : "softx87-stats.txt", "a");
    if (!f) return;
    char line[256];
    unsigned long long m0 = t.mn[0], x0 = t.mx[0], m1 = t.mn[1], x1 = t.mx[1];
    m0 = (m0 >> 63) ? (m0 & ~(1ULL << 63)) : ~m0; x0 = (x0 >> 63) ? (x0 & ~(1ULL << 63)) : ~x0;
    m1 = (m1 >> 63) ? (m1 & ~(1ULL << 63)) : ~m1; x1 = (x1 >> 63) ? (x1 & ~(1ULL << 63)) : ~x1;
    int len = hulk_host__snprintf(line, sizeof line, "%s n=%u bad=%u diff=%u a0=%08x%08x..%08x%08x a1=%08x%08x..%08x%08x\n", name, t.n,
                                  t.bad, t.diff, (unsigned)(m0 >> 32), (unsigned)m0, (unsigned)(x0 >> 32), (unsigned)x0,
                                  nargs > 1 ? (unsigned)(m1 >> 32) : 0, nargs > 1 ? (unsigned)m1 : 0,
                                  nargs > 1 ? (unsigned)(x1 >> 32) : 0, nargs > 1 ? (unsigned)x1 : 0);
    if (len > 0) hulk_host_fwrite(line, 1, (hulk_u32)len, f);
    hulk_host_fclose(f);
}
#if defined(__i386__) || defined(_M_IX86)
// the instruction the control build runs (the OFF glue below), for the diff counter; st(0) is stored to a double
static double hulk_ref_sin(double x) { double r; __asm__("fsin" : "=t"(r) : "0"(x)); return r; }
static double hulk_ref_cos(double x) { double r; __asm__("fcos" : "=t"(r) : "0"(x)); return r; }
static double hulk_ref_tan(double x) { double r; __asm__("fptan\n\tfstp %%st(0)" : "=t"(r) : "0"(x)); return r; }
static double hulk_ref_atan(double x) { double r; __asm__("fld1\n\tfpatan" : "=t"(r) : "0"(x)); return r; }
static double hulk_ref_atan2(double y, double x) { double r; __asm__("fpatan" : "=t"(r) : "0"(x), "u"(y) : "st(1)"); return r; }
static double hulk_ref_exp(double x) {
    double r;
    __asm__("fldl2e\n\tfmulp\n\tfld %%st(0)\n\tfrndint\n\tfxch %%st(1)\n\tfsub %%st(1), %%st\n\tf2xm1\n\tfld1\n\tfaddp\n\tfscale\n\tfstp %%st(1)"
            : "=t"(r) : "0"(x));
    return r;
}
// (the value compared is the one stored to a double: a double return is already stored, st(0) one is rounded here)
static double hulk_sx_dbl(double v) {
    volatile double d = v;
    return d;
}
#define HULK_SX1(k, name, expr, refexpr) { hulk_sx_note(k, name, x, 0.0, 1, hulk_sx_dbl(expr), (refexpr), 1); return expr; }
#define HULK_SX2(k, name, expr, refexpr) { hulk_sx_note(k, name, x, y, 2, hulk_sx_dbl(expr), (refexpr), 1); return expr; }
#else
#define HULK_SX1(k, name, expr, refexpr) hulk_sx_note(k, name, x, 0.0, 1); return expr
#define HULK_SX2(k, name, expr, refexpr) hulk_sx_note(k, name, x, y, 2); return expr
#endif
#define HULK_SXN1(k, name, expr) hulk_sx_note(k, name, x, 0.0, 1); return expr
#define HULK_SXN2(k, name, expr) hulk_sx_note(k, name, x, y, 2); return expr
#else
#define HULK_SX1(k, name, expr, refexpr) return expr
#define HULK_SX2(k, name, expr, refexpr) return expr
#define HULK_SXN1(k, name, expr) return expr
#define HULK_SXN2(k, name, expr) return expr
#endif
// The result as the original's code finds it: on i386 the 80-bit value left in st(0) (fldt does not round; the next arithmetic
// instruction rounds to the control word's precision, as it does after the real fsin). HULK_SOFT_X87=2 stores it to a double
// first; other targets return a double.
#if (defined(__i386__) || defined(_M_IX86)) && HULK_SOFT_X87 != 2
static inline double hulk_st0(hulk_x87_ext r) {
    double d;
    __asm__("fldt %1" : "=t"(d) : "m"(r));
    return d;
}
#else
static inline double hulk_st0(hulk_x87_ext r) { return hulk_x87_to_double(r); }
#endif
double HULK_HOST_CDECL hulk_crt_sin(double x) { HULK_SX1(0, "sin", hulk_st0(hulk_x87_sin_ext(x)), hulk_ref_sin(x)); }
double HULK_HOST_CDECL hulk_crt_cos(double x) { HULK_SX1(1, "cos", hulk_st0(hulk_x87_cos_ext(x)), hulk_ref_cos(x)); }
double HULK_HOST_CDECL hulk_crt_tan(double x) { HULK_SX1(2, "tan", hulk_st0(hulk_x87_tan_ext(x)), hulk_ref_tan(x)); }
double HULK_HOST_CDECL hulk_crt_atan(double x) { HULK_SX1(3, "atan", hulk_st0(hulk_x87_atan_ext(x)), hulk_ref_atan(x)); }
double HULK_HOST_CDECL hulk_crt_atan2(double y, double x) { HULK_SX2(4, "atan2(y,x)", hulk_st0(hulk_x87_atan2_ext(y, x)), hulk_ref_atan2(y, x)); }
double HULK_HOST_CDECL hulk_crt_exp(double x) { HULK_SX1(5, "exp", hulk_st0(hulk_x87_exp_ext(x)), hulk_ref_exp(x)); }
double HULK_HOST_CDECL hulk_crt_asin(double x) { HULK_SXN1(6, "asin", hulk_st0(hulk_x87_asin_ext(x))); }
double HULK_HOST_CDECL hulk_crt_acos(double x) { HULK_SXN1(7, "acos", hulk_st0(hulk_x87_acos_ext(x))); }
double HULK_HOST_CDECL hulk_crt_log(double x) { HULK_SXN1(8, "log", hulk_st0(hulk_x87_log_ext(x))); }
double HULK_HOST_CDECL hulk_crt_log10(double x) { HULK_SXN1(9, "log10", hulk_st0(hulk_x87_log10_ext(x))); }
double HULK_HOST_CDECL hulk_crt_pow(double x, double y) { HULK_SXN2(10, "pow(x,y)", hulk_st0(hulk_x87_pow_ext(x, y))); }
double HULK_HOST_CDECL hulk_crt_fmod(double x, double y) { HULK_SXN2(11, "fmod(x,y)", hulk_x87_fmod(x, y)); }
#if defined(__i386__) || defined(_M_IX86)
// The CRT's register-argument entry points (_CIpow, _CIfmod: x in st(1), y in st(0); _CIacos, _CIasin: x in st(0)),
// which both operands popped and the result in st(0): spill the operands, call the soft version, return its st(0).
__asm__(".text\n"
        ".globl _hulk_crt_CIpow\n_hulk_crt_CIpow:\n"
        "\tsubl $20, %esp\n\tfstpl 8(%esp)\n\tfstpl (%esp)\n\tcalll _hulk_crt_pow\n\taddl $20, %esp\n\tretl\n"
        ".globl _hulk_crt_CIfmod\n_hulk_crt_CIfmod:\n"
        "\tsubl $20, %esp\n\tfstpl 8(%esp)\n\tfstpl (%esp)\n\tcalll _hulk_crt_fmod\n\taddl $20, %esp\n\tretl\n"
        ".globl _hulk_crt_CIacos\n_hulk_crt_CIacos:\n"
        "\tsubl $12, %esp\n\tfstpl (%esp)\n\tcalll _hulk_crt_acos\n\taddl $12, %esp\n\tretl\n"
        ".globl _hulk_crt_CIasin\n_hulk_crt_CIasin:\n"
        "\tsubl $12, %esp\n\tfstpl (%esp)\n\tcalll _hulk_crt_asin\n\taddl $12, %esp\n\tretl\n");
#endif
#elif defined(__i386__) || defined(_M_IX86)
double HULK_HOST_CDECL hulk_crt_sin(double x) {
    double r;
    __asm__("fsin" : "=t"(r) : "0"(x));
    return r;
}
double HULK_HOST_CDECL hulk_crt_cos(double x) {
    double r;
    __asm__("fcos" : "=t"(r) : "0"(x));
    return r;
}
double HULK_HOST_CDECL hulk_crt_tan(double x) {
    double r;
    __asm__("fptan\n\tfstp %%st(0)" : "=t"(r) : "0"(x));  // fptan pushes 1.0 after tan(x)
    return r;
}
double HULK_HOST_CDECL hulk_crt_atan(double x) {
    double r;
    __asm__("fld1\n\tfpatan" : "=t"(r) : "0"(x));  // atan(x / 1)
    return r;
}
double HULK_HOST_CDECL hulk_crt_atan2(double y, double x) {
    double r;
    __asm__("fpatan" : "=t"(r) : "0"(x), "u"(y) : "st(1)");  // atan(st1 / st0), pops
    return r;
}
// exp: MSVC 7.1's inline sequence (the game's only exp: fldl2e, frndint, f2xm1, fscale; 8 functions)
double HULK_HOST_CDECL hulk_crt_exp(double x) {
    double r;
    __asm__("fldl2e\n\tfmulp\n\tfld %%st(0)\n\tfrndint\n\tfxch %%st(1)\n\tfsub %%st(1), %%st\n\tf2xm1\n\t"
            "fld1\n\tfaddp\n\tfscale\n\tfstp %%st(1)"
            : "=t"(r) : "0"(x));
    return r;
}
#else
double HULK_HOST_CDECL hulk_host_sin(double);
double HULK_HOST_CDECL hulk_host_cos(double);
double HULK_HOST_CDECL hulk_host_tan(double);
double HULK_HOST_CDECL hulk_host_atan(double);
double HULK_HOST_CDECL hulk_host_atan2(double, double);
double HULK_HOST_CDECL hulk_host_exp(double);
double HULK_HOST_CDECL hulk_crt_sin(double x) { return hulk_host_sin(x); }
double HULK_HOST_CDECL hulk_crt_cos(double x) { return hulk_host_cos(x); }
double HULK_HOST_CDECL hulk_crt_tan(double x) { return hulk_host_tan(x); }
double HULK_HOST_CDECL hulk_crt_atan(double x) { return hulk_host_atan(x); }
double HULK_HOST_CDECL hulk_crt_atan2(double y, double x) { return hulk_host_atan2(y, x); }
double HULK_HOST_CDECL hulk_crt_exp(double x) { return hulk_host_exp(x); }
#endif

}  // extern "C"

// ---------------------------------------------------------------------------------------------------------------
// C++ runtime pieces msvcrt.dll doesn't export. (type_info's vftable, which clang's RTTI descriptors and the game's,
// XBE 0x00439de8, point at, is in tools/native_link.py's startup.s: one slot, a deleting destructor that deletes
// nothing, since nothing deletes a type descriptor.)
// The sized delete clang calls (-fsized-deallocation, C++14) is the game's own operator delete: MSVC 7.1 had none.
void operator delete(void* p) noexcept;
void operator delete(void* p, unsigned int) noexcept { ::operator delete(p); }
