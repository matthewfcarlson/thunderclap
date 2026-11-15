// Preconditions of a function's inputs (integ1, D54; docs/equivalence.md "Preconditions").
//
// HULK_PRE_NOTNAN(x): the float (or double) x is not a NaN on entry. The original never checked it; where the MSVC 7.1
// code and the x87/SSE builds would hand on a different NaN (x87 keeps the larger significand when two NaNs meet,
// SSE the first operand), the input is outside the function's contract.
//   - MSVC 7.1 (the byte-matched / proven 32-bit build): nothing, so the object code and its proofs are unchanged.
//   - clang (the Wine build and the native builds): a NaN traps. hulk_pre_fail stores the function and the violated
//     condition where a debugger or a crash dump shows them, then executes a trap instruction: the run stops with a
//     backtrace at the call that broke the contract instead of computing on.
// A block that uses it carries the matching `// pre: notnan(...)` annotation (tools/equiv.py honours it: inputs that
// violate it are repaired on both sides, and in --wine mode a violating input must hit the trap).
// Include this header in the TU that uses it (not from common.h: MSVC 7.1's code for some functions depends on how
// many declarations precede them, docs/merge-once.md hash3; this header declares nothing under MSVC).
#ifndef HULK_COMPAT_PRE_H
#define HULK_COMPAT_PRE_H

#if defined(__clang__)
// (static inline, emitted only in a TU that calls it: no external symbol to bind, no change to other objects)
static inline __attribute__((noreturn, cold, noinline)) void hulk_pre_fail(const char* fn, const char* what) {
    static const char* volatile s_fn;
    static const char* volatile s_what;
    s_fn = fn;      // (the function whose precondition failed and the condition: visible in the backtrace's
    s_what = what;  //  arguments and in these two words of a crash dump)
    __builtin_trap();
}
#define HULK_PRE_NOTNAN(x) (__builtin_isnan(x) ? hulk_pre_fail(__func__, "notnan(" #x ")") : (void)0)
#else
#define HULK_PRE_NOTNAN(x) ((void)0)
#endif

#endif
