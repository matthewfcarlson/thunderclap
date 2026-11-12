// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa3ff49b {
#define TREE_TU_END }
namespace fn_fa3ff49b {} using namespace fn_fa3ff49b;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fa3ff49b {
struct Src_61ea0 {
    int a;
    int b;
    int c;
};
class Obj_61ea0 {
  public:
    char pad[0x1c];
    int m1;
    int m2;
    int m3;
    bool Set(const Src_61ea0* s);
};
const float k = 0.017453292f;
class X_61f70 {
  public:
    char pad[16];
    int m10;
    char SetTimeBegin_00061f70(int v);
};
class A_61f80 {
  public:
    char pad[0x14];
    int value;
    bool SetAttachmentIndex_00061f80(int x);
};
class Obj_61f90 {
  public:
    char pad[0x0c];
    int m;
    char SetEvent_00061f90(int x);
};
struct M_61fa0 {
    int v;
};
class O_61fa0 {
    char p[0x10];
    M_61fa0 m;

  public:
    char Set(int x);
};
extern int* hulk_at_004dc618;
class CCondition_62000 {
  public:
    virtual int vfunc_0(int);
};
struct Param_62140 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_62140 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" void __cdecl FUN_00267760(void*, int, const char*, ...);
typedef unsigned int u32_621a0;
struct Track_621a0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
};
struct Param_621a0 {
    virtual void p1();
    virtual void p2();
    virtual void p4();
};
extern void* alloc_0008d690(hulk_uintptr);
struct CWeaponCollisionAction_621a0 {
    u32_621a0 construct_0001b080(u32_621a0, CWeaponCollisionTrack*, int);
};
extern const int hulk_at_00494b44;
extern const int hulk_at_00494b60;
extern int* hulk_at_004dc620;
class CCondition_62210 {
  public:
    virtual int vfunc_0(int);
};
struct Param_62270 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_62270 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Vec {
    float x, y, z;
};
struct Helper_62300 {
    int Fnf_0001ea30(CSmartPropAttachTrack*, hulk_intptr);
};
extern "C" Helper_62300* __cdecl FUN_0008d690(int);
extern int* hulk_at_004dc628;
class CCondition_62350 {
  public:
    virtual int vfunc_0(int);
};
struct Param_623f0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_623f0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int hulk_at_003faf9c;
class Part_62400 {
  public:
    int x[2];
    void Init_0027af50();
};
class CSmartPropUpdateAttachmentTrack_62400 {
  public:
    hulk_intptr vt;
    char pad[0x14];
    Part_62400 p18;
    Part_62400 p20;
    void Final_00068c70();
    void Run();
};
struct Vector3 { float x, y, z; };
struct Angles {
  public:
    char _m_pad_0[0x38];
    float x;
    float y;
    float z;
    void FUN_00062280(float *out);
    void FUN_00062430(Vector3 *out);
};
extern int* hulk_at_004dc630;
class CCondition_62500 {
  public:
    virtual int vfunc_0(int);
};
struct V {
    float x, y, z;
};
} // namespace fn_fa3ff49b
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned);
#endif
namespace fn_fa3ff49b {
void* FUN_0008d690(unsigned int size);
struct Helper_626e0 {
    int FUN_0001eff0(CSmartPropSpawnTrack*, hulk_intptr);
};
extern int* hulk_at_004dc638;
class CCondition_62730 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc640;
class CCondition_627f0 {
  public:
    virtual int vfunc_0(int);
};
class Helper_62860 {
  public:
    int go_0001f1f0(hulk_intptr);
};
extern int* hulk_at_004dc648;
class CCondition_628a0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc650;
class CCondition_62990 {
  public:
    virtual int vfunc_0(int);
};
class CTrack_629a0 {
  public:
    CTrack_629a0();
    virtual hulk_intptr baseMethod_00062990(int);
    char pad[4];
};
class CSmartPropThrowingTrack_629a0 : public CTrack_629a0 {
  public:
    virtual bool method1_00234270(void*);
    int m8;
    int mC;
    float m10;
    CSmartPropThrowingTrack_629a0();
};
extern int* hulk_at_004dc658;
class CCondition_62a70 {
  public:
    virtual int vfunc_0(int);
};
class Obj_62ac0 {
    char pad[0x10];

