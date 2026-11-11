// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015cd10..0x00161c10 (kind game, layer game, confidence high), dominant class hulkfight::motion::HeliLocomotionAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f94adb62 {
#define TREE_TU_END }
namespace fn_f94adb62 {} using namespace fn_f94adb62;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f94adb62 {
extern char threat_vftable_15cd10;
struct Obj_15cd10 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_15cd10*);
class JointPlantedCondition_15cd10 {
  public:
    void* vftable;
    char pad[0x0c];
    JointPlantedCondition_15cd10* vfunc_5(unsigned char);
};
extern void* Condition_15cd40_vftable[];
class Condition_15cd40 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class PhaseCondition_15cd40 : public Condition_15cd40 {
  public:
    PhaseCondition_15cd40* vfunc_5(signed char flags);
};
extern void* Track_15cd70_vftable[];
class Track_15cd70 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class LocomotingTrack_15cd70 : public Track_15cd70 {
  public:
    LocomotingTrack_15cd70* vfunc_5(signed char flags);
};
extern void* heliVftable;
struct Sub_15cde0 {
    void init();
};
class HeliLocomotionTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual HeliLocomotionTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x9c];
    void after();
};
void thunk_FUN_00267090(HeliLocomotionTrack*);
class Track {
  public:
    ~Track();
    char _m_pad_0[0x68];
    unsigned int count;
};
class Part_15ce20 {
  public:
    ~Part_15ce20();
};
class LocomotionSteerTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual ~LocomotionSteerTrack();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    char pad[0x50];
};
typedef unsigned char byte_15cec0;
struct H {
    char p[8];
    void f();
};
extern char vft_15cec0[];
void release_obj(void* p);
struct GrappleLocomotionSteerTrack {
    void* vt;
    char pad[0x14];
    H h18, h20, h28, h30, h38;
    void g();
    GrappleLocomotionSteerTrack* vfunc_5(byte_15cec0 flag);
};
union FloatBits_15cf40 {
    float f;
    unsigned int u;
};
struct Entry_15cfd0 { char pad[8]; unsigned lo, hi; char rest[24]; };
struct Source_15cfd0 { char pad[0x44]; Entry_15cfd0* begin; Entry_15cfd0* end; };
struct Pair_15cfd0 { unsigned lo,hi; };
struct Packet_15cfd0 { Pair_15cfd0 first, second; unsigned zero1,zero2; };
struct Receiver_15cfd0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void send(Packet_15cfd0*);
};
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern char DAT_0048d534[];
extern char DAT_004ac1d0[];
extern char DAT_0048e01c[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
hulk_freg __cdecl FUN_0015cf40(float value);
struct Marker_15d0c0 {
    char pad0[0x24];
    float value;
};
struct Ramp {
    char pad0[0x224];
    char active;
    char pad225[7];
    float start;
    float end;
    char pad234[8];
    float target;
};
struct Timeline_15d0c0 {
    Track *FUN_00059a40();
};
struct Source_15d0c0 {
};
class PhaseCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused1, Source_15d0c0 *source, int unused3);
    char pad4[8];
    float phase;
    float tolerance;
};
class Ref_15d460 {
  public:
    virtual void A();
    virtual void B();
};
extern int vtable_15d460;
struct Action_15d460 {
    void InitBase();
};
struct LocomotionStrafeAction_nv_15d460 {
    void InitBase();
};
extern void* g_vftable_15d4b0[];
class Ref_15d4b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_15d4b0 {
  public:
    void* vptr;
};
void Free(void*) throw();
struct Sub_15d4b0 {
    char c;
};
void __fastcall SubFini(Sub_15d4b0*) throw();
void __fastcall SubFini2(Sub_15d4b0*) throw();
void __fastcall SubFini3(Sub_15d4b0*) throw();
class LocomotionStrafeAction_15d4b0 : public Action_15d4b0 {
  public:
    char p1c[24];
    Ref_15d4b0* m1c;
    Ref_15d4b0* m20;
    ~LocomotionStrafeAction_15d4b0() throw();
};
hulk_freg __cdecl FUN_00224fc0(float a, float b);
class Table_15d4f0 {
public:
    char pad0[0x24];
    float lo[4];
    float hi[4];
    hulk_freg FUN_0015d4f0(float t, float a, float b);
};
} // namespace fn_f94adb62
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f94adb62 {
struct RefObject { virtual void addRef(); virtual void release(); };
extern void* g_vftable_15e160[];
class Ref_15e160 {
  public:
    virtual void F0();
    virtual void Release();
};
class LocomotionStrafeAction_15e160 {
  public:
    void* vptr;
};
class LocomotionStrafe4Action_15e160 : public LocomotionStrafeAction_15e160 {
  public:
    char p[0x18];
    Ref_15e160* m1c;
    Ref_15e160* m20;
    char p2[0x20];
    void* m44;
    ~LocomotionStrafe4Action_15e160() throw();
};
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_15e1b0 {
  public:
    virtual void f();
    char pad[24];
    Action_15e1b0();
};
class LocomotionSprintAction : public Action_15e1b0 {
  public:
    int x;
    Ref* p;
    int a, b, c;
    LocomotionSprintAction(int, Ref*);
    virtual void f();
};
extern void* g_vftable_15e200[];
class Ref_15e200 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_15e200 {
  public:
    void* vptr;
};
class LocomotionSprintAction_15e200 : public Action_15e200 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_15e200* m20;
    Ref_15e200* m24;
    ~LocomotionSprintAction_15e200();
};
class Ref_15e730 {
  public:
    virtual void A();
    virtual void B();
};
class Action_15e730 {
  public:
    virtual void X();
    Action_15e730();
};
class LocomotionSteerAction_15e730 : public Action_15e730 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[0x18];
    int m1;
    Ref_15e730* m2;
    int m3;
    LocomotionSteerAction_15e730(int, Ref_15e730*);
};
extern void* g_vftable_15e780[];
class Ref_15e780 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_15e780 {
  public:
    void* vptr;
};
class LocomotionSteerAction_15e780 : public Action_15e780 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_15e780* m20;
    Ref_15e780* m24;
    ~LocomotionSteerAction_15e780();
};
struct V3_15e7d0 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_15e7d0 *other, float eps);
};
struct Mgr10_15e7d0 {
    bool FUN_00059a50(V3_15e7d0 *out);
};
struct Player_15e7d0 {
    char pad0[0x10];
    Mgr10_15e7d0 *mgr10;
    char pad14[0x144 - 0x14];
    int flags144;
    char pad148[0x2064 - 0x148];
    V3_15e7d0 v2064;
    float f2070;
    char pad2074[0x20a8 - 0x2074];
    int i20a8;
    hulk_freg FUN_000354c0();
    void FUN_00035550(V3_15e7d0 *out);
};
struct Mgr_15e7d0 {
    Player_15e7d0 *FUN_00059a30();
};
struct Holder_15e7d0 {
};
struct CurObj {
    char pad0[0x8a8];
    float f8a8;
    float f8ac;
    float f8b0;
};
struct Cfg_15e7d0 {
    char pad0[0x14];
    float f14;
    float f18;
};
static inline float Abs(float v)
{
    union {
        float f;
        unsigned int u;
    } b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}
