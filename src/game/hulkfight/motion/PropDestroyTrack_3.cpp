// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c450..0x0018c500 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDestroyTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fee6b466 {
#define TREE_TU_END }
namespace fn_fee6b466 {} using namespace fn_fee6b466;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fee6b466 {
class TrackFactoryTemplate_18c450 {
  public:
    TrackFactoryTemplate_18c450() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00188730();
extern "C" char DAT_004195cc[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Track_18c490 {
  public:
    void Init_00236d40();
};
extern int hulk_at_0041a8b4;

} // namespace fn_fee6b466

// 0x0018c450 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_1 (60 B): matches/0x0018c450.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropDestroyTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c450));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c450* t = new (mem) TrackFactoryTemplate_18c450();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00188730();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c490 fight::TrackFactoryTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_5 (59 B): matches/0x0018c490.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropDestroyTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_5() {
    Track_18c490* p = (Track_18c490*)FUN_0008d690(0x14);
    if (p) {
        p->Init_00236d40();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004195cc);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fee6b466 {

// 0x0018c4d0 fight::TrackFactoryTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_2 (43 B): matches/0x0018c4d0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fee6b466@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a8b4;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fee6b466
