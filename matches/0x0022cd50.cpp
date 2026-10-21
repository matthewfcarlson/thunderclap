#include "compat/ptr.h"
extern "C" double sqrt(double);
struct Vec {
    float x, y;
};
struct Mat {
    float a[11];
    void Init(const Vec* v);
};
// x87: the reciprocal length stays in a register for x; y uses the copy MSVC spills to a float slot (rounded)
void Mat::Init(const Vec* v) {
    float vx = v->x;
    hulk_freg n = 1.0f / (hulk_freg)sqrt((hulk_freg)v->y * v->y + (hulk_freg)vx * vx);
    hulk_freg x = n * v->x;
    float spilled = n;
    hulk_freg y = spilled * v->y;
    a[0] = x;
    a[2] = 0;
    a[6] = 0;
    a[8] = 0;
    a[1] = y;
    a[9] = 0;
    a[10] = 1.0f;
    a[4] = -y;
    a[5] = x;
}
