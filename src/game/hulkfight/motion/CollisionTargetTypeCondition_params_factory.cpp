// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154780..0x00154900 (kind game, layer game, confidence low)
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


// 0x001547b0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_0 (30 B): matches/0x001547b0.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionTargetTypeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1547b0)
#endif


// 0x001547e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_0 (36 B): matches/0x001547e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionInterruptPriorityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &g1, &hulk_at_004b2b30, 0) != 0;
}


// 0x00154810 fight::ParamEnumConstList<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_0 (30 B): matches/0x00154810.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionInterruptPriorityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionInterruptPriorityCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionInterruptPriorityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154810)
#endif


// 0x00154840 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_0 (36 B): matches/0x00154840.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionSourceNameCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b2c00, 0) != 0;
}


// 0x00154870 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNameCondition>::vfunc_0 (30 B): matches/0x00154870.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNameCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154870)
#endif


// 0x001548a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_0 (36 B): matches/0x001548a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VInterruptAccumulatorSetTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &hulk_at_0049850c, &hulk_at_004b2cc8, 0)) != 0;
}


// 0x001548d0 fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_0 (30 B): matches/0x001548d0.cpp
// sym: ??_G?$ParamFloatConstRange@VInterruptAccumulatorSetTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1548d0)
#endif

