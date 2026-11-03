#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: gEmpty_240380 = DAT_003f335c, gSentinel_240380 = DAT_004cc02c
#include "gen/owners.h"

extern "C" int strcmp(const char*, const char*);
char owners::StringLike_240380::FUN_00240380(const char* other) {
    char* p = mData;
    if (other == 0)
        return p == (*(char**)&DAT_004cc02c);
    if (p == (*(char**)&DAT_004cc02c))
        p = ((char*)&DAT_003f335c);
    return strcmp(p, other) == 0;
}
