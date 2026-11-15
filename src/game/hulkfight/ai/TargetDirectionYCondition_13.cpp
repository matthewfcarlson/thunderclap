// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127a00..0x0012a270 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/TargetDirectionYCondition.cpp
// piece 0x00128140..0x001281c0 (kind game, layer game, confidence high, dominant class hulkfight::ai::TargetVelocityXZCondition); was game/hulkfight/ai/TargetVelocityXZCondition_2.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4ab4178 {
#define TREE_TU_END }
namespace fn_f4ab4178 {} using namespace fn_f4ab4178;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_128140 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TargetVelocityXZCondition_128140 {};
} }
namespace fn_f4ab4178 {
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a88d0;

} // namespace fn_f4ab4178

// 0x00128140 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_0 (36 B): matches/0x00128140.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a88d0, 0) != 0;
}

