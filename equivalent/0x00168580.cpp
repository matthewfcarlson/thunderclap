// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::motion::ChargeCondition::vfunc_6 @ 0x00168580
extern "C" { extern char DAT_00494b44; extern char DAT_00494b60; void* __cdecl FUN_00344e74(void*, int, void*, void*, int); bool __cdecl FUN_00018960(float,float,float); }
struct State_168580 { char pad[0x1e58]; float charge; int kind; };
struct Intermediate_168580 { State_168580* FUN_00059a30(); };
struct Actor_168580 { Intermediate_168580* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct ChargeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor_168580*, void*);
 char pad[8]; unsigned operation; float threshold; int kind;
};
bool ChargeCondition::vfunc_6(void*, Actor_168580* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_168580* state=actor->FUN_000592a0()->FUN_00059a30();
 float value=state->charge;
 if (kind!=state->kind) value=0.0f;
 switch(operation) {
 case 0: return value<threshold;
 case 1: return value<=threshold;
 case 2: return FUN_00018960(value,threshold,0.00001f);
 case 3: return !FUN_00018960(value,threshold,0.00001f);
 case 4: return value>=threshold;
 case 5: return value>threshold;
 default: return false;
 }
}
} }
