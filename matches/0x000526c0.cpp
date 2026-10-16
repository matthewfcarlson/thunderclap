// Same code shape as 0x00052580 (propagated; names are from that function)
#include "gen/fight.h"

struct CIsGrappledCondition_526c0 {
    virtual ~CIsGrappledCondition_526c0();
    void init(int);
};
void* operator new(unsigned int);
extern void* condition_vftable_526c0;

template <> void* fight::ConditionFactoryTemplate<CIsInvincibleCondition>::vfunc_5() {
    CIsGrappledCondition_526c0* p = (CIsGrappledCondition_526c0*)operator new(0x0c);
    if (p) {
        p->init(0);
        *(void**)p = &condition_vftable_526c0;
        return (void*)(p);
    }
    return (void*)(0);
}
