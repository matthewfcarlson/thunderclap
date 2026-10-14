// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityYCondition::vfunc_6 @ 0x00167e20
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00494b44;
extern char DAT_00494b60;
extern bool __cdecl FUN_00018960(float, float, float);
struct Body_167e20 { float FUN_00035680(); };
struct Actor_167e20 { Body_167e20* FUN_00059a30(); };
struct Context { Actor_167e20* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct VelocityYCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[8]; unsigned operation; float threshold;
 virtual bool vfunc_6(void*, Context*, void*);
};
bool VelocityYCondition::vfunc_6(void*, Context* context, void*) {
 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float velocity = context->FUN_000592a0()->FUN_00059a30()->FUN_00035680();
 switch (operation) {
 case 0: return velocity < threshold;
 case 1: return velocity <= threshold;
 case 2: return FUN_00018960(velocity,threshold,0.00001f);
 case 3: return !FUN_00018960(velocity,threshold,0.00001f);
 case 4: return velocity >= threshold;
 case 5: return velocity > threshold;
 default: return false;
 }
}
}}
