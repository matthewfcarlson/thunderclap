// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001652f0..0x00165380 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleLocomotionSteerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f738addc {
#define TREE_TU_END }
namespace fn_f738addc {} using namespace fn_f738addc;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f738addc {
class TrackFactoryTemplate_1652f0 {
  public:
    TrackFactoryTemplate_1652f0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00163790();
typedef unsigned int u32_165330;
struct CGrabTrack_165330 {
    hulk_uintptr init();
};
extern "C" void* __cdecl operator_new(unsigned int);
extern int g_vftable_165350;

} // namespace fn_f738addc

// 0x001652f0 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_1 (60 B): matches/0x001652f0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VGrappleLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1652f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1652f0* t = new (mem) TrackFactoryTemplate_1652f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00163790();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00165330 fight::TrackFactoryTemplate<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_5 (24 B): matches/0x00165330.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VGrappleLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f3d0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_5() {
    CGrabTrack_165330* p = (CGrabTrack_165330*)operator_new(0x50);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}

namespace fn_f738addc {

// 0x00165350 fight::TrackFactoryTemplate<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_2 (43 B): matches/0x00165350.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f738addc@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_165350;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f738addc
