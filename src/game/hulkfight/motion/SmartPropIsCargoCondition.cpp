// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018bc20..0x0018bcc0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SmartPropIsCargoCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe26452e {
#define TREE_TU_END }
namespace fn_fe26452e {} using namespace fn_fe26452e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe26452e {
class TrackFactoryTemplate_18bc20 {
  public:
    TrackFactoryTemplate_18bc20() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187d40();
extern "C" char DAT_0041928c[];
class SmartPropIsCargoCondition_18bc60 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    int a, b, c, d;
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_0041a764;
struct ConditionFactoryTemplate_18bc90 {
    void* m_vptr;
    void base1_dtor_00180a80();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe26452e

// 0x0018bc20 fight::ConditionFactoryCasterTemplate<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_1 (60 B): matches/0x0018bc20.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VSmartPropIsCargoCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18bc20));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18bc20* t = new (mem) TrackFactoryTemplate_18bc20();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187d40();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018bc60 fight::ConditionFactoryTemplate<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_5 (47 B): matches/0x0018bc60.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VSmartPropIsCargoCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_5() {
    SmartPropIsCargoCondition_18bc60* p = (SmartPropIsCargoCondition_18bc60*)FUN_0008d690(0x10);
    if (p) {
        p->Init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0041928c);
        p->c = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fe26452e {

// 0x0018bc90 fight::ConditionFactoryTemplate<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_2 (43 B): matches/0x0018bc90.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18bc90@fn_fe26452e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18bc90::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a764;
    base1_dtor_00180a80();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fe26452e
