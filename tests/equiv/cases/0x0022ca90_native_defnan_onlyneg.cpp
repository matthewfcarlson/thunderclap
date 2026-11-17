// STATUS: must fail (tools/equiv.py --wine): D65's first defnan test, which allowed only 0xffc00000 (integ2, D85)
// 0x7fc00000 (arm64's default NaN, the negation of 0xffc00000) is inside the contract: a macro that traps on it
// fails the allowed-NaN word check.
#include "compat/pre.h"
#if defined(__clang__)
#undef HULK_PRE_DEFNAN_N
static inline void d65_defnan_n(const void* p, int n) {
    for (int i = 0; i < n; ++i) { unsigned u; __builtin_memcpy(&u, (const char*)p + 4 * i, 4);
        if ((u & 0x7fffffffu) > 0x7f800000u && u != 0xffc00000u) __builtin_trap(); }
}
#define HULK_PRE_DEFNAN_N(p, n) d65_defnan_n((p), (n))
#endif
struct Matrix_22ca90 { float m[4][4]; void FUN_0022ca90(const Matrix_22ca90* a, const Matrix_22ca90* b); };

// pre: defnan(*arg1+0x0..0x40) defnan(*arg2+0x0..0x40)
void Matrix_22ca90::FUN_0022ca90(const Matrix_22ca90* a, const Matrix_22ca90* b) {
 HULK_PRE_DEFNAN_N(&a->m[0][0], 16);
 HULK_PRE_DEFNAN_N(&b->m[0][0], 16);
 Matrix_22ca90 r;
 r.m[0][0]=(a->m[0][0]*b->m[0][0]+a->m[0][2]*b->m[2][0])+b->m[1][0]*a->m[0][1];
 r.m[0][1]=(b->m[0][1]*a->m[0][0]+a->m[0][2]*b->m[2][1])+b->m[1][1]*a->m[0][1];
 r.m[0][2]=(b->m[2][2]*a->m[0][2]+b->m[1][2]*a->m[0][1])+a->m[0][0]*b->m[0][2];
 r.m[0][3]=0.0f;
 r.m[1][0]=(a->m[1][0]*b->m[0][0]+a->m[1][2]*b->m[2][0])+a->m[1][1]*b->m[1][0];
 r.m[1][1]=(a->m[1][2]*b->m[2][1]+a->m[1][1]*b->m[1][1])+b->m[0][1]*a->m[1][0];
 r.m[1][2]=(a->m[1][1]*b->m[1][2]+a->m[1][0]*b->m[0][2])+a->m[1][2]*b->m[2][2];
 r.m[1][3]=0.0f;
 r.m[2][0]=(a->m[2][2]*b->m[2][0]+b->m[1][0]*a->m[2][1])+a->m[2][0]*b->m[0][0];
 r.m[2][1]=(a->m[2][2]*b->m[2][1]+b->m[0][1]*a->m[2][0])+b->m[1][1]*a->m[2][1];
 r.m[2][2]=(b->m[1][2]*a->m[2][1]+a->m[2][0]*b->m[0][2])+a->m[2][2]*b->m[2][2];
 r.m[2][3]=0.0f;
 r.m[3][0]=((a->m[3][1]*b->m[1][0]+a->m[3][0]*b->m[0][0])+a->m[3][2]*b->m[2][0])+b->m[3][0];
 r.m[3][1]=((a->m[3][1]*b->m[1][1]+a->m[3][0]*b->m[0][1])+a->m[3][2]*b->m[2][1])+b->m[3][1];
 r.m[3][2]=((a->m[3][0]*b->m[0][2]+b->m[2][2]*a->m[3][2])+b->m[1][2]*a->m[3][1])+b->m[3][2];
 r.m[3][3]=1.0f;
 *this=r;
}
