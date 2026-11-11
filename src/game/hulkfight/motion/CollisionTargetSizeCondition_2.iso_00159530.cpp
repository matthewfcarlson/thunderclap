// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001594f0..0x001595a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetSizeCondition
#include "tree_prelude.h"


// 0x00159530 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_5 (54 B): matches/0x00159530.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionTargetSizeCondition@motion@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

/* size_t: tree_prelude.h */
void* operator new(size_t) HULK_NEW_THROW;
class Base {
  public:
    Base(int) throw();
    virtual void f();
    virtual void g();
    virtual void h();
    int a;
    int b;
};
class CollisionTargetSizeCondition_159530 : public Base {
  public:
    CollisionTargetSizeCondition_159530() throw();
    virtual void f();
    int x;
    int y;
};
CollisionTargetSizeCondition_159530::CollisionTargetSizeCondition_159530() throw() : Base(0) {
    x = 0;
    y = 0;
}

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_5() {
    return (void*)(new CollisionTargetSizeCondition_159530);
}

