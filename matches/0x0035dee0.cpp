#include "decls/data/game/global.h"
// data: gData = DAT_00400488, gResult = DAT_004e09b8

extern __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035dee0() {
    (*(__int64*)&DAT_004e09b8) = FUN_0027b020(((char*)&DAT_00400488));
}