// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115e20..0x00115ed0 (kind game, layer game, confidence medium), dominant class hulkfight::ai::MotionFacingAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa598c1c {
#define TREE_TU_END }
namespace fn_fa598c1c {} using namespace fn_fa598c1c;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fa598c1c {
struct Vector_115e20 { float x,y,z; hulk_freg FUN_0022d110(); };
struct Actor_115e20 { char pad[0x2064]; Vector_115e20 facing; float rate; };
struct HandleResult_115e20 { Actor_115e20* FUN_00059a30(); };
struct Handle_115e20 {  };
struct Settings_115e20 { char pad[0x14]; float angle; Vector_115e20 direction; float rate; };
struct Heading_115e20 { hulk_freg FUN_000354c0(); };
void __cdecl FUN_00224d70(float, Vector_115e20*);

} // namespace fn_fa598c1c

// 0x00115e20 hulkfight::ai::MotionFacingAction::vfunc_5 (173 B): equivalent/0x00115e20.cpp
// sym: ?vfunc_5@MotionFacingAction@ai@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19976 inputs, branch coverage 4/4)
// hulkfight::ai::MotionFacingAction::vfunc_5 @ 0x00115e20
bool hulkfight::ai::MotionFacingAction::vfunc_5(hulk_intptr phase, int unused) {
if (phase != 0) return true;
if (!(*(Handle_115e20 * *)&this->f_20)) return false;
Actor_115e20* actor = ((HandleResult_115e20 *)((owners::Object_592a0 *)((*(Handle_115e20 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
Vector_115e20 direction = (*(Settings_115e20 * *)&this->f_1c)->direction;
float angle = (*(Settings_115e20 * *)&this->f_1c)->angle;
FUN_00224d70(((Heading_115e20*)actor)->FUN_000354c0() + angle, &direction);
direction.FUN_0022d110();
actor->facing = direction;
actor->rate = (*(Settings_115e20 * *)&this->f_1c)->rate;
return true;
}

