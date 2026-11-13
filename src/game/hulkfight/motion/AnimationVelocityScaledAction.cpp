// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001399d0..0x0013e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::AnimationVelocityScaledAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f30d2d27 {
#define TREE_TU_END }
namespace fn_f30d2d27 {} using namespace fn_f30d2d27;
namespace fn_f30d2d27 { extern "C" char DAT_00412410[], DAT_00412450[], DAT_00412480[], DAT_004124b0[], DAT_004124e0[], DAT_004126cc[], DAT_00412540[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f30d2d27 {
struct Obj_1399f0 {
    char pad[0x10];
    void* Get();
};
class Obj_139a10 {
  public:
    char Pad[0x18];
    int Value;
    char Set(int v);
};
class Obj_139a20 {
  public:
    char pad[0x1c];
    int m;
    bool Set(int x);
};
class Obj_139a50 {
  public:
    virtual void v0();
    char pad[0x14];
    void* Get();
};
class Obj_139bb0 {
  public:
    virtual void V();
    char pad[0x14];
    int field;
    void* Get();
};
class Obj_139e90 {
  public:
    char pad[0x18];
};
struct T_139f90 {
    char pad[0x40];
    void* p;
};
extern int* hulk_at_004e0f08;
class CCondition_13a020 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_00412410[];
struct Sub_13a060 {
    void Fin_0027af50();
};
class Condition_13a060 {
  public:
    void* vptr;
    void Fin_002345b0();
};
class FrameReachedCondition_13a060 : public Condition_13a060 {
  public:
    char pad[0xc];
    Sub_13a060 sub;
    void f();
};
extern int* hulk_at_004e0f10;
class CCondition_13a0a0 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_00412430[];
struct Sub_13a0e0 {
    void Fin_0027af50() throw();
};
class Condition_13a0e0 {
  public:
    void* vptr;
    ~Condition_13a0e0() throw();
};
class FrameCondition_13a0e0 : public Condition_13a0e0 {
  public:
    char pad[0x10 - 4];
    Sub_13a0e0 sub;
    ~FrameCondition_13a0e0() throw();
};
extern int* hulk_at_004e0f18;
class CCondition_13a120 {
  public:
    virtual int vfunc_0(int);
};
class Track_13a130 {
  public:
    virtual void f();
    char pad[8];
    Track_13a130();
};
class Part_13a130 {
  public:
    Part_13a130();
    char pad[8];
};
class AnimationTrack : public Track_13a130 {
  public:
    virtual void f();
    int zero;
    float negative;
    char pad0[4];
    Part_13a130 part1;
    float one;
    int z24, z28;
    float neg2;
    int z30;
    char yes;
    char pad1[3];
    Part_13a130 part2;
    int z40;
    float a, b;
    AnimationTrack();
};
struct Param_13a1a0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_13a1a0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern void* hulk_at_00412450[];
class Str_13a1b0 {
  public:
    void Init_0027af50();
};
class Track_13a1b0 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class AnimationTrack_13a1b0 : public Track_13a1b0 {
  public:
    char pad[0x14];
    Str_13a1b0 s18;
    char pad2[0x1f];
    Str_13a1b0 s38;
    ~AnimationTrack_13a1b0();
};
extern int* hulk_at_004e0f20;
class CCondition_13a200 {
  public:
    virtual int vfunc_0(int);
};
class Track_13a210 {
  public:
    virtual void fn();
    char pad[8];
    Track_13a210();
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class AnimationChargeTrack : public Track_13a210 {
  public:
    int a;
    float b;
    int c;
    Sub one;
    int d;
    float e;
    Sub two;
    int f;
    float g, h;
    AnimationChargeTrack();
    virtual void fn();
};
struct Param_13a270 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_13a270 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
typedef unsigned int u32_13a280;
extern u32_13a280 hulk_at_00412480;
struct Sub_13a280 {
    void Init_0027af50();
};
struct Base_13a280 {
    void Finish_00236d60();
};
extern int* hulk_at_004e0f28;
class CCondition_13a2d0 {
  public:
    virtual int vfunc_0(int);
};
class Track_13a2e0 {
  public:
    virtual void v();
    Track_13a2e0();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class AnimationLinkedTrack : public Track_13a2e0 {
  public:
    virtual void v();
    AnimationLinkedTrack();
    int a;
    float b;
    char gap[4];
    Part p;
    float x, y, z;
    char gap2[4];
    Part q;
    float r, s, t;
};
struct Param_13a350 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_13a350 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int hulk_at_004124b0;
class Helper_13a360 {
  public:
    void Init_0027af50();
};
extern int* hulk_at_004e0f30;
class CCondition_13a3b0 {
  public:
    virtual int vfunc_0(int);
};
class Track_13a3c0 {
  public:
    Track_13a3c0();
    virtual void v();
    char pad[4];
    int flag;
};
class Elem_13a3c0 {
  public:
    Elem_13a3c0();
    char bytes[8];
};
class AnimationPhaseMatchedTrack : public Track_13a3c0 {
  public:
    AnimationPhaseMatchedTrack();
    virtual void v();
    int c;
    float ten;
    char pad14[4];
    Elem_13a3c0 e;
    int a, b;
    float neg;
    char pad2c[4];
    Elem_13a3c0 e2;
    int color;
    float x, y;
};
struct Param_13a430 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_13a430 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int hulk_at_004124e0;
class Helper_13a440 {
  public:
    void Init_0027af50();
};
extern int* hulk_at_004e0f38;
class CCondition_13a490 {
  public:
    virtual int vfunc_0(int);
};
class Track_13a4a0 {
  public:
    virtual hulk_intptr Fnf_0013a490(int);
    Track_13a4a0();
    char pad[8];
};
class Part_13a4a0 {
  public:
    Part_13a4a0();
    char pad[8];
};
class AnimationVelocityScaledTrack : public Track_13a4a0 {
  public:
    AnimationVelocityScaledTrack();
    int a;
    float b;
    char gap[4];
    Part_13a4a0 p;
    int c;
    float d;
    int e;
    float f0;
    int g;
    int h;
    float i;
    int j;
    Part_13a4a0 q;
    int k;
    float l;
    float m;
};
struct Param_13a520 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_13a520 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct A_13a5c0 {
};
struct B_13a5c0 {
    int Check_00059a40();
};
struct C_13a5c0 {
    bool Finish_00222a00(void*);
};
struct Target_13a5c0 {
    char pad[0x20];
    A_13a5c0* field20;
    void* field24;
    bool Run();
};
struct AnimationState;
struct AnimationResult {
    bool FUN_00222a00(void* clip);
};
struct AnimationState {
    AnimationResult* FUN_00059a40();
};
struct AnimationSource {
};
class AnimationTrack_13a640 {
  public:
    AnimationTrack_13a640();
    virtual hulk_intptr FnF_0013a120(int);
};
class GrappleAnimationTrack : public AnimationTrack_13a640 {
  public:
    GrappleAnimationTrack();
};
struct A_13a670 {
};
struct B_13a670 {
    int Check_00059a40();
};
struct C_13a670 {
    bool Finish_00222a00(void*);
};
struct Target_13a670 {
    char pad[0x20];
    A_13a670* field20;
    void* field24;
    bool Run();
};
struct Actor { void* FUN_000592a0(); };
struct Animation_13a6a0 { void* FUN_00059a40(); };
struct State { bool FUN_00222a00(void*); };
struct A_13a6f0 {
};
struct B_13a6f0 {
    int Check_00059a40();
};
struct C_13a6f0 {
    bool Finish_00222a00(void*);
};
struct Target_13a6f0 {
    char pad[0x20];
    A_13a6f0* field20;
    void* field24;
    bool Run();
};
struct MotionInstance {
    bool FUN_00222a00(void*);
};
struct MotionOwner {
    MotionInstance* FUN_00059a40();
};
struct MotionSource {
};
class Obj_13a790 {
  public:
    virtual void A();
    virtual void B();
};
extern char threat_vftable_13a840;
struct Obj_13a840 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_13a840*);
class FrameReachedCondition_13a840 {
  public:
    void* vftable;
    char pad[0x0c];
    FrameReachedCondition_13a840* vfunc_5(unsigned char);
};
extern char threat_vftable_13a870;
struct Obj_13a870 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_13a870*);
class FrameCondition_13a870 {
  public:
    void* vftable;
    char pad[0x0c];
    FrameCondition_13a870* vfunc_5(unsigned char);
};
struct AnimationTrack_13a8a0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual AnimationTrack_13a8a0* vfunc_5(int);
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
};
struct H {
    void Fnf_0027af50();
};
struct G_13a8a0 {
    void Fng_00236d60();
};
extern void __cdecl thunk_FUN_00267090(AnimationTrack_13a8a0*);
extern int vftable_13a8a0;
struct Helper_13a920 {
    void run_0027af50();
};
struct AnimationLinkedTrack_13a920 {
    void* vptr;
    char pad04[0x14];
    Helper_13a920 h18;
    char pad1d[0x17];
    Helper_13a920 h30;
    AnimationLinkedTrack_13a920* other_00236d60();
    AnimationLinkedTrack_13a920* vfunc_5(unsigned int);
};
extern void* threat_vftable_13a920;
void destroy_0008d330(AnimationLinkedTrack_13a920*);
struct Helper_13a960 {
    void run_0027af50();
};
struct AnimationPhaseMatchedTrack_13a960 {
    void* vptr;
    char pad04[0x14];
    Helper_13a960 h18;
    char pad1d[0x17];
    Helper_13a960 h30;
    AnimationPhaseMatchedTrack_13a960* other_00236d60();
    AnimationPhaseMatchedTrack_13a960* vfunc_5(unsigned int);
};
extern void* threat_vftable_13a960;
void destroy_0008d330(AnimationPhaseMatchedTrack_13a960*);
} // namespace fn_f30d2d27
namespace fight {
class Params_13a9e0 {
public:
    virtual void vfunc_0();
};
}
namespace fn_f30d2d27 {
class CFightParams_13a9e0 : public fight::Params_13a9e0 {
public:
    virtual void vfunc_0();
};
namespace choreo2 {
class Driver_13a9e0 {
public:
    virtual void vfunc_0();
};
}
struct DriverInfo_13a9e0 {
    char pad0[8];
    int idLo;
    int idHi;
};
namespace choreo2 {
class AnimationDriver_13a9e0 : public Driver_13a9e0 {
public:
    virtual void vfunc_0();
    char pad04[0x1c];
    DriverInfo_13a9e0 *info;
    char pad24[0x23c - 0x24];
    float value;
};
}
struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *obj);
struct DriverSet_13a9e0 {
    char pad0[0x68];
    unsigned int count;
};
DriverSet_13a9e0 *__fastcall FUN_00059a40(Context *ctx);
extern "C" char __cdecl FUN_00018960(float a, float b, float epsilon);
class FrameCondition {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual char vfunc_6(int a, fight::Params_13a9e0 *params, int c);
    char _m_pad_4[0xc];
    int idLo;
    int idHi;
    union { int a; unsigned int mode; };
    union { int b; float threshold; };
    void initialize_00234590(int);
    void initializeExtra_0027af00();
};
class Other_13ad20 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_13ad20 {
  public:
    Action_13ad20();
    virtual void FnX_00018b30();
    char pad[0x18];
};
struct S_13ad20 {
    int a;
    Other_13ad20* b;
    int c;
    S_13ad20() throw() {
        a = 0;
        b = 0;
        c = 0;
    }
};
class AnimationAction : public Action_13ad20 {
  public:
    virtual void FnA_00018b40();
    S_13ad20 s;
    AnimationAction(int, Other_13ad20*);
};
struct AnimationClip { virtual void vfunc_0(); virtual void vfunc_1(); char pad[0x220]; unsigned char flag; };
struct Context_13adc0 { void* FUN_000592a0(); };
struct Link { void* FUN_00059a40(); };
struct Controller { void FUN_00222b50(AnimationClip*, int, float); void FUN_00222970(AnimationClip*, int); };
class AnimationTrack_13ae40 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
};
class NewObject {
  public:
    int Init_0013ad20(hulkfight::motion::GrappleAnimationTrack*, int);
};
extern int __cdecl Find_0005a470(int);
extern NewObject* __cdecl Alloc_0008d690(int);
class Ref_13ae80 {
  public:
    virtual void Fn0();
    virtual void Fn();
};
class Action_13ae80 {
  public:
    virtual void FnF_00018b30();
    Action_13ae80();
};
class AnimationPhaseMatchedAction : public Action_13ae80 {
  public:
    virtual void FnG_00018b40();
    char pad04[0x18];
    int mA;
    Ref_13ae80* mRef;
    int mC;
    AnimationPhaseMatchedAction(int a, Ref_13ae80* r);
};
struct Controller_13af20;
struct Context_13af20 {  };
struct Entries_13af20;
struct Controller_13af20 { Entries_13af20* FUN_00059a40(); };
struct Entries_13af20 { char pad[0x68]; unsigned count;  };
struct Phase { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(int); char pad[0x1c]; float duration; float phase; };
struct Animation_13af20 { char pad[0x228]; float speed; float start; float end; float FUN_00225ab0(); void FUN_00225cf0(float); };
struct Offset_13af20 { char pad[0x20]; float value; };
extern int DAT_0048d534;
extern int DAT_004ac1d0;
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
class PhaseObj {
  public:
    virtual void f0();
    virtual void f1();
};
class Helper_13b040 {
  public:
    void* next_00059a40();
    void act_00222970(void*, int);
};
class Action_13b080 {
  public:
    Action_13b080();
    virtual void FnA_00018b30();
    virtual void FnB_00018b40();
};
class Owner_13b080 {
  public:
    virtual void A();
    virtual void B();
};
class AnimationVelocityScaledAction : public Action_13b080 {
  public:
    int p[6];
    int mArg;
    Owner_13b080* mOwner;
    int mValue;
    AnimationVelocityScaledAction(int, Owner_13b080*);
};
} // namespace fn_f30d2d27
namespace hulkfight { namespace motion {
struct Obj_13b120 {
    virtual void f0();
    virtual void f1();
    char pad[0x220];
    unsigned char flag;
};
} }
namespace hulkfight { namespace motion {
struct Result_13b120 {
    void StopA_00222970(Obj_13b120*, int);
    void StopB_00222b50(Obj_13b120*, int, float);
};
} }
namespace hulkfight { namespace motion {
struct Mid_13b120 {
    Result_13b120* Get_00059a40();
};
} }
namespace hulkfight { namespace motion {
struct Owner_13b120 {
    Mid_13b120* Get_000592a0();
};
} }
namespace fn_f30d2d27 {
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_13b180 {
  public:
    Action_13b180();
    virtual void Fn();
    char pad[0x18];
};
struct Val {
    int n;
    Val() : n(0) {}
    Val& operator=(int x) {
        n = x;
        return *this;
    }
};
class AnimationChargeAction : public Action_13b180 {
  public:
    virtual void Fn();
    Val value;
    Ref* ref;
    int other;
    AnimationChargeAction(int, Ref*);
};
struct Mixer_13b220 {
    char pad0[0x1e58];
    float blend;            // 0x1e58
};
struct Context_13b220 {
    Mixer_13b220* FUN_00059a30();
};
struct Manager_13b220 {
};
struct Dial {
    char pad0[0x22c];
    float from;             // 0x22c
    float to;               // 0x230
    void FUN_00225cf0(float value);
};
class Helper_13b2a0 {
  public:
    void* next_00059a40();
    void act_00222970(void*, int);
};
struct Ref_13b2e0 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_13b2e0 {
    Action_13b2e0() throw();
    virtual void V0();
    char pad04[0x18];
};
struct AnimationLinkedAction_13b2e0 : Action_13b2e0 {
    int m1c;
    Ref_13b2e0* m20;
    int m24;
    AnimationLinkedAction_13b2e0(int a, Ref_13b2e0* r);
    virtual void V0();
};
class Service_13b380 {
  public:
    Service_13b380* check_00059a40();
    void run_00222b50(void*, int, float);
};
struct Obj_13b380 {
    virtual void a();
    virtual void b();
};
class CStageCondition_13b410;
class ParamValue_13b410 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b410 : public ParamValue_13b410 {
  public:
    int pad;
};
struct CAxisArcCondition_13b450;
class CStageCondition_13b460 {};
class ParamValue_13b460 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_13b460 : public ParamValue_13b460 {
  public:
    virtual void f();
};
class CStageCondition_13b4f0;
class ParamValue_13b4f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b4f0 : public ParamValue_13b4f0 {
  public:
    int pad;
};
class CStageCondition_13b540;
class ParamValue_13b540 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b540 : public ParamValue_13b540 {
  public:
    int pad;
};
struct CAxisArcCondition_13b580;
class CStageCondition_13b590 {};
class ParamValue_13b590 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_13b590 : public ParamValue_13b590 {
  public:
    virtual void f();
};
class CStageCondition_13b620;
class ParamValue_13b620 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b620 : public ParamValue_13b620 {
  public:
    int pad;
};
class ParamValueInt_13b630 {
  public:
    void* vptr;
    ParamValueInt_13b630(int a);
};
class ParamIntConstRange_13b630 : public ParamValueInt_13b630 {
  public:
    char pad[12];
    int m10;
    ParamIntConstRange_13b630(int a, int b);
};
class CStageCondition_13b670;
class ParamValue_13b670 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b670 : public ParamValue_13b670 {
  public:
    int pad;
};
class CStageCondition_13b6c0;
class ParamValue_13b6c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b6c0 : public ParamValue_13b6c0 {
  public:
    int pad;
};
class CStageCondition_13b710;
class ParamValue_13b710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b710 : public ParamValue_13b710 {
  public:
    int pad;
};
class CStageCondition_13b760;
class ParamValue_13b760 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b760 : public ParamValue_13b760 {
  public:
    int pad;
};
class CStageCondition_13b7b0;
class ParamValue_13b7b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b7b0 : public ParamValue_13b7b0 {
  public:
    int pad;
};
class CStageCondition_13b800;
class ParamValue_13b800 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b800 : public ParamValue_13b800 {
  public:
    int pad;
};
class CStageCondition_13b850;
class ParamValue_13b850 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b850 : public ParamValue_13b850 {
  public:
    int pad;
};
class CStageCondition_13b8a0;
class ParamValue_13b8a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b8a0 : public ParamValue_13b8a0 {
  public:
    int pad;
};
struct CAxisArcCondition_13b8e0;
class CStageCondition_13b8f0 {};
class ParamValue_13b8f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_13b8f0 : public ParamValue_13b8f0 {
  public:
    virtual void f();
};
class CStageCondition_13b980;
class ParamValue_13b980 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_13b980 : public ParamValue_13b980 {
  public:
    int pad;
};
extern void* hulk_at_00412820[];
class ConditionFactoryCaster_13b9f0 {
  public:
    void* vptr;
    ConditionFactoryCaster_13b9f0() { vptr = 0; }
};
class ConditionFactoryCasterTemplate_13b9f0 : public ConditionFactoryCaster_13b9f0 {
  public:
    ConditionFactoryCasterTemplate_13b9f0();
};
extern int FUN_00344e74(void*, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_004acbf8;
extern int hulk_at_0049850c;
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual int vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
class GrappleAnimationTrack_13bd60;
extern void* a;
extern void* hulk_at_004acd80;
} // namespace fn_f30d2d27
namespace fight {
class TrackFactoryCaster_13bd60 {
  public:
    virtual bool vfunc_0(GrappleAnimationTrack_13bd60*);
    virtual void vfunc_1();
};
}
namespace fn_f30d2d27 {
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class TrackFactoryCasterTemplate_13c1f0 {
  public:
    virtual bool cast_0013bb40(void*);
};
void __cdecl use_00236ac0(void*, TrackFactoryCasterTemplate_13c1f0*);
class ParamValueName_13c260 {
  public:
    ParamValueName_13c260(int);
    virtual void f();
};
class ParamName : public ParamValueName_13c260 {
  public:
    ParamName(int, int);
    virtual void f();
    char pad[12];
    int value;
};
class TrackFactoryCasterTemplate_13c620 {
  public:
    virtual int cast_0013ba80(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_13c620*);
class TrackFactoryCasterTemplate_13cb60 {
  public:
    virtual int Cast_0013bbc0(void*);
};
extern void* Find_00236ac0(const char*, TrackFactoryCasterTemplate_13cb60*);
class TrackFactoryCasterTemplate_13cdd0 {
  public:
    virtual int Cast_0013bc40(void*);
};
class Track {};
class Owner {
  public:
    void set_002367c0(void*);
    void Set_002367c0(void*);
    Track* Add_002367c0(Track*);
    void apply_002367c0(void*);
};
Track* Find_00236ac0(const char*, TrackFactoryCasterTemplate_13cdd0*);
class TrackFactoryCasterTemplate_13d040 {
  public:
    virtual int cast_0013bcc0(void*);
};
extern "C" void* lookup(void*, TrackFactoryCasterTemplate_13d040*);
class ConditionFactoryCaster_13d3c0 {
  public:
    virtual void cast();
};
class ConditionFactoryCasterTemplate_13d3c0 : public ConditionFactoryCaster_13d3c0 {
  public:
    virtual void cast();
};
class Reached : public ConditionFactoryCaster_13d3c0 {
  public:
    virtual void cast();
};
class Condition;
extern "C" Condition* __cdecl FUN_002343e0(const char*, ConditionFactoryCaster_13d3c0*);
class Factory {
  public:
    void add_00236760(Condition*);
};
} // namespace fn_f30d2d27
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f30d2d27 {
class TrackFactoryTemplate_13e330 {
  public:
    TrackFactoryTemplate_13e330() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_13e370;
extern void* __cdecl alloc_0008d690(unsigned int);
struct Init_13e370 {
    void Fnf_00234590(int);
};
struct Sub_13e370 {
    void Fnf_0027af00();
};
struct FrameReachedCondition_13e370 {
    hulk_uintptr vptr;
    char pad[0x1c];
};
extern u32_13e370 frame_vtable;
extern int hulk_at_004129a4;
struct ConditionFactoryTemplate_13e3b0 {
    void* m_vptr;
    void base1_dtor_0013a000();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_13e3e0 {
  public:
    TrackFactoryTemplate_13e3e0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00412430[];
void* __cdecl operator_new(unsigned int);
extern int hulk_at_004129c0;
struct ConditionFactoryTemplate_13e460 {
    void* m_vptr;
    void base1_dtor_0013a080();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_13e490 {
  public:
    TrackFactoryTemplate_13e490() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_004129dc;
class TrackFactoryTemplate_13e520 {
  public:
    TrackFactoryTemplate_13e520() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_13e560;
struct Grapple_13e560 {
    hulk_uintptr BuildTrack_0013a210();
};
class TrackFactoryTemplate_13e5b0 {
  public:
    TrackFactoryTemplate_13e5b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern void* __cdecl Allocate_0008d690(unsigned int);
struct Track_13e5f0 {
    void* Init_0013a2e0();
};
class TrackFactoryTemplate_13e640 {
  public:
    TrackFactoryTemplate_13e640() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
struct Track_13e680 {
    void* Init_0013a3c0();
};
class TrackFactoryTemplate_13e6d0 {
  public:
    TrackFactoryTemplate_13e6d0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class TrackFactoryTemplate_13e760 {
  public:
    TrackFactoryTemplate_13e760() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
struct CHitAnimationTrack_13e7a0 {
    unsigned int* vf;
    void init_0013a130();
};

} // namespace fn_f30d2d27

// 0x001399d0 FUN_001399d0 (4 B): matches/0x001399d0.cpp
// sym: ?FUN_001399d0@Obj_1399d0@owners@@QAEPAXXZ
void* owners::Obj_1399d0::FUN_001399d0() {
    return (char*)this + 0x10;
}


// 0x001399e0 FUN_001399e0 (12 B): matches/0x001399e0.cpp
// sym: ?FUN_001399e0@X_1399e0@owners@@QAEDH@Z
char owners::X_1399e0::FUN_001399e0(int a) {
    m18 = a;
    return 1;
}

namespace fn_f30d2d27 {

// 0x001399f0 FUN_001399f0 (4 B): matches/0x001399f0.cpp
// sym: ?Get@Obj_1399f0@fn_f30d2d27@@QAEPAXXZ
void* Obj_1399f0::Get() {
    return (char*)this + 0x10;
}


// 0x00139a10 FUN_00139a10 (12 B): matches/0x00139a10.cpp
// sym: ?Set@Obj_139a10@fn_f30d2d27@@QAEDH@Z
char Obj_139a10::Set(int v) {
    Value = v;
    return 1;
}


// 0x00139a20 FUN_00139a20 (12 B): matches/0x00139a20.cpp
// sym: ?Set@Obj_139a20@fn_f30d2d27@@QAE_NH@Z
bool Obj_139a20::Set(int x) {
    m = x;
    return true;
}

} // namespace fn_f30d2d27

// 0x00139a30 FUN_00139a30 (12 B): matches/0x00139a30.cpp
// sym: ?FUN_00139a30@C_139a30@owners@@QAE_NH@Z
bool owners::C_139a30::FUN_00139a30(int x) {
    m = x;
    return true;
}


// 0x00139a40 FUN_00139a40 (12 B): matches/0x00139a40.cpp
// sym: ?FUN_00139a40@S_139a40@owners@@QAEDH@Z
char owners::S_139a40::FUN_00139a40(int x) {
    m = x;
    return 1;
}

namespace fn_f30d2d27 {

// 0x00139a50 FUN_00139a50 (4 B): matches/0x00139a50.cpp
// sym: ?Get@Obj_139a50@fn_f30d2d27@@QAEPAXXZ
void* Obj_139a50::Get() {
    return (char*)this + 0x18;
}

} // namespace fn_f30d2d27

// 0x00139a70 FUN_00139a70 (12 B): matches/0x00139a70.cpp
// sym: ?FUN_00139a70@X_139a70@owners@@QAE_NH@Z
bool owners::X_139a70::FUN_00139a70(int x) {
    value = x;
    return true;
}


// 0x00139a90 FUN_00139a90 (12 B): matches/0x00139a90.cpp
// sym: ?FUN_00139a90@Obj_139a90@owners@@QAE_NH@Z
bool owners::Obj_139a90::FUN_00139a90(int value) {
    m24 = value;
    return true;
}


// 0x00139ab0 FUN_00139ab0 (12 B): matches/0x00139ab0.cpp
// sym: ?FUN_00139ab0@X_139ab0@owners@@QAE_NH@Z
bool owners::X_139ab0::FUN_00139ab0(int v) {
    m28 = v;
    return true;
}


// 0x00139ad0 FUN_00139ad0 (12 B): matches/0x00139ad0.cpp
// sym: ?FUN_00139ad0@Obj_139ad0@owners@@QAEDH@Z
char owners::Obj_139ad0::FUN_00139ad0(int v) {
    m = v;
    return 1;
}


// 0x00139af0 FUN_00139af0 (12 B): matches/0x00139af0.cpp
// sym: ?FUN_00139af0@Obj_139af0@owners@@QAEDH@Z
char owners::Obj_139af0::FUN_00139af0(int x) {
    m = x;
    return 1;
}


// 0x00139b10 FUN_00139b10 (12 B): matches/0x00139b10.cpp
// sym: ?FUN_00139b10@Obj_139b10@owners@@QAEDD@Z
char owners::Obj_139b10::FUN_00139b10(char b) {
    m34 = b;
    return 1;
}


// 0x00139b20 FUN_00139b20 (4 B): matches/0x00139b20.cpp
// sym: ?FUN_00139b20@X_139b20@owners@@QAEPAXXZ
void* owners::X_139b20::FUN_00139b20() {
    return (char*)this + 0x38;
}


// 0x00139b40 FUN_00139b40 (12 B): matches/0x00139b40.cpp
// sym: ?FUN_00139b40@Obj_139b40@owners@@QAEDH@Z
char owners::Obj_139b40::FUN_00139b40(int x) {
    value = x;
    return 1;
}


// 0x00139b60 FUN_00139b60 (12 B): matches/0x00139b60.cpp
// sym: ?FUN_00139b60@Obj_139b60@owners@@QAEDH@Z
char owners::Obj_139b60::FUN_00139b60(int v) {
    m44 = v;
    return 1;
}


// 0x00139b80 FUN_00139b80 (12 B): matches/0x00139b80.cpp
// sym: ?FUN_00139b80@Obj_139b80@owners@@QAE_NH@Z
bool owners::Obj_139b80::FUN_00139b80(int x) {
    mField = x;
    return true;
}


// 0x00139b90 FUN_00139b90 (12 B): matches/0x00139b90.cpp
// sym: ?FUN_00139b90@S_139b90@owners@@QAEDH@Z
char owners::S_139b90::FUN_00139b90(int v) {
    m = v;
    return 1;
}


// 0x00139ba0 FUN_00139ba0 (12 B): matches/0x00139ba0.cpp
// sym: ?FUN_00139ba0@Obj_139ba0@owners@@QAEDH@Z
char owners::Obj_139ba0::FUN_00139ba0(int x) {
    mValue = x;
    return 1;
}

namespace fn_f30d2d27 {

// 0x00139bb0 FUN_00139bb0 (4 B): matches/0x00139bb0.cpp
// sym: ?Get@Obj_139bb0@fn_f30d2d27@@QAEPAXXZ
void* Obj_139bb0::Get() {
    return &field;
}

} // namespace fn_f30d2d27

// 0x00139bd0 FUN_00139bd0 (12 B): matches/0x00139bd0.cpp
// sym: ?FUN_00139bd0@Obj_139bd0@owners@@QAE_NI@Z
bool owners::Obj_139bd0::FUN_00139bd0(unsigned int v) {
    mValue = v;
    return true;
}


// 0x00139bf0 FUN_00139bf0 (12 B): matches/0x00139bf0.cpp
// sym: ?FUN_00139bf0@Obj_139bf0@owners@@QAE_NH@Z
bool owners::Obj_139bf0::FUN_00139bf0(int v) {
    m24 = v;
    return true;
}


// 0x00139c00 FUN_00139c00 (4 B): matches/0x00139c00.cpp
// sym: ?FUN_00139c00@X_139c00@owners@@QAEPAXXZ
void* owners::X_139c00::FUN_00139c00() {
    return (char*)this + 0x28;
}


// 0x00139c20 FUN_00139c20 (12 B): matches/0x00139c20.cpp
// sym: ?FUN_00139c20@T_139c20@owners@@QAE_NH@Z
bool owners::T_139c20::FUN_00139c20(int v) {
    m30 = v;
    return true;
}


// 0x00139c40 FUN_00139c40 (12 B): matches/0x00139c40.cpp
// sym: ?FUN_00139c40@C_139c40@owners@@QAEDH@Z
char owners::C_139c40::FUN_00139c40(int v) {
    mValue = v;
    return 1;
}


// 0x00139c60 FUN_00139c60 (12 B): matches/0x00139c60.cpp
// sym: ?FUN_00139c60@X_139c60@owners@@QAEDH@Z
char owners::X_139c60::FUN_00139c60(int v) {
    m38 = v;
    return 1;
}


// 0x00139c70 FUN_00139c70 (12 B): matches/0x00139c70.cpp
// sym: ?FUN_00139c70@Obj_139c70@owners@@QAE_NH@Z
bool owners::Obj_139c70::FUN_00139c70(int v) {
    m1c = v;
    return true;
}


// 0x00139c80 FUN_00139c80 (12 B): matches/0x00139c80.cpp
// sym: ?FUN_00139c80@Obj_139c80@owners@@QAEDH@Z
char owners::Obj_139c80::FUN_00139c80(int x) {
    *(int*)(m + 0x10) = x;
    return 1;
}


// 0x00139c90 FUN_00139c90 (4 B): matches/0x00139c90.cpp
// sym: ?FUN_00139c90@Obj_139c90@owners@@QAEPADXZ
char* owners::Obj_139c90::FUN_00139c90() {
    return (char*)((char*)pad + 0x18);
}


// 0x00139cb0 FUN_00139cb0 (12 B): matches/0x00139cb0.cpp
// sym: ?FUN_00139cb0@Obj_139cb0@owners@@QAE_NH@Z
bool owners::Obj_139cb0::FUN_00139cb0(int value) {
    mField = value;
    return true;
}


// 0x00139cd0 FUN_00139cd0 (12 B): matches/0x00139cd0.cpp
// sym: ?FUN_00139cd0@Obj_139cd0@owners@@QAEDH@Z
char owners::Obj_139cd0::FUN_00139cd0(int x) {
    Value = x;
    return 1;
}


// 0x00139cf0 FUN_00139cf0 (12 B): matches/0x00139cf0.cpp
// sym: ?FUN_00139cf0@C_139cf0@owners@@QAE_NH@Z
bool owners::C_139cf0::FUN_00139cf0(int v) {
    m28 = v;
    return true;
}


// 0x00139d00 FUN_00139d00 (4 B): matches/0x00139d00.cpp
// sym: ?FUN_00139d00@X_139d00@owners@@QAEPADXZ
char* owners::X_139d00::FUN_00139d00() {
    return m + 0x30;
}


// 0x00139d20 FUN_00139d20 (12 B): matches/0x00139d20.cpp
// sym: ?FUN_00139d20@Obj_139d20@owners@@QAE_NH@Z
bool owners::Obj_139d20::FUN_00139d20(int v) {
    m38 = v;
    return true;
}


// 0x00139d40 FUN_00139d40 (12 B): matches/0x00139d40.cpp
// sym: ?FUN_00139d40@Obj_139d40@owners@@QAEDH@Z
char owners::Obj_139d40::FUN_00139d40(int v) {
    m3c = v;
    return 1;
}


// 0x00139d60 FUN_00139d60 (12 B): matches/0x00139d60.cpp
// sym: ?FUN_00139d60@X_139d60@owners@@QAE_NH@Z
bool owners::X_139d60::FUN_00139d60(int v) {
    m = v;
    return true;
}


// 0x00139d70 FUN_00139d70 (12 B): matches/0x00139d70.cpp
// sym: ?FUN_00139d70@Obj_139d70@owners@@QAEDH@Z
char owners::Obj_139d70::FUN_00139d70(int v) {
    m = v;
    return 1;
}


// 0x00139d80 FUN_00139d80 (12 B): matches/0x00139d80.cpp
// sym: ?FUN_00139d80@Obj_139d80@owners@@QAEDH@Z
char owners::Obj_139d80::FUN_00139d80(int value) {
    m10 = value;
    return 1;
}


// 0x00139d90 FUN_00139d90 (4 B): matches/0x00139d90.cpp
// sym: ?FUN_00139d90@Obj_139d90@owners@@QAEPAXXZ
void* owners::Obj_139d90::FUN_00139d90() {
    return (void*)&mValue;
}


// 0x00139db0 FUN_00139db0 (12 B): matches/0x00139db0.cpp
// sym: ?FUN_00139db0@Obj_139db0@owners@@QAEDH@Z
char owners::Obj_139db0::FUN_00139db0(int v) {
    m20 = v;
    return 1;
}


// 0x00139dd0 FUN_00139dd0 (12 B): matches/0x00139dd0.cpp
// sym: ?FUN_00139dd0@Obj_139dd0@owners@@QAEDH@Z
char owners::Obj_139dd0::FUN_00139dd0(int v) {
    *(int*)((char*)this + 0x24) = v;
    return 1;
}


// 0x00139df0 FUN_00139df0 (12 B): matches/0x00139df0.cpp
// sym: ?FUN_00139df0@A_139df0@owners@@QAEDH@Z
char owners::A_139df0::FUN_00139df0(int x) {
    m28 = x;
    return 1;
}


// 0x00139e00 FUN_00139e00 (4 B): matches/0x00139e00.cpp
// sym: ?FUN_00139e00@Obj_139e00@owners@@QAEPAXXZ
void* owners::Obj_139e00::FUN_00139e00() {
    return (void*)((char*)this + 0x30);
}


// 0x00139e20 FUN_00139e20 (12 B): matches/0x00139e20.cpp
// sym: ?FUN_00139e20@O_139e20@owners@@QAE_NH@Z
bool owners::O_139e20::FUN_00139e20(int x) {
    value = x;
    return 1;
}


// 0x00139e40 FUN_00139e40 (12 B): matches/0x00139e40.cpp
// sym: ?FUN_00139e40@X_139e40@owners@@QAE_NH@Z
bool owners::X_139e40::FUN_00139e40(int v) {
    mVal = v;
    return true;
}


// 0x00139e60 FUN_00139e60 (12 B): matches/0x00139e60.cpp
// sym: ?FUN_00139e60@X_139e60@owners@@QAEDH@Z
char owners::X_139e60::FUN_00139e60(int v) {
    m40 = v;
    return 1;
}


// 0x00139e70 FUN_00139e70 (12 B): matches/0x00139e70.cpp
// sym: ?FUN_00139e70@A_139e70@owners@@QAEDH@Z
char owners::A_139e70::FUN_00139e70(int x) {
    mVal = x;
    return 1;
}


// 0x00139e80 FUN_00139e80 (12 B): matches/0x00139e80.cpp
// sym: ?FUN_00139e80@Obj_139e80@owners@@QAE_NH@Z
bool owners::Obj_139e80::FUN_00139e80(int v) {
    mValue = v;
    return true;
}

namespace fn_f30d2d27 {

// 0x00139e90 FUN_00139e90 (4 B): matches/0x00139e90.cpp
// sym: ?FUN_00139e90@fn_f30d2d27@@YIPAXPAVObj_139e90@1@@Z
void* __fastcall FUN_00139e90(Obj_139e90* self) {
    return (char*)self + 0x18;
}

} // namespace fn_f30d2d27

// 0x00139eb0 FUN_00139eb0 (12 B): matches/0x00139eb0.cpp
// sym: ?FUN_00139eb0@X_139eb0@owners@@QAE_NH@Z
bool owners::X_139eb0::FUN_00139eb0(int v) {
    m20 = v;
    return true;
}


// 0x00139ec0 FUN_00139ec0 (12 B): matches/0x00139ec0.cpp
// sym: ?FUN_00139ec0@Obj_139ec0@owners@@QAE_NH@Z
bool owners::Obj_139ec0::FUN_00139ec0(int v) {
    mField = v;
    return true;
}


// 0x00139ee0 FUN_00139ee0 (12 B): matches/0x00139ee0.cpp
// sym: ?FUN_00139ee0@X_139ee0@owners@@QAE_NH@Z
bool owners::X_139ee0::FUN_00139ee0(int x) {
    value = x;
    return true;
}


// 0x00139f00 FUN_00139f00 (12 B): matches/0x00139f00.cpp
// sym: ?FUN_00139f00@Obj_139f00@owners@@QAE_NH@Z
bool owners::Obj_139f00::FUN_00139f00(int x) {
    m2c = x;
    return true;
}


// 0x00139f20 FUN_00139f20 (12 B): matches/0x00139f20.cpp
// sym: ?FUN_00139f20@Obj_139f20@owners@@QAEDPAX@Z
char owners::Obj_139f20::FUN_00139f20(void* v) {
    m30 = v;
    return 1;
}


// 0x00139f40 FUN_00139f40 (12 B): matches/0x00139f40.cpp
// sym: ?FUN_00139f40@Obj_139f40@owners@@QAE_NH@Z
bool owners::Obj_139f40::FUN_00139f40(int v) {
    mVal = v;
    return true;
}


// 0x00139f60 FUN_00139f60 (12 B): matches/0x00139f60.cpp
// sym: ?FUN_00139f60@Obj_139f60@owners@@QAE_NH@Z
bool owners::Obj_139f60::FUN_00139f60(int x) {
    mX = x;
    return true;
}


// 0x00139f80 FUN_00139f80 (12 B): matches/0x00139f80.cpp
// sym: ?FUN_00139f80@Obj_139f80@owners@@QAEDH@Z
char owners::Obj_139f80::FUN_00139f80(int value) {
    *(int*)((char*)this + 0x3c) = value;
    return 1;
}

namespace fn_f30d2d27 {

// 0x00139f90 FUN_00139f90 (4 B): matches/0x00139f90.cpp
// sym: ?FUN_00139f90@fn_f30d2d27@@YIPAXPAUT_139f90@1@@Z
void* __fastcall FUN_00139f90(T_139f90* self) {
    return (void*)((char*)self + 0x40);
}

} // namespace fn_f30d2d27

// 0x00139fb0 FUN_00139fb0 (12 B): matches/0x00139fb0.cpp
// sym: ?FUN_00139fb0@Obj_139fb0@owners@@QAEDH@Z
char owners::Obj_139fb0::FUN_00139fb0(int v) {
    m48 = v;
    return 1;
}


// 0x00139fd0 FUN_00139fd0 (12 B): matches/0x00139fd0.cpp
// sym: ?FUN_00139fd0@Obj_139fd0@owners@@QAE_NH@Z
bool owners::Obj_139fd0::FUN_00139fd0(int v) {
    mValue = v;
    return true;
}


// 0x00139ff0 FUN_00139ff0 (12 B): matches/0x00139ff0.cpp
// sym: ?FUN_00139ff0@Obj_139ff0@owners@@QAEDH@Z
char owners::Obj_139ff0::FUN_00139ff0(int value) {
    mField = value;
    return 1;
}

namespace fn_f30d2d27 {

// 0x0013a000 FUN_0013a000 (19 B): matches/0x0013a000.cpp
// sym: ?FUN_0013a000@fn_f30d2d27@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013a000() {
    FUN_00234810(((char*)&DAT_004e0f08), ((char*)&DAT_004e0f0c));
}

} // namespace fn_f30d2d27

// 0x0013a020 hulkfight::motion::FrameReachedCondition::vfunc_0 (16 B): matches/0x0013a020.cpp
// sym: ?vfunc_0@FrameReachedCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FrameReachedCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0f08;
    return p[index];
}

namespace fn_f30d2d27 {

// 0x0013a060 FUN_0013a060 (25 B): matches/0x0013a060.cpp
// sym: ?f@FrameReachedCondition_13a060@fn_f30d2d27@@QAEXXZ
void FrameReachedCondition_13a060::f() {
    vptr = hulk_at_00412410;
    sub.Fin_0027af50();
    Fin_002345b0();
}


// 0x0013a080 FUN_0013a080 (19 B): matches/0x0013a080.cpp
// sym: ?FUN_0013a080@fn_f30d2d27@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013a080() {
    FUN_00234810(((char*)&DAT_004e0f10), ((char*)&DAT_004e0f14));
}

} // namespace fn_f30d2d27

// 0x0013a0a0 hulkfight::motion::FrameCondition::vfunc_0 (16 B): matches/0x0013a0a0.cpp
// sym: ?vfunc_0@FrameCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FrameCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0f10;
    return p[index];
}

namespace fn_f30d2d27 {

// 0x0013a0e0 FUN_0013a0e0 (25 B): matches/0x0013a0e0.cpp
// sym: ??1FrameCondition_13a0e0@fn_f30d2d27@@QAE@XZ
FrameCondition_13a0e0::~FrameCondition_13a0e0() throw() {
    vptr = hulk_at_00412430;
    sub.Fin_0027af50();
}


// 0x0013a100 FUN_0013a100 (19 B): matches/0x0013a100.cpp
// sym: ?FUN_0013a100@fn_f30d2d27@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013a100() {
    FUN_00234810(((char*)&DAT_004e0f18), ((char*)&DAT_004e0f1c));
}

} // namespace fn_f30d2d27

// 0x0013a120 hulkfight::motion::AnimationTrack::vfunc_0 (16 B): matches/0x0013a120.cpp
// sym: ?vfunc_0@AnimationTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::AnimationTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f18;
    return p[index];
}

namespace fn_f30d2d27 {

// 0x0013a130 FUN_0013a130 (89 B): matches/0x0013a130.cpp
// sym: ??0AnimationTrack@fn_f30d2d27@@QAE@XZ
AnimationTrack::AnimationTrack()
    : zero(0), negative(-1.0f), one(1.0f), z24(0), z28(0), neg2(-1.0f), z30(0), yes(1), z40(0), a(0.1f),
      b(0.1f) {}

} // namespace fn_f30d2d27

// 0x0013a190 hulkfight::motion::AnimationTrack::vfunc_6 (4 B): matches/0x0013a190.cpp
// sym: ?vfunc_6@AnimationTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::AnimationTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0013a1a0 hulkfight::motion::AnimationTrack::vfunc_7 (7 B): matches/0x0013a1a0.cpp
// sym: ?vfunc_7@AnimationTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::AnimationTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f30d2d27 {

// 0x0013a1b0 FUN_0013a1b0 (33 B): matches/0x0013a1b0.cpp
// sym: ??1AnimationTrack_13a1b0@fn_f30d2d27@@QAE@XZ
AnimationTrack_13a1b0::~AnimationTrack_13a1b0() {
    vptr = hulk_at_00412450;
    s38.Init_0027af50();
    s18.Init_0027af50();
    Fin_00236d60();
}


// 0x0013a1e0 FUN_0013a1e0 (19 B): matches/0x0013a1e0.cpp
// sym: ?FUN_0013a1e0@fn_f30d2d27@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013a1e0() {
    FUN_00234810(((char*)&DAT_004e0f20), ((char*)&DAT_004e0f24));
}

} // namespace fn_f30d2d27

// 0x0013a200 hulkfight::motion::AnimationChargeTrack::vfunc_0 (16 B): matches/0x0013a200.cpp
// sym: ?vfunc_0@AnimationChargeTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::AnimationChargeTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f20;
    return p[index];
}

namespace fn_f30d2d27 {

// 0x0013a210 FUN_0013a210 (80 B): matches/0x0013a210.cpp
// sym: ??0AnimationChargeTrack@fn_f30d2d27@@QAE@XZ
AnimationChargeTrack::AnimationChargeTrack()
    : a(0), b(-1.0f), one(), d(0), e(-1.0f), two(), f(0), g(0.1f), h(0.1f) {}

} // namespace fn_f30d2d27

// 0x0013a260 hulkfight::motion::AnimationChargeTrack::vfunc_6 (4 B): matches/0x0013a260.cpp
// sym: ?vfunc_6@AnimationChargeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::AnimationChargeTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0013a270 hulkfight::motion::AnimationChargeTrack::vfunc_7 (7 B): matches/0x0013a270.cpp
// sym: ?vfunc_7@AnimationChargeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::AnimationChargeTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0013a280 FUN_0013a280 (33 B): matches/0x0013a280.cpp
// sym: ?FUN_0013a280@AnimationChargeTrack@motion@hulkfight@@QAEXXZ
void hulkfight::motion::AnimationChargeTrack::FUN_0013a280() {
    *(hulk_uintptr*)this = (hulk_uintptr)&hulk_at_00412480;
    ((Sub_13a280*)((char*)this + 0x28))->Init_0027af50();
    ((Sub_13a280*)((char*)this + 0x18))->Init_0027af50();
    ((Base_13a280*)this)->Finish_00236d60();
}

namespace fn_f30d2d27 {

// 0x0013a2b0 FUN_0013a2b0 (19 B): matches/0x0013a2b0.cpp
// sym: ?FUN_0013a2b0@fn_f30d2d27@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013a2b0() {
    FUN_00234810(((char*)&DAT_004e0f28), ((char*)&DAT_004e0f2c));
}

} // namespace fn_f30d2d27

// 0x0013a2d0 hulkfight::motion::AnimationLinkedTrack::vfunc_0 (16 B): matches/0x0013a2d0.cpp
// sym: ?vfunc_0@AnimationLinkedTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::AnimationLinkedTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f28;
    return p[index];
}

namespace fn_f30d2d27 {

// 0x0013a2e0 FUN_0013a2e0 (87 B): matches/0x0013a2e0.cpp
// sym: ??0AnimationLinkedTrack@fn_f30d2d27@@QAE@XZ
AnimationLinkedTrack::AnimationLinkedTrack()
    : Track_13a2e0(), a(0), b(-1.0f), p(), x(1.0f), y(0.0f), z(-1.0f), q(), r(0.0f), s(0.1f), t(0.1f) {}

} // namespace fn_f30d2d27

// 0x0013a340 hulkfight::motion::AnimationLinkedTrack::vfunc_6 (4 B): matches/0x0013a340.cpp
// sym: ?vfunc_6@AnimationLinkedTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::AnimationLinkedTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0013a350 hulkfight::motion::AnimationLinkedTrack::vfunc_7 (7 B): matches/0x0013a350.cpp
// sym: ?vfunc_7@AnimationLinkedTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::AnimationLinkedTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0013a360 FUN_0013a360 (33 B): matches/0x0013a360.cpp
// sym: ?FUN_0013a360@AnimationLinkedTrack@motion@hulkfight@@QAEXXZ
// Same code shape as 0x0012b640 (propagated; names are from that function)
void hulkfight::motion::AnimationLinkedTrack::FUN_0013a360() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_004124b0;
    ((Helper_13a360*)((char*)this + 0x30))->Init_0027af50();
    ((Helper_13a360*)((char*)this + 0x18))->Init_0027af50();
    ((Ender*)this)->Finish();
}

