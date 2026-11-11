// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018cab0..0x0018ecb0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TimerCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1f11990 {
#define TREE_TU_END }
namespace fn_f1f11990 {} using namespace fn_f1f11990;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f1f11990 {
class A_18cb20 {
  public:
    char pad[0x10];
    struct X_18cb20* Get();
};
struct X_18cb20 {};
class Obj_18cb30 {
    char pad[0x18];
    int m18;

  public:
    bool Set(int x);
};
class Obj_18cb40 {
  public:
    char pad[0x1c];
    void* m1c;
    bool Set(void* p);
};
struct Obj_18cb50 {
    char pad[0x10];
    int* GetVariable_0018cb50();
};
class Obj_18cb60 {
    char pad[0x18];

  public:
    char SetCompare_0018cb60(int v);
};
class Obj_18cb70 {
  public:
    char pad[0x1c];
    int value;
    char SetValue_0018cb70(int x);
};
class Obj_18cb80 {
  public:
    char pad[0xc];
    int mValue;
    bool SetTimeBegin_0018cb80(int x);
};
class Obj_18cba0 {
  public:
    char pad[0x10];
    int field;
    bool SetTimer_0018cba0(int value);
};
class Obj_18cbc0 {
  public:
    char pad[0x14];
    int mVal;
    char SetValue_0018cbc0(int v);
};
extern int* hulk_at_004e1508;
class CCondition_18cc90 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1510;
class CCondition_18cd00 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_0041aa68[];
class Str_18cd40 {
  public:
    void Init_0027af50();
};
class Condition_18cd40 {
  public:
    void* vptr;
    char pad[12];
    Str_18cd40 s;
    void Fin_002345b0();
};
class GrappleVarCompareCondition_18cd40 : public Condition_18cd40 {
  public:
    ~GrappleVarCompareCondition_18cd40();
};
extern int* hulk_at_004e1518;
class CCondition_18cd80 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_0041aa88[];
class Str_18cdc0 {
  public:
    void Init_0027af50();
};
class Condition_18cdc0 {
  public:
    void* vptr;
    char pad[12];
    Str_18cdc0 s;
    void Fin_002345b0();
};
class VarCompareCondition_18cdc0 : public Condition_18cdc0 {
  public:
    ~VarCompareCondition_18cdc0();
};
extern int* hulk_at_004e1520;
class CCondition_18ce00 {
  public:
    virtual int vfunc_0(int);
};
class Track_18ce10 {
  public:
    Track_18ce10();
    virtual void f();
    char pad[8];
};
class TimerSetTrack : public Track_18ce10 {
  public:
    TimerSetTrack();
    virtual void f();
    int a, b, c;
};
extern int* hulk_at_004e1528;
class CCondition_18ce90 {
  public:
    virtual int vfunc_0(int);
};
class Track_18cea0 {
  public:
    Track_18cea0();
    virtual void f();
    char pad[4];
    int n;
};
class Part {
  public:
    Part();
    char pad[8];
};
class VarAssignTrack : public Track_18cea0 {
  public:
    VarAssignTrack();
    virtual void f();
    int a;
    Part part;
    int b, c, d;
    char flag;
};
extern void* hulk_at_0041aad8[];
struct Sub_18cf00 {
    void Fin_0027af50() throw();
};
class Track_18cf00 {
  public:
    void* vptr;
    ~Track_18cf00() throw();
};
class VarAssignTrack_18cf00 : public Track_18cf00 {
  public:
    char pad[0x10 - 4];
    Sub_18cf00 sub;
    ~VarAssignTrack_18cf00() throw();
};
struct Key_18d0d0 { char data[8]; };
struct Config_18d0d0 { char pad[16]; Key_18d0d0 key; unsigned op; unsigned unused; int value; unsigned char enabled; };
struct Vars {  void FUN_00036e70(Key_18d0d0*, int); };
struct Context_18d0d0 { Vars* FUN_00059a30(); };
struct Owner_18d0d0 {  };
class HelperA_18d280 {
  public:
    void* run_000592a0();
};
class HelperB_18d280 {
  public:
    void* run_00059a30();
};
extern void* hulk_at_0041aa48[];
class Condition_18d300 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class TimerCondition_18d300 : public Condition_18d300 {
  public:
    TimerCondition_18d300* vfunc_5(signed char flags);
};
extern char threat_vftable_18d330;
struct TimerCondition_nv_18d330 {
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(hulkfight::motion::TimerCondition*);
class GrappleVarCompareCondition_18d330 {
  public:
    void* vftable;
    char pad[0x0c];
    GrappleVarCompareCondition_18d330* vfunc_5(unsigned char);
};
extern char threat_vftable_18d360;
struct TimerCondition_nv_18d360 {
    void f1_0027af50();
    void f2_002345b0();
};
class VarCompareCondition_18d360 {
  public:
    void* vftable;
    char pad[0x0c];
    VarCompareCondition_18d360* vfunc_5(unsigned char);
};
extern void* hulk_at_0041aaa8[];
class Track_18d390 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class TimerSetTrack_18d390 : public Track_18d390 {
  public:
    TimerSetTrack_18d390* vfunc_5(signed char flags);
};
extern char threat_vftable_18d3c0;
struct Obj_18d3c0 {
    int x;
    void f1_0027af50();
    void f2_00236d60();
};
extern void thunk_FUN_00267090(Obj_18d3c0*);
class VarAssignTrack_18d3c0 {
  public:
    void* vftable;
    char pad[0x0c];
    VarAssignTrack_18d3c0* vfunc_5(unsigned char);
};
class RefObj_18d3f0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_18d3f0 {
  public:
    Action_18d3f0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class VarAssignAction_18d3f0 : public Action_18d3f0 {
  public:
    int mTarget;
    RefObj_18d3f0* mObj;
    VarAssignAction_18d3f0(int target, RefObj_18d3f0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_0041ab08[];
class Ref_18d440 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_18d440 {
  public:
    void* vptr;
};
class VarAssignAction_18d440 : public Action_18d440 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_18d440* m20;
    ~VarAssignAction_18d440();
};
struct Timing_18d480 {
    char pad0[0x1e60];
    float values[14];
    unsigned char valid[14];
    float FUN_0003eca0(const char* name);
};
struct Clock_18d480 {
    Timing_18d480* FUN_00059a30();
};
} // namespace fn_f1f11990
namespace fight {
class Params_18d480 {
public:
    virtual void vfunc_0();
    char pad4[4];
    Clock_18d480* FUN_000592a0();
};
}
namespace fn_f1f11990 {
class CFightParams_18d480 : public fight::Params_18d480 {
public:
    virtual void vfunc_0();
};
extern "C" bool FUN_00018960(float a, float b, float eps);
class TimerCondition {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int a, fight::Params_18d480* params, int c);
    char pad04[8];
    int index;
    int mode;
    float limit;
    char useNamed;
    char pad19[3];
    int nameIndex;
};
class RefObj_18d610 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_18d610 {
  public:
    Action_18d610();
    virtual void Update_00018b30();
    char pad[0x18];
};
class TimerSetAction_18d610 : public Action_18d610 {
  public:
    int mTarget;
    RefObj_18d610* mObj;
    TimerSetAction_18d610(int target, RefObj_18d610* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_0041ab24[];
class Ref_18d660 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_18d660 {
  public:
    void* vptr;
};
class TimerSetAction_18d660 : public Action_18d660 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_18d660* m20;
    ~TimerSetAction_18d660();
};
class CStageCondition_18d6e0;
class ParamValue_18d6e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18d6e0 : public ParamValue_18d6e0 {
  public:
    int pad;
};
struct CAxisArcCondition_18d720;
class CStageCondition_18d730 {};
class ParamValue_18d730 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_18d730 : public ParamValue_18d730 {
  public:
    virtual void f();
};
class CStageCondition_18d7c0;
class ParamValue_18d7c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18d7c0 : public ParamValue_18d7c0 {
  public:
    int pad;
};
class CStageCondition_18d810;
class ParamValue_18d810 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18d810 : public ParamValue_18d810 {
  public:
    int pad;
};
struct CAxisArcCondition_18d850;
class CStageCondition_18d860 {};
class ParamValue_18d860 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_18d860 : public ParamValue_18d860 {
  public:
    virtual void f();
};
class CStageCondition_18d8f0;
class ParamValue_18d8f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18d8f0 : public ParamValue_18d8f0 {
  public:
    int pad;
};
struct CAxisArcCondition_18d930;
class CStageCondition_18d940 {};
class ParamValue_18d940 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_18d940 : public ParamValue_18d940 {
  public:
    virtual void f();
};
class CStageCondition_18d9d0;
class ParamValue_18d9d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18d9d0 : public ParamValue_18d9d0 {
  public:
    int pad;
};
class CStageCondition_18da20;
class ParamValue_18da20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18da20 : public ParamValue_18da20 {
  public:
    int pad;
};
class CStageCondition_18da70;
class ParamValue_18da70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18da70 : public ParamValue_18da70 {
  public:
    int pad;
};
class CStageCondition_18dac0;
class ParamValue_18dac0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18dac0 : public ParamValue_18dac0 {
  public:
    int pad;
};
struct CAxisArcCondition_18db00;
class CStageCondition_18db10 {};
class ParamValue_18db10 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_18db10 : public ParamValue_18db10 {
  public:
    virtual void f();
};
class CStageCondition_18dba0;
class ParamValue_18dba0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18dba0 : public ParamValue_18dba0 {
  public:
    int pad;
};
class CStageCondition_18dbf0;
class ParamValue_18dbf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18dbf0 : public ParamValue_18dbf0 {
  public:
    int pad;
};
} // namespace fn_f1f11990
namespace hulkfight { namespace motion {
class TimerCondition_18dc10;
} }
namespace fight {
class ConditionFactoryCaster_18dc10 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f1f11990 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004bf228;
} // namespace fn_f1f11990
namespace fight {
class ConditionFactoryCaster_18dd50 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class VarCompareCondition_18dd50 {};
} }
namespace fn_f1f11990 {
extern char DAT_004bf3a8;
extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004bf458;
} // namespace fn_f1f11990
namespace fight {
class TrackFactoryCaster_18ddd0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TimerSetTrack_18ddd0;
} }
namespace hulkfight { namespace motion {
class VarAssignTrack_18de50 {};
} }
namespace fn_f1f11990 {
struct TypeRecord {
    void* vtable;
};
extern const TypeRecord hulk_at_004bf500;
extern const TypeRecord hulk_at_0049850c;
} // namespace fn_f1f11990
namespace fight {
class TrackFactoryCaster_18de50 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f1f11990 {
struct RefCounted_18e190 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_18e190[];
class VarAssignAction_18e190 {
  public:
    VarAssignAction_18e190* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_18e190* m_20;
};
struct RefCounted_18e230 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_18e230[];
class TimerSetAction_18e230 {
  public:
    TimerSetAction_18e230* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_18e230* m_20;
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class VarCaster {
  public:
    virtual bool Fnf_0018de50(void*);
};
class TrackFactoryCasterTemplate_18e8d0 {
  public:
    virtual bool Fnf_0018ddd0(void*);
};
extern "C" void* FUN_00236ac0(const char*, void*);
class Factory {
  public:
    void add_002367c0(void*);
};
extern int hulk_at_0041ae28;
struct ConditionFactoryTemplate_18e9a0 {
    void* m_vptr;
    void base1_dtor_0018cc70();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_0041aaa8[];
struct TimerSetTrack_18ea10 {
    hulk_intptr vptr;
    int pad4;
    int m8;
    int mc;
    int m10;
    int m14;
    void Init_00236d40();
};
extern "C" void* __cdecl Allocate(unsigned int);
extern int hulk_at_0041ae44;
extern int hulk_at_0041ae60;
struct ConditionFactoryTemplate_18eb10 {
    void* m_vptr;
    void base1_dtor_0018cce0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class Sub {
  public:
    Sub();
};
extern char VT_18eb80[];
extern void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_0041ae7c;
struct ConditionFactoryTemplate_18ebc0 {
    void* m_vptr;
    void base1_dtor_0018cd60();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
} // namespace fn_f1f11990
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace hulkfight { namespace motion {
class Base {
  public:
    Base() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    int count;
    int flag;
};
} }
namespace hulkfight { namespace motion {
class Elem {
  public:
    Elem() throw();
    int a, b;
};
} }
namespace hulkfight { namespace motion {
class VarAssignTrack_18ec30 : public Base {
  public:
    VarAssignTrack_18ec30() throw() : x(0), elem(), p(0), q(0), r(0), v(0) { flag = 1; }
    virtual void a();
    virtual void b();
    virtual void c();
    int x;
    Elem elem;
    int p, q, r;
    char v;
};
} }


// 0x0018cab0 FUN_0018cab0 (12 B): matches/0x0018cab0.cpp
// sym: ?FUN_0018cab0@Obj_18cab0@owners@@QAEDH@Z
char owners::Obj_18cab0::FUN_0018cab0(int a) {
    mValue = a;
    return 1;
}


// 0x0018cac0 FUN_0018cac0 (12 B): matches/0x0018cac0.cpp
// sym: ?FUN_0018cac0@X_18cac0@owners@@QAEDI@Z
char owners::X_18cac0::FUN_0018cac0(unsigned int v) {
    m = v;
    return 1;
}


// 0x0018cad0 FUN_0018cad0 (12 B): matches/0x0018cad0.cpp
// sym: ?FUN_0018cad0@Obj_18cad0@owners@@QAE_NH@Z
bool owners::Obj_18cad0::FUN_0018cad0(int x) {
    mVal = x;
    return true;
}


// 0x0018caf0 FUN_0018caf0 (12 B): matches/0x0018caf0.cpp
// sym: ?FUN_0018caf0@X_18caf0@owners@@QAEDD@Z
char owners::X_18caf0::FUN_0018caf0(char c) {
    m18 = c;
    return 1;
}


// 0x0018cb10 FUN_0018cb10 (12 B): matches/0x0018cb10.cpp
// sym: ?FUN_0018cb10@Obj_18cb10@owners@@QAEDH@Z
char owners::Obj_18cb10::FUN_0018cb10(int x) {
    mVal = x;
    return 1;
}

namespace fn_f1f11990 {

// 0x0018cb20 FUN_0018cb20 (4 B): matches/0x0018cb20.cpp
// sym: ?Get@A_18cb20@fn_f1f11990@@QAEPAUX_18cb20@2@XZ
X_18cb20* A_18cb20::Get() {
    return (X_18cb20*)((char*)this + 0x10);
}


// 0x0018cb30 FUN_0018cb30 (12 B): matches/0x0018cb30.cpp
// sym: ?Set@Obj_18cb30@fn_f1f11990@@QAE_NH@Z
bool Obj_18cb30::Set(int x) {
    m18 = x;
    return true;
}


// 0x0018cb40 FUN_0018cb40 (12 B): matches/0x0018cb40.cpp
// sym: ?Set@Obj_18cb40@fn_f1f11990@@QAE_NPAX@Z
bool Obj_18cb40::Set(void* p) {
    m1c = p;
    return true;
}


// 0x0018cb50 FUN_0018cb50 (4 B): matches/0x0018cb50.cpp
// sym: ?GetVariable_0018cb50@Obj_18cb50@fn_f1f11990@@QAEPAHXZ
int* Obj_18cb50::GetVariable_0018cb50() {
    return (int*)((char*)this + 0x10);
}


// 0x0018cb60 FUN_0018cb60 (12 B): matches/0x0018cb60.cpp
// sym: ?SetCompare_0018cb60@Obj_18cb60@fn_f1f11990@@QAEDH@Z
char Obj_18cb60::SetCompare_0018cb60(int v) {
    *(int*)((char*)this + 0x18) = v;
    return 1;
}


// 0x0018cb70 FUN_0018cb70 (12 B): matches/0x0018cb70.cpp
// sym: ?SetValue_0018cb70@Obj_18cb70@fn_f1f11990@@QAEDH@Z
char Obj_18cb70::SetValue_0018cb70(int x) {
    value = x;
    return 1;
}


// 0x0018cb80 FUN_0018cb80 (12 B): matches/0x0018cb80.cpp
// sym: ?SetTimeBegin_0018cb80@Obj_18cb80@fn_f1f11990@@QAE_NH@Z
bool Obj_18cb80::SetTimeBegin_0018cb80(int x) {
    mValue = x;
    return 1;
}


// 0x0018cba0 FUN_0018cba0 (12 B): matches/0x0018cba0.cpp
// sym: ?SetTimer_0018cba0@Obj_18cba0@fn_f1f11990@@QAE_NH@Z
bool Obj_18cba0::SetTimer_0018cba0(int value) {
    field = value;
    return 1;
}


// 0x0018cbc0 FUN_0018cbc0 (12 B): matches/0x0018cbc0.cpp
// sym: ?SetValue_0018cbc0@Obj_18cbc0@fn_f1f11990@@QAEDH@Z
char Obj_18cbc0::SetValue_0018cbc0(int v) {
    mVal = v;
    return 1;
}

} // namespace fn_f1f11990

// 0x0018cbd0 FUN_0018cbd0 (12 B): matches/0x0018cbd0.cpp
// sym: ?FUN_0018cbd0@O_18cbd0@owners@@QAEDH@Z
char owners::O_18cbd0::FUN_0018cbd0(int x) {
    m = x;
    return 1;
}


// 0x0018cbe0 FUN_0018cbe0 (4 B): matches/0x0018cbe0.cpp
// sym: ?FUN_0018cbe0@Obj_18cbe0@owners@@QAEPADXZ
char* owners::Obj_18cbe0::FUN_0018cbe0() {
    return (char*)this + 0x10;
}


// 0x0018cc00 FUN_0018cc00 (12 B): matches/0x0018cc00.cpp
// sym: ?FUN_0018cc00@Obj_18cc00@owners@@QAEEH@Z
unsigned char owners::Obj_18cc00::FUN_0018cc00(int value) {
    mValue = value;
    return 1;
}


// 0x0018cc20 FUN_0018cc20 (12 B): matches/0x0018cc20.cpp
// sym: ?FUN_0018cc20@O_18cc20@owners@@QAE_NH@Z
bool owners::O_18cc20::FUN_0018cc20(int a) {
    m = a;
    return true;
}


// 0x0018cc40 FUN_0018cc40 (12 B): matches/0x0018cc40.cpp
// sym: ?FUN_0018cc40@Obj_18cc40@owners@@QAEDH@Z
char owners::Obj_18cc40::FUN_0018cc40(int a) {
    *(volatile int*)&m20 = a;
    return 1;
}


// 0x0018cc60 FUN_0018cc60 (12 B): matches/0x0018cc60.cpp
// sym: ?FUN_0018cc60@Obj_18cc60@owners@@QAEDD@Z
char owners::Obj_18cc60::FUN_0018cc60(char v) {
    m24 = v;
    return 1;
}

namespace fn_f1f11990 {

// 0x0018cc70 FUN_0018cc70 (19 B): matches/0x0018cc70.cpp
// sym: ?FUN_0018cc70@fn_f1f11990@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0018cc70() {
    FUN_00234810(((char*)&DAT_004e1508), ((char*)&DAT_004e150c));
}

} // namespace fn_f1f11990

// 0x0018cc90 hulkfight::motion::TimerCondition::vfunc_0 (16 B): matches/0x0018cc90.cpp
// sym: ?vfunc_0@TimerCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TimerCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1508;
    return p[index];
}

namespace fn_f1f11990 {

// 0x0018cce0 FUN_0018cce0 (19 B): matches/0x0018cce0.cpp
// sym: ?FUN_0018cce0@fn_f1f11990@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0018cce0() {
    FUN_00234810(((char*)&DAT_004e1510), ((char*)&DAT_004e1514));
}

} // namespace fn_f1f11990

// 0x0018cd00 hulkfight::motion::GrappleVarCompareCondition::vfunc_0 (16 B): matches/0x0018cd00.cpp
// sym: ?vfunc_0@GrappleVarCompareCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleVarCompareCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1510;
    return p[index];
}

namespace fn_f1f11990 {

// 0x0018cd40 FUN_0018cd40 (25 B): matches/0x0018cd40.cpp
// sym: ??1GrappleVarCompareCondition_18cd40@fn_f1f11990@@QAE@XZ
GrappleVarCompareCondition_18cd40::~GrappleVarCompareCondition_18cd40() {
    vptr = hulk_at_0041aa68;
    s.Init_0027af50();
    Fin_002345b0();
}


// 0x0018cd60 FUN_0018cd60 (19 B): matches/0x0018cd60.cpp
// sym: ?FUN_0018cd60@fn_f1f11990@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0018cd60() {
    FUN_00234810(((char*)&DAT_004e1518), ((char*)&DAT_004e151c));
}

} // namespace fn_f1f11990

// 0x0018cd80 hulkfight::motion::VarCompareCondition::vfunc_0 (16 B): matches/0x0018cd80.cpp
// sym: ?vfunc_0@VarCompareCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VarCompareCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1518;
    return p[index];
}

