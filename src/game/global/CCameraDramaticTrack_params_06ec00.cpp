// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0006ec00..0x0006ed60 (kind game, layer game, confidence high), dominant class CCameraDramaticTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6703eac {
#define TREE_TU_END }
namespace fn_f6703eac {} using namespace fn_f6703eac;
#include "game/global.h"


// 0x0006ece0 fight::ParamFloatConstRange<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x0006ece0.cpp
// sym: ??_G?$ParamFloatConstRange@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CCameraDramaticTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CCameraDramaticTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ece0)
#endif


// 0x0006ed00 fight::ParamVector<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x0006ed00.cpp
// sym: ??_G?$ParamVector@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CCameraDramaticTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CCameraDramaticTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ed00)
#endif


// 0x0006ed20 fight::ParamBool<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x0006ed20.cpp
// sym: ??_G?$ParamBool@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CCameraDramaticTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CCameraDramaticTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ed20)
#endif


// 0x0006ed40 fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x0006ed40.cpp
// sym: ??_G?$ParamEnumConstList@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CCameraDramaticTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CCameraDramaticTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ed40)
#endif