namespace fn_f30d2d27 {

// 0x0013a390 FUN_0013a390 (19 B): matches/0x0013a390.cpp
// sym: ?FUN_0013a390@fn_f30d2d27@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013a390() {
    FUN_00234810(((char*)&DAT_004e0f30), ((char*)&DAT_004e0f34));
}

} // namespace fn_f30d2d27

// 0x0013a3b0 hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_0 (16 B): matches/0x0013a3b0.cpp
// sym: ?vfunc_0@AnimationPhaseMatchedTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f30;
    return p[index];
}

namespace fn_f30d2d27 {

// 0x0013a3c0 FUN_0013a3c0 (94 B): matches/0x0013a3c0.cpp
// sym: ??0AnimationPhaseMatchedTrack@fn_f30d2d27@@QAE@XZ
AnimationPhaseMatchedTrack::AnimationPhaseMatchedTrack()
    : Track_13a3c0(), c(0), ten(-1.0f), e(), a(0), b(0), neg(-1.0f), e2(), color(-1), x(0.1f), y(0.1f) {
    flag = 1;
}

} // namespace fn_f30d2d27

// 0x0013a420 hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_6 (4 B): matches/0x0013a420.cpp
// sym: ?vfunc_6@AnimationPhaseMatchedTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0013a430 hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_7 (7 B): matches/0x0013a430.cpp
// sym: ?vfunc_7@AnimationPhaseMatchedTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0013a440 FUN_0013a440 (33 B): matches/0x0013a440.cpp
// sym: ?FUN_0013a440@AnimationPhaseMatchedTrack@motion@hulkfight@@QAEXXZ
// Same code shape as 0x0012b640 (propagated; names are from that function)
void hulkfight::motion::AnimationPhaseMatchedTrack::FUN_0013a440() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_004124e0;
    ((Helper_13a440*)((char*)this + 0x30))->Init_0027af50();
    ((Helper_13a440*)((char*)this + 0x18))->Init_0027af50();
    ((Ender*)this)->Finish();
}

