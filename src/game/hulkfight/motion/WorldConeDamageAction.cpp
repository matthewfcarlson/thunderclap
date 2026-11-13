// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00143100..0x00146900 (kind game, layer game, confidence high), dominant class hulkfight::motion::WorldConeDamageAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3c8e3e3 {
#define TREE_TU_END }
namespace fn_f3c8e3e3 {} using namespace fn_f3c8e3e3;
namespace fn_f3c8e3e3 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
namespace fn_f3c8e3e3 { extern "C" char DAT_00412f14[], DAT_00412f74[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
namespace fn_f3c8e3e3 { extern "C" char DAT_00413034[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f3c8e3e3 {
union FloatBits_143100 {
    float f;
    unsigned int u;
};
struct Sub_1431e0 {
    char b[0x28];
};
struct Obj_1431e0 {
    Sub_1431e0* Get();
};
class Obj_1432f0 {
  public:
    char pad[16];
};
struct Src_143360 {
    int a;
    int b;
    int c;
};
class C_143360 {
  public:
    char pad[0x24];
    int m24;
    int m28;
    int m2c;
    bool Set(Src_143360* p);
};
class Obj_1433b0 {
  public:
    virtual void A();
    char pad[0x30];
    int m;
    char Set(int x);
};
struct Vec3_143430 {
    int x, y, z;
};
struct Obj_143430 {
    char pad[0x10];
    Vec3_143430 v;
    bool Set(const Vec3_143430* other);
};
struct Vec {
    int x, y, z;
};
class Obj {
  public:
    char _m_pad_0[0x14];
    int value;
    char _m_pad_18[0x4];
    int x;
    int y;
    int z;
    bool Set(Vec* p);
    char Set(int v);
    void Set_002367c0(void*);
};
struct Vec3_1434b0 {
    float x, y, z;
};
class Obj_1434b0 {
  public:
    char pad[0x28];
    float a, b, c;
    char Set(Vec3_1434b0* v);
};
class X_143630 {
  public:
    char pad[0x10];
    unsigned int value;
    bool Set(unsigned int v);
};
class A_143670 {
  public:
    char pad[0x18];
    int m18;
    bool Set(int x);
};
class C_143690 {
    char pad[0x1c];

  public:
    char Set(unsigned int x);
};
class Obj_1436b0 {
  public:
    char m[0x20];
    char Set(int value);
};
extern int* hulk_at_004e0f80;
class CCondition_143710 {
  public:
    virtual int vfunc_0(int);
};
typedef unsigned int u32_143790;
extern u32_143790 hulk_at_00412f14;
struct Sub_143790 {
    void Init_0027af50();
};
struct Base_143790 {
    void Finish_00236d60();
};
extern int* hulk_at_004e0f88;
class CCondition_1437e0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0f90;
class CCondition_143880 {
  public:
    virtual int vfunc_0(int);
};
extern int hulk_at_00412f74;
class Inner_143900 {
  public:
    void Init_0027af50();
};
class WorldDamageTrack {
  public:
    int* vptr;
    char pad[12];
    Inner_143900 inner;
    void BaseFn_00236d60();
    void Fn();
};
extern int* hulk_at_004e0f98;
class CCondition_143940 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0fa0;
class CCondition_143a10 {
  public:
    virtual int vfunc_0(int);
};
HULK_REFCOUNT_PACK   // (x64t7) pure3d::NonCopyable's stand-in: 12 bytes natively (compat/ptr.h)
class Track_143a20 {
  public:
    Track_143a20();
    virtual hulk_intptr Fnf_00143a10(int);
    char pad[4];
};
HULK_REFCOUNT_PACK_END
class MotionBlurTrack : public Track_143a20 {
  public:
    MotionBlurTrack();
    char p[4];
    int a;
    float x, y, z;
    int b, c;
};
extern int* hulk_at_004e0fa8;
class CCondition_143ab0 {
  public:
    virtual int vfunc_0(int);
};
class Track_143ac0 {
  public:
    Track_143ac0();
    virtual hulk_intptr Fnf_00143ab0(int);
    char pad[4];
};
class MotionTrailStopTrack : public Track_143ac0 {
  public:
    MotionTrailStopTrack();
    int a;
    int b;
    int c;
};
struct V3_143b20 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(const V3_143b20 *other, float eps);
};
struct Matrix_143b20 {
    float m[16];
};
struct Skeleton_143b20 {
    char pad0[0x1c];
    Matrix_143b20 *mats;
    unsigned int FUN_002843a0(unsigned int lo, unsigned int hi);
};
struct Entity_143b20 {
    char pad0[0x120];
    Skeleton_143b20 *skel;
    void FUN_00035160(Matrix_143b20 *out);
    void FUN_00035630(V3_143b20 *in, V3_143b20 *out);
    hulk_freg FUN_000354c0();
};
struct Anchor_143b20 {
    void FUN_00059a50(V3_143b20 *out);
};
struct Handle_143b20 {
    Entity_143b20 *FUN_00059a30();
};
struct Caster_143b20 {
    bool FUN_00202460(V3_143b20 *origin, V3_143b20 *dir, float len, int mask, V3_143b20 *hit, V3_143b20 *normal, void **ptr1, void **ptr2);
};
struct Sweeper_143b20 {
    void FUN_001f6cd0(void *p1, void *p2, V3_143b20 *hit, V3_143b20 *normal, V3_143b20 *dir, int n, int a, int b, int *outv, int z);
};
struct Sink_143b20 {
};
} // namespace fn_f3c8e3e3
struct World {
    char pad0[0x24];
    Caster_143b20 *caster;     // 0x24
    char pad28[0xc];
    Sink_143b20 *sink;         // 0x34
    Sweeper_143b20 *sweeper;   // 0x38
};
namespace fn_f3c8e3e3 {
struct Owner_143b20 {
};
struct Data_143b20 {
    char pad0[0x10];
    unsigned int idLo;
    unsigned int idHi;
    V3_143b20 posA;            // 0x18
    V3_143b20 vecB;            // 0x24
    float length;       // 0x30
    int count;          // 0x34
    int f38;
    int f3c;
};
void __cdecl FUN_00224d70(float angle, V3_143b20 *v);
struct MotionSource {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual float vfunc_6();
    char pad[0x1c - 4];
    float value;
};
class Action_1442f0 {
    char pad[0x20];

  public:
    int value;
};
struct Receiver_1442f0 {
    void call_00086100(int);
};
struct GlobalObj_1442f0 {
    char pad[0x58];
    Receiver_1442f0* member;
};
extern GlobalObj_1442f0* hulk_at_004dd700;
extern const float hulk_at_003f32e0;
struct MotionState_144310 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual float f6();
    char pad[0x1c - 4];
    float value;
};
struct Registry_144310 {
    void FUN_001c3840(void*, void*);
};
Registry_144310* FUN_001c3d90();
struct X_144590 {
    X_144590* Fna_000592a0();
    X_144590* Fnb_00059a30();
    void Fne_002834e0(int);
};
extern "C" X_144590* __cdecl FUN_0027f250();
class MotionTrailStopAction {
  public:
    char pad00[0x1c];
    struct A {
        char pad[0x10];
        int value;
    }* mA;
    hulk_intptr mCheck;
    void vfunc_4();
};
typedef unsigned char byte_1447b0;
class Sub_1447b0 {
  public:
    void Fnf_0027af50();
};
class Base_1447b0 {
  public:
    void Fng_00236d60();
};
extern void cdel_0008d330(void*);
extern int vftable_1447b0;
class HitEffectTrack_1447b0 {
  public:
    hulk_intptr vf;
    char pad1[0x18 - 4];
    Sub_1447b0 a;
    char pad2[0x28 - 0x18 - 1];
    Sub_1447b0 b;
    HitEffectTrack_1447b0* vfunc_5(byte_1447b0 param);
};
extern void* hulk_at_00412f44[];
class Track_1447f0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class SlowMotionTrack_1447f0 : public Track_1447f0 {
  public:
    SlowMotionTrack_1447f0* vfunc_5(signed char flags);
};
extern char threat_vftable_144820;
struct Obj_144820 {
    int x;
    void f1_0027af50();
    void f2_00236d60();
};
extern void thunk_FUN_00267090(Obj_144820*);
class WorldDamageTrack_144820 {
  public:
    void* vftable;
    char pad[0x0c];
    WorldDamageTrack_144820* vfunc_5(unsigned char);
};
extern void* hulk_at_00412fa4[];
class Track_144850 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class WorldConeDamageTrack_144850 : public Track_144850 {
  public:
    WorldConeDamageTrack_144850* vfunc_5(signed char flags);
};
extern void* hulk_at_00412fd4[];
class Track_144880 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class MotionBlurTrack_144880 : public Track_144880 {
  public:
    MotionBlurTrack_144880* vfunc_5(signed char flags);
};
extern void* hulk_at_00413004[];
class Track_1448b0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class MotionTrailStopTrack_1448b0 : public Track_1448b0 {
  public:
    MotionTrailStopTrack_1448b0* vfunc_5(signed char flags);
};
class RefObj_1448e0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1448e0 {
  public:
    Action_1448e0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class WorldDamageAction_1448e0 : public Action_1448e0 {
  public:
    int mTarget;
    RefObj_1448e0* mObj;
    WorldDamageAction_1448e0(int target, RefObj_1448e0* obj);
    virtual void Execute_00018b40();
};
class Ref_144930 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_144930 {
  public:
    void* vptr;
};
class WorldDamageAction_144930 : public Action_144930 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_144930* m20;
    ~WorldDamageAction_144930() throw();
};
class Params_144970 {
  public:
    int x;
};
extern Params_144970 hulk_at_00494b44;
extern Params_144970 hulk_at_00494b60;
class Object_144970 {
  public:
    int Init_001448e0(hulkfight::motion::WorldDamageTrack*, hulk_intptr);
};
Object_144970* __cdecl Alloc_0008d690(int);
class RefObj_1449c0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1449c0 {
  public:
    Action_1449c0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class WorldConeDamageAction_1449c0 : public Action_1449c0 {
  public:
    int mTarget;
    RefObj_1449c0* mObj;
    WorldConeDamageAction_1449c0(int target, RefObj_1449c0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00413050[];
class Ref_144a10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_144a10 {
  public:
    void* vptr;
};
class WorldConeDamageAction_144a10 : public Action_144a10 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_144a10* m20;
    ~WorldConeDamageAction_144a10();
};
class Action_144aa0 {
  public:
    virtual void FnF_00018b30();
    char pad[0x18];
    Action_144aa0();
};
class SlowMotionAction_144aa0 : public Action_144aa0 {
  public:
    int value;
    SlowMotionAction_144aa0(int);
};
extern "C" char DAT_0041306c[];
typedef unsigned int u32_144af0;
void* __cdecl Alloc(hulk_uintptr);
struct SlowMotionAction_144af0 {
    void init_00232660();
    char pad[0x1c];
    void* volatile owner;
};
struct Track_144af0 {
    char pad[0x1c];
};
class Action_144b30 {
  public:
    virtual void FnF_00018b30();
    char pad[0x18];
    Action_144b30();
};
class MotionBlurAction : public Action_144b30 {
  public:
    virtual void m_vf1_00018b40();
    virtual MotionBlurAction* vfunc_2(int);
    virtual bool m_vf3_00144310(hulk_intptr, hulk_intptr);
    virtual void m_vf4_00144570();
    virtual bool m_vf5_00144360(int, float);
    MotionBlurAction(int);
    union { int mObject; int value; };
};
class RefObj_144b80 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_144b80 {
  public:
    Action_144b80();
    virtual void Update_00018b30();
    char pad[0x18];
};
class MotionTrailStopAction_144b80 : public Action_144b80 {
  public:
    int mTarget;
    RefObj_144b80* mObj;
    MotionTrailStopAction_144b80(int target, RefObj_144b80* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_004130a4[];
class Ref_144bd0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_144bd0 {
  public:
    void* vptr;
};
class MotionTrailStopAction_144bd0 : public Action_144bd0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_144bd0* m20;
    ~MotionTrailStopAction_144bd0();
};
class Action_144c10 {
  public:
    virtual void FnV_00018b30();
    char pad[0x18];
    Action_144c10();
};
class Ref_144c10 {
  public:
    virtual void Add();
    virtual void Release();
};
class HitEffectAction : public Action_144c10 {
  public:
    Ref_144c10* a;
    int b;
    Ref_144c10* c;
    virtual void FnW_00018b40();
    HitEffectAction(Ref_144c10*, int, Ref_144c10*);
};
extern void* hulk_at_004130c0[];
class Ref_144c80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_144c80 {
  public:
    void* vptr;
};
class HitEffectAction_144c80 : public Action_144c80 {
  public:
    char pad[0x18];
    Ref_144c80* m1c;
    void* m20;
    Ref_144c80* m24;
    ~HitEffectAction_144c80();
};
class Effect_144cd0 {
  public:
    int init_00144c10(hulk_intptr, hulkfight::motion::HitEffectTrack*, hulk_intptr);
};
extern void* alloc_0008d690(unsigned int);
extern const char type1_144cd0[];
extern const char type2_144cd0[];
class CStageCondition_144d60;
class ParamValue_144d60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_144d60 : public ParamValue_144d60 {
  public:
    int pad;
};
class CStageCondition_144db0;
class ParamValue_144db0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_144db0 : public ParamValue_144db0 {
  public:
    int pad;
};
class CStageCondition_144e00;
class ParamValue_144e00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_144e00 : public ParamValue_144e00 {
  public:
    int pad;
};
class CStageCondition_144e50;
class ParamValue_144e50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_144e50 : public ParamValue_144e50 {
  public:
    int pad;
};
class CStageCondition_144ea0;
class ParamValue_144ea0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_144ea0 : public ParamValue_144ea0 {
  public:
    int pad;
};
class CStageCondition_144ef0;
class ParamValue_144ef0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_144ef0 : public ParamValue_144ef0 {
  public:
    int pad;
};
struct CAxisArcCondition_144f30;
class CStageCondition_144f40 {};
class ParamValue_144f40 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_144f40 : public ParamValue_144f40 {
  public:
    virtual void f();
};
class CStageCondition_144fd0;
class ParamValue_144fd0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_144fd0 : public ParamValue_144fd0 {
  public:
    int pad;
};
class CStageCondition_145020;
class ParamValue_145020 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_145020 : public ParamValue_145020 {
  public:
    int pad;
};
class CStageCondition_145070;
class ParamValue_145070 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_145070 : public ParamValue_145070 {
  public:
    int pad;
};
struct CAxisArcCondition_1450b0;
class CStageCondition_1450c0 {};
class ParamValue_1450c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1450c0 : public ParamValue_1450c0 {
  public:
    virtual void f();
};
class CStageCondition_145150;
class ParamValue_145150 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_145150 : public ParamValue_145150 {
  public:
    int pad;
};
class CStageCondition_1451a0;
class ParamValue_1451a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1451a0 : public ParamValue_1451a0 {
  public:
    int pad;
};
class CStageCondition_1451f0;
class ParamValue_1451f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1451f0 : public ParamValue_1451f0 {
  public:
    int pad;
};
extern char DAT_0049850c;
extern char DAT_004adef0;
} // namespace fn_f3c8e3e3
namespace fight {
class TrackFactoryCaster_145210 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitEffectTrack_145210;
} }
namespace fn_f3c8e3e3 {
extern char DAT_004adf98;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f3c8e3e3
namespace fight {
class TrackFactoryCaster_145290 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class SlowMotionTrack_145290;
} }
namespace fight {
class TrackFactoryCaster_145310 {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class WorldDamageTrack_145310 {};
} }
namespace fn_f3c8e3e3 {
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_004ae040;
extern char DAT_004ae0f0;
} // namespace fn_f3c8e3e3
namespace fight {
class TrackFactoryCaster_1453b0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class MotionBlurTrack_145470 {};
} }
namespace fn_f3c8e3e3 {
extern char DAT_004ae1a0;
} // namespace fn_f3c8e3e3
namespace fight {
class TrackFactoryCaster_145470 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f3c8e3e3 {
extern char DAT_004ae250;
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(hulk_intptr, int, void*, void*, int);
class TrackFactoryCaster_1454d0 {
  public:
    virtual bool vfunc_0(int);
    virtual void vfunc_1();
};
struct RefCounted_145ba0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00413034[];
class WorldDamageAction_145ba0 {
  public:
    WorldDamageAction_145ba0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_145ba0* m_20;
};
struct RefCounted_145bf0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_145bf0[];
class WorldConeDamageAction_145bf0 {
  public:
    WorldConeDamageAction_145bf0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_145bf0* m_20;
};
typedef unsigned int u32_145c40;
struct SlowMotionAction {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual SlowMotionAction* vfunc_2(unsigned char flags);
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    char _m_pad_4[0x18];
    union { u32_145c40 member; MotionSource* source; };
    float factor;
    float measured;
    bool vfunc_3(int a, int b);
};
void destroy_0008d330(SlowMotionAction* p);
extern void* hulk_at_00413088[];
class BaseAction {
  public:
    BaseAction();
    virtual void a();
    virtual void b();
    char pad[0x18];
};
class MBAction : public BaseAction {
  public:
    void* owner;
    char pad2[0x2c - 0x20 - 4 - 0];
};
extern void* motionVtable[];
extern void DeleteThunk_0008d330(MotionBlurAction*);
struct RefCounted_145d50 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_145d50[];
class MotionTrailStopAction_145d50 {
  public:
    MotionTrailStopAction_145d50* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_145d50* m_20;
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class TrackFactoryCasterTemplate_146130 {
  public:
    virtual bool Cast_00145290(void*);
};
extern void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_146130*);
class Factory {
  public:
    void Add_002367c0(void*);
};
class TrackFactoryCasterTemplate_146370 {
  public:
    virtual bool Cast_001453b0(void*);
};
extern void* Find_00236ac0(const char*, TrackFactoryCasterTemplate_146370*);
} // namespace fn_f3c8e3e3
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f3c8e3e3 {
class TrackFactoryTemplate_1464e0 {
  public:
    TrackFactoryTemplate_1464e0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00412f44[];
struct SlowMotionTrack {
    char pad0[8];
    int refs;
    int zero;
    float d;
    float e;
    float a;
    float b;
    char flag;
    void Init_00236d40();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_0041349c;
class TrackFactoryTemplate_1465b0 {
  public:
    TrackFactoryTemplate_1465b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
struct TrackFactory_1465f0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct Built_1465f0 {
    void* init_00143950();
};
class TrackFactoryTemplate_146640 {
  public:
    TrackFactoryTemplate_146640() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class TrackFactoryTemplate_146710 {
  public:
    TrackFactoryTemplate_146710() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00413004[];
class Motion_146750 {
  public:
    void Init_00236d40();
};
class TrackFactoryTemplate_1467c0 {
  public:
    TrackFactoryTemplate_1467c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class Track_146800 {
  public:
    hulk_intptr method_00143720();
};
extern void* __cdecl operator_new(unsigned int);
class TrackFactoryTemplate_146850 {
  public:
    TrackFactoryTemplate_146850() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_146890;
struct Grapple_146890 {
    hulk_uintptr BuildTrack_00143890();
};

} // namespace fn_f3c8e3e3

// 0x00143100 FUN_00143100 (103 B): equivalent/0x00143100.cpp
// sym: ?FUN_00143100@RandomGen_143100@owners@@QAEMXZ @524a37e27e33 @wee527563539a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00143100 @ 0x00143100
float owners::RandomGen_143100::FUN_00143100() {
    z = (z & 0xffff) * 0x9069 + (z >> 16);
    w = (w & 0xffff) * 0x4650 + (w >> 16);
    unsigned int r = (z << 16) + (w & 0xffff);
    FloatBits_143100 b;
    b.u = (r & 0x7fffff) | 0x3f800000;
    b.f = b.f - 1.0f;
    b.u |= r & 0x80000000;
    return b.f;
}


// 0x00143180 FUN_00143180 (12 B): matches/0x00143180.cpp
// sym: ?FUN_00143180@Obj_143180@owners@@QAE_NH@Z
bool owners::Obj_143180::FUN_00143180(int v) {
    mValue = v;
    return true;
}


// 0x001431a0 FUN_001431a0 (12 B): matches/0x001431a0.cpp
// sym: ?FUN_001431a0@O_1431a0@owners@@QAEDH@Z
char owners::O_1431a0::FUN_001431a0(int v) {
    m10 = v;
    return 1;
}


// 0x001431b0 FUN_001431b0 (4 B): matches/0x001431b0.cpp
// sym: ?FUN_001431b0@Obj_1431b0@owners@@QAEPAXXZ
void* owners::Obj_1431b0::FUN_001431b0() {
    return (char*)this + 0x18;
}


// 0x001431d0 FUN_001431d0 (12 B): matches/0x001431d0.cpp
// sym: ?FUN_001431d0@X_1431d0@owners@@QAEDH@Z
char owners::X_1431d0::FUN_001431d0(int v) {
    value = v;
    return 1;
}

namespace fn_f3c8e3e3 {

// 0x001431e0 FUN_001431e0 (4 B): matches/0x001431e0.cpp
// sym: ?Get@Obj_1431e0@fn_f3c8e3e3@@QAEPAUSub_1431e0@2@XZ
Sub_1431e0* Obj_1431e0::Get() {
    return (Sub_1431e0*)((char*)this + 0x28);
}

} // namespace fn_f3c8e3e3

// 0x00143200 FUN_00143200 (12 B): matches/0x00143200.cpp
// sym: ?FUN_00143200@T_143200@owners@@QAE_NH@Z
bool owners::T_143200::FUN_00143200(int x) {
    m = x;
    return true;
}


// 0x00143220 FUN_00143220 (12 B): matches/0x00143220.cpp
// sym: ?FUN_00143220@Obj_143220@owners@@QAEDH@Z
char owners::Obj_143220::FUN_00143220(int v) {
    value = v;
    return 1;
}


// 0x00143230 FUN_00143230 (12 B): matches/0x00143230.cpp
// sym: ?FUN_00143230@Obj_143230@owners@@QAE_NH@Z
bool owners::Obj_143230::FUN_00143230(int v) {
    value = v;
    return true;
}


// 0x00143250 FUN_00143250 (12 B): matches/0x00143250.cpp
// sym: ?FUN_00143250@X_143250@owners@@QAEEH@Z
unsigned char owners::X_143250::FUN_00143250(int v) {
    value = v;
    return 1;
}


// 0x00143270 FUN_00143270 (12 B): matches/0x00143270.cpp
// sym: ?FUN_00143270@Obj_143270@owners@@QAE_NH@Z
bool owners::Obj_143270::FUN_00143270(int x) {
    m14 = x;
    return true;
}


// 0x00143290 FUN_00143290 (12 B): matches/0x00143290.cpp
// sym: ?FUN_00143290@Obj_143290@owners@@QAEDH@Z
char owners::Obj_143290::FUN_00143290(int a) {
    m18 = a;
    return 1;
}


// 0x001432b0 FUN_001432b0 (12 B): matches/0x001432b0.cpp
// sym: ?FUN_001432b0@Obj_1432b0@owners@@QAE_NH@Z
bool owners::Obj_1432b0::FUN_001432b0(int v) {
    m1c = v;
    return true;
}


// 0x001432d0 FUN_001432d0 (12 B): matches/0x001432d0.cpp
// sym: ?FUN_001432d0@C_1432d0@owners@@QAEDD@Z
char owners::C_1432d0::FUN_001432d0(char value) {
    m20 = value;
    return 1;
}


// 0x001432e0 FUN_001432e0 (12 B): matches/0x001432e0.cpp
// sym: ?FUN_001432e0@Obj_1432e0@owners@@QAEDH@Z
char owners::Obj_1432e0::FUN_001432e0(int v) {
    mVal = v;
    return 1;
}

namespace fn_f3c8e3e3 {

// 0x001432f0 FUN_001432f0 (4 B): matches/0x001432f0.cpp
// sym: ?Target@fn_f3c8e3e3@@YIPADPAVObj_1432f0@1@@Z
char* __fastcall Target(Obj_1432f0* p) {
    return (char*)p + 0x10;
}

} // namespace fn_f3c8e3e3

// 0x00143320 FUN_00143320 (26 B): matches/0x00143320.cpp
// sym: ?FUN_00143320@Obj_143320@owners@@QAEDPBH@Z
char owners::Obj_143320::FUN_00143320(const int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return 1;
}

namespace fn_f3c8e3e3 {

// 0x00143360 FUN_00143360 (26 B): matches/0x00143360.cpp
// sym: ?Set@C_143360@fn_f3c8e3e3@@QAE_NPAUSrc_143360@2@@Z
bool C_143360::Set(Src_143360* p) {
    m24 = p->a;
    m28 = p->b;
    m2c = p->c;
    return true;
}

} // namespace fn_f3c8e3e3

// 0x00143390 FUN_00143390 (12 B): matches/0x00143390.cpp
// sym: ?FUN_00143390@Obj_143390@owners@@QAE_NH@Z
bool owners::Obj_143390::FUN_00143390(int x) {
    m30 = x;
    return true;
}

namespace fn_f3c8e3e3 {

// 0x001433b0 FUN_001433b0 (12 B): matches/0x001433b0.cpp
// sym: ?Set@Obj_1433b0@fn_f3c8e3e3@@QAEDH@Z
char Obj_1433b0::Set(int x) {
    m = x;
    return 1;
}

} // namespace fn_f3c8e3e3

// 0x001433d0 FUN_001433d0 (12 B): matches/0x001433d0.cpp
// sym: ?FUN_001433d0@X_1433d0@owners@@QAE_NH@Z
bool owners::X_1433d0::FUN_001433d0(int v) {
    m38 = v;
    return true;
}


// 0x001433f0 FUN_001433f0 (12 B): matches/0x001433f0.cpp
// sym: ?FUN_001433f0@Obj_1433f0@owners@@QAEDH@Z
char owners::Obj_1433f0::FUN_001433f0(int value) {
    m3c = value;
    return 1;
}


// 0x00143400 FUN_00143400 (12 B): matches/0x00143400.cpp
// sym: ?FUN_00143400@A_143400@owners@@QAE_NH@Z
bool owners::A_143400::FUN_00143400(int x) {
    m = x;
    return true;
}

namespace fn_f3c8e3e3 {

// 0x00143430 FUN_00143430 (26 B): matches/0x00143430.cpp
// sym: ?Set@Obj_143430@fn_f3c8e3e3@@QAE_NPBUVec3_143430@2@@Z
bool Obj_143430::Set(const Vec3_143430* other) {
    v.x = other->x;
    v.y = other->y;
    v.z = other->z;
    return true;
}


// 0x00143470 FUN_00143470 (26 B): matches/0x00143470.cpp
// sym: ?Set@Obj@fn_f3c8e3e3@@QAE_NPAUVec@2@@Z
bool Obj::Set(Vec* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return true;
}


// 0x001434b0 FUN_001434b0 (26 B): matches/0x001434b0.cpp
// sym: ?Set@Obj_1434b0@fn_f3c8e3e3@@QAEDPAUVec3_1434b0@2@@Z
char Obj_1434b0::Set(Vec3_1434b0* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return 1;
}

} // namespace fn_f3c8e3e3

// 0x001434e0 FUN_001434e0 (18 B): matches/0x001434e0.cpp
// sym: ?FUN_001434e0@A_1434e0@owners@@QAEDM@Z
char owners::A_1434e0::FUN_001434e0(float x) {
    mAngle = x * 0.017453292f;
    return 1;
}


// 0x00143510 FUN_00143510 (18 B): matches/0x00143510.cpp
// sym: ?FUN_00143510@Obj_143510@owners@@QAE_NM@Z
bool owners::Obj_143510::FUN_00143510(float a) {
    value = a * (float)0.017453292f;
    return true;
}


// 0x00143540 FUN_00143540 (12 B): matches/0x00143540.cpp
// sym: ?FUN_00143540@A_143540@owners@@QAE_NH@Z
bool owners::A_143540::FUN_00143540(int v) {
    m3c = v;
    return true;
}


// 0x00143560 FUN_00143560 (12 B): matches/0x00143560.cpp
// sym: ?FUN_00143560@C_143560@owners@@QAEDH@Z
char owners::C_143560::FUN_00143560(int v) {
    mVal = v;
    return 1;
}


// 0x00143580 FUN_00143580 (12 B): matches/0x00143580.cpp
// sym: ?FUN_00143580@X_143580@owners@@QAEDH@Z
char owners::X_143580::FUN_00143580(int v) {
    *(int*)((char*)this + 0x44) = v;
    return 1;
}


// 0x001435a0 FUN_001435a0 (12 B): matches/0x001435a0.cpp
// sym: ?FUN_001435a0@Obj_1435a0@owners@@QAEDH@Z
char owners::Obj_1435a0::FUN_001435a0(int v) {
    m048 = v;
    return 1;
}


// 0x001435c0 FUN_001435c0 (12 B): matches/0x001435c0.cpp
// sym: ?FUN_001435c0@C_1435c0@owners@@QAEDI@Z
char owners::C_1435c0::FUN_001435c0(unsigned int v) {
    m = v;
    return 1;
}


// 0x001435e0 FUN_001435e0 (12 B): matches/0x001435e0.cpp
// sym: ?FUN_001435e0@Obj_1435e0@owners@@QAE_NH@Z
bool owners::Obj_1435e0::FUN_001435e0(int v) {
    m50 = v;
    return true;
}


// 0x00143600 FUN_00143600 (12 B): matches/0x00143600.cpp
// sym: ?FUN_00143600@Obj_143600@owners@@QAE_NH@Z
bool owners::Obj_143600::FUN_00143600(int x) {
    value = x;
    return true;
}


// 0x00143610 FUN_00143610 (12 B): matches/0x00143610.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Set@X_143610@fn_00143610@@QAEDH@Z
namespace fn_00143610 {
class X_143610 {
  public:
    char Set(int v);
    char pad[12];
    int m;
};

char X_143610::Set(int v) {
    *(volatile int*)&m = v;
    return 1;
}

void UseX() {
    X_143610 x;
    x.Set(0);
}
} // namespace fn_00143610

namespace fn_f3c8e3e3 {

// 0x00143630 FUN_00143630 (12 B): matches/0x00143630.cpp
// sym: ?Set@X_143630@fn_f3c8e3e3@@QAE_NI@Z
bool X_143630::Set(unsigned int v) {
    value = v;
    return true;
}


// 0x00143650 FUN_00143650 (12 B): matches/0x00143650.cpp
// sym: ?Set@Obj@fn_f3c8e3e3@@QAEDH@Z
char Obj::Set(int v) {
    value = v;
    return 1;
}


// 0x00143670 FUN_00143670 (12 B): matches/0x00143670.cpp
// sym: ?Set@A_143670@fn_f3c8e3e3@@QAE_NH@Z
bool A_143670::Set(int x) {
    m18 = x;
    return true;
}


// 0x00143690 FUN_00143690 (12 B): matches/0x00143690.cpp
// sym: ?Set@C_143690@fn_f3c8e3e3@@QAEDI@Z
char C_143690::Set(unsigned int x) {
    *(unsigned int*)((char*)this + 0x1c) = x;
    return 1;
}


// 0x001436b0 FUN_001436b0 (12 B): matches/0x001436b0.cpp
// sym: ?Set@Obj_1436b0@fn_f3c8e3e3@@QAEDH@Z
char Obj_1436b0::Set(int value) {
    *(int*)(m + 0x20) = value;
    return 1;
}

} // namespace fn_f3c8e3e3

// 0x001436c0 FUN_001436c0 (12 B): matches/0x001436c0.cpp
// sym: ?FUN_001436c0@X_1436c0@owners@@QAE_NH@Z
bool owners::X_1436c0::FUN_001436c0(int v) {
    m = v;
    return true;
}


// 0x001436e0 FUN_001436e0 (12 B): matches/0x001436e0.cpp
// sym: ?FUN_001436e0@Obj_1436e0@owners@@QAE_NH@Z
bool owners::Obj_1436e0::FUN_001436e0(int v) {
    m10 = v;
    return true;
}

namespace fn_f3c8e3e3 {

// 0x001436f0 FUN_001436f0 (19 B): matches/0x001436f0.cpp
// sym: ?FUN_001436f0@fn_f3c8e3e3@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001436f0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0f80), ((char*)&DAT_004e0f84));
}

} // namespace fn_f3c8e3e3

// 0x00143710 hulkfight::motion::HitEffectTrack::vfunc_0 (16 B): matches/0x00143710.cpp
// sym: ?vfunc_0@HitEffectTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitEffectTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f80;
    return p[index];
}


// 0x00143720 FUN_00143720 (76 B): matches/0x00143720.cpp [wrapped: merged class would differ: HitEffectTrack: field v18: Field(+0x18 Vec v18) vs Field(+0x18 Vec v18)]
// sym: ??0HitEffectTrack@fn_00143720@@QAE@XZ
namespace fn_00143720 {
class Track_143720 {
  public:
    Track_143720();
    virtual void f();
    char pad[8];
};
class Vec {
  public:
    Vec();
    char pad[8];
};
class HitEffectTrack : public Track_143720 {
  public:
    HitEffectTrack();
    virtual void f();
    int mC;
    float m10;
    char pad14[4];
    Vec v18;
    float m20;
    char pad24[4];
    Vec v28;
    float m30;
    int m34;
};
HitEffectTrack::HitEffectTrack() : Track_143720(), mC(0), m10(-1.0f), v18(), m20(1.0f), v28(), m30(1.0f), m34(0) {
    *(int*)((char*)this + 8) = 1;
}
} // namespace fn_00143720


// 0x00143770 hulkfight::motion::HitEffectTrack::vfunc_6 (4 B): matches/0x00143770.cpp
// sym: ?vfunc_6@HitEffectTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitEffectTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00143780 hulkfight::motion::HitEffectTrack::vfunc_7 (7 B): matches/0x00143780.cpp
// sym: ?vfunc_7@HitEffectTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitEffectTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00143790 FUN_00143790 (33 B): matches/0x00143790.cpp
// sym: ?FUN_00143790@HitEffectTrack@motion@hulkfight@@QAEXXZ
// Same code shape as 0x0013a280 (propagated; names are from that function)
void hulkfight::motion::HitEffectTrack::FUN_00143790() {
    *(hulk_uintptr*)this = (hulk_uintptr)&hulk_at_00412f14;
    ((Sub_143790*)((char*)this + 0x28))->Init_0027af50();
    ((Sub_143790*)((char*)this + 0x18))->Init_0027af50();
    ((Base_143790*)this)->Finish_00236d60();
}

namespace fn_f3c8e3e3 {

// 0x001437c0 FUN_001437c0 (19 B): matches/0x001437c0.cpp
// sym: ?FUN_001437c0@fn_f3c8e3e3@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001437c0() {
    FUN_00234810(((char*)&DAT_004e0f88), ((char*)&DAT_004e0f8c));
}

} // namespace fn_f3c8e3e3

// 0x001437e0 hulkfight::motion::SlowMotionTrack::vfunc_0 (16 B): matches/0x001437e0.cpp
// sym: ?vfunc_0@SlowMotionTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SlowMotionTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f88;
    return p[index];
}


// 0x001437f0 FUN_001437f0 (58 B): matches/0x001437f0.cpp [wrapped: conflict: hulkfight::motion::SlowMotionTrack]
// sym: ??0SlowMotionTrack@motion@hulkfight@fn_001437f0@@QAE@XZ
namespace fn_001437f0 {
namespace hulkfight {
namespace motion {
struct FUN_00236d40 {
    FUN_00236d40();
    virtual hulk_intptr unknown_001437e0(int);
};
struct SlowMotionTrack : FUN_00236d40 {
    int field04;
    int field08;
    int field0c;
    float field10;
    float field14;
    float field18;
    float field1c;
    unsigned char field20;
    SlowMotionTrack();
};
SlowMotionTrack::SlowMotionTrack() {
    field0c = 0;
    field18 = 1.0f;
    field1c = 1.0f;
    field10 = 0.1f;
    field14 = 0.9f;
    field20 = 0;
    field08 = 1;
}
} // namespace motion
} // namespace hulkfight
} // namespace fn_001437f0


// 0x00143830 hulkfight::motion::SlowMotionTrack::vfunc_6 (4 B): matches/0x00143830.cpp
// sym: ?vfunc_6@SlowMotionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::SlowMotionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00143840 hulkfight::motion::SlowMotionTrack::vfunc_7 (7 B): matches/0x00143840.cpp
// sym: ?vfunc_7@SlowMotionTrack@motion@hulkfight@@UAEMXZ
hulk_freg hulkfight::motion::SlowMotionTrack::vfunc_7() {
    return this->f_18 - this->f_0c;
}

namespace fn_f3c8e3e3 {

// 0x00143860 FUN_00143860 (19 B): matches/0x00143860.cpp
// sym: ?FUN_00143860@fn_f3c8e3e3@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00143860(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0f90), ((char*)&DAT_004e0f94));
}

} // namespace fn_f3c8e3e3

// 0x00143880 hulkfight::motion::WorldDamageTrack::vfunc_0 (16 B): matches/0x00143880.cpp
// sym: ?vfunc_0@WorldDamageTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::WorldDamageTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f90;
    return p[index];
}


// 0x00143890 FUN_00143890 (79 B): equivalent/0x00143890.cpp [wrapped: conflict: hulkfight::motion::WorldDamageTrack]
// sym: ??0WorldDamageTrack@motion@hulkfight@fn_00143890@@QAE@XZ @6e1986357fab @w4802410f3583
namespace fn_00143890 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00143890 @ 0x00143890
struct FUN_00236d40 {
    FUN_00236d40();
    virtual void dummy();
    char reserved[4];
    int enabled;
};
struct FUN_0027af00 { FUN_0027af00(); char data[8]; };
namespace hulkfight { namespace motion {
struct WorldDamageTrack : FUN_00236d40 {
    virtual void dummy();
    int zeroC;
    FUN_0027af00 object;
    int zero18, zero1C, zero20, zero24, zero28;
    float negativeOne, one30;
    int zero34;
    float one38, one3C;
    WorldDamageTrack();
};
WorldDamageTrack::WorldDamageTrack() : zeroC(0) {
    zero18=zero1C=zero20=zero24=zero28=0;
    negativeOne=-1.0f;
    one30=1.0f;
    zero34=0;
    one38=one3C=1.0f;
    enabled=1;
}
}}
} // namespace fn_00143890


// 0x001438e0 hulkfight::motion::WorldDamageTrack::vfunc_6 (4 B): matches/0x001438e0.cpp
// sym: ?vfunc_6@WorldDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::WorldDamageTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001438f0 hulkfight::motion::WorldDamageTrack::vfunc_7 (7 B): matches/0x001438f0.cpp
// sym: ?vfunc_7@WorldDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::WorldDamageTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f3c8e3e3 {

// 0x00143900 FUN_00143900 (25 B): matches/0x00143900.cpp
// sym: ?Fn@WorldDamageTrack@fn_f3c8e3e3@@QAEXXZ
void WorldDamageTrack::Fn() {
    vptr = &hulk_at_00412f74;
    inner.Init_0027af50();
    BaseFn_00236d60();
}


// 0x00143920 FUN_00143920 (19 B): matches/0x00143920.cpp
// sym: ?FUN_00143920@fn_f3c8e3e3@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00143920(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0f98), ((char*)&DAT_004e0f9c));
}

} // namespace fn_f3c8e3e3

// 0x00143940 hulkfight::motion::WorldConeDamageTrack::vfunc_0 (16 B): matches/0x00143940.cpp
// sym: ?vfunc_0@WorldConeDamageTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::WorldConeDamageTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f98;
    return p[index];
}


// 0x00143950 FUN_00143950 (103 B): equivalent/0x00143950.cpp [wrapped: conflict: hulkfight::motion::WorldConeDamageTrack]
// sym: ?FUN_00143950@WorldConeDamageTrack@motion@hulkfight@fn_00143950@@QAEPAV1234@XZ @f215eae40e4c @wba0d14f7d512
namespace fn_00143950 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00143950 @ 0x00143950


struct Base12 {
    char data[12];
    void FUN_00236d40();
};

namespace hulkfight {
namespace motion {
class WorldConeDamageTrack {
public:
    virtual hulk_intptr vfunc_0_00143940(int);
    int f04;
    int f08;
    int f0c, f10, f14, f18, f1c, f20;
    float f24;
    int f28;
    float f2c;
    int f30;
    float f34, f38, f3c, f40;
    int f44, f48;
    float f4c, f50;
    int f54;