union Arg1_15e7d0 {
    int skip;
    float f;
};
class LocomotionSteerAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(Arg1_15e7d0 a, float dt);
    char pad04[0x1c - 4];
    Cfg_15e7d0 *cfg;
    Holder_15e7d0 *owner;
    CurObj *cur;
    hulk_freg FUN_0015c590(float t);
};
extern "C" char DAT_00415bb4[];
class Action_15ea80 {
  public:
    Action_15ea80();
    virtual void A();
    virtual void B();
    virtual void C();
};
class Ref_15ea80 {
  public:
    virtual void X();
    virtual void Release();
};
class GrappleLocomotionSteerAction : public Action_15ea80 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[24];
    int m1;
    Ref_15ea80* m2;
    int m3;
    GrappleLocomotionSteerAction(int, Ref_15ea80*);
};
extern void* g_vftable_15ead0[];
class Ref_15ead0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_15ead0 {
  public:
    void* vptr;
};
class GrappleLocomotionSteerAction_15ead0 : public Action_15ead0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_15ead0* m20;
    Ref_15ead0* m24;
    ~GrappleLocomotionSteerAction_15ead0();
};
class Thing_15eb20 {
  public:
    virtual void A();
    virtual void B();
};
class Action_15eb20 {
  public:
    virtual void X();
    Action_15eb20();
};
extern void* g_vftable_15eb70[];
class Ref_15eb70 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
struct HeliLocomotionAction_nv_15eb70 {
};
class ClimbLocomotionAction_15eb70 {
  public:
    void* vptr;
    char p[0x18];
    Ref_15eb70* m1c;
    Ref_15eb70* m20;
    Ref_15eb70* m24;
    void f();
};
class Table_15ebc0 {
public:
    char pad0[0x28];
    float lo[4];
    float hi[4];
    hulk_freg FUN_0015ebc0(float t, float a, float b);
};
struct V3_15ed10 {
    float x, y, z;
};
struct Name_15ed10 {
    unsigned int lo, hi;
};
class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_15ed10 name;
    char pad10[4];
    int f14;
    JointDriver *FUN_002248f0(int a);
};
namespace choreo2 {
class Driver_15ed10 {
public:
    virtual void AddRef();
    virtual void v1();
    char pad04[4];
    unsigned int lo;       // 8
    unsigned int hi;       // 0xc
};
}
namespace choreo2 {
class LocomotionStrafeDriver_15ed10 : public Driver_15ed10 {
public:
    virtual void v2();
    char pad10[0x24 - 0x10];
    float f24;
};
}
struct Skeleton;
struct Timing_15ed10 {
    void FUN_00035980(int v);
};
struct Skeleton {
    char pad0[0x10];
    char sub10[4];
    char pad14[0x64 - 0x14];
    int f64;
    unsigned int f68;
    int FUN_002226b0();
    void FUN_00222890(void *driver, float a, int b, float c, float d, float e, float f);
};
struct Clock_15ed10 {
    Timing_15ed10 *FUN_00059a30();
    Skeleton *FUN_00059a40();
};
struct Target_15ed10 {
};
struct Frame_15ed10 {
    char pad0[3];
    char padx;
    float a;               // 0x10
    float best;            // 0x14
    choreo2::LocomotionStrafeDriver_15ed10 *found;  // 0x18
    float s1c;             // 0x1c
    float s20;             // 0x20
    int n24;               // 0x24
    float f28, f2c, f30, f34, f38, f3c, f40;  // 0x28
    int x44;               // 0x44
    hulk_uintptr t48;      // 0x48
    int i4c;               // 0x4c
    int i50;               // 0x50
    char pad54[4];
    unsigned int hi;       // 0x58
    V3_15ed10 q;                  // 0x5c
};
class Climb;
extern "C" void __cdecl FUN_0015cfd0(void *, void *);
class Climb {
public:
    virtual void v0();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual unsigned int v7();
    char pad04[0x18 - 4];
    int f18;
    char pad1c[0x24 - 0x1c];
    float f24;
    char pad28[0x12dc - 0x28];
    char b12dc;
    char b12dd;
    char pad12de[2];
    float f12e0;
    float f12e4;
    float f12e8;
    void FUN_002268f0(V3_15ed10 *v);
};
class ClimbLocomotionAction : public Action_15eb20 {
  public:
    virtual void A();
    virtual void _m_vf2();
    virtual bool vfunc_3(int a, int b);
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual unsigned long long id6();
    virtual void gather(int x, float *p40, float *p3c, float *p38, float *p34, float *p30, float *p2c,
                        float *p28, float *pa, int *p4c, int *p24, float *p20, float *p1c);
    virtual void _m_vf8();
    ClimbLocomotionAction(Thing_15eb20*);
    char _m_pad_4[0x18];
    union { Thing_15eb20* mThing; Target_15ed10 *target; };
    union { Climb *climb; int m20; };
    union { JointDriver *driver; int m24; };
    void FUN_0015c780(float a, float b, float c, float d, float e, float f);
    hulk_freg FUN_0015ebc0(float a, float b, float c);
};
extern void* g_vftable_15f5d0[];
class Ref_15f5d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class ClimbLocomotionAction_15f5d0 {
  public:
    void* vptr;
};
class ClimbLocomotion4Action_15f5d0 : public ClimbLocomotionAction_15f5d0 {
  public:
    char p[0x18];
    Ref_15f5d0* m1c;
    Ref_15f5d0* m20;
    Ref_15f5d0* m24;
    char p2[0x20];
    void* m48;
    ~ClimbLocomotion4Action_15f5d0() throw();
};
struct TypeInfo_15f630 {
    int x;
};
extern TypeInfo_15f630 CFightParamsType_15f630;
extern TypeInfo_15f630 FightParamsType_15f630;
int __cdecl IsType(void*, int, TypeInfo_15f630*, TypeInfo_15f630*, int);
void* __cdecl Allocate(int);
class Allocated_15f630 {
  public:
    int Init(hulkfight::motion::HeliLocomotionTrack*, void*);
};
extern "C" char DAT_00415b00[];
class Base_15f680 {
  public:
    virtual void f0();
    virtual void f1();
};
class HeliLocomotionAction_15f680 {
  public:
    virtual void slot0();
    char pad[0x1c];
    Base_15f680* p20;
    Base_15f680* p24;
};
class Ref_1606d0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1606d0 {
  public:
    virtual void V();
    Action_1606d0();
};
class LocomotingAction_1606d0 : public Action_1606d0 {
  public:
    virtual void V2();
    char pad[0x18];
    Ref_1606d0* mRef;
    LocomotingAction_1606d0(Ref_1606d0*);
};
class Ref_160710 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_160710 {
  public:
    void* vptr;
};
class LocomotingAction_160710 : public Action_160710 {
  public:
    char pad[24];
    Ref_160710* m;
    ~LocomotingAction_160710() throw();
};
class CStageCondition_160780;
class ParamValue_160780 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160780 : public ParamValue_160780 {
  public:
    int pad;
};
class CStageCondition_1607d0;
class ParamValue_1607d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1607d0 : public ParamValue_1607d0 {
  public:
    int pad;
};
class CStageCondition_160820;
class ParamValue_160820 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160820 : public ParamValue_160820 {
  public:
    int pad;
};
class CStageCondition_160870;
class ParamValue_160870 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160870 : public ParamValue_160870 {
  public:
    int pad;
};
class CStageCondition_1608c0;
class ParamValue_1608c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1608c0 : public ParamValue_1608c0 {
  public:
    int pad;
};
class CStageCondition_160910;
class ParamValue_160910 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160910 : public ParamValue_160910 {
  public:
    int pad;
};
class CStageCondition_160960;
class ParamValue_160960 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160960 : public ParamValue_160960 {
  public:
    int pad;
};
class CStageCondition_1609b0;
class ParamValue_1609b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1609b0 : public ParamValue_1609b0 {
  public:
    int pad;
};
class CStageCondition_160a00;
class ParamValue_160a00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160a00 : public ParamValue_160a00 {
  public:
    int pad;
};
class CStageCondition_160a50;
class ParamValue_160a50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160a50 : public ParamValue_160a50 {
  public:
    int pad;
};
class CStageCondition_160aa0;
class ParamValue_160aa0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160aa0 : public ParamValue_160aa0 {
  public:
    int pad;
};
class CStageCondition_160af0;
class ParamValue_160af0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160af0 : public ParamValue_160af0 {
  public:
    int pad;
};
class CStageCondition_160b40;
class ParamValue_160b40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160b40 : public ParamValue_160b40 {
  public:
    int pad;
};
class CStageCondition_160b90;
class ParamValue_160b90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160b90 : public ParamValue_160b90 {
  public:
    int pad;
};
class CStageCondition_160be0;
class ParamValue_160be0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160be0 : public ParamValue_160be0 {
  public:
    int pad;
};
class CStageCondition_160c30;
class ParamValue_160c30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160c30 : public ParamValue_160c30 {
  public:
    int pad;
};
class CStageCondition_160c80;
class ParamValue_160c80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160c80 : public ParamValue_160c80 {
  public:
    int pad;
};
class CStageCondition_160cd0;
class ParamValue_160cd0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160cd0 : public ParamValue_160cd0 {
  public:
    int pad;
};
class CStageCondition_160d20;
class ParamValue_160d20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160d20 : public ParamValue_160d20 {
  public:
    int pad;
};
class CStageCondition_160d70;
class ParamValue_160d70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160d70 : public ParamValue_160d70 {
  public:
    int pad;
};
} // namespace fn_f94adb62
namespace fight {
class ConditionFactoryCaster_160d90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class LocomotingCondition_160d90 {};
} }
namespace fn_f94adb62 {
extern char DAT_004b4450;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f94adb62
namespace fight {
class ConditionFactoryCaster_160df0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class JointPlantedCondition_160df0 {};
} }
namespace fn_f94adb62 {
extern char DAT_004b4508;
} // namespace fn_f94adb62
namespace fight {
class ConditionFactoryCaster_160e70 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PhaseCondition_160e70 {};
} }
namespace fn_f94adb62 {
extern char DAT_004b45c0;
extern int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b4670;
} // namespace fn_f94adb62
namespace fight {
class TrackFactoryCaster_160ed0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class LocomotingTrack_160ed0;
} }
namespace fn_f94adb62 {
extern char DAT_004b4720;
} // namespace fn_f94adb62
namespace fight {
class TrackFactoryCaster_160f30 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class ClimbLocomotion4Track_160f30;
} }
namespace fn_f94adb62 {
extern char DAT_004b47d8;
} // namespace fn_f94adb62
namespace fight {
class TrackFactoryCaster_160fb0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class LocomotionStrafe4Track_160fb0;
} }
namespace fn_f94adb62 {
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int gTypeA_161050;
} // namespace fn_f94adb62
namespace fight {
class TrackFactoryCaster_1610f0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class LocomotionSteerTrack_1610f0 {};
} }
namespace fn_f94adb62 {
extern char DAT_004b4948;
extern char DAT_004b4ac0;
} // namespace fn_f94adb62
namespace fight {
class TrackFactoryCaster_161210 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class GrappleLocomotionSteerTrack_161210 {};
} }
namespace fn_f94adb62 {
void* FUN_0008d690(unsigned int size);
} // namespace fn_f94adb62
namespace hulkfight { namespace motion {
class LocomotingCondition_161280 {
public:
    void FUN_0015a820();
};
} }
namespace fn_f94adb62 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f94adb62
namespace fight {
template <class T>
class ParamBool_161280 : public ParamBoolBase {
public:
    ParamBool_161280(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f94adb62 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f94adb62
namespace hulkfight { namespace motion {
class PhaseCondition_1612e0 {
public:
    void FUN_0015a870();
    void FUN_0015a890();
};
} }
namespace fn_f94adb62 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f94adb62
namespace fight {
template <class T>
class ParamFloatConstRange_1612e0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1612e0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class LocomotingTrack_161380 {
public:
    void FUN_0015a8a0();
    void FUN_0015a8b0();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_161380 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_161380(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f94adb62 {
struct RefObj_161420 {
    virtual void fn0();
    virtual void Release();
};
class LocomotionStrafeAction {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void* vfunc_2(unsigned char flag);
    char _m_pad_4[0x18];
    union { RefObj_161420* volatile m1c; RefObject *object; };
    union { RefObj_161420* volatile m20; unsigned int other; };
    void FUN_00232660();
};
struct LocomotionStrafe4Action : LocomotionStrafeAction {
    char pad2[0x44-0x24];
    unsigned int value;
    virtual void v0();
    LocomotionStrafe4Action *FUN_0015e100(unsigned int initial, RefObject *replacement);
};
extern int g_vt_161420;
class Helper_161470 {
  public:
    int run(hulkfight::motion::LocomotionStrafe4Track*, hulk_intptr);
};
extern void* g_vftable_1614a0[];
class Ref_1614a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class LocomotionStrafeAction_1614a0 {
  public:
    void* vptr;
};
class LocomotionStrafe4Action_1614a0 : public LocomotionStrafeAction_1614a0 {
  public:
    char p[0x18];
    Ref_1614a0* m1c;
    Ref_1614a0* m20;
    char p2[0x20];
    void* m44;
    LocomotionStrafe4Action_1614a0* f2(unsigned char fl);
};
struct Result_161500 {
    int Init(hulkfight::motion::LocomotionSprintTrack*, hulk_intptr);
};
extern Result_161500* Alloc(unsigned int);
extern int g_vftable_161530;
class RefObj_161530 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class LocomotionSprintAction_161530 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_161530* m2;
    RefObj_161530* m3;
    void* vfunc_2(unsigned char flag);
};
extern int g_vftable_1615c0;
class RefObj_1615c0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class LocomotionSteerAction_1615c0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_1615c0* m2;
    RefObj_1615c0* m3;
    void* vfunc_2(unsigned char flag);
};
class Result_161620 {
  public:
    int Build(hulkfight::motion::GrappleLocomotionSteerTrack*, int);
};
extern "C" int __cdecl FUN_0005a470(int);
extern void* __cdecl Allocate(unsigned int);
extern int g_vftable_161660;
class RefObj_161660 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class GrappleLocomotionSteerAction_161660 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_161660* m2;
    RefObj_161660* m3;
    void* vfunc_2(unsigned char flag);
};
class Helper_161720 {
  public:
    int f(hulkfight::motion::ClimbLocomotion4Track*, hulk_intptr);
};
extern "C" Helper_161720* FUN_0008d690(int);
extern void* g_vftable_161770[];
class Ref_161770 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
struct HeliLocomotionAction_nv_161770 {
};
class HeliLocomotionAction_161770 {
  public:
    void* vptr;
    char p[0x1c];
    Ref_161770* m20;
    Ref_161770* m24;
    HeliLocomotionAction_161770* f2(unsigned char flags);
};
extern "C" char DAT_00415c50[];
class LocomotingAction {
  public:
    volatile hulk_intptr vptr;
    char pad[0x1c - 4];
    class Obj_161800* mObj;
    LocomotingAction* V2(int);
};
class Obj_161800 {
  public:
    virtual void V0();
    virtual void V1();
};
extern void thunk(LocomotingAction*);
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
struct ParamValueName_161a00 {
    ParamValueName_161a00(int a);
    virtual void V0();
    char pad[12];
    int m10;
};
struct ParamName_161a00 : ParamValueName_161a00 {
    ParamName_161a00(int a, int b);
};


// 0x0015cd10 hulkfight::motion::JointPlantedCondition::vfunc_5 (46 B): matches/0x0015cd10.cpp
// sym: ?vfunc_5@JointPlantedCondition_15cd10@fn_f94adb62@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
JointPlantedCondition_15cd10* JointPlantedCondition_15cd10::vfunc_5(unsigned char param) {
    JointPlantedCondition_15cd10* p = this;
    *(char**)p = &threat_vftable_15cd10;
    ((Obj_15cd10*)((char*)p + 0x10))->f1();
    ((Obj_15cd10*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_15cd10*)p);
    return p;
}


// 0x0015cd40 hulkfight::motion::PhaseCondition::vfunc_5 (36 B): matches/0x0015cd40.cpp
// sym: ?vfunc_5@PhaseCondition_15cd40@fn_f94adb62@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
PhaseCondition_15cd40* PhaseCondition_15cd40::vfunc_5(signed char flags) {
    *(void***)this = Condition_15cd40_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0015cd70 hulkfight::motion::LocomotingTrack::vfunc_5 (36 B): matches/0x0015cd70.cpp
// sym: ?vfunc_5@LocomotingTrack_15cd70@fn_f94adb62@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
LocomotingTrack_15cd70* LocomotingTrack_15cd70::vfunc_5(signed char flags) {
    *(void***)this = Track_15cd70_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f94adb62

// 0x0015cda0 hulkfight::motion::ClimbLocomotion4Track::vfunc_5 (30 B): matches/0x0015cda0.cpp
// sym: ??_GClimbLocomotion4Track@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::ClimbLocomotion4Track::~ClimbLocomotion4Track() {}


// 0x0015cdc0 hulkfight::motion::LocomotionStrafe4Track::vfunc_5 (30 B): matches/0x0015cdc0.cpp
// sym: ??_GLocomotionStrafe4Track@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::LocomotionStrafe4Track::~LocomotionStrafe4Track() {}

namespace fn_f94adb62 {

// 0x0015cde0 hulkfight::motion::HeliLocomotionTrack::vfunc_5 (49 B): matches/0x0015cde0.cpp
// sym: ?vfunc_5@HeliLocomotionTrack@fn_f94adb62@@UAEPAV12@H@Z
HeliLocomotionTrack* HeliLocomotionTrack::vfunc_5(int flag) {
    *(void**)this = &heliVftable;
    ((Sub_15cde0*)((char*)this + 0xa0))->init();
    after();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x0015ce20 hulkfight::motion::LocomotionSteerTrack::vfunc_5 (78 B): matches/0x0015ce20.cpp
// sym: ??_GLocomotionSteerTrack@fn_f94adb62@@UAEPAXI@Z
LocomotionSteerTrack::~LocomotionSteerTrack() {
    ((Part_15ce20*)((char*)this + 0x50))->~Part_15ce20();
    ((Part_15ce20*)((char*)this + 0x40))->~Part_15ce20();
    ((Part_15ce20*)((char*)this + 0x38))->~Part_15ce20();
    ((Part_15ce20*)((char*)this + 0x30))->~Part_15ce20();
    ((Part_15ce20*)((char*)this + 0x28))->~Part_15ce20();
    ((Track*)this)->~Track();
}

} // namespace fn_f94adb62

// 0x0015ce70 hulkfight::motion::LocomotionSprintTrack::vfunc_5 (78 B): matches/0x0015ce70.cpp [wrapped: conflict: Track]
// sym: ?vfunc_5@LocomotionSprintTrack@fn_0015ce70@@QAEPAV12@E@Z
void operator delete(void* p);
namespace fn_0015ce70 {
extern "C" char DAT_00415aa0[];

struct Track {
  public:
    virtual void vfunc_3();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual ~Track();
    char pad[0x2c];
};

struct Elem_15ce70 {
    ~Elem_15ce70();
    char data[8];
};

class LocomotionSprintTrack : public Track {
  public:
    virtual void vfunc_0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot4();
    virtual void slot6();
    virtual void slot7();
    virtual void slot10();
    LocomotionSprintTrack* vfunc_5(unsigned char flag);
    Elem_15ce70 m_elems[5];
};



LocomotionSprintTrack* LocomotionSprintTrack::vfunc_5(unsigned char flag) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00415aa0);
    this->m_elems[4].~Elem_15ce70();
    this->m_elems[3].~Elem_15ce70();
    this->m_elems[2].~Elem_15ce70();
    this->m_elems[1].~Elem_15ce70();
    this->m_elems[0].~Elem_15ce70();
    this->Track::~Track();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}
} // namespace fn_0015ce70

namespace fn_f94adb62 {

// 0x0015cec0 hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_5 (78 B): matches/0x0015cec0.cpp
// sym: ?vfunc_5@GrappleLocomotionSteerTrack@fn_f94adb62@@QAEPAU12@E@Z
GrappleLocomotionSteerTrack* GrappleLocomotionSteerTrack::vfunc_5(byte_15cec0 flag) {
    vt = vft_15cec0;
    h38.f();
    h30.f();
    h28.f();
    h20.f();
    h18.f();
    g();
    if (flag & 1)
        release_obj(this);
    return this;
}


// 0x0015cf40 FUN_0015cf40 (135 B): equivalent/0x0015cf40.cpp
// sym: ?FUN_0015cf40@fn_f94adb62@@YAMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 7/8, incomplete)
// FUN_0015cf40 @ 0x0015cf40
// Wraps x into [0, 1); results within 1e-5 of 0 or 1 snap to 0.
hulk_freg __cdecl FUN_0015cf40(float x)
{
    if (!(x < 0.0f) && !(x >= 1.0f))
        return x;
    hulk_freg frac = -floor(x) + x;
    FloatBits_15cf40 d;
    d.f = (float)(frac - 1.0f);
    d.u &= 0x7fffffff;
    if (d.f <= 1e-5f)
        return 0.0f;
    d.f = (float)frac;
    d.u &= 0x7fffffff;
    if (d.f <= 1e-5f)
        return 0.0f;
    return frac;
}


// 0x0015cfd0 FUN_0015cfd0 (232 B): equivalent/0x0015cfd0.cpp
// sym: _FUN_0015cfd0
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// FUN_0015cfd0 @ 0x0015cfd0
extern "C" void __cdecl FUN_0015cfd0(void * source, void * receiver) {
 if (!((Source_15cfd0 *)source) || !((Receiver_15cfd0 *)receiver)) return;
 if (((Source_15cfd0 *)source)->end-((Source_15cfd0 *)source)->begin != 2) return;
 Packet_15cfd0 p;
 p.first.lo=((Source_15cfd0 *)source)->begin[0].lo; p.first.hi=((Source_15cfd0 *)source)->begin[0].hi;
 p.second.lo=((Source_15cfd0 *)source)->begin[1].lo; p.second.hi=((Source_15cfd0 *)source)->begin[1].hi;
 p.zero1=0; p.zero2=0;
 unsigned lo,hi;
 if (!((*(unsigned*)&DAT_004e11b0) & 1)) {
 (*(unsigned*)&DAT_004e11b0) |= 1;
 unsigned __int64 key=FUN_002672f0("right_leg",0,0);
 lo=(unsigned)key; hi=(unsigned)(key>>32);
 DAT_004e11a8=lo; (*(unsigned*)&DAT_004e11ac)=hi;
 } else {lo=DAT_004e11a8; hi=(*(unsigned*)&DAT_004e11ac);}
 if(p.second.lo==lo && p.second.hi==hi) {p.second=p.first; p.first.lo=lo;p.first.hi=hi;}
 ((Receiver_15cfd0 *)receiver)->send(&p);
}


// 0x0015d0c0 hulkfight::motion::PhaseCondition::vfunc_6 (310 B): equivalent/0x0015d0c0.cpp
// sym: ?vfunc_6@PhaseCondition@fn_f94adb62@@UAE_NHPAUSource_15d0c0@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 17/18, incomplete)
// hulkfight::motion::PhaseCondition::vfunc_6 @ 0x0015d0c0
bool PhaseCondition::vfunc_6(int unused1, Source_15d0c0 *source, int unused3)
{
    if (!FUN_00344e74(source, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    Track *track = ((Timeline_15d0c0 *)((owners::Object_592a0 *)source)->FUN_000592a0())->FUN_00059a40();
    if (!track)
        return false;

    float zero = (*(float*)&DAT_003f32e0);
    float x;
    unsigned int n = track->count;
    unsigned int i = 0;
    for (;;) {
        if (i >= n) {
            x = zero - phase;
            break;
        }
        Item *item = ((Item *)((owners::C_222e20 *)track)->FUN_00222e20((unsigned)i));
        Marker_15d0c0 *m = (Marker_15d0c0 *)FUN_00344e74(item, 0, DAT_0048d534, DAT_004ac1d0, 0);
        if (m) {
            x = m->value - phase;
            break;
        }
        Ramp *r = (Ramp *)FUN_00344e74(item, 0, DAT_0048d534, DAT_0048e01c, 0);
        if (r && r->active) {
            if (r->end - r->start > 0.0f) {
                x = (r->target - r->start) / (r->end - r->start) - phase;
                break;
            }
        }
        i++;
    }
    float result = FUN_0015cf40(x);
    if (result < 0.0f)
        result = -result;
    return result < tolerance;
}

} // namespace fn_f94adb62

// 0x0015d200 hulkfight::motion::JointPlantedCondition::vfunc_6 (595 B): equivalent/0x0015d200.cpp [wrapped: conflict: CFightParams; fight::Params; hulkfight::motion::JointPlantedCondition]
// sym: ?vfunc_6@JointPlantedCondition@motion@hulkfight@fn_0015d200@@UAE_NHPAVParams@fight@4@H@Z
namespace fn_0015d200 {
// STATUS: equivalent (tools/equiv.py level 3: 20015 inputs, branch coverage 24/24)
// hulkfight::motion::JointPlantedCondition::vfunc_6 @ 0x0015d200
struct Mat_15d200 {
    float m[16];
};

struct BoneEntry_15d200 {
    char pad0[0x10];
    unsigned int *bits;
    char pad14[0x28 - 0x14];
};

struct Finder_15d200 {
    char pad0[0x44];
    BoneEntry_15d200 *begin;
    BoneEntry_15d200 *end;
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Skeleton {
    char pad0[8];
    Finder_15d200 *finder;
    char pad0c[0x1c - 0xc];
    Mat_15d200 *matrices;
};

struct Body_15d200 {
    char pad0[0x64];
    Skeleton *skeleton;
    void FUN_00224540(BoneEntry_15d200 *entry, float *out);
};

struct Stats_15d200 {
    char pad0[0x140];
    int mode;
    char pad144[0x1a48 - 0x144];
    float f1a48;
    float f1a4c;
    float f1a50;
    char pad1a54[0x1ad4 - 0x1a54];
    float f1ad4, f1ad8, f1adc;
    float f1ae0, f1ae4, f1ae8;
    float f1aec, f1af0, f1af4;
    float f1af8, f1afc, f1b00;
    char pad1b04[4];
    char f1b08;
};

struct Handle_15d200 {
    Stats_15d200 *FUN_00059a30();
    Body_15d200 *FUN_00059a40();
};

namespace fight {
class Params {
public:
    virtual void p0();
};
}

class CFightParams : public fight::Params {
public:
    Handle_15d200 *FUN_000592a0();
};

namespace hulkfight {
namespace motion {
class JointPlantedCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a1, fight::Params *params, int a3);

    char pad04[0xc];
    unsigned int idLo;
    unsigned int idHi;
    float threshold;
    char expected;
};

bool JointPlantedCondition::vfunc_6(int a1, fight::Params *params, int a3)
{
    if (!dynamic_cast<CFightParams *>(params))
        return false;

    Handle_15d200 *handle = ((CFightParams *)params)->FUN_000592a0();
    Stats_15d200 *stats = handle->FUN_00059a30();
    Body_15d200 *body = handle->FUN_00059a40();
    Skeleton *skel = body->skeleton;
    Finder_15d200 *finder = skel->finder;
    unsigned int id = finder->FUN_0027b200(idLo, idHi);
    if (id == 0xffff)
        return false;

    unsigned int count = (unsigned int)(finder->end - finder->begin);
    BoneEntry_15d200 *e = finder->begin;
    for (unsigned int i = 0; i < count; i++, e++) {
        if (e->bits[(id >> 5) + 1] & (1u << (id & 0x1f))) {
            float v = 0.0f;
            body->FUN_00224540(e, &v);
            return (v > 0.5f) == expected;
        }
    }

    hulk_freg ax, ay, az, dot;
    if (stats->mode == 4) {
        if (stats->f1b08 == 0) {
            ax = stats->f1ae0;
            ay = stats->f1ae4;
            az = stats->f1ae8;
            dot = (az * stats->f1adc + ay * stats->f1ad8) + ax * stats->f1ad4;
        } else {
            ax = stats->f1af8;
            ay = stats->f1afc;
            az = stats->f1b00;
            dot = (az * stats->f1af4 + ay * stats->f1af0) + ax * stats->f1aec;
        }
    } else {
        ax = 0.0f;
        ay = 1.0f;
        az = 0.0f;
        dot = (stats->f1a50 * 0.0f + stats->f1a48 * 0.0f) + stats->f1a4c;
    }
    float *p = skel->matrices[id].m + 12;
    hulk_freg val = ((p[2] * az + p[1] * ay) + p[0] * ax) + (-dot);
    return (val < threshold) == expected;
}
}
}
} // namespace fn_0015d200


// 0x0015d460 FUN_0015d460 (65 B): matches/0x0015d460.cpp
// sym: ?FUN_0015d460@LocomotionStrafeAction@motion@hulkfight@@QAEPAV123@PAX@Z
hulkfight::motion::LocomotionStrafeAction* hulkfight::motion::LocomotionStrafeAction::FUN_0015d460(void* __p0) { Ref_15d460 * p = (Ref_15d460 *)__p0;

    ((LocomotionStrafeAction_nv_15d460*)this)->InitBase();
    *(hulk_intptr*)this = (hulk_intptr)&vtable_15d460;
    (*(Ref_15d460 * *)&this->f_1c) = 0;
    (*(int *)&this->f_20) = 0;
    if (p)
        p->A();
    if ((*(Ref_15d460 * *)&this->f_1c))
        (*(Ref_15d460 * *)&this->f_1c)->B();
    (*(Ref_15d460 * *)&this->f_1c) = p;
    return (hulkfight::motion::LocomotionStrafeAction*)(this);
}

namespace fn_f94adb62 {

// 0x0015d4b0 FUN_0015d4b0 (55 B): matches/0x0015d4b0.cpp
// sym: ??1LocomotionStrafeAction_15d4b0@fn_f94adb62@@QAE@XZ
LocomotionStrafeAction_15d4b0::~LocomotionStrafeAction_15d4b0() throw() {
    vptr = g_vftable_15d4b0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_15d4b0 *)this)->FUN_002326a0();
}


// 0x0015d4f0 FUN_0015d4f0 (334 B): equivalent/0x0015d4f0.cpp
// sym: ?FUN_0015d4f0@Table_15d4f0@fn_f94adb62@@QAEMMMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 12/12)
// FUN_0015d4f0 @ 0x0015d4f0
hulk_freg Table_15d4f0::FUN_0015d4f0(float t, float a, float b)
{
    if (!(t > 0.0f))
        return 0.0f;
    hulk_freg r1 = FUN_00224fc0(a, b);
    hulk_freg r2 = FUN_0004af40(0.0f, 6.2831855f, r1);
    if (!(DAT_004e11b8 & 1)) {
        DAT_004e11b8 |= 1;
        DAT_004e11b4 = 1.5707964f;
    }
    hulk_freg inv = 1.0f / DAT_004e11b4;
    int quad = (int)(inv * r2);
    int i0 = quad % 4;
    int i1 = (i0 + 1) % 4;
    hulk_freg f = (r2 - (float)i0 * DAT_004e11b4) * inv;
    if (!(t > 0.5f)) {
        return ((1.0f - f) * lo[i0] + f * lo[i1]) * (t + t);
    }
    if (t < 1.0f) {
        hulk_freg h = (t - 0.5f) + (t - 0.5f);
        hulk_freg a1 = (1.0f - f) * lo[i0] + f * lo[i1];
        hulk_freg b1 = (1.0f - f) * hi[i0] + f * hi[i1];
        return (1.0f - h) * a1 + b1 * h;
    }
    return ((1.0f - f) * hi[i0] + f * hi[i1]) * t;
}

} // namespace fn_f94adb62

// 0x0015d640 hulkfight::motion::LocomotionStrafeAction::vfunc_3 (736 B): equivalent/0x0015d640.cpp [wrapped: conflict: hulkfight::motion::LocomotionStrafeAction]
// sym: ?vfunc_3@LocomotionStrafeAction@motion@hulkfight@fn_0015d640@@UAE_NHH@Z
namespace fn_0015d640 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/28, incomplete)
// hulkfight::motion::LocomotionStrafeAction::vfunc_3 @ 0x0015d640
struct V3_15d640 {
    float x, y, z;
};

struct WObj;

namespace choreo2 {
class Driver {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
};
class LocomotionStrafeDriver : public Driver {
public:
    char pad04[4];
    int idlo;               // 0x8
    int idhi;               // 0xc
    char pad10[0x24 - 0x10];
    float f24;              // 0x24
    char pad28[0x12e0 - 0x28];
    float f12e0;
    float f12e4;
    float f12e8;
    void FUN_00222550(float v, int z);
    void FUN_002268f0(V3_15d640 *v);
};
}

struct Sub10_15d640 {
    hulk_freg FUN_002220d0();
};

struct Skel_15d640 {
    char pad0[0x10];
    Sub10_15d640 sub;              // 0x10
    char pad_[0x68 - 0x10 - 1];
    unsigned int count;     // 0x68
    choreo2::Driver *FUN_00222e20(unsigned int i);
    WObj *FUN_002226b0();
    void FUN_00222890(choreo2::LocomotionStrafeDriver *d, float a, float b, float c, float e, float f, float g);
};

struct Player_15d640 {
    void FUN_00035660(V3_15d640 *out);
    void FUN_00035980(int v);
};

struct Owner_15d640 {
    Player_15d640 *FUN_00059a30();
    Skel_15d640 *FUN_00059a40();
};

struct Link_15d640 {
    Owner_15d640 *FUN_000592a0();
};

extern "C++" __declspec(nothrow) void __cdecl FUN_0015cfd0(void *, void *);
extern hulk_freg FUN_000964e0();

namespace hulkfight {
namespace motion {

class LocomotionStrafeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual unsigned __int64 vfunc_6();
    virtual void vfunc_7(WObj *w, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7,
                         float *a8, float *a9, float *a10, float *a11, float *a12, float *a13);
    virtual void vfunc_8();
    char pad04[0x18];
    Link_15d640 *link;             // 0x1c
    choreo2::LocomotionStrafeDriver *driver;    // 0x20
    void FUN_0015c2a0(float a, float b, float c, float d, float e, float f);
    hulk_freg FUN_0015d4f0(float a, float b, float c);
};

struct Frame_15d640 {
    float l58;
    float res;
    choreo2::LocomotionStrafeDriver *found;
    float l4c, l48, l44, l40, l3c, l38;
    float l34, l30, l2c, l28;
    WObj *w1;
    Player_15d640 *player;
    float l1c;
    int z18;
    int pad14;
    int idhi;
    V3_15d640 vv;
};

bool LocomotionStrafeAction::vfunc_3(int a, int b)
{
    Frame_15d640 fr;
    Owner_15d640 *o = link->FUN_000592a0();
    Player_15d640 *p = o->FUN_00059a30();
    fr.player = p;
    Skel_15d640 *q = o->FUN_00059a40();
    if (q == 0)
        return false;
    fr.w1 = q->FUN_002226b0();
    unsigned __int64 id = vfunc_6();
    int idlo = (int)id;
    fr.idhi = (int)(id >> 32);
    fr.res = -1.0f;
    fr.found = 0;
    if (q->count != 0) {
        unsigned int i = 0;
        do {
            choreo2::Driver *d = q->FUN_00222e20(i);
            choreo2::LocomotionStrafeDriver *t = dynamic_cast<choreo2::LocomotionStrafeDriver *>(d);
            if (t != 0) {
                if (fr.res < 0.0f)
                    fr.res = t->f24;
                if ((idlo | fr.idhi) != 0 && t->idlo == idlo && t->idhi == fr.idhi) {
                    fr.found = t;
                    break;
                }
            }
            i++;
        } while (i < q->count);
    }
    if (fr.found != 0)
        fr.found->d0();
    if (driver != 0)
        driver->d1();
    driver = fr.found;
    WObj *w1 = fr.w1;
    fr.l1c = 0.0f;
    fr.z18 = 0;
    fr.l2c = 0.0f;
    fr.l28 = -1.0f;
    fr.l38 = -1.0f;
    fr.l3c = -1.0f;
    fr.l40 = -1.0f;
    fr.l44 = -1.0f;
    fr.l48 = -1.0f;
    fr.l4c = -1.0f;
    fr.l58 = -1.0f;
    fr.l30 = 0.1f;
    fr.l34 = 0.1f;
    vfunc_7(w1, &fr.l28, &fr.l38, &fr.l3c, &fr.l40, &fr.l44, &fr.l48, &fr.l4c, &fr.l58,
            &fr.l1c, &fr.l2c, &fr.l30, &fr.l34);
    driver->FUN_00222550(fr.l1c, fr.z18);
    FUN_0015cfd0((WObj *)w1, (choreo2 :: LocomotionStrafeDriver *)driver);
    FUN_0015c2a0(fr.l38, fr.l3c, fr.l40, fr.l44, fr.l48, fr.l4c);
    if (fr.l58 < 0.0f) {
        float r = fr.res;
        fr.l58 = r;
        if (r < 0.0f)
            fr.l58 = FUN_000964e0();
    }
    driver->f24 = fr.l58;
    float t = q->sub.FUN_002220d0();
    driver->f12e0 = t;
    Player_15d640 *p2 = fr.player;
    fr.vv.x = 0.0f;
    fr.vv.y = 0.0f;
    fr.vv.z = 0.0f;
    p2->FUN_00035660(&fr.vv);
    driver->FUN_002268f0(&fr.vv);
    float e0 = driver->f12e0;
    float e4 = driver->f12e4;
    double r2 = FUN_0015d4f0(1.0f, e4, e0);
    if (r2 > 0.0 && r2 < driver->f12e8)
        driver->f12e8 = (float)r2;
    q->FUN_00222890(driver, fr.l28, fr.l2c, 1.0f, fr.l30, fr.l34, -1.0f);
    p2->FUN_00035980(1);
    return true;
}

}
}
} // namespace fn_0015d640


// 0x0015d920 hulkfight::motion::LocomotionStrafeAction::vfunc_5 (2003 B): equivalent/0x0015d920.cpp [wrapped: conflict: DAT_004b4d60]
// sym: ?v5@LocomotionStrafeAction@fn_0015d920@@UAE_NHM@Z
namespace fn_0015d920 {
// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 69/70, incomplete)
// hulkfight::motion::LocomotionStrafeAction::vfunc_5 @ 0x0015d920

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double fabs(double);
#endif


struct V3 {
    float x, y, z;
    char FUN_0022d2b0(const V3 *z, float eps);
    hulk_freg FUN_0022d110();
    hulk_freg FUN_00018990();
};

struct Obj10 {
    void FUN_00059a50(V3 *out);
};

struct Part8 {
    char pad0[0x10];
    Obj10 *f10;
    void FUN_001d69f0(V3 *out);
};

struct Obj328 {
    char pad0[8];
    Part8 *f8;
    int fc;
    char pad10[0x40 - 0x10];
    float f40, f44, f48;
};

struct Obj1ca0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
};

struct YObj {
    char pad0[0x10];
    Obj10 *f10;
    char pad14[0x144 - 0x14];
    unsigned int f144;
    char pad148[0x328 - 0x148];
    Obj328 *f328;
    char pad32c[0x1ca0 - 0x32c];
    Obj1ca0 *f1ca0;
    char pad1ca4[0x2064 - 0x1ca4];
    V3 v2064;
    float f2070;
    V3 v2074;
    char pad2080[0x20a8 - 0x2080];
    int f20a8;
    hulk_freg FUN_000354c0();
    void FUN_00035550(V3 *out);
};

struct XObj {
    YObj *FUN_00059a30();
};
struct F1c {
};

struct State {
    char pad0[0x12e0];
    float f12e0;
    float f12e4;
    float f12e8;
};

extern float DAT_004b4d60;
extern float DAT_004b4d64;
extern float DAT_004b4d68;

hulk_freg __cdecl FUN_00224ea0(float a, float b);
hulk_freg __cdecl FUN_00224fc0(float a, float b);
hulk_freg __cdecl FUN_00224f10(V3 *v);
char __cdecl FUN_00018960(float a, float b, float c);
void __cdecl FUN_00224d70(float angle, V3 *v);

struct Frame {
    char pad0[3];
    char b3;            // 0x03
    float s10;          // 0x04
    float s14;          // 0x08
    float s18;          // 0x0c
    float s1c;          // 0x10
    float s20;          // 0x14
    float s24;          // 0x18
    float s28;          // 0x1c
    V3 H;               // 0x20
    V3 D;               // 0x2c
    V3 Vv;              // 0x38
    V3 G;               // 0x44
    V3 P;               // 0x50
    V3 Z1;              // 0x5c
    V3 Z2;              // 0x68
};

class LocomotionStrafeAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool v5(int a0, float dt);
    virtual void v6();
    virtual void v7();
    virtual void v8(float *a, float *b, char *c);
    char pad04[0x1c - 4];
    F1c *f1c;
    State *f20;
    hulk_freg FUN_0015d4f0(float a, float b, float c);
};

