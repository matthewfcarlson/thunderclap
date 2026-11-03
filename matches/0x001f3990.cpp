#include "decls/data/game/global.h"
// data: gHundred = DAT_004c7df4

#include "compat/ptr.h"
#include "gen/owners.h"
void Apply(int, float);
void owners::Thing_1f3990::FUN_001f3990(float x) {
    DAT_004c7df4 = x;
    if (mA && !mB) {
        int v = *(int*)(mA + 4);
        if (v)
            Apply(v, x * 0.01f);
    }
}