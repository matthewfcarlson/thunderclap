#include "compat/ptr.h"
#include "gen/owners.h"
extern const float kMinDist = 0.02f;
extern "C" double sqrt(double);
unsigned char owners::Vec_1b3670::FUN_001b3670(const owners::Vec_1b3670* other) {
    hulk_freg dx = other->x - x, dy = other->y - y, dz = other->z - z;
    hulk_freg a = dz * dz;
    a += dx * dx;
    a += dy * dy;
    a = (hulk_freg)sqrt(a);
    if (a < kMinDist)
        a = kMinDist;
    return a <= limit;
}
