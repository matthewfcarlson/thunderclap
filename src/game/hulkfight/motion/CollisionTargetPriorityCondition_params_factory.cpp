// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154080..0x00154220 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetPriorityCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fadc1bae {
#define TREE_TU_END }
namespace fn_fadc1bae {} using namespace fn_fadc1bae;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_154080 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionThrowCondition_154080 {};
} }
namespace fn_fadc1bae {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b1da0;
struct Data {
    int x;
};
extern Data hulk_at_00491ca8, hulk_at_004b1e68;
extern char DAT_004b1f30;
} // namespace fn_fadc1bae
namespace fight {
class ConditionFactoryCaster_154140 {
  public:
    virtual int Check(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace motion {
class CollisionSourceTypeCondition_154140;
} }
namespace fn_fadc1bae {
} // namespace fn_fadc1bae
namespace fight {
class ConditionFactoryCaster_1541a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionTargetPriorityCondition_1541a0 {};
} }
namespace fn_fadc1bae {
extern char DAT_004b2000;

} // namespace fn_fadc1bae

// 0x00154080 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_0 (36 B): matches/0x00154080.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionThrowCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b1da0, 0) != 0;
}


// 0x001540e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_0 (36 B): matches/0x001540e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00491ca8), (void*)(&hulk_at_004b1e68), 0)) != 0;
}


// 0x00154140 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_0 (36 B): matches/0x00154140.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionSourceTypeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b1f30, 0) != 0;
}


// 0x001541a0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_0 (36 B): matches/0x001541a0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004b2000, 0)) != 0;
}

