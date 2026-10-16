#include "gen/fight.h"

extern char VT_1aaab0[];
extern void* __cdecl FUN_0008d690(int);
class Sub_1aaab0 {
  public:
    void Init();
};
class Event_PropTypeCondition_1aaab0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    char pad[12];
    Sub_1aaab0 sub;
    Event_PropTypeCondition_1aaab0(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_5() {
    Event_PropTypeCondition_1aaab0* p = (Event_PropTypeCondition_1aaab0*)FUN_0008d690(0x18);
    if (p) {
        p->Event_PropTypeCondition_1aaab0::Event_PropTypeCondition_1aaab0(0);
        *(void**)p = VT_1aaab0;
        p->sub.Init();
        return (void*)(p);
    }
    return (void*)(0);
}