    WorldConeDamageTrack() {}
    WorldConeDamageTrack *FUN_00143950();
};
}
}

hulkfight::motion::WorldConeDamageTrack *hulkfight::motion::WorldConeDamageTrack::FUN_00143950()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) WorldConeDamageTrack;
    f0c = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = -1.0f;
    f28 = 0;
    f30 = 0;
    f2c = 1.0f;
    f34 = 0.7853982f;
    f38 = 0.7853982f;
    f54 = 0;
    f3c = 1.0f;
    f40 = 10.0f;
    f44 = 1;
    f48 = 1;
    f4c = 1.0f;
    f50 = 1.0f;
    f08 = 1;
    return this;
}
} // namespace fn_00143950


// 0x001439c0 hulkfight::motion::WorldConeDamageTrack::vfunc_6 (4 B): matches/0x001439c0.cpp
// sym: ?vfunc_6@WorldConeDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::WorldConeDamageTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001439d0 hulkfight::motion::WorldConeDamageTrack::vfunc_7 (7 B): matches/0x001439d0.cpp
// sym: ?vfunc_7@WorldConeDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::WorldConeDamageTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f3c8e3e3 {

// 0x001439f0 FUN_001439f0 (19 B): matches/0x001439f0.cpp
// sym: ?FUN_001439f0@fn_f3c8e3e3@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001439f0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0fa0), ((char*)&DAT_004e0fa4));
}

} // namespace fn_f3c8e3e3

