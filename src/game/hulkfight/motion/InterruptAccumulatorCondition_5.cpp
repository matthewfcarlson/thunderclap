// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00158f00 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/InterruptAccumulatorCondition.cpp
// piece 0x00154400..0x00154480 (kind game, layer game, confidence high, dominant class hulkfight::motion::HitPushbackVelocityCondition); was game/hulkfight/motion/HitPushbackVelocityCondition_params_factory.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3764e8f {
#define TREE_TU_END }
namespace fn_f3764e8f {} using namespace fn_f3764e8f;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f3764e8f {
extern char DAT_004b24c8;
} // namespace fn_f3764e8f
namespace fight {
class ConditionFactoryCaster_154400 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitPushbackVelocityCondition_154400 {};
} }


// 0x00154400 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_0 (36 B): matches/0x00154400.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004b24c8, 0)) != 0;
}

