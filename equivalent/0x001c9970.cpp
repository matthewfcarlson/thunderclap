// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 6/6)
// FUN_001c9970 @ 0x001c9970
// cl-flags: /GS
#include "gen/owners.h"
struct Service_1c9970 {
 void FUN_001d1e10(const char*, int);
 void FUN_001d1d10();
};
extern "C" Service_1c9970* __cdecl FUN_001d4c90();
void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
bool owners::Object_1c9970::FUN_001c9970() {
 bool result = false;
 if (FUN_001c9840()) {
  Service_1c9970* service = FUN_001d4c90();
  if (service && ((owners::Obj_1d2e80 *)service)->FUN_001d2e80()) {
   char origin[32];
   FUN_00096d50(origin, 32, originLow, originHigh);
   ((owners::Thing_1d1d50 *)service)->FUN_001d1d50((hulk_uintptr)"origin", (hulk_uintptr)origin);
   service->FUN_001d1e10("devastator", devastator);
   service->FUN_001d1d10();
   result = true;
  }
 }
 return result;
}