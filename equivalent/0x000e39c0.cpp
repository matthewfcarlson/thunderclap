// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// MapThing::vfunc_13 @ 0x000e39c0
#include "decls/address.h"
struct Vec_e39c0 { float x,y,z; };
struct Test_e39c0 { char pad[4]; };
// equiv-conv: FUN_0022d2b0 ecx stack
extern bool __stdcall FUN_0022d2b0(void*,Vec_e39c0*);
struct Lookup_e39c0 { Test_e39c0* FUN_000c8190(int); };
struct Manager_e39c0 { Lookup_e39c0* FUN_000cae70(); };
struct Entry_e39c0 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual Vec_e39c0* slot8(Vec_e39c0*, unsigned); };
struct Store { Entry_e39c0* FUN_001fd780(const char*); };
struct Link_e39c0 { char pad[8]; Manager_e39c0* manager; };
struct World { char pad[0x28]; Store* store; char gap[0x10]; Link_e39c0* link; };
extern unsigned DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned);
extern int __cdecl FUN_000964a0(char*, unsigned, const char*, ...);
struct MapThing { char pad[0x118]; int id; Entry_e39c0* vfunc_13(); };
Entry_e39c0* MapThing::vfunc_13() {
 unsigned cookie=DAT_004d9968;
 Lookup_e39c0* lookup=DAT_004dd700->link->manager->FUN_000cae70();
 Test_e39c0* target = lookup->FUN_000c8190(id);
 if (!target) { __security_check_cookie(cookie); return 0; }
 Store* store = DAT_004dd700->store;
 char name[32]; Vec_e39c0 pos;
 for (int i=0x2ca;i<=0x2dd;++i) {
 FUN_000964a0(name,32,"jump_%d_loc",i-0x2c9);
 Entry_e39c0* entry=store->FUN_001fd780(name);
 if(entry && FUN_0022d2b0((char*)target+4,entry->slot8(&pos,0x3727c5ac))) { __security_check_cookie(cookie); return entry; }
 }
 __security_check_cookie(cookie); return 0;
}