namespace fn_f1f11990 {

// 0x0018cdc0 FUN_0018cdc0 (25 B): matches/0x0018cdc0.cpp
// sym: ??1VarCompareCondition_18cdc0@fn_f1f11990@@QAE@XZ
VarCompareCondition_18cdc0::~VarCompareCondition_18cdc0() {
    vptr = hulk_at_0041aa88;
    s.Init_0027af50();
    Fin_002345b0();
}


// 0x0018cde0 FUN_0018cde0 (19 B): matches/0x0018cde0.cpp
// sym: ?FUN_0018cde0@fn_f1f11990@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0018cde0() {
    FUN_00234810(((char*)&DAT_004e1520), ((char*)&DAT_004e1524));
}

} // namespace fn_f1f11990

// 0x0018ce00 hulkfight::motion::TimerSetTrack::vfunc_0 (16 B): matches/0x0018ce00.cpp
// sym: ?vfunc_0@TimerSetTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TimerSetTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1520;
    return p[index];
}

namespace fn_f1f11990 {

// 0x0018ce10 FUN_0018ce10 (36 B): matches/0x0018ce10.cpp
// sym: ??0TimerSetTrack@fn_f1f11990@@QAE@XZ
TimerSetTrack::TimerSetTrack() : Track_18ce10() {
    a = 0;
    b = 0;
    c = 0;
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_f1f11990

// 0x0018ce40 hulkfight::motion::TimerSetTrack::vfunc_6 (4 B): matches/0x0018ce40.cpp
// sym: ?vfunc_6@TimerSetTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::TimerSetTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0018ce50 hulkfight::motion::TimerSetTrack::vfunc_7 (7 B): matches/0x0018ce50.cpp
// sym: ?vfunc_7@TimerSetTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::TimerSetTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f1f11990 {

// 0x0018ce70 FUN_0018ce70 (19 B): matches/0x0018ce70.cpp
// sym: ?FUN_0018ce70@fn_f1f11990@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0018ce70() {
    FUN_00234810(((char*)&DAT_004e1528), ((char*)&DAT_004e152c));
}

} // namespace fn_f1f11990