  public:
    unsigned int value;
};
extern int* hulk_at_004dc660;
class CCondition_62b40 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc668;
class CCondition_62c00 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc670;
class CCondition_62cc0 {
  public:
    virtual int vfunc_0(int);
};
class CStageCondition_630d0;
class ParamValue_630d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_630d0 : public ParamValue_630d0 {
  public:
    int pad;
};
class CStageCondition_63120;
class ParamValue_63120 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63120 : public ParamValue_63120 {
  public:
    int pad;
};
class CStageCondition_63170;
class ParamValue_63170 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63170 : public ParamValue_63170 {
  public:
    int pad;
};
struct CAxisArcCondition_631b0;
class CStageCondition_631c0 {};
class ParamValue_631c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_631c0 : public ParamValue_631c0 {
  public:
    virtual void f();
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class CStageCondition_63280;
class ParamValue_63280 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63280 : public ParamValue_63280 {
  public:
    int pad;
};
class CStageCondition_632d0;
class ParamValue_632d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_632d0 : public ParamValue_632d0 {
  public:
    int pad;
};
class ParamValue_63300 {
  public:
    char pad[12];
};
class ParamValueBool_63300 : public ParamValue_63300 {};
class CCollisionTrack_63300;
class CStageCondition_633a0;
class ParamValue_633a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_633a0 : public ParamValue_633a0 {
  public:
    int pad;
};
class CStageCondition_633f0;
class ParamValue_633f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_633f0 : public ParamValue_633f0 {
  public:
    int pad;
};
class CStageCondition_63440;
class ParamValue_63440 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63440 : public ParamValue_63440 {
  public:
    int pad;
};
class CStageCondition_63490;
class ParamValue_63490 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63490 : public ParamValue_63490 {
  public:
    int pad;
};
class CStageCondition_634e0;
class ParamValue_634e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_634e0 : public ParamValue_634e0 {
  public:
    int pad;
};
class CStageCondition_63530;
class ParamValue_63530 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63530 : public ParamValue_63530 {
  public:
    int pad;
};
class CStageCondition_63580;
class ParamValue_63580 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63580 : public ParamValue_63580 {
  public:
    int pad;
};
class CStageCondition_635d0;
class ParamValue_635d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_635d0 : public ParamValue_635d0 {
  public:
    int pad;
};
class CStageCondition_63620;
class ParamValue_63620 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63620 : public ParamValue_63620 {
  public:
    int pad;
};
class CStageCondition_63670;
class ParamValue_63670 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63670 : public ParamValue_63670 {
  public:
    int pad;
};
class CStageCondition_636c0;
class ParamValue_636c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_636c0 : public ParamValue_636c0 {
  public:
    int pad;
};
class CStageCondition_63710;
class ParamValue_63710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63710 : public ParamValue_63710 {
  public:
    int pad;
};
class CStageCondition_63760;
class ParamValue_63760 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63760 : public ParamValue_63760 {
  public:
    int pad;
};
class CStageCondition_637b0;
class ParamValue_637b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_637b0 : public ParamValue_637b0 {
  public:
    int pad;
};
class CStageCondition_63800;
class ParamValue_63800 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63800 : public ParamValue_63800 {
  public:
    int pad;
};
class CStageCondition_63850;
class ParamValue_63850 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63850 : public ParamValue_63850 {
  public:
    int pad;
};
class CStageCondition_638a0;
class ParamValue_638a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_638a0 : public ParamValue_638a0 {
  public:
    int pad;
};
class CStageCondition_638f0;
class ParamValue_638f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_638f0 : public ParamValue_638f0 {
  public:
    int pad;
};
class CStageCondition_63940;
class ParamValue_63940 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63940 : public ParamValue_63940 {
  public:
    int pad;
};
class CStageCondition_63990;
class ParamValue_63990 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63990 : public ParamValue_63990 {
  public:
    int pad;
};
class CStageCondition_639e0;
class ParamValue_639e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_639e0 : public ParamValue_639e0 {
  public:
    int pad;
};
class CStageCondition_63a30;
class ParamValue_63a30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63a30 : public ParamValue_63a30 {
  public:
    int pad;
};
class CStageCondition_63a80;
class ParamValue_63a80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63a80 : public ParamValue_63a80 {
  public:
    int pad;
};
class CStageCondition_63ad0;
class ParamValue_63ad0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63ad0 : public ParamValue_63ad0 {
  public:
    int pad;
};
struct CAxisArcCondition_63b10;
class CStageCondition_63b20 {};
class ParamValue_63b20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_63b20 : public ParamValue_63b20 {
  public:
    virtual void f();
};
class CStageCondition_63bb0;
class ParamValue_63bb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63bb0 : public ParamValue_63bb0 {
  public:
    int pad;
};
class CStageCondition_63c00;
class ParamValue_63c00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63c00 : public ParamValue_63c00 {
  public:
    int pad;
};
class CStageCondition_63c50;
class ParamValue_63c50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63c50 : public ParamValue_63c50 {
  public:
    int pad;
};
class CStageCondition_63ca0;
class ParamValue_63ca0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63ca0 : public ParamValue_63ca0 {
  public:
    int pad;
};
class CStageCondition_63cf0;
class ParamValue_63cf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_63cf0 : public ParamValue_63cf0 {
  public:
    int pad;
};
} // namespace fn_fa3ff49b
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fa3ff49b {
class CSmartPropThrowTrack_642e0 {
public:
    void FUN_00061e60();
    void FUN_00061e70();
    void FUN_00061e80();
    void FUN_00061ea0();
    void FUN_00061ec0();
    void FUN_00061ee0();
    void FUN_00061ef0();
    void FUN_00061f00();
    void FUN_00061f10();
    void FUN_00061f20();
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_fa3ff49b
namespace fight {
template <class T>
class ParamBool_642e0 : public ParamBoolBase {
public:
    ParamBool_642e0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa3ff49b {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_fa3ff49b
namespace fight {
template <class T>
class ParamFloatConstRange_642e0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_642e0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_642e0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_642e0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_642e0 : public ParamVectorBase {
public:
    ParamVector_642e0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa3ff49b {
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class CSmartPropAttachTrack_65190 {
public:
    void FUN_00061cb0();
    void FUN_00061cc0();
    void FUN_00061cd0();
    void FUN_00012670();
    void FUN_00012680();
    void FUN_00061ce0();
    void FUN_00061cf0();
    void FUN_000622d0();
    void FUN_00061d20();
    void FUN_00061d10();
    void FUN_00061d30();
    void FUN_00012720();
};
} // namespace fn_fa3ff49b
namespace fight {
template <class T>
class ParamBool_65190 : public ParamBoolBase {
public:
    ParamBool_65190(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_65190 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_65190(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_65190 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_65190(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa3ff49b {
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_fa3ff49b
namespace fight {
template <class T>
class ParamName_65190 : public ParamNameBase {
public:
    ParamName_65190(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa3ff49b {
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_fa3ff49b
namespace fight {
template <class T>
class ParamNameConstList_65190 : public ParamNameConstListBase {
public:
    ParamNameConstList_65190(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_65190 : public ParamVectorBase {
public:
    ParamVector_65190(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa3ff49b {
class CSmartPropUpdateAttachmentTrack_65430 {
public:
    void FUN_00061d50();
    void FUN_00061d60();
    void FUN_00061d70();
    void FUN_00012740();
    void FUN_00012750();
    void FUN_00061d80();
    void FUN_00061d90();
    void FUN_00062480();
    void FUN_00061db0();
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
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CSmartPropSpawnTrack_65630 {
public:
    void FUN_00061dc0();
    void FUN_000626c0();
    void FUN_000127d0();
    void FUN_00061e20();
    void FUN_000127e0();
    void FUN_000127f0();
    void FUN_00061dd0();
    void FUN_00061de0();
    void FUN_00062680();
    void FUN_00061e10();
};
} // namespace fn_fa3ff49b
namespace fight {
template <class T>
class ParamBool_65630 : public ParamBoolBase {
public:
    ParamBool_65630(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_65630 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_65630(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_65630 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_65630(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_65630 : public ParamNameBase {
public:
    ParamName_65630(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_65630 : public ParamNameConstListBase {
public:
    ParamNameConstList_65630(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamString_65630 : public ParamStringBase {
public:
    ParamString_65630(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_65630 : public ParamVectorBase {
public:
    ParamVector_65630(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa3ff49b {
struct Obj_65870 {
    char Check_0022d2b0(int, unsigned int);
};
struct Obj_65a90 {
    char p[0x1a0];
    unsigned char value;
};
class Clock_65ac0 {
  public:
    float Get_00086080();
};
class Obj_65ac0 {
  public:
    char pad0[4];
    Clock_65ac0* mClock;
    char pad8[0x35c];
    float mDeadline;
    char pad2[4];
    unsigned char mActive;
    void Target();
};
struct Manager {
  public:
    char _m_pad_0[0x2c];
    union { void* item; void* ptr; };
};
extern Manager* hulk_at_004dd700;
class Active {
  public:
    float check_00086080();
    float compute_00086080();
};
class Obj {
  public:
    union { void* item; void* ptr; };
    Active* active;
    char _m_pad_8[0x8];
    unsigned __int64 val;
    char _m_pad_18[0x20];
    float x;
    float y;
    float z;
    char _m_pad_44[0x74];
    V angles;
    char _m_pad_c4[0x284];
    int a;
    int b;
    char _m_pad_350[0x4];
    int c;
    char _m_pad_358[0x4];
    int d;
    char _m_pad_360[0x4];
    union { int e; float result; };
    float offset;
    char flag;
    char _m_pad_36d[0x19d7];
    float value;
    unsigned char Set(Vec const* v);
    V Get();
    void Run();
    void update();
};
struct Entity {
    char pad[0x1d40];
    char active;
    void Update_000403f0();
};
struct EntList_65b80 {
    char pad[0xc];
    int count;
    Entity* Get_00024190(int i);
};
struct Game_65b80 {
    char pad[0x20];
    EntList_65b80* list;
    char pad2[0x8];
    int val;
};
extern Game_65b80* g_game_65b80;
struct Clock_65b80 {
    float Now_00086080();
};
struct Obj_65b80 {
    int mType;
    Clock_65b80* mClock;
    char pad[0x354];
    float mNext;
    float mInterval;
    void Tick(int a);
};
struct Manager_65c10 {
    char pad[0x0c];
    int count;
    void* GetItem_00024190(int);
};
struct Root_65c10 {
    char pad[0x20];
    Manager_65c10* manager;
};
extern Root_65c10* gRoot_65c10;
class Finder_65c50 {
  public:
    int Find_00024280(int, int);
};
class Manager_65c50 {
  public:
    char pad[0x20];
    Finder_65c50* finder;
};
extern Manager_65c50* gManager_65c50;
class Owner_65c50 {
  public:
    char pad0[0x170];
    struct Entry {
        int a;
        int b;
    } entries[40];
    int count;
};
struct Pair_65cb0 {
    int a, b;
};
class Obj_65cb0 {
    char pad[0x170];
    volatile Pair_65cb0 entries[40];
    int count;

  public:
    void Add(const volatile Pair_65cb0* p);
};
struct Key_65d10 {
    int lo;
    int hi;
};
class KeySet_65d10 {
public:
    char pad0[0x170];
    Key_65d10 keys[40];       // 0x170
    int count;          // 0x2b0
    void FUN_00065d10(const Key_65d10* key);
};
struct Pair { int first; int second; };
struct List {
    char reserved[0x10];
    Pair entries[40];
    int count;
    void FUN_00065dd0(const Pair* item);
};
struct Key_65e20 {
    int lo;
    int hi;
};
class KeySet_65e20 {
public:
    char pad0[0x10];
    Key_65e20 keys[40];       // 0x10
    int count;          // 0x150
    void FUN_00065e20(const Key_65e20* key);
};
struct Pair_65ee0 { int a; int b; };
struct PairList {
    char pad0[0x390];
    int count;
    int pad394;
    Pair_65ee0 entries[64];
    void FUN_00065ee0(const Pair_65ee0* key);
};
typedef unsigned int U_65fb0;
struct B_65fb0 {
    U_65fb0 FUN_00230800(U_65fb0);
};
struct A_65fb0 {
    U_65fb0 x;
    B_65fb0* y;
    A_65fb0* f();
};
typedef unsigned int U_66020;
struct B_66020 {
    U_66020 FUN_00230800(U_66020);
};
struct A_66020 {
    U_66020 x;
    B_66020* y;
    A_66020* f();
};
class Obj_66060 {
  public:
    Obj_66060* Get();
};
class Obj_660a0 {
  public:
    Obj_660a0* Get();
};
struct Provider {
    char pad[0x2c];
    void* item;
};
extern Provider* gProvider;
extern Manager* gMgr;
struct CalcObj {
    float Calc_00086080();
};
class Foo {
  public:
    void* p;
    CalcObj* q;
    char check(Obj* o);
};
} // namespace fn_fa3ff49b
struct World {
    char pad[0x2c];
    int value;
};
namespace fn_fa3ff49b {
extern "C" float __fastcall Run_00086080(int);
struct Target_66860 {
    Target_66860* Run(int);
};
struct Target_66870 {
    Target_66870* Run(int);
};
struct Item {
  public:
    float x;
    char _m_pad_4[0xc];
    float value;
};
struct Other {
    char pad[16];
    float x;
};
extern "C" int thunk_FUN_00267090(int);
struct Value { char pad[16]; unsigned int low; unsigned int high; };
class Obj_66a10 {
  public:
    char pad[0x390];
    int count;
    char pad2[4];
    struct Pair {
        int a, b;
    } entries[150];
    void Base_00066530();
    void Add(const int*);
};
typedef unsigned int u32_66a50;
struct Obj_66a50 {
    u32_66a50 a;
};
extern u32_66a50 __fastcall FUN_00230ea0(Obj_66a50*);
void FUN_00066900();
void FUN_000668c0();
extern "C" void *FUN_0008d6d0(unsigned int size);
struct Key_66a90 {
    int w[4];
};
struct Node {
    char pad0[0x10];
    Key_66a90 key;
};
struct Result_66a90 {
    Node *node;
    void *owner;
};
struct Owner_66a90 {
    void FUN_00230c30(Node *node, void (*notify)(), void *found);
    void FUN_00066a90(Result_66a90 *out, const Key_66a90 *key);
    void *FUN_00230be0(void (*match)(), const Key_66a90 *key);
};
typedef unsigned int u32_66b20;
struct Obj_66b20 {
    u32_66b20 a;
};
extern u32_66b20 __fastcall FUN_00230ea0(Obj_66b20*);
extern "C" void __cdecl FUN_00066980();
typedef unsigned int u32_670a0;
struct Inner_670a0 {
    hulk_intptr Find_00230ba0(const void*, void*);
};
struct S_670a0 {
    char pad[0x2f4];
};
class H {
  public:
    void* lookup_00230ba0(hulk_uintptr, unsigned int);
};
struct Rec_67110 { char pad[0x18]; float v18; };
struct Inner_67110 { float FUN_00086080(); };
struct Sub_67110 { Rec_67110 *FUN_00230ba0(void (*fn)(), int arg); };
class Target_67110 {
public:
    char pad0[4];
    Inner_67110 *inner;
    char pad1[0x2f4 - 8];
    Sub_67110 sub;
    char pad2[0x34c - 0x2f4 - sizeof(Sub_67110)];
    float f34c;
    char pad3[0x378 - 0x350];
    float f378;
    hulk_freg FUN_00067110(int key);
};
struct Slot_675b0 {
    char data[0x1c];
};
class Vehicle_675b0 {
public:
    char pad0[0x150];
    int f150;
    char pad154[0x15c];
    int f2b0;
    int f2b4;
    float f2b8;
    float f2bc;
    int f2c0;
    int f2c4;
    int f2c8;
    int f2cc;
    int f2d0;
    int f2d4;
    Slot_675b0 s2d8;
    Slot_675b0 s2f4;
    Slot_675b0 s310;
    int f32c;
    int f330;
    int f334;
    int f338;
    int f33c;
    int f340;
    int f344;
    int f348;
    int f34c;
    float f350;
    int f354;
    float f358;
    int f35c;
    float f360;
    int f364;
    float f368;
    char f36c;
    char pad36d[3];
    float f370;
    float f374;
    float f378;
    int f37c;
    int f380;
    int f384;
    int f388;
    int f38c;
    int f390;

    Vehicle_675b0 *FUN_000675b0();
};
extern "C" void __cdecl FUN_00066930();
struct Helper_676f0 {
    void Init_00230f50(void (*)(), void*);
};
struct Obj_676f0 {
    char pad[0x2d8];
    void Run();
};
class Base_67870 {
  public:
    float Compute_00086080();
};
class Obj_67870 {
  public:
    char p[4];
    Base_67870* base;
    char q[0x34c];
    float value;
    void Tick(hulk_intptr);
    void Do_00067490(float*, int);
};
class B_67870 {
  public:
    char p[0x10];
    void Run_00059a50(float*);
};
class A_67870 {
  public:
    char p[0x10];
    B_67870* y;
};
class Manager_67870 {
  public:
    char p[0x124];
    A_67870* a;
};
class Root_67870 {
  public:
    char p[0x20];
    Manager_67870* m;
};
extern Root_67870* gRoot_67870;
} // namespace fn_fa3ff49b
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif
namespace fn_fa3ff49b {
extern "C" void cleanup();
struct Obj_678d0 {
    void init_000675b0();
};
struct Vec_67930 {
    float x, y, z;
};
struct C_679c0 {
    char pad[0x18];
};
extern void __fastcall FUN_0027af50(C_679c0*);
struct Item_67a20 {
    void tick_0027af50();
};
struct Name_67b00 {
    char data[8];
    void FUN_0027af70(int v);
};
struct Record_67b00 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int pad14;
    Name_67b00 name;              // 0x18
};
class HandlePool {
public:
    unsigned int serial;    // 0x00
    int head;               // 0x04
    unsigned int ids[64];   // 0x08
    Record_67b00 records[64];     // 0x108
    unsigned int FUN_00067b00(int arg);
};
struct Name_67ba0 {
    char pad[8];
};
struct Entry_67ba0 {
    int a, b, c, d, e;
    char pad14[4];
    Name_67ba0 name;
};
class HandleTable {
public:
    unsigned counter;
    int head;
    unsigned slot[64];
    Entry_67ba0 entry[64];
    unsigned Alloc();
};
struct Data_67c30 {
    unsigned int v[5];
};
class Obj_67c30 {
  public:
    unsigned char bytes[0x108];
    bool Put(unsigned int key, const Data_67c30* src);
};
struct Rec_67ce0 {
    int tag;
    float x, y, z;
    float radius;
    int pad14;
    int idLo;
    int idHi;
};
struct Sphere_67ce0 {
    float x, y, z;
    float radius;
};
struct V3_67ce0 { float x, y, z; };
struct ObjId { int lo; int hi; };
class Tracker_67ce0 {
public:
    bool run(const ObjId* id, int skipTag, const Sphere_67ce0* s, V3_67ce0* outPos, void** outObj);
    char p0[8];
    void* objs[64];
    Rec_67ce0 recs[64];
};
struct Inner {
    int x[6];
    Inner();
};
struct Obj_67e60 {
    int v[5];
    int pad;
    Inner inner;
    Obj_67e60* Copy(const Obj_67e60*);
};
struct Key_67ea0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
};
struct Entry_67ea0 {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    char pad14[4];
    Key_67ea0 key;
};
class Table_67ea0 {
public:
    int one;
    int zero;
    char pad08[0x100];
    Entry_67ea0 entries[0x40];
    Table_67ea0();
    void FUN_00067a40();
};
struct Entry_67f60 {
    int a;
    int b;
    int c;
};
class Obj_67f60 {
  public:
    char pad[0x24];
    int m24;
    int m28;
    int m2c;
    bool Set(Entry_67f60* e);
};
class Base_67f90 {
  public:
    virtual void BaseFn();
    char pad[0x3c];
};
class Obj_67f90 : public Base_67f90 {
  public:
    virtual ~Obj_67f90() throw();
    bool Set(int v);
    int m40;
};
extern const float k_68140 = 0.0174532924f;
extern const float kRad = 0.01745329252f;
class Obj_68250 {
  public:
    char pad[12];
    int mValue;
    unsigned char Set(int v);
};
class C_68260 {
    char pad[0xc];

  public:
    char Set(int v);
};
class Target_68270 {
  public:
    char pad[0x50];
    int field;
    bool Set(int value);
};
class Obj_682e0 {
  public:
    bool Ctor(int arg);
    char pad[0xc];
    int mValue;
};
class Obj_682f0 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};
class Obj_68300 {
  public:
    char pad[0x14];
    int mX;
    bool SetX(int v);
};
class O_68310 {
  public:
    char SetTimeBegin_00068310(int a);
    char pad[0xc];
    int m;
};
class Base_68330 {
  public:
    char pad[0x14];
};
class Target_68330 : public Base_68330 {
  public:
    int mField;
    char SetDistance_00068330(int);
};
class Obj_683b0 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int v);
};
struct X_683c0 {
    char pad[16];
    unsigned int m10;
    char Set(int v);
};
class Obj_683d0 {
  public:
    char Set(int value);
    char mPad[0x1c];
    int mValue;
};
struct Object { char pad[0x20]; unsigned int flags; bool FUN_00068410(bool enabled); };
class Obj_68470 {
  public:
    char pad[0x38];
    char m38;
    char Set(char v);
};
class Obj_68480 {
  public:
    char pad[0x24];
    float mValue;
    char Set(float angle);
};
class Obj_684a0 {
  public:
    char pad[0x28];
    float mAngle;
    char Set(float a);
};
class Obj_684c0 {
  public:
    char pad[0x2c];
    int mValue;
    char Set(int v);
};
struct Obj_684d0 {
    char pad[0x30];
    int value;
    char Set(int v);
};
class Obj_684e0 {
  public:
    char pad[0x34];
    int mVal;
    bool Set(int v);
};
class X_684f0 {
  public:
    char SetTimeBegin_000684f0(int n);
    int pad1;
    int pad2;
    int pad3;
    int m;
};
class Obj_68500 {
  public:
    char pad[0x10];
    int m10;
    char SetDamage_00068500(int x);
};
class Obj_68510 {
  public:
    char SetDamageMax_00068510(int v);
    char pad[0x13];
    int m14;
};
class Target_68520 {
  public:
    char pad[12];
    int value;
    char Set(int x);
};
class O_68530 {
  public:
    char pad[16];
    int m;
    char Set(int x);
};
class Obj_68540 {
  public:
    char pad[0x14];
    void* value;
    bool Set(void* p);
};
class Obj_68550 {
  public:
    char pad[0xc];
    int value;
    char SetTimeBegin_00068550(int x);
};
class Obj_68560 {
  public:
    char pad[0x10];
    int mValue;
    char SetTimeEnd_00068560(int value);
};
struct X_68570 {
    char pad[0x14];
    int m14;
    bool SetComboTimer_00068570(int x);
};
class Obj_68580 {
  public:
    char pad[12];
    int mVal;
    bool Set(int v);
};
class C_68590 {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};
class C_685a0 {
  public:
    char pad[0x14];
    int m14;
    bool Set(int v);
};
class Obj_685f0 {
  public:
    char pad[0xc];
    int mVal;
    char SetTimeBegin_000685f0(int v);
};
class Obj_68600 {
  public:
    char pad[0x10];
    int m10;
    bool SetTimeEnd_00068600(int x);
};
class Obj_68620 {
  public:
    char SetFrequency_00068620(int a);
    char pad[0x18];
    int m18;
};
struct Src_68650 {
    int a;
    int b;
    int c;
};
class Obj_68650 {
  public:
    char Pad[0x14];
    int x;
    int y;
    int z;
    char Set(Src_68650* p);
};
class Obj_68770 {
  public:
    char pad[0xc];
    int value;
    bool SetTimeBegin_00068770(int x);
};
class X_68780 {
  public:
    char SetTimeEnd_00068780(int value);
    char mPad[0x10];
    int mValue;
};
class Obj_68790 {
  public:
    char pad[0x14];
    int value;
    char SetHint_00068790(int v);
};
struct Vec_687c0 {
    int x;
    int y;
    int z;
};
class Obj_687c0 {
  public:
    char pad[0x14];
    Vec_687c0 v;
    char Set(Vec_687c0* p);
};
extern const float kRadianToDegree = 0.017453292f;
class O_688f0 {
  public:
    char Set(int v);
    int m4;
    int m8;
    int pad;
    int m1c;
};
class O_68900 {
  public:
    char pad[0x10];
    int m10;
    char m14;
    bool Set(int v);
};
class Obj_68910 {
  public:
    char pad[0x14];
    int m14;
    bool Set(int x);
};
class Obj_68920 {
  public:
    char Fn(int a);
    char pad[0x18];
    int m18;
};
class Obj_68930 {
  public:
    char pad[12];
    int m;
    unsigned char SetTimeBegin_00068930(int v);
};
class Obj_68940 {
  public:
    char pad[0x10];
    int m;
    bool SetTimeEnd_00068940(int v);
};
class T_68950 {
  public:
    char pad[0x14];
    int m14;
    bool SetExtensionTime_00068950(int value);
};
class Obj_68960 {
  public:
    char pad[12];
    int value;
    bool Set(int x);
};
class Obj_68970 {
  public:
    char pad[0x10];
    int m;
    bool Set(int x);
};
class Obj_68980 {
  public:
    char pad[0x14];
    int value;
    bool Set(int arg);
};
struct Vec3_689f0 {
    int x, y, z;
};
class Obj_689f0 {
  public:
    char pad[0x20];
    int a, b, c;
    bool Set(const Vec3_689f0* p);
};
struct In {
    int a;
    int b;
    int c;
};
class Obj_68a10 {
  public:
    char pad[0x2c];
    int m1;
    int m2;
    int m3;
    bool Set(In* p);
};
struct S_68a30 {
    char pad[0x38];
    float value;
};
class Obj_68b40 {
  public:
    char pad[0xc];
    int mVal;
    bool SetTimeBegin_00068b40(int v);
};
class Obj_68b50 {
  public:
    char pad[0x10];
    int value;
    bool SetTimeEnd_00068b50(int x);
};
struct Sub_68b60 {};
struct Obj_68b60 {
    char pad[0x18];
    Sub_68b60* GetHint_00068b60();
};
class C_68b90 {
  public:
    char pad[12];
    int mVal;
    bool SetTimeBegin_00068b90(int x);
};
class Obj_68ba0 {
  public:
    char pad[0x10];
    int m10;
    bool SetTimeEnd_00068ba0(int v);
};
class Obj_68bb0 {
  public:
    char pad[0x14];
    int m;
    bool SetHeight_00068bb0(int v);
};

} // namespace fn_fa3ff49b

// 0x00061e30 FUN_00061e30 (12 B): matches/0x00061e30.cpp
// sym: ?FUN_00061e30@O_61e30@owners@@QAEDH@Z
char owners::O_61e30::FUN_00061e30(int x) {
    m = x;
    return 1;
}


// 0x00061e40 FUN_00061e40 (12 B): matches/0x00061e40.cpp
// sym: ?FUN_00061e40@O_61e40@owners@@QAE_NH@Z
bool owners::O_61e40::FUN_00061e40(int v) {
    m = v;
    return true;
}


// 0x00061e50 FUN_00061e50 (12 B): matches/0x00061e50.cpp
// sym: ?FUN_00061e50@Obj_61e50@owners@@QAEDH@Z
char owners::Obj_61e50::FUN_00061e50(int v) {
    mValue = v;
    return 1;
}


// 0x00061e60 FUN_00061e60 (12 B): matches/0x00061e60.cpp
// sym: ?FUN_00061e60@Obj_61e60@owners@@QAEDH@Z
char owners::Obj_61e60::FUN_00061e60(int value) {
    mField = value;
    return 1;
}


// 0x00061e70 FUN_00061e70 (12 B): matches/0x00061e70.cpp
// sym: ?FUN_00061e70@C_61e70@owners@@QAE_NH@Z
bool owners::C_61e70::FUN_00061e70(int x) {
    m = x;
    return true;
}


// 0x00061e80 FUN_00061e80 (26 B): matches/0x00061e80.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4T_61e80@fn_00061e80@@QAE_NPBUS_61e80@1@@Z
namespace fn_00061e80 {
struct S_61e80 {
    int a, b, c;
};
struct T_61e80 {
    char pad[16];
    S_61e80 s;
    bool operator=(const S_61e80* p_61e80);
};
bool T_61e80::operator=(const S_61e80* p_61e80) {
    s.a = p_61e80->a;
    s.b = p_61e80->b;
    s.c = p_61e80->c;
    return true;
}
} // namespace fn_00061e80

namespace fn_fa3ff49b {

// 0x00061ea0 FUN_00061ea0 (26 B): matches/0x00061ea0.cpp
// sym: ?Set@Obj_61ea0@fn_fa3ff49b@@QAE_NPBUSrc_61ea0@2@@Z
bool Obj_61ea0::Set(const Src_61ea0* s) {
    m1 = s->a;
    m2 = s->b;
    m3 = s->c;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00061ec0 FUN_00061ec0 (18 B): matches/0x00061ec0.cpp
// sym: ?FUN_00061ec0@Obj_61ec0@owners@@QAEDM@Z
char owners::Obj_61ec0::FUN_00061ec0(float x) {
    angle = x * k;
    return 1;
}


// 0x00061ee0 FUN_00061ee0 (12 B): matches/0x00061ee0.cpp
// sym: ?FUN_00061ee0@Obj_61ee0@owners@@QAE_NH@Z
bool owners::Obj_61ee0::FUN_00061ee0(int value) {
    *(int*)((char*)this + 0x2c) = value;
    return true;
}


// 0x00061ef0 FUN_00061ef0 (12 B): matches/0x00061ef0.cpp
// sym: ?FUN_00061ef0@O_61ef0@owners@@QAEDH@Z
char owners::O_61ef0::FUN_00061ef0(int x) {
    value = x;
    return 1;
}


// 0x00061f00 FUN_00061f00 (12 B): matches/0x00061f00.cpp
// sym: ?FUN_00061f00@Obj_61f00@owners@@QAEDH@Z
char owners::Obj_61f00::FUN_00061f00(int x) {
    m34 = x;
    return 1;
}


// 0x00061f10 FUN_00061f10 (12 B): matches/0x00061f10.cpp
// sym: ?FUN_00061f10@Obj_61f10@owners@@QAE_NPAX@Z
bool owners::Obj_61f10::FUN_00061f10(void* v) {
    m38 = v;
    return true;
}


// 0x00061f20 FUN_00061f20 (12 B): matches/0x00061f20.cpp
// sym: ?FUN_00061f20@O_61f20@owners@@QAEEE@Z
unsigned char owners::O_61f20::FUN_00061f20(unsigned char c) {
    m3c = c;
    return 1;
}


// 0x00061f30 FUN_00061f30 (12 B): matches/0x00061f30.cpp
// sym: ?FUN_00061f30@O_61f30@owners@@QAEDH@Z
char owners::O_61f30::FUN_00061f30(int x) {
    m = x;
    return 1;
}


// 0x00061f40 FUN_00061f40 (12 B): matches/0x00061f40.cpp
// sym: ?FUN_00061f40@Obj_61f40@owners@@QAEDH@Z
char owners::Obj_61f40::FUN_00061f40(int v) {
    value = v;
    return 1;
}


// 0x00061f50 FUN_00061f50 (12 B): matches/0x00061f50.cpp
// sym: ?FUN_00061f50@Obj_61f50@owners@@QAE_NH@Z
bool owners::Obj_61f50::FUN_00061f50(int x) {
    mVal = x;
    return true;
}


// 0x00061f60 FUN_00061f60 (12 B): matches/0x00061f60.cpp
// sym: ?FUN_00061f60@A_61f60@owners@@QAE_NH@Z
bool owners::A_61f60::FUN_00061f60(int v) {
    m = v;
    return true;
}

namespace fn_fa3ff49b {

// 0x00061f70 FUN_00061f70 (12 B): matches/0x00061f70.cpp
// sym: ?SetTimeBegin_00061f70@X_61f70@fn_fa3ff49b@@QAEDH@Z
char X_61f70::SetTimeBegin_00061f70(int v) {
    m10 = v;
    return 1;
}


// 0x00061f80 FUN_00061f80 (12 B): matches/0x00061f80.cpp
// sym: ?SetAttachmentIndex_00061f80@A_61f80@fn_fa3ff49b@@QAE_NH@Z
bool A_61f80::SetAttachmentIndex_00061f80(int x) {
    value = x;
    return true;
}


// 0x00061f90 FUN_00061f90 (12 B): matches/0x00061f90.cpp
// sym: ?SetEvent_00061f90@Obj_61f90@fn_fa3ff49b@@QAEDH@Z
char Obj_61f90::SetEvent_00061f90(int x) {
    m = x;
    return 1;
}


// 0x00061fa0 FUN_00061fa0 (12 B): matches/0x00061fa0.cpp
// sym: ?Set@O_61fa0@fn_fa3ff49b@@QAEDH@Z
char O_61fa0::Set(int x) {
    m.v = x;
    return 1;
}

} // namespace fn_fa3ff49b

// 0x00061fb0 FUN_00061fb0 (12 B): matches/0x00061fb0.cpp
// sym: ?FUN_00061fb0@Obj_61fb0@owners@@QAE_NH@Z
bool owners::Obj_61fb0::FUN_00061fb0(int v) {
    mVal = v;
    return true;
}


// 0x00061fc0 FUN_00061fc0 (12 B): matches/0x00061fc0.cpp
// sym: ?FUN_00061fc0@Obj_61fc0@owners@@QAE_NH@Z
bool owners::Obj_61fc0::FUN_00061fc0(int x) {
    mValue = x;
    return true;
}


// 0x00061fd0 FUN_00061fd0 (12 B): matches/0x00061fd0.cpp
// sym: ?FUN_00061fd0@Obj_61fd0@owners@@QAEDH@Z
char owners::Obj_61fd0::FUN_00061fd0(int value) {
    field = value;
    return 1;
}

namespace fn_fa3ff49b {

// 0x00061fe0 FUN_00061fe0 (19 B): matches/0x00061fe0.cpp
// sym: ?FUN_00061fe0@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00061fe0() {
    FUN_00234810(((char*)&DAT_004dc618), ((char*)&DAT_004dc61c));
}

} // namespace fn_fa3ff49b

// 0x00062000 CWeaponCollisionTrack::vfunc_0 (16 B): matches/0x00062000.cpp
// sym: ?vfunc_0@CWeaponCollisionTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CWeaponCollisionTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc618;
    return p[index];
}


// 0x00062120 CWeaponCollisionTrack::vfunc_11 (13 B): matches/0x00062120.cpp
// sym: ?vfunc_11@CWeaponCollisionTrack@@UAEXPAX@Z
// Same code shape as 0x0005b140 (propagated; names are from that function)
void CWeaponCollisionTrack::vfunc_11(void* __p0) { int * out = (int *)__p0;

    *out = 0xffffff00;
}


// 0x00062130 CWeaponCollisionTrack::vfunc_6 (4 B): matches/0x00062130.cpp
// sym: ?vfunc_6@CWeaponCollisionTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CWeaponCollisionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00062140 CWeaponCollisionTrack::vfunc_7 (7 B): matches/0x00062140.cpp
// sym: ?vfunc_7@CWeaponCollisionTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CWeaponCollisionTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x00062150 FUN_00062150 (41 B): matches/0x00062150.cpp [wrapped: conflict: CWeaponCollisionTrack]
// sym: ?Kill@CWeaponCollisionTrack@fn_00062150@@UAEXXZ
namespace fn_00062150 {
extern "C" char DAT_003faf2c[];
struct Small_62150 {
    ~Small_62150();
    char p[12];
};
struct Big_62150 {
    ~Big_62150();
    char p[16];
};
struct Other_62150 {
    ~Other_62150();
    char p[4];
};
struct Base {
    virtual ~Base();
};
struct CWeaponCollisionTrack : Base {
    char pad[0x28];
    Small_62150 c;
    Big_62150 b;
    Other_62150 a;
    virtual void Kill();
};
void CWeaponCollisionTrack::Kill() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003faf2c);
    a.~Other_62150();
    b.~Big_62150();
    c.~Small_62150();
    this->Base::~Base();
}
} // namespace fn_00062150


// 0x00062180 FUN_00062180 (29 B): matches/0x00062180.cpp
// sym: ?FUN_00062180@Obj_62180@owners@@QAEDPBD@Z
char owners::Obj_62180::FUN_00062180(const char* v) {
    FUN_00267760((char*)this + 0x50, 0x40, "%s", v);
    return 1;
}


// 0x000621a0 CWeaponCollisionTrack::vfunc_10 (80 B): matches/0x000621a0.cpp
// sym: ?vfunc_10@CWeaponCollisionTrack@@UAEHHHH@Z
hulk_intptr CWeaponCollisionTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_621a0 a = (u32_621a0)__p0; u32_621a0 b = (u32_621a0)__p1; u32_621a0 c = (u32_621a0)__p2;

    int x = ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(c), 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (x) {
        void* p = alloc_0008d690(0x80);
        if (p)
            return (int)(((CWeaponCollisionAction_621a0*)p)->construct_0001b080(a, this, x));
    }
    return (int)(0);
}

namespace fn_fa3ff49b {

// 0x000621f0 FUN_000621f0 (19 B): matches/0x000621f0.cpp
// sym: ?FUN_000621f0@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000621f0() {
    FUN_00234810(((char*)&DAT_004dc620), ((char*)&DAT_004dc624));
}

} // namespace fn_fa3ff49b

// 0x00062210 CSmartPropAttachTrack::vfunc_0 (16 B): matches/0x00062210.cpp
// sym: ?vfunc_0@CSmartPropAttachTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropAttachTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc620;
    return p[index];
}


// 0x00062220 FUN_00062220 (41 B): matches/0x00062220.cpp [wrapped: conflict: CSmartPropAttachTrack]
// sym: ?Construct@CSmartPropAttachTrack@fn_00062220@@QAEXXZ
namespace fn_00062220 {
extern "C" char DAT_003faf60[];
struct Helper_62220 {
    void Run_0027af50();
};
struct CSmartPropAttachTrack {
    void* vf;
    char pad[0x58 - 4];
    void Construct();
};
struct Finalizer {
    void Run_00068c70();
};
void CSmartPropAttachTrack::Construct() {
    vf = (void*)((hulk_intptr)DAT_003faf60);
    ((Helper_62220*)((char*)this + 0x58))->Run_0027af50();
    ((Helper_62220*)((char*)this + 0x20))->Run_0027af50();
    ((Helper_62220*)((char*)this + 0x18))->Run_0027af50();
    ((Finalizer*)this)->Run_00068c70();
}
} // namespace fn_00062220


// 0x00062250 CSmartPropAttachTrack::vfunc_13 (13 B): matches/0x00062250.cpp
// sym: ?vfunc_13@CSmartPropAttachTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CSmartPropAttachTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00062260 CSmartPropAttachTrack::vfunc_6 (4 B): matches/0x00062260.cpp
// sym: ?vfunc_6@CSmartPropAttachTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSmartPropAttachTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00062270 CSmartPropAttachTrack::vfunc_7 (7 B): matches/0x00062270.cpp
// sym: ?vfunc_7@CSmartPropAttachTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CSmartPropAttachTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fa3ff49b {

// 0x00062280 FUN_00062280 (72 B): equivalent/0x00062280.cpp
// sym: ?FUN_00062280@Angles@fn_fa3ff49b@@QAEXPAM@Z @430e596a4352 @wb4acd61ad30f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00062280 @ 0x00062280
void Angles::FUN_00062280(float *out) {
    out[0] = x * (*(float*)&DAT_003f3ef4);
    out[1] = y * (*(float*)&DAT_003f3ef4);
    out[2] = z * (*(float*)&DAT_003f3ef4);
}


// 0x000622d0 FUN_000622d0 (44 B): matches/0x000622d0.cpp
// sym: ?Set@Obj@fn_fa3ff49b@@QAEEPBUVec@2@@Z
unsigned char Obj::Set(Vec const* v) {
    x = v->x * 0.017453292519943295f;
    y = v->y * 0.017453292519943295f;
    z = v->z * 0.017453292519943295f;
    return 1;
}

} // namespace fn_fa3ff49b

// 0x00062300 CSmartPropAttachTrack::vfunc_12 (40 B): matches/0x00062300.cpp
// sym: ?vfunc_12@CSmartPropAttachTrack@@UAEHH@Z
hulk_intptr CSmartPropAttachTrack::vfunc_12(hulk_intptr a) {
    Helper_62300* p = FUN_0008d690(0x2c);
    if (p)
        return p->Fnf_0001ea30(this, a);
    return 0;
}

namespace fn_fa3ff49b {

// 0x00062330 FUN_00062330 (19 B): matches/0x00062330.cpp
// sym: ?FUN_00062330@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00062330() {
    FUN_00234810(((char*)&DAT_004dc628), ((char*)&DAT_004dc62c));
}

} // namespace fn_fa3ff49b

// 0x00062350 CSmartPropUpdateAttachmentTrack::vfunc_0 (16 B): matches/0x00062350.cpp
// sym: ?vfunc_0@CSmartPropUpdateAttachmentTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropUpdateAttachmentTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc628;
    return p[index];
}


// 0x00062360 FUN_00062360 (104 B): equivalent/0x00062360.cpp [wrapped: conflict: CSmartPropUpdateAttachmentTrack]
// sym: ??0CSmartPropUpdateAttachmentTrack@fn_00062360@@QAE@XZ @e0a615b5a095 @wb3f74696a066
namespace fn_00062360 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00062360 @ 0x00062360
struct Name_62360 {
    unsigned int a, b;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

class __declspec(novtable) CTrack_62360 {
public:
    virtual hulk_intptr b0_00062350(int);
    int pad04;
    int pad08;
    void FUN_00236d40();
    CTrack_62360() { FUN_00236d40(); }
};

class CSmartPropUpdateAttachmentTrack : public CTrack_62360 {
public:
    virtual bool vfunc_0_00234270(void*);
    virtual bool v1_002342b0(int);
    virtual bool v2_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool v3_00234350(int, int);
    virtual void* v4_00062e80(void*, char);
    virtual void v5_000623e0();
    virtual void vfunc_6_000623f0();
    virtual int vfunc_7_00068c80(int, int);

    int f0c, f10, f14;
    Name_62360 bone;
    Name_62360 prop;
    char enabled;
    char pad29[3];
    int f2c, f30, f34, f38, f3c, f40, f44;

    CSmartPropUpdateAttachmentTrack();
};

CSmartPropUpdateAttachmentTrack::CSmartPropUpdateAttachmentTrack() {
    f0c = 0; f10 = 0; f14 = 0;
    bone.FUN_0027af00();
    prop.FUN_0027af00();
    enabled = 1;
    f2c = 0; f30 = 0; f34 = 0; f38 = 0; f3c = 0; f40 = 0; f44 = 0;
    bone.FUN_0027b040("Wrist_R");
    prop.FUN_0027b040("Wealded_Weap_1");
}
} // namespace fn_00062360


// 0x000623d0 CSmartPropUpdateAttachmentTrack::vfunc_13 (13 B): matches/0x000623d0.cpp
// sym: ?vfunc_13@CSmartPropUpdateAttachmentTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CSmartPropUpdateAttachmentTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x000623e0 CSmartPropUpdateAttachmentTrack::vfunc_6 (4 B): matches/0x000623e0.cpp
// sym: ?vfunc_6@CSmartPropUpdateAttachmentTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSmartPropUpdateAttachmentTrack::vfunc_6() {
    return this->f_0c;
}


// 0x000623f0 CSmartPropUpdateAttachmentTrack::vfunc_7 (7 B): matches/0x000623f0.cpp
// sym: ?vfunc_7@CSmartPropUpdateAttachmentTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CSmartPropUpdateAttachmentTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fa3ff49b {

// 0x00062400 FUN_00062400 (33 B): matches/0x00062400.cpp
// sym: ?Run@CSmartPropUpdateAttachmentTrack_62400@fn_fa3ff49b@@QAEXXZ
// Same code shape as 0x001703a0 (propagated; names are from that function)
void CSmartPropUpdateAttachmentTrack_62400::Run() {
    vt = (hulk_intptr)&hulk_at_003faf9c;
    p20.Init_0027af50();
    p18.Init_0027af50();
    Final_00068c70();
}


// 0x00062430 FUN_00062430 (72 B): equivalent/0x00062430.cpp
// sym: ?FUN_00062430@Angles@fn_fa3ff49b@@QAEXPAUVector3@2@@Z @6f3d1bc442da @w5cab9d201def
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_00062430 @ 0x00062430
void Angles::FUN_00062430(Vector3 *out) {
    out->x = x * 57.2957764f;
    out->y = y * 57.2957764f;
    out->z = z * 57.2957764f;
}

} // namespace fn_fa3ff49b

// 0x00062480 FUN_00062480 (44 B): matches/0x00062480.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_00062480@@QAE_NPBUVec@2@@Z
namespace fn_00062480 {
struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x38];
    float x, y, z;

  public:
    bool Set(const Vec* v);
};
bool Obj::Set(const Vec* v) {
    x = v->x * 0.017453292f;
    y = v->y * 0.017453292f;
    z = v->z * 0.017453292f;
    return true;
}
} // namespace fn_00062480

namespace fn_fa3ff49b {

// 0x000624e0 FUN_000624e0 (19 B): matches/0x000624e0.cpp
// sym: ?FUN_000624e0@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000624e0() {
    FUN_00234810(((char*)&DAT_004dc630), ((char*)&DAT_004dc634));
}

} // namespace fn_fa3ff49b

// 0x00062500 CSmartPropSpawnTrack::vfunc_0 (16 B): matches/0x00062500.cpp
// sym: ?vfunc_0@CSmartPropSpawnTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropSpawnTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc630;
    return p[index];
}


// 0x00062510 FUN_00062510 (148 B): equivalent/0x00062510.cpp [wrapped: conflict: CSmartPropSpawnTrack]
// sym: ??0CSmartPropSpawnTrack@fn_00062510@@QAE@XZ @45f464a7f1af @w021340aa344f
namespace fn_00062510 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00062510 @ 0x00062510
struct Name_62510 {
    unsigned int a, b;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

class __declspec(novtable) CTrack_62510 {
public:
    virtual hulk_intptr b0_00062500(int);
    int pad04;
    int pad08;
    void FUN_00236d40();
    CTrack_62510() { FUN_00236d40(); }
};

class CSmartPropSpawnTrack : public CTrack_62510 {
public:
    virtual bool vfunc_0_00234270(void*);
    virtual bool v1_002342b0(int);
    virtual bool v2_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool v3_00234350(int, int);
    virtual void* v4_00062ec0(char);
    virtual void v5_000625c0();
    virtual void vfunc_6_000625d0();
    virtual int vfunc_7_00068c80(int, int);

    int f0c;
    char f10;
    char pad11[0x7f];
    int f90;
    int pad94;
    Name_62510 bone;
    Name_62510 prop;
    char enabled;
    char pada9[3];
    int fac, fb0, fb4, fb8, fbc, fc0, fc4;
    Name_62510 extra;

    CSmartPropSpawnTrack();
};

CSmartPropSpawnTrack::CSmartPropSpawnTrack() {
    f0c = 0;
    f90 = 0;
    bone.FUN_0027af00();
    prop.FUN_0027af00();
    enabled = 1;
    fac = 0; fb0 = 0; fb4 = 0; fb8 = 0; fbc = 0; fc0 = 0; fc4 = 0;
    extra.FUN_0027af00();
    bone.FUN_0027b040("Wrist_R");
    prop.FUN_0027b040("Wealded_Weap_1");
    f10 = 0;
}
} // namespace fn_00062510


// 0x000625b0 CSmartPropSpawnTrack::vfunc_13 (13 B): matches/0x000625b0.cpp
// sym: ?vfunc_13@CSmartPropSpawnTrack@@UAEXPAX@Z
// Same code shape as 0x0005dd10 (propagated; names are from that function)
void CSmartPropSpawnTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xffff0000;
}


// 0x000625c0 CSmartPropSpawnTrack::vfunc_6 (4 B): matches/0x000625c0.cpp
// sym: ?vfunc_6@CSmartPropSpawnTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSmartPropSpawnTrack::vfunc_6() {
    return this->f_0c;
}


// 0x000625d0 CSmartPropSpawnTrack::vfunc_7 (7 B): matches/0x000625d0.cpp
// sym: ?vfunc_7@CSmartPropSpawnTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CSmartPropSpawnTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x000625e0 FUN_000625e0 (50 B): matches/0x000625e0.cpp [wrapped: conflict: CSmartPropSpawnTrack]
// sym: ?Dtor@CSmartPropSpawnTrack@fn_000625e0@@QAEXXZ
namespace fn_000625e0 {
extern "C" char DAT_003fafd8[];
extern void __fastcall FUN_0027af50(void*);
extern void __fastcall FUN_00068c70(void*);
struct CSmartPropSpawnTrack {
    void* vptr;
    char p0[0x94];
    char a;
    char p1[7];
    char b;
    char p2[0x27];
    char c;
    void Dtor();
};
void CSmartPropSpawnTrack::Dtor() {
    vptr = (void*)((hulk_intptr)DAT_003fafd8);
    FUN_0027af50(&c);
    FUN_0027af50(&b);
    FUN_0027af50(&a);
    FUN_00068c70(this);
}
} // namespace fn_000625e0

namespace fn_fa3ff49b {

// 0x00062620 FUN_00062620 (81 B): matches/0x00062620.cpp
// sym: ?Get@Obj@fn_fa3ff49b@@QAE?AUV@2@XZ
V Obj::Get() {
    V result;
    result.x = angles.x * 57.295776f;
    result.y = angles.y * 57.295776f;
    result.z = angles.z * 57.295776f;
    return result;
}

} // namespace fn_fa3ff49b

// 0x00062680 FUN_00062680 (53 B): matches/0x00062680.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_00062680@@QAEDABUVec@2@@Z
namespace fn_00062680 {
struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0xb8];
    float x, y, z;

  public:
    char Set(Vec const& v);
};
char Obj::Set(Vec const& v) {
    x = v.x * 0.017453292519943295f;
    y = v.y * 0.017453292519943295f;
    z = v.z * 0.017453292519943295f;
    return 1;
}
} // namespace fn_00062680


// 0x000626c0 FUN_000626c0 (27 B): matches/0x000626c0.cpp
// sym: ?FUN_000626c0@X_626c0@owners@@QAEDPBD@Z
char owners::X_626c0::FUN_000626c0(const char* s) {
    strncpy(buf, s, 0x80);
    return 1;
}


// 0x000626e0 CSmartPropSpawnTrack::vfunc_12 (40 B): matches/0x000626e0.cpp
// sym: ?vfunc_12@CSmartPropSpawnTrack@@UAEHH@Z
// Same code shape as 0x0005dd70 (propagated; names are from that function)
hulk_intptr CSmartPropSpawnTrack::vfunc_12(hulk_intptr param) {
    Helper_626e0* p = (Helper_626e0*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001eff0(this, param);
    return 0;
}

namespace fn_fa3ff49b {

// 0x00062710 FUN_00062710 (19 B): matches/0x00062710.cpp
// sym: ?FUN_00062710@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00062710() {
    FUN_00234810(((char*)&DAT_004dc638), ((char*)&DAT_004dc63c));
}

} // namespace fn_fa3ff49b

// 0x00062730 CSmartPropSetStateTrack::vfunc_0 (16 B): matches/0x00062730.cpp
// sym: ?vfunc_0@CSmartPropSetStateTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropSetStateTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc638;
    return p[index];
}


// 0x00062740 FUN_00062740 (26 B): matches/0x00062740.cpp [wrapped: conflict: CSmartPropSetStateTrack]
// sym: ??0CSmartPropSetStateTrack@fn_00062740@@QAE@XZ
namespace fn_00062740 {
class CTrack_62740 {
  public:
    virtual void f();
    char pad[8];
    int a, b;
    CTrack_62740();
};
class CSmartPropSetStateTrack : public CTrack_62740 {
  public:
    virtual void f();
    CSmartPropSetStateTrack();
};
CSmartPropSetStateTrack::CSmartPropSetStateTrack() {
    a = 0;
    b = 0;
}
} // namespace fn_00062740


// 0x00062760 CSmartPropSetStateTrack::vfunc_13 (13 B): matches/0x00062760.cpp
// sym: ?vfunc_13@CSmartPropSetStateTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CSmartPropSetStateTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00062770 CSmartPropSetStateTrack::vfunc_6 (4 B): matches/0x00062770.cpp
// sym: ?vfunc_6@CSmartPropSetStateTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSmartPropSetStateTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00062780 CSmartPropSetStateTrack::vfunc_7 (7 B): matches/0x00062780.cpp
// sym: ?vfunc_7@CSmartPropSetStateTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CSmartPropSetStateTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_fa3ff49b {

// 0x000627d0 FUN_000627d0 (19 B): matches/0x000627d0.cpp
// sym: ?FUN_000627d0@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000627d0() {
    FUN_00234810(((char*)&DAT_004dc640), ((char*)&DAT_004dc644));
}

} // namespace fn_fa3ff49b

// 0x000627f0 CSmartPropDetachTrack::vfunc_0 (16 B): matches/0x000627f0.cpp
// sym: ?vfunc_0@CSmartPropDetachTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropDetachTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc640;
    return p[index];
}


// 0x00062800 FUN_00062800 (25 B): matches/0x00062800.cpp [wrapped: conflict: CSmartPropDetachTrack]
// sym: ??0CSmartPropDetachTrack@fn_00062800@@QAE@XZ
namespace fn_00062800 {
class CTrack_62800 {
  public:
    virtual hulk_intptr BaseFn0_000627f0(int);
    virtual bool BaseFn1_00234270(void*);
    CTrack_62800();

  private:
    int b0;
    int b1;
};

class CSmartPropDetachTrack : public CTrack_62800 {
  public:
    virtual bool TrackFn0_002342b0(int);
    virtual bool TrackFn1_00236c50(hulk_intptr, int, hulk_intptr);
    CSmartPropDetachTrack();

  private:
    int mZero;
};

CSmartPropDetachTrack::CSmartPropDetachTrack() {
    mZero = 0;
}
} // namespace fn_00062800


// 0x00062820 CSmartPropDetachTrack::vfunc_13 (13 B): matches/0x00062820.cpp
// sym: ?vfunc_13@CSmartPropDetachTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CSmartPropDetachTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00062830 CSmartPropDetachTrack::vfunc_6 (4 B): matches/0x00062830.cpp
// sym: ?vfunc_6@CSmartPropDetachTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSmartPropDetachTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00062840 CSmartPropDetachTrack::vfunc_7 (7 B): matches/0x00062840.cpp
// sym: ?vfunc_7@CSmartPropDetachTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CSmartPropDetachTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00062860 CSmartPropDetachTrack::vfunc_12 (26 B): matches/0x00062860.cpp
// sym: ?vfunc_12@CSmartPropDetachTrack@@UAEHH@Z
// Same code shape as 0x0005e050 (propagated; names are from that function)
hulk_intptr CSmartPropDetachTrack::vfunc_12(hulk_intptr a) {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_62860*)p)->go_0001f1f0(a);
    return 0;
}

namespace fn_fa3ff49b {

// 0x00062880 FUN_00062880 (19 B): matches/0x00062880.cpp
// sym: ?FUN_00062880@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00062880() {
    FUN_00234810(((char*)&DAT_004dc648), ((char*)&DAT_004dc64c));
}

} // namespace fn_fa3ff49b

// 0x000628a0 CSmartPropThrowTrack::vfunc_0 (16 B): matches/0x000628a0.cpp
// sym: ?vfunc_0@CSmartPropThrowTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropThrowTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc648;
    return p[index];
}


// 0x000628b0 FUN_000628b0 (80 B): equivalent/0x000628b0.cpp [wrapped: conflict: CSmartPropThrowTrack]
// sym: ??0CSmartPropThrowTrack@fn_000628b0@@QAE@XZ @aca1dbe861de @w0227558e6d53
namespace fn_000628b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000628b0 @ 0x000628b0
struct FUN_00236d40 { virtual hulk_intptr slot0_000628a0(int); char pad[8]; int fieldC; FUN_00236d40(); }; struct CSmartPropThrowTrack : FUN_00236d40 { int field10,field14; float field18; int field1c,field20,field24; float field28; int field2c; float field30,field34,field38; unsigned char field3c; char pad3d[3]; int field40; CSmartPropThrowTrack(); }; CSmartPropThrowTrack::CSmartPropThrowTrack() { fieldC=0; field10=0; field14=0; field18=-1.0f; field1c=0; field20=0; field24=0; field2c=0; field40=0; field28=1.5707964f; field30=10.0f; field34=20.0f; field38=10.0f; field3c=1; }
} // namespace fn_000628b0


// 0x00062900 CSmartPropThrowTrack::vfunc_13 (13 B): matches/0x00062900.cpp
// sym: ?vfunc_13@CSmartPropThrowTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CSmartPropThrowTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00062910 CSmartPropThrowTrack::vfunc_6 (4 B): matches/0x00062910.cpp
// sym: ?vfunc_6@CSmartPropThrowTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSmartPropThrowTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00062920 CSmartPropThrowTrack::vfunc_7 (7 B): matches/0x00062920.cpp
// sym: ?vfunc_7@CSmartPropThrowTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CSmartPropThrowTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_fa3ff49b {

// 0x00062970 FUN_00062970 (19 B): matches/0x00062970.cpp
// sym: ?FUN_00062970@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00062970() {
    FUN_00234810(((char*)&DAT_004dc650), ((char*)&DAT_004dc654));
}

} // namespace fn_fa3ff49b

// 0x00062990 CSmartPropThrowingTrack::vfunc_0 (16 B): matches/0x00062990.cpp
// sym: ?vfunc_0@CSmartPropThrowingTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropThrowingTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc650;
    return p[index];
}

namespace fn_fa3ff49b {

// 0x000629a0 FUN_000629a0 (39 B): matches/0x000629a0.cpp
// sym: ??0CSmartPropThrowingTrack_629a0@fn_fa3ff49b@@QAE@XZ
CSmartPropThrowingTrack_629a0::CSmartPropThrowingTrack_629a0() {
    mC = 0;
    m10 = -1.0f;
    m8 = 1;
}

} // namespace fn_fa3ff49b

// 0x000629d0 CSmartPropThrowingTrack::vfunc_13 (13 B): matches/0x000629d0.cpp
// sym: ?vfunc_13@CSmartPropThrowingTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CSmartPropThrowingTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x000629e0 CSmartPropThrowingTrack::vfunc_6 (4 B): matches/0x000629e0.cpp
// sym: ?vfunc_6@CSmartPropThrowingTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSmartPropThrowingTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00062a30 CSmartPropThrowingTrack::vfunc_7 (28 B): matches/0x00062a30.cpp
// sym: ?vfunc_7@CSmartPropThrowingTrack@@UAEMXZ
hulk_freg CSmartPropThrowingTrack::vfunc_7() {
    hulk_freg x = this->f_10 - this->f_0c;
    if (x <= 0.0f)
        return -1.0f;
    return x;
}

namespace fn_fa3ff49b {

// 0x00062a50 FUN_00062a50 (19 B): matches/0x00062a50.cpp
// sym: ?FUN_00062a50@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00062a50() {
    FUN_00234810(((char*)&DAT_004dc658), ((char*)&DAT_004dc65c));
}

} // namespace fn_fa3ff49b

// 0x00062a70 CSmartPropDropTrack::vfunc_0 (16 B): matches/0x00062a70.cpp
// sym: ?vfunc_0@CSmartPropDropTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropDropTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc658;
    return p[index];
}


