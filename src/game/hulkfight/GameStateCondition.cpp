// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f587a2cf {
#define TREE_TU_END }
namespace fn_f587a2cf {} using namespace fn_f587a2cf;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f587a2cf {
class Obj_12dfe0 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int value);
};
class Obj {
  public:
    char _m_pad_0[0xc];
    union { char* name; int value; };
    char _m_pad_10[0x4];
    char* str;
    bool SetUnlockable_0012dff0(int x);
    char SetMission_0012e470(const char* s);
    bool Set(const char* s);
    void apply_002367c0(void*);
};
class X_12e000 {
  public:
    char pad[0x10];
    char m10;
    char SetLocked_0012e000(char v);
};
class X_12e010 {
  public:
    char pad[0x10];
    int m10;
    char SetCompare_0012e010(int v);
};
class Obj_12e020 {
  public:
    char Pad[0xc];
    int mVal;
    bool SetEnvironmentCompare_0012e020(int x);
};
class Obj_12e030 {
  public:
    char pad[0x14];
    void* m14;
    bool SetTimeOfDayCompare_0012e030(void* p);
};
class T_12e050 {
  public:
    char pad[0xc];
    int value;
    bool Set(int x);
};
class Target_12e060 {
  public:
    char pad[0x10];
    int mValue;
    char mFlag;
    char Set(int value);
};
class Obj_12e080 {
  public:
    char pad[0x14];
    int m14;
    char Set(int a);
};
class C_12e090 {
  public:
    char Pad[0x18];
    int Value;
    char Set(int v);
};
class Obj_12e0c0 {
  public:
    char pad[0xc];
    int value;
    bool Set(int x);
};
class Obj_12e180 {
  public:
    char pad[0xc];
    int mValue;
    bool SetTimeBegin_0012e180(int v);
};
class Obj_12e190 {
  public:
    char pad[0x10];
    int mVal;
    char SetTimeEnd_0012e190(int v);
};
class X_12e200 {
  public:
    virtual void V0();
    char Set(int value);
    char pad[8];
    int m12;
    char pad2[4];
};
extern int* hulk_at_004e0e4c;
class CCondition_12e250 {
  public:
    virtual int vfunc_0(int);
};
struct MissionProgressCondition {
    void* vf;
    char pad4[8];
    volatile void* a;
    char pad10[4];
    volatile void* b;
    void Init();
    void Tail_002345b0();
};
extern char hulk_at_00411224;
void __cdecl thunk_0008d340(void*);
extern "C" void __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char padding[0x14];
    char* text;
    unsigned char FUN_0012e320(const char* source);
};
extern int* hulk_at_004e0e54;
class CCondition_12e3a0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0e5c;
class CCondition_12e400 {
  public:
    virtual int vfunc_0(int);
};
extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(hulk_uintptr);
} // namespace fn_f587a2cf
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
namespace fn_f587a2cf {
extern "C" void __cdecl thunk_FUN_00267090(void*);
extern int* hulk_at_004e0e64;
class CCondition_12e550 {
  public:
    virtual int vfunc_0(int);
};
typedef unsigned int u32_12e590;
void thunk_FUN_00267090(u32_12e590);
extern int hulk_at_00411284;
struct Condition_12e590 {
    void finish_002345b0();
};
struct DebugPrintCondition : Condition_12e590 {
    void* vt;
    char pad4[8];
    u32_12e590 a;
    u32_12e590 b;
    void dtorish();
};
extern int* hulk_at_004e0e6c;
class CCondition_12e6a0 {
  public:
    virtual int vfunc_0(int);
};
typedef unsigned int u32_12e6e0;
extern void* hulk_at_004112a4;
extern void __cdecl ReleaseThing_0008d340(u32_12e6e0);
class GameStateCondition_12e6e0 {
  public:
    u32_12e6e0 x[7];
    void Finish_002345b0();
};
extern int* hulk_at_004e0e74;
class CCondition_12e7f0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0e7c;
class CCondition_12e860 {
  public:
    virtual int vfunc_0(int);
};
class Track_12e870 {
  public:
    Track_12e870();
    virtual void f();
    char pad[4];
};
class StatBeginTrialTrack : public Track_12e870 {
  public:
    StatBeginTrialTrack();
    char pad2[4];
    int a, b;
    virtual void f();
};
extern void __cdecl thunk_0008d340(int);
extern int* hulk_at_004e0e84;
class CCondition_12e950 {
  public:
    virtual int vfunc_0(int);
};
class Base {
  public:
    virtual void fn();
    char pad[4];
    int value;
    Base();
};
class Track_12e960 : public Base {
  public:
    int a, b, c, d;
    Track_12e960() : a(0), b(0), c(0), d(0) {}
};
class NISSoundTrack : public Track_12e960 {
  public:
    NISSoundTrack();
    virtual void fn();
};
extern int* hulk_at_004e0e8c;
class CCondition_12eb20 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_00411344[];
typedef unsigned int U_12eb80;
class DialogueTrack;
extern void __fastcall final_fn_00236d60(DialogueTrack*);
extern void __cdecl release_0008d340(U_12eb80);
class DialogueTrack {
  public:
    void* vf;
    char pad[12];
    U_12eb80 a;
    U_12eb80 b;
    char pad2[4];
    U_12eb80 c;
    U_12eb80 d;
    void destroy();
};
extern int* hulk_at_004e0e94;
class CCondition_12ed60 {
  public:
    virtual int vfunc_0(int);
};
class Track_12ed70 {
  public:
    Track_12ed70();
    virtual void fn();
    char pad[4];
};
class DebugPrintTrack : public Track_12ed70 {
  public:
    DebugPrintTrack();
    int count;
    int* p;
    float value;
    int a;
    int b;
};
extern int* hulk_at_004e0e9c;
class CCondition_12eed0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0ea4;
class CCondition_12efc0 {
  public:
    virtual int vfunc_0(int);
};
class Track_12efd0 {
  public:
    Track_12efd0();
    virtual void f();
    char pad[4];
};
class StatTrack : public Track_12efd0 {
  public:
    StatTrack();
    virtual void f();
    char pad2[4];
    int a;
    int b;
};
extern int* hulk_at_004e0eac;
class CCondition_12f0b0 {
  public:
    virtual int vfunc_0(int);
};
class Track_12f0c0 {
  public:
    Track_12f0c0();
    virtual void f();
    char pad[8];
};
class XPTrack : public Track_12f0c0 {
  public:
    int m12, m16;
    XPTrack();
};
class Action_12f910 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Action_12f990 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
typedef unsigned int u32_12f9b0;
struct Action_12f9b0 {
    char pad[0x1c];
};
struct Manager_12f9b0 {
    Manager_12f9b0* doA_00086370();
    void doB_00090720(u32_12f9b0, int);
};
extern Manager_12f9b0* hulk_at_004dd6ec;
class Action_12f9e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
typedef unsigned int u32_12fa00;
class Result_12fa00 {
  public:
    void run_000906f0(u32_12fa00);
};
class Helper_12fa00 {
  public:
    Result_12fa00* run_00086370();
};
extern Helper_12fa00* gGlobal_12fa00;
class ActionBase_12fa00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(void*, void*);
    virtual void f4();
    virtual void f5();
};
class Action_12fa30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
typedef unsigned int u32_12fa50;
class Result_12fa50 {
  public:
    void run_00090df0(u32_12fa50);
};
class Helper_12fa50 {
  public:
    Result_12fa50* run_00086370();
};
extern Helper_12fa50* gGlobal_12fa50;
class ActionBase_12fa50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(void*, void*);
    virtual void f4();
    virtual void f5();
};
class Action_12fa80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Action_12fa90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
struct Datum {
    char pad[16];
    float value;
};
class Result {
  public:
    void Apply_00090720(const char*, int);
};
class Manager {
  public:
    Result* Find_00086370();
};
extern Manager* gManager;
class Action_12fae0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_00411244[];
class Condition_12fc20 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class UnlockableCondition_12fc20 : public Condition_12fc20 {
  public:
    UnlockableCondition_12fc20* vfunc_5(signed char flags);
};
extern int hulk_at_00411264;
class GameStateCondition_12fc50 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual GameStateCondition_12fc50* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void baseDtor_002345b0();
    char pad4[8];
    void* m0c;
    char pad10[4];
    void* m14;
};
extern "C" const void* loc_vftable;
class LocationCondition {
  public:
    char pad0[0x10];
    void* m1;       // +0x10
    char pad2[4];   // +0x14
    void* m2;       // +0x18
    void Cleanup_002345b0(); // FUN_002345b0, thiscall no args
    LocationCondition* vfunc_5(int b);
};
extern void* hulk_at_004112c4[];
class Condition_12fd10 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class ChapterMissionCondition_12fd10 : public Condition_12fd10 {
  public:
    ChapterMissionCondition_12fd10* vfunc_5(signed char flags);
};
extern void* hulk_at_004112e4[];
} // namespace fn_f587a2cf
void operator delete[](void*);
namespace fn_f587a2cf {
class Track_12fd40 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class StatBeginTrialTrack_12fd40 : public Track_12fd40 {
  public:
    char pad[0x10 - 4];
    void* m10;
    StatBeginTrialTrack_12fd40* f5(unsigned char flags);
};
class DialogueTrack_12fdd0 {
  public:
    void* vptr;
    char pad4[0x10 - 0x4];
    void* m10;
    void* m14;
    char pad18[0x1c - 0x18];
    void* m1c;
    void* m20;

