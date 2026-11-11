// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00051480..0x000514f0 (kind game, layer game, confidence high), dominant class CStageCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc5f15cd {
#define TREE_TU_END }
namespace fn_fc5f15cd {} using namespace fn_fc5f15cd;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc5f15cd {
extern "C" int __cdecl FUN_00344e74(int, int, const void*, const void*, int);
extern char DAT_00494510;
} // namespace fn_fc5f15cd
namespace fight {
class ConditionFactoryCaster_51480 {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
};
}
namespace fight {
class CStageCondition_51480;
}


// 0x00051480 fight::ConditionFactoryCasterTemplate<CStageCondition>::vfunc_0 (36 B): matches/0x00051480.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCStageCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CStageCondition>::vfunc_0(void* __p0) { int x = (int)__p0;

    return FUN_00344e74(x, 0, &DAT_00491ca8, &DAT_00494510, 0) != 0;
}


// 0x000514b0 fight::ParamEnumConstList<CStageCondition>::vfunc_0 (30 B): matches/0x000514b0.cpp
// sym: ??_G?$ParamEnumConstList@VCStageCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CStageCondition>::~ParamEnumConstList() {}


// 0x000514d0 fight::ParamIntConstRange<CStageCondition>::vfunc_0 (30 B): matches/0x000514d0.cpp
// sym: ??_G?$ParamIntConstRange@VCStageCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CStageCondition>::~ParamIntConstRange() {}

