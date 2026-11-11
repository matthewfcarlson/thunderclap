// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001792a0..0x00179360 (kind game, layer game, confidence high), dominant class hulkfight::motion::DriftToPositionTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ff203ab8 {
#define TREE_TU_END }
namespace fn_ff203ab8 {} using namespace fn_ff203ab8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ff203ab8 {
extern char DAT_0049850c;
extern char DAT_004ba360;
extern "C" void* Find(void*, int, void*, void*, int);
} // namespace fn_ff203ab8
namespace fight {
class TrackFactoryCaster_1792a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class DriftToPositionTrack_1792a0;
} }


// 0x001792a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (36 B): matches/0x001792a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &DAT_0049850c, &DAT_004ba360, 0) != 0;
}


// 0x001792d0 fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (30 B): matches/0x001792d0.cpp
// sym: ??_G?$ParamFloatConstRange@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1792d0)
#endif


// 0x001792f0 fight::ParamBool<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (30 B): matches/0x001792f0.cpp
// sym: ??_G?$ParamBool@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::DriftToPositionTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::DriftToPositionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1792f0)
#endif


// 0x00179310 fight::ParamVector<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (30 B): matches/0x00179310.cpp
// sym: ??_G?$ParamVector@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::DriftToPositionTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::DriftToPositionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179310)
#endif


// 0x00179330 fight::ParamString<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (30 B): matches/0x00179330.cpp
// sym: ??_G?$ParamString@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::motion::DriftToPositionTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::motion::DriftToPositionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179330)
#endif

