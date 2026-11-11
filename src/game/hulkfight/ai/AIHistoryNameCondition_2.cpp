// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110f00..0x00111060 (kind game, layer game, confidence high), dominant class hulkfight::ai::AIHistoryNameCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5cad1e3 {
#define TREE_TU_END }
namespace fn_f5cad1e3 {} using namespace fn_f5cad1e3;
#include "game/hulkfight/ai.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace hulkfight { namespace ai {
class AIFightNodeCondition_110f00 {};
} }
namespace fn_f5cad1e3 {
} // namespace fn_f5cad1e3
namespace fight {
class ConditionFactoryCaster_110f00 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f5cad1e3 {
extern char DAT_00491ca8;
extern char DAT_004a3a00;
} // namespace fn_f5cad1e3
namespace fight {
class ConditionFactoryCaster_110f60 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class DefendingCondition_110f60 {};
} }
namespace fn_f5cad1e3 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004a3ab0;
} // namespace fn_f5cad1e3
namespace fight {
class ConditionFactoryCaster_110fc0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class AIHistoryNameCondition_110fc0;
} }
namespace fn_f5cad1e3 {
extern char DAT_004a3b68;

} // namespace fn_f5cad1e3

// 0x00110f00 fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_0 (36 B): matches/0x00110f00.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VAIFightNodeCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004a3a00, 0)) != 0;
}


// 0x00110f30 fight::ParamBranch<hulkfight::ai::AIFightNodeCondition>::vfunc_0 (30 B): matches/0x00110f30.cpp
// sym: ??_G?$ParamBranch@VAIFightNodeCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<hulkfight::ai::AIFightNodeCondition>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<hulkfight::ai::AIFightNodeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x110f30)
#endif


// 0x00110f60 fight::ConditionFactoryCasterTemplate<hulkfight::ai::DefendingCondition>::vfunc_0 (36 B): matches/0x00110f60.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VDefendingCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::DefendingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a3ab0, 0) != 0;
}


// 0x00110f90 fight::ParamBool<hulkfight::ai::DefendingCondition>::vfunc_0 (30 B): matches/0x00110f90.cpp
// sym: ??_G?$ParamBool@VDefendingCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::DefendingCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::DefendingCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x110f90)
#endif


// 0x00110fc0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_0 (36 B): matches/0x00110fc0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a3b68, 0) != 0;
}


// 0x00110ff0 fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_0 (30 B): matches/0x00110ff0.cpp
// sym: ??_G?$ParamEnumConstList@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x110ff0)
#endif


// 0x00111010 fight::ParamString<hulkfight::ai::AIHistoryNameCondition>::vfunc_0 (30 B): matches/0x00111010.cpp
// sym: ??_G?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::ai::AIHistoryNameCondition>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::ai::AIHistoryNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x111010)
#endif


// 0x00111030 fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>::vfunc_0 (30 B): matches/0x00111030.cpp
// sym: ??_G?$ParamFloatConstRange@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x111030)
#endif

