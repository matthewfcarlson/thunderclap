// STATUS: must fail (rev5 pairnan: the branch needs several default NaNs at once) (tools/equiv.py --wine): ours computes otherwise on the default NaN (integ2, D65)
// r.m[0][3] is 1.0 where a->m[0][0] is a NaN (the original stores 0.0 always): the default NaN is inside the
// contract, so this is a difference (the per-word default-NaN check and the planted inputs find it).
#include "compat/pre.h"
struct Matrix_22ca90 { float m[4][4]; void FUN_0022ca90(const Matrix_22ca90* a, const Matrix_22ca90* b); };

// pre: defnan(*arg1+0x0..0x40) defnan(*arg2+0x0..0x40)
void Matrix_22ca90::FUN_0022ca90(const Matrix_22ca90* a, const Matrix_22ca90* b) {
 HULK_PRE_DEFNAN_N(&a->m[0][0], 16);
 HULK_PRE_DEFNAN_N(&b->m[0][0], 16);
 Matrix_22ca90 r;
 r.m[0][0]=(a->m[0][0]*b->m[0][0]+a->m[0][2]*b->m[2][0])+b->m[1][0]*a->m[0][1];
 r.m[0][1]=(b->m[0][1]*a->m[0][0]+a->m[0][2]*b->m[2][1])+b->m[1][1]*a->m[0][1];
 r.m[0][2]=(b->m[2][2]*a->m[0][2]+b->m[1][2]*a->m[0][1])+a->m[0][0]*b->m[0][2];
 r.m[0][3]=(a->m[0][0]!=a->m[0][0] && b->m[1][1]!=b->m[1][1])?1.0f:0.0f;
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
