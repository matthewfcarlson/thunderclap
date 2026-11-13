// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
#include "tree_prelude.h"


// 0x00139760 fight::TrackFactoryCasterTemplate<hulkfight::motion::HoverTrack>::vfunc_1 (60 B): matches/0x00139760.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHoverTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
#include "gen/fight.h"

void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}

struct InitHelper {
    void init();
    void init_00236a90();   // (unb4) the constructor the call reaches (verify_relocs)
};

struct TrackImpl {
    int m0;
    int m1;
    void setup_0027b040(void* arg);
};

class TrackFactoryTemplate_139760 {
  public:
    TrackFactoryTemplate_139760() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};

void postInit();

template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HoverTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_139760));
    if (mem) {
        ((InitHelper*)mem)->init_00236a90();
        TrackFactoryTemplate_139760* t = new (mem) TrackFactoryTemplate_139760();
        t->mTrack.setup_0027b040(arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

