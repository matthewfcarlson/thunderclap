// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0017bc70..0x0017e1a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SnapToGroundTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f05a6271 {
#define TREE_TU_END }
namespace fn_f05a6271 {} using namespace fn_f05a6271;
namespace fn_f05a6271 {
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
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
class Caster_17cbd0 {
  public:
    virtual bool Dummy_00178f00(void*);
};
class Obj {
  public:
    void use_002367c0(void*);
    void Apply_002367c0(void*);
    void set_002367c0(void*);
    void second_002367c0(int);
    void Process_002367c0(void*);
    void Apply_002367c0(int);
};
void* __cdecl Find_00236ac0(const char*, Caster_17cbd0*);
class Caster_17cc00 {
  public:
    virtual bool Cast_00178f60(void*);
};
extern void* Find_00236ac0(const char*, Caster_17cc00*);
class Track {
  public:
    void Set_002367c0(void*);
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
class Caster_17d180 {
  public:
    virtual bool cast_00179100(void*);
};
void* __cdecl find_00236ac0(const char*, Caster_17d180*);
class Caster {
  public:
    virtual bool Cast_00179160(void*);
};
class Owner {
  public:
    void Attach_002367c0(Track*);
    void Apply_002367c0(void*);
};
Track* Find_00236ac0(const char*, Caster*);
class Caster_17d1e0 {
  public:
    virtual bool Fnf_001791e0(void*);
};
int first_00236ac0(int, Caster_17d1e0*);
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
class Caster_17d5b0 {
  public:
    virtual bool cast_00179360(void*);
};
extern void* __cdecl Find_00236ac0(const char*, Caster_17d5b0*);
class Caster_17d610 {
  public:
    virtual bool Cast_00179460(void*);
};
extern int __cdecl Find_00236ac0(int, Caster_17d610*);
class Caster_17d640 {
  public:
    virtual bool cast_001794c0(void*);
};
void* find_00236ac0(const char*, Caster_17d640*);
class Caster_17d670 {
  public:
    virtual bool Cast_00179520(void*);
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
class Caster_17d8a0 {
  public:
    virtual bool Fnf_00179640(void*);
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
class Caster_17dc10 {
  public:
    virtual int Cast_00179720(void*);
};
class Target {
  public:
    void Set_002367c0(void*);
};
void* Find_00236ac0(void*, Caster_17dc10*);
class Caster_17dc40 {
  public:
    virtual bool Cast_001797a0(void*);
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
        operator_delete(this);
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
        opdel(this);
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
        opdel(this);
    }
    return this;
}

} // namespace fn_f05a6271

// 0x0017be60 hulkfight::motion::MomentumXZAddTrack::vfunc_10 (70 B): matches/0x0017be60.cpp
// sym: ?vfunc_10@MomentumXZAddTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00119fb0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MomentumXZAddTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17be60 a = (u32_17be60)__p0; u32_17be60 b = (u32_17be60)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_17be60, &TypeB, 0)) {
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
        opdel(this);
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
        opdel(this);
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
        opdel(this);
    }
    return this;
}


// 0x0017c080 fight::ParamNameConstList<hulkfight::motion::JointTrackerTrack>::vfunc_7 (12 B): matches/0x0017c080.cpp
// sym: ?vfunc_6@ParamBranch@fn_f05a6271@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_0017c510


// 0x0017c520 fight::ParamNameConstList<hulkfight::motion::JointTrackerTrack>::vfunc_0 (30 B): matches/0x0017c520.cpp
// sym: ??_G?$ParamNameConstList@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::JointTrackerTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::JointTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x17c520)
#endif


// 0x0017c540 fight::ParamName<hulkfight::motion::RestPoseTrack>::vfunc_0 (30 B): matches/0x0017c540.cpp
// sym: ??_G?$ParamName@VRestPoseTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::RestPoseTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::RestPoseTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x17c540)
#endif


// 0x0017c560 fight::ParamNameConstList<hulkfight::motion::JointRelativeTrack>::vfunc_0 (30 B): matches/0x0017c560.cpp
// sym: ??_G?$ParamNameConstList@VJointRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::JointRelativeTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::JointRelativeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x17c560)
#endif


// 0x0017c580 fight::ParamName<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x0017c580.cpp
// sym: ??_G?$ParamName@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::SyncToLocatorTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::SyncToLocatorTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x17c580)
#endif


