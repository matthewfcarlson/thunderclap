// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00158f00..0x00158fb0 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptAccumulatorCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb2816f1 {
#define TREE_TU_END }
namespace fn_fb2816f1 {} using namespace fn_fb2816f1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb2816f1 {
class TrackFactoryTemplate_158f00 {
  public:
    TrackFactoryTemplate_158f00() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001550b0();
extern "C" char DAT_00413f70[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct Obj_158f40 {
    hulk_uintptr vt;
    int pad[2];
    int a;
    int b;
    void Init_00234590(int);
};
extern int hulk_at_0041551c;
struct ConditionFactoryTemplate_158f80 {
    void* m_vptr;
    void base1_dtor_0014d250();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb2816f1

// 0x00158f00 fight::ConditionFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_1 (60 B): matches/0x00158f00.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_158f00));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_158f00* t = new (mem) TrackFactoryTemplate_158f00();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001550b0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00158f40 fight::ConditionFactoryTemplate<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_5 (54 B): matches/0x00158f40.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_5() {
    Obj_158f40* p = (Obj_158f40*)FUN_0008d690((int)sizeof(Obj_158f40));
    if (p) {
        p->Init_00234590(0);
        p->vt = ((hulk_intptr)DAT_00413f70);
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fb2816f1 {

// 0x00158f80 fight::ConditionFactoryTemplate<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_2 (43 B): matches/0x00158f80.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_158f80@fn_fb2816f1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_158f80::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041551c;
    base1_dtor_0014d250();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb2816f1
