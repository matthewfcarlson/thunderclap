// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00187340..0x00188ab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f5c5d2a1 {
#define TREE_TU_END }
namespace fn_f5c5d2a1 {} using namespace fn_f5c5d2a1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class TrackFactory_187340 {
  public:
    virtual void dummy();
};
}
namespace fight {
template <class T> class TrackFactoryTemplate_187340 : public TrackFactory_187340 {};
}
namespace fight {
class TrackFactoryCaster_187340 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class ShieldArcTrack_187340;
} }
namespace fn_f5c5d2a1 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be510;
} // namespace fn_f5c5d2a1
namespace fight {
class TrackFactoryCaster_1873a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropAddToCollisionTrack_1873a0;
} }
namespace fn_f5c5d2a1 {
extern "C" int __cdecl Check(void*, int, void*, void*, int);
} // namespace fn_f5c5d2a1
namespace fight {
class TrackFactoryCaster_187440 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropAddToMissileCountTrack_187440 {};
} }
namespace fn_f5c5d2a1 {
extern char DAT_004be5c8;
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern char DAT_004be680;
} // namespace fn_f5c5d2a1
namespace fight {
class TrackFactoryCaster_1874c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropDamageTrack_1874c0 {};
} }
namespace fn_f5c5d2a1 {
extern char DAT_004be728;
} // namespace fn_f5c5d2a1
namespace fight {
class TrackFactoryCaster_187540 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class TrackFactoryCaster_1875e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropDestroyTrack_1875e0 {};
} }
namespace fn_f5c5d2a1 {
extern char DAT_004be7d0;
} // namespace fn_f5c5d2a1
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f5c5d2a1 {
void* FUN_0008d690(unsigned int size);
} // namespace fn_f5c5d2a1
namespace hulkfight { namespace motion {
class PropMissionCriticalCondition_187650 {
public:
    void FUN_0017f2b0();
    void FUN_0017f2d0();
};
} }
namespace fn_f5c5d2a1 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f5c5d2a1
namespace fight {
template <class T>
class ParamBool_187650 : public ParamBoolBase {
public:
    ParamBool_187650(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_187650 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187650(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f5c5d2a1 {
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f5c5d2a1
namespace hulkfight { namespace motion {
class SmartPropGrabbableCondition_1876f0 {
public:
    void FUN_0017f2f0();
    void FUN_0017f310();
    void FUN_0017f330();
    void FUN_0017f350();
    void FUN_0017f370();
    void FUN_0017f390();
    void FUN_0017f3b0();
    void FUN_0017f3d0();
    void FUN_0017f3f0();
    void FUN_0017f410();
};
} }
namespace fight {
template <class T>
class ParamBool_1876f0 : public ParamBoolBase {
public:
    ParamBool_1876f0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_1876f0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1876f0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace hulkfight { namespace motion {
class PropGrabbableIsThrownCondition_187960 {
public:
    void FUN_0017f470();
};
} }
namespace fight {
template <class T>
class ParamBool_187960 : public ParamBoolBase {
public:
    ParamBool_187960(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropAtRestCondition_1879c0 {
public:
    void FUN_0017f500();
};
} }
namespace fight {
template <class T>
class ParamBool_1879c0 : public ParamBoolBase {
public:
    ParamBool_1879c0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropIsAttachedCondition_187a20 {
public:
    void FUN_0017f520();
    void FUN_0017f530();
};
} }
namespace fight {
template <class T>
class ParamBool_187a20 : public ParamBoolBase {
public:
    ParamBool_187a20(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_187a20 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187a20(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropCollidedWithWorldCondition_187ca0 {
public:
    void FUN_0017f660();
    void FUN_0017f670();
};
} }
namespace fight {
template <class T>
class ParamBool_187ca0 : public ParamBoolBase {
public:
    ParamBool_187ca0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_187ca0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187ca0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CSMPropIsCharacterCondition_187da0 {
public:
    void FUN_0017f6a0();
};
} }
namespace fight {
template <class T>
class ParamBool_187da0 : public ParamBoolBase {
public:
    ParamBool_187da0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropActorThinkingTrack_187f00 {
public:
    void FUN_0017f760();
    void FUN_0017f780();
};
} }
namespace fn_f5c5d2a1 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f5c5d2a1
namespace fight {
template <class T>
class ParamBool_187f00 : public ParamBoolBase {
public:
    ParamBool_187f00(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_187f00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_187f00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropDropTrack_187fa0 {
public:
    void FUN_0017f790();
    void FUN_0017f7b0();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_187fa0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_187fa0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_187fa0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187fa0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class BallAndChainSpinTrack_188220 {
public:
    void FUN_001801c0();
    void FUN_001801d0();
    void FUN_001801f0();
    void FUN_00180210();
    void FUN_00180230();
    void FUN_00180250();
    void FUN_00180280();
    void FUN_001802c0();
};
} }
namespace fn_f5c5d2a1 {
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
} // namespace fn_f5c5d2a1
namespace hulkfight { namespace motion {
class ShieldArcTrack_1883f0 {
public:
    void FUN_00180300();
    void FUN_00180320();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_1883f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1883f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropDestroyTrack_188730 {
public:
    void FUN_00180580();
    void FUN_001805a0();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_188730 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_188730(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_188730 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_188730(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f5c5d2a1 {
struct RefCounted_188820 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00419608[];
class PropActorToPropAction_188820 {
  public:
    PropActorToPropAction_188820* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188820* m_20;
};
struct RefCounted_1888c0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00419624[];
class PropActorThinkingAction_1888c0 {
  public:
    PropActorThinkingAction_1888c0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1888c0* m_20;
};
extern int FUN_00344e74(int, int, const void*, const void*, int);
extern void* FUN_0008d690(int);
class AllocObj_188910 {
  public:
    int init_00183aa0(hulkfight::motion::PropAnimationTrack*, hulk_intptr);
};
class Ref_188960 {
  public:
    virtual void f0();
    virtual void f1();
};
class Action {
  public:
    virtual void f0();
    virtual void f1();
    virtual int f2(char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void baseCleanup_002326a0();
};
class PropAnimationAction : public Action {
  public:
    char pad[0x18];
    int m1c;
    Ref_188960* m20;
    Ref_188960* m24;
    Ref_188960* m28;
    virtual int f2(char);
};
extern char hulk_at_00419640[];
extern void thunk_0008d330(PropAnimationAction*);
struct RefCounted_188a10 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0041965c[];
class PropAddToMissileCountAction_188a10 {
  public:
    PropAddToMissileCountAction_188a10* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188a10* m_20;
};

} // namespace fn_f5c5d2a1

// 0x00187340 fight::TrackFactoryCasterTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_0 (36 B): matches/0x00187340.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VShieldArcTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
// the original asks whether a factory is the ShieldArcTrack one: dynamic_cast from fight::TrackFactory (RTTI 0x0049850c)
// to fight::TrackFactoryTemplate<hulkfight::motion::ShieldArcTrack> (0x004be460)
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return dynamic_cast<fight::TrackFactoryTemplate_187340<hulkfight::motion::ShieldArcTrack_187340>*>((fight::TrackFactory_187340*)p) != 0;
}


// 0x00187370 fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>::vfunc_0 (30 B): matches/0x00187370.cpp
// sym: ??_G?$ParamFloatConstRange@VShieldArcTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187370)
#endif


// 0x001873a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0 (36 B): matches/0x001873a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be510, 0) != 0;
}


// 0x001873d0 fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0 (30 B): matches/0x001873d0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1873d0)
#endif


// 0x001873f0 fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0 (30 B): matches/0x001873f0.cpp
// sym: ??_G?$ParamIntConstRange@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1873f0)
#endif


// 0x00187410 fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0 (30 B): matches/0x00187410.cpp
// sym: ??_G?$ParamBool@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187410)
#endif


// 0x00187440 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0 (36 B): matches/0x00187440.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_004be5c8, 0) != 0;
}


// 0x00187470 fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0 (30 B): matches/0x00187470.cpp
// sym: ??_G?$ParamFloatConstRange@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187470)
#endif


// 0x00187490 fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0 (30 B): matches/0x00187490.cpp
// sym: ??_G?$ParamIntConstRange@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187490)
#endif


// 0x001874c0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDamageTrack>::vfunc_0 (36 B): matches/0x001874c0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropDamageTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDamageTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be680, 0) != 0;
}


// 0x001874f0 fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>::vfunc_0 (30 B): matches/0x001874f0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1874f0)
#endif


// 0x00187510 fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>::vfunc_0 (30 B): matches/0x00187510.cpp
// sym: ??_G?$ParamIntConstRange@VPropDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187510)
#endif


// 0x00187540 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_0 (36 B): matches/0x00187540.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropSpawnTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be728, 0) != 0;
}


// 0x00187570 fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>::vfunc_0 (30 B): matches/0x00187570.cpp
// sym: ??_G?$ParamFloatConstRange@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187570)
#endif


// 0x00187590 fight::ParamString<hulkfight::motion::PropSpawnTrack>::vfunc_0 (30 B): matches/0x00187590.cpp
// sym: ??_G?$ParamString@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::motion::PropSpawnTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::motion::PropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187590)
#endif


// 0x001875b0 fight::ParamVector<hulkfight::motion::PropSpawnTrack>::vfunc_0 (30 B): matches/0x001875b0.cpp
// sym: ??_G?$ParamVector@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::PropSpawnTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::PropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1875b0)
#endif


// 0x001875e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_0 (36 B): matches/0x001875e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropDestroyTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be7d0, 0) != 0;
}


// 0x00187610 fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_0 (30 B): matches/0x00187610.cpp
// sym: ??_G?$ParamFloatConstRange@VPropDestroyTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187610)
#endif


// 0x00187630 fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_0 (30 B): matches/0x00187630.cpp
// sym: ??_G?$ParamIntConstRange@VPropDestroyTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x187630)
#endif

namespace fn_f5c5d2a1 {

// 0x00187650 FUN_00187650 (158 B): equivalent/0x00187650.cpp
// sym: _FUN_00187650 @4d2982084af0 @wa07555ad0193
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00187650 @ 0x00187650
extern "C" void FUN_00187650()
{
    if (DAT_004e1404 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_187650<hulkfight::motion::PropMissionCriticalCondition_187650>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange_187650<hulkfight::motion::PropMissionCriticalCondition_187650>("attachmentIndex", &hulkfight::motion::PropMissionCriticalCondition_187650::FUN_0017f2b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_187650<hulkfight::motion::PropMissionCriticalCondition_187650>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_187650<hulkfight::motion::PropMissionCriticalCondition_187650>("missionCritical", &hulkfight::motion::PropMissionCriticalCondition_187650::FUN_0017f2d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1400), params, 2);
    }
    DAT_004e1404++;
}


// 0x001876f0 FUN_001876f0 (618 B): equivalent/0x001876f0.cpp
// sym: _FUN_001876f0 @7012b95dbced @w2bc19091f107
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 22/22)
// FUN_001876f0 @ 0x001876f0
extern "C" void FUN_001876f0()
{
    if (DAT_004e140c == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchObjectClass", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f2f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("objectClass", ((const char**)&DAT_004c5fd0), 23, &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f310);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchCargo", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f330);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("isCargo", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f350);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchWeaponType", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f370);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("weaponType", ((const char**)&DAT_004c6028), 7, &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f390);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchWeaponizableType", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f3b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("weaponizableType", ((const char**)&DAT_004c6028), 7, &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f3d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchHasEvent", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f3f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("event", ((const char**)&DAT_00496168), 16, &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f410);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1408), params, 10);
    }
    DAT_004e140c++;
}


// 0x00187960 FUN_00187960 (95 B): equivalent/0x00187960.cpp
// sym: _FUN_00187960 @6431a8eca4c1 @wb9a57d3ef3c5
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00187960 @ 0x00187960
extern "C" void FUN_00187960()
{
    if (DAT_004e141c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_187960<hulkfight::motion::PropGrabbableIsThrownCondition_187960>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_187960<hulkfight::motion::PropGrabbableIsThrownCondition_187960>("isThrown", &hulkfight::motion::PropGrabbableIsThrownCondition_187960::FUN_0017f470);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1418), params, 1);
    }
    DAT_004e141c++;
}


// 0x001879c0 FUN_001879c0 (95 B): equivalent/0x001879c0.cpp
// sym: _FUN_001879c0 @6d2435907b4e @w1619c000828d
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_001879c0 @ 0x001879c0
extern "C" void FUN_001879c0()
{
    if (DAT_004e142c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1879c0<hulkfight::motion::PropAtRestCondition_1879c0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_1879c0<hulkfight::motion::PropAtRestCondition_1879c0>("atRest", &hulkfight::motion::PropAtRestCondition_1879c0::FUN_0017f500);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1428), params, 1);
    }
    DAT_004e142c++;
}


// 0x00187a20 FUN_00187a20 (158 B): equivalent/0x00187a20.cpp
// sym: _FUN_00187a20 @f3d4d19b3886 @wa522c744e059
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00187a20 @ 0x00187a20
extern "C" void FUN_00187a20()
{
    if (DAT_004e1434 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_187a20<hulkfight::motion::PropIsAttachedCondition_187a20>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange_187a20<hulkfight::motion::PropIsAttachedCondition_187a20>("attachmentIndex", &hulkfight::motion::PropIsAttachedCondition_187a20::FUN_0017f520);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_187a20<hulkfight::motion::PropIsAttachedCondition_187a20>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_187a20<hulkfight::motion::PropIsAttachedCondition_187a20>("isAttached", &hulkfight::motion::PropIsAttachedCondition_187a20::FUN_0017f530);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1430), params, 2);
    }
    DAT_004e1434++;
}


// 0x00187ca0 FUN_00187ca0 (158 B): equivalent/0x00187ca0.cpp
// sym: _FUN_00187ca0 @eaf2ee4cb9d4 @wb3209d77993b
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00187ca0 @ 0x00187ca0
extern "C" void FUN_00187ca0()
{
    if (DAT_004e1454 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_187ca0<hulkfight::motion::PropCollidedWithWorldCondition_187ca0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange_187ca0<hulkfight::motion::PropCollidedWithWorldCondition_187ca0>("attachmentIndex", &hulkfight::motion::PropCollidedWithWorldCondition_187ca0::FUN_0017f660);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_187ca0<hulkfight::motion::PropCollidedWithWorldCondition_187ca0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_187ca0<hulkfight::motion::PropCollidedWithWorldCondition_187ca0>("collided", &hulkfight::motion::PropCollidedWithWorldCondition_187ca0::FUN_0017f670);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1450), params, 2);
    }
    DAT_004e1454++;
}

} // namespace fn_f5c5d2a1

// 0x00187d40 FUN_00187d40 (95 B): equivalent/0x00187d40.cpp [wrapped: conflict: fight::ParamIntConstRange; hulkfight::motion::SmartPropIsCargoCondition]
// sym: _FUN_00187d40 @5aa7faa257ed @wde561d51a648
namespace fn_00187d40 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00187d40 @ 0x00187d40


void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class SmartPropIsCargoCondition {
public:
    void FUN_0017f690();
};
}
}

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00187d40()
{
    if (DAT_004e145c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>("attachmentIndex", &hulkfight::motion::SmartPropIsCargoCondition::FUN_0017f690);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1458), params, 1);
    }
    DAT_004e145c++;
}
} // namespace fn_00187d40

