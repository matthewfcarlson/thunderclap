// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018cab0..0x0018ecb0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TimerCondition
#include "tree_prelude.h"


// 0x0018ea90 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleVarCompareCondition>::vfunc_1 (60 B): matches/0x0018ea90.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VGrappleVarCompareCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
#include "gen/fight.h"

void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}

struct InitHelper {
    void init();
    void init_002343b0();   // (unb4) the constructor the call reaches (verify_relocs)
};

struct TrackImpl {
    int m0;
    int m1;
    void setup_0027b040(void* arg);
};

class ConditionFactoryTemplate_18ea90 {
  public:
    ConditionFactoryTemplate_18ea90() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};

void postInit();

template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleVarCompareCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(ConditionFactoryTemplate_18ea90));
    if (mem) {
        ((InitHelper*)mem)->init_002343b0();
        ConditionFactoryTemplate_18ea90* t = new (mem) ConditionFactoryTemplate_18ea90();
        t->mTrack.setup_0027b040(arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

