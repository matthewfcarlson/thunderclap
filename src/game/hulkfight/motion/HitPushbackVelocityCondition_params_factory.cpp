// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154400..0x00154480 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackVelocityCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3764e8f {
#define TREE_TU_END }
namespace fn_f3764e8f {} using namespace fn_f3764e8f;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f3764e8f {
extern char DAT_004b24c8;
} // namespace fn_f3764e8f
namespace fight {
class ConditionFactoryCaster_154400 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitPushbackVelocityCondition_154400 {};
} }


// 0x00154400 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_0 (36 B): matches/0x00154400.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004b24c8, 0)) != 0;
}


// 0x00154430 fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_0 (30 B): matches/0x00154430.cpp
// sym: ??_G?$ParamEnumConstList@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154430)
#endif


// 0x00154450 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_0 (30 B): matches/0x00154450.cpp
// sym: ??_G?$ParamFloatConstRange@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154450)
#endif

