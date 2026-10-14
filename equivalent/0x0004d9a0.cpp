// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CCharacterFloatCondition::vfunc_7 @ 0x0004d9a0
struct Character { float get(); };
struct Handle { Character* FUN_00059a30(); };
struct Context { Handle* FUN_000592a0(); };
extern bool __cdecl FUN_00018960(float, float, float);
struct CCharacterFloatCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8];
 float (Character::*getter)();
 unsigned comparison;
 float threshold;
};
bool CCharacterFloatCondition::vfunc_7(Context* context) {
 Character* character = context->FUN_000592a0()->FUN_00059a30();
 float value = (character->*getter)();
 switch(comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value, threshold, 0.00001f);
 case 3: return !FUN_00018960(value, threshold, 0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}