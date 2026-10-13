// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::motion::HealthPercentCondition::vfunc_6 @ 0x00168930
extern char DAT_00494b44;
extern char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern bool __cdecl FUN_00018960(float, float, float);
struct Health { char pad[0x1b0c]; float current; float maximum; };
struct Component { Health* FUN_00059a30(); };
struct Actor { Component* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct HealthPercentCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor*, void*);
char pad[8]; unsigned comparison; float threshold;
};
bool HealthPercentCondition::vfunc_6(void*, Actor* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Health* health = actor->FUN_000592a0()->FUN_00059a30();
 union { float f; unsigned bits; } magnitude;
 magnitude.f = health->maximum; magnitude.bits &= 0x7fffffff;
 float percent = 0.0f;
 if (!(magnitude.f < 1e-5f)) percent = (health->current / health->maximum) * 100.0f;
 switch(comparison) {
 case 0: return percent < threshold;
 case 1: return percent <= threshold;
 case 2: return FUN_00018960(percent,threshold,1e-5f);
 case 3: return !FUN_00018960(percent,threshold,1e-5f);
 case 4: return percent >= threshold;
 case 5: return percent > threshold;
 default: return false;
 }
}
}}
