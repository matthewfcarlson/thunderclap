// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159450..0x001594f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetIsTargetCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc5343c3 {
#define TREE_TU_END }
namespace fn_fc5343c3 {} using namespace fn_fc5343c3;
namespace fn_fc5343c3 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc5343c3 {
class TrackFactoryTemplate_159450 {
  public:
    TrackFactoryTemplate_159450() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155560();
extern "C" char DAT_00414070[];
class Condition_159490 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void Init_00234590(int);
    char pad[8];
    char flag;
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_004155fc;
struct ConditionFactoryTemplate_1594c0 {
    void* m_vptr;
    void base1_dtor_0014d5a0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc5343c3

// 0x00159450 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_1 (60 B): matches/0x00159450.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionTargetIsTargetCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159450));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_159450* t = new (mem) TrackFactoryTemplate_159450();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155560();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159490 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_5 (44 B): matches/0x00159490.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionTargetIsTargetCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_5() {
    Condition_159490* p = (Condition_159490*)FUN_0008d690((int)sizeof(Condition_159490));
    if (p) {
        p->Init_00234590(0);
        *((hulk_intptr*)p) = ((hulk_intptr)DAT_00414070);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc5343c3 {

// 0x001594c0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_2 (43 B): matches/0x001594c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1594c0@fn_fc5343c3@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1594c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004155fc;
    base1_dtor_0014d5a0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fc5343c3
