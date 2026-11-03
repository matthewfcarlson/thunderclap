#include "compat/ptr.h"
#include "gen/owners.h"
hulk_intptr owners::Thing_337680::FUN_00337680(hulk_intptr arg) {
    if (Check(((int)arg))) {
        state = 7;
        return 0;
    }
    int i = count;
    if (i >= 32) {
        state = 5;
        return 0;
    }
    ((owners::Thing_337680*)((char*)this + i * 0x288 + 8))->Init(((int)arg));
    count++;
    return (hulk_intptr)((char*)this + i * 0x288 + 8);
}