// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// hulkfight::ai::MotionFacingAction::vfunc_5 @ 0x00115e20
#include "gen/hulkfight.h"

struct Vector_115e20 { float x,y,z; float FUN_0022d110(); };
struct Actor_115e20 { char pad[0x2064]; Vector_115e20 facing; float rate; };
struct HandleResult_115e20 { Actor_115e20* FUN_00059a30(); };
struct Handle_115e20 { HandleResult_115e20* FUN_000592a0(); };
struct Settings_115e20 { char pad[0x14]; float angle; Vector_115e20 direction; float rate; };
// equiv-conv: FUN_000354c0 ecx stack
float __cdecl FUN_000354c0(Actor_115e20*, Vector_115e20*);
void __cdecl FUN_00224d70(float, Vector_115e20*);
namespace hulkfight { namespace ai {

}}
bool hulkfight::ai::MotionFacingAction::vfunc_5(int phase, int unused) {
if (phase != 0) return true;
if (!(*(Handle_115e20 * *)&this->f_20)) return false;
Actor_115e20* actor = (*(Handle_115e20 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
Vector_115e20 direction = (*(Settings_115e20 * *)&this->f_1c)->direction;
float angle = (*(Settings_115e20 * *)&this->f_1c)->angle;
FUN_00224d70(FUN_000354c0(actor, &direction) + angle, &direction);
direction.FUN_0022d110();
actor->facing = direction;
actor->rate = (*(Settings_115e20 * *)&this->f_1c)->rate;
return true;
}