// 0x0017c5a0 fight::ParamNameConstList<hulkfight::motion::MoveJointTrack>::vfunc_0 (30 B): matches/0x0017c5a0.cpp
// sym: ??_G?$ParamNameConstList@VMoveJointTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::MoveJointTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::MoveJointTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x17c5a0)
#endif


// 0x0017c5c0 fight::ParamNameConstList<hulkfight::motion::PushOutTrack>::vfunc_0 (30 B): matches/0x0017c5c0.cpp
// sym: ??_G?$ParamNameConstList@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::PushOutTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::PushOutTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x17c5c0)
#endif


// 0x0017c5e0 fight::ParamNameConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (30 B): matches/0x0017c5e0.cpp
// sym: ??_G?$ParamNameConstList@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::JointPivotTrackerTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::JointPivotTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x17c5e0)
#endif


// 0x0017c600 fight::ParamNameConstList<hulkfight::motion::FootPivotTrack>::vfunc_0 (30 B): matches/0x0017c600.cpp
// sym: ??_G?$ParamNameConstList@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::FootPivotTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::FootPivotTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x17c600)
#endif


// 0x0017c620 FUN_0017c620 (38 B): matches/0x0017c620.cpp [wrapped: conflict: Find; fight::TrackFactoryCasterTemplate]
// sym: _FUN_0017c620
namespace fn_0017c620 {
namespace fight {
class TrackFactoryCasterTemplate {
  public:
    virtual bool Cast_00178d00(void*);
};
} // namespace fight
class Thing {
  public:
    void Set_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* Find_00236ac0(const char*, fight::TrackFactoryCasterTemplate*);
extern "C" void FUN_0017c620(Thing* thing, const char* name) {
    fight::TrackFactoryCasterTemplate caster;
    thing->Set_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0017c620

namespace fn_f05a6271 {

// 0x0017c650 FUN_0017c650 (933 B): equivalent/0x0017c650.cpp
// sym: _FUN_0017c650 @ed9f49ce204b @w15d6c7af4405
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_0017c650 @ 0x0017c650
extern "C" void FUN_0017c650()
{
    if (DAT_004e12ec == 0) {
        void* params[17];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("timeBegin", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e720);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("timeEnd", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e730);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_17c650<hulkfight::motion::JointTrackerTrack_17c650>("joint", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e740);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_17c650<hulkfight::motion::JointTrackerTrack_17c650>("north", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e770);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_17c650<hulkfight::motion::JointTrackerTrack_17c650>("east", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e7b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("turnRate", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e7e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("vertMinAngle", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e810);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("vertMaxAngle", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e840);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("horzMinAngle", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e870);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("horzMaxAngle", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e8a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_17c650<hulkfight::motion::JointTrackerTrack_17c650>("targetRequired", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e8d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("targetArc", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e8f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("targetDistance", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e920);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamEnumConstList_17c650<hulkfight::motion::JointTrackerTrack_17c650>("targetLocation", ((const char**)&DAT_004b7cf0), 3, (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e940);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamIntConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("priority", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e960);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("blendInTime", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e980);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("blendOutTime", (void (hulkfight::motion::JointTrackerTrack_17c650::*)())&hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e9a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e12e8), params, 17);
    }
    DAT_004e12ec++;
}

} // namespace fn_f05a6271

// 0x0017ca00 FUN_0017ca00 (38 B): matches/0x0017ca00.cpp [wrapped: conflict: Find]
// sym: _FUN_0017ca00
namespace fn_0017ca00 {
class Caster_17ca00 {
  public:
    virtual bool Cast_00178de0(void*);
};
class Obj {
  public:
    void Apply_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, Caster_17ca00*);
extern "C" void __cdecl FUN_0017ca00(Obj* obj, void* value) {
    Caster_17ca00 caster;
    void* p = Find_00236ac0(value, &caster);
    obj->Apply_002367c0(p);
}
} // namespace fn_0017ca00


// 0x0017ca30 FUN_0017ca30 (38 B): matches/0x0017ca30.cpp [wrapped: conflict: Find]
// sym: _FUN_0017ca30
namespace fn_0017ca30 {
class Caster_17ca30 {
  public:
    virtual bool Cast_00178e80(void*);
};
class Obj {
  public:
    void Set_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, Caster_17ca30*);
extern "C" void __cdecl FUN_0017ca30(Obj* obj, void* name) {
    Caster_17ca30 caster;
    obj->Set_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0017ca30

namespace fn_f05a6271 {

// 0x0017ca60 FUN_0017ca60 (358 B): equivalent/0x0017ca60.cpp
// sym: _FUN_0017ca60 @c2779d21229a @w7aac995ae6c0
// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 14/14)
// FUN_0017ca60 @ 0x0017ca60
extern "C" void FUN_0017ca60()
{
    if (DAT_004e12fc == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RestPoseTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<RestPoseTrack>("timeBegin", (void (RestPoseTrack::*)())&RestPoseTrack::FUN_0016ea30);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RestPoseTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<RestPoseTrack>("timeEnd", (void (RestPoseTrack::*)())&RestPoseTrack::FUN_0016ea40);
        mem = FUN_0008d690((int)sizeof(ParamName<RestPoseTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<RestPoseTrack>("partition", &RestPoseTrack::FUN_0016ea50);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<RestPoseTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<RestPoseTrack>("priority", (void (RestPoseTrack::*)())&RestPoseTrack::FUN_0016ea70);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RestPoseTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<RestPoseTrack>("blendInTime", (void (RestPoseTrack::*)())&RestPoseTrack::FUN_0016ea90);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RestPoseTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<RestPoseTrack>("blendOutTime", (void (RestPoseTrack::*)())&RestPoseTrack::FUN_0016eab0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e12f8), params, 6);
    }
    DAT_004e12fc++;
}


// 0x0017cbd0 FUN_0017cbd0 (38 B): matches/0x0017cbd0.cpp
// sym: _FUN_0017cbd0
extern "C" void __cdecl FUN_0017cbd0(Obj* obj, const char* name) {
    Caster_17cbd0 caster;
    obj->Apply_002367c0(Find_00236ac0(name, &caster));
}


// 0x0017cc00 FUN_0017cc00 (38 B): matches/0x0017cc00.cpp
// sym: _FUN_0017cc00
extern "C" void FUN_0017cc00(Track* track, const char* name) {
    Caster_17cc00 caster;
    void* found = Find_00236ac0(name, &caster);
    track->Set_002367c0(found);
}


// 0x0017cc30 FUN_0017cc30 (613 B): equivalent/0x0017cc30.cpp
// sym: _FUN_0017cc30 @19491d48245d @w23b1deba88f0
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_0017cc30 @ 0x0017cc30
extern "C" void FUN_0017cc30()
{
    if (DAT_004e130c == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17cc30<JointRelativeTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17cc30<JointRelativeTrack>("timeBegin", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016ead0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17cc30<JointRelativeTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17cc30<JointRelativeTrack>("timeEnd", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016eae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17cc30<JointRelativeTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_17cc30<JointRelativeTrack>("joint", &JointRelativeTrack::FUN_0016eaf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17cc30<JointRelativeTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_17cc30<JointRelativeTrack>("useRestPose", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016eb10);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17cc30<JointRelativeTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_17cc30<JointRelativeTrack>("hasTranslation", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016eb30);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17cc30<JointRelativeTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector_17cc30<JointRelativeTrack>("translation", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016eb60);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17cc30<JointRelativeTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_17cc30<JointRelativeTrack>("hasRotation", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016eb90);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17cc30<JointRelativeTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_17cc30<JointRelativeTrack>("rotation", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016ebc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17cc30<JointRelativeTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_17cc30<JointRelativeTrack>("priority", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016ec10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17cc30<JointRelativeTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17cc30<JointRelativeTrack>("blendInTime", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016ec30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17cc30<JointRelativeTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_17cc30<JointRelativeTrack>("blendOutTime", (void (JointRelativeTrack::*)())&JointRelativeTrack::FUN_0016ec50);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1308), params, 11);
    }
    DAT_004e130c++;
}

} // namespace fn_f05a6271

// 0x0017cea0 FUN_0017cea0 (38 B): matches/0x0017cea0.cpp [wrapped: conflict: Find]
// sym: _FUN_0017cea0
namespace fn_0017cea0 {
class Caster {
  public:
    virtual bool Cast_00179020(void*);
};
class Obj {
  public:
    void Use_002367c0(int);
};
extern int Find_00236ac0(void*, Caster*);
extern "C" void FUN_0017cea0(Obj* obj, void* name) {
    Caster c;
    int x = Find_00236ac0(name, &c);
    obj->Use_002367c0(x);
}
} // namespace fn_0017cea0

namespace fn_f05a6271 {

// 0x0017ced0 FUN_0017ced0 (678 B): equivalent/0x0017ced0.cpp
// sym: _FUN_0017ced0 @2a2028bfaf9b @w4378baffa689
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_0017ced0 @ 0x0017ced0
extern "C" void FUN_0017ced0()
{
    if (DAT_004e1314 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("timeBegin", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ec60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("timeEnd", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ec70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("rotationEnd", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ec90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("translationEnd", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ecb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("locatorName", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ecc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamScript_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamScript_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("locatorInitScript", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_00170130);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamEnumConstList_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("rotationOverride", ((const char**)&DAT_004b7cfc), 3, (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ed00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("orientOffset", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ed20);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("positionOffset", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ed60);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamIntConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("priority", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ed90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("blendInTime", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016edb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("blendOutTime", (void (hulkfight::motion::SyncToLocatorTrack_17ced0::*)())&hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016edd0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1310), params, 12);
    }
    DAT_004e1314++;
}


// 0x0017d180 FUN_0017d180 (38 B): matches/0x0017d180.cpp
// sym: _FUN_0017d180
extern "C" void __cdecl FUN_0017d180(Obj* obj, const char* name) {
    Caster_17d180 caster;
    obj->set_002367c0(find_00236ac0(name, &caster));
}


// 0x0017d1b0 FUN_0017d1b0 (38 B): matches/0x0017d1b0.cpp
// sym: _FUN_0017d1b0
extern "C" void FUN_0017d1b0(Owner* owner, const char* name) {
    Caster caster;
    Track* t = Find_00236ac0(name, &caster);
    owner->Attach_002367c0(t);
}


// 0x0017d1e0 FUN_0017d1e0 (38 B): matches/0x0017d1e0.cpp
// sym: _FUN_0017d1e0
extern "C" void FUN_0017d1e0(Obj* obj, int n) {
    Caster_17d1e0 caster;
    int x = first_00236ac0(n, &caster);
    obj->second_002367c0(x);
}


// 0x0017d210 FUN_0017d210 (868 B): equivalent/0x0017d210.cpp
// sym: _FUN_0017d210 @349d8f786f61 @wc0fd0d999dbf
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0017d210 @ 0x0017d210
extern "C" void FUN_0017d210()
{
    if (hulk_at_004e132c == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("timeBegin", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016eeb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("timeEnd", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016eed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("attachmentIndex", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016eef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamNameConstList_17d210<hulkfight::motion::MoveJointTrack_17d210>("moveJoint", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016ef00);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamNameConstList_17d210<hulkfight::motion::MoveJointTrack_17d210>("startJoint", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016ef10);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector_17d210<hulkfight::motion::MoveJointTrack_17d210>("offset", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016ef40);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_17d210<hulkfight::motion::MoveJointTrack_17d210>("direction", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016ef80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("distanceStart", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016efb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("distanceEnd", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016efd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("initVelocity", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016eff0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("maxVelocity", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016f010);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("acceleration", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016f030);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamBool_17d210<hulkfight::motion::MoveJointTrack_17d210>("simulateMotion", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016f050);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("priority", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016f060);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("blendInTime", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016f070);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("blendOutTime", (void (hulkfight::motion::MoveJointTrack_17d210::*)())&hulkfight::motion::MoveJointTrack_17d210::FUN_0016f080);
        FUN_002347b0(&hulk_at_004e1328, params, 16);
    }
    hulk_at_004e132c++;
}

} // namespace fn_f05a6271

// 0x0017d580 FUN_0017d580 (38 B): matches/0x0017d580.cpp [wrapped: conflict: Find]
// sym: _FUN_0017d580
namespace fn_0017d580 {
class Caster_17d580 {
  public:
    virtual bool Cast_001792a0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, Caster_17d580*);
class Obj {
  public:
    void Take_002367c0(void*);
};
extern "C" void __cdecl FUN_0017d580(Obj* obj, void* value) {
    Caster_17d580 caster;
    obj->Take_002367c0(Find_00236ac0(value, &caster));
}
} // namespace fn_0017d580

namespace fn_f05a6271 {

// 0x0017d5b0 FUN_0017d5b0 (38 B): matches/0x0017d5b0.cpp
// sym: _FUN_0017d5b0
extern "C" void FUN_0017d5b0(Obj* obj, const char* name) {
    Caster_17d5b0 caster;
    void* p = Find_00236ac0(name, &caster);
    obj->Process_002367c0(p);
}

} // namespace fn_f05a6271

// 0x0017d5e0 FUN_0017d5e0 (38 B): matches/0x0017d5e0.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_0017d5e0@@YAXPAVHolder@1@PAX@Z
namespace fn_0017d5e0 {
class Caster {
  public:
    virtual bool Fnf_001793e0(void*);
};
class Holder {
  public:
    void Set_002367c0(void*);
};
void* Find_00236ac0(void*, Caster*);
void Target(Holder* h, void* x) {
    Caster c;
    void* p = Find_00236ac0(x, &c);
    h->Set_002367c0(p);
}
} // namespace fn_0017d5e0

namespace fn_f05a6271 {

// 0x0017d610 FUN_0017d610 (38 B): matches/0x0017d610.cpp
// sym: _FUN_0017d610
extern "C" void FUN_0017d610(Obj* obj, int id) {
    Caster_17d610 caster;
    obj->Apply_002367c0(Find_00236ac0(id, &caster));
}


// 0x0017d640 FUN_0017d640 (38 B): matches/0x0017d640.cpp
// sym: _FUN_0017d640
extern "C" void FUN_0017d640(Obj* obj, const char* name) {
    Caster_17d640 c;
    obj->use_002367c0(find_00236ac0(name, &c));
}


// 0x0017d670 FUN_0017d670 (38 B): matches/0x0017d670.cpp
// sym: _FUN_0017d670
extern "C" void FUN_0017d670(Owner* owner, void* key) {
    Caster_17d670 c;
    void* result = Find_00236ac0(key, &c);
    owner->Apply_002367c0(result);
}


// 0x0017d6a0 FUN_0017d6a0 (460 B): equivalent/0x0017d6a0.cpp
// sym: _FUN_0017d6a0 @61eae1ca18e2 @w793c539dce88
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_0017d6a0 @ 0x0017d6a0
extern "C" void FUN_0017d6a0()
{
    if (DAT_004e135c == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PushOutTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<PushOutTrack>("timeBegin", (void (PushOutTrack::*)())&PushOutTrack::FUN_0016f250);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PushOutTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<PushOutTrack>("timeEnd", (void (PushOutTrack::*)())&PushOutTrack::FUN_0016f260);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<PushOutTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamNameConstList<PushOutTrack>("joint", &PushOutTrack::FUN_0016f270);
        mem = FUN_0008d690((int)sizeof(ParamVector<PushOutTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<PushOutTrack>("offset", (void (PushOutTrack::*)())&PushOutTrack::FUN_0016f2a0);
        mem = FUN_0008d690((int)sizeof(ParamVector<PushOutTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<PushOutTrack>("direction", (void (PushOutTrack::*)())&PushOutTrack::FUN_0016f2e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PushOutTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<PushOutTrack>("distance", (void (PushOutTrack::*)())&PushOutTrack::FUN_0016f310);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PushOutTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<PushOutTrack>("velocity", (void (PushOutTrack::*)())&PushOutTrack::FUN_0016f330);
        mem = FUN_0008d690((int)sizeof(ParamBool<PushOutTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamBool<PushOutTrack>("allowY", (void (PushOutTrack::*)())&PushOutTrack::FUN_0016f350);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1358), params, 8);
    }
    DAT_004e135c++;
}

} // namespace fn_f05a6271

// 0x0017d870 FUN_0017d870 (38 B): matches/0x0017d870.cpp [wrapped: conflict: find]
// sym: _FUN_0017d870
namespace fn_0017d870 {
class Caster_17d870 {
  public:
    virtual bool Fnf_001795c0(void*);
};
class Track {
  public:
    void get_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl find_00236ac0(void*, Caster_17d870*);
extern "C" void FUN_0017d870(Track* t, void* name) {
    Caster_17d870 c;
    t->get_002367c0(find_00236ac0(name, &c));
}
} // namespace fn_0017d870

namespace fn_f05a6271 {

// 0x0017d8a0 FUN_0017d8a0 (38 B): matches/0x0017d8a0.cpp
// sym: _FUN_0017d8a0
extern "C" void FUN_0017d8a0(Obj* obj, void* id) {
    Caster_17d8a0 caster;
    void* p = resolve_00236ac0(id, &caster);
    obj->use_002367c0(p);
}


// 0x0017d8d0 FUN_0017d8d0 (831 B): equivalent/0x0017d8d0.cpp
// sym: _FUN_0017d8d0 @3b2a4c945e8b @w54a93db2ac84
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/32)
// FUN_0017d8d0 @ 0x0017d8d0
extern "C" void FUN_0017d8d0()
{
    if (DAT_004e136c == 0) {
        void* params[15];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("timeBegin", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f3b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("timeEnd", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f3c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("joint", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f3d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("trackAxis", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f400);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("pivotAxis", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f440);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("turnRate", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f470);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("angleMin", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f4a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("angleMax", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f4d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("targetRequired", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f500);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("targetArc", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f520);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("targetDistance", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f550);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamEnumConstList_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("targetLocation", ((const char**)&DAT_004b7cf0), 3, (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f570);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("priority", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f590);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("blendInTime", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f5b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("blendOutTime", (void (hulkfight::motion::JointPivotTrackerTrack_17d8d0::*)())&hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f5d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1368), params, 15);
    }
    DAT_004e136c++;
}


// 0x0017dc10 FUN_0017dc10 (38 B): matches/0x0017dc10.cpp
// sym: _FUN_0017dc10
extern "C" void FUN_0017dc10(Target* obj, void* name) {
    Caster_17dc10 caster;
    obj->Set_002367c0(Find_00236ac0(name, &caster));
}


// 0x0017dc40 FUN_0017dc40 (38 B): matches/0x0017dc40.cpp
// sym: _FUN_0017dc40
extern "C" void FUN_0017dc40(Target* target, void* name) {
    Caster_17dc40 caster;
    target->Set_002367c0(Find_00236ac0(name, &caster));
}

} // namespace fn_f05a6271

// 0x0017dc70 FUN_0017dc70 (38 B): matches/0x0017dc70.cpp [wrapped: conflict: find]
// sym: _FUN_0017dc70
namespace fn_0017dc70 {
class Caster_17dc70 {
  public:
    virtual bool foo_00179800(void*);
};
class Track {
  public:
    void apply_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl find_00236ac0(void*, Caster_17dc70*);
extern "C" void __cdecl FUN_0017dc70(Track* track, void* name) {
    Caster_17dc70 caster;
    track->apply_002367c0(find_00236ac0(name, &caster));
}
} // namespace fn_0017dc70


// 0x0017dca0 FUN_0017dca0 (38 B): matches/0x0017dca0.cpp [wrapped: conflict: Find]
// sym: _FUN_0017dca0
namespace fn_0017dca0 {
class Caster {
  public:
    virtual bool Cast_00179860(void*);
};
class Obj {
  public:
    void Set_002367c0(void*);
};
void* __cdecl Find_00236ac0(const char*, Caster*);
extern "C" void FUN_0017dca0(Obj* obj, const char* name) {
    Caster caster;
    obj->Set_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0017dca0


// 0x0017dcd0 FUN_0017dcd0 (38 B): matches/0x0017dcd0.cpp [wrapped: conflict: find]
// sym: _FUN_0017dcd0
namespace fn_0017dcd0 {
class Caster {
  public:
    virtual bool cast_001798e0(void*);
};
struct Owner {
    void add_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl find_00236ac0(int, Caster*);
extern "C" void __cdecl FUN_0017dcd0(Owner* owner, hulk_intptr id) {
    Caster caster;
    owner->add_002367c0(find_00236ac0(id, &caster));
}
} // namespace fn_0017dcd0


// 0x0017dd00 FUN_0017dd00 (38 B): matches/0x0017dd00.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_0017dd00@@YAXPAVObj@1@PAX@Z
namespace fn_0017dd00 {
class Caster {
  public:
    virtual bool Cast_00179960(void*);
};
class Obj {
  public:
    void Act_002367c0(void*);
};
void* __cdecl Find_00236ac0(void*, Caster*);
void __cdecl Target(Obj* obj, void* p) {
    Caster caster;
    obj->Act_002367c0(Find_00236ac0(p, &caster));
}
} // namespace fn_0017dd00


// 0x0017dd30 FUN_0017dd30 (38 B): matches/0x0017dd30.cpp [wrapped: conflict: Find]
// sym: _FUN_0017dd30
namespace fn_0017dd30 {
class Caster {
  public:
    virtual bool Cast_001799c0(void*);
};
extern "C++" __declspec(nothrow) void* Find_00236ac0(void*, Caster*);
class Obj {
  public:
    void Use_002367c0(void*);
};
extern "C" void FUN_0017dd30(Obj* obj, void* name) {
    Caster caster;
    obj->Use_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0017dd30


// 0x0017dd60 FUN_0017dd60 (38 B): matches/0x0017dd60.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_0017dd60@@YAXPAVObj@1@PAX@Z
namespace fn_0017dd60 {
class Caster {
  public:
    virtual bool Fn_00179a60(void*);
};
class Obj {
  public:
    void Do_002367c0(void*);
};
void* Find_00236ac0(void*, Caster*);
void Target(Obj* obj, void* key) {
    Caster caster;
    obj->Do_002367c0(Find_00236ac0(key, &caster));
}
} // namespace fn_0017dd60


// 0x0017dd90 FUN_0017dd90 (38 B): matches/0x0017dd90.cpp [wrapped: conflict: Find]
// sym: _FUN_0017dd90
namespace fn_0017dd90 {
class Caster {
  public:
    virtual bool Fnf_00179ae0(void*);
};
class Obj {
  public:
    void Set_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find(void*, Caster*);
extern "C" void FUN_0017dd90(Obj* obj, void* name) {
    Caster caster;
    void* p = Find(name, &caster);
    obj->Set_002367c0(p);
}
} // namespace fn_0017dd90


// 0x0017ddc0 FUN_0017ddc0 (38 B): matches/0x0017ddc0.cpp [wrapped: conflict: Obj]
// sym: _FUN_0017ddc0
namespace fn_0017ddc0 {
class Caster {
  public:
    virtual bool cast_00179b60(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl lookup_00236ac0(void*, Caster*);
class Obj {
  public:
    void* use_002367c0(void*);
};
extern "C" void* FUN_0017ddc0(Obj* obj, void* key) {
    Caster caster;
    void* result = lookup_00236ac0(key, &caster);
    return obj->use_002367c0(result);
}
} // namespace fn_0017ddc0

namespace fn_f05a6271 {

// 0x0017ddf0 FUN_0017ddf0 (562 B): equivalent/0x0017ddf0.cpp
// sym: _FUN_0017ddf0 @8fae0e3dc400 @w22c2a1c9ba59
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 22/22)
// FUN_0017ddf0 @ 0x0017ddf0
extern "C" void FUN_0017ddf0()
{
    if (DAT_004e13bc == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("timeBegin", (void (FootPivotTrack::*)())&FootPivotTrack::FUN_0016fad0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("timeEnd", (void (FootPivotTrack::*)())&FootPivotTrack::FUN_0016fae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17ddf0<FootPivotTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_17ddf0<FootPivotTrack>("joint", &FootPivotTrack::FUN_0016faf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17ddf0<FootPivotTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_17ddf0<FootPivotTrack>("offset", (void (FootPivotTrack::*)())&FootPivotTrack::FUN_0016fb20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("facing", (void (FootPivotTrack::*)())&FootPivotTrack::FUN_0016fb50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("turningVelocity", (void (FootPivotTrack::*)())&FootPivotTrack::FUN_0016fb80);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17ddf0<FootPivotTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_17ddf0<FootPivotTrack>("useTarget", (void (FootPivotTrack::*)())&FootPivotTrack::FUN_0016fbb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17ddf0<FootPivotTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_17ddf0<FootPivotTrack>("priority", (void (FootPivotTrack::*)())&FootPivotTrack::FUN_0016fbd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("blendInTime", (void (FootPivotTrack::*)())&FootPivotTrack::FUN_0016fbf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("blendOutTime", (void (FootPivotTrack::*)())&FootPivotTrack::FUN_0016fc10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e13b8), params, 10);
    }
    DAT_004e13bc++;
}

} // namespace fn_f05a6271

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
        thunk_delete_00263f30(this);
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

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418dfc;
    base1_dtor_0016ff00();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0017e170

