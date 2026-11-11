// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e4e0..0x0016e5b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastTargetCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f930926e {
#define TREE_TU_END }
namespace fn_f930926e {} using namespace fn_f930926e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f930926e {
class TrackFactoryTemplate_16e4e0 {
  public:
    TrackFactoryTemplate_16e4e0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016c600();
class Sub {
  public:
    Sub();
};
extern char VT_16e520[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int g_vftable_16e580;
struct ConditionFactoryTemplate_16e580 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f930926e

// 0x0016e4e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_1 (60 B): matches/0x0016e4e0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e4e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16e4e0* t = new (mem) TrackFactoryTemplate_16e4e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016c600();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e520 fight::ConditionFactoryTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_5 (85 B): matches/0x0016e520.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_5() {
    Child* p = (Child*)FUN_0008d690(0x38);
    if (p) {
        p->Child::Child(0);
        *(void**)p = VT_16e520;
        ((Sub*)((char*)p + 0x10))->Sub::Sub();
        *(int*)((char*)p + 0x18) = 0;
        *(int*)((char*)p + 0x1c) = 0;
        *(int*)((char*)p + 0x20) = 0;
        *(int*)((char*)p + 0x24) = 0;
        *(int*)((char*)p + 0x28) = 0;
        *(float*)((char*)p + 0x2c) = -1.0f;
        _ReadWriteBarrier();
        *(float*)((char*)p + 0x30) = 1.0f;
        *(char*)((char*)p + 0x34) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f930926e {

// 0x0016e580 fight::ConditionFactoryTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_2 (43 B): matches/0x0016e580.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e580@fn_f930926e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e580::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_16e580;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f930926e
