// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00146900..0x0014c470 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleThrowAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1739f6f {
#define TREE_TU_END }
namespace fn_f1739f6f {} using namespace fn_f1739f6f;
namespace fn_f1739f6f { extern "C" char DAT_00413708[], DAT_004137d0[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
namespace fn_f1739f6f { extern "C" char DAT_00413768[], DAT_00413798[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f1739f6f {
class Obj_146990 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int value);
};
struct Vec3_1469c0 {
    int x;
    int y;
    int z;
};
class Obj_1469c0 {
  public:
    char m[0x10];
    Vec3_1469c0 mVec;
    char Set(const Vec3_1469c0* src);
};
struct Angles {
    char pad[0x1c];
    float x, y, z;
    unsigned int FUN_00146a00(const float *input);
};
struct Src_146a70 {
    int a, b, c;
};
class Owner_146a70 {
  public:
    char pad[0x10];
    int m10, m14, m18;
    char Set(Src_146a70* p);
};
const float kScale_146b80 = 0.0174532924f;
struct Vec3_146cb0 {
    int x;
    int y;
    int z;
};
class Obj_146cb0 {
  public:
    char pad[0x10];
    int a;
    int b;
    int c;
    char Set(Vec3_146cb0* v);
};
extern const float k_146dc0 = 0.0174532925f;
extern int* hulk_at_004e0fbc;
class CCondition_147180 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_00413578[];
struct Sub_1471c0 {
    void Fin_0027af50();
};
class Condition_1471c0 {
  public:
    void* vptr;
    void Fin_002345b0();
};
class GrappleAttachJointCondition_1471c0 : public Condition_1471c0 {
  public:
    char pad[0xc];
    Sub_1471c0 sub;
    void f();
};
extern int* hulk_at_004e0fc4;
class CCondition_147200 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0fcc;
class CCondition_147260 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0fd4;
class CCondition_1472c0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0fdc;
class CCondition_147320 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0fe4;
class CCondition_147390 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0fec;
class CCondition_147420 {
  public:
    virtual int vfunc_0(int);
};
extern float hulk_at_003f3388;
extern int* hulk_at_004e0ff4;
class CCondition_1474e0 {
  public:
    virtual int vfunc_0(int);
};
class Track_1474f0 {
  public:
    Track_1474f0();
    virtual void f();
    char pad[4];
};
class GrappleStruggleTrack : public Track_1474f0 {
  public:
    GrappleStruggleTrack();
    virtual void f();
    int a;
    int b;
    float c;
    int d, e, g, h;
};
struct Param_147540 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_147540 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0ffc;
class CCondition_147580 {
  public:
    virtual int vfunc_0(int);
};
class Root {
  public:
    virtual void fn();
    Root();
    char pad[8];
};
class Track_147590 : public Root {
  public:
    Track_147590() { a = 0; }
    int a;
};
class CivilianThrowTrack : public Track_147590 {
  public:
    virtual void fn();
    CivilianThrowTrack();
    int b, c;
    float d, e, f, g, h, i;
    int j, k, l;
    float m;
};
extern int* hulk_at_004e1004;
class CCondition_147640 {
  public:
    virtual int vfunc_0(int);
};
class Track_147650 {
  public:
    void* vptr;
    int m4;
    int m8;
    Track_147650();
};
class CivilianAttachTrack_147650 : public Track_147650 {
  public:
    int mc;
    CivilianAttachTrack_147650();
};
extern int* hulk_at_004e100c;
class CCondition_1476c0 {
  public:
    virtual int vfunc_0(int);
};
class Track_1476d0 {
  public:
    virtual void f();
    Track_1476d0();
    char pad[4];
    int mode;
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class GrappleHitReactionTrack : public Track_1476d0 {
  public:
    virtual void f();
    GrappleHitReactionTrack();
    int a, b, c, d;
    int gap;
    Sub sub;
    int e, f1, g;
    unsigned char flag;
    char pad2[3];
    int h, i, j, k, l, m, o;
};
extern void* hulk_at_00413708[];
struct Sub_147750 {
    void Fin_0027af50() throw();
};
class Track_147750 {
  public:
    void* vptr;
    ~Track_147750() throw();
};
class GrappleHitReactionTrack_147750 : public Track_147750 {
  public:
    char pad[0x20 - 4];
    Sub_147750 sub;
    ~GrappleHitReactionTrack_147750() throw();
};
extern int* hulk_at_004e1014;
class CCondition_147790 {
  public:
    virtual int vfunc_0(int);
};
class Track_1477a0 {
  public:
    Track_1477a0();
    virtual hulk_intptr Fnf_00147790(int);
    char pad[8];
};
struct Param_1477f0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1477f0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" char DAT_00413738[];
struct PartA_147800 {
    void Init_00236fd0();
};
struct PartB_147800 {
    void Init_00234150();
};
struct End_147800 {
    void Finish_00236d60();
};
extern int* hulk_at_004e101c;
class CCondition_147850 {
  public:
    virtual int vfunc_0(int);
};
struct Param_1478c0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1478c0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Tail_1478d0 {
    void Init_0027af50();
};
struct CivilianAnimationTrack_1478d0 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_00413768;
extern char hulk_at_00494b60;
extern char hulk_at_00494b44;
class Helper_1479f0 {
  public:
    void* getB_00059a30();
};
struct P_147a50 {
    P_147a50* FnB_00059a30();
};
extern char kDesc1;
extern char kDesc2;
struct CivilianAttachedCondition {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(void* a, void* b, void* c);
    char pad[8];
    u8 flag;
};
struct P_147ab0 {
    P_147ab0* FnB_00059a30();
};
struct CivilianTargetCondition_147ab0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(void* a, void* b, void* c);
    char pad[8];
    u8 flag;
};
struct Result_147b80 {
    char pad[0x1e58];
    float value;
    int flag;
};
struct HelperA_147b80 {
};
struct HelperB_147b80 {
    Result_147b80* Fng_00059a30();
};
class Action_147b80 {
  public:
    char pad[0x20];
};
struct Source_147bb0 {
    char pad[0x334];
    Source_147bb0* a334;
    Source_147bb0* b338;
    char pad2[0x1e58 - 0x33c];
    float value;
    int valueSet;
    char pad3[0x1f58 - 0x1e60];
    int flagA;
    char pad4[0x1f7c - 0x1f5c];
    int flagB;
    char pad5[0x20a8 - 0x1f80];
    int limitIndex;
};
struct Node { Source_147bb0* FUN_00059a30(); };
struct Owner_147bb0 {  };
class Config_147bb0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float v6();
    char pad[0x14 - 4];
    float f14;
    float f18;
    float f1c;
    float f20;
};
class GrappleStruggleAction {
public:
    bool run(int mode, float dt);
    char p0[0x1c];
    Config_147bb0* cfg;
    Owner_147bb0* owner;
    float elapsed;
};
struct B_147cf0 {
    B_147cf0* second_00059a30();
};
class Base_147d20 {
  public:
    void run_00232240();
};
class AnimThing {
  public:
    void FnA_002322f0(int, int);
    void FnB_00231f20(int);
    void FnC_002324b0(int);
    int FnD_00231ee0();
};
class Base_147da0 {
  public:
    void run_00232240();
};
struct Name {
    int lo;
    int hi;
    Name(const Name &o) throw();
    ~Name() throw();
};
struct Msg_147db0 {
    char data[0x20];
    Msg_147db0 *FUN_001c9b30(Name key);
};
struct Dispatcher_147db0 {
    void FUN_001cbc20(Msg_147db0 *m);
};
} // namespace fn_f1739f6f
struct World {
    char pad0[0x30];
    Dispatcher_147db0 *dispatcher;
};
namespace fn_f1739f6f {
struct Target_147db0 {
    char pad0[8];
    Name name;
    char pad10[0x100 - 0x10];
    int f100;
};
struct Fighter_147db0 {
    char pad0[0x328];
    int f328;
    char pad32c[0x630 - 0x32c];
    Target_147db0 *target;
    char pad634[0x20a8 - 0x634];
    int f20a8;
    void FUN_0003b190(int v);
    void FUN_0003b160(Target_147db0 *t);
    void FUN_000393c0();
};
struct Holder_147db0 {
    Fighter_147db0 *FUN_00059a30();
};
struct Params_147db0 {
};
union FlagWord {
    unsigned char b;
    unsigned int w;
};
struct Params_147f90 {
    int f2c;
    FlagWord flag;
    int f24;
};
struct Source_147f90 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float v6();
    char pad04[0xc];
    float f10;
    char pad14[4];
    int f18;
    int f1c;
    int f20;
    int f24;
    char b28;
    char pad29[3];
    int f2c;
};
struct Target_147f90 {
    void FUN_000819f0(int a, int b, int c, float d, int e, unsigned int f, int g);
};
struct Player_147f90 {
};
struct Anchor_147f90 {
    Player_147f90 *FUN_00059a30();
};
struct Owner_147f90 {
};
extern char threat_vftable_148110;
struct Obj_148110 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_148110*);
class GrappleAttachJointCondition_148110 {
  public:
    void* vftable;
    char pad[0x0c];
    GrappleAttachJointCondition_148110* vfunc_5(unsigned char);
};
extern void* hulk_at_00413598[];
class Condition_148140 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class GrappleAttachedCondition_148140 : public Condition_148140 {
  public:
    GrappleAttachedCondition_148140* vfunc_5(signed char flags);
};
extern void* hulk_at_004135b8[];
class Condition_148170 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CivilianAttachedCondition_148170 : public Condition_148170 {
  public:
    CivilianAttachedCondition_148170* vfunc_5(signed char flags);
};
extern void* hulk_at_004135d8[];
class Condition_1481a0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CivilianTargetCondition_1481a0 : public Condition_1481a0 {
  public:
    CivilianTargetCondition_1481a0* vfunc_5(signed char flags);
};
extern void* hulk_at_004135f8[];
class Condition_1481d0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class GrappleOrientationCondition_1481d0 : public Condition_1481d0 {
  public:
    GrappleOrientationCondition_1481d0* vfunc_5(signed char flags);
};
extern void* hulk_at_00413618[];
class Track_148200 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class CivilianDetachTrack_148200 : public Track_148200 {
  public:
    CivilianDetachTrack_148200* vfunc_5(signed char flags);
};
extern void* hulk_at_00413648[];
class Track_148230 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class GrappleThrowTrack_148230 : public Track_148230 {
  public:
    GrappleThrowTrack_148230* vfunc_5(signed char flags);
};
extern void* hulk_at_00413678[];
class Track_148260 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class GrappleStruggleTrack_148260 : public Track_148260 {
  public:
    GrappleStruggleTrack_148260* vfunc_5(signed char flags);
};
extern void* hulk_at_004136a8[];
class Track_148290 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class CivilianThrowTrack_148290 : public Track_148290 {
  public:
    CivilianThrowTrack_148290* vfunc_5(signed char flags);
};
extern void* hulk_at_004136d8[];
class Track_1482c0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class CivilianAttachTrack_1482c0 : public Track_1482c0 {
  public:
    CivilianAttachTrack_1482c0* vfunc_5(signed char flags);
};
extern void* g_vftable_1482f0[];
class Mem_1482f0 {
  public:
    ~Mem_1482f0();
};
class Track_1482f0 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class GrappleHitReactionTrack_1482f0 : public Track_1482f0 {
  public:
    char pad[28];
    Mem_1482f0 m;
    GrappleHitReactionTrack_1482f0* f2(unsigned char flags);
};
typedef unsigned char u8_148320;
class GrappleExecuteTrack : public Track_1477a0 {
  public:
    virtual bool m_vf1_00234270(void*);
    virtual bool m_vf2_002342b0(int);
    virtual bool m_vf3_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool m_vf4_00234350(int, int);
    virtual GrappleExecuteTrack* vfunc_5(u8_148320);
    virtual void m_vf6_001477e0();
    virtual void m_vf7_001477f0();
    virtual int m_vf8_00147b10(int, int);
    virtual int m_vf9_00236bb0(hulk_intptr, hulk_intptr, hulk_intptr);
    virtual int m_vf10_00147b20(int, int, int);
    GrappleExecuteTrack();
    int a;
    float b;
    PartA p;
    int c;
    PartB q;
    char _m_pad_25[0xb];
};
struct Sub_148320 {
    char pad[0x24];
};
void __fastcall initA_00236fd0(Sub_148320*);
extern "C" void __fastcall FUN_00234150(void*);
void __fastcall initC_00236d60(GrappleExecuteTrack*);
void __cdecl destroyThing_0008d330(GrappleExecuteTrack*);
struct Sub_148360 {
    void* v;
    void Fin_0027af50();
};
class Track_148360 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class CivilianAnimationTrack_148360 : public Track_148360 {
  public:
    char pad[0x18 - 4];
    Sub_148360 sub;
    CivilianAnimationTrack_148360* f5(unsigned char flags);
};
struct Ref_1484f0 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_1484f0 {
    Action_1484f0() throw();
    virtual void V0();
    char pad04[0x18];
};
struct GrappleStruggleAction_1484f0 : Action_1484f0 {
    int m1c;
    Ref_1484f0* m20;
    int m24;
    GrappleStruggleAction_1484f0(int a, Ref_1484f0* r);
    virtual void V0();
};
class Ref_148540 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_148540 {
  public:
    void* vptr;
};
class GrappleStruggleAction_148540 : public Action_148540 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_148540* m20;
    ~GrappleStruggleAction_148540() throw();
};
struct Vec3_148580 { float x, y, z; };
class RefCounted_148580 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Stats_148580 {
    char pad0[0x12c];
    RefCounted_148580 *ref;
    char pad130[0x334 - 0x130];
    Stats_148580 *altTarget;
    Stats_148580 *target;
    char pad33c[0x1e58 - 0x33c];
    float blend;
    hulk_freg FUN_000354c0();
};
struct Params {
    char pad0[0x10];
    int f10;
    int f14;
    float f18;
    char pad1c[4];
    int f20;
    int f24;
    float f28;
    float f2c;
    int f30;
    unsigned char f34;
    char pad35[3];
    union {
        float f38;
        int f38i;
    };
    int f3c;
    float f40;
    int f44;
    float f48;
    int f4c;
    int f50;
};
struct Effect_148580 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    char pad14[4];
    Vec3_148580 dir;
    unsigned char f24;
    char pad25[0x4c - 0x25];
    RefCounted_148580 *ref4c;
    RefCounted_148580 *ref50;
    int f54;
    int f58;
    char pad5c[0x68 - 0x5c];
    int f68;
    char pad6c[0x74 - 0x6c];
    int f74;
    float f78;
    void FUN_000595f0(Vec3_148580 *dir, int a, float b, int c);
};
void *__fastcall FUN_000592a0(void *owner);
Stats_148580 *__fastcall FUN_00059a30(void *x);
extern "C" void FUN_00224d70(float v, Vec3_148580 *dir);
class Ref_148840 {
  public:
    virtual void F();
    virtual void G();
};
class Action_148840 {
  public:
    virtual void FnV_00018b30();
    Action_148840();
};
class Sub_148840 {
  public:
    Sub_148840();
    char pad[0x28];
};
class GrappleHitReactionAction_148840 : public Action_148840 {
  public:
    char pad[0x18];
    int* mA;
    Ref_148840* mB;
    Sub_148840 sub;
    int x;
    int y;
    unsigned char z;
    GrappleHitReactionAction_148840(int* a, Ref_148840* b);
};
extern void* hulk_at_004137b4[];
class Ref_1488a0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub_1488a0 {
  public:
    void Fn_002325f0();
};
struct GrappleThrowAction_nv_1488a0 {
    void Fn_002326a0();
};
class GrappleHitReactionAction_1488a0 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_1488a0* m20;
    Sub_1488a0 m24;
    char p28[0x24];
    Ref_1488a0* m4c;
    void f();
};
class C3_1489d0 {
  public:
};
class C2_1489d0 {
  public:
    C3_1489d0* Get_00059a30();
};
class Motion_1489d0 {
  public:
    C2_1489d0* Get_000592a0();
};
class Action_1489d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int f(int, int);
};
class Obj_1489d0 {
  public:
    virtual void A();
    virtual void B();
};
class Sub_1489d0 {
  public:
    Obj_1489d0* cur;
    void Init_002322f0(int, int);
    void Set_00231f20(int);
    void Set2_002324b0(int);
    int Finish_00231ee0();
};
class GrappleHitReactionAction : public Action_1489d0 {
  public:
    char pad4[0x1c];
    Motion_1489d0* motion;
    Sub_1489d0 sub;
    char pad28[0x24];
    Obj_1489d0* old;
    int count;
    char flag;
    virtual int f(int x, int y);
};
class Ref_148a60 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_148a60 {
  public:
    virtual void FnB_00018b30();
    char pad[0x18];
    Action_148a60();
};
class Sub_148a60 {
  public:
    char pad[0x28];
    Sub_148a60();
};
class GrappleThrowAction : public Action_148a60 {
  public:
    virtual void m_vf1_00018b40();
    virtual void* m_vf2_0014adb0(char);
    virtual char m_vf3_00148b00(int, int);
    virtual void m_vf4_00147da0();
    virtual int vfunc_5(int, int);
    GrappleThrowAction(int a, Ref_148a60* p);
    int mA;
    Ref_148a60* mObj;
    Sub_148a60 sub;
    union { int count; int mCount; };
    union { unsigned char flag; char mFlag; };
    char _m_pad_51[0x3];
};
extern void* hulk_at_004137d0[];
class Ref_148ac0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_148ac0 {
  public:
    void* vptr;
};
void Free(void*) throw();
struct Sub_148ac0 {
    char c;
};
void __fastcall SubFini(Sub_148ac0*) throw();
void __fastcall SubFini2(Sub_148ac0*) throw();
void __fastcall SubFini3_002325f0(Sub_148ac0*) throw();
class GrappleThrowAction_148ac0 : public Action_148ac0 {
  public:
    char p1c[24];
    void* m1c;
    Ref_148ac0* m20;
    Sub_148ac0 s24;
    ~GrappleThrowAction_148ac0() throw();
};
class RefObj_148eb0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_148eb0 {
  public:
    Action_148eb0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class CivilianThrowAction_148eb0 : public Action_148eb0 {
  public:
    int mTarget;
    RefObj_148eb0* mObj;
    CivilianThrowAction_148eb0(int target, RefObj_148eb0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_004137ec[];
class Ref_148f00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_148f00 {
  public:
    void* vptr;
};
class CivilianThrowAction_148f00 : public Action_148f00 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_148f00* m20;
    ~CivilianThrowAction_148f00();
};
class RefObj_1492a0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1492a0 {
  public:
    Action_1492a0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class CivilianAttachAction_1492a0 : public Action_1492a0 {
  public:
    int mTarget;
    RefObj_1492a0* mObj;
    CivilianAttachAction_1492a0(int target, RefObj_1492a0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00413808[];
class Ref_1492f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1492f0 {
  public:
    void* vptr;
};
class CivilianAttachAction_1492f0 : public Action_1492f0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1492f0* m20;
    ~CivilianAttachAction_1492f0();
};
class RefObj_149330 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_149330 {
  public:
    Action_149330();
    virtual void Update_00018b30();
    char pad[0x18];
};
class CivilianDetachAction_149330 : public Action_149330 {
  public:
    int mTarget;
    RefObj_149330* mObj;
    CivilianDetachAction_149330(int target, RefObj_149330* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00413824[];
class Ref_149380 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_149380 {
  public:
    void* vptr;
};
class CivilianDetachAction_149380 : public Action_149380 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_149380* m20;
    ~CivilianDetachAction_149380();
};
class RefObj_1493c0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1493c0 {
  public:
    Action_1493c0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class CivilianAnimationAction_1493c0 : public Action_1493c0 {
  public:
    int mTarget;
    RefObj_1493c0* mObj;
    CivilianAnimationAction_1493c0(int target, RefObj_1493c0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00413840[];
class Ref_149410 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_149410 {
  public:
    void* vptr;
};
class CivilianAnimationAction_149410 : public Action_149410 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_149410* m20;
    ~CivilianAnimationAction_149410();
};
struct CAxisArcCondition_149480;
class CStageCondition_149490 {};
class ParamValue_149490 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_149490 : public ParamValue_149490 {
  public:
    virtual void f();
};
class CStageCondition_149520;
class ParamValue_149520 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149520 : public ParamValue_149520 {
  public:
    int pad;
};
class CStageCondition_149570;
class ParamValue_149570 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149570 : public ParamValue_149570 {
  public:
    int pad;
};
class CStageCondition_1495c0;
class ParamValue_1495c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1495c0 : public ParamValue_1495c0 {
  public:
    int pad;
};
class CStageCondition_149610;
class ParamValue_149610 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149610 : public ParamValue_149610 {
  public:
    int pad;
};
class CStageCondition_149660;
class ParamValue_149660 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149660 : public ParamValue_149660 {
  public:
    int pad;
};
class CStageCondition_1496b0;
class ParamValue_1496b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1496b0 : public ParamValue_1496b0 {
  public:
    int pad;
};
class CStageCondition_149700;
class ParamValue_149700 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149700 : public ParamValue_149700 {
  public:
    int pad;
};
class CStageCondition_149750;
class ParamValue_149750 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149750 : public ParamValue_149750 {
  public:
    int pad;
};
class CStageCondition_1497a0;
class ParamValue_1497a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1497a0 : public ParamValue_1497a0 {
  public:
    int pad;
};
class CStageCondition_1497f0;
class ParamValue_1497f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1497f0 : public ParamValue_1497f0 {
  public:
    int pad;
};
class CStageCondition_149840;
class ParamValue_149840 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149840 : public ParamValue_149840 {
  public:
    int pad;
};
class CStageCondition_149890;
class ParamValue_149890 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149890 : public ParamValue_149890 {
  public:
    int pad;
};
class CStageCondition_1498e0;
class ParamValue_1498e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1498e0 : public ParamValue_1498e0 {
  public:
    int pad;
};
struct CAxisArcCondition_149920;
class CStageCondition_149930 {};
class ParamValue_149930 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_149930 : public ParamValue_149930 {
  public:
    virtual void f();
};
class CStageCondition_1499c0;
class ParamValue_1499c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1499c0 : public ParamValue_1499c0 {
  public:
    int pad;
};
class CStageCondition_149a10;
class ParamValue_149a10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149a10 : public ParamValue_149a10 {
  public:
    int pad;
};
class CStageCondition_149a60;
class ParamValue_149a60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149a60 : public ParamValue_149a60 {
  public:
    int pad;
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class CStageCondition_149ae0;
class ParamValue_149ae0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149ae0 : public ParamValue_149ae0 {
  public:
    int pad;
};
class CStageCondition_149b60;
class ParamValue_149b60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149b60 : public ParamValue_149b60 {
  public:
    int pad;
};
class CStageCondition_149bb0;
class ParamValue_149bb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149bb0 : public ParamValue_149bb0 {
  public:
    int pad;
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004aefb8;
} // namespace fn_f1739f6f
namespace fight {
class ConditionFactoryCaster_149bd0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class GrappleAttachJointCondition_149bd0 {};
} }
namespace fn_f1739f6f {
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_00491ca8;
} // namespace fn_f1739f6f
namespace fight {
class ConditionFactoryCaster_149c90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CivilianAttachedCondition_149c90 {};
} }
namespace fn_f1739f6f {
extern char DAT_004af148;
} // namespace fn_f1739f6f
namespace fight {
class ConditionFactoryCaster_149d50 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f1739f6f {
extern "C" int __cdecl Find(void*, int, void*, void*, int);
extern int a, hulk_at_004af2d8;
extern char DAT_0049850c;
extern char DAT_004af448;
} // namespace fn_f1739f6f
namespace fight {
class TrackFactoryCaster_149e30 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class GrappleThrowTrack_149e30 {};
} }
namespace fn_f1739f6f {
extern char DAT_004af5b0;
} // namespace fn_f1739f6f
namespace fight {
class TrackFactoryCaster_149f10 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CivilianThrowTrack_149f10 {};
} }
namespace fight {
class TrackFactoryCaster_149ff0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class GrappleHitReactionTrack_149ff0;
} }
namespace fn_f1739f6f {
extern char DAT_004af720;
extern char DAT_004af7d8;
} // namespace fn_f1739f6f
namespace fight {
class TrackFactoryCaster_14a0b0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class GrappleExecuteTrack_14a0b0;
} }
namespace fn_f1739f6f {
class Track_14a170 {};
} // namespace fn_f1739f6f
namespace fight {
class TrackFactoryCaster_14a170 {
  public:
    virtual bool vfunc_0(Track_14a170*);
    virtual void vfunc_1();
};
}
namespace fn_f1739f6f {
extern char DAT_004af890;
typedef unsigned int u32_14ac70;
extern int TypeA_14ac70;
extern int TypeB_14ac70;
struct Result_14ac70 {
    u32_14ac70 Init_001484f0(void*, void*);
};
extern Result_14ac70* Alloc_0008d690(int);
struct RefCounted_14acc0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00413798[];
class GrappleStruggleAction_14acc0 {
  public:
    GrappleStruggleAction_14acc0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_14acc0* m_20;
};
class Track_14ad10 {
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
    virtual int v10(int, int, int);
};
class Param_14ad10 {};
class GrappleHitReactionAction_14ad10 {
  public:
    int Init_00148840(hulkfight::motion::GrappleHitReactionTrack*, int);
};
extern int GetParam_0005a470(hulk_intptr);
extern GrappleHitReactionAction_14ad10* Allocate_0008d690(int);
extern void* g_vftable_14adb0[];
class Ref_14adb0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub_14adb0 {
  public:
    void Fn_002325f0();
};
struct GrappleThrowAction_nv_14adb0 {
    void Fn_002326a0();
};
class GrappleThrowAction_14adb0 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_14adb0* m20;
    Sub_14adb0 m24;
    GrappleThrowAction_14adb0* f2(unsigned char flags);
};
struct RefCounted_14ae50 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_14ae50[];
class CivilianThrowAction_14ae50 {
  public:
    CivilianThrowAction_14ae50* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_14ae50* m_20;
};
struct RefCounted_14aef0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_14aef0[];
class CivilianAttachAction_14aef0 {
  public:
    CivilianAttachAction_14aef0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_14aef0* m_20;
};
struct RefCounted_14af90 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_14af90[];
class CivilianDetachAction_14af90 {
  public:
    CivilianDetachAction_14af90* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_14af90* m_20;
};
struct RefCounted_14b030 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_14b030[];
class CivilianAnimationAction_14b030 {
  public:
    CivilianAnimationAction_14b030* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_14b030* m_20;
};
class ConditionFactoryCasterTemplate_14b3f0 {
  public:
    virtual bool Cast_00149c30(void*);
};
class Target {
  public:
    void Apply_00236760(void*);
};
void* FUN_002343e0(void*, ConditionFactoryCasterTemplate_14b3f0*);
class TrackFactoryCasterTemplate_14b4b0 {
  public:
    virtual bool Cast_00149db0(void*);
};
class Owner {
  public:
    void Set_002367c0(void*);
    void Add_002367c0(void*);
    void set_002367c0(void*);
};
extern "C" void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_14b4b0*);
class TrackFactoryCasterTemplate_14b4e0 {
  public:
    virtual bool Cast_00149e30(void*);
};
void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_14b4e0*);
class TrackFactoryCasterTemplate_14b510 {
  public:
    virtual bool Cast_00149eb0(void*);
};
extern "C++" __declspec(nothrow) void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_14b510*);
class Factory {
  public:
    void* Create_002367c0(void*);
    void Add_002367c0(Track*);
};
class TrackFactoryCasterTemplate_14b540 {
  public:
    virtual bool Fnf_00149f10(void*);
};
extern "C" void* __cdecl findTrack_00236ac0(const char*, TrackFactoryCasterTemplate_14b540*);
class TrackFactoryCasterTemplate_14b570 {
  public:
    virtual int dummy_00149f90(void*);
};
class Obj {
  public:
    void apply_002367c0(void*);
    int Get_002367c0(void*);
    void Set_002367c0(void*);
};
void* __cdecl find_00236ac0(void*, TrackFactoryCasterTemplate_14b570*);
class TrackFactoryCasterTemplate_14b5a0 {
  public:
    virtual bool Cast_00149ff0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_14b5a0*);
