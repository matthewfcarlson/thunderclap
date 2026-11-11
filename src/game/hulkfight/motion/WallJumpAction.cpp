// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0013e810..0x00143100 (kind game, layer game, confidence high), dominant class hulkfight::motion::WallJumpAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8068520 {
#define TREE_TU_END }
namespace fn_f8068520 {} using namespace fn_f8068520;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f8068520 {
struct SubObj_13e9a0 {
    char pad[0x40];
    char* p40;
};
struct Obj_13e9a0 {
    char pad[0x40];
    char* p40;
};
struct Obj_13e9b0 {
    char pad[0x48];
};
class A_13ea30 {
  public:
    virtual void V();
    char pad[12];
    int m;
    unsigned char Set(int x);
};
class Obj_13ea40 {
  public:
    char pad[0x14];
    float value;
};
extern const float rad_13ec30 = 0.017453292f;
struct O_13ec30 {
    virtual void V();
    char pad[0x40];
    float v;
    bool Set(float x);
};
const float RADIAN_FACTOR = 0.017453292f;
extern int* hulk_at_004e0f40;
class CCondition_13ee40 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0f48;
class CCondition_13eeb0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_13ef60 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_13ef60 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" char DAT_00412ad0[];
struct Base {
    virtual void f();
    ~Base();
};
struct Sub_13ef70 {
    unsigned char x[8];
    void Dtor_0027af50();
};
struct WallRunTrack : Base {
    unsigned char pad[0x34];
    Sub_13ef70 a;
    Sub_13ef70 b;
    Sub_13ef70 c;
    void Kill();
};
extern int* hulk_at_004e0f50;
class CCondition_13efc0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_13f050 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_13f050 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0f58;
class CCondition_13f090 {
  public:
    virtual int vfunc_0(int);
};
class Track_13f0a0 {
  public:
    Track_13f0a0();
    virtual void vf();
    char pad[8];
};
class WallExitTrack : public Track_13f0a0 {
  public:
    WallExitTrack();
    virtual void vf();
    int a;
    float b;
    int c;
    int d;
    float e;
    int f;
    float g;
    float h;
    int i;
    int j;
    int k;
};
struct Param_13f100 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_13f100 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
typedef unsigned int u32_13f190;
struct Proxy;
struct Owner_13f190 {
    Proxy* second_00059a40();
};
struct Proxy {
    void apply_00222970(u32_13f190, int);
};
struct Two_13f610 {
    void* Fnf_00059a40();
};
struct Two_13f640 {
    void* Fnf_00059a40();
};
extern void* hulk_at_00412ab0[];
class Condition_13f720 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class WallVelocityCondition_13f720 : public Condition_13f720 {
  public:
    WallVelocityCondition_13f720* vfunc_5(signed char flags);
};
extern void* hulk_at_00412b00[];
class Track_13f790 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class WallJumpTrack_13f790 : public Track_13f790 {
  public:
    WallJumpTrack_13f790* vfunc_5(signed char flags);
};
extern void* hulk_at_00412b30[];
class Track_13f7c0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class WallExitTrack_13f7c0 : public Track_13f7c0 {
  public:
    WallExitTrack_13f7c0* vfunc_5(signed char flags);
};
class Ref_13f9c0 {
  public:
    virtual void First();
    virtual void Release();
};
class Action_13f9c0 {
  public:
    hulk_intptr v;
    Action_13f9c0();
};
class WallRunAction : public Action_13f9c0 {
  public:
    WallRunAction(int, Ref_13f9c0*);
    char _m_pad_4[0x18];
    int m1c;
    union { Ref_13f9c0* m20; Owner_13f190* owner; };
    union { int m24; u32_13f190 value24; };
    union { int m28; u32_13f190 value28; };
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    char m50;
    char _m_pad_51[0x3];
    int m54;
    void vfunc_4();
};
extern int hulk_at_00412b60;
extern void* g_vftable_13fa30[];
class Ref_13fa30 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_13fa30 {
  public:
    void* vptr;
};
class WallRunAction_13fa30 : public Action_13fa30 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_13fa30* m20;
    Ref_13fa30* m24;
    Ref_13fa30* m28;
    ~WallRunAction_13fa30();
};
class Ref_140100 {
  public:
    virtual void Add();
    virtual void Rel();
};
class Action_140100 {
  public:
    Action_140100();
    virtual void f0_00018b30();
    char pad[0x18];
};
class WallExitAction : public Action_140100 {
  public:
    WallExitAction(int a, Ref_140100* b);
    virtual void g0_00018b40();
    int m1c;
    Ref_140100* m20;
    int m24, m28, m2c, m30, m34, m38;
    float m3c;
    int m40, m44, m48;
};
extern void* hulk_at_00412b80[];
class Ref_140170 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_140170 {
  public:
    void* vptr;
};
class WallExitAction_140170 : public Action_140170 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_140170* m20;
    Ref_140170* m24;
    ~WallExitAction_140170();
};
class Obj_140590 {
  public:
    virtual void f();
    virtual void g();
};
class Action_140590 {
  public:
    Action_140590();
    virtual void a();
    char pad[0x18];
};
class WallJumpAction_140590 : public Action_140590 {
  public:
    WallJumpAction_140590(int p, Obj_140590* o);
    virtual void a();
    int m1;
    Obj_140590* m2;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    float m3c;
    char m40;
    int m44;
    int m48;
    int m4c;
};
extern void* hulk_at_00412b9c[];
class Ref_140600 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_140600 {
  public:
    void* vptr;
};
class WallJumpAction_140600 : public Action_140600 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_140600* m20;
    Ref_140600* m24;
    ~WallJumpAction_140600();
};
struct CAxisArcCondition_141570;
class CStageCondition_141580 {};
class ParamValue_141580 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_141580 : public ParamValue_141580 {
  public:
    virtual void f();
};
class CStageCondition_141610;
class ParamValue_141610 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_141610 : public ParamValue_141610 {
  public:
    int pad;
};
class CStageCondition_141660;
class ParamValue_141660 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_141660 : public ParamValue_141660 {
  public:
    int pad;
};
class CStageCondition_1416b0;
class ParamValue_1416b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1416b0 : public ParamValue_1416b0 {
  public:
    int pad;
};
class CStageCondition_141700;
class ParamValue_141700 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_141700 : public ParamValue_141700 {
  public:
    int pad;
};
class CStageCondition_141750;
class ParamValue_141750 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_141750 : public ParamValue_141750 {
  public:
    int pad;
};
class CStageCondition_1417a0;
class ParamValue_1417a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1417a0 : public ParamValue_1417a0 {
  public:
    int pad;
};
class CStageCondition_1417f0;
class ParamValue_1417f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1417f0 : public ParamValue_1417f0 {
  public:
    int pad;
};
class CStageCondition_141840;
class ParamValue_141840 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_141840 : public ParamValue_141840 {
  public:
    int pad;
};
class CStageCondition_141890;
class ParamValue_141890 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_141890 : public ParamValue_141890 {
  public:
    int pad;
};
extern char DAT_004ad4d0;
} // namespace fn_f8068520
namespace fight {
class ConditionFactoryCaster_1418b0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class WallVelocityCondition_1418b0 {};
} }
namespace fight {
class TrackFactoryCaster_141930 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f8068520 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004ad588;
} // namespace fn_f8068520
namespace fight {
class TrackFactoryCaster_1419d0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class WallJumpTrack_1419d0 {};
} }
namespace fn_f8068520 {
extern char DAT_004ad630;
extern char DAT_004ad6d8;
class TrackFactoryCaster_141a70 {
  public:
    virtual int Cast(void* obj);
};
typedef unsigned int u32_1421d0;
struct Helper_1421d0 {
    int run_0013f9c0(hulkfight::motion::WallRunTrack*, u32_1421d0);
};
extern int __cdecl FUN_00344e74(u32_1421d0, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char hulk_at_00494b44[];
extern const char hulk_at_00494b60[];
extern void* g_vftable_142220[];
class Ref_142220 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_142220 {
  public:
    void* vptr;
};
class WallRunAction_142220 : public Action_142220 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_142220* m20;
    Ref_142220* m24;
    Ref_142220* m28;
    WallRunAction_142220* f2(unsigned char flags);
};
struct Obj_142280 {
    int Init_00140100(hulkfight::motion::WallExitTrack*, hulk_intptr);
};
extern void* __cdecl Alloc_0008d690(int);
extern int g1_142280, g2;
extern int g_vftable_1422d0;
class RefObj_1422d0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class WallExitAction_1422d0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_1422d0* m2;
    RefObj_1422d0* m3;
    void* vfunc_2(unsigned char flag);
};
struct Result_142330 {
    unsigned int init_00140590(hulkfight::motion::WallJumpTrack*, hulk_uintptr);
};
extern Result_142330* MakeResult_0008d690(void*);
extern const int RT1;
extern const int RT2;
extern int g_vftable_142380;
class RefObj_142380 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class WallJumpAction_142380 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_142380* m2;
    RefObj_142380* m3;
    void* vfunc_2(unsigned char flag);
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class Track {};
class TrackFactoryCasterTemplate_1424e0 {
  public:
    virtual bool Cast_00141930(void*);
    TrackFactoryCasterTemplate_1424e0() {}
};
Track* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_1424e0*);
class Owner {
  public:
    void Set_002367c0(Track*);
    void Add_002367c0(void*);
};
class TrackFactoryCasterTemplate_1428b0 {
  public:
    virtual bool Cast_001419d0(void*);
};
class Obj {
  public:
    void Apply_002367c0(void*);
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_1428b0*);
class TrackFactoryCasterTemplate_1428e0 {
  public:
    virtual bool Cast_00141a70(void*);
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_1428e0*);
class ConditionFactoryCasterTemplate_142910 {
  public:
    virtual bool Cast_001418b0(void*);
};
struct Result;
extern "C" Result* FUN_002343e0(const char*, ConditionFactoryCasterTemplate_142910*);
class Manager {
  public:
    void Add_00236760(Result*);
};
} // namespace fn_f8068520
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8068520 {
class TrackFactoryTemplate_142ea0 {
  public:
    TrackFactoryTemplate_142ea0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00412ab0[];
class Obj_142ee0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Obj_142ee0* v5();
    void Init_00234590(int);
    int a;
    char pad[4];
    int b;
    int c;
};
extern int hulk_at_00412e48;
struct ConditionFactoryTemplate_142f20 {
    void* m_vptr;
    void base1_dtor_0013ee20();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_142f50 {
  public:
    TrackFactoryTemplate_142f50() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_00412e64;
class TrackFactoryTemplate_142fe0 {
  public:
    TrackFactoryTemplate_142fe0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class Track_143020 {
  public:
    hulk_intptr method_0013f0a0();
};
extern void* __cdecl operator_new(unsigned int);
class TrackFactoryTemplate_143070 {
  public:
    TrackFactoryTemplate_143070() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_1430b0;
extern void* __cdecl Alloc(hulk_uintptr);
struct InitObj_1430b0 {
    hulk_uintptr Init_0013eec0();
};

} // namespace fn_f8068520

// 0x0013e810 FUN_0013e810 (12 B): matches/0x0013e810.cpp
// sym: ?FUN_0013e810@X_13e810@owners@@QAE_NH@Z
bool owners::X_13e810::FUN_0013e810(int v) {
    m12 = v;
    return true;
}


// 0x0013e820 FUN_0013e820 (12 B): matches/0x0013e820.cpp
// sym: ?FUN_0013e820@Obj_13e820@owners@@QAEDH@Z
char owners::Obj_13e820::FUN_0013e820(int a) {
    m10 = a;
    return 1;
}


// 0x0013e830 FUN_0013e830 (12 B): matches/0x0013e830.cpp
// sym: ?FUN_0013e830@Obj_13e830@owners@@QAE_NH@Z
bool owners::Obj_13e830::FUN_0013e830(int v) {
    m1c = v;
    return true;
}


// 0x0013e840 FUN_0013e840 (12 B): matches/0x0013e840.cpp
// sym: ?FUN_0013e840@X_13e840@owners@@QAE_NH@Z
bool owners::X_13e840::FUN_0013e840(int v) {
    mValue = v;
    return true;
}


// 0x0013e860 FUN_0013e860 (12 B): matches/0x0013e860.cpp
// sym: ?FUN_0013e860@Obj_13e860@owners@@QAE_NH@Z
bool owners::Obj_13e860::FUN_0013e860(int v) {
    mValue = v;
    return true;
}


// 0x0013e880 FUN_0013e880 (12 B): matches/0x0013e880.cpp
// sym: ?FUN_0013e880@C_13e880@owners@@QAE_NH@Z
bool owners::C_13e880::FUN_0013e880(int value) {
    mValue = value;
    return true;
}


// 0x0013e8a0 FUN_0013e8a0 (12 B): matches/0x0013e8a0.cpp
// sym: ?FUN_0013e8a0@Obj_13e8a0@owners@@QAE_NH@Z
bool owners::Obj_13e8a0::FUN_0013e8a0(int x) {
    mValue = x;
    return true;
}


// 0x0013e8c0 FUN_0013e8c0 (12 B): matches/0x0013e8c0.cpp
// sym: ?FUN_0013e8c0@Obj_13e8c0@owners@@QAEDH@Z
char owners::Obj_13e8c0::FUN_0013e8c0(int value) {
    m20 = value;
    return 1;
}


// 0x0013e8e0 FUN_0013e8e0 (12 B): matches/0x0013e8e0.cpp
// sym: ?FUN_0013e8e0@Obj_13e8e0@owners@@QAEDE@Z
char owners::Obj_13e8e0::FUN_0013e8e0(unsigned char a) {
    m24 = a;
    return 1;
}


// 0x0013e900 FUN_0013e900 (12 B): matches/0x0013e900.cpp
// sym: ?FUN_0013e900@Obj_13e900@owners@@QAE_NH@Z
bool owners::Obj_13e900::FUN_0013e900(int v) {
    mValue = v;
    return true;
}


// 0x0013e920 FUN_0013e920 (12 B): matches/0x0013e920.cpp
// sym: ?FUN_0013e920@Obj_13e920@owners@@QAEDH@Z
char owners::Obj_13e920::FUN_0013e920(int a) {
    m2c = a;
    return 1;
}


// 0x0013e940 FUN_0013e940 (18 B): matches/0x0013e940.cpp
// sym: ?FUN_0013e940@Obj_13e940@owners@@QAE_NM@Z
bool owners::Obj_13e940::FUN_0013e940(float deg) {
    angle = deg * 0.01745329238474369f;
    return true;
}


// 0x0013e970 FUN_0013e970 (18 B): matches/0x0013e970.cpp
// sym: ?FUN_0013e970@R_13e970@owners@@QAE_NM@Z
bool owners::R_13e970::FUN_0013e970(float x) {
    v = x * 0.017453292f;
    return 1;
}


// 0x0013e990 FUN_0013e990 (4 B): matches/0x0013e990.cpp
// sym: ?FUN_0013e990@X_13e990@owners@@QAEPAXXZ
void* owners::X_13e990::FUN_0013e990() {
    return (char*)this + 0x38;
}

namespace fn_f8068520 {

// 0x0013e9a0 FUN_0013e9a0 (4 B): matches/0x0013e9a0.cpp
// sym: ?FUN_0013e9a0@fn_f8068520@@YIPAUObj_13e9a0@1@PAU21@@Z
Obj_13e9a0* __fastcall FUN_0013e9a0(Obj_13e9a0* self) {
    return (Obj_13e9a0*)((char*)self + 0x40);
}


// 0x0013e9b0 FUN_0013e9b0 (4 B): matches/0x0013e9b0.cpp
// sym: @FUN_0013e9b0@4
extern "C" void* __fastcall FUN_0013e9b0(Obj_13e9b0* self) {
    return (char*)self + 0x48;
}

} // namespace fn_f8068520

// 0x0013e9d0 FUN_0013e9d0 (12 B): matches/0x0013e9d0.cpp
// sym: ?FUN_0013e9d0@Obj_13e9d0@owners@@QAE_NH@Z
bool owners::Obj_13e9d0::FUN_0013e9d0(int x) {
    m50 = x;
    return true;
}


// 0x0013e9f0 FUN_0013e9f0 (12 B): matches/0x0013e9f0.cpp
// sym: ?FUN_0013e9f0@O_13e9f0@owners@@QAE_NH@Z
bool owners::O_13e9f0::FUN_0013e9f0(int x) {
    mValue = x;
    return true;
}


// 0x0013ea10 FUN_0013ea10 (12 B): matches/0x0013ea10.cpp
// sym: ?FUN_0013ea10@C_13ea10@owners@@QAE_NH@Z
bool owners::C_13ea10::FUN_0013ea10(int x) {
    m = x;
    return true;
}


// 0x0013ea20 FUN_0013ea20 (12 B): matches/0x0013ea20.cpp
// sym: ?FUN_0013ea20@Obj_13ea20@owners@@QAEDH@Z
char owners::Obj_13ea20::FUN_0013ea20(int x) {
    value = x;
    return 1;
}

namespace fn_f8068520 {

// 0x0013ea30 FUN_0013ea30 (12 B): matches/0x0013ea30.cpp
// sym: ?Set@A_13ea30@fn_f8068520@@QAEEH@Z
unsigned char A_13ea30::Set(int x) {
    m = x;
    return 1;
}


// 0x0013ea40 FUN_0013ea40 (4 B): matches/0x0013ea40.cpp
// sym: ?FUN_0013ea40@fn_f8068520@@YIMPAVObj_13ea40@1@@Z
float __fastcall FUN_0013ea40(Obj_13ea40* p) {
    return p->value;
}

} // namespace fn_f8068520

// 0x0013ea50 FUN_0013ea50 (12 B): matches/0x0013ea50.cpp
// sym: ?FUN_0013ea50@Obj_13ea50@owners@@QAEDH@Z
char owners::Obj_13ea50::FUN_0013ea50(int v) {
    m14 = v;
    return 1;
}


// 0x0013ea70 FUN_0013ea70 (12 B): matches/0x0013ea70.cpp
// sym: ?FUN_0013ea70@Obj_13ea70@owners@@QAEDH@Z
char owners::Obj_13ea70::FUN_0013ea70(int v) {
    value = v;
    return 1;
}


// 0x0013ea90 FUN_0013ea90 (12 B): matches/0x0013ea90.cpp
// sym: ?FUN_0013ea90@A_13ea90@owners@@QAEDH@Z
char owners::A_13ea90::FUN_0013ea90(int x) {
    m = x;
    return 1;
}


// 0x0013eab0 FUN_0013eab0 (12 B): matches/0x0013eab0.cpp
// sym: ?FUN_0013eab0@Obj_13eab0@owners@@QAEDH@Z
char owners::Obj_13eab0::FUN_0013eab0(int v) {
    *(int*)((char*)this + 0x20) = v;
    return 1;
}


// 0x0013ead0 FUN_0013ead0 (18 B): matches/0x0013ead0.cpp
// sym: ?FUN_0013ead0@Obj_13ead0@owners@@QAEDM@Z
char owners::Obj_13ead0::FUN_0013ead0(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}


// 0x0013eb00 FUN_0013eb00 (18 B): matches/0x0013eb00.cpp
// sym: ?FUN_0013eb00@X_13eb00@owners@@QAEDM@Z
char owners::X_13eb00::FUN_0013eb00(float x) {
    angle = x * 0.0174532925f;
    return 1;
}


// 0x0013eb30 FUN_0013eb30 (18 B): matches/0x0013eb30.cpp
// sym: ?FUN_0013eb30@Obj_13eb30@owners@@QAEDM@Z
char owners::Obj_13eb30::FUN_0013eb30(float a) {
    angle = a * 0.017453292519943295f;
    return 1;
}


// 0x0013eb60 FUN_0013eb60 (18 B): matches/0x0013eb60.cpp
// sym: ?FUN_0013eb60@A_13eb60@owners@@QAEEM@Z
unsigned char owners::A_13eb60::FUN_0013eb60(float x) {
    m = x * 0.017453292519943295f;
    return 1;
}


// 0x0013eb90 FUN_0013eb90 (12 B): matches/0x0013eb90.cpp
// sym: ?FUN_0013eb90@Obj_13eb90@owners@@QAEDH@Z
char owners::Obj_13eb90::FUN_0013eb90(int x) {
    m34 = x;
    return 1;
}


// 0x0013ebb0 FUN_0013ebb0 (12 B): matches/0x0013ebb0.cpp
// sym: ?FUN_0013ebb0@C_13ebb0@owners@@QAEEE@Z
unsigned char owners::C_13ebb0::FUN_0013ebb0(unsigned char x) {
    m38 = x;
    return 1;
}


// 0x0013ebd0 FUN_0013ebd0 (18 B): matches/0x0013ebd0.cpp
// sym: ?FUN_0013ebd0@Obj_13ebd0@owners@@QAEDM@Z
char owners::Obj_13ebd0::FUN_0013ebd0(float x) {
    angle = x * 0.017453292f;
    return 1;
}


// 0x0013ec00 FUN_0013ec00 (18 B): matches/0x0013ec00.cpp
// sym: ?FUN_0013ec00@X_13ec00@owners@@QAE_NM@Z
bool owners::X_13ec00::FUN_0013ec00(float degrees) {
    angle = degrees * 0.017453292519943295f;
    return true;
}

namespace fn_f8068520 {

// 0x0013ec30 FUN_0013ec30 (18 B): matches/0x0013ec30.cpp
// sym: ?Set@O_13ec30@fn_f8068520@@QAE_NM@Z
bool O_13ec30::Set(float x) {
    v = x * rad_13ec30;
    return true;
}

} // namespace fn_f8068520

// 0x0013ec60 FUN_0013ec60 (12 B): matches/0x0013ec60.cpp
// sym: ?FUN_0013ec60@Obj_13ec60@owners@@QAE_NH@Z
bool owners::Obj_13ec60::FUN_0013ec60(int v) {
    value = v;
    return true;
}


// 0x0013ec80 FUN_0013ec80 (12 B): matches/0x0013ec80.cpp
// sym: ?FUN_0013ec80@Obj_13ec80@owners@@QAEDH@Z
char owners::Obj_13ec80::FUN_0013ec80(int x) {
    value = x;
    return 1;
}


// 0x0013eca0 FUN_0013eca0 (12 B): matches/0x0013eca0.cpp
// sym: ?FUN_0013eca0@X_13eca0@owners@@QAE_NH@Z
bool owners::X_13eca0::FUN_0013eca0(int v) {
    m50 = v;
    return true;
}


// 0x0013ecb0 FUN_0013ecb0 (12 B): matches/0x0013ecb0.cpp
// sym: ?FUN_0013ecb0@Obj_13ecb0@owners@@QAEDH@Z
char owners::Obj_13ecb0::FUN_0013ecb0(int x) {
    mValue = x;
    return 1;
}


// 0x0013ecc0 FUN_0013ecc0 (12 B): matches/0x0013ecc0.cpp
// sym: ?FUN_0013ecc0@Obj_13ecc0@owners@@QAEDH@Z
char owners::Obj_13ecc0::FUN_0013ecc0(int v) {
    m10 = v;
    return 1;
}


// 0x0013ece0 FUN_0013ece0 (12 B): matches/0x0013ece0.cpp
// sym: ?FUN_0013ece0@Obj_13ece0@owners@@QAEDH@Z
char owners::Obj_13ece0::FUN_0013ece0(int v) {
    m14 = v;
    return 1;
}


// 0x0013ed00 FUN_0013ed00 (12 B): matches/0x0013ed00.cpp
// sym: ?FUN_0013ed00@Obj_13ed00@owners@@QAE_NH@Z
bool owners::Obj_13ed00::FUN_0013ed00(int v) {
    mVal = v;
    return true;
}


// 0x0013ed20 FUN_0013ed20 (12 B): matches/0x0013ed20.cpp
// sym: ?FUN_0013ed20@Obj_13ed20@owners@@QAE_NH@Z
bool owners::Obj_13ed20::FUN_0013ed20(int x) {
    m1c = x;
    return true;
}


// 0x0013ed40 FUN_0013ed40 (18 B): matches/0x0013ed40.cpp
// sym: ?FUN_0013ed40@Obj_13ed40@owners@@QAE_NM@Z
bool owners::Obj_13ed40::FUN_0013ed40(float angle) {
    mAngle = angle * 0.0174532925f;
    return true;
}


// 0x0013ed70 FUN_0013ed70 (18 B): matches/0x0013ed70.cpp
// sym: ?FUN_0013ed70@Obj_13ed70@owners@@QAEDM@Z
char owners::Obj_13ed70::FUN_0013ed70(float v) {
    *(float*)((char*)this + 0x24) = v * RADIAN_FACTOR;
    return 1;
}


// 0x0013eda0 FUN_0013eda0 (18 B): matches/0x0013eda0.cpp
// sym: ?FUN_0013eda0@X_13eda0@owners@@QAEDM@Z
char owners::X_13eda0::FUN_0013eda0(float x) {
    angle = x * 0.017453292f;
    return 1;
}


// 0x0013edd0 FUN_0013edd0 (12 B): matches/0x0013edd0.cpp
// sym: ?FUN_0013edd0@X_13edd0@owners@@QAE_NH@Z
bool owners::X_13edd0::FUN_0013edd0(int v) {
    mValue = v;
    return true;
}


// 0x0013edf0 FUN_0013edf0 (12 B): matches/0x0013edf0.cpp
// sym: ?FUN_0013edf0@O_13edf0@owners@@QAE_NH@Z
bool owners::O_13edf0::FUN_0013edf0(int x) {
    m30 = x;
    return true;
}


// 0x0013ee10 FUN_0013ee10 (12 B): matches/0x0013ee10.cpp
// sym: ?FUN_0013ee10@Obj_13ee10@owners@@QAEDH@Z
char owners::Obj_13ee10::FUN_0013ee10(int v) {
    m = v;
    return 1;
}

namespace fn_f8068520 {

// 0x0013ee20 FUN_0013ee20 (19 B): matches/0x0013ee20.cpp
// sym: ?FUN_0013ee20@fn_f8068520@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013ee20() {
    FUN_00234810(((char*)&DAT_004e0f40), ((char*)&DAT_004e0f44));
}

} // namespace fn_f8068520

// 0x0013ee40 hulkfight::motion::WallVelocityCondition::vfunc_0 (16 B): matches/0x0013ee40.cpp
// sym: ?vfunc_0@WallVelocityCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::WallVelocityCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0f40;
    return p[index];
}

namespace fn_f8068520 {

// 0x0013ee90 FUN_0013ee90 (19 B): matches/0x0013ee90.cpp
// sym: ?FUN_0013ee90@fn_f8068520@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013ee90() {
    FUN_00234810(((char*)&DAT_004e0f48), ((char*)&DAT_004e0f4c));
}

} // namespace fn_f8068520

// 0x0013eeb0 hulkfight::motion::WallRunTrack::vfunc_0 (16 B): matches/0x0013eeb0.cpp
// sym: ?vfunc_0@WallRunTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::WallRunTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f48;
    return p[index];
}


