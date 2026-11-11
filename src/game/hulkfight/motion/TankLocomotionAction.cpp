// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018ecb0..0x00192030 (kind game, layer game, confidence high), dominant class hulkfight::motion::TankLocomotionAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc171dfe {
#define TREE_TU_END }
namespace fn_fc171dfe {} using namespace fn_fc171dfe;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fc171dfe {
struct Vec3_18ecf0 {
    int x;
    int y;
    int z;
};
class Obj_18ecf0 {
  public:
    char pad[0x18];
    Vec3_18ecf0 v;
    bool Set(Vec3_18ecf0* p);
};
struct Vec3 {
    float x, y, z;
};
class Obj {
  public:
    char _m_pad_0[0x24];
    float x;
    float y;
    float z;
    char Set(const Vec3* v);
    void Set_002367c0(void*);
};
struct S3_18ed70 {
    int a;
    int b;
    int c;
};
struct T_18ed70 {
    char pad[0x30];
    int m30;
    int m34;
    int m38;
    bool m3c;
    bool Set(S3_18ed70* p);
};
struct Val {
    int a;
    int b;
    int c;
};
class Obj_18ef50 {
  public:
    char pad[0x34];
    int m34;
    int m38;
    int m3c;
    bool Set(const Val* v);
};
extern int* hulk_at_004e1530;
class CCondition_18f150 {
  public:
    virtual int vfunc_0(int);
};
class Track_18f160 {
  public:
    Track_18f160();
    virtual void f();
    char pad[4];
    int n;
};
class Sub {
  public:
    Sub();
    int a, b;
};
class ImpulseVelocityTrack : public Track_18f160 {
  public:
    ImpulseVelocityTrack();
    virtual void f();
    int x;
    Sub sub;
    int vals[9];
    char flag;
    char pad2[3];
    float scale;
};
extern void* hulk_at_0041aed8[];
class Str_18f1d0 {
  public:
    void Init_0027af50();
};
class Track_18f1d0 {
  public:
    void* vptr;
    char pad[12];
    Str_18f1d0 s;
    void Fin_00236d60();
};
class ImpulseVelocityTrack_18f1d0 : public Track_18f1d0 {
  public:
    ~ImpulseVelocityTrack_18f1d0();
};
extern int* hulk_at_004e1538;
class CCondition_18f210 {
  public:
    virtual int vfunc_0(int);
};
class Track_18f220 {
  public:
    Track_18f220();
    virtual void f();
};
class SimulationTrack : public Track_18f220 {
  public:
    SimulationTrack();
    char pad[8];
    int x;
    float y;
};
struct Param_18f250 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_18f250 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e1540;
class CCondition_18f290 {
  public:
    virtual int vfunc_0(int);
};
struct Param_18f330 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_18f330 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Vec3_18f350 {
    float x, y, z;
};
struct Key_18f350 {
    unsigned lo;
    unsigned hi;
};
class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Key_18f350 name;
    char pad10[0x60];
    JointDriver *FUN_002248f0(int arg);
};
struct Fighter_18f350 {
    char pad0[0x8c];
    int f8c;
    void FUN_00035980(char flag);
};
struct Skeleton {
    void FUN_00222890(JointDriver *drv, float a, float b, float c, float d, float e, float f);
};
struct Holder_18f350 {
    Fighter_18f350 *FUN_00059a30();
    Skeleton *FUN_00059a40();
    void FUN_00059a50(Vec3_18f350 *out);
};
struct HolderSource_18f350 {
};
struct Target_18f350 {
    char pad0[0x68];
    Vec3_18f350 aim;
};
class TankLocomotionAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Target_18f350 *target;
    HolderSource_18f350 *source;
    JointDriver *driver;
    char pad28[8];
    Vec3_18f350 p30;
    Vec3_18f350 p3c;
    Vec3_18f350 p48;
    Vec3_18f350 p54;
    Vec3_18f350 d60;
    Vec3_18f350 d6c;
    Vec3_18f350 d78;
    Vec3_18f350 d84;
    int f90;
};
struct Sub1_18f490;
struct Sub2_18f490;
struct Mid_18f490 {
    Sub1_18f490* FnA_00059a40();
    Sub2_18f490* FnB_00059a30();
};
struct Mgr_18f490 {
};
struct Sub1_18f490 {
    void Init_00222970(int a, int b);
};
struct Sub2_18f490 {
    void Fin_00035980(int a);
};
struct Q_18f4d0 {
    void Go_001d7510();
};
struct Z {
    char pad[0x128];
    Q_18f4d0* field;
};
struct Y_18f4d0 {
    Z* GetZ_00059a30();
};
struct X_18f4d0 {
};
struct C_18f500 {
    void Fng_001d7590();
};
struct A_18f500 {
    A_18f500* f2_00059a30();
    char pad[0x128];
    C_18f500* field;
};
extern char threat_vftable_18f580;
struct Obj_18f580 {
    int x;
    void f1_0027af50();
    void f2_00236d60();
};
extern void thunk_FUN_00267090(Obj_18f580*);
class ImpulseVelocityTrack_18f580 {
  public:
    void* vftable;
    char pad[0x0c];
    ImpulseVelocityTrack_18f580* vfunc_5(unsigned char);
};
extern void* hulk_at_0041af08[];
class Track_18f5b0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class SimulationTrack_18f5b0 : public Track_18f5b0 {
  public:
    SimulationTrack_18f5b0* vfunc_5(signed char flags);
};
extern void* hulk_at_0041af38[];
class Track_18f5e0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class TankLocomotionTrack_18f5e0 : public Track_18f5e0 {
  public:
    TankLocomotionTrack_18f5e0* vfunc_5(signed char flags);
};
struct Ref_18f610 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_18f610 {
    Action_18f610();
    virtual void f0();
    char p[0x18];
};
struct TankLocomotionAction_18f610 : Action_18f610 {
    TankLocomotionAction_18f610(int a, Ref_18f610* r);
    virtual void f1();
    int m1c;
    Ref_18f610* m20;
    int m24, m28;
    char flags[4];
    char pad[0x90 - 0x30];
    int m90;
    int arr[4];
};
extern void* hulk_at_0041af68[];
class Ref_18f680 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_18f680 {
  public:
    void* vptr;
};
class TankLocomotionAction_18f680 : public Action_18f680 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_18f680* m20;
    Ref_18f680* m24;
    ~TankLocomotionAction_18f680();
};
class RefObj_190920 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_190920 {
  public:
    Action_190920();
    virtual void Update();
    char pad[0x18];
};
class SimulationAction_190920 : public Action_190920 {
  public:
    int mTarget;
    RefObj_190920* mObj;
    SimulationAction_190920(int target, RefObj_190920* obj);
    virtual void Execute();
};
extern void* hulk_at_0041af84[];
class Ref_190970 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_190970 {
  public:
    void* vptr;
};
class SimulationAction_190970 : public Action_190970 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_190970* m20;
    ~SimulationAction_190970();
};
class RefObj_1909b0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1909b0 {
  public:
    Action_1909b0();
    virtual void Update();
    char pad[0x18];
};
class ImpulseVelocityAction_1909b0 : public Action_1909b0 {
  public:
    int mTarget;
    RefObj_1909b0* mObj;
    ImpulseVelocityAction_1909b0(int target, RefObj_1909b0* obj);
    virtual void Execute();
};
extern char hulk_at_0041afa0[];
class Obj_190a00 {
  public:
    virtual void A();
    virtual void B();
};
class TankLocomotionAction_190a00 {
  public:
};
struct V3_190a40 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_190a40 *other, float eps);
};
struct Mat_190a40 {
    float m[16];
};
extern "C" float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
struct Prop_190a40 {
    char pad0[0x1e58];
    float scale;
};
struct Table_190a40 {
    char pad0[0x10];
    unsigned int count;
    char pad14[0x10];
    unsigned int *ids;
    unsigned int FUN_0027b200(unsigned int lo, unsigned int hi);
};
struct Skeleton_190a40 {
    char pad0[8];
    Table_190a40 *table;
    char pad0c[0x10];
    Mat_190a40 *mats;
};
struct Holder_190a40 {
    char pad0[0x120];
    Skeleton_190a40 *skel;
    char pad124[0x210];
    Prop_190a40 *propB;    // 0x334
    Prop_190a40 *propA;    // 0x338
    void FUN_00038410(V3_190a40 *a, V3_190a40 *b);
};
struct Source_190a40 {
    char pad0[8];
    V3_190a40 posA;
    char pad14[0x14];
    V3_190a40 velB;
    char pad34[0xc];
};
struct Params_190a40 {
    char pad0[0x10];
    unsigned int idLo;
    unsigned int idHi;
    V3_190a40 anchor;      // 0x18
    V3_190a40 start;       // 0x24
    V3_190a40 end;         // 0x30
    char pad3c;
    char pad3d[3];
    float factor;   // 0x40
};
struct Handle_190a40 {
    Holder_190a40 *FUN_00059a30();
};
struct Owner_190a40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Source_190a40 *GetSource();
};
struct ArgBlock {
    char pad0[0x28];
    V3_190a40 vel;
};
class CStageCondition_190d40;
class ParamValue_190d40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_190d40 : public ParamValue_190d40 {
  public:
    int pad;
};
class CStageCondition_190d90;
class ParamValue_190d90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_190d90 : public ParamValue_190d90 {
  public:
    int pad;
};
class CStageCondition_190de0;
class ParamValue_190de0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_190de0 : public ParamValue_190de0 {
  public:
    int pad;
};
class CStageCondition_190e30;
class ParamValue_190e30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_190e30 : public ParamValue_190e30 {
  public:
    int pad;
};
class CStageCondition_190e80;
class ParamValue_190e80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_190e80 : public ParamValue_190e80 {
  public:
    int pad;
};
class CStageCondition_190ed0;
class ParamValue_190ed0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_190ed0 : public ParamValue_190ed0 {
  public:
    int pad;
};
class CStageCondition_190f20;
class ParamValue_190f20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_190f20 : public ParamValue_190f20 {
  public:
    int pad;
};
extern const char hulk_at_0049850c[];
extern const char hulk_at_004bfa08[];
extern "C" void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
} // namespace fn_fc171dfe
namespace fight {
class TrackFactoryCaster_190f40 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class ImpulseVelocityTrack_190f40 {};
} }
namespace fn_fc171dfe {
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, const char*, const char*, int);
} // namespace fn_fc171dfe
namespace fight {
class TrackFactoryCaster_190fe0 {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class SimulationTrack_190fe0 {};
} }
namespace fn_fc171dfe {
extern const char a[], hulk_at_004bfab8[];
extern char DAT_0049850c;
extern char DAT_004bfb68;
extern "C" void* __cdecl Lookup(void*, int, void*, void*, int);
} // namespace fn_fc171dfe
namespace fight {
class TrackFactoryCaster_191040 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TankLocomotionTrack_191040 {};
} }
namespace fn_fc171dfe {
extern int hulk_at_00494b44, hulk_at_00494b60;
class Created_191670 {
  public:
    int init_0018f610(hulkfight::motion::TankLocomotionTrack*, hulk_intptr);
};
extern Created_191670* alloc_0008d690(int);
extern int g_vftable_1916c0;
class RefObj_1916c0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class TankLocomotionAction_1916c0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_1916c0* m2;
    RefObj_1916c0* m3;
    void* vfunc_2(unsigned char flag);
};
class Params_191720 {
  public:
    int x;
};
extern Params_191720 TypeA_191720;
extern Params_191720 TypeB_191720;
struct SimulationAction_nv_191720 {
    int Init_00190920(hulkfight::motion::SimulationTrack*, hulk_intptr);
};
hulkfight::motion::SimulationAction* __cdecl Alloc_0008d690(int);
struct RefCounted_191770 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_191770[];
class SimulationAction_191770 {
  public:
    SimulationAction_191770* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_191770* m_20;
};
struct RefCounted_191810 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_191810[];
class ImpulseVelocityAction_191810 {
  public:
    ImpulseVelocityAction_191810* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_191810* m_20;
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class TrackFactoryCasterTemplate_191910 {
  public:
    virtual void cast();
};
void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_191910*);
class TrackFactoryCasterTemplate_191b10 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set_002367c0(void*);
};
void* Find_00236ac0(const char*, TrackFactoryCasterTemplate_191b10*);
} // namespace fn_fc171dfe
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc171dfe {
class TrackFactoryTemplate_191b40 {
  public:
    TrackFactoryTemplate_191b40() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0041af08[];
class SimulationTrack_191b80 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    char pad[8];
    int x;
    float y;
    SimulationTrack_191b80();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_0041b1d4;
class TrackFactoryTemplate_191bf0 {
  public:
    TrackFactoryTemplate_191bf0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
void* __cdecl operator_new(unsigned int);
struct Init_191c30 {
    hulk_intptr initialize_0018f2a0();
};
class TrackFactoryTemplate_191c80 {
  public:
    TrackFactoryTemplate_191c80() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern void* __cdecl Allocate_0008d690(unsigned int);
struct Track_191cc0 {
    void* Init_0018f160();
};

} // namespace fn_fc171dfe

// 0x0018ecb0 FUN_0018ecb0 (12 B): matches/0x0018ecb0.cpp
// sym: ?FUN_0018ecb0@X_18ecb0@owners@@QAEDH@Z
char owners::X_18ecb0::FUN_0018ecb0(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}


// 0x0018ecc0 FUN_0018ecc0 (4 B): matches/0x0018ecc0.cpp
// sym: ?FUN_0018ecc0@O_18ecc0@owners@@QAEPAHXZ
int* owners::O_18ecc0::FUN_0018ecc0() {
    return (int*)((char*)this + 0x10);
}

namespace fn_fc171dfe {

// 0x0018ecf0 FUN_0018ecf0 (26 B): matches/0x0018ecf0.cpp
// sym: ?Set@Obj_18ecf0@fn_fc171dfe@@QAE_NPAUVec3_18ecf0@2@@Z
bool Obj_18ecf0::Set(Vec3_18ecf0* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}


// 0x0018ed30 FUN_0018ed30 (26 B): matches/0x0018ed30.cpp
// sym: ?Set@Obj@fn_fc171dfe@@QAEDPBUVec3@2@@Z
char Obj::Set(const Vec3* v) {
    x = v->x;
    y = v->y;
    z = v->z;
    return 1;
}


// 0x0018ed70 FUN_0018ed70 (26 B): matches/0x0018ed70.cpp
// sym: ?Set@T_18ed70@fn_fc171dfe@@QAE_NPAUS3_18ed70@2@@Z
bool T_18ed70::Set(S3_18ed70* p) {
    m30 = p->a;
    m34 = p->b;
    m38 = p->c;
    return true;
}

} // namespace fn_fc171dfe

// 0x0018eda0 FUN_0018eda0 (12 B): matches/0x0018eda0.cpp
// sym: ?FUN_0018eda0@Obj_18eda0@owners@@QAEEE@Z
unsigned char owners::Obj_18eda0::FUN_0018eda0(unsigned char a) {
    m3c = (char)a;
    return 1;
}


// 0x0018edc0 FUN_0018edc0 (12 B): matches/0x0018edc0.cpp
// sym: ?FUN_0018edc0@Obj_18edc0@owners@@QAE_NH@Z
bool owners::Obj_18edc0::FUN_0018edc0(int x) {
    mValue = x;
    return true;
}


// 0x0018edd0 FUN_0018edd0 (12 B): matches/0x0018edd0.cpp
// sym: ?FUN_0018edd0@X_18edd0@owners@@QAEDH@Z
char owners::X_18edd0::FUN_0018edd0(int a) {
    m = a;
    return 1;
}


// 0x0018ede0 FUN_0018ede0 (12 B): matches/0x0018ede0.cpp
// sym: ?FUN_0018ede0@Obj_18ede0@owners@@QAE_NH@Z
bool owners::Obj_18ede0::FUN_0018ede0(int x) {
    value = x;
    return true;
}


// 0x0018edf0 FUN_0018edf0 (12 B): matches/0x0018edf0.cpp
// sym: ?FUN_0018edf0@Target_18edf0@owners@@QAEEH@Z
unsigned char owners::Target_18edf0::FUN_0018edf0(int x) {
    value = x;
    return 1;
}


// 0x0018ee00 FUN_0018ee00 (12 B): matches/0x0018ee00.cpp
// sym: ?FUN_0018ee00@Obj_18ee00@owners@@QAE_NH@Z
bool owners::Obj_18ee00::FUN_0018ee00(int v) {
    mVal = v;
    return true;
}


// 0x0018ee20 FUN_0018ee20 (12 B): matches/0x0018ee20.cpp
// sym: ?FUN_0018ee20@Obj_18ee20@owners@@QAE_NH@Z
bool owners::Obj_18ee20::FUN_0018ee20(int v) {
    mValue = v;
    return true;
}


// 0x0018ee40 FUN_0018ee40 (12 B): matches/0x0018ee40.cpp
// sym: ?FUN_0018ee40@Obj_18ee40@owners@@QAE_NH@Z
bool owners::Obj_18ee40::FUN_0018ee40(int v) {
    m18 = v;
    return true;
}


// 0x0018ee60 FUN_0018ee60 (12 B): matches/0x0018ee60.cpp
// sym: ?FUN_0018ee60@C_18ee60@owners@@QAE_NH@Z
bool owners::C_18ee60::FUN_0018ee60(int x) {
    m = x;
    return true;
}


// 0x0018ee80 FUN_0018ee80 (12 B): matches/0x0018ee80.cpp
// sym: ?FUN_0018ee80@X_18ee80@owners@@QAE_NPAX@Z
bool owners::X_18ee80::FUN_0018ee80(void* v) {
    m = v;
    return true;
}


// 0x0018eea0 FUN_0018eea0 (18 B): matches/0x0018eea0.cpp
// sym: ?FUN_0018eea0@Obj_18eea0@owners@@QAEDM@Z
char owners::Obj_18eea0::FUN_0018eea0(float x) {
    angle = x * 0.017453292f;
    return 1;
}


// 0x0018eed0 FUN_0018eed0 (18 B): matches/0x0018eed0.cpp
// sym: ?FUN_0018eed0@Obj_18eed0@owners@@QAE_NM@Z
bool owners::Obj_18eed0::FUN_0018eed0(float x) {
    angle = x * 0.017453292519943295f;
    return true;
}


// 0x0018ef00 FUN_0018ef00 (12 B): matches/0x0018ef00.cpp
// sym: ?FUN_0018ef00@Obj_18ef00@owners@@QAE_NH@Z
bool owners::Obj_18ef00::FUN_0018ef00(int v) {
    value = v;
    return true;
}


// 0x0018ef20 FUN_0018ef20 (12 B): matches/0x0018ef20.cpp
// sym: ?FUN_0018ef20@Obj_18ef20@owners@@QAEDH@Z
char owners::Obj_18ef20::FUN_0018ef20(int value) {
    *((int*)((char*)this + 0x30)) = value;
    return 1;
}

namespace fn_fc171dfe {

// 0x0018ef50 FUN_0018ef50 (26 B): matches/0x0018ef50.cpp
// sym: ?Set@Obj_18ef50@fn_fc171dfe@@QAE_NPBUVal@2@@Z
bool Obj_18ef50::Set(const Val* v) {
    m34 = v->a;
    m38 = v->b;
    m3c = v->c;
    return true;
}

} // namespace fn_fc171dfe

// 0x0018ef80 FUN_0018ef80 (12 B): matches/0x0018ef80.cpp
// sym: ?FUN_0018ef80@Obj_18ef80@owners@@QAEDH@Z
char owners::Obj_18ef80::FUN_0018ef80(int x) {
    *(int*)((char*)this + 0x40) = x;
    return 1;
}


// 0x0018efa0 FUN_0018efa0 (12 B): matches/0x0018efa0.cpp
// sym: ?FUN_0018efa0@Obj_18efa0@owners@@QAE_NH@Z
bool owners::Obj_18efa0::FUN_0018efa0(int x) {
    value = x;
    return true;
}


// 0x0018efc0 FUN_0018efc0 (12 B): matches/0x0018efc0.cpp
// sym: ?FUN_0018efc0@Obj_18efc0@owners@@QAE_NH@Z
bool owners::Obj_18efc0::FUN_0018efc0(int value) {
    mField = value;
    return true;
}


// 0x0018efe0 FUN_0018efe0 (12 B): matches/0x0018efe0.cpp
// sym: ?FUN_0018efe0@X_18efe0@owners@@QAEDH@Z
char owners::X_18efe0::FUN_0018efe0(int x) {
    value = x;
    return 1;
}


// 0x0018f000 FUN_0018f000 (18 B): matches/0x0018f000.cpp
// sym: ?FUN_0018f000@Obj_18f000@owners@@QAE_NM@Z
bool owners::Obj_18f000::FUN_0018f000(float x) {
    value = x * 0.017453292f;
    return true;
}


// 0x0018f030 FUN_0018f030 (18 B): matches/0x0018f030.cpp
// sym: ?FUN_0018f030@C_18f030@owners@@QAEDM@Z
char owners::C_18f030::FUN_0018f030(float x) {
    m = x * 0.0174532925f;
    return 1;
}


// 0x0018f060 FUN_0018f060 (12 B): matches/0x0018f060.cpp
// sym: ?FUN_0018f060@X_18f060@owners@@QAE_NH@Z
bool owners::X_18f060::FUN_0018f060(int v) {
    m58 = v;
    return true;
}


// 0x0018f080 FUN_0018f080 (12 B): matches/0x0018f080.cpp
// sym: ?FUN_0018f080@Obj_18f080@owners@@QAEDH@Z
char owners::Obj_18f080::FUN_0018f080(int a) {
    value = a;
    return 1;
}


// 0x0018f0a0 FUN_0018f0a0 (12 B): matches/0x0018f0a0.cpp
// sym: ?FUN_0018f0a0@O_18f0a0@owners@@QAE_NH@Z
bool owners::O_18f0a0::FUN_0018f0a0(int x) {
    value = x;
    return true;
}


// 0x0018f0c0 FUN_0018f0c0 (12 B): matches/0x0018f0c0.cpp
// sym: ?FUN_0018f0c0@Obj_18f0c0@owners@@QAEDH@Z
char owners::Obj_18f0c0::FUN_0018f0c0(int v) {
    m64 = v;
    return 1;
}


// 0x0018f0e0 FUN_0018f0e0 (12 B): matches/0x0018f0e0.cpp
// sym: ?FUN_0018f0e0@O_18f0e0@owners@@QAEDH@Z
char owners::O_18f0e0::FUN_0018f0e0(int value) {
    m = value;
    return 1;
}


// 0x0018f100 FUN_0018f100 (12 B): matches/0x0018f100.cpp
// sym: ?FUN_0018f100@Obj_18f100@owners@@QAE_NH@Z
bool owners::Obj_18f100::FUN_0018f100(int x) {
    value = x;
    return true;
}


// 0x0018f120 FUN_0018f120 (12 B): matches/0x0018f120.cpp
// sym: ?FUN_0018f120@X_18f120@owners@@QAE_NH@Z
bool owners::X_18f120::FUN_0018f120(int v) {
    m70 = v;
    return true;
}

namespace fn_fc171dfe {

// 0x0018f130 FUN_0018f130 (19 B): matches/0x0018f130.cpp
// sym: ?FUN_0018f130@fn_fc171dfe@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0018f130() {
    FUN_00234810(((char*)&DAT_004e1530), ((char*)&DAT_004e1534));
}

} // namespace fn_fc171dfe

// 0x0018f150 hulkfight::motion::ImpulseVelocityTrack::vfunc_0 (16 B): matches/0x0018f150.cpp
// sym: ?vfunc_0@ImpulseVelocityTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ImpulseVelocityTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1530;
    return p[index];
}

namespace fn_fc171dfe {

// 0x0018f160 FUN_0018f160 (77 B): matches/0x0018f160.cpp
// sym: ??0ImpulseVelocityTrack@fn_fc171dfe@@QAE@XZ
ImpulseVelocityTrack::ImpulseVelocityTrack() : Track_18f160(), x(0), sub() {
    for (int i = 0; i < 9; i++)
        vals[i] = 0;
    flag = 0;
    scale = 1.0f;
    n = 1;
}

} // namespace fn_fc171dfe

// 0x0018f1b0 hulkfight::motion::ImpulseVelocityTrack::vfunc_6 (4 B): matches/0x0018f1b0.cpp
// sym: ?vfunc_6@ImpulseVelocityTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::ImpulseVelocityTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0018f1c0 hulkfight::motion::ImpulseVelocityTrack::vfunc_7 (7 B): matches/0x0018f1c0.cpp
// sym: ?vfunc_7@ImpulseVelocityTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::ImpulseVelocityTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_fc171dfe {

// 0x0018f1d0 FUN_0018f1d0 (25 B): matches/0x0018f1d0.cpp
// sym: ??1ImpulseVelocityTrack_18f1d0@fn_fc171dfe@@QAE@XZ
ImpulseVelocityTrack_18f1d0::~ImpulseVelocityTrack_18f1d0() {
    vptr = hulk_at_0041aed8;
    s.Init_0027af50();
    Fin_00236d60();
}


// 0x0018f1f0 FUN_0018f1f0 (19 B): matches/0x0018f1f0.cpp
// sym: ?FUN_0018f1f0@fn_fc171dfe@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0018f1f0() {
    FUN_00234810(((char*)&DAT_004e1538), ((char*)&DAT_004e153c));
}

} // namespace fn_fc171dfe