namespace fn_f30d2d27 {

// 0x0013a470 FUN_0013a470 (19 B): matches/0x0013a470.cpp
// sym: ?FUN_0013a470@fn_f30d2d27@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0013a470() {
    FUN_00234810(((char*)&DAT_004e0f38), ((char*)&DAT_004e0f3c));
}

} // namespace fn_f30d2d27

// 0x0013a490 hulkfight::motion::AnimationVelocityScaledTrack::vfunc_0 (16 B): matches/0x0013a490.cpp
// sym: ?vfunc_0@AnimationVelocityScaledTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::AnimationVelocityScaledTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f38;
    return p[index];
}

namespace fn_f30d2d27 {

// 0x0013a4a0 FUN_0013a4a0 (98 B): matches/0x0013a4a0.cpp
// sym: ??0AnimationVelocityScaledTrack@fn_f30d2d27@@QAE@XZ
AnimationVelocityScaledTrack::AnimationVelocityScaledTrack()
    : a(0), b(-1.0f), c(0), d(1.0f), e(0), f0(-1.0f), g(0), h(0), i(-1.0f), j(0), k(0), l(0.1f), m(0.1f) {}

} // namespace fn_f30d2d27

// 0x0013a510 hulkfight::motion::AnimationVelocityScaledTrack::vfunc_6 (4 B): matches/0x0013a510.cpp
// sym: ?vfunc_6@AnimationVelocityScaledTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::AnimationVelocityScaledTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0013a520 hulkfight::motion::AnimationVelocityScaledTrack::vfunc_7 (7 B): matches/0x0013a520.cpp
// sym: ?vfunc_7@AnimationVelocityScaledTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::AnimationVelocityScaledTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0013a530 FUN_0013a530 (33 B): matches/0x0013a530.cpp [wrapped: conflict: AnimationVelocityScaledTrack]
// sym: ?Build@AnimationVelocityScaledTrack@fn_0013a530@@QAEXXZ
namespace fn_0013a530 {
class Sub_13a530 {
  public:
    void Init_0027af50();
};
extern void* hulk_at_00412510;
class AnimationVelocityScaledTrack {
  public:
    void* vf;
    char pad[0x3c];
    void Finish_00236d60();
    void Build();
};
void AnimationVelocityScaledTrack::Build() {
    vf = &hulk_at_00412510;
    ((Sub_13a530*)((char*)this + 0x40))->Init_0027af50();
    ((Sub_13a530*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}
} // namespace fn_0013a530

namespace fn_f30d2d27 {

// 0x0013a5c0 FUN_0013a5c0 (39 B): matches/0x0013a5c0.cpp
// sym: ?Run@Target_13a5c0@fn_f30d2d27@@QAE_NXZ
bool Target_13a5c0::Run() {
    void* value = ((void *)((owners::Object_592a0 *)field20)->FUN_000592a0());
    hulk_intptr result = ((B_13a5c0*)value)->Check_00059a40();
    if (!result)
        return true;
    return ((C_13a5c0*)result)->Finish_00222a00(field24);
}

} // namespace fn_f30d2d27

// 0x0013a5f0 hulkfight::motion::AnimationAction::vfunc_5 (74 B): equivalent/0x0013a5f0.cpp
// sym: ?vfunc_5@AnimationAction@motion@hulkfight@@UAE_NHH@Z @f4a65125a6a1 @we3b8b0e70dba
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 7/8, incomplete)
// hulkfight::motion::AnimationAction::vfunc_5 @ 0x0013a5f0
bool hulkfight::motion::AnimationAction::vfunc_5(hulk_intptr event, int unused) {
    if (event != 1) return true;
    AnimationState* state = ((AnimationState *)((owners::Object_592a0 *)((*(AnimationSource * *)&this->f_20)))->FUN_000592a0());
    AnimationResult* result = state->FUN_00059a40();
    if (!result) return false;
    return !result->FUN_00222a00(this->f_24);
}

namespace fn_f30d2d27 {

// 0x0013a640 FUN_0013a640 (18 B): matches/0x0013a640.cpp
// sym: ??0GrappleAnimationTrack@fn_f30d2d27@@QAE@XZ
GrappleAnimationTrack::GrappleAnimationTrack() : AnimationTrack_13a640() {}

} // namespace fn_f30d2d27

// 0x0013a660 hulkfight::motion::GrappleAnimationTrack::vfunc_8 (16 B): matches/0x0013a660.cpp
// sym: ?vfunc_8@GrappleAnimationTrack@motion@hulkfight@@UAEPAXPAX0@Z
void* hulkfight::motion::GrappleAnimationTrack::vfunc_8(void* __p0, void* __p1) { int a = (int)__p0; int b = (int)__p1;

    return (void*)(FUN_0005a3f0(b));
}

namespace fn_f30d2d27 {

// 0x0013a670 FUN_0013a670 (39 B): matches/0x0013a670.cpp
// sym: ?Run@Target_13a670@fn_f30d2d27@@QAE_NXZ
// Same code shape as 0x0013a5c0 (propagated; names are from that function)
bool Target_13a670::Run() {
    void* value = ((void *)((owners::Object_592a0 *)field20)->FUN_000592a0());
    hulk_intptr result = ((B_13a670*)value)->Check_00059a40();
    if (!result)
        return true;
    return ((C_13a670*)result)->Finish_00222a00(field24);
}

} // namespace fn_f30d2d27

// 0x0013a6a0 hulkfight::motion::AnimationVelocityScaledAction::vfunc_5 (74 B): equivalent/0x0013a6a0.cpp
// sym: ?vfunc_5@AnimationVelocityScaledAction@motion@hulkfight@@UAE_NHH@Z @f4a65125a6a1 @we3b8b0e70dba
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 7/8, incomplete)
// hulkfight::motion::AnimationVelocityScaledAction::vfunc_5 @ 0x0013a6a0
bool hulkfight::motion::AnimationVelocityScaledAction::vfunc_5(hulk_intptr type, int unused) { if(type != 1) return true; Animation_13a6a0* anim = (Animation_13a6a0*)(*(Actor * *)&this->f_20)->FUN_000592a0(); State* state = (State*)anim->FUN_00059a40(); if (!state) return false; return !state->FUN_00222a00((*(void * *)&this->f_24)); }

