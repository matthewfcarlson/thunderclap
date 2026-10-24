// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 6/6)
// FUN_000189c0 @ 0x000189c0
// Clamping asin: the argument is limited to [-1, 1] (NaN becomes -1) before the CRT's __CIasin.
#include "compat/ptr.h"
extern "C" double asin(double);

// equiv-map: __CIasin = 0x003442bc
hulk_freg __cdecl FUN_000189c0(float x)
{
    if (!(x >= -1.0f && x <= 1.0f))
        x = (x > 1.0f) ? 1.0f : -1.0f;
    double r = asin(x);
    return (float)r;
}
