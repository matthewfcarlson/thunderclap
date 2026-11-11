// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001598f0..0x001599b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionDamageHealthCompareCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f370be9d {
#define TREE_TU_END }
namespace fn_f370be9d {} using namespace fn_f370be9d;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f370be9d {
class TrackFactoryTemplate_1598f0 {
  public:
    TrackFactoryTemplate_1598f0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001559d0();
extern "C" char DAT_00414190[];
extern "C" void* __cdecl FUN_0008d690(uint);
struct Obj_159930 {
    hulk_uintptr vt;
    int a;
    int b;
    int c;
    int d;
    int e;
    char flag;
    void Init_00234590(int);
};
extern int hulk_at_004156c0;
struct ConditionFactoryTemplate_159980 {
    void* m_vptr;
    void base1_dtor_0014d980();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f370be9d

// 0x001598f0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_1 (60 B): matches/0x001598f0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1598f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1598f0* t = new (mem) TrackFactoryTemplate_1598f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001559d0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159930 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_5 (65 B): matches/0x00159930.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_5() {
    Obj_159930* p = (Obj_159930*)FUN_0008d690((int)sizeof(Obj_159930));
    if (p) {
        p->Init_00234590(0);
        p->vt = ((hulk_intptr)DAT_00414190);
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f370be9d {

// 0x00159980 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_2 (43 B): matches/0x00159980.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159980@fn_f370be9d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159980::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004156c0;
    base1_dtor_0014d980();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f370be9d