namespace fn_f30d2d27 {

// 0x0013a6f0 FUN_0013a6f0 (39 B): matches/0x0013a6f0.cpp
// sym: ?Run@Target_13a6f0@fn_f30d2d27@@QAE_NXZ
// Same code shape as 0x0013a5c0 (propagated; names are from that function)
bool Target_13a6f0::Run() {
    void* value = ((void *)((owners::Object_592a0 *)field20)->FUN_000592a0());
    hulk_intptr result = ((B_13a6f0*)value)->Check_00059a40();
    if (!result)
        return true;
    return ((C_13a6f0*)result)->Finish_00222a00(field24);
}

} // namespace fn_f30d2d27

// 0x0013a720 hulkfight::motion::AnimationLinkedAction::vfunc_5 (74 B): matches/0x0013a720.cpp
// sym: ?vfunc_5@AnimationLinkedAction@motion@hulkfight@@UAE_NHH@Z
 // namespace hulkfight
bool hulkfight::motion::AnimationLinkedAction::vfunc_5(hulk_intptr event, int other) {
    if (event == 1) {
        MotionInstance* instance = ((MotionOwner *)((owners::Object_592a0 *)((*(MotionSource * *)&this->f_20)))->FUN_000592a0())->FUN_00059a40();
        bool result;
        if (!instance)
            result = true;
        else
            result = instance->FUN_00222a00((*(void * *)&this->f_24));
        return !result;
    }
    return true;
}

namespace fn_f30d2d27 {

// 0x0013a790 FUN_0013a790 (36 B): matches/0x0013a790.cpp
// sym: ?Set@fn_f30d2d27@@YAXPAPAVObj_13a790@1@PAV21@@Z
// Same code shape as 0x000187a0 (propagated; names are from that function)
void Set(Obj_13a790** p, Obj_13a790* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}


// 0x0013a840 hulkfight::motion::FrameReachedCondition::vfunc_5 (46 B): matches/0x0013a840.cpp
// sym: ?vfunc_5@FrameReachedCondition_13a840@fn_f30d2d27@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
FrameReachedCondition_13a840* FrameReachedCondition_13a840::vfunc_5(unsigned char param) {
    FrameReachedCondition_13a840* p = this;
    *(char**)p = ((char*)DAT_00412410);
    ((Obj_13a840*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_13a840*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_13a840*)p);
    return p;
}


// 0x0013a870 hulkfight::motion::FrameCondition::vfunc_5 (46 B): matches/0x0013a870.cpp
// sym: ?vfunc_5@FrameCondition_13a870@fn_f30d2d27@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
FrameCondition_13a870* FrameCondition_13a870::vfunc_5(unsigned char param) {
    FrameCondition_13a870* p = this;
    *(char**)p = ((char*)DAT_00412430);
    ((Obj_13a870*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_13a870*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_13a870*)p);
    return p;
}


// 0x0013a8a0 hulkfight::motion::AnimationTrack::vfunc_5 (54 B): matches/0x0013a8a0.cpp
// sym: ?vfunc_5@AnimationTrack_13a8a0@fn_f30d2d27@@UAEPAU12@H@Z
// Same code shape as 0x0005e160 (propagated; names are from that function)
AnimationTrack_13a8a0* AnimationTrack_13a8a0::vfunc_5(int param) {
    *(hulk_intptr*)this = (hulk_intptr)((int*)DAT_00412450);
    ((H*)((char*)this + 0x38))->Fnf_0027af50();
    ((H*)((char*)this + 0x18))->Fnf_0027af50();
    ((G_13a8a0*)this)->Fng_00236d60();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f30d2d27

// 0x0013a8e0 hulkfight::motion::AnimationChargeTrack::vfunc_5 (54 B): matches/0x0013a8e0.cpp [wrapped: conflict: AnimationChargeTrack]
// sym: ?vfunc_5@AnimationChargeTrack@fn_0013a8e0@@QAEPAV12@E@Z
namespace fn_0013a8e0 {
typedef unsigned char byte_13a8e0;
class Sub_13a8e0 {
  public:
    void Fnf_0027af50();
};
class Base_13a8e0 {
  public:
    void Fng_00236d60();
};
extern void cdel_0008d330(void*);
extern int vftable_13a8e0;
class AnimationChargeTrack {
  public:
    hulk_intptr vf;
    char pad1[0x18 - 4];
    Sub_13a8e0 a;
    char pad2[0x28 - 0x18 - 1];
    Sub_13a8e0 b;
    AnimationChargeTrack* vfunc_5(byte_13a8e0 param);
};
AnimationChargeTrack* AnimationChargeTrack::vfunc_5(byte_13a8e0 param) {
    vf = (hulk_intptr)((int*)DAT_00412480);
    b.Fnf_0027af50();
    a.Fnf_0027af50();
    ((Base_13a8e0*)this)->Fng_00236d60();
    if (param & 1)
        cdel_0008d330(this);
    return this;
}
} // namespace fn_0013a8e0

namespace fn_f30d2d27 {

// 0x0013a920 hulkfight::motion::AnimationLinkedTrack::vfunc_5 (54 B): matches/0x0013a920.cpp
// sym: ?vfunc_5@AnimationLinkedTrack_13a920@fn_f30d2d27@@QAEPAU12@I@Z
// Same code shape as 0x0012bcc0 (propagated; names are from that function)
AnimationLinkedTrack_13a920* AnimationLinkedTrack_13a920::vfunc_5(unsigned int flags) {
    vptr = ((void**)DAT_004124b0);
    h30.run_0027af50();
    h18.run_0027af50();
    other_00236d60();
    if (flags & 1)
        destroy_0008d330(this);
    return this;
}


// 0x0013a960 hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_5 (54 B): matches/0x0013a960.cpp
// sym: ?vfunc_5@AnimationPhaseMatchedTrack_13a960@fn_f30d2d27@@QAEPAU12@I@Z
// Same code shape as 0x0012bcc0 (propagated; names are from that function)
AnimationPhaseMatchedTrack_13a960* AnimationPhaseMatchedTrack_13a960::vfunc_5(unsigned int flags) {
    vptr = ((void**)DAT_004124e0);
    h30.run_0027af50();
    h18.run_0027af50();
    other_00236d60();
    if (flags & 1)
        destroy_0008d330(this);
    return this;
}

} // namespace fn_f30d2d27

// 0x0013a9a0 hulkfight::motion::AnimationVelocityScaledTrack::vfunc_5 (54 B): matches/0x0013a9a0.cpp [wrapped: conflict: AnimationVelocityScaledTrack]
// sym: ?v5@AnimationVelocityScaledTrack@fn_0013a9a0@@UAEPAV12@E@Z
namespace fn_0013a9a0 {
typedef unsigned char byte_13a9a0;
struct Helper_13a9a0 {
    int x;
    void run_0027af50();
};
struct Main_13a9a0 {
    void run_00236d60();
};
extern int vf_13a9a0;
extern void cleanup_0008d330(void*);
class AnimationVelocityScaledTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual AnimationVelocityScaledTrack* v5(byte_13a9a0);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x14];
    Helper_13a9a0 h18;
    char gap[0x24];
    Helper_13a9a0 h40;
};
AnimationVelocityScaledTrack* AnimationVelocityScaledTrack::v5(byte_13a9a0 x) {
    *(hulk_intptr*)this = (hulk_intptr)&vf_13a9a0;
    h40.run_0027af50();
    h18.run_0027af50();
    ((Main_13a9a0*)this)->run_00236d60();
    if (x & 1)
        cleanup_0008d330(this);
    return this;
}
} // namespace fn_0013a9a0

namespace fn_f30d2d27 {

// 0x0013a9e0 hulkfight::motion::FrameCondition::vfunc_6 (330 B): equivalent/0x0013a9e0.cpp
// sym: ?vfunc_6@FrameCondition@fn_f30d2d27@@UAEDHPAVParams_13a9e0@fight@@H@Z @8a1cce5c2a27 @wd3bb9be582db
// STATUS: equivalent (tools/equiv.py level 3: 3035 inputs, branch coverage 30/30; Wine build 3036 inputs, 30/30)
// hulkfight::motion::FrameCondition::vfunc_6 @ 0x0013a9e0
char FrameCondition::vfunc_6(int a, fight::Params_13a9e0 *params, int c)
{
    if (dynamic_cast<CFightParams_13a9e0 *>(params) == 0)
        return 0;
    DriverSet_13a9e0 *drivers = FUN_00059a40(FUN_000592a0(params));
    if (drivers == 0)
        return 0;

    unsigned int count = drivers->count;
    for (unsigned int i = 0; i < count; i++) {
        choreo2::AnimationDriver_13a9e0 *drv = dynamic_cast<choreo2::AnimationDriver_13a9e0 *>(((choreo2 :: Driver_13a9e0 *)((owners::C_222e20 *)drivers)->FUN_00222e20((unsigned)i)));
        if (drv == 0 || drv->info == 0)
            continue;
        if (drv->info->idLo != idLo || drv->info->idHi != idHi)
            continue;
        float v = drv->value;
        switch (mode) {
        case 0: return v < threshold;
        case 1: return v <= threshold;
        case 2: return FUN_00018960(v, threshold, 1e-5f);
        case 3: return FUN_00018960(v, threshold, 1e-5f) == 0;
        case 4: return v >= threshold;
        case 5: return v > threshold;
        }
        return 0;
    }
    return 0;
}

} // namespace fn_f30d2d27

// 0x0013ab50 hulkfight::motion::FrameReachedCondition::vfunc_6 (459 B): equivalent/0x0013ab50.cpp [wrapped: conflict: FUN_00059a40]
// sym: ?vfunc_6@FrameReachedCondition@fn_0013ab50@@UAEDHPAVParams_13ab50@fight@2@H@Z @0a29ee7495d4 @w007bf94d7887
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0013ab50 {
// STATUS: equivalent (tools/equiv.py level 3: 3099 inputs, branch coverage 36/36; Wine build 3048 inputs, 36/36)
// hulkfight::motion::FrameReachedCondition::vfunc_6 @ 0x0013ab50
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

namespace fight {
class Params_13ab50 {
public:
    virtual void vfunc_0();
};
}

class CFightParams_13ab50 : public fight::Params_13ab50 {
public:
    virtual void vfunc_0();
};

namespace choreo2 {
class Driver_13ab50 {
public:
    virtual void vfunc_0();
};
}

struct DriverInfo_13ab50 {
    char pad0[8];
    int idLo;
    int idHi;
    char pad10[4];
    float scale;
};

namespace choreo2 {
class AnimationDriver_13ab50 : public Driver_13ab50 {
public:
    virtual void vfunc_0();
    char pad04[0x1c];
    DriverInfo_13ab50 *info;
    char pad24[0x224 - 0x24];
    char wraps;
    char pad225[3];
    float rate;
    float wrapA;
    float wrapB;
    char pad234[8];
    float value;
};
}

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *obj);

struct DriverSet_13ab50 {
    char pad0[0x68];
    unsigned int count;
};
DriverSet_13ab50 *__fastcall FUN_00059a40(Context *ctx);

struct Clock_13ab50 {
    hulk_freg FUN_000860c0();
};
struct World {
    char pad0[0x58];
    Clock_13ab50 *clock;
};

class FrameReachedCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, fight::Params_13ab50 *params, int c);
    char pad04[0xc];
    int idLo;
    int idHi;
    float threshold;
};

char FrameReachedCondition::vfunc_6(int a, fight::Params_13ab50 *params, int c)
{
    if (dynamic_cast<CFightParams_13ab50 *>(params) == 0)
        return 0;
    DriverSet_13ab50 *drivers = FUN_00059a40(FUN_000592a0(params));
    if (drivers == 0)
        return 0;
    unsigned int count = drivers->count;
    for (unsigned int i = 0; i < count; i++) {
        choreo2::AnimationDriver_13ab50 *drv = dynamic_cast<choreo2::AnimationDriver_13ab50 *>(((choreo2 :: Driver_13ab50 *)((owners::C_222e20 *)drivers)->FUN_00222e20((unsigned)i)));
        if (drv == 0 || drv->info == 0)
            continue;
        if (drv->info->idLo != idLo || drv->info->idHi != idHi)
            continue;
        float lo = drv->value;
        float hi = drv->info->scale * drv->rate * DAT_004dd700->clock->FUN_000860c0() + lo;
        if (hi < lo) {
            float t = hi;
            hi = lo;
            lo = t;
        }
        if (lo < threshold && threshold <= hi)
            return 1;
        if (!drv->wraps)
            return 0;
        float wa = drv->wrapA;
        float wb = drv->wrapB;
        if (lo < wb && wb <= hi) {
            return lo + (wa - wb) < threshold && threshold <= hi + (wa - wb);
        }
        if (lo < wa && wa <= hi) {
            return lo + (wb - wa) < threshold && threshold <= hi + (wb - wa);
        }
        return 0;
    }
    return 0;
}
} // namespace fn_0013ab50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f30d2d27 {

// 0x0013ad20 FUN_0013ad20 (79 B): matches/0x0013ad20.cpp
// sym: ??0AnimationAction@fn_f30d2d27@@QAE@HPAVOther_13ad20@1@@Z
AnimationAction::AnimationAction(int value, Other_13ad20* other) {
    s.a = value;
    if (other)
        other->AddRef();
    if (s.b)
        s.b->Release();
    s.b = other;
}

} // namespace fn_f30d2d27

