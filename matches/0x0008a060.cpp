#include "decls/data/game/global.h"
// data: gZero_8a060 = DAT_003f335c
#include "gen/owners.h"

char* owners::Obj_8a060::FUN_0008a060(hulk_intptr arg) {
    int i = Find(((int)arg));
    if (i == -1)
        return (char*)&(*(float*)&DAT_003f335c);
    return (char*)this + 0x160 + i * 0x18;
}