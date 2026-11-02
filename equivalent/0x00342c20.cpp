// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00342c20 @ 0x00342c20
#include "compat/ptr.h"
struct Butterfly_342c20 {
    float v[8];
};

// equiv-conv: FUN_00342c20 eax
extern "C" void FUN_00342c20(void *p)
{
    hulk_freg a = ((Butterfly_342c20 *)p)->v[0] + ((Butterfly_342c20 *)p)->v[4];
    hulk_freg b = ((Butterfly_342c20 *)p)->v[1] + ((Butterfly_342c20 *)p)->v[5];
    float c = ((Butterfly_342c20 *)p)->v[0] - ((Butterfly_342c20 *)p)->v[4];
    float d = ((Butterfly_342c20 *)p)->v[1] - ((Butterfly_342c20 *)p)->v[5];
    hulk_freg e = ((Butterfly_342c20 *)p)->v[6] + ((Butterfly_342c20 *)p)->v[2];
    float f = ((Butterfly_342c20 *)p)->v[3] + ((Butterfly_342c20 *)p)->v[7];
    float g = ((Butterfly_342c20 *)p)->v[2] - ((Butterfly_342c20 *)p)->v[6];
    float h = ((Butterfly_342c20 *)p)->v[3] - ((Butterfly_342c20 *)p)->v[7];
    ((Butterfly_342c20 *)p)->v[0] = a + e;
    ((Butterfly_342c20 *)p)->v[1] = b + f;
    ((Butterfly_342c20 *)p)->v[4] = a - e;
    ((Butterfly_342c20 *)p)->v[5] = b - f;
    ((Butterfly_342c20 *)p)->v[2] = c - h;
    ((Butterfly_342c20 *)p)->v[3] = g + d;
    ((Butterfly_342c20 *)p)->v[6] = h + c;
    ((Butterfly_342c20 *)p)->v[7] = d - g;
}