// 0x0013ad70 FUN_0013ad70 (69 B): matches/0x0013ad70.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?Destroy@AnimationAction@motion@hulkfight@fn_0013ad70@@QAEXXZ
namespace fn_0013ad70 {
extern char hulk_at_00412570;

namespace hulkfight {
namespace motion {

class MemObj {
  public:
    virtual void f0();
    virtual void Release();
};

class Base_13ad70 {
  public:
    virtual void vf();
    void Cleanup_002326a0();
    char pad[0x18];
};

class AnimationAction : public Base_13ad70 {
  public:
    void Destroy();
    MemObj* m1c;
    MemObj* m20;
    MemObj* m24;
};

void AnimationAction::Destroy() {
    volatile int* v = (volatile int*)this;
    v[0] = (hulk_intptr)&hulk_at_00412570;
    MemObj* a = (MemObj*)v[8];
    if (a) {
        a->Release();
        v[8] = 0;
    }
    int b = v[7];
    if (b) {
        v[7] = 0;
    }
    MemObj* c = (MemObj*)v[9];
    if (c) {
        c->Release();
        v[9] = 0;
    }
    Base_13ad70::Cleanup_002326a0();
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013ad70


// 0x0013adc0 hulkfight::motion::AnimationAction::vfunc_4 (88 B): equivalent/0x0013adc0.cpp
// sym: ?vfunc_4@AnimationAction@motion@hulkfight@@UAEXXZ @3d982c555041 @w794e7460a0a1
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::AnimationAction::vfunc_4 @ 0x0013adc0
void hulkfight::motion::AnimationAction::vfunc_4() { if ((*(AnimationClip * *)&this->f_24)) { Link* link = (Link*)(*(Context_13adc0 * *)&this->f_20)->FUN_000592a0(); Controller* controller = (Controller*)link->FUN_00059a40(); if (controller) { if ((*(AnimationClip * *)&this->f_24)->flag) controller->FUN_00222b50((*(AnimationClip * *)&this->f_24), 0, -1.0f); else controller->FUN_00222970((*(AnimationClip * *)&this->f_24), 0); if ((*(AnimationClip * *)&this->f_24)) { (*(AnimationClip * *)&this->f_24)->vfunc_1(); (*(AnimationClip * *)&this->f_24) = 0; } } } }


// 0x0013ae20 hulkfight::motion::GrappleAnimationTrack::vfunc_5 (30 B): matches/0x0013ae20.cpp
// sym: ??_GGrappleAnimationTrack@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::GrappleAnimationTrack::~GrappleAnimationTrack() {}


// 0x0013ae40 hulkfight::motion::GrappleAnimationTrack::vfunc_10 (58 B): matches/0x0013ae40.cpp
// sym: ?vfunc_10@GrappleAnimationTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::GrappleAnimationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int v = Find_0005a470(c);
    if (v) {
        NewObject* p = Alloc_0008d690(0x28);
        if (p)
            return p->Init_0013ad20(this, v);
    }
    return 0;
}

namespace fn_f30d2d27 {

// 0x0013ae80 FUN_0013ae80 (79 B): matches/0x0013ae80.cpp
// sym: ??0AnimationPhaseMatchedAction@fn_f30d2d27@@QAE@HPAVRef_13ae80@1@@Z
AnimationPhaseMatchedAction::AnimationPhaseMatchedAction(int a, Ref_13ae80* r) : Action_13ae80() {
    int* p = &mA;
    *p = 0;
    mRef = 0;
    mC = 0;
    mA = a;
    if (r)
        r->Fn0();
    if (mRef) {
        Ref_13ae80* q = mRef;
        q->Fn();
    }
    mRef = r;
}

} // namespace fn_f30d2d27

// 0x0013aed0 FUN_0013aed0 (69 B): matches/0x0013aed0.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?Destroy@AnimationAction@motion@hulkfight@fn_0013aed0@@QAEXXZ
namespace fn_0013aed0 {
// Same code shape as 0x0013ad70 (propagated; names are from that function)
extern char hulk_at_0041258c;

namespace hulkfight {
namespace motion {

class MemObj {
  public:
    virtual void f0();
    virtual void Release();
};

class Base_13aed0 {
  public:
    virtual void vf();
    void Cleanup_002326a0();
    char pad[0x18];
};

class AnimationAction : public Base_13aed0 {
  public:
    void Destroy();
    MemObj* m1c;
    MemObj* m20;
    MemObj* m24;
};

void AnimationAction::Destroy() {
    volatile int* v = (volatile int*)this;
    v[0] = (hulk_intptr)&hulk_at_0041258c;
    MemObj* a = (MemObj*)v[8];
    if (a) {
        a->Release();
        v[8] = 0;
    }
    int b = v[7];
    if (b) {
        v[7] = 0;
    }
    MemObj* c = (MemObj*)v[9];
    if (c) {
        c->Release();
        v[9] = 0;
    }
    Base_13aed0::Cleanup_002326a0();
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013aed0


// 0x0013af20 hulkfight::motion::AnimationPhaseMatchedAction::vfunc_5 (288 B): equivalent/0x0013af20.cpp
// sym: ?vfunc_5@AnimationPhaseMatchedAction@motion@hulkfight@@UAE_NHH@Z @4c42a813c5ab @wf040abf8a17a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// hulkfight::motion::AnimationPhaseMatchedAction::vfunc_5 @ 0x0013af20
bool hulkfight::motion::AnimationPhaseMatchedAction::vfunc_5(hulk_intptr flag, int unused) {
 if(flag) return true;
 if(!(*(Context_13af20 * *)&this->f_20)) return false;
 Entries_13af20* entries=((Controller_13af20 *)((owners::Object_592a0 *)((*(Context_13af20 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a40();
 if(!entries) return false;
 for(unsigned i=0;i<entries->count;++i) {
 Phase* phase=(Phase*)FUN_00344e74(((void *)((owners::C_222e20 *)entries)->FUN_00222e20(i)),0,&DAT_0048d534,&DAT_004ac1d0,0);
 if(!phase) continue;
 phase->v9(0);
 float duration=phase->duration;
 if(duration>0.0f) {
 float scale=(*(Animation_13af20 * *)&this->f_24)->FUN_00225ab0();
 (*(Animation_13af20 * *)&this->f_24)->speed=scale*(*(Animation_13af20 * *)&this->f_24)->speed/duration;
 }
 float start=(*(Animation_13af20 * *)&this->f_24)->start;
 float end=(*(Animation_13af20 * *)&this->f_24)->end;
 float value=(end-start)*phase->phase+(*(Offset_13af20 * *)&this->f_1c)->value;
 float result=FUN_0004af40(start,end,value);
 (*(Animation_13af20 * *)&this->f_24)->FUN_00225cf0(result);
 break;
 }
 return true;
}


// 0x0013b040 hulkfight::motion::AnimationPhaseMatchedAction::vfunc_4 (63 B): matches/0x0013b040.cpp
// sym: ?vfunc_4@AnimationPhaseMatchedAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::AnimationPhaseMatchedAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        void* x = ((void *)((owners::Object_592a0 *)(((Helper_13b040*)(*(void * *)&this->f_20))))->FUN_000592a0());
        x = ((Helper_13b040*)x)->next_00059a40();
        if (x) {
            ((Helper_13b040*)x)->act_00222970((*(void * *)&this->f_24), 0);
            if ((*(void * *)&this->f_24)) {
                ((PhaseObj*)(*(void * *)&this->f_24))->f1();
                (*(void * *)&this->f_24) = 0;
            }
        }
    }
}

namespace fn_f30d2d27 {

// 0x0013b080 FUN_0013b080 (79 B): matches/0x0013b080.cpp
// sym: ??0AnimationVelocityScaledAction@fn_f30d2d27@@QAE@HPAVOwner_13b080@1@@Z
AnimationVelocityScaledAction::AnimationVelocityScaledAction(int x, Owner_13b080* o) : Action_13b080() {
    int* q = &mArg;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    mArg = x;
    if (o)
        o->A();
    if (mOwner)
        mOwner->B();
    mOwner = o;
}

} // namespace fn_f30d2d27

// 0x0013b0d0 FUN_0013b0d0 (69 B): matches/0x0013b0d0.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?Destroy@AnimationAction@motion@hulkfight@fn_0013b0d0@@QAEXXZ
namespace fn_0013b0d0 {
// Same code shape as 0x0013ad70 (propagated; names are from that function)
extern char hulk_at_004125a8;

namespace hulkfight {
namespace motion {

class MemObj {
  public:
    virtual void f0();
    virtual void Release();
};

class Base_13b0d0 {
  public:
    virtual void vf();
    void Cleanup_002326a0();
    char pad[0x18];
};

class AnimationAction : public Base_13b0d0 {
  public:
    void Destroy();
    MemObj* m1c;
    MemObj* m20;
    MemObj* m24;
};

void AnimationAction::Destroy() {
    volatile int* v = (volatile int*)this;
    v[0] = (hulk_intptr)&hulk_at_004125a8;
    MemObj* a = (MemObj*)v[8];
    if (a) {
        a->Release();
        v[8] = 0;
    }
    int b = v[7];
    if (b) {
        v[7] = 0;
    }
    MemObj* c = (MemObj*)v[9];
    if (c) {
        c->Release();
        v[9] = 0;
    }
    Base_13b0d0::Cleanup_002326a0();
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013b0d0


// 0x0013b120 hulkfight::motion::AnimationVelocityScaledAction::vfunc_4 (88 B): matches/0x0013b120.cpp
// sym: ?vfunc_4@AnimationVelocityScaledAction@motion@hulkfight@@UAEXXZ
 // namespace hulkfight
void hulkfight::motion::AnimationVelocityScaledAction::vfunc_4() {
    if (!(*(Obj_13b120 * *)&this->f_24))
        return;
    Result_13b120* p = (*(Owner_13b120 * *)&this->f_20)->Get_000592a0()->Get_00059a40();
    if (!p)
        return;
    if ((*(Obj_13b120 * *)&this->f_24)->flag)
        p->StopB_00222b50((*(Obj_13b120 * *)&this->f_24), 0, -1.0f);
    else
        p->StopA_00222970((*(Obj_13b120 * *)&this->f_24), 0);
    if ((*(Obj_13b120 * *)&this->f_24)) {
        (*(Obj_13b120 * *)&this->f_24)->f1();
        (*(Obj_13b120 * *)&this->f_24) = 0;
    }
}

namespace fn_f30d2d27 {

// 0x0013b180 FUN_0013b180 (79 B): matches/0x0013b180.cpp
// sym: ??0AnimationChargeAction@fn_f30d2d27@@QAE@HPAVRef@1@@Z
AnimationChargeAction::AnimationChargeAction(int x, Ref* r) : value(), ref(0), other(0) {
    value = x;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
}

} // namespace fn_f30d2d27

// 0x0013b1d0 FUN_0013b1d0 (69 B): matches/0x0013b1d0.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?Destroy@AnimationAction@motion@hulkfight@fn_0013b1d0@@QAEXXZ
namespace fn_0013b1d0 {
// Same code shape as 0x0013ad70 (propagated; names are from that function)
extern char hulk_at_004125c4;

namespace hulkfight {
namespace motion {

class MemObj {
  public:
    virtual void f0();
    virtual void Release();
};

class Base_13b1d0 {
  public:
    virtual void vf();
    void Cleanup_002326a0();
    char pad[0x18];
};

class AnimationAction : public Base_13b1d0 {
  public:
    void Destroy();
    MemObj* m1c;
    MemObj* m20;
    MemObj* m24;
};

void AnimationAction::Destroy() {
    volatile int* v = (volatile int*)this;
    v[0] = (hulk_intptr)&hulk_at_004125c4;
    MemObj* a = (MemObj*)v[8];
    if (a) {
        a->Release();
        v[8] = 0;
    }
    int b = v[7];
    if (b) {
        v[7] = 0;
    }
    MemObj* c = (MemObj*)v[9];
    if (c) {
        c->Release();
        v[9] = 0;
    }
    Base_13b1d0::Cleanup_002326a0();
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013b1d0


// 0x0013b220 hulkfight::motion::AnimationChargeAction::vfunc_5 (127 B): equivalent/0x0013b220.cpp
// sym: ?vfunc_5@AnimationChargeAction@motion@hulkfight@@UAE_NHH@Z @dfe5a263177f @wf35148dff070
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::AnimationChargeAction::vfunc_5 @ 0x0013b220
bool hulkfight::motion::AnimationChargeAction::vfunc_5(hulk_intptr skip, int unused) {
    if (skip == 0) {
        float t = ((Context_13b220 *)((owners::Object_592a0 *)((*(Manager_13b220 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30()->blend;
        if (t >= 0.0f && t <= 1.0f) {
        } else if (t > 1.0f) {
            t = 1.0f;
        } else {
            t = 0.0f;
        }
        (*(Dial * *)&this->f_24)->FUN_00225cf0(((*(Dial * *)&this->f_24)->to - (*(Dial * *)&this->f_24)->from) * t + (*(Dial * *)&this->f_24)->from);
    }
    return true;
}


// 0x0013b2a0 hulkfight::motion::AnimationChargeAction::vfunc_4 (63 B): matches/0x0013b2a0.cpp
// sym: ?vfunc_4@AnimationChargeAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x0013b040 (propagated; names are from that function)
void hulkfight::motion::AnimationChargeAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        void* x = ((void *)((owners::Object_592a0 *)(((Helper_13b2a0*)(*(void * *)&this->f_20))))->FUN_000592a0());
        x = ((Helper_13b2a0*)x)->next_00059a40();
        if (x) {
            ((Helper_13b2a0*)x)->act_00222970((*(void * *)&this->f_24), 0);
            if ((*(void * *)&this->f_24)) {
                ((PhaseObj*)(*(void * *)&this->f_24))->f1();
                (*(void * *)&this->f_24) = 0;
            }
        }
    }
}

namespace fn_f30d2d27 {

// 0x0013b2e0 FUN_0013b2e0 (79 B): matches/0x0013b2e0.cpp
// sym: ??0AnimationLinkedAction_13b2e0@fn_f30d2d27@@QAE@HPAURef_13b2e0@1@@Z
AnimationLinkedAction_13b2e0::AnimationLinkedAction_13b2e0(int a, Ref_13b2e0* r) {
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m1c = a;
    if (r)
        r->AddRef();
    if (m20)
        m20->Release();
    m20 = r;
}

} // namespace fn_f30d2d27

// 0x0013b330 FUN_0013b330 (69 B): matches/0x0013b330.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?Destroy@AnimationAction@motion@hulkfight@fn_0013b330@@QAEXXZ
namespace fn_0013b330 {
// Same code shape as 0x0013ad70 (propagated; names are from that function)
extern char hulk_at_004125e0;

namespace hulkfight {
namespace motion {

class MemObj {
  public:
    virtual void f0();
    virtual void Release();
};

class Base_13b330 {
  public:
    virtual void vf();
    void Cleanup_002326a0();
    char pad[0x18];
};

class AnimationAction : public Base_13b330 {
  public:
    void Destroy();
    MemObj* m1c;
    MemObj* m20;
    MemObj* m24;
};

void AnimationAction::Destroy() {
    volatile int* v = (volatile int*)this;
    v[0] = (hulk_intptr)&hulk_at_004125e0;
    MemObj* a = (MemObj*)v[8];
    if (a) {
        a->Release();
        v[8] = 0;
    }
    int b = v[7];
    if (b) {
        v[7] = 0;
    }
    MemObj* c = (MemObj*)v[9];
    if (c) {
        c->Release();
        v[9] = 0;
    }
    Base_13b330::Cleanup_002326a0();
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013b330


// 0x0013b380 hulkfight::motion::AnimationLinkedAction::vfunc_4 (68 B): matches/0x0013b380.cpp
// sym: ?vfunc_4@AnimationLinkedAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::AnimationLinkedAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        Service_13b380* x = ((Service_13b380 *)((owners::Object_592a0 *)((*(Service_13b380 * *)&this->f_20)))->FUN_000592a0());
        Service_13b380* y = x->check_00059a40();
        if (y) {
            y->run_00222b50((*(void * *)&this->f_24), 0, -1.0f);
            if ((*(void * *)&this->f_24)) {
                ((Obj_13b380*)(*(void * *)&this->f_24))->b();
                (*(void * *)&this->f_24) = 0;
            }
        }
    }
}


// 0x0013b3f0 fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>::vfunc_6 (26 B): matches/0x0013b3f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>::**)(int))&this->f_10))(b);
}


// 0x0013b410 fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>::vfunc_2 (11 B): matches/0x0013b410.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b450 fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_7 (6 B): matches/0x0013b450.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0013b460 fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_6 (30 B): matches/0x0013b460.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_13b460 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_13b460*)&DAT_003f335c));
}


// 0x0013b480 fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_8 (26 B): matches/0x0013b480.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::FrameCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::**)(int))&this->f_18))(b);
}


// 0x0013b4a0 fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_2 (11 B): matches/0x0013b4a0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0013b4d0 fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>::vfunc_6 (26 B): matches/0x0013b4d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>::**)(int))&this->f_10))(b);
}


// 0x0013b4f0 fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>::vfunc_2 (11 B): matches/0x0013b4f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b520 fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>::vfunc_6 (26 B): matches/0x0013b520.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b540 fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>::vfunc_2 (11 B): matches/0x0013b540.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b580 fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_7 (6 B): matches/0x0013b580.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0013b590 fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_6 (30 B): matches/0x0013b590.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_13b590 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_13b590*)&DAT_003f335c));
}


// 0x0013b5b0 fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_8 (26 B): matches/0x0013b5b0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::**)(int))&this->f_18))(b);
}


// 0x0013b5d0 fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_2 (11 B): matches/0x0013b5d0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0013b600 fight::ParamBool<hulkfight::motion::AnimationTrack>::vfunc_6 (26 B): matches/0x0013b600.cpp
// sym: ?vfunc_6@?$ParamBool@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::AnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::AnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::AnimationTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::AnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b620 fight::ParamBool<hulkfight::motion::AnimationTrack>::vfunc_2 (11 B): matches/0x0013b620.cpp
// sym: ?vfunc_2@?$ParamBool@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::AnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f30d2d27 {

// 0x0013b630 FUN_0013b630 (32 B): matches/0x0013b630.cpp
// sym: ??0ParamIntConstRange_13b630@fn_f30d2d27@@QAE@HH@Z
ParamIntConstRange_13b630::ParamIntConstRange_13b630(int a, int b) : ParamValueInt_13b630(a) {
    vptr = ((void**)DAT_004126cc);
    m10 = b;
}

} // namespace fn_f30d2d27

// 0x0013b650 fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>::vfunc_6 (26 B): matches/0x0013b650.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b670 fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>::vfunc_2 (11 B): matches/0x0013b670.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b6a0 fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_6 (26 B): matches/0x0013b6a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b6c0 fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_2 (11 B): matches/0x0013b6c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b6f0 fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_6 (26 B): matches/0x0013b6f0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b710 fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_2 (11 B): matches/0x0013b710.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b740 fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_6 (26 B): matches/0x0013b740.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b760 fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_2 (11 B): matches/0x0013b760.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b790 fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_6 (26 B): matches/0x0013b790.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b7b0 fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_2 (11 B): matches/0x0013b7b0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b7e0 fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_6 (26 B): matches/0x0013b7e0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b800 fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_2 (11 B): matches/0x0013b800.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b830 fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_6 (26 B): matches/0x0013b830.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b850 fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_2 (11 B): matches/0x0013b850.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b880 fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_6 (26 B): matches/0x0013b880.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b8a0 fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_2 (11 B): matches/0x0013b8a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b8e0 fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_7 (6 B): matches/0x0013b8e0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0013b8f0 fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_6 (30 B): matches/0x0013b8f0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_13b8f0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_13b8f0*)&DAT_003f335c));
}


// 0x0013b910 fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_8 (26 B): matches/0x0013b910.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::**)(int))&this->f_18))(b);
}


// 0x0013b930 fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_2 (11 B): matches/0x0013b930.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0013b960 fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_6 (26 B): matches/0x0013b960.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::**)(int))&this->f_10))(b);
}


// 0x0013b980 fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_2 (11 B): matches/0x0013b980.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0013b9a0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameReachedCondition>::vfunc_0 (36 B): matches/0x0013b9a0.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate; hulkfight::motion::FrameReachedCondition]
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VFrameReachedCondition@motion@hulkfight@fn_0013b9a0@@@fight@fn_0013b9a0@@UAE_NPAX@Z
namespace fn_0013b9a0 {
extern "C++" __declspec(nothrow) int __cdecl check(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FrameReachedCondition {};
} // namespace motion
} // namespace hulkfight
extern void* hulk_at_00491ca8;
extern void* hulk_at_004ac870;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameReachedCondition>::vfunc_0(void* p) {
    return check(p, 0, &hulk_at_00491ca8, &hulk_at_004ac870, 0) != 0;
}
} // namespace fn_0013b9a0


// 0x0013b9d0 fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>::vfunc_0 (30 B): matches/0x0013b9d0.cpp
// sym: ??_G?$ParamFloatConstRange@VFrameReachedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::FrameReachedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13b9d0)
#endif

namespace fn_f30d2d27 {

// 0x0013b9f0 FUN_0013b9f0 (9 B): matches/0x0013b9f0.cpp
// sym: ??0ConditionFactoryCasterTemplate_13b9f0@fn_f30d2d27@@QAE@XZ
ConditionFactoryCasterTemplate_13b9f0::ConditionFactoryCasterTemplate_13b9f0() {
    vptr = hulk_at_00412820;
    _ReadWriteBarrier();
}

} // namespace fn_f30d2d27

// 0x0013ba00 fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameCondition>::vfunc_0 (36 B): matches/0x0013ba00.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate; hulkfight::motion::FrameCondition]
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VFrameCondition@motion@hulkfight@fn_0013ba00@@@fight@fn_0013ba00@@UAE_NPBD@Z
namespace fn_0013ba00 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FrameCondition {};
} // namespace motion
} // namespace hulkfight
extern int FUN_00344e74(const char*, int, const void*, const void*, int);
extern int g1, hulk_at_004ac928;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameCondition>::vfunc_0(const char* p) {
    return FUN_00344e74(p, 0, &g1, &hulk_at_004ac928, 0) != 0;
}
} // namespace fn_0013ba00


// 0x0013ba30 fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_0 (30 B): matches/0x0013ba30.cpp
// sym: ??_G?$ParamEnumConstList@VFrameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::FrameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13ba30)
#endif


// 0x0013ba50 fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>::vfunc_0 (30 B): matches/0x0013ba50.cpp
// sym: ??_G?$ParamFloatConstRange@VFrameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13ba50)
#endif


// 0x0013ba80 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationTrack>::vfunc_0 (36 B): matches/0x0013ba80.cpp [wrapped: conflict: FUN_00344e74; a; b; fight::TrackFactoryCaster (+1)]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAnimationTrack@motion@hulkfight@fn_0013ba80@@@fight@fn_0013ba80@@UAEHPAX@Z
namespace fn_0013ba80 {
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class AnimationTrack;
}
} // namespace hulkfight
extern int FUN_00344e74(void*, int, void*, void*, int);
extern int a;
extern int hulk_at_004ac9d8;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &hulk_at_004ac9d8, 0) != 0;
}
} // namespace fn_0013ba80


// 0x0013bab0 fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>::vfunc_0 (30 B): matches/0x0013bab0.cpp
// sym: ??_G?$ParamFloatConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bab0)
#endif


// 0x0013bad0 fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_0 (30 B): matches/0x0013bad0.cpp
// sym: ??_G?$ParamEnumConstList@VAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bad0)
#endif


// 0x0013baf0 fight::ParamBool<hulkfight::motion::AnimationTrack>::vfunc_0 (30 B): matches/0x0013baf0.cpp
// sym: ??_G?$ParamBool@VAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::AnimationTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::AnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13baf0)
#endif


// 0x0013bb10 fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>::vfunc_0 (30 B): matches/0x0013bb10.cpp
// sym: ??_G?$ParamIntConstRange@VAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bb10)
#endif


// 0x0013bb40 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationChargeTrack>::vfunc_0 (36 B): matches/0x0013bb40.cpp [wrapped: conflict: Check; a; b; fight::TrackFactoryCaster (+1)]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAnimationChargeTrack@motion@hulkfight@fn_0013bb40@@@fight@fn_0013bb40@@UAE_NPAX@Z
namespace fn_0013bb40 {
extern "C++" __declspec(nothrow) int __cdecl Check(void*, int, const void*, const void*, int);
extern int a;
extern int hulk_at_004aca88;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class AnimationChargeTrack;
}
} // namespace hulkfight
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationChargeTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &hulk_at_004aca88, 0) != 0;
}
} // namespace fn_0013bb40


// 0x0013bb70 fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_0 (30 B): matches/0x0013bb70.cpp
// sym: ??_G?$ParamFloatConstRange@VAnimationChargeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::AnimationChargeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bb70)
#endif


// 0x0013bb90 fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>::vfunc_0 (30 B): matches/0x0013bb90.cpp
// sym: ??_G?$ParamIntConstRange@VAnimationChargeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::AnimationChargeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bb90)
#endif


// 0x0013bbc0 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationLinkedTrack>::vfunc_0 (36 B): matches/0x0013bbc0.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate; hulkfight::motion::AnimationLinkedTrack]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAnimationLinkedTrack@motion@hulkfight@fn_0013bbc0@@@fight@fn_0013bbc0@@UAEHPAX@Z
namespace fn_0013bbc0 {
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
namespace motion {
class AnimationLinkedTrack {};
} // namespace motion
} // namespace hulkfight
extern "C++" __declspec(nothrow) int __cdecl check(void*, int, void*, void*, int);
extern void* a;
extern void* hulk_at_004acb40;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationLinkedTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &hulk_at_004acb40, 0) != 0;
}
} // namespace fn_0013bbc0


