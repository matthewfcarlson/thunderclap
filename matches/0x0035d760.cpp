#include "decls/data/game/global.h"
// data: gFirst_35d760 = DAT_004ddff8, gSecond_35d760 = DAT_004ddffc

unsigned __int64 FUN_0027b020(const char* s);

void __cdecl FUN_0035d760() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned int*)&DAT_004ddff8) = (unsigned int)r;
    (*(unsigned int*)&DAT_004ddffc) = (unsigned int)(r >> 32);
}