// 0x00062a80 FUN_00062a80 (32 B): matches/0x00062a80.cpp [wrapped: conflict: CSmartPropDropTrack]
// sym: ??0CSmartPropDropTrack@fn_00062a80@@QAE@XZ
namespace fn_00062a80 {
class CTrack_62a80 {
  public:
    CTrack_62a80();
    virtual ~CTrack_62a80();
    char m_a[4];
    char m_b[4];
};

class CSmartPropDropTrack : public CTrack_62a80 {
  public:
    CSmartPropDropTrack();
    virtual ~CSmartPropDropTrack();
    int m_c;
    int m_10;
};

CSmartPropDropTrack::CSmartPropDropTrack() {
    m_c = 0;
    m_10 = -1;
}
} // namespace fn_00062a80


// 0x00062aa0 CSmartPropDropTrack::vfunc_13 (13 B): matches/0x00062aa0.cpp
// sym: ?vfunc_13@CSmartPropDropTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CSmartPropDropTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00062ab0 CSmartPropDropTrack::vfunc_6 (4 B): matches/0x00062ab0.cpp
// sym: ?vfunc_6@CSmartPropDropTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSmartPropDropTrack::vfunc_6() {
    return this->f_0c;
}

namespace fn_fa3ff49b {

// 0x00062ac0 CSmartPropDropTrack::vfunc_14 (4 B): matches/0x00062ac0.cpp
// sym: ?FUN_00062ac0@fn_fa3ff49b@@YIIPAVObj_62ac0@1@@Z
// Same code shape as 0x00059a30 (propagated; names are from that function)
unsigned int __fastcall FUN_00062ac0(Obj_62ac0* self) {
    return self->value;
}

} // namespace fn_fa3ff49b

// 0x00062ad0 CSmartPropDropTrack::vfunc_7 (7 B): matches/0x00062ad0.cpp
// sym: ?vfunc_7@CSmartPropDropTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CSmartPropDropTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00062ae0 FUN_00062ae0 (11 B): matches/0x00062ae0.cpp [wrapped: conflict: CEffectStopTrack]
// sym: ?FUN_00062ae0@fn_00062ae0@@YIXPAVCEffectStopTrack@1@@Z
namespace fn_00062ae0 {
// Same code shape as 0x00060920 (propagated; names are from that function)
extern int hulk_at_003fb104;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_00068c70(CEffectStopTrack*);
void __fastcall FUN_00062ae0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&hulk_at_003fb104;
    FUN_00068c70(self);
}
} // namespace fn_00062ae0

namespace fn_fa3ff49b {

// 0x00062b20 FUN_00062b20 (19 B): matches/0x00062b20.cpp
// sym: ?FUN_00062b20@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00062b20() {
    FUN_00234810(((char*)&DAT_004dc660), ((char*)&DAT_004dc664));
}

} // namespace fn_fa3ff49b

// 0x00062b40 CSmartPropEventTrack::vfunc_0 (16 B): matches/0x00062b40.cpp
// sym: ?vfunc_0@CSmartPropEventTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropEventTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc660;
    return p[index];
}


// 0x00062b50 FUN_00062b50 (29 B): matches/0x00062b50.cpp [wrapped: conflict: CSmartPropEventTrack]
// sym: ??0CSmartPropEventTrack@fn_00062b50@@QAE@XZ
namespace fn_00062b50 {
class CTrack_62b50 {
  public:
    CTrack_62b50();
    virtual hulk_intptr BaseFn_00062b40(int);
};

class CSmartPropEventTrack : public CTrack_62b50 {
  public:
    CSmartPropEventTrack();
    virtual bool Fn_00234270(void*);
    char pad0[8];
    int m_c;
    int m_10;
    int m_14;
};

CSmartPropEventTrack::CSmartPropEventTrack() : m_c(0), m_10(0), m_14(0) {}
} // namespace fn_00062b50


// 0x00062b70 CSmartPropEventTrack::vfunc_13 (13 B): matches/0x00062b70.cpp
// sym: ?vfunc_13@CSmartPropEventTrack@@UAEXPAX@Z
// Same code shape as 0x0005dd10 (propagated; names are from that function)
void CSmartPropEventTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xffff0000;
}


// 0x00062b80 CSmartPropEventTrack::vfunc_6 (4 B): matches/0x00062b80.cpp
// sym: ?vfunc_6@CSmartPropEventTrack@@UAEMXZ
// Same code shape as 0x0005d1d0 (propagated; names are from that function)
hulk_freg CSmartPropEventTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00062b90 CSmartPropEventTrack::vfunc_7 (7 B): matches/0x00062b90.cpp
// sym: ?vfunc_7@CSmartPropEventTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CSmartPropEventTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00062bb0 CSmartPropEventTrack::vfunc_12 (47 B): matches/0x00062bb0.cpp [wrapped: conflict: CSmartPropEventTrack; FUN_0008d690]
// sym: ?vfunc_12@CSmartPropEventTrack@fn_00062bb0@@UAEII@Z
namespace fn_00062bb0 {
typedef unsigned int u32_62bb0;
struct CSmartPropEventAction_62bb0 {
    u32_62bb0 call_0001f3e0(u32_62bb0, u32_62bb0, u32_62bb0);
};
struct CSmartPropEventTrack {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual u32_62bb0 vfunc_12(u32_62bb0);
    virtual void f13();
    char pad[8];
    u32_62bb0 c;
    u32_62bb0 pad10;
    u32_62bb0 d;
};
extern void* __cdecl FUN_0008d690(int);
u32_62bb0 CSmartPropEventTrack::vfunc_12(u32_62bb0 arg) {
    void* p = FUN_0008d690(0x28);
    if (p)
        return ((CSmartPropEventAction_62bb0*)p)->call_0001f3e0(arg, d, c);
    return 0;
}
} // namespace fn_00062bb0

namespace fn_fa3ff49b {

// 0x00062be0 FUN_00062be0 (19 B): matches/0x00062be0.cpp
// sym: ?FUN_00062be0@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00062be0() {
    FUN_00234810(((char*)&DAT_004dc668), ((char*)&DAT_004dc66c));
}

} // namespace fn_fa3ff49b

// 0x00062c00 CSmartPropRemoveInstanceTrack::vfunc_0 (16 B): matches/0x00062c00.cpp
// sym: ?vfunc_0@CSmartPropRemoveInstanceTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropRemoveInstanceTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc668;
    return p[index];
}


// 0x00062c10 FUN_00062c10 (26 B): matches/0x00062c10.cpp [wrapped: conflict: CSmartPropRemoveInstanceTrack]
// sym: ??0CSmartPropRemoveInstanceTrack@fn_00062c10@@QAE@XZ
namespace fn_00062c10 {
class CTrack_62c10 {
  public:
    CTrack_62c10();
    virtual ~CTrack_62c10();
};

class CSmartPropRemoveInstanceTrack : public CTrack_62c10 {
  public:
    CSmartPropRemoveInstanceTrack();
    virtual ~CSmartPropRemoveInstanceTrack();
    char pad[8];
    int mX;
    int mY;
};

CSmartPropRemoveInstanceTrack::CSmartPropRemoveInstanceTrack() {
    mX = 0;
    mY = 0;
}
} // namespace fn_00062c10


// 0x00062c30 CSmartPropRemoveInstanceTrack::vfunc_13 (13 B): matches/0x00062c30.cpp
// sym: ?vfunc_13@CSmartPropRemoveInstanceTrack@@UAEXPAX@Z
// Same code shape as 0x0005dd10 (propagated; names are from that function)
void CSmartPropRemoveInstanceTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xffff0000;
}


// 0x00062c40 CSmartPropRemoveInstanceTrack::vfunc_6 (4 B): matches/0x00062c40.cpp
// sym: ?vfunc_6@CSmartPropRemoveInstanceTrack@@UAEMXZ
// Same code shape as 0x0005d1d0 (propagated; names are from that function)
hulk_freg CSmartPropRemoveInstanceTrack::vfunc_6() {
    return this->f_10;
}


// 0x00062c50 CSmartPropRemoveInstanceTrack::vfunc_7 (7 B): matches/0x00062c50.cpp
// sym: ?vfunc_7@CSmartPropRemoveInstanceTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CSmartPropRemoveInstanceTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_fa3ff49b {

// 0x00062ca0 FUN_00062ca0 (19 B): matches/0x00062ca0.cpp
// sym: ?FUN_00062ca0@fn_fa3ff49b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00062ca0() {
    FUN_00234810(((char*)&DAT_004dc670), ((char*)&DAT_004dc674));
}

} // namespace fn_fa3ff49b

// 0x00062cc0 CPropActorSetStateTrack::vfunc_0 (16 B): matches/0x00062cc0.cpp
// sym: ?vfunc_0@CPropActorSetStateTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CPropActorSetStateTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc670;
    return p[index];
}


// 0x00062cd0 FUN_00062cd0 (33 B): matches/0x00062cd0.cpp [wrapped: conflict: CPropActorSetStateTrack]
// sym: ??0CPropActorSetStateTrack@fn_00062cd0@@QAE@XZ
namespace fn_00062cd0 {
class CTrack_62cd0 {
  public:
    CTrack_62cd0();
    virtual void A();
};

class CPropActorSetStateTrack : public CTrack_62cd0 {
  public:
    CPropActorSetStateTrack();
    virtual void A();
    char pad[4];
    int m8;
    int mC;
    int m10;
};

CPropActorSetStateTrack::CPropActorSetStateTrack() : CTrack_62cd0() {
    mC = 0;
    m10 = 0;
    m8 = 1;
}
} // namespace fn_00062cd0


// 0x00062d00 CPropActorSetStateTrack::vfunc_13 (13 B): matches/0x00062d00.cpp
// sym: ?vfunc_13@CPropActorSetStateTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CPropActorSetStateTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00062d10 CPropActorSetStateTrack::vfunc_6 (4 B): matches/0x00062d10.cpp
// sym: ?vfunc_6@CPropActorSetStateTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CPropActorSetStateTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00062d20 CPropActorSetStateTrack::vfunc_7 (7 B): matches/0x00062d20.cpp
// sym: ?vfunc_7@CPropActorSetStateTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CPropActorSetStateTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00062d70 CWeaponCollisionTrack::vfunc_5 (62 B): matches/0x00062d70.cpp [wrapped: conflict: CWeaponCollisionTrack]
// sym: ?vfunc_5@CWeaponCollisionTrack@fn_00062d70@@QAEPAV12@E@Z
namespace fn_00062d70 {
extern int hulk_at_003faf2c;
struct SubA_62d70 {
    void init_00234150();
};
struct SubB_62d70 {
    void init2_0027af50();
};
struct CWeaponCollisionTrack_62d70 {
    void finish_00236d60();
};
class CWeaponCollisionTrack {
  public:
    hulk_intptr vf;
    char x[0x28];
    SubA_62d70 s2c;
    char y[0xb];
    SubA_62d70 s38;
    char z[0xf];
    SubB_62d70 s48;
    CWeaponCollisionTrack* vfunc_5(unsigned char p);
};
void destroy_0008d330(CWeaponCollisionTrack*);
CWeaponCollisionTrack* CWeaponCollisionTrack::vfunc_5(unsigned char p) {
    vf = (hulk_intptr)&hulk_at_003faf2c;
    s48.init2_0027af50();
    s38.init_00234150();
    s2c.init_00234150();
    ((CWeaponCollisionTrack_62d70*)this)->finish_00236d60();
    if (p & 1)
        destroy_0008d330(this);
    return this;
}
} // namespace fn_00062d70


// 0x00062db0 FUN_00062db0 (133 B): equivalent/0x00062db0.cpp [wrapped: conflict: CSmartPropAttachTrack]
// sym: ??0CSmartPropAttachTrack@fn_00062db0@@QAE@XZ @8dd91dd4e3b2 @wc29413eb9dd4
namespace fn_00062db0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00062db0 @ 0x00062db0
struct Name_62db0 {
    unsigned int a, b;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

class __declspec(novtable) CTrack_62db0 {
public:
    virtual hulk_intptr b0_00062210(int);
    int pad04;
    int pad08;
    void FUN_00236d40();
    CTrack_62db0() { FUN_00236d40(); }
};

class CSmartPropAttachTrack : public CTrack_62db0 {
public:
    virtual bool vfunc_0_00234270(void*);
    virtual bool v1_002342b0(int);
    virtual bool v2_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool v3_00234350(int, int);
    virtual void* v4_00062e40(char);
    virtual void v5_00062260();
    virtual void vfunc_6_00062270();
    virtual int vfunc_7_00068c80(int, int);

    int f0c, f10, f14;
    Name_62db0 bone;
    Name_62db0 prop;
    char enabled;
    char pad29[3];
    int f2c, f30, f34, f38, f3c, f40, f44;
    char f48;
    char pad49[3];
    int f4c, f50, f54;
    Name_62db0 extra;

    CSmartPropAttachTrack();
};

CSmartPropAttachTrack::CSmartPropAttachTrack() {
    f0c = 0; f10 = 0; f14 = 0;
    bone.FUN_0027af00();
    prop.FUN_0027af00();
    enabled = 1;
    f2c = 0; f30 = 0; f34 = 0; f38 = 0; f3c = 0; f40 = 0; f44 = 0;
    f48 = 0;
    f4c = 0; f50 = 0; f54 = 0;
    extra.FUN_0027af00();
    bone.FUN_0027b040("Wrist_R");
    prop.FUN_0027b040("Wealded_Weap_1");
    extra.FUN_0027b040(0);
}
} // namespace fn_00062db0


// 0x00062e40 CSmartPropAttachTrack::vfunc_5 (62 B): matches/0x00062e40.cpp [wrapped: conflict: CSmartPropAttachTrack]
// sym: ?vfunc_5@CSmartPropAttachTrack@fn_00062e40@@UAEPAU12@E@Z
namespace fn_00062e40 {
extern int hulk_at_003faf60;
struct CSmartPropAttachTrack;
void FUN_0008d330(CSmartPropAttachTrack*);
struct A_62e40 {
    void Fnf_0027af50();
};
struct B_62e40 {
    void Fnf_00068c70();
};
struct CSmartPropAttachTrack {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CSmartPropAttachTrack* vfunc_5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[0x58 - 4];
};
CSmartPropAttachTrack* CSmartPropAttachTrack::vfunc_5(unsigned char p) {
    *(void**)this = &hulk_at_003faf60;
    ((A_62e40*)((char*)this + 0x58))->Fnf_0027af50();
    ((A_62e40*)((char*)this + 0x20))->Fnf_0027af50();
    ((A_62e40*)((char*)this + 0x18))->Fnf_0027af50();
    ((B_62e40*)this)->Fnf_00068c70();
    if (p & 1)
        FUN_0008d330(this);
    return this;
}
} // namespace fn_00062e40


// 0x00062e80 CSmartPropUpdateAttachmentTrack::vfunc_5 (54 B): matches/0x00062e80.cpp [wrapped: conflict: CSmartPropUpdateAttachmentTrack]
// sym: ?CSmartPropUpdateAttachmentTrack_vfunc_5@fn_00062e80@@YIPAUCSmartPropUpdateAttachmentTrack@1@PAU21@PAXE@Z
namespace fn_00062e80 {
extern "C" char DAT_003faf9c[];
typedef unsigned char byte_62e80;
struct CSmartPropUpdateAttachmentTrack {
    char pad[0x24];
};
void __fastcall Init_0027af50(void*);
void __fastcall Setup_00068c70(CSmartPropUpdateAttachmentTrack*);
void __cdecl Destroy_0008d330(CSmartPropUpdateAttachmentTrack*);
CSmartPropUpdateAttachmentTrack* __fastcall
CSmartPropUpdateAttachmentTrack_vfunc_5(CSmartPropUpdateAttachmentTrack* p, void*, byte_62e80 b) {
    *(hulk_ulongptr*)p = ((hulk_intptr)DAT_003faf9c);
    Init_0027af50((char*)p + 0x20);
    Init_0027af50((char*)p + 0x18);
    Setup_00068c70(p);
    if (b & 1)
        Destroy_0008d330(p);
    return p;
}
} // namespace fn_00062e80


// 0x00062ec0 CSmartPropSpawnTrack::vfunc_5 (71 B): matches/0x00062ec0.cpp [wrapped: conflict: CSmartPropSpawnTrack]
// sym: ?vfunc_5@CSmartPropSpawnTrack@fn_00062ec0@@UAEPAV12@E@Z
namespace fn_00062ec0 {
class CSmartPropSpawnTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CSmartPropSpawnTrack* vfunc_5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[0x94];
    void finish_00068c70();
};
struct Helper_62ec0 {
    void call_0027af50();
};
extern void* hulk_at_003fafd8[];
extern void FUN_0008d330(CSmartPropSpawnTrack*);
CSmartPropSpawnTrack* CSmartPropSpawnTrack::vfunc_5(unsigned char p) {
    ((void**)this)[0] = hulk_at_003fafd8;
    ((Helper_62ec0*)((char*)this + 0xc8))->call_0027af50();
    ((Helper_62ec0*)((char*)this + 0xa0))->call_0027af50();
    ((Helper_62ec0*)((char*)this + 0x98))->call_0027af50();
    finish_00068c70();
    if (p & 1)
        FUN_0008d330(this);
    return this;
}
} // namespace fn_00062ec0


// 0x00062f10 CSmartPropSetStateTrack::vfunc_5 (36 B): matches/0x00062f10.cpp [wrapped: conflict: CSmartPropSetStateTrack; CTrack]
// sym: ?vfunc_5@CSmartPropSetStateTrack@fn_00062f10@@QAEPAV12@C@Z
namespace fn_00062f10 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fb014[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CSmartPropSetStateTrack : public CTrack {
  public:
    CSmartPropSetStateTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CSmartPropSetStateTrack* CSmartPropSetStateTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fb014;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00062f10


// 0x00062f40 CSmartPropDetachTrack::vfunc_5 (36 B): matches/0x00062f40.cpp [wrapped: conflict: CSmartPropDetachTrack; CTrack]
// sym: ?vfunc_5@CSmartPropDetachTrack@fn_00062f40@@QAEPAV12@C@Z
namespace fn_00062f40 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fb050[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CSmartPropDetachTrack : public CTrack {
  public:
    CSmartPropDetachTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CSmartPropDetachTrack* CSmartPropDetachTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fb050;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00062f40


// 0x00062f70 CSmartPropThrowTrack::vfunc_5 (36 B): matches/0x00062f70.cpp [wrapped: conflict: CSmartPropThrowTrack; CTrack]
// sym: ?vfunc_5@CSmartPropThrowTrack@fn_00062f70@@QAEPAV12@C@Z
namespace fn_00062f70 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fb08c[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CSmartPropThrowTrack : public CTrack {
  public:
    CSmartPropThrowTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CSmartPropThrowTrack* CSmartPropThrowTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fb08c;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00062f70


// 0x00062fa0 CSmartPropThrowingTrack::vfunc_5 (36 B): matches/0x00062fa0.cpp [wrapped: conflict: CSmartPropThrowingTrack; CTrack]
// sym: ?vfunc_5@CSmartPropThrowingTrack@fn_00062fa0@@QAEPAV12@C@Z
namespace fn_00062fa0 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fb0c8[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CSmartPropThrowingTrack : public CTrack {
  public:
    CSmartPropThrowingTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CSmartPropThrowingTrack* CSmartPropThrowingTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fb0c8;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00062fa0


// 0x00062fd0 CSmartPropDropTrack::vfunc_5 (36 B): matches/0x00062fd0.cpp [wrapped: conflict: CSmartPropDropTrack; CTrack]
// sym: ?vfunc_5@CSmartPropDropTrack@fn_00062fd0@@QAEPAV12@C@Z
namespace fn_00062fd0 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CTrack_vftable[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CSmartPropDropTrack : public CTrack {
  public:
    CSmartPropDropTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CSmartPropDropTrack* CSmartPropDropTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00062fd0


// 0x00063000 CSmartPropEventTrack::vfunc_5 (36 B): matches/0x00063000.cpp [wrapped: conflict: CSmartPropEventTrack; CTrack]
// sym: ?vfunc_5@CSmartPropEventTrack@fn_00063000@@QAEPAV12@C@Z
namespace fn_00063000 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fb144[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CSmartPropEventTrack : public CTrack {
  public:
    CSmartPropEventTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CSmartPropEventTrack* CSmartPropEventTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fb144;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00063000


// 0x00063030 CSmartPropRemoveInstanceTrack::vfunc_5 (36 B): matches/0x00063030.cpp [wrapped: conflict: CSmartPropRemoveInstanceTrack; CTrack]
// sym: ?vfunc_5@CSmartPropRemoveInstanceTrack@fn_00063030@@QAEPAV12@C@Z
namespace fn_00063030 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fb180[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CSmartPropRemoveInstanceTrack : public CTrack {
  public:
    CSmartPropRemoveInstanceTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CSmartPropRemoveInstanceTrack* CSmartPropRemoveInstanceTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fb180;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00063030


// 0x00063060 CPropActorSetStateTrack::vfunc_5 (36 B): matches/0x00063060.cpp [wrapped: conflict: CPropActorSetStateTrack; CTrack]
// sym: ?vfunc_5@CPropActorSetStateTrack@fn_00063060@@QAEPAV12@C@Z
namespace fn_00063060 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fb1bc[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CPropActorSetStateTrack : public CTrack {
  public:
    CPropActorSetStateTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CPropActorSetStateTrack* CPropActorSetStateTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fb1bc;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00063060


// 0x000630b0 fight::ParamFloatConstRange<CWeaponCollisionTrack>::vfunc_6 (26 B): matches/0x000630b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CWeaponCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CWeaponCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CWeaponCollisionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CWeaponCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x000630d0 fight::ParamFloatConstRange<CWeaponCollisionTrack>::vfunc_2 (11 B): matches/0x000630d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CWeaponCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063100 fight::ParamIntConstRange<CWeaponCollisionTrack>::vfunc_6 (26 B): matches/0x00063100.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CWeaponCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CWeaponCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CWeaponCollisionTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CWeaponCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x00063120 fight::ParamIntConstRange<CWeaponCollisionTrack>::vfunc_2 (11 B): matches/0x00063120.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CWeaponCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063150 fight::ParamBool<CWeaponCollisionTrack>::vfunc_6 (26 B): matches/0x00063150.cpp
// sym: ?vfunc_6@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CWeaponCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CWeaponCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CWeaponCollisionTrack>*)a)->*(*(bool (fight::ParamBool<CWeaponCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x00063170 fight::ParamBool<CWeaponCollisionTrack>::vfunc_2 (11 B): matches/0x00063170.cpp
// sym: ?vfunc_2@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CWeaponCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000631b0 fight::ParamEnumConstList<CWeaponCollisionTrack>::vfunc_7 (6 B): matches/0x000631b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCWeaponCollisionTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CWeaponCollisionTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x000631c0 fight::ParamEnumConstList<CWeaponCollisionTrack>::vfunc_6 (30 B): matches/0x000631c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCWeaponCollisionTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CWeaponCollisionTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_631c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_631c0*)&DAT_003f335c));
}


// 0x000631e0 fight::ParamEnumConstList<CWeaponCollisionTrack>::vfunc_8 (26 B): matches/0x000631e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CWeaponCollisionTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CWeaponCollisionTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CWeaponCollisionTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CWeaponCollisionTrack>::**)(int))&this->f_18))(b);
}


// 0x00063200 fight::ParamEnumConstList<CWeaponCollisionTrack>::vfunc_2 (11 B): matches/0x00063200.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CWeaponCollisionTrack>::vfunc_2() {
    return this->f_18 == 0;
}

namespace fn_fa3ff49b {

// 0x00063230 fight::ParamBranch<CWeaponCollisionTrack>::vfunc_6 (12 B): matches/0x00063230.cpp
// sym: ?vfunc_6@ParamBranch@fn_fa3ff49b@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fa3ff49b

// 0x00063260 fight::ParamString<CWeaponCollisionTrack>::vfunc_6 (26 B): matches/0x00063260.cpp
// sym: ?vfunc_6@?$ParamString@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<CWeaponCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<CWeaponCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<CWeaponCollisionTrack>*)a)->*(*(bool (fight::ParamString<CWeaponCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x00063280 fight::ParamString<CWeaponCollisionTrack>::vfunc_2 (11 B): matches/0x00063280.cpp
// sym: ?vfunc_2@?$ParamString@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<CWeaponCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000632b0 fight::ParamVector<CWeaponCollisionTrack>::vfunc_6 (26 B): matches/0x000632b0.cpp
// sym: ?vfunc_6@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CWeaponCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CWeaponCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CWeaponCollisionTrack>*)a)->*(*(bool (fight::ParamVector<CWeaponCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x000632d0 fight::ParamVector<CWeaponCollisionTrack>::vfunc_2 (11 B): matches/0x000632d0.cpp
// sym: ?vfunc_2@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CWeaponCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063300 fight::ParamBoolPtr<CWeaponCollisionTrack>::vfunc_6 (19 B): matches/0x00063300.cpp
// sym: ?vfunc_6@?$ParamBoolPtr@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0005e4b0 (propagated; names are from that function)
template <> bool fight::ParamBoolPtr<CWeaponCollisionTrack>::vfunc_6(hulk_intptr __p0, int __p1) { unsigned char * p = (unsigned char *)__p0; unsigned char v = (unsigned char)__p1;

    p[this->f_10] = v;
    return true;
}

namespace fn_fa3ff49b {

// 0x00063340 fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>::vfunc_6 (19 B): matches/0x00063340.cpp
// sym: ?v6@ParamFloatPtrConstRange@fn_fa3ff49b@@UAE_NPAXM@Z
// Same code shape as 0x0005e4f0 (propagated; names are from that function)
bool ParamFloatPtrConstRange::v6(void* p, float value) {
    *(float*)((char*)p + offset) = value;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00063380 fight::ParamFloatConstRange<CSmartPropAttachTrack>::vfunc_6 (26 B): matches/0x00063380.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropAttachTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropAttachTrack>::**)(int))&this->f_10))(b);
}


// 0x000633a0 fight::ParamFloatConstRange<CSmartPropAttachTrack>::vfunc_2 (11 B): matches/0x000633a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropAttachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000633d0 fight::ParamIntConstRange<CSmartPropAttachTrack>::vfunc_6 (26 B): matches/0x000633d0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropAttachTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropAttachTrack>::**)(int))&this->f_10))(b);
}


// 0x000633f0 fight::ParamIntConstRange<CSmartPropAttachTrack>::vfunc_2 (11 B): matches/0x000633f0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropAttachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063420 fight::ParamBool<CSmartPropAttachTrack>::vfunc_6 (26 B): matches/0x00063420.cpp
// sym: ?vfunc_6@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CSmartPropAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CSmartPropAttachTrack>*)a)->*(*(bool (fight::ParamBool<CSmartPropAttachTrack>::**)(int))&this->f_10))(b);
}


// 0x00063440 fight::ParamBool<CSmartPropAttachTrack>::vfunc_2 (11 B): matches/0x00063440.cpp
// sym: ?vfunc_2@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropAttachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063470 fight::ParamVector<CSmartPropAttachTrack>::vfunc_6 (26 B): matches/0x00063470.cpp
// sym: ?vfunc_6@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CSmartPropAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CSmartPropAttachTrack>*)a)->*(*(bool (fight::ParamVector<CSmartPropAttachTrack>::**)(int))&this->f_10))(b);
}


// 0x00063490 fight::ParamVector<CSmartPropAttachTrack>::vfunc_2 (11 B): matches/0x00063490.cpp
// sym: ?vfunc_2@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropAttachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000634c0 fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_6 (26 B): matches/0x000634c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>::**)(int))&this->f_10))(b);
}


// 0x000634e0 fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_2 (11 B): matches/0x000634e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063510 fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_6 (26 B): matches/0x00063510.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>::**)(int))&this->f_10))(b);
}


// 0x00063530 fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_2 (11 B): matches/0x00063530.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063560 fight::ParamBool<CSmartPropUpdateAttachmentTrack>::vfunc_6 (26 B): matches/0x00063560.cpp
// sym: ?vfunc_6@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropUpdateAttachmentTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CSmartPropUpdateAttachmentTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CSmartPropUpdateAttachmentTrack>*)a)->*(*(bool (fight::ParamBool<CSmartPropUpdateAttachmentTrack>::**)(int))&this->f_10))(b);
}


// 0x00063580 fight::ParamBool<CSmartPropUpdateAttachmentTrack>::vfunc_2 (11 B): matches/0x00063580.cpp
// sym: ?vfunc_2@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropUpdateAttachmentTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000635b0 fight::ParamVector<CSmartPropUpdateAttachmentTrack>::vfunc_6 (26 B): matches/0x000635b0.cpp
// sym: ?vfunc_6@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropUpdateAttachmentTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CSmartPropUpdateAttachmentTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CSmartPropUpdateAttachmentTrack>*)a)->*(*(bool (fight::ParamVector<CSmartPropUpdateAttachmentTrack>::**)(int))&this->f_10))(b);
}


// 0x000635d0 fight::ParamVector<CSmartPropUpdateAttachmentTrack>::vfunc_2 (11 B): matches/0x000635d0.cpp
// sym: ?vfunc_2@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropUpdateAttachmentTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063600 fight::ParamFloatConstRange<CSmartPropSpawnTrack>::vfunc_6 (26 B): matches/0x00063600.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropSpawnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropSpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropSpawnTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropSpawnTrack>::**)(int))&this->f_10))(b);
}


// 0x00063620 fight::ParamFloatConstRange<CSmartPropSpawnTrack>::vfunc_2 (11 B): matches/0x00063620.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropSpawnTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063650 fight::ParamString<CSmartPropSpawnTrack>::vfunc_6 (26 B): matches/0x00063650.cpp
// sym: ?vfunc_6@?$ParamString@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<CSmartPropSpawnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<CSmartPropSpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<CSmartPropSpawnTrack>*)a)->*(*(bool (fight::ParamString<CSmartPropSpawnTrack>::**)(int))&this->f_10))(b);
}


// 0x00063670 fight::ParamString<CSmartPropSpawnTrack>::vfunc_2 (11 B): matches/0x00063670.cpp
// sym: ?vfunc_2@?$ParamString@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<CSmartPropSpawnTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000636a0 fight::ParamIntConstRange<CSmartPropSpawnTrack>::vfunc_6 (26 B): matches/0x000636a0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropSpawnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropSpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropSpawnTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropSpawnTrack>::**)(int))&this->f_10))(b);
}


// 0x000636c0 fight::ParamIntConstRange<CSmartPropSpawnTrack>::vfunc_2 (11 B): matches/0x000636c0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropSpawnTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000636f0 fight::ParamBool<CSmartPropSpawnTrack>::vfunc_6 (26 B): matches/0x000636f0.cpp
// sym: ?vfunc_6@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropSpawnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CSmartPropSpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CSmartPropSpawnTrack>*)a)->*(*(bool (fight::ParamBool<CSmartPropSpawnTrack>::**)(int))&this->f_10))(b);
}


