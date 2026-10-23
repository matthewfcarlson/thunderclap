// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 19/22, incomplete)
// hulkfight::motion::TargetHealthPercentCondition::vfunc_6 @ 0x00168b30
#include "gen/hulkfight.h"

struct Health { char pad[0x1b0c]; float current; float maximum; };
struct Target_168b30 { char pad[8]; Health* health; int kind; };
struct Actor_168b30 { char pad[0x328]; Target_168b30* target; };
struct ContextActor { Actor_168b30* FUN_00059a30(); };
struct Context_168b30 { ContextActor* FUN_000592a0(); };
extern bool __cdecl FUN_00018960(float, float, float);
namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::TargetHealthPercentCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Context_168b30 * context = (Context_168b30 *)__p1;

 Target_168b30* target = context->FUN_000592a0()->FUN_00059a30()->target;
 if (!target || !target->health || target->kind != 1) return false;
 float maximum = target->health->maximum;
 union { float f; unsigned u; } magnitude;
 magnitude.f = maximum; magnitude.u &= 0x7fffffff;
 float percent;
 if (magnitude.f < 1e-05f) percent = 0.0f;
 else percent = (target->health->current / maximum) * 100.0f;
 switch ((*(unsigned int *)&this->f_0c)) {
 case 0: return percent < this->f_10;
 case 1: return percent <= this->f_10;
 case 2: return FUN_00018960(percent, this->f_10, 1e-05f);
 case 3: return !FUN_00018960(percent, this->f_10, 1e-05f);
 case 4: return percent >= this->f_10;
 case 5: return percent > this->f_10;
 default: return false;
 }
}