    void FUN_00236d60();
    DialogueTrack_12fdd0* vfunc_5(int param);
};
extern int hulk_at_004113a4;
class StatEndTrialTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual StatEndTrialTrack* vfunc_5(int);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    int a;
    int b;
    int c;
    void* m10;
    void Cleanup_00236d60();
};
extern void* hulk_at_00411404[];
class Track_12fee0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class XPTrack_12fee0 : public Track_12fee0 {
  public:
    XPTrack_12fee0* vfunc_5(signed char flags);
};
class RefObj_12ff10 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_12ff10 {
  public:
    Action_12ff10();
    virtual void Update();
    char pad[0x18];
};
extern void* hulk_at_0041146c[];
class Ref_12ff60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_12ff60 {
  public:
    void* vptr;
};
class Action : public Base_12ff60 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_12ff60* m20;
    ~Action();
};
class RefObj_12ffa0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_12ffa0 {
  public:
    Action_12ffa0();
    virtual void Update();
    char pad[0x18];
};
class NISSoundAction_12ffa0 : public Action_12ffa0 {
  public:
    int mTarget;
    RefObj_12ffa0* mObj;
    NISSoundAction_12ffa0(int target, RefObj_12ffa0* obj);
    virtual void Execute();
};
extern void* hulk_at_00411488[];
class Ref_12fff0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_12fff0 {
  public:
    void* vptr;
};
class NISSoundAction_12fff0 : public Action_12fff0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_12fff0* m20;
    ~NISSoundAction_12fff0();
};
class RefObj_130030 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_130030 {
  public:
    Action_130030();
    virtual void Update();
    char pad[0x18];
};
class StatAction_130030 : public Action_130030 {
  public:
    int mTarget;
    RefObj_130030* mObj;
    StatAction_130030(int target, RefObj_130030* obj);
    virtual void Execute();
};
extern void* hulk_at_004114a4[];
class Ref_130080 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_130080 {
  public:
    void* vptr;
};
class StatAction_130080 : public Action_130080 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_130080* m20;
    void f();
};
class RefObj_1300c0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1300c0 {
  public:
    Action_1300c0();
    virtual void Update();
    char pad[0x18];
};
class StatBeginTrialAction_1300c0 : public Action_1300c0 {
  public:
    int mTarget;
    RefObj_1300c0* mObj;
    StatBeginTrialAction_1300c0(int target, RefObj_1300c0* obj);
    virtual void Execute();
};
extern void* hulk_at_004114c0[];
class Ref_130110 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_130110 {
  public:
    void* vptr;
};
class StatBeginTrialAction_130110 : public Action_130110 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_130110* m20;
    ~StatBeginTrialAction_130110();
};
class RefObj_130150 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_130150 {
  public:
    Action_130150();
    virtual void Update();
    char pad[0x18];
};
class StatEndTrialAction_130150 : public Action_130150 {
  public:
    int mTarget;
    RefObj_130150* mObj;
    StatEndTrialAction_130150(int target, RefObj_130150* obj);
    virtual void Execute();
};
extern void* hulk_at_004114dc[];
class Ref_1301a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1301a0 {
  public:
    void* vptr;
    ~Action_1301a0() throw();
};
class StatEndTrialAction_1301a0 : public Action_1301a0 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_1301a0* m20;
    ~StatEndTrialAction_1301a0() throw();
};
class RefObj_1301e0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1301e0 {
  public:
    Action_1301e0();
    virtual void Update();
    char pad[0x18];
};
class XPAction_1301e0 : public Action_1301e0 {
  public:
    int mTarget;
    RefObj_1301e0* mObj;
    XPAction_1301e0(int target, RefObj_1301e0* obj);
    virtual void Execute();
};
extern void* hulk_at_004114f8[];
class Ref_130230 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_130230 {
  public:
    void* vptr;
};
class XPAction_130230 : public Action_130230 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_130230* m20;
    ~XPAction_130230();
};
struct Obj_130270 {
    virtual void F();
    virtual void R();
};
extern int hulk_at_00411514;
struct PostEvent_StringAction {
    void* vf;
    int pad[6];
    int arg;
    Obj_130270* object;
    void Init_00232660();
    PostEvent_StringAction* Build(int, Obj_130270*);
};
extern void* g_vftable_1302c0[];
class Ref_1302c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1302c0 {
  public:
    void* vptr;
};
class DebugPrintAction_1302c0 : public Action_1302c0 {
  public:
    char pad[0x1c];
    Ref_1302c0* m20;
    ~DebugPrintAction_1302c0();
};
class CStageCondition_130330;
class ParamValue_130330 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130330 : public ParamValue_130330 {
  public:
    int pad;
};
struct CAxisArcCondition_130370;
class CStageCondition_130380 {};
class ParamValue_130380 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_130380 : public ParamValue_130380 {
  public:
    virtual void f();
};
struct CAxisArcCondition_130400;
class CStageCondition_130410 {};
class ParamValue_130410 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_130410 : public ParamValue_130410 {
  public:
    virtual void f();
};
class CStageCondition_1304a0;
class ParamValue_1304a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1304a0 : public ParamValue_1304a0 {
  public:
    int pad;
};
class CStageCondition_1304f0;
class ParamValue_1304f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1304f0 : public ParamValue_1304f0 {
  public:
    int pad;
};
struct CAxisArcCondition_130530;
class CStageCondition_130540 {};
class ParamValue_130540 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_130540 : public ParamValue_130540 {
  public:
    virtual void f();
};
class CStageCondition_1305d0;
class ParamValue_1305d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1305d0 : public ParamValue_1305d0 {
  public:
    int pad;
};
struct CAxisArcCondition_130610;
class CStageCondition_130620 {};
class ParamValue_130620 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_130620 : public ParamValue_130620 {
  public:
    virtual void f();
};
class CStageCondition_1306b0;
class ParamValue_1306b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1306b0 : public ParamValue_1306b0 {
  public:
    int pad;
};
struct CAxisArcCondition_1306f0;
class CStageCondition_130700 {};
class ParamValue_130700 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_130700 : public ParamValue_130700 {
  public:
    virtual void f();
};
class CStageCondition_130790;
class ParamValue_130790 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130790 : public ParamValue_130790 {
  public:
    int pad;
};
class CStageCondition_1307e0;
class ParamValue_1307e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1307e0 : public ParamValue_1307e0 {
  public:
    int pad;
};
class CStageCondition_130830;
class ParamValue_130830 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130830 : public ParamValue_130830 {
  public:
    int pad;
};
class CStageCondition_130880;
class ParamValue_130880 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130880 : public ParamValue_130880 {
  public:
    int pad;
};
class CStageCondition_1308d0;
class ParamValue_1308d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1308d0 : public ParamValue_1308d0 {
  public:
    int pad;
};
class CStageCondition_130920;
class ParamValue_130920 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130920 : public ParamValue_130920 {
  public:
    int pad;
};
class CStageCondition_130970;
class ParamValue_130970 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130970 : public ParamValue_130970 {
  public:
    int pad;
};
class CStageCondition_1309c0;
class ParamValue_1309c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1309c0 : public ParamValue_1309c0 {
  public:
    int pad;
};
class CStageCondition_130a10;
class ParamValue_130a10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130a10 : public ParamValue_130a10 {
  public:
    int pad;
};
class CStageCondition_130a60;
class ParamValue_130a60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130a60 : public ParamValue_130a60 {
  public:
    int pad;
};
class CStageCondition_130ab0;
class ParamValue_130ab0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130ab0 : public ParamValue_130ab0 {
  public:
    int pad;
};
class CStageCondition_130b00;
class ParamValue_130b00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130b00 : public ParamValue_130b00 {
  public:
    int pad;
};
class CStageCondition_130b50;
class ParamValue_130b50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130b50 : public ParamValue_130b50 {
  public:
    int pad;
};
class CStageCondition_130ba0;
class ParamValue_130ba0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130ba0 : public ParamValue_130ba0 {
  public:
    int pad;
};
class CStageCondition_130bf0;
class ParamValue_130bf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130bf0 : public ParamValue_130bf0 {
  public:
    int pad;
};
class CStageCondition_130c40;
class ParamValue_130c40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_130c40 : public ParamValue_130c40 {
  public:
    int pad;
};
} // namespace fn_f587a2cf
namespace fight {
class ConditionFactoryCaster_130c60 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight {
class MissionProgressCondition_130c60 {};
}
namespace fn_f587a2cf {
extern "C" int __cdecl helper(const char*, int, const void*, const void*, int);
extern char DAT_00491ca8;
extern char DAT_004aa710;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004aa7c0;
} // namespace fn_f587a2cf
namespace fight {
class ConditionFactoryCaster_130ce0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight {
class UnlockableCondition_130ce0 {};
}
namespace fn_f587a2cf {
class ConditionFactoryCaster_130d60 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class GameStateCondition_130d60 {};
extern void* hulk_at_00491ca8;
extern void* hulk_at_004aa868;
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
} // namespace fn_f587a2cf
namespace hulkfight {
class DebugPrintCondition_130de0;
}
namespace fight {
class ConditionFactoryCaster_130de0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
extern void* a;
}
namespace fight {
extern void* hulk_at_004aa910;
}
namespace fight {
class ConditionFactoryCaster_130e40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight {
class LocationCondition_130e40 {};
}
namespace fn_f587a2cf {
extern char DAT_004aa9b8;
extern "C" int __cdecl check(void*, int, void*, void*, int);
struct Token {
    int x;
};
extern char DAT_004aaa68;
} // namespace fn_f587a2cf
namespace fight {
class ConditionFactoryCaster_130ec0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight {
class ChapterMissionCondition_130ec0 {};
}
namespace fn_f587a2cf {
class TrackFactoryCaster_130f40 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_004aab18;
} // namespace fn_f587a2cf
namespace fight {
class TrackFactoryCaster_130fc0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight {
class NISSoundTrack_130fc0;
}
namespace fn_f587a2cf {
extern int hulk_at_0049850c, hulk_at_004aabb8;
extern "C" int __cdecl cast(void*, int, int*, int*, int);
extern int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_004aac50;
} // namespace fn_f587a2cf
namespace fight {
class TrackFactoryCaster_131040 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight {
class DialogueTrack_131040 {};
}
namespace fn_f587a2cf {
class TrackFactoryCaster_131100 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class DebugPrintTrack_131100 {};
extern char DAT_004aace8;
} // namespace fn_f587a2cf
namespace fight {
class TrackFactoryCaster_131180 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight {
class StatEndTrialTrack_131180 {};
}
namespace fn_f587a2cf {
extern char DAT_004aad80;
} // namespace fn_f587a2cf
namespace fight {
class TrackFactoryCaster_131200 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight {
class StatTrack_131200 {};
}
namespace fn_f587a2cf {
extern char DAT_004aae18;
} // namespace fn_f587a2cf
namespace hulkfight {
class XPTrack_131280;
}
namespace fn_f587a2cf {
extern char DAT_004aaea8;
} // namespace fn_f587a2cf
namespace fight {
class TrackFactoryCaster_131280 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f587a2cf {
class Track_131e70 {
  public:
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
};
struct H {
  public:
    int call_0012ff10(hulkfight::DialogueTrack*, int);
    int call_0012ffa0(hulkfight::NISSoundTrack*, int);
    int call_00130030(hulkfight::StatTrack*, int);
    int call_001300c0(hulkfight::StatBeginTrialTrack*, int);
    int call_00130150(hulkfight::StatEndTrialTrack*, int);
    int call_001301e0(hulkfight::XPTrack*, int);
};
extern H* FUN_0008d690(int);
struct RefCounted_131ea0 {
  public:
    virtual void f0();
    virtual void Release();
};
class FaceTargetAction : public Action_12ff10 {
  public:
    virtual void _m_vf1();
    FaceTargetAction(int target, RefObj_12ff10* obj);
    union { int mTarget; int m_1c; };
    union { RefObj_12ff10* mObj; RefCounted_131ea0* m_20; };
    FaceTargetAction* vfunc_2(int flag);
};
extern char g_vt_131ea0[];
extern "C" void opdel_0008d330(void*);
class Track_131ef0 {
  public:
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
};
struct RefCounted_131f20 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_131f20[];
class NISSoundAction_131f20 {
  public:
    NISSoundAction_131f20* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_131f20* m_20;
};
class Track_131f70 {
  public:
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
};
struct RefCounted_131fa0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_131fa0[];
class StatAction_131fa0 {
  public:
    StatAction_131fa0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_131fa0* m_20;
};
class Track_131ff0 {
  public:
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
};
struct RefCounted_132020 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_132020[];
class StatBeginTrialAction_132020 {
  public:
    StatBeginTrialAction_132020* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_132020* m_20;
};
class Track_132070 {
  public:
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
};
struct RefCounted_1320a0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_1320a0[];
class StatEndTrialAction_1320a0 {
  public:
    StatEndTrialAction_1320a0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1320a0* m_20;
};
class Track_1320f0 {
  public:
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
};
struct RefCounted_132120 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_132120[];
class XPAction_132120 {
  public:
    XPAction_132120* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_132120* m_20;
};
extern void* g_vftable_1321d0[];
class Ref_1321d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1321d0 {
  public:
    void* vptr;
};
class DebugPrintAction_1321d0 : public Action_1321d0 {
  public:
    char pad[28];
    Ref_1321d0* m;
    DebugPrintAction_1321d0* f2(unsigned char flags);
};
class TrackFactoryCasterTemplate_1324d0 {
  public:
    virtual void Cast();
};
extern void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_1324d0*);
class Owner {
  public:
    void Set_002367c0(void*);
};
class TrackFactoryCasterTemplate_132530 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_132530*);
class TrackFactoryCasterTemplate_132560 {
  public:
    virtual void f();
};
void* __cdecl find_00236ac0(const char*, TrackFactoryCasterTemplate_132560*);
class TrackFactoryCasterTemplate_1325c0 {
  public:
    virtual void Cast();
};
extern "C++" __declspec(nothrow) void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_1325c0*);
class TrackFactoryCasterTemplate_1325f0 {
  public:
    virtual Track* Cast(void*);
};
extern "C++" __declspec(nothrow) void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_1325f0*);
extern int hulk_at_00411a20;
extern "C" char DAT_00411244[];
class Obj_1327f0 {
  public:
    void Init_00234590(int);
    char pad[12];
    int z;
    char c;
};
extern int hulk_at_00411a3c;
struct ConditionFactoryTemplate_132830 {
    void* m_vptr;
    void base1_dtor_0012e380();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern int hulk_at_00411a58;
struct ConditionFactoryTemplate_1328e0 {
    void* m_vptr;
    void base1_dtor_0012e3e0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_00411284[];
struct DebugPrintCondition_132950 {
    hulk_uintptr vptr;
    int a;
    int b;
    int c;
    int d;
    void Init_00234590(int);
};
extern int hulk_at_00411a74;
struct ConditionFactoryTemplate_132990 {
    void* m_vptr;
    void base1_dtor_0012e530();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern int DAT_004112a4;
struct GameStateCondition_132a00 {
    virtual void f0();
    char pad[8];
    int a, b, c, d;
    void Init_00234590(int);
};
extern int hulk_at_00411a90;
struct ConditionFactoryTemplate_132a40 {
    void* m_vptr;
    void base1_dtor_0012e680();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_004112c4[];
struct GameStateCondition_132ab0 {
    hulk_intptr v0;
    int x04;
    int x08;
    int x0c;
    int x10;
    int x14;
    int x18;
    void InitBase_00234590(int);
};
extern int hulk_at_00411aac;
struct ConditionFactoryTemplate_132af0 {
    void* m_vptr;
    void base1_dtor_0012e7d0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_004112e4[];
typedef unsigned int u32_132b60;
extern "C" void* __cdecl alloc(hulk_uintptr);
class Track_132b60 {
  public:
    Track_132b60();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class DialogueTrack_132cc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    int a, b, c, d, e, f;
    char g;
    void Init_00236d40();
};


// 0x0012dfe0 FUN_0012dfe0 (12 B): matches/0x0012dfe0.cpp
// sym: ?Set@Obj_12dfe0@fn_f587a2cf@@QAE_NH@Z
bool Obj_12dfe0::Set(int value) {
    mValue = value;
    return true;
}


// 0x0012dff0 FUN_0012dff0 (12 B): matches/0x0012dff0.cpp
// sym: ?SetUnlockable_0012dff0@Obj@fn_f587a2cf@@QAE_NH@Z
bool Obj::SetUnlockable_0012dff0(int x) {
    value = x;
    return true;
}


// 0x0012e000 FUN_0012e000 (12 B): matches/0x0012e000.cpp
// sym: ?SetLocked_0012e000@X_12e000@fn_f587a2cf@@QAEDD@Z
char X_12e000::SetLocked_0012e000(char v) {
    m10 = v;
    return 1;
}


// 0x0012e010 FUN_0012e010 (12 B): matches/0x0012e010.cpp
// sym: ?SetCompare_0012e010@X_12e010@fn_f587a2cf@@QAEDH@Z
char X_12e010::SetCompare_0012e010(int v) {
    m10 = v;
    return 1;
}


// 0x0012e020 FUN_0012e020 (12 B): matches/0x0012e020.cpp
// sym: ?SetEnvironmentCompare_0012e020@Obj_12e020@fn_f587a2cf@@QAE_NH@Z
bool Obj_12e020::SetEnvironmentCompare_0012e020(int x) {
    mVal = x;
    return true;
}


// 0x0012e030 FUN_0012e030 (12 B): matches/0x0012e030.cpp
// sym: ?SetTimeOfDayCompare_0012e030@Obj_12e030@fn_f587a2cf@@QAE_NPAX@Z
bool Obj_12e030::SetTimeOfDayCompare_0012e030(void* p) {
    m14 = p;
    return true;
}


// 0x0012e050 FUN_0012e050 (12 B): matches/0x0012e050.cpp
// sym: ?Set@T_12e050@fn_f587a2cf@@QAE_NH@Z
bool T_12e050::Set(int x) {
    value = x;
    return true;
}


// 0x0012e060 FUN_0012e060 (12 B): matches/0x0012e060.cpp
// sym: ?Set@Target_12e060@fn_f587a2cf@@QAEDH@Z
char Target_12e060::Set(int value) {
    mValue = value;
    return 1;
}


// 0x0012e080 FUN_0012e080 (12 B): matches/0x0012e080.cpp
// sym: ?Set@Obj_12e080@fn_f587a2cf@@QAEDH@Z
char Obj_12e080::Set(int a) {
    m14 = a;
    return 1;
}


// 0x0012e090 FUN_0012e090 (12 B): matches/0x0012e090.cpp
// sym: ?Set@C_12e090@fn_f587a2cf@@QAEDH@Z
char C_12e090::Set(int v) {
    Value = v;
    return 1;
}

} // namespace fn_f587a2cf

// 0x0012e0a0 FUN_0012e0a0 (12 B): matches/0x0012e0a0.cpp
// sym: ?FUN_0012e0a0@A_12e0a0@owners@@QAE_NH@Z
bool owners::A_12e0a0::FUN_0012e0a0(int value) {
    mValue = value;
    return true;
}

namespace fn_f587a2cf {

// 0x0012e0c0 FUN_0012e0c0 (12 B): matches/0x0012e0c0.cpp
// sym: ?Set@Obj_12e0c0@fn_f587a2cf@@QAE_NH@Z
bool Obj_12e0c0::Set(int x) {
    value = x;
    return true;
}

} // namespace fn_f587a2cf

// 0x0012e100 FUN_0012e100 (12 B): matches/0x0012e100.cpp
// sym: ?FUN_0012e100@Obj_12e100@owners@@QAEDH@Z
char owners::Obj_12e100::FUN_0012e100(int v) {
    mField = v;
    return 1;
}


// 0x0012e130 FUN_0012e130 (12 B): matches/0x0012e130.cpp
// sym: ?FUN_0012e130@X_12e130@owners@@QAEDH@Z
char owners::X_12e130::FUN_0012e130(int v) {
    *(int*)((char*)this + 0x18) = v;
    return 1;
}


// 0x0012e170 FUN_0012e170 (12 B): matches/0x0012e170.cpp
// sym: ?FUN_0012e170@Obj_12e170@owners@@QAEDD@Z
char owners::Obj_12e170::FUN_0012e170(char c) {
    m24 = c;
    return 1;
}

namespace fn_f587a2cf {

// 0x0012e180 FUN_0012e180 (12 B): matches/0x0012e180.cpp
// sym: ?SetTimeBegin_0012e180@Obj_12e180@fn_f587a2cf@@QAE_NH@Z
bool Obj_12e180::SetTimeBegin_0012e180(int v) {
    mValue = v;
    return true;
}


// 0x0012e190 FUN_0012e190 (12 B): matches/0x0012e190.cpp
// sym: ?SetTimeEnd_0012e190@Obj_12e190@fn_f587a2cf@@QAEDH@Z
char Obj_12e190::SetTimeEnd_0012e190(int v) {
    mVal = v;
    return 1;
}

} // namespace fn_f587a2cf

// 0x0012e1c0 FUN_0012e1c0 (12 B): matches/0x0012e1c0.cpp
// sym: ?FUN_0012e1c0@Obj_12e1c0@owners@@QAEDH@Z
char owners::Obj_12e1c0::FUN_0012e1c0(int v) {
    m = v;
    return 1;
}


// 0x0012e1e0 FUN_0012e1e0 (12 B): matches/0x0012e1e0.cpp
// sym: ?FUN_0012e1e0@Obj_12e1e0@owners@@QAE_NH@Z
bool owners::Obj_12e1e0::FUN_0012e1e0(int v) {
    mField = v;
    return true;
}

namespace fn_f587a2cf {

// 0x0012e200 FUN_0012e200 (12 B): matches/0x0012e200.cpp
// sym: ?Set@X_12e200@fn_f587a2cf@@QAEDH@Z
char X_12e200::Set(int value) {
    m12 = value;
    return 1;
}

} // namespace fn_f587a2cf

// 0x0012e220 FUN_0012e220 (12 B): matches/0x0012e220.cpp
// sym: ?FUN_0012e220@C_12e220@owners@@QAE_NH@Z
bool owners::C_12e220::FUN_0012e220(int v) {
    mValue = v;
    return true;
}

namespace fn_f587a2cf {

// 0x0012e230 FUN_0012e230 (19 B): matches/0x0012e230.cpp
// sym: ?FUN_0012e230@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012e230() {
    FUN_00234810(((char*)&DAT_004e0e4c), ((char*)&DAT_004e0e50));
}

} // namespace fn_f587a2cf

// 0x0012e250 hulkfight::MissionProgressCondition::vfunc_0 (16 B): matches/0x0012e250.cpp
// sym: ?vfunc_0@MissionProgressCondition@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::MissionProgressCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e4c;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012e290 FUN_0012e290 (38 B): matches/0x0012e290.cpp
// sym: ?Init@MissionProgressCondition@fn_f587a2cf@@QAEXXZ
void MissionProgressCondition::Init() {
    vf = &hulk_at_00411224;
    thunk_0008d340((void*)a);
    thunk_0008d340((void*)b);
    Tail_002345b0();
}

} // namespace fn_f587a2cf

// 0x0012e2c0 FUN_0012e2c0 (82 B): matches/0x0012e2c0.cpp [wrapped: conflict: strlen]
// sym: ?Set@X@fn_0012e2c0@@QAE_NPBD@Z
namespace fn_0012e2c0 {
/* size_t: tree_prelude.h */
extern "C" void FUN_0008d340(void*);
extern "C++" __declspec(nothrow) void* FUN_0008d6d0(size_t);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" size_t strlen(const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strcpy(char*, const char*);
#endif

class X {
    char pad[12];
    char* str;

