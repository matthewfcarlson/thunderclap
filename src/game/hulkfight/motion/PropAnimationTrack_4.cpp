// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c7e0..0x0018c870 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAnimationTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0c97f94 {
#define TREE_TU_END }
namespace fn_f0c97f94 {} using namespace fn_f0c97f94;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0c97f94 {
class TrackFactoryTemplate_18c7e0 {
  public:
    TrackFactoryTemplate_18c7e0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0018a100();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct PropAnimationTrack_nv_18c820 {
    void* init();
};
extern int g_vftable_18c840;

} // namespace fn_f0c97f94

// 0x0018c7e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAnimationTrack>::vfunc_1 (60 B): matches/0x0018c7e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAnimationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c7e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c7e0* t = new (mem) TrackFactoryTemplate_18c7e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0018a100();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f0c97f94 {

// 0x0018c820 fight::TrackFactoryTemplate<hulkfight::motion::PropAnimationTrack>::vfunc_5 (24 B): matches/0x0018c820.cpp
// sym: ?f@fn_f0c97f94@@YAPAXXZ
// Same code shape as 0x0014c420 (propagated; names are from that function)
void* f() {
    hulkfight::motion::PropAnimationTrack* p = (hulkfight::motion::PropAnimationTrack*)FUN_0008d690((int)sizeof(hulkfight::motion::PropAnimationTrack));
    if (p)
        return ((PropAnimationTrack_nv_18c820*)(((hulkfight::motion::PropAnimationTrack*)(p))))->init();
    return 0;
}


// 0x0018c840 fight::TrackFactoryTemplate<hulkfight::motion::PropAnimationTrack>::vfunc_2 (43 B): matches/0x0018c840.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f0c97f94@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_18c840;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0c97f94
