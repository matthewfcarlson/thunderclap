// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00178f00..0x00179020 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointRelativeTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f59baee4 {
#define TREE_TU_END }
namespace fn_f59baee4 {} using namespace fn_f59baee4;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f59baee4 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b9f48;
} // namespace fn_f59baee4
namespace fight {
class TrackFactoryCaster_178f00 {
  public:
    virtual int vfunc_0(void*);
    virtual int vfunc_1();
};
}
namespace hulkfight { namespace motion {
class SnapToGroundTrack_178f00 {};
} }
namespace fn_f59baee4 {
extern char DAT_004b9ff8;
} // namespace fn_f59baee4
namespace fight {
class TrackFactoryCaster_178f60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class JointRelativeTrack_178f60;
} }


// 0x00178f00 fight::TrackFactoryCasterTemplate<hulkfight::motion::SnapToGroundTrack>::vfunc_0 (36 B): matches/0x00178f00.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSnapToGroundTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SnapToGroundTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b9f48, 0) != 0;
}


// 0x00178f30 fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>::vfunc_0 (30 B): matches/0x00178f30.cpp
// sym: ??_G?$ParamFloatConstRange@VSnapToGroundTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x178f30)
#endif


// 0x00178f60 fight::TrackFactoryCasterTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_0 (36 B): matches/0x00178f60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VJointRelativeTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, (void*)(&DAT_0049850c), (void*)(&DAT_004b9ff8), 0) != 0;
}


// 0x00178f90 fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x00178f90.cpp
// sym: ??_G?$ParamFloatConstRange@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x178f90)
#endif


// 0x00178fb0 fight::ParamBool<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x00178fb0.cpp
// sym: ??_G?$ParamBool@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::JointRelativeTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::JointRelativeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x178fb0)
#endif


// 0x00178fd0 fight::ParamVector<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x00178fd0.cpp
// sym: ??_G?$ParamVector@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::JointRelativeTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::JointRelativeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x178fd0)
#endif


// 0x00178ff0 fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x00178ff0.cpp
// sym: ??_G?$ParamIntConstRange@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x178ff0)
#endif

