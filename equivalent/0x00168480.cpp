// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_6 @ 0x00168480
#include "gen/hulkfight.h"

struct Vec_168480 { float x,y,z; };
struct Motion_168480 { void FUN_000356c0(Vec_168480*); void FUN_00035550(Vec_168480*); };
struct Controller_168480 { Motion_168480* FUN_00059a30(); };
struct Actor_168480 { Controller_168480* FUN_000592a0(); };
extern int DAT_00494b44; extern int DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" float __cdecl FUN_00224f10(Vec_168480*);
extern "C" float __cdecl FUN_00224fc0(float,float);
namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Actor_168480 * actor = (Actor_168480 *)__p1;

if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
Motion_168480* m=actor->FUN_000592a0()->FUN_00059a30();
Vec_168480 a; a.x=a.y=a.z=0.0f; m->FUN_000356c0(&a);
float first=FUN_00224f10(&a);
Vec_168480 b; b.x=b.y=b.z=0.0f; m->FUN_00035550(&b);
float second=FUN_00224f10(&b);
float delta=FUN_00224fc0(second,first);
float difference=FUN_00224fc0(delta,this->f_0c);
union { float f; unsigned int u; } absval; absval.f=difference; absval.u &= 0x7fffffff;
return this->f_10*0.5f > absval.f;
}
