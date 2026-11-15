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
// A block that uses them carries the matching `// pre: notnan(...)` annotation, and an annotation needs them
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
static inline void hulk_pre_notnan_n(const float* p, int n, const char* fn, const char* what) {
    for (int i = 0; i < n; ++i)
        if (__builtin_isnan(p[i]))
            hulk_pre_fail(fn, what);
}
#define HULK_PRE_NOTNAN(x) (__builtin_isnan(x) ? hulk_pre_fail(__func__, "notnan(" #x ")") : (void)0)
#define HULK_PRE_NOTNAN_N(p, n) hulk_pre_notnan_n((const float*)(p), (n), __func__, "notnan(" #p "[0.." #n "])")
#else
#define HULK_PRE_NOTNAN(x) ((void)0)
#define HULK_PRE_NOTNAN_N(p, n) ((void)0)
#endif

#endif