// 0x0013eec0 FUN_0013eec0 (131 B): equivalent/0x0013eec0.cpp [wrapped: conflict: hulkfight::motion::WallRunTrack]
// sym: ?FUN_0013eec0@WallRunTrack@motion@hulkfight@fn_0013eec0@@QAEPAV1234@XZ @8bbdedd4881c @w2424952ca33a
namespace fn_0013eec0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0013eec0 @ 0x0013eec0


struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_13eec0 {
    int lo, hi;
    void FUN_0027af00();
};

namespace hulkfight {
namespace motion {
class WallRunTrack {
public:
    virtual hulk_intptr vfunc_0_0013eeb0(int);
    int f04;
    int f08;
    int f0c;
    float f10, f14, f18, f1c, f20;
    char b24;
    char pad25[3];
    float f28, f2c, f30, f34;
    Name8_13eec0 n38, n40, n48;
    int f50;
    float f54, f58;

    WallRunTrack() {}
    WallRunTrack *FUN_0013eec0();
};
}
}

hulkfight::motion::WallRunTrack *hulkfight::motion::WallRunTrack::FUN_0013eec0()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) WallRunTrack;
    f0c = 0;
    f10 = -1.0f;
    f14 = 10.0f;
    f18 = 1.0f;
    f1c = 1.0f;
    f20 = 100.0f;
    b24 = 0;
    f28 = 20.0f;
    f2c = 5.0f;
    f30 = 1.5707964f;
    f34 = 0.7853982f;
    n38.FUN_0027af00();
    n40.FUN_0027af00();
    n48.FUN_0027af00();
    f54 = 0.1f;
    f58 = 0.1f;
    f50 = 0;
    return this;
}
} // namespace fn_0013eec0


