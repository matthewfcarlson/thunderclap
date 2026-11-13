// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d980..0x0016da20 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetingCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbe157e8 {
#define TREE_TU_END }
namespace fn_fbe157e8 {} using namespace fn_fbe157e8;
namespace fn_fbe157e8 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbe157e8 {
class TrackFactoryTemplate_16d980 {
  public:
    TrackFactoryTemplate_16d980() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b540();
extern "C" char DAT_004167d8[];
class TargetingCondition_16d9c0 {
  public:
    TargetingCondition_16d9c0(int);
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init_00234590(int);
    char pad[12];
    char flag;
};
extern "C" void* FUN_0008d690(unsigned int);
extern int hulk_at_00417610;
struct ConditionFactoryTemplate_16d9f0 {
    void* m_vptr;
    void base1_dtor_00165fa0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbe157e8

// 0x0016d980 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetingCondition>::vfunc_1 (60 B): matches/0x0016d980.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetingCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetingCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d980));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_16d980* t = new (mem) TrackFactoryTemplate_16d980();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b540();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016d9c0 fight::ConditionFactoryTemplate<hulkfight::motion::TargetingCondition>::vfunc_5 (44 B): matches/0x0016d9c0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetingCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TargetingCondition>::vfunc_5() {
    TargetingCondition_16d9c0* p = (TargetingCondition_16d9c0*)FUN_0008d690(0x10);
    if (p) {
        p->Init_00234590(0);
        *(void**)p = (void*)((hulk_intptr)DAT_004167d8);
        *((char*)p + 0xc) = 1;
    } else {
        p = 0;
    }
    return (void*)(p);
}

namespace fn_fbe157e8 {

// 0x0016d9f0 fight::ConditionFactoryTemplate<hulkfight::motion::TargetingCondition>::vfunc_2 (43 B): matches/0x0016d9f0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d9f0@fn_fbe157e8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d9f0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00417610;
    base1_dtor_00165fa0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fbe157e8
