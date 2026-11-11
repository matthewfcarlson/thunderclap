// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b190..0x0012d920 (kind game, layer game, confidence high), dominant class hulkfight::ai::ThreatDistanceCondition
#include "tree_prelude.h"


// 0x0012d650 fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatDistanceCondition>::vfunc_1 (60 B): matches/0x0012d650.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
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

class ConditionFactoryTemplate_12d650 {
  public:
    ConditionFactoryTemplate_12d650() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

void postInit();

template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatDistanceCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(ConditionFactoryTemplate_12d650));
    if (mem) {
        ((InitHelper*)mem)->init();
        ConditionFactoryTemplate_12d650* t = new (mem) ConditionFactoryTemplate_12d650();
        t->mTrack.setup_0027b040(arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

