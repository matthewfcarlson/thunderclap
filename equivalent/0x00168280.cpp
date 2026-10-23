// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityAnimatedYCondition::vfunc_6 @ 0x00168280
#include "gen/hulkfight.h"

extern char DAT_00494b44, DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern bool __cdecl FUN_00018960(float,float,float);
struct C_168280 { float FUN_000356f0(); };
struct B_168280 { C_168280* FUN_00059a30(); };
struct A_168280 { B_168280* FUN_000592a0(); };
namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::VelocityAnimatedYCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { A_168280 * actor = (A_168280 *)__p1;

 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float value=actor->FUN_000592a0()->FUN_00059a30()->FUN_000356f0();
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return value < this->f_10;
 case 1: return value <= this->f_10;
 case 2: return FUN_00018960(value,this->f_10,0.00001f);
 case 3: return !FUN_00018960(value,this->f_10,0.00001f);
 case 4: return value >= this->f_10;
 case 5: return value > this->f_10;
 }
 return false;
}
