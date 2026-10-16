// STATUS: equivalent (tools/equiv.py level 3: 536 inputs, branch coverage 16/16)
// FUN_001e95c0 @ 0x001e95c0
#include "decls/address.h"
struct Controller_1e95c0 { bool FUN_00266750(); void FUN_00263e90(); };
struct Subsystem_1e95c0 { void FUN_000862a0(); };
struct World { char pad[0x54]; Subsystem_1e95c0* subsystem; };
extern Controller_1e95c0* DAT_004e3694;
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
void __cdecl FUN_00240bb0();
int __cdecl FUN_00240750(float);
void __cdecl FUN_00243090(int);
struct Entry_1e95c0 { int state; };
struct Target_1e95c0 { char pad[0x19c]; Entry_1e95c0* entries[200]; int count; void FUN_002696a0(); void update(float time, bool active); };
void Target_1e95c0::update(float time, bool active) {
 unsigned int cookie=DAT_004d9968;
 FUN_002696a0();
 FUN_00240bb0();
 FUN_00243090(FUN_00240750(time * 1000.0f));
 if (DAT_004dd700 && DAT_004dd700->subsystem) DAT_004dd700->subsystem->FUN_000862a0();
 if (active) {
 for(int i=0;i<count;++i) {
 Entry_1e95c0* entry=entries[i];
 if(entry && entry->state==1 && DAT_004e3694->FUN_00266750()) {
 entry->state=3;
 DAT_004e3694->FUN_00263e90();
 DAT_004e3694=0;
 }
 }
 }
 __security_check_cookie(cookie);
}