// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 8/8; --wine 611 inputs)
// FUN_00280840 @ 0x00280840
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct V3_280840 { float x, y, z; };

static hulk_freg DistSq(const V3_280840 &c, const V3_280840 *p) {
    hulk_freg dx = c.x - p->x;
    hulk_freg dy = c.y - p->y;
    hulk_freg dz = c.z - p->z;
    return dz * dz + dy * dy + dx * dx;
}

int __cdecl FUN_00280840(const V3_280840 *center, float margin, const V3_280840 *a, const V3_280840 *b, const V3_280840 *c) {
    hulk_freg sx0 = a->x + b->x;
    hulk_freg sy = a->y + b->y;
    float sz0 = b->z + a->z;
    float sx = (float)(sx0 + c->x);
    sy = sy + c->y;
    hulk_freg sz = sz0 + c->z;
    V3_280840 m;
    m.x = sx * 0.33333334f;
    m.y = sy * 0.33333334f;
    m.z = sz * 0.33333334f;
    float best = 0.0f;
    hulk_freg d = DistSq(m, a);
    if (d > best) best = (float)d;
    d = DistSq(m, b);
    if (d > best) best = (float)d;
    d = DistSq(m, c);
    if (d > best) best = (float)d;
    hulk_freg r = sqrt((double)best);
    hulk_freg dc = sqrt((double)DistSq(m, center));
    return r + margin > dc;
}
