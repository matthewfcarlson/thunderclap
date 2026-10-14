// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CAxisValueCondition::vfunc_9 @ 0x0004b520
struct AxisState { char pad[16]; float value; };
bool __cdecl FUN_00018960(float, float, float);
struct CAxisTimeCondition {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual bool vfunc_9(void*, AxisState*);
 char pad[20];
 unsigned comparison;
 float threshold;
};
struct CAxisValueCondition : CAxisTimeCondition { virtual bool vfunc_9(void*, AxisState*); };
bool CAxisValueCondition::vfunc_9(void* arg, AxisState* state) {
 if (!CAxisTimeCondition::vfunc_9(arg,state)) return false;
 switch(comparison) {
 case 0: return state->value < threshold;
 case 1: return state->value <= threshold;
 case 2: return FUN_00018960(state->value,threshold,0.00001f);
 case 3: return !FUN_00018960(state->value,threshold,0.00001f);
 case 4: return state->value >= threshold;
 case 5: return state->value > threshold;
 default: return false;
 }
}