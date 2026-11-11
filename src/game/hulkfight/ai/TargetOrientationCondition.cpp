// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a690..0x0012a740 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetOrientationCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f31675a1 {
#define TREE_TU_END }
namespace fn_f31675a1 {} using namespace fn_f31675a1;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f31675a1 {
class TrackFactoryTemplate_12a690 {
  public:
    TrackFactoryTemplate_12a690() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128a30();
extern "C" char DAT_0040fdf4[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct Target_12a6d0 {
    hulk_uintptr vt;
    unsigned int a;
    unsigned int b;
    unsigned int zero;
    float angle;
};
struct Init_12a6d0 {
    void initialize_00234590(int);
};
extern int hulk_at_004109f8;
struct ConditionFactoryTemplate_12a710 {
    void* m_vptr;
    void base1_dtor_00123de0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f31675a1

// 0x0012a690 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetOrientationCondition>::vfunc_1 (60 B): matches/0x0012a690.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetOrientationCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetOrientationCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a690));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a690* t = new (mem) TrackFactoryTemplate_12a690();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128a30();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012a6d0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetOrientationCondition>::vfunc_5 (54 B): matches/0x0012a6d0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetOrientationCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetOrientationCondition>::vfunc_5() {
    Target_12a6d0* p = (Target_12a6d0*)FUN_0008d690((int)sizeof(Target_12a6d0));
    if (p) {
        ((Init_12a6d0*)p)->initialize_00234590(0);
        p->vt = ((hulk_intptr)DAT_0040fdf4);
        p->zero = 0;
        p->angle = 3.1415927f;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f31675a1 {

// 0x0012a710 fight::ConditionFactoryTemplate<hulkfight::ai::TargetOrientationCondition>::vfunc_2 (43 B): matches/0x0012a710.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a710@fn_f31675a1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a710::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004109f8;
    base1_dtor_00123de0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f31675a1