// 0x0018ce90 hulkfight::motion::VarAssignTrack::vfunc_0 (16 B): matches/0x0018ce90.cpp
// sym: ?vfunc_0@VarAssignTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VarAssignTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1528;
    return p[index];
}

namespace fn_f1f11990 {

// 0x0018cea0 FUN_0018cea0 (52 B): matches/0x0018cea0.cpp
// sym: ??0VarAssignTrack@fn_f1f11990@@QAE@XZ
VarAssignTrack::VarAssignTrack() : Track_18cea0(), a(0), part(), b(0), c(0), d(0), flag(0) {
    n = 1;
}

} // namespace fn_f1f11990

// 0x0018cee0 hulkfight::motion::VarAssignTrack::vfunc_6 (4 B): matches/0x0018cee0.cpp
// sym: ?vfunc_6@VarAssignTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::VarAssignTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0018cef0 hulkfight::motion::VarAssignTrack::vfunc_7 (7 B): matches/0x0018cef0.cpp
// sym: ?vfunc_7@VarAssignTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::VarAssignTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f1f11990 {

// 0x0018cf00 FUN_0018cf00 (25 B): matches/0x0018cf00.cpp
// sym: ??1VarAssignTrack_18cf00@fn_f1f11990@@QAE@XZ
VarAssignTrack_18cf00::~VarAssignTrack_18cf00() throw() {
    vptr = hulk_at_0041aad8;
    sub.Fin_0027af50();
}

} // namespace fn_f1f11990

