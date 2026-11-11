// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186700..0x00186780 (kind game, layer game, confidence high), dominant class hulkfight::motion::SmartPropGrabbableCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fdf9c5e7 {
#define TREE_TU_END }
namespace fn_fdf9c5e7 {} using namespace fn_fdf9c5e7;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fdf9c5e7 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004bd350;
} // namespace fn_fdf9c5e7
namespace fight {
class ConditionFactoryCaster_186700 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class SmartPropGrabbableCondition_186700 {};
} }


// 0x00186700 fight::ConditionFactoryCasterTemplate<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_0 (36 B): matches/0x00186700.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd350, 0) != 0;
}


// 0x00186730 fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_0 (30 B): matches/0x00186730.cpp
// sym: ??_G?$ParamBool@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186730)
#endif


// 0x00186750 fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_0 (30 B): matches/0x00186750.cpp
// sym: ??_G?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186750)
#endif

