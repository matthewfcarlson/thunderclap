// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a910..0x0016c600 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"


// 0x0016aee0 FUN_0016aee0 (192 B): equivalent/0x0016aee0.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?target@fn_fff8100e@@YAXXZ @3b6f0b7e2a97 @w0efb599e15c6
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_fff8100e {} using namespace fn_fff8100e;
namespace fn_fff8100e {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0016aee0 @ 0x0016aee0

void* __cdecl FUN_0008d690(unsigned);

} // namespace fn_fff8100e
__forceinline void* __cdecl operator new(size_t, void* memory) { return memory; }
namespace fn_fff8100e {

bool SetCompare_001653b0(void*, int); /* (unb5) as defined; address taken only */ bool SetMotionState_001653c0(void*, int); /* (unb5) as defined; address taken only */
namespace hulkfight { namespace motion { class TargetMotionStateCondition; } }
namespace fight { template<class T> struct ParamEnumConstList {
virtual void slot0(); char padding[12]; void* values; int count; void (*callback)(); int tail;
void FUN_00234cc0(const char*);
}; }
typedef fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition> Entry_16aee0;
void __cdecl FUN_002347b0(void*,Entry_16aee0**,int);
void target() {
if (!DAT_004e11e4) {
Entry_16aee0* items[2];
Entry_16aee0* p=(Entry_16aee0*)FUN_0008d690((int)sizeof(Entry_16aee0));
if(p) { int count=(*(int*)&DAT_00427760); p->FUN_00234cc0("compare"); new(p) Entry_16aee0; p->values=((char*)&DAT_00427758); p->count=count; p->callback=(void (*)())SetCompare_001653b0; }
items[0]=p;
p=(Entry_16aee0*)FUN_0008d690((int)sizeof(Entry_16aee0));
if(p) { int count=(*(int*)&DAT_003f5bb8); p->FUN_00234cc0("motionState"); new(p) Entry_16aee0; p->values=((char*)&DAT_0048f57c); p->count=count; p->callback=(void (*)())SetMotionState_001653c0; }
items[1]=p;
FUN_002347b0(((int*)&DAT_004e11e0),items,2);
}
++DAT_004e11e4;
}
} // namespace fn_fff8100e

