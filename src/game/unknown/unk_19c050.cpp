// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0019c050..0x0019e430 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fdcf800c {
#define TREE_TU_END }
namespace fn_fdcf800c {} using namespace fn_fdcf800c;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fdcf800c {
class TrackFactoryCasterTemplate_19c050 {
  public:
    virtual bool Cast_0019a260(void*);
    TrackFactoryCasterTemplate_19c050() {}
};
class Owner {
  public:
    void Apply_002367c0(void*);
    void Set_002367c0(void*);
};
extern "C" void* Lookup(void*, TrackFactoryCasterTemplate_19c050*);
} // namespace fn_fdcf800c
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fdcf800c {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_fdcf800c
namespace hulkfight { namespace motion {
class FireProjectileTrack_19c080 {
public:
    bool FUN_00192190(int); /* (unb4) as defined; address taken only */
    bool FUN_001921a0(int); /* (unb4) as defined; address taken only */
    void FUN_001921b0();
    bool FUN_001921e0(void*); /* (unb4) as defined; address taken only */
    bool FUN_00192210(int); /* (unb4) as defined; address taken only */
    bool FUN_00192230(int); /* (unb4) as defined; address taken only */
    void FUN_00192240();
    bool FUN_00192270(void*); /* (unb4) as defined; address taken only */
    char FUN_001922b0(void*); /* (unb4) as defined; address taken only */
    bool FUN_001922e0(float); /* (unb4) as defined; address taken only */
    bool FUN_00192310(int); /* (unb4) as defined; address taken only */
    char FUN_00192330(int); /* (unb4) as defined; address taken only */
    bool FUN_00192350(int); /* (unb4) as defined; address taken only */
    bool FUN_00192370(float); /* (unb4) as defined; address taken only */
    char FUN_001923a0(int); /* (unb4) as defined; address taken only */
    char FUN_001923c0(float); /* (unb4) as defined; address taken only */
    char FUN_001923f0(char); /* (unb4) as defined; address taken only */
    char FUN_00192400(char); /* (unb4) as defined; address taken only */
    char FUN_00192410(char); /* (unb4) as defined; address taken only */
    bool FUN_00192430(void*); /* (unb4) as defined; address taken only */
    char FUN_00192450(int); /* (unb4) as defined; address taken only */
    char FUN_00192470(int); /* (unb4) as defined; address taken only */
    void FUN_00192480();
    char FUN_001924c0(void*); /* (unb4) as defined; address taken only */
    void FUN_001924f0();
    void FUN_00192500();
    char FUN_00192520(int); /* (unb4) as defined; address taken only */
    bool FUN_00192540(int); /* (unb4) as defined; address taken only */
    bool FUN_00192560(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_fdcf800c {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_fdcf800c
namespace fight {
template <class T>
class ParamBool_19c080 : public ParamBoolBase {
public:
    ParamBool_19c080(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamBranch_19c080 : public ParamBranchBase {
public:
    ParamBranch_19c080(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_19c080 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_19c080(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_19c080 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_19c080(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_19c080 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19c080(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_19c080 : public ParamNameBase {
public:
    ParamName_19c080(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_19c080 : public ParamNameConstListBase {
public:
    ParamNameConstList_19c080(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_19c080 : public ParamVectorBase {
public:
    ParamVector_19c080(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fdcf800c {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class TrackFactoryCasterTemplate_19c690 {
  public:
    virtual bool dummy_0019a360(void*);
};
class Obj {
  public:
    void Do_002367c0(void*);
    void Set_002367c0(void*);
};
void* Cast_00236ac0(void*, TrackFactoryCasterTemplate_19c690*);
class TrackFactoryCasterTemplate_19c6c0 {
  public:
    virtual bool cast_0019a400(void*);
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_19c6c0*);
class TrackFactoryCasterTemplate_19c6f0 {
  public:
    virtual bool Cast_0019a480(void*);
};
extern void* Find_00236ac0(void*, TrackFactoryCasterTemplate_19c6f0*);
class TrackFactoryCasterTemplate_19c720 {
  public:
    virtual bool Cast_0019a4e0(void*);
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_19c720*);
class TrackFactoryCasterTemplate_19d130 {
  public:
    virtual bool Cast_0019a5e0(void*);
};
void* Find_00236ac0(const char*, TrackFactoryCasterTemplate_19d130*);
} // namespace fn_fdcf800c
namespace hulkfight { namespace motion {
class FireMissileTrack_19d160 {
public:
    bool FUN_00192f80(int); /* (unb4) as defined; address taken only */
    void FUN_00192f90();
    void FUN_00192fa0();
    void FUN_00192fb0();
    bool FUN_00192fe0(void*); /* (unb4) as defined; address taken only */
    char FUN_00193010(int); /* (unb4) as defined; address taken only */
    void FUN_00193020();
    bool FUN_00193050(void*); /* (unb4) as defined; address taken only */
    bool FUN_00193090(void*); /* (unb4) as defined; address taken only */
    char FUN_001930c0(char); /* (unb4) as defined; address taken only */
    bool FUN_001930e0(int); /* (unb4) as defined; address taken only */
    char FUN_00193100(int); /* (unb4) as defined; address taken only */
    char FUN_00193120(int); /* (unb4) as defined; address taken only */
    char FUN_00193140(float); /* (unb4) as defined; address taken only */
    bool FUN_00193170(int); /* (unb4) as defined; address taken only */
    char FUN_00193190(float); /* (unb4) as defined; address taken only */
    char FUN_001931c0(char); /* (unb4) as defined; address taken only */
    char FUN_001931e0(char); /* (unb4) as defined; address taken only */
    bool FUN_00193200(char); /* (unb4) as defined; address taken only */
    char FUN_00193220(char); /* (unb4) as defined; address taken only */
    char FUN_00193240(int); /* (unb4) as defined; address taken only */
    bool FUN_00193260(int); /* (unb4) as defined; address taken only */
    char FUN_00193280(float); /* (unb4) as defined; address taken only */
    bool FUN_001932b0(float); /* (unb4) as defined; address taken only */
    bool FUN_001932e0(int); /* (unb4) as defined; address taken only */
    bool FUN_00193300(int); /* (unb4) as defined; address taken only */
    bool FUN_00193320(int); /* (unb4) as defined; address taken only */
    char FUN_00193340(char); /* (unb4) as defined; address taken only */
    bool FUN_00193360(char); /* (unb4) as defined; address taken only */
    char FUN_00193380(char); /* (unb4) as defined; address taken only */
    bool FUN_001933a0(int); /* (unb4) as defined; address taken only */
    char FUN_001933c0(float); /* (unb4) as defined; address taken only */
    char FUN_001933f0(int); /* (unb4) as defined; address taken only */
    char FUN_00193410(float); /* (unb4) as defined; address taken only */
    char FUN_00193430(int); /* (unb4) as defined; address taken only */
    bool FUN_00193450(float); /* (unb4) as defined; address taken only */
    bool FUN_00193480(int); /* (unb4) as defined; address taken only */
    char FUN_001934a0(int); /* (unb4) as defined; address taken only */
    char FUN_001934c0(int); /* (unb4) as defined; address taken only */
    void FUN_001934d0();
    void FUN_001934e0();
    bool FUN_00193500(int); /* (unb4) as defined; address taken only */
    char FUN_00193520(int); /* (unb4) as defined; address taken only */
    char FUN_00194510(void*); /* (unb4) as defined; address taken only */
    char FUN_00193550(int); /* (unb4) as defined; address taken only */
    void FUN_00193560();
    char FUN_001935a0(void*); /* (unb4) as defined; address taken only */
    bool FUN_001935e0(int); /* (unb4) as defined; address taken only */
    void FUN_001935f0();
    bool FUN_00193610(int); /* (unb4) as defined; address taken only */
    bool FUN_00193630(int); /* (unb4) as defined; address taken only */
    char FUN_00193650(int); /* (unb4) as defined; address taken only */
    bool FUN_00193690(void*); /* (unb4) as defined; address taken only */
    char FUN_001936d0(int); /* (unb4) as defined; address taken only */
    void FUN_001936e0();
    bool FUN_00193720(void*); /* (unb4) as defined; address taken only */
    bool FUN_00193760(int); /* (unb4) as defined; address taken only */
    bool FUN_00193780(int); /* (unb4) as defined; address taken only */
    char FUN_001937a0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_19d160 : public ParamBoolBase {
public:
    ParamBool_19d160(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamBranch_19d160 : public ParamBranchBase {
public:
    ParamBranch_19d160(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_19d160 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_19d160(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_19d160 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_19d160(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_19d160 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19d160(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_19d160 : public ParamNameBase {
public:
    ParamName_19d160(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_19d160 : public ParamNameConstListBase {
public:
    ParamNameConstList_19d160(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamString_19d160 : public ParamStringBase {
public:
    ParamString_19d160(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_19d160 : public ParamVectorBase {
public:
    ParamVector_19d160(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class FireGroundShockwaveTrack_19de50 {
public:
    char FUN_001937b0(int); /* (unb4) as defined; address taken only */
    bool FUN_001937e0(void*); /* (unb4) as defined; address taken only */
    bool FUN_00193820(void*); /* (unb4) as defined; address taken only */
    char FUN_00193850(int); /* (unb4) as defined; address taken only */
    bool FUN_00193870(int); /* (unb4) as defined; address taken only */
    bool FUN_00193890(int); /* (unb4) as defined; address taken only */
    char FUN_001938b0(int); /* (unb4) as defined; address taken only */
    bool FUN_001938d0(int); /* (unb4) as defined; address taken only */
    char FUN_001938f0(int); /* (unb4) as defined; address taken only */
    void FUN_00193900();
    bool FUN_00193930(void*); /* (unb4) as defined; address taken only */
    bool FUN_00193960(int); /* (unb4) as defined; address taken only */
    bool FUN_00193980(int); /* (unb4) as defined; address taken only */
    bool FUN_001939a0(int); /* (unb4) as defined; address taken only */
    bool FUN_001939c0(int); /* (unb4) as defined; address taken only */
    bool FUN_001939e0(int); /* (unb4) as defined; address taken only */
    bool FUN_00193a00(float); /* (unb4) as defined; address taken only */
    bool FUN_00193a30(int); /* (unb4) as defined; address taken only */
    bool FUN_00193a50(int); /* (unb4) as defined; address taken only */
    bool FUN_00193a70(int); /* (unb4) as defined; address taken only */
    char FUN_00193a90(int); /* (unb4) as defined; address taken only */
    bool FUN_00193ab0(int); /* (unb4) as defined; address taken only */
    char FUN_00193af0(void*); /* (unb4) as defined; address taken only */
    char FUN_00193b50(void*); /* (unb4) as defined; address taken only */
    void FUN_00193b80();
    void FUN_00193b90();
};
} }
namespace fight {
template <class T>
class ParamBranch_19de50 : public ParamBranchBase {
public:
    ParamBranch_19de50(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_19de50 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_19de50(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_19de50 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_19de50(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_19de50 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19de50(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_19de50 : public ParamNameBase {
public:
    ParamName_19de50(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_19de50 : public ParamVectorBase {
public:
    ParamVector_19de50(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fdcf800c {
struct CasterA {
    CasterA() {}
    virtual bool Cast_0019a180(void*);
};
struct CasterB {
    CasterB() {}
    virtual bool Cast_0019a1e0(void*);
};
extern "C" void* __cdecl FUN_002343e0(const char*, void*);
class Registry {
  public:
    void Add_00236760(void*);
};


// 0x0019c050 FUN_0019c050 (38 B): matches/0x0019c050.cpp
// sym: _FUN_0019c050
extern "C" void FUN_0019c050(Owner* owner, void* value) {
    TrackFactoryCasterTemplate_19c050 caster;
    owner->Apply_002367c0(Lookup(value, &caster));
}


// 0x0019c080 FUN_0019c080 (1547 B): equivalent/0x0019c080.cpp
// sym: ?FUN_0019c080@fn_fdcf800c@@YAXXZ @dab271606ee1 @w4c0f7ee42285
// STATUS: equivalent (tools/equiv.py level 3: 1655 inputs, branch coverage 60/60)
// FUN_0019c080 @ 0x0019c080
void FUN_0019c080()
{
    if (DAT_004e155c == 0) {
        void* params[29];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("timeBegin", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192190);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("timeEnd", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_001921a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_19c080<hulkfight::motion::FireProjectileTrack_19c080>("effect", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001921b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>("effectAxis", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_001921e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("rateOfFire", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192210);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("originAttachment", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192230);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamNameConstList_19c080<hulkfight::motion::FireProjectileTrack_19c080>("originJoint", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192240);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>("originOffset", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192270);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>("direction", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_001922b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("spread", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_001922e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("initVelocity", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192310);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("maxVelocity", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192330);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("acceleration", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192350);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("targetArc", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192370);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("targetDistance", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_001923a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("tracking", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_001923c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_19c080<hulkfight::motion::FireProjectileTrack_19c080>("trackInitLockon", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_001923f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBool_19c080<hulkfight::motion::FireProjectileTrack_19c080>("usesFirstShotFailureOnTracking", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192400);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamBool_19c080<hulkfight::motion::FireProjectileTrack_19c080>("ifFirstShotFailureUsesInitLockon", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192410);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("lifeTime", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192430);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamIntConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("projectilePriority", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192450);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamIntConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("interruptPriority", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192470);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamName_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitEffect", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192480);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitEffectAxis", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_001924c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamBranch_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitBranch", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001924f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamBranch_19c080<hulkfight::motion::FireProjectileTrack_19c080>("giverBranch", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192500);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitPropDamage", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192520);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitPropForce", (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192540);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_19c080<hulkfight::motion::FireProjectileTrack_19c080>));
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamEnumConstList_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitDamageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), (void (hulkfight::motion::FireProjectileTrack_19c080::*)())&hulkfight::motion::FireProjectileTrack_19c080::FUN_00192560);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1558), params, 29);
    }
    DAT_004e155c++;
}


// 0x0019c690 FUN_0019c690 (38 B): matches/0x0019c690.cpp
// sym: _FUN_0019c690
extern "C" void FUN_0019c690(Obj* obj, void* p) {
    TrackFactoryCasterTemplate_19c690 c;
    obj->Do_002367c0(Cast_00236ac0(p, &c));
}


// 0x0019c6c0 FUN_0019c6c0 (38 B): matches/0x0019c6c0.cpp
// sym: _FUN_0019c6c0
extern "C" void FUN_0019c6c0(Obj* a, void* b) {
    TrackFactoryCasterTemplate_19c6c0 c;
    void* p = Find_00236ac0(b, &c);
    a->Do_002367c0(p);
}


// 0x0019c6f0 FUN_0019c6f0 (38 B): matches/0x0019c6f0.cpp
// sym: _FUN_0019c6f0
extern "C" void FUN_0019c6f0(Obj* o, void* name) {
    TrackFactoryCasterTemplate_19c6f0 c;
    void* p = Find_00236ac0(name, &c);
    o->Set_002367c0(p);
}


// 0x0019c720 FUN_0019c720 (38 B): matches/0x0019c720.cpp
// sym: _FUN_0019c720
extern "C" void __cdecl FUN_0019c720(Obj* obj, void* arg) {
    TrackFactoryCasterTemplate_19c720 caster;
    void* p = Find_00236ac0(arg, &caster);
    obj->Set_002367c0(p);
}


// 0x0019d130 FUN_0019d130 (38 B): matches/0x0019d130.cpp
// sym: _FUN_0019d130
extern "C" void FUN_0019d130(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_19d130 caster;
    owner->Set_002367c0(Find_00236ac0(name, &caster));
}


// 0x0019d160 FUN_0019d160 (3259 B): equivalent/0x0019d160.cpp
// sym: _FUN_0019d160 @cf29edf97144 @w3b0c565fd03c
// STATUS: equivalent (tools/equiv.py level 3: 918 inputs, branch coverage 120/120)
// FUN_0019d160 @ 0x0019d160
extern "C" void FUN_0019d160()
{
    if (DAT_004e1584 == 0) {
        void* params[59];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("timeBegin", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00192f80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("propName", &hulkfight::motion::FireMissileTrack_19d160::FUN_00192f90);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("propInitState", &hulkfight::motion::FireMissileTrack_19d160::FUN_00192fa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("propHitState", &hulkfight::motion::FireMissileTrack_19d160::FUN_00192fb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("propAxis", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00192fe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("originAttachment", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193010);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamNameConstList_19d160<hulkfight::motion::FireMissileTrack_19d160>("originJoint", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193020);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("originOffset", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193050);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("direction", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193090);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("inheritVelocityFromCharacter", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001930c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("initVelocity", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001930e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("maxVelocity", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193100);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("acceleration", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193120);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("targetArc", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193140);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("targetDistance", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193170);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("tracking", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193190);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("trackInitLockon", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001931c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("usesFirstShotFailureOnTracking", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001931e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("ifFirstShotFailureUsesInitLockon", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193200);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("sway", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193220);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayTimeBegin", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193240);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayTimeDuration", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193260);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAngle", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193280);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAnglePerFrameReduction", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001932b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayResetTime", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001932e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayResetTimeScaler", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193300);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swaySideStart", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193320);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("swaySideStartRandom", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193340);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("swaySideSkipZero", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193360);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("swaySideNextRandom", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193380);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayThresholdDistance", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001933a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAfterDurationTracking", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001933c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAfterDurationTrackingTime", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001933f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[33] = 0;
        if (mem)
            params[33] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAfterThresholdTracking", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193410);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[34] = 0;
        if (mem)
            params[34] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAfterThresholdTrackingTime", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193430);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[35] = 0;
        if (mem)
            params[35] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayDuringSwayTracking", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193450);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[36] = 0;
        if (mem)
            params[36] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("lifeTime", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193480);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[37] = 0;
        if (mem)
            params[37] = new (mem) fight::ParamIntConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("projectilePriority", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001934a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[38] = 0;
        if (mem)
            params[38] = new (mem) fight::ParamIntConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("interruptPriority", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001934c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[39] = 0;
        if (mem)
            params[39] = new (mem) fight::ParamBranch_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitBranch", &hulkfight::motion::FireMissileTrack_19d160::FUN_001934d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[40] = 0;
        if (mem)
            params[40] = new (mem) fight::ParamBranch_19d160<hulkfight::motion::FireMissileTrack_19d160>("giverBranch", &hulkfight::motion::FireMissileTrack_19d160::FUN_001934e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[41] = 0;
        if (mem)
            params[41] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitPropDamage", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193500);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[42] = 0;
        if (mem)
            params[42] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitPropForce", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193520);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[43] = 0;
        if (mem)
            params[43] = new (mem) fight::ParamString_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitPropSound", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00194510);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[44] = 0;
        if (mem)
            params[44] = new (mem) fight::ParamEnumConstList_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitDamageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193550);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[45] = 0;
        if (mem)
            params[45] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionEffect", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193560);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[46] = 0;
        if (mem)
            params[46] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionEffectAxis", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001935a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[47] = 0;
        if (mem)
            params[47] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionRadius", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001935e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[48] = 0;
        if (mem)
            params[48] = new (mem) fight::ParamBranch_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionHitBranch", &hulkfight::motion::FireMissileTrack_19d160::FUN_001935f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[49] = 0;
        if (mem)
            params[49] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionHitPropDamage", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193610);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[50] = 0;
        if (mem)
            params[50] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionHitPropForce", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193630);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[51] = 0;
        if (mem)
            params[51] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailWidth", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193650);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[52] = 0;
        if (mem)
            params[52] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailOffset", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193690);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[53] = 0;
        if (mem)
            params[53] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailFadeOutTime", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001936d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[54] = 0;
        if (mem)
            params[54] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailShader", &hulkfight::motion::FireMissileTrack_19d160::FUN_001936e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[55] = 0;
        if (mem)
            params[55] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailShrinkOffset", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193720);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[56] = 0;
        if (mem)
            params[56] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailShrinkTime", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193760);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[57] = 0;
        if (mem)
            params[57] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailFadeTime", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_00193780);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>));
        params[58] = 0;
        if (mem)
            params[58] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailTextureTime", (void (hulkfight::motion::FireMissileTrack_19d160::*)())&hulkfight::motion::FireMissileTrack_19d160::FUN_001937a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1580), params, 59);
    }
    DAT_004e1584++;
}

} // namespace fn_fdcf800c

// 0x0019de20 FUN_0019de20 (38 B): matches/0x0019de20.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: _FUN_0019de20
namespace fn_0019de20 {
namespace fight {
class TrackFactoryCasterTemplate {
  public:
    virtual bool Cast_0019a700(void*);
};
} // namespace fight
class Obj {
  public:
    void Use_002367c0(void*);
};
void* Find_00236ac0(void*, fight::TrackFactoryCasterTemplate*);
extern "C" void FUN_0019de20(Obj* obj, void* value) {
    fight::TrackFactoryCasterTemplate caster;
    void* found = Find_00236ac0(value, &caster);
    obj->Use_002367c0(found);
}
} // namespace fn_0019de20

namespace fn_fdcf800c {

// 0x0019de50 FUN_0019de50 (1412 B): equivalent/0x0019de50.cpp
// sym: _FUN_0019de50 @7cb090194c68 @w29bf4743fe2f
// STATUS: equivalent (tools/equiv.py level 3: 1980 inputs, branch coverage 54/54)
// FUN_0019de50 @ 0x0019de50
extern "C" void FUN_0019de50()
{
    if ((*(int*)&DAT_004e158c) == 0) {
        void* params[26];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("timeBegin", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001937b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("origin", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001937e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("direction", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193820);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("distance", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193850);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("lifeTime", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193870);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("projectilePriority", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193890);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("radius", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001938b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("maxAffectedHeight", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001938d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("maxYChange", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001938f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("effect", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193900);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("effectAxis", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193930);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamEnumConstList_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("decalDamageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193960);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("decalScale", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193980);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("decalDistance", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001939a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamEnumConstList_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneDamageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001939c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneRadius", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001939e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneArc", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a00);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamIntConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneDecalCount", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneDecalScale", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a50);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamIntConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("interruptPriority", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("damage", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("damageMax", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193ab0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("force", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193af0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("forceMax", (void (hulkfight::motion::FireGroundShockwaveTrack_19de50::*)())&hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193b50);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamBranch_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("hitBranch", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193b80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamName_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("hitEffect", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193b90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1588), params, 26);
    }
    (*(int*)&DAT_004e158c)++;
}


// 0x0019e3e0 FUN_0019e3e0 (77 B): matches/0x0019e3e0.cpp
// sym: _FUN_0019e3e0
extern "C" void __cdecl FUN_0019e3e0(Registry* reg) {
    int slot;
    CasterA* a = reinterpret_cast<CasterA*>(&slot);
    a->CasterA::CasterA();
    reg->Add_00236760(FUN_002343e0(DAT_0041c1b0, a));
    CasterB* b = reinterpret_cast<CasterB*>(&slot);
    b->CasterB::CasterB();
    reg->Add_00236760(FUN_002343e0(DAT_0041c1a0, b));
}

} // namespace fn_fdcf800c
