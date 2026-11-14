// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001280c0..0x00128140 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2408468 {
#define TREE_TU_END }
namespace fn_f2408468 {} using namespace fn_f2408468;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f2408468 {
class ConditionFactoryCaster_1280c0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class AcquireTargetCondition_1280c0 {};
extern char DAT_00491ca8;
extern char DAT_004a8818;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

} // namespace fn_f2408468

// 0x001280c0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::AcquireTargetCondition>::vfunc_0 (36 B): matches/0x001280c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::AcquireTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a8818, 0) != 0;
}


// 0x001280f0 fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>::vfunc_0 (30 B): matches/0x001280f0.cpp
// sym: ??_G?$ParamFloatConstRange@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1280f0)
#endif


// 0x00128110 fight::ParamBool<hulkfight::ai::AcquireTargetCondition>::vfunc_0 (30 B): matches/0x00128110.cpp
// sym: ??_G?$ParamBool@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::AcquireTargetCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::AcquireTargetCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x128110)
#endif

