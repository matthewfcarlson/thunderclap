// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012aaa0..0x0012ab50 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbf50673 {
#define TREE_TU_END }
namespace fn_fbf50673 {} using namespace fn_fbf50673;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbf50673 {
class TrackFactoryTemplate_12aaa0 {
  public:
    TrackFactoryTemplate_12aaa0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128ed0();
extern "C" char DAT_0040feb4[];
typedef unsigned int u32_12aae0;
struct AcquireTargetCondition_12aae0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad4[8];
    float a;
    float b;
    u8 c;
    void Initialize(int);
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int g_vftable_12ab20;
struct ConditionFactoryTemplate_12ab20 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbf50673

// 0x0012aaa0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::AcquireTargetCondition>::vfunc_1 (60 B): matches/0x0012aaa0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::AcquireTargetCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12aaa0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12aaa0* t = new (mem) TrackFactoryTemplate_12aaa0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128ed0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012aae0 fight::ConditionFactoryTemplate<hulkfight::ai::AcquireTargetCondition>::vfunc_5 (58 B): matches/0x0012aae0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::AcquireTargetCondition>::vfunc_5() {
    AcquireTargetCondition_12aae0* p = (AcquireTargetCondition_12aae0*)FUN_0008d690((int)sizeof(AcquireTargetCondition_12aae0));
    if (p) {
        p->Initialize(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040feb4);
        p->a = 1.57079637f;
        p->b = 100.0f;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fbf50673 {

// 0x0012ab20 fight::ConditionFactoryTemplate<hulkfight::ai::AcquireTargetCondition>::vfunc_2 (43 B): matches/0x0012ab20.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12ab20@fn_fbf50673@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12ab20::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_12ab20;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbf50673
