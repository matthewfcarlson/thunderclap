// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127ca0..0x00127d20 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDirectionCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f00f161e {
#define TREE_TU_END }
namespace fn_f00f161e {} using namespace fn_f00f161e;
#include "game/hulkfight/ai.h"


// 0x00127ca0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionCondition>::vfunc_0 (36 B): matches/0x00127ca0.cpp [wrapped: conflict: fight::ConditionFactoryCaster]
// sym: ?vfunc_0@Caster@fn_00127ca0@@UAE_NPAX@Z
namespace fn_00127ca0 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TargetDirectionCondition {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* hulk_at_00491ca8;
extern void* hulk_at_004a8240;
class Caster : public fight::ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void* p);
    virtual void vfunc_1();
};
bool Caster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &hulk_at_00491ca8, &hulk_at_004a8240, 0) != 0;
}
} // namespace fn_00127ca0

