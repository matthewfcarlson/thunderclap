#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: g_compare = DAT_004cc02c, g_zero_23fb00 = DAT_003f335c

void* __fastcall FUN_0023fb00(void* p) {
    void* v = *(void**)p;
    if (v == (*(void**)&DAT_004cc02c))
        return ((unsigned char*)&DAT_003f335c);
    return v;
}