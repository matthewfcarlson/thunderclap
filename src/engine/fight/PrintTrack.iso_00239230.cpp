// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00238850..0x002393a0 (kind game, layer engine, confidence high), dominant class fight::PrintTrack
#include "tree_prelude.h"


// 0x00239230 fight::ConditionFactoryCasterTemplate<fight::PrintCondition>::vfunc_1 (60 B): matches/0x00239230.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPrintCondition@fight@@@fight@@UAEPAXPAX@Z
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

class ConditionFactoryTemplate_239230 {
  public:
    ConditionFactoryTemplate_239230() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

void postInit();

template <> void* fight::ConditionFactoryCasterTemplate<fight::PrintCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(ConditionFactoryTemplate_239230));
    if (mem) {
        ((InitHelper*)mem)->init();
        ConditionFactoryTemplate_239230* t = new (mem) ConditionFactoryTemplate_239230();
        t->mTrack.setup_0027b040(arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

