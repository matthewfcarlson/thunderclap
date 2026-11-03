#include "compat/ptr.h"
#include "gen/owners.h"
bool owners::X_26e200::FUN_0026e200(void* p) {
    hulk_intptr i = mHead;
    while (i != 0) {
        if (i == (hulk_intptr)p)
            return true;
        i = *(int*)(i + 0x10);
    }
    return false;
}