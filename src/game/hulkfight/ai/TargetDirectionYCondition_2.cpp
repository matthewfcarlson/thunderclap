// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a270..0x0012a320 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDirectionYCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4ffcb1d {
#define TREE_TU_END }
namespace fn_f4ffcb1d {} using namespace fn_f4ffcb1d;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4ffcb1d {
class TrackFactoryTemplate_12a270 {
  public:
    TrackFactoryTemplate_12a270() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001284f0();
extern "C" char DAT_0040fd14[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class TargetDirectionYCondition_12a2b0 {
  public:
    hulk_intptr v0;
    int pad4;
    int pad8;
    int x;
    int y;
};
class Base_12a2b0 {
  public:
    void Init(int);
};
extern int g_vftable_12a2f0;
struct ConditionFactoryTemplate_12a2f0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4ffcb1d

// 0x0012a270 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionYCondition>::vfunc_1 (60 B): matches/0x0012a270.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionYCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a270));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a270* t = new (mem) TrackFactoryTemplate_12a270();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001284f0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012a2b0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionYCondition>::vfunc_5 (54 B): matches/0x0012a2b0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionYCondition>::vfunc_5() {
    TargetDirectionYCondition_12a2b0* p = (TargetDirectionYCondition_12a2b0*)FUN_0008d690((int)sizeof(TargetDirectionYCondition_12a2b0));
    if (p) {
        ((Base_12a2b0*)p)->Init(0);
        p->v0 = ((hulk_intptr)DAT_0040fd14);
        p->x = 0;
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f4ffcb1d {

// 0x0012a2f0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionYCondition>::vfunc_2 (43 B): matches/0x0012a2f0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a2f0@fn_f4ffcb1d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a2f0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_12a2f0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4ffcb1d
