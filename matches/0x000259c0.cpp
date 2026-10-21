// Same code shape as 0x00018990 (propagated; names are from that function)
#include "compat/ptr.h"
extern "C" double sqrt(double);
hulk_freg __fastcall FUN_000259c0(float* p) {
    return (float)sqrt((double)(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]));
}
