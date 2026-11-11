// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058250..0x00058300 (kind game, layer game, confidence high), dominant class CIntentionSpeedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8c6c731 {
#define TREE_TU_END }
namespace fn_f8c6c731 {} using namespace fn_f8c6c731;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8c6c731 {
class TrackFactoryTemplate_58250 {
  public:
    TrackFactoryTemplate_58250() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00054750();
typedef unsigned int u32_58290;
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct CCollisionPushbackYAngleCondition_58290 {
    hulk_uintptr vptr;
    char pad[8];
    int fieldC;
    int field10;
    void Init_00234590(int);
};
extern u32_58290 hulk_at_003f7504;
extern int hulk_at_003f955c;
struct ConditionFactoryTemplate_582d0 {
    void* m_vptr;
    void base1_dtor_0004a900();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f8c6c731

// 0x00058250 fight::ConditionFactoryCasterTemplate<CIntentionSpeedCondition>::vfunc_1 (60 B): matches/0x00058250.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCIntentionSpeedCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CIntentionSpeedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58250));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58250* t = new (mem) TrackFactoryTemplate_58250();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00054750();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058290 fight::ConditionFactoryTemplate<CIntentionSpeedCondition>::vfunc_5 (54 B): matches/0x00058290.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCIntentionSpeedCondition@@@fight@@UAEPAXXZ
// Same code shape as 0x00057c10 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<CIntentionSpeedCondition>::vfunc_5() {
    CCollisionPushbackYAngleCondition_58290* p = (CCollisionPushbackYAngleCondition_58290*)Alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        p->vptr = (hulk_uintptr)&hulk_at_003f7504;
        p->fieldC = 5;
        p->field10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f8c6c731 {

// 0x000582d0 fight::ConditionFactoryTemplate<CIntentionSpeedCondition>::vfunc_2 (43 B): matches/0x000582d0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_582d0@fn_f8c6c731@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_582d0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f955c;
    base1_dtor_0004a900();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8c6c731
