// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058a70..0x00058b20 (kind game, layer game, confidence high), dominant class CSmartPropWeaponizableTypeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fba35ab2 {
#define TREE_TU_END }
namespace fn_fba35ab2 {} using namespace fn_fba35ab2;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fba35ab2 {
class TrackFactoryTemplate_58a70 {
  public:
    TrackFactoryTemplate_58a70() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000539a0();
extern "C" char DAT_003f7130[];
class Condition_58ab0 {
  public:
    void init(int);
};
class CSmartPropWeaponizableTypeCondition_58ab0 {
  public:
    hulk_uintptr vptr;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int g_vftable_58af0;
struct ConditionFactoryTemplate_58af0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fba35ab2

// 0x00058a70 fight::ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition>::vfunc_1 (60 B): matches/0x00058a70.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropWeaponizableTypeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58a70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58a70* t = new (mem) TrackFactoryTemplate_58a70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000539a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058ab0 fight::ConditionFactoryTemplate<CSmartPropWeaponizableTypeCondition>::vfunc_5 (54 B): matches/0x00058ab0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCSmartPropWeaponizableTypeCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CSmartPropWeaponizableTypeCondition>::vfunc_5() {
    CSmartPropWeaponizableTypeCondition_58ab0* p = (CSmartPropWeaponizableTypeCondition_58ab0*)FUN_0008d690((int)sizeof(CSmartPropWeaponizableTypeCondition_58ab0));
    if (p) {
        ((Condition_58ab0*)p)->init(0);
        p->vptr = ((hulk_intptr)DAT_003f7130);
        p->c = 0;
        p->d = 0xffffffff;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fba35ab2 {

// 0x00058af0 fight::ConditionFactoryTemplate<CSmartPropWeaponizableTypeCondition>::vfunc_2 (43 B): matches/0x00058af0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58af0@fn_fba35ab2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58af0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_58af0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fba35ab2
