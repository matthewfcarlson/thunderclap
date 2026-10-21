// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 4/4)
// FUN_00358630 @ 0x00358630
// Interval test along a direction: writes (centre - radius) to *out and returns whether |centre| <= radius.
#include "compat/ptr.h"
struct Vec3_358630 {
    float x, y, z;
};

union AbsFloat {
    float f;
    unsigned int bits;
};

extern "C" double sqrt(double);

bool __cdecl FUN_00358630(const Vec3_358630 *a, const Vec3_358630 *b, float k1, float k2, char flag, float offset,
                          const Vec3_358630 *dir, float *out)
{
    // x87: the centre, the root and the radius stay in registers (53 bits); |t| and q go through the frame
    hulk_freg centre = (hulk_freg)a->z * dir->z + (hulk_freg)a->y * dir->y + (hulk_freg)dir->x * a->x + offset;

    AbsFloat t;
    t.f = b->z * dir->z + b->y * dir->y + b->x * dir->x;
    t.bits &= 0x7fffffff;

    AbsFloat q;
    q.f = 1.0f - t.f * t.f;
    q.bits &= 0x7fffffff;

    hulk_freg radius;
    if (flag)
        radius = (hulk_freg)sqrt(q.f) * k1 + (hulk_freg)t.f * k2;
    else
        radius = (hulk_freg)t.f * k2 + k1;

    *out = (float)(centre - radius);

    AbsFloat c;
    c.f = (float)centre;
    c.bits &= 0x7fffffff;
    return c.f <= radius;
}
