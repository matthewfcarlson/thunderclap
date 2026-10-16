#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t);
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int a;
    int b;
};
class Member {
  public:
    Member() throw();
    int a;
    int b;
};
class CGrappleCharacterTemplateCondition_58ef0 : public Base {
  public:
    CGrappleCharacterTemplateCondition_58ef0() throw();
    virtual void f0();
    int val;
    Member m;
};
CGrappleCharacterTemplateCondition_58ef0::CGrappleCharacterTemplateCondition_58ef0() throw() : Base(0), val(0), m() {}

template <> void* fight::ConditionFactoryTemplate<CGrappleCharacterTemplateCondition>::vfunc_5() {
    return (void*)(new CGrappleCharacterTemplateCondition_58ef0);
}
