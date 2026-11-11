// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a830..0x0016a910 (kind game, layer game, confidence high), dominant class hulkfight::motion::CharacterPropStatusCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffa1c541 {
#define TREE_TU_END }
namespace fn_ffa1c541 {} using namespace fn_ffa1c541;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ffa1c541 {
extern int __cdecl Check(void*, void*, void*, void*, void*);
extern int hulk_at_00491ca8, hulk_at_004b7270;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b7340;
} // namespace fn_ffa1c541
namespace fight {
class ConditionFactoryCaster_16a890 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x0016a830 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_0 (36 B): matches/0x0016a830.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetCharacterTemplateCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &hulk_at_00491ca8, &hulk_at_004b7270, 0) != 0;
}


// 0x0016a860 fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x0016a860.cpp
// sym: ??_G?$ParamString@VTargetCharacterTemplateCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a860)
#endif


// 0x0016a890 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CharacterPropStatusCondition>::vfunc_0 (36 B): matches/0x0016a890.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CharacterPropStatusCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7340, 0) != 0;
}


// 0x0016a8c0 fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_0 (30 B): matches/0x0016a8c0.cpp
// sym: ??_G?$ParamEnumConstList@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a8c0)
#endif


// 0x0016a8e0 fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>::vfunc_0 (30 B): matches/0x0016a8e0.cpp
// sym: ??_G?$ParamFloatConstRange@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a8e0)
#endif

