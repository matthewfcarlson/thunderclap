// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00165020..0x001650b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::ClimbLocomotion4Track
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdc06d21 {
#define TREE_TU_END }
namespace fn_fdc06d21 {} using namespace fn_fdc06d21;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fdc06d21 {
class TrackFactoryTemplate_165020 {
  public:
    TrackFactoryTemplate_165020() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00161d80();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_00416504;

} // namespace fn_fdc06d21

// 0x00165020 fight::TrackFactoryCasterTemplate<hulkfight::motion::ClimbLocomotion4Track>::vfunc_1 (60 B): matches/0x00165020.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::ClimbLocomotion4Track>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_165020));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_165020* t = new (mem) TrackFactoryTemplate_165020();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00161d80();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00165060 fight::TrackFactoryTemplate<hulkfight::motion::ClimbLocomotion4Track>::vfunc_5 (27 B): matches/0x00165060.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00077a90 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ClimbLocomotion4Track>::vfunc_5() {
    void* p = FUN_0008d690(0xa0);
    if (p)
        return (void*)(construct_camera(p));
    return (void*)(0);
}

namespace fn_fdc06d21 {

// 0x00165080 fight::TrackFactoryTemplate<hulkfight::motion::ClimbLocomotion4Track>::vfunc_2 (43 B): matches/0x00165080.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fdc06d21@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00416504;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fdc06d21
