// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00158f00 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/InterruptAccumulatorCondition.cpp
// piece 0x00154c00..0x00156e80 (kind game, layer game, confidence high, dominant class hulkfight::motion::InterruptPriorityTrack); was game/hulkfight/motion/InterruptPriorityTrack_reg.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/game/global.h"   // (gx3, D18) for the merged registrations
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "decls/data/engine/fight.h"   // (gx3, D32) its owner object's data, merged
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_ff72ca8e {
#define TREE_TU_END }
namespace fn_ff72ca8e {} using namespace fn_ff72ca8e;
#include "game/hulkfight/motion.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f2fc69c6 { struct A_14c620 { void * GetBranch_0014c620(); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct A_14c680 { char SetUseArmorValue_0014c680(char); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct A_14c700 { unsigned char SetCompareVsHealthPercent_0014c700(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct A_14cd10 { bool SetInterruptPriority_0014cd10(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct C_14c730 { unsigned char f(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct D { bool SetCompare_0014c580(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct O_14cce0 { char SetTimeBegin_0014cce0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c490 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c4f0 { bool SetCompare_0014c4f0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c500 { char SetType_0014c500(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c590 { bool SetSize_0014c590(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c610 { unsigned char SetCompare_0014c610(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c640 { bool SetCompare_0014c640(unsigned int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c6b0 { bool SetCompare_0014c6b0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c6e0 { char SetPercent_0014c6e0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c710 { char SetCompare_0014c710(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14c720 { bool SetType_0014c720(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14caa0 { bool SetTimeBegin_0014caa0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct Obj_14cac0 { bool SetPauseTime_0014cac0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct T_14ccf0 { char SetTimeEnd_0014ccf0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct X_14c4d0 { char SetCompare_0014c4d0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct X_14c4e0 { bool SetSize_0014c4e0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct X_14c550 { unsigned char Fn(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct X_14c630 { unsigned char SetCheckAncestors_0014c630(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct X_14c660 { char SetCharge_0014c660(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct X_14c6d0 { char SetDamage_0014c6d0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
namespace fn_f2fc69c6 { struct X_14cae0 { char SetBlendOutTime_0014cae0(int); }; }   // (gx3, D18) setters, as defined in unk_14c470.cpp
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

// 0x00153fb0 fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_0 (30 B): matches/0x00153fb0.cpp
// sym: ??_G?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from InterruptAccumulatorCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00153fd0 fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_0 (30 B): matches/0x00153fd0.cpp
// sym: ??_G?$ParamFloatConstRange@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from InterruptAccumulatorCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154030 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_0 (30 B): matches/0x00154030.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceForceMagnitudeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionSourceForceMagnitudeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154050 fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_0 (30 B): matches/0x00154050.cpp
// sym: ??_G?$ParamFloatConstRange@VCollisionSourceForceMagnitudeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionSourceForceMagnitudeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x001540b0 fight::ParamBool<hulkfight::motion::CollisionThrowCondition>::vfunc_0 (30 B): matches/0x001540b0.cpp
// sym: ??_G?$ParamBool@VCollisionThrowCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionTargetPriorityCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154110 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_0 (30 B): matches/0x00154110.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionTargetPriorityCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154170 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_0 (30 B): matches/0x00154170.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceTypeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionTargetPriorityCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x001541d0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_0 (30 B): matches/0x001541d0.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionTargetPriorityCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x001541f0 fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_0 (30 B): matches/0x001541f0.cpp
// sym: ??_G?$ParamIntConstRange@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionTargetPriorityCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154250 fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::vfunc_0 (30 B): matches/0x00154250.cpp
// sym: ??_G?$ParamBool@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionDevastatorCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x001542b0 fight::ParamBool<hulkfight::motion::HitPushbackCondition>::vfunc_0 (30 B): matches/0x001542b0.cpp
// sym: ??_G?$ParamBool@VHitPushbackCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionDevastatorCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154310 fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_0 (30 B): matches/0x00154310.cpp
// sym: ??_G?$ParamBool@VCollisionTargetIsTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionDevastatorCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154370 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_0 (30 B): matches/0x00154370.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionTargetSizeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionDevastatorCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x001543d0 fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_0 (30 B): matches/0x001543d0.cpp
// sym: ??_G?$ParamBool@VCollisionSourceIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionDevastatorCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154430 fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_0 (30 B): matches/0x00154430.cpp
// sym: ??_G?$ParamEnumConstList@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitPushbackVelocityCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154450 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_0 (30 B): matches/0x00154450.cpp
// sym: ??_G?$ParamFloatConstRange@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitPushbackVelocityCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154510 fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>::vfunc_0 (30 B): matches/0x00154510.cpp
// sym: ??_G?$ParamBool@VCollisionExplosionCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionSourceNodeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154570 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_0 (30 B): matches/0x00154570.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionSourceNodeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154590 fight::ParamBranch<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_0 (30 B): matches/0x00154590.cpp
// sym: ??_G?$ParamBranch@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionSourceNodeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x001545b0 fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_0 (30 B): matches/0x001545b0.cpp
// sym: ??_G?$ParamBool@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionSourceNodeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154610 fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_0 (30 B): matches/0x00154610.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionChargeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154630 fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::vfunc_0 (30 B): matches/0x00154630.cpp
// sym: ??_G?$ParamFloatConstRange@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionChargeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154650 fight::ParamBool<hulkfight::motion::CollisionChargeCondition>::vfunc_0 (30 B): matches/0x00154650.cpp
// sym: ??_G?$ParamBool@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionChargeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154710 fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_0 (30 B): matches/0x00154710.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionDamageHealthCompareCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154730 fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_0 (30 B): matches/0x00154730.cpp
// sym: ??_G?$ParamFloatConstRange@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionDamageHealthCompareCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154750 fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_0 (30 B): matches/0x00154750.cpp
// sym: ??_G?$ParamBool@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionDamageHealthCompareCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x001547b0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_0 (30 B): matches/0x001547b0.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionTargetTypeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionTargetTypeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154810 fight::ParamEnumConstList<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_0 (30 B): matches/0x00154810.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionInterruptPriorityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionTargetTypeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x001548d0 fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_0 (30 B): matches/0x001548d0.cpp
// sym: ??_G?$ParamFloatConstRange@VInterruptAccumulatorSetTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionTargetTypeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154930 fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>::vfunc_0 (30 B): matches/0x00154930.cpp
// sym: ??_G?$ParamFloatConstRange@VHitThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitThrowTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154950 fight::ParamBool<hulkfight::motion::HitThrowTrack>::vfunc_0 (30 B): matches/0x00154950.cpp
// sym: ??_G?$ParamBool@VHitThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitThrowTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154970 fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::vfunc_0 (30 B): matches/0x00154970.cpp
// sym: ??_G?$ParamIntConstRange@VHitThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitThrowTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154a90 fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::vfunc_0 (30 B): matches/0x00154a90.cpp
// sym: ??_G?$ParamFloatConstRange@VHitPauseTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitReactionTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154bb0 fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>::vfunc_0 (30 B): matches/0x00154bb0.cpp
// sym: ??_G?$ParamFloatConstRange@VHitWaitTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitWaitTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154bd0 fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_0 (30 B): matches/0x00154bd0.cpp
// sym: ??_G?$ParamEnumConstList@VHitWaitTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitWaitTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001550b0 / FUN_00155160 / FUN_00155210 / FUN_00155270 / FUN_00155330 / FUN_001553f0 / FUN_001554a0 / FUN_00155500 / FUN_00155560 / FUN_001555c0 / FUN_00155680 / FUN_001556e0 / FUN_00155790 / FUN_001557f0 / FUN_001558e0 / FUN_001559d0 / FUN_00155af0 / FUN_00155bb0 / FUN_00155c30 / FUN_00155cd0 / FUN_00155ea0 / FUN_00155f80 / FUN_00156030 / FUN_00156110 / FUN_00156280 / FUN_00156420 / FUN_00156480 / FUN_00156520 / FUN_00156660 / FUN_00156700 / FUN_00156970 / FUN_00156bb0)



// 0x00154c00 fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_0 (36 B): matches/0x00154c00.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b30e0, 0) != 0;
}


