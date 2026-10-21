// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 18/18)
// FUN_000a00e0 @ 0x000a00e0
#include "compat/ptr.h"
float FUN_000186b0(float *p0, float *p1, float *p2);
float FUN_0009f760(float x);

struct Frame_a00e0 { float L0, t, q, vc; };

hulk_freg FUN_000a00e0(float a, float b, float c, float d, float e)
{
    Frame_a00e0 f;
    f.L0 = b - a;
    if (f.L0 == 0.0f || c == 0.0f || d == 0.0f)
        return a;

    f.vc = a;
    double vcd = a; // the register copy of f.vc (unrounded)
    unsigned bits = *(unsigned *)&f.L0 & 0x7fffffff;
    f.t = *(float *)&bits - e;
        if (f.t > 0.0f) {
        f.q = f.t / c;
        bool lim = !(f.q < d);
        if (!lim) {
            f.vc = -f.t;
        } else {
            f.t = c * d;
            f.vc = -(c * d);
        }
        f.t = FUN_000186b0(&f.L0, &f.vc, &f.t);
        if (lim)
            f.q = d;
        vcd = f.t + a;
        f.vc = vcd;
        f.L0 = f.L0 - f.t;
        d = d - f.q;
    }
    double x = vcd; // returned unrounded (st0) by the original
    if (e > 0.0f && d > 0.0f) {
        unsigned bits2 = *(unsigned *)&f.L0 & 0x7fffffff;
        if (!(e * 0.001f >= *(float *)&bits2)) {
            float tmp = -(c / e * d);
            x = (1.0f - FUN_0009f760(tmp)) * f.L0 + f.vc;
        } else {
            x = b;
        }
    }
    volatile float xs = x;
    unsigned bits3 = *(unsigned *)&xs & 0x7fffffff;
    if (!(*(float *)&bits3 <= 1e-5f))
        return x;
    return 0.0f;
}
