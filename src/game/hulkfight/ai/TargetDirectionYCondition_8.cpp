// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127a00..0x0012a270 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/TargetDirectionYCondition.cpp
// piece 0x00127dc0..0x00127ec0 (kind game, layer game, confidence high, dominant class hulkfight::ai::ProjectileDistanceCondition); was game/hulkfight/ai/ProjectileDistanceCondition.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9d94b3f {
#define TREE_TU_END }
namespace fn_f9d94b3f {} using namespace fn_f9d94b3f;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_127dc0 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
}
namespace fn_f9d94b3f {
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int hulk_at_00491ca8, g2;
extern TypeInfo a, hulk_at_004a8478;
extern "C" int __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
} // namespace fn_f9d94b3f
namespace fight {
class ConditionFactoryCaster_127e20 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class ProjectileDistanceCondition_127e20 {};
} }


// 0x00127dc0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetOrientationCondition>::vfunc_0 (36 B): matches/0x00127dc0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetOrientationCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetOrientationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &hulk_at_00491ca8, &g2, 0) != 0;
}


// 0x00127e20 fight::ConditionFactoryCasterTemplate<hulkfight::ai::ProjectileDistanceCondition>::vfunc_0 (36 B): matches/0x00127e20.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VProjectileDistanceCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::ProjectileDistanceCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &hulk_at_004a8478, 0) != 0;
}