// 0x00143a10 hulkfight::motion::MotionBlurTrack::vfunc_0 (16 B): matches/0x00143a10.cpp
// sym: ?vfunc_0@MotionBlurTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MotionBlurTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0fa0;
    return p[index];
}

namespace fn_f3c8e3e3 {

// 0x00143a20 FUN_00143a20 (57 B): matches/0x00143a20.cpp
// sym: ??0MotionBlurTrack@fn_f3c8e3e3@@QAE@XZ
MotionBlurTrack::MotionBlurTrack() : a(0), x(0.1f), y(0.9f), z(1.0f), b(0), c(0) {
    *(int*)((char*)&this->p) = 1;
}

} // namespace fn_f3c8e3e3

// 0x00143a60 hulkfight::motion::MotionBlurTrack::vfunc_6 (4 B): matches/0x00143a60.cpp
// sym: ?vfunc_6@MotionBlurTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::MotionBlurTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00143a70 hulkfight::motion::MotionBlurTrack::vfunc_7 (7 B): matches/0x00143a70.cpp
// sym: ?vfunc_7@MotionBlurTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::MotionBlurTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f3c8e3e3 {

// 0x00143a90 FUN_00143a90 (19 B): matches/0x00143a90.cpp
// sym: ?FUN_00143a90@fn_f3c8e3e3@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00143a90(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0fa8), ((char*)&DAT_004e0fac));
}

} // namespace fn_f3c8e3e3

