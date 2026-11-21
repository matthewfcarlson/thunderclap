// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a050..0x0016d360 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/ChargeCondition_2.cpp
// piece 0x0016a6d0..0x0016a7b0 (kind game, layer game, confidence high, dominant class hulkfight::motion::TargetHealthPercentCondition); was game/hulkfight/motion/TargetHealthPercentCondition_2.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd656eb9 {
#define TREE_TU_END }
namespace fn_fd656eb9 {} using namespace fn_fd656eb9;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fd656eb9 {
extern char DAT_004b7010;
} // namespace fn_fd656eb9
namespace fight {
class ConditionFactoryCaster_16a6d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TargetLocomotionMotionStateCondition_16a6d0;
} }
namespace fn_fd656eb9 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b70e0;
} // namespace fn_fd656eb9
namespace fight {
class ConditionFactoryCaster_16a730 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TargetHealthPercentCondition_16a730 {};
} }


// 0x0016a6d0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_0 (36 B): matches/0x0016a6d0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&DAT_00491ca8), (void*)(hulk_uintptr)(&DAT_004b7010), 0)) != 0;
}


// 0x0016a730 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_0 (36 B): matches/0x0016a730.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b70e0, 0) != 0;
}

