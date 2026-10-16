// Same code shape as 0x0006f850 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_122d30;
struct Grapple_122d30 {
    u32_122d30 ctor();
};
extern void* __cdecl Alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::PathLocatorTestCondition>::vfunc_5() {
    Grapple_122d30* p = (Grapple_122d30*)Alloc(0x2c);
    if (p)
        return (void*)(p->ctor());
    return (void*)(0);
}
