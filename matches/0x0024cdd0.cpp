#include "compat/ptr.h"
extern "C" double sqrt(double);
extern "C" double pow(double, double);
extern "C" void _ReadWriteBarrier();
extern const float gOne_24cdd0;
extern const float gZero_24cdd0;
hulk_freg FUN_0024cdd0(float* a, float* b) {
    hulk_freg x = a[0] - b[0];
    hulk_freg y = a[1] - b[1];
    hulk_freg z = a[2] - b[2];
    double s = sqrt(y * y + z * z + x * x);  // the listing's order (MSVC 7.1 reassociates; clang does not)
    float d = (float)s;
    if ((float)s <= b[15])
        return gOne_24cdd0;
    if (d >= b[16])
        return gZero_24cdd0;
    float r = (float)pow(b[17], (d - b[15]) / (b[16] - b[15]));
    _ReadWriteBarrier();
    return r;
}