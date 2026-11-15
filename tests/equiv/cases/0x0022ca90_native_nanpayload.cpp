// STATUS: fails, also with EQUIV_ON=nanpayload (tools/equiv.py --wine level 3)
// (integ1, D39 nanpayload; not adopted) a 4x4 matrix product with the original's operand order: on an input where two
// NaNs meet, the x87 hands on the larger significand and SSE the first operand, so this+0x4 gets another quiet NaN
// (input 938: 0xfff84ab4, expected 0xffeca8b1). a07ba065a's rule set that input aside; after rev3's review the rule takes
// only words both sides last stored with a 4-byte float store, and clang copies r into *this as integer words, so the
// rule does not apply and the case fails with it on too (it documents the restriction, not a pass).
struct Matrix_22ca90 { float m[4][4]; void FUN_0022ca90(const Matrix_22ca90* a, const Matrix_22ca90* b); };

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