// 0x0018f210 hulkfight::motion::SimulationTrack::vfunc_0 (16 B): matches/0x0018f210.cpp
// sym: ?vfunc_0@SimulationTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SimulationTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1538;
    return p[index];
}

namespace fn_fc171dfe {

// 0x0018f220 FUN_0018f220 (32 B): matches/0x0018f220.cpp
// sym: ??0SimulationTrack@fn_fc171dfe@@QAE@XZ
SimulationTrack::SimulationTrack() {
    x = 0;
    y = -1.0f;
}

} // namespace fn_fc171dfe

// 0x0018f240 hulkfight::motion::SimulationTrack::vfunc_6 (4 B): matches/0x0018f240.cpp
// sym: ?vfunc_6@SimulationTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::SimulationTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0018f250 hulkfight::motion::SimulationTrack::vfunc_7 (7 B): matches/0x0018f250.cpp
// sym: ?vfunc_7@SimulationTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::SimulationTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fc171dfe {

// 0x0018f270 FUN_0018f270 (19 B): matches/0x0018f270.cpp
// sym: ?FUN_0018f270@fn_fc171dfe@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0018f270() {
    FUN_00234810(((char*)&DAT_004e1540), ((char*)&DAT_004e1544));
}

} // namespace fn_fc171dfe

