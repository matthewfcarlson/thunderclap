// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 18/18)
// FUN_0030adc0 @ 0x0030adc0
#include "compat/ptr.h"
hulk_freg __stdcall FUN_0030adc0(float start, float delta, float lower, float upper)
{
    union { float f; unsigned int u; } magnitude;
    magnitude.f = delta;
    magnitude.u &= 0x7fffffff;
    if (!(magnitude.f > 0.0f)) return 1.0f;
    double end = (double)start + (double)delta;
    if (end <= upper && end >= lower) return 1.0f;
    if (start >= upper && delta > 0.0f) return 0.0f;
    if (start <= lower && delta < 0.0f) return 0.0f;
    double fraction = ((double)(delta > 0.0f ? upper : lower) - (double)start) / (double)delta;
    if (fraction > 1.0f) return 1.0f;
    return (float)fraction;
}