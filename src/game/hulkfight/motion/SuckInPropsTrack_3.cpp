// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001797a0..0x001798e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SuckInPropsTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9830261 {
#define TREE_TU_END }
namespace fn_f9830261 {} using namespace fn_f9830261;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_1797a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TargetIconDistanceTrack_1797a0;
} }
namespace fn_f9830261 {
extern char DAT_0049850c;
extern char DAT_004ba968;
} // namespace fn_f9830261
namespace hulkfight { namespace motion {
class SuckInPropsTrack_179860;
} }
namespace fn_f9830261 {
extern char DAT_004baad0;
extern "C" int __cdecl check(void*, int, const void*, const void*, int);
} // namespace fn_f9830261
namespace fight {
class TrackFactoryCaster_179860 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x001797a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_0 (36 B): matches/0x001797a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004ba968, 0) != 0;
}


// 0x001797d0 fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>::vfunc_0 (30 B): matches/0x001797d0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1797d0)
#endif


// 0x00179800 fight::TrackFactoryCasterTemplate<hulkfight::motion::CriticalMassDrainTrack>::vfunc_0 (36 B): matches/0x00179800.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCriticalMassDrainTrack@motion@hulkfight@fn_00179800@@@fight@fn_00179800@@UAE_NPAX@Z
namespace fn_00179800 {
extern int DAT_0049850c, DAT_004baa20;
extern "C" int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> bool TrackFactoryCasterTemplate<T>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004baa20, 0) != 0;
}
} // namespace fight
namespace hulkfight {
namespace motion {
class CriticalMassDrainTrack {};
} // namespace motion
} // namespace hulkfight
template bool fight::TrackFactoryCasterTemplate<hulkfight::motion::CriticalMassDrainTrack>::vfunc_0(void*);
} // namespace fn_00179800


// 0x00179830 fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>::vfunc_0 (30 B): matches/0x00179830.cpp
// sym: ??_G?$ParamFloatConstRange@VCriticalMassDrainTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179830)
#endif


// 0x00179860 fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckInPropsTrack>::vfunc_0 (36 B): matches/0x00179860.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSuckInPropsTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckInPropsTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004baad0, 0) != 0;
}


// 0x00179890 fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_0 (30 B): matches/0x00179890.cpp
// sym: ??_G?$ParamFloatConstRange@VSuckInPropsTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179890)
#endif


// 0x001798b0 fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_0 (30 B): matches/0x001798b0.cpp
// sym: ??_G?$ParamIntConstRange@VSuckInPropsTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1798b0)
#endif

