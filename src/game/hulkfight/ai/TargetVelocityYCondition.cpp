// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127ec0..0x00127fa0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityYCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffd564f9 {
#define TREE_TU_END }
namespace fn_ffd564f9 {} using namespace fn_ffd564f9;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_127ec0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class HasTargetCondition_127ec0 {};
} }
namespace fn_ffd564f9 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a8530;
} // namespace fn_ffd564f9
namespace fight {
class ConditionFactoryCaster_127f20 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TargetVelocityYCondition_127f20 {};
} }
namespace fn_ffd564f9 {
extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_004a85e8;

} // namespace fn_ffd564f9

// 0x00127ec0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasTargetCondition>::vfunc_0 (36 B): matches/0x00127ec0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHasTargetCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a8530, 0) != 0;
}


// 0x00127ef0 fight::ParamBool<hulkfight::ai::HasTargetCondition>::vfunc_0 (30 B): matches/0x00127ef0.cpp
// sym: ??_G?$ParamBool@VHasTargetCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::HasTargetCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::HasTargetCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127ef0)
#endif


// 0x00127f20 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_0 (36 B): matches/0x00127f20.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetVelocityYCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004a85e8, 0) != 0;
}


// 0x00127f50 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_0 (30 B): matches/0x00127f50.cpp
// sym: ??_G?$ParamEnumConstList@VTargetVelocityYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127f50)
#endif


// 0x00127f70 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>::vfunc_0 (30 B): matches/0x00127f70.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetVelocityYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127f70)
#endif

