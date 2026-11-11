// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a5e0..0x0012a690 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDistanceYCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa44f589 {
#define TREE_TU_END }
namespace fn_fa44f589 {} using namespace fn_fa44f589;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fa44f589 {
class TrackFactoryTemplate_12a5e0 {
  public:
    TrackFactoryTemplate_12a5e0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001288e0();
extern "C" char DAT_0040fdd4[];
typedef unsigned int u32_12a620;
extern "C" void* FUN_0008d690(hulk_uintptr);
class InitBase_12a620 {
  public:
    void Init(int);
};
struct TargetDistanceYCondition_12a620 : InitBase_12a620 {
    hulk_uintptr vptr;
    u32_12a620 pad1;
    u32_12a620 pad2;
    int a;
    int b;
    u8 c, d, e;
};
extern int g_vftable_12a660;
struct ConditionFactoryTemplate_12a660 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fa44f589

// 0x0012a5e0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_1 (60 B): matches/0x0012a5e0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetDistanceYCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a5e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a5e0* t = new (mem) TrackFactoryTemplate_12a5e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001288e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012a620 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_5 (59 B): matches/0x0012a620.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetDistanceYCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_5() {
    TargetDistanceYCondition_12a620* p = (TargetDistanceYCondition_12a620*)FUN_0008d690((int)sizeof(TargetDistanceYCondition_12a620));
    if (p != 0) {
        p->Init(0);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->vptr = ((hulk_intptr)DAT_0040fdd4);
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fa44f589 {

// 0x0012a660 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_2 (43 B): matches/0x0012a660.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a660@fn_fa44f589@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a660::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_12a660;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fa44f589
