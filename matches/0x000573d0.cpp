#include "gen/fight.h"

extern "C" char DAT_003f927c[];
class CButtonReleaseCondition_573d0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void Init();
};
extern void* __cdecl Allocate(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CButtonReleaseCondition>::vfunc_5() {
    CButtonReleaseCondition_573d0* p = (CButtonReleaseCondition_573d0*)Allocate(0x18);
    if (p) {
        p->Init();
        *(unsigned int*)p = ((int)DAT_003f927c);
        return (void*)(p);
    }
    return (void*)(0);
}