// 0x00154c30 fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_0 (30 B): matches/0x00154c30.cpp
// sym: ??_G?$ParamFloatConstRange@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00154c50 fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_0 (30 B): matches/0x00154c50.cpp
// sym: ??_G?$ParamIntConstRange@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


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
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00154cd0 fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_0 (30 B): matches/0x00154cd0.cpp
// sym: ??_G?$ParamIntConstRange@VHitOrientToPushbackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00154d00 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitFloatTrack>::vfunc_0 (36 B): matches/0x00154d00.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitFloatTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitFloatTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b3248, 0) != 0;
}


// 0x00154d30 fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>::vfunc_0 (30 B): matches/0x00154d30.cpp
// sym: ??_G?$ParamFloatConstRange@VHitFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00154d50 fight::ParamBool<hulkfight::motion::HitFloatTrack>::vfunc_0 (30 B): matches/0x00154d50.cpp
// sym: ??_G?$ParamBool@VHitFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00154d70 fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>::vfunc_0 (30 B): matches/0x00154d70.cpp
// sym: ??_G?$ParamIntConstRange@VHitFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00154da0 fight::TrackFactoryCasterTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_0 (36 B): matches/0x00154da0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b3300, 0) != 0;
}


// 0x00154dd0 fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_0 (30 B): matches/0x00154dd0.cpp
// sym: ??_G?$ParamFloatConstRange@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


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
// (gx2, D18) implicit: the registration that constructs the class emits this


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
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00154eb0 fight::ParamBool<hulkfight::motion::HealthTrack>::vfunc_0 (30 B): matches/0x00154eb0.cpp
// sym: ??_G?$ParamBool@VHealthTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00154ee0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitDamageTrack>::vfunc_0 (36 B): matches/0x00154ee0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitDamageTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitDamageTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004b3518, 0) != 0;
}