// 0x0018cf60 hulkfight::motion::VarCompareCondition::vfunc_6 (169 B): equivalent/0x0018cf60.cpp [wrapped: conflict: FUN_00344e74; hulkfight::motion::VarCompareCondition]
// sym: ?vfunc_6@VarCompareCondition@motion@hulkfight@fn_0018cf60@@QAE_NPAXPAUParams@4@0@Z @6d87c459d534 @w6ee2aea4bd98
namespace fn_0018cf60 {
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 22/22)
// hulkfight::motion::VarCompareCondition::vfunc_6 @ 0x0018cf60
extern char DAT_00494b44;
extern char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Key_18cf60 { char data[8]; };
struct Values_18cf60 { int FUN_00036e40(Key_18cf60*); };
struct State_18cf60 { Values_18cf60* FUN_00059a30(); };
struct Params { State_18cf60* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct VarCompareCondition {
 char padding[16];
 Key_18cf60 key;
 unsigned comparison;
 int threshold;
 bool vfunc_6(void*, Params*, void*);
};
bool VarCompareCondition::vfunc_6(void*, Params* params, void*) {
 if (!FUN_00344e74(params,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_18cf60* state = params->FUN_000592a0();
 Values_18cf60* values = state->FUN_00059a30();
 int value = values->FUN_00036e40(&key);
 switch(comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return value == threshold;
 case 3: return value != threshold;
 case 4: return value >= threshold;
 case 5: return value > threshold;
 }
 return false;
}
}}
} // namespace fn_0018cf60


// 0x0018d030 hulkfight::motion::GrappleVarCompareCondition::vfunc_6 (133 B): equivalent/0x0018d030.cpp [wrapped: conflict: hulkfight::motion::GrappleVarCompareCondition]
// sym: ?vfunc_6@GrappleVarCompareCondition@motion@hulkfight@fn_0018d030@@QAE_NHPAXH@Z @ed93355330a9 @wa4c354ccb656
namespace fn_0018d030 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 22/22)
// hulkfight::motion::GrappleVarCompareCondition::vfunc_6 @ 0x0018d030
struct Key_18d030 {
    unsigned int lo;
    unsigned int hi;
};

struct Grappler {
    int FUN_00036e40(Key_18d030 *key);
};
extern "C" Grappler *__cdecl FUN_00048260(void *owner);

namespace hulkfight {
namespace motion {

class GrappleVarCompareCondition {
public:
    virtual void vfunc_0();
    char pad04[0xc];
    Key_18d030 variable;
    int op;
    int value;
    bool vfunc_6(int a, void *owner, int c);
};

bool GrappleVarCompareCondition::vfunc_6(int a, void *owner, int c)
{
    Grappler *g = FUN_00048260(owner);
    if (g == 0)
        return false;
    int v = g->FUN_00036e40(&variable);
    int rhs = value;
    switch (op) {
    case 0: return v < rhs;
    case 1: return v <= rhs;
    case 2: return v == rhs;
    case 3: return v != rhs;
    case 4: return v >= rhs;
    case 5: return v > rhs;
    }
    return false;
}

}
}
} // namespace fn_0018d030