// 0x0013ef50 hulkfight::motion::WallRunTrack::vfunc_6 (4 B): matches/0x0013ef50.cpp
// sym: ?vfunc_6@WallRunTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::WallRunTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0013ef60 hulkfight::motion::WallRunTrack::vfunc_7 (7 B): matches/0x0013ef60.cpp
// sym: ?vfunc_7@WallRunTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::WallRunTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f8068520 {

// 0x0013ef70 FUN_0013ef70 (41 B): matches/0x0013ef70.cpp
// sym: ?Kill@WallRunTrack@fn_f8068520@@QAEXXZ
void WallRunTrack::Kill() {
    *(void**)this = (void*)((hulk_intptr)DAT_00412ad0);
    c.Dtor_0027af50();
    b.Dtor_0027af50();
    a.Dtor_0027af50();
    this->Base::~Base();
}


// 0x0013efa0 FUN_0013efa0 (19 B): matches/0x0013efa0.cpp
// sym: ?FUN_0013efa0@fn_f8068520@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013efa0() {
    FUN_00234810(((char*)&DAT_004e0f50), ((char*)&DAT_004e0f54));
}

} // namespace fn_f8068520

// 0x0013efc0 hulkfight::motion::WallJumpTrack::vfunc_0 (16 B): matches/0x0013efc0.cpp
// sym: ?vfunc_0@WallJumpTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::WallJumpTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f50;
    return p[index];
}


// 0x0013efd0 FUN_0013efd0 (103 B): matches/0x0013efd0.cpp [wrapped: conflict: hulkfight::motion::WallJumpTrack]
// sym: ??0WallJumpTrack@motion@hulkfight@fn_0013efd0@@QAE@XZ
namespace fn_0013efd0 {
// FUN_0013efd0 @ 0x0013efd0
class __declspec(novtable) Track_13efd0 {
public:
    virtual hulk_intptr b0_0013efc0(int);
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_13efd0() { FUN_00236d40(); }
};

namespace hulkfight {
namespace motion {
class WallJumpTrack : public Track_13efd0 {
public:
    virtual bool vfunc_0_00234270(void*);
    virtual bool v1_002342b0(int);
    virtual bool v2_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool v3_00234350(int, int);
    virtual void* v4_0013f790(char);
    virtual void v5_0013f040();
    virtual void vfunc_6_0013f050();
    virtual void* vfunc_7_00236ba0(void*, void*);

    int f0c;
    float f10;
    int f14, f18, f1c, f20, f24;
    float f28, f2c, f30, f34;
    char f38;
    char pad39[3];
    int f3c;
    float f40;
    int f44;
    int f48;
    int f4c, f50;

    WallJumpTrack();
};
}
}

hulkfight::motion::WallJumpTrack::WallJumpTrack() {
    f0c = 0; f14 = 0; f18 = 0; f1c = 0; f20 = 0; f24 = 0; f3c = 0; f44 = 0; f4c = 0; f50 = 0;
    f10 = -1.0f;
    f28 = 0.7853982f;
    f2c = 0.5235987901687622f;
    f30 = 0.2617993950843811f;
    f34 = 7.0f;
    f38 = 1;
    f40 = 1.5707964f;
    f48 = -5;
}
} // namespace fn_0013efd0


// 0x0013f040 hulkfight::motion::WallJumpTrack::vfunc_6 (4 B): matches/0x0013f040.cpp
// sym: ?vfunc_6@WallJumpTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::WallJumpTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0013f050 hulkfight::motion::WallJumpTrack::vfunc_7 (7 B): matches/0x0013f050.cpp
// sym: ?vfunc_7@WallJumpTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::WallJumpTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f8068520 {

// 0x0013f070 FUN_0013f070 (19 B): matches/0x0013f070.cpp
// sym: ?FUN_0013f070@fn_f8068520@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013f070() {
    FUN_00234810(((char*)&DAT_004e0f58), ((char*)&DAT_004e0f5c));
}

} // namespace fn_f8068520

// 0x0013f090 hulkfight::motion::WallExitTrack::vfunc_0 (16 B): matches/0x0013f090.cpp
// sym: ?vfunc_0@WallExitTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::WallExitTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f58;
    return p[index];
}

namespace fn_f8068520 {

// 0x0013f0a0 FUN_0013f0a0 (73 B): matches/0x0013f0a0.cpp
// sym: ??0WallExitTrack@fn_f8068520@@QAE@XZ
WallExitTrack::WallExitTrack()
    : a(0), b(-1.0f), c(0), d(0), e(20.0f), f(0), g(0.785398185f), h(0.52359879f), i(-5), j(0), k(0) {}

} // namespace fn_f8068520

// 0x0013f0f0 hulkfight::motion::WallExitTrack::vfunc_6 (4 B): matches/0x0013f0f0.cpp
// sym: ?vfunc_6@WallExitTrack@motion@hulkfight@@UAEMXZ
hulk_freg hulkfight::motion::WallExitTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0013f100 hulkfight::motion::WallExitTrack::vfunc_7 (7 B): matches/0x0013f100.cpp
// sym: ?vfunc_7@WallExitTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::WallExitTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f8068520 {

// 0x0013f190 hulkfight::motion::WallRunAction::vfunc_4 (54 B): matches/0x0013f190.cpp
// sym: ?vfunc_4@WallRunAction@fn_f8068520@@QAEXXZ
void WallRunAction::vfunc_4() {
    Proxy* p = ((Owner_13f190 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->second_00059a40();
    if (p) {
        p->apply_00222970(value28, 0);
        p->apply_00222970(value24, 0);
    }
}

} // namespace fn_f8068520

// 0x0013f1d0 hulkfight::motion::WallExitAction::vfunc_3 (1074 B): equivalent/0x0013f1d0.cpp [wrapped: conflict: hulkfight::motion::WallExitAction]
// sym: ?vfunc_3@WallExitAction@motion@hulkfight@fn_0013f1d0@@UAE_NHH@Z @f68910895ba0 @w54684ffa0d53
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0013f1d0 {
// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 18/18)
// hulkfight::motion::WallExitAction::vfunc_3 @ 0x0013f1d0
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif

extern "C++" __declspec(nothrow) void *__cdecl FUN_00263ea0(unsigned int size) throw();

union Bits_13f1d0 {
    float f;
    unsigned int u;
};

struct V3_13f1d0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(V3_13f1d0 *other, float eps);
    void Scale(float s) { x = s * x; y = s * y; z = s * z; }
    void Add(const V3_13f1d0 &o) { x = o.x + x; y = o.y + y; z = o.z + z; }
};

struct Name_13f1d0 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(V3_13f1d0 *axis, float angle);
    void FUN_0022c3b0(V3_13f1d0 *in, V3_13f1d0 *out);
};

class JointDriver_13f1d0 {
public:
    virtual void AddRef();
    char pad4[4];
    Name_13f1d0 name;
    JointDriver_13f1d0 *FUN_002248f0(int a);
};

struct Tracker_13f1d0 {
    void FUN_00222890(JointDriver_13f1d0 *d, float a, float b, float c, float e, float f, float g);
};

struct Fighter_13f1d0 {
    struct Stats_13f1d0 *FUN_00059a30();
    void FUN_00059a50(V3_13f1d0 *out);
    Tracker_13f1d0 *FUN_00059a40();
};

struct Holder_13f1d0 {
    Fighter_13f1d0 *FUN_000592a0();
};

struct Node34 {
    char pad0[0x34];
    float f34;
};

struct Stats_13f1d0 {
    char pad0[0x11c];
    Node34 *f11c;               // 0x11c
    char pad120[0x1ad4 - 0x120];
    V3_13f1d0 va;                      // 0x1ad4
    V3_13f1d0 vb;                      // 0x1ae0
    V3_13f1d0 vc;                      // 0x1aec
    V3_13f1d0 vd;                      // 0x1af8
    char FUN_00035550(V3_13f1d0 *out);
    void FUN_000356c0(V3_13f1d0 *out);
};

struct Config_13f1d0 {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    char pad28[4];
    Bits_13f1d0 f2c;
    Bits_13f1d0 f30;
    Bits_13f1d0 f34;
};

struct Sys8 {
    void FUN_00099d20(struct World *sys, Stats_13f1d0 *st, float a, unsigned int b, float c);
};

struct World {
    char pad0[8];
    Sys8 *f8;
};

namespace hulkfight {
namespace motion {

class WallExitAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_13f1d0 *cfg;                // 0x1c
    Holder_13f1d0 *holder;             // 0x20
    JointDriver_13f1d0 *driver;          // 0x24
    V3_13f1d0 v28;                     // 0x28
    V3_13f1d0 v34;                     // 0x34
    V3_13f1d0 v40;                     // 0x40
};

bool WallExitAction::vfunc_3(int a, int b)
{
    struct Frame {
        Bits_13f1d0 s10;
        Bits_13f1d0 s14;
        Bits_13f1d0 s18;
        V3_13f1d0 u;
        V3_13f1d0 t;
        V3_13f1d0 z;
        V3_13f1d0 w;
        Matrix m;
    } fr;

    Fighter_13f1d0 *fighter = holder->FUN_000592a0();
    Stats_13f1d0 *st = fighter->FUN_00059a30();
    v34 = st->vd;
    v28 = st->vc;
    fr.z.x = 0.0f;
    fr.z.y = 0.0f;
    fr.z.z = 0.0f;
    if (v34.FUN_0022d2b0(&fr.z, 0.00001f)) {
        v34 = st->vb;
        v28 = st->va;
        fr.z.x = 0.0f;
        fr.z.y = 0.0f;
        fr.z.z = 0.0f;
        if (v34.FUN_0022d2b0(&fr.z, 0.00001f)) {
            fr.t.x = 0.0f;
            fr.t.y = 0.0f;
            fr.t.z = -1.0f;
            st->FUN_00035550(&fr.t);
            v34 = fr.t;
            v34.x = -v34.x;
            v34.z = -v34.z;
            fr.s10.f = st->f11c->f34;
            fr.z.x = 0.0f;
            fr.z.y = 0.0f;
            fr.z.z = 0.0f;
            fighter->FUN_00059a50(&fr.z);
            v28 = fr.t;
            v28.Scale(fr.s10.f);
            v28.Add(fr.z);
        }
    }

    fr.u.x = 0.0f;
    fr.u.y = 0.0f;
    fr.u.z = 0.0f;
    st->FUN_000356c0(&fr.u);
    double dot = fr.u.z * v34.z + fr.u.y * v34.y + fr.u.x * v34.x;
    if (dot < 0.0) {
        double nd = -dot;
        fr.t = v34;
        fr.t.y = fr.t.y * nd;
        fr.t.z = fr.t.z * nd;
        fr.u.x = fr.u.x + fr.t.x * nd;
        fr.u.y = fr.t.y + fr.u.y;
        fr.u.z = fr.t.z + fr.u.z;
    }
    fr.s10.f = fr.u.FUN_0022d110();
    v34.y = 0.0f;
    v34.FUN_0022d110();
    fr.w.x = 1.0f * v34.z - 0.0f * v34.y;
    fr.w.y = 0.0f * v34.x - 0.0f * v34.z;
    fr.w.z = 0.0f * v34.y - 1.0f * v34.x;
    double c = fr.u.y;
    if (fr.u.y < 0.0f)
        c = 0.0f;
    fr.s14.f = (cfg->f24 - cfg->f20) * c + cfg->f20;
    fr.m.FUN_0022b980();
    fr.m.FUN_0022baf0(&fr.w, fr.s14.f);
    fr.m.FUN_0022c3b0(&fr.u, &v40);

    Config_13f1d0 *cf = cfg;
    if (fr.s10.f < cf->f14)
        fr.s10.f = cf->f14;
    if (cf->f18 > 0.0f && fr.s10.f > cf->f18)
        fr.s10.f = cf->f18;
    v40.x = fr.s10.f * v40.x;
    v40.y = fr.s10.f * v40.y;
    v40.z = fr.s10.f * v40.z;

    Tracker_13f1d0 *tr = fighter->FUN_00059a40();
    if (tr == 0)
        return false;
    fr.s18 = cfg->f2c;
    fr.s10 = cfg->f30;
    fr.s14 = cfg->f34;
    void *mem = FUN_00263ea0(0x70);
    JointDriver_13f1d0 *d;
    if (mem != 0)
        d = ((JointDriver_13f1d0 *)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    d->name.FUN_0027b040("wallExit");
    driver->AddRef();
    tr->FUN_00222890(driver, -1.0f, fr.s18.f, 1.0f, fr.s10.f, fr.s14.f, -1.0f);

    Bits_13f1d0 yb;
    yb.f = v40.y;
    double sq = v40.x * v40.x + v40.z * v40.z;
    DAT_004dd700->f8->FUN_00099d20(DAT_004dd700, st, sqrt(sq), yb.u, cfg->f1c);
    return true;
}

}
}
} // namespace fn_0013f1d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0013f610 hulkfight::motion::WallExitAction::vfunc_4 (37 B): matches/0x0013f610.cpp
// sym: ?vfunc_4@WallExitAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::WallExitAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_13f610*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}


