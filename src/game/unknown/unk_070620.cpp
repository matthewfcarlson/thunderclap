// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070620..0x00072590 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f844dd59 {
#define TREE_TU_END }
namespace fn_f844dd59 {} using namespace fn_f844dd59;
#include "game/unknown.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_fa3ff49b { struct Vec_687c0; } 
namespace fn_00068320 { struct Obj { bool SetTimeEnd_00068320(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_00068440 { struct X { bool Fn(bool); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_00068610 { struct Obj { bool SetAmplitude_00068610(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_00069d10 { struct Obj { char Set(float); }; }   // (gx3, D18) setters, as defined in CAutoTargetTrack.cpp
namespace fn_f8f15a4b { struct X { bool Fn(void *); }; }   // (gx3, D18) setters, as defined in CComboMessageTrack.cpp
namespace fn_fa3ff49b { struct C_68260 { char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct C_68590 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct C_685a0 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct O_68310 { char SetTimeBegin_00068310(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct O_68530 { char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct O_688f0 { char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct O_68900 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68250 { unsigned char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_682e0 { bool Ctor(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_682f0 { char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68300 { bool SetX(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_683b0 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_683d0 { char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68470 { char Set(char); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68480 { char Set(float); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_684a0 { char Set(float); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_684c0 { char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_684d0 { char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_684e0 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68500 { char SetDamage_00068500(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68510 { char SetDamageMax_00068510(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68540 { bool Set(void *); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68550 { char SetTimeBegin_00068550(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68560 { char SetTimeEnd_00068560(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68580 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_685f0 { char SetTimeBegin_000685f0(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68600 { bool SetTimeEnd_00068600(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68620 { char SetFrequency_00068620(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68770 { bool SetTimeBegin_00068770(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68790 { char SetHint_00068790(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_687c0 { char Set(struct fn_fa3ff49b::Vec_687c0 *); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68910 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68920 { char Fn(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68930 { unsigned char SetTimeBegin_00068930(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68940 { bool SetTimeEnd_00068940(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68960 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68970 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68980 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Object { bool FUN_00068410(bool); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct T_68950 { bool SetExtensionTime_00068950(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Target_68270 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Target_68330 { char SetDistance_00068330(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Target_68520 { char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct X_683c0 { char Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct X_684f0 { char SetTimeBegin_000684f0(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct X_68570 { bool SetComboTimer_00068570(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct X_68780 { char SetTimeEnd_00068780(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fabf106d { struct Obj { char Set(float); }; }   // (gx3, D18) setters, as defined in CAutoTargetTrack.cpp
namespace fn_fad3cf42 { struct Obj { bool Set(float); }; }   // (gx3, D18) setters, as defined in unk_06b300.cpp
namespace fn_fad3cf42 { struct X { char SetDirection_0006b7b0(float); }; }   // (gx3, D18) setters, as defined in unk_06b300.cpp
namespace fn_fdda11e6 { struct A_69730 { bool Fn(int); }; }   // (gx3, D18) setters, as defined in CSoundTrack.cpp
namespace fn_fdda11e6 { struct Obj_69750 { unsigned char FUN_00069750(unsigned char); }; }   // (gx3, D18) setters, as defined in CSoundTrack.cpp

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f844dd59 {
void* FUN_0008d690(unsigned int size);
class CClimbingTrack_70620 {
public:
    void FUN_00067fc0();
    void FUN_00067fd0();
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_70620 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_70620(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CJumpTrack_706c0 {
public:
    bool FUN_00067fe0(int); /* (unb4) as defined; address taken only */
    char FUN_00067ff0(int); /* (unb4) as defined; address taken only */
    char FUN_00068000(void*); /* (unb4) as defined; address taken only */
    char FUN_00068010(int); /* (unb4) as defined; address taken only */
    bool FUN_00068020(int); /* (unb4) as defined; address taken only */
    bool FUN_00068030(int); /* (unb4) as defined; address taken only */
    char FUN_00068040(int); /* (unb4) as defined; address taken only */
    char FUN_00068050(int); /* (unb4) as defined; address taken only */
    bool FUN_00068060(int); /* (unb4) as defined; address taken only */
    char FUN_000680e0(float); /* (unb4) as defined; address taken only */
    bool FUN_00068070(int); /* (unb4) as defined; address taken only */
    bool FUN_00068100(float); /* (unb4) as defined; address taken only */
    bool FUN_00068080(int); /* (unb4) as defined; address taken only */
    bool FUN_00068090(int); /* (unb4) as defined; address taken only */
    char FUN_000680a0(int); /* (unb4) as defined; address taken only */
    bool FUN_000680b0(int); /* (unb4) as defined; address taken only */
    char FUN_000680c0(char); /* (unb4) as defined; address taken only */
    char FUN_000680d0(char); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamBool_706c0 : public ParamBoolBase {
public:
    ParamBool_706c0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_706c0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_706c0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_706c0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_706c0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CDropTrack_70ab0 {
public:
    bool FUN_00068120(int); /* (unb4) as defined; address taken only */
    char FUN_00068130(int); /* (unb4) as defined; address taken only */
    char FUN_00068140(float); /* (unb4) as defined; address taken only */
    char FUN_00068160(float); /* (unb4) as defined; address taken only */
    bool FUN_00068180(float); /* (unb4) as defined; address taken only */
    char FUN_000681a0(char); /* (unb4) as defined; address taken only */
    char FUN_000681b0(int); /* (unb4) as defined; address taken only */
    char FUN_000681c0(int); /* (unb4) as defined; address taken only */
    bool FUN_000681d0(void*); /* (unb4) as defined; address taken only */
    bool FUN_000681e0(int); /* (unb4) as defined; address taken only */
    bool FUN_000681f0(int); /* (unb4) as defined; address taken only */
    bool FUN_00068200(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamBool_70ab0 : public ParamBoolBase {
public:
    ParamBool_70ab0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_70ab0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_70ab0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_70ab0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_70ab0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CMoveTrack_70f20 {
public:
    bool FUN_00068280(int); /* (unb4) as defined; address taken only */
    bool FUN_00068290(int); /* (unb4) as defined; address taken only */
    char FUN_000682a0(int); /* (unb4) as defined; address taken only */
    bool FUN_000682b0(int); /* (unb4) as defined; address taken only */
    bool FUN_000682c0(int); /* (unb4) as defined; address taken only */
    bool FUN_000682d0(int); /* (unb4) as defined; address taken only */
    bool FUN_0006b6f0(float); /* (unb4) as defined; address taken only */
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_70f20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_70f20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_70f20 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_70f20(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CSweepTrack_712c0 {
public:
    char FUN_00068340(int); /* (unb4) as defined; address taken only */
    bool FUN_00068350(int); /* (unb4) as defined; address taken only */
    bool FUN_00068360(float); /* (unb4) as defined; address taken only */
    bool FUN_00068380(int); /* (unb4) as defined; address taken only */
    char FUN_00068390(int); /* (unb4) as defined; address taken only */
    char FUN_000683a0(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CIntangibleTrack_71a80 {
public:
    void FUN_000685b0();
    void FUN_000685c0();
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_71a80 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_71a80(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CIntangibleToActorsTrack_71b20 {
public:
    void FUN_000685d0();
    void FUN_000685e0();
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_71b20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_71b20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CJumpAttackTrack_71db0 {
public:
    bool FUN_000687a0(int); /* (unb4) as defined; address taken only */
    bool FUN_000687b0(int); /* (unb4) as defined; address taken only */
    char FUN_000687c0(void*); /* (unb4) as defined; address taken only */
    char FUN_000687e0(float); /* (unb4) as defined; address taken only */
    char FUN_00068800(int); /* (unb4) as defined; address taken only */
    bool FUN_00068810(int); /* (unb4) as defined; address taken only */
    bool FUN_00068820(int); /* (unb4) as defined; address taken only */
    char FUN_00068830(int); /* (unb4) as defined; address taken only */
    bool FUN_00068840(int); /* (unb4) as defined; address taken only */
};
class COrientTrack_71fb0 {
public:
    bool FUN_00068850(int); /* (unb4) as defined; address taken only */
    char FUN_00068860(int); /* (unb4) as defined; address taken only */
    bool FUN_00068870(float); /* (unb4) as defined; address taken only */
    char FUN_00068890(float); /* (unb4) as defined; address taken only */
    char FUN_000688b0(char); /* (unb4) as defined; address taken only */
    bool FUN_000688c0(int); /* (unb4) as defined; address taken only */
    bool FUN_000688d0(int); /* (unb4) as defined; address taken only */
    char FUN_000688e0(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CRageModeTrack_72440 {
public:
    void FUN_00068990();
    void FUN_000689a0();
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamEnumConstList_72440 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_72440(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_72440 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_72440(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CStageTrack_724f0 {
public:
    void FUN_000689b0();
    void FUN_000689c0();
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_724f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_724f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_724f0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_724f0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_f844dd59 {

} // namespace fn_f844dd59

namespace fn_f844dd59 {

} // namespace fn_f844dd59

namespace fn_f844dd59 {

} // namespace fn_f844dd59

namespace fn_f844dd59 {

} // namespace fn_f844dd59

// 0x0006e8e0 fight::ParamFloatConstRange<CClimbingTrack>::vfunc_0 (30 B): matches/0x0006e8e0.cpp
// sym: ??_G?$ParamFloatConstRange@VCClimbingTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpTrack_params_06e8c0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006e900 fight::ParamFloatConstRange<CJumpTrack>::vfunc_0 (30 B): matches/0x0006e900.cpp
// sym: ??_G?$ParamFloatConstRange@VCJumpTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpTrack_params_06e8c0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006e920 fight::ParamIntConstRange<CJumpTrack>::vfunc_0 (30 B): matches/0x0006e920.cpp
// sym: ??_G?$ParamIntConstRange@VCJumpTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpTrack_params_06e8c0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006e940 fight::ParamBool<CJumpTrack>::vfunc_0 (30 B): matches/0x0006e940.cpp
// sym: ??_G?$ParamBool@VCJumpTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpTrack_params_06e8c0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006e960 fight::ParamFloatConstRange<CDropTrack>::vfunc_0 (30 B): matches/0x0006e960.cpp
// sym: ??_G?$ParamFloatConstRange@VCDropTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CDropTrack_params_06e960.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006e980 fight::ParamBool<CDropTrack>::vfunc_0 (30 B): matches/0x0006e980.cpp
// sym: ??_G?$ParamBool@VCDropTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CDropTrack_params_06e960.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006e9a0 fight::ParamIntConstRange<CDropTrack>::vfunc_0 (30 B): matches/0x0006e9a0.cpp
// sym: ??_G?$ParamIntConstRange@VCDropTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CDropTrack_params_06e960.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ea20 fight::ParamFloatConstRange<CSoundTrack>::vfunc_0 (30 B): matches/0x0006ea20.cpp
// sym: ??_G?$ParamFloatConstRange@VCSoundTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSoundTrack_params_06ea20.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ea40 fight::ParamString<CSoundTrack>::vfunc_0 (30 B): matches/0x0006ea40.cpp
// sym: ??_G?$ParamString@VCSoundTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSoundTrack_params_06ea20.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ea60 fight::ParamBool<CSoundTrack>::vfunc_0 (30 B): matches/0x0006ea60.cpp
// sym: ??_G?$ParamBool@VCSoundTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSoundTrack_params_06ea20.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ea80 fight::ParamFloatConstRange<CComboMessageTrack>::vfunc_0 (30 B): matches/0x0006ea80.cpp
// sym: ??_G?$ParamFloatConstRange@VCComboMessageTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CComboMessageTrack_params_06ea80.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eaa0 fight::ParamString<CComboMessageTrack>::vfunc_0 (30 B): matches/0x0006eaa0.cpp
// sym: ??_G?$ParamString@VCComboMessageTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CComboMessageTrack_params_06ea80.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eac0 fight::ParamEnumConstList<CComboMessageTrack>::vfunc_0 (30 B): matches/0x0006eac0.cpp
// sym: ??_G?$ParamEnumConstList@VCComboMessageTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CComboMessageTrack_params_06ea80.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eae0 fight::ParamFloatConstRange<CMoveTrack>::vfunc_0 (30 B): matches/0x0006eae0.cpp
// sym: ??_G?$ParamFloatConstRange@VCMoveTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAutoTargetTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eb00 fight::ParamIntConstRange<CMoveTrack>::vfunc_0 (30 B): matches/0x0006eb00.cpp
// sym: ??_G?$ParamIntConstRange@VCMoveTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAutoTargetTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eb20 fight::ParamFloatConstRange<CMoveAddTrack>::vfunc_0 (30 B): matches/0x0006eb20.cpp
// sym: ??_G?$ParamFloatConstRange@VCMoveAddTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAutoTargetTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eb40 fight::ParamFloatConstRange<CMoveAddYTrack>::vfunc_0 (30 B): matches/0x0006eb40.cpp
// sym: ??_G?$ParamFloatConstRange@VCMoveAddYTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAutoTargetTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eb60 fight::ParamFloatConstRange<CSweepTrack>::vfunc_0 (30 B): matches/0x0006eb60.cpp
// sym: ??_G?$ParamFloatConstRange@VCSweepTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAutoTargetTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eb80 fight::ParamIntConstRange<CSweepTrack>::vfunc_0 (30 B): matches/0x0006eb80.cpp
// sym: ??_G?$ParamIntConstRange@VCSweepTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAutoTargetTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eba0 fight::ParamFloatConstRange<CAutoTargetTrack>::vfunc_0 (30 B): matches/0x0006eba0.cpp
// sym: ??_G?$ParamFloatConstRange@VCAutoTargetTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAutoTargetTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ebc0 fight::ParamBool<CAutoTargetTrack>::vfunc_0 (30 B): matches/0x0006ebc0.cpp
// sym: ??_G?$ParamBool@VCAutoTargetTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAutoTargetTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ebe0 fight::ParamIntConstRange<CAutoTargetTrack>::vfunc_0 (30 B): matches/0x0006ebe0.cpp
// sym: ??_G?$ParamIntConstRange@VCAutoTargetTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAutoTargetTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ec00 fight::ParamFloatConstRange<CDamageTrack>::vfunc_0 (30 B): matches/0x0006ec00.cpp
// sym: ??_G?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ec20 fight::ParamFloatConstRange<CDrainHealthTrack>::vfunc_0 (30 B): matches/0x0006ec20.cpp
// sym: ??_G?$ParamFloatConstRange@VCDrainHealthTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ec40 fight::ParamFloatConstRange<CComboTimerTrack>::vfunc_0 (30 B): matches/0x0006ec40.cpp
// sym: ??_G?$ParamFloatConstRange@VCComboTimerTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ec60 fight::ParamFloatConstRange<CInvincibleTrack>::vfunc_0 (30 B): matches/0x0006ec60.cpp
// sym: ??_G?$ParamFloatConstRange@VCInvincibleTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ec80 fight::ParamFloatConstRange<CIntangibleTrack>::vfunc_0 (30 B): matches/0x0006ec80.cpp
// sym: ??_G?$ParamFloatConstRange@VCIntangibleTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eca0 fight::ParamFloatConstRange<CIntangibleToActorsTrack>::vfunc_0 (30 B): matches/0x0006eca0.cpp
// sym: ??_G?$ParamFloatConstRange@VCIntangibleToActorsTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ecc0 fight::ParamFloatConstRange<CCameraShakeTrack>::vfunc_0 (30 B): matches/0x0006ecc0.cpp
// sym: ??_G?$ParamFloatConstRange@VCCameraShakeTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ed60 fight::ParamFloatConstRange<CCameraHintTrack>::vfunc_0 (30 B): matches/0x0006ed60.cpp
// sym: ??_G?$ParamFloatConstRange@VCCameraHintTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpAttackTrack_params_06ed60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ed80 fight::ParamEnumConstList<CCameraHintTrack>::vfunc_0 (30 B): matches/0x0006ed80.cpp
// sym: ??_G?$ParamEnumConstList@VCCameraHintTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpAttackTrack_params_06ed60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eda0 fight::ParamFloatConstRange<CJumpAttackTrack>::vfunc_0 (30 B): matches/0x0006eda0.cpp
// sym: ??_G?$ParamFloatConstRange@VCJumpAttackTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpAttackTrack_params_06ed60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006edc0 fight::ParamVector<CJumpAttackTrack>::vfunc_0 (30 B): matches/0x0006edc0.cpp
// sym: ??_G?$ParamVector@VCJumpAttackTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpAttackTrack_params_06ed60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ede0 fight::ParamIntConstRange<CJumpAttackTrack>::vfunc_0 (30 B): matches/0x0006ede0.cpp
// sym: ??_G?$ParamIntConstRange@VCJumpAttackTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpAttackTrack_params_06ed60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ee00 fight::ParamFloatConstRange<COrientTrack>::vfunc_0 (30 B): matches/0x0006ee00.cpp
// sym: ??_G?$ParamFloatConstRange@VCOrientTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from COrientTrack_params_06ee00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ee20 fight::ParamBool<COrientTrack>::vfunc_0 (30 B): matches/0x0006ee20.cpp
// sym: ??_G?$ParamBool@VCOrientTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from COrientTrack_params_06ee00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ee40 fight::ParamIntConstRange<COrientTrack>::vfunc_0 (30 B): matches/0x0006ee40.cpp
// sym: ??_G?$ParamIntConstRange@VCOrientTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from COrientTrack_params_06ee00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ee60 fight::ParamFloatConstRange<CDriftTrack>::vfunc_0 (30 B): matches/0x0006ee60.cpp
// sym: ??_G?$ParamFloatConstRange@VCDriftTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ee80 fight::ParamFloatConstRange<CUninterruptibleTrack>::vfunc_0 (30 B): matches/0x0006ee80.cpp
// sym: ??_G?$ParamFloatConstRange@VCUninterruptibleTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eea0 fight::ParamFloatConstRange<CInvulnerableTrack>::vfunc_0 (30 B): matches/0x0006eea0.cpp
// sym: ??_G?$ParamFloatConstRange@VCInvulnerableTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eec0 fight::ParamFloatConstRange<CRageModeTrack>::vfunc_0 (30 B): matches/0x0006eec0.cpp
// sym: ??_G?$ParamFloatConstRange@VCRageModeTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006eee0 fight::ParamEnumConstList<CRageModeTrack>::vfunc_0 (30 B): matches/0x0006eee0.cpp
// sym: ??_G?$ParamEnumConstList@VCRageModeTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ef00 fight::ParamFloatConstRange<CStageTrack>::vfunc_0 (30 B): matches/0x0006ef00.cpp
// sym: ??_G?$ParamFloatConstRange@VCStageTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x0006ef20 fight::ParamIntConstRange<CStageTrack>::vfunc_0 (30 B): matches/0x0006ef20.cpp
// sym: ??_G?$ParamIntConstRange@VCStageTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00070620 / FUN_000706c0 / FUN_00070ab0 / FUN_00070d50 / FUN_00070e30 / FUN_00070f20 / FUN_000710c0 / FUN_000711c0 / FUN_000712c0 / FUN_00071430 / FUN_00071700 / FUN_000717e0 / FUN_000718c0 / FUN_000719a0 / FUN_00071a80 / FUN_00071b20 / FUN_00071bc0 / FUN_00071cc0 / FUN_00071db0 / FUN_00071fb0 / FUN_00072180 / FUN_00072280 / FUN_00072360 / FUN_00072440 / FUN_000724f0)



// 0x00070620 FUN_00070620 (158 B): matches/0x00070620.cpp
// sym: _FUN_00070620
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CClimbingTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00070620()
{
    if (DAT_004dcf1c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CClimbingTrack>("timeBegin", &owners::O_67fc0::FUN_00067fc0);
        params[1] = new ::fight::ParamFloatConstRange< ::CClimbingTrack>("timeEnd", &owners::Obj_67fd0::FUN_00067fd0);
        FUN_002347b0(&DAT_004dcf18, params, 2);
    }
    DAT_004dcf1c++;
}



// 0x000706c0 FUN_000706c0 (970 B): matches/0x000706c0.cpp
// sym: _FUN_000706c0
// (gx2, D18) rewritten; constructs the real ParamBool<CJumpTrack>, ParamFloatConstRange<CJumpTrack>, ParamIntConstRange<CJumpTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000706c0()
{
    if (DAT_004dcf24 == 0) {
        ::fight::ParamValue* params[18];
        params[0] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("timeBegin", &owners::Obj_67fe0::FUN_00067fe0);
        params[1] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("timeEnd", &owners::Obj_67ff0::FUN_00067ff0);
        params[2] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("minFlightTime", &owners::Obj_68000::FUN_00068000);
        params[3] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("maxFlightTime", &owners::Obj_68010::FUN_00068010);
        params[4] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("upDistanceMin", &owners::Obj_68020::FUN_00068020);
        params[5] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("upDistanceMax", &owners::A_68030::FUN_00068030);
        params[6] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("forwardDistanceMin", &owners::X_68040::FUN_00068040);
        params[7] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("forwardDistanceMax", &owners::Obj_68050::FUN_00068050);
        params[8] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("drift", &owners::A_68060::FUN_00068060);
        params[9] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("turningVelocityMin", &owners::Obj_680e0::FUN_000680e0);
        params[10] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("turningVelocityMinForwardSpeedCap", &owners::Obj_68070::FUN_00068070);
        params[11] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("turningVelocityMax", &owners::Obj_68100::FUN_00068100);
        params[12] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("turningVelocityMaxForwardSpeedCap", &owners::Obj_68080::FUN_00068080);
        params[13] = new ::fight::ParamIntConstRange< ::CJumpTrack>("priority", &owners::Obj_68090::FUN_00068090);
        params[14] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("blendInTime", &owners::Obj_680a0::FUN_000680a0);
        params[15] = new ::fight::ParamFloatConstRange< ::CJumpTrack>("blendOutTime", &owners::X_680b0::FUN_000680b0);
        params[16] = new ::fight::ParamBool< ::CJumpTrack>("stopTrackAtApex", &owners::Target_680c0::FUN_000680c0);
        params[17] = new ::fight::ParamBool< ::CJumpTrack>("redirect", &owners::Obj_680d0::FUN_000680d0);
        FUN_002347b0(&DAT_004dcf20, params, 18);
    }
    DAT_004dcf24++;
}



// 0x00070ab0 FUN_00070ab0 (664 B): matches/0x00070ab0.cpp
// sym: _FUN_00070ab0
// (gx2, D18) rewritten; constructs the real ParamBool<CDropTrack>, ParamFloatConstRange<CDropTrack>, ParamIntConstRange<CDropTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00070ab0()
{
    if (DAT_004dcf2c == 0) {
        ::fight::ParamValue* params[12];
        params[0] = new ::fight::ParamFloatConstRange< ::CDropTrack>("timeBegin", &owners::O_68120::FUN_00068120);
        params[1] = new ::fight::ParamFloatConstRange< ::CDropTrack>("timeEnd", &owners::Obj_68130::FUN_00068130);
        params[2] = new ::fight::ParamFloatConstRange< ::CDropTrack>("facing", &owners::C_68140::FUN_00068140);
        params[3] = new ::fight::ParamFloatConstRange< ::CDropTrack>("facingVelocity", &owners::Obj_68160::FUN_00068160);
        params[4] = new ::fight::ParamFloatConstRange< ::CDropTrack>("turningVelocity", &owners::Obj_68180::FUN_00068180);
        params[5] = new ::fight::ParamBool< ::CDropTrack>("useInitialVelocity", &owners::Obj_681a0::FUN_000681a0);
        params[6] = new ::fight::ParamFloatConstRange< ::CDropTrack>("initialVelocity", &owners::Target_681b0::FUN_000681b0);
        params[7] = new ::fight::ParamFloatConstRange< ::CDropTrack>("gravity", &owners::Obj_681c0::FUN_000681c0);
        params[8] = new ::fight::ParamFloatConstRange< ::CDropTrack>("maxVelocity", &owners::Obj_681d0::FUN_000681d0);
        params[9] = new ::fight::ParamIntConstRange< ::CDropTrack>("priority", &owners::Obj_681e0::FUN_000681e0);
        params[10] = new ::fight::ParamFloatConstRange< ::CDropTrack>("rootBlendInTime", &owners::Obj_681f0::FUN_000681f0);
        params[11] = new ::fight::ParamFloatConstRange< ::CDropTrack>("rootBlendOutTime", &owners::Obj_68200::FUN_00068200);
        FUN_002347b0(&DAT_004dcf28, params, 12);
    }
    DAT_004dcf2c++;
}



// 0x00070d50 FUN_00070d50 (213 B): matches/0x00070d50.cpp
// sym: _FUN_00070d50
// (gx2, D18) from unk_070620.new_plain.cpp; constructs the real ParamBool<CSoundTrack>, ParamFloatConstRange<CSoundTrack>, ParamString<CSoundTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00070d50()
{
    if (DAT_004dcf3c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CSoundTrack>("timeBegin", &fn_fa3ff49b::Obj_68250::Set);
        params[1] = new ::fight::ParamString< ::CSoundTrack>("sound", &fn_fdda11e6::A_69730::Fn);
        params[2] = new ::fight::ParamBool< ::CSoundTrack>("weapon", &fn_fdda11e6::Obj_69750::FUN_00069750);
        FUN_002347b0(&DAT_004dcf38, params, 3);
    }
    DAT_004dcf3c++;
}



// 0x00070e30 FUN_00070e30 (227 B): matches/0x00070e30.cpp
// sym: _FUN_00070e30
// (gx2, D18) from unk_070620.new_plain.cpp; constructs the real ParamEnumConstList<CComboMessageTrack>, ParamFloatConstRange<CComboMessageTrack>, ParamString<CComboMessageTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00070e30()
{
    if (DAT_004dcf44 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CComboMessageTrack>("timeBegin", &fn_fa3ff49b::C_68260::Set);
        params[1] = new ::fight::ParamString< ::CComboMessageTrack>("string", &fn_f8f15a4b::X::Fn);
        params[2] = new ::fight::ParamEnumConstList< ::CComboMessageTrack>("type", (void*)&DAT_00496f8c, 4, &fn_fa3ff49b::Target_68270::Set);
        FUN_002347b0(&DAT_004dcf40, params, 3);
    }
    DAT_004dcf44++;
}



// 0x00070f20 FUN_00070f20 (409 B): matches/0x00070f20.cpp
// sym: _FUN_00070f20
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CMoveTrack>, ParamIntConstRange<CMoveTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00070f20()
{
    if (DAT_004dcf4c == 0) {
        ::fight::ParamValue* params[7];
        params[0] = new ::fight::ParamFloatConstRange< ::CMoveTrack>("timeBegin", &owners::Obj_68280::FUN_00068280);
        params[1] = new ::fight::ParamFloatConstRange< ::CMoveTrack>("timeEnd", &owners::Obj_68290::FUN_00068290);
        params[2] = new ::fight::ParamFloatConstRange< ::CMoveTrack>("distance", &owners::Obj_682a0::FUN_000682a0);
        params[3] = new ::fight::ParamFloatConstRange< ::CMoveTrack>("direction", &owners::C_6b6f0::FUN_0006b6f0);
        params[4] = new ::fight::ParamIntConstRange< ::CMoveTrack>("priority", &owners::X_682b0::FUN_000682b0);
        params[5] = new ::fight::ParamFloatConstRange< ::CMoveTrack>("blendInTime", &owners::X_682c0::FUN_000682c0);
        params[6] = new ::fight::ParamFloatConstRange< ::CMoveTrack>("blendOutTime", &owners::Obj_682d0::FUN_000682d0);
        FUN_002347b0(&DAT_004dcf48, params, 7);
    }
    DAT_004dcf4c++;
}



// 0x000710c0 FUN_000710c0 (256 B): matches/0x000710c0.cpp
// sym: _FUN_000710c0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CMoveAddTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000710c0()
{
    if (DAT_004dcf54 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::CMoveAddTrack>("timeBegin", &fn_fa3ff49b::Obj_682e0::Ctor);
        params[1] = new ::fight::ParamFloatConstRange< ::CMoveAddTrack>("timeEnd", &fn_fa3ff49b::Obj_682f0::Set);
        params[2] = new ::fight::ParamFloatConstRange< ::CMoveAddTrack>("distance", &fn_fa3ff49b::Obj_68300::SetX);
        params[3] = new ::fight::ParamFloatConstRange< ::CMoveAddTrack>("direction", &fn_fad3cf42::Obj::Set);
        FUN_002347b0(&DAT_004dcf50, params, 4);
    }
    DAT_004dcf54++;
}



// 0x000711c0 FUN_000711c0 (256 B): matches/0x000711c0.cpp
// sym: _FUN_000711c0
// (gx2, D18) from unk_070620.new_plain.cpp; constructs the real ParamFloatConstRange<CMoveAddYTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000711c0()
{
    if (DAT_004dcf5c == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::CMoveAddYTrack>("timeBegin", &fn_fa3ff49b::O_68310::SetTimeBegin_00068310);
        params[1] = new ::fight::ParamFloatConstRange< ::CMoveAddYTrack>("timeEnd", &fn_00068320::Obj::SetTimeEnd_00068320);
        params[2] = new ::fight::ParamFloatConstRange< ::CMoveAddYTrack>("distance", &fn_fa3ff49b::Target_68330::SetDistance_00068330);
        params[3] = new ::fight::ParamFloatConstRange< ::CMoveAddYTrack>("direction", &fn_fad3cf42::X::SetDirection_0006b7b0);
        FUN_002347b0(&DAT_004dcf58, params, 4);
    }
    DAT_004dcf5c++;
}



// 0x000712c0 FUN_000712c0 (358 B): matches/0x000712c0.cpp
// sym: _FUN_000712c0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CSweepTrack>, ParamIntConstRange<CSweepTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000712c0()
{
    if (DAT_004dcf64 == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamFloatConstRange< ::CSweepTrack>("timeBegin", &owners::Obj_68340::FUN_00068340);
        params[1] = new ::fight::ParamFloatConstRange< ::CSweepTrack>("timeEnd", &owners::Obj_68350::FUN_00068350);
        params[2] = new ::fight::ParamFloatConstRange< ::CSweepTrack>("arc", &owners::Thing_68360::FUN_00068360);
        params[3] = new ::fight::ParamIntConstRange< ::CSweepTrack>("priority", &owners::Obj_68380::FUN_00068380);
        params[4] = new ::fight::ParamFloatConstRange< ::CSweepTrack>("rootBlendInTime", &owners::Obj_68390::FUN_00068390);
        params[5] = new ::fight::ParamFloatConstRange< ::CSweepTrack>("rootBlendOutTime", &owners::Obj_683a0::FUN_000683a0);
        FUN_002347b0(&DAT_004dcf60, params, 6);
    }
    DAT_004dcf64++;
}



// 0x00071430 FUN_00071430 (715 B): matches/0x00071430.cpp
// sym: ?FUN_00071430@@YAXXZ
// (gx2, D18) rewritten; constructs the real ParamBool<CAutoTargetTrack>, ParamFloatConstRange<CAutoTargetTrack>, ParamIntConstRange<CAutoTargetTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00071430()
{
    if ((*(int*)&DAT_004dcf6c) == 0) {
        ::fight::ParamValue* params[13];
        params[0] = new ::fight::ParamFloatConstRange< ::CAutoTargetTrack>("timeBegin", &fn_fa3ff49b::Obj_683b0::Set);
        params[1] = new ::fight::ParamFloatConstRange< ::CAutoTargetTrack>("timeEnd", &fn_fa3ff49b::X_683c0::Set);
        params[2] = new ::fight::ParamFloatConstRange< ::CAutoTargetTrack>("turningVelocity", &fn_fabf106d::Obj::Set);
        params[3] = new ::fight::ParamFloatConstRange< ::CAutoTargetTrack>("arc", &fn_00069d10::Obj::Set);
        params[4] = new ::fight::ParamFloatConstRange< ::CAutoTargetTrack>("distance", &fn_fa3ff49b::Obj_683d0::Set);
        params[5] = new ::fight::ParamBool< ::CAutoTargetTrack>("checkDistance", &fn_fa3ff49b::Object::FUN_00068410);
        params[6] = new ::fight::ParamBool< ::CAutoTargetTrack>("pickupPropTarget", &fn_00068440::X::Fn);
        params[7] = new ::fight::ParamBool< ::CAutoTargetTrack>("locator", &fn_fa3ff49b::Obj_68470::Set);
        params[8] = new ::fight::ParamFloatConstRange< ::CAutoTargetTrack>("orientOffset", &fn_fa3ff49b::Obj_68480::Set);
        params[9] = new ::fight::ParamFloatConstRange< ::CAutoTargetTrack>("orientOffsetFromTarget", &fn_fa3ff49b::Obj_684a0::Set);
        params[10] = new ::fight::ParamIntConstRange< ::CAutoTargetTrack>("priority", &fn_fa3ff49b::Obj_684c0::Set);
        params[11] = new ::fight::ParamFloatConstRange< ::CAutoTargetTrack>("blendInTime", &fn_fa3ff49b::Obj_684d0::Set);
        params[12] = new ::fight::ParamFloatConstRange< ::CAutoTargetTrack>("blendOutTime", &fn_fa3ff49b::Obj_684e0::Set);
        FUN_002347b0(&DAT_004dcf68, params, 13);
    }
    (*(int*)&DAT_004dcf6c)++;
}



// 0x00071700 FUN_00071700 (213 B): matches/0x00071700.cpp
// sym: _FUN_00071700
// (gx2, D18) from unk_070620.new_plain.cpp; constructs the real ParamFloatConstRange<CDamageTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00071700()
{
    if (DAT_004dcf74 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CDamageTrack>("timeBegin", &fn_fa3ff49b::X_684f0::SetTimeBegin_000684f0);
        params[1] = new ::fight::ParamFloatConstRange< ::CDamageTrack>("damage", &fn_fa3ff49b::Obj_68500::SetDamage_00068500);
        params[2] = new ::fight::ParamFloatConstRange< ::CDamageTrack>("damageMax", &fn_fa3ff49b::Obj_68510::SetDamageMax_00068510);
        FUN_002347b0(&DAT_004dcf70, params, 3);
    }
    DAT_004dcf74++;
}



// 0x000717e0 FUN_000717e0 (213 B): matches/0x000717e0.cpp
// sym: _FUN_000717e0
// (gx2, D18) from unk_070620.new_plain.cpp; constructs the real ParamFloatConstRange<CDrainHealthTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000717e0()
{
    if (DAT_004dcf7c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CDrainHealthTrack>("timeBegin", &fn_fa3ff49b::Target_68520::Set);
        params[1] = new ::fight::ParamFloatConstRange< ::CDrainHealthTrack>("timeEnd", &fn_fa3ff49b::O_68530::Set);
        params[2] = new ::fight::ParamFloatConstRange< ::CDrainHealthTrack>("damage", &fn_fa3ff49b::Obj_68540::Set);
        FUN_002347b0(&DAT_004dcf78, params, 3);
    }
    DAT_004dcf7c++;
}



// 0x000718c0 FUN_000718c0 (213 B): matches/0x000718c0.cpp
// sym: _FUN_000718c0
// (gx2, D18) from unk_070620.iso_000718c0.cpp; constructs the real ParamFloatConstRange<CComboTimerTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000718c0()
{
    if (DAT_004dcf84 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CComboTimerTrack>("timeBegin", &fn_fa3ff49b::Obj_68550::SetTimeBegin_00068550);
        params[1] = new ::fight::ParamFloatConstRange< ::CComboTimerTrack>("timeEnd", &fn_fa3ff49b::Obj_68560::SetTimeEnd_00068560);
        params[2] = new ::fight::ParamFloatConstRange< ::CComboTimerTrack>("comboTimer", &fn_fa3ff49b::X_68570::SetComboTimer_00068570);
        FUN_002347b0(&DAT_004dcf80, params, 3);
    }
    DAT_004dcf84++;
}



// 0x000719a0 FUN_000719a0 (213 B): matches/0x000719a0.cpp
// sym: _FUN_000719a0
// (gx2, D18) from unk_070620.iso_000719a0.cpp; constructs the real ParamFloatConstRange<CInvincibleTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000719a0()
{
    if (DAT_004dcf8c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CInvincibleTrack>("timeBegin", &fn_fa3ff49b::Obj_68580::Set);
        params[1] = new ::fight::ParamFloatConstRange< ::CInvincibleTrack>("timeEnd", &fn_fa3ff49b::C_68590::Set);
        params[2] = new ::fight::ParamFloatConstRange< ::CInvincibleTrack>("extensionTime", &fn_fa3ff49b::C_685a0::Set);
        FUN_002347b0(&DAT_004dcf88, params, 3);
    }
    DAT_004dcf8c++;
}



// 0x00071a80 FUN_00071a80 (158 B): matches/0x00071a80.cpp
// sym: _FUN_00071a80
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CIntangibleTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00071a80()
{
    if (DAT_004dcf94 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CIntangibleTrack>("timeBegin", &owners::X_685b0::FUN_000685b0);
        params[1] = new ::fight::ParamFloatConstRange< ::CIntangibleTrack>("timeEnd", &owners::Obj_685c0::FUN_000685c0);
        FUN_002347b0(&DAT_004dcf90, params, 2);
    }
    DAT_004dcf94++;
}



// 0x00071b20 FUN_00071b20 (158 B): matches/0x00071b20.cpp
// sym: _FUN_00071b20
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CIntangibleToActorsTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00071b20()
{
    if (DAT_004dcf9c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CIntangibleToActorsTrack>("timeBegin", &owners::Obj_685d0::FUN_000685d0);
        params[1] = new ::fight::ParamFloatConstRange< ::CIntangibleToActorsTrack>("timeEnd", &owners::Obj_685e0::FUN_000685e0);
        FUN_002347b0(&DAT_004dcf98, params, 2);
    }
    DAT_004dcf9c++;
}



// 0x00071bc0 FUN_00071bc0 (256 B): matches/0x00071bc0.cpp
// sym: ?FUN_00071bc0@@YAXXZ
// (gx2, D18) from unk_070620.iso_00071bc0.cpp; constructs the real ParamFloatConstRange<CCameraShakeTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00071bc0()
{
    if (DAT_004dcfa4 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::CCameraShakeTrack>("timeBegin", &fn_fa3ff49b::Obj_685f0::SetTimeBegin_000685f0);
        params[1] = new ::fight::ParamFloatConstRange< ::CCameraShakeTrack>("timeEnd", &fn_fa3ff49b::Obj_68600::SetTimeEnd_00068600);
        params[2] = new ::fight::ParamFloatConstRange< ::CCameraShakeTrack>("amplitude", &fn_00068610::Obj::SetAmplitude_00068610);
        params[3] = new ::fight::ParamFloatConstRange< ::CCameraShakeTrack>("frequency", &fn_fa3ff49b::Obj_68620::SetFrequency_00068620);
        FUN_002347b0(&DAT_004dcfa0, params, 4);
    }
    DAT_004dcfa4++;
}



// 0x00071cc0 FUN_00071cc0 (227 B): matches/0x00071cc0.cpp
// sym: _FUN_00071cc0
// (gx2, D18) from unk_070620.iso_00071cc0.cpp; constructs the real ParamEnumConstList<CCameraHintTrack>, ParamFloatConstRange<CCameraHintTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00071cc0()
{
    if (DAT_004dcfb4 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CCameraHintTrack>("timeBegin", &fn_fa3ff49b::Obj_68770::SetTimeBegin_00068770);
        params[1] = new ::fight::ParamFloatConstRange< ::CCameraHintTrack>("timeEnd", &fn_fa3ff49b::X_68780::SetTimeEnd_00068780);
        params[2] = new ::fight::ParamEnumConstList< ::CCameraHintTrack>("hint", (void*)&DAT_00496fb4, 9, &fn_fa3ff49b::Obj_68790::SetHint_00068790);
        FUN_002347b0(&DAT_004dcfb0, params, 3);
    }
    DAT_004dcfb4++;
}



// 0x00071db0 FUN_00071db0 (511 B): matches/0x00071db0.cpp
// sym: _FUN_00071db0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CJumpAttackTrack>, ParamIntConstRange<CJumpAttackTrack>, ParamVector<CJumpAttackTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00071db0()
{
    if (DAT_004dcfbc == 0) {
        ::fight::ParamValue* params[9];
        params[0] = new ::fight::ParamFloatConstRange< ::CJumpAttackTrack>("timeBegin", &owners::A_687a0::FUN_000687a0);
        params[1] = new ::fight::ParamFloatConstRange< ::CJumpAttackTrack>("timeEnd", &owners::A_687b0::FUN_000687b0);
        params[2] = new ::fight::ParamVector< ::CJumpAttackTrack>("direction", &fn_fa3ff49b::Obj_687c0::Set);
        params[3] = new ::fight::ParamFloatConstRange< ::CJumpAttackTrack>("arc", &owners::Sub_687e0::FUN_000687e0);
        params[4] = new ::fight::ParamFloatConstRange< ::CJumpAttackTrack>("distance", &owners::Obj_68800::FUN_00068800);
        params[5] = new ::fight::ParamFloatConstRange< ::CJumpAttackTrack>("speed", &owners::Obj_68810::FUN_00068810);
        params[6] = new ::fight::ParamIntConstRange< ::CJumpAttackTrack>("priority", &owners::C_68820::FUN_00068820);
        params[7] = new ::fight::ParamFloatConstRange< ::CJumpAttackTrack>("rootBlendInTime", &owners::Obj_68830::FUN_00068830);
        params[8] = new ::fight::ParamFloatConstRange< ::CJumpAttackTrack>("rootBlendOutTime", &owners::Obj_68840::FUN_00068840);
        FUN_002347b0(&DAT_004dcfb8, params, 9);
    }
    DAT_004dcfbc++;
}



// 0x00071fb0 FUN_00071fb0 (460 B): matches/0x00071fb0.cpp
// sym: _FUN_00071fb0
// (gx2, D18) rewritten; constructs the real ParamBool<COrientTrack>, ParamFloatConstRange<COrientTrack>, ParamIntConstRange<COrientTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00071fb0()
{
    if (DAT_004dcfc4 == 0) {
        ::fight::ParamValue* params[8];
        params[0] = new ::fight::ParamFloatConstRange< ::COrientTrack>("timeBegin", &owners::Obj_68850::FUN_00068850);
        params[1] = new ::fight::ParamFloatConstRange< ::COrientTrack>("timeEnd", &owners::Obj_68860::FUN_00068860);
        params[2] = new ::fight::ParamFloatConstRange< ::COrientTrack>("turningVelocity", &owners::Obj_68870::FUN_00068870);
        params[3] = new ::fight::ParamFloatConstRange< ::COrientTrack>("offset", &owners::Obj_68890::FUN_00068890);
        params[4] = new ::fight::ParamBool< ::COrientTrack>("steering", &owners::Obj_688b0::FUN_000688b0);
        params[5] = new ::fight::ParamIntConstRange< ::COrientTrack>("priority", &owners::X_688c0::FUN_000688c0);
        params[6] = new ::fight::ParamFloatConstRange< ::COrientTrack>("blendInTime", &owners::C_688d0::FUN_000688d0);
        params[7] = new ::fight::ParamFloatConstRange< ::COrientTrack>("blendOutTime", &owners::Target_688e0::FUN_000688e0);
        FUN_002347b0(&DAT_004dcfc0, params, 8);
    }
    DAT_004dcfc4++;
}



// 0x00072180 FUN_00072180 (256 B): matches/0x00072180.cpp
// sym: _FUN_00072180
// (gx2, D18) from unk_070620.iso_00072180.cpp; constructs the real ParamFloatConstRange<CDriftTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00072180()
{
    if (DAT_004dcfcc == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::CDriftTrack>("timeBegin", &fn_fa3ff49b::O_688f0::Set);
        params[1] = new ::fight::ParamFloatConstRange< ::CDriftTrack>("timeEnd", &fn_fa3ff49b::O_68900::Set);
        params[2] = new ::fight::ParamFloatConstRange< ::CDriftTrack>("minVelocity", &fn_fa3ff49b::Obj_68910::Set);
        params[3] = new ::fight::ParamFloatConstRange< ::CDriftTrack>("maxVelocity", &fn_fa3ff49b::Obj_68920::Fn);
        FUN_002347b0(&DAT_004dcfc8, params, 4);
    }
    DAT_004dcfcc++;
}



// 0x00072280 FUN_00072280 (213 B): matches/0x00072280.cpp
// sym: _FUN_00072280
// (gx2, D18) from unk_070620.iso_00072280.cpp; constructs the real ParamFloatConstRange<CUninterruptibleTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00072280()
{
    if (DAT_004dcfd4 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CUninterruptibleTrack>("timeBegin", &fn_fa3ff49b::Obj_68930::SetTimeBegin_00068930);
        params[1] = new ::fight::ParamFloatConstRange< ::CUninterruptibleTrack>("timeEnd", &fn_fa3ff49b::Obj_68940::SetTimeEnd_00068940);
        params[2] = new ::fight::ParamFloatConstRange< ::CUninterruptibleTrack>("extensionTime", &fn_fa3ff49b::T_68950::SetExtensionTime_00068950);
        FUN_002347b0(&DAT_004dcfd0, params, 3);
    }
    DAT_004dcfd4++;
}



// 0x00072360 FUN_00072360 (213 B): matches/0x00072360.cpp
// sym: _FUN_00072360
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CInvulnerableTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00072360()
{
    if (DAT_004dcfdc == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CInvulnerableTrack>("timeBegin", &fn_fa3ff49b::Obj_68960::Set);
        params[1] = new ::fight::ParamFloatConstRange< ::CInvulnerableTrack>("timeEnd", &fn_fa3ff49b::Obj_68970::Set);
        params[2] = new ::fight::ParamFloatConstRange< ::CInvulnerableTrack>("extensionTime", &fn_fa3ff49b::Obj_68980::Set);
        FUN_002347b0(&DAT_004dcfd8, params, 3);
    }
    DAT_004dcfdc++;
}



// 0x00072440 FUN_00072440 (172 B): matches/0x00072440.cpp
// sym: _FUN_00072440
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CRageModeTrack>, ParamFloatConstRange<CRageModeTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00072440()
{
    if (DAT_004dcfe4 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CRageModeTrack>("timeBegin", &owners::Obj_68990::FUN_00068990);
        params[1] = new ::fight::ParamEnumConstList< ::CRageModeTrack>("rageMode", (void*)&DAT_00496fd8, 3, &owners::X_689a0::FUN_000689a0);
        FUN_002347b0(&DAT_004dcfe0, params, 2);
    }
    DAT_004dcfe4++;
}



// 0x000724f0 FUN_000724f0 (158 B): matches/0x000724f0.cpp
// sym: _FUN_000724f0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CStageTrack>, ParamIntConstRange<CStageTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000724f0()
{
    if (DAT_004dcfec == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CStageTrack>("timeBegin", &owners::X_689b0::FUN_000689b0);
        params[1] = new ::fight::ParamIntConstRange< ::CStageTrack>("stage", &owners::Obj_689c0::FUN_000689c0);
        FUN_002347b0(&DAT_004dcfe8, params, 2);
    }
    DAT_004dcfec++;
}


