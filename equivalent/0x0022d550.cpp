// STATUS: equivalent (tools/equiv.py level 3: 20019 inputs, branch coverage 10/10)
// FUN_0022d550 @ 0x0022d550
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct V3_22d550 {
    float x, y, z;
    void FUN_0022d180();
};

// Closest approach between a line (point P + t * dir ...) and a segment, see out parameters.
char FUN_0022d550(const V3_22d550 *s, const V3_22d550 *dir, const V3_22d550 *p, const V3_22d550 *t, float *outA, float *outB)
{
    V3_22d550 d1;
    d1.x = s->x - p->x;
    d1.y = s->y - p->y;
    d1.z = s->z - p->z;
    V3_22d550 d2;
    d2.x = t->x - p->x;
    d2.y = t->y - p->y;
    d2.z = t->z - p->z;
    float len = (float)sqrt(d2.z * d2.z + d2.y * d2.y + d2.x * d2.x);
    d2.FUN_0022d180();

    hulk_freg a = dir->y * dir->y + dir->z * dir->z + dir->x * dir->x;
    float b = d2.x * dir->x + d2.y * dir->y + d2.z * dir->z;
    hulk_freg e = d2.z * d2.z + d2.y * d2.y + d2.x * d2.x;
    float c = d1.z * dir->z + d1.x * dir->x + d1.y * dir->y;
    hulk_freg f = d2.z * d1.z + d2.x * d1.x + d2.y * d1.y;

    hulk_freg denom = e * a - b * b;
    if (denom < 1e-5f) {
        *outB = 0;
        *outA = -(c / a);
        return 0;
    }
    hulk_freg inv = 1.0f / denom;
    *outA = (f * b - c * e) * inv;
    hulk_freg tt = (f * a - c * b) * inv;
    *outB = tt;
    if (!(tt < 0.0f) && !(len < tt))
        return 1;
    if (tt < 0.0f)
        *outB = 0;
    if (*outB > len)
        *outB = len;
    *outA = (b * *outB - c) / a;
    return 1;
}
