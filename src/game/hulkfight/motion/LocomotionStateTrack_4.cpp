// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e260..0x0017e310 (kind game, layer game, confidence high), dominant class hulkfight::motion::LocomotionStateTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9c37d7e {
#define TREE_TU_END }
namespace fn_f9c37d7e {} using namespace fn_f9c37d7e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f9c37d7e {
class TrackFactoryTemplate_17e260 {
  public:
    TrackFactoryTemplate_17e260() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00179f30();
extern "C" char DAT_004179e8[];
extern "C" void* FUN_0008d690(unsigned int);
class Base_17e2a0 {
  public:
    void init_00236d40();
};
struct LocomotionStateTrack_17e2a0 {
    hulk_intptr vf;
    int pad;
    int m8;
    int mc;
    int m10;
};
extern int hulk_at_00418e34;

} // namespace fn_f9c37d7e

// 0x0017e260 fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_1 (60 B): matches/0x0017e260.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VLocomotionStateTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e260));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17e260* t = new (mem) TrackFactoryTemplate_17e260();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00179f30();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e2a0 fight::TrackFactoryTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_5 (59 B): matches/0x0017e2a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VLocomotionStateTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_5() {
    LocomotionStateTrack_17e2a0* p = (LocomotionStateTrack_17e2a0*)FUN_0008d690((int)sizeof(LocomotionStateTrack_17e2a0));
    if (p) {
        ((Base_17e2a0*)p)->init_00236d40();
        p->vf = ((hulk_intptr)DAT_004179e8);
        p->mc = 0;
        p->m10 = 0;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f9c37d7e {

// 0x0017e2e0 fight::TrackFactoryTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_2 (43 B): matches/0x0017e2e0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f9c37d7e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418e34;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9c37d7e
