#include "gen/fight.h"

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
    void Setup(void*);
};

template <> void* fight::ConditionFactoryCasterTemplate<CIsHelicopterCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* p = Allocate(0x10);
    if (p) {
        ((InitObj_525e0*)p)->Init();
        *(unsigned int*)p = ((int)DAT_003f8644);
        ((SetupObj_525e0*)((char*)p + 8))->Setup(arg);
        return (void*)(p);
    }
    return (void*)(0);
}