// 0x00154f10 fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>::vfunc_0 (30 B): matches/0x00154f10.cpp
// sym: ??_G?$ParamFloatConstRange@VHitDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


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
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00154f90 fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_0 (30 B): matches/0x00154f90.cpp
// sym: ??_G?$ParamIntConstRange@VGroundSlideTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


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
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00155010 fight::ParamBool<hulkfight::motion::HitPushbackTrack>::vfunc_0 (30 B): matches/0x00155010.cpp
// sym: ??_G?$ParamBool@VHitPushbackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00155030 fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_0 (30 B): matches/0x00155030.cpp
// sym: ??_G?$ParamIntConstRange@VHitPushbackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


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
// (gx2, D18) implicit: the registration that constructs the class emits this

namespace fn_ff72ca8e {

} // namespace fn_ff72ca8e

namespace fn_ff72ca8e {

} // namespace fn_ff72ca8e

// 0x001550b0 FUN_001550b0 (176 B): matches/0x001550b0.cpp
// sym: _FUN_001550b0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>, ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001550b0()
{
    if (DAT_004e102c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::InterruptAccumulatorCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_14c470::FUN_0014c470);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::InterruptAccumulatorCondition>("percent", &owners::Obj_14c480::FUN_0014c480);
        FUN_002347b0(&DAT_004e1028, params, 2);
    }
    DAT_004e102c++;
}



// 0x00155160 FUN_00155160 (176 B): matches/0x00155160.cpp
// sym: _FUN_00155160
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>, ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155160()
{
    if (DAT_004e1034 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionSourceForceMagnitudeCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f2fc69c6::Obj_14c490::Set);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::CollisionSourceForceMagnitudeCondition>("force", &owners::Obj_14c4b0::FUN_0014c4b0);
        FUN_002347b0(&DAT_004e1030, params, 2);
    }
    DAT_004e1034++;
}



// 0x00155210 FUN_00155210 (95 B): matches/0x00155210.cpp
// sym: _FUN_00155210
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::CollisionThrowCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155210()
{
    if (DAT_004e103c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::CollisionThrowCondition>("throw", &owners::Obj_14c4c0::FUN_0014c4c0);
        FUN_002347b0(&DAT_004e1038, params, 1);
    }
    DAT_004e103c++;
}



