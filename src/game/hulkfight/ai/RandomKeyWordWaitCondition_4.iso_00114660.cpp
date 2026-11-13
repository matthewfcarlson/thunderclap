// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX-
// object 0x00114620..0x001146d0 (kind game, layer game, confidence high), dominant class hulkfight::ai::RandomKeyWordWaitCondition
#include "tree_prelude.h"


// 0x00114660 fight::ConditionFactoryTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_5 (54 B): matches/0x00114660.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"
#include "gen/hulkfight.h"   // (dtor1) hulkfight::ai::RandomKeyWordWaitCondition, the stub class's real class

/* size_t: tree_prelude.h */
void* operator new(size_t);
namespace hulkfight {
namespace ai {
class BaseCondition {
  public:
    virtual void v0();
    virtual bool v1_00234270(void*);
    virtual bool v2_002342b0(int);
    char pad[8];
    BaseCondition(int) throw();
};
class RandomKeyWordWaitCondition_114660 : public ::hulkfight::ai::RandomKeyWordWaitCondition {
  public:
    RandomKeyWordWaitCondition_114660() throw();
};
RandomKeyWordWaitCondition_114660::RandomKeyWordWaitCondition_114660() throw() : ::hulkfight::ai::RandomKeyWordWaitCondition(0) {
    f_0c = 0;
    f_10 = 0;}
} // namespace ai
} // namespace hulkfight
namespace fight {
class ConditionFactory_114660 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::ai::RandomKeyWordWaitCondition_114660* vfunc_5();
};

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_5() {
    return (void*)(new hulkfight::ai::RandomKeyWordWaitCondition_114660);
}

