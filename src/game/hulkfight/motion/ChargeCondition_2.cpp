// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a050..0x0016a0d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f83e72bb {
#define TREE_TU_END }
namespace fn_f83e72bb {} using namespace fn_f83e72bb;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f83e72bb {
extern "C" int __cdecl Check(void*, int, void*, void*, int);
} // namespace fn_f83e72bb
namespace fight {
class ConditionFactoryCaster_16a050 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class ChargeCondition_16a050 {};
} }
namespace fn_f83e72bb {
extern char DAT_004b6550;

} // namespace fn_f83e72bb

// 0x0016a050 fight::ConditionFactoryCasterTemplate<hulkfight::motion::ChargeCondition>::vfunc_0 (36 B): matches/0x0016a050.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VChargeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::ChargeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b6550, 0) != 0;
}


// 0x0016a080 fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_0 (30 B): matches/0x0016a080.cpp
// sym: ??_G?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a080)
#endif


// 0x0016a0a0 fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>::vfunc_0 (30 B): matches/0x0016a0a0.cpp
// sym: ??_G?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x16a0a0)
#endif

