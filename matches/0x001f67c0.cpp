#include "gen/owners.h"
int FUN_00247930(int a, int b);
void FUN_00247a90(int a, int b, int c);
void thunk_FUN_00270a50();
void FUN_002656a0();
extern "C" void FUN_00240bb0();


void owners::Obj_1f67c0::FUN_001f67c0() {
    if (!mB)
        return;
    if (FUN_00247930(mA, mB) == 1) {
        while (FUN_00247930(mA, mB) != 2) {
            thunk_FUN_00270a50();
            FUN_002656a0();
            FUN_00240bb0();
            Step(0.001f);
        }
    }
    if (FUN_00247930(mA, mB) == 2) {
        FUN_00247a90(mA, mB, 0);
        return;
    }
    mFlag = 1;
}
