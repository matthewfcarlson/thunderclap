// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 24/24)
// hulkfight::ai::RandomKeyWordWaitCondition::vfunc_6 @ 0x0010dc30
struct TypeDescriptor;
extern TypeDescriptor DAT_00494b44;
extern TypeDescriptor DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeDescriptor*, TypeDescriptor*, int);
struct State_10dc30 { char pad[0x39c]; int value; };
struct Context { State_10dc30* FUN_00059a30(); };
struct Actor_10dc30 { Context* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct RandomKeyWordWaitCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor_10dc30*, void*);
 char pad[8]; unsigned comparison; int threshold;
};
bool RandomKeyWordWaitCondition::vfunc_6(void*, Actor_10dc30* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_10dc30* state = actor->FUN_000592a0()->FUN_00059a30();
 if (!state) return false;
 int value = state->value;
 switch(comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return value == threshold;
 case 3: return value != threshold;
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}
}}