// 0x00143ab0 hulkfight::motion::MotionTrailStopTrack::vfunc_0 (16 B): matches/0x00143ab0.cpp
// sym: ?vfunc_0@MotionTrailStopTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MotionTrailStopTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0fa8;
    return p[index];
}

namespace fn_f3c8e3e3 {

// 0x00143ac0 FUN_00143ac0 (33 B): matches/0x00143ac0.cpp
// sym: ??0MotionTrailStopTrack@fn_f3c8e3e3@@QAE@XZ
MotionTrailStopTrack::MotionTrailStopTrack() : Track_143ac0() {
    b = 0;
    c = 0;
    a = 1;
}

} // namespace fn_f3c8e3e3

// 0x00143af0 hulkfight::motion::MotionTrailStopTrack::vfunc_6 (4 B): matches/0x00143af0.cpp
// sym: ?vfunc_6@MotionTrailStopTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::MotionTrailStopTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00143b00 hulkfight::motion::MotionTrailStopTrack::vfunc_7 (7 B): matches/0x00143b00.cpp
// sym: ?vfunc_7@MotionTrailStopTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::MotionTrailStopTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00143b20 hulkfight::motion::WorldDamageAction::vfunc_5 (707 B): equivalent/0x00143b20.cpp
// sym: ?vfunc_5@WorldDamageAction@motion@hulkfight@@UAE_NHH@Z @b3a5cc1cfdb4 @w32d93461cb37
// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 16/16)
// hulkfight::motion::WorldDamageAction::vfunc_5 @ 0x00143b20
bool hulkfight::motion::WorldDamageAction::vfunc_5(hulk_intptr a1, int a2) {
    if (a1 != 1)
        return true;
    struct Frame {
        int outv;
        V3_143b20 out14;
        V3_143b20 vb;
        V3_143b20 pa;
        void *ptr1;
        void *ptr2;
        int n;
        int d3c;
        int d38;
        V3_143b20 w2;
        V3_143b20 w1;
        V3_143b20 hit;
        V3_143b20 normal;
        Matrix_143b20 m;
    } f;
    f.n = (*(Data_143b20 * *)&this->f_1c)->count;
    if (f.n <= 0)
        return false;
    Handle_143b20 *y = ((Handle_143b20 *)((owners::Object_592a0 *)((*(Owner_143b20 * *)&this->f_20)))->FUN_000592a0());
    Handle_143b20 *yy = y;
    Entity_143b20 *x = y->FUN_00059a30();
    Skeleton_143b20 *skel = x->skel;
    unsigned int idx = skel->FUN_002843a0((*(Data_143b20 * *)&this->f_1c)->idLo, (*(Data_143b20 * *)&this->f_1c)->idHi);
    if (idx == 0xffff)
        x->FUN_00035160(&f.m);
    else
        f.m = skel->mats[idx];
    f.pa = (*(Data_143b20 * *)&this->f_1c)->posA;
    ((owners::Mat_22c2b0 *)&(f.m))->FUN_0022c2b0((float *)(const V3_143b20 *)(&f.pa), (float *)(V3_143b20 *)(&f.w1));
    f.vb = (*(Data_143b20 * *)&this->f_1c)->vecB;
    if (f.vb.z * f.vb.z + f.vb.y * f.vb.y + f.vb.x * f.vb.x <= (*(float*)&DAT_00412ec0)) {
        f.vb.x = 0;
        f.vb.y = 1.0f;
        f.vb.z = 0;
    }
    x->FUN_00035630(&f.vb, &f.out14);
    ((Anchor_143b20 *)yy)->FUN_00059a50(&f.w2);
    f.out14.x = f.out14.x - f.w2.x;
    f.out14.y = f.out14.y - f.w2.y;
    f.out14.z = f.out14.z - f.w2.z;
    f.out14.FUN_0022d110();
    Data_143b20 *d = (*(Data_143b20 * *)&this->f_1c);
    f.d3c = d->f3c;
    f.ptr1 = 0;
    f.ptr2 = 0;
    f.outv = *(int *)&d->length;
    f.d38 = d->f38;
    if (!DAT_004dd700->caster->FUN_00202460(&f.w1, &f.out14, d->length, 1, &f.hit, &f.normal, &f.ptr1, &f.ptr2))
        return true;
    if (f.ptr1 == 0)
        return true;
    int n1 = f.n - 1;
    f.pa.x = 0;
    f.pa.y = -1.0f;
    f.pa.z = 0;
    bool vertical = f.out14.FUN_0022d2b0(&f.pa, 0.00001f);
    if (!vertical) {
        f.pa.x = 0;
        f.pa.y = 1.0f;
        f.pa.z = 0;
        vertical = f.out14.FUN_0022d2b0(&f.pa, 0.00001f);
    }
    if (vertical) {
        f.out14 = (*(V3_143b20*)&DAT_004ad7b4);
        FUN_00224d70(x->FUN_000354c0(), &f.out14);
    }
    f.outv = 0;
    DAT_004dd700->sweeper->FUN_001f6cd0(f.ptr1, f.ptr2, &f.hit, &f.normal, &f.out14, n1, f.d38, f.d3c, &f.outv, 0);
    ((owners::Crusher_1ecd00 *)(DAT_004dd700->sink))->FUN_001ecd00((const char *)(hulk_uintptr)(int)(f.outv), (hulk_intptr)(Entity_143b20 *)x);
    return true;
}

