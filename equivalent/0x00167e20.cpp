// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityYCondition::vfunc_6 @ 0x00167e20
#include "gen/hulkfight.h"

extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00494b44;
extern char DAT_00494b60;
extern bool __cdecl FUN_00018960(float, float, float);
struct Body_167e20 { float FUN_00035680(); };
struct Actor_167e20 { Body_167e20* FUN_00059a30(); };
struct Context_167e20 { Actor_167e20* FUN_000592a0(); };
namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::VelocityYCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Context_167e20 * context = (Context_167e20 *)__p1;

 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float velocity = context->FUN_000592a0()->FUN_00059a30()->FUN_00035680();
 switch ((*(unsigned int *)&this->f_0c)) {
 case 0: return velocity < this->f_10;
 case 1: return velocity <= this->f_10;
 case 2: return FUN_00018960(velocity,this->f_10,0.00001f);
 case 3: return !FUN_00018960(velocity,this->f_10,0.00001f);
 case 4: return velocity >= this->f_10;
 case 5: return velocity > this->f_10;
 default: return false;
 }
}
