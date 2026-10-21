// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 12/12)
// FUN_00314a10 @ 0x00314a10
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct V3_314a10 {
    float x, y, z;
    void FUN_000111b0(const V3_314a10* a, const V3_314a10* b);
    float FUN_0022d110();
    void FUN_001f6bc0(const V3_314a10* base, float scale, const V3_314a10* dir);
};

struct Capsule {
    char pad00[0xc];
    float inner;
    float radius;
    int FUN_00314a10(const V3_314a10* a1, const V3_314a10* a2, const V3_314a10* axis, float f4, float f5, char flag, V3_314a10* out, V3_314a10* out2);
};

int Capsule::FUN_00314a10(const V3_314a10* a1, const V3_314a10* a2, const V3_314a10* axis, float f4, float f5, char flag, V3_314a10* out, V3_314a10* out2)
{
    V3_314a10 d;
    d.x = a2->x - a1->x;
    d.y = a2->y - a1->y;
    d.z = a2->z - a1->z;
    hulk_freg dd = d.z * d.z + d.x * d.x + d.y * d.y;
    float reach = radius + radius + f4 + f5;
    if (dd > reach * reach)
        return -1;
    double len = sqrt(dd);
    float lenf = (float)len;
    if (f5 + radius > len + f4 || f4 + radius > lenf + f5) {
        *out = *a1;
        return 0;
    }
    hulk_freg f4sq = f4 * f4;
    hulk_freg u = (f4sq - f5 * f5) + lenf * lenf;
    hulk_freg w = u / (lenf + lenf);
    float v = f4sq - w * w;
    hulk_freg r = w / lenf;
    out->x = d.x * r + a1->x;
    out->y = d.y * r + a1->y;
    out->z = d.z * r + a1->z;
    if (flag == 0)
        return 1;
    if (v <= inner * inner)
        return 1;
    V3_314a10 c;
    c.FUN_000111b0(&d, axis);
    c.FUN_0022d110();
    if (v < 0.0f)
        return -1;
    float s = (float)sqrt(v);
    out2->FUN_001f6bc0(out, s, &c);
    out->FUN_001f6bc0(out2, s * -2.0f, &c);
    return 2;
}
