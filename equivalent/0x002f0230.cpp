// STATUS: equivalent (tools/equiv.py level 3: 20021 inputs, branch coverage 36/36)
// FUN_002f0230 @ 0x002f0230
#include "decls/data/game/global.h"

struct V3_2f0230 {
    float x, y, z;
};


bool __cdecl FUN_002f01c0(const V3_2f0230 *origin, const V3_2f0230 *extent);

union FBits_2f0230 {
    float f;
    unsigned int u;
};

static float absf(float v)
{
    FBits_2f0230 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

float FUN_002f0230(const V3_2f0230 *origin, const V3_2f0230 *dir, const V3_2f0230 *extent)
{
    float tx = 2.0f;
    float ty = 2.0f;
    double tz = DAT_003f5cf8; // the original keeps tz in an x87 register (unrounded)

    if (FUN_002f01c0(origin, extent))
        return 0.0f;

    if (origin->x * dir->x < 0.0f) {
        tx = absf(origin->x) - extent->x;
        bool hit = tx >= 0.0f && tx <= absf(dir->x);
        if (hit) {
            tx = tx / absf(dir->x);
            hit = !(absf(tx * dir->y + origin->y) >= extent->y) && !(absf(tx * dir->z + origin->z) >= extent->z);
        }
        if (!hit)
            tx = 2.0f;
    }
    if (origin->y * dir->y < 0.0f) {
        ty = absf(origin->y) - extent->y;
        bool hit = ty >= 0.0f && ty <= absf(dir->y);
        if (hit) {
            ty = ty / absf(dir->y);
            hit = !(absf(ty * dir->x + origin->x) >= extent->x) && !(absf(ty * dir->z + origin->z) >= extent->z);
        }
        if (!hit)
            ty = 2.0f;
    }
    if (origin->z * dir->z < 0.0f) {
        float tzd = absf(origin->z) - extent->z;
        bool hit = tzd >= 0.0f && tzd <= absf(dir->z);
        if (hit) {
            tz = tzd / absf(dir->z);
            hit = !(absf(tz * dir->x + origin->x) >= extent->x) && !(absf(tz * dir->y + origin->y) >= extent->y);
        }
        if (!hit)
            tz = DAT_003f5cf8;
    }
    double r = tz;
    if (ty < r)
        r = ty;
    if (tx < r)
        r = tx;
    return r;
}