// 0x0018f290 hulkfight::motion::TankLocomotionTrack::vfunc_0 (16 B): matches/0x0018f290.cpp
// sym: ?vfunc_0@TankLocomotionTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TankLocomotionTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1540;
    return p[index];
}


// 0x0018f2a0 FUN_0018f2a0 (121 B): equivalent/0x0018f2a0.cpp [wrapped: conflict: hulkfight::motion::TankLocomotionTrack]
// sym: ??0TankLocomotionTrack@motion@hulkfight@fn_0018f2a0@@QAE@XZ @14e5e0236638 @w9c0d193a91d8
namespace fn_0018f2a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0018f2a0 @ 0x0018f2a0
class __declspec(novtable) Track_18f2a0 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_18f2a0() { FUN_00236d40(); }
};

namespace hulkfight {
namespace motion {
class TankLocomotionTrack : public Track_18f2a0 {
public:
    virtual unsigned int vfunc_0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6();
    virtual void vfunc_7();

    int f0c;
    float f10;
    int f14, f18, f1c, f20, f24, f28;
    float f2c, f30;
    int f34, f38, f3c;
    float f40, f44, f48, f4c, f50, f54, f58, f5c, f60;
    int f64;
    int f68;
    int f6c, f70;

    TankLocomotionTrack();
};
}
}

