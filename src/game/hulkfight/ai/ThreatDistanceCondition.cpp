// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b190..0x0012d920 (kind game, layer game, confidence high), dominant class hulkfight::ai::ThreatDistanceCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9c2e0ac {
#define TREE_TU_END }
namespace fn_f9c2e0ac {} using namespace fn_f9c2e0ac;
#include "game/hulkfight/ai.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f9c2e0ac {
class A_12b190 {
  public:
    char pad[0xc];
    unsigned char value;
    bool SetThreat_0012b190(unsigned char x);
};
class Obj_12b1a0 {
  public:
    char pad[0x10];
    void* GetThreatName_0012b1a0();
};
class C_12b1b0 {
    char pad[0x18];
    char m;

  public:
    char SetThreatRespondOnlyOnce_0012b1b0(char c);
};
class Obj_12b1c0 {
  public:
    char pad[12];
    int m12;
    bool SetCompare_0012b1c0(int v);
};
class Obj_12b1d0 {
  public:
    char pad[0x10];
    int mValue;
    bool SetDistance_0012b1d0(int x);
};
class X_12b1e0 {
  public:
    char pad[0x18];
    void* GetThreatName_0012b1e0();
};
class Obj_12b1f0 {
  public:
    char pad[0x20];
    char m20;
    unsigned char SetThreatRespondOnlyOnce_0012b1f0(unsigned char v);
};
class C_12b200 {
  public:
    char pad[12];
    float value;
};
class Obj_12b220 {
  public:
    char pad[0x10];
    float mF10;
    bool SetArc_0012b220(float angle);
};
const float kDegToRad = 0.017453292f;
class Obj_12b240 {
  public:
    char pad[0x18];
    void* GetThreatName_0012b240();
};
class Obj_12b250 {
  public:
    char Pad[0x20];
    char Value;
    char SetThreatRespondOnlyOnce_0012b250(char c);
};
struct Obj_12b2c0 {
    char pad[0x18];
    void* m18;
};
extern int* hulk_at_004e0e14;
class CCondition_12b3d0 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_00410bd4[];
class Sub_12b410 {
  public:
    void Init_0027af50();
};
class ThreatDistanceCondition_12b410 {
  public:
    void Finish_002345b0();
};
extern int* hulk_at_004e0e1c;
class CCondition_12b450 {
  public:
    virtual int vfunc_0(int);
};
struct Tail_12b490 {
    void Init_0027af50();
};
struct ThreatDistanceCondition_12b490 {
    void* vptr;
    char pad[0x14];
    void Finish_002345b0();
    void Run();
};
extern void* hulk_at_00410bf4;
extern int* hulk_at_004e0e24;
class CCondition_12b4d0 {
  public:
    virtual int vfunc_0(int);
};
struct Tail_12b510 {
    void Init_0027af50();
};
struct ThreatAngleCondition_12b510 {
    void* vptr;
    char pad[0x14];
    void Finish_002345b0();
    void Run();
};
extern void* hulk_at_00410c14;
extern int* hulk_at_004e0e2c;
class CCondition_12b550 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0e34;
class CCondition_12b5c0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_12b630 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_12b630 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int hulk_at_00410c54;
class Helper_12b640 {
  public:
    void Init_0027af50();
};
extern int* hulk_at_004e0e3c;
class CCondition_12b690 {
  public:
    virtual int vfunc_0(int);
};
class Track_12b6a0 {
  public:
    Track_12b6a0();
    virtual void f();
};
class Sub {
  public:
    Sub();
};
class ThreatDodgeTrack : public Track_12b6a0 {
  public:
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual ThreatDodgeTrack* vfunc_5(unsigned char);
    virtual void m_vf6_0012b6e0();
    virtual void m_vf7_0012b6f0();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    ThreatDodgeTrack();
    char _m_pad_4[0x8];
    int a;
    float b;
    float c;
    char d;
    char _m_pad_19[0x7];
    Sub sub;
    char _m_pad_21[0x3];
};
struct Param_12b6f0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_12b6f0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern void* hulk_at_00410c84[];
struct Sub_12b700 {
    char c;
};
void __fastcall Fin(Sub_12b700*) throw();
class Track_12b700 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class ThreatDodgeTrack_12b700 : public Track_12b700 {
  public:
    char pad[0x1c];
    Sub_12b700 sub;
    void F();
    ~ThreatDodgeTrack_12b700() throw();
};
extern "C" void __fastcall FUN_0027af50(Sub_12b700*) throw();
extern const char hulk_at_00494b44[];
extern const char hulk_at_00494b60[];
class Obj2_12b780 {
  public:
    unsigned char Test_00037080(void* a, unsigned char b);
};
class Obj_12b780 {
  public:
    Obj2_12b780* Next_00059a30();
};
struct Obj_12b8e0 {
    int Fn_00067b00(hulk_intptr);
};
struct Inner_12b8e0 {
    char pad[8];
    Obj_12b8e0* obj8;
};
struct Outer_12b8e0 {
    char pad[0x20];
    Inner_12b8e0* inner;
};
extern Outer_12b8e0* hulk_at_004dd700;
struct Vec3_12b910 { float x, y, z; };
struct Mat_12b910 {
    float m[16];
};
struct JointFinder_12b910 {
    unsigned int FUN_0027b200(int a, int b);
};
struct Skeleton_12b910 {
    char pad0[8];
    JointFinder_12b910 *finder;
    char pad0c[0x1c - 0xc];
    Mat_12b910 *matrices;
};
class Attach_12b910 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int v15();
    Skeleton_12b910 *FUN_001d68d0();
};
struct Stats_12b910 {
    char pad0[0x120];
    Skeleton_12b910 *skeleton;
};
struct Fighter_12b910 { char pad[4]; };
Fighter_12b910 *__fastcall FUN_000592a0(void *owner);
extern "C" Stats_12b910 *__fastcall FUN_00059a30(Fighter_12b910 *f);
struct Sink_12b910;
struct Request_12b910 {
    void *source;
    Vec3_12b910 pos;
    float extra;
    char pad14[0x20 - 0x14];
    void FUN_00067e20();
    void FUN_000679c0();
};
struct Sink_12b910 {
    void FUN_00067c30(int arg, Request_12b910 *req);
};
struct SinkHolder_12b910 {
    char pad0[8];
    Sink_12b910 *sink;
};
} // namespace fn_f9c2e0ac
struct World {
    char pad0[0x20];
    SinkHolder_12b910 *holder;
};
namespace fn_f9c2e0ac {
struct Owner_12b910 {
    char pad0[8];
    void *f08;
};
struct Data_12b910 {
    char pad0[0x14];
    int slot;
    int f18;
    int f1c;
    Vec3_12b910 offset;
    float f2c;
};
struct Obj_12ba80 {
    void call_00067c80(int);
    void tail_00065c10();
};
struct Inner_12ba80 {
    char pad[8];
    Obj_12ba80* p;
};
struct Global_12ba80 {
    char pad[0x20];
    Inner_12ba80* inner;
};
extern Global_12ba80* g_12ba80;
extern Obj_12ba80* __cdecl FUN_000678d0();
struct Vec_12bab0 { float x,y,z; hulk_freg FUN_0022d110(); };
struct Position_12bab0 { void FUN_00059a50(Vec_12bab0*); };
struct Actor_12bab0 { char pad0[0x10]; Position_12bab0* position; char pad1[0x2064-0x14]; Vec_12bab0 direction; unsigned int mode; Vec_12bab0 direction2; char pad2[0x22a0-0x2080]; Vec_12bab0 reference; bool FUN_00037080(void*,unsigned int); };
struct Link2_12bab0 { Actor_12bab0* FUN_00059a30(); };
struct Link_12bab0 {  };
struct Settings_12bab0 { char pad[0x14]; unsigned int mode; unsigned char flag; char pad2[7]; char data[1]; };
extern char hulk_at_00410bd4;
struct ThreatDistanceCondition_12bc00 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(ThreatDistanceCondition_12bc00*);
class ThreatCondition {
  public:
    void* vftable;
    char pad[0x0c];
    ThreatCondition* vfunc_5(unsigned char);
};
extern void* g_vftable_12bc30[];
class Str_12bc30 {
  public:
    void Init_0027af50();
};
class Condition_12bc30 {
  public:
    void* vptr;
    char pad[20];
    Str_12bc30 s;
    void Fin_002345b0();
};
class ThreatDistanceCondition_12bc30 : public Condition_12bc30 {
  public:
    void* Del(unsigned char flags);
};
struct Sub_12bc60 {
    void FnF_0027af50();
};
struct ThreatAngleCondition {
    void* vf;
    char pad[0x14];
    Sub_12bc60 sub;
    ThreatAngleCondition* vfunc_5(int);
    void Second_002345b0();
};
void Cleanup_0008d330(ThreatAngleCondition*);
extern char vtable_12bc60[];
extern void* hulk_at_00410c34[];
class Condition_12bc90 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class ShotFailCountCondition_12bc90 : public Condition_12bc90 {
  public:
    ShotFailCountCondition_12bc90* vfunc_5(signed char flags);
};
extern "C" char DAT_00410c84[];
class Helper_12bd00 {
  public:
    void call1_0027af50();
    void call2_00236d60();
};
void FUN_0008d330(ThreatDodgeTrack*);
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_12bff0 {
  public:
    Action_12bff0();
    virtual void f();
    char pad[24];
};
struct Fields {
    int a;
    Ref* p;
    int c;
    Fields() : a(0), p(0), c(0) {}
};
class ThreatBallAction : public Action_12bff0 {
  public:
    ThreatBallAction(int, Ref*);
    virtual void f();
    Fields m;
};
extern void* hulk_at_00410cb4[];
class Ref_12c040 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_12c040 {
  public:
    void* vptr;
};
class ThreatBallAction_12c040 : public Action_12c040 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_12c040* m20;
    ~ThreatBallAction_12c040();
};
class RefObj_12c080 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_12c080 {
  public:
    Action_12c080();
    virtual void Update_00018b30();
    char pad[0x18];
};
class ThreatDodgeAction_12c080 : public Action_12c080 {
  public:
    int mTarget;
    RefObj_12c080* mObj;
    ThreatDodgeAction_12c080(int target, RefObj_12c080* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00410cd0[];
class Ref_12c0d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_12c0d0 {
  public:
    void* vptr;
};
class ThreatDodgeAction_12c0d0 : public Action_12c0d0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_12c0d0* m20;
    ~ThreatDodgeAction_12c0d0();
};
class CStageCondition_12c150;
class ParamValue_12c150 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c150 : public ParamValue_12c150 {
  public:
    int pad;
};
struct CAxisArcCondition_12c190;
class CStageCondition_12c1a0 {};
class ParamValue_12c1a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_12c1a0 : public ParamValue_12c1a0 {
  public:
    virtual void f();
};
class CStageCondition_12c230;
class ParamValue_12c230 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c230 : public ParamValue_12c230 {
  public:
    int pad;
};
class CStageCondition_12c280;
class ParamValue_12c280 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c280 : public ParamValue_12c280 {
  public:
    int pad;
};
class CStageCondition_12c2d0;
class ParamValue_12c2d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c2d0 : public ParamValue_12c2d0 {
  public:
    int pad;
};
class CStageCondition_12c320;
class ParamValue_12c320 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c320 : public ParamValue_12c320 {
  public:
    int pad;
};
struct CAxisArcCondition_12c360;
class CStageCondition_12c370 {};
class ParamValue_12c370 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_12c370 : public ParamValue_12c370 {
  public:
    virtual void f();
};
class CStageCondition_12c400;
class ParamValue_12c400 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c400 : public ParamValue_12c400 {
  public:
    int pad;
};
class CStageCondition_12c450;
class ParamValue_12c450 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c450 : public ParamValue_12c450 {
  public:
    int pad;
};
class CStageCondition_12c4a0;
class ParamValue_12c4a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c4a0 : public ParamValue_12c4a0 {
  public:
    int pad;
};
class CStageCondition_12c4f0;
class ParamValue_12c4f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c4f0 : public ParamValue_12c4f0 {
  public:
    int pad;
};
class CStageCondition_12c540;
class ParamValue_12c540 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c540 : public ParamValue_12c540 {
  public:
    int pad;
};
class CStageCondition_12c590;
class ParamValue_12c590 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c590 : public ParamValue_12c590 {
  public:
    int pad;
};
class Object_12c5b0 {};
class ConditionFactoryCaster_12c5b0 {
  public:
    virtual bool vfunc_0(Object_12c5b0*);
    virtual void vfunc_1();
};
class ThreatCondition_12c5b0 {};
extern void* hulk_at_00491ca8;
extern void* hulk_at_004a9438;
} // namespace fn_f9c2e0ac
namespace fight {
class ConditionFactoryCaster_12c6b0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class ThreatAngleCondition_12c6b0 {};
} }
namespace fn_f9c2e0ac {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a95a0;
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int gTypeA_12c730;
typedef unsigned int u32_12c970;
extern int TypeA_12c970;
extern int TypeB_12c970;
struct Result_12c970 {
    u32_12c970 Init_0012bff0(void*, void*);
};
extern Result_12c970* Alloc_0008d690(int);
struct RefCounted_12c9c0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_12c9c0[];
class ThreatBallAction_12c9c0 {
  public:
    ThreatBallAction_12c9c0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_12c9c0* m_20;
};
struct RefCounted_12ca60 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_12ca60[];
class ThreatDodgeAction_12ca60 {
  public:
    ThreatDodgeAction_12ca60* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_12ca60* m_20;
};
} // namespace fn_f9c2e0ac
inline void* operator new(size_t, void* memory) {
    return memory;
}
namespace fn_f9c2e0ac {
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetThreat_0012b190();
void __cdecl GetThreatName_0012b1a0();
void __cdecl SetThreatRespondOnlyOnce_0012b1b0();
} // namespace fn_f9c2e0ac
namespace hulkfight { namespace ai {
class ThreatCondition_12cd80;
} }
namespace fn_f9c2e0ac {
struct Base_12cd80 {
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    int tail;
};
} // namespace fn_f9c2e0ac
namespace fight {
template <class T> struct ParamBool_12cd80 : Base_12cd80 {
    virtual void slot0();
};
}
namespace fight {
template <class T> struct ParamName_12cd80 : Base_12cd80 {
    virtual void slot0();
};
}
namespace fn_f9c2e0ac {
void __cdecl FUN_002347b0(void*, void**, int);
extern "C" char DAT_00410ec0[];
typedef unsigned int u32_12d0e0;
extern u32_12d0e0 __cdecl FUN_002343e0(u32_12d0e0, void*);
struct Obj_12d0e0 {
    void Fn_00236760(u32_12d0e0);
};
struct Factory_12d0e0 {
    hulk_uintptr vft;
};
class TrackFactoryCasterTemplate_12d110 {
  public:
    virtual void cast();
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_12d110*);
class Obj {
  public:
    void* finish_002367c0(void*);
    void apply_002367c0(int);
};
class TrackFactoryCasterTemplate_12d2e0 {
  public:
    virtual void f();
};
extern "C" int __cdecl find(void*, TrackFactoryCasterTemplate_12d2e0*);
extern "C" char DAT_00410c34[];
extern "C" void* __cdecl alloc(hulk_uintptr);
struct ThreatDistanceCondition_12d530 {
    void* vt;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    float d;
    void Init_00234590(int x);
};
extern int hulk_at_0041101c;
struct ConditionFactoryTemplate_12d570 {
    void* m_vptr;
    void base1_dtor_0012b530();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern int hulk_at_00411038;
struct ConditionFactoryTemplate_12d620 {
    void* m_vptr;
    void base1_dtor_0012b3b0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_00410bf4[];
typedef unsigned int u32_12d690;
extern void* Alloc(hulk_uintptr);
struct Sub_12d690 {
    void Setup_0027af00();
};
struct ThreatDistanceCondition_12d690 {
    hulk_uintptr vf;
    char pad04[8];
    u32_12d690 mC;
    u32_12d690 mD;
    char pad14[4];
    Sub_12d690 sub;
    char pad1c[7];
    char flag;
    void Init_00234590(int);
};
extern int hulk_at_00411054;
struct ConditionFactoryTemplate_12d6e0 {
    void* m_vptr;
    void base1_dtor_0012b430();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_00410c14[];
void* __cdecl alloc28_0008d690(unsigned int);
struct Sub_12d750 {
    int a;
    int b;
    void Init_0027af00();
};
struct ThreatDistanceCondition_nv_12d750 {
    void Init_00234590(int);
};
class ThreatAngleCondition_12d750 {
  public:
    hulk_intptr vtable;
    char pad4[8];
    int c;
    int f;
    char pad14[4];
    Sub_12d750 sub;
    char enabled;
    char pad21[7];
};
extern int hulk_at_00411070;
struct ConditionFactoryTemplate_12d7a0 {
    void* m_vptr;
    void base1_dtor_0012b4b0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class Track_12d810 {
  public:
    hulk_intptr method_0012b5d0();
};
extern int hulk_at_0041108c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0012b5a0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};


// 0x0012b190 FUN_0012b190 (12 B): matches/0x0012b190.cpp
// sym: ?SetThreat_0012b190@A_12b190@fn_f9c2e0ac@@QAE_NE@Z
bool A_12b190::SetThreat_0012b190(unsigned char x) {
    value = x;
    return true;
}


// 0x0012b1a0 FUN_0012b1a0 (4 B): matches/0x0012b1a0.cpp
// sym: ?GetThreatName_0012b1a0@Obj_12b1a0@fn_f9c2e0ac@@QAEPAXXZ
void* Obj_12b1a0::GetThreatName_0012b1a0() {
    return (char*)this + 0x10;
}


// 0x0012b1b0 FUN_0012b1b0 (12 B): matches/0x0012b1b0.cpp
// sym: ?SetThreatRespondOnlyOnce_0012b1b0@C_12b1b0@fn_f9c2e0ac@@QAEDD@Z
char C_12b1b0::SetThreatRespondOnlyOnce_0012b1b0(char c) {
    m = c;
    return 1;
}


// 0x0012b1c0 FUN_0012b1c0 (12 B): matches/0x0012b1c0.cpp
// sym: ?SetCompare_0012b1c0@Obj_12b1c0@fn_f9c2e0ac@@QAE_NH@Z
bool Obj_12b1c0::SetCompare_0012b1c0(int v) {
    m12 = v;
    return true;
}


// 0x0012b1d0 FUN_0012b1d0 (12 B): matches/0x0012b1d0.cpp
// sym: ?SetDistance_0012b1d0@Obj_12b1d0@fn_f9c2e0ac@@QAE_NH@Z
bool Obj_12b1d0::SetDistance_0012b1d0(int x) {
    mValue = x;
    return true;
}


// 0x0012b1e0 FUN_0012b1e0 (4 B): matches/0x0012b1e0.cpp
// sym: ?GetThreatName_0012b1e0@X_12b1e0@fn_f9c2e0ac@@QAEPAXXZ
void* X_12b1e0::GetThreatName_0012b1e0() {
    return (char*)this + 0x18;
}


// 0x0012b1f0 FUN_0012b1f0 (12 B): matches/0x0012b1f0.cpp
// sym: ?SetThreatRespondOnlyOnce_0012b1f0@Obj_12b1f0@fn_f9c2e0ac@@QAEEE@Z
unsigned char Obj_12b1f0::SetThreatRespondOnlyOnce_0012b1f0(unsigned char v) {
    m20 = (char)v;
    return 1;
}


// 0x0012b200 FUN_0012b200 (18 B): matches/0x0012b200.cpp
// sym: ?SetAngle_0012b200@fn_f9c2e0ac@@YI_NPAVC_12b200@1@PAXM@Z
bool __fastcall SetAngle_0012b200(C_12b200* self, void*, float f) {
    self->value = f * 0.017453292f;
    return true;
}


// 0x0012b220 FUN_0012b220 (18 B): matches/0x0012b220.cpp
// sym: ?SetArc_0012b220@Obj_12b220@fn_f9c2e0ac@@QAE_NM@Z
bool Obj_12b220::SetArc_0012b220(float angle) {
    mF10 = angle * kDegToRad;
    return true;
}


// 0x0012b240 FUN_0012b240 (4 B): matches/0x0012b240.cpp
// sym: ?GetThreatName_0012b240@Obj_12b240@fn_f9c2e0ac@@QAEPAXXZ
void* Obj_12b240::GetThreatName_0012b240() {
    return (char*)this + 0x18;
}


// 0x0012b250 FUN_0012b250 (12 B): matches/0x0012b250.cpp
// sym: ?SetThreatRespondOnlyOnce_0012b250@Obj_12b250@fn_f9c2e0ac@@QAEDD@Z
char Obj_12b250::SetThreatRespondOnlyOnce_0012b250(char c) {
    Value = c;
    return 1;
}

} // namespace fn_f9c2e0ac

// 0x0012b260 FUN_0012b260 (12 B): matches/0x0012b260.cpp
// sym: ?FUN_0012b260@T_12b260@owners@@QAE_NH@Z
bool owners::T_12b260::FUN_0012b260(int x) {
    m = x;
    return true;
}


// 0x0012b270 FUN_0012b270 (12 B): matches/0x0012b270.cpp
// sym: ?FUN_0012b270@X_12b270@owners@@QAE_NH@Z
bool owners::X_12b270::FUN_0012b270(int value) {
    mThing = value;
    return true;
}


// 0x0012b280 FUN_0012b280 (12 B): matches/0x0012b280.cpp
// sym: ?FUN_0012b280@Obj_12b280@owners@@QAE_NH@Z
bool owners::Obj_12b280::FUN_0012b280(int x) {
    mVal = x;
    return true;
}


// 0x0012b290 FUN_0012b290 (12 B): matches/0x0012b290.cpp
// sym: ?FUN_0012b290@X_12b290@owners@@QAEDH@Z
char owners::X_12b290::FUN_0012b290(int v) {
    m = v;
    return 1;
}


// 0x0012b2b0 FUN_0012b2b0 (12 B): matches/0x0012b2b0.cpp
// sym: ?FUN_0012b2b0@Obj_12b2b0@owners@@QAEDH@Z
char owners::Obj_12b2b0::FUN_0012b2b0(int x) {
    m14 = x;
    return 1;
}

namespace fn_f9c2e0ac {

// 0x0012b2c0 FUN_0012b2c0 (4 B): matches/0x0012b2c0.cpp
// sym: ?FUN_0012b2c0@fn_f9c2e0ac@@YIPAXPAUObj_12b2c0@1@@Z
void* __fastcall FUN_0012b2c0(Obj_12b2c0* self) {
    return (char*)self + 0x18;
}

} // namespace fn_f9c2e0ac

// 0x0012b2f0 FUN_0012b2f0 (26 B): matches/0x0012b2f0.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4Obj_12b2f0@fn_0012b2f0@@QAE_NPBUSrc_12b2f0@1@@Z
namespace fn_0012b2f0 {
struct Src_12b2f0 {
    int a, b, c;
};
struct Obj_12b2f0 {
    char pad[0x20];
    int x, y, z;
    bool operator=(const Src_12b2f0* s);
};
bool Obj_12b2f0::operator=(const Src_12b2f0* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}
} // namespace fn_0012b2f0


// 0x0012b320 FUN_0012b320 (12 B): matches/0x0012b320.cpp
// sym: ?FUN_0012b320@Target_12b320@owners@@QAEEH@Z
unsigned char owners::Target_12b320::FUN_0012b320(int v) {
    value = v;
    return 1;
}


// 0x0012b330 FUN_0012b330 (4 B): matches/0x0012b330.cpp
// sym: ?FUN_0012b330@Obj_12b330@owners@@QAEPADXZ
char* owners::Obj_12b330::FUN_0012b330() {
    return (char*)this + 0x30;
}


// 0x0012b340 FUN_0012b340 (12 B): matches/0x0012b340.cpp
// sym: ?FUN_0012b340@Obj_12b340@owners@@QAE_NH@Z
bool owners::Obj_12b340::FUN_0012b340(int x) {
    value = x;
    return true;
}


// 0x0012b350 FUN_0012b350 (12 B): matches/0x0012b350.cpp
// sym: ?FUN_0012b350@X_12b350@owners@@QAEDH@Z
char owners::X_12b350::FUN_0012b350(int v) {
    m10 = v;
    return 1;
}


// 0x0012b370 FUN_0012b370 (12 B): matches/0x0012b370.cpp
// sym: ?FUN_0012b370@O_12b370@owners@@QAE_NH@Z
bool owners::O_12b370::FUN_0012b370(int x) {
    m14 = x;
    return true;
}


// 0x0012b390 FUN_0012b390 (12 B): matches/0x0012b390.cpp
// sym: ?FUN_0012b390@Obj_12b390@owners@@QAE_ND@Z
bool owners::Obj_12b390::FUN_0012b390(char c) {
    m = c;
    return true;
}


// 0x0012b3a0 FUN_0012b3a0 (4 B): matches/0x0012b3a0.cpp
// sym: ?FUN_0012b3a0@X_12b3a0@owners@@QAEPAXXZ
void* owners::X_12b3a0::FUN_0012b3a0() {
    return (char*)this + 0x20;
}

namespace fn_f9c2e0ac {

// 0x0012b3b0 FUN_0012b3b0 (19 B): matches/0x0012b3b0.cpp
// sym: ?FUN_0012b3b0@fn_f9c2e0ac@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012b3b0() {
    FUN_00234810(((char*)&DAT_004e0e14), ((char*)&DAT_004e0e18));
}

} // namespace fn_f9c2e0ac

// 0x0012b3d0 hulkfight::ai::ThreatCondition::vfunc_0 (16 B): matches/0x0012b3d0.cpp
// sym: ?vfunc_0@ThreatCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ThreatCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e14;
    return p[index];
}


// 0x0012b410 FUN_0012b410 (25 B): matches/0x0012b410.cpp
// sym: ?FUN_0012b410@ThreatCondition@ai@hulkfight@@QAEXXZ
void hulkfight::ai::ThreatCondition::FUN_0012b410() {
    *(void**)this = (void*)((hulk_intptr)DAT_00410bd4);
    ((Sub_12b410*)((char*)this + 0x10))->Init_0027af50();
    ((ThreatDistanceCondition_12b410*)this)->Finish_002345b0();
}

namespace fn_f9c2e0ac {

// 0x0012b430 FUN_0012b430 (19 B): matches/0x0012b430.cpp
// sym: ?FUN_0012b430@fn_f9c2e0ac@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012b430() {
    FUN_00234810(((char*)&DAT_004e0e1c), ((char*)&DAT_004e0e20));
}

} // namespace fn_f9c2e0ac

