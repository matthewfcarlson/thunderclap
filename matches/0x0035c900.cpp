#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
// data: hulk_at_003f3fd8 = DAT_003f3fd8

#include "compat/ptr.h"
#include "decls/address.h"
typedef unsigned __int64 U64_35c900;
void FUN_0035c900() {
    U64_35c900 r = FUN_0027b020((const char*)((hulk_intptr)((char*)&DAT_003f3fd8)));
    (*(int*)&DAT_004dc0b8) = (int)r;
    (*(int*)((char*)&DAT_004dc0b8 + 4)) = (int)(r >> 32);
}
