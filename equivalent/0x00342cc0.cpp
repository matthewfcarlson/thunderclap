// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00342cc0 @ 0x00342cc0
#include "compat/ptr.h"
struct Butterfly_342cc0 {
    float v[8];
};

// equiv-conv: FUN_00342cc0 eax
extern "C" void FUN_00342cc0(void *p)
{
    hulk_freg a = ((Butterfly_342cc0 *)p)->v[0] + ((Butterfly_342cc0 *)p)->v[4];
    hulk_freg b = ((Butterfly_342cc0 *)p)->v[1] + ((Butterfly_342cc0 *)p)->v[5];
    float c = ((Butterfly_342cc0 *)p)->v[0] - ((Butterfly_342cc0 *)p)->v[4];
    float d = ((Butterfly_342cc0 *)p)->v[1] - ((Butterfly_342cc0 *)p)->v[5];
    hulk_freg e = ((Butterfly_342cc0 *)p)->v[6] + ((Butterfly_342cc0 *)p)->v[2];
    float f = ((Butterfly_342cc0 *)p)->v[3] + ((Butterfly_342cc0 *)p)->v[7];
    float g = ((Butterfly_342cc0 *)p)->v[2] - ((Butterfly_342cc0 *)p)->v[6];
    float h = ((Butterfly_342cc0 *)p)->v[3] - ((Butterfly_342cc0 *)p)->v[7];
    ((Butterfly_342cc0 *)p)->v[0] = a + e;
    ((Butterfly_342cc0 *)p)->v[1] = b + f;
    ((Butterfly_342cc0 *)p)->v[4] = a - e;
    ((Butterfly_342cc0 *)p)->v[5] = b - f;
    ((Butterfly_342cc0 *)p)->v[2] = h + c;
    ((Butterfly_342cc0 *)p)->v[3] = d - g;
    ((Butterfly_342cc0 *)p)->v[6] = c - h;
    ((Butterfly_342cc0 *)p)->v[7] = g + d;
}
