// Same code shape as 0x0006fa30 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_16e6b0;
struct Grapple_16e6b0 {
    u32_16e6b0 BuildTrack();
};
extern void* operator new(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::RayCastCondition>::vfunc_5() {
    Grapple_16e6b0* p = (Grapple_16e6b0*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack());
    return (void*)(0);
}
