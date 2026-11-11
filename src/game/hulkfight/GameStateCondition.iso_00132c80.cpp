// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
#include "tree_prelude.h"


// 0x00132c80 fight::TrackFactoryCasterTemplate<hulkfight::DialogueTrack>::vfunc_1 (60 B): matches/0x00132c80.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VDialogueTrack@hulkfight@@@fight@@UAEPAXPAX@Z
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
    void setup(void* arg);
};

class TrackFactoryTemplate_132c80 {
  public:
    TrackFactoryTemplate_132c80() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

void postInit();

template <> void* fight::TrackFactoryCasterTemplate<hulkfight::DialogueTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_132c80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_132c80* t = new (mem) TrackFactoryTemplate_132c80();
        t->mTrack.setup(arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

