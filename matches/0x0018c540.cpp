#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041916c[];
typedef unsigned int uint;
void* __cdecl Alloc(hulk_uintptr);
struct Base_18c540 {
    void Init(int);
};
struct Sub_18c540 {
    void Setup();
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_5() {
    Base_18c540* p = (Base_18c540*)Alloc(0x20);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041916c);
        ((uint*)p)[3] = 0xffffffff;
        ((uint*)p)[4] = 0;
        ((Sub_18c540*)((char*)p + 0x18))->Setup();
        return (void*)(p);
    }
    return (void*)((void*)0);
}
