#include "decls/data/game/global.h"
// data: g1_35cad0 = DAT_004dcef0, g2_35cad0 = DAT_004dcef4

unsigned __int64 FUN_0027b020(const char* s);
void FUN_0035cad0() {
    unsigned long long r = FUN_0027b020("airsmash");
    (*(unsigned int*)&DAT_004dcef0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004dcef4) = (unsigned int)(r >> 32);
}
