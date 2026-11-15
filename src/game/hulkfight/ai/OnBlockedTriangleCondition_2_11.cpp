// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110e60..0x001133f0 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/OnBlockedTriangleCondition_2.cpp
// piece 0x00111540..0x001115c0 (kind game, layer game, confidence high, dominant class hulkfight::ai::RandomKeyWordWaitCondition); was game/hulkfight/ai/RandomKeyWordWaitCondition_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8d1d998 {
#define TREE_TU_END }
namespace fn_f8d1d998 {} using namespace fn_f8d1d998;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f8d1d998 {
extern "C" int __cdecl FUN_00344e74(const char*, const char*, const char*, const char*, int);
} // namespace fn_f8d1d998
namespace fight {
class ConditionFactoryCaster_111540 {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class RandomKeyWordWaitCondition_111540 {};
} }
namespace fn_f8d1d998 {
extern const char DAT_00491ca8[];
extern const char DAT_004a4290[];

} // namespace fn_f8d1d998

// 0x00111540 fight::ConditionFactoryCasterTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0 (36 B): matches/0x00111540.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, DAT_00491ca8, DAT_004a4290, 0) != 0;
}

