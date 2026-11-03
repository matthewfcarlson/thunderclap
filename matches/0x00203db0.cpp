#include "decls/data/game/global.h"
// data: g_flag_203db0 = DAT_004c91d9
#include "gen/owners.h"

hulk_intptr owners::Obj_203db0::FUN_00203db0(hulk_intptr key) {
    int result = 0;
    if ((*(unsigned char*)((char*)&DAT_004c91d8 + 1))) {
        int i;
        for (i = 0; i < 2; ++i) {
            if (keys[i] == ((int)key)) {
                if (i >= 0)
                    result = *(int*)((char*)this + 0x530 + i * 0x3c);
                break;
            }
        }
    }
    return result;
}
