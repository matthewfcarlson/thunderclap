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

class TrackFactoryTemplate_17f210 {
  public:
    TrackFactoryTemplate_17f210() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

extern "C" void FUN_0017ddf0();

template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17f210));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17f210* t = new (mem) TrackFactoryTemplate_17f210();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017ddf0();
        return (void*)(t);
    }
    return (void*)(0);
}
