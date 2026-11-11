// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001111e0..0x001112e0 (kind game, layer game, confidence high), dominant class hulkfight::ai::KeyWordWaitCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f74dcadf {
#define TREE_TU_END }
namespace fn_f74dcadf {} using namespace fn_f74dcadf;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f74dcadf {
extern int gA;
extern int gB;
extern "C" int __cdecl Check(void*, int, void*, void*, int);
} // namespace fn_f74dcadf
namespace fight {
class ConditionFactoryCaster_1111e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f74dcadf {
extern char DAT_00491ca8;
extern char DAT_004a3f00;
extern hulk_intptr FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);

} // namespace fn_f74dcadf

// 0x001111e0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::LeashedCondition>::vfunc_0 (36 B): matches/0x001111e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VLeashedCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::LeashedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &gA, &gB, 0) != 0;
}


// 0x00111210 fight::ParamBool<hulkfight::ai::LeashedCondition>::vfunc_0 (30 B): matches/0x00111210.cpp
// sym: ??_G?$ParamBool@VLeashedCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::LeashedCondition>::~ParamBool() {}


// 0x00111240 fight::ConditionFactoryCasterTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_0 (36 B): matches/0x00111240.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_0(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    return (int)FUN_00344e74(a, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_004a3f00, 0) ? 1 : 0;
}


// 0x00111270 fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_0 (30 B): matches/0x00111270.cpp
// sym: ??_G?$ParamEnumConstList@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::~ParamEnumConstList() {}


// 0x00111290 fight::ParamString<hulkfight::ai::KeyWordWaitCondition>::vfunc_0 (30 B): matches/0x00111290.cpp
// sym: ??_G?$ParamString@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::ai::KeyWordWaitCondition>::~ParamString() {}


// 0x001112b0 fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>::vfunc_0 (30 B): matches/0x001112b0.cpp
// sym: ??_G?$ParamFloatConstRange@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>::~ParamFloatConstRange() {}

