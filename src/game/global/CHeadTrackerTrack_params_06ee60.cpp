// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0006ee60..0x0006efa0 (kind game, layer game, confidence high), dominant class CHeadTrackerTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb16fcd9 {
#define TREE_TU_END }
namespace fn_fb16fcd9 {} using namespace fn_fb16fcd9;
#include "game/global.h"


// 0x0006ef40 fight::ParamFloatConstRange<CHeadTrackerTrack>::vfunc_0 (30 B): matches/0x0006ef40.cpp
// sym: ??_G?$ParamFloatConstRange@VCHeadTrackerTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CHeadTrackerTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CHeadTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ef40)
#endif


// 0x0006ef60 fight::ParamVector<CHeadTrackerTrack>::vfunc_0 (30 B): matches/0x0006ef60.cpp
// sym: ??_G?$ParamVector@VCHeadTrackerTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CHeadTrackerTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CHeadTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ef60)
#endif


// 0x0006ef80 fight::ParamIntConstRange<CHeadTrackerTrack>::vfunc_0 (30 B): matches/0x0006ef80.cpp
// sym: ??_G?$ParamIntConstRange@VCHeadTrackerTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CHeadTrackerTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CHeadTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ef80)
#endif

