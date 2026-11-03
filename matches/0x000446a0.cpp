#include "decls/data/game/global.h"
// data: gZero_446a0 = DAT_003f32e0
#include "gen/owners.h"

float owners::C_446a0::FUN_000446a0(int index) {
    if (index == 0)
        return DAT_003f32e0;
    return *(float*)((char*)this + 0xd0 + index * 4);
}