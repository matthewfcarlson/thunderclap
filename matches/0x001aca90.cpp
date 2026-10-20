#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041d48c[];
extern void* __cdecl Allocate(unsigned int);
class Thing_1aca90 {
  public:
    void Init(int);
};
class Sub_1aca90 {
  public:
    void Finish();
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PathNameCondition>::vfunc_5() {
    Thing_1aca90* p = (Thing_1aca90*)Allocate(24);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041d48c);
        *(unsigned int*)((char*)p + 12) = 0;
        ((Sub_1aca90*)((char*)p + 16))->Finish();
        return (void*)(p);
    }
    return (void*)(0);
}
