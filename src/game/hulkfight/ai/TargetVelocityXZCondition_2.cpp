// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00128140..0x001281c0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityXZCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4ab4178 {
#define TREE_TU_END }
namespace fn_f4ab4178 {} using namespace fn_f4ab4178;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_128140 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TargetVelocityXZCondition_128140 {};
} }
namespace fn_f4ab4178 {
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a88d0;

} // namespace fn_f4ab4178

// 0x00128140 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_0 (36 B): matches/0x00128140.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a88d0, 0) != 0;
}


// 0x00128170 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_0 (30 B): matches/0x00128170.cpp
// sym: ??_G?$ParamEnumConstList@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x128170)
#endif


// 0x00128190 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>::vfunc_0 (30 B): matches/0x00128190.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x128190)
#endif

