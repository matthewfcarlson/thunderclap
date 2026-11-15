// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x00186ae0..0x00186b60 (kind game, layer game, confidence high, dominant class hulkfight::motion::PropMissileCountCondition); was game/hulkfight/motion/PropMissileCountCondition_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb6015c0 {
#define TREE_TU_END }
namespace fn_fb6015c0 {} using namespace fn_fb6015c0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_186ae0 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropMissileCountCondition_186ae0 {};
} }
namespace fn_fb6015c0 {
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_004bd988;

} // namespace fn_fb6015c0

// 0x00186ae0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_0 (36 B): matches/0x00186ae0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_00491ca8, &DAT_004bd988, 0) != 0;
}

