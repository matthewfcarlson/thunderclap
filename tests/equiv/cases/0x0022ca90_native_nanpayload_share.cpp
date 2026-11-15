// STATUS: must fail, also with EQUIV_ON=nanpayload (tools/equiv.py --wine level 3)
// (integ1, rev3 review of D39) deliberately wrong: every NaN element of the product is replaced by another quiet NaN
// (a payload bit flipped). With a07ba065a's rule 32 of 87 inputs were nan_payload and it passed; now each element reaches
// *this through clang's struct copy (integer words, no float store), so the rule never applies and it fails. (Where the
// rule does apply, a share over 10% of the inputs run makes the run not promotable.)
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
 for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) if (r.m[i][j] != r.m[i][j]) { union { float f; unsigned u; } c_; c_.f = r.m[i][j]; c_.u ^= 1; r.m[i][j] = c_.f; }   // WRONG: every NaN element gets another payload
 *this=r;
}
