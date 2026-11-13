// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001650b0..0x00165140 (kind game, layer game, confidence high), dominant class hulkfight::motion::LocomotionStrafe4Track
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb2d9485 {
#define TREE_TU_END }
namespace fn_fb2d9485 {} using namespace fn_fb2d9485;
namespace fn_fb2d9485 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb2d9485 {
class TrackFactoryTemplate_1650b0 {
  public:
    TrackFactoryTemplate_1650b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001622b0();
class LocomotionStrafe4Track_1650f0 {
  public:
    hulk_intptr Init_0015baf0();
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern int hulk_at_00416520;

} // namespace fn_fb2d9485

// 0x001650b0 fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStrafe4Track>::vfunc_1 (60 B): matches/0x001650b0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStrafe4Track>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1650b0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_1650b0* t = new (mem) TrackFactoryTemplate_1650b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001622b0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001650f0 fight::TrackFactoryTemplate<hulkfight::motion::LocomotionStrafe4Track>::vfunc_5 (27 B): matches/0x001650f0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::LocomotionStrafe4Track>::vfunc_5() {
    LocomotionStrafe4Track_1650f0* p = (LocomotionStrafe4Track_1650f0*)Alloc(0xa8);
    if (p)
        return (void*)(p->Init_0015baf0());
    return (void*)(0);
}

namespace fn_fb2d9485 {

// 0x00165110 fight::TrackFactoryTemplate<hulkfight::motion::LocomotionStrafe4Track>::vfunc_2 (43 B): matches/0x00165110.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fb2d9485@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00416520;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fb2d9485
