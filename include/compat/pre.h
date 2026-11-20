// Preconditions of a function's inputs (integ1, D54; docs/equivalence.md "Preconditions").
//
// HULK_PRE_NOTNAN(x): the float (or double) x is not a NaN on entry. HULK_PRE_NOTNAN_N(p, n): none of the n floats at p
// is (one statement, no loop in the source: a loop changes MSVC 7.1's code even with an empty body). The original never
// checked them; where the MSVC 7.1 code and the x87/SSE builds would hand on a different NaN (x87 keeps the larger
// significand when two NaNs meet, SSE the first operand), the input is outside the function's contract.
//   - MSVC 7.1 (the byte-matched / proven 32-bit build): nothing, so the object code and its proofs are unchanged (an
//     adopting edit shows its block's @msvc hash unchanged).
//   - clang (the Wine build and the native builds): a NaN traps. hulk_pre_fail writes "hulk: precondition failed:
//     <function>: <condition>" to stderr (fd 2, a raw write system call on the 64-bit Linux / Android / macOS builds: no
//     library call; the Wine build has none and only traps), keeps the two strings where a debugger or a crash dump shows
//     them, and executes a trap instruction: the run stops with a backtrace where the contract broke.
// HULK_PRE_DEFNAN(x) / HULK_PRE_DEFNAN_N(p, n) (integ2, D65; D85): any NaN among them is the zero-payload quiet NaN of
// either sign: 0xffc00000 (the x87 indefinite, SSE's default NaN) or 0x7fc00000 (arm64's default NaN, and the
// negation of 0xffc00000). The game does pass the default NaN (play3 frame 37080: a matrix whose rotation is all
// 0xffc00000 reaches FUN_0022ca90); with these NaNs the only ones, x87 and SSE hand on the same bits up to the sign
// (IEEE leaves a NaN's sign unspecified). Only another NaN traps; the test is on the bits (no float load).
// A block that uses them carries the matching `// pre: notnan(...)` / `// pre: defnan(...)` annotation, and an annotation needs them
// (tools/equiv.py refuses either without the other; it repairs violating inputs and checks the trap per contract word).
// Include this header in the TU that uses it (not from common.h: MSVC 7.1's code for some functions depends on how
// many declarations precede them, docs/merge-once.md hash3; this header declares nothing under MSVC).
#ifndef HULK_COMPAT_PRE_H
#define HULK_COMPAT_PRE_H

