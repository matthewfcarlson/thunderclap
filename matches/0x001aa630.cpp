#include "gen/fight.h"

extern "C" char DAT_0041c550[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Event_1aa630 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    void Init(int);
    int a;
    int b;
    int c;
    int d;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_5() {
    Event_1aa630* p = (Event_1aa630*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041c550);
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)((Event_1aa630*)0);
}
