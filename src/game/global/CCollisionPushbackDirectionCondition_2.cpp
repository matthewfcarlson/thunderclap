// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000579c0..0x00057a70 (kind game, layer game, confidence high), dominant class CCollisionPushbackDirectionCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8ff7609 {
#define TREE_TU_END }
namespace fn_f8ff7609 {} using namespace fn_f8ff7609;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8ff7609 {
class TrackFactoryTemplate_579c0 {
  public:
    TrackFactoryTemplate_579c0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053440();
extern "C" char DAT_003f6fec[];
class CCollisionPushbackDirectionCondition_57a00 {
  public:
    hulk_intptr pad0;
    int pad4;
    int pad8;
    int mA;
    int mB;
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003f93bc;
struct ConditionFactoryTemplate_57a40 {
    void* m_vptr;
    void base1_dtor_00048cc0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f8ff7609

// 0x000579c0 fight::ConditionFactoryCasterTemplate<CCollisionPushbackDirectionCondition>::vfunc_1 (60 B): matches/0x000579c0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionPushbackDirectionCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionPushbackDirectionCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_579c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_579c0* t = new (mem) TrackFactoryTemplate_579c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053440();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057a00 fight::ConditionFactoryTemplate<CCollisionPushbackDirectionCondition>::vfunc_5 (54 B): matches/0x00057a00.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionPushbackDirectionCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCollisionPushbackDirectionCondition>::vfunc_5() {
    CCollisionPushbackDirectionCondition_57a00* p = (CCollisionPushbackDirectionCondition_57a00*)FUN_0008d690((int)sizeof(CCollisionPushbackDirectionCondition_57a00));
    if (p) {
        p->Init_00234590(0);
        p->pad0 = ((hulk_intptr)DAT_003f6fec);
        p->mA = 0;
        p->mB = 0x3fc90fdb;
        return (void*)(p);
    }
    return (void*)((void*)0);
}

namespace fn_f8ff7609 {

// 0x00057a40 fight::ConditionFactoryTemplate<CCollisionPushbackDirectionCondition>::vfunc_2 (43 B): matches/0x00057a40.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57a40@fn_f8ff7609@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57a40::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f93bc;
    base1_dtor_00048cc0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8ff7609
