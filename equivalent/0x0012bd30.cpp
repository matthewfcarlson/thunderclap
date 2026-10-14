// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::ai::ThreatAngleCondition::vfunc_6 @ 0x0012bd30
struct TypeInfo; extern TypeInfo DAT_00494b44; extern TypeInfo DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
struct Vector { float x,y,z; };
extern float __cdecl FUN_00224f10(Vector*);
extern float __cdecl FUN_00224fc0(float,float);
struct Entity { void FUN_00059a50(Vector*); };
struct Threat_12bd30 { char pad[0x10]; Entity* entity; char pad2[0x22a0-0x14]; Vector position; bool FUN_00037080(void*,unsigned int); float FUN_000354c0(); };
struct Owner_12bd30 { Threat_12bd30* FUN_00059a30(); };
struct Context { Owner_12bd30* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct ThreatAngleCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int,Context*,int);
 char pad[8]; float offset; float width; char pad2[4]; unsigned int selection[2]; unsigned char flag;
};
bool ThreatAngleCondition::vfunc_6(int unused1,Context* context,int unused2) {
 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Threat_12bd30* threat=context->FUN_000592a0()->FUN_00059a30();
 if (!threat->FUN_00037080(selection,flag)) return false;
 Vector target=threat->position;
 Vector origin; origin.x=origin.y=origin.z=0.0f;
 threat->entity->FUN_00059a50(&origin);
 Vector delta; delta.x=target.x-origin.x; delta.y=target.y-origin.y; delta.z=target.z-origin.z;
 float angle=FUN_00224f10(&delta);
 float shifted=threat->FUN_000354c0()+offset;
 angle=FUN_00224fc0(shifted,angle);
 union { float f; unsigned int u; } absolute; absolute.f=angle; absolute.u &= 0x7fffffff;
 return width*0.5f > absolute.f;
}
}}
