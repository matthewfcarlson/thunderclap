// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014ed50..0x0014ee00 (kind game, layer game, confidence medium), dominant class hulkfight::motion::CollisionThrownObjectCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f0a5d923 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0a5d923 {} using namespace fn_f0a5d923;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0a5d923 {
typedef unsigned long U32_14ed50;
struct TypeInfo_14ed50 { U32_14ed50 value; };
extern TypeInfo_14ed50 DAT_00494b44;
extern TypeInfo_14ed50 DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*,int,TypeInfo_14ed50*,TypeInfo_14ed50*,int);
struct IdA { unsigned __int64 FUN_000443c0(); };
struct IdB { unsigned __int64 FUN_001d4f70(); };
struct Owner_14ed50 { char pad[0xec]; IdB* b; char pad2[0x2c]; IdA* a; };
struct Thrown { char pad[8]; Owner_14ed50* owner; int kind; };
struct State_14ed50 { char pad[0x60]; Thrown* thrown; };
struct Params { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State_14ed50* slot3(); };
namespace hulkfight { namespace motion {
struct CollisionThrownObjectCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(U32_14ed50,Params*,U32_14ed50);
char pad[8]; unsigned char expected; char pad2[3]; U32_14ed50 low; U32_14ed50 high;
};
} }


// 0x0014ed50 hulkfight::motion::CollisionThrownObjectCondition::vfunc_6 (172 B): equivalent/0x0014ed50.cpp
// sym: ?vfunc_6@CollisionThrownObjectCondition@motion@hulkfight@fn_f0a5d923@@UAE_NKPAUParams@4@K@Z @6add8800de5b @wfb378770b590
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 24/24)
// hulkfight::motion::CollisionThrownObjectCondition::vfunc_6 @ 0x0014ed50
namespace hulkfight { namespace motion {
bool CollisionThrownObjectCondition::vfunc_6(U32_14ed50,Params* params,U32_14ed50) {
if (!FUN_00344e74(params,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
State_14ed50* state=params->slot3(); if (!state) return false;
Thrown* object=state->thrown;
bool present=object!=0; bool matches=true;
if(object && (low || high)) {
U32_14ed50 wantLow=low, wantHigh=high;
unsigned __int64 id;
if(object->kind==5) id=object->owner->b->FUN_001d4f70();
else if(object->kind==1 && object->owner->a) id=object->owner->a->FUN_000443c0();
else return expected==present && false;
matches=((U32_14ed50)id==wantLow && (U32_14ed50)(id>>32)==wantHigh);
}
return expected==present && matches;
}
} }

} // namespace fn_f0a5d923