class TrackFactoryCasterTemplate_14b960 {
  public:
    virtual bool Cast_0014a0b0(void*);
};
Track* FUN_00236ac0(void*, TrackFactoryCasterTemplate_14b960*);
class TrackFactoryCasterTemplate_14b990 {
  public:
    virtual bool cast_0014a170(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_14b990*);
} // namespace fn_f1739f6f
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f1739f6f {
class TrackFactoryTemplate_14bc20 {
  public:
    TrackFactoryTemplate_14bc20() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00413598[];
extern void* __cdecl alloc_0008d690(unsigned int);
class GrappleAttachedCondition_14bc60 {
  public:
    GrappleAttachedCondition_14bc60(int);
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[8];
    unsigned char flag;
};
extern int hulk_at_00413db4;
struct ConditionFactoryTemplate_14bc90 {
    void* m_vptr;
    void base1_dtor_001471e0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_14bcc0 {
  public:
    TrackFactoryTemplate_14bcc0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
} // namespace fn_f1739f6f
void* operator new(size_t);
namespace hulkfight { namespace motion {
class BaseCondition {
  public:
    virtual void f();
    char pad[8];
    BaseCondition(int) throw();
};
} }
namespace hulkfight { namespace motion {
class CivilianAttachedCondition_14bd00 : public BaseCondition {
  public:
    virtual void f();
    unsigned char flag;
    CivilianAttachedCondition_14bd00(int x) throw() : BaseCondition(x), flag(1) {}
};
} }
namespace fn_f1739f6f {
extern int hulk_at_00413dd0;
struct ConditionFactoryTemplate_14bd30 {
    void* m_vptr;
    void base1_dtor_00147240();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_14bd60 {
  public:
    TrackFactoryTemplate_14bd60() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_004135d8[];
extern void* __cdecl Allocate(unsigned int);
class CivilianTargetCondition_14bda0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    CivilianTargetCondition_14bda0(int);
    char data[12];
};
extern int hulk_at_00413dec;
struct ConditionFactoryTemplate_14bdd0 {
    void* m_vptr;
    void base1_dtor_001472a0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_14be00 {
  public:
    TrackFactoryTemplate_14be00() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class BaseCondition {
  public:
    BaseCondition(int) throw();
    virtual void v0();
    virtual bool v1_00234270(void*);
    virtual bool v2_002342b0(int);
    char pad[8];
};
class GrappleOrientationCondition_14be40 : public BaseCondition {
  public:
    GrappleOrientationCondition_14be40() throw() : BaseCondition(0) {
        a = 0;
        b = 0x3fc90fdb;
    }
    virtual void v0();
    int a;
    int b;
};
extern int hulk_at_00413e08;
struct ConditionFactoryTemplate_14be80 {
    void* m_vptr;
    void base1_dtor_00147300();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_14beb0 {
  public:
    TrackFactoryTemplate_14beb0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00413618[];
extern "C" void* __cdecl FUN_0008d690(int size);
struct CDTrack {
    int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24;
    void Init_00236d40();
};
extern int hulk_at_00413e24;
class TrackFactoryTemplate_14bf60 {
  public:
    TrackFactoryTemplate_14bf60() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_14bfa0;
struct Grapple_14bfa0 {
    hulk_uintptr BuildTrack_00147430();
};
class TrackFactoryTemplate_14bff0 {
  public:
    TrackFactoryTemplate_14bff0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00413678[];
typedef unsigned int u32_14c030;
struct GrappleStruggleTrack_14c030 {
    hulk_uintptr a0, a4, a8, ac, a10, a14, a18, a1c, a20;
    void initialize_00236d40();
};
class TrackFactoryTemplate_14c0b0 {
  public:
    TrackFactoryTemplate_14c0b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_14c0f0;
struct Grapple_14c0f0 {
    hulk_uintptr BuildTrack_00147590();
};
class TrackFactoryTemplate_14c140 {
  public:
    TrackFactoryTemplate_14c140() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_004136d8[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Track_14c180 {
  public:
    Track_14c180();
};
class TrackFactoryTemplate_14c1e0 {
  public:
    TrackFactoryTemplate_14c1e0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
void* operator_new(unsigned int);
typedef unsigned int u32_14c220;
struct Base1_14c220 {
    void Init1_00236d40();
};
struct Sub1_14c220 {
    void Init2_00233dd0();
};
struct Sub2_14c220 {
    void Init3_00236e00();
};
class TrackFactoryTemplate_14c2a0 {
  public:
    TrackFactoryTemplate_14c2a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00413578[];
class Base_14c2e0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* F();
};
class Cond_14c2e0 {
  public:
    void Init_00234590(int);
};
class Sub_14c2e0 {
  public:
    void Init_0027af00();
};
class Factory_14c2e0 : public Base_14c2e0 {
  public:
    char pad[8];
    int field;
    Sub_14c2e0 sub;
    void* F();
};
extern int hulk_at_00413ecc;
struct ConditionFactoryTemplate_14c320 {
    void* m_vptr;
    void base1_dtor_00147160();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_14c350 {
  public:
    TrackFactoryTemplate_14c350() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class TrackFactoryTemplate_14c3e0 {
  public:
    TrackFactoryTemplate_14c3e0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
struct CivilianAnimationTrack_nv_14c420 {
    void* init_00147860();
};

} // namespace fn_f1739f6f

// 0x00146900 FUN_00146900 (12 B): matches/0x00146900.cpp
// sym: ?FUN_00146900@O_146900@owners@@QAEDH@Z
char owners::O_146900::FUN_00146900(int a) {
    m = a;
    return 1;
}


// 0x00146910 FUN_00146910 (4 B): matches/0x00146910.cpp
// sym: ?FUN_00146910@O_146910@owners@@QAEPAXXZ
void* owners::O_146910::FUN_00146910() {
    return (void*)((char*)this + 0x10);
}


// 0x00146920 FUN_00146920 (12 B): matches/0x00146920.cpp
// sym: ?FUN_00146920@Obj_146920@owners@@QAE_ND@Z
bool owners::Obj_146920::FUN_00146920(char value) {
    mFlag = value;
    return true;
}


// 0x00146930 FUN_00146930 (12 B): matches/0x00146930.cpp
// sym: ?FUN_00146930@Obj_146930@owners@@QAEEE@Z
unsigned char owners::Obj_146930::FUN_00146930(unsigned char c) {
    m = (char)c;
    return 1;
}


// 0x00146940 FUN_00146940 (12 B): matches/0x00146940.cpp
// sym: ?FUN_00146940@Obj_146940@owners@@QAEEE@Z
unsigned char owners::Obj_146940::FUN_00146940(unsigned char v) {
    mVal = v;
    return 1;
}


// 0x00146950 FUN_00146950 (18 B): matches/0x00146950.cpp
// sym: ?FUN_00146950@Thing_146950@owners@@QAEDM@Z
char owners::Thing_146950::FUN_00146950(float f) {
    char r = 1;
    *(float*)((char*)this + 0xc) = f * 0.0174532925f;
    return r;
}


// 0x00146970 FUN_00146970 (18 B): matches/0x00146970.cpp
// sym: ?FUN_00146970@Obj_146970@owners@@QAE_NM@Z
bool owners::Obj_146970::FUN_00146970(float degrees) {
    value = degrees * 0.017453292519943295f;
    return true;
}

namespace fn_f1739f6f {

// 0x00146990 FUN_00146990 (12 B): matches/0x00146990.cpp
// sym: ?Set@Obj_146990@fn_f1739f6f@@QAE_NH@Z
bool Obj_146990::Set(int value) {
    mValue = value;
    return true;
}


// 0x001469c0 FUN_001469c0 (26 B): matches/0x001469c0.cpp
// sym: ?Set@Obj_1469c0@fn_f1739f6f@@QAEDPBUVec3_1469c0@2@@Z
char Obj_1469c0::Set(const Vec3_1469c0* src) {
    mVec.x = src->x;
    mVec.y = src->y;
    mVec.z = src->z;
    return 1;
}


// 0x00146a00 FUN_00146a00 (60 B): equivalent/0x00146a00.cpp
// sym: ?FUN_00146a00@Angles@fn_f1739f6f@@QAEIPBM@Z @cba8749b4cd7 @wefe7b7b792f3
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00146a00 @ 0x00146a00
unsigned int Angles::FUN_00146a00(const float *input) {
    x = input[0] * (*(float*)&DAT_003f32b8);
    y = input[1] * (*(float*)&DAT_003f32b8);
    z = input[2] * (*(float*)&DAT_003f32b8);
    return (*reinterpret_cast<unsigned int *>(&z) & 0xffffff00u) | 1u;
}

} // namespace fn_f1739f6f

// 0x00146a40 FUN_00146a40 (12 B): matches/0x00146a40.cpp
// sym: ?FUN_00146a40@Obj_146a40@owners@@QAEEH@Z
unsigned char owners::Obj_146a40::FUN_00146a40(int x) {
    value = x;
    return 1;
}

namespace fn_f1739f6f {

// 0x00146a70 FUN_00146a70 (26 B): matches/0x00146a70.cpp
// sym: ?Set@Owner_146a70@fn_f1739f6f@@QAEDPAUSrc_146a70@2@@Z
char Owner_146a70::Set(Src_146a70* p) {
    m10 = p->a;
    m14 = p->b;
    m18 = p->c;
    return 1;
}

} // namespace fn_f1739f6f

// 0x00146aa0 FUN_00146aa0 (12 B): matches/0x00146aa0.cpp
// sym: ?FUN_00146aa0@Obj_146aa0@owners@@QAE_NH@Z
bool owners::Obj_146aa0::FUN_00146aa0(int x) {
    field = x;
    return true;
}


// 0x00146ac0 FUN_00146ac0 (12 B): matches/0x00146ac0.cpp
// sym: ?FUN_00146ac0@C_146ac0@owners@@QAE_NH@Z
bool owners::C_146ac0::FUN_00146ac0(int x) {
    m = x;
    return true;
}


// 0x00146ae0 FUN_00146ae0 (12 B): matches/0x00146ae0.cpp
// sym: ?FUN_00146ae0@Obj_146ae0@owners@@QAEDH@Z
char owners::Obj_146ae0::FUN_00146ae0(int x) {
    value = x;
    return 1;
}


// 0x00146b00 FUN_00146b00 (12 B): matches/0x00146b00.cpp
// sym: ?FUN_00146b00@Obj_146b00@owners@@QAEDH@Z
char owners::Obj_146b00::FUN_00146b00(int x) {
    value = x;
    return 1;
}


// 0x00146b20 FUN_00146b20 (18 B): matches/0x00146b20.cpp
// sym: ?FUN_00146b20@Obj_146b20@owners@@QAEDM@Z
char owners::Obj_146b20::FUN_00146b20(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}


// 0x00146b50 FUN_00146b50 (18 B): matches/0x00146b50.cpp
// sym: ?FUN_00146b50@C_146b50@owners@@QAE_NM@Z
bool owners::C_146b50::FUN_00146b50(float deg) {
    mRad = deg * 0.017453292f;
    return true;
}


// 0x00146b80 FUN_00146b80 (18 B): matches/0x00146b80.cpp
// sym: ?FUN_00146b80@X_146b80@owners@@QAE_NM@Z
bool owners::X_146b80::FUN_00146b80(float v) {
    angle = v * kScale_146b80;
    return true;
}


// 0x00146bb0 FUN_00146bb0 (12 B): matches/0x00146bb0.cpp
// sym: ?FUN_00146bb0@Obj_146bb0@owners@@QAE_NH@Z
bool owners::Obj_146bb0::FUN_00146bb0(int x) {
    value = x;
    return true;
}


// 0x00146bd0 FUN_00146bd0 (12 B): matches/0x00146bd0.cpp
// sym: ?FUN_00146bd0@Obj_146bd0@owners@@QAEDH@Z
char owners::Obj_146bd0::FUN_00146bd0(int value) {
    m3c = value;
    return 1;
}


// 0x00146be0 FUN_00146be0 (12 B): matches/0x00146be0.cpp
// sym: ?FUN_00146be0@Obj_146be0@owners@@QAEDH@Z
char owners::Obj_146be0::FUN_00146be0(int value) {
    mValue = value;
    return 1;
}


// 0x00146bf0 FUN_00146bf0 (12 B): matches/0x00146bf0.cpp
// sym: ?FUN_00146bf0@Obj_146bf0@owners@@QAE_NH@Z
bool owners::Obj_146bf0::FUN_00146bf0(int x) {
    value = x;
    return true;
}


// 0x00146c10 FUN_00146c10 (12 B): matches/0x00146c10.cpp
// sym: ?FUN_00146c10@X_146c10@owners@@QAE_NH@Z
bool owners::X_146c10::FUN_00146c10(int a) {
    m = a;
    return true;
}


// 0x00146c30 FUN_00146c30 (12 B): matches/0x00146c30.cpp
// sym: ?FUN_00146c30@X_146c30@owners@@QAEDPAD@Z
char owners::X_146c30::FUN_00146c30(char* p) {
    m18 = p;
    return 1;
}


// 0x00146c50 FUN_00146c50 (12 B): matches/0x00146c50.cpp
// sym: ?FUN_00146c50@A_146c50@owners@@QAEDH@Z
char owners::A_146c50::FUN_00146c50(int x) {
    mVal = x;
    return 1;
}


// 0x00146c70 FUN_00146c70 (12 B): matches/0x00146c70.cpp
// sym: ?FUN_00146c70@Target_146c70@owners@@QAE_NH@Z
bool owners::Target_146c70::FUN_00146c70(int v) {
    mValue = v;
    return true;
}


// 0x00146c80 FUN_00146c80 (12 B): matches/0x00146c80.cpp
// sym: ?FUN_00146c80@Obj_146c80@owners@@QAE_NH@Z
bool owners::Obj_146c80::FUN_00146c80(int a) {
    m1c = a;
    return true;
}

namespace fn_f1739f6f {

// 0x00146cb0 FUN_00146cb0 (26 B): matches/0x00146cb0.cpp
// sym: ?Set@Obj_146cb0@fn_f1739f6f@@QAEDPAUVec3_146cb0@2@@Z
char Obj_146cb0::Set(Vec3_146cb0* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return 1;
}

} // namespace fn_f1739f6f

// 0x00146ce0 FUN_00146ce0 (12 B): matches/0x00146ce0.cpp
// sym: ?FUN_00146ce0@Obj_146ce0@owners@@QAE_NH@Z
bool owners::Obj_146ce0::FUN_00146ce0(int v) {
    mVal = v;
    return true;
}


// 0x00146d00 FUN_00146d00 (12 B): matches/0x00146d00.cpp
// sym: ?FUN_00146d00@Obj_146d00@owners@@QAEDH@Z
char owners::Obj_146d00::FUN_00146d00(int v) {
    mField = v;
    return 1;
}


// 0x00146d20 FUN_00146d20 (12 B): matches/0x00146d20.cpp
// sym: ?FUN_00146d20@X_146d20@owners@@QAE_NH@Z
bool owners::X_146d20::FUN_00146d20(int v) {
    m24 = v;
    return true;
}


// 0x00146d40 FUN_00146d40 (12 B): matches/0x00146d40.cpp
// sym: ?FUN_00146d40@Obj_146d40@owners@@QAEDH@Z
char owners::Obj_146d40::FUN_00146d40(int value) {
    m28 = value;
    return 1;
}


// 0x00146d60 FUN_00146d60 (18 B): matches/0x00146d60.cpp
// sym: ?FUN_00146d60@Layout_146d60@owners@@QAE_NM@Z
bool owners::Layout_146d60::FUN_00146d60(float angle) {
    mAngle = angle * 0.017453292519943295f;
    return true;
}


// 0x00146d90 FUN_00146d90 (18 B): matches/0x00146d90.cpp
// sym: ?FUN_00146d90@A_146d90@owners@@QAEDM@Z
char owners::A_146d90::FUN_00146d90(float v) {
    f30 = v * 0.017453292f;
    return 1;
}


// 0x00146dc0 FUN_00146dc0 (18 B): matches/0x00146dc0.cpp
// sym: ?FUN_00146dc0@Obj_146dc0@owners@@QAE_NM@Z
bool owners::Obj_146dc0::FUN_00146dc0(float value) {
    m = value * k_146dc0;
    return true;
}


// 0x00146df0 FUN_00146df0 (12 B): matches/0x00146df0.cpp
// sym: ?FUN_00146df0@Obj_146df0@owners@@QAE_NH@Z
bool owners::Obj_146df0::FUN_00146df0(int x) {
    m38 = x;
    return true;
}


// 0x00146e10 FUN_00146e10 (12 B): matches/0x00146e10.cpp
// sym: ?FUN_00146e10@Obj_146e10@owners@@QAE_NH@Z
bool owners::Obj_146e10::FUN_00146e10(int x) {
    m3c = x;
    return true;
}


// 0x00146e20 FUN_00146e20 (12 B): matches/0x00146e20.cpp
// sym: ?FUN_00146e20@O_146e20@owners@@QAEDH@Z
char owners::O_146e20::FUN_00146e20(int x) {
    m = x;
    return 1;
}


// 0x00146e30 FUN_00146e30 (12 B): matches/0x00146e30.cpp
// sym: ?FUN_00146e30@Obj_146e30@owners@@QAE_NH@Z
bool owners::Obj_146e30::FUN_00146e30(int x) {
    mVal = x;
    return true;
}


// 0x00146e50 FUN_00146e50 (12 B): matches/0x00146e50.cpp
// sym: ?FUN_00146e50@Obj_146e50@owners@@QAE_NPAX@Z
bool owners::Obj_146e50::FUN_00146e50(void* p) {
    m10 = p;
    return true;
}


// 0x00146e70 FUN_00146e70 (12 B): matches/0x00146e70.cpp
// sym: ?FUN_00146e70@A_146e70@owners@@QAE_NH@Z
bool owners::A_146e70::FUN_00146e70(int x) {
    value = x;
    return true;
}


// 0x00146e90 FUN_00146e90 (18 B): matches/0x00146e90.cpp
// sym: ?FUN_00146e90@T_146e90@owners@@QAEEM@Z
unsigned char owners::T_146e90::FUN_00146e90(float x) {
    v = x * 0.017453293f;
    return 1;
}


// 0x00146eb0 FUN_00146eb0 (4 B): matches/0x00146eb0.cpp
// sym: ?FUN_00146eb0@Obj_146eb0@owners@@QAEPAXXZ
void* owners::Obj_146eb0::FUN_00146eb0() {
    return (void*)((char*)this + 0x20);
}


// 0x00146ed0 FUN_00146ed0 (12 B): matches/0x00146ed0.cpp
// sym: ?FUN_00146ed0@X_146ed0@owners@@QAE_NH@Z
bool owners::X_146ed0::FUN_00146ed0(int a) {
    field = a;
    return true;
}


// 0x00146ef0 FUN_00146ef0 (12 B): matches/0x00146ef0.cpp
// sym: ?FUN_00146ef0@Obj_146ef0@owners@@QAEDH@Z
char owners::Obj_146ef0::FUN_00146ef0(int v) {
    value = v;
    return 1;
}


// 0x00146f10 FUN_00146f10 (12 B): matches/0x00146f10.cpp
// sym: ?FUN_00146f10@Obj_146f10@owners@@QAE_NH@Z
bool owners::Obj_146f10::FUN_00146f10(int value) {
    m30 = value;
    return true;
}


// 0x00146f30 FUN_00146f30 (12 B): matches/0x00146f30.cpp
// sym: ?FUN_00146f30@Obj_146f30@owners@@QAE_ND@Z
bool owners::Obj_146f30::FUN_00146f30(char a) {
    *(char*)((char*)this + 0x34) = a;
    return true;
}


// 0x00146f50 FUN_00146f50 (12 B): matches/0x00146f50.cpp
// sym: ?FUN_00146f50@Obj_146f50@owners@@QAEEPAX@Z
unsigned char owners::Obj_146f50::FUN_00146f50(void* v) {
    m38 = v;
    return 1;
}


// 0x00146f70 FUN_00146f70 (12 B): matches/0x00146f70.cpp
// sym: ?FUN_00146f70@Base_146f70@owners@@QAE_NH@Z
bool owners::Base_146f70::FUN_00146f70(int x) {
    m3c = x;
    return true;
}


// 0x00146f90 FUN_00146f90 (18 B): matches/0x00146f90.cpp
// sym: ?FUN_00146f90@Obj_146f90@owners@@QAEDM@Z
char owners::Obj_146f90::FUN_00146f90(float deg) {
    value = deg * 0.01745329238474369f;
    return 1;
}


// 0x00146fc0 FUN_00146fc0 (12 B): matches/0x00146fc0.cpp
// sym: ?FUN_00146fc0@X_146fc0@owners@@QAEDH@Z
char owners::X_146fc0::FUN_00146fc0(int v) {
    *(int*)((char*)this + 0x44) = v;
    return 1;
}


// 0x00146fe0 FUN_00146fe0 (12 B): matches/0x00146fe0.cpp
// sym: ?FUN_00146fe0@Obj_146fe0@owners@@QAEDH@Z
char owners::Obj_146fe0::FUN_00146fe0(int x) {
    value = x;
    return 1;
}


// 0x00147000 FUN_00147000 (12 B): matches/0x00147000.cpp
// sym: ?FUN_00147000@Obj_147000@owners@@QAEDH@Z
char owners::Obj_147000::FUN_00147000(int v) throw() {
    mVal = v;
    return 1;
}


// 0x00147020 FUN_00147020 (12 B): matches/0x00147020.cpp
// sym: ?FUN_00147020@Obj_147020@owners@@QAEDH@Z
char owners::Obj_147020::FUN_00147020(int x) {
    m50 = x;
    return 1;
}


// 0x00147030 FUN_00147030 (12 B): matches/0x00147030.cpp
// sym: ?FUN_00147030@X_147030@owners@@QAEDH@Z
char owners::X_147030::FUN_00147030(int v) {
    m = v;
    return 1;
}


// 0x00147040 FUN_00147040 (12 B): matches/0x00147040.cpp
// sym: ?FUN_00147040@Thing_147040@owners@@QAE_NH@Z
bool owners::Thing_147040::FUN_00147040(int x) {
    value = x;
    return true;
}


// 0x00147050 FUN_00147050 (4 B): matches/0x00147050.cpp
// sym: ?FUN_00147050@Foo_147050@owners@@QAEPAHXZ
int* owners::Foo_147050::FUN_00147050() {
    return &mVal;
}


// 0x00147070 FUN_00147070 (12 B): matches/0x00147070.cpp
// sym: ?FUN_00147070@Obj_147070@owners@@QAEDPAX@Z
char owners::Obj_147070::FUN_00147070(void* x) {
    *(void**)(m + 0x20) = x;
    return 1;
}


// 0x00147080 FUN_00147080 (4 B): matches/0x00147080.cpp
// sym: ?FUN_00147080@Obj_147080@owners@@QAEPADXZ
char* owners::Obj_147080::FUN_00147080() {
    return pad + 0x24;
}


// 0x00147090 FUN_00147090 (12 B): matches/0x00147090.cpp
// sym: ?FUN_00147090@O_147090@owners@@QAE_NH@Z
bool owners::O_147090::FUN_00147090(int x) {
    m = x;
    return true;
}


// 0x001470b0 FUN_001470b0 (12 B): matches/0x001470b0.cpp
// sym: ?FUN_001470b0@Target_1470b0@owners@@QAE_NH@Z
bool owners::Target_1470b0::FUN_001470b0(int x) {
    mField = x;
    return true;
}


// 0x001470c0 FUN_001470c0 (4 B): matches/0x001470c0.cpp
// sym: ?FUN_001470c0@A_1470c0@owners@@QAEPAXXZ
void* owners::A_1470c0::FUN_001470c0() {
    return &data;
}


// 0x001470e0 FUN_001470e0 (12 B): matches/0x001470e0.cpp
// sym: ?FUN_001470e0@Obj_1470e0@owners@@QAEDH@Z
char owners::Obj_1470e0::FUN_001470e0(int x) {
    *(int*)((char*)this + 0x20) = x;
    return 1;
}


// 0x00147100 FUN_00147100 (12 B): matches/0x00147100.cpp
// sym: ?FUN_00147100@Obj_147100@owners@@QAEDH@Z
char owners::Obj_147100::FUN_00147100(int x) {
    m24 = x;
    return 1;
}


// 0x00147120 FUN_00147120 (12 B): matches/0x00147120.cpp
// sym: ?FUN_00147120@X_147120@owners@@QAEDE@Z
char owners::X_147120::FUN_00147120(unsigned char a) {
    m28 = a;
    return 1;
}


// 0x00147140 FUN_00147140 (12 B): matches/0x00147140.cpp
// sym: ?FUN_00147140@Obj_147140@owners@@QAEDH@Z
char owners::Obj_147140::FUN_00147140(int x) {
    Value = x;
    return 1;
}

namespace fn_f1739f6f {

// 0x00147160 FUN_00147160 (19 B): matches/0x00147160.cpp
// sym: ?FUN_00147160@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00147160() {
    FUN_00234810(((char*)&DAT_004e0fbc), ((char*)&DAT_004e0fc0));
}

} // namespace fn_f1739f6f

// 0x00147180 hulkfight::motion::GrappleAttachJointCondition::vfunc_0 (16 B): matches/0x00147180.cpp
// sym: ?vfunc_0@GrappleAttachJointCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleAttachJointCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0fbc;
    return p[index];
}

namespace fn_f1739f6f {

// 0x001471c0 FUN_001471c0 (25 B): matches/0x001471c0.cpp
// sym: ?f@GrappleAttachJointCondition_1471c0@fn_f1739f6f@@QAEXXZ
void GrappleAttachJointCondition_1471c0::f() {
    vptr = hulk_at_00413578;
    sub.Fin_0027af50();
    Fin_002345b0();
}


// 0x001471e0 FUN_001471e0 (19 B): matches/0x001471e0.cpp
// sym: ?FUN_001471e0@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001471e0() {
    FUN_00234810(((char*)&DAT_004e0fc4), ((char*)&DAT_004e0fc8));
}

} // namespace fn_f1739f6f

// 0x00147200 hulkfight::motion::GrappleAttachedCondition::vfunc_0 (16 B): matches/0x00147200.cpp
// sym: ?vfunc_0@GrappleAttachedCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleAttachedCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0fc4;
    return p[index];
}

namespace fn_f1739f6f {

// 0x00147240 FUN_00147240 (19 B): matches/0x00147240.cpp
// sym: ?FUN_00147240@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00147240() {
    FUN_00234810(((char*)&DAT_004e0fcc), ((char*)&DAT_004e0fd0));
}

} // namespace fn_f1739f6f

// 0x00147260 hulkfight::motion::CivilianAttachedCondition::vfunc_0 (16 B): matches/0x00147260.cpp
// sym: ?vfunc_0@CivilianAttachedCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CivilianAttachedCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0fcc;
    return p[index];
}

namespace fn_f1739f6f {

// 0x001472a0 FUN_001472a0 (19 B): matches/0x001472a0.cpp
// sym: ?FUN_001472a0@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001472a0() {
    FUN_00234810(((char*)&DAT_004e0fd4), ((char*)&DAT_004e0fd8));
}

} // namespace fn_f1739f6f

// 0x001472c0 hulkfight::motion::CivilianTargetCondition::vfunc_0 (16 B): matches/0x001472c0.cpp
// sym: ?vfunc_0@CivilianTargetCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CivilianTargetCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0fd4;
    return p[index];
}

namespace fn_f1739f6f {

// 0x00147300 FUN_00147300 (19 B): matches/0x00147300.cpp
// sym: ?FUN_00147300@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00147300() {
    FUN_00234810(((char*)&DAT_004e0fdc), ((char*)&DAT_004e0fe0));
}

} // namespace fn_f1739f6f

// 0x00147320 hulkfight::motion::GrappleOrientationCondition::vfunc_0 (16 B): matches/0x00147320.cpp
// sym: ?vfunc_0@GrappleOrientationCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleOrientationCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0fdc;
    return p[index];
}

namespace fn_f1739f6f {

// 0x00147370 FUN_00147370 (19 B): matches/0x00147370.cpp
// sym: ?FUN_00147370@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00147370() {
    FUN_00234810(((char*)&DAT_004e0fe4), ((char*)&DAT_004e0fe8));
}

} // namespace fn_f1739f6f

// 0x00147390 hulkfight::motion::CivilianDetachTrack::vfunc_0 (16 B): matches/0x00147390.cpp
// sym: ?vfunc_0@CivilianDetachTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CivilianDetachTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0fe4;
    return p[index];
}


// 0x001473a0 FUN_001473a0 (41 B): matches/0x001473a0.cpp [wrapped: conflict: hulkfight::motion::CivilianDetachTrack]
// sym: ??0CivilianDetachTrack@motion@hulkfight@fn_001473a0@@QAE@XZ
namespace fn_001473a0 {
extern "C" void _ReadWriteBarrier();
namespace hulkfight {
namespace motion {
class Base {
  public:
    virtual void f();
    Base();
    char pad[8];
    int p;
};
class Mid : public Base {
  public:
    Mid() : Base() { p = 0; }
};
class CivilianDetachTrack : public Mid {
  public:
    CivilianDetachTrack();
    virtual bool Fng_00234270(void*);
    int a, b, c, d, e, f0;
};
CivilianDetachTrack::CivilianDetachTrack() : Mid() {
    _ReadWriteBarrier();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f0 = 0;
}
} // namespace motion
} // namespace hulkfight
} // namespace fn_001473a0


// 0x001473d0 hulkfight::motion::CivilianDetachTrack::vfunc_6 (4 B): matches/0x001473d0.cpp
// sym: ?vfunc_6@CivilianDetachTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::CivilianDetachTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001473e0 hulkfight::motion::CivilianDetachTrack::vfunc_7 (7 B): matches/0x001473e0.cpp
// sym: ?vfunc_7@CivilianDetachTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::CivilianDetachTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f1739f6f {

// 0x00147400 FUN_00147400 (19 B): matches/0x00147400.cpp
// sym: ?FUN_00147400@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00147400() {
    FUN_00234810(((char*)&DAT_004e0fec), ((char*)&DAT_004e0ff0));
}

} // namespace fn_f1739f6f

// 0x00147420 hulkfight::motion::GrappleThrowTrack::vfunc_0 (16 B): matches/0x00147420.cpp
// sym: ?vfunc_0@GrappleThrowTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleThrowTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0fec;
    return p[index];
}


// 0x00147430 FUN_00147430 (81 B): equivalent/0x00147430.cpp [wrapped: conflict: hulkfight::motion::GrappleThrowTrack]
// sym: ??0GrappleThrowTrack@motion@hulkfight@fn_00147430@@QAE@XZ @1d7e20e2a007 @w253f15429f9c
namespace fn_00147430 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00147430 @ 0x00147430
namespace hulkfight { namespace motion {
struct BaseTrack {
    virtual void slot0();
    BaseTrack();
    char pad[8];
};
struct GrappleThrowTrack : BaseTrack {
    virtual void slot0();
    void* field_c;
    void* field_10;
    void* field_14;
    float field_18;
    float field_1c;
    float field_20;
    float field_24;
    float field_28;
    float field_2c;
    int field_30;
    int field_34;
    int field_38;
    float field_3c;
    GrappleThrowTrack();
};
GrappleThrowTrack::GrappleThrowTrack() {
    field_c = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = -1.0f;
    field_30 = 0;
    field_34 = 0;
    field_38 = 0;
    field_1c = 10.0f;
    field_20 = 100.0f;
    field_24 = 10.0f;
    field_28 = 100.0f;
    field_2c = 1.57079637f;
    field_3c = 1.0f;
}
}}
} // namespace fn_00147430


// 0x00147490 hulkfight::motion::GrappleThrowTrack::vfunc_6 (4 B): matches/0x00147490.cpp
// sym: ?vfunc_6@GrappleThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::GrappleThrowTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001474a0 hulkfight::motion::GrappleThrowTrack::vfunc_7 (7 B): matches/0x001474a0.cpp
// sym: ?vfunc_7@GrappleThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::GrappleThrowTrack::vfunc_7() {
    return hulk_at_003f3388;
}

