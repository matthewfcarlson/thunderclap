// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012ab50..0x0012ac00 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityXZCondition
#include "tree_prelude.h"


// 0x0012ab90 fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_5 (54 B): matches/0x0012ab90.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

/* size_t: tree_prelude.h */
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace hulkfight {
namespace ai {
class BaseCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    int x;
    int y;
    int z;
    int w;
    BaseCondition(int) throw();
};
class TargetVelocityXZCondition_12ab90 : public BaseCondition {
  public:
    TargetVelocityXZCondition_12ab90() throw();
    virtual void a();
    virtual void b();
    virtual void c();
};
TargetVelocityXZCondition_12ab90::TargetVelocityXZCondition_12ab90() throw() : BaseCondition(0) {
    z = 0;
    w = 0;
}
} // namespace ai
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_5() {
    return (void*)(new hulkfight::ai::TargetVelocityXZCondition_12ab90());
}

