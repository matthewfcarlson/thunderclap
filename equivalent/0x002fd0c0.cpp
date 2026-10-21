// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 2/2)
// FUN_002fd0c0 @ 0x002fd0c0
#include "compat/ptr.h"
struct Sym3 {
    char pad0[4];
    float xx;       // 0x4
    float xy;       // 0x8
    float xz;       // 0xc
    float yy;       // 0x10
    float yz;       // 0x14
    float zz;       // 0x18
    void FUN_002fd0c0(const Sym3 *a);
};

// Inverse of a symmetric 3x3 matrix stored as six floats; zero when the pivot product vanishes.
// Intermediates are kept as double (the original keeps them unrounded on the x87 stack).
void Sym3::FUN_002fd0c0(const Sym3 *a)
{
    double inv = 1.0 / a->xx;
    double piv = inv * a->xx;
    hulk_freg t0 = (float)(inv * a->xy);
    hulk_freg t1 = (float)(inv * a->xz);
    hulk_freg t2 = (float)(inv * a->yy);
    hulk_freg t3 = (float)(inv * a->yz);
    double e4 = inv * a->zz;
    hulk_freg t4 = (float)e4;
    double e5 = e4 * t2;
    volatile float u = (float)e5;      // the original stores and reloads it rounded
    double q = e5 * piv;
    if (q == 0.0) {
        yy = 0.0f;
        xx = 0.0f;
        yz = 0.0f;
        xz = 0.0f;
        xy = 0.0f;
        zz = 0.0f;
        return;
    }
    xx = (float)piv;
    double r1 = (double)t3 * t1;
    volatile float m0 = (float)r1;     // likewise (fst [esp])
    xy = t0;
    xz = t1;
    yy = t2;
    yz = t3;
    zz = t4;
    double d = inv / (((r1 * t0 + r1 * t0) + q) - ((double)t1 * t1) * t2 - ((double)t0 * t0) * t4 - ((double)t3 * t3) * piv);
    hulk_freg x1 = (float)((u - (double)t3 * t3) * d);
    hulk_freg x2 = (float)(-(((double)t0 * t4 - m0) * d));
    hulk_freg x3 = (float)(((double)t3 * t0 - (double)t1 * t2) * d);
    hulk_freg x4 = (float)(((double)t4 * xx - (double)t1 * t1) * d);
    hulk_freg x5 = (float)(-(((double)t3 * xx - (double)t0 * t1) * d));
    hulk_freg x6 = (float)(((double)t2 * xx - (double)t0 * t0) * d);
    xz = x3;
    yy = x4;
    yz = x5;
    zz = x6;
    xx = x1;
    xy = x2;
}