namespace fn_f1739f6f {

// 0x001474c0 FUN_001474c0 (19 B): matches/0x001474c0.cpp
// sym: ?FUN_001474c0@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001474c0() {
    FUN_00234810(((char*)&DAT_004e0ff4), ((char*)&DAT_004e0ff8));
}

} // namespace fn_f1739f6f

// 0x001474e0 hulkfight::motion::GrappleStruggleTrack::vfunc_0 (16 B): matches/0x001474e0.cpp
// sym: ?vfunc_0@GrappleStruggleTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleStruggleTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ff4;
    return p[index];
}

namespace fn_f1739f6f {

// 0x001474f0 FUN_001474f0 (49 B): matches/0x001474f0.cpp
// sym: ??0GrappleStruggleTrack@fn_f1739f6f@@QAE@XZ
GrappleStruggleTrack::GrappleStruggleTrack() : Track_1474f0() {
    b = 0;
    d = 0;
    e = 0;
    g = 0;
    h = 0;
    c = -1.0f;
    a = 1;
}

} // namespace fn_f1739f6f

// 0x00147530 hulkfight::motion::GrappleStruggleTrack::vfunc_6 (4 B): matches/0x00147530.cpp
// sym: ?vfunc_6@GrappleStruggleTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::GrappleStruggleTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00147540 hulkfight::motion::GrappleStruggleTrack::vfunc_7 (7 B): matches/0x00147540.cpp
// sym: ?vfunc_7@GrappleStruggleTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::GrappleStruggleTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f1739f6f {

