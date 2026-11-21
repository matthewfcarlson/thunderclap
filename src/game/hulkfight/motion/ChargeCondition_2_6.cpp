// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a050..0x0016d360 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/ChargeCondition_2.cpp
// piece 0x0016a3b0..0x0016a430 (kind game, layer game, confidence high, dominant class hulkfight::motion::TurningVelocityCondition); was game/hulkfight/motion/TurningVelocityCondition.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0f627b9 {
#define TREE_TU_END }
namespace fn_f0f627b9 {} using namespace fn_f0f627b9;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f0f627b9 {
extern char DAT_004b6aa8;
} // namespace fn_f0f627b9
namespace fight {
class ConditionFactoryCaster_16a3b0 {
  public:
    virtual bool Test(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace motion {
class TurningVelocityCondition_16a3b0 {};
} }


// 0x0016a3b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_0 (36 B): matches/0x0016a3b0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTurningVelocityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&DAT_00491ca8), (void*)(hulk_uintptr)(&DAT_004b6aa8), 0)) != 0;
}

