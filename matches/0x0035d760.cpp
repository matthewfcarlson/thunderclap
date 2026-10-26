#include "decls/data/game/global.h"
// data: gFirst_35d760 = DAT_004ddff8, gSecond_35d760 = DAT_004ddffc

extern "C" unsigned long long __cdecl Define(const char*);

void __cdecl FUN_0035d760() {
    unsigned long long r = Define("$MACRO_DEFINE");
    (*(unsigned int*)&DAT_004ddff8) = (unsigned int)r;
    (*(unsigned int*)&DAT_004ddffc) = (unsigned int)(r >> 32);
}