// 0x00147560 FUN_00147560 (19 B): matches/0x00147560.cpp
// sym: ?FUN_00147560@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00147560() {
    FUN_00234810(((char*)&DAT_004e0ffc), ((char*)&DAT_004e1000));
}

} // namespace fn_f1739f6f

// 0x00147580 hulkfight::motion::CivilianThrowTrack::vfunc_0 (16 B): matches/0x00147580.cpp
// sym: ?vfunc_0@CivilianThrowTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CivilianThrowTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ffc;
    return p[index];
}

namespace fn_f1739f6f {

// 0x00147590 FUN_00147590 (81 B): matches/0x00147590.cpp
// sym: ??0CivilianThrowTrack@fn_f1739f6f@@QAE@XZ
CivilianThrowTrack::CivilianThrowTrack() {
    b = 0;
    c = 0;
    d = -1.0f;
    _ReadWriteBarrier();
    e = 10.0f;
    f = 100.0f;
    g = 10.0f;
    h = 100.0f;
    i = 3.1415927f / 2;
    j = 0;
    k = 0;
    l = 0;
    m = 1.0f;
}

} // namespace fn_f1739f6f

// 0x001475f0 hulkfight::motion::CivilianThrowTrack::vfunc_6 (4 B): matches/0x001475f0.cpp
// sym: ?vfunc_6@CivilianThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::CivilianThrowTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00147600 hulkfight::motion::CivilianThrowTrack::vfunc_7 (7 B): matches/0x00147600.cpp
// sym: ?vfunc_7@CivilianThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::CivilianThrowTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f1739f6f {

// 0x00147620 FUN_00147620 (19 B): matches/0x00147620.cpp
// sym: ?FUN_00147620@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00147620() {
    FUN_00234810(((char*)&DAT_004e1004), ((char*)&DAT_004e1008));
}

} // namespace fn_f1739f6f

// 0x00147640 hulkfight::motion::CivilianAttachTrack::vfunc_0 (16 B): matches/0x00147640.cpp
// sym: ?vfunc_0@CivilianAttachTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CivilianAttachTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1004;
    return p[index];
}

namespace fn_f1739f6f {

// 0x00147650 FUN_00147650 (25 B): matches/0x00147650.cpp
// sym: ??0CivilianAttachTrack_147650@fn_f1739f6f@@QAE@XZ
CivilianAttachTrack_147650::CivilianAttachTrack_147650() : Track_147650() {
    vptr = ((void**)DAT_004136d8);
    mc = 0;
}

} // namespace fn_f1739f6f

// 0x00147670 hulkfight::motion::CivilianAttachTrack::vfunc_6 (4 B): matches/0x00147670.cpp
// sym: ?vfunc_6@CivilianAttachTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::CivilianAttachTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00147680 hulkfight::motion::CivilianAttachTrack::vfunc_7 (7 B): matches/0x00147680.cpp
// sym: ?vfunc_7@CivilianAttachTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::CivilianAttachTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f1739f6f {

// 0x001476a0 FUN_001476a0 (19 B): matches/0x001476a0.cpp
// sym: ?FUN_001476a0@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001476a0() {
    FUN_00234810(((char*)&DAT_004e100c), ((char*)&DAT_004e1010));
}

} // namespace fn_f1739f6f

// 0x001476c0 hulkfight::motion::GrappleHitReactionTrack::vfunc_0 (16 B): matches/0x001476c0.cpp
// sym: ?vfunc_0@GrappleHitReactionTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleHitReactionTrack::vfunc_0(int index) {
    int* p = hulk_at_004e100c;
    return p[index];
}

namespace fn_f1739f6f {

// 0x001476d0 FUN_001476d0 (83 B): matches/0x001476d0.cpp
// sym: ??0GrappleHitReactionTrack@fn_f1739f6f@@QAE@XZ
GrappleHitReactionTrack::GrappleHitReactionTrack()
    : Track_1476d0(), a(0), b(0), c(0), d(0), sub(), e(0), f1(0), g(0), h(0), i(0), j(0), k(0), l(0), m(0), o(0) {
    flag = 1;
    mode = 3;
}

} // namespace fn_f1739f6f

// 0x00147730 hulkfight::motion::GrappleHitReactionTrack::vfunc_6 (4 B): matches/0x00147730.cpp
// sym: ?vfunc_6@GrappleHitReactionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::GrappleHitReactionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00147740 hulkfight::motion::GrappleHitReactionTrack::vfunc_7 (7 B): matches/0x00147740.cpp
// sym: ?vfunc_7@GrappleHitReactionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::GrappleHitReactionTrack::vfunc_7() {
    return hulk_at_003f3388;
}

namespace fn_f1739f6f {

// 0x00147750 FUN_00147750 (25 B): matches/0x00147750.cpp
// sym: ??1GrappleHitReactionTrack_147750@fn_f1739f6f@@QAE@XZ
GrappleHitReactionTrack_147750::~GrappleHitReactionTrack_147750() throw() {
    vptr = hulk_at_00413708;
    sub.Fin_0027af50();
}


// 0x00147770 FUN_00147770 (19 B): matches/0x00147770.cpp
// sym: ?FUN_00147770@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00147770() {
    FUN_00234810(((char*)&DAT_004e1014), ((char*)&DAT_004e1018));
}

} // namespace fn_f1739f6f

// 0x00147790 hulkfight::motion::GrappleExecuteTrack::vfunc_0 (16 B): matches/0x00147790.cpp
// sym: ?vfunc_0@GrappleExecuteTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleExecuteTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1014;
    return p[index];
}

namespace fn_f1739f6f {

// 0x001477a0 FUN_001477a0 (55 B): matches/0x001477a0.cpp
// sym: ??0GrappleExecuteTrack@fn_f1739f6f@@QAE@XZ
GrappleExecuteTrack::GrappleExecuteTrack() : Track_1477a0(), a(0), b(-1.0f), p(), c(-1000), q() {}

} // namespace fn_f1739f6f

// 0x001477e0 hulkfight::motion::GrappleExecuteTrack::vfunc_6 (4 B): matches/0x001477e0.cpp
// sym: ?vfunc_6@GrappleExecuteTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::GrappleExecuteTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001477f0 hulkfight::motion::GrappleExecuteTrack::vfunc_7 (7 B): matches/0x001477f0.cpp
// sym: ?vfunc_7@GrappleExecuteTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::GrappleExecuteTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x00147800 FUN_00147800 (33 B): matches/0x00147800.cpp
// sym: ?FUN_00147800@GrappleExecuteTrack@motion@hulkfight@@QAEXXZ
void hulkfight::motion::GrappleExecuteTrack::FUN_00147800() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_00413738);
    ((PartA_147800*)((char*)this + 0x24))->Init_00236fd0();
    ((PartB_147800*)((char*)this + 0x14))->Init_00234150();
    ((End_147800*)this)->Finish_00236d60();
}

namespace fn_f1739f6f {

// 0x00147830 FUN_00147830 (19 B): matches/0x00147830.cpp
// sym: ?FUN_00147830@fn_f1739f6f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00147830() {
    FUN_00234810(((char*)&DAT_004e101c), ((char*)&DAT_004e1020));
}

} // namespace fn_f1739f6f

// 0x00147850 hulkfight::motion::CivilianAnimationTrack::vfunc_0 (16 B): matches/0x00147850.cpp
// sym: ?vfunc_0@CivilianAnimationTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CivilianAnimationTrack::vfunc_0(int index) {
    int* p = hulk_at_004e101c;
    return p[index];
}


// 0x00147860 FUN_00147860 (72 B): matches/0x00147860.cpp [wrapped: conflict: hulkfight::motion::CivilianAnimationTrack]
// sym: ??0CivilianAnimationTrack@motion@hulkfight@fn_00147860@@QAE@XZ
namespace fn_00147860 {
namespace hulkfight {
namespace motion {
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class CivilianAnimationTrack : public Base {
  public:
    CivilianAnimationTrack();
    virtual void f();
    int a;
    float b;
    char pad2[4];
    Part part;
    float c;
    int d;
    char e;
    char pad3[3];
    float g;
};
CivilianAnimationTrack::CivilianAnimationTrack()
    : Base(), a(0), b(-1.0f), part(), c(1.0f), d(0), e(0), g(0.1f) {
    *(int*)((char*)this + 8) = 1;
}
} // namespace motion
} // namespace hulkfight
} // namespace fn_00147860


// 0x001478b0 hulkfight::motion::CivilianAnimationTrack::vfunc_6 (4 B): matches/0x001478b0.cpp
// sym: ?vfunc_6@CivilianAnimationTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::CivilianAnimationTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001478c0 hulkfight::motion::CivilianAnimationTrack::vfunc_7 (7 B): matches/0x001478c0.cpp
// sym: ?vfunc_7@CivilianAnimationTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::CivilianAnimationTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f1739f6f {

// 0x001478d0 FUN_001478d0 (25 B): matches/0x001478d0.cpp
// sym: ?Run@CivilianAnimationTrack_1478d0@fn_f1739f6f@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void CivilianAnimationTrack_1478d0::Run() {
    vptr = &hulk_at_00413768;
    ((Tail_1478d0*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}

} // namespace fn_f1739f6f

// 0x00147930 hulkfight::motion::GrappleAttachJointCondition::vfunc_6 (190 B): equivalent/0x00147930.cpp [wrapped: conflict: FUN_00344e74; hulkfight::motion::GrappleAttachJointCondition]
// sym: ?vfunc_6@GrappleAttachJointCondition@motion@hulkfight@fn_00147930@@UAE_NPAXPAUInput_147930@4@0@Z @45fd26a1b5f4 @w0089db148ae1
namespace fn_00147930 {
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 22/22)
// hulkfight::motion::GrappleAttachJointCondition::vfunc_6 @ 0x00147930
extern "C" { extern char DAT_00494b44; extern char DAT_00494b60; extern "C++" { __declspec(nothrow) void* __cdecl FUN_00344e74(void*, int, void*, void*, int); } }
struct Pair_147930 { unsigned first, second; };
struct Table_147930 { char pad[0x24]; Pair_147930* entries; };
struct Link_147930 { char pad[8]; Table_147930* table; };
struct Actor_147930 { char pad[0x120]; Link_147930* link; char pad2[0x210]; Actor_147930* previous; Actor_147930* attached; unsigned index; };
struct Context { Actor_147930* FUN_00059a30(); };
struct Input_147930 { Context* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct GrappleAttachJointCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Input_147930*, void*);
 char pad[8]; unsigned mode; unsigned first, second;
};
bool GrappleAttachJointCondition::vfunc_6(void*, Input_147930* input, void*) {
 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Actor_147930* actor = input->FUN_000592a0()->FUN_00059a30();
 Table_147930* table; unsigned index;
 if (actor->attached) { index=actor->index; table=actor->attached->link->table; }
 else { if (!actor->previous) return false; index=actor->previous->index; table=actor->link->table; }
 if (index==0xffff || !table) return false;
 Pair_147930 pair=table->entries[index];
 if (mode==0) return first==pair.first && second==pair.second;
 if (mode==1) return first!=pair.first || second!=pair.second;
 return false;
}
} }
} // namespace fn_00147930


// 0x001479f0 hulkfight::motion::GrappleAttachedCondition::vfunc_6 (84 B): matches/0x001479f0.cpp
// sym: ?vfunc_6@GrappleAttachedCondition@motion@hulkfight@@UAE_NPAX00@Z
bool hulkfight::motion::GrappleAttachedCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * p2 = (void *)__p1;

    if (!((int)(hulk_uintptr)__RTDynamicCast(p2, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0)))
        return false;
    void* a = ((void *)((owners::Object_592a0 *)(((Helper_1479f0*)p2)))->FUN_000592a0());
    void* b = ((Helper_1479f0*)a)->getB_00059a30();
    int x = *(int*)((char*)b + 0x334);
    bool t = (x != 0);
    return this->f_0c == t;
}

namespace fn_f1739f6f {

// 0x00147a50 hulkfight::motion::CivilianAttachedCondition::vfunc_6 (85 B): matches/0x00147a50.cpp
// sym: ?vfunc_6@CivilianAttachedCondition@fn_f1739f6f@@UAE_NPAX00@Z
bool CivilianAttachedCondition::vfunc_6(void* a, void* b, void* c) {
    if (!((int)(hulk_uintptr)__RTDynamicCast(b, 0, &kDesc1, &kDesc2, 0)))
        return false;
    P_147a50* p = ((P_147a50 *)((owners::Object_592a0 *)(((P_147a50*)b)))->FUN_000592a0());
    p = p->FnB_00059a30();
    int x = ((int)((owners::Thing_36020 *)p)->FUN_00036020());
    bool r = (x != 0);
    return r == flag;
}


// 0x00147ab0 hulkfight::motion::CivilianTargetCondition::vfunc_6 (85 B): matches/0x00147ab0.cpp
// sym: ?vfunc_6@CivilianTargetCondition_147ab0@fn_f1739f6f@@UAE_NPAX00@Z
// Same code shape as 0x00147a50 (propagated; names are from that function)
bool CivilianTargetCondition_147ab0::vfunc_6(void* a, void* b, void* c) {
    if (!((int)(hulk_uintptr)__RTDynamicCast(b, 0, &kDesc1, &kDesc2, 0)))
        return false;
    P_147ab0* p = ((P_147ab0 *)((owners::Object_592a0 *)(((P_147ab0*)b)))->FUN_000592a0());
    p = p->FnB_00059a30();
    int x = ((int)((owners::C_36030 *)p)->FUN_00036030());
    bool r = (x != 0);
    return r == flag;
}

} // namespace fn_f1739f6f

// 0x00147b10 hulkfight::motion::GrappleExecuteTrack::vfunc_8 (16 B): matches/0x00147b10.cpp [wrapped: conflict: fight::Param; fight::Track; hulkfight::motion::GrappleExecuteTrack]
// sym: ?vfunc_8@GrappleExecuteTrack@motion@hulkfight@fn_00147b10@@UAEHHH@Z
namespace fn_00147b10 {
namespace fight {
class Track {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};
class Param {};
} // namespace fight
namespace hulkfight {
namespace motion {
class GrappleExecuteTrack : public fight::Track, public fight::Param {
  public:
    virtual int vfunc_8(int, int);
};
} // namespace motion
} // namespace hulkfight
int execute_0005a3f0(int);
int hulkfight::motion::GrappleExecuteTrack::vfunc_8(int a, int b) {
    return execute_0005a3f0(b);
}
} // namespace fn_00147b10


// 0x00147b20 hulkfight::motion::GrappleExecuteTrack::vfunc_10 (82 B): matches/0x00147b20.cpp [wrapped: conflict: GrappleExecuteTrack]
// sym: ?vfunc_10@GrappleExecuteTrack@fn_00147b20@@QAEHHHH@Z
namespace fn_00147b20 {
int __cdecl findThing_0005a470(int);
void* __cdecl allocThing_0008d690(int);
class ExecuteAction_147b20 {
  public:
    int init_002397c0(int, void*, int, int, void*, int, int);
};
class GrappleExecuteTrack {
    char p0[0x14];
    int a;
    char p18[8];
    int b;
    int c;

