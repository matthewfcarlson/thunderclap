// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 8/8)
// FUN_0010ac60 @ 0x0010ac60
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Vec3_10ac60 {
    float x, y, z;
    float FUN_0022d110();
};

struct Vec4_10ac60 {
    float x, y, z, w;
};

struct Locator {
    void FUN_00059a50(Vec3_10ac60 *out);
};

struct Body_10ac60 {
    char pad[0x10];
    Locator *locator;
    char FUN_000359e0(Vec4_10ac60 *out);
};

hulk_freg FUN_0010ac60(Body_10ac60 *a, Body_10ac60 *b, float radius, Vec3_10ac60 *out)
{
    Vec3_10ac60 pa;
    Vec3_10ac60 pb;
    Vec4_10ac60 info;
    float ra;
    float rb;

    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;

    a->locator->FUN_00059a50(&pa);
    b->locator->FUN_00059a50(&pb);

    float dx = pa.x - pb.x;
    ra = 0.0f;
    float dz = pa.z - pb.z;
    float d2 = dz * dz + dx * dx;

    if (a->FUN_000359e0(&info))
        ra = info.w * 0.5f;
    rb = 0.0f;
    if (b->FUN_000359e0(&info))
        rb = info.w * 0.5f;

    float reach = rb + ra + radius;
    if (!(d2 < reach * reach))
        return -1.0f;

    out->x = dx;
    out->y = 0.0f;
    out->z = dz;
    out->FUN_0022d110();

    float gap = (float)sqrt((double)d2) - ra - rb;
    if (gap < 0.0f)
        return 0.0f;
    return gap;
}
