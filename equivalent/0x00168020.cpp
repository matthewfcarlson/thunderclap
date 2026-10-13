// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::VelocityXZAngleCondition::vfunc_6 @ 0x00168020
struct TypeInfo { unsigned int value; }; extern TypeInfo DAT_00494b60, DAT_00494b44;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
struct Vec { float x,y,z; };
struct Motion { void FUN_00035660(Vec*); void FUN_00035550(Vec*); };
struct ActorPart { Motion* FUN_00059a30(); };
struct Actor { ActorPart* FUN_000592a0(); };
extern "C" float __cdecl FUN_00224f10(Vec*);
extern "C" float __cdecl FUN_00224fc0(float,float);
namespace hulkfight { namespace motion {
struct VelocityXZAngleCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Actor*,void*);
 char pad[8]; float angle; float width;
};
bool VelocityXZAngleCondition::vfunc_6(void*,Actor* actor,void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Motion* m=actor->FUN_000592a0()->FUN_00059a30();
 Vec velocity={0.0f,0.0f,0.0f}; m->FUN_00035660(&velocity);
 float a=FUN_00224f10(&velocity);
 Vec direction={0.0f,0.0f,0.0f}; m->FUN_00035550(&direction);
 float b=FUN_00224f10(&direction);
 float difference=FUN_00224fc0(b,a);
 float delta=FUN_00224fc0(difference,angle);
 union {float f; unsigned int u;} absolute; absolute.f=delta; absolute.u &=0x7fffffff;
 return width*0.5f > absolute.f;
}
}}