  public:
    int vfunc_10(int x, int y, int z);
};
int GrappleExecuteTrack::vfunc_10(int x, int y, int z) {
    int v = findThing_0005a470(z);
    if (v) {
        ExecuteAction_147b20* p = (ExecuteAction_147b20*)allocThing_0008d690(0x68);
        if (p) {
            int bb = b;
            int aa = a;
            return p->init_002397c0(x, this, aa, bb, &c, y, v);
        }
    }
    return 0;
}
} // namespace fn_00147b20


// 0x00147b80 hulkfight::motion::GrappleStruggleAction::vfunc_3 (40 B): matches/0x00147b80.cpp
// sym: ?vfunc_3@GrappleStruggleAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::GrappleStruggleAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    HelperA_147b80* a = *(HelperA_147b80**)((char*)this + 0x20);
    HelperA_147b80* b = ((HelperA_147b80 *)((owners::Object_592a0 *)a)->FUN_000592a0());
    Result_147b80* r = ((HelperB_147b80*)b)->Fng_00059a30();
    r->flag = 1;
    r->value = 0.5f;
    return true;
}

namespace fn_f1739f6f {

// 0x00147bb0 hulkfight::motion::GrappleStruggleAction::vfunc_5 (313 B): equivalent/0x00147bb0.cpp
// sym: ?run@GrappleStruggleAction@fn_f1739f6f@@QAE_NHM@Z @9a6aeb9dc8bb @we1c61b96848f
// STATUS: equivalent (tools/equiv.py level 3: 117 inputs, branch coverage 26/28, incomplete)
// hulkfight::motion::GrappleStruggleAction::vfunc_5 @ 0x00147bb0
bool GrappleStruggleAction::run(int mode, float dt)
{
    Source_147bb0* s = ((Node *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();

    if (mode == 1) {
        if (s->a334 != 0) {
            Source_147bb0* from = s->b338;
            if (from == 0)
                from = s->a334;
            s->value = from->value;
            s->valueSet = 1;
        }
        if (s->b338 == 0)
            return true;
    } else if (mode == 0) {
        if (s->b338 != 0) {
            s->value = s->b338->value;
            s->valueSet = 1;
        }
        if (s->a334 == 0)
            return true;
    } else {
        return true;
    }

    float base = s->value;
    float r = ((cfg->f1c - cfg->f18) * base + cfg->f18) * dt;
    elapsed = dt + elapsed;
    if (s->limitIndex >= 0) {
        float lim = cfg->f14;
        if (lim - cfg->v6() < elapsed) {
            int flag = 0;
            if (s->flagA == 1 || s->flagB == 1)
                flag = 1;
            r = flag * cfg->f20 * dt + r;
        }
    }
    s->valueSet = 1;
    s->value = r + base;
    return true;
}

} // namespace fn_f1739f6f

// 0x00147cf0 hulkfight::motion::GrappleStruggleAction::vfunc_4 (26 B): matches/0x00147cf0.cpp
// sym: ?vfunc_4@GrappleStruggleAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::GrappleStruggleAction::vfunc_4() {
    B_147cf0* p = ((B_147cf0 *)((owners::Object_592a0 *)((*(B_147cf0 * *)&this->f_20)))->FUN_000592a0());
    B_147cf0* q = p->second_00059a30();
    *(int*)((char*)q + 0x1e58) = 0;
}


// 0x00147d10 hulkfight::motion::GrappleHitReactionTrack::vfunc_8 (16 B): matches/0x00147d10.cpp [wrapped: conflict: fight::Param; fight::Track; hulkfight::motion::GrappleHitReactionTrack]
// sym: ?vfunc_8@GrappleHitReactionTrack@motion@hulkfight@fn_00147d10@@UAEHHH@Z
namespace fn_00147d10 {
namespace fight {
class Track {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual int f8(int, int);
};
class Param {};
} // namespace fight
extern "C++" __declspec(nothrow) int __cdecl helper_0005a3f0(hulk_intptr);
namespace hulkfight {
namespace motion {
class GrappleHitReactionTrack : public fight::Track, public fight::Param {
  public:
    virtual int vfunc_8(int a, int b);
};
int GrappleHitReactionTrack::vfunc_8(int a, int b) {
    return helper_0005a3f0(b);
}
} // namespace motion
} // namespace hulkfight
} // namespace fn_00147d10


// 0x00147d20 hulkfight::motion::GrappleHitReactionAction::vfunc_4 (8 B): matches/0x00147d20.cpp
// sym: ?vfunc_4@GrappleHitReactionAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::GrappleHitReactionAction::vfunc_4() {
    ((Base_147d20*)((char*)this + 0x24))->run_00232240();
}


// 0x00147d30 hulkfight::motion::GrappleThrowTrack::vfunc_8 (16 B): matches/0x00147d30.cpp [wrapped: conflict: fight::Param; fight::Track; hulkfight::motion::GrappleThrowTrack]
// sym: ?vfunc_8@GrappleThrowTrack@motion@hulkfight@fn_00147d30@@UAEHHH@Z
namespace fn_00147d30 {
namespace fight {
class Track {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual int vfunc_8(int, int);
};
class Param {};
} // namespace fight
namespace hulkfight {
namespace motion {
class GrappleThrowTrack : public fight::Track, public fight::Param {
  public:
    virtual int vfunc_8(int a, int b);
};
} // namespace motion
} // namespace hulkfight
hulk_intptr __cdecl FUN_0005a3f0(hulk_intptr);
int hulkfight::motion::GrappleThrowTrack::vfunc_8(int a, int b) {
    return FUN_0005a3f0(b);
}
} // namespace fn_00147d30

namespace fn_f1739f6f {

// 0x00147d40 hulkfight::motion::GrappleThrowAction::vfunc_5 (82 B): matches/0x00147d40.cpp
// sym: ?vfunc_5@GrappleThrowAction@fn_f1739f6f@@UAEHHH@Z
int GrappleThrowAction::vfunc_5(int x, int y) {
    if (x == 0 && flag == 0)
        ((AnimThing*)((char*)this + 0x24))->FnA_002322f0(count, y);
    flag = 0;
    ((AnimThing*)((char*)this + 0x24))->FnB_00231f20(x);
    if (x == count - 1)
        ((AnimThing*)((char*)this + 0x24))->FnC_002324b0(1);
    return ((AnimThing*)((char*)this + 0x24))->FnD_00231ee0();
}

} // namespace fn_f1739f6f

// 0x00147da0 hulkfight::motion::GrappleThrowAction::vfunc_4 (8 B): matches/0x00147da0.cpp
// sym: ?vfunc_4@GrappleThrowAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00147d20 (propagated; names are from that function)
void hulkfight::motion::GrappleThrowAction::vfunc_4() {
    ((Base_147da0*)((char*)this + 0x24))->run_00232240();
}


