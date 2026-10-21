#include "compat/ptr.h"
extern const float one;
extern "C" double sqrt(double);
// x87: the squared length (x*x + y*y, then + z*z), its root and the reciprocal stay in registers; MSVC drops the
// (float) cast of sqrt's result
void __fastcall Normalize(float* p, void*) {
    hulk_freg s = (hulk_freg)p[0] * p[0] + (hulk_freg)p[1] * p[1] + (hulk_freg)p[2] * p[2];
    hulk_freg f = one / (hulk_freg)sqrt((double)s);
    p[0] = f * p[0];
    p[1] = f * p[1];
    p[2] = f * p[2];
}