// 0x0012b450 hulkfight::ai::ThreatDistanceCondition::vfunc_0 (16 B): matches/0x0012b450.cpp
// sym: ?vfunc_0@ThreatDistanceCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ThreatDistanceCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e1c;
    return p[index];
}

namespace fn_f9c2e0ac {

// 0x0012b490 FUN_0012b490 (25 B): matches/0x0012b490.cpp
// sym: ?Run@ThreatDistanceCondition_12b490@fn_f9c2e0ac@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void ThreatDistanceCondition_12b490::Run() {
    vptr = &hulk_at_00410bf4;
    ((Tail_12b490*)((char*)this + 0x18))->Init_0027af50();
    Finish_002345b0();
}


// 0x0012b4b0 FUN_0012b4b0 (19 B): matches/0x0012b4b0.cpp
// sym: ?FUN_0012b4b0@fn_f9c2e0ac@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012b4b0() {
    FUN_00234810(((char*)&DAT_004e0e24), ((char*)&DAT_004e0e28));
}

} // namespace fn_f9c2e0ac

// 0x0012b4d0 hulkfight::ai::ThreatAngleCondition::vfunc_0 (16 B): matches/0x0012b4d0.cpp
// sym: ?vfunc_0@ThreatAngleCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ThreatAngleCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e24;
    return p[index];
}

