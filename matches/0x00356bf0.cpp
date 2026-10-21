#include "compat/ptr.h"
extern "C" double sin(double);
extern "C" double cos(double);
void FUN_00356bf0(float a, float b, float c, float* x, float* y, float* z) {
    hulk_freg s = (hulk_freg)sin(c) * a;
    *x = s * (hulk_freg)cos(b);
    *y = s * (hulk_freg)sin(b);
    *z = a * (hulk_freg)cos(c);
}
