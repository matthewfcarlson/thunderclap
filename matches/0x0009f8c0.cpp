#include "compat/ptr.h"
extern "C" double sin(double);
extern "C" double cos(double);
extern const float rad;
float* FUN_0009f8c0(float* out, volatile float a, volatile float b, float r) {
    hulk_freg aa = a * rad;
    hulk_freg bb = b * rad;
    a = (hulk_freg)cos(bb);
    out[0] = (float)(sin(aa) * a * r);
    out[1] = (float)(sin(bb) * r);
    out[2] = (float)(cos(aa) * a * r);
    return out;
}