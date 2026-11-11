// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00059100..0x000591b0 (kind game, layer game, confidence high), dominant class CSmartPropGrabbableNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f40eb462 {
#define TREE_TU_END }
namespace fn_f40eb462 {} using namespace fn_f40eb462;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f40eb462 {
class TrackFactoryTemplate_59100 {
  public:
    TrackFactoryTemplate_59100() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00056830();
extern "C" void* __cdecl Allocate(unsigned int);
extern "C" int hulk_at_003f7208;
struct Sub_59140 {
    int x;
    void Init_0027af00();
};
class Cond_59140 {
  public:
    virtual void V0();
    virtual void V1();
    int a, b, c;
    Sub_59140 s;
    int pad;
    void Initialize_00234590(int);
};
extern int hulk_at_003f97f0;
struct ConditionFactoryTemplate_59180 {
    void* m_vptr;
    void base1_dtor_00049840();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f40eb462

// 0x00059100 fight::ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>::vfunc_1 (60 B): matches/0x00059100.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropGrabbableNameCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_59100));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_59100* t = new (mem) TrackFactoryTemplate_59100();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00056830();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00059140 fight::ConditionFactoryTemplate<CSmartPropGrabbableNameCondition>::vfunc_5 (55 B): matches/0x00059140.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCSmartPropGrabbableNameCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CSmartPropGrabbableNameCondition>::vfunc_5() {
    Cond_59140* p = (Cond_59140*)Allocate(0x18);
    if (p) {
        p->Initialize_00234590(0);
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_003f7208;
        p->c = 0;
        p->s.Init_0027af00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f40eb462 {

// 0x00059180 fight::ConditionFactoryTemplate<CSmartPropGrabbableNameCondition>::vfunc_2 (43 B): matches/0x00059180.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_59180@fn_f40eb462@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_59180::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f97f0;
    base1_dtor_00049840();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f40eb462
