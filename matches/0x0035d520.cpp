#include "decls/address.h"
#include "decls/data/game/global.h"
// data: g_hash0 = DAT_004ddf28, g_hash1 = DAT_004ddf2c
extern "C" void __cdecl FUN_0035d520() throw() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned int*)&DAT_004ddf28) = (unsigned int)r;
    (*(unsigned int*)&DAT_004ddf2c) = (unsigned int)(r >> 32);
}
