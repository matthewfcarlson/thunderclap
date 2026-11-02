// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 4/4; Wine build: input 71 differs only past the double exponent range (80-bit st0 overflow), HEAD failed at input 0)
// FUN_0009faa0 @ 0x0009faa0
#include "compat/ptr.h"
extern "C" double exp(double x);

hulk_freg __cdecl FUN_0009faa0(float from, float to, float a, float b)
{
    // the original keeps t and r in st0: t = 1 - exp(-(a/b)) and r = from + (to - from) * t are never rounded;
    // only the dead-zone test uses r stored to float (fst), and the unrounded r is returned
    hulk_freg t;
    if (b == 0.0f)
        t = 1.0f;
    else
        t = 1.0f - exp(-(a / b));
    hulk_freg r = from + (to - from) * t;
    float rf = (float)r;
    if (rf < 0.0f ? -rf <= 1e-05f : rf <= 1e-05f)
        return 0.0f;
    return r;
}
