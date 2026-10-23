// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CStageCondition::vfunc_7 @ 0x00048350
#include "gen/global.h"

struct Stage_48350 { char pad[0x1e44]; int value; };
struct Context_48350 { Stage_48350* FUN_00059a30(); };
struct Argument_48350 { Context_48350* FUN_000592a0(); };

bool CStageCondition::vfunc_7(void* __p0) { Argument_48350 * arg = (Argument_48350 *)__p0;

 Stage_48350* stage = arg->FUN_000592a0()->FUN_00059a30();
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return stage->value < this->f_10;
 case 1: return stage->value <= this->f_10;
 case 2: return stage->value == this->f_10;
 case 3: return stage->value != this->f_10;
 case 4: return stage->value >= this->f_10;
 case 5: return stage->value > this->f_10;
 default: return false;
 }
}
