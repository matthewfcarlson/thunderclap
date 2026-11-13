// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057290..0x00057360 (kind game, layer game, confidence high), dominant class CButtonPressCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fafd18b7 {
#define TREE_TU_END }
namespace fn_fafd18b7 {} using namespace fn_fafd18b7;
namespace fn_fafd18b7 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fafd18b7 {
class TrackFactoryTemplate_57290 {
  public:
    TrackFactoryTemplate_57290() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f9214;
struct ConditionFactoryTemplate_572d0 {
    void* m_vptr;
    void base1_dtor_000484f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003f9230[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CButtonPressCondition_57300 {
  public:
    CButtonPressCondition_57300();
};
extern void* hulk_at_003f6d50[];
class CButtonValueCondition_57330 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fafd18b7
class CButtonPressCondition : public CButtonValueCondition_57330 {
  public:
    CButtonPressCondition* vfunc_5(signed char flags);
};


// 0x00057290 fight::ConditionFactoryCasterTemplate<CButtonPressCondition>::vfunc_1 (60 B): matches/0x00057290.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCButtonPressCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CButtonPressCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57290));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_57290* t = new (mem) TrackFactoryTemplate_57290();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000528d0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fafd18b7 {

// 0x000572d0 fight::ConditionFactoryTemplate<CButtonPressCondition>::vfunc_2 (43 B): matches/0x000572d0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_572d0@fn_fafd18b7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_572d0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9214;
    base1_dtor_000484f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fafd18b7

// 0x00057300 fight::ConditionFactoryTemplate<CButtonPressCondition>::vfunc_5 (38 B): matches/0x00057300.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCButtonPressCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CButtonPressCondition>::vfunc_5() {
    CButtonPressCondition_57300* p = (CButtonPressCondition_57300*)FUN_0008d690(0x20);
    if (p) {
        p->CButtonPressCondition_57300::CButtonPressCondition_57300();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f9230);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00057330 CButtonPressCondition::vfunc_5 (36 B): matches/0x00057330.cpp
// sym: ?vfunc_5@CButtonPressCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CButtonPressCondition* CButtonPressCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