#if defined(__clang__)
// (static inline, emitted only in a TU that calls them: no external symbol to bind, no change to other objects)
static inline void hulk_pre_write2(const char* s) {
    unsigned long n = 0;
    while (s[n])
        ++n;
#if defined(__x86_64__) && defined(__linux__)
    long r;
    __asm__ volatile("syscall" : "=a"(r) : "a"(1L), "D"(2L), "S"(s), "d"(n) : "rcx", "r11", "memory");
#elif defined(__aarch64__) && (defined(__linux__) || defined(__APPLE__))
    register long x0 __asm__("x0") = 2;
    register const char* x1 __asm__("x1") = s;
    register unsigned long x2 __asm__("x2") = n;
#if defined(__APPLE__)
    register long nr __asm__("x16") = 4;     // SYS_write
    __asm__ volatile("svc #0x80" : "+r"(x0) : "r"(x1), "r"(x2), "r"(nr) : "memory", "cc");
#else
    register long nr __asm__("x8") = 64;     // __NR_write
    __asm__ volatile("svc #0" : "+r"(x0) : "r"(x1), "r"(x2), "r"(nr) : "memory", "cc");
#endif
#else
    (void)s;
    (void)n;
#endif
}
static inline __attribute__((noreturn, cold, noinline)) void hulk_pre_fail(const char* fn, const char* what) {
    static const char* volatile s_fn;
    static const char* volatile s_what;
    s_fn = fn;      // (the function whose precondition failed and the condition: visible in the backtrace's
    s_what = what;  //  arguments and in these two words of a crash dump)
    hulk_pre_write2("hulk: precondition failed: ");
    hulk_pre_write2(fn);
    hulk_pre_write2(": ");
    hulk_pre_write2(what);
    hulk_pre_write2("\n");
    __builtin_trap();
}
// (integ3, D152) range contracts. HULK_CONTRACTS: 2 trap (the default, and always in the Wine build and native release
// builds), 1 log (development only: report and go on), 0 off (development only). A run built with another value than
// 2 proves nothing.
#ifndef HULK_CONTRACTS
#define HULK_CONTRACTS 2
#endif
static inline void hulk_pre_hex(unsigned long long v, int digits) {
    char b[20];
    int i = 0;
    b[i++] = '0';
    b[i++] = 'x';
    for (int d = digits - 1; d >= 0; --d)
        b[i++] = "0123456789abcdef"[(v >> (4 * d)) & 15];
    b[i] = 0;
    hulk_pre_write2(b);
}
static inline __attribute__((cold, noinline)) void hulk_pre_fail_bits(const char* fn, const char* what,
                                                                       unsigned long long bits, int digits) {
    hulk_pre_write2("hulk: contract failed: ");
    hulk_pre_write2(fn);
    hulk_pre_write2(": ");
    hulk_pre_write2(what);
    hulk_pre_write2(" (value ");
    hulk_pre_hex(bits, digits);
    hulk_pre_write2(")\n");
#if HULK_CONTRACTS >= 2
    static const char* volatile s_fn;
    static const char* volatile s_what;
    s_fn = fn;      // (as hulk_pre_fail: in the backtrace and a crash dump)
    s_what = what;
    __builtin_trap();
#endif
}
// (rev5) the value's bits at its own width, whatever its type (long under LLP64, short, char, bool, enums, floats)
template <class T> static inline unsigned long long hulk_pre_bits(T x) {
    unsigned long long u = 0;
    __builtin_memcpy(&u, &x, sizeof(T) < 8 ? sizeof(T) : 8);
    return u;
}
#define HULK_PRE_BITS_(x) hulk_pre_bits(x)
#define HULK_PRE_DIG_(x) ((int)(2 * sizeof(x)))
#if HULK_CONTRACTS >= 1
// (the conditions are written so a NaN fails every one of them: `x >= lo && x <= hi` is false for a NaN)
#define HULK_PRE_IF_(ok, x, what) ((ok) ? (void)0 : hulk_pre_fail_bits(__func__, what, HULK_PRE_BITS_(x), HULK_PRE_DIG_(x)))
#else
#define HULK_PRE_IF_(ok, x, what) ((void)0)
#endif
#define HULK_PRE_RANGE(x, lo, hi) HULK_PRE_IF_((x) >= (lo) && (x) <= (hi), x, "range(" #x ", " #lo ", " #hi ")")
#define HULK_PRE_GT(x, c) HULK_PRE_IF_((x) > (c), x, "gt(" #x ", " #c ")")
#define HULK_PRE_GE(x, c) HULK_PRE_IF_((x) >= (c), x, "ge(" #x ", " #c ")")
#define HULK_PRE_LT(x, c) HULK_PRE_IF_((x) < (c), x, "lt(" #x ", " #c ")")
#define HULK_PRE_LE(x, c) HULK_PRE_IF_((x) <= (c), x, "le(" #x ", " #c ")")
// (integ4, post) postconditions: the same checks, written right before the return they describe (`*out = i;
// HULK_POST_LT(*out, count); return true;`); the block's `// post: ... when ret` items name them (tools/equiv64.py)
#define HULK_POST_GE(x, c) HULK_PRE_IF_((x) >= (c), x, "post ge(" #x ", " #c ")")
#define HULK_POST_GT(x, c) HULK_PRE_IF_((x) > (c), x, "post gt(" #x ", " #c ")")
#define HULK_POST_LT(x, c) HULK_PRE_IF_((x) < (c), x, "post lt(" #x ", " #c ")")
#define HULK_POST_LE(x, c) HULK_PRE_IF_((x) <= (c), x, "post le(" #x ", " #c ")")
// (not for a proven block: tools/equiv.py can't read an arbitrary condition and refuses it there)
#define HULK_PRE(cond) HULK_PRE_IF_((cond), 0, "pre(" #cond ")")
static inline void hulk_pre_notnan_n(const float* p, int n, const char* fn, const char* what) {
    for (int i = 0; i < n; ++i)
        if (__builtin_isnan(p[i]))
            hulk_pre_fail(fn, what);
}
static inline int hulk_pre_otherNaN(unsigned int u) {
    return (u & 0x7fffffffu) > 0x7f800000u && (u & 0x7fffffffu) != 0x7fc00000u;
}
static inline void hulk_pre_defnan_n(const void* p, int n, const char* fn, const char* what) {
    for (int i = 0; i < n; ++i) {
        unsigned int u;
        __builtin_memcpy(&u, (const char*)p + 4 * i, 4);
        if (hulk_pre_otherNaN(u))
            hulk_pre_fail(fn, what);
    }
}
static inline void hulk_pre_defnan1(float x, const char* fn, const char* what) {
    unsigned int u;
    __builtin_memcpy(&u, &x, 4);
    if (hulk_pre_otherNaN(u))
        hulk_pre_fail(fn, what);
}
#define HULK_PRE_NOTNAN(x) (__builtin_isnan(x) ? hulk_pre_fail(__func__, "notnan(" #x ")") : (void)0)
#define HULK_PRE_NOTNAN_N(p, n) hulk_pre_notnan_n((const float*)(p), (n), __func__, "notnan(" #p "[0.." #n "])")
#define HULK_PRE_DEFNAN(x) hulk_pre_defnan1((x), __func__, "defnan(" #x ")")
#define HULK_PRE_DEFNAN_N(p, n) hulk_pre_defnan_n((const void*)(p), (n), __func__, "defnan(" #p "[0.." #n "])")
#else
#define HULK_PRE_RANGE(x, lo, hi) ((void)0)
#define HULK_PRE_GT(x, c) ((void)0)
#define HULK_PRE_GE(x, c) ((void)0)
#define HULK_PRE_LT(x, c) ((void)0)
#define HULK_PRE_LE(x, c) ((void)0)
#define HULK_POST_GE(x, c) ((void)0)
#define HULK_POST_GT(x, c) ((void)0)
#define HULK_POST_LT(x, c) ((void)0)
#define HULK_POST_LE(x, c) ((void)0)
#define HULK_PRE(cond) ((void)0)
#define HULK_PRE_NOTNAN(x) ((void)0)
#define HULK_PRE_NOTNAN_N(p, n) ((void)0)
#define HULK_PRE_DEFNAN(x) ((void)0)
#define HULK_PRE_DEFNAN_N(p, n) ((void)0)
#endif

#endif
