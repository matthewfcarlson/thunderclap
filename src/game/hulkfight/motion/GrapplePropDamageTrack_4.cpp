// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018bf70..0x0018c020 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrapplePropDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f64057df {
#define TREE_TU_END }
namespace fn_f64057df {} using namespace fn_f64057df;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f64057df {
class TrackFactoryTemplate_18bf70 {
  public:
    TrackFactoryTemplate_18bf70() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00188040();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class CCameraShakeTrack_18bfb0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[4];
    int flag;
    int x;
    int y;
    int z;
    int w;
    void Init_00236d40();
};
extern int hulk_at_0041a7f0;

} // namespace fn_f64057df

// 0x0018bf70 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_1 (60 B): matches/0x0018bf70.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18bf70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18bf70* t = new (mem) TrackFactoryTemplate_18bf70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00188040();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018bfb0 fight::TrackFactoryTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_5 (62 B): matches/0x0018bfb0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00075e70 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_5() {
    CCameraShakeTrack_18bfb0* p = (CCameraShakeTrack_18bfb0*)FUN_0008d690((int)sizeof(CCameraShakeTrack_18bfb0));
    if (p) {
        p->Init_00236d40();
        p->x = 0;
        p->y = 0;
        p->z = 0;
        p->w = 0;
        *(hulk_ulongptr*)p = (hulk_ulongptr)&shakeVtable;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f64057df {

// 0x0018bff0 fight::TrackFactoryTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_2 (43 B): matches/0x0018bff0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f64057df@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a7f0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f64057df