namespace fn_f9c2e0ac {

// 0x0012b510 FUN_0012b510 (25 B): matches/0x0012b510.cpp
// sym: ?Run@ThreatAngleCondition_12b510@fn_f9c2e0ac@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void ThreatAngleCondition_12b510::Run() {
    vptr = &hulk_at_00410c14;
    ((Tail_12b510*)((char*)this + 0x18))->Init_0027af50();
    Finish_002345b0();
}


// 0x0012b530 FUN_0012b530 (19 B): matches/0x0012b530.cpp
// sym: ?FUN_0012b530@fn_f9c2e0ac@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012b530() {
    FUN_00234810(((char*)&DAT_004e0e2c), ((char*)&DAT_004e0e30));
}

} // namespace fn_f9c2e0ac

// 0x0012b550 hulkfight::ai::ShotFailCountCondition::vfunc_0 (16 B): matches/0x0012b550.cpp
// sym: ?vfunc_0@ShotFailCountCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ShotFailCountCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0e2c;
    return p[index];
}

namespace fn_f9c2e0ac {

// 0x0012b5a0 FUN_0012b5a0 (19 B): matches/0x0012b5a0.cpp
// sym: ?FUN_0012b5a0@fn_f9c2e0ac@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012b5a0() {
    FUN_00234810(((char*)&DAT_004e0e34), ((char*)&DAT_004e0e38));
}

} // namespace fn_f9c2e0ac

