// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017ef40..0x0017efd0 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointRelativeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5ac7054 {
#define TREE_TU_END }
namespace fn_f5ac7054 {} using namespace fn_f5ac7054;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5ac7054 {
class TrackFactoryTemplate_17ef40 {
  public:
    TrackFactoryTemplate_17ef40() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017cc30();
typedef unsigned int u32_17ef80;
struct CGrabTrack_17ef80 {
    hulk_uintptr init_0016ffb0();
};
extern "C" void* __cdecl operator_new(unsigned int);
extern int hulk_at_0041902c;

} // namespace fn_f5ac7054

// 0x0017ef40 fight::TrackFactoryCasterTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_1 (60 B): matches/0x0017ef40.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17ef40));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17ef40* t = new (mem) TrackFactoryTemplate_17ef40();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017cc30();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017ef80 fight::TrackFactoryTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_5 (24 B): matches/0x0017ef80.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f3d0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_5() {
    CGrabTrack_17ef80* p = (CGrabTrack_17ef80*)operator_new(0x50);
    if (p)
        return (void*)(p->init_0016ffb0());
    return (void*)(0);
}

namespace fn_f5ac7054 {

// 0x0017efa0 fight::TrackFactoryTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_2 (43 B): matches/0x0017efa0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f5ac7054@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041902c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5ac7054
