// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00059030..0x00059100 (kind game, layer game, confidence high), dominant class CSmartPropDistanceCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0c31a8c {
#define TREE_TU_END }
namespace fn_f0c31a8c {} using namespace fn_f0c31a8c;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0c31a8c {
class TrackFactoryTemplate_59030 {
  public:
    TrackFactoryTemplate_59030() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00056710();
extern int hulk_at_003f71e4;
class CSmartPropDistanceCondition_59070 {
  public:
    hulk_intptr vptr;
    int pad4[2];
    int one;
    float val;
    char pad14[4];
    class Inner {
      public:
        void init_0027af00();
    } inner;
    int pad1c;
    int f;
    int g;
    int h;
    void setup_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_003f97d4;
struct ConditionFactoryTemplate_590d0 {
    void* m_vptr;
    void base1_dtor_000497b0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f0c31a8c

// 0x00059030 fight::ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>::vfunc_1 (60 B): matches/0x00059030.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropDistanceCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_59030));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_59030* t = new (mem) TrackFactoryTemplate_59030();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00056710();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00059070 fight::ConditionFactoryTemplate<CSmartPropDistanceCondition>::vfunc_5 (83 B): matches/0x00059070.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCSmartPropDistanceCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CSmartPropDistanceCondition>::vfunc_5() {
    CSmartPropDistanceCondition_59070* p = (CSmartPropDistanceCondition_59070*)FUN_0008d690(0x30);
    if (p) {
        p->setup_00234590(0);
        p->vptr = (hulk_intptr)&hulk_at_003f71e4;
        p->one = 1;
        p->val = 1.0f;
        p->inner.init_0027af00();
        p->f = 0;
        p->g = 0;
        p->h = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f0c31a8c {

// 0x000590d0 fight::ConditionFactoryTemplate<CSmartPropDistanceCondition>::vfunc_2 (43 B): matches/0x000590d0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_590d0@fn_f0c31a8c@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_590d0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f97d4;
    base1_dtor_000497b0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0c31a8c
