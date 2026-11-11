// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018be10..0x0018bec0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropActorThinkingTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4f57fbd {
#define TREE_TU_END }
namespace fn_f4f57fbd {} using namespace fn_f4f57fbd;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4f57fbd {
class TrackFactoryTemplate_18be10 {
  public:
    TrackFactoryTemplate_18be10() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187f00();
extern "C" char DAT_0041932c[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct Track_18be50 {
    unsigned char pad[0x14];
    void Init_00236d40();
};
extern int hulk_at_0041a7b8;

} // namespace fn_f4f57fbd

// 0x0018be10 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_1 (60 B): matches/0x0018be10.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropActorThinkingTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18be10));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18be10* t = new (mem) TrackFactoryTemplate_18be10();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187f00();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018be50 fight::TrackFactoryTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_5 (49 B): matches/0x0018be50.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropActorThinkingTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_5() {
    Track_18be50* p = (Track_18be50*)Alloc(0x14);
    if (p) {
        p->Init_00236d40();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041932c);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f4f57fbd {

// 0x0018be90 fight::TrackFactoryTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_2 (43 B): matches/0x0018be90.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f4f57fbd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a7b8;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4f57fbd
