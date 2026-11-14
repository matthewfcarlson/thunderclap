// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00179460..0x001795c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PushOutTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fcc97952 {
#define TREE_TU_END }
namespace fn_fcc97952 {} using namespace fn_fcc97952;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace hulkfight { namespace motion {
class MomentumXZAddTrack_179460;
} }
namespace fn_fcc97952 {
extern char DAT_0049850c;
extern char DAT_004ba560;
} // namespace fn_fcc97952
namespace fight {
class TrackFactoryCaster_179460 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fcc97952 {
extern char DAT_004ba6b8;
} // namespace fn_fcc97952
namespace fight {
class TrackFactoryCaster_179520 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PushOutTrack_179520;
} }


// 0x00179460 fight::TrackFactoryCasterTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_0 (36 B): matches/0x00179460.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, (void*)(&DAT_0049850c), (void*)(&DAT_004ba560), 0) != 0;
}


// 0x00179490 fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>::vfunc_0 (30 B): matches/0x00179490.cpp
// sym: ??_G?$ParamFloatConstRange@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179490)
#endif


// 0x001794c0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetBreakTrack>::vfunc_0 (36 B): matches/0x001794c0.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTargetBreakTrack@motion@hulkfight@fn_001794c0@@@fight@fn_001794c0@@UAE_NPAX@Z
namespace fn_001794c0 {
extern "C++" { extern void* DAT_0049850c; }
extern "C" void* DAT_004ba610;
extern "C" void* __cdecl FUN_00344e74(void*, int, void**, void**, int);
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
} // namespace fight
namespace hulkfight {
namespace motion {
class TargetBreakTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetBreakTrack>::vfunc_0(void* obj) {
    return FUN_00344e74(obj, 0, &DAT_0049850c, &DAT_004ba610, 0) != 0;
}
} // namespace fn_001794c0


// 0x001794f0 fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>::vfunc_0 (30 B): matches/0x001794f0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetBreakTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1794f0)
#endif


// 0x00179520 fight::TrackFactoryCasterTemplate<hulkfight::motion::PushOutTrack>::vfunc_0 (36 B): matches/0x00179520.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPushOutTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PushOutTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004ba6b8, 0) != 0;
}


// 0x00179550 fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>::vfunc_0 (30 B): matches/0x00179550.cpp
// sym: ??_G?$ParamFloatConstRange@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179550)
#endif


// 0x00179570 fight::ParamVector<hulkfight::motion::PushOutTrack>::vfunc_0 (30 B): matches/0x00179570.cpp
// sym: ??_G?$ParamVector@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::PushOutTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::PushOutTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179570)
#endif


// 0x00179590 fight::ParamBool<hulkfight::motion::PushOutTrack>::vfunc_0 (30 B): matches/0x00179590.cpp
// sym: ??_G?$ParamBool@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PushOutTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PushOutTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179590)
#endif