// 0x0013f640 hulkfight::motion::WallJumpAction::vfunc_4 (37 B): matches/0x0013f640.cpp
// sym: ?vfunc_4@WallJumpAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::WallJumpAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_13f640*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}

namespace fn_f8068520 {

// 0x0013f720 hulkfight::motion::WallVelocityCondition::vfunc_5 (36 B): matches/0x0013f720.cpp
// sym: ?vfunc_5@WallVelocityCondition_13f720@fn_f8068520@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
WallVelocityCondition_13f720* WallVelocityCondition_13f720::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00412ab0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f8068520

// 0x0013f750 hulkfight::motion::WallRunTrack::vfunc_5 (62 B): matches/0x0013f750.cpp [wrapped: conflict: hulkfight::motion::WallRunTrack]
// sym: ?vfunc_5@WallRunTrack@motion@hulkfight@fn_0013f750@@UAEPAV1234@E@Z
namespace fn_0013f750 {
typedef unsigned char byte_13f750;
extern int hulk_at_00412ad0;
class Helper_13f750 {
  public:
    void clean_0027af50();
};
class Base_13f750 {
  public:
    void init_00236d60();
};
void thunk_0008d330(void*);
namespace hulkfight {
namespace motion {
class WallRunTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual WallRunTrack* vfunc_5(byte_13f750);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x38];
};
WallRunTrack* WallRunTrack::vfunc_5(byte_13f750 param) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_00412ad0;
    ((Helper_13f750*)((char*)this + 0x48))->clean_0027af50();
    ((Helper_13f750*)((char*)this + 0x40))->clean_0027af50();
    ((Helper_13f750*)((char*)this + 0x38))->clean_0027af50();
    ((Base_13f750*)this)->init_00236d60();
    if (param & 1)
        thunk_0008d330(this);
    return this;
}
} // namespace motion
} // namespace hulkfight
} // namespace fn_0013f750

namespace fn_f8068520 {

// 0x0013f790 hulkfight::motion::WallJumpTrack::vfunc_5 (36 B): matches/0x0013f790.cpp
// sym: ?vfunc_5@WallJumpTrack_13f790@fn_f8068520@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
WallJumpTrack_13f790* WallJumpTrack_13f790::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00412b00;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0013f7c0 hulkfight::motion::WallExitTrack::vfunc_5 (36 B): matches/0x0013f7c0.cpp
// sym: ?vfunc_5@WallExitTrack_13f7c0@fn_f8068520@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
WallExitTrack_13f7c0* WallExitTrack_13f7c0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00412b30;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f8068520

// 0x0013f7f0 hulkfight::motion::WallVelocityCondition::vfunc_6 (425 B): equivalent/0x0013f7f0.cpp [wrapped: conflict: CFightParams; fight::Params; hulkfight::motion::WallVelocityCondition]
// sym: ?vfunc_6@WallVelocityCondition@motion@hulkfight@fn_0013f7f0@@UAEDHPAVParams@fight@4@H@Z @48b79c8c0812 @w8b835b0bdfb3
namespace fn_0013f7f0 {
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 17/18, incomplete)
// hulkfight::motion::WallVelocityCondition::vfunc_6 @ 0x0013f7f0
struct Vec3_13f7f0 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_13f7f0 *other, float epsilon);
};

namespace fight {
class Params {
public:
    virtual void vfunc_0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void vfunc_0();
};

struct Stats_13f7f0 {
    char pad0[0x1ae0];
    Vec3_13f7f0 aimB;
    char pad1aec[0x1af8 - 0x1aec];
    Vec3_13f7f0 aimA;
    void FUN_000356c0(Vec3_13f7f0 *out);
};

void *__fastcall FUN_000592a0(void *owner);
Stats_13f7f0 *__fastcall FUN_00059a30(void *x);
extern "C" char FUN_00018960(float a, float b, float epsilon);

namespace hulkfight { namespace motion {

class WallVelocityCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a0, fight::Params *params, int a2);
    char pad04[8];
    unsigned int mode;
    float threshold;
};

char WallVelocityCondition::vfunc_6(int a0, fight::Params *params, int a2)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;

    Stats_13f7f0 *stats = FUN_00059a30(FUN_000592a0(params));

    Vec3_13f7f0 dir = stats->aimA;
    Vec3_13f7f0 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    if (dir.FUN_0022d2b0(&zero, 1e-5f))
        dir = stats->aimB;

    Vec3_13f7f0 vel;
    vel.x = 0.0f;
    vel.y = 0.0f;
    vel.z = 0.0f;
    stats->FUN_000356c0(&vel);

    float v = -(vel.z * dir.z + vel.y * dir.y + vel.x * dir.x);

    switch (mode) {
    case 0:
        return v < threshold;
    case 1:
        return v <= threshold;
    case 2:
        return FUN_00018960(v, threshold, 1e-5f);
    case 3:
        return !FUN_00018960(v, threshold, 1e-5f);
    case 4:
        return v >= threshold;
    case 5:
        return v > threshold;
    }
    return 0;
}

}}
} // namespace fn_0013f7f0

namespace fn_f8068520 {

// 0x0013f9c0 FUN_0013f9c0 (107 B): matches/0x0013f9c0.cpp
// sym: ??0WallRunAction@fn_f8068520@@QAE@HPAVRef_13f9c0@1@@Z
WallRunAction::WallRunAction(int a, Ref_13f9c0* p) {
    v = (hulk_intptr)&hulk_at_00412b60;
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = 0;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    m50 = 0;
    m54 = 0;
    m1c = a;
    if (p)
        p->First();
    if (m20)
        m20->Release();
    m20 = p;
}


// 0x0013fa30 FUN_0013fa30 (74 B): matches/0x0013fa30.cpp
// sym: ??1WallRunAction_13fa30@fn_f8068520@@QAE@XZ
WallRunAction_13fa30::~WallRunAction_13fa30() {
    vptr = g_vftable_13fa30;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_13fa30 *)this)->FUN_002326a0();
}

} // namespace fn_f8068520

// 0x0013fa80 hulkfight::motion::WallRunAction::vfunc_5 (1664 B): equivalent/0x0013fa80.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@WallRunAction@fn_0013fa80@@UAEDTArg1_13fa80@2@TArg2_13fa80@2@@Z @2224bb6695c4 @w0a7f0467902b
namespace fn_0013fa80 {
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 44/44; --wine 644 inputs)
// hulkfight::motion::WallRunAction::vfunc_5 @ 0x0013fa80


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double cos(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_13fa80 {
    float x, y, z;
    float FUN_0022d110() throw();
    char FUN_0022d2b0(const Vec3_13fa80 *z, float eps) throw();
    void FUN_000111b0(const Vec3_13fa80 *a, const Vec3_13fa80 *b) throw();
};

// |v| read back from memory (the original reloads the components it just stored, rounded)
static double Length_13fa80(const Vec3_13fa80 *v)
{
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

struct Quat_13fa80 {
    float q[4];
    void FUN_0022b4d0(Vec3_13fa80 *in, Vec3_13fa80 *out) throw();
};

struct Fighter_13fa80 {
    void FUN_00059a50(Vec3_13fa80 *out) throw();
};

struct Stats2_13fa80 {
    char pad0000[0x1ae0];
    Vec3_13fa80 v1ae0;
    char pad1aec[0x1af8 - 0x1aec];
    Vec3_13fa80 v1af8;
    char pad1b04[0x2008 - 0x1b04];
    float f2008;
    char pad200c[0x2064 - 0x200c];
    Vec3_13fa80 v2064;
};

struct Obj24_13fa80 {
    char pad000[0x8a0];
    float f8a0;
    float f8a4;
    char pad8a8[8];
    float f8b0;
};

struct Sub18_13fa80 {
    void FUN_00222180(Vec3_13fa80 *p) throw();
};

struct Obj28_13fa80 {
    char pad00[0x18];
    Sub18_13fa80 sub;
};

struct Cfg_13fa80 {
    char pad00[0x1c];
    float f1c;
    float f20;
    char pad24[4];
    float f28;
    float f2c;
    float f30;
    float f34;
};


Fighter_13fa80 *__fastcall FUN_000592a0(void *owner) throw();
Stats2_13fa80 *__fastcall FUN_00059a30(Fighter_13fa80 *f) throw();
float __cdecl FUN_00224fc0(float a, float b) throw();
float __cdecl FUN_00018a20(float x) throw();
extern "C" float __cdecl FUN_000186b0(float *v, float *lo, float *hi) throw();

union Arg1_13fa80 {
    int i;
    float f;
    unsigned int u;
};

union Arg2_13fa80 {
    float f;
    unsigned int u;
};

class WallRunAction {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual char vfunc_5(Arg1_13fa80 a1, Arg2_13fa80 a2);
    char pad04[0x18];
    Cfg_13fa80 *f1c;
    void *f20;
    Obj24_13fa80 *f24;
    Obj28_13fa80 *f28;
    Vec3_13fa80 v2c;
    Vec3_13fa80 v38;
    Vec3_13fa80 v44;
    char b50;
    char pad51[3];
    float f54;
};

char WallRunAction::vfunc_5(Arg1_13fa80 a1, Arg2_13fa80 a2)
{
    struct Frame {
        float s0;
        Vec3_13fa80 U;
        Vec3_13fa80 W;
        Vec3_13fa80 X;
        Vec3_13fa80 Y2;
        Vec3_13fa80 V;
        Vec3_13fa80 P;
        Vec3_13fa80 Y;
        Quat_13fa80 M;
    } f;

    if (a1.i != 0)
        return 1;
    if (f24 == 0 || f28 == 0)
        return 0;
    Fighter_13fa80 *fighter = FUN_000592a0(f20);
    Stats2_13fa80 *stats = FUN_00059a30(fighter);
    f.P.x = 0.0f;
    f.P.y = 0.0f;
    f.P.z = 0.0f;
    fighter->FUN_00059a50(&f.P);
    f.U = stats->v1af8;
    bool ok = true;
    f.V.x = 0.0f;
    f.V.y = 0.0f;
    f.V.z = 0.0f;
    if (f.U.FUN_0022d2b0(&f.V, 1e-05f)) {
        f.U = stats->v1ae0;
        f.V.x = 0.0f;
        f.V.y = 0.0f;
        f.V.z = 0.0f;
        if (f.U.FUN_0022d2b0(&f.V, 1e-05f))
            ok = false;
    }
    a1.f = f.U.y;
    a1.u &= 0x7fffffff;
    if (a1.f > 0.6f)
        ok = false;
    f.U.y = 0.0f;
    f.U.FUN_0022d110();
    if (!(DAT_004e0f7c & 1)) {
        DAT_004e0f7c |= 1;
        DAT_004e0f78 = (float)cos(0.017453293005625408);
    }
    f.V.x = v2c.x;
    f.V.z = v2c.z;
    f.V.y = 0.0f;
    f.V.FUN_0022d110();
    hulk_freg d1 = f.V.z * f.U.z + f.V.x * f.U.x + f.V.y * f.U.y;
    if (DAT_004e0f78 - 1.0f < d1) {
        if (f.U.z * v38.z + f.U.y * v38.y + f.U.x * v38.x < -0.707106769f) {
            ok = false;
        } else {
            double c = cos(f1c->f34);
            if (c > f.U.z * v44.z + f.U.y * v44.y + f.U.x * v44.x)
                ok = false;
        }
    } else {
        v38 = f.U;
    }
    v44 = f.U;
    ((owners::C_359c0 *)stats)->FUN_000359c0(4);
    if (b50 == 0) {
        float diff = FUN_00224fc0(stats->f2008, f54);
        a1.f = diff;
        a1.u &= 0x7fffffff;
        if (a1.f > 0.0872664675f)
            b50 = 1;
    }
    if (b50 != 0) {
        f.V = v2c;
        f.V.FUN_0022d110();
        hulk_freg dd = f.V.z * stats->v2064.z + f.V.y * stats->v2064.y + f.V.x * stats->v2064.x;
        a1.f = dd;
        if (dd < 1.0f) {
            f.Y.FUN_000111b0(&f.V, &stats->v2064);
            f.Y.FUN_0022d110();
            double ang = FUN_00018a20(a1.f);
            double maxStep = a2.f * f1c->f30;
            a1.f = (float)maxStep;
            if (maxStep > ang)
                a1.f = (float)ang;
            ((owners::Vec4_22b170 *)&(f.M))->FUN_0022b170(a1.f, (float *)(Vec3_13fa80 *)(&f.Y));
            f.M.FUN_0022b4d0(&v2c, &v2c);
        }
    }
    v2c.y = v2c.y - a2.f * f1c->f28;
    a1.f = (float)Length_13fa80(&v2c);
    double dot = f.U.z * v2c.z;      // one term per statement, in the listing's order
    dot += f.U.y * v2c.y;
    dot += f.U.x * v2c.x;
    double nd = -dot;
    v2c.x = f.U.x * nd + v2c.x;
    v2c.y = f.U.y * nd + v2c.y;
    v2c.z = f.U.z * nd + v2c.z;
    v2c.FUN_0022d110();
    v2c.x = a1.f * v2c.x;
    v2c.y = a1.f * v2c.y;
    v2c.z = a1.f * v2c.z;
    f.W = v2c;
    double len = f.W.FUN_0022d110();
    if (len <= 0.0f) {
        f.W.x = 0.0f;
        f.W.y = 1.0f;
        f.W.z = 0.0f;
    }
    double lo = f1c->f1c;
    a1.f = (float)(len - a2.f * f1c->f2c);
    if (f1c->f1c < 0.0f)
        lo = 0.0f;
    if (a1.f < lo)
        a1.f = (float)lo;
    f.s0 = f1c->f20;
    if (f1c->f20 > lo && a1.f > f.s0)
        a1.f = f.s0;
    v2c = f.W;
    v2c.x = a1.f * v2c.x;
    v2c.y = a1.f * v2c.y;
    v2c.z = a1.f * v2c.z;
    f.X = v2c;
    hulk_freg xs = f.X.x * a2.f;   // x and y stay in x87 registers, z is stored before the add
    hulk_freg ys = f.X.y * a2.f;
    volatile float zs = f.X.z * a2.f;   // stored before the add, under both compilers
    f.X.x = xs + f.P.x;
    f.X.y = ys + f.P.y;
    f.X.z = zs + f.P.z;
    ((owners::Target_22be40 *)&(f28->sub))->FUN_0022be40((const int *)(Vec3_13fa80 *)(&f.X));
    f.Y2.x = f.U.x * -1.0f;
    f.Y2.y = 0.0f;
    f.Y2.z = f.U.z * -1.0f;
    if (f.Y2.FUN_0022d110() > 0.0f)
        f28->sub.FUN_00222180(&f.Y2);
    f24->f8b0 = a1.f;
    f.P.x = f.W.y * 0.0f - f.W.z;
    a2.u = *(unsigned int *)&f.W.y;
    f.P.y = f.W.z * 0.0f - f.W.x * 0.0f;
    f.s0 = -0.9999f;
    a1.u = 0x3f7ff972;
    f.P.z = f.W.x - f.W.y * 0.0f;
    a2.f = FUN_000186b0(&a2.f, &f.s0, &a1.f);
    float angle = FUN_00018a20(a2.f);
    if (f.P.z * f.U.z + f.P.x * f.U.x + f.P.y * f.U.y < 0.0f)
        angle = -angle;
    f24->f8a0 = angle;
    f24->f8a4 = 1.0f;
    return ok;
}
} // namespace fn_0013fa80

namespace fn_f8068520 {

// 0x00140100 FUN_00140100 (102 B): matches/0x00140100.cpp
// sym: ??0WallExitAction@fn_f8068520@@QAE@HPAVRef_140100@1@@Z
WallExitAction::WallExitAction(int a, Ref_140100* b) {
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = -1.0f;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m1c = a;
    if (b)
        b->Add();
    if (m20)
        m20->Rel();
    m20 = b;
}


// 0x00140170 FUN_00140170 (69 B): matches/0x00140170.cpp
// sym: ??1WallExitAction_140170@fn_f8068520@@QAE@XZ
WallExitAction_140170::~WallExitAction_140170() {
    vptr = hulk_at_00412b80;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_140170 *)this)->FUN_002326a0();
}

} // namespace fn_f8068520