namespace fn_f3c8e3e3 {

// 0x00144150 hulkfight::motion::SlowMotionAction::vfunc_3 (70 B): matches/0x00144150.cpp
// sym: ?vfunc_3@SlowMotionAction@fn_f3c8e3e3@@QAE_NHH@Z
bool SlowMotionAction::vfunc_3(int a, int b) {
    measured = source->vfunc_6();
    factor = 1.0f;
    float value = source->value;
    if (value <= DAT_003f3358)
        return false;
    if (value != DAT_003f32dc)
        return true;
    return false;
}

} // namespace fn_f3c8e3e3

// 0x001441a0 hulkfight::motion::SlowMotionAction::vfunc_5 (325 B): equivalent/0x001441a0.cpp [wrapped: conflict: World]
// sym: ?vfunc_5@SlowMotionAction@fn_001441a0@@UAEDHM@Z @e24ed9e8ae4c @w2441d1f5e7b5
namespace fn_001441a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 12/12; Wine build 617 inputs, 12/12)
// hulkfight::motion::SlowMotionAction::vfunc_5 @ 0x001441a0
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
extern "C" double __cdecl sin(double);
#endif


class Clock_1441a0 {
public:
};

struct World {
    char pad0[0x58];
    Clock_1441a0 *clock;
};

class Curve_1441a0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual float vfunc_6();
    char pad04[0xc];
    float fadeInEnd;
    float fadeOutBegin;
    float fadeOutEnd;
    float target;
    char active;
};

class SlowMotionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(int mode, float dt);

    char pad04[0x18];
    Curve_1441a0 *curve;
    float base;
    float elapsed;
};

char SlowMotionAction::vfunc_5(int mode, float dt)
{
    if (mode != 1 && curve->active == 0)
        return 1;

    float t = dt + elapsed;
    elapsed = t;
    Curve_1441a0 *c = curve;
    float val = c->target;

    if (t < c->fadeInEnd) {
        float end = c->fadeInEnd;
        float den = end - c->vfunc_6();
        c = curve;
        hulk_freg v6 = c->vfunc_6();      // MSVC calls first and reads elapsed after (the callee may change it); clang reads the left operand first
        hulk_freg r = (elapsed - v6) / den;
        if (val > base)
            val = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (val - base) * 0.5f + base;
        else
            val = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (base - val) * 0.5f + val;
    } else if (t > c->fadeOutBegin) {
        hulk_freg r = (t - c->fadeOutBegin) / (c->fadeOutEnd - c->fadeOutBegin);
        if (val > base)
            val = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (val - base) * 0.5f + base;
        else
            val = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (base - val) * 0.5f + val;
    }
    ((owners::Thing_86100 *)(DAT_004dd700->clock))->FUN_00086100(val);
    return 1;
}
} // namespace fn_001441a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001442f0 hulkfight::motion::SlowMotionAction::vfunc_4 (19 B): matches/0x001442f0.cpp
// sym: ?vfunc_4@SlowMotionAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::SlowMotionAction::vfunc_4() {
    hulk_at_004dd700->member->call_00086100(this->f_20);
}


// 0x00144310 hulkfight::motion::MotionBlurAction::vfunc_3 (65 B): matches/0x00144310.cpp
// sym: ?vfunc_3@MotionBlurAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::MotionBlurAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    this->f_20 = (*(MotionState_144310 * *)&this->f_1c)->f6();
    if ((*(MotionState_144310 * *)&this->f_1c)->value < hulk_at_003f32e0)
        return false;
    FUN_001c3d90()->FUN_001c3840((char*)this + 0x24, (char*)this + 0x28);
    return true;
}


// 0x00144360 hulkfight::motion::MotionBlurAction::vfunc_5 (528 B): equivalent/0x00144360.cpp [wrapped: conflict: FUN_001c3d90; hulkfight::motion::MotionBlurAction]
// sym: ?vfunc_5@MotionBlurAction@motion@hulkfight@fn_00144360@@UAE_NHM@Z @65958afd2054 @wc9a39cb9900b
namespace fn_00144360 {
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 14/14; Wine build 625 inputs, 14/14)
// hulkfight::motion::MotionBlurAction::vfunc_5 @ 0x00144360

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif


struct Holder_144360 {
    void FUN_001c3830(float a, float b);
};
Holder_144360 *FUN_001c3d90();

class BlurState {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual float vfunc_6();
    char pad04[0xc];
    float fadeInEnd;
    float fadeOutBegin;
    float fadeOutEnd;
    float valueB;
    float valueA;
};

namespace hulkfight {
namespace motion {

class MotionBlurAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int mode, float dt);

    char pad04[0x18];
    BlurState *state;
    float elapsed;
    float targetB;
    float targetA;
};

}
}

bool hulkfight::motion::MotionBlurAction::vfunc_5(int mode, float dt)
{
    if (mode != 1)
        return true;

    float t = dt + elapsed;
    elapsed = t;
    BlurState *s = state;
    float a = s->valueA;
    float b = s->valueB;

    if (t < s->fadeInEnd) {
        float fin = s->fadeInEnd;
        float den = fin - s->vfunc_6();
        hulk_freg v6 = state->vfunc_6();      // MSVC calls first and reads elapsed after (the callee may change it); clang reads the left operand first
        hulk_freg r = (elapsed - v6) / den;
        if (b > targetB)
            b = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (b - targetB) * 0.5f + targetB;
        else
            b = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (targetB - b) * 0.5f + b;
        if (a > targetA)
            a = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (a - targetA) * 0.5f + targetA;
        else
            a = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (targetA - a) * 0.5f + a;
    } else if (t > s->fadeOutBegin) {
        hulk_freg r = (t - s->fadeOutBegin) / (s->fadeOutEnd - s->fadeOutBegin);
        if (b > targetB)
            b = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (b - targetB) * 0.5f + targetB;
        else
            b = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (targetA - b) * 0.5f + b;
        if (a > targetA)
            a = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (a - targetA) * 0.5f + targetA;
        else
            a = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (targetA - a) * 0.5f + a;
    }
    FUN_001c3d90()->FUN_001c3830(b, a);
    return true;
}
} // namespace fn_00144360


// 0x00144570 hulkfight::motion::MotionBlurAction::vfunc_4 (21 B): matches/0x00144570.cpp [wrapped: conflict: FUN_001c3d90; hulkfight::motion::MotionBlurAction]
// sym: ?vfunc_4@MotionBlurAction@motion@hulkfight@fn_00144570@@UAEXXZ
namespace fn_00144570 {
struct Blur_Target {
    void FUN_001c3830(int a, int b);
};
Blur_Target* FUN_001c3d90();

namespace hulkfight { namespace motion {
class MotionBlurAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[0x24 - 4];
    int a;
    int b;
};
void MotionBlurAction::vfunc_4() {
    int y = b;
    int x = a;
    FUN_001c3d90()->FUN_001c3830(x, y);
}
}}
} // namespace fn_00144570

