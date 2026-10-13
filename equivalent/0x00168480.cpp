// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_6 @ 0x00168480
struct Vec { float x,y,z; };
struct Motion { void FUN_000356c0(Vec*); void FUN_00035550(Vec*); };
struct Controller { Motion* FUN_00059a30(); };
struct Actor { Controller* FUN_000592a0(); };
extern int DAT_00494b44; extern int DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" float __cdecl FUN_00224f10(Vec*);
extern "C" float __cdecl FUN_00224fc0(float,float);
namespace hulkfight { namespace motion {
struct VelocityAnimatedXZAngleCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int,Actor*,int);
char padding[8]; float angle; float tolerance;
};
bool VelocityAnimatedXZAngleCondition::vfunc_6(int, Actor* actor, int) {
if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
Motion* m=actor->FUN_000592a0()->FUN_00059a30();
Vec a; a.x=a.y=a.z=0.0f; m->FUN_000356c0(&a);
float first=FUN_00224f10(&a);
Vec b; b.x=b.y=b.z=0.0f; m->FUN_00035550(&b);
float second=FUN_00224f10(&b);
float delta=FUN_00224fc0(second,first);
float difference=FUN_00224fc0(delta,angle);
union { float f; unsigned int u; } absval; absval.f=difference; absval.u &= 0x7fffffff;
return tolerance*0.5f > absval.f;
}
}}