// 0x001401c0 hulkfight::motion::WallExitAction::vfunc_5 (962 B): equivalent/0x001401c0.cpp [wrapped: conflict: WallExitAction]
// sym: ?vfunc_5@WallExitAction@fn_001401c0@@UAE_NHM@Z @064d05d0afa4 @w14cc767b0467
namespace fn_001401c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 22/22)
// hulkfight::motion::WallExitAction::vfunc_5 @ 0x001401c0
struct Vec3_1401c0 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_1401c0* other, float eps);
    float FUN_0022d110();
};

union FloatBits_1401c0 {
    float f;
    unsigned int u;
};

float __cdecl FUN_00224f10(Vec3_1401c0* v);
float __cdecl FUN_00224fc0(float from, float to);
void __cdecl FUN_00224d70(float angle, Vec3_1401c0* v);

struct Xform_1401c0 {
    void FUN_00221d20(float v);
};

struct Target_1401c0 {
    char pad00[0x18];
    Xform_1401c0 xform;
};

struct Limits_1401c0 {
    char pad00[0x30];
    float halfHeight;
    float limit;
};

struct Fighter_1401c0 {
    char pad00[0x11c];
    Limits_1401c0* limits;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x1ad4 - 0x144];
    Vec3_1401c0 a;
    Vec3_1401c0 b;
    Vec3_1401c0 c;
    Vec3_1401c0 d;
    char pad1b04[0x2064 - 0x1b04];
    Vec3_1401c0 vel;
};

struct Anchor_1401c0 {
    Fighter_1401c0* FUN_00059a30();
    void FUN_00059a50(Vec3_1401c0* out);
};

struct Owner_1401c0 {
};

struct Params {
    char pad00[0x1c];
    float drag;
    char pad20[0x28 - 0x20];
    float rate;
};

class WallExitAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int skip, float dt);
    char pad04[0x1c - 4];
    Params* params;
    Owner_1401c0* owner;
    Target_1401c0* target;
    Vec3_1401c0 g;
    Vec3_1401c0 n;
    Vec3_1401c0 vel;
};

bool WallExitAction::vfunc_5(int skip, float dt)
{
    if (skip != 0) {
        return true;
    }
    if (target == 0) {
        return false;
    }
    Anchor_1401c0* anchor = ((Anchor_1401c0 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    Fighter_1401c0* fighter = anchor->FUN_00059a30();
    ((owners::C_359c0 *)fighter)->FUN_000359c0(3);

    hulk_freg s1 = FUN_00224f10(&vel);
    Vec3_1401c0 fv = fighter->vel;
    hulk_freg s2 = FUN_00224f10(&fv);
    hulk_freg held = s1;
    hulk_freg diff = FUN_00224fc0(s1, s2);
    hulk_freg v;
    if (!(diff < 2.3561945f)) {
        v = held;
    } else {
        held = params->rate;
        if (!(held < 0.0f)) {
            hulk_freg diff2 = FUN_00224fc0(s1, s2);
            hulk_freg step = held * dt;
            FloatBits_1401c0 ab;
            ab.f = diff2;
            ab.u &= 0x7fffffff;
            if (!(ab.f <= step)) {
                if (!(diff2 < 0.0f)) {
                    v = step + s1;
                } else {
                    v = s1 - step;
                }
            } else {
                v = s2;
            }
        } else {
            v = s2;
        }
    }
    FUN_00224d70(v - s1, &vel);

    vel.y = vel.y - dt * params->drag;
    Vec3_1401c0 push;
    push.x = vel.x * dt;
    push.y = vel.y * dt;
    push.z = vel.z * dt;

    Vec3_1401c0 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    anchor->FUN_00059a50(&pos);

    if (fighter->mode == 4) {
        Vec3_1401c0 f = fighter->d;
        Vec3_1401c0 gg = fighter->c;
        Vec3_1401c0 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        bool update = true;
        if (f.FUN_0022d2b0(&zero, 1e-05f)) {
            f = fighter->b;
            gg = fighter->a;
            zero.x = 0.0f;
            zero.y = 0.0f;
            zero.z = 0.0f;
            if (f.FUN_0022d2b0(&zero, 1e-05f)) {
                update = false;
            }
        }
        if (update) {
            f.y = 0.0f;
            f.FUN_0022d110();
            n = f;
            g = gg;
        }
    }

    push.x = pos.x + push.x;
    push.y = pos.y + push.y;
    push.z = pos.z + push.z;
    Limits_1401c0* lim = fighter->limits;
    if (lim->halfHeight * 0.5f > push.y - g.y) {
        hulk_freg t = n.z * g.z + n.y * g.y + n.x * g.x;
        hulk_freg depth = n.x * push.x + n.y * push.y + n.z * push.z - t;
        if (depth < lim->limit) {
            Vec3_1401c0 h;
            hulk_freg d = lim->limit - depth;
            h.x = n.x * d;
            h.y = n.y * d;
            h.z = n.z * d;
            ((owners::C_357a0 *)fighter)->FUN_000357a0((float *)(Vec3_1401c0 *)(&h));
        }
    }
    ((owners::Target_22be40 *)&(target->xform))->FUN_0022be40((const int *)(Vec3_1401c0 *)(&push));
    float arg1 = FUN_00224f10(&vel);
    target->xform.FUN_00221d20(arg1);
    return true;
}
} // namespace fn_001401c0

namespace fn_f8068520 {

// 0x00140590 FUN_00140590 (105 B): matches/0x00140590.cpp
// sym: ??0WallJumpAction_140590@fn_f8068520@@QAE@HPAVObj_140590@1@@Z
WallJumpAction_140590::WallJumpAction_140590(int p, Obj_140590* o) {
    int* q = &m1;
    *q = 0;
    m2 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = -1.0f;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    m1 = p;
    if (o)
        o->f();
    if (m2)
        m2->g();
    m2 = o;
}


// 0x00140600 FUN_00140600 (69 B): matches/0x00140600.cpp
// sym: ??1WallJumpAction_140600@fn_f8068520@@QAE@XZ
WallJumpAction_140600::~WallJumpAction_140600() {
    vptr = hulk_at_00412b9c;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_140600 *)this)->FUN_002326a0();
}

} // namespace fn_f8068520

// 0x00140650 hulkfight::motion::WallJumpAction::vfunc_3 (2539 B): equivalent/0x00140650.cpp [wrapped: conflict: FUN_000592a0; World]
// sym: ?vfunc_3@WallJumpAction@fn_00140650@@UAE_NHH@Z @8237446b06a5 @wf552bddd93a6
namespace fn_00140650 {
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 56/56)
// hulkfight::motion::WallJumpAction::vfunc_3 @ 0x00140650
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif


struct V3_140650 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    char FUN_0022d2b0(const V3_140650 *other, float eps);
};

struct Mat4_140650 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(V3_140650 *axis, float angle);
};

struct NameHolder_140650 {
    char pad[8];
};

class JointDriver {
public:
    virtual void AddRef();
    char pad04[4];
    NameHolder_140650 name;
    char pad10[0x70 - 0x10];
    JointDriver *FUN_002248f0(int a);
};

struct Rig_140650 {
    void FUN_00222890(JointDriver *d, float a, int b, float c, int e, int f, float g);
};

struct Gear_140650 {
    char pad00[0x34];
    float f34;
};

struct Pos_140650 {
    void FUN_00059a50(V3_140650 *out);
};

struct Stats_140650 {
    char pad00[0x10];
    Pos_140650 *f10;
    char pad14[0x11c - 0x14];
    Gear_140650 *f11c;
    char pad120[0x140 - 0x120];
    int f140;
    char pad144[0x1ad4 - 0x144];
    V3_140650 v1ad4;
    V3_140650 v1ae0;
    V3_140650 v1aec;
    V3_140650 v1af8;
    char pad1b04[0x2064 - 0x1b04];
    V3_140650 v2064;
    void FUN_00035550(V3_140650 *out);
    hulk_freg FUN_000354c0();
    char FUN_000356c0(V3_140650 *out);
};

struct Anchor_140650 {
    void FUN_00059a50(V3_140650 *out);
};
Anchor_140650 *__fastcall FUN_000592a0(void *owner);
Stats_140650 *__fastcall FUN_00059a30(Anchor_140650 *f);
extern "C" Rig_140650 *__fastcall FUN_00059a40(Anchor_140650 *f);

struct Fx34_140650 {
    void FUN_001ec980(Stats_140650 *st, const char *name);
};
struct World8 {
    void FUN_00099d20(struct World *w, Stats_140650 *st, float len, float y, int z);
};
struct World {
    char pad00[8];
    World8 *f8;
    char pad0c[0x34 - 0xc];
    Fx34_140650 *f34;
};

void *thunk_FUN_0008d690(unsigned int size);
hulk_freg __cdecl FUN_00018a20(float v);
void __cdecl FUN_00224d70(float angle, V3_140650 *axis);

struct Data_140650 {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    int f20;
    float f24;
    float f28;
    char pad2c[4];
    float f30;
    char pad34[4];
    char b38;
    char pad39[3];
    float f3c;
    float f40;
    float f44;
    int f48;
    int f4c;
    int f50;
};

struct Frame_140650 {
    V3_140650 t10;                 // 0x10
    float f1c;              // 0x1c
    V3_140650 w;                   // 0x20
    V3_140650 bq;                  // 0x2c
    float s38;              // 0x38
    V3_140650 av;                  // 0x3c
    V3_140650 rv;                  // 0x48
    V3_140650 pv;                  // 0x54
    float ang;              // 0x60
    float spd;              // 0x64
    Anchor_140650 *saved;          // 0x68
    V3_140650 qv;                  // 0x6c
    Mat4_140650 m;                 // 0x78
    V3_140650 out;                 // 0xb8
};

class WallJumpAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x1c - 4];
    Data_140650 *data;
    void *owner;
    JointDriver *driver;
    V3_140650 v28;
    V3_140650 dir;                 // 0x34
    char b40;
    char pad41[3];
    V3_140650 v44;
};

