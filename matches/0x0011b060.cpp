#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040eac0[];
extern void* __cdecl Alloc(unsigned int);
class LocatorDistanceCondition_11b060 {
  public:
    LocatorDistanceCondition_11b060(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::LocatorDistanceCondition>::vfunc_5() {
    LocatorDistanceCondition_11b060* p = (LocatorDistanceCondition_11b060*)Alloc(0x14);
    if (p) {
        p->LocatorDistanceCondition_11b060::LocatorDistanceCondition_11b060(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040eac0);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