// 0x0012b5c0 hulkfight::ai::ThreatBallTrack::vfunc_0 (16 B): matches/0x0012b5c0.cpp
// sym: ?vfunc_0@ThreatBallTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ThreatBallTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e34;
    return p[index];
}


// 0x0012b5d0 FUN_0012b5d0 (74 B): matches/0x0012b5d0.cpp [wrapped: merged class would differ: ThreatBallTrack: field s1: Field(+0x18 Sub s1) vs Field(+0x18 Sub s1)]
// sym: ??0ThreatBallTrack@fn_0012b5d0@@QAE@XZ
namespace fn_0012b5d0 {
class Track_12b5d0 {
  public:
    Track_12b5d0();
    virtual void a();
    char pad[8];
};
class Sub {
  public:
    Sub();
    char pad[8];
};
struct Z {
    int v;
    Z() : v(0) {}
};
class ThreatBallTrack : public Track_12b5d0 {
  public:
    ThreatBallTrack();
    virtual void a();
    int x;
    float y;
    int z;
    Sub s1;
    int p, q, r;
    Z t;
    Sub s2;
};
ThreatBallTrack::ThreatBallTrack() : Track_12b5d0(), x(0), y(-1.0f), z(-1), s1(), p(0), q(0), r(0), t(), s2() {
    *(int*)((char*)this + 8) = 1;
}
} // namespace fn_0012b5d0


// 0x0012b620 hulkfight::ai::ThreatBallTrack::vfunc_6 (4 B): matches/0x0012b620.cpp
// sym: ?vfunc_6@ThreatBallTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::ThreatBallTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0012b630 hulkfight::ai::ThreatBallTrack::vfunc_7 (7 B): matches/0x0012b630.cpp
// sym: ?vfunc_7@ThreatBallTrack@ai@hulkfight@@UAEMXZ
hulk_freg hulkfight::ai::ThreatBallTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0012b640 FUN_0012b640 (33 B): matches/0x0012b640.cpp
// sym: ?FUN_0012b640@ThreatBallTrack@ai@hulkfight@@QAEXXZ
void hulkfight::ai::ThreatBallTrack::FUN_0012b640() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_00410c54;
    ((Helper_12b640*)((char*)this + 0x30))->Init_0027af50();
    ((Helper_12b640*)((char*)this + 0x18))->Init_0027af50();
    ((Ender*)this)->Finish();
}

namespace fn_f9c2e0ac {

// 0x0012b670 FUN_0012b670 (19 B): matches/0x0012b670.cpp
// sym: ?FUN_0012b670@fn_f9c2e0ac@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012b670() {
    FUN_00234810(((char*)&DAT_004e0e3c), ((char*)&DAT_004e0e40));
}

} // namespace fn_f9c2e0ac

// 0x0012b690 hulkfight::ai::ThreatDodgeTrack::vfunc_0 (16 B): matches/0x0012b690.cpp
// sym: ?vfunc_0@ThreatDodgeTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ThreatDodgeTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e3c;
    return p[index];
}

namespace fn_f9c2e0ac {

// 0x0012b6a0 FUN_0012b6a0 (51 B): matches/0x0012b6a0.cpp
// sym: ??0ThreatDodgeTrack@fn_f9c2e0ac@@QAE@XZ
ThreatDodgeTrack::ThreatDodgeTrack() : Track_12b6a0(), a(0), b(-1.0f), c(1.0f), d(1), sub() {}

} // namespace fn_f9c2e0ac

// 0x0012b6e0 hulkfight::ai::ThreatDodgeTrack::vfunc_6 (4 B): matches/0x0012b6e0.cpp
// sym: ?vfunc_6@ThreatDodgeTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::ThreatDodgeTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0012b6f0 hulkfight::ai::ThreatDodgeTrack::vfunc_7 (7 B): matches/0x0012b6f0.cpp
// sym: ?vfunc_7@ThreatDodgeTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::ThreatDodgeTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f9c2e0ac {

// 0x0012b700 FUN_0012b700 (25 B): matches/0x0012b700.cpp
// sym: ??1ThreatDodgeTrack_12b700@fn_f9c2e0ac@@QAE@XZ
ThreatDodgeTrack_12b700::~ThreatDodgeTrack_12b700() throw() {
    vptr = hulk_at_00410c84;
    FUN_0027af50(&sub);
    Fin_00236d60();
}

} // namespace fn_f9c2e0ac

// 0x0012b780 hulkfight::ai::ThreatCondition::vfunc_6 (90 B): matches/0x0012b780.cpp
// sym: ?vfunc_6@ThreatCondition@ai@hulkfight@@UAE_NPAX00@Z
bool hulkfight::ai::ThreatCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr c = (hulk_intptr)__p1; hulk_intptr d = (hulk_intptr)__p2;

    if (!((int)(hulk_uintptr)__RTDynamicCast((void*)(c), 0, (void*)(hulk_at_00494b44), (void*)(hulk_at_00494b60), 0)))
        return false;
    Obj_12b780* o = ((Obj_12b780 *)((owners::Object_592a0 *)(((Obj_12b780*)c)))->FUN_000592a0());
    Obj2_12b780* x = o->Next_00059a30();
    unsigned char r = x->Test_00037080((*(char (*)[8])&this->threatName), this->threatRespondOnlyOnce);
    unsigned char m = this->threat;
    return r == m;
}


// 0x0012b7e0 hulkfight::ai::ShotFailCountCondition::vfunc_6 (224 B): equivalent/0x0012b7e0.cpp [wrapped: conflict: FUN_00344e74; hulkfight::ai::ShotFailCountCondition]
// sym: ?vfunc_6@ShotFailCountCondition@ai@hulkfight@fn_0012b7e0@@UAE_NPAXPAUAgent_12b7e0@4@0@Z @0aa705de28b0 @w862d3e4c8633
namespace fn_0012b7e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// hulkfight::ai::ShotFailCountCondition::vfunc_6 @ 0x0012b7e0
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C++" __declspec(nothrow) void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct State_12b7e0 { char pad[0x1d1c]; int shotFailCount; };
struct AgentData { State_12b7e0* FUN_00059a30(); };
struct Agent_12b7e0 { AgentData* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct ShotFailCountCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Agent_12b7e0*, void*);
 char pad[8]; unsigned comparison; float threshold;
};
bool ShotFailCountCondition::vfunc_6(void*, Agent_12b7e0* agent, void*) {
 if (!FUN_00344e74(agent,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 int count = agent->FUN_000592a0()->FUN_00059a30()->shotFailCount;
 switch(comparison) {
 case 0: return (double)count < threshold;
 case 1: return (double)count <= threshold;
 case 2: return (double)count == threshold;
 case 3: return (double)count != threshold;
 case 4: return (double)count >= threshold;
 case 5: return (double)count > threshold;
 default: return false;
 }
}
}}
} // namespace fn_0012b7e0


// 0x0012b8e0 hulkfight::ai::ThreatBallAction::vfunc_3 (48 B): matches/0x0012b8e0.cpp
// sym: ?vfunc_3@ThreatBallAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::ThreatBallAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    if (!this->f_20)
        return false;
    Obj_12b8e0* o = hulk_at_004dd700->inner->obj8;
    this->f_24 = o->Fn_00067b00(this->f_1c + 0x30);
    return true;
}


// 0x0012b910 hulkfight::ai::ThreatBallAction::vfunc_5 (362 B): equivalent/0x0012b910.cpp
// sym: ?vfunc_5@ThreatBallAction@ai@hulkfight@@UAE_NHH@Z @bf9fd3559550 @w8e34778d4d4c
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 17/18, incomplete)
// hulkfight::ai::ThreatBallAction::vfunc_5 @ 0x0012b910
bool hulkfight::ai::ThreatBallAction::vfunc_5(hulk_intptr msg, int unused) {
    if (msg == 1) {
        Sink_12b910 *sink = DAT_004dd700->holder->sink;
        Stats_12b910 *stats = FUN_00059a30(FUN_000592a0((*(Owner_12b910 * *)&this->f_20)));
        int slot = (*(Data_12b910 * *)&this->f_1c)->slot;
        Skeleton_12b910 *skel = stats->skeleton;
        Attach_12b910 *att = 0;
        unsigned int joint = 0;
        if (slot >= 0 && slot < 8) {
            att = ((Attach_12b910 *)((owners::C_35ef0 *)stats)->FUN_00035ef0((hulk_intptr)slot));
            if (att != 0) skel = att->FUN_001d68d0();
        }
        if (skel != 0) {
            JointFinder_12b910 *finder = skel->finder;
            if (((*(Data_12b910 * *)&this->f_1c)->f18 | (*(Data_12b910 * *)&this->f_1c)->f1c) != 0) {
                joint = finder->FUN_0027b200((*(Data_12b910 * *)&this->f_1c)->f18, (*(Data_12b910 * *)&this->f_1c)->f1c);
                if (joint == 0xffff) joint = 0;
            }
        }
        Vec3_12b910 world;
        Mat_12b910 M;
        world.x = 0; world.y = 0; world.z = 0;
        if (skel != 0) {
            Mat_12b910 *src = skel->matrices + joint;
            if (att != 0) {
                ((owners::Matrix_22ca90 *)&M)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat_12b910 *)src, (const owners::Matrix_22ca90 *)(hulk_uintptr)(int)(att->v15()));
            } else {
                M = *src;
            }
            Vec3_12b910 local = (*(Data_12b910 * *)&this->f_1c)->offset;
            ((owners::Mat_22c2b0 *)&M)->FUN_0022c2b0((float *)(const Vec3_12b910 *)(&local), (float *)(Vec3_12b910 *)(&world));
        }
        Request_12b910 req;
        req.FUN_00067e20();
        req.source = (*(Owner_12b910 * *)&this->f_20)->f08;
        req.pos = world;
        req.extra = (*(Data_12b910 * *)&this->f_1c)->f2c;
        sink->FUN_00067c30(this->f_24, &req);
        req.FUN_000679c0();
    }
    return true;
}


