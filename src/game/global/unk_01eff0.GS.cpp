// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001eff0..0x0001fab0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#define TREE_TU_BEGIN namespace fn_f41a76ff {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f41a76ff {} using namespace fn_f41a76ff;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f41a76ff {
struct Vec3_1f080 { float x,y,z; };
struct Ref_1f080 { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Prop_1f080 : Ref_1f080 { void FUN_001d6630(const void*); };
struct Transform_1f080 { void FUN_00059a50(Vec3_1f080*); };
struct ActorData { char pad[16]; Transform_1f080* transform; };
struct Actor_1f080 { ActorData* FUN_00059a30(); };
struct Owner_1f080 { Actor_1f080* FUN_000592a0(); };
struct Descriptor_1f080 { char pad[16]; char resource[184]; unsigned int flags[2]; };
struct Manager_1f080 { void FUN_001e5860(char*, const void*, Vec3_1f080); Prop_1f080* FUN_001def30(char*); };
} // namespace fn_f41a76ff
struct World { char pad[12]; Manager_1f080* manager; };
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif
namespace fn_f41a76ff {
struct CSmartPropSpawnAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int); virtual void vfunc_7(); virtual void vfunc_8();
 char pad[24]; Owner_1f080* owner; Descriptor_1f080* descriptor; Prop_1f080* prop;
};


// 0x0001f080 CSmartPropSpawnAction::vfunc_6 (231 B): equivalent/0x0001f080.cpp
// sym: ?vfunc_6@CSmartPropSpawnAction@fn_f41a76ff@@UAE_NH@Z @0a63bdf88e63 @w86eb26595fdf
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 6/6)
// CSmartPropSpawnAction::vfunc_6 @ 0x0001f080
bool CSmartPropSpawnAction::vfunc_6(int) {
 Vec3_1f080 position;
 owner->FUN_000592a0()->FUN_00059a30()->transform->FUN_00059a50(&position);
 char name[32];
 int number=(*(int*)&DAT_004dc018)++;
 sprintf(name,"SpawnedProp%d",number);
 Manager_1f080* manager=DAT_004dd700->manager;
 manager->FUN_001e5860(name,descriptor->resource,position);
 Prop_1f080* spawned=manager->FUN_001def30(name);
 if (!spawned) { return false; }
 if (descriptor->flags[0] | descriptor->flags[1]) spawned->FUN_001d6630(descriptor->flags);
 spawned->vfunc_0();
 if(prop) prop->vfunc_1();
 prop=spawned;
 return true;
}

} // namespace fn_f41a76ff
