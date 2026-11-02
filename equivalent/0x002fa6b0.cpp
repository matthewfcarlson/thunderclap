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
extern "C" void FUN_002fa6b0(const void * a, const void * b, const void * c, void * out)
{
    hulk_freg dx = ((const V3_2fa6b0 *)a)->x - ((const V3_2fa6b0 *)c)->x;
    hulk_freg dy = ((const V3_2fa6b0 *)a)->y - ((const V3_2fa6b0 *)c)->y;
    hulk_freg dz = ((const V3_2fa6b0 *)a)->z - ((const V3_2fa6b0 *)c)->z;
    volatile float e[3];
    e[0] = ((const V3_2fa6b0 *)a)->x - ((const V3_2fa6b0 *)b)->x;
    e[1] = ((const V3_2fa6b0 *)a)->y - ((const V3_2fa6b0 *)b)->y;
    hulk_freg ez = ((const V3_2fa6b0 *)a)->z - ((const V3_2fa6b0 *)b)->z;
    ((V3_2fa6b0 *)out)->x = e[1] * dz - ez * dy;
    ((V3_2fa6b0 *)out)->y = ez * dx - dz * e[0];
    ((V3_2fa6b0 *)out)->z = e[0] * dy - e[1] * dx;
    ((V3_2fa6b0 *)out)->FUN_0022d180();
}
