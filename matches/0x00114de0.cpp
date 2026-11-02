// Same code shape as 0x00122f30 (propagated; names are from that function)
#include "gen/fight.h"

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
    void setup(void* arg);
};

class TrackFactoryTemplate_114de0 {
  public:
    TrackFactoryTemplate_114de0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

extern "C" void FUN_00112f10();

template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(0x10);
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114de0* t = new (mem) TrackFactoryTemplate_114de0();
        t->mTrack.setup(arg);
        FUN_00112f10();
        return (void*)(t);
    }
    return (void*)(0);
}
