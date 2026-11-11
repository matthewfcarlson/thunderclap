// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017f180..0x0017f210 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointPivotTrackerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f18716a5 {
#define TREE_TU_END }
namespace fn_f18716a5 {} using namespace fn_f18716a5;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f18716a5 {
class TrackFactoryTemplate_17f180 {
  public:
    TrackFactoryTemplate_17f180() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017d8d0();
typedef unsigned int u32_17f1c0;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct InitObj_17f1c0 {
    hulk_uintptr Init_001708a0();
};
extern int hulk_at_0041909c;

} // namespace fn_f18716a5

// 0x0017f180 fight::TrackFactoryCasterTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_1 (60 B): matches/0x0017f180.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17f180));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17f180* t = new (mem) TrackFactoryTemplate_17f180();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017d8d0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017f1c0 fight::TrackFactoryTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_5 (24 B): matches/0x0017f1c0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f220 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x60);
    if (p)
        return (void*)(((InitObj_17f1c0*)p)->Init_001708a0());
    return (void*)(0);
}

namespace fn_f18716a5 {

// 0x0017f1e0 fight::TrackFactoryTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2 (43 B): matches/0x0017f1e0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f18716a5@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041909c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f18716a5
