// Same code shape as 0x00052580 (propagated; names are from that function)
#include "gen/fight.h"

struct CIsGrappledCondition_52620 {
    virtual ~CIsGrappledCondition_52620();
    void init(int);
};
void* operator new(unsigned int);
extern void* condition_vftable_52620;

template <> void* fight::ConditionFactoryTemplate<CIsHelicopterCondition>::vfunc_5() {
    CIsGrappledCondition_52620* p = (CIsGrappledCondition_52620*)operator new(0x0c);
    if (p) {
        p->init(0);
        *(void**)p = &condition_vftable_52620;
        return (void*)(p);
    }
    return (void*)(0);
}
