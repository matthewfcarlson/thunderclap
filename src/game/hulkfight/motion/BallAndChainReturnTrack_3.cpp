// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001870c0..0x00187160 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainReturnTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fbe35d68 {
#define TREE_TU_END }
namespace fn_fbe35d68 {} using namespace fn_fbe35d68;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_1870c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class BallAndChainReturnTrack_1870c0 {};
} }
namespace fn_fbe35d68 {
extern char DAT_0049850c;
extern char DAT_004be188;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

} // namespace fn_fbe35d68

// 0x001870c0 fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (36 B): matches/0x001870c0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be188, 0) != 0;
}


// 0x001870f0 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x001870f0.cpp
// sym: ??_G?$ParamFloatConstRange@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>::~ParamFloatConstRange() {}


// 0x00187110 fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00187110.cpp
// sym: ??_G?$ParamIntConstRange@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>::~ParamIntConstRange() {}


// 0x00187130 fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00187130.cpp
// sym: ??_G?$ParamVector@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>::~ParamVector() {}

