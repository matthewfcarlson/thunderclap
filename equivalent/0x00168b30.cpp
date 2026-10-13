// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 19/22, incomplete)
// hulkfight::motion::TargetHealthPercentCondition::vfunc_6 @ 0x00168b30
struct Health { char pad[0x1b0c]; float current; float maximum; };
struct Target { char pad[8]; Health* health; int kind; };
struct Actor { char pad[0x328]; Target* target; };
struct ContextActor { Actor* FUN_00059a30(); };
struct Context { ContextActor* FUN_000592a0(); };
extern bool __cdecl FUN_00018960(float, float, float);
namespace hulkfight { namespace motion {
struct TargetHealthPercentCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual bool vfunc_6(void*, Context*, void*);
 char pad[8]; unsigned comparison; float threshold;
};
bool TargetHealthPercentCondition::vfunc_6(void*, Context* context, void*) {
 Target* target = context->FUN_000592a0()->FUN_00059a30()->target;
 if (!target || !target->health || target->kind != 1) return false;
 float maximum = target->health->maximum;
 union { float f; unsigned u; } magnitude;
 magnitude.f = maximum; magnitude.u &= 0x7fffffff;
 float percent;
 if (magnitude.f < 1e-05f) percent = 0.0f;
 else percent = (target->health->current / maximum) * 100.0f;
 switch (comparison) {
 case 0: return percent < threshold;
 case 1: return percent <= threshold;
 case 2: return FUN_00018960(percent, threshold, 1e-05f);
 case 3: return !FUN_00018960(percent, threshold, 1e-05f);
 case 4: return percent >= threshold;
 case 5: return percent > threshold;
 default: return false;
 }
}
}}
