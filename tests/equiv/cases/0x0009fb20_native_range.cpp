// FUN_0009fb20 @ 0x0009fb20
// (integ3, D152) a range contract: dt >= 0 and tau >= 0 (frame times and time constants; a negative one sends exp past
// the double range where the original's x87 keeps a 15-bit exponent). Inputs are repaired into the range; --wine:
// the bounds pin the sense (just outside traps, just inside computes)
#include "compat/pre.h"
typedef double hulk_freg;
extern "C" double __cdecl exp(double);
// pre: ge(arg4, 0) ge(arg5, 0)
// pre-callers: 0x000a81d1 0x000a81f8 0x000a8220 0x000a8248 (the four calls in 0x000a8180; play3: dt is the frame time, tau a
// camera time constant, both >= 0 at every call)
hulk_freg __cdecl FUN_0009fb20(float a, float b, float c, float dt, float tau) {
    HULK_PRE_GE(dt, 0.0f);
    HULK_PRE_GE(tau, 0.0f);
    double factor = 1.0;
    if (tau != 0.0f) factor = 1.0 - exp(-(double)dt / tau);
    double second = 0.0;
    if (dt != 0.0f) {
        double q = factor / dt;
        second = 1.0 - q * tau;
    }
    double result = ((double)b - a) * factor + ((double)c - b) * second + a;
    union { float f; unsigned int u; } magnitude;
    magnitude.f = (float)result;
    magnitude.u &= 0x7fffffff;
    if (magnitude.f <= 1e-5f) return 0.0f;
    return result;
}
