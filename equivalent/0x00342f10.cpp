// STATUS: equivalent (tools/equiv.py level 3: 1860 inputs, branch coverage 8/8; --wine 433 inputs)
// FUN_00342f10 @ 0x00342f10
// equiv-conv: FUN_00342f10 ebx stack stack stack
#include "compat/ptr.h"
void FUN_00342f10(float *b, int n, float *c, int total)
{
    int half = n >> 1;
    int q = total / n;
    int lo = 0;
    int hi = total;
    for (int i = 1; i < half; i++) {
        lo += q;
        hi -= q;
        hulk_freg d = b[lo] - b[hi];
        hulk_freg s = b[hi] + b[lo];
        float sr = (float)s;  // MSVC stores s to a temp and reloads it for the second product
        float a = s * c[i] - d * c[n - i];
        float bb = d * c[i] + sr * c[n - i];
        c[i] = bb;
        c[n - i] = a;
    }
    c[half] = c[half] * b[0];
}
