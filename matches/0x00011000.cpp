#include "compat/ptr.h"
extern "C" double __cdecl acos(double);
hulk_freg __cdecl FUN_00011000(float value) {
    double result = acos(value);
    return (float)result;
}