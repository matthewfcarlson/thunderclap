// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159790..0x00159840 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceNodeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f73fc4d4 {
#define TREE_TU_END }
namespace fn_f73fc4d4 {} using namespace fn_f73fc4d4;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f73fc4d4 {
class TrackFactoryTemplate_159790 {
  public:
    TrackFactoryTemplate_159790() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001557f0();
extern "C" char DAT_00414130[];
class Sub_1597d0 {
  public:
    void InitSub_00233dd0();
};
class CollisionSourceNodeCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char p4[8];
    int fieldC;
    Sub_1597d0* unused;
    char p14[8];
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_00415688;
struct ConditionFactoryTemplate_159810 {
    void* m_vptr;
    void base1_dtor_0014d810();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f73fc4d4

// 0x00159790 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_1 (60 B): matches/0x00159790.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159790));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159790* t = new (mem) TrackFactoryTemplate_159790();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001557f0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f73fc4d4 {

// 0x001597d0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_5 (59 B): matches/0x001597d0.cpp
// sym: ?FactoryVfunc5@fn_f73fc4d4@@YAPAVCollisionSourceNodeCondition@1@XZ
CollisionSourceNodeCondition* FactoryVfunc5() {
    CollisionSourceNodeCondition* p = (CollisionSourceNodeCondition*)FUN_0008d690(0x20);
    if (p) {
        p->Init_00234590(0);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_00414130);
        p->fieldC = 0;
        ((Sub_1597d0*)((char*)p + 0x10))->InitSub_00233dd0();
        *((char*)p + 0x1c) = 0;
        return p;
    }
    return 0;
}


// 0x00159810 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_2 (43 B): matches/0x00159810.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159810@fn_f73fc4d4@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159810::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415688;
    base1_dtor_0014d810();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f73fc4d4
