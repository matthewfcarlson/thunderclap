// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 8/8)
// FUN_001ca890 @ 0x001ca890
// cl-flags: /GS
#include "decls/address.h"
#include "gen/owners.h"
struct Actor_1ca890 { const char* FUN_00036d00(); };
struct Registry_1ca890 {  };
struct World { char pad[0x44]; Registry_1ca890* registry; };
struct Writer_1ca890 {    void FUN_001d1d10(); };
extern "C" void __cdecl FUN_00096d50(char*, int, unsigned int, unsigned int);
struct Target_1ca890 { char pad[0x10]; unsigned int actor; char pad14[4]; unsigned int propLow, propHigh, typeLow, typeHigh, attachment; Writer_1ca890* FUN_001d4c90(); bool run(); };
bool Target_1ca890::run() {
 Writer_1ca890* writer = FUN_001d4c90();
 bool result = false;
 if (writer && ((owners::Obj_1d2e80 *)writer)->FUN_001d2e80()) {
 char buffer[32];
 FUN_00096d50(buffer, 32, propLow, propHigh);
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, typeLow, typeHigh);
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer);
 ((owners::Obj_1d1dd0 *)writer)->FUN_001d1dd0((hulk_intptr)"attachment_index", (int)attachment);
 World* world = DAT_004dd700;
 unsigned int id = actor;
 if (world) {
 Actor_1ca890* a = ((Actor_1ca890 *)((owners::ThisWrap_00059c10 *)(world->registry))->FUN_00059c10((void *)(hulk_uintptr)(unsigned int)id));
 const char* name = a ? a->FUN_00036d00() : "UNKNOWN";
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)name);
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!");
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!");
 result = true;
 }
 writer->FUN_001d1d10();
 }
 return result;
}