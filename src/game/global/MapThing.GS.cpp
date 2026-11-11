// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e36a0..0x000e3ac0 (kind game, layer game, confidence high), dominant class MapThing
#include "tree_prelude.h"
#include "decls/address.h"
#define TREE_TU_BEGIN namespace fn_f9d36b1d {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9d36b1d {} using namespace fn_f9d36b1d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9d36b1d {
struct Vec_e39c0 { float x,y,z; };
struct Test_e39c0 { char pad[4]; };
struct ThisNote_0022d2b0 {
    bool FUN_0022d2b0(Vec_e39c0*, unsigned);
};
struct Lookup_e39c0 { Test_e39c0* FUN_000c8190(int); };
struct Manager_e39c0 { Lookup_e39c0* FUN_000cae70(); };
struct Entry_e39c0 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual Vec_e39c0* slot8(Vec_e39c0*); };
struct Store { Entry_e39c0* FUN_001fd780(const char*); };
struct Link_e39c0 { char pad[8]; Manager_e39c0* manager; };
} // namespace fn_f9d36b1d
struct World { char pad[0x28]; Store* store; char gap[0x10]; Link_e39c0* link; };
namespace fn_f9d36b1d {
extern int __cdecl FUN_000964a0(char*, unsigned, const char*, ...);
struct MapThing { char pad[0x118]; int id; Entry_e39c0* vfunc_13(); };


// 0x000e39c0 MapThing::vfunc_13 (204 B): equivalent/0x000e39c0.cpp
// sym: ?vfunc_13@MapThing@fn_f9d36b1d@@QAEPAUEntry_e39c0@2@XZ
// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 7/8, incomplete)
// MapThing::vfunc_13 @ 0x000e39c0
// MapThing::vfunc_13 @ 0x000e39c0
Entry_e39c0* MapThing::vfunc_13() {
 Lookup_e39c0* lookup=DAT_004dd700->link->manager->FUN_000cae70();
 Test_e39c0* target = lookup->FUN_000c8190(id);
 if (!target) { return 0; }
 Store* store = DAT_004dd700->store;
 char name[32]; Vec_e39c0 pos;
 for (int i=0x2ca;i<=0x2dd;++i) {
 FUN_000964a0(name,32,"jump_%d_loc",i-0x2c9);
 Entry_e39c0* entry=store->FUN_001fd780(name);
 if(entry && ((ThisNote_0022d2b0*)((char*)target+4))->FUN_0022d2b0(entry->slot8(&pos),0x3727c5ac)) { return entry; }
 }
  return 0;
}

} // namespace fn_f9d36b1d
