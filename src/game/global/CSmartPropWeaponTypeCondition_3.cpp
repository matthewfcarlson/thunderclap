// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058b20..0x00058bd0 (kind game, layer game, confidence high), dominant class CSmartPropWeaponTypeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb5c6613 {
#define TREE_TU_END }
namespace fn_fb5c6613 {} using namespace fn_fb5c6613;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb5c6613 {
class TrackFactoryTemplate_58b20 {
  public:
    TrackFactoryTemplate_58b20() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053a50();
extern "C" char DAT_003f7154[];
class CSmartPropWeaponTypeCondition_58b60 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    int x4;
    int x8;
    int value;
    int type;
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003f96c8;
struct ConditionFactoryTemplate_58ba0 {
    void* m_vptr;
    void base1_dtor_00049340();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb5c6613

// 0x00058b20 fight::ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition>::vfunc_1 (60 B): matches/0x00058b20.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropWeaponTypeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58b20));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58b20* t = new (mem) TrackFactoryTemplate_58b20();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053a50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058b60 fight::ConditionFactoryTemplate<CSmartPropWeaponTypeCondition>::vfunc_5 (54 B): matches/0x00058b60.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCSmartPropWeaponTypeCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CSmartPropWeaponTypeCondition>::vfunc_5() {
    CSmartPropWeaponTypeCondition_58b60* p = (CSmartPropWeaponTypeCondition_58b60*)FUN_0008d690((int)sizeof(CSmartPropWeaponTypeCondition_58b60));
    if (p) {
        p->Init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f7154);
        p->value = 0;
        p->type = -1;
        return (void*)(p);
    }
    return (void*)((void*)0);
}

namespace fn_fb5c6613 {

// 0x00058ba0 fight::ConditionFactoryTemplate<CSmartPropWeaponTypeCondition>::vfunc_2 (43 B): matches/0x00058ba0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58ba0@fn_fb5c6613@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58ba0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f96c8;
    base1_dtor_00049340();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb5c6613
