// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e2e0..0x0016e380 (kind game, layer game, confidence high), dominant class hulkfight::motion::ThinkingCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f53a7970 {
#define TREE_TU_END }
namespace fn_f53a7970 {} using namespace fn_f53a7970;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f53a7970 {
class TrackFactoryTemplate_16e2e0 {
  public:
    TrackFactoryTemplate_16e2e0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016bdf0();
extern "C" char DAT_004169b8[];
struct Obj_16e320 {
    hulk_intptr vf;
    char pad[8];
    unsigned char flag;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int g_vftable_16e350;
struct ConditionFactoryTemplate_16e350 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f53a7970

// 0x0016e2e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::ThinkingCondition>::vfunc_1 (60 B): matches/0x0016e2e0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VThinkingCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::ThinkingCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e2e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16e2e0* t = new (mem) TrackFactoryTemplate_16e2e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016bdf0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e320 fight::ConditionFactoryTemplate<hulkfight::motion::ThinkingCondition>::vfunc_5 (44 B): matches/0x0016e320.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VThinkingCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::ThinkingCondition>::vfunc_5() {
    Obj_16e320* p = (Obj_16e320*)FUN_0008d690((int)sizeof(Obj_16e320));
    if (p) {
        p->Init(0);
        p->vf = ((hulk_intptr)DAT_004169b8);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)((Obj_16e320*)0);
}

namespace fn_f53a7970 {

// 0x0016e350 fight::ConditionFactoryTemplate<hulkfight::motion::ThinkingCondition>::vfunc_2 (43 B): matches/0x0016e350.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e350@fn_f53a7970@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e350::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_16e350;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f53a7970