// 0x00063710 fight::ParamBool<CSmartPropSpawnTrack>::vfunc_2 (11 B): matches/0x00063710.cpp
// sym: ?vfunc_2@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropSpawnTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063740 fight::ParamVector<CSmartPropSpawnTrack>::vfunc_6 (26 B): matches/0x00063740.cpp
// sym: ?vfunc_6@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropSpawnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CSmartPropSpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CSmartPropSpawnTrack>*)a)->*(*(bool (fight::ParamVector<CSmartPropSpawnTrack>::**)(int))&this->f_10))(b);
}


// 0x00063760 fight::ParamVector<CSmartPropSpawnTrack>::vfunc_2 (11 B): matches/0x00063760.cpp
// sym: ?vfunc_2@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropSpawnTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063790 fight::ParamFloatConstRange<CSmartPropSetStateTrack>::vfunc_6 (26 B): matches/0x00063790.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropSetStateTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropSetStateTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropSetStateTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropSetStateTrack>::**)(int))&this->f_10))(b);
}


// 0x000637b0 fight::ParamFloatConstRange<CSmartPropSetStateTrack>::vfunc_2 (11 B): matches/0x000637b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropSetStateTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000637e0 fight::ParamIntConstRange<CSmartPropSetStateTrack>::vfunc_6 (26 B): matches/0x000637e0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropSetStateTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropSetStateTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropSetStateTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropSetStateTrack>::**)(int))&this->f_10))(b);
}


// 0x00063800 fight::ParamIntConstRange<CSmartPropSetStateTrack>::vfunc_2 (11 B): matches/0x00063800.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropSetStateTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063830 fight::ParamFloatConstRange<CSmartPropDetachTrack>::vfunc_6 (26 B): matches/0x00063830.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropDetachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropDetachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropDetachTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropDetachTrack>::**)(int))&this->f_10))(b);
}


// 0x00063850 fight::ParamFloatConstRange<CSmartPropDetachTrack>::vfunc_2 (11 B): matches/0x00063850.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropDetachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063880 fight::ParamFloatConstRange<CSmartPropThrowTrack>::vfunc_6 (26 B): matches/0x00063880.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropThrowTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x000638a0 fight::ParamFloatConstRange<CSmartPropThrowTrack>::vfunc_2 (11 B): matches/0x000638a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000638d0 fight::ParamIntConstRange<CSmartPropThrowTrack>::vfunc_6 (26 B): matches/0x000638d0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropThrowTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x000638f0 fight::ParamIntConstRange<CSmartPropThrowTrack>::vfunc_2 (11 B): matches/0x000638f0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063920 fight::ParamVector<CSmartPropThrowTrack>::vfunc_6 (26 B): matches/0x00063920.cpp
// sym: ?vfunc_6@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CSmartPropThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CSmartPropThrowTrack>*)a)->*(*(bool (fight::ParamVector<CSmartPropThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00063940 fight::ParamVector<CSmartPropThrowTrack>::vfunc_2 (11 B): matches/0x00063940.cpp
// sym: ?vfunc_2@?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063970 fight::ParamBool<CSmartPropThrowTrack>::vfunc_6 (26 B): matches/0x00063970.cpp
// sym: ?vfunc_6@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CSmartPropThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CSmartPropThrowTrack>*)a)->*(*(bool (fight::ParamBool<CSmartPropThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00063990 fight::ParamBool<CSmartPropThrowTrack>::vfunc_2 (11 B): matches/0x00063990.cpp
// sym: ?vfunc_2@?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000639c0 fight::ParamFloatConstRange<CSmartPropThrowingTrack>::vfunc_6 (26 B): matches/0x000639c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropThrowingTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropThrowingTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropThrowingTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropThrowingTrack>::**)(int))&this->f_10))(b);
}


// 0x000639e0 fight::ParamFloatConstRange<CSmartPropThrowingTrack>::vfunc_2 (11 B): matches/0x000639e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropThrowingTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063a10 fight::ParamFloatConstRange<CSmartPropDropTrack>::vfunc_6 (26 B): matches/0x00063a10.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropDropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropDropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropDropTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropDropTrack>::**)(int))&this->f_10))(b);
}


// 0x00063a30 fight::ParamFloatConstRange<CSmartPropDropTrack>::vfunc_2 (11 B): matches/0x00063a30.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropDropTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063a60 fight::ParamIntConstRange<CSmartPropDropTrack>::vfunc_6 (26 B): matches/0x00063a60.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropDropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropDropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropDropTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropDropTrack>::**)(int))&this->f_10))(b);
}


// 0x00063a80 fight::ParamIntConstRange<CSmartPropDropTrack>::vfunc_2 (11 B): matches/0x00063a80.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropDropTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063ab0 fight::ParamIntConstRange<CSmartPropEventTrack>::vfunc_6 (26 B): matches/0x00063ab0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropEventTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropEventTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropEventTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropEventTrack>::**)(int))&this->f_10))(b);
}


// 0x00063ad0 fight::ParamIntConstRange<CSmartPropEventTrack>::vfunc_2 (11 B): matches/0x00063ad0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropEventTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063b10 fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_7 (6 B): matches/0x00063b10.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCWeaponCollisionTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00063b20 fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_6 (30 B): matches/0x00063b20.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCWeaponCollisionTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_63b20 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_63b20*)&DAT_003f335c));
}


// 0x00063b40 fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_8 (26 B): matches/0x00063b40.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropEventTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropEventTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropEventTrack>::**)(int))&this->f_18))(b);
}


// 0x00063b60 fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_2 (11 B): matches/0x00063b60.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00063b90 fight::ParamFloatConstRange<CSmartPropEventTrack>::vfunc_6 (26 B): matches/0x00063b90.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropEventTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropEventTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropEventTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropEventTrack>::**)(int))&this->f_10))(b);
}


// 0x00063bb0 fight::ParamFloatConstRange<CSmartPropEventTrack>::vfunc_2 (11 B): matches/0x00063bb0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropEventTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063be0 fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>::vfunc_6 (26 B): matches/0x00063be0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>::**)(int))&this->f_10))(b);
}


// 0x00063c00 fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>::vfunc_2 (11 B): matches/0x00063c00.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063c30 fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>::vfunc_6 (26 B): matches/0x00063c30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>::**)(int))&this->f_10))(b);
}


// 0x00063c50 fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>::vfunc_2 (11 B): matches/0x00063c50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063c80 fight::ParamFloatConstRange<CPropActorSetStateTrack>::vfunc_6 (26 B): matches/0x00063c80.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CPropActorSetStateTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CPropActorSetStateTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CPropActorSetStateTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CPropActorSetStateTrack>::**)(int))&this->f_10))(b);
}


// 0x00063ca0 fight::ParamFloatConstRange<CPropActorSetStateTrack>::vfunc_2 (11 B): matches/0x00063ca0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CPropActorSetStateTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063cd0 fight::ParamIntConstRange<CPropActorSetStateTrack>::vfunc_6 (26 B): matches/0x00063cd0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CPropActorSetStateTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CPropActorSetStateTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CPropActorSetStateTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CPropActorSetStateTrack>::**)(int))&this->f_10))(b);
}


// 0x00063cf0 fight::ParamIntConstRange<CPropActorSetStateTrack>::vfunc_2 (11 B): matches/0x00063cf0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CPropActorSetStateTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00063d00 fight::ParamFloatConstRange<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x00063d00.cpp
// sym: ??_G?$ParamFloatConstRange@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CWeaponCollisionTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63d00)
#endif


// 0x00063d20 fight::ParamIntConstRange<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x00063d20.cpp
// sym: ??_G?$ParamIntConstRange@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CWeaponCollisionTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63d20)
#endif


// 0x00063d40 fight::ParamBool<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x00063d40.cpp
// sym: ??_G?$ParamBool@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CWeaponCollisionTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63d40)
#endif


// 0x00063d60 fight::ParamEnumConstList<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x00063d60.cpp
// sym: ??_G?$ParamEnumConstList@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CWeaponCollisionTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63d60)
#endif


// 0x00063d80 fight::ParamBranch<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x00063d80.cpp
// sym: ??_G?$ParamBranch@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<CWeaponCollisionTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63d80)
#endif


// 0x00063da0 fight::ParamString<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x00063da0.cpp
// sym: ??_G?$ParamString@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<CWeaponCollisionTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63da0)
#endif


// 0x00063dc0 fight::ParamVector<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x00063dc0.cpp
// sym: ??_G?$ParamVector@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CWeaponCollisionTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63dc0)
#endif


// 0x00063de0 fight::ParamBoolPtr<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x00063de0.cpp
// sym: ??_G?$ParamBoolPtr@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBoolPtr<CWeaponCollisionTrack>::~ParamBoolPtr() {}
#if defined(HULK_PTR64)
template class fight::ParamBoolPtr<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63de0)
#endif


// 0x00063e00 fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x00063e00.cpp
// sym: ??_G?$ParamFloatPtrConstRange@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>::~ParamFloatPtrConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63e00)
#endif


// 0x00063e20 fight::ParamFloatConstRange<CSmartPropAttachTrack>::vfunc_0 (30 B): matches/0x00063e20.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropAttachTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63e20)
#endif


// 0x00063e40 fight::ParamIntConstRange<CSmartPropAttachTrack>::vfunc_0 (30 B): matches/0x00063e40.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropAttachTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63e40)
#endif


// 0x00063e60 fight::ParamBool<CSmartPropAttachTrack>::vfunc_0 (30 B): matches/0x00063e60.cpp
// sym: ??_G?$ParamBool@VCSmartPropAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CSmartPropAttachTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CSmartPropAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63e60)
#endif


// 0x00063e80 fight::ParamVector<CSmartPropAttachTrack>::vfunc_0 (30 B): matches/0x00063e80.cpp
// sym: ??_G?$ParamVector@VCSmartPropAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CSmartPropAttachTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CSmartPropAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63e80)
#endif


// 0x00063ea0 fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_0 (30 B): matches/0x00063ea0.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropUpdateAttachmentTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63ea0)
#endif


// 0x00063ec0 fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>::vfunc_0 (30 B): matches/0x00063ec0.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropUpdateAttachmentTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropUpdateAttachmentTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63ec0)
#endif


// 0x00063ee0 fight::ParamBool<CSmartPropUpdateAttachmentTrack>::vfunc_0 (30 B): matches/0x00063ee0.cpp
// sym: ??_G?$ParamBool@VCSmartPropUpdateAttachmentTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CSmartPropUpdateAttachmentTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CSmartPropUpdateAttachmentTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63ee0)
#endif


// 0x00063f00 fight::ParamVector<CSmartPropUpdateAttachmentTrack>::vfunc_0 (30 B): matches/0x00063f00.cpp
// sym: ??_G?$ParamVector@VCSmartPropUpdateAttachmentTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CSmartPropUpdateAttachmentTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CSmartPropUpdateAttachmentTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63f00)
#endif


// 0x00063f20 fight::ParamFloatConstRange<CSmartPropSpawnTrack>::vfunc_0 (30 B): matches/0x00063f20.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropSpawnTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropSpawnTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63f20)
#endif


// 0x00063f40 fight::ParamString<CSmartPropSpawnTrack>::vfunc_0 (30 B): matches/0x00063f40.cpp
// sym: ??_G?$ParamString@VCSmartPropSpawnTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<CSmartPropSpawnTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<CSmartPropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63f40)
#endif


// 0x00063f60 fight::ParamIntConstRange<CSmartPropSpawnTrack>::vfunc_0 (30 B): matches/0x00063f60.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropSpawnTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropSpawnTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63f60)
#endif


// 0x00063f80 fight::ParamBool<CSmartPropSpawnTrack>::vfunc_0 (30 B): matches/0x00063f80.cpp
// sym: ??_G?$ParamBool@VCSmartPropSpawnTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CSmartPropSpawnTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CSmartPropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63f80)
#endif


// 0x00063fa0 fight::ParamVector<CSmartPropSpawnTrack>::vfunc_0 (30 B): matches/0x00063fa0.cpp
// sym: ??_G?$ParamVector@VCSmartPropSpawnTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CSmartPropSpawnTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CSmartPropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63fa0)
#endif


// 0x00063fc0 fight::ParamFloatConstRange<CSmartPropSetStateTrack>::vfunc_0 (30 B): matches/0x00063fc0.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropSetStateTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropSetStateTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropSetStateTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63fc0)
#endif


// 0x00063fe0 fight::ParamIntConstRange<CSmartPropSetStateTrack>::vfunc_0 (30 B): matches/0x00063fe0.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropSetStateTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropSetStateTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropSetStateTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x63fe0)
#endif


// 0x00064000 fight::ParamFloatConstRange<CSmartPropDetachTrack>::vfunc_0 (30 B): matches/0x00064000.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropDetachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropDetachTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropDetachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64000)
#endif


// 0x00064020 fight::ParamFloatConstRange<CSmartPropThrowTrack>::vfunc_0 (30 B): matches/0x00064020.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropThrowTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropThrowTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64020)
#endif


// 0x00064040 fight::ParamIntConstRange<CSmartPropThrowTrack>::vfunc_0 (30 B): matches/0x00064040.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropThrowTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropThrowTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64040)
#endif


// 0x00064060 fight::ParamVector<CSmartPropThrowTrack>::vfunc_0 (30 B): matches/0x00064060.cpp
// sym: ??_G?$ParamVector@VCSmartPropThrowTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CSmartPropThrowTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CSmartPropThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64060)
#endif


// 0x00064080 fight::ParamBool<CSmartPropThrowTrack>::vfunc_0 (30 B): matches/0x00064080.cpp
// sym: ??_G?$ParamBool@VCSmartPropThrowTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CSmartPropThrowTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CSmartPropThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64080)
#endif


// 0x000640a0 fight::ParamFloatConstRange<CSmartPropThrowingTrack>::vfunc_0 (30 B): matches/0x000640a0.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropThrowingTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropThrowingTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropThrowingTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x640a0)
#endif


// 0x000640c0 fight::ParamFloatConstRange<CSmartPropDropTrack>::vfunc_0 (30 B): matches/0x000640c0.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropDropTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropDropTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropDropTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x640c0)
#endif


// 0x000640e0 fight::ParamIntConstRange<CSmartPropDropTrack>::vfunc_0 (30 B): matches/0x000640e0.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropDropTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropDropTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropDropTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x640e0)
#endif


// 0x00064100 fight::ParamIntConstRange<CSmartPropEventTrack>::vfunc_0 (30 B): matches/0x00064100.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropEventTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropEventTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropEventTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64100)
#endif


// 0x00064120 fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_0 (30 B): matches/0x00064120.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropEventTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CSmartPropEventTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CSmartPropEventTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64120)
#endif


// 0x00064140 fight::ParamFloatConstRange<CSmartPropEventTrack>::vfunc_0 (30 B): matches/0x00064140.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropEventTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropEventTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropEventTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64140)
#endif


// 0x00064160 fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>::vfunc_0 (30 B): matches/0x00064160.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropRemoveInstanceTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropRemoveInstanceTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64160)
#endif


// 0x00064180 fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>::vfunc_0 (30 B): matches/0x00064180.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropRemoveInstanceTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropRemoveInstanceTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64180)
#endif


// 0x000641a0 fight::ParamFloatConstRange<CPropActorSetStateTrack>::vfunc_0 (30 B): matches/0x000641a0.cpp
// sym: ??_G?$ParamFloatConstRange@VCPropActorSetStateTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CPropActorSetStateTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CPropActorSetStateTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x641a0)
#endif


// 0x000641c0 fight::ParamIntConstRange<CPropActorSetStateTrack>::vfunc_0 (30 B): matches/0x000641c0.cpp
// sym: ??_G?$ParamIntConstRange@VCPropActorSetStateTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CPropActorSetStateTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CPropActorSetStateTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x641c0)
#endif

