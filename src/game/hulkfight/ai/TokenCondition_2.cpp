// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001146d0..0x00114770 (kind game, layer game, confidence high), dominant class hulkfight::ai::TokenCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcf8ca27 {
#define TREE_TU_END }
namespace fn_fcf8ca27 {} using namespace fn_fcf8ca27;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcf8ca27 {
class TrackFactoryTemplate_1146d0 {
  public:
    TrackFactoryTemplate_1146d0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112570();
extern "C" char DAT_0040db44[];
typedef unsigned int u32_114710;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct InitObj_114710 {
    void Init_00234590(int);
};
extern int hulk_at_0040e94c;
struct ConditionFactoryTemplate_114740 {
    void* m_vptr;
    void base1_dtor_0010cfa0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fcf8ca27

// 0x001146d0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TokenCondition>::vfunc_1 (60 B): matches/0x001146d0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTokenCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TokenCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1146d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1146d0* t = new (mem) TrackFactoryTemplate_1146d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112570();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114710 fight::ConditionFactoryTemplate<hulkfight::ai::TokenCondition>::vfunc_5 (48 B): matches/0x00114710.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTokenCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TokenCondition>::vfunc_5() {
    void* p = FUN_0008d690(0x10);
    if (p) {
        ((InitObj_114710*)p)->Init_00234590(0);
        ((u8*)p)[0xc] = 1;
        ((u8*)p)[0xd] = 1;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040db44);
        return (void*)(p);
    }
    return (void*)((void*)0);
}

namespace fn_fcf8ca27 {

// 0x00114740 fight::ConditionFactoryTemplate<hulkfight::ai::TokenCondition>::vfunc_2 (43 B): matches/0x00114740.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_114740@fn_fcf8ca27@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_114740::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e94c;
    base1_dtor_0010cfa0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fcf8ca27
