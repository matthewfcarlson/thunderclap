#include "gen/owners.h"
hulk_intptr owners::Obj_446c0::FUN_000446c0(int index) {
    if (index >= 0 && index < 8)
        return *(int*)((char*)this + (index * 5 + 0x37) * 8);
    return 0;
}