// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e910..0x0014ea20 (kind game, layer game, confidence medium), dominant class hulkfight::motion::CollisionTargetPriorityCondition
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f2efbb64 {
#define TREE_TU_END }
namespace fn_f2efbb64 {} using namespace fn_f2efbb64;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2efbb64 {
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" void __cdecl FUN_00096b50(void*, void*, int*);
struct State_14e910 { char pad[0x50]; void* object; };
struct Context_14e910 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State_14e910* slot3(); };

} // namespace fn_f2efbb64

// 0x0014e910 hulkfight::motion::CollisionTargetPriorityCondition::vfunc_6 (248 B): equivalent/0x0014e910.cpp
// sym: ?vfunc_6@CollisionTargetPriorityCondition@motion@hulkfight@@UAE_NPAX00@Z @cfb8d2d6310f @w42cc6512a6f3
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 24/24)
// hulkfight::motion::CollisionTargetPriorityCondition::vfunc_6 @ 0x0014e910
bool hulkfight::motion::CollisionTargetPriorityCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Context_14e910 * context = (Context_14e910 *)__p1;

 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_14e910* state=context->slot3();
 if (!state) return false;
 char result[12]; int priority=0;
 FUN_00096b50(state->object,result,&priority);
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return priority < this->f_10;
 case 1: return priority <= this->f_10;
 case 2: return priority == this->f_10;
 case 3: return priority != this->f_10;
 case 4: return priority >= this->f_10;
 case 5: return priority > this->f_10;
 default: return false;
 }
}