namespace fn_fa3ff49b {

// 0x000642e0 FUN_000642e0 (562 B): equivalent/0x000642e0.cpp
// sym: _FUN_000642e0 @b8938b6db98f @w1641c446770f
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 22/22)
// FUN_000642e0 @ 0x000642e0
extern "C" void FUN_000642e0()
{
    if (DAT_004dc64c == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("timeBegin", &CSmartPropThrowTrack_642e0::FUN_00061e60);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange_642e0<CSmartPropThrowTrack_642e0>("attachmentIndex", &CSmartPropThrowTrack_642e0::FUN_00061e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_642e0<CSmartPropThrowTrack_642e0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector_642e0<CSmartPropThrowTrack_642e0>("direction", &CSmartPropThrowTrack_642e0::FUN_00061e80);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_642e0<CSmartPropThrowTrack_642e0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_642e0<CSmartPropThrowTrack_642e0>("offset", &CSmartPropThrowTrack_642e0::FUN_00061ea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("arc", &CSmartPropThrowTrack_642e0::FUN_00061ec0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("minDistance", &CSmartPropThrowTrack_642e0::FUN_00061ee0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("maxDistance", &CSmartPropThrowTrack_642e0::FUN_00061ef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("velocity", &CSmartPropThrowTrack_642e0::FUN_00061f00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("naturalDistance", &CSmartPropThrowTrack_642e0::FUN_00061f10);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_642e0<CSmartPropThrowTrack_642e0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_642e0<CSmartPropThrowTrack_642e0>("useYVelocity", &CSmartPropThrowTrack_642e0::FUN_00061f20);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc648), params, 10);
    }
    DAT_004dc64c++;
}

} // namespace fn_fa3ff49b

// 0x000648b0 fight::ParamName<CWeaponCollisionTrack>::vfunc_7 (12 B): matches/0x000648b0.cpp [wrapped: same definition as 0x00063230 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_000648b0@@UAEXPAX@Z
namespace fn_000648b0 {
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
} // namespace fn_000648b0


// 0x000648e0 fight::ParamNameConstList<CSmartPropAttachTrack>::vfunc_7 (12 B): matches/0x000648e0.cpp [wrapped: same definition as 0x00063230 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_000648e0@@UAEXPAX@Z
namespace fn_000648e0 {
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
} // namespace fn_000648e0


// 0x00064910 fight::ParamName<CSmartPropAttachTrack>::vfunc_7 (12 B): matches/0x00064910.cpp [wrapped: same definition as 0x00063230 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00064910@@UAEXPAX@Z
namespace fn_00064910 {
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
} // namespace fn_00064910


// 0x00064940 fight::ParamNameConstList<CSmartPropUpdateAttachmentTrack>::vfunc_7 (12 B): matches/0x00064940.cpp [wrapped: same definition as 0x00063230 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00064940@@UAEXPAX@Z
namespace fn_00064940 {
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
} // namespace fn_00064940


// 0x00064970 fight::ParamName<CSmartPropSpawnTrack>::vfunc_7 (12 B): matches/0x00064970.cpp [wrapped: same definition as 0x00063230 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00064970@@UAEXPAX@Z
namespace fn_00064970 {
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
} // namespace fn_00064970


// 0x000649a0 fight::ParamNameConstList<CSmartPropSpawnTrack>::vfunc_7 (12 B): matches/0x000649a0.cpp [wrapped: same definition as 0x00063230 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_000649a0@@UAEXPAX@Z
namespace fn_000649a0 {
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
} // namespace fn_000649a0


// 0x000649b0 fight::ParamName<CWeaponCollisionTrack>::vfunc_0 (30 B): matches/0x000649b0.cpp
// sym: ??_G?$ParamName@VCWeaponCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CWeaponCollisionTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CWeaponCollisionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x649b0)
#endif


// 0x000649d0 fight::ParamNameConstList<CSmartPropAttachTrack>::vfunc_0 (30 B): matches/0x000649d0.cpp
// sym: ??_G?$ParamNameConstList@VCSmartPropAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CSmartPropAttachTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CSmartPropAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x649d0)
#endif


// 0x000649f0 fight::ParamName<CSmartPropAttachTrack>::vfunc_0 (30 B): matches/0x000649f0.cpp
// sym: ??_G?$ParamName@VCSmartPropAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CSmartPropAttachTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CSmartPropAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x649f0)
#endif


// 0x00064a10 fight::ParamNameConstList<CSmartPropUpdateAttachmentTrack>::vfunc_0 (30 B): matches/0x00064a10.cpp
// sym: ??_G?$ParamNameConstList@VCSmartPropUpdateAttachmentTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CSmartPropUpdateAttachmentTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CSmartPropUpdateAttachmentTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64a10)
#endif


// 0x00064a30 fight::ParamName<CSmartPropSpawnTrack>::vfunc_0 (30 B): matches/0x00064a30.cpp
// sym: ??_G?$ParamName@VCSmartPropSpawnTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CSmartPropSpawnTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CSmartPropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64a30)
#endif


// 0x00064a50 fight::ParamNameConstList<CSmartPropSpawnTrack>::vfunc_0 (30 B): matches/0x00064a50.cpp
// sym: ??_G?$ParamNameConstList@VCSmartPropSpawnTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CSmartPropSpawnTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CSmartPropSpawnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x64a50)
#endif

namespace fn_fa3ff49b {

// 0x00065190 FUN_00065190 (664 B): equivalent/0x00065190.cpp
// sym: _FUN_00065190 @4a75346d1e3b @w9273e856b1f9
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 26/26)
// FUN_00065190 @ 0x00065190
extern "C" void FUN_00065190()
{
    if (DAT_004dc624 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_65190<CSmartPropAttachTrack_65190>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_65190<CSmartPropAttachTrack_65190>("timeBegin", &CSmartPropAttachTrack_65190::FUN_00061cb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_65190<CSmartPropAttachTrack_65190>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_65190<CSmartPropAttachTrack_65190>("timeAttach", &CSmartPropAttachTrack_65190::FUN_00061cc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_65190<CSmartPropAttachTrack_65190>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_65190<CSmartPropAttachTrack_65190>("attachmentIndex", &CSmartPropAttachTrack_65190::FUN_00061cd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_65190<CSmartPropAttachTrack_65190>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamNameConstList_65190<CSmartPropAttachTrack_65190>("joint", &CSmartPropAttachTrack_65190::FUN_00012670);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_65190<CSmartPropAttachTrack_65190>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamNameConstList_65190<CSmartPropAttachTrack_65190>("channel", &CSmartPropAttachTrack_65190::FUN_00012680);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_65190<CSmartPropAttachTrack_65190>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_65190<CSmartPropAttachTrack_65190>("useOffset", &CSmartPropAttachTrack_65190::FUN_00061ce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_65190<CSmartPropAttachTrack_65190>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_65190<CSmartPropAttachTrack_65190>("offset", &CSmartPropAttachTrack_65190::FUN_00061cf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_65190<CSmartPropAttachTrack_65190>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_65190<CSmartPropAttachTrack_65190>("orientation", &CSmartPropAttachTrack_65190::FUN_000622d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_65190<CSmartPropAttachTrack_65190>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_65190<CSmartPropAttachTrack_65190>("minDistance", &CSmartPropAttachTrack_65190::FUN_00061d20);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_65190<CSmartPropAttachTrack_65190>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_65190<CSmartPropAttachTrack_65190>("useCharacterArray", &CSmartPropAttachTrack_65190::FUN_00061d10);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_65190<CSmartPropAttachTrack_65190>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamVector_65190<CSmartPropAttachTrack_65190>("velocityOffset", &CSmartPropAttachTrack_65190::FUN_00061d30);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_65190<CSmartPropAttachTrack_65190>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_65190<CSmartPropAttachTrack_65190>("state", &CSmartPropAttachTrack_65190::FUN_00012720);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc620), params, 12);
    }
    DAT_004dc624++;
}


// 0x00065430 FUN_00065430 (511 B): equivalent/0x00065430.cpp
// sym: _FUN_00065430 @4c80a44060b4 @wae47d26da145
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 20/20)
// FUN_00065430 @ 0x00065430
extern "C" void FUN_00065430()
{
    if (DAT_004dc62c == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSmartPropUpdateAttachmentTrack_65430>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CSmartPropUpdateAttachmentTrack_65430>("timeBegin", &CSmartPropUpdateAttachmentTrack_65430::FUN_00061d50);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSmartPropUpdateAttachmentTrack_65430>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CSmartPropUpdateAttachmentTrack_65430>("timeAttach", &CSmartPropUpdateAttachmentTrack_65430::FUN_00061d60);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<CSmartPropUpdateAttachmentTrack_65430>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamIntConstRange<CSmartPropUpdateAttachmentTrack_65430>("attachmentIndex", &CSmartPropUpdateAttachmentTrack_65430::FUN_00061d70);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<CSmartPropUpdateAttachmentTrack_65430>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamNameConstList<CSmartPropUpdateAttachmentTrack_65430>("joint", &CSmartPropUpdateAttachmentTrack_65430::FUN_00012740);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<CSmartPropUpdateAttachmentTrack_65430>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamNameConstList<CSmartPropUpdateAttachmentTrack_65430>("channel", &CSmartPropUpdateAttachmentTrack_65430::FUN_00012750);
        mem = FUN_0008d690((int)sizeof(ParamBool<CSmartPropUpdateAttachmentTrack_65430>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<CSmartPropUpdateAttachmentTrack_65430>("useOffset", &CSmartPropUpdateAttachmentTrack_65430::FUN_00061d80);
        mem = FUN_0008d690((int)sizeof(ParamVector<CSmartPropUpdateAttachmentTrack_65430>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamVector<CSmartPropUpdateAttachmentTrack_65430>("offset", &CSmartPropUpdateAttachmentTrack_65430::FUN_00061d90);
        mem = FUN_0008d690((int)sizeof(ParamVector<CSmartPropUpdateAttachmentTrack_65430>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamVector<CSmartPropUpdateAttachmentTrack_65430>("orientation", &CSmartPropUpdateAttachmentTrack_65430::FUN_00062480);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSmartPropUpdateAttachmentTrack_65430>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<CSmartPropUpdateAttachmentTrack_65430>("minDistance", &CSmartPropUpdateAttachmentTrack_65430::FUN_00061db0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc628), params, 9);
    }
    DAT_004dc62c++;
}


// 0x00065630 FUN_00065630 (562 B): equivalent/0x00065630.cpp
// sym: _FUN_00065630 @cd340a1019c4 @wccb918d9b4ee
// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 22/22)
// FUN_00065630 @ 0x00065630
extern "C" void FUN_00065630()
{
    if (DAT_004dc634 == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_65630<CSmartPropSpawnTrack_65630>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_65630<CSmartPropSpawnTrack_65630>("timeBegin", &CSmartPropSpawnTrack_65630::FUN_00061dc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_65630<CSmartPropSpawnTrack_65630>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString_65630<CSmartPropSpawnTrack_65630>("name", &CSmartPropSpawnTrack_65630::FUN_000626c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_65630<CSmartPropSpawnTrack_65630>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_65630<CSmartPropSpawnTrack_65630>("initialState", &CSmartPropSpawnTrack_65630::FUN_000127d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_65630<CSmartPropSpawnTrack_65630>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamIntConstRange_65630<CSmartPropSpawnTrack_65630>("attachmentIndex", &CSmartPropSpawnTrack_65630::FUN_00061e20);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_65630<CSmartPropSpawnTrack_65630>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamNameConstList_65630<CSmartPropSpawnTrack_65630>("joint", &CSmartPropSpawnTrack_65630::FUN_000127e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_65630<CSmartPropSpawnTrack_65630>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamNameConstList_65630<CSmartPropSpawnTrack_65630>("channel", &CSmartPropSpawnTrack_65630::FUN_000127f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_65630<CSmartPropSpawnTrack_65630>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_65630<CSmartPropSpawnTrack_65630>("useOffset", &CSmartPropSpawnTrack_65630::FUN_00061dd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_65630<CSmartPropSpawnTrack_65630>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_65630<CSmartPropSpawnTrack_65630>("offset", &CSmartPropSpawnTrack_65630::FUN_00061de0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_65630<CSmartPropSpawnTrack_65630>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_65630<CSmartPropSpawnTrack_65630>("orientation", &CSmartPropSpawnTrack_65630::FUN_00062680);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_65630<CSmartPropSpawnTrack_65630>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_65630<CSmartPropSpawnTrack_65630>("minDistance", &CSmartPropSpawnTrack_65630::FUN_00061e10);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc630), params, 10);
    }
    DAT_004dc634++;
}


// 0x00065870 FUN_00065870 (25 B): matches/0x00065870.cpp
// sym: _FUN_00065870
extern "C" int __cdecl FUN_00065870(Obj_65870* object, int value) {
    return object->Check_0022d2b0(value, 0x3727c5ac) == 0;
}


// 0x000658d0 FUN_000658d0 (103 B): matches/0x000658d0.cpp
// sym: _FUN_000658d0
extern "C" int FUN_000658d0(float* a, float* b, float* c, float* out) {
    float v = (a[1] * c[0] - a[0] * c[1]) + (b[0] * c[1] - b[1] * c[0]) + (b[1] * a[0] - b[0] * a[1]);  // the listing's order (MSVC 7.1 reassociates; clang does not)
    *out = v;
    if (v > DAT_003f342c)    // (dg1) the game's constants 5 / -5, not local copies
        return -1;
    if (v < DAT_003fb864)
        return 1;
    return 0;
}


// 0x00065a90 FUN_00065a90 (7 B): matches/0x00065a90.cpp
// sym: ?FUN_00065a90@fn_fa3ff49b@@YIEPAUObj_65a90@1@@Z
unsigned char __fastcall FUN_00065a90(Obj_65a90* self) {
    return self->value;
}

} // namespace fn_fa3ff49b

// 0x00065aa0 FUN_00065aa0 (8 B): matches/0x00065aa0.cpp
// sym: ?FUN_00065aa0@Target_65aa0@owners@@QAEXXZ
void owners::Target_65aa0::FUN_00065aa0() {
    field = 0;
}


// 0x00065ab0 FUN_00065ab0 (7 B): matches/0x00065ab0.cpp
// sym: ?FUN_00065ab0@C_65ab0@owners@@QAEEXZ
unsigned char owners::C_65ab0::FUN_00065ab0() {
    return value;
}

namespace fn_fa3ff49b {

// 0x00065ac0 FUN_00065ac0 (53 B): matches/0x00065ac0.cpp
// sym: ?Target@Obj_65ac0@fn_fa3ff49b@@QAEXXZ
void Obj_65ac0::Target() {
    if (mActive) {
        float now = mClock->Get_00086080();
        if (mDeadline <= now) {
            mActive = 0;
            mDeadline = 0.0f;
        }
    }
}


// 0x00065b20 FUN_00065b20 (84 B): matches/0x00065b20.cpp
// sym: ?Run@Obj@fn_fa3ff49b@@QAEXXZ
// data: gZero = DAT_003f32e0
void Obj::Run() {
    if (active) {
        if (!ptr) {
            ptr = hulk_at_004dd700->item;
            if (!ptr)
                return;
        }
        if (active->check_00086080() == DAT_003f32e0) {
            a = 0;
            b = 0;
            c = 0;
            d = 0;
            e = 0;
        }
    }
}


// 0x00065b80 FUN_00065b80 (133 B): matches/0x00065b80.cpp
// sym: ?Tick@Obj_65b80@fn_fa3ff49b@@QAEXH@Z
void Obj_65b80::Tick(int a) {
    if (!mClock)
        return;
    if (mType == 0) {
        int v = *(int*)((char*)g_game_65b80 + 0x2c);
        mType = v;
        if (!v)
            return;
    }
    if (mClock->Now_00086080() >= mNext) {
        EntList_65b80* l = g_game_65b80->list;
        int n = l->count;
        for (int i = 0; i < n; i++) {
            Entity* e = g_game_65b80->list->Get_00024190(i);
            if (e && e->active)
                e->Update_000403f0();
        }
        mNext = mClock->Now_00086080() + mInterval;
    }
}


// 0x00065c10 FUN_00065c10 (56 B): matches/0x00065c10.cpp
// sym: ?Target@fn_fa3ff49b@@YAXXZ
void __cdecl Target() {
    int n = gRoot_65c10->manager->count;
    for (int i = 0; i < n; ++i) {
        void* p = gRoot_65c10->manager->GetItem_00024190(i);
        if (p)
            *(int*)((char*)p + 0x214c) = 0;
    }
}


// 0x00065c50 FUN_00065c50 (82 B): matches/0x00065c50.cpp
// sym: ?Target@fn_fa3ff49b@@YIHPAVOwner_65c50@1@@Z
hulk_intptr __fastcall Target(Owner_65c50* self) {
    int i = 0;
    hulk_intptr result = 0;
    if (self->count > 0) {
        Owner_65c50::Entry* e = self->entries;
        do {
            Finder_65c50* f = gManager_65c50->finder;
            result = f->Find_00024280(e->a, e->b);
            if (*(char*)((char*)result + 0x1b84) != 0)
                return result;
            ++i;
            ++e;
        } while (i < self->count);
    }
    return 0;
}


// 0x00065cb0 FUN_00065cb0 (96 B): matches/0x00065cb0.cpp
// sym: ?Add@Obj_65cb0@fn_fa3ff49b@@QAEXPDUPair_65cb0@2@@Z
void Obj_65cb0::Add(const volatile Pair_65cb0* p) {
    int n = count;
    int i = 0;
    if (n > 0) {
        volatile Pair_65cb0* e = entries;
        do {
            if (e->a == p->a && e->b == p->b)
                return;
            ++i;
            ++e;
        } while (i < *(volatile int*)&count);
    }
    if (n < 40) {
        entries[n].a = p->a;
        entries[n].b = p->b;
        ++count;
    }
}


// 0x00065d10 FUN_00065d10 (125 B): equivalent/0x00065d10.cpp
// sym: ?FUN_00065d10@KeySet_65d10@fn_fa3ff49b@@QAEXPBUKey_65d10@2@@Z @45e40018412a @w1351dda46c1d
// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 12/12)
// FUN_00065d10 @ 0x00065d10
// Removes the first entry equal to *key, shifting the rest down.
void KeySet_65d10::FUN_00065d10(const Key_65d10* key)
{
    if (count <= 0)
        return;
    int lo = key->lo;
    int hi = key->hi;
    int i = 0;
    while (keys[i].lo != lo || keys[i].hi != hi) {
        i++;
        if (i >= count)
            return;
    }
    for (i++; i < count; i++)
        keys[i - 1] = keys[i];
    count--;
}


// 0x00065dd0 FUN_00065dd0 (80 B): equivalent/0x00065dd0.cpp
// sym: ?FUN_00065dd0@List@fn_fa3ff49b@@QAEXPBUPair@2@@Z @63bfd3e4040b @w3108aa2cd5f4
// STATUS: equivalent (tools/equiv.py level 3: 1548 inputs, branch coverage 10/10)
// FUN_00065dd0 @ 0x00065dd0
void List::FUN_00065dd0(const Pair* item) {
    int originalCount = count;
    for (int i = 0; i < originalCount; ++i) {
        if (entries[i].first == item->first && entries[i].second == item->second)
            return;
        if (i + 1 >= count)
            break;
    }
    if (originalCount < 40) {
        entries[originalCount].first = item->first;
        entries[originalCount].second = item->second;
        ++count;
    }
}


// 0x00065e20 FUN_00065e20 (125 B): equivalent/0x00065e20.cpp
// sym: ?FUN_00065e20@KeySet_65e20@fn_fa3ff49b@@QAEXPBUKey_65e20@2@@Z @877e7f97e954 @wad55ab09b12d
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 12/12)
// FUN_00065e20 @ 0x00065e20
// Removes the first entry equal to *key, shifting the rest down.
void KeySet_65e20::FUN_00065e20(const Key_65e20* key)
{
    if (count <= 0)
        return;
    int lo = key->lo;
    int hi = key->hi;
    int i = 0;
    while (keys[i].lo != lo || keys[i].hi != hi) {
        i++;
        if (i >= count)
            return;
    }
    for (i++; i < count; i++)
        keys[i - 1] = keys[i];
    count--;
}


// 0x00065ee0 FUN_00065ee0 (119 B): matches/0x00065ee0.cpp
// sym: ?FUN_00065ee0@PairList@fn_fa3ff49b@@QAEXPBUPair_65ee0@2@@Z
// FUN_00065ee0 @ 0x00065ee0
// Removes every entry equal to key.
void PairList::FUN_00065ee0(const Pair_65ee0* key) {
    for (int i = 0; i < count; i++) {
        if (key->a == entries[i].a && key->b == entries[i].b) {
            for (int j = i + 1; j < count; j++)
                entries[j - 1] = entries[j];
            count--;
        }
    }
}

} // namespace fn_fa3ff49b

// 0x00065f60 FUN_00065f60 (7 B): matches/0x00065f60.cpp
// sym: ?FUN_00065f60@C_65f60@owners@@QAEIXZ
unsigned int owners::C_65f60::FUN_00065f60() {
    return value;
}

namespace fn_fa3ff49b {

// 0x00065fb0 FUN_00065fb0 (20 B): matches/0x00065fb0.cpp
// sym: ?f@A_65fb0@fn_fa3ff49b@@QAEPAU12@XZ
A_65fb0* A_65fb0::f() {
    x = y->FUN_00230800(x);
    return this;
}


// 0x00066020 FUN_00066020 (20 B): matches/0x00066020.cpp
// sym: ?f@A_66020@fn_fa3ff49b@@QAEPAU12@XZ
// Same code shape as 0x00065fb0 (propagated; names are from that function)
A_66020* A_66020::f() {
    x = y->FUN_00230800(x);
    return this;
}


// 0x00066060 FUN_00066060 (3 B): matches/0x00066060.cpp
// sym: ?Get@Obj_66060@fn_fa3ff49b@@QAEPAV12@XZ
Obj_66060* Obj_66060::Get() {
    return this;
}


// 0x000660a0 FUN_000660a0 (3 B): matches/0x000660a0.cpp
// sym: ?Get@Obj_660a0@fn_fa3ff49b@@QAEPAV12@XZ
Obj_660a0* Obj_660a0::Get() {
    return this;
}


// 0x000661f0 FUN_000661f0 (55 B): matches/0x000661f0.cpp
// sym: ?update@Obj@fn_fa3ff49b@@QAEXXZ
void Obj::update() {
    if (active) {
        if (!item)
            item = gProvider->item;
        if (item) {
            float x = active->compute_00086080();
            flag = 1;
            result = x + offset;
        }
    }
}


// 0x00066230 FUN_00066230 (73 B): matches/0x00066230.cpp
// sym: ?check@Foo@fn_fa3ff49b@@QAEDPAVObj@2@@Z
char Foo::check(Obj* o) {
    if (q && (p || (p = gMgr->ptr)) && o) {
        *(float*)&o = o->value;
        return q->Calc_00086080() >= *(float*)&o;
    }
    return 0;
}

} // namespace fn_fa3ff49b

// 0x00066280 FUN_00066280 (41 B): matches/0x00066280.cpp
// sym: ?FUN_00066280@Obj_66280@owners@@QAEMXZ
float owners::Obj_66280::FUN_00066280() {
    if (!enabled)
        return DAT_003f3388;
    if (!cached) {
        cached = DAT_004dd700->value;
        if (!cached)
            return DAT_003f3388;
    }
    return Run_00086080(enabled);
}


// 0x000662b0 FUN_000662b0 (220 B): equivalent/0x000662b0.cpp [wrapped: conflict: Entity; World]
// sym: ?FUN_000662b0@Object@fn_000662b0@@QAE_NXZ @3a23f1b23330 @w64efe9119dcd
namespace fn_000662b0 {
// STATUS: equivalent (tools/equiv.py level 3: 376 inputs, branch coverage 14/14)
// FUN_000662b0 @ 0x000662b0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Entity { char pad[0x1b0c]; float value; char pad2[0x94]; unsigned char active; };
struct Manager_662b0 { Entity* FUN_00024280(unsigned int a, unsigned int b); };
struct World { char pad[0x20]; Manager_662b0* manager; };
struct Entry_662b0 { unsigned int a,b; };
struct Object { char pad[0x170]; Entry_662b0 entries[40]; int count; bool FUN_000662b0(); };
bool Object::FUN_000662b0() {
 for (int i=0; i<count; ++i) {
  Entity* e=DAT_004dd700->manager->FUN_00024280(entries[i].a,entries[i].b);
  if(e && !(e->value < 0.0f)) {
   if(e->active) return true;
  } else {
   for(int j=i+1;j<count;++j) { entries[j-1].a=entries[j].a; entries[j-1].b=entries[j].b; }
   --count; --i;
  }
 }
 return false;
}
} // namespace fn_000662b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00066390 FUN_00066390 (404 B): equivalent/0x00066390.cpp [wrapped: conflict: World]
// sym: ?FUN_00066390@Tracker_66390@fn_00066390@@QAEPAUTarget_66390@2@PAUVec3_66390@2@@Z @9c57500cbbed @w6262578cb645
namespace fn_00066390 {
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 18/18)
// FUN_00066390 @ 0x00066390
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_66390 {
    float x, y, z;
    float FUN_0022d110();
};

struct Transform_66390 {
    void FUN_00059a50(Vec3_66390 *out);
};

struct Target_66390 {
    char pad0[0x10];
    Transform_66390 *transform;
    char pad1[0x1b0c - 0x14];
    float score;
    char pad2[0x1ba4 - 0x1b10];
    char locked;
};

struct TargetTable_66390 {
    Target_66390 *FUN_00024280(int a, int b);
};

struct World {
    char pad0[0x20];
    TargetTable_66390 *targets;
};


struct Key_66390 {
    int a, b;
};

struct Clock_66390 {
    float FUN_00086080();
};

class Tracker_66390 {
public:
    Target_66390 *FUN_00066390(Vec3_66390 *pos);

    char pad0[4];
    Clock_66390 *clock;
    char pad1[0x154 - 8];
    Vec3_66390 origin;
    char pad2[0x170 - 0x160];
    Key_66390 keys[40];
    int count;
    char pad4[0x354 - 0x2b4];
    float result;
};

Target_66390 *Tracker_66390::FUN_00066390(Vec3_66390 *pos)
{
    origin = *pos;
    Target_66390 *best = 0;
    float bestDist = 0.0f;
    for (int i = 0; i < count; i++) {
        Target_66390 *t = DAT_004dd700->targets->FUN_00024280(keys[i].a, keys[i].b);
        Vec3_66390 p;
        t->transform->FUN_00059a50(&p);
        if (t->score < 0.0f) {
            for (int j = i + 1; j < count; j++)
                keys[j - 1] = keys[j];
            count--;
            i--;
        } else {
            Vec3_66390 d;
            d.x = p.x - origin.x;
            d.y = p.y - origin.y;
            d.z = p.z - origin.z;
            float dist = d.FUN_0022d110();
            if (best == 0 || dist < bestDist) {
                bestDist = dist;
                best = t;
            }
        }
    }
    if (best != 0 && !best->locked)
        result = clock->FUN_00086080();
    return best;
}
} // namespace fn_00066390
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00066530 FUN_00066530 (175 B): equivalent/0x00066530.cpp [wrapped: conflict: Entity; World]
// sym: ?update@Owner_66530@fn_00066530@@QAEXXZ @11e28064a937 @wd9d1998c643b
namespace fn_00066530 {
// STATUS: equivalent (tools/equiv.py level 3: 687 inputs, branch coverage 14/14)
// FUN_00066530 @ 0x00066530
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct ValueSource {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual float slot21();
};
struct Link2_66530 { char pad[0x70]; ValueSource* source; };
struct Link1_66530 { char pad[0x10]; Link2_66530* next; };
struct Entity { char pad0[0xa0]; Link1_66530* link; char pad1[0x114-0xa4]; int state; char pad2[0x1a0-0x118]; unsigned char active; char pad3[0x1ed-0x1a1]; unsigned char flagged; };
struct Manager_66530 { Entity* FUN_001dee40(int, int); };
struct World { char pad[12]; Manager_66530* manager; };
struct Entry_66530 { int first; int second; };
struct Owner_66530 { char pad[0x390]; int count; int unknown; Entry_66530 entries[1]; void FUN_00065ee0(Entry_66530*); void update(); };
void Owner_66530::update() {
 for (int i=0; i<count; ++i) {
  Entry_66530* entry=&entries[i];
  Entity* entity=DAT_004dd700->manager->FUN_001dee40(entry->first,entry->second);
  if (entity) {
   if (entity->link->next->source->slot21() == 0.0f) FUN_00065ee0(entry);
   if (entity->flagged) FUN_00065ee0(entry);
   if (!entity->active) FUN_00065ee0(entry);
   if (entity->state) FUN_00065ee0(entry);
  }
 }
}
} // namespace fn_00066530
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000665e0 FUN_000665e0 (632 B): equivalent/0x000665e0.cpp [wrapped: conflict: World]
// sym: ?FUN_000665e0@Squad@fn_000665e0@@QAE_NPAUPair_665e0@2@PAUSource_665e0@2@@Z @501f12a1101b @wf90729727636
namespace fn_000665e0 {
// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 43/46, incomplete)
// FUN_000665e0 @ 0x000665e0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct V3_665e0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

class Gauge_665e0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual float Value();
};

struct Level1_665e0 {
    char pad[0x70];
    Gauge_665e0 *gauge;
};

struct Level2_665e0 {
    char pad[0x10];
    Level1_665e0 *next;
};

class Unit_665e0 {
public:
    char pad0[0xa0];
    Level2_665e0 *state;
    char pad4[0x114 - 0xa4];
    int blocked;
    char pad118[0x1a0 - 0x118];
    bool alive;
    char pad1a1[0x1ed - 0x1a1];
    bool immune;

    bool FUN_001d7300();
    V3_665e0 *FUN_001d6b40();
};

struct Roster_665e0 {
    Unit_665e0 *FUN_001dee40(int lo, int hi);
};

struct World {
    char pad0[0xc];
    Roster_665e0 *roster;
};

struct Pair_665e0 {
    int lo;
    int hi;
};

struct Source_665e0 {
    char pad0[0x10];
    struct Ref_665e0 *ref;
};

struct Ref_665e0 {
    void FUN_00059a50(V3_665e0 *out);
};


class Squad {
public:
    char pad0[0x390];
    int count;
    char pad394[4];
    Pair_665e0 pairs[1];

    void FUN_00066530();
    bool FUN_000665e0(Pair_665e0 *out, Source_665e0 *from);
};

bool Squad::FUN_000665e0(Pair_665e0 *out, Source_665e0 *from)
{
    bool found = false;
    bool cleanup = false;
    int i = 0;
    if (from == 0) {
        if (count <= 0)
            return found;
        Pair_665e0 *p = pairs;
        do {
            if (found)
                break;
            Unit_665e0 *u = DAT_004dd700->roster->FUN_001dee40(p->lo, p->hi);
            if (u != 0 && u->alive && u->FUN_001d7300() && u->state->next->gauge->Value() != 0.0f &&
                !u->immune && u->alive && u->blocked == 0) {
                out->lo = p->lo;
                out->hi = p->hi;
                found = true;
            } else {
                cleanup = true;
            }
            i++;
            p++;
        } while (i < count);
    } else {
        int best = -1;
        float bestDist = -1.0f;
        V3_665e0 pos;
        from->ref->FUN_00059a50(&pos);
        if (count > 0) {
            Pair_665e0 *p = pairs;
            do {
                V3_665e0 d;
                d.z = 0;
                d.y = 0;
                d.x = 0;
                Unit_665e0 *u = DAT_004dd700->roster->FUN_001dee40(p->lo, p->hi);
                if (u != 0 && u->alive && u->FUN_001d7300() && u->state->next->gauge->Value() != 0.0f &&
                    !u->immune && u->alive && u->blocked == 0) {
                    V3_665e0 *at = u->FUN_001d6b40();
                    d.x = at->x;
                    d.y = at->y;
                    d.x = d.x - pos.x;
                    found = true;
                    d.y = d.y - pos.y;
                    d.z = at->z - pos.z;
                    float len = d.FUN_0022d110();
                    if (bestDist < 0.0f || len < bestDist) {
                        bestDist = len;
                        best = i;
                    }
                } else {
                    cleanup = true;
                }
                i++;
                p++;
            } while (i < count);
        }
        out->lo = pairs[best].lo;
        out->hi = pairs[best].hi;
    }
    if (cleanup)
        FUN_00066530();
    return found;
}
} // namespace fn_000665e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fa3ff49b {

// 0x00066860 FUN_00066860 (14 B): matches/0x00066860.cpp
// sym: ?Run@Target_66860@fn_fa3ff49b@@QAEPAU12@H@Z
Target_66860* Target_66860::Run(int x) {
    ((owners::X_230b60 *)(((ThisCall_00230b60*)(this))))->FUN_00230b60();
    return this;
}


// 0x00066870 FUN_00066870 (14 B): matches/0x00066870.cpp
// sym: ?Run@Target_66870@fn_fa3ff49b@@QAEPAU12@H@Z
// Same code shape as 0x00066860 (propagated; names are from that function)
Target_66870* Target_66870::Run(int x) {
    ((owners::X_230b60 *)(((ThisCall_00230b60*)(this))))->FUN_00230b60();
    return this;
}


// 0x000668c0 FUN_000668c0 (49 B): equivalent/0x000668c0.cpp
// sym: ?FUN_000668c0@fn_fa3ff49b@@YAHPBUItem@1@0@Z @cc5ceee3e4a4 @w3751967ebcb4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000668c0 @ 0x000668c0
int __cdecl FUN_000668c0(const Item *a, const Item *b)
{
    if (a->value < b->value) return -1;
    if (b->value < a->value) return 1;
    return 0;
}


// 0x00066900 FUN_00066900 (47 B): matches/0x00066900.cpp
// sym: ?FUN_00066900@fn_fa3ff49b@@YAHPBUItem@1@PBUOther@1@@Z
int __cdecl FUN_00066900(const Item* a, const Other* b) {
    if (a->x < b->x)
        return -1;
    if (b->x < a->x)
        return 1;
    return 0;
}


// 0x00066930 FUN_00066930 (16 B): matches/0x00066930.cpp
// sym: ?FUN_00066930@fn_fa3ff49b@@YADH@Z
char __cdecl FUN_00066930(int a) {
    thunk_FUN_00267090(a);
    return 1;
}


// 0x00066940 FUN_00066940 (57 B): equivalent/0x00066940.cpp
// sym: ?FUN_00066940@fn_fa3ff49b@@YAHPBUValue@1@0@Z @541449e0c351 @wa708dbe4a486
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// FUN_00066940 @ 0x00066940
int __cdecl FUN_00066940(const Value* a, const Value* b) { if (a->high < b->high || (a->high == b->high && a->low < b->low)) return -1; if (b->high < a->high || (b->high == a->high && b->low < a->low)) return 1; return 0; }


// 0x00066980 FUN_00066980 (56 B): matches/0x00066980.cpp
// sym: ?FUN_00066980@fn_fa3ff49b@@YAHPB_KPBVObj@1@@Z
int __cdecl FUN_00066980(const unsigned __int64* a, const Obj* b) {
    const unsigned __int64* p = &b->val;
    if (*a < *p)
        return -1;
    if (*p < *a)
        return 1;
    return 0;
}

} // namespace fn_fa3ff49b

// 0x00066a00 FUN_00066a00 (16 B): matches/0x00066a00.cpp [wrapped: conflict: thunk_FUN_00267090]
// sym: ?FUN_00066a00@fn_00066a00@@YA_NH@Z
namespace fn_00066a00 {
extern "C++" __declspec(nothrow) void __cdecl thunk_FUN_00267090(int);
bool __cdecl FUN_00066a00(int a) {
    thunk_FUN_00267090(a);
    return true;
}
} // namespace fn_00066a00

namespace fn_fa3ff49b {

// 0x00066a10 FUN_00066a10 (54 B): matches/0x00066a10.cpp
// sym: ?Add@Obj_66a10@fn_fa3ff49b@@QAEXPBH@Z
void Obj_66a10::Add(const int* p) {
    Base_00066530();
    int i = count;
    if (i < 0x96) {
        entries[i].a = p[0];
        entries[i].b = p[1];
        ++count;
    }
}


// 0x00066a50 FUN_00066a50 (23 B): matches/0x00066a50.cpp
// sym: ?target@fn_fa3ff49b@@YIPAIPAUObj_66a50@1@PAXPAI@Z
u32_66a50* __fastcall target(Obj_66a50* self, void*, u32_66a50* out) {
    u32_66a50 v = FUN_00230ea0(self);
    out[0] = v;
    out[1] = (hulk_uintptr)self;
    return out;
}


// 0x00066a90 FUN_00066a90 (115 B): equivalent/0x00066a90.cpp
// sym: ?FUN_00066a90@Owner_66a90@fn_fa3ff49b@@QAEXPAUResult_66a90@2@PBUKey_66a90@2@@Z @fe27a32aa7d4 @w1e7d263e8fcd
// STATUS: equivalent (tools/equiv.py level 3: 19961 inputs, branch coverage 4/4)
// FUN_00066a90 @ 0x00066a90
void Owner_66a90::FUN_00066a90(Result_66a90 *out, const Key_66a90 *key)
{
    void *found = FUN_00230be0(FUN_00066900, key);
    if (found == 0) {
        out->node = 0;
        out->owner = 0;
        return;
    }
    Node *node = (Node *)FUN_0008d6d0((int)sizeof(Node));
    if (node)
        node->key = *key;
    FUN_00230c30(node, FUN_000668c0, found);
    out->owner = this;
    out->node = node;
}


// 0x00066b20 FUN_00066b20 (23 B): matches/0x00066b20.cpp
// sym: ?target@fn_fa3ff49b@@YIPAIPAUObj_66b20@1@PAXPAI@Z
// Same code shape as 0x00066a50 (propagated; names are from that function)
u32_66b20* __fastcall target(Obj_66b20* self, void*, u32_66b20* out) {
    u32_66b20 v = FUN_00230ea0(self);
    out[0] = v;
    out[1] = (hulk_uintptr)self;
    return out;
}

} // namespace fn_fa3ff49b

// 0x00066b60 FUN_00066b60 (115 B): equivalent/0x00066b60.cpp [wrapped: conflict: Node]
// sym: ?FUN_00066b60@Owner_66b60@fn_00066b60@@QAEXPAUResult_66b60@2@PBUKey_66b60@2@@Z @4655cd0f04c5 @w59a09f8c6685
namespace fn_00066b60 {
// STATUS: equivalent (tools/equiv.py level 3: 19961 inputs, branch coverage 4/4)
// FUN_00066b60 @ 0x00066b60
void FUN_00066980();
void FUN_00066940();
extern "C" void *FUN_0008d6d0(unsigned int size);

struct Key_66b60 {
    int w[4];
};
struct Node {
    char pad0[0x10];
    Key_66b60 key;
};
struct Result_66b60 {
    Node *node;
    void *owner;
};

struct Owner_66b60 {
    void FUN_00230c30(Node *node, void (*notify)(), void *found);
    void FUN_00066b60(Result_66b60 *out, const Key_66b60 *key);
    void *FUN_00230be0(void (*match)(), const Key_66b60 *key);
};

void Owner_66b60::FUN_00066b60(Result_66b60 *out, const Key_66b60 *key)
{
    void *found = FUN_00230be0(FUN_00066980, key);
    if (found == 0) {
        out->node = 0;
        out->owner = 0;
        return;
    }
    Node *node = (Node *)FUN_0008d6d0((int)sizeof(Node));
    if (node)
        node->key = *key;
    FUN_00230c30(node, FUN_00066940, found);
    out->owner = this;
    out->node = node;
}
} // namespace fn_00066b60


// 0x00066c20 FUN_00066c20 (303 B): equivalent/0x00066c20.cpp [wrapped: conflict: World]
// sym: ?FUN_00066c20@Owner_66c20@fn_00066c20@@QAEXH@Z @3d14cb1f257d @wf6027f946513
namespace fn_00066c20 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00066c20 @ 0x00066c20
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct World {
    char pad0[0x2c];
    int field_2c;
    char pad30[0x58 - 0x30];
    int field_58;
};

struct Pair_66c20 {
    int a;
    int b;
};

struct Key_66c20 {
    int a;
    int b;
    int c;
};

struct Table_66c20 {
    void FUN_00066b60(Pair_66c20 *out, Key_66c20 *key);
};


struct Owner_66c20 {
    int field_00;
    int field_04;
    char pad08[0x2f4 - 8];
    Table_66c20 table;
    void FUN_00066c20(hulk_intptr unused);
};

void Owner_66c20::FUN_00066c20(hulk_intptr unused)
{
    Pair_66c20 out;
    Key_66c20 key;

    field_00 = DAT_004dd700->field_2c;
    field_04 = DAT_004dd700->field_58;

    key.a = DAT_004dced0; key.b = DAT_004dced4; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dcef8; key.b = DAT_004dcefc; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dced8; key.b = DAT_004dcedc; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dcec8; key.b = DAT_004dcecc; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dcef0; key.b = DAT_004dcef4; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dcee8; key.b = DAT_004dceec; key.c = 0;
    table.FUN_00066b60(&out, &key);
}
} // namespace fn_00066c20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00066d50 FUN_00066d50 (834 B): equivalent/0x00066d50.cpp [wrapped: conflict: World]
// sym: ?FUN_00066d50@Tracker_66d50@fn_00066d50@@QAEXXZ @7fa4bc26b0bb @w7d88f126edf2
namespace fn_00066d50 {
// STATUS: equivalent (tools/equiv.py level 3: 218 inputs, branch coverage 36/36)
// FUN_00066d50 @ 0x00066d50
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_66d50 {
    float x, y, z;
    float FUN_0022d110();
};

struct Anchor_66d50 {
    void FUN_00059a50(Vec3_66d50* out);
};

struct Entity {
    char pad00[0x10];
    Anchor_66d50* anchor;
    char pad14[0x1b0c - 0x14];
    float f1b0c;
    char pad1b10[0x1b38 - 0x1b10];
    int f1b38;
    char pad1b3c[4];
    int f1b40;
    int f1b44;
};

struct Registry_66d50 {
    Entity* FUN_00024280(unsigned int lo, unsigned int hi);
};

struct World {
    char pad00[0x20];
    Registry_66d50* registry;
};


struct Handle_66d50 {
    int a, b;
};

struct Query_66d50 {
    int out;
    int pad;
    unsigned int lo;
    unsigned int hi;
};

struct Sub_66d50 {
    void FUN_00230f50(void (*fn)(), Sub_66d50* self);
    void FUN_00066a90(Handle_66d50* h, Query_66d50* q);
};

struct Id_66d50 {
    unsigned int lo;
    unsigned int hi;
};

void FUN_00066930();
extern "C++" __declspec(nothrow) int __cdecl FUN_000658d0(float *, float *, float *, float *);

class Tracker_66d50 {
public:
    char pad00[0x10];
    Id_66d50 ids[1];
    char pad18[0x150 - 0x18];
    int count;
    Vec3_66d50 center;
    Vec3_66d50 v160;
    char pad16c[0x2d8 - 0x16c];
    Sub_66d50 sub;
    char pad2dc[0x370 - 0x2dc];
    float f370;
    float f374;
    void FUN_00066d50();
};

void Tracker_66d50::FUN_00066d50()
{
    struct Frame {
        int out;
        Handle_66d50 h;
        Vec3_66d50 pos;
        Vec3_66d50 w;
        Query_66d50 q;
    } f;
    f.w.x = 0.0f;
    f.w.y = 0.0f;
    f.w.z = 0.0f;
    sub.FUN_00230f50(FUN_00066930, &sub);
    Entity* best = 0;
    float bestDist = 0.0f;
    if (count <= 0)
        return;
    int i;
    for (i = 0; i < count; i++) {
        Entity* e = DAT_004dd700->registry->FUN_00024280(ids[i].lo, ids[i].hi);
        if (e != 0 && !(e->f1b0c < 0.0f)) {
            e->anchor->FUN_00059a50(&f.pos);
            f.pos.x = f.pos.x - center.x;
            f.pos.y = 0.0f;
            f.pos.z = f.pos.z - center.z;
            float dist = f.pos.FUN_0022d110();
            if (best == 0 || dist < bestDist) {
                bestDist = dist;
                best = e;
            }
        } else {
            for (int k = i + 1; k < count; k++) {
                ids[k - 1].lo = ids[k].lo;
                ids[k - 1].hi = ids[k].hi;
            }
            count = count - 1;
            i--;
        }
    }
    if (best == 0)
        return;
    best->anchor->FUN_00059a50(&v160);
    if (count <= 0)
        return;
    for (i = 0; i < count; i++) {
        Entity* e = DAT_004dd700->registry->FUN_00024280(ids[i].lo, ids[i].hi);
        e->anchor->FUN_00059a50(&f.w);
        if (!(e->f1b0c < 0.0f)) {
            f.pos.x = f.w.x;
            f.pos.z = f.w.z;
            f.pos.y = f.w.y;
            f.pos.x = f.pos.x - center.x;
            f.pos.y = 0.0f;
            f.pos.z = f.pos.z - center.z;
            float dist = f.pos.FUN_0022d110();
            if (dist < f374 && dist > f370 && (e->f1b40 | e->f1b44) != 0) {
                FUN_000658d0((float *)(Vec3_66d50 *)(&f.w), (float *)(Vec3_66d50 *)(&center), (float *)(Vec3_66d50 *)(&v160), (float *)(int *)(&f.out));
                f.q.out = f.out;
                f.q.lo = ids[i].lo;
                f.q.hi = ids[i].hi;
                sub.FUN_00066a90(&f.h, &f.q);
                if (e == best)
                    e->f1b38 = 0;
                else
                    e->f1b38 = f.out;
            }
        } else {
            for (int k = i + 1; k < count; k++) {
                ids[k - 1].lo = ids[k].lo;
                ids[k - 1].hi = ids[k].hi;
            }
            count = count - 1;
            i--;
        }
    }
}
} // namespace fn_00066d50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fa3ff49b {

// 0x000670a0 FUN_000670a0 (61 B): matches/0x000670a0.cpp
// sym: ?Target@fn_fa3ff49b@@YIXPAUS_670a0@1@PAXPAIH@Z
void __fastcall Target(S_670a0* self, void*, u32_670a0* param, int value) {
    Inner_670a0* p = (Inner_670a0*)((char*)self + 0x2f4);
    int* result = (int*)p->Find_00230ba0((void*)((hulk_intptr)(void (__cdecl*)())&FUN_00066980), param);
    if (result) {
        *(u32_670a0*)((char*)self + 0x380) = param[0];
        *(u32_670a0*)((char*)self + 0x384) = param[1];
        *(float*)((char*)result + 0x18) += (float)value;
    }
}

} // namespace fn_fa3ff49b

// 0x000670e0 FUN_000670e0 (40 B): matches/0x000670e0.cpp
// sym: ?FUN_000670e0@C_670e0@owners@@QAEMI@Z
// data: gZero_670e0 = DAT_003f32e0
float owners::C_670e0::FUN_000670e0(hulk_uintptr x) {
    H* h = (H*)((char*)this + 0x2f4);
    void* p = h->lookup_00230ba0(((hulk_intptr)(void (__cdecl*)())&FUN_00066980), ((unsigned int)x));
    if (!p)
        return DAT_003f32e0;
    return *(float*)((char*)p + 0x18);
}

namespace fn_fa3ff49b {

// 0x00067110 FUN_00067110 (108 B): equivalent/0x00067110.cpp
// sym: ?FUN_00067110@Target_67110@fn_fa3ff49b@@QAEMH@Z @56d3659ab17c @w00f4b48c9050
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 4/4)
// FUN_00067110 @ 0x00067110
hulk_freg Target_67110::FUN_00067110(int key)
{
    Rec_67110 *r = sub.FUN_00230ba0(FUN_00066980, key);
    if (r == 0)
        return 0.0f;
    hulk_freg t = inner->FUN_00086080() - (f34c - f378);
    if (t == 0.0f)
        return 0.0f;
    return r->v18 / (t * 30.0f);
}

} // namespace fn_fa3ff49b

// 0x000671b0 FUN_000671b0 (128 B): equivalent/0x000671b0.cpp [wrapped: conflict: World]
// sym: ?FUN_000671b0@Tracker_671b0@fn_000671b0@@QAEXPBUVec3_671b0@2@@Z @9ccdf5681e23 @wb196925139c5
namespace fn_000671b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000671b0 @ 0x000671b0
// 0x000671b0: record a target position and re-arm the timer once the cooldown has passed or it moved
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_671b0 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_671b0* other, float eps);
};

struct Clock_671b0 {
    float FUN_00086080();
};

struct World {
    char pad[0x2c];
    int link;
};

class Tracker_671b0 {
public:
    int link;
    Clock_671b0* clock;
    char pad08[0x14c];
    Vec3_671b0 pos;
    char pad160[0x1e8];
    float next_time;
    char pad34c[4];
    float interval;
    void FUN_00066d50();
    void FUN_000671b0(const Vec3_671b0* target);
};

void Tracker_671b0::FUN_000671b0(const Vec3_671b0* target)
{
    if (clock == 0)
        return;
    if (link == 0) {
        link = DAT_004dd700->link;
        if (link == 0)
            return;
    }
    pos.x = target->x;
    pos.y = target->y;
    pos.z = target->z;
    if (clock->FUN_00086080() >= next_time || !((Vec3_671b0*)target)->FUN_0022d2b0(&pos, 1e-05f)) {
        FUN_00066d50();
        next_time = clock->FUN_00086080() + interval;
    }
}
} // namespace fn_000671b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00067230 FUN_00067230 (607 B): equivalent/0x00067230.cpp [wrapped: conflict: World]
// sym: ?FUN_00067230@Tracker_67230@fn_00067230@@QAE_NPAUTarget_67230@2@@Z @30ad8eb5a9b2 @w1eaf6b91ce33
namespace fn_00067230 {
// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 24/24)
// FUN_00067230 @ 0x00067230
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_67230 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Transform_67230 {
    void FUN_00059a50(Vec3_67230 *out);
};

struct Target_67230 {
    char pad0[0x10];
    Transform_67230 *transform;
    char pad1[0x1b0c - 0x14];
    float score;
    char pad2[0x1ba4 - 0x1b10];
    char locked;
};

struct TargetTable_67230 {
    char pad0[0x124];
    Target_67230 *player;
    Target_67230 *FUN_00024280(int a, int b);
};

struct World {
    char pad0[0x20];
    TargetTable_67230 *targets;
};


struct Key_67230 {
    int a, b;
};

struct TreeNode_67230 {
    char pad0[0x18];
    int keyA;
    int keyB;
};

struct Entry_67230 {
    float dist;
    int unused;
    int keyA;
    int keyB;
};

struct Tree_67230 {
    int link[6];
    void FUN_00230f50(void (__cdecl *cb)(void *, void *), void *user);
    void FUN_00066a90(int *out, Entry_67230 *entry);
    TreeNode_67230 *FUN_00230ea0();
    TreeNode_67230 *FUN_00230800(TreeNode_67230 *node);
};

void __cdecl FUN_00066930(void *node, void *user);

class Tracker_67230 {
public:
    bool FUN_00067230(Target_67230 *self);

    char pad0[0x154];
    Vec3_67230 origin;
    char pad2[0x170 - 0x160];
    Key_67230 keys[40];
    int count;
    char pad4[0x2c4 - 0x2b4];
    int bonus;
    char pad5[0x2d0 - 0x2c8];
    int limit;
    char pad6[0x310 - 0x2d4];
    Tree_67230 tree;
};

bool Tracker_67230::FUN_00067230(Target_67230 *self)
{
    struct Frame {
        int outPair[2];
        Vec3_67230 d;
        Vec3_67230 pos;
        Vec3_67230 player;
        Entry_67230 entry;
    } f;
    int n = 0;
    int nearCount = 0;
    int i;

    f.pos.x = 0.0f; f.pos.y = 0.0f; f.pos.z = 0.0f;
    f.player.x = 0.0f; f.player.y = 0.0f; f.player.z = 0.0f;
    tree.FUN_00230f50(FUN_00066930, &tree);
    DAT_004dd700->targets->player->transform->FUN_00059a50(&f.player);
    for (i = 0; i < count; i++) {
        Target_67230 *t = DAT_004dd700->targets->FUN_00024280(keys[i].a, keys[i].b);
        t->transform->FUN_00059a50(&f.pos);
        if (!(t->score < 0.0f)) {
            f.d.x = f.pos.x - origin.x;
            f.d.y = f.pos.y - origin.y;
            f.d.z = f.pos.z - origin.z;
            if (((int)((owners::Widget_35910 *)t)->FUN_00035910()) == 6 || self == t)
                nearCount++;
            f.d.y = 0.0f;
            f.entry.dist = f.d.FUN_0022d110();
            f.entry.keyA = keys[i].a;
            f.entry.keyB = keys[i].b;
            tree.FUN_00066a90(f.outPair, &f.entry);
        } else {
            for (int j = i + 1; j < count; j++)
                keys[j - 1] = keys[j];
            count--;
            i--;
        }
    }
    if (tree.link[5] < limit)
        return false;
    TreeNode_67230 *node = tree.FUN_00230ea0();
    if (node == 0)
        return false;
    do {
        Target_67230 *t = DAT_004dd700->targets->FUN_00024280(node->keyA, node->keyB);
        if (t != 0) {
            if (n < bonus + nearCount) {
                n++;
                t->locked = 1;
            } else {
                t->locked = 0;
            }
        }
        node = tree.FUN_00230800(node);
    } while (node != 0);
    return true;
}
} // namespace fn_00067230
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00067490 FUN_00067490 (242 B): equivalent/0x00067490.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_00067490@State_67490@fn_00067490@@QAEXPBUVec_67490@2@H@Z @ee8f44c43908 @w4bda8b00c746
namespace fn_00067490 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_00067490 @ 0x00067490
struct Vec_67490 { float x,y,z; };
struct Clock_67490 { float FUN_00086080(); };
struct Context { char pad[0x2c]; void* resource; };

#define DAT_004dd700 (*(Context* *)&::DAT_004dd700)

struct State_67490 {
 void* resource; Clock_67490* clock;
 char pad0[0x154-8]; Vec_67490 position;
 char pad1[0x2b0-0x160]; int current; int previous;
 char pad2[0x354-0x2b8]; float deadline; float interval;
 bool FUN_000662b0(); bool FUN_00067230(int arg);
 void FUN_00067490(const Vec_67490* pos, int arg);
};
void State_67490::FUN_00067490(const Vec_67490* pos, int arg) {
 if (!clock) return;
 if (!resource) { resource=DAT_004dd700->resource; if (!resource) return; }
 position=*pos;
 float threshold=deadline-interval;
 if (clock->FUN_00086080() < threshold) deadline=clock->FUN_00086080();
 if (previous != current) deadline=clock->FUN_00086080();
 if (!FUN_000662b0()) deadline=clock->FUN_00086080();
 if (clock->FUN_00086080() >= deadline) {
  if (FUN_00067230(arg)) {
   float value=clock->FUN_00086080()+interval;
   previous=current;
   deadline=value;
  }
 }
}
} // namespace fn_00067490
#undef DAT_004dd700

namespace fn_fa3ff49b {

// 0x000675b0 FUN_000675b0 (317 B): matches/0x000675b0.cpp
// sym: ?FUN_000675b0@Vehicle_675b0@fn_fa3ff49b@@QAEPAV12@XZ
// FUN_000675b0 @ 0x000675b0
Vehicle_675b0 *Vehicle_675b0::FUN_000675b0()
{
    f2b0 = 0;
    f2b4 = -1;
    f2b8 = 10.0f;
    f2bc = 20.0f;
    f2c0 = 1;
    f2c4 = 2;
    f2c8 = 3;
    f2cc = 10;
    f2d0 = 3;
    f2d4 = 10;
    ((owners::X_230b60 *)&s2d8)->FUN_00230b60();
    ((owners::X_230b60 *)&s2f4)->FUN_00230b60();
    ((owners::X_230b60 *)&s310)->FUN_00230b60();
    f330 = 10;
    f338 = 10;
    f358 = 2.0f;
    f360 = 2.0f;
    f32c = 0;
    f334 = 0;
    f33c = 0;
    f340 = 0;
    f344 = 0;
    f348 = 0;
    f34c = 0;
    f354 = 0;
    f35c = 0;
    f364 = 0;
    f36c = 0;
    f390 = 0;
    f388 = 0;
    f38c = 0;
    f380 = 0;
    f384 = 0;
    f150 = 0;
    f350 = 4.5f;
    f368 = 1.1f;
    f370 = 10.0f;
    f374 = 200.0f;
    f378 = 1.5f;
    return this;
}


// 0x000676f0 FUN_000676f0 (56 B): matches/0x000676f0.cpp
// sym: ?Run@Obj_676f0@fn_fa3ff49b@@QAEXXZ
void Obj_676f0::Run() {
    ((Helper_676f0*)((char*)this + 0x310))->Init_00230f50((void (*)())((hulk_intptr)(void (__cdecl*)())&FUN_00066930), (char*)this + 0x310);
    ((Helper_676f0*)((char*)this + 0x2f4))->Init_00230f50((void (*)())((hulk_intptr)(void (__cdecl*)())&FUN_00066a00), (char*)this + 0x2f4);
    ((Helper_676f0*)((char*)this + 0x2d8))->Init_00230f50((void (*)())((hulk_intptr)(void (__cdecl*)())&FUN_00066930), (char*)this + 0x2d8);
}

} // namespace fn_fa3ff49b

// 0x00067730 FUN_00067730 (156 B): equivalent/0x00067730.cpp [wrapped: conflict: World]
// sym: ?FUN_00067730@Ticker@fn_00067730@@QAEXXZ @913c09383451 @we3518c35dfcd
namespace fn_00067730 {
// STATUS: equivalent (tools/equiv.py level 3: 490 inputs, branch coverage 12/12)
// FUN_00067730 @ 0x00067730
// FUN_00067730: once the clock passes the next-update time, refresh every entry's score and schedule the next update
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Clock_67730 {
    float FUN_00086080();
};

struct World {
    char pad00[0x2c];
    int f2c;
};

struct Pos_67730 {
    int x;
    int y;
};

struct Entry_67730 {
    char pad00[0x10];
    Pos_67730 pos;
    float score;
};

struct List_67730 {
    char data[0x58];
    Entry_67730 *FUN_00230ea0();
    Entry_67730 *FUN_00230800(Entry_67730 *e);
};


class Ticker {
public:
    int f0;
    Clock_67730 *clock;
    char pad08[0x2ec];
    List_67730 list;
    float nextTime;
    char pad350[0x378 - 0x350];
    float interval;
    char pad37c[0x388 - 0x37c];
    Pos_67730 last;

    hulk_freg FUN_00067110(Pos_67730 *p);
    void FUN_00067730();
};

void Ticker::FUN_00067730()
{
    if (clock == 0)
        return;
    if (f0 == 0) {
        f0 = DAT_004dd700->f2c;
        if (f0 == 0)
            return;
    }
    if (!(clock->FUN_00086080() >= nextTime))
        return;
    for (Entry_67730 *e = list.FUN_00230ea0(); e != 0; e = list.FUN_00230800(e)) {
        e->score = FUN_00067110(&e->pos) * 0.2f;
        last = e->pos;
    }
    nextTime = clock->FUN_00086080() + interval;
}
} // namespace fn_00067730
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000677d0 FUN_000677d0 (160 B): matches/0x000677d0.cpp [wrapped: conflict: World]
// sym: ?FUN_000677d0@Effect_677d0@fn_000677d0@@QAEXXZ
namespace fn_000677d0 {
// FUN_000677d0 @ 0x000677d0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_677d0 {
    float x, y, z;
};

class Entity {
public:
    char pad0[0x10];
    class Sub_677d0 *sub;
};

class Sub_677d0 {
public:
    char pad0[0x124];
    Entity *entity;
};

class World {
public:
    char pad0[0x20];
    Sub_677d0 *sub;
};

class Node {
public:
    void FUN_00059a50(Vec3_677d0 *out);
};

class Clock_677d0 {
public:
    float FUN_00086080();
};

class Effect_677d0 {
public:
    void FUN_000677d0();
    void FUN_00065b20();
    void FUN_000671b0(Vec3_677d0 *v);
    void FUN_00067730();
    void FUN_00067490(Vec3_677d0 *v, int flag);
    void FUN_00065b80(int flag);

    char pad0[4];
    Clock_677d0 *clock;
    char pad1[0x364 - 8];
    float threshold;
    char pad2[4];
    char active;
};


void Effect_677d0::FUN_000677d0()
{
    Vec3_677d0 pos;
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    ((Node *)DAT_004dd700->sub->entity->sub)->FUN_00059a50(&pos);
    FUN_00065b20();
    FUN_000671b0(&pos);
    FUN_00067730();
    FUN_00067490(&pos, 0);
    FUN_00065b80(0);
    if (active) {
        if (clock->FUN_00086080() >= threshold) {
            active = 0;
            threshold = 0;
        }
    }
}
} // namespace fn_000677d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fa3ff49b {

// 0x00067870 FUN_00067870 (96 B): matches/0x00067870.cpp
// sym: ?Tick@Obj_67870@fn_fa3ff49b@@QAEXH@Z
void Obj_67870::Tick(hulk_intptr arg) {
    value = base->Compute_00086080();
    float v[3] = {0, 0, 0};
    B_67870* b = gRoot_67870->m->a->y;
    b->Run_00059a50(v);
    Do_00067490(v, arg);
}


// 0x000678d0 FUN_000678d0 (58 B): matches/0x000678d0.cpp
// sym: _FUN_000678d0
// data: flag_678d0 = DAT_004dcec0, object_678d0 = DAT_004dc678
extern "C" Obj_678d0* FUN_000678d0() {
    if (((*(unsigned int*)&DAT_004dcec0) & 1) == 0) {
        (*(unsigned int*)&DAT_004dcec0) = (*(unsigned int*)&DAT_004dcec0) | 1;
        (*(Obj_678d0*)&DAT_004dc678).init_000675b0();
        atexit(cleanup);
    }
    return ((Obj_678d0*)&DAT_004dc678);
}


// 0x00067930 FUN_00067930 (51 B): matches/0x00067930.cpp
// sym: ?FUN_00067930@fn_fa3ff49b@@YIXPAUVec_67930@1@PAX0M@Z
void __fastcall FUN_00067930(Vec_67930* self, void*, Vec_67930* other, float t) {
    self->x = (other->x - self->x) * t + self->x;
    self->y = (other->y - self->y) * t + self->y;
    self->z = (other->z - self->z) * t + self->z;
}


// 0x000679c0 FUN_000679c0 (8 B): matches/0x000679c0.cpp
// sym: ?FUN_000679c0@fn_fa3ff49b@@YIXPAUC_679c0@1@@Z
void __fastcall FUN_000679c0(C_679c0* self) {
    FUN_0027af50((C_679c0*)((char*)self + 0x18));
}

} // namespace fn_fa3ff49b

// 0x00067a20 FUN_00067a20 (32 B): matches/0x00067a20.cpp
// sym: ?FUN_00067a20@C_67a20@owners@@QAEXXZ
void owners::C_67a20::FUN_00067a20() {
    Item_67a20* p = (Item_67a20*)((char*)this + 0x920);
    int i = 0x40;
    do {
        p = (Item_67a20*)((char*)p - 0x20);
        p->tick_0027af50();
        --i;
    } while (i != 0);
}


// 0x00067a40 FUN_00067a40 (80 B): matches/0x00067a40.cpp [wrapped: merged class would differ: Elem: field val: Field(+0x18 V val) vs Field(+0x18 V val)]
// sym: ?run@X@fn_00067a40@@QAEXXZ
namespace fn_00067a40 {
// data: globalV = DAT_004dcf00, zero = DAT_003f335c

struct V {
    int value;
};
struct Elem {
    int a, b, c, d, e;
    char pad[4];
    V val;
    char tail[4];
};
struct X {
    char pad[8];
    int first[64];
    Elem elems[64];
    void run();
};
void X::run() {
    ((owners::Target_27b040 *)&((*(V*)&DAT_004dcf00)))->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
    int* p = first;
    volatile int* q = &elems[0].c;
    int n = 64;
    do {
        *p = 0;
        q[-2] = 0;
        q[1] = 0;
        q[0] = 0;
        q[-1] = 0;
        q[2] = 0;
        ((owners::Target_27b040 *)(((V*)(q + 4))))->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
        ++p;
        q += 8;
    } while (--n);
}
} // namespace fn_00067a40


// 0x00067ad0 FUN_00067ad0 (43 B): matches/0x00067ad0.cpp
// sym: ?FUN_00067ad0@C_67ad0@owners@@QAEPAXI@Z
void* owners::C_67ad0::FUN_00067ad0(unsigned int x) {
    if (x == 0)
        return 0;
    int i = (int)(x & 255);
    if (slots[i] != x)
        return 0;
    if (i < 0)
        return 0;
    return (char*)this + i * 32 + 0x108;
}

namespace fn_fa3ff49b {

// 0x00067b00 FUN_00067b00 (157 B): equivalent/0x00067b00.cpp
// sym: ?FUN_00067b00@HandlePool@fn_fa3ff49b@@QAEIH@Z @5907e9c8d04f @w73c88db9a587
// STATUS: equivalent (tools/equiv.py level 3: 2756 inputs, branch coverage 9/10, incomplete)
// FUN_00067b00 @ 0x00067b00
// FUN_00067b00 @ 0x00067b00: allocate a handle (serial << 8 | slot) in a ring of 64 slots
unsigned int HandlePool::FUN_00067b00(int arg)
{
    int start = head;
    int slot = start;
    do {
        if (ids[slot] == 0)
            break;
        slot = (slot + 1) % 64;
    } while (slot != start);

    Record_67b00 *r = &records[slot];
    r->f0 = 0;
    r->fc = 0;
    r->f8 = 0;
    r->f4 = 0;
    r->f10 = 0;
    ((owners::Target_27b040 *)&(r->name))->FUN_0027b040((hulk_uintptr)(((const char*)&DAT_003f335c)));
    records[slot].name.FUN_0027af70(arg);

    unsigned int id = (serial << 8) | slot;
    ids[slot] = id;
    head = (slot + 1) % 64;
    serial = (serial + 1) % 0xffffff;
    if (serial == 0)
        serial = 1;
    return id;
}


// 0x00067ba0 FUN_00067ba0 (137 B): equivalent/0x00067ba0.cpp
// sym: ?Alloc@HandleTable@fn_fa3ff49b@@QAEIXZ @2534e7c535ae @w7283969284fd
// STATUS: equivalent (tools/equiv.py level 3: 233 inputs, branch coverage 10/10)
// FUN_00067ba0 @ 0x00067ba0
unsigned HandleTable::Alloc() {
    int start = head;
    int i = start;
    do {
        if (slot[i] == 0) break;
        i = (i + 1) % 64;
    } while (i != start);
    Entry_67ba0* e = &entry[i];
    e->a = 0; e->d = 0; e->c = 0; e->b = 0;
    e->e = 0;
    ((owners::Target_27b040 *)&(e->name))->FUN_0027b040((hulk_uintptr)"");
    unsigned gen = counter;
    unsigned handle = (gen << 8) | i;
    slot[i] = handle;
    head = (i + 1) % 64;
    counter = (gen + 1) % 0xffffff;
    if (counter == 0) counter = 1;
    return handle;
}


// 0x00067c30 FUN_00067c30 (77 B): matches/0x00067c30.cpp
// sym: ?Put@Obj_67c30@fn_fa3ff49b@@QAE_NIPBUData_67c30@2@@Z
bool Obj_67c30::Put(unsigned int key, const Data_67c30* src) {
    int i;
    if (key == 0)
        return false;
    i = (int)(key & 255);
    if (*(unsigned int*)(bytes + 8 + i * 4) != key)
        return false;
    if (i < 0)
        return false;
    *(Data_67c30*)(bytes + 0x108 + i * 32) = *src;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00067c80 FUN_00067c80 (81 B): equivalent/0x00067c80.cpp [wrapped: conflict: Object]
// sym: ?FUN_00067c80@Object@fn_00067c80@@QAEEI@Z @86ef90765773 @w2a8894431039
namespace fn_00067c80 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 5/6, incomplete)
// FUN_00067c80 @ 0x00067c80

struct Value {  }; struct Entry { unsigned a,b,c,d,e; char pad[4]; Value value; char tail[4]; }; struct Object { char pad[8]; unsigned handles[64]; Entry entries[256]; unsigned char FUN_00067c80(unsigned handle); };  unsigned char Object::FUN_00067c80(unsigned handle) { if (!handle) return 0; unsigned index = handle & 255; if (handles[index] != handle) return 0; handles[index] = 0; Entry &entry = entries[index]; entry.a = 0; entry.d = 0; entry.c = 0; entry.b = 0; entry.e = 0; ((owners::Target_27b040 *)&(entry.value))->FUN_0027b040((hulk_uintptr)(((float*)&DAT_003f335c))); return 1; }
} // namespace fn_00067c80

namespace fn_fa3ff49b {

// 0x00067ce0 FUN_00067ce0 (314 B): equivalent/0x00067ce0.cpp
// sym: ?run@Tracker_67ce0@fn_fa3ff49b@@QAE_NPBUObjId@2@HPBUSphere_67ce0@2@PAUV3_67ce0@2@PAPAX@Z @1aeb240c9154 @w985c6e5768ed
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 22/22)
// FUN_00067ce0 @ 0x00067ce0
bool Tracker_67ce0::run(const ObjId* id, int skipTag, const Sphere_67ce0* s, V3_67ce0* outPos, void** outObj)
{
    int count = 0;
    outPos->z = 0;
    outPos->y = 0;
    outPos->x = 0;
    for (int i = 0; i < 64; i++) {
        void* obj = objs[i];
        Rec_67ce0* r = &recs[i];
        if (obj == 0 || r->tag == skipTag)
            continue;
        if (id->lo != DAT_004dcf00 || id->hi != DAT_004dcf04) {
            if (r->idLo != id->lo || r->idHi != id->hi)
                continue;
        }
        hulk_freg rad = r->radius + s->radius;
        hulk_freg dx = s->x - r->x;
        hulk_freg dy = s->y - r->y;
        hulk_freg dz = s->z - r->z;
        hulk_freg d2 = dz * dz + dy * dy + dx * dx;
        if (!(rad * rad >= d2))
            continue;
        if (*outObj != 0 && *outObj == obj)
            continue;
        count++;
        *outObj = obj;
        hulk_freg w = 1.0f / count;
        outPos->x = (r->x - outPos->x) * w + outPos->x;
        outPos->y = (r->y - outPos->y) * w + outPos->y;
        outPos->z = (r->z - outPos->z) * w + outPos->z;
    }
    return count > 0;
}

} // namespace fn_fa3ff49b

// 0x00067e20 FUN_00067e20 (59 B): matches/0x00067e20.cpp [wrapped: conflict: Obj]
// sym: ??0Obj@fn_00067e20@@QAE@XZ
namespace fn_00067e20 {
// data: zero = DAT_003f335c

extern "C" void _ReadWriteBarrier();
struct Vec {
    void Init_0027af00();
};
struct Obj {
    int a, b, c, d, e, f;
    Vec v;
    Obj();
};
Obj::Obj() {
    v.Init_0027af00();
    ((owners::Target_27b040 *)&v)->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
    a = 0;
    d = 0;
    c = 0;
    b = 0;
    _ReadWriteBarrier();
    e = 0;
    ((owners::Target_27b040 *)&v)->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
}
} // namespace fn_00067e20

namespace fn_fa3ff49b {

// 0x00067e60 FUN_00067e60 (49 B): matches/0x00067e60.cpp
// sym: ?Copy@Obj_67e60@fn_fa3ff49b@@QAEPAU12@PBU12@@Z
Obj_67e60* Obj_67e60::Copy(const Obj_67e60* src) {
    inner.Inner::Inner();
    v[0] = src->v[0];
    v[1] = src->v[1];
    v[2] = src->v[2];
    v[3] = src->v[3];
    v[4] = src->v[4];
    return this;
}


// 0x00067ea0 FUN_00067ea0 (133 B): equivalent/0x00067ea0.cpp
// sym: ??0Table_67ea0@fn_fa3ff49b@@QAE@XZ @a0ccc6600e57 @w1687a25465d0
// STATUS: equivalent (tools/equiv.py level 3: 1751 inputs, branch coverage 2/2)
// FUN_00067ea0 @ 0x00067ea0
Table_67ea0::Table_67ea0()
{
    one = 1;
    zero = 0;
    for (int i = 0; i < 0x40; i++) {
        Entry_67ea0 *e = &entries[i];
        e->key.FUN_0027af00();
        ((owners::Target_27b040 *)&(e->key))->FUN_0027b040((hulk_uintptr)"");
        e->f00 = 0;
        e->f0c = 0;
        e->f08 = 0;
        e->f04 = 0;
        e->f10 = 0;
        ((owners::Target_27b040 *)&(e->key))->FUN_0027b040((hulk_uintptr)"");
    }
    FUN_00067a40();
}

} // namespace fn_fa3ff49b

// 0x00067f30 FUN_00067f30 (12 B): matches/0x00067f30.cpp
// sym: ?FUN_00067f30@Obj_67f30@owners@@QAE_NPAX@Z
bool owners::Obj_67f30::FUN_00067f30(void* p) {
    *(void**)((char*)this + 12) = p;
    return true;
}


// 0x00067f40 FUN_00067f40 (12 B): matches/0x00067f40.cpp
// sym: ?FUN_00067f40@Obj_67f40@owners@@QAEDH@Z
char owners::Obj_67f40::FUN_00067f40(int x) {
    m10 = x;
    return 1;
}


// 0x00067f50 FUN_00067f50 (12 B): matches/0x00067f50.cpp
// sym: ?FUN_00067f50@X_67f50@owners@@QAEDD@Z
char owners::X_67f50::FUN_00067f50(char v) {
    m20 = v;
    return 1;
}

namespace fn_fa3ff49b {

// 0x00067f60 FUN_00067f60 (26 B): matches/0x00067f60.cpp
// sym: ?Set@Obj_67f60@fn_fa3ff49b@@QAE_NPAUEntry_67f60@2@@Z
bool Obj_67f60::Set(Entry_67f60* e) {
    m24 = e->a;
    m28 = e->b;
    m2c = e->c;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00067f80 FUN_00067f80 (12 B): matches/0x00067f80.cpp
// sym: ?FUN_00067f80@Obj_67f80@owners@@QAEEE@Z
unsigned char owners::Obj_67f80::FUN_00067f80(unsigned char v) {
    m = v;
    return 1;
}

namespace fn_fa3ff49b {

// 0x00067f90 FUN_00067f90 (12 B): matches/0x00067f90.cpp
// sym: ?Set@Obj_67f90@fn_fa3ff49b@@QAE_NH@Z
bool Obj_67f90::Set(int v) {
    m40 = v;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00067fa0 FUN_00067fa0 (12 B): matches/0x00067fa0.cpp
// sym: ?FUN_00067fa0@Obj_67fa0@owners@@QAEDH@Z
char owners::Obj_67fa0::FUN_00067fa0(int a) {
    *(int*)(m + 0x44) = a;
    return 1;
}


// 0x00067fb0 FUN_00067fb0 (12 B): matches/0x00067fb0.cpp
// sym: ?FUN_00067fb0@Obj_67fb0@owners@@QAEDH@Z
char owners::Obj_67fb0::FUN_00067fb0(int v) {
    mVal = v;
    return 1;
}


// 0x00067fc0 FUN_00067fc0 (12 B): matches/0x00067fc0.cpp
// sym: ?FUN_00067fc0@O_67fc0@owners@@QAE_NH@Z
bool owners::O_67fc0::FUN_00067fc0(int x) {
    m = x;
    return true;
}


// 0x00067fd0 FUN_00067fd0 (12 B): matches/0x00067fd0.cpp
// sym: ?FUN_00067fd0@Obj_67fd0@owners@@QAEDH@Z
char owners::Obj_67fd0::FUN_00067fd0(int x) {
    m = x;
    return 1;
}


// 0x00067fe0 FUN_00067fe0 (12 B): matches/0x00067fe0.cpp
// sym: ?FUN_00067fe0@Obj_67fe0@owners@@QAE_NH@Z
bool owners::Obj_67fe0::FUN_00067fe0(int x) {
    mVal = x;
    return true;
}


// 0x00067ff0 FUN_00067ff0 (12 B): matches/0x00067ff0.cpp
// sym: ?FUN_00067ff0@Obj_67ff0@owners@@QAEDH@Z
char owners::Obj_67ff0::FUN_00067ff0(int v) {
    m10 = v;
    return 1;
}


// 0x00068000 FUN_00068000 (12 B): matches/0x00068000.cpp
// sym: ?FUN_00068000@Obj_68000@owners@@QAEDPAX@Z
char owners::Obj_68000::FUN_00068000(void* p) {
    value = p;
    return 1;
}


// 0x00068010 FUN_00068010 (12 B): matches/0x00068010.cpp
// sym: ?FUN_00068010@Obj_68010@owners@@QAEDH@Z
char owners::Obj_68010::FUN_00068010(int v) {
    m18 = v;
    return 1;
}


// 0x00068020 FUN_00068020 (12 B): matches/0x00068020.cpp
// sym: ?FUN_00068020@Obj_68020@owners@@QAE_NH@Z
bool owners::Obj_68020::FUN_00068020(int x) {
    m1c = x;
    return true;
}


// 0x00068030 FUN_00068030 (12 B): matches/0x00068030.cpp
// sym: ?FUN_00068030@A_68030@owners@@QAE_NH@Z
bool owners::A_68030::FUN_00068030(int x) {
    m20 = x;
    return true;
}


// 0x00068040 FUN_00068040 (12 B): matches/0x00068040.cpp
// sym: ?FUN_00068040@X_68040@owners@@QAEDH@Z
char owners::X_68040::FUN_00068040(int x) {
    mField = x;
    return 1;
}


// 0x00068050 FUN_00068050 (12 B): matches/0x00068050.cpp
// sym: ?FUN_00068050@Obj_68050@owners@@QAEEH@Z
unsigned char owners::Obj_68050::FUN_00068050(int a) {
    m28 = a;
    return 1;
}


// 0x00068060 FUN_00068060 (12 B): matches/0x00068060.cpp
// sym: ?FUN_00068060@A_68060@owners@@QAE_NH@Z
bool owners::A_68060::FUN_00068060(int x) {
    value = x;
    return true;
}


// 0x00068070 FUN_00068070 (12 B): matches/0x00068070.cpp
// sym: ?FUN_00068070@Obj_68070@owners@@QAE_NH@Z
bool owners::Obj_68070::FUN_00068070(int value) {
    mField = value;
    return true;
}


// 0x00068080 FUN_00068080 (12 B): matches/0x00068080.cpp
// sym: ?FUN_00068080@Obj_68080@owners@@QAE_NH@Z
bool owners::Obj_68080::FUN_00068080(int x) {
    value = x;
    return true;
}


// 0x00068090 FUN_00068090 (12 B): matches/0x00068090.cpp
// sym: ?FUN_00068090@Obj_68090@owners@@QAE_NH@Z
bool owners::Obj_68090::FUN_00068090(int x) {
    value = x;
    return true;
}


// 0x000680a0 FUN_000680a0 (12 B): matches/0x000680a0.cpp
// sym: ?FUN_000680a0@Obj_680a0@owners@@QAEDH@Z
char owners::Obj_680a0::FUN_000680a0(int v) {
    mValue = v;
    return 1;
}


// 0x000680b0 FUN_000680b0 (12 B): matches/0x000680b0.cpp
// sym: ?FUN_000680b0@X_680b0@owners@@QAE_NH@Z
bool owners::X_680b0::FUN_000680b0(int v) {
    m = v;
    return true;
}


// 0x000680c0 FUN_000680c0 (12 B): matches/0x000680c0.cpp
// sym: ?FUN_000680c0@Target_680c0@owners@@QAEDD@Z
char owners::Target_680c0::FUN_000680c0(char v) {
    data[0x50] = v;
    return 1;
}


// 0x000680d0 FUN_000680d0 (12 B): matches/0x000680d0.cpp
// sym: ?FUN_000680d0@Obj_680d0@owners@@QAEDD@Z
char owners::Obj_680d0::FUN_000680d0(char v) {
    value = v;
    return 1;
}


// 0x000680e0 FUN_000680e0 (18 B): matches/0x000680e0.cpp
// sym: ?FUN_000680e0@Obj_680e0@owners@@QAEDM@Z
char owners::Obj_680e0::FUN_000680e0(float x) {
    value = x * 0.01745329252f;
    return 1;
}


// 0x00068100 FUN_00068100 (18 B): matches/0x00068100.cpp
// sym: ?FUN_00068100@Obj_68100@owners@@QAE_NM@Z
bool owners::Obj_68100::FUN_00068100(float x) {
    angle = x * 0.017453292519943295f;
    return true;
}


// 0x00068120 FUN_00068120 (12 B): matches/0x00068120.cpp
// sym: ?FUN_00068120@O_68120@owners@@QAE_NH@Z
bool owners::O_68120::FUN_00068120(int a) {
    mF12 = a;
    return true;
}


// 0x00068130 FUN_00068130 (12 B): matches/0x00068130.cpp
// sym: ?FUN_00068130@Obj_68130@owners@@QAEDH@Z
char owners::Obj_68130::FUN_00068130(int x) {
    mValue = x;
    return 1;
}


// 0x00068140 FUN_00068140 (18 B): matches/0x00068140.cpp
// sym: ?FUN_00068140@C_68140@owners@@QAEDM@Z
char owners::C_68140::FUN_00068140(float x) {
    f = x * k_68140;
    return 1;
}


// 0x00068160 FUN_00068160 (18 B): matches/0x00068160.cpp
// sym: ?FUN_00068160@Obj_68160@owners@@QAEDM@Z
char owners::Obj_68160::FUN_00068160(float deg) {
    angle = deg * 0.017453292f;
    return 1;
}


// 0x00068180 FUN_00068180 (18 B): matches/0x00068180.cpp
// sym: ?FUN_00068180@Obj_68180@owners@@QAE_NM@Z
bool owners::Obj_68180::FUN_00068180(float x) {
    value = x * kRad;
    return true;
}


// 0x000681a0 FUN_000681a0 (12 B): matches/0x000681a0.cpp
// sym: ?FUN_000681a0@Obj_681a0@owners@@QAEEE@Z
unsigned char owners::Obj_681a0::FUN_000681a0(unsigned char value) {
    m = value;
    return 1;
}


// 0x000681b0 FUN_000681b0 (12 B): matches/0x000681b0.cpp
// sym: ?FUN_000681b0@Target_681b0@owners@@QAEDH@Z
char owners::Target_681b0::FUN_000681b0(int arg) {
    m24 = arg;
    return 1;
}


// 0x000681c0 FUN_000681c0 (12 B): matches/0x000681c0.cpp
// sym: ?FUN_000681c0@Obj_681c0@owners@@QAEDH@Z
char owners::Obj_681c0::FUN_000681c0(int v) {
    value = v;
    return 1;
}


// 0x000681d0 FUN_000681d0 (12 B): matches/0x000681d0.cpp
// sym: ?FUN_000681d0@Obj_681d0@owners@@QAE_NPAX@Z
bool owners::Obj_681d0::FUN_000681d0(void* p) {
    m2c = p;
    return true;
}


// 0x000681e0 FUN_000681e0 (12 B): matches/0x000681e0.cpp
// sym: ?FUN_000681e0@Obj_681e0@owners@@QAE_NH@Z
bool owners::Obj_681e0::FUN_000681e0(int value) {
    mValue = value;
    return true;
}


// 0x000681f0 FUN_000681f0 (12 B): matches/0x000681f0.cpp
// sym: ?FUN_000681f0@Obj_681f0@owners@@QAE_NH@Z
bool owners::Obj_681f0::FUN_000681f0(int v) {
    m34 = v;
    return true;
}


// 0x00068200 FUN_00068200 (12 B): matches/0x00068200.cpp
// sym: ?FUN_00068200@Obj_68200@owners@@QAE_NH@Z
bool owners::Obj_68200::FUN_00068200(int v) {
    m = v;
    return true;
}


// 0x00068210 FUN_00068210 (12 B): matches/0x00068210.cpp
// sym: ?FUN_00068210@O_68210@owners@@QAEDE@Z
char owners::O_68210::FUN_00068210(unsigned char x) {
    m58 = x;
    return 1;
}


// 0x00068220 FUN_00068220 (12 B): matches/0x00068220.cpp
// sym: ?FUN_00068220@Obj_68220@owners@@QAEDH@Z
char owners::Obj_68220::FUN_00068220(int value) {
    field = value;
    return 1;
}


// 0x00068230 FUN_00068230 (12 B): matches/0x00068230.cpp
// sym: ?FUN_00068230@Obj_68230@owners@@QAE_NH@Z
bool owners::Obj_68230::FUN_00068230(int x) {
    value = x;
    return true;
}


// 0x00068240 FUN_00068240 (12 B): matches/0x00068240.cpp
// sym: ?FUN_00068240@Obj_68240@owners@@QAE_NH@Z
bool owners::Obj_68240::FUN_00068240(int x) {
    value = x;
    return true;
}

namespace fn_fa3ff49b {

// 0x00068250 FUN_00068250 (12 B): matches/0x00068250.cpp
// sym: ?Set@Obj_68250@fn_fa3ff49b@@QAEEH@Z
unsigned char Obj_68250::Set(int v) {
    mValue = v;
    return 1;
}


// 0x00068260 FUN_00068260 (12 B): matches/0x00068260.cpp
// sym: ?Set@C_68260@fn_fa3ff49b@@QAEDH@Z
char C_68260::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}


// 0x00068270 FUN_00068270 (12 B): matches/0x00068270.cpp
// sym: ?Set@Target_68270@fn_fa3ff49b@@QAE_NH@Z
bool Target_68270::Set(int value) {
    field = value;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00068280 FUN_00068280 (12 B): matches/0x00068280.cpp
// sym: ?FUN_00068280@Obj_68280@owners@@QAE_NH@Z
bool owners::Obj_68280::FUN_00068280(int arg) {
    value = arg;
    return true;
}


// 0x00068290 FUN_00068290 (12 B): matches/0x00068290.cpp
// sym: ?FUN_00068290@Obj_68290@owners@@QAE_NH@Z
bool owners::Obj_68290::FUN_00068290(int v) {
    mValue = v;
    return true;
}


// 0x000682a0 FUN_000682a0 (12 B): matches/0x000682a0.cpp
// sym: ?FUN_000682a0@Obj_682a0@owners@@QAEDH@Z
char owners::Obj_682a0::FUN_000682a0(int value) {
    m14 = value;
    return 1;
}


// 0x000682b0 FUN_000682b0 (12 B): matches/0x000682b0.cpp
// sym: ?FUN_000682b0@X_682b0@owners@@QAE_NH@Z
bool owners::X_682b0::FUN_000682b0(int v) {
    mVal = v;
    return true;
}


// 0x000682c0 FUN_000682c0 (12 B): matches/0x000682c0.cpp
// sym: ?FUN_000682c0@X_682c0@owners@@QAE_NH@Z
bool owners::X_682c0::FUN_000682c0(int v) {
    mValue = v;
    return true;
}


// 0x000682d0 FUN_000682d0 (12 B): matches/0x000682d0.cpp
// sym: ?FUN_000682d0@Obj_682d0@owners@@QAE_NH@Z
bool owners::Obj_682d0::FUN_000682d0(int x) {
    value = x;
    return 1;
}

namespace fn_fa3ff49b {

// 0x000682e0 FUN_000682e0 (12 B): matches/0x000682e0.cpp
// sym: ?Ctor@Obj_682e0@fn_fa3ff49b@@QAE_NH@Z
bool Obj_682e0::Ctor(int arg) {
    mValue = arg;
    return true;
}


// 0x000682f0 FUN_000682f0 (12 B): matches/0x000682f0.cpp
// sym: ?Set@Obj_682f0@fn_fa3ff49b@@QAEDH@Z
char Obj_682f0::Set(int x) {
    value = x;
    return 1;
}


// 0x00068300 FUN_00068300 (12 B): matches/0x00068300.cpp
// sym: ?SetX@Obj_68300@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68300::SetX(int v) {
    mX = v;
    return true;
}


// 0x00068310 FUN_00068310 (12 B): matches/0x00068310.cpp
// sym: ?SetTimeBegin_00068310@O_68310@fn_fa3ff49b@@QAEDH@Z
char O_68310::SetTimeBegin_00068310(int a) {
    m = a;
    return 1;
}

} // namespace fn_fa3ff49b

// 0x00068320 FUN_00068320 (12 B): matches/0x00068320.cpp [wrapped: conflict: Obj]
// sym: ?SetTimeEnd_00068320@Obj@fn_00068320@@QAE_NH@Z
namespace fn_00068320 {
class Obj {
    char pad[16];
    int value;

  public:
    bool SetTimeEnd_00068320(int v);
};
bool Obj::SetTimeEnd_00068320(int v) {
    value = v;
    return true;
}
} // namespace fn_00068320

namespace fn_fa3ff49b {

// 0x00068330 FUN_00068330 (12 B): matches/0x00068330.cpp
// sym: ?SetDistance_00068330@Target_68330@fn_fa3ff49b@@QAEDH@Z
char Target_68330::SetDistance_00068330(int x) {
    mField = x;
    return 1;
}

} // namespace fn_fa3ff49b

// 0x00068340 FUN_00068340 (12 B): matches/0x00068340.cpp
// sym: ?FUN_00068340@Obj_68340@owners@@QAEDH@Z
char owners::Obj_68340::FUN_00068340(int v) {
    mVal = v;
    return 1;
}


// 0x00068350 FUN_00068350 (12 B): matches/0x00068350.cpp
// sym: ?FUN_00068350@Obj_68350@owners@@QAE_NH@Z
bool owners::Obj_68350::FUN_00068350(int value) {
    m10 = value;
    return true;
}


// 0x00068360 FUN_00068360 (18 B): matches/0x00068360.cpp
// sym: ?FUN_00068360@Thing_68360@owners@@QAE_NM@Z
bool owners::Thing_68360::FUN_00068360(float v) {
    bool r = true;
    angle = v * 0.0174532925f;
    return r;
}


// 0x00068380 FUN_00068380 (12 B): matches/0x00068380.cpp
// sym: ?FUN_00068380@Obj_68380@owners@@QAE_NH@Z
bool owners::Obj_68380::FUN_00068380(int v) {
    m18 = v;
    return true;
}


// 0x00068390 FUN_00068390 (12 B): matches/0x00068390.cpp
// sym: ?FUN_00068390@Obj_68390@owners@@QAEDH@Z
char owners::Obj_68390::FUN_00068390(int x) {
    mValue = x;
    return 1;
}


// 0x000683a0 FUN_000683a0 (12 B): matches/0x000683a0.cpp
// sym: ?FUN_000683a0@Obj_683a0@owners@@QAEDH@Z
char owners::Obj_683a0::FUN_000683a0(int value) throw() {
    m = value;
    return 1;
}

namespace fn_fa3ff49b {

// 0x000683b0 FUN_000683b0 (12 B): matches/0x000683b0.cpp
// sym: ?Set@Obj_683b0@fn_fa3ff49b@@QAE_NH@Z
bool Obj_683b0::Set(int v) {
    mValue = v;
    return true;
}


// 0x000683c0 FUN_000683c0 (12 B): matches/0x000683c0.cpp
// sym: ?Set@X_683c0@fn_fa3ff49b@@QAEDH@Z
char X_683c0::Set(int v) {
    m10 = v;
    return 1;
}


// 0x000683d0 FUN_000683d0 (12 B): matches/0x000683d0.cpp
// sym: ?Set@Obj_683d0@fn_fa3ff49b@@QAEDH@Z
char Obj_683d0::Set(int value) {
    mValue = value;
    return 1;
}


// 0x00068410 FUN_00068410 (33 B): equivalent/0x00068410.cpp
// sym: ?FUN_00068410@Object@fn_fa3ff49b@@QAE_N_N@Z @9903d8996f8d @w52e4c14d5a65
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00068410 @ 0x00068410
bool Object::FUN_00068410(bool enabled) { if (enabled) flags |= 1; else flags &= ~1u; return true; }

} // namespace fn_fa3ff49b

// 0x00068440 FUN_00068440 (33 B): matches/0x00068440.cpp [wrapped: conflict: X]
// sym: ?Fn@X@fn_00068440@@QAE_N_N@Z
namespace fn_00068440 {
class X {
  public:
    char pad[0x20];
    unsigned int flags;
    bool Fn(bool b);
};

bool X::Fn(bool b) {
    if (b)
        flags |= 2;
    else
        flags &= ~2;
    return true;
}
} // namespace fn_00068440

namespace fn_fa3ff49b {

// 0x00068470 FUN_00068470 (12 B): matches/0x00068470.cpp
// sym: ?Set@Obj_68470@fn_fa3ff49b@@QAEDD@Z
char Obj_68470::Set(char v) {
    m38 = v;
    return 1;
}


// 0x00068480 FUN_00068480 (18 B): matches/0x00068480.cpp
// sym: ?Set@Obj_68480@fn_fa3ff49b@@QAEDM@Z
char Obj_68480::Set(float angle) {
    mValue = angle * (float)(3.14159265358979323846f / 180.0f);
    return 1;
}


// 0x000684a0 FUN_000684a0 (18 B): matches/0x000684a0.cpp
// sym: ?Set@Obj_684a0@fn_fa3ff49b@@QAEDM@Z
char Obj_684a0::Set(float a) {
    mAngle = a * 0.017453292f;
    return 1;
}


// 0x000684c0 FUN_000684c0 (12 B): matches/0x000684c0.cpp
// sym: ?Set@Obj_684c0@fn_fa3ff49b@@QAEDH@Z
char Obj_684c0::Set(int v) {
    mValue = v;
    return 1;
}


// 0x000684d0 FUN_000684d0 (12 B): matches/0x000684d0.cpp
// sym: ?Set@Obj_684d0@fn_fa3ff49b@@QAEDH@Z
char Obj_684d0::Set(int v) {
    value = v;
    return 1;
}


// 0x000684e0 FUN_000684e0 (12 B): matches/0x000684e0.cpp
// sym: ?Set@Obj_684e0@fn_fa3ff49b@@QAE_NH@Z
bool Obj_684e0::Set(int v) {
    mVal = v;
    return true;
}


// 0x000684f0 FUN_000684f0 (12 B): matches/0x000684f0.cpp
// sym: ?SetTimeBegin_000684f0@X_684f0@fn_fa3ff49b@@QAEDH@Z
char X_684f0::SetTimeBegin_000684f0(int n) {
    m = n;
    return 1;
}


// 0x00068500 FUN_00068500 (12 B): matches/0x00068500.cpp
// sym: ?SetDamage_00068500@Obj_68500@fn_fa3ff49b@@QAEDH@Z
char Obj_68500::SetDamage_00068500(int x) {
    m10 = x;
    return 1;
}


// 0x00068510 FUN_00068510 (12 B): matches/0x00068510.cpp
// sym: ?SetDamageMax_00068510@Obj_68510@fn_fa3ff49b@@QAEDH@Z
char Obj_68510::SetDamageMax_00068510(int v) {
    m14 = v;
    return 1;
}


// 0x00068520 FUN_00068520 (12 B): matches/0x00068520.cpp
// sym: ?Set@Target_68520@fn_fa3ff49b@@QAEDH@Z
char Target_68520::Set(int x) {
    value = x;
    return 1;
}


// 0x00068530 FUN_00068530 (12 B): matches/0x00068530.cpp
// sym: ?Set@O_68530@fn_fa3ff49b@@QAEDH@Z
char O_68530::Set(int x) {
    m = x;
    return 1;
}


// 0x00068540 FUN_00068540 (12 B): matches/0x00068540.cpp
// sym: ?Set@Obj_68540@fn_fa3ff49b@@QAE_NPAX@Z
bool Obj_68540::Set(void* p) {
    value = p;
    return true;
}


// 0x00068550 FUN_00068550 (12 B): matches/0x00068550.cpp
// sym: ?SetTimeBegin_00068550@Obj_68550@fn_fa3ff49b@@QAEDH@Z
char Obj_68550::SetTimeBegin_00068550(int x) {
    value = x;
    return 1;
}


// 0x00068560 FUN_00068560 (12 B): matches/0x00068560.cpp
// sym: ?SetTimeEnd_00068560@Obj_68560@fn_fa3ff49b@@QAEDH@Z
char Obj_68560::SetTimeEnd_00068560(int value) {
    mValue = value;
    return 1;
}


// 0x00068570 FUN_00068570 (12 B): matches/0x00068570.cpp
// sym: ?SetComboTimer_00068570@X_68570@fn_fa3ff49b@@QAE_NH@Z
bool X_68570::SetComboTimer_00068570(int x) {
    m14 = x;
    return true;
}


// 0x00068580 FUN_00068580 (12 B): matches/0x00068580.cpp
// sym: ?Set@Obj_68580@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68580::Set(int v) {
    mVal = v;
    return true;
}


// 0x00068590 FUN_00068590 (12 B): matches/0x00068590.cpp
// sym: ?Set@C_68590@fn_fa3ff49b@@QAE_NH@Z
bool C_68590::Set(int v) {
    m = v;
    return true;
}


// 0x000685a0 FUN_000685a0 (12 B): matches/0x000685a0.cpp
// sym: ?Set@C_685a0@fn_fa3ff49b@@QAE_NH@Z
bool C_685a0::Set(int v) {
    m14 = v;
    return true;
}

} // namespace fn_fa3ff49b

// 0x000685b0 FUN_000685b0 (12 B): matches/0x000685b0.cpp
// sym: ?FUN_000685b0@X_685b0@owners@@QAE_NH@Z
bool owners::X_685b0::FUN_000685b0(int value) {
    m = value;
    return true;
}


// 0x000685c0 FUN_000685c0 (12 B): matches/0x000685c0.cpp
// sym: ?FUN_000685c0@Obj_685c0@owners@@QAE_NH@Z
bool owners::Obj_685c0::FUN_000685c0(int v) {
    mValue = v;
    return true;
}


// 0x000685d0 FUN_000685d0 (12 B): matches/0x000685d0.cpp
// sym: ?FUN_000685d0@Obj_685d0@owners@@QAE_NH@Z
bool owners::Obj_685d0::FUN_000685d0(int v) {
    mVal = v;
    return true;
}


// 0x000685e0 FUN_000685e0 (12 B): matches/0x000685e0.cpp
// sym: ?FUN_000685e0@Obj_685e0@owners@@QAE_NH@Z
bool owners::Obj_685e0::FUN_000685e0(int value) {
    m10 = value;
    return true;
}

namespace fn_fa3ff49b {

// 0x000685f0 FUN_000685f0 (12 B): matches/0x000685f0.cpp
// sym: ?SetTimeBegin_000685f0@Obj_685f0@fn_fa3ff49b@@QAEDH@Z
char Obj_685f0::SetTimeBegin_000685f0(int v) {
    mVal = v;
    return 1;
}


// 0x00068600 FUN_00068600 (12 B): matches/0x00068600.cpp
// sym: ?SetTimeEnd_00068600@Obj_68600@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68600::SetTimeEnd_00068600(int x) {
    m10 = x;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00068610 FUN_00068610 (12 B): matches/0x00068610.cpp [wrapped: conflict: Obj]
// sym: ?SetAmplitude_00068610@Obj@fn_00068610@@QAE_NH@Z
namespace fn_00068610 {
class Obj {
    char pad[0x14];
    int value;

  public:
    bool SetAmplitude_00068610(int x);
};
bool Obj::SetAmplitude_00068610(int x) {
    value = x;
    return true;
}
} // namespace fn_00068610

namespace fn_fa3ff49b {

// 0x00068620 FUN_00068620 (12 B): matches/0x00068620.cpp
// sym: ?SetFrequency_00068620@Obj_68620@fn_fa3ff49b@@QAEDH@Z
char Obj_68620::SetFrequency_00068620(int a) {
    m18 = a;
    return 1;
}

} // namespace fn_fa3ff49b

// 0x00068630 FUN_00068630 (12 B): matches/0x00068630.cpp
// sym: ?FUN_00068630@Obj_68630@owners@@QAEDH@Z
char owners::Obj_68630::FUN_00068630(int value) {
    mField = value;
    return 1;
}


// 0x00068640 FUN_00068640 (12 B): matches/0x00068640.cpp
// sym: ?FUN_00068640@Obj_68640@owners@@QAEDH@Z
char owners::Obj_68640::FUN_00068640(int v) {
    Value = v;
    return 1;
}

namespace fn_fa3ff49b {

// 0x00068650 FUN_00068650 (26 B): matches/0x00068650.cpp
// sym: ?Set@Obj_68650@fn_fa3ff49b@@QAEDPAUSrc_68650@2@@Z
char Obj_68650::Set(Src_68650* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return 1;
}

} // namespace fn_fa3ff49b

// 0x00068670 FUN_00068670 (12 B): matches/0x00068670.cpp
// sym: ?FUN_00068670@Obj_68670@owners@@QAEDPAX@Z
char owners::Obj_68670::FUN_00068670(void* p) {
    mValue = p;
    return 1;
}


// 0x00068680 FUN_00068680 (12 B): matches/0x00068680.cpp
// sym: ?FUN_00068680@C_68680@owners@@QAEDH@Z
char owners::C_68680::FUN_00068680(int a) {
    *(int*)((char*)this + 0x64) = a;
    return 1;
}


// 0x00068690 FUN_00068690 (12 B): matches/0x00068690.cpp
// sym: ?FUN_00068690@Obj_68690@owners@@QAEDH@Z
char owners::Obj_68690::FUN_00068690(int x) {
    value = x;
    return 1;
}


// 0x000686a0 FUN_000686a0 (12 B): matches/0x000686a0.cpp
// sym: ?FUN_000686a0@Obj_686a0@owners@@QAE_NH@Z
bool owners::Obj_686a0::FUN_000686a0(int v) {
    field = v;
    return true;
}


// 0x000686b0 FUN_000686b0 (12 B): matches/0x000686b0.cpp
// sym: ?FUN_000686b0@Obj_686b0@owners@@QAE_NH@Z
bool owners::Obj_686b0::FUN_000686b0(int x) {
    field = x;
    return true;
}


// 0x000686c0 FUN_000686c0 (12 B): matches/0x000686c0.cpp
// sym: ?FUN_000686c0@Obj_686c0@owners@@QAE_NH@Z
bool owners::Obj_686c0::FUN_000686c0(int x) {
    field = x;
    return true;
}


// 0x000686d0 FUN_000686d0 (12 B): matches/0x000686d0.cpp
// sym: ?FUN_000686d0@Obj_686d0@owners@@QAEDH@Z
char owners::Obj_686d0::FUN_000686d0(int x) {
    *(int*)((char*)this + 0x78) = x;
    return 1;
}


// 0x000686e0 FUN_000686e0 (12 B): matches/0x000686e0.cpp
// sym: ?FUN_000686e0@Obj_686e0@owners@@QAE_NH@Z
bool owners::Obj_686e0::FUN_000686e0(int arg) {
    m7c = arg;
    return true;
}


// 0x000686f0 FUN_000686f0 (15 B): matches/0x000686f0.cpp
// sym: ?FUN_000686f0@A_686f0@owners@@QAE_NH@Z
bool owners::A_686f0::FUN_000686f0(int x) {
    m80 = x;
    return true;
}


// 0x00068700 FUN_00068700 (15 B): matches/0x00068700.cpp
// sym: ?FUN_00068700@O_68700@owners@@QAE_ND@Z
bool owners::O_68700::FUN_00068700(char value) {
    mFlag = value;
    return true;
}


// 0x00068710 FUN_00068710 (15 B): matches/0x00068710.cpp
// sym: ?FUN_00068710@Target_68710@owners@@QAE_NH@Z
bool owners::Target_68710::FUN_00068710(int x) {
    value = x;
    return true;
}


// 0x00068720 FUN_00068720 (15 B): matches/0x00068720.cpp
// sym: ?FUN_00068720@Obj_68720@owners@@QAEDH@Z
char owners::Obj_68720::FUN_00068720(int v) {
    value = v;
    return 1;
}


// 0x00068730 FUN_00068730 (15 B): matches/0x00068730.cpp
// sym: ?FUN_00068730@Obj_68730@owners@@QAE_NH@Z
bool owners::Obj_68730::FUN_00068730(int value) {
    field = value;
    return true;
}


// 0x00068740 FUN_00068740 (15 B): matches/0x00068740.cpp
// sym: ?FUN_00068740@Obj_68740@owners@@QAE_NH@Z
bool owners::Obj_68740::FUN_00068740(int x) {
    m = x;
    return true;
}


// 0x00068750 FUN_00068750 (15 B): matches/0x00068750.cpp
// sym: ?FUN_00068750@Obj_68750@owners@@QAE_NH@Z
bool owners::Obj_68750::FUN_00068750(int v) {
    m98 = v;
    return true;
}


// 0x00068760 FUN_00068760 (15 B): matches/0x00068760.cpp
// sym: ?FUN_00068760@Target_68760@owners@@QAE_NH@Z
bool owners::Target_68760::FUN_00068760(int v) {
    value = v;
    return true;
}

namespace fn_fa3ff49b {

// 0x00068770 FUN_00068770 (12 B): matches/0x00068770.cpp
// sym: ?SetTimeBegin_00068770@Obj_68770@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68770::SetTimeBegin_00068770(int x) {
    value = x;
    return true;
}


// 0x00068780 FUN_00068780 (12 B): matches/0x00068780.cpp
// sym: ?SetTimeEnd_00068780@X_68780@fn_fa3ff49b@@QAEDH@Z
char X_68780::SetTimeEnd_00068780(int value) {
    mValue = value;
    return 1;
}


// 0x00068790 FUN_00068790 (12 B): matches/0x00068790.cpp
// sym: ?SetHint_00068790@Obj_68790@fn_fa3ff49b@@QAEDH@Z
char Obj_68790::SetHint_00068790(int v) {
    value = v;
    return 1;
}

} // namespace fn_fa3ff49b

// 0x000687a0 FUN_000687a0 (12 B): matches/0x000687a0.cpp
// sym: ?FUN_000687a0@A_687a0@owners@@QAE_NH@Z
bool owners::A_687a0::FUN_000687a0(int v) {
    m = v;
    return true;
}


// 0x000687b0 FUN_000687b0 (12 B): matches/0x000687b0.cpp
// sym: ?FUN_000687b0@A_687b0@owners@@QAE_NH@Z
bool owners::A_687b0::FUN_000687b0(int x) {
    Value = x;
    return true;
}

namespace fn_fa3ff49b {

// 0x000687c0 FUN_000687c0 (26 B): matches/0x000687c0.cpp
// sym: ?Set@Obj_687c0@fn_fa3ff49b@@QAEDPAUVec_687c0@2@@Z
char Obj_687c0::Set(Vec_687c0* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return 1;
}

} // namespace fn_fa3ff49b

// 0x000687e0 FUN_000687e0 (18 B): matches/0x000687e0.cpp
// sym: ?FUN_000687e0@Sub_687e0@owners@@QAEEM@Z
unsigned char owners::Sub_687e0::FUN_000687e0(float v) {
    mAngle = v * kRadianToDegree;
    return 1;
}


// 0x00068800 FUN_00068800 (12 B): matches/0x00068800.cpp
// sym: ?FUN_00068800@Obj_68800@owners@@QAEEH@Z
unsigned char owners::Obj_68800::FUN_00068800(int x) {
    value = x;
    return 1;
}


// 0x00068810 FUN_00068810 (12 B): matches/0x00068810.cpp
// sym: ?FUN_00068810@Obj_68810@owners@@QAE_NH@Z
bool owners::Obj_68810::FUN_00068810(int v) {
    mValue = v;
    return true;
}


// 0x00068820 FUN_00068820 (12 B): matches/0x00068820.cpp
// sym: ?FUN_00068820@C_68820@owners@@QAE_NH@Z
bool owners::C_68820::FUN_00068820(int x) {
    *((int*)((char*)this + 0x2c)) = x;
    return true;
}


// 0x00068830 FUN_00068830 (12 B): matches/0x00068830.cpp
// sym: ?FUN_00068830@Obj_68830@owners@@QAEDH@Z
char owners::Obj_68830::FUN_00068830(int v) {
    Value = v;
    return 1;
}


// 0x00068840 FUN_00068840 (12 B): matches/0x00068840.cpp
// sym: ?FUN_00068840@Obj_68840@owners@@QAE_NH@Z
bool owners::Obj_68840::FUN_00068840(int v) {
    m34 = v;
    return true;
}


// 0x00068850 FUN_00068850 (12 B): matches/0x00068850.cpp
// sym: ?FUN_00068850@Obj_68850@owners@@QAE_NH@Z
bool owners::Obj_68850::FUN_00068850(int value) {
    mValue = value;
    return true;
}


// 0x00068860 FUN_00068860 (12 B): matches/0x00068860.cpp
// sym: ?FUN_00068860@Obj_68860@owners@@QAEEI@Z
unsigned char owners::Obj_68860::FUN_00068860(unsigned int v) {
    m10 = v;
    return 1;
}


// 0x00068870 FUN_00068870 (18 B): matches/0x00068870.cpp
// sym: ?FUN_00068870@Obj_68870@owners@@QAE_NM@Z
bool owners::Obj_68870::FUN_00068870(float degrees) {
    angle = degrees * 0.017453292f;
    return true;
}


// 0x00068890 FUN_00068890 (18 B): matches/0x00068890.cpp
// sym: ?FUN_00068890@Obj_68890@owners@@QAEDM@Z
char owners::Obj_68890::FUN_00068890(float x) {
    angle = x * 0.017453292f;
    return 1;
}


// 0x000688b0 FUN_000688b0 (12 B): matches/0x000688b0.cpp
// sym: ?FUN_000688b0@Obj_688b0@owners@@QAEED@Z
unsigned char owners::Obj_688b0::FUN_000688b0(char x) {
    mVal = x;
    return 1;
}


// 0x000688c0 FUN_000688c0 (12 B): matches/0x000688c0.cpp
// sym: ?FUN_000688c0@X_688c0@owners@@QAE_NH@Z
bool owners::X_688c0::FUN_000688c0(int v) {
    m20 = v;
    return true;
}


// 0x000688d0 FUN_000688d0 (12 B): matches/0x000688d0.cpp
// sym: ?FUN_000688d0@C_688d0@owners@@QAE_NH@Z
bool owners::C_688d0::FUN_000688d0(int value) {
    m24 = value;
    return true;
}


// 0x000688e0 FUN_000688e0 (12 B): matches/0x000688e0.cpp
// sym: ?FUN_000688e0@Target_688e0@owners@@QAEDH@Z
char owners::Target_688e0::FUN_000688e0(int value) {
    m28 = value;
    return 1;
}

namespace fn_fa3ff49b {

// 0x000688f0 FUN_000688f0 (12 B): matches/0x000688f0.cpp
// sym: ?Set@O_688f0@fn_fa3ff49b@@QAEDH@Z
char O_688f0::Set(int v) {
    m1c = v;
    return 1;
}


// 0x00068900 FUN_00068900 (12 B): matches/0x00068900.cpp
// sym: ?Set@O_68900@fn_fa3ff49b@@QAE_NH@Z
bool O_68900::Set(int v) {
    m10 = v;
    return true;
}


// 0x00068910 FUN_00068910 (12 B): matches/0x00068910.cpp
// sym: ?Set@Obj_68910@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68910::Set(int x) {
    m14 = x;
    return true;
}


// 0x00068920 FUN_00068920 (12 B): matches/0x00068920.cpp
// sym: ?Fn@Obj_68920@fn_fa3ff49b@@QAEDH@Z
char Obj_68920::Fn(int a) {
    m18 = a;
    return 1;
}


// 0x00068930 FUN_00068930 (12 B): matches/0x00068930.cpp
// sym: ?SetTimeBegin_00068930@Obj_68930@fn_fa3ff49b@@QAEEH@Z
unsigned char Obj_68930::SetTimeBegin_00068930(int v) {
    m = v;
    return 1;
}


// 0x00068940 FUN_00068940 (12 B): matches/0x00068940.cpp
// sym: ?SetTimeEnd_00068940@Obj_68940@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68940::SetTimeEnd_00068940(int v) {
    m = v;
    return true;
}


// 0x00068950 FUN_00068950 (12 B): matches/0x00068950.cpp
// sym: ?SetExtensionTime_00068950@T_68950@fn_fa3ff49b@@QAE_NH@Z
bool T_68950::SetExtensionTime_00068950(int value) {
    m14 = value;
    return true;
}


// 0x00068960 FUN_00068960 (12 B): matches/0x00068960.cpp
// sym: ?Set@Obj_68960@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68960::Set(int x) {
    value = x;
    return true;
}


// 0x00068970 FUN_00068970 (12 B): matches/0x00068970.cpp
// sym: ?Set@Obj_68970@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68970::Set(int x) {
    m = x;
    return true;
}


// 0x00068980 FUN_00068980 (12 B): matches/0x00068980.cpp
// sym: ?Set@Obj_68980@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68980::Set(int arg) {
    value = arg;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00068990 FUN_00068990 (12 B): matches/0x00068990.cpp
// sym: ?FUN_00068990@Obj_68990@owners@@QAEDH@Z
char owners::Obj_68990::FUN_00068990(int v) {
    mVal = v;
    return 1;
}


// 0x000689a0 FUN_000689a0 (12 B): matches/0x000689a0.cpp
// sym: ?FUN_000689a0@X_689a0@owners@@QAEDH@Z
char owners::X_689a0::FUN_000689a0(int v) {
    *(int*)((char*)this + 0x10) = v;
    return 1;
}


// 0x000689b0 FUN_000689b0 (12 B): matches/0x000689b0.cpp
// sym: ?FUN_000689b0@X_689b0@owners@@QAE_NH@Z
bool owners::X_689b0::FUN_000689b0(int v) {
    mValue = v;
    return true;
}


// 0x000689c0 FUN_000689c0 (12 B): matches/0x000689c0.cpp
// sym: ?FUN_000689c0@Obj_689c0@owners@@QAEDH@Z
char owners::Obj_689c0::FUN_000689c0(int value) {
    mValue = value;
    return 1;
}


// 0x000689d0 FUN_000689d0 (12 B): matches/0x000689d0.cpp
// sym: ?FUN_000689d0@Obj_689d0@owners@@QAE_NH@Z
bool owners::Obj_689d0::FUN_000689d0(int v) {
    m1c = v;
    return true;
}


// 0x000689e0 FUN_000689e0 (12 B): matches/0x000689e0.cpp
// sym: ?FUN_000689e0@Obj_689e0@owners@@QAEDH@Z
char owners::Obj_689e0::FUN_000689e0(int x) {
    m10 = x;
    return 1;
}

namespace fn_fa3ff49b {

// 0x000689f0 FUN_000689f0 (26 B): matches/0x000689f0.cpp
// sym: ?Set@Obj_689f0@fn_fa3ff49b@@QAE_NPBUVec3_689f0@2@@Z
bool Obj_689f0::Set(const Vec3_689f0* p) {
    a = p->x;
    b = p->y;
    c = p->z;
    return true;
}


// 0x00068a10 FUN_00068a10 (26 B): matches/0x00068a10.cpp
// sym: ?Set@Obj_68a10@fn_fa3ff49b@@QAE_NPAUIn@2@@Z
bool Obj_68a10::Set(In* p) {
    m1 = p->a;
    m2 = p->b;
    m3 = p->c;
    return true;
}


// 0x00068a30 FUN_00068a30 (18 B): matches/0x00068a30.cpp
// sym: ?FUN_00068a30@fn_fa3ff49b@@YI_NPAUS_68a30@1@PAXM@Z
bool __fastcall FUN_00068a30(S_68a30* self, void* notUsed, float degrees) {
    self->value = degrees * 0.017453292f;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00068a50 FUN_00068a50 (18 B): matches/0x00068a50.cpp
// sym: ?FUN_00068a50@Obj_68a50@owners@@QAEDM@Z
char owners::Obj_68a50::FUN_00068a50(float a) {
    Value = a * 0.01745329238474369f;
    return 1;
}


// 0x00068a70 FUN_00068a70 (18 B): matches/0x00068a70.cpp
// sym: ?FUN_00068a70@C_68a70@owners@@QAEDM@Z
char owners::C_68a70::FUN_00068a70(float x) {
    *(float*)((char*)this + 0x40) = x * 0.0174532925f;
    return 1;
}


// 0x00068ab0 FUN_00068ab0 (18 B): matches/0x00068ab0.cpp
// sym: ?FUN_00068ab0@T_68ab0@owners@@QAEDM@Z
char owners::T_68ab0::FUN_00068ab0(float x) {
    m48 = x * 0.017453292f;
    return 1;
}


// 0x00068ad0 FUN_00068ad0 (12 B): matches/0x00068ad0.cpp
// sym: ?FUN_00068ad0@O_68ad0@owners@@QAE_NH@Z
bool owners::O_68ad0::FUN_00068ad0(int v) {
    m50 = v;
    return true;
}


// 0x00068ae0 FUN_00068ae0 (12 B): matches/0x00068ae0.cpp
// sym: ?FUN_00068ae0@Obj_68ae0@owners@@QAEDH@Z
char owners::Obj_68ae0::FUN_00068ae0(int value) {
    mValue = value;
    return 1;
}


// 0x00068af0 FUN_00068af0 (12 B): matches/0x00068af0.cpp
// sym: ?FUN_00068af0@Obj_68af0@owners@@QAE_NH@Z
bool owners::Obj_68af0::FUN_00068af0(int x) {
    value = x;
    return true;
}


// 0x00068b00 FUN_00068b00 (12 B): matches/0x00068b00.cpp
// sym: ?FUN_00068b00@Obj_68b00@owners@@QAE_NH@Z
bool owners::Obj_68b00::FUN_00068b00(int v) {
    m5c = v;
    return true;
}


// 0x00068b10 FUN_00068b10 (12 B): matches/0x00068b10.cpp
// sym: ?FUN_00068b10@Obj_68b10@owners@@QAEDH@Z
char owners::Obj_68b10::FUN_00068b10(int v) {
    value = v;
    return 1;
}


// 0x00068b20 FUN_00068b20 (12 B): matches/0x00068b20.cpp
// sym: ?FUN_00068b20@Obj_68b20@owners@@QAEDPAX@Z
char owners::Obj_68b20::FUN_00068b20(void* p) {
    mValue = p;
    return 1;
}


// 0x00068b30 FUN_00068b30 (12 B): matches/0x00068b30.cpp
// sym: ?FUN_00068b30@Obj_68b30@owners@@QAE_NH@Z
bool owners::Obj_68b30::FUN_00068b30(int x) {
    m = x;
    return true;
}

namespace fn_fa3ff49b {

// 0x00068b40 FUN_00068b40 (12 B): matches/0x00068b40.cpp
// sym: ?SetTimeBegin_00068b40@Obj_68b40@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68b40::SetTimeBegin_00068b40(int v) {
    mVal = v;
    return true;
}


// 0x00068b50 FUN_00068b50 (12 B): matches/0x00068b50.cpp
// sym: ?SetTimeEnd_00068b50@Obj_68b50@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68b50::SetTimeEnd_00068b50(int x) {
    value = x;
    return true;
}


// 0x00068b60 FUN_00068b60 (4 B): matches/0x00068b60.cpp
// sym: ?GetHint_00068b60@Obj_68b60@fn_fa3ff49b@@QAEPAUSub_68b60@2@XZ
Sub_68b60* Obj_68b60::GetHint_00068b60() {
    return (Sub_68b60*)((char*)this + 0x18);
}

} // namespace fn_fa3ff49b

// 0x00068b70 FUN_00068b70 (12 B): matches/0x00068b70.cpp
// sym: ?FUN_00068b70@Obj_68b70@owners@@QAEDH@Z
char owners::Obj_68b70::FUN_00068b70(int arg) {
    m = arg;
    return 1;
}


// 0x00068b80 FUN_00068b80 (12 B): matches/0x00068b80.cpp
// sym: ?FUN_00068b80@Obj_68b80@owners@@QAE_NH@Z
bool owners::Obj_68b80::FUN_00068b80(int v) {
    mValue = v;
    return true;
}

namespace fn_fa3ff49b {

// 0x00068b90 FUN_00068b90 (12 B): matches/0x00068b90.cpp
// sym: ?SetTimeBegin_00068b90@C_68b90@fn_fa3ff49b@@QAE_NH@Z
bool C_68b90::SetTimeBegin_00068b90(int x) {
    mVal = x;
    return true;
}


// 0x00068ba0 FUN_00068ba0 (12 B): matches/0x00068ba0.cpp
// sym: ?SetTimeEnd_00068ba0@Obj_68ba0@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68ba0::SetTimeEnd_00068ba0(int v) {
    m10 = v;
    return true;
}


// 0x00068bb0 FUN_00068bb0 (12 B): matches/0x00068bb0.cpp
// sym: ?SetHeight_00068bb0@Obj_68bb0@fn_fa3ff49b@@QAE_NH@Z
bool Obj_68bb0::SetHeight_00068bb0(int v) {
    m = v;
    return true;
}

} // namespace fn_fa3ff49b

