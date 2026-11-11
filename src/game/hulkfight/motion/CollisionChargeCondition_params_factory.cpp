// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001545e0..0x00154680 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionChargeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffe42598 {
#define TREE_TU_END }
namespace fn_ffe42598 {} using namespace fn_ffe42598;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ffe42598 {
class CollisionChargeCondition_1545e0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_ffe42598
namespace fight {
class ConditionFactoryCaster_1545e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_ffe42598 {
extern char DAT_004b27f0;

} // namespace fn_ffe42598

// 0x001545e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_0 (36 B): matches/0x001545e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b27f0, 0) != 0;
}


// 0x00154610 fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_0 (30 B): matches/0x00154610.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154610)
#endif


// 0x00154630 fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::vfunc_0 (30 B): matches/0x00154630.cpp
// sym: ??_G?$ParamFloatConstRange@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154630)
#endif


// 0x00154650 fight::ParamBool<hulkfight::motion::CollisionChargeCondition>::vfunc_0 (30 B): matches/0x00154650.cpp
// sym: ??_G?$ParamBool@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CollisionChargeCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CollisionChargeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154650)
#endif

