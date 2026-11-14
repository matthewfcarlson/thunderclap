// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a1ed0..0x001aace0 (kind game, layer game, confidence high), dominant class hulkfight::scenario::EffectAction
#include "tree_prelude.h"


// 0x001aa580 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_5 (54 B): matches/0x001aa580.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"
#include "gen/hulkfight.h"   // (dtor1) hulkfight::scenario::Event_LocomotionStateNamePreviousCondition, the stub class's real class

/* size_t: tree_prelude.h */
void* operator new(size_t) HULK_NEW_THROW;
namespace hulkfight {
namespace scenario {
class Base {
  public:
    virtual void v0();
    virtual bool v1_00234270(void*);
    virtual bool v2_002342b0(int);
    virtual bool v3_002344d0(hulk_intptr, int, hulk_intptr);
    virtual bool v4_00234350(int, int);
    virtual void* v5_001a5b30(char);
    char pad[8];
    Base(int);
};
class Event_LocomotionStateNamePreviousCondition_1aa580 : public ::hulkfight::scenario::Event_LocomotionStateNamePreviousCondition {
  public:
    Event_LocomotionStateNamePreviousCondition_1aa580();
};
Event_LocomotionStateNamePreviousCondition_1aa580::Event_LocomotionStateNamePreviousCondition_1aa580() : ::hulkfight::scenario::Event_LocomotionStateNamePreviousCondition(0) {
    compare = 0;
    oldState = 0;}
} // namespace scenario
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_5() {
    return (void*)(new hulkfight::scenario::Event_LocomotionStateNamePreviousCondition_1aa580);
}

