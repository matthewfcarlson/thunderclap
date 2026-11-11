// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179640..0x00179720 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointPivotTrackerTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7fdf59c {
#define TREE_TU_END }
namespace fn_f7fdf59c {} using namespace fn_f7fdf59c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f7fdf59c {
extern char DAT_0049850c;
extern char DAT_004ba810;
extern "C" int __cdecl cast_check(void*, int, const void*, const void*, int);
} // namespace fn_f7fdf59c
namespace hulkfight { namespace motion {
class JointPivotTrackerTrack_179640;
} }
namespace fight {
class TrackFactoryCaster_179640 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00179640 fight::TrackFactoryCasterTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (36 B): matches/0x00179640.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return cast_check(p, 0, &DAT_0049850c, &DAT_004ba810, 0) != 0;
}


// 0x00179670 fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x00179670.cpp
// sym: ??_G?$ParamFloatConstRange@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179670)
#endif


// 0x00179690 fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x00179690.cpp
// sym: ??_G?$ParamVector@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179690)
#endif


// 0x001796b0 fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x001796b0.cpp
// sym: ??_G?$ParamBool@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1796b0)
#endif


// 0x001796d0 fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x001796d0.cpp
// sym: ??_G?$ParamEnumConstList@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1796d0)
#endif


// 0x001796f0 fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x001796f0.cpp
// sym: ??_G?$ParamIntConstRange@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1796f0)
#endif

