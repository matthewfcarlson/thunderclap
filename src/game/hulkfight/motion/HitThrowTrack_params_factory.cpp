// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00154900..0x001549a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitThrowTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5e9ef75 {
#define TREE_TU_END }
namespace fn_f5e9ef75 {} using namespace fn_f5e9ef75;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_154900 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitThrowTrack_154900 {};
} }
namespace fn_f5e9ef75 {
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b2d80;

} // namespace fn_f5e9ef75

// 0x00154900 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitThrowTrack>::vfunc_0 (36 B): matches/0x00154900.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitThrowTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b2d80, 0) != 0;
}


// 0x00154930 fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>::vfunc_0 (30 B): matches/0x00154930.cpp
// sym: ??_G?$ParamFloatConstRange@VHitThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154930)
#endif


// 0x00154950 fight::ParamBool<hulkfight::motion::HitThrowTrack>::vfunc_0 (30 B): matches/0x00154950.cpp
// sym: ??_G?$ParamBool@VHitThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::HitThrowTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::HitThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154950)
#endif


// 0x00154970 fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::vfunc_0 (30 B): matches/0x00154970.cpp
// sym: ??_G?$ParamIntConstRange@VHitThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154970)
#endif

