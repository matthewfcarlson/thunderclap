// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00187160..0x001871e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSetStateByIndexTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0fc7646 {
#define TREE_TU_END }
namespace fn_f0fc7646 {} using namespace fn_f0fc7646;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0fc7646 {
extern char DAT_0049850c;
extern char DAT_004be240;
class Track_187160 {};
class Caster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};

} // namespace fn_f0fc7646

// 0x00187160 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0 (36 B): matches/0x00187160.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return DynamicCast(p, 0, (void*)&DAT_0049850c, (void*)&DAT_004be240, 0) != 0;
}


// 0x00187190 fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0 (30 B): matches/0x00187190.cpp
// sym: ??_G?$ParamFloatConstRange@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187190)
#endif


// 0x001871b0 fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0 (30 B): matches/0x001871b0.cpp
// sym: ??_G?$ParamIntConstRange@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1871b0)
#endif

