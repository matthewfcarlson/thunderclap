// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058910..0x000589c0 (kind game, layer game, confidence high), dominant class CSmartPropStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f02c287b {
#define TREE_TU_END }
namespace fn_f02c287b {} using namespace fn_f02c287b;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f02c287b {
class TrackFactoryTemplate_58910 {
  public:
    TrackFactoryTemplate_58910() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053cd0();
extern "C" char DAT_003f7250[];
class Factory_58950 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* f5();
};
class Init_58950 {
  public:
    void InitFn_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003f9674;
struct ConditionFactoryTemplate_58990 {
    void* m_vptr;
    void base1_dtor_000499f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f02c287b

// 0x00058910 fight::ConditionFactoryCasterTemplate<CSmartPropStateCondition>::vfunc_1 (60 B): matches/0x00058910.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropStateCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropStateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58910));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58910* t = new (mem) TrackFactoryTemplate_58910();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053cd0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058950 fight::ConditionFactoryTemplate<CSmartPropStateCondition>::vfunc_5 (54 B): matches/0x00058950.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCSmartPropStateCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CSmartPropStateCondition>::vfunc_5() {
    void* p = FUN_0008d690(0x14);
    if (p) {
        ((Init_58950*)p)->InitFn_00234590(0);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_003f7250);
        *(unsigned long*)((char*)p + 0xc) = 2;
        *(unsigned long*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)((void*)0);
}

namespace fn_f02c287b {

// 0x00058990 fight::ConditionFactoryTemplate<CSmartPropStateCondition>::vfunc_2 (43 B): matches/0x00058990.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58990@fn_f02c287b@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58990::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9674;
    base1_dtor_000499f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f02c287b