bool LocomotionStrafeAction::v5(int a0, float dt)
{
    Frame f;

    if (f20 == 0)
        return false;
    YObj *Y = ((XObj *)((owners::Object_592a0 *)f1c)->FUN_000592a0())->FUN_00059a30();
    f.s1c = -1.0f;
    f.s18 = -1.0f;
    f.b3 = 0;
    v8(&f.s1c, &f.s18, &f.b3);
    if (a0)
        return true;
    f20->f12e0 = Y->FUN_000354c0();
    Y->f10->FUN_00059a50(&f.P);
    if (Y->f328 != 0) {
        Obj328 *o = Y->f328;
        int kind = o->fc;
        if (kind == 1) {
            f.Vv.z = 0.0f;
            f.Vv.y = 0.0f;
            f.Vv.x = 0.0f;
            o->f8->f10->FUN_00059a50(&f.Vv);
        } else if (kind == 5) {
            o->f8->FUN_001d69f0(&f.Vv);
        } else {
            f.Vv.x = o->f40;
            f.Vv.y = o->f44;
            f.Vv.z = o->f48;
        }
        f.D.x = f.Vv.x - f.P.x;
        f.D.y = f.Vv.y - f.P.y;
        f.D.z = f.Vv.z - f.P.z;
        Obj1ca0 *o1 = Y->f1ca0;
        if (o1 != 0) {
            if (o1->v9() == 4) {
                f.D.x = f.D.x * -1.0f;
                f.D.y = f.D.y * -1.0f;
                f.D.z = f.D.z * -1.0f;
            }
        }
    } else {
        f.D.x = Y->v2074.x;
        f.D.y = Y->v2074.y;
        f.D.z = Y->v2074.z;
        f.Z1.x = 0.0f;
        f.Z1.y = 0.0f;
        f.Z1.z = 0.0f;
        if (f.D.FUN_0022d2b0(&f.Z1, 1e-5f)) {
            f.D.x = Y->v2064.x;
            f.D.y = Y->v2064.y;
            f.D.z = Y->v2064.z;
            f.Z2.x = 0.0f;
            f.Z2.y = 0.0f;
            f.Z2.z = 0.0f;
            if (f.D.FUN_0022d2b0(&f.Z2, 1e-5f))
                Y->FUN_00035550(&f.D);
        }
    }

    if (f.b3) {
        f.s20 = FUN_00224ea0(f.D.x, f.D.z);
        f.s10 = f20->f12e0;
        f.s28 = f.s18;
        double nv;
        if (f.s18 <= 0.0f) {
            nv = f.s20;
        } else {
            float diff = FUN_00224fc0(f.s10, f.s20);
            f.s14 = f.s28 * dt;
            f.s24 = diff;
            f.s24 = (float)fabs(f.s24);
            if (f.s24 <= f.s14) {
                nv = f.s20;
            } else if (diff < 0.0f) {
                nv = f.s10 - f.s14;
            } else {
                nv = f.s14 + f.s10;
            }
        }
        f.s10 = (float)nv;
        f20->f12e0 = (float)nv;
        f20->f12e4 = (float)nv;
        f.s24 = f20->f12e8;
        f.s14 = Y->f2070;
        if (!(Y->f20a8 < 0)) {
            if (f.s14 <= 0.0f) {
                f.s14 = 0.0f;
            } else {
                float old = f.s14;
                f.s14 = 0.5f;
                if (!(old <= 0.5f))
                    f.s14 = 1.0f;
            }
        }
        float n10 = f.s10;
        f.s14 = FUN_0015d4f0(f.s14, n10, n10);
        if (Y->f144 & 2) {
            float r2 = FUN_0015d4f0(0.5f, n10, n10);
            if (f.s14 > r2)
                f.s14 = r2;
        }
        if (!(f.s1c <= 0.0f)) {
            f.s20 = f.s1c * dt;
            double d = f.s14 - f.s24;
            if (d > 0.0) {
                if (!(f.s20 > d))
                    f20->f12e8 = (float)(f.s20 + f.s24);
                else
                    f20->f12e8 = f.s14;
            } else if (-f.s20 < d) {
                f20->f12e8 = f.s14;
            } else {
                f20->f12e8 = f.s24 - f.s20;
            }
            return true;
        }
        f20->f12e8 = f.s14;
        return true;
    }

    f.G.x = Y->v2064.x;
    f.G.y = Y->v2064.y;
    f.G.z = Y->v2064.z;
    f.s10 = Y->f2070;
    if (!(Y->f20a8 < 0)) {
        if (f.s10 <= 0.0f) {
            f.s10 = 0.0f;
        } else {
            float old = f.s10;
            f.s10 = 0.5f;
            if (!(old <= 0.5f))
                f.s10 = 1.0f;
        }
    }
    f.s24 = f.s10;
    f.s24 = (float)fabs(f.s24);
    if (f.s24 <= 1e-5f) {
        f.G.x = f.D.x;
        f.G.y = f.D.y;
        f.G.z = f.D.z;
    }
    {
        float c0 = f20->f12e0;
        float c4 = f20->f12e4;
        f.s28 = c0;
        f.s24 = c4;
        f.s10 = FUN_0015d4f0(f.s10, c4, c0);
    }
    if (Y->f144 & 2) {
        float d0 = f20->f12e0;
        float d4 = f20->f12e4;
        f.s28 = d0;
        f.s24 = d4;
        float r2 = FUN_0015d4f0(0.5f, d4, d0);
        if (f.s10 > r2)
            f.s10 = r2;
    }
    f.s28 = f20->f12e0;
    f.s20 = FUN_00224f10(&f.D);
    f.s24 = f.s18;
    double nvB;
    if (f.s18 <= 0.0f) {
        nvB = f.s20;
    } else {
        float diff = FUN_00224fc0(f.s28, f.s20);
        f.s14 = f.s24 * dt;
        f.s24 = diff;
        f.s24 = (float)fabs(f.s24);
        if (f.s24 <= f.s14)
            nvB = f.s20;
        else if (diff < 0.0f)
            nvB = f.s28 - f.s14;
        else
            nvB = f.s14 + f.s28;
    }
    f20->f12e0 = (float)nvB;
    float cur2 = f20->f12e4;
    float f8s = f20->f12e8;
    f.s14 = cur2;
    f.s24 = f8s;
    f.s20 = FUN_00224f10(&f.G);
    f.s28 = cur2 - f.s20;
    f.s28 = (float)fabs(f.s28);
    float p4;
    double p8;
    bool early = false;
    if (f.s28 <= 1e-5f) {
        if (FUN_00018960(f8s, f.s10, 1e-5f)) {
            p4 = f.s20;
            p8 = f.s10;
            early = true;
        }
    }
    if (!early) {
        f.s28 = f.s1c;
        if (f.s1c <= 0.0f) {
            p4 = f.s20;
            p8 = f.s10;
        } else {
            f.Vv.x = DAT_004b4d60;
            f.Vv.y = DAT_004b4d64;
            f.Vv.z = DAT_004b4d68;
            f.Vv.x = f.Vv.x * f8s;
            f.Vv.y = f.Vv.y * f8s;
            f.Vv.z = f.Vv.z * f8s;
            FUN_00224d70(cur2, &f.Vv);
            f.H.x = DAT_004b4d60;
            f.H.y = DAT_004b4d64;
            f.H.z = DAT_004b4d68;
            f.H.x = f.H.x * f.s10;
            f.H.y = f.H.y * f.s10;
            f.H.z = f.H.z * f.s10;
            FUN_00224d70(f.s20, &f.H);
            f.H.x = f.H.x - f.Vv.x;
            f.H.y = f.H.y - f.Vv.y;
            f.H.z = f.H.z - f.Vv.z;
            f.s24 = f.s28 * dt;
            if (f.H.FUN_0022d110() <= f.s24) {
                p4 = f.s20;
                p8 = f.s10;
            } else {
                struct { hulk_freg x, y; float z; } hs;   // H * s24: z is stored (rounded), x and y stay in registers
                hs.x = f.H.x * f.s24;
                hs.y = f.H.y * f.s24;
                hs.z = f.H.z * f.s24;
                f.H.x = hs.x + f.Vv.x;
                f.H.y = hs.y + f.Vv.y;
                f.H.z = hs.z + f.Vv.z;
                p4 = FUN_00224f10(&f.H);
                p8 = f.H.FUN_00018990();
            }
        }
    }
    f20->f12e4 = p4;
    f20->f12e8 = (float)p8;
    return true;
}
} // namespace fn_0015d920

