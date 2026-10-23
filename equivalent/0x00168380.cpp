// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityAnimatedXZCondition::vfunc_6 @ 0x00168380
#include "gen/hulkfight.h"

extern int DAT_00494b44;
extern int DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern bool __cdecl FUN_00018960(float,float,float);
struct Speed_168380 { float FUN_00035700(); };
struct Motion_168380 { Speed_168380* FUN_00059a30(); };
struct Actor_168380 { Motion_168380* FUN_000592a0(); };
namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::VelocityAnimatedXZCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Actor_168380 * actor = (Actor_168380 *)__p1;

 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float speed=actor->FUN_000592a0()->FUN_00059a30()->FUN_00035700();
 switch((*(unsigned int *)&this->f_0c)) {
 case 0:return speed<this->f_10;
 case 1:return speed<=this->f_10;
 case 2:return FUN_00018960(speed,this->f_10,0.00001f);
 case 3:return !FUN_00018960(speed,this->f_10,0.00001f);
 case 4:return speed>=this->f_10;
 case 5:return speed>this->f_10;
 }
 return false;
}
