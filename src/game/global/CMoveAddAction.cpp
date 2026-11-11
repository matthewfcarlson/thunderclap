// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00014e90..0x00014f50 (kind game, layer game, confidence medium), dominant class CMoveAddAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#define TREE_TU_BEGIN namespace fn_f335f10a {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f335f10a {} using namespace fn_f335f10a;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f335f10a {
struct Vec_14e90 { float x,y,z; };
struct Actor_14e90 { hulk_freg FUN_000354c0(); void FUN_00035720(Vec_14e90*); };
struct HandleResult_14e90 { Actor_14e90* FUN_00059a30(); };
struct Handle_14e90 { HandleResult_14e90* FUN_000592a0(); };
struct Move_14e90 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7();
 char pad[0x10]; float distance; float angle;
};
void __cdecl FUN_00224d70(float, Vec_14e90*);
struct CMoveAddAction {
 char pad[0x1c]; Handle_14e90* handle; Move_14e90* move;
 bool vfunc_7(float dt);
};


// 0x00014e90 CMoveAddAction::vfunc_7 (185 B): equivalent/0x00014e90.cpp
// sym: ?vfunc_7@CMoveAddAction@fn_f335f10a@@QAE_NM@Z @ef6cb52ad618 @w548b3189e824
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 2/2)
// CMoveAddAction::vfunc_7 @ 0x00014e90
bool CMoveAddAction::vfunc_7(float dt) {
 Actor_14e90* actor=handle->FUN_000592a0()->FUN_00059a30();
 float duration=move->slot7();
 if(duration<=0.0f) return false;
 Vec_14e90 v=(*(Vec_14e90*)&DAT_0048e054);
 Move_14e90* m=move;
 double factor=(double)m->distance/duration*dt;
 v.x=(float)(v.x*factor); v.y=(float)(v.y*factor); v.z=(float)(v.z*factor);
 float angle=m->angle;
 hulk_freg heading=actor->FUN_000354c0(); /* st0: added unrounded */
 FUN_00224d70(heading+angle,&v);
 actor->FUN_00035720(&v);
 return true;
}

} // namespace fn_f335f10a
