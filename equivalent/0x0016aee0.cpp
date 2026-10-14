// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0016aee0 @ 0x0016aee0
void* __cdecl FUN_0008d690(unsigned);
__forceinline void* __cdecl operator new(unsigned, void* memory) { return memory; }
extern int DAT_004e11e4, DAT_004e11e0, DAT_00427760, DAT_003f5bb8;
extern char DAT_00427758, DAT_0048f57c;
void FUN_001653b0(); void FUN_001653c0();
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
Entry_16aee0* p=(Entry_16aee0*)FUN_0008d690(32);
if(p) { int count=DAT_00427760; p->FUN_00234cc0("compare"); new(p) Entry_16aee0; p->values=&DAT_00427758; p->count=count; p->callback=FUN_001653b0; }
items[0]=p;
p=(Entry_16aee0*)FUN_0008d690(32);
if(p) { int count=DAT_003f5bb8; p->FUN_00234cc0("motionState"); new(p) Entry_16aee0; p->values=&DAT_0048f57c; p->count=count; p->callback=FUN_001653c0; }
items[1]=p;
FUN_002347b0(&DAT_004e11e0,items,2);
}
++DAT_004e11e4;
}