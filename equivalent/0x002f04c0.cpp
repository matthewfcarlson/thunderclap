// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 8/8)
// FUN_002f04c0 @ 0x002f04c0
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Vec3_2f04c0 {
    float x, y, z;
};

bool FUN_002f04c0(const Vec3_2f04c0 *c, const Vec3_2f04c0 *d, float maxDist, float radius, float *out)
{
    // x87: b, pz, q, s, x1 and the e terms stay in registers; px, py, y1, z1 and radius^2 are stored (rounded)
    radius = radius * radius;
    hulk_freg cc = c->x * c->x + c->y * c->y + c->z * c->z;
    if (cc <= radius) {
        *out = 0.0f;
        return true;
    }
    hulk_freg b = c->x * d->x + c->y * d->y + d->z * c->z;
    if (b >= 0.0f)
        return false;
    b = -b;
    float px = b * d->x + c->x;
    float py = b * d->y + c->y;
    hulk_freg pz = b * d->z + c->z;
    hulk_freg q = pz * pz + px * px + py * py;
    if (!(q < radius))
        return false;
    hulk_freg s = -sqrt(radius - q);
    hulk_freg x1 = s * d->x + px;
    float y1 = s * d->y + py;
    float z1 = s * d->z + pz;
    hulk_freg ex = x1 - c->x;
    hulk_freg ey = y1 - c->y;
    hulk_freg ez = z1 - c->z;
    hulk_freg sum = ez * ez + ex * ex + ey * ey;
    if (!(sum <= (hulk_freg)maxDist * maxDist))
        return false;
    *out = (float)sqrt(sum);
    return true;
}
