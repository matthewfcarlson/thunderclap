// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x00186a60..0x00186ae0 (kind game, layer game, confidence high, dominant class hulkfight::motion::PropStateByIndexCondition); was game/hulkfight/motion/PropStateByIndexCondition_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5a2b790 {
#define TREE_TU_END }
namespace fn_f5a2b790 {} using namespace fn_f5a2b790;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5a2b790 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004bd8c0;
} // namespace fn_f5a2b790
namespace fight {
class ConditionFactoryCaster_186a60 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropStateByIndexCondition_186a60 {};
} }


// 0x00186a60 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_0 (36 B): matches/0x00186a60.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd8c0, 0) != 0;
}

