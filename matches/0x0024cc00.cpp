#include "compat/ptr.h"
struct Light {
    float pos[3];
    char pad[0x24 - 12];
    float dir[3];
    float nearD;
    float farD;
    float k;
    float extra;
    char Check(const Light* l, int key) const;
};

struct Obj_24cc00 {
    float x, y, z;
    char Check(const Light* l, int key) const;
};

extern float Dot(const float* a, const float* b);

hulk_freg FUN_0024cc00(const Obj_24cc00* p, const Light* l) {
    float d;
    if (p->Check(l, 0x3727c5ac) == 0) {
        float v[3];
        v[0] = p->x - l->pos[0];
        v[1] = p->y - l->pos[1];
        v[2] = p->z - l->pos[2];
        d = Dot(l->dir, v);
    } else {
        d = 0.0f;
    }
    if (d <= l->nearD)
        return 1.0f;
    if (l->nearD < d && d < l->farD)
        return (d - l->nearD) / (l->farD - l->nearD) * (1.0f - l->k);
    return l->k;
}
