#include "gen/fight.h"

typedef unsigned int size_t;
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
class PrintCondition_239270 : public Condition_239270 {
  public:
    PrintCondition_239270() throw();
    virtual void f();
};
PrintCondition_239270::PrintCondition_239270() throw() : Condition_239270(0) {
    a = 0;
    b = 0;
}

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<fight::PrintCondition>::vfunc_5() {
    return (void*)(new PrintCondition_239270);
}
