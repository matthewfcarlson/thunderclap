// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a3b0..0x0016a430 (kind game, layer game, confidence high), dominant class hulkfight::motion::TurningVelocityCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0f627b9 {
#define TREE_TU_END }
namespace fn_f0f627b9 {} using namespace fn_f0f627b9;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0f627b9 {
extern "C" int __cdecl check(void*, int, void*, void*, int);
extern char DAT_004b6aa8;
} // namespace fn_f0f627b9
namespace fight {
class ConditionFactoryCaster_16a3b0 {
  public:
    virtual bool Test(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace motion {
class TurningVelocityCondition_16a3b0 {};
} }


// 0x0016a3b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_0 (36 B): matches/0x0016a3b0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTurningVelocityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_00491ca8, &DAT_004b6aa8, 0) != 0;
}


// 0x0016a3e0 fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_0 (30 B): matches/0x0016a3e0.cpp
// sym: ??_G?$ParamEnumConstList@VTurningVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a3e0)
#endif


// 0x0016a400 fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>::vfunc_0 (30 B): matches/0x0016a400.cpp
// sym: ??_G?$ParamFloatConstRange@VTurningVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a400)
#endif

