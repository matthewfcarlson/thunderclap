// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0006ea80..0x0006eae0 (kind game, layer game, confidence high), dominant class CComboMessageTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f452c69f {
#define TREE_TU_END }
namespace fn_f452c69f {} using namespace fn_f452c69f;
#include "game/global.h"


// 0x0006ea80 fight::ParamFloatConstRange<CComboMessageTrack>::vfunc_0 (30 B): matches/0x0006ea80.cpp
// sym: ??_G?$ParamFloatConstRange@VCComboMessageTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CComboMessageTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CComboMessageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ea80)
#endif


// 0x0006eaa0 fight::ParamString<CComboMessageTrack>::vfunc_0 (30 B): matches/0x0006eaa0.cpp
// sym: ??_G?$ParamString@VCComboMessageTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<CComboMessageTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<CComboMessageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6eaa0)
#endif


// 0x0006eac0 fight::ParamEnumConstList<CComboMessageTrack>::vfunc_0 (30 B): matches/0x0006eac0.cpp
// sym: ??_G?$ParamEnumConstList@VCComboMessageTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CComboMessageTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CComboMessageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6eac0)
#endif

