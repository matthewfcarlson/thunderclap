// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 24/24)
// hulkfight::motion::CollisionTargetPriorityCondition::vfunc_6 @ 0x0014e910
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" void __cdecl FUN_00096b50(void*, void*, int*);
struct State_14e910 { char pad[0x50]; void* object; };
struct Context { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State_14e910* slot3(); };
namespace hulkfight { namespace motion {
struct CollisionTargetPriorityCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Context*,void*);
 char pad[8]; unsigned comparison; int threshold;
};
bool CollisionTargetPriorityCondition::vfunc_6(void*, Context* context, void*) {
 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_14e910* state=context->slot3();
 if (!state) return false;
 char result[12]; int priority=0;
 FUN_00096b50(state->object,result,&priority);
 switch(comparison) {
 case 0: return priority < threshold;
 case 1: return priority <= threshold;
 case 2: return priority == threshold;
 case 3: return priority != threshold;
 case 4: return priority >= threshold;
 case 5: return priority > threshold;
 default: return false;
 }
}
}}