namespace fn_f5c5d2a1 {

// 0x00187da0 FUN_00187da0 (95 B): equivalent/0x00187da0.cpp
// sym: _FUN_00187da0 @59dc01c82b0d @w180c43975c73
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00187da0 @ 0x00187da0
extern "C" void FUN_00187da0()
{
    if (DAT_004e1464 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_187da0<hulkfight::motion::CSMPropIsCharacterCondition_187da0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_187da0<hulkfight::motion::CSMPropIsCharacterCondition_187da0>("isCharacter", &hulkfight::motion::CSMPropIsCharacterCondition_187da0::FUN_0017f6a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1460), params, 1);
    }
    DAT_004e1464++;
}


// 0x00187f00 FUN_00187f00 (158 B): equivalent/0x00187f00.cpp
// sym: _FUN_00187f00 @e67bde918464 @w737842099be4
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00187f00 @ 0x00187f00
extern "C" void FUN_00187f00()
{
    if (DAT_004e147c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_187f00<hulkfight::motion::PropActorThinkingTrack_187f00>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_187f00<hulkfight::motion::PropActorThinkingTrack_187f00>("timeBegin", &hulkfight::motion::PropActorThinkingTrack_187f00::FUN_0017f760);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_187f00<hulkfight::motion::PropActorThinkingTrack_187f00>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_187f00<hulkfight::motion::PropActorThinkingTrack_187f00>("thinking", &hulkfight::motion::PropActorThinkingTrack_187f00::FUN_0017f780);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1478), params, 2);
    }
    DAT_004e147c++;
}


