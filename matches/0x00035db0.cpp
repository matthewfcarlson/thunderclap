#include "decls/data/game/hulkfight.h"
// data: gState_35db0 = DAT_004dc290

extern "C" unsigned char __cdecl FUN_00035db0(unsigned char value) {
    unsigned char old = (*(unsigned char*)&DAT_004dc290);
    (*(unsigned char*)&DAT_004dc290) = value;
    return old;
}