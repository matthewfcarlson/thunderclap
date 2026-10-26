#include "decls/address.h"
#include "decls/data/game/global.h"
void FUN_0035c860() {
    unsigned long long r = FUN_0027b020("bradley");
    (*(unsigned int*)&DAT_004dc098) = (unsigned int)r;
    (*(unsigned int*)((char*)&DAT_004dc098 + 4)) = (unsigned int)(r >> 32);
}
