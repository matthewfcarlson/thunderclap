// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00111360..0x001113e0 (kind game, layer game, confidence high), dominant class hulkfight::ai::InActiveCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_feff1804 {
#define TREE_TU_END }
namespace fn_feff1804 {} using namespace fn_feff1804;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_111360 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class InActiveCondition_111360 {};
} }
namespace fn_feff1804 {
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a4068;

} // namespace fn_feff1804

// 0x00111360 fight::ConditionFactoryCasterTemplate<hulkfight::ai::InActiveCondition>::vfunc_0 (36 B): matches/0x00111360.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VInActiveCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::InActiveCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return helper(p, 0, &DAT_00491ca8, &DAT_004a4068, 0) != 0;
}


// 0x00111390 fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_0 (30 B): matches/0x00111390.cpp
// sym: ??_G?$ParamEnumConstList@VInActiveCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x111390)
#endif


// 0x001113b0 fight::ParamBool<hulkfight::ai::InActiveCondition>::vfunc_0 (30 B): matches/0x001113b0.cpp
// sym: ??_G?$ParamBool@VInActiveCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::InActiveCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::InActiveCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1113b0)
#endif