// 0x00147db0 hulkfight::motion::CivilianAttachAction::vfunc_3 (158 B): equivalent/0x00147db0.cpp
// sym: ?vfunc_3@CivilianAttachAction@motion@hulkfight@@UAE_NHH@Z @899c00c346a2 @w4a51a88eed98
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 8/8)
// hulkfight::motion::CivilianAttachAction::vfunc_3 @ 0x00147db0
// hulkfight::motion::CivilianAttachAction::vfunc_3 @ 0x00147db0
// equiv-map: ??0Name@@QAE@ABU0@@Z = 0x0027af30
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
bool hulkfight::motion::CivilianAttachAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    Fighter_147db0 *fighter = ((Holder_147db0 *)((owners::Object_592a0 *)((*(Params_147db0 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
    if (fighter == 0)
        return false;
    Target_147db0 *target = ((Target_147db0 *)((owners::C_36030 *)fighter)->FUN_00036030());
    if (target == 0)
        return false;

    fighter->FUN_0003b190(0);
    fighter->FUN_0003b160(target);
    ((owners::C_80cb0 *)target)->FUN_00080cb0(5);

    Msg_147db0 msg;
    msg.FUN_001c9b30(target->name);
    DAT_004dd700->dispatcher->FUN_001cbc20(&msg);

    if (fighter->f20a8 >= 0 && fighter->f328 == target->f100)
        fighter->FUN_000393c0();
    return true;
}


// 0x00147f90 hulkfight::motion::CivilianAnimationAction::vfunc_3 (156 B): equivalent/0x00147f90.cpp
// sym: ?vfunc_3@CivilianAnimationAction@motion@hulkfight@@UAE_NHH@Z @caeb8e1e362f @w1fbf296d5a7c
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// hulkfight::motion::CivilianAnimationAction::vfunc_3 @ 0x00147f90
// hulkfight::motion::CivilianAnimationAction::vfunc_3
bool hulkfight::motion::CivilianAnimationAction::vfunc_3(hulk_intptr unused1, hulk_intptr unused2) {
    Player_147f90 *p = ((Anchor_147f90 *)((owners::Object_592a0 *)((*(Owner_147f90 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
    if (p == 0)
        return (bool)(0);
    Target_147f90 *t = ((Target_147f90 *)((owners::Thing_36020 *)p)->FUN_00036020());
    if (t == 0)
        return (bool)(0);
    Source_147f90 *s = (*(Source_147f90 * *)&this->f_1c);
    Params_147f90 q;
    q.f2c = s->f2c;
    q.flag.b = s->b28;
    q.f24 = s->f24;
    float start = s->f10;
    int a = s->f18;
    int b = s->f1c;
    int c = s->f20;
    t->FUN_000819f0(a, b, c, start - s->v6(), q.f24, q.flag.w, q.f2c);
    return (bool)(1);
}

namespace fn_f1739f6f {

// 0x00148110 hulkfight::motion::GrappleAttachJointCondition::vfunc_5 (46 B): matches/0x00148110.cpp
// sym: ?vfunc_5@GrappleAttachJointCondition_148110@fn_f1739f6f@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
GrappleAttachJointCondition_148110* GrappleAttachJointCondition_148110::vfunc_5(unsigned char param) {
    GrappleAttachJointCondition_148110* p = this;
    *(char**)p = ((char*)DAT_00413578);
    ((Obj_148110*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_148110*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_148110*)p);
    return p;
}


// 0x00148140 hulkfight::motion::GrappleAttachedCondition::vfunc_5 (36 B): matches/0x00148140.cpp
// sym: ?vfunc_5@GrappleAttachedCondition_148140@fn_f1739f6f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
GrappleAttachedCondition_148140* GrappleAttachedCondition_148140::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413598;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00148170 hulkfight::motion::CivilianAttachedCondition::vfunc_5 (36 B): matches/0x00148170.cpp
// sym: ?vfunc_5@CivilianAttachedCondition_148170@fn_f1739f6f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CivilianAttachedCondition_148170* CivilianAttachedCondition_148170::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004135b8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001481a0 hulkfight::motion::CivilianTargetCondition::vfunc_5 (36 B): matches/0x001481a0.cpp
// sym: ?vfunc_5@CivilianTargetCondition_1481a0@fn_f1739f6f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CivilianTargetCondition_1481a0* CivilianTargetCondition_1481a0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004135d8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001481d0 hulkfight::motion::GrappleOrientationCondition::vfunc_5 (36 B): matches/0x001481d0.cpp
// sym: ?vfunc_5@GrappleOrientationCondition_1481d0@fn_f1739f6f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
GrappleOrientationCondition_1481d0* GrappleOrientationCondition_1481d0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004135f8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00148200 hulkfight::motion::CivilianDetachTrack::vfunc_5 (36 B): matches/0x00148200.cpp
// sym: ?vfunc_5@CivilianDetachTrack_148200@fn_f1739f6f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CivilianDetachTrack_148200* CivilianDetachTrack_148200::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413618;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00148230 hulkfight::motion::GrappleThrowTrack::vfunc_5 (36 B): matches/0x00148230.cpp
// sym: ?vfunc_5@GrappleThrowTrack_148230@fn_f1739f6f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
GrappleThrowTrack_148230* GrappleThrowTrack_148230::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413648;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00148260 hulkfight::motion::GrappleStruggleTrack::vfunc_5 (36 B): matches/0x00148260.cpp
// sym: ?vfunc_5@GrappleStruggleTrack_148260@fn_f1739f6f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
GrappleStruggleTrack_148260* GrappleStruggleTrack_148260::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413678;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00148290 hulkfight::motion::CivilianThrowTrack::vfunc_5 (36 B): matches/0x00148290.cpp
// sym: ?vfunc_5@CivilianThrowTrack_148290@fn_f1739f6f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CivilianThrowTrack_148290* CivilianThrowTrack_148290::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004136a8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001482c0 hulkfight::motion::CivilianAttachTrack::vfunc_5 (36 B): matches/0x001482c0.cpp
// sym: ?vfunc_5@CivilianAttachTrack_1482c0@fn_f1739f6f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CivilianAttachTrack_1482c0* CivilianAttachTrack_1482c0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004136d8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001482f0 hulkfight::motion::GrappleHitReactionTrack::vfunc_5 (46 B): matches/0x001482f0.cpp
// sym: ?f2@GrappleHitReactionTrack_1482f0@fn_f1739f6f@@QAEPAV12@E@Z
GrappleHitReactionTrack_1482f0* GrappleHitReactionTrack_1482f0::f2(unsigned char flags) {
    vptr = ((void**)DAT_00413708);

    m.~Mem_1482f0();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00148320 hulkfight::motion::GrappleExecuteTrack::vfunc_5 (54 B): matches/0x00148320.cpp
// sym: ?vfunc_5@GrappleExecuteTrack@fn_f1739f6f@@UAEPAV12@E@Z
GrappleExecuteTrack* GrappleExecuteTrack::vfunc_5(u8_148320 param) {
    Sub_148320* p = (Sub_148320*)((char*)this + 0x24);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00413738);
    initA_00236fd0(p);
    FUN_00234150((char*)this + 0x14);
    initC_00236d60(this);
    if (param & 1)
        destroyThing_0008d330(this);
    return this;
}


// 0x00148360 hulkfight::motion::CivilianAnimationTrack::vfunc_5 (46 B): matches/0x00148360.cpp
// sym: ?f5@CivilianAnimationTrack_148360@fn_f1739f6f@@QAEPAV12@E@Z
CivilianAnimationTrack_148360* CivilianAnimationTrack_148360::f5(unsigned char flags) {
    vptr = (void**)DAT_00413768;
    sub.Fin_0027af50();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f1739f6f

// 0x00148390 hulkfight::motion::GrappleOrientationCondition::vfunc_6 (347 B): equivalent/0x00148390.cpp [wrapped: conflict: CFightParams; fight::Params]
// sym: ?vfunc_6@GrappleOrientationCondition@fn_00148390@@UAEDHPAVParams@fight@2@M@Z @2e610a46edaf @w7612f705e0d1
namespace fn_00148390 {
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 6/6)
// hulkfight::motion::GrappleOrientationCondition::vfunc_6 @ 0x00148390
struct Vec3_148390 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

class Ent_148390 {
public:
    char pad0[0x10];
    Ent_148390 *FUN_00059a30();
    char FUN_00059a50(Vec3_148390 *out);
};

namespace fight {
class Params {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    Ent_148390 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void vfunc_3();
    virtual void vfunc_4();
};

class Actor_148390 {
public:
    char pad0[0x10];
    Ent_148390 *ent;
    hulk_freg FUN_000354c0();
};

extern "C" Actor_148390 *FUN_00048260(fight::Params *p);
hulk_freg FUN_00224f10(Vec3_148390 *v);
hulk_freg FUN_00224fc0(float x, float y);

class GrappleOrientationCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a1, fight::Params *params, float a3);

    char pad04[0xc - 4];
    float f0c;
    float f10;
};

char GrappleOrientationCondition::vfunc_6(int a1, fight::Params *params, float a3)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;
    Ent_148390 *e = params->FUN_000592a0();
    e->FUN_00059a30();
    Actor_148390 *actor = FUN_00048260(params);
    if (actor == 0)
        return 0;
    Vec3_148390 a;
    a.x = 0;
    a.y = 0;
    a.z = 0;
    e->FUN_00059a50(&a);
    Vec3_148390 b;
    b.x = 0;
    b.y = 0;
    b.z = 0;
    actor->ent->FUN_00059a50(&b);
    Vec3_148390 v;
    v.x = a.x;
    v.y = a.y;
    v.z = a.z;
    v.x = v.x - b.x;
    v.y = 0;
    v.z = v.z - b.z;
    v.FUN_0022d110();
    hulk_freg r1 = FUN_00224f10(&v);
    hulk_freg r2 = actor->FUN_000354c0();
    hulk_freg r3 = FUN_00224fc0(r2, r1);
    hulk_freg r4 = FUN_00224fc0(r3, f0c);
    union {
        float f;
        unsigned int u;
    } d;
    d.f = r4;
    d.u &= 0x7fffffff;
    hulk_freg limit = f10 * 0.5f;
    if (limit > d.f)
        return 1;
    return 0;
}
} // namespace fn_00148390

namespace fn_f1739f6f {

// 0x001484f0 FUN_001484f0 (79 B): matches/0x001484f0.cpp
// sym: ??0GrappleStruggleAction_1484f0@fn_f1739f6f@@QAE@HPAURef_1484f0@1@@Z
GrappleStruggleAction_1484f0::GrappleStruggleAction_1484f0(int a, Ref_1484f0* r) {
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


// 0x00148540 FUN_00148540 (50 B): matches/0x00148540.cpp
// sym: ??1GrappleStruggleAction_148540@fn_f1739f6f@@QAE@XZ
GrappleStruggleAction_148540::~GrappleStruggleAction_148540() throw() {
    vptr = (void**)DAT_00413798;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_148540 *)this)->FUN_002326a0();
}


// 0x00148580 FUN_00148580 (422 B): equivalent/0x00148580.cpp
// sym: ?FUN_00148580@fn_f1739f6f@@YA_NPAXPAUEffect_148580@1@PAUParams@1@@Z @011e4e542b03 @w15a3297c4eef
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 24/24)
// FUN_00148580 @ 0x00148580
// equiv-conv: FUN_00148580 ecx esi edi
bool FUN_00148580(void *owner, Effect_148580 *fx, Params *p)
{
    if (owner == 0)
        return false;
    Stats_148580 *s = FUN_00059a30(FUN_000592a0(owner));
    if (s == 0)
        return false;

    Stats_148580 *t = s->target;
    if (t == 0) {
        t = s->altTarget;
        if (t == 0)
            return false;
    }

    RefCounted_148580 *r = t->ref;
    if (r)
        r->vfunc_0();
    if (fx->ref4c)
        fx->ref4c->vfunc_1();
    fx->ref4c = r;

    r = s->ref;
    if (r)
        r->vfunc_0();
    if (fx->ref50)
        fx->ref50->vfunc_1();
    fx->ref50 = r;

    fx->f74 = p->f10;
    fx->f10 = 0;
    fx->fc = 0;
    fx->f8 = 0;

    hulk_freg v = s->FUN_000354c0();   // st0: the heading is added unrounded (both uses)
    if (p->f14 == 0)
        v = t->FUN_000354c0();
    fx->dir = (*(Vec3_148580*)&DAT_004ae358);
    FUN_00224d70(v + p->f18, &fx->dir);

    fx->f0 = p->f20;
    fx->f4 = p->f24;
    fx->f54 = p->f30;
    fx->f24 = p->f34;
    fx->f58 = p->f38i;
    float x = p->f28;
    fx->f78 = x;
    if (x < p->f2c)
        fx->f78 = (p->f2c - x) * t->blend + x;
    fx->f68 = p->f50;

    float w = p->f48;
    if (w < 0.0f)
        w = p->f38;

    v = s->FUN_000354c0();
    if (p->f3c == 0)
        v = t->FUN_000354c0();
    Vec3_148580 dir2 = (*(Vec3_148580*)&DAT_004ae358);
    FUN_00224d70(v + p->f40, &dir2);
    fx->FUN_000595f0(&dir2, p->f44, w, p->f4c);
    return true;
}


// 0x00148840 FUN_00148840 (85 B): matches/0x00148840.cpp
// sym: ??0GrappleHitReactionAction_148840@fn_f1739f6f@@QAE@PAHPAVRef_148840@1@@Z
GrappleHitReactionAction_148840::GrappleHitReactionAction_148840(int* a, Ref_148840* b) : mA(0), mB(0), sub() {
    x = 0;
    y = 0;
    z = 0;
    mA = a;
    if (b)
        b->F();
    if (mB)
        mB->G();
    mB = b;
}


// 0x001488a0 FUN_001488a0 (77 B): matches/0x001488a0.cpp
// sym: ?f@GrappleHitReactionAction_1488a0@fn_f1739f6f@@QAEXXZ
void GrappleHitReactionAction_1488a0::f() {
    vptr = hulk_at_004137b4;
    _ReadWriteBarrier();
    if (m4c) {
        m4c->f1();
        m4c = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    m24.Fn_002325f0();
    ((GrappleThrowAction_nv_1488a0*)(((hulkfight::motion::GrappleThrowAction*)(((hulkfight::motion::GrappleThrowAction*)this)))))->Fn_002326a0();
}

} // namespace fn_f1739f6f

// 0x001488f0 hulkfight::motion::GrappleHitReactionAction::vfunc_3 (219 B): equivalent/0x001488f0.cpp [wrapped: conflict: hulkfight::motion::GrappleHitReactionAction]
// sym: ?vfunc_3@GrappleHitReactionAction@motion@hulkfight@fn_001488f0@@UAE_NHH@Z @c35edcec23ca @wdee1500dbfaf
namespace fn_001488f0 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// hulkfight::motion::GrappleHitReactionAction::vfunc_3 @ 0x001488f0
// hulkfight::motion::GrappleHitReactionAction::vfunc_3 @ 0x001488f0
struct Context;
struct ReactionData { char data[0x78]; int value; char tail[0x1c]; void FUN_00059820(); void FUN_00059300(); };
struct Controller_1488f0 { void FUN_000437a0(int, ReactionData*, void*, int, int); };
struct Intermediate_1488f0 { Controller_1488f0* FUN_00059a30(); };
struct Actor_1488f0 { char pad[12]; int fieldC; Intermediate_1488f0* FUN_000592a0(); };
// equiv-conv: FUN_00148580 ecx esi edi
bool FUN_00148580(Actor_1488f0*, ReactionData*, int);
struct Motion_1488f0 { int first; int second; char pad[0x24]; void FUN_002322f0(int,int); bool FUN_00231ee0(); };
namespace hulkfight { namespace motion {
struct GrappleHitReactionAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
 char pad4[8]; unsigned flags; char pad10[12]; int field1C; Actor_1488f0* actor; Motion_1488f0 motion; int argument; unsigned char active;
};
bool GrappleHitReactionAction::vfunc_3(int a,int b) {
 argument=a;
 Controller_1488f0* controller=actor->FUN_000592a0()->FUN_00059a30();
 if(!controller) return false;
 ReactionData data;
 data.FUN_00059820();
 if(!FUN_00148580(actor, &data, field1C)) { data.FUN_00059300(); return false; }
 controller->FUN_000437a0(data.value,&data,&motion,actor->fieldC,0);
 if(motion.second) flags &= ~3u; else flags=(flags & ~2u)|1u;
 motion.FUN_002322f0(argument,b);
 active=1;
 bool result=motion.FUN_00231ee0();
 data.FUN_00059300();
 return result;
}
}}
} // namespace fn_001488f0

namespace fn_f1739f6f {

// 0x001489d0 hulkfight::motion::GrappleHitReactionAction::vfunc_5 (141 B): matches/0x001489d0.cpp
// sym: ?f@GrappleHitReactionAction@fn_f1739f6f@@UAEHHH@Z
int GrappleHitReactionAction::f(int x, int y) {
    if (!x && !flag)
        sub.Init_002322f0(count, y);
    Obj_1489d0* p = old;
    Obj_1489d0* q = sub.cur;
    flag = 0;
    if (p != q)
        ((owners::C_35cd0 *)(motion->Get_000592a0()->Get_00059a30()))->FUN_00035cd0();
    sub.Set_00231f20(x);
    if (x == count - 1)
        sub.Set2_002324b0(1);
    Obj_1489d0* r = sub.cur;
    if (r)
        r->A();
    if (old)
        old->B();
    old = r;
    return sub.Finish_00231ee0();
}


// 0x00148a60 FUN_00148a60 (82 B): matches/0x00148a60.cpp
// sym: ??0GrappleThrowAction@fn_f1739f6f@@QAE@HPAVRef_148a60@1@@Z
GrappleThrowAction::GrappleThrowAction(int a, Ref_148a60* p) : Action_148a60(), mA(0), mObj(0), sub(), mCount(0), mFlag(0) {
    mA = a;
    if (p)
        p->AddRef();
    if (mObj)
        mObj->Release();
    mObj = p;
}


// 0x00148ac0 FUN_00148ac0 (58 B): matches/0x00148ac0.cpp
// sym: ??1GrappleThrowAction_148ac0@fn_f1739f6f@@QAE@XZ
GrappleThrowAction_148ac0::~GrappleThrowAction_148ac0() throw() {
    vptr = hulk_at_004137d0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    SubFini3_002325f0(&s24);
    ((fight::Action *)(Action_148ac0 *)this)->FUN_002326a0();
}

} // namespace fn_f1739f6f

// 0x00148b00 hulkfight::motion::GrappleThrowAction::vfunc_3 (944 B): equivalent/0x00148b00.cpp [wrapped: conflict: hulkfight::motion::GrappleThrowAction]
// sym: ?vfunc_3@GrappleThrowAction@motion@hulkfight@fn_00148b00@@UAEDHH@Z @aa77f7452877 @wca5284c25332
namespace fn_00148b00 {
// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 24/24)
// hulkfight::motion::GrappleThrowAction::vfunc_3 @ 0x00148b00
struct Vec3_148b00 {
    float x, y, z;
    char FUN_0022d2b0(Vec3_148b00* other, float eps);
    double FUN_0022d110();
};

struct Mat4_148b00 {
    void FUN_0022c3b0(Vec3_148b00* in, Vec3_148b00* out);
};

struct Part_148b00 {
    Mat4_148b00* FUN_00221c40();
};

struct Body_148b00 {
    char pad00[0x10];
    Part_148b00 part;
};

class Ref_148b00 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Entity {
    void FUN_00059a50(Vec3_148b00* out);
    Body_148b00* FUN_00059a40();
};

struct Link_148b00 {
    char pad00[0x14];
    int f14;
};

struct Throwable {
    char pad00[0x10];
    Entity* entity;
    char pad14[0x12c - 0x14];
    Ref_148b00* ref;
    char pad130[0x328 - 0x130];
    Ref_148b00* ref328;
    char pad32c[0x334 - 0x32c];
    int f334;
    float FUN_0003ec00(int mode);
};

struct Owner_148b00 {
    char pad00[0x10];
    Entity* entity;
    char pad14[0x11c - 0x14];
    Link_148b00* link;
    char pad120[0x12c - 0x120];
    Ref_148b00* ref;
    char pad130[0x338 - 0x130];
    Throwable* held;
    void FUN_0003a680(int a1, int a2, int a3, int a4, int a5, int a6, float a7, int a8);
    void FUN_000437a0(int a1, struct Desc_148b00* desc, struct Sub_148b00* sub, int a4, int a5);
};

struct Handle_148b00 {
    Owner_148b00* FUN_00059a30();
};

struct Source_148b00 {
    Handle_148b00* FUN_000592a0();
};

struct Config_148b00 {
    char pad00[0x10];
    Vec3_148b00 target;
    float a0, a1;
    float b0, b1;
    float c0, c1;
    float f34;
    float d0, d1;
};

struct Desc_148b00 {
    int f00, f04, f08, f0c, f10;
    int pad14;
    Vec3_148b00 dir;
    char f24;
    char pad25[3];
    Vec3_148b00 vel;
    char f34;
    char pad35[3];
    char pad38[0x48 - 0x38];
    int id;
    Ref_148b00* ref1;
    Ref_148b00* ref2;
    int pad54;
    int f58;
    int f5c;
    int pad60;
    int f64;
    float f68;
    int pad6c;
    int pad70;
    int f74;
    int pad78;
    float f7c;
    float f80;
    Ref_148b00* ref3;
    float f88;
    float f8c;
    char pad90[8];
    void FUN_00059820();
    void FUN_00059300();
};

struct Sub_148b00 {
    char pad00[4];
    int f04;
    char pad08[0x20 - 8];
    int f20;
    void FUN_002322f0(int a, int b);
    char FUN_00231ee0();
};

void __cdecl FUN_00097a30(float b, float c, float k, Ref_148b00* ref, int z, Vec3_148b00* pos, float p34, Vec3_148b00* dir, int a9, int a10, int a11, int a12);

struct Frame_148b00 {
    union {
        float b;
        Ref_148b00* ref;
    } t;
    float speed;
    Vec3_148b00 dir;
    Vec3_148b00 v2;
    Vec3_148b00 v1;
    Vec3_148b00 v3;
    Desc_148b00 desc;
};

namespace hulkfight {
namespace motion {

class GrappleThrowAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a, int b);

    char pad04[0x1c - 4];
    Config_148b00* config;
    Source_148b00* source;
    Sub_148b00 sub;
    char pad_sub[0x4c - 0x24 - sizeof(Sub_148b00)];
    int saved;
    char flag50;
};

char GrappleThrowAction::vfunc_3(int a, int b)
{
    Frame_148b00 f;
    saved = a;
    Owner_148b00* owner = source->FUN_000592a0()->FUN_00059a30();
    if (!owner)
        return false;
    Throwable* th = owner->held;
    if (!th)
        return false;

    f.v1.x = 0;
    f.v1.y = 0;
    f.v1.z = 0;
    owner->entity->FUN_00059a50(&f.v1);
    f.v2.x = 0;
    f.v2.y = 0;
    f.v2.z = 0;
    f.v3.x = config->target.x;
    f.v3.y = config->target.y;
    f.v3.z = config->target.z;
    if (!f.v3.FUN_0022d2b0(&f.v2, 0.00001f)) {
        Body_148b00* body = th->entity->FUN_00059a40();
        if (body) {
            f.v3.x = config->target.x;
            f.v3.y = config->target.y;
            f.v3.z = config->target.z;
            body->part.FUN_00221c40()->FUN_0022c3b0(&f.v3, &f.dir);
        }
    } else {
        f.v2.x = 0;
        f.v2.y = 0;
        f.v2.z = 0;
        th->entity->FUN_00059a50(&f.v2);
        f.dir.x = f.v1.x - f.v2.x;
        f.dir.y = f.v1.y - f.v2.y;
        f.dir.z = f.v1.z - f.v2.z;
    }
    f.dir.FUN_0022d110();

    Ref_148b00* grabRef = th->ref328;
    if (grabRef == owner->ref)
        grabRef = 0;
    owner->FUN_0003a680(0, -1, 0, 0, 0, 0, 1.0f, 0);
    th->f334 = 0;
    f.desc.FUN_00059820();

    f.t.ref = th->ref;
    if (f.t.ref)
        f.t.ref->AddRef();
    if (f.desc.ref1)
        f.desc.ref1->Release();
    f.desc.ref1 = f.t.ref;

    f.t.ref = owner->ref;
    if (f.t.ref)
        f.t.ref->AddRef();
    if (f.desc.ref2)
        f.desc.ref2->Release();
    f.desc.ref2 = f.t.ref;

    f.desc.dir.x = f.dir.x;
    f.desc.dir.z = f.dir.z;
    f.desc.f00 = f.desc.f04 = f.desc.f08 = f.desc.f0c = f.desc.f10 = 0;
    f.desc.dir.y = f.dir.y;
    f.desc.f24 = 1;
    f.desc.f58 = f.desc.f5c = f.desc.f64 = f.desc.f74 = 0;
    f.desc.f68 = 0;

    f.speed = th->FUN_0003ec00(2);
    f.desc.f34 = 1;
    f.desc.f7c = f.speed;
    f.desc.f80 = 0;
    if (owner->link->f14)
        f.desc.f80 = 1.0f;

    if (grabRef)
        grabRef->AddRef();
    if (f.desc.ref3)
        f.desc.ref3->Release();

    f.desc.ref3 = grabRef;
    f.desc.f88 = (config->a1 - config->a0) * f.speed + config->a0;
    f.t.b = (config->b1 - config->b0) * f.speed + config->b0;
    f.desc.f8c = (config->c1 - config->c0) * f.speed + config->c0;
    f.desc.f68 = (config->d1 - config->d0) * f.speed + config->d0;
    FUN_00097a30(f.t.b, f.desc.f8c, -1.0f, grabRef, 0, &f.v1, config->f34, &f.dir, 0, 0, 0, 1);

    f.desc.vel.x = f.dir.x * f.t.b;
    f.desc.vel.y = f.dir.y * f.t.b;
    f.desc.vel.z = f.dir.z * f.t.b;
    owner->FUN_000437a0(0, &f.desc, &sub, 0, 0);
    sub.FUN_002322f0(saved, b);
    flag50 = 1;
    char result = sub.FUN_00231ee0();
    f.desc.FUN_00059300();
    return result;
}

}
}
} // namespace fn_00148b00

namespace fn_f1739f6f {

// 0x00148eb0 FUN_00148eb0 (72 B): matches/0x00148eb0.cpp
// sym: ??0CivilianThrowAction_148eb0@fn_f1739f6f@@QAE@HPAVRefObj_148eb0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
CivilianThrowAction_148eb0::CivilianThrowAction_148eb0(int target, RefObj_148eb0* obj) {
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


// 0x00148f00 FUN_00148f00 (50 B): matches/0x00148f00.cpp
// sym: ??1CivilianThrowAction_148f00@fn_f1739f6f@@QAE@XZ
CivilianThrowAction_148f00::~CivilianThrowAction_148f00() {
    vptr = hulk_at_004137ec;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_148f00 *)this)->FUN_002326a0();
}


// 0x001492a0 FUN_001492a0 (72 B): matches/0x001492a0.cpp
// sym: ??0CivilianAttachAction_1492a0@fn_f1739f6f@@QAE@HPAVRefObj_1492a0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
CivilianAttachAction_1492a0::CivilianAttachAction_1492a0(int target, RefObj_1492a0* obj) {
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


// 0x001492f0 FUN_001492f0 (50 B): matches/0x001492f0.cpp
// sym: ??1CivilianAttachAction_1492f0@fn_f1739f6f@@QAE@XZ
CivilianAttachAction_1492f0::~CivilianAttachAction_1492f0() {
    vptr = hulk_at_00413808;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1492f0 *)this)->FUN_002326a0();
}


// 0x00149330 FUN_00149330 (72 B): matches/0x00149330.cpp
// sym: ??0CivilianDetachAction_149330@fn_f1739f6f@@QAE@HPAVRefObj_149330@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
CivilianDetachAction_149330::CivilianDetachAction_149330(int target, RefObj_149330* obj) {
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


// 0x00149380 FUN_00149380 (50 B): matches/0x00149380.cpp
// sym: ??1CivilianDetachAction_149380@fn_f1739f6f@@QAE@XZ
CivilianDetachAction_149380::~CivilianDetachAction_149380() {
    vptr = hulk_at_00413824;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_149380 *)this)->FUN_002326a0();
}


// 0x001493c0 FUN_001493c0 (72 B): matches/0x001493c0.cpp
// sym: ??0CivilianAnimationAction_1493c0@fn_f1739f6f@@QAE@HPAVRefObj_1493c0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
CivilianAnimationAction_1493c0::CivilianAnimationAction_1493c0(int target, RefObj_1493c0* obj) {
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


// 0x00149410 FUN_00149410 (50 B): matches/0x00149410.cpp
// sym: ??1CivilianAnimationAction_149410@fn_f1739f6f@@QAE@XZ
CivilianAnimationAction_149410::~CivilianAnimationAction_149410() {
    vptr = hulk_at_00413840;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_149410 *)this)->FUN_002326a0();
}

} // namespace fn_f1739f6f

// 0x00149480 fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_7 (6 B): matches/0x00149480.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00149490 fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_6 (30 B): matches/0x00149490.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_149490 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_149490*)&DAT_003f335c));
}


// 0x001494b0 fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_8 (26 B): matches/0x001494b0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::**)(int))&this->f_18))(b);
}


// 0x001494d0 fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_2 (11 B): matches/0x001494d0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00149500 fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>::vfunc_6 (26 B): matches/0x00149500.cpp
// sym: ?vfunc_6@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>::**)(int))&this->f_10))(b);
}


// 0x00149520 fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>::vfunc_2 (11 B): matches/0x00149520.cpp
// sym: ?vfunc_2@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149550 fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>::vfunc_6 (26 B): matches/0x00149550.cpp
// sym: ?vfunc_6@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>::**)(int))&this->f_10))(b);
}


// 0x00149570 fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>::vfunc_2 (11 B): matches/0x00149570.cpp
// sym: ?vfunc_2@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001495a0 fight::ParamBool<hulkfight::motion::CivilianTargetCondition>::vfunc_6 (26 B): matches/0x001495a0.cpp
// sym: ?vfunc_6@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CivilianTargetCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CivilianTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CivilianTargetCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CivilianTargetCondition>::**)(int))&this->f_10))(b);
}


// 0x001495c0 fight::ParamBool<hulkfight::motion::CivilianTargetCondition>::vfunc_2 (11 B): matches/0x001495c0.cpp
// sym: ?vfunc_2@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CivilianTargetCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001495f0 fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>::vfunc_6 (26 B): matches/0x001495f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>::**)(int))&this->f_10))(b);
}


// 0x00149610 fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>::vfunc_2 (11 B): matches/0x00149610.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149640 fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>::vfunc_6 (26 B): matches/0x00149640.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>::**)(int))&this->f_10))(b);
}


// 0x00149660 fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>::vfunc_2 (11 B): matches/0x00149660.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149690 fight::ParamVector<hulkfight::motion::CivilianDetachTrack>::vfunc_6 (26 B): matches/0x00149690.cpp
// sym: ?vfunc_6@?$ParamVector@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::CivilianDetachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::CivilianDetachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::CivilianDetachTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::CivilianDetachTrack>::**)(int))&this->f_10))(b);
}


