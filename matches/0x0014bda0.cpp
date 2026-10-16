#include "gen/fight.h"

extern "C" char DAT_004135d8[];
extern void* __cdecl Allocate(unsigned int);
class CivilianTargetCondition_14bda0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    CivilianTargetCondition_14bda0(int);
    char data[12];
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CivilianTargetCondition>::vfunc_5() {
    CivilianTargetCondition_14bda0* p = (CivilianTargetCondition_14bda0*)Allocate(0x10);
    void* r;
    if (p) {
        p->CivilianTargetCondition_14bda0::CivilianTargetCondition_14bda0(0);
        *(unsigned long*)p = ((int)DAT_004135d8);
        p->data[8] = 1;
        r = p;
    } else
        r = 0;
    return (void*)(r);
}
