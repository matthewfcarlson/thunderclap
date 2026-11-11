// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057360..0x00057430 (kind game, layer game, confidence high), dominant class CButtonReleaseCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f55977f3 {
#define TREE_TU_END }
namespace fn_f55977f3 {} using namespace fn_f55977f3;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f55977f3 {
class TrackFactoryTemplate_57360 {
  public:
    TrackFactoryTemplate_57360() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f9260;
struct ConditionFactoryTemplate_573a0 {
    void* m_vptr;
    void base1_dtor_00048450();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003f927c[];
class CButtonReleaseCondition_573d0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void Init_00048480();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* hulk_at_003f6d50[];
class CButtonCondition_57400 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f55977f3
class CButtonReleaseCondition : public CButtonCondition_57400 {
  public:
    CButtonReleaseCondition* vfunc_5(signed char flags);
};


// 0x00057360 fight::ConditionFactoryCasterTemplate<CButtonReleaseCondition>::vfunc_1 (60 B): matches/0x00057360.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCButtonReleaseCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CButtonReleaseCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57360));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57360* t = new (mem) TrackFactoryTemplate_57360();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000527d0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f55977f3 {

// 0x000573a0 fight::ConditionFactoryTemplate<CButtonReleaseCondition>::vfunc_2 (43 B): matches/0x000573a0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_573a0@fn_f55977f3@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_573a0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9260;
    base1_dtor_00048450();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f55977f3

// 0x000573d0 fight::ConditionFactoryTemplate<CButtonReleaseCondition>::vfunc_5 (38 B): matches/0x000573d0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCButtonReleaseCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CButtonReleaseCondition>::vfunc_5() {
    CButtonReleaseCondition_573d0* p = (CButtonReleaseCondition_573d0*)FUN_0008d690(0x18);
    if (p) {
        p->Init_00048480();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f927c);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00057400 CButtonReleaseCondition::vfunc_5 (36 B): matches/0x00057400.cpp
// sym: ?vfunc_5@CButtonReleaseCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CButtonReleaseCondition* CButtonReleaseCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

