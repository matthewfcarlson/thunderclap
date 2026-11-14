// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001115c0..0x00111720 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc036bb8 {
#define TREE_TU_END }
namespace fn_fc036bb8 {} using namespace fn_fc036bb8;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fc036bb8 {
extern char DAT_00491ca8;
extern char DAT_004a4348;
extern "C" int FUN_00344e74(hulk_intptr a, int b, hulk_intptr c, hulk_intptr d, int e);
class ConditionFactoryCaster_1115c0 {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1();
};
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004a43f8;
} // namespace fn_fc036bb8
namespace fight {
class ConditionFactoryCaster_111620 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class FightingOtherNPCCondition_111620 {};
} }
namespace fight {
class TrackFactoryCaster_111680 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class SemaphoreClearTrack_111680 {};
} }
namespace fn_fc036bb8 {
extern char DAT_004a44b0;

} // namespace fn_fc036bb8

// 0x001115c0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TokenCondition>::vfunc_0 (36 B): matches/0x001115c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTokenCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TokenCondition>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (FUN_00344e74(a, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_004a4348, 0) != 0);
}


// 0x001115f0 fight::ParamBool<hulkfight::ai::TokenCondition>::vfunc_0 (30 B): matches/0x001115f0.cpp
// sym: ??_G?$ParamBool@VTokenCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TokenCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::TokenCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1115f0)
#endif


// 0x00111620 fight::ConditionFactoryCasterTemplate<hulkfight::ai::FightingOtherNPCCondition>::vfunc_0 (36 B): matches/0x00111620.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VFightingOtherNPCCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::FightingOtherNPCCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a43f8, 0) != 0;
}


// 0x00111650 fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_0 (30 B): matches/0x00111650.cpp
// sym: ??_G?$ParamEnumConstList@VFightingOtherNPCCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x111650)
#endif


// 0x00111680 fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreClearTrack>::vfunc_0 (36 B): matches/0x00111680.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreClearTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a44b0, 0) != 0;
}


// 0x001116b0 fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>::vfunc_0 (30 B): matches/0x001116b0.cpp
// sym: ??_G?$ParamFloatConstRange@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1116b0)
#endif


// 0x001116d0 fight::ParamName<hulkfight::ai::SemaphoreClearTrack>::vfunc_0 (30 B): matches/0x001116d0.cpp
// sym: ??_G?$ParamName@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::SemaphoreClearTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::ai::SemaphoreClearTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1116d0)
#endif


// 0x001116f0 fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>::vfunc_0 (30 B): matches/0x001116f0.cpp
// sym: ??_G?$ParamBool@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1116f0)
#endif

