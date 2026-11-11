// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001aace0..0x001acb90 (kind game, layer game, confidence high), dominant class hulkfight::scenario::Event_PathNameCondition
#include "tree_prelude.h"


// 0x001aca50 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PathNameCondition>::vfunc_1 (60 B): matches/0x001aca50.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VEvent_PathNameCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
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

class ConditionFactoryTemplate_1aca50 {
  public:
    ConditionFactoryTemplate_1aca50() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

void postInit();

template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PathNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(ConditionFactoryTemplate_1aca50));
    if (mem) {
        ((InitHelper*)mem)->init();
        ConditionFactoryTemplate_1aca50* t = new (mem) ConditionFactoryTemplate_1aca50();
        t->mTrack.setup_0027b040(arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

