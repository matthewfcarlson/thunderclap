// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 30/30)
// hulkfight::motion::PropStateByIndexCondition::vfunc_6 @ 0x00181900
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Prop_181900 { char pad[0x40]; int state; };
struct Collection_181900 { char pad[0x128]; Prop_181900* current; Prop_181900* FUN_00035ef0(int); };
struct Actor_181900 { Collection_181900* FUN_00059a30(); };
struct Context { Actor_181900* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct PropStateByIndexCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Context*, void*);
 char pad[8]; int index; unsigned operation; int expected;
};
bool PropStateByIndexCondition::vfunc_6(void*, Context* context, void*) {
 if (!FUN_00344e74(context, 0, &DAT_00494b44, &DAT_00494b60, 0)) return false;
 Actor_181900* actor = context->FUN_000592a0();
 Collection_181900* collection = actor->FUN_00059a30();
 if (!collection) return false;
 Prop_181900* prop;
 if (index < 0) prop = collection->current;
 else { if (index >= 8) return false; prop = collection->FUN_00035ef0(index); }
 if (!prop) return false;
 int value = prop->state;
 switch (operation) {
 case 0: return value < expected;
 case 1: return value <= expected;
 case 2: return value == expected;
 case 3: return value != expected;
 case 4: return value >= expected;
 case 5: return value > expected;
 default: return false;
 }
}
}}