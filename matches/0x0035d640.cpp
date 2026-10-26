#include "decls/address.h"
#include "decls/data/game/global.h"
// data: gMemCardControl = DAT_004ddf54, gMemCardName = DAT_004ddf50
void FUN_0035d640() {
    unsigned long long h = FUN_0027b020("AddMemCardControl");
    (*(unsigned int*)&DAT_004ddf50) = (unsigned int)h;
    (*(unsigned int*)((char*)&DAT_004ddf50 + 4)) = (unsigned int)(h >> 32);
}
