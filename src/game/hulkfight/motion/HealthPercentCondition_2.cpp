// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e230..0x0016e2e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HealthPercentCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe77683c {
#define TREE_TU_END }
namespace fn_fe77683c {} using namespace fn_fe77683c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe77683c {
class TrackFactoryTemplate_16e230 {
  public:
    TrackFactoryTemplate_16e230() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016bd40();
} // namespace fn_fe77683c
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_fe77683c {
class Condition_16e270 {
  public:
    virtual hulk_intptr f0_00166640(int);
    virtual bool f1_00234270(void*);
    virtual bool f2_002342b0(int);
    virtual bool f3_002344d0(hulk_intptr, int, hulk_intptr);
    virtual bool f4_00234350(int, int);
    virtual void f5();
    Condition_16e270(int) throw();
    char pad[8];
};
class HealthPercentCondition_16e270 : public Condition_16e270 {
  public:
    HealthPercentCondition_16e270() throw() : Condition_16e270(0), a(0), b(0) {}
    virtual void f5();
    int a;
    int b;
};
extern int hulk_at_0041777c;
struct ConditionFactoryTemplate_16e2b0 {
    void* m_vptr;
    void base1_dtor_00166620();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe77683c

// 0x0016e230 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_1 (60 B): matches/0x0016e230.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e230));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16e230* t = new (mem) TrackFactoryTemplate_16e230();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016bd40();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e270 fight::ConditionFactoryTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_5 (54 B): matches/0x0016e270.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_5() {
    return (void*)(new HealthPercentCondition_16e270);
}

namespace fn_fe77683c {

// 0x0016e2b0 fight::ConditionFactoryTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_2 (43 B): matches/0x0016e2b0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e2b0@fn_fe77683c@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e2b0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041777c;
    base1_dtor_00166620();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fe77683c
