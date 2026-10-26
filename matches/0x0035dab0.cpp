#include "decls/address.h"
#include "decls/data/game/global.h"
// data: g_hash_35dab0 = DAT_004de700
extern unsigned int g_hash_hi;
void FUN_0035dab0() {
    unsigned long long r = FUN_0027b020("TextInputEntryLocators");
    (*(unsigned int*)&DAT_004de700) = (unsigned int)r;
    g_hash_hi = (unsigned int)(r >> 32);
}
