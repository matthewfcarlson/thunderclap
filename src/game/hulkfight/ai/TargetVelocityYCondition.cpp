// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127ec0..0x00127fa0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityYCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffd564f9 {
#define TREE_TU_END }
namespace fn_ffd564f9 {} using namespace fn_ffd564f9;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_127ec0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class HasTargetCondition_127ec0 {};
} }
namespace fn_ffd564f9 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a8530;
} // namespace fn_ffd564f9
namespace fight {
class ConditionFactoryCaster_127f20 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TargetVelocityYCondition_127f20 {};
} }
namespace fn_ffd564f9 {
extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_004a85e8;

} // namespace fn_ffd564f9

// 0x00127ec0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasTargetCondition>::vfunc_0 (36 B): matches/0x00127ec0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHasTargetCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a8530, 0) != 0;
}


// 0x00127f20 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_0 (36 B): matches/0x00127f20.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetVelocityYCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004a85e8, 0) != 0;
}

