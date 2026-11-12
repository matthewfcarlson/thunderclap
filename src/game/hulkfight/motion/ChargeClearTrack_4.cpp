// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017ec80..0x0017ed30 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0814f05 {
#define TREE_TU_END }
namespace fn_f0814f05 {} using namespace fn_f0814f05;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0814f05 {
class TrackFactoryTemplate_17ec80 {
  public:
    TrackFactoryTemplate_17ec80() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017ae00();
extern "C" char DAT_00417d18[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Track {
  public:
    void Init_00236d40();
    hulk_intptr vfptr;
    int a4;
    int a8;
    int a12;
    int a16;
    unsigned char flag;
};
extern int hulk_at_00418fbc;

} // namespace fn_f0814f05

// 0x0017ec80 fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_1 (60 B): matches/0x0017ec80.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VChargeClearTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17ec80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17ec80* t = new (mem) TrackFactoryTemplate_17ec80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017ae00();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f0814f05 {

// 0x0017ecc0 fight::TrackFactoryTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_5 (63 B): matches/0x0017ecc0.cpp
// sym: ?make_track@fn_f0814f05@@YAPAXXZ
void* __cdecl make_track() {
    Track* p = (Track*)FUN_0008d690((int)sizeof(Track));
    if (p) {
        p->Init_00236d40();
        p->flag = 1;
        p->a8 = 1;
        p->vfptr = ((hulk_intptr)DAT_00417d18);
        p->a12 = 0;
        p->a16 = 0xbf800000;
        return p;
    }
    return 0;
}


// 0x0017ed00 fight::TrackFactoryTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_2 (43 B): matches/0x0017ed00.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f0814f05@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418fbc;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0814f05
