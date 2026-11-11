// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x00178de0 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointTrackerTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6ef1ee0 {
#define TREE_TU_END }
namespace fn_f6ef1ee0 {} using namespace fn_f6ef1ee0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6ef1ee0 {
class Track_178d00 {};
extern char DAT_0049850c;
extern char DAT_004b9d48;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f6ef1ee0
namespace fight {
class TrackFactoryCaster_178d00 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class JointTrackerTrack_178d00;
} }


// 0x00178d00 fight::TrackFactoryCasterTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_0 (36 B): matches/0x00178d00.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b9d48, 0) != 0;
}


// 0x00178d30 fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178d30.cpp
// sym: ??_G?$ParamFloatConstRange@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>::~ParamFloatConstRange() {}


// 0x00178d50 fight::ParamVector<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178d50.cpp
// sym: ??_G?$ParamVector@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::JointTrackerTrack>::~ParamVector() {}


// 0x00178d70 fight::ParamBool<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178d70.cpp
// sym: ??_G?$ParamBool@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::JointTrackerTrack>::~ParamBool() {}


// 0x00178d90 fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178d90.cpp
// sym: ??_G?$ParamEnumConstList@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::~ParamEnumConstList() {}


// 0x00178db0 fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178db0.cpp
// sym: ??_G?$ParamIntConstRange@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::~ParamIntConstRange() {}

