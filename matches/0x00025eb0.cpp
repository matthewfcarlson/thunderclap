#include "decls/data/game/unknown.h"
// data: gValue_25eb0 = DAT_004dc0d8
#include "gen/owners.h"

extern void __fastcall InitThing(void*);
void owners::Thing_25eb0::FUN_00025eb0() {
    mFlag50 = 1;
    mA = 4;
    mB = 3;
    mC = 1;
    InitThing(mChild);
    m350 = 0;
    m351 = 0;
    m352 = 1;
    (*(int*)&DAT_004dc0d8) = 0x41000000;
    m584 = 0x7fffffff;
    m588 = 0;
}