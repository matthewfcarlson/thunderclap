// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a050..0x0016d360 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/ChargeCondition_2.cpp
// piece 0x0016a210..0x0016a290 (kind game, layer game, confidence high, dominant class hulkfight::motion::VelocityYCondition); was game/hulkfight/motion/VelocityYCondition.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fad67fc9 {
#define TREE_TU_END }
namespace fn_fad67fc9 {} using namespace fn_fad67fc9;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fad67fc9 {
extern char DAT_004b6860;
} // namespace fn_fad67fc9
namespace fight {
class ConditionFactoryCaster_16a210 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class VelocityYCondition_16a210 {};
} }


// 0x0016a210 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityYCondition>::vfunc_0 (36 B): matches/0x0016a210.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVelocityYCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&DAT_00491ca8), (void*)(hulk_uintptr)(&DAT_004b6860), 0)) != 0;
}