bool WallJumpAction::vfunc_3(int a, int b)
{
    Frame_140650 f;
    Anchor_140650 *fighter = FUN_000592a0(owner);
    f.saved = fighter;
    Stats_140650 *st = FUN_00059a30(fighter);
    bool cond = (st->f140 == 4);
    b40 = cond;
    if (cond) {
        dir = st->v1af8;
        v28 = st->v1aec;
        f.t10.x = 0;
        f.t10.y = 0;
        f.t10.z = 0;
        if (dir.FUN_0022d2b0(&f.t10, 1e-05f)) {
            dir = st->v1ae0;
            v28 = st->v1ad4;
            f.t10.x = 0;
            f.t10.y = 0;
            f.t10.z = 0;
            if (dir.FUN_0022d2b0(&f.t10, 1e-05f)) {
                f.t10.x = 0;
                f.t10.y = 0;
                f.t10.z = -1.0f;
                st->FUN_00035550(&f.t10);
                dir = f.t10;
                dir.x = -dir.x;
                dir.z = -dir.z;
                f.f1c = st->f11c->f34;
                f.bq.x = 0;
                f.bq.y = 0;
                f.bq.z = 0;
                fighter->FUN_00059a50(&f.bq);
                v28 = f.t10;
                v28.x = f.f1c * v28.x;
                v28.y = f.f1c * v28.y;
                v28.z = f.f1c * v28.z;
                v28.x = f.bq.x + v28.x;
                v28.y = f.bq.y + v28.y;
                v28.z = f.bq.z + v28.z;
            }
        }
        dir.y = 0;
        dir.FUN_0022d110();
    } else {
        dir.x = (*(float*)&DAT_004ad77c);
        dir.y = (*(float*)((char*)&DAT_004ad77c + 4));
        dir.z = (*(float*)((char*)&DAT_004ad77c + 8));
        FUN_00224d70(st->FUN_000354c0() + 3.14159274f, &dir);
    }

    f.s38 = 0;
    if (data->b38) {
        if (!st->FUN_000356c0(&f.w))
            return false;
        float dot = f.w.y * dir.y + f.w.z * dir.z + f.w.x * dir.x;
        f.bq = dir;
        f.t10.x = 0;
        f.t10.y = 0;
        f.t10.z = -1.0f;
        dot = -dot;
        f.bq.y = f.bq.y * dot;
        f.bq.z = f.bq.z * dot;
        f.w.x = f.bq.x * dot + f.w.x;
        f.w.y = f.bq.y + f.w.y;
        f.w.z = f.bq.z + f.w.z;
        st->FUN_00035550(&f.t10);
        f.t10.y = 0;
        f.t10.FUN_0022d110();
        float dot2 = f.t10.z * f.w.z + f.w.y * f.t10.y + f.t10.x * f.w.x;
        dot2 = -dot2;
        f.bq.y = dot2 * f.t10.y;
        f.bq.z = f.t10.z * dot2;
        f.w.x = f.t10.x * dot2 + f.w.x;
        f.w.y = f.bq.y + f.w.y;
        f.w.z = f.bq.z + f.w.z;
        if (f.w.y < 0.0f) {
            if (b40)
                f.w.y = 0;
            else
                f.w = f.t10;
        }
        f.s38 = f.w.FUN_0022d110();
        if (f.s38 <= 0.0f) {
            f.w.x = 0;
            f.w.y = 1.0f;
            f.w.z = 0;
        }
    } else {
        f.t10.x = 0;
        f.t10.y = 1.0f;
        f.t10.z = 0;
        f.m.FUN_0022b980();
        f.m.FUN_0022baf0(&dir, data->f3c);
        ((owners::M_22c3b0 *)&(f.m))->FUN_0022c3b0((float *)(V3_140650 *)(&f.t10), (float *)(V3_140650 *)(&f.w));
    }
    f.rv = f.w;

    if (!data->b38) {
        f.f1c = data->f40 * 0.5f;
        f.m.FUN_0022b980();
        f.m.FUN_0022baf0(&dir, 1.57079637f - data->f44);
        f.qv.x = 0;
        f.qv.y = 1.0f;
        f.qv.z = 0;
        ((owners::M_22c3b0 *)&(f.m))->FUN_0022c3b0((float *)(V3_140650 *)(&f.qv), (float *)(V3_140650 *)(&f.av));
        f.m.FUN_0022baf0(&dir, -f.f1c);
        ((owners::M_22c3b0 *)&(f.m))->FUN_0022c3b0((float *)(V3_140650 *)(&f.w), (float *)(V3_140650 *)(&f.bq));
        if (f.bq.y < f.av.y) {
            if (f.bq.z * f.av.z + f.bq.x * f.av.x + f.av.y * f.bq.y > 0.0f) {
                f.bq = f.av;
            } else {
                f.bq.x = -f.av.x;
                f.bq.y = f.av.y;
                f.bq.z = -f.av.z;
            }
        }
        f.m.FUN_0022baf0(&dir, f.f1c);
        ((owners::M_22c3b0 *)&(f.m))->FUN_0022c3b0((float *)(V3_140650 *)(&f.w), (float *)(V3_140650 *)(&f.t10));
        if (f.t10.y < f.av.y) {
            if (f.t10.z * f.av.z + f.t10.x * f.av.x + f.t10.y * f.av.y > 0.0f) {
                f.t10 = f.av;
            } else {
                f.t10.x = -f.av.x;
                f.t10.y = f.av.y;
                f.t10.z = -f.av.z;
            }
        }
        f.pv = st->v2064;
        float dp = f.pv.z * dir.z + f.pv.y * dir.y + f.pv.x * dir.x;
        f.av = dir;
        dp = -dp;
        f.av.y = f.av.y * dp;
        f.av.z = f.av.z * dp;
        f.pv.x = f.av.x * dp + f.pv.x;
        f.pv.y = f.av.y + f.pv.y;
        f.pv.z = f.av.z + f.pv.z;
        f.pv.FUN_0022d110();
        if (FUN_00018a20(f.pv.y * f.w.y + f.pv.z * f.w.z + f.pv.x * f.w.x) < f.f1c) {
            f.rv = f.pv;
        } else {
            if ((f.pv.y * f.t10.y + f.pv.z * f.t10.z + f.pv.x * f.t10.x)
                < (f.pv.y * f.bq.y + f.pv.z * f.bq.z + f.pv.x * f.bq.x))
                f.rv = f.bq;
            else
                f.rv = f.t10;
        }
    }

    Data_140650 *d = data;
    if (FUN_00018a20(f.rv.y) < d->f30 * 0.5f) {
        f.rv.x = 0;
        f.rv.y = 1.0f;
        f.rv.z = 0;
    }
    f.qv.x = dir.z - dir.y * 0.0f;
    f.qv.y = dir.x * 0.0f - dir.z * 0.0f;
    f.qv.z = dir.y * 0.0f - dir.x;
    float t = (f.w.y < 0.0f) ? 0.0f : f.w.y;
    f.ang = d->f24 + (d->f28 - d->f24) * t;
    f.m.FUN_0022b980();
    f.m.FUN_0022baf0(&f.qv, f.ang);
    f.t10 = f.rv;
    ((owners::M_22c3b0 *)&(f.m))->FUN_0022c3b0((float *)(V3_140650 *)(&f.t10), (float *)(V3_140650 *)(&f.rv));
    f.ang = ((owners::Progress_3ec00 *)st)->FUN_0003ec00(0);
    Data_140650 *d2 = data;
    float lo = d2->f14;
    if (lo < f.s38)
        lo = f.s38;
    float hi = d2->f18;
    if (hi < lo)
        hi = lo;
    f.s38 = lo + (hi - lo) * f.ang;
    if (f.rv.y < 0.0f) {
        if (f.rv.y > -1e-05f)
            f.rv.y = 0;
    }
    v44 = f.rv;
    v44.x = f.s38 * v44.x;
    v44.y = f.s38 * v44.y;
    v44.z = f.s38 * v44.z;

    f.f1c = data->f1c;
    if (f.f1c > 0.0f) {
        float vx = *(volatile float *)&v44.x;
        float vz = *(volatile float *)&v44.z;
        double sp = sqrt(vx * vx + vz * vz);
        f.spd = (float)sp;
        if (sp > f.f1c) {
            v44.y = (float)(sin(FUN_00018a20(f.f1c / f.s38)) * f.s38);
            v44.x = (f.f1c / f.spd) * v44.x;
            v44.z = (f.f1c / f.spd) * v44.z;
        }
    }

    Rig_140650 *rig = FUN_00059a40(f.saved);
    if (!rig)
        return false;
    Data_140650 *dd = data;
    int e4c = dd->f4c;
    int e50 = dd->f50;
    int e48 = dd->f48;
    void *mem = thunk_FUN_0008d690((int)sizeof(JointDriver));
    JointDriver *drv;
    if (mem)
        drv = ((JointDriver *)mem)->FUN_002248f0(0);
    else
        drv = 0;
    driver = drv;
    ((owners::Target_27b040 *)&(drv->name))->FUN_0027b040((hulk_uintptr)"wallJump");
    driver->AddRef();
    rig->FUN_00222890(driver, -1.0f, e48, 1.0f, e4c, e50, -1.0f);
    World *world = DAT_004dd700;
    float hx = *(volatile float *)&v44.x;
    float hz = *(volatile float *)&v44.z;
    float hl = (float)sqrt(hx * hx + hz * hz);
    world->f8->FUN_00099d20(world, st, hl, v44.y, data->f20);
    st->f10->FUN_00059a50(&f.out);
    if (f.ang >= 1.0f) {
        if (f.out.y > 100.0f)
            world->f34->FUN_001ec980(st, "StartChargedJump");
    }
    return true;
}
} // namespace fn_00140650
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00141040 hulkfight::motion::WallJumpAction::vfunc_5 (1276 B): equivalent/0x00141040.cpp [wrapped: conflict: WallJumpAction]
// sym: ?vfunc_5@WallJumpAction@fn_00141040@@UAE_NTSlot_141040@2@0@Z @bbaef637bbdd @w53a0717c489a
namespace fn_00141040 {
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 25/26, incomplete)
// hulkfight::motion::WallJumpAction::vfunc_5 @ 0x00141040


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_141040 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(V3_141040 *other, float limit);
};

struct Plane_141040 {
    float x, y, z, w;
    void FUN_00037680(const V3_141040 *n, const V3_141040 *p);
};

struct Mat4_141040 {
    float m[16];
    void FUN_00221d20(float angle);
};

struct Sub11c_141040 {
    char pad0[0x30];
    float f30;
    float f34;
};

struct Stats_141040 {
    char pad0[0x11c];
    Sub11c_141040 *f11c;
    char pad120[0x140 - 0x120];
    int f140;
    char pad144[0x1ad4 - 0x144];
    V3_141040 v1ad4;
    V3_141040 v1ae0;
    V3_141040 v1aec;
    V3_141040 v1af8;
    char pad1b04[0x2064 - 0x1b04];
    V3_141040 v2064;
};

struct Clock_141040 {
    Stats_141040 *FUN_00059a30();
    char FUN_00059a50(V3_141040 *out);
};

struct OwnerObj_141040 {
};

struct Driver {
    char pad0[0x18];
    Mat4_141040 xform;
};

struct Cfg_141040 {
    char pad0[0x20];
    float f20;
    char pad24[0x2c - 0x24];
    float f2c;
    char pad30[0x34 - 0x30];
    float f34;
};

double __cdecl FUN_00224f10(V3_141040 *v);
double __cdecl FUN_00224fc0(int a, int b);
void __cdecl FUN_00224d70(int angle, V3_141040 *v);

union Slot_141040 {
    int i;
    float f;
    unsigned int u;
};

union Bits_141040 {
    float f;
    unsigned int u;
    int i;
};

class WallJumpAction {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vfunc_5(Slot_141040 a1, Slot_141040 a2);
    char pad04[0x1c - 4];
    Cfg_141040 *cfg;
    OwnerObj_141040 *owner;
    Driver *target;
    V3_141040 contactPos;
    V3_141040 contactNormal;
    char hasContact;
    char pad41[3];
    V3_141040 vel2;
};

