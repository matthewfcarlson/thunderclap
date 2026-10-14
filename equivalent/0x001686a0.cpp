// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::TurningVelocityCondition::vfunc_6 @ 0x001686a0
extern char DAT_00494b44;
extern char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern bool __cdecl FUN_00018960(float, float, float);
struct Velocity_1686a0 { char pad[0x8c]; float turning; };
struct State_1686a0 { Velocity_1686a0* FUN_00059a30(); };
struct Actor_1686a0 { State_1686a0* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct TurningVelocityCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual bool vfunc_6(void*, Actor_1686a0*, void*);
 char pad[8]; unsigned operation; float threshold;
};
bool TurningVelocityCondition::vfunc_6(void*, Actor_1686a0* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float value = actor->FUN_000592a0()->FUN_00059a30()->turning;
 switch(operation) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value,threshold,0.00001f);
 case 3: return !FUN_00018960(value,threshold,0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}
}}
