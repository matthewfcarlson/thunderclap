// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::VelocityXZAngleCondition::vfunc_6 @ 0x00168020
struct TypeInfo_168020 { unsigned int value; }; extern TypeInfo_168020 DAT_00494b60, DAT_00494b44;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo_168020*, TypeInfo_168020*, int);
struct Vec_168020 { float x,y,z; };
struct Motion_168020 { void FUN_00035660(Vec_168020*); void FUN_00035550(Vec_168020*); };
struct ActorPart { Motion_168020* FUN_00059a30(); };
struct Actor_168020 { ActorPart* FUN_000592a0(); };
extern "C" float __cdecl FUN_00224f10(Vec_168020*);
extern "C" float __cdecl FUN_00224fc0(float,float);
namespace hulkfight { namespace motion {
struct VelocityXZAngleCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Actor_168020*,void*);
 char pad[8]; float angle; float width;
};
bool VelocityXZAngleCondition::vfunc_6(void*,Actor_168020* actor,void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Motion_168020* m=actor->FUN_000592a0()->FUN_00059a30();
 Vec_168020 velocity={0.0f,0.0f,0.0f}; m->FUN_00035660(&velocity);
 float a=FUN_00224f10(&velocity);
 Vec_168020 direction={0.0f,0.0f,0.0f}; m->FUN_00035550(&direction);
 float b=FUN_00224f10(&direction);
 float difference=FUN_00224fc0(b,a);
 float delta=FUN_00224fc0(difference,angle);
 union {float f; unsigned int u;} absolute; absolute.f=delta; absolute.u &=0x7fffffff;
 return width*0.5f > absolute.f;
}
}}
