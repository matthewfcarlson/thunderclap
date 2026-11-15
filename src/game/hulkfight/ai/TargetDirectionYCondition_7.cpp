// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127a00..0x0012a270 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/TargetDirectionYCondition.cpp
// piece 0x00127d20..0x00127dc0 (kind game, layer game, confidence high, dominant class hulkfight::ai::TargetDistanceYCondition); was game/hulkfight/ai/TargetDistanceYCondition.cpp until D46
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

