// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 20/20)
// hulkfight::motion::InterruptAccumulatorCondition::vfunc_6 @ 0x001508d0
extern char DAT_00494b44, DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern bool __cdecl FUN_00018960(float,float,float);
struct Accumulator { char pad[0x1a8]; float maximum; };
struct State { char pad[0x11c]; Accumulator* accumulator; char pad2[0x200]; float current; };
struct Actor { State* FUN_00059a30(); };
struct Context { Actor* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct InterruptAccumulatorCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Context*,void*);
 char pad[8]; unsigned operation; float threshold;
};
bool InterruptAccumulatorCondition::vfunc_6(void*, Context* context, void*) {
 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State* state = context->FUN_000592a0()->FUN_00059a30();
 if (!state->accumulator) return false;
 float value = 0.0f;
 if (state->accumulator->maximum > 0.0f) value = state->current / state->accumulator->maximum * 100.0f;
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