// 0x0018d0d0 hulkfight::motion::VarAssignAction::vfunc_4 (199 B): equivalent/0x0018d0d0.cpp
// sym: ?vfunc_4@VarAssignAction@motion@hulkfight@@UAEXXZ @b828ca984780 @w4dc57146c769
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 18/18)
// hulkfight::motion::VarAssignAction::vfunc_4 @ 0x0018d0d0
void hulkfight::motion::VarAssignAction::vfunc_4() {
 Vars* vars = ((Context_18d0d0 *)((owners::Object_592a0 *)((*(Owner_18d0d0 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
 if (!(*(Config_18d0d0 * *)&this->f_1c)->enabled) return;
 int current = ((int)((owners::Obj_36e40 *)vars)->FUN_00036e40((hulk_uintptr)(Key_18d0d0 *)(&(*(Config_18d0d0 * *)&this->f_1c)->key)));
 Config_18d0d0* c = (*(Config_18d0d0 * *)&this->f_1c);
 int v = c->value;
 int result;
 switch(c->op) {
 case 0: result = v; break;
 case 1: result = (int)((unsigned)current + (unsigned)v); break;
 case 2: result = (int)((unsigned)current - (unsigned)v); break;
 case 3: result = (int)((unsigned)current * (unsigned)v); break;
 case 4: result = v ? current / v : 0; break;
 case 5: result = v ? current % v : 0; break;
 case 6: result = (int)((unsigned)current + 1); if(v) result %= v; break;
 case 7: result = (int)((unsigned)current + (unsigned)v - 1); if(v) result %= v; break;
 default: return;
 }
 vars->FUN_00036e70(&c->key, result);
}


// 0x0018d1c0 hulkfight::motion::VarAssignAction::vfunc_3 (147 B): equivalent/0x0018d1c0.cpp [wrapped: conflict: hulkfight::motion::VarAssignAction]
// sym: ?vfunc_3@VarAssignAction@motion@hulkfight@fn_0018d1c0@@UAEDHH@Z @016c64d2e077 @w138868625866
namespace fn_0018d1c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 18/18)
// hulkfight::motion::VarAssignAction::vfunc_3 @ 0x0018d1c0
struct Name_18d1c0 {
    int lo, hi;
};

struct VarAssign {
    char pad0[0x10];
    Name_18d1c0 name;              // 0x10
    unsigned int op;        // 0x18
    int operand;            // 0x1c
    char pad20[4];
    char result;            // 0x24
};

struct Character_18d1c0 {
    int FUN_00036e40(const Name_18d1c0 *name);
    void FUN_00036e70(const Name_18d1c0 *name, int value);
};

struct Slot_18d1c0 {
    Character_18d1c0 *FUN_00059a30();
};

struct Owner_18d1c0 {
    Slot_18d1c0 *FUN_000592a0();
};

namespace hulkfight { namespace motion {
class VarAssignAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a, int b);

    char pad4[0x1c - 4];
    VarAssign *assign;      // 0x1c
    Owner_18d1c0 *owner;           // 0x20
};

char VarAssignAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return 0;

    Character_18d1c0 *c = owner->FUN_000592a0()->FUN_00059a30();
    int value = c->FUN_00036e40(&assign->name);
    VarAssign *va = assign;
    int operand = va->operand;
    switch (va->op) {
    case 0:
        value = operand;
        break;
    case 1:
        value = value + operand;
        break;
    case 2:
        value = value - operand;
        break;
    case 3:
        value = value * operand;
        break;
    case 4:
        value = (operand != 0) ? value / operand : 0;
        break;
    case 5:
        value = (operand != 0) ? value % operand : 0;
        break;
    case 6:
        value = value + 1;
        if (operand != 0)
            value = value % operand;
        break;
    case 7:
        value = value + operand - 1;
        if (operand != 0)
            value = value % operand;
        break;
    default:
        return 0;
    }
    c->FUN_00036e70(&va->name, value);
    return assign->result;
}
}}
} // namespace fn_0018d1c0


// 0x0018d280 hulkfight::motion::TimerSetAction::vfunc_3 (54 B): matches/0x0018d280.cpp
// sym: ?vfunc_3@TimerSetAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::TimerSetAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    int i = *(int*)((char*)(*(void * *)&this->f_1c) + 0x10);
    if (i >= 0 && i < 14) {
        void* x = ((HelperA_18d280*)(*(void * *)&this->f_20))->run_000592a0();
        x = ((HelperB_18d280*)x)->run_00059a30();
        *(int*)((char*)x + 0x1e60 + i * 4) = *(int*)((char*)(*(void * *)&this->f_1c) + 0x14);
    }
    return (bool)(0);
}

namespace fn_f1f11990 {

// 0x0018d300 hulkfight::motion::TimerCondition::vfunc_5 (36 B): matches/0x0018d300.cpp
// sym: ?vfunc_5@TimerCondition_18d300@fn_f1f11990@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TimerCondition_18d300* TimerCondition_18d300::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041aa48;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0018d330 hulkfight::motion::GrappleVarCompareCondition::vfunc_5 (46 B): matches/0x0018d330.cpp
// sym: ?vfunc_5@GrappleVarCompareCondition_18d330@fn_f1f11990@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
GrappleVarCompareCondition_18d330* GrappleVarCompareCondition_18d330::vfunc_5(unsigned char param) {
    GrappleVarCompareCondition_18d330* p = this;
    *(char**)p = &threat_vftable_18d330;
    ((TimerCondition_nv_18d330*)(((hulkfight::motion::TimerCondition*)(((hulkfight::motion::TimerCondition*)((char*)p + 0x10))))))->f1_0027af50();
    ((TimerCondition_nv_18d330*)(((hulkfight::motion::TimerCondition*)(((hulkfight::motion::TimerCondition*)p)))))->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::motion::TimerCondition*)p);
    return p;
}


// 0x0018d360 hulkfight::motion::VarCompareCondition::vfunc_5 (46 B): matches/0x0018d360.cpp
// sym: ?vfunc_5@VarCompareCondition_18d360@fn_f1f11990@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
VarCompareCondition_18d360* VarCompareCondition_18d360::vfunc_5(unsigned char param) {
    VarCompareCondition_18d360* p = this;
    *(char**)p = &threat_vftable_18d360;
    ((TimerCondition_nv_18d360*)(((hulkfight::motion::TimerCondition*)(((hulkfight::motion::TimerCondition*)((char*)p + 0x10))))))->f1_0027af50();
    ((TimerCondition_nv_18d360*)(((hulkfight::motion::TimerCondition*)(((hulkfight::motion::TimerCondition*)p)))))->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::motion::TimerCondition*)p);
    return p;
}


// 0x0018d390 hulkfight::motion::TimerSetTrack::vfunc_5 (36 B): matches/0x0018d390.cpp
// sym: ?vfunc_5@TimerSetTrack_18d390@fn_f1f11990@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TimerSetTrack_18d390* TimerSetTrack_18d390::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041aaa8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0018d3c0 hulkfight::motion::VarAssignTrack::vfunc_5 (46 B): matches/0x0018d3c0.cpp
// sym: ?vfunc_5@VarAssignTrack_18d3c0@fn_f1f11990@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
VarAssignTrack_18d3c0* VarAssignTrack_18d3c0::vfunc_5(unsigned char param) {
    VarAssignTrack_18d3c0* p = this;
    *(char**)p = &threat_vftable_18d3c0;
    ((Obj_18d3c0*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_18d3c0*)p)->f2_00236d60();
    if (param & 1)
        thunk_FUN_00267090((Obj_18d3c0*)p);
    return p;
}


// 0x0018d3f0 FUN_0018d3f0 (72 B): matches/0x0018d3f0.cpp
// sym: ??0VarAssignAction_18d3f0@fn_f1f11990@@QAE@HPAVRefObj_18d3f0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
VarAssignAction_18d3f0::VarAssignAction_18d3f0(int target, RefObj_18d3f0* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x0018d440 FUN_0018d440 (50 B): matches/0x0018d440.cpp
// sym: ??1VarAssignAction_18d440@fn_f1f11990@@QAE@XZ
VarAssignAction_18d440::~VarAssignAction_18d440() {
    vptr = hulk_at_0041ab08;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_18d440 *)this)->FUN_002326a0();
}


