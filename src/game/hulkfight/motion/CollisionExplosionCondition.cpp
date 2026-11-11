// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001596f0..0x00159790 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionExplosionCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd3da653 {
#define TREE_TU_END }
namespace fn_fd3da653 {} using namespace fn_fd3da653;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd3da653 {
class TrackFactoryTemplate_1596f0 {
  public:
    TrackFactoryTemplate_1596f0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155790();
extern "C" char DAT_00414110[];
extern "C" void* __cdecl alloc(hulk_uintptr);
struct Obj_159730 {
    hulk_intptr vf;
    char pad[8];
    char flag;
    void Init_00234590(int);
};
extern int hulk_at_0041566c;
struct ConditionFactoryTemplate_159760 {
    void* m_vptr;
    void base1_dtor_0014d7b0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fd3da653

// 0x001596f0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionExplosionCondition>::vfunc_1 (60 B): matches/0x001596f0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionExplosionCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionExplosionCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1596f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1596f0* t = new (mem) TrackFactoryTemplate_1596f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155790();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159730 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionExplosionCondition>::vfunc_5 (44 B): matches/0x00159730.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionExplosionCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionExplosionCondition>::vfunc_5() {
    Obj_159730* p = (Obj_159730*)alloc(0x10);
    if (p) {
        p->Init_00234590(0);
        p->vf = ((hulk_intptr)DAT_00414110);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fd3da653 {

// 0x00159760 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionExplosionCondition>::vfunc_2 (43 B): matches/0x00159760.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159760@fn_fd3da653@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159760::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041566c;
    base1_dtor_0014d7b0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd3da653
