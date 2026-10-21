// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 6/6)
// FUN_0009fb20 @ 0x0009fb20
#include "compat/ptr.h"
extern "C" double __cdecl exp(double);
hulk_freg __cdecl FUN_0009fb20(float a, float b, float c, float dt, float tau) {
    double factor = 1.0;
    if (tau != 0.0f) factor = 1.0 - exp(-(double)dt / tau);
    double second = 0.0;
    if (dt != 0.0f) {
        double q = factor / dt;     // the listing divides first, then multiplies by tau
        second = 1.0 - q * tau;
    }
    double result = ((double)b - a) * factor + ((double)c - b) * second + a;
    union { float f; unsigned int u; } magnitude;
    magnitude.f = (float)result;
    magnitude.u &= 0x7fffffff;
    if (magnitude.f <= 1e-5f) return 0.0f;
    return result;                  // st(0) unrounded
}