// 0x0018d480 hulkfight::motion::TimerCondition::vfunc_6 (371 B): equivalent/0x0018d480.cpp
// sym: ?vfunc_6@TimerCondition@fn_f1f11990@@UAE_NHPAVParams_18d480@fight@@H@Z @f76495bc97e8 @w4f1ccf27a760
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 26/26)
// hulkfight::motion::TimerCondition::vfunc_6 @ 0x0018d480
bool TimerCondition::vfunc_6(int a, fight::Params_18d480* params, int c)
{
    if (index < 0 || index >= 14)
        return false;
    if (dynamic_cast<CFightParams_18d480*>(params) == 0)
        return false;
    Timing_18d480* timing = params->FUN_000592a0()->FUN_00059a30();
    float target = limit;
    if (useNamed != 0) {
        float v = timing->FUN_0003eca0(((const char**)&DAT_004bebb4)[nameIndex]);
        if (v == 0.0f) {
            target = 3.4028235e38f;
        } else {
            target = v;
            if (timing->valid[index] == 0)
                ((owners::Owner_36350 *)timing)->FUN_00036350(index, v);
        }
    }
    float cur = timing->values[index];
    switch (mode) {
    case 0:
        return cur < target;
    case 1:
        return cur <= target;
    case 2:
        return FUN_00018960(cur, target, 1e-5f);
    case 3:
        return !FUN_00018960(cur, target, 1e-5f);
    case 4:
        return cur >= target;
    case 5:
        return cur > target;
    }
    return false;
}


// 0x0018d610 FUN_0018d610 (72 B): matches/0x0018d610.cpp
// sym: ??0TimerSetAction_18d610@fn_f1f11990@@QAE@HPAVRefObj_18d610@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
TimerSetAction_18d610::TimerSetAction_18d610(int target, RefObj_18d610* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x0018d660 FUN_0018d660 (50 B): matches/0x0018d660.cpp
// sym: ??1TimerSetAction_18d660@fn_f1f11990@@QAE@XZ
TimerSetAction_18d660::~TimerSetAction_18d660() {
    vptr = hulk_at_0041ab24;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_18d660 *)this)->FUN_002326a0();
}

} // namespace fn_f1f11990

// 0x0018d6c0 fight::ParamIntConstRange<hulkfight::motion::TimerCondition>::vfunc_6 (26 B): matches/0x0018d6c0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::TimerCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::TimerCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::TimerCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::TimerCondition>::**)(int))&this->f_10))(b);
}


// 0x0018d6e0 fight::ParamIntConstRange<hulkfight::motion::TimerCondition>::vfunc_2 (11 B): matches/0x0018d6e0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::TimerCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018d720 fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_7 (6 B): matches/0x0018d720.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0018d730 fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_6 (30 B): matches/0x0018d730.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_18d730 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_18d730*)&DAT_003f335c));
}


// 0x0018d750 fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_8 (26 B): matches/0x0018d750.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::TimerCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::**)(int))&this->f_18))(b);
}


// 0x0018d770 fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_2 (11 B): matches/0x0018d770.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0018d7a0 fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>::vfunc_6 (26 B): matches/0x0018d7a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>::**)(int))&this->f_10))(b);
}


// 0x0018d7c0 fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>::vfunc_2 (11 B): matches/0x0018d7c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018d7f0 fight::ParamBool<hulkfight::motion::TimerCondition>::vfunc_6 (26 B): matches/0x0018d7f0.cpp
// sym: ?vfunc_6@?$ParamBool@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::TimerCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::TimerCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::TimerCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::TimerCondition>::**)(int))&this->f_10))(b);
}


// 0x0018d810 fight::ParamBool<hulkfight::motion::TimerCondition>::vfunc_2 (11 B): matches/0x0018d810.cpp
// sym: ?vfunc_2@?$ParamBool@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::TimerCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018d850 fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_7 (6 B): matches/0x0018d850.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0018d860 fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_6 (30 B): matches/0x0018d860.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_18d860 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_18d860*)&DAT_003f335c));
}


// 0x0018d880 fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_8 (26 B): matches/0x0018d880.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::**)(int))&this->f_18))(b);
}


// 0x0018d8a0 fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_2 (11 B): matches/0x0018d8a0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0018d8d0 fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>::vfunc_6 (26 B): matches/0x0018d8d0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>::**)(int))&this->f_10))(b);
}


// 0x0018d8f0 fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>::vfunc_2 (11 B): matches/0x0018d8f0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018d930 fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::vfunc_7 (6 B): matches/0x0018d930.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0018d940 fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::vfunc_6 (30 B): matches/0x0018d940.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_18d940 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_18d940*)&DAT_003f335c));
}


// 0x0018d960 fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::vfunc_8 (26 B): matches/0x0018d960.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::**)(int))&this->f_18))(b);
}


// 0x0018d980 fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::vfunc_2 (11 B): matches/0x0018d980.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0018d9b0 fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>::vfunc_6 (26 B): matches/0x0018d9b0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>::**)(int))&this->f_10))(b);
}


// 0x0018d9d0 fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>::vfunc_2 (11 B): matches/0x0018d9d0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018da00 fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>::vfunc_6 (26 B): matches/0x0018da00.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>::**)(int))&this->f_10))(b);
}


// 0x0018da20 fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>::vfunc_2 (11 B): matches/0x0018da20.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018da50 fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>::vfunc_6 (26 B): matches/0x0018da50.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>::**)(int))&this->f_10))(b);
}


// 0x0018da70 fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>::vfunc_2 (11 B): matches/0x0018da70.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018daa0 fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>::vfunc_6 (26 B): matches/0x0018daa0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>::**)(int))&this->f_10))(b);
}


// 0x0018dac0 fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>::vfunc_2 (11 B): matches/0x0018dac0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018db00 fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::vfunc_7 (6 B): matches/0x0018db00.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0018db10 fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::vfunc_6 (30 B): matches/0x0018db10.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_18db10 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_18db10*)&DAT_003f335c));
}


// 0x0018db30 fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::vfunc_8 (26 B): matches/0x0018db30.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::**)(int))&this->f_18))(b);
}


// 0x0018db50 fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::vfunc_2 (11 B): matches/0x0018db50.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0018db80 fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>::vfunc_6 (26 B): matches/0x0018db80.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>::**)(int))&this->f_10))(b);
}


// 0x0018dba0 fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>::vfunc_2 (11 B): matches/0x0018dba0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018dbd0 fight::ParamBool<hulkfight::motion::VarAssignTrack>::vfunc_6 (26 B): matches/0x0018dbd0.cpp
// sym: ?vfunc_6@?$ParamBool@VTimerCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::VarAssignTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::VarAssignTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::VarAssignTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::VarAssignTrack>::**)(int))&this->f_10))(b);
}


// 0x0018dbf0 fight::ParamBool<hulkfight::motion::VarAssignTrack>::vfunc_2 (11 B): matches/0x0018dbf0.cpp
// sym: ?vfunc_2@?$ParamBool@VTimerCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::VarAssignTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0018dc10 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TimerCondition>::vfunc_0 (36 B): matches/0x0018dc10.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTimerCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TimerCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bf228, 0) != 0;
}


// 0x0018dc40 fight::ParamIntConstRange<hulkfight::motion::TimerCondition>::vfunc_0 (30 B): matches/0x0018dc40.cpp
// sym: ??_G?$ParamIntConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::TimerCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::TimerCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dc40)
#endif


// 0x0018dc60 fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_0 (30 B): matches/0x0018dc60.cpp
// sym: ??_G?$ParamEnumConstList@VTimerCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::TimerCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dc60)
#endif


// 0x0018dc80 fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>::vfunc_0 (30 B): matches/0x0018dc80.cpp
// sym: ??_G?$ParamFloatConstRange@VTimerCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dc80)
#endif


