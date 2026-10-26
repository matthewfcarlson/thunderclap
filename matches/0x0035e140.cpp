#include "decls/address.h"
#include "decls/data/game/DollyScript.h"
// data: g_first_35e140 = DAT_004e0a40, g_second_35e140 = DAT_004e0a44

void FUN_0035e140() {
    unsigned __int64 result = FUN_0027b020("$MACRO_INSERT");
    (*(unsigned int*)&DAT_004e0a40) = (unsigned int)result;
    (*(unsigned int*)&DAT_004e0a44) = (unsigned int)(result >> 32);
}
