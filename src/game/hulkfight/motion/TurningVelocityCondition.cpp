// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a3b0..0x0016a430 (kind game, layer game, confidence high), dominant class hulkfight::motion::TurningVelocityCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0f627b9 {
#define TREE_TU_END }
namespace fn_f0f627b9 {} using namespace fn_f0f627b9;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0f627b9 {
extern "C" int __cdecl check(void*, int, void*, void*, int);
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

    return check(p, 0, &DAT_00491ca8, &DAT_004b6aa8, 0) != 0;
}

