#include "gen/fight.h"

extern "C" char DAT_003f9130[];
extern "C" void* __cdecl Allocate(unsigned int);
class CAxisReleaseCondition_56fe0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    void Init();
};

template <> void* fight::ConditionFactoryTemplate<CAxisReleaseCondition>::vfunc_5() {
    CAxisReleaseCondition_56fe0* p = (CAxisReleaseCondition_56fe0*)Allocate(0x18);
    if (p) {
        p->Init();
        *(void**)p = (void*)((int)DAT_003f9130);
        return (void*)(p);
    }
    return (void*)(0);
}
