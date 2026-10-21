// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// FUN_0022fec0 @ 0x0022fec0
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Bounds_22fec0 {
    float min[3];
    float max[3];
    void GetCenter(struct CenterRadius *out);
};

struct CenterRadius {
    float x, y, z;
    float radius;
};

void Bounds_22fec0::GetCenter(CenterRadius *out)
{
    hulk_freg dx = min[0] - max[0];
    hulk_freg dy = min[1] - max[1];
    hulk_freg dz = min[2] - max[2];
    hulk_freg sx = min[0] + max[0];
    hulk_freg sy = max[1] + min[1];
    hulk_freg sz = max[2] + min[2];
    out->x = sx * 0.5f;
    out->y = sy * 0.5f;
    out->z = sz * 0.5f;
    out->radius = (float)sqrt(dz * dz + dx * dx + dy * dy);
}
