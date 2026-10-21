#include "compat/ptr.h"
extern "C" double sqrt(double);
hulk_freg __fastcall FUN_00018990(float* p) {
    return (float)sqrt((double)(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]));
}