// 0x00187fa0 FUN_00187fa0 (158 B): equivalent/0x00187fa0.cpp
// sym: _FUN_00187fa0 @e3ede787ed25 @waae4ce83092d
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00187fa0 @ 0x00187fa0
extern "C" void FUN_00187fa0()
{
    if (DAT_004e1484 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_187fa0<hulkfight::motion::PropDropTrack_187fa0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_187fa0<hulkfight::motion::PropDropTrack_187fa0>("timeBegin", &hulkfight::motion::PropDropTrack_187fa0::FUN_0017f790);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_187fa0<hulkfight::motion::PropDropTrack_187fa0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange_187fa0<hulkfight::motion::PropDropTrack_187fa0>("attachmentIndex", &hulkfight::motion::PropDropTrack_187fa0::FUN_0017f7b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1480), params, 2);
    }
    DAT_004e1484++;
}


// 0x00188220 FUN_00188220 (460 B): equivalent/0x00188220.cpp
// sym: _FUN_00188220 @6d29f6a5f251 @w5a6ffca5b45f
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 18/18)
// FUN_00188220 @ 0x00188220
extern "C" void FUN_00188220()
{
    if (DAT_004e14bc == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>("timeBegin", &hulkfight::motion::BallAndChainSpinTrack_188220::FUN_001801c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>("timeEnd", &hulkfight::motion::BallAndChainSpinTrack_188220::FUN_001801d0);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>("attachmentIndex", &hulkfight::motion::BallAndChainSpinTrack_188220::FUN_001801f0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>("radius", &hulkfight::motion::BallAndChainSpinTrack_188220::FUN_00180210);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>("height", &hulkfight::motion::BallAndChainSpinTrack_188220::FUN_00180230);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>("startAngle", &hulkfight::motion::BallAndChainSpinTrack_188220::FUN_00180250);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack_188220>("spinVelocity", &hulkfight::motion::BallAndChainSpinTrack_188220::FUN_00180280);
        mem = FUN_0008d690((int)sizeof(ParamVector<hulkfight::motion::BallAndChainSpinTrack_188220>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamVector<hulkfight::motion::BallAndChainSpinTrack_188220>("orient", &hulkfight::motion::BallAndChainSpinTrack_188220::FUN_001802c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14b8), params, 8);
    }
    DAT_004e14bc++;
}


// 0x001883f0 FUN_001883f0 (158 B): equivalent/0x001883f0.cpp
// sym: _FUN_001883f0 @b63594971701 @wab87470c91fe
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001883f0 @ 0x001883f0
extern "C" void FUN_001883f0()
{
    if (DAT_004e14c4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1883f0<hulkfight::motion::ShieldArcTrack_1883f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1883f0<hulkfight::motion::ShieldArcTrack_1883f0>("timeBegin", &hulkfight::motion::ShieldArcTrack_1883f0::FUN_00180300);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1883f0<hulkfight::motion::ShieldArcTrack_1883f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1883f0<hulkfight::motion::ShieldArcTrack_1883f0>("arc", &hulkfight::motion::ShieldArcTrack_1883f0::FUN_00180320);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14c0), params, 2);
    }
    DAT_004e14c4++;
}

} // namespace fn_f5c5d2a1

