// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// MapThing::vfunc_13 @ 0x000e39c0
struct Vec { float x,y,z; };
struct Test { char pad[4]; };
// equiv-conv: FUN_0022d2b0 ecx stack
extern bool __stdcall FUN_0022d2b0(void*,Vec*);
struct Lookup { Test* FUN_000c8190(int); };
struct Manager { Lookup* FUN_000cae70(); };
struct Entry { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual Vec* slot8(Vec*, unsigned); };
struct Store { Entry* FUN_001fd780(const char*); };
struct Link { char pad[8]; Manager* manager; };
struct Global { char pad[0x28]; Store* store; char gap[0x10]; Link* link; };
extern Global* DAT_004dd700;
extern unsigned DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned);
extern int __cdecl FUN_000964a0(char*, unsigned, const char*, ...);
struct MapThing { char pad[0x118]; int id; Entry* vfunc_13(); };
Entry* MapThing::vfunc_13() {
 unsigned cookie=DAT_004d9968;
 Lookup* lookup=DAT_004dd700->link->manager->FUN_000cae70();
 Test* target = lookup->FUN_000c8190(id);
 if (!target) { __security_check_cookie(cookie); return 0; }
 Store* store = DAT_004dd700->store;
 char name[32]; Vec pos;
 for (int i=0x2ca;i<=0x2dd;++i) {
 FUN_000964a0(name,32,"jump_%d_loc",i-0x2c9);
 Entry* entry=store->FUN_001fd780(name);
 if(entry && FUN_0022d2b0((char*)target+4,entry->slot8(&pos,0x3727c5ac))) { __security_check_cookie(cookie); return entry; }
 }
 __security_check_cookie(cookie); return 0;
}