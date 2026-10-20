#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" void _ReadWriteBarrier();
class Child {
  public:
    Child(int);
};
class Sub {
  public:
    Sub();
};
extern char VT_12b100[];
extern void* __cdecl FUN_0008d690(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetArcCondition>::vfunc_5() {
    Child* p = (Child*)FUN_0008d690(0x30);
    if (p) {
        p->Child::Child(0);
        *(void**)p = VT_12b100;
        *(int*)((char*)p + 0xc) = 0;
        *(float*)((char*)p + 0x10) = 1.5707964f;
        *(char*)((char*)p + 0x14) = 0;
        ((Sub*)((char*)p + 0x18))->Sub::Sub();
        *(int*)((char*)p + 0x20) = 0;
        *(int*)((char*)p + 0x24) = 0;
        *(float*)((char*)p + 0x28) = -1.0f;
        _ReadWriteBarrier();
        *(char*)((char*)p + 0x2c) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