// 0x00068bc0 FUN_00068bc0 (12 B): matches/0x00068bc0.cpp
// sym: ?FUN_00068bc0@X_68bc0@owners@@QAE_NH@Z
bool owners::X_68bc0::FUN_00068bc0(int a) {
    mValue = a;
    return true;
}


// 0x00068bd0 FUN_00068bd0 (12 B): matches/0x00068bd0.cpp
// sym: ?FUN_00068bd0@A_68bd0@owners@@QAE_NH@Z
bool owners::A_68bd0::FUN_00068bd0(int x) {
    m10 = x;
    return true;
}


// 0x00068be0 FUN_00068be0 (12 B): matches/0x00068be0.cpp
// sym: ?FUN_00068be0@C_68be0@owners@@QAEDH@Z
char owners::C_68be0::FUN_00068be0(int x) {
    m14 = x;
    return 1;
}


// 0x00068bf0 FUN_00068bf0 (12 B): matches/0x00068bf0.cpp
// sym: ?FUN_00068bf0@Obj_68bf0@owners@@QAE_NH@Z
bool owners::Obj_68bf0::FUN_00068bf0(int v) {
    field = v;
    return true;
}


// 0x00068c00 FUN_00068c00 (12 B): matches/0x00068c00.cpp
// sym: ?FUN_00068c00@Obj_68c00@owners@@QAE_NH@Z
bool owners::Obj_68c00::FUN_00068c00(int v) {
    mValue = v;
    return true;
}


