// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00111480..0x00111540 (kind game, layer game, confidence high), dominant class hulkfight::ai::PropsToSuckCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5acf196 {
#define TREE_TU_END }
namespace fn_f5acf196 {} using namespace fn_f5acf196;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f5acf196 {
extern char DAT_00491ca8;
extern char DAT_004a41d8;
} // namespace fn_f5acf196
namespace fight {
class ConditionFactoryCaster_111480 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class PropsToSuckCondition_111480;
} }


// 0x00111480 fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (36 B): matches/0x00111480.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004a41d8, 0) != 0;
}


// 0x001114b0 fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (30 B): matches/0x001114b0.cpp
// sym: ??_G?$ParamEnumConstList@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1114b0)
#endif


// 0x001114d0 fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (30 B): matches/0x001114d0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1114d0)
#endif


// 0x001114f0 fight::ParamBool<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (30 B): matches/0x001114f0.cpp
// sym: ??_G?$ParamBool@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::PropsToSuckCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::PropsToSuckCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1114f0)
#endif


// 0x00111510 fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (30 B): matches/0x00111510.cpp
// sym: ??_G?$ParamIntConstRange@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x111510)
#endif

