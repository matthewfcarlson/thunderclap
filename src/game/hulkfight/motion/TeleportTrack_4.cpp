// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e6c0..0x0017e780 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6c39359 {
#define TREE_TU_END }
namespace fn_f6c39359 {} using namespace fn_f6c39359;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f6c39359 {
class TrackFactoryTemplate_17e6c0 {
  public:
    TrackFactoryTemplate_17e6c0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017a480();
extern "C" char DAT_00417b68[];
class TeleportTrackBase {
  public:
    void Ctor();
};
struct TeleportTrack_17e700 {
    void* vt;
    int pad;
    int one;
    int z1;
    int z2;
    int z3;
    float last;
};
extern "C" void* FUN_0008d690(hulk_uintptr);
extern int g_vftable_17e750;

} // namespace fn_f6c39359

// 0x0017e6c0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportTrack>::vfunc_1 (60 B): matches/0x0017e6c0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VTeleportTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e6c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17e6c0* t = new (mem) TrackFactoryTemplate_17e6c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017a480();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e700 fight::TrackFactoryTemplate<hulkfight::motion::TeleportTrack>::vfunc_5 (73 B): matches/0x0017e700.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VTeleportTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TeleportTrack>::vfunc_5() {
    TeleportTrack_17e700* p = (TeleportTrack_17e700*)FUN_0008d690((int)sizeof(TeleportTrack_17e700));
    if (p) {
        ((TeleportTrackBase*)p)->Ctor();
        p->vt = (void*)((hulk_intptr)DAT_00417b68);
        p->z1 = 0;
        p->z2 = 0;
        p->z3 = 0;
        p->last = -1.0f;
        p->one = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f6c39359 {

// 0x0017e750 fight::TrackFactoryTemplate<hulkfight::motion::TeleportTrack>::vfunc_2 (43 B): matches/0x0017e750.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f6c39359@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_17e750;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f6c39359
