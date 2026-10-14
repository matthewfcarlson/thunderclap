// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 24/24)
// hulkfight::motion::CollisionThrownObjectCondition::vfunc_6 @ 0x0014ed50
typedef unsigned long U32;
struct TypeInfo { U32 value; }; extern TypeInfo DAT_00494b44; extern TypeInfo DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*,int,TypeInfo*,TypeInfo*,int);
struct IdA { unsigned __int64 FUN_000443c0(); };
struct IdB { unsigned __int64 FUN_001d4f70(); };
struct Owner { char pad[0xec]; IdB* b; char pad2[0x2c]; IdA* a; };
struct Thrown { char pad[8]; Owner* owner; int kind; };
struct State { char pad[0x60]; Thrown* thrown; };
struct Params { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State* slot3(); };
namespace hulkfight { namespace motion {
struct CollisionThrownObjectCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(U32,Params*,U32);
char pad[8]; unsigned char expected; char pad2[3]; U32 low; U32 high;
};
bool CollisionThrownObjectCondition::vfunc_6(U32,Params* params,U32) {
if (!FUN_00344e74(params,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
State* state=params->slot3(); if (!state) return false;
Thrown* object=state->thrown;
bool present=object!=0; bool matches=true;
if(object && (low || high)) {
U32 wantLow=low, wantHigh=high;
unsigned __int64 id;
if(object->kind==5) id=object->owner->b->FUN_001d4f70();
else if(object->kind==1 && object->owner->a) id=object->owner->a->FUN_000443c0();
else return expected==present && false;
matches=((U32)id==wantLow && (U32)(id>>32)==wantHigh);
}
return expected==present && matches;
}
} }