// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a1170..0x001a1200 (kind game, layer game, confidence high), dominant class hulkfight::motion::FireMissileTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc49459c {
#define TREE_TU_END }
namespace fn_fc49459c {} using namespace fn_fc49459c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc49459c {
class TrackFactoryTemplate_1a1170 {
  public:
    TrackFactoryTemplate_1a1170() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0019d160();
typedef unsigned int u32_1a11b0;
struct Track_1a11b0 {
    char x[0x148];
    hulk_uintptr Init_00194290();
};
extern int hulk_at_0041c2a4;

} // namespace fn_fc49459c

// 0x001a1170 fight::TrackFactoryCasterTemplate<hulkfight::motion::FireMissileTrack>::vfunc_1 (60 B): matches/0x001a1170.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::FireMissileTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a1170));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1a1170* t = new (mem) TrackFactoryTemplate_1a1170();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0019d160();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001a11b0 fight::TrackFactoryTemplate<hulkfight::motion::FireMissileTrack>::vfunc_5 (27 B): matches/0x001a11b0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FireMissileTrack>::vfunc_5() {
    Track_1a11b0* p = (Track_1a11b0*)::operator new(0x148);
    if (p)
        return (void*)(p->Init_00194290());
    return (void*)(0);
}

namespace fn_fc49459c {

// 0x001a11d0 fight::TrackFactoryTemplate<hulkfight::motion::FireMissileTrack>::vfunc_2 (43 B): matches/0x001a11d0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fc49459c@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041c2a4;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc49459c
