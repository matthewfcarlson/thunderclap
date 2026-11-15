// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110e60..0x001133f0 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/OnBlockedTriangleCondition_2.cpp
// piece 0x00111480..0x00111540 (kind game, layer game, confidence high, dominant class hulkfight::ai::PropsToSuckCondition); was game/hulkfight/ai/PropsToSuckCondition_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5acf196 {
#define TREE_TU_END }
namespace fn_f5acf196 {} using namespace fn_f5acf196;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f5acf196 {
extern char DAT_00491ca8;
extern char DAT_004a41d8;
} // namespace fn_f5acf196
namespace fight {
class ConditionFactoryCaster_111480 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class PropsToSuckCondition_111480;
} }


// 0x00111480 fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (36 B): matches/0x00111480.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004a41d8, 0) != 0;
}

