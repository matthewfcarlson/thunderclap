// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_002c6900 @ 0x002c6900
struct Src_2c6900 {
    char pad00[0x14];
    int f14;
    float p[3];
    char pad24[0x58 - 0x24];
    float v[3];
};

void FUN_002c5260(float width, float* from, float w2, float* to, int a, int b, int c, int d);

struct Obj_2c6900 {
    int w0, w4, w8, wc;
    void FUN_002c6900(Src_2c6900* s, float f);
};

void Obj_2c6900::FUN_002c6900(Src_2c6900* s, float f)
{
    double k = f * -0.65f; // kept in a register, unrounded
    w4 = s->f14;
    float sx = s->v[0], sy = s->v[1], sz = s->v[2];
    struct Frame { float A[3]; float t[3]; float S[3]; float B[3]; } fr;
    float* t = fr.t;
    float* A = fr.A;
    float* B = fr.B;
    fr.S[0] = sx; fr.S[1] = sy; fr.S[2] = sz;
    t[0] = sx * k + s->p[0];
    t[1] = sy * k + s->p[1];
    t[2] = sz * k + s->p[2];
    A[0] = t[0];
    A[1] = t[1];
    A[2] = t[2];
    A[0] = sx * f + A[0];
    A[1] = sy * f + A[1];
    A[2] = sz * f + A[2];
    B[0] = A[0];
    B[1] = A[1];
    B[2] = A[2];
    double m = f * 0.3f;
    B[0] = sx * m + B[0];
    B[1] = sy * m + B[1];
    B[2] = sz * m + B[2];
    float g = f * 0.05f;
    FUN_002c5260(g, t, g, A, w0, s->f14, w8, wc);
    FUN_002c5260(f * 0.15f, A, 0.0f, B, w0, w4, w8, wc);
}
