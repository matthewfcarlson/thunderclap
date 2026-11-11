// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018bb70..0x0018bc20 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropCollidedWithWorldCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2d49a4e {
#define TREE_TU_END }
namespace fn_f2d49a4e {} using namespace fn_f2d49a4e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f2d49a4e {
class TrackFactoryTemplate_18bb70 {
  public:
    TrackFactoryTemplate_18bb70() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187ca0();
extern "C" char DAT_0041926c[];
typedef unsigned int u32_18bbb0;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class Condition_18bbb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[8];
    int fieldC;
    u8 flag10;
    void init_00234590(int);
};
extern int hulk_at_0041a748;
struct ConditionFactoryTemplate_18bbf0 {
    void* m_vptr;
    void base1_dtor_00180a20();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f2d49a4e

// 0x0018bb70 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_1 (60 B): matches/0x0018bb70.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18bb70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18bb70* t = new (mem) TrackFactoryTemplate_18bb70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187ca0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018bbb0 fight::ConditionFactoryTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_5 (51 B): matches/0x0018bbb0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_5() {
    Condition_18bbb0* p = (Condition_18bbb0*)FUN_0008d690((int)sizeof(Condition_18bbb0));
    if (p) {
        p->init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041926c);
        p->fieldC = 0;
        p->flag10 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f2d49a4e {

// 0x0018bbf0 fight::ConditionFactoryTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_2 (43 B): matches/0x0018bbf0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18bbf0@fn_f2d49a4e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18bbf0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a748;
    base1_dtor_00180a20();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f2d49a4e
