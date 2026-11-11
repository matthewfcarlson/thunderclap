// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127b20..0x00127c20 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDistanceCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa4f80aa {
#define TREE_TU_END }
namespace fn_fa4f80aa {} using namespace fn_fa4f80aa;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_127b20 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa4f80aa {
extern "C" int FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;
} // namespace fn_fa4f80aa
namespace fight {
class ConditionFactoryCaster_127b80 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TargetDistanceCondition_127b80 {};
} }
namespace fn_fa4f80aa {
extern char DAT_00491ca8;
extern char DAT_004a80d0;

} // namespace fn_fa4f80aa

// 0x00127b20 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetTypeCondition>::vfunc_0 (36 B): matches/0x00127b20.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetTypeCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetTypeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}


// 0x00127b50 fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_0 (30 B): matches/0x00127b50.cpp
// sym: ??_G?$ParamEnumConstList@VTargetTypeCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::~ParamEnumConstList() {}


// 0x00127b80 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceCondition>::vfunc_0 (36 B): matches/0x00127b80.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetDistanceCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a80d0, 0) != 0;
}


// 0x00127bb0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_0 (30 B): matches/0x00127bb0.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::~ParamEnumConstList() {}


// 0x00127bd0 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>::vfunc_0 (30 B): matches/0x00127bd0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>::~ParamFloatConstRange() {}


// 0x00127bf0 fight::ParamBool<hulkfight::ai::TargetDistanceCondition>::vfunc_0 (30 B): matches/0x00127bf0.cpp
// sym: ??_G?$ParamBool@VTargetDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TargetDistanceCondition>::~ParamBool() {}

