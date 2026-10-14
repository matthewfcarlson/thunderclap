// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CButtonValueCondition::vfunc_9 @ 0x0004b1e0
struct Input_4b1e0 { char pad[8]; float value; };
extern bool __cdecl FUN_00018960(float, float, float);
struct CButtonCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
 virtual bool vfunc_9(Input_4b1e0*);
 char pad[20];
};
struct CButtonValueCondition : CButtonCondition {
 unsigned comparison;
 float threshold;
 virtual bool vfunc_9(Input_4b1e0*);
};
bool CButtonValueCondition::vfunc_9(Input_4b1e0* input) {
 if (!CButtonCondition::vfunc_9(input)) return false;
 switch (comparison) {
 case 0: return input->value < threshold;
 case 1: return input->value <= threshold;
 case 2: return FUN_00018960(input->value, threshold, 0.00001f);
 case 3: return !FUN_00018960(input->value, threshold, 0.00001f);
 case 4: return input->value >= threshold;
 case 5: return input->value > threshold;
 default: return false;
 }
}
