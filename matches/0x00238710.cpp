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

class TrackFactoryTemplate_238710 {
  public:
    TrackFactoryTemplate_238710() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

void postInit();

template <> void* fight::ConditionFactoryCasterTemplate<fight::MaybeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_238710));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_238710* t = new (mem) TrackFactoryTemplate_238710();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}
