// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057bd0..0x00057c80 (kind game, layer game, confidence high), dominant class CCollisionPushbackYAngleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff4b9afe {
#define TREE_TU_END }
namespace fn_ff4b9afe {} using namespace fn_ff4b9afe;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff4b9afe {
class TrackFactoryTemplate_57bd0 {
  public:
    TrackFactoryTemplate_57bd0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053750();
typedef unsigned int u32_57c10;
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct CCollisionPushbackYAngleCondition_57c10 {
    hulk_uintptr vptr;
    char pad[8];
    int fieldC;
    int field10;
    void Init_00234590(int);
};
extern u32_57c10 hulk_at_003f70c4;
extern int hulk_at_003f9410;
struct ConditionFactoryTemplate_57c50 {
    void* m_vptr;
    void base1_dtor_00049040();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff4b9afe

// 0x00057bd0 fight::ConditionFactoryCasterTemplate<CCollisionPushbackYAngleCondition>::vfunc_1 (60 B): matches/0x00057bd0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionPushbackYAngleCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionPushbackYAngleCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57bd0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57bd0* t = new (mem) TrackFactoryTemplate_57bd0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053750();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057c10 fight::ConditionFactoryTemplate<CCollisionPushbackYAngleCondition>::vfunc_5 (54 B): matches/0x00057c10.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionPushbackYAngleCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCollisionPushbackYAngleCondition>::vfunc_5() {
    CCollisionPushbackYAngleCondition_57c10* p = (CCollisionPushbackYAngleCondition_57c10*)Alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        p->vptr = (hulk_uintptr)&hulk_at_003f70c4;
        p->fieldC = 5;
        p->field10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ff4b9afe {

// 0x00057c50 fight::ConditionFactoryTemplate<CCollisionPushbackYAngleCondition>::vfunc_2 (43 B): matches/0x00057c50.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57c50@fn_ff4b9afe@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57c50::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9410;
    base1_dtor_00049040();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff4b9afe
