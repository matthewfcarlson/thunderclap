#include "decls/data/game/global.h"
// data: gA_1afa70 = DAT_004c3704, gB_1afa70 = DAT_004c3700

void __cdecl FUN_001afa70(int a, int b) {
    (*(int*)&DAT_004c3704) = b;
    (*(int*)&DAT_004c3700) = a;
}
