// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityXZCondition::vfunc_6 @ 0x00167f20
#include "gen/hulkfight.h"

extern char DAT_00494b44;
extern char DAT_00494b60;
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Speed_167f20 { float FUN_00035690(); };
struct Motion_167f20 { Speed_167f20* FUN_00059a30(); };
struct Actor_167f20 { Motion_167f20* FUN_000592a0(); };
bool __cdecl FUN_00018960(float, float, float);
namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::VelocityXZCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Actor_167f20 * actor = (Actor_167f20 *)__p1;

 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float speed = actor->FUN_000592a0()->FUN_00059a30()->FUN_00035690();
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return speed < this->f_10;
 case 1: return speed <= this->f_10;
 case 2: return FUN_00018960(speed,this->f_10,0.00001f);
 case 3: return !FUN_00018960(speed,this->f_10,0.00001f);
 case 4: return speed >= this->f_10;
 case 5: return speed > this->f_10;
 default: return false;
 }
}
