// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 6/6)
// FUN_001cab60 @ 0x001cab60
// cl-flags: /GS
#include "decls/data/game/hulkfight/scenario.h"
#include "gen/owners.h"

struct Writer_1cab60 {
 void FUN_001d1d10();
};
extern void __cdecl FUN_00096d50(char*, int, unsigned int, unsigned int);
struct Object {
 char pad[0x18];
 unsigned int propLow, propHigh, typeLow, typeHigh;
 int state, increase;
 unsigned int originLow, originHigh;
 Writer_1cab60* FUN_001d4c90();
 bool FUN_001cab60();
};
bool Object::FUN_001cab60() {
 Writer_1cab60* w = FUN_001d4c90();
 if (!w || !((owners::Obj_1d2e80 *)w)->FUN_001d2e80()) {
 return false;
 }
 char buffer[32];
 FUN_00096d50(buffer, 32, propLow, propHigh);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, typeLow, typeHigh);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, originLow, originHigh);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"origin", (hulk_uintptr)buffer);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"state_desc", (hulk_uintptr)(state == -1 ? "unDEfiNeD - tell Zaven!" : ((const char**)&DAT_004c165c)[state]));
 ((owners::Obj_1d1dd0 *)w)->FUN_001d1dd0((hulk_intptr)"ers_increase", increase);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!");
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!");
 w->FUN_001d1d10();
 return true;
}
