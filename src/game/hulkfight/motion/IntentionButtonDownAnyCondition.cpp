// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d410..0x0016d4b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::IntentionButtonDownAnyCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6697388 {
#define TREE_TU_END }
namespace fn_f6697388 {} using namespace fn_f6697388;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f6697388 {
class TrackFactoryTemplate_16d410 {
  public:
    TrackFactoryTemplate_16d410() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016afa0();
extern "C" char DAT_00416698[];
class AllocThing {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class InitThing {
  public:
    void Init_00234590(int);
};
extern int hulk_at_00417530;
struct ConditionFactoryTemplate_16d480 {
    void* m_vptr;
    void base1_dtor_00165b10();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f6697388

// 0x0016d410 fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_1 (60 B): matches/0x0016d410.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VIntentionButtonDownAnyCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d410));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16d410* t = new (mem) TrackFactoryTemplate_16d410();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016afa0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016d450 fight::ConditionFactoryTemplate<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_5 (44 B): matches/0x0016d450.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VIntentionButtonDownAnyCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_5() {
    InitThing* p = (InitThing*)FUN_0008d690(0x10);
    if (p) {
        p->Init_00234590(0);
        *(void**)p = (void*)((hulk_intptr)DAT_00416698);
        *((char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)((void*)0);
}

namespace fn_f6697388 {

// 0x0016d480 fight::ConditionFactoryTemplate<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_2 (43 B): matches/0x0016d480.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d480@fn_f6697388@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d480::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00417530;
    base1_dtor_00165b10();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f6697388
