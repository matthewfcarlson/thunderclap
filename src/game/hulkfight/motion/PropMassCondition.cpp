// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00186800..0x00186900 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropMassCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f14fdbae {
#define TREE_TU_END }
namespace fn_f14fdbae {} using namespace fn_f14fdbae;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f14fdbae {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004bd4f0;
extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_004bd5b8;
} // namespace fn_f14fdbae
namespace fight {
class ConditionFactoryCaster_186860 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropMassCondition_186860 {};
} }


// 0x00186800 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_0 (36 B): matches/0x00186800.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropGrabbableIsThrownCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd4f0, 0) != 0;
}


// 0x00186830 fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_0 (30 B): matches/0x00186830.cpp
// sym: ??_G?$ParamBool@VPropGrabbableIsThrownCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186830)
#endif


// 0x00186860 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMassCondition>::vfunc_0 (36 B): matches/0x00186860.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropMassCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMassCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004bd5b8, 0) != 0;
}


// 0x00186890 fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>::vfunc_0 (30 B): matches/0x00186890.cpp
// sym: ??_G?$ParamIntConstRange@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186890)
#endif


// 0x001868b0 fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_0 (30 B): matches/0x001868b0.cpp
// sym: ??_G?$ParamEnumConstList@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1868b0)
#endif


// 0x001868d0 fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>::vfunc_0 (30 B): matches/0x001868d0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1868d0)
#endif

