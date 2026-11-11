// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00165140..0x001651d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HeliLocomotionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9bc2ae8 {
#define TREE_TU_END }
namespace fn_f9bc2ae8 {} using namespace fn_f9bc2ae8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f9bc2ae8 {
class TrackFactoryTemplate_165140 {
  public:
    TrackFactoryTemplate_165140() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00162850();
typedef unsigned int u32_165180;
struct Factory_165180 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_165180 vfunc_5();
};
extern "C" void* FUN_0008d690(unsigned int);
struct Product {
    hulk_uintptr Initialize_0015bc90();
};
extern int hulk_at_0041653c;

} // namespace fn_f9bc2ae8

// 0x00165140 fight::TrackFactoryCasterTemplate<hulkfight::motion::HeliLocomotionTrack>::vfunc_1 (60 B): matches/0x00165140.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HeliLocomotionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_165140));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_165140* t = new (mem) TrackFactoryTemplate_165140();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00162850();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00165180 fight::TrackFactoryTemplate<hulkfight::motion::HeliLocomotionTrack>::vfunc_5 (27 B): matches/0x00165180.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HeliLocomotionTrack>::vfunc_5() {
    Product* p = (Product*)FUN_0008d690(0xd8);
    if (p)
        return (void*)(p->Initialize_0015bc90());
    return (void*)(0);
}

namespace fn_f9bc2ae8 {

// 0x001651a0 fight::TrackFactoryTemplate<hulkfight::motion::HeliLocomotionTrack>::vfunc_2 (43 B): matches/0x001651a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f9bc2ae8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041653c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9bc2ae8
