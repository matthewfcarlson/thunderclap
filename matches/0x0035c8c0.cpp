#include "decls/address.h"
#include "decls/data/game/global.h"
void FUN_0035c8c0() {
    unsigned long long r = FUN_0027b020("devil_hulk");
    (*(unsigned int*)&DAT_004dc090) = (unsigned int)r;
    (*(unsigned int*)((char*)&DAT_004dc090 + 4)) = (unsigned int)(r >> 32);
}
