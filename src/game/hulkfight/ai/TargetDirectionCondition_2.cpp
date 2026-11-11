// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a530..0x0012a5e0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDirectionCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f27f3b52 {
#define TREE_TU_END }
namespace fn_f27f3b52 {} using namespace fn_f27f3b52;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f27f3b52 {
class TrackFactoryTemplate_12a530 {
  public:
    TrackFactoryTemplate_12a530() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128830();
extern "C" char DAT_0040fdb4[];
extern "C" void* __cdecl FUN_0008d690(int);
class Target_12a570 {
  public:
    void Init_00234590(int);
};
extern int hulk_at_004109c0;
struct ConditionFactoryTemplate_12a5b0 {
    void* m_vptr;
    void base1_dtor_00123d00();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f27f3b52

// 0x0012a530 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionCondition>::vfunc_1 (60 B): matches/0x0012a530.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetDirectionCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a530));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a530* t = new (mem) TrackFactoryTemplate_12a530();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128830();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012a570 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionCondition>::vfunc_5 (54 B): matches/0x0012a570.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetDirectionCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionCondition>::vfunc_5() {
    Target_12a570* p = (Target_12a570*)FUN_0008d690(0x14);
    if (p) {
        p->Init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0040fdb4);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f27f3b52 {

// 0x0012a5b0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionCondition>::vfunc_2 (43 B): matches/0x0012a5b0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a5b0@fn_f27f3b52@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a5b0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004109c0;
    base1_dtor_00123d00();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f27f3b52