// 0x0012ba80 hulkfight::ai::ThreatBallAction::vfunc_4 (44 B): matches/0x0012ba80.cpp
// sym: ?vfunc_4@ThreatBallAction@ai@hulkfight@@UAEXXZ
void hulkfight::ai::ThreatBallAction::vfunc_4() {
    g_12ba80->inner->p->call_00067c80(this->f_24);
    this->f_24 = 0;
    FUN_000678d0()->tail_00065c10();
}


// 0x0012bab0 hulkfight::ai::ThreatDodgeAction::vfunc_5 (271 B): equivalent/0x0012bab0.cpp
// sym: ?vfunc_5@ThreatDodgeAction@ai@hulkfight@@UAE_NHH@Z @e4e3efad51d7 @w29353f2efe93
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// hulkfight::ai::ThreatDodgeAction::vfunc_5 @ 0x0012bab0
bool hulkfight::ai::ThreatDodgeAction::vfunc_5(hulk_intptr __p0, int __p1) { unsigned int state = (unsigned int)__p0; unsigned int unused = (unsigned int)__p1;

 if (state != 0) return true;
 if (!(*(Link_12bab0 * *)&this->f_20)) return false;
 Actor_12bab0* actor = ((Link2_12bab0 *)((owners::Object_592a0 *)((*(Link_12bab0 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
 unsigned int flag = (state & 0xffffff00u) | (*(Settings_12bab0 * *)&this->f_1c)->flag;
 if (actor->FUN_00037080((*(Settings_12bab0 * *)&this->f_1c)->data, flag)) {
 Vec_12bab0 reference = actor->reference;
 Vec_12bab0 position; position.x=0; position.y=0; position.z=0;
 actor->position->FUN_00059a50(&position);
 Vec_12bab0 direction; direction.x=position.x-reference.x; direction.y=0; direction.z=position.z-reference.z;
 direction.FUN_0022d110();
 actor->direction=direction;
 actor->direction2=direction;
 actor->mode=(*(Settings_12bab0 * *)&this->f_1c)->mode;
 }
 return true;
}

namespace fn_f9c2e0ac {

// 0x0012bc00 hulkfight::ai::ThreatCondition::vfunc_5 (46 B): matches/0x0012bc00.cpp
// sym: ?vfunc_5@ThreatCondition@fn_f9c2e0ac@@QAEPAV12@E@Z
ThreatCondition* ThreatCondition::vfunc_5(unsigned char param) {
    ThreatCondition* p = this;
    *(char**)p = &hulk_at_00410bd4;
    ((ThreatDistanceCondition_12bc00*)((char*)p + 0x10))->f1_0027af50();
    ((ThreatDistanceCondition_12bc00*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((ThreatDistanceCondition_12bc00*)p);
    return p;
}


// 0x0012bc30 hulkfight::ai::ThreatDistanceCondition::vfunc_5 (46 B): matches/0x0012bc30.cpp
// sym: ?Del@ThreatDistanceCondition_12bc30@fn_f9c2e0ac@@QAEPAXE@Z
void* ThreatDistanceCondition_12bc30::Del(unsigned char flags) {
    vptr = g_vftable_12bc30;
    s.Init_0027af50();
    Fin_002345b0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x0012bc60 hulkfight::ai::ThreatAngleCondition::vfunc_5 (46 B): matches/0x0012bc60.cpp
// sym: ?vfunc_5@ThreatAngleCondition@fn_f9c2e0ac@@QAEPAU12@H@Z
ThreatAngleCondition* ThreatAngleCondition::vfunc_5(int flag) {
    vf = vtable_12bc60;
    sub.FnF_0027af50();
    Second_002345b0();
    if (flag & 1)
        Cleanup_0008d330(this);
    return this;
}


// 0x0012bc90 hulkfight::ai::ShotFailCountCondition::vfunc_5 (36 B): matches/0x0012bc90.cpp
// sym: ?vfunc_5@ShotFailCountCondition_12bc90@fn_f9c2e0ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ShotFailCountCondition_12bc90* ShotFailCountCondition_12bc90::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00410c34;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f9c2e0ac

// 0x0012bcc0 hulkfight::ai::ThreatBallTrack::vfunc_5 (54 B): matches/0x0012bcc0.cpp [wrapped: conflict: ThreatBallTrack]
// sym: ?vfunc_5@ThreatBallTrack@fn_0012bcc0@@QAEPAU12@I@Z
namespace fn_0012bcc0 {
struct Helper_12bcc0 {
    void run_0027af50();
};
struct ThreatBallTrack {
    void* vptr;
    char pad04[0x14];
    Helper_12bcc0 h18;
    char pad1d[0x17];
    Helper_12bcc0 h30;
    ThreatBallTrack* other_00236d60();
    ThreatBallTrack* vfunc_5(unsigned int);
};
extern void* threat_vftable_12bcc0;
void destroy_0008d330(ThreatBallTrack*);
ThreatBallTrack* ThreatBallTrack::vfunc_5(unsigned int flags) {
    vptr = &threat_vftable_12bcc0;
    h30.run_0027af50();
    h18.run_0027af50();
    other_00236d60();
    if (flags & 1)
        destroy_0008d330(this);
    return this;
}
} // namespace fn_0012bcc0

namespace fn_f9c2e0ac {

// 0x0012bd00 hulkfight::ai::ThreatDodgeTrack::vfunc_5 (46 B): matches/0x0012bd00.cpp
// sym: ?vfunc_5@ThreatDodgeTrack@fn_f9c2e0ac@@UAEPAV12@E@Z
ThreatDodgeTrack* ThreatDodgeTrack::vfunc_5(unsigned char flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_00410c84);
    ((Helper_12bd00*)((char*)this + 0x20))->call1_0027af50();
    ((Helper_12bd00*)this)->call2_00236d60();
    if (flags & 1)
        FUN_0008d330(this);
    return this;
}

} // namespace fn_f9c2e0ac

// 0x0012bd30 hulkfight::ai::ThreatAngleCondition::vfunc_6 (283 B): equivalent/0x0012bd30.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60; hulkfight::ai::ThreatAngleCondition]
// sym: ?vfunc_6@ThreatAngleCondition@ai@hulkfight@fn_0012bd30@@UAE_NHPAUContext@4@H@Z @b5ff1be4e72b @w6c4885615950
namespace fn_0012bd30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::ai::ThreatAngleCondition::vfunc_6 @ 0x0012bd30
struct TypeInfo; extern TypeInfo DAT_00494b44; extern TypeInfo DAT_00494b60;
extern "C++" __declspec(nothrow) void* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
struct Vector { float x,y,z; };
extern hulk_freg __cdecl FUN_00224f10(Vector*);
extern hulk_freg __cdecl FUN_00224fc0(float,float);
struct Entity { void FUN_00059a50(Vector*); };
struct Threat_12bd30 { char pad[0x10]; Entity* entity; char pad2[0x22a0-0x14]; Vector position; bool FUN_00037080(void*,unsigned int); hulk_freg FUN_000354c0(); };
struct Owner_12bd30 { Threat_12bd30* FUN_00059a30(); };
struct Context { Owner_12bd30* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct ThreatAngleCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int,Context*,int);
 char pad[8]; float offset; float width; char pad2[4]; unsigned int selection[2]; unsigned char flag;
};
bool ThreatAngleCondition::vfunc_6(int unused1,Context* context,int unused2) {
 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Threat_12bd30* threat=context->FUN_000592a0()->FUN_00059a30();
 if (!threat->FUN_00037080(selection,flag)) return false;
 Vector target=threat->position;
 Vector origin; origin.x=origin.y=origin.z=0.0f;
 threat->entity->FUN_00059a50(&origin);
 Vector delta; delta.x=target.x-origin.x; delta.y=target.y-origin.y; delta.z=target.z-origin.z;
 float angle=FUN_00224f10(&delta);
 float shifted=threat->FUN_000354c0()+offset;
 angle=FUN_00224fc0(shifted,angle);
 union { float f; unsigned int u; } absolute; absolute.f=angle; absolute.u &= 0x7fffffff;
 return width*0.5f > absolute.f;
}
}}
} // namespace fn_0012bd30


// 0x0012be50 hulkfight::ai::ThreatDistanceCondition::vfunc_6 (392 B): equivalent/0x0012be50.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60]
// sym: ?vfunc_6@ThreatDistanceCondition@fn_0012be50@@UAEDHPAUOwner_12be50@2@H@Z @4b59a85ab528 @w2fde08bcb339
namespace fn_0012be50 {
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 16/18, incomplete)
// hulkfight::ai::ThreatDistanceCondition::vfunc_6 @ 0x0012be50

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif

extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern "C" char FUN_00018960(float a, float b, float eps);

struct Vec3_12be50 {
    float x, y, z;
};

struct Locator {
    void FUN_00059a50(Vec3_12be50 *out);
};

struct Actor_12be50 {
    char pad0[0x10];
    Locator *locator;
    char pad14[0x22a0 - 0x14];
    Vec3_12be50 pos;
    char FUN_00037080(char *a, int b);
};

struct Chain_12be50 {
    Actor_12be50 *FUN_00059a30();
};

struct Owner_12be50 {
};

class ThreatDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner_12be50 *owner, int unused3);
    char pad4[8];
    unsigned int mode;
    float threshold;
    char pad14[4];
    char key[8];
    unsigned char keyFlag;
};

char ThreatDistanceCondition::vfunc_6(int unused1, Owner_12be50 *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Actor_12be50 *actor = ((Chain_12be50 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    if (!actor->FUN_00037080(key, keyFlag))
        return 0;

    Vec3_12be50 target = actor->pos;
    Vec3_12be50 mine;
    mine.x = 0;
    mine.y = 0;
    mine.z = 0;
    actor->locator->FUN_00059a50(&mine);

    float dx = target.x - mine.x;
    float dy = target.y - mine.y;
    float dz = target.z - mine.z;
    float dist = (float)sqrt((double)(dz * dz + dy * dy + dx * dx));

    switch (mode) {
    case 0:
        return dist < threshold;
    case 1:
        return dist <= threshold;
    case 2:
        return FUN_00018960(dist, threshold, 1e-5f);
    case 3:
        return !FUN_00018960(dist, threshold, 1e-5f);
    case 4:
        return dist >= threshold;
    case 5:
        return dist > threshold;
    }
    return 0;
}
} // namespace fn_0012be50

namespace fn_f9c2e0ac {

// 0x0012bff0 FUN_0012bff0 (79 B): matches/0x0012bff0.cpp
// sym: ??0ThreatBallAction@fn_f9c2e0ac@@QAE@HPAVRef@1@@Z
ThreatBallAction::ThreatBallAction(int v, Ref* q) : Action_12bff0() {
    m.a = v;
    if (q)
        q->Add();
    if (m.p)
        m.p->Release();
    m.p = q;
}


// 0x0012c040 FUN_0012c040 (50 B): matches/0x0012c040.cpp
// sym: ??1ThreatBallAction_12c040@fn_f9c2e0ac@@QAE@XZ
ThreatBallAction_12c040::~ThreatBallAction_12c040() {
    vptr = hulk_at_00410cb4;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_12c040 *)this)->FUN_002326a0();
}


// 0x0012c080 FUN_0012c080 (72 B): matches/0x0012c080.cpp
// sym: ??0ThreatDodgeAction_12c080@fn_f9c2e0ac@@QAE@HPAVRefObj_12c080@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
ThreatDodgeAction_12c080::ThreatDodgeAction_12c080(int target, RefObj_12c080* obj) {
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


// 0x0012c0d0 FUN_0012c0d0 (50 B): matches/0x0012c0d0.cpp
// sym: ??1ThreatDodgeAction_12c0d0@fn_f9c2e0ac@@QAE@XZ
ThreatDodgeAction_12c0d0::~ThreatDodgeAction_12c0d0() {
    vptr = hulk_at_00410cd0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_12c0d0 *)this)->FUN_002326a0();
}

} // namespace fn_f9c2e0ac

