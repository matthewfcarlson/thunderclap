// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00199630..0x0019e430 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/FireProjectileAction.cpp
// piece 0x0019c050..0x0019e430 (kind game, layer game, confidence low); was game/unknown/unk_19c050.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fdcf800c {
#define TREE_TU_END }
namespace fn_fdcf800c {} using namespace fn_fdcf800c;
#include "game/unknown.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_00192c40 { struct In; } 
namespace fn_00192ca0 { struct Vec3; } 
namespace fn_00193690 { struct Vec3; } 
namespace fn_001937e0 { struct Vec; } 
namespace fn_00193b50 { struct Src; } 
namespace fn_fa51549e { struct Data_192a60; } 
namespace fn_fa51549e { struct Inner_1924f0; } 
namespace fn_fa51549e { struct Inner_193b90; } 
namespace fn_fa51549e { struct S_192910; } 
namespace fn_fa51549e { struct Src; } 
namespace fn_fa51549e { struct Src_1921e0; } 
namespace fn_fa51549e { struct Src_1928d0; } 
namespace fn_fa51549e { struct Src_193090; } 
namespace fn_fa51549e { struct Src_193820; } 
namespace fn_fa51549e { struct Sub_1921b0; } 
namespace fn_fa51549e { struct Sub_192b90; } 
namespace fn_fa51549e { struct T; } 
namespace fn_fa51549e { struct Triple; } 
namespace fn_fa51549e { struct Vec3; } 
namespace fn_fa51549e { struct Vec3_192270; } 
namespace fn_fa51549e { struct Vec3_193050; } 
namespace fn_fa51549e { struct Vec3_193930; } 
namespace fn_fa51549e { struct Vec; } 
namespace fn_00192c40 { struct Obj { bool Set(struct fn_00192c40::In *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_00192ca0 { struct Obj { bool Set(struct fn_00192ca0::Vec3 const *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_00193690 { struct Obj { bool Set(struct fn_00193690::Vec3 *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_001937e0 { struct Obj { bool Set(struct fn_001937e0::Vec const &); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_00193b50 { struct Obj { unsigned char Set(struct fn_00193b50::Src *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Base_1932b0 { bool SetRadians(float); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Item_1936e0 { void * f(); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct O { bool Set(struct fn_fa51549e::T *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj { bool Set(struct fn_fa51549e::Src *); bool Set(struct fn_fa51549e::Vec3 const *); char Set(struct fn_fa51549e::Vec const &); char Set(struct fn_fa51549e::Vec3 *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_1921b0 { struct fn_fa51549e::Sub_1921b0 * Get(); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_1921e0 { bool Set(struct fn_fa51549e::Src_1921e0 *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_192270 { bool Set(struct fn_fa51549e::Vec3_192270 *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_1924f0 { struct fn_fa51549e::Inner_1924f0 * Get(); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_1928d0 { char Set(struct fn_fa51549e::Src_1928d0 *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_193050 { bool Set(struct fn_fa51549e::Vec3_193050 const *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_193090 { bool Set(struct fn_fa51549e::Src_193090 *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_193820 { bool Set(struct fn_fa51549e::Src_193820 const *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_193930 { bool Set(struct fn_fa51549e::Vec3_193930 const *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Obj_193b90 { struct fn_fa51549e::Inner_193b90 * GetBody(); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Owner_192a60 { bool Set(struct fn_fa51549e::Data_192a60 *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Owner_192fe0 { bool Assign(struct fn_fa51549e::Triple *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct T_192910 { char Fn(struct fn_fa51549e::S_192910 *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Target { char Fn(struct fn_fa51549e::Src *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Target_192b90 { struct fn_fa51549e::Sub_192b90 * Get(); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp
namespace fn_fa51549e { struct Tgt { bool Copy(struct fn_fa51549e::Src *); }; }   // (gx3, D18) setters, as defined in unk_192030.cpp

// ---- declarations shared by the functions below
namespace fn_fdcf800c {
extern "C" char DAT_0041b990[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::FireProjectileTrack>::vftable
struct TrackFactoryCasterTemplate_19c050 {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
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
extern "C" char DAT_0041b99c[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::MissileThrowTrack>::vftable
struct TrackFactoryCasterTemplate_19c690 {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
};
class Obj {
  public:
    void Do_002367c0(void*);
    void Set_002367c0(void*);
};
void* Cast_00236ac0(void*, TrackFactoryCasterTemplate_19c690*);
extern "C" char DAT_0041b9a8[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::MissilePunchTrack>::vftable
struct TrackFactoryCasterTemplate_19c6c0 {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_19c6c0*);
extern "C" char DAT_0041b9b4[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::AccuracyLatencyTrack>::vftable
struct TrackFactoryCasterTemplate_19c6f0 {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
};
extern void* Find_00236ac0(void*, TrackFactoryCasterTemplate_19c6f0*);
extern "C" char DAT_0041b9c0[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::FireBeamTrack>::vftable
struct TrackFactoryCasterTemplate_19c720 {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_19c720*);
extern "C" char DAT_0041b9cc[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::FireMissileTrack>::vftable
struct TrackFactoryCasterTemplate_19d130 {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
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


} // namespace fn_fdcf800c

// 0x0019a290 fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a290.cpp
// sym: ??_G?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a2b0 fight::ParamVector<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a2b0.cpp
// sym: ??_G?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a2d0 fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a2d0.cpp
// sym: ??_G?$ParamIntConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a2f0 fight::ParamBool<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a2f0.cpp
// sym: ??_G?$ParamBool@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a310 fight::ParamBranch<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a310.cpp
// sym: ??_G?$ParamBranch@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a330 fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a330.cpp
// sym: ??_G?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a510 fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a510.cpp
// sym: ??_G?$ParamFloatConstRange@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a530 fight::ParamVector<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a530.cpp
// sym: ??_G?$ParamVector@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a550 fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a550.cpp
// sym: ??_G?$ParamIntConstRange@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a570 fight::ParamBool<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a570.cpp
// sym: ??_G?$ParamBool@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)

namespace fn_fdcf800c {


} // namespace fn_fdcf800c

// 0x0019a590 fight::ParamBranch<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a590.cpp
// sym: ??_G?$ParamBranch@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a5b0 fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a5b0.cpp
// sym: ??_G?$ParamEnumConstList@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a610 fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a610.cpp
// sym: ??_G?$ParamFloatConstRange@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a630 fight::ParamVector<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a630.cpp
// sym: ??_G?$ParamVector@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a650 fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a650.cpp
// sym: ??_G?$ParamIntConstRange@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a670 fight::ParamBool<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a670.cpp
// sym: ??_G?$ParamBool@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)

namespace fn_fdcf800c {


} // namespace fn_fdcf800c

// 0x0019a690 fight::ParamBranch<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a690.cpp
// sym: ??_G?$ParamBranch@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a6b0 fight::ParamString<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a6b0.cpp
// sym: ??_G?$ParamString@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a6d0 fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a6d0.cpp
// sym: ??_G?$ParamEnumConstList@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a730 fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a730.cpp
// sym: ??_G?$ParamFloatConstRange@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a750 fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a750.cpp
// sym: ??_G?$ParamVector@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a770 fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a770.cpp
// sym: ??_G?$ParamIntConstRange@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a790 fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a790.cpp
// sym: ??_G?$ParamEnumConstList@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019a7b0 fight::ParamBranch<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a7b0.cpp
// sym: ??_G?$ParamBranch@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)

namespace fn_fdcf800c {


} // namespace fn_fdcf800c

// 0x0019bf10 fight::ParamName<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019bf10.cpp
// sym: ??_G?$ParamName@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019bf30 fight::ParamNameConstList<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019bf30.cpp
// sym: ??_G?$ParamNameConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019bf50 fight::ParamName<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019bf50.cpp
// sym: ??_G?$ParamName@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)

namespace fn_fdcf800c {


} // namespace fn_fdcf800c

// 0x0019bf70 fight::ParamNameConstList<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019bf70.cpp
// sym: ??_G?$ParamNameConstList@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019bf90 fight::ParamName<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019bf90.cpp
// sym: ??_G?$ParamName@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019bfb0 fight::ParamNameConstList<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019bfb0.cpp
// sym: ??_G?$ParamNameConstList@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)



// 0x0019bfd0 fight::ParamName<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019bfd0.cpp
// sym: ??_G?$ParamName@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FireProjectileAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0019c080 / FUN_0019c750 / FUN_0019d160 / FUN_0019de50)

namespace fn_fdcf800c {


// 0x0019c050 FUN_0019c050 (38 B): matches/0x0019c050.cpp
// sym: _FUN_0019c050
extern "C" void FUN_0019c050(Owner* owner, void* value) {
    TrackFactoryCasterTemplate_19c050 caster;
    caster.vftable = (void*)DAT_0041b990;   // (sweep-caster-fix1) the game's vftable by address
    owner->Apply_002367c0(Lookup(value, &caster));
}


} // namespace fn_fdcf800c

// 0x0019c080 FUN_0019c080 (1547 B): matches/0x0019c080.cpp
// sym: ?FUN_0019c080@@YAXXZ
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::FireProjectileTrack>, ParamBranch<hulkfight::motion::FireProjectileTrack>, ParamEnumConstList<hulkfight::motion::FireProjectileTrack>, ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>, ParamIntConstRange<hulkfight::motion::FireProjectileTrack>, ParamName<hulkfight::motion::FireProjectileTrack>, ParamNameConstList<hulkfight::motion::FireProjectileTrack>, ParamVector<hulkfight::motion::FireProjectileTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_0019c080()
{
    if (DAT_004e155c == 0) {
        ::fight::ParamValue* params[29];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("timeBegin", &owners::X_192190::FUN_00192190);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("timeEnd", &owners::C_1921a0::FUN_001921a0);
        params[2] = new ::fight::ParamName< ::hulkfight::motion::FireProjectileTrack>("effect", &fn_fa51549e::Obj_1921b0::Get);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::FireProjectileTrack>("effectAxis", &fn_fa51549e::Obj_1921e0::Set);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("rateOfFire", &owners::Obj_192210::FUN_00192210);
        params[5] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireProjectileTrack>("originAttachment", &owners::Obj_192230::FUN_00192230);
        params[6] = new ::fight::ParamNameConstList< ::hulkfight::motion::FireProjectileTrack>("originJoint", &owners::X_192240::FUN_00192240);
        params[7] = new ::fight::ParamVector< ::hulkfight::motion::FireProjectileTrack>("originOffset", &fn_fa51549e::Obj_192270::Set);
        params[8] = new ::fight::ParamVector< ::hulkfight::motion::FireProjectileTrack>("direction", &owners::Obj_1922b0::FUN_001922b0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("spread", &owners::Target_1922e0::FUN_001922e0);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("initVelocity", &owners::X_192310::FUN_00192310);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("maxVelocity", &owners::Obj_192330::FUN_00192330);
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("acceleration", &owners::Obj_192350::FUN_00192350);
        params[13] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("targetArc", &owners::Obj_192370::FUN_00192370);
        params[14] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("targetDistance", &owners::X_1923a0::FUN_001923a0);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("tracking", &owners::X_1923c0::FUN_001923c0);
        params[16] = new ::fight::ParamBool< ::hulkfight::motion::FireProjectileTrack>("trackInitLockon", &owners::Obj_1923f0::FUN_001923f0);
        params[17] = new ::fight::ParamBool< ::hulkfight::motion::FireProjectileTrack>("usesFirstShotFailureOnTracking", &owners::Obj_192400::FUN_00192400);
        params[18] = new ::fight::ParamBool< ::hulkfight::motion::FireProjectileTrack>("ifFirstShotFailureUsesInitLockon", &owners::Obj_192410::FUN_00192410);
        params[19] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("lifeTime", &owners::X_192430::FUN_00192430);
        params[20] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireProjectileTrack>("projectilePriority", &owners::Obj_192450::FUN_00192450);
        params[21] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireProjectileTrack>("interruptPriority", &owners::X_192470::FUN_00192470);
        params[22] = new ::fight::ParamName< ::hulkfight::motion::FireProjectileTrack>("hitEffect", &owners::Obj_192480::FUN_00192480);
        params[23] = new ::fight::ParamVector< ::hulkfight::motion::FireProjectileTrack>("hitEffectAxis", static_cast<char (fn_fa51549e::Obj::*)(struct fn_fa51549e::Vec3 *)>(&fn_fa51549e::Obj::Set));
        params[24] = new ::fight::ParamBranch< ::hulkfight::motion::FireProjectileTrack>("hitBranch", &fn_fa51549e::Obj_1924f0::Get);
        params[25] = new ::fight::ParamBranch< ::hulkfight::motion::FireProjectileTrack>("giverBranch", &owners::Obj_192500::FUN_00192500);
        params[26] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("hitPropDamage", &owners::Obj_192520::FUN_00192520);
        params[27] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireProjectileTrack>("hitPropForce", &owners::A_192540::FUN_00192540);
        params[28] = new ::fight::ParamEnumConstList< ::hulkfight::motion::FireProjectileTrack>("hitDamageType", (void*)&DAT_004ad788, DAT_00412ed4, &owners::C_192560::FUN_00192560);
        FUN_002347b0(&DAT_004e1558, params, 29);
    }
    DAT_004e155c++;
}

namespace fn_fdcf800c {


// 0x0019c690 FUN_0019c690 (38 B): matches/0x0019c690.cpp
// sym: _FUN_0019c690
extern "C" void FUN_0019c690(Obj* obj, void* p) {
    TrackFactoryCasterTemplate_19c690 c;
    c.vftable = (void*)DAT_0041b99c;   // (sweep-caster-fix1) the game's vftable by address
    obj->Do_002367c0(Cast_00236ac0(p, &c));
}


// 0x0019c6c0 FUN_0019c6c0 (38 B): matches/0x0019c6c0.cpp
// sym: _FUN_0019c6c0
extern "C" void FUN_0019c6c0(Obj* a, void* b) {
    TrackFactoryCasterTemplate_19c6c0 c;
    c.vftable = (void*)DAT_0041b9a8;   // (sweep-caster-fix1) the game's vftable by address
    void* p = Find_00236ac0(b, &c);
    a->Do_002367c0(p);
}


// 0x0019c6f0 FUN_0019c6f0 (38 B): matches/0x0019c6f0.cpp
// sym: _FUN_0019c6f0
extern "C" void FUN_0019c6f0(Obj* o, void* name) {
    TrackFactoryCasterTemplate_19c6f0 c;
    c.vftable = (void*)DAT_0041b9b4;   // (sweep-caster-fix1) the game's vftable by address
    void* p = Find_00236ac0(name, &c);
    o->Set_002367c0(p);
}


// 0x0019c720 FUN_0019c720 (38 B): matches/0x0019c720.cpp
// sym: _FUN_0019c720
extern "C" void __cdecl FUN_0019c720(Obj* obj, void* arg) {
    TrackFactoryCasterTemplate_19c720 caster;
    caster.vftable = (void*)DAT_0041b9c0;   // (sweep-caster-fix1) the game's vftable by address
    void* p = Find_00236ac0(arg, &caster);
    obj->Set_002367c0(p);
}


} // namespace fn_fdcf800c

// 0x0019c750 FUN_0019c750 (2518 B): matches/0x0019c750.cpp
// sym: ?FUN_0019c750@@YAXXZ
// (gx2, D18) from unk_19c050.iso_0019c750.cpp; constructs the real ParamBool<hulkfight::motion::FireBeamTrack>, ParamBranch<hulkfight::motion::FireBeamTrack>, ParamEnumConstList<hulkfight::motion::FireBeamTrack>, ParamFloatConstRange<hulkfight::motion::FireBeamTrack>, ParamIntConstRange<hulkfight::motion::FireBeamTrack>, ParamName<hulkfight::motion::FireBeamTrack>, ParamNameConstList<hulkfight::motion::FireBeamTrack>, ParamVector<hulkfight::motion::FireBeamTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_0019c750()
{
    if (DAT_004e157c == 0) {
        ::fight::ParamValue* params[46];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("timeBegin", &owners::Obj_192830::FUN_00192830);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("timeEnd", &owners::Obj_192840::FUN_00192840);
        params[2] = new ::fight::ParamName< ::hulkfight::motion::FireBeamTrack>("effect", &owners::Obj_192850::FUN_00192850);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("effectAxis", static_cast<char (fn_fa51549e::Obj::*)(struct fn_fa51549e::Vec const &)>(&fn_fa51549e::Obj::Set));
        params[4] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireBeamTrack>("originAttachment", &owners::Obj_192890::FUN_00192890);
        params[5] = new ::fight::ParamNameConstList< ::hulkfight::motion::FireBeamTrack>("originJoint", &owners::Obj_1928a0::FUN_001928a0);
        params[6] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("originOffset", &fn_fa51549e::Obj_1928d0::Set);
        params[7] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("direction", &fn_fa51549e::T_192910::Fn);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("maxLength", &owners::Thing_192940::FUN_00192940);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("targetArc", &owners::Obj_192960::FUN_00192960);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("targetDistance", &owners::Obj_192990::FUN_00192990);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("tracking", &owners::Obj_1929b0::FUN_001929b0);
        params[12] = new ::fight::ParamBool< ::hulkfight::motion::FireBeamTrack>("trackInitLockon", &owners::X_1929e0::FUN_001929e0);
        params[13] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("lifeTime", &owners::Obj_192a00::FUN_00192a00);
        params[14] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireBeamTrack>("interruptPriority", &owners::Obj_192a20::FUN_00192a20);
        params[15] = new ::fight::ParamName< ::hulkfight::motion::FireBeamTrack>("hitEffect", &owners::Thing_192a30::FUN_00192a30);
        params[16] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("hitEffectAxis", &fn_fa51549e::Owner_192a60::Set);
        params[17] = new ::fight::ParamBranch< ::hulkfight::motion::FireBeamTrack>("hitBranch", &owners::Obj_192a80::FUN_00192a80);
        params[18] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("hitPropDamage", &owners::C_192aa0::FUN_00192aa0);
        params[19] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("hitDamage", &owners::Obj_192ac0::FUN_00192ac0);
        params[20] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("hitSameAlignmentDamageFactor", &owners::Obj_192ae0::FUN_00192ae0);
        params[21] = new ::fight::ParamBool< ::hulkfight::motion::FireBeamTrack>("hitBranchOnlyOnSameAlignment", &owners::Obj_192b00::FUN_00192b00);
        params[22] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("hitPropForce", &owners::X_192b20::FUN_00192b20);
        params[23] = new ::fight::ParamEnumConstList< ::hulkfight::motion::FireBeamTrack>("hitDamageType", (void*)&DAT_004ad788, DAT_00412ed4, &owners::Obj_192b40::FUN_00192b40);
        params[24] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("hitTraceWidth", &owners::C_192b60::FUN_00192b60);
        params[25] = new ::fight::ParamBool< ::hulkfight::motion::FireBeamTrack>("ignoreCollisionOnSameAlignment", &owners::O_192b80::FUN_00192b80);
        params[26] = new ::fight::ParamBranch< ::hulkfight::motion::FireBeamTrack>("giverBranch", &fn_fa51549e::Target_192b90::Get);
        params[27] = new ::fight::ParamName< ::hulkfight::motion::FireBeamTrack>("propName", &owners::Obj_192ba0::FUN_00192ba0);
        params[28] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("initialAbsoluteOffset", static_cast<bool (fn_fa51549e::Obj::*)(struct fn_fa51549e::Vec3 const *)>(&fn_fa51549e::Obj::Set));
        params[29] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("initialRandomOffset", &fn_00192c40::Obj::Set);
        params[30] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("initialRelativeOffset", &fn_00192ca0::Obj::Set);
        params[31] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("initialPositionScaler", &owners::Obj_192ce0::FUN_00192ce0);
        params[32] = new ::fight::ParamBool< ::hulkfight::motion::FireBeamTrack>("catchUpUseSweep", &owners::X_192d00::FUN_00192d00);
        params[33] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("catchUpSweepAngle", &owners::Obj_192d20::FUN_00192d20);
        params[34] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("catchUpSweepAngleDirection", &owners::X_192d50::FUN_00192d50);
        params[35] = new ::fight::ParamBool< ::hulkfight::motion::FireBeamTrack>("catchUpSweepAngleRandomDirection", &owners::Obj_192d70::FUN_00192d70);
        params[36] = new ::fight::ParamBool< ::hulkfight::motion::FireBeamTrack>("catchUpHulkDynamic", &owners::Obj_192d90::FUN_00192d90);
        params[37] = new ::fight::ParamBool< ::hulkfight::motion::FireBeamTrack>("catchUpHulkVelocity", &owners::X_192db0::FUN_00192db0);
        params[38] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("catchUpAbsoluteOffset", &owners::C_192df0::FUN_00192df0);
        params[39] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("catchUpRandomOffset", static_cast<bool (fn_fa51549e::Obj::*)(struct fn_fa51549e::Src *)>(&fn_fa51549e::Obj::Set));
        params[40] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("catchUpDistanceScaler", &owners::Obj_192e90::FUN_00192e90);
        params[41] = new ::fight::ParamVector< ::hulkfight::motion::FireBeamTrack>("catchUpRelativeOffset", &fn_fa51549e::Tgt::Copy);
        params[42] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("catchUpIncrementScaler", &owners::Obj_192f10::FUN_00192f10);
        params[43] = new ::fight::ParamBool< ::hulkfight::motion::FireBeamTrack>("catchUpByEndOfTrack", &owners::Obj_192f30::FUN_00192f30);
        params[44] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("catchUpMultiplier", &owners::Target_192f50::FUN_00192f50);
        params[45] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireBeamTrack>("catchUpPercentage", &owners::Obj_192f70::FUN_00192f70);
        FUN_002347b0(&DAT_004e1578, params, 46);
    }
    DAT_004e157c++;
}

namespace fn_fdcf800c {


// 0x0019d130 FUN_0019d130 (38 B): matches/0x0019d130.cpp
// sym: _FUN_0019d130
extern "C" void FUN_0019d130(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_19d130 caster;
    caster.vftable = (void*)DAT_0041b9cc;   // (sweep-caster-fix1) the game's vftable by address
    owner->Set_002367c0(Find_00236ac0(name, &caster));
}


} // namespace fn_fdcf800c

// 0x0019d160 FUN_0019d160 (3259 B): matches/0x0019d160.cpp
// sym: _FUN_0019d160
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::FireMissileTrack>, ParamBranch<hulkfight::motion::FireMissileTrack>, ParamEnumConstList<hulkfight::motion::FireMissileTrack>, ParamFloatConstRange<hulkfight::motion::FireMissileTrack>, ParamIntConstRange<hulkfight::motion::FireMissileTrack>, ParamName<hulkfight::motion::FireMissileTrack>, ParamNameConstList<hulkfight::motion::FireMissileTrack>, ParamString<hulkfight::motion::FireMissileTrack>, ParamVector<hulkfight::motion::FireMissileTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0019d160()
{
    if (DAT_004e1584 == 0) {
        ::fight::ParamValue* params[59];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("timeBegin", &owners::Obj_192f80::FUN_00192f80);
        params[1] = new ::fight::ParamName< ::hulkfight::motion::FireMissileTrack>("propName", &owners::Obj_192f90::FUN_00192f90);
        params[2] = new ::fight::ParamName< ::hulkfight::motion::FireMissileTrack>("propInitState", &owners::Obj_192fa0::FUN_00192fa0);
        params[3] = new ::fight::ParamName< ::hulkfight::motion::FireMissileTrack>("propHitState", &owners::Obj_192fb0::FUN_00192fb0);
        params[4] = new ::fight::ParamVector< ::hulkfight::motion::FireMissileTrack>("propAxis", &fn_fa51549e::Owner_192fe0::Assign);
        params[5] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireMissileTrack>("originAttachment", &owners::Obj_193010::FUN_00193010);
        params[6] = new ::fight::ParamNameConstList< ::hulkfight::motion::FireMissileTrack>("originJoint", &owners::Obj_193020::FUN_00193020);
        params[7] = new ::fight::ParamVector< ::hulkfight::motion::FireMissileTrack>("originOffset", &fn_fa51549e::Obj_193050::Set);
        params[8] = new ::fight::ParamVector< ::hulkfight::motion::FireMissileTrack>("direction", &fn_fa51549e::Obj_193090::Set);
        params[9] = new ::fight::ParamBool< ::hulkfight::motion::FireMissileTrack>("inheritVelocityFromCharacter", &owners::Obj_1930c0::FUN_001930c0);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("initVelocity", &owners::Obj_1930e0::FUN_001930e0);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("maxVelocity", &owners::Obj_193100::FUN_00193100);
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("acceleration", &owners::Obj_193120::FUN_00193120);
        params[13] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("targetArc", &owners::Obj_193140::FUN_00193140);
        params[14] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("targetDistance", &owners::Obj_193170::FUN_00193170);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("tracking", &owners::Thing_193190::FUN_00193190);
        params[16] = new ::fight::ParamBool< ::hulkfight::motion::FireMissileTrack>("trackInitLockon", &owners::X_1931c0::FUN_001931c0);
        params[17] = new ::fight::ParamBool< ::hulkfight::motion::FireMissileTrack>("usesFirstShotFailureOnTracking", &owners::Sub_1931e0::FUN_001931e0);
        params[18] = new ::fight::ParamBool< ::hulkfight::motion::FireMissileTrack>("ifFirstShotFailureUsesInitLockon", &owners::Obj_193200::FUN_00193200);
        params[19] = new ::fight::ParamBool< ::hulkfight::motion::FireMissileTrack>("sway", &owners::Obj_193220::FUN_00193220);
        params[20] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayTimeBegin", &owners::X_193240::FUN_00193240);
        params[21] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayTimeDuration", &owners::Obj_193260::FUN_00193260);
        params[22] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayAngle", &owners::Obj_193280::FUN_00193280);
        params[23] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayAnglePerFrameReduction", &fn_fa51549e::Base_1932b0::SetRadians);
        params[24] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayResetTime", &owners::Obj_1932e0::FUN_001932e0);
        params[25] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayResetTimeScaler", &owners::Obj_193300::FUN_00193300);
        params[26] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swaySideStart", &owners::Obj_193320::FUN_00193320);
        params[27] = new ::fight::ParamBool< ::hulkfight::motion::FireMissileTrack>("swaySideStartRandom", &owners::X_193340::FUN_00193340);
        params[28] = new ::fight::ParamBool< ::hulkfight::motion::FireMissileTrack>("swaySideSkipZero", &owners::T_193360::FUN_00193360);
        params[29] = new ::fight::ParamBool< ::hulkfight::motion::FireMissileTrack>("swaySideNextRandom", &owners::Obj_193380::FUN_00193380);
        params[30] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayThresholdDistance", &owners::Obj_1933a0::FUN_001933a0);
        params[31] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayAfterDurationTracking", &owners::Obj_1933c0::FUN_001933c0);
        params[32] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayAfterDurationTrackingTime", &owners::X_1933f0::FUN_001933f0);
        params[33] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayAfterThresholdTracking", &owners::Obj_193410::FUN_00193410);
        params[34] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayAfterThresholdTrackingTime", &owners::T_193430::FUN_00193430);
        params[35] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("swayDuringSwayTracking", &owners::Obj_193450::FUN_00193450);
        params[36] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("lifeTime", &owners::Obj_193480::FUN_00193480);
        params[37] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireMissileTrack>("projectilePriority", &owners::Obj_1934a0::FUN_001934a0);
        params[38] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireMissileTrack>("interruptPriority", &owners::Obj_1934c0::FUN_001934c0);
        params[39] = new ::fight::ParamBranch< ::hulkfight::motion::FireMissileTrack>("hitBranch", &owners::Obj_1934d0::FUN_001934d0);
        params[40] = new ::fight::ParamBranch< ::hulkfight::motion::FireMissileTrack>("giverBranch", &owners::X_1934e0::FUN_001934e0);
        params[41] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("hitPropDamage", &owners::X_193500::FUN_00193500);
        params[42] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("hitPropForce", &owners::Obj_193520::FUN_00193520);
        params[43] = new ::fight::ParamString< ::hulkfight::motion::FireMissileTrack>("hitPropSound", &owners::Object_194510::FUN_00194510);
        params[44] = new ::fight::ParamEnumConstList< ::hulkfight::motion::FireMissileTrack>("hitDamageType", (void*)&DAT_004ad788, DAT_00412ed4, &owners::Target_193550::FUN_00193550);
        params[45] = new ::fight::ParamName< ::hulkfight::motion::FireMissileTrack>("explosionEffect", &owners::Obj_193560::FUN_00193560);
        params[46] = new ::fight::ParamVector< ::hulkfight::motion::FireMissileTrack>("explosionEffectAxis", &owners::Obj_1935a0::FUN_001935a0);
        params[47] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("explosionRadius", &owners::X_1935e0::FUN_001935e0);
        params[48] = new ::fight::ParamBranch< ::hulkfight::motion::FireMissileTrack>("explosionHitBranch", &owners::T_1935f0::FUN_001935f0);
        params[49] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("explosionHitPropDamage", &owners::Obj_193610::FUN_00193610);
        params[50] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("explosionHitPropForce", &owners::Obj_193630::FUN_00193630);
        params[51] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("motionTrailWidth", &owners::C_193650::FUN_00193650);
        params[52] = new ::fight::ParamVector< ::hulkfight::motion::FireMissileTrack>("motionTrailOffset", &fn_00193690::Obj::Set);
        params[53] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("motionTrailFadeOutTime", &owners::Obj_1936d0::FUN_001936d0);
        params[54] = new ::fight::ParamName< ::hulkfight::motion::FireMissileTrack>("motionTrailShader", &fn_fa51549e::Item_1936e0::f);
        params[55] = new ::fight::ParamVector< ::hulkfight::motion::FireMissileTrack>("motionTrailShrinkOffset", &fn_fa51549e::O::Set);
        params[56] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("motionTrailShrinkTime", &owners::Obj_193760::FUN_00193760);
        params[57] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("motionTrailFadeTime", &owners::C_193780::FUN_00193780);
        params[58] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireMissileTrack>("motionTrailTextureTime", &owners::Obj_1937a0::FUN_001937a0);
        FUN_002347b0(&DAT_004e1580, params, 59);
    }
    DAT_004e1584++;
}



// 0x0019de20 FUN_0019de20 (38 B): matches/0x0019de20.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: _FUN_0019de20
namespace fn_0019de20 {
extern "C" char DAT_0041b9d8[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::FireGroundShockwaveTrack>::vftable
namespace fight {
struct TrackFactoryCasterTemplate {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
};
} // namespace fight
class Obj {
  public:
    void Use_002367c0(void*);
};
void* Find_00236ac0(void*, fight::TrackFactoryCasterTemplate*);
extern "C" void FUN_0019de20(Obj* obj, void* value) {
    fight::TrackFactoryCasterTemplate caster;
    caster.vftable = (void*)DAT_0041b9d8;   // (sweep-caster-fix1) the game's vftable by address
    void* found = Find_00236ac0(value, &caster);
    obj->Use_002367c0(found);
}
} // namespace fn_0019de20

namespace fn_fdcf800c {

} // namespace fn_fdcf800c

// 0x0019de50 FUN_0019de50 (1412 B): matches/0x0019de50.cpp
// sym: _FUN_0019de50
// (gx2, D18) rewritten; constructs the real ParamBranch<hulkfight::motion::FireGroundShockwaveTrack>, ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>, ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>, ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>, ParamName<hulkfight::motion::FireGroundShockwaveTrack>, ParamVector<hulkfight::motion::FireGroundShockwaveTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0019de50()
{
    if ((*(int*)&DAT_004e158c) == 0) {
        ::fight::ParamValue* params[26];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("timeBegin", &owners::Obj_1937b0::FUN_001937b0);
        params[1] = new ::fight::ParamVector< ::hulkfight::motion::FireGroundShockwaveTrack>("origin", &fn_001937e0::Obj::Set);
        params[2] = new ::fight::ParamVector< ::hulkfight::motion::FireGroundShockwaveTrack>("direction", &fn_fa51549e::Obj_193820::Set);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("distance", &owners::Obj_193850::FUN_00193850);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("lifeTime", &owners::Obj_193870::FUN_00193870);
        params[5] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("projectilePriority", &owners::Obj_193890::FUN_00193890);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("radius", &owners::C_1938b0::FUN_001938b0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("maxAffectedHeight", &owners::Obj_1938d0::FUN_001938d0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("maxYChange", &owners::Obj_1938f0::FUN_001938f0);
        params[9] = new ::fight::ParamName< ::hulkfight::motion::FireGroundShockwaveTrack>("effect", &owners::Obj_193900::FUN_00193900);
        params[10] = new ::fight::ParamVector< ::hulkfight::motion::FireGroundShockwaveTrack>("effectAxis", &fn_fa51549e::Obj_193930::Set);
        params[11] = new ::fight::ParamEnumConstList< ::hulkfight::motion::FireGroundShockwaveTrack>("decalDamageType", (void*)&DAT_004ad788, DAT_00412ed4, &owners::Obj_193960::FUN_00193960);
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("decalScale", &owners::Obj_193980::FUN_00193980);
        params[13] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("decalDistance", &owners::Obj_1939a0::FUN_001939a0);
        params[14] = new ::fight::ParamEnumConstList< ::hulkfight::motion::FireGroundShockwaveTrack>("coneDamageType", (void*)&DAT_004ad788, DAT_00412ed4, &owners::C_1939c0::FUN_001939c0);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("coneRadius", &owners::Thing_1939e0::FUN_001939e0);
        params[16] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("coneArc", &owners::O_193a00::FUN_00193a00);
        params[17] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("coneDecalCount", &owners::O_193a30::FUN_00193a30);
        params[18] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("coneDecalScale", &owners::Obj_193a50::FUN_00193a50);
        params[19] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("interruptPriority", &owners::Obj_193a70::FUN_00193a70);
        params[20] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("damage", &owners::Obj_193a90::FUN_00193a90);
        params[21] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FireGroundShockwaveTrack>("damageMax", &owners::X_193ab0::FUN_00193ab0);
        params[22] = new ::fight::ParamVector< ::hulkfight::motion::FireGroundShockwaveTrack>("force", &fn_fa51549e::Target::Fn);
        params[23] = new ::fight::ParamVector< ::hulkfight::motion::FireGroundShockwaveTrack>("forceMax", &fn_00193b50::Obj::Set);
        params[24] = new ::fight::ParamBranch< ::hulkfight::motion::FireGroundShockwaveTrack>("hitBranch", &owners::Obj_193b80::FUN_00193b80);
        params[25] = new ::fight::ParamName< ::hulkfight::motion::FireGroundShockwaveTrack>("hitEffect", &fn_fa51549e::Obj_193b90::GetBody);
        FUN_002347b0(&DAT_004e1588, params, 26);
    }
    (*(int*)&DAT_004e158c)++;
}

namespace fn_fdcf800c {


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
