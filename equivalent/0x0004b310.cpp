// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CAxisTimeCondition::vfunc_9 @ 0x0004b310
extern bool __cdecl FUN_00018960(float, float, float);
struct AxisInput_4b310 { int unknown; float time; };
struct CAxisTimeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(int, AxisInput_4b310*); virtual bool FUN_00344f51(AxisInput_4b310*, float*);
 char pad[12]; unsigned comparison; float threshold;
};
bool CAxisTimeCondition::vfunc_9(int unused, AxisInput_4b310* input) {
 float value=input->time;
 if(!FUN_00344f51(input,&value)) return false;
 switch(comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value,threshold,0.00001f);
 case 3: return !FUN_00018960(value,threshold,0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}