// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 8/8)
// FUN_001ca430 @ 0x001ca430
// cl-flags: /GS
#include "decls/address.h"
#include "gen/owners.h"
struct Report {    void FUN_001d1d10(); };
struct Actor_1ca430 { const char* FUN_00036d00(); };
struct Registry_1ca430 {  };
struct World { char pad[0x44]; Registry_1ca430* registry; };
extern "C" void __cdecl FUN_00096d50(char*, int, int, int);
struct Target_1ca430 { char pad[0x10]; int actor; char pad14[4]; int prop1; int prop2; int type1; int type2; int index; Report* FUN_001d4c90(); bool run(); };
bool Target_1ca430::run() { Report* report = FUN_001d4c90(); bool result=false; if (report && ((owners::Obj_1d2e80 *)report)->FUN_001d2e80()) { char buffer[32]; FUN_00096d50(buffer,32,prop1,prop2); ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer); FUN_00096d50(buffer,32,type1,type2); ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer); ((owners::Obj_1d1dd0 *)report)->FUN_001d1dd0((hulk_intptr)"attachment_index", index); World* world=DAT_004dd700; int actorId=actor; if (world) { Actor_1ca430* found=((Actor_1ca430 *)((owners::ThisWrap_00059c10 *)(world->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)actorId)); const char* name=found ? found->FUN_00036d00() : "UNKNOWN"; ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)name); ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!"); ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!"); result=true; } report->FUN_001d1d10(); }  return result; }