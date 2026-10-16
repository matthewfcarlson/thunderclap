// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001ca430 @ 0x001ca430
#include "decls/address.h"
struct Report { bool FUN_001d2e80(); void FUN_001d1d50(const char*, const char*); void FUN_001d1dd0(const char*, int); void FUN_001d1d10(); };
struct Actor_1ca430 { const char* FUN_00036d00(); };
struct Registry_1ca430 { Actor_1ca430* FUN_00059c10(int); };
struct World { char pad[0x44]; Registry_1ca430* registry; };
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" void __cdecl FUN_00096d50(char*, int, int, int);
struct Target_1ca430 { char pad[0x10]; int actor; char pad14[4]; int prop1; int prop2; int type1; int type2; int index; Report* FUN_001d4c90(); bool run(); };
bool Target_1ca430::run() { unsigned int cookie=DAT_004d9968; Report* report = FUN_001d4c90(); bool result=false; if (report && report->FUN_001d2e80()) { char buffer[32]; FUN_00096d50(buffer,32,prop1,prop2); report->FUN_001d1d50("prop",buffer); FUN_00096d50(buffer,32,type1,type2); report->FUN_001d1d50("prop_type",buffer); report->FUN_001d1dd0("attachment_index",index); World* world=DAT_004dd700; int actorId=actor; if (world) { Actor_1ca430* found=world->registry->FUN_00059c10(actorId); const char* name=found ? found->FUN_00036d00() : "UNKNOWN"; report->FUN_001d1d50("actor",name); report->FUN_001d1d50("prop_DANGEROUS","prop_DANGEROUS is not defined in RELEASE!"); report->FUN_001d1d50("prop_type_DANGEROUS","prop_type_DANGEROUS is not defined in RELEASE!"); result=true; } report->FUN_001d1d10(); } __security_check_cookie(cookie); return result; }