// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058eb0..0x00058f60 (kind game, layer game, confidence high), dominant class CGrappleCharacterTemplateCondition
#include "tree_prelude.h"


// 0x00058ef0 fight::ConditionFactoryTemplate<CGrappleCharacterTemplateCondition>::vfunc_5 (55 B): matches/0x00058ef0.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCGrappleCharacterTemplateCondition@@@fight@@UAEPAXXZ
#include "gen/fight.h"

/* size_t: tree_prelude.h */
void* operator new(size_t);
class Base {
  public:
    Base(int);
    virtual void f0();
    virtual bool f1_00234270(void*);
    virtual bool f2_002342b0(int);
    int a;
    int b;
};
class Member {
  public:
    Member();
    int a;
    int b;
};
class CGrappleCharacterTemplateCondition_58ef0 : public Base {
  public:
    CGrappleCharacterTemplateCondition_58ef0();
    virtual void f0();
    int val;
    Member m;
};
CGrappleCharacterTemplateCondition_58ef0::CGrappleCharacterTemplateCondition_58ef0() : Base(0), val(0), m() {}

template <> void* fight::ConditionFactoryTemplate<CGrappleCharacterTemplateCondition>::vfunc_5() {
    return (void*)(new CGrappleCharacterTemplateCondition_58ef0);
}

