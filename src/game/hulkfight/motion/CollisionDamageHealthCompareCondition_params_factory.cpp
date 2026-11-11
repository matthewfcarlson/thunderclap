// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154680..0x00154780 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionDamageHealthCompareCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7fc8eef {
#define TREE_TU_END }
namespace fn_f7fc8eef {} using namespace fn_f7fc8eef;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_154680 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionTargetNameCondition_154680;
} }
namespace fn_f7fc8eef {
extern int hulk_at_00491ca8, hulk_at_004b28b8;
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int gTypeA_1546e0;

} // namespace fn_f7fc8eef

// 0x00154680 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition>::vfunc_0 (36 B): matches/0x00154680.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, (void*)(&hulk_at_00491ca8), (void*)(&hulk_at_004b28b8), 0) != 0;
}


// 0x001546b0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_0 (30 B): matches/0x001546b0.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1546b0)
#endif


// 0x001546e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_0 (36 B): matches/0x001546e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_1546e0, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00154710 fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_0 (30 B): matches/0x00154710.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154710)
#endif


// 0x00154730 fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_0 (30 B): matches/0x00154730.cpp
// sym: ??_G?$ParamFloatConstRange@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154730)
#endif


// 0x00154750 fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_0 (30 B): matches/0x00154750.cpp
// sym: ??_G?$ParamBool@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154750)
#endif

