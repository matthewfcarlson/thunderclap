// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 2/2)
// FUN_00314380 @ 0x00314380
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Vec3_314380 {
    float x, y, z;
    float FUN_0022d110();
};

struct Plane_314380 {
    char pad0[0x44];
    Vec3_314380 n;           // 0x44
    char pad1[4];
    float d;          // 0x54
};


bool __cdecl FUN_00314380(Plane_314380 *plane, int unused, Vec3_314380 *v, Vec3_314380 *out)
{
    v->FUN_0022d110();
    // x87: dot, s and k stay in registers (53 bits); |dot| is tested on a rounded frame copy
    hulk_freg dot = (hulk_freg)plane->n.z * v->z + (hulk_freg)plane->n.y * v->y + (hulk_freg)plane->n.x * v->x;
    union { float f; unsigned int u; } a;
    a.f = (float)dot;
    a.u &= 0x7fffffff;
    if (1.0f - a.f < 1.0e-6f)
        return false;
    hulk_freg s = plane->d / (hulk_freg)sqrt(1.0f - dot * dot);
    out->x = s * v->x;
    out->y = s * v->y;
    out->z = s * v->z;
    hulk_freg k = -(dot * s);
    out->x += k * plane->n.x;
    out->y += k * plane->n.y;
    out->z += k * plane->n.z;
    return true;
}
