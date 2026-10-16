#include "gen/fight.h"

struct CIsGrappledCondition_52580 {
    virtual ~CIsGrappledCondition_52580();
    void init(int);
};
void* operator new(unsigned int);
extern void* condition_vftable_52580;

template <> void* fight::ConditionFactoryTemplate<CIsGrappledCondition>::vfunc_5() {
    CIsGrappledCondition_52580* p = (CIsGrappledCondition_52580*)operator new(0x0c);
    if (p) {
        p->init(0);
        *(void**)p = &condition_vftable_52580;
        return (void*)(p);
    }
    return (void*)(0);
}