// 0x0013bbf0 fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_0 (30 B): matches/0x0013bbf0.cpp
// sym: ??_G?$ParamFloatConstRange@VAnimationLinkedTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::AnimationLinkedTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bbf0)
#endif


// 0x0013bc10 fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>::vfunc_0 (30 B): matches/0x0013bc10.cpp
// sym: ??_G?$ParamIntConstRange@VAnimationLinkedTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::AnimationLinkedTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bc10)
#endif

namespace fn_f30d2d27 {

// 0x0013bc40 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_0 (36 B): matches/0x0013bc40.cpp
// sym: ?vfunc_0@TrackFactoryCasterTemplate@fn_f30d2d27@@UAEHPAX@Z
int TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return (int)FUN_00344e74(p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&hulk_at_004acbf8, 0) != 0;
}

} // namespace fn_f30d2d27

// 0x0013bc70 fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_0 (30 B): matches/0x0013bc70.cpp
// sym: ??_G?$ParamFloatConstRange@VAnimationPhaseMatchedTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bc70)
#endif


// 0x0013bc90 fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_0 (30 B): matches/0x0013bc90.cpp
// sym: ??_G?$ParamIntConstRange@VAnimationPhaseMatchedTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::AnimationPhaseMatchedTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bc90)
#endif


// 0x0013bcc0 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_0 (36 B): matches/0x0013bcc0.cpp [wrapped: conflict: a]
// sym: ?check@Caster@fn_0013bcc0@@UAEHPAX@Z
namespace fn_0013bcc0 {
class Base {
  public:
    virtual int check(void*);
    virtual void other();
};
class Caster : public Base {
  public:
    virtual int check(void*);
    virtual void other();
};
extern int a, hulk_at_004accc0;
int Caster::check(void* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &a, &hulk_at_004accc0, 0)) != 0;
}
} // namespace fn_0013bcc0


// 0x0013bcf0 fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_0 (30 B): matches/0x0013bcf0.cpp
// sym: ??_G?$ParamFloatConstRange@VAnimationVelocityScaledTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bcf0)
#endif


// 0x0013bd10 fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_0 (30 B): matches/0x0013bd10.cpp
// sym: ??_G?$ParamEnumConstList@VAnimationVelocityScaledTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bd10)
#endif


// 0x0013bd30 fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_0 (30 B): matches/0x0013bd30.cpp
// sym: ??_G?$ParamIntConstRange@VAnimationVelocityScaledTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13bd30)
#endif


// 0x0013bd60 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleAnimationTrack>::vfunc_0 (36 B): matches/0x0013bd60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGrappleAnimationTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleAnimationTrack>::vfunc_0(void* __p0) { GrappleAnimationTrack_13bd60 * p = (GrappleAnimationTrack_13bd60 *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(p), 0, &a, &hulk_at_004acd80, 0)) != 0;
}


// 0x0013bde0 hulkfight::motion::AnimationAction::vfunc_2 (90 B): matches/0x0013bde0.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?vfunc_2@AnimationAction@motion@hulkfight@fn_0013bde0@@QAEPAV1234@E@Z
namespace fn_0013bde0 {
extern "C" {
extern "C" char DAT_00412570[];
extern "C++" { __declspec(nothrow) void __cdecl opdel_0008d330(void*); }
void _ReadWriteBarrier();
}

class RefObj_13bde0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};

namespace hulkfight {
namespace motion {

class AnimationAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    AnimationAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    void Cleanup_002326a0();