// 0x00188490 FUN_00188490 (213 B): equivalent/0x00188490.cpp [wrapped: conflict: FUN_0008d690; fight::ParamBool; fight::ParamFloatConstRange; fight::ParamIntConstRange]
// sym: _FUN_00188490 @b883fa3d2468 @w57d18a36ba70
namespace fn_00188490 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00188490 @ 0x00188490

void FUN_00180340();
void FUN_00180360();
void FUN_00180380();
namespace hulkfight { namespace motion { class PropAddToCollisionTrack; } }
struct FUN_0008d690 { static void* __cdecl operator new(size_t) HULK_NEW_THROW; };
struct FUN_00234960 : FUN_0008d690 {
 FUN_00234960(const char* = "timeBegin") throw();
 virtual void slot0();
 char data[12];
 void (*callback)();
 int tail;
};
struct FUN_002348e0 : FUN_0008d690 {
 FUN_002348e0(const char* = "attachmentIndex") throw();
 virtual void slot0();
 char data[12];
 void (*callback)();
 int tail;
};
struct FUN_00234860 : FUN_0008d690 {
 FUN_00234860(const char* = "addMissile") throw();
 virtual void slot0();
 char data[12];
 void (*callback)();
 int tail;
};
namespace fight {
 template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot0(); };
 template<class T> struct ParamIntConstRange : FUN_002348e0 { virtual void slot0(); };
 template<class T> struct ParamBool : FUN_00234860 { virtual void slot0(); };
}
void __cdecl FUN_002347b0(void*,void**,int);
extern "C" void __cdecl FUN_00188490() {
 if (!DAT_004e14cc) {
 void* params[3];
 fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>* a=new fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>;
 if(a) a->callback=FUN_00180340;
 params[0]=a;
 fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>* b=new fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>;
 if(b) b->callback=FUN_00180360;
 params[1]=b;
 fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>* c=new fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>;
 if(c) c->callback=FUN_00180380;
 params[2]=c;
 FUN_002347b0(&DAT_004e14c8,params,3);
 }
 ++DAT_004e14cc;
}
} // namespace fn_00188490

