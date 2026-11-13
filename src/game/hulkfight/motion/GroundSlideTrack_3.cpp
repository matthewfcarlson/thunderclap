// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a2e0..0x0015a370 (kind game, layer game, confidence high), dominant class hulkfight::motion::GroundSlideTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f26a8aea {
#define TREE_TU_END }
namespace fn_f26a8aea {} using namespace fn_f26a8aea;
namespace fn_f26a8aea {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f26a8aea {
class TrackFactoryTemplate_15a2e0 {
  public:
    TrackFactoryTemplate_15a2e0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156700();
class Track_15a320 {
  public:
    hulk_intptr method_0014e330();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_00415848;

} // namespace fn_f26a8aea

// 0x0015a2e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::GroundSlideTrack>::vfunc_1 (60 B): matches/0x0015a2e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VGroundSlideTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::GroundSlideTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a2e0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_15a2e0* t = new (mem) TrackFactoryTemplate_15a2e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156700();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0015a320 fight::TrackFactoryTemplate<hulkfight::motion::GroundSlideTrack>::vfunc_5 (24 B): matches/0x0015a320.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VGroundSlideTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fac0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GroundSlideTrack>::vfunc_5() {
    Track_15a320* p = (Track_15a320*)FUN_0008d690(0x38);
    if (p)
        return (void*)(p->method_0014e330());
    return (void*)(0);
}

namespace fn_f26a8aea {

// 0x0015a340 fight::TrackFactoryTemplate<hulkfight::motion::GroundSlideTrack>::vfunc_2 (43 B): matches/0x0015a340.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f26a8aea@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415848;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f26a8aea
