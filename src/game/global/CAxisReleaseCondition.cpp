// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00056f70..0x00057040 (kind game, layer game, confidence high), dominant class CAxisReleaseCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f26d4621 {
#define TREE_TU_END }
namespace fn_f26d4621 {} using namespace fn_f26d4621;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f26d4621 {
class TrackFactoryTemplate_56f70 {
  public:
    TrackFactoryTemplate_56f70() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f9114;
struct ConditionFactoryTemplate_56fb0 {
    void* m_vptr;
    void base1_dtor_00048680();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003f9130[];
extern "C" void* __cdecl Allocate(unsigned int);
class CAxisReleaseCondition_56fe0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    void Init_000486b0();
};
extern void* hulk_at_003f6d50[];
class CAxisTimeCondition_57010 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f26d4621
class CAxisReleaseCondition : public CAxisTimeCondition_57010 {
  public:
    CAxisReleaseCondition* vfunc_5(signed char flags);
};


// 0x00056f70 fight::ConditionFactoryCasterTemplate<CAxisReleaseCondition>::vfunc_1 (60 B): matches/0x00056f70.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAxisReleaseCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAxisReleaseCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_56f70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_56f70* t = new (mem) TrackFactoryTemplate_56f70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00052a40();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f26d4621 {

// 0x00056fb0 fight::ConditionFactoryTemplate<CAxisReleaseCondition>::vfunc_2 (43 B): matches/0x00056fb0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_56fb0@fn_f26d4621@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_56fb0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9114;
    base1_dtor_00048680();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f26d4621

// 0x00056fe0 fight::ConditionFactoryTemplate<CAxisReleaseCondition>::vfunc_5 (38 B): matches/0x00056fe0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCAxisReleaseCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CAxisReleaseCondition>::vfunc_5() {
    CAxisReleaseCondition_56fe0* p = (CAxisReleaseCondition_56fe0*)Allocate(0x18);
    if (p) {
        p->Init_000486b0();
        *(void**)p = (void*)((hulk_intptr)DAT_003f9130);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00057010 CAxisReleaseCondition::vfunc_5 (36 B): matches/0x00057010.cpp
// sym: ?vfunc_5@CAxisReleaseCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisReleaseCondition* CAxisReleaseCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

