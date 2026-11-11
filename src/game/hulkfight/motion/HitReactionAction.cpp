// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014f210..0x0014f2f0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::HitReactionAction
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f708d323 {
#define TREE_TU_END }
namespace fn_f708d323 {} using namespace fn_f708d323;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f708d323 {
class Base_14f2e0 {
  public:
    void run();
};

} // namespace fn_f708d323

// 0x0014f210 hulkfight::motion::HitReactionAction::vfunc_3 (199 B): equivalent/0x0014f210.cpp [wrapped: conflict: hulkfight::motion::HitReactionAction]
// sym: ?vfunc_3@HitReactionAction@motion@hulkfight@fn_0014f210@@UAE_NII@Z
namespace fn_0014f210 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// hulkfight::motion::HitReactionAction::vfunc_3 @ 0x0014f210
struct Reaction_14f210; struct State_14f210; struct Stats_14f210 { char pad[0x1d24]; float multiplier; void FUN_000437a0(float,Reaction_14f210*,State_14f210*,unsigned,unsigned); }; struct Intermediate_14f210 { Stats_14f210* FUN_00059a30(); }; struct Actor_14f210 { char pad[12]; unsigned value; Intermediate_14f210* FUN_000592a0(); }; struct Reaction_14f210 { char pad[0x78]; float strength; char tail[0x1c]; void FUN_00059820(); void FUN_00059300(); }; struct State_14f210 { unsigned a; unsigned active; char pad[0x24]; void FUN_002322f0(unsigned,unsigned); bool FUN_00231ee0(); };
// equiv-conv: FUN_0014efd0 ebx esi edi
extern "C" void FUN_0014efd0(Actor_14f210*, void*, Reaction_14f210*);
namespace hulkfight { namespace motion { struct HitReactionAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned,unsigned); virtual void vfunc_4(); virtual void vfunc_5(); char p04[8]; unsigned flags; char p10[12]; void* source; Actor_14f210* actor; State_14f210 state; unsigned saved; bool enabled; }; bool HitReactionAction::vfunc_3(unsigned first,unsigned second) { saved=first; Stats_14f210* stats=actor->FUN_000592a0()->FUN_00059a30(); Reaction_14f210 reaction; reaction.FUN_00059820(); FUN_0014efd0(actor,source,&reaction); reaction.strength*=stats->multiplier; stats->FUN_000437a0(reaction.strength,&reaction,&state,actor->value,0); if(state.active) flags &= ~3u; else flags=(flags & ~2u)|1u; state.FUN_002322f0(saved,second); enabled=true; bool result=state.FUN_00231ee0(); reaction.FUN_00059300(); return result; } } }
} // namespace fn_0014f210


// 0x0014f2e0 hulkfight::motion::HitReactionAction::vfunc_4 (8 B): matches/0x0014f2e0.cpp
// sym: ?vfunc_4@HitReactionAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00147d20 (propagated; names are from that function)
void hulkfight::motion::HitReactionAction::vfunc_4() {
    ((Base_14f2e0*)((char*)this + 0x24))->run();
}