// 0x00155270 FUN_00155270 (192 B): matches/0x00155270.cpp
// sym: _FUN_00155270
// (gx2, D18) from InterruptPriorityTrack_reg.new_plain.cpp; constructs the real ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155270()
{
    if (DAT_004e1044 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionSourceSizeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f2fc69c6::X_14c4d0::SetCompare_0014c4d0);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionSourceSizeCondition>("size", (void*)&DAT_0048f6b4, DAT_003f5eb4, &fn_f2fc69c6::X_14c4e0::SetSize_0014c4e0);
        FUN_002347b0(&DAT_004e1040, params, 2);
    }
    DAT_004e1044++;
}



// 0x00155330 FUN_00155330 (190 B): matches/0x00155330.cpp
// sym: _FUN_00155330
// (gx2, D18) from InterruptPriorityTrack_reg.new_plain.cpp; constructs the real ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155330()
{
    if (DAT_004e104c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionSourceTypeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f2fc69c6::Obj_14c4f0::SetCompare_0014c4f0);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionSourceTypeCondition>("type", (void*)&DAT_004af9f0, 2, &fn_f2fc69c6::Obj_14c500::SetType_0014c500);
        FUN_002347b0(&DAT_004e1048, params, 2);
    }
    DAT_004e104c++;
}



// 0x001553f0 FUN_001553f0 (176 B): matches/0x001553f0.cpp
// sym: _FUN_001553f0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>, ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001553f0()
{
    if (DAT_004e1054 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionTargetPriorityCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::X_14c510::FUN_0014c510);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::CollisionTargetPriorityCondition>("targetPriority", &owners::T_14c530::FUN_0014c530);
        FUN_002347b0(&DAT_004e1050, params, 2);
    }
    DAT_004e1054++;
}



// 0x001554a0 FUN_001554a0 (95 B): matches/0x001554a0.cpp
// sym: _FUN_001554a0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::CollisionDevastatorCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001554a0()
{
    if (DAT_004e105c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::CollisionDevastatorCondition>("isDevastator", &owners::Obj_14c540::FUN_0014c540);
        FUN_002347b0(&DAT_004e1058, params, 1);
    }
    DAT_004e105c++;
}



// 0x00155500 FUN_00155500 (95 B): matches/0x00155500.cpp
// sym: _FUN_00155500
// (gx2, D18) from InterruptPriorityTrack_reg.iso_00155500.cpp; constructs the real ParamBool<hulkfight::motion::HitPushbackCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155500()
{
    if ((*(int*)&DAT_004e1064) == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::HitPushbackCondition>("hasHitPushback", &fn_f2fc69c6::X_14c550::Fn);
        FUN_002347b0(&DAT_004e1060, params, 1);
    }
    (*(int*)&DAT_004e1064)++;
}



// 0x00155560 FUN_00155560 (95 B): matches/0x00155560.cpp
// sym: _FUN_00155560
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155560()
{
    if (DAT_004e106c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::CollisionTargetIsTargetCondition>("isTarget", &owners::X_14c570::FUN_0014c570);
        FUN_002347b0(&DAT_004e1068, params, 1);
    }
    DAT_004e106c++;
}



// 0x001555c0 FUN_001555c0 (192 B): matches/0x001555c0.cpp
// sym: _FUN_001555c0
// (gx2, D18) from InterruptPriorityTrack_reg.new_plain.cpp; constructs the real ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001555c0()
{
    if (DAT_004e1074 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionTargetSizeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f2fc69c6::D::SetCompare_0014c580);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionTargetSizeCondition>("size", (void*)&DAT_0048f6b4, DAT_003f5eb4, &fn_f2fc69c6::Obj_14c590::SetSize_0014c590);
        FUN_002347b0(&DAT_004e1070, params, 2);
    }
    DAT_004e1074++;
}



// 0x00155680 FUN_00155680 (95 B): matches/0x00155680.cpp
// sym: _FUN_00155680
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155680()
{
    if (DAT_004e107c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::CollisionSourceIsMissileCondition>("isMissile", &owners::Obj_14c5a0::FUN_0014c5a0);
        FUN_002347b0(&DAT_004e1078, params, 1);
    }
    DAT_004e107c++;
}



// 0x001556e0 FUN_001556e0 (176 B): matches/0x001556e0.cpp
// sym: _FUN_001556e0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>, ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001556e0()
{
    if (DAT_004e1084 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::HitPushbackVelocityCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_14c5b0::FUN_0014c5b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackVelocityCondition>("velocity", &owners::Obj_14c5d0::FUN_0014c5d0);
        FUN_002347b0(&DAT_004e1080, params, 2);
    }
    DAT_004e1084++;
}