hulkfight::motion::TankLocomotionTrack::TankLocomotionTrack() {
    f0c = 0; f14 = 0; f18 = 0; f1c = 0; f20 = 0; f24 = 0; f28 = 0;
    f10 = -1.0f;
    f2c = 1.0f;
    f30 = 1.0f;
    f34 = 0; f38 = 0; f3c = 0;
    f50 = 1.0471975803375244f;
    f54 = 1.0471975803375244f;
    f64 = 0; f6c = 0; f70 = 0;
    f40 = 1.0f; f44 = 1.0f; f48 = 1.0f; f4c = 1.0f;
    f58 = 98.0f;
    f5c = 98.0f;
    f60 = 1.0f;
    f68 = -5;
}
} // namespace fn_0018f2a0


// 0x0018f320 hulkfight::motion::TankLocomotionTrack::vfunc_6 (4 B): matches/0x0018f320.cpp
// sym: ?vfunc_6@TankLocomotionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::TankLocomotionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0018f330 hulkfight::motion::TankLocomotionTrack::vfunc_7 (7 B): matches/0x0018f330.cpp
// sym: ?vfunc_7@TankLocomotionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::TankLocomotionTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fc171dfe {

// 0x0018f350 hulkfight::motion::TankLocomotionAction::vfunc_3 (320 B): equivalent/0x0018f350.cpp
// sym: ?vfunc_3@TankLocomotionAction@fn_fc171dfe@@UAE_NHH@Z @fbbae38320a8 @w62e453d92b86
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// hulkfight::motion::TankLocomotionAction::vfunc_3 @ 0x0018f350
bool TankLocomotionAction::vfunc_3(int a, int b)
{
    Holder_18f350 *holder = ((Holder_18f350 *)((owners::Object_592a0 *)source)->FUN_000592a0());
    Fighter_18f350 *fighter = holder->FUN_00059a30();
    Skeleton *skel = holder->FUN_00059a40();
    if (skel == 0)
        return false;

    float ax = target->aim.x;
    float ay = target->aim.y;
    float az = target->aim.z;

    void *mem = FUN_00263ea0(0x70);
    JointDriver *drv = 0;
    if (mem != 0)
        drv = ((JointDriver *)mem)->FUN_002248f0(0);
    driver = drv;
    ((owners::Target_27b040 *)&(drv->name))->FUN_0027b040((hulk_uintptr)"tankLocomotion");
    driver->AddRef();
    skel->FUN_00222890(driver, -1.0f, ax, 1.0f, ay, az, -1.0f);

    f90 = fighter->f8c;
    Vec3_18f350 pos;
    holder->FUN_00059a50(&pos);
    p30 = pos;
    d60.x = 0;
    d60.y = 1.0f;
    d60.z = 0;
    p3c = pos;
    d6c.x = 0;
    d6c.y = 1.0f;
    d6c.z = 0;
    p48 = pos;
    d78.x = 0;
    d78.y = 1.0f;
    d78.z = 0;
    p54 = pos;
    d84.x = 0;
    d84.y = 1.0f;
    d84.z = 0;
    fighter->FUN_00035980(1);
    return true;
}

} // namespace fn_fc171dfe

// 0x0018f490 hulkfight::motion::TankLocomotionAction::vfunc_4 (61 B): matches/0x0018f490.cpp
// sym: ?vfunc_4@TankLocomotionAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x0015cb40 (propagated; names are from that function)
void hulkfight::motion::TankLocomotionAction::vfunc_4() {
    Mid_18f490* m = ((Mid_18f490 *)((owners::Object_592a0 *)((*(Mgr_18f490 * *)&this->f_20)))->FUN_000592a0());
    Sub1_18f490* s = m->FnA_00059a40();
    if (s) {
        s->Init_00222970(this->f_24, 0);
        Sub2_18f490* t = m->FnB_00059a30();
        if (t)
            t->Fin_00035980(0);
    }
}


// 0x0018f4d0 hulkfight::motion::SimulationAction::vfunc_3 (40 B): matches/0x0018f4d0.cpp
// sym: ?vfunc_3@SimulationAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::SimulationAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    X_18f4d0* x = (*(X_18f4d0 * *)&this->f_20);
    Y_18f4d0* y = ((Y_18f4d0 *)((owners::Object_592a0 *)x)->FUN_000592a0());
    Z* z = y->GetZ_00059a30();
    Q_18f4d0* q = z->field;
    if (!q)
        return false;
    q->Go_001d7510();
    return true;
}


// 0x0018f500 hulkfight::motion::SimulationAction::vfunc_4 (31 B): matches/0x0018f500.cpp
// sym: ?vfunc_4@SimulationAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::SimulationAction::vfunc_4() {
    A_18f500* a = ((A_18f500 *)((owners::Object_592a0 *)((*(A_18f500 * *)&this->f_20)))->FUN_000592a0());
    A_18f500* b = a->f2_00059a30();
    if (b->field)
        b->field->Fng_001d7590();
}

namespace fn_fc171dfe {

// 0x0018f580 hulkfight::motion::ImpulseVelocityTrack::vfunc_5 (46 B): matches/0x0018f580.cpp
// sym: ?vfunc_5@ImpulseVelocityTrack_18f580@fn_fc171dfe@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
ImpulseVelocityTrack_18f580* ImpulseVelocityTrack_18f580::vfunc_5(unsigned char param) {
    ImpulseVelocityTrack_18f580* p = this;
    *(char**)p = &threat_vftable_18f580;
    ((Obj_18f580*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_18f580*)p)->f2_00236d60();
    if (param & 1)
        thunk_FUN_00267090((Obj_18f580*)p);
    return p;
}


// 0x0018f5b0 hulkfight::motion::SimulationTrack::vfunc_5 (36 B): matches/0x0018f5b0.cpp
// sym: ?vfunc_5@SimulationTrack_18f5b0@fn_fc171dfe@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
SimulationTrack_18f5b0* SimulationTrack_18f5b0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041af08;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0018f5e0 hulkfight::motion::TankLocomotionTrack::vfunc_5 (36 B): matches/0x0018f5e0.cpp
// sym: ?vfunc_5@TankLocomotionTrack_18f5e0@fn_fc171dfe@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TankLocomotionTrack_18f5e0* TankLocomotionTrack_18f5e0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041af38;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0018f610 FUN_0018f610 (105 B): matches/0x0018f610.cpp
// sym: ??0TankLocomotionAction_18f610@fn_fc171dfe@@QAE@HPAURef_18f610@1@@Z
TankLocomotionAction_18f610::TankLocomotionAction_18f610(int a, Ref_18f610* r) {
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m90 = 0;
    m1c = a;
    if (r)
        r->AddRef();
    if (m20)
        m20->Release();
    m20 = r;
    for (int i = 0; i < 4; i++) {
        arr[i] = 0;
        flags[i] = 1;
    }
}


// 0x0018f680 FUN_0018f680 (69 B): matches/0x0018f680.cpp
// sym: ??1TankLocomotionAction_18f680@fn_fc171dfe@@QAE@XZ
TankLocomotionAction_18f680::~TankLocomotionAction_18f680() {
    vptr = hulk_at_0041af68;
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
    ((fight::Action *)(Action_18f680 *)this)->FUN_002326a0();
}

} // namespace fn_fc171dfe

