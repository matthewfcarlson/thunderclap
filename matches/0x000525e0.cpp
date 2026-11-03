#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"

extern "C" char DAT_003f8644[];
class ConditionFactoryCaster_525e0 {
  public:
    virtual void V0();
    virtual void* V1(void*);
};
class HelicopterCondition {
  public:
    virtual void V0();
};
extern void* __cdecl Allocate(unsigned int);
class InitObj_525e0 {
  public:
    void Init();
};
class SetupObj_525e0 {
  public:
};

template <> void* fight::ConditionFactoryCasterTemplate<CIsHelicopterCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* p = Allocate(0x10);
    if (p) {
        ((InitObj_525e0*)p)->Init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f8644);
        ((owners::Target_27b040 *)(((SetupObj_525e0*)((char*)p + 8))))->FUN_0027b040((hulk_uintptr)arg);
        return (void*)(p);
    }
    return (void*)(0);
}