// 0x00155790 FUN_00155790 (95 B): matches/0x00155790.cpp
// sym: _FUN_00155790
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::CollisionExplosionCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155790()
{
    if (DAT_004e1094 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::CollisionExplosionCondition>("explosion", &owners::Obj_14c600::FUN_0014c600);
        FUN_002347b0(&DAT_004e1090, params, 1);
    }
    DAT_004e1094++;
}



// 0x001557f0 FUN_001557f0 (231 B): matches/0x001557f0.cpp
// sym: ?FUN_001557f0@@YAXXZ
// (gx2, D18) from InterruptPriorityTrack_reg.new_plain.cpp; constructs the real ParamBool<hulkfight::motion::CollisionSourceNodeCondition>, ParamBranch<hulkfight::motion::CollisionSourceNodeCondition>, ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_001557f0()
{
    if ((*(int*)&DAT_004e109c) == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionSourceNodeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f2fc69c6::Obj_14c610::SetCompare_0014c610);
        params[1] = new ::fight::ParamBranch< ::hulkfight::motion::CollisionSourceNodeCondition>("branch", &fn_f2fc69c6::A_14c620::GetBranch_0014c620);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::CollisionSourceNodeCondition>("checkAncestors", &fn_f2fc69c6::X_14c630::SetCheckAncestors_0014c630);
        FUN_002347b0(&DAT_004e1098, params, 3);
    }
    (*(int*)&DAT_004e109c)++;
}



// 0x001558e0 FUN_001558e0 (231 B): matches/0x001558e0.cpp
// sym: ?FUN_001558e0@@YAXXZ
// (gx2, D18) from InterruptPriorityTrack_reg.new_plain.cpp; constructs the real ParamBool<hulkfight::motion::CollisionChargeCondition>, ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>, ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_001558e0()
{
    if ((*(int*)&DAT_004e10a4) == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionChargeCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f2fc69c6::Obj_14c640::SetCompare_0014c640);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::CollisionChargeCondition>("charge", &fn_f2fc69c6::X_14c660::SetCharge_0014c660);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::CollisionChargeCondition>("useArmorValue", &fn_f2fc69c6::A_14c680::SetUseArmorValue_0014c680);
        FUN_002347b0(&DAT_004e10a0, params, 3);
    }
    (*(int*)&DAT_004e10a4)++;
}



// 0x001559d0 FUN_001559d0 (274 B): matches/0x001559d0.cpp
// sym: _FUN_001559d0
// (gx2, D18) from InterruptPriorityTrack_reg.iso_001559d0.cpp; constructs the real ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>, ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>, ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001559d0()
{
    if (DAT_004e10b4 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionDamageHealthCompareCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f2fc69c6::Obj_14c6b0::SetCompare_0014c6b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::CollisionDamageHealthCompareCondition>("damage", &fn_f2fc69c6::X_14c6d0::SetDamage_0014c6d0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::CollisionDamageHealthCompareCondition>("percent", &fn_f2fc69c6::Obj_14c6e0::SetPercent_0014c6e0);
        params[3] = new ::fight::ParamBool< ::hulkfight::motion::CollisionDamageHealthCompareCondition>("compareVsHealthPercent", &fn_f2fc69c6::A_14c700::SetCompareVsHealthPercent_0014c700);
        FUN_002347b0(&DAT_004e10b0, params, 4);
    }
    DAT_004e10b4++;
}



// 0x00155af0 FUN_00155af0 (190 B): matches/0x00155af0.cpp
// sym: _FUN_00155af0
// (gx2, D18) from InterruptPriorityTrack_reg.iso_00155af0.cpp; constructs the real ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155af0()
{
    if (DAT_004e10bc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionTargetTypeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f2fc69c6::Obj_14c710::SetCompare_0014c710);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionTargetTypeCondition>("type", (void*)&DAT_004af9f0, 2, &fn_f2fc69c6::Obj_14c720::SetType_0014c720);
        FUN_002347b0(&DAT_004e10b8, params, 2);
    }
    DAT_004e10bc++;
}