namespace fn_f3c8e3e3 {

// 0x00144590 hulkfight::motion::MotionTrailStopAction::vfunc_4 (59 B): matches/0x00144590.cpp
// sym: ?vfunc_4@MotionTrailStopAction@fn_f3c8e3e3@@QAEXXZ
void MotionTrailStopAction::vfunc_4() {
    if (mCheck) {
        X_144590* a = ((X_144590*)mCheck)->Fna_000592a0();
        X_144590* b = a->Fnb_00059a30();
        X_144590* c = FUN_0027f250();
        int t = mA->value;
        int v = ((int)((owners::X_36cb0 *)b)->FUN_00036cb0((unsigned int)t));
        c->Fne_002834e0(v);
    }
}

} // namespace fn_f3c8e3e3

// 0x001445d0 hulkfight::motion::HitEffectAction::vfunc_3 (283 B): equivalent/0x001445d0.cpp [wrapped: conflict: World; hulkfight::motion::HitEffectAction]
// sym: ?vfunc_3@HitEffectAction@motion@hulkfight@fn_001445d0@@UAE_NII@Z @f446c0e8670f @wd68115e2a6d1
namespace fn_001445d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::HitEffectAction::vfunc_3 @ 0x001445d0
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

struct Vec_1445d0 { float x,y,z; bool FUN_0022d2b0(Vec_1445d0*,float); };
struct Pair_1445d0 { float x,y; };
struct Matrix { float m[16]; void FUN_0022b980(); void FUN_0022be40(Vec_1445d0*); };
extern "C" void __cdecl FUN_00224db0(Matrix*,Vec_1445d0*,Vec_1445d0*);
struct Hit_1445d0 { char pad[8]; Vec_1445d0 position; char gap[4]; Vec_1445d0 direction; };
struct Inner_1445d0 { void FUN_00059a30(); };
struct Actor_1445d0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual Hit_1445d0* s3(); Inner_1445d0* FUN_000592a0(); };
struct Settings_1445d0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual float s6(); char pad[12]; float time; char gap[4]; Pair_1445d0 a; unsigned int b; unsigned int gap2; unsigned int c; unsigned int d; unsigned int e; unsigned int f; };
struct EffectManager { void FUN_00025590(Hit_1445d0*,Pair_1445d0*,unsigned int,unsigned int*,unsigned int,Matrix*,float,unsigned int); };
struct World { char pad[32]; EffectManager* manager; }; 
namespace hulkfight { namespace motion { struct HitEffectAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned int,unsigned int); virtual void vfunc_4(); virtual void vfunc_5(); char pad[28]; Settings_1445d0* settings; Actor_1445d0* actor; }; 
bool HitEffectAction::vfunc_3(unsigned int,unsigned int) { actor->FUN_000592a0()->FUN_00059a30(); Hit_1445d0* hit=actor->s3(); if(hit) { Vec_1445d0 position=hit->position; Vec_1445d0 direction=hit->direction; Matrix matrix; matrix.FUN_0022b980(); Vec_1445d0 up; up.x=0;up.y=1;up.z=0; if(!direction.FUN_0022d2b0(&up,0.00001f)) { up.x=0;up.y=1;up.z=0; FUN_00224db0(&matrix,&up,&direction); } matrix.FUN_0022be40(&position); float time=settings->time; float remaining=time-settings->s6(); Settings_1445d0* s=settings; DAT_004dd700->manager->FUN_00025590(hit,&s->a,s->b,&s->c,s->e,&matrix,remaining,s->f); } return false; }
} }
} // namespace fn_001445d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3c8e3e3 {

// 0x001447b0 hulkfight::motion::HitEffectTrack::vfunc_5 (54 B): matches/0x001447b0.cpp
// sym: ?vfunc_5@HitEffectTrack_1447b0@fn_f3c8e3e3@@QAEPAV12@E@Z
// Same code shape as 0x0013a8e0 (propagated; names are from that function)
HitEffectTrack_1447b0* HitEffectTrack_1447b0::vfunc_5(byte_1447b0 param) {
    vf = (hulk_intptr)((int*)DAT_00412f14);
    b.Fnf_0027af50();
    a.Fnf_0027af50();
    ((Base_1447b0*)this)->Fng_00236d60();
    if (param & 1)
        cdel_0008d330(this);
    return this;
}


// 0x001447f0 hulkfight::motion::SlowMotionTrack::vfunc_5 (36 B): matches/0x001447f0.cpp
// sym: ?vfunc_5@SlowMotionTrack_1447f0@fn_f3c8e3e3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
SlowMotionTrack_1447f0* SlowMotionTrack_1447f0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00412f44;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00144820 hulkfight::motion::WorldDamageTrack::vfunc_5 (46 B): matches/0x00144820.cpp
// sym: ?vfunc_5@WorldDamageTrack_144820@fn_f3c8e3e3@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
WorldDamageTrack_144820* WorldDamageTrack_144820::vfunc_5(unsigned char param) {
    WorldDamageTrack_144820* p = this;
    *(char**)p = ((char*)DAT_00412f74);
    ((Obj_144820*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_144820*)p)->f2_00236d60();
    if (param & 1)
        thunk_FUN_00267090((Obj_144820*)p);
    return p;
}


// 0x00144850 hulkfight::motion::WorldConeDamageTrack::vfunc_5 (36 B): matches/0x00144850.cpp
// sym: ?vfunc_5@WorldConeDamageTrack_144850@fn_f3c8e3e3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
WorldConeDamageTrack_144850* WorldConeDamageTrack_144850::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00412fa4;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00144880 hulkfight::motion::MotionBlurTrack::vfunc_5 (36 B): matches/0x00144880.cpp
// sym: ?vfunc_5@MotionBlurTrack_144880@fn_f3c8e3e3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
MotionBlurTrack_144880* MotionBlurTrack_144880::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00412fd4;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001448b0 hulkfight::motion::MotionTrailStopTrack::vfunc_5 (36 B): matches/0x001448b0.cpp
// sym: ?vfunc_5@MotionTrailStopTrack_1448b0@fn_f3c8e3e3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
MotionTrailStopTrack_1448b0* MotionTrailStopTrack_1448b0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413004;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001448e0 FUN_001448e0 (72 B): matches/0x001448e0.cpp
// sym: ??0WorldDamageAction_1448e0@fn_f3c8e3e3@@QAE@HPAVRefObj_1448e0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
WorldDamageAction_1448e0::WorldDamageAction_1448e0(int target, RefObj_1448e0* obj) {
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


// 0x00144930 FUN_00144930 (50 B): matches/0x00144930.cpp
// sym: ??1WorldDamageAction_144930@fn_f3c8e3e3@@QAE@XZ
WorldDamageAction_144930::~WorldDamageAction_144930() throw() {
    vptr = (void**)DAT_00413034;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_144930 *)this)->FUN_002326a0();
}

} // namespace fn_f3c8e3e3

// 0x00144970 hulkfight::motion::WorldDamageTrack::vfunc_10 (70 B): matches/0x00144970.cpp
// sym: ?vfunc_10@WorldDamageTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::WorldDamageTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        Object_144970* p = Alloc_0008d690(0x24);
        if (p)
            return p->Init_001448e0(this, c);
    }
    return 0;
}

namespace fn_f3c8e3e3 {

// 0x001449c0 FUN_001449c0 (72 B): matches/0x001449c0.cpp
// sym: ??0WorldConeDamageAction_1449c0@fn_f3c8e3e3@@QAE@HPAVRefObj_1449c0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
WorldConeDamageAction_1449c0::WorldConeDamageAction_1449c0(int target, RefObj_1449c0* obj) {
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


// 0x00144a10 FUN_00144a10 (50 B): matches/0x00144a10.cpp
// sym: ??1WorldConeDamageAction_144a10@fn_f3c8e3e3@@QAE@XZ
WorldConeDamageAction_144a10::~WorldConeDamageAction_144a10() {
    vptr = hulk_at_00413050;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_144a10 *)this)->FUN_002326a0();
}


// 0x00144aa0 FUN_00144aa0 (34 B): matches/0x00144aa0.cpp
// sym: ??0SlowMotionAction_144aa0@fn_f3c8e3e3@@QAE@H@Z
// Same code shape as 0x00144b30 (propagated; names are from that function)
SlowMotionAction_144aa0::SlowMotionAction_144aa0(int x) : Action_144aa0(), value(0) {
    int* p = &value;
    *p = 0;
    value = x;
}

} // namespace fn_f3c8e3e3

// 0x00144af0 hulkfight::motion::SlowMotionTrack::vfunc_10 (57 B): matches/0x00144af0.cpp
// sym: ?vfunc_10@SlowMotionTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::SlowMotionTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    SlowMotionAction_144af0* p = (SlowMotionAction_144af0*)Alloc_0008d690(0x28);
    if (p) {
        p->init_00232660();
        *(volatile hulk_uintptr*)p = ((hulk_intptr)DAT_0041306c);
        p->owner = 0;
        p->owner = this;
        return (hulk_intptr)(p);
    }
    return (int)(0);
}

namespace fn_f3c8e3e3 {

// 0x00144b30 FUN_00144b30 (34 B): matches/0x00144b30.cpp
// sym: ??0MotionBlurAction@fn_f3c8e3e3@@QAE@H@Z
MotionBlurAction::MotionBlurAction(int x) : Action_144b30(), value(0) {
    int* p = &value;
    *p = 0;
    value = x;
}


// 0x00144b80 FUN_00144b80 (72 B): matches/0x00144b80.cpp
// sym: ??0MotionTrailStopAction_144b80@fn_f3c8e3e3@@QAE@HPAVRefObj_144b80@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
MotionTrailStopAction_144b80::MotionTrailStopAction_144b80(int target, RefObj_144b80* obj) {
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


// 0x00144bd0 FUN_00144bd0 (50 B): matches/0x00144bd0.cpp
// sym: ??1MotionTrailStopAction_144bd0@fn_f3c8e3e3@@QAE@XZ
MotionTrailStopAction_144bd0::~MotionTrailStopAction_144bd0() {
    vptr = hulk_at_004130a4;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_144bd0 *)this)->FUN_002326a0();
}


// 0x00144c10 FUN_00144c10 (108 B): matches/0x00144c10.cpp
// sym: ??0HitEffectAction@fn_f3c8e3e3@@QAE@PAVRef_144c10@1@H0@Z
HitEffectAction::HitEffectAction(Ref_144c10* p, int x, Ref_144c10* q) {
    a = 0;
    b = 0;
    c = 0;
    if (p)
        p->Add();
    if (a)
        a->Release();
    a = p;
    b = x;
    if (q)
        q->Add();
    if (c)
        c->Release();
    c = q;
}


// 0x00144c80 FUN_00144c80 (69 B): matches/0x00144c80.cpp
// sym: ??1HitEffectAction_144c80@fn_f3c8e3e3@@QAE@XZ
HitEffectAction_144c80::~HitEffectAction_144c80() {
    vptr = hulk_at_004130c0;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20)
        m20 = 0;
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_144c80 *)this)->FUN_002326a0();
}

} // namespace fn_f3c8e3e3

