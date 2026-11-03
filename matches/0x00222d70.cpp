#include "gen/owners.h"
bool owners::Obj_222d70::FUN_00222d70(hulk_intptr key, int value) {
    unsigned i = 0;
    while (i < count) {
        int* p = (int*)((char*)this + 0x6c + i * 0x28);
        if (*p == ((int)key)) {
            p[8] = value;
            return true;
        }
        ++i;
    }
    return false;
}