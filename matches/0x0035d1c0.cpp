#include "decls/address.h"
#include "decls/data/game/unknown.h"
void FUN_0035d1c0() {
    long long r = FUN_0027b020("$MACRO_INSERT");
    *(int*)&r = *(int*)&r;
    (*(int*)&DAT_004dd8f0) = *(int*)&r;
    (*(int*)&DAT_004dd8f4) = *(int*)((char*)&r + 4);
}
