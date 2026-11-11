// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159060..0x00159100 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionThrowCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f083ce94 {
#define TREE_TU_END }
namespace fn_f083ce94 {} using namespace fn_f083ce94;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f083ce94 {
class TrackFactoryTemplate_159060 {
  public:
    TrackFactoryTemplate_159060() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155210();
extern "C" char DAT_00413fb0[];
extern "C" void* FUN_0008d690(unsigned int);
class CollisionThrowCondition_1590a0 {
  public:
    hulk_intptr vt;
    int a;
    int b;
    unsigned char flag;
    void Init(int);
};
extern int g_vftable_1590d0;
struct ConditionFactoryTemplate_1590d0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f083ce94

// 0x00159060 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_1 (60 B): matches/0x00159060.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionThrowCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159060));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159060* t = new (mem) TrackFactoryTemplate_159060();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155210();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001590a0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_5 (44 B): matches/0x001590a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionThrowCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_5() {
    CollisionThrowCondition_1590a0* p = (CollisionThrowCondition_1590a0*)FUN_0008d690((int)sizeof(CollisionThrowCondition_1590a0));
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_00413fb0);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f083ce94 {

// 0x001590d0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_2 (43 B): matches/0x001590d0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1590d0@fn_f083ce94@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1590d0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1590d0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f083ce94
