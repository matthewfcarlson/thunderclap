// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00158f00 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/InterruptAccumulatorCondition.cpp
// piece 0x00154780..0x00154900 (kind game, layer game, confidence low); was game/hulkfight/motion/CollisionTargetTypeCondition_params_factory.cpp until D46
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc8fe8a1 {
#define TREE_TU_END }
namespace fn_fc8fe8a1 {} using namespace fn_fc8fe8a1;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fc8fe8a1 {
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_00491ca8;
class ConditionFactoryCaster_1547e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* g1;
extern void* hulk_at_004b2b30;
class CollisionInterruptPriorityCondition_1547e0 {};
class Condition_154840 {};
} // namespace fn_fc8fe8a1
namespace fight {
class ConditionFactoryCaster_154840 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionSourceNameCondition_154840 {};
} }
namespace fn_fc8fe8a1 {
extern char DAT_004b2c00;
extern char hulk_at_0049850c, hulk_at_004b2cc8;
} // namespace fn_fc8fe8a1
namespace fight {
class TrackFactoryCaster_1548a0 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
}


// 0x00154780 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_0 (36 B): matches/0x00154780.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionTargetTypeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x001547e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_0 (36 B): matches/0x001547e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionInterruptPriorityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &g1, &hulk_at_004b2b30, 0) != 0;
}


// 0x00154840 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_0 (36 B): matches/0x00154840.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionSourceNameCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b2c00, 0) != 0;
}


// 0x001548a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_0 (36 B): matches/0x001548a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VInterruptAccumulatorSetTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &hulk_at_0049850c, &hulk_at_004b2cc8, 0)) != 0;
}