// 0x001496b0 fight::ParamVector<hulkfight::motion::CivilianDetachTrack>::vfunc_2 (11 B): matches/0x001496b0.cpp
// sym: ?vfunc_2@?$ParamVector@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::CivilianDetachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001496e0 fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>::vfunc_6 (26 B): matches/0x001496e0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00149700 fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>::vfunc_2 (11 B): matches/0x00149700.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149730 fight::ParamVector<hulkfight::motion::GrappleThrowTrack>::vfunc_6 (26 B): matches/0x00149730.cpp
// sym: ?vfunc_6@?$ParamVector@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::GrappleThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::GrappleThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::GrappleThrowTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::GrappleThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00149750 fight::ParamVector<hulkfight::motion::GrappleThrowTrack>::vfunc_2 (11 B): matches/0x00149750.cpp
// sym: ?vfunc_2@?$ParamVector@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::GrappleThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149780 fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>::vfunc_6 (26 B): matches/0x00149780.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>::**)(int))&this->f_10))(b);
}


// 0x001497a0 fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>::vfunc_2 (11 B): matches/0x001497a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001497d0 fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>::vfunc_6 (26 B): matches/0x001497d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x001497f0 fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>::vfunc_2 (11 B): matches/0x001497f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149820 fight::ParamVector<hulkfight::motion::CivilianThrowTrack>::vfunc_6 (26 B): matches/0x00149820.cpp
// sym: ?vfunc_6@?$ParamVector@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::CivilianThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::CivilianThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::CivilianThrowTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::CivilianThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00149840 fight::ParamVector<hulkfight::motion::CivilianThrowTrack>::vfunc_2 (11 B): matches/0x00149840.cpp
// sym: ?vfunc_2@?$ParamVector@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::CivilianThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149870 fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>::vfunc_6 (26 B): matches/0x00149870.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>::**)(int))&this->f_10))(b);
}


// 0x00149890 fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>::vfunc_2 (11 B): matches/0x00149890.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001498c0 fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_6 (26 B): matches/0x001498c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>::**)(int))&this->f_10))(b);
}


// 0x001498e0 fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_2 (11 B): matches/0x001498e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149920 fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::vfunc_7 (6 B): matches/0x00149920.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00149930 fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::vfunc_6 (30 B): matches/0x00149930.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_149930 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_149930*)&DAT_003f335c));
}


// 0x00149950 fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::vfunc_8 (26 B): matches/0x00149950.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::**)(int))&this->f_18))(b);
}


// 0x00149970 fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::vfunc_2 (11 B): matches/0x00149970.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001499a0 fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_6 (26 B): matches/0x001499a0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>::**)(int))&this->f_10))(b);
}


// 0x001499c0 fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_2 (11 B): matches/0x001499c0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001499f0 fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>::vfunc_6 (26 B): matches/0x001499f0.cpp
// sym: ?vfunc_6@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>::**)(int))&this->f_10))(b);
}


// 0x00149a10 fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>::vfunc_2 (11 B): matches/0x00149a10.cpp
// sym: ?vfunc_2@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149a40 fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_6 (26 B): matches/0x00149a40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::**)(int))&this->f_10))(b);
}


// 0x00149a60 fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_2 (11 B): matches/0x00149a60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f1739f6f {

// 0x00149a90 fight::ParamBranch<hulkfight::motion::GrappleExecuteTrack>::vfunc_6 (12 B): matches/0x00149a90.cpp
// sym: ?vfunc_6@ParamBranch@fn_f1739f6f@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f1739f6f

// 0x00149ac0 fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_6 (26 B): matches/0x00149ac0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>::**)(int))&this->f_10))(b);
}


// 0x00149ae0 fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_2 (11 B): matches/0x00149ae0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149b10 fight::ParamConditionGroup<hulkfight::motion::GrappleExecuteTrack>::vfunc_6 (12 B): matches/0x00149b10.cpp [wrapped: same definition as 0x00149a90 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00149b10@@UAEXPAX@Z
namespace fn_00149b10 {
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
} // namespace fn_00149b10


// 0x00149b40 fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>::vfunc_6 (26 B): matches/0x00149b40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x00149b60 fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>::vfunc_2 (11 B): matches/0x00149b60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149b90 fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>::vfunc_6 (26 B): matches/0x00149b90.cpp
// sym: ?vfunc_6@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x00149bb0 fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>::vfunc_2 (11 B): matches/0x00149bb0.cpp
// sym: ?vfunc_2@?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00149bd0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachJointCondition>::vfunc_0 (36 B): matches/0x00149bd0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachJointCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004aefb8, 0) != 0;
}


// 0x00149c00 fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_0 (30 B): matches/0x00149c00.cpp
// sym: ??_G?$ParamEnumConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149c00)
#endif


// 0x00149c30 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachedCondition>::vfunc_0 (36 B): matches/0x00149c30.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00149c60 fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>::vfunc_0 (30 B): matches/0x00149c60.cpp
// sym: ??_G?$ParamBool@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::GrappleAttachedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149c60)
#endif


// 0x00149c90 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_0 (36 B): matches/0x00149c90.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCivilianAttachedCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004af148, 0) != 0;
}


// 0x00149cc0 fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>::vfunc_0 (30 B): matches/0x00149cc0.cpp
// sym: ??_G?$ParamBool@VCivilianAttachedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149cc0)
#endif


// 0x00149cf0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianTargetCondition>::vfunc_0 (36 B): matches/0x00149cf0.cpp [wrapped: conflict: DAT_00491ca8; fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCivilianTargetCondition@fn_00149cf0@@@fight@fn_00149cf0@@UAE_NPAX@Z
namespace fn_00149cf0 {
class CivilianTargetCondition;
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
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
extern void *DAT_00491ca8, *DAT_004af210;
template <> bool fight::ConditionFactoryCasterTemplate<CivilianTargetCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004af210, 0) != 0;
}
} // namespace fn_00149cf0


// 0x00149d20 fight::ParamBool<hulkfight::motion::CivilianTargetCondition>::vfunc_0 (30 B): matches/0x00149d20.cpp
// sym: ??_G?$ParamBool@VCivilianTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CivilianTargetCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CivilianTargetCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149d20)
#endif


// 0x00149d50 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleOrientationCondition>::vfunc_0 (36 B): matches/0x00149d50.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleOrientationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &a, &hulk_at_004af2d8, 0) != 0;
}


// 0x00149d80 fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>::vfunc_0 (30 B): matches/0x00149d80.cpp
// sym: ??_G?$ParamFloatConstRange@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::GrappleOrientationCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149d80)
#endif


// 0x00149db0 fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianDetachTrack>::vfunc_0 (36 B): matches/0x00149db0.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate; hulkfight::motion::CivilianDetachTrack]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCivilianDetachTrack@motion@hulkfight@fn_00149db0@@@fight@fn_00149db0@@UAE_NPBD@Z
namespace fn_00149db0 {
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
namespace fight {
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CivilianDetachTrack {};
} // namespace motion
} // namespace hulkfight
extern const void* DAT_0049850c;
extern const void* DAT_004af398;
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianDetachTrack>::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004af398, 0) != 0;
}
} // namespace fn_00149db0


// 0x00149de0 fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>::vfunc_0 (30 B): matches/0x00149de0.cpp
// sym: ??_G?$ParamFloatConstRange@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149de0)
#endif


// 0x00149e00 fight::ParamVector<hulkfight::motion::CivilianDetachTrack>::vfunc_0 (30 B): matches/0x00149e00.cpp
// sym: ??_G?$ParamVector@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::CivilianDetachTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::CivilianDetachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149e00)
#endif


// 0x00149e30 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleThrowTrack>::vfunc_0 (36 B): matches/0x00149e30.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGrappleThrowTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af448, 0) != 0;
}


// 0x00149e60 fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>::vfunc_0 (30 B): matches/0x00149e60.cpp
// sym: ??_G?$ParamFloatConstRange@VGrappleThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::GrappleThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149e60)
#endif


// 0x00149e80 fight::ParamVector<hulkfight::motion::GrappleThrowTrack>::vfunc_0 (30 B): matches/0x00149e80.cpp
// sym: ??_G?$ParamVector@VGrappleThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::GrappleThrowTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::GrappleThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149e80)
#endif


// 0x00149eb0 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleStruggleTrack>::vfunc_0 (36 B): matches/0x00149eb0.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate; hulkfight::motion::GrappleStruggleTrack]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGrappleStruggleTrack@motion@hulkfight@fn_00149eb0@@@fight@fn_00149eb0@@UAE_NPAX@Z
namespace fn_00149eb0 {
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
class GrappleStruggleTrack {};
} // namespace motion
} // namespace hulkfight
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c[], DAT_004af500[];
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleStruggleTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, DAT_0049850c, DAT_004af500, 0) != 0;
}
} // namespace fn_00149eb0


// 0x00149ee0 fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>::vfunc_0 (30 B): matches/0x00149ee0.cpp
// sym: ??_G?$ParamFloatConstRange@VGrappleStruggleTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::GrappleStruggleTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149ee0)
#endif


// 0x00149f10 fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianThrowTrack>::vfunc_0 (36 B): matches/0x00149f10.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCivilianThrowTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af5b0, 0) != 0;
}


// 0x00149f40 fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>::vfunc_0 (30 B): matches/0x00149f40.cpp
// sym: ??_G?$ParamFloatConstRange@VCivilianThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::CivilianThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149f40)
#endif


// 0x00149f60 fight::ParamVector<hulkfight::motion::CivilianThrowTrack>::vfunc_0 (30 B): matches/0x00149f60.cpp
// sym: ??_G?$ParamVector@VCivilianThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::CivilianThrowTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::CivilianThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149f60)
#endif


// 0x00149f90 fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_0 (36 B): matches/0x00149f90.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate; hulkfight::motion::CivilianAttachTrack]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCivilianAttachTrack@motion@hulkfight@fn_00149f90@@@fight@fn_00149f90@@UAEHPAX@Z
namespace fn_00149f90 {
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* DAT_0049850c;
extern void* DAT_004af668;
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
class CivilianAttachTrack {};
} // namespace motion
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af668, 0) != 0;
}
template class fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAttachTrack>;
} // namespace fn_00149f90


// 0x00149fc0 fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>::vfunc_0 (30 B): matches/0x00149fc0.cpp
// sym: ??_G?$ParamFloatConstRange@VCivilianAttachTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::CivilianAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x149fc0)
#endif


// 0x00149ff0 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleHitReactionTrack>::vfunc_0 (36 B): matches/0x00149ff0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleHitReactionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af720, 0) != 0;
}


// 0x0014a020 fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_0 (30 B): matches/0x0014a020.cpp
// sym: ??_G?$ParamFloatConstRange@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a020)
#endif


// 0x0014a040 fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::vfunc_0 (30 B): matches/0x0014a040.cpp
// sym: ??_G?$ParamEnumConstList@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a040)
#endif


// 0x0014a060 fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>::vfunc_0 (30 B): matches/0x0014a060.cpp
// sym: ??_G?$ParamIntConstRange@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a060)
#endif


// 0x0014a080 fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>::vfunc_0 (30 B): matches/0x0014a080.cpp
// sym: ??_G?$ParamBool@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a080)
#endif


// 0x0014a0b0 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleExecuteTrack>::vfunc_0 (36 B): matches/0x0014a0b0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGrappleExecuteTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleExecuteTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af7d8, 0) != 0;
}


// 0x0014a0e0 fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_0 (30 B): matches/0x0014a0e0.cpp
// sym: ??_G?$ParamFloatConstRange@VGrappleExecuteTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a0e0)
#endif


// 0x0014a100 fight::ParamBranch<hulkfight::motion::GrappleExecuteTrack>::vfunc_0 (30 B): matches/0x0014a100.cpp
// sym: ??_G?$ParamBranch@VGrappleExecuteTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<hulkfight::motion::GrappleExecuteTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<hulkfight::motion::GrappleExecuteTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a100)
#endif


// 0x0014a120 fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_0 (30 B): matches/0x0014a120.cpp
// sym: ??_G?$ParamIntConstRange@VGrappleExecuteTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::GrappleExecuteTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a120)
#endif


// 0x0014a140 fight::ParamConditionGroup<hulkfight::motion::GrappleExecuteTrack>::vfunc_0 (30 B): matches/0x0014a140.cpp
// sym: ??_G?$ParamConditionGroup@VGrappleExecuteTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<hulkfight::motion::GrappleExecuteTrack>::~ParamConditionGroup() {}
#if defined(HULK_PTR64)
template class fight::ParamConditionGroup<hulkfight::motion::GrappleExecuteTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a140)
#endif


// 0x0014a170 fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAnimationTrack>::vfunc_0 (36 B): matches/0x0014a170.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCivilianAnimationTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAnimationTrack>::vfunc_0(void* __p0) { Track_14a170 * p = (Track_14a170 *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af890, 0) != 0;
}


// 0x0014a1a0 fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>::vfunc_0 (30 B): matches/0x0014a1a0.cpp
// sym: ??_G?$ParamFloatConstRange@VCivilianAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a1a0)
#endif


// 0x0014a1c0 fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>::vfunc_0 (30 B): matches/0x0014a1c0.cpp
// sym: ??_G?$ParamBool@VCivilianAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::CivilianAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14a1c0)
#endif


// 0x0014a3a0 FUN_0014a3a0 (213 B): equivalent/0x0014a3a0.cpp [wrapped: conflict: fight::ParamFloatConstRange; fight::ParamVector]
// sym: ?FUN_0014a3a0@fn_0014a3a0@@YAXXZ @02f4372c34fc @w22dfc9edec6a
namespace fn_0014a3a0 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_0014a3a0 @ 0x0014a3a0


extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(unsigned int);
extern "C" void FUN_00146990();
extern "C" void FUN_001469c0();
extern "C" void FUN_00146a00();
struct FUN_00234960 { FUN_00234960(const char*); virtual void slot0(); char pad[12]; void (*callback)(); int tail; };
struct FUN_00234e50 { FUN_00234e50(const char*); virtual void slot0(); char pad[12]; void (*callback)(); int tail; };
namespace hulkfight { namespace motion { class CivilianDetachTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange : FUN_00234960 { ParamFloatConstRange(const char* s):FUN_00234960(s) {} virtual void slot0(); };
template<class T> struct ParamVector : FUN_00234e50 { ParamVector(const char* s):FUN_00234e50(s) {} virtual void slot0(); };
}
extern "C" void __cdecl FUN_002347b0(void*, void**, int);
void FUN_0014a3a0() {
 if (!DAT_004e0fe8) {
 void* items[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack> FloatParam;
 typedef fight::ParamVector<hulkfight::motion::CivilianDetachTrack> VectorParam;
 FloatParam* a = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(a) { a = new(a) FloatParam("timeBegin"); a->callback = FUN_00146990; }
 items[0]=a;
 VectorParam* b=(VectorParam*)FUN_0008d690((int)sizeof(VectorParam));
 if(b) { b = new(b) VectorParam("offset"); b->callback=FUN_001469c0; }
 items[1]=b;
 VectorParam* c=(VectorParam*)FUN_0008d690((int)sizeof(VectorParam));
 if(c) { c = new(c) VectorParam("orient"); c->callback=FUN_00146a00; }
 items[2]=c;
 FUN_002347b0(&DAT_004e0fe4,items,3);
 }
 ++DAT_004e0fe8;
}
} // namespace fn_0014a3a0


// 0x0014ac70 hulkfight::motion::GrappleStruggleTrack::vfunc_10 (70 B): matches/0x0014ac70.cpp
// sym: ?vfunc_10@GrappleStruggleTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleStruggleTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_14ac70 a = (u32_14ac70)__p0; u32_14ac70 b = (u32_14ac70)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&TypeA_14ac70), (void*)(&TypeB_14ac70), 0))) {
        Result_14ac70* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(q->Init_001484f0(this, p));
    }
    return (int)(0);
}

namespace fn_f1739f6f {

// 0x0014acc0 hulkfight::motion::GrappleStruggleAction::vfunc_2 (71 B): matches/0x0014acc0.cpp
// sym: ?vfunc_2@GrappleStruggleAction_14acc0@fn_f1739f6f@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
GrappleStruggleAction_14acc0* GrappleStruggleAction_14acc0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00413798;
    RefCounted_14acc0* q = *(RefCounted_14acc0* volatile*)&m_20;
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

} // namespace fn_f1739f6f

// 0x0014ad10 hulkfight::motion::GrappleHitReactionTrack::vfunc_10 (58 B): matches/0x0014ad10.cpp
// sym: ?vfunc_10@GrappleHitReactionTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::GrappleHitReactionTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int x = GetParam_0005a470(c);
    if (x) {
        GrappleHitReactionAction_14ad10* p = Allocate_0008d690(0x58);
        if (p)
            return p->Init_00148840(this, x);
    }
    return 0;
}


// 0x0014ad50 hulkfight::motion::GrappleHitReactionAction::vfunc_2 (30 B): matches/0x0014ad50.cpp
// sym: ??_GGrappleHitReactionAction@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::GrappleHitReactionAction::~GrappleHitReactionAction() {}

