#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00428a98[];
class ConditionFactoryCaster_23d140 {
  public:
    virtual void A();
    virtual void B();
};
class Helper_23d140 {
  public:
    void Init();
    void Setup(void*);
};
extern "C" void* __cdecl alloc(unsigned int);

template <> void* fight::ConditionFactoryCasterTemplate<fight::OrCondition>::vfunc_1(void* __p0) { void * p = (void *)__p0;

    void* q = alloc(0x10);
    if (q) {
        ((Helper_23d140*)q)->Init();
        *(hulk_uintptr*)q = ((hulk_intptr)DAT_00428a98);
        ((Helper_23d140*)((char*)q + 8))->Setup(p);
        return (void*)(q);
    }
    return (void*)(0);
}
