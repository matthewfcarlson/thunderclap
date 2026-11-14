// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001872a0..0x00187340 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainSpinTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f11b481b {
#define TREE_TU_END }
namespace fn_f11b481b {} using namespace fn_f11b481b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_1872a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class BallAndChainSpinTrack_1872a0 {};
} }
namespace fn_f11b481b {
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be3b0;

} // namespace fn_f11b481b

// 0x001872a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0 (36 B): matches/0x001872a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return helper(p, 0, &DAT_0049850c, &DAT_004be3b0, 0) != 0;
}


// 0x001872d0 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0 (30 B): matches/0x001872d0.cpp
// sym: ??_G?$ParamFloatConstRange@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1872d0)
#endif


// 0x001872f0 fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0 (30 B): matches/0x001872f0.cpp
// sym: ??_G?$ParamIntConstRange@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1872f0)
#endif


// 0x00187310 fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0 (30 B): matches/0x00187310.cpp
// sym: ??_G?$ParamVector@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187310)
#endif