bool WallJumpAction::vfunc_5(Slot_141040 a1, Slot_141040 a2)
{
    struct Frame {
        float s0;
        float s4;
        float s8;
        float sC;
        Clock_141040 *clk;
        V3_141040 v0;
        V3_141040 d;
        V3_141040 a;
        V3_141040 b;
        V3_141040 vc;
        V3_141040 p;
        V3_141040 vcopy;
        Plane_141040 q;
    } f;

    if (a1.i != 0)
        return true;
    if (target == 0)
        return false;

    f.clk = ((Clock_141040 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    Stats_141040 *st = f.clk->FUN_00059a30();
    ((owners::C_359c0 *)st)->FUN_000359c0(3);
    f.s0 = (float)FUN_00224f10(&vel2);
    f.vcopy = st->v2064;
    f.s4 = (float)FUN_00224f10(&f.vcopy);
    f.sC = f.s0;
    double diffA = FUN_00224fc0(*(int *)&f.s0, *(int *)&f.s4);

    double v;
    if (!(diffA < 2.3561944961547852)) {
        v = f.sC;
    } else {
        f.sC = cfg->f2c;
        if (f.sC < 0.0f) {
            v = f.s4;
        } else {
            double diff3 = FUN_00224fc0(*(int *)&f.s0, *(int *)&f.s4);
            double stepd = (double)f.sC * a2.f;
            f.sC = (float)stepd;
            f.s8 = (float)diff3;
            Bits_141040 ab;
            ab.f = f.s8;
            ab.u &= 0x7fffffff;
            f.s8 = ab.f;
            if (f.s8 <= f.sC)
                v = f.s4;
            else if (diff3 < 0.0)
                v = (double)f.s0 - f.sC;
            else
                v = (double)f.sC + f.s0;
        }
    }
    float wf = (float)(v - f.s0);
    FUN_00224d70(*(int *)&wf, &vel2);

    Cfg_141040 *c2 = cfg;
    vel2.y = (float)((double)vel2.y - a2.f * c2->f20);
    *(int *)&f.s8 = *(int *)&c2->f34;
    f.sC = (float)FUN_00224f10(&vel2);
    f.v0 = (*(V3_141040*)&DAT_004ad77c);
    FUN_00224d70(*(int *)&f.sC, &f.v0);
    f.vc = st->v2064;
    f.vc.y = 0.0f;
    f.vc.FUN_0022d110();
    double t = (f.v0.z * f.vc.z + f.v0.x * f.vc.x + f.v0.y * f.vc.y) * f.s8;
    double h = sqrt(vel2.x * vel2.x + vel2.z * vel2.z);
    f.sC = (float)(-h);
    double tt = t;
    if (t < f.sC)
        tt = f.sC;
    double u = tt * a2.f;
    f.v0.x = (float)(f.v0.x * u);
    f.v0.y = (float)(f.v0.y * u);
    f.v0.z = (float)(f.v0.z * u);
    ((owners::C_357a0 *)st)->FUN_000357a0((float *)(V3_141040 *)(&f.v0));

    V3_141040 tv = vel2;
    f.p.x = 0.0f;
    f.d.x = tv.x * a2.f;
    f.d.y = tv.y * a2.f;
    f.p.y = 0.0f;
    f.p.z = 0.0f;
    f.d.z = tv.z * a2.f;
    f.clk->FUN_00059a50(&f.p);
    f.d.x = f.p.x + f.d.x;
    f.d.y = f.p.y + f.d.y;
    f.d.z = f.d.z + f.p.z;

    if (st->f140 == 4) {
        f.a = st->v1af8;
        f.b = st->v1aec;
        V3_141040 *z = (V3_141040 *)&f.q;
        z->x = 0.0f;
        z->y = 0.0f;
        z->z = 0.0f;
        bool take = true;
        if (!f.a.FUN_0022d2b0(z, 1e-5f)) {
        } else {
            f.a = st->v1ae0;
            f.b = st->v1ad4;
            z->x = 0.0f;
            z->y = 0.0f;
            z->z = 0.0f;
            if (f.a.FUN_0022d2b0(z, 1e-5f))
                take = false;
        }
        if (take) {
            f.a.y = 0.0f;
            f.a.FUN_0022d110();
            contactNormal = f.a;
            contactPos = f.b;
            hasContact = 1;
        }
    }

    if (hasContact) {
        double dy = f.d.y - contactPos.y;
        if (dy < st->f11c->f30) {
            f.q.FUN_00037680(&contactNormal, &contactPos);
            double dist = f.q.z * f.d.z + f.q.x * f.d.x + f.q.y * f.d.y + f.q.w;
            float R = st->f11c->f34;
            if (dist < R) {
                double k = R - dist;
                V3_141040 n = contactNormal;
                f.a.x = (float)(n.x * k);
                f.a.y = (float)(n.y * k);
                f.a.z = (float)(n.z * k);
                ((owners::C_357a0 *)st)->FUN_000357a0((float *)(V3_141040 *)(&f.a));
            }
        }
    }

    ((owners::Target_22be40 *)&(target->xform))->FUN_0022be40((const int *)(const V3_141040 *)(&f.d));
    float len4 = (float)FUN_00224f10(&vel2);
    target->xform.FUN_00221d20(len4);
    return true;
}
} // namespace fn_00141040


// 0x00141570 fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::vfunc_7 (6 B): matches/0x00141570.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VWallVelocityCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00141580 fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::vfunc_6 (30 B): matches/0x00141580.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VWallVelocityCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_141580 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_141580*)&DAT_003f335c));
}


// 0x001415a0 fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::vfunc_8 (26 B): matches/0x001415a0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::**)(int))&this->f_18))(b);
}


// 0x001415c0 fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::vfunc_2 (11 B): matches/0x001415c0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001415f0 fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::vfunc_6 (26 B): matches/0x001415f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::**)(int))&this->f_10))(b);
}


// 0x00141610 fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::vfunc_2 (11 B): matches/0x00141610.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00141640 fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>::vfunc_6 (26 B): matches/0x00141640.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>::**)(int))&this->f_10))(b);
}


// 0x00141660 fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>::vfunc_2 (11 B): matches/0x00141660.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00141690 fight::ParamBool<hulkfight::motion::WallRunTrack>::vfunc_6 (26 B): matches/0x00141690.cpp
// sym: ?vfunc_6@?$ParamBool@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::WallRunTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::WallRunTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::WallRunTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::WallRunTrack>::**)(int))&this->f_10))(b);
}


// 0x001416b0 fight::ParamBool<hulkfight::motion::WallRunTrack>::vfunc_2 (11 B): matches/0x001416b0.cpp
// sym: ?vfunc_2@?$ParamBool@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::WallRunTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001416e0 fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>::vfunc_6 (26 B): matches/0x001416e0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>::**)(int))&this->f_10))(b);
}


// 0x00141700 fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>::vfunc_2 (11 B): matches/0x00141700.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00141730 fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>::vfunc_6 (26 B): matches/0x00141730.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>::**)(int))&this->f_10))(b);
}


// 0x00141750 fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>::vfunc_2 (11 B): matches/0x00141750.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00141780 fight::ParamBool<hulkfight::motion::WallJumpTrack>::vfunc_6 (26 B): matches/0x00141780.cpp
// sym: ?vfunc_6@?$ParamBool@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::WallJumpTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::WallJumpTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::WallJumpTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::WallJumpTrack>::**)(int))&this->f_10))(b);
}


// 0x001417a0 fight::ParamBool<hulkfight::motion::WallJumpTrack>::vfunc_2 (11 B): matches/0x001417a0.cpp
// sym: ?vfunc_2@?$ParamBool@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::WallJumpTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001417d0 fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>::vfunc_6 (26 B): matches/0x001417d0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>::**)(int))&this->f_10))(b);
}


// 0x001417f0 fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>::vfunc_2 (11 B): matches/0x001417f0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00141820 fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>::vfunc_6 (26 B): matches/0x00141820.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>::**)(int))&this->f_10))(b);
}


// 0x00141840 fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>::vfunc_2 (11 B): matches/0x00141840.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00141870 fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>::vfunc_6 (26 B): matches/0x00141870.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>::**)(int))&this->f_10))(b);
}


// 0x00141890 fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>::vfunc_2 (11 B): matches/0x00141890.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001418b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::WallVelocityCondition>::vfunc_0 (36 B): matches/0x001418b0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VWallVelocityCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::WallVelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004ad4d0, 0)) != 0;
}


// 0x001418e0 fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::vfunc_0 (30 B): matches/0x001418e0.cpp
// sym: ??_G?$ParamEnumConstList@VWallVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1418e0)
#endif


// 0x00141900 fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::vfunc_0 (30 B): matches/0x00141900.cpp
// sym: ??_G?$ParamFloatConstRange@VWallVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x141900)
#endif


// 0x00141930 fight::TrackFactoryCasterTemplate<hulkfight::motion::WallRunTrack>::vfunc_0 (36 B): matches/0x00141930.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VWallRunTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::WallRunTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ad588, 0) != 0;
}


// 0x00141960 fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>::vfunc_0 (30 B): matches/0x00141960.cpp
// sym: ??_G?$ParamFloatConstRange@VWallRunTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x141960)
#endif


// 0x00141980 fight::ParamBool<hulkfight::motion::WallRunTrack>::vfunc_0 (30 B): matches/0x00141980.cpp
// sym: ??_G?$ParamBool@VWallRunTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::WallRunTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::WallRunTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x141980)
#endif


// 0x001419a0 fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>::vfunc_0 (30 B): matches/0x001419a0.cpp
// sym: ??_G?$ParamIntConstRange@VWallRunTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1419a0)
#endif


// 0x001419d0 fight::TrackFactoryCasterTemplate<hulkfight::motion::WallJumpTrack>::vfunc_0 (36 B): matches/0x001419d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VWallJumpTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::WallJumpTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ad630, 0) != 0;
}


// 0x00141a00 fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>::vfunc_0 (30 B): matches/0x00141a00.cpp
// sym: ??_G?$ParamFloatConstRange@VWallJumpTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x141a00)
#endif


// 0x00141a20 fight::ParamBool<hulkfight::motion::WallJumpTrack>::vfunc_0 (30 B): matches/0x00141a20.cpp
// sym: ??_G?$ParamBool@VWallJumpTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::WallJumpTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::WallJumpTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x141a20)
#endif


// 0x00141a40 fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>::vfunc_0 (30 B): matches/0x00141a40.cpp
// sym: ??_G?$ParamIntConstRange@VWallJumpTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x141a40)
#endif


// 0x00141a70 fight::TrackFactoryCasterTemplate<hulkfight::motion::WallExitTrack>::vfunc_0 (36 B): matches/0x00141a70.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VWallExitTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::WallExitTrack>::vfunc_0(void* __p0) { void * obj = (void *)__p0;

    return (FUN_00344e74(obj, 0, &DAT_0049850c, &DAT_004ad6d8, 0) != 0);
}


// 0x00141aa0 fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>::vfunc_0 (30 B): matches/0x00141aa0.cpp
// sym: ??_G?$ParamFloatConstRange@VWallExitTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::WallExitTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x141aa0)
#endif


// 0x00141ac0 fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>::vfunc_0 (30 B): matches/0x00141ac0.cpp
// sym: ??_G?$ParamIntConstRange@VWallExitTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x141ac0)
#endif


// 0x001421d0 hulkfight::motion::WallRunTrack::vfunc_10 (70 B): matches/0x001421d0.cpp
// sym: ?vfunc_10@WallRunTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::WallRunTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1421d0 a = (u32_1421d0)__p0; u32_1421d0 b = (u32_1421d0)__p1; u32_1421d0 c = (u32_1421d0)__p2;

    if (FUN_00344e74(c, 0, hulk_at_00494b44, hulk_at_00494b60, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_1421d0*)p)->run_0013f9c0(this, c);
    }
    return 0;
}

namespace fn_f8068520 {

// 0x00142220 hulkfight::motion::WallRunAction::vfunc_2 (95 B): matches/0x00142220.cpp
// sym: ?f2@WallRunAction_142220@fn_f8068520@@QAEPAV12@E@Z
WallRunAction_142220* WallRunAction_142220::f2(unsigned char flags) {
    vptr = g_vftable_142220;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_142220 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f8068520

// 0x00142280 hulkfight::motion::WallExitTrack::vfunc_10 (70 B): matches/0x00142280.cpp
// sym: ?vfunc_10@WallExitTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::WallExitTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (IsType((void*)c, 0, &g1_142280, &g2, 0)) {
        Obj_142280* p = (Obj_142280*)Alloc_0008d690(0x4c);
        if (p)
            return p->Init_00140100(this, c);
    }
    return 0;
}

namespace fn_f8068520 {

// 0x001422d0 hulkfight::motion::WallExitAction::vfunc_2 (90 B): matches/0x001422d0.cpp
// sym: ?vfunc_2@WallExitAction_1422d0@fn_f8068520@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* WallExitAction_1422d0::vfunc_2(unsigned char flag) {
    volatile WallExitAction_1422d0* self = this;
    self->mVptr = &g_vftable_1422d0;
    RefObj_1422d0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_1422d0* t2 = self->m2;
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

} // namespace fn_f8068520

// 0x00142330 hulkfight::motion::WallJumpTrack::vfunc_10 (70 B): matches/0x00142330.cpp
// sym: ?vfunc_10@WallJumpTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::WallJumpTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { unsigned int a = (unsigned int)__p0; unsigned int b = (unsigned int)__p1; hulk_uintptr c = (unsigned int)__p2;

    if (IsType((void*)c, 0, &RT1, &RT2, 0)) {
        Result_142330* r = (Result_142330*)MakeResult_0008d690((void*)0x50);
        if (r)
            return (int)(r->init_00140590(this, c));
    }
    return (int)(0);
}

namespace fn_f8068520 {

// 0x00142380 hulkfight::motion::WallJumpAction::vfunc_2 (90 B): matches/0x00142380.cpp
// sym: ?vfunc_2@WallJumpAction_142380@fn_f8068520@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* WallJumpAction_142380::vfunc_2(unsigned char flag) {
    volatile WallJumpAction_142380* self = this;
    self->mVptr = &g_vftable_142380;
    RefObj_142380* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_142380* t2 = self->m2;
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


// 0x00142440 fight::ParamName<hulkfight::motion::WallRunTrack>::vfunc_7 (12 B): matches/0x00142440.cpp
// sym: ?vfunc_6@ParamBranch@fn_f8068520@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f8068520

// 0x00142490 fight::ParamName<hulkfight::motion::WallRunTrack>::vfunc_0 (30 B): matches/0x00142490.cpp
// sym: ??_G?$ParamName@VWallRunTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::WallRunTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::WallRunTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x142490)
#endif

namespace fn_f8068520 {

// 0x001424e0 FUN_001424e0 (38 B): matches/0x001424e0.cpp
// sym: _FUN_001424e0
extern "C" void __cdecl FUN_001424e0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1424e0 c;
    Track* t = Find_00236ac0(name, &c);
    owner->Set_002367c0(t);
}


// 0x001428b0 FUN_001428b0 (38 B): matches/0x001428b0.cpp
// sym: _FUN_001428b0
extern "C" void __cdecl FUN_001428b0(Obj* obj, void* source) {
    TrackFactoryCasterTemplate_1428b0 c;
    obj->Apply_002367c0(Find_00236ac0(source, &c));
}


// 0x001428e0 FUN_001428e0 (38 B): matches/0x001428e0.cpp
// sym: _FUN_001428e0
extern "C" void FUN_001428e0(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_1428e0 caster;
    owner->Add_002367c0(FUN_00236ac0(name, &caster));
}


// 0x00142910 FUN_00142910 (38 B): matches/0x00142910.cpp
// sym: _FUN_00142910
extern "C" void FUN_00142910(Manager* mgr) {
    ConditionFactoryCasterTemplate_142910 c;
    mgr->Add_00236760(FUN_002343e0("wallVelocity", &c));
}

} // namespace fn_f8068520

// 0x00142940 FUN_00142940 (67 B): equivalent/0x00142940.cpp [wrapped: conflict: World; content::LoadInventory::DynamicCaster]
// sym: _FUN_00142940 @b66cccfdbc21 @w4c8f193d04b9
namespace fn_00142940 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00142940 @ 0x00142940
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

