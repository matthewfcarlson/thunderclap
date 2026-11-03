#include "compat/ptr.h"
#include "gen/owners.h"
int owners::Obj_231770::FUN_00231770(hulk_uintptr key) {
    int n = 0;
    unsigned int i = 0;
    while (i < count) {
        if (keys[i] == ((unsigned int)key)) {
            keys[i] = (hulk_uintptr)((char*)this + 0x20);
            unsigned int* d = data;
            d[i * 2] = 0;
            d[i * 2 + 1] = 0;
            ++n;
            ++found;
            --remaining;
        }
        ++i;
    }
    if (flag && found > limit)
        Resize();
    return n;
}