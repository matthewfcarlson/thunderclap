// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// CGrappleTimerCondition::vfunc_7 @ 0x0004d710
struct TimerSource { float FUN_0003eca0(void*); };
struct Fighter_4d710 { char pad[0x330]; TimerSource* primary; TimerSource* secondary; char pad2[0x54]; float timer; };
struct Intermediate_4d710 { Fighter_4d710* FUN_00059a30(); };
struct Context { Intermediate_4d710* FUN_000592a0(); };
extern void* DAT_0048f9d4[];
extern bool __cdecl FUN_00018960(float,float,float);
struct CGrappleTimerCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned operation; float threshold; unsigned char dynamic; char pad2[3]; unsigned index;
};
bool CGrappleTimerCondition::vfunc_7(Context* context) {
 Fighter_4d710* fighter=context->FUN_000592a0()->FUN_00059a30();
 float value=threshold;
 if(dynamic) {
 TimerSource* source=fighter->secondary;
 if(!source) source=fighter->primary;
 if(source) { float result=source->FUN_0003eca0(DAT_0048f9d4[index]); value=(result==0.0f)?3.402823466e38f:result; }
 }
 switch(operation) {
 case 0: return fighter->timer < value;
 case 1: return fighter->timer <= value;
 case 2: return FUN_00018960(fighter->timer,value,0.00001f);
 case 3: return !FUN_00018960(fighter->timer,value,0.00001f);
 case 4: return fighter->timer >= value;
 case 5: return fighter->timer > value;
 default: return false;
 }
}