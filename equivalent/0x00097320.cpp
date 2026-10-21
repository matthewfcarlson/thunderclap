// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 14/14)
// FUN_00097320 @ 0x00097320
#include "compat/ptr.h"
hulk_freg __cdecl FUN_00097320(float a, float b) {
    bool negative = a < 0.0f;
    double magnitude = negative ? -(double)a : (double)a;
    int whole = (int)magnitude;
    double na = (magnitude - whole) + (whole % 360);
    if (negative) na = 360.0f - na;
    volatile float ar = (float)na; // the original reloads the rounded copy from its frame slot
    negative = b < 0.0f;
    magnitude = negative ? -(double)b : (double)b;
    whole = (int)magnitude;
    double nb = (magnitude - whole) + (whole % 360);
    if (negative) nb = 360.0f - nb;
    float br = (float)nb;
    float direct = (float)(nb - ar);
    if (nb > 180.0f) br = (float)(nb - 360.0f);
    if (ar > 180.0f) na = (double)ar - 360.0f;
    double wrapped = (double)br - na;
    float wr = (float)wrapped;
    union Bits { float f; unsigned int u; } x,y;
    x.f = direct; x.u &= 0x7fffffff;
    y.f = wr; y.u &= 0x7fffffff;
    if (x.f < y.f) return direct;
    return (float)wrapped;
}