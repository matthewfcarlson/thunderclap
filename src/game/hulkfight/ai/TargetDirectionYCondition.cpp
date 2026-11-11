// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127a00..0x00127a80 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDirectionYCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa5629fc {
#define TREE_TU_END }
namespace fn_fa5629fc {} using namespace fn_fa5629fc;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fa5629fc {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a7ea8;
} // namespace fn_fa5629fc
namespace fight {
class ConditionFactoryCaster_127a00 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00127a00 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionYCondition>::vfunc_0 (36 B): matches/0x00127a00.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a7ea8, 0) != 0;
}


// 0x00127a30 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_0 (30 B): matches/0x00127a30.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127a30)
#endif


// 0x00127a50 fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::vfunc_0 (30 B): matches/0x00127a50.cpp
// sym: ??_G?$ParamIntConstRange@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127a50)
#endif

