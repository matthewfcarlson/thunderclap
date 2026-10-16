#include "gen/fight.h"

struct Base_58fd0 {
    virtual void f0();
    Base_58fd0() throw();
    char pad[0x14];
};
struct CNameFlagCondition_58fd0 : Base_58fd0 {
    CNameFlagCondition_58fd0() throw() {}
    virtual void f0();
};
void* operator new(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CNameFlagCondition>::vfunc_5() {
    return (void*)(new CNameFlagCondition_58fd0);
}
