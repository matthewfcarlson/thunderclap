// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x0017e1a0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/JointTrackerTrack_3.cpp
// piece 0x0017bc70..0x0017e1a0 (kind game, layer game, confidence high, dominant class hulkfight::motion::SnapToGroundTrack); was game/hulkfight/motion/SnapToGroundTrack_2.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f05a6271 {
#define TREE_TU_END }
namespace fn_f05a6271 {} using namespace fn_f05a6271;
namespace fn_f05a6271 {
}
#include "game/hulkfight/motion.h"
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_0016eb60 { struct S_16eb60; } 
namespace fn_fa642773 { struct Data_16f2e0; } 
namespace fn_fa642773 { struct Src_16ef80; } 
namespace fn_fa642773 { struct Src_16f400; } 
namespace fn_fa642773 { struct V; } 
namespace fn_fa642773 { struct Vec3; } 
namespace fn_fa642773 { struct Vec3_16ef40; } 
namespace fn_fa642773 { struct Vec3_16f2a0; } 
namespace fn_fa642773 { struct Vec3_16f440; } 
namespace fn_fa642773 { struct Vec; } 
namespace fn_0016eb60 { struct C_16eb60 { bool operator=(struct fn_0016eb60::S_16eb60 *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct C_16e770 { bool Set(struct fn_fa642773::V *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Ctx_16f2e0 { char Set(struct fn_fa642773::Data_16f2e0 *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj { bool Set(struct fn_fa642773::Vec const &); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16ef10 { char * Get(); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16ef40 { bool Set(struct fn_fa642773::Vec3_16ef40 const *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16ef80 { bool Set(struct fn_fa642773::Src_16ef80 *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f2a0 { char Set(struct fn_fa642773::Vec3_16f2a0 *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f400 { bool Set(struct fn_fa642773::Src_16f400 *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f440 { bool Set(struct fn_fa642773::Vec3_16f440 *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Thing { bool Set(struct fn_fa642773::Vec3 const *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f05a6271 {
typedef unsigned int u32_17bc70;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct Result_17bc70 {
    u32_17bc70 Init_00176f50(void*, void*);
};
extern Result_17bc70* Alloc_0008d690(int);
extern int hulk_at_00418014;
class RefObj_17bcc0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class RestPoseAction_17bcc0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_17bcc0* m2;
    RefObj_17bcc0* m3;
    void* vfunc_2(unsigned char flag);
};
struct RefCounted_17bd70 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00418030[];
class SuckAction_17bd70 {
  public:
    SuckAction_17bd70* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17bd70* m_20;
};
struct RefCounted_17be10 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0041804c[];
class CriticalMassDrainAction_17be10 {
  public:
    CriticalMassDrainAction_17be10* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17be10* m_20;
};
typedef unsigned int u32_17be60;
extern int TypeA_17be60, TypeB;
struct Params_17be60 {
    int Init_001774c0(hulkfight::motion::MomentumXZAddTrack*, void*);
};
extern void* Alloc(hulk_uintptr);
struct RefCounted_17beb0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00418068[];
class MomentumXZAddAction_17beb0 {
  public:
    MomentumXZAddAction_17beb0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17beb0* m_20;
};
struct RefCounted_17bf50 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00418084[];
class VisibilityAction_17bf50 {
  public:
    VisibilityAction_17bf50* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17bf50* m_20;
};
struct RefCounted_17bff0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_004180a0[];
class SnapToGroundAction_17bff0 {
  public:
    SnapToGroundAction_17bff0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17bff0* m_20;
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
} // namespace fn_f05a6271
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f05a6271 {
void* FUN_0008d690(unsigned int size);
} // namespace fn_f05a6271
namespace hulkfight { namespace motion {
class JointTrackerTrack_17c650 {
public:
    bool FUN_0016e720(int); /* (unb4) as defined; address taken only */
    bool FUN_0016e730(int); /* (unb4) as defined; address taken only */
    void FUN_0016e740();
    bool FUN_0016e770(void*); /* (unb4) as defined; address taken only */
    bool FUN_0016e7b0(void*); /* (unb4) as defined; address taken only */
    char FUN_0016e7e0(float); /* (unb4) as defined; address taken only */
    bool FUN_0016e810(float); /* (unb4) as defined; address taken only */
    char FUN_0016e840(float); /* (unb4) as defined; address taken only */
    char FUN_0016e870(float); /* (unb4) as defined; address taken only */
    char FUN_0016e8a0(float); /* (unb4) as defined; address taken only */
    bool FUN_0016e8d0(char); /* (unb4) as defined; address taken only */
    char FUN_0016e8f0(float); /* (unb4) as defined; address taken only */
    char FUN_0016e920(int); /* (unb4) as defined; address taken only */
    bool FUN_0016e940(int); /* (unb4) as defined; address taken only */
    char FUN_0016e960(int); /* (unb4) as defined; address taken only */
    bool FUN_0016e980(int); /* (unb4) as defined; address taken only */
    char FUN_0016e9a0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f05a6271 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_f05a6271
namespace fight {
template <class T>
class ParamBool_17c650 : public ParamBoolBase {
public:
    ParamBool_17c650(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_17c650 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_17c650(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_17c650 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17c650(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_17c650 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17c650(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_17c650 : public ParamNameConstListBase {
public:
    ParamNameConstList_17c650(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_17c650 : public ParamVectorBase {
public:
    ParamVector_17c650(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f05a6271 {
class RestPoseTrack {
public:
    bool FUN_0016ea30(int); /* (unb4) as defined; address taken only */
    char FUN_0016ea40(int); /* (unb4) as defined; address taken only */
    void FUN_0016ea50();
    char FUN_0016ea70(int); /* (unb4) as defined; address taken only */
    char FUN_0016ea90(int); /* (unb4) as defined; address taken only */
    bool FUN_0016eab0(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
extern "C" char DAT_00418970[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::SnapToGroundTrack>'s vftable
class Caster_17cbd0 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Obj {
  public:
    bool FUN_002367c0(void*);
};
void* __cdecl Find_00236ac0(const char*, Caster_17cbd0*);
extern "C" char DAT_0041897c[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::JointRelativeTrack>'s vftable
class Caster_17cc00 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
extern void* Find_00236ac0(const char*, Caster_17cc00*);
class Track {
  public:
    bool FUN_002367c0(void*);
};
class JointRelativeTrack {
public:
    char FUN_0016ead0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016eae0(int); /* (unb4) as defined; address taken only */
    void FUN_0016eaf0();
    char FUN_0016eb10(char); /* (unb4) as defined; address taken only */
    char FUN_0016eb30(char); /* (unb4) as defined; address taken only */
    bool FUN_0016eb60(void*); /* (unb4) as defined; address taken only */
    char FUN_0016eb90(char); /* (unb4) as defined; address taken only */
    char FUN_0016ebc0(void*); /* (unb4) as defined; address taken only */
    char FUN_0016ec10(int); /* (unb4) as defined; address taken only */
    char FUN_0016ec30(int); /* (unb4) as defined; address taken only */
    bool FUN_0016ec50(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f05a6271
namespace fight {
template <class T>
class ParamBool_17cc30 : public ParamBoolBase {
public:
    ParamBool_17cc30(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_17cc30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17cc30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_17cc30 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17cc30(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_17cc30 : public ParamNameConstListBase {
public:
    ParamNameConstList_17cc30(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_17cc30 : public ParamVectorBase {
public:
    ParamVector_17cc30(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class SyncToLocatorTrack_17ced0 {
public:
    char FUN_0016ec60(int); /* (unb4) as defined; address taken only */
    bool FUN_0016ec70(int); /* (unb4) as defined; address taken only */
    bool FUN_0016ec90(int); /* (unb4) as defined; address taken only */
    bool FUN_0016ecb0(int); /* (unb4) as defined; address taken only */
    void FUN_0016ecc0();
    bool FUN_00170130(void*, int); /* (unb4) as defined; address taken only */
    bool FUN_0016ed00(int); /* (unb4) as defined; address taken only */
    char FUN_0016ed20(float); /* (unb4) as defined; address taken only */
    bool FUN_0016ed60(void*); /* (unb4) as defined; address taken only */
    char FUN_0016ed90(int); /* (unb4) as defined; address taken only */
    char FUN_0016edb0(int); /* (unb4) as defined; address taken only */
    char FUN_0016edd0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f05a6271 {
class __declspec(novtable) ParamScriptBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234c00(const char* name);
    ParamScriptBase(const char* name) { FUN_00234c00(name); }
};
} // namespace fn_f05a6271
namespace fight {
template <class T>
class ParamEnumConstList_17ced0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_17ced0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_17ced0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17ced0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_17ced0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17ced0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_17ced0 : public ParamNameBase {
public:
    ParamName_17ced0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamScript_17ced0 : public ParamScriptBase {
public:
    ParamScript_17ced0(const char* name, void (T::*s)()) : ParamScriptBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_17ced0 : public ParamVectorBase {
public:
    ParamVector_17ced0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f05a6271 {
extern "C" char DAT_00418994[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckTrack>'s vftable
class Caster_17d180 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
void* __cdecl find_00236ac0(const char*, Caster_17d180*);
extern "C" char DAT_004189a0[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStateTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Owner {
  public:
    bool FUN_002367c0(void*);
};
Track* Find_00236ac0(const char*, Caster*);
extern "C" char DAT_004189ac[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::MoveJointTrack>'s vftable
class Caster_17d1e0 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
void* first_00236ac0(const char*, Caster_17d1e0*);
} // namespace fn_f05a6271
namespace hulkfight { namespace motion {
class MoveJointTrack_17d210 {
public:
    bool FUN_0016eeb0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016eed0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016eef0(int); /* (unb4) as defined; address taken only */
    void FUN_0016ef00();
    void FUN_0016ef10();
    bool FUN_0016ef40(void*); /* (unb4) as defined; address taken only */
    bool FUN_0016ef80(void*); /* (unb4) as defined; address taken only */
    char FUN_0016efb0(void*); /* (unb4) as defined; address taken only */
    bool FUN_0016efd0(int); /* (unb4) as defined; address taken only */
    char FUN_0016eff0(int); /* (unb4) as defined; address taken only */
    char FUN_0016f010(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f030(int); /* (unb4) as defined; address taken only */
    char FUN_0016f050(char); /* (unb4) as defined; address taken only */
    char FUN_0016f060(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f070(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f080(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_17d210 : public ParamBoolBase {
public:
    ParamBool_17d210(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_17d210 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17d210(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_17d210 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17d210(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_17d210 : public ParamNameConstListBase {
public:
    ParamNameConstList_17d210(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_17d210 : public ParamVectorBase {
public:
    ParamVector_17d210(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f05a6271 {
extern ParamRegistry hulk_at_004e1328;
extern int hulk_at_004e132c;
extern "C" char DAT_004189c4[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToHulkTrack>'s vftable
class Caster_17d5b0 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
extern void* __cdecl Find_00236ac0(const char*, Caster_17d5b0*);
extern "C" char DAT_004189dc[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::MomentumXZAddTrack>'s vftable
class Caster_17d610 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
extern void* __cdecl Find_00236ac0(const char*, Caster_17d610*);
extern "C" char DAT_004189e8[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetBreakTrack>'s vftable
class Caster_17d640 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
void* find_00236ac0(const char*, Caster_17d640*);
extern "C" char DAT_004189f4[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::PushOutTrack>'s vftable
class Caster_17d670 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
void* Find_00236ac0(void*, Caster_17d670*);
class PushOutTrack {
public:
    char FUN_0016f250(int); /* (unb4) as defined; address taken only */
    char FUN_0016f260(int); /* (unb4) as defined; address taken only */
    void FUN_0016f270();
    char FUN_0016f2a0(void*); /* (unb4) as defined; address taken only */
    char FUN_0016f2e0(void*); /* (unb4) as defined; address taken only */
    char FUN_0016f310(int); /* (unb4) as defined; address taken only */
    char FUN_0016f330(int); /* (unb4) as defined; address taken only */
    char FUN_0016f350(char); /* (unb4) as defined; address taken only */
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
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
extern "C" char DAT_00418a0c[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::JointPivotTrackerTrack>'s vftable
class Caster_17d8a0 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
void* __cdecl resolve_00236ac0(void*, Caster_17d8a0*);
} // namespace fn_f05a6271
namespace hulkfight { namespace motion {
class JointPivotTrackerTrack_17d8d0 {
public:
    char FUN_0016f3b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f3c0(int); /* (unb4) as defined; address taken only */
    void FUN_0016f3d0();
    bool FUN_0016f400(void*); /* (unb4) as defined; address taken only */
    bool FUN_0016f440(void*); /* (unb4) as defined; address taken only */
    char FUN_0016f470(float); /* (unb4) as defined; address taken only */
    bool FUN_0016f4a0(float); /* (unb4) as defined; address taken only */
    bool FUN_0016f4d0(float); /* (unb4) as defined; address taken only */
    char FUN_0016f500(char); /* (unb4) as defined; address taken only */
    char FUN_0016f520(float); /* (unb4) as defined; address taken only */
    char FUN_0016f550(int); /* (unb4) as defined; address taken only */
    char FUN_0016f570(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f590(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f5b0(int); /* (unb4) as defined; address taken only */
    char FUN_0016f5d0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_17d8d0 : public ParamBoolBase {
public:
    ParamBool_17d8d0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_17d8d0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_17d8d0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_17d8d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17d8d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_17d8d0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17d8d0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_17d8d0 : public ParamNameConstListBase {
public:
    ParamNameConstList_17d8d0(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_17d8d0 : public ParamVectorBase {
public:
    ParamVector_17d8d0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f05a6271 {
extern "C" char DAT_00418a18[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::SurfTrack>'s vftable
class Caster_17dc10 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Target {
  public:
    bool FUN_002367c0(void*);
};
void* Find_00236ac0(void*, Caster_17dc10*);
extern "C" char DAT_00418a24[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetIconDistanceTrack>'s vftable
class Caster_17dc40 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
extern void* Find_00236ac0(void*, Caster_17dc40*);
class FootPivotTrack {
public:
    char FUN_0016fad0(int); /* (unb4) as defined; address taken only */
    char FUN_0016fae0(int); /* (unb4) as defined; address taken only */
    void FUN_0016faf0();
    bool FUN_0016fb20(void*); /* (unb4) as defined; address taken only */
    char FUN_0016fb50(float); /* (unb4) as defined; address taken only */
    char FUN_0016fb80(float); /* (unb4) as defined; address taken only */
    bool FUN_0016fbb0(char); /* (unb4) as defined; address taken only */
    char FUN_0016fbd0(int); /* (unb4) as defined; address taken only */
    char FUN_0016fbf0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016fc10(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f05a6271
namespace fight {
template <class T>
class ParamBool_17ddf0 : public ParamBoolBase {
public:
    ParamBool_17ddf0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_17ddf0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17ddf0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_17ddf0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17ddf0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_17ddf0 : public ParamNameConstListBase {
public:
    ParamNameConstList_17ddf0(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_17ddf0 : public ParamVectorBase {
public:
    ParamVector_17ddf0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f05a6271 {
struct ChargeTrack_17e070 {
    hulk_intptr vt;
    int pad4;
    int enabled;
    float padc;
    float value10;
    int pad14;
    char flag18;
    char pad19[3];
    float value1c;
    void Init_00236d40();
};
extern int hulk_at_004178c8;
extern int hulk_at_00418de0;

} // namespace fn_f05a6271

// 0x00178d30 fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178d30.cpp
// sym: ??_G?$ParamFloatConstRange@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178d50 fight::ParamVector<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178d50.cpp
// sym: ??_G?$ParamVector@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178d70 fight::ParamBool<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178d70.cpp
// sym: ??_G?$ParamBool@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178d90 fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178d90.cpp
// sym: ??_G?$ParamEnumConstList@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178db0 fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x00178db0.cpp
// sym: ??_G?$ParamIntConstRange@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178eb0 fight::ParamFloatConstRange<hulkfight::motion::RestPoseTrack>::vfunc_0 (30 B): matches/0x00178eb0.cpp
// sym: ??_G?$ParamFloatConstRange@VRestPoseTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RestPoseTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178ed0 fight::ParamIntConstRange<hulkfight::motion::RestPoseTrack>::vfunc_0 (30 B): matches/0x00178ed0.cpp
// sym: ??_G?$ParamIntConstRange@VRestPoseTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RestPoseTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178f90 fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x00178f90.cpp
// sym: ??_G?$ParamFloatConstRange@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointRelativeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178fb0 fight::ParamBool<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x00178fb0.cpp
// sym: ??_G?$ParamBool@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointRelativeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178fd0 fight::ParamVector<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x00178fd0.cpp
// sym: ??_G?$ParamVector@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointRelativeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00178ff0 fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x00178ff0.cpp
// sym: ??_G?$ParamIntConstRange@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointRelativeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179050 fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x00179050.cpp
// sym: ??_G?$ParamFloatConstRange@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SyncToLocatorTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179070 fight::ParamScript<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x00179070.cpp
// sym: ??_G?$ParamScript@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SyncToLocatorTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179090 fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x00179090.cpp
// sym: ??_G?$ParamEnumConstList@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SyncToLocatorTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x001790b0 fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x001790b0.cpp
// sym: ??_G?$ParamVector@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SyncToLocatorTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x001790d0 fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x001790d0.cpp
// sym: ??_G?$ParamIntConstRange@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SyncToLocatorTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179210 fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>::vfunc_0 (30 B): matches/0x00179210.cpp
// sym: ??_G?$ParamFloatConstRange@VMoveJointTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from MoveJointTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179230 fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>::vfunc_0 (30 B): matches/0x00179230.cpp
// sym: ??_G?$ParamIntConstRange@VMoveJointTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from MoveJointTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179250 fight::ParamVector<hulkfight::motion::MoveJointTrack>::vfunc_0 (30 B): matches/0x00179250.cpp
// sym: ??_G?$ParamVector@VMoveJointTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from MoveJointTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179270 fight::ParamBool<hulkfight::motion::MoveJointTrack>::vfunc_0 (30 B): matches/0x00179270.cpp
// sym: ??_G?$ParamBool@VMoveJointTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from MoveJointTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179550 fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>::vfunc_0 (30 B): matches/0x00179550.cpp
// sym: ??_G?$ParamFloatConstRange@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PushOutTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179570 fight::ParamVector<hulkfight::motion::PushOutTrack>::vfunc_0 (30 B): matches/0x00179570.cpp
// sym: ??_G?$ParamVector@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PushOutTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179590 fight::ParamBool<hulkfight::motion::PushOutTrack>::vfunc_0 (30 B): matches/0x00179590.cpp
// sym: ??_G?$ParamBool@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PushOutTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179670 fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x00179670.cpp
// sym: ??_G?$ParamFloatConstRange@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointPivotTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179690 fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x00179690.cpp
// sym: ??_G?$ParamVector@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointPivotTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x001796b0 fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x001796b0.cpp
// sym: ??_G?$ParamBool@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointPivotTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x001796d0 fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x001796d0.cpp
// sym: ??_G?$ParamEnumConstList@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointPivotTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x001796f0 fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x001796f0.cpp
// sym: ??_G?$ParamIntConstRange@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointPivotTrackerTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179b90 fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x00179b90.cpp
// sym: ??_G?$ParamFloatConstRange@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FootPivotTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179bb0 fight::ParamVector<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x00179bb0.cpp
// sym: ??_G?$ParamVector@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FootPivotTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179bd0 fight::ParamBool<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x00179bd0.cpp
// sym: ??_G?$ParamBool@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FootPivotTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x00179bf0 fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x00179bf0.cpp
// sym: ??_G?$ParamIntConstRange@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FootPivotTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0017c650 / FUN_0017ca60 / FUN_0017cc30 / FUN_0017ced0 / FUN_0017d210 / FUN_0017d6a0 / FUN_0017d8d0 / FUN_0017ddf0)



// 0x0017bc70 hulkfight::motion::RestPoseTrack::vfunc_10 (70 B): matches/0x0017bc70.cpp
// sym: ?vfunc_10@RestPoseTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::RestPoseTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17bc70 a = (u32_17bc70)__p0; u32_17bc70 b = (u32_17bc70)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        Result_17bc70* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(q->Init_00176f50(this, p));
    }
    return (int)(0);
}

namespace fn_f05a6271 {

// 0x0017bcc0 hulkfight::motion::RestPoseAction::vfunc_2 (90 B): matches/0x0017bcc0.cpp
// sym: ?vfunc_2@RestPoseAction_17bcc0@fn_f05a6271@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* RestPoseAction_17bcc0::vfunc_2(unsigned char flag) {
    volatile RestPoseAction_17bcc0* self = this;
    self->mVptr = &hulk_at_00418014;
    RefObj_17bcc0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_17bcc0* t2 = self->m2;
    if (t2) {
        t2->Release();
        self->m2 = 0;
    }
    int v1 = self->m1;
    if (v1) {
        self->m1 = 0;
    }
    BaseDtor(this);
    if (flag & 1)
        ::operator delete(this);
    return this;
}


// 0x0017bd70 hulkfight::motion::SuckAction::vfunc_2 (71 B): matches/0x0017bd70.cpp
// sym: ?vfunc_2@SuckAction_17bd70@fn_f05a6271@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
SuckAction_17bd70* SuckAction_17bd70::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00418030;
    RefCounted_17bd70* q = *(RefCounted_17bd70* volatile*)&m_20;
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


// 0x0017be10 hulkfight::motion::CriticalMassDrainAction::vfunc_2 (71 B): matches/0x0017be10.cpp
// sym: ?vfunc_2@CriticalMassDrainAction_17be10@fn_f05a6271@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
CriticalMassDrainAction_17be10* CriticalMassDrainAction_17be10::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0041804c;
    RefCounted_17be10* q = *(RefCounted_17be10* volatile*)&m_20;
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

} // namespace fn_f05a6271

// 0x0017be60 hulkfight::motion::MomentumXZAddTrack::vfunc_10 (70 B): matches/0x0017be60.cpp
// sym: ?vfunc_10@MomentumXZAddTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00119fb0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MomentumXZAddTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17be60 a = (u32_17be60)__p0; u32_17be60 b = (u32_17be60)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&TypeA_17be60), (void*)(hulk_uintptr)(&TypeB), 0))) {
        Params_17be60* q = (Params_17be60*)Alloc_0008d690(0x34);
        if (q)
            return q->Init_001774c0(this, p);
    }
    return 0;
}

namespace fn_f05a6271 {

// 0x0017beb0 hulkfight::motion::MomentumXZAddAction::vfunc_2 (71 B): matches/0x0017beb0.cpp
// sym: ?vfunc_2@MomentumXZAddAction_17beb0@fn_f05a6271@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
MomentumXZAddAction_17beb0* MomentumXZAddAction_17beb0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00418068;
    RefCounted_17beb0* q = *(RefCounted_17beb0* volatile*)&m_20;
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


// 0x0017bf50 hulkfight::motion::VisibilityAction::vfunc_2 (71 B): matches/0x0017bf50.cpp
// sym: ?vfunc_2@VisibilityAction_17bf50@fn_f05a6271@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
VisibilityAction_17bf50* VisibilityAction_17bf50::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00418084;
    RefCounted_17bf50* q = *(RefCounted_17bf50* volatile*)&m_20;
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


// 0x0017bff0 hulkfight::motion::SnapToGroundAction::vfunc_2 (71 B): matches/0x0017bff0.cpp
// sym: ?vfunc_2@SnapToGroundAction_17bff0@fn_f05a6271@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
SnapToGroundAction_17bff0* SnapToGroundAction_17bff0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_004180a0;
    RefCounted_17bff0* q = *(RefCounted_17bff0* volatile*)&m_20;
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


// 0x0017c080 fight::ParamNameConstList<hulkfight::motion::JointTrackerTrack>::vfunc_7 (12 B): matches/0x0017c080.cpp
// sym: ?vfunc_6@ParamBranch@fn_f05a6271@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}

} // namespace fn_f05a6271

// 0x0017c0f0 fight::ParamName<hulkfight::motion::RestPoseTrack>::vfunc_7 (12 B): matches/0x0017c0f0.cpp [wrapped: same definition as 0x0017c080 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0017c0f0@@UAEXPAX@Z
namespace fn_0017c0f0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_0017c0f0


// 0x0017c160 fight::ParamNameConstList<hulkfight::motion::JointRelativeTrack>::vfunc_7 (12 B): matches/0x0017c160.cpp [wrapped: same definition as 0x0017c080 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0017c160@@UAEXPAX@Z
namespace fn_0017c160 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_0017c160


// 0x0017c1b0 fight::ParamName<hulkfight::motion::SyncToLocatorTrack>::vfunc_7 (12 B): matches/0x0017c1b0.cpp [wrapped: same definition as 0x0017c080 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0017c1b0@@UAEXPAX@Z
namespace fn_0017c1b0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_0017c1b0


// 0x0017c240 fight::ParamNameConstList<hulkfight::motion::MoveJointTrack>::vfunc_7 (12 B): matches/0x0017c240.cpp [wrapped: same definition as 0x0017c080 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0017c240@@UAEXPAX@Z
namespace fn_0017c240 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_0017c240


// 0x0017c330 fight::ParamNameConstList<hulkfight::motion::PushOutTrack>::vfunc_7 (12 B): matches/0x0017c330.cpp [wrapped: same definition as 0x0017c080 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0017c330@@UAEXPAX@Z
namespace fn_0017c330 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_0017c330


// 0x0017c3a0 fight::ParamNameConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_7 (12 B): matches/0x0017c3a0.cpp [wrapped: same definition as 0x0017c080 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0017c3a0@@UAEXPAX@Z
namespace fn_0017c3a0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_0017c3a0


// 0x0017c510 fight::ParamNameConstList<hulkfight::motion::FootPivotTrack>::vfunc_7 (12 B): matches/0x0017c510.cpp [wrapped: same definition as 0x0017c080 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0017c510@@UAEXPAX@Z
namespace fn_0017c510 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_0017c510


// 0x0017c520 fight::ParamNameConstList<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x0017c520.cpp
// sym: ??_G?$ParamNameConstList@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0017c540 fight::ParamName<hulkfight::motion::RestPoseTrack>::vfunc_0 (30 B): matches/0x0017c540.cpp
// sym: ??_G?$ParamName@VRestPoseTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0017c560 fight::ParamNameConstList<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x0017c560.cpp
// sym: ??_G?$ParamNameConstList@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0017c580 fight::ParamName<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x0017c580.cpp
// sym: ??_G?$ParamName@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0017c5a0 fight::ParamNameConstList<hulkfight::motion::MoveJointTrack>::vfunc_0 (30 B): matches/0x0017c5a0.cpp
// sym: ??_G?$ParamNameConstList@VMoveJointTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0017c5c0 fight::ParamNameConstList<hulkfight::motion::PushOutTrack>::vfunc_0 (30 B): matches/0x0017c5c0.cpp
// sym: ??_G?$ParamNameConstList@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0017c5e0 fight::ParamNameConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x0017c5e0.cpp
// sym: ??_G?$ParamNameConstList@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0017c600 fight::ParamNameConstList<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x0017c600.cpp
// sym: ??_G?$ParamNameConstList@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0017c620 FUN_0017c620 (38 B): matches/0x0017c620.cpp [wrapped: conflict: Find; fight::TrackFactoryCasterTemplate]
// sym: _FUN_0017c620
namespace fn_0017c620 {
extern "C" char DAT_0041894c[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::JointTrackerTrack>::vftable
namespace fight {
struct TrackFactoryCasterTemplate {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
};
} // namespace fight
class Thing {
  public:
    bool FUN_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* Find_00236ac0(const char*, fight::TrackFactoryCasterTemplate*);
extern "C" void FUN_0017c620(Thing* thing, const char* name) {
    fight::TrackFactoryCasterTemplate caster;
    caster.vftable = (void*)DAT_0041894c;   // (sweep-caster-fix1) the game's vftable by address
    thing->FUN_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0017c620

namespace fn_f05a6271 {

} // namespace fn_f05a6271

// 0x0017c650 FUN_0017c650 (933 B): matches/0x0017c650.cpp
// sym: _FUN_0017c650
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::JointTrackerTrack>, ParamEnumConstList<hulkfight::motion::JointTrackerTrack>, ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>, ParamIntConstRange<hulkfight::motion::JointTrackerTrack>, ParamNameConstList<hulkfight::motion::JointTrackerTrack>, ParamVector<hulkfight::motion::JointTrackerTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017c650()
{
    if (DAT_004e12ec == 0) {
        ::fight::ParamValue* params[17];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("timeBegin", &owners::Obj_16e720::FUN_0016e720);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("timeEnd", &owners::Obj_16e730::FUN_0016e730);
        params[2] = new ::fight::ParamNameConstList< ::hulkfight::motion::JointTrackerTrack>("joint", &owners::A_16e740::FUN_0016e740);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::JointTrackerTrack>("north", &fn_fa642773::C_16e770::Set);
        params[4] = new ::fight::ParamVector< ::hulkfight::motion::JointTrackerTrack>("east", &fn_fa642773::Thing::Set);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("turnRate", &owners::A_16e7e0::FUN_0016e7e0);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("vertMinAngle", &owners::Obj_16e810::FUN_0016e810);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("vertMaxAngle", &owners::Obj_16e840::FUN_0016e840);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("horzMinAngle", &owners::X_16e870::FUN_0016e870);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("horzMaxAngle", &owners::Obj_16e8a0::FUN_0016e8a0);
        params[10] = new ::fight::ParamBool< ::hulkfight::motion::JointTrackerTrack>("targetRequired", &owners::C_16e8d0::FUN_0016e8d0);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("targetArc", &owners::Target_16e8f0::FUN_0016e8f0);
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("targetDistance", &owners::Obj_16e920::FUN_0016e920);
        params[13] = new ::fight::ParamEnumConstList< ::hulkfight::motion::JointTrackerTrack>("targetLocation", (void*)&DAT_004b7cf0, 3, &owners::Obj_16e940::FUN_0016e940);
        params[14] = new ::fight::ParamIntConstRange< ::hulkfight::motion::JointTrackerTrack>("priority", &owners::Obj_16e960::FUN_0016e960);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("blendInTime", &owners::Obj_16e980::FUN_0016e980);
        params[16] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointTrackerTrack>("blendOutTime", &owners::Obj_16e9a0::FUN_0016e9a0);
        FUN_002347b0(&DAT_004e12e8, params, 17);
    }
    DAT_004e12ec++;
}



// 0x0017ca00 FUN_0017ca00 (38 B): matches/0x0017ca00.cpp [wrapped: conflict: Find]
// sym: _FUN_0017ca00
namespace fn_0017ca00 {
extern "C" char DAT_00418958[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeTrack>'s vftable
class Caster_17ca00 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Obj {
  public:
    bool FUN_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, Caster_17ca00*);
extern "C" void __cdecl FUN_0017ca00(Obj* obj, void* value) {
    Caster_17ca00 caster;
    caster.vftable = (void*)DAT_00418958;   // (sweep-caster-land) the game's vftable by address
    void* p = Find_00236ac0(value, &caster);
    obj->FUN_002367c0(p);
}
} // namespace fn_0017ca00


// 0x0017ca30 FUN_0017ca30 (38 B): matches/0x0017ca30.cpp [wrapped: conflict: Find]
// sym: _FUN_0017ca30
namespace fn_0017ca30 {
extern "C" char DAT_00418964[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::RestPoseTrack>'s vftable
class Caster_17ca30 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Obj {
  public:
    bool FUN_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, Caster_17ca30*);
extern "C" void __cdecl FUN_0017ca30(Obj* obj, void* name) {
    Caster_17ca30 caster;
    caster.vftable = (void*)DAT_00418964;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0017ca30

namespace fn_f05a6271 {

} // namespace fn_f05a6271

// 0x0017ca60 FUN_0017ca60 (358 B): matches/0x0017ca60.cpp
// sym: _FUN_0017ca60
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::RestPoseTrack>, ParamIntConstRange<hulkfight::motion::RestPoseTrack>, ParamName<hulkfight::motion::RestPoseTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017ca60()
{
    if (DAT_004e12fc == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RestPoseTrack>("timeBegin", &owners::C_16ea30::FUN_0016ea30);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RestPoseTrack>("timeEnd", &owners::Foo_16ea40::FUN_0016ea40);
        params[2] = new ::fight::ParamName< ::hulkfight::motion::RestPoseTrack>("partition", &owners::Obj_16ea50::FUN_0016ea50);
        params[3] = new ::fight::ParamIntConstRange< ::hulkfight::motion::RestPoseTrack>("priority", &owners::O_16ea70::FUN_0016ea70);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RestPoseTrack>("blendInTime", &owners::X_16ea90::FUN_0016ea90);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RestPoseTrack>("blendOutTime", &owners::Obj_16eab0::FUN_0016eab0);
        FUN_002347b0(&DAT_004e12f8, params, 6);
    }
    DAT_004e12fc++;
}

namespace fn_f05a6271 {


// 0x0017cbd0 FUN_0017cbd0 (38 B): matches/0x0017cbd0.cpp
// sym: _FUN_0017cbd0
extern "C" void __cdecl FUN_0017cbd0(Obj* obj, const char* name) {
    Caster_17cbd0 caster;
    caster.vftable = (void*)DAT_00418970;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(Find_00236ac0(name, &caster));
}


// 0x0017cc00 FUN_0017cc00 (38 B): matches/0x0017cc00.cpp
// sym: _FUN_0017cc00
extern "C" void FUN_0017cc00(Track* track, const char* name) {
    Caster_17cc00 caster;
    caster.vftable = (void*)DAT_0041897c;   // (sweep-caster-land) the game's vftable by address
    void* found = Find_00236ac0(name, &caster);
    track->FUN_002367c0(found);
}


} // namespace fn_f05a6271

// 0x0017cc30 FUN_0017cc30 (613 B): matches/0x0017cc30.cpp
// sym: _FUN_0017cc30
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::JointRelativeTrack>, ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>, ParamIntConstRange<hulkfight::motion::JointRelativeTrack>, ParamNameConstList<hulkfight::motion::JointRelativeTrack>, ParamVector<hulkfight::motion::JointRelativeTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017cc30()
{
    if (DAT_004e130c == 0) {
        ::fight::ParamValue* params[11];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointRelativeTrack>("timeBegin", &owners::Obj_16ead0::FUN_0016ead0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointRelativeTrack>("timeEnd", &owners::Obj_16eae0::FUN_0016eae0);
        params[2] = new ::fight::ParamNameConstList< ::hulkfight::motion::JointRelativeTrack>("joint", &owners::Obj_16eaf0::FUN_0016eaf0);
        params[3] = new ::fight::ParamBool< ::hulkfight::motion::JointRelativeTrack>("useRestPose", &owners::Obj_16eb10::FUN_0016eb10);
        params[4] = new ::fight::ParamBool< ::hulkfight::motion::JointRelativeTrack>("hasTranslation", &owners::Obj_16eb30::FUN_0016eb30);
        params[5] = new ::fight::ParamVector< ::hulkfight::motion::JointRelativeTrack>("translation", static_cast<bool (fn_0016eb60::C_16eb60::*)(struct fn_0016eb60::S_16eb60 *)>(&fn_0016eb60::C_16eb60::operator=));
        params[6] = new ::fight::ParamBool< ::hulkfight::motion::JointRelativeTrack>("hasRotation", &owners::Obj_16eb90::FUN_0016eb90);
        params[7] = new ::fight::ParamVector< ::hulkfight::motion::JointRelativeTrack>("rotation", &owners::Obj_16ebc0::FUN_0016ebc0);
        params[8] = new ::fight::ParamIntConstRange< ::hulkfight::motion::JointRelativeTrack>("priority", &owners::Obj_16ec10::FUN_0016ec10);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointRelativeTrack>("blendInTime", &owners::X_16ec30::FUN_0016ec30);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointRelativeTrack>("blendOutTime", &owners::Obj_16ec50::FUN_0016ec50);
        FUN_002347b0(&DAT_004e1308, params, 11);
    }
    DAT_004e130c++;
}



// 0x0017cea0 FUN_0017cea0 (38 B): matches/0x0017cea0.cpp [wrapped: conflict: Find]
// sym: _FUN_0017cea0
namespace fn_0017cea0 {
extern "C" char DAT_00418988[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::SyncToLocatorTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Obj {
  public:
    bool FUN_002367c0(void*);   // (decl1) passes as defined
};
extern void* Find_00236ac0(void*, Caster*);
extern "C" void FUN_0017cea0(Obj* obj, void* name) {
    Caster c;
    c.vftable = (void*)DAT_00418988;   // (sweep-caster-land) the game's vftable by address
    void* x = Find_00236ac0(name, &c);
    obj->FUN_002367c0(x);
}
} // namespace fn_0017cea0

namespace fn_f05a6271 {

} // namespace fn_f05a6271

// 0x0017ced0 FUN_0017ced0 (678 B): matches/0x0017ced0.cpp
// sym: _FUN_0017ced0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>, ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>, ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>, ParamName<hulkfight::motion::SyncToLocatorTrack>, ParamScript<hulkfight::motion::SyncToLocatorTrack>, ParamVector<hulkfight::motion::SyncToLocatorTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017ced0()
{
    if (DAT_004e1314 == 0) {
        ::fight::ParamValue* params[12];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SyncToLocatorTrack>("timeBegin", &owners::Obj_16ec60::FUN_0016ec60);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SyncToLocatorTrack>("timeEnd", &owners::Obj_16ec70::FUN_0016ec70);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SyncToLocatorTrack>("rotationEnd", &owners::Obj_16ec90::FUN_0016ec90);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SyncToLocatorTrack>("translationEnd", &owners::Obj_16ecb0::FUN_0016ecb0);
        params[4] = new ::fight::ParamName< ::hulkfight::motion::SyncToLocatorTrack>("locatorName", &owners::Obj_16ecc0::FUN_0016ecc0);
        params[5] = new ::fight::ParamScript< ::hulkfight::motion::SyncToLocatorTrack>("locatorInitScript", &owners::StrHolder_170130::FUN_00170130);
        params[6] = new ::fight::ParamEnumConstList< ::hulkfight::motion::SyncToLocatorTrack>("rotationOverride", (void*)&DAT_004b7cfc, 3, &owners::Obj_16ed00::FUN_0016ed00);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SyncToLocatorTrack>("orientOffset", &owners::Obj_16ed20::FUN_0016ed20);
        params[8] = new ::fight::ParamVector< ::hulkfight::motion::SyncToLocatorTrack>("positionOffset", &fn_fa642773::Obj::Set);
        params[9] = new ::fight::ParamIntConstRange< ::hulkfight::motion::SyncToLocatorTrack>("priority", &owners::Obj_16ed90::FUN_0016ed90);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SyncToLocatorTrack>("blendInTime", &owners::X_16edb0::FUN_0016edb0);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SyncToLocatorTrack>("blendOutTime", &owners::Obj_16edd0::FUN_0016edd0);
        FUN_002347b0(&DAT_004e1310, params, 12);
    }
    DAT_004e1314++;
}

namespace fn_f05a6271 {


// 0x0017d180 FUN_0017d180 (38 B): matches/0x0017d180.cpp
// sym: _FUN_0017d180
extern "C" void __cdecl FUN_0017d180(Obj* obj, const char* name) {
    Caster_17d180 caster;
    caster.vftable = (void*)DAT_00418994;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(find_00236ac0(name, &caster));
}


// 0x0017d1b0 FUN_0017d1b0 (38 B): matches/0x0017d1b0.cpp
// sym: _FUN_0017d1b0
extern "C" void FUN_0017d1b0(Owner* owner, const char* name) {
    Caster caster;
    caster.vftable = (void*)DAT_004189a0;   // (sweep-caster-land) the game's vftable by address
    Track* t = Find_00236ac0(name, &caster);
    owner->FUN_002367c0(t);
}


// 0x0017d1e0 FUN_0017d1e0 (38 B): matches/0x0017d1e0.cpp
// sym: _FUN_0017d1e0
extern "C" void FUN_0017d1e0(Obj* obj, const char* n) {
    Caster_17d1e0 caster;
    caster.vftable = (void*)DAT_004189ac;   // (sweep-caster-land) the game's vftable by address
    void* x = first_00236ac0(n, &caster);
    obj->FUN_002367c0(x);
}


} // namespace fn_f05a6271

// 0x0017d210 FUN_0017d210 (868 B): matches/0x0017d210.cpp
// sym: _FUN_0017d210
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::MoveJointTrack>, ParamFloatConstRange<hulkfight::motion::MoveJointTrack>, ParamIntConstRange<hulkfight::motion::MoveJointTrack>, ParamNameConstList<hulkfight::motion::MoveJointTrack>, ParamVector<hulkfight::motion::MoveJointTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017d210()
{
    if ((*(int*)&DAT_004e132c) == 0) {
        ::fight::ParamValue* params[16];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MoveJointTrack>("timeBegin", &owners::X_16eeb0::FUN_0016eeb0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MoveJointTrack>("timeEnd", &owners::C_16eed0::FUN_0016eed0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::MoveJointTrack>("attachmentIndex", &owners::X_16eef0::FUN_0016eef0);
        params[3] = new ::fight::ParamNameConstList< ::hulkfight::motion::MoveJointTrack>("moveJoint", &owners::Obj_16ef00::FUN_0016ef00);
        params[4] = new ::fight::ParamNameConstList< ::hulkfight::motion::MoveJointTrack>("startJoint", &fn_fa642773::Obj_16ef10::Get);
        params[5] = new ::fight::ParamVector< ::hulkfight::motion::MoveJointTrack>("offset", &fn_fa642773::Obj_16ef40::Set);
        params[6] = new ::fight::ParamVector< ::hulkfight::motion::MoveJointTrack>("direction", &fn_fa642773::Obj_16ef80::Set);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MoveJointTrack>("distanceStart", &owners::Obj_16efb0::FUN_0016efb0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MoveJointTrack>("distanceEnd", &owners::Thing_16efd0::FUN_0016efd0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MoveJointTrack>("initVelocity", &owners::Obj_16eff0::FUN_0016eff0);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MoveJointTrack>("maxVelocity", &owners::X_16f010::FUN_0016f010);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MoveJointTrack>("acceleration", &owners::X_16f030::FUN_0016f030);
        params[12] = new ::fight::ParamBool< ::hulkfight::motion::MoveJointTrack>("simulateMotion", &owners::X_16f050::FUN_0016f050);
        params[13] = new ::fight::ParamIntConstRange< ::hulkfight::motion::MoveJointTrack>("priority", &owners::X_16f060::FUN_0016f060);
        params[14] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MoveJointTrack>("blendInTime", &owners::Obj_16f070::FUN_0016f070);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MoveJointTrack>("blendOutTime", &owners::Obj_16f080::FUN_0016f080);
        FUN_002347b0(&DAT_004e1328, params, 16);
    }
    (*(int*)&DAT_004e132c)++;
}



// 0x0017d580 FUN_0017d580 (38 B): matches/0x0017d580.cpp [wrapped: conflict: Find]
// sym: _FUN_0017d580
namespace fn_0017d580 {
extern "C" char DAT_004189b8[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToPositionTrack>'s vftable
class Caster_17d580 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, Caster_17d580*);
class Obj {
  public:
    bool FUN_002367c0(void*);
};
extern "C" void __cdecl FUN_0017d580(Obj* obj, void* value) {
    Caster_17d580 caster;
    caster.vftable = (void*)DAT_004189b8;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(Find_00236ac0(value, &caster));
}
} // namespace fn_0017d580

namespace fn_f05a6271 {

// 0x0017d5b0 FUN_0017d5b0 (38 B): matches/0x0017d5b0.cpp
// sym: _FUN_0017d5b0
extern "C" void FUN_0017d5b0(Obj* obj, const char* name) {
    Caster_17d5b0 caster;
    caster.vftable = (void*)DAT_004189c4;   // (sweep-caster-land) the game's vftable by address
    void* p = Find_00236ac0(name, &caster);
    obj->FUN_002367c0(p);
}

} // namespace fn_f05a6271

// 0x0017d5e0 FUN_0017d5e0 (38 B): matches/0x0017d5e0.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_0017d5e0@@YAXPAVHolder@1@PAX@Z
namespace fn_0017d5e0 {
extern "C" char DAT_004189d0[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionStateTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Holder {
  public:
    bool FUN_002367c0(void*);
};
void* Find_00236ac0(void*, Caster*);
void Target(Holder* h, void* x) {
    Caster c;
    c.vftable = (void*)DAT_004189d0;   // (sweep-caster-land) the game's vftable by address
    void* p = Find_00236ac0(x, &c);
    h->FUN_002367c0(p);
}
} // namespace fn_0017d5e0

namespace fn_f05a6271 {

// 0x0017d610 FUN_0017d610 (38 B): matches/0x0017d610.cpp
// sym: _FUN_0017d610
extern "C" void FUN_0017d610(Obj* obj, const char* id) {
    Caster_17d610 caster;
    caster.vftable = (void*)DAT_004189dc;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(Find_00236ac0(id, &caster));
}


// 0x0017d640 FUN_0017d640 (38 B): matches/0x0017d640.cpp
// sym: _FUN_0017d640
extern "C" void FUN_0017d640(Obj* obj, const char* name) {
    Caster_17d640 c;
    c.vftable = (void*)DAT_004189e8;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(find_00236ac0(name, &c));
}


// 0x0017d670 FUN_0017d670 (38 B): matches/0x0017d670.cpp
// sym: _FUN_0017d670
extern "C" void FUN_0017d670(Owner* owner, void* key) {
    Caster_17d670 c;
    c.vftable = (void*)DAT_004189f4;   // (sweep-caster-land) the game's vftable by address
    void* result = Find_00236ac0(key, &c);
    owner->FUN_002367c0(result);
}


} // namespace fn_f05a6271

// 0x0017d6a0 FUN_0017d6a0 (460 B): matches/0x0017d6a0.cpp
// sym: _FUN_0017d6a0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::PushOutTrack>, ParamFloatConstRange<hulkfight::motion::PushOutTrack>, ParamNameConstList<hulkfight::motion::PushOutTrack>, ParamVector<hulkfight::motion::PushOutTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017d6a0()
{
    if (DAT_004e135c == 0) {
        ::fight::ParamValue* params[8];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PushOutTrack>("timeBegin", &owners::Obj_16f250::FUN_0016f250);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PushOutTrack>("timeEnd", &owners::X_16f260::FUN_0016f260);
        params[2] = new ::fight::ParamNameConstList< ::hulkfight::motion::PushOutTrack>("joint", &owners::Obj_16f270::FUN_0016f270);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::PushOutTrack>("offset", &fn_fa642773::Obj_16f2a0::Set);
        params[4] = new ::fight::ParamVector< ::hulkfight::motion::PushOutTrack>("direction", &fn_fa642773::Ctx_16f2e0::Set);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PushOutTrack>("distance", &owners::X_16f310::FUN_0016f310);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PushOutTrack>("velocity", &owners::Thing_16f330::FUN_0016f330);
        params[7] = new ::fight::ParamBool< ::hulkfight::motion::PushOutTrack>("allowY", &owners::X_16f350::FUN_0016f350);
        FUN_002347b0(&DAT_004e1358, params, 8);
    }
    DAT_004e135c++;
}



// 0x0017d870 FUN_0017d870 (38 B): matches/0x0017d870.cpp [wrapped: conflict: find]
// sym: _FUN_0017d870
namespace fn_0017d870 {
extern "C" char DAT_00418a00[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportTrack>'s vftable
class Caster_17d870 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Track {
  public:
    bool FUN_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl find_00236ac0(void*, Caster_17d870*);
extern "C" void FUN_0017d870(Track* t, void* name) {
    Caster_17d870 c;
    c.vftable = (void*)DAT_00418a00;   // (sweep-caster-land) the game's vftable by address
    t->FUN_002367c0(find_00236ac0(name, &c));
}
} // namespace fn_0017d870

namespace fn_f05a6271 {

// 0x0017d8a0 FUN_0017d8a0 (38 B): matches/0x0017d8a0.cpp
// sym: _FUN_0017d8a0
extern "C" void FUN_0017d8a0(Obj* obj, void* id) {
    Caster_17d8a0 caster;
    caster.vftable = (void*)DAT_00418a0c;   // (sweep-caster-land) the game's vftable by address
    void* p = resolve_00236ac0(id, &caster);
    obj->FUN_002367c0(p);
}


} // namespace fn_f05a6271

// 0x0017d8d0 FUN_0017d8d0 (831 B): matches/0x0017d8d0.cpp
// sym: _FUN_0017d8d0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::JointPivotTrackerTrack>, ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>, ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>, ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>, ParamNameConstList<hulkfight::motion::JointPivotTrackerTrack>, ParamVector<hulkfight::motion::JointPivotTrackerTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017d8d0()
{
    if (DAT_004e136c == 0) {
        ::fight::ParamValue* params[15];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("timeBegin", &owners::Obj_16f3b0::FUN_0016f3b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("timeEnd", &owners::Obj_16f3c0::FUN_0016f3c0);
        params[2] = new ::fight::ParamNameConstList< ::hulkfight::motion::JointPivotTrackerTrack>("joint", &owners::O_16f3d0::FUN_0016f3d0);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::JointPivotTrackerTrack>("trackAxis", &fn_fa642773::Obj_16f400::Set);
        params[4] = new ::fight::ParamVector< ::hulkfight::motion::JointPivotTrackerTrack>("pivotAxis", &fn_fa642773::Obj_16f440::Set);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("turnRate", &owners::Obj_16f470::FUN_0016f470);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("angleMin", &owners::Obj_16f4a0::FUN_0016f4a0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("angleMax", &owners::Obj_16f4d0::FUN_0016f4d0);
        params[8] = new ::fight::ParamBool< ::hulkfight::motion::JointPivotTrackerTrack>("targetRequired", &owners::Obj_16f500::FUN_0016f500);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("targetArc", &owners::Obj_16f520::FUN_0016f520);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("targetDistance", &owners::Obj_16f550::FUN_0016f550);
        params[11] = new ::fight::ParamEnumConstList< ::hulkfight::motion::JointPivotTrackerTrack>("targetLocation", (void*)&DAT_004b7cf0, 3, &owners::Obj_16f570::FUN_0016f570);
        params[12] = new ::fight::ParamIntConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("priority", &owners::X_16f590::FUN_0016f590);
        params[13] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("blendInTime", &owners::X_16f5b0::FUN_0016f5b0);
        params[14] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPivotTrackerTrack>("blendOutTime", &owners::X_16f5d0::FUN_0016f5d0);
        FUN_002347b0(&DAT_004e1368, params, 15);
    }
    DAT_004e136c++;
}

namespace fn_f05a6271 {


// 0x0017dc10 FUN_0017dc10 (38 B): matches/0x0017dc10.cpp
// sym: _FUN_0017dc10
extern "C" void FUN_0017dc10(Target* obj, void* name) {
    Caster_17dc10 caster;
    caster.vftable = (void*)DAT_00418a18;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(Find_00236ac0(name, &caster));
}


// 0x0017dc40 FUN_0017dc40 (38 B): matches/0x0017dc40.cpp
// sym: _FUN_0017dc40
extern "C" void FUN_0017dc40(Target* target, void* name) {
    Caster_17dc40 caster;
    caster.vftable = (void*)DAT_00418a24;   // (sweep-caster-land) the game's vftable by address
    target->FUN_002367c0(Find_00236ac0(name, &caster));
}

} // namespace fn_f05a6271

// 0x0017dc70 FUN_0017dc70 (38 B): matches/0x0017dc70.cpp [wrapped: conflict: find]
// sym: _FUN_0017dc70
namespace fn_0017dc70 {
extern "C" char DAT_00418a30[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::CriticalMassDrainTrack>'s vftable
class Caster_17dc70 {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Track {
  public:
    bool FUN_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl find_00236ac0(void*, Caster_17dc70*);
extern "C" void __cdecl FUN_0017dc70(Track* track, void* name) {
    Caster_17dc70 caster;
    caster.vftable = (void*)DAT_00418a30;   // (sweep-caster-land) the game's vftable by address
    track->FUN_002367c0(find_00236ac0(name, &caster));
}
} // namespace fn_0017dc70


// 0x0017dca0 FUN_0017dca0 (38 B): matches/0x0017dca0.cpp [wrapped: conflict: Find]
// sym: _FUN_0017dca0
namespace fn_0017dca0 {
extern "C" char DAT_00418a3c[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckInPropsTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Obj {
  public:
    bool FUN_002367c0(void*);
};
void* __cdecl Find_00236ac0(const char*, Caster*);
extern "C" void FUN_0017dca0(Obj* obj, const char* name) {
    Caster caster;
    caster.vftable = (void*)DAT_00418a3c;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0017dca0


// 0x0017dcd0 FUN_0017dcd0 (38 B): matches/0x0017dcd0.cpp [wrapped: conflict: find]
// sym: _FUN_0017dcd0
namespace fn_0017dcd0 {
extern "C" char DAT_00418a48[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportRelativeTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
struct Owner {
    bool FUN_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl find_00236ac0(hulk_intptr, Caster*);
extern "C" void __cdecl FUN_0017dcd0(Owner* owner, hulk_intptr id) {
    Caster caster;
    caster.vftable = (void*)DAT_00418a48;   // (sweep-caster-land) the game's vftable by address
    owner->FUN_002367c0(find_00236ac0(id, &caster));
}
} // namespace fn_0017dcd0


// 0x0017dd00 FUN_0017dd00 (38 B): matches/0x0017dd00.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_0017dd00@@YAXPAVObj@1@PAX@Z
namespace fn_0017dd00 {
extern "C" char DAT_00418a54[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::IntentionClearTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Obj {
  public:
    bool FUN_002367c0(void*);
};
void* __cdecl Find_00236ac0(void*, Caster*);
void __cdecl Target(Obj* obj, void* p) {
    Caster caster;
    caster.vftable = (void*)DAT_00418a54;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(Find_00236ac0(p, &caster));
}
} // namespace fn_0017dd00


// 0x0017dd30 FUN_0017dd30 (38 B): matches/0x0017dd30.cpp [wrapped: conflict: Find]
// sym: _FUN_0017dd30
namespace fn_0017dd30 {
extern "C" char DAT_00418a60[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportToLocatorTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
extern "C++" __declspec(nothrow) void* Find_00236ac0(void*, Caster*);
class Obj {
  public:
    bool FUN_002367c0(void*);
};
extern "C" void FUN_0017dd30(Obj* obj, void* name) {
    Caster caster;
    caster.vftable = (void*)DAT_00418a60;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0017dd30


// 0x0017dd60 FUN_0017dd60 (38 B): matches/0x0017dd60.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_0017dd60@@YAXPAVObj@1@PAX@Z
namespace fn_0017dd60 {
extern "C" char DAT_00418a6c[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeClearTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Obj {
  public:
    bool FUN_002367c0(void*);
};
void* Find_00236ac0(void*, Caster*);
void Target(Obj* obj, void* key) {
    Caster caster;
    caster.vftable = (void*)DAT_00418a6c;   // (sweep-caster-land) the game's vftable by address
    obj->FUN_002367c0(Find_00236ac0(key, &caster));
}
} // namespace fn_0017dd60


// 0x0017dd90 FUN_0017dd90 (38 B): matches/0x0017dd90.cpp [wrapped: conflict: Find]
// sym: _FUN_0017dd90
namespace fn_0017dd90 {
extern "C" char DAT_00418a78[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::VisibilityTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
class Obj {
  public:
    bool FUN_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, Caster*);
extern "C" void FUN_0017dd90(Obj* obj, void* name) {
    Caster caster;
    caster.vftable = (void*)DAT_00418a78;   // (sweep-caster-land) the game's vftable by address
    void* p = Find_00236ac0(name, &caster);
    obj->FUN_002367c0(p);
}
} // namespace fn_0017dd90


// 0x0017ddc0 FUN_0017ddc0 (38 B): matches/0x0017ddc0.cpp [wrapped: conflict: Obj]
// sym: _FUN_0017ddc0
namespace fn_0017ddc0 {
extern "C" char DAT_00418a84[];   // fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>'s vftable
class Caster {
  public:
    void* vftable;   // (sweep-caster-land) the word its inline constructor writes (was a local polymorphic stand-in:
                     // clang's own vftable natively, whose slot had no definition)
};
extern "C++" __declspec(nothrow) void* __cdecl lookup_00236ac0(void*, Caster*);
class Obj {
  public:
    bool FUN_002367c0(void*);
};
extern "C" bool FUN_0017ddc0(Obj* obj, void* key) {
    Caster caster;
    caster.vftable = (void*)DAT_00418a84;   // (sweep-caster-land) the game's vftable by address
    void* result = lookup_00236ac0(key, &caster);
    return obj->FUN_002367c0(result);
}
} // namespace fn_0017ddc0

namespace fn_f05a6271 {

} // namespace fn_f05a6271

// 0x0017ddf0 FUN_0017ddf0 (562 B): matches/0x0017ddf0.cpp
// sym: _FUN_0017ddf0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::FootPivotTrack>, ParamFloatConstRange<hulkfight::motion::FootPivotTrack>, ParamIntConstRange<hulkfight::motion::FootPivotTrack>, ParamNameConstList<hulkfight::motion::FootPivotTrack>, ParamVector<hulkfight::motion::FootPivotTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017ddf0()
{
    if (DAT_004e13bc == 0) {
        ::fight::ParamValue* params[10];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FootPivotTrack>("timeBegin", &owners::C_16fad0::FUN_0016fad0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FootPivotTrack>("timeEnd", &owners::Obj_16fae0::FUN_0016fae0);
        params[2] = new ::fight::ParamNameConstList< ::hulkfight::motion::FootPivotTrack>("joint", &owners::X_16faf0::FUN_0016faf0);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::FootPivotTrack>("offset", &owners::A_16fb20::FUN_0016fb20);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FootPivotTrack>("facing", &owners::X_16fb50::FUN_0016fb50);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FootPivotTrack>("turningVelocity", &owners::Obj_16fb80::FUN_0016fb80);
        params[6] = new ::fight::ParamBool< ::hulkfight::motion::FootPivotTrack>("useTarget", &owners::C_16fbb0::FUN_0016fbb0);
        params[7] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FootPivotTrack>("priority", &owners::Obj_16fbd0::FUN_0016fbd0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FootPivotTrack>("blendInTime", &owners::X_16fbf0::FUN_0016fbf0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FootPivotTrack>("blendOutTime", &owners::Obj_16fc10::FUN_0016fc10);
        FUN_002347b0(&DAT_004e13b8, params, 10);
    }
    DAT_004e13bc++;
}



// 0x0017e070 fight::TrackFactoryTemplate<hulkfight::motion::ChargeTrack>::vfunc_5 (77 B): matches/0x0017e070.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VChargeTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ChargeTrack>::vfunc_5() {
    ChargeTrack_17e070* p = (ChargeTrack_17e070*)operator new(sizeof(ChargeTrack_17e070));
    if (p) {
        p->Init_00236d40();
        p->vt = (hulk_intptr)&hulk_at_004178c8;
        p->padc = 0.0f;
        p->value10 = -1.0f;
        p->pad14 = 0;
        p->flag18 = 0;
        p->value1c = 1.0f;
        p->enabled = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f05a6271 {

// 0x0017e0c0 fight::TrackFactoryTemplate<hulkfight::motion::ChargeTrack>::vfunc_2 (43 B): matches/0x0017e0c0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f05a6271@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418de0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        ::content::LoadObject::operator delete(this);
    return this;
}

} // namespace fn_f05a6271

// 0x0017e130 fight::TrackFactoryTemplate<hulkfight::motion::SnapToGroundTrack>::vfunc_5 (52 B): matches/0x0017e130.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@TrackFactory@fight@fn_0017e130@@UAEPAXXZ
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_0017e130 {
/* size_t: tree_prelude.h */

namespace fight {
class TrackFactory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void a();
    int x;
    int y;
    int z;
};
class SnapToGroundTrack : public BaseTrack {
  public:
    SnapToGroundTrack() throw();
    virtual void a();
};
SnapToGroundTrack::SnapToGroundTrack() throw() {
    z = 0;
    y = 1;
}
} // namespace motion
} // namespace hulkfight
void* fight::TrackFactory::vfunc_5() {
    return new hulkfight::motion::SnapToGroundTrack;
}
} // namespace fn_0017e130


// 0x0017e170 fight::TrackFactoryTemplate<hulkfight::motion::SnapToGroundTrack>::vfunc_2 (43 B): matches/0x0017e170.cpp [wrapped: same definition as 0x0017e0c0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0017e170@@QAEPAXE@Z
namespace fn_0017e170 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00418dfc;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0016ff00();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};


void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418dfc;
    base1_dtor_0016ff00();
    base2_dtor_00236ab0();
    if (flags & 1)
        ::content::LoadObject::operator delete(this);
    return this;
}
} // namespace fn_0017e170

