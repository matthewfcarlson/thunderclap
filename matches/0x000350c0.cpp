#include "compat/ptr.h"
struct Y_350c0 {
    char p0[0x14];
    int kind;
    char p1[0x18];
    float f30;
    float f34;
    char p2[4];
    float f3c;
};
struct X_350c0 {
    void Fn(float* p);
};
struct C_350c0 {
    char p0[0x10];
    X_350c0* x;
    char p1[0x108];
    Y_350c0* y;
    char p2[0x20];
    int mode;
    bool F(float* p);
};
bool C_350c0::F(float* p) {
    x->Fn(p);
    Y_350c0* q;
    if (mode == 1 && (q = y) != 0) {
        hulk_freg v = q->f30;
        if (v <= 0.0f)
            v = q->f34 + q->f34;
        double r = v * 0.5f + (double)p[1];
        p[1] = r;
        int k = y->kind;
        if (k == 2 || k == 3)
            p[1] = (float)(y->f3c * 0.5f + r);
    }
    return true;
}