// 0x0018f6d0 hulkfight::motion::TankLocomotionAction::vfunc_5 (4678 B): equivalent/0x0018f6d0.cpp [wrapped: conflict: hulkfight::motion::TankLocomotionAction]
// sym: ?vfunc_5@TankLocomotionAction@motion@hulkfight@fn_0018f6d0@@UAE_NHM@Z @24a5f55b9e1d @wd5415ee319c6
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0018f6d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3050 inputs, branch coverage 98/98; --wine 234 inputs)
// hulkfight::motion::TankLocomotionAction::vfunc_5 @ 0x0018f6d0
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double atan(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif


struct Vec3_18f6d0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(const Vec3_18f6d0 *other, float eps);
};

struct Pt_18f6d0 {
    float x, y, z;
};
// the element constructor (thiscall: the element first; returns it), passed to the vector helper as a function
void* __fastcall FUN_00011090(void* element);
void __stdcall FUN_00011520(void *p, unsigned int size, int count, void *ctor);

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bab0(float a);
    void FUN_0022ba30(float a);
    void FUN_0022ba70(float a);
    void FUN_0022ca90(const Matrix *a, const Matrix *b);
    void FUN_0022c2b0(const Vec3_18f6d0 *in, Vec3_18f6d0 *out);
};

struct Xform_18f6d0 {
    Matrix *FUN_00221c40();
    void FUN_00221c60(Matrix *m);
};

struct Skel_18f6d0 {
    char pad00[0x10];
    Xform_18f6d0 xf;
};

struct Driver {
    char pad00[0x18];
    Xform_18f6d0 xf;
};

struct Part_18f6d0 {
    char pad00[0xe8];
    char disabled;
};

struct Entity {
    char pad000[0x140];
    int f140;
    char pad144[0x1d8 - 0x144];
    Vec3_18f6d0 v1d8;
    char pad1e4[0x1ac4 - 0x1e4];
    Vec3_18f6d0 v1ac4;
    char pad1ad0[0x1ca0 - 0x1ad0];
    Part_18f6d0 *part;
    char pad1ca4[0x2064 - 0x1ca4];
    Vec3_18f6d0 v2064;
    float f2070;
    Vec3_18f6d0 v2074;
    Vec3_18f6d0 v2080;
    void FUN_000356c0(Vec3_18f6d0 *out);
    void FUN_00035550(Vec3_18f6d0 *out);
    void FUN_00035230(Vec3_18f6d0 *out);
    void FUN_000357e0();
    void FUN_000359c0(int a);
    void FUN_000368d0(int a);
    void FUN_00035fa0(int a);
};

struct Holder_18f6d0 {
    Entity *FUN_00059a30();
    Skel_18f6d0 *FUN_00059a40();
    void FUN_00059a50(Vec3_18f6d0 *out);
};

struct HolderSource_18f6d0 {
    Holder_18f6d0 *FUN_000592a0();
};

struct Zone;
struct Mid_18f6d0 {
    Zone *FUN_00204200(float x, float y, float z);
    bool FUN_00204440(Zone *z);
};

struct Holder54_18f6d0 {
    Mid_18f6d0 *FUN_000862a0();
};

struct Player_18f6d0 {
    void FUN_00025260(int a, int b, int c);
};

struct World {
    char pad00[0x20];
    Player_18f6d0 *player;
    char pad24[0x54 - 0x24];
    Holder54_18f6d0 *holder;
};

struct Settings_18f6d0 {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    Vec3_18f6d0 v34;
    float f40;
    float f44;
    float f48;
    float f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    float f64;
};


hulk_freg __cdecl FUN_00224f10(Vec3_18f6d0 *v);
hulk_freg __cdecl FUN_00224fc0(float a, float b);
float __cdecl FUN_00083d90(float *v);
void __cdecl FUN_00224d70(float angle, Vec3_18f6d0 *v);
char __cdecl FUN_00202560(Vec3_18f6d0 *origin, float dist, int a, Vec3_18f6d0 *outB, Vec3_18f6d0 *outA, int b, int c, int d);

