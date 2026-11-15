// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a430..0x0016a5f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastConeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe650bd9 {
#define TREE_TU_END }
namespace fn_fe650bd9 {} using namespace fn_fe650bd9;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fe650bd9 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b6b70;
} // namespace fn_fe650bd9
namespace fight {
class ConditionFactoryCaster_16a430 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class IntentionInputCondition_16a430;
} }
namespace fn_fe650bd9 {
extern char DAT_004b6c38;
} // namespace fn_fe650bd9
namespace fight {
class ConditionFactoryCaster_16a490 {
  public:
    virtual int Test(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace motion {
class LocomotionMotionStateCondition_16a490 {};
} }
namespace fn_fe650bd9 {
extern char DAT_004b6d08;
} // namespace fn_fe650bd9
namespace fight {
class ConditionFactoryCaster_16a4f0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class GrappleReactionTypeCondition_16a4f0 {};
} }
namespace fn_fe650bd9 {
extern int hulk_at_00491ca8, hulk_at_004b6dc8;

} // namespace fn_fe650bd9

// 0x0016a430 fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionInputCondition>::vfunc_0 (36 B): matches/0x0016a430.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VIntentionInputCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionInputCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b6b70, 0) != 0;
}


// 0x0016a490 fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_0 (36 B): matches/0x0016a490.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b6c38, 0) != 0;
}


// 0x0016a4f0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_0 (36 B): matches/0x0016a4f0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VGrappleReactionTypeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b6d08, 0) != 0;
}


// 0x0016a550 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastConeCondition>::vfunc_0 (36 B): matches/0x0016a550.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRayCastConeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastConeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &hulk_at_00491ca8, &hulk_at_004b6dc8, 0)) != 0;
}

