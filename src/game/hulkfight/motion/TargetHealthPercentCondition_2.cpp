// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0016a6d0..0x0016a7b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetHealthPercentCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd656eb9 {
#define TREE_TU_END }
namespace fn_fd656eb9 {} using namespace fn_fd656eb9;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd656eb9 {
extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_004b7010;
} // namespace fn_fd656eb9
namespace fight {
class ConditionFactoryCaster_16a6d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TargetLocomotionMotionStateCondition_16a6d0;
} }
namespace fn_fd656eb9 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b70e0;
} // namespace fn_fd656eb9
namespace fight {
class ConditionFactoryCaster_16a730 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TargetHealthPercentCondition_16a730 {};
} }


// 0x0016a6d0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_0 (36 B): matches/0x0016a6d0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b7010, 0) != 0;
}


// 0x0016a700 fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_0 (30 B): matches/0x0016a700.cpp
// sym: ??_G?$ParamEnumConstList@VTargetLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a700)
#endif


// 0x0016a730 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_0 (36 B): matches/0x0016a730.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b70e0, 0) != 0;
}


// 0x0016a760 fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_0 (30 B): matches/0x0016a760.cpp
// sym: ??_G?$ParamEnumConstList@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a760)
#endif


// 0x0016a780 fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>::vfunc_0 (30 B): matches/0x0016a780.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a780)
#endif

