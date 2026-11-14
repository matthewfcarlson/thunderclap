// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00127c20..0x00127ca0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetAngleYCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9f28e4f {
#define TREE_TU_END }
namespace fn_f9f28e4f {} using namespace fn_f9f28e4f;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f9f28e4f {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a8188;
} // namespace fn_f9f28e4f
namespace fight {
class ConditionFactoryCaster_127c20 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TargetAngleYCondition_127c20 {};
} }


// 0x00127c20 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_0 (36 B): matches/0x00127c20.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetAngleYCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a8188, 0) != 0;
}


// 0x00127c50 fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_0 (30 B): matches/0x00127c50.cpp
// sym: ??_G?$ParamEnumConstList@VTargetAngleYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127c50)
#endif


// 0x00127c70 fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>::vfunc_0 (30 B): matches/0x00127c70.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetAngleYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127c70)
#endif

