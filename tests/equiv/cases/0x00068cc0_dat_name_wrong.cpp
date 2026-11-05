// (unb3) matches/0x00068cc0.cpp before the sweep: DAT_004dc3f8 / DAT_004dc3fc for the original 0x004dcf08 / 0x004dcf0c
// Same code shape as 0x000482e0 (propagated; names are from that function)
#include "decls/data/game/hulkfight.h"

extern "C" void FUN_00234810(void*, void*);
void FUN_00068cc0() {
    FUN_00234810(((char*)&DAT_004dc3f8), ((char*)&DAT_004dc3fc));
}