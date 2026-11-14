// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001869e0..0x00186a60 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropStateByNameCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f574dea6 {
#define TREE_TU_END }
namespace fn_f574dea6 {} using namespace fn_f574dea6;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_1869e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f574dea6 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int hulk_at_00491ca8;
extern int hulk_at_004bd7f8;

} // namespace fn_f574dea6

// 0x001869e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByNameCondition>::vfunc_0 (36 B): matches/0x001869e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &hulk_at_00491ca8, &hulk_at_004bd7f8, 0) != 0;
}


// 0x00186a10 fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>::vfunc_0 (30 B): matches/0x00186a10.cpp
// sym: ??_G?$ParamIntConstRange@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186a10)
#endif


// 0x00186a30 fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_0 (30 B): matches/0x00186a30.cpp
// sym: ??_G?$ParamEnumConstList@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186a30)
#endif

