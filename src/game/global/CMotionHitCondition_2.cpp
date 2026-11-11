// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058460..0x00058510 (kind game, layer game, confidence high), dominant class CMotionHitCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4054f60 {
#define TREE_TU_END }
namespace fn_f4054f60 {} using namespace fn_f4054f60;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4054f60 {
class TrackFactoryTemplate_58460 {
  public:
    TrackFactoryTemplate_58460() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000540a0();
extern "C" char DAT_003f73bc[];
extern "C" void* __cdecl Allocate(unsigned int);
struct CMotionHitCondition_584a0 {
    hulk_uintptr vtable;
    unsigned int pad1;
    unsigned int pad2;
    unsigned int value;
    unsigned int value2;
    void Init_00234590(int);
};
extern int hulk_at_003f95b0;
struct ConditionFactoryTemplate_584e0 {
    void* m_vptr;
    void base1_dtor_0004a310();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4054f60

// 0x00058460 fight::ConditionFactoryCasterTemplate<CMotionHitCondition>::vfunc_1 (60 B): matches/0x00058460.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCMotionHitCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CMotionHitCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58460));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58460* t = new (mem) TrackFactoryTemplate_58460();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000540a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000584a0 fight::ConditionFactoryTemplate<CMotionHitCondition>::vfunc_5 (54 B): matches/0x000584a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCMotionHitCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CMotionHitCondition>::vfunc_5() {
    CMotionHitCondition_584a0* p = (CMotionHitCondition_584a0*)Allocate(0x14);
    if (p) {
        p->Init_00234590(0);
        p->vtable = ((hulk_intptr)DAT_003f73bc);
        p->value = 0;
        p->value2 = 2;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f4054f60 {

// 0x000584e0 fight::ConditionFactoryTemplate<CMotionHitCondition>::vfunc_2 (43 B): matches/0x000584e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_584e0@fn_f4054f60@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_584e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f95b0;
    base1_dtor_0004a310();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4054f60
