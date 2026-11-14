// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00186680..0x00186700 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropMissionCriticalCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe12320d {
#define TREE_TU_END }
namespace fn_fe12320d {} using namespace fn_fe12320d;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fe12320d {
extern char DAT_004bd288;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fe12320d
namespace fight {
class ConditionFactoryCaster_186680 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00186680 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissionCriticalCondition>::vfunc_0 (36 B): matches/0x00186680.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissionCriticalCondition>::vfunc_0(void* __p0) { void * value = (void *)__p0;

    return FUN_00344e74(value, 0, &DAT_00491ca8, &DAT_004bd288, 0) != 0;
}


// 0x001866b0 fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>::vfunc_0 (30 B): matches/0x001866b0.cpp
// sym: ??_G?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1866b0)
#endif


// 0x001866d0 fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>::vfunc_0 (30 B): matches/0x001866d0.cpp
// sym: ??_G?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1866d0)
#endif

