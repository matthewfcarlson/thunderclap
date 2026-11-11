// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186b60..0x00186be0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropCollidedWithWorldCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f56c16da {
#define TREE_TU_END }
namespace fn_f56c16da {} using namespace fn_f56c16da;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f56c16da {
extern char DAT_004bda50;
} // namespace fn_f56c16da
namespace fight {
class ConditionFactoryCaster_186b60 {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace motion {
class PropCollidedWithWorldCondition_186b60;
} }


// 0x00186b60 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_0 (36 B): matches/0x00186b60.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004bda50, 0)) != 0;
}


// 0x00186b90 fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_0 (30 B): matches/0x00186b90.cpp
// sym: ??_G?$ParamIntConstRange@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186b90)
#endif


// 0x00186bb0 fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_0 (30 B): matches/0x00186bb0.cpp
// sym: ??_G?$ParamBool@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186bb0)
#endif

