// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d770..0x0016d820 (kind game, layer game, confidence high), dominant class hulkfight::motion::IntentionInputCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f28f7103 {
#define TREE_TU_END }
namespace fn_f28f7103 {} using namespace fn_f28f7103;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f28f7103 {
class TrackFactoryTemplate_16d770 {
  public:
    TrackFactoryTemplate_16d770() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b2c0();
typedef unsigned int u32_16d7b0;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct IntentionInputCondition_16d7b0 {
    u8 pad[16];
    void Init_00234590(int);
};
extern u32_16d7b0 hulk_at_00416758;
extern int hulk_at_004175bc;
struct ConditionFactoryTemplate_16d7f0 {
    void* m_vptr;
    void base1_dtor_00165dc0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f28f7103

// 0x0016d770 fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionInputCondition>::vfunc_1 (60 B): matches/0x0016d770.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VIntentionInputCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionInputCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d770));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16d770* t = new (mem) TrackFactoryTemplate_16d770();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b2c0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016d7b0 fight::ConditionFactoryTemplate<hulkfight::motion::IntentionInputCondition>::vfunc_5 (55 B): matches/0x0016d7b0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VIntentionInputCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::IntentionInputCondition>::vfunc_5() {
    IntentionInputCondition_16d7b0* p = (IntentionInputCondition_16d7b0*)FUN_0008d690((int)sizeof(IntentionInputCondition_16d7b0));
    if (p) {
        p->Init_00234590(0);
        ((u8*)p)[0xd] = 1;
        ((u8*)p)[0xe] = 1;
        ((u8*)p)[0xf] = 1;
        *(hulk_uintptr*)p = (hulk_uintptr)&hulk_at_00416758;
        ((u8*)p)[0xc] = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f28f7103 {

// 0x0016d7f0 fight::ConditionFactoryTemplate<hulkfight::motion::IntentionInputCondition>::vfunc_2 (43 B): matches/0x0016d7f0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d7f0@fn_f28f7103@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d7f0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004175bc;
    base1_dtor_00165dc0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f28f7103