namespace fn_f1739f6f {

// 0x0014adb0 hulkfight::motion::GrappleThrowAction::vfunc_2 (79 B): matches/0x0014adb0.cpp
// sym: ?f2@GrappleThrowAction_14adb0@fn_f1739f6f@@QAEPAV12@E@Z
GrappleThrowAction_14adb0* GrappleThrowAction_14adb0::f2(unsigned char flags) {
    vptr = ((void**)DAT_004137d0);
    _ReadWriteBarrier();
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    m24.Fn_002325f0();
    ((GrappleThrowAction_nv_14adb0*)(((hulkfight::motion::GrappleThrowAction*)this)))->Fn_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x0014ae50 hulkfight::motion::CivilianThrowAction::vfunc_2 (71 B): matches/0x0014ae50.cpp
// sym: ?vfunc_2@CivilianThrowAction_14ae50@fn_f1739f6f@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
CivilianThrowAction_14ae50* CivilianThrowAction_14ae50::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_14ae50;
    RefCounted_14ae50* q = *(RefCounted_14ae50* volatile*)&m_20;
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


// 0x0014aef0 hulkfight::motion::CivilianAttachAction::vfunc_2 (71 B): matches/0x0014aef0.cpp
// sym: ?vfunc_2@CivilianAttachAction_14aef0@fn_f1739f6f@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
CivilianAttachAction_14aef0* CivilianAttachAction_14aef0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_14aef0;
    RefCounted_14aef0* q = *(RefCounted_14aef0* volatile*)&m_20;
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


// 0x0014af90 hulkfight::motion::CivilianDetachAction::vfunc_2 (71 B): matches/0x0014af90.cpp
// sym: ?vfunc_2@CivilianDetachAction_14af90@fn_f1739f6f@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
CivilianDetachAction_14af90* CivilianDetachAction_14af90::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_14af90;
    RefCounted_14af90* q = *(RefCounted_14af90* volatile*)&m_20;
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


// 0x0014b030 hulkfight::motion::CivilianAnimationAction::vfunc_2 (71 B): matches/0x0014b030.cpp
// sym: ?vfunc_2@CivilianAnimationAction_14b030@fn_f1739f6f@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
CivilianAnimationAction_14b030* CivilianAnimationAction_14b030::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_14b030;
    RefCounted_14b030* q = *(RefCounted_14b030* volatile*)&m_20;
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

} // namespace fn_f1739f6f

// 0x0014b0c0 fight::ParamNameConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_7 (12 B): matches/0x0014b0c0.cpp [wrapped: same definition as 0x00149a90 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0014b0c0@@UAEXPAX@Z
namespace fn_0014b0c0 {
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
} // namespace fn_0014b0c0


// 0x0014b230 fight::ParamName<hulkfight::motion::GrappleHitReactionTrack>::vfunc_7 (12 B): matches/0x0014b230.cpp [wrapped: same definition as 0x00149a90 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0014b230@@UAEXPAX@Z
namespace fn_0014b230 {
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
} // namespace fn_0014b230


// 0x0014b2a0 fight::ParamName<hulkfight::motion::CivilianAnimationTrack>::vfunc_7 (12 B): matches/0x0014b2a0.cpp [wrapped: same definition as 0x00149a90 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0014b2a0@@UAEXPAX@Z
namespace fn_0014b2a0 {
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
} // namespace fn_0014b2a0


// 0x0014b2b0 fight::ParamNameConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_0 (30 B): matches/0x0014b2b0.cpp
// sym: ??_G?$ParamNameConstList@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::GrappleAttachJointCondition>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::GrappleAttachJointCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14b2b0)
#endif


// 0x0014b2d0 fight::ParamName<hulkfight::motion::GrappleHitReactionTrack>::vfunc_0 (30 B): matches/0x0014b2d0.cpp
// sym: ??_G?$ParamName@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::GrappleHitReactionTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::GrappleHitReactionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14b2d0)
#endif


// 0x0014b2f0 fight::ParamName<hulkfight::motion::CivilianAnimationTrack>::vfunc_0 (30 B): matches/0x0014b2f0.cpp
// sym: ??_G?$ParamName@VCivilianAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::CivilianAnimationTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::CivilianAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x14b2f0)
#endif

namespace fn_f1739f6f {

// 0x0014b3f0 FUN_0014b3f0 (38 B): matches/0x0014b3f0.cpp
// sym: ?FUN_0014b3f0@fn_f1739f6f@@YAXPAVTarget@1@PAX@Z
void FUN_0014b3f0(Target* target, void* arg) {
    ConditionFactoryCasterTemplate_14b3f0 caster;
    void* result = FUN_002343e0(arg, &caster);
    target->Apply_00236760(result);
}


// 0x0014b4b0 FUN_0014b4b0 (38 B): matches/0x0014b4b0.cpp
// sym: _FUN_0014b4b0
extern "C" void FUN_0014b4b0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_14b4b0 caster;
    void* p = FUN_00236ac0(name, &caster);
    owner->Set_002367c0(p);
}


// 0x0014b4e0 FUN_0014b4e0 (38 B): matches/0x0014b4e0.cpp
// sym: _FUN_0014b4e0
extern "C" void FUN_0014b4e0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_14b4e0 caster;
    void* p = FUN_00236ac0(name, &caster);
    owner->Add_002367c0(p);
}


// 0x0014b510 FUN_0014b510 (38 B): matches/0x0014b510.cpp
// sym: _FUN_0014b510
extern "C" void* FUN_0014b510(Factory* factory, const char* name) {
    TrackFactoryCasterTemplate_14b510 caster;
    return factory->Create_002367c0(FUN_00236ac0(name, &caster));
}


// 0x0014b540 FUN_0014b540 (38 B): matches/0x0014b540.cpp
// sym: _FUN_0014b540
extern "C" void __cdecl FUN_0014b540(Owner* o, const char* name) {
    TrackFactoryCasterTemplate_14b540 c;
    o->set_002367c0(findTrack_00236ac0(name, &c));
}


// 0x0014b570 FUN_0014b570 (38 B): matches/0x0014b570.cpp
// sym: _FUN_0014b570
extern "C" void FUN_0014b570(Obj* o, void* p) {
    TrackFactoryCasterTemplate_14b570 c;
    o->apply_002367c0(find_00236ac0(p, &c));
}


// 0x0014b5a0 FUN_0014b5a0 (38 B): matches/0x0014b5a0.cpp
// sym: _FUN_0014b5a0
extern "C" int __cdecl FUN_0014b5a0(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_14b5a0 caster;
    return obj->Get_002367c0(FUN_00236ac0(name, &caster));
}


// 0x0014b960 FUN_0014b960 (38 B): matches/0x0014b960.cpp
// sym: _FUN_0014b960
extern "C" void FUN_0014b960(Factory* factory, void* name) {
    TrackFactoryCasterTemplate_14b960 caster;
    Track* track = FUN_00236ac0(name, &caster);
    factory->Add_002367c0(track);
}


// 0x0014b990 FUN_0014b990 (38 B): matches/0x0014b990.cpp
// sym: _FUN_0014b990
extern "C" void FUN_0014b990(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_14b990 c;
    obj->Set_002367c0(FUN_00236ac0(name, &c));
}

} // namespace fn_f1739f6f

// 0x0014bb60 FUN_0014bb60 (179 B): equivalent/0x0014bb60.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_0014bb60 @398b27c4a929 @w59174f0463a2
namespace fn_0014bb60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0014bb60 @ 0x0014bb60
namespace hulkfight { namespace motion { class GrappleAttachJointCondition; class GrappleAttachedCondition; class CivilianAttachedCondition; class CivilianTargetCondition; class GrappleOrientationCondition; } }
namespace fight {
template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); };
}
extern void* __cdecl FUN_002343e0(const char*, void*);
struct Registry_14bb60 { void FUN_00236760(void*); };
extern "C" void __cdecl FUN_0014bb60(Registry_14bb60* registry) {
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleOrientationCondition> orientation;
 registry->FUN_00236760(FUN_002343e0("grappleOrientation", &orientation));
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachJointCondition> joint;
 registry->FUN_00236760(FUN_002343e0("grappleAttachJoint", &joint));
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachedCondition> attached;
 registry->FUN_00236760(FUN_002343e0("grappleAttached", &attached));
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianAttachedCondition> civilian;
 registry->FUN_00236760(FUN_002343e0("civilianAttached", &civilian));
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianTargetCondition> target;
 registry->FUN_00236760(FUN_002343e0("civilianTarget", &target));
}
} // namespace fn_0014bb60


// 0x0014bc20 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachedCondition>::vfunc_1 (60 B): matches/0x0014bc20.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14bc20));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14bc20* t = new (mem) TrackFactoryTemplate_14bc20();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014bc60 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleAttachedCondition>::vfunc_5 (44 B): matches/0x0014bc60.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VGrappleAttachedCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrappleAttachedCondition>::vfunc_5() {
    GrappleAttachedCondition_14bc60* p = (GrappleAttachedCondition_14bc60*)alloc_0008d690(16);
    if (p) {
        p->GrappleAttachedCondition_14bc60::GrappleAttachedCondition_14bc60(0);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_00413598);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f1739f6f {

// 0x0014bc90 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleAttachedCondition>::vfunc_2 (43 B): matches/0x0014bc90.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_14bc90@fn_f1739f6f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_14bc90::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413db4;
    base1_dtor_001471e0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1739f6f

// 0x0014bcc0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_1 (60 B): matches/0x0014bcc0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCivilianAttachedCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14bcc0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14bcc0* t = new (mem) TrackFactoryTemplate_14bcc0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014bd00 fight::ConditionFactoryTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_5 (44 B): matches/0x0014bd00.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCivilianAttachedCondition@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace hulkfight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::CivilianAttachedCondition_14bd00(0));
}

namespace fn_f1739f6f {

// 0x0014bd30 fight::ConditionFactoryTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_2 (43 B): matches/0x0014bd30.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_14bd30@fn_f1739f6f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_14bd30::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413dd0;
    base1_dtor_00147240();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1739f6f

// 0x0014bd60 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianTargetCondition>::vfunc_1 (60 B): matches/0x0014bd60.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCivilianTargetCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianTargetCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14bd60));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14bd60* t = new (mem) TrackFactoryTemplate_14bd60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014bda0 fight::ConditionFactoryTemplate<hulkfight::motion::CivilianTargetCondition>::vfunc_5 (44 B): matches/0x0014bda0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCivilianTargetCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CivilianTargetCondition>::vfunc_5() {
    CivilianTargetCondition_14bda0* p = (CivilianTargetCondition_14bda0*)Allocate_0008d690(0x10);
    void* r;
    if (p) {
        p->CivilianTargetCondition_14bda0::CivilianTargetCondition_14bda0(0);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_004135d8);
        p->data[8] = 1;
        r = p;
    } else
        r = 0;
    return (void*)(r);
}

namespace fn_f1739f6f {

// 0x0014bdd0 fight::ConditionFactoryTemplate<hulkfight::motion::CivilianTargetCondition>::vfunc_2 (43 B): matches/0x0014bdd0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_14bdd0@fn_f1739f6f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_14bdd0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413dec;
    base1_dtor_001472a0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1739f6f

// 0x0014be00 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleOrientationCondition>::vfunc_1 (60 B): matches/0x0014be00.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleOrientationCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14be00));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14be00* t = new (mem) TrackFactoryTemplate_14be00();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014be40 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleOrientationCondition>::vfunc_5 (54 B): matches/0x0014be40.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VGrappleOrientationCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrappleOrientationCondition>::vfunc_5() {
    return (void*)(new GrappleOrientationCondition_14be40);
}

namespace fn_f1739f6f {

// 0x0014be80 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleOrientationCondition>::vfunc_2 (43 B): matches/0x0014be80.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_14be80@fn_f1739f6f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_14be80::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413e08;
    base1_dtor_00147300();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1739f6f

// 0x0014beb0 fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianDetachTrack>::vfunc_1 (60 B): matches/0x0014beb0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianDetachTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14beb0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14beb0* t = new (mem) TrackFactoryTemplate_14beb0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014bef0 fight::TrackFactoryTemplate<hulkfight::motion::CivilianDetachTrack>::vfunc_5 (64 B): matches/0x0014bef0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCivilianDetachTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::CivilianDetachTrack>::vfunc_5() {
    CDTrack* p = (CDTrack*)FUN_0008d690((int)sizeof(CDTrack));
    if (p != 0) {
        p->Init_00236d40();
        *(volatile int*)&p->fc = 0;
        *(volatile hulk_intptr*)&p->f0 = ((hulk_intptr)DAT_00413618);
        *(volatile int*)&p->f10 = 0;
        *(volatile int*)&p->f14 = 0;
        *(volatile int*)&p->f18 = 0;
        *(volatile int*)&p->f1c = 0;
        *(volatile int*)&p->f20 = 0;
        *(volatile int*)&p->f24 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f1739f6f {

// 0x0014bf30 fight::TrackFactoryTemplate<hulkfight::motion::CivilianDetachTrack>::vfunc_2 (43 B): matches/0x0014bf30.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f1739f6f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413e24;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1739f6f

// 0x0014bf60 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleThrowTrack>::vfunc_1 (60 B): matches/0x0014bf60.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VGrappleThrowTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleThrowTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14bf60));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14bf60* t = new (mem) TrackFactoryTemplate_14bf60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014bfa0 fight::TrackFactoryTemplate<hulkfight::motion::GrappleThrowTrack>::vfunc_5 (24 B): matches/0x0014bfa0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VGrappleThrowTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fa30 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleThrowTrack>::vfunc_5() {
    Grapple_14bfa0* p = (Grapple_14bfa0*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack_00147430());
    return (void*)(0);
}


// 0x0014bfc0 fight::TrackFactoryTemplate<hulkfight::motion::GrappleThrowTrack>::vfunc_2 (43 B): matches/0x0014bfc0.cpp [wrapped: same definition as 0x0014bf30 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0014bfc0@@QAEPAXE@Z
namespace fn_0014bfc0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00413e40;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00147400();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413e40;
    base1_dtor_00147400();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0014bfc0


// 0x0014bff0 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleStruggleTrack>::vfunc_1 (60 B): matches/0x0014bff0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VGrappleStruggleTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleStruggleTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14bff0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14bff0* t = new (mem) TrackFactoryTemplate_14bff0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014c030 fight::TrackFactoryTemplate<hulkfight::motion::GrappleStruggleTrack>::vfunc_5 (72 B): matches/0x0014c030.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VGrappleStruggleTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleStruggleTrack>::vfunc_5() {
    GrappleStruggleTrack_14c030* p = (GrappleStruggleTrack_14c030*)alloc_0008d690(0x24);
    if (p) {
        p->initialize_00236d40();
        p->ac = 0;
        p->a14 = 0;
        p->a18 = 0;
        p->a1c = 0;
        p->a20 = 0;
        p->a0 = ((hulk_intptr)DAT_00413678);
        p->a10 = 0xbf800000;
        p->a8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0014c080 fight::TrackFactoryTemplate<hulkfight::motion::GrappleStruggleTrack>::vfunc_2 (43 B): matches/0x0014c080.cpp [wrapped: same definition as 0x0014bf30 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0014c080@@QAEPAXE@Z
namespace fn_0014c080 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00413e5c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_001474c0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413e5c;
    base1_dtor_001474c0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0014c080


// 0x0014c0b0 fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianThrowTrack>::vfunc_1 (60 B): matches/0x0014c0b0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCivilianThrowTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianThrowTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14c0b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14c0b0* t = new (mem) TrackFactoryTemplate_14c0b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014c0f0 fight::TrackFactoryTemplate<hulkfight::motion::CivilianThrowTrack>::vfunc_5 (24 B): matches/0x0014c0f0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCivilianThrowTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fa30 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::CivilianThrowTrack>::vfunc_5() {
    Grapple_14c0f0* p = (Grapple_14c0f0*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack_00147590());
    return (void*)(0);
}


// 0x0014c110 fight::TrackFactoryTemplate<hulkfight::motion::CivilianThrowTrack>::vfunc_2 (43 B): matches/0x0014c110.cpp [wrapped: same definition as 0x0014bf30 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0014c110@@QAEPAXE@Z
namespace fn_0014c110 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00413e78;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00147560();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413e78;
    base1_dtor_00147560();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0014c110


// 0x0014c140 fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_1 (60 B): matches/0x0014c140.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCivilianAttachTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14c140));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14c140* t = new (mem) TrackFactoryTemplate_14c140();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014c180 fight::TrackFactoryTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_5 (45 B): matches/0x0014c180.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCivilianAttachTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_5() {
    Track_14c180* p = (Track_14c180*)FUN_0008d690(0x10);
    if (p) {
        p->Track_14c180::Track_14c180();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004136d8);
        *((int*)p + 3) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0014c1b0 fight::TrackFactoryTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_2 (43 B): matches/0x0014c1b0.cpp [wrapped: same definition as 0x0014bf30 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0014c1b0@@QAEPAXE@Z
namespace fn_0014c1b0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00413e94;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00147620();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413e94;
    base1_dtor_00147620();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0014c1b0


// 0x0014c1e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleExecuteTrack>::vfunc_1 (60 B): matches/0x0014c1e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VGrappleExecuteTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleExecuteTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14c1e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14c1e0* t = new (mem) TrackFactoryTemplate_14c1e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014c220 fight::TrackFactoryTemplate<hulkfight::motion::GrappleExecuteTrack>::vfunc_5 (75 B): matches/0x0014c220.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VGrappleExecuteTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleExecuteTrack>::vfunc_5() {
    char* p = (char*)operator_new(0x28);
    if (p) {
        ((Base1_14c220*)p)->Init1_00236d40();
        *(hulk_uintptr*)(p) = ((hulk_intptr)DAT_00413738);
        *(u32_14c220*)(p + 0xc) = 0;
        *(u32_14c220*)(p + 0x10) = 0xbf800000;
        ((Sub1_14c220*)(p + 0x14))->Init2_00233dd0();
        *(u32_14c220*)(p + 0x20) = 0xfffffc18;
        ((Sub2_14c220*)(p + 0x24))->Init3_00236e00();
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0014c270 fight::TrackFactoryTemplate<hulkfight::motion::GrappleExecuteTrack>::vfunc_2 (43 B): matches/0x0014c270.cpp [wrapped: same definition as 0x0014bf30 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0014c270@@QAEPAXE@Z
namespace fn_0014c270 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00413eb0;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00147770();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413eb0;
    base1_dtor_00147770();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0014c270


// 0x0014c2a0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachJointCondition>::vfunc_1 (60 B): matches/0x0014c2a0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VGrappleAttachJointCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachJointCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14c2a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14c2a0* t = new (mem) TrackFactoryTemplate_14c2a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f1739f6f {

// 0x0014c2e0 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleAttachJointCondition>::vfunc_5 (55 B): matches/0x0014c2e0.cpp
// sym: ?F@Factory_14c2e0@fn_f1739f6f@@UAEPAXXZ
void* Factory_14c2e0::F() {
    Factory_14c2e0* p = (Factory_14c2e0*)FUN_0008d690(0x18);
    if (p) {
        ((Cond_14c2e0*)p)->Init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00413578);
        p->field = 0;
        p->sub.Init_0027af00();
        return p;
    }
    return 0;
}


// 0x0014c320 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleAttachJointCondition>::vfunc_2 (43 B): matches/0x0014c320.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_14c320@fn_f1739f6f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_14c320::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413ecc;
    base1_dtor_00147160();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1739f6f

// 0x0014c350 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleHitReactionTrack>::vfunc_1 (60 B): matches/0x0014c350.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleHitReactionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14c350));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14c350* t = new (mem) TrackFactoryTemplate_14c350();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0014c3b0 fight::TrackFactoryTemplate<hulkfight::motion::GrappleHitReactionTrack>::vfunc_2 (43 B): matches/0x0014c3b0.cpp [wrapped: same definition as 0x0014bf30 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0014c3b0@@QAEPAXE@Z
namespace fn_0014c3b0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00413ee8;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_001476a0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413ee8;
    base1_dtor_001476a0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0014c3b0


// 0x0014c3e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAnimationTrack>::vfunc_1 (60 B): matches/0x0014c3e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCivilianAnimationTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAnimationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_14c3e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_14c3e0* t = new (mem) TrackFactoryTemplate_14c3e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f1739f6f {

// 0x0014c420 fight::TrackFactoryTemplate<hulkfight::motion::CivilianAnimationTrack>::vfunc_5 (24 B): matches/0x0014c420.cpp
// sym: ?f@fn_f1739f6f@@YAPAXXZ
void* f() {
    hulkfight::motion::CivilianAnimationTrack* p = (hulkfight::motion::CivilianAnimationTrack*)alloc_0008d690(0x30);
    if (p)
        return ((CivilianAnimationTrack_nv_14c420*)(((hulkfight::motion::CivilianAnimationTrack*)(p))))->init_00147860();
    return 0;
}

} // namespace fn_f1739f6f

// 0x0014c440 fight::TrackFactoryTemplate<hulkfight::motion::CivilianAnimationTrack>::vfunc_2 (43 B): matches/0x0014c440.cpp [wrapped: same definition as 0x0014bf30 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0014c440@@QAEPAXE@Z
namespace fn_0014c440 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00413f04;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00147830();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413f04;
    base1_dtor_00147830();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0014c440

