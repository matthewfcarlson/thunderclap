// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 6/6)
// FUN_0022d3a0 @ 0x0022d3a0
// Distance along `dir` from point `b` to point `a`, clamped to [0, limit]; 0 when limit is 0.
#include "compat/ptr.h"
struct Vec3_22d3a0 {
    float x, y, z;
};

void FUN_0022d3a0(const Vec3_22d3a0* a, const Vec3_22d3a0* b, const Vec3_22d3a0* dir, float limit, float* out)
{
    if (limit == 0.0f) {
        *out = 0.0f;
        return;
    }
    hulk_freg t = (a->z - b->z) * dir->z + (a->y - b->y) * dir->y + (a->x - b->x) * dir->x;
    if (t <= 0.0f) {
        *out = 0.0f;
        return;
    }
    if (t >= limit) {
        *out = limit;
    } else {
        *out = t;
    }
}
