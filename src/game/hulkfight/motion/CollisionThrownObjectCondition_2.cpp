// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a4f0..0x0015a5a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionThrownObjectCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fab280ce {
#define TREE_TU_END }
namespace fn_fab280ce {} using namespace fn_fab280ce;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fab280ce {
class TrackFactoryTemplate_15a4f0 {
  public:
    TrackFactoryTemplate_15a4f0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00157ee0();
extern "C" void* __cdecl alloc(hulk_uintptr);
extern "C" int hulk_at_004140f0;
struct Helper_15a530 {
    char pad[8];
    void Go_0027af00();
};
struct Cond_15a530 {
    void* vp;
    char pad1[8];
    char flag;
    char pad2[3];
    Helper_15a530 h;
    void Init_00234590(int);
};
extern int hulk_at_0041589c;
struct ConditionFactoryTemplate_15a570 {
    void* m_vptr;
    void base1_dtor_0014d740();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fab280ce

// 0x0015a4f0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_1 (60 B): matches/0x0015a4f0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a4f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_15a4f0* t = new (mem) TrackFactoryTemplate_15a4f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00157ee0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0015a530 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_5 (52 B): matches/0x0015a530.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_5() {
    Cond_15a530* p = (Cond_15a530*)alloc(0x18);
    if (p) {
        p->Init_00234590(0);
        p->vp = (void*)&hulk_at_004140f0;
        p->flag = 1;
        p->h.Go_0027af00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fab280ce {

// 0x0015a570 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_2 (43 B): matches/0x0015a570.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_15a570@fn_fab280ce@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_15a570::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041589c;
    base1_dtor_0014d740();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fab280ce
