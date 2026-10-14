// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CLuaNumberCondition::vfunc_7 @ 0x0004cf00
struct LuaState_4cf00 { float FUN_001d2790(void* name); };
bool __cdecl FUN_00018960(float a,float b,float tolerance);
struct CLuaNumberCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(void*);
 char pad04[8]; unsigned operation; char name[64]; float threshold;
 LuaState_4cf00* FUN_001d4c90();
};
bool CLuaNumberCondition::vfunc_7(void*) {
 LuaState_4cf00* state=FUN_001d4c90();
 if(!state) return false;
 float value=state->FUN_001d2790(name);
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