namespace fn_f94adb62 {

// 0x0015e100 FUN_0015e100 (85 B): equivalent/0x0015e100.cpp
// sym: ?FUN_0015e100@LocomotionStrafe4Action@fn_f94adb62@@QAEPAU12@IPAURefObject@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0015e100 @ 0x0015e100
LocomotionStrafe4Action *LocomotionStrafe4Action::FUN_0015e100(unsigned int initial, RefObject *replacement) {
    FUN_00232660();
    new ((void*)this) LocomotionStrafeAction;
    object = 0;
    other = 0;
    if (replacement) replacement->addRef();
    if (object) object->release();
    object = replacement;
    new ((void*)this) LocomotionStrafe4Action;
    value = 0;
    value = initial;
    return this;
}


// 0x0015e160 FUN_0015e160 (75 B): matches/0x0015e160.cpp
// sym: ??1LocomotionStrafe4Action_15e160@fn_f94adb62@@QAE@XZ
LocomotionStrafe4Action_15e160::~LocomotionStrafe4Action_15e160() throw() {
    vptr = g_vftable_15e160;
    _ReadWriteBarrier();
    if (m44)
        m44 = 0;
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(LocomotionStrafeAction_15e160 *)this)->FUN_002326a0();
}


// 0x0015e1b0 FUN_0015e1b0 (77 B): matches/0x0015e1b0.cpp
// sym: ??0LocomotionSprintAction@fn_f94adb62@@QAE@HPAVRef@1@@Z
LocomotionSprintAction::LocomotionSprintAction(int v, Ref* q) : Action_15e1b0() {
    volatile int* px = &x;
    *px = 0;
    p = 0;
    a = 0;
    b = 0;
    c = 0;
    x = v;
    if (q)
        q->Add();
    if (p)
        p->Release();
    p = q;
}