static __forceinline float FAbs(float v)
{
    union {
        float f;
        unsigned u;
    } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

static __forceinline bool NearZero(Vec3_18f6d0 *v)
{
    Vec3_18f6d0 z;
    z.x = 0.0f;
    z.y = 0.0f;
    z.z = 0.0f;
    return v->FUN_0022d2b0(&z, 1e-5f);
}

namespace hulkfight {
namespace motion {

class TankLocomotionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x18];
    Settings_18f6d0 *volatile settings;
    HolderSource_18f6d0 *owner;
    Driver *volatile driver;
    int cursor;
    char hit[4];
    Vec3_18f6d0 cacheHit[4];
    Vec3_18f6d0 cacheNrm[4];
    float a90;
    float vel[4];
};

bool TankLocomotionAction::vfunc_5(int a, float dt)
{
    if (a != 0)
        return true;
    if (driver == 0)
        return false;
    Holder_18f6d0 *h = owner->FUN_000592a0();
    Entity *ent = h->FUN_00059a30();
    Skel_18f6d0 *sk = h->FUN_00059a40();
    if (FAbs(dt) <= 1e-5f) {
        driver->xf.FUN_00221c60(sk->xf.FUN_00221c40());
        return true;
    }

    Vec3_18f6d0 pos;
    h->FUN_00059a50(&pos);
    Vec3_18f6d0 vA;
    vA.x = 0.0f;
    vA.y = 0.0f;
    vA.z = 0.0f;
    ent->FUN_000356c0(&vA);
    vA.y = 0.0f;
    Vec3_18f6d0 vB = vA;
    float lenB = vB.FUN_0022d110();
    Vec3_18f6d0 vC;
    vC.x = 0.0f;
    vC.y = 0.0f;
    vC.z = 0.0f;
    ent->FUN_00035550(&vC);
    float hC = FUN_00224f10(&vC);
    Vec3_18f6d0 W = ent->v2064;
    if (NearZero(&W))
        W = vC;
    Vec3_18f6d0 U = ent->v2074;
    if (NearZero(&U)) {
        U = ent->v2080;
        U.FUN_0022d110();
        if (NearZero(&U))
            U = W;
    }
    float hU = FUN_00224f10(&U);
    double dot1 = (U.z * W.z + U.y * W.y) + U.x * W.x;
    float s98 = dot1 * ent->f2070;
    volatile float kb4;
    if (dot1 > 0.0f)
        kb4 = settings->f14;
    else
        kb4 = settings->f18;

    Vec3_18f6d0 X = ent->v1ac4;
    if (!NearZero(&X)) {
        float hX = FUN_00224f10(&X);
        float d = FUN_00224fc0(hU, hX);
        float ad = FAbs(d);
        if (ad > 1.5707963705062866f) {
            if (d < 0.0f)
                hU = hX + 1.5707963705062866f;
            else
                hU = hX - 1.5707963705062866f;
        }
    }

    hulk_freg rx = (FUN_00224fc0(hC, hU) * 0.31830987334251404f) * settings->f28;
    float r = (float)rx;
    float k28 = settings->f28;
    float k24 = settings->f24;
    hulk_freg rr = rx;
    if (k24 > 0.0f) {
        float am = FAbs(a90);
        float mn = am < k24 ? am : k24;
        rr = r - (((FUN_00083d90(&a90) * mn) / k24) * k28);
    }
    hulk_freg a90n = rr * dt + a90;
    a90 = a90n;
    Vec3_18f6d0 vF8 = (*(Vec3_18f6d0*)&DAT_004bfc24);
    float ang = (a90n * dt) + hC;
    FUN_00224d70(ang, &vF8);
    float spd = ((vB.z * vF8.z + vB.y * vF8.y) + vB.x * vF8.x) * lenB;
    double P = (double)kb4 * s98;
    double D = P - spd;
    double V;
    if (D > 0.0f) {
        volatile float lim = dt * settings->f1c;
        if (D < lim)
            V = P;
        else
            V = lim + spd;
    } else {
        volatile float lim2 = dt * settings->f20;
        if (D > -((double)dt * settings->f20))
            V = P;
        else
            V = spd - lim2;
    }
    Vec3_18f6d0 vG;
    vG.x = vF8.x * V;
    vG.y = vF8.y * V;
    vG.z = vF8.z * V;
    Vec3_18f6d0 v48;
    v48.x = vG.x - vA.x;
    v48.y = vG.y - vA.y;
    v48.z = vG.z - vA.z;
    Vec3_18f6d0 vE = v48;
    float lenE = vE.FUN_0022d110();
    Matrix *M = sk->xf.FUN_00221c40();
    Matrix m2e0;
    memcpy(&m2e0, M, 0x40);
    float hz = settings->f2c * 0.5f;
    float hx = settings->f30 * 0.5f;
    Vec3_18f6d0 c3 = settings->v34;
    volatile float k16c = settings->f44;
    volatile float k168 = settings->f4c;
    volatile float s98b = settings->f40;
    volatile float k154 = settings->f48;
    volatile float s34 = settings->f54;
    volatile float L14 = settings->f64;
    volatile float s44 = settings->f50;
    volatile float s1c = settings->f58;
    if (ent->f140 == 3) {
        s1c = settings->f5c;
        L14 = settings->f60;
    }
    Vec3_18f6d0 vN = ent->v1d8;
    float lenN = vN.FUN_0022d110();

    float inp[12];
    inp[0] = c3.x + hx;
    inp[1] = c3.y;
    inp[2] = c3.z - hz;
    inp[3] = c3.x - hx;
    inp[4] = c3.y;
    inp[5] = c3.z - hz;
    inp[6] = c3.x + hx;
    inp[7] = c3.y;
    inp[8] = c3.z + hz;
    inp[9] = c3.x - hx;
    inp[10] = c3.y;
    inp[11] = c3.z + hz;
    Pt_18f6d0 pts[4];
    FUN_00011520(pts, 12, 4, (void*)&FUN_00011090);
    for (int j = 0; j < 4; j++)
        m2e0.FUN_0022c2b0((Vec3_18f6d0 *)(inp + j * 3), (Vec3_18f6d0 *)&pts[j]);

    float y0 = pos.y;
    Vec3_18f6d0 v15c;
    v15c.x = 0.0f;
    v15c.y = 0.0f;
    v15c.z = 0.0f;
    ent->FUN_00035230(&v15c);
    if (v15c.y > y0)
        y0 = v15c.y;
    volatile float s78 = -s1c;
    pos.y = 0.0f;

    int contacts = 0;
    Vec3_18f6d0 hitp;
    Vec3_18f6d0 vH;
    Vec3_18f6d0 Q;
    for (int i = 0; i < 4; i++) {
        vH.x = 0.0f;
        vH.y = 1.0f;
        vH.z = 0.0f;
        if (i != cursor && (ent->part == 0 || ent->part->disabled == 0)) {
            hitp = cacheHit[i];
            vH = cacheNrm[i];
        } else {
            Q.x = pts[i].x;
            Q.y = pts[i].y + 2.0f;
            Q.z = pts[i].z;
            if (Q.y < y0)
                Q.y = y0;
            ent->FUN_000368d0(0);
            ent->FUN_00035fa0(0);
            DAT_004dd700->player->FUN_00025260(0, 0, 0);
            char hq = FUN_00202560(&Q, 100.0f, 0, &hitp, &vH, 0, 0, 0);
            hit[i] = hq;
            if (vH.y < 0.05f)
                hit[i] = 0;
            DAT_004dd700->player->FUN_00025260(1, 0, 0);
            ent->FUN_000368d0(1);
            ent->FUN_00035fa0(1);
            if (!hq) {
                hitp.x = pos.x;
                hitp.y = y0;
                hitp.z = pos.z;
                Zone *zq = DAT_004dd700->holder->FUN_000862a0()->FUN_00204200(Q.x, Q.y, Q.z);   // MSVC evaluates the argument before the receiver
                if (DAT_004dd700->holder->FUN_000862a0()->FUN_00204440(zq)) {
                    Vec3_18f6d0 dd;
                    dd.x = pos.x - pts[i].x;
                    dd.y = 0.0f;
                    dd.z = pos.z - pts[i].z;
                    dd.FUN_0022d110();
                    double dot3 = (dd.z * vG.z + dd.x * vG.x) + vG.y * dd.y;
                    if (dot3 < 0.0f) {
                        double nn = -dot3;
                        vG.x = dd.x * nn + vG.x;
                        vG.y = dd.y * nn + vG.y;
                        vG.z = dd.z * nn + vG.z;
                    }
                }
            }
            cacheHit[i] = hitp;
            cacheNrm[i] = vH;
        }

        // x87: dy is stored (fst) and the unrounded st0 is compared with s98b
        hulk_freg dyu = pts[i].y - hitp.y;
        float dy = dyu;
        double Y;
        if (dyu < s98b) {
            v48.x = pts[i].x - pos.x;
            v48.y = 0.0f;
            v48.z = pts[i].z - pos.z;
            v48.FUN_0022d110();
            char hf = hit[i];
            float force = (((s98b - dy) * k16c) + s78) - (k154 * vel[i]);
            if (hf) {
                float ay = FAbs(vH.y);
                double slope;
                if (ay <= 1e-5f)
                    slope = 1.5707963705062866f;
                else
                    slope = atan(sqrt(vH.z * vH.z + vH.x * vH.x) / vH.y);
                if (slope > s44) {
                    float fct = 1.0f - vH.y;
                    if (s44 < s34 && slope < s34)
                        fct = ((slope - s44) / (s34 - s44)) * fct;
                    Vec3_18f6d0 vS;
                    vS.x = vH.x;
                    vS.y = vH.y;
                    vS.z = vH.z;
                    vS.y = 0.0f;
                    vS.FUN_0022d110();
                    double t = ((fct * kb4) * dt) * 0.25f;
                    vS.y = vS.y * t;
                    vS.z = vS.z * t;
                    pos.x = vS.x * t + pos.x;
                    pos.y = vS.y + pos.y;
                    pos.z = vS.z + pos.z;
                }
            }
            contacts++;
            Y = ((force - ((((vE.z * v48.z + vE.x * v48.x) + vE.y * v48.y) * k168) * lenE)) - (((vN.z * v48.z + vN.x * v48.x) + vN.y * v48.y) * lenN));
        } else {
            Y = s78;
        }
        if (dy < 0.0f)
            pts[i].y = hitp.y;
        float nv = Y * dt + vel[i];
        vel[i] = nv;
        if (L14 > 0.0f) {
            if (nv < -L14)
                vel[i] = -L14;
            else if (nv > L14)
                vel[i] = L14;
        }
        hulk_freg ny = dt * vel[i] + pts[i].y;
        pts[i].y = ny;
        pos.y = ny + pos.y;
    }

    pos.y = (pos.y * 0.25f) - c3.y;
    ent->FUN_000357e0();
    int mode = 1;
    if (contacts <= 2) {
        int k = 0;
        while (hit[k]) {
            k++;
            if (k >= 4) {
                mode = 3;
                break;
            }
        }
    }
    ent->FUN_000359c0(mode);

    // MSVC keeps x1, y1, y2, z2, z3 in x87 registers (53-bit) and stores only x2, x3, y3, z1
    hulk_freg x1 = pts[1].x + pts[0].x;
    hulk_freg y1 = pts[1].y + pts[0].y;
    float z1 = pts[0].z + pts[1].z;
    float x2 = x1 - pts[2].x;
    hulk_freg y2 = y1 - pts[2].y;
    hulk_freg z2 = z1 - pts[2].z;
    float x3 = x2 - pts[3].x;
    float y3 = y2 - pts[3].y;
    hulk_freg z3 = z2 - pts[3].z;
    volatile float hy1 = y3 * 0.5f;
    hulk_freg zh1 = z3 * 0.5f;
    hulk_freg xh1 = x3 * 0.5f;
    double L1 = sqrt(zh1 * zh1 + xh1 * xh1);
    float pitch;
    if (FAbs((float)L1) <= 1e-5f)
        pitch = 0.0f;
    else
        pitch = (float)atan(hy1 / L1);
    if (!(pitch >= -s34)) {
        if (pitch > s34)
            pitch = s34;
        else
            pitch = -s34;
    } else if (pitch > s34) {
        pitch = s34;
    }

    hulk_freg x1b = pts[0].x + pts[2].x;
    hulk_freg y1b = pts[0].y + pts[2].y;
    float z1b = pts[0].z + pts[2].z;
    float x2b = x1b - pts[1].x;
    hulk_freg y2b = y1b - pts[1].y;
    hulk_freg z2b = z1b - pts[1].z;
    float x3b = x2b - pts[3].x;
    float y3b = y2b - pts[3].y;
    hulk_freg z3b = z2b - pts[3].z;
    volatile float hy2 = y3b * 0.5f;
    hulk_freg zh2 = z3b * 0.5f;
    hulk_freg xh2 = x3b * 0.5f;
    double L2 = sqrt(zh2 * zh2 + xh2 * xh2);
    float roll;
    if (FAbs((float)L2) <= 1e-5f)
        roll = 0.0f;
    else
        roll = (float)atan(hy2 / L2);
    if (!(roll >= -s34)) {
        if (roll > s34)
            roll = s34;
        else
            roll = -s34;
    } else if (roll > s34) {
        roll = s34;
    }

    Vec3_18f6d0 np;
    np.x = pos.x;
    np.y = pos.y;
    np.z = pos.z;
    volatile float zp = vG.z * dt;
    np.x = np.x + vG.x * dt;
    np.y = np.y + vG.y * dt;
    np.z = np.z + zp;

    Matrix m1e0;
    m1e0.FUN_0022b980();
    m1e0.FUN_0022bab0(roll);
    Matrix m2a0;
    m2a0.FUN_0022b980();
    m2a0.FUN_0022ba30(pitch);
    Matrix m220;
    m220.FUN_0022b980();
    m220.FUN_0022ba70(ang);
    Matrix m260;
    m260.FUN_0022b980();
    m260.FUN_0022ca90(&m1e0, &m2a0);
    Matrix m1a0;
    m1a0.FUN_0022b980();
    m1a0.FUN_0022ca90(&m260, &m220);
    m1a0.m[12] = np.x;
    m1a0.m[13] = np.y;
    m1a0.m[14] = np.z;
    driver->xf.FUN_00221c60(&m1a0);
    cursor = (cursor + 1) % 4;
    return true;
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_0018f6d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fc171dfe {

// 0x00190920 FUN_00190920 (72 B): matches/0x00190920.cpp
// sym: ??0SimulationAction_190920@fn_fc171dfe@@QAE@HPAVRefObj_190920@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
SimulationAction_190920::SimulationAction_190920(int target, RefObj_190920* obj) {
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


// 0x00190970 FUN_00190970 (50 B): matches/0x00190970.cpp
// sym: ??1SimulationAction_190970@fn_fc171dfe@@QAE@XZ
SimulationAction_190970::~SimulationAction_190970() {
    vptr = hulk_at_0041af84;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_190970 *)this)->FUN_002326a0();
}


// 0x001909b0 FUN_001909b0 (72 B): matches/0x001909b0.cpp
// sym: ??0ImpulseVelocityAction_1909b0@fn_fc171dfe@@QAE@HPAVRefObj_1909b0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
ImpulseVelocityAction_1909b0::ImpulseVelocityAction_1909b0(int target, RefObj_1909b0* obj) {
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

} // namespace fn_fc171dfe

// 0x00190a00 FUN_00190a00 (50 B): matches/0x00190a00.cpp
// sym: ?FUN_00190a00@ImpulseVelocityAction@motion@hulkfight@@QAEXXZ
void hulkfight::motion::ImpulseVelocityAction::FUN_00190a00() {
    *(void**)this = &hulk_at_0041afa0;
    _ReadWriteBarrier();
    if ((*(Obj_190a00 * *)&this->f_20)) {
        (*(Obj_190a00 * *)&this->f_20)->B();
        (*(Obj_190a00 * *)&this->f_20) = 0;
    }
    if ((*(void * *)&this->f_1c))
        (*(void * *)&this->f_1c) = 0;
    ((fight::Action *)(((TankLocomotionAction_190a00*)this)))->FUN_002326a0();
}


// 0x00190a40 hulkfight::motion::ImpulseVelocityAction::vfunc_5 (693 B): equivalent/0x00190a40.cpp
// sym: ?vfunc_5@ImpulseVelocityAction@motion@hulkfight@@UAE_NHH@Z @ecfaef1d9997 @wd368b208e1d8
// STATUS: equivalent (tools/equiv.py level 3: 3041 inputs, branch coverage 20/20)
// hulkfight::motion::ImpulseVelocityAction::vfunc_5 @ 0x00190a40
bool hulkfight::motion::ImpulseVelocityAction::vfunc_5(hulk_intptr a, int b) {
    if (a != 0)
        return true;
    Holder_190a40 *holder = ((Handle_190a40 *)((owners::Object_592a0 *)((*(Owner_190a40 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
    Skeleton_190a40 *skel = holder->skel;
    if (skel == 0)
        return false;
    unsigned int idx = 0;
    if (((*(Params_190a40 * *)&this->f_1c)->idLo | (*(Params_190a40 * *)&this->f_1c)->idHi) != 0) {
        idx = skel->table->FUN_0027b200((*(Params_190a40 * *)&this->f_1c)->idLo, (*(Params_190a40 * *)&this->f_1c)->idHi);
        if (idx == 0xffff)
            idx = 0;
    }
    Mat_190a40 m = skel->mats[idx];
    V3_190a40 zero;
    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    V3_190a40 t1 = (*(Params_190a40 * *)&this->f_1c)->anchor;
    ((owners::Mat_22c2b0 *)&m)->FUN_0022c2b0((float *)(const V3_190a40 *)(&t1), (float *)(V3_190a40 *)(&zero));
    V3_190a40 p = (*(Params_190a40 * *)&this->f_1c)->start;
    t1 = (*(Params_190a40 * *)&this->f_1c)->end;
    if (t1.z * t1.z + t1.y * t1.y + t1.x * t1.x > 0.0f) {
        float scale = 0;
        if (holder->propA != 0) {
            scale = holder->propA->scale;
        } else if (holder->propB != 0) {
            scale = holder->propB->scale;
        }
        t1.x = t1.x - p.x;
        t1.y = t1.y - p.y;
        float one = 1.0f;
        float lo = 0;
        t1.z = t1.z - p.z;
        float c = FUN_000186b0(&scale, &lo, &one);
        hulk_freg dx = t1.x * c;    // x87: kept in st0 and added to p.x unrounded (t1.y, t1.z are stored)
        t1.y = t1.y * c;
        t1.z = t1.z * c;
        p.x = p.x + dx;
        p.y = p.y + t1.y;
        p.z = p.z + t1.z;
    }
    V3_190a40 w;
    w.x = 0;
    w.y = 0;
    w.z = 0;
    ((owners::M_22c3b0 *)&m)->FUN_0022c3b0((float *)(const V3_190a40 *)(&p), (float *)(V3_190a40 *)(&w));
    bool doSet = (*(Params_190a40 * *)&this->f_1c)->pad3c != 0;
    if (!doSet) {
        t1.x = 0;
        t1.y = 0;
        t1.z = 0;
        doSet = w.FUN_0022d2b0(&t1, 0.00001f);
    }
    if (doSet) {
        Source_190a40 *src = (*(Owner_190a40 * *)&this->f_20)->GetSource();
        if (src != 0) {
            zero = src->posA;
            w = ((ArgBlock *)src)->vel;
            float k = (*(Params_190a40 * *)&this->f_1c)->factor;
            w.x = w.x * k;
            w.y = w.y * k;
            w.z = w.z * k;
        }
    }
    holder->FUN_00038410(&zero, &w);
    return false;
}


// 0x00190d20 fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>::vfunc_6 (26 B): matches/0x00190d20.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>::**)(int))&this->f_10))(b);
}


// 0x00190d40 fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>::vfunc_2 (11 B): matches/0x00190d40.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00190d70 fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>::vfunc_6 (26 B): matches/0x00190d70.cpp
// sym: ?vfunc_6@?$ParamVector@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>::**)(int))&this->f_10))(b);
}


// 0x00190d90 fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>::vfunc_2 (11 B): matches/0x00190d90.cpp
// sym: ?vfunc_2@?$ParamVector@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00190dc0 fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>::vfunc_6 (26 B): matches/0x00190dc0.cpp
// sym: ?vfunc_6@?$ParamBool@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>::**)(int))&this->f_10))(b);
}


// 0x00190de0 fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>::vfunc_2 (11 B): matches/0x00190de0.cpp
// sym: ?vfunc_2@?$ParamBool@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00190e10 fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>::vfunc_6 (26 B): matches/0x00190e10.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>::**)(int))&this->f_10))(b);
}


// 0x00190e30 fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>::vfunc_2 (11 B): matches/0x00190e30.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00190e60 fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_6 (26 B): matches/0x00190e60.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>::**)(int))&this->f_10))(b);
}


// 0x00190e80 fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_2 (11 B): matches/0x00190e80.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00190eb0 fight::ParamVector<hulkfight::motion::TankLocomotionTrack>::vfunc_6 (26 B): matches/0x00190eb0.cpp
// sym: ?vfunc_6@?$ParamVector@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::TankLocomotionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::TankLocomotionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::TankLocomotionTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::TankLocomotionTrack>::**)(int))&this->f_10))(b);
}


// 0x00190ed0 fight::ParamVector<hulkfight::motion::TankLocomotionTrack>::vfunc_2 (11 B): matches/0x00190ed0.cpp
// sym: ?vfunc_2@?$ParamVector@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::TankLocomotionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00190f00 fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_6 (26 B): matches/0x00190f00.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VTankLocomotionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>::**)(int))&this->f_10))(b);
}


