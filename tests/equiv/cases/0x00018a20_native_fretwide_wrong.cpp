// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 6/6)
// FUN_00018a20 @ 0x00018a20
// Clamping acos: the argument is limited to [-1, 1] (NaN becomes -1) before the CRT's __CIacos.
#include "compat/ptr.h"
extern "C" double acos(double);

// equiv-map: __CIacos = 0x003441f0
hulk_freg __cdecl FUN_00018a20(float x)
{
    if (!(x >= -1.0f && x <= 1.0f))
        x = (x > 1.0f) ? 1.0f : -1.0f;
    double r = acos(x);
    return (float)r;
}
