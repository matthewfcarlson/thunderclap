// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159de0..0x00159ea0 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4b23336 {
#define TREE_TU_END }
namespace fn_f4b23336 {} using namespace fn_f4b23336;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4b23336 {
class TrackFactoryTemplate_159de0 {
  public:
    TrackFactoryTemplate_159de0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156030();
extern "C" char DAT_00414330[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class TrackBase_159e20 {
  public:
    void Init_00236d40();
};
extern int hulk_at_00415784;

} // namespace fn_f4b23336

// 0x00159de0 fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_1 (60 B): matches/0x00159de0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159de0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159de0* t = new (mem) TrackFactoryTemplate_159de0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156030();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159e20 fight::TrackFactoryTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_5 (66 B): matches/0x00159e20.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_5() {
    char* p = (char*)Alloc(0x18);
    if (p) {
        ((TrackBase_159e20*)p)->Init_00236d40();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414330);
        *(int*)(p + 0xc) = 0;
        *(int*)(p + 0x10) = (int)0xbf800000;
        *(int*)(p + 0x14) = 0;
        *(int*)(p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f4b23336 {

// 0x00159e70 fight::TrackFactoryTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_2 (43 B): matches/0x00159e70.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f4b23336@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415784;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4b23336