namespace fn_f5c5d2a1 {

// 0x00188730 FUN_00188730 (158 B): equivalent/0x00188730.cpp
// sym: _FUN_00188730 @ba4e62e125b6 @w461bc40d2823
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00188730 @ 0x00188730
extern "C" void FUN_00188730()
{
    if (DAT_004e14ec == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_188730<hulkfight::motion::PropDestroyTrack_188730>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_188730<hulkfight::motion::PropDestroyTrack_188730>("timeBegin", &hulkfight::motion::PropDestroyTrack_188730::FUN_00180580);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_188730<hulkfight::motion::PropDestroyTrack_188730>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange_188730<hulkfight::motion::PropDestroyTrack_188730>("attachmentIndex", &hulkfight::motion::PropDestroyTrack_188730::FUN_001805a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14e8), params, 2);
    }
    DAT_004e14ec++;
}


// 0x00188820 hulkfight::motion::PropActorToPropAction::vfunc_2 (71 B): matches/0x00188820.cpp
// sym: ?vfunc_2@PropActorToPropAction_188820@fn_f5c5d2a1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropActorToPropAction_188820* PropActorToPropAction_188820::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00419608;
    RefCounted_188820* q = *(RefCounted_188820* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x001888c0 hulkfight::motion::PropActorThinkingAction::vfunc_2 (71 B): matches/0x001888c0.cpp
// sym: ?vfunc_2@PropActorThinkingAction_1888c0@fn_f5c5d2a1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropActorThinkingAction_1888c0* PropActorThinkingAction_1888c0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00419624;
    RefCounted_1888c0* q = *(RefCounted_1888c0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}

} // namespace fn_f5c5d2a1

