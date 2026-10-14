// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CAxisSpeedCondition::vfunc_9 @ 0x0004b420
extern bool __cdecl FUN_00018960(float, float, float);
struct AxisInput { char pad[0x20]; float speed; };
struct CAxisSpeedCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(void*, AxisInput*);
 char pad[0xc]; unsigned operation; float threshold;
};
bool CAxisSpeedCondition::vfunc_9(void*, AxisInput* input) {
 float value = input->speed * 57.2957763671875f;
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