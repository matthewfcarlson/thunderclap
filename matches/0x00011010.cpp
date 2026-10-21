#include "compat/ptr.h"
extern "C" double __cdecl asin(double);
hulk_freg __cdecl FUN_00011010(float value) {
    double result = asin(value);
    return (float)result;
}