  public:
    bool Set(const char* s);
};
bool X::Set(const char* s) {
    FUN_0008d340(str);
    if (!s) {
        str = 0;
        return true;
    }
    str = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(str, s);
    return true;
}
} // namespace fn_0012e2c0

namespace fn_f587a2cf {

// 0x0012e320 FUN_0012e320 (82 B): equivalent/0x0012e320.cpp
// sym: ?FUN_0012e320@Object@fn_f587a2cf@@QAEEPBD@Z @f4449191efda @wdafe9e63c58f
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012e320 @ 0x0012e320
unsigned char Object::FUN_0012e320(const char* source) {
    FUN_0008d340(text);
    if (!source) {
        text = 0;
        return 1;
    }
    const char* end = source;
    while (*end) ++end;
    text = (char*)FUN_0008d6d0((unsigned int)(end - source + 1));
    char* destination = text;
    do {
        *destination++ = *source;
    } while (*source++);
    return 1;
}


// 0x0012e380 FUN_0012e380 (19 B): matches/0x0012e380.cpp
// sym: ?FUN_0012e380@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012e380() {
    FUN_00234810(((char*)&DAT_004e0e54), ((char*)&DAT_004e0e58));
}

} // namespace fn_f587a2cf

// 0x0012e3a0 hulkfight::UnlockableCondition::vfunc_0 (16 B): matches/0x0012e3a0.cpp
// sym: ?vfunc_0@UnlockableCondition@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::UnlockableCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e54;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012e3e0 FUN_0012e3e0 (19 B): matches/0x0012e3e0.cpp
// sym: ?FUN_0012e3e0@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012e3e0() {
    FUN_00234810(((char*)&DAT_004e0e5c), ((char*)&DAT_004e0e60));
}

} // namespace fn_f587a2cf

// 0x0012e400 hulkfight::GameStateCondition::vfunc_0 (16 B): matches/0x0012e400.cpp
// sym: ?vfunc_0@GameStateCondition@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::GameStateCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e5c;
    return p[index];
}


// 0x0012e440 FUN_0012e440 (38 B): matches/0x0012e440.cpp [wrapped: same definition as 0x0012e290 in this TU]
// sym: ?Init@MissionProgressCondition@fn_0012e440@@QAEXXZ
namespace fn_0012e440 {
// Same code shape as 0x0012e290 (propagated; names are from that function)
struct MissionProgressCondition {
    void* vf;
    char pad4[8];
    volatile void* a;
    char pad10[4];
    volatile void* b;
    void Init();
    void Tail_002345b0();
};
extern char missionVftable;
void __cdecl thunk_0008d340(void*);
void MissionProgressCondition::Init() {
    vf = &missionVftable;
    thunk_0008d340((void*)a);
    thunk_0008d340((void*)b);
    Tail_002345b0();
}
} // namespace fn_0012e440

namespace fn_f587a2cf {

// 0x0012e470 FUN_0012e470 (82 B): matches/0x0012e470.cpp
// sym: ?SetMission_0012e470@Obj@fn_f587a2cf@@QAEDPBD@Z
char Obj::SetMission_0012e470(const char* s) {
    Free(name);
    if (!s) {
        name = 0;
        return 1;
    }
    name = (char*)Alloc(strlen(s) + 1);
    strcpy(name, s);
    return 1;
}


// 0x0012e4d0 FUN_0012e4d0 (82 B): matches/0x0012e4d0.cpp
// sym: ?Set@Obj@fn_f587a2cf@@QAE_NPBD@Z
bool Obj::Set(const char* s) {
    thunk_FUN_00267090(str);
    if (!s) {
        str = 0;
        return true;
    }
    str = (char*)malloc(strlen(s) + 1);
    strcpy(str, s);
    return true;
}


// 0x0012e530 FUN_0012e530 (19 B): matches/0x0012e530.cpp
// sym: ?FUN_0012e530@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012e530() {
    FUN_00234810(((char*)&DAT_004e0e64), ((char*)&DAT_004e0e68));
}

} // namespace fn_f587a2cf

// 0x0012e550 hulkfight::DebugPrintCondition::vfunc_0 (16 B): matches/0x0012e550.cpp
// sym: ?vfunc_0@DebugPrintCondition@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::DebugPrintCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e64;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012e590 FUN_0012e590 (38 B): matches/0x0012e590.cpp
// sym: ?dtorish@DebugPrintCondition@fn_f587a2cf@@QAEXXZ
void DebugPrintCondition::dtorish() {
    u32_12e590 x = a;
    vt = &hulk_at_00411284;
    thunk_FUN_00267090(x);
    thunk_FUN_00267090(b);
    Condition_12e590::finish_002345b0();
}

} // namespace fn_f587a2cf

// 0x0012e5c0 FUN_0012e5c0 (82 B): equivalent/0x0012e5c0.cpp
// sym: ?FUN_0012e5c0@Object_12e5c0@owners@@QAE_NPBD@Z @ceb1083b6fd1 @w2ae63d33cad5
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012e5c0 @ 0x0012e5c0
bool owners::Object_12e5c0::FUN_0012e5c0(const char* text) {
    FUN_0008d340(name);
    if (!text) { name = 0; return true; }
    unsigned int length = 0;
    while (text[length]) ++length;
    name = (char*)FUN_0008d6d0(length + 1);
    char* dest = name;
    do { *dest++ = *text; } while (*text++);
    return true;
}


// 0x0012e620 FUN_0012e620 (82 B): equivalent/0x0012e620.cpp
// sym: ?FUN_0012e620@C_12e620@owners@@QAE_NPBD@Z @42521a6c5bc3 @w8be7a7c06f53
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012e620 @ 0x0012e620
bool owners::C_12e620::FUN_0012e620(const char* value) { FUN_0008d340(text); if (!value) { text = 0; return true; } unsigned int size = 1; for (const char* p = value; *p; ++p) ++size; text = (char*)FUN_0008d6d0(size); char* dest = text; do { *dest++ = *value; } while (*value++); return true; }

namespace fn_f587a2cf {

// 0x0012e680 FUN_0012e680 (19 B): matches/0x0012e680.cpp
// sym: ?FUN_0012e680@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012e680() {
    FUN_00234810(((char*)&DAT_004e0e6c), ((char*)&DAT_004e0e70));
}

} // namespace fn_f587a2cf

// 0x0012e6a0 hulkfight::LocationCondition::vfunc_0 (16 B): matches/0x0012e6a0.cpp
// sym: ?vfunc_0@LocationCondition@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::LocationCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e6c;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012e6e0 FUN_0012e6e0 (38 B): matches/0x0012e6e0.cpp
// sym: ?FUN_0012e6e0@fn_f587a2cf@@YIXPAVGameStateCondition_12e6e0@1@@Z
void __fastcall FUN_0012e6e0(GameStateCondition_12e6e0* p) {
    p->x[0] = (hulk_uintptr)&hulk_at_004112a4;
    ReleaseThing_0008d340(p->x[4]);
    ReleaseThing_0008d340(p->x[6]);
    p->Finish_002345b0();
}

} // namespace fn_f587a2cf

// 0x0012e710 FUN_0012e710 (82 B): equivalent/0x0012e710.cpp [wrapped: conflict: FUN_0008d340]
// sym: ?SetEnvironment_0012e710@Obj@fn_0012e710@@QAEIPBD@Z @ba96014dfacf @wa9d6b9a54db2
namespace fn_0012e710 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// SetEnvironment_0012e710 @ 0x0012e710
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Obj { char pad[0x10]; char *text; unsigned int SetEnvironment_0012e710(const char *value); };
unsigned int Obj::SetEnvironment_0012e710(const char *value) {
    unsigned int result = FUN_0008d340(text);
    if (!value) { text = 0; return (result & ~255u) | 1; }
    unsigned int length = 1;
    const char *p = value;
    while (*p++) ++length;
    char *allocated = (char *)FUN_0008d6d0(length);
    text = allocated;
    char *out = allocated;
    do { *out++ = *value; } while (*value++);
    return ((hulk_uintptr)allocated & ~255u) | 1;
}
} // namespace fn_0012e710


// 0x0012e770 FUN_0012e770 (82 B): equivalent/0x0012e770.cpp [wrapped: conflict: FUN_0008d340; FUN_0008d6d0; Object]
// sym: ?SetTimeOfDay_0012e770@Object@fn_0012e770@@QAEHPBD@Z @0703693ede6c @w7495cc681be3
namespace fn_0012e770 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// SetTimeOfDay_0012e770 @ 0x0012e770
struct Object { char pad[0x18]; char* text; hulk_intptr SetTimeOfDay_0012e770(const char* source); };
int __cdecl FUN_0008d340(void*);
char* __cdecl FUN_0008d6d0(unsigned int);
hulk_intptr Object::SetTimeOfDay_0012e770(const char* source) {
    hulk_intptr result = FUN_0008d340(text);
    if (!source) { text = 0; return (result & ~255) | 1; }
    const char* end = source;
    while (*end++) {}
    text = FUN_0008d6d0((unsigned int)(end - source));
    result = (hulk_intptr)text;
    char* dest = text;
    char c;
    do { c = *source++; *dest++ = c; } while (c);
    return (result & ~255) | 1;
}
} // namespace fn_0012e770

namespace fn_f587a2cf {

// 0x0012e7d0 FUN_0012e7d0 (19 B): matches/0x0012e7d0.cpp
// sym: ?FUN_0012e7d0@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012e7d0() {
    FUN_00234810(((char*)&DAT_004e0e74), ((char*)&DAT_004e0e78));
}

} // namespace fn_f587a2cf

// 0x0012e7f0 hulkfight::ChapterMissionCondition::vfunc_0 (16 B): matches/0x0012e7f0.cpp
// sym: ?vfunc_0@ChapterMissionCondition@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ChapterMissionCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e74;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012e840 FUN_0012e840 (19 B): matches/0x0012e840.cpp
// sym: ?FUN_0012e840@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012e840() {
    FUN_00234810(((char*)&DAT_004e0e7c), ((char*)&DAT_004e0e80));
}

} // namespace fn_f587a2cf

// 0x0012e860 hulkfight::StatBeginTrialTrack::vfunc_0 (16 B): matches/0x0012e860.cpp
// sym: ?vfunc_0@StatBeginTrialTrack@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::StatBeginTrialTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e7c;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012e870 FUN_0012e870 (26 B): matches/0x0012e870.cpp
// sym: ??0StatBeginTrialTrack@fn_f587a2cf@@QAE@XZ
StatBeginTrialTrack::StatBeginTrialTrack() {
    a = 0;
    b = 0;
}

} // namespace fn_f587a2cf

// 0x0012e890 hulkfight::StatBeginTrialTrack::vfunc_6 (4 B): matches/0x0012e890.cpp
// sym: ?vfunc_6@StatBeginTrialTrack@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::StatBeginTrialTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0012e8a0 hulkfight::StatBeginTrialTrack::vfunc_7 (7 B): matches/0x0012e8a0.cpp
// sym: ?vfunc_7@StatBeginTrialTrack@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::StatBeginTrialTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f587a2cf {

// 0x0012e8b0 FUN_0012e8b0 (29 B): matches/0x0012e8b0.cpp
// sym: ?run@CRawScript@fn_f587a2cf@@QAEXXZ
// Same code shape as 0x000f99b0 (propagated; names are from that function)
void CRawScript::run() {
    vptr = &rawVtable;
    thunk_0008d340(mArg);
    finish();
}

} // namespace fn_f587a2cf

// 0x0012e8d0 FUN_0012e8d0 (82 B): matches/0x0012e8d0.cpp [wrapped: conflict: X; X::Set]
// sym: ?Set@X@fn_0012e8d0@@QAEDPBD@Z
namespace fn_0012e8d0 {
extern "C" void FUN_0008d340(void*);
extern "C++" __declspec(nothrow) void* FUN_0008d6d0(unsigned int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int strlen(const char*);
#endif

inline void Copy(char* dst, const char* src) {
    char c;
    do {
        c = *src;
        ++src;
        *dst = c;
        ++dst;
    } while (c);
}
class X {
    char pad[16];
    char* str;

  public:
    char Set(const char* s);
};
char X::Set(const char* s) {
    FUN_0008d340(str);
    if (!s) {
        str = 0;
        return 1;
    }
    char* d = (char*)FUN_0008d6d0(strlen(s) + 1);
    str = d;
    Copy(d, s);
    return 1;
}
} // namespace fn_0012e8d0

namespace fn_f587a2cf {

// 0x0012e930 FUN_0012e930 (19 B): matches/0x0012e930.cpp
// sym: ?FUN_0012e930@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012e930() {
    FUN_00234810(((char*)&DAT_004e0e84), ((char*)&DAT_004e0e88));
}

} // namespace fn_f587a2cf

// 0x0012e950 hulkfight::NISSoundTrack::vfunc_0 (16 B): matches/0x0012e950.cpp
// sym: ?vfunc_0@NISSoundTrack@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::NISSoundTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e84;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012e960 FUN_0012e960 (39 B): matches/0x0012e960.cpp
// sym: ??0NISSoundTrack@fn_f587a2cf@@QAE@XZ
NISSoundTrack::NISSoundTrack() {
    value = 1;
}

} // namespace fn_f587a2cf

// 0x0012e990 hulkfight::NISSoundTrack::vfunc_6 (4 B): matches/0x0012e990.cpp
// sym: ?vfunc_6@NISSoundTrack@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::NISSoundTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0012e9a0 hulkfight::NISSoundTrack::vfunc_7 (7 B): matches/0x0012e9a0.cpp
// sym: ?vfunc_7@NISSoundTrack@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::NISSoundTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0012e9b0 FUN_0012e9b0 (47 B): matches/0x0012e9b0.cpp [wrapped: conflict: NISSoundTrack]
// sym: ?Destroy@NISSoundTrack@fn_0012e9b0@@QAEXXZ
namespace fn_0012e9b0 {
extern "C" char DAT_00411314[];
typedef unsigned int u32_12e9b0;
struct NISSoundTrack {
    hulk_uintptr vptr;
    char pad[12];
    u32_12e9b0 a, b, c;
    void BaseDestroy_00236d60();
    void Destroy();
};
extern void __cdecl ReleaseThing_0008d340(u32_12e9b0);
void NISSoundTrack::Destroy() {
    vptr = ((hulk_intptr)DAT_00411314);
    ReleaseThing_0008d340(a);
    ReleaseThing_0008d340(b);
    ReleaseThing_0008d340(c);
    BaseDestroy_00236d60();
}
} // namespace fn_0012e9b0


// 0x0012e9e0 FUN_0012e9e0 (82 B): equivalent/0x0012e9e0.cpp [wrapped: conflict: FUN_0008d340; FUN_0008d6d0]
// sym: ?FUN_0012e9e0@Object@fn_0012e9e0@@QAEIPBD@Z @6421589101a5 @w7959d6fe2bc5
namespace fn_0012e9e0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012e9e0 @ 0x0012e9e0
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_0008d340(void*);
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_0008d6d0(unsigned int);
struct Object {
 char pad[0x10];
 char* value;
 unsigned int FUN_0012e9e0(const char* text);
};
unsigned int Object::FUN_0012e9e0(const char* text) {
 hulk_uintptr result = FUN_0008d340(value);
 if (!text) {
  value = 0;
  return (result & 0xffffff00) | 1;
 }
 unsigned int length = 0;
 while (text[length]) ++length;
 result = FUN_0008d6d0(length + 1);
 value = (char*)result;
 char* dest = value;
 do { *dest++ = *text; } while (*text++);
 return (result & 0xffffff00) | 1;
}
} // namespace fn_0012e9e0


// 0x0012ea40 FUN_0012ea40 (82 B): matches/0x0012ea40.cpp [wrapped: conflict: Obj; Obj::Set]
// sym: ?Set@Obj@fn_0012ea40@@QAEEPBD@Z
namespace fn_0012ea40 {
extern "C" void __cdecl FUN_0008d340(void*);
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d6d0(hulk_uintptr);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strcpy(char*, const char*);
#endif

class Obj {
    char pad[0x14];
    char* p;

  public:
    unsigned char Set(const char* s);
};
unsigned char Obj::Set(const char* s) {
    FUN_0008d340(p);
    if (!s) {
        p = 0;
        return 1;
    }
    p = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(p, s);
    return 1;
}
} // namespace fn_0012ea40


// 0x0012eaa0 FUN_0012eaa0 (82 B): equivalent/0x0012eaa0.cpp [wrapped: conflict: FUN_0008d340; Obj]
// sym: ?FUN_0012eaa0@Obj@fn_0012eaa0@@QAEHPBD@Z @e0221e0d3234 @w7d3f4bae3f6b
namespace fn_0012eaa0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012eaa0 @ 0x0012eaa0
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d340(void*); extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d6d0(unsigned int); struct Obj { char pad[0x18]; char* text; hulk_intptr FUN_0012eaa0(const char* value); }; hulk_intptr Obj::FUN_0012eaa0(const char* value) { void* freed = FUN_0008d340(text); if (!value) { text = 0; return ((hulk_intptr)freed & ~255) | 1; } unsigned int len = 0; while (value[len]) ++len; char* allocated = (char*)FUN_0008d6d0(len + 1); text = allocated; char* dest = allocated; do { *dest++ = *value; } while (*value++); return ((hulk_intptr)allocated & ~255) | 1; }
} // namespace fn_0012eaa0

namespace fn_f587a2cf {

// 0x0012eb00 FUN_0012eb00 (19 B): matches/0x0012eb00.cpp
// sym: ?FUN_0012eb00@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012eb00() {
    FUN_00234810(((char*)&DAT_004e0e8c), ((char*)&DAT_004e0e90));
}

} // namespace fn_f587a2cf

// 0x0012eb20 hulkfight::DialogueTrack::vfunc_0 (16 B): matches/0x0012eb20.cpp
// sym: ?vfunc_0@DialogueTrack@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::DialogueTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e8c;
    return p[index];
}


// 0x0012eb30 FUN_0012eb30 (48 B): matches/0x0012eb30.cpp [wrapped: conflict: hulkfight::DialogueTrack]
// sym: ??0DialogueTrack@hulkfight@fn_0012eb30@@QAE@XZ
namespace fn_0012eb30 {
class Track_12eb30 {
  public:
    Track_12eb30();
    virtual void f();
    int x;
};
namespace hulkfight {
class DialogueTrack : public Track_12eb30 {
  public:
    DialogueTrack();
    virtual void f();
    int unknown, a, b, c, d, e, g;
    char flag;
};
} // namespace hulkfight
hulkfight::DialogueTrack::DialogueTrack() : Track_12eb30(), a(0), b(0), c(0), d(0), e(0), g(0), flag(0) {
    unknown = 1;
}
} // namespace fn_0012eb30


// 0x0012eb60 hulkfight::DialogueTrack::vfunc_6 (4 B): matches/0x0012eb60.cpp
// sym: ?vfunc_6@DialogueTrack@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::DialogueTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0012eb70 hulkfight::DialogueTrack::vfunc_7 (7 B): matches/0x0012eb70.cpp
// sym: ?vfunc_7@DialogueTrack@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::DialogueTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f587a2cf {

// 0x0012eb80 FUN_0012eb80 (56 B): matches/0x0012eb80.cpp
// sym: ?destroy@DialogueTrack@fn_f587a2cf@@QAEXXZ
void DialogueTrack::destroy() {
    vf = (void*)((hulk_intptr)DAT_00411344);
    release_0008d340(a);
    release_0008d340(b);
    release_0008d340(c);
    release_0008d340(d);
    final_fn_00236d60(this);
}

} // namespace fn_f587a2cf

// 0x0012ebc0 FUN_0012ebc0 (82 B): equivalent/0x0012ebc0.cpp [wrapped: conflict: Object]
// sym: ?FUN_0012ebc0@Object@fn_0012ebc0@@QAE_NPBD@Z @22db57b6ceaa @w0225d9ec3efd
namespace fn_0012ebc0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ebc0 @ 0x0012ebc0
extern "C" void __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char pad[16]; char *text; bool FUN_0012ebc0(const char *value); };
bool Object::FUN_0012ebc0(const char *value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return true;
    }
    unsigned int length = 0;
    do { ++length; } while (value[length - 1]);
    text = (char *)FUN_0008d6d0(length);
    char *destination = text;
    do { *destination++ = *value; } while (*value++);
    return true;
}
} // namespace fn_0012ebc0


// 0x0012ec20 FUN_0012ec20 (82 B): equivalent/0x0012ec20.cpp
// sym: ?FUN_0012ec20@Object_12ec20@owners@@QAE_NPBD@Z @fb12656ebe36 @wc1c995f6464c
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ec20 @ 0x0012ec20
bool owners::Object_12ec20::FUN_0012ec20(const char* input) { FUN_0008d340(text); if (!input) { text = 0; return true; } unsigned int length = 0; while (input[length]) ++length; text = (char*)FUN_0008d6d0(length + 1); char* dst = text; do { *dst++ = *input; } while (*input++); return true; }


