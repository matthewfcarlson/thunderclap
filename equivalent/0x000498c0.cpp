// STATUS: equivalent (tools/equiv.py level 3: 3052 inputs, branch coverage 28/28)
// CSmartPropGrabbableNameCondition::vfunc_7 @ 0x000498c0
struct NameSource { char pad[8]; unsigned low, high; unsigned __int64 FUN_001d4f70(); };
struct Object { char pad[0xec]; NameSource* name; };
struct Prop { char pad[8]; Object* object; unsigned type; };
struct Actor { char pad[0x3a4]; Prop* prop; };
struct ContextInner { Actor* FUN_00059a30(); };
struct Context { ContextInner* FUN_000592a0(); void FUN_00059790(Prop*); };
struct CSmartPropGrabbableNameCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned mode; unsigned low, high;
};
bool CSmartPropGrabbableNameCondition::vfunc_7(Context* context) {
 if (!(low | high)) return false;
 Prop* prop = context->FUN_000592a0()->FUN_00059a30()->prop;
 if (!prop || prop->type != 5 || !prop->object) return false;
 if (mode > 1) return false;
 unsigned m = mode;
 NameSource* source = prop->object->name;
 unsigned l = low, h = high;
 bool equal = source->low == l && source->high == h;
 if (!equal) { unsigned __int64 n = source->FUN_001d4f70(); equal = (unsigned)n == l && (unsigned)(n >> 32) == h; }
 if (equal == (m == 0)) { context->FUN_00059790(prop); return true; }
 return false;
}