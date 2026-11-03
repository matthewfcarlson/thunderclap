#include "compat/ptr.h"
#include "gen/owners.h"
typedef unsigned char bool8_27aac0;
bool8_27aac0 owners::Obj_27aac0::FUN_0027aac0(hulk_intptr a, int* out) {
    if (Check(((int)a))) {
        *(hulk_intptr*)out = index * 0x60 + (hulk_intptr)this + 0xd38;
        return 1;
    }
    *out = 0;
    return 0;
}