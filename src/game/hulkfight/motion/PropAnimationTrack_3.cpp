// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00186ec0..0x00186f60 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAnimationTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3f8e56f {
#define TREE_TU_END }
namespace fn_f3f8e56f {} using namespace fn_f3f8e56f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3f8e56f {
extern char DAT_0049850c;
extern char DAT_004bdf70;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f3f8e56f
namespace fight {
class TrackFactoryCaster_186ec0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropAnimationTrack_186ec0 {};
} }


// 0x00186ec0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAnimationTrack>::vfunc_0 (36 B): matches/0x00186ec0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropAnimationTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAnimationTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004bdf70, 0) != 0;
}


// 0x00186ef0 fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_0 (30 B): matches/0x00186ef0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186ef0)
#endif


// 0x00186f10 fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_0 (30 B): matches/0x00186f10.cpp
// sym: ??_G?$ParamIntConstRange@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186f10)
#endif


// 0x00186f30 fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_0 (30 B): matches/0x00186f30.cpp
// sym: ??_G?$ParamEnumConstList@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186f30)
#endif

