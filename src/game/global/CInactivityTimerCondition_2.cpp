// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000581a0..0x00058250 (kind game, layer game, confidence high), dominant class CInactivityTimerCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fabb32d7 {
#define TREE_TU_END }
namespace fn_fabb32d7 {} using namespace fn_fabb32d7;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fabb32d7 {
class TrackFactoryTemplate_581a0 {
  public:
    TrackFactoryTemplate_581a0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00054480();
typedef unsigned int u32_581e0;
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct CCollisionPushbackYAngleCondition_581e0 {
    hulk_uintptr vptr;
    char pad[8];
    int fieldC;
    int field10;
    void Init_00234590(int);
};
extern u32_581e0 hulk_at_003f7474;
extern int hulk_at_003f9540;
struct ConditionFactoryTemplate_58220 {
    void* m_vptr;
    void base1_dtor_0004a6a0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fabb32d7

// 0x000581a0 fight::ConditionFactoryCasterTemplate<CInactivityTimerCondition>::vfunc_1 (60 B): matches/0x000581a0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCInactivityTimerCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CInactivityTimerCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_581a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_581a0* t = new (mem) TrackFactoryTemplate_581a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00054480();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000581e0 fight::ConditionFactoryTemplate<CInactivityTimerCondition>::vfunc_5 (54 B): matches/0x000581e0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCInactivityTimerCondition@@@fight@@UAEPAXXZ
// Same code shape as 0x00057c10 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<CInactivityTimerCondition>::vfunc_5() {
    CCollisionPushbackYAngleCondition_581e0* p = (CCollisionPushbackYAngleCondition_581e0*)Alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        p->vptr = (hulk_uintptr)&hulk_at_003f7474;
        p->fieldC = 5;
        p->field10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fabb32d7 {

// 0x00058220 fight::ConditionFactoryTemplate<CInactivityTimerCondition>::vfunc_2 (43 B): matches/0x00058220.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58220@fn_fabb32d7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58220::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9540;
    base1_dtor_0004a6a0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fabb32d7
