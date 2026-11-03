#include "decls/data/engine/physics.h"
// data: threshold_30e8a0 = DAT_004d2fb8
#include "gen/owners.h"

void owners::Obj_30e8a0::FUN_0030e8a0() {
    state = 0;
    if (a > (*(const float*)&DAT_004d2fb8)) {
        state = 2;
        a = 1.0f;
        c = 0.0f;
        b = 0.0f;
        return;
    }
    if (b > (*(const float*)&DAT_004d2fb8)) {
        state = 3;
        a = 0.0f;
        b = 1.0f;
        c = 0.0f;
        return;
    }
    if (c > (*(const float*)&DAT_004d2fb8)) {
        state = 4;
        a = 0.0f;
        c = 1.0f;
        b = 0.0f;
    }
}
