// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 14/14)
// FUN_00359260 @ 0x00359260
#include "compat/ptr.h"
extern "C" double __cdecl sqrt(double);

struct Vec3_359260 {
    float x, y, z;
};

static inline float fabsf_(float f)
{
    union { float f; unsigned int u; } x;
    x.f = f;
    x.u &= 0x7fffffff;
    return x.f;
}

bool FUN_003577c0(Vec3_359260* p, Vec3_359260* a, Vec3_359260* b, Vec3_359260* c, Vec3_359260* n);
void FUN_00357ea0(Vec3_359260* origin, Vec3_359260* a, Vec3_359260* b, Vec3_359260* c, Vec3_359260* closest, bool e0, bool e1, bool e2);

// Ray/plane distance plus triangle containment test; falls back to the closest edge point.
bool FUN_00359260(Vec3_359260* origin, float eps, Vec3_359260* a, Vec3_359260* b, Vec3_359260* c, Vec3_359260* normal,
                  float* dist, Vec3_359260* hit, Vec3_359260* outDir, bool e0, bool e1, bool e2)
{
    double zx = (origin->z - b->z) * normal->z + (origin->x - b->x) * normal->x; // keep the original's summation order
    hulk_freg d = zx + (origin->y - b->y) * normal->y;
    *dist = d;
    if (fabsf_(d) > eps)
        return false;

    hulk_freg mx = d * normal->x;
    volatile float my = d * normal->y;
    volatile float mz = d * normal->z;
    hit->x = origin->x - mx;
    hit->y = origin->y - my;
    hit->z = origin->z - mz;

    if (FUN_003577c0(hit, a, b, c, normal)) {
        *outDir = *normal;
        *dist = *dist - eps;
        return true;
    }

    if (!e0 && !e1 && !e2)
        return false;

    FUN_00357ea0(origin, a, b, c, hit, e0, e1, e2);

    double dx = origin->x - hit->x; // the offsets stay in registers (unrounded) for len2
    double dy = origin->y - hit->y;
    double dz = origin->z - hit->z;
    outDir->x = dx;
    outDir->y = dy;
    outDir->z = dz;
    float len2 = dz * dz + dy * dy + dx * dx;
    if (eps * eps < len2)
        return false;

    if (!(fabsf_(len2) <= 0.00001f)) {
        double len = sqrt(len2); // unrounded in st0 in the original
        *dist = len;
        double inv = 1.0f / len;
        outDir->x = outDir->x * inv;
        outDir->y = outDir->y * inv;
        outDir->z = outDir->z * inv;
    } else {
        *dist = 0.0f;
        *outDir = *normal;
    }
    *dist = *dist - eps;
    return true;
}