// 0x0018dca0 fight::ParamBool<hulkfight::motion::TimerCondition>::vfunc_0 (30 B): matches/0x0018dca0.cpp
// sym: ??_G?$ParamBool@VTimerCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::TimerCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::TimerCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dca0)
#endif


// 0x0018dcd0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleVarCompareCondition>::vfunc_0 (36 B): matches/0x0018dcd0.cpp [wrapped: conflict: fight::ConditionFactoryCaster]
// sym: ?vfunc_0@GrappleCaster@fight@fn_0018dcd0@@UAEHPAX@Z
namespace fn_0018dcd0 {
struct Info {
    int x;
};
extern Info hulk_at_00491ca8, hulk_at_004bf2e8;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class GrappleCaster : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
int fight::GrappleCaster::vfunc_0(void* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00491ca8), (void*)(&hulk_at_004bf2e8), 0)) != 0;
}
} // namespace fn_0018dcd0


// 0x0018dd00 fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_0 (30 B): matches/0x0018dd00.cpp
// sym: ??_G?$ParamEnumConstList@VGrappleVarCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dd00)
#endif


// 0x0018dd20 fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>::vfunc_0 (30 B): matches/0x0018dd20.cpp
// sym: ??_G?$ParamIntConstRange@VGrappleVarCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::GrappleVarCompareCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dd20)
#endif


// 0x0018dd50 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VarCompareCondition>::vfunc_0 (36 B): matches/0x0018dd50.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVarCompareCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VarCompareCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bf3a8, 0) != 0;
}


// 0x0018dd80 fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::vfunc_0 (30 B): matches/0x0018dd80.cpp
// sym: ??_G?$ParamEnumConstList@VVarCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dd80)
#endif


// 0x0018dda0 fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>::vfunc_0 (30 B): matches/0x0018dda0.cpp
// sym: ??_G?$ParamIntConstRange@VVarCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dda0)
#endif


// 0x0018ddd0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TimerSetTrack>::vfunc_0 (36 B): matches/0x0018ddd0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTimerSetTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TimerSetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_004bf458, 0) != 0;
}


// 0x0018de00 fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>::vfunc_0 (30 B): matches/0x0018de00.cpp
// sym: ??_G?$ParamFloatConstRange@VTimerSetTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18de00)
#endif


// 0x0018de20 fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>::vfunc_0 (30 B): matches/0x0018de20.cpp
// sym: ??_G?$ParamIntConstRange@VTimerSetTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18de20)
#endif


// 0x0018de50 fight::TrackFactoryCasterTemplate<hulkfight::motion::VarAssignTrack>::vfunc_0 (36 B): matches/0x0018de50.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VVarAssignTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::VarAssignTrack>::vfunc_0(void* __p0) { void * track = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(track, 0, (void*)(&hulk_at_0049850c), (void*)(&hulk_at_004bf500), 0)) != 0;
}


// 0x0018de80 fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>::vfunc_0 (30 B): matches/0x0018de80.cpp
// sym: ??_G?$ParamFloatConstRange@VVarAssignTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::VarAssignTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18de80)
#endif


// 0x0018dea0 fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::vfunc_0 (30 B): matches/0x0018dea0.cpp
// sym: ??_G?$ParamEnumConstList@VVarAssignTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::VarAssignTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dea0)
#endif


// 0x0018dec0 fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>::vfunc_0 (30 B): matches/0x0018dec0.cpp
// sym: ??_G?$ParamIntConstRange@VVarAssignTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::VarAssignTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dec0)
#endif


// 0x0018dee0 fight::ParamBool<hulkfight::motion::VarAssignTrack>::vfunc_0 (30 B): matches/0x0018dee0.cpp
// sym: ??_G?$ParamBool@VVarAssignTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::VarAssignTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::VarAssignTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18dee0)
#endif


// 0x0018e060 FUN_0018e060 (213 B): equivalent/0x0018e060.cpp [wrapped: conflict: fight::ParamFloatConstRange; fight::ParamIntConstRange]
// sym: ?FUN_0018e060@fn_0018e060@@YAXXZ @4ea37e894a48 @wa9384706866f
inline void* __cdecl operator new(size_t,void* p) { return p; }
namespace fn_0018e060 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0018e060 @ 0x0018e060


void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetTimeBegin_0018cb80(); void __cdecl SetTimer_0018cba0(); void __cdecl SetValue_0018cbc0();
namespace hulkfight { namespace motion { class TimerSetTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234960(const char*); };
template<class T> struct ParamIntConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_002348e0(const char*); };
}
 
void __cdecl FUN_002347b0(void*,void**,int);
void __cdecl FUN_0018e060() {
 if (!DAT_004e1524) {
  void* params[3];
  typedef fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack> F;
  typedef fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack> I;
  F* a=(F*)FUN_0008d690((int)sizeof(F));
  if(a) { a->FUN_00234960("timeBegin"); a=new(a) F; a->callback=SetTimeBegin_0018cb80; }
  params[0]=a;
  I* b=(I*)FUN_0008d690((int)sizeof(I));
  if(b) { b->FUN_002348e0("timer"); b=new(b) I; b->callback=SetTimer_0018cba0; }
  params[1]=b;
  F* c=(F*)FUN_0008d690((int)sizeof(F));
  if(c) { c->FUN_00234960("value"); c=new(c) F; c->callback=SetValue_0018cbc0; }
  params[2]=c;
  FUN_002347b0(&DAT_004e1520,params,3);
 }
 ++DAT_004e1524;
}
} // namespace fn_0018e060

