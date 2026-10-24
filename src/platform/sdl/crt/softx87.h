// softx87: the x87 transcendental and special instructions as portable integer-only C++ (no host FPU, no libm, no
// long double). They compute what Intel x87 hardware returns: operands and results are 80-bit extended values
// (64-bit mantissa), the results of the transcendental instructions are rounded once to nearest-even at 64 bits
// (precision control does not apply to them on real hardware), fsin/fcos/fptan reduce their argument with the
// FPU's 66-bit approximation of pi (so they differ from a correctly rounded sin/cos for large arguments exactly as the
// hardware does: fsin of the double nearest pi is 1.2246063538223773e-16, not 1.2246467991473532e-16). Documentation:
// docs/soft-x87.md.
//
// Rounding control is always round-to-nearest-even and all exceptions are masked (the game's control word, 0x027F, apart
// from the precision field). Nothing here reads or writes the host's x87/SSE/NEON state.
#ifndef HULK_SOFTX87_H
#define HULK_SOFTX87_H

#ifdef __cplusplus
extern "C" {
#endif

// An 80-bit extended value as the FPU stores it: m has the explicit integer bit (bit 63); se is sign (bit 15) and
// the biased exponent (bits 0-14, bias 16383).
typedef struct hulk_x87_ext {
    unsigned long long m;
    unsigned short se;
} hulk_x87_ext;

// ---- conversions ----------------------------------------------------------------------------------------------
hulk_x87_ext hulk_x87_from_double(double x);   // exact
hulk_x87_ext hulk_x87_from_float(float x);     // exact
double hulk_x87_to_double(hulk_x87_ext x);     // fstp qword: round to nearest even (denormals, overflow to inf)
float hulk_x87_to_float(hulk_x87_ext x);       // fstp dword
hulk_x87_ext hulk_x87_round_pc(hulk_x87_ext x, int pc_bits);   // what an arithmetic result gets at PC = 24, 53 or 64

// ---- the instructions (operands in ST order as the manual names them) -----------------------------------------------
// Each returns the C2 flag (1 = operand out of range, |x| >= 2^63, *out is the operand unchanged).
int hulk_x87_fsin(hulk_x87_ext x, hulk_x87_ext* out);
int hulk_x87_fcos(hulk_x87_ext x, hulk_x87_ext* out);
int hulk_x87_fsincos(hulk_x87_ext x, hulk_x87_ext* sin_out, hulk_x87_ext* cos_out);
int hulk_x87_fptan(hulk_x87_ext x, hulk_x87_ext* tan_out);        // (the instruction then pushes 1.0)
hulk_x87_ext hulk_x87_fpatan(hulk_x87_ext st1, hulk_x87_ext st0);   // atan(st1 / st0) in the right quadrant
hulk_x87_ext hulk_x87_f2xm1(hulk_x87_ext x);                      // 2^x - 1
hulk_x87_ext hulk_x87_fyl2x(hulk_x87_ext x /*st0*/, hulk_x87_ext y /*st1*/);     // y * log2(x)
hulk_x87_ext hulk_x87_fyl2xp1(hulk_x87_ext x /*st0*/, hulk_x87_ext y /*st1*/);   // y * log2(x + 1)
hulk_x87_ext hulk_x87_fscale(hulk_x87_ext st0, hulk_x87_ext st1);  // st0 * 2^trunc(st1)
hulk_x87_ext hulk_x87_frndint(hulk_x87_ext x);                    // round to nearest even
// fprem / fprem1: *rem = st0 REM st1 (partial for large exponent differences). Returns C2; *q gets Q (low bits valid
// when C2 = 0): C0 = q bit 2, C3 = q bit 1, C1 = q bit 0.
int hulk_x87_fprem(hulk_x87_ext* rem, hulk_x87_ext st1, unsigned long long* q);
int hulk_x87_fprem1(hulk_x87_ext* rem, hulk_x87_ext st1, unsigned long long* q);
hulk_x87_ext hulk_x87_fsqrt(hulk_x87_ext x, int pc_bits);          // correctly rounded at pc_bits (24/53/64)
hulk_x87_ext hulk_x87_fmul(hulk_x87_ext a, hulk_x87_ext b, int pc_bits);
hulk_x87_ext hulk_x87_fadd(hulk_x87_ext a, hulk_x87_ext b, int pc_bits);
hulk_x87_ext hulk_x87_fsub(hulk_x87_ext a, hulk_x87_ext b, int pc_bits);   // a - b

// ---- the C library functions the game's sources call, in terms of the instructions MSVC 7.1 inlined -----------------------
// Result: the 80-bit instruction result stored to a double (one rounding), i.e. what the original's code sees at the
// game's 53-bit precision control. Arguments that make the instruction set C2 return the argument unchanged.
double hulk_x87_sin(double x);
double hulk_x87_cos(double x);
double hulk_x87_tan(double x);
double hulk_x87_atan(double x);
double hulk_x87_atan2(double y, double x);
double hulk_x87_exp(double x);            // MSVC 7.1's inline sequence (fldl2e; fmul; frndint; fsub; f2xm1; fld1; fadd; fscale), PC 53
double hulk_x87_log(double x);            // fldln2; fxch; fyl2x
double hulk_x87_log10(double x);          // fldlg2; fxch; fyl2x
double hulk_x87_pow(double x, double y);  // fyl2x, frndint/fsub, f2xm1, fscale (the usual x87 sequence; unverified against the CRT's)
double hulk_x87_asin(double x);
double hulk_x87_acos(double x);
double hulk_x87_fmod(double x, double y); // fprem loop (exact)
double hulk_x87_sqrt(double x);           // correctly rounded (== SSE2 sqrtsd / x87 fsqrt at PC 53)
// The same without the final store to double: the 80-bit value the original's code finds in st(0) and goes on to compute with.
hulk_x87_ext hulk_x87_sin_ext(double x);
hulk_x87_ext hulk_x87_cos_ext(double x);
hulk_x87_ext hulk_x87_tan_ext(double x);
hulk_x87_ext hulk_x87_atan_ext(double x);
hulk_x87_ext hulk_x87_atan2_ext(double y, double x);
hulk_x87_ext hulk_x87_exp_ext(double x);
hulk_x87_ext hulk_x87_log_ext(double x);
hulk_x87_ext hulk_x87_log10_ext(double x);
hulk_x87_ext hulk_x87_pow_ext(double x, double y);
hulk_x87_ext hulk_x87_asin_ext(double x);
hulk_x87_ext hulk_x87_acos_ext(double x);

#ifdef __cplusplus
}
#endif
#endif
