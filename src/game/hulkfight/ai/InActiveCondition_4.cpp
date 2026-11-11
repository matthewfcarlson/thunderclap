// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114400..0x001144b0 (kind game, layer game, confidence high), dominant class hulkfight::ai::InActiveCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc88775a {
#define TREE_TU_END }
namespace fn_fc88775a {} using namespace fn_fc88775a;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc88775a {
class TrackFactoryTemplate_114400 {
  public:
    TrackFactoryTemplate_114400() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112200();
class InActiveCondition_114440 {
  public:
    hulk_uintptr vptr;
    char pad4[8];
    int fieldC;
    char field10;
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_0040dac4;
extern int hulk_at_0040e8dc;
struct ConditionFactoryTemplate_114480 {
    void* m_vptr;
    void base1_dtor_0010cd80();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc88775a

// 0x00114400 fight::ConditionFactoryCasterTemplate<hulkfight::ai::InActiveCondition>::vfunc_1 (60 B): matches/0x00114400.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VInActiveCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::InActiveCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114400));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114400* t = new (mem) TrackFactoryTemplate_114400();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112200();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114440 fight::ConditionFactoryTemplate<hulkfight::ai::InActiveCondition>::vfunc_5 (51 B): matches/0x00114440.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VInActiveCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::InActiveCondition>::vfunc_5() {
    InActiveCondition_114440* p = (InActiveCondition_114440*)FUN_0008d690((int)sizeof(InActiveCondition_114440));
    if (p) {
        p->Init_00234590(0);
        p->vptr = (hulk_uintptr)&hulk_at_0040dac4;
        p->fieldC = 0;
        p->field10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc88775a {

// 0x00114480 fight::ConditionFactoryTemplate<hulkfight::ai::InActiveCondition>::vfunc_2 (43 B): matches/0x00114480.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_114480@fn_fc88775a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_114480::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e8dc;
    base1_dtor_0010cd80();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc88775a
