// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dbec0 @ 0x001dbec0
#include "decls/data/game/global.h"

typedef unsigned __int64 Key_1dbec0;
extern Key_1dbec0 __cdecl FUN_0027afb0(const char*);
bool __stdcall FUN_001dbec0(Key_1dbec0 key)
{
    if (!((*(unsigned int*)((char*)&DAT_004e2658 + 80)) & 1)) {
        (*(unsigned int*)((char*)&DAT_004e2658 + 80)) |= 1;
        ((Key_1dbec0*)&DAT_004e2658)[0] = FUN_0027afb0("agcfWaves");
        ((Key_1dbec0*)&DAT_004e2658)[1] = FUN_0027afb0("fire01");
        ((Key_1dbec0*)&DAT_004e2658)[2] = FUN_0027afb0("fire02");
        ((Key_1dbec0*)&DAT_004e2658)[3] = FUN_0027afb0("icyGas");
        ((Key_1dbec0*)&DAT_004e2658)[4] = FUN_0027afb0("roadFlare");
        ((Key_1dbec0*)&DAT_004e2658)[5] = FUN_0027afb0("smoke01");
        ((Key_1dbec0*)&DAT_004e2658)[6] = FUN_0027afb0("smoke02");
        ((Key_1dbec0*)&DAT_004e2658)[7] = FUN_0027afb0("spark02");
        ((Key_1dbec0*)&DAT_004e2658)[8] = FUN_0027afb0("waterGyserDamLeak");
        ((Key_1dbec0*)&DAT_004e2658)[9] = FUN_0027afb0("waterGyserPenstock");
    }
    for (int i = 0; i < 10; ++i) {
        if (((Key_1dbec0*)&DAT_004e2658)[i] == key) return true;
    }
    return false;
}
