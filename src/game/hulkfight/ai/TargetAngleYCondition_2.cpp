// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a480..0x0012a530 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetAngleYCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6e5a698 {
#define TREE_TU_END }
namespace fn_f6e5a698 {} using namespace fn_f6e5a698;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f6e5a698 {
class TrackFactoryTemplate_12a480 {
  public:
    TrackFactoryTemplate_12a480() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128780();
extern "C" char DAT_0040fd94[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class InitObj_12a4c0 {
  public:
    void Init(int);
};
extern int g_vftable_12a500;
struct ConditionFactoryTemplate_12a500 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f6e5a698

// 0x0012a480 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_1 (60 B): matches/0x0012a480.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetAngleYCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a480));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a480* t = new (mem) TrackFactoryTemplate_12a480();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128780();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012a4c0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_5 (54 B): matches/0x0012a4c0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetAngleYCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_5() {
    void* p = FUN_0008d690(0x14);
    if (p) {
        ((InitObj_12a4c0*)p)->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040fd94);
        *(unsigned int*)((char*)p + 0x0c) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f6e5a698 {

// 0x0012a500 fight::ConditionFactoryTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_2 (43 B): matches/0x0012a500.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a500@fn_f6e5a698@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a500::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_12a500;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f6e5a698
