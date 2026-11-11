// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00056d10..0x00056dd0 (kind game, layer game, confidence high), dominant class CAxisDoubleTapCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fee895d5 {
#define TREE_TU_END }
namespace fn_fee895d5 {} using namespace fn_fee895d5;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fee895d5 {
class TrackFactoryTemplate_56d10 {
  public:
    TrackFactoryTemplate_56d10() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00052f20();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_003f6f08;
struct CAxisDoubleTapCondition_56d50 {
    hulk_intptr vt;
    int pad0;
    int pad1;
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    void Init_00234590(int);
};
extern int hulk_at_003f9060;
struct ConditionFactoryTemplate_56da0 {
    void* m_vptr;
    void base1_dtor_00048910();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fee895d5

// 0x00056d10 fight::ConditionFactoryCasterTemplate<CAxisDoubleTapCondition>::vfunc_1 (60 B): matches/0x00056d10.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAxisDoubleTapCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAxisDoubleTapCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_56d10));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_56d10* t = new (mem) TrackFactoryTemplate_56d10();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00052f20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00056d50 fight::ConditionFactoryTemplate<CAxisDoubleTapCondition>::vfunc_5 (75 B): matches/0x00056d50.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCAxisDoubleTapCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CAxisDoubleTapCondition>::vfunc_5() {
    CAxisDoubleTapCondition_56d50* p = (CAxisDoubleTapCondition_56d50*)FUN_0008d690((int)sizeof(CAxisDoubleTapCondition_56d50));
    if (p) {
        p->Init_00234590(0);
        p->x0 = 0;
        p->vt = (hulk_intptr)&hulk_at_003f6f08;
        p->x1 = 0;
        p->x2 = 0x3fc90fdb;
        p->x3 = 0;
        p->x4 = 0x3f000000;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fee895d5 {

// 0x00056da0 fight::ConditionFactoryTemplate<CAxisDoubleTapCondition>::vfunc_2 (43 B): matches/0x00056da0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_56da0@fn_fee895d5@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_56da0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9060;
    base1_dtor_00048910();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fee895d5
