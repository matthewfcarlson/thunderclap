// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006fcf0..0x0006fd80 (kind game, layer game, confidence high), dominant class CPropActorSetStateTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc3736bb {
#define TREE_TU_END }
namespace fn_fc3736bb {} using namespace fn_fc3736bb;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc3736bb {
class TrackFactoryTemplate_6fcf0 {
  public:
    TrackFactoryTemplate_6fcf0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000647f0();
struct Thing_6fd30 {
    hulk_intptr init_00062cd0();
};
extern int hulk_at_003fd2a4;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00062ca0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc3736bb

// 0x0006fcf0 fight::TrackFactoryCasterTemplate<CPropActorSetStateTrack>::vfunc_1 (60 B): matches/0x0006fcf0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCPropActorSetStateTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CPropActorSetStateTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6fcf0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6fcf0* t = new (mem) TrackFactoryTemplate_6fcf0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000647f0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006fd30 fight::TrackFactoryTemplate<CPropActorSetStateTrack>::vfunc_5 (24 B): matches/0x0006fd30.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCPropActorSetStateTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f4f0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CPropActorSetStateTrack>::vfunc_5() {
    Thing_6fd30* p = (Thing_6fd30*)operator new(0x14);
    if (p)
        return (void*)(p->init_00062cd0());
    return (void*)(0);
}

namespace fn_fc3736bb {

// 0x0006fd50 fight::TrackFactoryTemplate<CPropActorSetStateTrack>::vfunc_2 (43 B): matches/0x0006fd50.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fc3736bb@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd2a4;
    base1_dtor_00062ca0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc3736bb
