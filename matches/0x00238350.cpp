#include "compat/ptr.h"
typedef float(__cdecl* Callback_238350)(unsigned int, unsigned int);
extern Callback_238350 gFunction;
extern unsigned int gValue_238350;
extern const float gZero_238350;
hulk_freg __cdecl FUN_00238350(unsigned int param) {
    if (gFunction == 0)
        return gZero_238350;
    return gFunction(param, gValue_238350);
}