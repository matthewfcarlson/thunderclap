// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001281c0..0x00128240 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDirectionXZCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f76a27a3 {
#define TREE_TU_END }
namespace fn_f76a27a3 {} using namespace fn_f76a27a3;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_1281c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f76a27a3 {
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int hulk_at_00491ca8, hulk_at_004a8990;

} // namespace fn_f76a27a3

// 0x001281c0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionXZCondition>::vfunc_0 (36 B): matches/0x001281c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &hulk_at_00491ca8, &hulk_at_004a8990, 0) != 0;
}


// 0x001281f0 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_0 (30 B): matches/0x001281f0.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1281f0)
#endif


// 0x00128210 fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>::vfunc_0 (30 B): matches/0x00128210.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x128210)
#endif