// 0x0015e200 FUN_0015e200 (69 B): matches/0x0015e200.cpp
// sym: ??1LocomotionSprintAction_15e200@fn_f94adb62@@QAE@XZ
LocomotionSprintAction_15e200::~LocomotionSprintAction_15e200() {
    vptr = g_vftable_15e200;
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
    ((fight::Action *)(Action_15e200 *)this)->FUN_002326a0();
}

} // namespace fn_f94adb62

// 0x0015e250 hulkfight::motion::LocomotionSprintAction::vfunc_5 (1243 B): equivalent/0x0015e250.cpp [wrapped: conflict: FUN_00224ea0]
// sym: ?vfunc_5@LocomotionSprintAction@fn_0015e250@@UAE_NTSlot_15e250@2@0@Z
namespace fn_0015e250 {
// STATUS: equivalent (tools/equiv.py level 3: 19963 inputs, branch coverage 28/28)
// hulkfight::motion::LocomotionSprintAction::vfunc_5 @ 0x0015e250


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_15e250 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(V3_15e250 *other, float limit);
};

struct Stats_15e250 {
    char pad0[0x2064];
    V3_15e250 v2064;
    char pad2070[4];
    V3_15e250 v2074;
    hulk_freg FUN_000354c0();
    char FUN_00035550(V3_15e250 *out);
};

struct Target_15e250 {
    char pad0[0x8a0];
    float f8a0;
    float f8a4;
    float f8a8;
    float f8ac;
    float f8b0;
};

struct Cfg_15e250 {
    char pad0[0x18];
    float f18;
    float f1c;
    float f20;
    float f24;
};

void *__fastcall FUN_000592a0(void *owner);
extern "C" Stats_15e250 *__fastcall FUN_00059a30(void *x);
double __cdecl FUN_00224ea0(float x, float z);
double __cdecl FUN_00224fc0(int a, int b);
double __cdecl FUN_00224f10(V3_15e250 *v);
double __cdecl FUN_00083d90(float *v);
void __cdecl FUN_00224d70(int angle, V3_15e250 *v);

union Slot_15e250 {
    int i;
    float f;
    unsigned int u;
};

union Bits_15e250 {
    float f;
    unsigned int u;
    int i;
};

class LocomotionSprintAction {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vfunc_5(Slot_15e250 a1, Slot_15e250 a2);
    char pad04[0x1c - 4];
    Cfg_15e250 *cfg;
    void *owner;
    Target_15e250 *target;
    char pad28[4];
    float f2c;
    hulk_freg FUN_0015c4f0(float v);
};

bool LocomotionSprintAction::vfunc_5(Slot_15e250 a1, Slot_15e250 a2)
{
    struct Frame {
        float s0;
        float s4;
        float s8;
        float sC;
        float s10;
        float s14;
        V3_15e250 w;
        V3_15e250 v2;
        V3_15e250 z;
        V3_15e250 v;
        V3_15e250 v0;
        V3_15e250 v1;
    } f;

    if (a1.i != 0)
        return true;
    if (target == 0)
        return false;

    Stats_15e250 *st = FUN_00059a30(FUN_000592a0(owner));
    f.v = st->v2064;
    f.z.x = 0.0f;
    f.z.y = 0.0f;
    f.z.z = 0.0f;
    if (f.v.FUN_0022d2b0(&f.z, 1e-5f)) {
        f.v = st->v2074;
        f.z.x = 0.0f;
        f.z.y = 0.0f;
        f.z.z = 0.0f;
        if (f.v.FUN_0022d2b0(&f.z, 1e-5f))
            st->FUN_00035550(&f.v);
    }

    a1.f = (float)FUN_00224ea0(f.v.x, f.v.z);
    int h0 = a1.i;
    f.s14 = FUN_0015c4f0(1.0f);
    *(int *)&f.s0 = *(int *)&target->f8ac;
    float cur = st->FUN_000354c0();
    target->f8a8 = cur;
    double dd = FUN_00224fc0(*(int *)&f.s0, h0);
    dd = dd * 0.31830987f;
    Cfg_15e250 *c = cfg;
    *(int *)&f.s4 = *(int *)&c->f1c;
    *(int *)&a1.i = *(int *)&c->f18;
    dd = dd * f.s4;
    f.s10 = (float)dd;

    double rr = dd;
    if (a1.f > 0.0f) {
        Bits_15e250 fc;
        fc.f = f2c;
        Bits_15e250 ab;
        ab.u = fc.u & 0x7fffffff;
        *(int *)&f.sC = fc.i;
        if (ab.f < a1.f)
            f.s8 = ab.f;
        else
            f.s8 = a1.f;
        rr = (double)f.s10 - FUN_00083d90(&f2c) * f.s8 / a1.f * f.s4;
    }
    Target_15e250 *t1 = target;
    double sum = rr * a2.f + f2c;
    f2c = (float)sum;
    double ang = sum * a2.f + f.s0;
    t1->f8a8 = (float)ang;
    float na = (float)ang;
    f.s0 = na;
    target->f8ac = na;
    target->f8b0 = f.s14;
    f.s0 = (float)FUN_00224fc0(h0, *(int *)&na);

    f.v0 = (*(V3_15e250*)&DAT_004b4d60);
    FUN_00224d70(*(int *)&na, &f.v0);
    f.v1 = (*(V3_15e250*)&DAT_004b4d60);
    FUN_00224d70(h0, &f.v1);
    Cfg_15e250 *c2 = cfg;
    Slot_15e250 s20;
    s20.f = c2->f20;
    a1.f = s20.f;
    double dot = f.v0.z * f.v1.z + f.v0.y * f.v1.y + f.v0.x * f.v1.x;
    double t;
    if (dot < a1.f)
        t = 0.0;
    else if (dot < 0.0)
        t = 0.0;
    else if (dot > 1.0)
        t = 1.0;
    else if (!(a1.f > 0.0f))
        t = dot;
    else
        t = (dot - a1.f) / a1.f;
    double u = 1.0 - t;
    f.sC = target->f8a0;
    f.s4 = target->f8a4;
    a1.f = (float)u;
    f.s8 = f.sC - f.s0;
    Bits_15e250 b1;
    b1.f = f.s8;
    b1.u &= 0x7fffffff;
    double outA;
    double outB;
    bool direct = false;
    if (b1.f <= 1e-5f) {
        f.s8 = f.s4 - a1.f;
        b1.f = f.s8;
        b1.u &= 0x7fffffff;
        if (b1.f <= 1e-5f)
            direct = true;
    }
    if (!direct) {
        f.s14 = c2->f24;
        if (f.s14 <= 0.0f)
            direct = true;
    }
    if (direct) {
        outA = f.s0;
        outB = a1.f;
    } else {
        f.v2 = (*(V3_15e250*)&DAT_004b4d60);
        FUN_00224d70(*(int *)&f.sC, &f.v2);
        f.v2.x = f.v2.x * f.s4;
        f.z = (*(V3_15e250*)&DAT_004b4d60);
        f.v2.y = f.v2.y * f.s4;
        f.v2.z = f.v2.z * f.s4;
        FUN_00224d70(*(int *)&f.s0, &f.z);
        f.z.x = f.z.x * a1.f;
        f.w.x = f.z.x;
        f.z.y = f.z.y * a1.f;
        f.w.y = f.z.y;
        f.z.z = f.z.z * a1.f;
        f.w.z = f.z.z;
        f.w.x = f.w.x - f.v2.x;
        f.w.y = f.w.y - f.v2.y;
        f.w.z = f.w.z - f.v2.z;
        a2.f = f.s14 * a2.f;
        double len = f.w.FUN_0022d110();
        if (len <= a2.f) {
            outA = f.s0;
            outB = a1.f;
        } else {
            struct { hulk_freg x, y; float z; } t;   // w * a2: z is stored (rounded), x and y stay in registers
            t.x = f.w.x * a2.f;
            t.y = f.w.y * a2.f;
            t.z = f.w.z * a2.f;
            f.w.x = t.x + f.v2.x;
            f.w.y = t.y + f.v2.y;
            f.w.z = t.z + f.v2.z;
            outA = FUN_00224f10(&f.w);
            outB = sqrt(f.w.z * f.w.z + f.w.y * f.w.y + f.w.x * f.w.x);
        }
    }
    target->f8a0 = (float)outA;
    target->f8a4 = (float)outB;
    return true;
}
} // namespace fn_0015e250

namespace fn_f94adb62 {

// 0x0015e730 FUN_0015e730 (79 B): matches/0x0015e730.cpp
// sym: ??0LocomotionSteerAction_15e730@fn_f94adb62@@QAE@HPAVRef_15e730@1@@Z
LocomotionSteerAction_15e730::LocomotionSteerAction_15e730(int a, Ref_15e730* b) : Action_15e730() {
    int* q = &m1;
    *q = 0;
    m2 = 0;
    m3 = 0;
    m1 = a;
    if (b)
        b->A();
    if (m2)
        m2->B();
    m2 = b;
}


// 0x0015e780 FUN_0015e780 (69 B): matches/0x0015e780.cpp
// sym: ??1LocomotionSteerAction_15e780@fn_f94adb62@@QAE@XZ
LocomotionSteerAction_15e780::~LocomotionSteerAction_15e780() {
    vptr = g_vftable_15e780;
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
    ((fight::Action *)(Action_15e780 *)this)->FUN_002326a0();
}


// 0x0015e7d0 hulkfight::motion::LocomotionSteerAction::vfunc_5 (674 B): equivalent/0x0015e7d0.cpp
// sym: ?vfunc_5@LocomotionSteerAction@fn_f94adb62@@UAE_NTArg1_15e7d0@2@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 25/30, incomplete)
// hulkfight::motion::LocomotionSteerAction::vfunc_5 @ 0x0015e7d0
  // 0.0
  // 0.5
bool LocomotionSteerAction::vfunc_5(Arg1_15e7d0 a, float dt)
{
    V3_15e7d0 vecA;
    V3_15e7d0 pos;
    V3_15e7d0 vecB;

    if (a.skip)
        return true;
    if (!cur)
        return false;

    Mgr_15e7d0 *mgr = ((Mgr_15e7d0 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    Player_15e7d0 *pl = mgr->FUN_00059a30();
    float f = pl->FUN_000354c0();
    cur->f8a8 = f;
    cur->f8ac = f;

    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    pl->mgr10->FUN_00059a50(&pos);

    vecA = pl->v2064;
    vecB.x = 0.0f;
    vecB.y = 0.0f;
    vecB.z = 0.0f;
    if (vecA.FUN_0022d2b0(&vecB, 0.00001f))
        pl->FUN_00035550(&vecA);

    float ang = FUN_00224ea0(vecA.x, vecA.z);
    float q = cur->f8ac;
    a.f = cfg->f18;
    float r;
    if (a.f <= (*(float*)&DAT_003f32e0)) {
        r = ang;
    } else {
        float d = FUN_00224fc0(q, ang);
        float maxStep = a.f * dt;
        a.f = d;
        if (Abs(a.f) <= maxStep) {
            r = ang;
        } else if (d < (*(float*)&DAT_003f32e0)) {
            r = q - maxStep;
        } else {
            r = maxStep + q;
        }
    }
    cur->f8a8 = r;
    cur->f8ac = r;

    float v = pl->f2070;
    CurObj *c2 = cur;
    float w = c2->f8b0;
    if (pl->i20a8 >= 0) {
        if (v <= (*(float*)&DAT_003f32e0)) {
            v = 0.0f;
        } else {
            float vold = v;
            v = 0.5f;
            if (!(vold <= (*(float*)&DAT_003f32f4)))
                v = 1.0f;
        }
    }
    a.f = FUN_0015c590(v);
    if (pl->flags144 & 2) {
        float h = FUN_0015c590(0.5f);
        if (a.f > h)
            a.f = h;
    }
    float r2 = a.f;
    if (cfg->f14 <= (*(float*)&DAT_003f32e0)) {
        c2->f8b0 = r2;
        return true;
    }
    dt = cfg->f14 * dt;
    if (r2 - w > (*(float*)&DAT_003f32e0)) {
        if (dt > r2 - w)
            c2->f8b0 = r2;
        else
            c2->f8b0 = dt + w;
    } else {
        if (-dt < r2 - w)
            c2->f8b0 = r2;
        else
            c2->f8b0 = w - dt;
    }
    return true;
}


// 0x0015ea80 FUN_0015ea80 (79 B): matches/0x0015ea80.cpp
// sym: ??0GrappleLocomotionSteerAction@fn_f94adb62@@QAE@HPAVRef_15ea80@1@@Z
GrappleLocomotionSteerAction::GrappleLocomotionSteerAction(int x, Ref_15ea80* p) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00415bb4);
    volatile int* q = &m1;
    *q = 0;
    m2 = 0;
    m3 = 0;
    m1 = x;
    if (p)
        p->X();
    if (m2)
        m2->Release();
    m2 = p;
}


// 0x0015ead0 FUN_0015ead0 (69 B): matches/0x0015ead0.cpp
// sym: ??1GrappleLocomotionSteerAction_15ead0@fn_f94adb62@@QAE@XZ
GrappleLocomotionSteerAction_15ead0::~GrappleLocomotionSteerAction_15ead0() {
    vptr = g_vftable_15ead0;
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
    ((fight::Action *)(Action_15ead0 *)this)->FUN_002326a0();
}


// 0x0015eb20 FUN_0015eb20 (72 B): matches/0x0015eb20.cpp
// sym: ??0ClimbLocomotionAction@fn_f94adb62@@QAE@PAVThing_15eb20@1@@Z
ClimbLocomotionAction::ClimbLocomotionAction(Thing_15eb20* p) {
    mThing = 0;
    m20 = 0;
    m24 = 0;
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}


// 0x0015eb70 FUN_0015eb70 (74 B): matches/0x0015eb70.cpp
// sym: ?f@ClimbLocomotionAction_15eb70@fn_f94adb62@@QAEXXZ
void ClimbLocomotionAction_15eb70::f() {
    vptr = g_vftable_15eb70;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c) {
        m1c->f1();
        m1c = 0;
    }
    ((fight::Action *)(((HeliLocomotionAction_nv_15eb70*)(((hulkfight::motion::HeliLocomotionAction*)(((hulkfight::motion::HeliLocomotionAction*)this)))))))->FUN_002326a0();
}