// 0x0012c130 fight::ParamBool<hulkfight::ai::ThreatCondition>::vfunc_6 (26 B): matches/0x0012c130.cpp
// sym: ?vfunc_6@?$ParamBool@VThreatCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ThreatCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::ThreatCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::ThreatCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::ThreatCondition>::**)(int))&this->f_10))(b);
}


// 0x0012c150 fight::ParamBool<hulkfight::ai::ThreatCondition>::vfunc_2 (11 B): matches/0x0012c150.cpp
// sym: ?vfunc_2@?$ParamBool@VThreatCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ThreatCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c190 fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::vfunc_7 (6 B): matches/0x0012c190.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0012c1a0 fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::vfunc_6 (30 B): matches/0x0012c1a0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_12c1a0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_12c1a0*)&DAT_003f335c));
}


// 0x0012c1c0 fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::vfunc_8 (26 B): matches/0x0012c1c0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::**)(int))&this->f_18))(b);
}


// 0x0012c1e0 fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::vfunc_2 (11 B): matches/0x0012c1e0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0012c210 fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>::vfunc_6 (26 B): matches/0x0012c210.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x0012c230 fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>::vfunc_2 (11 B): matches/0x0012c230.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c260 fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::vfunc_6 (26 B): matches/0x0012c260.cpp
// sym: ?vfunc_6@?$ParamBool@VThreatCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x0012c280 fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::vfunc_2 (11 B): matches/0x0012c280.cpp
// sym: ?vfunc_2@?$ParamBool@VThreatCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c2b0 fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>::vfunc_6 (26 B): matches/0x0012c2b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>::**)(int))&this->f_10))(b);
}


// 0x0012c2d0 fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>::vfunc_2 (11 B): matches/0x0012c2d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c300 fight::ParamBool<hulkfight::ai::ThreatAngleCondition>::vfunc_6 (26 B): matches/0x0012c300.cpp
// sym: ?vfunc_6@?$ParamBool@VThreatCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ThreatAngleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::ThreatAngleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::ThreatAngleCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::ThreatAngleCondition>::**)(int))&this->f_10))(b);
}


// 0x0012c320 fight::ParamBool<hulkfight::ai::ThreatAngleCondition>::vfunc_2 (11 B): matches/0x0012c320.cpp
// sym: ?vfunc_2@?$ParamBool@VThreatCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ThreatAngleCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c360 fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::vfunc_7 (6 B): matches/0x0012c360.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0012c370 fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::vfunc_6 (30 B): matches/0x0012c370.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_12c370 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_12c370*)&DAT_003f335c));
}


// 0x0012c390 fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::vfunc_8 (26 B): matches/0x0012c390.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::**)(int))&this->f_18))(b);
}


// 0x0012c3b0 fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::vfunc_2 (11 B): matches/0x0012c3b0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0012c3e0 fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>::vfunc_6 (26 B): matches/0x0012c3e0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>::**)(int))&this->f_10))(b);
}


// 0x0012c400 fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>::vfunc_2 (11 B): matches/0x0012c400.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c430 fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_6 (26 B): matches/0x0012c430.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>::**)(int))&this->f_10))(b);
}


// 0x0012c450 fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_2 (11 B): matches/0x0012c450.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c480 fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_6 (26 B): matches/0x0012c480.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VThreatBallTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>::**)(int))&this->f_10))(b);
}


// 0x0012c4a0 fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_2 (11 B): matches/0x0012c4a0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VThreatBallTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c4d0 fight::ParamVector<hulkfight::ai::ThreatBallTrack>::vfunc_6 (26 B): matches/0x0012c4d0.cpp
// sym: ?vfunc_6@?$ParamVector@VThreatBallTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::ThreatBallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::ThreatBallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::ThreatBallTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::ThreatBallTrack>::**)(int))&this->f_10))(b);
}


// 0x0012c4f0 fight::ParamVector<hulkfight::ai::ThreatBallTrack>::vfunc_2 (11 B): matches/0x0012c4f0.cpp
// sym: ?vfunc_2@?$ParamVector@VThreatBallTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::ThreatBallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c520 fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>::vfunc_6 (26 B): matches/0x0012c520.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>::**)(int))&this->f_10))(b);
}


// 0x0012c540 fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>::vfunc_2 (11 B): matches/0x0012c540.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c570 fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>::vfunc_6 (26 B): matches/0x0012c570.cpp
// sym: ?vfunc_6@?$ParamBool@VThreatCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>::**)(int))&this->f_10))(b);
}


// 0x0012c590 fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>::vfunc_2 (11 B): matches/0x0012c590.cpp
// sym: ?vfunc_2@?$ParamBool@VThreatCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012c5b0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatCondition>::vfunc_0 (36 B): matches/0x0012c5b0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VThreatCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatCondition>::vfunc_0(void* __p0) { Object_12c5b0 * p = (Object_12c5b0 *)__p0;

    return DynamicCast(p, 0, &hulk_at_00491ca8, &hulk_at_004a9438, 0) != 0;
}


// 0x0012c5e0 fight::ParamBool<hulkfight::ai::ThreatCondition>::vfunc_0 (30 B): matches/0x0012c5e0.cpp
// sym: ??_G?$ParamBool@VThreatCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::ThreatCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::ThreatCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c5e0)
#endif


// 0x0012c610 fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatDistanceCondition>::vfunc_0 (36 B): matches/0x0012c610.cpp [wrapped: conflict: a; fight::ConditionFactoryCaster]
// sym: ?vfunc_0@ThreatCaster@fight@fn_0012c610@@UAEHPAX@Z
namespace fn_0012c610 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C++" __declspec(nothrow) int FUN_00344e74(void*, int, void*, void*, int);
extern int a, hulk_at_004a94e8;
namespace fight {
class ThreatCaster : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int ThreatCaster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &hulk_at_004a94e8, 0) != 0;
}
} // namespace fight
} // namespace fn_0012c610


// 0x0012c640 fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::vfunc_0 (30 B): matches/0x0012c640.cpp
// sym: ??_G?$ParamEnumConstList@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::ThreatDistanceCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c640)
#endif


// 0x0012c660 fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>::vfunc_0 (30 B): matches/0x0012c660.cpp
// sym: ??_G?$ParamFloatConstRange@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::ThreatDistanceCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c660)
#endif


// 0x0012c680 fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::vfunc_0 (30 B): matches/0x0012c680.cpp
// sym: ??_G?$ParamBool@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c680)
#endif


// 0x0012c6b0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatAngleCondition>::vfunc_0 (36 B): matches/0x0012c6b0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VThreatAngleCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatAngleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a95a0, 0) != 0;
}


// 0x0012c6e0 fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>::vfunc_0 (30 B): matches/0x0012c6e0.cpp
// sym: ??_G?$ParamFloatConstRange@VThreatAngleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c6e0)
#endif


// 0x0012c700 fight::ParamBool<hulkfight::ai::ThreatAngleCondition>::vfunc_0 (30 B): matches/0x0012c700.cpp
// sym: ??_G?$ParamBool@VThreatAngleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::ThreatAngleCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::ThreatAngleCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c700)
#endif


