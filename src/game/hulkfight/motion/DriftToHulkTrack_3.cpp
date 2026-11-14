// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00179360..0x001793e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::DriftToHulkTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fcb6b986 {
#define TREE_TU_END }
namespace fn_fcb6b986 {} using namespace fn_fcb6b986;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fcb6b986 {
extern char DAT_0049850c;
extern char DAT_004ba410;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fcb6b986
namespace hulkfight { namespace motion {
class DriftToHulkTrack_179360;
} }
namespace fight {
class TrackFactoryCaster_179360 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00179360 fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_0 (36 B): matches/0x00179360.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ba410, 0) != 0;
}


// 0x00179390 fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>::vfunc_0 (30 B): matches/0x00179390.cpp
// sym: ??_G?$ParamFloatConstRange@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179390)
#endif


// 0x001793b0 fight::ParamVector<hulkfight::motion::DriftToHulkTrack>::vfunc_0 (30 B): matches/0x001793b0.cpp
// sym: ??_G?$ParamVector@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::DriftToHulkTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::DriftToHulkTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1793b0)
#endif

