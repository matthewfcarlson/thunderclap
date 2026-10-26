#include "decls/address.h"
#include "decls/data/game/global.h"
// data: gValue = DAT_004e09ec
void FUN_0035dfa0() {
    unsigned long long v = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned int*)&DAT_004e09e8) = (unsigned int)v;
    (*(unsigned int*)&DAT_004e09ec) = (unsigned int)(v >> 32);
}
