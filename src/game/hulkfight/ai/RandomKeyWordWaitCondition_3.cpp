// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00111540..0x001115c0 (kind game, layer game, confidence high), dominant class hulkfight::ai::RandomKeyWordWaitCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8d1d998 {
#define TREE_TU_END }
namespace fn_f8d1d998 {} using namespace fn_f8d1d998;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f8d1d998 {
extern "C" int __cdecl FUN_00344e74(const char*, const char*, const char*, const char*, int);
} // namespace fn_f8d1d998
namespace fight {
class ConditionFactoryCaster_111540 {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class RandomKeyWordWaitCondition_111540 {};
} }
namespace fn_f8d1d998 {
extern const char DAT_00491ca8[];
extern const char DAT_004a4290[];

} // namespace fn_f8d1d998

// 0x00111540 fight::ConditionFactoryCasterTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0 (36 B): matches/0x00111540.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, DAT_00491ca8, DAT_004a4290, 0) != 0;
}


// 0x00111570 fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0 (30 B): matches/0x00111570.cpp
// sym: ??_G?$ParamEnumConstList@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x111570)
#endif


// 0x00111590 fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0 (30 B): matches/0x00111590.cpp
// sym: ??_G?$ParamIntConstRange@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x111590)
#endif

