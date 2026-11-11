// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058510..0x000585c0 (kind game, layer game, confidence high), dominant class CMotionStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f56c52e2 {
#define TREE_TU_END }
namespace fn_f56c52e2 {} using namespace fn_f56c52e2;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f56c52e2 {
class TrackFactoryTemplate_58510 {
  public:
    TrackFactoryTemplate_58510() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_58550;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CMotionStateCondition_58550 {
    hulk_uintptr vtable;
    u32_58550 pad4;
    u32_58550 pad8;
    u32_58550 fieldC;
    u32_58550 field10;
    void Initialize_00234590(int);
};
extern int hulk_at_003f95cc;
struct ConditionFactoryTemplate_58590 {
    void* m_vptr;
    void base1_dtor_0004a1f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f56c52e2

// 0x00058510 fight::ConditionFactoryCasterTemplate<CMotionStateCondition>::vfunc_1 (60 B): matches/0x00058510.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCMotionStateCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CMotionStateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58510));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58510* t = new (mem) TrackFactoryTemplate_58510();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053fe0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058550 fight::ConditionFactoryTemplate<CMotionStateCondition>::vfunc_5 (54 B): matches/0x00058550.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCMotionStateCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CMotionStateCondition>::vfunc_5() {
    CMotionStateCondition_58550* p = (CMotionStateCondition_58550*)FUN_0008d690((int)sizeof(CMotionStateCondition_58550));
    if (p) {
        p->Initialize_00234590(0);
        p->vtable = ((hulk_intptr)DAT_003f7394);
        p->fieldC = 0;
        p->field10 = 1;
        return (void*)(p);
    } else {
        return (void*)(0);
    }
}

namespace fn_f56c52e2 {

// 0x00058590 fight::ConditionFactoryTemplate<CMotionStateCondition>::vfunc_2 (43 B): matches/0x00058590.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58590@fn_f56c52e2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58590::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f95cc;
    base1_dtor_0004a1f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f56c52e2
