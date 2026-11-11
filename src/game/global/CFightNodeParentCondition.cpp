// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052050..0x00052130 (kind game, layer game, confidence high), dominant class CFightNodeParentCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f85aa0a8 {
#define TREE_TU_END }
namespace fn_f85aa0a8 {} using namespace fn_f85aa0a8;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f85aa0a8 {
class TrackFactoryTemplate_52050 {
  public:
    TrackFactoryTemplate_52050() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f84e8;
struct ConditionFactoryTemplate_52090 {
    void* m_vptr;
    void base1_dtor_00235ad0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003f8504[];
typedef unsigned int u32_520c0;
struct CFightNodeParentCondition_520c0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Helper_520f0 {
  public:
    int second_00059a30();
};

} // namespace fn_f85aa0a8

// 0x00052050 fight::ConditionFactoryCasterTemplate<CFightNodeParentCondition>::vfunc_1 (60 B): matches/0x00052050.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCFightNodeParentCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CFightNodeParentCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_52050));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_52050* t = new (mem) TrackFactoryTemplate_52050();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00236250();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f85aa0a8 {

// 0x00052090 fight::ConditionFactoryTemplate<CFightNodeParentCondition>::vfunc_2 (43 B): matches/0x00052090.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_52090@fn_f85aa0a8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_52090::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f84e8;
    base1_dtor_00235ad0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f85aa0a8

// 0x000520c0 fight::ConditionFactoryTemplate<CFightNodeParentCondition>::vfunc_5 (38 B): matches/0x000520c0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCFightNodeParentCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CFightNodeParentCondition>::vfunc_5() {
    CFightNodeParentCondition_520c0* p = (CFightNodeParentCondition_520c0*)FUN_0008d690(0x20);
    if (p) {
        ((fight::FightNodeParentCondition *)p)->FUN_00235b00();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f8504);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x000520f0 CFightNodeParentCondition::vfunc_7 (24 B): matches/0x000520f0.cpp
// sym: ?vfunc_7@CFightNodeParentCondition@@UAEHPAX@Z
// Same code shape as 0x00052010 (propagated; names are from that function)
hulk_intptr CFightNodeParentCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    hulk_intptr x = ((int)((owners::Object_592a0 *)(((Helper_520f0*)arg)))->FUN_000592a0());
    return ((Helper_520f0*)x)->second_00059a30() + 0xdc;
}


// 0x00052110 CFightNodeParentCondition::vfunc_5 (30 B): matches/0x00052110.cpp
// sym: ??_GCFightNodeParentCondition@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CFightNodeParentCondition::~CFightNodeParentCondition() {}