// 0x0012ece0 FUN_0012ece0 (82 B): equivalent/0x0012ece0.cpp
// sym: ?FUN_0012ece0@Thing_12ece0@owners@@QAEEPBD@Z @6747492f8a9e @wd82974c3248d
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ece0 @ 0x0012ece0
unsigned char owners::Thing_12ece0::FUN_0012ece0(const char* value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return 1;
    }
    const char* end = value;
    while (*end) ++end;
    text = (char*)FUN_0008d6d0((unsigned int)(end - value + 1));
    char* dest = text;
    do {
        *dest++ = *value;
    } while (*value++);
    return 1;
}

namespace fn_f587a2cf {

// 0x0012ed40 FUN_0012ed40 (19 B): matches/0x0012ed40.cpp
// sym: ?FUN_0012ed40@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012ed40() {
    FUN_00234810(((char*)&DAT_004e0e94), ((char*)&DAT_004e0e98));
}

} // namespace fn_f587a2cf

// 0x0012ed60 hulkfight::DebugPrintTrack::vfunc_0 (16 B): matches/0x0012ed60.cpp
// sym: ?vfunc_0@DebugPrintTrack@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::DebugPrintTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e94;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012ed70 FUN_0012ed70 (43 B): matches/0x0012ed70.cpp
// sym: ??0DebugPrintTrack@fn_f587a2cf@@QAE@XZ
DebugPrintTrack::DebugPrintTrack() : Track_12ed70(), p(0), value(-1.0f), a(0), b(0) {
    count = 1;
}

} // namespace fn_f587a2cf

// 0x0012eda0 hulkfight::DebugPrintTrack::vfunc_6 (4 B): matches/0x0012eda0.cpp
// sym: ?vfunc_6@DebugPrintTrack@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::DebugPrintTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0012edb0 hulkfight::DebugPrintTrack::vfunc_7 (7 B): matches/0x0012edb0.cpp
// sym: ?vfunc_7@DebugPrintTrack@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::DebugPrintTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0012edc0 FUN_0012edc0 (38 B): matches/0x0012edc0.cpp [wrapped: conflict: DebugPrintTrack]
// sym: ?Cleanup@DebugPrintTrack@fn_0012edc0@@QAEXXZ
namespace fn_0012edc0 {
extern "C" char DAT_00411374[];
typedef unsigned int u32_12edc0;
extern void __cdecl ReleaseThing_0008d340(u32_12edc0);
struct DebugPrintTrack {
    hulk_uintptr vftable;
    char pad4[0x10];
    u32_12edc0 a;
    u32_12edc0 b;
    void Cleanup();
};
extern void __fastcall Finish_00236d60(DebugPrintTrack*);
void DebugPrintTrack::Cleanup() {
    vftable = ((hulk_intptr)DAT_00411374);
    ReleaseThing_0008d340(a);
    ReleaseThing_0008d340(b);
    Finish_00236d60(this);
}
} // namespace fn_0012edc0


// 0x0012edf0 FUN_0012edf0 (82 B): matches/0x0012edf0.cpp [wrapped: same definition as 0x0012e4d0 in this TU]
// sym: ?Set@Obj@fn_0012edf0@@QAE_NPBD@Z
namespace fn_0012edf0 {
extern "C++" __declspec(nothrow) void __cdecl Free_0008d340(void*);
extern "C++" __declspec(nothrow) void* __cdecl Alloc_0008d6d0(hulk_uintptr);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strcpy(char*, const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif

class Obj {
    char pad[0x14];
    char* str;

  public:
    bool Set(const char* s);
};
bool Obj::Set(const char* s) {
    Free_0008d340(str);
    if (!s) {
        str = 0;
        return true;
    }
    str = (char*)Alloc_0008d6d0(strlen(s) + 1);
    strcpy(str, s);
    return true;
}
} // namespace fn_0012edf0


// 0x0012ee50 FUN_0012ee50 (82 B): equivalent/0x0012ee50.cpp [wrapped: conflict: FUN_0008d340; Object]
// sym: ?SetChannel_0012ee50@Object@fn_0012ee50@@QAEIPBD@Z @9913d0a3788a @w4254c54bcbab
namespace fn_0012ee50 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// SetChannel_0012ee50 @ 0x0012ee50
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_0008d340(void*); extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d6d0(unsigned int); struct Object { char pad[0x18]; char* text; unsigned int SetChannel_0012ee50(const char* value); }; unsigned int Object::SetChannel_0012ee50(const char* value) { hulk_uintptr result = FUN_0008d340(text); if (!value) { text = 0; return (result & ~255u) | 1; } unsigned int length = 0; do { ++length; } while (value[length-1]); text = (char*)FUN_0008d6d0(length); result = (hulk_uintptr)text; char* dest = text; do { *dest++ = *value; } while (*value++); return (result & ~255u) | 1; }
} // namespace fn_0012ee50

namespace fn_f587a2cf {

// 0x0012eeb0 FUN_0012eeb0 (19 B): matches/0x0012eeb0.cpp
// sym: ?FUN_0012eeb0@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012eeb0() {
    FUN_00234810(((char*)&DAT_004e0e9c), ((char*)&DAT_004e0ea0));
}

} // namespace fn_f587a2cf

// 0x0012eed0 hulkfight::StatEndTrialTrack::vfunc_0 (16 B): matches/0x0012eed0.cpp
// sym: ?vfunc_0@StatEndTrialTrack@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::StatEndTrialTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e9c;
    return p[index];
}


// 0x0012eee0 FUN_0012eee0 (26 B): matches/0x0012eee0.cpp [wrapped: conflict: hulkfight::StatEndTrialTrack]
// sym: ??0StatEndTrialTrack@hulkfight@fn_0012eee0@@QAE@XZ
namespace fn_0012eee0 {
namespace hulkfight {
class Base {
  public:
    virtual void f();
    char pad[8];
    Base();
};
class StatEndTrialTrack : public Base {
  public:
    int a, b;
    StatEndTrialTrack();
    virtual void f();
};
StatEndTrialTrack::StatEndTrialTrack() : Base(), a(0), b(0) {}
} // namespace hulkfight
} // namespace fn_0012eee0


// 0x0012ef00 hulkfight::StatEndTrialTrack::vfunc_6 (4 B): matches/0x0012ef00.cpp
// sym: ?vfunc_6@StatEndTrialTrack@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::StatEndTrialTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0012ef10 hulkfight::StatEndTrialTrack::vfunc_7 (7 B): matches/0x0012ef10.cpp
// sym: ?vfunc_7@StatEndTrialTrack@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::StatEndTrialTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0012ef20 FUN_0012ef20 (29 B): matches/0x0012ef20.cpp [wrapped: same definition as 0x0012e8b0 in this TU]
// sym: ?run@CRawScript@fn_0012ef20@@QAEXXZ
namespace fn_0012ef20 {
// Same code shape as 0x000f99b0 (propagated; names are from that function)
extern int rawVtable;
class CRawScript {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish_00236d60();
    void run();
};
extern void __cdecl thunk_0008d340(int);
void CRawScript::run() {
    vptr = &rawVtable;
    thunk_0008d340(mArg);
    finish_00236d60();
}
} // namespace fn_0012ef20

namespace fn_f587a2cf {

// 0x0012efa0 FUN_0012efa0 (19 B): matches/0x0012efa0.cpp
// sym: ?FUN_0012efa0@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012efa0() {
    FUN_00234810(((char*)&DAT_004e0ea4), ((char*)&DAT_004e0ea8));
}

} // namespace fn_f587a2cf

// 0x0012efc0 hulkfight::StatTrack::vfunc_0 (16 B): matches/0x0012efc0.cpp
// sym: ?vfunc_0@StatTrack@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::StatTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ea4;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012efd0 FUN_0012efd0 (26 B): matches/0x0012efd0.cpp
// sym: ??0StatTrack@fn_f587a2cf@@QAE@XZ
StatTrack::StatTrack() : Track_12efd0() {
    a = 0;
    b = 0;
}

} // namespace fn_f587a2cf

// 0x0012eff0 hulkfight::StatTrack::vfunc_6 (4 B): matches/0x0012eff0.cpp
// sym: ?vfunc_6@StatTrack@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::StatTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0012f000 hulkfight::StatTrack::vfunc_7 (7 B): matches/0x0012f000.cpp
// sym: ?vfunc_7@StatTrack@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::StatTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0012f010 FUN_0012f010 (29 B): matches/0x0012f010.cpp [wrapped: same definition as 0x0012e8b0 in this TU]
// sym: ?run@CRawScript@fn_0012f010@@QAEXXZ
namespace fn_0012f010 {
// Same code shape as 0x000f99b0 (propagated; names are from that function)
extern int hulk_at_004113d4;
class CRawScript {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish_00236d60();
    void run();
};
extern void __cdecl thunk_0008d340(int);
void CRawScript::run() {
    vptr = &hulk_at_004113d4;
    thunk_0008d340(mArg);
    finish_00236d60();
}
} // namespace fn_0012f010


// 0x0012f030 FUN_0012f030 (82 B): matches/0x0012f030.cpp [wrapped: conflict: Obj; Obj::Set]
// sym: ?Set@Obj@fn_0012f030@@QAEEPBD@Z
namespace fn_0012f030 {
extern "C" void __cdecl FUN_0008d340(void*);
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d6d0(hulk_uintptr);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strcpy(char*, const char*);
#endif

class Obj {
    char pad[16];
    char* s;

  public:
    unsigned char Set(const char* p);
};
unsigned char Obj::Set(const char* p) {
    FUN_0008d340(s);
    if (!p) {
        s = 0;
        return 1;
    }
    s = (char*)FUN_0008d6d0(strlen(p) + 1);
    strcpy(s, p);
    return 1;
}
} // namespace fn_0012f030

namespace fn_f587a2cf {

// 0x0012f090 FUN_0012f090 (19 B): matches/0x0012f090.cpp
// sym: ?FUN_0012f090@fn_f587a2cf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012f090() {
    FUN_00234810(((char*)&DAT_004e0eac), ((char*)&DAT_004e0eb0));
}

} // namespace fn_f587a2cf

// 0x0012f0b0 hulkfight::XPTrack::vfunc_0 (16 B): matches/0x0012f0b0.cpp
// sym: ?vfunc_0@XPTrack@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::XPTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0eac;
    return p[index];
}

namespace fn_f587a2cf {

// 0x0012f0c0 FUN_0012f0c0 (26 B): matches/0x0012f0c0.cpp
// sym: ??0XPTrack@fn_f587a2cf@@QAE@XZ
XPTrack::XPTrack() {
    m12 = 0;
    m16 = 0;
}

} // namespace fn_f587a2cf

// 0x0012f0e0 hulkfight::XPTrack::vfunc_6 (4 B): matches/0x0012f0e0.cpp
// sym: ?vfunc_6@XPTrack@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::XPTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0012f0f0 hulkfight::XPTrack::vfunc_7 (7 B): matches/0x0012f0f0.cpp
// sym: ?vfunc_7@XPTrack@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::XPTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0012f110 hulkfight::UnlockableCondition::vfunc_6 (235 B): equivalent/0x0012f110.cpp [wrapped: conflict: FUN_00344e74; hulkfight::UnlockableCondition]
// sym: ?vfunc_6@UnlockableCondition@hulkfight@fn_0012f110@@UAE_NHHH@Z @e89975909e46 @w5d0012d03b8e
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0012f110 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// hulkfight::UnlockableCondition::vfunc_6 @ 0x0012f110
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

struct Info_12f110 {
 char pad[8]; unsigned char enabled; char rest[23]; unsigned char state;
 unsigned char FUN_00091f40();
};
struct Registry_12f110 { Info_12f110* FUN_00092ad0(int); };
struct Singleton_4dd6ec { Registry_12f110* FUN_00086340(); };
extern char DAT_0049dab8, DAT_0049dafc, DAT_0049db1c;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace hulkfight {
struct UnlockableCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int,int,int);
 char pad[8]; int id; unsigned char desired;
};
bool UnlockableCondition::vfunc_6(int,int,int) {
 Registry_12f110* registry = DAT_004dd6ec->FUN_00086340();
 Info_12f110* info = registry->FUN_00092ad0(id);
 if (!info) return false;
 Info_12f110* first = (Info_12f110*)FUN_00344e74(info,0,&DAT_0049dab8,&DAT_0049dafc,0);
 if (first) return first->enabled == desired && first->state == (desired == 0);
 Info_12f110* second = (Info_12f110*)FUN_00344e74(info,0,&DAT_0049dab8,&DAT_0049db1c,0);
 if (!second) return true;
 Info_12f110* special = (Info_12f110*)FUN_00344e74(registry->FUN_00092ad0(29),0,&DAT_0049dab8,&DAT_0049dafc,0);
 if (special && special->enabled == 0 && special->state != 0) return true;
 if (second->enabled != desired) return false;
 unsigned char state = second->FUN_00091f40();
 return state == (desired == 0);
}
}
} // namespace fn_0012f110
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0012f200 hulkfight::ChapterMissionCondition::vfunc_6 (238 B): equivalent/0x0012f200.cpp [wrapped: conflict: hulkfight::ChapterMissionCondition]
// sym: ?vfunc_6@ChapterMissionCondition@hulkfight@fn_0012f200@@UAEHHHH@Z @9ae8f370ae05 @w68571b33809c
namespace fn_0012f200 {
// STATUS: equivalent (tools/equiv.py level 3: 3096 inputs, branch coverage 36/48, incomplete)
// hulkfight::ChapterMissionCondition::vfunc_6 @ 0x0012f200
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

struct MissionState { int FUN_00088fa0(); int FUN_00088fb0(); };
struct Mission_12f200 { char pad[0x80]; MissionState state; };
struct Manager_12f200 { Mission_12f200* FUN_00086310(); };
struct World { char pad[0x54]; Manager_12f200* manager; };
namespace hulkfight {
struct ChapterMissionCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual int vfunc_6(int,int,int);
 char pad[8]; int chapterOperator; int chapter; int missionOperator; int mission;
};
int ChapterMissionCondition::vfunc_6(int,int,int) {
 bool a=true,b=true;
 Mission_12f200* current=DAT_004dd700->manager->FUN_00086310();
 if(chapter>=0) {
 int value=current->state.FUN_00088fa0();
 switch(chapterOperator) {
 case 0:a=value<chapter;break;
 case 1:a=value<=chapter;break;
 case 2:a=value==chapter;break;
 case 3:a=value!=chapter;break;
 case 4:a=value>=chapter;break;
 case 5:a=value>chapter;break;
 default:a=false;break;
 }
 }
 if(mission>=0) {
 int value=current->state.FUN_00088fb0();
 switch(missionOperator) {
 case 0:b=value<mission;break;
 case 1:b=value<=mission;break;
 case 2:b=value==mission;break;
 case 3:b=value!=mission;break;
 case 4:b=value>=mission;break;
 case 5:b=value>mission;break;
 default:b=false;break;
 }
 }
 return a && b ? 1:0;
}
}
} // namespace fn_0012f200
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0012f320 hulkfight::LocationCondition::vfunc_6 (211 B): equivalent/0x0012f320.cpp [wrapped: conflict: World; hulkfight::LocationCondition]
// sym: ?vfunc_6@LocationCondition@hulkfight@fn_0012f320@@UAE_NHHH@Z @eb212eed23ee @w935b6a013695
namespace fn_0012f320 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// hulkfight::LocationCondition::vfunc_6 @ 0x0012f320
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

struct NameSource_12f320 { const char* FUN_000897e0(); };
struct Manager_12f320 { NameSource_12f320* FUN_00086310(); };
struct World { char pad[0x54]; Manager_12f320* manager; };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl strncmp(const char*, const char*, unsigned int);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strrchr(const char*, int);
#endif

namespace hulkfight {
struct LocationCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int,int,int);
 char pad[8]; int prefixMode; const char* prefix; int suffixMode; const char* suffix;
};
bool LocationCondition::vfunc_6(int,int,int) {
 const char* name = DAT_004dd700->manager->FUN_00086310()->FUN_000897e0();
 if (!name) name = ((const char*)&DAT_003f335c);
 if (prefixMode != 2) {
  const char* p = prefix ? prefix : ((const char*)&DAT_003f335c);
  unsigned int n=0; while(p[n]) ++n;
  int result = strncmp(name,p,n);
  if (result ? prefixMode == 0 : prefixMode != 0) return false;
 }
 if (suffixMode != 2) {
  const char* tail = strrchr(name,'_');
  if (!tail) tail = ((const char*)&DAT_003f335c);
  else if (*tail) ++tail;
  const char* p = suffix ? suffix : ((const char*)&DAT_003f335c);
  unsigned int n=0; while(p[n]) ++n;
  int result = strncmp(tail,p,n);
  if (result ? suffixMode == 0 : suffixMode != 0) return false;
 }
 return true;
}
}
} // namespace fn_0012f320
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0012f670 hulkfight::MissionProgressCondition::vfunc_6 (221 B): equivalent/0x0012f670.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_6@MissionProgressCondition@hulkfight@fn_0012f670@@UAE_NHHH@Z @560a614dce6b @w4f8d8cad3b58
namespace fn_0012f670 {
// STATUS: equivalent (tools/equiv.py level 3: 20043 inputs, branch coverage 28/32, incomplete)
// hulkfight::MissionProgressCondition::vfunc_6 @ 0x0012f670
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

struct Names_12f670 {
    const char *FUN_0008a060(int id);
};

struct NameTable {
    Names_12f670 *FUN_00086310();
};

struct World {
    char pad00[0x54];
    NameTable *table;
};


static int StrCmp(const char *a, const char *b)
{
    while (*a == *b) {
        if (*a == 0)
            return 0;
        a++;
        b++;
    }
    return (unsigned char)*a < (unsigned char)*b ? -1 : 1;
}

namespace hulkfight {
class MissionProgressCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, int b, int c);
    char pad04[8];
    int id;
    int mode;
    const char *expected;
};
}

