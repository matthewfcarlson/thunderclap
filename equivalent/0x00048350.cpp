// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CStageCondition::vfunc_7 @ 0x00048350
struct Stage_48350 { char pad[0x1e44]; int value; };
struct Context { Stage_48350* FUN_00059a30(); };
struct Argument_48350 { Context* FUN_000592a0(); };
struct CStageCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Argument_48350* arg);
 char pad[8]; unsigned comparison; int threshold;
};
bool CStageCondition::vfunc_7(Argument_48350* arg) {
 Stage_48350* stage = arg->FUN_000592a0()->FUN_00059a30();
 switch(comparison) {
 case 0: return stage->value < threshold;
 case 1: return stage->value <= threshold;
 case 2: return stage->value == threshold;
 case 3: return stage->value != threshold;
 case 4: return stage->value >= threshold;
 case 5: return stage->value > threshold;
 default: return false;
 }
}