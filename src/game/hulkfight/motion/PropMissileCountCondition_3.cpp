// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00186ae0..0x00186b60 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropMissileCountCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb6015c0 {
#define TREE_TU_END }
namespace fn_fb6015c0 {} using namespace fn_fb6015c0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_186ae0 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropMissileCountCondition_186ae0 {};
} }
namespace fn_fb6015c0 {
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_004bd988;

} // namespace fn_fb6015c0

// 0x00186ae0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_0 (36 B): matches/0x00186ae0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_00491ca8, &DAT_004bd988, 0) != 0;
}


// 0x00186b10 fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>::vfunc_0 (30 B): matches/0x00186b10.cpp
// sym: ??_G?$ParamIntConstRange@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186b10)
#endif


// 0x00186b30 fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_0 (30 B): matches/0x00186b30.cpp
// sym: ??_G?$ParamEnumConstList@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186b30)
#endif

