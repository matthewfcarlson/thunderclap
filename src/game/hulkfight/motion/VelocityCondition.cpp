// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0016a0d0..0x0016a210 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5f2c90b {
#define TREE_TU_END }
namespace fn_f5f2c90b {} using namespace fn_f5f2c90b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5f2c90b {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f5f2c90b
namespace fight {
class ConditionFactoryCaster_16a0d0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TargetMotionStateCondition_16a0d0 {};
} }
namespace fn_f5f2c90b {
extern char DAT_004b6610;
extern char DAT_004b66e0;
} // namespace fn_f5f2c90b
namespace fight {
class ConditionFactoryCaster_16a130 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class IntentionButtonDownAnyCondition_16a130 {};
} }
namespace fn_f5f2c90b {
extern char DAT_004b67a8;
} // namespace fn_f5f2c90b
namespace fight {
class ConditionFactoryCaster_16a190 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class VelocityCondition_16a190;
} }


// 0x0016a0d0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetMotionStateCondition>::vfunc_0 (36 B): matches/0x0016a0d0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetMotionStateCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetMotionStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b6610, 0) != 0;
}


// 0x0016a100 fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_0 (30 B): matches/0x0016a100.cpp
// sym: ??_G?$ParamEnumConstList@VTargetMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a100)
#endif


// 0x0016a130 fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_0 (36 B): matches/0x0016a130.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VIntentionButtonDownAnyCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b66e0, 0) != 0;
}


// 0x0016a160 fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_0 (30 B): matches/0x0016a160.cpp
// sym: ??_G?$ParamBool@VIntentionButtonDownAnyCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a160)
#endif


// 0x0016a190 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityCondition>::vfunc_0 (36 B): matches/0x0016a190.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVelocityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b67a8, 0) != 0;
}


// 0x0016a1c0 fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_0 (30 B): matches/0x0016a1c0.cpp
// sym: ??_G?$ParamEnumConstList@VVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a1c0)
#endif


// 0x0016a1e0 fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>::vfunc_0 (30 B): matches/0x0016a1e0.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a1e0)
#endif

