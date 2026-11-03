#include "decls/data/engine/audio.h"
// data: gThing_23fc90 = DAT_004cc02c
#include "gen/owners.h"

owners::Obj_23fc90* owners::Obj_23fc90::FUN_0023fc90(hulk_intptr a, int b, int c) {
    if (((int)a) == 0) {
        mPtr = (*(void**)&DAT_004cc02c);
        short* p = (short*)((char*)(*(void**)&DAT_004cc02c) - 4);
        ++*p;
        mC = 0;
        mB = 2;
    } else
        helper(((int)a), b, b, c);
    return this;
}