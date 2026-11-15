// STATUS: must fail (tools/equiv.py level 2): the contract without the trap (integ1, D54)
// `// pre:` stays, HULK_PRE_NOTNAN is gone: the builds would compute on where the proof assumed the contract.
#include "compat/pre.h"
struct Matrix_22ca90 { float m[4][4]; void FUN_0022ca90(const Matrix_22ca90* a, const Matrix_22ca90* b); };

// pre: notnan(*arg1+0x0..0x40) notnan(*arg2+0x0..0x40)
void Matrix_22ca90::FUN_0022ca90(const Matrix_22ca90* a, const Matrix_22ca90* b) {
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
