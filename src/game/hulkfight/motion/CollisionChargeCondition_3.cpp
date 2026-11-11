// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159840..0x001598f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionChargeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd954afd {
#define TREE_TU_END }
namespace fn_fd954afd {} using namespace fn_fd954afd;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd954afd {
class TrackFactoryTemplate_159840 {
  public:
    TrackFactoryTemplate_159840() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001558e0();
extern "C" char DAT_00414150[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class CollisionChargeCondition_159880 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    char pad[8];
    int a;
    int b;
    char c;
    void Init_00234590(int);
};
extern int hulk_at_004156a4;
struct ConditionFactoryTemplate_1598c0 {
    void* m_vptr;
    void base1_dtor_0014d890();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fd954afd

// 0x00159840 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_1 (60 B): matches/0x00159840.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159840));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159840* t = new (mem) TrackFactoryTemplate_159840();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001558e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159880 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_5 (58 B): matches/0x00159880.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_5() {
    CollisionChargeCondition_159880* p = (CollisionChargeCondition_159880*)Alloc(0x18);
    if (p) {
        p->Init_00234590(0);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_00414150);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fd954afd {

// 0x001598c0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_2 (43 B): matches/0x001598c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1598c0@fn_fd954afd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1598c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004156a4;
    base1_dtor_0014d890();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd954afd
