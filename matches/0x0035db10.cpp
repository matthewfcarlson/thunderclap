#include "decls/data/game/global.h"
// data: gHashHigh = DAT_004de724, gHashLow = DAT_004de720, hulk_at_00400488 = DAT_00400488

#include "compat/ptr.h"
extern "C" unsigned __int64 Hash(const char*);
void FUN_0035db10() {
    unsigned __int64 h = Hash((const char*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(unsigned int*)&DAT_004de720) = (unsigned int)h;
    (*(unsigned int*)&DAT_004de724) = (unsigned int)(h >> 32);
}
