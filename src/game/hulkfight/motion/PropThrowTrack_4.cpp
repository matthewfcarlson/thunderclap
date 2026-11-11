// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c870..0x0018c900 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropThrowTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fde74312 {
#define TREE_TU_END }
namespace fn_fde74312 {} using namespace fn_fde74312;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fde74312 {
class TrackFactoryTemplate_18c870 {
  public:
    TrackFactoryTemplate_18c870() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0018a340();
typedef unsigned int u32_18c8b0;
struct Prop_18c8b0 {
    hulk_uintptr init_00180f00();
};
extern "C" void* __cdecl operator_new(unsigned int);
extern int hulk_at_0041a95c;

} // namespace fn_fde74312

// 0x0018c870 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropThrowTrack>::vfunc_1 (60 B): matches/0x0018c870.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropThrowTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c870));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c870* t = new (mem) TrackFactoryTemplate_18c870();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0018a340();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c8b0 fight::TrackFactoryTemplate<hulkfight::motion::PropThrowTrack>::vfunc_5 (27 B): matches/0x0018c8b0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropThrowTrack>::vfunc_5() {
    Prop_18c8b0* p = (Prop_18c8b0*)operator_new(0x88);
    if (p)
        return (void*)(p->init_00180f00());
    return (void*)(0);
}

namespace fn_fde74312 {

// 0x0018c8d0 fight::TrackFactoryTemplate<hulkfight::motion::PropThrowTrack>::vfunc_2 (43 B): matches/0x0018c8d0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fde74312@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a95c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fde74312
