#include "decls/address.h"
#include "decls/data/game/unknown.h"

void FUN_0035c760() {
    unsigned long long r = FUN_0027b020("missilesoldier");
    (*(unsigned int*)&DAT_004dc040) = (unsigned int)r;
    (*(unsigned int*)&DAT_004dc044) = (unsigned int)(r >> 32);
}