// 0x00068c10 FUN_00068c10 (12 B): matches/0x00068c10.cpp
// sym: ?FUN_00068c10@Obj_68c10@owners@@QAE_NH@Z
bool owners::Obj_68c10::FUN_00068c10(int x) {
    m20 = x;
    return true;
}


// 0x00068c20 FUN_00068c20 (12 B): matches/0x00068c20.cpp
// sym: ?FUN_00068c20@Obj_68c20@owners@@QAEDH@Z
char owners::Obj_68c20::FUN_00068c20(int value) {
    *((int*)((char*)this + 0x24)) = value;
    return 1;
}


// 0x00068c30 FUN_00068c30 (12 B): matches/0x00068c30.cpp
// sym: ?FUN_00068c30@X_68c30@owners@@QAEDH@Z
char owners::X_68c30::FUN_00068c30(int a) {
    m28 = a;
    return 1;
}


// 0x00068c40 FUN_00068c40 (12 B): matches/0x00068c40.cpp
// sym: ?FUN_00068c40@Obj_68c40@owners@@QAEEH@Z
unsigned char owners::Obj_68c40::FUN_00068c40(int x) {
    *(int*)((char*)this + 0x2c) = x;
    return 1;
}


// 0x00068c50 FUN_00068c50 (12 B): matches/0x00068c50.cpp
// sym: ?FUN_00068c50@Obj_68c50@owners@@QAEDH@Z
char owners::Obj_68c50::FUN_00068c50(int v) {
    *(int*)((char*)this + 12) = v;
    return 1;
}


// 0x00068c60 FUN_00068c60 (12 B): matches/0x00068c60.cpp
// sym: ?FUN_00068c60@Obj_68c60@owners@@QAEEH@Z
unsigned char owners::Obj_68c60::FUN_00068c60(int v) {
    mValue = v;
    return 1;
}


// 0x00068c70 FUN_00068c70 (11 B): matches/0x00068c70.cpp [wrapped: conflict: CEffectStopTrack]
// sym: ?FUN_00068c70@fn_00068c70@@YIXPAVCEffectStopTrack@1@@Z
namespace fn_00068c70 {
// Same code shape as 0x00060920 (propagated; names are from that function)
extern int hulk_at_003f98d0;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_00236d60(CEffectStopTrack*);
void __fastcall FUN_00068c70(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&hulk_at_003f98d0;
    FUN_00236d60(self);
}
} // namespace fn_00068c70