// 0x0015ebc0 FUN_0015ebc0 (334 B): equivalent/0x0015ebc0.cpp
// sym: ?FUN_0015ebc0@Table_15ebc0@fn_f94adb62@@QAEMMMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 12/12)
// FUN_0015ebc0 @ 0x0015ebc0
hulk_freg Table_15ebc0::FUN_0015ebc0(float t, float a, float b)
{
    if (!(t > 0.0f))
        return 0.0f;
    hulk_freg r1 = FUN_00224fc0(a, b);
    hulk_freg r2 = FUN_0004af40(0.0f, 6.2831855f, r1);
    if (!((*(unsigned int*)&DAT_004e11c0) & 1)) {
        (*(unsigned int*)&DAT_004e11c0) |= 1;
        DAT_004e11bc = 1.5707964f;
    }
    hulk_freg inv = 1.0f / DAT_004e11bc;
    int quad = (int)(inv * r2);
    int i0 = quad % 4;
    int i1 = (i0 + 1) % 4;
    hulk_freg f = (r2 - (float)i0 * DAT_004e11bc) * inv;
    if (!(t > 0.5f)) {
        return ((1.0f - f) * lo[i0] + f * lo[i1]) * (t + t);
    }
    if (t < 1.0f) {
        hulk_freg h = (t - 0.5f) + (t - 0.5f);
        hulk_freg a1 = (1.0f - f) * lo[i0] + f * lo[i1];
        hulk_freg b1 = (1.0f - f) * hi[i0] + f * hi[i1];
        return (1.0f - h) * a1 + b1 * h;
    }
    return ((1.0f - f) * hi[i0] + f * hi[i1]) * t;
}


// 0x0015ed10 hulkfight::motion::ClimbLocomotionAction::vfunc_3 (858 B): equivalent/0x0015ed10.cpp
// sym: ?vfunc_3@ClimbLocomotionAction@fn_f94adb62@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 349 inputs, branch coverage 32/32)
// hulkfight::motion::ClimbLocomotionAction::vfunc_3 @ 0x0015ed10
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ??_R0?AVDriver@choreo2@@@8 = 0x0048d534
// equiv-map: ??_R0?AVLocomotionStrafeDriver@choreo2@@@8 = 0x0048d554
bool ClimbLocomotionAction::vfunc_3(int a, int b)
{
    Frame_15ed10 f;
    Clock_15ed10 *clock = ((Clock_15ed10 *)((owners::Object_592a0 *)target)->FUN_000592a0());
    Timing_15ed10 *timing = clock->FUN_00059a30();
    Skeleton *skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    f.t48 = (hulk_uintptr)timing;
    f.x44 = skel->FUN_002226b0();
    unsigned long long id = id6();
    unsigned int lo = (unsigned int)id;
    f.hi = (unsigned int)(id >> 32);
    f.a = -1.0f;
    f.best = -1.0f;
    f.found = 0;
    for (unsigned int i = 0; i < skel->f68; i++) {
        choreo2::Driver_15ed10 *node = ((choreo2 :: Driver_15ed10 *)((owners::C_222e20 *)skel)->FUN_00222e20((unsigned)i));
        choreo2::LocomotionStrafeDriver_15ed10 *c = dynamic_cast<choreo2::LocomotionStrafeDriver_15ed10 *>(node);
        if (c) {
            if (f.best < 0.0f)
                f.best = c->f24;
            if ((lo | f.hi) != 0 && c->lo == lo && c->hi == f.hi) {
                f.found = c;
                break;
            }
        }
    }
    if (f.found)
        f.found->AddRef();
    if (climb)
        climb->release();
    climb = (Climb *)f.found;

    f.i4c = 0;
    f.i50 = 0;
    f.n24 = 0;
    f.s1c = 0.1f;
    f.s20 = 0.1f;
    f.f28 = f.f2c = f.f30 = f.f34 = f.f38 = f.f3c = f.f40 = -1.0f;
    f.a = -1.0f;
    int x = f.x44;
    gather(x, &f.f40, &f.f3c, &f.f38, &f.f34, &f.f30, &f.f2c, &f.f28, &f.a, &f.i4c, &f.n24, &f.s20, &f.s1c);
    FUN_0015cfd0((void *)(hulk_uintptr)(int)x, (Climb *)climb);
    FUN_0015c780(f.f3c, f.f38, f.f34, f.f30, f.f2c, f.f28);
    if (f.a < 0.0f) {
        f.a = f.best;
        if (f.best < 0.0f)
            f.a = FUN_000964e0();
    }
    climb->f24 = f.a;
    float ft = ((SubSkel *)skel->sub10)->FUN_002220d0();
    climb->f12e0 = ft;
    Timing_15ed10 *tm = (Timing_15ed10 *)f.t48;
    f.q.x = 0.0f;
    f.q.y = 0.0f;
    f.q.z = 0.0f;
    ((owners::C_35660 *)tm)->FUN_00035660((int *)(V3_15ed10 *)(&f.q));
    climb->FUN_002268f0(&f.q);
    f.t48 = *(unsigned int *)&climb->f12e0;
    f.x44 = *(int *)&climb->f12e4;
    float v = FUN_0015ebc0(1.0f, climb->f12e4, climb->f12e0);
    if (v > 0.0f && v < climb->f12e8)
        climb->f12e8 = v;
    if (climb->v7() == 0)
        climb->f18 = 1;
    climb->b12dc = 0;
    climb->b12dd = 0;
    skel->FUN_00222890(climb, f.f40, f.n24, 1.0f, f.s20, f.s1c, -1.0f);

    void *mem = thunk_FUN_0008d690(0x70);
    JointDriver *drv = 0;
    if (mem)
        drv = ((JointDriver *)mem)->FUN_002248f0(0);
    driver = drv;
    ((owners::Target_27b040 *)&(drv->name))->FUN_0027b040((hulk_uintptr)"climbLocomotion");
    driver->f14 = 1;
    driver->AddRef();
    skel->FUN_00222890(driver, -1.0f, f.n24 - 1, 1.0f, f.s20, f.s1c, -1.0f);
    tm->FUN_00035980(1);
    return true;
}

} // namespace fn_f94adb62

// 0x0015f070 hulkfight::motion::ClimbLocomotionAction::vfunc_5 (1290 B): equivalent/0x0015f070.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@ClimbLocomotionAction@motion@hulkfight@fn_0015f070@@UAEDHM@Z
namespace fn_0015f070 {
// STATUS: equivalent (tools/equiv.py level 3: 19967 inputs, branch coverage 26/26)
// hulkfight::motion::ClimbLocomotionAction::vfunc_5 @ 0x0015f070

struct V3_15f070 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_000111b0(const V3_15f070 *a, const V3_15f070 *b);
    hulk_freg FUN_00018990();
};

union FloatBits_15f070 {
    float f;
    unsigned int u;
};

static float AbsF(float v)
{
    FloatBits_15f070 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

extern "C++" __declspec(nothrow) hulk_freg __cdecl FUN_00018a20(float v);
extern "C" bool __cdecl FUN_00018960(float a, float b, float eps);
extern "C" void __cdecl FUN_00224d70(float angle, V3_15f070 *v);
extern "C" hulk_freg __cdecl FUN_00224f10(V3_15f070 *v);

struct Mat_15f070 {
    char data[0x30];
    void FUN_0022baf0(V3_15f070 *axis, float ang);
    void FUN_0022c3b0(V3_15f070 *in, V3_15f070 *out);
};

struct Stats_15f070 {
    char pad0[0x2064];
    V3_15f070 vec2064;
    float f2070;
    char pad2074[0x20a8 - 0x2074];
    int i20a8;
    void FUN_000359c0(int n);
    char FUN_00035550(V3_15f070 *out);
};

struct Pool_15f070 {
    Stats_15f070 *FUN_00059a30();
    void FUN_00059a50(V3_15f070 *out);
};

struct Owner_15f070 {
    Pool_15f070 *FUN_000592a0();
};

struct Transform_15f070 {
    void FUN_0022be40(V3_15f070 *p);
};

struct Rig_15f070 {
    char pad0[0x18];
    Transform_15f070 transform;
};

struct Obj_15f070 {
    char pad0[0x12e0];
    float f12e0;
    float f12e4;
    float f12e8;
};

struct Pair_15f070 {
    V3_15f070 u;
    V3_15f070 t;
    float o0c;
};

struct Loc_15f070 {
    V3_15f070 dir;
    float x;
    V3_15f070 r;
};

namespace hulkfight { namespace motion {

class ClimbLocomotionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(int a0, float a1);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(float *out);
    char pad04[0x18];
    Owner_15f070 *owner;   // 0x1c
    Obj_15f070 *obj;       // 0x20
    Rig_15f070 *rig;       // 0x24
    hulk_freg FUN_0015ebc0(float k, float a, float b);
};

char ClimbLocomotionAction::vfunc_5(int a0, float a1)
{
    if (a0 != 0)
        return 1;
    if (obj == 0)
        return 0;

    Pool_15f070 *pool = owner->FUN_000592a0();
    Stats_15f070 *stats = pool->FUN_00059a30();
    Loc_15f070 loc;
    loc.x = -1.0f;
    vfunc_8(&loc.x);
    stats->FUN_000359c0(4);
    V3_15f070 q;
    pool->FUN_00059a50(&q);
    obj->f12e0 = 0.0f;
    V3_15f070 &dir = loc.dir;
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 0.0f;
    if (!stats->FUN_00035550(&dir))
        return 0;
    dir.y = 0.0f;
    dir.FUN_0022d110();

    float k = stats->f2070;
    if (stats->i20a8 >= 0) {
        if (!(k <= 0.0f)) {
            if (!(k <= 0.5f))
                k = 1.0f;
            else
                k = 0.5f;
        } else {
            k = 0.0f;
        }
    }

    float nm;
    if (!(AbsF(k) <= 1e-5f)) {
        V3_15f070 a = stats->vec2064;
        V3_15f070 b = stats->vec2064;
        double dot = ((double)a.z * dir.z + (double)a.x * dir.x) + (double)a.y * dir.y;
        b.y = (float)(b.y * dot);
        b.z = (float)(b.z * dot);
        a.x = (float)((double)a.x - (double)a.x * dot);
        a.y = a.y - b.y;
        a.z = a.z - b.z;
        a.FUN_0022d110();
        float m = FUN_00018a20(a.y);
        if (FUN_00018960(AbsF(a.y), 1.0f, 1e-5f)) {
            nm = -m;
        } else {
            V3_15f070 up;
            up.x = 0.0f;
            up.y = 1.0f;
            up.z = 0.0f;
            V3_15f070 &r = loc.r;
            r.FUN_000111b0(&a, &up);
            double d2 = ((double)r.z * dir.z + (double)r.x * dir.x) + (double)r.y * dir.y;
            if (d2 > 0.0)
                nm = m;
            else
                nm = -m;
        }
    } else {
        nm = 0.0f;
    }

    float o0 = obj->f12e0;
    float o1 = obj->f12e4;
    float nk = FUN_0015ebc0(k, o1, o0);
    float p1 = obj->f12e4;
    float p2 = obj->f12e8;

    bool direct = false;
    float ang = 0.0f;
    float val = 0.0f;
    float diff = AbsF(p1 - nm);
    if (!(diff <= 1e-5f)) {
        direct = false;
    } else {
        direct = FUN_00018960(p2, nk, 1e-5f);
    }
    if (!direct) {
        Pair_15f070 L;
        L.o0c = diff;
        V3_15f070 &t = L.t;
        V3_15f070 &u = L.u;
        t.x = (*(V3_15f070*)&DAT_004b4d60).x * p2;
        t.y = (*(V3_15f070*)&DAT_004b4d60).y * p2;
        t.z = (*(V3_15f070*)&DAT_004b4d60).z * p2;
        FUN_00224d70(p1, &t);
        u.x = (*(V3_15f070*)&DAT_004b4d60).x * nk;
        u.y = (*(V3_15f070*)&DAT_004b4d60).y * nk;
        u.z = (*(V3_15f070*)&DAT_004b4d60).z * nk;
        FUN_00224d70(nm, &u);
        V3_15f070 w;
        w.x = u.x - t.x;
        w.y = u.y - t.y;
        w.z = u.z - t.z;
        float len = w.FUN_0022d110();
        if (loc.x <= 0.0f) {
            direct = true;
        } else {
            float s = loc.x * a1;
            if (len <= s) {
                direct = true;
            } else {
                struct { hulk_freg x, y; float z; } ws;   // w * s: z is stored (rounded), x and y stay in registers
                ws.x = w.x * s;
                ws.y = w.y * s;
                ws.z = w.z * s;
                w.x = ws.x + t.x;
                w.y = ws.y + t.y;
                w.z = ws.z + t.z;
                ang = FUN_00224f10(&w);
                val = w.FUN_00018990();
            }
        }
    }
    if (direct) {
        ang = nm;
        val = nk;
    }
    obj->f12e4 = ang;
    obj->f12e8 = val;

    Mat_15f070 M;
    M.FUN_0022baf0(&dir, obj->f12e4);
    V3_15f070 r2;
    r2.x = 0.0f;
    r2.y = a1 * obj->f12e8;
    r2.z = 0.0f;
    V3_15f070 out;
    M.FUN_0022c3b0(&r2, &out);
    out.x = out.x + q.x;
    out.y = q.y + out.y;
    out.z = q.z + out.z;
    rig->transform.FUN_0022be40(&out);
    return 1;
}

}}
} // namespace fn_0015f070


