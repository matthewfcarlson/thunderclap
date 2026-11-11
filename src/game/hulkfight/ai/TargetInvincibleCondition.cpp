// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012ad50..0x0012adf0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetInvincibleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f89653d6 {
#define TREE_TU_END }
namespace fn_f89653d6 {} using namespace fn_f89653d6;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f89653d6 {
class TrackFactoryTemplate_12ad50 {
  public:
    TrackFactoryTemplate_12ad50() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00129170();
extern "C" char DAT_0040ff34[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TargetInvincibleCondition_12ad90 {
  public:
    TargetInvincibleCondition_12ad90(int);
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    unsigned char flag;
};
extern int hulk_at_00410b10;
struct ConditionFactoryTemplate_12adc0 {
    void* m_vptr;
    void base1_dtor_00124220();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f89653d6

// 0x0012ad50 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_1 (60 B): matches/0x0012ad50.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetInvincibleCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12ad50));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12ad50* t = new (mem) TrackFactoryTemplate_12ad50();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00129170();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012ad90 fight::ConditionFactoryTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_5 (44 B): matches/0x0012ad90.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetInvincibleCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_5() {
    TargetInvincibleCondition_12ad90* p = (TargetInvincibleCondition_12ad90*)FUN_0008d690((int)sizeof(TargetInvincibleCondition_12ad90));
    if (p) {
        p->TargetInvincibleCondition_12ad90::TargetInvincibleCondition_12ad90(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040ff34);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)((TargetInvincibleCondition_12ad90*)0);
}

namespace fn_f89653d6 {

// 0x0012adc0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_2 (43 B): matches/0x0012adc0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12adc0@fn_f89653d6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12adc0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410b10;
    base1_dtor_00124220();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f89653d6
