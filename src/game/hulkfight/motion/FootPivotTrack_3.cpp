// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179b60..0x00179c10 (kind game, layer game, confidence high), dominant class hulkfight::motion::FootPivotTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0d3ef45 {
#define TREE_TU_END }
namespace fn_f0d3ef45 {} using namespace fn_f0d3ef45;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0d3ef45 {
extern "C" int __cdecl check(void*, int, const void*, const void*, int);
extern char DAT_0049850c;
extern char DAT_004baef0;
} // namespace fn_f0d3ef45
namespace fight {
class TrackFactoryCaster_179b60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class FootPivotTrack_179b60;
} }


// 0x00179b60 fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>::vfunc_0 (36 B): matches/0x00179b60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004baef0, 0) != 0;
}


// 0x00179b90 fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x00179b90.cpp
// sym: ??_G?$ParamFloatConstRange@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179b90)
#endif


// 0x00179bb0 fight::ParamVector<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x00179bb0.cpp
// sym: ??_G?$ParamVector@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::FootPivotTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::FootPivotTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179bb0)
#endif


// 0x00179bd0 fight::ParamBool<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x00179bd0.cpp
// sym: ??_G?$ParamBool@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::FootPivotTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::FootPivotTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179bd0)
#endif


// 0x00179bf0 fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x00179bf0.cpp
// sym: ??_G?$ParamIntConstRange@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179bf0)
#endif

