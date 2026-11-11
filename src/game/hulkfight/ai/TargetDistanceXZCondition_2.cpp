// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00128020..0x001280c0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDistanceXZCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5bcb2a4 {
#define TREE_TU_END }
namespace fn_f5bcb2a4 {} using namespace fn_f5bcb2a4;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f5bcb2a4 {
extern int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern "C" const char DAT_00491ca8[];
extern "C" const char DAT_004a8758[];
} // namespace fn_f5bcb2a4
namespace fight {
class ConditionFactoryCaster_128020 {
  public:
    virtual int f0(void*);
    virtual int f1();
};
}
namespace hulkfight { namespace ai {
class TargetDistanceXZCondition_128020;
} }


// 0x00128020 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceXZCondition>::vfunc_0 (36 B): matches/0x00128020.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, DAT_00491ca8, DAT_004a8758, 0) != 0;
}


// 0x00128050 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_0 (30 B): matches/0x00128050.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::~ParamEnumConstList() {}


// 0x00128070 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>::vfunc_0 (30 B): matches/0x00128070.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>::~ParamFloatConstRange() {}


// 0x00128090 fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>::vfunc_0 (30 B): matches/0x00128090.cpp
// sym: ??_G?$ParamBool@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>::~ParamBool() {}