bool hulkfight::MissionProgressCondition::vfunc_6(int a, int b, int c)
{
    if (expected == 0 || id == 0)
        return false;
    int key = id; // MSVC reads the argument before calling FUN_00086310; clang would read it after
    const char *current = DAT_004dd700->table->FUN_00086310()->FUN_0008a060(key);
    switch (mode) {
    case 0:
        return StrCmp(current, expected) == 0;
    case 1:
        return StrCmp(current, expected) != 0;
    }
    return false;
}
} // namespace fn_0012f670
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0012f910 hulkfight::DialogueAction::vfunc_5 (5 B): matches/0x0012f910.cpp
// sym: ?vfunc_5@DialogueAction@hulkfight@@UAE_NHH@Z
// Same code shape as 0x0012da20 (propagated; names are from that function)
bool hulkfight::DialogueAction::vfunc_5(hulk_intptr a, int b) {
    return (bool)(1);
}

namespace fn_f587a2cf {

// 0x0012f920 hulkfight::DialogueAction::vfunc_4 (1 B): matches/0x0012f920.cpp
// sym: ?FUN_0012f920@fn_f587a2cf@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0012f920() {}

} // namespace fn_f587a2cf

// 0x0012f930 hulkfight::NISSoundAction::vfunc_3 (90 B): equivalent/0x0012f930.cpp [wrapped: conflict: Singleton_4dd6ec; hulkfight::NISSoundAction]
// sym: ?vfunc_3@NISSoundAction@hulkfight@fn_0012f930@@UAE_NHH@Z @f0ace26cb039 @wb95eaf61ce5b
namespace fn_0012f930 {
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 2/2)
// hulkfight::NISSoundAction::vfunc_3 @ 0x0012f930
// hulkfight::NISSoundAction::vfunc_3 @ 0x0012f930
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

struct SoundValue { unsigned int data[2]; void FUN_0027b0e0(unsigned int); void FUN_0027af50(); };
struct SoundInfo { char pad[16]; unsigned int sound; unsigned int value; unsigned int extra; };
struct Singleton_4dd6ec {};
struct SoundHandle { void FUN_001eb5e0(SoundValue *, unsigned int, unsigned int); };
extern "C" SoundHandle *__fastcall FUN_000862e0(Singleton_4dd6ec *);
namespace hulkfight {
struct NISSoundAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x1c-4]; SoundInfo *info; unsigned int enabled;
};
bool NISSoundAction::vfunc_3(int, int) {
 if (!enabled) return false;
 SoundValue value;
 value.FUN_0027b0e0(info->value);
 unsigned int extra = info->extra;
 unsigned int sound = info->sound;
 SoundHandle *handle = FUN_000862e0(DAT_004dd6ec);
 handle->FUN_001eb5e0(&value, sound, extra);
 value.FUN_0027af50();
 return true;
}
}
} // namespace fn_0012f930
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0012f990 hulkfight::NISSoundAction::vfunc_5 (5 B): matches/0x0012f990.cpp
// sym: ?vfunc_5@NISSoundAction@hulkfight@@UAE_NHH@Z
// Same code shape as 0x0012da20 (propagated; names are from that function)
bool hulkfight::NISSoundAction::vfunc_5(hulk_intptr a, int b) {
    return (bool)(1);
}

namespace fn_f587a2cf {

// 0x0012f9a0 hulkfight::NISSoundAction::vfunc_4 (1 B): matches/0x0012f9a0.cpp
// sym: ?FUN_0012f9a0@fn_f587a2cf@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0012f9a0() {}

} // namespace fn_f587a2cf

// 0x0012f9b0 hulkfight::StatAction::vfunc_3 (44 B): matches/0x0012f9b0.cpp
// sym: ?vfunc_3@StatAction@hulkfight@@UAE_NHH@Z
bool hulkfight::StatAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if (!this->f_20)
        return false;
    u32_12f9b0 x = *(u32_12f9b0*)((char*)this->f_1c + 0x10);
    hulk_at_004dd6ec->doA_00086370()->doB_00090720(x, 1);
    return true;
}


// 0x0012f9e0 hulkfight::StatAction::vfunc_5 (5 B): matches/0x0012f9e0.cpp
// sym: ?vfunc_5@StatAction@hulkfight@@UAE_NHH@Z
// Same code shape as 0x0012da20 (propagated; names are from that function)
bool hulkfight::StatAction::vfunc_5(hulk_intptr a, int b) {
    return (bool)(1);
}

namespace fn_f587a2cf {

// 0x0012f9f0 hulkfight::StatAction::vfunc_4 (1 B): matches/0x0012f9f0.cpp
// sym: ?FUN_0012f9f0@fn_f587a2cf@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0012f9f0() {}

} // namespace fn_f587a2cf

// 0x0012fa00 hulkfight::StatBeginTrialAction::vfunc_3 (42 B): matches/0x0012fa00.cpp
// sym: ?vfunc_3@StatBeginTrialAction@hulkfight@@UAE_NHH@Z
bool hulkfight::StatBeginTrialAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    if (!(*(u32_12fa00 *)&this->f_20))
        return false;
    u32_12fa00 x = *(u32_12fa00*)((*(hulk_uintptr *)&this->f_1c) + 0x10);
    gGlobal_12fa00->run_00086370()->run_000906f0(x);
    return true;
}


// 0x0012fa30 hulkfight::StatBeginTrialAction::vfunc_5 (5 B): matches/0x0012fa30.cpp
// sym: ?vfunc_5@StatBeginTrialAction@hulkfight@@UAE_NHH@Z
// Same code shape as 0x0012da20 (propagated; names are from that function)
bool hulkfight::StatBeginTrialAction::vfunc_5(hulk_intptr a, int b) {
    return (bool)(1);
}

namespace fn_f587a2cf {

// 0x0012fa40 hulkfight::StatBeginTrialAction::vfunc_4 (1 B): matches/0x0012fa40.cpp
// sym: ?FUN_0012fa40@fn_f587a2cf@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0012fa40() {}

} // namespace fn_f587a2cf

// 0x0012fa50 hulkfight::StatEndTrialAction::vfunc_3 (42 B): matches/0x0012fa50.cpp
// sym: ?vfunc_3@StatEndTrialAction@hulkfight@@UAE_NHH@Z
// Same code shape as 0x0012fa00 (propagated; names are from that function)
bool hulkfight::StatEndTrialAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    if (!(*(u32_12fa50 *)&this->f_20))
        return false;
    u32_12fa50 x = *(u32_12fa50*)((*(hulk_uintptr *)&this->f_1c) + 0x10);
    gGlobal_12fa50->run_00086370()->run_00090df0(x);
    return true;
}


// 0x0012fa80 hulkfight::StatEndTrialAction::vfunc_5 (5 B): matches/0x0012fa80.cpp
// sym: ?vfunc_5@StatEndTrialAction@hulkfight@@UAE_NHH@Z
// Same code shape as 0x0012da20 (propagated; names are from that function)
bool hulkfight::StatEndTrialAction::vfunc_5(hulk_intptr a, int b) {
    return (bool)(1);
}


// 0x0012fa90 hulkfight::StatEndTrialAction::vfunc_4 (1 B): matches/0x0012fa90.cpp
// sym: ?vfunc_4@StatEndTrialAction@hulkfight@@UAEXXZ
void hulkfight::StatEndTrialAction::vfunc_4() {
    return;
}


// 0x0012faa0 hulkfight::XPAction::vfunc_3 (52 B): matches/0x0012faa0.cpp
// sym: ?vfunc_3@XPAction@hulkfight@@UAE_NHH@Z
bool hulkfight::XPAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (!(*(int *)&this->f_20))
        return (bool)(0);
    int n = (int)(__int64)((Datum*)(*(void * *)&this->f_1c))->value;
    gManager->Find_00086370()->Apply_00090720("xp", n);
    return (bool)(1);
}


// 0x0012fae0 hulkfight::XPAction::vfunc_5 (5 B): matches/0x0012fae0.cpp
// sym: ?vfunc_5@XPAction@hulkfight@@UAE_NHH@Z
// Same code shape as 0x0012da20 (propagated; names are from that function)
bool hulkfight::XPAction::vfunc_5(hulk_intptr a, int b) {
    return (bool)(1);
}

namespace fn_f587a2cf {

// 0x0012faf0 hulkfight::XPAction::vfunc_4 (1 B): matches/0x0012faf0.cpp
// sym: ?FUN_0012faf0@fn_f587a2cf@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0012faf0() {}

} // namespace fn_f587a2cf

// 0x0012fb00 hulkfight::DebugPrintCondition::vfunc_6 (5 B): matches/0x0012fb00.cpp
// sym: ?vfunc_6@DebugPrintCondition@hulkfight@@UAE_NPAX00@Z
bool hulkfight::DebugPrintCondition::vfunc_6(void* __p0, void* __p1, void* __p2) {
    return true;
}


// 0x0012fb10 hulkfight::DebugPrintAction::vfunc_3 (5 B): matches/0x0012fb10.cpp
// sym: ?vfunc_3@DebugPrintAction@hulkfight@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool hulkfight::DebugPrintAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    return false;
}


// 0x0012fbe0 hulkfight::MissionProgressCondition::vfunc_5 (59 B): matches/0x0012fbe0.cpp [wrapped: conflict: MissionProgressCondition]
// sym: ?vfunc_5@MissionProgressCondition@fn_0012fbe0@@UAEPAV12@E@Z
void __cdecl operator delete(void* p);
namespace fn_0012fbe0 {
extern "C++" __declspec(nothrow) void __cdecl thunk_FUN_00267090(void* p);

extern int g_vftable_12fbe0;

class MissionProgressCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual MissionProgressCondition* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void baseDtor_002345b0();
    char pad4[8];
    void* m0c;
    char pad10[4];
    void* m14;
};

MissionProgressCondition* MissionProgressCondition::vfunc_5(unsigned char flag) {
    *(void**)this = &g_vftable_12fbe0;
    thunk_FUN_00267090(m0c);
    thunk_FUN_00267090(m14);
    baseDtor_002345b0();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}
} // namespace fn_0012fbe0

namespace fn_f587a2cf {

// 0x0012fc20 hulkfight::UnlockableCondition::vfunc_5 (36 B): matches/0x0012fc20.cpp
// sym: ?vfunc_5@UnlockableCondition_12fc20@fn_f587a2cf@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
UnlockableCondition_12fc20* UnlockableCondition_12fc20::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00411244;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0012fc50 hulkfight::GameStateCondition::vfunc_5 (59 B): matches/0x0012fc50.cpp
// sym: ?vfunc_5@GameStateCondition_12fc50@fn_f587a2cf@@UAEPAV12@E@Z
// Same code shape as 0x0012fbe0 (propagated; names are from that function)
GameStateCondition_12fc50* GameStateCondition_12fc50::vfunc_5(unsigned char flag) {
    *(void**)this = &hulk_at_00411264;
    thunk_FUN_00267090(m0c);
    thunk_FUN_00267090(m14);
    baseDtor_002345b0();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}

} // namespace fn_f587a2cf

// 0x0012fc90 hulkfight::DebugPrintCondition::vfunc_5 (59 B): matches/0x0012fc90.cpp [wrapped: conflict: DebugPrintCondition]
// sym: ?v5@DebugPrintCondition@fn_0012fc90@@UAEPAXE@Z
namespace fn_0012fc90 {
extern "C" {
extern "C++" { __declspec(nothrow) void __cdecl thunk_FUN_00267090(void*); }
extern "C++" { __declspec(nothrow) void __cdecl thunk_FUN_00267090b_0008d340(void*); }
extern "C++" { __declspec(nothrow) void __cdecl thunk_FUN_00267090c_0008d330(void*); }
extern "C++" { extern char g_vftable_target; }
}

struct GameStateCondition_12fc90 {
  public:
    void Dtor_002345b0();
};

class DebugPrintCondition {
  public:
    virtual ~DebugPrintCondition();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5(unsigned char flag);
    virtual void v6();
    char pad[8];
    void* m_p1;
    void* m_p2;
};

void* DebugPrintCondition::v5(unsigned char flag) {
    *(char**)this = &g_vftable_target;
    thunk_FUN_00267090(m_p1);
    thunk_FUN_00267090b_0008d340(m_p2);
    ((GameStateCondition_12fc90*)this)->Dtor_002345b0();
    if (flag & 1) {
        thunk_FUN_00267090c_0008d330(this);
    }
    return this;
}
} // namespace fn_0012fc90

namespace fn_f587a2cf {

// 0x0012fcd0 hulkfight::LocationCondition::vfunc_5 (59 B): matches/0x0012fcd0.cpp
// sym: ?vfunc_5@LocationCondition@fn_f587a2cf@@QAEPAV12@H@Z
LocationCondition* LocationCondition::vfunc_5(int b) {
    void* p1 = m1;
    *(const void**)this = &loc_vftable;
    FUN_0008d340(p1);
    FUN_0008d340(m2);
    Cleanup_002345b0();
    if (b & 1) {
        operator delete(this);
    }
    return this;
}


// 0x0012fd10 hulkfight::ChapterMissionCondition::vfunc_5 (36 B): matches/0x0012fd10.cpp
// sym: ?vfunc_5@ChapterMissionCondition_12fd10@fn_f587a2cf@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ChapterMissionCondition_12fd10* ChapterMissionCondition_12fd10::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004112c4;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0012fd40 hulkfight::StatBeginTrialTrack::vfunc_5 (50 B): matches/0x0012fd40.cpp
// sym: ?f5@StatBeginTrialTrack_12fd40@fn_f587a2cf@@QAEPAV12@E@Z
StatBeginTrialTrack_12fd40* StatBeginTrialTrack_12fd40::f5(unsigned char flags) {
    void* p = m10;
    vptr = hulk_at_004112e4;
    operator delete[](p);
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f587a2cf

// 0x0012fd80 hulkfight::NISSoundTrack::vfunc_5 (68 B): matches/0x0012fd80.cpp [wrapped: conflict: NISSoundTrack]
// sym: ?vfunc_5_impl@NISSoundTrack@fn_0012fd80@@QAEPAV12@E@Z
namespace fn_0012fd80 {
extern "C" char DAT_00411314[];
extern "C++" __declspec(nothrow) void __cdecl free_a_0008d340(void*);
extern "C++" __declspec(nothrow) void __cdecl free_b_0008d330(void*);

class NISSoundTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual NISSoundTrack* vfunc_5(unsigned char param);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();

    void FUN_00236d60(); // thiscall member, matches mov ecx,esi; call

    NISSoundTrack* vfunc_5_impl(unsigned char param);

    char pad0[0xC]; // offsets 4..0xF
    void* m10;      // 0x10
    void* m14;      // 0x14
    void* m18;      // 0x18
};

NISSoundTrack* NISSoundTrack::vfunc_5_impl(unsigned char param) {
    *(void**)this = (void*)((hulk_intptr)DAT_00411314);
    free_a_0008d340(m10);
    free_a_0008d340(m14);
    free_a_0008d340(m18);
    FUN_00236d60();
    if (param & 1) {
        free_b_0008d330(this);
    }
    return this;
}
} // namespace fn_0012fd80

namespace fn_f587a2cf {

// 0x0012fdd0 hulkfight::DialogueTrack::vfunc_5 (77 B): matches/0x0012fdd0.cpp
// sym: ?vfunc_5@DialogueTrack_12fdd0@fn_f587a2cf@@QAEPAV12@H@Z
DialogueTrack_12fdd0* DialogueTrack_12fdd0::vfunc_5(int param) {
    vptr = (void*)DAT_00411344;
    FUN_0008d340(m10);
    FUN_0008d340(m14);
    FUN_0008d340(m1c);
    FUN_0008d340(m20);
    FUN_00236d60();
    if (param & 1) {
        operator delete(this);
    }
    return this;
}

} // namespace fn_f587a2cf

// 0x0012fe20 hulkfight::DebugPrintTrack::vfunc_5 (59 B): matches/0x0012fe20.cpp [wrapped: conflict: DebugPrintTrack]
// sym: ?vfunc_5@DebugPrintTrack@fn_0012fe20@@QAEPAV12@E@Z
namespace fn_0012fe20 {
extern "C++" __declspec(nothrow) void __cdecl thunk_FUN_00267090(void* p);

extern int hulk_at_00411374;

class DebugPrintTrack {
  public:
    virtual ~DebugPrintTrack();
    char pad1[0x10];
    void* m14;
    void* m18;
    void MemberFunc_00236d60();
    DebugPrintTrack* vfunc_5(unsigned char flags);
};

DebugPrintTrack* DebugPrintTrack::vfunc_5(unsigned char flags) {
    void* p14 = m14;
    *(void**)this = &hulk_at_00411374;
    thunk_FUN_00267090(p14);
    thunk_FUN_00267090(m18);
    MemberFunc_00236d60();
    if (flags & 1) {
        operator delete(this);
    }
    return this;
}
} // namespace fn_0012fe20

namespace fn_f587a2cf {

// 0x0012fe60 hulkfight::StatEndTrialTrack::vfunc_5 (50 B): matches/0x0012fe60.cpp
// sym: ?vfunc_5@StatEndTrialTrack@fn_f587a2cf@@UAEPAV12@H@Z
StatEndTrialTrack* StatEndTrialTrack::vfunc_5(int flag) {
    void* x = m10;
    *(void**)this = &hulk_at_004113a4;
    thunk_FUN_00267090(x);
    Cleanup_00236d60();
    if (flag & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f587a2cf

// 0x0012fea0 hulkfight::StatTrack::vfunc_5 (50 B): matches/0x0012fea0.cpp [wrapped: conflict: StatTrack]
// sym: ??_GStatTrack@fn_0012fea0@@UAEPAXI@Z
namespace fn_0012fea0 {
class StatTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~StatTrack();
    virtual void v6();
    int pad04[3];
    int m10;
    void trackCall_00236d60();
};
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
StatTrack::~StatTrack() {
    thunk_FUN_00267090(m10);
    trackCall_00236d60();
}
} // namespace fn_0012fea0

namespace fn_f587a2cf {

// 0x0012fee0 hulkfight::XPTrack::vfunc_5 (36 B): matches/0x0012fee0.cpp
// sym: ?vfunc_5@XPTrack_12fee0@fn_f587a2cf@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
XPTrack_12fee0* XPTrack_12fee0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00411404;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0012ff10 FUN_0012ff10 (72 B): matches/0x0012ff10.cpp
// sym: ??0FaceTargetAction@fn_f587a2cf@@QAE@HPAVRefObj_12ff10@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
FaceTargetAction::FaceTargetAction(int target, RefObj_12ff10* obj) {
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


// 0x0012ff60 FUN_0012ff60 (50 B): matches/0x0012ff60.cpp
// sym: ??1Action@fn_f587a2cf@@QAE@XZ
Action::~Action() {
    vptr = hulk_at_0041146c;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Base_12ff60 *)this)->FUN_002326a0();
}


// 0x0012ffa0 FUN_0012ffa0 (72 B): matches/0x0012ffa0.cpp
// sym: ??0NISSoundAction_12ffa0@fn_f587a2cf@@QAE@HPAVRefObj_12ffa0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
NISSoundAction_12ffa0::NISSoundAction_12ffa0(int target, RefObj_12ffa0* obj) {
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


// 0x0012fff0 FUN_0012fff0 (50 B): matches/0x0012fff0.cpp
// sym: ??1NISSoundAction_12fff0@fn_f587a2cf@@QAE@XZ
NISSoundAction_12fff0::~NISSoundAction_12fff0() {
    vptr = hulk_at_00411488;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_12fff0 *)this)->FUN_002326a0();
}


// 0x00130030 FUN_00130030 (72 B): matches/0x00130030.cpp
// sym: ??0StatAction_130030@fn_f587a2cf@@QAE@HPAVRefObj_130030@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
StatAction_130030::StatAction_130030(int target, RefObj_130030* obj) {
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


// 0x00130080 FUN_00130080 (50 B): matches/0x00130080.cpp
// sym: ?f@StatAction_130080@fn_f587a2cf@@QAEXXZ
void StatAction_130080::f() {
    vptr = hulk_at_004114a4;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_130080 *)this)->FUN_002326a0();
}


// 0x001300c0 FUN_001300c0 (72 B): matches/0x001300c0.cpp
// sym: ??0StatBeginTrialAction_1300c0@fn_f587a2cf@@QAE@HPAVRefObj_1300c0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
StatBeginTrialAction_1300c0::StatBeginTrialAction_1300c0(int target, RefObj_1300c0* obj) {
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


// 0x00130110 FUN_00130110 (50 B): matches/0x00130110.cpp
// sym: ??1StatBeginTrialAction_130110@fn_f587a2cf@@QAE@XZ
StatBeginTrialAction_130110::~StatBeginTrialAction_130110() {
    vptr = hulk_at_004114c0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_130110 *)this)->FUN_002326a0();
}


