// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002c5c90 @ 0x002c5c90
struct Src {
    char pad00[0x14];
    int f14;
    float p[3];
};

void FUN_002c5260(float width, float* from, float w2, float* to, int a, int b, int c, int d);

struct Obj {
    int w0, w4, w8, wc;
    void FUN_002c5c90(Src* s, float f);
};

void Obj::FUN_002c5c90(Src* s, float f)
{
    struct Frame {
        float p0copy;
        float p1copy;
        float neg;
        int oldw8;
        int oldwc;
        float X[3];
        float T[3];
    } fr;
    fr.oldw8 = w8;
    fr.oldwc = wc;
    w4 = s->f14;
    w8 = 0x40000000;
    wc = 0x40000000;
    fr.X[0] = s->p[0];
    fr.X[1] = s->p[1];
    fr.X[2] = s->p[2];
    fr.p1copy = fr.X[1];
    fr.T[0] = fr.X[0] + (f * 0.25f);
    fr.T[1] = fr.p1copy;
    fr.T[2] = fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.neg = -(f * 0.25f);
    fr.T[0] = fr.neg + fr.X[0];
    fr.T[1] = fr.p1copy;
    fr.T[2] = fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.p0copy = fr.X[0];
    fr.T[0] = fr.X[0];
    fr.T[1] = fr.X[1] + (f * 0.25f);
    fr.T[2] = fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.T[0] = fr.p0copy;
    fr.T[1] = fr.neg + fr.X[1];
    fr.T[2] = fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.T[0] = fr.p0copy;
    fr.T[1] = fr.p1copy;
    fr.T[2] = fr.X[2] + (f * 0.25f);
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.T[0] = fr.p0copy;
    fr.T[1] = fr.p1copy;
    fr.T[2] = fr.neg + fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    w8 = fr.oldw8;
    wc = fr.oldwc;
}
