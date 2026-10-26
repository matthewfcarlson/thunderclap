#include "decls/address.h"
#include "decls/data/game/global.h"
// data: gResultHi = DAT_004dd75c, gResultLo = DAT_004dd758
void __cdecl FUN_0035cff0() {
    extern const char gLabel[];
    __int64 r = FUN_0027b020(gLabel);
    (*(int*)&DAT_004dd758) = (int)r;
    (*(int*)&DAT_004dd75c) = (int)((unsigned __int64)r >> 32);
}
