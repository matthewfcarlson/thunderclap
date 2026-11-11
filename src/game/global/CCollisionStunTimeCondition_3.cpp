// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057c80..0x00057d30 (kind game, layer game, confidence high), dominant class CCollisionStunTimeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffd03ba6 {
#define TREE_TU_END }
namespace fn_ffd03ba6 {} using namespace fn_ffd03ba6;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ffd03ba6 {
class TrackFactoryTemplate_57c80 {
  public:
    TrackFactoryTemplate_57c80() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053800();
typedef unsigned int u32_57cc0;
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct CCollisionPushbackYAngleCondition_57cc0 {
    hulk_uintptr vptr;
    char pad[8];
    int fieldC;
    int field10;
    void Init(int);
};
extern u32_57cc0 CCollisionPushbackYAngleCondition_vftable_57cc0;
extern int g_vftable_57d00;
struct ConditionFactoryTemplate_57d00 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ffd03ba6

// 0x00057c80 fight::ConditionFactoryCasterTemplate<CCollisionStunTimeCondition>::vfunc_1 (60 B): matches/0x00057c80.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionStunTimeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionStunTimeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57c80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57c80* t = new (mem) TrackFactoryTemplate_57c80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053800();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057cc0 fight::ConditionFactoryTemplate<CCollisionStunTimeCondition>::vfunc_5 (54 B): matches/0x00057cc0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionStunTimeCondition@@@fight@@UAEPAXXZ
// Same code shape as 0x00057c10 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<CCollisionStunTimeCondition>::vfunc_5() {
    CCollisionPushbackYAngleCondition_57cc0* p = (CCollisionPushbackYAngleCondition_57cc0*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (hulk_uintptr)&CCollisionPushbackYAngleCondition_vftable_57cc0;
        p->fieldC = 5;
        p->field10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ffd03ba6 {

// 0x00057d00 fight::ConditionFactoryTemplate<CCollisionStunTimeCondition>::vfunc_2 (43 B): matches/0x00057d00.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57d00@fn_ffd03ba6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57d00::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_57d00;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffd03ba6
