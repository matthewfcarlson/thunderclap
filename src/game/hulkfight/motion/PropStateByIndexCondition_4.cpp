// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018ba10..0x0018bac0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropStateByIndexCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fddfd452 {
#define TREE_TU_END }
namespace fn_fddfd452 {} using namespace fn_fddfd452;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fddfd452 {
class TrackFactoryTemplate_18ba10 {
  public:
    TrackFactoryTemplate_18ba10() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187ac0();
extern "C" char DAT_0041922c[];
class PropStateByIndexCondition_18ba50 {
  public:
    hulk_intptr a;
    int b;
    int c;
    int d;
    int e;
    int f;
    void Init_00234590(int);
};
extern "C" void* FUN_0008d690(hulk_uintptr);
extern int hulk_at_0041a710;
struct ConditionFactoryTemplate_18ba90 {
    void* m_vptr;
    void base1_dtor_00180940();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fddfd452

// 0x0018ba10 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_1 (60 B): matches/0x0018ba10.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18ba10));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18ba10* t = new (mem) TrackFactoryTemplate_18ba10();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187ac0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018ba50 fight::ConditionFactoryTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_5 (61 B): matches/0x0018ba50.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_5() {
    PropStateByIndexCondition_18ba50* p = (PropStateByIndexCondition_18ba50*)FUN_0008d690((int)sizeof(PropStateByIndexCondition_18ba50));
    if (p) {
        p->Init_00234590(0);
        p->a = ((hulk_intptr)DAT_0041922c);
        p->d = -1;
        p->e = 0;
        p->f = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fddfd452 {

// 0x0018ba90 fight::ConditionFactoryTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_2 (43 B): matches/0x0018ba90.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18ba90@fn_fddfd452@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18ba90::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a710;
    base1_dtor_00180940();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fddfd452
