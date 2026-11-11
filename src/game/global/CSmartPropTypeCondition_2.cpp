// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000589c0..0x00058a70 (kind game, layer game, confidence high), dominant class CSmartPropTypeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3bc6b16 {
#define TREE_TU_END }
namespace fn_f3bc6b16 {} using namespace fn_f3bc6b16;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f3bc6b16 {
class TrackFactoryTemplate_589c0 {
  public:
    TrackFactoryTemplate_589c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053b00();
extern "C" char DAT_003f7178[];
class CSmartPropTypeCondition_58a00 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    void Init_00234590(int);
    char pad[8];
    int a;
    int b;
};
extern "C" CSmartPropTypeCondition_58a00* Alloc(hulk_uintptr);
extern int hulk_at_003f9690;
struct ConditionFactoryTemplate_58a40 {
    void* m_vptr;
    void base1_dtor_00049450();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f3bc6b16

// 0x000589c0 fight::ConditionFactoryCasterTemplate<CSmartPropTypeCondition>::vfunc_1 (60 B): matches/0x000589c0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropTypeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropTypeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_589c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_589c0* t = new (mem) TrackFactoryTemplate_589c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053b00();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058a00 fight::ConditionFactoryTemplate<CSmartPropTypeCondition>::vfunc_5 (54 B): matches/0x00058a00.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCSmartPropTypeCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CSmartPropTypeCondition>::vfunc_5() {
    CSmartPropTypeCondition_58a00* p = Alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f7178);
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f3bc6b16 {

// 0x00058a40 fight::ConditionFactoryTemplate<CSmartPropTypeCondition>::vfunc_2 (43 B): matches/0x00058a40.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58a40@fn_f3bc6b16@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58a40::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9690;
    base1_dtor_00049450();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f3bc6b16
