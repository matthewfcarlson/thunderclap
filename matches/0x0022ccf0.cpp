#include "compat/ptr.h"
extern "C" double sqrt(double);
struct V {
    float pad;
    float b;
    float c;
};
struct Mat_22ccf0 {
    float a[11];
    void Set(V* v);
};
// x87: the root and its reciprocal stay in registers; x uses the register copy, y the copy MSVC spills to a
// float slot (rounded)
void Mat_22ccf0::Set(V* v) {
    hulk_freg s = (hulk_freg)sqrt((double)((hulk_freg)v->c * v->c + (hulk_freg)v->b * v->b));
    hulk_freg n = 1.0f / s;
    hulk_freg x = n * v->b;
    float spilled = n;
    hulk_freg y = spilled * v->c;
    a[0] = 1.0f;
    a[1] = 0.0f;
    a[5] = y;
    a[2] = 0.0f;
    a[4] = 0.0f;
    a[8] = 0.0f;
    a[6] = -x;
    a[9] = x;
    a[10] = y;
}
