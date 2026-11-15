// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00127ca0..0x00127d20 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDirectionCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f00f161e {
#define TREE_TU_END }
namespace fn_f00f161e {} using namespace fn_f00f161e;
#include "game/hulkfight/ai.h"


// 0x00127ca0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionCondition>::vfunc_0 (36 B): matches/0x00127ca0.cpp [wrapped: conflict: fight::ConditionFactoryCaster]
// sym: ?vfunc_0@Caster@fn_00127ca0@@UAE_NPAX@Z
namespace fn_00127ca0 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TargetDirectionCondition {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* hulk_at_00491ca8;
extern void* hulk_at_004a8240;
class Caster : public fight::ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void* p);
    virtual void vfunc_1();
};
bool Caster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &hulk_at_00491ca8, &hulk_at_004a8240, 0) != 0;
}
} // namespace fn_00127ca0


// 0x00127cd0 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_0 (30 B): matches/0x00127cd0.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDirectionCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127cd0)
#endif


// 0x00127cf0 fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>::vfunc_0 (30 B): matches/0x00127cf0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDirectionCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127cf0)
#endif