// 0x0015f580 FUN_0015f580 (80 B): equivalent/0x0015f580.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0ClimbLocomotion4Action@motion@hulkfight@fn_0015f580@@QAE@HPAVCounted@3@@Z
namespace fn_0015f580 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0015f580 @ 0x0015f580
class Counted {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};

struct CountedRef {
    Counted* p;
    CountedRef() : p(0) {}
    CountedRef& operator=(Counted* q)
    {
        if (q)
            q->AddRef();
        if (p)
            p->Release();
        p = q;
        return *this;
    }
};

namespace fight {
class Action {
public:
    Action() throw();
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int, int);
    virtual void vfunc_4();
    virtual bool vfunc_5(int, int);
    char pad4[0x1c - 4];
};
}

namespace hulkfight {
namespace motion {

class ClimbLocomotionAction : public fight::Action {
public:
    ClimbLocomotionAction(Counted* t);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(void*);
    CountedRef target;
    int f_20;
    int f_24;
};

ClimbLocomotionAction::ClimbLocomotionAction(Counted* t) : f_20(0), f_24(0)
{
    target = t;
}

class ClimbLocomotion4Action : public ClimbLocomotionAction {
public:
    ClimbLocomotion4Action(int v, Counted* t);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(void*);
    char pad28[0x20];
    int f_48;
};

ClimbLocomotion4Action::ClimbLocomotion4Action(int v, Counted* t) : ClimbLocomotionAction(t), f_48(0)
{
    f_48 = v;
}

}
}
} // namespace fn_0015f580

namespace fn_f94adb62 {

// 0x0015f5d0 FUN_0015f5d0 (82 B): matches/0x0015f5d0.cpp
// sym: ??1ClimbLocomotion4Action_15f5d0@fn_f94adb62@@QAE@XZ
ClimbLocomotion4Action_15f5d0::~ClimbLocomotion4Action_15f5d0() throw() {
    vptr = g_vftable_15f5d0;
    _ReadWriteBarrier();
    if (m48)
        m48 = 0;
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(ClimbLocomotionAction_15f5d0 *)this)->FUN_002326a0();
}

} // namespace fn_f94adb62

// 0x0015f630 hulkfight::motion::HeliLocomotionTrack::vfunc_10 (70 B): matches/0x0015f630.cpp
// sym: ?vfunc_10@HeliLocomotionTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0011a1b0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HeliLocomotionTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * p = (void *)__p2;

    int ok = IsType(p, 0, &FightParamsType_15f630, &CFightParamsType_15f630, 0);
    if (ok) {
        Allocated_15f630* x = (Allocated_15f630*)Allocate(0x68);
        if (x)
            return x->Init(this, p);
    }
    return 0;
}

namespace fn_f94adb62 {

// 0x0015f680 FUN_0015f680 (44 B): matches/0x0015f680.cpp
// sym: ?slot0@HeliLocomotionAction_15f680@fn_f94adb62@@UAEXXZ
void HeliLocomotionAction_15f680::slot0() {
    *(void**)this = (void*)((hulk_intptr)DAT_00415b00);
    _ReadWriteBarrier();
    if (p24) {
        p24->f1();
        p24 = 0;
    }
    p20->f1();
    ((fight::Action *)this)->FUN_002326a0();
}


// 0x001606d0 FUN_001606d0 (58 B): matches/0x001606d0.cpp
// sym: ??0LocomotingAction_1606d0@fn_f94adb62@@QAE@PAVRef_1606d0@1@@Z
// Same code shape as 0x00018af0 (propagated; names are from that function)
LocomotingAction_1606d0::LocomotingAction_1606d0(Ref_1606d0* arg) : Action_1606d0() {
    mRef = 0;
    if (arg)
        arg->AddRef();
    if (mRef)
        mRef->Release();
    mRef = arg;
}


// 0x00160710 FUN_00160710 (36 B): matches/0x00160710.cpp
// sym: ??1LocomotingAction_160710@fn_f94adb62@@QAE@XZ
LocomotingAction_160710::~LocomotingAction_160710() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_160710 *)this)->FUN_002326a0();
}

} // namespace fn_f94adb62

// 0x00160760 fight::ParamBool<hulkfight::motion::LocomotingCondition>::vfunc_6 (26 B): matches/0x00160760.cpp
// sym: ?vfunc_6@?$ParamBool@VLocomotingCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::LocomotingCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::LocomotingCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::LocomotingCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::LocomotingCondition>::**)(int))&this->f_10))(b);
}


// 0x00160780 fight::ParamBool<hulkfight::motion::LocomotingCondition>::vfunc_2 (11 B): matches/0x00160780.cpp
// sym: ?vfunc_2@?$ParamBool@VLocomotingCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::LocomotingCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001607b0 fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>::vfunc_6 (26 B): matches/0x001607b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>::**)(int))&this->f_10))(b);
}


// 0x001607d0 fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>::vfunc_2 (11 B): matches/0x001607d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160800 fight::ParamBool<hulkfight::motion::JointPlantedCondition>::vfunc_6 (26 B): matches/0x00160800.cpp
// sym: ?vfunc_6@?$ParamBool@VLocomotingCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::JointPlantedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::JointPlantedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::JointPlantedCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::JointPlantedCondition>::**)(int))&this->f_10))(b);
}


// 0x00160820 fight::ParamBool<hulkfight::motion::JointPlantedCondition>::vfunc_2 (11 B): matches/0x00160820.cpp
// sym: ?vfunc_2@?$ParamBool@VLocomotingCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::JointPlantedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160850 fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>::vfunc_6 (26 B): matches/0x00160850.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>::**)(int))&this->f_10))(b);
}


// 0x00160870 fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>::vfunc_2 (11 B): matches/0x00160870.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001608a0 fight::ParamFloatConstRange<hulkfight::motion::LocomotingTrack>::vfunc_6 (26 B): matches/0x001608a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotingTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotingTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::LocomotingTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotingTrack>::**)(int))&this->f_10))(b);
}


// 0x001608c0 fight::ParamFloatConstRange<hulkfight::motion::LocomotingTrack>::vfunc_2 (11 B): matches/0x001608c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotingTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001608f0 fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_6 (26 B): matches/0x001608f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>::**)(int))&this->f_10))(b);
}


// 0x00160910 fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_2 (11 B): matches/0x00160910.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160940 fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_6 (26 B): matches/0x00160940.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::**)(int))&this->f_10))(b);
}


// 0x00160960 fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_2 (11 B): matches/0x00160960.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160990 fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_6 (26 B): matches/0x00160990.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>::**)(int))&this->f_10))(b);
}


// 0x001609b0 fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_2 (11 B): matches/0x001609b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001609e0 fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>::vfunc_6 (26 B): matches/0x001609e0.cpp
// sym: ?vfunc_6@?$ParamBool@VLocomotingCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>::**)(int))&this->f_10))(b);
}


// 0x00160a00 fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>::vfunc_2 (11 B): matches/0x00160a00.cpp
// sym: ?vfunc_2@?$ParamBool@VLocomotingCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160a30 fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_6 (26 B): matches/0x00160a30.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>::**)(int))&this->f_10))(b);
}


// 0x00160a50 fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_2 (11 B): matches/0x00160a50.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160a80 fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_6 (26 B): matches/0x00160a80.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>::**)(int))&this->f_10))(b);
}


// 0x00160aa0 fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_2 (11 B): matches/0x00160aa0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160ad0 fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>::vfunc_6 (26 B): matches/0x00160ad0.cpp
// sym: ?vfunc_6@?$ParamVector@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>::**)(int))&this->f_10))(b);
}


// 0x00160af0 fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>::vfunc_2 (11 B): matches/0x00160af0.cpp
// sym: ?vfunc_2@?$ParamVector@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160b20 fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_6 (26 B): matches/0x00160b20.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>::**)(int))&this->f_10))(b);
}


// 0x00160b40 fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_2 (11 B): matches/0x00160b40.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160b70 fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_6 (26 B): matches/0x00160b70.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>::**)(int))&this->f_10))(b);
}


// 0x00160b90 fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_2 (11 B): matches/0x00160b90.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160bc0 fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>::vfunc_6 (26 B): matches/0x00160bc0.cpp
// sym: ?vfunc_6@?$ParamBool@VLocomotingCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>::**)(int))&this->f_10))(b);
}


// 0x00160be0 fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>::vfunc_2 (11 B): matches/0x00160be0.cpp
// sym: ?vfunc_2@?$ParamBool@VLocomotingCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160c10 fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_6 (26 B): matches/0x00160c10.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>::**)(int))&this->f_10))(b);
}


// 0x00160c30 fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_2 (11 B): matches/0x00160c30.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160c60 fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_6 (26 B): matches/0x00160c60.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>::**)(int))&this->f_10))(b);
}


// 0x00160c80 fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_2 (11 B): matches/0x00160c80.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160cb0 fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_6 (26 B): matches/0x00160cb0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>::**)(int))&this->f_10))(b);
}


// 0x00160cd0 fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_2 (11 B): matches/0x00160cd0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160d00 fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_6 (26 B): matches/0x00160d00.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::**)(int))&this->f_10))(b);
}


// 0x00160d20 fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_2 (11 B): matches/0x00160d20.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160d50 fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_6 (26 B): matches/0x00160d50.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::**)(int))&this->f_10))(b);
}


// 0x00160d70 fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_2 (11 B): matches/0x00160d70.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00160d90 fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotingCondition>::vfunc_0 (36 B): matches/0x00160d90.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VLocomotingCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b4450, 0) != 0;
}


// 0x00160dc0 fight::ParamBool<hulkfight::motion::LocomotingCondition>::vfunc_0 (30 B): matches/0x00160dc0.cpp
// sym: ??_G?$ParamBool@VLocomotingCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::LocomotingCondition>::~ParamBool() {}


// 0x00160df0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::JointPlantedCondition>::vfunc_0 (36 B): matches/0x00160df0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VJointPlantedCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::JointPlantedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b4508, 0) != 0;
}


// 0x00160e20 fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>::vfunc_0 (30 B): matches/0x00160e20.cpp
// sym: ??_G?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>::~ParamFloatConstRange() {}


// 0x00160e40 fight::ParamBool<hulkfight::motion::JointPlantedCondition>::vfunc_0 (30 B): matches/0x00160e40.cpp
// sym: ??_G?$ParamBool@VJointPlantedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::JointPlantedCondition>::~ParamBool() {}


// 0x00160e70 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PhaseCondition>::vfunc_0 (36 B): matches/0x00160e70.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPhaseCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PhaseCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b45c0, 0) != 0;
}


// 0x00160ea0 fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>::vfunc_0 (30 B): matches/0x00160ea0.cpp
// sym: ??_G?$ParamFloatConstRange@VPhaseCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>::~ParamFloatConstRange() {}


// 0x00160ed0 fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotingTrack>::vfunc_0 (36 B): matches/0x00160ed0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VLocomotingTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotingTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_004b4670, 0) != 0;
}


// 0x00160f00 fight::ParamFloatConstRange<hulkfight::motion::LocomotingTrack>::vfunc_0 (30 B): matches/0x00160f00.cpp
// sym: ??_G?$ParamFloatConstRange@VLocomotingTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::LocomotingTrack>::~ParamFloatConstRange() {}


// 0x00160f30 fight::TrackFactoryCasterTemplate<hulkfight::motion::ClimbLocomotion4Track>::vfunc_0 (36 B): matches/0x00160f30.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ClimbLocomotion4Track>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b4720, 0) != 0;
}


// 0x00160f60 fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_0 (30 B): matches/0x00160f60.cpp
// sym: ??_G?$ParamFloatConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>::~ParamFloatConstRange() {}


// 0x00160f80 fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_0 (30 B): matches/0x00160f80.cpp
// sym: ??_G?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::~ParamIntConstRange() {}


// 0x00160fb0 fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0 (36 B): matches/0x00160fb0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b47d8, 0) != 0;
}


// 0x00160fe0 fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0 (30 B): matches/0x00160fe0.cpp
// sym: ??_G?$ParamFloatConstRange@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>::~ParamFloatConstRange() {}


// 0x00161000 fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0 (30 B): matches/0x00161000.cpp
// sym: ??_G?$ParamBool@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>::~ParamBool() {}


// 0x00161020 fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0 (30 B): matches/0x00161020.cpp
// sym: ??_G?$ParamIntConstRange@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>::~ParamIntConstRange() {}


// 0x00161050 fight::TrackFactoryCasterTemplate<hulkfight::motion::HeliLocomotionTrack>::vfunc_0 (36 B): matches/0x00161050.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HeliLocomotionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_161050, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00161080 fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_0 (30 B): matches/0x00161080.cpp
// sym: ??_G?$ParamFloatConstRange@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>::~ParamFloatConstRange() {}


