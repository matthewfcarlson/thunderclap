// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e430..0x0016e4e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HealthCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa61cb85 {
#define TREE_TU_END }
namespace fn_fa61cb85 {} using namespace fn_fa61cb85;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fa61cb85 {
class TrackFactoryTemplate_16e430 {
  public:
    TrackFactoryTemplate_16e430() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016bf00();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class Condition_16e470 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init_00234590(int);
    int x;
    int y;
    int z;
    int w;
    int q;
};
extern int hulk_at_004177d0;
struct ConditionFactoryTemplate_16e4b0 {
    void* m_vptr;
    void base1_dtor_00166760();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fa61cb85

// 0x0016e430 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthCondition>::vfunc_1 (60 B): matches/0x0016e430.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHealthCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e430));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16e430* t = new (mem) TrackFactoryTemplate_16e430();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016bf00();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e470 fight::ConditionFactoryTemplate<hulkfight::motion::HealthCondition>::vfunc_5 (61 B): matches/0x0016e470.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VHealthCondition@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00113f80 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::HealthCondition>::vfunc_5() {
    Condition_16e470* p = (Condition_16e470*)FUN_0008d690((int)sizeof(Condition_16e470));
    void* result;
    if (p) {
        p->Init_00234590(0);
        *(int**)p = &AIHistoryNameCondition_vftable;
        p->z = 0;
        p->w = 0;
        p->q = 0;
        result = p;
    } else
        result = 0;
    return (void*)(result);
}

namespace fn_fa61cb85 {

// 0x0016e4b0 fight::ConditionFactoryTemplate<hulkfight::motion::HealthCondition>::vfunc_2 (43 B): matches/0x0016e4b0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e4b0@fn_fa61cb85@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e4b0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004177d0;
    base1_dtor_00166760();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fa61cb85
