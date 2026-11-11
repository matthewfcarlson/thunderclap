// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110e60..0x00110f00 (kind game, layer game, confidence high), dominant class hulkfight::ai::OnBlockedTriangleCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1a9e6f5 {
#define TREE_TU_END }
namespace fn_f1a9e6f5 {} using namespace fn_f1a9e6f5;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f1a9e6f5 {
extern char DAT_00491ca8;
extern char DAT_004a3940;
} // namespace fn_f1a9e6f5
namespace fight {
class ConditionFactoryCaster_110e60 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace ai {
class OnBlockedTriangleCondition_110e60;
} }


// 0x00110e60 fight::ConditionFactoryCasterTemplate<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_0 (36 B): matches/0x00110e60.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004a3940, 0) != 0;
}


// 0x00110e90 fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_0 (30 B): matches/0x00110e90.cpp
// sym: ??_G?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x110e90)
#endif


// 0x00110eb0 fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_0 (30 B): matches/0x00110eb0.cpp
// sym: ??_G?$ParamBool@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x110eb0)
#endif


// 0x00110ed0 fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_0 (30 B): matches/0x00110ed0.cpp
// sym: ??_G?$ParamIntConstRange@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x110ed0)
#endif

