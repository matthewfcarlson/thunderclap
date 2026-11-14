// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159640..0x001596f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackVelocityCondition
#include "tree_prelude.h"


// 0x00159680 fight::ConditionFactoryTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_5 (54 B): matches/0x00159680.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

/* size_t: tree_prelude.h */
void* operator new(size_t);
class Base {
  public:
    virtual void a();
    virtual bool Fnb_00234270(void*);
    virtual bool Fnc_002342b0(int);
    int x;
    int y;
    Base(int);
};
class HitPushbackVelocityCondition_159680 : public Base {
  public:
    HitPushbackVelocityCondition_159680();
    virtual void a();
    int velocity;
    int timer;
};
HitPushbackVelocityCondition_159680::HitPushbackVelocityCondition_159680() : Base(0) {
    velocity = 0;
    timer = 0;
}

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_5() {
    return (void*)(new HitPushbackVelocityCondition_159680);
}

