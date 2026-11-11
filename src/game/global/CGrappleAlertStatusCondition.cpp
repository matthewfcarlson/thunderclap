// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057de0..0x00057eb0 (kind game, layer game, confidence high), dominant class CGrappleAlertStatusCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9b6de1e {
#define TREE_TU_END }
namespace fn_f9b6de1e {} using namespace fn_f9b6de1e;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f9b6de1e {
class TrackFactoryTemplate_57de0 {
  public:
    TrackFactoryTemplate_57de0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f9464;
struct ConditionFactoryTemplate_57e20 {
    void* m_vptr;
    void base1_dtor_0004a470();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
struct CFightNodeTimeCondition_57e50 {
    virtual ~CFightNodeTimeCondition_57e50();
    char pad[0x10];
    void Initialize_0004a4a0();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* hulk_at_003f6d50[];
class CAlertStatusCondition_57e80 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9b6de1e
class CGrappleAlertStatusCondition : public CAlertStatusCondition_57e80 {
  public:
    CGrappleAlertStatusCondition* vfunc_5(signed char flags);
};


// 0x00057de0 fight::ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>::vfunc_1 (60 B): matches/0x00057de0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCGrappleAlertStatusCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57de0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57de0* t = new (mem) TrackFactoryTemplate_57de0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00054240();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f9b6de1e {

// 0x00057e20 fight::ConditionFactoryTemplate<CGrappleAlertStatusCondition>::vfunc_2 (43 B): matches/0x00057e20.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57e20@fn_f9b6de1e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57e20::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9464;
    base1_dtor_0004a470();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9b6de1e

// 0x00057e50 fight::ConditionFactoryTemplate<CGrappleAlertStatusCondition>::vfunc_5 (38 B): matches/0x00057e50.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCGrappleAlertStatusCondition@@@fight@@UAEPAXXZ
// Same code shape as 0x000521a0 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<CGrappleAlertStatusCondition>::vfunc_5() {
    CFightNodeTimeCondition_57e50* p = (CFightNodeTimeCondition_57e50*)FUN_0008d690((int)sizeof(CFightNodeTimeCondition_57e50));
    if (p) {
        p->Initialize_0004a4a0();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00057e80 CGrappleAlertStatusCondition::vfunc_5 (36 B): matches/0x00057e80.cpp
// sym: ?vfunc_5@CGrappleAlertStatusCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleAlertStatusCondition* CGrappleAlertStatusCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

