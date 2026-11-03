#include "gen/owners.h"
hulk_intptr owners::CGrabAction_1dc0b0::FUN_001dc0b0(int index) {
    int r = 0;
    if (index < mCount) {
        if (index >= 0)
            r = *(int*)((char*)this + 0x1e620 + index * 4);
    }
    return r;
}
