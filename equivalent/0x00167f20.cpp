// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityXZCondition::vfunc_6 @ 0x00167f20
extern char DAT_00494b44;
extern char DAT_00494b60;
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Speed_167f20 { float FUN_00035690(); };
struct Motion_167f20 { Speed_167f20* FUN_00059a30(); };
struct Actor_167f20 { Motion_167f20* FUN_000592a0(); };
bool __cdecl FUN_00018960(float, float, float);
namespace hulkfight { namespace motion {
struct VelocityXZCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor_167f20*, void*);
 char pad[8]; unsigned comparison; float threshold;
};
bool VelocityXZCondition::vfunc_6(void*, Actor_167f20* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float speed = actor->FUN_000592a0()->FUN_00059a30()->FUN_00035690();
 switch(comparison) {
 case 0: return speed < threshold;
 case 1: return speed <= threshold;
 case 2: return FUN_00018960(speed,threshold,0.00001f);
 case 3: return !FUN_00018960(speed,threshold,0.00001f);
 case 4: return speed >= threshold;
 case 5: return speed > threshold;
 default: return false;
 }
}
}}
