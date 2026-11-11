// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127fa0..0x00128020 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_facfd6fc {
#define TREE_TU_END }
namespace fn_facfd6fc {} using namespace fn_facfd6fc;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_127fa0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TargetVelocityCondition_127fa0 {};
} }
namespace fn_facfd6fc {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a86a0;

} // namespace fn_facfd6fc

// 0x00127fa0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityCondition>::vfunc_0 (36 B): matches/0x00127fa0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a86a0, 0) != 0;
}


// 0x00127fd0 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_0 (30 B): matches/0x00127fd0.cpp
// sym: ??_G?$ParamEnumConstList@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::~ParamEnumConstList() {}


// 0x00127ff0 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>::vfunc_0 (30 B): matches/0x00127ff0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>::~ParamFloatConstRange() {}