// 0x001610a0 fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>::vfunc_0 (30 B): matches/0x001610a0.cpp
// sym: ??_G?$ParamVector@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>::~ParamVector() {}


// 0x001610c0 fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_0 (30 B): matches/0x001610c0.cpp
// sym: ??_G?$ParamIntConstRange@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>::~ParamIntConstRange() {}


// 0x001610f0 fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionSteerTrack>::vfunc_0 (36 B): matches/0x001610f0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VLocomotionSteerTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionSteerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b4948, 0) != 0;
}


// 0x00161120 fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161120.cpp
// sym: ??_G?$ParamFloatConstRange@VLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>::~ParamFloatConstRange() {}


// 0x00161140 fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161140.cpp
// sym: ??_G?$ParamBool@VLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>::~ParamBool() {}


// 0x00161160 fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161160.cpp
// sym: ??_G?$ParamIntConstRange@VLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>::~ParamIntConstRange() {}


// 0x00161190 fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionSprintTrack>::vfunc_0 (36 B): matches/0x00161190.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VLocomotionSprintTrack@motion@hulkfight@fn_00161190@@@fight@fn_00161190@@UAEHPAX@Z
namespace fn_00161190 {
extern int gA, gB;
extern "C++" __declspec(nothrow) int __cdecl check(void*, int, const void*, const void*, int);
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
class LocomotionSprintTrack;
}
} // namespace hulkfight
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionSprintTrack>::vfunc_0(void* p) {
    return check(p, 0, &gA, &gB, 0) != 0;
}
} // namespace fn_00161190


// 0x001611c0 fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_0 (30 B): matches/0x001611c0.cpp
// sym: ??_G?$ParamFloatConstRange@VLocomotionSprintTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>::~ParamFloatConstRange() {}


// 0x001611e0 fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_0 (30 B): matches/0x001611e0.cpp
// sym: ??_G?$ParamIntConstRange@VLocomotionSprintTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>::~ParamIntConstRange() {}


// 0x00161210 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_0 (36 B): matches/0x00161210.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGrappleLocomotionSteerTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b4ac0, 0) != 0;
}


// 0x00161240 fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161240.cpp
// sym: ??_G?$ParamFloatConstRange@VGrappleLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::~ParamFloatConstRange() {}


// 0x00161260 fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161260.cpp
// sym: ??_G?$ParamIntConstRange@VGrappleLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::~ParamIntConstRange() {}

namespace fn_f94adb62 {

// 0x00161280 FUN_00161280 (95 B): equivalent/0x00161280.cpp
// sym: _FUN_00161280
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_00161280 @ 0x00161280
extern "C" void FUN_00161280()
{
    if (DAT_004e115c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_161280<hulkfight::motion::LocomotingCondition_161280>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_161280<hulkfight::motion::LocomotingCondition_161280>("isLocomoting", &hulkfight::motion::LocomotingCondition_161280::FUN_0015a820);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1158), params, 1);
    }
    DAT_004e115c++;
}


// 0x001612e0 FUN_001612e0 (158 B): equivalent/0x001612e0.cpp
// sym: _FUN_001612e0
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001612e0 @ 0x001612e0
extern "C" void FUN_001612e0()
{
    if (DAT_004e116c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1612e0<hulkfight::motion::PhaseCondition_1612e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1612e0<hulkfight::motion::PhaseCondition_1612e0>("phase", &hulkfight::motion::PhaseCondition_1612e0::FUN_0015a870);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1612e0<hulkfight::motion::PhaseCondition_1612e0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1612e0<hulkfight::motion::PhaseCondition_1612e0>("arc", &hulkfight::motion::PhaseCondition_1612e0::FUN_0015a890);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1168), params, 2);
    }
    DAT_004e116c++;
}


// 0x00161380 FUN_00161380 (158 B): equivalent/0x00161380.cpp
// sym: _FUN_00161380
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00161380 @ 0x00161380
extern "C" void FUN_00161380()
{
    if (DAT_004e1174 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161380<hulkfight::motion::LocomotingTrack_161380>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_161380<hulkfight::motion::LocomotingTrack_161380>("timeBegin", &hulkfight::motion::LocomotingTrack_161380::FUN_0015a8a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161380<hulkfight::motion::LocomotingTrack_161380>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_161380<hulkfight::motion::LocomotingTrack_161380>("timeEnd", &hulkfight::motion::LocomotingTrack_161380::FUN_0015a8b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1170), params, 2);
    }
    DAT_004e1174++;
}


// 0x00161420 hulkfight::motion::LocomotionStrafeAction::vfunc_2 (76 B): matches/0x00161420.cpp
// sym: ?vfunc_2@LocomotionStrafeAction@fn_f94adb62@@UAEPAXE@Z
void* LocomotionStrafeAction::vfunc_2(unsigned char flag) {
    *(volatile hulk_intptr*)this = (hulk_intptr)&g_vt_161420;
    RefObj_161420* p = m20;
    if (p) {
        p->Release();
        m20 = 0;
    }
    p = m1c;
    if (p) {
        p->Release();
        m1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}

} // namespace fn_f94adb62

// 0x00161470 hulkfight::motion::LocomotionStrafe4Track::vfunc_10 (40 B): matches/0x00161470.cpp
// sym: ?vfunc_10@LocomotionStrafe4Track@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::LocomotionStrafe4Track::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    void* p = FUN_0008d690(0x48);
    if (p)
        return ((Helper_161470*)p)->run(this, c);
    return 0;
}

namespace fn_f94adb62 {

// 0x001614a0 hulkfight::motion::LocomotionStrafe4Action::vfunc_2 (96 B): matches/0x001614a0.cpp
// sym: ?f2@LocomotionStrafe4Action_1614a0@fn_f94adb62@@QAEPAV12@E@Z
LocomotionStrafe4Action_1614a0* LocomotionStrafe4Action_1614a0::f2(unsigned char fl) {
    vptr = g_vftable_1614a0;
    _ReadWriteBarrier();
    if (m44)
        m44 = 0;
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(LocomotionStrafeAction_1614a0 *)this)->FUN_002326a0();
    if (fl & 1)
        Free(this);
    return this;
}

} // namespace fn_f94adb62

// 0x00161500 hulkfight::motion::LocomotionSprintTrack::vfunc_10 (40 B): matches/0x00161500.cpp
// sym: ?vfunc_10@LocomotionSprintTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::LocomotionSprintTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    Result_161500* p = Alloc(0x30);
    if (p)
        return p->Init(this, c);
    return 0;
}

namespace fn_f94adb62 {

// 0x00161530 hulkfight::motion::LocomotionSprintAction::vfunc_2 (90 B): matches/0x00161530.cpp
// sym: ?vfunc_2@LocomotionSprintAction_161530@fn_f94adb62@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* LocomotionSprintAction_161530::vfunc_2(unsigned char flag) {
    volatile LocomotionSprintAction_161530* self = this;
    self->mVptr = &g_vftable_161530;
    RefObj_161530* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_161530* t2 = self->m2;
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


// 0x001615c0 hulkfight::motion::LocomotionSteerAction::vfunc_2 (90 B): matches/0x001615c0.cpp
// sym: ?vfunc_2@LocomotionSteerAction_1615c0@fn_f94adb62@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* LocomotionSteerAction_1615c0::vfunc_2(unsigned char flag) {
    volatile LocomotionSteerAction_1615c0* self = this;
    self->mVptr = &g_vftable_1615c0;
    RefObj_1615c0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_1615c0* t2 = self->m2;
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

} // namespace fn_f94adb62

// 0x00161620 hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_10 (58 B): matches/0x00161620.cpp
// sym: ?vfunc_10@GrappleLocomotionSteerTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int value = FUN_0005a470(c);
    if (value) {
        Result_161620* p = (Result_161620*)Allocate(0x30);
        if (p)
            return p->Build(this, value);
    }
    return 0;
}

namespace fn_f94adb62 {

// 0x00161660 hulkfight::motion::GrappleLocomotionSteerAction::vfunc_2 (90 B): matches/0x00161660.cpp
// sym: ?vfunc_2@GrappleLocomotionSteerAction_161660@fn_f94adb62@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* GrappleLocomotionSteerAction_161660::vfunc_2(unsigned char flag) {
    volatile GrappleLocomotionSteerAction_161660* self = this;
    self->mVptr = &g_vftable_161660;
    RefObj_161660* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_161660* t2 = self->m2;
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

} // namespace fn_f94adb62

// 0x00161720 hulkfight::motion::ClimbLocomotion4Track::vfunc_10 (40 B): matches/0x00161720.cpp
// sym: ?vfunc_10@ClimbLocomotion4Track@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::ClimbLocomotion4Track::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    Helper_161720* p = FUN_0008d690(0x4c);
    if (p)
        return p->f(this, c);
    return 0;
}


// 0x00161750 hulkfight::motion::ClimbLocomotion4Action::vfunc_2 (30 B): matches/0x00161750.cpp
// sym: ??_GClimbLocomotion4Action@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::ClimbLocomotion4Action::~ClimbLocomotion4Action() {}

namespace fn_f94adb62 {

// 0x00161770 hulkfight::motion::HeliLocomotionAction::vfunc_2 (65 B): matches/0x00161770.cpp
// sym: ?f2@HeliLocomotionAction_161770@fn_f94adb62@@QAEPAV12@E@Z
HeliLocomotionAction_161770* HeliLocomotionAction_161770::f2(unsigned char flags) {
    vptr = g_vftable_161770;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    m20->f1();
    ((fight::Action *)(((HeliLocomotionAction_nv_161770*)(((hulkfight::motion::HeliLocomotionAction*)this)))))->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00161800 hulkfight::motion::LocomotingAction::vfunc_2 (57 B): matches/0x00161800.cpp
// sym: ?V2@LocomotingAction@fn_f94adb62@@QAEPAV12@H@Z
LocomotingAction* LocomotingAction::V2(int flags) {
    vptr = ((hulk_intptr)DAT_00415c50);
    _ReadWriteBarrier();
    if (mObj) {
        mObj->V1();
        mObj = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flags & 1)
        thunk(this);
    return this;
}


// 0x001618a0 fight::ParamNameConstList<hulkfight::motion::JointPlantedCondition>::vfunc_7 (12 B): matches/0x001618a0.cpp
// sym: ?vfunc_6@ParamBranch@fn_f94adb62@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f94adb62

// 0x00161930 fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>::vfunc_7 (12 B): matches/0x00161930.cpp [wrapped: same definition as 0x001618a0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00161930@@UAEXPAX@Z
namespace fn_00161930 {
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
} // namespace fn_00161930


// 0x00161980 fight::ParamName<hulkfight::motion::LocomotionStrafe4Track>::vfunc_7 (12 B): matches/0x00161980.cpp [wrapped: same definition as 0x001618a0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00161980@@UAEXPAX@Z
namespace fn_00161980 {
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
} // namespace fn_00161980


// 0x001619d0 fight::ParamName<hulkfight::motion::HeliLocomotionTrack>::vfunc_7 (12 B): matches/0x001619d0.cpp [wrapped: same definition as 0x001618a0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001619d0@@UAEXPAX@Z
namespace fn_001619d0 {
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
} // namespace fn_001619d0

namespace fn_f94adb62 {

// 0x00161a00 FUN_00161a00 (32 B): matches/0x00161a00.cpp
// sym: ??0ParamName_161a00@fn_f94adb62@@QAE@HH@Z
ParamName_161a00::ParamName_161a00(int a, int b) : ParamValueName_161a00(a) {
    m10 = b;
}

} // namespace fn_f94adb62

// 0x00161a20 fight::ParamName<hulkfight::motion::LocomotionSteerTrack>::vfunc_7 (12 B): matches/0x00161a20.cpp [wrapped: same definition as 0x001618a0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00161a20@@UAEXPAX@Z
namespace fn_00161a20 {
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
} // namespace fn_00161a20


// 0x00161a70 fight::ParamName<hulkfight::motion::LocomotionSprintTrack>::vfunc_7 (12 B): matches/0x00161a70.cpp [wrapped: same definition as 0x001618a0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00161a70@@UAEXPAX@Z
namespace fn_00161a70 {
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
} // namespace fn_00161a70


// 0x00161ac0 fight::ParamName<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_7 (12 B): matches/0x00161ac0.cpp [wrapped: same definition as 0x001618a0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00161ac0@@UAEXPAX@Z
namespace fn_00161ac0 {
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
} // namespace fn_00161ac0


// 0x00161ad0 fight::ParamNameConstList<hulkfight::motion::JointPlantedCondition>::vfunc_0 (30 B): matches/0x00161ad0.cpp
// sym: ??_G?$ParamNameConstList@VJointPlantedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::JointPlantedCondition>::~ParamNameConstList() {}


// 0x00161af0 fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>::vfunc_0 (30 B): matches/0x00161af0.cpp
// sym: ??_G?$ParamName@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>::~ParamName() {}


// 0x00161b10 fight::ParamName<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0 (30 B): matches/0x00161b10.cpp
// sym: ??_G?$ParamName@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::LocomotionStrafe4Track>::~ParamName() {}


// 0x00161b30 fight::ParamName<hulkfight::motion::HeliLocomotionTrack>::vfunc_0 (30 B): matches/0x00161b30.cpp
// sym: ??_G?$ParamName@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::HeliLocomotionTrack>::~ParamName() {}


// 0x00161b50 fight::ParamName<hulkfight::motion::LocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161b50.cpp
// sym: ??_G?$ParamName@VLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::LocomotionSteerTrack>::~ParamName() {}


// 0x00161b70 fight::ParamName<hulkfight::motion::LocomotionSprintTrack>::vfunc_0 (30 B): matches/0x00161b70.cpp
// sym: ??_G?$ParamName@VLocomotionSprintTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::LocomotionSprintTrack>::~ParamName() {}


// 0x00161b90 fight::ParamName<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161b90.cpp
// sym: ??_G?$ParamName@VGrappleLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::GrappleLocomotionSteerTrack>::~ParamName() {}

