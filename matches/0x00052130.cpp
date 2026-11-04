// Same code shape as 0x00122f30 (propagated; names are from that function)
#include "gen/fight.h"
#include "gen/owners.h"

void* __cdecl operator new(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* where) {
    return where;
}

struct InitHelper {
    void init();
};

struct TrackImpl {
    int m0;
    int m1;
};

class TrackFactoryTemplate_52130 {
  public:
    TrackFactoryTemplate_52130() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

extern "C" void FUN_00236340();

template <> void* fight::ConditionFactoryCasterTemplate<CFightNodeTimeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_52130));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_52130* t = new (mem) TrackFactoryTemplate_52130();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00236340();
        return (void*)(t);
    }
    return (void*)(0);
}
