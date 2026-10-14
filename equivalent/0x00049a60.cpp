// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 28/28)
// CSmartPropStateCondition::vfunc_7 @ 0x00049a60
struct State { char pad[0x40]; int value; };
struct Link { char pad[8]; State* state; int type; };
struct Actor { char pad[0x3a4]; Link* link; State* FUN_00035ef0(int); };
struct Owner { Actor* FUN_00059a30(); };
struct Context { Owner* FUN_000592a0(); };
struct CSmartPropStateCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned comparison; int threshold;
};
bool CSmartPropStateCondition::vfunc_7(Context* context) {
 Actor* actor = context->FUN_000592a0()->FUN_00059a30();
 State* state = actor->FUN_00035ef0(0);
 if (!state) {
  Link* link = actor->link;
  if (!link || link->type != 5) return false;
  state = link->state;
  if (!state) return false;
 }
 int value = state->value;
 switch (comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return value == threshold;
 case 3: return value != threshold;
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}