// 0x00144cd0 hulkfight::motion::HitEffectTrack::vfunc_10 (75 B): matches/0x00144cd0.cpp
// sym: ?vfunc_10@HitEffectTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::HitEffectTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(type1_144cd0), (void*)(type2_144cd0), 0))) {
        Effect_144cd0* p = (Effect_144cd0*)alloc_0008d690(0x28);
        if (p)
            return p->init_00144c10(a, this, c);
    }
    return 0;
}


// 0x00144d40 fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>::vfunc_6 (26 B): matches/0x00144d40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>::**)(int))&this->f_10))(b);
}


// 0x00144d60 fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>::vfunc_2 (11 B): matches/0x00144d60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00144d90 fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>::vfunc_6 (26 B): matches/0x00144d90.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>::**)(int))&this->f_10))(b);
}


// 0x00144db0 fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>::vfunc_2 (11 B): matches/0x00144db0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00144de0 fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>::vfunc_6 (26 B): matches/0x00144de0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>::**)(int))&this->f_10))(b);
}


// 0x00144e00 fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>::vfunc_2 (11 B): matches/0x00144e00.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00144e30 fight::ParamBool<hulkfight::motion::SlowMotionTrack>::vfunc_6 (26 B): matches/0x00144e30.cpp
// sym: ?vfunc_6@?$ParamBool@VSlowMotionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::SlowMotionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::SlowMotionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::SlowMotionTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::SlowMotionTrack>::**)(int))&this->f_10))(b);
}


// 0x00144e50 fight::ParamBool<hulkfight::motion::SlowMotionTrack>::vfunc_2 (11 B): matches/0x00144e50.cpp
// sym: ?vfunc_2@?$ParamBool@VSlowMotionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::SlowMotionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00144e80 fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>::vfunc_6 (26 B): matches/0x00144e80.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x00144ea0 fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>::vfunc_2 (11 B): matches/0x00144ea0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00144ed0 fight::ParamVector<hulkfight::motion::WorldDamageTrack>::vfunc_6 (26 B): matches/0x00144ed0.cpp
// sym: ?vfunc_6@?$ParamVector@VWorldDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::WorldDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::WorldDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::WorldDamageTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::WorldDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x00144ef0 fight::ParamVector<hulkfight::motion::WorldDamageTrack>::vfunc_2 (11 B): matches/0x00144ef0.cpp
// sym: ?vfunc_2@?$ParamVector@VWorldDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::WorldDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00144f30 fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::vfunc_7 (6 B): matches/0x00144f30.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00144f40 fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::vfunc_6 (30 B): matches/0x00144f40.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_144f40 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_144f40*)&DAT_003f335c));
}


// 0x00144f60 fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::vfunc_8 (26 B): matches/0x00144f60.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::**)(int))&this->f_18))(b);
}


// 0x00144f80 fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::vfunc_2 (11 B): matches/0x00144f80.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00144fb0 fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_6 (26 B): matches/0x00144fb0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x00144fd0 fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_2 (11 B): matches/0x00144fd0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00145000 fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>::vfunc_6 (26 B): matches/0x00145000.cpp
// sym: ?vfunc_6@?$ParamVector@VWorldDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x00145020 fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>::vfunc_2 (11 B): matches/0x00145020.cpp
// sym: ?vfunc_2@?$ParamVector@VWorldDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00145050 fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_6 (26 B): matches/0x00145050.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x00145070 fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_2 (11 B): matches/0x00145070.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001450b0 fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::vfunc_7 (6 B): matches/0x001450b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001450c0 fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::vfunc_6 (30 B): matches/0x001450c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1450c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1450c0*)&DAT_003f335c));
}


// 0x001450e0 fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::vfunc_8 (26 B): matches/0x001450e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::**)(int))&this->f_18))(b);
}


// 0x00145100 fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::vfunc_2 (11 B): matches/0x00145100.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00145130 fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>::vfunc_6 (26 B): matches/0x00145130.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>::**)(int))&this->f_10))(b);
}


// 0x00145150 fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>::vfunc_2 (11 B): matches/0x00145150.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00145180 fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_6 (26 B): matches/0x00145180.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>::**)(int))&this->f_10))(b);
}


// 0x001451a0 fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_2 (11 B): matches/0x001451a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001451d0 fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_6 (26 B): matches/0x001451d0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>::**)(int))&this->f_10))(b);
}


// 0x001451f0 fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_2 (11 B): matches/0x001451f0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00145210 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitEffectTrack>::vfunc_0 (36 B): matches/0x00145210.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitEffectTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitEffectTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004adef0, 0)) != 0;
}


// 0x00145240 fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>::vfunc_0 (30 B): matches/0x00145240.cpp
// sym: ??_G?$ParamFloatConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::HitEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145240)
#endif


// 0x00145260 fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>::vfunc_0 (30 B): matches/0x00145260.cpp
// sym: ??_G?$ParamIntConstRange@VHitEffectTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::HitEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145260)
#endif


// 0x00145290 fight::TrackFactoryCasterTemplate<hulkfight::motion::SlowMotionTrack>::vfunc_0 (36 B): matches/0x00145290.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSlowMotionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SlowMotionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004adf98, 0) != 0;
}


// 0x001452c0 fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>::vfunc_0 (30 B): matches/0x001452c0.cpp
// sym: ??_G?$ParamFloatConstRange@VSlowMotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::SlowMotionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1452c0)
#endif


// 0x001452e0 fight::ParamBool<hulkfight::motion::SlowMotionTrack>::vfunc_0 (30 B): matches/0x001452e0.cpp
// sym: ??_G?$ParamBool@VSlowMotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::SlowMotionTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::SlowMotionTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1452e0)
#endif


// 0x00145310 fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldDamageTrack>::vfunc_0 (36 B): matches/0x00145310.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VWorldDamageTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldDamageTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004ae040, 0) != 0;
}


// 0x00145340 fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>::vfunc_0 (30 B): matches/0x00145340.cpp
// sym: ??_G?$ParamFloatConstRange@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::WorldDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145340)
#endif


// 0x00145360 fight::ParamVector<hulkfight::motion::WorldDamageTrack>::vfunc_0 (30 B): matches/0x00145360.cpp
// sym: ??_G?$ParamVector@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::WorldDamageTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::WorldDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145360)
#endif


// 0x00145380 fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::vfunc_0 (30 B): matches/0x00145380.cpp
// sym: ??_G?$ParamEnumConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::WorldDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145380)
#endif


// 0x001453b0 fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldConeDamageTrack>::vfunc_0 (36 B): matches/0x001453b0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VWorldConeDamageTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldConeDamageTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ae0f0, 0) != 0;
}


// 0x001453e0 fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_0 (30 B): matches/0x001453e0.cpp
// sym: ??_G?$ParamFloatConstRange@VWorldConeDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1453e0)
#endif


// 0x00145400 fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>::vfunc_0 (30 B): matches/0x00145400.cpp
// sym: ??_G?$ParamVector@VWorldConeDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145400)
#endif


// 0x00145420 fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>::vfunc_0 (30 B): matches/0x00145420.cpp
// sym: ??_G?$ParamIntConstRange@VWorldConeDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145420)
#endif


// 0x00145440 fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::vfunc_0 (30 B): matches/0x00145440.cpp
// sym: ??_G?$ParamEnumConstList@VWorldConeDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145440)
#endif


// 0x00145470 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionBlurTrack>::vfunc_0 (36 B): matches/0x00145470.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionBlurTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionBlurTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ae1a0, 0) != 0;
}


// 0x001454a0 fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>::vfunc_0 (30 B): matches/0x001454a0.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionBlurTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1454a0)
#endif


// 0x001454d0 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionTrailStopTrack>::vfunc_0 (36 B): matches/0x001454d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionTrailStopTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionTrailStopTrack>::vfunc_0(void* __p0) { hulk_intptr arg = (hulk_intptr)__p0;

    return (FUN_00344e74(arg, 0, (void*)&DAT_0049850c, (void*)&DAT_004ae250, 0) != 0);
}


// 0x00145500 fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_0 (30 B): matches/0x00145500.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionTrailStopTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::MotionTrailStopTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145500)
#endif


// 0x00145520 fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>::vfunc_0 (30 B): matches/0x00145520.cpp
// sym: ??_G?$ParamIntConstRange@VMotionTrailStopTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::MotionTrailStopTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145520)
#endif

namespace fn_f3c8e3e3 {

// 0x00145ba0 hulkfight::motion::WorldDamageAction::vfunc_2 (71 B): matches/0x00145ba0.cpp
// sym: ?vfunc_2@WorldDamageAction_145ba0@fn_f3c8e3e3@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
WorldDamageAction_145ba0* WorldDamageAction_145ba0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00413034;
    RefCounted_145ba0* q = *(RefCounted_145ba0* volatile*)&m_20;
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


// 0x00145bf0 hulkfight::motion::WorldConeDamageAction::vfunc_2 (71 B): matches/0x00145bf0.cpp
// sym: ?vfunc_2@WorldConeDamageAction_145bf0@fn_f3c8e3e3@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
WorldConeDamageAction_145bf0* WorldConeDamageAction_145bf0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_145bf0;
    RefCounted_145bf0* q = *(RefCounted_145bf0* volatile*)&m_20;
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


// 0x00145c40 hulkfight::motion::SlowMotionAction::vfunc_2 (52 B): matches/0x00145c40.cpp
// sym: ?vfunc_2@SlowMotionAction@fn_f3c8e3e3@@UAEPAU12@E@Z
SlowMotionAction* SlowMotionAction::vfunc_2(unsigned char flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_0041306c);
    _ReadWriteBarrier();
    if (member)
        member = 0;
    ((fight::Action *)this)->FUN_002326a0();
    if (flags & 1)
        destroy_0008d330(this);
    return this;
}

} // namespace fn_f3c8e3e3

// 0x00145c80 hulkfight::motion::MotionBlurTrack::vfunc_10 (57 B): matches/0x00145c80.cpp
// sym: ?vfunc_10@MotionBlurTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::MotionBlurTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    MBAction* p = (MBAction*)alloc_0008d690(0x2c);
    if (p) {
        p->BaseAction::BaseAction();
        *(void* volatile*)p = hulk_at_00413088;
        *(void* volatile*)&p->owner = 0;
        p->owner = (void*)this;
        return (hulk_intptr)(p);
    }
    return (int)(0);
}

namespace fn_f3c8e3e3 {

// 0x00145cc0 hulkfight::motion::MotionBlurAction::vfunc_2 (52 B): matches/0x00145cc0.cpp
// sym: ?vfunc_2@MotionBlurAction@fn_f3c8e3e3@@UAEPAV12@H@Z
MotionBlurAction* MotionBlurAction::vfunc_2(int flag) {
    *(void**)this = motionVtable;
    _ReadWriteBarrier();
    if (mObject)
        mObject = 0;
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1)
        DeleteThunk_0008d330(this);
    return this;
}


