// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001871e0..0x001872a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainShootTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6adaa5c {
#define TREE_TU_END }
namespace fn_f6adaa5c {} using namespace fn_f6adaa5c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6adaa5c {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be2f8;
} // namespace fn_f6adaa5c
namespace fight {
class TrackFactoryCaster_1871e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class BallAndChainShootTrack_1871e0 {};
} }


// 0x001871e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (36 B): matches/0x001871e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be2f8, 0) != 0;
}


// 0x00187210 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00187210.cpp
// sym: ??_G?$ParamFloatConstRange@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187210)
#endif


// 0x00187230 fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00187230.cpp
// sym: ??_G?$ParamIntConstRange@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187230)
#endif


// 0x00187250 fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00187250.cpp
// sym: ??_G?$ParamVector@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187250)
#endif


// 0x00187270 fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00187270.cpp
// sym: ??_G?$ParamEnumConstList@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187270)
#endif

