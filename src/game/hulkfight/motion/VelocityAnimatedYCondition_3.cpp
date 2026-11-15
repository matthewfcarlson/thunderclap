// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a5f0..0x0016a6d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityAnimatedYCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fab8e315 {
#define TREE_TU_END }
namespace fn_fab8e315 {} using namespace fn_fab8e315;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fab8e315 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fab8e315
namespace fight {
class ConditionFactoryCaster_16a5f0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TargetingCondition_16a5f0 {};
} }
namespace fn_fab8e315 {
extern char DAT_004b6e80;
class Base {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern void* hulk_at_00491ca8;
extern void* hulk_at_004b6f40;

} // namespace fn_fab8e315

// 0x0016a5f0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetingCondition>::vfunc_0 (36 B): matches/0x0016a5f0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetingCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b6e80, 0) != 0;
}


// 0x0016a650 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_0 (36 B): matches/0x0016a650.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &hulk_at_00491ca8, &hulk_at_004b6f40, 0) != 0;
}

