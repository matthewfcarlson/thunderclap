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
extern char VT_16e520[];
extern void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_5() {
    Child* p = (Child*)FUN_0008d690(0x38);
    if (p) {
        p->Child::Child(0);
        *(void**)p = VT_16e520;
        ((Sub*)((char*)p + 0x10))->Sub::Sub();
        *(int*)((char*)p + 0x18) = 0;
        *(int*)((char*)p + 0x1c) = 0;
        *(int*)((char*)p + 0x20) = 0;
        *(int*)((char*)p + 0x24) = 0;
        *(int*)((char*)p + 0x28) = 0;
        *(float*)((char*)p + 0x2c) = -1.0f;
        _ReadWriteBarrier();
        *(float*)((char*)p + 0x30) = 1.0f;
        *(char*)((char*)p + 0x34) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