namespace fn_f1f11990 {

// 0x0018e190 hulkfight::motion::VarAssignAction::vfunc_2 (71 B): matches/0x0018e190.cpp
// sym: ?vfunc_2@VarAssignAction_18e190@fn_f1f11990@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
VarAssignAction_18e190* VarAssignAction_18e190::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_18e190;
    RefCounted_18e190* q = *(RefCounted_18e190* volatile*)&m_20;
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


// 0x0018e230 hulkfight::motion::TimerSetAction::vfunc_2 (71 B): matches/0x0018e230.cpp
// sym: ?vfunc_2@TimerSetAction_18e230@fn_f1f11990@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
TimerSetAction_18e230* TimerSetAction_18e230::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_18e230;
    RefCounted_18e230* q = *(RefCounted_18e230* volatile*)&m_20;
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


// 0x0018e2e0 fight::ParamName<hulkfight::motion::GrappleVarCompareCondition>::vfunc_7 (12 B): matches/0x0018e2e0.cpp
// sym: ?vfunc_6@ParamBranch@fn_f1f11990@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f1f11990

// 0x0018e330 fight::ParamName<hulkfight::motion::VarCompareCondition>::vfunc_7 (12 B): matches/0x0018e330.cpp [wrapped: same definition as 0x0018e2e0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0018e330@@UAEXPAX@Z
namespace fn_0018e330 {
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
} // namespace fn_0018e330


// 0x0018e3a0 fight::ParamName<hulkfight::motion::VarAssignTrack>::vfunc_7 (12 B): matches/0x0018e3a0.cpp [wrapped: same definition as 0x0018e2e0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0018e3a0@@UAEXPAX@Z
namespace fn_0018e3a0 {
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
} // namespace fn_0018e3a0


// 0x0018e3b0 fight::ParamName<hulkfight::motion::GrappleVarCompareCondition>::vfunc_0 (30 B): matches/0x0018e3b0.cpp
// sym: ??_G?$ParamName@VGrappleVarCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::GrappleVarCompareCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::GrappleVarCompareCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18e3b0)
#endif


// 0x0018e3d0 fight::ParamName<hulkfight::motion::VarCompareCondition>::vfunc_0 (30 B): matches/0x0018e3d0.cpp
// sym: ??_G?$ParamName@VVarCompareCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::VarCompareCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::VarCompareCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18e3d0)
#endif


// 0x0018e3f0 fight::ParamName<hulkfight::motion::VarAssignTrack>::vfunc_0 (30 B): matches/0x0018e3f0.cpp
// sym: ??_G?$ParamName@VVarAssignTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::VarAssignTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::VarAssignTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x18e3f0)
#endif


// 0x0018e860 FUN_0018e860 (111 B): matches/0x0018e860.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_0018e860
namespace fn_0018e860 {
// FUN_0018e860 @ 0x0018e860
namespace hulkfight { namespace motion { class VarCompareCondition; class GrappleVarCompareCondition; class TimerCondition; } }
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry_18e860 { void FUN_00236760(void *factory); };
extern "C" void *__cdecl FUN_002343e0(const char *name, void *caster);

extern "C" void __cdecl FUN_0018e860(Registry_18e860 *r)
{
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VarCompareCondition> caster;
        r->FUN_00236760(FUN_002343e0("varCompare", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleVarCompareCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleVarCompare", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::TimerCondition> caster;
        r->FUN_00236760(FUN_002343e0("timer", &caster));
    }
}
} // namespace fn_0018e860

namespace fn_f1f11990 {

// 0x0018e8d0 FUN_0018e8d0 (77 B): matches/0x0018e8d0.cpp
// sym: _FUN_0018e8d0
extern "C" void FUN_0018e8d0(Factory* p) {
    {
        VarCaster a;
        p->add_002367c0(FUN_00236ac0("varAssign", &a));
    }
    {
        TrackFactoryCasterTemplate_18e8d0 b;
        p->add_002367c0(FUN_00236ac0("timerSet", &b));
    }
}

} // namespace fn_f1f11990

// 0x0018e960 fight::ConditionFactoryTemplate<hulkfight::motion::TimerCondition>::vfunc_5 (59 B): matches/0x0018e960.cpp [wrapped: conflict: Alloc; TimerCondition]
// sym: ?factory_vfunc5@fn_0018e960@@YAPAUTimerCondition@1@XZ
namespace fn_0018e960 {
extern "C++" __declspec(nothrow) void* __cdecl Alloc_0008d690(hulk_uintptr);
extern void* timerVtable;
struct TimerCondition {
    void* vptr;
    char pad[8];
    int a;
    int b;
    int c;
    char flag;
    char pad2[3];
    int d;
    void Init_00234590(int);
};
TimerCondition* factory_vfunc5() {
    TimerCondition* p = (TimerCondition*)Alloc_0008d690(0x20);
    if (p) {
        p->Init_00234590(0);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->flag = 0;
        p->d = 0;
        p->vptr = &timerVtable;
        return p;
    }
    return 0;
}
} // namespace fn_0018e960

namespace fn_f1f11990 {

// 0x0018e9a0 fight::ConditionFactoryTemplate<hulkfight::motion::TimerCondition>::vfunc_2 (43 B): matches/0x0018e9a0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18e9a0@fn_f1f11990@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18e9a0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041ae28;
    base1_dtor_0018cc70();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1f11990

// 0x0018ea10 fight::TrackFactoryTemplate<hulkfight::motion::TimerSetTrack>::vfunc_5 (66 B): matches/0x0018ea10.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VTimerSetTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TimerSetTrack>::vfunc_5() {
    TimerSetTrack_18ea10* p = (TimerSetTrack_18ea10*)Allocate(0x18);
    if (p) {
        p->Init_00236d40();
        p->vptr = ((hulk_intptr)DAT_0041aaa8);
        p->mc = 0;
        p->m10 = 0;
        p->m14 = 0;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f1f11990 {

// 0x0018ea60 fight::TrackFactoryTemplate<hulkfight::motion::TimerSetTrack>::vfunc_2 (43 B): matches/0x0018ea60.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f1f11990@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041ae44;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1f11990

// 0x0018ead0 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleVarCompareCondition>::vfunc_5 (62 B): matches/0x0018ead0.cpp [wrapped: conflict: fight::ConditionFactoryTemplate; hulkfight::motion::GrappleVarCompareCondition]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@UGrappleVarCompareCondition@motion@hulkfight@fn_0018ead0@@@fight@fn_0018ead0@@UAEPAUBase@3@XZ
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_0018ead0 {

struct Sub {
    Sub() throw();
    char data[8];
};
struct Base {
    Base(int) throw();
    virtual void v0();
    char pad[12];
};
namespace hulkfight {
namespace motion {
struct GrappleVarCompareCondition : Base {
    Sub sub;
    int a, b;
    GrappleVarCompareCondition() throw() : Base(0), sub(), a(0), b(0) {}
    virtual void v0();
};
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> struct ConditionFactoryTemplate {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Base* vfunc_5();
};
template <> Base* ConditionFactoryTemplate<hulkfight::motion::GrappleVarCompareCondition>::vfunc_5() {
    return new hulkfight::motion::GrappleVarCompareCondition();
}
} // namespace fight
} // namespace fn_0018ead0

namespace fn_f1f11990 {

// 0x0018eb10 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleVarCompareCondition>::vfunc_2 (43 B): matches/0x0018eb10.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18eb10@fn_f1f11990@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18eb10::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041ae60;
    base1_dtor_0018cce0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1f11990

// 0x0018eb80 fight::ConditionFactoryTemplate<hulkfight::motion::VarCompareCondition>::vfunc_5 (62 B): matches/0x0018eb80.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VVarCompareCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VarCompareCondition>::vfunc_5() {
    Child* p = (Child*)FUN_0008d690(0x20);
    if (p) {
        p->Child::Child(0);
        *(void**)p = VT_18eb80;
        ((Sub*)((char*)p + 0x10))->Sub::Sub();
        *(int*)((char*)p + 0x18) = 0;
        *(int*)((char*)p + 0x1c) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f1f11990 {

// 0x0018ebc0 fight::ConditionFactoryTemplate<hulkfight::motion::VarCompareCondition>::vfunc_2 (43 B): matches/0x0018ebc0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18ebc0@fn_f1f11990@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18ebc0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041ae7c;
    base1_dtor_0018cd60();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1f11990

// 0x0018ec30 fight::TrackFactoryTemplate<hulkfight::motion::VarAssignTrack>::vfunc_5 (73 B): matches/0x0018ec30.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VVarAssignTrack@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::VarAssignTrack>::vfunc_5() {
    return (void*)(new hulkfight::motion::VarAssignTrack_18ec30);
}


// 0x0018ec80 fight::TrackFactoryTemplate<hulkfight::motion::VarAssignTrack>::vfunc_2 (43 B): matches/0x0018ec80.cpp [wrapped: same definition as 0x0018ea60 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0018ec80@@QAEPAXE@Z
namespace fn_0018ec80 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0041ae98;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0018ce70();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041ae98;
    base1_dtor_0018ce70();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0018ec80

