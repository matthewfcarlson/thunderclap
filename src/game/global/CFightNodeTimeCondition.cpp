// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052130..0x00052210 (kind game, layer game, confidence high), dominant class CFightNodeTimeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f006dedf {
#define TREE_TU_END }
namespace fn_f006dedf {} using namespace fn_f006dedf;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f006dedf {
class TrackFactoryTemplate_52130 {
  public:
    TrackFactoryTemplate_52130() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f8528;
struct ConditionFactoryTemplate_52170 {
    void* m_vptr;
    void base1_dtor_00235be0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
struct CFightNodeTimeCondition_521a0 {
    virtual ~CFightNodeTimeCondition_521a0();
    char pad[0x10];
    void Initialize_00235c10();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Helper_521d0 {
  public:
    int second_00059a30();
};

} // namespace fn_f006dedf

// 0x00052130 fight::ConditionFactoryCasterTemplate<CFightNodeTimeCondition>::vfunc_1 (60 B): matches/0x00052130.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCFightNodeTimeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CFightNodeTimeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_52130));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_52130* t = new (mem) TrackFactoryTemplate_52130();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00236340();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f006dedf {

// 0x00052170 fight::ConditionFactoryTemplate<CFightNodeTimeCondition>::vfunc_2 (43 B): matches/0x00052170.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_52170@fn_f006dedf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_52170::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f8528;
    base1_dtor_00235be0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f006dedf

// 0x000521a0 fight::ConditionFactoryTemplate<CFightNodeTimeCondition>::vfunc_5 (38 B): matches/0x000521a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCFightNodeTimeCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CFightNodeTimeCondition>::vfunc_5() {
    CFightNodeTimeCondition_521a0* p = (CFightNodeTimeCondition_521a0*)FUN_0008d690((int)sizeof(CFightNodeTimeCondition_521a0));
    if (p) {
        p->Initialize_00235c10();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x000521d0 CFightNodeTimeCondition::vfunc_7 (24 B): matches/0x000521d0.cpp
// sym: ?vfunc_7@CFightNodeTimeCondition@@UAEHPAX@Z
// Same code shape as 0x00052010 (propagated; names are from that function)
hulk_intptr CFightNodeTimeCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    hulk_intptr x = ((int)((owners::Object_592a0 *)(((Helper_521d0*)arg)))->FUN_000592a0());
    return ((Helper_521d0*)x)->second_00059a30() + 0xdc;
}


// 0x000521f0 CFightNodeTimeCondition::vfunc_5 (30 B): matches/0x000521f0.cpp
// sym: ??_GCFightNodeTimeCondition@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CFightNodeTimeCondition::~CFightNodeTimeCondition() {}