// 0x00130150 FUN_00130150 (72 B): matches/0x00130150.cpp
// sym: ??0StatEndTrialAction_130150@fn_f587a2cf@@QAE@HPAVRefObj_130150@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
StatEndTrialAction_130150::StatEndTrialAction_130150(int target, RefObj_130150* obj) {
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


// 0x001301a0 FUN_001301a0 (50 B): matches/0x001301a0.cpp
// sym: ??1StatEndTrialAction_1301a0@fn_f587a2cf@@QAE@XZ
StatEndTrialAction_1301a0::~StatEndTrialAction_1301a0() throw() {
    vptr = hulk_at_004114dc;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
}


// 0x001301e0 FUN_001301e0 (72 B): matches/0x001301e0.cpp
// sym: ??0XPAction_1301e0@fn_f587a2cf@@QAE@HPAVRefObj_1301e0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
XPAction_1301e0::XPAction_1301e0(int target, RefObj_1301e0* obj) {
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


// 0x00130230 FUN_00130230 (50 B): matches/0x00130230.cpp
// sym: ??1XPAction_130230@fn_f587a2cf@@QAE@XZ
XPAction_130230::~XPAction_130230() {
    vptr = hulk_at_004114f8;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_130230 *)this)->FUN_002326a0();
}


// 0x00130270 FUN_00130270 (65 B): matches/0x00130270.cpp
// sym: ?Build@PostEvent_StringAction@fn_f587a2cf@@QAEPAU12@HPAUObj_130270@2@@Z
// Same code shape as 0x0012db50 (propagated; names are from that function)
PostEvent_StringAction* PostEvent_StringAction::Build(int a, Obj_130270* p) {
    Init_00232660();
    vf = &hulk_at_00411514;
    object = 0;
    arg = a;
    if (p)
        p->F();
    if (object)
        object->R();
    object = p;
    return this;
}


// 0x001302c0 FUN_001302c0 (36 B): matches/0x001302c0.cpp
// sym: ??1DebugPrintAction_1302c0@fn_f587a2cf@@QAE@XZ
DebugPrintAction_1302c0::~DebugPrintAction_1302c0() {
    vptr = g_vftable_1302c0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    ((fight::Action *)(Action_1302c0 *)this)->FUN_002326a0();
}

} // namespace fn_f587a2cf

// 0x00130310 fight::ParamString<hulkfight::MissionProgressCondition>::vfunc_6 (26 B): matches/0x00130310.cpp
// sym: ?vfunc_6@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::MissionProgressCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::MissionProgressCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::MissionProgressCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::MissionProgressCondition>::**)(int))&this->f_10))(b);
}


// 0x00130330 fight::ParamString<hulkfight::MissionProgressCondition>::vfunc_2 (11 B): matches/0x00130330.cpp
// sym: ?vfunc_2@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::MissionProgressCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130370 fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::vfunc_7 (6 B): matches/0x00130370.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00130380 fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::vfunc_6 (30 B): matches/0x00130380.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_130380 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_130380*)&DAT_003f335c));
}


// 0x001303a0 fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::vfunc_8 (26 B): matches/0x001303a0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::MissionProgressCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::**)(int))&this->f_18))(b);
}


// 0x001303c0 fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::vfunc_2 (11 B): matches/0x001303c0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00130400 fight::ParamEnumConstList<hulkfight::UnlockableCondition>::vfunc_7 (6 B): matches/0x00130400.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::UnlockableCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00130410 fight::ParamEnumConstList<hulkfight::UnlockableCondition>::vfunc_6 (30 B): matches/0x00130410.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::UnlockableCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_130410 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_130410*)&DAT_003f335c));
}


// 0x00130430 fight::ParamEnumConstList<hulkfight::UnlockableCondition>::vfunc_8 (26 B): matches/0x00130430.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::UnlockableCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::UnlockableCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::UnlockableCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::UnlockableCondition>::**)(int))&this->f_18))(b);
}


// 0x00130450 fight::ParamEnumConstList<hulkfight::UnlockableCondition>::vfunc_2 (11 B): matches/0x00130450.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::UnlockableCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00130480 fight::ParamBool<hulkfight::UnlockableCondition>::vfunc_6 (26 B): matches/0x00130480.cpp
// sym: ?vfunc_6@?$ParamBool@VUnlockableCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::UnlockableCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::UnlockableCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::UnlockableCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::UnlockableCondition>::**)(int))&this->f_10))(b);
}


// 0x001304a0 fight::ParamBool<hulkfight::UnlockableCondition>::vfunc_2 (11 B): matches/0x001304a0.cpp
// sym: ?vfunc_2@?$ParamBool@VUnlockableCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::UnlockableCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001304d0 fight::ParamString<hulkfight::GameStateCondition>::vfunc_6 (26 B): matches/0x001304d0.cpp
// sym: ?vfunc_6@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::GameStateCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::GameStateCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::GameStateCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::GameStateCondition>::**)(int))&this->f_10))(b);
}


// 0x001304f0 fight::ParamString<hulkfight::GameStateCondition>::vfunc_2 (11 B): matches/0x001304f0.cpp
// sym: ?vfunc_2@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::GameStateCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130530 fight::ParamEnumConstList<hulkfight::GameStateCondition>::vfunc_7 (6 B): matches/0x00130530.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::GameStateCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00130540 fight::ParamEnumConstList<hulkfight::GameStateCondition>::vfunc_6 (30 B): matches/0x00130540.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::GameStateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_130540 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_130540*)&DAT_003f335c));
}


// 0x00130560 fight::ParamEnumConstList<hulkfight::GameStateCondition>::vfunc_8 (26 B): matches/0x00130560.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::GameStateCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::GameStateCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::GameStateCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::GameStateCondition>::**)(int))&this->f_18))(b);
}


// 0x00130580 fight::ParamEnumConstList<hulkfight::GameStateCondition>::vfunc_2 (11 B): matches/0x00130580.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::GameStateCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001305b0 fight::ParamString<hulkfight::DebugPrintCondition>::vfunc_6 (26 B): matches/0x001305b0.cpp
// sym: ?vfunc_6@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::DebugPrintCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::DebugPrintCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::DebugPrintCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::DebugPrintCondition>::**)(int))&this->f_10))(b);
}


// 0x001305d0 fight::ParamString<hulkfight::DebugPrintCondition>::vfunc_2 (11 B): matches/0x001305d0.cpp
// sym: ?vfunc_2@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::DebugPrintCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130610 fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_7 (6 B): matches/0x00130610.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00130620 fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_6 (30 B): matches/0x00130620.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_130620 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_130620*)&DAT_003f335c));
}


// 0x00130640 fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_8 (26 B): matches/0x00130640.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::LocationCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::LocationCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::LocationCondition>::**)(int))&this->f_18))(b);
}


// 0x00130660 fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_2 (11 B): matches/0x00130660.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00130690 fight::ParamStringConstList<hulkfight::LocationCondition>::vfunc_6 (26 B): matches/0x00130690.cpp
// sym: ?vfunc_6@?$ParamStringConstList@VLocationCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamStringConstList<hulkfight::LocationCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamStringConstList<hulkfight::LocationCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamStringConstList<hulkfight::LocationCondition>*)a)->*(*(bool (fight::ParamStringConstList<hulkfight::LocationCondition>::**)(int))&this->f_10))(b);
}


// 0x001306b0 fight::ParamStringConstList<hulkfight::LocationCondition>::vfunc_2 (11 B): matches/0x001306b0.cpp
// sym: ?vfunc_2@?$ParamStringConstList@VLocationCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamStringConstList<hulkfight::LocationCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001306f0 fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::vfunc_7 (6 B): matches/0x001306f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00130700 fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::vfunc_6 (30 B): matches/0x00130700.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_130700 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_130700*)&DAT_003f335c));
}


// 0x00130720 fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::vfunc_8 (26 B): matches/0x00130720.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::**)(int))&this->f_18))(b);
}


// 0x00130740 fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::vfunc_2 (11 B): matches/0x00130740.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00130770 fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>::vfunc_6 (26 B): matches/0x00130770.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VChapterMissionCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>::**)(int))&this->f_10))(b);
}


// 0x00130790 fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>::vfunc_2 (11 B): matches/0x00130790.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VChapterMissionCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001307c0 fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>::vfunc_6 (26 B): matches/0x001307c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>::**)(int))&this->f_10))(b);
}


// 0x001307e0 fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>::vfunc_2 (11 B): matches/0x001307e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130810 fight::ParamString<hulkfight::StatBeginTrialTrack>::vfunc_6 (26 B): matches/0x00130810.cpp
// sym: ?vfunc_6@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::StatBeginTrialTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::StatBeginTrialTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::StatBeginTrialTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::StatBeginTrialTrack>::**)(int))&this->f_10))(b);
}


// 0x00130830 fight::ParamString<hulkfight::StatBeginTrialTrack>::vfunc_2 (11 B): matches/0x00130830.cpp
// sym: ?vfunc_2@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::StatBeginTrialTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130860 fight::ParamFloatConstRange<hulkfight::NISSoundTrack>::vfunc_6 (26 B): matches/0x00130860.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::NISSoundTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::NISSoundTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::NISSoundTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::NISSoundTrack>::**)(int))&this->f_10))(b);
}


// 0x00130880 fight::ParamFloatConstRange<hulkfight::NISSoundTrack>::vfunc_2 (11 B): matches/0x00130880.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::NISSoundTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001308b0 fight::ParamString<hulkfight::NISSoundTrack>::vfunc_6 (26 B): matches/0x001308b0.cpp
// sym: ?vfunc_6@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::NISSoundTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::NISSoundTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::NISSoundTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::NISSoundTrack>::**)(int))&this->f_10))(b);
}


// 0x001308d0 fight::ParamString<hulkfight::NISSoundTrack>::vfunc_2 (11 B): matches/0x001308d0.cpp
// sym: ?vfunc_2@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::NISSoundTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130900 fight::ParamFloatConstRange<hulkfight::DialogueTrack>::vfunc_6 (26 B): matches/0x00130900.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::DialogueTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::DialogueTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::DialogueTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::DialogueTrack>::**)(int))&this->f_10))(b);
}


// 0x00130920 fight::ParamFloatConstRange<hulkfight::DialogueTrack>::vfunc_2 (11 B): matches/0x00130920.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::DialogueTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130950 fight::ParamString<hulkfight::DialogueTrack>::vfunc_6 (26 B): matches/0x00130950.cpp
// sym: ?vfunc_6@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::DialogueTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::DialogueTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::DialogueTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::DialogueTrack>::**)(int))&this->f_10))(b);
}


// 0x00130970 fight::ParamString<hulkfight::DialogueTrack>::vfunc_2 (11 B): matches/0x00130970.cpp
// sym: ?vfunc_2@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::DialogueTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001309a0 fight::ParamIntConstRange<hulkfight::DialogueTrack>::vfunc_6 (26 B): matches/0x001309a0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VChapterMissionCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::DialogueTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::DialogueTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::DialogueTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::DialogueTrack>::**)(int))&this->f_10))(b);
}


// 0x001309c0 fight::ParamIntConstRange<hulkfight::DialogueTrack>::vfunc_2 (11 B): matches/0x001309c0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VChapterMissionCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::DialogueTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001309f0 fight::ParamBool<hulkfight::DialogueTrack>::vfunc_6 (26 B): matches/0x001309f0.cpp
// sym: ?vfunc_6@?$ParamBool@VUnlockableCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::DialogueTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::DialogueTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::DialogueTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::DialogueTrack>::**)(int))&this->f_10))(b);
}


// 0x00130a10 fight::ParamBool<hulkfight::DialogueTrack>::vfunc_2 (11 B): matches/0x00130a10.cpp
// sym: ?vfunc_2@?$ParamBool@VUnlockableCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::DialogueTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130a40 fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>::vfunc_6 (26 B): matches/0x00130a40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>::**)(int))&this->f_10))(b);
}


// 0x00130a60 fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>::vfunc_2 (11 B): matches/0x00130a60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130a90 fight::ParamString<hulkfight::DebugPrintTrack>::vfunc_6 (26 B): matches/0x00130a90.cpp
// sym: ?vfunc_6@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::DebugPrintTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::DebugPrintTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::DebugPrintTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::DebugPrintTrack>::**)(int))&this->f_10))(b);
}


// 0x00130ab0 fight::ParamString<hulkfight::DebugPrintTrack>::vfunc_2 (11 B): matches/0x00130ab0.cpp
// sym: ?vfunc_2@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::DebugPrintTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130ae0 fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>::vfunc_6 (26 B): matches/0x00130ae0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>::**)(int))&this->f_10))(b);
}


// 0x00130b00 fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>::vfunc_2 (11 B): matches/0x00130b00.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130b30 fight::ParamString<hulkfight::StatEndTrialTrack>::vfunc_6 (26 B): matches/0x00130b30.cpp
// sym: ?vfunc_6@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::StatEndTrialTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::StatEndTrialTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::StatEndTrialTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::StatEndTrialTrack>::**)(int))&this->f_10))(b);
}


// 0x00130b50 fight::ParamString<hulkfight::StatEndTrialTrack>::vfunc_2 (11 B): matches/0x00130b50.cpp
// sym: ?vfunc_2@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::StatEndTrialTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130b80 fight::ParamFloatConstRange<hulkfight::StatTrack>::vfunc_6 (26 B): matches/0x00130b80.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::StatTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::StatTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::StatTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::StatTrack>::**)(int))&this->f_10))(b);
}


// 0x00130ba0 fight::ParamFloatConstRange<hulkfight::StatTrack>::vfunc_2 (11 B): matches/0x00130ba0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::StatTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130bd0 fight::ParamString<hulkfight::StatTrack>::vfunc_6 (26 B): matches/0x00130bd0.cpp
// sym: ?vfunc_6@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::StatTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::StatTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::StatTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::StatTrack>::**)(int))&this->f_10))(b);
}


// 0x00130bf0 fight::ParamString<hulkfight::StatTrack>::vfunc_2 (11 B): matches/0x00130bf0.cpp
// sym: ?vfunc_2@?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::StatTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130c20 fight::ParamFloatConstRange<hulkfight::XPTrack>::vfunc_6 (26 B): matches/0x00130c20.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::XPTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::XPTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::XPTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::XPTrack>::**)(int))&this->f_10))(b);
}


// 0x00130c40 fight::ParamFloatConstRange<hulkfight::XPTrack>::vfunc_2 (11 B): matches/0x00130c40.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::XPTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00130c60 fight::ConditionFactoryCasterTemplate<hulkfight::MissionProgressCondition>::vfunc_0 (36 B): matches/0x00130c60.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VMissionProgressCondition@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::MissionProgressCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return helper(s, 0, &DAT_00491ca8, &DAT_004aa710, 0) != 0;
}


// 0x00130c90 fight::ParamString<hulkfight::MissionProgressCondition>::vfunc_0 (30 B): matches/0x00130c90.cpp
// sym: ??_G?$ParamString@VMissionProgressCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::MissionProgressCondition>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::MissionProgressCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130c90)
#endif


// 0x00130cb0 fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::vfunc_0 (30 B): matches/0x00130cb0.cpp
// sym: ??_G?$ParamEnumConstList@VMissionProgressCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::MissionProgressCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::MissionProgressCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130cb0)
#endif


