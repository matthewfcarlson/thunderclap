// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110e60..0x001133f0 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/OnBlockedTriangleCondition_2.cpp
// piece 0x00111360..0x001113e0 (kind game, layer game, confidence high, dominant class hulkfight::ai::InActiveCondition); was game/hulkfight/ai/InActiveCondition_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_feff1804 {
#define TREE_TU_END }
namespace fn_feff1804 {} using namespace fn_feff1804;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_111360 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class InActiveCondition_111360 {};
} }
namespace fn_feff1804 {
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a4068;

} // namespace fn_feff1804

// 0x00111360 fight::ConditionFactoryCasterTemplate<hulkfight::ai::InActiveCondition>::vfunc_0 (36 B): matches/0x00111360.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VInActiveCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::InActiveCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return helper(p, 0, &DAT_00491ca8, &DAT_004a4068, 0) != 0;
}

