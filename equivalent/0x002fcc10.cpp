// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fcc10 @ 0x002fcc10
struct Matrix { int tag; float m11,m12,m13,m22,m23,m33; void FUN_002fcc10(const Matrix* a,const Matrix* b); };
void Matrix::FUN_002fcc10(const Matrix* a,const Matrix* b) {
    volatile float middle = a->m12*b->m12;
    double p13 = (double)b->m13*a->m13;
    double p23 = (double)b->m23*a->m23;
    float r11 = (float)(((double)a->m11*b->m11 + middle) + p13);
    float r12 = (float)(((double)a->m11*b->m12 + (double)b->m23*a->m13) + (double)a->m12*b->m22);
    float r13 = (float)(((double)b->m33*a->m13 + (double)a->m12*b->m23) + (double)a->m11*b->m13);
    float r22 = (float)(((double)b->m22*a->m22 + p23) + middle);
    float r23 = (float)(((double)b->m23*a->m22 + (double)a->m23*b->m33) + (double)a->m12*b->m13);
    float r33 = (float)(((double)a->m33*b->m33 + p23) + p13);
    m13=r13; m22=r22; m23=r23; m33=r33; m11=r11; m12=r12;
}