// 0x00145d50 hulkfight::motion::MotionTrailStopAction::vfunc_2 (71 B): matches/0x00145d50.cpp
// sym: ?vfunc_2@MotionTrailStopAction_145d50@fn_f3c8e3e3@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
MotionTrailStopAction_145d50* MotionTrailStopAction_145d50::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_145d50;
    RefCounted_145d50* q = *(RefCounted_145d50* volatile*)&m_20;
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


// 0x00145e40 fight::ParamName<hulkfight::motion::HitEffectTrack>::vfunc_7 (12 B): matches/0x00145e40.cpp
// sym: ?vfunc_6@ParamBranch@fn_f3c8e3e3@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f3c8e3e3

// 0x00145eb0 fight::ParamNameConstList<hulkfight::motion::WorldDamageTrack>::vfunc_7 (12 B): matches/0x00145eb0.cpp [wrapped: same definition as 0x00145e40 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00145eb0@@UAEXPAX@Z
namespace fn_00145eb0 {
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
} // namespace fn_00145eb0


// 0x00145f20 fight::ParamName<hulkfight::motion::HitEffectTrack>::vfunc_0 (30 B): matches/0x00145f20.cpp
// sym: ??_G?$ParamName@VHitEffectTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::HitEffectTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::HitEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145f20)
#endif


// 0x00145f40 fight::ParamNameConstList<hulkfight::motion::WorldDamageTrack>::vfunc_0 (30 B): matches/0x00145f40.cpp
// sym: ??_G?$ParamNameConstList@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::WorldDamageTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::WorldDamageTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x145f40)
#endif

namespace fn_f3c8e3e3 {

// 0x00146130 FUN_00146130 (38 B): matches/0x00146130.cpp
// sym: _FUN_00146130
extern "C" void __cdecl FUN_00146130(Factory* factory, const char* name) {
    TrackFactoryCasterTemplate_146130 caster;
    factory->Add_002367c0(Find_00236ac0(name, &caster));
}


// 0x00146370 FUN_00146370 (38 B): matches/0x00146370.cpp
// sym: ?FUN_00146370@fn_f3c8e3e3@@YAXPAVObj@1@PBD@Z
void FUN_00146370(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_146370 caster;
    obj->Set_002367c0(Find_00236ac0(name, &caster));
}

} // namespace fn_f3c8e3e3

// 0x001463a0 FUN_001463a0 (38 B): matches/0x001463a0.cpp [wrapped: conflict: Target]
// sym: _FUN_001463a0
namespace fn_001463a0 {
class TrackFactoryCasterTemplate_1463a0 {
  public:
    virtual bool Cast_00145470(void*);
};
struct Target {
    int Get_002367c0(void*);
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_1463a0*);
extern "C" int FUN_001463a0(Target* t, void* x) {
    TrackFactoryCasterTemplate_1463a0 c;
    void* p = FUN_00236ac0(x, &c);
    return t->Get_002367c0(p);
}
} // namespace fn_001463a0


// 0x00146400 FUN_00146400 (215 B): equivalent/0x00146400.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: _FUN_00146400 @5f1e86489d52 @w65d7f3a29874
namespace fn_00146400 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00146400 @ 0x00146400
namespace hulkfight { namespace motion { class HitEffectTrack; class SlowMotionTrack; class WorldDamageTrack; class WorldConeDamageTrack; class MotionBlurTrack; class MotionTrailStopTrack; } }
namespace fight {
template<class T> struct TrackFactoryCasterTemplate { virtual void cast(); };
}
extern void* __cdecl FUN_00236ac0(const char*, void*);
struct Registry_146400 { void FUN_002367c0(void*); };
extern "C" bool __cdecl FUN_00146400(Registry_146400* registry) {
 fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldDamageTrack> a;
 registry->FUN_002367c0(FUN_00236ac0("worldDamage", &a));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldConeDamageTrack> b;
 registry->FUN_002367c0(FUN_00236ac0("worldConeDamage", &b));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionTrailStopTrack> c;
 registry->FUN_002367c0(FUN_00236ac0("motionTrailStop", &c));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitEffectTrack> d;
 registry->FUN_002367c0(FUN_00236ac0("hitEffect", &d));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::SlowMotionTrack> e;
 registry->FUN_002367c0(FUN_00236ac0("effectSlowMotion", &e));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionBlurTrack> f;
 registry->FUN_002367c0(FUN_00236ac0("effectMotionBlur", &f));
 return true;
}
} // namespace fn_00146400


// 0x001464e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::SlowMotionTrack>::vfunc_1 (60 B): matches/0x001464e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSlowMotionTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::SlowMotionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1464e0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_1464e0* t = new (mem) TrackFactoryTemplate_1464e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f3c8e3e3 {

// 0x00146520 fight::TrackFactoryTemplate<hulkfight::motion::SlowMotionTrack>::vfunc_5 (81 B): matches/0x00146520.cpp
// sym: ?target@fn_f3c8e3e3@@YAPAUSlowMotionTrack@1@XZ
SlowMotionTrack* __cdecl target() {
    SlowMotionTrack* p = (SlowMotionTrack*)FUN_0008d690((int)sizeof(SlowMotionTrack));
    if (p) {
        p->Init_00236d40();
        p->a = 1.0f;
        p->b = 1.0f;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00412f44);
        p->zero = 0;
        p->d = 0.1f;
        p->e = 0.9f;
        p->flag = 0;
        p->refs = 1;
        return p;
    }
    return 0;
}


// 0x00146580 fight::TrackFactoryTemplate<hulkfight::motion::SlowMotionTrack>::vfunc_2 (43 B): matches/0x00146580.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f3c8e3e3@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041349c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f3c8e3e3

// 0x001465b0 fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldConeDamageTrack>::vfunc_1 (60 B): matches/0x001465b0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VWorldConeDamageTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldConeDamageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1465b0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_1465b0* t = new (mem) TrackFactoryTemplate_1465b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001465f0 fight::TrackFactoryTemplate<hulkfight::motion::WorldConeDamageTrack>::vfunc_5 (24 B): matches/0x001465f0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VWorldConeDamageTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0013e710 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::WorldConeDamageTrack>::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((Built_1465f0*)p)->init_00143950());
    return (void*)(0);
}


// 0x00146610 fight::TrackFactoryTemplate<hulkfight::motion::WorldConeDamageTrack>::vfunc_2 (43 B): matches/0x00146610.cpp [wrapped: same definition as 0x00146580 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00146610@@QAEPAXE@Z
namespace fn_00146610 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_004134b8;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00143920();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004134b8;
    base1_dtor_00143920();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00146610


// 0x00146640 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionBlurTrack>::vfunc_1 (60 B): matches/0x00146640.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionBlurTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionBlurTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_146640));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_146640* t = new (mem) TrackFactoryTemplate_146640();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00146680 fight::TrackFactoryTemplate<hulkfight::motion::MotionBlurTrack>::vfunc_5 (87 B): matches/0x00146680.cpp [wrapped: conflict: MotionBlurTrack]
// sym: ?CreateTrack@fn_00146680@@YAPAUMotionBlurTrack@1@XZ
extern void* operator new(size_t);
namespace fn_00146680 {
extern "C" char DAT_00412fd4[];
struct MotionBlurTrack {
  public:
    void Init_00236d40();
    hulk_intptr vf;
    int mHdr;
    int mOne;
    int mZero;
    float mA;
    float mB;
    float mC;
    int mD;
    int mE;
};


MotionBlurTrack* CreateTrack() {
    MotionBlurTrack* p = (MotionBlurTrack*)operator new(sizeof(MotionBlurTrack));
    if (p != 0) {
        p->Init_00236d40();
        p->vf = ((hulk_intptr)DAT_00412fd4);
        p->mZero = 0;
        p->mA = 0.1f;
        p->mB = 0.9f;
        p->mC = 1.0f;
        p->mD = 0;
        p->mE = 0;
        p->mOne = 1;
        return p;
    }
    return 0;
}
} // namespace fn_00146680


// 0x001466e0 fight::TrackFactoryTemplate<hulkfight::motion::MotionBlurTrack>::vfunc_2 (43 B): matches/0x001466e0.cpp [wrapped: same definition as 0x00146580 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001466e0@@QAEPAXE@Z
namespace fn_001466e0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_004134d4;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_001439f0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004134d4;
    base1_dtor_001439f0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_001466e0


// 0x00146710 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionTrailStopTrack>::vfunc_1 (60 B): matches/0x00146710.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionTrailStopTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionTrailStopTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_146710));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_146710* t = new (mem) TrackFactoryTemplate_146710();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00146750 fight::TrackFactoryTemplate<hulkfight::motion::MotionTrailStopTrack>::vfunc_5 (59 B): matches/0x00146750.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMotionTrailStopTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::MotionTrailStopTrack>::vfunc_5() {
    Motion_146750* p = (Motion_146750*)Alloc_0008d690(0x14);
    if (p) {
        p->Init_00236d40();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00413004);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)((void*)((char*)p - (char*)p));
}


// 0x00146790 fight::TrackFactoryTemplate<hulkfight::motion::MotionTrailStopTrack>::vfunc_2 (43 B): matches/0x00146790.cpp [wrapped: same definition as 0x00146580 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00146790@@QAEPAXE@Z
namespace fn_00146790 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_004134f0;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00143a90();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004134f0;
    base1_dtor_00143a90();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00146790


// 0x001467c0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitEffectTrack>::vfunc_1 (60 B): matches/0x001467c0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitEffectTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitEffectTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1467c0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_1467c0* t = new (mem) TrackFactoryTemplate_1467c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00146800 fight::TrackFactoryTemplate<hulkfight::motion::HitEffectTrack>::vfunc_5 (24 B): matches/0x00146800.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitEffectTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fac0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitEffectTrack>::vfunc_5() {
    Track_146800* p = (Track_146800*)operator_new(0x38);
    if (p)
        return (void*)(p->method_00143720());
    return (void*)(0);
}


// 0x00146820 fight::TrackFactoryTemplate<hulkfight::motion::HitEffectTrack>::vfunc_2 (43 B): matches/0x00146820.cpp [wrapped: same definition as 0x00146580 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00146820@@QAEPAXE@Z
namespace fn_00146820 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0041350c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_001436f0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041350c;
    base1_dtor_001436f0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00146820


// 0x00146850 fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldDamageTrack>::vfunc_1 (60 B): matches/0x00146850.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldDamageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_146850));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_146850* t = new (mem) TrackFactoryTemplate_146850();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00146890 fight::TrackFactoryTemplate<hulkfight::motion::WorldDamageTrack>::vfunc_5 (24 B): matches/0x00146890.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VWorldDamageTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fa30 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::WorldDamageTrack>::vfunc_5() {
    Grapple_146890* p = (Grapple_146890*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack_00143890());
    return (void*)(0);
}


// 0x001468b0 fight::TrackFactoryTemplate<hulkfight::motion::WorldDamageTrack>::vfunc_2 (43 B): matches/0x001468b0.cpp [wrapped: same definition as 0x00146580 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001468b0@@QAEPAXE@Z
namespace fn_001468b0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00413528;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00143860();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00413528;
    base1_dtor_00143860();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_001468b0

