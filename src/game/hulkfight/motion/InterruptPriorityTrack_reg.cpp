// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00154c00..0x00156e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_ff72ca8e {
#define TREE_TU_END }
namespace fn_ff72ca8e {} using namespace fn_ff72ca8e;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_154c00 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class InterruptPriorityTrack_154c00 {};
} }
namespace fn_ff72ca8e {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b30e0;
} // namespace fn_ff72ca8e
namespace fight {
class TrackFactoryCaster_154d00 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitFloatTrack_154d00 {};
} }
namespace fn_ff72ca8e {
extern char DAT_004b3248;
} // namespace fn_ff72ca8e
namespace fight {
class TrackFactoryCaster_154da0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class ClearFightParamsHitRecordTrack_154da0 {};
} }
namespace fn_ff72ca8e {
extern char DAT_004b3300;
extern char DAT_004b33c0;
} // namespace fn_ff72ca8e
namespace fight {
class TrackFactoryCaster_154e00 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitPushbackAddTrack_154e00 {};
} }
namespace fn_ff72ca8e {
extern char DAT_004b3470;
} // namespace fn_ff72ca8e
namespace fight {
class TrackFactoryCaster_154e60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class TrackFactoryCaster_154ee0 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitDamageTrack_154ee0 {};
} }
namespace fn_ff72ca8e {
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_004b3518;
extern int hulk_at_0049850c;
extern int hulk_at_004b35c0;
} // namespace fn_ff72ca8e
namespace fight {
class TrackFactoryCaster_154f40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_ff72ca8e {
extern char DAT_004b3710;
} // namespace fn_ff72ca8e
namespace fight {
class TrackFactoryCaster_155060 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class NoHitPushbackTrack_155060 {};
} }
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_ff72ca8e {
void* FUN_0008d690(unsigned int size);
} // namespace fn_ff72ca8e
namespace hulkfight { namespace motion {
class InterruptAccumulatorCondition_1550b0 {
public:
    bool FUN_0014c470(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c480(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_ff72ca8e {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_ff72ca8e
namespace fight {
template <class T>
class ParamEnumConstList_1550b0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1550b0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_1550b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1550b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff72ca8e {
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_ff72ca8e
namespace hulkfight { namespace motion {
class CollisionSourceForceMagnitudeCondition_155160 {
public:
    char FUN_0014c490(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c4b0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_155160 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_155160(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_155160 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_155160(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CollisionThrowCondition_155210 {
public:
    bool FUN_0014c4c0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fn_ff72ca8e {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_ff72ca8e
namespace fight {
template <class T>
class ParamBool_155210 : public ParamBoolBase {
public:
    ParamBool_155210(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CollisionDevastatorCondition_1554a0 {
public:
    char FUN_0014c540(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_1554a0 : public ParamBoolBase {
public:
    ParamBool_1554a0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CollisionTargetIsTargetCondition_155560 {
public:
    char FUN_0014c570(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_155560 : public ParamBoolBase {
public:
    ParamBool_155560(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CollisionSourceIsMissileCondition_155680 {
public:
    char FUN_0014c5a0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_155680 : public ParamBoolBase {
public:
    ParamBool_155680(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class HitPushbackVelocityCondition_1556e0 {
public:
    char FUN_0014c5b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c5d0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_1556e0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1556e0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_1556e0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1556e0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CollisionExplosionCondition_155790 {
public:
    char FUN_0014c600(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_155790 : public ParamBoolBase {
public:
    ParamBool_155790(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff72ca8e {
extern "C" void __cdecl FUN_0014c730();
extern "C" char DAT_00414ad0[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Param {
  public:
    void Init_00234cc0(const char*);
    char pad[0x20];
};
extern "C" void __cdecl Register_002347b0(void*, void**, int);
} // namespace fn_ff72ca8e
namespace hulkfight { namespace motion {
class InterruptAccumulatorSetTrack_155c30 {
public:
    bool FUN_0014c760(int); /* (unb4) as defined; address taken only */
    char FUN_0014c780(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_155c30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_155c30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff72ca8e {
class HitThrowTrack {
public:
    bool FUN_0014c790(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c7a0(int); /* (unb4) as defined; address taken only */
    char FUN_0014c7c0(char); /* (unb4) as defined; address taken only */
    char FUN_0014c7e0(float); /* (unb4) as defined; address taken only */
    char FUN_0014c810(int); /* (unb4) as defined; address taken only */
    char FUN_0014c830(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c850(int); /* (unb4) as defined; address taken only */
    char FUN_0014c870(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
} // namespace fn_ff72ca8e
namespace hulkfight { namespace motion {
class HitWaitTrack_155f80 {
public:
    char FUN_0014ccb0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014ccd0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_155f80 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_155f80(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_155f80 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_155f80(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff72ca8e {
class HitOrientToPushbackTrack {
public:
    char FUN_0014cd20(int); /* (unb4) as defined; address taken only */
    char FUN_0014cd30(int); /* (unb4) as defined; address taken only */
    bool FUN_0014cd50(float); /* (unb4) as defined; address taken only */
    bool FUN_0014cd80(int); /* (unb4) as defined; address taken only */
    char FUN_0014cda0(int); /* (unb4) as defined; address taken only */
    char FUN_0014cdc0(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_ff72ca8e
namespace hulkfight { namespace motion {
class HitFloatTrack_156280 {
public:
    char FUN_0014cdd0(int); /* (unb4) as defined; address taken only */
    char FUN_0014cde0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014ce00(char); /* (unb4) as defined; address taken only */
    bool FUN_0014ce20(float); /* (unb4) as defined; address taken only */
    char FUN_0014ce50(int); /* (unb4) as defined; address taken only */
    bool FUN_0014ce70(int); /* (unb4) as defined; address taken only */
    char FUN_0014ce90(int); /* (unb4) as defined; address taken only */
};
} }
namespace hulkfight { namespace motion {
class ClearFightParamsHitRecordTrack_156420 {
public:
    bool FUN_0014cea0(void*); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_156420 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156420(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class HitPushbackAddTrack_156480 {
public:
    bool FUN_0014ceb0(void*); /* (unb4) as defined; address taken only */
    char FUN_0014ced0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_156480 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156480(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff72ca8e {
class HealthTrack {
public:
    char FUN_0014cee0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014cf00(int); /* (unb4) as defined; address taken only */
    char FUN_0014cf20(char); /* (unb4) as defined; address taken only */
    char FUN_0014cf40(char); /* (unb4) as defined; address taken only */
    char FUN_0014cf60(char); /* (unb4) as defined; address taken only */
};
} // namespace fn_ff72ca8e
namespace hulkfight { namespace motion {
class HitDamageTrack_156660 {
public:
    char FUN_0014cf70(int); /* (unb4) as defined; address taken only */
    bool FUN_0014cf90(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_156660 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156660(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff72ca8e {
class GroundSlideTrack {
public:
    char FUN_0014cfa0(int); /* (unb4) as defined; address taken only */
    char FUN_0014cfb0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014cfd0(float); /* (unb4) as defined; address taken only */
    char FUN_0014d000(int); /* (unb4) as defined; address taken only */
    bool FUN_0014d020(int); /* (unb4) as defined; address taken only */
    char FUN_0014d040(int); /* (unb4) as defined; address taken only */
    bool FUN_0014d060(int); /* (unb4) as defined; address taken only */
    bool FUN_0014d080(int); /* (unb4) as defined; address taken only */
    bool FUN_0014d0a0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014d0c0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014d0e0(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_ff72ca8e
namespace fight {
template <class T>
class ParamFloatConstRange_156700 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156700(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_156700 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_156700(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff72ca8e {
class HitPushbackTrack {
public:
    bool FUN_0014d0f0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014d100(int); /* (unb4) as defined; address taken only */
    bool FUN_0014d120(int); /* (unb4) as defined; address taken only */
    char FUN_0014d140(int); /* (unb4) as defined; address taken only */
    char FUN_0014d160(char); /* (unb4) as defined; address taken only */
    char FUN_0014d180(float); /* (unb4) as defined; address taken only */
    bool FUN_0014d1b0(float); /* (unb4) as defined; address taken only */
    bool FUN_0014d1e0(int); /* (unb4) as defined; address taken only */
    char FUN_0014d200(int); /* (unb4) as defined; address taken only */
    bool FUN_0014d220(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_ff72ca8e
namespace fight {
template <class T>
class ParamBool_156970 : public ParamBoolBase {
public:
    ParamBool_156970(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_156970 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156970(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_156970 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_156970(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class NoHitPushbackTrack_156bb0 {
public:
    char FUN_0014d230(int); /* (unb4) as defined; address taken only */
    char FUN_0014d240(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_156bb0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156bb0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff72ca8e {
struct RefCounted_156ca0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00414510[];
class InterruptAccumulatorSetAction_156ca0 {
  public:
    InterruptAccumulatorSetAction_156ca0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_156ca0* m_20;
};
struct RefCounted_156d40 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0041452c[];
class InterruptPriorityAction_156d40 {
  public:
    InterruptPriorityAction_156d40* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_156d40* m_20;
};
struct RefCounted_156de0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00414548[];
class HitWaitAction_156de0 {
  public:
    HitWaitAction_156de0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_156de0* m_20;
};
extern int FUN_00344e74(int, int, const void*, const void*, int);
extern void* FUN_0008d690(int);
class AllocObj_156e30 {
  public:
    int init_00151180(hulkfight::motion::GroundSlideTrack*, hulk_intptr);
};

} // namespace fn_ff72ca8e

// 0x00154c00 fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_0 (36 B): matches/0x00154c00.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b30e0, 0) != 0;
}


// 0x00154c30 fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_0 (30 B): matches/0x00154c30.cpp
// sym: ??_G?$ParamFloatConstRange@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154c30)
#endif


// 0x00154c50 fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_0 (30 B): matches/0x00154c50.cpp
// sym: ??_G?$ParamIntConstRange@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154c50)
#endif


// 0x00154c80 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_0 (36 B): matches/0x00154c80.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate; hulkfight::motion::HitOrientToPushbackTrack]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitOrientToPushbackTrack@motion@hulkfight@fn_00154c80@@@fight@fn_00154c80@@UAE_NPAX@Z
namespace fn_00154c80 {
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitOrientToPushbackTrack {};
} // namespace motion
} // namespace hulkfight
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_0049850c, DAT_004b3198;
template <class T> bool fight::TrackFactoryCasterTemplate<T>::vfunc_0(void* t) {
    return FUN_00344e74(t, 0, &DAT_0049850c, &DAT_004b3198, 0) != 0;
}
template bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_0(void*);
} // namespace fn_00154c80


// 0x00154cb0 fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_0 (30 B): matches/0x00154cb0.cpp
// sym: ??_G?$ParamFloatConstRange@VHitOrientToPushbackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154cb0)
#endif


// 0x00154cd0 fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_0 (30 B): matches/0x00154cd0.cpp
// sym: ??_G?$ParamIntConstRange@VHitOrientToPushbackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154cd0)
#endif


// 0x00154d00 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitFloatTrack>::vfunc_0 (36 B): matches/0x00154d00.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitFloatTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitFloatTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b3248, 0) != 0;
}


// 0x00154d30 fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>::vfunc_0 (30 B): matches/0x00154d30.cpp
// sym: ??_G?$ParamFloatConstRange@VHitFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154d30)
#endif


// 0x00154d50 fight::ParamBool<hulkfight::motion::HitFloatTrack>::vfunc_0 (30 B): matches/0x00154d50.cpp
// sym: ??_G?$ParamBool@VHitFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::HitFloatTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::HitFloatTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154d50)
#endif


// 0x00154d70 fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>::vfunc_0 (30 B): matches/0x00154d70.cpp
// sym: ??_G?$ParamIntConstRange@VHitFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154d70)
#endif


// 0x00154da0 fight::TrackFactoryCasterTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_0 (36 B): matches/0x00154da0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b3300, 0) != 0;
}


// 0x00154dd0 fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_0 (30 B): matches/0x00154dd0.cpp
// sym: ??_G?$ParamFloatConstRange@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154dd0)
#endif


// 0x00154e00 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackAddTrack>::vfunc_0 (36 B): matches/0x00154e00.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitPushbackAddTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackAddTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b33c0, 0) != 0;
}


// 0x00154e30 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>::vfunc_0 (30 B): matches/0x00154e30.cpp
// sym: ??_G?$ParamFloatConstRange@VHitPushbackAddTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154e30)
#endif


// 0x00154e60 fight::TrackFactoryCasterTemplate<hulkfight::motion::HealthTrack>::vfunc_0 (36 B): matches/0x00154e60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHealthTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HealthTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004b3470, 0)) != 0;
}


// 0x00154e90 fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>::vfunc_0 (30 B): matches/0x00154e90.cpp
// sym: ??_G?$ParamFloatConstRange@VHealthTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154e90)
#endif


// 0x00154eb0 fight::ParamBool<hulkfight::motion::HealthTrack>::vfunc_0 (30 B): matches/0x00154eb0.cpp
// sym: ??_G?$ParamBool@VHealthTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::HealthTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::HealthTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154eb0)
#endif


// 0x00154ee0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitDamageTrack>::vfunc_0 (36 B): matches/0x00154ee0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitDamageTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitDamageTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004b3518, 0) != 0;
}


// 0x00154f10 fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>::vfunc_0 (30 B): matches/0x00154f10.cpp
// sym: ??_G?$ParamFloatConstRange@VHitDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154f10)
#endif


// 0x00154f40 fight::TrackFactoryCasterTemplate<hulkfight::motion::GroundSlideTrack>::vfunc_0 (36 B): matches/0x00154f40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGroundSlideTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GroundSlideTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, (void*)(&hulk_at_0049850c), (void*)(&hulk_at_004b35c0), 0) != 0;
}


// 0x00154f70 fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_0 (30 B): matches/0x00154f70.cpp
// sym: ??_G?$ParamFloatConstRange@VGroundSlideTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154f70)
#endif


// 0x00154f90 fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_0 (30 B): matches/0x00154f90.cpp
// sym: ??_G?$ParamIntConstRange@VGroundSlideTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154f90)
#endif


// 0x00154fc0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_0 (36 B): matches/0x00154fc0.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate; hulkfight::motion::HitPushbackTrack]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitPushbackTrack@motion@hulkfight@fn_00154fc0@@@fight@fn_00154fc0@@UAE_NPAX@Z
namespace fn_00154fc0 {
extern char DAT_0049850c[];
extern char DAT_004b3668[];
extern "C++" __declspec(nothrow) void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitPushbackTrack {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, DAT_0049850c, DAT_004b3668, 0) != 0;
}
} // namespace fn_00154fc0


// 0x00154ff0 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_0 (30 B): matches/0x00154ff0.cpp
// sym: ??_G?$ParamFloatConstRange@VHitPushbackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x154ff0)
#endif


// 0x00155010 fight::ParamBool<hulkfight::motion::HitPushbackTrack>::vfunc_0 (30 B): matches/0x00155010.cpp
// sym: ??_G?$ParamBool@VHitPushbackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::HitPushbackTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::HitPushbackTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x155010)
#endif


// 0x00155030 fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_0 (30 B): matches/0x00155030.cpp
// sym: ??_G?$ParamIntConstRange@VHitPushbackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x155030)
#endif


// 0x00155060 fight::TrackFactoryCasterTemplate<hulkfight::motion::NoHitPushbackTrack>::vfunc_0 (36 B): matches/0x00155060.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VNoHitPushbackTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::NoHitPushbackTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b3710, 0) != 0;
}


// 0x00155090 fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>::vfunc_0 (30 B): matches/0x00155090.cpp
// sym: ??_G?$ParamFloatConstRange@VNoHitPushbackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x155090)
#endif

namespace fn_ff72ca8e {

// 0x001550b0 FUN_001550b0 (176 B): equivalent/0x001550b0.cpp
// sym: _FUN_001550b0 @8bc43043d391 @w84cdc963796f
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_001550b0 @ 0x001550b0
extern "C" void FUN_001550b0()
{
    if (DAT_004e102c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1550b0<hulkfight::motion::InterruptAccumulatorCondition_1550b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_1550b0<hulkfight::motion::InterruptAccumulatorCondition_1550b0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (hulkfight::motion::InterruptAccumulatorCondition_1550b0::*)())&hulkfight::motion::InterruptAccumulatorCondition_1550b0::FUN_0014c470);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1550b0<hulkfight::motion::InterruptAccumulatorCondition_1550b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1550b0<hulkfight::motion::InterruptAccumulatorCondition_1550b0>("percent", (void (hulkfight::motion::InterruptAccumulatorCondition_1550b0::*)())&hulkfight::motion::InterruptAccumulatorCondition_1550b0::FUN_0014c480);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1028), params, 2);
    }
    DAT_004e102c++;
}


// 0x00155160 FUN_00155160 (176 B): equivalent/0x00155160.cpp
// sym: _FUN_00155160 @ba8efcc297c8 @wcc9bda801523
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00155160 @ 0x00155160
extern "C" void FUN_00155160()
{
    if (DAT_004e1034 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_155160<hulkfight::motion::CollisionSourceForceMagnitudeCondition_155160>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_155160<hulkfight::motion::CollisionSourceForceMagnitudeCondition_155160>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (hulkfight::motion::CollisionSourceForceMagnitudeCondition_155160::*)())&hulkfight::motion::CollisionSourceForceMagnitudeCondition_155160::FUN_0014c490);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_155160<hulkfight::motion::CollisionSourceForceMagnitudeCondition_155160>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_155160<hulkfight::motion::CollisionSourceForceMagnitudeCondition_155160>("force", (void (hulkfight::motion::CollisionSourceForceMagnitudeCondition_155160::*)())&hulkfight::motion::CollisionSourceForceMagnitudeCondition_155160::FUN_0014c4b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1030), params, 2);
    }
    DAT_004e1034++;
}


// 0x00155210 FUN_00155210 (95 B): equivalent/0x00155210.cpp
// sym: _FUN_00155210 @3661897d1191 @wb5d68453cbe9
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00155210 @ 0x00155210
extern "C" void FUN_00155210()
{
    if (DAT_004e103c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_155210<hulkfight::motion::CollisionThrowCondition_155210>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_155210<hulkfight::motion::CollisionThrowCondition_155210>("throw", (void (hulkfight::motion::CollisionThrowCondition_155210::*)())&hulkfight::motion::CollisionThrowCondition_155210::FUN_0014c4c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1038), params, 1);
    }
    DAT_004e103c++;
}

} // namespace fn_ff72ca8e

// 0x001553f0 FUN_001553f0 (176 B): equivalent/0x001553f0.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamIntConstRange; hulkfight::motion::CollisionTargetPriorityCondition]
// sym: _FUN_001553f0 @9d90bee09bb2 @w0bc35e6e39d6
namespace fn_001553f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_001553f0 @ 0x001553f0


void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class CollisionTargetPriorityCondition {
public:
    bool FUN_0014c510(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c530(int); /* (unb4) as defined; address taken only */
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
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

extern "C" void FUN_001553f0()
{
    if (DAT_004e1054 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (hulkfight::motion::CollisionTargetPriorityCondition::*)())&hulkfight::motion::CollisionTargetPriorityCondition::FUN_0014c510);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>("targetPriority", (void (hulkfight::motion::CollisionTargetPriorityCondition::*)())&hulkfight::motion::CollisionTargetPriorityCondition::FUN_0014c530);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1050), params, 2);
    }
    DAT_004e1054++;
}
} // namespace fn_001553f0

namespace fn_ff72ca8e {

// 0x001554a0 FUN_001554a0 (95 B): equivalent/0x001554a0.cpp
// sym: _FUN_001554a0 @72199db0f57c @w21e527b4ed88
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_001554a0 @ 0x001554a0
extern "C" void FUN_001554a0()
{
    if (DAT_004e105c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1554a0<hulkfight::motion::CollisionDevastatorCondition_1554a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_1554a0<hulkfight::motion::CollisionDevastatorCondition_1554a0>("isDevastator", (void (hulkfight::motion::CollisionDevastatorCondition_1554a0::*)())&hulkfight::motion::CollisionDevastatorCondition_1554a0::FUN_0014c540);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1058), params, 1);
    }
    DAT_004e105c++;
}


// 0x00155560 FUN_00155560 (95 B): equivalent/0x00155560.cpp
// sym: _FUN_00155560 @7d33a6745868 @w5653ca5d165e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00155560 @ 0x00155560
extern "C" void FUN_00155560()
{
    if (DAT_004e106c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_155560<hulkfight::motion::CollisionTargetIsTargetCondition_155560>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_155560<hulkfight::motion::CollisionTargetIsTargetCondition_155560>("isTarget", (void (hulkfight::motion::CollisionTargetIsTargetCondition_155560::*)())&hulkfight::motion::CollisionTargetIsTargetCondition_155560::FUN_0014c570);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1068), params, 1);
    }
    DAT_004e106c++;
}


// 0x00155680 FUN_00155680 (95 B): equivalent/0x00155680.cpp
// sym: _FUN_00155680 @8b12dc1def7a @wf69b7a26abb0
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00155680 @ 0x00155680
extern "C" void FUN_00155680()
{
    if (DAT_004e107c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_155680<hulkfight::motion::CollisionSourceIsMissileCondition_155680>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_155680<hulkfight::motion::CollisionSourceIsMissileCondition_155680>("isMissile", (void (hulkfight::motion::CollisionSourceIsMissileCondition_155680::*)())&hulkfight::motion::CollisionSourceIsMissileCondition_155680::FUN_0014c5a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1078), params, 1);
    }
    DAT_004e107c++;
}


// 0x001556e0 FUN_001556e0 (176 B): equivalent/0x001556e0.cpp
// sym: _FUN_001556e0 @1fd2a1ba265c @w63ccebd2973b
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_001556e0 @ 0x001556e0
extern "C" void FUN_001556e0()
{
    if (DAT_004e1084 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1556e0<hulkfight::motion::HitPushbackVelocityCondition_1556e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_1556e0<hulkfight::motion::HitPushbackVelocityCondition_1556e0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (hulkfight::motion::HitPushbackVelocityCondition_1556e0::*)())&hulkfight::motion::HitPushbackVelocityCondition_1556e0::FUN_0014c5b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1556e0<hulkfight::motion::HitPushbackVelocityCondition_1556e0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1556e0<hulkfight::motion::HitPushbackVelocityCondition_1556e0>("velocity", (void (hulkfight::motion::HitPushbackVelocityCondition_1556e0::*)())&hulkfight::motion::HitPushbackVelocityCondition_1556e0::FUN_0014c5d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1080), params, 2);
    }
    DAT_004e1084++;
}


// 0x00155790 FUN_00155790 (95 B): equivalent/0x00155790.cpp
// sym: _FUN_00155790 @a6f1c53a33d1 @wdadb06b451d0
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_00155790 @ 0x00155790
extern "C" void FUN_00155790()
{
    if (DAT_004e1094 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_155790<hulkfight::motion::CollisionExplosionCondition_155790>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_155790<hulkfight::motion::CollisionExplosionCondition_155790>("explosion", (void (hulkfight::motion::CollisionExplosionCondition_155790::*)())&hulkfight::motion::CollisionExplosionCondition_155790::FUN_0014c600);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1090), params, 1);
    }
    DAT_004e1094++;
}


// 0x00155bb0 FUN_00155bb0 (113 B): matches/0x00155bb0.cpp
// sym: _FUN_00155bb0
// data: gCount_155bb0 = DAT_004e10c4, gSlot_155bb0 = DAT_004e10c0, gValue_155bb0 = DAT_00427754
extern "C" void FUN_00155bb0() {
    if ((*(int*)&DAT_004e10c4)) {
        ++(*(int*)&DAT_004e10c4);
        return;
    }
    void* tmp;
    Param* p = (Param*)Alloc(0x20);
    if (p) {
        int v = (*(int*)&DAT_00427754);
        p->Init_00234cc0("compare");
        *(int*)((char*)p + 0x14) = v;
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414ad0);
        *(hulk_intptr*)((char*)p + 0x10) = ((hulk_intptr)((char*)&DAT_0042773c));
        *(hulk_intptr*)((char*)p + 0x18) = ((hulk_intptr)(void (__cdecl*)())&FUN_0014c730);
        tmp = p;
    } else
        tmp = 0;
    Register_002347b0(((void**)&DAT_004e10c0), &tmp, 1);
    ++(*(int*)&DAT_004e10c4);
}


// 0x00155c30 FUN_00155c30 (158 B): equivalent/0x00155c30.cpp
// sym: _FUN_00155c30 @2356f4d4ef18 @w679380170fc0
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00155c30 @ 0x00155c30
extern "C" void FUN_00155c30()
{
    if (DAT_004e10d4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_155c30<hulkfight::motion::InterruptAccumulatorSetTrack_155c30>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_155c30<hulkfight::motion::InterruptAccumulatorSetTrack_155c30>("timeBegin", (void (hulkfight::motion::InterruptAccumulatorSetTrack_155c30::*)())&hulkfight::motion::InterruptAccumulatorSetTrack_155c30::FUN_0014c760);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_155c30<hulkfight::motion::InterruptAccumulatorSetTrack_155c30>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_155c30<hulkfight::motion::InterruptAccumulatorSetTrack_155c30>("value", (void (hulkfight::motion::InterruptAccumulatorSetTrack_155c30::*)())&hulkfight::motion::InterruptAccumulatorSetTrack_155c30::FUN_0014c780);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10d0), params, 2);
    }
    DAT_004e10d4++;
}


// 0x00155cd0 FUN_00155cd0 (460 B): equivalent/0x00155cd0.cpp
// sym: _FUN_00155cd0 @eb9052ab16a4 @w2e682ee5c681
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_00155cd0 @ 0x00155cd0
extern "C" void FUN_00155cd0()
{
    if (DAT_004e10dc == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitThrowTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<HitThrowTrack>("timeBegin", (void (HitThrowTrack::*)())&HitThrowTrack::FUN_0014c790);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitThrowTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<HitThrowTrack>("timeEnd", (void (HitThrowTrack::*)())&HitThrowTrack::FUN_0014c7a0);
        mem = FUN_0008d690((int)sizeof(ParamBool<HitThrowTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<HitThrowTrack>("snapToPushback", (void (HitThrowTrack::*)())&HitThrowTrack::FUN_0014c7c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitThrowTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<HitThrowTrack>("orientation", (void (HitThrowTrack::*)())&HitThrowTrack::FUN_0014c7e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitThrowTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<HitThrowTrack>("gravity", (void (HitThrowTrack::*)())&HitThrowTrack::FUN_0014c810);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<HitThrowTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamIntConstRange<HitThrowTrack>("priority", (void (HitThrowTrack::*)())&HitThrowTrack::FUN_0014c830);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitThrowTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<HitThrowTrack>("blendInTime", (void (HitThrowTrack::*)())&HitThrowTrack::FUN_0014c850);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitThrowTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<HitThrowTrack>("blendOutTime", (void (HitThrowTrack::*)())&HitThrowTrack::FUN_0014c870);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10d8), params, 8);
    }
    DAT_004e10dc++;
}


// 0x00155f80 FUN_00155f80 (172 B): equivalent/0x00155f80.cpp
// sym: _FUN_00155f80 @d6d01487165f @we71a96704441
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00155f80 @ 0x00155f80
extern "C" void FUN_00155f80()
{
    if (DAT_004e10fc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_155f80<hulkfight::motion::HitWaitTrack_155f80>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_155f80<hulkfight::motion::HitWaitTrack_155f80>("timeBegin", (void (hulkfight::motion::HitWaitTrack_155f80::*)())&hulkfight::motion::HitWaitTrack_155f80::FUN_0014ccb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_155f80<hulkfight::motion::HitWaitTrack_155f80>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_155f80<hulkfight::motion::HitWaitTrack_155f80>("wait", ((const char**)&DAT_004af9e4), 3, (void (hulkfight::motion::HitWaitTrack_155f80::*)())&hulkfight::motion::HitWaitTrack_155f80::FUN_0014ccd0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10f8), params, 2);
    }
    DAT_004e10fc++;
}


// 0x00156110 FUN_00156110 (358 B): equivalent/0x00156110.cpp
// sym: _FUN_00156110 @25fba8729d11 @w03163c011485
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_00156110 @ 0x00156110
extern "C" void FUN_00156110()
{
    if (DAT_004e110c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitOrientToPushbackTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("timeBegin", (void (HitOrientToPushbackTrack::*)())&HitOrientToPushbackTrack::FUN_0014cd20);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitOrientToPushbackTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("timeEnd", (void (HitOrientToPushbackTrack::*)())&HitOrientToPushbackTrack::FUN_0014cd30);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitOrientToPushbackTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("turningVelocity", (void (HitOrientToPushbackTrack::*)())&HitOrientToPushbackTrack::FUN_0014cd50);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<HitOrientToPushbackTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<HitOrientToPushbackTrack>("priority", (void (HitOrientToPushbackTrack::*)())&HitOrientToPushbackTrack::FUN_0014cd80);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitOrientToPushbackTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("blendInTime", (void (HitOrientToPushbackTrack::*)())&HitOrientToPushbackTrack::FUN_0014cda0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HitOrientToPushbackTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("blendOutTime", (void (HitOrientToPushbackTrack::*)())&HitOrientToPushbackTrack::FUN_0014cdc0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1108), params, 6);
    }
    DAT_004e110c++;
}


// 0x00156280 FUN_00156280 (409 B): equivalent/0x00156280.cpp
// sym: _FUN_00156280 @aa57aea330b0 @wb8835f80182d
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_00156280 @ 0x00156280
extern "C" void FUN_00156280()
{
    if (DAT_004e1114 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("timeBegin", (void (hulkfight::motion::HitFloatTrack_156280::*)())&hulkfight::motion::HitFloatTrack_156280::FUN_0014cdd0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("timeEnd", (void (hulkfight::motion::HitFloatTrack_156280::*)())&hulkfight::motion::HitFloatTrack_156280::FUN_0014cde0);
        mem = FUN_0008d690((int)sizeof(ParamBool<hulkfight::motion::HitFloatTrack_156280>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<hulkfight::motion::HitFloatTrack_156280>("snapToPushback", (void (hulkfight::motion::HitFloatTrack_156280::*)())&hulkfight::motion::HitFloatTrack_156280::FUN_0014ce00);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("orientation", (void (hulkfight::motion::HitFloatTrack_156280::*)())&hulkfight::motion::HitFloatTrack_156280::FUN_0014ce20);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamIntConstRange<hulkfight::motion::HitFloatTrack_156280>("priority", (void (hulkfight::motion::HitFloatTrack_156280::*)())&hulkfight::motion::HitFloatTrack_156280::FUN_0014ce50);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("blendInTime", (void (hulkfight::motion::HitFloatTrack_156280::*)())&hulkfight::motion::HitFloatTrack_156280::FUN_0014ce70);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("blendOutTime", (void (hulkfight::motion::HitFloatTrack_156280::*)())&hulkfight::motion::HitFloatTrack_156280::FUN_0014ce90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1110), params, 7);
    }
    DAT_004e1114++;
}


// 0x00156420 FUN_00156420 (95 B): equivalent/0x00156420.cpp
// sym: _FUN_00156420 @a74b3938b2fa @waace213e7b69
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00156420 @ 0x00156420
extern "C" void FUN_00156420()
{
    if (DAT_004e111c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156420<hulkfight::motion::ClearFightParamsHitRecordTrack_156420>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156420<hulkfight::motion::ClearFightParamsHitRecordTrack_156420>("timeBegin", (void (hulkfight::motion::ClearFightParamsHitRecordTrack_156420::*)())&hulkfight::motion::ClearFightParamsHitRecordTrack_156420::FUN_0014cea0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1118), params, 1);
    }
    DAT_004e111c++;
}


// 0x00156480 FUN_00156480 (158 B): equivalent/0x00156480.cpp
// sym: _FUN_00156480 @ab3ca3551739 @we0df02d42b15
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00156480 @ 0x00156480
extern "C" void FUN_00156480()
{
    if (DAT_004e1124 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156480<hulkfight::motion::HitPushbackAddTrack_156480>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156480<hulkfight::motion::HitPushbackAddTrack_156480>("timeBegin", (void (hulkfight::motion::HitPushbackAddTrack_156480::*)())&hulkfight::motion::HitPushbackAddTrack_156480::FUN_0014ceb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156480<hulkfight::motion::HitPushbackAddTrack_156480>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_156480<hulkfight::motion::HitPushbackAddTrack_156480>("weight", (void (hulkfight::motion::HitPushbackAddTrack_156480::*)())&hulkfight::motion::HitPushbackAddTrack_156480::FUN_0014ced0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1120), params, 2);
    }
    DAT_004e1124++;
}


// 0x00156520 FUN_00156520 (307 B): equivalent/0x00156520.cpp
// sym: _FUN_00156520 @f19e6fc8a38f @w888ba7d01534
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00156520 @ 0x00156520
extern "C" void FUN_00156520()
{
    if (DAT_004e112c == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HealthTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<HealthTrack>("timeBegin", (void (HealthTrack::*)())&HealthTrack::FUN_0014cee0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HealthTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<HealthTrack>("hitPoints", (void (HealthTrack::*)())&HealthTrack::FUN_0014cf00);
        mem = FUN_0008d690((int)sizeof(ParamBool<HealthTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<HealthTrack>("directDamage", (void (HealthTrack::*)())&HealthTrack::FUN_0014cf20);
        mem = FUN_0008d690((int)sizeof(ParamBool<HealthTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<HealthTrack>("addTheseHitPoints", (void (HealthTrack::*)())&HealthTrack::FUN_0014cf40);
        mem = FUN_0008d690((int)sizeof(ParamBool<HealthTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<HealthTrack>("subtractTheseHitPoints", (void (HealthTrack::*)())&HealthTrack::FUN_0014cf60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1128), params, 5);
    }
    DAT_004e112c++;
}


// 0x00156660 FUN_00156660 (158 B): equivalent/0x00156660.cpp
// sym: _FUN_00156660 @1f084d2eeb95 @wfe1452c8bef5
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00156660 @ 0x00156660
extern "C" void FUN_00156660()
{
    if (DAT_004e1134 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156660<hulkfight::motion::HitDamageTrack_156660>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156660<hulkfight::motion::HitDamageTrack_156660>("timeBegin", (void (hulkfight::motion::HitDamageTrack_156660::*)())&hulkfight::motion::HitDamageTrack_156660::FUN_0014cf70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156660<hulkfight::motion::HitDamageTrack_156660>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_156660<hulkfight::motion::HitDamageTrack_156660>("weight", (void (hulkfight::motion::HitDamageTrack_156660::*)())&hulkfight::motion::HitDamageTrack_156660::FUN_0014cf90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1130), params, 2);
    }
    DAT_004e1134++;
}


// 0x00156700 FUN_00156700 (613 B): equivalent/0x00156700.cpp
// sym: _FUN_00156700 @7373d81b0235 @w500d41c423b0
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 24/24)
// FUN_00156700 @ 0x00156700
extern "C" void FUN_00156700()
{
    if (DAT_004e113c == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("timeBegin", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014cfa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("timeEnd", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014cfb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("facing", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014cfd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("friction", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014d000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("deceleration", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014d020);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("minInitVelocity", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014d040);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("minVelocity", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014d060);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("maxVelocity", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014d080);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_156700<GroundSlideTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_156700<GroundSlideTrack>("priority", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014d0a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("blendInTime", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014d0c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156700<GroundSlideTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_156700<GroundSlideTrack>("blendOutTime", (void (GroundSlideTrack::*)())&GroundSlideTrack::FUN_0014d0e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1138), params, 11);
    }
    DAT_004e113c++;
}


// 0x00156970 FUN_00156970 (562 B): equivalent/0x00156970.cpp
// sym: _FUN_00156970 @16a4b7c46034 @w17f073822b29
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 22/22)
// FUN_00156970 @ 0x00156970
extern "C" void FUN_00156970()
{
    if (DAT_004e1144 == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("timeBegin", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d0f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("timeEnd", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d100);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("weight", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d120);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("maxDistance", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d140);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_156970<HitPushbackTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_156970<HitPushbackTrack>("snapToPushback", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d160);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("orientation", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d180);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("proneSpin", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d1b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_156970<HitPushbackTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_156970<HitPushbackTrack>("priority", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d1e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("blendInTime", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d200);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("blendOutTime", (void (HitPushbackTrack::*)())&HitPushbackTrack::FUN_0014d220);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1140), params, 10);
    }
    DAT_004e1144++;
}


// 0x00156bb0 FUN_00156bb0 (158 B): equivalent/0x00156bb0.cpp
// sym: _FUN_00156bb0 @c8d597476cba @w3d9673ae1609
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00156bb0 @ 0x00156bb0
extern "C" void FUN_00156bb0()
{
    if (DAT_004e114c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156bb0<hulkfight::motion::NoHitPushbackTrack_156bb0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156bb0<hulkfight::motion::NoHitPushbackTrack_156bb0>("timeBegin", (void (hulkfight::motion::NoHitPushbackTrack_156bb0::*)())&hulkfight::motion::NoHitPushbackTrack_156bb0::FUN_0014d230);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156bb0<hulkfight::motion::NoHitPushbackTrack_156bb0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_156bb0<hulkfight::motion::NoHitPushbackTrack_156bb0>("timeEnd", (void (hulkfight::motion::NoHitPushbackTrack_156bb0::*)())&hulkfight::motion::NoHitPushbackTrack_156bb0::FUN_0014d240);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1148), params, 2);
    }
    DAT_004e114c++;
}


// 0x00156ca0 hulkfight::motion::InterruptAccumulatorSetAction::vfunc_2 (71 B): matches/0x00156ca0.cpp
// sym: ?vfunc_2@InterruptAccumulatorSetAction_156ca0@fn_ff72ca8e@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
InterruptAccumulatorSetAction_156ca0* InterruptAccumulatorSetAction_156ca0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00414510;
    RefCounted_156ca0* q = *(RefCounted_156ca0* volatile*)&m_20;
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


// 0x00156d40 hulkfight::motion::InterruptPriorityAction::vfunc_2 (71 B): matches/0x00156d40.cpp
// sym: ?vfunc_2@InterruptPriorityAction_156d40@fn_ff72ca8e@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
InterruptPriorityAction_156d40* InterruptPriorityAction_156d40::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0041452c;
    RefCounted_156d40* q = *(RefCounted_156d40* volatile*)&m_20;
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


// 0x00156de0 hulkfight::motion::HitWaitAction::vfunc_2 (71 B): matches/0x00156de0.cpp
// sym: ?vfunc_2@HitWaitAction_156de0@fn_ff72ca8e@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
HitWaitAction_156de0* HitWaitAction_156de0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00414548;
    RefCounted_156de0* q = *(RefCounted_156de0* volatile*)&m_20;
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

} // namespace fn_ff72ca8e

// 0x00156e30 hulkfight::motion::GroundSlideTrack::vfunc_10 (70 B): matches/0x00156e30.cpp
// sym: ?vfunc_10@GroundSlideTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001134e0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GroundSlideTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (FUN_00344e74(c, 0, &RTTI_Type1, &RTTI_Type2, 0)) {
        AllocObj_156e30* p = (AllocObj_156e30*)FUN_0008d690(0x2c);
        if (p)
            return p->init_00151180(this, c);
    }
    return 0;
}