    char pad[0x18];
    int m1c;
    RefObj_13bde0* m20;
    RefObj_13bde0* m24;
};

AnimationAction* AnimationAction::vfunc_2(unsigned char param) {
    *(hulk_intptr*)this = (hulk_intptr)DAT_00412570;
    _ReadWriteBarrier();
    RefObj_13bde0* a = m20;
    if (a) {
        a->Release();
        m20 = 0;
    }
    int v = m1c;
    if (v) {
        m1c = 0;
    }
    RefObj_13bde0* b = m24;
    if (b) {
        b->Release();
        m24 = 0;
    }
    this->Cleanup_002326a0();
    if (param & 1) {
        opdel_0008d330(this);
    }
    return this;
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013bde0


// 0x0013be90 hulkfight::motion::AnimationPhaseMatchedAction::vfunc_2 (90 B): matches/0x0013be90.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?vfunc_2@AnimationAction@motion@hulkfight@fn_0013be90@@QAEPAV1234@E@Z
namespace fn_0013be90 {
// Same code shape as 0x0013bde0 (propagated; names are from that function)
extern "C" {
extern "C" char DAT_0041258c[];
extern "C++" { __declspec(nothrow) void __cdecl opdel(void*); }
void _ReadWriteBarrier();
}

class RefObj_13be90 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};

namespace hulkfight {
namespace motion {

class AnimationAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    AnimationAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    void Cleanup_002326a0();

    char pad[0x18];
    int m1c;
    RefObj_13be90* m20;
    RefObj_13be90* m24;
};

AnimationAction* AnimationAction::vfunc_2(unsigned char param) {
    *(hulk_intptr*)this = (hulk_intptr)DAT_0041258c;
    _ReadWriteBarrier();
    RefObj_13be90* a = m20;
    if (a) {
        a->Release();
        m20 = 0;
    }
    int v = m1c;
    if (v) {
        m1c = 0;
    }
    RefObj_13be90* b = m24;
    if (b) {
        b->Release();
        m24 = 0;
    }
    this->Cleanup_002326a0();
    if (param & 1) {
        opdel(this);
    }
    return this;
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013be90


// 0x0013bf40 hulkfight::motion::AnimationVelocityScaledAction::vfunc_2 (90 B): matches/0x0013bf40.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?vfunc_2@AnimationAction@motion@hulkfight@fn_0013bf40@@QAEPAV1234@E@Z
namespace fn_0013bf40 {
// Same code shape as 0x0013bde0 (propagated; names are from that function)
extern "C" {
extern "C" char DAT_004125a8[];
extern "C++" { __declspec(nothrow) void __cdecl opdel(void*); }
void _ReadWriteBarrier();
}

class RefObj_13bf40 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};

namespace hulkfight {
namespace motion {

class AnimationAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    AnimationAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    void Cleanup_002326a0();

    char pad[0x18];
    int m1c;
    RefObj_13bf40* m20;
    RefObj_13bf40* m24;
};

AnimationAction* AnimationAction::vfunc_2(unsigned char param) {
    *(hulk_intptr*)this = (hulk_intptr)DAT_004125a8;
    _ReadWriteBarrier();
    RefObj_13bf40* a = m20;
    if (a) {
        a->Release();
        m20 = 0;
    }
    int v = m1c;
    if (v) {
        m1c = 0;
    }
    RefObj_13bf40* b = m24;
    if (b) {
        b->Release();
        m24 = 0;
    }
    this->Cleanup_002326a0();
    if (param & 1) {
        opdel(this);
    }
    return this;
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013bf40


// 0x0013bff0 hulkfight::motion::AnimationChargeAction::vfunc_2 (90 B): matches/0x0013bff0.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?vfunc_2@AnimationAction@motion@hulkfight@fn_0013bff0@@QAEPAV1234@E@Z
namespace fn_0013bff0 {
// Same code shape as 0x0013bde0 (propagated; names are from that function)
extern "C" {
extern "C" char DAT_004125c4[];
extern "C++" { __declspec(nothrow) void __cdecl opdel(void*); }
void _ReadWriteBarrier();
}

class RefObj_13bff0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};

namespace hulkfight {
namespace motion {

class AnimationAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    AnimationAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    void Cleanup_002326a0();

    char pad[0x18];
    int m1c;
    RefObj_13bff0* m20;
    RefObj_13bff0* m24;
};

AnimationAction* AnimationAction::vfunc_2(unsigned char param) {
    *(hulk_intptr*)this = (hulk_intptr)DAT_004125c4;
    _ReadWriteBarrier();
    RefObj_13bff0* a = m20;
    if (a) {
        a->Release();
        m20 = 0;
    }
    int v = m1c;
    if (v) {
        m1c = 0;
    }
    RefObj_13bff0* b = m24;
    if (b) {
        b->Release();
        m24 = 0;
    }
    this->Cleanup_002326a0();
    if (param & 1) {
        opdel(this);
    }
    return this;
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013bff0


// 0x0013c0a0 hulkfight::motion::AnimationLinkedAction::vfunc_2 (90 B): matches/0x0013c0a0.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?vfunc_2@AnimationAction@motion@hulkfight@fn_0013c0a0@@QAEPAV1234@E@Z
namespace fn_0013c0a0 {
// Same code shape as 0x0013bde0 (propagated; names are from that function)
extern "C" {
extern "C" char DAT_004125e0[];
extern "C++" { __declspec(nothrow) void __cdecl opdel(void*); }
void _ReadWriteBarrier();
}

class RefObj_13c0a0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};

namespace hulkfight {
namespace motion {

class AnimationAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    AnimationAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    void Cleanup_002326a0();

    char pad[0x18];
    int m1c;
    RefObj_13c0a0* m20;
    RefObj_13c0a0* m24;
};

AnimationAction* AnimationAction::vfunc_2(unsigned char param) {
    *(hulk_intptr*)this = (hulk_intptr)DAT_004125e0;
    _ReadWriteBarrier();
    RefObj_13c0a0* a = m20;
    if (a) {
        a->Release();
        m20 = 0;
    }
    int v = m1c;
    if (v) {
        m1c = 0;
    }
    RefObj_13c0a0* b = m24;
    if (b) {
        b->Release();
        m24 = 0;
    }
    this->Cleanup_002326a0();
    if (param & 1) {
        opdel(this);
    }
    return this;
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0013c0a0

namespace fn_f30d2d27 {

// 0x0013c140 fight::ParamName<hulkfight::motion::FrameReachedCondition>::vfunc_7 (12 B): matches/0x0013c140.cpp
// sym: ?vfunc_6@ParamBranch@fn_f30d2d27@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f30d2d27

// 0x0013c190 fight::ParamName<hulkfight::motion::FrameCondition>::vfunc_7 (12 B): matches/0x0013c190.cpp [wrapped: same definition as 0x0013c140 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0013c190@@UAEXPAX@Z
namespace fn_0013c190 {
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
} // namespace fn_0013c190


// 0x0013c1e0 fight::ParamName<hulkfight::motion::AnimationTrack>::vfunc_7 (12 B): matches/0x0013c1e0.cpp [wrapped: same definition as 0x0013c140 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0013c1e0@@UAEXPAX@Z
namespace fn_0013c1e0 {
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
} // namespace fn_0013c1e0

namespace fn_f30d2d27 {

// 0x0013c1f0 FUN_0013c1f0 (27 B): matches/0x0013c1f0.cpp
// sym: ?target@fn_f30d2d27@@YAXPAX@Z
void __cdecl target(void* p) {
    TrackFactoryCasterTemplate_13c1f0 c;
    use_00236ac0(p, &c);
}

} // namespace fn_f30d2d27

// 0x0013c230 fight::ParamName<hulkfight::motion::AnimationChargeTrack>::vfunc_7 (12 B): matches/0x0013c230.cpp [wrapped: same definition as 0x0013c140 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0013c230@@UAEXPAX@Z
namespace fn_0013c230 {
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
} // namespace fn_0013c230

namespace fn_f30d2d27 {

// 0x0013c260 FUN_0013c260 (32 B): matches/0x0013c260.cpp
// sym: ??0ParamName@fn_f30d2d27@@QAE@HH@Z
ParamName::ParamName(int a, int b) : ParamValueName_13c260(a), value(b) {}

} // namespace fn_f30d2d27

// 0x0013c280 fight::ParamName<hulkfight::motion::AnimationLinkedTrack>::vfunc_7 (12 B): matches/0x0013c280.cpp [wrapped: same definition as 0x0013c140 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0013c280@@UAEXPAX@Z
namespace fn_0013c280 {
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
} // namespace fn_0013c280


// 0x0013c290 FUN_0013c290 (27 B): matches/0x0013c290.cpp [wrapped: same definition as 0x0013c1f0 in this TU]
// sym: ?target@fn_0013c290@@YAXPAX@Z
namespace fn_0013c290 {
class TrackFactoryCasterTemplate_13c290 {
  public:
    virtual int Fnf_0013bc40(void*);
};
extern void fun_00236ac0(void*, TrackFactoryCasterTemplate_13c290*);
void target(void* p) {
    TrackFactoryCasterTemplate_13c290 c;
    fun_00236ac0(p, &c);
}
} // namespace fn_0013c290


// 0x0013c2d0 fight::ParamName<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_7 (12 B): matches/0x0013c2d0.cpp [wrapped: same definition as 0x0013c140 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0013c2d0@@UAEXPAX@Z
namespace fn_0013c2d0 {
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
} // namespace fn_0013c2d0


// 0x0013c320 fight::ParamName<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_7 (12 B): matches/0x0013c320.cpp [wrapped: same definition as 0x0013c140 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0013c320@@UAEXPAX@Z
namespace fn_0013c320 {
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
} // namespace fn_0013c320


// 0x0013c350 fight::ParamName<hulkfight::motion::FrameReachedCondition>::vfunc_0 (30 B): matches/0x0013c350.cpp
// sym: ??_G?$ParamName@VFrameReachedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::FrameReachedCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::FrameReachedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13c350)
#endif


// 0x0013c370 fight::ParamName<hulkfight::motion::FrameCondition>::vfunc_0 (30 B): matches/0x0013c370.cpp
// sym: ??_G?$ParamName@VFrameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::FrameCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::FrameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13c370)
#endif


// 0x0013c390 fight::ParamName<hulkfight::motion::AnimationTrack>::vfunc_0 (30 B): matches/0x0013c390.cpp
// sym: ??_G?$ParamName@VAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::AnimationTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::AnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13c390)
#endif


// 0x0013c3b0 fight::ParamName<hulkfight::motion::AnimationChargeTrack>::vfunc_0 (30 B): matches/0x0013c3b0.cpp
// sym: ??_G?$ParamName@VAnimationChargeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::AnimationChargeTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::AnimationChargeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13c3b0)
#endif


// 0x0013c3d0 fight::ParamName<hulkfight::motion::AnimationLinkedTrack>::vfunc_0 (30 B): matches/0x0013c3d0.cpp
// sym: ??_G?$ParamName@VAnimationLinkedTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::AnimationLinkedTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::AnimationLinkedTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13c3d0)
#endif


// 0x0013c3f0 fight::ParamName<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_0 (30 B): matches/0x0013c3f0.cpp
// sym: ??_G?$ParamName@VAnimationPhaseMatchedTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::AnimationPhaseMatchedTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::AnimationPhaseMatchedTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13c3f0)
#endif


// 0x0013c410 fight::ParamName<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_0 (30 B): matches/0x0013c410.cpp
// sym: ??_G?$ParamName@VAnimationVelocityScaledTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::AnimationVelocityScaledTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::AnimationVelocityScaledTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x13c410)
#endif


// 0x0013c530 FUN_0013c530 (231 B): equivalent/0x0013c530.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamFloatConstRange; fight::ParamName]
// sym: ?FUN_0013c530@fn_0013c530@@YAXXZ @05f69ba953ea @w98adf8dce2fe
namespace fn_0013c530 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_0013c530 @ 0x0013c530

void* __cdecl FUN_0008d690(unsigned int);

  
void FUN_001399f0(); void FUN_00139a10(); void FUN_00139a20();
struct FUN_00234a90 { virtual void slot(); char pad[12]; void (*callback)(); int tail; FUN_00234a90(const char* = "animation"); };
struct FUN_00234cc0 { virtual void slot(); char pad[12]; const char* names; int count; void (*callback)(); int tail; FUN_00234cc0(const char* = "compare"); };
struct FUN_00234960 { virtual void slot(); char pad[12]; void (*callback)(); int tail; FUN_00234960(const char* = "frame"); };
namespace hulkfight { namespace motion { class FrameCondition; } }
namespace fight {
template<class T> struct ParamName : FUN_00234a90 { virtual void slot(); };
template<class T> struct ParamEnumConstList : FUN_00234cc0 { virtual void slot(); };
template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot(); };
}
extern "C" void __cdecl FUN_002347b0(void*,void**,int);
void __cdecl FUN_0013c530() {
 if (!DAT_004e0f14) {
 void* items[3];
 void* p=FUN_0008d690((int)sizeof(fight::ParamName<hulkfight::motion::FrameCondition>));
 if(p) { fight::ParamName<hulkfight::motion::FrameCondition>* b=new(p) fight::ParamName<hulkfight::motion::FrameCondition>; b->callback=FUN_001399f0; items[0]=b; } else items[0]=0;
 p=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::motion::FrameCondition>));
 if(p) { int n=(*(int*)&DAT_00427754); fight::ParamEnumConstList<hulkfight::motion::FrameCondition>* b=new(p) fight::ParamEnumConstList<hulkfight::motion::FrameCondition>; b->count=n; b->names="lwB"; b->callback=FUN_00139a10; items[1]=b; } else items[1]=0;
 p=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>));
 if(p) { fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>* b=new(p) fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>; b->callback=FUN_00139a20; items[2]=b; } else items[2]=0;
 FUN_002347b0(&DAT_004e0f10,items,3);
 }
 ++DAT_004e0f14;
}
} // namespace fn_0013c530

namespace fn_f30d2d27 {

// 0x0013c620 FUN_0013c620 (38 B): matches/0x0013c620.cpp
// sym: _FUN_0013c620
extern "C" void FUN_0013c620(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_13c620 caster;
    owner->set_002367c0(find(name, &caster));
}

} // namespace fn_f30d2d27

// 0x0013c930 FUN_0013c930 (38 B): matches/0x0013c930.cpp [wrapped: conflict: find]
// sym: _FUN_0013c930
namespace fn_0013c930 {
class TrackFactoryCasterTemplate_13c930 {
  public:
    virtual bool cast_0013bb40(void*);
};
class Obj {
  public:
    void use_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* find_00236ac0(void*, TrackFactoryCasterTemplate_13c930*);
extern "C" void FUN_0013c930(Obj* o, void* p) {
    TrackFactoryCasterTemplate_13c930 c;
    o->use_002367c0(find_00236ac0(p, &c));
}
} // namespace fn_0013c930

namespace fn_f30d2d27 {

// 0x0013cb60 FUN_0013cb60 (38 B): matches/0x0013cb60.cpp
// sym: _FUN_0013cb60
extern "C" void FUN_0013cb60(Owner* o, const char* name) {
    TrackFactoryCasterTemplate_13cb60 caster;
    o->Set_002367c0(Find_00236ac0(name, &caster));
}


// 0x0013cdd0 FUN_0013cdd0 (38 B): matches/0x0013cdd0.cpp
// sym: _FUN_0013cdd0
extern "C" Track* FUN_0013cdd0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_13cdd0 caster;
    Track* p = Find_00236ac0(name, &caster);
    return owner->Add_002367c0(p);
}


// 0x0013d040 FUN_0013d040 (38 B): matches/0x0013d040.cpp
// sym: _FUN_0013d040
extern "C" void FUN_0013d040(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_13d040 c;
    owner->apply_002367c0(lookup(name, &c));
}


// 0x0013d3c0 FUN_0013d3c0 (77 B): matches/0x0013d3c0.cpp
// sym: _FUN_0013d3c0
extern "C" void __cdecl FUN_0013d3c0(Factory* factory) {
    {
        ConditionFactoryCasterTemplate_13d3c0 frame;
        factory->add_00236760(FUN_002343e0("frame", &frame));
    }
    {
        Reached reached;
        factory->add_00236760(FUN_002343e0("frameReached", &reached));
    }
}

} // namespace fn_f30d2d27

// 0x0013d410 hulkfight::motion::AnimationAction::vfunc_3 (870 B): equivalent/0x0013d410.cpp [wrapped: conflict: AnimationAction; FUN_00059a40; World; content::LoadInventory::DynamicCaster (+1)]
// sym: ?vfunc_3@AnimationAction@fn_0013d410@@UAE_NHH@Z @0cf2e1851a2e @w722d1e57c279
namespace fn_0013d410 {
// STATUS: equivalent (tools/equiv.py level 3: 3254 inputs, branch coverage 52/52; Wine build 700 inputs, 52/52)
// hulkfight::motion::AnimationAction::vfunc_3 @ 0x0013d410
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



namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class Animation; }

struct V3_13d410 {
    float x, y, z;
};

struct Id64_13d410 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(Id64_13d410 *src);
};

struct Animation {
    char pad0[8];
    Id64_13d410 id;
    float f10;
    float f14;
    char flag18;
};

namespace choreo2 {
class Driver {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_13d410 id;            // 8
};
}

namespace choreo2 {
class AnimationDriver : public choreo2::Driver {
public:
    char pad10[0x10];
    Animation *anim;    // 0x20
    char pad24[0x200];
    char b224;
    char b225;
    char pad226[6];
    float f22c;
    float f230;
    char b234;
    char b235;
    char pad236[6];
    float f23c;
    choreo2::AnimationDriver *FUN_00225950(void *rig, Animation *anim);
    void FUN_002224a0(int v);
    void FUN_00225e00(float t, V3_13d410 v);
    void FUN_00225cf0(float v);
    float FUN_00225b30();
};
}

struct Rig_13d410 {
    int FUN_0027b670(unsigned int lo, unsigned int hi);
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *owner);

struct LayerSet_13d410 {
    char pad0[0x64];
    Rig_13d410 **rigRef;
    unsigned int count;
    Rig_13d410 *FUN_002226b0();
    choreo2::Driver *FUN_00222e20(unsigned int index);
    void FUN_00222890(choreo2::AnimationDriver *d, float r, float a, float b, float c, float e, float f);
};
LayerSet_13d410 *__fastcall FUN_00059a40(Context *ctx);

class Factory_13d410 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo,
                          unsigned int hi);
};

struct Holder44_13d410 { Factory_13d410 *FUN_00203d70(); };
struct Holder28_13d410 { Holder44_13d410 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_13d410 *holder; };

class AnimData_13d410 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float GetValue();
    char pad4[0x14];
    unsigned int idLo;
    unsigned int idHi;
    float f20;
    float f24;
    float f28;
    float f2c;
    int mode;
    char b34;
    char pad35[3];
    unsigned int key2Lo;
    unsigned int key2Hi;
    float f40;
    float f44;
    float f48;
};

void *thunk_FUN_0008d690(unsigned int size);
hulk_freg FUN_000964e0();
hulk_freg __cdecl FUN_00225be0(float a, float b, float c, int d);

class AnimationAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    AnimData_13d410 *data;                  // 0x1c
    void *owner;                     // 0x20
    choreo2::AnimationDriver *driver; // 0x24
};

bool AnimationAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;
    LayerSet_13d410 *layers = FUN_00059a40(FUN_000592a0(owner));
    if (layers == 0)
        return false;

    union {
        hulk_freg v;
        char slot0[4];
    } u;
    hulk_freg f24;
    Rig_13d410 *rig = layers->FUN_002226b0();
    unsigned int lo = data->idLo;
    unsigned int hi = data->idHi;
    Factory_13d410 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
        new (u.slot0) content::LoadInventory::DynamicCaster<pure3d::Animation>;
    Animation *anim = factory->f3(caster, lo, hi);
    if (anim == 0)
        return false;

    bool reuse;
    bool found = false;
    int mode = data->mode;
    if (mode == 2 || (mode == 0 && anim->flag18)) {
        reuse = true;
        for (unsigned int i = 0; i < layers->count; i++) {
            choreo2::Driver *d = layers->FUN_00222e20(i);
            if (d->id.lo != lo || d->id.hi != hi)
                continue;
            choreo2::AnimationDriver *ad = dynamic_cast<choreo2::AnimationDriver *>(d);
            if (ad != 0 && ad->anim == anim) {
                u.v = ad->f23c;
                found = true;
                break;
            }
        }
    } else {
        reuse = false;
    }

    bool created;
    choreo2::AnimationDriver *nd = (choreo2::AnimationDriver *)thunk_FUN_0008d690((int)sizeof(choreo2::AnimationDriver));
    if (nd != 0)
        nd = nd->FUN_00225950(rig, anim);
    if (nd != 0)
        nd->AddRef();
    if (driver != 0)
        driver->Release();
    driver = nd;
    if (found && !(u.v < 0.0f)) {
        nd->FUN_00225cf0(u.v);
        created = false;
    } else {
        created = true;
    }
    driver->id.FUN_0027af70(&anim->id);

    if ((data->key2Lo | data->key2Hi) != 0) {
        int r = rig->FUN_0027b670(data->key2Lo, data->key2Hi);
        if (r != 0)
            driver->FUN_002224a0(r);
    }

    hulk_freg f44 = data->f44;
    hulk_freg f48 = data->f48;
    hulk_freg f40 = data->f40;
    driver->b224 = reuse;
    driver->b225 = data->mode == 3;

    V3_13d410 dir;
    hulk_freg f28 = data->f28;
    hulk_freg f2c = data->f2c;
    dir.x = data->f20;
    dir.y = f28;
    dir.z = f2c;
    float arg1 = data->GetValue();
    driver->FUN_00225e00(arg1, dir);
    if (!data->b34) {
        driver->b235 = 0;
        driver->b234 = data->b34;
    }
    float arg2 = driver->FUN_00225b30();
    layers->FUN_00222890(driver, arg2, f40, 1.0f, f44, f48, -1.0f);

    f24 = data->f24;
    if (f24 < 0.0f) {
        if (driver->b224) {
            hulk_freg lo2 = driver->f22c;
            hulk_freg span = driver->f230 - lo2;
            hulk_freg v = FUN_000964e0() * span + lo2;
            driver->FUN_00225cf0(v);
        } else {
            driver->FUN_00225cf0(driver->f230);
        }
    } else if (created) {
        float arg3 = FUN_00225be0(f24, driver->f22c, driver->f230, 0);
        driver->FUN_00225cf0(arg3);
    }
    return true;
}
} // namespace fn_0013d410
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0013d780 FUN_0013d780 (38 B): matches/0x0013d780.cpp [wrapped: conflict: Find]
// sym: _FUN_0013d780
namespace fn_0013d780 {
class TrackFactoryCasterTemplate_13d780 {
  public:
    virtual bool Cast_0013bd60(void*);
};
class Target {
  public:
    void Set_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_13d780*);
extern "C" void __cdecl FUN_0013d780(Target* t, const char* name) {
    TrackFactoryCasterTemplate_13d780 caster;
    void* p = Find_00236ac0(name, &caster);
    t->Set_002367c0(p);
}
} // namespace fn_0013d780


// 0x0013de80 hulkfight::motion::AnimationChargeAction::vfunc_3 (488 B): equivalent/0x0013de80.cpp [wrapped: conflict: AnimationChargeAction; FUN_000592a0; World; content::LoadInventory::DynamicCaster (+1)]
// sym: ?vfunc_3@AnimationChargeAction@fn_0013de80@@UAEDHH@Z @b52170e99310 @w83f935dfe99c
namespace fn_0013de80 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 16/16)
// hulkfight::motion::AnimationChargeAction::vfunc_3 @ 0x0013de80
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

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class Animation; }


