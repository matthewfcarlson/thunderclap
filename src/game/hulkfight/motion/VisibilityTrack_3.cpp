// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00179ae0..0x00179b60 (kind game, layer game, confidence high), dominant class hulkfight::motion::VisibilityTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f65cd6aa {
#define TREE_TU_END }
namespace fn_f65cd6aa {} using namespace fn_f65cd6aa;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f65cd6aa {
extern char DAT_0049850c;
extern char DAT_004bae48;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f65cd6aa
namespace fight {
class TrackFactoryCaster_179ae0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class VisibilityTrack_179ae0;
} }


// 0x00179ae0 fight::TrackFactoryCasterTemplate<hulkfight::motion::VisibilityTrack>::vfunc_0 (36 B): matches/0x00179ae0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VVisibilityTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::VisibilityTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004bae48, 0) != 0;
}


// 0x00179b10 fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>::vfunc_0 (30 B): matches/0x00179b10.cpp
// sym: ??_G?$ParamFloatConstRange@VVisibilityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179b10)
#endif


// 0x00179b30 fight::ParamBool<hulkfight::motion::VisibilityTrack>::vfunc_0 (30 B): matches/0x00179b30.cpp
// sym: ??_G?$ParamBool@VVisibilityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::VisibilityTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::VisibilityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179b30)
#endif

