// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a050..0x0016d360 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/ChargeCondition_2.cpp
// piece 0x0016a310..0x0016a3b0 (kind game, layer game, confidence high, dominant class hulkfight::motion::RayCastTargetCondition); was game/hulkfight/motion/RayCastTargetCondition.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6eccf8b {
#define TREE_TU_END }
namespace fn_f6eccf8b {} using namespace fn_f6eccf8b;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f6eccf8b {
extern char DAT_004b69e0;
} // namespace fn_f6eccf8b
namespace fight {
class ConditionFactoryCaster_16a310 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class RayCastTargetCondition_16a310 {};
} }


// 0x0016a310 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (36 B): matches/0x0016a310.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004b69e0, 0)) != 0;
}

