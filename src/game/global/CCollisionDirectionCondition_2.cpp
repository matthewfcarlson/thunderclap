// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057710..0x000577c0 (kind game, layer game, confidence high), dominant class CCollisionDirectionCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff1234ab {
#define TREE_TU_END }
namespace fn_ff1234ab {} using namespace fn_ff1234ab;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff1234ab {
class TrackFactoryTemplate_57710 {
  public:
    TrackFactoryTemplate_57710() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000533a0();
extern "C" char DAT_003f6fc8[];
typedef unsigned int u32_57750;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct CCollisionDirectionCondition_57750 {
    hulk_uintptr vptr;
    u32_57750 pad4, pad8, fieldC, field10;
    void Init_00234590(int);
};
extern int hulk_at_003f934c;
struct ConditionFactoryTemplate_57790 {
    void* m_vptr;
    void base1_dtor_00048c50();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff1234ab

// 0x00057710 fight::ConditionFactoryCasterTemplate<CCollisionDirectionCondition>::vfunc_1 (60 B): matches/0x00057710.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionDirectionCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionDirectionCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57710));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57710* t = new (mem) TrackFactoryTemplate_57710();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000533a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057750 fight::ConditionFactoryTemplate<CCollisionDirectionCondition>::vfunc_5 (54 B): matches/0x00057750.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionDirectionCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCollisionDirectionCondition>::vfunc_5() {
    CCollisionDirectionCondition_57750* p = (CCollisionDirectionCondition_57750*)FUN_0008d690((int)sizeof(CCollisionDirectionCondition_57750));
    if (p) {
        p->Init_00234590(0);
        p->vptr = ((hulk_intptr)DAT_003f6fc8);
        p->fieldC = 0;
        p->field10 = 0x3fc90fdb;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ff1234ab {

// 0x00057790 fight::ConditionFactoryTemplate<CCollisionDirectionCondition>::vfunc_2 (43 B): matches/0x00057790.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57790@fn_ff1234ab@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57790::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f934c;
    base1_dtor_00048c50();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff1234ab
