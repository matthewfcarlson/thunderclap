// STATUS: equivalent (tools/equiv.py level 3: 20021 inputs, branch coverage 18/18)
// FUN_00359860 @ 0x00359860
#include "compat/ptr.h"
extern "C" double __cdecl fabs(double);

struct Vec3_359860 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    void FUN_0022c2b0(const Vec3_359860 *in, Vec3_359860 *out);
};

static inline float fabsf_(float f)
{
    union { float f; unsigned int u; } x;
    x.f = f;
    x.u &= 0x7fffffff;
    return x.f;
}

// Slab test of a ray against an oriented box: returns the negated smallest per-axis ratio.
hulk_freg FUN_00359860(Vec3_359860 *origin, Vec3_359860 *extent, Vec3_359860 *axisX, Vec3_359860 *axisY, Vec3_359860 *axisZ, Vec3_359860 *dir, Vec3_359860 *point)
{
    struct Frame {
        Vec3_359860 v;
        Vec3_359860 q;
        Vec3_359860 p;
        Matrix m;
    } f;

    f.m.m[0] = axisX->x;
    f.m.m[1] = axisY->x;
    f.m.m[2] = axisZ->x;
    f.m.m[3] = 0.0f;
    f.m.m[4] = axisX->y;
    f.m.m[5] = axisY->y;
    f.m.m[6] = axisZ->y;
    f.m.m[7] = 0.0f;
    f.m.m[8] = axisX->z;
    f.m.m[9] = axisY->z;
    f.m.m[10] = axisZ->z;
    f.m.m[11] = 0.0f;
    f.m.m[12] = 0.0f;
    f.m.m[13] = 0.0f;
    f.m.m[14] = 0.0f;
    f.m.m[15] = 1.0f;

    f.v.x = point->x - origin->x;
    f.v.y = point->y - origin->y;
    f.v.z = point->z - origin->z;
    f.m.FUN_0022c2b0(&f.v, &f.p);
    f.m.FUN_0022c2b0(dir, &f.q);

    float best = 1.0e12f;

    if (!(fabsf_(f.q.x) <= 1e-5f)) {
        double t = (extent->x + (f.q.x < 0.0f ? f.p.x : -f.p.x)) / fabs(f.q.x);
        volatile float r = (float)t; // rounded through the frame in the original
        if (t < best)
            best = r;
    }
    if (!(fabsf_(f.q.y) <= 1e-5f)) {
        double t = (extent->y + (f.q.y < 0.0f ? f.p.y : -f.p.y)) / fabs(f.q.y);
        volatile float r = (float)t; // rounded through the frame in the original
        if (t < best)
            best = r;
    }
    if (!(fabsf_(f.q.z) <= 1e-5f)) {
        double t = (extent->z + (f.q.z < 0.0f ? f.p.z : -f.p.z)) / fabs(f.q.z);
        volatile float r = (float)t; // rounded through the frame in the original
        if (t < best)
            best = r;
    }
    return -best;
}