// 0x00155bb0 FUN_00155bb0 (113 B): matches/0x00155bb0.cpp
// sym: _FUN_00155bb0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::CollisionInterruptPriorityCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155bb0()
{
    if ((*(int*)&DAT_004e10c4) == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionInterruptPriorityCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f2fc69c6::C_14c730::f);
        FUN_002347b0(&DAT_004e10c0, params, 1);
    }
    (*(int*)&DAT_004e10c4)++;
}



// 0x00155c30 FUN_00155c30 (158 B): matches/0x00155c30.cpp
// sym: _FUN_00155c30
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155c30()
{
    if (DAT_004e10d4 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::InterruptAccumulatorSetTrack>("timeBegin", &owners::A_14c760::FUN_0014c760);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::InterruptAccumulatorSetTrack>("value", &owners::Obj_14c780::FUN_0014c780);
        FUN_002347b0(&DAT_004e10d0, params, 2);
    }
    DAT_004e10d4++;
}



// 0x00155cd0 FUN_00155cd0 (460 B): matches/0x00155cd0.cpp
// sym: _FUN_00155cd0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::HitThrowTrack>, ParamFloatConstRange<hulkfight::motion::HitThrowTrack>, ParamIntConstRange<hulkfight::motion::HitThrowTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155cd0()
{
    if (DAT_004e10dc == 0) {
        ::fight::ParamValue* params[8];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitThrowTrack>("timeBegin", &owners::X_14c790::FUN_0014c790);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitThrowTrack>("timeEnd", &owners::X_14c7a0::FUN_0014c7a0);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::HitThrowTrack>("snapToPushback", &owners::X_14c7c0::FUN_0014c7c0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitThrowTrack>("orientation", &owners::C_14c7e0::FUN_0014c7e0);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitThrowTrack>("gravity", &owners::Obj_14c810::FUN_0014c810);
        params[5] = new ::fight::ParamIntConstRange< ::hulkfight::motion::HitThrowTrack>("priority", &owners::Obj_14c830::FUN_0014c830);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitThrowTrack>("blendInTime", &owners::Obj_14c850::FUN_0014c850);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitThrowTrack>("blendOutTime", &owners::Obj_14c870::FUN_0014c870);
        FUN_002347b0(&DAT_004e10d8, params, 8);
    }
    DAT_004e10dc++;
}



// 0x00155ea0 FUN_00155ea0 (213 B): matches/0x00155ea0.cpp
// sym: _FUN_00155ea0
// (gx2, D18) from InterruptPriorityTrack_reg.iso_00155ea0.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::HitPauseTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155ea0()
{
    if (DAT_004e10ec == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPauseTrack>("timeBegin", &fn_f2fc69c6::Obj_14caa0::SetTimeBegin_0014caa0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPauseTrack>("pauseTime", &fn_f2fc69c6::Obj_14cac0::SetPauseTime_0014cac0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPauseTrack>("blendOutTime", &fn_f2fc69c6::X_14cae0::SetBlendOutTime_0014cae0);
        FUN_002347b0(&DAT_004e10e8, params, 3);
    }
    DAT_004e10ec++;
}



// 0x00155f80 FUN_00155f80 (172 B): matches/0x00155f80.cpp
// sym: _FUN_00155f80
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::HitWaitTrack>, ParamFloatConstRange<hulkfight::motion::HitWaitTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00155f80()
{
    if (DAT_004e10fc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitWaitTrack>("timeBegin", &owners::X_14ccb0::FUN_0014ccb0);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::HitWaitTrack>("wait", (void*)&DAT_004af9e4, 3, &owners::Obj_14ccd0::FUN_0014ccd0);
        FUN_002347b0(&DAT_004e10f8, params, 2);
    }
    DAT_004e10fc++;
}



// 0x00156030 FUN_00156030 (213 B): matches/0x00156030.cpp
// sym: _FUN_00156030
// (gx2, D18) from InterruptPriorityTrack_reg.iso_00156030.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>, ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156030()
{
    if (DAT_004e1104 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::InterruptPriorityTrack>("timeBegin", &fn_f2fc69c6::O_14cce0::SetTimeBegin_0014cce0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::InterruptPriorityTrack>("timeEnd", &fn_f2fc69c6::T_14ccf0::SetTimeEnd_0014ccf0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::InterruptPriorityTrack>("interruptPriority", &fn_f2fc69c6::A_14cd10::SetInterruptPriority_0014cd10);
        FUN_002347b0(&DAT_004e1100, params, 3);
    }
    DAT_004e1104++;
}



// 0x00156110 FUN_00156110 (358 B): matches/0x00156110.cpp
// sym: _FUN_00156110
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>, ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156110()
{
    if (DAT_004e110c == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitOrientToPushbackTrack>("timeBegin", &owners::X_14cd20::FUN_0014cd20);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitOrientToPushbackTrack>("timeEnd", &owners::Target_14cd30::FUN_0014cd30);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitOrientToPushbackTrack>("turningVelocity", &owners::C_14cd50::FUN_0014cd50);
        params[3] = new ::fight::ParamIntConstRange< ::hulkfight::motion::HitOrientToPushbackTrack>("priority", &owners::X_14cd80::FUN_0014cd80);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitOrientToPushbackTrack>("blendInTime", &owners::Obj_14cda0::FUN_0014cda0);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitOrientToPushbackTrack>("blendOutTime", &owners::Obj_14cdc0::FUN_0014cdc0);
        FUN_002347b0(&DAT_004e1108, params, 6);
    }
    DAT_004e110c++;
}



// 0x00156280 FUN_00156280 (409 B): matches/0x00156280.cpp
// sym: _FUN_00156280
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::HitFloatTrack>, ParamFloatConstRange<hulkfight::motion::HitFloatTrack>, ParamIntConstRange<hulkfight::motion::HitFloatTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156280()
{
    if (DAT_004e1114 == 0) {
        ::fight::ParamValue* params[7];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitFloatTrack>("timeBegin", &owners::Obj_14cdd0::FUN_0014cdd0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitFloatTrack>("timeEnd", &owners::Obj_14cde0::FUN_0014cde0);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::HitFloatTrack>("snapToPushback", &owners::Obj_14ce00::FUN_0014ce00);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitFloatTrack>("orientation", &owners::C_14ce20::FUN_0014ce20);
        params[4] = new ::fight::ParamIntConstRange< ::hulkfight::motion::HitFloatTrack>("priority", &owners::Obj_14ce50::FUN_0014ce50);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitFloatTrack>("blendInTime", &owners::T_14ce70::FUN_0014ce70);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitFloatTrack>("blendOutTime", &owners::Obj_14ce90::FUN_0014ce90);
        FUN_002347b0(&DAT_004e1110, params, 7);
    }
    DAT_004e1114++;
}



// 0x00156420 FUN_00156420 (95 B): matches/0x00156420.cpp
// sym: _FUN_00156420
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156420()
{
    if (DAT_004e111c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClearFightParamsHitRecordTrack>("timeBegin", &owners::Obj_14cea0::FUN_0014cea0);
        FUN_002347b0(&DAT_004e1118, params, 1);
    }
    DAT_004e111c++;
}



// 0x00156480 FUN_00156480 (158 B): matches/0x00156480.cpp
// sym: _FUN_00156480
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156480()
{
    if (DAT_004e1124 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackAddTrack>("timeBegin", &owners::Target_14ceb0::FUN_0014ceb0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackAddTrack>("weight", &owners::X_14ced0::FUN_0014ced0);
        FUN_002347b0(&DAT_004e1120, params, 2);
    }
    DAT_004e1124++;
}



// 0x00156520 FUN_00156520 (307 B): matches/0x00156520.cpp
// sym: _FUN_00156520
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::HealthTrack>, ParamFloatConstRange<hulkfight::motion::HealthTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156520()
{
    if (DAT_004e112c == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HealthTrack>("timeBegin", &owners::O_14cee0::FUN_0014cee0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HealthTrack>("hitPoints", &owners::O_14cf00::FUN_0014cf00);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::HealthTrack>("directDamage", &owners::Thing_14cf20::FUN_0014cf20);
        params[3] = new ::fight::ParamBool< ::hulkfight::motion::HealthTrack>("addTheseHitPoints", &owners::X_14cf40::FUN_0014cf40);
        params[4] = new ::fight::ParamBool< ::hulkfight::motion::HealthTrack>("subtractTheseHitPoints", &owners::X_14cf60::FUN_0014cf60);
        FUN_002347b0(&DAT_004e1128, params, 5);
    }
    DAT_004e112c++;
}



// 0x00156660 FUN_00156660 (158 B): matches/0x00156660.cpp
// sym: _FUN_00156660
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::HitDamageTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156660()
{
    if (DAT_004e1134 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitDamageTrack>("timeBegin", &owners::Obj_14cf70::FUN_0014cf70);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitDamageTrack>("weight", &owners::Obj_14cf90::FUN_0014cf90);
        FUN_002347b0(&DAT_004e1130, params, 2);
    }
    DAT_004e1134++;
}



// 0x00156700 FUN_00156700 (613 B): matches/0x00156700.cpp
// sym: _FUN_00156700
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>, ParamIntConstRange<hulkfight::motion::GroundSlideTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156700()
{
    if (DAT_004e113c == 0) {
        ::fight::ParamValue* params[11];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("timeBegin", &owners::Obj_14cfa0::FUN_0014cfa0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("timeEnd", &owners::Target_14cfb0::FUN_0014cfb0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("facing", &owners::C_14cfd0::FUN_0014cfd0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("friction", &owners::X_14d000::FUN_0014d000);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("deceleration", &owners::Obj_14d020::FUN_0014d020);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("minInitVelocity", &owners::X_14d040::FUN_0014d040);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("minVelocity", &owners::X_14d060::FUN_0014d060);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("maxVelocity", &owners::C_14d080::FUN_0014d080);
        params[8] = new ::fight::ParamIntConstRange< ::hulkfight::motion::GroundSlideTrack>("priority", &owners::Obj_14d0a0::FUN_0014d0a0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("blendInTime", &owners::X_14d0c0::FUN_0014d0c0);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GroundSlideTrack>("blendOutTime", &owners::X_14d0e0::FUN_0014d0e0);
        FUN_002347b0(&DAT_004e1138, params, 11);
    }
    DAT_004e113c++;
}



// 0x00156970 FUN_00156970 (562 B): matches/0x00156970.cpp
// sym: _FUN_00156970
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::HitPushbackTrack>, ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>, ParamIntConstRange<hulkfight::motion::HitPushbackTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156970()
{
    if (DAT_004e1144 == 0) {
        ::fight::ParamValue* params[10];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackTrack>("timeBegin", &owners::X_14d0f0::FUN_0014d0f0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackTrack>("timeEnd", &owners::Obj_14d100::FUN_0014d100);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackTrack>("weight", &owners::Obj_14d120::FUN_0014d120);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackTrack>("maxDistance", &owners::Obj_14d140::FUN_0014d140);
        params[4] = new ::fight::ParamBool< ::hulkfight::motion::HitPushbackTrack>("snapToPushback", &owners::T_14d160::FUN_0014d160);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackTrack>("orientation", &owners::C_14d180::FUN_0014d180);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackTrack>("proneSpin", &owners::C_14d1b0::FUN_0014d1b0);
        params[7] = new ::fight::ParamIntConstRange< ::hulkfight::motion::HitPushbackTrack>("priority", &owners::C_14d1e0::FUN_0014d1e0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackTrack>("blendInTime", &owners::Obj_14d200::FUN_0014d200);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitPushbackTrack>("blendOutTime", &owners::Obj_14d220::FUN_0014d220);
        FUN_002347b0(&DAT_004e1140, params, 10);
    }
    DAT_004e1144++;
}



// 0x00156bb0 FUN_00156bb0 (158 B): matches/0x00156bb0.cpp
// sym: _FUN_00156bb0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00156bb0()
{
    if (DAT_004e114c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::NoHitPushbackTrack>("timeBegin", &owners::A_14d230::FUN_0014d230);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::NoHitPushbackTrack>("timeEnd", &owners::C_14d240::FUN_0014d240);
        FUN_002347b0(&DAT_004e1148, params, 2);
    }
    DAT_004e114c++;
}

namespace fn_ff72ca8e {


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
        ::operator delete(this);
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
        ::operator delete(this);
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
        ::operator delete(this);
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

