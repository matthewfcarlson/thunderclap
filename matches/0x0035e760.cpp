#include "decls/data/game/global.h"

unsigned __int64 FUN_0027b020(const char* s);
void FUN_0035e760() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    (*(int*)&DAT_004e2288) = (int)r;
    (*(int*)&DAT_004e228c) = (int)(r >> 32);
}
