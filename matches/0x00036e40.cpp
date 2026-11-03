#include "gen/owners.h"
typedef unsigned int u32_36e40;
u32_36e40 owners::Obj_36e40::FUN_00036e40(hulk_uintptr arg) {
    int i = FUN_00036d90(((u32_36e40)arg));
    if (i < 0)
        return 0;
    return *(u32_36e40*)((char*)this + 0x2158 + i * 16);
}