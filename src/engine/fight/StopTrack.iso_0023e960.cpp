// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023e4d0..0x0023ea20 (kind game, layer engine, confidence high), dominant class fight::StopTrack
#include "tree_prelude.h"


// 0x0023e960 fight::TrackFactoryCasterTemplate<fight::StopTrack>::vfunc_1 (60 B): matches/0x0023e960.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VStopTrack@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
#include "gen/fight.h"

void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}

struct InitHelper {
    void init();
};

struct TrackImpl {
    int m0;
    int m1;
    void setup_0027b040(void* arg);
};

class TrackFactoryTemplate_23e960 {
  public:
    TrackFactoryTemplate_23e960() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

void postInit();

template <> void* fight::TrackFactoryCasterTemplate<fight::StopTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_23e960));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_23e960* t = new (mem) TrackFactoryTemplate_23e960();
        t->mTrack.setup_0027b040(arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