// 0x00190f20 fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_2 (11 B): matches/0x00190f20.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VTankLocomotionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00190f40 fight::TrackFactoryCasterTemplate<hulkfight::motion::ImpulseVelocityTrack>::vfunc_0 (36 B): matches/0x00190f40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ImpulseVelocityTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, hulk_at_0049850c, hulk_at_004bfa08, 0) != 0;
}


// 0x00190f70 fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>::vfunc_0 (30 B): matches/0x00190f70.cpp
// sym: ??_G?$ParamFloatConstRange@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::ImpulseVelocityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x190f70)
#endif


// 0x00190f90 fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>::vfunc_0 (30 B): matches/0x00190f90.cpp
// sym: ??_G?$ParamVector@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::ImpulseVelocityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x190f90)
#endif


// 0x00190fb0 fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>::vfunc_0 (30 B): matches/0x00190fb0.cpp
// sym: ??_G?$ParamBool@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::ImpulseVelocityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x190fb0)
#endif


// 0x00190fe0 fight::TrackFactoryCasterTemplate<hulkfight::motion::SimulationTrack>::vfunc_0 (36 B): matches/0x00190fe0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSimulationTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SimulationTrack>::vfunc_0(void* __p0) { const char * name = (const char *)__p0;

    return FUN_00344e74(name, 0, a, hulk_at_004bfab8, 0) != 0;
}


