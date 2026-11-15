// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00154000..0x00154080 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceForceMagnitudeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fcb542fc {
#define TREE_TU_END }
namespace fn_fcb542fc {} using namespace fn_fcb542fc;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fcb542fc {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fcb542fc
namespace fight {
class ConditionFactoryCaster_154000 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionSourceForceMagnitudeCondition_154000 {};
} }
namespace fn_fcb542fc {
extern char DAT_004b1cc8;

} // namespace fn_fcb542fc

// 0x00154000 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_0 (36 B): matches/0x00154000.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionSourceForceMagnitudeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b1cc8, 0) != 0;
}


// 0x00154030 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_0 (30 B): matches/0x00154030.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceForceMagnitudeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154030)
#endif


// 0x00154050 fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_0 (30 B): matches/0x00154050.cpp
// sym: ??_G?$ParamFloatConstRange@VCollisionSourceForceMagnitudeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154050)
#endif

