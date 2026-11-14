// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00238850..0x002393a0 (kind game, layer engine, confidence high), dominant class fight::PrintTrack
#include "tree_prelude.h"


// 0x00239270 fight::ConditionFactoryTemplate<fight::PrintCondition>::vfunc_5 (54 B): matches/0x00239270.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPrintCondition@fight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

/* size_t: tree_prelude.h */
void* operator new(size_t);
namespace fight {
class Condition_239270 {
  public:
    virtual void f();
    char pad[8];
    void* a;
    void* b;
    Condition_239270(int) throw();
};
class PrintCondition_239270 : public ::fight::PrintCondition {
  public:
    PrintCondition_239270() throw();
};
PrintCondition_239270::PrintCondition_239270() throw() : ::fight::PrintCondition(0) {
    f_0c = 0;
    f_10 = 0;
}

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<fight::PrintCondition>::vfunc_5() {
    return (void*)(new PrintCondition_239270);
}

