// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a050..0x0016d360 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/ChargeCondition_2.cpp
// piece 0x0016a050..0x0016a0d0 (kind game, layer game, confidence high, dominant class hulkfight::motion::ChargeCondition)
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f83e72bb {
#define TREE_TU_END }
namespace fn_f83e72bb {} using namespace fn_f83e72bb;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f83e72bb {
extern "C" int __cdecl Check(void*, int, void*, void*, int);
} // namespace fn_f83e72bb
namespace fight {
class ConditionFactoryCaster_16a050 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class ChargeCondition_16a050 {};
} }
namespace fn_f83e72bb {
extern char DAT_004b6550;

} // namespace fn_f83e72bb

// 0x0016a050 fight::ConditionFactoryCasterTemplate<hulkfight::motion::ChargeCondition>::vfunc_0 (36 B): matches/0x0016a050.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VChargeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::ChargeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b6550, 0) != 0;
}

