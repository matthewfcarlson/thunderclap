// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionStunTimeCondition::vfunc_7 @ 0x0004c580
struct State_4c580 { char pad[0x68]; float stunTime; };
struct Context { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State_4c580* slot3(); };
extern bool __cdecl FUN_00018960(float, float, float);
struct CCollisionStunTimeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned operation; float threshold;
};
bool CCollisionStunTimeCondition::vfunc_7(Context* context) {
 State_4c580* state = context->slot3();
 if (!state) return false;
 float time = state->stunTime;
 switch (operation) {
 case 0: return time < threshold;
 case 1: return time <= threshold;
 case 2: return FUN_00018960(time, threshold, 0.00001f);
 case 3: return !FUN_00018960(time, threshold, 0.00001f);
 case 4: return time >= threshold;
 case 5: return time > threshold;
 default: return false;
 }
}