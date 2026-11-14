// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00186900..0x001869e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropIsAttachedCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f00beca1 {
#define TREE_TU_END }
namespace fn_f00beca1 {} using namespace fn_f00beca1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f00beca1 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f00beca1
namespace fight {
class ConditionFactoryCaster_186900 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropAtRestCondition_186900 {};
} }
namespace fn_f00beca1 {
extern char DAT_004bd670;
extern char DAT_004bd730;
} // namespace fn_f00beca1
namespace fight {
class ConditionFactoryCaster_186960 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropIsAttachedCondition_186960 {};
} }


// 0x00186900 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropAtRestCondition>::vfunc_0 (36 B): matches/0x00186900.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropAtRestCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropAtRestCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd670, 0) != 0;
}


// 0x00186930 fight::ParamBool<hulkfight::motion::PropAtRestCondition>::vfunc_0 (30 B): matches/0x00186930.cpp
// sym: ??_G?$ParamBool@VPropAtRestCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropAtRestCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropAtRestCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186930)
#endif


// 0x00186960 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsAttachedCondition>::vfunc_0 (36 B): matches/0x00186960.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropIsAttachedCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsAttachedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd730, 0) != 0;
}


// 0x00186990 fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>::vfunc_0 (30 B): matches/0x00186990.cpp
// sym: ??_G?$ParamIntConstRange@VPropIsAttachedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186990)
#endif


// 0x001869b0 fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>::vfunc_0 (30 B): matches/0x001869b0.cpp
// sym: ??_G?$ParamBool@VPropIsAttachedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1869b0)
#endif

