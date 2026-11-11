// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154480..0x001545e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceNodeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa50d77a {
#define TREE_TU_END }
namespace fn_fa50d77a {} using namespace fn_fa50d77a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fa50d77a {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b2590;
} // namespace fn_fa50d77a
namespace fight {
class ConditionFactoryCaster_154480 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionThrownObjectCondition_154480 {};
} }
namespace fn_fa50d77a {
extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_004b2660;
} // namespace fn_fa50d77a
namespace fight {
class ConditionFactoryCaster_1544e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionExplosionCondition_1544e0 {};
} }
namespace fn_fa50d77a {
extern char DAT_004b2728;
} // namespace fn_fa50d77a
namespace fight {
class ConditionFactoryCaster_154540 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionSourceNodeCondition_154540 {};
} }


// 0x00154480 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_0 (36 B): matches/0x00154480.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b2590, 0) != 0;
}


// 0x001544b0 fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_0 (30 B): matches/0x001544b0.cpp
// sym: ??_G?$ParamBool@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>::~ParamBool() {}


// 0x001544e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionExplosionCondition>::vfunc_0 (36 B): matches/0x001544e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionExplosionCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionExplosionCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b2660, 0) != 0;
}


// 0x00154510 fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>::vfunc_0 (30 B): matches/0x00154510.cpp
// sym: ??_G?$ParamBool@VCollisionExplosionCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>::~ParamBool() {}


// 0x00154540 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_0 (36 B): matches/0x00154540.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b2728, 0) != 0;
}


// 0x00154570 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_0 (30 B): matches/0x00154570.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::~ParamEnumConstList() {}


// 0x00154590 fight::ParamBranch<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_0 (30 B): matches/0x00154590.cpp
// sym: ??_G?$ParamBranch@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<hulkfight::motion::CollisionSourceNodeCondition>::~ParamBranch() {}


// 0x001545b0 fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_0 (30 B): matches/0x001545b0.cpp
// sym: ??_G?$ParamBool@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>::~ParamBool() {}

