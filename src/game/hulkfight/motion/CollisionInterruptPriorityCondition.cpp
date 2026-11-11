// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e550..0x0014e630 (kind game, layer game, confidence medium), dominant class hulkfight::motion::CollisionInterruptPriorityCondition
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa021504 {
#define TREE_TU_END }
namespace fn_fa021504 {} using namespace fn_fa021504;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fa021504 {
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct PrioritySource { int FUN_00036270(); };
struct Intermediate_14e550 { PrioritySource* FUN_00059a30(); };
struct Collision_14e550 { char pad[0x54]; int priority; };
struct Actor_14e550 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Collision_14e550* slot3();
};

} // namespace fn_fa021504

// 0x0014e550 hulkfight::motion::CollisionInterruptPriorityCondition::vfunc_6 (197 B): equivalent/0x0014e550.cpp
// sym: ?vfunc_6@CollisionInterruptPriorityCondition@motion@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 24/24)
// hulkfight::motion::CollisionInterruptPriorityCondition::vfunc_6 @ 0x0014e550
bool hulkfight::motion::CollisionInterruptPriorityCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Actor_14e550 * actor = (Actor_14e550 *)__p1;

 if (!FUN_00344e74(actor, 0, &DAT_00494b44, &DAT_00494b60, 0)) return false;
 Collision_14e550* collision = actor->slot3();
 if (!collision) return false;
 Intermediate_14e550* intermediate = ((Intermediate_14e550 *)((owners::Object_592a0 *)actor)->FUN_000592a0());
 PrioritySource* source = intermediate->FUN_00059a30();
 int priority = collision->priority;
 int other = source->FUN_00036270();
 switch ((*(unsigned int *)&this->f_0c)) {
 case 0: return priority < other;
 case 1: return priority <= other;
 case 2: return priority == other;
 case 3: return priority != other;
 case 4: return priority >= other;
 case 5: return priority > other;
 default: return false;
 }
}

