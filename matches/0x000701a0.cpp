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

class TrackFactoryTemplate_701a0 {
  public:
    TrackFactoryTemplate_701a0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

extern "C" void FUN_000641e0();

template <> void* fight::TrackFactoryCasterTemplate<CSmartPropSetStateTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_701a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_701a0* t = new (mem) TrackFactoryTemplate_701a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000641e0();
        return (void*)(t);
    }
    return (void*)(0);
}
