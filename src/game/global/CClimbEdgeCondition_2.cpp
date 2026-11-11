// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057660..0x00057710 (kind game, layer game, confidence high), dominant class CClimbEdgeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f190b021 {
#define TREE_TU_END }
namespace fn_f190b021 {} using namespace fn_f190b021;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f190b021 {
class TrackFactoryTemplate_57660 {
  public:
    TrackFactoryTemplate_57660() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00054800();
extern "C" char DAT_003f7528[];
typedef unsigned int u32_576a0;
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct CClimbEdgeCondition_576a0 {
    hulk_uintptr vptr;
    char pad[8];
    u32_576a0 f0c;
    char f10;
    void Init(int);
};
extern int g_vftable_576e0;
struct ConditionFactoryTemplate_576e0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f190b021

// 0x00057660 fight::ConditionFactoryCasterTemplate<CClimbEdgeCondition>::vfunc_1 (60 B): matches/0x00057660.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCClimbEdgeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CClimbEdgeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57660));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57660* t = new (mem) TrackFactoryTemplate_57660();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00054800();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000576a0 fight::ConditionFactoryTemplate<CClimbEdgeCondition>::vfunc_5 (51 B): matches/0x000576a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCClimbEdgeCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CClimbEdgeCondition>::vfunc_5() {
    CClimbEdgeCondition_576a0* p = (CClimbEdgeCondition_576a0*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = ((hulk_intptr)DAT_003f7528);
        p->f0c = 0;
        p->f10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f190b021 {

// 0x000576e0 fight::ConditionFactoryTemplate<CClimbEdgeCondition>::vfunc_2 (43 B): matches/0x000576e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_576e0@fn_f190b021@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_576e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_576e0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f190b021
