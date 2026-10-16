// Same code shape as 0x00052580 (propagated; names are from that function)
#include "gen/fight.h"

struct CIsGrappledCondition_23d3a0 {
    virtual ~CIsGrappledCondition_23d3a0();
    void init(int);
};
void* operator new(unsigned int);
extern void* condition_vftable_23d3a0;

template <> void* fight::ConditionFactoryTemplate<fight::FalseCondition>::vfunc_5() {
    CIsGrappledCondition_23d3a0* p = (CIsGrappledCondition_23d3a0*)operator new(0x0c);
    if (p) {
        p->init(0);
        *(void**)p = &condition_vftable_23d3a0;
        return (void*)(p);
    }
    return (void*)(0);
}
