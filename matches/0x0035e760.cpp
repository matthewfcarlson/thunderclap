#include "decls/data/game/global.h"

extern "C" unsigned long long hash(const char*);
void FUN_0035e760() {
    unsigned long long r = hash("$MACRO_DEFINE");
    (*(int*)&DAT_004e2288) = (int)r;
    (*(int*)&DAT_004e228c) = (int)(r >> 32);
}
