#include "compat/ptr.h"
#include "gen/owners.h"
extern const float one;
void owners::Thing_ac7a0::FUN_000ac7a0(float a, float b) {
    flag = 1;
    hulk_freg d = mB - mA;
    x = (one - a) * d;
    y = (one - b) * d;
}