// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186dc0..0x00186e40 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropActorThinkingTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6208f8e {
#define TREE_TU_END }
namespace fn_f6208f8e {} using namespace fn_f6208f8e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6208f8e {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f6208f8e
namespace fight {
class TrackFactoryCaster_186dc0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropActorThinkingTrack_186dc0 {};
} }
namespace fn_f6208f8e {
extern char DAT_0049850c;
extern char DAT_004bde18;

} // namespace fn_f6208f8e

// 0x00186dc0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_0 (36 B): matches/0x00186dc0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropActorThinkingTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004bde18, 0) != 0;
}


// 0x00186df0 fight::ParamFloatConstRange<hulkfight::motion::PropActorThinkingTrack>::vfunc_0 (30 B): matches/0x00186df0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropActorThinkingTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropActorThinkingTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropActorThinkingTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186df0)
#endif


// 0x00186e10 fight::ParamBool<hulkfight::motion::PropActorThinkingTrack>::vfunc_0 (30 B): matches/0x00186e10.cpp
// sym: ??_G?$ParamBool@VPropActorThinkingTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropActorThinkingTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropActorThinkingTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186e10)
#endif

