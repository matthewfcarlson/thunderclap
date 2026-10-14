// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityAnimatedYCondition::vfunc_6 @ 0x00168280
extern char DAT_00494b44, DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern bool __cdecl FUN_00018960(float,float,float);
struct C_168280 { float FUN_000356f0(); };
struct B_168280 { C_168280* FUN_00059a30(); };
struct A_168280 { B_168280* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct VelocityAnimatedYCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, A_168280*, void*);
 char pad[8]; unsigned operation; float threshold;
};
bool VelocityAnimatedYCondition::vfunc_6(void*, A_168280* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float value=actor->FUN_000592a0()->FUN_00059a30()->FUN_000356f0();
 switch(operation) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value,threshold,0.00001f);
 case 3: return !FUN_00018960(value,threshold,0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 }
 return false;
}
}}
