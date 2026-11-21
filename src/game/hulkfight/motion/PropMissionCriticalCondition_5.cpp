// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x00186800..0x00186900 (kind game, layer game, confidence high, dominant class hulkfight::motion::PropMassCondition); was game/hulkfight/motion/PropMassCondition.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f14fdbae {
#define TREE_TU_END }
namespace fn_f14fdbae {} using namespace fn_f14fdbae;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f14fdbae {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004bd4f0;
extern char DAT_004bd5b8;
} // namespace fn_f14fdbae
namespace fight {
class ConditionFactoryCaster_186860 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropMassCondition_186860 {};
} }


// 0x00186800 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_0 (36 B): matches/0x00186800.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropGrabbableIsThrownCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd4f0, 0) != 0;
}


// 0x00186860 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMassCondition>::vfunc_0 (36 B): matches/0x00186860.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropMassCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMassCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&DAT_00491ca8), (void*)(hulk_uintptr)(&DAT_004bd5b8), 0)) != 0;
}

