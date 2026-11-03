// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001ca730 @ 0x001ca730
// cl-flags: /GS
#include "gen/owners.h"
struct Reporter_1ca730 {
 void FUN_001d1d10();
};
void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
struct Object {
 char pad[0x18];
 unsigned int propLo, propHi;
 unsigned int typeLo, typeHi;
 unsigned int increase;
 unsigned int unused;
 unsigned int originLo, originHi;
 Reporter_1ca730* FUN_001d4c90();
 bool target();
};
bool Object::target() {
 Reporter_1ca730* r = FUN_001d4c90();
 if (!r || !((owners::Obj_1d2e80 *)r)->FUN_001d2e80()) {
 return false;
 }
 char buffer[32];
 FUN_00096d50(buffer, 32, propLo, propHi);
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, typeLo, typeHi);
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, originLo, originHi);
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"origin", (hulk_uintptr)buffer);
 ((owners::Obj_1d1dd0 *)r)->FUN_001d1dd0((hulk_intptr)"ers_increase", (int)increase);
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!");
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!");
 r->FUN_001d1d10();
 return true;
}
