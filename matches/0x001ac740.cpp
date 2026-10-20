#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041d40c[];
class Event_1ac740 {
  public:
    void Init(int);
};
void* __cdecl Alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_5() {
    Event_1ac740* p = (Event_1ac740*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((hulk_intptr)DAT_0041d40c);
        *((unsigned char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
