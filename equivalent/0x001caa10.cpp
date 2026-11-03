// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001caa10 @ 0x001caa10
// cl-flags: /GS
#include "gen/owners.h"
struct Properties_1caa10 {
 void FUN_001d1d10();
};
extern "C" void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Object {
 char padding[0x18];
 unsigned int propLow, propHigh;
 unsigned int typeLow, typeHigh;
 Properties_1caa10* FUN_001d4c90();
 bool target();
};
bool Object::target() {
 Properties_1caa10* properties = FUN_001d4c90();
 if (!properties || !((owners::Obj_1d2e80 *)properties)->FUN_001d2e80()) {
 return false;
 }
 char buffer[32];
 FUN_00096d50(buffer, 32, propLow, propHigh);
 ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, typeLow, typeHigh);
 ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer);
 ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!");
 ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!");
 properties->FUN_001d1d10();
 return true;
}