extern void *__cdecl FUN_00263ea0(unsigned int size);

struct Name_13de80 {
    unsigned int lo, hi;
    void FUN_0027af70(const Name_13de80 *other);
};

struct Handle_13de80 {
    char pad0[8];
    Name_13de80 name;
};

class Factory_13de80 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Handle_13de80 *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, int a, int b);
};

struct Holder44_13de80 { Factory_13de80 *FUN_00203d70(); };
struct Holder28_13de80 { Holder44_13de80 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_13de80 *holder; };

struct Sub_13de80 {
    void *FUN_0027b670(int lo, int hi);
};

class AnimationDriver_13de80 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[4];
    Name_13de80 name;
    char pad10[0x224 - 0x10];
    char flag224;
    char flag225;
    char pad226[2];
    int i228;
    float f22c;
    float f230;
    AnimationDriver_13de80 *FUN_00225950(Sub_13de80 *skel, Handle_13de80 *h);
    void FUN_00225e00(float a, int b, int c, int d);
    void FUN_00225cf0(float t);
    void FUN_002224a0(void *p);
    float FUN_00225b30();
};

struct Body_13de80 {
    Sub_13de80 *FUN_002226b0();
    void FUN_00222890(AnimationDriver_13de80 *a, float t, int c30, float one, int c34, int c38, float m1);
};

struct Fighter_13de80 { char pad[4]; };
Fighter_13de80 *__fastcall FUN_000592a0(void *owner);

struct Stats_13de80 {
    char pad0[0x1e58];
    float time;
};
Stats_13de80 *__fastcall FUN_00059a30(Fighter_13de80 *f);
Body_13de80 *__fastcall FUN_00059a40(Fighter_13de80 *f);

extern "C" float __cdecl FUN_000186b0(float *value, float *lo, float *hi);

struct Config_13de80 {
    char pad0[0x18];
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
};

class AnimationChargeAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char vfunc_3(int a, int b);
    char pad04[0x18];
    Config_13de80 *cfg;
    void *owner;
    AnimationDriver_13de80 *anim;
};

struct Frame_13de80 {
    char slot0[4];
    Sub_13de80 *skel;
    union {
        Stats_13de80 *stats;
        float time;
    } u;
    float one;
    float zero;
};

char AnimationChargeAction::vfunc_3(int a, int b)
{
    Frame_13de80 fr;
    if (!owner)
        return 0;
    Fighter_13de80 *fighter = FUN_000592a0(owner);
    fr.u.stats = FUN_00059a30(fighter);
    Body_13de80 *body = FUN_00059a40(fighter);
    if (!body)
        return 0;
    fr.skel = body->FUN_002226b0();
    int c18 = cfg->f18;
    int c1c = cfg->f1c;
    Factory_13de80 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
        new (fr.slot0) content::LoadInventory::DynamicCaster<pure3d::Animation>;
    Handle_13de80 *handle = factory->f3(caster, c18, c1c);
    if (!handle)
        return 0;
    AnimationDriver_13de80 *created;
    void *mem = FUN_00263ea0(0x240);
    if (mem)
        created = ((AnimationDriver_13de80 *)mem)->FUN_00225950(fr.skel, handle);
    else
        created = 0;
    if (created)
        created->AddRef();
    if (anim)
        anim->Release();
    anim = created;
    created->name.FUN_0027af70(&handle->name);
    anim->flag224 = 0;
    anim->flag225 = 1;
    anim->FUN_00225e00(-1.0f, 0, cfg->f20, cfg->f24);
    anim->i228 = 0;
    AnimationDriver_13de80 *a2 = anim;
    float *lo = (float *)fr.slot0;
    *lo = a2->f22c;
    fr.u.time = fr.u.stats->time;
    fr.one = 1.0f;
    fr.zero = 0.0f;
    float r = FUN_000186b0(&fr.u.time, &fr.zero, &fr.one);
    a2->FUN_00225cf0((a2->f230 - *lo) * r + *lo);
    int c28 = cfg->f28;
    int c2c = cfg->f2c;
    if ((c28 | c2c) != 0) {
        void *p = fr.skel->FUN_0027b670(c28, c2c);
        if (p)
            anim->FUN_002224a0(p);
    }
    Config_13de80 *c = cfg;
    int c30 = c->f30;
    int c34 = c->f34;
    int c38 = c->f38;
    body->FUN_00222890(anim, anim->FUN_00225b30(), c30, 1.0f, c34, c38, -1.0f);
    return 1;
}
} // namespace fn_0013de80
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0013e070 hulkfight::motion::AnimationLinkedAction::vfunc_3 (699 B): equivalent/0x0013e070.cpp [wrapped: conflict: Animation; FUN_00059a40; World; choreo2::Driver (+2)]
// sym: ?vfunc_3@AnimationLinkedAction@fn_0013e070@@UAE_NHH@Z @42864d7bfd25 @w99c2b3b54875
namespace fn_0013e070 {
// STATUS: equivalent (tools/equiv.py level 3: 3290 inputs, branch coverage 37/40, incomplete; Wine build 745 inputs, 37/40)
// hulkfight::motion::AnimationLinkedAction::vfunc_3 @ 0x0013e070
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



namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class Animation; }

struct V3_13e070 {
    float x, y, z;
};

struct Id64_13e070 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(Id64_13e070 *src);
};

struct Animation {
    char pad0[8];
    Id64_13e070 id;
};

namespace choreo2 {
class Driver {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_13e070 id;            // 8
};
}

namespace choreo2 {
class AnimationDriver : public choreo2::Driver {
public:
    char pad10[0x10];
    Animation *anim;    // 0x20
    char pad24[0x218];
    float value;        // 0x23c
    choreo2::AnimationDriver *FUN_00225950(void *rig, Animation *anim);
    void FUN_002224a0(int v);
    void FUN_00225e00(float t, V3_13e070 v);
    void FUN_00225cf0(float v);
    float FUN_00225b30();
};
}

struct Rig_13e070 {
    char pad0[0x34];
    int vec34;
    int vec38;
    int FUN_0027b670(unsigned int lo, unsigned int hi);
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *obj);

struct LayerSet_13e070 {
    char pad0[0x64];
    Rig_13e070 **rigRef;
    unsigned int count;
    Rig_13e070 *FUN_002226b0();
    choreo2::Driver *FUN_00222e20(unsigned int index);
    int FUN_00222bf0(choreo2::Driver *d);
    void FUN_00222890(choreo2::AnimationDriver *d, float r, float a, float b, float c, float e, float f);
};
LayerSet_13e070 *__fastcall FUN_00059a40(Context *ctx);

class Factory_13e070 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo,
                          unsigned int hi);
};

struct Holder44_13e070 { Factory_13e070 *FUN_00203d70(); };
struct Holder28_13e070 { Holder44_13e070 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_13e070 *holder; };

class AnimData_13e070 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float GetValue();
    char pad4[0x14];
    unsigned int idLo;      // 0x18
    unsigned int idHi;      // 0x1c
    V3_13e070 posA;                // 0x20
    char pad2c[4];
    unsigned int id2Lo;     // 0x30
    unsigned int id2Hi;     // 0x34
    V3_13e070 posB;                // 0x38
};

void *__cdecl thunk_FUN_0008d690(unsigned int size);

class AnimationLinkedAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    AnimData_13e070 *data;                 // 0x1c
    void *owner;                    // 0x20
    choreo2::AnimationDriver *driver; // 0x24
};

bool AnimationLinkedAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;
    LayerSet_13e070 *layers = FUN_00059a40(FUN_000592a0(owner));
    if (layers == 0)
        return false;
    struct Frame {
        content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
        Rig_13e070 *rig;
        unsigned int lo;
        unsigned int hi;
    } fr;
    fr.rig = layers->FUN_002226b0();
    fr.lo = data->idLo;
    fr.hi = data->idHi;
    Factory_13e070 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    Animation *anim = factory->f3(&fr.caster, fr.lo, fr.hi);
    Rig_13e070 *rig = fr.rig;
    unsigned int lo = fr.lo;
    unsigned int hi = fr.hi;
    if (anim == 0)
        return false;
    float best = -1.0f;
    int bestKey = 0x7fffffff;
    for (unsigned int i = 0; i < layers->count; i++) {
        choreo2::Driver *d = layers->FUN_00222e20(i);
        if (d->id.lo != lo || d->id.hi != hi)
            continue;
        int key = layers->FUN_00222bf0(d);
        if (key > bestKey)
            continue;
        choreo2::AnimationDriver *ad = dynamic_cast<choreo2::AnimationDriver *>(d);
        if (ad == 0 || ad->anim != anim)
            continue;
        float v = ad->value;
        if (key < bestKey || v > best) {
            best = v;
            bestKey = key;
        }
    }
    choreo2::AnimationDriver *nd = (choreo2::AnimationDriver *)thunk_FUN_0008d690((int)sizeof(choreo2::AnimationDriver));
    if (nd != 0)
        nd = nd->FUN_00225950(rig, anim);
    if (nd != 0)
        nd->AddRef();
    if (driver != 0)
        driver->Release();
    driver = nd;
    nd->id.FUN_0027af70(&anim->id);
    if ((data->id2Lo | data->id2Hi) != 0) {
        int r = rig->FUN_0027b670(data->id2Lo, data->id2Hi);
        if (r != 0)
            driver->FUN_002224a0(r);
    }
    AnimData_13e070 *dd = data;
    V3_13e070 pa = dd->posA;
    V3_13e070 pb = dd->posB;
    float value = dd->GetValue();
    driver->FUN_00225e00(value, pa);
    driver->FUN_00225cf0(data->posA.y);
    float lim = data->posA.z;
    if (best > 0.0f && best < lim) {
        float t = driver->FUN_00225b30();
        if (t > 0.0f) {
            V3_13e070 vv;
            vv.x = 1.0f;
            vv.y = best;
            vv.z = lim;
            driver->FUN_00225e00(t, vv);
            driver->FUN_00225cf0(best);
        }
    }
    layers->FUN_00222890(driver, driver->FUN_00225b30(), pb.x, 1.0f, pb.y, pb.z, -1.0f);
    return true;
}
} // namespace fn_0013e070
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0013e330 fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameReachedCondition>::vfunc_1 (60 B): matches/0x0013e330.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VFrameReachedCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameReachedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_13e330));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_13e330* t = new (mem) TrackFactoryTemplate_13e330();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0013e370 fight::ConditionFactoryTemplate<hulkfight::motion::FrameReachedCondition>::vfunc_5 (55 B): matches/0x0013e370.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VFrameReachedCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::FrameReachedCondition>::vfunc_5() {
    FrameReachedCondition_13e370* p = (FrameReachedCondition_13e370*)alloc_0008d690(0x20);
    if (p) {
        ((Init_13e370*)p)->Fnf_00234590(0);
        p->vptr = (hulk_uintptr)&frame_vtable;
        ((Sub_13e370*)((char*)p + 0x10))->Fnf_0027af00();
        *(u32_13e370*)((char*)p + 0x18) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f30d2d27 {

// 0x0013e3b0 fight::ConditionFactoryTemplate<hulkfight::motion::FrameReachedCondition>::vfunc_2 (43 B): matches/0x0013e3b0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_13e3b0@fn_f30d2d27@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_13e3b0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004129a4;
    base1_dtor_0013a000();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f30d2d27

// 0x0013e3e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameCondition>::vfunc_1 (60 B): matches/0x0013e3e0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VFrameCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_13e3e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_13e3e0* t = new (mem) TrackFactoryTemplate_13e3e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f30d2d27 {

// 0x0013e420 fight::ConditionFactoryTemplate<hulkfight::motion::FrameCondition>::vfunc_5 (62 B): matches/0x0013e420.cpp
// sym: ?target@fn_f30d2d27@@YAPAVFrameCondition@1@XZ
FrameCondition* target(void) {
    FrameCondition* p = (FrameCondition*)operator_new(0x20);
    if (p) {
        p->initialize_00234590(0);
        *(void**)p = (void*)((hulk_intptr)DAT_00412430);
        ((FrameCondition*)((char*)&p->idLo))->initializeExtra_0027af00();
        p->a = 0;
        p->b = 0;
        return p;
    }
    return (FrameCondition*)0;
}


// 0x0013e460 fight::ConditionFactoryTemplate<hulkfight::motion::FrameCondition>::vfunc_2 (43 B): matches/0x0013e460.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_13e460@fn_f30d2d27@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_13e460::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004129c0;
    base1_dtor_0013a080();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f30d2d27

// 0x0013e490 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationTrack>::vfunc_1 (60 B): matches/0x0013e490.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VAnimationTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_13e490));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_13e490* t = new (mem) TrackFactoryTemplate_13e490();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f30d2d27 {

// 0x0013e4f0 fight::TrackFactoryTemplate<hulkfight::motion::AnimationTrack>::vfunc_2 (43 B): matches/0x0013e4f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f30d2d27@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004129dc;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f30d2d27

// 0x0013e520 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationChargeTrack>::vfunc_1 (60 B): matches/0x0013e520.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VAnimationChargeTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationChargeTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_13e520));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_13e520* t = new (mem) TrackFactoryTemplate_13e520();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0013e560 fight::TrackFactoryTemplate<hulkfight::motion::AnimationChargeTrack>::vfunc_5 (24 B): matches/0x0013e560.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VAnimationChargeTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fa30 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AnimationChargeTrack>::vfunc_5() {
    Grapple_13e560* p = (Grapple_13e560*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack_0013a210());
    return (void*)(0);
}


// 0x0013e580 fight::TrackFactoryTemplate<hulkfight::motion::AnimationChargeTrack>::vfunc_2 (43 B): matches/0x0013e580.cpp [wrapped: same definition as 0x0013e4f0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0013e580@@QAEPAXE@Z
namespace fn_0013e580 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_004129f8;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0013a1e0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004129f8;
    base1_dtor_0013a1e0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0013e580


// 0x0013e5b0 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationLinkedTrack>::vfunc_1 (60 B): matches/0x0013e5b0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VAnimationLinkedTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationLinkedTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_13e5b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_13e5b0* t = new (mem) TrackFactoryTemplate_13e5b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0013e5f0 fight::TrackFactoryTemplate<hulkfight::motion::AnimationLinkedTrack>::vfunc_5 (24 B): matches/0x0013e5f0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VAnimationLinkedTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00070420 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AnimationLinkedTrack>::vfunc_5() {
    void* p = Allocate_0008d690(0x48);
    if (p)
        return (void*)(((Track_13e5f0*)p)->Init_0013a2e0());
    return (void*)(0);
}


// 0x0013e610 fight::TrackFactoryTemplate<hulkfight::motion::AnimationLinkedTrack>::vfunc_2 (43 B): matches/0x0013e610.cpp [wrapped: same definition as 0x0013e4f0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0013e610@@QAEPAXE@Z
namespace fn_0013e610 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412a14;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0013a2b0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412a14;
    base1_dtor_0013a2b0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0013e610


// 0x0013e640 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_1 (60 B): matches/0x0013e640.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VAnimationPhaseMatchedTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_13e640));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_13e640* t = new (mem) TrackFactoryTemplate_13e640();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0013e680 fight::TrackFactoryTemplate<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_5 (24 B): matches/0x0013e680.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VAnimationPhaseMatchedTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00070420 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_5() {
    void* p = Allocate_0008d690(0x48);
    if (p)
        return (void*)(((Track_13e680*)p)->Init_0013a3c0());
    return (void*)(0);
}


// 0x0013e6a0 fight::TrackFactoryTemplate<hulkfight::motion::AnimationPhaseMatchedTrack>::vfunc_2 (43 B): matches/0x0013e6a0.cpp [wrapped: same definition as 0x0013e4f0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0013e6a0@@QAEPAXE@Z
namespace fn_0013e6a0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412a30;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0013a390();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412a30;
    base1_dtor_0013a390();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0013e6a0


// 0x0013e6d0 fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_1 (60 B): matches/0x0013e6d0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VAnimationVelocityScaledTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_13e6d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_13e6d0* t = new (mem) TrackFactoryTemplate_13e6d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0013e730 fight::TrackFactoryTemplate<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_2 (43 B): matches/0x0013e730.cpp [wrapped: same definition as 0x0013e4f0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0013e730@@QAEPAXE@Z
namespace fn_0013e730 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412a4c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0013a470();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412a4c;
    base1_dtor_0013a470();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0013e730


// 0x0013e760 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleAnimationTrack>::vfunc_1 (60 B): matches/0x0013e760.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VGrappleAnimationTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleAnimationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_13e760));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_13e760* t = new (mem) TrackFactoryTemplate_13e760();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0013e7a0 fight::TrackFactoryTemplate<hulkfight::motion::GrappleAnimationTrack>::vfunc_5 (38 B): matches/0x0013e7a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VGrappleAnimationTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fb80 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleAnimationTrack>::vfunc_5() {
    CHitAnimationTrack_13e7a0* p = (CHitAnimationTrack_13e7a0*)alloc_0008d690(0x50);
    if (p) {
        p->init_0013a130();
        p->vf = (unsigned int*)((int*)DAT_00412540);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0013e7d0 fight::TrackFactoryTemplate<hulkfight::motion::GrappleAnimationTrack>::vfunc_2 (43 B): matches/0x0013e7d0.cpp [wrapped: same definition as 0x0013e4f0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0013e7d0@@QAEPAXE@Z
namespace fn_0013e7d0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412a68;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0013a100();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412a68;
    base1_dtor_0013a100();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0013e7d0

