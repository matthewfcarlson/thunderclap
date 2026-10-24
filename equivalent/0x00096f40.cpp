// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8; --wine 601 inputs)
// FUN_00096f40 @ 0x00096f40
#include "compat/ptr.h"
struct Vec3_96f40 {
    float x, y, z;
};

struct Plane_96f40 {
    float nx, ny, nz, d;
    void FUN_0022dfe0(const Vec3_96f40 *a, const Vec3_96f40 *b, const Vec3_96f40 *c);
    char FUN_0022e1f0(const Vec3_96f40 *from, const Vec3_96f40 *to, float *t);
};

char FUN_00096f40(Vec3_96f40 v1, Vec3_96f40 v2, Vec3_96f40 v3, Vec3_96f40 v4)
{
    Plane_96f40 plane;
    float t;
    Vec3_96f40 up;
    up.x = v3.x;
    up.y = v3.y + 1.0f;
    up.z = v3.z;
    plane.FUN_0022dfe0(&v3, &up, &v4);
    if (!plane.FUN_0022e1f0(&v1, &v2, &t))
        return 0;

    Vec3_96f40 d;
    d.x = v2.x - v1.x;
    d.y = v2.y - v1.y;
    d.z = v2.z - v1.z;
    hulk_freg dtx = d.x * t;
    hulk_freg dty = d.y * t;
    float dtz = d.z * t;
    Vec3_96f40 q;
    q.x = v1.x + dtx;
    hulk_freg qy = v1.y + dty;
    q.z = v1.z + dtz;
    if (qy < v3.y)
        return 0;

    hulk_freg ex = v4.x - v3.x;
    hulk_freg ey = v4.y - v3.y;
    hulk_freg ez = v4.z - v3.z;
    hulk_freg lenSq = ez * ez + ey * ey + ex * ex;

    hulk_freg gx = q.x - v3.x;
    hulk_freg gy = 0.0f;
    hulk_freg gz = q.z - v3.z;
    float hx = q.x - v4.x;
    float hy = v3.y - v4.y;
    float hz = q.z - v4.z;
    if (lenSq < gz * gz + gy * gy + gx * gx)
        return 0;
    if (lenSq < hz * hz + hy * hy + hx * hx)
        return 0;
    return 1;
}