namespace pure3d { struct Animation_142940 {}; }
namespace content { namespace LoadInventory {
template<class T> struct DynamicCaster { virtual void cast(); };
}}
struct Inventory {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(content::LoadInventory::DynamicCaster<pure3d::Animation_142940>*, int, int);
};
struct Provider {  };
struct World { char pad[0x54]; struct Service* service; };
struct Service {  };
struct Pair { int first; int second; };
// equiv-conv: FUN_00142940 eax
extern "C" int FUN_00142940(void * pair) {
    int first = ((Pair *)pair)->first;
    int second = ((Pair *)pair)->second;
    if (!(first | second)) return 0;
    Provider* provider = ((Provider *)((owners::Target_862a0 *)(DAT_004dd700->service))->FUN_000862a0());
    Inventory* inventory = ((Inventory *)((owners::Target_203d70 *)provider)->FUN_00203d70());
    content::LoadInventory::DynamicCaster<pure3d::Animation_142940> caster;
    return inventory->slot3(&caster, first, second);
}
} // namespace fn_00142940
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00142990 hulkfight::motion::WallRunAction::vfunc_3 (1292 B): equivalent/0x00142990.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_3@WallRunAction@motion@hulkfight@fn_00142990@@UAEDHH@Z @1d4ae7a7a3c6 @weea68171fc05
namespace fn_00142990 {
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 36/36)
// hulkfight::motion::WallRunAction::vfunc_3 @ 0x00142990
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-conv: FUN_00142940 eax

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif

void *thunk_FUN_0008d690(unsigned int size);

union FloatBits_142990 {
    float f;
    unsigned int u;
};

static float AbsF(float v)
{
    FloatBits_142990 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

struct V3_142990 {
    union {
        float x;
        int ix;
    };
    union {
        float y;
        int iy;
    };
    union {
        float z;
        int iz;
    };
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(const V3_142990 *other, float epsilon);
};

extern "C++" __declspec(nothrow) int __cdecl FUN_00142940(void *);

struct Name_142990 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct LocomotionSteerDriver_142990 {
    virtual void v0();
    virtual void v1();
    char pad04[4];
    Name_142990 name;
    char pad10[0x89c - 0x10];
    bool b89c;
    bool b89d;
    LocomotionSteerDriver_142990 *FUN_00229760(int a, int b, int c, int *desc, int d);
};

struct JointDriver_142990 {
    virtual void v0();
    virtual void v1();
    char pad04[4];
    Name_142990 name;
    JointDriver_142990 *FUN_002248f0(unsigned int id);
};

struct Stats_142990 {
    char pad0[0x1ae0];
    V3_142990 vB;
    char pad1aec[0x1af8 - 0x1aec];
    V3_142990 vA;
    char pad1b04[0x2008 - 0x1b04];
    int i2008;
    char pad200c[0x2064 - 0x200c];
    V3_142990 vec2064;
    float FUN_0003ec00(int z);
    char FUN_000356c0(V3_142990 *out);
};

struct Scene_142990 {
    int FUN_002226b0();
    void FUN_00222890(LocomotionSteerDriver_142990 *r, float a, int b, float c, int d, int e, float f);
};

struct Pool_142990 {
    Stats_142990 *FUN_00059a30();
    Scene_142990 *FUN_00059a40();
};

struct Owner_142990 {
    Pool_142990 *FUN_000592a0();
};

struct Config_142990 {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    bool flag24;
    char pad25[0x38 - 0x25];
    char id1[8];
    char id2[8];
    char id3[8];
    int i50;
    int i54;
    int i58;
};

extern "C" void __cdecl FUN_0015cfd0(int h, LocomotionSteerDriver_142990 *r);

namespace hulkfight { namespace motion {

class WallRunAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a0, int a1);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Config_142990 *cfg;    // 0x1c
    Owner_142990 *owner;   // 0x20
    LocomotionSteerDriver_142990 *rig;       // 0x24
    JointDriver_142990 *root;     // 0x28
    V3_142990 w;           // 0x2c
    V3_142990 a;           // 0x38
    V3_142990 b;           // 0x44
    bool flag50;    // 0x50
    char pad51[3];
    int i54;        // 0x54
};

char WallRunAction::vfunc_3(int a0, int a1)
{
    Pool_142990 *pool = owner->FUN_000592a0();
    Stats_142990 *stats = pool->FUN_00059a30();

    V3_142990 v = stats->vA;
    V3_142990 z;
    z.x = 0.0f;
    z.y = 0.0f;
    z.z = 0.0f;
    if (v.FUN_0022d2b0(&z, 1e-5f)) {
        v = stats->vB;
        z.x = 0.0f;
        z.y = 0.0f;
        z.z = 0.0f;
        if (v.FUN_0022d2b0(&z, 1e-5f))
            return 0;
    }

    v.y = 0.0f;
    v.FUN_0022d110();
    a.ix = v.ix;
    a.iy = v.iy;
    a.iz = v.iz;
    b.ix = v.ix;
    b.iy = v.iy;
    b.iz = v.iz;
    i54 = stats->i2008;
    w.ix = 0;
    w.iy = 0;
    w.iz = 0;
    if (cfg->flag24) {
        flag50 = true;
        w.ix = stats->vec2064.ix;
        w.iy = stats->vec2064.iy;
        w.iz = stats->vec2064.iz;
        hulk_freg dot = v.z * w.z + v.y * w.y + v.x * w.x;
        if (dot < 0.0f) {
            hulk_freg nd = -dot;
            struct { hulk_freg x; float y, z; } t;   // v * nd: x stays in a register, y and z are stored
            t.x = v.x * nd;
            t.y = v.y * nd;
            t.z = v.z * nd;
            w.x = t.x + w.x;
            w.y = t.y + w.y;
            w.z = t.z + w.z;
        }
        if (w.y < 0.0f)
            w.iy = 0;
        float len = w.FUN_0022d110();
        if (AbsF(len) <= 1e-5f) {
            w.ix = 0;
            w.y = 1.0f;
            w.iz = 0;
        }
        if (w.y < 0.70710677f) {
            float zz = w.z;
            w.y = 0.70710677f;
            double r = sqrt(w.x * w.x + zz * zz);
            double k = 0.70710677f / r;
            w.x = (float)(k * w.x);
            w.z = (float)(k * w.z);
        }
        hulk_freg R = stats->FUN_0003ec00(0);
        float c1c = cfg->f1c;
        hulk_freg m = c1c + R * (cfg->f20 - c1c);
        w.x = m * w.x;
        w.y = m * w.y;
        w.z = m * w.z;
    } else {
        flag50 = false;
        stats->FUN_000356c0(&w);
        hulk_freg dot = v.z * w.z + v.y * w.y + v.x * w.x;
        if (dot < 0.0f) {
            hulk_freg nd = -dot;
            struct { hulk_freg x; float y, z; } t;   // v * nd: x stays in a register, y and z are stored
            t.x = v.x * nd;
            t.y = v.y * nd;
            t.z = v.z * nd;
            w.x = t.x + w.x;
            w.y = t.y + w.y;
            w.z = t.z + w.z;
        }
        Config_142990 *c = cfg;
        float c18 = c->f18;
        if (c18 > 0.0f && c18 > w.y)
            w.y = c18;
        float c14 = c->f14;
        if (c14 > 0.0f) {
            double len = sqrt(w.x * w.x + w.y * w.y + w.z * w.z);
            if (len <= 0.0) {
                w.ix = 0;
                w.y = 1.0f;
                w.iz = 0;
                len = 1.0;
            }
            if (len < c14) {
                double k = c14 / len;
                w.x = (float)(k * w.x);
                w.y = (float)(k * w.y);
                w.z = (float)(k * w.z);
            }
        }
    }

    Scene_142990 *scene = pool->FUN_00059a40();
    if (scene == 0)
        return 0;
    int h = scene->FUN_002226b0();
    int id1 = FUN_00142940((void *)(const void *)(cfg->id1));
    int id2 = FUN_00142940((void *)(const void *)(cfg->id2));
    int id3 = FUN_00142940((void *)(const void *)(cfg->id3));
    int desc[10];
    desc[0] = 0;
    desc[1] = 0;
    desc[2] = 0;
    desc[3] = 0;
    desc[4] = 0;
    desc[5] = id2;
    desc[6] = id2;
    desc[7] = id1;
    desc[8] = 0;
    desc[9] = id3;
    void *mem = thunk_FUN_0008d690(0x910);
    LocomotionSteerDriver_142990 *obj = 0;
    if (mem)
        obj = ((LocomotionSteerDriver_142990 *)mem)->FUN_00229760(h, 4, 2, desc, 0);
    if (obj)
        obj->v0();
    if (rig)
        rig->v1();
    rig = obj;
    FUN_0015cfd0(h, obj);
    int c54 = cfg->i54;
    int c58 = cfg->i58;
    int c50 = cfg->i50;
    rig->b89d = false;
    rig->b89c = false;
    rig->name.FUN_0027b040("wallRunLoco");
    scene->FUN_00222890(rig, -1.0f, c50, 1.0f, c54, c58, -1.0f);

    void *mem2 = thunk_FUN_0008d690(0x70);
    JointDriver_142990 *r2 = 0;
    if (mem2)
        r2 = ((JointDriver_142990 *)mem2)->FUN_002248f0(0);
    root = r2;
    r2->name.FUN_0027b040("wallRunRoot");
    root->v0();
    scene->FUN_00222890((LocomotionSteerDriver_142990 *)root, -1.0f, c50 - 1, 1.0f, c54, c58, -1.0f);
    return 1;
}

}}
} // namespace fn_00142990


// 0x00142ea0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::WallVelocityCondition>::vfunc_1 (60 B): matches/0x00142ea0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VWallVelocityCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::WallVelocityCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_142ea0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_142ea0* t = new (mem) TrackFactoryTemplate_142ea0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f8068520 {

// 0x00142ee0 fight::ConditionFactoryTemplate<hulkfight::motion::WallVelocityCondition>::vfunc_5 (54 B): matches/0x00142ee0.cpp
// sym: ?v5@Obj_142ee0@fn_f8068520@@UAEPAV12@XZ
Obj_142ee0* Obj_142ee0::v5() {
    Obj_142ee0* p = (Obj_142ee0*)FUN_0008d690((int)sizeof(Obj_142ee0));
    if (p) {
        p->Init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00412ab0);
        p->b = 0;
        p->c = 0;
        return p;
    }
    return 0;
}


// 0x00142f20 fight::ConditionFactoryTemplate<hulkfight::motion::WallVelocityCondition>::vfunc_2 (43 B): matches/0x00142f20.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_142f20@fn_f8068520@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_142f20::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412e48;
    base1_dtor_0013ee20();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8068520

// 0x00142f50 fight::TrackFactoryCasterTemplate<hulkfight::motion::WallJumpTrack>::vfunc_1 (60 B): matches/0x00142f50.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VWallJumpTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::WallJumpTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_142f50));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_142f50* t = new (mem) TrackFactoryTemplate_142f50();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00142f90 fight::TrackFactoryTemplate<hulkfight::motion::WallJumpTrack>::vfunc_5 (24 B): matches/0x00142f90.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VWallJumpTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00076ec0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::WallJumpTrack>::vfunc_5() {
    Jump* p = (Jump*)alloc_54(0x54);
    if (p)
        return (void*)(p->construct());
    return (void*)(0);
}

namespace fn_f8068520 {

// 0x00142fb0 fight::TrackFactoryTemplate<hulkfight::motion::WallJumpTrack>::vfunc_2 (43 B): matches/0x00142fb0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f8068520@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412e64;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8068520

// 0x00142fe0 fight::TrackFactoryCasterTemplate<hulkfight::motion::WallExitTrack>::vfunc_1 (60 B): matches/0x00142fe0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VWallExitTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::WallExitTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_142fe0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_142fe0* t = new (mem) TrackFactoryTemplate_142fe0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00143020 fight::TrackFactoryTemplate<hulkfight::motion::WallExitTrack>::vfunc_5 (24 B): matches/0x00143020.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VWallExitTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fac0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::WallExitTrack>::vfunc_5() {
    Track_143020* p = (Track_143020*)operator_new(0x38);
    if (p)
        return (void*)(p->method_0013f0a0());
    return (void*)(0);
}


// 0x00143040 fight::TrackFactoryTemplate<hulkfight::motion::WallExitTrack>::vfunc_2 (43 B): matches/0x00143040.cpp [wrapped: same definition as 0x00142fb0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00143040@@QAEPAXE@Z
namespace fn_00143040 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412e80;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0013f070();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412e80;
    base1_dtor_0013f070();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00143040


// 0x00143070 fight::TrackFactoryCasterTemplate<hulkfight::motion::WallRunTrack>::vfunc_1 (60 B): matches/0x00143070.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VWallRunTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::WallRunTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_143070));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_143070* t = new (mem) TrackFactoryTemplate_143070();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001430b0 fight::TrackFactoryTemplate<hulkfight::motion::WallRunTrack>::vfunc_5 (24 B): matches/0x001430b0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VWallRunTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f220 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::WallRunTrack>::vfunc_5() {
    void* p = Alloc_0008d690(0x60);
    if (p)
        return (void*)(((InitObj_1430b0*)p)->Init_0013eec0());
    return (void*)(0);
}


// 0x001430d0 fight::TrackFactoryTemplate<hulkfight::motion::WallRunTrack>::vfunc_2 (43 B): matches/0x001430d0.cpp [wrapped: same definition as 0x00142fb0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001430d0@@QAEPAXE@Z
namespace fn_001430d0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412e9c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0013ee90();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412e9c;
    base1_dtor_0013ee90();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_001430d0

