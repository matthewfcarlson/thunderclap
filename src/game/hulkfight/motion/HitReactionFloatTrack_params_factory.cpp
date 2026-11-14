// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001549a0..0x00154a60 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitReactionFloatTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3dfe215 {
#define TREE_TU_END }
namespace fn_f3dfe215 {} using namespace fn_f3dfe215;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3dfe215 {
struct TrackFactoryCaster_1549a0 {
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int hulk_at_0049850c, hulk_at_004b2e30;

} // namespace fn_f3dfe215

// 0x001549a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (36 B): matches/0x001549a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &hulk_at_0049850c, &hulk_at_004b2e30, 0) != 0;
}


// 0x001549d0 fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x001549d0.cpp
// sym: ??_G?$ParamFloatConstRange@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1549d0)
#endif


// 0x001549f0 fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x001549f0.cpp
// sym: ??_G?$ParamEnumConstList@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1549f0)
#endif


// 0x00154a10 fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x00154a10.cpp
// sym: ??_G?$ParamIntConstRange@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154a10)
#endif


// 0x00154a30 fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x00154a30.cpp
// sym: ??_G?$ParamBool@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154a30)
#endif

