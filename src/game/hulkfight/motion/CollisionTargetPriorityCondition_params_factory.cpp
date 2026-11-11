// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154080..0x00154220 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetPriorityCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fadc1bae {
#define TREE_TU_END }
namespace fn_fadc1bae {} using namespace fn_fadc1bae;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class ConditionFactoryCaster_154080 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionThrowCondition_154080 {};
} }
namespace fn_fadc1bae {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b1da0;
struct Data {
    int x;
};
extern Data hulk_at_00491ca8, hulk_at_004b1e68;
extern int __cdecl check(void*, int, Data*, Data*, int);
extern char DAT_004b1f30;
} // namespace fn_fadc1bae
namespace fight {
class ConditionFactoryCaster_154140 {
  public:
    virtual int Check(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace motion {
class CollisionSourceTypeCondition_154140;
} }
namespace fn_fadc1bae {
extern "C" int __cdecl CastCheck(void*, int, void*, void*, int);
} // namespace fn_fadc1bae
namespace fight {
class ConditionFactoryCaster_1541a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionTargetPriorityCondition_1541a0 {};
} }
namespace fn_fadc1bae {
extern char DAT_004b2000;

} // namespace fn_fadc1bae

// 0x00154080 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_0 (36 B): matches/0x00154080.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionThrowCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b1da0, 0) != 0;
}


// 0x001540b0 fight::ParamBool<hulkfight::motion::CollisionThrowCondition>::vfunc_0 (30 B): matches/0x001540b0.cpp
// sym: ??_G?$ParamBool@VCollisionThrowCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CollisionThrowCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CollisionThrowCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1540b0)
#endif


// 0x001540e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_0 (36 B): matches/0x001540e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &hulk_at_00491ca8, &hulk_at_004b1e68, 0) != 0;
}


// 0x00154110 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_0 (30 B): matches/0x00154110.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154110)
#endif


// 0x00154140 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_0 (36 B): matches/0x00154140.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionSourceTypeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b1f30, 0) != 0;
}


// 0x00154170 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_0 (30 B): matches/0x00154170.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceTypeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154170)
#endif


// 0x001541a0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_0 (36 B): matches/0x001541a0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return CastCheck(p, 0, &DAT_00491ca8, &DAT_004b2000, 0) != 0;
}


// 0x001541d0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_0 (30 B): matches/0x001541d0.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1541d0)
#endif


// 0x001541f0 fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_0 (30 B): matches/0x001541f0.cpp
// sym: ??_G?$ParamIntConstRange@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1541f0)
#endif

