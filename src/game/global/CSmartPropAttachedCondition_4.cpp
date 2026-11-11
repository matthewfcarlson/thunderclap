// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000587c0..0x00058870 (kind game, layer game, confidence high), dominant class CSmartPropAttachedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f662c1ee {
#define TREE_TU_END }
namespace fn_f662c1ee {} using namespace fn_f662c1ee;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f662c1ee {
class TrackFactoryTemplate_587c0 {
  public:
    TrackFactoryTemplate_587c0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000538b0();
extern "C" char DAT_003f710c[];
extern "C" void* __cdecl Allocate(unsigned int);
struct Condition_58800 {
    void* vptr;
    unsigned char pad4[8];
    unsigned char enabled;
    unsigned char padD[3];
    int value;
    int last;
    void Initialize(int);
};
extern int g_vftable_58840;
struct ConditionFactoryTemplate_58840 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f662c1ee

// 0x000587c0 fight::ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>::vfunc_1 (60 B): matches/0x000587c0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropAttachedCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_587c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_587c0* t = new (mem) TrackFactoryTemplate_587c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000538b0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058800 fight::ConditionFactoryTemplate<CSmartPropAttachedCondition>::vfunc_5 (58 B): matches/0x00058800.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCSmartPropAttachedCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CSmartPropAttachedCondition>::vfunc_5() {
    Condition_58800* p = (Condition_58800*)Allocate(0x18);
    if (p) {
        p->Initialize(0);
        p->vptr = (void*)((hulk_intptr)DAT_003f710c);
        p->enabled = 1;
        p->value = 0;
        p->last = -1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f662c1ee {

// 0x00058840 fight::ConditionFactoryTemplate<CSmartPropAttachedCondition>::vfunc_2 (43 B): matches/0x00058840.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58840@fn_f662c1ee@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58840::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_58840;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f662c1ee