// 0x00130ce0 fight::ConditionFactoryCasterTemplate<hulkfight::UnlockableCondition>::vfunc_0 (36 B): matches/0x00130ce0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VUnlockableCondition@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::UnlockableCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004aa7c0, 0) != 0;
}


// 0x00130d10 fight::ParamEnumConstList<hulkfight::UnlockableCondition>::vfunc_0 (30 B): matches/0x00130d10.cpp
// sym: ??_G?$ParamEnumConstList@VUnlockableCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::UnlockableCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::UnlockableCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130d10)
#endif


// 0x00130d30 fight::ParamBool<hulkfight::UnlockableCondition>::vfunc_0 (30 B): matches/0x00130d30.cpp
// sym: ??_G?$ParamBool@VUnlockableCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::UnlockableCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::UnlockableCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130d30)
#endif


// 0x00130d60 fight::ConditionFactoryCasterTemplate<hulkfight::GameStateCondition>::vfunc_0 (36 B): matches/0x00130d60.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VGameStateCondition@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::GameStateCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &hulk_at_00491ca8, &hulk_at_004aa868, 0) != 0;
}


// 0x00130d90 fight::ParamString<hulkfight::GameStateCondition>::vfunc_0 (30 B): matches/0x00130d90.cpp
// sym: ??_G?$ParamString@VGameStateCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::GameStateCondition>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::GameStateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130d90)
#endif


// 0x00130db0 fight::ParamEnumConstList<hulkfight::GameStateCondition>::vfunc_0 (30 B): matches/0x00130db0.cpp
// sym: ??_G?$ParamEnumConstList@VGameStateCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::GameStateCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::GameStateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130db0)
#endif


// 0x00130de0 fight::ConditionFactoryCasterTemplate<hulkfight::DebugPrintCondition>::vfunc_0 (36 B): matches/0x00130de0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VDebugPrintCondition@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::DebugPrintCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &hulk_at_004aa910, 0) != 0;
}


// 0x00130e10 fight::ParamString<hulkfight::DebugPrintCondition>::vfunc_0 (30 B): matches/0x00130e10.cpp
// sym: ??_G?$ParamString@VDebugPrintCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::DebugPrintCondition>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::DebugPrintCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130e10)
#endif


// 0x00130e40 fight::ConditionFactoryCasterTemplate<hulkfight::LocationCondition>::vfunc_0 (36 B): matches/0x00130e40.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VLocationCondition@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::LocationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_00491ca8, &DAT_004aa9b8, 0) != 0;
}


// 0x00130e70 fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_0 (30 B): matches/0x00130e70.cpp
// sym: ??_G?$ParamEnumConstList@VLocationCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::LocationCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::LocationCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130e70)
#endif


// 0x00130e90 fight::ParamStringConstList<hulkfight::LocationCondition>::vfunc_0 (30 B): matches/0x00130e90.cpp
// sym: ??_G?$ParamStringConstList@VLocationCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamStringConstList<hulkfight::LocationCondition>::~ParamStringConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamStringConstList<hulkfight::LocationCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130e90)
#endif


// 0x00130eb0 FUN_00130eb0 (9 B): matches/0x00130eb0.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate; hulkfight::ChapterMissionCondition]
// sym: ??0?$ConditionFactoryCasterTemplate@VChapterMissionCondition@hulkfight@fn_00130eb0@@@fight@fn_00130eb0@@QAE@XZ
namespace fn_00130eb0 {
namespace hulkfight {
class ChapterMissionCondition {};
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryCasterTemplate {
  public:
    ConditionFactoryCasterTemplate();
    virtual void dummy();
};
template <>
ConditionFactoryCasterTemplate<hulkfight::ChapterMissionCondition>::ConditionFactoryCasterTemplate() {}
} // namespace fight
} // namespace fn_00130eb0


// 0x00130ec0 fight::ConditionFactoryCasterTemplate<hulkfight::ChapterMissionCondition>::vfunc_0 (36 B): matches/0x00130ec0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VChapterMissionCondition@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ChapterMissionCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004aaa68, 0) != 0;
}


// 0x00130ef0 fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::vfunc_0 (30 B): matches/0x00130ef0.cpp
// sym: ??_G?$ParamEnumConstList@VChapterMissionCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ChapterMissionCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130ef0)
#endif


// 0x00130f10 fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>::vfunc_0 (30 B): matches/0x00130f10.cpp
// sym: ??_G?$ParamIntConstRange@VChapterMissionCondition@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::ChapterMissionCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130f10)
#endif


// 0x00130f40 fight::TrackFactoryCasterTemplate<hulkfight::StatBeginTrialTrack>::vfunc_0 (36 B): matches/0x00130f40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VStatBeginTrialTrack@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::StatBeginTrialTrack>::vfunc_0(void* __p0) { const char * name = (const char *)__p0;

    return FUN_00344e74(name, 0, &DAT_0049850c, &DAT_004aab18, 0) != 0;
}


// 0x00130f70 fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>::vfunc_0 (30 B): matches/0x00130f70.cpp
// sym: ??_G?$ParamFloatConstRange@VStatBeginTrialTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::StatBeginTrialTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130f70)
#endif


// 0x00130f90 fight::ParamString<hulkfight::StatBeginTrialTrack>::vfunc_0 (30 B): matches/0x00130f90.cpp
// sym: ??_G?$ParamString@VStatBeginTrialTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::StatBeginTrialTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::StatBeginTrialTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130f90)
#endif


// 0x00130fc0 fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack>::vfunc_0 (36 B): matches/0x00130fc0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VNISSoundTrack@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return cast(p, 0, &hulk_at_0049850c, &hulk_at_004aabb8, 0) != 0;
}


// 0x00130ff0 fight::ParamFloatConstRange<hulkfight::NISSoundTrack>::vfunc_0 (30 B): matches/0x00130ff0.cpp
// sym: ??_G?$ParamFloatConstRange@VNISSoundTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::NISSoundTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::NISSoundTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x130ff0)
#endif


// 0x00131010 fight::ParamString<hulkfight::NISSoundTrack>::vfunc_0 (30 B): matches/0x00131010.cpp
// sym: ??_G?$ParamString@VNISSoundTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::NISSoundTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::NISSoundTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x131010)
#endif


// 0x00131040 fight::TrackFactoryCasterTemplate<hulkfight::DialogueTrack>::vfunc_0 (36 B): matches/0x00131040.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VDialogueTrack@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::DialogueTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_004aac50, 0) != 0;
}


// 0x00131070 fight::ParamFloatConstRange<hulkfight::DialogueTrack>::vfunc_0 (30 B): matches/0x00131070.cpp
// sym: ??_G?$ParamFloatConstRange@VDialogueTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::DialogueTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::DialogueTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x131070)
#endif


// 0x00131090 fight::ParamString<hulkfight::DialogueTrack>::vfunc_0 (30 B): matches/0x00131090.cpp
// sym: ??_G?$ParamString@VDialogueTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::DialogueTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::DialogueTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x131090)
#endif


// 0x001310b0 fight::ParamIntConstRange<hulkfight::DialogueTrack>::vfunc_0 (30 B): matches/0x001310b0.cpp
// sym: ??_G?$ParamIntConstRange@VDialogueTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::DialogueTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::DialogueTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1310b0)
#endif


// 0x001310d0 fight::ParamBool<hulkfight::DialogueTrack>::vfunc_0 (30 B): matches/0x001310d0.cpp
// sym: ??_G?$ParamBool@VDialogueTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::DialogueTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::DialogueTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1310d0)
#endif


// 0x00131100 fight::TrackFactoryCasterTemplate<hulkfight::DebugPrintTrack>::vfunc_0 (36 B): matches/0x00131100.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VDebugPrintTrack@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::DebugPrintTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004aace8, 0) != 0;
}


// 0x00131130 fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>::vfunc_0 (30 B): matches/0x00131130.cpp
// sym: ??_G?$ParamFloatConstRange@VDebugPrintTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::DebugPrintTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x131130)
#endif


// 0x00131150 fight::ParamString<hulkfight::DebugPrintTrack>::vfunc_0 (30 B): matches/0x00131150.cpp
// sym: ??_G?$ParamString@VDebugPrintTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::DebugPrintTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::DebugPrintTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x131150)
#endif


// 0x00131180 fight::TrackFactoryCasterTemplate<hulkfight::StatEndTrialTrack>::vfunc_0 (36 B): matches/0x00131180.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VStatEndTrialTrack@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::StatEndTrialTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004aad80, 0) != 0;
}


// 0x001311b0 fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>::vfunc_0 (30 B): matches/0x001311b0.cpp
// sym: ??_G?$ParamFloatConstRange@VStatEndTrialTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::StatEndTrialTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1311b0)
#endif


// 0x001311d0 fight::ParamString<hulkfight::StatEndTrialTrack>::vfunc_0 (30 B): matches/0x001311d0.cpp
// sym: ??_G?$ParamString@VStatEndTrialTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::StatEndTrialTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::StatEndTrialTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1311d0)
#endif


// 0x00131200 fight::TrackFactoryCasterTemplate<hulkfight::StatTrack>::vfunc_0 (36 B): matches/0x00131200.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VStatTrack@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::StatTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004aae18, 0) != 0;
}


// 0x00131230 fight::ParamFloatConstRange<hulkfight::StatTrack>::vfunc_0 (30 B): matches/0x00131230.cpp
// sym: ??_G?$ParamFloatConstRange@VStatTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::StatTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::StatTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x131230)
#endif


// 0x00131250 fight::ParamString<hulkfight::StatTrack>::vfunc_0 (30 B): matches/0x00131250.cpp
// sym: ??_G?$ParamString@VStatTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::StatTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::StatTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x131250)
#endif


// 0x00131280 fight::TrackFactoryCasterTemplate<hulkfight::XPTrack>::vfunc_0 (36 B): matches/0x00131280.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VXPTrack@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::XPTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004aaea8, 0) != 0;
}


// 0x001312b0 fight::ParamFloatConstRange<hulkfight::XPTrack>::vfunc_0 (30 B): matches/0x001312b0.cpp
// sym: ??_G?$ParamFloatConstRange@VXPTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::XPTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::XPTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1312b0)
#endif


// 0x001312d0 FUN_001312d0 (231 B): matches/0x001312d0.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamString]
// sym: ?target@fn_001312d0@@YAXXZ
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
namespace fn_001312d0 {

void* __cdecl FUN_0008d690(unsigned int);

void FUN_0012dfe0();
void FUN_0012e2c0();
void FUN_0012e320();
struct FUN_002349e0 {
    virtual void slot0();
    char pad[12];
    void (*callback)();
    int tail;
    FUN_002349e0(const char*);
};
struct FUN_00234cc0 {
    virtual void slot0();
    char pad[12];
    int* list;
    int count;
    void (*callback)();
    int tail;
    FUN_00234cc0(const char*);
};
namespace hulkfight {
class MissionProgressCondition;
}
namespace fight {
template <class T> struct ParamString : FUN_002349e0 {
    virtual void slot0();
    ParamString(const char* s, void (*f)()) : FUN_002349e0(s) { callback = f; }
};
template <class T> struct ParamEnumConstList : FUN_00234cc0 {
    virtual void slot0();
    ParamEnumConstList(const char* s, int n) : FUN_00234cc0(s) {
        count = n;
        list = ((int*)&DAT_00427758);
        callback = FUN_0012dfe0;
    }
};
} // namespace fight
void __cdecl FUN_002347b0(int*, void**, int);
void target() {
    if (!DAT_004e0e50) {
        void* params[3];
        typedef fight::ParamString<hulkfight::MissionProgressCondition> S;
        typedef fight::ParamEnumConstList<hulkfight::MissionProgressCondition> E;
        void* p = FUN_0008d690((int)sizeof(S));
        params[0] = p ? new (p) S("mission", FUN_0012e2c0) : 0;
        p = FUN_0008d690((int)sizeof(E));
        params[1] = p ? new (p) E("compare", (*(int*)&DAT_00427760)) : 0;
        p = FUN_0008d690((int)sizeof(S));
        params[2] = p ? new (p) S("progress", FUN_0012e320) : 0;
        FUN_002347b0(&DAT_004e0e4c, params, 3);
    }
    ++DAT_004e0e50;
}
} // namespace fn_001312d0


// 0x001313c0 FUN_001313c0 (172 B): equivalent/0x001313c0.cpp [wrapped: conflict: fight::ParamBool; fight::ParamEnumConstList]
// sym: ?FUN_001313c0@fn_001313c0@@YAXXZ @749de9671d01 @wf752c47f7ee6
namespace fn_001313c0 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_001313c0 @ 0x001313c0


extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(unsigned int);
extern "C" void SetUnlockable_0012dff0();
extern "C" void SetLocked_0012e000();
namespace hulkfight { class UnlockableCondition; }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char base[12];
 const char* list;
 int count;
 void (*callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamBool {
 virtual void slot0();
 char base[12];
 void (*callback)();
 int tail;
 void FUN_00234860(const char*);
};
}
extern "C" void __cdecl FUN_002347b0(int*,void**,int);
void __cdecl FUN_001313c0() {
 if (!DAT_004e0e58) {
  void* params[2];
  fight::ParamEnumConstList<hulkfight::UnlockableCondition>* e = (fight::ParamEnumConstList<hulkfight::UnlockableCondition>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::UnlockableCondition>));
  if(e) {
   e->FUN_00234cc0("unlockable");
   e = new(e) fight::ParamEnumConstList<hulkfight::UnlockableCondition>;
   e->list=((char*)&DAT_0049ceb0); e->count=766; e->callback=SetUnlockable_0012dff0;
  }
  params[0]=e;
  fight::ParamBool<hulkfight::UnlockableCondition>* b=(fight::ParamBool<hulkfight::UnlockableCondition>*)FUN_0008d690((int)sizeof(fight::ParamBool<hulkfight::UnlockableCondition>));
  if(b) {
   b->FUN_00234860("locked");
   b = new(b) fight::ParamBool<hulkfight::UnlockableCondition>;
   b->callback=SetLocked_0012e000;
  }
  params[1]=b;
  FUN_002347b0(&DAT_004e0e54,params,2);
 }
 ++DAT_004e0e58;
}
} // namespace fn_001313c0


// 0x00131470 FUN_00131470 (231 B): equivalent/0x00131470.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamString]
// sym: ?FUN_00131470@fn_00131470@@YAXXZ @44a88934cd9a @w6b9912505589
namespace fn_00131470 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00131470 @ 0x00131470


void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetCompare_0012e010(); void __cdecl SetMission_0012e470(); void __cdecl FUN_0012e4d0();
namespace hulkfight { class GameStateCondition; }
namespace fight {
template<class T> struct ParamString {
 virtual void slot0(); char pad[12]; void (*callback)(); int tail;
 void FUN_002349e0(const char*);
};
template<class T> struct ParamEnumConstList {
 virtual void slot0(); char pad[12]; int* values; int count; void (*callback)(); int tail;
 void FUN_00234cc0(const char*);
};
}
void __cdecl FUN_002347b0(int*, void**, int);
void __cdecl FUN_00131470() {
 if (!DAT_004e0e60) {
 void* params[3];
 fight::ParamString<hulkfight::GameStateCondition>* a = (fight::ParamString<hulkfight::GameStateCondition>*)FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::GameStateCondition>));
 if(a) { a->FUN_002349e0("mission"); new (a) fight::ParamString<hulkfight::GameStateCondition>; a->callback=SetMission_0012e470; }
 params[0]=a;
 fight::ParamEnumConstList<hulkfight::GameStateCondition>* b=(fight::ParamEnumConstList<hulkfight::GameStateCondition>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::GameStateCondition>));
 if(b) { int count=(*(int*)&DAT_00427760); b->FUN_00234cc0("compare"); b->count=count; new (b) fight::ParamEnumConstList<hulkfight::GameStateCondition>; b->values=((int*)&DAT_00427758); b->callback=SetCompare_0012e010; }
 params[1]=b;
 fight::ParamString<hulkfight::GameStateCondition>* c=(fight::ParamString<hulkfight::GameStateCondition>*)FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::GameStateCondition>));
 if(c) { c->FUN_002349e0("gameState"); new (c) fight::ParamString<hulkfight::GameStateCondition>; c->callback=FUN_0012e4d0; }
 params[2]=c;
 FUN_002347b0(((int*)&DAT_004e0e5c),params,3);
 }
 ++DAT_004e0e60;
}
} // namespace fn_00131470


// 0x00131600 FUN_00131600 (284 B): equivalent/0x00131600.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamStringConstList]
// sym: ?FUN_00131600@fn_00131600@@YAXXZ @8b830ab8e1bc @w0b61e0ef9dc6
namespace fn_00131600 {
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 10/10)
// FUN_00131600 @ 0x00131600

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetEnvironmentCompare_0012e020(); void __cdecl SetTimeOfDayCompare_0012e030(); void __cdecl SetEnvironment_0012e710(); void __cdecl SetTimeOfDay_0012e770();
namespace hulkfight { class LocationCondition; }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char base[12]; int* values; int count; void (__cdecl *callback)(); int extra; void FUN_00234cc0(const char*); };
template<class T> struct ParamStringConstList { virtual void slot0(); char base[12]; void (__cdecl *callback)(); int extra; void FUN_00234af0(const char*); };
}
void __cdecl FUN_002347b0(int*,void**,int);
void __cdecl FUN_00131600() {
 if (DAT_004e0e70 == 0) {
 void* entries[4];
 typedef fight::ParamEnumConstList<hulkfight::LocationCondition> Enum;
 typedef fight::ParamStringConstList<hulkfight::LocationCondition> String;
 Enum* a = (Enum*)FUN_0008d690((int)sizeof(Enum));
 if(a) { a->FUN_00234cc0("environmentCompare"); a->Enum::ParamEnumConstList(); a->values=((int*)&DAT_004a9bb4); a->count=3; a->callback=SetEnvironmentCompare_0012e020; }
 entries[0]=a;
 String* b=(String*)FUN_0008d690((int)sizeof(String));
 if(b) { b->FUN_00234af0("environment"); b->String::ParamStringConstList(); b->callback=SetEnvironment_0012e710; }
 entries[1]=b;
 Enum* c=(Enum*)FUN_0008d690((int)sizeof(Enum));
 if(c) { c->FUN_00234cc0("timeOfDayCompare"); c->Enum::ParamEnumConstList(); c->values=((int*)&DAT_004a9bb4); c->count=3; c->callback=SetTimeOfDayCompare_0012e030; }
 entries[2]=c;
 String* d=(String*)FUN_0008d690((int)sizeof(String));
 if(d) { d->FUN_00234af0("timeOfDay"); d->String::ParamStringConstList(); d->callback=SetTimeOfDay_0012e770; }
 entries[3]=d;
 FUN_002347b0(((int*)&DAT_004e0e6c),entries,4);
 }
 ++DAT_004e0e70;
}
} // namespace fn_00131600


