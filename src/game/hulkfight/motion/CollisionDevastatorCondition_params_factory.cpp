// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00154220..0x00154400 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f12b892d {
#define TREE_TU_END }
namespace fn_f12b892d {} using namespace fn_f12b892d;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f12b892d {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b20d0;
} // namespace fn_f12b892d
namespace fight {
class ConditionFactoryCaster_154220 {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace motion {
class CollisionDevastatorCondition_154220 {};
} }
namespace fight {
class ConditionFactoryCaster_154280 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitPushbackCondition_154280 {};
} }
namespace fn_f12b892d {
extern char DAT_004b2190;
class ConditionFactoryCaster_1542e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern int hulk_at_00491ca8, hulk_at_004b2258;
extern char DAT_004b2328;
} // namespace fn_f12b892d
namespace fight {
class ConditionFactoryCaster_154340 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionTargetSizeCondition_154340 {};
} }


// 0x00154220 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDevastatorCondition>::vfunc_0 (36 B): matches/0x00154220.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDevastatorCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b20d0, 0) != 0;
}


// 0x00154250 fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::vfunc_0 (30 B): matches/0x00154250.cpp
// sym: ??_G?$ParamBool@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154250)
#endif


// 0x00154280 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackCondition>::vfunc_0 (36 B): matches/0x00154280.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHitPushbackCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b2190, 0) != 0;
}


// 0x001542b0 fight::ParamBool<hulkfight::motion::HitPushbackCondition>::vfunc_0 (30 B): matches/0x001542b0.cpp
// sym: ??_G?$ParamBool@VHitPushbackCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::HitPushbackCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::HitPushbackCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1542b0)
#endif


// 0x001542e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_0 (36 B): matches/0x001542e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionTargetIsTargetCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &hulk_at_00491ca8, &hulk_at_004b2258, 0) != 0;
}


// 0x00154310 fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_0 (30 B): matches/0x00154310.cpp
// sym: ??_G?$ParamBool@VCollisionTargetIsTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154310)
#endif


// 0x00154340 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_0 (36 B): matches/0x00154340.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionTargetSizeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b2328, 0) != 0;
}


// 0x00154370 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_0 (30 B): matches/0x00154370.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionTargetSizeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154370)
#endif


// 0x001543a0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_0 (36 B): matches/0x001543a0.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_001543a0@@UAE_NPBD@Z
namespace fn_001543a0 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
};
} // namespace fight
extern int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int a, hulk_at_004b23f8;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &a, &hulk_at_004b23f8, 0) != 0;
}
} // namespace fn_001543a0


// 0x001543d0 fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_0 (30 B): matches/0x001543d0.cpp
// sym: ??_G?$ParamBool@VCollisionSourceIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1543d0)
#endif

