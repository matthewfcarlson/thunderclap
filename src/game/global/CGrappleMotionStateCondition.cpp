// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057eb0..0x00057f80 (kind game, layer game, confidence high), dominant class CGrappleMotionStateCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe1aa6b6 {
#define TREE_TU_END }
namespace fn_fe1aa6b6 {} using namespace fn_fe1aa6b6;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe1aa6b6 {
class TrackFactoryTemplate_57eb0 {
  public:
    TrackFactoryTemplate_57eb0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f94a8;
struct ConditionFactoryTemplate_57ef0 {
    void* m_vptr;
    void base1_dtor_0004a1f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
struct CFightNodeTimeCondition_57f20 {
    virtual ~CFightNodeTimeCondition_57f20();
    char pad[0x10];
    void Initialize_0004a220();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* hulk_at_003f6d50[];
class CMotionStateCondition_57f50 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fe1aa6b6
class CGrappleMotionStateCondition : public CMotionStateCondition_57f50 {
  public:
    CGrappleMotionStateCondition* vfunc_5(signed char flags);
};


// 0x00057eb0 fight::ConditionFactoryCasterTemplate<CGrappleMotionStateCondition>::vfunc_1 (60 B): matches/0x00057eb0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCGrappleMotionStateCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CGrappleMotionStateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57eb0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57eb0* t = new (mem) TrackFactoryTemplate_57eb0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053fe0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fe1aa6b6 {

// 0x00057ef0 fight::ConditionFactoryTemplate<CGrappleMotionStateCondition>::vfunc_2 (43 B): matches/0x00057ef0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57ef0@fn_fe1aa6b6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57ef0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f94a8;
    base1_dtor_0004a1f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fe1aa6b6

// 0x00057f20 fight::ConditionFactoryTemplate<CGrappleMotionStateCondition>::vfunc_5 (38 B): matches/0x00057f20.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCGrappleMotionStateCondition@@@fight@@UAEPAXXZ
// Same code shape as 0x000521a0 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<CGrappleMotionStateCondition>::vfunc_5() {
    CFightNodeTimeCondition_57f20* p = (CFightNodeTimeCondition_57f20*)FUN_0008d690((int)sizeof(CFightNodeTimeCondition_57f20));
    if (p) {
        p->Initialize_0004a220();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00057f50 CGrappleMotionStateCondition::vfunc_5 (36 B): matches/0x00057f50.cpp
// sym: ?vfunc_5@CGrappleMotionStateCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleMotionStateCondition* CGrappleMotionStateCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

