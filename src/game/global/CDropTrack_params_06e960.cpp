// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006e960..0x0006e9c0 (kind game, layer game, confidence high), dominant class CDropTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7f421f6 {
#define TREE_TU_END }
namespace fn_f7f421f6 {} using namespace fn_f7f421f6;
#include "game/global.h"


// 0x0006e960 fight::ParamFloatConstRange<CDropTrack>::vfunc_0 (30 B): matches/0x0006e960.cpp
// sym: ??_G?$ParamFloatConstRange@VCDropTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CDropTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CDropTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6e960)
#endif


// 0x0006e980 fight::ParamBool<CDropTrack>::vfunc_0 (30 B): matches/0x0006e980.cpp
// sym: ??_G?$ParamBool@VCDropTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CDropTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CDropTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6e980)
#endif


// 0x0006e9a0 fight::ParamIntConstRange<CDropTrack>::vfunc_0 (30 B): matches/0x0006e9a0.cpp
// sym: ??_G?$ParamIntConstRange@VCDropTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CDropTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CDropTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6e9a0)
#endif