// 0x0012c730 fight::ConditionFactoryCasterTemplate<hulkfight::ai::ShotFailCountCondition>::vfunc_0 (36 B): matches/0x0012c730.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VShotFailCountCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::ShotFailCountCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_12c730, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0012c760 fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::vfunc_0 (30 B): matches/0x0012c760.cpp
// sym: ??_G?$ParamEnumConstList@VShotFailCountCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::ShotFailCountCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c760)
#endif


// 0x0012c780 fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>::vfunc_0 (30 B): matches/0x0012c780.cpp
// sym: ??_G?$ParamFloatConstRange@VShotFailCountCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::ShotFailCountCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c780)
#endif


// 0x0012c7b0 fight::TrackFactoryCasterTemplate<hulkfight::ai::ThreatBallTrack>::vfunc_0 (36 B): matches/0x0012c7b0.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VThreatBallTrack@ai@hulkfight@fn_0012c7b0@@@fight@fn_0012c7b0@@UAEHPAX@Z
namespace fn_0012c7b0 {
extern "C++" __declspec(nothrow) int __cdecl helper(void*, int, void*, void*, int);
extern void* hulk_at_0049850c;
extern void* hulk_at_004a9708;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class ThreatBallTrack;
}
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::ai::ThreatBallTrack>::vfunc_0(void* x) {
    return helper(x, 0, &hulk_at_0049850c, &hulk_at_004a9708, 0) != 0;
}
} // namespace fn_0012c7b0


// 0x0012c7e0 fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_0 (30 B): matches/0x0012c7e0.cpp
// sym: ??_G?$ParamFloatConstRange@VThreatBallTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c7e0)
#endif


// 0x0012c800 fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_0 (30 B): matches/0x0012c800.cpp
// sym: ??_G?$ParamIntConstRange@VThreatBallTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::ai::ThreatBallTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c800)
#endif


// 0x0012c820 fight::ParamVector<hulkfight::ai::ThreatBallTrack>::vfunc_0 (30 B): matches/0x0012c820.cpp
// sym: ??_G?$ParamVector@VThreatBallTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::ai::ThreatBallTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::ai::ThreatBallTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c820)
#endif


// 0x0012c850 fight::TrackFactoryCasterTemplate<hulkfight::ai::ThreatDodgeTrack>::vfunc_0 (36 B): matches/0x0012c850.cpp [wrapped: conflict: a]
// sym: ?vfunc_0@Caster@fn_0012c850@@UAE_NPAX@Z
namespace fn_0012c850 {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ThreatDodgeTrack;
extern "C++" __declspec(nothrow) int FUN_00344e74(void*, void*, void*, void*, void*);
extern int a, hulk_at_004a97b0;
class Caster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
bool Caster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &hulk_at_004a97b0, 0) != 0;
}
} // namespace fn_0012c850


// 0x0012c880 fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>::vfunc_0 (30 B): matches/0x0012c880.cpp
// sym: ??_G?$ParamFloatConstRange@VThreatDodgeTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::ThreatDodgeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c880)
#endif


// 0x0012c8a0 fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>::vfunc_0 (30 B): matches/0x0012c8a0.cpp
// sym: ??_G?$ParamBool@VThreatDodgeTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::ThreatDodgeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12c8a0)
#endif


// 0x0012c970 hulkfight::ai::ThreatBallTrack::vfunc_10 (70 B): matches/0x0012c970.cpp
// sym: ?vfunc_10@ThreatBallTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ThreatBallTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_12c970 a = (u32_12c970)__p0; u32_12c970 b = (u32_12c970)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&TypeA_12c970), (void*)(&TypeB_12c970), 0))) {
        Result_12c970* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(q->Init_0012bff0(this, p));
    }
    return (int)(0);
}

namespace fn_f9c2e0ac {

// 0x0012c9c0 hulkfight::ai::ThreatBallAction::vfunc_2 (71 B): matches/0x0012c9c0.cpp
// sym: ?vfunc_2@ThreatBallAction_12c9c0@fn_f9c2e0ac@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
ThreatBallAction_12c9c0* ThreatBallAction_12c9c0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_12c9c0;
    RefCounted_12c9c0* q = *(RefCounted_12c9c0* volatile*)&m_20;
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


// 0x0012ca60 hulkfight::ai::ThreatDodgeAction::vfunc_2 (71 B): matches/0x0012ca60.cpp
// sym: ?vfunc_2@ThreatDodgeAction_12ca60@fn_f9c2e0ac@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
ThreatDodgeAction_12ca60* ThreatDodgeAction_12ca60::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_12ca60;
    RefCounted_12ca60* q = *(RefCounted_12ca60* volatile*)&m_20;
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


// 0x0012caf0 fight::ParamName<hulkfight::ai::ThreatCondition>::vfunc_7 (12 B): matches/0x0012caf0.cpp
// sym: ?vfunc_6@ParamBranch@fn_f9c2e0ac@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f9c2e0ac

// 0x0012cb40 fight::ParamName<hulkfight::ai::ThreatDistanceCondition>::vfunc_7 (12 B): matches/0x0012cb40.cpp [wrapped: same definition as 0x0012caf0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0012cb40@@UAEXPAX@Z
namespace fn_0012cb40 {
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
} // namespace fn_0012cb40


// 0x0012cb90 fight::ParamName<hulkfight::ai::ThreatAngleCondition>::vfunc_7 (12 B): matches/0x0012cb90.cpp [wrapped: same definition as 0x0012caf0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0012cb90@@UAEXPAX@Z
namespace fn_0012cb90 {
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
} // namespace fn_0012cb90


// 0x0012cc00 fight::ParamNameConstList<hulkfight::ai::ThreatBallTrack>::vfunc_7 (12 B): matches/0x0012cc00.cpp [wrapped: same definition as 0x0012caf0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0012cc00@@UAEXPAX@Z
namespace fn_0012cc00 {
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
} // namespace fn_0012cc00


// 0x0012cc30 fight::ParamName<hulkfight::ai::ThreatBallTrack>::vfunc_7 (12 B): matches/0x0012cc30.cpp [wrapped: same definition as 0x0012caf0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0012cc30@@UAEXPAX@Z
namespace fn_0012cc30 {
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
} // namespace fn_0012cc30


// 0x0012cc80 fight::ParamName<hulkfight::ai::ThreatDodgeTrack>::vfunc_7 (12 B): matches/0x0012cc80.cpp [wrapped: same definition as 0x0012caf0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0012cc80@@UAEXPAX@Z
namespace fn_0012cc80 {
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
} // namespace fn_0012cc80


// 0x0012cc90 fight::ParamName<hulkfight::ai::ThreatCondition>::vfunc_0 (30 B): matches/0x0012cc90.cpp
// sym: ??_G?$ParamName@VThreatCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::ThreatCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::ai::ThreatCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12cc90)
#endif


// 0x0012ccb0 fight::ParamName<hulkfight::ai::ThreatDistanceCondition>::vfunc_0 (30 B): matches/0x0012ccb0.cpp
// sym: ??_G?$ParamName@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::ThreatDistanceCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::ai::ThreatDistanceCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12ccb0)
#endif


// 0x0012ccd0 fight::ParamName<hulkfight::ai::ThreatAngleCondition>::vfunc_0 (30 B): matches/0x0012ccd0.cpp
// sym: ??_G?$ParamName@VThreatAngleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::ThreatAngleCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::ai::ThreatAngleCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12ccd0)
#endif


// 0x0012ccf0 fight::ParamNameConstList<hulkfight::ai::ThreatBallTrack>::vfunc_0 (30 B): matches/0x0012ccf0.cpp
// sym: ??_G?$ParamNameConstList@VThreatBallTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::ai::ThreatBallTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::ai::ThreatBallTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12ccf0)
#endif


// 0x0012cd10 fight::ParamName<hulkfight::ai::ThreatBallTrack>::vfunc_0 (30 B): matches/0x0012cd10.cpp
// sym: ??_G?$ParamName@VThreatBallTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::ThreatBallTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::ai::ThreatBallTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12cd10)
#endif


// 0x0012cd30 fight::ParamName<hulkfight::ai::ThreatDodgeTrack>::vfunc_0 (30 B): matches/0x0012cd30.cpp
// sym: ??_G?$ParamName@VThreatDodgeTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::ThreatDodgeTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::ai::ThreatDodgeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12cd30)
#endif

namespace fn_f9c2e0ac {

// 0x0012cd80 FUN_0012cd80 (213 B): matches/0x0012cd80.cpp
// sym: ?FUN_0012cd80@fn_f9c2e0ac@@YAXXZ
void FUN_0012cd80() {
    if (!DAT_004e0e18) {
        void* params[3];
        Base_12cd80* mem = (Base_12cd80*)FUN_0008d690((int)sizeof(fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>));
        if (mem) {
            ((fight::ParamValueBool *)(Base_12cd80 *)mem)->FUN_00234860("threat");
            fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>* p =
                new (mem) fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>;
            p->callback = SetThreat_0012b190;
            params[0] = p;
        } else
            params[0] = 0;
        mem = (Base_12cd80*)FUN_0008d690((int)sizeof(fight::ParamName_12cd80<hulkfight::ai::ThreatCondition_12cd80>));
        if (mem) {
            ((fight::ParamValueName *)(Base_12cd80 *)mem)->FUN_00234a90("threatName");
            fight::ParamName_12cd80<hulkfight::ai::ThreatCondition_12cd80>* p =
                new (mem) fight::ParamName_12cd80<hulkfight::ai::ThreatCondition_12cd80>;
            p->callback = GetThreatName_0012b1a0;
            params[1] = p;
        } else
            params[1] = 0;
        mem = (Base_12cd80*)FUN_0008d690((int)sizeof(fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>));
        if (mem) {
            ((fight::ParamValueBool *)(Base_12cd80 *)mem)->FUN_00234860("threatRespondOnlyOnce");
            fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>* p =
                new (mem) fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>;
            p->callback = SetThreatRespondOnlyOnce_0012b1b0;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004e0e14, params, 3);
    }
    ++DAT_004e0e18;
}

} // namespace fn_f9c2e0ac

// 0x0012ce90 FUN_0012ce90 (274 B): equivalent/0x0012ce90.cpp [wrapped: conflict: fight::ParamBool; fight::ParamEnumConstList; fight::ParamFloatConstRange; fight::ParamName]
// sym: ?initialize@fn_0012ce90@@YAXXZ @29bd5ba07162 @w68739595bb52
namespace fn_0012ce90 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 10/10)
// FUN_0012ce90 @ 0x0012ce90


extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl SetCompare_0012b1c0();
extern "C" void __cdecl SetDistance_0012b1d0();
extern "C" void __cdecl GetThreatName_0012b1e0();
extern "C" void __cdecl SetThreatRespondOnlyOnce_0012b1f0();
extern "C++" __declspec(nothrow) void __cdecl FUN_002347b0(void*,void**,int);
namespace hulkfight { namespace ai { class ThreatDistanceCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot(); char pad[12]; const char* values; int count; void (__cdecl *callback)(); int end; void FUN_00234cc0(const char*); };
template<class T> struct ParamFloatConstRange { virtual void slot(); char pad[12]; void (__cdecl *callback)(); int end; void FUN_00234960(const char*); };
template<class T> struct ParamName { virtual void slot(); char pad[12]; void (__cdecl *callback)(); int end; void FUN_00234a90(const char*); };
template<class T> struct ParamBool { virtual void slot(); char pad[12]; void (__cdecl *callback)(); int end; void FUN_00234860(const char*); };
}
void initialize() {
 if (DAT_004e0e20 == 0) {
 void* params[4];
 typedef hulkfight::ai::ThreatDistanceCondition T;
 fight::ParamEnumConstList<T>* a=(fight::ParamEnumConstList<T>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<T>));
 if(a) { int count=(*(int*)&DAT_00427754); a->FUN_00234cc0("compare"); new (a) fight::ParamEnumConstList<T>; a->count=count; a->values="lwB"; a->callback=SetCompare_0012b1c0; }
 params[0]=a;
 fight::ParamFloatConstRange<T>* b=(fight::ParamFloatConstRange<T>*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<T>));
 if(b) { b->FUN_00234960("distance"); new (b) fight::ParamFloatConstRange<T>; b->callback=SetDistance_0012b1d0; } params[1]=b;
 fight::ParamName<T>* c=(fight::ParamName<T>*)FUN_0008d690((int)sizeof(fight::ParamName<T>));
 if(c) { c->FUN_00234a90("threatName"); new (c) fight::ParamName<T>; c->callback=GetThreatName_0012b1e0; } params[2]=c;
 fight::ParamBool<T>* d=(fight::ParamBool<T>*)FUN_0008d690((int)sizeof(fight::ParamBool<T>));
 if(d) { d->FUN_00234860("threatRespondOnlyOnce"); new (d) fight::ParamBool<T>; d->callback=SetThreatRespondOnlyOnce_0012b1f0; } params[3]=d;
 FUN_002347b0(&DAT_004e0e1c,params,4);
 }
 ++DAT_004e0e20;
}
} // namespace fn_0012ce90

namespace fn_f9c2e0ac {

// 0x0012d0e0 FUN_0012d0e0 (38 B): matches/0x0012d0e0.cpp
// sym: ?target@fn_f9c2e0ac@@YAXPAUObj_12d0e0@1@I@Z
void __cdecl target(Obj_12d0e0* a, u32_12d0e0 b) {
    Factory_12d0e0 local;
    local.vft = ((hulk_intptr)DAT_00410ec0);
    u32_12d0e0 x = FUN_002343e0(b, &local);
    a->Fn_00236760(x);
}


// 0x0012d110 FUN_0012d110 (38 B): matches/0x0012d110.cpp
// sym: _FUN_0012d110
extern "C" void* __cdecl FUN_0012d110(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_12d110 caster;
    void* found = FUN_00236ac0(name, &caster);
    return obj->finish_002367c0(found);
}


// 0x0012d2e0 FUN_0012d2e0 (38 B): matches/0x0012d2e0.cpp
// sym: _FUN_0012d2e0
extern "C" void FUN_0012d2e0(Obj* o, void* p) {
    TrackFactoryCasterTemplate_12d2e0 c;
    o->apply_002367c0(find(p, &c));
}

} // namespace fn_f9c2e0ac

// 0x0012d450 FUN_0012d450 (145 B): matches/0x0012d450.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_0012d450
namespace fn_0012d450 {
// FUN_0012d450 @ 0x0012d450
namespace hulkfight { namespace ai { class ThreatCondition; class ThreatDistanceCondition; class ThreatAngleCondition; class ShotFailCountCondition; } }
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry_12d450 { void FUN_00236760(void*); };
void* __cdecl FUN_002343e0(const char*, void*);
extern "C" void __cdecl FUN_0012d450(Registry_12d450* r)
{
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatCondition> caster;
        r->FUN_00236760(FUN_002343e0("threat", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatAngleCondition> caster;
        r->FUN_00236760(FUN_002343e0("threatAngle", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatDistanceCondition> caster;
        r->FUN_00236760(FUN_002343e0("threatDistance", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::ShotFailCountCondition> caster;
        r->FUN_00236760(FUN_002343e0("shotFailCount", &caster));
    }
}
} // namespace fn_0012d450

namespace fn_f9c2e0ac {

// 0x0012d530 fight::ConditionFactoryTemplate<hulkfight::ai::ShotFailCountCondition>::vfunc_5 (54 B): matches/0x0012d530.cpp
// sym: ?target@fn_f9c2e0ac@@YAPAUThreatDistanceCondition_12d530@1@XZ
ThreatDistanceCondition_12d530* target() {
    ThreatDistanceCondition_12d530* p = (ThreatDistanceCondition_12d530*)alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        p->vt = (void*)((hulk_intptr)DAT_00410c34);
        p->c = 0;
        p->d = 1.0f;
        return p;
    }
    return 0;
}


// 0x0012d570 fight::ConditionFactoryTemplate<hulkfight::ai::ShotFailCountCondition>::vfunc_2 (43 B): matches/0x0012d570.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12d570@fn_f9c2e0ac@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12d570::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041101c;
    base1_dtor_0012b530();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}


// 0x0012d620 fight::ConditionFactoryTemplate<hulkfight::ai::ThreatCondition>::vfunc_2 (43 B): matches/0x0012d620.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12d620@fn_f9c2e0ac@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12d620::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411038;
    base1_dtor_0012b3b0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9c2e0ac

// 0x0012d690 fight::ConditionFactoryTemplate<hulkfight::ai::ThreatDistanceCondition>::vfunc_5 (66 B): matches/0x0012d690.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VThreatDistanceCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::ThreatDistanceCondition>::vfunc_5() {
    ThreatDistanceCondition_12d690* p = (ThreatDistanceCondition_12d690*)Alloc_0008d690(0x28);
    if (p) {
        p->Init_00234590(0);
        p->vf = ((hulk_intptr)DAT_00410bf4);
        p->mC = 0;
        p->mD = 0;
        p->sub.Setup_0027af00();
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f9c2e0ac {

// 0x0012d6e0 fight::ConditionFactoryTemplate<hulkfight::ai::ThreatDistanceCondition>::vfunc_2 (43 B): matches/0x0012d6e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12d6e0@fn_f9c2e0ac@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12d6e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411054;
    base1_dtor_0012b430();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}


// 0x0012d750 fight::ConditionFactoryTemplate<hulkfight::ai::ThreatAngleCondition>::vfunc_5 (66 B): matches/0x0012d750.cpp
// sym: ?factory_vfunc5@fn_f9c2e0ac@@YAPAVThreatAngleCondition_12d750@1@XZ
ThreatAngleCondition_12d750* factory_vfunc5() {
    ThreatAngleCondition_12d750* p = (ThreatAngleCondition_12d750*)alloc28_0008d690(0x28);
    if (p) {
        ((ThreatDistanceCondition_nv_12d750*)(((hulkfight::ai::ThreatDistanceCondition*)(((hulkfight::ai::ThreatDistanceCondition*)p)))))->Init_00234590(0);
        p->vtable = ((hulk_intptr)DAT_00410c14);
        p->c = 0;
        p->f = 0x3fc90fdb;
        p->sub.Init_0027af00();
        p->enabled = 1;
        return p;
    }
    return 0;
}


// 0x0012d7a0 fight::ConditionFactoryTemplate<hulkfight::ai::ThreatAngleCondition>::vfunc_2 (43 B): matches/0x0012d7a0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12d7a0@fn_f9c2e0ac@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12d7a0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411070;
    base1_dtor_0012b4b0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9c2e0ac

// 0x0012d810 fight::TrackFactoryTemplate<hulkfight::ai::ThreatBallTrack>::vfunc_5 (24 B): matches/0x0012d810.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VThreatBallTrack@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fac0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::ThreatBallTrack>::vfunc_5() {
    Track_12d810* p = (Track_12d810*)operator_new(0x38);
    if (p)
        return (void*)(p->method_0012b5d0());
    return (void*)(0);
}

namespace fn_f9c2e0ac {

// 0x0012d830 fight::TrackFactoryTemplate<hulkfight::ai::ThreatBallTrack>::vfunc_2 (43 B): matches/0x0012d830.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f9c2e0ac@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041108c;
    base1_dtor_0012b5a0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9c2e0ac

// 0x0012d8f0 fight::TrackFactoryTemplate<hulkfight::ai::ThreatDodgeTrack>::vfunc_2 (43 B): matches/0x0012d8f0.cpp [wrapped: same definition as 0x0012d830 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0012d8f0@@QAEPAXE@Z
namespace fn_0012d8f0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_004110a8;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0012b670();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004110a8;
    base1_dtor_0012b670();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0012d8f0

