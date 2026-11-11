// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001793e0..0x00179460 (kind game, layer game, confidence high), dominant class hulkfight::motion::MotionStateTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1dd71da {
#define TREE_TU_END }
namespace fn_f1dd71da {} using namespace fn_f1dd71da;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace hulkfight { namespace motion {
class MotionStateTrack_1793e0;
} }
namespace fn_f1dd71da {
extern char DAT_0049850c;
extern char DAT_004ba4b8;
extern "C" void* __cdecl Cast(void*, int, const void*, const void*, int);
} // namespace fn_f1dd71da
namespace fight {
class TrackFactoryCaster_1793e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x001793e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionStateTrack>::vfunc_0 (36 B): matches/0x001793e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionStateTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionStateTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Cast(p, 0, &DAT_0049850c, &DAT_004ba4b8, 0) != 0;
}


// 0x00179410 fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>::vfunc_0 (30 B): matches/0x00179410.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionStateTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>::~ParamFloatConstRange() {}


// 0x00179430 fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_0 (30 B): matches/0x00179430.cpp
// sym: ??_G?$ParamEnumConstList@VMotionStateTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::~ParamEnumConstList() {}

