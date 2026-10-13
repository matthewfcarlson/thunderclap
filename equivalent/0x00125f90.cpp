// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::ai::TargetVelocityYCondition::vfunc_6 @ 0x00125f90
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" bool __cdecl FUN_00018960(float, float, float);
struct Velocity { char pad[0x54]; float y; };
struct Entity { char pad[0x328]; Velocity* velocity; };
struct Controller { Entity* FUN_00059a30(); };
struct Actor { Controller* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct TargetVelocityYCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual bool vfunc_6(void*, Actor*, void*);
 char pad[8]; unsigned comparison; float threshold;
};
bool TargetVelocityYCondition::vfunc_6(void*, Actor* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Entity* entity = actor->FUN_000592a0()->FUN_00059a30();
 if (!entity->velocity) return false;
 float y = entity->velocity->y;
 switch(comparison) {
 case 0: return y < threshold;
 case 1: return y <= threshold;
 case 2: return FUN_00018960(y,threshold,0.00001f);
 case 3: return !FUN_00018960(y,threshold,0.00001f);
 case 4: return y >= threshold;
 case 5: return y > threshold;
 default: return false;
 }
}
} }