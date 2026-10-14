// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CInactivityTimerCondition::vfunc_7 @ 0x0004d890
struct State_4d890 { char pad[0x1e48]; float inactivity; };
struct Actor_4d890 { State_4d890* FUN_00059a30(); };
struct Context { Actor_4d890* FUN_000592a0(); };
bool __cdecl FUN_00018960(float, float, float);
struct CInactivityTimerCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned comparison; float threshold;
};
bool CInactivityTimerCondition::vfunc_7(Context* context) {
 State_4d890* state = context->FUN_000592a0()->FUN_00059a30();
 switch(comparison) {
 case 0: return state->inactivity < threshold;
 case 1: return state->inactivity <= threshold;
 case 2: return FUN_00018960(state->inactivity, threshold, 0.00001f);
 case 3: return !FUN_00018960(state->inactivity, threshold, 0.00001f);
 case 4: return state->inactivity >= threshold;
 case 5: return state->inactivity > threshold;
 default: return false;
 }
}