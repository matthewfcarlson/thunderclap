// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00186a60..0x00186ae0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropStateByIndexCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5a2b790 {
#define TREE_TU_END }
namespace fn_f5a2b790 {} using namespace fn_f5a2b790;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5a2b790 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004bd8c0;
} // namespace fn_f5a2b790
namespace fight {
class ConditionFactoryCaster_186a60 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropStateByIndexCondition_186a60 {};
} }


// 0x00186a60 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_0 (36 B): matches/0x00186a60.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd8c0, 0) != 0;
}


// 0x00186a90 fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>::vfunc_0 (30 B): matches/0x00186a90.cpp
// sym: ??_G?$ParamIntConstRange@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186a90)
#endif


// 0x00186ab0 fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_0 (30 B): matches/0x00186ab0.cpp
// sym: ??_G?$ParamEnumConstList@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186ab0)
#endif

