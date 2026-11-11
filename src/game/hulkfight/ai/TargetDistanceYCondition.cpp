// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127d20..0x00127dc0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDistanceYCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0578858 {
#define TREE_TU_END }
namespace fn_f0578858 {} using namespace fn_f0578858;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f0578858 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a82f8;
} // namespace fn_f0578858
namespace fight {
class ConditionFactoryCaster_127d20 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TargetDistanceYCondition_127d20 {};
} }


// 0x00127d20 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_0 (36 B): matches/0x00127d20.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetDistanceYCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a82f8, 0) != 0;
}


// 0x00127d50 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_0 (30 B): matches/0x00127d50.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDistanceYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::~ParamEnumConstList() {}


// 0x00127d70 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::vfunc_0 (30 B): matches/0x00127d70.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDistanceYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::~ParamFloatConstRange() {}


// 0x00127d90 fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>::vfunc_0 (30 B): matches/0x00127d90.cpp
// sym: ??_G?$ParamBool@VTargetDistanceYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>::~ParamBool() {}

