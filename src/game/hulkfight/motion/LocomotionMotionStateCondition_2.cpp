// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d820..0x0016d8d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::LocomotionMotionStateCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1bdf2cd {
#define TREE_TU_END }
namespace fn_f1bdf2cd {} using namespace fn_f1bdf2cd;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f1bdf2cd {
class TrackFactoryTemplate_16d820 {
  public:
    TrackFactoryTemplate_16d820() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b3c0();
class Condition_16d860 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int LocomotionVTable;
struct Locomotion_16d860 {
    int* vptr;
    char pad[8];
    int a;
    int b;
};
extern int g_vftable_16d8a0;
struct ConditionFactoryTemplate_16d8a0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f1bdf2cd

// 0x0016d820 fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_1 (60 B): matches/0x0016d820.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d820));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16d820* t = new (mem) TrackFactoryTemplate_16d820();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b3c0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016d860 fight::ConditionFactoryTemplate<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_5 (54 B): matches/0x0016d860.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_5() {
    Condition_16d860* p = (Condition_16d860*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        Locomotion_16d860* q = (Locomotion_16d860*)p;
        q->vptr = &LocomotionVTable;
        q->a = 0;
        q->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f1bdf2cd {

// 0x0016d8a0 fight::ConditionFactoryTemplate<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_2 (43 B): matches/0x0016d8a0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d8a0@fn_f1bdf2cd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d8a0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_16d8a0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1bdf2cd
