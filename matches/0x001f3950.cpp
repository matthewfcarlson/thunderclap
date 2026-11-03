#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"

extern float gScale_1f3950;
void __cdecl Apply(int, float);
void owners::Obj_1f3950::FUN_001f3950(float value) {
    *(volatile float*)((hulk_intptr)((char*)&DAT_004c7df0)) = value;
    if (mPtr != 0 && mBusy == 0) {
        int x = *(int*)(mPtr + 4);
        if (x != 0)
            Apply(x, value * 0.01f);
    }
}