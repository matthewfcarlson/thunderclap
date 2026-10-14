// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CIntentionSpeedCondition::vfunc_7 @ 0x0004db20
struct SpeedData { char pad[0x2070]; float speed; };
struct SpeedOwner { SpeedData* FUN_00059a30(); };
struct Context { SpeedOwner* FUN_000592a0(); };
extern bool __cdecl FUN_00018960(float, float, float);
struct CIntentionSpeedCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned operation; float threshold;
};
bool CIntentionSpeedCondition::vfunc_7(Context* context) {
 float speed = context->FUN_000592a0()->FUN_00059a30()->speed;
 switch(operation) {
 case 0: return speed < threshold;
 case 1: return speed <= threshold;
 case 2: return FUN_00018960(speed, threshold, 0.00001f);
 case 3: return !FUN_00018960(speed, threshold, 0.00001f);
 case 4: return speed >= threshold;
 case 5: return speed > threshold;
 default: return false;
 }
}
