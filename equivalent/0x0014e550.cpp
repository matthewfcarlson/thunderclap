// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 24/24)
// hulkfight::motion::CollisionInterruptPriorityCondition::vfunc_6 @ 0x0014e550
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct PrioritySource { int FUN_00036270(); };
struct Intermediate { PrioritySource* FUN_00059a30(); };
struct Collision { char pad[0x54]; int priority; };
struct Actor {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Collision* slot3();
 Intermediate* FUN_000592a0();
};
namespace hulkfight { namespace motion {
struct CollisionInterruptPriorityCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual bool vfunc_6(void*, Actor*, void*);
 char pad[8]; unsigned int comparison;
};
bool CollisionInterruptPriorityCondition::vfunc_6(void*, Actor* actor, void*) {
 if (!FUN_00344e74(actor, 0, &DAT_00494b44, &DAT_00494b60, 0)) return false;
 Collision* collision = actor->slot3();
 if (!collision) return false;
 Intermediate* intermediate = actor->FUN_000592a0();
 PrioritySource* source = intermediate->FUN_00059a30();
 int priority = collision->priority;
 int other = source->FUN_00036270();
 switch (comparison) {
 case 0: return priority < other;
 case 1: return priority <= other;
 case 2: return priority == other;
 case 3: return priority != other;
 case 4: return priority >= other;
 case 5: return priority > other;
 default: return false;
 }
}
} }
