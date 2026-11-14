// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00186be0..0x00186d40 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropActorToPropTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa7f24e6 {
#define TREE_TU_END }
namespace fn_fa7f24e6 {} using namespace fn_fa7f24e6;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fa7f24e6 {
class SmartPropIsCargoCondition_186be0 {};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004bdb20;
} // namespace fn_fa7f24e6
namespace fight {
class ConditionFactoryCaster_186be0 {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};
}
namespace fn_fa7f24e6 {
extern char DAT_004bdbe8;
} // namespace fn_fa7f24e6
namespace fight {
class ConditionFactoryCaster_186c40 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CSMPropIsCharacterCondition_186c40;
} }
namespace fn_fa7f24e6 {
class Actor;
class Track_186ca0;
} // namespace fn_fa7f24e6
namespace fight {
class TrackFactoryCaster_186ca0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropActorToPropTrack_186ca0 {};
} }
namespace fn_fa7f24e6 {
extern char DAT_0049850c;
extern char DAT_004bdca8;

} // namespace fn_fa7f24e6

// 0x00186be0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_0 (36 B): matches/0x00186be0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VSmartPropIsCargoCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bdb20, 0) != 0;
}


// 0x00186c10 fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_0 (30 B): matches/0x00186c10.cpp
// sym: ??_G?$ParamIntConstRange@VSmartPropIsCargoCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186c10)
#endif


// 0x00186c40 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_0 (36 B): matches/0x00186c40.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCSMPropIsCharacterCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bdbe8, 0) != 0;
}


// 0x00186c70 fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_0 (30 B): matches/0x00186c70.cpp
// sym: ??_G?$ParamBool@VCSMPropIsCharacterCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186c70)
#endif


// 0x00186ca0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorToPropTrack>::vfunc_0 (36 B): matches/0x00186ca0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorToPropTrack>::vfunc_0(void* __p0) { void * x = (void *)__p0;

    return FUN_00344e74(x, 0, &DAT_0049850c, &DAT_004bdca8, 0) != 0;
}


// 0x00186cd0 fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_0 (30 B): matches/0x00186cd0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186cd0)
#endif


// 0x00186cf0 fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_0 (30 B): matches/0x00186cf0.cpp
// sym: ??_G?$ParamIntConstRange@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186cf0)
#endif


// 0x00186d10 fight::ParamBool<hulkfight::motion::PropActorToPropTrack>::vfunc_0 (30 B): matches/0x00186d10.cpp
// sym: ??_G?$ParamBool@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropActorToPropTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropActorToPropTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x186d10)
#endif