// 0x00191010 fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>::vfunc_0 (30 B): matches/0x00191010.cpp
// sym: ??_G?$ParamFloatConstRange@VSimulationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::SimulationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x191010)
#endif


// 0x00191040 fight::TrackFactoryCasterTemplate<hulkfight::motion::TankLocomotionTrack>::vfunc_0 (36 B): matches/0x00191040.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTankLocomotionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TankLocomotionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Lookup(p, 0, &DAT_0049850c, &DAT_004bfb68, 0) != 0;
}


// 0x00191070 fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_0 (30 B): matches/0x00191070.cpp
// sym: ??_G?$ParamFloatConstRange@VTankLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x191070)
#endif


// 0x00191090 fight::ParamVector<hulkfight::motion::TankLocomotionTrack>::vfunc_0 (30 B): matches/0x00191090.cpp
// sym: ??_G?$ParamVector@VTankLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::TankLocomotionTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::TankLocomotionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x191090)
#endif


// 0x001910b0 fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>::vfunc_0 (30 B): matches/0x001910b0.cpp
// sym: ??_G?$ParamIntConstRange@VTankLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1910b0)
#endif


// 0x00191670 hulkfight::motion::TankLocomotionTrack::vfunc_10 (73 B): matches/0x00191670.cpp
// sym: ?vfunc_10@TankLocomotionTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::TankLocomotionTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        Created_191670* p = alloc_0008d690(0xa4);
        if (p)
            return p->init_0018f610(this, c);
    }
    return 0;
}

namespace fn_fc171dfe {

// 0x001916c0 hulkfight::motion::TankLocomotionAction::vfunc_2 (90 B): matches/0x001916c0.cpp
// sym: ?vfunc_2@TankLocomotionAction_1916c0@fn_fc171dfe@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* TankLocomotionAction_1916c0::vfunc_2(unsigned char flag) {
    volatile TankLocomotionAction_1916c0* self = this;
    self->mVptr = &g_vftable_1916c0;
    RefObj_1916c0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_1916c0* t2 = self->m2;
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

} // namespace fn_fc171dfe

// 0x00191720 hulkfight::motion::SimulationTrack::vfunc_10 (70 B): matches/0x00191720.cpp
// sym: ?vfunc_10@SimulationTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SimulationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&TypeA_191720), (void*)(&TypeB_191720), 0));
    if (result) {
        hulkfight::motion::SimulationAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((SimulationAction_nv_191720*)(((hulkfight::motion::SimulationAction*)(p))))->Init_00190920(this, c);
    }
    return 0;
}

namespace fn_fc171dfe {

// 0x00191770 hulkfight::motion::SimulationAction::vfunc_2 (71 B): matches/0x00191770.cpp
// sym: ?vfunc_2@SimulationAction_191770@fn_fc171dfe@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
SimulationAction_191770* SimulationAction_191770::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_191770;
    RefCounted_191770* q = *(RefCounted_191770* volatile*)&m_20;
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


// 0x00191810 hulkfight::motion::ImpulseVelocityAction::vfunc_2 (71 B): matches/0x00191810.cpp
// sym: ?vfunc_2@ImpulseVelocityAction_191810@fn_fc171dfe@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
ImpulseVelocityAction_191810* ImpulseVelocityAction_191810::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_191810;
    RefCounted_191810* q = *(RefCounted_191810* volatile*)&m_20;
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


// 0x001918a0 fight::ParamNameConstList<hulkfight::motion::ImpulseVelocityTrack>::vfunc_7 (12 B): matches/0x001918a0.cpp
// sym: ?vfunc_6@ParamBranch@fn_fc171dfe@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fc171dfe

// 0x001918f0 fight::ParamNameConstList<hulkfight::motion::ImpulseVelocityTrack>::vfunc_0 (30 B): matches/0x001918f0.cpp
// sym: ??_G?$ParamNameConstList@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::ImpulseVelocityTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::ImpulseVelocityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1918f0)
#endif

namespace fn_fc171dfe {

// 0x00191910 FUN_00191910 (38 B): matches/0x00191910.cpp
// sym: _FUN_00191910
extern "C" void __cdecl FUN_00191910(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_191910 caster;
    obj->Set_002367c0(Find_00236ac0(name, &caster));
}

} // namespace fn_fc171dfe

// 0x00191ae0 FUN_00191ae0 (38 B): matches/0x00191ae0.cpp [wrapped: conflict: Find]
// sym: _FUN_00191ae0
namespace fn_00191ae0 {
class TrackFactoryCasterTemplate_191ae0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_191ae0*);
extern "C" void FUN_00191ae0(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_191ae0 caster;
    void* p = Find_00236ac0(name, &caster);
    obj->Set_002367c0(p);
}
} // namespace fn_00191ae0

namespace fn_fc171dfe {

// 0x00191b10 FUN_00191b10 (38 B): matches/0x00191b10.cpp
// sym: _FUN_00191b10
extern "C" void FUN_00191b10(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_191b10 caster;
    void* p = Find_00236ac0(name, &caster);
    owner->Set_002367c0(p);
}

} // namespace fn_fc171dfe

// 0x00191b40 fight::TrackFactoryCasterTemplate<hulkfight::motion::SimulationTrack>::vfunc_1 (60 B): matches/0x00191b40.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSimulationTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::SimulationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_191b40));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_191b40* t = new (mem) TrackFactoryTemplate_191b40();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00191b80 fight::TrackFactoryTemplate<hulkfight::motion::SimulationTrack>::vfunc_5 (52 B): matches/0x00191b80.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VSimulationTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::SimulationTrack>::vfunc_5() {
    SimulationTrack_191b80* p = (SimulationTrack_191b80*)FUN_0008d690((int)sizeof(SimulationTrack_191b80));
    if (p) {
        p->SimulationTrack_191b80::SimulationTrack_191b80();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0041af08);
        p->x = 0;
        p->y = -1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc171dfe {

// 0x00191bc0 fight::TrackFactoryTemplate<hulkfight::motion::SimulationTrack>::vfunc_2 (43 B): matches/0x00191bc0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fc171dfe@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041b1d4;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc171dfe

// 0x00191bf0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TankLocomotionTrack>::vfunc_1 (60 B): matches/0x00191bf0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VTankLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::TankLocomotionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_191bf0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_191bf0* t = new (mem) TrackFactoryTemplate_191bf0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00191c30 fight::TrackFactoryTemplate<hulkfight::motion::TankLocomotionTrack>::vfunc_5 (24 B): matches/0x00191c30.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VTankLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TankLocomotionTrack>::vfunc_5() {
    Init_191c30* p = (Init_191c30*)operator_new(0x74);
    if (p)
        return (void*)(p->initialize_0018f2a0());
    return (void*)(0);
}


// 0x00191c50 fight::TrackFactoryTemplate<hulkfight::motion::TankLocomotionTrack>::vfunc_2 (43 B): matches/0x00191c50.cpp [wrapped: same definition as 0x00191bc0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00191c50@@QAEPAXE@Z
namespace fn_00191c50 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0041b1f0;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0018f270();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041b1f0;
    base1_dtor_0018f270();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00191c50


// 0x00191c80 fight::TrackFactoryCasterTemplate<hulkfight::motion::ImpulseVelocityTrack>::vfunc_1 (60 B): matches/0x00191c80.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::ImpulseVelocityTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_191c80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_191c80* t = new (mem) TrackFactoryTemplate_191c80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00191cc0 fight::TrackFactoryTemplate<hulkfight::motion::ImpulseVelocityTrack>::vfunc_5 (24 B): matches/0x00191cc0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VImpulseVelocityTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00070420 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ImpulseVelocityTrack>::vfunc_5() {
    void* p = Allocate_0008d690(0x48);
    if (p)
        return (void*)(((Track_191cc0*)p)->Init_0018f160());
    return (void*)(0);
}


// 0x00191ce0 fight::TrackFactoryTemplate<hulkfight::motion::ImpulseVelocityTrack>::vfunc_2 (43 B): matches/0x00191ce0.cpp [wrapped: same definition as 0x00191bc0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00191ce0@@QAEPAXE@Z
namespace fn_00191ce0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0041b20c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0018f130();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041b20c;
    base1_dtor_0018f130();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00191ce0