// 0x00188910 hulkfight::motion::PropAnimationTrack::vfunc_10 (70 B): matches/0x00188910.cpp
// sym: ?vfunc_10@PropAnimationTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001134e0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropAnimationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (FUN_00344e74(c, 0, &RTTI_Type1, &RTTI_Type2, 0)) {
        AllocObj_188910* p = (AllocObj_188910*)FUN_0008d690(0x2c);
        if (p)
            return p->init_00183aa0(this, c);
    }
    return 0;
}

namespace fn_f5c5d2a1 {

// 0x00188960 hulkfight::motion::PropAnimationAction::vfunc_2 (95 B): matches/0x00188960.cpp
// sym: ?f2@PropAnimationAction@fn_f5c5d2a1@@UAEHD@Z
int PropAnimationAction::f2(char param) {
    *(void**)this = (void*)hulk_at_00419640;
    _ReadWriteBarrier();
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    this->Action::baseCleanup_002326a0();
    if (param & 1)
        thunk_0008d330(this);
    return (hulk_intptr)this;
}


// 0x00188a10 hulkfight::motion::PropAddToMissileCountAction::vfunc_2 (71 B): matches/0x00188a10.cpp
// sym: ?vfunc_2@PropAddToMissileCountAction_188a10@fn_f5c5d2a1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropAddToMissileCountAction_188a10* PropAddToMissileCountAction_188a10::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0041965c;
    RefCounted_188a10* q = *(RefCounted_188a10* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}

} // namespace fn_f5c5d2a1
