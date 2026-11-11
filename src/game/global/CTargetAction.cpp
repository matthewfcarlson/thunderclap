// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00017cb0..0x00017e00 (kind game, layer game, confidence medium), dominant class CTargetAction
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc71f465 {
#define TREE_TU_END }
namespace fn_fc71f465 {} using namespace fn_fc71f465;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc71f465 {
struct ThingB {};
struct ThingA {
    ThingB* next_00059a30();
};
struct Start {
};
struct R_17ce0 {
    void call_00222970(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern "C" R_17ce0* __fastcall FUN_00059a40(void*);
struct Entity_17d10;
struct Info_17d10 { char pad[0x74]; void* item; };
struct Entity_17d10 { char pad[0x148]; void* owner; char pad2[0x20b0-0x14c]; int state;   };
struct Target_17d10 { char pad[8]; Entity_17d10* entity; int kind; };
struct Actor_17d10 { char pad[0x328]; Target_17d10* target; unsigned char active; char pad2[7]; void* first; void* second; char pad3[0x1b48-0x33c]; unsigned char flag;  void FUN_000393c0(); };
struct Intermediate_17d10 { Actor_17d10* FUN_00059a30(); };
struct Source_17d10 {  };
struct Manager_17d10 { bool FUN_002edc00(void*); };

} // namespace fn_fc71f465

// 0x00017cb0 CMotionHitGroundHeightAction::vfunc_7 (33 B): matches/0x00017cb0.cpp
// sym: ?vfunc_7@CMotionHitGroundHeightAction@@UAE_NH@Z
bool CMotionHitGroundHeightAction::vfunc_7(int __p0) { unsigned int arg = (unsigned int)__p0;

    ThingA* a = ((ThingA *)((owners::Object_592a0 *)((*(Start * *)&this->f_1c)))->FUN_000592a0());
    ThingB* b = a->next_00059a30();
    *(void**)((char*)b + 0x148) = (*(void * *)&this->f_20);
    return true;
}


// 0x00017ce0 CWallSlideAction::vfunc_4 (37 B): matches/0x00017ce0.cpp
// sym: ?vfunc_4@CWallSlideAction@@UAEXXZ
// Same code shape as 0x00013b40 (propagated; names are from that function)
void CWallSlideAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_17ce0* b = FUN_00059a40(a);
    if (b)
        b->call_00222970((*(void * *)&this->f_24), 0);
}


// 0x00017d10 CTargetAction::vfunc_7 (238 B): equivalent/0x00017d10.cpp
// sym: ?vfunc_7@CTargetAction@@UAE_NH@Z @efa3dde090ac @w507c22cd16bc
// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 36/36)
// CTargetAction::vfunc_7 @ 0x00017d10
bool CTargetAction::vfunc_7(int ) {
 Actor_17d10* actor = ((Intermediate_17d10 *)((owners::Object_592a0 *)((*(Source_17d10 * *)&this->f_1c)))->FUN_000592a0())->FUN_00059a30();
 if (actor->active) {
  Target_17d10* t = actor->target;
  if (!t) return true;
  int kind = t->kind;
  Entity_17d10* e = t->entity;
  bool clear = false;
  if (!kind || !e) clear = true;
  else if (kind == 5) {
   for (int i=0; i<8; ++i) { if (((Entity_17d10 *)((owners::C_35ef0 *)actor)->FUN_00035ef0((hulk_intptr)i))==e) {clear=true; break;} }
   if (!clear) {
    void* owner=e->owner;
    if (owner && (owner==actor->first || owner==actor->second)) clear=true;
    else if (!((owners::Self_1d7450 *)e)->FUN_001d7450()) clear=true;
    else { Info_17d10* info=((Info_17d10 *)((owners::C_1d72e0 *)e)->FUN_001d72e0()); if (!info || !info->item) clear=true; else clear=!(*(Manager_17d10**)&DAT_00554c14)->FUN_002edc00(info->item); }
   }
  } else if (kind == 1) { clear = e==actor->first || e==actor->second || e->state==2; }
  if (!clear) return true;
  actor->FUN_000393c0();
  actor->active=0;
 }
 if (!actor->flag) actor->FUN_000393c0();
 return true;
}

