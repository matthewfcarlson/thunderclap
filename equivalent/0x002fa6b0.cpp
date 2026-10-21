// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 0/0)
// FUN_002fa6b0 @ 0x002fa6b0
struct V3_2fa6b0 {
    float x, y, z;
    void FUN_0022d180();
};

#include "compat/ptr.h"
// out = normalised cross product (a - b) x (a - c)
// x87: the differences to c and the z difference to b stay in registers (53 bits); the x and y differences to b
// go through the frame (rounded)
void FUN_002fa6b0(const V3_2fa6b0* a, const V3_2fa6b0* b, const V3_2fa6b0* c, V3_2fa6b0* out)
{
    hulk_freg dx = a->x - c->x;
    hulk_freg dy = a->y - c->y;
    hulk_freg dz = a->z - c->z;
    volatile float e[3];
    e[0] = a->x - b->x;
    e[1] = a->y - b->y;
    hulk_freg ez = a->z - b->z;
    out->x = e[1] * dz - ez * dy;
    out->y = ez * dx - dz * e[0];
    out->z = e[0] * dy - e[1] * dx;
    out->FUN_0022d180();
}
