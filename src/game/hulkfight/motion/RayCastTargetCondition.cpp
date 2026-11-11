// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a310..0x0016a3b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastTargetCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6eccf8b {
#define TREE_TU_END }
namespace fn_f6eccf8b {} using namespace fn_f6eccf8b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6eccf8b {
extern int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_004b69e0;
} // namespace fn_f6eccf8b
namespace fight {
class ConditionFactoryCaster_16a310 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class RayCastTargetCondition_16a310 {};
} }


// 0x0016a310 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (36 B): matches/0x0016a310.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b69e0, 0) != 0;
}


// 0x0016a340 fight::ParamVector<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (30 B): matches/0x0016a340.cpp
// sym: ??_G?$ParamVector@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::RayCastTargetCondition>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::RayCastTargetCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a340)
#endif


// 0x0016a360 fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (30 B): matches/0x0016a360.cpp
// sym: ??_G?$ParamFloatConstRange@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a360)
#endif


// 0x0016a380 fight::ParamBool<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (30 B): matches/0x0016a380.cpp
// sym: ??_G?$ParamBool@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::RayCastTargetCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::RayCastTargetCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a380)
#endif