// 0x00131e70 hulkfight::DialogueTrack::vfunc_10 (40 B): matches/0x00131e70.cpp
// sym: ?vfunc_10@DialogueTrack@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::DialogueTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    H* p = FUN_0008d690(0x24);
    if (p)
        return p->call_0012ff10(this, c);
    return 0;
}

namespace fn_f587a2cf {

// 0x00131ea0 hulkfight::DialogueAction::vfunc_2 (71 B): matches/0x00131ea0.cpp
// sym: ?vfunc_2@FaceTargetAction@fn_f587a2cf@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
FaceTargetAction* FaceTargetAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_131ea0;
    RefCounted_131ea0* q = *(RefCounted_131ea0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel_0008d330(this);
    }
    return this;
}

} // namespace fn_f587a2cf

// 0x00131ef0 hulkfight::NISSoundTrack::vfunc_10 (40 B): matches/0x00131ef0.cpp
// sym: ?vfunc_10@NISSoundTrack@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00131e70 (propagated; names are from that function)
hulk_intptr hulkfight::NISSoundTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    H* p = FUN_0008d690(0x24);
    if (p)
        return p->call_0012ffa0(this, c);
    return 0;
}

namespace fn_f587a2cf {

// 0x00131f20 hulkfight::NISSoundAction::vfunc_2 (71 B): matches/0x00131f20.cpp
// sym: ?vfunc_2@NISSoundAction_131f20@fn_f587a2cf@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
NISSoundAction_131f20* NISSoundAction_131f20::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_131f20;
    RefCounted_131f20* q = *(RefCounted_131f20* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel_0008d330(this);
    }
    return this;
}

} // namespace fn_f587a2cf

// 0x00131f70 hulkfight::StatTrack::vfunc_10 (40 B): matches/0x00131f70.cpp
// sym: ?vfunc_10@StatTrack@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00131e70 (propagated; names are from that function)
hulk_intptr hulkfight::StatTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    H* p = FUN_0008d690(0x24);
    if (p)
        return p->call_00130030(this, c);
    return 0;
}

namespace fn_f587a2cf {

// 0x00131fa0 hulkfight::StatAction::vfunc_2 (71 B): matches/0x00131fa0.cpp
// sym: ?vfunc_2@StatAction_131fa0@fn_f587a2cf@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
StatAction_131fa0* StatAction_131fa0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_131fa0;
    RefCounted_131fa0* q = *(RefCounted_131fa0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel_0008d330(this);
    }
    return this;
}

} // namespace fn_f587a2cf

// 0x00131ff0 hulkfight::StatBeginTrialTrack::vfunc_10 (40 B): matches/0x00131ff0.cpp
// sym: ?vfunc_10@StatBeginTrialTrack@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00131e70 (propagated; names are from that function)
hulk_intptr hulkfight::StatBeginTrialTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    H* p = FUN_0008d690(0x24);
    if (p)
        return p->call_001300c0(this, c);
    return 0;
}

namespace fn_f587a2cf {

// 0x00132020 hulkfight::StatBeginTrialAction::vfunc_2 (71 B): matches/0x00132020.cpp
// sym: ?vfunc_2@StatBeginTrialAction_132020@fn_f587a2cf@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
StatBeginTrialAction_132020* StatBeginTrialAction_132020::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_132020;
    RefCounted_132020* q = *(RefCounted_132020* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel_0008d330(this);
    }
    return this;
}

} // namespace fn_f587a2cf

// 0x00132070 hulkfight::StatEndTrialTrack::vfunc_10 (40 B): matches/0x00132070.cpp
// sym: ?vfunc_10@StatEndTrialTrack@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00131e70 (propagated; names are from that function)
hulk_intptr hulkfight::StatEndTrialTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    H* p = FUN_0008d690(0x24);
    if (p)
        return p->call_00130150(this, c);
    return 0;
}

namespace fn_f587a2cf {

// 0x001320a0 hulkfight::StatEndTrialAction::vfunc_2 (71 B): matches/0x001320a0.cpp
// sym: ?vfunc_2@StatEndTrialAction_1320a0@fn_f587a2cf@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
StatEndTrialAction_1320a0* StatEndTrialAction_1320a0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_1320a0;
    RefCounted_1320a0* q = *(RefCounted_1320a0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel_0008d330(this);
    }
    return this;
}

} // namespace fn_f587a2cf

// 0x001320f0 hulkfight::XPTrack::vfunc_10 (40 B): matches/0x001320f0.cpp
// sym: ?vfunc_10@XPTrack@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00131e70 (propagated; names are from that function)
hulk_intptr hulkfight::XPTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    H* p = FUN_0008d690(0x24);
    if (p)
        return p->call_001301e0(this, c);
    return 0;
}

namespace fn_f587a2cf {

// 0x00132120 hulkfight::XPAction::vfunc_2 (71 B): matches/0x00132120.cpp
// sym: ?vfunc_2@XPAction_132120@fn_f587a2cf@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
XPAction_132120* XPAction_132120::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_132120;
    RefCounted_132120* q = *(RefCounted_132120* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel_0008d330(this);
    }
    return this;
}

} // namespace fn_f587a2cf

// 0x00132170 hulkfight::DebugPrintTrack::vfunc_10 (86 B): matches/0x00132170.cpp [wrapped: conflict: fight::Param; fight::Track; hulkfight::DebugPrintAction; hulkfight::DebugPrintTrack]
// sym: ?vfunc_10@DebugPrintTrack@hulkfight@fn_00132170@@UAEPAVDebugPrintAction@23@HHPAVRef@3@@Z
void* operator new(size_t);
namespace fn_00132170 {
/* size_t: tree_prelude.h */

namespace fight {
class Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};
class Param {};
} // namespace fight
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
namespace hulkfight {
class DebugPrintTrack;
class ActionBase {
  public:
    virtual void Run();
    char pad[24];
    ActionBase() throw();
};
class DebugPrintAction : public ActionBase {
  public:
    DebugPrintTrack* owner;
    Ref* ref;
    DebugPrintAction(DebugPrintTrack* t, Ref* r) throw() : owner(t), ref(0) {
        if (r)
            r->Add();
        if (ref)
            ref->Release();
        ref = r;
    }
    virtual void Run();
};
class DebugPrintTrack : public fight::Track, public fight::Param {
  public:
    virtual DebugPrintAction* vfunc_10(int a, int b, Ref* r);
};
DebugPrintAction* DebugPrintTrack::vfunc_10(int a, int b, Ref* r) {
    return new DebugPrintAction(this, r);
}
} // namespace hulkfight
} // namespace fn_00132170

namespace fn_f587a2cf {

// 0x001321d0 hulkfight::DebugPrintAction::vfunc_2 (57 B): matches/0x001321d0.cpp
// sym: ?f2@DebugPrintAction_1321d0@fn_f587a2cf@@QAEPAV12@E@Z
DebugPrintAction_1321d0* DebugPrintAction_1321d0::f2(unsigned char flags) {
    vptr = g_vftable_1321d0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1321d0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x001324d0 FUN_001324d0 (38 B): matches/0x001324d0.cpp
// sym: _FUN_001324d0
extern "C" void FUN_001324d0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1324d0 caster;
    void* p = Find_00236ac0(name, &caster);
    owner->Set_002367c0(p);
}

} // namespace fn_f587a2cf

// 0x00132500 FUN_00132500 (38 B): matches/0x00132500.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: _FUN_00132500
namespace fn_00132500 {
namespace hulkfight {
class NISSoundTrack;
}
namespace fight {
template <class T> class TrackFactoryCasterTemplate {
  public:
    virtual void Cast();
};
} // namespace fight
class TrackManager {
  public:
    void Add_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* FUN_00236ac0(const char*, fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack>*);
extern "C" void FUN_00132500(TrackManager* manager, const char* name) {
    fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack> caster;
    manager->Add_002367c0(FUN_00236ac0(name, &caster));
}
} // namespace fn_00132500

namespace fn_f587a2cf {

// 0x00132530 FUN_00132530 (38 B): matches/0x00132530.cpp
// sym: _FUN_00132530
extern "C" void __cdecl FUN_00132530(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_132530 caster;
    void* p = FUN_00236ac0(name, &caster);
    owner->Set_002367c0(p);
}


// 0x00132560 FUN_00132560 (38 B): matches/0x00132560.cpp
// sym: _FUN_00132560
extern "C" void __cdecl FUN_00132560(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_132560 caster;
    obj->apply_002367c0(find_00236ac0(name, &caster));
}

} // namespace fn_f587a2cf

// 0x00132590 FUN_00132590 (38 B): matches/0x00132590.cpp [wrapped: conflict: Find]
// sym: _FUN_00132590
namespace fn_00132590 {
class TrackFactoryCasterTemplate_132590 {
  public:
    virtual void f();
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(char*, TrackFactoryCasterTemplate_132590*);
class Owner {
  public:
    void Add_002367c0(void*);
};
extern "C" void __cdecl FUN_00132590(Owner* owner, char* name) {
    TrackFactoryCasterTemplate_132590 caster;
    owner->Add_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_00132590

namespace fn_f587a2cf {

// 0x001325c0 FUN_001325c0 (38 B): matches/0x001325c0.cpp
// sym: _FUN_001325c0
extern "C" void FUN_001325c0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1325c0 caster;
    void* p = FUN_00236ac0(name, &caster);
    owner->Set_002367c0(p);
}


// 0x001325f0 FUN_001325f0 (38 B): matches/0x001325f0.cpp
// sym: _FUN_001325f0
extern "C" void FUN_001325f0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1325f0 c;
    owner->Set_002367c0(FUN_00236ac0(name, &c));
}

} // namespace fn_f587a2cf

// 0x00132620 FUN_00132620 (213 B): matches/0x00132620.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_00132620
namespace fn_00132620 {
namespace hulkfight {
class MissionProgressCondition;
class UnlockableCondition;
class GameStateCondition;
class DebugPrintCondition;
class LocationCondition;
class ChapterMissionCondition;
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryCasterTemplate {
  public:
    virtual void Cast();
};
} // namespace fight
extern "C" void* __cdecl FUN_002343e0(const char*, const void*);
struct Registry_132620 {
    void FUN_00236760(void*);
};
extern "C" void __cdecl FUN_00132620(Registry_132620* registry) {
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::UnlockableCondition> caster;
        registry->FUN_00236760(FUN_002343e0("unlockable", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::DebugPrintCondition> caster;
        registry->FUN_00236760(FUN_002343e0("debugPrint", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ChapterMissionCondition> caster;
        registry->FUN_00236760(FUN_002343e0("chapterMission", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::LocationCondition> caster;
        registry->FUN_00236760(FUN_002343e0("location", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::GameStateCondition> caster;
        registry->FUN_00236760(FUN_002343e0("gameState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::MissionProgressCondition> caster;
        registry->FUN_00236760(FUN_002343e0("missionProgress", &caster));
    }
}
} // namespace fn_00132620

namespace fn_f587a2cf {

// 0x00132780 fight::ConditionFactoryTemplate<hulkfight::MissionProgressCondition>::vfunc_2 (43 B): matches/0x00132780.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f587a2cf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411a20;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f587a2cf

// 0x001327f0 fight::ConditionFactoryTemplate<hulkfight::UnlockableCondition>::vfunc_5 (51 B): matches/0x001327f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VUnlockableCondition@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::UnlockableCondition>::vfunc_5() {
    Obj_1327f0* p = (Obj_1327f0*)Alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00411244);
        p->z = 0;
        p->c = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f587a2cf {

// 0x00132830 fight::ConditionFactoryTemplate<hulkfight::UnlockableCondition>::vfunc_2 (43 B): matches/0x00132830.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_132830@fn_f587a2cf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_132830::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411a3c;
    base1_dtor_0012e380();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}


// 0x001328e0 fight::ConditionFactoryTemplate<hulkfight::GameStateCondition>::vfunc_2 (43 B): matches/0x001328e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1328e0@fn_f587a2cf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1328e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411a58;
    base1_dtor_0012e3e0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f587a2cf

// 0x00132950 fight::ConditionFactoryTemplate<hulkfight::DebugPrintCondition>::vfunc_5 (54 B): matches/0x00132950.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VDebugPrintCondition@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::DebugPrintCondition>::vfunc_5() {
    DebugPrintCondition_132950* p = (DebugPrintCondition_132950*)Alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        p->vptr = ((hulk_intptr)DAT_00411284);
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f587a2cf {

// 0x00132990 fight::ConditionFactoryTemplate<hulkfight::DebugPrintCondition>::vfunc_2 (43 B): matches/0x00132990.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_132990@fn_f587a2cf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_132990::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411a74;
    base1_dtor_0012e530();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}


// 0x00132a00 fight::ConditionFactoryTemplate<hulkfight::LocationCondition>::vfunc_5 (56 B): matches/0x00132a00.cpp
// sym: ?FactoryVfunc5@fn_f587a2cf@@YAPAXXZ
void* FactoryVfunc5() {
    GameStateCondition_132a00* p = (GameStateCondition_132a00*)FUN_0008d690((int)sizeof(GameStateCondition_132a00));
    if (p) {
        p->Init_00234590(0);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        *(hulk_intptr*)p = (hulk_intptr)&DAT_004112a4;
        return p;
    }
    return 0;
}


// 0x00132a40 fight::ConditionFactoryTemplate<hulkfight::LocationCondition>::vfunc_2 (43 B): matches/0x00132a40.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_132a40@fn_f587a2cf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_132a40::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411a90;
    base1_dtor_0012e680();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}


// 0x00132ab0 fight::ConditionFactoryTemplate<hulkfight::ChapterMissionCondition>::vfunc_5 (63 B): matches/0x00132ab0.cpp
// sym: ?Factory_vfunc5@fn_f587a2cf@@YAPAUGameStateCondition_132ab0@1@XZ
GameStateCondition_132ab0* Factory_vfunc5(void) {
    GameStateCondition_132ab0* p = (GameStateCondition_132ab0*)FUN_0008d690((int)sizeof(GameStateCondition_132ab0));
    if (p) {
        p->InitBase_00234590(0);
        p->x10 = -1;
        p->x18 = -1;
        p->v0 = ((hulk_intptr)DAT_004112c4);
        p->x0c = 0;
        p->x14 = 0;
        return p;
    }
    return 0;
}


// 0x00132af0 fight::ConditionFactoryTemplate<hulkfight::ChapterMissionCondition>::vfunc_2 (43 B): matches/0x00132af0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_132af0@fn_f587a2cf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_132af0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411aac;
    base1_dtor_0012e7d0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f587a2cf

// 0x00132b60 fight::TrackFactoryTemplate<hulkfight::StatBeginTrialTrack>::vfunc_5 (52 B): matches/0x00132b60.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VStatBeginTrialTrack@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::StatBeginTrialTrack>::vfunc_5() {
    Track_132b60* p = (Track_132b60*)alloc(0x14);
    if (p) {
        p->Track_132b60::Track_132b60();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004112e4);
        *(u32_132b60*)((char*)p + 0xc) = 0;
        *(u32_132b60*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00132ba0 fight::TrackFactoryTemplate<hulkfight::StatBeginTrialTrack>::vfunc_2 (43 B): matches/0x00132ba0.cpp [wrapped: same definition as 0x00132780 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00132ba0@@QAEPAXE@Z
namespace fn_00132ba0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00411ac8;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0012e840();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411ac8;
    base1_dtor_0012e840();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00132ba0


// 0x00132c50 fight::TrackFactoryTemplate<hulkfight::NISSoundTrack>::vfunc_2 (43 B): matches/0x00132c50.cpp [wrapped: same definition as 0x00132780 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00132c50@@QAEPAXE@Z
namespace fn_00132c50 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00411ae4;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0012e930();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411ae4;
    base1_dtor_0012e930();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00132c50


// 0x00132cc0 fight::TrackFactoryTemplate<hulkfight::DialogueTrack>::vfunc_5 (71 B): matches/0x00132cc0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VDialogueTrack@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::DialogueTrack>::vfunc_5() {
    DialogueTrack_132cc0* p = (DialogueTrack_132cc0*)FUN_0008d690((int)sizeof(DialogueTrack_132cc0));
    int z = 0;
    if (p != 0) {
        p->Init_00236d40();
        p->a = z;
        p->b = z;
        p->c = z;
        p->d = z;
        p->e = z;
        p->f = z;
        p->g = (char)z;
        *(void**)p = (void*)((hulk_intptr)DAT_00411344);
        *((int*)p + 2) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00132d10 fight::TrackFactoryTemplate<hulkfight::DialogueTrack>::vfunc_2 (43 B): matches/0x00132d10.cpp [wrapped: same definition as 0x00132780 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00132d10@@QAEPAXE@Z
namespace fn_00132d10 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00411b00;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0012eb00();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411b00;
    base1_dtor_0012eb00();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00132d10


// 0x00132dd0 fight::TrackFactoryTemplate<hulkfight::DebugPrintTrack>::vfunc_2 (43 B): matches/0x00132dd0.cpp [wrapped: same definition as 0x00132780 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00132dd0@@QAEPAXE@Z
namespace fn_00132dd0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00411b1c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0012ed40();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411b1c;
    base1_dtor_0012ed40();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00132dd0

