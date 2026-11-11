// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186fe0..0x001870c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropThrowTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f737fdd5 {
#define TREE_TU_END }
namespace fn_f737fdd5 {} using namespace fn_f737fdd5;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_186fe0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropThrowTrack_186fe0 {};
} }
namespace fn_f737fdd5 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be0d8;

} // namespace fn_f737fdd5

// 0x00186fe0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropThrowTrack>::vfunc_0 (36 B): matches/0x00186fe0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be0d8, 0) != 0;
}


// 0x00187010 fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187010.cpp
// sym: ??_G?$ParamFloatConstRange@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>::~ParamFloatConstRange() {}


// 0x00187030 fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187030.cpp
// sym: ??_G?$ParamIntConstRange@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>::~ParamIntConstRange() {}


// 0x00187050 fight::ParamBool<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187050.cpp
// sym: ??_G?$ParamBool@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropThrowTrack>::~ParamBool() {}


// 0x00187070 fight::ParamVector<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187070.cpp
// sym: ??_G?$ParamVector@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::PropThrowTrack>::~ParamVector() {}


// 0x00187090 fight::ParamBranch<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187090.cpp
// sym: ??_G?$ParamBranch@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<hulkfight::motion::PropThrowTrack>::~ParamBranch() {}

