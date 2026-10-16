#include "gen/fight.h"

struct Base_574a0 {
    virtual void f0();
    Base_574a0() throw();
    char pad[0x14];
};
struct CButtonUpCondition_574a0 : Base_574a0 {
    CButtonUpCondition_574a0() throw() {}
    virtual void f0();
};
void* operator new(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CButtonUpCondition>::vfunc_5() {
    return (void*)(new CButtonUpCondition_574a0);
}
