// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016dc30..0x0016dce0 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleHealthCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0016dc70 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleHealthCondition>::vfunc_5 (61 B): matches/0x0016dc70.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

class GrappleHealthCondition_16dc70 {
  public:
    GrappleHealthCondition_16dc70();
    void Init_00234590(int x);
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2() {}
    virtual void f3() {}
    virtual void f4() {}
    virtual void f5() {}
    int m4;
    int m8;
    int m12;
    int m16;
    int m20;
};

GrappleHealthCondition_16dc70::GrappleHealthCondition_16dc70() {
    m12 = 0;
    m16 = 0;
    m20 = 0;
}

void* Alloc_0008d690(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrappleHealthCondition>::vfunc_5() {
    GrappleHealthCondition_16dc70* p = (GrappleHealthCondition_16dc70*)Alloc_0008d690(0x18);
    if (p) {
        p->Init_00234590(0);
        p->GrappleHealthCondition_16dc70::GrappleHealthCondition_16dc70();
        return (void*)(p);
    }
    return (void*)(0);
}

